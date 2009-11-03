
#include "a4gl_libaubit4gl.h"
#include "./common.h"
/**
 * *
 * *
 * * @param
 * */
int
attr_code (char *s)
{

  A4GL_debug ("Decoding colour %s\n", s);

  return A4GL_get_attr_from_string (s);

}

