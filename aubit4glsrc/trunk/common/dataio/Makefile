# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
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
# $Id: Makefile,v 1.2 2008-02-12 12:46:58 mikeaubury Exp $
#

ROOT        =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                    		Settings
## ==================================================================

LOCAL_IFLAGS=-I..
CFLAGS      +=${LOCAL_IFLAGS} -D_NO_FORM_X_H_

#we don't want -Wall in CFLAGS when compiling rpcgen generated code because it would
#give us bunch of warnings about unused varibles, that we cannot fix:
CFLAGS_RPCGEN	=$(CFLAGS:%-Wall=%)

RPC		=${PLUGINDIR}/libXDRPACKER_struct_form${SO_EXT} \
		${PLUGINDIR}/libXDRPACKER_report${SO_EXT} \
		${PLUGINDIR}/libXDRPACKER_module${SO_EXT}  \
		${PLUGINDIR}/libXDRPACKER_module_definition${SO_EXT}  

XGEN	=${PLUGINDIR}/libDATA_struct_form${SO_EXT} \
		${PLUGINDIR}/libDATA_report${SO_EXT} \
		${PLUGINDIR}/libDATA_module${SO_EXT} \
		${PLUGINDIR}/libDATA_module_definition${SO_EXT}

ANY		=${PLUGINDIR}/libDATA_any${SO_EXT}

ifneq "${COMSPEC}" ""
	LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
	ALL         =${LIBROOT}/libaubit4gl.${SO_EXT}
endif
#How do I say "OR" here??
ifeq "${TARGET_OS}" "solaris"
	LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
	ALL         =${LIBROOT}/libaubit4gl.${SO_EXT}
endif

#ALL 	+=${XGEN} ${ANY}
ALL 	+=${XGEN}

#...but we do need rpcgen:
ifeq "${USE_RPCGEN}" "0"
	#FIXME: update this:
	RPCGEN_FORM		=${CP} ${ROOT}/tools/cygwin/form_x_xdr.c ${ROOT}/tools/cygwin/form_x.h .
	RPCGEN_REPORT		=${CP} ${ROOT}/tools/cygwin/report_xdr.c .
	RPCGEN_FGL		=${CP} ${ROOT}/tools/cygwin/fgl_xdr.c .
	RPCGEN_MENU		=${CP} ${ROOT}/tools/cygwin/menu_x_xdr.c .
	RPCGEN_PCODE		=${CP} ${ROOT}/tools/cygwin/npcode_xdr.c .
	#Is there any point in doing this? Not on Windows, since unresolved dependencies are not
    #allowed at link time, and we have no RPCLIB to link with anyway:
	ifeq "${COMSPEC}" ""
		ifneq "${GCC_MINGW}" "yes"
            #No point in making XDR format libraries with CygWin Sun RPC, usign MinGW GCC - they
            #Would depend on cygwin1.dll, and MinGW GCC would not link it in. We can use XDR libs
            #compiled using CygWin GCC, if we provide cygwin1.dll at runtime, but why do we
            #want to use XDR format any more - we have PACKED, and XML?
			
			#In therory, we should be able to compile this from precompiled files,
            #end we dont need to have rpclib to do this (we do to run it)
            #but since we now have packers, what's the point?
			ifneq "1" "0"
				ALL			+=${RPC}
            endif
        endif
    endif
else
	RPCGEN_FORM	=${RPCGEN} form_x.x
	RPCGEN_REPORT   =${RPCGEN} report.x
	RPCGEN_FGL   	=${RPCGEN} fgl.x
	RPCGEN_MENU     =${RPCGEN} menu_x.x
	RPCGEN_PCODE    =${RPCGEN} npcode.x
	ifneq "${GCC_MINGW}" "yes"
		#No point in making XDR format libraries with CygWin Sun RPC, usign MinGW GCC - they
        #Would depend on cygwin1.dll, and MinGW GCC would not link it in. We can use XDR libs
        #compiled using CygWin GCC, if we provide cygwin1.dll at runtime, but why do we
        #want to use XDR format any more - we have PACKED, and XML?
		ALL				+=${RPC}
    endif
endif
ifneq "${COMSPEC}" ""
	LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
endif

ifeq "${HAVE_RPCLIB}" "0"
	CFLAGS      +=-I${ROOT}/tools/no_rpc/cygwin
endif

XGENEXE    		=${ROOT}/bin/xgen

## ==================================================================
##                          Targets
## ==================================================================

all: pluginsdir ${ALL}
	@echo "Default targets (${ALL}) built successfully."

${PLUGINDIR}/libDATA_struct_form${SO_EXT}: form_x.xi.o form_x.xio.o form_x.xo.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}


${PLUGINDIR}/libDATA_report${SO_EXT}: report.xi.o report.xio.o report.xo.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}

