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
# $Id: 4glc.c,v 1.24 2002-05-14 09:27:27 afalout Exp $
#
*/

/**
 * @file
 * The main module for the 4gl compiler.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "a4gl_aubit_lib.h"
#include "a4gl_pointers.h"


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

#ifdef YYDEBUG
	extern int yydebug;
#else
	int yydebug;
#endif
extern FILE *ferr;
extern int yylineno;
extern int yyleng;
char yytext[] = "";
extern int chk4var;
extern int lcnt;
extern FILE *yyin;
int yyin_len;
extern int glob_only;
char *outputfilename;
static char outputfile[132]; /** The output file name */
extern char infilename[132];
char errbuff[1024] = "";
int globals_only = 0;

/**
 * Flag that identifies if the compiler should generate function call stack
 * actualization.
 */
static int genStackInfo = 1;

extern long fpos; /** The current file position for direct fseek */

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void setGenStackInfo(int _genStackInfo);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Breaks the file name to take the file name without extension and dir name
 *
 * Its used to separate column names from tablename too.
 *
 * @param str The file name
 * @param str1 A pointer to the place where to return the left part.
 * @param str2 A pointer to the place where to return the right part.
 */
static void
bname (char *str, char *str1, char *str2)
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
 * Print the usage message when executing the 4gl compiler.
 */
static void 
printUsage(char *argv[])
{
  printf("Usage %s [options] filename[.4gl]\n", argv[0]);
  printf("Options:\n");
  printf("  -G     | --globals         : Generate the globals map file\n");
  printf("  -s 0|1 | --stack_trace 0|1 : ");
  printf("Instruct the stack trace inclusion in file:\n");
  printf("     0 - No generate\n");
  printf("     1 - Generate(Default)\n");
}


/**
 * Parse the comand line arguments and acording to the passed values
 * set(s) the properties.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
static void 
initArguments(int argc, char *argv[])
{
  int i;
  extern char *optarg;
  int this_option_optind = optind ? optind : 1;
  int option_index = 0;
  int si;
  char a[128];
  char b[128];
  char c[128];
  static struct option long_options[] =
  {
    {"globals",     0, 0, 'G'},
    {"stack_trace", 1, 0, 's'},
    {"help", 0, 0, '?'},
    {0, 0, 0, 0},
  };

  while ( ( i = getopt_long (argc, argv, "Gs:?h",
                        long_options, &option_index) ) != -1)
  {
    switch(i)
    {
      case 'G':              /* Global generate only */
        globals_only = 1;
        break;

      case 's':              /* Stack information inclusion */
	si = atoi(optarg);
        if ( si != 0 && si != 1 )
	{
	  printUsage(argv);
	  exit(1);
	}
        setGenStackInfo(si);
        break;

      case '?':
      case 'h':
	printUsage(argv);
        exit(0);
    }
  }

  if ( optind >= argc )
  {
    printf("No file name defined\n");
    printUsage(argv);
    exit(1);
  }
  check_and_show_id ("4GL Compiler", argv[optind]);
  outputfilename = outputfile;
  if (strcmp (acl_getenv ("YYDEBUG"), "") != 0)
  {
    printf ("Yacc Debugging on\n");
    yydebug = 1;
  }
  
  strcpy (c, argv[optind]);
  bname (c, a, b);
  if (b[0] == 0)
  {
    strcat (c, ".4gl");
  }
  bname (c, a, b);
  strcpy (outputfilename, a);
  yyin = fopen (c, "r");
 
  strcpy (infilename, c);
}


