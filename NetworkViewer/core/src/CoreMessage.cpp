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

#include "CoreMessage.h"

namespace netcore
{
    CoreMessage::CoreMessage(QDateTime timestamp, CoreProtocols::CORE_PROTOCOL_TYPE id, int interfaceID)
        :   m_timestamp(timestamp), m_protocolType(id), m_interfaceID(interfaceID)
    {

    }

    CoreMessage::~CoreMessage()
    {

    }

    CoreProtocols::CORE_PROTOCOL_TYPE CoreMessage::protocolType() const
    {
        return m_protocolType;
    }

    int CoreMessage::interfaceID() const
    {
        return m_interfaceID;
    }

    void CoreMessage::setInterfaceID(int id)
    {
        m_interfaceID = id;
    }

    QDateTime CoreMessage::timestamp() const
    {
        return m_timestamp;
    }

    void CoreMessage::setTimestamp(const QDateTime &datetime)
    {
        m_timestamp = datetime;
    }

} //namespace netcore
