/****************************************************************************
** Meta object code from reading C++ file 'dsPICBootloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NetworkViewer/GUI/plugins/dsPICBootloader/dsPICBootloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dsPICBootloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dsPICBootloader_t {
    QByteArrayData data[26];
    char stringdata[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_dsPICBootloader_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_dsPICBootloader_t qt_meta_stringdata_dsPICBootloader = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 7),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 6),
QT_MOC_LITERAL(4, 32, 7),
QT_MOC_LITERAL(5, 40, 4),
QT_MOC_LITERAL(6, 45, 12),
QT_MOC_LITERAL(7, 58, 7),
QT_MOC_LITERAL(8, 66, 19),
QT_MOC_LITERAL(9, 86, 8),
QT_MOC_LITERAL(10, 95, 15),
QT_MOC_LITERAL(11, 111, 17),
QT_MOC_LITERAL(12, 129, 7),
QT_MOC_LITERAL(13, 137, 14),
QT_MOC_LITERAL(14, 152, 23),
QT_MOC_LITERAL(15, 176, 4),
QT_MOC_LITERAL(16, 181, 11),
QT_MOC_LITERAL(17, 193, 5),
QT_MOC_LITERAL(18, 199, 18),
QT_MOC_LITERAL(19, 218, 11),
QT_MOC_LITERAL(20, 230, 14),
QT_MOC_LITERAL(21, 245, 6),
QT_MOC_LITERAL(22, 252, 13),
QT_MOC_LITERAL(23, 266, 14),
QT_MOC_LITERAL(24, 281, 5),
QT_MOC_LITERAL(25, 287, 14)
    },
    "dsPICBootloader\0loadHEX\0\0upload\0timeout\0"
    "stop\0printMessage\0message\0addEmergencyProgram\0"
    "moduleID\0addResetCommand\0addSetBaseAddress\0"
    "address\0addSendDataInc\0QVector<unsigned char>&\0"
    "data\0addSetState\0state\0addWriteBootConfig\0"
    "moduleAdded\0NetworkModule*\0module\0"
    "moduleRemoved\0comboActivated\0index\0"
    "changeModuleID\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dsPICBootloader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x09,
       3,    0,   90,    2, 0x09,
       4,    0,   91,    2, 0x09,
       5,    0,   92,    2, 0x09,
       6,    1,   93,    2, 0x09,
       8,    1,   96,    2, 0x09,
      10,    1,   99,    2, 0x09,
      11,    2,  102,    2, 0x09,
      13,    2,  107,    2, 0x09,
      16,    2,  112,    2, 0x09,
      18,    1,  117,    2, 0x09,
      19,    1,  120,    2, 0x09,
      22,    1,  123,    2, 0x09,
      23,    1,  126,    2, 0x09,
      25,    0,  129,    2, 0x09,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    9,   12,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 14,    9,   15,
    QMetaType::Void, QMetaType::UInt, QMetaType::UChar,    9,   17,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,

       0        // eod
};

void dsPICBootloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dsPICBootloader *_t = static_cast<dsPICBootloader *>(_o);
        switch (_id) {
        case 0: _t->loadHEX(); break;
        case 1: _t->upload(); break;
        case 2: _t->timeout(); break;
        case 3: _t->stop(); break;
        case 4: _t->printMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->addEmergencyProgram((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 6: _t->addResetCommand((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 7: _t->addSetBaseAddress((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 8: _t->addSendDataInc((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QVector<unsigned char>(*)>(_a[2]))); break;
        case 9: _t->addSetState((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 10: _t->addWriteBootConfig((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 11: _t->moduleAdded((*reinterpret_cast< NetworkModule*(*)>(_a[1]))); break;
        case 12: _t->moduleRemoved((*reinterpret_cast< NetworkModule*(*)>(_a[1]))); break;
        case 13: _t->comboActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->changeModuleID(); break;
        default: ;
        }
    }
}

const QMetaObject dsPICBootloader::staticMetaObject = {
    { &BasePlugin::staticMetaObject, qt_meta_stringdata_dsPICBootloader.data,
      qt_meta_data_dsPICBootloader,  qt_static_metacall, 0, 0}
};


const QMetaObject *dsPICBootloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dsPICBootloader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dsPICBootloader.stringdata))
        return static_cast<void*>(const_cast< dsPICBootloader*>(this));
    if (!strcmp(_clname, "NETVMessageObserverIF"))
        return static_cast< NETVMessageObserverIF*>(const_cast< dsPICBootloader*>(this));
    return BasePlugin::qt_metacast(_clname);
}

int dsPICBootloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasePlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
