ROOT=../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common


CFLAGS+=-I$(AUBITDIR)/incl -I. -Iuilib


all: libUI_XML${SO_EXT} proxy

libUI_XML${SO_EXT}: xml.o uilib/libuilib.a 
	${LD} ${SO_LDFLAGS}  -o $@  xml.o -Bstatic  -Luilib -luilib
	cp $@ `aubit-config DEFAULT_PLUGINDIR`

proxy: proxy.o pipe.o debug.o
	${CC} ${CFLAGS_NO_PEDANTIC} -g -o proxy proxy.o pipe.o debug.o

noproxy: noproxy.o pipe.o debug.o
	${CC} ${CFLAGS_NO_PEDANTIC} -g -o noproxy noproxy.o pipe.o debug.o

uilib/libuilib.a: 
	cd uilib && make -f Makefile.libaubit4gl libuilib.a


clean: 
	rm libUI_XML${SO_EXT} `aubit-config DEFAULT_PLUGINDIR`/libUI_XML${SO_EXT}
	cd uilib && make clean
	cd uilib/xml && make clean
