/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: main.c,v 1.4 2002-07-09 10:07:12 mikeaubury Exp $
#*/

/**
 * @file
 *
 *
 *
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#ifdef OLD_INCL

	#include <stdio.h>
	#include "report.h"

#else

    #include "a4gl_ace_int.h"

#endif

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern FILE *yyin;
char outputfile[132];
int lineno;
int colno;
int ignorekw = 0;
char *outputfilename;
#ifdef YYDEBUG
        extern int yydebug;
#else /*  */
        int yydebug;
#endif /*  */





int yywrap (void);



/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
int
yywrap (void)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
void
yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;

  ld = buffpos ();
  sprintf (errfile, "%s.err", outputfile);
  f = (FILE *)write_errfile (yyin, errfile, ld - 1, lineno);
  fprintf (f, "| %s", s);
  write_cont (yyin);
  printf ("Error compiling %s.ace - check %s.err (xline=%d yline=%d)\n",
	  outputfile, outputfile, lineno, lineno);
  exit (2);
}

/**
 *
 * @todo Describe function
 */
/*
static void
ace_bname (char *str, char *str1, char *str2)
{
  char fn[132];
  int a;
  char *ptr;
  strcpy (fn, str);

  for (a = strlen (fn); a >= 0; a--)
    {
      if (fn[a] == '.')
        {
          fn[a] = 0;
          break;
        }
    }
  ptr = &fn[a];
  strcpy (str1, fn);
  if (a >= 0)
        strcpy (str2, ptr + 1);
  else
    str2[0] = 0;
}
*/

/**
 *
 * @todo Describe function
 */
int
main (int argc, char *argv[])
{
char a[128];
char b[128];
char c[128];
char d[128];
int rval;

  /* load settings from config file(s): */
  build_user_resources ();

  yydebug=1;
  strcpy (d, "");

  if (argc > 1)
    {
     check_and_show_id ("4GL ACE Compiler", argv[1]);

     outputfilename = outputfile;

     strcpy (c, argv[1]);


     bname (c, a, b);

      if (b[0] == 0)
	{
	  strcat (c, ".ace");
	}


	strcpy(outputfilename,a);
	/* strcat(outputfilename,".aarc"); */


      yyin = (FILE *)mja_fopen (c, "r");

    }

  else
    {

      printf ("Usage\n   %s filename\n", argv[0]);

      exit (0);

    }

  yydebug = 1;

  if (yyin == 0)
    {

      printf ("Error opening file : %s\n", c);

      exit (0);

    }

  init_report();
  rval=yyparse ();
  if (rval==0) {
	write_report();
  	//close_database();
  	exit(0);
} else {
	exit(2);
}

    return 0;

}



/* ================================= EOF =========================== */

