#-------------------------------------------------
#
# Project created by QtCreator 2017-12-01T17:03:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WSYPractice
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wsy.cpp \
    wsylist.cpp \
    resultcount.cpp

HEADERS  += mainwindow.h \
    wsy.h \
    wsylist.h \
    resultcount.h

FORMS    += mainwindow.ui

RESOURCES += \
    wsypractice.qrc

DISTFILES += \
    rc.rc

RC_FILE += \
    rc.rc
