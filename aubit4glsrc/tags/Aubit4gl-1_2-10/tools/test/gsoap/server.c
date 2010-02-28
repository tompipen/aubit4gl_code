#include "soapH.h" /* get the gSOAP-generated definitions */
#include "fglserver.nsmap" /* get the gSOAP-generated namespace bindings */
#include <math.h> 

int aclfgl_run_server(int n)  
{ int m, s; /* master and slave sockets */
   int port;
  struct soap *soap = soap_new();
  if (n==0) {
    soap_serve(soap); /* serve as CGI application */
    soap_done(soap);
    free(soap);
    return 0;
  }

   port=A4GL_pop_int();
   printf("Listening on port %d\n",port);
   m = soap_bind(soap, NULL, port, 100); /* bind to the port supplied as command-line argument */
    if (m < 0)
    { soap_print_fault(soap, stderr);
      exit(-1);
    }
    fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
    for (;;)
    { s = soap_accept(soap);
      fprintf(stderr, "Socket connection successful: slave socket = %d\n", s);
      if (s < 0)
      { soap_print_fault(soap, stderr);
        exit(1);
      } 
      soap_serve(soap);
      soap_end(soap);
    }
  
  soap_done(soap);
  free(soap);
  return 0;
} 

