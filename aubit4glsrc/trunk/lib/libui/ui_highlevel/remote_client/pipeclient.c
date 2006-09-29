#include "a4gl_libaubit4gl_int.h"
#include "ui_lowlevel.h"
#ifdef htons
#undef htons
#endif
#ifdef htonl
#undef htonl
#endif

#include <stdio.h>
#include <stdlib.h>
#ifndef MSVC
#include <unistd.h>
#endif
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

#if (defined(WIN32) && ! defined(__CYGWIN__))
#define USE_WINSOCK
int A4GL_get_connection (int socket_type, u_short port, int *listener);
#endif

#ifndef USE_WINSOCK
#define SOCKET int
#endif

#ifdef USE_WINSOCK
#ifndef EINTR
#define EINTR WSAEINTR
#endif
#endif

#include <errno.h>		/* EINTR */



#include "pipeclient.h"
static struct in_addr *internal_atoaddr (char *address);
static int internal_atoport (char *service, char *proto);

#define STREAM_BUFF_SIZE 10240

char sock_buff[20000]="";

int serversocket = 0;

static struct in_addr *
internal_atoaddr (char *address)
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
  return (struct in_addr *) 0;
}


int
pipe_sock_gets (int sockfd, char *str, size_t count)
{


  int bytes_read;
  int total_count = 0;
  char *current_position;
  char last_read = 0;
  fd_set rfds;
  int retval;

  current_position = str;

  while (last_read != 10)
    {

      FD_ZERO (&rfds);
      FD_SET (sockfd, &rfds);
      while (1)
	{

	  retval = 1;


	  if (retval > 0)
	    {
	      bytes_read = recv (sockfd, &last_read, 1, 0);
	    }
	  else
	    {
	      continue;
	    }

	  if (bytes_read <= 0 || retval < 0)
	    {

	      return 0;
	    }

	  if (bytes_read)
	    break;

	}
      if ((total_count < count) && (last_read != 10) && (last_read != 13))
	{
	  current_position[0] = last_read;
	  current_position++;
	  total_count++;
	}
    }
  if (count > 0)
    current_position[0] = 0;
  return total_count;
  return 0;
}


static int
pipe_make_connection (char *service, char *netaddress)
{
  // First convert service from a string, to a number...
  int port = -1;
  struct in_addr *addr;
  int sock, connected;
  struct sockaddr_in address;

  port = internal_atoport (service, "tcp");


  if (port == -1)
    {
      FPRINTF (stderr, "make_connection:  Invalid socket type.\n");
      return 0;
    }
  if (netaddress == 0)
    {
      // No host to connect to....
      return 0;
    }
  addr = internal_atoaddr (netaddress);

  if (addr == NULL)
    {
      FPRINTF (stderr, "make_connection:  Invalid network address.\n");
      return 0;
    }

  memset ((char *) &address, 0, sizeof (address));
  address.sin_family = AF_INET;
  address.sin_port = (port);
  address.sin_addr.s_addr = addr->s_addr;

  sock = socket (AF_INET, SOCK_STREAM, 0);

  PRINTF ("Connecting to %s on port %d.\n", inet_ntoa (*addr), htons (port));

  connected = connect (sock, (struct sockaddr *) &address, sizeof (address));
  if (connected < 0)
    {
      perror ("connect");
      return 0;
    }

  return sock;
}

static int
internal_atoport (char *service, char *proto)
{
  int port;
  long int lport;
  struct servent *serv;
  char *errpos;

  // First try to read it from /etc/services
  serv = getservbyname (service, proto);
  if (serv != NULL)
    port = serv->s_port;
  else
    {				// Not in services, maybe a number?
      lport = strtol (service, &errpos, 0);
      if ((errpos[0] != 0) || (lport < 1) || (lport > 65535))
	return -1;		// Invalid port address
      port = htons (lport);
    }
  return port;
}


/**
 * This is just like the read() system call, accept that it will make
 * sure that all your data goes through the socket.
 *
 * @param sockfd
 * @param buf
 * @param count
 * @return The number of byted read.
 */
int
pipe_sock_read (int sockfd, char *buf, size_t count)
{
  size_t bytes_read = 0;
  int this_read;

  while (bytes_read < count)
    {
      do
	this_read = read (sockfd, buf, count - bytes_read);
      while ((this_read < 0) && (A4GL_last_error () == EINTR));
      if (this_read < 0)
	return this_read;
      else if (this_read == 0)
	return bytes_read;
      bytes_read += this_read;
      buf += this_read;
    }
  return count;
}

int
pipe_sock_write (int sockfd, char *buf, size_t count)
{
  size_t bytes_sent = 0;
  int this_write;

  while (bytes_sent < count)
    {
      do
	{
	  this_write = write (sockfd, buf, count - bytes_sent);
	}
      while ((this_write < 0) && (A4GL_last_error () == EINTR));
      if (this_write <= 0)
	{
	  return this_write;
	}
      bytes_sent += this_write;
      buf += this_write;
    }
  return count;
}



/* this isn't a real socket flush - just emptying our buffer... */
int pipe_flush(int sockfd) {
	if (strlen(sock_buff)) {
		pipe_sock_puts(sockfd,0);
	}
}

