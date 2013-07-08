#include "test_Serializer.h"

using namespace netcore;

class testApp : public QCoreApplication
{
public:
    testApp(int argc, char* argv[])
        : QCoreApplication(argc,argv), m_driver(this)
    {

        CoreMessage* message1 = new CANMessage(0,CANMessage::NoFlag,QByteArray());
        CoreMessage* message2 = new NETVMessage(0,0,0,0,0,0,QByteArray());

        m_driver.sendMessage(message1);
        m_driver.sendMessage(message2);

        m_driver.start();
    }

    ~testApp()
    {
        qDebug("~testApp...");
    }

protected:
    myDriver m_driver;
};




int main(int argc, char* argv[])
{
    testApp app(argc, argv);



    return app.exec();
}
