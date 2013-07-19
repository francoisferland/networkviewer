#include "CoreSerializer.h"
#include "CANMessage.h"
#include "NETVMessage.h"
#include <QBuffer>
#include <QDataStream>
#include <QCoreApplication>
#include <CoreDriver.h>
#include <QTimer>
#include "NETVMessage.h"


namespace netcore
{

    class mySerializer : public CoreSerializer
    {
    public:
        virtual bool serialize(const CoreMessage &message,QIODevice &dev)
        {
            qDebug("bool mySerializer::serialize(const CoreMessage &message)");
            return true;
        }

        virtual bool serialize(const CANMessage &message, QIODevice &dev)
        {
            qDebug("bool mySerializer::serialize(const CANMessage &message)");
            return true;
        }

        virtual bool serialize(const NETVMessage &message, QIODevice &dev)
        {
            qDebug("bool mySerializer::serialize(const NETVMessage &message)");
            return true;
        }

    };




    class myDriver : public CoreDriver
    {
        Q_OBJECT

    public:

        myDriver(QObject *parent)
            : CoreDriver(parent)
        {

        }

        ~myDriver()
        {
            qDebug("~myDriver()");
        }

        virtual CoreDriverInfo info()
        {
            return CoreDriverInfo("myDriver",0,0,0,"Test driver",QStringList(), NULL);
        }

        //Init & config
        virtual CoreDriverState initialize(QStringList args)
        {
            return CoreDriver::DRIVER_OK;
        }

        virtual void terminate()
        {

        }

        virtual CoreDriverState state()
        {
            return CoreDriver::DRIVER_OK;
        }

    protected:
        virtual CoreDriverState  internalThreadRecvFunction()
        {
            //Will fill queue
            //qDebug("myDriver::internalThreadRecvFunction()");
            NETVMessage *message = new NETVMessage(0,0,0,0,0,0,QByteArray());
            if (!this->pushRecvMessage(message))
            {
                    //qDebug("Unable to push Recv Message, queue sized : %i",recvQueueSize());
                    delete message;
            }

            return CoreDriver::DRIVER_OK;
        }

        virtual CoreDriverState  internalThreadSendFunction()
        {
            //qDebug("myDriver::internalThreadSendFunction()");
            //Will send every message on the queue
            while(sendQueueSize() > 0)
            {
                //We own it now
                CoreMessage *message = pullSendMessage();

                QBuffer buf;
                buf.open(QIODevice::WriteOnly);

                message->serialize(ser,buf);


                qDebug("myDriver::internalThreadSendFunction() sending %p",message);
                //Write it somewhere

                //Delete message
                delete message;
            }
            return CoreDriver::DRIVER_OK;
        }

        mySerializer ser;
    };

}//namespace netcore
