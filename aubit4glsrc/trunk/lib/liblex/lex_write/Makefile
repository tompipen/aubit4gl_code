ROOT        =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common


ALL             =${PLUGINDIR}/libLEX_WRITE${SO_EXT}

all: $(ALL)
clean:
	rm ${PLUGINDIR}/libLEX_WRITE${SO_EXT}

${PLUGINDIR}/libLEX_WRITE${SO_EXT}: write.c
	 ${LD} ${SO_LDFLAGS}  -I$(ROOT)/incl -o $@ $<


