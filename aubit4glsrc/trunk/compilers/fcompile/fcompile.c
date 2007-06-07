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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: fcompile.c,v 1.57 2007-06-07 11:15:29 mikeaubury Exp $
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

int silent=0;
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
int opened_db=0;
void usage (char *s);
void a4gl_form_yyerror (char *s);
char *rm_dup_quotes(char *s) ;
void bye(void ) ;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/
int fcompile=0;



void bye(void ) {
  if (opened_db) {
        A4GL_close_database();
  }
}


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
  int waserr;
  char errfile[513];
  char d[128] = "";
  int cnt;
  int cnt_files = 0;

  A4GL_setarg0 (argv[0]);

  if (argc == 1)
    {
      usage (argv[0]);
    }

  A4GL_debug ("Initializing fcompile\n");
  A4GL_setenv("A4GL_UI","CONSOLE",1);
  A4GL_fgl_start(argc,argv);
  default_database=acl_getenv_not_set_as_0("DEFAULT_DATABASE");
  fcompile=0;
  if (strstr(argv[0],"fcompile"))  fcompile=1;


  /* load settings from config file(s): */
  //A4GL_build_user_resources ();
  strcpy (d, "");

  as_c = 0;
  if (A4GL_isyes(acl_getenv("FCOMPILE_SILENT"))) {
	  silent=1;
  }

  for (cnt = 1; cnt < argc; cnt++)
    {


      if (strcmp(argv[cnt],"-q")==0) {
	      	silent=1;
		continue;
      }
      if (strcmp(argv[cnt],"-s")==0) {
	      	silent=1;
		continue;
      }
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
	  default_database = acl_strdup (argv[cnt]);
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
      outputfilename = acl_strdup (a);
    }
  else
    {
      outputfilename = acl_strdup (d);
    }


  if (!silent) {
  	A4GL_check_and_show_id ("4GL Form Compiler", "");
	printf("\nThe form '%s' will now be compiled\n\n\n",c);
  }


  yyin = A4GL_mja_fopen (c, "r");

  if (A4GL_isyes(acl_getenv("A4GL_YYDEBUG")) ){
  	a4gl_form_yydebug = 1;
  } else {
  	a4gl_form_yydebug = 0;
  }

  if (yyin == 0)
    {

      printf ("Error opening file : %s\n", c);
      exit (1);

    }
  A4GL_init_form ();

  atexit(bye);

  sprintf (errfile, "%s.err", outputfilename);
  A4GL_delete_file(errfile);
  A4GL_delete_compiled_form_file();

  waserr=a4gl_form_yyparse ();

  if (!silent) {
  	if (waserr) {
		  printf("    The form compilation was ** not ** successful.\nPlease look at the relevant .err file\n\n");
	  } else {
		  printf("    The form compilation was successful.\n\n");
	}
  }

  return waserr;
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
  ld = ftell(yyin); //buffpos ();
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


void clr_status(void) {
  A4GL_set_fcompile_err("");
  A4GL_set_a4gl_status(0);
}


void err_on_status(void) {
  if (A4GL_get_a4gl_status()!=0) {
      	a4gl_form_yyerror (A4GL_get_fcompile_err());
	
  }
                
}

/**
 *
 * @todo Describe function
 */
int
A4GLF_getdatatype_fcompile (char *col, char *tab)
{
  int a;
  A4GL_set_a4gl_status(0);
  a = A4GL_getdatatype (col, tab);

	err_on_status();
if (a==-1) {
      	a4gl_form_yyerror (A4GL_get_fcompile_err());
}


  A4GL_debug ("DATATYPE : %s.%s = %d (%x)\n", tab, col, a,a);

  if (a==DTYPE_VCHAR) a=DTYPE_CHAR;
  
  return a&0xffff;
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

  opened_db=1;
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
x=acl_strdup(s);
c=0;
for (a=0;a<strlen(s);a++) {
	if (s[a]=='"'&&s[a+1]=='"') continue;
	x[c++]=s[a];
}
x[c]=0;
return x;
}

int doing_4gl(void) {
	if (A4GL_isyes(acl_getenv("FGLFRMCOMPILE"))) return 1;
	if (A4GL_isno(acl_getenv("FGLFRMCOMPILE"))) return 0;
	if (fcompile) return 1;
	return 0;
}

int A4GL_check_compiled_form() {
int a;
int found;
int b;

if (strcmp(the_form.dbname,"formonly")!=0) {
	if (the_form.tables.tables_len==0) {
		fprintf(stderr,"Warning: DATABASE defined - but no tables used\n");
	}
}


  // Check that all field tags actually relate to things in the
  // attribute section 
  //
  for (a = 0; a < the_form.fields.fields_len; a++)
    {
	found=0;
	if (strcmp(the_form.fields.fields_val[a].tag,"_label")==0) {
	continue;
	}
	for (b=0;b<the_form.attributes.attributes_len;b++) {
		if (the_form.attributes.attributes_val[b].field_no==a) {
		found++;
		break;
		}
	}
	if (!found) {
		char buff[256];
		sprintf(buff, "Tag '%s' has not been used", the_form.fields.fields_val[a].tag);
		a4gl_form_yyerror(buff);
		return 0;
        }
    }


return 1;

}

/* ================================== EOF ============================= */
