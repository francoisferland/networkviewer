/****************************************************************************
** Meta object code from reading C++ file 'NETVRemoteServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/core/src/NETVRemoteServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NETVRemoteServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NETVRemoteServer_t {
    QByteArrayData data[8];
    char stringdata[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NETVRemoteServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NETVRemoteServer_t qt_meta_stringdata_NETVRemoteServer = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 12),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 21),
QT_MOC_LITERAL(4, 53, 7),
QT_MOC_LITERAL(5, 61, 15),
QT_MOC_LITERAL(6, 77, 15),
QT_MOC_LITERAL(7, 93, 18)
    },
    "NETVRemoteServer\0addInterface\0\0"
    "NETVInterfaceManager*\0manager\0"
    "removeInterface\0readyReadSocket\0"
    "socketDisconnected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NETVRemoteServer[] = {

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
       1,    1,   34,    2, 0x0a,
       5,    1,   37,    2, 0x0a,
       6,    0,   40,    2, 0x09,
       7,    0,   41,    2, 0x09,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NETVRemoteServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NETVRemoteServer *_t = static_cast<NETVRemoteServer *>(_o);
        switch (_id) {
        case 0: _t->addInterface((*reinterpret_cast< NETVInterfaceManager*(*)>(_a[1]))); break;
        case 1: _t->removeInterface((*reinterpret_cast< NETVInterfaceManager*(*)>(_a[1]))); break;
        case 2: _t->readyReadSocket(); break;
        case 3: _t->socketDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NETVInterfaceManager* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NETVInterfaceManager* >(); break;
            }
            break;
        }
    }
}

const QMetaObject NETVRemoteServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_NETVRemoteServer.data,
      qt_meta_data_NETVRemoteServer,  qt_static_metacall, 0, 0}
};


const QMetaObject *NETVRemoteServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NETVRemoteServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NETVRemoteServer.stringdata))
        return static_cast<void*>(const_cast< NETVRemoteServer*>(this));
    if (!strcmp(_clname, "NETVMessageObserverIF"))
        return static_cast< NETVMessageObserverIF*>(const_cast< NETVRemoteServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int NETVRemoteServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
