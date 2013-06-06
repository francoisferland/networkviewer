/****************************************************************************
** Meta object code from reading C++ file 'ScriptEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NetworkViewer/GUI/plugins/ScriptEngine/ScriptEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScriptEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ModuleVariableSlider_t {
    QByteArrayData data[9];
    char stringdata[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ModuleVariableSlider_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ModuleVariableSlider_t qt_meta_stringdata_ModuleVariableSlider = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 15),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 22),
QT_MOC_LITERAL(4, 61, 15),
QT_MOC_LITERAL(5, 77, 3),
QT_MOC_LITERAL(6, 81, 20),
QT_MOC_LITERAL(7, 102, 18),
QT_MOC_LITERAL(8, 121, 5)
    },
    "ModuleVariableSlider\0terminateSlider\0"
    "\0variableAboutToDestroy\0ModuleVariable*\0"
    "var\0variableValueChanged\0sliderValueChanged\0"
    "value\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModuleVariableSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x09,
       6,    1,   38,    2, 0x09,
       7,    1,   41,    2, 0x09,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ModuleVariableSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModuleVariableSlider *_t = static_cast<ModuleVariableSlider *>(_o);
        switch (_id) {
        case 0: _t->terminateSlider(); break;
        case 1: _t->variableAboutToDestroy((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 2: _t->variableValueChanged((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 3: _t->sliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ModuleVariableSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ModuleVariableSlider::terminateSlider)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ModuleVariableSlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_ModuleVariableSlider.data,
      qt_meta_data_ModuleVariableSlider,  qt_static_metacall, 0, 0}
};


const QMetaObject *ModuleVariableSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModuleVariableSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModuleVariableSlider.stringdata))
        return static_cast<void*>(const_cast< ModuleVariableSlider*>(this));
    return QSlider::qt_metacast(_clname);
}

int ModuleVariableSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ModuleVariableSlider::terminateSlider()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
struct qt_meta_stringdata_ScriptEngine_t {
    QByteArrayData data[13];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScriptEngine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ScriptEngine_t qt_meta_stringdata_ScriptEngine = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 11),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 14),
QT_MOC_LITERAL(4, 41, 6),
QT_MOC_LITERAL(5, 48, 13),
QT_MOC_LITERAL(6, 62, 11),
QT_MOC_LITERAL(7, 74, 17),
QT_MOC_LITERAL(8, 92, 16),
QT_MOC_LITERAL(9, 109, 17),
QT_MOC_LITERAL(10, 127, 12),
QT_MOC_LITERAL(11, 140, 6),
QT_MOC_LITERAL(12, 147, 17)
    },
    "ScriptEngine\0moduleAdded\0\0NetworkModule*\0"
    "module\0moduleRemoved\0timerUpdate\0"
    "loadButtonClicked\0runButtonClicked\0"
    "saveButtonClicked\0updatePeriod\0period\0"
    "helpButtonClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptEngine[] = {

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
       1,    1,   54,    2, 0x09,
       5,    1,   57,    2, 0x09,
       6,    0,   60,    2, 0x09,
       7,    0,   61,    2, 0x09,
       8,    0,   62,    2, 0x09,
       9,    0,   63,    2, 0x09,
      10,    1,   64,    2, 0x09,
      12,    0,   67,    2, 0x09,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void ScriptEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptEngine *_t = static_cast<ScriptEngine *>(_o);
        switch (_id) {
        case 0: _t->moduleAdded((*reinterpret_cast< NetworkModule*(*)>(_a[1]))); break;
        case 1: _t->moduleRemoved((*reinterpret_cast< NetworkModule*(*)>(_a[1]))); break;
        case 2: _t->timerUpdate(); break;
        case 3: _t->loadButtonClicked(); break;
        case 4: _t->runButtonClicked(); break;
        case 5: _t->saveButtonClicked(); break;
        case 6: _t->updatePeriod((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->helpButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObject ScriptEngine::staticMetaObject = {
    { &BasePlugin::staticMetaObject, qt_meta_stringdata_ScriptEngine.data,
      qt_meta_data_ScriptEngine,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScriptEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptEngine.stringdata))
        return static_cast<void*>(const_cast< ScriptEngine*>(this));
    return BasePlugin::qt_metacast(_clname);
}

int ScriptEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasePlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
