head	1.5;
access;
symbols;
locks; strict;
comment	@# @;


1.5
date	89.01.31.16.21.20;	author john;	state Exp;
branches;
next	1.4;

1.4
date	89.01.31.16.19.23;	author john;	state Exp;
branches;
next	1.3;

1.3
date	89.01.31.16.18.36;	author john;	state Exp;
branches;
next	1.2;

1.2
date	89.01.31.16.16.29;	author john;	state Exp;
branches;
next	1.1;

1.1
date	89.01.31.16.11.17;	author john;	state Exp;
branches;
next	;


desc
@@


1.5
log
@Add rdscurses.h
@
text
@#	@@(#)$Id: makefile,v 1.1 2002-06-14 05:03:47 afalout Exp $
#
#	Makefile for issuing bits of Sphinx Informix Tools library

null:
	@@echo "You must specify what to make:"
	@@echo "	make scrdump.sa"

SRCDIR=../src
TSTDIR=.
MANDIR=../man

ANYTHING=i4gl.mk

SCRDMP_SRC=popstr.c scrdump.c rdscurses.h
SCRDMP_TST=scrdump.mk dumptst.4gl dumptst.per
SCRDMP_MAN=popstr.man scrdump.man
SCRDMP_FILES=$(SCRDMP_SRC) $(SCRDMP_TST) $(SCRDMP_MAN) $(ANYTHING)

scrdump.sa:	$(SCRDMP_FILES)
	shar $(SCRDMP_FILES) >$@@
	chmod 644 $@@

i4gl.mk:	$(HOME)/data/mk.4gl
	sed 's/mk.4gl/i4gl.mk/g' $? >$@@

$(SCRDMP_TST):	$(TSTDIR)/SCCS/s.$$@@
	get $?

$(SCRDMP_MAN):	$(MANDIR)/SCCS/s.$$@@
	get $?

$(SCRDMP_SRC):	$(SRCDIR)/SCCS/s.$$@@
	get $?

cleanup:
	rm -f $(SCRDMP_FILES) scrdump.sa
	rm -f makefile
@


1.4
log
@Remove archive too
@
text
@d15 1
a15 1
SCRDMP_SRC=popstr.c scrdump.c
@


1.3
log
@Add cleanup
@
text
@d37 1
a37 1
	rm -f $(SCRDMP_FILES)
@


1.2
log
@Make sure archives are readable
@
text
@d35 4
@


1.1
log
@Initial revision
@
text
@d22 1
@
