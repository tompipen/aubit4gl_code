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
# $Id: Makefile,v 1.15 2007-09-13 08:10:06 mikeaubury Exp $
#

ROOT    =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

#FIXME: why do we need fcompile headers and RPC lib includes here?
#-I${LIBROOT}/compilers/fcompile
C_LOCAL_IFLAGS  		=-I..
CFLAGS					+=${C_LOCAL_IFLAGS}
CFLAGS_NOREDUND			=$(CFLAGS:%-Wredundant-decls=%)
CFLAGS_NOSTRICTPROTO	=$(CFLAGS:%-Wstrict-prototypes=%)
LCLINT_CFLAGS   		=${C_IFLAGS} ${C_LOCAL_IFLAGS}
OBJECTS					=sql.o sqlex.o array.o
#LD_RUN_PATH 			=${INFORMIXDIR}/lib/esql

CFLAGS_SQLITE	= -DSQLITEODBC -DHAVE_LIBVERSION=1 \
				-DWITHOUT_DRIVERMGR ${CFLAGS_NOREDUND} -DHAVE_LOCALECONV=1 \
				-L${SQLITE_LDPATH} -L${SQLITE_LDPATH2} -I${ROOT}/tools/odbctest/incl -I.
#SQLITE_ODBC_VER
#SQLITE_ODBC_LIBNAME_SHARED
#SQLITE_ODBC_LIBNAME_STATIC
				
				
ifneq "${COMSPEC}" ""
#Windows only
	LINKLIBS		=-L${LIBROOT} -l${AUBITLIBFULL}
	#On Windows we renamed .dll/.def files in original distribution 
	#(adding 'lib' prefix) and copied them to /cygwin/lib directory:
	#WARNING: paths for MinGW GCC MUST use forward slash - NOT backslash!!!
	CYGWIN_PATH_WIN :=$(shell cygpath -m "${CYGWIN_PATH_WIN}")
	SQLITE_LDPATH	:=$(shell cygpath -m "${SQLITE_LDPATH}")
	SQLITE_LDPATH2	:=$(shell cygpath -m "${SQLITE_LDPATH2}")
	#SQLITE_LINKLIBS	=-L${CYGWIN_PATH_WIN}/lib -L${SQLITE_LDPATH}
	SQLITE_LINKLIBS	=-L${SQLITE_LDPATH} -L${SQLITE_LDPATH2}
	CFLAGS_SQLITE	+=-DDLL_EXPORT -DPIC -DMEMORY_DEBUG=2

else
	CFLAGS_SQLITE	+=-DHAVE_USLEEP=1 
	#-L/usr/local/lib -L/usr/lib
endif

ALL		=iodbc unixodbc ifxodbc pgodbc sapodbc sqlite

ifeq "${SQLITE_ODBC}" "1"
	ALL		+=sqliteodbc
endif

.PHONY : ${ALL} clean all allodbc odbc32 #sqlite.static

ifeq "${TARGET_OS}" "darwin"
SQLITE_FLAGS=-L/opt/local/lib
else
SQLITE_FLAGS=-Wl,-call_shared -Wl,--dll-verbose 
endif

## ==================================================================
##                              Targets
## ==================================================================

all :
	@echo "Must specify target (because clean is not working.)"
	@echo "Targets: ${ALL} odbc32 allodbc " #sqlite.static"

allodbc: ${ALL}

#we MUST always clean first, because we don't know for which libs where
#current object compiled, if they exists.
iodbc: 		clean_iodbc ${PLUGINDIR}/libSQL_iodbc${SO_EXT}
	@echo "iODBC target compiled successfully"
unixodbc: 	clean_unixodbc ${PLUGINDIR}/libSQL_unixodbc${SO_EXT}
	@echo "unixODBC target compiled successfully"
ifxodbc: 	clean_ifxodbc ${PLUGINDIR}/libSQL_ifxodbc${SO_EXT}
	@echo "Informix ODBC target compiled successfully"
pgodbc: 	clean_pgodbc ${PLUGINDIR}/libSQL_pgodbc${SO_EXT}
	@echo "PostgreSQL ODBC target compiled successfully"
