
include $(AUBITDIR)/incl/Makefile-common
CLIENT_CFLAGS       :=$(shell xmlrpc-c-config libwww-client --cflags)
CLIENT_LIBS         :=$(shell xmlrpc-c-config libwww-client --ldadd)
prefix=$(AUBITDIR)/lib
CFLAGS              :=-I.. -I${LIBROOT}/libincl ${CLIENT_CFLAGS} ${CFLAGS}

OBJS_RPC= barcodelookup.o


all: barcodelookup${SO_EXT} testbarcode

barcodelookup${SO_EXT}: ${OBJS_RPC}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${CLIENT_LIBS} ${LINKLIBS}
	cp $@ $(AUBITDIR)

testbarcode: testbarcode.4gl
	4glpc -o testbarcode  testbarcode.4gl

clean:
	rm -f barcodelookup.o barcodelookup.so
