/****************************************************************************
** Meta object code from reading C++ file 'ScopeView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NetworkViewer/GUI/plugins/ScopeView/ScopeView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScopeView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScopeView_t {
    QByteArrayData data[20];
    char stringdata[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ScopeView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ScopeView_t qt_meta_stringdata_ScopeView = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 8),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 15),
QT_MOC_LITERAL(4, 36, 8),
QT_MOC_LITERAL(5, 45, 11),
QT_MOC_LITERAL(6, 57, 17),
QT_MOC_LITERAL(7, 75, 12),
QT_MOC_LITERAL(8, 88, 8),
QT_MOC_LITERAL(9, 97, 13),
QT_MOC_LITERAL(10, 111, 8),
QT_MOC_LITERAL(11, 120, 5),
QT_MOC_LITERAL(12, 126, 11),
QT_MOC_LITERAL(13, 138, 12),
QT_MOC_LITERAL(14, 151, 11),
QT_MOC_LITERAL(15, 163, 5),
QT_MOC_LITERAL(16, 169, 21),
QT_MOC_LITERAL(17, 191, 4),
QT_MOC_LITERAL(18, 196, 11),
QT_MOC_LITERAL(19, 208, 10)
    },
    "ScopeView\0addCurve\0\0ModuleVariable*\0"
    "variable\0removeCurve\0legendItemClicked\0"
    "QwtPlotItem*\0plotItem\0legendClicked\0"
    "itemInfo\0index\0updateTimer\0destroyCurve\0"
    "ScopeCurve*\0curve\0setCurveMaxBufferSize\0"
    "size\0clearCurves\0saveCurves\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScopeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a,
       5,    1,   62,    2, 0x0a,
       6,    1,   65,    2, 0x09,
       9,    2,   68,    2, 0x09,
      12,    0,   73,    2, 0x09,
      13,    1,   74,    2, 0x09,
      16,    1,   77,    2, 0x09,
      18,    0,   80,    2, 0x09,
      19,    0,   81,    2, 0x09,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QVariant, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScopeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScopeView *_t = static_cast<ScopeView *>(_o);
        switch (_id) {
        case 0: _t->addCurve((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 1: _t->removeCurve((*reinterpret_cast< ModuleVariable*(*)>(_a[1]))); break;
        case 2: _t->legendItemClicked((*reinterpret_cast< QwtPlotItem*(*)>(_a[1]))); break;
        case 3: _t->legendClicked((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->updateTimer(); break;
        case 5: _t->destroyCurve((*reinterpret_cast< ScopeCurve*(*)>(_a[1]))); break;
        case 6: _t->setCurveMaxBufferSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->clearCurves(); break;
        case 8: _t->saveCurves(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QwtPlotItem* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ScopeCurve* >(); break;
            }
            break;
        }
    }
}

const QMetaObject ScopeView::staticMetaObject = {
    { &BasePlugin::staticMetaObject, qt_meta_stringdata_ScopeView.data,
      qt_meta_data_ScopeView,  qt_static_metacall, 0, 0}
};


const QMetaObject *ScopeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScopeView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ScopeView.stringdata))
        return static_cast<void*>(const_cast< ScopeView*>(this));
    if (!strcmp(_clname, "Ui::ScopeView"))
        return static_cast< Ui::ScopeView*>(const_cast< ScopeView*>(this));
    return BasePlugin::qt_metacast(_clname);
}

int ScopeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BasePlugin::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
