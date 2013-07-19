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
        : QThread(parent), m_driver(parent), m_running(false)
    {
        Q_ASSERT(m_driver != NULL);
    }

    void CoreDriverRecvThread::run()
    {
        qDebug() << "CoreDriverRecvThread::run()" << " thread: " << QThread::currentThread();
        m_running = true;
        while(m_running)
        {
            CoreDriver::CoreDriverState state = m_driver->internalThreadRecvFunction();

            switch(state)
            {
                case CoreDriver::DRIVER_BUS:
                    usleep(1000);
                break;

                case CoreDriver::DRIVER_OK:
                    //Everything went well
                break;

                case CoreDriver::DRIVER_FAIL:
                    usleep(1000);
                break;

                case CoreDriver::DRIVER_UNDERFLOW:
                    usleep(1000);
                break;

                case CoreDriver::DRIVER_OVERFLOW:
                    usleep(1000);
                break;

                case CoreDriver::DRIVER_NOT_INITIALIZED:
                    usleep(1000);
                break;
            }

        }
        //Execute event loop
        exec();

        qDebug("CoreDriverRecvThread::run() - done");
    }

    void CoreDriverRecvThread::stop()
    {
        //This should be called from another thread
        Q_ASSERT(QThread::currentThread() != this);
        m_running = false;
        quit();
        wait();

        qDebug("CoreDriverRecvThread::stop() quit&wait ok");
    }


    CoreDriverSendThread::CoreDriverSendThread(CoreDriver *parent)
        : QThread(parent), m_driver(parent), m_running(false)
    {
        Q_ASSERT(m_driver != NULL);
    }


    void CoreDriverSendThread::run()
    {
        qDebug() << "CoreDriverSendThread::run()" << " thread: " << QThread::currentThread();
        m_running = true;
        while(m_running)
        {

            CoreDriver::CoreDriverState state = m_driver->internalThreadSendFunction();

            switch(state)
            {
                case CoreDriver::DRIVER_BUS:
                    usleep(1000);
                break;

                case CoreDriver::DRIVER_OK:
                    //Everything went well...
                break;

                case CoreDriver::DRIVER_FAIL:
                    usleep(1000);
                break;

                case CoreDriver::DRIVER_UNDERFLOW:
                    usleep(100);
                break;

                case CoreDriver::DRIVER_OVERFLOW:
                    usleep(100);
                break;

                case CoreDriver::DRIVER_NOT_INITIALIZED:
                    usleep(1000);
                break;
            }

        }

        //Execute event loop
        exec();

        qDebug("CoreDriverSendThread::run() - done");
    }

    void CoreDriverSendThread::stop()
    {
        //This should called from another thread
        Q_ASSERT(QThread::currentThread() != this);
        m_running = false;
        quit();
        wait();
        qDebug("CoreDriverSendThread::stop() quit&wait ok");
    }


    CoreDriver::CoreDriver(QObject *parent, int maxRecvQueueSize, int maxSendQueueSize)
        : QThread(parent),
          m_maxRecvQueueSize(maxRecvQueueSize),
          m_maxSendQueueSize(maxSendQueueSize),
          m_sendMutex(QMutex::Recursive),
          m_sendSemaphore(0),
          m_recvMutex(QMutex::Recursive),
          m_recvSemaphore(0),
          m_sendWorkerThread(NULL),
          m_recvWorkerThread(NULL)
    {

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

        Q_ASSERT(QThread::currentThread() != this);

        qDebug("CoreDriver::start()");
        if (m_sendWorkerThread == NULL)
        {
            m_sendWorkerThread = new CoreDriverSendThread(this);
            connect(m_sendWorkerThread,SIGNAL(destroyed()),this,SLOT(sendThreadDestroyed()));
            m_sendWorkerThread->start();
        }
        else
        {
            qWarning("CoreDriver::start() - sendWorkerThread already started");
        }

        if (m_recvWorkerThread == NULL)
        {
            m_recvWorkerThread = new CoreDriverRecvThread(this);
            connect(m_recvWorkerThread,SIGNAL(destroyed()),this,SLOT(recvThreaddestroyed()));
            m_recvWorkerThread->start();
        }
        else
        {
            qWarning("CoreDriver::start() - recvWorkerThread already started");
        }

        if(!QThread::isRunning())
        {
            moveToThread(this);
            //Start own thread
            QThread::start();
        }

    }

    void CoreDriver::stop()
    {
        Q_ASSERT(QThread::currentThread() != this);

        if (m_sendWorkerThread)
        {
            m_sendWorkerThread->stop();
            m_sendWorkerThread->deleteLater();
        }

        if (m_recvWorkerThread)
        {
            m_recvWorkerThread->stop();
            m_recvWorkerThread->deleteLater();
        }

        if (QThread::isRunning())
        {
            QThread::quit();
            QThread::wait();
        }

        //Go back to caller's thread
        //moveToThread(QThread::currentThread());
    }

    bool CoreDriver::sendMessage(CoreMessage *message)
    {
        return pushSendMessage(message);
    }

    CoreMessage* CoreDriver::recvMessage()
    {
        QMutexLocker lock(&m_recvMutex);
        CoreMessage *message = NULL;

        if (m_recvQueue.size() > 0 && m_recvSemaphore.tryAcquire(1,100))
        {
            message = m_recvQueue.front();
            m_recvQueue.pop_front();
        }
        return message;
    }

    QList<CoreMessage*> CoreDriver::recvAllMessages()
    {
         QMutexLocker lock(&m_recvMutex);
         QList<CoreMessage*> myList;
         if (m_recvSemaphore.tryAcquire(m_recvQueue.size()))
         {
            myList = m_recvQueue;
            m_recvQueue.clear();
         }
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

    //Driver internal
    CoreMessage* CoreDriver::pullRecvMessage()
    {
        QMutexLocker lock(&m_recvMutex);
        CoreMessage *message = NULL;
        if (m_recvQueue.size() > 0 && m_recvSemaphore.tryAcquire(1,100))
        {
            message = m_recvQueue.front();
            m_recvQueue.pop_front();
        }
        return message;
    }

    //Driver internal
    CoreMessage* CoreDriver::pullSendMessage()
    {
        QMutexLocker lock(&m_sendMutex);
        CoreMessage *message = NULL;
        if (m_sendQueue.size() > 0 && m_sendSemaphore.tryAcquire(1,100))
        {
            message = m_sendQueue.front();
            m_sendQueue.pop_front();
        }
        return message;
    }

    //Driver internal
    bool CoreDriver::pushRecvMessage(CoreMessage *message)
    {
        QMutexLocker lock(&m_recvMutex);

        if (message && m_recvQueue.size() < m_maxRecvQueueSize)
        {
            m_recvSemaphore.release(1);
            m_recvQueue.push_back(message);
            return true;
        }
        return false;
    }

    //Driver internal
    bool CoreDriver::pushSendMessage(CoreMessage *message)
    {
        QMutexLocker lock(&m_sendMutex);

        if (message && m_sendQueue.size() < m_maxSendQueueSize)
        {
            m_sendSemaphore.release(1);
            m_sendQueue.push_back(message);
            return true;
        }
        return false;
    }

    void CoreDriver::sendThreadDestroyed()
    {
        qDebug("CoreDriver::sendThreadDestroyed()");
        m_sendWorkerThread = NULL;
    }

    void CoreDriver::recvThreaddestroyed()
    {
        qDebug("CoreDriver::recvThreadDestroyed()");
        m_recvWorkerThread = NULL;
    }

    void CoreDriver::run()
    {
        CoreDriverInfo driverInfo = info();

        qDebug() << "CoreDriver::run() running : " << driverInfo.m_name << " thread: " << QThread::currentThread();

        //Execute event loop
        exec();

        qDebug() << "CoreDriver::run() done : " << driverInfo.m_name << " thread: " << QThread::currentThread();
    }

}//namespace netcore
