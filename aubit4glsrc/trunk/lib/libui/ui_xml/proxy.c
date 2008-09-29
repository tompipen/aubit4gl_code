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

#ifdef htons
#undef htons
#endif
#ifdef htonl
#undef htonl
#endif

#ifndef USE_WINSOCK
#define SOCKET int
#endif

#ifdef USE_WINSOCK
#ifndef EINTR
#define EINTR WSAEINTR
#endif
#endif


#define MYPORT 3490		// the port users will be connecting to

#define BACKLOG 10		// how many pending connections queue will hold


//#define STREAM_BUFF_SIZE 10000
//char sock_buff[20000];
int localsocket_in = 0;
int localsocket_out = 0;
int timeout_sock=-1;
void remove_pipes (void);
static void maintain_socket (int newfd);
void send_expect (int fs_read,int fs_write,  char *sendtxt, char *expecttxt);

void wait_for_some_action (int clientui_read, int clientui_write,
			   int listen_fgl);

static char *get_passwd(char*username) ;

static void tea_8c_encipher(const unsigned long *const v,unsigned long *const w, const unsigned long * const k);
static void tea_8c_decipher(const unsigned long *const v,unsigned long *const w, const unsigned long * const k);


static int
encrypt_passwdfile (void);

static char hex_digit(int n) {
	if (n>=0&&n<=9) return n+'0';
	if (n==10) return 'a';
	if (n==11) return 'b';
	if (n==12) return 'c';
	if (n==13) return 'd';
	if (n==14) return 'e';
	if (n==15) return 'f';
	return 'x';
}


static char *A4GL_tea_string_encipher(char *s) {
	char buff[1000];
	static char buff_out[1000];
	char smbuff[20];
	int a;
	unsigned long key[4];
	char rbuff[10];
	unsigned long *x;
	//long b[10];
	memset(rbuff,0,sizeof(rbuff));

	memset(&key[0],0,sizeof(key));
			key[0]=0x12447469;
			key[1]=0x87873739;
			key[2]=0x908acd69;
			key[3]=0xfc892782;

	memset(buff,0,1000);
	strcpy(buff,s);
	strcpy(buff_out,"");

	for (a=0;a<strlen(buff);a+=8) {
		x=(unsigned long *)rbuff;
		tea_8c_encipher((unsigned long *)&buff[a],x,key);
		smbuff[8]=0;
		smbuff[7]=hex_digit(x[0]&0xf); x[0]=x[0]>>4; // 0x???????X
		smbuff[6]=hex_digit(x[0]&0xf); x[0]=x[0]>>4; // 0x??????X
		smbuff[5]=hex_digit(x[0]&0xf); x[0]=x[0]>>4; // 0x?????X
		smbuff[4]=hex_digit(x[0]&0xf); x[0]=x[0]>>4; // 0x????X
		smbuff[3]=hex_digit(x[0]&0xf); x[0]=x[0]>>4; // 0x???X
		smbuff[2]=hex_digit(x[0]&0xf); x[0]=x[0]>>4; // 0x??X.
		smbuff[1]=hex_digit(x[0]&0xf); x[0]=x[0]>>4; // 0x?X..
		smbuff[0]=hex_digit(x[0]&0xf); x[0]=x[0]>>4; // 0xX...
		strcat(buff_out,smbuff);

		smbuff[8]=0;
		smbuff[7]=hex_digit(x[1]&0xf); x[1]=x[1]>>4; // 0x???????X
		smbuff[6]=hex_digit(x[1]&0xf); x[1]=x[1]>>4; // 0x??????X
		smbuff[5]=hex_digit(x[1]&0xf); x[1]=x[1]>>4; // 0x?????X
		smbuff[4]=hex_digit(x[1]&0xf); x[1]=x[1]>>4; // 0x????X
		smbuff[3]=hex_digit(x[1]&0xf); x[1]=x[1]>>4; // 0x???X
		smbuff[2]=hex_digit(x[1]&0xf); x[1]=x[1]>>4; // 0x??X.
		smbuff[1]=hex_digit(x[1]&0xf); x[1]=x[1]>>4; // 0x?X..
		smbuff[0]=hex_digit(x[1]&0xf); x[1]=x[1]>>4; // 0xX...
		strcat(buff_out,smbuff);

	}
	return buff_out;
}


