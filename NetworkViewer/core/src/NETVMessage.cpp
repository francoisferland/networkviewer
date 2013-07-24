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

#include "NETVMessage.h"

namespace netcore
{

    NETVMessage::NETVMessage()
        : CANMessage(0,CANMessage::ExtendedFlag, QByteArray())
    {
        m_protocolType = CoreProtocols::NETV_CAN;
    }

    NETVMessage::NETVMessage(quint8 priority, quint8 type, quint8 boot_flags, quint8 command, quint8 dest, quint32 flags, QByteArray payload)
        :    CANMessage(0,CANMessage::ExtendedFlag | flags, payload)
    {
        //Set protocol type
        m_protocolType = CoreProtocols::NETV_CAN;

        //Updated m_eid according to fields.
        setEID(priority,type,boot_flags,command,dest);

    }

    NETVMessage::NETVMessage(const NETVMessage &cpy)
        :  CANMessage(cpy)
    {
        m_protocolType = CoreProtocols::NETV_CAN;
    }

    void NETVMessage::setEID(quint8 priority, quint8 type, quint8 boot_flags, quint8 command, quint8 dest)
    {
        //ID
        m_eid  = 0;

        //priority
        m_eid  |= (((quint32)priority << 26) & 0x1C000000);

        //type
        m_eid  |= (((quint32)type << 18) & 0x03FC0000);

        //boot
        m_eid  |= (((quint32)boot_flags << 16) & 0x00030000);

        //cmd
        m_eid  |= (((quint32)command << 8) & 0x0000FF00);

        //dest
        m_eid |= (((quint32)dest) & 0x000000FF);
    }

    CoreMessage* NETVMessage::clone() const
    {
        return new NETVMessage(*this);
    }

    bool NETVMessage::serialize(CoreSerializer& ser, QIODevice &dev)
    {
        return ser.serialize(*this,dev);
    }

    bool NETVMessage::deserialize(CoreDeserializer &des, QIODevice &dev)
    {
        return des.deserialize(*this,dev);
    }

    quint8 NETVMessage::getPriority() const
    {
        return (quint8) ((m_eid & 0x1C000000) >> 26);
    }

    quint8 NETVMessage::getType() const
    {
        return (quint8) ((m_eid & 0x03FC0000) >> 18);
    }

    quint8 NETVMessage::getBootFlags() const
    {
        return (quint8) ((m_eid & 0x00030000) >> 16);
    }

    quint8 NETVMessage::getCommand() const
    {
        return (quint8) ((m_eid & 0x0000FF00) >> 8);
    }

    quint8 NETVMessage::getDestination() const
    {
        return (quint8) ((m_eid & 0x000000FF));
    }

    void NETVMessage::setPriority(quint8 priority)
    {
        m_eid  |= (((quint32)priority << 26) & 0x1C000000);
    }

    void NETVMessage::setType(quint8 type)
    {
        m_eid  |= (((quint32)type << 18) & 0x03FC0000);
    }

    void NETVMessage::setBootFlags(quint8 bootflags)
    {
        m_eid  |= (((quint32)bootflags << 16) & 0x00030000);
    }

    void NETVMessage::setCommand(quint8 command)
    {
        m_eid  |= (((quint32)command << 8) & 0x0000FF00);
    }

    void NETVMessage::setDestination(quint8 dest)
    {
        m_eid |= (((quint32)dest) & 0x000000FF);
    }


}//namespace netcore

