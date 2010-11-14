ROOT    =../..
LIBROOT	=${ROOT}/lib
BINROOT	=${ROOT}/bin

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}


#Targets we can compile in any case
ALL             = $(BINROOT)/wsdl2fgl
				
ifeq "${TARGET_OS}" "solaris"
	CFLAGS+=-DSOLARIS
endif
CFLAGS+=-Wall


all: ${ALL} 
	@echo "Default targets (${ALL}) compiled."

%.o:%.c
	${CC} ${CFLAGS_NOWARN} -c $<


y.tab.o : simple.yacc 
	${BISON} -y -t -d -v $<
	$(CC) ${CFLAGS_NOWARN} -g -c y.tab.c

lex.yy.c: simple.lex
	${LEX} -i $<

$(BINROOT)/wsdl2fgl: main.o y.tab.o lex.yy.o structs.o
	$(CC) -o $(BINROOT)/wsdl2fgl main.o y.tab.o lex.yy.o structs.o $(LINKLIBS)


Client_4gl.c: fglserver.wsdl $(BINROOT)/wsdl2fgl
	wsdl2fgl fglserver.wsdl

soapClient.c soapC.c: fglserver.h
	soapcpp2 -n -w -x -c -C fglserver.h

testclient: Client_4gl.c soapC.c soapClient.c
	4glpc -g -o client_4gl testclient.4gl  soapC.c soapClient.c Client_4gl.c -lgsoap


clean: 
	rm $(BINROOT)/wsdl2fgl lex.yy.c lex.yy.o y.tab.o main.o structs.o y.tab.o *.ao *.o *.xml fglserver.nsmap fglserver.h y.output  y.tab.c  y.tab.h testclient.c soapStub.h soapH.h soapClientLib.c soapClient.c soapC.c client_4gl Client_4gl.c