/**
 *  * Writes a character string out to a socket.
 *   *
 *    * @return -1 if the connection is closed while it is trying to write.
 *    * str=0 means flush.....
 *     */
int
pipe_sock_puts (int sockfd, char *str)
{
	int sz_buff;
	int sz_str=0;
	int ok=1;

	sz_buff=strlen(sock_buff);
	if (str) {
		sz_str=strlen(str);
	}

	// Do we need to send what we've got ? 
	if (sz_buff>STREAM_BUFF_SIZE || sz_str+sz_buff>STREAM_BUFF_SIZE || sz_str>STREAM_BUFF_SIZE || str==0) { // Yes - i know if sz_str>STREAM_BUFF_SIZE then sz_str+sz_buff>STREAM_BUFF_SIZE anyway...
		if (str!=0) {
			printf("BUFFER FULL ;-) %d %d\n",sz_buff,sz_str);
		}
		printf("SENDING CACHE :\n----'%s'\n\n----\n",sock_buff);
	  	ok=pipe_sock_write (sockfd, sock_buff, strlen (sock_buff));
		sz_buff=0;
		strcpy(sock_buff,"");
	}

	if (str==0) {
		fsync(sockfd);
		return 1;
	}

	if (sz_str>STREAM_BUFF_SIZE) {
		// Its too large to cache...
		if (ok) {
			printf("SENDING NEW :\n----'%s'\n\n----\n",str);
	  		ok=pipe_sock_write (sockfd, str, strlen (str));
		}
		return ok;
	
	}
	//printf("ADDING TO CACHE : '%s'\n",str);
	strcat(sock_buff,str);

  return ok;
}


char *
client_encode_list_of_fields (list_of_fields * p)
{
  int a;
  static char *buff = 0;
  char *buff2 = 0;
  char smbuff[256];

  if (buff)
    {
      free (buff);
      buff = 0;
    }

  if (p->a.a_len)
    {

      for (a = 0; a < p->a.a_len; a++)
	{
	  sprintf (smbuff, "%ld", p->a.a_val[a]);
	  if (a == 0)
	    {
	      buff = malloc (strlen (smbuff) + 10);	// Allow extra for the trailing NULL and the ) thats appended later
	      sprintf (buff, "(%s", smbuff);
	    }
	  else
	    {
	      buff2 = malloc (strlen (buff) + 10 + strlen (smbuff));	// Allow extra for the trailing NULL and the ) thats appended later
	      sprintf (buff2, "%s,%s", buff, smbuff);
	      free (buff);
	      buff = buff2;
	    }
	}
      strcat (buff, ")");
      return buff;
    }
  else
    {
      return "(0)";
    }
}


// Encode a string so its safe to pass over the
// network
char *
client_encode_string (char *ptr)
{
  static char *buff = 0;
  char smbuff[3];
  int l;
  int a;
  static int maxlen = 0;
  l = strlen (ptr);
  A4GL_debug ("Encoding : %s\n", ptr);
  if (l > maxlen)
    {
      buff = realloc (buff, (l * 2) + 1);
      maxlen = l;
    }

  // We could use some fancy base64 encoding here..
  // but for now - we'll just send it as hex...
  strcpy (buff, "");
  for (a = 0; a < strlen (ptr); a++)
    {
      sprintf (smbuff, "%02X", ptr[a]);
      strcat (buff, smbuff);
    }
  A4GL_debug ("Encoding : %s -> %s\n", ptr, buff);
  return buff;
}


int
pipe_expect (char *s)
{
  char buff[256];
  int a;
  memset (buff, 0, sizeof (buff));

  pipe_flush(serversocket);
  printf("Expect...\n");
  pipe_sock_gets (serversocket, buff, 255);

  if (strcmp (buff, s) != 0)
    {
      printf ("Expecting %s - got '%s'\n", s, buff);
      for (a=0;a<17;a++) {
	      	printf("(%02x %c) ",buff[a]&0xff, isprint(buff[a])?buff[a]:'.');
      }
      printf("\n");
      return 0;
    }
  else
    {
	    printf("Got expected : '%s','%s'\n",buff,s);
      return 1;
    }

}

static int
handshake ()
{
  char buff[256];
  A4GL_debug ("Handshaking\n");
  if (!pipe_expect ("WELCOME")) {
  	if (!pipe_expect ("WELCOME")) {
    		return 0;
	}
  }
  pipe_sock_puts (serversocket, "PROTOCOL 1\n"); pipe_flush(serversocket);
  if (!pipe_expect ("OK"))
    return 0;

  sprintf (buff, "NAME %s\n", A4GL_get_running_program ()); 
  pipe_sock_puts (serversocket, buff); pipe_flush(serversocket);
  if (!pipe_expect ("OK"))
    return 0;


  A4GL_debug ("handshake OK\n");
  return 1;
}

int
client_connect (char *host, char *p)
{
  char buff[2000];
  serversocket = pipe_make_connection (p, host);
  if (serversocket == 0)
    {
      printf ("Couldn't connect...\n");
      return 0;
    }

  if (!handshake ())
    {
      return 0;
    }


  // Opened...
  return 1;
}

