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
# $Id: gui.c,v 1.4 2002-04-24 07:45:59 afalout Exp $
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

#ifdef WIN32
#ifndef __CYGWIN__
#define USE_WINSOCK
#endif
#endif

#include "a4gl_sockhelp.h"
//#include <stdio.h>
#include "a4gl_dbform.h"
//#include <stdarg.h>
#include "a4gl_debug.h"
#include "a4gl_runtime_tui.h"

#ifndef USE_WINSOCK
#define SOCKET int
#endif

#ifndef WIN32
#include <sys/time.h>
#endif
#ifdef __CYGWIN__
#include <sys/time.h>
#endif


int use_gui = 0;
SOCKET sock = 0;
int m_retval = 0;
char m_cretval[64] = "";
static char params[20][80];
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


int listensock = -1;		/* So that we can close sockets on ctrl-c */
SOCKET connectsock = -1;
int connected = 1;
//#include <sys/signal.h>



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
int
start_gui (void)
{
  char buffer[1024];
  char *current_character;
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
read_gui ()
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
}


/**
 * Close the socket to the client.
 */
void gui_close (void)
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
 *
 * @param address
 * @return
 *   - NULL : The address can not be found. 
 *   - Otherwise :
 */
struct in_addr *atoaddr (char *address)
{
  struct hostent *host;
  static struct in_addr saddr;

  /* First try it as aaa.bbb.ccc.ddd. */
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
      listen (listening_socket, 5);	/* Queue up to five connections
before
					   having them automatically
rejected. */

