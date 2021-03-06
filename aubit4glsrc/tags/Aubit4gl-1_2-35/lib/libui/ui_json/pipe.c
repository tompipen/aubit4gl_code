#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

#include "sock_xml.h"
//#include <sys/un.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <sys/wait.h>
//#include <signal.h>
//#include <sys/select.h>

#include <ctype.h>
#include "pipe.h"
#include "debug.h"

int stream_buff_size=1000000;
void remove_pipes (void);
//#define stream_buff_size 50000
char **sock_buff=0;
int *sock_buff_sz=0;
int nsock=0;
int startedenvelope=0;
int handshaking=1;
int using_stdio=0;
int getMyId(void);


void set_using_stdio(int n) {
	using_stdio=n;
}


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


static int logproxy(void) {
static int lp=-1;

if (lp==-1) {
        char *ptr;
	lp=0;
        ptr=getenv("LOGPROXY");
        if (ptr) {
		if (strcmp(ptr,"Y")==0) lp=1;
		if (strcmp(ptr,"y")==0) lp=1;
		if (strcmp(ptr,"1")==0) lp=1;
        }
}

return lp;
}



void suspend_flush(int a) {
	UIdebug(4,"Suspend flush called with %d (%d)\n",a,cantflush);
	cantflush+=a;
	if (cantflush<0) {
		FPRINTF(stderr,"Internal error - can't flush went below zero cantflush=%d\n",cantflush);
		exit(2);
	}
	UIdebug(4,"Suspend flush done (%d)\n",cantflush);
}




// Make sure we've set up a placeholder to contain the transmit buffer 
// for the socket
static void ensure_sock(int n) {
int a;


if (n>=nsock) {
	sock_buff=realloc(sock_buff,sizeof(char *)*(n+1));
	sock_buff_sz=realloc(sock_buff_sz,sizeof(int)*(n+1));
}

if (nsock==0) {
	for (a=nsock;a<=n;a++) {
		sock_buff[a]=0;
		sock_buff_sz[a]=0;
	}
} else {
	for (a=nsock+1;a<=n;a++) {
		sock_buff[a]=0;
		sock_buff_sz[a]=0;
	}
}
nsock=n;

if ( sock_buff[n]==0) {
		sock_buff[n]=malloc(stream_buff_size+40);
		
		strcpy(sock_buff[n],get_leadin(n));
		sock_buff_sz[n]=strlen( sock_buff[n]);
}

}



