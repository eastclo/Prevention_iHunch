/****************************************************************************
** Meta object code from reading C++ file 'iHunch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../iHunch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iHunch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iHunch_t {
    QByteArrayData data[24];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iHunch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iHunch_t qt_meta_stringdata_iHunch = {
    {
QT_MOC_LITERAL(0, 0, 6), // "iHunch"
QT_MOC_LITERAL(1, 7, 11), // "textChanger"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 6), // "string"
QT_MOC_LITERAL(4, 27, 3), // "arr"
QT_MOC_LITERAL(5, 31, 11), // "closeSignal"
QT_MOC_LITERAL(6, 43, 11), // "debugSignal"
QT_MOC_LITERAL(7, 55, 4), // "mode"
QT_MOC_LITERAL(8, 60, 13), // "iconActivated"
QT_MOC_LITERAL(9, 74, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(10, 108, 6), // "reason"
QT_MOC_LITERAL(11, 115, 7), // "setPose"
QT_MOC_LITERAL(12, 123, 5), // "mybtn"
QT_MOC_LITERAL(13, 129, 11), // "minimum_Btn"
QT_MOC_LITERAL(14, 141, 9), // "close_Btn"
QT_MOC_LITERAL(15, 151, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(16, 166, 12), // "QMouseEvent*"
QT_MOC_LITERAL(17, 179, 5), // "mouse"
QT_MOC_LITERAL(18, 185, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(19, 203, 5), // "event"
QT_MOC_LITERAL(20, 209, 12), // "alramMessage"
QT_MOC_LITERAL(21, 222, 11), // "modeChanged"
QT_MOC_LITERAL(22, 234, 14), // "timeCalculator"
QT_MOC_LITERAL(23, 249, 9) // "debugSlot"

    },
    "iHunch\0textChanger\0\0string\0arr\0"
    "closeSignal\0debugSignal\0mode\0iconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0setPose\0mybtn\0minimum_Btn\0"
    "close_Btn\0mouseMoveEvent\0QMouseEvent*\0"
    "mouse\0mouseReleaseEvent\0event\0"
    "alramMessage\0modeChanged\0timeCalculator\0"
    "debugSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iHunch[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   91,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,
      15,    1,   98,    2, 0x0a /* Public */,
      18,    1,  101,    2, 0x0a /* Public */,
      20,    0,  104,    2, 0x0a /* Public */,
      21,    1,  105,    2, 0x0a /* Public */,
      22,    0,  108,    2, 0x0a /* Public */,
      23,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void iHunch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<iHunch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textChanger((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->closeSignal(); break;
        case 2: _t->debugSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 4: _t->setPose(); break;
        case 5: _t->mybtn(); break;
        case 6: _t->minimum_Btn(); break;
        case 7: _t->close_Btn(); break;
        case 8: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: _t->alramMessage(); break;
        case 11: _t->modeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->timeCalculator(); break;
        case 13: _t->debugSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (iHunch::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iHunch::textChanger)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (iHunch::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iHunch::closeSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (iHunch::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iHunch::debugSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject iHunch::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_iHunch.data,
    qt_meta_data_iHunch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *iHunch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iHunch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iHunch.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int iHunch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void iHunch::textChanger(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void iHunch::closeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void iHunch::debugSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
