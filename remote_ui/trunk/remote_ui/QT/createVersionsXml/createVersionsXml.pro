#-------------------------------------------------
#
# Project created by QtCreator 2012-05-25T20:28:44
#
#-------------------------------------------------

QT       += core

QT       -= console

TARGET = create

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += mainCreate.cpp

HEADERS +=

win32 {
CONFIG(debug) {
QMAKE_POST_LINK = $$OUT_PWD/debug/create
}
CONFIG(release) {
QMAKE_POST_LINK = $$OUT_PWD/release/create
}
}
unix {
QMAKE_POST_LINK = $$OUT_PWD/create
}
