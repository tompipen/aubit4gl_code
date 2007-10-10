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




int
connect_ui (void)
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
  int l=0;
  struct s_attr *attr = 0;

  last_attr = 0;
  UIdebug (4,"Get_event_from_ui\n");

  while (1)
    {
      UIdebug (4,"Getting from buffer\n");
      if (!pipe_sock_gets (clientui_sock_read, buff, 255))
	{
	  UIdebug (2,"PIPE CLOSED - client disconnected ?\n");
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
		      UIdebug (5,"Single line trigger\n");
		      attr = xml_parse (localbuff);
		      //if (attr)
			//{
			  break;
			//}
		    }
		}
	    }
	  localbuff = strdup (buff);
	}
      else
	{
	UIdebug(5,"l=%d localbuff=%p '%s' buff='%s'\n",l,localbuff,localbuff,buff);
	l=strlen(localbuff);
	l += strlen (buff);
	UIdebug(5,"l=%d localbuff=%p\n",l,localbuff);

	  localbuff = realloc (localbuff, l + 10);
	if (localbuff==0) {
			UIdebug(0,"Unable to allocate memory");
			exit(1);
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



  if (attr->id)
    {
      int n = -1;
		printf("---->%s\n", attr->id);
      if (strcmp (attr->id, "DIE") == 0 || strcmp (attr->id, "-999")==0)
        {
          exit(2);
        }

      if (strcmp (attr->id, "ACCEPT") == 0)
	{
	  n = -100;
	}

      if (strcmp (attr->id, "CANCEL") == 0) 	{ n = -100; }
      if (strcmp (attr->id, "YES") == 0) 	{ n = -101; }
      if (strcmp (attr->id, "NO") == 0) 	{ n = -102; }

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

  UIdebug(0, "End of get_event_from_ui - shouldn't happen");
  exit(2);
}


#ifdef OBSOLETE

int
get_event_from_ui_old (char *srch, char **res)
{
  char buff[256];
  char *ptr;
  int n;
  char nstr[200];
  flush_ui ();


  UIdebug ("FGLPROG : WAITING FOR SOME UI\n");

  UIdebug ("FGLPROG LOOP\n");
  if (!pipe_sock_gets (clientui_sock_read, buff, 255))
    {
      printf ("PIPE CLOSED - client disconnected ?\n");
      exit (0);
    }

  UIdebug ("Buff=%s\n", buff);

  if (strncmp (buff, "<TRIGGERED", 10) != 0)
    {				// Invalid packet back ...
      return -1;
    }

  sscanf (buff, "<TRIGGERED ID=\"%s\"", &nstr);

  UIdebug ("nstr=%s\n", nstr);
  ptr = strchr (nstr, '"');
  if (ptr)
    *ptr = 0;
  ptr = strchr (nstr, '\'');
  if (ptr)
    *ptr = 0;

  UIdebug ("nstr=%s\n", nstr);
  n = -1;

  if (strcmp (nstr, "ACCEPT") == 0)
    {
      n = -100;
    }

  if (strcmp (nstr, "INTERRUPT") == 0)
    {
      n = -101;
    }
  UIdebug ("nstr=%s\n", nstr);
  if (n == -1)
    {
      n = atoi (nstr);
    }
  UIdebug ("n=%d\n", n);
  if (srch)
    {
      char buff2[200];
      UIdebug ("Got srch\n");
      UIdebug ("Srch=%s\n", srch);
      for (ptr = buff + 11; *ptr && *ptr != ' '; ptr++);
      if (*ptr == 0)
	{
	  *res = 0;
	  return n;
	}
      if (*ptr == ' ')
	ptr++;
      UIdebug ("ptr=%s\n", srch);

      if (strncmp (ptr, srch, strlen (srch) != 0))
	{
	  UIdebug ("SRCH not found (%s %s)\n", ptr, srch);
	  return n;
	}
      ptr += strlen (srch);
      ptr++;			// = 
      ptr++;			// "
      strcpy (buff2, ptr);
      ptr = strchr (buff2, '"');
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff2, '\'');
      if (ptr)
	*ptr = 0;
      UIdebug ("RESULT : %s\n", buff2);
      UIdebug ("setting res\n", srch);
      *res = strdup (buff2);

      return n;
    }
  return n;
}
#endif

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
