#include "a4gl_libaubit4gl_int.h"
#include <stdio.h>

void A4GL_assertion_failed(char *s)  {
      fflush (stdout);
      A4GL_set_errm (s);
      A4GL_debug ("%s", A4GL_null_as_null(s));

	if (A4GL_isyes(acl_getenv("DOING_CM"))) {
      		FPRINTF (stderr,"%s\n", A4GL_null_as_null(s));
	}

      if (A4GL_isyes(acl_getenv("CORE_ON_ASSERT"))) {
		char *ptr=0;
      		A4GL_exitwith ("Assertion failed %s");
		*ptr=0;
      		A4GL_chk_err (0, "Unknown");
	}

      A4GL_set_lasterrorstr(s);
      A4GL_exitwith ("Assertion failed");
      FPRINTF (stderr, "Assertion failed: %s\n", A4GL_null_as_null(s));
      A4GL_chk_err (0, "Unknown");
      A4GL_fgl_die(2);
}



/**
 * Assert if an expression is true.
 *
 * @param a The result of the expression:
 *   - 0 : The expression was true.
 *   - Otherwise : The expression was not true.
 * @param s The message if the expression is not true.
 */
void
A4GL_assertion (int a, char *s)
{
/* A4GL_debug("Assertion ? a=%d s=%s",a,s); */
if (a) {
	A4GL_assertion_failed(s);
}
}


