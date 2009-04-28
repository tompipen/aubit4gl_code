ROOT                    =../..
################
#All stuff common to more then one Aubit compiler make file is there:
include                 ${ROOT}/incl/Makefile-common

PICKDIR         = ${ROOT}/lib/extra_libs/pick
OBJS_PICK       = ${PICKDIR}/pick10.afr${A4GL_OBJ_EXT}  ${PICKDIR}/pick20.afr${A4GL_OBJ_EXT} ${PICKDIR}/pick38.afr${A4GL_OBJ_EXT} ${PICKDIR}/pick78.afr${A4GL_OBJ_EXT}  ${PICKDIR}/pick${A4GL_OBJ_EXT}



#FORMS=prog.afr.dat

A4GL_OBJ_EXT=.ao

all: sqlmetrics.4ae 

sqlmetrics.4ae: sqlmetrics${A4GL_OBJ_EXT} load${A4GL_OBJ_EXT} purge${A4GL_OBJ_EXT} main${A4GL_OBJ_EXT} analyze${A4GL_OBJ_EXT} report${A4GL_OBJ_EXT}  ../asql/filehand${A4GL_OBJ_EXT} ../asql/generic_db${A4GL_OBJ_EXT} sqls.afr${A4GL_OBJ_EXT} sqlerr.afr${A4GL_OBJ_EXT} sqldeta.afr${A4GL_OBJ_EXT} ${OBJS_PICK}  splash.afr${A4GL_OBJ_EXT} purge.afr${A4GL_OBJ_EXT}
	4glpc -g -o $@ $^
	cp sqlmetrics.4ae ${ROOT}/bin



%.afr${A4GL_OBJ_EXT}:%.per
	fcompile -c $<
	4glpc -t C -c -o $@ ${subst .per,.afr.c,$<}


%.afr.dat:%.per
	fcompile  $<

%${A4GL_OBJ_EXT}: %.4gl
	4glpc -K -o $@ -g -c $<

clean:
	rm -f sqlmetrics${A4GL_OBJ_EXT} load${A4GL_OBJ_EXT} report${A4GL_OBJ_EXT} main${A4GL_OBJ_EXT} analyze${A4GL_OBJ_EXT} sqlmetrics.4ae *.afr.*  
