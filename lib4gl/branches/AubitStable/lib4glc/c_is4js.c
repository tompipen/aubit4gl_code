
# include	"cfun4gl.h"


function(c_is4js,0,0,1,1)
    RUNNER(fgiusr)
{
    if(nargs != 0)
	fgl_fatal("usage: c_is4js() returning integer\n");

    retint(0);
    return 1;

}   /* c_is4js */
/*JFACE*/ int c_is4js_0(int nargs) { return c_is4js(nargs); }
