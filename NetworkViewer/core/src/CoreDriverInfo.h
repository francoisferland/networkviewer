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

#ifndef _CORE_DRIVER_INFO_H_
#define _CORE_DRIVER_INFO_H_

#include <QStringList>

namespace netcore
{

    class CoreDriverInfo
    {
    public:
        QString m_name;
        quint32 m_major;
        quint32 m_minor;
        quint32 m_micro;
        QString m_description;
        QStringList m_defaultArgs;

        CoreDriverInfo(QString name, quint32 major, quint32 minor, quint32 micro, QString description, QStringList defaultArgs)
            : m_name(name),
              m_major(major),
              m_minor(minor),
              m_micro(micro),
              m_description(description),
              m_defaultArgs(defaultArgs)
        {

        }

        CoreDriverInfo(const CoreDriverInfo &cpy)
            : m_name(cpy.m_name),
              m_major(cpy.m_major),
              m_minor(cpy.m_minor),
              m_micro(cpy.m_micro),
              m_description(cpy.m_description),
              m_defaultArgs(cpy.m_defaultArgs)
        {

        }

        bool operator==(const CoreDriverInfo &op)
        {
            return (m_name == op.m_name) &&
                    (m_major == op.m_major) &&
                    (m_minor == op.m_minor) &&
                    (m_micro == op.m_micro) &&
                    (m_description == op.m_description) &&
                    (m_defaultArgs == op.m_defaultArgs);

        }

        CoreDriverInfo& operator=(const CoreDriverInfo &op)
        {
            m_name = op.m_name;
            m_major = op.m_major;
            m_minor = op.m_minor;
            m_micro = op.m_micro;
            m_description = op.m_description;
            m_defaultArgs = op.m_defaultArgs;
            return *this;
        }


};


} //namespace netcore

#endif //_CORE_DRIVER_INFO_H_
