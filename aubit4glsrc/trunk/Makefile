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
# $Id: Makefile,v 1.29 2006-10-14 08:25:29 afalout Exp $
#

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
.PHONY: all clean default log corecompile extra ide api.headers glade

###############################
#Things we compile by default
ALL					=settings api.headers corecompile libfile libstring

ifneq "${enable_minimal}" "yes" 
	ALL 			+=	liblogical glade aace pcode
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
	@echo "| PREFIX           =${PREFIX} (under ${AUBITNAME}) "
	@echo "| LIB_INSTALL_LINK =${LIB_INSTALL_LINK}"
	@echo "| BIN_INSTALL_LINK =${BIN_INSTALL_LINK}"
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
endif
	$(MAKE) -C help
	@echo Aubit 4gl compiler core is now compiled

aace:
	$(MAKE) -C compilers/ace
	
pcode:
#FIXME: can't make pcode without Bison
ifneq "${BISON}" "no"
	$(MAKE) -C compilers/pcode
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
	-mv lib/swig ?akefile /tmp/swig-makefile
#Must allow it to fail, as we may or may not have makefile allready created there
	-${MAKE} -C lib/swig clean
	-mv /tmp/swig-makefile lib/swig/Makefile
	

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
	lib/liblex/lex_c/Makefile lib/liblex/lex_perl/Makefile
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
	aubit4gl.lsm rpmbuild.log .\#*
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

install: install.core install.Makefile-common install.setmod install.example \
		install.manual install.config \
		install.links install.aubitrc install.libs.links \
		install.makefile-install install.libs.conf install.registry
ifneq "${AUBITRCFILEEXISTS}" ""
	@echo " "
	@echo "WARNING: Configuration file aubitrc exists in ${AUBITETC}/aubitrc"
	@echo "====================== WILL NOT OVERWRITE ======================"
	@echo "use 'make install.aubitrc aubitrc=new' if you want to do that "
	@echo "Automatically created aubitrc placed in /tmp/aubitrc.tmp"
	@echo " "
endif
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
#Register p-code runner with kernel (Linux with binfmt_misc suppoert in kernel ONLY)
pcode.register: /proc/sys/fs/binfmt_misc/register $(INSTALL_DIR)/compilers/pcode/runner_fgl_wrapper
#TODO: remove compilers/pcode/register
#On linux - if you have binfmt_misc in the kernel (or loaded as a module )
#you can get the kernel to run a program to run a program. This is normally
#used for running java or C# code, but we can use it for running aubit pcode
#bin_fmt registration.
ifndef COMSPEC
#Load binfmt_misc module in runningn kernel:
#	su -c "modprobe binfmt_misc" 
#Set (NOTE: this is NOT a file on ordinary filesystem, but on the vistual kernel fs (/proc):
	su -c "echo \":A4GL:M::\xa4\xfc\x23\x45::$(INSTALL_DIR)/compilers/pcode/runner_fgl_wrapper:\" > $^"
#Check:
	cat /proc/sys/fs/binfmt_misc/status
	echo " "
	cat /proc/sys/fs/binfmt_misc/A4GL
#TODO - how do we make registration permanent between reboots, and how I load binfmt_misc module 
#automatically on boot?
	
endif

$(INSTALL_DIR)/compilers/pcode/runner_fgl_wrapper:
	@echo "YOU NEED TO INSTALL AUBIT COMPILER FIRST! (make install)"
	@exit 1


########################
#Check that Winsows setup  installed everything we expect, and not things (FULL LOOP)
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
install.Makefile-common:
	@echo "#AUBIT_BIN_INSTALL is needed for make files and 4glpc to know they are not in Aubit compiler source code tree:" > /tmp/Makefile-common
	@echo "AUBIT_BIN_INSTALL=1" >> /tmp/Makefile-common
	@cat $(INCL_DIR)/Makefile-common >> /tmp/Makefile-common
	@mv /tmp/Makefile-common $(INCL_DEST)

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

tar: clean.all
#COMPILE_DATE=20-01-2002
#TARGET=i586-pc-linux-gnu
	${RM} ${SOURCETARBASENAME}
ifndef COMSPEC
	tar -cvzf ${SOURCETARBASENAME} *
	@echo "Aubit tarball created"
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


tar.bin:
	${RM} ${BINTARBASENAME}
	tar -cvzf ${BINTARBASENAME} *
	@echo "Aubit binary tarball created (${BINTARBASENAME})"

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


#this will make rpm form autoconf-ed etc/aubit-rpm.conf
rpm:
ifneq "${RPM}" ""
	./config.status --file etc/aubit-rpm.spec
	${MAKE} rpm.build
else
	@echo "RPM tools where not detected on your system."
endif

rpm.build: RPMCONFFILE:=${AUBITDIR}/etc/aubit-rpm.spec
rpm.build: SRCTMP:=${RPMBUILDROOT}/SOURCES/${NAMEVERBLD}.${ARCHEXT}
rpm.build: rpm.check.all
#RPM insists to have source code in ${RPMBUILDROOT}/SOURCES/ before it will
#build it, and only then make src and bin RPM
	@echo "+--------------------------------------------------------------------+"
	@echo "| Building RPM packages...                                           |"
	@echo "+--------------------------------------------------------------------+"
ifeq "${RPM}" "new"
	${RM} ${SRCTMP}
	${RM} /tmp/${NAMEVERBLD}/${SOURCETARBASENAME}
	rm -rf /usr/src/redhat/BUILD/aubit4gl*
