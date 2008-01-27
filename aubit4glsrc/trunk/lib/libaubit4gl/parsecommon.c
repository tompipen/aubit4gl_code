#include "a4gl_libaubit4gl.h"


#ifdef OLD
struct binding_comp *
ensure_bind (long *a_bindp, long need, struct binding_comp *b)
{
  long a_bind;
  a_bind = *a_bindp;
  A4GL_debug ("ensure bind %d %d\n", a_bind, need);

  if (a_bind > need)
    return b;

  while (a_bind <= need)
    {
      if (a_bind == 0)
        a_bind = 2000;          // Start off small :-)
      else
        {
          a_bind = a_bind * 2;  // just double it ?
        }
    }
  b = realloc (b, sizeof (struct binding_comp) * a_bind);
  A4GL_debug ("ensure bind Allocted %d\n", a_bind);
  A4GL_assertion (b == 0, "Unable to allocation memory for binding");
  *a_bindp = a_bind;
  return b;
}
#endif




void
A4GL_strip_bracket (char *s)
{
  char buff[2048];
  int a;
  int c = 0;
  int f = 0;

  A4GL_debug ("strip_bracket %s\n", s);
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '[')
        f++;

      if (f == 0 && s[a] != ' ')
        {
          buff[c++] = s[a];
          buff[c] = 0;
          if (c >= sizeof (buff))
            {
              A4GL_assertion (1, "buff in strip_bracket too small");
            }
        }
      if (s[a] == ']')
        f--;
    }
  if (c >= sizeof (buff))
    {
      A4GL_assertion (1, "buff in strip_bracket too small");
    }
  buff[c] = 0;
  strcpy (s, buff);
}


int A4GL_bad_identifiers(char *S) {
	return 0;
}

