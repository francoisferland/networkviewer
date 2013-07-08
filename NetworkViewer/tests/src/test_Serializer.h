#include "CoreSerializer.h"
#include "CANMessage.h"
#include "NETVMessage.h"
#include <QBuffer>
#include <QDataStream>
#include <QCoreApplication>
#include <CoreDriver.h>

namespace netcore
{

    class mySerializer : public CoreSerializer
    {
    public:
        virtual bool serialize(const CoreMessage &message,QIODevice &dev)
        {
            qDebug("virtual QByteArray serialize(const CoreMessage &message)");
            return true;
        }

        virtual bool serialize(const CANMessage &message, QIODevice &dev)
        {
            qDebug("QByteArray serialize(const CANMessage &message)");
            return true;
        }

        virtual bool serialize(const NETVMessage &message, QIODevice &dev)
        {
            qDebug("QByteArray serialize(const NETVMessage &message)");
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

        }

        virtual int version()
        {
            return 0;
        }

        virtual QString name()
        {
            return "myDriver";
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
        virtual bool internalThreadRecvFunction()
        {
            qDebug("myDriver::internalThreadRecvFunction()");
            return true;
        }

        virtual bool internalThreadSendFunction()
        {
            qDebug("myDriver::internalThreadSendFunction()");
            return true;
        }
    };

}//namespace netcore
