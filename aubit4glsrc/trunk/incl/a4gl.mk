##########################################################################
#
#   @(#)$Id: a4gl.mk,v 1.17 2003-01-21 08:25:51 afalout Exp $
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
#
##########################################################################

##########################################################################
# Compilers and flags
##########################################################################

###########################
#Name of the warper script for allAubit commands, that we expect in the PATH
AUBIT_WRAPER		=aubit

ifdef COMSPEC
    SH=bash
else
    SH=sh
endif

AUBIT_CMD   =${SH} ${AUBIT_WRAPER}


###########################
#If this compilers needs objects ar run-time, set to 'yes':
A4GL_INST_OBJ		=no

###########################
#If this compiler uses C compiler to create native executables, set thi to 'yes':
A4GL_IS_C_COMPILER	=yes

###########################
#Name of C compiler used to compile Aubit created C files, and for linking objects:
AUCC				=gcc

###########################
#Flags to C compiler for compiling objects:
AUCC_FLAGS			=-g -O2 -static -O -I${AUBITDIR}/incl -DAUBIT4GL

###########################
# A4GL C-code Compiler
#should I use 4glc instead 4glpc here?
A4GL_CC_CMD     = ${AUBIT_CMD} ${SH} 4glpc #-shared
A4GL_CC_ENV     =
A4GL_CC_FLAGS   = #-verbose

###########################
# A4GL C-code Linker
A4GL_CL_CMD     = ${A4GL_CC_CMD}
A4GL_CL_ENV     = ${A4GL_CC_ENV}
A4GL_CL_FLAGS   = ${A4GL_CC_FLAGS}
A4GL_CL_LDFLAGS = ${LDFLAGS}

###########################
# A4GL Form Compiler
A4GL_FC_CMD     = ${AUBIT_WRAPER} fcompile
A4GL_FC_FLAGS   =

###########################
# A4GL Message Compiler
A4GL_MC_CMD     = ${AUBIT_WRAPER} mkmess
A4GL_MC_FLAGS   =

###########################
# Complete commands for compiling and linking -- seldom changed
A4GL_CC         = ${A4GL_CC_ENV} ${A4GL_CC_CMD} ${A4GL_CC_FLAGS}
A4GL_CL         = ${A4GL_CL_ENV} ${A4GL_CL_CMD} ${A4GL_CL_FLAGS}
A4GL_FC         = ${A4GL_FC_CMD} ${A4GL_FC_FLAGS}
A4GL_MC         = ${A4GL_MC_CMD} ${A4GL_MC_FLAGS}


#######################
# Define suffixes which are recognised.

A4GL_PRG_EXT=.4ae
A4GL_OBJ_EXT=.ao
A4GL_FRM_EXT=.afr.xml
A4GL_HLP_EXT=.hlp
A4GL_LIB_EXT=.aox
A4GL_MNU_EXT=.mnu.xml

#Files compiler uses as source files:
#FIXME: 4GL_SRC_SUFFIXES should be in some common place for all compilers
4GL_SRC_SUFFIXES	= .4gl .per .msg
#Files that compiler created, but are not neded at run-time:
A4GL_TMP_SUFFIXES   = ${A4GL_OBJ_EXT} .c .h .err .glb
#Files that compiler created, needed at run-time
A4GL_SUFFIXES 		= ${A4GL_PRG_EXT} ${A4GL_FRM_EXT} ${A4GL_HLP_EXT} ${A4GL_MNU_EXT}
.SUFFIXES:	${A4GL_SUFFIXES} ${4GL_SRC_SUFFIXES} ${A4GL_TMP_SUFFIXES}

#Files we need to delete, to clean everything compiler creates
A4GL_CLEAN_FLAGS	=$(addprefix *,	$(A4GL_TMP_SUFFIXES)) $(addprefix *,$(A4GL_SUFFIXES)) *.bak *.glb

# ====================== Rules for compiling A4GL ==========================

####################################
# Rule to compile executable from single 4gl file
.4gl${A4GL_PRG_EXT}:
	${A4GL_CL} -o $@ $< ${A4GL_CL_LDFLAGS}


####################################
#$(FILES.ao): %.ao: %.4gl
#${OBJSTORE}%.ao: %.4gl
#	${A4GL_CC} $< -c -o $@

