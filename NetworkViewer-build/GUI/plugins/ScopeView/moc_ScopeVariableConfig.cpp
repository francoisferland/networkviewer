/****************************************************************************
** Meta object code from reading C++ file 'ScopeVariableConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NetworkViewer/GUI/plugins/ScopeView/ScopeVariableConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScopeVariableConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScopeVariableConfig_t {
    QByteArrayData data[6];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScopeVariableConfig_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ScopeVariableConfig_t qt_meta_stringdata_ScopeVariableConfig = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 15),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 13),
QT_MOC_LITERAL(4, 51, 5),
QT_MOC_LITERAL(5, 57, 21)
    },
    "ScopeVariableConfig\0setColorClicked\0"
    "\0colorSelected\0color\0removeVariableClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScopeVariableConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09,
       3,    1,   30,    2, 0x09,
       5,    0,   33,    2, 0x09,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    4,
    QMetaType::Void,

       0        // eod
};

void ScopeVariableConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScopeVariableConfig *_t = static_cast<ScopeVariableConfig *>(_o);
        switch (_id) {
        case 0: _t->setColorClicked(); break;
        case 1: _t->colorSelected((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->removeVariableClicked(); break;
        default: ;
        }
    }
}

const QMetaObject ScopeVariableConfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ScopeVariableConfig.data,
      qt_meta_data_ScopeVariableConfig,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScopeVariableConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScopeVariableConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScopeVariableConfig.stringdata))
        return static_cast<void*>(const_cast< ScopeVariableConfig*>(this));
    if (!strcmp(_clname, "Ui::ScopeVariableConfig"))
        return static_cast< Ui::ScopeVariableConfig*>(const_cast< ScopeVariableConfig*>(this));
    return QDialog::qt_metacast(_clname);
}

int ScopeVariableConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
