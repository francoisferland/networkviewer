/**
     Copyright (C) 2009-2010 IntRoLab
     http://introlab.gel.usherbrooke.ca
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

#ifndef ScriptEngine_H_
#define ScriptEngine_H_

#include "BasePlugin.h"
#include "NetworkModule.h"
#include <QScriptEngine>
#include <QScriptEngineAgent>
#include <QTimer>
#include <QTime>
#include "ui_ScriptEngine.h"

/**

  Documentation.
 */
class ScriptEngine : public BasePlugin
{
	Q_OBJECT;


public:

	ScriptEngine(NetworkView *view);

	virtual void init();
	virtual void terminate();
        bool scopeRequest(int module_id, int variable_id);
        bool createPseudoModule(int module_id);
        bool addScriptVariable(int module_id, QString name, QString description = "");

protected slots:

        void moduleAdded(NetworkModule *module);
        void moduleRemoved(NetworkModule *module);
	void timerUpdate();
        void loadButtonClicked();
        void runButtonClicked();
        void updatePeriod(int period);
        void helpButtonClicked();


protected:

        void updateEngineVariables(bool modulesOnly = false);
	QTimer *m_timer;
	Ui::ScriptEngine m_ui;
	QList<NetworkModule*> m_modules;
        QScriptEngine m_scriptEngine;
        QTime m_startTime;
        bool m_running;
        QString m_lastPath;
        int m_cycle;
};

#endif /* ScriptEngine_H_ */