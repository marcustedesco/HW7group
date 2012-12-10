/****************************************************************************
** Meta object code from reading C++ file 'clientWid1.h'
**
** Created: Sun Dec 9 23:00:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clientWid1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientWid1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_clientWid1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   11,   27,   11, 0x0a,
      43,   11,   27,   11, 0x0a,
      53,   11,   27,   11, 0x0a,
      63,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_clientWid1[] = {
    "clientWid1\0\0buttonPushed()\0QString\0"
    "getIP()\0getPort()\0getName()\0ipBoxChanged()\0"
    "portBoxChanged()\0nameBoxChanged()\0"
    "sendButtonPushed()\0"
};

void clientWid1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        clientWid1 *_t = static_cast<clientWid1 *>(_o);
        switch (_id) {
        case 0: _t->buttonPushed(); break;
        case 1: { QString _r = _t->getIP();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->getPort();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->getName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: _t->ipBoxChanged(); break;
        case 5: _t->portBoxChanged(); break;
        case 6: _t->nameBoxChanged(); break;
        case 7: _t->sendButtonPushed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData clientWid1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject clientWid1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_clientWid1,
      qt_meta_data_clientWid1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &clientWid1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *clientWid1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *clientWid1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_clientWid1))
        return static_cast<void*>(const_cast< clientWid1*>(this));
    return QWidget::qt_metacast(_clname);
}

int clientWid1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void clientWid1::buttonPushed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
