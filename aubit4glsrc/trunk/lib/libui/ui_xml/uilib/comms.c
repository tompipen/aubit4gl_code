/*
 *  * This program connects to the socket named in the command line
 *   * and sends a one line message to that socket.  The form of the
 *    * command line is ustreamwrite pathname.
 *     */
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>


#include "sock_xml.h"





#include <sys/time.h>


#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>



#define NOPROXY

#ifdef NOPROXY
#ifdef WIN32

#else
#endif /* win32 */
#endif /* NOPROXY */

#include "xml/attr.h"
#include "../debug.h"
#include "../pipe.h"
#include "comms.h"

#define ID_SETYOURID -122

void A4GL_set_buffer_touched(int n);
int _myId=-1; 	// myId may be set from the Proxy to tell us what descriptor its using
		// if its set - then we'll use this as our envelope ID..


void set_using_stdio(int n);
void A4GL_set_last_cursor(int n);


struct timeval tl={0,0}; // Last time the flush happend....
int something=0;

int clientui_sock_read = 0;
int clientui_sock_write = 0;

struct s_attr *last_attr = 0;

int A4GL_strstartswith(char *str, char *srch_for);
char sockbuff[20000] = "";
//static void timeout_flush_ui (void);
void A4GL_trim (char *p);


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
atoport_noproxy (char *service,char *proto)
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

	cleanup();
exit(2);
return 0;
}

static char *local_acl_getenv(char *s) {
	return getenv(s);
}

int
connect_ui (void) {
char *s;
s=local_acl_getenv("AFGLSERVER");
if (s) {
	if (strlen(s)==0) s=0;
}

if (s) {
	return connect_ui_noproxy();
} else {
	return connect_ui_proxy();
}
}

int
connect_ui_noproxy (void)
{
  //struct sockaddr_un server;
  struct sockaddr_in address;
  struct in_addr *addr;
  int rval;
  int cnt;
#ifdef __WIN32__
WSADATA wsaData;
WORD wVersionRequested=MAKEWORD(1,1);
#endif
int type=SOCK_STREAM;
int port;

  char *netport="1350";
  char *netaddress = "localhost";

#ifdef __WIN32__
WSAStartup(wVersionRequested,&wsaData);
#endif
  if (local_acl_getenv("AFGLSERVER")) {
  	   netaddress=local_acl_getenv("AFGLSERVER");
  }
  if (local_acl_getenv("AFGLPORT")) {
  	   netport=local_acl_getenv("AFGLPORT");
  }


  port= atoport_noproxy (netport, "tcp");
  addr = atoaddr (netaddress);
  if (addr==0) {
            fprintf(stderr, "Error : Unable to identify address for AFGLSERVER\n");
	cleanup();
              exit(2);
          }

  memset ((char *) &address, 0, sizeof (address));
  address.sin_family = AF_INET;
  address.sin_port = (port);
  address.sin_addr.s_addr = addr->s_addr;


  clientui_sock_read = socket (AF_INET, type, 0);
#ifdef __WIN32__
  if (clientui_sock_read ==INVALID_SOCKET )
    {
	printf("Win32.. Address : %s port=%s\n",netaddress,netport);
        perror ("opening stream socket (1)");
	cleanup();
        exit (1);
    }
#else
  if (clientui_sock_read <0 )
    {
		printf("Address : %s port=%s\n",netaddress,netport);
      perror ("opening stream socket (1)");
	cleanup();
      exit (1);
    }
#endif
  UIdebug (3, "Got socket\n");
  clientui_sock_write = clientui_sock_read;


  for (cnt = 0; cnt < 4; cnt++)
    {
#ifdef __WIN32__
      Sleep (1);
#else
      usleep (100000);
#endif
      rval = connect (clientui_sock_read, (struct sockaddr *) &address, sizeof (address));

      if (rval < 0)
	continue;
      break;
    }


  if (rval < 0)
    {
      UIdebug (3, "closing - connect failed.(%d)\n", rval);
      close (clientui_sock_read);
      return 0;
    }
  UIdebug (3, "set envelope\n");
//sleep(30);
//printf("Setting envelope mode");
  set_envelope_mode ();


  return 1;
}

