
# include	"cfun4gl.h"
# if defined(__linux)
#  include	<sys/types.h>
# endif
# include	<sys/wait.h>
# include	<signal.h>
# if defined(__linux)
#  include	<string.h>
# endif


# define	MAX_ARGV	1000
# define	MAX_ARGC	100

static char *argv[MAX_ARGC + 1];


static struct
{
    char *name;
    int value;
} signames[] =
{
    { "HUP",	SIGHUP	},
    { "INT",	SIGINT	},
    { "QUIT",	SIGQUIT	},
    { "ILL",	SIGILL	},
    { "TRAP",	SIGTRAP	},
    { "ABRT",	SIGABRT	},
    { "FPE",	SIGFPE	},
    { "KILL",	SIGKILL	},
    { "BUS",	SIGBUS	},
    { "SEGV",	SIGSEGV	},
    { "SYS",	SIGSYS	},
    { "PIPE",	SIGPIPE	},
    { "ALRM",	SIGALRM	},
    { "TERM",	SIGTERM	},
    { "USR1",	SIGUSR1	},
    { "USR2",	SIGUSR2	},
    { "CHLD",	SIGCHLD	},
    { "PWR",	SIGPWR	},
    { "WINCH",	SIGWINCH},
    { "URG",	SIGURG	},
    { "POLL",	SIGPOLL	},
    { "STOP",	SIGSTOP	},
    { "TSTP",	SIGTSTP	},
    { "CONT",	SIGCONT	},
    { "TTIN",	SIGTTIN	},
    { "TTOU",	SIGTTOU	},
    { "VTALRM",	SIGVTALRM},
    { "PROF",	SIGPROF	},
    { "XCPU",	SIGXCPU	},
    { "XFSZ",	SIGXFSZ	},
    {  0,       0 }
};


char *cfgl_sig_name(int n)
{
    int i;

    for(i = 0; signames[i].name; ++i)
	if(signames[i].value == n)
	    break;

    return signames[i].name;

}   /* cfgl_sig_name */


int cfgl_get_sig(void)
{
    int i, j;
    int sig = 0;
    char buf[21];

    popstring(buf, sizeof(buf));

    i = 0;
    while(isspace(buf[i]))
	++i;

    while(isdigit(buf[i]))
	sig = sig * 10 + buf[i++] - '0';

    if(buf[i])	/* must be a non-numeric argument */
    {
	/* if there is a leading "SIG" then skip it */
	j = strncmp(buf, "SIG", 3) ? 0 : 3;

	for(i = 0; signames[i].name; ++i)
	    if(!strcmp(buf + j, signames[i].name))
		return signames[i].value;

	sig = -1;
    }

    return sig;

}   /* cfgl_get_sig */


static void stuff_args(int nargs)
{
    char buf[MAX_ARGV + 1];

    if(--nargs <= MAX_ARGC)
	argv[nargs] = 0;
    else
	argv[MAX_ARGC] = 0;

    while(nargs > 0)
    {
	popstring(buf, sizeof(buf));
	if(--nargs <= MAX_ARGC)
	    argv[nargs] = strdup(buf);
    }
}   /* stuff_args */


static void free_args(void)
{
    char **cpp = argv;

    while(*cpp)
	free(*cpp++);
}   /* stuff_args */


function(c_fork,0,0,1,1)
{
    int pid;

    if(nargs != 0)
	cfgl_fatal("usage: c_fork() returning integer\n");

    fflush(NULL);	/* flush all buffered I/O */

    pid = fork();
    if(pid < 0)
	cfgl_errno = errno;

    if(pid == 0)
	sqldetach();

    retint(pid);
    return 1;

}   /* c_fork */
/*JFACE*/ int c_fork_0(int nargs) { return c_fork(nargs); }


function(c_wait,0,0,1,2)
{
    pid_t pid;
    int status = 0;

    if(nargs != 0)
	cfgl_fatal("usage: c_wait() returning (pid, status) integer\n");

    pid = wait(&status);
    if(pid < 0)
	cfgl_errno = errno;

    retint(pid);
    retint(status);

    return 2;

}   /* c_wait */
/*JFACE*/ int c_wait_0(int nargs) { return c_wait(nargs); }


function(c_waitpid,1,2,1,2)
{
    int pid;
    int options, status = 0;
    char *cp, buf[21];

    if(nargs != 1 && nargs != 2)
	cfgl_fatal("usage: c_waitpid(pid integer[, options char(*)])"
			 " returning (pid, status) integer\n");

    if(nargs != 2)
	options = 0;
    else
    {
	popstring(buf, sizeof(buf) - 1);
	for(options = 0, cp = buf; *cp; ++cp)
	    switch(*cp)
	    {
# if ! defined(__linux)
	    case 'C': options |= WCONTINUED; break;
	    case 'W': options |= WNOWAIT;    break;
# endif
	    case 'H': options |= WNOHANG;    break;
	    case 'U': options |= WUNTRACED;  break;
	    }
    }
    popint(&pid);

    pid = waitpid(pid, &status, options);
    if(pid < 0)
	cfgl_errno = errno;

    retint(pid);
    retint(status);

    return 2;

}   /* c_waitpid */
/*JFACE*/ int c_waitpid_1(int nargs) { return c_waitpid(nargs); }
/*JFACE*/ int c_waitpid_2(int nargs) { return c_waitpid(nargs); }


