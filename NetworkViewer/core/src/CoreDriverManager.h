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

#ifndef _CORE_DRIVER_MANAGER_H_
#define _CORE_DRIVER_MANAGER_H_

#include <QObject>
#include <QThread>
#include "CoreDriver.h"

namespace netcore
{

    class CoreDriverManager;
    class CoreDriverManagerReader : public QThread
    {
        Q_OBJECT

        public:

        CoreDriverManagerReader(CoreDriverManager* manager);
        virtual void run();

        public slots:

        void managerThreadStarted();
        void managerThreadFinished();

    protected:

        bool m_running;
        CoreDriverManager *m_manager;
    };


    /**
     * @brief The CoreDriverManager class
     *
     *
     */
    class CoreDriverManager : public QThread
    {
        friend class CoreDriverManagerReader;

        Q_OBJECT

    public:

        CoreDriverManager(CoreDriver *driver, QObject *parent=NULL);

        //Thread stuff
        virtual void startup() = 0;
        virtual void shutdown() = 0;
        virtual void process(CoreMessage* message) = 0;
        virtual void run();

    protected:
        CoreDriver *m_driver;
        CoreDriverManagerReader m_reader;
    };

} //namespace netcore

#endif
