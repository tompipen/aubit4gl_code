/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"
#ifdef htons
	#undef htons
#endif
#ifdef htonl
	#undef htonl
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
// in a4gl_libaubit4gl.h    #include <sys/socket.h>
// in a4gl_libaubit4gl.h    #include <netinet/in.h>
// what is this for: (not on Windows) #include <arpa/inet.h>
// what is this for: (not on Windows) #include <sys/wait.h>
#include <signal.h>
// in a4gl_libaubit4gl.h    #include <netdb.h>


#if (defined(WIN32) && ! defined(__CYGWIN__))
	#define USE_WINSOCK
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

/*
=====================================================================
		                    Module Variables
=====================================================================
*/

SOCKET sock = 0;
int connected=0;
int listensock = -1;
void A4GL_init_wsock (void);

/*
=====================================================================
		                    
=====================================================================
*/


#ifdef TEST
main() {
	A4GL_start_monitor();
}
#endif


int A4GL_has_monitor() {
	return connected;
}

void A4GL_start_monitor (void)
{
  char *p;
  int port = -1;
  
  p = acl_getenv ("MONITORPORT");
  if (p==0) p="";
  A4GL_init_wsock ();
  if (p) { if (strcmp (p, "") == 0) p = 0; }
  if (p == 0)
    {
      connected=0;
	A4GL_debug("No monitoring");
      return;
    }

  port = atoport (p, "tcp");

  if (port == -1)
    {
      A4GL_exitwith ("Unable to start TCP session");
    }

  printf("Waiting on port : %d for monitor\n",port);
  sock = A4GL_get_connection (SOCK_STREAM, port, &listensock);
  printf("Got connection\n");
  if (A4GL_sock_puts (sock, "INIT\n")) connected = 1;
  else connected=0;
  printf("Connected=%d\n",connected); sleep (1);
}

void
A4GL_monitor_close (void)
{
  close (sock);
}


/**
 * Gets a port from where to act as a server using TCP.
 *  OBSOLETE
 * Tries to check by name in /etc/services and then return it as a number
 * (if valid).
 *
 * @param service The service name to found in /etc/services.
 * @param proto Protocol (normaly TCP).
 */

int
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
    {				// Not in services, maybe a number?
      lport = strtol (service, &errpos, 0);
      if ((errpos[0] != 0) || (lport < 1) || (lport > 65535))
	return -1;		// Invalid port address
      port = htons (lport);
    }
  return port;
}



/**
 * Converts ascii text to in_addr struct.
 *                      OBSOLETE
 * @param address
 * @return
 *   - NULL : The address can not be found.
 *   - Otherwise :
 */
/*
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
*/

/**
 * This function listens on a port, and returns connections.  It forks
 * returns off internally, so your main function doesn't have to worry
 * about that.  This can be confusing if you don't know what is going on.
 * The function will create a new process for every incoming connection,
 * so in the listening process, it will never return.  Only when a
 * connection
 * comes in, and we create a new process for it will the function return.
 * This means that your code that calls it should _not_ loop.
 * 
 * The parameters are as follows:
 * @param socket_type: SOCK_STREAM or SOCK_DGRAM (TCP or UDP sockets)
 * @param port: The port to listen on.  Remember that ports < 1024 are
 * reserved for the root user.  Must be passed in network byte
 * order (see "man htons").
 * @param listener: This is a pointer to a variable for holding the file
 * descriptor of the socket which is being used to listen.  It
 * is provided so that you can write a signal handler to close
 * it in the event of program termination.  If you aren't interested,
 * just pass NULL.  Note that all modern unixes will close file
 * descriptors for you on exit, so this is not required.
 *
 * @return The socket ???
 *   - -1 :
 *   - otherwise :
 */
int
A4GL_get_connection (int socket_type, u_short port, int *listener)
{

  struct sockaddr_in address;
  int listening_socket;
  int connected_socket = -1;
  int new_process;
  int reuse_addr = 1;

  memset ((char *) &address, 0, sizeof (address));
  address.sin_family = AF_INET;
	printf("Port now : %d\n",port);
  address.sin_port = port;
  address.sin_addr.s_addr = htonl (INADDR_ANY);

  listening_socket = socket (AF_INET, socket_type, 0);
  if (listening_socket < 0)
    {
      perror ("socket");
      exit (EXIT_FAILURE);
    }

  if (listener != NULL)
    *listener = listening_socket;

  setsockopt (listening_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_addr,
	      sizeof (reuse_addr));

  if (bind (listening_socket, (struct sockaddr *) &address,
	    sizeof (address)) < 0)
    {
      perror ("bind");
      close (listening_socket);
      exit (EXIT_FAILURE);
    }

  if (socket_type == SOCK_STREAM)
    {
      listen (listening_socket, 1);
      /* Queue up to five connections before
         having them automatically rejected. */

      while (connected_socket < 0)
	{
	  connected_socket = accept (listening_socket, NULL, NULL);
	  if (connected_socket < 0)
	    {
	      /* Either a real error occured, or blocking was interrupted for
	         some reason.  Only abort execution if a real error occured. */
	      if (A4GL_last_error () != EINTR)
		{
		  perror ("accept");
		  close (listening_socket);
		  exit (EXIT_FAILURE);
		}
	      else
		{
		  continue;	/* don't fork - do the accept again */
		}
	    }

	  close (listening_socket);	/* Close our copy of this socket */
	  if (listener != NULL) *listener = -1;	/* Closed in this process.  We are not responsible for it. */
	}
      return connected_socket;
    }
  else
    return listening_socket;

  return 0;

}

