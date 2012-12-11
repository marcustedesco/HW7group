/****************************************************************************
** Meta object code from reading C++ file 'clientWid2.h'
**
** Created: Mon Dec 10 23:50:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "clientWid2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientWid2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_clientWid2[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      35,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
     105,   97,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_clientWid2[] = {
    "clientWid2\0\0connectPushed(QString)\0"
    "disconnectPushed()\0sendConnectPushed()\0"
    "sendDisconnectPushed()\0friends\0"
    "updateFriends(QStringList)\0"
};

void clientWid2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        clientWid2 *_t = static_cast<clientWid2 *>(_o);
        switch (_id) {
        case 0: _t->connectPushed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->disconnectPushed(); break;
        case 2: _t->sendConnectPushed(); break;
        case 3: _t->sendDisconnectPushed(); break;
        case 4: _t->updateFriends((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData clientWid2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject clientWid2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_clientWid2,
      qt_meta_data_clientWid2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &clientWid2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *clientWid2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *clientWid2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_clientWid2))
        return static_cast<void*>(const_cast< clientWid2*>(this));
    return QWidget::qt_metacast(_clname);
}

int clientWid2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void clientWid2::connectPushed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void clientWid2::disconnectPushed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
