# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   lib makefile				 |
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
# $Id: Makefile,v 1.7 2003-05-01 02:37:48 afalout Exp $
#

ROOT    	=../..
LIBROOT		=..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Settings
## ==================================================================

4GLC	=${ROOT}/bin/4glc
FCOMPILE=${ROOT}/bin/fcompile

## ==================================================================
##                              Targets
## ==================================================================

${LIBROOT}/libHELP_std${SO_EXT}: helplib.c a4gl_xxhelp.afr.c
	export A4GL_SQLTYPE=nosql; ${SH} ${ROOT}/bin/4glpc -as-dll $^ -o $@
#WARNING: cannot use 4glc directly, because of broken getopt_long() on CygWin (-o will not be recognized)
#	export A4GL_SQLTYPE=nosql; ${4GLC} --shared $^ -o $@

## ==================================================================
##                              Sub-targets
## ==================================================================


helplib.c: helplib.4gl
	export A4GL_SQLTYPE=nosql; ${4GLC} --namespace "aclfgli_" $^

a4gl_xxhelp.afr.c: a4gl_xxhelp.per
	(export A4GL_PACKER=PACKED; export A4GL_FORMTYPE=GENERIC; export A4GL_SQLTYPE=nosql; ${FCOMPILE} -c $^)

## ==================================================================
##                              Clean
## ==================================================================

clean:
	rm -f a4gl_xxhelp.afr.c ${LIBROOT}/libHELP_std${SO_EXT} a4gl_xxhelp.afr.dat helplib.c helplib.glb helplib.h *.err *.bak debug.out

# =============================== EOF ================================