####################################
#Note: we don't want to have separate rules for 4gl-> and then from c->o because
#we want to allways have the dependency of the object to the 4gl source file.
#Otherwise, make would be happy when it see that object is up-to-date in
#respect to the c file, and ignore possible change in 4gl file
.4gl${A4GL_OBJ_EXT}:
#%.ao : %.4gl
#	${A4GL_CC} $< -c -o ${OBJSTORE}$@
	${FAIL_CMPL_4GL}${A4GL_CC} $< -c -o $@
#	aubit 4glc -c hello.4gl
#	${FAIL_CMPL_C}${AUCC} ${AUCC_FLAGS} -c $*.c -o $*.ao
ifeq "${VERBOSE}" "1"
ifneq "${FAIL_CMPL_4GL}" "-"
#we will not know if we succeded if ignore is on:
	@echo 4GL OK: $<
endif
endif


####################################
%${A4GL_LIB_EXT}:  %.mk
	@echo "Making library $*.aox using $^"
	${MAKE} -f $^

####################################
%.mk:
#LAST RESORT: Trying to translate makefile to cinqwind.mk
#FIXME: what if missing .mk is not from this directory? How to find
#out where it should be, and how to make it?
	@echo "LAST RESORT: Trying to translate makefile to $*.mk $^"
#   cd somewhere???
#	prepmake -verbose
	@echo Sorry: disabled in a4gl.mk

####################################
#With XML packer, fcompile will by defailt create forms with .frm.xml extension:
%${A4GL_FRM_EXT}: %.per
#.per.afr:
#	${A4GL_FC} $*
#using VPATH:
#	${A4GL_FC} $^ > /dev/null
#	${FAIL_CMPL_FRM}${A4GL_FC} $^ ${FORMSTORE}$@
	${FAIL_CMPL_FRM}${A4GL_FC} $<
ifeq "${VERBOSE}" "1"
ifneq "${FAIL_CMPL_FRM}" "-"
#we will not know if we succeded if ignore is on:
	@echo PER OK: $<
endif
endif
%.tmpcommentedout:
#FIXME: change form compiler and aubit compiler to recognise .afr, and
#remove this "ln" line(s)
	XX=$(shell  if test -f ${FORMSTORE}$*.afr.xml ; then echo 1; fi)
	@echo XX=${XX}
	@echo xx$(shell  if test -f ${FORMSTORE}$*.afr.xml ; then echo 1; fi)xx
ifeq "$(shell  if test -f ${FORMSTORE}$*.afr.xml ; then echo 1; fi)" "1"
	@echo exist: ${FORMSTORE}$*.afr.xml
	ln ${FORMSTORE}$*.afr.xml ${FORMSTORE}$*.xml.frm
else
	@echo No file: ${FORMSTORE}$*.afr.xml
#ifeq "$(shell  if test -f ${FORMSTORE}$@ ; then echo 1; fi)" "1"
ifeq "$(shell  if test -f ${FORMSTORE}$*.afr ; then echo 1; fi)" "1"
#	@echo exist: ${FORMSTORE}$@
	@echo exist: ${FORMSTORE}$*.afr
	rm -f ${FORMSTORE}$*.frm
	ln ${FORMSTORE}$@ ${FORMSTORE}$*.frm
else
	@echo No file: ${FORMSTORE}$*.afr
endif
endif

####################################
#For old makefiles that still use .afr extension:
%.afr: %${A4GL_FRM_EXT}
#	${FAIL_CMPL_FRM}${A4GL_FC} $<
#	mv $*${A4GL_FRM_EXT} $@


####################################
#Form compiled to XML format:
# Rules for compiling message files
#FIXME: this assumes program will look for .iem extension
#FIXME: Aubit will not look for help file in executable directory,
#it will look only in current directory (.) and fail if program is
#executed from anywhere else!
#.msg.iem:
.msg${A4GL_HLP_EXT}:
	${A4GL_MC} $*
#because of this make fill always recompile help file, since it can't
#find .hlp files; can we make aubit compiler to automatically look for
#.hlp if it can't find .iem (or other extension sopecified in code):
#	mv $@ $*.iem

####################################
#Aubit/Plexus Menu compiler
%${A4GL_MNU_EXT}: %.menu
	mcompile $<

#Non-XML packer:
#%.mnu: %${A4GL_MNU_EXT}
%.mnu: %.menu
	mcompile $<


#--------------------------- EOF --------------------------------






