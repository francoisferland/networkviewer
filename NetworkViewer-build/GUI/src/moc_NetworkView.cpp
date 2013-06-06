/****************************************************************************
** Meta object code from reading C++ file 'NetworkView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../NetworkViewer/GUI/src/NetworkView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PluginActionHandler_t {
    QByteArrayData data[6];
    char stringdata[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PluginActionHandler_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PluginActionHandler_t qt_meta_stringdata_PluginActionHandler = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 15),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 4),
QT_MOC_LITERAL(4, 42, 15),
QT_MOC_LITERAL(5, 58, 7)
    },
    "PluginActionHandler\0pluginActivated\0"
    "\0name\0actionTriggered\0checked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PluginActionHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,

       0        // eod
};

void PluginActionHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PluginActionHandler *_t = static_cast<PluginActionHandler *>(_o);
        switch (_id) {
        case 0: _t->pluginActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->actionTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PluginActionHandler::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PluginActionHandler::pluginActivated)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject PluginActionHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PluginActionHandler.data,
      qt_meta_data_PluginActionHandler,  qt_static_metacall, 0, 0}
};


const QMetaObject *PluginActionHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PluginActionHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PluginActionHandler.stringdata))
        return static_cast<void*>(const_cast< PluginActionHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int PluginActionHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PluginActionHandler::pluginActivated(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_NetworkView_t {
    QByteArrayData data[40];
    char stringdata[576];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NetworkView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NetworkView_t qt_meta_stringdata_NetworkView = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 13),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 14),
QT_MOC_LITERAL(4, 42, 6),
QT_MOC_LITERAL(5, 49, 11),
QT_MOC_LITERAL(6, 61, 16),
QT_MOC_LITERAL(7, 78, 21),
QT_MOC_LITERAL(8, 100, 7),
QT_MOC_LITERAL(9, 108, 14),
QT_MOC_LITERAL(10, 123, 14),
QT_MOC_LITERAL(11, 138, 17),
QT_MOC_LITERAL(12, 156, 18),
QT_MOC_LITERAL(13, 175, 24),
QT_MOC_LITERAL(14, 200, 25),
QT_MOC_LITERAL(15, 226, 13),
QT_MOC_LITERAL(16, 240, 12),
QT_MOC_LITERAL(17, 253, 12),
QT_MOC_LITERAL(18, 266, 15),
QT_MOC_LITERAL(19, 282, 8),
QT_MOC_LITERAL(20, 291, 12),
QT_MOC_LITERAL(21, 304, 18),
QT_MOC_LITERAL(22, 323, 10),
QT_MOC_LITERAL(23, 334, 7),
QT_MOC_LITERAL(24, 342, 9),
QT_MOC_LITERAL(25, 352, 31),
QT_MOC_LITERAL(26, 384, 18),
QT_MOC_LITERAL(27, 403, 4),
QT_MOC_LITERAL(28, 408, 14),
QT_MOC_LITERAL(29, 423, 6),
QT_MOC_LITERAL(30, 430, 19),
QT_MOC_LITERAL(31, 450, 15),
QT_MOC_LITERAL(32, 466, 4),
QT_MOC_LITERAL(33, 471, 23),
QT_MOC_LITERAL(34, 495, 7),
QT_MOC_LITERAL(35, 503, 20),
QT_MOC_LITERAL(36, 524, 14),
QT_MOC_LITERAL(37, 539, 15),
QT_MOC_LITERAL(38, 555, 12),
QT_MOC_LITERAL(39, 568, 6)
    },
    "NetworkView\0moduleRemoved\0\0NetworkModule*\0"
    "module\0moduleAdded\0interfaceRemoved\0"
    "NETVInterfaceManager*\0manager\0"
    "interfaceAdded\0tileMDIWindows\0"
    "cascadeMDIWindows\0closeAllMDIWindows\0"
    "enableAllModuleVariables\0"
    "disableAllModuleVariables\0clearTextEdit\0"
    "saveTextEdit\0scopeRequest\0ModuleVariable*\0"
    "variable\0removeModule\0NetworkModuleItem*\0"
    "printDebug\0message\0addModule\0"
    "moduleDockWidgetLocationChanged\0"
    "Qt::DockWidgetArea\0area\0scopeDestroyed\0"
    "object\0moduleDoubleClicked\0pluginActivated\0"
    "name\0deviceSelectorTriggered\0checked\0"
    "preferencesTriggered\0aboutTriggered\0"
    "updateConnStats\0moduleActive\0active\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x05,
       5,    1,  142,    2, 0x05,
       6,    1,  145,    2, 0x05,
       9,    1,  148,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      10,    0,  151,    2, 0x0a,
      11,    0,  152,    2, 0x0a,
      12,    0,  153,    2, 0x0a,
      13,    0,  154,    2, 0x0a,
      14,    0,  155,    2, 0x0a,
      15,    0,  156,    2, 0x0a,
      16,    0,  157,    2, 0x0a,
      17,    1,  158,    2, 0x0a,
      20,    1,  161,    2, 0x0a,
      22,    1,  164,    2, 0x0a,
      24,    1,  167,    2, 0x0a,
      20,    1,  170,    2, 0x0a,
      25,    1,  173,    2, 0x09,
      28,    1,  176,    2, 0x09,
      30,    1,  179,    2, 0x09,
      31,    1,  182,    2, 0x09,
      33,    1,  185,    2, 0x09,
      35,    1,  188,    2, 0x09,
      36,    1,  191,    2, 0x09,
      37,    0,  194,    2, 0x09,
      38,    2,  195,    2, 0x09,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,    4,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, QMetaType::QObjectStar,   29,
    QMetaType::Void, 0x80000000 | 21,    4,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,   39,

       0        // eod
};

void NetworkView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkView *_t = static_cast<NetworkView *>(_o);
        switch (_id) {
        case 0: _t->moduleRemoved((*reinterpret_cast< NetworkModule*(*)>(_a[1]))); break;
        case 1: _t->moduleAdded((*reinterpret_cast< NetworkModule*(*)>(_a[1]))); break;
        case 2: _t->interfaceRemoved((*reinterpret_cast< NETVInterfaceManager*(*)>(_a[1]))); break;
        case 3: _t->interfaceAdded((*reinterpret_cast< NETVInterfaceManager*(*)>(_a[1]))); break;
        case 4: _t->tileMDIWindows(); break;
        case 5: _t->cascadeMDIWindows(); break;
        case 6: _t->closeAllMDIWindows(); break;
        case 7: _t->enableAllModuleVariables(); break;
        case 8: _t->disableAllModuleVariables(); break;
        case 9: _t->clearTextEdit(); break;
        case 10: _t->saveTextEdit(); break;
        case 11: _t->scopeRequest((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 12: _t->removeModule((*reinterpret_cast< NetworkModuleItem*(*)>(_a[1]))); break;
        case 13: _t->printDebug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->addModule((*reinterpret_cast< NetworkModule*(*)>(_a[1]))); break;
        case 15: _t->removeModule((*reinterpret_cast< NetworkModule*(*)>(_a[1]))); break;
        case 16: _t->moduleDockWidgetLocationChanged((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1]))); break;
        case 17: _t->scopeDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 18: _t->moduleDoubleClicked((*reinterpret_cast< NetworkModuleItem*(*)>(_a[1]))); break;
        case 19: _t->pluginActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->deviceSelectorTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->preferencesTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->aboutTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->updateConnStats(); break;
        case 24: _t->moduleActive((*reinterpret_cast< NetworkModule*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModule* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModule* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NETVInterfaceManager* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NETVInterfaceManager* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModuleVariable* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModuleItem* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModule* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModule* >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModuleItem* >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< NetworkModule* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetworkView::*_t)(NetworkModule * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkView::moduleRemoved)) {
                *result = 0;
            }
        }
        {
            typedef void (NetworkView::*_t)(NetworkModule * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkView::moduleAdded)) {
                *result = 1;
            }
        }
        {
            typedef void (NetworkView::*_t)(NETVInterfaceManager * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkView::interfaceRemoved)) {
                *result = 2;
            }
        }
        {
            typedef void (NetworkView::*_t)(NETVInterfaceManager * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkView::interfaceAdded)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject NetworkView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_NetworkView.data,
      qt_meta_data_NetworkView,  qt_static_metacall, 0, 0}
};


const QMetaObject *NetworkView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkView.stringdata))
        return static_cast<void*>(const_cast< NetworkView*>(this));
    if (!strcmp(_clname, "Ui::NetworkView"))
        return static_cast< Ui::NetworkView*>(const_cast< NetworkView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int NetworkView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void NetworkView::moduleRemoved(NetworkModule * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkView::moduleAdded(NetworkModule * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkView::interfaceRemoved(NETVInterfaceManager * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetworkView::interfaceAdded(NETVInterfaceManager * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
