
ZLIB=-DHAVE_ZLIB 
CFLAGS=-g -fPIC -I.  -I../../../incl -DA4GL_EXPR_H -Wall $(ZLIB) #-DHAVE_ZLIB


HAVE_FLEXML:=$(shell type flexml 2> /dev/null)
HAVE_EXTFLEX:=$(shell type ${AUBITDIR}/compilers/4glc/xml/extflex/bin/flex 2> /dev/null)

USE_PREGEN=Y
ifneq "$(HAVE_FLEXML)" ""
ifneq "$(HAVE_EXTFLEX)" ""
USE_PREGEN=N
endif
endif



all: module_def.dtd libPACKER_XMLBEST.so 


%.o : %c
	$(CC) -c $<
fgl.setparent.o: fgl.setparent.c 
	$(CC) $(CFLAGS) -c $<

libPACKER_XMLBEST.so: pack_xml.o fgl.xo.o overloads.h overloads.o module_def.o lex.yy.o stack.o fgl.setparent.o  overloads_read.o
	$(CC) $(CFLAGS) -shared -fPIC -I../../../incl pack_xml.o fgl.xo.o overloads.o module_def.o lex.yy.o stack.o fgl.setparent.o overloads_read.o -o `aubit-config DEFAULT_PLUGINDIR`/libPACKER_XMLBEST.so 



fgl.x: ../../../common/dataio/fgl.x
	cp ../../../common/dataio/fgl.x .
	
${AUBITDIR}/bin/xgen_new:
	cd ${AUBITDIR}/compilers/xgen_new && make

fgl.xo.c fgl.xoh.h fgl.attlist.dtd fgl.setparent.c: fgl.x ${AUBITDIR}/bin/xgen_new
	${AUBITDIR}/bin/xgen_new fgl.x

module_def.dtd: fgl.attlist.dtd fgl.elements.dtd  default.dtd
		cat default.dtd fgl.attlist.dtd fgl.elements.dtd | sort -k2 -k1r | awk '(NF) {print }'  > module_def.dtd
	
module_def.act: module_def.top.act  fgl.start.act fgl.end.act module_def.tail.act
	cat $^ > $@

module_def.o: module_def.h module_def.c
	$(CC) -c -rdynamic $(CFLAGS) module_def.c

lex.yy.o: lex.yy.c pack_xml.h
	$(CC) $(CFLAGS) -c lex.yy.c

check:
	xmllint --noout --valid cbenD.obj

clean : 
	rm *.o lex.yy.c module_def.c fgl.xo.c fgl.setparent.c fgl.end.act fgl.start.act module_def.act module_def.h fgl.xh.h fgl.xoh.h  fgl.attlist.dtd fgl.elements.dtd  module_def.dtd module_def.l reload libPACKER_XMLBEST.so

test:
	echo "HAVE_FLEXML"="$(HAVE_FLEXML)"



ifeq "$(USE_PREGEN)" "Y"
include Makefile.noflexml
else
include Makefile.flexml
endif
