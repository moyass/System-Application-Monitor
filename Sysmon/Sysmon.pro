#-------------------------------------------------
#
# Project created by QtCreator 2018-04-01T10:28:33
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sysmon
TEMPLATE = app


SOURCES += main.cpp\
        sysmon.cpp \
    get-proc-info.cpp \
    QRoundProgressBar.cpp \
    ../battery.cc \
    ../cpu_frequency.cc \
    ../cpu_temp.cc

HEADERS  += sysmon.h \
    main.h \
    process.h \
    QRoundProgressBar.h

FORMS    += sysmon.ui \
    dockwidget.ui

LIBS += -lprocps

DISTFILES += \
    ../battery-percentage.sh

