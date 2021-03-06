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
# $Id: Makefile,v 1.10 2008-11-06 13:30:19 mikeaubury Exp $
#

ROOT		=../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common
HOSTNAME		:=$(shell echo $$HOSTNAME)

.PHONY: all clean 

## ==================================================================
##                              GTK+ Options
## ==================================================================

CFLAGS+=-g ${GTK_INC_PATH} ${GTK_LIB_PATH}

ifeq "${WIN_PATH}" "1"
#ifeq "" "$(findstring cygdrive,${GTK_INC_PATH})"
ifeq "" "$(findstring :,${GTK_INC_PATH})"
#GTK installed inside CygWin tree - need to translate to Windows path
	#under cygwin path /usr/lib/ is actailly a symling to /lib, but "real" Windows
	#app (like MingGW) don't know anythign about links! So for now we will add path to
	#there.   -ID:/cygwin/usr/lib/glib-2.0/include
	ADD_ME		=-I${WIN_CYGPATH}/lib/glib-2.0/include \
					-I${WIN_CYGPATH}/lib/gtk-2.0/include
	GLIB_CFLAGS		:=$(subst -I,-I${WIN_CYGPATH},${GLIB_CFLAGS}) ${ADD_ME}
	GTK_INC_PATH	:=$(subst -I,-I${WIN_CYGPATH},${GTK_INC_PATH}) ${ADD_ME}
	GTK_LIB_PATH	:=$(subst -L,-L${WIN_CYGPATH},${GTK_LIB_PATH}) -L${WIN_CYGPATH}/lib
endif
#endif
endif

GTKLIBS			:=$(subst -rdynamic,,${GTKLIBS}) 

#Need to find better sollution for this:
#dropline.net and other installers have -lintl, but zip has -lintl-1
#ifeq "${HOSTNAME}" "istation"
#	GTKLIBS			:=$(subst -lintl,-lintl-1,${GTKLIBS})
#endif

CFLAGS				+=-I.. -I. -I${ROOT}/incl ${GLIB_CFLAGS} ${GTK_INC_PATH} \
					${GTK_LIB_PATH} -I/usr/local/include/ncurses -I/usr/local/include

CFLAGS				:=$(subst /target/build,/usr,${CFLAGS})
GTK_LIB_PATH   		:=$(subst /target/build,/usr,${GTK_LIB_PATH})

CFLAGS		 		:=$(subst /target,/usr,${CFLAGS})
CFLAGS				+=${PIC}
GTK_LIB_PATH 		:=$(subst /target,/usr,${GTK_LIB_PATH})

#-mms-bitfields or -fnative-struct

ifeq "${WIN_PATH}" "1"
ifeq "" "$(findstring :,${GTK_LIB_PATH})"
	GTK_LIB_PATH 	:=$(subst -L,-L${WIN_CYGPATH},${GTK_LIB_PATH})  -L${WIN_CYGPATH}/lib
endif
endif

#we don't want -Wall in CFLAGS when compiling form_x_xdr.c because it would
#give us bunch of warnings about unised varibles, that we cannot fix
#because this file is generated by rpcgen:
CFLAGS_FORM_X_XDR_C =$(CFLAGS:%-Wall=%)

# We don't want -Wmissing-declarations and -Wmissing-prototypes when
# compiling C code created by 4glc, since it is not creating prototypes,
# so we get lots of warnings:
CFLAGS_4GLC2 		=$(CFLAGS:%-Wmissing-declarations=%)
CFLAGS_4GLC1 		=$(CFLAGS_4GLC2:%-Wmissing-prototypes=%)
CFLAGS_4GLC 		=$(CFLAGS_4GLC1:%-Wstrict-prototypes=%)

#we cannot compile GTK code with  -Wstrict-prototypes because
#GTK+ supplied libraries have many functions declared without parameters
CFLAGS_GTK_C 		=$(CFLAGS:%-Wstrict-prototypes=%)

