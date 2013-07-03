#include "CoreSerializer.h"
#include "CANMessage.h"
#include "NETVMessage.h"
#include <QBuffer>
#include <QDataStream>

using namespace netcore;

class mySerializer : public CoreSerializer
{
public:
    virtual QByteArray serialize(const CoreMessage &message)
    {
        qDebug("virtual QByteArray serialize(const CoreMessage &message)");
        QBuffer buf;
        buf.open(QIODevice::WriteOnly);

        QDateTime timestamp = message.timestamp();

        CoreProtocols::CORE_PROTOCOL_TYPE type = message.protocolType();

        int interfaceID = message.interfaceID();

        QDataStream stream(&buf);



        stream << timestamp;
        stream << type;
        stream << interfaceID;



        return buf.data();
    }

    virtual QByteArray serialize(const CANMessage &message)
    {
        qDebug("QByteArray serialize(const CANMessage &message)");
        QBuffer buf;
        return buf.data();
    }

    virtual QByteArray serialize(const NETVMessage &message)
    {
        qDebug("QByteArray serialize(const NETVMessage &message)");
        QBuffer buf;
        return buf.data();
    }
};

int main(int argc, char* argv[])
{

    CoreMessage* message1 = new CANMessage(0,CANMessage::NoFlag,QByteArray());
    CoreMessage* message2 = new NETVMessage(0,0,0,0,0,0,QByteArray());

    mySerializer ser;

    message1->serialize(ser);
    message2->serialize(ser);


    return 0;
}
