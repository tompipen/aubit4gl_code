
ROOT    =../../..
include ${ROOT}/incl/Makefile-common
4GLC    	=${ROOT}/bin/4glc
4GLC_SET	=export A4GL_OBJ_EXT=.o; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C;
4GLC_FLAGS	=--verbose
4GLC_CFLAGS	+= -I. ${GLIB_CFLAGS}

LINKLIBS	=-l${AUBITLIBFULL}  ${GLIB_LFLAGS}
LFLAGS		= -L${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:

OUTPUT=$(PLUGINDIR)/liberrhook_sample${SO_EXT}
$(OUTPUT): sample.o
	${LD} ${SO_LDFLAGS} ${CFLAGS} -o $@ $^ ${LFLAGS} ${LINKLIBS} 

sample.c: sample.4gl
	${4GLC_SET} ${4GLC} sample.4gl

clean: 
	rm -f *.o $(OUTPUT) sample.c
	



