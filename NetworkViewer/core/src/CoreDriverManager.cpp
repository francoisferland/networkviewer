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
#include "CoreDriverManager.h"

namespace netcore
{

    CoreDriverManagerReader::CoreDriverManagerReader(CoreDriverManager* manager)
        :   QThread(NULL), m_manager(manager), m_running(false)
    {
        qDebug("CoreDriverManagerReader::CoreDriverManagerReader(CoreDriverManager* manager = %p)",m_manager);
        Q_ASSERT(m_manager != NULL);
    }


    void CoreDriverManagerReader::managerThreadStarted()
    {
        qDebug("CoreDriverManagerReader::managerThreadStarted()");
        if (!isRunning())
        {
            start();
        }
    }

    void CoreDriverManagerReader::managerThreadFinished()
    {
        qDebug("CoreDriverManagerReader::managerThreadFinished()");
        if (isRunning())
        {
            m_running = false;
            quit();
            wait();
        }
    }


    void CoreDriverManagerReader::run()
    {
        m_running = true;
        qDebug("CoreDriverManagerReader::run() - starting!");
        while(m_running)
        {
            //Will wait for semaphore, max 100ms
            CoreMessage* message = m_manager->m_driver->recvMessage();
            if (message)
            {
                m_manager->process(message);
                delete message;
            }
        }
        qDebug("CoreDriverManagerReader::run() - done!");
    }



    CoreDriverManager::CoreDriverManager(CoreDriver *driver, QObject *parent)
        : QThread(parent), m_driver(driver), m_reader(this)
    {
        Q_ASSERT(m_driver != NULL);

        connect(this,SIGNAL(started()),&m_reader,SLOT(managerThreadStarted()));
        connect(this,SIGNAL(finished()),&m_reader,SLOT(managerThreadFinished()));

    }

    void CoreDriverManager::run()
    {
        qDebug() << "CoreDriverManager::run() starting" << " Thread: " << QThread::currentThread();

        startup();

        //Execute event loop
        exec();

        shutdown();
    }


} //namespace netcore
