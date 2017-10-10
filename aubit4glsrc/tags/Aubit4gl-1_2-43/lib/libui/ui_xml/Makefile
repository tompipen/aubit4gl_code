ROOT=../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

ifneq "${COMSPEC}" ""
        LINKLIBS        =-lwsock32
endif

ifeq "${TARGET_OS}" "darwin"
      LINKLIBS+=-liconv
endif



CFLAGS+=-I$(ROOT)/incl -I. -I./uilib  -I./aubit4gl -Wall

ifneq "${COMSPEC}" ""
	PROXY=
else
	PROXY=proxy
endif

all: ${PLUGINDIR}/libUI_XML${SO_EXT} $(PROXY)


${PLUGINDIR}/libUI_XML${SO_EXT}: xml.o uilib/libuilib.a  $(ROOT)/lib/libpacker/formxml/formxml.o
	${LD} ${SO_LDFLAGS} ${CFLAGS} -o $@  xml.o $(ROOT)/lib/libpacker/formxml/formxml.o -Bstatic  -Luilib -luilib -L../.. -laubit4gl $(LINKLIBS)


./uilib/xml/pregenerated/triggers.o: ./uilib/xml/pregenerated/triggers.c
	${CC} -c -o $@ ${CFLAGS} -I./uilib/xml ./uilib/xml/pregenerated/triggers.c

./uilib/xml/pregenerated/triggers_act.o: ./uilib/xml/pregenerated/triggers_act.c
	${CC} -c -o $@ ${CFLAGS} -I./uilib/xml ./uilib/xml/pregenerated/triggers_act.c

proxy: proxy.o pipe.o debug.o uilib/xml/pregenerated/triggers_act.o uilib/xml/attr.c ./uilib/xml/pregenerated/triggers.o 
	${CC} ${CFLAGS} -DCOMPILING_PROXY -g -o proxy proxy.o pipe.c debug.o uilib/xml/pregenerated/triggers_act.o uilib/xml/attr.c ./uilib/xml/pregenerated/triggers.o

noproxy: noproxy.o pipe.o debug.o
	${CC} ${CFLAGS} -g -o noproxy noproxy.o pipe.o debug.o

uilib/libuilib.a: uilib/comms.c uilib/uilib.c uilib/xml/attr.c pipe.c debug.c  uilib/xml/triggers_act.act uilib/xml/triggers.dtd
	cd uilib && make -f Makefile libuilib.a


clean: 
	rm -f ${PLUGINDIR}/libUI_XML${SO_EXT} `aubit-config DEFAULT_PLUGINDIR`/libUI_XML${SO_EXT} libUI_XML${SO_EXT} debug.o pipe.o proxy.o
	cd uilib && make clean 
	cd uilib/xml && make clean
