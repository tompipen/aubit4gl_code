/*
@(#)File:            $RCSfile: sqlmain.c,v $
@(#)Version:         $Revision: 1.3 $
@(#)Last changed:    $Date: 2003-05-15 07:10:51 $
@(#)Purpose:         Convert ISQL/I4GL Keywords to upper case
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1987,1990-1993,1996,1998
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/  
  
/* -- Include Files -- */ 
  
#include <stdio.h>
#include "getopt.h"
#include "stderr.h"
#include "sqlfmt.h"
#include "filter.h"
  
/* -- Declarations -- */ 
char **kw_table;
int kw_size;
int kflag = PLAIN_CASE;	/* Print keywords as supplied */
int wflag = PLAIN_CASE;	/* Print words (non-keywords) ditto */
extern char *sql_tab[];
extern int sql_size;
extern char *fgl_tab[];
extern int fgl_size;

#ifndef lint
static const char sccs[] =
  "@(#)$Id: sqlmain.c,v 1.3 2003-05-15 07:10:51 mikeaubury Exp $";

#endif	/*  */
  int
main (int argc, char **argv) 
{
  int i;
  int arg;
  char *file = (char *) 0;
  int pflag = 0;
  setarg0 (argv[0]);
  while ((arg = getopt (argc, argv, "LUVlpuf:")) != EOF)
    
    {
      switch (arg)
	
	{
	case 'L':		/* Print keywords in lower case */
	  kflag = LOWER_CASE;
	  break;
	case 'U':		/* Print keywords in upper case */
	  kflag = UPPER_CASE;
	  break;
	case 'l':		/* Print words (non-keywords) in lower case */
	  wflag = LOWER_CASE;
	  break;
	case 'u':		/* Print words (non-keywords) in upper case */
	  wflag = UPPER_CASE;
	  break;
	case 'p':
	  pflag = 1;
	  break;
	case 'f':
	  file = optarg;
	  break;
	case 'V':
	  puts (&"@(#)SQLFMT Version 14 (1998-11-04)"[4]);
	  version ("", "$Revision: 1.3 $ ($Date: 2003-05-15 07:10:51 $)");
	  exit (0);
	  
	    /* NOTREACHED */ 
	default:
	  usage ("[-LUVlpu] [-f keywordfile] [file ...]");
	  break;
	}
    }
  
    /* Set up appropriate set of keywords */ 
    if (file)
    install (file);
  
  else if (strcmp ("fglfmt", A4GL_getarg0 ()) == 0)
    
    {
      kw_table = fgl_tab;
      kw_size = fgl_size;
    }
  
  else
    
    {
      kw_table = sql_tab;
      kw_size = sql_size;
    }
  if (pflag)
    
    {
      for (i = 0; i < kw_size; i++)
	printf ("%s\n", kw_table[i]);
    }
  
  else
    
    {
      filter (argc, argv, optind, sqlfmt);
    }
  return (0);
}


