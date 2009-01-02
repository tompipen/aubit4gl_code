ROOT    =../../..
include ${ROOT}/incl/Makefile-common
4GLC            =${ROOT}/bin/4glc
4GLC_SET        =export A4GL_OBJ_EXT=.o; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C;
4GLC_FLAGS      =--verbose
LINKLIBS        =-l${AUBITLIBFULL}  ${GLIB_LFLAGS} -lgsoap
LFLAGS          = -L${ROOT}/lib
XCFLAGS=${subst -DHAVE_CONFIG_H,,${CFLAGS}}
4GLC_CFLAGS     += -I. ${XCFLAGS} -DDEBUG
SOAP_URL	=http://www.aubit.com/mantis/api/soap/mantisconnect.php

#uses 'gsoap' to generate the marshalling code
# http://www.cs.fsu.edu/~engelen/soap.html
#  Check  to see if 'soapcpp2' is available
GSOAP:=$(shell type soapcpp2 2> /dev/null)
#
ifeq "$(GSOAP)" ""
	ALL=installgsoap
else
	ALL=lib
endif





all: $(ALL)


info:
	echo $(GSOAP)
	echo "All=$(ALL)"

installgsoap:
	@echo "You must install gsoap to use this library"
	@echo "Available from http://www.cs.fsu.edu/~engelen/soap.html"

lib: $(PLUGINDIR)/liberrhook_mantis.so
$(PLUGINDIR)/liberrhook_mantis.so: soapC.o mantis.o soapClient.o
	${LD} ${SO_LDFLAGS} ${XCFLAGS} -o $@ $^  ${LFLAGS} ${LINKLIBS}

mantis.c: mantis.4gl
	${4GLC_SET} ${4GLC} mantis.4gl

mantis.o: mantis.c
	$(CC) $(XCFLAGS) -I${ROOT}/incl -c -o $@ $^
	
soapC.o: soapC.c
	$(CC) $(XCFLAGS) -c -o $@ $^

soapClient.o: soapClient.c
	$(CC) $(XCFLAGS) -c -o $@ $^

mantis.wsdl:
	wget -O mantis.wsdl $(SOAP_URL)?wsdl

outfile.h: 
	wsdl2h -c  -o outfile.h $(SOAP_URL)?wsdl

soapC.c soapClient.c: outfile.h
	soapcpp2 -1 -cLC  outfile.h


clean:
	rm *.xml soapC.c  soapClient.c  soapClientLib.c  soapH.h  soapServer.c  soapServerLib.c  soapStub.h MantisConnectBinding.nsmap outfile.h mantis.c mantis.o soapC.o soapClient.o
