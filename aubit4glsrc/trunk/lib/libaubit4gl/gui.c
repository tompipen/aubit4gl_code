/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: gui.c,v 1.8 2002-05-26 06:26:49 afalout Exp $
#
*/

/**
 * @file
 * GUI interface implementations
 *
 * The user interface functions pass allways from here.
 *
 * There is work to be done in this module in order to change it to work
 * like SQL library with several interfaces:
 *   - Curses
 *   - GTK
 *   - Thin client using TCP
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

 /*
=====================================================================
                    Constants definitions
=====================================================================
*/

#ifdef WIN32
	#ifndef __CYGWIN__
		#define USE_WINSOCK
	#endif
#endif

#ifndef USE_WINSOCK
	#define SOCKET int
#endif

#ifdef USE_WINSOCK
	#ifndef EINTR
		#define EINTR WSAEINTR
	#endif
#endif

#ifdef USE_GTK
	#define HAS_GTK 1
	#define START_HAS_GTK if (ui_mode==UI_MODE_GTK) {
	#define END_HAS_GTK }
#endif


/*
=====================================================================
		                    Includes
=====================================================================
*/

//obsolete #include <arpa/inet.h> //for inet_addr()

#include <unistd.h> //close() write()

#ifndef WIN32
	#include <sys/time.h>
#endif

#ifdef __CYGWIN__
	#include <sys/time.h>
#endif


#include "a4gl_dbform.h"
#include "a4gl_sockhelp.h"
#include "a4gl_debug.h"
#include "a4gl_runtime_tui.h"
#include "a4gl_aubit_lib.h"

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void init_wsock (void);
void proc_format (char *s, int a);
int proc_gui_in (char *buff);
void gui_kpress (void);
void gui_click (void);
int last_error (void);


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

int use_gui = 0;
SOCKET sock = 0;
int m_retval = 0;
char m_cretval[64] = "";
static char params[20][800];
int listensock = -1;		/* So that we can close sockets on ctrl-c */
SOCKET connectsock = -1;
int connected = 1;

struct s_in
{
  char name[10];
  char format[20];
  void (*func) ();
}

defs[] =
{
  { "KeyPress", "IIII", gui_kpress},
  { "Click", "IIII", gui_click},
  { "0", "0", 0}
};

//gui.c:148: warning: missing braces around initializer
//gui.c:148: warning: (near initialization for `defs[2].name')


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
void
proc_it (char *buff)
{
  int a;
  debug ("Use gui=%d sock=%d", use_gui, sock);
  if (use_gui > 0 && sock)
    {
      debug ("Sending %s to front end", buff);
      a = write (sock, buff, strlen (buff));
      if (a <= 0)
	connected = 0;
    }

}

/**
 * Start the user interface.
 *
 * If the environment variable GUIPORT is set, act as a server in the port
 * defined.
 *
 * @return Nothing important.
 */
void
start_gui (void)
{
//  char buffer[1024];
//  char *current_character;
  char *p;
  int port = -1;

  debug ("Start gui...");
  p = acl_getenv ("GUIPORT");
  init_wsock ();

  if (p) {
	if (strcmp(p,"")==0) p=0;
  }

  if (p == 0)
    {
      debug ("No Port");
      use_gui = -1;
      return;
    }
  port = atoport (p, "tcp");

  debug ("GUI PORT %d %s", port, p);
  if (port == -1)
    {
      debug ("Unable to find service: %s\n", p);
      exitwith ("Unable to start TCP session");
    }

  sock = get_connection (SOCK_STREAM, port, &listensock);
  debug ("Socket %d", sock);
  connectsock = sock;
  if (sock_puts (sock, "STARTGUI\n"))
    use_gui = 1;
  else
    connected = 0;
}

/**
 * @todo : Understand if not used and if not remove it.
 */
/*
int
read_gui (void)
{
  static char buffer[1024];
  fd_set rfds;
  struct timeval tv;
  int retval;
  FD_ZERO (&rfds);
  FD_SET (sock, &rfds);
  tv.tv_sec = 1;
  tv.tv_usec = 0;

  retval = select (10, &rfds, 0, 0, &tv);

//proc_it("KEEPALIVE");
  if (retval == 0)
    return 0;
  if (sock_read (sock, buffer, 1024) < 0)
    {
      connected = 0;
      exitwith ("Front end closed unexpectedly");
      return 0;
    }
  stripnl (buffer);
  debug ("Got %s over network", buffer);
  if (strncmp (buffer, "GotKey", 6) == 0)
    {
      return net_keyval (&buffer[7]);
    }

  return 0;
}
*/

