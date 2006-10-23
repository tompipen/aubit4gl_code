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
# $Id: Makefile,v 1.8 2006-10-23 10:08:41 mikeaubury Exp $
#

ROOT		=../../..
LIBROOT		=${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

ALL			= ${PLUGINDIR}/libSQL_mysql${SO_EXT}
CMODS		= mysql.c
OBJS		= ${CMODS:.c=.o}
L_FLAGS		= ${MYSQL_LFLAGS} -L$(LIBROOT)
LINKLIBS	= -lmysqlclient -laubit4gl-${A4GL_VERSION_STRING}
CFLAGS		:= ${MYSQL_IFLAGS} -I${ROOT}/incl ${CFLAGS}


## ==================================================================
##                              Targets
## ==================================================================

ALL: ${ALL}
	@echo "Default targets (${ALL}) built successfully."
	
${PLUGINDIR}/libSQL_mysql${SO_EXT} : ${OBJS}
	${LD} ${SO_LDFLAGS} -o $@ $^ -L/usr/lib64/mysql ${L_FLAGS} ${LINKLIBS} 

## ==================================================================
##                              Sub-Targets
## ==================================================================

#Debugging: show current settings of make variables
show:
	@echo "IFX_LIBS=${IFX_LIBS}"
#	@echo "Output of 'set':"
#	set

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} ${ALL} *.o *~
	
#----------------------------- EOF ----------------------------------

