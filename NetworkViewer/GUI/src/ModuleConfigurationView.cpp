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

#include "ModuleConfigurationView.h"
#include <QCheckBox>
#include <QFileDialog>
#include "AddVariableDialog.h"


ModuleConfigurationView::ModuleConfigurationView(QWidget *parent, NetworkModule *module)
    : QWidget(parent), m_module(module)
{
    Q_ASSERT(m_module);

    //Setup UI
    m_ui.setupUi(this);

    m_table = new QTableView(this);
    m_table->setModel(m_module->getConfiguration());
    m_table->setDragEnabled(true);

    //Make sure everything fits
    m_table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    m_table->setWordWrap(true);

    //Stretching
    m_table->horizontalHeader()->setStretchLastSection(true);


    //Set Delegate
    m_delegate = new ValueEditorDelegate(m_table);
    m_table->setItemDelegate(m_delegate);

    //Make sure everything is visible
    for (unsigned int i = 0; i < ModuleConfiguration::VARIABLE_DESCRIPTION; i++)
    {
        m_table->resizeColumnToContents(i);
    }

    for (unsigned int i = 0; i < m_module->getConfiguration()->size(); i++)
    {
        m_table->setRowHeight(i,50);
    }


    m_ui.verticalLayout->addWidget(m_table);

    //Make sure we know when the module is destroyed
    connect(m_module,SIGNAL(destroyed()),this,SLOT(moduleDestroyed()));

    //TableView signals.
    connect(m_table,SIGNAL(doubleClicked(const QModelIndex&)),this,SLOT(cellDoubleClicked(const QModelIndex&)));

    //Buttons
    connect(m_ui.toolButton_Activate,SIGNAL(clicked()),this,SLOT(activateAllVariables()));
    connect(m_ui.toolButton_Deactivate,SIGNAL(clicked()),this,SLOT(disableAllVariables()));
    connect(m_ui.toolButton_SaveConf,SIGNAL(clicked()),this,SLOT(saveConfiguration()));
    connect(m_ui.toolButton_LoadConf,SIGNAL(clicked()),this,SLOT(loadConfiguration()));
    connect(m_ui.toolButton_NewVariable,SIGNAL(clicked()),this,SLOT(newVariableClicked()));

}

void ModuleConfigurationView::moduleDestroyed()
{
    qDebug("ModuleConfigurationView::moduleDestroyed()");
    m_module = NULL;
    emit closeRequest();
}

void ModuleConfigurationView::cellDoubleClicked(const QModelIndex &index)
{

    int column = index.column();
    int row = index.row();

    //qDebug("ModuleConfigurationView::cellDoubleClicked row %i col %i",row,column);
    if (column == ModuleConfiguration::VARIABLE_NAME && m_module)
    {
        ModuleConfiguration *config = m_module->getConfiguration();
        Q_ASSERT(config);

        if (row < config->size())
        {
            emit scopeRequest((*config)[row]);
        }
    }
}

void ModuleConfigurationView::activateAllVariables()
{
    if(m_module)
    {
        ModuleConfiguration *config = m_module->getConfiguration();
        for (unsigned int i = 0; i < config->size(); i++)
        {
            (*config)[i]->setActivated(true);
        }
    }
}

void ModuleConfigurationView::disableAllVariables()
{
    if (m_module)
    {
        ModuleConfiguration *config = m_module->getConfiguration();
        for (unsigned int i = 0; i < config->size(); i++)
        {
            (*config)[i]->setActivated(false);
        }
    }
}

void ModuleConfigurationView::loadConfiguration()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Configuration File"),
                                                     m_module->getConfiguration()->getFilename(),
                                                     "XML (*.xml)");
    if (fileName.size() > 0)
    {
            qDebug() << "Loading configuration :" << fileName;
            //Loading config, variables only
            m_module->getConfiguration()->loadConfiguration(fileName,true);

	    for (unsigned int i = 0; i < m_module->getConfiguration()->size(); i++)
            {
		    ModuleVariable *variable = (*m_module->getConfiguration())[i];

		    //This is a hack to get the internal value written to the bus
		    //Can we do better
		    QVariant value = variable->getValue();

		    variable->setUserValue(value);
	    }

    }
}

void ModuleConfigurationView::saveConfiguration()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Configuration File"),
                                                    m_module->getConfiguration()->getFilename(),
                                                    "XML (*.xml)");
    if (fileName.size() > 0)
    {
            qDebug() << "Saving configuration :" << fileName;
            m_module->getConfiguration()->saveConfiguration(fileName);
    }
}

void ModuleConfigurationView::newVariableClicked()
{
    AddVariableDialog dialog(m_module);
    dialog.exec();

    if (dialog.result() == QDialog::Accepted)
    {
        //Create new variable
        ModuleVariable *var = new ModuleVariable(dialog.getVariableType(),
                                                 dialog.getVariableName(),
                                                 dialog.getVariableMemoryType(),
                                                 dialog.getVariableMemoryOffset(),
                                                 dialog.getVariableDescription());

        //Variable will be owned by the configuration
        m_module->getConfiguration()->addVariable(var);


    }
}
