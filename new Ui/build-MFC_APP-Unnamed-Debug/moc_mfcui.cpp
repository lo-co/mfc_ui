/****************************************************************************
** Meta object code from reading C++ file 'mfcui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MFC_APP/mfcui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mfcui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MfcUi[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      20,   17,    6,    6, 0x08,
      50,   17,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MfcUi[] = {
    "MfcUi\0\0getData()\0sp\0on_ac0SP_valueChanged(double)\0"
    "on_ac1SP_valueChanged(double)\0"
};

void MfcUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MfcUi *_t = static_cast<MfcUi *>(_o);
        switch (_id) {
        case 0: _t->getData(); break;
        case 1: _t->on_ac0SP_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_ac1SP_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MfcUi::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MfcUi::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MfcUi,
      qt_meta_data_MfcUi, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MfcUi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MfcUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MfcUi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MfcUi))
        return static_cast<void*>(const_cast< MfcUi*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MfcUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
