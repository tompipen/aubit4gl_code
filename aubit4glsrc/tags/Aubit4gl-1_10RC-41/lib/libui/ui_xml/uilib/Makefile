ROOT=../../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common



NAME=`uname | tr '-' '_'`
CFLAGS=-fPIC -g -Wall  -Iaubit4gl -I$(AUBITDIR)/incl -I$(ROOT)/lib/libui/ui_xml -I$(ROOT)/lib/libui/ui_xml/uilib
HASFLEXML:=$(shell type flexml 2> /dev/null)

ifeq "$(HASFLEXML)" ""
	TRIGGERS_O=xml/pregenerated/triggers.o xml/pregenerated/triggers_act.o
	CFLAGS+=-Ixml/pregenerated -Ixml 
else
	TRIGGERS_O=xml/triggers.o xml/triggers_act.o
endif

all: libuilib.a 
#uirunner uirunner_s
clean:
	rm -f libuilib.so libuilib.a comms.o uilib.o xml/attr.o xml/triggers.o xml/triggers_act.o ../pipe.o ../debug.o uirunner uirunner_s


libuilib${SO_EXT}: comms.o uilib.o xml/attr.o $(TRIGGERS_O) ../pipe.o ../debug.o
	 ${LD} ${SO_LDFLAGS} -o libuilib${SO_EXT} $^

libuilib.a: comms.o uilib.o xml/attr.o $(TRIGGERS_O) ../pipe.o ../debug.o
	ar rc $@ $^
	ranlib $@
	

xml/triggers_act.c: xml/triggers_act.act xml/triggers.dtd
	cd xml  && make

xml/triggers.c: xml/triggers_act.act
	cd xml  && make

uirunner: link.c
	cfglgo -DINFX link.c infx.c -I$(HOME)/proxy/uilib -L. -luilib -o uirunner

uirunner_s: link.c
	cfglgo -DINFX link.c infx.c -I$(HOME)/proxy/uilib -L. libuilib.a -o uirunner_s

uilib.o: uilib.h
