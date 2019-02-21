/****************************************************************************
** Meta object code from reading C++ file 'my_joy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../my_joy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_joy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_my_joy_t {
    QByteArrayData data[14];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_my_joy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_my_joy_t qt_meta_stringdata_my_joy = {
    {
QT_MOC_LITERAL(0, 0, 6), // "my_joy"
QT_MOC_LITERAL(1, 7, 16), // "signalAxisChange"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "Axis"
QT_MOC_LITERAL(4, 30, 5), // "Value"
QT_MOC_LITERAL(5, 36, 15), // "signalButtonPUP"
QT_MOC_LITERAL(6, 52, 6), // "Button"
QT_MOC_LITERAL(7, 59, 4), // "Stat"
QT_MOC_LITERAL(8, 64, 15), // "signalHATChange"
QT_MOC_LITERAL(9, 80, 14), // "signalJoyError"
QT_MOC_LITERAL(10, 95, 3), // "str"
QT_MOC_LITERAL(11, 99, 14), // "signalFinished"
QT_MOC_LITERAL(12, 114, 6), // "dowork"
QT_MOC_LITERAL(13, 121, 8) // "slotStop"

    },
    "my_joy\0signalAxisChange\0\0Axis\0Value\0"
    "signalButtonPUP\0Button\0Stat\0signalHATChange\0"
    "signalJoyError\0str\0signalFinished\0"
    "dowork\0slotStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_my_joy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    2,   54,    2, 0x06 /* Public */,
       8,    1,   59,    2, 0x06 /* Public */,
       9,    1,   62,    2, 0x06 /* Public */,
      11,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   66,    2, 0x0a /* Public */,
      13,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::SChar,    4,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void my_joy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        my_joy *_t = static_cast<my_joy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalAxisChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->signalButtonPUP((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->signalHATChange((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 3: _t->signalJoyError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->signalFinished(); break;
        case 5: _t->dowork(); break;
        case 6: _t->slotStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (my_joy::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&my_joy::signalAxisChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (my_joy::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&my_joy::signalButtonPUP)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (my_joy::*)(qint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&my_joy::signalHATChange)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (my_joy::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&my_joy::signalJoyError)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (my_joy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&my_joy::signalFinished)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject my_joy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_my_joy.data,
      qt_meta_data_my_joy,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *my_joy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *my_joy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_my_joy.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int my_joy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void my_joy::signalAxisChange(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void my_joy::signalButtonPUP(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void my_joy::signalHATChange(qint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void my_joy::signalJoyError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void my_joy::signalFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
