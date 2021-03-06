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

#ifndef _NETV_REMOTE_CLIENT_H_
#define _NETV_REMOTE_CLIENT_H_

#include <QTcpSocket>
#include "Core.h"
#include "NETVDevice.h"

class NETVCORE_EXPORT NETVRemoteClient : public QTcpSocket
{
    Q_OBJECT

public :

    NETVRemoteClient(const QString &hostname, int port, QObject *parent = NULL);

public slots:
    void sendMessage(const NETV_MESSAGE &msg);


signals:

    void messageReady(const NETV_MESSAGE &msg);




protected slots:

    void clientConnected(void);
    void clientDisconnected(void);
    void readyReadSocket(void);
    void writeError(QAbstractSocket::SocketError socketError);

 protected:

    bool event ( QEvent * e );
};

#endif