#Fails with error: initializer element is not computable at load time:
ifeq "${NON_PEDANTIC_OK}" "1"
	CFLAGS_4GLC 	:=$(CFLAGS_4GLC:%-pedantic=%)
endif

ifeq "${GTKBUILD}" "yes"
	ALL				+=${PLUGINDIR}/libUI_HL_GTK${SO_EXT}
endif

## ==================================================================
##                              Curses Options
## ==================================================================

PDCURSESX_CFLAGS	=${XCURSES_CFLAGS} -DXCURSES -I${ROOT}/incl -I.. \
	${CWARN} -DSRC_TREE -DDEBUG -DHAVE_CONFIG_H
	
ifneq "${HAVE_CURSES}" "0"
	ALL					+=${PLUGINDIR}/libUI_HL_TUI${SO_EXT} ${PLUGINDIR}/libUI_HL_TUIN${SO_EXT}
	#CURSES_INC_PATH must be BEFORE system paths:
	#Note: On CygWin term.h is in -I/usr/include/ncurses
	CFLAGS				:=${CURSES_INC_PATH} -I/usr/include/ncurses ${CFLAGS}
else
	ifneq "${HAVE_PDCURSES}" "0"
		ALL				+=${PLUGINDIR}/libUI_HL_TUIN${SO_EXT}
		DO_PDCURSES		=1
	endif
	ifneq "${HAS_PDCURSES_STATIC_OBJS}" "0"
		ALL				+=${PLUGINDIR}/libUI_HL_TUINs${SO_EXT}
		ALL				+=${PLUGINDIR}/libUI_HL_TUIw${SO_EXT}
		DO_PDCURSES		=1
	endif
		
	ifeq "${DO_PDCURSES}" "1"
		CURSES_LIB_PATH	=${PD_CURSES_LIB_PATH}
		CURSES_INC_PATH	=${PD_CURSES_INC_PATH}
		CURSES_LIB_NAME	=${PD_CURSES_LIB_NAME}

		ifeq "${WIN_PATH}" "1"
			#CURSES_LIB_PATH 	:=$(subst -L/cygdrive/d,-Ld:,${CURSES_LIB_PATH})
			#CURSES_INC_PATH 	:=$(subst -I/cygdrive/d,-Id:,${CURSES_INC_PATH})
			#CURSES_LIB_NAME 	:=$(subst /cygdrive/d,d:,${CURSES_LIB_NAME})
			CURSES_LIB_PATH 	:=$(subst -L${PD_CURSES_CYGDRIVE},-L${PD_CURSES_DRIVE}:,${CURSES_LIB_PATH})
			CURSES_INC_PATH 	:=$(subst -I${PD_CURSES_CYGDRIVE},-I${PD_CURSES_DRIVE}:,${CURSES_INC_PATH})
			CURSES_LIB_NAME 	:=$(subst ${PD_CURSES_CYGDRIVE},${PD_CURSES_DRIVE}:,${CURSES_LIB_NAME})
			#CURSES_LIB_NAME 	:=$(subst /cygdrive/d,d:,${CURSES_LIB_NAME}) d:/pdc25_vc_w32/panel.lib
			#CURSES_LIB_NAME=d:/pdc25_vc_w32/curses.dll d:/pdc25_vc_w32/panel.lib
		endif

		#CURSES_INC_PATH must be BEFORE system paths:
		CFLAGS			:=${CURSES_INC_PATH} ${CFLAGS}
	endif
endif

CFLAGS					+=-I.. -I. -I${ROOT}/incl

ifeq "${NON_PEDANTIC_OK}" "1"
	CFLAGS_NO_PEDANTIC  =$(CFLAGS:%-pedantic=%)
else
	CFLAGS_NO_PEDANTIC  =${CFLAGS}
endif

CURSES_LIB_NAME_NO_FORM	=$(CURSES_LIB_NAME:%-lform=%)

## ==================================================================
##                              Common Options
## ==================================================================


ifneq "${COMSPEC}" ""
	LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
endif

