#   @(#)$Id: i4gl.mk,v 1.5 2003-01-30 11:54:38 afalout Exp $
#
#   @(#)$Product: INFORMIX D4GL Programmer's Environment Version 2.00.UC2 (1998-07-31) $
#
#   Makefile for Classic INFORMIX Dynamic 4GL Compilation
#   Knows about: C, ESQL/C, I4GL, I4GL-RDS, RDSLIB and RDSLINK
#--------------------------------------------------------------------------
# Note that this file does not define any targets; it only defines
# compilation rules and macros.
#--------------------------------------------------------------------------

###############################################################################
# Compilers and flags
###############################################################################

# -- if ${IXCC} is gcc, set IXCC to "gcc -fwritable-strings"
IXCC=gcc -fwritable-strings

# ESQL/C Compiler
ESQL_EC_CMD     = esql
ESQL_EC_ENV     = INFORMIXC="${IXCC}"
ESQL_EC_FLAGS   =
ESQL_EC_LDFLAGS = ${LDFLAGS}

# I4GL C-code Compiler
I4GL_CC_CMD     = c4gl
I4GL_CC_ENV     = INFORMIXC="${IXCC}"
I4GL_CC_FLAGS   = ${CFLAGS}

# I4GL C-code Linker
I4GL_CL_CMD     = ${I4GL_CC_CMD}
I4GL_CL_ENV     = ${I4GL_CC_ENV}
I4GL_CL_FLAGS   = ${I4GL_CC_FLAGS}
I4GL_CL_LDFLAGS = ${LDFLAGS}

# I4GL P-code Compiler
I4GL_PC_CMD     = fglpc
I4GL_PC_ENV     =
I4GL_PC_FLAGS   =

# I4GL P-code Linker
#I4GL_PL_CMD     = rdslink -o
I4GL_PL_CMD     = cat
I4GL_PL_ENV     = ${I4GL_PC_ENV}
I4GL_PL_FLAGS   = ${I4GL_PC_FLAGS}
I4GL_PL_LDFLAGS =

# I4GL Form Compiler
I4GL_FC_CMD     = form4gl
I4GL_FC_FLAGS   = -q

# I4GL Message Compiler
I4GL_MC_CMD     = mkmessage
I4GL_MC_FLAGS   =

# I4GL P-code Librarian
I4GL_PA_CMD     = rdslib
I4GL_PA_FLAGS   = -rv

# I4GL P-code Runner Compiler
I4GL_RC_CMD   = cfglgo
I4GL_RC_FLAGS =
I4GL_RC_ENV   = ${I4GL_CC_ENV}

# I4GL P-code Runner Compiler
I4GL_DC_CMD   = cfgldb
I4GL_DC_FLAGS =
I4GL_DC_ENV   = ${I4GL_CC_ENV}

# Complete commands for compiling and linking -- seldom changed
ESQL            = ${ESQL_EC_ENV} ${ESQL_EC_CMD} ${ESQL_EC_FLAGS}
I4GL_CC         = ${I4GL_CC_ENV} ${I4GL_CC_CMD} ${I4GL_CC_FLAGS}
I4GL_CL         = ${I4GL_CL_ENV} ${I4GL_CL_CMD} ${I4GL_CL_FLAGS}
I4GL_PC         = ${I4GL_PC_ENV} ${I4GL_PC_CMD} ${I4GL_PC_FLAGS}
I4GL_PL         = ${I4GL_PL_ENV} ${I4GL_PL_CMD} ${I4GL_PL_FLAGS}
I4GL_RC         = ${I4GL_RC_ENV} ${I4GL_RC_CMD} ${I4GL_RC_FLAGS}
I4GL_DC         = ${I4GL_DC_ENV} ${I4GL_DC_CMD} ${I4GL_DC_FLAGS}
I4GL_FC         = ${I4GL_FC_CMD} ${I4GL_FC_FLAGS}
I4GL_MC         = ${I4GL_MC_CMD} ${I4GL_MC_FLAGS}
I4GL_PA         = ${I4GL_PA_CMD} ${I4GL_PA_FLAGS}

