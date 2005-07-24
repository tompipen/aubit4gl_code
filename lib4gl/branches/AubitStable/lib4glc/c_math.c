
# include	"cfun4gl.h"
# include	<math.h>


function(c_log,1,1,1,1)
{
    double n;

    if(nargs != 1)
        cfgl_fatal("usage: c_log(n double) returning double\n");

    popdub(&n);
    n = log(n);
    retdub(&n);
    return 1;

}   /* c_log */
/*JFACE*/ int c_log_1(int nargs) { return c_log(nargs); }


function(c_log10,1,1,1,1)
{
    double n;

    if(nargs != 1)
        cfgl_fatal("usage: c_log10(n double) returning double\n");

    popdub(&n);
    n = log10(n);
    retdub(&n);
    return 1;

}   /* c_log10 */
/*JFACE*/ int c_log10_1(int nargs) { return c_log10(nargs); }


function(c_srand,1,1,1,0)
{
    int seed;

    if(nargs != 1)
	cfgl_fatal("usage: c_srand(seed integer)\n");

    popint(&seed);
    if(risnull(CINTTYPE, (char *) &seed))
	seed = 0;
    srand(seed);

    return 0;

}   /* c_srand */
/*JFACE*/ int c_srand_1(int nargs) { return c_srand(nargs); }


function(c_rand,0,0,1,1)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_rand() returning integer\n");

    retint(rand());
    return 1;

}   /* c_rand */
/*JFACE*/ int c_rand_0(int nargs) { return c_rand(nargs); }
