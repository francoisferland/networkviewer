/**
     Copyright (C) 2009-2013 IntRoLab
     http://introlab.3it.usherbrooke.ca
     Dominic Letourneau, ing. M.Sc.A.
     Dominic.Letourneau@USherbrooke.ca

     This file is part of OpenECoSys/NetworkViewer.
     OpenECoSys/NetworkViewer is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by the Free Software
     Foundation, either version 3 of the License, or (at your option) any later version.
     OpenECoSys/NetworkViewer is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
     or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
     You should have received a copy of the GNU General Public License along with
     OpenECoSys/NetworkViewer. If not, see http://www.gnu.org/licenses/.
 */


#include "NETVDriverManager.h"
#include "NETVMessage.h"
#include <QMutexLocker>
#include <QBuffer>
#include "CoreSerializer.h"

namespace netcore
{

    class DebugSerializer : public CoreSerializer
    {
        //Convert a message to a series of bytes
        virtual bool serialize(const CoreMessage &message, QIODevice &dev)
        {
            return true;
        }

        virtual bool serialize(const CANMessage &message, QIODevice &dev)
        {

           return true;
        }

        virtual bool serialize(const NETVMessage &message, QIODevice &dev)
        {
            qDebug("NETVMessage : eid = %u, flags = %u",message.eid(),message.flags());
            qDebug("priority: %u type: %u command: %u dest: %u payloadSize: %i",message.getPriority(),message.getType(),message.getCommand(), message.getDestination(), message.payloadSize());
            qDebug() << message.payload();
            return true;
        }
    };



    NETVDriverManager::NETVDriverManager(CoreDriver* driver, QObject *parent)
        : CoreDriverManager(driver, parent), m_scheduler(NULL), m_mutex(QMutex::Recursive), m_watchdogTimer(NULL)
    {

    }

    NETVDriverManager::~NETVDriverManager()
    {
        //Remove all modules
        while(m_modules.size() > 0)
        {
            removeModule(m_modules.front());
        }
    }

    void NETVDriverManager::startup()
    {
        qDebug("NETVDriverManager::startup()");
        //Create scheduler in the manager's thread
        m_scheduler = new NETVScheduler(this);

        //Watch for modules alive over time
        m_watchdogTimer = new QTimer(this);
        connect(m_watchdogTimer,SIGNAL(timeout()),this,SLOT(watchdogTimeout()));
        m_watchdogTimer->start(1000);

    }

    void NETVDriverManager::shutdown()
    {
        delete m_watchdogTimer;
        m_watchdogTimer = NULL;

        qDebug("NETVDriverManager::shutdown()");
        if (m_scheduler)
        {
            delete m_scheduler;
            m_scheduler = NULL;
        }

        //Remove all modules
        while(m_modules.size() > 0)
        {
            removeModule(m_modules.front());
        }
    }

    void NETVDriverManager::process(const CoreMessage* message)
    {
        //This is called from the CoreManager's thread...
        qDebug() << "NETVDriverManager::process(CoreMessage* message)" << " Thread: " << QThread::currentThread();
        DebugSerializer ser;
        QBuffer buf;
        const_cast<CoreMessage*>(message)->serialize(ser,buf);
        process(dynamic_cast<const NETVMessage*>(message));
    }