sapodbc: 	clean_sapodbc ${PLUGINDIR}/libSQL_sapodbc${SO_EXT}
	@echo "SAP DB ODBC target compiled successfully"
sqliteodbc: clean_sqliteodbc ${PLUGINDIR}/libSQL_sqliteodbc${SO_EXT}
	@echo "SQLite ODBC target compiled successfully"
sqlite: clean_sqlite ${PLUGINDIR}/libSQL_sqlite${SO_EXT}
	@echo "SQLite native Aubit plug-in compiled successfully"
sqlite.static: clean_sqliteS ${PLUGINDIR}/libSQL_sqliteS${SO_EXT}
	@echo "SQLite native Aubit plug-in (static link) compiled successfully"
sqlite3: clean_sqlite3 ${PLUGINDIR}/libSQL_sqlite3${SO_EXT}
	@echo "SQLite3 native Aubit plug-in compiled successfully"
sqlite3.static: clean_sqlite3S ${PLUGINDIR}/libSQL_sqlite3S${SO_EXT}
	@echo "SQLite3 native Aubit plug-in (static link) compiled successfully"

################################
#Aubit ODBC plug-in code linked with Microsoft Windows ODBC manager library
odbc32: 	clean_odbc32 ${OBJECTS} ${PLUGINDIR}/libSQL_odbc32${SO_EXT}
${PLUGINDIR}/libSQL_odbc32${SO_EXT} : ${OBJECTS}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS} -lodbc32
	@echo "Windows ODBC target compiled successfully"

################################
#Aubit ODBC plug-in code linked with iODBC ODBC manager library
${PLUGINDIR}/libSQL_iodbc${SO_EXT}: CFLAGS:=-DIODBC  ${IODBC_INCLUDE} ${IODBC_LFLAGS} ${CFLAGS_NOREDUND}
${PLUGINDIR}/libSQL_iodbc${SO_EXT}: ${OBJECTS}
	${LD} ${SO_LDFLAGS} $^ -o $@ ${IODBC_LIBS} ${IODBC_LFLAGS}

################################
#Aubit ODBC plug-in code linked with unixODBC ODBC manager library
${PLUGINDIR}/libSQL_unixodbc${SO_EXT}: CFLAGS:=-DUNIXODBC ${UNIXODBC_LFLAGS} ${UNIXODBC_INCLUDE} ${CFLAGS}
${PLUGINDIR}/libSQL_unixodbc${SO_EXT}: ${OBJECTS}
	${LD} ${SO_LDFLAGS} $^ -o $@ ${UNIXODBC_LIBS} ${UNIXODBC_LFLAGS}

################################
#Aubit ODBC plug-in code linked with (Informix) ODBC driver library, for use without ODBC manager
${PLUGINDIR}/libSQL_ifxodbc${SO_EXT}: CFLAGS:=-DIFXODBC  -I${INFORMIXDIR} -I${INFORMIXDIR}/incl/cli -L${INFORMIXDIR}/lib/cli -L${INFORMIXDIR}/lib/esql ${CFLAGS_NOSTRICTPROTO}
${PLUGINDIR}/libSQL_ifxodbc${SO_EXT}: ${OBJECTS}
	${LD} ${SO_LDFLAGS} $^ -o $@ -lifcli -lifdmr -L${INFORMIXDIR}/lib/cli -L${INFORMIXDIR}/lib/esql

################################
#Aubit ODBC plug-in code linked with (PG) ODBC driver library, for use without ODBC manager
${PLUGINDIR}/libSQL_pgodbc${SO_EXT}: CFLAGS:=-DPGODBC -DSQLHDBC=HDBC  -DINCLUDEDATASOURCES ${PGODBC_INCLUDE} ${PGODBC_LFLAGS} ${CFLAGS_NOREDUND}
${PLUGINDIR}/libSQL_pgodbc${SO_EXT}: ${OBJECTS}
	${LD} ${SO_LDFLAGS} $^ -o $@ -l${PGODBC_LIBNAME} ${PGODBC_LFLAGS}

