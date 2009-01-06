# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0
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
# $Id: Makefile,v 1.2 2006-07-27 16:04:26 mikeaubury Exp $
#

ROOT    =../..
LIBROOT =${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ../../incl/Makefile-common
override NOINCL=0

## ==================================================================
##                              Options
## ==================================================================

4GLPCFLAGS=
FGLPCEXEC=export A4GL_LEXTYPE=C; ${FGLPCEXEC}
AMAKE=export A4GL_LEXTYPE=C; ${SH} ../../bin/amake
4GLC	=${ROOT}/bin/4glc

## ==================================================================
##                              Targets
## ==================================================================

all: html
	@echo default targets successfully compiled

html:
#	${AMAKE} simple_html
#	${AMAKE} ${VERBOSE_FLAG} A4GL_CC_LDFLAGS+=A4GL_CC_LDFLAGS+=-noodbc simple_html MOVETARGETTOSTORE=0
#	${AMAKE} A4GL_CC_LDFLAGS+= A4GL_CC_LDFLAGS+= A4GL_CC_LDFLAGS+=simple_html MOVETARGETTOSTORE=0
	${AMAKE} MOVETARGETTOSTORE=0


#Create start-up shell script:
simple_html:
#	@rm simple_html
	@echo '#!/bin/sh' > simple_html
#	@echo 'export NOCURSES=YES' >> simple_html
	@echo 'export A4GL_UI=CONSOLE' >> simple_html
#	@echo '/home/groups/a/au/aubit4gl/cgi-bin/simple_html.4ae NOCURSES=YES $$@' >> simple_html
	@echo 'simple_html.4ae $$@' >> simple_html
	@echo "simple_html sh script created"

simple_html.sf:
	@echo '#!/bin/sh' > simple_html
	@echo 'export A4GL_UI=CONSOLE' >> simple_html
	@echo '/home/groups/a/au/aubit4gl/cgi-bin/simple_html.4ae $$@' >> simple_html
	@echo "simple_html sh script created"

libA4GL_HTML${SO_EXT}: ${LIBROOT}/libA4GL_HTML${SO_EXT}
${LIBROOT}/libA4GL_HTML${SO_EXT}: libahtmllib.c
#	${FGLPCEXEC} ${AS_DLL} $^ -o $@
#FIXME: how are we going to link with this on Windows without .dll.a file ?
#fix 4glpc --as-dll to create .a file, and migrate everything to 4glc...
	${LD} ${SO_LDFLAGS} ${CFLAGS} -o $@ $^ -L${ROOT}/lib -l${AUBITLIBFULL}
	@echo "HTML library sucesfully compiled."

libahtmllib.c: libahtmllib.4gl
	export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; ${4GLC} ${VERBOSE_FLAG} $^



## ==================================================================
##                          Install
## ==================================================================

#This will copy to local cgi-bin:
copy.cgi: simple_html.4ae simple_html
	@if [ -d /usr/Apache-JServ/webserver/cgi-bin ] ;then ${CP} simple_html.4ae simple_html /usr/Apache-JServ/webserver/cgi-bin; fi
	@echo "Programs copied to local cgi-bin"

copy.css:
	@if [ -d /usr/Apache-JServ/webserver/cgi-bin ] ;then ${CP} *.css /usr/Apache-JServ/webserver/cgi-bin; fi

#This will use expect script "autosfscp-cgi" to provide password:
put.cgi: simple_html.4ae simple_html
	autosfscp-cgi simple_html
	autosfscp-cgi simple_html.4ae

#This will prompt for password for scp:
put.cgi.manual: simple_html.4ae simple_html
	scp simple_html.4ae afalout@aubit4gl.sourceforge.net:/home/groups/a/au/aubit4gl/cgi-bin


#this will put any file to cgi-bin on SF: "make put.manual FILE=myfile"
put.manual:
	scp $(FILE) afalout@aubit4gl
	urceforge.net:/home/groups/a/au/aubit4gl/cgi-bin




## ==================================================================
##                          Help
## ==================================================================

help:
	@echo "use 'make' to compile without GTK GUI"
	@echo "use 'make' to compile with GTK GUI"


## ==================================================================
##                           Clean targets
## ==================================================================


clean: html.clean.all
	$(RM) *.BAK *.bak core *~ *.ln *.output *.out *.frm *.h *.o *.4ae \
	simple_html *.hlp *.exe *.stackdump *.err *.tmp *.glb *.so *.${FGLC_OUTPUT_EXT}


html.clean.target:
	${AMAKE} simple_html clean.target

html.clean.all:
	${AMAKE} simple_html clean


#--------------------------- EOF -----------------------------------

