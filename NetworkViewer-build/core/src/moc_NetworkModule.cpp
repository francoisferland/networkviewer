/****************************************************************************
** Meta object code from reading C++ file 'NetworkModule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/core/src/NetworkModule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkModule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetworkModule_t {
    QByteArrayData data[19];
    char stringdata[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NetworkModule_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NetworkModule_t qt_meta_stringdata_NetworkModule = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 13),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 15),
QT_MOC_LITERAL(4, 45, 8),
QT_MOC_LITERAL(5, 54, 20),
QT_MOC_LITERAL(6, 75, 15),
QT_MOC_LITERAL(7, 91, 14),
QT_MOC_LITERAL(8, 106, 14),
QT_MOC_LITERAL(9, 121, 20),
QT_MOC_LITERAL(10, 142, 5),
QT_MOC_LITERAL(11, 148, 12),
QT_MOC_LITERAL(12, 161, 13),
QT_MOC_LITERAL(13, 175, 5),
QT_MOC_LITERAL(14, 181, 9),
QT_MOC_LITERAL(15, 191, 6),
QT_MOC_LITERAL(16, 198, 11),
QT_MOC_LITERAL(17, 210, 13),
QT_MOC_LITERAL(18, 224, 13)
    },
    "NetworkModule\0variableWrite\0\0"
    "ModuleVariable*\0variable\0configurationChanged\0"
    "moduleDestroyed\0variableUpdate\0"
    "getNumVariable\0createScriptVariable\0"
    "_name\0_description\0getVariableAt\0index\0"
    "variables\0active\0getDeviceID\0getConfigName\0"
    "getUpdateTime\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkModule[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x05,
       5,    0,   82,    2, 0x05,
       6,    0,   83,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   84,    2, 0x09,

 // methods: name, argc, parameters, tag, flags
       8,    0,   87,    2, 0x02,
       9,    2,   88,    2, 0x02,
       9,    1,   93,    2, 0x22,
      12,    1,   96,    2, 0x02,
      14,    0,   99,    2, 0x02,
      15,    0,  100,    2, 0x02,
      16,    0,  101,    2, 0x02,
      17,    0,  102,    2, 0x02,
      18,    0,  103,    2, 0x02,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::QVariant, QMetaType::Int,   13,
    QMetaType::QVariant,
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QTime,

       0        // eod
};

void NetworkModule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkModule *_t = static_cast<NetworkModule *>(_o);
        switch (_id) {
        case 0: _t->variableWrite((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 1: _t->configurationChanged(); break;
        case 2: _t->moduleDestroyed(); break;
        case 3: _t->variableUpdate((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 4: { int _r = _t->getNumVariable();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->createScriptVariable((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->createScriptVariable((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { QVariant _r = _t->getVariableAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 8: { QVariant _r = _t->variables();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->active();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->getDeviceID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { QString _r = _t->getConfigName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { QTime _r = _t->getUpdateTime();
            if (_a[0]) *reinterpret_cast< QTime*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetworkModule::*_t)(ModuleVariable * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkModule::variableWrite)) {
                *result = 0;
            }
        }
        {
            typedef void (NetworkModule::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkModule::configurationChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (NetworkModule::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkModule::moduleDestroyed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject NetworkModule::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkModule.data,
      qt_meta_data_NetworkModule,  qt_static_metacall, 0, 0}
};


const QMetaObject *NetworkModule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkModule.stringdata))
        return static_cast<void*>(const_cast< NetworkModule*>(this));
    return QObject::qt_metacast(_clname);
}

int NetworkModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void NetworkModule::variableWrite(ModuleVariable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkModule::configurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void NetworkModule::moduleDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