# Basic Unix file commands
RM            = rm -f       # Delete files

###############################################################################
# Define suffixes which are recognised.

I4GL_PRG_EXT		=.4gi
I4GL_OBJ_EXT		=.4go
I4GL_FRM_EXT		=.frm
I4GL_HLP_EXT		=.iem
I4GL_LIB_EXT		=.4gx

#WARNING:
I4GL_C_SUFFIXES 	=.ec .c .4ge

#Files compiler uses as source files:
#FIXME: 4GL_SRC_SUFFIXES should be in some common place for all compilers
4GL_SRC_SUFFIXES	=.4gl .per .msg
#Files that compiler created, but are not neded at run-time, that are safe to delete:
I4GL_TMP_SUFFIXES_DELETE=${I4GL_OBJ_EXT} .err
#Files that compiler created, but are not neded at run-time:
I4GL_TMP_SUFFIXES   =${I4GL_TMP_SUFFIXES_DELETE}
#Files that compiler created, needed at run-time
I4GL_SUFFIXES 		=${I4GL_PRG_EXT} ${I4GL_FRM_EXT} ${I4GL_HLP_EXT}
#Make directive to recognize as sufixes:
.SUFFIXES:	${I4GL_SUFFIXES} ${4GL_SRC_SUFFIXES} ${I4GL_TMP_SUFFIXES}
#Files we need to delete, to clean everything compiler creates
I4GL_CLEAN_FLAGS	=$(addprefix *,	$(I4GL_TMP_SUFFIXES_DELETE)) $(addprefix *,$(I4GL_SUFFIXES)) *.bak

#=============================================================================

# Rules for compiling I4GL (assuming 4.12/6.00 or later with -nokeep as default)
#is this rule needed?
#> In a4gl.mk, you ask about the null-suffix rule ".4gl:"; it is probably
#> not needed.  In any case, in a multi-compiler system, it is ambiguous;
#> is that supposed to be a Querix, Aubit, Informix, 4J's 4GL executable?
#.4gl:
#	${I4GL_CL} -o $@ $< ${I4GL_CL_LDFLAGS}
.4gl.4ge:
	@echo here3
	${I4GL_CL} -o $@ $< ${I4GL_CL_LDFLAGS}

.4gl.o:
	@echo here4
	${I4GL_CC} -c $<

.4gl.ec:
#	@echo --- debug 2 --- $< $@
	${I4GL_CC} -e $<

# Rules for compiling ESQL/C
.ec:
	@echo here6
	${ESQL_EC} -o $@ $< ${ESQL_EC_LDFLAGS}
	${RM} $*.[co]
.ec.o:
	${ESQL_EC} -c $<
	${RM} $*.c
.ec.c:
	${ESQL_EC} -e $<

# Rules for compiling I4GL form files
.per.frm:
	${I4GL_FC} $<
#	${I4GL_FC} $*

# Rules for compiling message files
.msg.iem:
	${I4GL_MC} $< $@

# I4GL RDS compiling
.4gl.4go:
#%.4go : %.4gl
#%.4go:
#	@echo here2
#	${I4GL_PC} $*.4gl
	${I4GL_PC} $<
#	${A4GL_CC} $< -c -o ${OBJSTORE}$@
#	${A4GL_CC} $< -c -o $@


#.4gl.4gi:
#	${I4GL_PC} $<
#	#${I4GL_PL} $@ $*.4go ${I4GL_PL_LDFLAGS}
#	${I4GL_PL} $*.4go > $@
#	${RM} $*.4go

.4go.4gi:
#	#${I4GL_PL} $@ $*.4go ${I4GL_PL_LDFLAGS}
	@echo here ${I4GL_PL}
	${I4GL_PL}123 $*.4go > $@
#	${RM} $*.4go


# ================================= EOF =================================