function(c_waitstat,2,2,1,1)
{
    int status;
    char funct[21];

    if(nargs != 2)
        cfgl_fatal("usage: c_waitstat(funct char(*), status integer)"
			 " returning integer\n");

    popint(&status);
    popstring(funct, sizeof(funct));

         if(!strcmp(funct, "W" "IFEXITED"))   retint(WIFEXITED(status));
    else if(!strcmp(funct, "W" "EXITSTATUS")) retint(WEXITSTATUS(status));
    else if(!strcmp(funct, "W" "IFSIGNALED")) retint(WIFSIGNALED(status));
    else if(!strcmp(funct, "W" "TERMSIG"))    retint(WTERMSIG(status));
    else if(!strcmp(funct, "W" "COREDUMP"))   retint(WCOREDUMP(status));
    else cfgl_fatal("c_waitstat(%s): unknown func" "tion");

    return 1;

}   /* c_waitstat */
/*JFACE*/ int c_waitstat_2(int nargs) { return c_waitstat(nargs); }


function(c_sqldetach,0,0,1,0)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_sqldetach()\n");

    sqldetach();
    return 0;

}   /* c_sqldetach */
/*JFACE*/ int c_sqldetach_0(int nargs) { return c_sqldetach(nargs); }


function(c_execv,1,20,1,1)
{
    cfgl_Path buf;

    if(nargs < 1)
	cfgl_fatal("usage: c_execv(path, [arg ...] char(*))"
			 " returning integer\n");

    argv[nargs - 1] = 0;
    while(nargs > 1)
    {
	--nargs;
	popstring(buf, sizeof(buf));
    }

    stuff_args(nargs);
    popstring(buf, sizeof(buf));

    fflush(NULL);	/* flush all buffered I/O */

    retint(execv(buf, argv));
    cfgl_errno = errno;
    free_args();

    return 1;

}   /* c_execv */
/*JFACE*/ int c_execv_1(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_2(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_3(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_4(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_5(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_6(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_7(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_8(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_9(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_10(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_11(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_12(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_13(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_14(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_15(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_16(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_17(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_18(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_19(int nargs) { return c_execv(nargs); }
/*JFACE*/ int c_execv_20(int nargs) { return c_execv(nargs); }


function(c_execvp,1,20,1,1)
{
    cfgl_Path buf;

    if(nargs < 1)
	cfgl_fatal("usage: c_execvp(file [arg ...] char(*))"
			 " returning integer\n");

    stuff_args(nargs);
    popstring(buf, sizeof(buf));

    fflush(NULL);	/* flush all buffered I/O */

    retint(execvp(buf, argv));
    cfgl_errno = errno;
    free_args();

    return 1;

}   /* c_execvp */
/*JFACE*/ int c_execvp_1(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_2(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_3(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_4(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_5(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_6(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_7(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_8(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_9(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_10(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_11(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_12(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_13(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_14(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_15(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_16(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_17(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_18(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_19(int nargs) { return c_execvp(nargs); }
/*JFACE*/ int c_execvp_20(int nargs) { return c_execvp(nargs); }


function(c_kill,2,21,1,1)
{
    int i, sig, status = 0;
    int pids[20];
    int npids = 0;
    int err = 0;

    if(nargs < 2 || nargs > 21)
	cfgl_fatal("usage: c_kill(sig, pid [, pid...] integer)"
			 " returning integer\n");

    while(nargs-- > 1)
	popint(&pids[npids++]);
    sig = cfgl_get_sig();

    if(sig == -1)
	cfgl_errno = EINVAL;
    else
    {
	for(i = 0; i < npids; ++i)
	    if(kill(pids[i], sig) == -1)
	    {
		status = -1;
		if(err == 0 || errno != ESRCH)
		    err = errno;
	    }

	if(err)
	    cfgl_errno = err;
    }

    retint(status);
    return 1;

}   /* c_kill */
/*JFACE*/ int c_kill_2(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_3(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_4(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_5(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_6(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_7(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_8(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_9(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_10(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_11(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_12(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_13(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_14(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_15(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_16(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_17(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_18(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_19(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_20(int nargs) { return c_kill(nargs); }
/*JFACE*/ int c_kill_21(int nargs) { return c_kill(nargs); }
