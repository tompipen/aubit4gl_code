/*
@(#)File:            $RCSfile: fglxref.c,v $
@(#)Version:         $Revision: 1.3 $
@(#)Last changed:    $Date: 2003-09-29 15:10:38 $
@(#)Purpose:         Produce basic data for I4GL Cross-Reference Program
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1990-92,1996,1998
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/  
  
/* -- Include Files -- */ 
  
#include <stdio.h>
#include "stderr.h"
#include "getopt.h"
#include "sqlfmt.h"
#include "filter.h"
  
/* -- Declarations -- */ 
char **kw_table;
int kw_size;
extern char *fgl_tab[];
extern int fgl_size;

#ifndef lint
static const char sccs[] =
  "@(#)$Id: fglxref.c,v 1.3 2003-09-29 15:10:38 mikeaubury Exp $";

#endif	/*  */
  int
main (int argc, char **argv) 
{
  int i;
  int arg;
  char *file = (char *) 0;
  int pflag = 0;
  A4GL_setarg0 (argv[0]);
  opterr = 0;
  while ((arg = getopt (argc, argv, "Vpf:")) != EOF)
    
    {
      switch (arg)
	
	{
	case 'p':
	  pflag = 1;
	  break;
	case 'f':
	  file = optarg;
	  break;
	case 'V':
	  puts (&"@(#)SQLFMT Version 14 (1998-11-04)"[4]);
	  version ("", "$Revision: 1.3 $ ($Date: 2003-09-29 15:10:38 $)");
	  exit (0);
	  
	    /* NOTREACHED */ 
	default:
	  usage ("[-V] [-p] [-f keywordfile] [file ...]");
	  break;
	}
    }
  
    /* Set up appropriate set of keywords */ 
    if (file)
    install (file);
  
  else
    
    {
      kw_table = fgl_tab;
      kw_size = fgl_size;
    }
  if (pflag)
    
    {
      for (i = 0; i < kw_size; i++)
	printf ("%s\n", kw_table[i]);
    }
  
  else
    
    {
      filter (argc, argv, optind, fglxref);
    }
  return (0);
}



int yywrap() {
return 1;
}
