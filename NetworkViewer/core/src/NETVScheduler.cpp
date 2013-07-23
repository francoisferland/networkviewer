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

#include "NETVScheduler.h"
#include "NETVDriverManager.h"

namespace netcore
{

     NETVScheduler::NETVScheduler(NETVDriverManager *manager)
         : QObject(NULL),
           m_manager(manager),
           m_schedulerTimer(NULL),
           m_aliveTimer(NULL)
     {
         Q_ASSERT(m_manager != NULL);

         //Events will be managed by the thread
         moveToThread(m_manager);

         m_aliveTimer = new QTimer(this);
         connect(m_aliveTimer,SIGNAL(timeout()), this, SLOT(schedulerAliveRequest()));
         m_aliveTimer->start(1000); //1sec alive requests.


         m_schedulerTimer = new QTimer(this);
         connect(m_schedulerTimer,SIGNAL(timeout()),this,SLOT(schedulerUpdate()));
         m_schedulerTimer->start(10);//10ms timer
     }


     void NETVScheduler::schedulerUpdate()
     {

         //qDebug("NETVScheduler::schedulerUpdate() nbVar : %i",m_variableScheduleList.size());

         //How many variables should we update at once?
         for (int iter = 0; iter < 1; iter++)
         {
             //verify that we have something to schedule
             if (m_variableScheduleList.size())
             {
                 //Get first variable to schedule
                 NETVVariable *var = m_variableScheduleList.front();
                 m_variableScheduleList.pop_front();

                 if (var->getActivated())
                 {
                     //Request variable on the bus
                     m_manager->requestVariable(var);

                     //At the end for rescheduling if activated...
                     m_variableScheduleList.push_back(var);
                 }
             }
             else
             {
                 break;
             }
         } //iter
     }

     void NETVScheduler::addModule(NETVModule* module)
     {
         //qDebug("NETVScheduler::addModule %p, conf size: %i",module,module->getConfiguration()->size());

         if (!m_modules.contains(module))
         {
             m_modules.push_back(module);

             //Add variables to schedule list
             NETVModuleConfiguration *conf = module->getConfiguration();

             for (int i = 0; i < conf->size(); i++)
             {
                 //Make sure variable is scheduled only once
                 addScheduledVariable((*conf)[i]);
             }
         }

         //If new variables are available, shedule them
         connect(module->getConfiguration(),SIGNAL(variableAdded(NETVVariable*)),this,SLOT(addScheduledVariable(NETVVariable*)));

         //If variables are removed from module, remove from schedule
         connect(module->getConfiguration(),SIGNAL(variableRemoved(NETVVariable*)),this,SLOT(removeScheduledVariable(NETVVariable*)));

     }

     void NETVScheduler::removeModule(NETVModule* module)
     {
         //qDebug("NETVScheduler::removeModule(NETVModule* module = %p",module);

         //Remove variables for scheduling
         NETVModuleConfiguration *conf = module->getConfiguration();

         //Disconnect new variables are available, shedule them
         disconnect(module->getConfiguration(),SIGNAL(variableAdded(NETVVariable*)),this,SLOT(addScheduledVariable(NETVVariable*)));

         //Disconnect variables are removed from module, remove from schedule
         disconnect(module->getConfiguration(),SIGNAL(variableRemoved(NETVVariable*)),this,SLOT(removeScheduledVariable(NETVVariable*)));

         for (int i = 0; i < conf->size(); i++)
         {
             removeScheduledVariable((*conf)[i],true);
         }

         m_modules.removeAll(module);
     }

     void NETVScheduler::schedulerAliveRequest()
     {
         if (m_manager)
         {
             m_manager->sendAliveRequest();
         }
     }

     void NETVScheduler::addScheduledVariable(NETVVariable *var)
     {
         if (!m_variableScheduleList.contains(var) && var->getMemType() < NETVVariable::SCRIPT_VARIABLE)
         {
             qDebug() << "Adding (NEW) variable for scheduling:"<<var->getName()<<" device id: "<<var->getDeviceID();

             //Connect variable activation change
             connect(var,SIGNAL(variableActivated(bool,NETVVariable*)),this,SLOT(variableActivated(bool,NETVVariable*)));

             //Connect variable for auto removal when destroyed
             connect(var,SIGNAL(aboutToDestroy(NETVVariable*)),this,SLOT(removeScheduledVariable(NETVVariable*)));

             m_variableScheduleList.push_back(var);
         }
     }


     void NETVScheduler::removeScheduledVariable(NETVVariable *var, bool disconnect_)
     {
         if (m_variableScheduleList.contains(var))
         {
             qDebug() << "Removing (OLD) variable for scheduling:"<<var->getName()<<" device id: "<<var->getDeviceID();

             if (disconnect_)
             {
                 //Disconnect variable activation change
                 disconnect(var,SIGNAL(variableActivated(bool,NETVVariable*)),this,SLOT(variableActivated(bool,NETVVariable*)));

                 //Disconnect variable for auto removal when destroyed
                 disconnect(var,SIGNAL(aboutToDestroy(NETVVariable*)),this,SLOT(removeScheduledVariable(NETVVariable*)));
             }

             m_variableScheduleList.removeAll(var);
         }
     }


     void NETVScheduler::variableActivated(bool activated, NETVVariable *var)
     {
         if (activated)
         {
             addScheduledVariable(var);
         }
         else
         {
             removeScheduledVariable(var);
         }

     }

     int NETVScheduler::getAliveRequestInterval()
     {
         Q_ASSERT(m_aliveTimer);
         return m_aliveTimer->interval();
     }

     int NETVScheduler::getVariableRequestInterval()
     {
         Q_ASSERT(m_schedulerTimer);
         return m_schedulerTimer->interval();
     }


     void NETVScheduler::setAliveRequestInterval(int value)
     {
         if (value > 0)
         {
             qDebug("void NETVScheduler::setAliveRequestInterval(int value = %i)",value);
             m_aliveTimer->setInterval(value);
         }
         else
         {
             qDebug("NETVScheduler::setAliveRequestInterval invalid value : %i",value);
         }
     }


     void NETVScheduler::setVariableRequestInterval(int value)
     {
         if (value > 0)
         {
             qDebug("NETVScheduler::setVariableRequestInterval(int value = %i)",value);
             m_schedulerTimer->setInterval(value);
         }
         else
         {
             qDebug("NETVScheduler::setVariableRequestInterval invalid value : %i",value);
         }
     }


} //namespace netcore
