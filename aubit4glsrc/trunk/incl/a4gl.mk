###########################################################################
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
###########################################################################

#	 $Id: a4gl.mk,v 1.21 2003-02-02 01:13:48 afalout Exp $

##########################################################################
#
#   @(#)$Id: a4gl.mk,v 1.21 2003-02-02 01:13:48 afalout Exp $
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

#FIXME: move this stuff in a common place, since it applies to all compilers:

ifndef AMAKE
	AMAKE=amake
endif

#Files compiler uses as source files:
#FIXME: 4GL_SRC_SUFFIXES should be in some common place for all compilers
4GL_SRC_SUFFIXES	= .4gl .per .msg


##########################################################################
# Compilers and flags
##########################################################################

###########################
#Name of the warper script for allAubit commands, that we expect in the PATH
AUBIT_WRAPER		=aubit

#Fixme: remove this by removing the need to use 4glpc script, and use 4glc directly instad:
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
A4GL_OBJ_EXT=.ao        #static object
A4GL_SOB_EXT=.aso       #shared object
A4GL_LIB_EXT=.aox       #static library
A4GL_SOL_EXT=.asx       #shared library
A4GL_FRM_EXT=.afr.xml
A4GL_HLP_EXT=.hlp
A4GL_MNU_EXT=.mnu.xml

#Files that compiler created, but are not neded at run-time, that are safe to delete:
A4GL_TMP_SUFFIXES_DELETE=${A4GL_OBJ_EXT} .err .glb
#All files that compiler created, but are not neded at run-time
A4GL_TMP_SUFFIXES   = ${A4GL_TMP_SUFFIXES_DELETE} .c .h
#Files that compiler created, needed at run-time
A4GL_SUFFIXES 		= ${A4GL_PRG_EXT} ${A4GL_FRM_EXT} ${A4GL_HLP_EXT} ${A4GL_MNU_EXT}

#FIXME: verify that this declaration is not overriden if foolowed by another one,
#since we often include all rules files one after the other...
.SUFFIXES:	${A4GL_SUFFIXES} ${4GL_SRC_SUFFIXES} ${A4GL_TMP_SUFFIXES}

#Files we need to delete, to clean everything compiler creates
#Note that we should NOT blidly delete all .c and .h files, since they may
#belong to C programs that we did not create
A4GL_CLEAN_FLAGS	=$(addprefix *,	$(A4GL_TMP_SUFFIXES_DELETE)) $(addprefix *,$(A4GL_SUFFIXES)) *.bak

# ====================== Rules for compiling A4GL ==========================


####################################
# Rule to compile executable from single 4gl file
#
#problem with this rule is, that when there is no explicit rule to
#build x.${A4GL_PRG_EXT} and we have x.4gl, this rule will be invoked
#with just one (${A4GL_PRG_EXT}.4gl) source file, instead with all the 4gl
#files needed:
#.4gl${A4GL_PRG_EXT}:
%${A4GL_PRG_EXT}: %.4gl
	${A4GL_CL} -o $@ $< ${A4GL_CL_LDFLAGS}


####################################
# Rule to compile an object file from a 4gl file
#
#Note: we don't want to have separate rules for 4gl->c and then from c->o because
#we want to allways have the dependency of the object to the 4gl source file.
#Otherwise, make would be happy when it see that object is up-to-date in
#respect to the c file, and ignore possible change in 4gl file
#.4gl${A4GL_OBJ_EXT}:
%${A4GL_OBJ_EXT} : %.4gl
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
# Rule to compile an shared object file from a 4gl file
%${A4GL_SOB_EXT} : %.4gl
	${FAIL_CMPL_4GL}${A4GL_CC} $< -c -as-dll -o $@


####################################
# Rule for making a library using .mk make file
#
%${A4GL_LIB_EXT}:  %.mk
	@echo "Making library $*.aox using $^"
#	${AMAKE} -f $<
	${AMAKE} $<

####################################
# Rule for compiling form files
#
#With XML packer, fcompile will by default create forms with .frm.xml extension:
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
#For old makefiles that still use .afr extension
#
#- this will still produce
#Aubit default form extension file - and NOT the .afr file !
#FIXME: why is redirection to aboce "real" rule not working?
#%.afr: %${A4GL_FRM_EXT}
%.afr: %.per
#	${FAIL_CMPL_FRM}${A4GL_FC} $< $@
	${FAIL_CMPL_FRM}${A4GL_FC} $<
#	mv $*${A4GL_FRM_EXT} $@


####################################
# Rules for compiling message files
#
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
# Rule for Aubit/Plexus Menu compiler
#
%${A4GL_MNU_EXT}: %.menu
	mcompile $<

####################################
# Rule for Aubit/Plexus Menu compiler - Non-XML packer:
#
#%.mnu: %${A4GL_MNU_EXT}
%.mnu: %.menu
	mcompile $<


#--------------------------- EOF --------------------------------






