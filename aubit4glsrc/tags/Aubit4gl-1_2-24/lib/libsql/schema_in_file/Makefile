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
# $Id: Makefile,v 1.4 2006-07-27 16:03:56 mikeaubury Exp $
#

ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common


## ==================================================================
##                              Options
## ==================================================================

#CFLAGS+=-I.. -I${ROOT}/compilers/fcompile -I/usr/local/include -I/usr/local/rpc -I/usr/local
CFLAGS+=-I..

ifneq "${COMSPEC}" ""
	LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
endif

ALL=${PLUGINDIR}/libSQL_FILESCHEMA${SO_EXT}

## ==================================================================
##                              Targets
## ==================================================================

ALL: ${ALL}

#FILESCHEMA${SO_EXT}: libSQL_FILESCHEMA${SO_EXT}

${PLUGINDIR}/libSQL_FILESCHEMA${SO_EXT}: schema_in_file.o
	${LD} ${SO_LDFLAGS} $^ -o $@  ${LINKLIBS}
#ifeq "${SO_EXT}" ".dll"
#	${MV} TMP${SOEXP_EXT} $@.a
#endif



## ==================================================================
##                              Clean
## ==================================================================


clean:
	${RM} *.o *${SO_EXT} *.bak *.base *.dll *.def *.exp *.a

#-------------------------------- EOF -------------------------------
