/****************************************************************************
** Meta object code from reading C++ file 'joypadw.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "joypadw.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'joypadw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JoyPadWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   27,   13,   13, 0x0a,
      42,   13,   13,   13, 0x0a,
      51,   13,   13,   13, 0x0a,
      59,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_JoyPadWidget[] = {
    "JoyPadWidget\0\0flashed(int)\0on\0flash(bool)\0"
    "update()\0clear()\0setAll()\0"
};

void JoyPadWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        JoyPadWidget *_t = static_cast<JoyPadWidget *>(_o);
        switch (_id) {
        case 0: _t->flashed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->flash((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->update(); break;
        case 3: _t->clear(); break;
        case 4: _t->setAll(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData JoyPadWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject JoyPadWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_JoyPadWidget,
      qt_meta_data_JoyPadWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JoyPadWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JoyPadWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JoyPadWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JoyPadWidget))
        return static_cast<void*>(const_cast< JoyPadWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int JoyPadWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void JoyPadWidget::flashed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
