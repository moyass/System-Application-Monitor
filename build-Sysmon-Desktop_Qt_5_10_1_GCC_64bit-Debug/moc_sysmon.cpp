/****************************************************************************
** Meta object code from reading C++ file 'sysmon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Sysmon/sysmon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sysmon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sysmon_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sysmon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sysmon_t qt_meta_stringdata_Sysmon = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Sysmon"
QT_MOC_LITERAL(1, 7, 18), // "aboutButtonHandler"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 20), // "monitorButtonHandler"
QT_MOC_LITERAL(4, 48, 20), // "refreshButtonHandler"
QT_MOC_LITERAL(5, 69, 4), // "Temp"
QT_MOC_LITERAL(6, 74, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(7, 94, 10), // "inputModel"
QT_MOC_LITERAL(8, 105, 18), // "std::vector<pid_t>"
QT_MOC_LITERAL(9, 124, 5) // "procs"

    },
    "Sysmon\0aboutButtonHandler\0\0"
    "monitorButtonHandler\0refreshButtonHandler\0"
    "Temp\0QStandardItemModel*\0inputModel\0"
    "std::vector<pid_t>\0procs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sysmon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    2,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,

       0        // eod
};

void Sysmon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sysmon *_t = static_cast<Sysmon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->aboutButtonHandler(); break;
        case 1: _t->monitorButtonHandler(); break;
        case 2: _t->refreshButtonHandler(); break;
        case 3: _t->Temp((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< std::vector<pid_t>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Sysmon::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Sysmon.data,
      qt_meta_data_Sysmon,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Sysmon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sysmon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sysmon.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Sysmon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
