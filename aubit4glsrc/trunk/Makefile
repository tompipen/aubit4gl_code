# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   root makefile              |
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
# | This program is distuributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: Makefile,v 1.40 2007-01-18 21:12:16 mikeaubury Exp $
#

#Save initial state of system varables, so we can undo changes 
#made by makefiles when we have to
INIT_PATH				:=${PATH}
INIT_LD_LIBRARY_PATH	:=${LD_LIBRARY_PATH}


## ==================================================================
##                    Includes
## ==================================================================

#All stuff common to more then one Aubit compiler make file is there:
include incl/Makefile-common

## ==================================================================
##                    Define default target
## ==================================================================

###############################
#All targets in this make file are "phony" targets - they do not create
#anything, they just invoke other make files:
.PHONY: all clean default log corecompile extra ide api.headers glade help deinstall

###############################
#Things we compile by default
ALL					=settings api.headers corecompile libfile libstring

ifneq "${enable_minimal}" "yes" 
	ALL 			+=	liblogical glade aace
endif

###############################
#Things we compile with 'extra' target
ALL_EXTRA  			=ide odbctest libhtml adbaccess adbload

#FIXME: All stuff that should be in ALL_EXTRA, but does not compile:
ALL_EXTRA_BROKEN=

ALL_EXTRA_BROKEN	=
ifneq "${PERLBUILD}" "no"
	ALL_EXTRA_BROKEN+=perl
endif
ifneq "${JABBERBUILD}" "no"
	ALL_EXTRA  		+=jabber
endif
#ifneq "${DOXYGEN}" "no"
	#Dont put DoxyGen in extra target - it takes a long time, and aubitbuild
	#calls 'make extra' and so it would tun it twice - as part of 'make extra'
	#ALL_EXTRA  		+=doxy
#endif

################################
#Define targets for liblogical
#Libraries are made with lib makefile
LIBLOGICAL_BUILD=bin/process_report ${PLUGINDIR}/libLOGREPPROC_TXT${SO_EXT} \
	${PLUGINDIR}/libLOGREPPROC_CSV${SO_EXT}
LIBLOGICAL_GTK2_DEPEND=${PLUGINDIR}/libLOGREP_CSV${SO_EXT} bin/layout_engine bin/report_viewer \
	${PLUGINDIR}/libLOGREP_TXT${SO_EXT}
LIBLOGICAL_PDF_DEPEND=${PLUGINDIR}/libLOGREPPROC_PDF${SO_EXT} ${PLUGINDIR}/libLOGREP_PDF${SO_EXT}

ifeq "${GTK_VERSION}" "2.0"
	LIBLOGICAL_BUILD+=${LIBLOGICAL_GTK2_DEPEND}
endif

ifneq "${PDFBUILD}" "no"
	LIBLOGICAL_BUILD+=${LIBLOGICAL_PDF_DEPEND}
endif


## ==================================================================
##                              Targets
## ==================================================================

#default: ${ALL} default.msg
default: ${ALL} test default.msg.tmp
	@echo " "

default.msg.tmp:
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "|      Successfully compiled Aubit compiler default targets          |"
	@echo "| You MUST install it before you can use it - execute 'make install' |"
	@echo "| Current default install settings :                                 |"
	@echo "| PREFIX           =${PREFIX} "
	@echo "| LIB_INSTALL_LINK =${LIB_INSTALL_LINK}"
	@echo "| BIN_INSTALL_LINK =${BIN_INSTALL_LINK}"
	@echo "| Override any variable above using 'make install <var>=<value>'     |"
	@echo "| Execute 'make extra' to compile additional components:             |"
	@echo "| ${ALL_EXTRA}"
	@echo "| Use Aubit regression tests available from CVS to test the build.   |"
	@echo "| Use 'make doxy' to create API documentation.                       |"
	@echo "+--------------------------------------------------------------------+"
	@echo " "
	@echo "Thank you for using Aubit 4gl compiler"

	
default.msg: TITLE="Default Aubit targets compiled successfuly"
default.msg: MSG=\
		"Successfully compiled Aubit compiler default targets \n\
		You MUST install it before you can use it - execute 'make install' \n\
		Current default install settings : \n\
		PREFIX=${PREFIX} (under ${AUBITNAME}) \n\
		LIB_INSTALL_LINK=${LIB_INSTALL_LINK} \n\
		BIN_INSTALL_LINK=${BIN_INSTALL_LINK} \n\
		Execute 'make extra' to compile additional components: \n\
		${ALL_EXTRA} \n\
		Use Aubit regression tests available from CVS to test the build. \n\
		Use 'make doxy' to create API documentation. \n\
		\n\
		Thank you for using Aubit 4gl compiler \n"
default.msg:
ifeq "${DIALOG_TYPE}" "no"
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "|      Successfully compiled Aubit compiler default targets          |"
	@echo "| You MUST install it before you can use it - execute 'make install' |"
	@echo "| Current default install settings :                                 |"
	@echo "| PREFIX           =${PREFIX} (under ${AUBITNAME}) "
	@echo "| LIB_INSTALL_LINK =${LIB_INSTALL_LINK}"
	@echo "| BIN_INSTALL_LINK =${BIN_INSTALL_LINK}"
	@echo "| You can override PREFIX with 'make install PREFIX=/some/path'      |"
	@echo "| Execute 'make extra' to compile additional components:             |"
	@echo "| ${ALL_EXTRA}"
	@echo "| Use Aubit regression tests available from CVS to test the build.   |"
	@echo "| Use 'make doxy' to create API documentation.                       |"
	@echo "+--------------------------------------------------------------------+"
	@echo " "
	@echo "Thank you for using Aubit 4gl compiler"
else
#--msgbox
ifeq "${DIALOG_TYPE}" "TUI"
#--backtitle
#--beep
#--stdout
	@${TUI_DIALOG} --stdout --cr-wrap --sleep 10 --title ${TITLE} --infobox ${MSG} 0 0
else
	@${XDIALOG} --title ${TITLE} --infobox ${MSG} 0 0 10000
endif

#		case $? in
#		  0)
#		    echo "OK";;
#		  255)
#		    echo "Box closed.";;
#		esac

endif

#Target do make default and extra targets, and install everything
all: default extra install

#Target to perform default compile, logging the output to file
log:
	@echo "Logging make process to make.log, please wait..."
	@time ${MAKE} > make.log 2>&1
	@echo "make finished successfuly, see make.log for details."
	@echo "Total compiler warnings: `grep -c 'warning:' make.log`"

#main target of default build
corecompile:
	@echo "Making XGEN"
	$(MAKE) -C compilers/xgen
	@echo "Making Dataio"
	$(MAKE) -C common/dataio
	@echo "Making lib"
	$(MAKE) -C lib
	@echo "Making compilers/4glc"
	$(MAKE) -C compilers/4glc
	@echo "Making compilers/sql"
	$(MAKE) -C compilers/sql
	@echo "Making compilers/helpcompile"
	$(MAKE) -C compilers/helpcompile
	$(MAKE) -C tools/4glpc
	$(MAKE) -C compilers/fcompile
	$(MAKE) -C compilers/menus
	$(MAKE) -C lib loadmap
	$(MAKE) -C tools/convertsql
	$(MAKE) -C tools/afinderr
	$(MAKE) -C tools/configuration
	$(MAKE) -C tools/asql
	$(MAKE) -C tools/adbschema
ifneq "${IFMX_ESQLC}" "no"
	#curently compiles only with ESQL/C
	$(MAKE) -C tools/aupscol
	$(MAKE) -C tools/adbload2
endif
	$(MAKE) -C help
	@echo Aubit 4gl compiler core is now compiled

aace:
	$(MAKE) -C compilers/ace
	
pcode:
ifeq "${PCODE_ENABLED}" "yes"
	$(MAKE) -C compilers/pcode
else
	@echo "PCODE compilation disabled   (PCODE_ENABLED='${PCODE_ENABLED}')"
endif
	
	
#Stuff form Mike's 'remake.mja' 
#TODO - shoud be part of this makefile
#cd lib/libui/ui_curses; sh make_static
#cd lib/libsql/esqlc; sh make_static; sh make_simple
#cd lib/libesql; sh make_static; sh make_simple

#Target to create API headers from .spec files
api.headers:
	$(MAKE) -C lib/libaubit4gl api.headers

## ==================================================================
##                              LibLogical targets
## ==================================================================

liblogical: ${LIBLOGICAL_BUILD}
ifneq "${GTK_VERSION}" "2.0"
	@echo " "
	@echo " ** WARNING:"	
	@echo " ** GTK+ version 2 not detected (have ${GTK_VERSION}) skipped targets:"
	@echo "${LIBLOGICAL_GTK2_DEPEND}"
	@echo " "	
endif	
ifneq "${PDFBUILD}" "yes"
	@echo " "
	@echo " ** WARNING:"	
	@echo " ** PDF library not detected, skipped targets:"
	@echo "${LIBLOGICAL_PDF_DEPEND}"
	@echo " "	
endif	
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| Successfuly built liblogical targets:                              |"
	@echo "| ${LIBLOGICAL_BUILD}"
	@echo "+--------------------------------------------------------------------+"
	@echo " "

bin/process_report:
	$(MAKE) -C lib/liblogical/processor
bin/layout_engine:
	$(MAKE) -C lib/liblogical/layout_engine
bin/report_viewer:
	$(MAKE) -C lib/liblogical/report_viewer

#Now in lib makefile:
${PLUGINDIR}/libLOGREPPROC_TXT${SO_EXT}:
	$(MAKE) -C lib/liblogical/txt/process
${PLUGINDIR}/libLOGREPPROC_CSV${SO_EXT}:
	$(MAKE) -C lib/liblogical/csv/process
${PLUGINDIR}/libLOGREPPROC_PDF${SO_EXT}:
	$(MAKE) -C lib/liblogical/pdf/process

${PLUGINDIR}/libLOGREP_TXT${SO_EXT}:
	$(MAKE) -C lib/liblogical/txt/layout
${PLUGINDIR}/libLOGREP_CSV${SO_EXT}:
	$(MAKE) -C lib/liblogical/csv/layout
${PLUGINDIR}/libLOGREP_PDF${SO_EXT}:
	$(MAKE) -C lib/liblogical/pdf/layout
	
clean.liblogical:
	$(MAKE) -C lib/liblogical/processor clean
	$(MAKE) -C lib/liblogical/layout_engine clean
	$(MAKE) -C lib/liblogical/report_viewer clean
	$(MAKE) -C lib/liblogical/txt/layout clean
	$(MAKE) -C lib/liblogical/txt/process clean
	$(MAKE) -C lib/liblogical/csv/layout clean
	$(MAKE) -C lib/liblogical/csv/process clean
	$(MAKE) -C lib/liblogical/pdf/layout clean
	$(MAKE) -C lib/liblogical/pdf/process clean

## ==================================================================
##                              Extra
## ==================================================================

extra: extra_msg ${ALL_EXTRA}
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| Successfully compiled aditional Aubit components :                 |"
	@echo "| ${ALL_EXTRA}."
	@echo "| FIXME: still broken targets:                                       |"
	@echo "| ${ALL_EXTRA_BROKEN}."
	@echo "+--------------------------------------------------------------------+"
	@echo " "

extra_msg:
	@echo "Will make: ${ALL_EXTRA}"

ide:
	$(MAKE) -C tools/ide
#	$(MAKE) -C tools/ide install.aubit

libfile:
	$(MAKE) -C lib/extra_libs/file

libstring:
	$(MAKE) -C lib/extra_libs/string

libhtml:
	$(MAKE) -C tools/html libA4GL_HTML${SO_EXT}

#This is now more or less obsolete - use asql instead
adbaccess:
#	$(MAKE) -C tools/adbaccess use.amake
#We have a problem with getopt_long() on CygWin, so use 4glpc for now:
	$(MAKE) -C tools/adbaccess misql.4ae

odbctest:
	$(MAKE) -C tools/odbctest

jabber:
#	$(MAKE) -C tools/jabber libIM_JABBER${SO_EXT}
	$(MAKE) -C lib ${PLUGINDIR}/libIM_JABBER${SO_EXT_LINKABLE}

adbload:
	$(MAKE) -C tools/adbload

#Glade IDE has no dependencies to compile, SQL Editor needs IFX ESQL 
#(check is in it's makefile). Both need libglade to run.
#TODO: include in install/deinstall, RPM and Windows installer
glade:
	$(MAKE) -C glade/ide
ifneq "${IFMX_ESQLC}" "no" 	
	$(MAKE) -C glade/ide/sqleditor
endif	
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| Successfuly built Glade support                                    |"
	@echo "+--------------------------------------------------------------------+"
	@echo " "

## ==================================================================
##                        Perl output mode
## ==================================================================

perl: api perl.compiler perl.lib test.perl
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| Perl - done. "
	@echo "+--------------------------------------------------------------------+"
	@echo " "

api:
	$(MAKE) -C lib/libaubit4gl api

#Build Lex plug-in for generating Perl output
perl.compiler:
	${MAKE} -C lib/liblex/lex_perl
	@echo Aubit 4gl Perl-code generating version LEX library created

#Make and install aubit4gl_pl.pm SWIG wrapper for libaubit4gl.so so generated
#Perl code can utilise Aubit library and its plug-ins
perl.lib:
#Perl created makefile will remove domake when running "clean", so we better make
#sure we have it:
	./config.status --file lib/swig/domake
	cd lib/swig; sh domake
	@echo Aubit 4gl Perl module/wrapper for libaubit4gl installed

test.perl:
	${MAKE} -C tools/test test.perl

clean.perl:
	${MAKE} -C lib/liblex/lex_perl clean
#WARNING - Perl created makefile will remove domake when running "clean"
	if test -f lib/swig/?akefile ; then mv lib/swig /tmp/swig-makefile; fi
#Must allow it to fail, as we may or may not have makefile allready created there
	-if test -f lib/swig ; then ${MAKE} -C lib/swig clean ; fi
	if test -f /tmp/swig-makefile ; then mv /tmp/swig-makefile lib/swig/Makefile; fi
	

########################################
#Release a file to SourceForge Released Files download site
release:
#       sf-upload -pr projectname -p packagename -r releasename -f file
#              [-type type] [-processor processor] [-user user] [-password password]
#              [-d releasedate]
#              [-n notes | -nf notesfile] [-c changes | -cf changesfile]
#              [-[no]ftp] [-[no]rc] [-[no]v] [-version]
#    ~/.sfuploadrc
#        You can put configuration options to this file. The format is
#            key = value
#        Allowed keys are: "user", "password", and "debug".
	sf-upload -pr aubit4gl -p "Aubit4gl-manual" -r "0.59-21" -f /tmp/HTML-Parser-3.55.tar.gz -user afalout
#	sf-upload -pr aubit4gl -p "Aubit Reasonably Stable Source" -r "1.0" -f file
#	sf-upload -pr aubit4gl -p "Aubit Reasonably Stable Binary" -r  1.0"  -f file

#...
#Net::FTP=GLOB(0x869a07c)>>> QUIT
#Net::FTP=GLOB(0x869a07c)<<< 221 Goodbye.
#Login to sourceforge
#make: *** [release] Segmentation fault

## ==================================================================
##            DoxyGen doccumentation creation
## ==================================================================

doxy: docs/doxy/html/index.html
docs/doxy/html/index.html:
#FIXME - Use Autoconf @DOXYGEN@ here
ifneq "${DOXYGEN}" "no"
	${MAKE} doxy.make
#FIXME: use Autoconf variable here:
ifneq "${WWW_DOCUMENT_ROOT}" ""
	${MAKE} doxy.install.www
