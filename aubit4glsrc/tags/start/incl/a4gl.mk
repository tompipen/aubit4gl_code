#   @(#)$Id: a4gl.mk,v 1.1.1.1 2001-08-20 02:36:00 afalout Exp $
#
#   @(#)$Product: Aubit 4gl $
#
#   Makefile for Aubit 4GL Compilation - based on i4gl.mk by JL
#
#--------------------------------------------------------------------------
# Note that this file does not define any targets; it only defines
# compilation rules and macros.
#--------------------------------------------------------------------------
# Under normal circumstances, you should not need to edit this file

##########################################################################
# Compilers and flags
##########################################################################

A4GL_CLEAN_FLAGS = *.ao *.bak *.h *.err *.glb *.hlp *.4ae

# A4GL C-code Compiler
A4GL_CC_CMD     = 4glpc -g -O2 -gtk -static
A4GL_CC_ENV     =
A4GL_CC_FLAGS   = -O -I${AUBITDIR}/incl -DAUBIT4GL

# A4GL C-code Linker
A4GL_CL_CMD     = ${A4GL_CC_CMD}
A4GL_CL_ENV     = ${A4GL_CC_ENV}
A4GL_CL_FLAGS   = ${A4GL_CC_FLAGS}
A4GL_CL_LDFLAGS = ${LDFLAGS}

# A4GL Form Compiler
A4GL_FC_CMD     = fcompile
A4GL_FC_FLAGS   =

# A4GL Message Compiler
A4GL_MC_CMD     = mkmess
A4GL_MC_FLAGS   =

# Complete commands for compiling and linking -- seldom changed
A4GL_CC         = ${A4GL_CC_ENV} ${A4GL_CC_CMD} ${A4GL_CC_FLAGS}
A4GL_CL         = ${A4GL_CL_ENV} ${A4GL_CL_CMD} ${A4GL_CL_FLAGS}
A4GL_FC         = ${A4GL_FC_CMD} ${A4GL_FC_FLAGS}
A4GL_MC         = ${A4GL_MC_CMD} ${A4GL_MC_FLAGS}

# Basic Unix file commands
RM            = rm -f       # Delete files

# Define suffixes which are recognised.
A4GL_SUFFIXES = .ao .4gl .c .4ae .afr .per .iem .msg .hlp
.SUFFIXES:	${A4GL_SUFFIXES}

# Rules for compiling A4GL

#is this rule needed?
#> In a4gl.mk, you ask about the null-suffix rule ".4gl:"; it is probably
#> not needed.  In any case, in a multi-compiler system, it is ambiguous;
#> is that supposed to be a Querix, Aubit, Informix, 4J's 4GL executable?
#.4gl:
#	${A4GL_CL} -o $@ $< ${A4GL_CL_LDFLAGS}

#.4gl.4ge:
.4gl.4ae:
	${A4GL_CL} -o $@ $< ${A4GL_CL_LDFLAGS}
#.4gl.o:
.4gl.ao:
	${A4GL_CC} -c $<
	mv $*.o $@

# Rules for compiling A4GL form files
#.per.frm:

.per.afr:
#	${A4GL_FC} $*
#using VPATH:
	${A4GL_FC} $^ > /dev/null
#	${A4GL_FC} $^
#if I do this, programs eill not be able to find forms; this need to be
#changed in form compiler and aubit compiler. Untill we do, make will always
#recompile forms, since it will not be able to find .afr files
#	-mv $*.frm $@

.c.ao:
#	${CC} ${CFLAGS} -DAUBIT4GL -c $?
	${CC} ${A4GL_CC_FLAGS} -c $?
	mv $*.o $@

# Rules for compiling message files
#FIXME: this assumes program will look for .iem extension
#FIXME: Aubit will not look for help file in executable directory,
#it will look only in current directory (.) and fail if program is
#executed from anywhere else!
#.msg.iem:
.msg.hlp:
	${A4GL_MC} $*
#because of this make fill always recompile help file, since it can't
#find .hlp files; can we make aubit compiler to automatically look for
#.hlp if it can't find .iem (or other extension sopecified in code):
	mv $@ $*.iem


#--------------------------- EOF --------------------------------






