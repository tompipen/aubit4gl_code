#	@(#)$Id: Makefile,v 1.2 2003-09-29 15:10:38 mikeaubury Exp $
#
#	Makefile for SQLFMT Version 14 (1998-11-04)

###################################################################
# Configuration:                                                  #
# You may need to change these values                             #
# LIBC      is the shared C library on Interactive 386/IX         #
# MISSING.o is a list of library routines which are not available #
#           in your local library (or which you want to replace). #
###################################################################
RANLIB    = : ranlib
LIBC      = #-lc_s
#LIBL      = -ll
STRIP     = -s
CFLAGS    = -O #-DNO_PROTOTYPES
MISSING.o = getopt.o memmove.o # bsearch.o
BINDIR    = /usr/local/bin
MANDIR    = /usr/local/man/man1
###############################################
# End of configuration section                #
# You shouldn't need to make any more changes #
# (Famous last words, methinks! :-)           #
###############################################

AWKPROG   = awk '{ if ($$1 ~ /^\.so$$/) system("cat " $$2); else print; }'
LDFLAGS   = ${LIBL} ${LIBC} ${STRIP}
PROGRAMS  = sqlfmt fglfmt esqlfmt fglxref i4glxref
MANPAGES  = sqlfmt.1 i4glxref.1

all:	${PROGRAMS}

SQLFMT.o =  \
	sqlmain.o \
	${MISSING.o} \
	compare.o \
	dokeyword.o \
	filter.o \
	fgldata.o \
	install.o \
	sqldata.o \
	sqlfmt.o \
	stderr.o \
	strlower.o \
	strupper.o

ESQLFMT.o =  \
	esqlmain.o \
	${MISSING.o} \
	compare.o \
	dokeyword.o \
	esqldata.o \
	esqlfmt.o \
	filter.o \
	install.o \
	stderr.o \
	strlower.o \
	strupper.o

FGLXREF.o = \
	fglxref.o \
	${MISSING.o} \
	compare.o \
	filter.o \
	fgldata.o \
	fglxrefl.o \
	install.o \
	stderr.o

sqlfmt:	${SQLFMT.o}
	${CC} -o $@ ${SQLFMT.o} ${LDFLAGS}

fglfmt:		sqlfmt
	rm -f $@
	ln $? $@

esqlfmt:	${ESQLFMT.o}
	${CC} -o $@ ${ESQLFMT.o} ${LDFLAGS}

fglxref:	${FGLXREF.o}
	${CC} -o $@ ${FGLXREF.o} ${LDFLAGS}

dokeyword.o:	sqlfmt.h
install.o:		sqlfmt.h
fglxref.o:		sqlfmt.h	stderr.h	getopt.h	filter.h
fglxrefl.o:		sqlfmt.h
sqlmain.o:		sqlfmt.h	stderr.h	getopt.h	filter.h
esqlmain.o:		sqlfmt.h	stderr.h	getopt.h	filter.h
stderr.o:		stderr.h
filter.o:       filter.h
strlower.o:		jlss.h
strupper.o:		jlss.h
# The getopt.c provided does not need getopt.h

install: ${PROGRAMS} ${MANPAGES}
	cd ${BINDIR} ; rm -f ${PROGRAMS}
	cp ${PROGRAMS} ${BINDIR}
	cd ${BINDIR} ; chmod 555 ${PROGRAMS}
	cd ${MANDIR} ; rm -f ${MANPAGES}
	cp ${MANPAGES} ${MANDIR}
	cd ${MANDIR} ; chmod 444 ${MANPAGES}

cleanup:
	rm -f $@ ${PROGRAMS} ${MANPAGES}
	rm -f ${SQLFMT.o} ${ESQLFMT.o} ${FGLXREF.o}
	rm -f mkversion mknmd sqlfmt.nmd core

# Manual pages
man:	${MANPAGES}

i4glxref.1:	i4glxref.1j example.out example.4gl \
			function.4gl report.4gl tmac.esee
	rm -f $@
	${AWKPROG} i4glxref.1j > $@

sqlfmt.1:	sqlfmt.1j tmac.esee
	rm -f $@
	${AWKPROG} sqlfmt.1j > $@

#############################################
# Create NMD
NMD:	./mkversion mknmd sqlfmt.nmd .FORCE
	mknmd . NMD sqlfmt.nmd

./mkversion:	./mkversion.sh
	rm -f $@
	sh $? $? > $@
	chmod 555 $@

.FORCE:
