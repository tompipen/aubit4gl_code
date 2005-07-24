#	@(#)$Id: makefile,v 1.2 2002-06-14 09:23:16 afalout Exp $
#
#	Makefile for stack of help message files

INC=${INFORMIXDIR}/incl
LIB=${INFORMIXDIR}/lib

RANLIB=ranlib
FORM4GL=form4gl

OLDLIB=${LIB}/libforms.old
OLDINC=${INC}/sqlfm.old

NEWLIB=${LIB}/libforms.a
NEWINC=${INC}/sqlfm.h

TAIL=sqlfm.tail
SRC=nextfld.ec popstr.c
OBJ=nextfld.o popstr.o
MAN=nextfld.man
MKFILE=makefile
SHAR=nextfld.sa
TSTPRG=nxfchk.4ge
TSTFRM=nxfchk.frm
TSTSRC=nxfchk.4gl nxfchk.per

ESQL=esql

.SUFFIXES: .ec

.ec.o:
	$(ESQL) -c $<
	rm -f $*.c

null:
	@echo "Run make install first, then make test"
	@echo "If it doesn't work, run make uninstall"

test:	${TSTPRG} ${TSTFRM}

${TSTPRG}:	${TSTPRG:.4ge=.4gl}
	c4gl -o $@ $?
	rm -f ${@:.4ge=.c} ${@:.4ge=.ec}

${TSTFRM}:	${TSTFRM:.frm=.per}
	$(FORM4GL) ${@:.frm=}

install:	${SRC} ${OBJ} ${TAIL}
	if [ ! -f ${OLDLIB} ] ; then \
		mv ${NEWLIB} ${OLDLIB} ; \
		cp ${OLDLIB} ${NEWLIB} ; \
	fi
	if [ ! -f ${OLDINC} ] ; then \
		mv ${NEWINC} ${OLDINC} ; \
		cp ${OLDINC} ${NEWINC} ; \
	fi
	ar ruv ${NEWLIB} ${OBJ}
	${RANLIB} ${NEWLIB}
	chmod +w ${NEWINC}
	cat ${TAIL} >>${NEWINC}
	chmod -w ${NEWINC}

uninstall:	${OLDINC} ${OLDLIB}
	mv ${OLDLIB} ${NEWLIB}
	mv ${OLDINC} ${NEWINC}

cleanup:
	rm -f ${SRC} ${OBJ} ${TAIL} ${MAN} ${MKFILE}
	rm -f ${TSTSRC} ${TSTPRG} ${TSTFRM}
	rm -f ${TSTPRG:.4ge=.4gl} ${TSTPRG:.4ge=.o} ${TSTPRG:.4ge=.c}
	rm -f ${TSTPRG:.4ge=.ec} ${SHAR}

shar:	${SRC} ${TAIL} ${MAN} ${MKFILE} ${TSTSRC}
	shar ${SRC} ${TAIL} ${MAN} ${MKFILE} ${TSTSRC} >${SHAR}

.DEFAULT:	SCCS/s.$$@
	$(GET) $(GFLAGS) SCCS/s.$@
