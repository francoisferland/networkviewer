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


#include "NETVVariable.h"
#include <QBuffer>
#include <sstream>

namespace netcore
{



    //This constructor is private
    NETVVariable::NETVVariable(QObject *parent)
        : QObject(parent),
          m_type(INVALID),
          m_name("Invalid"),
          m_memType(RAM_VARIABLE),
          m_offset(-1),
          m_description("Invalid variable"),
          m_deviceID(-1),
          m_interfaceID(-1),
          m_activated(true),
          m_updateTime(QDateTime::currentDateTime()),
          m_elapsedTime(0)
    {

    }



    NETVVariable::NETVVariable(VARIABLE_TYPE _type, const QString &_name, VARIABLE_MEMORY_TYPE _memType, int _offset, const QString &_description , QObject *parent)
        : QObject(parent),
          m_type(_type),
          m_name(_name),
          m_memType(_memType),
          m_offset(_offset),
          m_description(_description),
          m_activated(true)
    {
        //Set deviceID to -1
        m_deviceID = -1;

        //Set interfaceID to -1
        m_interfaceID = -1;

        //Set time
        m_updateTime = QDateTime::currentDateTime();
        m_elapsedTime = 0;

        setProperty("name",QString("NETVVariable:") + QString(m_name));
    }


    NETVVariable& NETVVariable::invalid()
    {
        static NETVVariable invalidVariable;
        return invalidVariable;
    }

    NETVVariable::NETVVariable(const NETVVariable &variable)
        : m_type(INVALID),
          m_name("Invalid"),
          m_offset(-1),
          m_description("Invalid variable"),
          m_deviceID(-1),
          m_activated(true)
    {
        m_type = variable.m_type;
        m_name = variable.m_name;
        m_memType = variable.m_memType;
        m_offset = variable.m_offset;
        m_description = variable.m_description;
        m_value = variable.m_value;
        m_deviceID = variable.m_deviceID;
        m_interfaceID = variable.m_interfaceID;
        m_activated = variable.m_activated;
        m_updateTime = variable.m_updateTime;
        m_elapsedTime = variable.m_elapsedTime;

        setProperty("name",QString("NETVVariable:") + QString(m_name));
    }

    NETVVariable::NETVVariable(QDomElement &element)
        : m_type(INVALID),
          m_name("Invalid"),
          m_memType(RAM_VARIABLE),
          m_offset(-1),
          m_description("Invalid variable"),
          m_deviceID(-1),
          m_interfaceID(-1),
          m_activated(true),
          m_updateTime(QDateTime::currentDateTime()),
          m_elapsedTime(0)
    {

        loadXML(element);

        setProperty("name",QString("NETVVariable:") + QString(m_name));
    }

    NETVVariable::~NETVVariable()
    {
        emit aboutToDestroy(this);
    }

    bool NETVVariable::loadXML(QDomElement &element)
    {
        if(element.tagName() == "NETVVariable" || element.tagName() == "ModuleVariable")
        {
            //Get all the content...
            /*
                VARIABLE_TYPE m_type;
                QString m_name;
                unsigned int m_offset;
                QString m_description;
                QVariant m_value;
                unsigned long m_version;
                int m_deviceID;
            */

            m_type = NETVVariable::stringToType(element.attributeNode("type").value());
            m_name = element.attributeNode("name").value();

            //For backward compatibility, we consider variable to be of RAM type if not specified...
            if (element.hasAttribute("memType"))
            {
                m_memType = (VARIABLE_MEMORY_TYPE) element.attributeNode("memType").value().toInt();
            }
            else
            {
                m_memType = RAM_VARIABLE;
            }


            m_offset = element.attributeNode("offset").value().toInt();
            m_description = element.attributeNode("description").value();

            //Default value (from string)...
            if (element.attributeNode("value").value().size())
            {
                setValue(element.attributeNode("value").value(),true);
            }

            return true;
        }
        else
        {
            qDebug() << "NETVVariable::loadXML() invalid tag name:" << element.tagName();
            return false;
        }

    }

