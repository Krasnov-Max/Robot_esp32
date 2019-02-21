/****************************************************************************
** Meta object code from reading C++ file 'my_video.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../my_video.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'my_video.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_My_video_t {
    QByteArrayData data[11];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_My_video_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_My_video_t qt_meta_stringdata_My_video = {
    {
QT_MOC_LITERAL(0, 0, 8), // "My_video"
QT_MOC_LITERAL(1, 9, 16), // "signalFrameReady"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 3), // "pix"
QT_MOC_LITERAL(4, 31, 16), // "signalVideoError"
QT_MOC_LITERAL(5, 48, 3), // "str"
QT_MOC_LITERAL(6, 52, 14), // "signalFinished"
QT_MOC_LITERAL(7, 67, 14), // "signalWinStart"
QT_MOC_LITERAL(8, 82, 6), // "dowork"
QT_MOC_LITERAL(9, 89, 8), // "slotStop"
QT_MOC_LITERAL(10, 98, 13) // "slotgetTimer2"

    },
    "My_video\0signalFrameReady\0\0pix\0"
    "signalVideoError\0str\0signalFinished\0"
    "signalWinStart\0dowork\0slotStop\0"
    "slotgetTimer2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_My_video[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    0,   55,    2, 0x06 /* Public */,
       7,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void My_video::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        My_video *_t = static_cast<My_video *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalFrameReady((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->signalVideoError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signalFinished(); break;
        case 3: _t->signalWinStart(); break;
        case 4: _t->dowork(); break;
        case 5: _t->slotStop(); break;
        case 6: _t->slotgetTimer2(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (My_video::*)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&My_video::signalFrameReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (My_video::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&My_video::signalVideoError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (My_video::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&My_video::signalFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (My_video::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&My_video::signalWinStart)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject My_video::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_My_video.data,
      qt_meta_data_My_video,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *My_video::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *My_video::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_My_video.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int My_video::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void My_video::signalFrameReady(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void My_video::signalVideoError(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void My_video::signalFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void My_video::signalWinStart()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
