###########################################################################
#
#   @(#)$Id: q4gl.mk,v 1.15 2003-06-13 05:49:18 afalout Exp $
#
#   @(#)$Product: Aubit 4gl $
#
#   Makefile for Querix 4GL Compilation - based on i4gl.mk by JL
#
#--------------------------------------------------------------------------
# Note that this file does not define any targets; it only defines
# compilation rules and macros.
#--------------------------------------------------------------------------
# Under normal circumstances, you should not need to edit this file
#
###########################################################################

#FIXME: Querix have 4 possible combinations:
#Informix CUI, Informix GUI, Oracle CUI, Oracle GUI
#This makefile should be able to compile all of them:

#QUERIXDIR This is the subdirectory of the querix home directory
#(called qxNNN.f.ARCH) It should be set in system environment.

#MSGPATH This is the path to the Querix message directory. It is usually
#$QUERIXDIR/msg. DBLANG is used in conjunction with MSGPATH

#QXAWK This is the name of an nawk compatible awk program on your system.
#QXMAKE This is the name of the make program on your system.

##########################################################################
# Compilers and flags
##########################################################################

#/opt/querix/lib/ (V4)

#static only:
#libesql.a
#libesqld.a
#libq4gl.a

#Other:
#main.4gl
#q4gl.def
#Makedef
#4rules

#Shared link libraries:
#libssl.so
#libcrypto.so
#libltdl.so
#
#libfgld.so
#libfgl.so
#
#libsqlcd.so
#libsqlc.so

#Run-time Loadable modules:
#moddbdb2d.so
#moddbdb2.so
#
#moddboracle.so
#moddboracled.so
#
#modrephtmld.so
#modrephtml.so
#
#moddbdefaultd.so
#moddbdefault.so
#
#moddbinformixd.so
#moddbinformixqxd.so
#moddbinformixqx.so
#moddbinformix.so
#
#modwinguid.so
#modwingui.so

###########################
#Version of Querix compiler in use
Q4GL_VERSION        =4

###########################
#If this compilers needs objects ar run-time, set to 'yes':
Q4GL_INST_OBJ		=no

###########################
#If this compiler uses C compiler to create native executables, set thi to 'yes':
Q4GL_IS_C_COMPILER	=yes

###########################
#Set QXDB to "o" to use Querix Oracle compiler, or leave empty for Informix.
QXDB				=

###########################
#If you want to link with debug version of Querix libraries, set this to 'd',
#otherwise leave empty:
USE_DEBUG_LIBRARIES	=

###########################
#Extender libraries needed for GUI, HTML and SN Querix functionality extensions:
ifneq "${QUERIXDIR}" ""
    ifndef COMSPEC
		#loaded libraries list from .ext files contains make style variables, but they
		#are not automatically expanded in this context, so we have to do this manually:
		DOLLAR=$$
		LEFT=(
		RIGHT=)

		EXTENDERLIBS_GUI	=$(subst QUERIXDIR,$(QUERIXDIR),$(shell cat "${QUERIXDIR}/etc/gui.ext" 2>/dev/null))
		EXTENDERLIBS_GUI	:=$(subst USE_DEBUG_LIBRARIES,${USE_DEBUG_LIBRARIES},${EXTENDERLIBS_GUI})
		EXTENDERLIBS_GUI	:=$(subst ${DOLLAR},,${EXTENDERLIBS_GUI})
		EXTENDERLIBS_GUI	:=$(subst ${LEFT},,${EXTENDERLIBS_GUI})
		EXTENDERLIBS_GUI	:=$(subst ${RIGHT},,${EXTENDERLIBS_GUI})

		EXTENDERLIBS_HTML	=$(shell cat "${QUERIXDIR}/etc/html.ext" 2>/dev/null)
    endif
endif

###########################
#Set the following to 'yes", to activate linking with Querix extender libraries
#for particular extension
#WARNING: if you set EXTENDER_GUI=yes, you wil lnot be able to run the compiled
#program in TUI mode, you will get this error message:
#This is a Querix Hydra GUI compiled binary and cannot be run directly.
#To run this program please use on of our Client programs, such as Phoenix
# or Chimera.
EXTENDER_GUI        =no
EXTENDER_HTML       =no

###########################
#If you want to link with local, native Curses libraries, set this to 'yes';
#otherwise, Querix provided static Curses libraries will be linked
#QX_CURSES_LOCAL		=yes

