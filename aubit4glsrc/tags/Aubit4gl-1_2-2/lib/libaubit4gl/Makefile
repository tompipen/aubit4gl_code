# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   lib makefile				 |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+

#
# $Id: Makefile,v 1.54 2009-10-16 10:04:38 mikeaubury Exp $
#

ROOT    	=../..
LIBROOT		=..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Source files
## ==================================================================

CMODS_PROJECT	=project.c

#List of API specification files used to generate .c/.h pair
#created headers are included via a4gl_libaubit4gl_int.h
API_SPEC    =API_esql.spec API_help.spec API_menu.spec API_packer.spec \
			API_form.spec  API_ui.spec  API_sqlparse.spec \
			API_sql.spec API_rpc.spec API_exreport.spec

#List of all Aubit API interfaces source files, part of libaubit4gl,
#generated from .spec files:
CMODS_API   =${API_SPEC:.spec=.c}

#List of all non-API source files of libaubit4gl, -- IN ALPHABETIC ORDER -- :
COMMONSRC= \
	attributes.c \
	builtin.c builtin_d.c \
	calldll.c mem.c assert.c fglextra.c net.c object.c ui_window.c ui_interface.c basechannel.c passreference.c int8.c conv.c compat.c corba_server_util.c \
	data_if.c common_ui.c dates.c dir.c dmy.c datatypes.c dataio.c decimal.c dynmem.c debug.c \
	err.c error.c errfile.c sqlexpr.c expr.c  extfile.c eval_field.c  \
	mapm/mapmutil.c mapm/mapmutl1.c mapm/mapmutl2.c mapm/mapm_add.c mapm/mapm_div.c mapm/mapm_mul.c \
	mapm/mapm_rnd.c mapm/mapmcnst.c mapm/mapmstck.c mapm/mapm_fft.c mapm/mapm_set.c mapm/mapm_fpf.c mapm/mapmfmul.c \
	mapm/mapmistr.c mapm/mapm_flr.c mapm/mapm_rcp.c mapm/mapmgues.c \
	fglwrap.c finderr.c funcs_d.c function_call_stack.c file.c \
	gtime.c gen_stack.c gui_io.c gui.c \
	helper.c \
	io.c interval.c \
	keys.c \
	load.c \
	match.c maths.c memfile.c \
	ns.c \
	others.c ops.c outer.c  querix_compat.c \
	pointers.c parsecommon.c \
	read_dty.c readkeys.c report.c rexp2.c ${LIBROOT}/resource/resource.c \
	screen.c sql_common.c sqlconvert.c stack_ops.c stack.c string.c sqlca.c ui_objects/ui_combobox.c \
	translate.c missing.c curl.c \
	ui.c

CMODS               =${COMMONSRC} ${LIBROOT}/generated/${CMODS_PROJECT} ${CMODS_API} 
OBJS_API			=${CMODS_API:.c=.o}
OBJS				=${CMODS:.c=.o}

## ==================================================================
##                              Options
## ==================================================================

LIBINCL_PATH	=${LIBROOT}/libincl
INCL_PATH		=${ROOT}/incl
DLMAGIC			=${LIBROOT}/bin/dlmagic
ALL				=api ${LIBROOT}/lib${AUBITLIBFULL}${SO_EXT_LINKABLE} ${LIBROOT}/libaubit4gl${SO_EXT_LINKABLE} \
					API_form_self.c API_help_self.c
CFLAGS			+=-I.

#we don't want -Wall in CFLAGS when compiling form_x_xdr.c because it would
#give us bunch of warnings about unised varibles, that we cannot fix
#because this file is generated by rpcgen:
CFLAGS_FORM_X_XDR_C =$(CFLAGS:%-Wall=%)

#we cannot compile API code with  -Wstrict-prototypes because we use
#static int (*func)	(); which need variable number of parameters:
CFLAGS_API_C 		=$(CFLAGS:%-Wstrict-prototypes=%)

ifeq "${NON_PEDANTIC_OK}" "1"
	CFLAGS_NO_PEDANTIC  =$(CFLAGS:%-pedantic=%)
else
	CFLAGS_NO_PEDANTIC  =${CFLAGS}
endif

LCLINT_CFLAGS   	=${C_IFLAGS} -I.

