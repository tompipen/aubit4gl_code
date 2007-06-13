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

#	 $Id: a4gl.mk,v 1.62 2007-06-13 16:36:19 mikeaubury Exp $

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

ifndef SH
	ifdef COMSPEC
		SH				=bash
	else
		SH				=sh
	endif
endif

ifndef SHELL
	SHELL=${SH}
endif

#------- end of common stuff ------------

ifeq "${MAKEFILE_COMMON_INCLUDED}" "1"
	#We are in the Aubit compier source code tree - so aubit-config was probably
	#not installed yet - and therefore not in the path. So we will have to provide
	#full path to it. If we don't, we will a) not get any value returned, and 
	#b) we will get garbage [ (@(@ to be specific ] when running a makefile 
	AUBIT_CONFIG=${AUBITDIR}/bin/aubit-config
else
	AUBIT_CONFIG=aubit-config
endif


#Despite of the use of 2>/dev/null, this will print rubbish (�&@�&@) to stdout when
#aubit-config is not installed yet. That's why we have to use the 'trick' with 
#x=`...`; echo $x
A4GL_CURR_PACKER:=$(shell x=`${AUBIT_CONFIG} A4GL_PACKER 2> /dev/null`; echo $$x )
FORMTYPE:=$(shell x=`${AUBIT_CONFIG} A4GL_FORMTYPE 2> /dev/null`; echo $$x )

ifeq "${A4GL_CURR_PACKER}" ""
	A4GL_CURR_PACKER=PACKED
endif

##########################################################################
# Compilers and flags
##########################################################################

###########################
#Name of the warper script for all Aubit commands, that we expect in the PATH
AUBIT_WRAPER		= ${SHELL} aubit

###########################
#Define command to be used to run Aubit compiler executables
ifdef COMSPEC
	#Must incoke shell scripts with bash on CygWin, since sh is default
	#and sh is NOT bash, and it will fail because it does not understand
	#functions
	AUBIT_CMD   		=${AUBIT_WRAPER}
else
	AUBIT_CMD   		=${AUBIT_WRAPER}
endif

###########################
#To find out if we are using MinGW, we can try:
ifdef COMSPEC
	MINGW			:=$(shell mingw32-gcc --version 2>/dev/null)
endif

###########################
#If this compilers needs objects at run-time, set to 'yes':
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
#do we want to use 4glpc shell script, or will we invoke 4glc directly
ifdef COMSPEC
	#We are on Windows
	ifeq "${MINGW}" ""
		#On Windows, but not using MinGW - so we are using CygWin
		#on CygWin (not MinGW) we have to use 4glpc because of the bug in 
		#CygWin implementation of getopt_long()
		USE_4GLPC	=1
	else
		#On Windows, using MinGW
		#We should use 4glc since we may not have shell installed
		#and 3glpc is a shell script
		USE_4GLPC	=0
	endif
endif
ifeq "${USE_4GLPC}" "1"
	#We are forced to use 4glpc
	ifneq "${FGLPCEXEC}" ""
		A4GL_FGLC	=${FGLPCEXEC}
	else
		A4GL_FGLC	=4glpc
	endif
	A4GL_CC_CMD     =${AUBIT_CMD} ${A4GL_FGLC} ${EXTRA_4GLC}
else
	#default
	USE_4GLPC		=0
	ifeq "${A4GL_FGLC}" ""
		A4GL_FGLC		=4glc 
	endif
	A4GL_CC_CMD     =${AUBIT_CMD} ${A4GL_FGLC} ${EXTRA_4GLC}
	#--clean
endif
A4GL_CC_ENV     =
#Variable VERBOSE is usually set by 'amake' but can be set in 
#shell environemnt too
ifeq "${VERBOSE}" "1"
	A4GL_CC_FLAGS   = --verbose
endif

