#	@(#)$Id: makefile,v 1.2 2002-06-14 09:23:16 afalout Exp $
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
	${C4GL} -o $@ ${TEST.o} ${FILES.o}

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
