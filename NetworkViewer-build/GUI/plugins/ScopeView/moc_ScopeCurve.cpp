/****************************************************************************
** Meta object code from reading C++ file 'ScopeCurve.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NetworkViewer/GUI/plugins/ScopeView/ScopeCurve.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScopeCurve.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScopeCurve_t {
    QByteArrayData data[15];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScopeCurve_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ScopeCurve_t qt_meta_stringdata_ScopeCurve = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 11),
QT_MOC_LITERAL(4, 39, 3),
QT_MOC_LITERAL(5, 43, 14),
QT_MOC_LITERAL(6, 58, 15),
QT_MOC_LITERAL(7, 74, 3),
QT_MOC_LITERAL(8, 78, 7),
QT_MOC_LITERAL(9, 86, 4),
QT_MOC_LITERAL(10, 91, 8),
QT_MOC_LITERAL(11, 100, 5),
QT_MOC_LITERAL(12, 106, 20),
QT_MOC_LITERAL(13, 127, 4),
QT_MOC_LITERAL(14, 132, 11)
    },
    "ScopeCurve\0aboutToDestroy\0\0ScopeCurve*\0"
    "ptr\0updateVariable\0ModuleVariable*\0"
    "var\0elapsed\0time\0setColor\0color\0"
    "setMaximumBufferSize\0size\0clearBuffer\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScopeCurve[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a,
       8,    1,   50,    2, 0x0a,
      10,    1,   53,    2, 0x0a,
      12,    1,   56,    2, 0x0a,
      14,    0,   59,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Double, QMetaType::QDateTime,    9,
    QMetaType::Void, QMetaType::QColor,   11,
    QMetaType::Void, QMetaType::ULong,   13,
    QMetaType::Void,

       0        // eod
};

void ScopeCurve::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScopeCurve *_t = static_cast<ScopeCurve *>(_o);
        switch (_id) {
        case 0: _t->aboutToDestroy((*reinterpret_cast< ScopeCurve*(*)>(_a[1]))); break;
        case 1: _t->updateVariable((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 2: { double _r = _t->elapsed((*reinterpret_cast< const QDateTime(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 3: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 4: _t->setMaximumBufferSize((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 5: _t->clearBuffer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ScopeCurve* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ScopeCurve::*_t)(ScopeCurve * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ScopeCurve::aboutToDestroy)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ScopeCurve::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ScopeCurve.data,
      qt_meta_data_ScopeCurve,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScopeCurve::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScopeCurve::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScopeCurve.stringdata))
        return static_cast<void*>(const_cast< ScopeCurve*>(this));
    if (!strcmp(_clname, "QwtPlotCurve"))
        return static_cast< QwtPlotCurve*>(const_cast< ScopeCurve*>(this));
    return QObject::qt_metacast(_clname);
}

int ScopeCurve::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ScopeCurve::aboutToDestroy(ScopeCurve * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
