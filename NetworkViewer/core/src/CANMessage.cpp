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

#include "CANMessage.h"
#include <QDebug>
#include <QBuffer>

namespace netcore
{

    CANMessage::CANMessage()
        :   CoreMessage(QDateTime::currentDateTime(), CoreProtocols::RAW_CAN)
    {

    }

    CANMessage::CANMessage(const CANMessage &cpy)
        :   CoreMessage(cpy.timestamp(),cpy.protocolType(),cpy.interfaceID())
    {
        m_eid = cpy.m_eid;
        m_flags = cpy.m_flags;
        m_data = cpy.m_data;
        validityCheck();
    }

    CANMessage::CANMessage(quint32 eid, quint32 flags, const QByteArray &data)
        :   CoreMessage(QDateTime::currentDateTime(), CoreProtocols::RAW_CAN)
    {
        m_eid = eid;
        m_flags = flags;
        m_data = data;
        validityCheck();
    }

    CANMessage& CANMessage::operator=(const CANMessage& cpy)
    {
        m_eid = cpy.m_eid;
        m_flags = cpy.m_flags;
        m_data = cpy.m_data;

        //Must copy base class information
        //Can we do better?
        m_timestamp = cpy.m_timestamp;
        m_protocolType = cpy.m_protocolType;
        m_interfaceID = cpy.m_interfaceID;
        return *this;
    }

    void CANMessage::setFlags(quint32 flags)
    {
        m_flags = flags;
    }

    bool CANMessage::setPayload(const QByteArray &data)
    {
        m_data = data;
        return validityCheck();
    }

    QByteArray CANMessage::payload() const
    {
        return m_data;
    }

    int CANMessage::payloadSize() const
    {
        return m_data.size();
    }

    bool CANMessage::isExtended() const
    {
        return (m_flags | ExtendedFlag);
    }

    bool CANMessage::isError() const
    {
        return (m_flags | ErrorFlag);
    }

    bool CANMessage::isRemote() const
    {
        return (m_flags | RTRFlag);
    }

    bool CANMessage::isValid() const
    {
        return !(m_flags | InvalidFlag);
    }

    bool CANMessage::validityCheck()
    {
        bool retval = true;

        if (m_data.size() > MaxPayloadSize)
        {
            qWarning("Maximum CANMessage payload size reached (%i), marking invalid",m_data.size());
            m_flags |= InvalidFlag;
            retval = false;
        }

        return retval;
    }

    QByteArray CANMessage::serializedData()
    {
        QBuffer buf;
        buf.write((char*) &m_eid, sizeof(m_eid));
        buf.write((char*) &m_flags, sizeof(m_flags));
        int size = m_data.size();
        buf.write((char*) &size,sizeof(size));
        buf.write(m_data);
        return buf.data();
    }


    bool CANMessage::setSerializedData(const QByteArray &data)
    {
        QByteArray array(data);
        QBuffer buf(&array);

        buf.read((char*) &m_eid,sizeof(m_eid));
        buf.read((char*) &m_flags,sizeof(m_flags));

        int size = 0;
        buf.read((char*) &size, sizeof(size));

        m_data = buf.read(size);

        if (m_data.size() == size)
        {
            return validityCheck();
        }

        return false;
    }


    void CANMessage::clear()
    {
        m_data.resize(0);
    }

    int CANMessage::maxPayloadSize() const
    {
        return MaxPayloadSize;
    }

    CoreMessage* CANMessage::clone()
    {
        return new CANMessage(*this);
    }


} //namespace netcore