int
decode_hex (char c)
{
  switch (c)
    {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;

    case 'a':
    case 'A':
      return 10;

    case 'b':
    case 'B':
      return 11;

    case 'c':
    case 'C':
      return 12;

    case 'd':
    case 'D':
      return 13;

    case 'e':
    case 'E':
      return 14;

    case 'f':
    case 'F':
      return 15;
    }
  return 0;
}

char *
client_decode_str (char *ptr)
{
  char *p;
  int a;
  int b = 0;
  int l;
  p = malloc ((strlen (ptr) / 2) + 1);

  for (a = 0; a < strlen (ptr); a += 2)
    {
      l = decode_hex (ptr[a]) * 16;
      l += decode_hex (ptr[a + 1]);
      p[b++] = l;
    }

  p[b] = 0;
  return p;
}


struct client_result *
pipe_get_result (char *func,struct client_result *r,int expectresult)
{
  char buff[2000];
  if (!expectresult) {
	      r->result = 0;
	      r->state = CALL_RESULT;
              A4GL_debug ("Function should return with no value\n");
              return r;
  }

  printf("%s is causing flush\n",func);
  pipe_flush(serversocket);

  while (1)
    {

      if (pipe_sock_gets (serversocket, buff, sizeof (buff)) == 0)
	{
	  A4GL_exitwith ("Invalid response - did the client die ?");
	  printf ("Invalid response - did the client die ?\n");
	  exit (2);
	}
     printf(">>>%s\n",buff);
      r->result = 0;


      if (strcmp (buff, "OK") == 0)
	{
	  r->result = 0;
	  r->state = CALL_RESULT;
	  A4GL_debug ("Function returned with no value\n");
	  return r;
	}

      if (strncmp (buff, "RETURN INT", 10) == 0)
	{
	  char *b;
	  b = &buff[11];
	  r->result = atol (b);
	  r->state = CALL_RESULT;
	  A4GL_debug ("Got int : %d\n", r->result);
	  return r;
	}

      if (strncmp (buff, "RETURN STR", 10) == 0)
	{
	  char *b;
	  b = &buff[11];
	  r->result = (long) client_decode_str (b);
	  r->state = CALL_RESULT_MALLOC;
	  A4GL_debug ("Got string : %s\n", r->result);
	  return r;
	}


      printf ("Unexpected return...");

    }
  return r;

}

struct client_result *
client_call (char *func, int expectresult, char *fmt, ...)
{
  va_list ap;
  struct client_result *r;
  int a;
  static char buff[20000];
  static char smbuff[20000];
  struct list_of_fields *lo;
  char *ptr;
  long l;

  init_client ();


  if (serversocket == 0)
    {
      A4GL_exitwith ("Not connected");
      exit (1);
      return 0;
    }
  r = malloc (sizeof (struct client_result));
  r->func = strdup (func);
  r->state = INITIALIZED;
  r->result = 0;
  A4GL_debug("CALL %s - expectresult=%d\n",func,expectresult);
  sprintf (buff, "CALL %s %s", func, fmt);

  if (strlen (fmt))
    {
      va_start (ap, fmt);
      for (a = 0; a < strlen (fmt); a++)
	{
	  strcpy (smbuff, "?");

	  switch (fmt[a])
	    {
	    case 's':
	      ptr = va_arg (ap, char *);
	      strcpy (smbuff, client_encode_string (ptr));
	      break;
	    case 'i':
	      l = va_arg (ap, long);
	      sprintf (smbuff, "%ld", l);
	      break;

	    case 'I':
	      lo = va_arg (ap, list_of_fields *);
	      strcpy (smbuff, client_encode_list_of_fields (lo));
	      break;
	    default:
	      printf ("Unrecognised format for call : '%c'\n", fmt[a]);
	      A4GL_assertion (1, "Bomb");
	      break;
	    }
	  strcat (buff, " ");
	  strcat (buff, smbuff);

	}
      va_end (ap);
    }

  strcat (buff, "\n");
  if (!pipe_sock_puts (serversocket, buff))
    {
      A4GL_exitwith ("Socket write failed");
      return 0;
    }
  return pipe_get_result (func,r,expectresult);
}






int
client_result_ok (struct client_result *result)
{
  if (result == 0)
    return 0;
  if (result->state == CALL_RESULT)
    return 1;
  if (result->state == CALL_RESULT_MALLOC)
    return 1;

  return 0;
}



void
client_get_value (struct client_result *result, char *fmt, void *p)
{
  //printf ("Get Value : %s\n", fmt);
  if (strcmp (fmt, "i") == 0)
    {
      *(long *) p = result->result;
    }
  if (strcmp (fmt, "s") == 0)
    {
      *(char **) p = (char *) result->result;
    }
  //printf ("Fmt=%s\n", fmt);
}



void
client_free_result (struct client_result *result)
{
  //printf ("free result : %p\n", result);
  free (result->func);
  if (result->state == CALL_RESULT_MALLOC)
    {
      free ((void *) result->result);
    }
  free (result);
}
