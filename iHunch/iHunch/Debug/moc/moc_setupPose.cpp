/****************************************************************************
** Meta object code from reading C++ file 'setupPose.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../setupPose.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setupPose.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_setupPose_t {
    QByteArrayData data[12];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setupPose_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setupPose_t qt_meta_stringdata_setupPose = {
    {
QT_MOC_LITERAL(0, 0, 9), // "setupPose"
QT_MOC_LITERAL(1, 10, 11), // "initPoseBtn"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(4, 38, 12), // "QMouseEvent*"
QT_MOC_LITERAL(5, 51, 5), // "mouse"
QT_MOC_LITERAL(6, 57, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(7, 75, 5), // "event"
QT_MOC_LITERAL(8, 81, 11), // "textChanged"
QT_MOC_LITERAL(9, 93, 6), // "string"
QT_MOC_LITERAL(10, 100, 3), // "arr"
QT_MOC_LITERAL(11, 104, 9) // "closeSlot"

    },
    "setupPose\0initPoseBtn\0\0mouseMoveEvent\0"
    "QMouseEvent*\0mouse\0mouseReleaseEvent\0"
    "event\0textChanged\0string\0arr\0closeSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setupPose[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,
       8,    1,   46,    2, 0x0a /* Public */,
      11,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void setupPose::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<setupPose *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initPoseBtn(); break;
        case 1: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->textChanged((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 4: _t->closeSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject setupPose::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_setupPose.data,
    qt_meta_data_setupPose,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *setupPose::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setupPose::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_setupPose.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int setupPose::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
