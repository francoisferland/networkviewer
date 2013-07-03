#include "CoreSerializer.h"
#include "CANMessage.h"
#include "NETVMessage.h"
#include <QBuffer>
#include <QDataStream>

using namespace netcore;

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

int main(int argc, char* argv[])
{

    CoreMessage* message1 = new CANMessage(0,CANMessage::NoFlag,QByteArray());
    CoreMessage* message2 = new NETVMessage(0,0,0,0,0,0,QByteArray());

    mySerializer ser;
    QBuffer buf;
    buf.open(QIODevice::ReadWrite);

    message1->serialize(ser,buf);
    message2->serialize(ser,buf);


    return 0;
}
