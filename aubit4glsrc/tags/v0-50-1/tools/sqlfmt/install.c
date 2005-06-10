/*
	@(#)$Id: install.c,v 1.2 2003-05-12 14:24:42 mikeaubury Exp $
	Install routine for sqlfmt
	Use file of keywords supplied by user
	J Leffler
*/  
  
#include <stdio.h>
#include <stdlib.h>
#include "sqlfmt.h"
#include "stderr.h"
  
#define GLOBAL
#define	KEYTABSIZE	512
#define BUFLEN		128
  
#define ALLOC(x)	malloc((unsigned)(x))
static char *buildtab[KEYTABSIZE];

#ifndef lint
static const char sccs[] =
  "@(#)$Id: install.c,v 1.2 2003-05-12 14:24:42 mikeaubury Exp $";

#endif	/*  */
  void
install (char *file) 
{
  FILE * fp;
  char *cp;
  int i = 0;
  int len;
  char buffer[BUFLEN];
  if ((fp = fopen (file, "r")) == NULL)
    error2 ("unable to open file", file);
  while (fgets (buffer, BUFLEN, fp) != NULL)
    
    {
      if (i >= KEYTABSIZE)
	error2 ("too many keywords in file", file);
      len = strlen (buffer);
      if ((cp = ALLOC (len)) == NULL)
	error2 ("out of memory reading file", file);
      buffer[len - 1] = '\0';
      strcpy (cp, buffer);
      buildtab[i++] = cp;
    }
  fclose (fp);
  kw_table = buildtab;
  kw_size = i;
}