ifndef COMSPEC
	ifeq "${QX_CURSES_LOCAL}" "yes"
		#FIXME: replace -lcurses with value assigned by autoconf (can be ncurses)
		QX_CURSES		=-lpanel -lcurses -lform
	    #apparently standard Linux -lpanel does not define few symbols needed by Querix..
		#this works:  gcc -I/opt/querix/./incl -DQUERIX -o test.4qe test.qo  -lcurses -lform  -L/opt/querix/./lib -lfgl -lsqli  -lpanel
		#this does not:  gcc -I/opt/querix/./incl -DQUERIX -o test.4qe test.qo  -lcurses -lform -lpanel -L/opt/querix/./lib -lfgl -lsqli
	else
		ifneq "${Q4GL_VERSION}" "4"
			QX_CURSES		="$(QUERIXDIR)/lib/libpanel.a" "$(QUERIXDIR)/lib/libcurses.a"
        endif
	endif
endif



###########################
#FIXME: how do we link Querix with shared libs?
SHARED				=-rdynamic

###########################
#All libraries needed to link Querix program:


ifdef COMSPEC
	#QXI_CORELIBS    =-lfgl$(USE_DEBUG_LIBRARIES).lib -lsqli$(USE_DEBUG_LIBRARIES).lib

	#QXI_CORELIBS    =-L"$(QUERIXDIR)/bin" -lfgl$(USE_DEBUG_LIBRARIES).dll -lsqli$(USE_DEBUG_LIBRARIES).dll


#	QXI_CORELIBS    ="$(QUERIXDIR)/lib/libfgl$(USE_DEBUG_LIBRARIES).lib" "$(QUERIXDIR)/lib/libsqlc$(USE_DEBUG_LIBRARIES).lib"
	
	QXI_CORELIBS    ="$(QUERIXDIR)/bin/libfgl$(USE_DEBUG_LIBRARIES).dll" "$(QUERIXDIR)/bin/libsqlc$(USE_DEBUG_LIBRARIES).dll"


#gcc -I"E:/Program files/W2000/QueriX/include" -DQUERIX -DWINNT -Dgetenv=QXgetenv -o hello.4qe hello.qo   -L"E:/Program files/W2000/QueriX/lib" -L"E:/Program files/W2000/QueriX/bin" -lfgl -lsqlc
#Warning: resolving _Sleep by linking to _Sleep@4
#Use --enable-stdcall-fixup to disable these warnings
#Use --disable-stdcall-fixup to disable these fixups
#d000008.o(.text+0x0): multiple definition of `_onexit'
#d:/MinGW/bin/../lib/gcc-lib/mingw32/3.2/../../../crt2.o(.text+0x60):crt1.c: first defined here
#d000011.o(.text+0x0): multiple definition of `atexit'
#d:/MinGW/bin/../lib/gcc-lib/mingw32/3.2/../../../crt2.o(.text+0x40):crt1.c: first defined here
#	QXI_CORELIBS    =-L"$(QUERIXDIR)/bin" -lfgl$(USE_DEBUG_LIBRARIES) -lsqlc$(USE_DEBUG_LIBRARIES)

else
	QXI_CORELIBS    =-lfgl$(USE_DEBUG_LIBRARIES)
	ifeq "${Q4GL_VERSION}" "4"
		QXI_CORELIBS	+=-lsqlc$(USE_DEBUG_LIBRARIES)
    else
		QXI_CORELIBS	+=-lsqli$(USE_DEBUG_LIBRARIES)
    endif
endif


#BAD ...glob_GLOBALS.qo  "/opt/querix/./lib/libpanel.a" "/opt/querix/./lib/libcurses.a" -L"/opt/querix/./lib" -lfgl -lsqli
#QXI_LIBS			=${QX_CURSES} -L"$(QUERIXDIR)/lib" ${QXI_CORELIBS}

#OK  ...glob_GLOBALS.qo  -L/opt/querix/./lib -lfgl -lsqli /opt/querix/./lib/libpanel.a /opt/querix/./lib/libcurses.a
QXI_LIBS			=-L"$(QUERIXDIR)/lib" ${QXI_CORELIBS} ${QX_CURSES}

#ifeq "${QX_CURSES_LOCAL}" "yes"
#	QXI_LIBS			=${QX_CURSES} -L$(QUERIXDIR)/lib -lfgl$(USE_DEBUG_LIBRARIES) \
#						-lsqli$(USE_DEBUG_LIBRARIES)
#else
#	QXI_LIBS			=-L$(QUERIXDIR)/lib -lfgl$(USE_DEBUG_LIBRARIES) \
#						-lsqli$(USE_DEBUG_LIBRARIES) ${QX_CURSES}
#endif


#The extender libs must appear in the link list before libfgl(d) and libsql(d).
ifeq "${EXTENDER_GUI}" "yes"
	QXI_LIBS		:=$(EXTENDERLIBS_GUI) ${QXI_LIBS}
