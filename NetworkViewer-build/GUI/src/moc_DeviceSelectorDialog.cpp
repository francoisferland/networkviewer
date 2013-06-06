/****************************************************************************
** Meta object code from reading C++ file 'DeviceSelectorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/GUI/src/DeviceSelectorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeviceSelectorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DeviceSelectorDialog_t {
    QByteArrayData data[7];
    char stringdata[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DeviceSelectorDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DeviceSelectorDialog_t qt_meta_stringdata_DeviceSelectorDialog = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 14),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 5),
QT_MOC_LITERAL(4, 43, 22),
QT_MOC_LITERAL(5, 66, 17),
QT_MOC_LITERAL(6, 84, 4)
    },
    "DeviceSelectorDialog\0comboActivated\0"
    "\0index\0configureButtonClicked\0"
    "deviceArgsChanged\0text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceSelectorDialog[] = {

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
       1,    1,   29,    2, 0x09,
       4,    0,   32,    2, 0x09,
       5,    1,   33,    2, 0x09,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void DeviceSelectorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DeviceSelectorDialog *_t = static_cast<DeviceSelectorDialog *>(_o);
        switch (_id) {
        case 0: _t->comboActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->configureButtonClicked(); break;
        case 2: _t->deviceArgsChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DeviceSelectorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DeviceSelectorDialog.data,
      qt_meta_data_DeviceSelectorDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *DeviceSelectorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceSelectorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceSelectorDialog.stringdata))
        return static_cast<void*>(const_cast< DeviceSelectorDialog*>(this));
    if (!strcmp(_clname, "Ui::DeviceSelectorDialog"))
        return static_cast< Ui::DeviceSelectorDialog*>(const_cast< DeviceSelectorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DeviceSelectorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
