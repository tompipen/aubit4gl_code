#   @(#)$Id: q4gl.mk,v 1.1.1.1 2001-08-20 02:36:00 afalout Exp $
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

#FIXME: Querix have 4 possible combinations:
#Informix CUI, Informix GUI, Oracle CUI, Oracle GUI
#This makefile should be able to compile all of them:
#fglc Main compiler for Informix
#fglco Main compiler for Oracle
#fmpc Form compiler for Informix
#fmpco Form compiler for Oracle

##########################################################################
# Compilers and flags
##########################################################################

Q4GL_CLEAN_FLAGS = *.o *.qo *.bak *.h *.err *.pic *.4qe

#EXTENDERLIBS="`cat $QUERIXDIR/etc/$i.ext`"
#QXS_LIBS=
QXI_LIBS=-L$(QUERIXDIR)/lib -lfgl$(USE_DEBUG_LIBRARIES) -lsqli$(USE_DEBUG_LIBRARIES) -lpanel -lcurses $(QXS_LIBS)
QX_LIBS=$(EXTENDERLIBS) $(QXI_LIBS)
QXCC=gcc
CFLAGS=-DQUERIX

# Q4GL C-code Compiler
Q4GL_CC_CMD     = fglc
Q4GL_CC_ENV     =
#Q4GL_CC_FLAGS   = "-a -I ${CFLAGS} -DQUERIX -I${QUERIXDIR}/incl -DQUERIX"
Q4GL_CC_FLAGS   = "-a -I -DQUERIX -I${QUERIXDIR}/incl "
#-ansi Causes verification of SQL statements for ANSI compliance.
#-w Enables extra warning tracking at runtime.
#-anyerr Enables tracking of variable type conversion and arithmetic errors in programs while in runtime, that use
#the “WHENEVER ERROR” command without the addition of “WHENEVER ANY ERROR” command.
#-H Generate a “.h” file from a globals file. This allows a globals file to be used with external “C” code.

# Q4GL C-code Linker
#Q4GL_CL_CMD     = ${Q4GL_CC_CMD}
Q4GL_CL_CMD     = gcc
Q4GL_CL_ENV     = ${Q4GL_CC_ENV}
Q4GL_CL_FLAGS   = ${Q4GL_CC_FLAGS}
Q4GL_CL_LDFLAGS = ${LDFLAGS}

# Q4GL Form Compiler
Q4GL_FC_CMD     = fmpc
Q4GL_FC_FLAGS   =

# Q4GL Message Compiler
Q4GL_MC_CMD     = msgc
Q4GL_MC_FLAGS   =

# Complete commands for compiling and linking -- seldom changed
Q4GL_CC         = ${Q4GL_CC_ENV} ${Q4GL_CC_CMD} ${Q4GL_CC_FLAGS}
Q4GL_CL         = ${Q4GL_CL_ENV} ${Q4GL_CL_CMD} ${Q4GL_CL_FLAGS}
Q4GL_FC         = ${Q4GL_FC_CMD} ${Q4GL_FC_FLAGS}
Q4GL_MC         = ${Q4GL_MC_CMD} ${Q4GL_MC_FLAGS}

# Basic Unix file commands
RM            = rm -f       # Delete files

# Define suffixes which are recognised.
Q4GL_SUFFIXES = .qo .4gl .c .4qe .pic .per .iem .msg .qms
.SUFFIXES:	${Q4GL_SUFFIXES}

# Rules for compiling Q4GL

#is this rule needed?
#.4gl:
#	${Q4GL_CL} -o $@ $< ${Q4GL_CL_LDFLAGS}


#.4gl.4ge:
.4gl.4qe:
	${Q4GL_CL} -o $@ $< ${Q4GL_CL_LDFLAGS}
#.4gl.o:
.4gl.qo:
	${Q4GL_CC} -c $<
	gcc -c -I/opt/querix/qxinf.f.lnx/incl $*.c
	mv $*.o $@

.c.qo:
	${CC} ${CFLAGS} -DQUERIX -c $?
	mv $*.o $@

# Rules for compiling Q4GL form files
.per.pic:
	${Q4GL_FC} $*

# Rules for compiling message files
#FIXME: this assumes program will look for .iem extension
#.msg.iem:
.msg.qms:
	${Q4GL_MC} $< $@
	mv $@ $*.iem

#--------------------------- EOF --------------------------------






