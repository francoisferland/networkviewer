#ifndef _NETWORKVIEWER_H_
#define _NETWORKVIEWER_H_

#include "ui_networkviewer.h"
#include "NetworkView.h"
#include "CoreDriver.h"
#include "CoreDriverFactory.h"
#include "NETVDriverManager.h"
#include "NETVModuleView.h"

class NetworkViewer : public QMainWindow
{
    Q_OBJECT
public:

    NetworkViewer(QWidget *parent = NULL)
        : QMainWindow(parent), m_view(NULL), m_driver(NULL)
    {
        m_ui.setupUi(this);
        setWindowTitle(QString("NetworkViewer-") + QString(NETWORKVIEWER_VERSION));
        connect(m_ui.m_startButton,SIGNAL(clicked()),this,SLOT(onStartButtonClicked()));
        connect(m_ui.m_stopButton,SIGNAL(clicked()),this,SLOT(onStopButtonClicked()));
        connect(m_ui.m_moduleViewButton,SIGNAL(clicked()),this,SLOT(onNETVModuleViewButtonClicked()));

        m_driver = netcore::CoreDriverFactoryBase::create("Loopback",QStringList(),NULL);
        m_manager = new netcore::NETVDriverManager(m_driver,this);

        connect(m_ui.m_clearLogButton,SIGNAL(clicked()),this,SLOT(onClearLogButtonClicked()));
        connect(m_ui.m_filterRegEx,SIGNAL(textChanged(QString)),this,SLOT(onFilterChanged(QString)));
    }

public slots:

    void onDebugInfo(QString info)
    {
        QRegExp exp(m_filterString);
        if (info.contains(exp))
        {
            m_ui.m_textEdit->append(info);
        }
    }

    void onClearLogButtonClicked()
    {
        m_ui.m_textEdit->clear();
    }


    void onStartButtonClicked()
    {
        if (m_driver)
        {
            m_driver->start();
            m_manager->start();
        }
    }

    void onStopButtonClicked()
    {
        if (m_driver)
        {
            m_driver->stop();
            m_manager->quit();
        }

    }

    void onNETVModuleViewButtonClicked()
    {
        qDebug("onNETVModuleViewButtonClicked()");
        QList<netcore::CoreDriverManager*> myList;
        myList.push_back(m_manager);
        m_moduleView = new netvgui::NETVModuleView(this,myList);
        m_moduleView->show();
    }

    void onNetworkViewDestroyed()
    {
        m_view = NULL;
    }

    void onFilterChanged(QString value)
    {
        m_filterString = value;
    }

protected:

    Ui::networkviewer m_ui;
    netcore::CoreDriver *m_driver;
    netcore::CoreDriverManager *m_manager;
    NetworkView *m_view;
    netvgui::NETVModuleView *m_moduleView;
    QString m_filterString;
};



class NetworkViewerApp : public QApplication
{

    friend void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    Q_OBJECT

public:
    NetworkViewerApp(int argc, char* argv[])
        : QApplication(argc,argv), m_networkviewer(NULL)
    {



    }

    void init()
    {
        //Scan for all drivers (from bin/drivers_new)
        netcore::CoreDriverFactoryBase::scanDrivers(QCoreApplication::applicationDirPath() + "/drivers_new");


        netcore::CoreDriverFactoryBase::CoreDriverFactoryMap driverMap = netcore::CoreDriverFactoryBase::registeredDrivers();

        for (netcore::CoreDriverFactoryBase::CoreDriverFactoryMap::iterator iter = driverMap.begin(); iter != driverMap.end(); iter++)
        {
            qDebug() << iter.key();
        }

        //Debug display
        m_networkviewer = new NetworkViewer(NULL);
        connect(this,SIGNAL(debugInfo(QString)),m_networkviewer,SLOT(onDebugInfo(QString)));
        m_networkviewer->show();
    }

signals:
    void debugInfo(QString info);

public slots:

    void displayDebug(QString info)
    {

    }

protected:

    void emitDebugInfo(QString info)
    {
        emit debugInfo(info);
    }

    NetworkViewer *m_networkviewer;

};



#endif