/**
 * This is a generic function to make a connection to a given server/port.
 *     OBSOLETE
 * @param service is the port name/number,
 * @param type is either SOCK_STREAM or SOCK_DGRAM, and
 * @param netaddress is the host name to connect to.
 * @eturn The socket, ready for action.
 */
/*
int
make_connection (service, type, netaddress)
     char *service;
     int type;
     char *netaddress;
{
  // First convert service from a string, to a number...
  int port = -1;
  struct in_addr *addr;
  int sock, connected;
  struct sockaddr_in address;

  if (type == SOCK_STREAM)
    port = atoport (service, "tcp");
  if (type == SOCK_DGRAM)
    port = atoport (service, "udp");
  if (port == -1)
    {
      fprintf (stderr, "make_connection:  Invalid socket type.\n");
      return -1;
    }
  addr = atoaddr (netaddress);
  if (addr == NULL)
    {
      fprintf (stderr, "make_connection:  Invalid network address.\n");
      return -1;
    }

  memset ((char *) &address, 0, sizeof (address));
  address.sin_family = AF_INET;
  address.sin_port = (port);
  address.sin_addr.s_addr = addr->s_addr;

  sock = socket (AF_INET, type, 0);

  printf ("Connecting to %s on port %d.\n", inet_ntoa (*addr), htons(port));

  if (type == SOCK_STREAM)
    {
      connected = connect (sock, (struct sockaddr *) &address,
			   sizeof (address));
      if (connected < 0)
	{
	  perror ("connect");
	  return -1;
	}
      return sock;
    }
  // Otherwise, must be for udp, so bind to address.
  if (bind (sock, (struct sockaddr *) &address, sizeof (address)) < 0)
    {
      perror ("bind");
      return -1;
    }
  return sock;
}
*/

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
A4GL_sock_read (int sockfd, char *buf, size_t count)
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
A4GL_sock_write_int (char *buf, size_t count)
{
	if (sock) return A4GL_sock_write(sock,buf,count);
	return 1;
}
/**
 * This is just like the write() system call, accept that it will
 * make sure that all data is transmitted.
 *
 * @param sockfd
 * @param buf
 * @param count
 * @return
 */
int
A4GL_sock_write (int sockfd, char *buf, size_t count)
{
  size_t bytes_sent = 0;
  int this_write;

  while (bytes_sent < count)
    {
      do this_write = write (sockfd, buf, count - bytes_sent);
      while ((this_write < 0) && (A4GL_last_error () == EINTR));
      if (this_write <= 0) {
			return this_write;
	}
      bytes_sent += this_write;
      buf += this_write;
    }
  return count;
}

/**
 * This function reads from a socket, until it recieves a linefeed
 * character.  It fills the buffer "str" up to the maximum size "count".
 *
 * Note that if a single line exceeds the length of count, the extra data
 * will be read and discarded!  You have been warned.
 *
 * @param sockfd The socket file descriptor.
 * @param str A pointer to the buffer where to write the information received
 * by the socket.
 * @param count The maximum size to read.
 * @return -1 if the socket is closed during the read operation or the number
 * of bytes readed.
 */
int
A4GL_sock_gets (int sockfd, char *str, size_t count)
{


  int bytes_read;
  int total_count = 0;
  char *current_position;
  char last_read = 0;
  fd_set rfds;
/* struct timeval tv; */
  int retval;


  current_position = str;

  while (last_read != 10)
    {

      FD_ZERO (&rfds);
      FD_SET (sockfd, &rfds);
      /* 
         tv.tv_sec = 1;
         tv.tv_usec = 0;
       */
      while (1)
	{

	  /* retval=select(10,&rfds,0,0,&tv); */
	  retval = 1;


	  if (retval > 0)
	    bytes_read = recv (sockfd, &last_read, 1, 0);
	  else
	    {
	      if (connected == 0)
		break;
	      continue;
	    }

	  if (bytes_read < 0 || retval < 0 || connected == 0)
	    {
	      /* The other side may have closed unexpectedly */
		connected=0;
		return;
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


int
A4GL_monitor_puts_int (char *str)
{
  if (connected) return A4GL_sock_puts (sock, str);
  else return 1;
}

/**
 * Writes a character string out to a socket.
 *
 * @return -1 if the connection is closed while it is trying to write.
 */
int
A4GL_sock_puts (int sockfd, char *str)
{
  return A4GL_sock_write (sockfd, str, strlen (str));
}


/**
 * Initialize windows sockets.
 */
void A4GL_init_wsock (void)
{
#ifdef USE_WINSOCK
  WSADATA wsaData;
  static int started = 0;
  int err;
  if (started == 0)
    {
      err = WSAStartup (MAKEWORD (1, 1), &wsaData);
      if (err)
	{
	  A4GL_assertion (1,"Error Starting Winsock");
	}
    }
  started = 1;
#endif
}

/**
 *
 * @todo Describe function
 */
int
A4GL_last_error (void)
{
  return errno;
/* return WSAGetLastError(); */
}


/* ================================ EOF ================================ */
