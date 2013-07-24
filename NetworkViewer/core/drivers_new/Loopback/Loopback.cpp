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

#include "Loopback.h"
#include "CoreDriverFactory.h"
#include "NETVMessage.h"

namespace netcore
{


    class LoopbackDriverRegistry
    {
    public:
        //Factory should register itself when the library is loaded
        // CoreDriverInfo(QString name, quint32 major, quint32 minor, quint32 micro, QString description, QStringList defaultArgs)
        static bool loaded;
    };

    bool LoopbackDriverRegistry::loaded = CoreDriverFactoryBase::registerDriverFactory(
                Loopback::internalInfo(),new CoreDriverFactory<Loopback>());

    Loopback::Loopback(QObject *parent)
        : CoreDriver(parent), m_mutex(QMutex::Recursive)
    {

        //Temp add 5 virtual modules
        for (unsigned int i = 0; i < 5; i++)
            m_moduleList.push_back(VirtualModule(i));
    }

    CoreDriverInfo Loopback::internalInfo()
    {
        static CoreDriverInfo info("Loopback",1,0,0,"Description",QStringList(), new CoreDriverFactory<Loopback>());
        return info;
    }

    CoreDriverInfo Loopback::info()
    {
        return Loopback::internalInfo();
    }

    CoreDriver::CoreDriverState Loopback::initialize(QStringList args)
    {
        return CoreDriver::DRIVER_OK;
    }

    void Loopback::startup()
    {
        qDebug("Loopback::startup()");
    }

    void Loopback::shutdown()
    {
        qDebug("Loopback::shutdown()");
    }

    CoreDriver::CoreDriverState Loopback::state()
    {
        return CoreDriver::DRIVER_OK;
    }

    CoreDriver::CoreDriverState Loopback::internalThreadRecvFunction()
    {
        //qDebug("Loopback::internalThreadRecvFunction()");

        //Read device
        //Should push recv messages
        return CoreDriver::DRIVER_UNDERFLOW;
    }

    CoreDriver::CoreDriverState Loopback::internalThreadSendFunction()
    {
        //qDebug("Loopback::internalThreadSendFunction()");
        //Should write messages to bus...

        //Get message to send
        CoreMessage *message = pullSendMessage();

        if (message)
        {
            qDebug("CoreDriver::CoreDriverState Loopback::internalThreadSendFunction() message: %p",message);

            NETVMessage *netvMessage = dynamic_cast<NETVMessage*>(message);
            if (netvMessage)
            {
                processMessage(netvMessage);
            }


            delete message;
            return CoreDriver::DRIVER_OK;
        }
        else
        {
            return CoreDriver::DRIVER_UNDERFLOW;
        }
    }


    void Loopback::timeout()
    {
        qDebug() << "Loopback::timeout() current thread : " << QThread::currentThread();
    }

    void Loopback::processMessage(const NETVMessage* message)
    {
        //BE CAREFUL THIS FUNCTION RUNS IN THE SEND THREAD

        qDebug("Priority : %u",message->getPriority());
        qDebug("Type : %u",message->getType());
        qDebug("BootFlags : %u",message->getBootFlags());
        qDebug("Command  : %u",message->getCommand());
        qDebug("Destination : %u",message->getDestination());


        if (message->getType() == NETV_TYPE_REQUEST_DATA)
        {
            int device_id = message->getDestination();

            m_mutex.lock();

            if (device_id < m_moduleList.size())
            {
 /*
                //Reading
                if (message.msg_remote)
                {
                    NETV_MESSAGE answer = message;
                    if (message.msg_cmd + message.msg_data_length <= (VirtualModule::NB_VARIABLES * sizeof(double)))
                    {
                        memcpy(answer.msg_data,&m_moduleList[device_id].data[message.msg_cmd],message.msg_data_length);
                        answer.msg_remote = 0;
                        //Writing answer
                        m_messageList.push_back(answer);
                        m_semaphore.release(1);
                    }
                }
                else //Writing
                {
                    if (message.msg_cmd + message.msg_data_length <= (VirtualModule::NB_VARIABLES * sizeof(double)))
                    {
                        memcpy(&m_moduleList[device_id].data[message.msg_cmd],message.msg_data,message.msg_data_length);
                    }
                }
*/
            }
            m_mutex.unlock();

        }
        else if (message->getType() == NETV_TYPE_EVENTS)
        {
            if (message->getCommand() == NETV_EVENTS_CMD_ALIVE)
            {
                m_mutex.lock();

                //process virtual modules alive request
                for(unsigned int i = 0; i < m_moduleList.size(); i++)
                {
                    NETVMessage *answer = dynamic_cast<NETVMessage*>(message->clone());

                    //Clear remote request flag
                    answer->clearFlags(CANMessage::RTRFlag);

                    //Set destination
                    answer->setDestination(m_moduleList[i].module_id);

                    QByteArray data;

                    //Fill data bytes
                    data.append((unsigned char) m_moduleList[i].state);
                    data.append((unsigned char) m_moduleList[i].project_id);
                    data.append((unsigned char) m_moduleList[i].module_id);
                    data.append((unsigned char) m_moduleList[i].code_version);
                    data.append((unsigned char) m_moduleList[i].table_version);
                    data.append((unsigned char) m_moduleList[i].boot_delay); //boot delay
                    data.append((unsigned char) m_moduleList[i].device_id >> 8); //device id
                    data.append((unsigned char) m_moduleList[i].device_id); //devicd id

                    answer->setPayload(data);

                    //Push back answer
                    pushRecvMessage(answer);
                }

                m_mutex.unlock();


            }

        }
        else if (message->getType() == NETV_TYPE_BOOTLOADER)
        {
/*
            unsigned int device_id = message.msg_dest;

            if (device_id < m_moduleList.size())
            {

                if(m_moduleList[device_id].state == NETV_BOOT_MODE_ID)
                {
                    //Send back bootloader ACK...
                    m_mutex.lock();
                    //return message
                    m_messageList.push_back(message);
                    m_mutex.unlock();
                    m_semaphore.release(1);


                    //Must be in boot mode to answer bootloader
                    if (message.msg_cmd == BOOTLOADER_RESET)
                    {
                        qDebug("Loopback::sendMessage BOOTLOADER_RESET");
                        m_moduleList[device_id].state = NETV_NORMAL_MODE_ID;
                    }
                }
            }

*/
        }
        else if (message->getType() == NETV_TYPE_EMERGENCY)
        {
/*
            unsigned int device_id = message.msg_dest;

            if (device_id < m_moduleList.size())
            {
                if (message.msg_cmd == NETV_EMERGENCY_CMD_RESET)
                {
                    qDebug("Loopback::sendMessage NETV_EMERGENCY_CMD_RESET");
                    m_moduleList[device_id].state = NETV_NORMAL_MODE_ID;
                }
                else if (message.msg_cmd == NETV_EMERGENCY_CMD_PROGRAM)
                {
                    qDebug("Loopback::sendMessage NETV_EMERGENCY_CMD_PROGRAM");
                    m_moduleList[device_id].state = NETV_BOOT_MODE_ID;
                }
            }
*/
        }


    }
}
