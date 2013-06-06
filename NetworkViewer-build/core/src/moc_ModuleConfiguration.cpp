/****************************************************************************
** Meta object code from reading C++ file 'ModuleConfiguration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/core/src/ModuleConfiguration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModuleConfiguration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModuleConfiguration_t {
    QByteArrayData data[16];
    char stringdata[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ModuleConfiguration_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ModuleConfiguration_t qt_meta_stringdata_ModuleConfiguration = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 13),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 15),
QT_MOC_LITERAL(4, 51, 8),
QT_MOC_LITERAL(5, 60, 13),
QT_MOC_LITERAL(6, 74, 15),
QT_MOC_LITERAL(7, 90, 24),
QT_MOC_LITERAL(8, 115, 18),
QT_MOC_LITERAL(9, 134, 15),
QT_MOC_LITERAL(10, 150, 3),
QT_MOC_LITERAL(11, 154, 11),
QT_MOC_LITERAL(12, 166, 14),
QT_MOC_LITERAL(13, 181, 22),
QT_MOC_LITERAL(14, 204, 25),
QT_MOC_LITERAL(15, 230, 5)
    },
    "ModuleConfiguration\0variableWrite\0\0"
    "ModuleVariable*\0variable\0variableAdded\0"
    "variableRemoved\0configurationAboutToLoad\0"
    "moduleStateChanged\0variableUpdated\0"
    "var\0addVariable\0removeVariable\0"
    "variableInternalUpdate\0variableInternalActivated\0"
    "state\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModuleConfiguration[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x05,
       5,    1,   67,    2, 0x05,
       6,    1,   70,    2, 0x05,
       7,    0,   73,    2, 0x05,
       8,    0,   74,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    1,   75,    2, 0x0a,
      11,    1,   78,    2, 0x0a,
      12,    1,   81,    2, 0x0a,
      13,    1,   84,    2, 0x09,
      14,    2,   87,    2, 0x09,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3,   15,   10,

       0        // eod
};

void ModuleConfiguration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModuleConfiguration *_t = static_cast<ModuleConfiguration *>(_o);
        switch (_id) {
        case 0: _t->variableWrite((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 1: _t->variableAdded((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 2: _t->variableRemoved((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 3: _t->configurationAboutToLoad(); break;
        case 4: _t->moduleStateChanged(); break;
        case 5: _t->variableUpdated((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 6: _t->addVariable((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 7: _t->removeVariable((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 8: _t->variableInternalUpdate((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 9: _t->variableInternalActivated((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< ModuleVariable*(*)>(_a[2]))); break;
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
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModuleConfiguration::*_t)(ModuleVariable * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleConfiguration::variableWrite)) {
                *result = 0;
            }
        }
        {
            typedef void (ModuleConfiguration::*_t)(ModuleVariable * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleConfiguration::variableAdded)) {
                *result = 1;
            }
        }
        {
            typedef void (ModuleConfiguration::*_t)(ModuleVariable * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleConfiguration::variableRemoved)) {
                *result = 2;
            }
        }
        {
            typedef void (ModuleConfiguration::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleConfiguration::configurationAboutToLoad)) {
                *result = 3;
            }
        }
        {
            typedef void (ModuleConfiguration::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleConfiguration::moduleStateChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject ModuleConfiguration::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_ModuleConfiguration.data,
      qt_meta_data_ModuleConfiguration,  qt_static_metacall, 0, 0}
};


const QMetaObject *ModuleConfiguration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModuleConfiguration::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModuleConfiguration.stringdata))
        return static_cast<void*>(const_cast< ModuleConfiguration*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int ModuleConfiguration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ModuleConfiguration::variableWrite(ModuleVariable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModuleConfiguration::variableAdded(ModuleVariable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModuleConfiguration::variableRemoved(ModuleVariable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ModuleConfiguration::configurationAboutToLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ModuleConfiguration::moduleStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
