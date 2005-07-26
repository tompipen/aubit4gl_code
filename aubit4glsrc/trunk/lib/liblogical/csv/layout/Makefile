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
# $Id: Makefile,v 1.10 2005-07-26 16:20:18 mikeaubury Exp $
#

LIBROOT		=../../..
ROOT		=../../../..

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
	ALL+=${LIBROOT}/libLOGREP_CSV${SO_EXT}
endif

## ==================================================================
##                              Options
## ==================================================================

#CFLAGS=-I$(ROOT)/lib/libaubit4gl -I$(ROOT)/incl \
#	`pkg-config --libs --cflags gtk+-2.0` \
#	-I../common -I../../common -Wall -rdynamic -shared -g

CFLAGS		+=-I$(ROOT)/lib/libaubit4gl -I$(ROOT)/incl -I../common -I../../common
LINKLIBS	=-L$(ROOT)/lib -laubit4gl

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}

${LIBROOT}/libLOGREP_CSV${SO_EXT} : layout_csv.c ../common/csv_io.c
#	${CC} ${CFLAGS} $^ -o $@ -L$(ROOT)/lib -laubit4gl
#	${LD} ${GTK_LIB_PATH} ${SO_LDFLAGS} -fPIC -o $@ $^ ${LINKLIBS} ${GTKLIBS} -Wl,--export-dynamic -L/opt/gnome/lib  ${GTKLIBS}
	${LD} ${GTK_LIB_PATH} ${GTK_INC_PATH} ${SO_LDFLAGS} ${CFLAGS} -o $@ $^ ${LINKLIBS} ${GTKLIBS}
#	-Wl,--export-dynamic
	
	
	
show:
	@echo "LINKLIBS=${LINKLIBS}"
	@echo "GTK_LIB_PATH=${GTK_LIB_PATH}" 
	@echo "GTKLIBS=${GTKLIBS}"
	@echo "CFLAGS_GTK_C=${CFLAGS_GTK_C}"
	@echo "CFLAGS=${CFLAGS}"
	@echo "HAVE_CURSES=${HAVE_CURSES}"
	@echo "CURSES_LIB_PATH=${CURSES_LIB_PATH}"
	@echo "CURSES_INC_PATH=${CURSES_INC_PATH}"
	@echo "CURSES_LIB_NAME=${CURSES_LIB_NAME}"
	@echo "HAVE_PDCURSES=${HAVE_PDCURSES}"	
	@echo "PD_CURSES_LIB_PATH=${PD_CURSES_LIB_PATH}"
	@echo "PD_CURSES_INC_PATH=${PD_CURSES_INC_PATH}"
	@echo "PD_CURSES_LIB_NAME=${PD_CURSES_LIB_NAME}"
	@echo "WIN_PATH=${WIN_PATH}"
	@echo "PD_CURSES_CYGDRIVE=${PD_CURSES_CYGDRIVE}"
	@echo "PD_CURSES_DRIVE=${PD_CURSES_DRIVE}"
	@echo "HOSTNAME=${HOSTNAME}"
	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o ${LIBROOT}/libLOGREP_CSV${SO_EXT} *.dll.a *~ ../common/csv_io.o
	
	
