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
# $Id: makefile,v 1.3 2004-09-28 09:49:15 afalout Exp $
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
LIBROOT =${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

4GLPC_EXEC=export A4GL_LEXTYPE=C; ${FGLPCEXEC}

ALL=${LIBROOT}/libA4GL_pcre${SO_EXT} 

4GLC	=${ROOT}/bin/4glc

## ==================================================================
##                              Targets
## ==================================================================

#FIXME: use amake

######### !!!!!!!!! PLEASE keep A4GL_ in UPPERCASE !!!!!!!!! ###############
all : ${ALL}

${LIBROOT}/libA4GL_pcre${SO_EXT}: match.4gl
#	${4GLPC_EXEC} -g -as-dll $^ -o $@ -lspopc
#	${LD} ${SO_LDFLAGS} ${CFLAGS} -o $@ $^ -L${ROOT}/lib -laubit4gl -lspopc
	${4GLPC_EXEC} $^ -as-dll -o $@ -lpcre
	@echo "PCRE library sucesfully compiled."


#pop.c: pop.4gl
#	export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; ${4GLC} --verbose $^

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.out *.c *.${FGLC_OUTPUT_EXT} *.h *${SO_EXT} *.err *.bak *.glb *.h \
	*.4ae *.afr.dat *.afr.xml *.afr  ${ALL} *.stackdump *~


