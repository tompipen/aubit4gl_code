#	@@(#)$Id: makefile,v 1.1 2002-06-14 05:03:45 afalout Exp $
#
#	Makefile for adjustable input array dimensions

.SUFFIXES: .ec
ESQL=esql

.ec.o:
	${ESQL} -c ${CFLAGS} $<
	rm -f $*.c

INC=${INFORMIXDIR}/incl
LIB=${INFORMIXDIR}/lib

RANLIB=ranlib

OLDLIB=${LIB}/libforms.old
OLDINC=${INC}/sqlfm.old

NEWLIB=${LIB}/libforms.a
NEWINC=${INC}/sqlfm.h

TAIL=sqlfm.tail
SRC=adjinarr.ec
OBJ=adjinarr.o
MAN=adjinarr.man
MKFILE=makefile
SHAR=adjinarr.sa
TSTPRG=adjchk.4ge
TSTFRM=adjchk.frm
TSTSRC=adjchk.4gl adjchk.per

null:
	@@echo "Run make install first, then make test"
	@@echo "If it doesn't work, run make uninstall"

test:	${TSTPRG} ${TSTFRM}

${TSTPRG}:	${TSTPRG:.4ge=.4gl}
	c4gl -o $@@ $?
	rm -f ${@@:.4ge=.c} ${@@:.4ge=.ec}

${TSTFRM}:	${TSTFRM:.frm=.per}
	form4gl ${@@:.frm=}

install:	${SRC} ${OBJ} ${TAIL}
	if [ ! -f ${OLDLIB} ] ; then \
		mv ${NEWLIB} ${OLDLIB} ; \
		cp ${OLDLIB} ${NEWLIB} ; \
	fi
	if [ ! -f ${OLDINC} ] ; then \
		mv ${NEWINC} ${OLDINC} ; \
		cp ${OLDINC} ${NEWINC} ; \
	fi
	ar ruv ${NEWLIB} adjinarr.o
	${RANLIB} ${NEWLIB}
	chmod +w ${NEWINC}
	if grep -s FAR_V_INPUT ${NEWINC} >/dev/null ; then : OK ; \
	else cat ${TAIL} >>${NEWINC} ; fi
	chmod -w ${NEWINC}

uninstall:	${OLDINC} ${OLDLIB}
	mv ${OLDLIB} ${NEWLIB}
	mv ${OLDINC} ${NEWINC}

cleanup:
	rm -f ${SRC} ${OBJ} ${TAIL} ${MAN} ${MKFILE}
	rm -f ${TSTSRC} ${TSTFRM}
	rm -f ${TSTPRG} ${TSTPRG:.4ge=.o} ${TSTPRG:.4ge=.ec} ${TSTPRG:.4ge=.c} 
	rm -f ${SHAR}

shar:	${SRC} ${TAIL} ${MAN} ${MKFILE} ${TSTSRC}
	shar ${SRC} ${TAIL} ${MAN} ${MKFILE} ${TSTSRC} >${SHAR}

.DEFAULT:	SCCS/s.$$@@
	$(GET) $(GFLAGS) SCCS/s.$@@

shar:	${SRC} ${TAIL} ${MAN} ${MKFILE}
	shar ${SRC} ${TAIL} ${MAN} ${MKFILE} >${SHAR}
	
	if [ -f ${OLDLIB} ] ; then echo "${OLDLIB} already exists" ; exit 1 ; fi
	if [ -f ${OLDINC} ] ; then echo "${OLDINC} already exists" ; exit 1 ; fi
	mv ${NEWLIB} ${OLDLIB}
	cp ${OLDLIB} ${NEWLIB}
	ar qv ${NEWLIB} adjinarr.o



	mv ${NEWINC} ${OLDINC}
	cp ${OLDINC} ${NEWINC}
	
	cat ${TAIL} >>${NEWINC}


RANLIB=: ranlib
	
	$(GET) $(GFLAGS) SCCS/s.$$@@

