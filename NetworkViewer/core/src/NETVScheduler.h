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

namespace netcore
{
    class NETVDriverManager;

    class NETVScheduler : QObject
    {
        Q_OBJECT
    public:

        NETVScheduler(NETVDriverManager *manager);

    protected:


        NETVDriverManager *m_manager;
    };


}//namespace netcore

#endif // _NETV_SCHEDULER_H_
