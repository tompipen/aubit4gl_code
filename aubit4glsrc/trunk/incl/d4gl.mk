#   @(#)$Id: d4gl.mk,v 1.9 2003-02-11 03:43:13 afalout Exp $
#
#   @(#)$Product: INFORMIX D4GL Programmer's Environment Version 2.00.UC2 (1998-07-31) $
#
#   Makefile for INFORMIX Dynamic 4GL / 4Js BDL Compilation
#--------------------------------------------------------------------------
# Note that this file does not define any targets; it only defines
# compilation rules and macros.
#--------------------------------------------------------------------------


# D4GL P-code Compiler
D4GL_PC_CMD     = fgl2p
D4GL_PC_ENV     =
D4GL_PC_FLAGS   =

# D4GL P-code Linker
# If using a custom runner, specify $FGLRUN in the environment,
# or in D4GL_PL_ENV.
D4GL_PL_CMD     = fgl2p
D4GL_PL_ENV     = # FGLRUN="${FGLRUN}"
D4GL_PL_FLAGS   =
D4GL_PL_LDFLAGS =

# D4GL C-code Compiler
# You shouldn't need to set D4GL_CC_ENV even with a non-standard
# compiler provided that FGLCC is set correctly.
D4GL_CC_CMD     = fgl2c
D4GL_CC_ENV     =
D4GL_CC_FLAGS   =

# D4GL C-code Linker
D4GL_CL_CMD     = fgl2c
D4GL_CL_FLAGS   =
D4GL_CL_ENV     = ${D4GL_CC_ENV}
D4GL_CL_LDFLAGS =

# D4GL Schema Compiler
D4GL_SC_CMD     = fglschema
D4GL_SC_FLAGS   =

# D4GL Form Compiler
D4GL_FC_CMD     = fglform
D4GL_FC_FLAGS   = -s

# D4GL Message Compiler
D4GL_MC_CMD     = fglmkmsg
D4GL_MC_FLAGS   =

# D4GL P-code Librarian
D4GL_PA_CMD     = fgl2p
D4GL_PA_FLAGS   =

# D4GL P-code Runner Compiler
D4GL_RC_CMD     = fglmkrun
D4GL_RC_FLAGS   =
D4GL_RC_ENV     = ${D4GL_CC_ENV}

# Complete commands for compiling and linking -- seldom changed
D4GL_CC         = ${D4GL_CC_ENV} ${D4GL_CC_CMD} ${D4GL_CC_FLAGS}
D4GL_CL         = ${D4GL_CL_ENV} ${D4GL_CL_CMD} ${D4GL_CL_FLAGS}
D4GL_PC         = ${D4GL_PC_ENV} ${D4GL_PC_CMD} ${D4GL_PC_FLAGS}
D4GL_PL         = ${D4GL_PL_ENV} ${D4GL_PL_CMD} ${D4GL_PL_FLAGS}
D4GL_RC         = ${D4GL_RC_ENV} ${D4GL_RC_CMD} ${D4GL_RC_FLAGS}
D4GL_FC         = ${D4GL_FC_CMD} ${D4GL_FC_FLAGS}
D4GL_MC         = ${D4GL_MC_CMD} ${D4GL_MC_FLAGS}
D4GL_PA         = ${D4GL_PA_CMD} ${D4GL_PA_FLAGS}
D4GL_SC         = ${D4GL_SC_CMD} ${D4GL_SC_FLAGS}


#######################
# Define suffixes which are recognised.

D4GL_PRG_EXT	=.42r
D4GL_CPRG_EXT	=.42e
D4GL_OBJ_EXT	=.42m
D4GL_FRM_EXT	=.42f
D4GL_HLP_EXT	=.42h
D4GL_LIB_EXT	=.42x
D4GL_CLIB_EXT	=.42o

#WARNING:
D4GL_C_SUFFIXES =.42e .42o .42h

