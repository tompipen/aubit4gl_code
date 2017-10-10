ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common
CFLAGS+=-I$(ROOT)/incl -I..


LINKLIBS        =-L${LIBROOT} -l${AUBITLIBFULL}

ifneq "${COMSPEC}" ""
	SOLINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
endif

ALL=${PLUGINDIR}/libSQL_IDXFILESCHEMA${SO_EXT} $(ROOT)/bin/index_fileschema



all: $(ALL)


index_fileschema.o: fileschema.x.h index_fileschema.c
read_fileschema.o: fileschema.x.h read_fileschema.c 

$(ROOT)/bin/index_fileschema: index_fileschema.o 
	$(CC) $(CFLAGS) -o $(ROOT)/bin/index_fileschema index_fileschema.c fileschema.xio.c fileschema.xo.c fileschema.xi.c $(LINKLIBS)

fileschema.x.h fileschema.xio.c fileschema.xo.c fileschema.xi.c: fileschema.x
	EXPECT_VERSION=1 xgen fileschema s_idx_tables

${PLUGINDIR}/libSQL_IDXFILESCHEMA${SO_EXT}: read_fileschema.o fileschema.xio.o fileschema.xo.o fileschema.xi.o
	${LD} ${SO_LDFLAGS} $^ -o $@  ${SOLINKLIBS}


clean:
	rm -f index_fileschema fileschema.x.h fileschema.xs.h ${PLUGINDIR}/libSQL_IDXFILESCHEMA${SO_EXT} *.o *${SO_EXT} *.bak *.base *.dll *.def *.exp *.a fileschema.xi.c fileschema.xio.c fileschema.xo.c  $(ROOT)/bin/index_fileschema
#-------------------------------- EOF -------------------------------
