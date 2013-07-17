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
#include "CoreSerializer.h"
#include "CoreMessage.h"
#include "CANMessage.h"
#include "NETVMessage.h"
#include <typeinfo>

namespace netcore
{
    bool CoreSerializer::serialize(const CoreMessage &message, QIODevice &dev)
    {
        qWarning("Unimplemented serializer for type : %s",typeid(&message).name());
        return false;
    }

    bool CoreSerializer::serialize(const CANMessage &message, QIODevice &dev)
    {
        qWarning("Unimplemented serializer for CANMessage? type : %i",message.protocolType());
        return false;
    }

    bool CoreSerializer::serialize(const NETVMessage &message, QIODevice &dev)
    {
        qWarning("Unimplemented serializer for NETVMessage? type : %i",message.protocolType());
        return false;
    }

} //namespace netcore
