# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   Jabber makefile	   		 |
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
# $Id: Makefile,v 1.3 2005-02-03 10:31:44 afalout Exp $
#

ROOT        =../..
LIBROOT		=${ROOT}/lib

include ../../incl/Makefile-common

## ==================================================================
##                              Settings
## ==================================================================

AMAKE		=../../bin/amake
AMAKE_FLAGS	=${VERBOSE_FLAG} A4GL_CC_LDFLAGS+=-liksemel USESTORE=0 MOVETARGETTOSTORE=0
#AMAKE_FLAGS+=A4GL_CC_LDFLAGS+=A4GL_CC_LDFLAGS+=-noodbc A4GL_CC_LDFLAGS+=-nopdf

ifneq "${JABBERBUILD}" "no"
    ALL 	=${LIBROOT}/libIM_JABBER${SO_EXT} test_im.4ae
else
    ALL 	=no_libs
endif

CFLAGS		+=${IKSEMEL_I_FLAGS}

ifdef COMSPEC
	#The Win32 API has WinSock, which is a BSD-ish sockets implementation
	#_including_ select().  When you use MingW, you get the Win32 API version,
	#and when you use Cygwin (without -mno-cygwin) you get the special version
	#that Cygwin provides that is a bit slower but works on other types of file
	#descriptors besides just sockets.
	LINKLIBS		+=-lws2_32
	#Note: dll is installed in /bin not /lib
	IKSEMEL_L_PATH_WIN=${shell echo "${IKSEMEL_L_FLAGS}" | sed -e 's/-L//' | sed -e 's/\/lib/\/bin/'}
	IKSEMEL_L_PATH=${shell cygpath -u "${IKSEMEL_L_PATH_WIN}"}
	PATH:=${IKSEMEL_L_PATH}:${PATH}
	export PATH
endif

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "Default targets (${ALL}) compiled"
	
test_im.4ae: ${LIBROOT}/libIM_JABBER${SO_EXT} test_im.afr.dat test_im.4gl
#	${SH} ${AMAKE} test_im ${AMAKE_FLAGS}
	${SH} aubit 4glc test_im.4gl -o test_im.4ae -L${LIBROOT} -lIM_JABBER

test_im.afr.dat: test_im.per
	${SH} aubit fcompile $^ 
	
#lib4glim.o:
#	${CC} lib4glim.c -c -o $@

#Dynamically linked:
#Note that on Windows the dll will misteriously be liniked with 
#file libiksemel-3.dll and NOT libiksemel.dll as you would expect
libIM_JABBER${SO_EXT}: ${LIBROOT}/libIM_JABBER${SO_EXT}
${LIBROOT}/libIM_JABBER${SO_EXT}: lib4glim.o
	${LD} ${SO_LDFLAGS} $^ ${IKSEMEL_L_FLAGS} -o $@ ${LINKLIBS} -liksemel
ifeq "${SO_EXT}" ".dll"
#We will still need the dll.a untill we dlopen() it instead of linking 
	${MV} TMP${SOEXP_EXT} $@.a
endif


#Statically linked:
libIM_JABBERs${SO_EXT}: ${LIBROOT}/libIM_JABBERs${SO_EXT}
${LIBROOT}/libIM_JABBERs${SO_EXT}: lib4glim.o
#WARNING: order is EXTREMELY important for static linking on Windows!
	${LD} ${SO_LDFLAGS} $^ ${IKSEMEL_L_FLAGS} -o $@  \
		-static -liksemel ${LINKLIBS} 
ifeq "${SO_EXT}" ".dll"
#We will still need the dll.a untill we dlopen() it instead of linking 
	${MV} TMP${SOEXP_EXT} $@.a
endif


no_libs:
	@echo "IksEmEl library was not detected on your system. Stop."

## ==================================================================
##                              Testing
## ==================================================================

#lib4glim can be compiled as executable for testing:
exec4glim: lib4glim.c
	${CC} ${CFLAGS} $^ -o $@ ${IKSEMEL_L_FLAGS} ${LINKLIBS} -liksemel -D__ASEXEC__

#Send a test message using just library
testlib: exec4glim 4glim.conf
	echo "This is my message to you" | exec4glim
	
#Create configuration file:
#Before use, make sure account (aubit-test) is still valid, as jabber.org
#occasionally deletes unused accounts
4glim.conf:
	@echo "LOG mylogfile.log" > $@
	@echo "DEBUG" >> $@
	@echo "USER aubit-test@jabber.org" >> $@
	@echo "PASS aubit" >> $@

#Run a 4GL program to test IM functionality
test4gl: test_im.4ae
	rm -f debug.out
	A4GL_UI=HL_TUIN DEBUG=ALL ./test_im.4ae
	
show:
	@echo "CFLAGS=${CFLAGS}"
	@echo "IKSEMEL_I_FLAGS=${IKSEMEL_I_FLAGS}"
	@echo "IKSEMEL_L_PATH_WIN=${IKSEMEL_L_PATH_WIN}"
	@echo "IKSEMEL_L_PATH=${IKSEMEL_L_PATH}"
	@echo "PATH=${PATH}"
	@echo "SO_EXT=${SO_EXT}"
	
## ==================================================================
##                              Clean
## ==================================================================

clean: clean.test
	${RM} *.o core *.core *.bak *.4ae *.err *.glb *.h exec4glim *.afr \
		*.frm *.log *${SO_EXT} *.dll

clean.test:
	${SH} ${AMAKE} test_im clean


#------------------------------ EOF ---------------------------------
