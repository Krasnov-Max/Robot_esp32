/****************************************************************************
** Meta object code from reading C++ file 'tcpip_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpip_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpip_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tcpip_client_t {
    QByteArrayData data[20];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tcpip_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tcpip_client_t qt_meta_stringdata_tcpip_client = {
    {
QT_MOC_LITERAL(0, 0, 12), // "tcpip_client"
QT_MOC_LITERAL(1, 13, 14), // "signalTCPError"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(4, 58, 3), // "err"
QT_MOC_LITERAL(5, 62, 14), // "signalFinished"
QT_MOC_LITERAL(6, 77, 14), // "signalDataSend"
QT_MOC_LITERAL(7, 92, 14), // "my_tcp_packet*"
QT_MOC_LITERAL(8, 107, 4), // "data"
QT_MOC_LITERAL(9, 112, 17), // "signalTCPProblems"
QT_MOC_LITERAL(10, 130, 3), // "str"
QT_MOC_LITERAL(11, 134, 17), // "signalIsConnected"
QT_MOC_LITERAL(12, 152, 11), // "slotGetData"
QT_MOC_LITERAL(13, 164, 9), // "slotError"
QT_MOC_LITERAL(14, 174, 6), // "dowork"
QT_MOC_LITERAL(15, 181, 8), // "slotStop"
QT_MOC_LITERAL(16, 190, 14), // "slotDataToSend"
QT_MOC_LITERAL(17, 205, 18), // "slotOpenConnection"
QT_MOC_LITERAL(18, 224, 19), // "slotCloseConnection"
QT_MOC_LITERAL(19, 244, 12) // "slotLifePack"

    },
    "tcpip_client\0signalTCPError\0\0"
    "QAbstractSocket::SocketError\0err\0"
    "signalFinished\0signalDataSend\0"
    "my_tcp_packet*\0data\0signalTCPProblems\0"
    "str\0signalIsConnected\0slotGetData\0"
    "slotError\0dowork\0slotStop\0slotDataToSend\0"
    "slotOpenConnection\0slotCloseConnection\0"
    "slotLifePack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tcpip_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    1,   83,    2, 0x06 /* Public */,
       9,    1,   86,    2, 0x06 /* Public */,
      11,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   92,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,
      16,    1,   98,    2, 0x0a /* Public */,
      17,    1,  101,    2, 0x0a /* Public */,
      18,    0,  104,    2, 0x0a /* Public */,
      19,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tcpip_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tcpip_client *_t = static_cast<tcpip_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalTCPError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->signalFinished(); break;
        case 2: _t->signalDataSend((*reinterpret_cast< my_tcp_packet*(*)>(_a[1]))); break;
        case 3: _t->signalTCPProblems((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->signalIsConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->slotGetData(); break;
        case 6: _t->slotError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->dowork(); break;
        case 8: _t->slotStop(); break;
        case 9: _t->slotDataToSend((*reinterpret_cast< my_tcp_packet*(*)>(_a[1]))); break;
        case 10: _t->slotOpenConnection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->slotCloseConnection(); break;
        case 12: _t->slotLifePack(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (tcpip_client::*)(QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpip_client::signalTCPError)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (tcpip_client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpip_client::signalFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (tcpip_client::*)(my_tcp_packet * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpip_client::signalDataSend)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (tcpip_client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpip_client::signalTCPProblems)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (tcpip_client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpip_client::signalIsConnected)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject tcpip_client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_tcpip_client.data,
      qt_meta_data_tcpip_client,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *tcpip_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcpip_client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tcpip_client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int tcpip_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void tcpip_client::signalTCPError(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tcpip_client::signalFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void tcpip_client::signalDataSend(my_tcp_packet * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void tcpip_client::signalTCPProblems(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void tcpip_client::signalIsConnected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
