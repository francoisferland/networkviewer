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
#ifndef _CORE_DRIVER_FACTORY_H_
#define _CORE_DRIVER_FACTORY_H_

#include "CoreDriverInfo.h"
#include <QStringList>
#include <QMap>

namespace netcore
{
    //Forward declaration of CoreDriver
    class CoreDriver;



    class CoreDriverFactoryBase
    {

    public:

        CoreDriverFactoryBase();

        ///Driver creation
        virtual CoreDriver* create(QStringList args) = 0;

        ///Driver configuration (before creation)
        virtual void configure(QStringList args);

        static bool registerDriverFactory(const CoreDriverInfo &info, CoreDriverFactoryBase* factory);
        static void scanDrivers(const QString &basePath);
        static QMap<CoreDriverInfo,CoreDriverFactoryBase*>& getFactoryMap();

     protected:

    };


    template <class T>
    class CoreDriverFactory : public CoreDriverFactoryBase
    {

    public:

        //Default constructor
        CoreDriverFactory()
        {

        }

        virtual CoreDriver* create(QStringList args)
        {
            //Create driver with no parent
            CoreDriver* driver = new T(NULL);
            //driver->initialize(args);
            return driver;
        }


    protected:





    };


}//namespace netcore

#endif //_CORE_DRIVER_FACTORY_H_

