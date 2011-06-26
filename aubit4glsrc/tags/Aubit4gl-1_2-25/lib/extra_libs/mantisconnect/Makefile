ROOT    =../../..
include ${ROOT}/incl/Makefile-common
4GLC            =${ROOT}/bin/4glc
4GLC_SET        =export A4GL_OBJ_EXT=.o; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C;
4GLC_FLAGS      =--verbose
LINKLIBS        =-l${AUBITLIBFULL}  ${GLIB_LFLAGS} -lgsoap 
LFLAGS          = -L${ROOT}/lib
SOAPDIR		=/programs/util
XCFLAGS=${subst -DHAVE_CONFIG_H,,${CFLAGS}}
4GLC_CFLAGS     += -I. ${XCFLAGS} -DDEBUG
SOAP_URL	=http://www.aubit.com/mantis/api/soap/mantisconnect.php

#uses 'gsoap' to generate the marshalling code
# http://www.cs.fsu.edu/~engelen/soap.html
#  Check  to see if 'soapcpp2' is available
GSOAP:=$(shell type soapcpp2 2> /dev/null)
#
#

ifeq "$(GSOAP)" ""
	GSOAP:=$(shell type $(SOAPDIR)/bin/soapcpp2 2> /dev/null)

# Is it still blank ???
ifeq "$(GSOAP)" ""
		ALL=installgsoap
		#   You can try setting 
		# ALL=lib
		#   but it will need to find -lgsoap to work...
		#   If doing that - then the pregenerated stuff is needed : 
		SOAP_C=pregen/soapC.c pregen/soapClient.c
		SOAP_H=pregen/soapH.h pregen/soapStub.h pregen/MantisConnectBinding.nsmap
		XCFLAGS+=-Ipregen
else
		LFLAGS+=$(SOAPDIR)/lib
		SOAP_C=soapC.c soapClient.c
		SOAP_H=soapH.h soapStub.h MantisConnectBinding.nsmap
		ALL=lib
endif
else
                SOAP_C=soapC.c soapClient.c
                SOAP_H=soapH.h soapStub.h MantisConnectBinding.nsmap
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

$(PLUGINDIR)/liberrhook_mantis.so:  mantis.o $(SOAP_C)
	${LD} ${SO_LDFLAGS} ${XCFLAGS} -o $@ $^  ${LFLAGS} ${LINKLIBS}

mantis.c: mantis.4gl $(SOAP_H) 
	${4GLC_SET} ${4GLC} mantis.4gl

mantis.o: mantis.c
	$(CC) $(XCFLAGS) -I${ROOT}/incl -c -o $@ $^
	
soapC.o: soapC.c
	$(CC) $(XCFLAGS) -c -o $@ $^

pregen/soapC.o: pregen/soapC.c
	$(CC) $(XCFLAGS) -c -o $@ $^

soapClient.o: soapClient.c
	$(CC) $(XCFLAGS) -c -o $@ $^

pregen/soapClient.o: pregen/soapClient.c
	$(CC) $(XCFLAGS) -c -o $@ $^

mantis.wsdl:
	wget -O mantis.wsdl $(SOAP_URL)?wsdl

outfile.h: 
	wsdl2h -c  -o outfile.h $(SOAP_URL)?wsdl

soapC.c soapClient.c soapH.h: outfile.h
	soapcpp2 -1 -cLC  outfile.h
	cp soapC.c soapClient.c soapH.h soapStub.h MantisConnectBinding.nsmap pregen


clean:
	rm *.xml soapC.c  soapClient.c  soapClientLib.c  soapH.h  soapServer.c  soapServerLib.c  soapStub.h MantisConnectBinding.nsmap outfile.h mantis.c mantis.o soapC.o soapClient.o
