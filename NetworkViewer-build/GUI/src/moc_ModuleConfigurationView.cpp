/****************************************************************************
** Meta object code from reading C++ file 'ModuleConfigurationView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/GUI/src/ModuleConfigurationView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModuleConfigurationView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModuleConfigurationView_t {
    QByteArrayData data[14];
    char stringdata[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ModuleConfigurationView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ModuleConfigurationView_t qt_meta_stringdata_ModuleConfigurationView = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 12),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 12),
QT_MOC_LITERAL(4, 51, 15),
QT_MOC_LITERAL(5, 67, 8),
QT_MOC_LITERAL(6, 76, 15),
QT_MOC_LITERAL(7, 92, 17),
QT_MOC_LITERAL(8, 110, 5),
QT_MOC_LITERAL(9, 116, 20),
QT_MOC_LITERAL(10, 137, 19),
QT_MOC_LITERAL(11, 157, 17),
QT_MOC_LITERAL(12, 175, 17),
QT_MOC_LITERAL(13, 193, 18)
    },
    "ModuleConfigurationView\0closeRequest\0"
    "\0scopeRequest\0ModuleVariable*\0variable\0"
    "moduleDestroyed\0cellDoubleClicked\0"
    "index\0activateAllVariables\0"
    "disableAllVariables\0loadConfiguration\0"
    "saveConfiguration\0newVariableClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModuleConfigurationView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x05,
       3,    1,   60,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x09,
       7,    1,   64,    2, 0x09,
       9,    0,   67,    2, 0x09,
      10,    0,   68,    2, 0x09,
      11,    0,   69,    2, 0x09,
      12,    0,   70,    2, 0x09,
      13,    0,   71,    2, 0x09,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ModuleConfigurationView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModuleConfigurationView *_t = static_cast<ModuleConfigurationView *>(_o);
        switch (_id) {
        case 0: _t->closeRequest(); break;
        case 1: _t->scopeRequest((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 2: _t->moduleDestroyed(); break;
        case 3: _t->cellDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->activateAllVariables(); break;
        case 5: _t->disableAllVariables(); break;
        case 6: _t->loadConfiguration(); break;
        case 7: _t->saveConfiguration(); break;
        case 8: _t->newVariableClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (ModuleConfigurationView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleConfigurationView::closeRequest)) {
                *result = 0;
            }
        }
        {
            typedef void (ModuleConfigurationView::*_t)(ModuleVariable * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleConfigurationView::scopeRequest)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ModuleConfigurationView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ModuleConfigurationView.data,
      qt_meta_data_ModuleConfigurationView,  qt_static_metacall, 0, 0}
};


const QMetaObject *ModuleConfigurationView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModuleConfigurationView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModuleConfigurationView.stringdata))
        return static_cast<void*>(const_cast< ModuleConfigurationView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ModuleConfigurationView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ModuleConfigurationView::closeRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ModuleConfigurationView::scopeRequest(ModuleVariable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
