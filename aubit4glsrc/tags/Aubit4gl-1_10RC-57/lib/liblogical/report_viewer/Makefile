# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   lib/libgui makefile		 |
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
# $Id: Makefile,v 1.14 2007-05-10 21:07:48 mikeaubury Exp $
#

ROOT		=../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              GTK+ Options
## ==================================================================

CFLAGS			+=${GTK_INC_PATH} ${GTK_LIB_PATH}
HOSTNAME		:=$(shell echo $$HOSTNAME)

ifeq "${WIN_PATH}" "1"
#ifeq "" "$(findstring cygdrive,${GTK_INC_PATH})"
ifeq "" "$(findstring :,${GTK_INC_PATH})"
	#GTK installed inside CygWin tree - need to translate to Windows path
	#under cygwin path /usr/lib/ is actailly a symling to /lib, but "real" Windows
	#app (like MingGW) don't know anythign about links! So for now we will add path to
	#there.   -ID:/cygwin/usr/lib/glib-2.0/include
	ADD_ME			=-I${WIN_CYGPATH}/lib/glib-2.0/include \
					-I${WIN_CYGPATH}/lib/gtk-2.0/include

	GLIB_CFLAGS		:=$(subst -I,-I${WIN_CYGPATH},${GLIB_CFLAGS}) ${ADD_ME}
	GTK_INC_PATH	:=$(subst -I,-I${WIN_CYGPATH},${GTK_INC_PATH}) ${ADD_ME}
	GTK_LIB_PATH	:=$(subst -L,-L${WIN_CYGPATH},${GTK_LIB_PATH}) -L${WIN_CYGPATH}/lib
endif
#endif
endif

GTKLIBS				:=$(subst -rdynamic,,${GTKLIBS}) 

#Need to find better sollution for this:
#dropline.net and other installers have -lintl, but zip has -lintl-1
#ifeq "${HOSTNAME}" "istation"
#	GTKLIBS			:=$(subst -lintl,-lintl-1,${GTKLIBS})
#endif

CFLAGS				+=-I.. -I. -I${ROOT}/incl ${GLIB_CFLAGS} ${GTK_INC_PATH} \
					${GTK_LIB_PATH} -I/usr/local/include/ncurses

CFLAGS				:=$(subst /target/build,/usr,${CFLAGS})
GTK_LIB_PATH    	:=$(subst /target/build,/usr,${GTK_LIB_PATH})

CFLAGS		 		:=$(subst /target,/usr,${CFLAGS})
#CFLAGS				+=-fPIC
GTK_LIB_PATH 		:=$(subst /target,/usr,${GTK_LIB_PATH})

#-mms-bitfields or -fnative-struct

ifeq "${WIN_PATH}" "1"
ifeq "" "$(findstring :,${GTK_LIB_PATH})"
	GTK_LIB_PATH 	:=$(subst -L,-L${WIN_CYGPATH},${GTK_LIB_PATH})  -L${WIN_CYGPATH}/lib
endif
endif

ifeq "${GTKBUILD}" "yes"
	ALL+=${ROOT}/bin/report_viewer
endif

## ==================================================================
##                              Options
## ==================================================================

#LFLAGS=` pkg-config --libs --cflags gtk+-2.0` 

LINKLIBS	=-L$(AUBITDIR)/lib -l${AUBITLIBFULL} 

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}

${ROOT}/bin/report_viewer: report_viewer.c main.c ../common/a4gl_lle.o
#	${CC} -g $^ -o $@ ${LFLAGS} -I$(AUBITDIR)/incl
	${LD} ${GTK_LIB_PATH} ${GTK_INC_PATH} ${LDFLAGS} ${CFLAGS} -o $@ $^ ${LINKLIBS} ${GTKLIBS} ${EXTRASYSTEMLIBS}

## ==================================================================
##                              Clean
## ==================================================================

clean: 
	${RM} ${ROOT}/bin/report_viewer *.o *.dll.a *~
	
	
