head	4.14;
access;
symbols;
locks
	jleffler:4.14; strict;
comment	@# @;


4.14
date	97.10.07.18.48.15;	author johnl;	state Exp;
branches;
next	4.13;

4.13
date	97.06.02.22.20.20;	author johnl;	state Exp;
branches;
next	4.12;

4.12
date	92.10.08.20.48.36;	author jl;	state Exp;
branches;
next	4.11;

4.11
date	92.05.28.23.17.32;	author jl;	state Exp;
branches;
next	4.10;

4.10
date	92.05.09.14.51.54;	author jl;	state Exp;
branches;
next	4.9;

4.9
date	91.11.18.07.08.06;	author jl;	state Exp;
branches;
next	4.8;

4.8
date	91.08.19.22.30.25;	author jl;	state Exp;
branches;
next	4.7;

4.7
date	91.08.19.22.26.59;	author jl;	state Exp;
branches;
next	4.6;

4.6
date	91.06.17.19.57.40;	author jl;	state Exp;
branches;
next	4.5;

4.5
date	91.05.17.13.28.53;	author johnl;	state Exp;
branches;
next	4.4;

4.4
date	91.05.17.13.26.40;	author johnl;	state Exp;
branches;
next	4.3;

4.3
date	91.05.09.18.13.30;	author johnl;	state Exp;
branches;
next	4.2;

4.2
date	91.05.09.14.46.08;	author johnl;	state Exp;
branches;
next	4.1;

4.1
date	91.03.12.11.46.20;	author johnl;	state Exp;
branches;
next	3.8;

3.8
date	90.10.04.17.51.51;	author john;	state Exp;
branches;
next	3.7;

3.7
date	90.08.14.11.11.51;	author john;	state Exp;
branches;
next	3.6;

3.6
date	90.08.06.16.46.07;	author john;	state Exp;
branches;
next	3.5;

3.5
date	90.07.19.11.08.41;	author john;	state Exp;
branches;
next	3.4;

3.4
date	90.07.19.11.05.02;	author john;	state Exp;
branches;
next	3.3;

3.3
date	90.05.21.13.59.04;	author john;	state Exp;
branches;
next	3.2;

3.2
date	90.05.21.13.50.03;	author john;	state Exp;
branches;
next	3.1;

3.1
date	90.05.21.13.37.26;	author john;	state Exp;
branches;
next	2.10;

2.10
date	90.04.11.17.40.41;	author john;	state Exp;
branches;
next	2.9;

2.9
date	90.04.05.11.05.33;	author john;	state Exp;
branches;
next	2.8;

2.8
date	90.02.09.09.55.43;	author john;	state Exp;
branches;
next	2.7;

2.7
date	89.10.10.16.37.54;	author john;	state Exp;
branches;
next	2.6;

2.6
date	89.10.10.09.48.41;	author john;	state Exp;
branches;
next	2.5;

2.5
date	89.08.03.10.01.32;	author john;	state Exp;
branches;
next	2.4;

2.4
date	89.08.03.09.59.48;	author john;	state Exp;
branches;
next	2.3;

2.3
date	88.12.06.10.31.55;	author john;	state Exp;
branches;
next	2.2;

2.2
date	88.10.13.16.22.00;	author john;	state Exp;
branches;
next	2.1;

2.1
date	88.09.27.09.35.00;	author john;	state Exp;
branches;
next	;


desc
@@


4.14
log
@Upgraded
@
text
@#	@@(#)$Id: Makefile,v 1.1 2002-06-14 05:03:46 afalout Exp $
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
	${RDSLINK} -o $@@ reptest.4go repdest.4go 

# RMK only
${LIB1.4ga}:	${LIB1.4ga}(${FILES.4go})
	${AR} ${ARFLAGS} $@@ $?
	${RDSLIB} $@@
	-rm -f $?

decabs decneg decpwr decsqrt decsci:		$$@@.c
	${ESQL} -o $@@ ${CFLAGS} -DTEST $@@.c ${LIB2.a} ${LDFLAGS}
@


