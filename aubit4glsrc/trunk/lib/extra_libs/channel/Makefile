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
# $Id: Makefile,v 1.6 2006-07-27 16:02:13 mikeaubury Exp $
#

ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

4GLC	=${ROOT}/bin/4glc -g

#NOTE: must NOT be named libA4GL_channel, since that would force
#renaming of all 'CALL channel::' to 'CALL A4GL_channel::'  
#ALL     =${LIBROOT}/libA4GL_channel${SO_EXT}
ALL     =${PLUGINDIR}/libchannel${SO_EXT}

## ==================================================================
##                              Targets
## ==================================================================

#FIXME: use amake
${ALL}: channel.o
	${LD} -g ${SO_LDFLAGS} ${CFLAGS} -o $@ $^ -L${ROOT}/lib -l${AUBITLIBFULL}
	@echo "Channel library sucesfully compiled."

channel.c: channel.4gl
	export A4GL_OBJ_EXT=.o; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; ${4GLC} ${VERBOSE_FLAG} $^

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.out *.c *.${FGLC_OUTPUT_EXT} *.h *${SO_EXT} *.err *.bak *.glb *.o *.ao \
	*.h ${ALL} *.stackdump

# ============================== EOF ================================


