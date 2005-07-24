
/*
 * This file contians the C function c_time() which is designed
 * to be called from an Informix 4GL program. It returns the current
 * system time as an integer which can be used to compare with the
 * mod times on files returned by c_statfile().
 *
 * usage: call c_time() returning current_time
 */


# include	"cfun4gl.h"
# include	<sys/types.h>
# include	<time.h>


function(c_time,0,0,1,1)
{
    time_t t;

    t = time((time_t *) 0);	/* call time() to get current system time */
    retlong((long) t);		/* return time and mtime */
    return 1;			/* return the number of arguments */

}   /* c_time */
/*JFACE*/ int c_time_0(int nargs) { return c_time(nargs); }
