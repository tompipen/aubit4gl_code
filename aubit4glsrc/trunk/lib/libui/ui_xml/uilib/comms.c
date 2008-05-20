/*
 *  * This program connects to the socket named in the command line
 *   * and sends a one line message to that socket.  The form of the
 *    * command line is ustreamwrite pathname.
 *     */
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


#define NOPROXY

#ifdef NOPROXY
#include <netinet/in.h>
#include <netdb.h>
#endif

#include "xml/attr.h"
#include "../debug.h"
#include "../pipe.h"
#include "comms.h"
struct timeval tl={0,0}; // Last time the flush happend....
int something=0;

int clientui_sock_read = 0;
int clientui_sock_write = 0;

struct s_attr *last_attr = 0;

char sockbuff[20000] = "";
static void timeout_flush_ui (void);


#ifdef NOPROXY
/**
 * Gets a port from where to act as a server using TCP.
 * Tries to check by name in /etc/services and then return it as a number
 * (if valid).
 *
 * @param service The service name to found in /etc/services.
 * @param proto Protocol (normaly TCP).
 */

static int
atoport (char *service,char *proto)
{
  int port;
  long int lport;
  struct servent *serv;
  char *errpos;

  // First try to read it from /etc/services
  serv = getservbyname (service, proto);
  if (serv != NULL) port = serv->s_port;
  else
    {                           // Not in services, maybe a number?
      lport = strtol (service, &errpos, 0);
      if ((errpos[0] != 0) || (lport < 1) || (lport > 65535))
        return -1;              // Invalid port address
      port = htons (lport);
    }
  return port;
}

static struct in_addr *
atoaddr (char *address)
{
  struct hostent *host;
  static struct in_addr saddr;

  // First try it as aaa.bbb.ccc.ddd.
  saddr.s_addr = inet_addr (address);
  if (saddr.s_addr != -1)
    {
      return &saddr;
    }
  host = gethostbyname (address);
  if (host != NULL)
    {
      return (struct in_addr *) *host->h_addr_list;
    }
  return (struct in_addr *)0;
}

#endif


int
get_ui_id (char c)
{
  if (c == 'r')
    {
      return clientui_sock_read;
    }
  if (c == 'w')
    {
      return clientui_sock_write;
    }
UIdebug(0,"No 'r' or 'w' for get_ui_id");
exit(2);
return 0;
}

static char *local_acl_getenv(char *s) {
	return getenv(s);
}

int
connect_ui (void) {
if (local_acl_getenv("AFGLSERVER")) {
	return connect_ui_noproxy();
} else {
	return connect_ui_proxy();
}
}

int
connect_ui_noproxy (void)
{
  struct sockaddr_un server;
  struct sockaddr_in address;
  struct in_addr *addr;
  int rval;
  int cnt;
int type=SOCK_STREAM;
int port;
  char *netport="1300";
  char *netaddress = "localhost";


  if (local_acl_getenv("AFGLSERVER")) {
  	   netaddress=local_acl_getenv("AFGLSERVER");
  }
  port= atoport (netport, "tcp");
  addr = atoaddr (netaddress);
  if (addr==0) {
            fprintf(stderr, "Error : Unable to identify address for AFGLSERVER\n");
              exit(2);
          }

  memset ((char *) &address, 0, sizeof (address));
  address.sin_family = AF_INET;
  address.sin_port = (port);
  address.sin_addr.s_addr = addr->s_addr;


  clientui_sock_read = socket (AF_INET, type, 0);
  if (clientui_sock_read < 0)
    {
      perror ("opening stream socket");
      exit (1);
    }
  UIdebug (3, "Got socket\n");
  clientui_sock_write = clientui_sock_read;


  for (cnt = 0; cnt < 4; cnt++)
    {
      usleep (100000);
      rval = connect (clientui_sock_read, (struct sockaddr *) &address, sizeof (address));

      if (rval < 0)
	continue;
      break;
    }


  if (rval < 0)
    {
      UIdebug (3, "closing - connect to %s failed.(%d)\n", server.sun_path, rval);
      close (clientui_sock_read);
      return 0;
    }
  UIdebug (3, "set envelope\n");
  set_envelope_mode ();

  return 1;
}

int
connect_ui_proxy (void)
{
  struct sockaddr_un server;

  /* Create socket. */
  if (!getenv ("PROXYPIPE"))
    {
      UIdebug (1,"No socket specified via PROXYPIPE - running standalone\n"); fflush(stdout);
      clientui_sock_read = 0;	// STDIN
      clientui_sock_write = 2;	// STDOUT
    }
  else
    {

	int rval;
	int cnt;

      clientui_sock_read = socket (AF_UNIX, SOCK_STREAM, 0);
      if (clientui_sock_read < 0)
	{
	  perror ("opening stream socket");
	  exit (1);
	}
	UIdebug(3,"Got socket\n");
      clientui_sock_write = clientui_sock_read;




      /* Connect socket using name specified by command line. */
      server.sun_family = AF_UNIX;
      strcpy (server.sun_path, getenv ("PROXYPIPE"));
	
	for (cnt=0;cnt<4;cnt++) {
      		usleep(100000);
      		rval=connect (clientui_sock_read, (struct sockaddr *) &server, sizeof (struct sockaddr_un));
		if (rval<0) continue;
		break;
	}


      if (rval<0) 
	{
		UIdebug(3,"closing - connect to %s failed.(%d)\n",server.sun_path,rval);
	  	close (clientui_sock_read);
	  	return 0;
	}
    }
  UIdebug(3,"set envelope\n");
  set_envelope_mode ();

  return 1;
}