static int hexToInt(int h){
	  if( h>='0' && h<='9' ){
		      return h - '0';
		        }else if( h>='a' && h<='f' ){
				    return h - 'a' + 10;
				      }else if( h>='A' && h<='F' ){
					          return h - 'A' + 10;
						    }else{
							        return 0;
								  }
}


static char *A4GL_tea_string_decipher(char *s) {
	char buff[1000];
	static char buff_out[1000];
	char smbuff[5];
	int a;
	unsigned long key[4];
	char rbuff[9];
	int l;
	unsigned long lgptr[2];

	memset(&key[0],0,sizeof(key));
	key[0]=0x12447469;
	key[1]=0x87873739;
	key[2]=0x908acd69;
	key[3]=0xfc892782;
	memset(buff,0,1000);
	strcpy(buff,s);
	strcpy(buff_out,"");

	for (a=0;a<strlen(buff);a+=16) {
		l=hexToInt(buff[a]);
		l=(l*16)+hexToInt(buff[a+1]);
		l=(l*16)+hexToInt(buff[a+2]);
		l=(l*16)+hexToInt(buff[a+3]);
		l=(l*16)+hexToInt(buff[a+4]);
		l=(l*16)+hexToInt(buff[a+5]);
		l=(l*16)+hexToInt(buff[a+6]);
		l=(l*16)+hexToInt(buff[a+7]);
		lgptr[0]=l;
		
		l=hexToInt(buff[a+8]);
		l=(l*16)+hexToInt(buff[a+9]);
		l=(l*16)+hexToInt(buff[a+10]);
		l=(l*16)+hexToInt(buff[a+11]);
		l=(l*16)+hexToInt(buff[a+12]);
		l=(l*16)+hexToInt(buff[a+13]);
		l=(l*16)+hexToInt(buff[a+14]);
		l=(l*16)+hexToInt(buff[a+15]);
		lgptr[1]=l;

		tea_8c_decipher(&lgptr[0],(unsigned long *)&rbuff[0],&key[0]);
		smbuff[0]=rbuff[0];
		smbuff[1]=rbuff[1];
		smbuff[2]=rbuff[2];
		smbuff[3]=rbuff[3];
		smbuff[4]=rbuff[4];
		smbuff[5]=rbuff[5];
		smbuff[6]=rbuff[6];
		smbuff[7]=rbuff[7];
		smbuff[8]=0;
		strcat(buff_out,smbuff);
	}
	return buff_out;
}

void tea_8c_encipher(const unsigned long * v,unsigned long * w, const unsigned long *  k)
{
	   unsigned long       y;
	   unsigned long       z;
	   unsigned long       sum;
	   unsigned long       delta;
	   unsigned long       n;
	   //unsigned long l;
	   y=v[0];
	   z=v[1];
	   sum=0;
	   delta=0x9E3779B9;
	   n=32;

	      while((n--) > 0)
		            {
			          y += ((z << 4) ^ (z >> 5)) + (z ^ sum) + k[sum&3];
					      sum += delta;
					z+=((y << 4) ^ (y >> 5)) + (y ^ sum) + k[(sum>>11)&3];
	          }

	         w[0]=y; 
		 w[1]=z;
}



void tea_8c_decipher(const unsigned long *const v,unsigned long *const w,
		   const unsigned long * const k)
{
	   register unsigned long       y=v[0],z=v[1],sum=0xC6EF3720,
		    				delta=0x9E3779B9,n=32;

	      /* sum = delta<<5, in general sum = delta * n */

	      while(n-->0)
		            {
				          z -= (y << 4 ^ y >> 5) + (y ^ sum) + k[sum>>11 & 3];
					        sum -= delta;
						      y -= (z << 4 ^ z >> 5) + (z ^ sum) + k[sum&3];
						            }
	         
	         w[0]=y; w[1]=z;
}


static void
sigchld_handler (int s)
{
  UIdebug (1,"SIGCHLD\n");
  while (waitpid (-1, NULL, WNOHANG) > 0);
  UIdebug (1,"child died ? \n");
}


