# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0
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
# $Id: Makefile,v 1.2 2006-09-01 19:32:24 mikeaubury Exp $
#

ROOT    		=../..

################
#All stuff common to more then one Aubit compiler make file is there:
include 		${ROOT}/incl/Makefile-common

#Include rules for compiling 4GL source code using Aubit compiler
#include 		${ROOT}/incl/a4gl.mk

ALL=${ROOT}/bin/adbschema

## ==================================================================
##                         Targets
## ==================================================================

all: ${ALL}

adbschema: ${ROOT}/bin/adbschema
${ROOT}/bin/adbschema: adbschema.4gl table.4gl grant.4gl proc.4gl
	4glpc  -g $^ -o $@ 
#	export AUBITDIR=/opt/aubit4gl; aubit 4glpc --make-compile $^ -o $@
#	cp $@ /opt/aubit4gl/bin

efence:
	export AUBITDIR=/opt/aubit4gl; aubit 4glc adbschema.4gl -o adbschema.ao
	export AUBITDIR=/opt/aubit4gl; aubit 4glc table.4gl -o table.ao
	export AUBITDIR=/opt/aubit4gl; aubit 4glc grant.4gl -o grant.ao
	export AUBITDIR=/opt/aubit4gl; aubit 4glc adbschema.ao table.ao grant.ao -o $@ -lefence
	cp $@ /opt/aubit4gl/bin
	
## ==================================================================
##                         Clean
## ==================================================================

clean:
	${RM} *.ao *.c *.glb *.h *.err *.warn *~ ${ALL}


