ROOT=../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common


CFLAGS+=-I$(ROOT)/incl -I. -Iuilib


all: ${PLUGINDIR}/libUI_XML${SO_EXT} proxy

${PLUGINDIR}/libUI_XML${SO_EXT}: xml.o uilib/libuilib.a  $(ROOT)/lib/libpacker/formxml/formxml.o
	${LD} ${SO_LDFLAGS}  -o $@  xml.o $(ROOT)/lib/libpacker/formxml/formxml.o -Bstatic  -Luilib -luilib

proxy: proxy.o pipe.o debug.o
	${CC} ${CFLAGS_NO_PEDANTIC} -g -o proxy proxy.o pipe.o debug.o

noproxy: noproxy.o pipe.o debug.o
	${CC} ${CFLAGS_NO_PEDANTIC} -g -o noproxy noproxy.o pipe.o debug.o

uilib/libuilib.a: 
	cd uilib && make -f Makefile libuilib.a


clean: 
	rm -f ${PLUGINDIR}/libUI_XML${SO_EXT} `aubit-config DEFAULT_PLUGINDIR`/libUI_XML${SO_EXT} libUI_XML${SO_EXT} debug.o pipe.o proxy.o
	cd uilib && make clean 
	cd uilib/xml && make clean
