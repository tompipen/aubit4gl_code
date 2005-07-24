#	@(#)$Id: Makefile,v 1.2 2002-06-14 09:23:16 afalout Exp $
#
#	Makefile for Informix-4GL Tools Library Directory
#	RMK only

BASE     = j4gl
DFLAGS   = -Xa
IFLAGS   = -I${HOME}/inc
OFLAGS   = -O
CFLAGS   = ${OFLAGS} ${IFLAGS} ${DFLAGS}
LIBDIR   = ${HOME}/lib
LIB1.a   = ${LIBDIR}/lib${BASE}.a
LIB1.4ga = ${LIBDIR}/lib${BASE}.4ga
LIB1     = -l${BASE}
LIBM     = -lm
RDSLINK- = -L ${LIBDIR}
STRIP    = -s
LDFLAGS  = ${LIB1.a} ${LIBM} ${STRIP}
RANLIB   = ranlib
RDSLIB   = rdslib
RDSLINK  = rdslink
ESQL     = ${C4GL}

#####################################################################
# Officially deprecated sources: no longer used.                    #
#####################################################################
#   chtodec.4gl  -- not really needed                               #
#   chtoint.4gl  -- not really needed                               #
#   clrerrln.c   -- uses internal knowledge                         #
#   fileextn.4gl -- not very reliable                               #
#   fnb.c        -- use ljust() instead                             #
#   getenv.c     -- use fgl_getenv() instead                        #
#   isdir.c      -- contorted interface                             #
#   olderr.4gl   -- use ermsg.4gl instead                           #
#   openlog.4gl  -- superseded by fgl_openlog()                     #
#   pushwin.c    -- uses internal knowledge (and not really needed) #
#   timeval.4gl  -- use DATETIME instead                            #
#   decabs.c     -- moved                                           #
#   decneg.c     -- moved                                           #
#   decpwr.c     -- moved                                           #
#   decsci.c     -- moved                                           #
#   decsqrt.c    -- moved                                           #
#####################################################################

SOURCES.ec = \
	scrdump.ec \
	sqltype.ec

SOURCES.c = \
	access.c \
	exec.c \
	getkey.c \
	isfile.c \
	ljust.c \
	mkfile.c \
	msgtext.c \
	popstr.c \
	random.c \
	redraw.c \
	report.c \
	sqlname.c \
	uname.c

SOURCES.4gl = \
	basedir.4gl \
	centre.4gl \
	checkint.4gl \
	dayname.4gl \
	dbexpln.4gl \
	dbtype.4gl \
	dispcntr.4gl \
	errmsg.4gl \
	fdquart.4gl \
	findstr.4gl \
	fnmonth.4gl \
	ftmonth.4gl \
	getopt.4gl \
	helpfile.4gl \
	incoff.4gl \
	instring.4gl \
	interr.4gl \
	ldquart.4gl \
	locks.4gl \
	ltmonth.4gl \
	mbetween.4gl \
	mkstring.4gl \
	mthname.4gl \
	nextfld.4gl \
	npwkday.4gl \
	opendb.4gl \
	repdest.4gl \
	reptype.4gl \
	rjust.4gl \
	scrndump.4gl \
	security.4gl \
	shell.4gl \
	stdopt.4gl \
	tdlyear.4gl \
	tdnyear.4gl \
	translog.4gl \
	usertype.4gl \
	zerodiv.4gl

FILES.4gf = \
	repdest.4gf \
	scrndump.4gf

FILES.frm = ${FILES.4gf:.4gf=.frm}

SOURCES = ${SOURCES.c} ${SOURCES.4gl}
OBJECTS = ${SOURCES.c:.c=.o}	${SOURCES.4gl:.4gl=.o} ${SOURCES.ec:.ec=.o}

FILES.4go = ${SOURCES.4gl:.4gl=.4go}

.PRECIOUS:	${LIB1.a}	${LIB1.4ga}

all:	c4gl	rds

rds:	${LIB1.4ga}	${FILES.frm}

c4gl:	${LIB1.a}	${FILES.frm}

# RMK only
${LIB1.a}:	${LIB1.a}(${OBJECTS})

redraw.o	${LIB1.a}(redraw.o):	rdscurses.h
#scrdump.o	${LIB1.a}(scrdump.o):	rdscurses.h

reptest.4gi: reptest.4go repdest.4go repdest.frm
	${RDSLINK} -o $@ reptest.4go repdest.4go 

# RMK only
${LIB1.4ga}:	${LIB1.4ga}(${FILES.4go})
	${AR} ${ARFLAGS} $@ $?
	${RDSLIB} $@
	-rm -f $?

decabs decneg decpwr decsqrt decsci:		$$@.c
	${ESQL} -o $@ ${CFLAGS} -DTEST $@.c ${LIB2.a} ${LDFLAGS}