###########################
# A4GL C-code Linker
A4GL_CL_CMD     = ${A4GL_CC_CMD}
A4GL_CL_ENV     = ${A4GL_CC_ENV}
A4GL_CL_FLAGS   = ${A4GL_CC_FLAGS}
A4GL_CL_LDFLAGS = ${LDFLAGS}

###########################
# A4GL Form Compiler
A4GL_FC_CMD     = ${AUBIT_CMD} fcompile
A4GL_FC_FLAGS   =

###########################
# A4GL Message Compiler
A4GL_MC_CMD     = ${AUBIT_CMD} amkmessage
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

ifeq "${A4GL_FAKELEXTYPE}" "PCODE"
	#In case of the p-code compilation, we need to add packer extension:
	#FIXME: currently p-code compiler supports only single module,
    #so program (TARGET) and object extensions are same
	A4GL_PCODE_EXT=.4pe
	ifeq "${A4GL_CURR_PACKER}" "PACKED"
		A4GL_EXE_EXT=${A4GL_PCODE_EXT}.dat
		A4GL_OBJ_EXT=${A4GL_PCODE_EXT}.dat
    endif
	ifeq "${A4GL_CURR_PACKER}" "XML"
		A4GL_EXE_EXT=${A4GL_PCODE_EXT}.xml
    	A4GL_OBJ_EXT=${A4GL_PCODE_EXT}.xml
    endif
    #To run P-code you must NOT have packer extension:
	A4GL_RUN_EXT=${A4GL_PCODE_EXT}
	
	DEFAULT_LINK=cp prog${A4GL_OBJ_EXT} progname${A4GL_EXE_EXT}
else
	#Executable (compile):
	A4GL_EXE_EXT=.4ae
	#Execute extension:
	A4GL_RUN_EXT=${A4GL_EXE_EXT}	
	#static object:
	A4GL_OBJ_EXT=.ao

	#define default linking action
	DEFAULT_LINK=${A4GL_FGLC} $^ -o $@
	
endif

#Used in 4glpc
export A4GL_OBJ_EXT

#shared object (single 4gl module compiled to shared library):
A4GL_SOB_EXT=.aso
#static library:
A4GL_LIB_EXT=.aox
#shared library (More then one object (4gl module) linked in a shared library):
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

#Consider this; there is object in common/x.ao; .4ge rule finds x.ao using 
#VPATH in common; rule to make .ao references .4gl; 4gl is found in common/
#Make rebuilds .ao using common.4gl, and puts resulting .ao in current directory
#(because if it puts it anywhere else, and not target exists at make invocation 
#linking will fail, because at that stage 
#prerequisites for .4ae where allready evaluated) then new target will be linked AGAIN
#with OLD common/x.ao and NOT with just created ./x.ao
#
#All targets should go where source file is, but I can't do it because
#link line prerequisites VPATH will not find them, since they will be made
#AFTER prereqiosites where searched for... And I cant find a way to force
#make to evaluate them AFTER...


####################################
# Rule to compile executable from single 4gl file
#
#problem with this rule is, that when there is no explicit rule to
#build x.${A4GL_EXE_EXT} and we have x.4gl, this rule will be invoked
#with just one (${A4GL_EXE_EXT}.4gl) source file, instead with all the 4gl
#files needed:
#warning we depend on this rule in tools/test/makefile
#.4gl${A4GL_EXE_EXT}:
%${A4GL_EXE_EXT}: %.4gl
	${A4GL_CL} -o$@ $< ${A4GL_CL_LDFLAGS}


