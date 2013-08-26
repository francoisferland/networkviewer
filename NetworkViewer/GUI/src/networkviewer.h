#ifndef _NETWORKVIEWER_H_
#define _NETWORKVIEWER_H_

#include "ui_networkviewer.h"
#include "NetworkView.h"
#include "CoreDriver.h"
#include "CoreDriverFactory.h"
#include "NETVDriverManager.h"

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

        m_driver = netcore::CoreDriverFactoryBase::create("Loopback",QStringList(),NULL);
        m_manager = new netcore::NETVDriverManager(m_driver,this);
    }

public slots:

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

    void onNetworkViewDestroyed()
    {
        m_view = NULL;
    }

protected:

    Ui::networkviewer m_ui;
    netcore::CoreDriver *m_driver;
    netcore::CoreDriverManager *m_manager;
    NetworkView *m_view;

};

#endif