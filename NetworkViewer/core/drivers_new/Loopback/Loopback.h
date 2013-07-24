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

#ifndef _LOOPBACK_H_
#define _LOOPBACK_H_


#include "CoreDriver.h"
#include <QSemaphore>
#include <QMutex>
#include <QList>
#include <QEvent>
#include <QTimer>
#include <QTime>
#include "NETV_define.h"

namespace netcore
{
    class Loopback : public CoreDriver
    {
        class VirtualModule
        {

        public:


            static const int NB_SINE_VARIABLES=4;
            static const int NB_TEMP_VARIABLES=10;
            static const int NB_VARIABLES=(NB_SINE_VARIABLES + NB_TEMP_VARIABLES);

            VirtualModule(int id)
                : module_id(id)
            {
                project_id = 0;
                code_version = 1;
                table_version = 2;
                device_id = 0;
                state = NETV_NORMAL_MODE_ID;
                boot_delay = 0;
                for (unsigned int i = 0 ; i < NB_VARIABLES; i++)
                {
                    variable[i] = 0;
                }
            }

            VirtualModule(const VirtualModule &cpy)
            {
                module_id = cpy.module_id;
                project_id = cpy.project_id;
                code_version = cpy.code_version;
                table_version = cpy.table_version;
                device_id = cpy.device_id;
                state = cpy.state;
                boot_delay = cpy.boot_delay;
                for (unsigned int i = 0 ; i < NB_VARIABLES; i++)
                {
                    variable[i] = cpy.variable[i];
                }
            }

            VirtualModule& operator= (const VirtualModule &cpy)
            {
                module_id = cpy.module_id;
                project_id = cpy.project_id;
                code_version = cpy.code_version;
                table_version = cpy.table_version;
                device_id = cpy.device_id;
                state = cpy.state;
                boot_delay = cpy.boot_delay;
                for (unsigned int i = 0 ; i < NB_VARIABLES; i++)
                {
                    variable[i] = cpy.variable[i];
                }
                return *this;
            }


            int module_id;
            int project_id;
            int code_version;
            int table_version;
            int device_id;
            int state;
            int boot_delay;

            union {

                struct {
                    double variable[NB_VARIABLES];
                };

                unsigned char data[NB_VARIABLES *sizeof(double)];

            };

        };


        friend class LoopbackDriverRegistry;

        Q_OBJECT;

        public:

        Loopback(QObject *parent=NULL);

        virtual CoreDriverInfo info();

        //Init & config
        virtual CoreDriver::CoreDriverState initialize(QStringList args);

        //Driver startup and terminate
        virtual void startup();
        virtual void shutdown();


        //state
        virtual CoreDriver::CoreDriverState state();

    protected slots:

        void timeout();


    protected:

        virtual CoreDriverState internalThreadRecvFunction();
        virtual CoreDriverState internalThreadSendFunction();
        static CoreDriverInfo internalInfo();
        void processMessage(const NETVMessage* message);

        QMutex m_mutex;
        QList<VirtualModule> m_moduleList;
    };

}//namespace netcore
#endif

