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
# $Id: Makefile,v 1.2 2004-12-19 08:12:38 afalout Exp $
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

#target names are maintained in configure.in
ALL_LIBS=${LIB_DEFAULT} ${LIB_OPTIONAL}
ALL 	=aubit-config ${ALL_LIBS}

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
#LIBLEXC_PATH   		=liblex/lex_c
LIBLEXEC_PATH  		=liblex/lex_esqlc
LIBLEXPERL_PATH   	=liblex/lex_perl
LIBEXREPORTPDF_PATH =libpdf
LIBFILE_PATH		=extra_libs/file
LIBSTRING_PATH		=extra_libs/string
LIBCHANNEL_PATH		=extra_libs/channel
LIBESQLCHELPER_PATH	=libesql
LIBHTML_PATH        =${ROOT}/tools/html
LIBSQLESQL_PATH     =libsql/esqlc
LIBUIHL_PATH       =libui/ui_highlevel
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
LIBPOP_PATH     	=extra_libs/pop
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
#LIBLEXC_DEPS		=$(wildcard ${LIBLEXC_PATH}/*.c) $(wildcard ${LIBLEXC_PATH}/*.h) \
#					$(wildcard ${LIBLEXC_PATH}/Makefile) ${ALL_H}
LIBLEXEC_DEPS		=$(wildcard ${LIBLEXEC_PATH}/*.c) $(wildcard ${LIBLEXEC_PATH}/*.h) ${ROOT}/compilers/4glc/API_lex.h \
					$(wildcard ${LIBLEXEC_PATH}/Makefile) ${ALL_H}
LIBLEXPERL_DEPS		=$(wildcard ${LIBLEXPERL_PATH}/*.c) $(wildcard ${LIBLEXPERL_PATH}/*.h) \
					$(wildcard ${LIBLEXPERL_PATH}/Makefile) ${ALL_H}
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
LIBPCRE_DEPS		=$(wildcard ${LIBPCRE_PATH}/*.4gl) $(wildcard ${LIBPCRE_PATH}/makefile) ${ALL_H}
LIBSXML_DEPS		=$(wildcard ${LIBPCRE_PATH}/*.4gl) $(wildcard ${LIBPCRE_PATH}/Makefile) ${ALL_H}
LIBHTML_DEPS		=$(wildcard ${LIBHTML_PATH}/*.c) $(wildcard ${LIBHTML_PATH}/*.h) \
					$(wildcard ${LIBHTML_PATH}/Makefile) ${ALL_H}
LIBSQLESQL_DEPS		=$(wildcard ${LIBSQLESQL_PATH}/*.ec) $(wildcard ${LIBSQLESQL_PATH}/*.h) \
					$(wildcard ${LIBSQLESQL_PATH}/Makefile) ${ALL_H}
LIBUIGTK_DEPS		=$(wildcard ${LIBUIGTK_PATH}/*.c) $(wildcard ${LIBUIGTK_PATH}/*.h) \
					$(wildcard ${LIBUIGTK_PATH}/Makefile) ${ALL_H}
LIBUIHL_DEPS		=$(wildcard ${LIBUIHL_PATH}/*.c) $(wildcard ${LIBUIHL_PATH}/*.h) \
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
	@for a in $(ALL_LIBS); do if ! test -f $$a; then echo "$$a does not exist"; exit 1; fi; done
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

libLEX_PERL${SO_EXT}: ${LIBLEXPERL_DEPS}
	${MAKE} -C ${LIBLEXPERL_PATH}

libLEX_C${SO_EXT} libLEX_EC${SO_EXT}: ${LIBLEXEC_DEPS}
	${MAKE} -C ${LIBLEXEC_PATH}

##############
#libUI_

libUI_TUI${SO_EXT}: ${LIBUICURSES_DEPS}
	$(MAKE) -C ${LIBUICURSES_PATH}

libUI_CONSOLE${SO_EXT}: ${LIBUICONSOLE_DEPS}
	$(MAKE) -C ${LIBUICONSOLE_PATH}

#libUI_HLGENERIC${SO_EXT}: ${LIBUIHL_DEPS}
#	$(MAKE) -C ${LIBUIHL_PATH}

libUI_HL_TUI${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

libUI_HL_TUIN${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

libUI_HL_TUINs${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

libUI_HL_TUIX${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@
	
libUI_HL_GTK${SO_EXT}: ${LIBUIHL_DEPS}
	$(MAKE) -C ${LIBUIHL_PATH} $@

libA4GL_glade${SO_EXT}: ${LIBUIGLADELIB_DEPS}
	$(MAKE) -C ${LIBUIGLADELIB_PATH}

libUI_GLADE${SO_EXT}: ${LIBUIGLADE_DEPS}
	$(MAKE) -C ${LIBUIGLADE_PATH}

##############
#libFORM_

libFORM_NOFORM${SO_EXT} : ${LIBFORMNOFORM_DEPS}
	${MAKE} -C ${LIBFORMNOFORM_PATH}

libFORM_XDR${SO_EXT} : ${LIBFORMXDR_DEPS}
	${MAKE} -C ${LIBFORMXDR_PATH}

libFORM_GENERIC${SO_EXT}: ${LIBFORMGENERIC_DEPS}
	${MAKE} -C ${LIBFORMGENERIC_PATH}

##############
#libMENU_

libMENU_NOMENU${SO_EXT} : ${LIBMENUNOMENU_DEPS}
	${MAKE} -C ${LIBMENUNOMENU_PATH}

libMENU_GENERIC${SO_EXT} : ${LIBMENUGENERIC_DEPS}
	${MAKE} -C ${LIBMENUGENERIC_PATH}

libMENU_XDR${SO_EXT} : ${LIBMENUXDR_DEPS}
	${MAKE} -C ${LIBMENUXDR_PATH}

##############
#libREPORT_

libEXREPORT_PDF${SO_EXT}: ${LIBEXREPORTPDF_DEPS}
	${MAKE} -C ${LIBEXREPORTPDF_PATH}

libEXREPORT_NOPDF${SO_EXT}: ${LIBEXREPORTPDF_DEPS}
	${MAKE} -C ${LIBEXREPORTPDF_PATH}

##############
#libPACKER_

libPACKER_PACKED${SO_EXT}: ${LIBPACKERPACKED_DEPS}
	${MAKE} -C ${LIBPACKERPACKED_PATH}

libPACKER_MEMPACKED${SO_EXT}: ${LIBPACKERMEMPACKED_DEPS}
	${MAKE} -C ${LIBPACKERMEMPACKED_PATH}

libPACKER_PERL${SO_EXT}: ${LIBPACKERPERL_DEPS}
	${MAKE} -C ${LIBPACKERPERL_PATH}

libPACKER_XDR${SO_EXT}: ${LIBPACKERXDR_DEPS}
	${MAKE} -C ${LIBPACKERXDR_PATH}

libPACKER_XML${SO_EXT}: ${LIBPACKERXML_DEPS}
	${MAKE} -C ${LIBPACKERXML_PATH}

##############
#libSQL_ ESQL (native)

#Informix ESQL/C code SQL plug-in compiled with Informix esql ESQL/C compiler
libSQL_esql${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@
#same thing, but different name for consistency:
libSQL_esqlI${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#Informix ESQL/C code SQL plug-in compiled with Querix esqlc ESQL/C compiler
libSQL_esqlQ${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#Informix ESQL/C code SQL plug-in compiled with SAP DB cpc ESQL/C compiler
libSQL_esqlSAP${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#Informix ESQL/C code SQL plug-in compiled with PostgreSQL ecpg ESQL/C compiler
libSQL_esqlPG${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#PostgreSQL esql plug-in based on 'simple' template (ecpg in non-Informix mode)
libSQL_c_ecpg${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@

#Informix esql plug-in based on 'simple' template
libSQL_c_esql${SO_EXT}: ${LIBSQLESQL_DEPS}
	${MAKE} -C ${LIBSQLESQL_PATH} $@


##############
#libSQL_ C (native)

#Dummy plug-in good for testing or to disable SQL
libSQL_nosql${SO_EXT}: ${LIBSQLNOSQL_DEPS}
	${MAKE} -C ${LIBSQLNOSQL_PATH}

#an simple PG plug-in with limited functionality (by Mike)
libSQL_pg${SO_EXT}: ${LIBSQLPG_DEPS}
	${MAKE} -C ${LIBSQLPG_PATH}

#Sergio never finished this one...
libSQL_pgDEVEL${SO_EXT}: ${LIBSQLPG_DEPS}
	${MAKE} -C ${LIBSQLPG_PATH}

#compile only plug-in for reading schema from file
libSQL_FILESCHEMA${SO_EXT}: ${FILESCHEMA_DEPS}
	${MAKE} -C ${FILESCHEMA_PATH}

##############
#libSQL_ (ODBC) plug-ins directly linked with ODBC driver

libSQL_ifxodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} ifxodbc

libSQL_pgodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} pgodbc

libSQL_sapodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sapodbc

#Linked with SQLite ODBC driver, like any other directly linked ODBC plug-in
#requires SQLite ODBC driver and SQLite library on the system
libSQL_sqliteodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sqliteodbc

#Compiled with SQLite ODBC driver source code in Aubit CVS
#requires SQLite library on the system
libSQL_sqlite${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sqlite
#Same, but version 3
libSQL_sqlite3${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sqlite3

#Compiled with SQLite ODBC driver source code in Aubit CVS and statically
#linked with SQLite database engine ligrary (self sufficient - used mainly 
#for binary distributions to provide "always there" SQL functionality)
libSQL_sqliteS${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sqlite.static
#Same, but version 3
libSQL_sqlite3S${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} sqlite3.static


##############
#libSQL_ (ODBC) managers

libSQL_iodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} iodbc

libSQL_unixodbc${SO_EXT}: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} unixodbc


libSQL_odbc32.dll: ${LIBSQLODBC_DEPS}
	${MAKE} -C ${LIBSQLODBC_PATH} odbc32

	
libSQLPARSE_NONE${SO_EXT}:
	${MAKE} -C libsqlparse/none

libSQLPARSE_INFORMIX${SO_EXT}:
	${MAKE} -C ../compilers/sql

##############
#libRPC_

libRPC_XDR${SO_EXT}: ${LIBRPCSUNRPC_DEPS}
	${MAKE} -C ${LIBRPCSUNRPC_PATH}

libRPC_NORPC${SO_EXT}: ${LIBRPCNORPC_DEPS}
	${MAKE} -C ${LIBRPCNORPC_PATH}

libRPC_XMLRPC${SO_EXT}: ${LIBRPCXMLRPC_DEPS}
	${MAKE} -C ${LIBRPCXMLRPC_PATH}

#############
# libESQL

libESQL_INFORMIX${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

libESQL_POSTGRES${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

libESQL_QUERIX${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

libESQL_SAP${SO_EXT}: ${LIBESQL_DEPS}
	${MAKE} -C ${LIBESQL_PATH} $@

##############
#libEXDTYPE_

libEXDTYPE_mpz${SO_EXT}: ${LIBEXDATA_DEPS}
	${MAKE} -C ${LIBEXDATA_PATH} $@

##############
#libDATA_ & libXDRPACKER_

libDATA_menu_list${SO_EXT} libDATA_struct_form${SO_EXT} libDATA_report${SO_EXT}\
libXDRPACKER_struct_form${SO_EXT} libXDRPACKER_menu_list${SO_EXT} \
libXDRPACKER_report${SO_EXT}: ${LIBDATA_DEPS}
	${MAKE} -C ${LIBDATA_PATH}


${ROOT}/compilers/4glc/API_lex.h: ${ROOT}/compilers/4glc/API_lex.spec
	${SH} ${ROOT}/lib/bin/dlmagic ${ROOT}/compilers/4glc/API_lex.spec -h > ${ROOT}/compilers/4glc/API_lex.h

###############
#Misc libs:
libMSG_NATIVE${SO_EXT}: ${LIBMSGNATIVE_DEPS}
	${MAKE} -C ${LIBMSGNATIVE_PATH}

libIM_JABBER${SO_EXT_LINKABLE}: ${LIBIMJABBER_DEPS}
	$(MAKE) -C ${LIBIMJABBER_PATH} $@

libIM_JABBERs${SO_EXT_LINKABLE}: ${LIBIMJABBER_DEPS}
	$(MAKE) -C ${LIBIMJABBER_PATH} $@
	
libA4GL_cint${SO_EXT_LINKABLE}:
	cd ../cint; ${SH} make_cintlib


##############
#Libs that need 4glc
libHELP_std${SO_EXT}: ${LIBHELP_STD_DEPS} ${4GLC} ${FCOMPILE}
	${MAKE} -C ${LIBHELP_STD_PATH}

libA4GL_file${SO_EXT}: ${4GLC} ${LIBFILE_DEPS}
	$(MAKE) -C ${LIBFILE_PATH}

libA4GL_string${SO_EXT}: ${4GLC} ${LIBSTRING_DEPS}
	$(MAKE) -C ${LIBSTRING_PATH}

libchannel${SO_EXT}: ${4GLC} ${LIBCHANNEL_DEPS}
	$(MAKE) -C ${LIBCHANNEL_PATH}
	
libA4GL_pop${SO_EXT}: ${4GLC} ${LIBPOP_DEPS}
	$(MAKE) -C ${LIBPOP_PATH}

libA4GL_pcre${SO_EXT}: ${4GLC} ${LIBPCRE_DEPS}
	$(MAKE) -C ${LIBPCRE_PATH}

libA4GL_sxml${SO_EXT}: ${4GLC} ${LIBSXML_DEPS}
	$(MAKE) -C ${LIBSXML_PATH}

libA4GL_HTML${SO_EXT_LINKABLE}: ${4GLC} ${LIBHTML_DEPS}
	$(MAKE) -C ${LIBHTML_PATH} $@

##############
#Not libraries - programs:
aubit-config: ${AUBITCONFIG_DEPS}
	${MAKE} -C ${AUBITCONFIG_PATH}

loadmap: ${LOADMAP_DEPS}
	${FAIL_OK}${MAKE} -C ${LOADMAP_PATH}

${4GLC}:
	${MAKE} -C ${ROOT}/compilers/4glc

${FCOMPILE}:
	${MAKE} -C ${ROOT}/compilers/fcompile

## ==================================================================
##                        Clean Targets
## ==================================================================

clean.all: clean
clean : \
	clean.generated clean.libsql clean.libpdf clean.librpc clean.libroot \
	clean.other clean.libui clean.libmenu clean.libform clean.libpacker \
	clean.cint

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

clean.other:
	${MAKE} -C ${LIBAUBIT4GL_PATH} clean
	${MAKE} -C ${LIBMSGNATIVE_PATH} clean
	${MAKE} -C ${LIBHELP_STD_PATH} clean
	${MAKE} -C ${AUBITCONFIG_PATH} clean
	${MAKE} -C ${LOADMAP_PATH} clean
	${MAKE} -C ${LIBLEXEC_PATH} clean
	${MAKE} -C ${LIBLEXPERL_PATH} clean
	${MAKE} -C ${LIBEXDATA_PATH} clean
	${MAKE} -C ${LIBESQL_PATH} clean
	${MAKE} -C ${LIBSTRING_PATH} clean
	${MAKE} -C ${LIBCHANNEL_PATH} clean	
	${MAKE} -C ${LIBFILE_PATH} clean
	${MAKE} -C ${LIBESQLCHELPER_PATH} clean
	${MAKE} -C ${LIBHTML_PATH} clean
	${MAKE} -C ${LIBPOP_PATH} clean
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


#----------------------------------- EOF -------------------------------



