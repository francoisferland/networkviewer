/****************************************************************************
** Meta object code from reading C++ file 'NETVInterfaceManagerView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/GUI/src/NETVInterfaceManagerView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NETVInterfaceManagerView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NETVInterfaceManagerView_t {
    QByteArrayData data[7];
    char stringdata[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NETVInterfaceManagerView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NETVInterfaceManagerView_t qt_meta_stringdata_NETVInterfaceManagerView = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 16),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 19),
QT_MOC_LITERAL(4, 63, 17),
QT_MOC_LITERAL(5, 81, 16),
QT_MOC_LITERAL(6, 98, 4)
    },
    "NETVInterfaceManagerView\0addButtonClicked\0"
    "\0removeButtonClicked\0itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NETVInterfaceManagerView[] = {

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
       3,    0,   30,    2, 0x09,
       4,    1,   31,    2, 0x09,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void NETVInterfaceManagerView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NETVInterfaceManagerView *_t = static_cast<NETVInterfaceManagerView *>(_o);
        switch (_id) {
        case 0: _t->addButtonClicked(); break;
        case 1: _t->removeButtonClicked(); break;
        case 2: _t->itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NETVInterfaceManagerView::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NETVInterfaceManagerView.data,
      qt_meta_data_NETVInterfaceManagerView,  qt_static_metacall, 0, 0}
};


const QMetaObject *NETVInterfaceManagerView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NETVInterfaceManagerView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NETVInterfaceManagerView.stringdata))
        return static_cast<void*>(const_cast< NETVInterfaceManagerView*>(this));
    if (!strcmp(_clname, "Ui::NETVInterfaceManagerView"))
        return static_cast< Ui::NETVInterfaceManagerView*>(const_cast< NETVInterfaceManagerView*>(this));
    return QDialog::qt_metacast(_clname);
}

int NETVInterfaceManagerView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
