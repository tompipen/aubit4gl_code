TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

TARGET = updatecp

CONFIG += console
CONFIG -= gui
CONFIG -= xml
CONFIG -= network

HEADERS += \
    copybinaries.h

SOURCES += \
    copybinaries.cpp \
    maincopy.cpp
