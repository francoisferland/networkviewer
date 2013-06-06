/****************************************************************************
** Meta object code from reading C++ file 'NetworkModuleItem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/GUI/src/NetworkModuleItem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkModuleItem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CrossModuleItem_t {
    QByteArrayData data[1];
    char stringdata[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CrossModuleItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CrossModuleItem_t qt_meta_stringdata_CrossModuleItem = {
    {
QT_MOC_LITERAL(0, 0, 15)
    },
    "CrossModuleItem\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CrossModuleItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void CrossModuleItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CrossModuleItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CrossModuleItem.data,
      qt_meta_data_CrossModuleItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *CrossModuleItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CrossModuleItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CrossModuleItem.stringdata))
        return static_cast<void*>(const_cast< CrossModuleItem*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< CrossModuleItem*>(this));
    return QObject::qt_metacast(_clname);
}

int CrossModuleItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_NetworkModuleItem_t {
    QByteArrayData data[9];
    char stringdata[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NetworkModuleItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NetworkModuleItem_t qt_meta_stringdata_NetworkModuleItem = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 13),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 18),
QT_MOC_LITERAL(4, 52, 4),
QT_MOC_LITERAL(5, 57, 12),
QT_MOC_LITERAL(6, 70, 10),
QT_MOC_LITERAL(7, 81, 4),
QT_MOC_LITERAL(8, 86, 12)
    },
    "NetworkModuleItem\0doubleClicked\0\0"
    "NetworkModuleItem*\0item\0removeModule\0"
    "timeUpdate\0time\0stateChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkModuleItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,
       5,    1,   37,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    1,   40,    2, 0x0a,
       8,    0,   43,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QTime,    7,
    QMetaType::Void,

       0        // eod
};

void NetworkModuleItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkModuleItem *_t = static_cast<NetworkModuleItem *>(_o);
        switch (_id) {
        case 0: _t->doubleClicked((*reinterpret_cast< NetworkModuleItem*(*)>(_a[1]))); break;
        case 1: _t->removeModule((*reinterpret_cast< NetworkModuleItem*(*)>(_a[1]))); break;
        case 2: _t->timeUpdate((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 3: _t->stateChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModuleItem* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModuleItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetworkModuleItem::*_t)(NetworkModuleItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkModuleItem::doubleClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (NetworkModuleItem::*_t)(NetworkModuleItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkModuleItem::removeModule)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject NetworkModuleItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkModuleItem.data,
      qt_meta_data_NetworkModuleItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *NetworkModuleItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkModuleItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkModuleItem.stringdata))
        return static_cast<void*>(const_cast< NetworkModuleItem*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< NetworkModuleItem*>(this));
    return QObject::qt_metacast(_clname);
}

int NetworkModuleItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void NetworkModuleItem::doubleClicked(NetworkModuleItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkModuleItem::removeModule(NetworkModuleItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
