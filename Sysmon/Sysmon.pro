#-------------------------------------------------
#
# Project created by QtCreator 2018-04-01T10:28:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sysmon
TEMPLATE = app


SOURCES += main.cpp\
        sysmon.cpp \
    get-proc-info.cpp

HEADERS  += sysmon.h \
    main.h

FORMS    += sysmon.ui

LIBS += -lprocps

