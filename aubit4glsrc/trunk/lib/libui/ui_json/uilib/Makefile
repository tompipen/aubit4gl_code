ROOT=../../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common



NAME=`uname | tr '-' '_'`
CFLAGS+=-I$(ROOT)/lib/libui/ui_xml -I$(ROOT)/lib/libui/ui_xml/uilib -I$(ROOT)/lib/libui/ui_xml/uilib/aubit4gl -Wall -I../json/libjson/libjson-0.8 

USE_AR=${AR}
USE_RANLIB=ranlib

ifeq "${TARGET_OS}" "AIX"
	USE_AR=ar -X 64 rc 
	USE_RANLIB=ranlib -X 64
endif

all: libuilib.a 
# testjson
#uirunner uirunner_s
clean:
	rm -f libuilib.so libuilib.a comms.o uilib.o  ../pipe.o ../debug.o uirunner uirunner_s


libuilib${SO_EXT}: comms.o uilib.o attr.o $(TRIGGERS_O) ../pipe.o ../debug.o
	 ${LD} ${SO_LDFLAGS} -o libuilib${SO_EXT} $^

deps: 
	echo comms.o uilib.o attr.o $(TRIGGERS_O) ../pipe.o ../debug.o

libuilib.a: comms.o uilib.o attr.o $(TRIGGERS_O) ../pipe.o ../debug.o jsonlib.o
	${USE_AR} $@ $^
	${USE_RANLIB} $@
	


uirunner: link.c
	cfglgo -DINFX link.c infx.c -I$(HOME)/proxy/uilib -L. -luilib -o uirunner

uirunner_s: link.c
	cfglgo -DINFX link.c infx.c -I$(HOME)/proxy/uilib -L. libuilib.a -o uirunner_s

uilib.o: uilib.h


testjson: jsonlib.c
	 gcc -DTEST  -g  -I../json/libjson/libjson-0.8 jsonlib.c -o testjson -L../json/libjson/libjson-0.8 -ljson
