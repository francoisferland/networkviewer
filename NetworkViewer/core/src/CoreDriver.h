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
#ifndef _CORE_DRIVER_H_
#define _CORE_DRIVER_H_

#include "CoreProtocols.h"
#include "CoreMessage.h"
#include "CoreDriverInfo.h"
#include <QStringList>
#include <QThread>
#include <QQueue>
#include <QMutex>

namespace netcore
{
    class CoreDriver;

    class CoreDriverRecvThread : public QThread
    {
        Q_OBJECT

    public:
        CoreDriverRecvThread(CoreDriver *parent);
        virtual void run();
    protected:
        CoreDriver *m_driver;
    };

    class  CoreDriverSendThread : public QThread
    {
        Q_OBJECT

    public:
        CoreDriverSendThread(CoreDriver *parent);
        virtual void run();
    protected:
        CoreDriver *m_driver;
    };

    class CoreDriver : public QObject
    {

        Q_OBJECT

        friend class CoreDriverRecvThread;
        friend class CoreDriverSendThread;

    public:

        static const int MAX_RECV_QUEUE_SIZE=5000;
        static const int MAX_SEND_QUEUE_SIZE=5000;

        ///Driver states
        typedef enum {DRIVER_OK,
                      DRIVER_FAIL,
                      DRIVER_OVERFLOW,
                      DRIVER_UNDERFLOW,
                      DRIVER_BUS,
                      DRIVER_NOT_INITIALIZED} CoreDriverState;


        CoreDriver(QObject *parent = NULL, int maxRecvQueueSize = MAX_RECV_QUEUE_SIZE, int maxSendQueueSize=MAX_SEND_QUEUE_SIZE);

        virtual ~CoreDriver();

        //Naming and loading
        virtual CoreDriverInfo info() = 0;

        //Init & config
        virtual CoreDriverState initialize(QStringList args) = 0;

        virtual void terminate() = 0;

        //state
        virtual CoreDriverState state() = 0;

        //Start & Stop
        virtual void start();
        virtual void stop();




        //Send & Receive from queue (external to driver usage)
        virtual bool sendMessage(CoreMessage *message);
        virtual CoreMessage* recvMessage();
        virtual QList<CoreMessage*> recvAllMessages();
        virtual int sendQueueSize();
        virtual int recvQueueSize();
        virtual bool sendQueueFull();
        virtual bool recvQueueFull();
        void setSendQueueMaxSize(int size);
        void setRecvQueueMaxSize(int size);




    protected:

        //Driver internals
        virtual bool internalThreadRecvFunction() = 0;
        virtual bool internalThreadSendFunction() = 0;
        bool pushRecvMessage(CoreMessage *message);
        CoreMessage* pullRecvMessage();
        bool pushSendMessage(CoreMessage *message);
        CoreMessage* pullSendMessage();

        int m_maxSendQueueSize;
        int m_maxRecvQueueSize;


    private:

        QMutex m_recvMutex;
        QMutex m_sendMutex;      
        CoreDriverSendThread *m_sendWorkerThread;
        CoreDriverRecvThread *m_recvWorkerThread;
        QQueue<CoreMessage*> m_sendQueue;
        QQueue<CoreMessage*> m_recvQueue;

    };

} //namespace netcore

#endif //_CORE_DRIVER_H_
