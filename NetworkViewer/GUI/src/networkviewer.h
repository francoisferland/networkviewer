#ifndef _NETWORKVIEWER_H_
#define _NETWORKVIEWER_H_

#include "ui_networkviewer.h"
#include "NetworkView.h"

class NetworkViewer : public QMainWindow
{
    Q_OBJECT
public:

    NetworkViewer(QWidget *parent = NULL)
        : QMainWindow(parent), m_view(NULL)
    {
        m_ui.setupUi(this);
        setWindowTitle(QString("NetworkViewer-") + QString(NETWORKVIEWER_VERSION));
        connect(m_ui.pushButton,SIGNAL(clicked()),this,SLOT(onButtonClicked()));
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

    void onNetworkViewDestroyed()
    {
        m_view = NULL;
    }

protected:

    Ui::networkviewer m_ui;

    NetworkView *m_view;

};

#endif
