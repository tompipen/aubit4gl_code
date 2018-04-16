#include "soapH.h" // obtain the generated stub 
#include "fglserver.nsmap" // obtain the generated XML namespace mapping table for the Quote service 
main() 
{ 
   struct soap *soap = soap_new();
   long id;
   if (soap_call_ns__get_tabid(soap, "http://localhost:9090", "get_tabid", "syscolumns", &id) == SOAP_OK) 
      printf("Tabid = %ld\n", id);
   else // an error occurred 
      soap_print_fault(soap, stderr); // display the SOAP fault on the stderr stream 
}
