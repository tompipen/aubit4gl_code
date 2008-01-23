# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: Makefile,v 1.4 2008-01-23 18:17:29 mikeaubury Exp $
#

ROOT    =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

#rules for making targets:
include ${ROOT}/incl/?4gl.mk

## ==================================================================
##                              Options
## ==================================================================


A4GL_LEXTYPE=C
DEBUG=ALL
A4GL_SQLTYPE=nosql
A4GL_UI=CONSOLE

export A4GL_LEXTYPE DEBUG A4GL_SQLTYPE A4GL_UI
					
#4GLPCFLAGS		=${VERBOSE_FLAG} -settings

#KEEP IN MIND THAT THIS MAKE FILE IS ALSO IN BINARY DISTRIBUTION - DO NOT ADD
#ANY MORE TARGETS HERE UNLESS YOU WILL ALSO MODIFY THE INSTALLER TO PACK NEEDED
#SOURCE FILES IN BYNARY DISTROS - OTHERWISE MAKE WILL FAIL BECAUSE OF MISSING
#SOURCE FILES ! KEEP ALSO IN MIND THAT DEFAULT TARGETS HERE ARE SUPPOSED TO BE
#ONLY FOR A LIGHT DEMO AND TO CONFIRM THAT COMPILER WORKS AND IS INSTALLED
#CORRECTLY - SO WE DON'T WANT TOO MANY PROGRAMS HERE
DEFAULT	=hello${A4GL_EXE_EXT} hello2${A4GL_EXE_EXT} hello_db${A4GL_EXE_EXT} \
		testmenu${A4GL_EXE_EXT} testmenu${A4GL_MNU_EXT} \
		form${A4GL_FRM_EXT} helpfile.hlp  file${A4GL_EXE_EXT}


SUB		=
#guidemos

ALL		=${DEFAULT} assoc2${A4GL_EXE_EXT}

ifeq "${EXDATA_MPZ}" "yes"
	ALL	+=testmpz${A4GL_EXE_EXT}
endif


#Targets still expected to fail, that need fixing:
ALL_FAIL=pdf_report${A4GL_EXE_EXT}

#Targets that need database to compile
ALL_DB  =test_select${A4GL_EXE_EXT}

ifneq "${AUBIT_BIN_INSTALL}" "1"
	#We have this dirs only in source code tree - not in bunary distros:
	SUB+=langdemos
	
	#Both regressiontests and dbtests need a database
	REGRES=regressiontests dbtests
    #examples we have only in source code tree, but not in binary installations:
	ALL +=solitaire${A4GL_EXE_EXT}
	4GLC=${ROOT}/bin/4glc
else
	4GLC=aubit 4glc
endif

ALL     +=${SUB}


.PHONY: default all sub test.build test.perl ${SUB} ${REGRES} \
		help clean clean.sub

## ==================================================================
##                              Targets
## ==================================================================

default: ${DEFAULT}
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| Default simple demo targets successfully compiled                  |"
	@echo "| Try 'make all' for more example code.                              |"
	@echo "| You can run compiled demo program 'hello' by executing:            |"
	@echo "|   ./hello${A4GL_EXE_EXT}                                                      |"
	@echo "| Alternatively, if you did not yet set your run-time environment for|"
	@echo "| execution of Aubit programs (PATH, LD_LIBRARY_PATH, AUBITDIR, etc) |"
	@echo "| you can use 'aubit' wrapper script to run programs - for example:  |"
	@echo "|   aubit ./hello${A4GL_EXE_EXT}                                                |"
	@echo "+--------------------------------------------------------------------+"
	@echo " "
	@echo "Thank you for using Aubit 4gl compiler"
	@echo " "

all: ${ALL}
	@echo "all targets successfully compiled"
	@echo "Targets that are expected to fail: ${ALL_FAIL}"


solitaire${A4GL_EXE_EXT}: sol.4gl random.4gl
	${FGLPCEXEC_NAME} ${4GLPCFLAGS} $^ -o $@

## ==================================================================
##              Targets for testing compiler build success
## ==================================================================

#This is used from root makefile, to test if compiler is working after building it:
test.build: test_build.4gl
	${RM} $(basename $<).c $(basename $<).h $(basename $<).o $(basename $<) $(basename $<).exe
	(DEBUG=ALL;export DEBUG;${FGLPCEXEC} ${VERBOSE_FLAG} ${4GLPCTESTFLAGS} $^ -o $(basename $<))

#Same purpose as test.build target, but for Perl compiler:
test.perl: test_build.4gl
#calldll.c            497    (     0,     0) 1 Function Not found : print_Constant
	export A4GL_LEXTYPE=PERL; export DEBUG=ALL; ${4GLC} ${VERBOSE_FLAG} $<
	export A4GL_UI=TUI;  export DEBUG=ALL; ${PERL} ./$(basename $<).pl

#For Pcode compiler:
test.pcode: test_build.4gl
#A4GL_FAKELEXTYPE isn't strictly needed - but it generates smaller C code:
	export A4GL_FAKELEXTYPE=PCODE; ${4GLC} $^
#(Should generate .4pe.dat or 4pe.xml)
	${ROOT}/bin/c2pcode_fgl $(basename $<).c 
#do not add .xml or .dat - thats added by the packer:
	
	
## ==================================================================
##                    Targets in sub-makefiles
## ==================================================================

sub: ${SUB}
	@echo targets in sub directories successfully compiled

#GUI demo code
guidemos:
	${MAKE} -C gui all

#Internationalisation demo code
langdemos:
	${MAKE} -C lang lang

#This is test suite of Informix ESQL driver, not a demo program
dbtests:
	${MAKE} -C db

#This is regression test, not demo code
regressiontests:
	${MAKE} -C regression

## ==================================================================
##                          Help
## ==================================================================

help:
	@echo "use 'make' to compile examples"

## ==================================================================
##                      Clean targets
## ==================================================================


clean:
	$(RM) *.BAK *.bak core *~ *.ln *.output *.out *.frm *.h *.o *.4ae \
	test_build *.hlp *.exe *.stackdump *.err *.c *.tmp *.42m *.glb \
	*.42r rr1.pdf *.ao *.log *.4ge *.pl *.pm pdf_report solitaire test_select test_mpz \
	test_build.c ${FILES.4gl:.4gl=.h} assoc file *.aso .\#* \
	*${A4GL_FRM_EXT} *${A4GL_MNU_EXT} *.aox *.warn *.ec *.lst *.4gi *.4go \
	*.cpc *.42f *.4qe *.qo *.pic *.pcl *.w2 *.w3 \
	*.afr.xml  *.mnu.xml
	
clean.sub:
ifneq "${AUBIT_BIN_INSTALL}" "1"
	${MAKE} -C regression clean
	${MAKE} -C db clean
	${MAKE} -C lang clean
	${MAKE} -C gui clean
endif




# ============================== EOF ================================