    NETVVariable& NETVVariable::operator= (const NETVVariable &variable)
    {
        m_type = variable.m_type;
        m_name = variable.m_name;
        m_memType = variable.m_memType;
        m_offset = variable.m_offset;
        m_description = variable.m_description;
        m_value = variable.m_value;
        m_deviceID = variable.m_deviceID;
        m_interfaceID = variable.m_interfaceID;
        m_updateTime = variable.m_updateTime;
        m_elapsedTime = variable.m_elapsedTime;

        setProperty("name",QString("NETVVariable:") + QString(m_name));

        emit valueChanged(this);

        return *this;
    }

    bool NETVVariable::operator== (const NETVVariable &variable) const
    {
        if (m_name == variable.m_name &&
                m_memType == variable.m_memType &&
                m_deviceID == variable.m_deviceID &&
                m_interfaceID == variable.m_interfaceID &&
                m_updateTime == variable.m_updateTime)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    void NETVVariable::saveXML(QDomDocument &document, QDomElement &parentElement)
    {
        QDomElement variableElement = document.createElement("NETVVariable");

        variableElement.setAttribute("type",typeToString(m_type));
        variableElement.setAttribute("name",m_name);
        variableElement.setAttribute("memType", QString::number(m_memType));
        variableElement.setAttribute("offset",QString::number(m_offset));
        variableElement.setAttribute("description",m_description);
        variableElement.setAttribute("value",m_value.toString());

        //deviceID not required...
        //variableElement.setAttribute("deviceID",QString::number(m_deviceID));

        //interfaceID not required...
        //variableElement.setAttribute("interfaceID",QString::number(m_interfaceID));

        parentElement.appendChild(variableElement);
    }

    QString NETVVariable::typeToString(VARIABLE_TYPE type)
    {
        QString typeString;

        switch(type)
        {
        case DOUBLE:
            typeString="double";
            break;

        case FLOAT:
            typeString="float";
            break;

        case SINT32:
            typeString="sint32";
            break;

        case UINT32:
            typeString="uint32";
            break;

        case SINT16:
            typeString="sint16";
            break;

        case UINT16:
            typeString="uint16";
            break;

        case SINT8:
            typeString="sint8";
            break;

        case UINT8:
            typeString="uint8";
            break;

        case BYTEARRAY8:
            typeString="bytearray8";
            break;

        default:
            qDebug("Unhandled type : %i",type);
            typeString="Unknown";
            break;

        }

        return typeString;
    }

    NETVVariable::VARIABLE_TYPE NETVVariable::stringToType(const QString &typeString)
    {
        if (typeString == "double")
        {
            return DOUBLE;
        }
        else if (typeString == "float")
        {
            return FLOAT;
        }
        else if (typeString == "sint32")
        {
            return SINT32;
        }
        else if (typeString == "uint32")
        {
            return UINT32;
        }
        else if (typeString == "sint16")
        {
            return SINT16;
        }
        else if (typeString == "uint16")
        {
            return UINT16;
        }
        else if (typeString == "sint8")
        {
            return SINT8;
        }
        else if (typeString == "uint8")
        {
            return UINT8;
        }
        else if (typeString =="bytearray8")
        {
            return BYTEARRAY8;
        }
        else
        {
            qDebug() << "Invalid type :" << typeString;
            return INVALID;
        }
    }


    void NETVVariable::setValue(float value, bool userUpdate, QDateTime time)
    {
        m_value = QVariant(value);
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }

    void NETVVariable::setValue(double value, bool userUpdate, QDateTime time)
    {
        m_value = QVariant(value);
        updateTime(time);;
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }

    void NETVVariable::setValue (int value, bool userUpdate, QDateTime time)
    {
        m_value = QVariant(value);
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }

    void NETVVariable::setUserValue(int value)
    {
        setValue(value,true);
    }

    void NETVVariable::setUserValue(bool value)
    {
        setValue((unsigned char) value,true);
    }

    void NETVVariable::setUserValue(QVariant value)
    {
        setValue(value,true);
    }

    void NETVVariable::setUserValue(double value)
    {
        setValue(value,true);
    }

    void NETVVariable::setValue (unsigned int value, bool userUpdate, QDateTime time)
    {
        m_value = QVariant(value);
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }

    void NETVVariable::setValue (short value, bool userUpdate, QDateTime time)
    {
        m_value = QVariant(value);
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }

    void NETVVariable::setValue (unsigned short value, bool userUpdate, QDateTime time)
    {
        m_value = QVariant(value);
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }

    void NETVVariable::setValue (char value, bool userUpdate, QDateTime time)
    {
        m_value = QVariant(value);
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }

    void NETVVariable::setValue (unsigned char value, bool userUpdate, QDateTime time)
    {
        m_value = QVariant(value);
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }


    void NETVVariable::setValue(QVariant value, bool userUpdate, QDateTime time)
    {
        m_value = value;
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            //emit user signal
            emit userChanged(this);
        }
    }

