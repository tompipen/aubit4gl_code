INCLUDEPATH += ./ssh/
INCLUDEPATH += ./ssh/libssh/
DEPENDPATH  += ./ssh/
DEPENDPATH  += ./ssh/libssh/
DEFINES+=SSH_USE
HEADERS += vssh.h \
    ssh/sshtunnel.h
SOURCES += vssh.cpp \
    ssh/sshtunnel.cpp