    void NETVDriverManager::process(const NETVMessage* message)
    {

        qDebug("NETVDriverManager::process(const NETVMessage* message = %p)",message);
        if (message == NULL)
            return;

        //We are called by another thread
        QMutexLocker lock(&m_mutex);

        //qDebug("NETVInterfaceManager::processCANMessage(const NETV_MESSAGE &msg)");
        //NETVDevice::printMessage(msg,std::cout);
        if (!message->isRemote())
        {
            qDebug("message is not remote");

            //WILL HANDLE ONLY REQUEST TYPE
            if (message->getType() == NETV_TYPE_REQUEST_DATA)
            {

                //NETVDevice::printMessage(msg,std::cout);

                //Let's see to which module it belongs...
                //Update the variable if it fits...
                for(unsigned int mod = 0; mod < m_modules.size(); mod++)
                {
                    NETVModule *module = m_modules[mod];

                    NETVModuleConfiguration *conf = module->getConfiguration();
                    Q_ASSERT(conf);

                    if (conf->getDeviceID() == message->getDestination())
                    {
                        for(int i =0; i < conf->size(); i++)
                        {
                            //Need to check the offset and the memory type
                            if ((*conf)[i]->getOffset() == message->getCommand() && (*conf)[i]->getMemType() == (NETVVariable::VARIABLE_MEMORY_TYPE) (message->getBootFlags() >> 1))
                            {
                                //FOUND IT
                                //UPDATING VALUE
                                (*conf)[i]->setValue(message->payload(),false,message->timestamp());
                                break;
                            }
                        }
                    }
                }
            }//type == REQUEST_DATA
            else if (message->getType() == NETV_TYPE_EVENTS)
            {
                if (message->getCommand() == NETV_EVENTS_CMD_ALIVE && message->payloadSize() == 8)
                {
                    //qDebug("ALIVE REQUEST ANSWERED...");
                    QByteArray data = message->payload();


                    int module_state = data[0];
                    int project_id = data[1];
                    int module_id = data[2];
                    int code_version = data[3];
                    int table_version = data[4];
                    int boot_delay = data[5];
                    int devID = (((int) data[7]) << 8) | (int) data[6];

                    //Look for already existing modules...
                    bool found = false;
                    for (unsigned int mod = 0; mod < m_modules.size(); mod++)
                    {
                        NETVModule *module = m_modules[mod];

                        if (module->getConfiguration()->getDeviceID() == module_id)
                        {
                            //Update module state
                            module->getConfiguration()->setModuleState(module_state);

                            found = true;

                            //Update time
                            module->setUpdateTime(QTime::currentTime());

                            //Module previously deactivated?
                            if (!module->active())
                            {
                                module->setActive(true);

                                if (m_scheduler)
                                {
                                    m_scheduler->addModule(module);
                                }

                                emit moduleActive(module,true);
                            }
                        }
                    }

                    if (!found)
                    {
                        qDebug("Inserting new module %i",module_id);

                        //fill configuration information...
                        NETVModuleConfiguration conf(project_id, code_version, devID, module_state, table_version, module_id);

                        //The module will belong to the manager's thread
                        NETVModule *module = new NETVModule(conf,NULL);
                        module->moveToThread(this);

                        //Add module
                        addModule(module);
                    }
                }
            }//type == EVENTS
        } // NOT REMOTE
    }


    void NETVDriverManager::sendAliveRequest()
    {
        qDebug() << "NETVDriverManager::sendAliveRequest() " << " Thread : "<<QThread::currentThread();

        char empty[8] = {0};
        NETVMessage *message = new NETVMessage(NETV_PRIORITY_MEDIUM,
                                               NETV_TYPE_EVENTS,
                                               0,
                                               NETV_EVENTS_CMD_ALIVE,
                                               NETV_ADDRESS_BROADCAST,
                                               CANMessage::RTRFlag | CANMessage::ExtendedFlag,
                                               QByteArray(empty,8));

        if (m_driver->sendMessage(message))
        {
            qDebug("m_driver->pushSendMessage(message) OK!");
        }

    }

    void NETVDriverManager::requestVariable(NETVVariable *variable)
    {

        //qDebug("NETVInterfaceManager::requestVariable(NETVVariable *variable = %p)",variable);
        Q_ASSERT(variable);


        if (variable->getMemType() < NETVVariable::SCRIPT_VARIABLE && variable->getOffset() >= 0 )
        {

            //Building NETV request...
            NETVMessage *message = new NETVMessage();

            message->setPriority(NETV_PRIORITY_HIGHEST);
            message->setType(NETV_TYPE_REQUEST_DATA);

            //Requesting the right type of memory
            switch(variable->getMemType())
            {
            case NETVVariable::RAM_VARIABLE:
                message->setBootFlags((NETV_REQUEST_RAM << 1) | (NETV_REQUEST_READ));
                break;

            case NETVVariable::EEPROM_VARIABLE:
                message->setBootFlags((NETV_REQUEST_EEPROM << 1) | (NETV_REQUEST_READ));
                break;
             default:
                qWarning("Unhandled memory type : %i",variable->getMemType());
                break;

            }

            message->setCommand(variable->getOffset());
            message->setDestination(variable->getDeviceID());

            //This is a remote request
            message->setFlags(CANMessage::ExtendedFlag | CANMessage::RTRFlag);

            QByteArray data;
            data.resize(variable->getLength());

            //Unused payload of the size of the variable...
            message->setPayload(data);

            //Sending to NETV bus...
            if(!m_driver->sendMessage(message))
            {
                qDebug("NETVDriverManager::requestVariable(NETVVariable *variable = %p) - unable to request variable",variable);
            }
        }
    }

