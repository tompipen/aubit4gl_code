
# include	"cfun4gl.h"


static int base, commas, depth;

static char *base_convert(char *str, unsigned long n, int width)
{
    int ch;

    if(commas && depth++ > 0 && depth % commas == 1)
	--width;
    if(width > 0 || n >= base)
    {
	str = base_convert(str, n / base, width - 1);
    }

    ch = n % base;
    *str = ch + (ch < 10 ? '0' : 'A' - 10);
    if(commas && --depth && depth % commas == 0)
	*++str =  ',';
    return str + 1;

}   /* base_convert */


function(c_asbase,2,4,1,1)
{
    int width;
    unsigned long n;
    char buf[65];

    if(nargs < 2 || nargs > 4)
	cfgl_fatal("usage: c_asbase(base, n [,width [, commas]] smallint)"
			 " returning char(*)\n");

    commas = 0;
    width = 0;
    switch(nargs)
    {
    case 4:
	popint(&commas);
	/* FALLTHROUGH */
    case 3:
	popint(&width);
	/* FALLTHROUGH */
    case 2:
	poplong((long *) &n);
	popint(&base);
    }

    if(width < 0) width = 0;
    if(width > 64) width = 64;
    if(commas < 0) commas = 0;

    if(base < 2 || base > 36)
	cfgl_fatal("c_asbase(): require base between 2 and 36\n");

    *base_convert(buf, n, width - 1) = 0;
    retquote(buf);
    return 1;

}   /* c_asbase */
/*JFACE*/ int c_asbase_2(int nargs) { return c_asbase(nargs); }
/*JFACE*/ int c_asbase_3(int nargs) { return c_asbase(nargs); }
/*JFACE*/ int c_asbase_4(int nargs) { return c_asbase(nargs); }


function(c_tuple,0,20,1,1)
{
    cfgl_String buf1, buf2;
    int l1, l2;

    *buf1 = 0;
    l1 = 0;
    while(nargs-- > 0)
    {
	popvchar(buf2, sizeof(buf2));
	l2 = strlen(buf2);
	if(l1 + l2 > sizeof(buf1) - 1)
	    l1 = l2 - sizeof(buf1) - 1;
	buf1[l1] = 0;
	strcat(buf2, buf1);
	strcpy(buf1, buf2);
	l1 += l2;
    }

    retquote(buf1);
    return 1;

}   /* c_tuple */
/*JFACE*/ int c_tuple_0(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_1(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_2(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_3(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_4(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_5(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_6(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_7(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_8(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_9(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_10(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_11(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_12(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_13(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_14(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_15(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_16(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_17(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_18(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_19(int nargs) { return c_tuple(nargs); }
/*JFACE*/ int c_tuple_20(int nargs) { return c_tuple(nargs); }


function(c_basename,1,1,1,1)
{
    cfgl_String buf;
    int i;
    char *cp = buf;

    popvchar(buf, sizeof(buf));
    for(i = 0; buf[i]; ++i)
	if(buf[i] == '/')
	    cp = buf + i + 1;

    retquote(cp);
    return 1;

}   /* c_basename */
/*JFACE*/ int c_basename_1(int nargs) { return c_basename(nargs); }