## ==================================================================
##                        Platform specific options
## ==================================================================

#ifeq "${TARGET_OS}" "solaris"
	#LINK_LIBS		+=-lsocket
#endif


ifeq "${USE_LIBDL}" "1"
	LINK_LIBS=-ldl
endif

ifeq "${TARGET_OS}" "hpux"
	LINK_LIBS           +=-lcl -lm -lnsl
endif

ifneq "${TARGET_OS}" "cygwin"
	ifneq "${GCC_MINGW}" "yes"
		LINK_LIBS           +=-lm
	endif
endif


ifeq "${GCC_MINGW}" "yes"
	#Needed for strcasecmp():
	LINK_LIBS		+=-lmoldname
	#Needed for getservbyname():
	LINK_LIBS		+=-lwsock32
endif

ifeq "${TARGET_OS}" "darwin"
		#This is to make ONLY dlopen() loadable library, not a standard
        #shared one, ("bundle") so we will need separate setting for
		#libaubit4gl.dynlib
		#
		#cc -dynamiclib -install_name /usr/local/lib/libfoo.2.dylib \
		# -compatibility_version 2.4 -current_version 2.4.5 \
		# -o libfoo.2.4.5.dylib source.o code.o
		#rm -f libfoo.2.dylib libfoo.dylib
		#ln -s libfoo.2.4.5.dylib libfoo.2.dylib
		#ln -s libfoo.2.4.5.dylib libfoo.dylib
		#
		#Also note that the static linker will use the libfoo.dylib symlink,
		#while the dynamic linker will use the libfoo.2.dylib symlink. It is
		#possible to point these symlinks at different minor revisions of
		#the library.

        INST_PATH=$(INSTALL_DIR)/lib
		INST_NAME=${INST_PATH}/libaubit4gl${SO_EXT_LINKABLE}
        #INST_NAME=${AUBITDIR}/lib/libaubit4gl${SO_EXT_LINKABLE}

        SO_LDFLAGS1=$(SO_LDFLAGS:%-flat_namespace=%)
		SO_LDFLAGS2=$(SO_LDFLAGS1:%-bundle=%)
		SO_LDFLAGS3=$(SO_LDFLAGS2:%-undefined=%)
		#SO_LDFLAGS_NOBUNDLE=-r $(SO_LDFLAGS3:%suppress=%)
		SO_LDFLAGS_NOBUNDLE=-dynamiclib \
			-install_name ${INST_NAME} \
			$(SO_LDFLAGS3:%suppress=%) ${CFLAGS}
        #FIXME: -install_name like this will not work after 'make install'!
        #since is in effect hard coded path to the lib file
		#we will have to link two libraries, one for use in source tree,
        #and one to install
	CC=glibtool --mode=compile gcc
	LD=glibtool --mode=link gcc
else
		SO_LDFLAGS_NOBUNDLE=${SO_LDFLAGS}
endif

ifeq "${HAVE_ZLIB}" "1"
	LINK_LIBS		+=-lz
endif

ifeq "${HAVELIBCURL}" "1"
	LINK_LIBS 	+=${LIBCURL_LIBS}
endif

.PHONY: all ci splint lclint api clean clean.generated clean.api api.headers lib

## ==================================================================
##                              Targets
## ==================================================================

#################################
# Build all default targets
all: ${ALL}
	@echo "Default targets (${ALL}) built successfully."

info.linklibs:
	echo ${LINK_LIBS}
info:
	echo ${SO_LDFLAGS}
#################################
# Build Aubit library file
# NOTE: we are building versioned library; un-versioned one is a link to versioned library
${LIBROOT}/lib${AUBITLIBFULL}${SO_EXT_LINKABLE}: $(OBJS)
	${LD} ${SO_LDFLAGS_NOBUNDLE} -o $@ $^ ${LINK_LIBS} ${EXTRASYSTEMLIBS}
ifeq "${TARGET_OS}" "darwin"
	${MKPATH} ${INST_PATH}
	${CP} $@ ${INST_PATH}
	${CP} $@ ${INST_PATH}/libaubit4gl.dylib
endif
ifeq "${SO_EXT_LINKABLE}" ".dll"
#Note - no linking on Windows
	${MV} TMP${SOEXP_EXT} $@.a
