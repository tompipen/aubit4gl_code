head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	91.11.17.23.07.52;	author jl;	state Exp;
branches;
next	1.1;

1.1
date	91.11.17.16.35.07;	author jl;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Upgrade to put mon???.o into $HOME/lib/libgeneral.a
@
text
@#	@@(#)$Id: makefile,v 1.1 2002-06-14 05:03:46 afalout Exp $
#
#	Makefile for: Test program for LOCALE table (Informix)
#	RMK only

FILES.o = \
	mon4gl.o \
	monfmt.o \
	monset.o

TEST.o = \
	montst.o \
	memmove.o \
	popstr.o

LIBGEN.a = ${JOHN_HOME}/lib/libgeneral.a

all:	locale.frm \
		${LIBGEN.a}

${LIBGEN.a}:	${LIBGEN.a}(${FILES.o})

test:	montst

montst:	${TEST.o} ${FILES.o}
	${C4GL} -o $@@ ${TEST.o} ${FILES.o}

monfmt.o:	monfmt.h
monset.o:	monfmt.h

SOURCE = \
	locale.per \
	locale.sql \
	locale.unl \
	makefile \
	mon4gl.c \
	mondmp.c \
	monfmt.c \
	monfmt.h \
	monset.ec \
	monset.h \
	montst.4gl

source: ${SOURCE}

mon4gl.o:	monfmt.h
mondmp.o:	monfmt.h
monfmt.o:	monfmt.h
monset.o:	monfmt.h
@


1.1
log
@Initial revision
@
text
@d4 1
a5 5
C4GL = c4gl
ESQL = esql
FBLD = sformbld

# Include memmove only if necessary
a6 1
	memmove.o \
a7 1
	mondmp.o \
d9 3
a11 1
	monset.o \
d13 1
d16 1
a16 1
LIBS = ${HOME}/lib/libgeneral.a ${HOME}/lib/libjl.a 
d19 3
a21 1
		montst
d23 4
a26 2
montst:	${FILES.o}
	${C4GL} -o $@@ ${FILES.o} ${LIBS}
d46 4
a49 8
.SUFFIXES: .4gl .ec .per .frm

.4gl.o:
	${C4GL} -c $<
.ec.o:
	${ESQL} -c $<
.per.frm:
	${FBLD} $<
@