################################
#Aubit ODBC plug-in code linked with (SAPDB) ODBC driver library, for use without ODBC manager
${PLUGINDIR}/libSQL_sapodbc${SO_EXT}: CFLAGS:=-DSAPODBC ${SAPODBC_INCLUDE} ${SAPODBC_LFLAGS} ${CFLAGS_NOREDUND}
${PLUGINDIR}/libSQL_sapodbc${SO_EXT}: ${OBJECTS}
	${LD} ${SO_LDFLAGS} $^ -o $@ ${SAPDB_ODBC_ADDLIBS} -lsqlod ${SAPODBC_LFLAGS}

###############################
#Aubit ODBC plug-in linked with SQLite ODBC driver for use without ODBC manager
#${LIBROOT}/libSQL_sqliteodbc${SO_EXT}: CFLAGS:=-DSQLITEODBC ${CFLAGS_NOREDUND} -I${ROOT}/tools/odbctest/incl
${PLUGINDIR}/libSQL_sqliteodbc${SO_EXT}: CFLAGS:=-I${ROOT}/tools/odbctest/incl  ${CFLAGS_SQLITE}
${PLUGINDIR}/libSQL_sqliteodbc${SO_EXT}: ${OBJECTS}
	${LD} ${SO_LDFLAGS} $^ -o $@ -L${SQLITE_ODBC_LIBDIR} -l${SQLITE_ODBC_LIBNAME_SHARED}

###############################
#SQLite plug-in dynamically linked with SQLite library/engine:
#This plug-in consists of 1) Aubit ODBC plug-in code 2) SQLiteODBC code we have
#a private copy of in Aubit CVS, and 3) SQLite engine library 
${PLUGINDIR}/libSQL_sqlite${SO_EXT}: CFLAGS:=${CFLAGS_SQLITE}  -DSQLITE_DIRECT
${PLUGINDIR}/libSQL_sqlite${SO_EXT}: ${OBJECTS} sqliteodbc.o
	${LD} ${SO_LDFLAGS} $^ -o $@ ${SQLITE_LINKLIBS} -l${SQLITE_LIBNAME} ${LINKLIBS}

################################	
#Same as above, but with SQLite VERSION 3
libSQL_sqlite3${SO_EXT}: ${PLUGINDIR}/libSQL_sqlite3${SO_EXT}
${PLUGINDIR}/libSQL_sqlite3${SO_EXT}: CFLAGS:=${CFLAGS_SQLITE}  -DSQLITE_DIRECT
${PLUGINDIR}/libSQL_sqlite3${SO_EXT}: ${OBJECTS} sqlite3odbc.o

	${LD} ${SO_LDFLAGS} $^ -o $@ ${SQLITE_LINKLIBS} ${SQLITE_FLAGS} -l${SQLITE_LIBNAME} ${LINKLIBS} > link.log 2>&1
#ifdef COMSPEC
	@echo "Should NOT be empty: '`cygcheck $@ | grep -v libSQL_ | grep ${SQLITE_LIBNAME}.dll`'"
#endif

#The above target on windows will produce statically linked dll anyway
#Failed to link dynamically, despite forcing linker with -Wl,-call_shared :
#attempt to open D:/msys/1.0/local/lib/libsqlite3.dll.a failed
#attempt to open D:/msys/1.0/local/lib/sqlite3.dll.a failed
#attempt to open D:/msys/1.0/local/lib/libsqlite3.a succeeded
#
#But when I hide libsqlite3.a (mv libsqlite3.a libsqlite3.a-hide)
#
#attempt to open D:/msys/1.0/local/lib/libsqlite3.dll.a failed
#attempt to open D:/msys/1.0/local/lib/sqlite3.dll.a failed
#attempt to open D:/msys/1.0/local/lib/libsqlite3.a failed
#attempt to open D:/msys/1.0/local/lib/libsqlite3.dll succeeded
#
#Conclusion: .a ALLWAYS has priority over .dll - the only way to link against
#.dll is to have dll.a or NOT to have .a
#
#SQLite on Windows produces .dll .a and .la - and NOT dll.a
#Unless I go and remove .a, or modify SQLite makefile to produce .dll.a,
#(or ask GCC people why are they happily linking with .dll when there is no .a)
#there is not much I can do...

