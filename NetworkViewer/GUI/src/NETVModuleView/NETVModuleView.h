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

#ifndef _NETV_MODULE_VIEW_H_
#define _NETV_MODULE_VIEW_H_

#include <QMainWindow>
#include <QList>
#include "ui_NETVModuleView.h"
#include "CoreDriverManager.h"

namespace netvgui
{
    using namespace netcore;

    class NETVModuleView : public QMainWindow
    {
    public:

        NETVModuleView(QWidget *parent, QList<CoreDriverManager*> managers);

    protected:

        QList<CoreDriverManager*> m_managerList;
        Ui::NETVModuleView m_ui;
    };
}

#endif
