
include $(AUBITDIR)/incl/Makefile-common
CLIENT_CFLAGS       :=$(shell xmlrpc-c-config libwww-client --cflags)
CLIENT_LIBS         :=$(shell xmlrpc-c-config libwww-client --ldadd)
prefix=$(AUBITDIR)/lib
CFLAGS              :=-I.. -I${LIBROOT}/libincl ${CLIENT_CFLAGS} ${CFLAGS}

OBJS_RPC= barcodelookup.o


ALL=${PLUGINDIR}/libbarcode${SO_EXT} testbarcode

all:  $(ALL)


${PLUGINDIR}/libbarcode${SO_EXT}: ${OBJS_RPC}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${CLIENT_LIBS} ${LINKLIBS}
	#cp $@ $(AUBITDIR)/

testbarcode: testbarcode.4gl
	4glc -o testbarcode  testbarcode.4gl

clean:
	rm -f barcodelookup.o barcodelookup.so testbarcode ${PLUGINDIR}/libbarcode${SO_EXT}
