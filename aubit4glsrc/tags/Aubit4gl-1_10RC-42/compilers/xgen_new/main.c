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
# $Id: main.c,v 1.1 2008-11-12 11:04:28 mikeaubury Exp $
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
// We dont want (or need) the a4gl_expr header - as this is used (indirectly) to generate it !!
#define IGNORE_XGEN_EXPR_HEADERS
#include "a4gl_xgen_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


extern int lineno;
extern int colno;
extern int yydebug;

extern FILE *yyin;
char outputfile[132];
char *outputfilename;

char ofile[134];
char hfile[134];
char hsfile[134];
char ccrfile[134];

/*
extern FILE *cfo;
extern FILE *cfio;
extern FILE *cfi;
extern FILE *hf;
extern FILE *hsf;
extern FILE *ccrf;
extern FILE *Dtd;
extern FILE *Act;
extern FILE *ActH;
*/
char export_name[128];


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void write_genout (void);
int yywrap (void);
void yyerror (char *s);

extern int yyparse (void);	/* in y.tab.c */

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * FIXME: we should ling xgen with libaubit4gl.so and use A4GL_bname that is defined there
 * @todo Describe function
 */
/* static */
void
A4GL_bname (char *str, char *str1, char *str2)
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


/**
 *
 * @todo Describe function
 */
void
yyerror (char *s)
{

  printf ("Error compiling %s.x (xline=%d yline=%d)\n",
	  outputfile, lineno, lineno);
  exit (2);
}

/**
 *
 * @todo Describe function
 */
int
main (int argc, char *argv[])
{
  char a[128]="";
  char b[128]="";
  char c[128]="";
  char d[128]="";
  int rval;

  /* load settings from config file(s): */

  
  yydebug = 0;

  strcpy (d, "");

  if (argc > 1)
    {
      outputfilename = outputfile;

      strcpy (c, argv[1]);

      if (argc > 2)
	{
	  strcpy (export_name, argv[2]);
	}
      else
	{
	  strcpy (export_name, argv[1]);
	}


      A4GL_bname (c, a, b);

      if (b[0] == 0)
	{
	  strcat (c, ".x");
	}


      strcpy (outputfilename, a);

      yyin = (FILE *) fopen (c, "r");


/*
      strcpy (ofile, outputfilename);
      strcat (ofile, ".xo.c");


      cfo = (FILE *) fopen (ofile, "w");
      if (cfo == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}

      strcpy (ofile, outputfilename);
      strcat (ofile, ".dtd");
      Dtd = (FILE *) fopen (ofile, "w");
      if (Dtd == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}

      strcpy (ofile, outputfilename);
      strcat (ofile, ".act");
      Act = (FILE *) fopen (ofile, "w");
      if (Act == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}

      strcpy (ofile, outputfilename);
      strcat (ofile, ".act.h");
      ActH = (FILE *) fopen (ofile, "w");
      if (ActH == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}


      strcpy (ofile, outputfilename);
      strcat (ofile, ".xi.c");
      cfi = (FILE *) fopen (ofile, "w");
      if (cfi == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}


      strcpy (ofile, outputfilename);
      strcat (ofile, ".xio.c");
      cfio = (FILE *) fopen (ofile, "w");
      if (cfi == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}

      strcpy (hfile, outputfilename);
      strcat (hfile, ".x.h");
      hf = (FILE *) fopen (hfile, "w");
      if (hf == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}

      strcpy (hsfile, outputfilename);
      strcat (hsfile, ".xs.h");
      hsf = (FILE *) fopen (hsfile, "w");
      if (hsf == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}


      strcpy (ccrfile, outputfilename);
      strcat (ccrfile, ".xs.h");
*/

      /* ccrf = (FILE *) fopen (ccrfile, "w"); 
      if (ccrf == 0)
	{
	  printf ("Unable to open output file\n");
	  exit (1);
	}
	*/
    }

  else
    {

      printf ("Usage\n   %s filename [export_name]\n", argv[0]);

      exit (0);

    }

  if (yyin == 0)
    {

      printf ("Error opening file : %s\n", c);

      exit (0);

    }


  rval = yyparse ();
  dump_structs(outputfilename);

/*
  fclose (cfo);
  fclose (cfi);
  fclose (hf);
  fclose (hsf);
  fclose(Dtd);
  fclose(Act);
*/

  return 0;
}




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
write_genout (void)
{
}


/*this function in normally in libaubit4gl, but xgen is not linked with it: */

#ifdef YYPRINT
  /* Give the individual parser a way to print the precise meaning
     of a token, for further debugging info.  */

/*YYPRINT (stderr, yychar, yylval) */
int
aubit_yyprint (int xstderr, int xyychar, int xyylval)
{

  /*do your output here */
  return 0;

}
#endif


char *
acl_strdup_full (void *a, char *r, char *f, int l)
{
  char *p;
  p = strdup (a);
  if (p == 0)
    {
      printf ("Unable to allocate memory\n");
      exit (1);
    }
  return p;
}

char *get_mod_name(void) {
	return export_name;
}

/* ================================= EOF ============================= */