/**
 * Close the socket to the client.
 */
void 
gui_close (void)
{
  close (sock);
}

/**
 * Gets a port from where to act as a server using TCP.
 *
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

  /* First try to read it from /etc/services */
  serv = getservbyname (service, proto);
  if (serv != NULL)
    port = serv->s_port;
  else
    {				/* Not in services, maybe a number? */
      lport = strtol (service, &errpos, 0);
      if ((errpos[0] != 0) || (lport < 1) || (lport > 65535))
	return -1;		/* Invalid port address */
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
get_connection (socket_type, port, listener)
     int socket_type;
     u_short port;
     int *listener;
{
  struct sockaddr_in address;
  int listening_socket;
  int connected_socket = -1;
  int new_process;
  int reuse_addr = 1;

  /* Setup internet address information.  
     This is used with the bind() call */
  memset ((char *) &address, 0, sizeof (address));
  address.sin_family = AF_INET;
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
      listen (listening_socket, 5);	
	  /* Queue up to five connections before
		 having them automatically rejected. */

      while (connected_socket < 0)
	{
	  connected_socket = accept (listening_socket, NULL, NULL);
	  if (connected_socket < 0)
	    {
	      /* Either a real error occured, or blocking was interrupted for
	         some reason.  Only abort execution if a real error occured. */
	      if (last_error () != EINTR)
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

	  //new_process = fork();
	  new_process = 0;
	  if (new_process < 0)
	    {
	      perror ("fork");
	      close (connected_socket);
	      connected_socket = -1;
	    }
	  else
	    {			/* We have a new process... */
	      if (new_process == 0)
		{
		  /* This is the new process. */
		  close (listening_socket);	/* Close our copy of this socket */
		  if (listener != NULL)
		    *listener = -1;	/* Closed in this process.  We are not
					   responsible for it. */
		}
	      else
		{
		  /* This is the main loop.  Close copy of connected socket, and
		     continue loop. */
		  close (connected_socket);
		  connected_socket = -1;
		}
	    }
	}
      return connected_socket;
    }
  else
    return listening_socket;
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
sock_read (int sockfd, char *buf, size_t count)
{
  size_t bytes_read = 0;
  int this_read;

  while (bytes_read < count)
    {
      do
	this_read = read (sockfd, buf, count - bytes_read);
      while ((this_read < 0) && (last_error () == EINTR));
      if (this_read < 0)
	return this_read;
      else if (this_read == 0)
	return bytes_read;
      bytes_read += this_read;
      buf += this_read;
    }
  return count;
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
sock_write (int sockfd, char *buf, size_t count)
{
  size_t bytes_sent = 0;
  int this_write;

  while (bytes_sent < count)
    {
      do
	this_write = write (sockfd, buf, count - bytes_sent);
      while ((this_write < 0) && (last_error () == EINTR));
      if (this_write <= 0)
	return this_write;
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
sock_gets (int sockfd, char *str, size_t count)
{
  int bytes_read;
  int total_count = 0;
  char *current_position;
  char last_read = 0;
  fd_set rfds;
  struct timeval tv;
  int retval;
  debug ("Waiting for a string...");
  current_position = str;

  while (last_read != 10)
    {

      FD_ZERO (&rfds);
      FD_SET (sockfd, &rfds);
      tv.tv_sec = 1;
      tv.tv_usec = 0;

      while (1)
	{

	  //retval=select(10,&rfds,0,0,&tv);
	  retval = 1;


	  if (retval > 0)
	    bytes_read = recv (sockfd, &last_read, 1, 0);
	  else
	    {
	      proc_it ("KEEPALIVE\n");
	      if (connected == 0)
		break;
	      continue;
	    }
	  if (bytes_read < 0 || retval < 0 || connected == 0)
	    {
	      /* The other side may have closed unexpectedly */
	      debug ("Its gone down !");
	      exitwith ("Connection Dropped");
	      gotolinemode();
	      exit (0);
	      return -1;	/* Is this effective on other platforms than linux? */
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
  debug ("Got %s\n", str);
  return total_count;
}

/**
 * Writes a character string out to a socket.
 *
 * @return -1 if the connection is closed while it is trying to write.
 */
int
sock_puts (sockfd, str)
     int sockfd;
     char *str;
{
  return sock_write (sockfd, str, strlen (str));
}


/**
 * This ignores the SIGPIPE signal.  This is usually a good idea, since
 * the default behaviour is to terminate the application.  SIGPIPE is
 * sent when you try to write to an unconnected socket.
 * You should check your return codes to make sure you catch this 
 * error!
 */
int
isgui (void)
{
  if (use_gui > 0 && sock)
    return 1;
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
get_gui_char (void)
{
  static char buff[256];
  debug ("Waiting for char...");
  sock_gets (sock, buff, 255);
  debug ("Got %s\n", buff);
  strcpy (params[0], "");
  m_retval = 0;
  strcpy (m_cretval, "");
  return proc_gui_in (buff);
}


/**
 *
 * @todo Describe function
 */
void
gui_kpress (void)
{
  debug ("Getting key val for %s from net_netval", params[0]);
  m_retval = net_keyval (params[0]);
  debug ("Key value=%d", m_retval);
}

/**
 *
 * @todo Describe function
 */
void
gui_click (void)
{
  debug ("In gui_click...");
  strcpy (m_cretval, params[0]);
  debug ("Params[0]=%s", params[0]);
  debug ("m_cretval=%s", m_cretval);
  m_retval = 0xffff;
}

/**
 * Find a function name in a string.
 *
 * The function name is in the definitions array.
 *
 * @param s The string where to do the search.
 * @return 
 *   - The position in the array of the string found.
 *   - -1 : The string wanted was not found.
 */
int
find_str_in (char *s)
{
  int a;
  for (a = 0; defs[a].func; a++)
    {
      if (strncasecmp (defs[a].name, s, strlen (defs[a].name)) == 0)
	{
	  return a;
	}
    }
  return -1;
}


/**
 *
 * @todo Describe function
 */
int
proc_gui_in (char *buff)
{
  int a;
  debug ("Processing (proc_gui_in) %s", buff);
  a = find_str_in (buff);
  debug ("a=%d", a);
  if (a < 0)
    return 0;
  debug ("Found...%d", a);
  proc_format (buff, a);
  debug ("Calling..");
  defs[a].func ();
  debug ("Returning %d", m_retval);
  return m_retval;
}

/**
 *
 * @todo Describe function
 */
char *
read_clicked (void)
{
  return m_cretval;
}

/**
 *
 * @todo Describe function
 */
void *
decode_clicked (void)
{
  void *ptr = 0;
  char buff[40];
  debug ("In decode_clicked");
  debug ("m_retval=%s", m_cretval);
  sprintf (buff, "0x%s", m_cretval);
  debug ("Buff set to %s", buff);
//  sscanf (buff, "%lx", (long unsigned int) &ptr); // waring: format argument is not a pointer (arg 3)
    sscanf (buff, "%px", &ptr);
  debug ("Ptr set to %p", ptr);
  return ptr;
}

/**
 *
 * @todo Describe function
 */
void
proc_format (char *s, int a)
{
  int slen = 0;
  int b;
  int eptr;
  int sptr;
  int pcnt = 0;
  char buff[256];
  char buff2[256];
  slen = strlen (defs[a].name);
  strcpy (buff, &s[slen + 1]);
  sptr = 0;
  debug ("In proc_format...");
  for (b = 0; b <= strlen (buff); b++)
    {
      if (buff[b] == '"')
	{
	  sptr++;
	  b++;
	  while (buff[b] != '"' || (buff[b] == '"' && buff[b - 1] == '\\'))
	    b++;
	}

      if (buff[b] == ' ' || buff[b] == 0)
	{
	  eptr = b;
	  if (buff[eptr - 1] == '"')
	    eptr--;
	  strcpy (buff2, &buff[sptr]);
	  buff2[eptr - sptr] = 0;
	  sptr = b + 1;
	  debug ("Param %d = %s", pcnt, buff2);
	  strcpy (params[pcnt++], buff2);
	}
    }
}

/**
 * Initialize windows sockets.
 */
void
init_wsock (void)
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
	  debug ("Error starting wsock");
	  exitwith ("Error Starting Winsock");
	  mja_endwin ();
	  exit (0);
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
last_error (void)
{
  return errno;
//return WSAGetLastError();
}


// ================================ EOF ================================

