INCLUDEPATH += ./ssh/
INCLUDEPATH += ./ssh/libssh/
DEPENDPATH  += ./ssh/
DEPENDPATH  += ./ssh/libssh/
DEFINES+=SSH_USE
HEADERS += ssh/vssh.h \
           ssh/sshtunnel.h
SOURCES += ssh/vssh.cpp \
           ssh/sshtunnel.cpp

