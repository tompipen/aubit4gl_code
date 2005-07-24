
# include	"cfun4gl.h"

# include	<sys/types.h>
# include	<sys/socket.h>
# include	<sys/un.h>
# include	<netinet/in.h>
# if defined(__alpha) || defined(__linux)
#  include	<sys/time.h>
# else
#  include	<sys/times.h>
# endif
# ifndef _HPUX_SOURCE
#  include	<sys/select.h>
# endif




/* TODO: if we are going to have true 4GL portability, */
/* we need to discover the worlds largest FD_SETSIZE   */
/* and post a constant for that ourselves              */
typedef char cfgl_fd_set[FD_SETSIZE + 1];

int inet_aton(char *buf, u_long *);
char *inet_ntoa(u_long addr);

static union
{
    struct sockaddr_in s_in;
    struct sockaddr_un s_un;
} sockaddr;

/* see comments in <sys/un.h> */
# define	MAX_GAG		sizeof(sockaddr.s_un.sun_path)


/* WARNING: You MUST keep this table sorted alphabetically */
static cfgl_Assoc socket_const[] =
{
#include "c_socket.h"
};


static long cfgl_socket_const(char *buf)
{
    return cfgl_const(socket_const,
		     (size_t) (sizeof(socket_const) / sizeof(cfgl_Assoc)),
                     "socket", buf);
}   /* cfgl_socket_const */


static void setsockaddr(int nargs)
{
    char c_path[MAX_GAG + 1];
    u_short port;
    u_long addr;

    switch(nargs)
    {
    case 1:
	popstring(c_path, sizeof(c_path));
	if(strlen(c_path) > MAX_GAG)
	    cfgl_fatal("AF_UNIX domain path %s exceeds maximum (%d)\n",
		       c_path, MAX_GAG);

	sockaddr.s_un.sun_family = AF_UNIX;
	strcpy(sockaddr.s_un.sun_path, c_path);
	break;

    case 2:
	poplong((long *) &addr);
	popshort((short *) &port);

	sockaddr.s_in.sin_family = AF_INET;
	sockaddr.s_in.sin_port = htons(port);
	sockaddr.s_in.sin_addr.s_addr = htonl(addr);
	sockaddr.s_in.sin_zero[0] = 0;
	sockaddr.s_in.sin_zero[1] = 0;
	sockaddr.s_in.sin_zero[2] = 0;
	sockaddr.s_in.sin_zero[3] = 0;
	sockaddr.s_in.sin_zero[4] = 0;
	sockaddr.s_in.sin_zero[5] = 0;
	sockaddr.s_in.sin_zero[6] = 0;
	sockaddr.s_in.sin_zero[7] = 0;
	break;

    default:
	cfgl_fatal("invalid internal use of setsockaddr\n");
        return;
    }

}   /* setsockaddr */


static int retsockaddr(int status, int n)
{
    retint(status);

    if(status < 0)
	cfgl_errno = errno;

    switch(n)
    {
    case 1:
	if(status < 0)
	    retquote("");
	else
	    retquote(sockaddr.s_un.sun_path);
	return 2;

    case 2:
	if(status < 0)
	{
	    retquote("");
	    retquote("");
	}
	else
	{
	    retshort(ntohs(sockaddr.s_in.sin_port));
	    retlong(ntohl(sockaddr.s_in.sin_addr.s_addr));
	}
	return 3;

    default:
	cfgl_fatal("invalid internal use of retsockaddr\n");
        return 0;
    }

}   /* retsockaddr */


function(c_inet_aton,1,1,1,1)
{
    char buf[21];
    u_long addr;

    if(nargs != 1)
	cfgl_fatal("usage: c_inet_aton(addr char(*))"
			 " returning (addr) integer\n");

    popstring(buf, sizeof(buf));

    if(inet_aton(buf, &addr))
	retint(ntohl(addr));
    else
	retquote("");
    return 1;

}   /* c_inet_aton */
/*JFACE*/ int c_inet_aton_1(int nargs) { return c_inet_aton(nargs); }


