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
#include "CoreDriver.h"

namespace netcore
{

    CoreDriverRecvThread::CoreDriverRecvThread(CoreDriver *parent)
        : QThread(parent), m_driver(parent)
    {
        Q_ASSERT(m_driver != NULL);
    }

    void CoreDriverRecvThread::run()
    {
        qDebug("CoreDriverRecvThread::run()");
        while(isRunning())
        {
            m_driver->internalThreadRecvFunction();
            usleep(100); //100us sleep
        }
        //Execute event loop
        exec();
    }


    CoreDriverSendThread::CoreDriverSendThread(CoreDriver *parent)
        : QThread(parent), m_driver(parent)
    {
        Q_ASSERT(m_driver != NULL);
    }


    void CoreDriverSendThread::run()
    {
        qDebug("CoreDriverSendThread::run()");
        while(isRunning())
        {
            m_driver->internalThreadSendFunction();
            usleep(100); //100us sleep
        }
        //Execute event loop
        exec();
    }


    CoreDriver::CoreDriver(QObject *parent, int maxRecvQueueSize, int maxSendQueueSize)
        : QObject(parent),
          m_maxRecvQueueSize(maxRecvQueueSize),
          m_maxSendQueueSize(maxSendQueueSize),
          m_sendMutex(QMutex::Recursive),
          m_recvMutex(QMutex::Recursive)
    {
        m_sendWorkerThread = new CoreDriverSendThread(this);
        m_recvWorkerThread = new CoreDriverRecvThread(this);
    }

    CoreDriver::~CoreDriver()
    {
        stop();

        //Should delete remaining messages
        while (m_sendQueue.size() > 0)
        {
            delete m_sendQueue.front();
            m_sendQueue.pop_front();
        }

        while(m_recvQueue.size() > 0)
        {
            delete m_recvQueue.front();
            m_recvQueue.pop_front();
        }

    }

    void CoreDriver::start()
    {
        m_sendWorkerThread->start();
        m_recvWorkerThread->start();
    }

    void CoreDriver::stop()
    {
        m_sendWorkerThread->quit();
        m_sendWorkerThread->wait();
        m_recvWorkerThread->quit();
        m_sendWorkerThread->wait();
    }

    bool CoreDriver::pushRecvMessage(CoreMessage *message)
    {
        QMutexLocker lock(&m_recvMutex);

        if (message && m_recvQueue.size() < m_maxRecvQueueSize)
        {
            m_recvQueue.push_back(message);
            return true;
        }

        return false;
    }

    bool CoreDriver::pushSendMessage(CoreMessage *message)
    {
        QMutexLocker lock(&m_sendMutex);

        if (message && m_sendQueue.size() < m_maxSendQueueSize)
        {
            m_sendQueue.push_back(message);
            return true;
        }

        return false;
    }

    bool CoreDriver::sendMessage(CoreMessage *message)
    {
        return pushSendMessage(message);
    }

    CoreMessage* CoreDriver::recvMessage()
    {
        QMutexLocker lock(&m_recvMutex);
        CoreMessage *message = NULL;

        if (m_recvQueue.size() > 0)
        {
            message = m_recvQueue.front();
            m_recvQueue.pop_front();
        }

        return message;
    }

    QList<CoreMessage*> CoreDriver::recvAllMessages()
    {
         QMutexLocker lock(&m_recvMutex);
         QList<CoreMessage*> myList = m_recvQueue;
         m_recvQueue.clear();
         return myList;
    }


    int CoreDriver::sendQueueSize()
    {
        QMutexLocker lock(&m_sendMutex);
        return m_sendQueue.size();
    }

    int CoreDriver::recvQueueSize()
    {
        QMutexLocker lock(&m_recvMutex);
        return m_recvQueue.size();
    }

    bool CoreDriver::sendQueueFull()
    {
        QMutexLocker lock(&m_sendMutex);
        return (m_sendQueue.size() > m_maxSendQueueSize);
    }

    bool CoreDriver::recvQueueFull()
    {
        QMutexLocker lock(&m_recvMutex);
        return (m_recvQueue.size() > m_maxRecvQueueSize);
    }

    void CoreDriver::setSendQueueMaxSize(int size)
    {
        QMutexLocker lock(&m_sendMutex);
        m_maxSendQueueSize = size;
    }

    void CoreDriver::setRecvQueueMaxSize(int size)
    {
        QMutexLocker lock(&m_recvMutex);
        m_maxRecvQueueSize = size;
    }

    CoreMessage* CoreDriver::pullRecvMessage()
    {
        QMutexLocker lock(&m_recvMutex);
        CoreMessage *message = NULL;
        if (m_recvQueue.size() > 0)
        {
            message = m_recvQueue.front();
            m_recvQueue.pop_front();
        }
        return message;
    }

    CoreMessage* CoreDriver::pullSendMessage()
    {
        QMutexLocker lock(&m_sendMutex);
        CoreMessage *message = NULL;
        if (m_sendQueue.size() > 0)
        {
            message = m_sendQueue.front();
            m_sendQueue.pop_front();
        }
        return message;
    }

}//namespace netcore
