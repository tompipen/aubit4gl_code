
# include	"cfun4gl.h"

function(c_getuid,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_getuid() returning integer\n");

    retint(getuid());
    return 1;
}   /* c_getuid */
/*JFACE*/ int c_getuid_0(int nargs) { return c_getuid(nargs); }


function(c_setuid,1,1,1,1)
{
    int status, uid;

    if(nargs != 1)
	cfgl_fatal("usage: c_setuid(uid integer) returning integer\n");

    popint(&uid);
    status = setuid(uid);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;
}   /* c_setuid */
/*JFACE*/ int c_setuid_1(int nargs) { return c_setuid(nargs); }


function(c_geteuid,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_geteuid() returning integer\n");

    retint(geteuid());
    return 1;
}   /* c_geteuid */
/*JFACE*/ int c_geteuid_0(int nargs) { return c_geteuid(nargs); }


function(c_getgid,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_getgid() returning integer\n");

    retint(getgid());
    return 1;
}   /* c_getgid */
/*JFACE*/ int c_getgid_0(int nargs) { return c_getgid(nargs); }


function(c_setgid,1,1,1,1)
{
    int status, gid;

    if(nargs != 1)
	cfgl_fatal("usage: c_setgid(gid) returning integer\n");

    popint(&gid);
    status = setgid(gid);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_setgid */
/*JFACE*/ int c_setgid_1(int nargs) { return c_setgid(nargs); }


function(c_getegid,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_getegid() returning integer\n");

    retint(getegid());
    return 1;
}   /* c_getegid */
/*JFACE*/ int c_getegid_0(int nargs) { return c_getegid(nargs); }


function(c_getpid,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_getpid() returning integer\n");

    retint(getpid());
    return 1;
}   /* c_getpid */
/*JFACE*/ int c_getpid_0(int nargs) { return c_getpid(nargs); }


function(c_getppid,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_getppid() returning integer\n");

    retint(getppid());
    return 1;
}   /* c_getppid */
/*JFACE*/ int c_getppid_0(int nargs) { return c_getppid(nargs); }


function(c_getpgrp,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_getpgrp() returning integer\n");

    retint(getpgrp());
    return 1;
}   /* c_getpgrp */
/*JFACE*/ int c_getpgrp_0(int nargs) { return c_getpgrp(nargs); }


function(c_ttyname,0,0,1,1)
{
    char *tp;
    int fd;

    if(nargs != 0)
	cfgl_fatal("usage: c_ttyname() returning char(*)\n");

    tp = 0;
    for(fd = 0; fd < 3; ++fd)
	if(isatty(fd))
	{
	    tp = ttyname(fd);
	    break;
	}

    if(!tp)
	tp = "";

    retquote(tp);
    return 1;

}   /* c_ttyname */
/*JFACE*/ int c_ttyname_0(int nargs) { return c_ttyname(nargs); }


function(c_setsid,0,0,1,1)
{
    int sid;

    if(nargs != 0)
	cfgl_fatal("usage: c_setsid() returning integer\n");

    sid = setsid();
    if(sid == -1)
	cfgl_errno = errno;
    
    retint(sid);
    return 1;

}   /* c_setsid */
/*JFACE*/ int c_setsid_0(int nargs) { return c_setsid(nargs); }
