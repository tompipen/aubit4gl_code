# Notes :
#
# You must make with A4GL_LEXTYPE=EC for now...
#
# Currently Informix only
#
#
# Set A4GL_UPSCOL_VAL, A4GL_UPSCOL_ATT to point to
# different tablenames if required
# (Tables will be created if they don't exist)
#
# You must have pick.ao in the asql directory first (compile asql before this one..)
#

ROOT=../..

include ${ROOT}/incl/Makefile-common

A4GL_LEXTYPE=EC
#INFORMIXC=gcc
export A4GL_LEXTYPE 
#export INFORMIXC

4GLC=${SH} ${ROOT}/bin/4glpc -verbose


${ROOT}/bin/aupscol: main.o upscol.o infx.o ../asql/ifx_pick.ao val.o att.o
	${4GLC} $^ -o $@

att.o: att.4gl
	${4GLC} -g -c $^ -o $@

main.o: main.4gl
	${4GLC} -g -c $^ -o $@

val.o: val.4gl
	${4GLC}  -g -c $^ -o $@

infx.o: infx.4gl
	${4GLC} -g -c $^ -o $@

upscol.o: upscol.4gl
	${4GLC} -g -c $^ -o $@

../asql/ifx_pick.ao:
	${MAKE} -C ../asql
	
clean:
	${RM} *.o *.ao *.bak *.h *.glb *.c *.ec *~ *.err aupscol ${ROOT}/bin/aupscol
	
	
