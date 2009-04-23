/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: fileio.c,v 1.15 2009-02-12 12:36:15 mikeaubury Exp $
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

#include "a4gl_ace_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern FILE *yyin;
extern char *outputfilename;	/* defined in libaubit4gl */
/*#ifdef YYDEBUG*/
extern int a4gl_ace_yydebug;	/* defined in y.tab.c */
/*#else */
/*int yydebug;*/
/*#endif */

char outputfile[256]="";
int lineno;
int colno;
int ignorekw = 0;
int yywrap (void);
int a4gl_ace_yyparse (void);

extern char*yytext;
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
a4gl_ace_yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;

  ld = buffpos ();
  sprintf (errfile, "%s.err", outputfile);
  f = (FILE *) A4GL_write_errfile (yyin, errfile, ld - 1, lineno);
  fprintf (f, "| %s (%s)", s,yytext);
  A4GL_write_cont (yyin);
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
compile_ace_report (char *filename)
{
  char a[128];
  char b[128];
  char c[128];
  char d[128];
  int rval;

  /* load settings from config file(s): */
  A4GL_build_user_resources ();

  a4gl_ace_yydebug = 0;
  strcpy (d, "");

  A4GL_check_and_show_id ("4GL ACE Compiler", filename);

  outputfilename = outputfile;

  strcpy (c, filename);

  A4GL_bname (c, a, b);
  yyin=0;

  if (!strchr(c,'.'))
    {
	char buff[2000];
	strcpy(buff,c);
      	strcat (buff, ".aace");
  	yyin = (FILE *) A4GL_mja_fopen (buff, "r");
	if (yyin==0)  {
		strcpy(buff,c);
      		strcat (buff, ".ace");
  		yyin = (FILE *) A4GL_mja_fopen (buff, "r");
	}
  	strcpy (outputfilename, c);

    }


  a4gl_ace_yydebug = 0;
  /* strcat(outputfilename,".aarc"); */

  if (yyin==0) {
  	yyin = (FILE *) A4GL_mja_fopen (c, "r");
  	strcpy (outputfilename, a);
  }




  if (yyin == 0)
    {

      fprintf (stderr,"Error opening file : %s\n", c);
      return 2;
    }

  init_report ();
  rval = a4gl_ace_yyparse ();

  if (rval == 0)
    {
      check_sql_columns ();
      A4GL_write_report ();
      return 0;
    }
  else
    {
      return 2;
    }

  return 2;
}



/* ================================= EOF =========================== */
