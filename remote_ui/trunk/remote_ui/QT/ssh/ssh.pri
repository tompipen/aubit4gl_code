INCLUDEPATH += ./ssh/
INCLUDEPATH += ./ssh/libssh/
DEPENDPATH  += ./ssh/
DEPENDPATH  += ./ssh/libssh/
DEFINES+=SSH_USE
HEADERS += vssh.h \
           sshtunnel.h
SOURCES += vssh.cpp \
           sshtunnel.cpp

