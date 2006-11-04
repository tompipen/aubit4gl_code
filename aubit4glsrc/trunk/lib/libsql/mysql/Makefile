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
# $Id: Makefile,v 1.9 2006-11-04 11:10:03 afalout Exp $
#

ROOT		=../../..
LIBROOT		=${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================


ifeq "${SQL_MYSQL_EMB}" "yes"
	ALL			= ${PLUGINDIR}/libSQL_mysqldb${SO_EXT}
endif
ifeq "${SQL_MYSQL}" "yes"
	ALL			+= ${PLUGINDIR}/libSQL_mysql${SO_EXT}
endif
CMODS		= mysql.c
OBJS		= ${CMODS:.c=.o}
OBJS_DB		= db-${CMODS:.c=.o}
L_FLAGS		= ${MYSQL_LFLAGS} -L$(LIBROOT)
LINKLIBS	= -lmysqlclient -laubit4gl-${A4GL_VERSION_STRING}
LINKLIBS_DB = -lmysqld -laubit4gl-${A4GL_VERSION_STRING}
CFLAGS		:= ${MYSQL_IFLAGS} -I${ROOT}/incl ${CFLAGS}


## ==================================================================
##                              Targets
## ==================================================================

ALL: ${ALL}
	@echo "Default targets (${ALL}) built successfully."

##############################################
#MySQL native plug-in, dynamically linked agains a shared library
libSQL_mysql${SO_EXT} : ${PLUGINDIR}/libSQL_mysql${SO_EXT}
${PLUGINDIR}/libSQL_mysql${SO_EXT} : ${OBJS}
#Someone added hard-coded -L/usr/lib64/mysql here. Please note that hard coding
#pretty much ANYTHING will have a great chance of:
#	a) not working for anyone else but you. Imagine if everyone added there
#		own private flags/paths directly to makefiles
#	b) breaking other's people build - like this broke mine as I compile 32 bit
# 		in 64 bin machine too (using 'linux32' utility)
#If you need it, please adjust configure.in to take case of your situation properly
#If you need help - please let me know (andrej at falout dot org)
	${LD} ${SO_LDFLAGS} -o $@ $^ ${L_FLAGS} ${LINKLIBS}

##############################################
#MySQL native plug-in, statically linked agains static library
libSQL_mysqlS${SO_EXT} : ${PLUGINDIR}/libSQL_mysqlS${SO_EXT}
${PLUGINDIR}/libSQL_mysqlS${SO_EXT} : ${OBJS}
#	${LD} ${SO_LDFLAGS} -o $@ $^ ${L_FLAGS} --static ${LINKLIBS}
#	${LD} ${SO_LDFLAGS} -o $@ $^ ${L_FLAGS} -laubit4gl-${A4GL_VERSION_STRING} -static -lmysqlclient
#	${LD} ${SO_LDFLAGS} -o $@ $^ -L$(LIBROOT) -laubit4gl-${A4GL_VERSION_STRING} -L/usr/lib/mysql -Wl,-static -lmysqlclient
#	${LD} $(filter-out -shared,${SO_LDFLAGS}) -o $@ $^ -L$(LIBROOT) -laubit4gl-${A4GL_VERSION_STRING} -L/usr/lib/mysql -Wl,-static -lmysqlclient
#Dont get it - not of the above produced .so statically linked with -lmysqlclient
#This did:
	ld -shared -o $@ $^ -L$(LIBROOT) -laubit4gl-${A4GL_VERSION_STRING} -L/usr/lib/mysql -static -lmysqlclient
	@ldd $@
#/usr/lib/mysql/libmysqlclient.a
#/usr/lib/mysql/libmysqlclient.la
	@echo "Compiled static plug-in OK"

##############################################
#Aubit MySQL plug-in containing Aubit connectivity and FULL MySQL database
#engine in a single library (MySQL embedded)
#One difference between the embedded server and the standalone server is that 
#for the embedded server, authentication for connections is disabled by default. 
#To use authentication for the embedded server, specify the 
#--with-embedded-privilege-control option when you invoke configure 
#to configure your MySQL distribution.
#When you link your program with libmysqld, you must also include the 
#system-specific pthread  libraries and some libraries that the MySQL server 
#uses. You can get the full list of libraries by executing mysql_config --libmysqld-libs.
libSQL_mysqldb${SO_EXT} : ${PLUGINDIR}/libSQL_mysqldb${SO_EXT}
${PLUGINDIR}/libSQL_mysqldb${SO_EXT} : ${OBJS_DB}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${L_FLAGS} ${LINKLIBS_DB} ${shell mysql_config --libmysqld-libs}
	@echo "Compiled static embedded MySQL plug-in OK"
	


#MYSQL4=/tmp/mysql-unpack-tmp/mysql-standard-4.1.21-pc-linux-gnu-i686-glibc23
#MYSQL4=/tmp/mysql-unpack-tmp/mysql-debug-4.1.21-pc-linux-gnu-i686-glibc23
MYSQL4=/tmp/mysql-4.1.21

libSQL_mysqldb4${SO_EXT} : ${PLUGINDIR}/libSQL_mysqldb4${SO_EXT}
${PLUGINDIR}/libSQL_mysqldb4${SO_EXT} : db-mysql4.o
	${LD} ${SO_LDFLAGS} -o $@ $^ ${shell ${MYSQL4}/bin/mysql_config --libmysqld-libs} \
		-L${ROOT}/lib -laubit4gl-${A4GL_VERSION_STRING} -lstdc++
	@ldd $@
	@echo "Compiled static embedded MySQL 4 plug-in OK"
	
	
	
## ==================================================================
##                              Sub-Targets
## ==================================================================

#Compile plug-in object for linking with embedded database, instead of 
#clienet. See http://dev.mysql.com/doc/refman/5.1/en/libmysqld.html
db-mysql.o: mysql.c
	${CC} ${CFLAGS} -c $^ -o $@ -DMYSQL_EMBEDDED

db-mysql4.o: mysql.c
	${CC} ${shell ${MYSQL4}/bin/mysql_config --cflags} -I${ROOT}/incl -c $^ -o $@ -DMYSQL_EMBEDDED

###########################
#Test embedded db plug-in
test: dbtest.4ae ${PLUGINDIR}/libSQL_mysqldb${SO_EXT} ./data
	DEBUG=ALL A4GL_SQLTYPE=mysqldb A4GL_LEXTYPE=C ./$^
	
dbtest.4ae: dbtest.4gl ${PLUGINDIR}/libSQL_mysqldb${SO_EXT}
	A4GL_SQLTYPE=mysqldb A4GL_LEXTYPE=C 4glpc $^ -o $@

###########################
#Test embedded db plug-in (4.1)
test4: dbtest4.4ae ${PLUGINDIR}/libSQL_mysqldb4${SO_EXT} ./data
	DEBUG=ALL A4GL_SQLTYPE=mysqldb4 A4GL_LEXTYPE=C gdb ./$<

dbtest4.4ae: dbtest.4gl ${PLUGINDIR}/libSQL_mysqldb4${SO_EXT}
	A4GL_SQLTYPE=mysqldb4 A4GL_LEXTYPE=C 4glpc $< -o $@

PWD=${shell pwd}

#############################
#Create minimal MySQL configuration file
./my.cnf: ${PWD}/my.cnf
${PWD}/my.cnf:
#When you use mysql_server_init(0, NULL, NULL), it initializes the server using
#groups = "server", "embedded" Any other group will be read ONLY if explicity 
#listed in server_init
	@echo "[server]" > $@ 
#	@echo "datadir=./data" >> $@
#	@echo "language=./english" >> $@
	@echo "datadir=${PWD}/data" >> $@
	@echo "language=${MYSQL4}/share/mysql/english" >> $@
	@echo "skip-innodb" >> $@
	@echo "default-character-set=latin1" >> $@
	@echo "basedir=${MYSQL4}/" >> $@
	@echo "log-error=/tmp/mysqld-emb.log" >> $@
	@echo " " >> $@

	@echo "[embedded]" >> $@
#	@echo "language=./english" >> $@
	@echo "language=${MYSQL4}/share/mysql/english" >> $@

	@echo "[client]" >> $@
#	@echo "language=./english" >> $@
	@echo "language=${MYSQL4}/share/mysql/english" >> $@
	@echo " " >> $@
	@echo "Created $@"
	
##############################
#Create empty data directory for use of MySQL db
#See http://dev.mysql.com/doc/refman/5.0/en/installing-binary.html
./data: ${PWD}/data
${PWD}/data: ${PWD}/my.cnf
	mkdir -p $@
#We WANT to create everything as current user, as embedded MySQL wil run
#as current user. On Windows, add --windows
	cd ${MYSQL4}; scripts/mysql_install_db --no-defaults \
		--user=${USER} --basedir=${MYSQL4} --datadir=$@ --verbose 
#MUST BE FIRST OPTION IN LIST: --defaults-file=$^ --no-defaults 
#	cd ${MYSQL4}; chown -R root  .; chown -R mysql data; chgrp -R mysql .
#	cd ${MYSQL4}; bin/mysqld_safe --user=mysql &
	@echo "Created $@"


################################
#Makefile debugging: show current settings of make variables
show:
	@echo "${shell ${MYSQL4}/bin/mysql_config --libmysqld-libs}"
#	@echo "Output of 'set':"
#	set

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} ${ALL} *.o *~ ${PLUGINDIR}/libSQL_mysqlS${SO_EXT} ${PLUGINDIR}/libSQL_mysqldb4${SO_EXT} \
	*.ao *.err *.4ae debug.out dbtest.c dbtest.h *.glb ./my.cnf
	rm -rf ./data
	
#----------------------------- EOF ----------------------------------

