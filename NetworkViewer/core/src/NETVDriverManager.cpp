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

namespace netcore
{

    NETVDriverManager::NETVDriverManager(CoreDriver* driver, QObject *parent)
        : CoreDriverManager(driver, parent), m_scheduler(NULL)
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

    }


} //namespace netcore
