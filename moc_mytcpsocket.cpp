/****************************************************************************
** Meta object code from reading C++ file 'mytcpsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mytcpsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myTCPSocket_t {
    QByteArrayData data[12];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myTCPSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myTCPSocket_t qt_meta_stringdata_myTCPSocket = {
    {
QT_MOC_LITERAL(0, 0, 11), // "myTCPSocket"
QT_MOC_LITERAL(1, 12, 8), // "mySignal"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 18), // "SignalDisconnected"
QT_MOC_LITERAL(4, 41, 18), // "SignalDataReceived"
QT_MOC_LITERAL(5, 60, 9), // "connected"
QT_MOC_LITERAL(6, 70, 12), // "disconnected"
QT_MOC_LITERAL(7, 83, 12), // "bytesWritten"
QT_MOC_LITERAL(8, 96, 5), // "bytes"
QT_MOC_LITERAL(9, 102, 9), // "readyRead"
QT_MOC_LITERAL(10, 112, 9), // "doConnect"
QT_MOC_LITERAL(11, 122, 12) // "doDisconnect"

    },
    "myTCPSocket\0mySignal\0\0SignalDisconnected\0"
    "SignalDataReceived\0connected\0disconnected\0"
    "bytesWritten\0bytes\0readyRead\0doConnect\0"
    "doDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myTCPSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int, QMetaType::LongLong,    8,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void myTCPSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myTCPSocket *_t = static_cast<myTCPSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mySignal(); break;
        case 1: _t->SignalDisconnected(); break;
        case 2: _t->SignalDataReceived(); break;
        case 3: { int _r = _t->connected();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->disconnected();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->bytesWritten((*reinterpret_cast< qint64(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->readyRead();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->doConnect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->doDisconnect();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (myTCPSocket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTCPSocket::mySignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (myTCPSocket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTCPSocket::SignalDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (myTCPSocket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myTCPSocket::SignalDataReceived)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject myTCPSocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_myTCPSocket.data,
      qt_meta_data_myTCPSocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *myTCPSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myTCPSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myTCPSocket.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int myTCPSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void myTCPSocket::mySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void myTCPSocket::SignalDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void myTCPSocket::SignalDataReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
