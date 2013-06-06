/****************************************************************************
** Meta object code from reading C++ file 'NetworkScheduler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/core/src/NetworkScheduler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkScheduler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetworkScheduler_t {
    QByteArrayData data[14];
    char stringdata[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NetworkScheduler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NetworkScheduler_t qt_meta_stringdata_NetworkScheduler = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 23),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 5),
QT_MOC_LITERAL(4, 48, 26),
QT_MOC_LITERAL(5, 75, 20),
QT_MOC_LITERAL(6, 96, 15),
QT_MOC_LITERAL(7, 112, 3),
QT_MOC_LITERAL(8, 116, 23),
QT_MOC_LITERAL(9, 140, 10),
QT_MOC_LITERAL(10, 151, 15),
QT_MOC_LITERAL(11, 167, 21),
QT_MOC_LITERAL(12, 189, 17),
QT_MOC_LITERAL(13, 207, 9)
    },
    "NetworkScheduler\0setAliveRequestInterval\0"
    "\0value\0setVariableRequestInterval\0"
    "addScheduledVariable\0ModuleVariable*\0"
    "var\0removeScheduledVariable\0disconnect\0"
    "schedulerUpdate\0schedulerAliveRequest\0"
    "variableActivated\0activated\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkScheduler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a,
       4,    1,   57,    2, 0x0a,
       5,    1,   60,    2, 0x09,
       8,    2,   63,    2, 0x09,
       8,    1,   68,    2, 0x29,
      10,    0,   71,    2, 0x09,
      11,    0,   72,    2, 0x09,
      12,    2,   73,    2, 0x09,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Bool,    7,    9,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 6,   13,    7,

       0        // eod
};

void NetworkScheduler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkScheduler *_t = static_cast<NetworkScheduler *>(_o);
        switch (_id) {
        case 0: _t->setAliveRequestInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setVariableRequestInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->addScheduledVariable((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 3: _t->removeScheduledVariable((*reinterpret_cast< ModuleVariable*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->removeScheduledVariable((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 5: _t->schedulerUpdate(); break;
        case 6: _t->schedulerAliveRequest(); break;
        case 7: _t->variableActivated((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< ModuleVariable*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        }
    }
}

const QMetaObject NetworkScheduler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkScheduler.data,
      qt_meta_data_NetworkScheduler,  qt_static_metacall, 0, 0}
};


const QMetaObject *NetworkScheduler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkScheduler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkScheduler.stringdata))
        return static_cast<void*>(const_cast< NetworkScheduler*>(this));
    return QObject::qt_metacast(_clname);
}

int NetworkScheduler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