function(c_inet_ntoa,1,1,1,1)
{
    u_long addr;
    char *cp;

    if(nargs != 1)
	cfgl_fatal("usage: c_inet_ntoa(addr integer)"
			 " returning (addr) char(*)\n");

    poplong((long *) &addr);
    addr = htonl(addr);

    cp = inet_ntoa(addr);
    if(cp)
	retquote(cp);
    else
	retquote("");
    return 1;

}   /* c_inet_ntoa */
/*JFACE*/ int c_inet_ntoa_1(int nargs) { return c_inet_ntoa(nargs); }


function(c_socket,3,3,1,1)
{
    char buf[21];
    int domain, type, proto;
    int fd;

    if(nargs != 3)
	cfgl_fatal("usage: c_socket(domain, type char(*), proto smallint)"
			 " returning (socket) smallint\n");

    popint(&proto);
    popstring(buf, sizeof(buf)); type   = (int) cfgl_socket_const(buf);
    popstring(buf, sizeof(buf)); domain = (int) cfgl_socket_const(buf);

    fd = socket(domain, type, proto);
    if(fd < 0)
	cfgl_errno = errno;

    retshort(fd);
    return 1;

}   /* c_socket */
/*JFACE*/ int c_socket_3(int nargs) { return c_socket(nargs); }


function(c_socketpair,3,3,1,2)
{
    char buf1[21], buf2[21];
    int domain, type, proto;
    int fd[2], status;

    if(nargs != 3)
	cfgl_fatal("usage: c_socketpair(domain, type char(*), proto smallint)"
			 " returning (socket1, socket2) smallint\n");

    popint(&proto);
    popstring(buf2, sizeof(buf2)); type   = (int) cfgl_socket_const(buf2);
    popstring(buf1, sizeof(buf1)); domain = (int) cfgl_socket_const(buf1);

    status = socketpair(domain, type, proto, fd);
    if(status < 0)
    {
	cfgl_errno = errno;
	retquote("");
	retquote("");
    }
    else
    {
	retshort(fd[0]);
	retshort(fd[1]);
    }

    return 2;

}   /* c_socketpair */
/*JFACE*/ int c_socketpair_3(int nargs) { return c_socketpair(nargs); }


