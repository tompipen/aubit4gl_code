#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <ctype.h>
#include <sys/select.h>
#include "pipe.h"
#include "debug.h"
#define STREAM_BUFF_SIZE 50000
char **sock_buff=0;
int nsock=0;
int startedenvelope=0;
int handshaking=1;


static char *get_leadin(int n) ;


void set_envelope_mode() {
	handshaking=0;
}

// We want to ensure that each envelope is complete with all
// closing tags
// that means that if we're sending a block of data in separate calls
// we need to suspend flusing that data until we've completed...
//
//

int cantflush=0;

void suspend_flush(int a) {
	UIdebug(4,"Suspend flush called with %d (%d)\n",a,cantflush);
	cantflush+=a;
	if (cantflush<0) {
		printf("Internal error - can't flush went below zero cantflush=%d\n",cantflush);
		exit(2);
	}
	UIdebug(4,"Suspend flush done (%d)\n",cantflush);
}




// Make sure we've set up a placeholder to contain the transmit buffer 
// for the socket
static void ensure_sock(int n) {
int a;


if (n>nsock) {
	sock_buff=realloc(sock_buff,sizeof(char *)*(n+1));
}

if (nsock==0) {
	for (a=nsock;a<=n;a++) {
		sock_buff[a]=0;
	}
} else {
	for (a=nsock+1;a<=n;a++) {
		sock_buff[a]=0;
	}
}
nsock=n;

if ( sock_buff[n]==0) {
		sock_buff[n]=malloc(STREAM_BUFF_SIZE+40);
		
			strcpy(sock_buff[n],get_leadin(n));
}

}



// Get a \n terminated string from a socket
int pipe_sock_gets (int sockfd, char *str, size_t count)
{


  int bytes_read;
  char buff[2];
  int total_count = 0;
  char *current_position;
  char last_read = 0;
  int retval;
  memset (str, 0, count);
  current_position = str;
  errno = 0;
  UIdebug(4,"READING from : %d",sockfd);
  while (last_read != 10)
    {
      while (1)
	{
	  retval = 1;


	  if (retval > 0)
	    {
	      	bytes_read = read (sockfd, &buff[0], 1);
		last_read=buff[0];
	    }
	  else
	    {
	      continue;
	    }


	  if (bytes_read <= 0 || retval < 0)
	    {
	      // No bytes read...
	      if (errno)
		{
		  perror ("recv");
		}
	      UIdebug (1,"No bytes read %d %d %d\n", errno, retval, bytes_read);
	      return 0;
	    }

	  if (bytes_read)
	    break;

	}
      if ((total_count < count) && (last_read != 10) && (last_read != 13) && (last_read!=0))
	{
	  current_position[0] = last_read;
	  current_position++;
	  total_count++;
	}
    }
  if (count > 0)
    current_position[0] = 0;
  UIdebug (4,"pipe_gets returning \n<<<%s>>>\n", str);
  return 1;
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
      while ((this_read < 0));
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

  ensure_sock(sockfd);
  while (bytes_sent < count)
    {
	int loop_cnt=0;
	
      do
	{
	errno=0;
	  this_write = write (sockfd, buf, count - bytes_sent);
		loop_cnt++;

		if(errno) {
			if (errno==EBADF || errno==EBADR) {
				// something wrong - so die..
				break;
			}
		}
	}
      while ((this_write < 0));

      if (this_write <= 0)
	{
	  return this_write;
	}
      bytes_sent += this_write;
      buf += this_write;
    }
  return count;
}



void timeout_flush(int sockfd) {
printf("TIMEOUT FLUSH\n");
  if (cantflush)  {
		printf("CANT FLUSH\n");
		return;
	}
  if (strlen (sock_buff[sockfd])==0) {
		printf("Nothing to FLUSH (%d)\n",sockfd);
		return;
	}
  pipe_flush(sockfd);

}

char *get_leadin(int n) {
static char leadin[200];
   if (!handshaking) {
 		sprintf (leadin, "<ENVELOPE ID=\"%d\">\n<COMMANDS>\n",n);
		return leadin;
   } else {
		return "";
	}
}

static int is_just_start(char *s,int n) {
	if (strcmp(s,get_leadin(n))==0) return 1;
	return 0;
}

/* this isn't a real socket flush - just emptying our buffer... */
void
pipe_flush (int sockfd)
{
  if (cantflush)  {
	UIdebug(4,"INTERNAL ERROR CANT FLUSH ATM - cantflush=%d\n",cantflush);
	printf("INTERNAL ERROR CANT FLUSH ATM\n");
	exit(1);
  }

  if (sock_buff==0) return;
  if (sock_buff[sockfd]==0) return;

  if (strlen (sock_buff[sockfd]) && !is_just_start(sock_buff[sockfd], sockfd))
    {
      char buff[2000]="";
      pipe_sock_write (sockfd, sock_buff[sockfd], strlen (sock_buff[sockfd]));
	if (!handshaking) {
      		sprintf(buff,"</COMMANDS>\n</ENVELOPE>\n");
	}
     
      pipe_sock_write (sockfd, buff, strlen (buff));
      fsync (sockfd);
   }

	strcpy(sock_buff[sockfd],get_leadin(sockfd));
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
  int sz_str = 0;
  int ok = 1;
  static int lastsock = -1;

  if (str==0) {
		printf("PIPE_SOCK_PUTS called with str=0");
		exit(2);
  }

  ensure_sock(sockfd);

	UIdebug(4,"sockfd=%d lastsock=%d\n",sockfd,lastsock);


  if ((sockfd != lastsock) && lastsock!=-1)
    {
	printf("FLUSH!\n");
      pipe_flush (lastsock);
    }
  lastsock = sockfd;


  sz_buff = strlen (sock_buff[sockfd]);
  if (str)
    {
      sz_str = strlen (str);
    }

  // Do we need to send what we've got ? 
  if (sz_buff > STREAM_BUFF_SIZE || sz_str + sz_buff > STREAM_BUFF_SIZE || sz_str > STREAM_BUFF_SIZE )
    {
      if (str != 0)
	{
	  UIdebug (4,"BUFFER FULL ;-) %d %d\n", sz_buff, sz_str);
	}

	pipe_flush(sockfd);
        sz_buff = 0;
    }



  if (str == 0)
    {
      return 1;
    }



  if (sz_str > STREAM_BUFF_SIZE)
    {
      // Its too large to cache...
      if (ok)
	{
	  ok = pipe_sock_write (sockfd, str, strlen (str));
	}
      return ok;

    }
  UIdebug (3,"ADDING TO CACHE : '%s' (%d)\n", str,sockfd);
  strcat (sock_buff[sockfd], str);
  //UIdebug ("--->%s\n", sock_buff[sockfd]);

  return ok;
}



int
pipe_expect (int serversocket, char *s)
{
  char buff[256];
  int a;
  memset (buff, 0, sizeof (buff));

  pipe_flush (serversocket);
  UIdebug (3,"Expect...\n");
  pipe_sock_gets (serversocket, buff, 255);

  if (strcmp (buff, s) != 0)
    {
      printf ("Expecting %s - got '%s'\n", s, buff);
      for (a = 0; a < 17; a++)
	{
	  printf ("(%02x %c) ", buff[a] & 0xff,
		  isprint (buff[a]) ? buff[a] : '.');
	}
      printf ("\n");
      return 0;
    }
  else
    {
      UIdebug (3,"Got expected : '%s','%s'\n", buff, s);
      return 1;
    }
}
