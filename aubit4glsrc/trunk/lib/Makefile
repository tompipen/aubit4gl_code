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
# $Id: Makefile,v 1.11 2006-10-10 05:45:45 afalout Exp $
#

ROOT    =..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Source files
## ==================================================================

#This make file does not have it's own targets, it only invokes other
#make files

## ==================================================================
##                              Options
## ==================================================================

4GLC    =${ROOT}/bin/4glc
4GLPC    =${ROOT}/bin/4glpc

#target names are maintained in configure.in
ALL_LIBS=${LIB_DEFAULT} ${LIB_OPTIONAL}
ALL 	= pluginsdir aubit-config ${ALL_LIBS}

ALL_H   =$(wildcard ${ROOT}/incl/*.h)

LIBAUBIT4GL_PATH    =libaubit4gl
LIBSQLODBC_PATH     =libsql/odbc
LIBMENUXDR_PATH		=libmenu/menu_xdr
LIBMENUNOMENU_PATH	=libmenu/menu_nomenu
LIBMENUGENERIC_PATH	=libmenu/menu_generic
LIBPACKERPACKED_PATH=libpacker/packed
LIBPACKERMEMPACKED_PATH=libpacker/mempacked
LIBPACKERPERL_PATH  =libpacker/perl
LIBPACKERXDR_PATH   =libpacker/xdr
LIBPACKERXML_PATH   =libpacker/xml
LIBPACKERGZPACKED_PATH   =libpacker/gzpacked
#LIBLEXC_PATH   		=liblex/lex_c
LIBLEXEC_PATH  		=liblex/lex_esqlc
LIBEXREPORTPDF_PATH =libpdf
LIBFILE_PATH		=extra_libs/file
LIBSTRING_PATH		=extra_libs/string
LIBCHANNEL_PATH		=extra_libs/channel
LIBESQLCHELPER_PATH	=libesql
LIBHTML_PATH        =${ROOT}/tools/html
LIBMEMCACHE_PATH	=extra_libs/memcached
LIBSQLESQL_PATH     =libsql/esqlc
LIBUIHL_PATH       	=libui/ui_highlevel
LIBUICURSES_PATH	=libui/ui_curses
LIBUICONSOLE_PATH	=libui/ui_console
LIBUIGLADE_PATH		=libui/ui_glade
LIBUIGLADELIB_PATH	=libui/ui_glade/glade_lib
LIBFORMNOFORM_PATH	=libform/noform
LIBFORMXDR_PATH		=libform/form_xdr
LIBFORMGENERIC_PATH	=libform/form_generic
LIBSQLNOSQL_PATH	=libsql/nosql
LIBSQLPG_PATH		=libsql/postgresql
LIBRPCSUNRPC_PATH	=librpc/sun_rpc
LIBRPCNORPC_PATH	=librpc/no_rpc
LIBRPCXMLRPC_PATH	=librpc/xml_rpc
LIBEXDATA_PATH		=libexdata
LIBESQL_PATH		=libesql
LIBDATA_PATH		=${ROOT}/common/dataio
LIBHELP_STD_PATH	=libhelp
LIBMSGNATIVE_PATH	=libmsg/msg_native
LIBIMJABBER_PATH	=${ROOT}/tools/jabber $@
LOADMAP_PATH		=${ROOT}/tools/loadmap
AUBITCONFIG_PATH	=resource
FILESCHEMA_PATH     =libsql/schema_in_file
MYSQL_PATH     		=libsql/mysql
INGRES_PATH			=libsql/ingres
LIBPOP_PATH     	=extra_libs/pop
LIBSMTP_PATH     	=extra_libs/smtp
LIBPCRE_PATH     	=extra_libs/pcre
LIBSXML_PATH     	=extra_libs/sxml

#Specify dependencies for libraries, so they get rebuilt if dependencies change:
#FIXME: do this for all libraries in this make file
LIBAUBIT4GL_DEPS	=$(wildcard ${LIBAUBIT4GL_PATH}/*.c) $(wildcard ${LIBAUBIT4GL_PATH}/*.h) \
					$(wildcard ${LIBAUBIT4GL_PATH}/*.spec) $(wildcard ${LIBAUBIT4GL_PATH}/Makefile) \
                    ${AUBITCONFIG_PATH}/resource.c ${ALL_H}
AUBITCONFIG_DEPS	=$(wildcard ${AUBITCONFIG_PATH}/*.c) $(wildcard ${AUBITCONFIG_PATH}/Makefile) ${ALL_H}
LIBDATA_DEPS		=$(wildcard ${LIBRPCSUNRPC_PATH}/*.x) $(wildcard ${LIBRPCSUNRPC_PATH}/Makefile) ${ALL_H}
LIBMSGNATIVE_DEPS	=$(wildcard ${LIBMSGNATIVE_PATH}/*.c) $(wildcard ${LIBMSGNATIVE_PATH}/*.h) \
					$(wildcard ${LIBMSGNATIVE_PATH}/Makefile) ${ALL_H}
LIBIMJABBER_DEPS	=$(wildcard ${LIBIMJABBER_PATH}/*.c) $(wildcard ${LIBIMJABBER_PATH}/*.h) \
					$(wildcard ${LIBIMJABBER_PATH}/Makefile) $(wildcard ${LIBIMJABBER_PATH}/*.4gl) ${ALL_H}
LOADMAP_DEPS		=$(wildcard ${LOADMAP_PATH}/Makefile) $(wildcard ${LOADMAP_PATH}/*.4gl) ${ALL_H}
LIBRPCSUNRPC_DEPS	=$(wildcard ${LIBRPCSUNRPC_PATH}/*.c) $(wildcard ${LIBRPCSUNRPC_PATH}/*.h) \
					$(wildcard ${LIBRPCSUNRPC_PATH}/Makefile) ${ALL_H}
LIBRPCNORPC_DEPS	=$(wildcard ${LIBRPCNORPC_PATH}/*.c) $(wildcard ${LIBRPCNORPC_PATH}/*.h) \
					$(wildcard ${LIBRPCNORPC_PATH}/Makefile) ${ALL_H}
LIBRPCXMLRPC_DEPS	=$(wildcard ${LIBRPCXMLRPC_PATH}/*.c) $(wildcard ${LIBRPCXMLRPC_PATH}/*.h) \
					$(wildcard ${LIBRPCXMLRPC_PATH}/Makefile) ${ALL_H}
LIBEXDATA_DEPS		=$(wildcard ${LIBEXDATA_PATH}/*.c) $(wildcard ${LIBEXDATA_PATH}/*.h) \
					$(wildcard ${LIBEXDATA_PATH}/Makefile) ${ALL_H}
LIBESQL_DEPS		=$(wildcard ${LIBESQL_PATH}/*.ec) $(wildcard ${LIBESQL_PATH}/*.h) \
					$(wildcard ${LIBESQL_PATH}/Makefile) ${ALL_H}
LIBSQLNOSQL_DEPS	=$(wildcard ${LIBSQLNOSQL_PATH}/*.c) $(wildcard ${LIBSQLNOSQL_PATH}/*.h) \
					$(wildcard ${LIBSQLNOSQL_PATH}/Makefile) ${ALL_H}
FILESCHEMA_DEPS     =$(wildcard ${FILESCHEMA_PATH}/*.c) \
					$(wildcard ${FILESCHEMA_PATH}/Makefile) ${ALL_H}
MYSQL_DEPS     		=$(wildcard ${MYSQL_PATH}/*.c) \
					$(wildcard ${MYSQL_PATH}/Makefile) ${ALL_H}
INGRES_DEPS    		=$(wildcard ${INGRES_PATH}/*.ec) \
					$(wildcard ${INGRES_PATH}/Makefile) $(wildcard ${INGRES_PATH}/makeit) ${ALL_H}
LIBHELP_STD_DEPS	=$(wildcard ${LIBHELP_STD_PATH}/*.per) $(wildcard ${LIBHELP_STD_PATH}/*.4gl) \
					$(wildcard ${LIBHELP_STD_PATH}/Makefile) ${ALL_H}
LIBSQLPG_DEPS		=$(wildcard ${LIBSQLPG_PATH}/*.cpp) $(wildcard ${LIBSQLPG_PATH}/*.h) \
					$(wildcard ${LIBSQLPG_PATH}/*.c) $(wildcard ${LIBSQLPG_PATH}/Makefile) ${ALL_H}
LIBSQLODBC_DEPS     =$(wildcard ${LIBSQLODBC_PATH}/*.c) $(wildcard ${LIBSQLODBC_PATH}/*.h) \
					$(wildcard ${LIBSQLODBC_PATH}/Makefile) ${ALL_H}
LIBMENUXDR_DEPS		=$(wildcard ${LIBMENUXDR_PATH}/*.c) $(wildcard ${LIBMENUXDR_PATH}/*.h) \
					$(wildcard ${LIBMENUXDR_PATH}/Makefile) ${ALL_H}
LIBMENUNOMENU_DEPS	=$(wildcard ${LIBMENUNOMENU_PATH}/*.c) $(wildcard ${LIBMENUNOMENU_PATH}/*.h) \
					$(wildcard ${LIBMENUNOMENU_PATH}/Makefile) ${ALL_H}
LIBMENUGENERIC_DEPS	=$(wildcard ${LIBMENUGENERIC_PATH}/*.c) $(wildcard ${LIBMENUGENERIC_PATH}/*.h) \
					$(wildcard ${LIBMENUGENERIC_PATH}/Makefile) ${ALL_H}
LIBPACKERPACKED_DEPS=$(wildcard ${LIBPACKERPACKED_PATH}/*.c) $(wildcard ${LIBPACKERPACKED_PATH}/*.h) \
					$(wildcard ${LIBPACKERPACKED_PATH}/Makefile) ${ALL_H}

LIBPACKERMEMPACKED_DEPS=$(wildcard ${LIBPACKERMEMPACKED_PATH}/*.c) $(wildcard ${LIBPACKERMEMPACKED_PATH}/*.h) \
					$(wildcard ${LIBPACKERMEMPACKED_PATH}/Makefile) ${ALL_H}

LIBPACKERPERL_DEPS	=$(wildcard ${LIBPACKERPERL_PATH}/*.c) $(wildcard ${LIBPACKERPERL_PATH}/*.h) \
					$(wildcard ${LIBPACKERPERL_PATH}/Makefile) ${ALL_H}
LIBPACKERXDR_DEPS	=$(wildcard ${LIBPACKERXDR_PATH}/*.c) $(wildcard ${LIBPACKERXDR_PATH}/*.h) \
					$(wildcard ${LIBPACKERXDR_PATH}/Makefile) ${ALL_H}
LIBPACKERXML_DEPS	=$(wildcard ${LIBPACKERXML_PATH}/*.c) $(wildcard ${LIBPACKERXML_PATH}/*.h) \
					$(wildcard ${LIBPACKERXML_PATH}/Makefile) ${ALL_H}
LIBPACKERGZPACKED_DEPS	=$(wildcard ${LIBPACKERGZPACKED_PATH}/*.c) $(wildcard ${LIBPACKERGZPACKED_PATH}/*.h) \
					$(wildcard ${LIBPACKERGZPACKED_PATH}/Makefile) ${ALL_H}
#LIBLEXC_DEPS		=$(wildcard ${LIBLEXC_PATH}/*.c) $(wildcard ${LIBLEXC_PATH}/*.h) \
#					$(wildcard ${LIBLEXC_PATH}/Makefile) ${ALL_H}
LIBLEXEC_DEPS		=$(wildcard ${LIBLEXEC_PATH}/*.c) $(wildcard ${LIBLEXEC_PATH}/*.h) ${ROOT}/compilers/4glc/API_lex.h \
					$(wildcard ${LIBLEXEC_PATH}/Makefile) ${ALL_H}
LIBEXREPORTPDF_DEPS	=$(wildcard ${LIBEXREPORTPDF_PATH}/*.c) $(wildcard ${LIBEXREPORTPDF_PATH}/*.h) \
					$(wildcard ${LIBEXREPORTPDF_PATH}/Makefile) ${ALL_H}
LIBFILE_DEPS		=$(wildcard ${LIBFILE_PATH}/*.c) $(wildcard ${LIBFILE_PATH}/*.h) \
					$(wildcard ${LIBFILE_PATH}/Makefile) ${ALL_H}
LIBESQLCHELPER_DEPS	=$(wildcard ${LIBESQLCHELPER_PATH}/*.ec) $(wildcard ${LIBESQLCHELPER_PATH}/Makefile) ${ALL_H}
LIBSTRING_DEPS		=$(wildcard ${LIBSTRING_PATH}/*.c) $(wildcard ${LIBSTRING_PATH}/*.h) \
					$(wildcard ${LIBSTRING_PATH}/Makefile) ${ALL_H}
LIBCHANNEL_DEPS		=$(wildcard ${LIBCHANNEL_PATH}/*.4gl) \
					$(wildcard ${LIBCHANNEL_PATH}/Makefile) ${ALL_H}
LIBPOP_DEPS			=$(wildcard ${LIBPOP_PATH}/*.4gl) $(wildcard ${LIBPOP_PATH}/Makefile) ${ALL_H}
LIBSMTP_DEPS			=$(wildcard ${LIBSMTP_PATH}/*.4gl) $(wildcard ${LIBSMTP_PATH}/Makefile) ${ALL_H}
LIBPCRE_DEPS		=$(wildcard ${LIBPCRE_PATH}/*.4gl) $(wildcard ${LIBPCRE_PATH}/makefile) ${ALL_H}
LIBSXML_DEPS		=$(wildcard ${LIBPCRE_PATH}/*.4gl) $(wildcard ${LIBPCRE_PATH}/Makefile) ${ALL_H}
LIBHTML_DEPS		=$(wildcard ${LIBHTML_PATH}/*.c) $(wildcard ${LIBHTML_PATH}/*.h) \
					$(wildcard ${LIBHTML_PATH}/Makefile) ${ALL_H}
LIBMEMCACHE_DEPS	=$(wildcard ${LIBMEMCACHE_PATH}/*.c) $(wildcard ${LIBMEMCACHE_PATH}/*.h) \
					$(wildcard ${LIBMEMCACHE_PATH}/Makefile) $(wildcard ${LIBMEMCACHE_PATH}/*.4gl) ${ALL_H}
LIBSQLESQL_DEPS		=$(wildcard ${LIBSQLESQL_PATH}/*.ec) $(wildcard ${LIBSQLESQL_PATH}/*.h) \
					$(wildcard ${LIBSQLESQL_PATH}/Makefile) ${ALL_H}
LIBUIGTK_DEPS		=$(wildcard ${LIBUIGTK_PATH}/*.c) $(wildcard ${LIBUIGTK_PATH}/*.h) \
					$(wildcard ${LIBUIGTK_PATH}/Makefile) ${ALL_H}
LIBUIHL_DEPS		=$(wildcard ${LIBUIHL_PATH}/*.c) $(wildcard ${LIBUIHL_PATH}/*.h) \
					$(wildcard ${LIBUIHL_PATH}/lowlevel/*.c) \
					$(wildcard ${LIBUIHL_PATH}/lowlevel/*.h) \
					$(wildcard ${LIBUIHL_PATH}/Makefile) ${ALL_H}
LIBUICURSES_DEPS	=$(wildcard ${LIBUICURSES_PATH}/*.c) $(wildcard ${LIBUICURSES_PATH}/*.h) \
					$(wildcard ${LIBUICURSES_PATH}/Makefile) ${ALL_H}
LIBUICONSOLE_DEPS	=$(wildcard ${LIBUICONSOLE_PATH}/*.c) $(wildcard ${LIBUICONSOLE_PATH}/*.h) \
					$(wildcard ${LIBUICONSOLE_PATH}/Makefile) ${ALL_H}
LIBUIGLADE_DEPS		=$(wildcard ${LIBUIGLADE_PATH}/*.c) \
					$(wildcard ${LIBUIGLADE_PATH}/Makefile) ${ALL_H}
LIBUIGLADELIB_DEPS	=$(wildcard ${LIBUIGLADELIB_PATH}/*.4gl) \
					$(wildcard ${LIBUIGLADELIB_PATH}/makefile) ${ALL_H}
LIBFORMNOFORM_DEPS	=$(wildcard ${LIBFORMNOFORM_PATH}/*.c) $(wildcard ${LIBFORMNOFORM_PATH}/*.h) \
					$(wildcard ${LIBFORMNOFORM_PATH}/Makefile) ${ALL_H}
LIBFORMXDR_DEPS		=$(wildcard ${LIBFORMXDR_PATH}/*.c) $(wildcard ${LIBFORMXDR_PATH}/*.h) \
					$(wildcard ${LIBFORMXDR_PATH}/Makefile) ${ALL_H}
LIBFORMGENERIC_DEPS	=$(wildcard ${LIBFORMGENERIC_PATH}/*.c) $(wildcard ${LIBFORMGENERIC_PATH}/*.h) \
					$(wildcard ${LIBFORMGENERIC_PATH}/Makefile) ${ALL_H}

.PHONY=all note check clean

## ==================================================================
##                              Targets
## ==================================================================

all: note ${ALL} check
	@echo "Default targets (${ALL}) built successfully."

note:
	@echo "Building: ${ALL}"

check:
#Note: file names in ALL_LIBS allready include absolute path
#Note: some libraries built here are NOT plug-ins, and do NOT belong to ${PLUGINDIR}
#for examle A4GL_clint
	@for a in $(ALL_LIBS); do \
		if ! test -f $$a ; then  \
			if ! test -f ${LIBROOT}/`basename $$a` ; then \
				echo "======================================================================"; \
				echo "Build check failed : `basename $$a` does not exist as:"; \
				echo "$$a"; \
				echo "or"; \
				echo "${LIBROOT}/`basename $$a`"; \
				echo "Build of that library/plug-in failed. If you used 'make -k' to force"; \
				echo "make to continue despite the error, this is expected. Hovewer, absence of this"; \
				echo "library will prevent 'make install' from working. Either fix the issue that "; \
				echo "prevents it from compiling succesfully, or disable it in configuration (so build"; \
				echo "of this library will not be attempted) using './configure --without-xxx' option."; \
				echo "See './configure --help' for list of all flags and components that can be "; \
				echo "individually enabled or disabled. If 'configure' reported that it can build it,"; \
				echo "but build then failed, please report this to Aubit mailing list" ;\
				echo "======================================================================"; \
				exit 1; \
			fi; \
		fi; \
	done
	@echo "All library files built OK"

## ==================================================================
##                       Targets in sub-makefiles
## ==================================================================

libaubit4gl${SO_EXT_LINKABLE} : ${LIBAUBIT4GL_DEPS}
	${MAKE} -C ${LIBAUBIT4GL_PATH}

##############
#libLEX_

#libLEX_C${SO_EXT}: ${LIBLEXC_DEPS}
#	${MAKE} -C ${LIBLEXC_PATH}

#libLEX_PERL${SO_EXT}: ${LIBLEXPERL_DEPS}
#	${MAKE} -C ${LIBLEXPERL_PATH}

${PLUGINDIR}/libLEX_C${SO_EXT} ${PLUGINDIR}/libLEX_EC${SO_EXT}: ${LIBLEXEC_DEPS}
	${MAKE} -C ${LIBLEXEC_PATH}

##############
#libUI_

${PLUGINDIR}/libUI_TUI${SO_EXT}: ${LIBUICURSES_DEPS}
	$(MAKE) -C ${LIBUICURSES_PATH}

${PLUGINDIR}/libUI_CONSOLE${SO_EXT}: ${LIBUICONSOLE_DEPS}
	$(MAKE) -C ${LIBUICONSOLE_PATH}

#libUI_HLGENERIC${SO_EXT}: ${LIBUIHL_DEPS}
#	$(MAKE) -C ${LIBUIHL_PATH}

${PLUGINDIR}/libUI_HL_TUI${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

${PLUGINDIR}/libUI_HL_TUIw${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

${PLUGINDIR}/libUI_HL_TUIws${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

${PLUGINDIR}/libUI_HL_TUIN${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@
	
${PLUGINDIR}/libUI_HL_TUINs${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

${PLUGINDIR}/libUI_HL_TUIX${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@
	
${PLUGINDIR}/libUI_HL_GTK${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

${PLUGINDIR}/libA4GL_glade${SO_EXT}: ${LIBUIGLADELIB_DEPS}
	$(MAKE) -C ${LIBUIGLADELIB_PATH}

${PLUGINDIR}/libUI_GLADE${SO_EXT}: ${LIBUIGLADE_DEPS}
	$(MAKE) -C ${LIBUIGLADE_PATH}

##############
#libFORM_

${PLUGINDIR}/libFORM_NOFORM${SO_EXT} : ${LIBFORMNOFORM_DEPS}
	${MAKE} -C ${LIBFORMNOFORM_PATH}

${PLUGINDIR}/libFORM_XDR${SO_EXT} : ${LIBFORMXDR_DEPS}
	${MAKE} -C ${LIBFORMXDR_PATH}

${PLUGINDIR}/libFORM_GENERIC${SO_EXT}: ${LIBFORMGENERIC_DEPS}
	${MAKE} -C ${LIBFORMGENERIC_PATH}

##############
#libMENU_

${PLUGINDIR}/libMENU_NOMENU${SO_EXT} : ${LIBMENUNOMENU_DEPS}
	${MAKE} -C ${LIBMENUNOMENU_PATH}

${PLUGINDIR}/libMENU_GENERIC${SO_EXT} : ${LIBMENUGENERIC_DEPS}
	${MAKE} -C ${LIBMENUGENERIC_PATH}

${PLUGINDIR}/libMENU_XDR${SO_EXT} : ${LIBMENUXDR_DEPS}
	${MAKE} -C ${LIBMENUXDR_PATH}

##############
#libREPORT_

${PLUGINDIR}/libEXREPORT_PDF${SO_EXT}: ${LIBEXREPORTPDF_DEPS}
	${MAKE} -C ${LIBEXREPORTPDF_PATH}

${PLUGINDIR}/libEXREPORT_NOPDF${SO_EXT}: ${LIBEXREPORTPDF_DEPS}
	${MAKE} -C ${LIBEXREPORTPDF_PATH}

##############
#libPACKER_

${PLUGINDIR}/libPACKER_PACKED${SO_EXT}: ${LIBPACKERPACKED_DEPS}
	${MAKE} -C ${LIBPACKERPACKED_PATH}

${PLUGINDIR}/libPACKER_MEMPACKED${SO_EXT}: ${LIBPACKERMEMPACKED_DEPS}
	${MAKE} -C ${LIBPACKERMEMPACKED_PATH}

${PLUGINDIR}/libPACKER_PERL${SO_EXT}: ${LIBPACKERPERL_DEPS}
	${MAKE} -C ${LIBPACKERPERL_PATH}

${PLUGINDIR}/libPACKER_XDR${SO_EXT}: ${LIBPACKERXDR_DEPS}
	${MAKE} -C ${LIBPACKERXDR_PATH}

${PLUGINDIR}/libPACKER_XML${SO_EXT}: ${LIBPACKERXML_DEPS}
	${MAKE} -C ${LIBPACKERXML_PATH}
	
${PLUGINDIR}/libPACKER_GZPACKED${SO_EXT}: ${LIBPACKERGZPACKED_DEPS}
	${MAKE} -C ${LIBPACKERGZPACKED_PATH}
	
##############
#libSQL_ ESQL (native)

#Informix ESQL/C code SQL plug-in compiled with Informix esql ESQL/C compiler
${PLUGINDIR}/libSQL_esql${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@
#same thing, but different name for consistency:
${PLUGINDIR}/libSQL_esqlI${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#Informix ESQL/C code SQL plug-in compiled with Querix esqlc ESQL/C compiler
${PLUGINDIR}/libSQL_esqlQ${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#Informix ESQL/C code SQL plug-in compiled with SAP DB cpc ESQL/C compiler
${PLUGINDIR}/libSQL_esqlSAP${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#Informix ESQL/C code SQL plug-in compiled with PostgreSQL ecpg ESQL/C compiler
${PLUGINDIR}/libSQL_esqlPG${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#PostgreSQL esql plug-in based on 'simple' template (ecpg in non-Informix mode)
${PLUGINDIR}/libSQL_c_ecpg${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#Informix esql plug-in based on 'simple' template
${PLUGINDIR}/libSQL_c_esql${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@


##############
#libSQL_ C (native)

#Dummy plug-in good for testing or to disable SQL
${PLUGINDIR}/libSQL_nosql${SO_EXT}: ${LIBSQLNOSQL_DEPS}
	${MAKE} -C ${LIBSQLNOSQL_PATH}

#an simple PG plug-in with limited functionality (by Mike)
${PLUGINDIR}/libSQL_pg${SO_EXT}: ${LIBSQLPG_DEPS}
	${MAKE} -C ${LIBSQLPG_PATH}

#Sergio never finished this one...
${PLUGINDIR}/libSQL_pgDEVEL${SO_EXT}: ${LIBSQLPG_DEPS}
	${MAKE} -C ${LIBSQLPG_PATH}

#compile only plug-in for reading schema from file
${PLUGINDIR}/libSQL_FILESCHEMA${SO_EXT}: ${FILESCHEMA_DEPS}
	${MAKE} -C ${FILESCHEMA_PATH}

#Native MySQL plug-in
${PLUGINDIR}/libSQL_mysql${SO_EXT}: ${MYSQL_DEPS}
	${MAKE} -C ${MYSQL_PATH}

#Native Ingres plug-in
ingres: ${PLUGINDIR}/libSQL_ingres${SO_EXT}
${PLUGINDIR}/libSQL_ingres${SO_EXT}: ${INGRES_DEPS}
#	${MAKE} -C ${INGRES_PATH}
	cd ${INGRES_PATH}; chmod a+x ./makeit; ./makeit

##############
#libSQL_ (ODBC) plug-ins directly linked with ODBC driver

${PLUGINDIR}/libSQL_ifxodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} ifxodbc

${PLUGINDIR}/libSQL_pgodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} pgodbc

${PLUGINDIR}/libSQL_sapodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sapodbc

#Linked with SQLite ODBC driver, like any other directly linked ODBC plug-in
#requires SQLite ODBC driver and SQLite library on the system
${PLUGINDIR}/libSQL_sqliteodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sqliteodbc

#Compiled with SQLite ODBC driver source code in Aubit CVS
#requires SQLite library on the system
${PLUGINDIR}/libSQL_sqlite${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sqlite
#Same, but version 3
${PLUGINDIR}/libSQL_sqlite3${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sqlite3


#################################### SQLITE - static/shared build issues...
## The makefile needs to be fixed for these to work - so I'm commenting them out for now...
#Compiled with SQLite ODBC driver source code in Aubit CVS and statically
#linked with SQLite database engine ligrary (self sufficient - used mainly 
#for binary distributions to provide "always there" SQL functionality)
#libSQL_sqliteS${SO_EXT}: ${LIBSQLODBC_DEPS}
#	${MAKE} -C ${LIBSQLODBC_PATH} sqlite.static
#Same, but version 3
#libSQL_sqlite3S${SO_EXT}: ${LIBSQLODBC_DEPS}
#	${MAKE} -C ${LIBSQLODBC_PATH} sqlite3.static


${PLUGINDIR}/libSQL_sqlite3S${SO_EXT}: 
	@echo "Sqlite3S build temporarily suspended"

###################################


##############
#libSQL_ (ODBC) managers

${PLUGINDIR}/libSQL_iodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} iodbc

${PLUGINDIR}/libSQL_unixodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} unixodbc


${PLUGINDIR}/libSQL_odbc32.dll: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} odbc32

	
${PLUGINDIR}/libSQLPARSE_NONE${SO_EXT}:
	${MAKE} -C libsqlparse/none

${PLUGINDIR}/libSQLPARSE_INFORMIX${SO_EXT}:
	${MAKE} -C ../compilers/sql

##############
#libRPC_

${PLUGINDIR}/libRPC_XDR${SO_EXT}: ${LIBRPCSUNRPC_DEPS}
	${MAKE} -C ${LIBRPCSUNRPC_PATH}

${PLUGINDIR}/libRPC_NORPC${SO_EXT}: ${LIBRPCNORPC_DEPS}
	${MAKE} -C ${LIBRPCNORPC_PATH}

${PLUGINDIR}/libRPC_XMLRPC${SO_EXT}: ${LIBRPCXMLRPC_DEPS}
	${MAKE} -C ${LIBRPCXMLRPC_PATH}

#############
# libESQL

${PLUGINDIR}/libESQL_INFORMIX${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

${PLUGINDIR}/libESQL_POSTGRES${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

${PLUGINDIR}/libESQL_QUERIX${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

${PLUGINDIR}/libESQL_SAP${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

${PLUGINDIR}/libESQL_INGRES${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

	
##############
#libEXDTYPE_

${PLUGINDIR}/libEXDTYPE_mpz${SO_EXT}: ${LIBEXDATA_DEPS}
	${MAKE} -C ${LIBEXDATA_PATH} $@

##############
#libDATA_ & libXDRPACKER_

${PLUGINDIR}/libDATA_menu_list${SO_EXT} ${PLUGINDIR}/libDATA_struct_form${SO_EXT} ${PLUGINDIR}/libDATA_report${SO_EXT}\
${PLUGINDIR}/libXDRPACKER_struct_form${SO_EXT} ${PLUGINDIR}/libXDRPACKER_menu_list${SO_EXT} \
${PLUGINDIR}/libXDRPACKER_report${SO_EXT}: ${LIBDATA_DEPS}
	${MAKE} -C ${LIBDATA_PATH}


${ROOT}/compilers/4glc/API_lex.h: ${ROOT}/compilers/4glc/API_lex.spec
	${SH} ${ROOT}/lib/bin/dlmagic ${ROOT}/compilers/4glc/API_lex.spec -h > ${ROOT}/compilers/4glc/API_lex.h

###############
#Misc libs:
${PLUGINDIR}/libMSG_NATIVE${SO_EXT}: ${LIBMSGNATIVE_DEPS}
	${MAKE} -C ${LIBMSGNATIVE_PATH}

${PLUGINDIR}/libIM_JABBER${SO_EXT_LINKABLE}: ${LIBIMJABBER_DEPS}
	$(MAKE) -C ${LIBIMJABBER_PATH} $@

${PLUGINDIR}/libIM_JABBERs${SO_EXT_LINKABLE}: ${LIBIMJABBER_DEPS}
	$(MAKE) -C ${LIBIMJABBER_PATH} $@
	
cint: ${PLUGINDIR}/libA4GL_cint${SO_EXT_LINKABLE}
${PLUGINDIR}/libA4GL_cint${SO_EXT_LINKABLE}:
	cd ../cint; ${SH} make_cintlib


##############
#Libs that need 4glc
${PLUGINDIR}/libHELP_std${SO_EXT}: ${LIBHELP_STD_DEPS} ${4GLC} ${FCOMPILE} ${PLUGINDIR}/libPACKER_PACKED${SO_EXT} ${PLUGINDIR}/libUI_CONSOLE${SO_EXT} ${PLUGINDIR}/libFORM_GENERIC${SO_EXT}
	${MAKE} -C ${LIBHELP_STD_PATH}

${PLUGINDIR}/libA4GL_file${SO_EXT}: ${4GLC} ${LIBFILE_DEPS}
	$(MAKE) -C ${LIBFILE_PATH}

${PLUGINDIR}/libA4GL_string${SO_EXT}: ${4GLC} ${LIBSTRING_DEPS}
	$(MAKE) -C ${LIBSTRING_PATH}

${PLUGINDIR}/libchannel${SO_EXT}: ${4GLC} ${LIBCHANNEL_DEPS}
	$(MAKE) -C ${LIBCHANNEL_PATH}
	
${PLUGINDIR}/libA4GL_pop${SO_EXT}: ${4GLC} ${LIBPOP_DEPS}
	$(MAKE) -C ${LIBPOP_PATH}
	
${PLUGINDIR}/libfgl_smtp${SO_EXT}: ${4GLC} ${LIBSMTP_DEPS}
	$(MAKE) -C ${LIBSMTP_PATH}

${PLUGINDIR}/libA4GL_pcre${SO_EXT}: ${4GLC} ${LIBPCRE_DEPS}
	$(MAKE) -C ${LIBPCRE_PATH}

${PLUGINDIR}/libA4GL_sxml${SO_EXT}: ${4GLC} ${LIBSXML_DEPS}
	$(MAKE) -C ${LIBSXML_PATH}

${PLUGINDIR}/libA4GL_HTML${SO_EXT_LINKABLE}: ${4GLC} ${LIBHTML_DEPS}
	$(MAKE) -C ${LIBHTML_PATH} $@

	
##############
#Libs that need 4glpc
${PLUGINDIR}/libA4GL_memcache${SO_EXT_LINKABLE}: ${4GLPC} ${LIBMEMCACHE_DEPS}
	$(MAKE) -C ${LIBMEMCACHE_PATH} $@


############################
#LibLogical libraries:

${PLUGINDIR}/libLOGREPPROC_TXT${SO_EXT}:
	$(MAKE) -C liblogical/txt/process
${PLUGINDIR}/libLOGREPPROC_CSV${SO_EXT}:
	$(MAKE) -C liblogical/csv/process
${PLUGINDIR}/libLOGREPPROC_PDF${SO_EXT}:
	$(MAKE) -C liblogical/pdf/process

${PLUGINDIR}/libLOGREP_TXT${SO_EXT}:
	$(MAKE) -C liblogical/txt/layout
${PLUGINDIR}/libLOGREP_CSV${SO_EXT}:
	$(MAKE) -C liblogical/csv/layout
${PLUGINDIR}/libLOGREP_PDF${SO_EXT}:
	$(MAKE) -C liblogical/pdf/layout

##############
#Not libraries - programs:
aubit-config: ${AUBITCONFIG_DEPS}
	${MAKE} -C ${AUBITCONFIG_PATH}

loadmap: ${LOADMAP_DEPS}
	${FAIL_OK}${MAKE} -C ${LOADMAP_PATH}

${4GLC}:
	${MAKE} -C ${ROOT}/compilers/4glc

${4GLPC}: ${4GLC}
	${MAKE} -C ${ROOT}/tools/4glpc
	
${FCOMPILE}:
	${MAKE} -C ${ROOT}/compilers/fcompile

## ==================================================================
##                        Clean Targets
## ==================================================================

clean.all: clean
clean : \
	clean.generated clean.libsql clean.libpdf clean.librpc clean.libroot \
	clean.other clean.libui clean.libmenu clean.libform clean.libpacker \
	clean.cint clean.liblogical

clean.libroot:
	${RM} core *.out *.glb *${SO_EXT} *.a  *.bak *.dll *.stackdump *.err \
    bin/*.bak liblex/*.bak libpacker/*.bak libsql/*.bak *.base *.exp *.warn

clean.generated:
	${RM} generated/errdefs generated/tmperrs.h generated/*.o \
	generated/project.c generated/.*.bak

clean.libui:
	${MAKE} -C ${LIBUIHL_PATH} clean
	${MAKE} -C ${LIBUICONSOLE_PATH} clean
	${MAKE} -C ${LIBUICURSES_PATH} clean
	${MAKE} -C ${LIBUIGLADELIB_PATH} clean
	${MAKE} -C ${LIBUIGLADE_PATH} clean

clean.libsql:
	${MAKE} -C ${LIBSQLNOSQL_PATH} clean
	${MAKE} -C ${LIBSQLODBC_PATH} clean
	${MAKE} -C ${LIBSQLESQL_PATH} clean
	${MAKE} -C ${LIBSQLPG_PATH} clean
	${MAKE} -C ${FILESCHEMA_PATH} clean
	${MAKE} -C ${MYSQL_PATH} clean
#FIXME: not a makefile:
	-${MAKE} -C ${INGRES_PATH} clean

clean.libpdf:
	${MAKE} -C ${LIBEXREPORTPDF_PATH} clean

clean.librpc:
	${MAKE} -C ${LIBRPCXMLRPC_PATH} clean
	${MAKE} -C ${LIBRPCNORPC_PATH} clean
	${MAKE} -C ${LIBRPCSUNRPC_PATH} clean

clean.libmenu:
	${MAKE} -C ${LIBMENUNOMENU_PATH} clean
	${MAKE} -C ${LIBMENUGENERIC_PATH} clean
	${MAKE} -C ${LIBMENUXDR_PATH} clean

clean.libform:
	${MAKE} -C ${LIBFORMGENERIC_PATH} clean
	${MAKE} -C ${LIBFORMNOFORM_PATH} clean
	${MAKE} -C ${LIBFORMXDR_PATH} clean

clean.libpacker:
	${MAKE} -C ${LIBPACKERPACKED_PATH} clean
	${MAKE} -C ${LIBPACKERMEMPACKED_PATH} clean
	${MAKE} -C ${LIBPACKERPERL_PATH} clean
	${MAKE} -C ${LIBPACKERXDR_PATH} clean
	${MAKE} -C ${LIBPACKERXML_PATH} clean
	${MAKE} -C ${LIBPACKERGZPACKED_PATH} clean

clean.liblogical:
	$(MAKE) -C liblogical/txt/process clean
	$(MAKE) -C liblogical/txt/layout clean
	$(MAKE) -C liblogical/csv/process clean
	$(MAKE) -C liblogical/csv/layout clean
	$(MAKE) -C liblogical/pdf/process clean
	$(MAKE) -C liblogical/pdf/layout clean

	
clean.other:
	${MAKE} -C ${LIBAUBIT4GL_PATH} clean
	${MAKE} -C ${LIBMSGNATIVE_PATH} clean
	${MAKE} -C ${LIBHELP_STD_PATH} clean
	${MAKE} -C ${AUBITCONFIG_PATH} clean
	${MAKE} -C ${LOADMAP_PATH} clean
	${MAKE} -C ${LIBLEXEC_PATH} clean
	${MAKE} -C ${LIBEXDATA_PATH} clean
	${MAKE} -C ${LIBESQL_PATH} clean
	${MAKE} -C ${LIBSTRING_PATH} clean
	${MAKE} -C ${LIBCHANNEL_PATH} clean	
	${MAKE} -C ${LIBFILE_PATH} clean
	${MAKE} -C ${LIBESQLCHELPER_PATH} clean
	${MAKE} -C ${LIBHTML_PATH} clean
	${MAKE} -C ${LIBMEMCACHE_PATH} clean
	${MAKE} -C ${LIBPOP_PATH} clean
	${MAKE} -C ${LIBSMTP_PATH} clean
	${MAKE} -C ${LIBPCRE_PATH} clean
	${MAKE} -C ${LIBSXML_PATH} clean
	${MAKE} -C libsqlparse/none clean
	${MAKE} -C ../compilers/sql clean
	
clean.cint:
#We have to allow this one to fail, since it is possible that 
#Makefile was not yet created by make_cintlib script
	-${MAKE} -C ../cint clean
	cd ../cint; ${SH} make_cintlib -clean
	
## ==================================================================
##                         Other Targets
## ==================================================================

show:
	@echo ${LIBAUBIT4GL_DEPS}
	@echo "$$INGRES_INST_PATH"
	@echo "$$INGRES_ESQLC"
	@echo "$$HAVE_INGRES_ESQLC"


pluginsdir:
	if test ! -d ${PLUGINDIR}; then mkdir ${PLUGINDIR} 2> /dev/null; fi
#----------------------------------- EOF -------------------------------