endif
ifeq "${EXTENDER_HTML}" "yes"
	QXI_LIBS		:=$(EXTENDERLIBS_HTML) ${QXI_LIBS}
endif

###########################
#This is the name of the ‘C’ compiler Querix will use to compile and link applications.
#FIXME: set this from autoconf
QXCC				=gcc

#######################
# Q4GL C-code Compiler
Q4GL_CC_CMD     	=fglc${QXDB}
Q4GL_CC_ENV     	=
#${CFLAGS}
Q4GL_CC_FLAGS   	=-a -w -D -I -z -Ig -Mi


#Querix specific comment (--*)
#requires a compiler switch (by default it will accept 4Js comments). Add '-Mi'
#to $FGLFLAGS and it should be OK ('-M4' is the default for 4Js comments).
#The compiler will only work in one mode at a time, so if you pass '-Mi' to
#fglc, it will treat 4Js comments as ordinary comments. Passing '-Mn' will set
#it into 'all comments are comments' mode.

#-ansi Causes verification of SQL statements for ANSI compliance.
#-w Enables extra warning tracking at runtime.
#-anyerr Enables tracking of variable type conversion and arithmetic errors in programs while in runtime, that use
#        the “WHENEVER ERROR” command without the addition of “WHENEVER ANY ERROR” command.
#-H Generate a “.h” file from a globals file. This allows a globals file to be used with external “C” code.
#-p directory #Places the output file in the specified directory path.
#-w Enables extra warning tracking at runtime.
#-z Force no function parameter checking. No errors will be flagged if functions return different
#   numbers of parameters at different times, or if the calling function does not expect the correct number
#   of return parameters.
#-Ig The mutliple symbol definition problem can be avoided by instructing the
#    compiler not to initialize global symboils by default since these are
#    global symbols they are actually null initialized during program
#    initialization. This means that all string variables will be nulled ("\0"),
#    and numeric variables set to 0.

#######################
# Q4GL C-code Linker
#QueriX supplies a C compilation utility named qxcc. This utility should be
#used as a linking tool (in place of $CC) when compiling applications where the
#main module is embedded within a C source:
#	qxcc $CFLAGS -o myprog $(SOURCES:.4gl=.o) $(LDLIBS)
#NOTE: this is only for use with 4gl code that NOES NOT define it's own MAIN!!!
Q4GL_CL_CMD     = ${QXCC}
Q4GL_CL_ENV     = ${Q4GL_CC_ENV}

ifdef COMSPEC
	Q4GL_CL_FLAGS   = -I"${QUERIXDIR}/include" -DQUERIX -DWINNT -Dgetenv=QXgetenv
else
	Q4GL_CL_FLAGS   = -I${QUERIXDIR}/incl -DQUERIX
endif
Q4GL_CL_LDFLAGS = ${LDFLAGS}

#######################
# Q4GL Form Compiler
Q4GL_FC_CMD     = fmpc${QXDB}
Q4GL_FC_FLAGS   =

#######################
# Q4GL Message Compiler
Q4GL_MC_CMD     = msgc
Q4GL_MC_FLAGS   =

#######################
# Complete commands for compiling and linking -- seldom changed
Q4GL_CC         = ${Q4GL_CC_ENV} ${Q4GL_CC_CMD} ${Q4GL_CC_FLAGS}
Q4GL_CL         = ${Q4GL_CL_ENV} ${Q4GL_CL_CMD} ${Q4GL_CL_FLAGS}
Q4GL_FC         = ${Q4GL_FC_CMD} ${Q4GL_FC_FLAGS}
Q4GL_MC         = ${Q4GL_MC_CMD} ${Q4GL_MC_FLAGS}

#######################
# Define suffixes which are recognised.

Q4GL_PRG_EXT=.4qe
Q4GL_OBJ_EXT=.qo
Q4GL_FRM_EXT=.pic
Q4GL_HLP_EXT=.qms
Q4GL_LIB_EXT=.qox

#Files compiler uses as source files:
#FIXME: 4GL_SRC_SUFFIXES should be in some common place for all compilers
4GL_SRC_SUFFIXES	= .4gl .per .msg
#Files that compiler created, but are not neded at run-time, that are safe to delete:
Q4GL_TMP_SUFFIXES_DELETE=${Q4GL_OBJ_EXT} ${Q4GL_LIB_EXT} .err
#Files that compiler created, but are not neded at run-time:
Q4GL_TMP_SUFFIXES   = ${Q4GL_TMP_SUFFIXES_DELETE} .c .h
#Files that compiler created, needed at run-time
Q4GL_SUFFIXES 		= ${Q4GL_PRG_EXT} ${Q4GL_FRM_EXT} ${Q4GL_HLP_EXT}
#Make directive to recognize sufixes:
.SUFFIXES:	${Q4GL_SUFFIXES} ${4GL_SRC_SUFFIXES} ${Q4GL_TMP_SUFFIXES}
#Files we need to delete, to clean everything compiler creates
Q4GL_CLEAN_FLAGS	=$(addprefix *,	$(Q4GL_TMP_SUFFIXES_DELETE)) $(addprefix *,$(Q4GL_SUFFIXES)) *.bak


