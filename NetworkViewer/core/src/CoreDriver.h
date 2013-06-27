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
#ifndef _CORE_DRIVER_H_
#define _CORE_DRIVER_H_

#include "CoreProtocols.h"
#include "CoreMessage.h"
#include "CoreDriverFactory.h"
#include <QStringList>

namespace netcore
{

    class CoreDriver
    {
    public:

        ///Driver states
        typedef enum {DRIVER_OK,
                      DRIVER_FAIL,
                      DRIVER_OVERFLOW,
                      DRIVER_UNDERFLOW,
                      DRIVER_BUS,
                      DRIVER_NOT_INITIALIZED} CoreDriverState;


        CoreDriver();

        ~CoreDriver();

        //Naming and loading
        virtual int version() = 0;
        virtual QString name() = 0;

        //Init & config
        virtual CoreDriverState initialize(QStringList args) = 0;

        //Send & Receive
        virtual CoreDriverState sendMessage(CoreMessage &message) = 0;
        virtual CoreDriverState recvMessage(CoreMessage &message) = 0;
        virtual bool newMessageReady() = 0;



    protected:


    };

} //namespace netcore

#endif //_CORE_DRIVER_H_
