
# include	"cfun4gl.h"
# include	<sys/stat.h>
# undef		__USLC__
# include	<stdarg.h>

int cfgl_badargs = 0;


void cfgl_ucase(char *str)
{
    while((*str = toupper(*str)))
	++str;
}   /* cfgl_ucase */


void cfgl_lcase(char *str)
{
    while((*str = tolower(*str)))
	++str;
}   /* cfgl_lcase */


int cfgl_trim(char *str)
{
    int i = 0;

    /* figure the length of the string (don't let NULL confuse us) */
    if(str)
    {
	while(str[i])
	    ++i;

	/* now wind back and trim */
	while(i > 0 && str[i-1] == ' ')
	    --i;
	str[i] = 0;
    }

    return i;
}   /* cfgl_trim */


int cfgl_interpMode(char *buf)
{
    int i;
    int mode = 0;

    if(isdigit(buf[0]))
	for(i = 0; i < 4 && '0' <= *buf && *buf <= '7'; ++i, ++buf)
	    mode = mode * 8 + *buf - '0';
    else
    {
	i = strlen(buf);

	if(i >= 1 && *buf++ == 'r') mode |= S_IRUSR;
	if(i >= 2 && *buf++ == 'w') mode |= S_IWUSR;
	if(i >= 3 && *buf++ == 'x') mode |= S_IXUSR;

	if(i >= 4 && *buf++ == 'r') mode |= S_IRGRP;
	if(i >= 5 && *buf++ == 'w') mode |= S_IWGRP;
	if(i >= 6 && *buf++ == 'x') mode |= S_IXGRP;

	if(i >= 7 && *buf++ == 'r') mode |= S_IROTH;
	if(i >= 8 && *buf++ == 'w') mode |= S_IWOTH;
	if(i >= 9 && *buf++ == 'x') mode |= S_IXOTH;
    }

    return mode;
}   /* cfgl_interpMode */


void cfgl_fatal(char *format, ...)
{
    va_list pvar;
    va_start(pvar, format);
    vfprintf(stderr, format, pvar);
    va_end(pvar);

    exit(CFGL_FATAL);

}   /* cfgl_fatal */


static int node_compare(char *cp1, char *cp2)
{

    return strcmp(((cfgl_Assoc *) cp1)->name, ((cfgl_Assoc *) cp2)->name);
}   /* node_compare */


long cfgl_const(cfgl_Assoc table[], size_t count, char *tab, char *name)
{
    cfgl_Assoc node, *np;

    cfgl_trim(name);
    node.name = name;
    np = (cfgl_Assoc *) bsearch(
			   (char *) &node,
			   (char *) table,
			   (size_t) count,
                           (size_t) sizeof(cfgl_Assoc),
			   (int (*)()) node_compare);

    if(! np)
	fgl_fatal("cfgl_const(%s::%s) not found\n", tab, name);
    
    return np->value;

}   /* cfgl_const */


function(c_badargs,0,0,1,0)
{
    cfgl_badargs = 1;
}   /* c_badargs */
/*JFACE*/ int c_badargs_0(int nargs) { return c_badargs(nargs); }


function(c_debug,0,20,1,0)
{
    cfgl_String buf, str;
    int i;

    str[0] = 0;

    while(nargs-- > 0)
    {
	popstring(buf, sizeof(buf) - 1);
	if(buf)
	{
	    for(i = 0; buf[i]; ++i)
		if(buf[i] == '\t')
		    buf[i] = ' ';

	    strncat(buf, str, sizeof(buf) - 1 - strlen(buf));
	    buf[sizeof(buf) - 1] = 0;
	    strcpy(str, buf);
	}
    }

    fputs(str, stderr);
    fflush(stderr);

    return 0;

}   /* c_debug */
/*JFACE*/ int c_debug_0(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_1(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_2(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_3(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_4(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_5(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_6(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_7(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_8(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_9(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_10(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_11(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_12(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_13(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_14(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_15(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_16(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_17(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_18(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_19(int nargs) { return c_debug(nargs); }
/*JFACE*/ int c_debug_20(int nargs) { return c_debug(nargs); }


function(c_interpreter,0,0,1,1)
{
    extern char *cfgl_interpreter;

    retquote(cfgl_interpreter);
    return 1;

}   /* c_interpreter */
/*JFACE*/ int c_interpreter_0(int nargs) { return c_interpreter(nargs); }


void cfgl_initstr(cfgl_DynStr *dyn)
{
    dyn->alloc = 0;
    dyn->len   = 0;
    dyn->str   = 0;

}   /* cfgl_initstr */


void cfgl_strcat(cfgl_DynStr *dyn, char *str)
{
    int len = strlen(str);
    int alloc;
    char *cp;

    /* nothing to do? */
    if(! len) return;

    if(! dyn->alloc)
    {
	dyn->len = len;
	dyn->alloc = (len + CFGL_STRING) / CFGL_STRING * CFGL_STRING;
	dyn->str = (char *) malloc(dyn->alloc);
	strcpy(dyn->str, str);
    }
    else
    {
	alloc = (len + dyn->len + CFGL_STRING) / CFGL_STRING * CFGL_STRING;
	if(alloc > dyn->alloc)
	{
	    cp = (char *) realloc((void *) dyn->str, alloc);
	    if(! cp)
		return;
		/* TODO: yield some sort of error! */

	    dyn->alloc = alloc;
	    dyn->str = cp;
	}

	dyn->len += len;
	strcat(dyn->str, str);
    }

}   /* cfgl_strcat */


void cfgl_retstr(cfgl_DynStr *dyn)
{
    if(! dyn->alloc)
	retquote("");
    else
    {
	retquote(dyn->str);
	free((void *) dyn->str);
	cfgl_initstr(dyn);	/* JUST in case */
    }

}   /* cfgl_retstr */
