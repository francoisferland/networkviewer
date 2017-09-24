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

#include "Core.h"
#include "CoreDriverInfo.h"
#include <QStringList>
#include <QMap>
#include <QDir>
#include <QLibrary>
#include <QFileInfoList>
#include <QList>
#include "CoreDriver.h"

namespace netcore
{
    class NETVCORE_EXPORT CoreDriverFactoryBase
    {

    public:

        typedef QMap<CoreDriverInfo,CoreDriverFactoryBase*> CoreDriverFactoryMap;

        CoreDriverFactoryBase();

        ///Driver creation
        virtual CoreDriver* create(QStringList args, QObject *parent = NULL) = 0;

        static CoreDriver* create(const QString &name, QStringList args, QObject* parent=NULL);

        ///Driver configuration (before creation)
        virtual void configure(QStringList args);
        static bool registerDriverFactory(const CoreDriverInfo &info, CoreDriverFactoryBase* factory);
        static void scanDrivers(const QString &basePath);
        static bool getInfo(QString driverName, CoreDriverInfo &info);
        static QMap<CoreDriverInfo,CoreDriverFactoryBase*> registeredDrivers();

     protected:

        static QMap<CoreDriverInfo,CoreDriverFactoryBase*>& getFactoryMap();
        static void recursiveScan(QDir directory, int level = 0);

    };


    template <class T>
    class CoreDriverFactory : public CoreDriverFactoryBase
    {

    public:

        //Default constructor
        CoreDriverFactory()
        {

        }

        //virtual void configure(QStringList args);

        virtual CoreDriver* create(QStringList args, QObject *parent = NULL)
        {
            //Create driver with no parent
            CoreDriver* driver = new T(parent);
            driver->initialize(args);
            return driver;
        }


    protected:





    };


}//namespace netcore

#endif //_CORE_DRIVER_FACTORY_H_

