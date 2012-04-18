INCLUDEPATH += ./ssh/
INCLUDEPATH += ./ssh/libssh/
DEPENDPATH  += ./ssh/
DEPENDPATH  += ./ssh/libssh/
DEFINES+=SSH_USE
HEADERS += vssh.h
SOURCES += vssh.cpp

