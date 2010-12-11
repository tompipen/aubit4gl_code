# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-9 Aubit Development Team (See Credits file)       |
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
# | contact licensing@aubit.com
# +----------------------------------------------------------------------+
#
# $Id: Makefile,v 1.2 2009-02-11 18:21:15 mikeaubury Exp $
#

ROOT    =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common


4GLPC   =${FGLPCEXEC}

## ==================================================================
##                    Targets
## ==================================================================

${ROOT}/bin/quickguide.4ae: quickguide.4gl
	$(ROOT)/bin/4glpc -o $@ $<


## ==================================================================
##                    Clean
## ==================================================================

clean:
	${RM} *.err *.bak *.c *.h *.4ge *.4ae core *.out *.glb *.warn ${ROOT}/bin/quickguide.4ae


