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


all: ${PLUGINDIR}/libUI_JSON${SO_EXT} $(PROXY)


${PLUGINDIR}/libUI_JSON${SO_EXT}: json.o uilib/libuilib.a  $(ROOT)/lib/libpacker/formxml/formjson.o libjson.o readJsonForm.o
	${LD} ${SO_LDFLAGS} ${CFLAGS} -o $@  json.o $(ROOT)/lib/libpacker/formxml/formjson.o -Bstatic  -Luilib -luilib -L../.. -laubit4gl $(LINKLIBS) libjson.o readJsonForm.o



uilib/libuilib.a: uilib/comms.c uilib/uilib.c uilib/attr.c pipe.c debug.c uilib/jsonlib.c
	cd uilib && make -f Makefile libuilib.a


clean: 
	${RM} ${PLUGINDIR}/libUI_JSON${SO_EXT} `aubit-config DEFAULT_PLUGINDIR`/libUI_JSON${SO_EXT} *.o
	cd uilib && make clean 
