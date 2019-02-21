/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[30];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "signalStopJoy"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "signalStopVideo"
QT_MOC_LITERAL(4, 42, 15), // "signalStopTCPIP"
QT_MOC_LITERAL(5, 58, 13), // "signalOpenTCP"
QT_MOC_LITERAL(6, 72, 3), // "str"
QT_MOC_LITERAL(7, 76, 14), // "signalSendData"
QT_MOC_LITERAL(8, 91, 14), // "my_tcp_packet*"
QT_MOC_LITERAL(9, 106, 4), // "pack"
QT_MOC_LITERAL(10, 111, 12), // "slotJoy_Axis"
QT_MOC_LITERAL(11, 124, 4), // "Axis"
QT_MOC_LITERAL(12, 129, 5), // "Value"
QT_MOC_LITERAL(13, 135, 14), // "slotJoy_Button"
QT_MOC_LITERAL(14, 150, 6), // "Button"
QT_MOC_LITERAL(15, 157, 4), // "Stat"
QT_MOC_LITERAL(16, 162, 11), // "slotJoy_HAT"
QT_MOC_LITERAL(17, 174, 11), // "slotEM_Stop"
QT_MOC_LITERAL(18, 186, 8), // "slotView"
QT_MOC_LITERAL(19, 195, 3), // "pix"
QT_MOC_LITERAL(20, 199, 12), // "slotJoyError"
QT_MOC_LITERAL(21, 212, 14), // "slotVideoError"
QT_MOC_LITERAL(22, 227, 14), // "slotTCPIPError"
QT_MOC_LITERAL(23, 242, 8), // "slotOpen"
QT_MOC_LITERAL(24, 251, 13), // "slotConnected"
QT_MOC_LITERAL(25, 265, 12), // "slotWinStart"
QT_MOC_LITERAL(26, 278, 15), // "slotProcessExit"
QT_MOC_LITERAL(27, 294, 4), // "code"
QT_MOC_LITERAL(28, 299, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(29, 320, 4) // "stat"

    },
    "MainWindow\0signalStopJoy\0\0signalStopVideo\0"
    "signalStopTCPIP\0signalOpenTCP\0str\0"
    "signalSendData\0my_tcp_packet*\0pack\0"
    "slotJoy_Axis\0Axis\0Value\0slotJoy_Button\0"
    "Button\0Stat\0slotJoy_HAT\0slotEM_Stop\0"
    "slotView\0pix\0slotJoyError\0slotVideoError\0"
    "slotTCPIPError\0slotOpen\0slotConnected\0"
    "slotWinStart\0slotProcessExit\0code\0"
    "QProcess::ExitStatus\0stat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    1,  102,    2, 0x06 /* Public */,
       7,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,  108,    2, 0x08 /* Private */,
      13,    2,  113,    2, 0x08 /* Private */,
      16,    1,  118,    2, 0x08 /* Private */,
      17,    0,  121,    2, 0x08 /* Private */,
      18,    1,  122,    2, 0x08 /* Private */,
      20,    1,  125,    2, 0x08 /* Private */,
      21,    1,  128,    2, 0x08 /* Private */,
      22,    1,  131,    2, 0x08 /* Private */,
      23,    0,  134,    2, 0x08 /* Private */,
      24,    1,  135,    2, 0x08 /* Private */,
      25,    0,  138,    2, 0x08 /* Private */,
      26,    2,  139,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::SChar,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,   19,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 28,   27,   29,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalStopJoy(); break;
        case 1: _t->signalStopVideo(); break;
        case 2: _t->signalStopTCPIP(); break;
        case 3: _t->signalOpenTCP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->signalSendData((*reinterpret_cast< my_tcp_packet*(*)>(_a[1]))); break;
        case 5: _t->slotJoy_Axis((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->slotJoy_Button((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->slotJoy_HAT((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 8: _t->slotEM_Stop(); break;
        case 9: _t->slotView((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 10: _t->slotJoyError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->slotVideoError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->slotTCPIPError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->slotOpen(); break;
        case 14: _t->slotConnected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->slotWinStart(); break;
        case 16: _t->slotProcessExit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalStopJoy)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalStopVideo)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalStopTCPIP)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalOpenTCP)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(my_tcp_packet * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSendData)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalStopJoy()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::signalStopVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::signalStopTCPIP()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::signalOpenTCP(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::signalSendData(my_tcp_packet * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