endif
#FIXME: this is wrong - check if cgi-bin dir exists
ifneq "${CGI_DIR}" ""
	${MAKE} doxy.install.search
endif
	@echo DoxyGen source code documentation generated.
	@echo To use it, open file 'docs/doxy/html/index.html' in your web browser
else
	@echo "Sorry, DOXYGEN not detected"
endif

doxy.make:
	rm -rf docs/doxy/html
	${DOXYGEN} docs/doxy/Doxyfile
	@echo DoxyGen doccumentation created and placed in docs/doxy/html

doxy.install.www:
	rm -rf ${WWW_DOCUMENT_ROOT}/${DOXY_WWWPATH}/html
	${MKPATH} ${WWW_DOCUMENT_ROOT}/${DOXY_WWWPATH}
	cp -r docs/doxy/html ${WWW_DOCUMENT_ROOT}/${DOXY_WWWPATH}/html
	cd ${WWW_DOCUMENT_ROOT}/${DOXY_WWWPATH}/html; doxytag -s search.idx
	@echo DoxyGen doccumentation installed in web server path :
	@echo ${WWW_DOCUMENT_ROOT}/${DOXY_WWWPATH}/html
	@echo Point your web browser to ${WWW_HOST_NAME}/${DOXY_WWWPATH}/html/index.html

doxy.install.search:
	${MKPATH} ${CGI_DIR}
	${CP} docs/doxy/html/doxysearch.cgi ${CGI_DIR}
#run docs/doxy/html/installdox to replace any dummy links:
	@docs/doxy/html/installdox


## ==================================================================
##                              Strip
## ==================================================================

#cuts size by more then 50%, but it makes it difficult to debug the core dumps
#if the debugging info has been stripped out.

# It should be optional, at most.  The increased size does not impact the
# runtime performance or memory usage; it only affects the amount of disk
# space used to store the programs (and the amount of time taken to
# distribute a binary distribution over a network).

#It should be implemented in the make file that created the executable

strip:
	cd bin; strip 4glc fcompile
	cd lib; strip *${SO_EXT}


## ==================================================================
##                              Clean
## ==================================================================

#FIXME: "clean" should clean intermediate files resulting from compile, but will skip
#executables and objects that are needed for instalation. After "clean", it should
#still be possiblt to do "make install"
clean:
	@echo FIXME: only cleanall works

#will clean EVERYTHING that is not source file from CVS
distclean: clean.all clean.tools clean.aubitbuild clean.distclean clean.config
	@echo Aubit 4gl compiler source tree now distribution clean

clean.distclean:
	-$(MAKE) -C tools/fgldoc distclean

#will clean EVERYTHING that is not source file from CVS appart from Autoconf generated stuff
clean.all: cleanall
cleanall: clean.root clean.bin clean.etc clean.incl clean.docs clean.install \
		clean.swig clean.project clean.liblogical clean.perl
	@echo Cleaning Aubit 4gl temporary compiler files and compiled objects...
	$(MAKE) -C lib clean
	$(MAKE) -C lib/libui/ui_console clean
	$(MAKE) -C lib/libui/ui_curses clean
#	$(MAKE) -C lib/libui/ui_gtk clean
	$(MAKE) -C lib/extra_libs/file clean
	$(MAKE) -C lib/extra_libs/string clean
	$(MAKE) -C lib/libexdata clean
	$(MAKE) -C lib/libpacker/packed clean
	$(MAKE) -C lib/libpacker/perl clean
	$(MAKE) -C lib/libpacker/xdr clean
	$(MAKE) -C lib/libpacker/xml clean
	$(MAKE) -C compilers/4glc/rules clean
	$(MAKE) -C compilers/4glc clean
	$(MAKE) -C compilers/sql clean
	$(MAKE) -C compilers/pcode clean
	$(MAKE) -C compilers/fcompile clean
	$(MAKE) -C compilers/menus clean
	$(MAKE) -C compilers/ace clean
	$(MAKE) -C compilers/helpcompile clean
	$(MAKE) -C compilers/xgen clean
	$(MAKE) -C common/dataio clean
	${RM} lib/swig/lib_wrap.doc
	$(MAKE) -C tools/test clean
	$(MAKE) -C tools/test/gui clean
	$(MAKE) -C tools/convertsql clean
	$(MAKE) -C tools/4glpc clean
	$(MAKE) -C tools/adbschema clean
	$(MAKE) -C tools/afinderr clean
	$(MAKE) -C tools/configuration clean
	$(MAKE) -C tools/asql clean
	$(MAKE) -C tools/adbaccess clean
	$(MAKE) -C tools/aupscol clean
	$(MAKE) -C tools/adbload2 clean
	$(MAKE) -C help clean
	$(MAKE) -C glade/ide clean
	@echo " "	
	@echo "+--------------------------------------------------------------------+"
	@echo "| Aubit 4gl compiler source tree is now clean                        |"
	@echo "| NOTE: tools tree not cleaned (use 'make clean.tools')              |"
	@echo "+--------------------------------------------------------------------+"
	@echo " "	


#user is expected to manually invoke this, so we save some time since usually
#we just want to clean compiler:
clean.tools:
	$(MAKE) -C tools/test/db clean
	$(MAKE) -C tools/test/db/informix clean
	$(MAKE) -C tools/test/db/postgresql clean
	$(MAKE) -C tools/test/lang clean
	$(MAKE) -C tools/test/regression clean
	$(MAKE) -C tools/ide clean
	$(MAKE) -C tools/html clean
	$(MAKE) -C tools/jabber clean
	$(MAKE) -C tools/adbaccess clean
	$(MAKE) -C tools/adbload clean
	$(MAKE) -C tools/odbctest clean
	$(MAKE) -C tools/4gl_beautify/dbbeauty clean
	$(MAKE) -C tools/4gl_beautify/iid clean
	$(MAKE) -C tools/4gl_beautify/infmx_tidy clean
	$(MAKE) -C tools/4glunit clean
	-$(MAKE) -C tools/fgldoc clean
	(cd tools/4gltree; ${RM} *.bak)
	(cd tools/metrics_4gl; ${RM} *.bak)
	@echo " "	
	@echo "+--------------------------------------------------------------------+"
	@echo "| Aubit 4gl compiler TOOLS source tree is now clean                  |"
	@echo "+--------------------------------------------------------------------+"
	@echo " "	

#This will clean everything created with Autoconf configure script:
clean.config: clean.configure
clean.configure: clean.makefiles clean.settings clean.splint
#"configure" _IS_ in CVS
	${RM} config.log config.status incl/config.h incl/a4gl_incl_config.h \
	docs/doxy/Doxyfile etc/aubit-rpm.spec configure.lineno libtool \
    bin/aubitbuild.sh etc/aubit-InnoSetup.iss incl/stamp-h compilers/4glc/mk_states_c

clean.settings:
	${RM} etc/a4glrc etc/aubitbuild.mk etc/aubitenv etc/aubitrc

clean.makefiles:
	${RM} compilers/4glc/rules/Makefile \
	compilers/fcompile/Makefile compilers/helpcompile/Makefile \
	incl/Makefile-common \
    lib/libui/ui_console/Makefile lib/libpdf/Makefile \
    lib/libsql/nosql/Makefile \
    lib/extra_libs/file/Makefile \
    lib/extra_libs/string/Makefile lib/libui/ui_curses/Makefile \
    tools/test/db/Makefile tools/test/lang/Makefile \
	tools/test/regression/Makefile tools/test/db/Makefile \
    tools/adbaccess/Makefile tools/adbload/Makefile \
    tools/ide/Makefile \
    tools/odbctest/Makefile \
    tools/test/Makefile tools/test/gui/Makefile \
	common/dataio/Makefile compilers/ace/Makefile \
	lib/libform/form_xdr/Makefile lib/libform/noform/Makefile \
	lib/libmenu/menu_nomenu/Makefile lib/libmenu/menu_xdr/Makefile \
	lib/libmsg/msg_native/Makefile lib/libpacker/packed/Makefile \
	lib/libpacker/perl/Makefile lib/libpacker/xdr/Makefile \
	lib/libpacker/xml/Makefile lib/librpc/no_rpc/Makefile \
	lib/librpc/sun_rpc/Makefile lib/librpc/xml_rpc/Makefile \
	lib/resource/Makefile tools/loadmap/Makefile \
	lib/liblex/lex_c/Makefile lib/liblex/lex_perl/Makefile \
	lib/liblex/lex_esqlc/Makefile \
	lib/libexdata/Makefile lib/libsql/postgresql/Makefile \
    lib/libform/form_generic/Makefile lib/libmenu/menu_generic/Makefile \
	lib/libsql/sapdb/Makefile tools/4glunit/Makefile \
	tools/test/db/informix/Makefile tools/test/db/postgresql/Makefile \
    tools/fgldoc/Makefile 

clean.splint:
	${RM} lclint.log compilers/fcompile/lclint.log compilers/helpcompile/lclint.log \
	compilers/menus/lclint.log lib/libaubit4gl/lclint.log


clean.root:
#We must not clean *.log when running make process to make.log:
#we must not clean *.tmp because of unixbuildnames.tmp:
	$(RM) *.bak *.BAK libincl .*.bak core cyrpc.flg debug.out \
	*.err ${PLATFORMINFO} make.log commit.log rpmbuild.log \
	aubit4gl.lsm rpmbuild.log .\#* aubit4glsrc-*-*.txt
	rm -rf autom4te.cache

#stuff created by aubitbuild.sh:
clean.build: clean.aubitbuild
clean.aubitbuild:
	${RM} tmpdlpage1.html aubitdownload.htm tmpdlpage2.html aubitdownload-template.htm \
    cybuildnames.tmp unixbuildnames.tmp unixsrcbuildnames.tmp cysrcbuildnames.tmp \
    warning.log
#FIXME: move this to appropriate makefile :
	${RM} compilers/fcompile/fshow.glb compilers/fcompile/fshow.h \
	tools/ide/debug.out tools/adbaccess/debug.out *.${ARCHEXT} *.htm *.html *.tmp

clean.rpc:
	${RM} compilers/fcompile/form_x_xdr.c compilers/menus/menu_x_xdr.c \
	compilers/fcompile/form_x.h compilers/menus/menu_x.h

clean.bin:
#dont clean aubitbuild.sh - this is Autoconf generated file
	(cd bin;${RM} 4glc${EXE} fcompile${EXE} mcompile${EXE} mkmess${EXE} \
	mcompile-noodbc${EXE} loadmap${EXE} \
	*.bak .*.bak ide${EXE} fcompile-noodbc${EXE} 4glc-noodbc${EXE} \
	4glp${EXE} mdecompile${EXE} fdecompile${EXE} fdecompile-j${EXE} \
	aubit-config${EXE} fshow${EXE}  odbctest-*${EXE} \
	aace${EXE} aace_4gl${EXE} aace_perl${EXE} adecompile${EXE} xgen${EXE} dbbeauty${EXE} *.err \
    iid${EXE} infmx_tidy${EXE} *.4ae *-strip${EXE} \
	convertsql${EXE} *.warn unmkmessage${EXE} amkmessage${EXE} default_frm${EXE} afinderr${EXE} \
	*.afr.dat *.afr.xml configurator${EXE} *.hlp \
	checker${EXE} runner_fgl${EXE} asql${EXE} aupscol${EXE} checker_fgl${EXE} c2pcode${EXE} \
	c2pcode_fgl${EXE} runner${EXE} *~ 4glpc${EXE} \
	)

