/****************************************************************************
** Meta object code from reading C++ file 'sysmon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Sysmon/sysmon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sysmon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Sysmon_t {
    QByteArrayData data[19];
    char stringdata0[245];
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
QT_MOC_LITERAL(5, 69, 18), // "debugButtonHandler"
QT_MOC_LITERAL(6, 88, 5), // "fetch"
QT_MOC_LITERAL(7, 94, 18), // "setPerformanceMode"
QT_MOC_LITERAL(8, 113, 16), // "setPowersaveMode"
QT_MOC_LITERAL(9, 130, 11), // "setProgress"
QT_MOC_LITERAL(10, 142, 3), // "val"
QT_MOC_LITERAL(11, 146, 15), // "connectToSlider"
QT_MOC_LITERAL(12, 162, 15), // "OnDoubleClicked"
QT_MOC_LITERAL(13, 178, 5), // "index"
QT_MOC_LITERAL(14, 184, 4), // "Temp"
QT_MOC_LITERAL(15, 189, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(16, 209, 10), // "inputModel"
QT_MOC_LITERAL(17, 220, 18), // "std::vector<pid_t>"
QT_MOC_LITERAL(18, 239, 5) // "procs"

    },
    "Sysmon\0aboutButtonHandler\0\0"
    "monitorButtonHandler\0refreshButtonHandler\0"
    "debugButtonHandler\0fetch\0setPerformanceMode\0"
    "setPowersaveMode\0setProgress\0val\0"
    "connectToSlider\0OnDoubleClicked\0index\0"
    "Temp\0QStandardItemModel*\0inputModel\0"
    "std::vector<pid_t>\0procs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sysmon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    1,   76,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,
      12,    1,   80,    2, 0x0a /* Public */,
      14,    2,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,

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
        case 3: _t->debugButtonHandler(); break;
        case 4: _t->fetch(); break;
        case 5: _t->setPerformanceMode(); break;
        case 6: _t->setPowersaveMode(); break;
        case 7: _t->setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->connectToSlider(); break;
        case 9: _t->OnDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->Temp((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< std::vector<pid_t>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Sysmon::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Sysmon.data,
      qt_meta_data_Sysmon,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Sysmon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sysmon::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Sysmon.stringdata0))
        return static_cast<void*>(const_cast< Sysmon*>(this));
    return QWidget::qt_metacast(_clname);
}

int Sysmon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
