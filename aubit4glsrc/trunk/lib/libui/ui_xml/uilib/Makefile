
NAME=`uname | tr '-' '_'`
CFLAGS=-fPIC -g -Wall  -Iaubit4gl

all: libuilib.so libuilib.a uirunner uirunner_s
clean:
	rm libuilib.so libuilib.a comms.o uilib.o xml/attr.o xml/triggers.o xml/triggers_act.o ../pipe.o ../debug.o uirunner uirunner_s


libuilib.so: comms.o uilib.o xml/attr.o xml/triggers.o xml/triggers_act.o ../pipe.o ../debug.o
	gcc -fPIC -g -shared -o libuilib.so $^
	#cp libuilib.so $(AUBITDIR)/lib

libuilib.a: comms.o uilib.o xml/attr.o xml/triggers.o xml/triggers_act.o ../pipe.o ../debug.o
	ar rc $@ $^
	ranlib $@
	
xml/triggers_act.c: xml/triggers_act.act xml/triggers.dtd

xml/triggers.c: xml/triggers_act.act
	cd xml && make

uirunner: link.c
	cfglgo -DINFX link.c infx.c -I$(HOME)/proxy/uilib -L. -luilib -o uirunner

uirunner_s: link.c
	cfglgo -DINFX link.c infx.c -I$(HOME)/proxy/uilib -L. libuilib.a -o uirunner_s

uilib.o: uilib.h
