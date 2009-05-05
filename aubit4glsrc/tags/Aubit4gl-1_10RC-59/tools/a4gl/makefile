ROOT                    =../..
################
#All stuff common to more then one Aubit compiler make file is there:
include                 ${ROOT}/incl/Makefile-common

PICKDIR         = ${ROOT}/lib/extra_libs/pick
OBJS_PICK       = ${PICKDIR}/pick10.afr${A4GL_OBJ_EXT}  ${PICKDIR}/pick20.afr${A4GL_OBJ_EXT} ${PICKDIR}/pick38.afr${A4GL_OBJ_EXT} ${PICKDIR}/pick78.afr${A4GL_OBJ_EXT}  ${PICKDIR}/pick${A4GL_OBJ_EXT}



#FORMS=prog.afr.dat

A4GL_OBJ_EXT=.ao

all: $(ROOT)/bin/a4gl.4ae 

$(ROOT)/bin/a4gl.4ae: a4gl${A4GL_OBJ_EXT} form${A4GL_OBJ_EXT} main${A4GL_OBJ_EXT} module${A4GL_OBJ_EXT} program${A4GL_OBJ_EXT}  ../asql/filehand${A4GL_OBJ_EXT} ../asql/generic_db${A4GL_OBJ_EXT} subrouts${A4GL_OBJ_EXT} times${A4GL_OBJ_EXT} prog.afr${A4GL_OBJ_EXT} settings.afr${A4GL_OBJ_EXT} entities.afr${A4GL_OBJ_EXT} warn.afr${A4GL_OBJ_EXT} ${OBJS_PICK}  splash.afr${A4GL_OBJ_EXT}
	4glpc -g -o $@ $^



%.afr${A4GL_OBJ_EXT}:%.per
	fcompile -c $<
	4glpc -t C -c -o $@ ${subst .per,.afr.c,$<}


%.afr.dat:%.per
	fcompile  $<

%${A4GL_OBJ_EXT}: %.4gl
	4glpc -o $@ -g -c $<

clean:
	rm -f a4gl${A4GL_OBJ_EXT} filehand${A4GL_OBJ_EXT} form${A4GL_OBJ_EXT} generic_db${A4GL_OBJ_EXT} main${A4GL_OBJ_EXT} module${A4GL_OBJ_EXT} pick${A4GL_OBJ_EXT} program${A4GL_OBJ_EXT} subrouts${A4GL_OBJ_EXT}  times${A4GL_OBJ_EXT} a4gl.4ae *.afr.*  ../asql/pick${A4GL_OBJ_EXT}  ../asql/filehand${A4GL_OBJ_EXT} ../asql/generic_db${A4GL_OBJ_EXT} warn.afr${A4GL_OBJ_EXT}
