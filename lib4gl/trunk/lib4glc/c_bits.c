
# include	"cfun4gl.h"


function(c_and,1,20,1,1)
{
    int x, y;

    if(nargs < 2)
	fgl_fatal("usage: c_and(n1, n2, ... integer) returning integer\n");

    popint(&x);
    while(--nargs > 0)
    {
	popint(&y);
	x &= y;
    }

    retint(x);
    return 1;

}   /* c_and */
/*JFACE*/ int c_and_1(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_2(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_3(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_4(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_5(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_6(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_7(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_8(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_9(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_10(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_11(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_12(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_13(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_14(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_15(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_16(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_17(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_18(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_19(int nargs) { return c_and(nargs); }
/*JFACE*/ int c_and_20(int nargs) { return c_and(nargs); }


function(c_or,1,20,1,1)
{
    int x, y;

    if(nargs < 2)
	fgl_fatal("usage: c_or(n1, n2, ... integer) returning integer\n");

    popint(&x);
    while(--nargs > 0)
    {
	popint(&y);
	x |= y;
    }

    retint(x);
    return 1;

}   /* c_or */
/*JFACE*/ int c_or_1(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_2(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_3(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_4(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_5(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_6(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_7(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_8(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_9(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_10(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_11(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_12(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_13(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_14(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_15(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_16(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_17(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_18(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_19(int nargs) { return c_or(nargs); }
/*JFACE*/ int c_or_20(int nargs) { return c_or(nargs); }


function(c_xor,1,20,1,1)
{
    int x, y;

    if(nargs < 2)
	fgl_fatal("usage: c_xor(n1, n2, ... integer) returning integer\n");

    popint(&x);
    while(--nargs > 0)
    {
	popint(&y);
	x ^= y;
    }

    retint(x);
    return 1;

}   /* c_xor */
/*JFACE*/ int c_xor_1(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_2(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_3(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_4(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_5(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_6(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_7(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_8(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_9(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_10(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_11(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_12(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_13(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_14(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_15(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_16(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_17(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_18(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_19(int nargs) { return c_xor(nargs); }
/*JFACE*/ int c_xor_20(int nargs) { return c_xor(nargs); }


function(c_not,1,1,1,1)
{
    int x;

    if(nargs != 1)
	fgl_fatal("usage: c_not(n1 integer) returning integer\n");

    popint(&x);
    retint(~x);
    return 1;

}   /* c_not */
/*JFACE*/ int c_not_1(int nargs) { return c_not(nargs); }


function(c_lshift,1,2,1,1)
{
    int n, s;

    if(nargs != 1 && nargs != 2)
	fgl_fatal("usage: c_lshift(n[, s] integer) returning integer\n");

    if(nargs == 2)
	popint(&s);
    else
	s = 1;
    popint(&n);
    retint(n << s);
    return 1;

}   /* c_lshift */
/*JFACE*/ int c_lshift_1(int nargs) { return c_lshift(nargs); }
/*JFACE*/ int c_lshift_2(int nargs) { return c_lshift(nargs); }


function(c_rshift,1,2,1,1)
{
    int n, s;

    if(nargs != 1 && nargs != 2)
	fgl_fatal("usage: c_rshift(n [, s] integer) returning integer\n");

    if(nargs == 2)
	popint(&s);
    else
	s = 1;

    popint(&n);
    retint(n >> s);
    return 1;

}   /* c_rshift */
/*JFACE*/ int c_rshift_1(int nargs) { return c_rshift(nargs); }
/*JFACE*/ int c_rshift_2(int nargs) { return c_rshift(nargs); }
