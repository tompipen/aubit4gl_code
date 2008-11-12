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
# $Id: Makefile,v 1.4 2007-06-19 18:02:02 mikeaubury Exp $
#

ROOT			=../../../..

#All stuff common to more then one Aubit compiler make file is there:
include 		${ROOT}/incl/Makefile-common

#Include rules for compiling 4GL source code using Aubit compiler
#include 		${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Options
## ==================================================================

CFLAGS			+=-I${ROOT}/incl
ALL				=${PLUGINDIR}/libA4GL_glade${SO_EXT}
OBJS			=list.ao common.ao form.ao sbar.ao field.ao entry.ao \
					text_view.ao mlist.ao
LINKLIBS		=$(shell pkg-config libglade-2.0 --libs)
#LINKLIBS		=$(shell pkg-config libglade-2.0 --libs-only-L) \
#					$(shell pkg-config libglade-2.0 --libs-only-l)
GLADE_CFLAGS	=$(shell pkg-config libglade-2.0 --cflags)

A4GL_LEXTYPE=C
export A4GL_LEXTYPE

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "+--------------------------------------------------------------------+"
	@echo "| Default targets (${ALL}) successfuly compiled"
	@echo "+--------------------------------------------------------------------+"	

${PLUGINDIR}/libA4GL_glade${SO_EXT} : ${OBJS}
#	export A4GL_LEXTYPE=C && 
	${CC} ${SO_LDFLAGS} -g  $^ -o $@ ${LINKLIBS} -L${LIBROOT} -l${AUBITLIBFULL}
#	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}
	
## ==================================================================
##                              Sub-targets
## ==================================================================

#Amake will do this automatically:

%.ao: %.4gl
	export A4GL_LEXTYPE=C && ${ROOT}/bin/4glc $< 
	${CC} ${CFLAGS} -g -c $*.c -o $@ ${GLADE_CFLAGS} -I$(ROOT)/incl 

#list.ao: list.4gl
#	export A4GL_LEXTYPE=C && 4glc $^ 
#	${CC} -g -c $*.c -o $@ `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl 

#mlist.ao: mlist.4gl
#	export A4GL_LEXTYPE=C && 4glc mlist.4gl 
#	gcc -g  -c mlist.c -o mlist.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl 

#common.ao: common.4gl
#	export A4GL_LEXTYPE=C && 4glc common.4gl 
#	gcc -g  -c common.c -o common.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

#form.ao: form.4gl
#	export A4GL_LEXTYPE=C && 4glc form.4gl 
#	gcc -g  -c form.c -o form.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

#sbar.ao: sbar.4gl
#	export A4GL_LEXTYPE=C && 4glc sbar.4gl 
#	gcc -g  -c sbar.c -o sbar.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

#field.ao: field.4gl
#	export A4GL_LEXTYPE=C && 4glc field.4gl 
#	gcc -g  -c field.c -o field.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

#entry.ao: entry.4gl
#	export A4GL_LEXTYPE=C && 4glc entry.4gl 
#	gcc -g  -c entry.c -o entry.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

#text_view.ao: text_view.4gl
#	export A4GL_LEXTYPE=C && 4glc text_view.4gl 
#	gcc -g  -c text_view.c -o text_view.o `pkg-config libglade-2.0 --cflags` -I$(AUBITDIR)/incl

show:
	@echo "FGLPCEXEC=${FGLPCEXEC}"
	@echo "AS_DLL=${AS_DLL}"
	@echo "LINKLIBS=${LINKLIBS}"
	@echo ""
	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.ao *.ec *.glb *.o *.c *.h *.err *.warn debug.out *~ *.bak ${ALL}


