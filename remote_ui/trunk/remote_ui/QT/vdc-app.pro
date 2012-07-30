# #####################################################################
# Automatically generated by qmake (2.01a) Mi Jun 25 20:30:56 2008
# #####################################################################

TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

unix:!macx {
QMAKE_LFLAGS += -Wl,--rpath="$$_PRO_FILE_PWD_/lib"
}
TARGET = VDC
QT += network
QT += xml
QT += webkit
QT += svg
win32 {
  LIBS += -lwsock32
}

VREPGEN_PATH = $$(VREPGEN)
SSH_PATH     = $$(VSSH)

!isEmpty(SSH_PATH) {
message("Compile with libssh")
DEFINES += SSH_USE
LIBS += -lssh
include("ssh/ssh.pri")
}

!isEmpty(VREPGEN_PATH) {
message("VREPGEN erkannt")
DEFINES += VREPGEN_USE
INCLUDEPATH += ./quazip/
LIBS += -L"$$_PRO_FILE_PWD_/lib" -lquazip
LIBS += -L"$$OUT_PWD/lib" -lquazip
LIBS += -L"$$OUT_PWD/quazip/lib" -lquazip

include("models/reportgen.pri")
}

#VKDCHART = /usr/local/KDAB/KDChart-2.4.3

!isEmpty(VKDCHART) {
include("models/chart.pri")
DEFINES += KDChart_Version
message( $$VKDCHART )

CONFIG(debug, debug|release) {
  INCLUDEPATH += $$VKDCHART/include/
message( $$INCLUDEPATH )
  !win32:LIBS += -L$$VKDCHART/lib/ -lkdchart
  win32:LIBS += -L$$VKDCHART/lib/ -lkdchartd
} else {
  INCLUDEPATH += $$VKDCHART/include/
  LIBS += -L$$VKDCHART/lib/ -lkdchart
}
}

macx {
  ICON = pics/vdc.icns
  QMAKE_POST_LINK = DYLD_LIBRARY_PATH=$$OUT_PWD/lib $$PWD/libsintobundle $$OUT_PWD/VDC.app
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
    fieldparsers/xmlparser.h \
    xmlparsers/xml2menu.h \
    xmlparsers/xml2style.h \
    qtelnet/qttelnet.h \
    models/xmlreader.h \
    include/vdc.h \
    models/webbrowser.h \
    ventasupdate.h \
    models/progress.h
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
    fieldparsers/xmlparser.cpp \
    xmlparsers/xml2menu.cpp \
    xmlparsers/xml2style.cpp \
    models/ringmenu.cpp \
    qtelnet/qttelnet.cpp \
    models/xmlreader.cpp \
    include/vdc.cpp \
    models/webbrowser.cpp \
    ventasupdate.cpp \
    models/progress.cpp

OTHER_FILES += versions.xml
OTHER_FILES += appicon.rc

RC_FILE = appicon.rc

RESOURCES += \
    ressource.qrc
