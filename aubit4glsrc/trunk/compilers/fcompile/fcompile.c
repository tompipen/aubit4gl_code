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
# $Id: fcompile.c,v 1.40 2005-01-05 20:02:04 mikeaubury Exp $
#*/

/**
 * @file
 * Main module from the form compiler.
 *
 * The form compiler parses a .per file and generates a compiled form
 *
 * The frm is the file used at run-time by x4gl
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/
#define yyparse a4gl_form_yyparse
#include "a4gl_fcompile_int.h"
#define DO_DEBUG
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int as_c;		/* defined in libaubit4gl */
//int as_c=1;

//#ifdef YYDEBUG
extern int a4gl_form_yydebug;	/* defined in y.tab.c */
//#else /*  */
//      int yydebug;
//#endif /*  */

extern int yylineno;
extern long fileseek;
extern int yyleng;
extern char yytext[];
extern int chk4var;
extern int lcnt;
extern int lineno;
extern FILE *yyin;
extern char *outputfilename;	/* defined in libaubit4gl */
extern struct struct_scr_field *fld;	/* defined in libaubit4gl */
extern struct struct_form the_form;	/* defined in libaubit4gl */

char outputfile[132];
int ignorekw = 0;
int colno = 0;
int lineno = 0;
int openwith = 0;
char currftag[256];
int fldno;
int scr = 0;
int newscreen = 0;
int fstart;
char *default_database = 0;
//int A4GLF_open_db (char *s);
void usage (char *s);
void a4gl_form_yyerror (char *s);
char *rm_dup_quotes(char *s) ;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/
int fcompile=0;


/**
 * The main entry point to the form compiler
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int
main (int argc, char *argv[])
{
  char a[128];
  char b[128];
  char c[128] = "";
  char d[128] = "";
  int cnt;
  int cnt_files = 0;

  A4GL_setarg0 (argv[0]);

  if (argc == 1)
    {
      usage (argv[0]);
    }

  A4GL_debug ("Initializing fcompile\n");
  A4GL_setenv("A4GL_UI","CONSOLE");
  A4GL_fgl_start(argc,argv);
  fcompile=0;
  if (strstr(argv[0],"fcompile"))  fcompile=1;


  /* load settings from config file(s): */
  //A4GL_build_user_resources ();
  strcpy (d, "");

  as_c = 0;

  for (cnt = 1; cnt < argc; cnt++)
    {

      if (strcmp (argv[cnt], "-v") == 0)
	{
	  A4GL_check_and_show_id ("4GL Form Compiler", argv[cnt]);
	  continue;
	}

      if (strcmp (argv[cnt], "-vfull") == 0)
	{
	  A4GL_check_and_show_id ("4GL Form Compiler", argv[cnt]);
	  continue;
	}

      if (strcmp (argv[cnt], "-c") == 0)
      // compile to C, not to compiled form format
	{
	  as_c = 1;
	  continue;
	}

      if (strcmp (argv[cnt], "-d") == 0)
      // secify database name to be used while compiling form
	{
	  cnt++;
	  default_database = strdup (argv[cnt]);
	  continue;
	}

      if (cnt_files == 0)
	{
	  strcpy (c, argv[cnt]);
	  cnt_files++;
	  continue;
	}

      if (cnt_files == 1)
	{
	  strcpy (d, argv[cnt]);
	  cnt_files++;
	  continue;
	}

    }

  if (strlen (c) == 0)
    {
      usage (argv[0]);
    }


  A4GL_bname (c, a, b);

  
  //does not work - attempting to compile form without specifying .per extension will fail:
  if (a[0] == 0)
    {
      strcat (c, ".per");
  	A4GL_bname (c, a, b);
    }


  if (strcmp (d, "") == 0)
    {
      outputfilename = strdup (a);
    }
  else
    {
      outputfilename = strdup (d);
    }



  yyin = A4GL_mja_fopen (c, "r");


  a4gl_form_yydebug = 0;

  if (yyin == 0)
    {

      printf ("Error opening file : %s\n", c);
      exit (1);

    }
  A4GL_init_form ();

  return (a4gl_form_yyparse ());

}

#ifdef DO_DEBUG
typedef union
{
  char str[1024];
  u_expression *expr;
}
YYSTYPE;

YYSTYPE yylval;

#endif
/**
 * Executed by the parser when it enconters some error
 *
 * @param s String with error message sended by the parser
 */
void
a4gl_form_yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;

  ld = buffpos ();
  sprintf (errfile, "%s.err", outputfilename);
  f = A4GL_write_errfile (yyin, errfile, ld - 1, yylineno);
  fprintf (f, "| %s", s);
  A4GL_write_cont (yyin);
  printf ("Error compiling %s.per - check %s.err (xline=%d yline=%d)\n",
	  outputfilename, outputfilename, lineno, yylineno);
#ifdef DO_DEBUG
  printf ("%s\n", yylval.str);
#endif
  exit (2);
}

/********************************** same finction from 4glc.c :

void
yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;
  char a;

  ld = ftell (yyin);
  sprintf (errfile, "%s.err", outputfile);
  a = 0;
  fseek (yyin, fpos, SEEK_SET);
  f = A4GL_write_errfile (yyin, errfile, ld, yylineno);
  fprintf (f, "| %s%s (%s)", s, errbuff, yytext);
  A4GL_write_cont (yyin);
  printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
  exit (2);
}

*********************************************************************/


/**
 *  Executed when the parser arrives the end of parsing 
 *
 *  @return 
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
int
A4GLF_getdatatype_fcompile (char *col, char *tab)
{
  int a;
  a = A4GL_getdatatype (col, tab);
  if (a == -1)
    {
      a4gl_form_yyerror ("Column/Table not found");
      return -1;
    }
  A4GL_debug ("%s.%s = %d\n", tab, col, a);
	if (a==DTYPE_VCHAR) a=DTYPE_CHAR;
  return a;
}

/**
 *
 * @todo Describe function
 */
void
usage (char *s)
{
  printf ("Usage\n   %s [-c] filename[.per] [path/compiledform.ext]\n", s);
  exit (0);
}

/**
 *
 * @todo Describe function
 */
int
A4GLF_open_db (char *s)
{
  if (default_database == 0)
    {
      return A4GLSQL_init_connection (s);
    }
  else
    {
      return A4GLSQL_init_connection (default_database);
    }
}


char *rm_dup_quotes(char *s) {
char *x;
int a;
int c;
x=strdup(s);
c=0;
for (a=0;a<strlen(s);a++) {
	if (s[a]=='"'&&s[a+1]=='"') continue;
	x[c++]=s[a];
}
x[c]=0;
return x;
}

int doing_4gl() {
	if (A4GL_isyes(acl_getenv("FGLFRMCOMPILE"))) return 1;
	if (A4GL_isno(acl_getenv("FGLFRMCOMPILE"))) return 0;
	if (fcompile) return 1;
	return 0;
}
/* ================================== EOF ============================= */
