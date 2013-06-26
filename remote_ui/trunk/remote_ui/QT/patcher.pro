TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

TARGET = update
QT += network
QT += xml
QT -= webkit

DEFINES += VREPGEN_USE
INCLUDEPATH += ./quazip/
LIBS += -L"$$_PRO_FILE_PWD_/lib" -lquazip
LIBS += -L"$$OUT_PWD/lib" -lquazip
LIBS += -L"$$OUT_PWD/quazip/lib" -lquazip

macx {
  QMAKE_POST_LINK = DYLD_LIBRARY_PATH=$$OUT_PWD/lib $$PWD/libsintobundle $$OUT_PWD/update.app
}

HEADERS += \
    patcher.h \
    include/vdc.h \
    models/zipunzip.h

SOURCES += \
    patcher.cpp \
    include/vdc.cpp \
    models/zipunzip.cpp