    void NETVVariable::setValue(const QByteArray &byteArray, bool userUpdate, QDateTime time)
    {

        //Make sure we have the right length
        QByteArray myValue = byteArray;
        myValue.resize(getLength());

        m_value = QVariant(myValue);
        updateTime(time);
        emit valueChanged(this);
        if (userUpdate)
        {
            emit userChanged(this);
        }
    }


    void NETVVariable::setValue (const QString &value, bool userUpdate, QDateTime updateTime)
    {
        bool ok = false;

        switch(m_type)
        {
        case DOUBLE:
            setValue(value.toDouble(&ok),userUpdate,updateTime);
            break;

        case FLOAT:
            setValue(value.toFloat(&ok),userUpdate,updateTime);
            break;

        case SINT32:
            setValue(value.toInt(&ok),userUpdate,updateTime);
            break;

        case UINT32:
            setValue(value.toUInt(&ok),userUpdate,updateTime);
            break;

        case SINT16:
            setValue(value.toShort(&ok),userUpdate,updateTime);
            break;
        case UINT16:
            setValue(value.toUShort(&ok),userUpdate,updateTime);
            break;

        case SINT8:
            setValue((char) value.toShort(&ok),userUpdate,updateTime);
            break;

        case UINT8:
            setValue((unsigned char) value.toUShort(&ok),userUpdate,updateTime);
            break;

        case BYTEARRAY8:
            ok = true;
            setValue(value.toLatin1(), userUpdate, updateTime);
            break;

        case INVALID:
            qDebug("Trying to set a value to invalid variable");
            break;

        }

        if (!ok)
        {
            qDebug() << "Invalid conversion from QString to " << typeToString(m_type) << " String: " << value;
        }
        else
        {
            if (userUpdate)
            {
                //emit user signal
                emit userChanged(this);
            }
        }

    }


    void NETVVariable::setValue(const unsigned char* data, int size, bool userUpdate, QDateTime updateTime)
    {
        if (size == getLength())
        {
            std::stringstream myStream(std::string((char*)data,size));

            switch(m_type)
            {
            case DOUBLE:
                {
                    double value;
                    myStream.read((char*) &value,sizeof(double));
                    setValue(value,userUpdate,updateTime);
                }
                break;

            case FLOAT:
                {
                    float value;
                    myStream.read((char*) &value,sizeof(float));
                    setValue(value,userUpdate,updateTime);
                }
                break;

            case SINT32:
                {
                    int value;
                    myStream.read((char*) &value,sizeof(int));
                    setValue(value,userUpdate,updateTime);
                }
                break;

            case UINT32:
                {
                    unsigned int value;
                    myStream.read((char*) &value,sizeof(unsigned int));
                    setValue(value,userUpdate,updateTime);
                }
                break;

            case SINT16:
                {
                    short value;
                    myStream.read((char*) &value,sizeof(short));
                    setValue(value,userUpdate,updateTime);
                }
                break;

            case UINT16:
                {
                    unsigned short value;
                    myStream.read((char*) &value,sizeof(unsigned short));
                    setValue(value,userUpdate,updateTime);
                }
                break;

            case SINT8:
                {
                    char value;
                    myStream.read((char*) &value,sizeof(char));
                    setValue(value,userUpdate,updateTime);
                }
                break;

            case UINT8:
                {
                    unsigned char value;
                    myStream.read((char*) &value,sizeof(unsigned char));
                    setValue(value,userUpdate,updateTime);
                }
                break;

            case BYTEARRAY8:
                {
                    QByteArray myValue((const char*)data, size);
                    setValue(myValue);
                }
                break;

            case INVALID:
                qDebug("Trying to set a value to invalid variable");
                break;

            }
        }
        else
        {
            qDebug("Invalid length %i for variable %s",size,getName().toStdString().c_str());
        }
    }


