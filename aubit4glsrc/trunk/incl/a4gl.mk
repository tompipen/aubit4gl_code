##########################################################################
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

#	 $Id: a4gl.mk,v 1.43 2003-12-10 09:33:14 afalout Exp $

##########################################################################
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
#maybe create file "common4gl.mki" and include it in all rules files?
ifndef AMAKE
	AMAKE=amake
endif

#Files compiler uses as source files:
4GL_SRC_SUFFIXES	=.4gl .per .msg

ifdef COMSPEC
    SH				=bash
else
    SH				=sh
endif

#------- end of common stuff ------------

#Despite of the use of 2>/dev/null, this will print rubbish (À&@À&@) to stdout when
#aubit-config is not installed yet. How can I prevent this?
A4GL_CURR_PACKER			:=$(shell aubit-config A4GL_PACKER 2> /dev/null)
ifeq "${A4GL_CURR_PACKER}" ""
	A4GL_CURR_PACKER=PACKED
endif

##########################################################################
# Compilers and flags
##########################################################################

###########################
#Name of the warper script for allAubit commands, that we expect in the PATH
AUBIT_WRAPER		=aubit

###########################
#Define command to be used to run Aubit compiler executbles
#AUBIT_CMD   		=${SH} ${AUBIT_WRAPER}
AUBIT_CMD   		=${AUBIT_WRAPER}

###########################
#do we want to use 4glpc shell script, or will we invoke 4glc directly
#on CygWin (not MinGW) we have to use 4glpc because of the bug in getopt_long()
#To find out iw wae are using MinGW, we can try:
ifdef COMSPEC
	MINGW			:=$(shell mingw32-gcc --version 2>/dev/null)
	ifeq "${MINGW}" ""
		USE_4GLPC	=1
    else            
		USE_4GLPC	=0
    endif
endif
#

###########################
#If this compilers needs objects ar run-time, set to 'yes':
#note: applies only to static objects, not shared libraries
A4GL_INST_OBJ		=no

###########################
#If this compiler uses C compiler to create native executables, set this to 'yes':
A4GL_IS_C_COMPILER	=yes

###########################
#Name of C compiler used to compile Aubit created C files, and for linking objects:
#FIXME: why do we need this? 4glpc and 4glc should do this...
AUCC				=gcc

###########################
#Define libraryes and paths to link compiled programs with
#FIXME: why do we need this? 4glpc and 4glc should do this...
A4GL_LINKLIBS       =-laubit4gl
A4GL_LINKLIBS_LFLAGS=-L${AUBITDIR}/lib

###########################
#Flags to C compiler for compiling objects:
#FIXME: why do we need this? 4glpc and 4glc should do this...
AUCC_FLAGS			=-g -static -O -I${AUBITDIR}/incl -DAUBIT4GL

###########################
# A4GL C-code Compiler command
ifeq "${USE_4GLPC}" "1"
	A4GL_CC_CMD     = ${AUBIT_CMD} ${SH} 4glpc
else
	A4GL_CC_CMD     = ${AUBIT_CMD} 4glc ${EXTRA_4GLC}
#--clean
endif
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
A4GL_MC_CMD     = ${AUBIT_WRAPER} amkmessage
A4GL_MC_FLAGS   =

###########################
# Complete commands for compiling and linking -- seldom changed
A4GL_CC         = ${A4GL_CC_ENV} ${A4GL_CC_CMD} ${A4GL_CC_FLAGS}
A4GL_CL         = ${A4GL_CL_ENV} ${A4GL_CL_CMD} ${A4GL_CL_FLAGS}
A4GL_FC         = ${A4GL_FC_CMD} ${A4GL_FC_FLAGS}
A4GL_MC         = ${A4GL_MC_CMD} ${A4GL_MC_FLAGS}


#######################
# Define suffixes which are recognised.
#NOTE: variable names and settings used here are identical to Aubit resource.c

#Executable:
A4GL_EXE_EXT=.4ae
#static object:
A4GL_OBJ_EXT=.ao
#shared object:
A4GL_SOB_EXT=.aso
#static library:
A4GL_LIB_EXT=.aox
#shared library:
A4GL_SOL_EXT=.asx
#Form file:
A4GL_FRM_BASE_EXT=.afr
#Menu file
A4GL_MNU_BASE_EXT=.mnu
#Packer extensions (added to resource files: form/menu...)
A4GL_XML_EXT=.xml
A4GL_PACKED_EXT=.dat
#help file
A4GL_HLP_EXT=.hlp
#ace intermediate file (to be converted to 4gl, or run using Perl aace runner)
#A4GL_ACERC_EXT=.aarc.xml
A4GL_ACERC_EXT=.aarc


#This to composite variables (A4GL_MNU_EXT and A4GL_FRM_EXT exist only in Amake
#FIXME: reverse => ${A4GL_FRM_BASE_EXT}${A4GL_XML_EXT}
ifeq "${A4GL_CURR_PACKER}" "XML"
	#Compiled form
	A4GL_FRM_EXT=${A4GL_FRM_BASE_EXT}${A4GL_XML_EXT}
	#Compiled menu:
	A4GL_MNU_EXT=${A4GL_MNU_BASE_EXT}${A4GL_XML_EXT}
