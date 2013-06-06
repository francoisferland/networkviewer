/****************************************************************************
** Meta object code from reading C++ file 'ModuleVariableTableWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NetworkViewer/GUI/plugins/Logger/ModuleVariableTableWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModuleVariableTableWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModuleVariableTableWidget_t {
    QByteArrayData data[16];
    char stringdata[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ModuleVariableTableWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ModuleVariableTableWidget_t qt_meta_stringdata_ModuleVariableTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 13),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 15),
QT_MOC_LITERAL(4, 57, 8),
QT_MOC_LITERAL(5, 66, 15),
QT_MOC_LITERAL(6, 82, 12),
QT_MOC_LITERAL(7, 95, 12),
QT_MOC_LITERAL(8, 108, 3),
QT_MOC_LITERAL(9, 112, 3),
QT_MOC_LITERAL(10, 116, 13),
QT_MOC_LITERAL(11, 130, 9),
QT_MOC_LITERAL(12, 140, 13),
QT_MOC_LITERAL(13, 154, 7),
QT_MOC_LITERAL(14, 162, 17),
QT_MOC_LITERAL(15, 180, 20)
    },
    "ModuleVariableTableWidget\0variableAdded\0"
    "\0ModuleVariable*\0variable\0variableRemoved\0"
    "scopeRequest\0enterPressed\0row\0col\0"
    "clearContents\0clearLogs\0setLogEnabled\0"
    "enabled\0variableDestroyed\0"
    "variableValueChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModuleVariableTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x05,
       5,    1,   62,    2, 0x05,
       6,    1,   65,    2, 0x05,
       7,    2,   68,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      10,    0,   73,    2, 0x0a,
      11,    0,   74,    2, 0x0a,
      12,    1,   75,    2, 0x0a,
      14,    1,   78,    2, 0x09,
      15,    1,   81,    2, 0x09,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void ModuleVariableTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModuleVariableTableWidget *_t = static_cast<ModuleVariableTableWidget *>(_o);
        switch (_id) {
        case 0: _t->variableAdded((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 1: _t->variableRemoved((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 2: _t->scopeRequest((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 3: _t->enterPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->clearContents(); break;
        case 5: _t->clearLogs(); break;
        case 6: _t->setLogEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->variableDestroyed((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 8: _t->variableValueChanged((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModuleVariableTableWidget::*_t)(ModuleVariable * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleVariableTableWidget::variableAdded)) {
                *result = 0;
            }
        }
        {
            typedef void (ModuleVariableTableWidget::*_t)(ModuleVariable * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleVariableTableWidget::variableRemoved)) {
                *result = 1;
            }
        }
        {
            typedef void (ModuleVariableTableWidget::*_t)(ModuleVariable * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleVariableTableWidget::scopeRequest)) {
                *result = 2;
            }
        }
        {
            typedef void (ModuleVariableTableWidget::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleVariableTableWidget::enterPressed)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ModuleVariableTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_ModuleVariableTableWidget.data,
      qt_meta_data_ModuleVariableTableWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ModuleVariableTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModuleVariableTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModuleVariableTableWidget.stringdata))
        return static_cast<void*>(const_cast< ModuleVariableTableWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int ModuleVariableTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ModuleVariableTableWidget::variableAdded(ModuleVariable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModuleVariableTableWidget::variableRemoved(ModuleVariable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModuleVariableTableWidget::scopeRequest(ModuleVariable * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ModuleVariableTableWidget::enterPressed(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
