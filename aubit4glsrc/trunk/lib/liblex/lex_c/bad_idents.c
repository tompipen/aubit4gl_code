#include "a4gl_lib_lex_c_int.h"


int
A4GL_bad_identifiers (char *s)
{
  if (strcasecmp (s, "case") == 0)
    return 1;
  if (strcasecmp (s, "switch") == 0)
    return 1;
  if (strcasecmp (s, "if") == 0)
    return 1;
  if (strcasecmp (s, "while") == 0)
    return 1;
  if (strcasecmp (s, "do") == 0)
    return 1;

  return 0;
}
