
# include	"cfun4gl.h"
# include	<fgicfunc.h>
# include	"fdecls.h"


# ifdef CFGL_FGLGO
char *cfgl_interpreter = "fglgo";
# endif

# ifdef CFGL_FGLDB
char *cfgl_interpreter = "fgldb";
# endif

/* comments in this array must be single-liners, so the scripts work */
cfunc_t usrcfuncs[] =
{
# include	"fgiusr.inc"

    0, 0, 0
};
