#	@(#)$Id: makefile,v 1.2 2002-06-14 09:23:16 afalout Exp $
#
#	Makefile for Informix-4GL Tools Library Directory -- D-lists

.AUGMENTED_MAKE:
.FORCE:
.PRECIOUS:	${LIBDLIST}

LIBTEST  = ./libdlist.a

LIBDLIST = ${JOHN_HOME}/lib/libdlist.a
LIBI4GL  = ${JOHN_HOME}/lib/libgeneral.a
LIBJL    = ${JOHN_HOME}/lib/libjl.a
LIBS     = ${LIBDLIST} ${LIBI4GL} ${LIBJL}
DEBUG    = -DPARANOID -I${HOME}/inc 
DEBUG    =
CFLAGS   = -O -I${INFORMIXDIR}/incl ${DEBUG}
STRIP    = -s
LDFLAGS  = ${STRIP} ${LIBS}
RANLIB   = ranlib

all:	${LIBDLIST}

lib:	${LIBDLIST}

SOURCES = \
	dlist.c \
	dlistint.c

${LIBDLIST}:\
		${LIBDLIST}(dlist.o) \
		${LIBDLIST}(dlistint.o)
	${RANLIB} ${LIBDLIST}

dlist.o    ${LIBDLIST}(dlist.o):	dlist.h
dlistint.o ${LIBDLIST}(dlistint.o):	dlist.h

.PRECIOUS:	${LIBTEST}

${SOURCES}:	SCCS/s.$$@
	${GET} ${GFLAGS} SCCS/s.$@

test:	${LIBTEST}	dltest	dlisti

${LIBTEST}:\
		${LIBTEST}(dlist.o) \
		${LIBTEST}(dlistint.o)
	${RANLIB} ${LIBTEST}

${LIBTEST}(dlist.o):	dlist.h
${LIBTEST}(dlistint.o):	dlist.h

DLTEST.o = \
	dltest.o \
	malloc.o \
	stderr.o

dltest:	${LIBTEST} ${DLTEST.o}
	${CC} ${CFLAGS} -o $@ ${DLTEST.o} ${LDFLAGS}

dlisti:	${LIBTEST} dlisti.o
	${C4GL} ${CFLAGS} -o $@ $@.o ${LDFLAGS}

TESTSRC =	dltest.c	dlisti.4gl

shar:	dlist.h ${SOURCES} ${TESTSRC} makefile
	shar dlist.h ${SOURCES} ${TESTSRC} makefile >dlist.sa

cleanup:
	rm -f dlist.h ${SOURCES} ${TESTSRC} makefile
	rm -f ${SOURCES:.c=.o} dlisti.c dlisti.ec
	rm -f dltest dlisti ${LIBTEST} dltest.o dlisti.o dlist.sa
