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
# $Id: Makefile,v 1.14 2003-10-16 09:46:25 afalout Exp $
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


#ifneq "${COMSPEC}" ""
	#LINKLIBS=-lD:/WINNT/system32/winsock.dll
	#LINKLIBS=-lwsock32
	#LINKLIBS=-lws2_32 -lwsock32 -lmswsock
#endif

## ==================================================================
##                              Targets
## ==================================================================

${LIBROOT}/libHELP_std${SO_EXT}: helplib.${FGLC_OUTPUT_EXT} a4gl_xxhelp.afr.c
#	export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; ${SH} ${ROOT}/bin/4glpc -verbose -g -DPORTABLE -as-dll -I../../incl -L../../lib $^ -o $@ ${LINKLIBS}
#	gcc -shared -Wl,--out-implib=TMP.dll.a -Wl,--export-all-symbols -I../../incl -o $@ $^ -L.. -laubit4gl
#WARNING: cannot use 4glc directly, because of broken getopt_long() on CygWin (-o will not be recognized)
#	export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; ${4GLC} --verbose --shared -DPORTABLE $^ -o $@ -I../../incl -L../../lib ${LINKLIBS}
	${LD} ${SO_LDFLAGS} -g -DPORTABLE -o $@ $^ -I${ROOT}/incl -L${ROOT}/lib -laubit4gl
#gcc -shared  -o  -L"/usr/src/aubit/aubit4glsrc/lib" -laubit4gl helplib.c a4gl_xxhelp.afr.c -o ../libHELP_std.dll -I../../incl -L../../lib  -DPORTABLE  -I"/usr/src/aubit/aubit4glsrc/incl" -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include
#gcc  -DSRC_TREE -g -DPORTABLE -shared helplib.c a4gl_xxhelp.afr.c -o  ../libHELP_std.dll -lwsock32 -ID:/cygwin/usr/src/aubit/aubit4glsrc/incl -ID:/cygwin/usr/src/aubit/aubit4glsrc/incl -LD:/cygwin/usr/src/aubit/aubit4glsrc/lib -L/usr/src/aubit/aubit4glsrc/lib -laubit4gl -L/usr/local/lib
	@echo "Help library sucesfully compiled."


## ==================================================================
##                              Sub-targets
## ==================================================================


helplib.${FGLC_OUTPUT_EXT}: helplib.4gl
	export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; ${4GLC}  --namespace "aclfgli_" $^

a4gl_xxhelp.afr.c: a4gl_xxhelp.per
	(export A4GL_PACKER=PACKED; export A4GL_FORMTYPE=GENERIC; export A4GL_SQLTYPE=nosql; ${FCOMPILE} -c $^)

## ==================================================================
##                              Clean
## ==================================================================

clean:
	rm -f a4gl_xxhelp.afr.c ${LIBROOT}/libHELP_std${SO_EXT} \
	a4gl_xxhelp.afr.dat helplib.${FGLC_OUTPUT_EXT} helplib.c helplib.ec helplib.glb helplib.h *.err *.bak debug.out

# =============================== EOF ================================
