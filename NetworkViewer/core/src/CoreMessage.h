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
#include "CoreSerializer.h"
#include "CoreDeserializer.h"

namespace netcore
{
    class CoreMessage
    {
        friend class CoreSerializer;
        friend class CoreDeserializer;

    public:

        ///Visitor pattern for serialization / deserialization
        virtual bool serialize(CoreSerializer& ser, QIODevice &dev) = 0;
        virtual bool deserialize(CoreDeserializer &des, QIODevice &dev) = 0;

        virtual ~CoreMessage();

        ///Cloning message
        virtual CoreMessage* clone() const = 0;


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


    }; //class CoreMessage
} //namespace netcore

#endif //_CORE_MESSAGE_H_
