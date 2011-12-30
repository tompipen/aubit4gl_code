# #####################################################################
# Automatically generated by qmake (2.01a) Mi Jun 25 20:30:56 2008
# #####################################################################

CONFIG += debug
TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += . ./quazip/
LIBS += -L"$$_PRO_FILE_PWD_/lib" -lquazip
unix {
QMAKE_LFLAGS += -Wl,--rpath="$$_PRO_FILE_PWD_/lib"
}
TARGET = VDC
QT += network
QT += xml
QT += webkit
win32 {
  LIBS += -lwsock32

}
macx {
  ICON = pics/vdc.icns
}
# Input
HEADERS += confwin.h \
    login.h \
    mainframe.h \
    clienttcp.h \
    screenhandler.h \
    include/fgl.h \
    models/fglform.h \
    models/statusbar.h \
    models/vwidgets.h \
    models/ringmenu.h \
    models/actionmenu.h \
    models/actions.h \
    models/toolbar.h \
    models/dialog.h \
    models/prompt.h \
    models/response.h \
    models/table.h \
    models/pulldown.h \
    context.h \ # fieldparsers/aubit2fields.h \
# fieldparsers/xml2fields.h \
# fieldparsers/xml2form.h \
    fieldparsers/parser.h \
    xmlparsers/xml2menu.h \
    xmlparsers/xml2style.h \
    qtelnet/qttelnet.h
SOURCES += confwin.cpp \
    main.cpp \
    mainframe.cpp \
    login.cpp \
    clienttcp.cpp \
    screenhandler.cpp \
    include/fgl.cpp \
    models/fglform.cpp \
    models/statusbar.cpp \
    models/vwidgets.cpp \
    models/actionmenu.cpp \
    models/actions.cpp \
    models/toolbar.cpp \
    models/dialog.cpp \
    models/prompt.cpp \
    models/response.cpp \
    models/table.cpp \
    models/pulldown.cpp \
    context.cpp \ # fieldparsers/aubit2fields.cpp \
# fieldparsers/xml2fields.cpp \
# fieldparsers/xml2form.cpp \
    fieldparsers/parser.cpp \
    xmlparsers/xml2menu.cpp \
    xmlparsers/xml2style.cpp \
    models/ringmenu.cpp \
    qtelnet/qttelnet.cpp

RESOURCES += \
    ressource.qrc