endif
ifeq "${A4GL_CURR_PACKER}" "PACKED"
	#Compiled form
	A4GL_FRM_EXT=${A4GL_FRM_BASE_EXT}${A4GL_PACKED_EXT}
	#Compiled menu:
	A4GL_MNU_EXT=${A4GL_MNU_BASE_EXT}${A4GL_PACKED_EXT}
endif

#Files that compiler created, but are not neded at run-time, that are safe to delete:
A4GL_TMP_SUFFIXES_DELETE=${A4GL_OBJ_EXT} ${A4GL_LIB_EXT} .err .glb
#All files that compiler created, but are not neded at run-time
A4GL_TMP_SUFFIXES   = ${A4GL_TMP_SUFFIXES_DELETE} .c .h
#Files that compiler created, needed at run-time
A4GL_SUFFIXES 		= ${A4GL_EXE_EXT} ${A4GL_FRM_EXT} ${A4GL_HLP_EXT} ${A4GL_MNU_EXT} ${A4GL_SOB_EXT} ${A4GL_SOL_EXT}

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
#build x.${A4GL_EXE_EXT} and we have x.4gl, this rule will be invoked
#with just one (${A4GL_EXE_EXT}.4gl) source file, instead with all the 4gl
#files needed:
#.4gl${A4GL_EXE_EXT}:
%${A4GL_EXE_EXT}: %.4gl
	${A4GL_CL} -o$@ $< ${A4GL_CL_LDFLAGS}


####################################
# Rule to compile an object file from a 4gl file
#
#Note: we don't want to have separate rules for 4gl->c and then from c->o because
#we want to allways have the dependency of the object to the 4gl source file.
#Otherwise, make would be happy when it see that object is up-to-date in
#respect to the c file, and ignore possible change in 4gl file
#On Windows when using Cygwin tools (that use UNIX paths and Cygwing path mangling) and native
#Windows 4glc and gcc (that know nothing about this CigWin paths) we need to add path to CygWin
#installation in front of any source file paths specified in rule call:
#Note: we can produce .glb file by specifying --globals and that would be
#much faster then doing a full compile
#.4gl${A4GL_OBJ_EXT}:
%${A4GL_OBJ_EXT} %.glb: %.4gl
ifeq "${USE_4GLPC}" "1"
	${FAIL_CMPL_4GL}${A4GL_CC} $< -c -o ${OBJSTORE}$@
else
#-I to the directory 4GL file is in is needed for Informix ESQL/C compiler,
#otherwise .h file created by 4glc will not be found by esql executable
	${FAIL_CMPL_4GL}@if test "$(<D)" = "" -o "$(<D)" = "."; then \
		EXEC="${A4GL_CC} $< -c -o ${OBJSTORE}$@"; \
	else \
		EXEC="${A4GL_CC} -I$(<D) ${CYGWIN_ROOT}$< -c -o ${OBJSTORE}$@"; \
	fi; \
	echo $$EXEC; \
	$$EXEC; \
	exit $$?;
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
	${AMAKE} $<

lib%${A4GL_LIB_EXT}:  $(subst lib,,%.mk)
	@echo "Making library $*.aox using $^"
	${AMAKE} $<



####################################
# Rule for compiling form files
%${A4GL_FRM_EXT}: %.per
#	${FAIL_CMPL_FRM}${A4GL_FC} $^ ${FORMSTORE}$@
	${FAIL_CMPL_FRM}${A4GL_FC} $<

#Rules for compiling forms when packer is given by specific extension
%${A4GL_FRM_BASE_EXT}${A4GL_PACKED_EXT}: %.per
	${FAIL_CMPL_FRM}export A4GL_PACKER=PACKED; export A4GL_FORMTYPE=GENERIC;${A4GL_FC} $<
%${A4GL_FRM_BASE_EXT}${A4GL_XML_EXT}: %.per
	${FAIL_CMPL_FRM}export A4GL_PACKER=XML; export A4GL_FORMTYPE=GENERIC;${A4GL_FC} $<


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
	${FAIL_CMPL_HLP}${A4GL_MC} $^ $@
#because of this make fill always recompile help file, since it can't
#find .hlp files; can we make aubit compiler to automatically look for
#.hlp if it can't find .iem (or other extension sopecified in code):
#	mv $@ $*.iem

####################################
# Rule for Aubit/Plexus Menu compiler
#
%${A4GL_MNU_EXT}: %.menu
	aubit mcompile $<

####################################
# Rule for Aubit/Plexus Menu compiler
#%.mnu: %${A4GL_MNU_EXT}
%${A4GL_MNU_EXT}: %.menu
	aubit mcompile $<

###################################
#Rule to compile Ace report files to intermediate file
%${A4GL_ACERC_EXT}: %.ace
	export A4GL_PACKER=XDR; aubit aace $<


###################################
#Rule to convert aace compiled file to 4gl code
#NOTE: it will ALLWAYS include MAIN block.
#FIXME: add a --nomain switch to aace_4gl
#NOTE: aace_4gl does NOT work on .xml files created by aace (Bad format)
.PRECIOUS: %.4gl
%.4gl: %${A4GL_ACERC_EXT}
	aubit aace_4gl $< > $@



#--------------------------- EOF --------------------------------