endif


##################################
# Create (link or copy) libaubit4gl without version string
lib: ${LIBROOT}/libaubit4gl${SO_EXT_LINKABLE}
${LIBROOT}/libaubit4gl${SO_EXT_LINKABLE}: ${LIBROOT}/libaubit4gl-${A4GL_VERSION_STRING}${SO_EXT_LINKABLE}
ifeq "${COMSPEC}" ""
#Please dont use hard links!
	ln -s $^ $@
else
#Note - no linking on Windows
	cp $^ $@
	cp $^.a $@.a
endif


## ==================================================================
##                             Sub Targets
## ==================================================================

test:
	echo ${CFLAGS}
	echo "All = $(ALL)"
	echo  $(addprefix ${INCL_PATH}/a4gl_,${API_SPEC:.spec=.h})



################
#Rule to make API objects
#Every API object needs coresponding .c file and ALL of the API headers:
API_%.o: API_%.c $(addprefix ${INCL_PATH}/a4gl_,${API_SPEC:.spec=.h})
	${CC} ${CFLAGS_API_C} -c -o $@ $< 


ci: $(CMODS)
	ci -l  $^

curl.o: curl.c
	${CC} ${CFLAGS} ${LIBCURLCPPFLAGS}  -c -o $@ $^

decimal.o: decimal.c
	${CC} -Imapm -DUSE_MAPM ${CFLAGS} -c -o $@ $^

funcs_d.o: funcs_d.c
	${CC} -Imapm -DUSE_MAPM ${CFLAGS} -c -o $@ $^
ops.o: ops.c
	${CC} -Imapm -DUSE_MAPM ${CFLAGS} -c -o $@ $^
mapm.a: mapm.c
	${CC} -Imapm -DUSE_MAPM ${CFLAGS} -c -o $@ $^

project.o: ${LIBROOT}/generated/${CMODS_PROJECT}
	${CC} ${CFLAGS} -c -o $@ $^

${LIBROOT}/generated/project.c:
	(cd ${ROOT}/tools/project; ${SH} mkproject)

${LIBROOT}/generated/tmperrs.h :
	(cd ${LIBROOT}; ${SH} ${LIBROOT}/bin/mkerrors)

${ROOT}/compilers/fcompile/form_x_xdr.c  ${ROOT}/compilers/fcompile/form_x.h:
	${MAKE} -C ${ROOT}/compilers/fcompile rpc

${ROOT}/compilers/fcompile/form_x_xdr.o: ${ROOT}/compilers/fcompile/form_x_xdr.c
	${CC} ${CFLAGS_FORM_X_XDR_C} -c -o $@ $^

builtin.o: builtin.c
	${CC} ${CFLAGS_NO_PEDANTIC} -c -o $@ $*.c
stack.o: stack.c
	${CC}  ${CFLAGS_NO_PEDANTIC} -c -o $@ $*.c
stack_ops.o: stack_ops.c
	${CC}  ${CFLAGS_NO_PEDANTIC} -c -o $@ $*.c
debug.o: debug.c
	${CC} ${CFLAGS_API_C} -c -o $@ $^

${ROOT}/common/dataio/form_x.x.h:
	${MAKE} -C ${ROOT}/common/dataio form_x.x.h

${ROOT}/common/dataio/fgl.x.h:
	${MAKE} -C ${ROOT}/common/dataio fgl.x.h


sqlconvert.o: sqlconvert.c ${ROOT}/lib/generated/sql_convert_constants.h
	${CC}  ${CFLAGS_NO_PEDANTIC} -I${ROOT}/lib -c -o $@ $*.c

${ROOT}/lib/generated/sql_convert_constants.h: ${ROOT}/lib/bin/convertsql.constants ${ROOT}/lib/bin/mk_convertsql
	${SH} ${ROOT}/lib/bin/mk_convertsql ${ROOT}/lib/bin/convertsql.constants > ${ROOT}/lib/generated/sql_convert_constants.h

## ==================================================================
##                        Dependencies
## ==================================================================

