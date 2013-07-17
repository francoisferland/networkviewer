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

#include "CoreDriverFactory.h"
#include "CoreDriver.h"


namespace netcore
{

    QMap<CoreDriverInfo,CoreDriverFactoryBase*>& CoreDriverFactoryBase::getFactoryMap()
    {
        static QMap<CoreDriverInfo,CoreDriverFactoryBase*> factory;
        return factory;
    }

    ///Driver configuration (before creation)
    void CoreDriverFactoryBase::configure(QStringList args)
    {
        qDebug("void CoreDriverFactoryBase::configure(QStringList args) - Nothing to do!");
    }

    CoreDriver* CoreDriverFactoryBase::create(const QString &name, QStringList args, QObject* parent)
    {
        CoreDriver *driver = NULL;
        CoreDriverInfo info;
        if (CoreDriverFactoryBase::getInfo(name,info))
        {
            if (info.m_factory)
            {
                driver = info.m_factory->create(args,parent);
            }
            else
            {
                qWarning("CoreDriver* CoreDriverFactoryBase::create(...) No factory for driver : %s",name.toStdString().c_str());
            }
        }

        return driver;
    }

    CoreDriverFactoryBase::CoreDriverFactoryBase()
    {

    }

    QMap<CoreDriverInfo,CoreDriverFactoryBase*> CoreDriverFactoryBase::registeredDrivers()
    {
        //Returning a copy of the map...
        return getFactoryMap();
    }

    bool CoreDriverFactoryBase::registerDriverFactory(const CoreDriverInfo &info, CoreDriverFactoryBase* factory)
    {
        //Already inserted?
        if (getFactoryMap().contains(info))
        {
            return false;
        }

        //Insert factory
        getFactoryMap().insert(info,factory);
        return true;
    }

    void CoreDriverFactoryBase::scanDrivers(const QString &basePath)
    {
        qDebug() << "CoreDriverFactoryBase::scanDrivers basePath: "<<basePath;

        //Plugins directory
        QDir dir(basePath);

        if (!dir.exists())
        {
            qWarning("CoreDriverFactoryBase::scanDrivers() : drivers directory not found");
            qWarning() << "CoreDriverFactoryBase::scanDrivers()  : Current path : " << dir.absolutePath();
        }
        else
        {
            qDebug() << "CoreDriverFactoryBase::scanDrivers()  : Scanning : " << dir.absolutePath();
            recursiveScan(dir);
        }
    }

    void CoreDriverFactoryBase::recursiveScan(QDir directory, int level)
    {
        qDebug() << "CoreDriverFactoryBase::recursiveScan :  Path :" << directory.path();

        if (level < 10 && directory.exists())
        {

            QFileInfoList myInfoList = directory.entryInfoList();

            for (int i = 0; i < myInfoList.size(); i++)
            {

                if (!myInfoList[i].fileName().startsWith("."))
                {
                    if (myInfoList[i].isDir())
                    {
                        recursiveScan(QDir(directory.path() + QDir::separator() + myInfoList[i].fileName()), level + 1);
                    }
                    else
                    {
                        //standard file
                        //TODO Unix dlls
    #ifdef WIN32
                        if (myInfoList[i].fileName().contains(".dll") && !myInfoList[i].fileName().contains(".dll.a")) {
    #else
                        if (myInfoList[i].fileName().contains(".so") || myInfoList[i].fileName().contains(".dylib")) {
    #endif
                            qDebug() << "CoreDriverFactoryBase::recursiveScan : Loading library : " << directory.path() + QDir::separator() + myInfoList[i].fileName();

                            QLibrary *library = new QLibrary(directory.path() + QDir::separator() + myInfoList[i].fileName());

                            if (library->load())
                            {
                                qDebug() << "CoreDriverFactoryBase::recursiveScan : Loaded : " << directory.path() + QDir::separator() + myInfoList[i].fileName();
                            }
                            else
                            {
                                qDebug() << "CoreDriverFactoryBase::recursiveScan : Error : " << library->errorString();
                                delete library;
                            }
                        }
                    }
                }//starts with "."
            }//for infoList
        }
        else
        {
            qWarning("BasePlugin::recursiveScan : error level : %i",level);
        }
    }

    bool CoreDriverFactoryBase::getInfo(QString driverName, CoreDriverInfo &info)
    {
        for (QMap<CoreDriverInfo,CoreDriverFactoryBase*>::iterator iter = getFactoryMap().begin(); iter != getFactoryMap().end(); iter++)
        {

            if (iter.key().m_name == driverName)
            {
                info = iter.key();
                return true;
            }
        }

        return false;
    }

} //namespace netcore