###############################
#Same as libSQL_sqlite but statically linked with SQLite library/engine:
#NOTE: no static SQLite library supplied for Windows in version 2.x
${PLUGINDIR}/libSQL_sqliteS${SO_EXT}: CFLAGS:=${CFLAGS_SQLITE} -DSQLITE_DIRECT
${PLUGINDIR}/libSQL_sqliteS${SO_EXT}: ${OBJECTS} sqliteodbc.o
	${LD} ${SO_LDFLAGS} -Wl,-static $^ -o $@ -L${SQLITE_LDPATH} -L${SQLITE_LDPATH2} \
		${SQLITE_LINKLIBS} -l${SQLITE_LIBNAME} ${LINKLIBS}

###############################
#Same as above, but linked with SQLite VERSION 3
#WARNING: order is EXTREMELY important for static linking on Windows!
libSQL_sqlite3S${SO_EXT}: ${PLUGINDIR}/libSQL_sqlite3S${SO_EXT}
${PLUGINDIR}/libSQL_sqlite3S${SO_EXT}: CFLAGS:=${CFLAGS_SQLITE} -DSQLITE_DIRECT
${PLUGINDIR}/libSQL_sqlite3S${SO_EXT}: ${OBJECTS} sqlite3odbc.o
	${LD} ${SO_LDFLAGS} $^ ${SQLITE_LINKLIBS} ${LINKLIBS} -L${SQLITE_LDPATH} -L${SQLITE_LDPATH2} -o $@  \
		${LINKLIBS} -Wl,-static -l${SQLITE_LIBNAME} 
#ifdef COMSPEC
	@echo "Should be empty: '`cygcheck $@ | grep ${SQLITE_LIBNAME}.dll`'"
#endif


## ==================================================================
##                              Clean
## ==================================================================

cleanish:
	${RM} *.o *.bak *.base *.dll *.def *.exp *.a 

clean_ifxodbc: cleanish
		${RM} ${PLUGINDIR}/libSQL_ifxodbc${SO_EXT} 
clean_iodbc: cleanish
		${RM} ${PLUGINDIR}/libSQL_iodbc${SO_EXT} 
clean_odbc32: cleanish
		${RM} ${PLUGINDIR}/libSQL_odbc32${SO_EXT} 
clean_pgodbc: cleanish
		${RM} ${PLUGINDIR}/libSQL_pgodbc${SO_EXT} 
clean_sapodbc: cleanish
		${RM} ${PLUGINDIR}/libSQL_sapodbc${SO_EXT} 
clean_sqlite: cleanish
		${RM} ${PLUGINDIR}/libSQL_sqlite${SO_EXT} 
clean_sqlite3: cleanish
		${RM} ${PLUGINDIR}/libSQL_sqlite3${SO_EXT} 
clean_sqlite3S: cleanish
		${RM} ${PLUGINDIR}/libSQL_sqlite3S${SO_EXT} 
clean_sqliteS: cleanish
		${RM} ${PLUGINDIR}/libSQL_sqliteS${SO_EXT} 
clean_sqliteodbc: cleanish
		${RM} ${PLUGINDIR}/libSQL_sqliteodbc${SO_EXT} 
clean_unixodbc: cleanish
		${RM} ${PLUGINDIR}/libSQL_unixodbc${SO_EXT} 
clean:  cleanish
		${RM} ${PLUGINDIR}/libSQL_ifxodbc${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_iodbc${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_odbc32${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_pgodbc${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_sapodbc${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_sqlite${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_sqlite3${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_sqlite3S${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_sqliteS${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_sqliteodbc${SO_EXT} 
		${RM} ${PLUGINDIR}/libSQL_unixodbc${SO_EXT} 


## ----------------------------- EOF -------------------------------

