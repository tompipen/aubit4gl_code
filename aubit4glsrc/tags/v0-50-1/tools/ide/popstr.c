/*
@(#)File:            $RCSfile: popstr.c,v $
@(#)Version:         $Revision: 1.3 $
@(#)Last changed:    $Date: 2003-05-15 07:10:48 $
@(#)Purpose:         Pop string and A4GL_strip trailing blanks
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1988,1990,1998
*/

#include <string.h>
#include <assert.h>

#ifdef FOURJS
#include "f2c/r_c.h"
#else
#include "fglsys.h"
#endif

#ifndef lint
static const char rcs[] =
  "@(#)$Id: popstr.c,v 1.3 2003-05-15 07:10:48 mikeaubury Exp $";
#endif

/* -- Routine: popstring		*/

void
popstring (char *s, int l)
{
  register char *p = s + l - 1;

  popquote (s, l);
  assert (strlen (s) == l - 1);

  if (l <= 1)
    return;			/* Length 1 => "" */

  while (p > s)
    if (*--p != ' ')
      break;
  *(p + 1) = '\0';
}
