head	1.4;
access;
symbols;
locks; strict;
comment	@# @;


1.4
date	88.12.06.10.29.40;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.10.07.15.18.49;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.09.09.12.35.18;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.09.09.12.31.42;	author john;	state Exp;
branches;
next	;


desc
@@


1.4
log
@Make cleanup more stringent
@
text
@#	@@(#)$Id: makefile,v 1.1 2002-06-14 05:03:46 afalout Exp $
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
	@@echo "Run make install first, then make test"
	@@echo "If it doesn't work, run make uninstall"

test:	${TSTPRG} ${TSTMSG}

${TSTPRG}:	${TSTPRG:.4ge=.4gl}
	c4gl -o $@@ $?
	rm -f ${@@:.4ge=.c} ${@@:.4ge=.ec}

${TSTMSG}:	${TSTMSG:.iem=.msg}
	$(MKMESSAGE) ${@@:.iem=.msg} $@@

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

.DEFAULT:	SCCS/s.$$@@
	$(GET) $(GFLAGS) SCCS/s.$@@
@


1.3
log
@Improve installation process
@
text
@d25 1
d62 2
d65 2
a66 2
shar:	${SRC} ${TAIL} ${MAN} ${MKFILE}
	shar ${SRC} ${TAIL} ${MAN} ${MKFILE} >${SHAR}
@


1.2
log
@Change source to .c (from .ec)
@
text
@d48 1
a48 1
	ar qv ${NEWLIB} pushhelp.o
d51 2
a52 1
	cat ${TAIL} >>${NEWINC}
@


1.1
log
@Initial revision
@
text
@d18 1
a18 1
SRC=pushhelp.ec
@
