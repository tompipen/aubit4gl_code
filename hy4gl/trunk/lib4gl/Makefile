# +----------------------------------------------------------------------+
# | Hy4gl 4gl Language Compiler Version $.0   root makefile				 |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 David Prieto [davidp@sgth.es]                   |
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
# | contact David Prieto [davidp@sgth.es]                                         |
# +----------------------------------------------------------------------+
#
# $Id: Makefile,v 1.2 2001-10-25 03:29:09 afalout Exp $

## ==================================================================
##                              Settings
## ==================================================================

include ../Makefile.global

FUENTES=4gl.c fecha.c pila.c menu.c browse.c pgres.c 4glforms.c fecha.c \
   fun_fecha.c runtime.c
OBJS=4gl.o fecha.o pila.o menu.o browse.o pgres.o 4glforms.o \
   fun_fecha.o runtime.o

## ==================================================================
##                              Targets
## ==================================================================

all: lib4gl.so.$(VERSION) lib4gl.$(VERSION).a


static: lib4gl.$(VERSION).a

.c.o:
	gcc -g -DVERSION='"$(VERSION)"' -Wall -c $< -I$(INCL_PGRES) -I.

lib4gl.so.$(VERSION): $(OBJS)
	ld -x -Bshareable -o lib4gl.so.$(VERSION) $(OBJS)

lib4gl.$(VERSION).a: $(OBJS)
	ar crs lib4gl.$(VERSION).a $(OBJS)
	ranlib lib4gl.$(VERSION).a

## ==================================================================
##                              Install
## ==================================================================

install: hy4gl.h lib4gl.so.$(VERSION) lib4gl.$(VERSION).a
	cp hy4gl.h $(INST_DIR)
	cp lib4gl.so.$(VERSION) $(INST_DIR)
	ln -sf lib4gl.so.$(VERSION) $(INST_DIR)/lib4gl.so
	cp lib4gl.$(VERSION).a $(INST_DIR)
	ln -sf lib4gl.$(VERSION).a $(INST_DIR)/lib4gl.a
	@echo Libraries installed to $(INST_DIR)

## ==================================================================
##                              Clean
## ==================================================================

clean:
	rm -f *.o lib4gl.so.$(VERSION) lib4gl.$(VERSION).a *.bak *~

#-------------------------------- EOF -------------------------------
