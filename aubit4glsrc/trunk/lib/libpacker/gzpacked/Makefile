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
# $Id: Makefile,v 1.2 2006-10-10 05:45:48 afalout Exp $
#

ROOT        =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                    		Settings
## ==================================================================

CMODS   	=pack_packed.c gzhelper.c
OBJS		=${CMODS:.c=.o}
ALL 		=${PLUGINDIR}/libPACKER_GZPACKED${SO_EXT}

LOCAL_IFLAGS=-I..

CFLAGS      +=${LOCAL_IFLAGS}

ifneq "${COMSPEC}" ""
	LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
endif
LINKLIBS+=-lz


## ==================================================================
##                          Targets
## ==================================================================

ALL: ${ALL}
	@echo "Done: ${ALL}"
	
${PLUGINDIR}/libPACKER_GZPACKED${SO_EXT}: ${OBJS}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}

## ==================================================================
##                          Clean
## ==================================================================

clean:
	${RM} ${ALL} *.bak *.o *~

## ==================================================================
##                         Other Targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"

#=============================== EOF ================================

