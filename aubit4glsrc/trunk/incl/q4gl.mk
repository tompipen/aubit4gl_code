#   @(#)$Id: q4gl.mk,v 1.4 2003-01-17 23:04:08 afalout Exp $
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

#QUERIXDIR This is the subdirectory of the querix home directory (called qxNNN.f.ARCH)

#MSGPATH This is the path to the Querix message directory. It is usually
#$QUERIXDIR/msg.

#QXCC This is the name of the ‘C’ compiler Querix will use to compile and link applications.
#QXAWK This is the name of an nawk compatible awk program on your system.
#QXMAKE This is the name of the make program on your system.


#FGLC environment vars:
#DBTEMP The temporary directory.
#MSGPATH Path to error message files.
#DBLANG Used in conjunction with MSGPATH
#SQLHOSTS Explicit location of the sqlhosts file to reference for database connections.

##########################################################################
# Compilers and flags
##########################################################################

Q4GL_CLEAN_FLAGS = *.o *.qo *.bak *.h *.err *.pic *.4qe

#EXTENDERLIBS="`cat $QUERIXDIR/etc/$i.ext`"
#QXS_LIBS=
#FIXME: replace -lcurses with value assigned by autoconf (can be ncurses)

QX_CURSES=$(QUERIXDIR)/lib/libpanel.a $(QUERIXDIR)/lib/libcurses.a
#QX_CURSES=-lpanel -lcurses

#USE_DEBUG_LIBRARIES=d

QXI_LIBS=-L$(QUERIXDIR)/lib -lfgl$(USE_DEBUG_LIBRARIES) -lsqli$(USE_DEBUG_LIBRARIES) ${QX_CURSES}
QX_LIBS=$(EXTENDERLIBS) $(QXI_LIBS)
QXCC=gcc

# Q4GL C-code Compiler
Q4GL_CC_CMD     = fglc
Q4GL_CC_ENV     =
#${CFLAGS}
Q4GL_CC_FLAGS   =-a -w -D -I -z
#-I${QUERIXDIR}/incl -- will be ignored and not passed to C compiler, so we will try to
#work around this by specifying CFLAGS:
#CFLAGS+=-I${QUERIXDIR}/incl
#-ansi Causes verification of SQL statements for ANSI compliance.
#-w Enables extra warning tracking at runtime.
#-anyerr Enables tracking of variable type conversion and arithmetic errors in programs while in runtime, that use
#the “WHENEVER ERROR” command without the addition of “WHENEVER ANY ERROR” command.
#-H Generate a “.h” file from a globals file. This allows a globals file to be used with external “C” code.
#-p directory #Places the output file in the specified directory path.
#-w Enables extra warning tracking at runtime.
#-z Force no function parameter checking. No errors will be flagged if functions return different
#numbers of parameters at different times, or if the calling function does not expect the correct number
#of return parameters.

#The mutliple symbol definition problem can be avoided by instructing the 
#compiler not to initialize global symboils by default; passing the flag 
#'-Ig' to fglc(.) will do this. You can pas compiler flags through 4make 
#using the variable $FGLFLAGS:
#
#FGLFLAGS="-Ig" ; export FGLFLAGS
#4make myprog



# Q4GL C-code Linker
#Q4GL_CL_CMD     = ${Q4GL_CC_CMD}
#QueriX supplies a C compilation utility named qxcc. This utility should be used as a linking
#tool (in place of $CC) when compiling applications where the main module is embedded within a C source.
#qxcc $CFLAGS -o myprog $(SOURCES:.4gl=.o) $(LDLIBS)
#NOTE: this is only for use with 4gl code that NOES NOT define it's own MAIN!!!
Q4GL_CL_CMD     = ${QXCC}
Q4GL_CL_ENV     = ${Q4GL_CC_ENV}
#Q4GL_CL_FLAGS   = ${Q4GL_CC_FLAGS}
Q4GL_CL_FLAGS   = -I${QUERIXDIR}/incl -DQUERIX
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
Q4GL_SUFFIXES = .qo .4gl .c .4qe .pic .per .msg .qms
.SUFFIXES:	${Q4GL_SUFFIXES}

# Rules for compiling Q4GL

#.4gl.4ge:
.4gl.4qe:
	${Q4GL_CL} -o $@ $< ${Q4GL_CL_LDFLAGS} ${QXI_LIBS}
#.4gl.o:
.4gl.qo:
#	${Q4GL_CC} -c $<
	${Q4GL_CC} $<
	${QXCC} -c ${Q4GL_CL_FLAGS} $*.c -o $@
#	mv $*.o $@

.4gl.c:
	${Q4GL_CC} $<

.c.qo:
#	${QXCC} ${Q4GL_CC_FLAGS} ${CFLAGS} -DQUERIX -c $?
#	${QXCC} -c ${Q4GL_CL_FLAGS} $? -o $@
	${QXCC} -c ${Q4GL_CL_FLAGS} $*.c -o $@
#	mv $*.o $@

# Rules for compiling Q4GL form files
.per.pic:
	${Q4GL_FC} $<

# Rules for compiling message files
#FIXME: this assumes program will look for .iem extension
#.msg.iem:
.msg.qms:
	${Q4GL_MC} $< $@
	mv $@ $*.iem

#--------------------------- EOF --------------------------------






