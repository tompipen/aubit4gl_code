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
# $Id: Makefile,v 1.3 2004-12-22 11:22:18 afalout Exp $
#

ROOT    =..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

#rules for making targets:
include ${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Options
## ==================================================================

DESTINATION=${ROOT}/${HELP_DESTINATION}/

HLP_FILES=	help_aubit${A4GL_HLP_EXT} \
			help_ecpg${A4GL_HLP_EXT} \
			help_sqlite${A4GL_HLP_EXT}

## ==================================================================
##                              Targets
## ==================================================================

all: ${HLP_FILES}
	cp $^ ${DESTINATION}
	@echo "Help files compiled."

#%${A4GL_HLP_EXT}: $(notdir %.msg)
#	../bin/amkmessage $(notdir $<) $@

#.msg${A4GL_HLP_EXT}:
#	${FAIL_CMPL_HLP}${A4GL_MC} $(notdir $^) $@

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} ${HLP_FILES} *.bak *~

