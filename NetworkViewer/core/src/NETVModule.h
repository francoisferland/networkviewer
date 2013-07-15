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
#ifndef _NETV_MODULE_H_
#define _NETV_MODULE_H_

#include "NETVModuleConfiguration.h"
#include <QTime>

namespace netcore
{


    /**
      The Network module will contain the module configuration and variables.
      \author Dominic Letourneau
    */
    class NETVModule : public QObject
    {
        Q_OBJECT;

    public:

            /**
              Constructor
              \param config The default configuration (can be empty)
              \parent The parent object, default = NULL
            */
            NETVModule(const NETVModuleConfiguration &config, QObject *parent = NULL);


            /**
                Destructor
            */
            virtual ~NETVModule();

            /**
                Utility function to get a variable from the NETVModuleConfiguration with its name
                \param name The name of the variable
                \return NETVVariable* the variable with name, NULL if not found
            */
            NETVVariable* getVariable(const QString &name);

            /**
                \return int the count of variables
            */
            Q_INVOKABLE int getNumVariable();


            /**
                Create a custom variable (mostly for scripts)
                \param name the name of the variable
                \return NETVVariable *the newly created module variable
            */
            Q_INVOKABLE bool createScriptVariable(const QString &_name, const QString &_description = "");

            /**
                Utility function to get the variables inside the NETVModuleConfiguration data structure
                \param index the index of the variable
                \return NETVVariable* the variable, NULL if out of range
            */
            NETVVariable* getVariable(int index);

            Q_INVOKABLE QVariant getVariableAt(int index);

            Q_INVOKABLE QVariant variables();

            /**
                Get current configurationChanged();
                \return the NETVModuleConfiguration*
            */
            NETVModuleConfiguration* getConfiguration();

            /**
                \return bool The active flag
            */
            Q_INVOKABLE bool active();


            Q_INVOKABLE int getDeviceID();

            Q_INVOKABLE QString getConfigName();

            /**
                Change the active flag.
                \param active TRUE when the module is activated, FALSE otherwise
            */
            void setActive(bool active);

            /**
                Set the last time the module have been seen on the bus
                \param time the current time
            */
            void setUpdateTime(const QTime &time = QTime::currentTime());

            /**
                Get the last time the module have been seen on the bus
            */
            Q_INVOKABLE QTime getUpdateTime() const;

    signals:

            /**
                We emit this signal when a variable has been written by the user
                \param variable The modified variable
            */
            void variableWrite(NETVVariable *variable);

            /**
                We emit this signal when the configuration changed
            */
            void configurationChanged();

            /**
                We emit this signal when we are destroyed
             */
            void moduleDestroyed();

    protected slots:

            /**
                Called when a variable has been updated by the user. This will cause the variableWrite signal to be emitted.
                \param variable The variable taht has been updated
            */
            void variableUpdate(NETVVariable *variable);

    protected:

            ///Module configuration \ref NETVModuleConfiguration
            NETVModuleConfiguration m_configuration;

            ///TRUE if the module is active on the bus
            bool m_active;

            ///Last time the module have been seen on the bus
            QTime m_lastUpdateTime;
    };


} //namespace netcore

#endif //_NETV_MODULE_H_
