#   @(#)$Id: i4gl.mk,v 1.12 2004-10-20 12:18:51 afalout Exp $
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

#fglpc flags:
#-ansi check all SQL for ANSI SQL compliance
#-p pathname - put resulting object in 'path'
#-a To have your compiled program check array bounds at runtime, specify the
#   -a option. The -a option requires additional processing, so you might prefer
#   to use this option only for debugging during development.
#The -globcurs option lets you make the names of cursors and of prepared
#objects global to the entire program. The compilers still require you to declare
#the cursor before using it for any other purpose in the module, so this option
#is seldom useful. This option might help in debugging, however, because the
#cursor names are not modified. See the section “The -globcurs and -localcurs
#Options” on page 1-38 for more information about the scope of cursor names.
#The -localcurs option can override the -globcurs option if that was set in the
#C4GLFLAGS environment variable, and makes the names of cursors and
#prepared objects local to the module in which they were declared.

ifndef AMAKE
	AMAKE		=amake
endif

# -- if ${IXCC} is gcc, set IXCC to "gcc -fwritable-strings"
IXCC			=gcc -fwritable-strings

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
I4GL_PC_FLAGS   +=

# I4GL P-code Linker
#I4GL_PL_CMD    = rdslink -o
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
I4GL_RC_CMD   	= cfglgo
I4GL_RC_FLAGS 	=
I4GL_RC_ENV   	= ${I4GL_CC_ENV}

# I4GL P-code Runner Compiler
I4GL_DC_CMD   	= cfgldb
I4GL_DC_FLAGS 	=
I4GL_DC_ENV   	= ${I4GL_CC_ENV}

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
RM            	= rm -f       # Delete files

###############################################################################
# Define suffixes which are recognised.

I4GL_PRG_EXT	=.4gi
I4GL_CPRG_EXT	=.4ge
I4GL_OBJ_EXT	=.4go
I4GL_COBJ_EXT	=.o
I4GL_FRM_EXT	=.frm
I4GL_HLP_EXT	=.iem
I4GL_LIB_EXT	=.4gx
I4GL_CLIB_EXT	=.4cx

#WARNING:
I4GL_C_SUFFIXES =.ec .c ${I4GL_CPRG_EXT}

#Files compiler uses as source files:
#FIXME: 4GL_SRC_SUFFIXES should be in some common place for all compilers
4GL_SRC_SUFFIXES	=.4gl .per .msg
#Files that compiler created, but are not neded at run-time, that are safe to delete:
I4GL_TMP_SUFFIXES_DELETE=${I4GL_OBJ_EXT} ${I4GL_LIB_EXT} .err
#Files that compiler created, but are not neded at run-time:
I4GL_TMP_SUFFIXES   =${I4GL_TMP_SUFFIXES_DELETE}
#Files that compiler created, needed at run-time
I4GL_SUFFIXES 		=${I4GL_PRG_EXT} ${I4GL_FRM_EXT} ${I4GL_HLP_EXT}
#Make directive to recognize as sufixes:
.SUFFIXES:	${I4GL_SUFFIXES} ${4GL_SRC_SUFFIXES} ${I4GL_TMP_SUFFIXES} .mk
#Files we need to delete, to clean everything compiler creates
I4GL_CLEAN_FLAGS	=$(addprefix *,	$(I4GL_TMP_SUFFIXES_DELETE)) $(addprefix *,$(I4GL_SUFFIXES)) *.bak

#=============================================================================

#ifeq "${A4GL_FAKELEXTYPE}" "PCODE"
	DEFAULT_LINK=cp prog${A4GL_OBJ_EXT} progname${A4GL_EXE_EXT}
#else
#	#define default linking action
#	DEFAULT_LINK=${A4GL_FGLC} $^ -o $@
#endif




# Rules for compiling I4GL (assuming 4.12/6.00 or later with -nokeep as default)

#########################
# Rule to make C code executable from single 4gl file
.4gl${I4GL_CPRG_EXT}:
	@echo here3
	${I4GL_CL} -o $@ $< ${I4GL_CL_LDFLAGS}

#########################
# Rule to make C code object
.4gl${I4GL_COBJ_EXT}o:
	@echo here4
	${I4GL_CC} -c $<

#########################
# Rule to translate 4gl to ESQL/C
.4gl.ec:
#	@echo --- debug 2 --- $< $@
	${I4GL_CC} -e $<

#########################
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

#########################
# Rule for making a library using .mk make file
#We have a problem here:
#we do make a library successfully, but if it's out of the current directory,
#when we come back to the linking stage, VPATH was already scanned, and the
#library name will NOT include the PATH - since file did not exist when
#dependencies where searched for. With 4JS, I think that linker finds them based
#on 4Js specific environment variable, FGLLDPATH. Wit C based compilers, ld finds
#libraries in LD_RUN_PATH. But here, we do not have a linker, just a humble 'cat'
#so what to we do?
#If user just re-issues make command, VPATH will find the created library,
#and all will lin (cat) just fine...
#%${I4GL_LIB_EXT}:  %.mk
.mk${I4GL_LIB_EXT}: 
#---- gives "*** No rule to make target `invwind.4gx'" unless .mk is added to .SUFFIXES
#	@echo "Making library $*${I4GL_LIB_EXT} using $^"
	@echo "Making library $@ using $^"
	${AMAKE} $<

#########################
# Rule for compiling form files
.per${I4GL_FRM_EXT}:
	${I4GL_FC} $<
#	${I4GL_FC} $*

#########################
# Rule for compiling message files
.msg${I4GL_HLP_EXT}:
	${I4GL_MC} $< $@

#########################
# I4GL RDS compiling
.4gl${I4GL_OBJ_EXT}:
#%.4go : %.4gl
#%.4go:
#	@echo here2
#	${I4GL_PC} $*.4gl
#when dropping object in originating directory, had a lot of problems...
#not sure why
#	${I4GL_PC} -p $(<D) $<
#	@echo "flags = ${I4GL_PC_FLAGS}"
	${I4GL_PC} $<
#	${A4GL_CC} $< -c -o ${OBJSTORE}$@
#	${A4GL_CC} $< -c -o $@


#########################
#Make executable from single 4gl file:
#.xxx4gl.xxxx4gi:
.4gl.4gi:
	${I4GL_PC} -p $(<D) $<
	@echo "${I4GL_PL} $*.4go > $@"
	@${I4GL_PL} $*.4go > $@; \
	if test "$$?" != "0"; then \
		echo "CAT failed, removing $@"; \
		rm $@; \
		exit 1; \
	fi


# ================================= EOF =================================

