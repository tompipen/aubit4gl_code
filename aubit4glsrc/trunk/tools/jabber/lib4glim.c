/*
From http://www.mingw.org/MinGWiki/index.php/sockets

The official MSDN documentation has some information about porting socket applications:

http://msdn.microsoft.com/library/en-us/winsock/winsock/porting_socket_applications_to_winsock.asp

   1. The first difference to be aware of when porting networking programs to 
   	Windows is that you must call WSAStartup() before using any sockets 
   	functions. If you forget to do this, all Winsock functions will fail when called.
   2. The select() function differs from Unix in that it can only be used for 
   	handles returned by socket() and similar functions, not on other handles 
	like those returned by _open(). The Win32 API provides various functions 
	for waiting on other handles, such as WaitForMultipleObjects().
   3. Similarly, the handles returned by socket() cannot be used with non-socket 
   	system calls like read(), fdopen(), etc.
   4. The names of the header files are also different, e.g. winsock.h or 
   	winsock2.h is used instead of socket.h
   5. Errors in socket functions do not set errno: instead you must call 
   	WSAGetLastError() to find what error occurred

Because of all these differences, many projects use cross-platform wrapper 
libraries instead of the native socket APIs.


*/
#include <sys/time.h>
#include <sys/types.h>

#ifdef __MINGW32__
	//If we dont include winsock2.h, at link time select() will be undefined
	#include <winsock2.h>
	char * a_strchr(char *s,int c);
#endif

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iksemel.h>

struct mydata
{
	iksparser * parser;
	iksid * id;
	char *username;
	char *password;
};

struct ReturnData
{
	int ret_status;
	char *MsgFrom;
	char *MsgBody;
};

static void j_on_log (void *udata, const char *xml, size_t size, int is_incoming);
static int j_on_packet (void *udata, int type, iks *node);
int j_send (char line1[4001], struct mydata net, char to[2000]);
int aclfgl_fgl_4glim (char line1[4001], int timeout, char to[2000], int receive,
	   char *rcv_msg, char *rcv_from, char IM_LOG[80], char IM_USER[80],
	   char IM_PASS[80], int IM_DEBUG);

static int finished;
static int retry;
static int debug = 0;
static FILE *log;

char *MsgFrom;
char *MsgBody;

#ifdef __ASEXEC__

#define J_DEBUG

int
main (int argc, char *argv[])
{
char line[1001], line1[4001], line2[2001];
int timeout;
char to[2000];
int receive;
int success;

	fgets (line1, 2000, stdin);
	fgets (line2, 2000, stdin);
	strcat (line1, line2);

	#ifdef __WIN32__
	{
	unsigned short version;
	int ret;
	WSADATA retdata;
		version = 0x101;
		//int WSAStartup( WORD wVersionRequested, LPWSADATA lpWSAData );
		if(ret = WSAStartup(version, &retdata)) {
			printf("Unable to locate winsock library!\n");
			exit (1);
		}
		if(retdata.wVersion != version) {
			printf("Could not find version 1.1 of winsock dll\n");
			exit (1);
		}
	}
	#endif
	
	
    // Maximum seconds we want to wait to receive message(s)
    timeout = 10;
    // Send message to:
    strcpy (to, "andrej@jabber.org");
    //do we want to wait for message (timeout seconds), or exit immediately
    //after we send
    receive = 1;
	
	
	printf ("Sending msg: '%s' to '%s'\n", line1, to);
	
	success = aclfgl_fgl_4glim (line1, timeout, to, receive,
		NULL, NULL, NULL, NULL, NULL, 1);
		/* int aclfgl_fgl_4glim (char line1[4001], int timeout, char to[2000], int receive,
	   char *rcv_msg, char *rcv_from, char IM_LOG[80], char IM_USER[80],
	   char IM_PASS[80], int IM_DEBUG); */
	//aubit-test@jabber.org
	//aubit


	
	if (! success) {
		printf ("Failed %d\n", success);
	}
	if (MsgFrom) {
		printf ("Msg from: '%s' \n", MsgFrom);
		printf ("Body: '%s'\n", MsgBody);
	}
	exit (success);
}

#endif