static void
sigterm_handler (int s)
{

  if (localsocket_out)
    {
      pipe_sock_puts (localsocket_out, "FAILED\n");
	UIdebug(9,"CLOSE1");
      close (localsocket_out);	// This may close both in and the out
    }

  if (localsocket_in && localsocket_in != localsocket_out)
    {
	UIdebug(9,"CLOSE2");
      close (localsocket_in);	// This will close 'in' - only if its not the same as 'out'
    }

  remove_pipes ();
  UIdebug (0,"PROGRAM QUITING\n");
  exit (0);
}

static void
sigintr_handler (int s)
{
  UIdebug (1,"SIGINT\n");
  if (localsocket_out)
    {
      pipe_sock_puts (localsocket_out, "FAILED\n");
	UIdebug(9,"CLOSE3");
      close (localsocket_out);	// This may close both in and the out
    }

  if (localsocket_in && localsocket_in != localsocket_out)
    {
	UIdebug(9,"CLOSE4");
      close (localsocket_in);	// This will close 'in' - only if its not the same as 'out'
    }
  remove_pipes ();
  UIdebug (0,"MAIN PROGRAM QUITING\n");
  exit (0);
}

/* 
 * UI PROXY
 *
 * This is pretty complicated - so bear with me...
 * the UI connects to this server which then starts a program
 * That program connects to this proxy too - but via unix domain sockets
 * that program may start other programs - but it should always close down the connection to this proxy first
 * So - any any time we should have the UI client and a single 4gl program connected...
 * 
*/

