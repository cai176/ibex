/****************************************************************************
** Meta object code from reading C++ file 'examinationmgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../temp/ibex-master/core/Controller/examinationmgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'examinationmgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ExaminationMgr_t {
    QByteArrayData data[6];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExaminationMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExaminationMgr_t qt_meta_stringdata_ExaminationMgr = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ExaminationMgr"
QT_MOC_LITERAL(1, 15, 21), // "OnActivateExamination"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 38), // "OnActivateExaminationAfterReg..."
QT_MOC_LITERAL(4, 77, 22), // "RegistrationFormModel&"
QT_MOC_LITERAL(5, 100, 5) // "model"

    },
    "ExaminationMgr\0OnActivateExamination\0"
    "\0OnActivateExaminationAfterRegistration\0"
    "RegistrationFormModel&\0model"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExaminationMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void ExaminationMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExaminationMgr *_t = static_cast<ExaminationMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnActivateExamination(); break;
        case 1: _t->OnActivateExaminationAfterRegistration((*reinterpret_cast< RegistrationFormModel(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ExaminationMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ExaminationMgr.data,
      qt_meta_data_ExaminationMgr,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ExaminationMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExaminationMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ExaminationMgr.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ExaminationMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE