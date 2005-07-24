
/* INSERT Art's copyright notice here */

/* Mostly the work of Art S. Kagel, but merged into Ye Olde Sanderson */
/* calling conventions and stdio-for-4GL library function */

#include "cfun4gl.h"
#include <value.h>

/* 4GL stack var externs - PROBABLY WON'T WORK ON 4JS!! */
extern value_t *fgl_stack, *fgl_stkptr;

typedef enum {Initial, InFmt, EndFmt} Scanning_t;
typedef enum {MethodS, MethodF, MethodP} Method_t;


static value_t *get_args(int n)
{
    value_t *pv = fgl_stkptr;
    value_t *args = (value_t *) malloc( sizeof (value_t) * n );
    char str[1025];

    /* Peek at args. */
    while (--n >= 0) {
	memcpy( &args[n], --pv, sizeof (value_t) );

	switch (args[n].v_type) {
	case SQLCHAR:
	    popstring( str, sizeof(str) );
	    args[n].v_charp = strdup(str);
	    break;

	case SQLSMINT:
	case SQLINT:
	    poplong( &args[n].v_long );
	    args[n].v_type = SQLINT;
	    break;

	case SQLSMFLOAT:
	case SQLFLOAT:
	case SQLDECIMAL:
	    popdub( &args[n].v_double );
	    args[n].v_type = SQLFLOAT;
	    break;

	default:
	    popstring(str, sizeof(str));
	    break;
	}
    }

    return args;
}   /* get_args */


static void free_args(value_t *args, int n)
{
    while (--n >= 0)
	if(args[n].v_type == SQLCHAR)
	    free((void *) args[n].v_charp);

    free((void *) args);
}   /* free_args */


static int art_printf( Method_t method, int nargs )
{
    static char indxstr[] = "cCpsSdfgGiuxXoeEn";

    value_t *args = NULL;
    int ix, ret, result;
    char format[1024], fmt[1025], *fr, *to;
    Scanning_t state;
    char outtemp[1025];
    cfgl_DynStr outstring;
    int outsize;
    char *ftn_name;
    FILE *outfile;

    args = get_args(nargs);
    popstring( format, sizeof(format) );

    switch(method)
    {
    case MethodS:
	ftn_name = "c_sprintf";
	cfgl_initstr(&outstring);
	break;

    case MethodF:
	ftn_name = "c_fprintf";
	cfgl_popfd(&outfile);
	if(! outfile)
	{
	    retquote("");
	    goto EXIT;
	}
	break;

    case MethodP:
	ftn_name = "c_printf";
	outfile = stdout;
	break;
    }

    /* OK, now I've got the args and the stack is properly popped.
     * Now's the time to set up and call the ?printf function.
     * Hmmmmmm, how to do that ....
     * OK, a partial scan of the format string to identify the spec 
     * for each argument ONLY.  Then ?printf each separately!
     */

    ret = 0;
    fr = format;
    memset( fmt, 0, sizeof fmt );
    for (ix=0; ix < nargs; ix++) {
	/* ?printf each argument from 4GL. */
	state = Initial;
	to = fmt;

	/* Copy to end of next format specifier taking any leading text. */
	do {
	    switch (state) {
	    case Initial:
		if (*fr != '%')
		    *to++ = *fr;
		else if (*(fr + 1) == '%') {
		    /* Don't get confused by escaped percents! */
		    /* NOT supporting redundant escapes like %q! */
		    *to++ = '%';
		    *to++ = '%';
		    fr++;
		} else {
		    state = InFmt;
		    *to++ = '%';
		}
		break;

	    case InFmt:
		*to++ = *fr;
		if (strchr( indxstr, *fr ) != (char *)NULL)
		    state = EndFmt;
		break;

	    case EndFmt:
	    default:
		fprintf( stderr,
			 "%s: State machine error (%d)!\n",
			 ftn_name, state );
		break;
	    }
	} while (*++fr != (char)0 && state != EndFmt);
	*to = (char)0;

	if (strlen( fmt ) > 0) {
	    switch (args[ix].v_type)
	    {
	    case SQLCHAR:
		if(method == MethodS)
		    result = sprintf( outtemp, fmt, args[ix].v_charp );
		else
		    result = fprintf( outfile, fmt, args[ix].v_charp );
		break;

	    case SQLINT:
		if(method == MethodS)
		    result = sprintf( outtemp, fmt, args[ix].v_long );
		else
		    result = fprintf( outfile, fmt, args[ix].v_long );
		break;

	    case SQLFLOAT:
		if(method == MethodS)
		    result = sprintf( outtemp, fmt, args[ix].v_double );
		else
		    result = fprintf( outfile, fmt, args[ix].v_double );
		break;

	    default:
		result = -1;
		fprintf( stderr,
			 "%s: Type mapping error (%d)! \n",
			 ftn_name, args[ix].v_type );
		break;
	    }

	    if(result < 0)
		cfgl_errno = errno;
	    else
	    {
		ret += result;
		if(method == MethodS)
		    cfgl_strcat(&outstring, outtemp);
	    }
	}
    }

    if (*fr != (char)0) {
	if(method == MethodS)
	    result = sprintf( outtemp, fr );
	else
	    result = fprintf( outfile, fr );

	if(result < 0)
	    cfgl_errno = errno;
	else
	{
	    ret += result;
	    if(method == MethodS)
		cfgl_strcat(&outstring, outtemp);
	}
    }

    if(method == MethodS) {
        cfgl_retstr(&outstring);
        retlong(ret);
        result = 2;
    }
    else {
	retlong(ret);
	result = 1;
    }

EXIT:
    if(args) free_args(args, nargs);

    return result;

}   /* art_printf */


function(c_sprintf,1,21,1,2)
{
    return art_printf(MethodS, nargs - 1);
}   /* c_sprintf */
/*JFACE*/ int c_sprintf_1(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_2(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_3(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_4(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_5(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_6(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_7(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_8(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_9(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_10(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_11(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_12(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_13(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_14(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_15(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_16(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_17(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_18(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_19(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_20(int nargs) { return c_sprintf(nargs); }
/*JFACE*/ int c_sprintf_21(int nargs) { return c_sprintf(nargs); }


function(c_fprintf,2,22,1,1)
{
    return art_printf(MethodF, nargs - 2);
}   /* c_fprintf */
/*JFACE*/ int c_fprintf_2(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_3(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_4(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_5(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_6(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_7(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_8(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_9(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_10(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_11(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_12(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_13(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_14(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_15(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_16(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_17(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_18(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_19(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_20(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_21(int nargs) { return c_fprintf(nargs); }
/*JFACE*/ int c_fprintf_22(int nargs) { return c_fprintf(nargs); }


function(c_printf,1,21,1,1)
{
    return art_printf(MethodP, nargs - 1);
}   /* c_printf */
/*JFACE*/ int c_printf_1(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_2(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_3(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_4(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_5(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_6(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_7(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_8(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_9(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_10(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_11(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_12(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_13(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_14(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_15(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_16(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_17(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_18(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_19(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_20(int nargs) { return c_printf(nargs); }
/*JFACE*/ int c_printf_21(int nargs) { return c_printf(nargs); }
