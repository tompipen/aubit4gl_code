
# ===========================================================================
# 4gl documenter test code.
#
# $Id: makefile,v 1.2 2003-05-15 10:23:26 afalout Exp $
# ===========================================================================

include ../../FgldocDefs.mk

CFLAGS+=-I..

.PHONY: clean test

#Run unit test program:
test: test_p4gl
	$^
#FIXME: this is going to fail:
#make[2]: Entering directory `/opt/aubit/doc4gl/parser/test'
#test_p4gl
#Running suite(s): P4glp4glpp: Erro a abrir ficheiro TestTable.4gl
#No such file or directory
#p4gl: TestTable.4gl, Unable to Pre-process source (TestTable.4gl)
#make[2]: *** [testit] Error 1


#Create unit thest program:
test_p4gl:	test_p4gl.o
	$(MAKE) -C .. p4gl.a
	$(ESQL) $(CFLAGS) $^ -o $@ ../p4gl.a -lcheck


clean:
	${RM} *.o test_p4gl