    QVariant NETVVariable::getValue() const
    {
        return m_value;
    }

    NETVVariable::VARIABLE_TYPE NETVVariable::getType() const
    {
        return m_type;
    }

    NETVVariable::VARIABLE_MEMORY_TYPE NETVVariable::getMemType() const
    {
        return m_memType;
    }

    QString NETVVariable::getName() const
    {
        return m_name;
    }

    int NETVVariable::getOffset() const
    {
        return m_offset;
    }

    QString NETVVariable::getDescription() const
    {
        return m_description;
    }

    void NETVVariable::setDeviceID(int id)
    {
        m_deviceID = id;
    }

    int NETVVariable::getDeviceID() const
    {
        return m_deviceID;
    }

    void NETVVariable::setInterfaceID(int id)
    {
        m_interfaceID = id;
    }

    int NETVVariable::getInterfaceID() const
    {
        return m_interfaceID;
    }

    int NETVVariable::getLength() const
    {
        int size = 0;

        switch(m_type)
        {
        case DOUBLE:
            size = 8;
            break;

        case FLOAT:
            size = 4;
            break;

        case SINT32:
            size = 4;
            break;

        case UINT32:
            size = 4;
            break;

        case SINT16:
            size = 2;
            break;

        case UINT16:
            size = 2;
            break;

        case SINT8:
            size = 1;
            break;

        case UINT8:
            size = 1;
            break;

        case BYTEARRAY8:
            size = 8;
            break;

        case INVALID:
            qDebug("Trying to set a value to invalid variable");
            break;

        }

        return size;
    }

    QByteArray NETVVariable::toByteArray() const
    {
        QBuffer buffer;
        buffer.open(QBuffer::WriteOnly);

        switch(m_type)
        {
        case DOUBLE:
            {
                double myValue = m_value.toDouble();
                buffer.write((char*) &myValue,sizeof(double));
            }
            break;

        case FLOAT:
            {
                float myValue = (float) m_value.toDouble();
                buffer.write((char*) &myValue,sizeof(float));
            }
            break;

        case SINT32:
            {
                int myValue = m_value.toInt();
                buffer.write((char*) &myValue,sizeof(int));
            }
            break;

        case UINT32:
            {
                unsigned int myValue = m_value.toUInt();
                buffer.write((char*) &myValue,sizeof(unsigned int));
            }
            break;

        case SINT16:
            {
                short myValue = (short) m_value.toInt();
                buffer.write((char*) &myValue,sizeof(short));
            }
            break;

        case UINT16:
            {
                unsigned short myValue = (unsigned short) m_value.toUInt();
                buffer.write((char*) &myValue,sizeof(unsigned short));
            }
            break;

        case SINT8:
            {
                char myValue = (char) m_value.toInt();
                buffer.write((char*) &myValue,sizeof(char));
            }
            break;

        case UINT8:
            {
                unsigned char myValue = (unsigned char) m_value.toUInt();
                buffer.write((char*) &myValue,sizeof(unsigned char));
            }
            break;

        case BYTEARRAY8:
            {
                //Make sure we have the right length
                QByteArray myValue = m_value.toByteArray();
                myValue.resize(getLength());
                buffer.write(myValue);
            }
            break;

        case INVALID:
            qDebug("Trying to set a value to invalid variable");
            break;
        }


        //Validation of the code...
        Q_ASSERT(buffer.data().size() == getLength());


        return buffer.data();

    }

    void NETVVariable::setActivated(bool activated)
    {
        if (activated != m_activated)
        {
            m_activated = activated;
            updateTime(m_updateTime);
            emit variableActivated(m_activated,this);
        }
    }

    bool NETVVariable::getActivated() const
    {
        return m_activated;
    }


    unsigned int NETVVariable::getSize() const
    {
        return getLength();
    }

    QDateTime NETVVariable::getUpdateTime() const
    {
        return m_updateTime;
    }

    qint64 NETVVariable::getElapsedTime() const
    {
        return m_elapsedTime;
    }

    void NETVVariable::updateTime(QDateTime time)
    {
        m_elapsedTime = m_updateTime.msecsTo(time);
        m_updateTime = time;
        emit updateTimeChanged(this);
    }

}//namespace netcore
