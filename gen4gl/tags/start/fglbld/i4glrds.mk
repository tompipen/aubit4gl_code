#	@(#)$Id: i4glrds.mk,v 1.1.1.1 2002-06-15 05:06:55 afalout Exp $
#
#	Makefile for I4GL-RDS Interpreters
#	Works with standard Xenix make and RMK

#############################################################################
# Recognised targets:
#	all:			Compiles FGLGO and FGLDB
#	cleanup:		Remove intermediate files
#	library:		Library needed to create FGLGO and FGLDB
#############################################################################

# Rules for compiling Informix
include informix.mk

# Directive for RMK -- does not affect MAKE
.AUGMENTED_MAKE:

# Target which is always out of date -- forces things to happen
.FORCE:
#############################################################################
#	General Definitions
#############################################################################
FGLBLDDIR=.
CFLAGS=-O -I${INFORMIXDIR}/incl -DI4GL_RDS
LIBRARY=./libdlist.a
LDFLAGS=${LIBRARY} -s
COPY=cp
RANLIB=ranlib

#############################################################################
#	Lists of build-time files
#	These are not needed in a binary-only distribution
#############################################################################

OBJECTS=\
	decformat.o\
	dlist.o\
	dlistdbl.o\
	dlistdec.o\
	dlistint.o\
	dliststr.o\
	editstr.o\
	exec.o\
	getenv.o\
	isdir.o\
	mkfile.o\
	popstr.o\
	redraw.o\
	report.o\
	round.o\
	scrdump.o\
	sqltype.o\
	uname.o

LIBOBJECTS=\
	${LIBRARY}(decformat.o)\
	${LIBRARY}(dlist.o)\
	${LIBRARY}(dlistdbl.o)\
	${LIBRARY}(dlistdec.o)\
	${LIBRARY}(dlistint.o)\
	${LIBRARY}(dliststr.o)\
	${LIBRARY}(editstr.o)\
	${LIBRARY}(exec.o)\
	${LIBRARY}(getenv.o)\
	${LIBRARY}(isdir.o)\
	${LIBRARY}(mkfile.o)\
	${LIBRARY}(popstr.o)\
	${LIBRARY}(redraw.o)\
	${LIBRARY}(report.o)\
	${LIBRARY}(round.o)\
	${LIBRARY}(scrdump.o)\
	${LIBRARY}(sqltype.o)\
	${LIBRARY}(uname.o)

INTERPRETER.o=\
	fgiusr.o

I4GL.rds=\
	fgldb\
	fglgo

#############################################################################
#	Rules for building FGLGO and FGLDB
#############################################################################

.PRECIOUS:	${LIBRARY}

all:	${I4GL.rds}

${I4GL.rds}:	${INTERPRETER.o} ${LIBRARY}
	rm -f o.${@F}
	if [ -f ${@F} ] ; then mv ${@F} o.${@F} ; rm -f o.${@F} ; fi
	c${@F} -o ${@F} ${INTERPRETER.o} ${LDFLAGS}

cleanup:
	rm -f ${OBJECTS}
	rm -f ${LIBRARY}
	rm -f ${I4GL.rds}

library:	${LIBRARY}

${LIBRARY}: ${LIBOBJECTS}
	${RANLIB} ${LIBRARY}

${LIBOBJECTS}: dlist.h

redraw.o  ${LIBRARY}(redraw.o):		rdscurses.h
scrdump.o ${LIBRARY}(scrdump.o):	rdscurses.h
