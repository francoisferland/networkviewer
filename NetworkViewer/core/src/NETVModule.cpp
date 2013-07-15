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

#include "NETVModule.h"

Q_DECLARE_METATYPE(QList<QObject*>)

namespace netcore
{

    NETVModule::NETVModule(const NETVModuleConfiguration &config, QObject *parent)
        : QObject(parent), m_configuration(config), m_active(true), m_lastUpdateTime(QTime::currentTime())
    {
        setProperty("name",QString("NETVModule:") + QString::number(m_configuration.getDeviceID()));
        connect(&m_configuration, SIGNAL(variableWrite(NETVVariable*)),this,SLOT(variableUpdate(NETVVariable*)));
    }

    NETVModule::~NETVModule()
    {
        emit moduleDestroyed();
        qDebug("NETVModule::~NETVModule()");
    }

    int NETVModule::getNumVariable()
    {
        return m_configuration.size();
    }

    NETVVariable*  NETVModule::getVariable(const QString &name)
    {
        for (int i = 0; i<m_configuration.size(); i++)
        {
            if (m_configuration[i]->getName() == name)
            {
                return m_configuration[i];
            }
        }

        return NULL;
    }

    NETVVariable* NETVModule::getVariable(int index)
    {
        if (index < m_configuration.size())
        {
            return m_configuration[index];
        }

        return NULL;
    }

    int NETVModule::getDeviceID()
    {
        return m_configuration.getDeviceID();
    }

    QString NETVModule::getConfigName()
    {
        return m_configuration.getConfigName();
    }

    QVariant NETVModule::variables()
    {
        QList<QObject*> varList;

        for (int i = 0; i < getNumVariable(); i++)
        {
            varList.append(getVariable(i));
        }
        return QVariant::fromValue(varList);
    }


    QVariant NETVModule::getVariableAt(int index)
    {
        NETVVariable *var = getVariable(index);
        return QVariant::fromValue((QObject*)var);
    }

    NETVModuleConfiguration* NETVModule::getConfiguration()
    {
        return &m_configuration;
    }

    void NETVModule::variableUpdate(NETVVariable *variable)
    {
        //qDebug("NETVModule::variableUpdate(NETVVariable *variable)");
        emit variableWrite(variable);
    }

    bool NETVModule::active()
    {
        return m_active;
    }

    void NETVModule::setActive(bool active)
    {
        m_active = active;
    }

    bool NETVModule::createScriptVariable(const QString &_name, const QString &_description )
    {
        NETVVariable *var = m_configuration.getVariableNamed(_name);

        if (var == NULL)
        {
            NETVVariable *var = new NETVVariable(NETVVariable::DOUBLE,_name,NETVVariable::SCRIPT_VARIABLE,-1,_description);
            int index = m_configuration.size();
            m_configuration.addVariable(var);
            return true;
        }

        return false;

    }

    void NETVModule::setUpdateTime(const QTime &time)
    {
        m_lastUpdateTime = time;
    }

    QTime NETVModule::getUpdateTime() const
    {
        return m_lastUpdateTime;
    }

} //namespace netcore
