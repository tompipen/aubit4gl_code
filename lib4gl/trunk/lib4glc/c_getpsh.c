
# define	MAXHOSTNAMELEN		256

# include	"cfun4gl.h"
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<netdb.h>

# define	MAX_PROTO	32
# define	MAX_SERV	32


static struct protoent *pp;
static int n_pAlias;

static struct servent *sp;
static int n_sAlias;

static struct hostent *hp;
static int n_hAlias;
static int n_hAddrs;


static int returnProtocol(void)
{
    n_pAlias = 0;

    if(! pp)
    {
	retquote("");
	retquote("");
	retquote("");
    }
    else
    {
	while(pp->p_aliases[n_pAlias])
	    ++n_pAlias;

	retquote(pp->p_name);
	retlong(n_pAlias);
	retlong(pp->p_proto);
    }

    return 3;

}   /* returnProtocol */


function(c_getprotobyname,1,1,1,3)
{
    char name[MAX_PROTO + 1];

    if(nargs != 1)
	fgl_fatal("usage: c_getprotobyname(name char(*))"
		 " returning (name) char(*), (nalias, proto) integer\n");

    popstring(name, sizeof(name));		/* get name argument */

    pp = getprotobyname(name);
    return returnProtocol();

}   /* c_getprotobyname */
/*JFACE*/ int c_getprotobyname_1(int nargs) { return c_getprotobyname(nargs); }


function(c_getprotobynumber,1,1,1,3)
{
    int proto;

    if(nargs != 1)
	fgl_fatal("usage: c_getprotobynumber(proto integer)"
		 " returning (name) char(*), (nalias, proto) integer\n");

    popint(&proto);		/* get number argument */

    pp = getprotobynumber(proto);
    return returnProtocol();

}   /* c_getprotobynumber */
/*JFACE*/ int c_getprotobynumber_1(int nargs) { return c_getprotobynumber(nargs); }


function(c_proto_alias,1,1,1,1)
{
    int nalias;

    if(nargs != 1)
	fgl_fatal("usage: c_proto_alias(nalias integer)"
		 " returning (alias) char(*)\n");

    popint(&nalias);	/* get number argument */

    if(!pp || nalias < 1 || nalias > n_pAlias)
	retquote("");
    else
	retquote(pp->p_aliases[nalias - 1]);
    return 1;

}   /* c_proto_alias */
/*JFACE*/ int c_proto_alias_1(int nargs) { return c_proto_alias(nargs); }


static int returnService(void)
{
    n_sAlias = 0;

    if(! sp)
    {
	retquote("");
	retquote("");
	retquote("");
	retquote("");
    }
    else
    {
	while(sp->s_aliases[n_sAlias])
	    ++n_sAlias;

	retquote(sp->s_name);
	retint(n_sAlias);
	retint(ntohs(sp->s_port));
	retquote(sp->s_proto);
    }

    return 4;

}   /* returnService */


function(c_getservbyname,2,2,1,4)
{
    char name[MAX_SERV + 1];
    char proto[MAX_PROTO + 1];
    char *p = NULL;

    if(nargs != 2)
	fgl_fatal("usage: c_getservbyname(name, proto char(*))"
		 " returning (name) char(*),"
		 " (nalias, port) integer, (proto) char(*)\n");

    popstring(proto, sizeof(proto));	/* get proto argument */
    popstring(name, sizeof(name));	/* get name argument */
    if(*proto) p = proto;

    sp = getservbyname(name, p);
    return returnService();

}   /* c_getservbyname */
/*JFACE*/ int c_getservbyname_2(int nargs) { return c_getservbyname(nargs); }


function(c_getservbyport,2,2,1,4)
{
    int port;
    char proto[MAX_PROTO + 1];
    char *p = NULL;

    if(nargs != 2)
	fgl_fatal("usage: c_getservbyport(port integer, proto char(*))"
		 " returning (name) char(*), "
		 " (nalias, port) integer, (proto) char(*)\n");

    popstring(proto, sizeof(proto));		/* get proto argument */
    popint(&port);			/* get number argument */
    if(*proto) p = proto;

    sp = getservbyport(htons(port), p);
    return returnService();

}   /* c_getservbyport */
/*JFACE*/ int c_getservbyport_2(int nargs) { return c_getservbyport(nargs); }


