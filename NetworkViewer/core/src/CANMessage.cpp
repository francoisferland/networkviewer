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

namespace netcore
{

    CANMessage::CANMessage()
        :   CoreMessage(QDateTime::currentDateTime(), CoreProtocols::RAW_CAN)
    {

    }


    CANMessage::CANMessage(const CANMessage &cpy)
        :   CoreMessage(cpy.timestamp(),CoreProtocols::RAW_CAN,cpy.interfaceID())
    {
        /*
        quint32 m_eid;
        quint32 m_flags;
        QByteArray m_data;
        */
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

    void CANMessage::setFlags(quint32 flags)
    {
        m_flags = flags;
    }

    bool CANMessage::setPayload(const QByteArray &data)
    {
        m_data = data;
        validityCheck();
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

        return (m_flags | CANMessageExtendedFlag);
    }

    bool CANMessage::isError() const
    {
        return (m_flags | CANMessageErrorFlag);
    }

    bool CANMessage::isRemote() const
    {
        return (m_flags | CANMessageRTRFlag);
    }

    bool CANMessage::isValid() const
    {
        return !(m_flags | CANMessageInvalidFlag);
    }

    void CANMessage::validityCheck()
    {
        if (m_data.size() > CANMessageMaxPayloadSize)
        {
            qWarning("Maximum CANMessage payload size reached (%i), marking invalid",m_data.size());
            m_flags |= CANMessageInvalidFlag;
        }
    }


} //namespace netcore