CFLAGS			+=-g -I${ROOT}/incl -I.. -I${LIBROOT}/libaubit4gl

## ==================================================================
##                              Source files
## ==================================================================

OBJS	=forms.o generic_ui.o menu.o display_array.o formcntrl.o input_array.o common_hlui.o misc.o 
OBJS2	=lowlevel_tui.o width_narrow.o
OBJS4	=lowlevel_tui_noform_wide.o form_tui.o width_wide.o
OBJS5	=lowlevel_gtk.o widget_gtk.o menu_gtk.o width_narrow.o

LIBS3	=-lpanel_g -lncurses_g -lgpm

PDCURSES_OBJ		=lowlevel_tui_noform.o form_tui.o width_narrow.o
PDCURSESX_OBJ		=lowlevel_tui_noformX.o form_tuiX.o width_narrow.o

## ==================================================================
##                              Targets
## ==================================================================

all: a4gl_API_lowlevel.h ${ALL}
	@echo "Default trgets (${ALL}) compiled sucessfuly."


#What was this is should it be removed completely? Mike?
#${LIBROOT}/libUI_HLGENERIC${SO_EXT}: $(OBJS) API_lowlevel.o
#	gcc -L${ROOT}/lib -rdynamic -shared $(OBJS) API_lowlevel.o -o $@ -l${AUBITLIBFULL}
#	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}

#Standard Curses based plug-in
#${PLUGINDIR}/libUI_HL_TUI${SO_EXT}: ${PLUGINDIR}/libUI_HL_TUI${SO_EXT}
${PLUGINDIR}/libUI_HL_TUI${SO_EXT}:  $(OBJS) ${OBJS2} 
	${LD} ${CURSES_LIB_PATH} ${SO_LDFLAGS} -o $@ $(OBJS) ${OBJS2} \
		${LINKLIBS} ${CURSES_LIB_NAME} 

TUIw: ${PLUGINDIR}/libUI_HL_TUIw${SO_EXT}

#PDcurses with libform from CygWin added
libUI_HL_TUIw${SO_EXT}: ${PLUGINDIR}/libUI_HL_TUIw${SO_EXT}
${PLUGINDIR}/libUI_HL_TUIw${SO_EXT}: $(OBJS) lowlevel_tui_win32.o width_narrow.o
	${LD} ${CURSES_LIB_PATH} ${SO_LDFLAGS} -o $@ $(OBJS) lowlevel_tui_win32.o width_narrow.o \
		${LINKLIBS} -L$(ROOT)/tools/cygwin/libform -lform ${CURSES_LIB_NAME} 

#PDcurses with libform from CygWin added - STATICALLY linked
libUI_HL_TUIws${SO_EXT}: ${PLUGINDIR}/libUI_HL_TUIws${SO_EXT}
${PLUGINDIR}/libUI_HL_TUIws${SO_EXT}: $(OBJS) lowlevel_tui_win32.o width_narrow.o
	${LD} ${CURSES_LIB_PATH} ${SO_LDFLAGS} -o $@ $(OBJS) lowlevel_tui_win32.o width_narrow.o \
		${LINKLIBS} -L$(ROOT)/tools/cygwin/libform -lform_g ${CURSES_LIB_NAME} 

#TUI mode plug-in with Aubit's own implementation of Curses libform
#This also enables PDcurses to be used instead of Ncurses, since PDcurses have 
#no libform implementation (PDcurses are only Curses implementation available for Windows)
libUI_HL_TUIN${SO_EXT}: ${PLUGINDIR}/libUI_HL_TUIN${SO_EXT}
${PLUGINDIR}/libUI_HL_TUIN${SO_EXT}: $(OBJS) ${PDCURSES_OBJ}
	${LD} ${CURSES_LIB_PATH} ${SO_LDFLAGS} -o $@ $(OBJS) ${PDCURSES_OBJ} \
		${LINKLIBS} ${CURSES_LIB_NAME_NO_FORM}  