function(c_bind,2,3,1,1)
{
    int socket, status;

    if(nargs != 2 && nargs != 3)
	cfgl_fatal("usage: c_bind(socket smallint, pathname char(*))"
			 " returning (status) integer\n"
	           "       c_bind(socket smallint, port, addr integer)"
			 " returning (status) integer\n");

    setsockaddr(nargs - 1);
    popint(&socket);

    switch(nargs)
    {
    case 2:
	status = bind(socket, (void *) &sockaddr.s_un, sizeof(sockaddr.s_un));
	break;

    case 3:
	status = bind(socket, (void *) &sockaddr.s_in, sizeof(sockaddr.s_in));
	break;
    }

    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_bind */
/*JFACE*/ int c_bind_2(int nargs) { return c_bind(nargs); }
/*JFACE*/ int c_bind_3(int nargs) { return c_bind(nargs); }


function(c_listen,2,2,1,1)
{
    int socket, backlog;
    int status;

    if(nargs != 2)
	cfgl_fatal("usage: c_listen(socket, backlog smallint)"
			 " returning (status) integer\n");

    popint(&backlog);
    popint(&socket);

    status = listen(socket, backlog);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_listen */
/*JFACE*/ int c_listen_2(int nargs) { return c_listen(nargs); }


function(c_accept,2,2,1,-3)
{
    int socket, n, ns;
    int addrlen;

    if(nargs != 2)
	cfgl_fatal("usage: c_accept(n, socket smallint)"
			 " returning (ns) smallint, ADDR\n");

    popint(&socket);
    popint(&n);

    switch(n)
    {
    case 1:
	sockaddr.s_un.sun_family = AF_UNIX;
	addrlen = sizeof(sockaddr.s_un);
	ns = accept(socket, (void *) &sockaddr.s_un, &addrlen);
	break;

    case 2:
	sockaddr.s_in.sin_family = AF_INET;
	addrlen = sizeof(sockaddr.s_in);
	ns = accept(socket, (void *) &sockaddr.s_in, &addrlen);
	break;

    default:
	cfgl_fatal("c_accept(): invalid n %d\n", n);
    }

    return retsockaddr(ns, n);

}   /* c_accept */
/*JFACE*/ int c_accept_2(int nargs) { return c_accept(nargs); }


function(c_connect,2,3,1,1)
{
    int socket, status;

    if(nargs != 2 && nargs != 3)
	cfgl_fatal("usage: c_accept(socket smallint, pathname char(*))"
			 " returning (status) integer\n"
	           "       c_accept(socket smallint, port, addr integer)"
			 " returning (status) integer\n");

    setsockaddr(nargs - 1);
    popint(&socket);

    switch(nargs)
    {
    case 2:
	status = connect(socket, (void *) &sockaddr.s_un, sizeof(sockaddr.s_un));
	break;

    case 3:
	status = connect(socket, (void *) &sockaddr.s_in, sizeof(sockaddr.s_in));
	break;
    }

    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_connect */
/*JFACE*/ int c_connect_2(int nargs) { return c_connect(nargs); }
/*JFACE*/ int c_connect_3(int nargs) { return c_connect(nargs); }


function(c_getpeername,2,2,1,-3)
{
    int socket, n, status;
    int addrlen;

    if(nargs != 2)
	cfgl_fatal("usage: c_getpeername(n, socket smallint)"
			 " returning (status) integer, ADDR\n");

    popint(&socket);
    popint(&n);

    switch(n)
    {
    case 1:
	sockaddr.s_un.sun_family = AF_UNIX;
	addrlen = sizeof(sockaddr.s_un);
	status = getpeername(socket, (void *) &sockaddr.s_un, &addrlen);
	break;

    case 2:
	sockaddr.s_in.sin_family = AF_INET;
	addrlen = sizeof(sockaddr.s_in);
	status = getpeername(socket, (void *) &sockaddr.s_in, &addrlen);
	break;

    default:
	cfgl_fatal("c_getpeername(): invalid n %d\n", n);
    }

    return retsockaddr(status, n);

}   /* c_getpeername */
/*JFACE*/ int c_getpeername_2(int nargs) { return c_getpeername(nargs); }


function(c_getsockname,2,2,1,-3)
{
    int socket, n, status;
    int addrlen;

    if(nargs != 2)
	cfgl_fatal("usage: c_getsockname(n, socket smallint)"
			 " returning (status) integer, ADDR\n");

    popint(&socket);
    popint(&n);

    switch(n)
    {
    case 1:
	sockaddr.s_un.sun_family = AF_UNIX;
	addrlen = sizeof(sockaddr.s_un);
	status = getsockname(socket, (void *) &sockaddr.s_un, &addrlen);
	break;

    case 2:
	sockaddr.s_in.sin_family = AF_INET;
	addrlen = sizeof(sockaddr.s_in);
	status = getsockname(socket, (void *) &sockaddr.s_in, &addrlen);
	break;

    default:
	cfgl_fatal("c_getsockname(): invalid n %d\n", n);
    }

    return retsockaddr(status, n);

}   /* c_getsockname */
/*JFACE*/ int c_getsockname_2(int nargs) { return c_getsockname(nargs); }


function(c_recv,4,5,1,1)
{
    cfgl_MemPtr mp;
    char *cp, buf[10];
    int status, socket, ofs, n, flags;

    if(nargs != 4 && nargs != 5)
	cfgl_fatal("usage: c_recv(socket, bufptr, ofs,"
	                 " n integer[, flags char(*)])"
		         " returning (nbytes) integer\n");

    flags = 0;
    if(nargs == 5)
    {
	popstring(buf, sizeof(buf));
	for(cp = buf; *cp; ++cp)
	    switch(*cp)
	    {
	    case 'O': flags |= MSG_OOB;  break;
	    case 'P': flags |= MSG_PEEK; break;
	    }
    }

    popint(&n);
    popint(&ofs);
    mp = cfgl_getptr();
    popint(&socket);

    cfgl_checkmem("c_recv", mp, ofs, n);

    status = recv(socket, mp->m + ofs, n, flags);
    if(status < 0)
	cfgl_errno = errno;
   
    retint(status);
    return 1;

}   /* c_recv */
/*JFACE*/ int c_recv_4(int nargs) { return c_recv(nargs); }
/*JFACE*/ int c_recv_5(int nargs) { return c_recv(nargs); }


/* TODO: FIX to pass address variants */
function(c_recvfrom,3,4,1,2)
{
    cfgl_String str;
    int status, socket, n, flags;
    char *cp, buf[21];
    int domain;
    int addrlen;

    if(nargs != 3 && nargs != 4)
	cfgl_fatal("usage: c_recvfrom('AF_UNIX', socket,"
	                 " n integer[, flags char(*)])"
		         " returning (nbytes) integer, (str) char(*)\n");

    flags = 0;
    if(nargs == 4)
    {
	popstring(str, sizeof(str));
	for(cp = str; *cp; ++cp)
	    switch(*cp)
	    {
	    case 'O': flags |= MSG_OOB;  break;
	    case 'P': flags |= MSG_PEEK; break;
	    }
    }

    popint(&n);
    popint(&socket);
    popstring(buf, sizeof(buf));
    domain = cfgl_socket_const(buf);
 
    /* make sure count is sensible */
    if(n > CFGL_IOBUF) n = CFGL_IOBUF;
    if(n < 1)          n = 1;

    switch(domain)
    {
    case AF_UNIX:
	addrlen = sizeof(sockaddr.s_un);
	status = recvfrom(socket, str, n, flags,
		        (struct sockaddr *) &sockaddr.s_un, &addrlen);
	break;

    case AF_INET:
	addrlen = sizeof(sockaddr.s_in);
	status = recvfrom(socket, str, n, flags,
		        (struct sockaddr *) &sockaddr.s_in, &addrlen);
	break;

    default:
	cfgl_fatal("c_recvfrom(): invalid domain %s\n", buf);
    }

    if(status < 0)
    {
	cfgl_errno = errno;
	str[0] = 0;
    }
    else
	str[status] = 0;
   
    retint(status);
    retquote(str);
    return 2;

}   /* c_recvfrom */
/*JFACE*/ int c_recvfrom_3(int nargs) { return c_recvfrom(nargs); }
/*JFACE*/ int c_recvfrom_4(int nargs) { return c_recvfrom(nargs); }


function(c_send,4,5,1,1)
{
    int status, socket, ofs, n, flags;
    char *cp, buf[10];
    cfgl_MemPtr mp;

    if(nargs != 4 && nargs != 5)
	cfgl_fatal(
	    "usage: c_send(socket, bufptr, ofs, n integer[, flags char(*)])"
		  " returning (nbytes) integer\n");

    flags = 0;
    if(nargs == 5)
    {
	popstring(buf, sizeof(buf));
	for(cp = buf; *cp; ++cp)
	    switch(*cp)
	    {
	    case 'O': flags |= MSG_OOB; break;
	    case 'R': flags |= MSG_DONTROUTE; break;
	    }
    }

    popint(&n);
    popint(&ofs);
    mp = cfgl_getptr();
    popint(&socket);

    cfgl_checkmem("c_send", mp, ofs, n);

    status = send(socket, mp->m + ofs, n, flags);
    if(status < 0)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_send */
/*JFACE*/ int c_send_4(int nargs) { return c_send(nargs); }
/*JFACE*/ int c_send_5(int nargs) { return c_send(nargs); }


/* TODO: FIX HIM to pass address variants */
function(c_sendto,4,5,1,1)
{
    int status, socket, n, flags;
    char *cp;
    cfgl_String str;
    char buf[21];
    int domain;

    if(nargs != 4 && nargs != 5)
	cfgl_fatal(
	    "usage: c_sendto('AF_UNIX', socket smallint,"
	          " str char(*), len integer[, flags char(*)])"
	          " returning (nbytes) integer\n"
	    "       c_sendto('AF_INET', socket smallint,"
	          " str char(*), len integer[, flags char(*)])"
	          " returning (nbytes) integer\n");

    flags = 0;
    if(nargs == 5)
    {
	popstring(str, sizeof(str));
	for(cp = str; *cp; ++cp)
	    switch(*cp)
	    {
	    case 'O': flags |= MSG_OOB; break;
	    case 'R': flags |= MSG_DONTROUTE; break;
	    }
    }

    popint(&n);
    popquote(str, sizeof(str));
    popint(&socket);
    popstring(buf, sizeof(buf));
    domain = cfgl_socket_const(buf);

    if(n > CFGL_IOBUF) n = CFGL_IOBUF;
    if(n < 0)          n = 0;
    if(n == 0)         n = cfgl_trim(str);

    switch(domain)
    {
    case AF_UNIX:
	status = sendto(socket, str, n, flags,
		      (struct sockaddr *) &sockaddr.s_un,
		      sizeof(sockaddr.s_un));
	break;

    case AF_INET:
	status = sendto(socket, str, n, flags,
		      (struct sockaddr *) &sockaddr.s_in,
		      sizeof(sockaddr.s_in));
	break;

    default:
	cfgl_fatal("c_sendto(): invalid domain %s\n", buf);
    }

    if(status < 0)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_sendto */
/*JFACE*/ int c_sendto_4(int nargs) { return c_sendto(nargs); }
/*JFACE*/ int c_sendto_5(int nargs) { return c_sendto(nargs); }


function(c_shutdown,1,2,1,1)
{
    int i, s, how;

    if(nargs != 1 && nargs != 2)
	cfgl_fatal("usage: c_shutdown(s[, how] smallint)"
			 " returning (status) integer\n");

    if(nargs == 2)
	popint(&how);
    else
	how = 2;
    popint(&s);

    if(how < 0 || how > 2)
    {
	i = -1;
	cfgl_errno = EINVAL;
    }
    else
    {
	i = shutdown(s, how);
	if(i < 0)
	    cfgl_errno = errno;
    }

    retint(i);
    return 1;

}   /* c_shutdown */
/*JFACE*/ int c_shutdown_1(int nargs) { return c_shutdown(nargs); }
/*JFACE*/ int c_shutdown_2(int nargs) { return c_shutdown(nargs); }


function(c_getsockopt,3,3,1,1)
{
    int status, socket, level, optname;
    union {
	int intval;
	struct linger lingval;
    } optval;
    int optlen;

    if(nargs != 3)
	cfgl_fatal("usage: c_getsockopt(socket, level, optname integer)"
			 " returning integer\n");

    popint(&optname);
    popint(&level);
    popint(&socket);

    if(optname != SO_LINGER)
	optlen = sizeof(optval.intval);
    else
	optlen = sizeof(optval.lingval);

    status = getsockopt(socket, level, optname, &optval, &optlen);
    if(status < 0)
    {
	cfgl_errno = errno;
	retquote("");	/* return null for bullshit */
    }
    else
    {
	if(optname != SO_LINGER)
	    retint(optval.intval);
	else if(optval.lingval.l_onoff)
	    retint(optval.lingval.l_linger);
	else
	    retint(-1);
    }

    return 1;

}   /* c_getsockopt */
/*JFACE*/ int c_getsockopt_3(int nargs) { return c_getsockopt(nargs); }


function(c_setsockopt,4,4,1,1)
{
    int status, socket, level, optname;
    union {
	int intval;
	struct linger lingval;
    } optval;
    int optlen;

    if(nargs != 4)
	cfgl_fatal("usage: c_setsockopt(socket, level,"
	                 " optname, optval integer)"
			 " returning (status) integer\n");

    popint(&optval.intval);
    popint(&optname);
    popint(&level);
    popint(&socket);

    if(optname != SO_LINGER)
	optlen = sizeof(optval.intval);
    else
    {
	optlen = sizeof(optval.lingval);

	if(optval.intval < 0)
	{
	    optval.lingval.l_linger = 0;
	    optval.lingval.l_onoff = 0;
	}
	else
	{
	    optval.lingval.l_linger = optval.intval;
	    optval.lingval.l_onoff = 1;
	}
    }

    status = setsockopt(socket, level, optname, &optval, optlen);

    if(status < 0)
	cfgl_errno = errno;
    retint(status);
    return 1;

}   /* c_setsockopt */
/*JFACE*/ int c_setsockopt_4(int nargs) { return c_setsockopt(nargs); }


function(c_select,4,4,1,5)
{
    cfgl_fd_set p_rfds, p_wfds, p_efds;
    double p_timeout;
    int i, nfds, status;
    fd_set rfds, wfds, efds;
    struct timeval timeout, *tp;

    if(nargs != 4)
	cfgl_fatal("usage: c_select(rfds, wfds, efds char(*), timeout float)"
		         " returning (nfds) smallint,"
		                   " (rfds, wfds, efds) char(*),"
			           " (timeout) float\n");

    popdub(&p_timeout);
    popstring(p_efds, sizeof(p_efds));
    popstring(p_wfds, sizeof(p_wfds));
    popstring(p_rfds, sizeof(p_rfds));

    nfds = 0;
    FD_ZERO(&rfds);
    FD_ZERO(&wfds);
    FD_ZERO(&efds);

    for(i = 0; p_rfds[i]; ++i)
        if(p_rfds[i] == '1')
	{
	    FD_SET(i, &rfds);
	    if(nfds < i) nfds = i;
	}

    for(i = 0; p_wfds[i]; ++i)
        if(p_wfds[i] == '1')
	{
	    FD_SET(i, &wfds);
	    if(nfds < i) nfds = i;
	}

    for(i = 0; p_efds[i]; ++i)
        if(p_efds[i] == '1')
	{
	    FD_SET(i, &efds);
	    if(nfds < i) nfds = i;
	}

    ++nfds;	/* increment because we want a count not an offset */
		/* does that make sense??? */

    if(risnull(CFLOATTYPE, (char *) &p_timeout))
	tp = 0;
    else
    {
	tp = &timeout;
	timeout.tv_sec = p_timeout;
	timeout.tv_usec = (p_timeout - timeout.tv_sec) * 1000000 + 0.5;
    }

    status = select(nfds, &rfds, &wfds, &efds, tp);


    if(status < 0)
    {
	cfgl_errno = errno;
	i = 0;
    }
    else
    {
	if(! risnull(CFLOATTYPE, (char *) &p_timeout))
	    p_timeout = timeout.tv_sec + timeout.tv_usec * 0.000001;

	for(i = 0; i < FD_SETSIZE; ++i)
	{
	    p_rfds[i] = i < nfds && FD_ISSET(i, &rfds) ? '1' : ' ';
	    p_wfds[i] = i < nfds && FD_ISSET(i, &wfds) ? '1' : ' ';
	    p_efds[i] = i < nfds && FD_ISSET(i, &efds) ? '1' : ' ';
	}
    }

    p_rfds[i] = 0;	cfgl_trim(p_rfds);
    p_wfds[i] = 0;	cfgl_trim(p_wfds);
    p_efds[i] = 0;	cfgl_trim(p_efds);

    retint(status);

    retquote(p_rfds);
    retquote(p_wfds);
    retquote(p_efds);
    retdub(&p_timeout);

    return 5;

}   /* c_select */
/*JFACE*/ int c_select_4(int nargs) { return c_select(nargs); }


function(c__socket,1,1,1,1)
{
    char buf[51];

    if(nargs != 1)
	cfgl_fatal("usage: c__socket(name char(*)) returning integer\n");

    popstring(buf, sizeof(buf));
    retint(cfgl_const(socket_const,
		     (size_t) (sizeof(socket_const) / sizeof(cfgl_Assoc)),
                     "socket", buf));
    return 1;

}   /* c__socket */
/*JFACE*/ int c__socket_1(int nargs) { return c__socket(nargs); }


function(c_htons,1,1,1,1)
{
    short s;
    popshort(&s);
    retshort(htons(s));
    return 1;
}   /* c_htons */
/*JFACE*/ int c_htons_1(int nargs) { return c_htons(nargs); }

function(c_htonl,1,1,1,1)
{
    long l;
    poplong(&l);
    retlong(htonl(l));
    return 1;
}   /* c_htonl */
/*JFACE*/ int c_htonl_1(int nargs) { return c_htonl(nargs); }

function(c_ntohs,1,1,1,1)
{
    short s;
    popshort(&s);
    retshort(ntohs(s));
    return 1;
}   /* c_ntohs */
/*JFACE*/ int c_ntohs_1(int nargs) { return c_ntohs(nargs); }

function(c_ntohl,1,1,1,1)
{
    long l;
    poplong(&l);
    retlong(ntohl(l));
    return 1;
}   /* c_ntohl */
/*JFACE*/ int c_ntohl_1(int nargs) { return c_ntohl(nargs); }
