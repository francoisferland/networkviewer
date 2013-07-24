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

namespace netcore
{

    NETVDriverManager::NETVDriverManager(CoreDriver* driver, QObject *parent)
        : CoreDriverManager(driver, parent), m_scheduler(NULL), m_mutex(QMutex::Recursive)
    {

    }

    void NETVDriverManager::startup()
    {
        qDebug("NETVDriverManager::startup()");
        //Create scheduler in the manager's thread
        m_scheduler = new NETVScheduler(this);

    }

    void NETVDriverManager::shutdown()
    {
        qDebug("NETVDriverManager::shutdown()");
        if (m_scheduler)
        {
            delete m_scheduler;
        }
    }

    void NETVDriverManager::process(const CoreMessage* message)
    {
        //This is called from the CoreManager's thread...
        qDebug() << "NETVDriverManager::process(CoreMessage* message)" << " Thread: " << QThread::currentThread();
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

        //qDebug("NETVInterfaceManager::requestVariable(ModuleVariable *variable = %p)",variable);
        Q_ASSERT(variable);
        NETVModule *module = getModule(variable->getDeviceID());
        Q_ASSERT(module);

        if (module->active() && variable->getMemType() < NETVVariable::SCRIPT_VARIABLE && variable->getOffset() >= 0 )
        {

            //Building NETV request...
            NETVMessage *message;

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
                connect(module,SIGNAL(variableWrite(ModuleVariable*)),this,SLOT(writeVariable(ModuleVariable*)));

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
        //qDebug("NETVInterfaceManager::writeVariable(ModuleVariable *variable = %p)",variable);
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
