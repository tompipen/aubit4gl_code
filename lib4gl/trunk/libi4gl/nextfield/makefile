head	1.5;
access;
symbols;
locks; strict;
comment	@# @;


1.5
date	88.12.06.10.23.36;	author john;	state Exp;
branches;
next	1.4;

1.4
date	88.09.26.10.49.25;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.09.23.16.55.05;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.09.23.16.50.11;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.09.23.16.39.46;	author john;	state Exp;
branches;
next	;


desc
@@


1.5
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
	@@echo "Run make install first, then make test"
	@@echo "If it doesn't work, run make uninstall"

test:	${TSTPRG} ${TSTFRM}

${TSTPRG}:	${TSTPRG:.4ge=.4gl}
	c4gl -o $@@ $?
	rm -f ${@@:.4ge=.c} ${@@:.4ge=.ec}

${TSTFRM}:	${TSTFRM:.frm=.per}
	$(FORM4GL) ${@@:.frm=}

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

.DEFAULT:	SCCS/s.$$@@
	$(GET) $(GFLAGS) SCCS/s.$@@
@


1.4
log
@Fix form compile line
@
text
@d69 3
@


1.3
log
@Add test code to shar distribution
@
text
@d46 1
a46 1
	$(FORM4GL) ${@@:.frm=.per} $@@
@


1.2
log
@Add popstr.o to objects; improve archiving mechanism
@
text
@d25 1
d70 2
a71 2
shar:	${SRC} ${TAIL} ${MAN} ${MKFILE}
	shar ${SRC} ${TAIL} ${MAN} ${MKFILE} >${SHAR}
@


1.1
log
@Initial revision
@
text
@d18 2
a19 2
SRC=nextfld.ec
OBJ=nextfld.o
d56 1
a56 1
	ar qv ${NEWLIB} nextfld.o
@