#Files compiler uses as source files:
#FIXME: 4GL_SRC_SUFFIXES should be in some common place for all compilers
4GL_SRC_SUFFIXES	=.4gl .per .msg
#Files that compiler created, but are not neded at run-time, that are safe to delete:
D4GL_TMP_SUFFIXES_DELETE=${D4GL_OBJ_EXT} .err
#Files that compiler created, but are not neded at run-time:
D4GL_TMP_SUFFIXES   = ${D4GL_TMP_SUFFIXES_DELETE}
#Files that compiler created, needed at run-time
D4GL_SUFFIXES 		= ${D4GL_PRG_EXT} ${D4GL_FRM_EXT} ${D4GL_HLP_EXT} ${D4GL_LIB_EXT}
#Make directive to recognize sufixes:
.SUFFIXES:	${D4GL_SUFFIXES} ${4GL_SRC_SUFFIXES} ${D4GL_TMP_SUFFIXES} .sch
#Files we need to delete, to clean everything compiler creates
D4GL_CLEAN_FLAGS	=$(addprefix *,	$(D4GL_TMP_SUFFIXES_DELETE)) $(addprefix *,$(D4GL_SUFFIXES)) *.bak


########################################################################
# If your version of MAKE defines the macro SUFFIXES with its default
# list of suffixes, then you can use the following two lines instead.
# It ensures that the D4GL rules take precedence over any other rules.
# This is less of a problem with D4GL than with classic I4GL because
# D4GL has its own, independent set of object file suffixes.  With
# classic I4GL, the c4gl compiler generates .c files, and if the suffix
# list is not cleared and there are two files, file01.4gl and file01.c,
# in the directory, MAKE will compile the object file file01.o from
# file01.c rather than file01.4gl.  Rewriting the suffix list prevents
# this problem.
# Solaris MAKE does define SUFFIXES; most other versions do not.
########################################################################
#.SUFFIXES:
#.SUFFIXES: ${D4GL_SUFFIXES} ${SUFFIXES}

#%.42m: %.4gl
.4gl.42m:
#	${D4GL_PC} -c $*.4gl
#using VPATH:
#	${D4GL_PC} -c $^
	${D4GL_PC} -c $<
#	${A4GL_CC} $< -c -o ${OBJSTORE}$@
#	${LIBMVCMD} $@ ${OBJSTORE}

#Compile single 4gl file to executable
.4gl.42r:
#	${D4GL_PC} -c $*.4gl
#	${D4GL_PL} -o $*.42m $*.42r ${D4GL_PL_LDFLAGS}
#using VPATH:
#	@echo eeeee
#	${D4GL_PC} -c $^
#	${D4GL_PL} -o $^.42m $^.42r ${D4GL_PL_LDFLAGS}
	${D4GL_PC} $<
#	${D4GL_PC} -o $@ ${$(<F):.4gl=.42m}
#	${D4GL_PC} -o $@ ${${@F}:.42r=.42m}
#	${D4GL_PC} -o $@ ${$(notdir $@):.42r=.42m}
	${D4GL_PC} -o $@ $(subst .42r,.42m,$(notdir $@))

#	fgllink -O -o $@ $*.42m ${FGLDIR}/lib/libfgl4js.42x ${D4GL_PL_LDFLAGS}

eerr%.42x:
	@echo $@ $^
#	fgllink -O -o $@ $^ ${FGLDIR}/lib/libfgl4js.42x ${D4GL_PL_LDFLAGS}

.4gl.42o:
	${D4GL_CC} -c $*.4gl

# This could be combined into a single compilation rule.
# It is kept as two steps to parallel the .4gl.42r rule
# above, which must use the two separate steps.
.4gl.42e:
	${D4GL_CC} -c $*.4gl
	${D4GL_CL} -o $*.42e $*.42o ${D4GL_CL_LDFLAGS}

%${D4GL_FRM_EXT}: %.per
	${D4GL_FC} $^
#	@echo MKTARGET = ${MKTARGET} FSTORE= ${FSTORE}
#	@echo FORMSTORE = ${FORMSTORE}
#	${FORMMVCMD} $(dir $^)$@ ${FORMSTORE}

.msg${D4GL_HLP_EXT}:
	${D4GL_MC} $^ $@

#rule to make database schemma file
#${DBASE.sch}:
%.sch:
	${D4GL_SC} ${D4GL_SC_FLAGS} ${DBASE}
#ifneq "${FGLDBPATH}" ""
#	${SCHMVCMD} ${DBASE}.sch ${FGLDBPATH}
#else
	mv ${DBASE}.sch ${SCH_DIR}
#endif


%.42x:  %.mk
	@echo "Making library $*.42x using $^"
#FIXME: it can be pcode and ccode:
#	${MAKE} -f $^ ${MAKEFLAGS}
#	${MAKE} -f $^ ${MKTARGET}
	${MAKE} -f $^ d4gl-pcode
