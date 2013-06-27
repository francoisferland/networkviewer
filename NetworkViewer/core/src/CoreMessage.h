/**
     Copyright (C) 2009-2013 IntRoLab
     http://introlab.3it.usherbrooke.ca
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

#ifndef _CORE_MESSAGE_H_
#define _CORE_MESSAGE_H_

#include "CoreProtocols.h"
#include <QByteArray>
#include <QDateTime>
#include <QIODevice>

namespace netcore
{
    class CoreMessage
    {
    public:


        int size();

        ///Message serialized form, needs to be implemented
        virtual QByteArray data() = 0;
        ///Set message data from serialized form
        virtual bool setData(const QByteArray &data) = 0;
        ///Clear message
        virtual void clear() = 0;
        ///Max data size
        virtual int maxSize() = 0;
        ///Cloning message
        virtual CoreMessage* clone() = 0;

        ///Overloaded function to set data, will call setData(const QByteArray &data)
        virtual bool setData(const char* data, int size);
        int serialize(QIODevice &dev);
        bool unserialize(QIODevice &dev);

        CoreProtocols::CORE_PROTOCOL_TYPE protocolType() const;
        int interfaceID() const;

        void setInterfaceID(int id);
        QDateTime timestamp() const;
        void setTimestamp(const QDateTime &datetime);

    protected:
        CoreMessage(QDateTime timestamp, CoreProtocols::CORE_PROTOCOL_TYPE id, int interfaceID = -1);


        QDateTime m_timestamp;
        CoreProtocols::CORE_PROTOCOL_TYPE m_protocolType;
        int m_interfaceID;

    private:
        CoreMessage();
        /*
        CoreMessage(const QByteArray &data);
        CoreMessage(const char*, int size);
        CoreMessage(const CoreMessage &message);
        CoreMessage& operator= (const CoreMessage &message);
        */

    };
}

#endif //_CORE_MESSAGE_H_