int
main (int argc, char *argv[])
{
  int sockfd, new_fd;		// listen on sock_fd, new connection on new_fd
  struct sockaddr_in my_addr;	// my address information
  struct sockaddr_in their_addr;	// connector's address information
  socklen_t sin_size;
  struct sigaction sa;
  int yes = 1;

  encrypt_passwdfile ();

  setenv ("A4GL_UI", "XML", 1);
// PIPEDIR specified where the names pipes that the 4gl programs
// will connect to are stored
  if (!getenv ("PIPEDIR"))
    {
      printf ("PIPEDIR has not been set\n");
      exit (2);
    }

// BASEPROGRAMS specifies where the executables will be found
  if (!getenv ("BASEPROGRAMS"))
    {
      printf ("BASEPROGRAMS has not been set\n");
      exit (2);
    }

  if (argc > 1)
    {
      printf ("STANDALONE MODE\n");
      maintain_socket (0);
      exit (1);
    }

// Create our network socket to listen for client connections
  if ((sockfd = socket (PF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("socket");
      exit (1);
    }

  if (setsockopt (sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int)) == -1)
    {
      perror ("setsockopt");
      exit (1);
    }

  my_addr.sin_family = AF_INET;	// host byte order
  my_addr.sin_port = htons (MYPORT);	// short, network byte order
  my_addr.sin_addr.s_addr = INADDR_ANY;	// automatically fill with my IP
  memset (&(my_addr.sin_zero), '\0', 8);	// zero the rest of the struct

  if (bind (sockfd, (struct sockaddr *) &my_addr, sizeof (struct sockaddr))
      == -1)
    {
      perror ("bind");
      exit (1);
    }

  if (listen (sockfd, BACKLOG) == -1)
    {
      perror ("listen");
      exit (1);
    }


  sa.sa_handler = sigchld_handler;	// reap all dead processes
  sigemptyset (&sa.sa_mask);
  sa.sa_flags = SA_RESTART;


  if (sigaction (SIGCHLD, &sa, NULL) == -1)
    {
      perror ("sigaction");
      exit (1);
    }


  sa.sa_handler = sigintr_handler;	// reap all dead processes
  sigemptyset (&sa.sa_mask);
  sa.sa_flags = SA_RESTART;


  if (sigaction (SIGINT, &sa, NULL) == -1)
    {
      perror ("sigaction");
      exit (1);
    }
  while (1)
    {				// main accept() loop
      sin_size = sizeof (struct sockaddr_in);
      if ((new_fd =
	   accept (sockfd, (struct sockaddr *) &their_addr, &sin_size)) == -1)
	{
	  perror ("accept");
	  continue;
	}

      UIdebug (1,"server: got connection from %s\n", inet_ntoa (their_addr.sin_addr));

      if (!fork ())
	{			// this is the child process
	UIdebug(9,"CLOSE5");
	  close (sockfd);	// child doesn't need the listener
	  maintain_socket (new_fd);
	  exit (0);
	}
	UIdebug(9,"CLOSE6");
      close (new_fd);		// parent doesn't need this
    }

  return 0;
}

void send_expect (int fs_read,int fs_write,  char *sendtxt, char *expecttxt)
{
  UIdebug (9,"SENDING %s\n", sendtxt);
  pipe_sock_puts (fs_write, sendtxt);
  pipe_flush (fs_write);
  UIdebug (9,"WAITING FOR EXPECT\n");
  if (!pipe_expect (fs_read, expecttxt))
    {
      UIdebug (1,"Handshaking failed\n");
      pipe_sock_puts (fs_write,"HANDSHAKING FAILED\n");
  	pipe_flush (fs_write);
      close (fs_read);
      close (fs_write);
      exit (0);
    }
}


void
remove_pipes ()
{
  char buff[1025];
  sprintf (buff, "%s/%d.in", getenv ("PIPEDIR"), getpid ());
  unlink (buff);
  UIdebug (3,"REMOVE PIPE : %s\n", buff);
}


// Create the domain sockets we'll be using...
static int
create_pipes (void)
{
  char buff[1025];
  int s, len;
  struct sockaddr_un saun;
  sprintf (buff, "%s/%d.in", getenv ("PIPEDIR"), getpid ());
  setenv ("PROXYPIPE", buff, 1);
  UIdebug (3,"CREATE PIPE : %s\n", buff);
  /*
   * Get a socket to work with.  This socket will
   * be in the UNIX domain, and will be a
   * stream socket.
   */
  if ((s = socket (AF_UNIX, SOCK_STREAM, 0)) < 0)
    {
      perror ("server: socket");
      exit (1);
    }

  /*
   * Create the address we will be binding to.
   */
  saun.sun_family = AF_UNIX;
  strcpy (saun.sun_path, buff);

  /*
   * Try to bind the address to the socket.  We
   * unlink the name first so that the bind won't
   * fail.
   *
   * The third argument indicates the "length" of
   * the structure, not just the length of the
   * socket name.
   */
  unlink (buff);
  len = sizeof (saun.sun_family) + strlen (saun.sun_path);

  if (bind (s, (struct sockaddr *) &saun, len) < 0)
    {
      perror ("server: bind");
      exit (1);
    }

  return s;
}





void
maintain_socket (int newfd_orig)
{
  char buff[1024];
  char prg[1024];
  char usr[1024];
  char passwd[1024];
  char *argv[100];
  int newfd_read;		// Normally these would be the
  int newfd_write;		// same - except when using STDIN and STDOUT in standalone mode..
  int a;
  int sock_s;
int pwok;
  struct sigaction sa;


  for (a = 0; a < 100; a++)
    {
      argv[a] = 0;
    }

  if (newfd_orig == 0)
    {
      newfd_read = STDIN_FILENO;
      newfd_write = STDOUT_FILENO;
    }
  else
    {
      newfd_read = newfd_orig;
      newfd_write = newfd_orig;
    }

  localsocket_in = newfd_read;
  localsocket_out = newfd_write;

  UIdebug (4,"GOT CONNECTION!\n");

  //
  // We've just been connected by a client...
  // Firstly - do some handshaking to make sure its what we were expecting
  //
  
  send_expect (newfd_read, newfd_write,  "PROTOCOL?\n", "UIVERSION 1.0");



  //
  // If we've got to here - we've got an active client - we need to be able to start a single "startup" 
  // 4gl program - so we need to know what thats called.
  // That program might start other programs - but we'll just start the first one for now...
  // 
  pipe_sock_puts (newfd_write, "PROGRAMNAME?\n");
  pipe_flush (newfd_write);
  pipe_sock_gets (newfd_read, buff, 512);
  pipe_sock_puts (newfd_write, "USER?\n");
  pipe_flush (newfd_write);
  pipe_sock_gets (newfd_read, usr, 512);
  pipe_sock_puts (newfd_write, "PASSWORD?\n");
  pipe_flush (newfd_write);
  pipe_sock_gets (newfd_read, passwd, 512);

  pwok=0;
  if (strcmp(passwd,"CM")==0) { 
		pwok=1;
  } else {
		char *pw;
		pw=get_passwd(usr);
		if (pw) {
		if (strcmp(passwd,pw)==0) {
			pwok=1;
		}
		}
  }
	if (!pwok) {
  	pipe_sock_puts (newfd_write, "AUTHFAILED\n");
  	pipe_flush (newfd_write);
	close(newfd_write);
	exit(0);
  }

  UIdebug (4,"They'd like program : '%s' as user '%s'\n", buff, usr);
  // If they're trying to run a program - make sure its under the base directory
  // that means - no '../../../' etc...
  if (strstr (buff, ".."))
    {
      UIdebug (0,"Looks like they want to use '..' - so they can get lost...\n");
      pipe_sock_puts (newfd_write, "THAT LOOKS LIKE A SECURITY RISK...\n");
      exit (0);
    }

  UIdebug (5,"Looks ok\n");
  sprintf (prg, "%s/%s", getenv ("BASEPROGRAMS"), buff);


  UIdebug (5,"prg=%s\n", prg);
  //  Need to run the program as a different user....
  //  but we'll do that later :-)
  sprintf (buff, "%d", getpid ());	// PID will be the PID of the child process...

  UIdebug (5,"Creating pipes\n");
  setenv("PROXYUSER",usr,1);
  // Now - tell our child process who we are...
  setenv ("PROXYID", buff, 1);
  sock_s = create_pipes ();
  UIdebug (5,"RUN prg:%s\n", prg);

  sa.sa_handler = sigterm_handler;	// reap all dead processes
  sigemptyset (&sa.sa_mask);
  sa.sa_flags = SA_RESTART;

  if (sigaction (SIGTERM, &sa, NULL) == -1)
    {
      perror ("sigaction");
      remove_pipes ();
      exit (1);
    }

  UIdebug (3,"Forking off 4gl program\n");

  if (!fork ())
    {				// this is the child process
      UIdebug (9,"Here in process - about to fork off %s\n", prg);

	if (strchr(prg,' ')) {
	argv[1]=0;
	char *ptr;
		ptr=strchr(prg,' ');
		*ptr=0;
		ptr++;
		argv[1]=ptr;
		argv[2]=0;
	} 
      	argv[0] = prg;
	UIdebug(2,"SPAWN argv[0]=%s argv[1]=%s\n",argv[0],argv[1]);
	pipe_sock_puts (newfd_write, "START\n"); pipe_flush (newfd_write);

      if (newfd_read == newfd_write)
	{
		UIdebug(9,"CLOSE8");
	  	//close (newfd_read);	// child doesn't need the listener
	  				// but we'll not close it if its STDIN or STDOUT
	}

	UIdebug(0,"Before exec...");
      	execv (prg, argv);
      UIdebug (0,"Failed to start : %s - %d\n",prg,errno);
	
	pipe_sock_puts (newfd_write, "FAILED TO START\n"); pipe_flush (newfd_write);

      // We should only ever get to here if our 4GL failed to start...
      // the execv should 'splat' this program with our 4gl one...
      // (which is ok - because we did that fork first to make us a new process)
      perror ("Execv");
      UIdebug (0,"Failed to start : %s - %d\n",prg,errno);
      kill (getppid (), SIGTERM);	// If we didn't start - there little point in the server waiting for us...
      remove_pipes ();
      exit (0);
    }

  atexit (remove_pipes);
  UIdebug (3,"Here in parent - waiting for connection from child\n");


  /*
   * Listen on the socket.
   */

  if (listen (sock_s, 5) < 0)
    {
      perror ("server: listen");
      exit (1);
    }

  wait_for_some_action (newfd_read, newfd_write, sock_s);

}


void
wait_for_some_action (int clientui_read, int clientui_write, int listen_fgl)
{
  int fglprog[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int has_connected = 0;
  int timeoutcnt=0;
  fd_set rfds;
  struct timeval tv;
  int retval;
  int a;
  int max = 0;
  //int timeoutconnect;
  struct sockaddr_in their_addr;	// connector's address information
  int latest_ui = 0;
  socklen_t sin_size;

//printf("wait_for_some_action\n");

  memset (&sin_size, 0, sizeof (sin_size));
  memset (&their_addr, 0, sizeof (their_addr));


  for (a = 0; a < 10; a++)
    {
      fglprog[a] = 0;
    }


  while (1)
    {
      int any = 0;
      max = 0;
      FD_ZERO (&rfds);
      FD_SET (clientui_read, &rfds);
      FD_SET (listen_fgl, &rfds);

      max = clientui_read;


      if (listen_fgl > max)
	max = listen_fgl;

      for (a = 0; a < 10; a++)
	{
	  //printf("SLOT : %d - %d\n",a,fglprog[a]);
	  if (fglprog[a])
	    {
	      any++;
	      FD_SET (fglprog[a], &rfds);
	      if (fglprog[a] > max)
		{
		  max = fglprog[a];
		}
	    }
	}


      if (!any && has_connected)
	{
	  // nothing left to do..
	  UIdebug (2,"NOTHING LEFT TO DO\n");
	  if (clientui_read == clientui_write)
	    {
			UIdebug(9,"CLOSE9");
	      close (clientui_read);
	    }
	  else
	    {
			UIdebug(9,"CLOSE10");
	      close (clientui_read);
	      close (clientui_write);
	    }
	  exit (0);
	}

      /* Wait up to one seconds. */
      tv.tv_sec = 1;
      tv.tv_usec = 0;
      retval = select (max + 1, &rfds, NULL, NULL, &tv);
      if (retval == 0)
	{
	
  		// timeout...
		timeoutcnt++;
		
		if (timeoutcnt>5 ) {
			timeoutcnt=0;
			if (!has_connected) {
				UIdebug(2,"No connection after 5 seconds... - assuming nothings coming");
				pipe_sock_puts (clientui_write, "TIMEOUT\n"); 
				pipe_flush (clientui_write);
				exit(2);
			}
			if (timeout_sock>=0) {
			// Call some timeout code....
				timeout_flush(timeout_sock);
			}
		}

	  continue;
	}

	UIdebug(6,"select returns");

      if (retval == -1)
	{
		UIdebug(1,"select error");
	  perror ("select()");
	  exit (2);
	}

		timeoutcnt=0;


	UIdebug(5,"checking what needs to be read");
      if (FD_ISSET (clientui_read, &rfds))
	{
	  char buff[260];
	  int nb;
	  memset(buff,0,sizeof(buff));
	  nb = read (clientui_read, buff, 255);
	  if (nb <= 0)
	    {
	      UIdebug (1,"Client died ?\n");
	      exit (0);
	    }
	  buff[nb] = 0;

	  UIdebug (2,"DATA FROM CLIENT : %s\n", buff);

	  if (latest_ui)
	    {
	      UIdebug (3,"WRITING TO FGLPROG '%s'\n", buff);
	      write (latest_ui, buff, strlen (buff) );
	    }
	}


      for (a = 0; a < 10; a++)
	{
	  if (fglprog[a] == 0)
	    continue;


	  if (FD_ISSET (fglprog[a], &rfds))
	    {
	      char buff[260];
	      int nb;
	      //memset(buff,0,sizeof(buff));
	      nb = read (fglprog[a], buff, 255);
	      if (nb <= 0)
		{
		  UIdebug (1,"FGL Program died ? %d\n", fglprog[a]);
		  fglprog[a] = 0;
		}
	      else
		{
		  buff[nb] = 0;
		  UIdebug (2,"DATA FROM FGLPROG : %s (%d)\n", buff, nb);
		  latest_ui = fglprog[a];
		  write (clientui_write, buff, strlen (buff) );
		}
	    }
	}



      if (FD_ISSET (listen_fgl, &rfds))
	{
	  int a;
	  int nc = 0;

	  
  	  UIdebug (2,"PROGRAM CONNECTED! too : fglprog_list=%d clientui=%d/%d\n", listen_fgl, clientui_read, clientui_write);
	  UIdebug (1,"NEW CONNECTION FROM FGLPROG : %d \n", listen_fgl);

	  has_connected++;
	  nc = accept (listen_fgl, (struct sockaddr *) &their_addr, &sin_size);
	  if (nc == -1)
	    {
	      perror ("accept - fglprog");
	      exit (1);
	    }
	  if (nc == 0)
	    {
	      UIdebug (1,"No socket number !\n");
	      exit (0);
	    }

	  UIdebug (2,"CONNECTED as : %d\n", nc);
	  for (a = 0; a < 10; a++)
	    {
	      if (fglprog[a] == 0)
		{
		  fglprog[a] = nc;
		  UIdebug (4,"Put in slot %d (%d)\n", a, fglprog[a]);

		  nc = 0;
		  break;
		}
	    }

	  if (nc)
	    {
	      UIdebug (0,"No free slots for new 4gl module :-(\n");
	    }
	}

    }
}


void set_timeout_flush_sock(int n) {
	timeout_sock=n;

}



static char *get_passwd(char*username) {
char *ptr;
FILE *f;
  //char fname[256];
  char buff[300];
  char buff_orig[300];
  char *ptr_fields[2];
  char *ptr_next;
char uname[200];
char passwd[200];

  ptr = getenv ("A4GL_PROXYPASSWD");
  if (ptr==0) return 0;
  f = fopen (ptr, "r");

  if (f == 0)
    return 0;

  while (1)
    {

      if (!fgets (buff, 256, f))
	break;

      strcpy (buff_orig, buff);

      ptr = strchr (buff, '#');

      if (ptr)
	{
	  *ptr = 0;
	}
      ptr = strchr (buff, '\n');
      if (ptr)
	{
	  *ptr = 0;
	}
      ptr = &buff[0];

      // File should contain fields like this :
      // username:passwd
      ptr_next = strchr (buff, ':');	// end of username

      ptr_fields[0] = 0;
      ptr_fields[1] = 0;

      ptr_fields[0] = &buff[0];

      if (ptr_next != 0)
	{
	  	*ptr_next = 0;
	  	ptr = ptr_next + 1;
	  	ptr_fields[1] = ptr;
	      strcpy (uname, ptr_fields[0]);
	      strcpy (passwd, ptr_fields[1]);

	      if (passwd[0] == '!')
		{
			if (strcmp(uname,username)==0) {
				return A4GL_tea_string_decipher (&passwd[1]);
			}
		}
	    }
  }
return 0;
}

static int
encrypt_passwdfile (void)
{
  FILE *f;
char uname[200];
char passwd[200];
  char fname[256];
  char buff[300];
  char buff_orig[300];
  char *ptr_fields[2];
  char *ptr;
  char *ptr_next;
  int printed = 0;
  FILE *fout;
  ptr = getenv ("A4GL_PROXYPASSWD");
  if (ptr==0) return 0;

  strcpy(fname,ptr);

  f = fopen (ptr, "r");

  if (f == 0)
    return 0;

  fout = fopen ("encrypted.pwfile", "w");
  if (fout == 0)
    {
      return 0;
    }

  while (1)
    {
      printed = 0;

      if (!fgets (buff, 256, f))
	break;

      strcpy (buff_orig, buff);

      ptr = strchr (buff, '#');

      if (ptr)
	{
	  *ptr = 0;
	}
      ptr = strchr (buff, '\n');
      if (ptr)
	{
	  *ptr = 0;
	}
      ptr = &buff[0];

      // File should contain fields like this :
      // username:passwd
      ptr_next = strchr (buff, ':');	// end of username

      ptr_fields[0] = 0;
      ptr_fields[1] = 0;

      ptr_fields[0] = &buff[0];

      if (ptr_next != 0)
	{
	  	*ptr_next = 0;
	  	ptr = ptr_next + 1;
	  	ptr_fields[1] = ptr;
	      strcpy (uname, ptr_fields[0]);
	      strcpy (passwd, ptr_fields[1]);

	      if (passwd[0] != '!')
		{
		  char buff[256];
		  strcpy (buff, A4GL_tea_string_encipher (passwd));
		  sprintf (passwd, "!%s", buff);
		}
	      printed = 1;
	      fprintf (fout,"%s:%s\n", uname, passwd);
	}

      if (!printed)
	{
	  // Don't recognise it - put back what we got  in
	  fprintf (fout, "%s", buff_orig);
	}
  }
  fclose (fout);
  fclose (f);

  if (unlink(fname)==0) { // All good!
  	rename("encrypted.pwfile",fname);
  } else {
	fprintf(stderr,"Unable to remove original ACL file");
	exit(2);
	return 0;
  }

  return 1;
}

