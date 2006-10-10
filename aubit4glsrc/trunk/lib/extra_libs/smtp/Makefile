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
# $Id: Makefile,v 1.4 2006-10-10 05:45:46 afalout Exp $
#

ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

GLIB_CFLAGS	=${shell pkg-config --cflags glib-2.0}
GLIB_LFLAGS	=${shell pkg-config --libs glib-2.0}

4GLC    	=${ROOT}/bin/4glc
4GLC_SET	=export A4GL_OBJ_EXT=.o; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C;
4GLC_FLAGS	=--verbose
4GLC_CFLAGS	+= -I. ${SMTP_INC_FLAGS} ${GLIB_CFLAGS}

CFLAGS		+= -I. ${SMTP_INC_FLAGS} ${GLIB_CFLAGS}
LINKLIBS	=-l${AUBITLIBFULL} -lsmtp -lsmtp_mime ${GLIB_LFLAGS}
LFLAGS		=-L$(smtpdir)/lib -L${ROOT}/lib

ALL			=${PLUGINDIR}/libfgl_smtp${SO_EXT} test_smtp test_rep

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "Done: $(ALL)"

libfgl_smtp${SO_EXT}: ${PLUGINDIR}/libfgl_smtp${SO_EXT}
${PLUGINDIR}/libfgl_smtp${SO_EXT}: aubit_smtp.o
	${LD} ${SMTP_LIB_FLAGS} ${SO_LDFLAGS} ${CFLAGS} -o $@ $^ ${LFLAGS} ${LINKLIBS}

aubit_smtp.o: aubit_smtp.4gl
	${4GLC_SET} ${4GLC} ${4GLC_FLAGS} $^ ${4GLC_CFLAGS} -o $@ 

## ==================================================================
##                              Test
## ==================================================================

test_smtp: test_smtp.4gl
	${FGLPC_NAME} test_smtp.4gl -o test_smtp

test_rep: test_rep.4gl
	${FGLPC_NAME} test_rep.4gl -o test_rep

show:
	@echo "GLIB_CFLAGS=${GLIB_CFLAGS}"
	@echo "GLIB_LFLAGS=${GLIB_LFLAGS}"
	@echo "SMTP_INC_FLAGS=${SMTP_INC_FLAGS}"
	
## ==================================================================
##                              Clean
## ==================================================================

clean: 
	${RM} ${PLUGINDIR}/libfgl_smtp.so test_smtp *.ao test_rep \
		*.o *.glb *.c *.h *~ 

	
	
# ------------------------------ EOF --------------------------------