    NETVModule* NETVDriverManager::getModule(unsigned int deviceID)
    {
        QMutexLocker lock(&m_mutex);
        NETVModule* module = NULL;

        for (unsigned int i = 0; i < m_modules.size(); i++)
        {
            NETVModuleConfiguration *conf = m_modules[i]->getConfiguration();

            if (conf->getDeviceID() == deviceID)
            {
                return m_modules[i];
            }
        }

        return module;
    }

    NETVScheduler* NETVDriverManager::getScheduler()
    {
        return m_scheduler;
    }

    QList<NETVModule *> NETVDriverManager::getModules()
    {
        QMutexLocker lock(&m_mutex);
        //Copy will occur here
        return m_modules;
    }

    bool NETVDriverManager::addModule(NETVModule *module)
    {
        QMutexLocker lock(&m_mutex);

        qDebug("NETVDriverManager::addModule(NETVModule *module = %p)",module);

        if (module)
        {
            if (m_modules.contains(module))
            {
                return false;
            }
            else
            {
                m_modules.push_back(module);
                emit moduleAdded(module);

                //Connect user write
                connect(module,SIGNAL(variableWrite(NETVVariable*)),this,SLOT(writeVariable(NETVVariable*)));

                //Add module to scheduling
                if (m_scheduler)
                {
                    m_scheduler->addModule(module);
                }
            }
        }

        return false;

    }

    bool NETVDriverManager::removeModule(NETVModule *module)
    {
        QMutexLocker lock(&m_mutex);

        qDebug("NETVDriverManager::removeModule(NETVModule *module = %p)",module);

        if (module)
        {
            if (m_modules.contains(module))
            {
                m_modules.removeAll(module);
                emit moduleRemoved(module);

                //Remove module from scheduler
                if (m_scheduler)
                {
                    m_scheduler->removeModule(module);
                }

                delete module;
                return true;
            }
        }

        return false;
    }

    void NETVDriverManager::writeVariable(NETVVariable *variable)
    {
        //qDebug("NETVInterfaceManager::writeVariable(NETVVariable *variable = %p)",variable);
        Q_ASSERT(variable);

        if (variable->getMemType() < NETVVariable::SCRIPT_VARIABLE && variable->getOffset() >= 0)
        {

            //Building NETV request...
            NETVMessage *message = new NETVMessage();

            message->setPriority(NETV_PRIORITY_HIGHEST);
            message->setType(NETV_TYPE_REQUEST_DATA);

            //Requesting the right type of memory
            switch(variable->getMemType())
            {
            case NETVVariable::RAM_VARIABLE:
                message->setBootFlags((NETV_REQUEST_RAM << 1) | (NETV_REQUEST_WRITE));
                break;

            case NETVVariable::EEPROM_VARIABLE:
                message->setBootFlags((NETV_REQUEST_EEPROM << 1) | (NETV_REQUEST_WRITE));
                break;

            default:
               qWarning("Unhandled memory type : %i",variable->getMemType());
               break;
            }

            message->setCommand(variable->getOffset());
            message->setDestination(variable->getDeviceID());

            //This is a NOT remote request
            message->setFlags(CANMessage::ExtendedFlag);


            //Set The data
            QByteArray array = variable->toByteArray();

            //Copy the data
            message->setPayload(array);

            //Sending to NETV bus...
            if (!m_driver->sendMessage(message))
            {
                qDebug("NETVDriverManager::writeVariable(NETVVariable *variable: %p) - could not write variable",variable);
                delete message;
            }

        }
    }

    void NETVDriverManager::watchdogTimeout()
    {
        QMutexLocker lock(&m_mutex);

        //Scan for inactive modules
        for (unsigned int i = 0; i < m_modules.size(); i++)
        {
            if (m_modules[i]->getUpdateTime().secsTo(QTime::currentTime()) > 5)
            {
                qDebug("Module not active : %p",m_modules[i]);
                m_modules[i]->setActive(false);

                if (m_scheduler)
                {
                    m_scheduler->removeModule(m_modules[i]);
                }

                emit moduleActive(m_modules[i],false);
            }
        }
    }


} //namespace netcore
