# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   root makefile              |
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
# $Id: Makefile,v 1.3 2004-02-02 09:38:13 afalout Exp $
#

ROOT=../..

## ==================================================================
##                    Includes
## ==================================================================

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

ALL=${ROOT}/bin/afinderr${EXE}

${ALL}: afinderr.4gl
	${SH} ${ROOT}/bin/4glpc $^ -o $@
#	${ROOT}/bin/4glc afinderr.4gl -o afinderr
#	cp ./afinderr${EXE} ${ROOT}/bin


clean:
	rm -f *.c *.glb *.h *.exe afinderr *.err *.bak ${ALL}
