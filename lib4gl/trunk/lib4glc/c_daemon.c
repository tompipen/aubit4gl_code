
# include	"cfun4gl.h"
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<sys/un.h>


function(c_daemon,0,0,1,1)
{
    int result;

    result = setsid();
    if(result == -1)
	cfgl_errno = errno;
    else
    {
	/* close low-level streams */
	close(0);
	close(1);
	close(2);

#ifdef SUN_SYSTEM
	int tty = open("/dev/tty", O_RDONLY);
	if(tty != -1)
	{
	    ioctl(tty, TIOCNOTTY);
	    close(tty);
	}
#endif

	fdopen(open("/dev/null", O_RDONLY), "r");
	fdopen(open("/dev/null", O_WRONLY), "w");
	fdopen(open("/dev/null", O_WRONLY), "w");
    }

    retint(result);
    return 1;

}   /* c_daemon */
/*JFACE*/ int c_daemon_0(int nargs) { return c_daemon(nargs); }