#	rm -rf /usr/src/redhat/SOURCES/${SOURCETARBASENAME}
	rm -rf /usr/src/redhat/SOURCES/aubit4gl*
	@echo "NOTE: if version numbers changed, run ./configure first!"
	./config.status --file etc/aubit-rpm.spec
	./config.status --file Makefile
	./config.status --file incl/Makefile-common
endif
#Since aubitbuild.sh ups the build number before building nightly builds,
#make rpm will need to make a new ${SRCTMP} tarball, and to do this, it 
#willneed to clean.all - leaving a machine without compiled Aubit :-(
#and RPM will deinstall installed Aubit as part of build process leaving 
#machine without installed Aubit :-((((
	@if [ ! -f ${SRCTMP} ]; then \
		echo "(1) No ${SRCTMP}, making it..."; \
		if [ ! -f /tmp/${NAMEVERBLD}/${SOURCETARBASENAME} ]; then \
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
	rpm -ba ${RPMCONFFILE} > rpmbuild.log 2>&1
	@echo "+--------------------------------------------------------------------+"
	@echo "| Created files:                                                     |"
	@echo "| ${RPMBUILDROOT}/SRPMS/${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}-1.src.rpm"
	@echo "| ${RPMBUILDROOT}/RPMS/i586/${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}-1.i586.rpm"
	@echo "| 'make rpm' successfull, see rpmbuild.log for details               |"
	@echo "+--------------------------------------------------------------------+"

rpm.check.all: RPMCONFFILE:=${AUBITDIR}/etc/aubit-rpm.spec
rpm.check.all: SRCTMP:=${RPMBUILDROOT}/SOURCES/${NAMEVERBLD}.${ARCHEXT}
rpm.check.all: rpm.check.deps
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
	@if [ ! -f ${SRCTMP} ]; then touch ${SRCTMP}; touch /tmp/fakesrctmp; fi
	rpm -bl ${RPMCONFFILE}
	@if [ -f /tmp/fakesrctmp ]; then rm -f ${SRCTMP}; rm -f /tmp/fakesrctmp; fi
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM config file (${RPMCONFFILE}) tested OK"
	@echo "+--------------------------------------------------------------------+"
	
###################
rpm.check.deps:
#Not sure this makes any senese on Linux - since I did not find a way to disable
#ldconfing cache or DT_RPATH/DT_RUNPATH, it will esentially just tell us which
#libraries we used to link Aubit stuff are not in ld.so.conf, since only thing I can 
#disable is LD_LIBRARY_PATH. Bastard is even smart enough to find libraries I 
#intentionally renamed...
	export MAKINGAUBIT=0; export IGNORE_MISSING_DEPS=1; ${SH} bin/4glpc.obsolete -deps

###################	
#Install created binary RPM and check it against binary installation 
#created with 'make install' for consistency:
rpm.install: RPM_FILE=${RPMBUILDROOT}/RPMS/i586/${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}-1.i586.rpm
#rpm.install: RPM_FILE=${RPMBUILDROOT}/RPMS/i586/${AUBITNAME}-${AUBITVERSION}.9-1.i586.rpm
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
	rpm --install --noscripts --prefix /tmp/aubit4gl-rpminstall ${RPM_FILE}
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM installed to /tmp/aubit4gl-rpminstall"
	@echo "+--------------------------------------------------------------------+"

#######################
rpm.deinstall:
	-rpm --erase --noscripts aubit4gl
#Should be gone, but just in case:	
	rm -rf /tmp/aubit4gl-rpminstall	
	@echo "+--------------------------------------------------------------------+"
	@echo "| aubit4gl RPM deinstalled"
	@echo "+--------------------------------------------------------------------+"

#######################
rpm.test.files:
	export MAKINGAUBIT=0; export INSTALLDIR="/tmp/aubit4gl-rpminstall/aubit4gl" ;${SH} bin/4glpc.obsolete -chk-install
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM files compare test finished"
	@echo "+--------------------------------------------------------------------+"

#######################
#The main target for testing of RPM package consitency; also invoked from
#aubitbuild.sh as part of automatic nightly builds
rpm.check: rpm.deinstall rpm.install rpm.test.files rpm.deinstall
	@echo "+--------------------------------------------------------------------+"
	@echo "| RPM test finished"
	@echo "+--------------------------------------------------------------------+"
	
########################	
#Show info about the RPM package
#rpm.info: RPM_FILE=${RPMBUILDROOT}/RPMS/i586/${AUBITNAME}-${AUBITVERSION}.${AUBITBUILD}-1.i586.rpm
rpm.info: RPM_FILE=${RPMBUILDROOT}/RPMS/i586/${AUBITNAME}-${AUBITVERSION}.9-1.i586.rpm
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

######################
#automatically create .spec file for RPM build:
etc/aubit-auto.spec: aubit4gl.lsm
	${MAKE} ${MKNAME} -n install | autospec -i -d -n ${NAMEVERBLD} -g Development/Languages > ${AUBITDIR}/etc/aubit-auto.spec

build.diff.patch:
	diff -uNr ${dirname}.orig ${dirname} > ${dirname}.patch
#Please, use cvs diff -u3p.

#Create Linux Software Map (.lsm) used by autospec, see http://www.execpc.com/lsm/
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
	@echo "  PREFIX= where to install binaries, default is $PREFIX"
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
		4glc/mk_states_1.h 4glc/mk_states.h 4glc/mk_states.c \
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

