###########################################################################
#
#   @(#)$Id: q4gl.mk,v 1.5 2003-01-21 08:25:51 afalout Exp $
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

	#loaded libraries list from .ext files contains make style variables, but they
	#are not automatically expanded in this context, so we have to do this manually:
	DOLLAR=$$
	LEFT=(
	RIGHT=)
	
	EXTENDERLIBS_GUI	=$(subst QUERIXDIR,$(QUERIXDIR),$(shell cat ${QUERIXDIR}/etc/gui.ext))
	EXTENDERLIBS_GUI	:=$(subst USE_DEBUG_LIBRARIES,${USE_DEBUG_LIBRARIES},${EXTENDERLIBS_GUI})
	EXTENDERLIBS_GUI	:=$(subst ${DOLLAR},,${EXTENDERLIBS_GUI})
	EXTENDERLIBS_GUI	:=$(subst ${LEFT},,${EXTENDERLIBS_GUI})
	EXTENDERLIBS_GUI	:=$(subst ${RIGHT},,${EXTENDERLIBS_GUI})

	EXTENDERLIBS_HTML	=$(shell cat ${QUERIXDIR}/etc/html.ext)

endif

###########################
#Set the following to 'yes", to activate linking with Querix extender libraries
#for particular extension
EXTENDER_GUI        =yes
EXTENDER_HTML       =no

###########################
#If you want to link with local, native Curses libraries, set this to 'yes';
#otherwise, Querix provided static Curses libraries will be linked
CURSES_LOCAL		=no

ifeq "${CURSES_LOCAL}" "yes"
	#FIXME: replace -lcurses with value assigned by autoconf (can be ncurses)
	QX_CURSES		=-lpanel -lcurses
else
	QX_CURSES		=$(QUERIXDIR)/lib/libpanel.a $(QUERIXDIR)/lib/libcurses.a
endif

###########################
#FIXME: how do we link Querix with shared libs?
SHARED				=-rdynamic

###########################
#All libraries needed to link Querix program:
QXI_LIBS			=-L$(QUERIXDIR)/lib -lfgl$(USE_DEBUG_LIBRARIES) \
						-lsqli$(USE_DEBUG_LIBRARIES) ${QX_CURSES}

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
Q4GL_CC_FLAGS   	=-a -w -D -I -z -Ig
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
Q4GL_CL_FLAGS   = -I${QUERIXDIR}/incl -DQUERIX
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
#Files that compiler created, but are not neded at run-time:
Q4GL_TMP_SUFFIXES   = ${Q4GL_OBJ_EXT} .c .h .err
#Files that compiler created, needed at run-time
Q4GL_SUFFIXES 		= ${Q4GL_PRG_EXT} ${Q4GL_FRM_EXT} ${Q4GL_HLP_EXT}
.SUFFIXES:	${Q4GL_SUFFIXES} ${4GL_SRC_SUFFIXES} ${Q4GL_TMP_SUFFIXES}

#Files we need to delete, to clean everything Querix compiler creates
#Q4GL_CLEAN_FLAGS 	= *${Q4GL_OBJ_EXT} *{Q4GL_PRG_EXT} *${Q4GL_FRM_EXT} *${Q4GL_HLP_EXT} *.bak *.c *.h *.err
Q4GL_CLEAN_FLAGS	=$(addprefix *,	$(Q4GL_TMP_SUFFIXES)) $(addprefix *,$(Q4GL_SUFFIXES)) *.bak


# ================ Rules for compiling Q4GL ====================

#######################
# Rule for compiling a program from single 4gl file
#FIXME: is this usable at all in real life? REMOVE IT
#.4gl.4qe:
#	${Q4GL_CL} -o $@ $< ${Q4GL_CL_LDFLAGS} ${QXI_LIBS}

#######################
# Rule for compiling program files to object
#Note: we don't want to have separate rules for 4gl-> and then from c->o because
#we want to allways have the dependency of the object to the 4gl source file.
#Otherwise, make would be happy when it see that object is up-to-date in
#respect to the c file, and ignore possible change in 4gl file
#.4gl.qo:
.4gl${Q4GL_OBJ_EXT}:
	${FAIL_CMPL_4GL}${Q4GL_CC} $<
#if 4gl compiler is allowed to fail, C compiler must be too, otherwise we will
#stop anyway sice c compiler will not get it's input c file:
	${FAIL_CMPL_4GL}${FAIL_CMPL_C}${QXCC} -c ${Q4GL_CL_FLAGS} $*.c -o $@

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