#Statically linked TUIN
libUI_HL_TUINs${SO_EXT}: ${PLUGINDIR}/libUI_HL_TUINs${SO_EXT}
${PLUGINDIR}/libUI_HL_TUINs${SO_EXT}: $(OBJS) ${PDCURSES_OBJ}
	${LD} ${CURSES_LIB_PATH} ${SO_LDFLAGS} -o $@ $(OBJS) ${PDCURSES_OBJ} \
		${LINKLIBS} ${PD_CURSES_LIB_NAME}

#Debug version of TUIN, using debug library libpanel_g
libUI_HL_TUIN-DEBUG${SO_EXT}: ${PLUGINDIR}/libUI_HL_TUIN-DEBUG${SO_EXT}
${PLUGINDIR}/libUI_HL_TUIN-DEBUG${SO_EXT}: $(OBJS) ${PDCURSES_OBJ}
	${LD} ${CURSES_LIB_PATH} ${SO_LDFLAGS} -o $@ $(OBJS) ${PDCURSES_OBJ} \
		${LINKLIBS} ${LIBS3}

#Not shure what this is? Mike?
libUI_HL_TUINW${SO_EXT}: ${PLUGINDIR}/libUI_HL_TUINW${SO_EXT}
${PLUGINDIR}/libUI_HL_TUINW${SO_EXT}: $(OBJS) ${OBJS4}
	${LD} ${CURSES_LIB_PATH} ${SO_LDFLAGS} -o $@ $(OBJS) ${OBJS4} ${LINKLIBS} \
		-L/usr/local/widec/lib -static -lpanelw_g -lncursesw_g

#TUI linked with Xcurses from PDcurses
#
#To use XCurses with an existing curses program, you need to make one
#      change to your code:
#      Call XCursesExit() just before exiting from your program. eg.
#     
#     #ifdef XCURSES
#      XCursesExit();
#     #endif
#      exit(0);
#     
#      This call is required to enable the child X process to shut down cleanly
#      and free up the shared memory it used.
#
#${PLUGINDIR}/libUI_HL_TUIX${SO_EXT}: ${PLUGINDIR}/libUI_HL_TUIX${SO_EXT}
${PLUGINDIR}/libUI_HL_TUIX${SO_EXT}: CFLAGS=${PDCURSESX_CFLAGS}
${PLUGINDIR}/libUI_HL_TUIX${SO_EXT}: $(OBJS) ${PDCURSESX_OBJ} 
	${LD} ${SO_LDFLAGS} -o $@ $(OBJS) ${PDCURSESX_OBJ} ${LINKLIBS} \
		${XCURSES_LIBS} -lXpanel
	
	
#Standard GTK+ based plug-in
#${PLUGINDIR}/libUI_HL_GTK${SO_EXT}: ${PLUGINDIR}/libUI_HL_GTK${SO_EXT}
${PLUGINDIR}/libUI_HL_GTK${SO_EXT}: $(OBJS) ${OBJS5}
	${LD} ${GTK_LIB_PATH} ${SO_LDFLAGS} ${PIC} -o $@ $(OBJS) ${OBJS5} \
		${LINKLIBS} ${GTKLIBS} ${RDYNAMIC} -L/opt/gnome/lib  ${GTKLIBS}

## ==================================================================
##                              Sub-Targets
## ==================================================================

#API_lowlevel.c: ${LIBROOT}/libaubit4gl/API_lowlevel.spec API_lowlevel.h a4gl_API_lowlevel.h
#	(cd ${LIBROOT}/libaubit4gl && ${SH} ../bin/dlmagic ./API_lowlevel.spec > ../libui/ui_highlevel/API_lowlevel.c)

#so is it now only this one, or...
a4gl_API_lowlevel.h: ${LIBROOT}/libaubit4gl/API_lowlevel.spec
	${SH} ${LIBROOT}/bin/dlmagic $^ -h > $@

width_narrow.o: width.c
	${CC} -DNO_WIDEC  ${CFLAGS} -c -o $@ $^

