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
    QByteArrayData data[11];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setupPose_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setupPose_t qt_meta_stringdata_setupPose = {
    {
QT_MOC_LITERAL(0, 0, 9), // "setupPose"
QT_MOC_LITERAL(1, 10, 10), // "onStartBtn"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "onStopBtn"
QT_MOC_LITERAL(4, 32, 12), // "onCaptureBtn"
QT_MOC_LITERAL(5, 45, 8), // "camError"
QT_MOC_LITERAL(6, 54, 14), // "QCamera::Error"
QT_MOC_LITERAL(7, 69, 5), // "error"
QT_MOC_LITERAL(8, 75, 12), // "imageCapture"
QT_MOC_LITERAL(9, 88, 3), // "pid"
QT_MOC_LITERAL(10, 92, 8) // "pPriview"

    },
    "setupPose\0onStartBtn\0\0onStopBtn\0"
    "onCaptureBtn\0camError\0QCamera::Error\0"
    "error\0imageCapture\0pid\0pPriview"
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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       8,    2,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    9,   10,

       0        // eod
};

void setupPose::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<setupPose *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStartBtn(); break;
        case 1: _t->onStopBtn(); break;
        case 2: _t->onCaptureBtn(); break;
        case 3: _t->camError((*reinterpret_cast< QCamera::Error(*)>(_a[1]))); break;
        case 4: _t->imageCapture((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCamera::Error >(); break;
            }
            break;
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
