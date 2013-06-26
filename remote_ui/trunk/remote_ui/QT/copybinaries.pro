TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

TARGET = updatecp

CONFIG += console
CONFIG -= gui
CONFIG -= xml
CONFIG -= network

macx {
  QMAKE_POST_LINK = DYLD_LIBRARY_PATH=$$OUT_PWD/lib $$PWD/libsintobundle $$OUT_PWD/updatecp.app
}

HEADERS += \
    copybinaries.h

SOURCES += \
    copybinaries.cpp \
    maincopy.cpp