/**
 * The main entry point function of 4glc compiler.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int
main(int argc, char *argv[])
{
  char a[128];
  char b[128];
  char c[128];
  int x;
  FILE *fopn;
  int fname_arg_no = 1;

  /** @todo : Remove things that are to use */
  int useGetopt = 1;
  init_states ();

  yydebug = 0;

  //load settings from config file(s):
  build_user_resources();


  if ( useGetopt )
    initArguments(argc,argv);
  else             /** @todo : Remove this code when it works OK */
  {
    if (argc > 1)
    {
      if (strcmp (argv[1], "-G") == 0)
      {
        globals_only = 1;
        fname_arg_no = 2;
      }
  
      check_and_show_id ("4GL Compiler", argv[fname_arg_no]);
  
      outputfilename = outputfile;
  
      if (strcmp (acl_getenv ("YYDEBUG"), "") != 0)
      {
        printf ("Yacc Debugging on\n");
        yydebug = 1;
      }
  
      strcpy (c, argv[fname_arg_no]);
      bname (c, a, b);
      if (b[0] == 0)
      {
        strcat (c, ".4gl");
      }
      bname (c, a, b);
      strcpy (outputfilename, a);
      yyin = fopen (c, "r");
  
      strcpy (infilename, c);
    }
    else
    {
      printf ("Usage %s [-G] filename[.4gl]\n", argv[0]);
      exit (1);
    }
  }

  if (yyin == 0)
  {
    printf ("Error opening file : %s\n", infilename);
    exit (1);
  }

  fseek(yyin,0,SEEK_END);
  yyin_len=ftell(yyin);
  rewind(yyin);

  if (yydebug)
    {
      printf ("Opened : %s\n", c);
    }

  openmap(outputfilename);
  if (!A4GLSQL_initlib()) {
	printf("4glc: Error opening SQL Library - check A4GL_SQLTYPE is set correctly (A4GL_SQLTYPE=%s)\n", acl_getenv("A4GL_SQLTYPE"));
//    printf ("A4GL_SQLTYPE=%s\n", acl_getenv("A4GL_SQLTYPE"));
	exit(1);
  }
  x = yyparse ();


  if (yydebug)
    {
      printf ("Closing map : %s\n", x);
    }

  closemap ();
  
  if (yydebug)
    {
      printf ("Exit\n");
    }


  exit (x);
}

/**
 * Remove the quotes in the beginning and at the from a quoted string
 *
 * @param s The string to be unquoted
 */
void 
rm_quote (char *s)
{
  char buff[256];
  int a;
  int b = 0;
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] != '"')
	{
	  buff[b++] = s[a];
	}
    }
  for (a = strlen (buff) - 1; a >= 0; a--)
    {
      if (buff[a] == '.')
	{
	  buff[a] = 0;
	  break;
	}
    }
  strcpy (s, buff);
}

/**
 * Read and parse the globals file (if found).
 *
 * @param fname The globals file name
 */
int 
read_globals (char *fname)
{
  char a[128];
  char b[128];
  char c[128];
  FILE *fopn;
  char ofname[256];
  FILE *fin;
  fin = yyin;

  glob_only = 1;
  rm_quote (fname);
//printf("Opening %s",fname);
  yyin = mja_fopen (fname, "r");

  if (yyin == 0)
    {
      printf ("Error opening globals file : %s\n", fname);
      return -1;
    }
//printf("/***********************************************************/\n");
  lex_printc ("/***********************************************************/\n");
  return (yyparse ());
//printf("/***********************************************************/\n");
  lex_printc ("/***********************************************************/\n");
  glob_only = 0;
  yyin = fin;
  return 0;
}

/**
 * Remove the quotes from a quoted string.
 *
 * @param s The string to be unquoted
 */
void
rm_quotes (char *s)
{
  char buff[256];
  int a;
  int b = 0;
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] != '"')
	{
	  buff[b++] = s[a];
	}
    }
  strcpy (s, buff);
}

/**
 * Treatment of an error ocurred in the parsing.
 *
 * It makes the proper treatment of an syntax error ocurred during the parsing
 *
 * @param s The string that contains the error
 */
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

/**
 *  Adds the parameters to the error buffer in the assigned with yyerror.
 *
 *  The purpose is to using sprintf with fixed number of parameters.
 *  I Think that this only exists until we start using varargs.
 *
 * @param s The first parameter
 * @param p The second parameter
 * @param q The tird parameter
 */
void 
adderr (char *s, char *p, char *q)
{
  sprintf (errbuff, s, p, q);
}


/**
 * Inform if we are just parsing the globals
 *
 * @return 
 *   - 1 : if we are just doing globals
 *   - 0 : otherwise
 */
int 
only_doing_globals (void)
{
  if (globals_only)
    return 1;
  return 0;
}

/**
 * Assign a value into the global flag that indicate if the compiler should
 * generate function call stack information.
 *
 * @param _genStackInfo The vlaue to assign to the flag
 */
void
setGenStackInfo(int _genStackInfo)
{
  genStackInfo = _genStackInfo;
}

/**
 * Check the value of the global flag that indicate if the compiler should
 * generate function call stack information.
 *
 * @param _genStackInfo The vlaue to assign to the flag
 */
int 
isGenStackInfo(void)
{
  return genStackInfo;
}

// ============================== EOF ===============================

