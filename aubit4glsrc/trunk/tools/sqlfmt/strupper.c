/*
@(#)File:            $RCSfile: strupper.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2003-05-12 14:24:43 $
@(#)Purpose:         Convert string to upper case
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992,1997-98
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/  
  
/*TABSTOP=4*/ 
  
#define _POSIX_SOURCE	1
  
#include <ctype.h>
#include "jlss.h"
  
#ifndef lint
static const char rcs[] =
  "@(#)$Id: strupper.c,v 1.2 2003-05-12 14:24:43 mikeaubury Exp $";

#endif	/*  */
char *
strupper (char *s) 
{
  char *t = s;
  char c;
  while ((c = *t) != '\0')
    *t++ = toupper (c);
  return (t);
}


#ifdef TEST
static char *list[] = 
  {
"ALL UPPER CASE OR NON-ALPHA _0123456789~`!@#$%^&*()-=+[]{}|\\\"':;/?.,<>", "all lower case",
"mIxEd CaSe", (char *) 0 
};

#include <assert.h>
#include <stdio.h>
#include <string.h>
  int
main (void) 
{
  char **s;
  char *end;
  char *src;
  char buffer[128];
  for (s = list; *s != (char *) 0; s++)
    
    {
      strcpy (buffer, *s);
      printf ("Before: %s\n", buffer);
      end = strupper (buffer);
      assert (*end == '\0');
      for (src = buffer; src < end; src++)
	
	{
	  char c = *src;
	  assert (!isalpha (c) || isupper (c));
	}
      printf ("After:  %s\n", buffer);
    }
  return (0);
}


#endif	/* TEST */
