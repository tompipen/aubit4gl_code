ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common
CFLAGS+=-I$(ROOT)/incl -I..


LINKLIBS        =-L${LIBROOT} -l${AUBITLIBFULL}

ifneq "${COMSPEC}" ""
	SOLINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
endif

ALL=${PLUGINDIR}/libSQL_IDXFILESCHEMA2${SO_EXT} $(ROOT)/bin/index_fileschema2



all: $(ALL)


index_fileschema.o: fileschema.h index_fileschema.c
read_fileschema.o: fileschema.h read_fileschema.c 

$(ROOT)/bin/index_fileschema2: index_fileschema.o  io.o 
	$(CC) $(CFLAGS) -o $(ROOT)/bin/index_fileschema2 index_fileschema.c io.o $(LINKLIBS)

dll:${PLUGINDIR}/libSQL_IDXFILESCHEMA2${SO_EXT}
${PLUGINDIR}/libSQL_IDXFILESCHEMA2${SO_EXT}: read_fileschema.o io.o 
	${LD} ${SO_LDFLAGS} $^ -o $@  ${SOLINKLIBS}


clean:
	rm -f index_fileschema fileschema.x.h fileschema.xs.h ${PLUGINDIR}/libSQL_IDXFILESCHEMA${SO_EXT} *.o *${SO_EXT} *.bak *.base *.dll *.def *.exp *.a fileschema.xi.c fileschema.xio.c fileschema.xo.c  $(ROOT)/bin/index_fileschema
#-------------------------------- EOF -------------------------------