4.13
log
@Revisions from May 1993 checked in 4 yours late
@
text
@d1 1
a1 1
#	@@(#)$Id: Makefile,v 1.1 2002-06-14 05:03:46 afalout Exp $
d6 9
a14 5
CFLAGS   = -O -I${HOME}/inc
LIBDIR   = ${JOHN_HOME}/lib
LIB1.a   = ${LIBDIR}/libj4gl.a
LIB1.4ga = ${LIBDIR}/libj4gl.4ga
LIB1     = -lj4gl
d22 1
d35 1
a35 1
#   openlog.4gl  -- not very reliable                               #
d38 5
a50 5
	decabs.c \
	decneg.c \
	decpwr.c \
	decsci.c \
	decsqrt.c \
@


4.12
log
@Rename libraries; remove some trash
@
text
@d6 1
a6 2
CFLAGS   = -O -I${INFORMIXDIR}/incl -I${HOME}/inc
LIBSQL   = ${INFORMIXDIR}/lib
a8 1
LIB2.a   = ${LIBSQL}/libsql.a
d10 1
a10 1
LIB1     = -lgeneral
d134 1
a134 1
	${CC} -o $@@ ${CFLAGS} -DTEST $@@.c ${LIB2.a} ${LDFLAGS}
@


4.11
log
@Add decabs and decneg
@
text
@d9 1
a9 1
LIB1.a   = ${LIBDIR}/libgeneral.a
d11 1
a11 1
LIB1.4ga = ${LIBDIR}/libgeneral.4ga
d21 16
a42 1
	clrerrln.c \
d49 1
a49 3
	fnb.c \
	getenv.c \
	isdir.c \
a54 1
	pushwin.c \
a64 2
	chtodec.4gl \
	chtoint.4gl \
a70 1
	fileextn.4gl \
a86 1
	olderr.4gl \
a87 1
	openlog.4gl \
a96 1
	timeval.4gl \
@


4.10
log
@Add STRIP and LIBM and decpwr and decsqrt
@
text
@d28 2
d129 1
a129 1
decpwr decsqrt decsci:		$$@@.c
@


4.9
log
@Misc additions
@
text
@d13 1
d15 2
a16 1
LDFLAGS  = ${LIB1.a} -s
d28 1
d30 1
d127 1
a127 1
decsci decfix:		$$@@.c
@


4.8
log
@Add $HOME/inc to CFLAGS
@
text
@d4 1
a4 1
#	Upgraded for RMK
d37 1
d53 1
d70 1
d72 1
a72 1
	nextfld.4gl \
@


4.7
log
@Various bits of tidying up
@
text
@d6 1
a6 1
CFLAGS   = -O -I${INFORMIXDIR}/incl
@


4.6
log
@Add msgtext.c
@
text
@d20 1
d23 1
a23 1
SOURCES.c= \
a38 1
	scrdump.c \
d42 1
a42 1
SOURCES.4gl= \
d69 1
a69 1
	nxtfield.4gl \
d86 1
a86 1
FILES.4gf= \
d90 1
a90 1
FILES.frm=${FILES.4gf:.4gf=.frm}
d92 2
a93 2
SOURCES=	${SOURCES.c} ${SOURCES.4gl}
OBJECTS=	${SOURCES.c:.c=.o}	${SOURCES.4gl:.4gl=.o} ${SOURCES.ec:.ec=.o}
d95 1
a95 1
FILES.4go=${SOURCES.4gl:.4gl=.4go}
d109 1
a109 1
scrdump.o	${LIB1.a}(scrdump.o):	rdscurses.h
@


4.5
log
@Rename forms to .4gf
@
text
@d33 1
@


4.4
log
@Add spaces before backslashes; also some additions
@
text
@d85 3
a87 3
FILES.4pr= \
	repdest.4pr \
	scrndump.4pr
d89 1
a89 1
FILES.frm=${FILES.4pr:.4pr=.frm}
@


4.3
log
@Upgrade
@
text
@d22 9
a30 8
SOURCES.c=\
	access.c\
	decsci.c\
	exec.c\
	fnb.c\
	getenv.c\
	isdir.c\
	isfile.c\