// Get a \n terminated string from a socket
int pipe_sock_gets (int sockfd, char *str, size_t count)
{


	      FILE *flog;
  int bytes_read;
  char buff[2];
  int total_count = 0;
  char *current_position;
  char last_read = 0;
  int retval;
	int use_read;
  memset (str, 0, count);
  current_position = str;
  errno = 0;
  UIdebug(4,"READING from : %d",sockfd);
#ifdef __WIN32__
	use_read=0;
	if (using_stdio) {
		use_read=1;
	}
#else
	use_read=1;
#endif
  while (last_read != 10)
    {
      while (1)
	{
	  retval = 1;


	  if (retval > 0)
	    {
		errno=0;
if (use_read) {
	      	bytes_read = read (sockfd, &buff[0], 1);
} else {
		bytes_read=recv(sockfd,&buff[0],1,0);
}
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
			printf("Errno=%d\n",errno);
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
      if (total_count >= count) {
    		current_position[0] = 0;
		//FPRINTF(stderr, "Partial : %s\n\n\n\n", str);
  		UIdebug (4,"pipe_gets returning \n<<<%s>>>\n", str);

		if (logproxy())  {
	      		flog = fopen ("logproxy.in", "a"); if (flog) { fprintf(flog,"%s\n",str);  fclose (flog); }
		}


		return 1;
	}
    }
  if (count > 0)
    current_position[0] = 0;
		if (logproxy())  {
	      		flog = fopen ("logproxy.in", "a"); if (flog) { fprintf(flog,"%s\n",str);  fclose (flog);}
		}
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
char *borig;
borig=buf;
int use_read;


  while (bytes_read < count)
    {
      do {
#ifdef __WIN32__
	use_read=0;
	if (using_stdio) {
		use_read=1;
	}
#else
	use_read=1;
#endif

if (use_read) {
		this_read = read (sockfd, buf, count - bytes_read); 
} else {
		this_read = recv(sockfd,buf,count-bytes_read,0);
}

      }
      while ((this_read < 0));



      if (this_read < 0)
	return this_read;


      if (this_read == 0)
	{
	  if (bytes_read > 0)
	    {
	      FILE *flog;
		if (logproxy())  {
	      		flog = fopen ("logproxy.in", "a");
	      		if (flog)
				{
		  		fwrite (borig, bytes_read, 1, flog);
	      			fclose (flog);
				}
		}
	    }
	  return bytes_read;
	}
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
  int use_write=0;
  FILE *flog;


#ifdef __WIN32__
	use_write=0;
	if (using_stdio) {
		use_write=1;
	}
#else
	use_write=1;
#endif

  ensure_sock(sockfd);
  while (bytes_sent < count)
    {
	int loop_cnt=0;
	
      do
	{
	errno=0;
	if (1) { // LOG ...
		if (logproxy())  {
			flog=fopen("logproxy.out","a");
			if (flog) {
				fwrite(buf,count - bytes_sent,1,flog);
				fclose(flog);
			}
		}
	}


if (use_write) {
	  this_write = write (sockfd, buf, count - bytes_sent);
} else {
	  this_write = send (sockfd, buf, count - bytes_sent,0);
}


		loop_cnt++;

		if(errno) {
			printf("Errno=%d\n",errno); 
		  	perror ("write");
#ifdef __WIN32__
			Sleep(1);
#else
			sleep(1);
#endif

			if (errno==32 || errno==29 || errno==5) {
				if(errno==5) {
					printf("I/O Error\n");
				}
#ifdef COMPILING_PROXY
            remove_pipes();
#endif
				exit(1);
			}

#ifdef EBADR
			if (errno==EBADF || errno==EBADR ) {
#else
			if (errno==EBADF ) {
#endif
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
  if (cantflush)  {
		return;
	}
  if (strlen (sock_buff[sockfd])==0) {
		return;
	}
  pipe_flush(sockfd);

}

char *get_leadin(int n) {
static char leadin[400];

   if (!handshaking) {
		int id;
		id=getMyId();
		UIdebug(2,"getMyId returns %d",id);
		if (id==-1) {
			id=n;
		}
		if (id==0) {
			printf("INTERNAL ERROR - ID SHOULD NOT BE 0\n");
			printf("n=%d getMyId=%d\n", n,getMyId());
			exit(2);
		}
 		SPRINTF (leadin, "{ \"ID\":\"%d\",\"PID\":\"%d\",\"Commands\": [\n",id,getpid());
		return leadin;
   } else {
		return "";
	}
}

static int is_just_start(char *s,int n) {
	if (strcmp(s,get_leadin(n))==0) return 1;
	return 0;
}


void
pipe_clear (void) {
	//UIdebug(2,"Critical problem... program is exiting");

	
	if (cantflush) {
	int sockfd;
		// Because we are quitting - force the flush
		cantflush=0;

		for (sockfd=0;sockfd<=nsock;sockfd++) {
			sock_buff[sockfd]=0;
			sock_buff_sz[sockfd]=0;
		}
	}
}

/* this isn't a real socket flush - just emptying our buffer... */
void
pipe_flush (int sockfd)
{
  if (cantflush)  {
	
	UIdebug(4,"INTERNAL ERROR CANT FLUSH ATM - cantflush=%d\n",cantflush);
	FPRINTF(stderr, "INTERNAL ERROR CANT FLUSH ATM\n");
	exit(1);
  }

  if (sock_buff==0) return;
  if (sock_buff[sockfd]==0) return;

  if (strlen (sock_buff[sockfd]) && !is_just_start(sock_buff[sockfd], sockfd))
    {
      char buff[2000]="";
      pipe_sock_write (sockfd, sock_buff[sockfd], strlen (sock_buff[sockfd]));
	if (!handshaking) {
      		SPRINTF(buff,"   null]\n}\n\n");
		
     }
     
      pipe_sock_write (sockfd, buff, strlen (buff));
#ifdef __WIN32__
	if (!using_stdio) {
 		_commit(sockfd);
	}
#else
      	fsync (sockfd);
#endif
   }

	strcpy(sock_buff[sockfd],get_leadin(sockfd));
	sock_buff_sz[sockfd]=strlen(sock_buff[sockfd]);
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
		FPRINTF(stderr, "PIPE_SOCK_PUTS called with str=0");
		exit(2);
  }

  ensure_sock(sockfd);

	UIdebug(4,"sockfd=%d lastsock=%d\n",sockfd,lastsock);


  if ((sockfd != lastsock) && lastsock!=-1)
    {
      pipe_flush (lastsock);
    }
  lastsock = sockfd;


  sz_buff = sock_buff_sz[sockfd];
  if (str)
    {
      sz_str = strlen (str);
    }


  // Do we need to send what we've got ? 
  if (sz_buff > stream_buff_size || sz_str + sz_buff > stream_buff_size || sz_str > stream_buff_size )
    {
	if (cantflush) {
		// We can't flush - we need to increase the buffer size instead...
		stream_buff_size*=2;
		sock_buff[sockfd]=realloc(sock_buff[sockfd] , stream_buff_size);
	} else {
      		if (str != 0) {
	  		UIdebug (4,"BUFFER FULL ;-) %d %d\n", sz_buff, sz_str);
			}

		pipe_flush(sockfd);
        	sz_buff = 0;
	}
    }


  if (str == 0)
    {
      return 1;
    }



  if (sz_str > stream_buff_size)
    {
      // Its too large to cache...
      if (ok)
	{
	  ok = pipe_sock_write (sockfd, str, sz_str);
	}
      return ok;

    }

char *p;
p=sock_buff[sockfd];
//printf("sock_buff[sockfd] before set '%s' : %d, '%s'\n", sock_buff[sockfd],sock_buff_sz[sockfd],str);
if (sock_buff_sz[sockfd]==0) {
	strcpy(sock_buff[sockfd],str);
} else {
	strcat(&p[sock_buff_sz[sockfd]-1],str);
}
sock_buff_sz[sockfd]+=sz_str;
//printf("sock_buff[sockfd] now set to %s\n", sock_buff[sockfd]);
  UIdebug (3,"ADDING TO CACHE : '%s' (%d)\n", str,sockfd);
  //strcat (sock_buff[sockfd], str);
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
      FPRINTF (stderr, "Expecting %s - got '%s'\n", s, buff);
      for (a = 0; a < 17; a++)
	{
	  FPRINTF (stderr, "(%02x %c) ", buff[a] & 0xff,
		  isprint (buff[a]) ? buff[a] : '.');
	}
      FPRINTF (stderr, "\n");
      return 0;
    }
  else
    {
      UIdebug (3,"Got expected : '%s','%s'\n", buff, s);
      return 1;
    }
}


#ifdef USE_ZLIB
int mja_uncompress (unsigned char *dest, unsigned long *destLen, unsigned char *source, unsigned long sourceLen)
{
    z_stream stream;
    int err;

    stream.next_in = (Bytef*)source;
    stream.avail_in = (uInt)sourceLen;
    /* Check for source > 64K on 16-bit machine: */
    if ((uLong)stream.avail_in != sourceLen) return Z_BUF_ERROR;

    stream.next_out = dest;
    stream.avail_out = (uInt)*destLen;
    if ((uLong)stream.avail_out != *destLen) return Z_BUF_ERROR;

    stream.zalloc = (alloc_func)0;
    stream.zfree = (free_func)0;

    err = inflateInit2(&stream,16+MAX_WBITS);
    if (err != Z_OK) return err;

    err = inflate(&stream, Z_FINISH);


    if (err != Z_STREAM_END) {
        inflateEnd(&stream);
        return err == Z_OK ? Z_BUF_ERROR : err;
    }
    *destLen = stream.total_out;

    err = inflateEnd(&stream);

    return err;
}
#endif

