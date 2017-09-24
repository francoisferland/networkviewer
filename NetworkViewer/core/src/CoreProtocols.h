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
#ifndef _CORE_PROTOCOLS_H_
#define _CORE_PROTOCOLS_H_

#include "Core.h"
#include <QString>
#include <QDebug>

namespace netcore
{
    class NETVCORE_EXPORT CoreProtocols
    {
    public:
        typedef enum {RAW_CAN, NETV_CAN, RAW_ETHERNET, NETV_ETHERNET, RAW_SERIAL, NETV_SERIAL} CORE_PROTOCOL_TYPE;

        static QString typeToString(CORE_PROTOCOL_TYPE type)
        {
            QString typeName = "UNKNOWN";

            switch(type)
            {
            case RAW_CAN:
                typeName = "RAW_CAN";
                break;

            case NETV_CAN:
                typeName = "NETV_CAN";
                break;

            case RAW_ETHERNET:
                typeName = "RAW_ETHERNET";
                break;

            default:
                qCritical("Unhandled protocol type : %i",type);
                break;
            }


            return typeName;
        }
    };
}

#endif //_CORE_PROTOCOLS_H_
