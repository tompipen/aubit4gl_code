#	@(#)$Id: scrdump.mk,v 1.2 2002-06-14 09:23:17 afalout Exp $
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
	$(C4GL) -o $@ $@.o $(LIB) $(LDFLAGS)