void
send_to_ui (char *s, ...)
{
  static va_list args;
  struct timeval tn={0,0};
  char buff[20000];
  va_start (args, s);
  vsprintf (buff, s, args);
  strcat (buff, "\n");
  UIdebug (4,"[[%s]]\n", buff);
  pipe_sock_puts (clientui_sock_write, buff);
	something++;
  gettimeofday(&tn,0);
  if (tn.tv_sec-tl.tv_sec>5) {
		//timeout_flush_ui();
  		tl.tv_sec=tn.tv_sec;
  }
}





int
get_event_from_ui ()
{
  char buff[25600];
  char *localbuff = 0;
  int l = 0;
  struct s_attr *attr = 0;

  last_attr = 0;
  UIdebug (4, "Get_event_from_ui\n");

  while (1)
    {
      UIdebug (4, "Getting from buffer\n");
      if (!pipe_sock_gets (clientui_sock_read, buff, 2550))
	{
	  UIdebug (2, "PIPE CLOSED - client disconnected ?\n");
	  exit (0);
	}


      if (localbuff == 0)
	{
	  // This is our first line- is it a single line 'TRIGGERED' ? 
	  //      
	  localbuff = strstr (buff, "<TRIGGERED");
	  if (localbuff)
	    {
	      l = strlen (localbuff);
	      // Well - its a good start - does it and in /> ? 
	      if (localbuff[l - 2] == '/' && localbuff[l - 1] == '>')
		{
		  // Even better - final check - we should have any extra
		  // starting tags - so we don't wabt to see any '<' after the first one..
		  //
		  if (!strchr (&localbuff[1], '<'))
		    {
		      // Cool - its a single line triggered...
		      UIdebug (5, "Single line trigger : %s\n", buff);
		      attr = xml_parse (localbuff);
		      break;
		    }
		}
	    }
	  if (strlen (buff))
	    {
	      localbuff = strdup (buff);
	      A4GL_trim (localbuff);

	      if (strlen (buff) == 0)
		{
		  free (localbuff);
		  localbuff = 0;
		}
	    }
	  if (localbuff == 0)
	    continue;
	}
      else
	{
	  //UIdebug (5, "l=%d localbuff=%p '%s' buff='%s'\n", l, localbuff, localbuff, buff);
	  l = strlen (localbuff);
	  l += strlen (buff);
	  //UIdebug (5, "l=%d localbuff=%p\n", l, localbuff);

	  localbuff = realloc (localbuff, l + 10);
	  if (localbuff == 0)
	    {
	      UIdebug (0, "Unable to allocate memory");
	      exit (1);
	    }
	  strcat (localbuff, buff);
	}

      if (strstr (localbuff, "</TRIGGERED>"))
	{
	  attr = xml_parse (localbuff);
	  free (localbuff);
	  if (attr)
	    {
	      break;
	    }
	}
    }


  printf("Id=%s\n",attr->id);

  if (attr->id)
    {
      int n = -1;
      if (strcmp (attr->id, "DIE") == 0 || strcmp (attr->id, "-999") == 0)
	{
	  exit (2);
	}

      if (strcmp (attr->id, "ACCEPT") == 0)
	{
	  n = -100;
	}

      if (strcmp (attr->id, "CANCEL") == 0)
	{
	  n = -100;
	}
      if (strcmp (attr->id, "YES") == 0)
	{
	  n = -101;
	}
      if (strcmp (attr->id, "NO") == 0)
	{
	  n = -102;
	}
      if (strcmp (attr->id, "FILEREQUEST") == 0)
	{
	  n = -103;
	}
      if (strcmp (attr->id, "EXEC") == 0)
	{
            printf("----> EXEC %s\n", attr->programname);
            system(attr->programname);
              n=-105;
	}

      if (strcmp (attr->id, "INTERRUPT") == 0)
	{
	  n = -101;

	}

      if (n == -1)
	{
	  n = atoi (attr->id);
	}


      last_attr = attr;
      return n;
    }

  UIdebug (0, "End of get_event_from_ui - shouldn't happen");
  exit (2);
}


void
flush_ui ()
{
  UIdebug (4,"FLUSH UI : %d\n",clientui_sock_write);
  pipe_flush (clientui_sock_write);
  UIdebug(4,"flushed UI\n");
  gettimeofday(&tl,0);
	something=0;
}


static void timeout_flush_ui ()
{
  UIdebug (4,"FLUSH UI : %d\n",clientui_sock_write);
  if (something) {
    printf("TIMEOUT FLUSH : \n");
    timeout_flush (clientui_sock_write);
    UIdebug(4,"flushed UI\n");
	something=0;
  }
  gettimeofday(&tl,0);
}



