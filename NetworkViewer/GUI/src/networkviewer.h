#ifndef _NETWORKVIEWER_H_
#define _NETWORKVIEWER_H_

#include "ui_networkviewer.h"
#include "NetworkView.h"
#include "CoreDriver.h"
#include "CoreDriverFactory.h"

class NetworkViewer : public QMainWindow
{
    Q_OBJECT
public:

    NetworkViewer(QWidget *parent = NULL)
        : QMainWindow(parent), m_view(NULL), m_driver(NULL)
    {
        m_ui.setupUi(this);
        setWindowTitle(QString("NetworkViewer-") + QString(NETWORKVIEWER_VERSION));
        connect(m_ui.pushButton,SIGNAL(clicked()),this,SLOT(onButtonClicked()));
        connect(m_ui.m_stopButton,SIGNAL(clicked()),this,SLOT(onStopButtonClicked()));

        m_driver = netcore::CoreDriverFactoryBase::create("Loopback",QStringList(),NULL);

        if (m_driver)
        {
            m_driver->start();
        }

    }

public slots:

    void onButtonClicked()
    {
        if (!m_view)
        {
            m_view = new NetworkView(m_ui.m_centerWidget);
            connect(m_view,SIGNAL(destroyed()),this,SLOT(onNetworkViewDestroyed()));
            m_view->show();
        }
    }

    void onStopButtonClicked()
    {
        if (m_driver)
        {
            m_driver->stop();
        }

    }

    void onNetworkViewDestroyed()
    {
        m_view = NULL;
    }

protected:

    Ui::networkviewer m_ui;
    netcore::CoreDriver *m_driver;
    NetworkView *m_view;

};

#endif
