/*
	ISOKC.c  -  4gwmail socket io routines

	4gwMail, a news and mail client 4glWorks module
	Copyright (C) 1997-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 97
	Current release: Jan 02

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef popquote
#define popquote popvchar	/* since this is what we actually need */
#endif

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>

#include "is-osdep.h"
#ifdef HAVE_SYS_IN_H
#include <sys/in.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#ifdef HAVE_SOCKETVAR_H
#include <socketvar.h>
#endif

extern int status;
extern int errno;

/*
**  read routine passed to fd_read
*/
fgw_sokread(s, b, l)
int s;
void *b;
int l;
{
    return recv(s, b, l, 0);
}
/*
**  write routine passed to fd_write
*/
fgw_sokwrite(s, b, l)
int s;
void *b;
int l;
{
    return send(s, b, l, 0);
}
/*
**  open socket
*/
socket_open(nargs)
int nargs;
{
    struct sockaddr_in name;
    struct servent *servrec;
    struct hostent *hostrec;
    char host[120];
    char serv[20];
    char proto[10];
    int sock;
    int fd_id;

    popquote(proto,10);
    popquote(serv,20);
    popquote(host,120);
    fgw_clip(host);
    fgw_clip(serv);
    fgw_clip(proto);
    if ((hostrec=gethostbyname(host))==NULL)
	hostrec=gethostbyaddr(host, strlen(host), AF_INET);
    if (hostrec!=NULL)
    {
	if ((servrec=getservbyname(serv, proto))==NULL)
	    servrec=getservbyport(atoi(serv), proto);
	if (servrec!=NULL)
	{
	    name.sin_port=servrec->s_port;
	    name.sin_family=hostrec->h_addrtype;
	    fgw_move((char *) &name.sin_addr, (char *) hostrec->h_addr,
		hostrec->h_length);
	    if ((sock=socket(AF_INET, SOCK_STREAM, 0))!=-1)
    		if (connect(sock, (struct sockaddr *) &name, sizeof(name))!=-1)
		    if ((fd_id=fgw_addfd(sock, fgw_sokread,
					 fgw_sokwrite, close))!=-1)
		    {
			retint(fd_id);
			return(1);
		    }
		    else
		    {
			close(sock);
			errno=-1;
		    }
	}
    }
    status=errno;
    retquote("");
    return(1);
}
