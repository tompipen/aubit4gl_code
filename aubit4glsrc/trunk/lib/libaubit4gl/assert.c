#include "a4gl_libaubit4gl_int.h"
#include <stdio.h>

static char * (*assertCallback)(const char *s, char *mod, int ln)=NULL;


void
A4GL_assertion_failed (const char *s)
{
  static int asserting = 0;
  fflush (stdout);
  /* Make sure we're only called once 
     if this assert is causing a later assert - we
     need to ignore any later ones...
   */
  if (asserting)
    return;
  asserting++;
  A4GL_set_errm (s);
#ifdef DEBUG
  A4GL_debug ("%s", A4GL_null_as_null (s));
#endif

  if (A4GL_isyes (acl_getenv ("DOING_CM")))
    {
      FPRINTF (A4GL_get_stderr (), "%s\n", A4GL_null_as_null (s));
    }

  if (A4GL_isyes (acl_getenv ("CORE_ON_ASSERT")))
    {
      char *ptr = 0;
      A4GL_exitwith ("Assertion failed %s");
      *ptr = 0;
      A4GL_chk_err (0, "Unknown");
    }
  	A4GL_gotolinemode ();
  	A4GL_set_lasterrorstr (s);

      A4GL_push_char ("\nAssert failed:\n\n");
      A4GL_push_char ((char*)s);
      A4GL_push_char ("\n\n");
      A4GL_errorlog ("Unknown", 0, 3);
  A4GL_exitwith ("Assertion failed");
  FPRINTF (A4GL_get_stderr (), "Assertion failed: %s\n", A4GL_null_as_null (s));


  A4GL_chk_err (0, "Unknown");
  A4GL_fgl_die (2);
}


#ifdef A4GL_assertion
#undef  A4GL_assertion
#endif

/**
 * Assert if an expression is true.
 *
 * @param a The result of the expression:
 *   - 0 : The expression was true.
 *   - Otherwise : The expression was not true.
 * @param s The message if the expression is not true.
 */
void
A4GL_assertion (int a, const char *s)
{
  if (a)
    {
      A4GL_assertion_failed (s);
    }
}


#

/**
 * Assert if an expression is true.
 *
 * @param a The result of the expression:
 *   - 0 : The expression was true.
 *   - Otherwise : The expression was not true.
 * @param s The message if the expression is not true.
 */
void
A4GL_assertion_full (int a, const char *s, char *mod, int ln)
{
  if (a)
    {
      char buff[2000];
      char *assertCallbackString="";
	if (assertCallback) {
		assertCallbackString=assertCallback(s,mod,ln);
	}
      SPRINTF4 (buff, "%s (File:%s Line:%d)%s", s, mod, ln, assertCallbackString);
      A4GL_assertion_failed (buff);

    }
}



void registerAssertionCallback(void *p) {
	assertCallback=p;
}
