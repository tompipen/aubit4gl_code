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
# $Id: makefile,v 1.2 2003-12-10 09:33:14 afalout Exp $
#

ROOT    =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

#rules for making targets:
include ${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Options
## ==================================================================

ALL=configurator helpfile.hlp change.afr.dat options.afr.dat

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "Default targets (${ALL}) compiled sucesfully"

helpfile.msg config.4gl: descriptions mk_config config.4gl.head
	${SH} mk_config > config.4gl

configurator: config.ao rest.ao
	${FGLPCEXEC} $^ -o $@

## ==================================================================
##                              Install/deinstall
## ==================================================================

install:
	cp ${ALL} ${ROOT}/bin
	@echo "Aubit configuratot installed"

deinstall:
	${RM} $(addprefix ${ROOT}/bin/,${ALL})
	@echo "Aubit configuratot deinstalled"

run: ${ALL}
#	export A4GL_UI=TUI; ${ROOT}/bin/configurator
	export A4GL_UI=TUI; ./configurator



## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.msg *.ao ${ALL} *.bak config.4gl *.c *.err *.glb *.h


# ================================= EOF =============================