function(c_serv_alias,1,1,1,1)
{
    int nalias;

    if(nargs != 1)
	fgl_fatal("usage: c_serv_alias(nalias integer)"
		 " returning (alias) char(*)\n");

    popint(&nalias);			/* get number argument */

    if(!sp || nalias < 1 || nalias > n_sAlias)
	retquote("");
    else
	retquote(sp->s_aliases[nalias - 1]);
    return 1;

}   /* c_serv_alias */
/*JFACE*/ int c_serv_alias_1(int nargs) { return c_serv_alias(nargs); }


function(c_gethostname,0,0,1,1)
{
    char c_hostname[MAXHOSTNAMELEN + 1];
    int status;

    if(nargs != 0)
	fgl_fatal("usage: c_gethostname()"
		 " returning (hostname) char(*)\n");

    status = gethostname(c_hostname, MAXHOSTNAMELEN);
    if(status == 0)
	retquote(c_hostname);
    else
    {
	cfgl_errno = errno;
	retquote("");
    }

    return 1;

}   /* c_gethostname */
/*JFACE*/ int c_gethostname_0(int nargs) { return c_gethostname(nargs); }


static int returnHost(void)
{
    n_hAlias = 0;
    n_hAddrs = 0;

    if(! hp)
    {
	retquote("");
	retquote("");
	retquote("");
    }
    else
    {
	while(hp->h_aliases[n_hAlias])
	    ++n_hAlias;
	    ;

	while(hp->h_addr_list[n_hAddrs])
	    ++n_hAddrs;

	retquote(hp->h_name);
	retint(n_hAlias);
	retint(n_hAddrs);
    }

    return 3;

}   /* returnHost */


function(c_gethostbyname,1,1,1,3)
{
    char name[MAXHOSTNAMELEN + 1];

    if(nargs != 1)
	fgl_fatal("usage: c_gethostbyname(name char(*))"
		 " returning (name) char(*), (nalias, naddr) integer\n");

    popstring(name, sizeof(name));	/* get name argument */

    hp = gethostbyname(name);
    return returnHost();

}   /* c_gethostbyname */
/*JFACE*/ int c_gethostbyname_1(int nargs) { return c_gethostbyname(nargs); }


function(c_gethostbyaddr,1,1,1,3)
{
    char buf[21];
    unsigned long addr;

    if(nargs != 1)
	fgl_fatal("usage: c_gethostbyaddr(ipaddr char(*))"
		 " returning (name) char(*), (nalias, naddr) integer\n");

    /* get addr argument */
    popstring(buf, sizeof(buf));
    addr = inet_addr(buf);

    hp = gethostbyaddr((const char *) &addr, sizeof(addr), AF_INET);
    return returnHost();

}   /* c_gethostbyaddr */
/*JFACE*/ int c_gethostbyaddr_1(int nargs) { return c_gethostbyaddr(nargs); }


function(c_host_alias,1,1,1,1)
{
    int nalias;

    if(nargs != 1)
	fgl_fatal("usage: c_host_alias(nalias integer)"
		 " returning (alias) char(*)\n");

    popint(&nalias);		/* get number argument */

    if(!hp || nalias < 1 || nalias > n_hAlias)
	retquote("");
    else
	retquote(hp->h_aliases[nalias - 1]);
    return 1;

}   /* c_host_alias */
/*JFACE*/ int c_host_alias_1(int nargs) { return c_host_alias(nargs); }


function(c_host_addr,1,1,1,1)
{
    int addr;

    if(nargs != 1)
	fgl_fatal("usage: c_host_addr(naddr integer)"
		 " returning (addr) char(*)\n");

    popint(&addr);		/* get number argument */

    if(!hp || addr < 1 || addr > n_hAddrs)
	retquote("");
    else
	retquote(inet_ntoa(* (struct in_addr *) hp->h_addr_list[addr - 1]));

    return 1;

}   /* c_host_addr */
/*JFACE*/ int c_host_addr_1(int nargs) { return c_host_addr(nargs); }