${PLUGINDIR}/libDATA_module${SO_EXT}: npcode.xi.o npcode.xio.o npcode.xo.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}


${PLUGINDIR}/libDATA_module_definition${SO_EXT}: fgl.xi.o fgl.xio.o fgl.xo.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}

${PLUGINDIR}/libXDRPACKER_struct_form${SO_EXT}:	form_x_xdr.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS} ${RPCLIB_NAME}


${PLUGINDIR}/libXDRPACKER_report${SO_EXT}:  		report_xdr.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS} ${RPCLIB_NAME}

${PLUGINDIR}/libXDRPACKER_module${SO_EXT}:  		npcode_xdr.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS} ${RPCLIB_NAME}

${PLUGINDIR}/libXDRPACKER_module_definition${SO_EXT}:  		fgl_xdr.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS} ${RPCLIB_NAME}

#FIXME: why not use this, or is it obsolete?
${PLUGINDIR}/libDATA_any${SO_EXT}: menu_x.xio.o form_x.xio.o report.xio.o npcode.xio.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}

## ==================================================================
##                          Sub-targets
## ==================================================================

form_x_xdr.c: form_x.x
#	@echo "RPCGEN_FORM=${RPCGEN_FORM}"
	${RPCGEN_FORM}

menu_x_xdr.c: menu_x.x
	${RPCGEN_MENU}

npcode_xdr.c: npcode.x
	${RPCGEN_PCODE}

report_xdr.c: report.x
	${RPCGEN_REPORT}

fgl_xdr.c: fgl.x
	${RPCGEN_FGL}

form_x.xs.h form_x.xo.c form_x.xi.c form_x.xio.c form_x.x.h: form_x.x
	${XGENEXE} $< struct_form
	cp form_x.xs.h $(ROOT)/incl/dataio/form_x.xs.h

npcode.xo.c npcode.xi.c npcode.xio.c: npcode.x
	${XGENEXE} $< module
	cp npcode.xs.h $(ROOT)/incl/dataio/npcode.xs.h

fgl.xo.c fgl.xi.c fgl.xio.c: fgl.x
	${XGENEXE} $< module_definition globals_definition
	cp fgl.xs.h $(ROOT)/incl/dataio/fgl.xs.h


report.xo.c report.xi.c report.xio.c: report.x
	${XGENEXE} $< report
	cp report.xs.h $(ROOT)/incl/dataio/report.xs.h

# As these are generated by a OS dependant program
# and is nothing to do with us - there seems little
# point -Wall'ing it and worrying users with warnings...
# or, we can add -Wno-unused
form_x_xdr.o: form_x_xdr.c
	${CC} ${CFLAGS} ${WARN_NONOUSED} -c form_x_xdr.c -o form_x_xdr.o

menu_x_xdr.o: menu_x_xdr.c
	${CC} ${CFLAGS} ${WARN_NONOUSED} -c menu_x_xdr.c -o menu_x_xdr.o
fgl_xdr.o: fgl_xdr.c
	${CC} ${CFLAGS} ${WARN_NONOUSED} -c fgl_xdr.c -o fgl_xdr.o

report_xdr.o: report_xdr.c
	${CC} ${CFLAGS} ${WARN_NONOUSED} -c report_xdr.c -o report_xdr.o

npcode_xdr.o: npcode_xdr.c
	${CC} ${CFLAGS} ${WARN_NONOUSED} -c npcode_xdr.c -o npcode_xdr.o

${XGENEXE}:
	${MAKE} -C ${ROOT}/compilers/xgen


## ==================================================================
##                          Dependencies
## ==================================================================

report.xi.o: form_x.x.h
form_x.xi.c: ${XGENEXE}

${LIBROOT}/libaubit4gl.${SO_EXT}: form_x.x.h
	${MAKE} -C${LIBROOT}/libaubit4gl

## ==================================================================
##                          Clean
## ==================================================================

clean:
	${RM} *.c *${SO_EXT} *.h *.bak .*.bak *.o *.dll.a \
		${PLUGINDIR}/libDATA_struct_form${SO_EXT} \
		${PLUGINDIR}/libDATA_report${SO_EXT} \
		${PLUGINDIR}/libDATA_module${SO_EXT} \
		${PLUGINDIR}/libDATA_module_definition${SO_EXT} \
		${PLUGINDIR}/libXDRPACKER_struct_form${SO_EXT} \
		${PLUGINDIR}/libXDRPACKER_report${SO_EXT} \
		${PLUGINDIR}/libXDRPACKER_module${SO_EXT} \
		${PLUGINDIR}/libXDRPACKER_module_definition${SO_EXT} \
		${PLUGINDIR}/libDATA_any${SO_EXT}


## ==================================================================
##                         Other Targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"

pluginsdir:
	if test ! -d ${PLUGINDIR}; then mkdir ${PLUGINDIR} 2> /dev/null; fi
#=============================== EOF ================================

