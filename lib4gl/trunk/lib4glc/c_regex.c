
# include       "cfun4gl.h"
# include       <sys/types.h>
# include       <regex.h>


# define        MAX_REGEX       2047

typedef struct
{
    int skip;
    regex_t preg;
    regmatch_t *pmatch;
} cfgl_regex;

function(c_regcomp,1,2,1,2)
{
    char flags[7];
    char buf[MAX_REGEX + 1];
    cfgl_regex *wp;
    int cflags;
    char *cp;
    int status;

    if(nargs != 1 && nargs != 2)
        cfgl_fatal("usage: c_regcomp(pattern [, flags] char(*))"
                         " returning (status, handle) integer\n");

    cflags = 0;
    if(nargs == 1)
        cflags = REG_EXTENDED;
    else
    {
        popstring(flags, sizeof(flags));
        for(cp = flags; *cp; ++cp)
        {
            switch(*cp)
            {
            case 'B': cflags &= ~REG_EXTENDED; break;
            case 'E': cflags |=  REG_EXTENDED; break;
            case 'I': cflags |=  REG_ICASE;    break;
            case 'N': cflags |=  REG_NOSUB;    break;
            case 'L': cflags |=  REG_NEWLINE;  break;
            }
        }
    }

    popstring(buf, sizeof(buf));

    wp = (cfgl_regex *) malloc(sizeof(cfgl_regex));
    if(!wp)
    {
        retint(REG_ESPACE);
        retquote("");
        return 2;
    }
    wp->skip = 0;
    wp->pmatch = 0;

    status = regcomp(&wp->preg, buf, cflags);
    if(status)
    {
        free((void *) wp);
        retint(status);
        retquote("");
        return 2;
    }

    wp->pmatch = (regmatch_t *) calloc(wp->preg.re_nsub + 1,
                                       sizeof(regmatch_t));

    if(!wp->pmatch)
    {
        regfree(&wp->preg);
        free((void *) wp);

        retint(REG_ESPACE);
        retquote("");
        return 2;
    }

    retint(wp->preg.re_nsub);
    retlong((long) wp);
    return 2;

}   /* c_regcomp */
/*JFACE*/ int c_regcomp_1(int nargs) { return c_regcomp(nargs); }
/*JFACE*/ int c_regcomp_2(int nargs) { return c_regcomp(nargs); }


function(c_regexec,3,4,1,1)
{
    char flags[7];
    char buf[2048];
    long handle;
    cfgl_regex *wp;
    char *cp;
    int eflags, skip;
    int status;

    if(nargs != 3 && nargs != 4)
        cfgl_fatal("usage: c_regexec(handle, skip integer, str [, flags] char(*))"
                         " returning (status) int\n");

    eflags = 0;
    if(nargs == 4)
    {
        popstring(flags, sizeof(flags));
        for(cp = flags; *cp; ++cp)
        {
            switch(*cp)
            {
            case 'B': eflags |= REG_NOTBOL; break;
            case 'E': eflags |= REG_NOTEOL; break;
            }
        }
    }

    popstring(buf, sizeof(buf));
    popint(&skip);
    poplong(&handle);

    if(risnull(CLONGTYPE, (char *) &handle) || ! handle)
    {
        retquote("");
        return 1;
    }

    wp = (cfgl_regex *) handle;
    wp->skip = skip;

    if(risnull(CINTTYPE, (char *) &wp->skip) || wp->skip < 0)
        wp->skip = 0;

    /* set this for your convenience if you are looping */
    if(wp->skip > 0) eflags |= REG_NOTBOL;

    status = regexec(&wp->preg, buf + wp->skip,
                   wp->preg.re_nsub + 1, wp->pmatch,
                   eflags);

    if(status == REG_NOMATCH)
        retquote("");
    else
        retint(status);

    return 1;

}   /* c_regexec */
/*JFACE*/ int c_regexec_3(int nargs) { return c_regexec(nargs); }
/*JFACE*/ int c_regexec_4(int nargs) { return c_regexec(nargs); }