d32 7
a38 7
	mkfile.c\
	popstr.c\
	pushwin.c\
	redraw.c\
	report.c\
	scrdump.c\
	sqlname.c\
d41 42
a82 40
SOURCES.4gl=\
	basedir.4gl\
	centre.4gl\
	checkint.4gl\
	chtodec.4gl\
	chtoint.4gl\
	dayname.4gl\
	dbexpln.4gl\
	dbtype.4gl\
	dispcntr.4gl\
	fdquart.4gl\
	fileextn.4gl\
	findstr.4gl\
	fnmonth.4gl\
	ftmonth.4gl\
	getopt.4gl\
	helpfile.4gl\
	instring.4gl\
	interr.4gl\
	ldquart.4gl\
	locks.4gl\
	ltmonth.4gl\
	mbetween.4gl\
	mkstring.4gl\
	mthname.4gl\
	nxtfield.4gl\
	opendb.4gl\
	openlog.4gl\
	repdest.4gl\
	reptype.4gl\
	rjust.4gl\
	scrndump.4gl\
	security.4gl\
	shell.4gl\
	stdopt.4gl\
	tdlyear.4gl\
	tdnyear.4gl\
	timeval.4gl\
	translog.4gl\
	usertype.4gl\
d85 2
a86 2
FILES.4pr=\
	repdest.4pr\
@


4.2
log
@Replace decformat
@
text
@d19 3
d30 1
d37 1
a37 1
	sqltype.c\
d89 1
a89 1
OBJECTS=	${SOURCES.c:.c=.o}	${SOURCES.4gl:.4gl=.o}
@


4.1
log
@Misc improvements and additions
@
text
@d7 1
d10 1
d21 1
a21 1
	decformat.c\
d111 3
@


3.8
log
@Add chtoint and chtodec
@
text
@d38 1
a39 1
	chtodec.4gl\
d41 3
d59 1
d63 1
d89 1
a89 1
all:	rds		c4gl
@


3.7
log
@Add findstr (function find_string)
@
text
@d38 2
@


3.6
log
@Add basedir, helpfile and openlog
@
text
@d41 1
@


3.5
log
@Add mbetween too
@
text
@d35 1
d44 1
d54 1
@


3.4
log
@Add getopt and instring; sort FILES.c
@
text
@d48 1
@


3.3
log
@Add locks.4gl and interr.4gl
@
text
@d18 1
a19 1
	access.c\
d42 2
@


3.2
log
@Add mthname.4gl
@
text
@d42 1
d44 1
d46 1
@


3.1
log
@Use RDSLIB and RDSLINK now; extend library
@
text
@d44 1
@


2.10
log
@Trimmed for use with RMK
@
text
@d6 10
a15 14
CFLAGS=-O -I${INFORMIXDIR}/incl
LIBGEN=${JOHN_HOME}/lib/libgeneral.a
LIBGENERAL.4ga=${JOHN_HOME}/lib/libgeneral.4ga
LDFLAGS=$(LIBGEN) -s
RANLIB=ranlib

#.AUGMENTED_MAKE:
.PRECIOUS:	${LIBGEN}

all:	rds		c4gl

c4gl:	${LIBGEN}

lib:	${LIBGEN}
d38 1
d42 1
d51 2
d55 2
a56 1
	usertype.4gl
d67 5
a71 1
all:	${LIBGEN}	${FILES.frm}
d73 1
a73 2
# RMK Systems only
${LIBGEN}:	${LIBGEN}(${OBJECTS})
d75 1
a75 2
redraw.o	${LIBGEN}(redraw.o):	rdscurses.h
scrdump.o	${LIBGEN}(scrdump.o):	rdscurses.h
d77 2
a78 2
reptest.4gi: reptest.4go repdest.4go repdest.frm
	cat reptest.4go repdest.4go >$@@
