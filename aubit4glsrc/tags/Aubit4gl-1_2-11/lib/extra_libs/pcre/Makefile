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
# $Id: Makefile,v 1.8 2009-01-15 18:52:51 mikeaubury Exp $
#

#PCRE - Perl Compatible Regular Expressions
#http://www.pcre.org/

#download:
#Source: 
#Latest (5.0) ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/pcre-5.0.tar.bz2

#Windows port home: http://gnuwin32.sourceforge.net/packages/pcre.htm
#Windows installer (with all dependencies) : http://gnuwin32.sourceforge.net/downlinks/pcre-bin.php

#Usage:
# import package a4gl_pcre
# main
#         if pcre_match("cat|dog","There was an old cat") then
#                 display "Matches to ",pcre_text(1)
#         else
#                display "No match"
#         end if
# end main
#TODO: create test in aubit4gltest

ROOT    =../../..

include ${ROOT}/incl/Makefile-common

LFLAGS	=-L${PCRE_LIB_PATH}/bin -L/usr/local/lib -lpcre 
IFLAGS	=-I${PCRE_INC_PATH} -I/usr/include/pcre -I/usr/local/include

CFLAGS  +=-I${PCRE_INC_PATH} -I/usr/include/pcre  -I/usr/local/include

#All stuff common to more then one Aubit compiler make file is there:

## ==================================================================
##                              Options
## ==================================================================

4GLPC_EXEC=export A4GL_LEXTYPE=C; ${FGLPCEXEC}
4GLPC_EXEC+=--verbose
ALL=${PLUGINDIR}/libA4GL_pcre${SO_EXT} 

4GLC	=${ROOT}/bin/4glc

## ==================================================================
##                              Targets
## ==================================================================

#FIXME: use amake

######### !!!!!!!!! PLEASE keep A4GL_ in UPPERCASE !!!!!!!!! ###############
all : ${ALL}

${PLUGINDIR}/libA4GL_pcre${SO_EXT}: match.4gl
	export A4GL_OBJ_EXT=.o; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; $(ROOT)/bin/4glpc ${IFLAGS} ${AS_DLL}  ${LFLAGS}  -o $@ $^
	@echo "PCRE library sucesfully compiled."



## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.out *.c *.${FGLC_OUTPUT_EXT} *.h *${SO_EXT} *.err *.bak *.glb *.h \
	*.4ae *.afr.dat *.afr.xml *.afr  ${ALL} *.stackdump *~


