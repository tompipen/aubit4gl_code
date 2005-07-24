
# include	"cfun4gl.h"
# include	<sys/types.h>
# include	<signal.h>


# define	MAX_KEYS	20
# define	KEY_LEN		10


static long hit;
struct KeyWord
{
    int value;
    char name[KEY_LEN + 1];
};


static struct KeyWord keywords[MAX_KEYS];

static int findKW(char *key)
{
    static char enver[] = "FGL_TO_1234567890";
    static int std_timing = -1;
    char *cp;
    int i, n;

    if(std_timing == -1)
    {
	cp = getenv("FGL_TO_TIMEOUT");
	if(!cp || sscanf(cp, "%d", &std_timing) != 1 || std_timing < 0)
	    std_timing = 15 * 60;	/* 15 minutes of grace */
    }

    /* attempt to detect a numeric timeout value */
    for(i = 0; isspace(key[i]); ++i)	/* skip spaces first */
    ;

    if(isdigit(key[i]))
    {
	for(n = 0; isdigit(key[i]); ++i)
	    n = n * 10 + key[i] - '0';
	while(isspace(key[i]))
	    ++i;
	if(!key[i])
	    return n;
	/* non-digital, so flop into string matching code */
    }

    for(i = 0; i < MAX_KEYS && *keywords[i].name; ++i)
	if(!strcmp(keywords[i].name, key))
	    return keywords[i].value;

    if(i == MAX_KEYS)
	return std_timing;	/* ran out of room in key array */

    strcpy(enver + 4, key);
    n = std_timing;
    if((cp = getenv(enver)))
	sscanf(cp, "%d", &n);
    if(n < 0) n = 0;

    strcpy(keywords[i].name, key);
    keywords[i].value = n;

    return keywords[i].value;

}   /* findKW */


static void catch_signal(int sig)
{
    hit |= 1 << sig;

    if(sig != SIGCLD)
	signal(sig, catch_signal);	/* keep signal alive */

    if(sig == SIGALRM)
	kill(getpid(), SIGINT);

}   /* catch_signal */


function(c_alarmed,0,0,1,1)
{
    int result = hit & (1 << SIGALRM);
    hit &= ~ result;

    retint(result);
    return 1;
}   /* c_alarmed */
/*JFACE*/ int c_alarmed_0(int nargs) { return c_alarmed(nargs); }


function(c_alarm,1,1,1,0)
{
    char key[KEY_LEN + 1];
    int sec, doit;
    void (*oaction)(int);

    /* collect and sanitise */
    popstring(key, sizeof(key));
    cfgl_lcase(key);

    sec = *key ? findKW(key) : 0;

    doit = 1;

    oaction = signal(SIGALRM, catch_signal);

#if defined(ALARM_PARANOID)
    if(oaction != SIG_DFL)
	if(oaction == SIG_IGN)
	{
	    signal(SIGALRM, SIG_IGN);	/* restore the status quo */
	    fprintf(stderr, "c_alarm(): someone else wants to ignore alarm!\n");
	    doit = 0;
	}
	else if(oaction != catch_signal)
	{
	    signal(SIGALRM, oaction);	/* oops! put it back quickly! */
	    fprintf(stderr, "c_alarm(): someone else wants the alarm!\n");
	    doit = 0;
	}
#endif

    if(doit)		/* still allowed? */
    {
	(void) alarm(sec);
	if(sec > 0) hit &= ~ (1 << SIGALRM);
    }

    return 0;

}   /* c_alarm */
/*JFACE*/ int c_alarm_1(int nargs) { return c_alarm(nargs); }


function(c_signal,2,2,1,1)
{
    int sig;
    int action;
    void (*func)();

    /* NULL = default */
    /* false = ignore */
    /* true = catch   */

    popint(&action);
    sig = cfgl_get_sig();
    if(sig == -1)
    {
	retint(0);
	return 1;
    }

    if(sig == SIGINT)
	cfgl_fatal("c_signal(): no WAY am I going to let you catch SIGINT this way!\n");

    if(risnull(CINTTYPE, (char *) &action))
	func = signal(sig, SIG_DFL);
    else if(action)
	func = signal(sig, catch_signal);
    else
	func = signal(sig, SIG_IGN);

    retint(func != SIG_ERR);
    return 1;

}   /* c_signal */
/*JFACE*/ int c_signal_2(int nargs) { return c_signal(nargs); }


function(c_signalq,1,1,1,2)
{
    void (*func) (int);
    int sig = cfgl_get_sig();
    char buf[15];
    char *cp;

    func = signal(sig, SIG_IGN);
    signal(sig, func);

    if(func == SIG_DFL)
	retquote("");
    else if(func == SIG_IGN)
	retshort(0);
    else if(func == catch_signal)
	retshort(1);
    else
	retshort(-1);

    buf[0] = 0;
    cp = cfgl_sig_name(sig);
    if(cp)
    {
	strcpy(buf, "SIG");
	strcat(buf, cp);
    }
    retquote(buf);

    return 2;

}   /* c_signalq */
/*JFACE*/ int c_signalq_1(int nargs) { return c_signalq(nargs); }


function(c_signalled,1,1,1,1)
{
    int sig = cfgl_get_sig();
    int result = hit & (1 << sig);
    hit &= ~ result;

    retint(result != 0);
    return 1;
}   /* c_signalled */
/*JFACE*/ int c_signalled_1(int nargs) { return c_signalled(nargs); }
