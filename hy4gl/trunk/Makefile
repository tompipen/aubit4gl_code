# Edita el Makefile.global para cambiar el nº de version y los dirs.
include Makefile.global

all: hy4gl.e
	
.c.o: 
	gcc -g -DVERSION='"$(VERSION)"' -Wall -c $<  -I$(INCL_PGRES)

hy4gl.e:  asa.o hy4gl.o y.tab.o lex.yy.o  genera.o genrpt.o genform.o
	gcc -g -static -DVERSION='"$(VERSION)"' -o hy4gl.e  \
		hy4gl.o y.tab.o lex.yy.o asa.o genera.o genrpt.o genform.o \
                -lfl -L. -L$(LIB_PGRES) -lpq -lcrypt
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

clean:
	rm -f *.bak *.o lex.yy* y.tab* asa.c asa.h
	cd lib4gl ; $(MAKE) clean

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
   		
install: 
	mkdir -p $(INST_DIR)
	cp -P hy4gl $(INST_DIR)/
	chmod +x $(INST_DIR)/hy4gl
	cp hy4gl /usr/local/bin
	chmod +x /usr/local/bin/hy4gl
	cp hy4gl.e $(INST_DIR)/hy4gl.e
	chmod +x $(INST_DIR)/hy4gl.e
	cd lib4gl ; $(MAKE) ; $(MAKE) install


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
