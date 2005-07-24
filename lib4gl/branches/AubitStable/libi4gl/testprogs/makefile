#	@(#)$Id: makefile,v 1.2 2002-06-14 09:23:17 afalout Exp $
#
#	Makefile for issuing bits of Sphinx Informix Tools library

null:
	@echo "You must specify what to make:"
	@echo "	make scrdump.sa"

SRCDIR=../src
TSTDIR=.
MANDIR=../man

ANYTHING=i4gl.mk

SCRDMP_SRC=popstr.c scrdump.c rdscurses.h
SCRDMP_TST=scrdump.mk dumptst.4gl dumptst.per
SCRDMP_MAN=popstr.man scrdump.man
SCRDMP_FILES=$(SCRDMP_SRC) $(SCRDMP_TST) $(SCRDMP_MAN) $(ANYTHING)

scrdump.sa:	$(SCRDMP_FILES)
	shar $(SCRDMP_FILES) >$@
	chmod 644 $@

i4gl.mk:	$(HOME)/data/mk.4gl
	sed 's/mk.4gl/i4gl.mk/g' $? >$@

$(SCRDMP_TST):	$(TSTDIR)/SCCS/s.$$@
	get $?

$(SCRDMP_MAN):	$(MANDIR)/SCCS/s.$$@
	get $?

$(SCRDMP_SRC):	$(SRCDIR)/SCCS/s.$$@
	get $?

cleanup:
	rm -f $(SCRDMP_FILES) scrdump.sa
	rm -f makefile
