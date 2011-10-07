/**
     Copyright (C) 2011 IntRoLab
     http://introlab.gel.usherbrooke.ca
     Dominic Letourneau, ing. M.Sc.A.
     Dominic.Letourneau@USherbrooke.ca

     This file is part of OpenECoSys/NetworkViewer.
     OpenECoSys/NetworkViewer is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by the Free Software
     Foundation, either version 3 of the License, or (at your option) any later version.
     OpenECoSys/NetworkViewer is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
     or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
     You should have received a copy of the GNU General Public License along with
     OpenECoSys/NetworkViewer. If not, see http://www.gnu.org/licenses/.

 */

#include "NETVRemoteServer.h"
#include "NETVMessageEvent.h"
#include <QtDebug>

NETVRemoteServer::NETVRemoteServer(QObject *parent)
    :   QTcpServer(parent)
{
    qDebug("NETVRemoteServer::NETVRemoteServer(QObject *parent = %p)",parent);

    //Listen for incoming conn...
    if (listen(QHostAddress::Any, NETVRemoteServer::DEFAULT_PORT))
    {
        qDebug("Listening on port %i", NETVRemoteServer::DEFAULT_PORT);
    }
}

void NETVRemoteServer::incomingConnection(int socketDescriptor)
{
    qDebug("NETVRemoteServer::incomingConnection(int socketDescriptor = %i)",socketDescriptor);

    //Creating socket
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    //Must be called so server know we have a socket pending...
    addPendingConnection(socket);

    //TODO socket disconnected signal


    //Add socket to the list
    m_socketList.push_back(socket);
}

void NETVRemoteServer::addInterface(NETVInterfaceManager *manager)
{
    if(manager->getInterfaceHandler())
    {
        manager->getInterfaceHandler()->registerObserver(this);
    }
}

void NETVRemoteServer::removeInterface(NETVInterfaceManager *manager)
{
    if (manager->getInterfaceHandler())
    {
        manager->getInterfaceHandler()->unregisterObserver(this);
    }
}

void NETVRemoteServer::notifyNETVMessage(const NETV_MESSAGE &msg)
{
    //This is called from another thread, be careful
    //Sending an event to ourself
    QCoreApplication::postEvent(this,new NETVMessageEvent(msg),Qt::HighEventPriority);
}

bool NETVRemoteServer::event ( QEvent * e )
{
    if (e->type() == QEvent::User)
    {
        //qDebug("NETVInterfaceManager::event %p QEvent::User",e);
        if (NETVMessageEvent *event = dynamic_cast<NETVMessageEvent*>(e))
        {
            //Send message to all sockets
            for (unsigned int i = 0; i < m_socketList.size(); i++)
            {
                //NETV_MESSAGE &msg = event->getMessage();
                event->getMessage().serialize(*m_socketList[i]);

            }

            return true;
        }
    }

    return QObject::event(e);
}