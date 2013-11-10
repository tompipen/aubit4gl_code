


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
# $Id: Makefile,v 1.7 2013-10-07 20:39:58 mikeaubury Exp $
#

ROOT        =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                    		Settings
## ==================================================================

CMODS   	= formxml.c wrapper.c 
CMODS_JSON      = formjson.c wrapper_json.c
OBJS		=${CMODS:.c=.o}
OBJS_JSON	=${CMODS_JSON:.c=.o}
ALL 		=${PLUGINDIR}/libPACKER_FORMXML${SO_EXT} ${PLUGINDIR}/libPACKER_FORMJSON${SO_EXT}

LOCAL_IFLAGS=-I..

CFLAGS      +=${LOCAL_IFLAGS} 

ifneq "${COMSPEC}" ""
	LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
endif


## ==================================================================
##                          Targets
## ==================================================================

ALL: ${ALL}

${PLUGINDIR}/libPACKER_FORMXML${SO_EXT}: ${OBJS}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}
${PLUGINDIR}/libPACKER_FORMJSON${SO_EXT}: ${OBJS_JSON}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}

#ifeq "${SO_EXT}" ".dll"
#	${MV} TMP${SOEXP_EXT} $@.a
#endif

## ==================================================================
##                          Clean
## ==================================================================

clean:
	${RM} ${PLUGINDIR}/libPACKER_FORMXML${SO_EXT} ${PLUGINDIR}/libPACKER_FORMJSON${SO_EXT}  *.bak *.o

## ==================================================================
##                         Other Targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"

#=============================== EOF ================================

#libPACKER_FORMXML.so: formxml.c wrapper.c
#$(CC) $(CFLAGS) -Wall -g -shared -fPIC -I../../../incl formxml.c wrapper.c -o libPACKER_FORMXML.so
#cp *.so `aubit-config DEFAULT_PLUGINDIR`
#clean:
#rm -f libPACKER_FORMXML.so  `aubit-config DEFAULT_PLUGINDIR`/libPACKER_FORMXML.so