clean.etc:
	${RM} etc/*.bak etc/*~ etc/config/*.bak etc/config/*~ etc/aubit-auto.spec \
	etc/*.hlp etc/*.afr.*
	rm -rf etc/Output

#Cant do a4gl_API_* because a4gl_API_exdata.h is NOT generated
#Note anymore - renamed to incl/a4gl_exdata.h apparently
clean.incl:
	${RM} incl/*.bak incl/\#* incl/*~
	${RM} incl/a4gl_API_esql.h  \
	incl/a4gl_API_esql_lib.h incl/a4gl_API_packer.h \
	incl/a4gl_API_packer_lib.h  \
	incl/a4gl_API_exreport.h incl/a4gl_API_rpc.h \
	incl/a4gl_API_exreport_lib.h  incl/a4gl_API_rpc_lib.h \
	incl/a4gl_API_form.h incl/a4gl_API_sql.h \
	incl/a4gl_API_form_lib.h incl/a4gl_API_sql_lib.h \
	incl/a4gl_API_help.h incl/a4gl_API_sqlparse.h \
	incl/a4gl_API_help_lib.h incl/a4gl_API_sqlparse_lib.h \
	incl/a4gl_API_menu.h incl/a4gl_API_ui.h \
	incl/a4gl_API_menu_lib.h incl/a4gl_API_ui_lib.h

clean.docs:
	rm -rf docs/doxy/html
	${RM} docs/doxy/*.bak docs/*.bak

clean.install:
	rm -rf install

clean.swig:
	@if [ -f lib/swig/?akefile ]; then \
		$(MAKE) -C lib/swig clean; \
    fi
	(cd lib/swig; ${RM} lib_wrap.c *.old *.bak aubit4gl_pl.pm domake)

clean.project:
	(cd tools/project; ${RM} *.bak .\#*)
	(cd tools/cygwin; ${RM} *.bak)



## ==================================================================
##                              Install
## ==================================================================
#FIXME: this should use ${INSTALL}
#make icons for KDE and GNOME: to IDE, to manual

#all targets common to installing compiled source code AND installing
#binary distributions are in here:
#THIS INCLUDE MUST BE HERE SINCE IT STARTS WITH A TARGET!!!!
include incl/Makefile-install.mki

#remaining install related targets defined here are used only when installing
#from compiled source code tree.

install: ./bin/4glc install.all
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| Aubit compiler installed to $(INSTALL_DIR)"
	@echo "| You can test the installation by executing:                        |"
	@echo "| cd $(INSTALL_DIR)/tools/test; make  "
	@echo "| You can check that all got installed with 'make install.check'     |"
	@echo "+--------------------------------------------------------------------+"
	@echo " "
	@echo "Thank you for using Aubit 4gl compiler"
	@echo " "

install.all: install.core install.Makefile-common install.setmod install.example \
		install.manual install.config \
		install.bin.links install.aubitrc install.libs.links \
		install.makefile-install install.libs.conf install.registry.bin
ifneq "${AUBITRCFILEEXISTS}" ""
	@echo " "
	@echo "WARNING: Configuration file aubitrc exists in ${AUBITETC}/aubitrc"
	@echo "====================== WILL NOT OVERWRITE ======================"
	@echo "use 'make install.aubitrc aubitrc=new' if you want to do that "
	@echo "Automatically created aubitrc placed in /tmp/aubitrc.tmp"
	@echo " "
endif
	
#WARNING: for some reason (sic!) assigning variables here MUST happen 
#on the beggining of the line:
ifeq "${INSTALLDIR}" ""
INSTALLDIR=${INSTALL_DIR}
endif
ifeq "${SOURCEDIR}" ""
SOURCEDIR=${AUBIT_SRC_ROOT}
endif

########################
#Check that 'make install' installed everything we expect, and not things
#we dont expect/want:
install.check:
	export MAKINGAUBIT=0; export SOURCEDIR="${SOURCEDIR}";export INSTALLDIR="${INSTALLDIR}"; \
		${SH} bin/4glpc.obsolete -chk-install

########################
#Check that Windows setup  installed everything we expect, and not things (FULL LOOP)
install.check.winsetup: winsetup winsetup.check

#########################
#Main target for checking windows installer files consistency
#also invoked from aubitbuild.sh
winsetup.check: winsetup.deinstall install.winsetup.silent install.check.winsetup.compare
		#EXEC="make winsetup.deinstall"; runexec

	@echo "WinSetup checks OK"
	
########################
#deinstall Windows setup
winsetup.deinstall:
#/SILENT shows only progress indicator, /VERYSILENT not even that
	-d:/tmp/aubit4gl-silent/unins000.exe /VERYSILENT
#Should be gone, but just in case:	
	rm -rf d:/tmp/aubit4gl-silent

########################
#check files installed by Windows setup executable
install.check.winsetup.compare:
	export MAKINGAUBIT=0; export INSTALLDIR="d:/tmp/aubit4gl-silent" ;${SH} bin/4glpc.obsolete -chk-install

########################
#Check that RPM installed everything we expect, and not things
#install.check.rpm:
#	export MAKINGAUBIT=0; export INSTALLDIR="xxyyzz" ;${SH} bin/4glpc.obsolete -chk-install
#remove above?	
	
########################
#install compiler core files
install.core: install.tree
	$(CP) ${TOSETTINGS} $(FGLPC_SETTINGS_DEST)
	${CP} $(TOBIN) $(BIN_DEST)
	$(CP) $(TOROOT) $(ROOT_DEST)
	$(CP) $(TOINCL) $(INCL_DEST)
	$(CP) $(TOLIB) $(LIB_DEST)
	$(CP) $(TOPLUGIN) $(PLUGIN_DEST)
	@echo Aubit 4gl core compiler files installed

#Prepare and install Makefile-common make include
install.Makefile-common: install.Makefile-common.in
#This is just a fake to have a file as include
#	@echo "#AUBIT_BIN_INSTALL is needed for make files and 4glpc to know they are not in Aubit compiler source code tree:" > /tmp/Makefile-common
#	@echo "AUBIT_BIN_INSTALL=1" >> /tmp/Makefile-common
#	@cat $(INCL_DIR)/Makefile-common >> /tmp/Makefile-common
#	@mv /tmp/Makefile-common $(INCL_DEST)
#	${RM} /tmp/Makefile-common
	echo " " > $(INCL_DEST)/Makefile-common

install.Makefile-common.in:
	@echo "#AUBIT_BIN_INSTALL is needed for make files and 4glpc to know they are not in Aubit compiler source code tree:" > /tmp/Makefile-common.in
	@echo "AUBIT_BIN_INSTALL=1" >> /tmp/Makefile-common.in
	@cat $(INCL_DIR)/Makefile-common.in >> /tmp/Makefile-common.in
#Make this variables permanent, so we can use then when installing binary
#packages - they wont be changing anyway:
	cat /tmp/Makefile-common.in | sed -e 's/@AUBIT_VERSION@/${AUBIT_VERSION}/g' \
		-e 's/@AUBIT_BUILD@/${AUBIT_BUILD}/g' \
		-e 's/@COMPILE_DATE@/${COMPILE_DATE}/g' \
		-e 's/@target@/${target}/g' \
		-e 's/@target_os@/${target_os}/g' > $(INCL_DEST)/Makefile-common.in
	#@mv /tmp/Makefile-common.in $(INCL_DEST)
	${RM} /tmp/Makefile-common.in
#script to enable configure emphasis display:
	${CP} tools/project/shtool $(INSTALL_DIR)/bin/shtool 
	
	
#set file level permisions and attributes
install.setmod:
	chmod a+x $(BIN_DEST)/*

#install configuration settings
install.config: install.home
	$(CP) ${TOETC} $(ETC_DEST)
	$(CP) ${TOCONVSQL} $(CONVSQL_DEST)
	$(CP) ${TOIMPORT} $(IMPORT_DEST)
	@echo "Configuration examples installed to $(INSTALL_DIR)/etc"

#Install files in user's home directory
install.home:
ifneq "${TOHOME}" ""
	$(CP) ${TOHOME} $(HOME_DEST)
endif

#Example files
install.example:
#	$(CP) $(TOTEST) $(TEST_DEST)
	$(CP) $(TOTEST_STD) $(TEST_DEST_STD)
	$(CP) $(TOTEST_GUI) $(TEST_DEST_GUI)
	@echo Aubit 4gl compiler programming examples are now installed

#Documentation files
install.manual:
	$(CP) $(TODOCS) $(DOC_DEST)
#	$(CP) $(TODOCS2) $(DOC_DEST)/manual/html
	@echo Aubit 4gl compiler manual is now installed

#install IDE binary files
#This is not done by default. Check if user compiled IDE first
install.ide:
	${MAKE} -C tools/ide install.aubit
	@echo Aubit 4gl compiler IDE is now installed

#Install IDE source files in Aubit installation tree
pack.ide:
	${CP} ${TOIDE} $(IDE_DEST)

#Create installation tree
install.tree:
	${MKPATH} $(BIN_DEST) $(LIB_DEST) $(ETC_DEST) $(FGLPC_SETTINGS_DEST) \
	${PLUGIN_DEST} \
	$(INCL_DEST) $(TEST_DEST)/gui $(DOC_DEST) ${CONVSQL_DEST} ${IMPORT_DEST}
	@echo "Aubit 4gl compiler instalation tree created"
#FIXME: we need to chown installation tree to something, since installation has 
#to be run as root - or use "install" utility?
#FIXME: we must chech is user is "root" before installing

install.makefile-install:
	${CP} etc/Makefile-install $(ROOT_DEST)/Makefile
	${CP} incl/Makefile-install.mki $(INCL_DEST)
	${CP} -r etc/config/ $(ETC_DEST)
	${CP} etc/aubitrc.in $(ETC_DEST)/aubitrc-bin.in
	${CP} configure $(ROOT_DEST)

deinstall: deinstall.all


## ==================================================================
##                     P-code runner registration
## ==================================================================
#See #http://www.tat.physik.uni-tuebingen.de/~rguenth/linux/binfmt_misc.html
#On linux - if you have binfmt_misc in the kernel (or loaded as a module )
#you can get the kernel to run a program to run a program. This is normally
#used for running java or C# code, but we can use it for running aubit pcode
#bin_fmt registration.

#-----------------------
#Register p-code runner with kernel (Linux with binfmt_misc support in kernel ONLY)
pcode.register: binfmt.boot binfmt.activate binfmt.status
	@echo "Binfmt activation complete"

#-----------------------
#Full circle - needed when setings change (you cant just register new value,
#updates are not possible - you have to delete everything first)
pcode.re-register: binfmt.disable binfmt.clear binfmt.sh.delete binfmt.boot \
	binfmt.activate binfmt.status binfmt.enable
	@echo "Binfmt activation complete"

#-----------------------
#Try to activate binfmt support by runing a script
binfmt.activate: /proc/sys/fs/binfmt_misc/register $(INSTALL_DIR)/bin/runner_fgl_wrapper /usr/bin/register_binfmt.sh
#TODO: remove compilers/pcode/register
ifndef COMSPEC
#Load binfmt_misc module in runningn kernel:
	su -c "${SH} /usr/bin/register_binfmt.sh"
endif

#-----------------------
#De-registers all previously registeres formats:
binfmt.clear: /proc/sys/fs/binfmt_misc/status
	su -c "echo -1 > $<"
	${MAKE} binfmt.status

#-----------------------
#Disable binfmt support
binfmt.disable: /proc/sys/fs/binfmt_misc/status
	su -c "echo 0 > $<"
	${MAKE} binfmt.status

#-----------------------
#Enable binfmt support
binfmt.enable: /proc/sys/fs/binfmt_misc/status
	su -c "echo 1 > $<"
	${MAKE} binfmt.status

#-----------------------
#Show binfmt support status
binfmt.status: /proc/sys/fs/binfmt_misc/status
	@echo "----------------------------------------------"
	@echo "binfmt_misc status is:"
	-@cat /proc/sys/fs/binfmt_misc/status
	@echo " "
	@echo "----------------------------------------------"
	@echo "A4GL interpreter configuration:"	
	-@cat /proc/sys/fs/binfmt_misc/A4GL
	@echo "----------------------------------------------"	

#-----------------------
#Check for presense of Aubit P-code wrapper script in installation location:
$(INSTALL_DIR)/bin/runner_fgl_wrapper:
	@echo "YOU NEED TO INSTALL AUBIT COMPILER FIRST! (make install)"
	@exit 1

#-----------------------
#Remove existing script
binfmt.sh.delete: /usr/bin/register_binfmt.sh
	su -c "${RM} $^"
	
#-----------------------
#Create binfmt registration script:
binfmt.sh: /usr/bin/register_binfmt.sh
/usr/bin/register_binfmt.sh:
	su -c "touch $@; chmod a+rwx $@;"
	@echo "#!/bin/sh/" > $@
	@echo "# this is to add the supported binary formats via binfmt_misc" >> $@
	@echo "" >> $@
	@echo "if test ! -e /proc/sys/fs/binfmt_misc ; then" >> $@
	@echo "	modprobe binfmt_misc" >> $@
	@echo "fi" >> $@
	@echo "" >> $@
	@echo "if test -e /proc/sys/fs/binfmt_misc ; then" >> $@
#	@echo "	echo ':Wine:M::MZ::/usr/local/bin/wine:' \> /proc/sys/fs/binfmt_misc/register" >> $@
#	@echo "	echo ':Java:M::\xca\xfe\xba\xbe::/usr/local/java/bin/javawrapper:' \> /proc/sys/fs/binfmt_misc/register" >> $@
#	@echo "	echo ':HTML:E::html::/usr/local/java/bin/appletviewer:' \> /proc/sys/fs/binfmt_misc/register" >> $@
#	@echo "	echo ':Applet:M::<!--applet::/usr/local/java/bin/appletviewer:' \> /proc/sys/fs/binfmt_misc/register" >> $@
	@echo "	echo ':A4GL:M::\xa4\xfc\x23\x45::$(INSTALL_DIR)/bin/runner_fgl_wrapper:' > /proc/sys/fs/binfmt_misc/register" >> $@	
	@echo "else" >> $@
	@echo "	echo 'No binfmt_misc support'" >> $@
	@echo "fi" >> $@
	@echo "exit 0" >> $@
	@echo "" >> $@
#	chmod a+x $@
#	chown root $@
	@echo "CREATED $@"
	
#-----------------------
#Enable invoking binfmt registration script on system boot:
binfmt.boot: /usr/bin/register_binfmt.sh
#On SuSE it's /etc/init.d/boot.local
	@BOOT_LOCAL=""; \
	if test -f /etc/rc/boot.local; then \
		BOOT_LOCAL="/etc/rc/boot.local"; \
	elif test -f /etc/init.d/boot.local; then \
		BOOT_LOCAL="/etc/init.d/boot.local"; \
	else \
		echo "/etc/rc/boot.local or /etc/init.d/boot.local does not exist"; \
	fi; \
	if test "$$BOOT_LOCAL" != ""; then \
		if test "`grep 'register_binfmt.sh' $$BOOT_LOCAL`" = ""; then \
			su -c "echo '$^' >> $$BOOT_LOCAL"; \
			echo "ADDED $^ invocation to $$BOOT_LOCAL"; \
		else \
			echo "$^ invocation in $$BOOT_LOCAL allready present"; \
		fi; \
	fi
	


## ==================================================================
##                           Packaging
## ==================================================================

tarinstall: platform
#FIXME: check if it exists first
#	(cd $(PREFIX); tar -cvzf $(SOURCE)/$(TARNAME) * $(A4GLRC))
	(cd $(INSTALL_DIR); tar -cvzf $(SOURCE)/$(TARNAME) * )

createcleantar: installdrop installall tarinstall
	@echo "Aubit 4gl compiler binary disribution is now in $(SOURCE)/$(TARNAME)"

#we should not use this
#installdrop:
#	${RMDIR} $(INSTALL_DIR)

tar: clean.all clean.tools
#COMPILE_DATE=20-01-2002
#TARGET=i586-pc-linux-gnu
	${RM} ${SOURCETARBASENAME}
ifndef COMSPEC
	tar -cvzf ${SOURCETARBASENAME} *
	@echo "Aubit tarball created:"
	@echo "(`ls ${SOURCETARBASENAME}`)"
else
#when on CygWin, maybe we should still use tar or bzip2, to preserve permissions, links...?
#zip [-options] [-b path] [-t mmddyyyy] [-n suffixes] [zipfile list] [-xi list]
#  -x   exclude the following names
	zip -r ${SOURCETARBASENAME} * -x bin/aubitbuild.sh aubitbuild.sh
#When running from aubitbuild.sh:
#  adding: bin/aubitbuild.sh
#  zip diagnostic: GetFileAttributes failed
#zip warning: Permission denied
#zip warning: could not open for reading: bin/aubitbuild.sh
	@echo "Aubit zipball created"
endif


tar.bin: $(INSTALL_DIR)/bin/4glc
	${RM} ${BINTARBASENAME}
#	tar -cvzf ${BINTARBASENAME} *
	if ! test -f $(INSTALL_DIR)/etc/aubitrc-bin; then cd $(INSTALL_DIR); ./configure; fi
	#${MAKE} -C $(INSTALL_DIR) tar.bin
	${MAKE} -C $(INSTALL_DIR) clean.all
	cd $(INSTALL_DIR); tar -cvzf ${BINTARBASENAME} *
	@echo "Aubit binary tarball created:"
	@echo "(`ls $(INSTALL_DIR)/${BINTARBASENAME}`)"

source.zip:
	${RMDIR} $(INSTALL_DIR)
	${MKPATH} $(INSTALL_DIR)
	(cd $(INSTALL_DIR); autocvspasswd; cvs -w checkout $(AUBITCVSNAME))
	(cd $(INSTALL_DIR)/$(AUBITCVSNAME); zip -r $(SOURCEZIPNAME) * )

#if we unhide them before zip, zip will not find them:
unhide.lnk:
	(cd $(INSTALL_DIR)/runtime; for afile in *.lnk.hide; do mv "$$afile" "`basename "$$afile" .hide`"; done;)

cygwin.zip.runtime:
	${RM} $(SOURCE)/$(ZIPRUNTIMENAME)
	(cd $(INSTALL_DIR)/runtime/; zip -r $(SOURCE)/$(ZIPRUNTIMENAME) * )

pack.amake:
	${MKPATH} /tmp/pack_amake/bin
	${MKPATH} /tmp/pack_amake/incl
	${CP} ${AMAKE_TOBIN} /tmp/pack_amake/bin
	${CP} ${AMAKE_TOINCL} /tmp/pack_amake/incl
	@echo "See HOWTO at http://sf.net/docman/?group_id=32409" > /tmp/pack_amake/README.txt
	(cd /tmp/pack_amake; tar -cvzf $(SOURCE)/amake-noarch.${ARCHEXT} * )
	@echo "Created: $(SOURCE)/amake-noarch.${ARCHEXT}"


cleantar:
	$(RM) *.${ARCHEXT}
	$(RM) *.${ARCHEXT}.txt


## ------------------------------------------------------------------
##                      RPM packaging
## ------------------------------------------------------------------

#You may need to create the following directories to make a build tree:
#	BUILD is the directory where all building occurs by RPM. You don't
#		have to do your test building anywhere in particular, but this is
#		where RPM will do it's building.
#	SOURCES is the directory where you should put your original source
#		tar files and your patches. This is where RPM will look by default.
#	SPECS is the directory where all spec files should go.
#	RPMS is where RPM will put all binary RPMs when built.
#	SRPMS is where all source RPMs will be put.


#installing cp from /usr/src/packages/BUILD/aubit4gl-1.00.6/aubit4glsrc-1.00-6
#to /home/aubit/aubit4gl

#Executing(%doc): /bin/sh -e /var/tmp/rpm-tmp.89960
#+ umask 022
#+ cd /usr/src/packages/BUILD
#+ cd aubit4gl-1.00.6
#+ DOCDIR=/home/aubit/aubit4gl/usr/share/doc/packages/aubit4gl
#+ export DOCDIR
#+ rm -rf /home/aubit/aubit4gl/usr/share/doc/packages/aubit4gl
#+ /bin/mkdir -p /home/aubit/aubit4gl/usr/share/doc/packages/aubit4gl
#+ cp -pr README.txt /home/aubit/aubit4gl/usr/share/doc/packages/aubit4gl
#cp: cannot stat `README.txt': No such file or directory
#error: Bad exit status from /var/tmp/rpm-tmp.89960 (%doc)

ifneq "${RPM}" "no"
#What the ???? Fist line inside ifneq must start on first char????
#Used to be all in rpm executable
RPMBUILD	=rpmbuild

	RPM_VENDOR:=${shell rpm --eval "%_vendor"}
	RPM_TARGET_OS:=${shell rpm --eval "%_target_os"}
	RPM_TARGET_PLATFORM:=${shell rpm --eval "%_target_platform"}
	#Something wrong here - even when it returns i586, it will build i686
	#I suppose its save to assume all machines will build (at least) i686 this days:
	RPM_TARGET_CPU_AUTO:=${shell rpm --eval "%_target_cpu"}
	RPM_TARGET_CPU=i686
	
	RPM_FILE_TO_MAKE=${RPMBUILDROOT}/RPMS/${RPM_TARGET_CPU}/${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}-1.${RPM_TARGET_CPU}.rpm

	SRCTMP		:=${RPMBUILDROOT}/SOURCES/${NAMEVERBLD}.${ARCHEXT}
	RPMCONFFILE	:=${AUBITDIR}/etc/aubit-rpm.spec
	TMP_RPM_INSTDIR	=/tmp/aubit4gl-rpminstall
	
	RPM_SRC_FILE:=${shell find ${RPMBUILDROOT}/SRPMS/ -name ${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}-1.src.rpm}
	RPM_FILE	:=${shell find ${RPMBUILDROOT}/RPMS/ -name ${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}-1.*.rpm}

	ifneq "${RPM_FILE}" ""
		PART1_ESC	=${shell echo ${RPMBUILDROOT}/RPMS | sed -e "s/\//\\\\\//g"}
		PART2_ESC	=${shell echo ${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}  | sed -e "s/\//\\\\\//g"}
		RPM_FILE_CPU:=${shell echo ${RPM_FILE} | sed -e "s/${PART1_ESC}//" -e "s/${PART2_ESC}//" -e 's/rpm//' -e 's/\.//g	' -e 's/\-1//' -e 's/\// /g' | awk '{print $$1}' }
	endif
	
endif



##############################
# make rpm form autoconf-ed etc/aubit-rpm.conf
rpm: rpm.refresh.specfile
ifneq "${shell id --name --user}" "root"
ifneq "${RPM}" ""
ifeq "${RPM}" "new"
	${MAKE} rpm.clean
endif
	${MAKE} rpm.build
else
	@echo "RPM tools where not detected on your system."
endif
else
	@echo "NEVER try to buid RPM packages as user 'root'!"
	exit 1
endif

##############################
# Do the actual build
rpm.build: rpm.check.all.pre ${RPM_FILE_TO_MAKE}
${RPM_FILE_TO_MAKE}: 
#RPM insists to have source code in ${RPMBUILDROOT}/SOURCES/ before it will
#build it, and only then make src and bin RPM
	@echo "+--------------------------------------------------------------------+"
	@echo "| Building RPM packages...                                           |"
	@echo "+--------------------------------------------------------------------+"
ifeq "${RPM}" "new"
	${MAKE} rpm.clean
endif
#Since aubitbuild.sh ups the build number before building nightly builds,
#make rpm will need to make a new ${SRCTMP} tarball, and to do this, it 
#will need to clean.all - leaving a machine without compiled Aubit :-(
#and RPM will deinstall installed Aubit as part of build process leaving 
#machine without installed Aubit :-((((
	@if test ! -f ${SRCTMP} ; then \
		echo "(1) No ${SRCTMP}, making it..."; \
		if test ! -f /tmp/${NAMEVERBLD}/${SOURCETARBASENAME} ; then \
			echo "(2) No /tmp/${NAMEVERBLD}/${SOURCETARBASENAME}, making it..."; \
			${MAKE} clean.all > /dev/null; \
			${RMDIR} /tmp/${NAMEVERBLD}; \
			${MKPATH} /tmp/${NAMEVERBLD}; \
			${LN_S} ${AUBITDIR} /tmp/${NAMEVERBLD}/${NAMEVERBLD}; \
			echo "Creating /tmp/${NAMEVERBLD}/$(SOURCETARBASENAME) from ${NAMEVERBLD}/ ..."; \
			(cd /tmp/${NAMEVERBLD}; tar -cvzf $(SOURCETARBASENAME) ${NAMEVERBLD}/* > /dev/null); \
		else \
            echo "Have /tmp/${NAMEVERBLD}/${SOURCETARBASENAME}"; \
		fi; \
		${CP} /tmp/${NAMEVERBLD}/${SOURCETARBASENAME} ${SRCTMP} ; \
	else \
        echo "Have ${SRCTMP}"; \
		echo "use RPM=new on make line to force refresh"; \
	fi
#	   -ba    Build binary and source packages (after doing the %prep, %build,
#              and %install stages).
	${RPMBUILD} -ba ${RPMCONFFILE} > rpmbuild.log 2>&1
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| 'make rpm' successfull, see rpmbuild.log for details               |"
	@echo "+--------------------------------------------------------------------+"
	${MAKE} rpm.show.created

	
# See 'rpm --querytags' for list of all tags you can query
#POSTIN OLDFILENAMES FILEUSERNAME FILEGROUPNAME ICON  PREFIXES INSTPREFIXES
#DIRINDEXES BASENAMES DIRNAMES OPTFLAGS DISTURL FILENAMES INSTALLPREFIX 
rpm.show:
#	no longer valid tag: rpm -qp --queryformat '%{DEFAULTPREFIX}\n' ${RPM_FILE}
#	rpm -qp --queryformat '%{RPM_A4GL_INSTALL_DIR}\n' ${RPM_FILE}
	rpm -qp --queryformat '%{PREFIXES}\n' ${RPM_FILE}
	rpm -qp --queryformat '%{INSTPREFIXES}\n' ${RPM_FILE}
#Prefix under which package WAS installed:
	rpm -qp --queryformat '%{INSTALLPREFIX}\n' ${RPM_FILE}
	rpm -q --queryformat '%{INSTALLPREFIX}\n' aubit4gl
#	rpm -qp --queryformat '%{FILENAMES}\n' ${RPM_FILE}
#	rpm -qp --queryformat '[%{NAME} %{FILENAMES}\n]' ${RPM_FILE}
	
#If you need to determine the actual string when it contains macros, you can 
#use rpm. For example, to determine the actual Source: value, you can run:
#
#rpm -q --specfile foo.spec --qf "$(grep -i ^Source foo.spec)\n"




################################################
#Create and deploy rpm to download web site
rpm.deploy: rpm rpm.scp
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: all done"
	@echo "+--------------------------------------------------------------------+"

################################################
#SCP the rpm to WWW root for download
rpm.scp:
	scp ${RPM_SRC_FILE} ${RPM_FILE} root@192.168.1.200:/srv/www/htdocs/files
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: done. URL:"
	@echo "| http://192.168.1.200/files/${RPM_SRC_FILE}"
	@echo "| http://192.168.1.200/files/${RPM_FILE}"	
	@echo "+--------------------------------------------------------------------+"

################################################
#SCP the rpm to user 'aubit' Desktop for testing
rpm.put:
	scp ${RPM_SRC_FILE} ${RPM_FILE} aubit@192.168.1.200:/home/aubit/Desktop
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: done. File placed on Desktop of user 'aubit'"
	@echo "+--------------------------------------------------------------------+"

	
##############################
#
rpm.show.created:
	@echo "+--------------------------------------------------------------------+"
	@echo "| Created files:                                                     |"
	@echo "| `ls ${RPM_SRC_FILE}`"
	@echo "| `ls ${RPM_FILE}`"
	@echo "| CPU: ${RPM_FILE_CPU}"
	@echo "+--------------------------------------------------------------------+"
	

###############################
# 
rpm.clean: rpm.clean.files rpm.refresh.specfile

###############################
# Remove all created and intermediate files to force complete refresh/rpm buid restart
rpm.clean.files:
	${RM} ${SRCTMP}
	${RM} /tmp/${NAMEVERBLD}/${SOURCETARBASENAME} ${RPM_SRC_FILE} ${RPM_FILE}
	rm -rf ${RPMBUILDROOT}/BUILD/aubit4glsrc*
#	rm -rf ${RPMBUILDROOT}/SOURCES/${SOURCETARBASENAME}
	rm -f ${RPMBUILDROOT}/SOURCES/aubit4gl*
	rm -f /usr/src/packages/SRPMS/aubit4gl-*
	rm -f /usr/src/packages/RPMS/i686/aubit4gl-*
	@echo "+--------------------------------------------------------------------+"
	@echo "| NOTE: if version numbers changed, run ./configure first!           |"
	@echo "+--------------------------------------------------------------------+"
	
##############################
# Verify that each file listed in spec file exist 
rpm.check.all.pre: rpm.refresh.specfile rpm.check.instdir
#rpm.check.deps -- if we list it here, we have to have source code compiled - so do this manually?
#${PREFIX}/bin/4glc 
#rpm.check.specfile.pre
	@echo "+--------------------------------------------------------------------+"
	@echo "| Traget $@ finished"
	@echo "+--------------------------------------------------------------------+"

#As RPM default prefic has to be used in parhs specified in %files section,
#and as rpm will package files that are installed in that location, it has to exist
#and be writable by us NOW 
rpm.check.instdir: ${RPM_A4GL_DEFAULT_PREFIX}
	@if ! test -w "${RPM_A4GL_DEFAULT_PREFIX}"; then \
		echo "ERROR: ${RPM_A4GL_DEFAULT_PREFIX} is not writable by current user" ; \
		exit 1; \
	fi
	
${RPM_A4GL_DEFAULT_PREFIX}:
	su -c "mkdir -p $@; chmod a+rw $@"
	
##############################
# Seems like this is really not a task to do before RPM is built and install -
# it seems that it was intended to compare result of RPM build with specfile, 
# and not to test validity of spec file itself, as it checks for various files 
# and places that only instlling created RPM would create?
rpm.check.specfile.pre:
#      -bl    Do  a  "list check".  The "%files" section from the
#              spec file is macro expanded, and checks are made to
#              verify that each file exists.
#      --nobuild
#              Do not execute any build stages. Useful for testing
#              out spec files.
#	./config.status --file etc/aubit-rpm.spec
	@echo "+--------------------------------------------------------------------+"
	@echo "| Testing RPM config file (${RPMCONFFILE})"
	@echo "+--------------------------------------------------------------------+"
#RPM demands ${SRCTMP} to exist, so we have to fake it; to know we are
#faking it (so we can remove the fake) we use the /tmp/fakesrctmp as a flag
#Now the fu*** morons even check the file size!!! MOOOOROOOOOONSSSSS!!!!!
	@if test ! -f ${SRCTMP} ; then cp ./Makefile ${SRCTMP}; touch /tmp/fakesrctmp; fi
	${RPMBUILD} -bl ${RPMCONFFILE}
	@if test -f /tmp/fakesrctmp; then rm -f ${SRCTMP}; rm -f /tmp/fakesrctmp; fi
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM config file (${RPMCONFFILE}) tested OK"
	@echo "+--------------------------------------------------------------------+"
	
#############################
#	
rpm.check.all.post:
	${RPMBUILD} -bl ${RPMCONFFILE}
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM config file (${RPMCONFFILE}) tested OK"
	@echo "+--------------------------------------------------------------------+"
	
	
###############################
# Refresh vital files
rpm.refresh.specfile:
ifneq "${shell id --name --user}" "root"
	./config.status --file etc/aubit-rpm.spec
	./config.status --file incl/Makefile-common
else
	@echo "NEVER try to buid RPM packages as user 'root'!"
	exit 1
endif
	
##############################
#
rpm.check.deps: 
#./bin/4glc
#Not sure this makes any senese on Linux - since I did not find a way to disable
#ldconfing cache or DT_RPATH/DT_RUNPATH, it will esentially just tell us which
#libraries we used to link Aubit stuff are not in ld.so.conf, since only thing I can 
#disable is LD_LIBRARY_PATH. Bastard is even smart enough to find libraries I 
#intentionally renamed...
	export MAKINGAUBIT=0; export IGNORE_MISSING_DEPS=1; ${SH} bin/4glpc.obsolete -deps

	
###############################
#
./bin/4glc:
	@echo "+--------------------------------------------------------------------+"
	@echo "| NOTE: target $@ invoked as depedency - starting build..."
	@echo "+--------------------------------------------------------------------+"
#	exit 1
	${MAKE}
	
##############################	
#Install created binary RPM and check it against binary installation 
#created with 'make install' for consistency:
rpm.install:
#       --badreloc
#              Used  with  --relocate,  permit  relocations on all
#              file paths, not just those  OLDPATH's  included  in
#              the binary package relocation hint(s).
#      --noscripts        --nopre        --nopost        --nopreun        --nopostun
#       --prefix NEWPATH
#              For relocateable  binary  packages,  translate  all
#              file  paths that start with the installation prefix
#              in the package relocation hint(s) to NEWPATH.

#       --relocate OLDPATH=NEWPATH
#              For relocatable binary packages, translate all file
#              paths  that start with OLDPATH in the package relo�
#              cation hint(s) to NEWPATH.  This option can be used
#              repeatedly  if several OLDPATH's in the package are
#              to be relocated.
	su -c "rpm --install --noscripts --prefix ${TMP_RPM_INSTDIR} ${RPM_FILE}"
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM installed to ${TMP_RPM_INSTDIR}"
	@echo "+--------------------------------------------------------------------+"

##############################
#
rpm.deinstall:
	su -c "rpm --erase --noscripts aubit4gl; rm -rf ${TMP_RPM_INSTDIR}"
	@echo "+--------------------------------------------------------------------+"
	@echo "| aubit4gl RPM deinstalled"
	@echo "+--------------------------------------------------------------------+"

##############################
#
rpm.test.files:
	export MAKINGAUBIT=0; export INSTALLDIR="${TMP_RPM_INSTDIR}" ;${SH} bin/4glpc.obsolete -chk-install
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM files compare test finished"
	@echo "+--------------------------------------------------------------------+"

##############################
# The main target for testing of RPM package consitency; also invoked from
# aubitbuild.sh as part of automatic nightly builds
rpm.check:
	su -c "${MAKE} rpm.check.internal"
rpm.check.internal: rpm.deinstall rpm.install rpm.test.files rpm.deinstall
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM test finished"
	@echo "+--------------------------------------------------------------------+"
	
##############################	
# Show info about the RPM package
#rpm.info: RPM_FILE=${RPMBUILDROOT}/RPMS/i586/${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}-1.i586.rpm
rpm.info:
#This command will show details about RPM and list all files in it
	rpm -qpil ${RPM_FILE}
#It will tell you if you can relocate the files.	
	rpm -qp --queryformat '%{DEFAULTPREFIX}\n' ${RPM_FILE}
#INSTALLPREFIX displays the prefix under which a package was installed.
	-rpm -q --queryformat '%{INSTALLPREFIX}\n' aubit4gl
#If the package is not relocatable, you'll only see the word (none). If, on the 
#other hand, the command displays a path, that means the package is relocatable. 
#Unless specified otherwise, every file in the package will be installed 
#somewhere below the path specified by the default prefix. 

##############################
# Make a patch by diffing two directories
build.diff.patch:
	diff -uNr ${dirname}.orig ${dirname} > ${dirname}.patch
#Please, use cvs diff -u3p.

##############################
# Create Linux Software Map (.lsm) used by autospec, see http://www.execpc.com/lsm/
aubit4gl.lsm: OUTFILE=aubit4gl.lsm
aubit4gl.lsm:
	@echo Begin4 > ${OUTFILE}
	@echo Title: Aubit 4gl compiler >> ${OUTFILE}
	@echo Version: ${AUBITVERSION}.${AUBITBUILD} >> ${OUTFILE}
	@echo Entered-date: ${COMPILEDATE} >> ${OUTFILE}
	@echo Description: Compiler for x4gl programming language >> ${OUTFILE}
	@echo Keywords: compiler 4gl database sql gui >> ${OUTFILE}
	@echo Author: Mike Aubury >> ${OUTFILE}
	@echo Maintained-by: Aubit development team >> ${OUTFILE}
	@echo Primary-site: http://aubit4gl.sourceforge.net >> ${OUTFILE}
	@echo Alternate-site: http://www.falout.com >> ${OUTFILE}
	@echo Original-site: http://www.aubit.com >> ${OUTFILE}
	@echo Platforms: POSIX Win32 >> ${OUTFILE}
	@echo Copying-policy: GNU GPL LGPL >> ${OUTFILE}
	@echo End >> ${OUTFILE}
	@echo >> ${OUTFILE}
	@echo >> ${OUTFILE}
	@echo Note: >> ${OUTFILE}
	@echo send this file to 'lsm@execpc.com' with the subject 'add'. >> ${OUTFILE}


## ------------------------------------------------------------------
##                      Deb packaging
## ------------------------------------------------------------------

#Notes:
#See http://kitenet.net/~joey/code/alien.html
#If alien is not run as root, the files in the generated package will have incorrect owners and permissions.  
#For converting to (but not from) deb format, the gcc, make, debmake, dpkg-dev, and dpkg packages must be installed.

##############################
# Convert RPM to Deb (aubit4gl-1.00.8-1.i686.rpm will be converted to aubit4gl_1.00.8-1_i386.deb)
#deb: ${RPM_FILE}
deb: ${RPM_FILE_TO_MAKE}
#-k = keep original version number 	 --scripts = include pre/post RPM scriptlets
	alien --to-deb --scripts -k $^
#Stampede .slp:
#	alien --to-slp --scripts -k $^
#Slackware tgz:
#	alien --to-tgz --scripts -k $^
	@echo "+--------------------------------------------------------------------+"
	@echo "| Alien converted RPM to ${shell find . -name ${AUBITNAME}_${AUBITVERSION}.${AUBITBUILD}-1_*.deb}"
	@echo "| To install it, use command 'dpkg -i <filename>.deb'"
	@echo "+--------------------------------------------------------------------+"

#--generate
#    Generate a temporary directory suitable for building a package from, but do not 
#    actually create the package. This is useful if you want to move files around in 
#    the package before building it. The package can be built from this temporary 
#	directory by running ``debian/rules binary'', if you were creating a Debian 
#	package, or by running ``rpm -bb <packagename>.spec'' if you were creating a Red Hat package.
	
#--scripts
#    Try to convert the scripts that are meant to be run when the package is 
#	installed and removed. Use this with caution, becuase these scripts might be 
#	designed to work on a system unlike your own, and could cause problems. It is 
#	recommended that you examine the scripts by hand and check to see what they do 
#	before using this option.
#    This is enabled by default when converting from lsb packages.

##############################
#
deb.scp:
	scp ${shell find . -name ${AUBITNAME}_${AUBITVERSION}.${AUBITBUILD}-1_*.deb} root@192.168.1.200:/srv/www/htdocs/files
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: done. URL:"
	@echo "| http://192.168.1.200/files/${shell find . -name ${AUBITNAME}_${AUBITVERSION}.${AUBITBUILD}-1_*.deb}"
	@echo "+--------------------------------------------------------------------+"

##############################
#
#all.scp: deb.scp rpm.scp autopackage.scp tar tar.bin
ALLPKGS=${shell find . -name ${AUBITNAME}_${AUBITVERSION}.${AUBITBUILD}-1_*.deb} \
	${RPM_SRC_FILE} ${RPM_FILE} ./${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package \
	${SOURCETARBASENAME} $(INSTALL_DIR)/${BINTARBASENAME}

all.packages.scp:
	@for x in ${ALLPKGS}; do \
		if ! test -f $$x; then \
			echo "ERROR: $$x is missing"; \
			exit 1; \
		else \
			echo "OK: $$x"; \
		fi ; \
	done
	scp ${ALLPKGS} root@192.168.1.200:/srv/www/htdocs/files
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: done. URL:"
	@echo "| http://192.168.1.200/files/"
	@echo "+--------------------------------------------------------------------+"

##############################
#
all.packages: rpm deb autopackage tar tar.bin
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: done."
	@echo "+--------------------------------------------------------------------+"
	
	
## ------------------------------------------------------------------
##                      AutoPackage packaging
## ------------------------------------------------------------------

####################################################################
#
# WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!! WARNING!!!
# Remeber that this makefile allready sets PATH LD_LIBRARY_PATH AUBITDIR etc
# so we need to REMOVE it before we run created installer/deinstaller/etc
# and also need to DEINSTALL 'make install' installed files !
#
#####################################################################

#Issues - user never propted for location
#.proxy files not deinstalled
#TUI install root prompt - cant automate install 

#AutoPackage utillities to potentially use in the future: 
#BinReloc - utility for easy relocation of binary packages
#objdum -p progname : required libs appear near the top in 'Dynamic sections'
#objdump -u: ??
#ldd -u : needed, but never used dependencies
#APBUILD SCRIPTS - filter out not needed dependencies (CC=apgcc; CXX=apg++)

autopackage.skeletons:
	ls /usr/share/autopackage/skeletons/@*

#WARNING: 'makeinstaller' apparently re-runs config-status if it finds .in file -
#and because we are altering it from here, we need to cheat by moving it away.
#TODO - do all changes in configure so we dont have to do this
AP_SPEC=./etc/default.apspec
AP_SPEC_USE=/tmp/default.apspec

#List of all .desktop and .applications files we need to make
ALL_DESKTOP=${PREFIX}/etc/aubit4gl-configurator.desktop
ALL_APPLICATIONS=${PREFIX}/etc/aubit4gl-configurator.applications

ifeq "${AP_UI}" "GUI"
#GUI seems to ingore -p :
	AP_INST_TMP=${HOME}/.local/aubit4gl-ap
	AP_UI_FLAG=""
	#AUTOPACKAGE_FRONTEND=autopackage-frontend-qt
	AUTOPACKAGE_FRONTEND=autopackage-frontend-gtk
	export AUTOPACKAGE_FRONTEND
else
	AP_INST_TMP=/tmp/autopackage2.test
	AP_UI_FLAG="-t"
	#AUTOPACKAGE_FRONTEND=apkg-ttyfe
endif

################################################
# clean, create package, test
autopackage: autopackage.clean autopackage.prepare autopackage.package \
	autopackage.test 
#autopackage.stat
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: all done"
	@echo "+--------------------------------------------------------------------+"

################################################
#Create and deploy package to download web site
autopackage.deploy: autopackage.clean autopackage.prepare autopackage.package autopackage.scp
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: all done"
	@echo "+--------------------------------------------------------------------+"

################################################
#SCP the package to WWW root for download
autopackage.scp:
	scp ./${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package root@192.168.1.200:/srv/www/htdocs/files
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: done. URL:"
	@echo "| http://192.168.1.200/files/${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package"
	@echo "+--------------------------------------------------------------------+"

################################################
#SCP the package to user 'aubit' Desktop for testing
autopackage.put:
	scp ./${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package aubit@192.168.1.200:/home/aubit/Desktop
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: done. File placed on Desktop of user 'aubit'"
	@echo "+--------------------------------------------------------------------+"
	
################################################
#Create the installer .package file
autopackage.package: ./${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package
./${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package: ${PREFIX}/bin/4glc ${ALL_DESKTOP} ${ALL_APPLICATIONS}
	export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
		makeinstaller ${AP_SPEC_USE}
#The meta package is 'aubit4gl-1.00.3.x86.package.meta'.
#	@echo "${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package.meta"
#The complete package is 'aubit4gl-1.00.3.x86.package'.
#	@echo "${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package"
#The Luau repository XML entry file is 'aubit4gl.xml'.
#	@echo "${AUBITNAME}.xml"
	@echo "+--------------------------------------------------------------------+"	
	@echo "| make $@ completed; all files created in current directory"
	@echo "+--------------------------------------------------------------------+"	

################################################
# Tried to compile from spoec file - what a nightmare
# UNUSED:
#autopackage.build:
#DONT_PASS_AC_FLGS: Tell aubitconf not to pass silly flags set by makeinstaller
#INJECT_AC_FLAGS: tell aubitconf to inject flags that AutoPackage would want
#Note that we dont pass CFLAGS from configure to makefiles anyway
#	export STRIP_PARAM_Q=0; export INJECT_AC_FLAGS="--prefix=/usr/local CC=apgcc CFLAGS= -O2 -march=i586 -pipe";
#	export STRIP_PARAM_Q=0; export INJECT_AC_FLAGS="--disable-prefix-check --prefix=/usr/local CC=apgcc CFLAGS=-pipe"; 
#	export STRIP_PARAM_Q=0; export INJECT_AC_FLAGS="--prefix=/usr/local CC=apgcc CFLAGS=-pipe"; export DONT_PASS_AC_FLGS=1; 
	

############################
# Dependecy checking
${PREFIX}/bin/4glc: install
#${PREFIX}/bin/4glc:
	@echo "+--------------------------------------------------------------------+"	
	@echo "| Target $@ invoked as missing dependency! "
	@echo "+--------------------------------------------------------------------+"
#	exit 1

##############################################
# Few quick checks
autopackage.stat:
#${HOME}/.local/share/applications/ contains ALL system .desktop files
#/home/aubit/.local/share/icons
#/home/aubit/.local/share/Trash
	@export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
	if test -d ${AP_INST_TMP}; then \
		echo "TMP package inst dir exists, `ls ${AP_INST_TMP}/bin | wc -l` files under bin/"; \
		file ${AP_INST_TMP}/bin/aubit-config ;\
		echo "aubit-config reports AUBITDIR=`${AP_INST_TMP}/bin/aubit-config AUBITDIR`"; \
	else \
		echo "TMP package inst dir DOES NOT exists"; \
	fi
	@export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
	if test -d ${HOME}/.local/bin ; then \
		echo "HOME/.local/bin dir exists, `ls ${HOME}/.local/bin | wc -l` files under bin/"; \
		if test "`echo ${PATH} | grep ${HOME}/.local/bin`" != ""; then \
			echo "...and it's in the PATH"; \
		fi \
	else \
		echo "HOME/.local/bin dir DOES NOT exists"; \
	fi
	@export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
	if test -d ${HOME}/.local/lib ; then \
		echo "HOME/.local/lib dir exists"; \
		if test "`echo ${LD_LIBRARY_PATH} | grep ${HOME}/.local/lib`" != ""; then \
			echo "...and it's in the LD_LIBRARY_PATH"; \
		fi \
	else \
		echo "HOME/.local/lib dir DOES NOT exists"; \
	fi
	@echo "+--------------------------------------------------------------------+"
#-w	
	@export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
	AD_LIST=`find ${HOME} -exec grep --exclude=aubit4gl/ --count --binary-files=without-match --with-filename --no-messages AUBITDIR {} \; | grep -v "\:0"` ; \
	for file in $$AD_LIST; do \
		echo "$$file" ; \
	done
	@echo "+--------------------------------------------------------------------+"
	@echo "AUBITDIR in ${HOME}/.aubit4gl/aubitrc :"
	@grep -w AUBITDIR ${HOME}/.aubit4gl/aubitrc
	@echo "+--------------------------------------------------------------------+"	
	@echo "AUBITDIR in ${HOME}/.packages/@aubit4gl.sf.net/aubit4gl:${AUBIT_VERSION}.${AUBIT_BUILD}/environment.en :"	
	@grep -w AUBITDIR ${HOME}/.packages/@aubit4gl.sf.net/aubit4gl:${AUBIT_VERSION}.${AUBIT_BUILD}/environment.en
	@echo "+--------------------------------------------------------------------+"
	
ss:
	@echo "+--------------------------------------------------------------------+"
#bin dev .gnupg lib mnt proc sbin subdomain var boot home media root srv sys
#	@AP_DIRS="/usr/libexec/autopackage /usr/share/autopackage /etc/autopackage ${HOME}"; 
	@AP_DIRS="/usr /opt /etc /tmp"; \
	for onedir in $$AP_DIRS; do \
		find $$onedir -exec grep --with-filename --count "autopackage\.test" {} 2> /dev/null \;  | grep -v "\:0" ; \
	done
	@echo "+--------------------------------------------------------------------+"

	
#		grep -w AUBITDIR $$file; 	
#--count
#--files-with-matches stops on the first match
#/home/aubit/.bashrc:[[ -f "/home/aubit/.config/autopackage/paths-bash" ]] && . "/home/aubit/.config/autopackage/paths-bash"
#/home/aubit/.config/: autopackage  gtk-2.0  menus
	
	
#find /var/packages -exec grep --with-filename "autopackage.test" {} 2> /dev/null \;


################################################
#Create the installer .apspec file
#TODO - move all relaces into ./configure
autopackage.prepare: ${PREFIX}/bin/4glc
	./config.status --file ${AP_SPEC}
	@unset AP_ROOT_FILES; for file in `find ${PREFIX} -maxdepth 1 -type f`; do export AP_ROOT_FILES="$$AP_ROOT_FILES `basename $$file`"; done; \
		echo "In makefile AP_ROOT_FILES=$$AP_ROOT_FILES"; \
		sed -e "/^export AP_ROOT_FILES/s/@AP_ROOT_FILES@/$$AP_ROOT_FILES/" ${AP_SPEC} > /tmp/out1.out
	@grep "^export AP_ROOT_FILES" /tmp/out1.out
	@unset AP_BIN_FILES; for file in `find ${PREFIX}/bin -maxdepth 1 -type f`; do export AP_BIN_FILES="$$AP_BIN_FILES `basename $$file`"; done; \
		echo "In makefile AP_BIN_FILES=$$AP_BIN_FILES"; \
		sed -e "/^export AP_BIN_FILES/s/@AP_BIN_FILES@/$$AP_BIN_FILES/" /tmp/out1.out > /tmp/out2.out
	@grep "^export AP_BIN_FILES" /tmp/out2.out
	@unset AP_ETC_FILES; for file in `find ${PREFIX}/etc -maxdepth 1 -type f`; do export AP_ETC_FILES="$$AP_ETC_FILES `basename $$file`"; done; \
		echo "In makefile AP_ETC_FILES=$$AP_ETC_FILES"; \
		sed -e "/^export AP_ETC_FILES/s/@AP_ETC_FILES@/$$AP_ETC_FILES/" /tmp/out2.out > /tmp/out1.out
	@grep "^export AP_ETC_FILES" /tmp/out1.out
	@unset AP_ETC_CONFIG_FILES; for file in `find ${PREFIX}/etc/config -maxdepth 1 -type f`; do export AP_ETC_CONFIG_FILES="$$AP_ETC_CONFIG_FILES `basename $$file`"; done; \
		echo "In makefile AP_ETC_CONFIG_FILES=$$AP_ETC_CONFIG_FILES"; \
		sed -e "/^export AP_ETC_CONFIG_FILES/s/@AP_ETC_CONFIG_FILES@/$$AP_ETC_CONFIG_FILES/" /tmp/out1.out > /tmp/out2.out
	@grep "^export AP_ETC_CONFIG_FILES" /tmp/out2.out
	@unset AP_ETC_IMPORT_FILES; for file in `find ${PREFIX}/etc/import -maxdepth 1 -type f`; do export AP_ETC_IMPORT_FILES="$$AP_ETC_IMPORT_FILES `basename $$file`"; done; \
		echo "In makefile AP_ETC_IMPORT_FILES=$$AP_ETC_IMPORT_FILES"; \
		sed -e "/^export AP_ETC_IMPORT_FILES/s/@AP_ETC_IMPORT_FILES@/$$AP_ETC_IMPORT_FILES/" /tmp/out2.out > /tmp/out1.out
	@grep "^export AP_ETC_IMPORT_FILES" /tmp/out1.out
	@unset AP_ETC_CONVERTSQL_FILES; for file in `find ${PREFIX}/etc/convertsql -maxdepth 1 -type f`; do export AP_ETC_CONVERTSQL_FILES="$$AP_ETC_CONVERTSQL_FILES `basename $$file`"; done; \
		echo "In makefile AP_ETC_CONVERTSQL_FILES=$$AP_ETC_CONVERTSQL_FILES"; \
		sed -e "/^export AP_ETC_CONVERTSQL_FILES/s/@AP_ETC_CONVERTSQL_FILES@/$$AP_ETC_CONVERTSQL_FILES/" /tmp/out1.out > /tmp/out2.out
	@grep "^export AP_ETC_CONVERTSQL_FILES" /tmp/out2.out
	@unset AP_DOCS_FILES; for file in `find ${PREFIX}/docs -maxdepth 1 -type f`; do export AP_DOCS_FILES="$$AP_DOCS_FILES `basename $$file`"; done; \
		echo "In makefile AP_DOCS_FILES=$$AP_DOCS_FILES"; \
		sed -e "/^export AP_DOCS_FILES/s/@AP_DOCS_FILES@/$$AP_DOCS_FILES/" /tmp/out2.out > /tmp/out1.out
	@grep "^export AP_DOCS_FILES" /tmp/out1.out
	@unset AP_INCL_FILES; for file in `find ${PREFIX}/incl -maxdepth 1 -type f`; do export AP_INCL_FILES="$$AP_INCL_FILES `basename $$file`"; done; \
		echo "In makefile AP_INCL_FILES=$$AP_INCL_FILES"; \
		sed -e "/^export AP_INCL_FILES/s/@AP_INCL_FILES@/$$AP_INCL_FILES/" /tmp/out1.out > /tmp/out2.out
	@grep "^export AP_INCL_FILES" /tmp/out2.out
	@unset AP_TOOLS_FILES; for file in `find ${PREFIX}/tools -maxdepth 1 -type f`; do export AP_TOOLS_FILES="$$AP_TOOLS_FILES `basename $$file`"; done; \
		echo "In makefile AP_TOOLS_FILES=$$AP_TOOLS_FILES"; \
		sed -e "/^export AP_TOOLS_FILES/s/@AP_TOOLS_FILES@/$$AP_TOOLS_FILES/" /tmp/out2.out > /tmp/out1.out
	@grep "^export AP_TOOLS_FILES" /tmp/out1.out
	@unset AP_TOOLS_TEST_FILES; for file in `find ${PREFIX}/tools/test -maxdepth 1 -type f`; do export AP_TOOLS_TEST_FILES="$$AP_TOOLS_TEST_FILES `basename $$file`"; done; \
		echo "In makefile AP_TOOLS_TEST_FILES=$$AP_TOOLS_TEST_FILES"; \
		sed -e "/^export AP_TOOLS_TEST_FILES/s/@AP_TOOLS_TEST_FILES@/$$AP_TOOLS_TEST_FILES/" /tmp/out1.out > /tmp/out2.out
	@grep "^export AP_TOOLS_TEST_FILES" /tmp/out2.out
	@unset AP_TOOLS_TEST_GUI_FILES; for file in `find ${PREFIX}/tools/test/gui -maxdepth 1 -type f`; do export AP_TOOLS_TEST_GUI_FILES="$$AP_TOOLS_TEST_GUI_FILES `basename $$file`"; done; \
		echo "In makefile AP_TOOLS_TEST_GUI_FILES=$$AP_TOOLS_TEST_GUI_FILES"; \
		sed -e "/^export AP_TOOLS_TEST_GUI_FILES/s/@AP_TOOLS_TEST_GUI_FILES@/$$AP_TOOLS_TEST_GUI_FILES/" /tmp/out2.out > /tmp/out1.out
	@grep "^export AP_TOOLS_TEST_GUI_FILES" /tmp/out1.out
	@unset AP_TOOLS_4GLPC_FILES; for file in `find ${PREFIX}/tools/4glpc -maxdepth 1 -type f`; do export AP_TOOLS_4GLPC_FILES="$$AP_TOOLS_4GLPC_FILES `basename $$file`"; done; \
		echo "In makefile AP_TOOLS_4GLPC_FILES=$$AP_TOOLS_4GLPC_FILES"; \
		sed -e "/^export AP_TOOLS_4GLPC_FILES/s/@AP_TOOLS_4GLPC_FILES@/$$AP_TOOLS_4GLPC_FILES/" /tmp/out1.out > /tmp/out2.out
	@grep "^export AP_TOOLS_4GLPC_FILES" /tmp/out2.out
	@unset AP_TOOLS_4GLPC_SETTINGS_FILES; for file in `find ${PREFIX}/tools/4glpc/settings -maxdepth 1 -type f`; do export AP_TOOLS_4GLPC_SETTINGS_FILES="$$AP_TOOLS_4GLPC_SETTINGS_FILES `basename $$file`"; done; \
		echo "In makefile AP_TOOLS_4GLPC_SETTINGS_FILES=$$AP_TOOLS_4GLPC_SETTINGS_FILES"; \
		sed -e "/^export AP_TOOLS_4GLPC_SETTINGS_FILES/s/@AP_TOOLS_4GLPC_SETTINGS_FILES@/$$AP_TOOLS_4GLPC_SETTINGS_FILES/" /tmp/out2.out > /tmp/out1.out
	@grep "^export AP_TOOLS_4GLPC_SETTINGS_FILES" /tmp/out1.out
#Note - directory name depends on the version number
	@unset AP_PLUGINS_FILES; for file in `find ${PREFIX}/plugins-${AUBIT_VERSION}_${AUBIT_BUILD} -maxdepth 1 -type f`; do export AP_PLUGINS_FILES="$$AP_PLUGINS_FILES `basename $$file`"; done; \
		echo "In makefile AP_PLUGINS_FILES=$$AP_PLUGINS_FILES"; \
		sed -e "/^export AP_PLUGINS_FILES/s/@AP_PLUGINS_FILES@/$$AP_PLUGINS_FILES/" /tmp/out1.out > /tmp/out2.out
	@grep "^export AP_PLUGINS_FILES" /tmp/out2.out
#Warning - avoid libaubit4gl.so - we will create link for it
	@unset AP_LIB_FILES; for file in `find ${PREFIX}/lib/*_*.* -maxdepth 1 -type f`; do export AP_LIB_FILES="$$AP_LIB_FILES `basename $$file`"; done; \
		echo "In makefile AP_LIB_FILES=$$AP_LIB_FILES"; \
		sed -e "/^export AP_LIB_FILES/s/@AP_LIB_FILES@/$$AP_LIB_FILES/" /tmp/out2.out > /tmp/out1.out
	@grep "^export AP_LIB_FILES" /tmp/out1.out
#Final bounce:
	cp /tmp/out1.out ${AP_SPEC_USE}
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@ completed; ${AP_SPEC_USE} created "
	@echo "+--------------------------------------------------------------------+"


################################################
#Create a default spec file
autopackage.default:
	export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
		makeinstaller --mkspec > /tmp/aubit4gl.default.apspec


################################################
#Test created package
autopackage.test: autopackage.install autopackage.compare
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@ completed"
	@echo "+--------------------------------------------------------------------+"

################################################
# Execute .package to run installed in TUI mode to tmp location
autopackage.install: ./${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package deinstall 
#check.exe.in.path
#.package files support:
# -x : this extracts the contents and places them in a directory named after 
#	the package. Use this when you don't want to install software, but instead 
#	just want the contents.
# -p/--prefix : you can select where you want packages to install to with this switch
# -t : forces the use of the TTYFE mode. If you have a graphical environment 
#	running but would prefer a purely command line based install, use this switch
# -d : puts the package into debug mode. In this mode, the metadata and payload 
#	are extracted to a temporary working directory. Then instead of starting the 
#	install scripts, you are dumped into a shell. You can now investigate or 
#	change the control scripts or payload. Type "exit" to quit the shell and clean up.
# -f, --force       Overrides fatal warnings to force the install to proceed
# -g, --gtkfe       Forces the usage of the graphical GTK based frontend
# -h, --help        Display this help screen
#
#WARNING - -p flag (install location/PREFIX) seems to be ignored in GUI installed and only valid for TUI
	export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
	export DEBUGLEVEL=3 ; ./$< ${AP_UI_FLAG} -p ${AP_INST_TMP}
ifeq "${LIST}" "1"
	@echo "+--------------------------------------------------------------------+"
	@echo "| Files installed to ${AP_INST_TMP}:"
	@echo "+--------------------------------------------------------------------+"	
	@find ${AP_INST_TMP}
endif
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: Done (see ./autopackage.log) "
	@echo "+--------------------------------------------------------------------+"	


#As we cant run AutoPackage deinstaller without user input, we depend on installer
#to first de-install; therefore we will at this point still potentially have AutoPackage
#installed executables in path. So we cant really use this test...
check.exe.in.path:
	@export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
	if test "`which aubit 2>/dev/null`" != "" -o "`which aubit-config 2>/dev/null`" != ""  \
		-o "`which 4glc 2>/dev/null`" != ""; then \
		echo "ERROR: we still have Aubit executables in the path!"; \
			which aubit; \
			which aubit-config; \
			which 4glc; \
		exit 1; \
	fi
	
################################################
# Extract files from package, so we can inspect them
autopackage.extract:
	export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
		./${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package -x ${AP_UI_FLAG}
	
################################################
# Compare AutoPackage installed files agains files installed by 'make install'
autopackage.compare: ${PREFIX}/bin/4glc
#Cant do diff as AutoPackage wraps executables into scripts
	@echo "+--------------------------------------------------------------------+"
	@echo "| Comparing AutoPackage installed files against files installed by 'make install'"
	@echo "+--------------------------------------------------------------------+"	
	@if test -d ${AP_INST_TMP}; then \
	if test -f ${PREFIX}/bin/4glc ; then \
		for file in `cd ${PREFIX}; find -type f | sed -e 's/\.\///g'`; do \
			true "Checking ${AP_INST_TMP}/$$file ..."; \
			if ! test -f ${AP_INST_TMP}/$$file; then \
				if test \
				"`echo $$file | grep 'CVS'`" = "" -a \
				"`echo $$file | grep '\.desktop'`" = "" -a \
				"`echo $$file | grep '\.applications'`" = "" -a \
				"`echo $$file | grep '\.db'`" = "" -a \
				"`echo $$file | grep 'config.nice'`" = "" -a \
				"`echo $$file | grep '\.png'`" = "" \
				; then \
					echo "ERROR: missing  ${AP_INST_TMP}/$$file"; \
				fi; \
			fi; \
		done ; \
	else \
		echo "ERROR: ${PREFIX} seems empty - Aubit was not installed there?"; \
	fi ; \
	else \
		echo "ERROR: ${AP_INST_TMP} does not exist !"; \
	fi
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: Done"
	@echo "+--------------------------------------------------------------------+"	
	
################################################
#Debug created package
autopackage.debug: ./${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package deinstall
#The following environment variables control how much debugging information is outputted:
#
#Installation of packages
#    * DEBUGLEVEL - Controls debugging output from the core program. Can be any 
#      number between 0 and 3 where 3 is the most verbose level.
#    * GTKFE_DEBUGLEVEL - Controls the debugging output from the GTK Frontend. Can 
#      be any number where a higher number means higher verbosity.
#
#Other autopackage programs
#    * AUTOPACKAGE_MANAGER_GTK_DEBUG - Makes the GTK version of the manager print 
#      debugging info. Value is boolean.
#    * AUTOPACKAGE_MANAGER_BACKEND_DEBUG - Makes the backend for the manager print 
#      debugging info. Value is boolean.
#    * AUTOPACKAGE_MKAPSPEC_DEBUG - Makes mkapspec print debugging information. Value is boolean.
#    * APBUILD_DEBUG - Makes apbuild print debugging information. Value is boolean.
#
#WARNING - -p flag (install location/PREFIX) seems to be ignored in GUI installed and only valid for TUI
	export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
		export DEBUGLEVEL=3 ; ./$^ -d ${AP_UI_FLAG} -p ${AP_INST_TMP}
#	find . -exec grep AP_LIB_FILES {} \;
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: Done"
	@echo "+--------------------------------------------------------------------+"	

	
################################################
# Clean all AutoPackage created files
autopackage.clean:
	${RM} ${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package.meta \
		${AUBITNAME}-${AUBIT_VERSION}.${AUBIT_BUILD}.x86.package \
		${AUBITNAME}.xml
#Dont delete directory where AP installed - it confuses the deinstaller:
#	rm -rf ${AP_INST_TMP}
	${RM} ${ALL_DESKTOP} ${ALL_APPLICATIONS} \
	${PREFIX}/docs/aubit4gl.png ${AP_SPEC_USE} /tmp/out1.out /tmp/out2.out ./autopackage.log
	rm -rf /tmp/apkg-fifo*
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: Done"
	@echo "+--------------------------------------------------------------------+"	

################################################
#Deinstall and then clean all traces of any AutoPackagge related activity
autopackage.remove: autopackage.deinstall autopackage.clean
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: Done"
	@echo "+--------------------------------------------------------------------+"	
	
	
###############################################
# Deinstall the package
autopackage.deinstall:
#CRAP - cant make it stay in TUI - allways pops up GUI:
#Installing automatically de-installs previous, so we can ignore it here
	-export PATH=${INIT_PATH}; export LD_LIBRARY_PATH=${INIT_LD_LIBRARY_PATH}; unset AUBITDIR; \
		export DEBUGLEVEL=3; export AUTOPACKAGE_MANAGER_BACKEND_DEBUG=3; package remove aubit4gl
#	package remove aubit4gl
#/home/aubit/.local/share/applications/ contains ALL system .desktop files
#/home/aubit/.local/share/icons
#/home/aubit/.local/share/Trash
#/home/aubit/.local/bin <<<<<<<<<<<<<<<<
#Spemthing also added /home/aubit/.local/lib to LD_LIBRARY_PATH
	@unset AP_BIN_FILES; for file in `find ${PREFIX}/bin -maxdepth 1 -type f`; do export AP_BIN_FILES="$$AP_BIN_FILES `basename $$file`"; done; \
		for afile in $$AP_BIN_FILES; do \
			REMOVE="${HOME}/.local/bin/$$afile"; \
			REMOVE2="${HOME}/.local/bin/.proxy.$$afile"; \
			echo "removing $$REMOVE and $$REMOVE2"; \
			${RM} $$REMOVE $$REMOVE2 ; \
		done
#/home/aubit/.bashrc:[[ -f "/home/aubit/.config/autopackage/paths-bash" ]] && . "/home/aubit/.config/autopackage/paths-bash"
#/home/aubit/.config/: autopackage  gtk-2.0  menus
	@echo "+--------------------------------------------------------------------+"
	@echo "| Files still in ~/.local/bin :"
	@echo "+--------------------------------------------------------------------+"	
	-ls -al ~/.local/bin/
	@echo "+--------------------------------------------------------------------+"
	@echo "| make $@: Done"
	@echo "+--------------------------------------------------------------------+"	

################################################
#
AP_VER=1.2.1
AP_GTK_VER=${AP_VER}
AP_QT_VER=1.2
autopackage.install.tools: autopackage.install.dev autopackage.install.gui
	package list
	
################################################
#
autopackage.install.dev:
	wget http://ftp.sunsite.dk/projects/autopackage/${AP_VER}/Autopackage%20Development%20Environment%20${AP_VER}.package
#mkapspec: APSpec File Generator
	chmod a+x *.package
	./Autopackage%20Development%20Environment%20${AP_VER}.package
	
################################################
#Download and install AutoPackage GUI interface packages
autopackage.install.gui:
	wget http://ftp.sunsite.dk/projects/autopackage/${AP_VER}/autopackage-gtk-${AP_VER}.package
	wget http://ftp.sunsite.dk/projects/autopackage/${AP_QT_VER}/autopackage-qt-${AP_QT_VER}.package
	chmod a+x *.package
	package install ./autopackage-gtk-${AP_VER}.package
	package install ./autopackage-qt-${AP_QT_VER}.package
	
################################################
#
autopackage.deinstall.tools: autopackage.deinstall.dev autopackage.deinstall.gui
	package list

################################################
#
autopackage.deinstall.dev:
	package remove autopackage-devel

################################################
#
autopackage.deinstall.gui:
	package remove autopackage-gtk
	package remove autopackage-qt

	
################################################
#Create .desktop file for GUI desktop envirionments (KDE, GNOME,...)
configurator.desktop: ${ALL_DESKTOP} 

${PREFIX}/etc/aubit4gl-configurator.desktop:
	@echo "[Desktop Entry]" > $@
	@echo "Name=Aubit 4GL compiler configuration" >> $@
	@echo "Comment=Configure Aubit compiler options" >> $@
	@echo "Exec=aubit4gl-configurator.sh" >> $@
	@echo "Icon=aubit4gl.png" >> $@
	@echo "Terminal=0" >> $@
	@echo "Type=Application" >> $@
#	@echo "MimeType=text/html" >> $@
	@echo "Categories=Application;Development;" >> $@
	echo "Created $@"
	convert docs/aubit4gl.ico ${PREFIX}/docs/aubit4gl.png

################################################
#Gnome 2 App Entry
configurator.applications: ${ALL_APPLICATIONS}

${PREFIX}/etc/aubit4gl-configurator.applications:
	@echo "configurator" > $@
	@echo "command=aubit4gl-configurator.sh" >> $@
	@echo "name=Aubit 4GL compiler configuration" >> $@
	@echo "can_open_multiple_files=false" >> $@
	@echo "expects_uris=false" >> $@
	@echo "requires_terminal=false" >> $@
	@echo "startup_notify=true" >> $@
#	@echo "mime_types=text/html" >> $@
	echo "Created $@"

## ------------------------------------------------------------------
##                       Other Targets (Misc.)
## ------------------------------------------------------------------

#This will increase build number; use it before releasing compiled binaries.
#Edit project/version file manually to increase version number; when
#you do, reset build counter to zero.
build:
	@echo Current versions before build number increase:
	@echo AUBITVERSION = ${AUBITVERSION} AUBITBUILD = ${AUBITBUILD}
	@chmod a+x tools/project/mkproject
	(cd tools/project; ${SH} mkproject -increase)
	@echo After build number increase:
	@echo "AUBITVERSION = `cat $(SOURCE)/tools/project/version` AUBITBUILD = `cat $(SOURCE)/tools/project/build`"
	@echo " "	
	@echo "==================================================================="
	@echo "                       WARNING!"
	@echo " As Aubit depends on the versin numbers to locate libraries of"
	@echo " particular version, DO NOT FORGET TO RE-RUN ./configure"
	@echo " after changing version and/or build number!"
	@echo " Also do not forget to clean the source code tree using"
	@echo " 'make clean.all' - as some compiled programs (like 4glc)"
	@echo " store version numbers at the compile time"
	@echo "==================================================================="
	@echo " "
	
commit.build: build commit.build.step2
commit.build.step2: BUILDNO=$(shell cat $(SOURCE)/tools/project/build)
commit.build.step2:
	@cvs commit -m "commit.build ${BULDNO}" > commit.log
	@echo "Build ${BUILDNO} Commit finished. See file './commit.log'"

#Compile example code
demo:
	${MAKE} ${MKNAME} -C tools/test
	@echo Aubit 4gl compiler examples are now compiled

help:
	@echo
	@echo This is Aubit 4gl compiler makefile help
	@echo
	@echo Usage: "make [targets] [option=value] ..."
	@echo
	@echo For more help use:
	@echo "  make help.options"
	@echo "  make help.targets"
	@echo "  make help.optional"
	@echo

help.targets:
	@echo
	@echo Targets:
	@echo
	@echo "  default (same as just "make") - compile the Aubit 4gl compiler"
#	@echo "  gtkgui - compile only GTK libraries"
	@echo "  clean - delete and temp and intermittent files, but not targets"
	@echo "  cleanall - delete ALL compiled object and temp files that where"
	@echo "          created with make. This will result in clan source code"
	@echo "          tree, as exported form CVS"
	@echo "  install - installs Aubit 4gl compiler in installation tree"
	@echo "  tarinstall - creates ${ARCHEXT} file from installation tree"
	@echo "  demo - compile 4gl exampe code in tools/test/ and tools/test/gui/"
	@echo "  log - log default target make process to ./make.log"
	@echo "  settings - show how is makefile configured"
	@echo "  platform - dump settings and current build data to $(PLATFORMINFO)"
	@echo

help.options:
	@echo
	@echo "Options: (first option is default)"
#	@echo "  PDFBUILD=(no/yes) NOTE: Must have PDF lib installed"
#	@echo "  GTKBUILD=(yes/no) NOTE: Must have GTK lib installed"
#	@echo "  JABBERBUILD=(yes/no) NOTE: Must have ikemel lib installed"
	@echo "  PREFIX=<path> Where to install compiler, default is ${PREFIX}"
	@echo
	@echo

help.optional:
	@echo
	@echo "Currently available automatic installation targets:"
	@echo " missing.optional: Install all options as detected mising by configure"
	@echo "  This would invoke this targets:"
	@echo "  ${INSTALL_MISSING_OPTIONAL}"
	@echo " install.iodbc: Install iODBC ODBC driver manager"
	@echo " install.pdflib: Install PDF library"
	@echo " install.iksemel: Install Jabber library"
	@echo " install.dot: Install DoxyGen Dot tool, part of Graphviz package"
	@echo ""
	@echo "FIXME: TO-DO:"
	@echo "install.doxygen:"
	@echo "install.pg.esql:"
	@echo "install.sapdb.odbc:"
	@echo "install.mpz:"
	@echo "install.sunrpc:"
	@echo "install.xmmlrpc:"
	@echo "install.unixodbc:"
	@echo "install.ifx.odbc:"
	@echo "install.pg.odbc:"
	@echo "install.ifx.esql:"
	@echo "install.gtk:"
	@echo ""


## ------------------------------------------------------------------
##       Handle CVS commits and updates
## ------------------------------------------------------------------

####################
#Update source code tree from CVS repository
update:
#FIXME: this will force user to type password TWICE unless SSH certificates are
#installed
#Note: - this configure check is just not worth it. In some sittuations CVS
#actually doenloads COMPLETE configure file form CVS to determine if the local 
#one was changed. It just takes too bloody long...and it was wrong - it would 
#remove local configure even when modified only localy
#	@cvs status ./configure | grep "Status: Locally Modified"; \
#		RET=$$?; \
#		if test "$$RET" = "0" ; then \
#			rm ./configure ; \
#			echo "./configure modified - removing it to avoid invalid merging"; \
#		else \
#			echo "./configure check OK."; \
#		fi
	@echo "+--------------------------------------------------------------------+"
	@echo "| CVS update started at `date`"
	@echo "| Logging to /tmp/cvsupdate-aubit4gl.log                             |"
	@echo "+--------------------------------------------------------------------+"	
	@echo " "
	@-cvs update -d -P > /tmp/cvsupdate-aubit4gl.log 2>&1; \
		RET=$$?; if test "$$RET" != "0"; then echo "ERROR: cvs updated failed"; fi
	@grep -v "cvs update: Updating" /tmp/cvsupdate-aubit4gl.log
	@grep "cvs update: conflict" /tmp/cvsupdate-aubit4gl.log  > /dev/null ; \
		RET=$$?; \
		if test "$$RET" = "0" ; then \
			grep "cvs update: conflict" /tmp/cvsupdate-aubit4gl.log; \
			echo "WARNING: conflict(s) detected - see /tmp/cvsupdate-aubit4gl.log"; \
		fi
	@grep "\.in" /tmp/cvsupdate-aubit4gl.log  > /dev/null ; \
		RET=$$?; \
		if test "$$RET" = "0" ; then \
			echo "WARNING: one or more .in files changed - run ./configure or ./config.status"; \
		fi
	@grep "configure" /tmp/cvsupdate-aubit4gl.log  > /dev/null ; \
		RET=$$?; \
		if test "$$RET" = "0" ; then \
			echo "WARNING: configure changed - re-run ./configure"; \
		fi
#TODO: check for merge conflicts		
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| CVS update finished at `date`"
	@echo "| See /tmp/cvsupdate-aubit4gl.log for details                        |"
	@echo "+--------------------------------------------------------------------+"
	@echo " "


####################
#Commit all changes to CVS repository
commit: refresh.all build
#Note: cvs commit command cannot be redirected to file because of the need
#to edit commit message
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| CVS commit started at `date`"
	@echo "+--------------------------------------------------------------------+"
	@echo " "
	cvs -q commit
	@echo " "
	@echo "+--------------------------------------------------------------------+"
	@echo "| CVS commit finished at `date`"
	@echo "+--------------------------------------------------------------------+"
	@echo " "
	
## ------------------------------------------------------------------
##       Maintainance of pre-assembled and pre-compiled files
##       used in absence of compiler tools when compiling from source code
## ------------------------------------------------------------------

####################
#refresh all files storred in CVS that are used in absence of verious
#compiler tools:
refresh.all: refresh.noyacc refresh.norpcgen refresh.norpclib refresh.perl

####################
#refresh pre-compiled parser files that are used for compilation on
#platforms that don't have Yacc (Bison) installed, or have incompatible version
#from Yacc created files:
#NOTE: diff exits with status 0 when files ARE DIFFERENT 

#  An exit status of 0 means no  differences  were  found,  1
#       means some differences were found, and 2 means trouble.

refresh.noyacc:
ifneq "${YACC}" "no"
	@update=0; \
	ALLF="4glc/rules/generated/y.tab.c 4glc/rules/generated/y.tab.h \
		4glc/rules/generated/kw.h 4glc/rules/generated/kw.yh \
		4glc/rules/generated/mk_states_1.h 4glc/rules/generated/mk_states.h 4glc/rules/generated/mk_states.c \
		sql/lex.sqlparse_yy.c sql/y.tab.c sql/y.tab.h \
		fcompile/lex.yy.c fcompile/y.tab.c \
		menus/lex.yy.c menus/y.tab.c \
		xgen/y.tab.c xgen/lex.yy.c \
		ace/y.tab.c ace/lex.yy.c"; \
	for a in $$ALLF; do \
		if test -f compilers/$$a ; then \
			if test -f tools/no_yacc/cygwin/compilers/$$a ; then \
				diff -q compilers/$$a tools/no_yacc/cygwin/compilers/$$a > /dev/null ; \
				x=$$?; \
				if test "$$x" != "0"; then update="1"; \
					echo "DIFFERENT: compilers/$$a"; \
					${CP} compilers/$$a tools/no_yacc/cygwin/compilers/$$a; \
				fi; \
			else \
				echo "MISSING DESTINATION: tools/no_yacc/cygwin/compilers/$$a" ; \
			fi ; \
		else \
			echo "MISSING SOURCE : compilers/$$a"; \
		fi ; \
	done; \
	if test "$$update" = "0"; then \
		echo "All no_yacc files up-to-date"; \
	fi
else
	@echo "Skipping refresh.noyacc - YACC=no."
endif



####################
#Since we are using xgen now, this should be obsolete
refresh.norpcgen:
ifneq "${COMSPEC}" ""
ifneq "${USE_RPCGEN}" "0"
	@x=0; \
	if diff -q compilers/fcompile/form_x.h tools/cygwin/form_x.h > /dev/null ; then x=1; fi; \
	if diff -q compilers/fcompile/form_x_xdr.c tools/cygwin/form_x_xdr.c > /dev/null ; then x=1; fi; \
	if diff -q compilers/menus/menu_x.h tools/cygwin/menu_x.h > /dev/null ; then x=1; fi; \
	if diff -q compilers/menus/menu_x_xdr.c tools/cygwin/menu_x_xdr.c > /dev/null ; then x=1; fi; \
	if diff -q compilers/ace/report.h tools/cygwin/report.h > /dev/null ; then x=1; fi; \
	if diff -q compilers/ace/report_xdr.c tools/cygwin/report_xdr.c > /dev/null ; then x=1; fi; \
	if test "$x" = "1"; then \
		echo "Need to update"; \
		${CP} compilers/fcompile/form_x.h tools/cygwin; \
		${CP} compilers/fcompile/form_x_xdr.c tools/cygwin; \
		${CP} compilers/menus/menu_x.h tools/cygwin; \
		${CP} compilers/menus/menu_x_xdr.c tools/cygwin; \
		${CP} compilers/ace/report.h tools/cygwin; \
		${CP} compilers/ace/report_xdr.c tools/cygwin; \
	else \
		echo "All no_rpcgen files up-to-date"; \
	fi
else
	@echo "Skipping refresh.norpcgen - USE_RPCGEN=0."
endif
else
	@echo "Skipping refresh.norpcgen - Not on CygWin"
endif

####################
#Since we are using xgen now, this should be obsolete
refresh.norpclib:
ifeq "${CONFIRM}" "IknowWhatImDoing"
ifneq "${COMSPEC}" ""
	${CP} ${RPC_INCL_DIR}/auth_unix.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/auth.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/pmap_clnt.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/clnt.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/netdb.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/pmap_prot.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/pmap_rmt.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/rpc.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/rpc_msg.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/svc.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/svc_auth.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/types.h tools/no_rpc/cygwin/rpc
	${CP} ${RPC_INCL_DIR}/xdr.h tools/no_rpc/cygwin/rpc
else
	@echo "Skipping refresh.norpclib - Not on CygWin."
endif
else
	@echo "Skipping refresh.norpclib - CONFIRM != IknowWhatImDoing"
endif

####################
#FIXME: add no_perl here
refresh.perl:
	@echo "FIXME: not storing Perl created files"

## ------------------------------------------------------------------
##                       Maintainance utility targets
## ------------------------------------------------------------------

#Find c files with same names
find.dup.c.files:
ifdef COMSPEC
	find . -name "*.c" -exec basename {} \; | /bin/sort | uniq -c | grep -v " 1"
else
	find . -name "*.c" -exec basename {} \; | sort | uniq -c | grep -v " 1"
endif
#compile examples and run them
test.install:
	(cd $(INSTALL_DIR)/tools/test; ${MAKE}; ./hello; cd gui; ${MAKE}; ./hello_gui)

#Clean and rebuild everything, install, compile examples and run them
test.full:
	${MAKE} clean.all
	./configure
	${MAKE}
	${MAKE} install
	${MAKE} test.install


#Create Makefile.in files from Makefile.am
#automake:
#	automake --add-missing


libtool: ${LIBTOOL_DEPS}
#copy:
#config.guess   config.sub   ltconfig   ltmain.in
#from local libtool directory:
#	cp /usr/local/share/libtool/config.* /usr/local/share/libtool/lt* etc/config
#	cp /usr/local/share/libtool/ltconfig /usr/local/share/libtool/ltmain.in etc/config
#old 1.3	(cd etc/config; ./ltconfig ./ltmain.sh)
#old 1.3	${CP} etc/config/libtool .
#for libtool 1.4:
	$(SH) ./config.status --recheck


## ------------------------------------------------------------------
##                       Make and build proccess Debugging
## ------------------------------------------------------------------

savesettings: OUT = $(PLATFORMINFO)
savesettings: newfile settings.common

#no stdout on CygWin :-(
#settings: OUT="/dev/stdout"
settings: OUT=  $(PLATFORMINFO)
settings: blankfile settings.common
	@cat $(PLATFORMINFO)

blankfile:
	@echo "" > ${OUT}

newfile:
	@echo "This file contains version info of compile platform" > ${OUT}

settings.common:
#	@echo "OUT = " ${OUT}
	@echo "+--------------------------------------------------------------------+" >> ${OUT}
	@echo "| make invoked with flags : ${MAKEFLAGS}" >> ${OUT}
	@echo "| make invoked in : ${PWD}" >> ${OUT}
	@echo "| Reading from root makefile variables:" >> ${OUT}
#	@echo -------------- Optional libraries ---------------- >> ${OUT}
#	@echo "GTKBUILD        = ${GTKBUILD}" >> ${OUT}
#	@echo "PDFBUILD        = ${PDFBUILD}" >> ${OUT}
#	@echo "JABBERBUILD     = ${JABBERBUILD}" >> ${OUT}
#	@echo -------------- SQL settings --------------------- >> ${OUT}
#	@echo "HAVE_UNIXODBC   = ${HAVE_UNIXODBC}" >> ${OUT}
#	@echo "HAVE_IODBC      = ${HAVE_IODBC}" >> ${OUT}
#	@echo "ODBC_LINK       = ${ODBC_LINK}" >> ${OUT}
#	@echo "ODBC            = ${ODBC}" >> ${OUT}
#	@echo "ODBCLIBDIR      = ${ODBCLIBDIR}" >> ${OUT}
#	@echo "ODBC_LIB_DIR    = ${ODBC_LIB_DIR}" >> ${OUT}
#	@echo "ODBC_LIB_NAME   = ${ODBC_LIB_NAME}" >> ${OUT}
	@echo "+--------------------- C Compiler settings --------------------------+" >> ${OUT}
	@echo "| CFLAGS          = ${CFLAGS}" >> ${OUT}
	@echo "| LD_LIBRARY_PATH = ${LD_LIBRARY_PATH}" >> ${OUT}
	@echo "+--------------------------------------------------------------------+" >> ${OUT}
	@echo "| COMPILEDATE=$(COMPILEDATE) AUBITVERSION=$(AUBITVERSION) AUBITBUILD=$(AUBITBUILD)" >> ${OUT}
	@echo "| AUBITDIR=${AUBITDIR} OS=$(TARGET) TARGET_OS=${TARGET_OS}" >> ${OUT}
	@echo "| CONFIGURE_COMMAND = ${CONFIGURE_COMMAND}" >> ${OUT}
	@echo "+--------------------------------------------------------------------+" >> ${OUT}


#For debugging of build system
show:
	@echo "GCC_MINGW=${GCC_MINGW}"
	@echo "GCC_VER=${GCC_VER}"
	@echo "GCC_NEW_STYLE=${GCC_NEW_STYLE}"
	@echo "GCC_NO_rdynamic=${GCC_NO_rdynamic}"
	@echo "GCC_NO_PIC=${GCC_NO_PIC}"
	@echo "GCC_NO_native-struct=${GCC_NO_native-struct}"
	@echo "AUBITDIR=${AUBITDIR}"
	@echo "CWARN=${CWARN}"
	@echo "WIN_PATH=${WIN_PATH}"
	@echo "C_IFLAGS=${C_IFLAGS}"
	@echo "CFLAGS=${CFLAGS}"
	@echo "TARGET_OS=${TARGET_OS}"
	@echo "YYDEBUG=${YYDEBUG}"
	@echo "C_DFLAGS=${C_DFLAGS}"
	@echo "INSTALL_DIR=${INSTALL_DIR}"
	@echo "PREFIX=${PREFIX}"
	@echo "AUBITNAME=${AUBITNAME}"
	@echo "CYG_AUBITDIR=${CYG_AUBITDIR}"
	@echo "enable_minimal=${enable_minimal}"
	@echo "CONFIGURE_COMMAND=${CONFIGURE_COMMAND}"
	@echo "BIN_EXE=${BIN_EXE}"
	@echo "COMP_EXE=${COMP_EXE}"
	@echo "AMAKE_BIN_EXE=${AMAKE_BIN_EXE}"
	@echo "RUNTIME_EXE=${RUNTIME_EXE}"
	@echo "BIN_EXE_NOT_4AE=$(BIN_EXE_NOT_4AE)"
	@echo "BIN_EXE_4AE=$(BIN_EXE_4AE)"
	@echo "A4GL_LEXTYPE=${A4GL_LEXTYPE}"
	@echo "A4GL_LEXTYPE in aubit-config=`aubit-config A4GL_LEXTYPE`"
	@echo "A4GL_LEXDIALECT=${A4GL_LEXDIALECT}"
	@echo "A4GL_LEXDIALECT in aubit-config=`aubit-config A4GL_LEXDIALECT`"
	@echo "FGLPC_SETTINGS_DEST=${FGLPC_SETTINGS_DEST}"
	@echo "FGLPC_SETTINGS_PATH=${FGLPC_SETTINGS_PATH}"
	@echo "LIBLOGICAL_BUILD=${LIBLOGICAL_BUILD}"

show.windows:
	@echo "MSYS_SH=${MSYS_SH}"
	@echo "MSYS_CONF=${MSYS_CONF}"
	@echo "MSYS_ROOTDIR=${MSYS_ROOTDIR}"
	@echo "MSYS_VERSION=${MSYS_VERSION}"
	@echo "MINGW_ROOTDIR=${MINGW_ROOTDIR}"
	@echo "MINGW_VERSION=${MINGW_VERSION}"
	
show.platform: OUT="/tmp/showplatform"
show.platform: platform.common
	cat /tmp/showplatform

platform: OUT = $(PLATFORMINFO)
platform: savesettings platform.common
	@${CP} $(OUT) $(INSTALL_DIR)
	@${CP} $(OUT) ${PLATFORMINFOFULL}
	@echo "platform: See result in ${OUT}"
	@echo "Also copied to $(INSTALL_DIR)/$(OUT) and ${PLATFORMINFOFULL}"


platform.common:
#	@echo OUT = $(OUT)
	@echo "----- Compile date: ---------" >> $(OUT)
	@date >> $(OUT)
	@echo "----- Compile host  ---------" >> $(OUT)
	@uname -a >> $(OUT)
	@${GTKCONFIGTEXT}  >> $(OUT)
	@${GTKCONFIGCMD} >> $(OUT)
	@echo "----- ${CC} -v ---------" >> $(OUT)
	@${CC} -v  >> $(OUT) 2>&1
	@if [ -f "bin/4glc" ]; then \
		echo "----- all shared libraries used by 4glc ---------" >> $(OUT) ; \
		ls -al bin/4glc  >> $(OUT) ; \
		${LDDCMD} bin/4glc${EXE} >> $(OUT) ; \
    fi
	@if [ -f "tools/test/test_build" ]; then \
		echo "----- all shared libraries used by compiled 4gl program ---------" >> $(OUT) ; \
		ls -al tools/test/test_build  >> $(OUT) ; \
		${LDDCMD} tools/test/test_build${EXE}  >> $(OUT) ; \
    fi
	@echo "-------------------- EOF -----------------------" >> $(OUT)

#FIXME: info needed for binary disrto: kernel version, ODBC lib version, PDF version,...


settings.rc:
	@echo
	@echo "A1 [${AUBITETC}/aubitrc]       =${A1}"
	@echo "A2 [${AUBITDIR}/etc/aubitrc]   =${A2}"
	@echo "A3 [../etc/aubitrc]            =${A3}"
	@echo "A4 [etc/aubitrc]               =${A4}"
	@echo "A5 [~/.aubit4gl/aubitrc]       =${A5}"
	@echo "A6 [./.aubitrc]                =${A6}"
	@echo "A7 ['$A4GL_INIFILE' ]            =${A7}"
	@echo


## ------------------------------------------------------------------
##         Static code error and warning checking (Splint)
## ------------------------------------------------------------------

splint: lclint
lclint:
	@echo "Cleaning old $(LCLINT_GLOBAL_LOG)..."
	@(echo " " > $(LCLINT_GLOBAL_LOG))
	$(MAKE) -C lib/libaubit4gl splint
	$(MAKE) -C compilers/4glc splint
	$(MAKE) -C compilers/fcompile splint
	$(MAKE) -C compilers/menus splint
	$(MAKE) -C compilers/helpcompile splint
	@echo "See <module_dir>$(LCLINT_GLOBAL_LOG) for cumulative results of all modules tested"
	@echo "See ./$(LCLINTLOG) in each module directory tested"
	@echo "Tested, in this order:"
	@echo "1: lib/libaubit4gl"
	@echo "2: compilers/4glc"
	@echo "3: compilers/fcompile"
	@echo "4: compilers/menus"
	@echo "5: compilers/helpcompile"
	@echo "All SPLint warnings: "
	@echo "                          Reported  Suppressed"
	@echo "`grep "^Total" lclint.log`"


#Show what preprocessor symbols GCC defines
gcc_symbols:
	gcc -E -dM - </dev/null

#######################
#Run full set of tests
#This target is invoked from aubitbuild.sh
test.build:
#run_tests script will determine what is available for testing based on
#available libraries in lib
#	-cd tools/test/build_tests; ${SH} run_tests -alltests
#	@echo "NOTE: build tests are no longer in Aubit 4GL compiler source code tree" 
	-cd ${AUBIT_TEST_DIR}; unset A4GL_UI; ${SH} run_tests -cert -silent -verbose-results -cron -range 1 20

	
########################
# Create source code metrics and statistical info
DIRS_TOP=common compilers lib tools glade
DIRS_COMPILERS=4glc ace fcompile helpcompile menus pcode sql xgen
DIRS_LIB=extra_libs libaubit4gl libesql libexdata libform libhelp liblex \
		liblogical libmenu libmsg libpacker libpdf librpc libsql libsqlparse \
		libui 
DIRS_TOOLS=4glpc afinderr asql aupscol configuration convertsql

metrics: metrics.all metrics.top metrics.compilers metrics.lib metrics.tools metrics.indexpage

metrics.all:
	rm -rf ./docs/cccc
	mkdir -p ./docs/cccc
	find . -name "*.c" | cccc --outdir=./docs/cccc/all -
metrics.top: 
	$(foreach dir,${DIRS_TOP},${shell find ./${dir} -name "*.c" | cccc --outdir=./docs/cccc/${dir} -})
metrics.compilers: 
	$(foreach dir,${DIRS_COMPILERS},${shell find ./compilers/${dir} -name "*.c" | cccc --outdir=./docs/cccc/compilers/${dir} -})
metrics.lib: 
	$(foreach dir,${DIRS_LIB},${shell find ./lib/${dir} -name "*.c" | cccc --outdir=./docs/cccc/lib/${dir} -})
metrics.tools: 
	$(foreach dir,${DIRS_TOOLS},${shell find ./tools/${dir} -name "*.c" | cccc --outdir=./docs/cccc/tools/${dir} -})
	
OUTFILE=./docs/cccc/index.html
metrics.indexpage:
	@echo "<html><head><title>All sources</title></head><body>" > ${OUTFILE}
	@echo "<h4 align='center'><font size="5">Aubit 4GL compiler</font></h4>" >> ${OUTFILE}
	@echo "<h4 align='center'>measurements of source code related metrics</h4>" >> ${OUTFILE}
	@echo "<hr>" >> ${OUTFILE}
	@echo "<p><a href='all/cccc.html'>All sources</a></p><ul>" >> ${OUTFILE}
	@echo "  <li><a href='compilers/cccc.html'>compilers</a><ul>" >> ${OUTFILE}
	@echo "    <li><a href='compilers/4glc/cccc.html'>4glc</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='compilers/ace/cccc.html'>ace</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='compilers/fcompile/cccc.html'>fcompile</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='compilers/helpcompile/cccc.html'>helpcompile</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='compilers/menus/cccc.html'>menus</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='compilers/pcode/cccc.html'>pcode</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='compilers/sql/cccc.html'>sql</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='compilers/xgen/cccc.html'>xgen</a></li>" >> ${OUTFILE}
	@echo "  </ul>" >> ${OUTFILE}
	@echo "  </li>" >> ${OUTFILE}
	@echo "  <li><a href='lib/cccc.html'>lib</a><ul>" >> ${OUTFILE}
	@echo "    <li><a href='lib/extra_libs/cccc.html'>extra_libs</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libaubit4gl/cccc.html'>libaubit4gl</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libesql/cccc.html'>libesql</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libexdata/cccc.html'>libexdata</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libform/cccc.html'>libform</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libhelp/cccc.html'>libhelp</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/liblex/cccc.html'>liblex</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/liblogical/cccc.html'>liblogical</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libmenu/cccc.html'>libmenu</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libmsg/cccc.html'>libmsg</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libpacker/cccc.html'>libpacker</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libpdf/cccc.html'>libpdf</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/librpc/cccc.html'>librpc</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libsql/cccc.html'>libsql</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libsqlparse/cccc.html'>libsqlparse</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='lib/libui/cccc.html'>libui</a></li>" >> ${OUTFILE}
	@echo "  </ul>" >> ${OUTFILE}
	@echo "  </li>" >> ${OUTFILE}
	@echo "  <li><a href='tools/cccc.html'>tools</a><ul>" >> ${OUTFILE}
	@echo "    <li><a href='tools/4glpc/cccc.html'>4glpc</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='tools/afinderr/cccc.html'>afinderr</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='tools/asql/cccc.html'>asql</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='tools/aupscol/cccc.html'>aupscol</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='tools/configuration/cccc.html'>configuration</a></li>" >> ${OUTFILE}
	@echo "    <li><a href='tools/convertsql/cccc.html'>convertsql</a></li>" >> ${OUTFILE}
	@echo "  </ul>" >> ${OUTFILE}
	@echo "  </li>" >> ${OUTFILE}
	@echo "  <li><a href='glade/cccc.html'>glade</a></li>" >> ${OUTFILE}
	@echo "  <li><a href='common/cccc.html'>common</a></li>" >> ${OUTFILE}
	@echo "</ul>" >> ${OUTFILE}
	@echo "<hr>" >> ${OUTFILE}	
	@echo "Created with CCCC - http://cccc.sourceforge.net" >> ${OUTFILE}
	@echo "</body></html>" >> ${OUTFILE}
#TODO: add notes about generated code: lex/yacc, .ec, .4gl, dlmagic, etc...
#and note the difference when running on clean tree, or after aubit is compiled
	
## ---------------------------- EOF ----------------------------------