      while (connected_socket < 0)
	{
	  connected_socket = accept (listening_socket, NULL, NULL);
	  if (connected_socket < 0)
	    {
	      /* Either a real error occured, or blocking was interrupted
for
	         some reason.  Only abort execution if a real error occured.
*/
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
		  close (listening_socket);	/* Close our copy of this
socket */
		  if (listener != NULL)
		    *listener = -1;	/* Closed in this process.  We are
not 
					   responsible for it. */
		}
	      else
		{
		  /* This is the main loop.  Close copy of connected socket,
and
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
 *
 * @param service is the port name/number,
 * @param type is either SOCK_STREAM or SOCK_DGRAM, and
 * @param netaddress is the host name to connect to.
 * @eturn The socket, ready for action.
 */
int
make_connection (service, type, netaddress)
     char *service;
     int type;
     char *netaddress;
{
  /* First convert service from a string, to a number... */
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

  printf ("Connecting to %s on port %d.\n", inet_ntoa (*addr), htons
(port));

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
  /* Otherwise, must be for udp, so bind to address. */
  if (bind (sock, (struct sockaddr *) &address, sizeof (address)) < 0)
    {
      perror ("bind");
      return -1;
    }
  return sock;
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
int sock_read (int sockfd, char *buf, size_t count)
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
	      return -1;	/* Is this effective on other platforms than
linux? */
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
isgui ()
{
  if (use_gui > 0 && sock)
    return 1;
  return 0;
}

get_gui_char ()
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


void
gui_kpress (void)
{
  debug ("Getting key val for %s from net_netval", params[0]);
  m_retval = net_keyval (params[0]);
  debug ("Key value=%d", m_retval);
}

void
gui_click (void)
{
  debug ("In gui_click...");
  strcpy (m_cretval, params[0]);
  debug ("Params[0]=%s", params[0]);
  debug ("m_cretval=%s", m_cretval);
  m_retval = 0xffff;
}

struct s_in
{
  char name[10];
  char format[20];
  void (*func) ();
}

defs[] =
{
  {
  "KeyPress", "IIII", gui_kpress}
  ,
  {
  "Click", "IIII", gui_click}
  ,
  {
  0, 0, 0}
}

;

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

char *
read_clicked ()
{
  return m_cretval;
}

void *
decode_clicked ()
{
  void *ptr;
  char buff[40];
  debug ("In decode_clicked");
  debug ("m_retval=%s", m_cretval);
  sprintf (buff, "0x%s", m_cretval);
  debug ("Buff set to %s", buff);
  sscanf (buff, "%lx", &ptr);
  debug ("Ptr set to %p", ptr);
  return ptr;
}

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
init_wsock ()
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

last_error ()
{
  return errno;
//return WSAGetLastError();
}

#ifdef MOVED_TO_UI_DOT_C

/* ************************************************************************/
/*                            TUI/GUI Stuff */
/* ************************************************************************/

/** User interface mode */
extern int ui_mode;

#define UI_MODE_TEXT 0
#define UI_MODE_GTK  1

/**
 * Create a new 4gl window.
 *
 * @param s The 4gl name of the window
 * @param iswindow
 * @param form_line The line where the eventual forms are opened.
 * @param error_line The line where the errors are displayed. 
 * @param prompt_line The line where the PROMPT statement is prcessed.
 * @param menu_line The line where the 4gl MENU statement is displayed.
 * @param border Flag that indicate if the window should have a border.
 * @param comment_line The line the comments are showed (form comments). 
 * @param message_line The line where the messages from MESSAGE statement is 
 *   showed.
 * @param attrib The attributes used Ignored.
 * @return The widget window created.
 */
void *cr_window (char *s, int iswindow, int form_line, int error_line,
	   int prompt_line, int menu_line, int border, int comment_line,
	   int message_line, int attrib)
{

  if (ui_mode == UI_MODE_TEXT)
    return (void *)cr_window_tui (
				s, iswindow, form_line, error_line, prompt_line,
			  menu_line, border, comment_line, message_line,
			  attrib
		);

#ifdef HAS_GTK
START_HAS_GTK
    return (void *)cr_window_gtk (s, iswindow, form_line, error_line, prompt_line,
			  menu_line, border, comment_line, message_line,
			  attrib);

END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (1)");
}


/**
 * Create a window with form.
 *
 * The form name is passed by the stack.
 *
 * @param s The 4gl name of the window
 * @param iswindow
 * @param form_line The line where the eventual forms are opened.
 * @param error_line The line where the errors are displayed.
 * @param prompt_line The line where the PROMPT statement is prcessed.
 * @param menu_line The line where the 4gl MENU statement is displayed.
 * @param border Flag that indicate if the window should have a border.
 * @param comment_line The line the comments are showed (form comments). 
 * @param message_line The line where the messages from MESSAGE statement is 
 *   showed. 
 * @param attrib The attributes used.
 */
int
cr_window_form (char *name,
  int iswindow, int form_line, int error_line, int prompt_line,
  int menu_line, int border, int comment_line, int message_line,
  int attrib)
{
char newname[1024];
strcpy(newname,name);
trim(newname);

  if (ui_mode == UI_MODE_TEXT)
    return cr_window_form_tui (newname,
			       iswindow,
			       form_line,
			       error_line,
			       prompt_line,
			       menu_line,
			       border, comment_line, message_line, attrib);

#ifdef HAS_GTK
START_HAS_GTK
    return cr_window_form_gtk (newname,
			       iswindow,
			       form_line,
			       error_line,
			       prompt_line,
			       menu_line,
			       border, comment_line, message_line, attrib);

END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (2)");
}

/**
 * Display the fields.
 *
 * @param n
 * @param attr The attributes.
 * @param ... The list of fields.
 * @return
 */
int disp_fields (int n, int attr, ...)
{
  va_list ap;
  va_start (ap, attr);
  if (ui_mode == UI_MODE_TEXT)
    return disp_fields_tui (n, attr, &ap);
#ifdef HAS_GTK
START_HAS_GTK
    return disp_fields_gtk (n, attr, &ap);
END_HAS_GTK
#endif

  exitwith ("Invalid UI Mode (3)");
}

int
disp_form_fields (int n, int attr, char *formname,...)
{
  va_list ap;
  va_start (ap, formname);

  if (ui_mode == UI_MODE_TEXT)
    return disp_form_fields_tui (n, attr, formname,&ap);
#ifdef HAS_GTK
START_HAS_GTK
    return disp_form_fields_gtk (n, attr, formname,&ap);
END_HAS_GTK
#endif

  exitwith ("Invalid UI Mode (3)");
}

/**
 * Open a form.
 *
 * Executed by the generated from the OPEN FORM 4gl statement.
 *
 * @param form_id The form file name.
 */
int
open_form (char *name)
{
int a;
  if (ui_mode == UI_MODE_TEXT) {
    a=open_form_tui (name);
    debug("a=%d\n",a);
	debug("Opened form...");
    return a;
  }

#ifdef HAS_GTK
START_HAS_GTK
    return open_form_gtk (name);
END_HAS_GTK
#endif

  exitwith ("Invalid UI Mode (4)");
}


/**
 * Implementation of the OPEN FORM 4gl statement.
 *
 * @param name The form name.
 * @return
 */
int
close_form (char *name)
{
  if (ui_mode == UI_MODE_TEXT)
    return close_form_tui (name);
#ifdef HAS_GTK
START_HAS_GTK
    return close_form_gtk (name);
END_HAS_GTK
#endif

  exitwith ("Invalid UI Mode (5)");
}

/**
 * Implementation of OPEN FORM 4gl statement.
 *
 * @param form_id The form file name.
 * @param a Attributes. Ignored
 */
int
disp_form (char *name, int attr)
{
debug("In disp_form");
debug(" params: %s %d",name,attr);

  if (ui_mode == UI_MODE_TEXT)
    return disp_form_tui (name, attr);
#ifdef HAS_GTK
START_HAS_GTK
    return disp_form_gtk (name, attr);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (6)");
}

/**
 * Implementation of 4gl CURRENT WINDOW IS statement.
 *
 * @param win_name A string with the name of the window.
 * @return
 */
int
current_window (char *win_name)
{
  if (ui_mode == UI_MODE_TEXT)
    return current_window_tui (win_name);
#ifdef HAS_GTK
START_HAS_GTK
    return current_window_gtk (win_name);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (7)");

}


/**
 * This function aparentrly is not used
 * @todo Understand if the function is not used and if not remove it
 */
ACL_Menu *new_menu (char *title, int x, int y, int mn_type, 
		    int help_no, int nopts, ...)
{
  va_list ap;
  va_start (ap, nopts);

  if (ui_mode == UI_MODE_TEXT)
    return new_menu_tui (title, x, y, mn_type, help_no, nopts, &ap);
#ifdef HAS_GTK
START_HAS_GTK
    return (void *)new_menu_gtk (title, x, y, mn_type, help_no, nopts, &ap);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (8)");

}

/**
 * Create a new menu.
 *
 * Called by the generated C code at run-time.
 * The items are created after with other function call.
 *
 * @param title The menu title.
 * @param x The column where to be created.
 * @param y The line where to be created.
 * @param mn_type The menu type:
 *   - Boxed
 *   - ???
 * @param help_no The help number of the menu.
 * @return A pointer to the structure that identifies the menu.
 */
ACL_Menu *new_menu_create(char *title, int x, int y, int mn_type, int help_no)  {
  if (ui_mode == UI_MODE_TEXT)
    return new_menu_create_tui (title, x, y, mn_type, help_no);
#ifdef HAS_GTK
START_HAS_GTK
    return (void *)new_menu_create_gtk (title, x, y, mn_type, help_no);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (8.1)");
}


/**
 * Add a new menu option/item.
 *
 * Executed at run-time by the generated program.
 *
 * @param menu A pointer to the menu structure.
 * @param txt The text of the option (immediatly after command)
 * @param keys The keys if so
 * @param desc The text long description.
 * @param helpno The help number.
 * @param attr The attributes
 */
void add_menu_option(ACL_Menu *menu,char *txt,char *keys,char *desc,
	int helpno,int attr)  
{
  if (ui_mode == UI_MODE_TEXT) {
	add_menu_option_tui(menu,txt,keys,desc,helpno,attr);
	return;
  }
#ifdef HAS_GTK
START_HAS_GTK
	add_menu_option_gtk(menu,txt,keys,desc,helpno,attr);
        return;
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (8.2)");

}

/**
 * Terminate the menu creation.
 *
 * Executed by the generated code at run-time after the menu created and all
 * the items inserted.
 *
 * @param menu The menu structure.
 */
void finish_create_menu(ACL_Menu *menu)  
{
  if (ui_mode == UI_MODE_TEXT) {
	finish_create_menu_tui(menu);
	return;
  }
#ifdef HAS_GTK
START_HAS_GTK
	finish_create_menu_gtk(menu);
        return;
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (8.3)");

}

/**
 * Called by the 4gl compiled program to display the menu.
 * The menu should be allready initialized when this function called.
 *
 * @todo Clean the return values or return void. Since the called functions
 * does not return anything. The cast is just for clean the warning but this
 * should be fixed
 *
 * @param A pointer to the menu information.
 * @return The return value is not used 
 */
char *disp_h_menu (ACL_Menu *menu)
{
  if (ui_mode == UI_MODE_TEXT)
    return disp_h_menu_tui (menu);
#ifdef HAS_GTK
START_HAS_GTK
    return (char *)disp_h_menu_gtk (menu);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (9)");
}

/**
 * Executes the menu loop until the user executes some option.
 *
 * Executed in run-time by the generated C code.
 *
 * @param menu A pointer to the menu structure information.
 */
int menu_loop (ACL_Menu *menu)
{
  if (ui_mode == UI_MODE_TEXT)
    return menu_loop_tui (menu);
#ifdef HAS_GTK
START_HAS_GTK
    return menu_loop_gtk (menu);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (10)");
}

/**
 * Execute the NEXT OPTION part of MENU statement.
 *
 * In GTK GUI mode have no efect.
 *
 * @param menu
 * @param nextop.
 */
int
next_option (ACL_Menu * menu,char *nextopt)
{
  if (ui_mode == UI_MODE_TEXT)
	return next_option_tui ( menu, nextopt) ;
#ifdef HAS_GTK
START_HAS_GTK
	return next_option_gtk ( menu, nextopt) ;
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (11)");
}


/**
 * Not used.
 */
int
free_menu (ACL_Menu * menu)
{
  if (ui_mode == UI_MODE_TEXT)
    return free_menu_tui (menu);
#ifdef HAS_GTK
START_HAS_GTK
    return free_menu_gtk (menu);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (12)");
}

/**
 * Not used but should be.
 */
int
menu_hide (ACL_Menu * menu, ...)
{
  va_list ap;
  va_start (ap, menu);
  if (ui_mode == UI_MODE_TEXT)
    return menu_hide_tui (menu, &ap);
#ifdef HAS_GTK
START_HAS_GTK
    return menu_hide_gtk (menu, &ap);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (13)");
}

/**
 * Show an item of the menu.
 *
 * Called by the generated C code at run-time.
 * 
 * @param The menu name to be showed.
 * @param ... The options to be showed.
 */
int menu_show (ACL_Menu * menu, ...)
{
  va_list ap;
  va_start (ap, menu);
  if (ui_mode == UI_MODE_TEXT)
    return menu_show_tui (menu, &ap);
#ifdef HAS_GTK
START_HAS_GTK
    return menu_show_gtk (menu, &ap);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (14)");
}

/**
 * Show a menu in a window.
 *
 * Called by the generated C code.
 *
 * @param menuid The menu name.
 * @param handler The menu handler name.
 * @return
 */
int
show_menu (char *menuid, void *handler)
{
  if (ui_mode == UI_MODE_TEXT)
    return show_menu_tui (menuid, handler);
#ifdef HAS_GTK
START_HAS_GTK
    return show_menu_gtk (menuid, handler);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (15)");
}

/**
 * Print a message.
 *
 * @param a The attributes.
 * @param wait The time to wait during the message presentation.
 */
#error BAD ..
int

aclfgli_pr_message (int attr,int wait)
{
  if (ui_mode == UI_MODE_TEXT)
    return aclfgli_pr_message_tui (attr,wait);
#ifdef HAS_GTK
START_HAS_GTK
    return aclfgli_pr_message_gtk (attr,wait);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (16)");
}

/**
 * Display a error received by the char stack.
 *
 * @param a Not used
 * @param wait - 0 : The Do not wait for OK.
 *             - 1 : Show a window witj OK button.
 */
int
display_error (int attr,int wait)
{
  A4GLSQL_set_status(0,0);  
  if (ui_mode == UI_MODE_TEXT)
    return display_error_tui (attr,wait);

#ifdef HAS_GTK
START_HAS_GTK
    return display_error_gtk (attr,wait);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (17)");
}

/**
 * Get the current form in GTK GUI mode.
 *
 * @return The current form
 */
struct s_form_dets *get_curr_form ()
{
  if (ui_mode == UI_MODE_TEXT)
    return get_curr_form_tui ();
#ifdef HAS_GTK
START_HAS_GTK
    return (void *)get_curr_form_gtk ();
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (18)");
}


/**
 * Implementation of part of the INPUT 4gl statement.
 *
 * Generate a list of fields acording the parameters.
 *
 * @param field_list A pointer to the place where to put the field list.
 * @param formdets Pointer to the structure filled with the form details.
 * @param ...
 * @return
 */
int
gen_field_chars (FIELD *** field_list, struct s_form_dets *formdets, ...)
{
  va_list ap;
  va_start (ap, formdets);

  if (ui_mode == UI_MODE_TEXT)
    return gen_field_chars_tui (field_list, formdets, &ap);

#ifdef HAS_GTK
START_HAS_GTK
    return gen_field_chars_gtk (field_list, formdets, &ap);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (19)");
}

/**
 * Implementation of the form input loop.
 *
 * Called by the generated C code.
 *
 * @param s A pointer to the screen IO structure.
 */
int
form_loop (struct s_screenio *s)
{
  if (ui_mode == UI_MODE_TEXT)
    return form_loop_tui (s);
#ifdef HAS_GTK
START_HAS_GTK
    return form_loop_gtk (s);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (20)");
}


/**
 *
 * @param s A pointer to the screen information.
 */
int push_constr (struct s_screenio *s)    
{
  if (ui_mode == UI_MODE_TEXT) 
   return push_constr_tui (s);

#ifdef HAS_GTK
START_HAS_GTK
    return push_constr_gtk (s);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (20)");
}


/* Input stuff */


/**
 * Part of the C implementation of the input.
 *
 * Called by the generated C code.
 *
 * @param sio a pointer to the screen IO structure.
 */
int
set_fields (struct s_screenio *sio)
{
  if (ui_mode == UI_MODE_TEXT)
    return set_fields_tui (sio);
#ifdef HAS_GTK
START_HAS_GTK
    return set_fields_gtk (sio);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (21)");
}

/**
 * DISPLAY AT 4gl statement implementation.
 *
 * @param n The row number where the display is made.
 * @param a The column number.
 */
int
display_at (int n, int a)
{
  if (ui_mode == UI_MODE_TEXT)
    return display_at_tui (n, a);
#ifdef HAS_GTK
START_HAS_GTK
    return display_at_gtk (n, a);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (22)");
}


/**
 * Move the 4gl window.
 *
 * Implement the MOVE WINDOW 4gl statement.
 *
 * @param s The window name.
 * @param to_by Flag that identifies the scope of the move:
 *   - 0 : The move is abosulte in the screen.
 *   - 1 : The move is relative to the current position.
 */
int
movewin (char *winname, int absol)
{
  if (ui_mode == UI_MODE_TEXT)
    return movewin_tui (winname, absol);
#ifdef HAS_GTK
START_HAS_GTK
    return movewin_gtk (winname, absol);
END_HAS_GTK
#endif

  exitwith ("Invalid UI Mode (23)");
}

/* Display.. */

/**
 * Implements the HIDE WINDOW 4gl instruction.
 *
 * @param winname The name of the window to be hidded.
 * @return ???
 */
int
hide_window (char *winname)
{
  if (ui_mode == UI_MODE_TEXT)
    return hide_window_tui (winname);
#ifdef HAS_GTK
START_HAS_GTK
    return hide_window_gtk (winname);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (24)");
}

/**
 * Show a window.
 *
 * @param winname The name of the window to be showed.
 */
int
show_window (char *winname)
{
  if (ui_mode == UI_MODE_TEXT)
    return show_window_tui (winname);
#ifdef HAS_GTK
START_HAS_GTK
    return show_window_gtk (winname);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (25)");
}

/**
 * Check if the user was in a screen field.
 *
 * @todo : Fix the call of the generrated C code that call this function
 * with only one parameter.
 *
 * @param s The field name.
 * @param a
 */
long fgl_infield (char *s, int a)  
{

  if (ui_mode == UI_MODE_TEXT)
    return fgl_infield_tui (s,a);
#ifdef HAS_GTK
START_HAS_GTK
    return fgl_infield_gtk (s,a);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (25)");
}

/**
 * Clear the content of a window.
 *
 * @param winname The name of the window to cleaned.
 */
int
clr_window (char *winname)
{
  if (ui_mode == UI_MODE_TEXT)
    return clr_window_tui (winname);
#ifdef HAS_GTK
START_HAS_GTK
    return clr_window_gtk (winname);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (26)");
}

/**
 * 4gl SLEEP statement implementation.
 */
int sleep_i ()
{
  if (ui_mode == UI_MODE_TEXT)
    return sleep_i_tui ();
#ifdef HAS_GTK
START_HAS_GTK
    return sleep_i_gtk ();
END_HAS_GTK
#endif
  debug("ui_mode=%d",ui_mode);
  exitwith ("Invalid UI Mode (27)");
}

/**
 * Implements the CLOSE WINDOW 4gl statement.
 *
 * Called by the generated C code.
 *
 * @param win_name The window name.
 */
int remove_window (char *win_name)
{
  if (ui_mode == UI_MODE_TEXT)
    return remove_window_tui (win_name);
#ifdef HAS_GTK
START_HAS_GTK
    return remove_window_gtk (win_name);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (28)");
}

/**
 * C Implementation of the PROMPT 4gl statement.
 *
 * Called by the generated C code for a 4gl souced with PROMPT statement.
 *
 * @param prompt A pointer to the prompt structure where the information about
 * it is stored.
 */
prompt_loop (struct s_prompt *prompt)
{
  if (ui_mode == UI_MODE_TEXT)
    return prompt_loop_tui (prompt);
#ifdef HAS_GTK
START_HAS_GTK

    return prompt_loop_gtk (prompt);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (29)");
}

/**
 * Implementation of the first part of C version PROMPT 4gl statement.
 *
 * @param prompt A pointer to the prompt identifier structure where this 
 *   function initialize the values.
 * @param ap The attributes for the message.
 * @param c Prompt for char (cbreak()) flag.
 * @param h The help number.
 * @param af The attributes.
 */
int
start_prompt (struct s_prompt *prompt, int ap, int c, int h, int af)
{
  if (ui_mode == UI_MODE_TEXT)
    return start_prompt_tui (prompt, ap, c, h, af);
#ifdef HAS_GTK
START_HAS_GTK
    return start_prompt_gtk (prompt, ap, c, h, af);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (30)");
}

/**
 * Enable or disable fields.
 *
 * @param en_dis The action to do:
 *   - D : Disable
 *   - E : Enable
 * @param ... The list of the fields to be enabled or disabled.
 */
int endis_fields (int en_dis, ...) 
{
  va_list ap;
  va_start (ap, en_dis);

  if (ui_mode==UI_MODE_TEXT) 
	  return endis_fields_tui(en_dis,&ap);

#ifdef HAS_GTK
START_HAS_GTK
	return endis_fields_gtk(en_dis,&ap);
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (30)");
}

/**
 * Clear the content of the fields in the current form.
 *
 * @param to_defaults Indicate if the values should be initialized just as in
 * defaults.
 */
void clr_form (int to_defaults) 
{

  if (ui_mode==UI_MODE_TEXT)  {
	  clr_form_tui(to_defaults);
	  return;
  }

#ifdef HAS_GTK
START_HAS_GTK

	clr_form_gtk(to_defaults);
	return;

END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (30)");
}

gui_init(int c,char *argv[]) {
#ifdef HAS_GTK
START_HAS_GTK
	gui_init_gtk(c,argv);
	return;
END_HAS_GTK
#else
	printf("Not compiled for GUI environment\n");
	exitwith("Not compiled for a GUI environment");
	exit(0);
#endif
}

/**
 * Make a refresh in the windows in GUI mode in the z axys.
 */
zrefresh ()
{
  if (ui_mode == UI_MODE_TEXT)
    return zrefresh_tui();
#ifdef HAS_GTK
START_HAS_GTK
    return zrefresh_gtk();
END_HAS_GTK
#endif
  exitwith ("Invalid UI Mode (31)");
}

#endif