####################################
# Rule to compile an STATIC object file from a 4gl file
#
#Note: we don't want to have separate rules for 4gl->c and then from c->o because
#we want to allways have the dependency of the object to the 4gl source file.
#Otherwise, make would be happy when it see that object is up-to-date in
#respect to the c file, and ignore possible change in 4gl file
#On Windows when using Cygwin tools (that use UNIX paths and Cygwing path mangling) and native
#Windows 4glc and gcc (that know nothing about this CygWin paths) we need to add path to CygWin
#installation in front of any source file paths specified in rule call:
#Note: we can produce .glb file by specifying --globals and that would be
#much faster then doing a full compile when all we need is a .glb file
#
#Why was I not placing objects in same place source file is in? Try this:
#OBJECTS_WITH_SOURCE=1
#Because makefiles like Amake OneMax ones dont know where source file is;
#all they know there is x.4gl required, and that it has to result in x.aso
#to link it in executable. Our rule will use VPATH to find 4gl, but .aso
#is allready on the link line - WITHOUT THE PATH and so it is expected in
#current directory... For link rule to find object outside current dir that 
#we just now created, we would have to restart the link target somehow, to 
#force make to look for it again.
#
%${A4GL_OBJ_EXT} %${A4GL_SOB_EXT} %.glb: %.4gl
ifeq "${USE_4GLPC}" "1"
	${FAIL_CMPL_4GL}${A4GL_CC} $< -c -o ${OBJSTORE}$*${A4GL_OBJ_EXT}
else
#-I to the directory 4GL file is in is needed for Informix ESQL/C compiler,
#otherwise .h file created by 4glc will not be found by esql executable
#$(<D) is directory part of the first prerequisite
#$(@D) is directory part of the file name of the target
#$* implicit rule match part
#@F filename of the target

	${FAIL_CMPL_4GL}@\
	if test "$(suffix $@)" = "${A4GL_SOB_EXT}" ; then \
		SO_FLAG="--shared" ; \
		TARGET_SUFFIX="${A4GL_SOB_EXT}" ; \
	else \
		TARGET_SUFFIX="${A4GL_OBJ_EXT}" ; \
	fi ; \
	if test "${OBJSTORE}" != "" ; then \
		OUTPUTPATH="${OBJSTORE}" ; \
	else \
		if test "$(@D)" != "" -a "$(@D)" != "." ; then \
			OUTPUTPATH="$(@D)/" ; \
		else \
			if test "$(<D)" != "" -a "$(<D)" != "." -a "$(OBJECTS_WITH_SOURCE)" = "1"; then \
				OUTPUTPATH="$(<D)/" ; \
			fi ; \
		fi ; \
	fi ; \
	BASENAME="${basename $(@F)}" ; \
	OUTOBJ="$$OUTPUTPATH$$BASENAME$$TARGET_SUFFIX" ; \
	if test "$(<D)" = "" -o "$(<D)" = "."; then \
		EXEC="${A4GL_CC} $< $$SO_FLAG -c -o $$OUTOBJ" ; \
	else \
		EXEC="${A4GL_CC} -I$(<D) ${CYGWIN_ROOT}$< $$SO_FLAG -c -o $$OUTOBJ" ; \
	fi; \
	echo $$EXEC; \
	$$EXEC; RET=$$?; \
	exit $$RET;
endif
#if test -f $*.cpc.err ; then cat $*.cpc.err >> /tmp/cpc_errors.log ; fi; \

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
#FIXME: Aubit will not look for help file in executable directory,
#it will look only in current directory (.) and fail if program is
#executed from anywhere else!
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
	${AUBIT_CMD} mcompile $<

####################################
# Rule for Aubit/Plexus Menu compiler
#%.mnu: %${A4GL_MNU_EXT}
%${A4GL_MNU_EXT}: %.menu
	${AUBIT_CMD} mcompile $<

###################################
#Rule to compile Ace report files to intermediate file
%${A4GL_ACERC_EXT}: %.ace
	export A4GL_PACKER=XDR; ${AUBIT_CMD} aace $<


###################################
#Rule to convert aace compiled file to 4gl code
#NOTE: it will ALLWAYS include MAIN block.
#FIXME: add a --nomain switch to aace_4gl
#NOTE: aace_4gl does NOT work on .xml files created by aace (Bad format)
.PRECIOUS: %.4gl
%.4gl: %${A4GL_ACERC_EXT}
	${AUBIT_CMD} aace_4gl $< > $@



#--------------------------- EOF --------------------------------






