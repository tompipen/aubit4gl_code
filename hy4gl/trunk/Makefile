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
# | contact David Prieto [davidp@sgth.es]                                |
# +----------------------------------------------------------------------+
#
# $Id: Makefile,v 1.3 2001-10-25 04:20:26 afalout Exp $

## ==================================================================
##                              Settings
## ==================================================================


# Edita el Makefile.global para cambiar el nº de version y los dirs.
# Edit file Makefile.global to change settings for your configuration.

include Makefile.global

#-Dbool
INCLPATH+=-DKEEPNCURSESBOOL
#INCLPATH+=-I.
INCLPATH+=-I$(INCL_PGRES)
#INCLPATH+=-Ilocalincl

OBJ=hy4gl.o y.tab.o lex.yy.o asa.o genera.o genrpt.o genform.o


## ==================================================================
##                              Targets
## ==================================================================

all: hy4gl.e
	@echo "Default build completed"


log:
	make > make.log 2>&1
	@echo "See make.log file for results"

.c.o:
	gcc ${INCLPATH} -g -DVERSION='"$(VERSION)"' -Wall -c $<

hy4gl.e: asa.h ${OBJ}
	gcc -g -static -DVERSION='"$(VERSION)"' -o hy4gl.e  ${OBJ} -lfl -L. -L$(LIB_PGRES) -lpq -lcrypt
	strip hy4gl.e
	$(MAKE) install


y.tab.c: sintax.y
	yacc -d -v sintax.y

lex.yy.c: lexico.l
	lex lexico.l

asa.c: asa.h asa.esa
	(hesa asa.esa; :)

asa.h:
	(hesa asa.esa; :)

lib4gl:
	$(MAKE) -C lib4gl

test:
	(cd demo; rm -f test_build.hye; hy4gl test_build.4gl -o test_build.hye; test_build.hye)


## ==================================================================
##                              Clean Targets
## ==================================================================

clean:
	rm -f *.bak *.o lex.yy* y.tab* asa.c asa.h
	rm -f *.output *.tmp *.log c.h hy4gl.e


clean.all: clean clean.lib clean.demo
	@echo "Hy4gl source tree is now clean"

clean.lib:
	cd lib4gl ; $(MAKE) clean

clean.demo:
	cd demo ; $(MAKE) clean


## ==================================================================
##              Install, release, distribution Targets
## ==================================================================

release:
	mkdir -p versiones
	mkdir -p hy4gl.$(VERSION)
	(cp * hy4gl.$(VERSION) ;:)
	mkdir -p hy4gl.$(VERSION)/demo
	mkdir -p hy4gl.$(VERSION)/doc
	mkdir -p hy4gl.$(VERSION)/lib4gl
	(cp demo/* hy4gl.$(VERSION)/demo ;:)
#	(cp doc/* hy4gl.$(VERSION)/doc ;:)
	(cp lib4gl/* hy4gl.$(VERSION)/lib4gl ; \
	tar zcvf versiones/hy4gl.$(VERSION).tgz hy4gl.$(VERSION))
	rm -rf hy4gl.$(VERSION)
	@echo "Release complete"

install:
	mkdir -p $(INST_DIR)
	cp -P hy4gl $(INST_DIR)/
	chmod +x $(INST_DIR)/hy4gl
	cp hy4gl /usr/local/bin
	chmod +x /usr/local/bin/hy4gl
	cp hy4gl.e $(INST_DIR)/hy4gl.e
	chmod +x $(INST_DIR)/hy4gl.e
#	cd lib4gl ; $(MAKE) ; $(MAKE) install
	$(MAKE) lib4gl
	$(MAKE) -C lib4gl install
	@echo "Install complete"

distrib: all
	mkdir hy4gl.$(VERSION)
	mkdir hy4gl.$(VERSION)/demo
	mkdir hy4gl.$(VERSION)/docs
	cp -v demo/* hy4gl.$(VERSION)/demo
	cp hy4gl.dist hy4gl.e install.sh CAMBIOS TODO hy4gl.$(VERSION)
	cp lib4gl/lib4gl.$(VERSION).a hy4gl.$(VERSION)
	cp lib4gl/lib4gl.so.$(VERSION) hy4gl.$(VERSION)
	cp lib4gl/hy4gl.h hy4gl.$(VERSION)
	cp doc/*.ps hy4gl.$(VERSION)/docs
	tar zcvf versiones/hy4gl-inst.$(VERSION).tgz hy4gl.$(VERSION)/
	rm -rf hy4gl.$(VERSION)
	@echo "Distrib complete"

#---------------------------- EOF -------------------------------------