error.c : ${LIBROOT}/generated/tmperrs.h
array.o: array.c ${ROOT}/compilers/fcompile/form_x_xdr.c
builtin.o API_ui.c: ${ROOT}/compilers/fcompile/form_x.h
${COMMONSRC}: api ${ROOT}/common/dataio/form_x.x.h ${ROOT}/common/dataio/fgl.x.h
${CMODS_API}: ${ROOT}/common/dataio/form_x.x.h ${ROOT}/common/dataio/fgl.x.h

${LIBROOT}/resource/resource.o:
	${MAKE} -C ${LIBROOT}/resource resource.o 

## ==================================================================
##                         Other Targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"

## ==================================================================
##                         API Targets
## ==================================================================

################
#Target to create ALL API objects. Must include list of all API header files
#as dependency since they are all included via a4gl_aubit4gl.h
api: $(addprefix ${INCL_PATH}/a4gl_,${API_SPEC:.spec=.h}) ${OBJS_API} 
	@echo "Sucessfuly created API objects:"
	@echo ${OBJS_API}

###############
#Target to crate all API headers files
api.headers: $(addprefix ${INCL_PATH}/a4gl_,${API_SPEC:.spec=.h}) ${ROOT}/common/dataio/fgl.x.h
	@echo "Sucessfuly created API headers"

################
#Rule to make API .c file from .spec file
#When API c file is generated, coresponding .h file must also be created, but
#not in same target, since we need a way to create ALL headers in one go, since
#they are needed for all targets, because they are included in a4gl_aubit4gl.h:
API_%.c: API_%.spec ${INCL_PATH}/a4gl_API_%.h
	${SH} ${DLMAGIC} $< > $@
	${SH} ${DLMAGIC} $< -S > ${@:.c=_self.c}

################
#Rule to make API header from .spec file:
${INCL_PATH}/a4gl_API_%.h: API_%.spec 
	${SH} ${DLMAGIC} $^ -h > $@
	${SH} ${DLMAGIC} $^ -H > ${@:.h=_lib.h}

################
# Eventually - we are going to allow compilation of libaubit4gl
# with certain plugins pre-compiled in.
# In order to do this - we are going to replace the API code generated by dlmagic
# with API code generated by dlmagic_self
#
API_%_self.c: API_%.spec
	${SH} ${DLMAGIC}  $^ -S > $@

#The former is needed for the API_ui.c in lib/libaubit4gl the latter for the libui/* stuff
#Andrej: former and latter ?what? 



libaubit4gl.a: $(OBJS)
	ar rc libaubit4gl.a $^

## ==================================================================
##                        Clean Targets
## ==================================================================

#################
#Clean all files created in the process of making libaubit4gl:
clean : clean.generated clean.api
	${RM} $(OBJS) $(OBJS_DEBUG) menu_x.h menu_x_xdr.c \
		form_x_xdr.c form_x.h project.c core lclint.log \
		*.out *.glb *${SO_EXT_LINKABLE} *.a  *.o  *.bak *.dll *.stackdump *.err \
		*.base *.exp *.def .\#* API_lex.c \
		${LIBROOT}/libaubit4gl${SO_EXT_LINKABLE} ${LIBROOT}/lib${AUBITLIBFULL}${SO_EXT_LINKABLE} \
		${LIBROOT}/libaubit4gl${SO_EXT_LINKABLE}.a ${LIBROOT}/lib${AUBITLIBFULL}${SO_EXT_LINKABLE}.a

#################
#Clean all generated files (except API files)
clean.generated:
	${RM} ${LIBROOT}/generated/errdefs ${LIBROOT}/generated/tmperrs.h \
		${LIBROOT}/generated/project.c ${LIBROOT}/generated/project.o

#################
#Clean all .c and .h files created from .spec files, and object files
#for all API's
clean.api:
	${RM} $(addprefix ${INCL_PATH}/a4gl_,${API_SPEC:.spec=.h}) ${API_SPEC:.spec=.c} \
	${OBJS_API} $(addprefix ${INCL_PATH}/a4gl_,${API_SPEC:.spec=_lib.h}) \
	API_esql_self.c API_exreport_self.c API_form_self.c API_help_self.c \
	API_menu_self.c API_packer_self.c API_rpc_self.c API_sql_self.c \
	API_sqlparse_self.c API_ui_self.c

#----------------------------------- EOF -------------------------------


	

