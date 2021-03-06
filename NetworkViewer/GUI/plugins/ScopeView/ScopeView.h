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

#ifndef _SCOPE_VIEW_H_
#define _SCOPE_VIEW_H_

#include "ScopeCurve.h"
#include "BasePlugin.h"
#include "qwt_plot_zoomer.h"
#include "qwt_plot_picker.h"

class NetworkView;

/**
    Scope main window
    \author Dominic Letourneau
*/
class ScopeView : public BasePlugin, public Ui::ScopeView
{

    Q_OBJECT;

public:

    /**
        Constructor
        \param parent Parent widget, default = NULL
    */
    ScopeView(NetworkView *parent= NULL);


    /**
     * 	NOT YET IMPLEMENTED, BUT PLUGINS NEED TO OVERLOAD THIS FUNCTION
     *
     */
    virtual void init();


    /**
     *  NOT YET IMPLEMENTED, BUT PLUGINS NEED TO OVERLOAD THIS FUNCTION
     *
     */
    virtual void terminate();

public slots:


    /**
        Add a curve to the scope view
        \param variable the variable to plot
    */
    void addCurve(ModuleVariable *variable);


    /**
        Remove a curve from the scope view
        \param  variable to remove
    */
    void removeCurve(ModuleVariable *variable);




protected slots:

    void legendItemClicked(QwtPlotItem *plotItem);

    void legendClicked(QVariant itemInfo, int index);

    void updateTimer();

    /**
        Remove a curve from the scope view
        \param  curve to remove
    */
    void destroyCurve(ScopeCurve *curve);


    void setCurveMaxBufferSize(int size);

    void clearCurves();

    void saveCurves();

protected:

    /**
        Event Handler, will process \ref BasePluginEvent
        \param e The event to handle.
    */

    bool event ( QEvent * e );
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);


    QwtPlotZoomer *m_zoomer;

    QwtPlotPicker *m_picker;

    ///The plot
    QwtPlot *m_plot;

    ///List of all curves on the plot
    QList<ScopeCurve*> m_curves;

    ///View update timer
    QTimer *m_updateTimer;

};


#endif
