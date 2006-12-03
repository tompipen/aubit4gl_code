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
# $Id: makefile,v 1.12 2006-12-03 08:58:36 afalout Exp $
#

ROOT    =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

#rules for making targets:
include ${ROOT}/incl/a4gl.mk

A4GL_LEXTYPE=C
#DEBUG=ALL
A4GL_SQLTYPE=nosql
A4GL_UI=CONSOLE
export A4GL_LEXTYPE DEBUG A4GL_SQLTYPE A4GL_UI

#'aubit' script debugging (invoked via amake rules):
#SHDBG=1
#export SHDBG


## ==================================================================
##                              Options
## ==================================================================

PROGS		=configurator${EXE}
FORMS		=change${COMP_FORM_EXT} options${COMP_FORM_EXT} values${COMP_FORM_EXT}
HELP		=helpfile${A4GL_HLP_EXT}
ALL			=${PROGS} ${FORMS} ${HELP}

.phony: install clean all run

OBJS=config.ao rest.ao dir.o globals.ao

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL} install
	@echo "Default targets (${ALL}) compiled sucesfully"

config.4gl helpfile.msg: descriptions mk_config 
	${SH} mk_config > config.4gl

configurator${EXE}: ${OBJS}
	export A4GL_LEXTYPE=C; export DEBUG=ALL; export A4GL_SQLTYPE=nosql; \
		export A4GL_UI=CONSOLE; ${FGLPCEXEC} $^ -o $@
show:
	@echo "A4GL_CURR_PACKER=${A4GL_CURR_PACKER}"
		
## ==================================================================
##                              Install
## ==================================================================

install:
	cp ${PROGS} ${ROOT}/bin
	cp ${HELP} ${ROOT}/${HELP_DESTINATION}
	cp ${FORMS} ${ROOT}/${FORMS_DESTINATION} 
	@echo "Aubit configurator installed"

run: ${ALL}
#	export A4GL_UI=TUI; ${ROOT}/bin/configurator
	export A4GL_UI=TUI; ./configurator -firstrun

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.msg *.ao ${ALL} *.bak config.4gl config.c rest.c *.err \
	*.glb *.h *.warn *~ *.o *.out globals.c


# ================================= EOF =============================
