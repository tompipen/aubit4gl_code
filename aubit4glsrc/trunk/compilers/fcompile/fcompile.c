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
# $Id: fcompile.c,v 1.23 2003-01-28 15:17:46 mikeaubury Exp $
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

#include "a4gl_fcompile_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int as_c; /* defined in libaubit4gl */
//int as_c=1;

//#ifdef YYDEBUG
	extern int yydebug; /* defined in y.tab.c */
//#else /*  */
//	int yydebug;
//#endif /*  */

extern int 		yylineno;
extern long 	fileseek;
extern int 		yyleng;
extern char 	yytext[];
extern int 		chk4var;
extern int 		lcnt;
extern int 		lineno;
extern FILE *	yyin;
extern char *	outputfilename; /* defined in libaubit4gl */
extern struct 	struct_scr_field *fld; /* defined in libaubit4gl */
extern struct 	struct_form the_form;  /* defined in libaubit4gl */

char 			outputfile[132];
int 			ignorekw = 0;
int 			colno = 0;
int 			lineno = 0;
int 			openwith = 0;
char 			currftag[256];
int 			fldno;
int 			scr = 0;
int 			newscreen = 0;
int 			fstart;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *  From a file name takes the basename of the file (the file without extension)
 *
 *  @param str Origin file name
 *  @param str1 Pointer to the place where the base name is putted
 *  @param str2 Pointer to the place where the extension will be inserted
 */
/* this function is in libaubit4gl
static bname (char *str, char *str1, char *str2)
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
char c[128];
char d[128];

	setarg0(argv[0]);
	debug("Initializing fcompile\n");

	/* load settings from config file(s): */
	build_user_resources();



  strcpy (d, "");

  if (argc > 1)
    {
      	check_and_show_id("4GL Form Compiler",argv[1]);

      	outputfilename = outputfile;

      	if (strcmp(argv[1],"-c")==0)
		{
			as_c=1;
      		strcpy (c, argv[2]);
			if (argc > 3)
		    {
				strcpy (d, argv[3]);
            }
        }
		else
		{
			as_c=0;
      		strcpy (c, argv[1]);
			if (argc > 2)
		    {
				strcpy (d, argv[2]);
            }
		}


     	bname (c, a, b);

      	if (b[0] == 0)
		{
        strcat (c, ".per");
		}


	    if (strcmp(d,"")==0)  {
	      strcpy (outputfilename, a);
		}
	    else {
	      strcpy (outputfilename, d);
	    }

/* 	printf ("Output to %s \n", outputfilename); */

      	yyin = mja_fopen (c, "r");

    }

  else
    {

      printf ("Usage\n   %s [-c] filename[.per] [path/compiledform.ext]\n", argv[0]);

      exit (0);

    }

  yydebug = 0;

  if (yyin == 0)
    {

      printf ("Error opening file : %s\n", c);

      exit (0);

    }
  init_form();

  return (yyparse ());

}


/**
 * Executed by the parser when it enconters some error
 *
 * @param s String with error message sended by the parser
 */
void 
yyerror(char *s)
{
  char errfile[256];
  FILE *f;
  long ld;

  ld=buffpos();
  sprintf(errfile,"%s.err",outputfile);
  f=write_errfile(yyin,errfile,ld-1,yylineno);
  fprintf (f, "| %s", s);
  write_cont(yyin);
  printf("Error compiling %s.per - check %s.err (xline=%d yline=%d)\n",
	  outputfile,outputfile,lineno,yylineno
  );
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
  f = write_errfile (yyin, errfile, ld, yylineno);
  fprintf (f, "| %s%s (%s)", s, errbuff, yytext);
  write_cont (yyin);
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
yywrap(void)
{
  return 1;
}



int getdatatype_fcompile(char *col,char *tab) {
int a;
	a=getdatatype(col,tab);
	if (a==-1) {
		yyerror("Column/Table not found");
		return -1;
	}
	debug("%s.%s = %d\n",tab,col,a);
	return a;
}
/* ================================== EOF ============================= */