/*
	4GL code calls this function to exchange messags.

You may also look at the iksroster.c in iksemel/tools for a 
simple example. It shows how to use new features (secure 
connection, etc).

To make it callable from 4GL, function has to have prefix aclfgl_

*/
int
aclfgl_fgl_4glim (char line1[4001], int timeout, char to[2000], int receive,
	   char *rcv_msg, char *rcv_from, char IM_LOG[80], char IM_USER[80],
	   char IM_PASS[80], int IM_DEBUG)
{
static struct mydata net;
char *p;
int retry;
int sent;
struct timeval tv;
fd_set fds;
int sock;
char line[1001];
FILE * config;

	MsgBody = NULL;
	MsgFrom = NULL;
	net.password = NULL;
	net.username = NULL;		//strdup("test985@jabber.at/notify");
	log = 0;

	#ifdef J_DEBUG
		printf ("IM_USER/IM_PASS: '%s'/'%s'\n", IM_USER,IM_PASS);
		printf ("net.username/net.password: '%s'/'%s'\n", net.username,net.password);		
	#endif
	
	if (!IM_USER || !IM_PASS) {
		if (!net.username || !net.password)	{
			config = fopen ("4glim.conf", "r");
			if (config) {
				while (config && fgets (line, 1000, config))  {
					
					#if defined (__MINGW32__)
						if ((p = a_strchr (line, '\n'))) {
					#else
						if ((p = index (line, '\n'))) {
					#endif
							*p = 0;
						}
						
					#ifdef J_DEBUG
						printf ("line: '%s'\n", line);
					#endif
						
					if (strncasecmp (line, "LOG ", 4) == 0) {
						log = fopen (line + 4, "a");
						#ifdef J_DEBUG
							printf ("Conf: Logging to '%s'\n", line + 4);
						#endif
						
					}
					if (strncasecmp (line, "DEBUG", 5) == 0) {
						debug = 1;
					} else if (strncasecmp (line, "USER ", 5) == 0) {
						net.username = strdup (line + 5);
					} else if (strncasecmp (line, "PASS ", 5) == 0) {
						net.password = strdup (line + 5);
					}
				} //end while
				fclose (config);
			} else {
				printf ("Cannot open config file '4glim.conf'\n");
			}
							
    	} else {
			debug = IM_DEBUG;
			net.username = IM_USER;
			net.password = IM_PASS;
			if (IM_LOG) {
				log = fopen (IM_LOG, "a");
				#ifdef J_DEBUG
					printf ("Logging to '%s'\n", IM_LOG);
				#endif
				
			}
		}
  
		#ifdef J_DEBUG
			printf ("Using account: '%s'/'%s'\n", net.username,net.password);
		#endif
		
		if (!net.username || !net.password)  {
			#ifdef J_DEBUG
				printf ("Missing username/password for sending account\n");
			#endif
			return 2;
		}
		if (!log) {
			log = stderr;
		}
		net.parser = iks_stream_new (IKS_NS_CLIENT, &net, j_on_packet);
		if (!net.parser) {
			return 3;
		}
		iks_set_log_hook (net.parser, j_on_log);
		net.id = iks_id_new (NULL, net.username);
		if (!net.id || !net.id->server || !net.id->user) {
			return 1;
		}
		if (!net.id->resource) {
			net.id->resource = "notify";
		}
		if (!iks_connect_tcp (net.parser, net.id->server, 0)) {
			iks_disconnect (net.parser);
			return 2;
		}
		retry = 2;
		sent = 0;
		while (retry) {
			finished = 0;
			while (!finished) {
				iks_recv (net.parser, 0);
			}
			retry = 0;
			if (!sent) {
				j_send (line1, net, to);
				sent = 1;
			}
			if (debug) {
				fprintf (log, "Waiting (max 20-timeout sec) for data ...\n");
			}
			sock = iks_fd (net.parser);
			FD_ZERO (&fds);
			if (sock != -1)	{
				FD_SET (sock, &fds);
			}
			//tv.tv_sec=20;
			tv.tv_sec = timeout;
			tv.tv_usec = 0;
			if (select (sock + 2, &fds, NULL, NULL, &tv) > 0) {
				if (sock != -1 && (FD_ISSET (sock, &fds))) {
					if (MsgFrom) {
						//if we got the message, return
						break;
					}
				}
				retry = 1;
			}
      
			if (debug) {
				fprintf (log, "done.\n");
			}
      
			if (!receive) {
				//don't wait to receive, exit immediately after message is sent
				break;
			}
		}
		iks_disconnect (net.parser);
		if (MsgFrom) {
			strcpy (rcv_msg, MsgBody);
			strcpy (rcv_from, MsgFrom);
		}
	}
	return 0;
}

int
j_send (char line1[4001], struct mydata net, char to[2000]) {
char text[2000];
char buf[4000];
int pos;
iks * x, *y;
char *p;
  
	x = iks_new ("message");
	iks_insert_attrib (x, "to", to);
	y = iks_insert (x, "body");
	p = line1;
	pos = 0;
  
	while (*p && pos < 3995) {
		if (*(unsigned char *) p < 0x80) {
			buf[pos++] = *p;
		} else 	{
			buf[pos++] = (0xC0 | (0x03 & (*p >> 6)));
			buf[pos++] = (0x80 | (0x3F & *p));
		}
		p++;
    }
	buf[pos] = 0;
	iks_insert_cdata (y, buf, -1);
	iks_send (net.parser, x);
	iks_delete (x);
}

static void
j_on_log (void *udata, const char *xml, size_t size, int is_incoming){

	if (!debug) {
		return;
	}
  
	if (is_incoming) {
		fprintf (log, "[RECV]\n");
	} else {
		fprintf (log, "[SEND]\n");
	}
	fprintf (log, "%s\n\n", xml);
}

static int
j_on_packet (void *udata, int type, iks *node) {
struct mydata *net = (struct mydata *) udata;
ikspak *pak;
iks * x;
char *id;

	if (!node) {
		finished = 1;
		return IKS_OK;
    }
  
	if (retry < 2) {
		finished = 1;
	}
  
	switch (type) {
		case IKS_NODE_START:
			x =
			iks_make_auth (net->id, net->password,
		       iks_find_attrib (pak->x, "id"));
			iks_insert_attrib (x, "id", "auth");
			iks_send (net->parser, x);
			iks_delete (x);
			break;
		case IKS_NODE_NORMAL:
			pak = iks_packet (node);
			switch (pak->type) {
				case IKS_PAK_MESSAGE:
			id = iks_find_attrib (pak->x, "from");
			MsgFrom = id;
			MsgBody = iks_find_cdata (pak->x, "body");
			fprintf (log, "Msg from: '%s' \n", id);
			fprintf (log, "Body: '%s'\n", iks_find_cdata (pak->x, "body"));
			if ((x = iks_find (pak->x, "error"))) {
				fprintf (log, "Error %s:'%s'\n", iks_find_attrib (x, "code"),
					iks_find_cdata (pak->x, "error"));
			}
			finished = 1;
			break;
		case IKS_PAK_IQ:
			id = iks_find_attrib (pak->x, "id");
			if (iks_strcmp (id, "auth") == 0){
				if (pak->subtype == IKS_TYPE_RESULT)  {
					x = iks_make_iq (IKS_TYPE_GET, IKS_NS_ROSTER);
					iks_send (net->parser, x);
					iks_delete (x);
				}
			} else if (iks_strcmp (pak->ns, IKS_NS_ROSTER) == 0) {
				switch (pak->subtype) {
					case IKS_TYPE_RESULT:
						x = iks_make_pres (0, NULL);
						iks_send (net->parser, x);
						iks_delete (x);
						finished = 1;
					case IKS_TYPE_SET:
						x = iks_child (pak->query);
						iks_delete (pak->x);
						break;
					default:
						printf ("parse roster failed\n");
						iks_delete (pak->x);
				}
			}
			break;
		}
    }
    return IKS_OK;
}

#ifdef __MINGW32__
//replacement for index() function missing on MinGW
char *
a_strchr(char *s,int c) {
int a;
	if (s==0) return 0;
	
	for (a=0;a<strlen(s);a++) {
			if (s[a]==c) return &s[a];
	}
	return 0;
}
#endif

// ----------------------------- EOF -----------------------------

