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
#ifndef _CORE_SERIALIZER_H_
#define _CORE_SERIALIZER_H_

#include <QIODevice>
#include <QDebug>
#include "Core.h"

namespace netcore
{

    class CANMessage;
    class NETVMessage;
    class CoreMessage;

    class NETVCORE_EXPORT CoreSerializer
    {
    public:
        //Convert a message to a series of bytes
        virtual bool serialize(const CoreMessage &message, QIODevice &dev);
        virtual bool serialize(const CANMessage &message, QIODevice &dev);
        virtual bool serialize(const NETVMessage &message, QIODevice &dev);
    };

} //namespace netcore

#endif //_CORE_SERIALIZER_H_
