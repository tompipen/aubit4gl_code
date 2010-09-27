
all:
	4glpc -t WRITE functions.4gl
	4glpc -o functions.o functions.4gl
	fglproto -w functions 
	soapcpp2 -c  prototypes.h
	4glpc -g -o server  soapC.c soapServerLib.c server.c  functions.o prototypes_server.c -lgsoap 
	4glpc -g client.c soapC.c soapClient.c -o client -lgsoap
	4glpc -g -o client_4gl testclient.4gl  soapC.c soapClient.c prototypes_client.c -lgsoap

clean:
	rm calc.add.req.xml calc.add.res.xml calc.nsmap calc.sqrt.req.xml calc.sqrt.res.xml calc.sub.req.xml calc.sub.res.xml calc.wsdl ns.xsd soapC.c soapClient.c soapClientLib.c soapH.h soapServer.c soapServerLib.c soapStub.h prototypes.h *.o *.ao client_4gl client server prototypes.c prototypes_server.c prototypes_client.c testclient.c fglserver.nsmap service.h functions.dat prototypes.unl prototypes.xml functions.c *.err *.warn *.xml fglserver.wsdl blacklist soap.nsmap

