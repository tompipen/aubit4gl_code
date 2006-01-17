#include "a4gl_libaubit4gl_int.h"


int aclfgl_aclfgl_set_color (int _nargs){
   long c ;
   long r ;
   long g ;
   long b ;
   struct BINDING fbind[4]={ /* 4 */
   {0,2,0,0,0,0} ,
   {0,2,0,0,0,0} ,
   {0,2,0,0,0,0} ,
   {0,2,0,0,0,0}
   };
   fbind[0].ptr=&c;
   fbind[1].ptr=&r;
   fbind[2].ptr=&g;
   fbind[3].ptr=&b;
   A4GL_pop_params(fbind,4);

   A4GL_init_color(c,r,g,b);

   return 0;
}



int aclfgl_aclfgl_random(int n) {
int a;
static int seeded=0;
        if (!seeded) {
                seeded=1;
                srand(time(0));
        }
        a=A4GL_pop_int();
        a=rand()%a;
        A4GL_push_int(a);
        return 1;
}


/**
 * Gets the keyval.
 *
 * @param _np the number of parameters passed by stack.
 * @return Allways 1
 */
int
aclfgl_fgl_keyval (int _np)
{
  int a;
  a = A4GL_fgl_keyval (_np);
  A4GL_debug ("TST1 Got %d\n", a);
  return a;
}

int aclfgl_aclfgl_get_user(int n) {
        A4GL_push_user ();
        return 1;
}






/* 
// Added with permission :
//___| read_pipe.c |______________________________________________________
*/
/*
    Run a Unix command and return the first line of output to 4GL
    Usage: CALL read_pipe(command) RETURNING string
    Doug Lawry, 19/12/91

	Modified for Aubit MJA - June 2004
*/

#define MAX_STRING 512

int aclfgl_aclfgl_read_pipe(int nargs)
{
    FILE *pp;                                /* pipe pointer          */
    char *cmd_orig;                    /* command to be run     */
    char *cmd;                    /* command to be run     */
    char data[MAX_STRING];                   /* return from command   */
    int  bytes = 0;                          /* number of bytes read  */

    cmd_orig=A4GL_char_pop();               /* get the command       */
    A4GL_trim(cmd_orig);                   /* strip trailing spaces */
    cmd=acl_malloc2(strlen(cmd_orig)+20);
    strcpy(cmd,cmd_orig);
    free(cmd_orig);
    strcat(cmd, " 2>/dev/null");             /* ignore error output   */

    A4GL_set_a4gl_status(0);

    if ((pp = popen(cmd, "r")) == NULL) {
        A4GL_set_a4gl_status(100);                   /* set error status      */
	} else {
        for (bytes = 0; bytes < MAX_STRING - 1; bytes++)
            if ((data[bytes] = getc(pp)) == EOF || data[bytes] == '\n')
                break;
#ifdef MSVC
        _pclose(pp);                          /* close the pipe        */
#else
		pclose(pp);                          /* close the pipe        */
#endif
    }

    data[bytes] = 0;                      /* terminate string      */

    free(cmd);
    A4GL_push_char(data);                          /* return command output */
    return(1);                               /* returning 1 parameter */
}

/* End of inclusion */



/**
 * Upshift a string.
 *
 * The origin string is getted from the stack.
 *
 * The string upshifted is returned by the stack.
 *
 * @param The number of parameters
 * @return Allways 1
 */
int
aclfgl_upshift (int _np)
{
  char *v1;
  if (_np != 1)
    {
      A4GL_fgl_error (-3000, "", 0, 0);
    }
  v1 = A4GL_char_pop ();
  A4GL_convupper (v1);
  A4GL_push_char (v1);
  acl_free (v1);
  return 1;
}


/**
 * Downshift a string.
 *
 * The origin string is getted from the stack.
 *
 * The string downshifted is returned by the stack.
 *
 * @param The number of parameters
 * @return Allways 1
 */
int
aclfgl_downshift (int _np)
{
  char *v1;
  if (_np != 1)
    {
      A4GL_fgl_error (-3000, "", 0, 0);
    }
  /* char_pop(v1); */
  v1 = A4GL_char_pop ();
  /* convupper(v1); */
  A4GL_convlower (v1);
  A4GL_push_char (v1);
  acl_free (v1);
  return 1;
}


/* ============================== EOF ========================== */