int
connect_ui_proxy (void)
{
int a;
int needyourid=1;
  /* Create socket. */
  if (!getenv ("PROXYPIPE"))
    {
      UIdebug (1,"No socket specified via PROXYPIPE - running standalone\n"); fflush(stdout);
	set_using_stdio(1);
      clientui_sock_read = 0;	// STDIN
      clientui_sock_write = 1;	// STDOUT
	needyourid=0;
	//stdout=fopen("/dev/null","w");
    }
  else
    {
#ifdef __WIN32__
	printf("connect_ui_proxy -Not available for win32\n");
	exit(2);
#else
  struct sockaddr_un server;

	int rval;
	int cnt;

      clientui_sock_read = socket (AF_UNIX, SOCK_STREAM, 0);
      if (clientui_sock_read < 0)
	{
	  perror ("opening stream socket (2)");
	cleanup();
	  exit (1);
	}
	UIdebug(3,"Got socket\n");

      clientui_sock_write = clientui_sock_read;




      /* Connect socket using name specified by command line. */
      server.sun_family = AF_UNIX;
      strcpy (server.sun_path, getenv ("PROXYPIPE"));
	
      UIdebug(3,"Attempting to connect to Unix socket :%s we'll call it %d\n", server.sun_path, clientui_sock_read);

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
#endif
    }
  UIdebug(3,"set envelope\n");
  set_envelope_mode ();
if (needyourid) {
//printf("Get event from ui\n");
  // The first thing we should get back is actually from the
  // proxy should should be a yourId...
  UIdebug (1, "Waiting for TRIGGERED to set YOURID");
  a=get_event_from_ui();
  if (a!=ID_SETYOURID) {
		printf("Expecting trigger to be ID_SETYOURID (SETYOURID) - but got %d -exiting\n",a);
		exit(2);
	}
  UIdebug (1, "Got TRIGGERED setting YOURID...");
}
//printf("Got event from ui");
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


void
send_to_ui_no_nl (char *s, ...)
{
  static va_list args;
  struct timeval tn={0,0};
  char buff[1000000];
  va_start (args, s);
  vsprintf (buff, s, args);
  UIdebug (4,"[[%s]]\n", buff);
  pipe_sock_puts (clientui_sock_write, buff);
	something++;
  gettimeofday(&tn,0);
  if (tn.tv_sec-tl.tv_sec>5) {
		//timeout_flush_ui();
  		tl.tv_sec=tn.tv_sec;
  }
}


int getMyId(void) {
	UIdebug(2,"GetMyId from comms.c : %d",_myId);
	return _myId;
}

static void set_myId(int n) {
	UIdebug(2,"Setting myId=%d",n);
	_myId=n;
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

	//printf("Getting data from : clientui_sock_read=%d clientui_sock_write=%d\n", clientui_sock_read, clientui_sock_write);
 


      UIdebug (4, "Getting from buffer\n");
      if (!pipe_sock_gets (clientui_sock_read, buff, 2550))
	{
	  UIdebug (2, "PIPE CLOSED - client disconnected ?\n");
	  cleanup();
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
  			if (attr->yourId) {
				if (strlen(attr->yourId)) {
					set_myId(atol(attr->yourId));
				}
  			}
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
	      cleanup();
	      exit (1);
	    }
	  strcat (localbuff, buff);
	}

      if (strstr (localbuff, "</TRIGGERED>"))
	{

		/*
		while (1) {
			char *pingptr;
			int a;
			int b;
			// Filter out any ping - we'll deal with these later...
			pingptr=strstr(localbuff,"<PING");
			if (pingptr==0) break;
			for (a=0;;a++) {
				if (pingptr[a]=='/' && pingptr[a+1]=='>') {
					for (b=0;b<=a;b++) {
						pingptr[a]=' ';
					}
				}
			}
		}
		*/

	  	attr = xml_parse (localbuff);
  		if (attr->yourId) {
			if (strlen(attr->yourId)) {
				set_myId(atol(attr->yourId));
			}
  		}
	  free (localbuff);
	  if (attr)
	    {
	      break;
	    }
	}
    }
  

  //printf("Id=%s\n",attr->id);
  A4GL_set_last_cursor(attr->lastcursor);
  A4GL_set_buffer_touched(attr->bufferTouched);


   //printf("Got bufferTouched=%d\n", attr->bufferTouched);


  if (attr->id)
    {
      int n = -1;
      if (strcmp (attr->id, "DIE") == 0 || strcmp (attr->id, "-999") == 0)
	{
	  cleanup();
	  exit (2);
	}

      if (strcmp (attr->id, "ACCEPT") == 0)
	{
	  n = -100;
	}

      if (strcmp (attr->id, "CANCEL") == 0)
	{
	  n = -118;
	}

      if (strcmp (attr->id, "YES") == 0)
	{
	  n = -101;
	}

      if (strcmp (attr->id, "NO") == 0)
	{
	  n = -102;
	}

      if (strcmp (attr->id, "OK") == 0)
	{
	  n = -119;
	}
      if (strcmp (attr->id, "IGNORE") == 0)
	{
	  n = -120;
	}

      if (strcmp (attr->id, "RETRY") == 0)
	{
	  n = -121;
	}
      if (strcmp (attr->id, "SETYOURID") == 0)
	{
	  n = ID_SETYOURID;
	}

      if (strcmp (attr->id, "FRONTCALLRETURN") == 0)
	{
	  n = ID_FRONTCALLRETURN;
	}

      if (strcmp (attr->id, "FILEREQUEST") == 0)
	{
	  n = -103;
	}

      if (strcmp (attr->id, "RETURN") == 0)
	{
	  n = -110;
	}

      if (strcmp (attr->id, "EXEC") == 0)
	{
		char buff[2000];
		sprintf(buff,"%s &", attr->programname);
            //printf("----> EXEC %s\n", buff);
            system(buff);
              n=-105;
	}


      if (strcmp (attr->id, "EXECWAIT") == 0)
	{
		char buff[2000];
		sprintf(buff,"%s", attr->programname);
            	system(buff);
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
	cleanup();
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

/*
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
*/


