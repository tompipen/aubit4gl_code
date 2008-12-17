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
# $Id: Makefile,v 1.3 2008-12-17 09:42:57 mikeaubury Exp $
#

ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common
include                 ${ROOT}/incl/a4gl.mk
## ==================================================================
##                              Options
## ==================================================================

4GLC	=${ROOT}/bin/4glc
ALL     =${PLUGINDIR}/libA4GL_pick${SO_EXT}

## #######################################################################
##
## PLEASE DONT ADD ANY EXTRA 4GLS OR C MODULES TO THIS DIRECTORY
## WITHOUT UPDATING THE OBJS_PICK in tools/asql and tools/a4gl and tools/aupscol
##
## #######################################################################

OBJS_FORM       = pick10.afr${A4GL_OBJ_EXT}  pick20.afr${A4GL_OBJ_EXT} pick38.afr${A4GL_OBJ_EXT} pick78.afr${A4GL_OBJ_EXT}
A4GL_PACKER=PACKED
A4GL_PACKER_EXT=.dat
A4GL_FORMTYPE=GENERIC
export A4GL_PACKER
export A4GL_PACKER_EXT
export A4GL_FORMTYPE

## ==================================================================
##                              Targets
## ==================================================================

${ALL}: pick.o ${OBJS_FORM}
	${LD} ${SO_LDFLAGS} ${CFLAGS_NOWARN} -o $@ $^ -L${ROOT}/lib -l${AUBITLIBFULL}
	@echo "File library sucesfully compiled."

## #######################################################################
##
## PLEASE DONT ADD ANY EXTRA 4GLS OR C MODULES TO THIS DIRECTORY
## WITHOUT UPDATING THE OBJS_PICK in tools/asql and tools/a4gl and tools/aupscol
##
## #######################################################################

pick.o: pick.4gl
	A4GL_OBJ_EXT=.o A4GL_SQLTYPE=nosql A4GL_LEXTYPE=C ${4GLC} -o $@ ${VERBOSE_FLAG} $^


%.afr${A4GL_OBJ_EXT}:%.per
	fcompile -c $<
	4glpc -t C -c -o $@ ${subst .per,.afr.c,$<}

%.afr.dat:%.per
	fcompile  $<

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.out *.c *.${FGLC_OUTPUT_EXT} *.h *${SO_EXT} *.err *.bak *.glb \
	*.h ${ALL} *.stackdump ${OBJS_FORM} *.afr.dat

# ============================== EOF ================================


