head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	89.02.01.17.29.21;	author john;	state Exp;
branches;
next	1.1;

1.1
date	89.01.31.15.53.25;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Change form name
@
text
@#	@@(#)$Id: scrdump.mk,v 1.1 2002-06-14 05:03:47 afalout Exp $
#
#	Makefile for Sphinx Informix Tools Library -- screen dump only

include i4gl.mk

LIB=libi4gl.a
LDFLAGS=-s

all:	$(LIB)	test

test:	dumptst

$(LIB):\
		$(LIB)(popstr.o)\
		$(LIB)(scrdump.o)
	ranlib $(LIB)

dumptst:	dumptst.o $(LIB) dumptst.frm
	$(C4GL) -o $@@ $@@.o $(LIB) $(LDFLAGS)
@


1.1
log
@Initial revision
@
text
@d12 1
a12 1
test:	scdmptst
d19 1
a19 1
scdmptst:	scdmptst.o $(LIB) scrdmp.frm
@
