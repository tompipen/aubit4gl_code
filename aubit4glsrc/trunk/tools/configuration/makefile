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
# $Id: makefile,v 1.6 2004-02-01 03:16:54 afalout Exp $
#

ROOT    =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

#rules for making targets:
include ${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Options
## ==================================================================

ALL=configurator${EXE} helpfile.hlp change.afr.dat options.afr.dat values.afr.dat

.phony: install clean all deinstall run

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL} install
	@echo "Default targets (${ALL}) compiled sucesfully"

config.4gl helpfile.msg: descriptions mk_config config.4gl.head
	${SH} mk_config > config.4gl

config.ao: config.4gl 
rest.ao: rest.4gl

configurator${EXE}: config.ao rest.ao dir.o
	${FGLPCEXEC} $^ -o $@

## ==================================================================
##                              Install/deinstall
## ==================================================================

install:
	cp ${ALL} ${ROOT}/bin
	@echo "Aubit configurator installed"

deinstall:
	${RM} $(addprefix ${ROOT}/bin/,${ALL})
	@echo "Aubit configurator deinstalled"

run: ${ALL}
#	export A4GL_UI=TUI; ${ROOT}/bin/configurator
	export A4GL_UI=TUI; ./configurator -firstrun



## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.msg *.ao ${ALL} *.bak config.4gl config.c rest.c *.err \
	*.glb *.h *.warn *~ *.o


# ================================= EOF =============================
