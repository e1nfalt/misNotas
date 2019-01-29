/****************************************************************************
** Meta object code from reading C++ file 'audionoteform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../misNotas/audionoteform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audionoteform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AudioNoteForm_t {
    QByteArrayData data[11];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioNoteForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioNoteForm_t qt_meta_stringdata_AudioNoteForm = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AudioNoteForm"
QT_MOC_LITERAL(1, 14, 4), // "play"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "open"
QT_MOC_LITERAL(4, 25, 4), // "save"
QT_MOC_LITERAL(5, 30, 18), // "volume_slider_move"
QT_MOC_LITERAL(6, 49, 15), // "positionChanged"
QT_MOC_LITERAL(7, 65, 15), // "durationChanged"
QT_MOC_LITERAL(8, 81, 11), // "setPosition"
QT_MOC_LITERAL(9, 93, 17), // "mediaStateChanged"
QT_MOC_LITERAL(10, 111, 19) // "QMediaPlayer::State"

    },
    "AudioNoteForm\0play\0\0open\0save\0"
    "volume_slider_move\0positionChanged\0"
    "durationChanged\0setPosition\0"
    "mediaStateChanged\0QMediaPlayer::State"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioNoteForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       7,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void AudioNoteForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioNoteForm *_t = static_cast<AudioNoteForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->open(); break;
        case 2: _t->save(); break;
        case 3: _t->volume_slider_move((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->mediaStateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AudioNoteForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AudioNoteForm.data,
      qt_meta_data_AudioNoteForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AudioNoteForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioNoteForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioNoteForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AudioNoteForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
