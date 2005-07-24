#	@(#)$Id: makefile,v 1.2 2002-06-14 09:23:16 afalout Exp $
#
#	Makefile for Informix-4GL Tools Library Directory -- D-lists
#	Minimal mods for RMK 
#	Remove source and object dependencies in library definitions
#	Remove duplicate .DEFAULT rule
#	Specify .AUGMENTED_MAKE

#include ${JOHN_HOME}/data/mk.4gl
.AUGMENTED_MAKE:

.FORCE:

CFLAGS=-O -I${INFORMIXDIR}/incl
LIBDLIST=${JOHN_HOME}/lib/libgeneral.a
RANLIB=ranlib

.PRECIOUS:	${LIBDLIST}

all:	${LIBDLIST}

lib:	${LIBDLIST}

SOURCES=\
	dlist.c\
	dlistdbl.c\
	dliststr.c\
	dlistdec.c\
	dlistint.c

${LIBDLIST}:\
		${LIBDLIST}(dlist.o)\
		${LIBDLIST}(dlistdbl.o)\
		${LIBDLIST}(dliststr.o)\
		${LIBDLIST}(dlistdec.o)\
		${LIBDLIST}(dlistint.o)
	${RANLIB} ${LIBDLIST}

dlist.o    ${LIBDLIST}(dlist.o):	dlist.h
dlistdbl.o ${LIBDLIST}(dlistdbl.o):	dlist.h
dliststr.o ${LIBDLIST}(dliststr.o):	dlist.h
dlistdec.o ${LIBDLIST}(dlistdec.o):	dlist.h
dlistint.o ${LIBDLIST}(dlistint.o):	dlist.h

LIBTEST=./libdlist.a
LDFLAGS=${LIBTEST}

.PRECIOUS:	${LIBTEST}

${SOURCES}:	SCCS/s.$$@
	${GET} ${GFLAGS} SCCS/s.$@

test:	${LIBTEST}	dltest	dlisti

${LIBTEST}:\
		${LIBTEST}(dlist.o)\
		${LIBTEST}(dlistdbl.o)\
		${LIBTEST}(dliststr.o)\
		${LIBTEST}(dlistdec.o)\
		${LIBTEST}(dlistint.o)
	${RANLIB} ${LIBTEST}

${LIBTEST}(dlist.o):	dlist.h
${LIBTEST}(dlistdbl.o):	dlist.h
${LIBTEST}(dliststr.o):	dlist.h
${LIBTEST}(dlistdec.o):	dlist.h
${LIBTEST}(dlistint.o):	dlist.h

dltest:	${LIBTEST} dltest.o
	${CC} ${CFLAGS} -o $@ $@.o ${LDFLAGS}

dlisti:	${LIBTEST} dlisti.o
	${C4GL} -o $@ $@.o ${LDFLAGS}

TESTSRC=	dltest.c	dlisti.4gl

shar:	dlist.h ${SOURCES} ${TESTSRC} makefile
	shar dlist.h ${SOURCES} ${TESTSRC} makefile >dlist.sa

cleanup:
	rm -f dlist.h ${SOURCES} ${TESTSRC} makefile
	rm -f ${SOURCES:.c=.o} dlisti.c dlisti.ec
	rm -f dltest dlisti ${LIBTEST} dltest.o dlisti.o dlist.sa
