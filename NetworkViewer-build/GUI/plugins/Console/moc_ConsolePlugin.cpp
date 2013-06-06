/****************************************************************************
** Meta object code from reading C++ file 'ConsolePlugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NetworkViewer/GUI/plugins/Console/ConsolePlugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConsolePlugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConsolePlugin_t {
    QByteArrayData data[8];
    char stringdata[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ConsolePlugin_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ConsolePlugin_t qt_meta_stringdata_ConsolePlugin = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 18),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 17),
QT_MOC_LITERAL(4, 52, 14),
QT_MOC_LITERAL(5, 67, 21),
QT_MOC_LITERAL(6, 89, 7),
QT_MOC_LITERAL(7, 97, 16)
    },
    "ConsolePlugin\0clearButtonClicked\0\0"
    "saveButtonClicked\0interfaceAdded\0"
    "NETVInterfaceManager*\0manager\0"
    "interfaceRemoved\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConsolePlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x09,
       3,    0,   35,    2, 0x09,
       4,    1,   36,    2, 0x09,
       7,    1,   39,    2, 0x09,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void ConsolePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConsolePlugin *_t = static_cast<ConsolePlugin *>(_o);
        switch (_id) {
        case 0: _t->clearButtonClicked(); break;
        case 1: _t->saveButtonClicked(); break;
        case 2: _t->interfaceAdded((*reinterpret_cast< NETVInterfaceManager*(*)>(_a[1]))); break;
        case 3: _t->interfaceRemoved((*reinterpret_cast< NETVInterfaceManager*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ConsolePlugin::staticMetaObject = {
    { &BasePlugin::staticMetaObject, qt_meta_stringdata_ConsolePlugin.data,
      qt_meta_data_ConsolePlugin,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConsolePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConsolePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConsolePlugin.stringdata))
        return static_cast<void*>(const_cast< ConsolePlugin*>(this));
    if (!strcmp(_clname, "NETVMessageObserverIF"))
        return static_cast< NETVMessageObserverIF*>(const_cast< ConsolePlugin*>(this));
    return BasePlugin::qt_metacast(_clname);
}

int ConsolePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasePlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
