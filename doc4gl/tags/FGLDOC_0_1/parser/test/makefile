
# ===========================================================================
# 4gl documenter test code.
#
# $Id: makefile,v 1.1 2003-01-06 20:17:34 saferreira Exp $
# ===========================================================================

include ../../FgldocDefs.mk

CFLAGS+=-I..

test_p4gl:	test_p4gl.o
	$(MAKE) -C .. p4gl.a
	$(ESQL) $(CFLAGS) test_p4gl.o -o test_p4gl ../p4gl.a -lcheck
