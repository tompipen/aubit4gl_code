
#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>

void
A4GL_pad_nstring (char *ptr, int size)
{
  //int a;
  int p;
  int s;
  s = (int) strlen (ptr);
  p = size - s;
  if (p > 0)
    {
      memset (&ptr[s], ' ', p);
    }
  ptr[size] = 0;
}




int nchar_strlen(char *s) {
	return A4GL_wcswidth(s);
}

