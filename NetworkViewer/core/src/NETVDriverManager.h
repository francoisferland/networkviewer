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
#ifndef _NETV_DRIVER_MANAGER_H_
#define _NETV_DRIVER_MANAGER_H_

#include "CoreDriverManager.h"
#include "NETVScheduler.h"

namespace netcore
{
    class NETVDriverManager : public CoreDriverManager
    {
        friend class NETVScheduler;

        Q_OBJECT

    public:
        NETVDriverManager(CoreDriver* driver, QObject* parent=NULL);
        virtual ~NETVDriverManager();

        //NETV specifics
        NETVModule *getModule(unsigned int deviceID);
        NETVScheduler* getScheduler();
        QList<NETVModule*> getModules();

    public slots:

        bool addModule(NETVModule *module);
        bool removeModule(NETVModule *module);

    signals:

        void moduleAdded(NETVModule *module);
        void moduleRemoved(NETVModule *module);
        void moduleActive(NETVModule *module, bool active);

    protected slots:

        void writeVariable(NETVVariable *variable);
        void watchdogTimeout();

    protected:

        virtual void startup();
        virtual void shutdown();

        void sendAliveRequest();
        void requestVariable(NETVVariable *variable);

        //Called from read thread...
        virtual void process(const CoreMessage* message);
        virtual void process(const NETVMessage* message);

        ///Variables scheduler
        NETVScheduler *m_scheduler;

        ///All modules on this interface
        QList<NETVModule*> m_modules;

        ///Mutex
        QMutex m_mutex;
    };

} //namespace netcore


#endif // _NETV_DRIVER_MANAGER_H
