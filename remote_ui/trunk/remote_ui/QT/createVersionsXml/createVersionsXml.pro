#-------------------------------------------------
#
# Project created by QtCreator 2012-05-25T20:28:44
#
#-------------------------------------------------

QT       += core

QT       -= console

TARGET = createVersionsXml
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS +=

#DESTDIR = ../
win32 {
QMAKE_POST_LINK = $$OUT_PWD/release/createVersionsXml
}