# ================ Rules for compiling Q4GL ====================

#######################
# Rule for compiling a program from single 4gl file
.4gl${Q4GL_PRG_EXT}:
#	${Q4GL_CL} -o $@ $< ${Q4GL_CL_LDFLAGS} ${QXI_LIBS}
#	${FAIL_CMPL_4GL}${Q4GL_CC} $< -o $*${Q4GL_OBJ_EXT}
#-p $(<D)
	

	
	${FAIL_CMPL_4GL}${Q4GL_CC} $<
	${FAIL_CMPL_4GL}${FAIL_CMPL_C}${QXCC} -c ${Q4GL_CL_FLAGS} $*.c -o $*${Q4GL_OBJ_EXT}
	${FAIL_LINK}${Q4GL_CL} -o $@ $*${Q4GL_OBJ_EXT} ${Q4GL_CL_LDFLAGS} ${QXI_LIBS}

####################################
# Rule for making a library using .mk make file
%${Q4GL_LIB_EXT}:  %.mk
	@echo "Making library $*${Q4GL_LIB_EXT} using $^"
	${AMAKE} $<

#######################
# Rule for compiling program files to object
#Note: we don't want to have separate rules for 4gl-> and then from c->o because
#we want to allways have the dependency of the object to the 4gl source file.
#Otherwise, make would be happy when it see that object is up-to-date in
#respect to the c file, and ignore possible change in 4gl file
#.4gl.qo:

%${Q4GL_OBJ_EXT} : %.4gl
#.4gl${Q4GL_OBJ_EXT}:
#	${Q4GL_CC} $<
#	@echo "--------"
#	@echo "${QXCC} -c ${Q4GL_CL_FLAGS} $*.c -o $@"
#	@echo "--------"
	${FAIL_CMPL_4GL}@if test "$(<D)" = "" -o "$(<D)" = "."; then \
		EXEC="${Q4GL_CC} $<"; \
	else \
		EXEC="${Q4GL_CC} ${CYGWIN_ROOT}$<"; \
	fi; \
	echo "$$EXEC"; \
	$$EXEC; \
	RET=$$?; \
	if test "$$RET" != "0" ; then \
		exit $$RET; \
    fi;
#if 4gl compiler is allowed to fail, C compiler must be too, otherwise we will
#stop anyway sice c compiler will not get it's input c file:
	${FAIL_CMPL_4GL}${FAIL_CMPL_C}${QXCC} -c ${Q4GL_CL_FLAGS} $*.c -o $@

#Works
#gcc -I/opt/querix/./incl -DQUERIX -Wl,-rpath /opt/aubit/apps/erp/src/common -rdynamic -o erpmenu.4qe erpmenu.qo menuwind.qo secufunc.qo glob_GLOBALS.qo  -L/opt/querix/./lib -lfgl -lsqli /opt/querix/./lib/libpanel.a /opt/querix/./lib/libcurses.a
#does not:
#gcc -I/opt/querix/./incl -DQUERIX -Wl,-rpath /opt/aubit/apps/erp/src/common -rdynamic -o erpmenu.4qe erpmenu.qo menuwind.qo secufunc.qo glob_GLOBALS.qo  "/opt/querix/./lib/libpanel.a" "/opt/querix/./lib/libcurses.a" -L"/opt/querix/./lib" -lfgl -lsqli

#OK  ...glob_GLOBALS.qo  -L/opt/querix/./lib -lfgl -lsqli /opt/querix/./lib/libpanel.a /opt/querix/./lib/libcurses.a
#BAD ...glob_GLOBALS.qo  "/opt/querix/./lib/libpanel.a" "/opt/querix/./lib/libcurses.a" -L"/opt/querix/./lib" -lfgl -lsqli



#######################
# Rule for compiling Q4GL form files
#.per.pic:
.per${Q4GL_FRM_EXT}:
	${FAIL_CMPL_FRM}${Q4GL_FC} $<

#######################
# Rule for compiling message files
#.msg.qms:
.msg${Q4GL_HLP_EXT}:
	${FAIL_HLP}${Q4GL_MC} $< $@

#--------------------------- EOF --------------------------------