d80 2
a81 1
rds:	${LIBGENERAL.4ga}	${FILES.frm}
d83 2
a84 1
FILES.4go=${SOURCES.4gl:.4gl=.4go}
d86 5
a90 2
${LIBGENERAL.4ga}:	${FILES.4go}
	${RDS.LINKER} ${FILES.4go} >$@@
@


2.9
log
@Add RDS rules
@
text
@d12 1
a12 1
.AUGMENTED_MAKE:
d50 1
d64 1
d68 2
a69 31
${LIBGEN}:\
		${LIBGEN}(access.o)\
		${LIBGEN}(centre.o)\
		${LIBGEN}(checkint.o)\
		${LIBGEN}(decformat.o)\
		${LIBGEN}(exec.o)\
		${LIBGEN}(fileextn.o)\
		${LIBGEN}(fnb.o)\
		${LIBGEN}(fnmonth.o)\
		${LIBGEN}(ftmonth.o)\
		${LIBGEN}(getenv.o)\
		${LIBGEN}(isdir.o)\
		${LIBGEN}(isfile.o)\
		${LIBGEN}(ltmonth.o)\
		${LIBGEN}(mkfile.o)\
		${LIBGEN}(opendb.o)\
		${LIBGEN}(popstr.o)\
		${LIBGEN}(pushwin.o)\
		${LIBGEN}(redraw.o)\
		${LIBGEN}(repdest.o)\
		${LIBGEN}(report.o)\
		${LIBGEN}(rjust.o)\
		${LIBGEN}(scrdump.o)\
		${LIBGEN}(shell.o)\
		${LIBGEN}(sqltype.o)\
		${LIBGEN}(stdopt.o)\
		${LIBGEN}(timeval.o)\
		${LIBGEN}(translog.o)\
		${LIBGEN}(uname.o)\
		${LIBGEN}(usertype.o)
	${RANLIB} ${LIBGEN}
@


2.8
log
@Add scrndump
@
text
@d8 1
d15 3
a17 1
all:	${LIBGEN}
d41 1
d103 7
@


2.7
log
@Add ftmonth et al
@
text
@d45 1
d53 2
a54 1
	repdest.4pr
@


2.6
log
@Add reptest.4gi rule
@
text
@d39 3
d68 2
d73 1
d78 1
a80 1
		${LIBGEN}(redraw.o)\
@


2.5
log
@Modify dependencies on rdscurses.h
@
text
@d88 3
@


2.4
log
@Fix it up for RMK; add repdest.frm and redraw
@
text
@d86 2
a87 2
${LIBGEN}(redraw.o):	rdscurses.h
${LIBGEN}(scrdump.o):	rdscurses.h
@


2.3
log
@Add centre?
@
text
@d4 1
a4 2

include ${JOHN_HOME}/data/mk.4gl
d11 1
a13 3
.DEFAULT:
	$(GET) SCCS/s.$@@

d18 2
a19 1
SOURCES=\
a20 3
	centre.4gl\
	checkint.4gl\
	decformat.c\
a21 1
	fileextn.4gl\
a26 1
	opendb.4gl\
d29 11
a40 1
	report.c\
a41 1
	scrdump.c\
a42 1
	sqltype.c\
a45 1
	uname.c\
d48 9
a57 1
		${SOURCES}\
d74 1
d86 1
@


2.2
log
@Keep dlist code separate
@
text
@d23 1
d51 1
@


2.1
log
@Initial revision
@
text
@a24 5
	dlist.c\
	dlistdbl.c\
	dliststr.c\
	dlistdec.c\
	dlistint.c\
a51 5
		${LIBGEN}(dlist.o)\
		${LIBGEN}(dlistdbl.o)\
		${LIBGEN}(dliststr.o)\
		${LIBGEN}(dlistdec.o)\
		${LIBGEN}(dlistint.o)\
a75 5
${LIBGEN}(dlist.o):		dlist.h
${LIBGEN}(dlistdbl.o):	dlist.h
${LIBGEN}(dliststr.o):	dlist.h
${LIBGEN}(dlistdec.o):	dlist.h
${LIBGEN}(dlistint.o):	dlist.h
@
