#include "test_Serializer.h"

using namespace netcore;

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    CoreMessage* message1 = new CANMessage(0,CANMessage::NoFlag,QByteArray());
    CoreMessage* message2 = new NETVMessage(0,0,0,0,0,0,QByteArray());

    mySerializer ser;
    QBuffer buf;
    buf.open(QIODevice::ReadWrite);

    message1->serialize(ser,buf);
    message2->serialize(ser,buf);


    myDriver driver(NULL);

    driver.start();

    return app.exec();
}
