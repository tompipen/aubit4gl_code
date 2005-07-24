#	@(#)$Id: makefile,v 1.2 2002-06-14 09:23:16 afalout Exp $
#
#	Makefile for stack of help message files

INC=${INFORMIXDIR}/incl
LIB=${INFORMIXDIR}/lib

RANLIB=ranlib
MKMESSAGE=mkmessage

OLDLIB=${LIB}/libforms.old
OLDINC=${INC}/sqlfm.old

NEWLIB=${LIB}/libforms.a
NEWINC=${INC}/sqlfm.h

TAIL=sqlfm.tail
SRC=pushhelp.c
OBJ=pushhelp.o
MAN=pushhelp.man
MKFILE=makefile
SHAR=pushhelp.sa
TSTPRG=phlpchk.4ge
TSTMSG=phlpchk1.iem phlpchk2.iem
TSTSRC=${TSTPRG:.4ge=.4gl} ${TSTMSG:.iem=.msg}

null:
	@echo "Run make install first, then make test"
	@echo "If it doesn't work, run make uninstall"

test:	${TSTPRG} ${TSTMSG}

${TSTPRG}:	${TSTPRG:.4ge=.4gl}
	c4gl -o $@ $?
	rm -f ${@:.4ge=.c} ${@:.4ge=.ec}

${TSTMSG}:	${TSTMSG:.iem=.msg}
	$(MKMESSAGE) ${@:.iem=.msg} $@

install:	${SRC} ${OBJ} ${TAIL}
	if [ ! -f ${OLDLIB} ] ; then \
		mv ${NEWLIB} ${OLDLIB} ; \
		cp ${OLDLIB} ${NEWLIB} ; \
	fi
	if [ ! -f ${OLDINC} ] ; then \
		mv ${NEWINC} ${OLDINC} ; \
		cp ${OLDINC} ${NEWINC} ; \
	fi
	ar ruv ${NEWLIB} pushhelp.o
	${RANLIB} ${NEWLIB}
	chmod +w ${NEWINC}
	if grep -s EF_V_HELP ${NEWINC} >/dev/null ; then : OK ; \
	else cat ${TAIL} >>${NEWINC} ; fi
	chmod -w ${NEWINC}

uninstall:	${OLDINC} ${OLDLIB}
	mv ${OLDLIB} ${NEWLIB}
	mv ${OLDINC} ${NEWINC}

cleanup:
	rm -f ${SRC} ${OBJ} ${TAIL} ${MAN} ${MKFILE}
	rm -f ${SHAR} ${TSTSRC} ${TSTPRG} ${TSTMSG}
	rm -f ${TSTPRG:.4ge=.c} ${TSTPRG:.4ge=.o} ${TSTPRG:.4ge=.ec}

shar:	${SRC} ${TAIL} ${MAN} ${MKFILE} ${TSTSRC}
	shar ${SRC} ${TAIL} ${MAN} ${MKFILE} ${TSTSRC} >${SHAR}

.DEFAULT:	SCCS/s.$$@
	$(GET) $(GFLAGS) SCCS/s.$@