function(c_regsub,1,21,1,-40)
{
    long handle;
    cfgl_regex *wp;
    int lo, hi;
    int i, sub, nsubs = 0, subs[20];

    if(nargs < 1 || nargs > 21)
        cfgl_fatal("usage: c_regsub(handle[, sub ...] integer)"
                         " returning (lo, hi) ... smallint\n");

    while(nargs-- > 1)
        popint(&subs[nargs - 1]);

    if(nsubs == 0)
	subs[nsubs++] = 0;

    poplong(&handle);
    if(risnull(CLONGTYPE, (char *) &handle) || ! handle)
    {
FAIL:
	for(i = 0; i < nsubs; ++i)
	{
	    retquote("");
	    retquote("");
	}
        return nsubs * 2;
    }

    wp = (cfgl_regex *) handle;
    if(!wp->pmatch)
        goto FAIL;

    for(i = 0; i < nsubs; ++i)
    {
	sub = subs[i];
	if(sub < 0 || sub >= wp->preg.re_nsub + 1)
        {
	    retquote("");
	    retquote("");
	}
	else
	{
	    lo = wp->pmatch[sub].rm_so;
	    hi = wp->pmatch[sub].rm_eo;

	    /* convert to 4GL offset, and be paranoid about -1 */
	    if(lo == -1)
		hi = -1;
	    else
		lo += wp->skip + 1;

	    if(hi == -1)
		lo = -1;
	    else
		hi += wp->skip;

	    retint(lo);
	    retint(hi);
	}
    }

    return nsubs * 2;

}   /* c_regsub */
/*JFACE*/ int c_regsub_1(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_2(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_3(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_4(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_5(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_6(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_7(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_8(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_9(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_10(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_11(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_12(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_13(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_14(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_15(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_16(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_17(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_18(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_19(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_20(int nargs) { return c_regsub(nargs); }
/*JFACE*/ int c_regsub_21(int nargs) { return c_regsub(nargs); }


function(c_regerror,1,2,1,2)
{
    long handle;
    int status;
    regex_t *rp;
    char *cp;
    char buf[2048];

    if(nargs != 1 && nargs != 2)
        cfgl_fatal("usage: c_regerror([handle,] status integer)"
                         " returning (errcode, errstr) char(*)\n");

    popint(&status);
    if(nargs == 1)
        rp = 0;
    else
    {
        poplong(&handle);

        if(risnull(CLONGTYPE, (char *) &handle))
            rp = 0;
        else
            rp = &((cfgl_regex *) handle)->preg;
    }

    if(risnull(CINTTYPE, (char *) &status))
        cp = "(NULL)";
    else
        switch(status)
        {
        case REG_NOMATCH:  cp = "NOMATCH";   break;
        case REG_BADPAT:   cp = "BADPAT";    break;
        case REG_ECOLLATE: cp = "ECOLLATE";  break;
        case REG_ECTYPE:   cp = "ECTYPE";    break;
        case REG_EESCAPE:  cp = "EESCAPE";   break;
        case REG_ESUBREG:  cp = "ESUBREG";   break;
        case REG_EBRACK:   cp = "EBRACK";    break;
# if ! defined(__linux)
        case REG_ENOSYS:   cp = "ENOSYS";    break;
# endif
        case REG_EPAREN:   cp = "EPAREN";    break;
        case REG_EBRACE:   cp = "EBRACE";    break;
        case REG_BADBR:    cp = "BADBR";     break;
        case REG_ERANGE:   cp = "ERANGE";    break;
        case REG_ESPACE:   cp = "ESPACE";    break;
        case REG_BADRPT:   cp = "BADRPT";    break;
        default:           cp = "(UNKNOWN)"; break;
        }

    (void) regerror(status, rp, buf, sizeof(buf));

    retquote(cp);
    retquote(buf);
    return 2;

}   /* c_regerror */
/*JFACE*/ int c_regerror_1(int nargs) { return c_regerror(nargs); }
/*JFACE*/ int c_regerror_2(int nargs) { return c_regerror(nargs); }


function(c_regfree,1,20,1,0)
{
    long handle;
    cfgl_regex *wp;

    if(nargs == 0)
        cfgl_fatal("usage: c_regfree(handle ... integer)\n");

    while(--nargs >= 0)
    {
        poplong(&handle);
        if(! risnull(CLONGTYPE, (char *) &handle))
        {
            wp = (cfgl_regex *) handle;

            free((void *) wp->pmatch);
            regfree(&wp->preg);
            free((void *) wp);
        }
    }

    return 0;

}   /* c_regfree */
/*JFACE*/ int c_regfree_1(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_2(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_3(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_4(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_5(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_6(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_7(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_8(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_9(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_10(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_11(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_12(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_13(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_14(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_15(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_16(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_17(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_18(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_19(int nargs) { return c_regfree(nargs); }
/*JFACE*/ int c_regfree_20(int nargs) { return c_regfree(nargs); }
