#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iksemel.h>


struct mydata {
	iksparser *parser;
	iksid *id;
	char *username;
	char *password;
};

struct ReturnData {
	int ret_status;
	char *MsgFrom;
	char *MsgBody;
};


static void j_on_log(void *udata, char *xml, int dir) ;
static void j_on_packet(void *udata, ikspak *pak);
static int finished;
static int retry;
static int debug=0;
static FILE *log;


	char *MsgFrom ;
	char *MsgBody ;

#ifdef __ASEXEC__

int main(int argc, char *argv[]){

	char line[1001],line1[4001],line2[2001];
    int timeout;
   	char to[2000];
    int receive;
    int success;

	fgets(line1,2000,stdin);
	fgets(line2,2000,stdin);
	strcat(line1,line2);


	// Maximum seconds we want to wait to receive message(s)
	timeout=10;

	// Send message to:
	strcpy(to,"andrej@jabber.org");

	//do we want to wait for message (timeout seconds), or exit immediately
    //after we send
	receive=1;

    success = fgl_4glim(line1,timeout,to,receive);


   	if ( MsgFrom ) {
		printf("Msg from: '%s' \n",MsgFrom);
		printf("Body: '%s'\n",MsgBody);
    }

    return 0;

}

#endif

int fgl_4glim(char line1[4001], int timeout, char to[2000], int receive, char *rcv_msg, char *rcv_from, char IM_LOG[80], char IM_USER[80], char IM_PASS[80], int IM_DEBUG){

	static struct mydata net;

	char *p;

	int retry;
	int sent;
	struct timeval tv;
	fd_set fds;
	int sock;
	char line[1001];
	FILE *config;

	MsgBody=NULL;
	MsgFrom=NULL;

	net.password=NULL;
	net.username=NULL; //strdup("test985@jabber.at/notify");
	log=0;


	if ( !IM_USER || !IM_PASS) {

		if ( !net.username || !net.password) {
		config=fopen("4glim.conf","r");
			while (config && fgets(line,1000,config)) {
				if ( (p =index(line,'\n')) )
				       *p=0;
				if( strncasecmp(line,"LOG ",4) == 0 )
					log = fopen(line+4,"a");
				if( strncasecmp(line,"DEBUG",5) == 0 )
					debug = 1;
				else if ( strncasecmp(line,"USER ",5) == 0 )
					net.username=strdup(line+5);
				else if ( strncasecmp(line,"PASS ",5) == 0 )
					net.password=strdup(line+5);
			}
		if (config)
			fclose(config);
        }

    } else {

		debug = IM_DEBUG;
		net.username=IM_USER;
		net.password=IM_PASS;

		if ( IM_LOG) {
			log = fopen(IM_LOG,"a");
        }

    }


	if ( !net.username || !net.password) {
		return 2;
    }


	if ( !log) log = stderr;


	net.parser = iks_jabber_new(&net,j_on_packet);
	if( !net.parser )
		return 3;
	iks_set_logging(net.parser,j_on_log);
	net.id = iks_id_new(NULL, net.username );

	if( !net.id || !net.id->server || !net.id->user )
		return 1;

	if(!net.id->resource) net.id->resource = "notify";

	if(!iks_connect_tcp(net.parser, net.id->server, 0)) {
		iks_disconnect(net.parser);
		return 2;
	}


	retry=2;sent=0;
	while(retry){
		finished=0;
		while(!finished) {
			iks_recv(net.parser, 0);
		}
		retry=0;
		if( !sent ) {
			j_send(line1, net, to);
			sent=1;
		}
		if (debug )
		fprintf(log,"Waiting (max 20-timeout sec) for data ...\n");

		sock = iks_fd(net.parser);
		FD_ZERO(&fds);
		if(sock != -1)
		{
			FD_SET(sock, &fds);
		}
		//tv.tv_sec=20;
        tv.tv_sec=timeout;
		tv.tv_usec=0;
		if(select(sock + 2, &fds, NULL, NULL, &tv) > 0) {
			if(sock != -1 && (FD_ISSET(sock, &fds) ))

			   	if ( MsgFrom ) {
                    //if we got the message, return
					break;
                }

				retry=1;
		}
		if (debug)
		fprintf(log,"done.\n");

		if( !receive ) {
            //don't wait to receive, exit immediately after message is sent
            break;
        }
	}

	iks_disconnect(net.parser);

    if (MsgFrom) {
		strcpy(rcv_msg,MsgBody);
		strcpy(rcv_from,MsgFrom);
    }

	return 0;
}


