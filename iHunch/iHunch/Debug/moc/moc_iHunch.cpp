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
    QByteArrayData data[22];
    char stringdata0[237];
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
QT_MOC_LITERAL(6, 43, 13), // "iconActivated"
QT_MOC_LITERAL(7, 57, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(8, 91, 6), // "reason"
QT_MOC_LITERAL(9, 98, 7), // "setPose"
QT_MOC_LITERAL(10, 106, 5), // "mybtn"
QT_MOC_LITERAL(11, 112, 11), // "minimum_Btn"
QT_MOC_LITERAL(12, 124, 9), // "close_Btn"
QT_MOC_LITERAL(13, 134, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(14, 149, 12), // "QMouseEvent*"
QT_MOC_LITERAL(15, 162, 5), // "mouse"
QT_MOC_LITERAL(16, 168, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(17, 186, 5), // "event"
QT_MOC_LITERAL(18, 192, 12), // "alramMessage"
QT_MOC_LITERAL(19, 205, 11), // "modeChanged"
QT_MOC_LITERAL(20, 217, 4), // "mode"
QT_MOC_LITERAL(21, 222, 14) // "timeCalculator"

    },
    "iHunch\0textChanger\0\0string\0arr\0"
    "closeSignal\0iconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0setPose\0mybtn\0minimum_Btn\0"
    "close_Btn\0mouseMoveEvent\0QMouseEvent*\0"
    "mouse\0mouseReleaseEvent\0event\0"
    "alramMessage\0modeChanged\0mode\0"
    "timeCalculator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iHunch[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   78,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    1,   85,    2, 0x0a /* Public */,
      16,    1,   88,    2, 0x0a /* Public */,
      18,    0,   91,    2, 0x0a /* Public */,
      19,    1,   92,    2, 0x0a /* Public */,
      21,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,

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
        case 2: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 3: _t->setPose(); break;
        case 4: _t->mybtn(); break;
        case 5: _t->minimum_Btn(); break;
        case 6: _t->close_Btn(); break;
        case 7: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 8: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 9: _t->alramMessage(); break;
        case 10: _t->modeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->timeCalculator(); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