width_wide.o: width.c
	${CC} -DWIDEC  ${CFLAGS} -c -o $@ $^

lowlevel_tui.o: lowlevel/lowlevel_tui.c a4gl_API_lowlevel.h
	${CC} ${CFLAGS} -I$(ROOT)/incl -I. -Ilowlevel -c -o $@ $<

lowlevel_tui_win32.o: lowlevel/lowlevel_tui.c a4gl_API_lowlevel.h
	${CC} ${CFLAGS} -I$(ROOT)/tools/cygwin/libform -I$(ROOT)/incl -I. -Ilowlevel  -c -o $@ $<

lowlevel_thin.o: lowlevel/lowlevel_thin.c
	${CC} ${CFLAGS} -I$(ROOT)/incl -I. -Ilowlevel -c -o $@ $^

lowlevel_tui_noform.o: lowlevel/lowlevel_tui.c a4gl_API_lowlevel.h
	${CC} ${CFLAGS} -DNO_CURSES_FORM -I$(ROOT)/incl -I. -Ilowlevel -c -o $@ $<

lowlevel_tui_noformX.o: lowlevel/lowlevel_tui.c
#Cant use warning flags here - xcurses headers produce flood of warnings 
#and there is nothing we can do about it ...
	${CC} $(filter-out ${CWARN},${PDCURSESX_CFLAGS}) -DNO_CURSES_FORM -Ilowlevel -I.  -c -o $@ $^
	
lowlevel_tui_noform_wide.o: lowlevel/lowlevel_tui.c
	${CC} ${CFLAGS} -DWIDEC -DNO_CURSES_FORM -c -I$(ROOT)/incl -I. -Ilowlevel -c -o $@ $^

form_tui.o: lowlevel/form_tui.c
	${CC} ${CFLAGS} -c -I$(ROOT)/incl -I. -Ilowlevel -c -o $@ $^

form_tuiX.o: lowlevel/form_tui.c
#Cant use warning flags here - xcurses headers produce flood of warnings 
#and there is nothing we can do about it ...
#NOTE: we still get some warnings here from PDcurses headers
	${CC} $(filter-out ${CWARN},${PDCURSESX_CFLAGS}) -DNO_CURSES_FORM -c -Ilowlevel -I. $^ -o $@

lowlevel_gtk.o: lowlevel/lowlevel_gtk.c a4gl_API_lowlevel.h
	${CC} ${CFLAGS_GTK_C} -c -I$(ROOT)/incl -I. -Ilowlevel $< -o $@ $(GTK_INC_PATH)

widget_gtk.o: lowlevel/widget_gtk.c
	${CC} ${CFLAGS_GTK_C} -c -I$(ROOT)/incl -I. -Ilowlevel $^ -o $@ $(GTK_INC_PATH)

menu_gtk.o: lowlevel/menu_gtk.c
	${CC} ${CFLAGS_GTK_C} -c -I$(ROOT)/incl -I../../../common/dataio -I. \
		-Ilowlevel $^ -o $@ $(GTK_INC_PATH)

## ==================================================================
##                              Dependencies
## ==================================================================

#Rule to generate API's:
${ROOT}/incl/a4gl_API_%.h :
	${MAKE} -C ${LIBROOT}/libaubit4gl api

${OBJS} :  a4gl_API_lowlevel.h

## ==================================================================
##                              Test
## ==================================================================

testit:  $(OBJS) testit.o API_lowlevel.o
	${CC} ${CURSES_LIB_PATH} -L${ROOT}/lib $^  -o testit -l${AUBITLIBFULL} ${CURSES_LIB_NAME} 

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
	@echo "HAS_PDCURSES_STATIC_OBJS=${HAS_PDCURSES_STATIC_OBJS}"
	@echo "DO_PDCURSES=${DO_PDCURSES}"	
	@echo "XCURSES_CFLAGS=${XCURSES_CFLAGS}"
	@echo "XCURSES_LIBS=${XCURSES_LIBS}"
	@echo "PLUGINDIR=${PLUGINDIR}"
	@echo "AUBIT_SRC_ROOT=${AUBIT_SRC_ROOT}"
	
