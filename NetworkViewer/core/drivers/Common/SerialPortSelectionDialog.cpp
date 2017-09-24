/**
     Copyright (C) 2009-2013 IntRoLab
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

#include "SerialPortSelectionDialog.h"
#include <QSerialPortInfo>
#include <QList>


SerialPortSelectionDialog::SerialPortSelectionDialog(QWidget *parent)
    : QDialog(parent), m_currentPortIndex(-1), m_currentBaudRateIndex(0)
{
    resize(640,480);
    setupUi(this);

    connect(m_portComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(portIndexChanged(int)));
    connect(m_baudComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(baudRateIndexChanged(int)));

    //Fill combo box with available ports
    //QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    QList<QSerialPortInfo>	ports = QSerialPortInfo::availablePorts();


    for (auto i = 0; i < ports.size(); i++)
    {
        if (i == 0)
        {
            m_currentPortIndex = 0;

            //Update info
            updateInfo(ports[i]);
        }

        //Add port to combo list
        m_portComboBox->addItem(ports[i].portName());
    }

    //Set Combo box @ 9600 baud
    int index = m_baudComboBox->findText("9600");
    m_baudComboBox->setCurrentIndex(index);
}

QString SerialPortSelectionDialog::getSerialPortString()
{
    if (m_currentPortIndex >= 0)
    {
        return m_portComboBox->itemText(m_currentPortIndex);
    }

    return QString();
}

QString SerialPortSelectionDialog::getBaudRateString()
{
    return m_baudComboBox->itemText(m_currentBaudRateIndex);
}


void SerialPortSelectionDialog::portIndexChanged ( int index )
{
    m_currentPortIndex = index;

    //Fill combo box with available ports
    QList<QSerialPortInfo>	ports = QSerialPortInfo::availablePorts();

    if (index < ports.size())
    {
        updateInfo(ports[index]);
    }
}

void SerialPortSelectionDialog::updateInfo(const QSerialPortInfo &info)
{
    /*
        QString	description() const
        bool	hasProductIdentifier() const
        bool	hasVendorIdentifier() const
        bool	isBusy() const
        bool	isNull() const
        bool	isValid() const
        QString	manufacturer() const
        QString	portName() const
        quint16	productIdentifier() const
        void	swap(QSerialPortInfo & other)
        QString	systemLocation() const
        quint16	vendorIdentifier() const

    */
    m_textEdit->clear();

    m_textEdit->append("Port name: " + info.portName());
    m_textEdit->append("Manufacturer: " + info.manufacturer());
    m_textEdit->append("Description: " + info.description());
    m_textEdit->append("Location: " +  info.systemLocation());

    if (info.hasVendorIdentifier())
        m_textEdit->append("Vendor ID: " + QString::number(info.vendorIdentifier(),16));

    if (info.hasProductIdentifier())
        m_textEdit->append("Product ID: " + QString::number(info.productIdentifier(), 16));

    m_textEdit->append("===================================");
}

void SerialPortSelectionDialog::baudRateIndexChanged ( int index )
{
    m_currentBaudRateIndex = index;
}

bool SerialPortSelectionDialog::getDebugStatus()
{
    return m_debugCheckbox->isChecked();
}

int SerialPortSelectionDialog::getDelay()
{
    return m_delaySpinBox->value();
}