int j_send(char line1[4001], struct mydata net,	char to[2000]) {

	char text[2000];
	char buf[4000];
	int pos;
	iks *x,*y;
	char *p;

			x = iks_new("message");
			iks_insert_attrib(x, "to", to);
			y = iks_insert(x, "body");
			p=line1;pos=0;
			while( *p && pos<3995) {
				if( *(unsigned char*)p < 0x80 )
					buf[pos++]=*p;
				else
				{
					buf[pos++]=(0xC0 | (0x03 & (*p >> 6)));
					buf[pos++]=(0x80 | (0x3F & *p));

				}
				p++;
			}
			buf[pos]=0;
			iks_insert_cdata(y, buf, -1);
			iks_send(net.parser,x);
			iks_delete(x);

}


static void j_on_log(void *udata, char *xml, int dir) {
	if (!debug) return;
	if(dir == IKS_DIR_IN) fprintf(log, "[RECV]\n"); else fprintf(log, "[SEND]\n");
	fprintf(log, "%s\n\n", xml);
}



static void j_on_packet(void *udata, ikspak *pak) {
	struct mydata *net=(struct mydata*)udata;
	iks *x;
	char *id ;

	if( !pak ) {
		finished=1;
		return;
	}
	if(retry<2)
		finished=1;
	switch(pak->type) {
		case IKS_PAK_STREAM:
			x = iks_make_auth(net->id, net->password, iks_find_attrib(pak->x,"id"));
			iks_insert_attrib(x,"id","auth");
			iks_send(net->parser, x);
			iks_delete(x);
			break;
		case IKS_PAK_MESSAGE:
			id = iks_find_attrib(pak->x,"from");
			MsgFrom=id;
            MsgBody=iks_find_cdata(pak->x,"body");
			fprintf(log,"Msg from: '%s' \n",id);
			fprintf(log,"Body: '%s'\n",iks_find_cdata(pak->x,"body"));
			if((x = iks_find(pak->x,"error"))) {
				fprintf(log,"Error %s:'%s'\n",iks_find_attrib(x,"code"),iks_find_cdata(pak->x,"error"));
			}
			finished=1;
			break;
		case IKS_PAK_UNKNOWN:
		case IKS_PAK_PRESENCE:
		case IKS_PAK_S10N:
			break;
		case IKS_PAK_IQ:
			id = iks_find_attrib(pak->x, "id");
			if(iks_strcmp(id, "auth") == 0) {
				if(pak->subtype == IKS_TYPE_RESULT) {
					x = iks_make_iq(IKS_TYPE_GET, IKS_NS_ROSTER);
					iks_send(net->parser, x);
					iks_delete(x);

				}
			}
			else if(iks_strcmp(pak->ns, IKS_NS_ROSTER) == 0) {
				switch(pak->subtype)
				{
					case IKS_TYPE_RESULT:
						x = iks_make_pres(0, 0, NULL, NULL);
						iks_send(net->parser, x);
						iks_delete(x);
						finished=1;


					case IKS_TYPE_SET:
						x = iks_child(pak->query);
						iks_delete(pak->x);
						break;

					default:
						printf("parse roster failed\n");
						iks_delete(pak->x);
				}
			}

			break;
	}
}


// ----------------------------- EOF -----------------------------

