ROOT        =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common
CFLAGS+=-I$(ROOT)/compilers/4glc 

ALL             =${PLUGINDIR}/libLEX_WRITE${SO_EXT}

ifneq "${COMSPEC}" ""
	LINKDEPS    =
	LINKLIBS	+=-L${LIBROOT} -l${AUBITLIBFULL} -l4glc
endif

all: $(ALL)
clean:
	rm ${PLUGINDIR}/libLEX_WRITE${SO_EXT}

${PLUGINDIR}/libLEX_WRITE${SO_EXT}: write.o
	 ${LD} ${SO_LDFLAGS}  -I$(ROOT)/incl -I$(ROOT)/compilers/4glc -o $@ $< $(LINKLIBS)




