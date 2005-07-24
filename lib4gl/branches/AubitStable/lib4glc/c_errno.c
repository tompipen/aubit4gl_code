
# include	"cfun4gl.h"
# include	<errno.h>


int cfgl_errno;


/* WARNING: You MUST keep this table sorted alphabetically */
static cfgl_Assoc errno_const[] =
{
#include "c_errno.h"
};


function(c_errno,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_errno() returning integer\n");

    retint(cfgl_errno);
    return 1;
}   /* c_errno */
/*JFACE*/ int c_errno_0(int nargs) { return c_errno(nargs); }


function(c_strerror,1,1,1,1)
{
    int err;

    if(nargs != 1)
	cfgl_fatal("usage: c_strerror(errno integer) returning char(*)\n");

    popint(&err);
    retquote(strerror(err));
    return 1;

}   /* c_strerror */
/*JFACE*/ int c_strerror_1(int nargs) { return c_strerror(nargs); }


function(c__errno,1,1,1,1)
{
    char buf[51];

    if(nargs != 1)
	fgl_fatal("usage: c__errno(name char(*)) returning integer\n");

    popquote(buf, sizeof(buf));
    retint(cfgl_const(errno_const,
		     (size_t) (sizeof(errno_const) / sizeof(cfgl_Assoc)),
		     "errno", buf));
    return 1;

}   /* c__errno */
/*JFACE*/ int c__errno_1(int nargs) { return c__errno(nargs); }
