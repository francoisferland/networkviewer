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
#ifndef _NETV_SCHEDULER_H_
#define _NETV_SCHEDULER_H_

#include <QObject>
#include <QTimer>
#include "Core.h"
#include "NETVModule.h"
#include <QMutex>

namespace netcore
{
    class NETVDriverManager;

    class NETVCORE_EXPORT NETVScheduler : QObject
    {
        Q_OBJECT
    public:

        NETVScheduler(NETVDriverManager *manager);


        /**
            Add a module for scheduling
            \param module The module to add
        */
        void addModule(NETVModule* module);

        /**
            Remove a module for scheduling
            \param module The module to remove
        */
        void removeModule(NETVModule* module);

        /**
          \return The alive request interval in ms
        */
        int getAliveRequestInterval();

        /**
            \return The variable request interval in ms
        */
        int getVariableRequestInterval();

    public slots:

        /**
            Set the alive request interval
            \param value the interval in ms
        */
        void setAliveRequestInterval(int value);

        /**
            Set the variable request interval
            \param value the interval in ms
        */
        void setVariableRequestInterval(int value);



    protected slots:

        /**
            Add a variable to the schedule
            \param var the Scheduled variable
        */
        void addScheduledVariable(NETVVariable *var);


        /**
            Remove a variable from scheduling
            \param var the variable to remove from schedule
        */
        void removeScheduledVariable(NETVVariable *var, bool disconnect=false);

        /**
            Called by the timer m_schedulerTimer (periodic)
            Will schedule variables to be updated
        */
        void schedulerUpdate();

        /**
            Called by the timer m_aliveTimer (periodic)
            Will shedule alive requests
        */
        void schedulerAliveRequest();

        /**
            Called by m_watchdogTimer (periodic)
            to determine if there is a timeout on a module
        */
        void schedulerWatchdog();

        /**
            Called when a variable changes its activation state
            \param state the state of activation
            \param var the variable pointer
        */
        void variableActivated(bool activated, NETVVariable *var);


    protected:

        ///The manager owning the scheduler (parent)
        NETVDriverManager *m_manager;
        ///The variable scheduler timer
        QTimer *m_schedulerTimer;
        ///The list of scheduled modules
        QList<NETVModule*> m_modules;
        ///The alive timer
        QTimer *m_aliveTimer;
        ///Watchdog timer
        QTimer *m_watchdogTimer;
        ///The scheduled variables (round robin)
        QList<NETVVariable*> m_variableScheduleList;
        ///Mutex protecting the list of modules and variables
        QMutex m_mutex;

    };


}//namespace netcore

#endif // _NETV_SCHEDULER_H_
