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
# $Id: Makefile,v 1.2 2006-10-10 05:45:46 afalout Exp $
#

ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

ALL	= ${PLUGINDIR}/libA4GL_memcache${SO_EXT_LINKABLE} test1.4ae

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "Done: ${ALL}"

libA4GL_memcache${SO_EXT_LINKABLE}: ${PLUGINDIR}/libA4GL_memcache${SO_EXT_LINKABLE}
${PLUGINDIR}/libA4GL_memcache${SO_EXT_LINKABLE}: memcache.c mem.4gl
	${ROOT}/bin/4glpc -g --as-dll -I. $^ -o $@

## ==================================================================
##                              Test
## ==================================================================
	
test1.4ae: test1.4gl
	-${ROOT}/bin/4glpc -g $^ -o $@
	-$@
	
## ==================================================================
##                              Clean
## =================================crc32_table.h  mem.4gl      memcache.c   mem.h              test1.err

clean:
	${RM} mem.h *.err *.ao test1.h mem.c *.so *~ *.glb test1.c ${ALL}

