#include "networkviewer.h"
#include "CoreDriverFactory.h"

//Test application
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);

    //Scan for all drivers (from bin/drivers_new)
    netcore::CoreDriverFactoryBase::scanDrivers(QCoreApplication::applicationDirPath() + "/drivers_new");


    netcore::CoreDriverFactoryBase::CoreDriverFactoryMap driverMap = netcore::CoreDriverFactoryBase::registeredDrivers();

    for (netcore::CoreDriverFactoryBase::CoreDriverFactoryMap::iterator iter = driverMap.begin(); iter != driverMap.end(); iter++)
    {
        qDebug() << iter.key();
    }

    netcore::CoreDriver *driver = netcore::CoreDriverFactoryBase::create("Loopback",QStringList(),NULL);

    if(driver)
    {
        driver->start();
    }

    NetworkViewer nv;
    nv.show();
    return app.exec();
}
