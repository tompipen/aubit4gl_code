#	@@(#)$Id: makefile,v 1.1 2002-06-14 05:03:45 afalout Exp $
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

${SOURCES}:	SCCS/s.$$@@
	${GET} ${GFLAGS} SCCS/s.$@@

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
	${CC} ${CFLAGS} -o $@@ $@@.o ${LDFLAGS}

dlisti:	${LIBTEST} dlisti.o
	${C4GL} -o $@@ $@@.o ${LDFLAGS}

TESTSRC=	dltest.c	dlisti.4gl

shar:	dlist.h ${SOURCES} ${TESTSRC} makefile
	shar dlist.h ${SOURCES} ${TESTSRC} makefile >dlist.sa

cleanup:
	rm -f dlist.h ${SOURCES} ${TESTSRC} makefile
	rm -f ${SOURCES:.c=.o} dlisti.c dlisti.ec
	rm -f dltest dlisti ${LIBTEST} dltest.o dlisti.o dlist.sa

####################################################################
#           remains of stripping from RCS format:
####################################################################

@


3.7
log
@Give RMK a complete specification of the dependencies
@
text
@d6 1
a6 1
#	Remove dupleicate .DEFAULT rule
d9 2
a10 1
include ${JOHN_HOME}/data/mk.4gl
d51 1
a51 1
	${GET} SCCS/s.$@@
@


3.6
log
@Change (clean up) for RMK -- minimal changes
@
text
@d38 5
a42 5
${LIBDLIST}(dlist.o):		dlist.h
${LIBDLIST}(dlistdbl.o):	dlist.h
${LIBDLIST}(dliststr.o):	dlist.h
${LIBDLIST}(dlistdec.o):	dlist.h
${LIBDLIST}(dlistint.o):	dlist.h
@


3.5
log
@RMK doesn't get dlist.h in time
*** CHANGED *** 89/06/28 18:59:03 john
Make cleanup more stringent
@
text
@d4 4
d11 1
a11 1
.force_build:
a18 3
.DEFAULT:
	${GET} SCCS/s.$@@

a30 1
		${SOURCES}\
d49 1
a49 1
.DEFAULT:
a54 1
		${SOURCES}\
@


3.4
log
@Add dlist.h in shar
@
text
@d16 1
a16 1
	$(GET) SCCS/s.$@@
d45 1
a45 1
LDFLAGS=$(LIBTEST)
d50 1
a50 1
	$(GET) SCCS/s.$@@
d70 1
a70 1
	$(CC) $(CFLAGS) -o $@@ $@@.o ${LDFLAGS}
d77 2
a78 2
shar:	dlist.h ${SOURCES} $(TESTSRC) makefile
	shar dlist.h $(SOURCES) $(TESTSRC) makefile >dlist.sa
d81 3
a83 1
	rm -f dltest dlisti ${LIBTEST} dltest.o dlisti.o
@


3.3
log
@Combine with test.mk; add shar and cleanup
@
text
@d77 2
a78 2
shar:	${SOURCES}	$(TESTSRC) makefile
	shar $(SOURCES) $(TESTSRC) makefile >dlist.sa
@


3.2
log
@Include test
@
text
@d7 2
d10 1
a10 2
LIBGEN=${JOHN_HOME}/lib/libgeneral.a
LDFLAGS=$(LIBGEN) -s
d13 1
a13 1
.PRECIOUS:	${LIBGEN}
d18 1
a18 1
all:	${LIBGEN}
d20 1
a20 1
lib:	${LIBGEN}
d29 26
a54 1
${LIBGEN}:\
d56 20
a75 12
		${LIBGEN}(dlist.o)\
		${LIBGEN}(dlistdbl.o)\
		${LIBGEN}(dliststr.o)\
		${LIBGEN}(dlistdec.o)\
		${LIBGEN}(dlistint.o)
	${RANLIB} ${LIBGEN}

${LIBGEN}(dlist.o):		dlist.h
${LIBGEN}(dlistdbl.o):	dlist.h
${LIBGEN}(dliststr.o):	dlist.h
${LIBGEN}(dlistdec.o):	dlist.h
${LIBGEN}(dlistint.o):	dlist.h
d77 2
a78 2
test:	.force_build
	$(MAKE) -f test.mk
d80 2
a81 1
.force_build:
@


3.1
log
@Initial revision
@
text
@d42 5
@