## ==================================================================
##                              Clean
## ==================================================================

cleanish: clean.capi
	${RM} *${SO_EXT} *.o *.bak testit API_lowlevel.c API_lowlevel.h \
	lowlevel/*.bak remote_client/*.o 

clean: cleanish
	${RM} ${PLUGINDIR}/libUI_HL_GTK${SO_EXT} \
		${PLUGINDIR}/libUI_HL_TUI${SO_EXT} \
		${PLUGINDIR}/libUI_HL_TUIN${SO_EXT} \
		${PLUGINDIR}/libUI_HL_TUIN-DEBUG${SO_EXT} \
		${PLUGINDIR}/libUI_HL_TUINW${SO_EXT} \
		${PLUGINDIR}/libUI_HL_TUINs${SO_EXT} \
		${PLUGINDIR}/libUI_HL_TUIX${SO_EXT} \
		${PLUGINDIR}/libUI_HL_TUIw${SO_EXT} \
		${PLUGINDIR}/libUI_HL_TUIws${SO_EXT} 

clean_hl_tui : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_TUI${SO_EXT} 

clean_hl_tuiw : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_TUIw${SO_EXT} 

clean_hl_tuiws : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_TUIws${SO_EXT} 

clean_hl_tuin : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_TUIN${SO_EXT} 

clean_hl_tuins : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_TUINs${SO_EXT} 

clean_hl_tuind : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_TUIN-DEBUG${SO_EXT} 

clean_hl_tuinw : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_TUIw${SO_EXT} 

clean_hl_tuix : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_TUIX${SO_EXT} 

clean_hl_gtk : cleanish
		${RM} ${PLUGINDIR}/libUI_HL_GTK${SO_EXT} 

## ==================================================================
##                     CORBA/ORBit settings
## ==================================================================

IDLMAGIC		=${LIBROOT}/bin/idlmagic
ifeq "${HAS_ORBIT_TYPE}" "2"
	#CAPI_CFLAGS=$(shell pkg-config ORBit-2.0 ORBit-CosNaming-2.0 --cflags)
	#CAPI_LDFLAGS=$(shell pkg-config ORBit-2.0 ORBit-CosNaming-2.0 --libs)
else
	#there is apparently no diff between client and server targets:
	#CAPI_CFLAGS=$(shell orbit-config --cflags client)
	#CAPI_LDFLAGS=$(shell orbit-config --libs client)
endif
#ORBIT_NAME		=ORBit-2.0
#ORBIT_VERSION	=2.6.3
#ORBIT_CONFIG		=

ifneq "${TARGET_OS}" "hpux"
	ifneq "${TARGET_OS}" "cygwin"
		ifneq "${GCC_MINGW}" "yes"
            #all platforms except HP-UX, CygWin and MinGW:
			LINK_LIBS_SERVER           =-ldl -lm
		endif
	endif
else
            #HP-UX only:
			LINK_LIBS_SERVER           =-lcl -lm -lnsl
endif

#this would actually applies to WHOLE makefile not just from this point down
#and it caused UI_HL_GTK to fail when using GTK2 on armada
#CFLAGS	:=${CAPI_CFLAGS} ${CFLAGS}
#-D__CAPI__

#Names of all Aubit interfaces to create CORBA APIs and cleants/servers for:
API_NAMES		=sqlparse
API_NAMES_UP	=${shell  echo "${API_NAMES}" | tr a-z A-Z   }

CLIENTS			=$(foreach api_name,${API_NAMES},lib${api_name}_CLIENT${SO_EXT})
SERVERS			=$(foreach api_name,${API_NAMES},${api_name}-server${EXE_EXT})

#Functions needed to pupport dlopen of 'real' plug-in on SERVER side"
#A4GL_dl_openlibrary A4GL_find_func_allow_missing A4GL_find_func - libaubit4gl/calldll.c
#acl_getenv - resource/resource.c
#A4GL_exitwith - libaubit4gl/error.c

DLOPEN_SUPPORT= ${LIBROOT}/libaubit4gl/calldll.o \
				${LIBROOT}/resource/resource.o \
				${LIBROOT}/libaubit4gl/error.o \
				${LIBROOT}/libaubit4gl/pointers.o 

#Prevent 'make' from deleting our intermedate files:
.SECONDARY:

## ==================================================================
##                        CORBA/ORBit targets
## ==================================================================

#######################################
#Create all Aubit CORBA clients and servers
capi: clean.capi capi.clients capi.servers
	@echo "CORBA API clients/servers created:"
	@echo "${CLIENTS} ${SERVERS}"


#######################################
#Create all Aubit CORBA clients (plug-ins)
capi.clients: ${CLIENTS}
	@echo "CORBA API clients created:"
	@echo "${CLIENTS}"

#######################################
#Create all Aubit CORBA servers (executables that load 'real' plug-ins)
capi.servers: ${SERVERS}
	@echo "CORBA API servers created:"
	@echo "${SERVERS}"

######################################
#Create Aubit CORBA plug-in for % API
lib%_CLIENT${SO_EXT}: CFLAGS:=${CAPI_CFLAGS} ${CFLAGS} -D__CAPI__ 
lib%_CLIENT${SO_EXT}: CAPI_%-common.o CAPI_%-stubs.o CAPI_%-client.o \
	CLIENT_corba_server_util.o
	${LD} ${SO_LDFLAGS} ${CAPI_LDFLAGS} -o $@ $^
	cp $@ ${LIBROOT}/lib${shell echo "$*" | tr a-z A-Z }_CLIENT${SO_EXT}
	@echo "Created: ${LIBROOT}/lib${shell echo "$*" | tr a-z A-Z }_CLIENT${SO_EXT}"


#######################################
#Create Aubit plug-in CORBA server for % API
%-server${EXE_EXT}: CFLAGS:=${CAPI_CFLAGS} ${CFLAGS} -D__CAPI__
%-server${EXE_EXT}: CAPI_%-common.o CAPI_%-skels.o CAPI_%-skelimpl.o \
	CAPI_%-server.o ${DLOPEN_SUPPORT} ${LIBROOT}/libaubit4gl/API_%.o \
	SERVER_corba_server_util.o 
#	CAPI_corba_server_util.o
	${CC} ${LDFLAGS} ${CAPI_LDFLAGS} -o $@ $^ ${LINK_LIBS_SERVER}


## ==================================================================
##                        CORBA/ORBit sub-targets
## ==================================================================

####################################
#Compile a separate object specifically for use in CORBA server (with -D__CAPI__)
SERVER_corba_server_util.o: ${LIBROOT}/libaubit4gl/corba_server_util.c
	${CC} ${CFLAGS} -c $^ -o $@ -D__CSERVER__ -D__CAPI__ 
CLIENT_corba_server_util.o: ${LIBROOT}/libaubit4gl/corba_server_util.c
	${CC} ${CFLAGS} -c $^ -o $@ -D__CCLIENT__ -D__CAPI__
#CAPI_corba_server_util.o: ${LIBROOT}/libaubit4gl/corba_server_util.c
#	${CC} ${CFLAGS} -c $^ -o $@ -D__CAPI__

${DLOPEN_SUPPORT} ${LIBROOT}/libaubit4gl/API_%.o :
	${MAKE} -C ${LIBROOT}/libaubit4gl
	
####################################
#Create C function call wraper for CORBA client, from Aubit API .spec file
#Calls to xxx() function are just forwarded to CORBA_xxx() function which is 
#created by ORBIT_IDL from .idl file in turn created fron this same .spec file
CAPI_%-client.c: ${LIBROOT}/libaubit4gl/API_%.spec ${IDLMAGIC}
	${SH} ${IDLMAGIC} $< -client > $@

####################################
#Create C function call wraper for CORBA server, from Aubit API .spec file
#Calls to CORBA_xxx() function are just forwarded to xxx() function, which
#is expected to be handled by normal Aubit API_xx.c code and forwarded 
#to 'normal' Aubit plug-in
CAPI_%-server.c: ${LIBROOT}/libaubit4gl/API_%.spec ${IDLMAGIC}
	${SH} ${IDLMAGIC} $< -server > $@
	
#######################################
#Create skelimpl C code from .idl specification
CAPI_%-skelimpl.c: CAPI_%.idl ${IDLMAGIC}
#CAPI_%.h CAPI_%-common.c CAPI_%-stubs.c CAPI_%-skels.c CAPI_%-skelimpl.c: CAPI_%.idl
	${RM} CAPI_$*-skelimpl.c
	$(ORBIT_IDL) --skeleton-impl $<
#Check if ORBIT_IDL worked OK, since it does not return error code on exit:
	@if test -f CAPI_$*-skelimpl.c; then echo "$(ORBIT_IDL) OK"; else echo "$(ORBIT_IDL) ERROR"; exit 1; fi
#Add additional functions to -skelimpl:
	${SH} ${IDLMAGIC} ${LIBROOT}/libaubit4gl/API_$*.spec -add-to-skelimpl >> $@
#re-read just generated -skelimpl.c and insert function calls to our actuall functions:
	mv $@ $@-tmp
	${SH} ${IDLMAGIC} ${LIBROOT}/libaubit4gl/API_$*.spec -add-func-calls $@-tmp > $@
	${RM} $@-tmp
	@echo "OK: $@ created."
	
#eee:
#	${SH} ${IDLMAGIC} ${LIBROOT}/libaubit4gl/API_sqlparse.spec -add-func-calls

	
#######################################
#Create all needed (except skelimpl) CORBA C code from .idl specification
CAPI_%.h CAPI_%-common.c CAPI_%-stubs.c CAPI_%-skels.c: CAPI_%.idl
	${RM} CAPI_$*.h CAPI_$*-common.c CAPI_$*-stubs.c CAPI_$*-skels.c
	$(ORBIT_IDL) $^
	@if test -f CAPI_$*.h; then echo "$(ORBIT_IDL) OK"; else echo "$(ORBIT_IDL) ERROR"; exit 1; fi
	
#######################################
#Create CORBA .idl specification from Aubit API .spec file
CAPI_%.idl: ${LIBROOT}/libaubit4gl/API_%.spec ${IDLMAGIC}
	${SH} ${IDLMAGIC} $< > $@

## ==================================================================
##                        CORBA/ORBit clean targets
## ==================================================================

#######################################
#Clean all CAPI intermedate files
clean.capi:
	${RM} CAPI_*-common.c CAPI_*.h CAPI_*.idl CAPI_*-skels.c CAPI_*-stubs.c \
		CAPI_*-skelimpl.c *~ *.ior *.ref *.o \
		CAPI_*-client.c CAPI_*-server.c *.c-tmp *-server${EXE_EXT}
		
#######################################
#Clean all CAPI intermedate files and targets
#NOTE: cleans only local targets in this this dir, not lib/ or bin/
clean.capi.distclean: clean.capi
	${RM} ${CLIENTS} ${SERVERS}


show.capi:
	@echo "HAS_ORBIT_TYPE	=${HAS_ORBIT_TYPE}"
	@echo "ORBIT_IDL		=${ORBIT_IDL}"
	@echo "ORBIT_NAME		=${ORBIT_NAME}"
	@echo "ORBIT_VERSION	=${ORBIT_VERSION}"
	@echo "CAPI_LDFLAGS		=${CAPI_LDFLAGS}"
	@echo "CAPI_CFLAGS		=${CAPI_CFLAGS}"
	@echo "ORBIT_CONFIG		=${ORBIT_CONFIG}"

	
#################################### EOF ###################################


