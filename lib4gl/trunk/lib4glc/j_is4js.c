
# include	"cfun4gl.h"


function(j_is4js,0,0,1,1)
    RUNNER(fglext c_is4js)
{
    retint(1);
    return 1;

}   /* j_is4js */
/*JFACE*/ int c_is4js_0(int nargs) { return j_is4js(nargs); }
