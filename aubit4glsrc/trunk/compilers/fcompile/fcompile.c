
/**
 * @file
 * Main module from the form compiler.
 *
 * The form compiler parses a .per file and generates a .frm (compiled form)
 *
 * The frm is the file used at run-time by x4gl
 */

 /* 
  * $Id: fcompile.c,v 1.12 2002-04-24 07:45:59 afalout Exp $
  */

#include "a4gl_compiler.h"
#include <stdio.h>
#include "a4gl_aubit_lib.h"
extern int as_c;
#ifdef YYDEBUG
extern int yydebug;


#else /*  */
int yydebug;

#endif /*  */

extern int yylineno;
extern long fileseek;

extern int yyleng;

extern char yytext[];

extern int chk4var;

extern int lcnt;
extern int lineno;
extern FILE *yyin;


char *outputfilename;

char outputfile[132];



/**
 *  From a file name takes the basename of the file (the file without extension)
 *
 *  @param str Origin file name
 *  @param str1 Pointer to the place where the base name is putted
 *  @param str2 Pointer to the place where the extension will be inserted
 */
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

/**
 * The main entry point to the form compiler
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int main (int argc, char *argv[])
{
  char a[128];
  char b[128];
  char c[128];
  char d[128];
  FILE *fopn;

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

//		printf ("Output to %s \n", outputfilename);

      	yyin = mja_fopen (c, "r");

    }

  else
    {

      printf ("Usage\n   %s [-c] filename[.per] [path/compiledform.ext]\n", argv[0]);

      exit (0);

    }

  yydebug = 1;

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
void yyerror(char *s)
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


/**
 *  Executed when the parser arrives the end of parsing 
 *
 *  @return 
 */
int yywrap(void)
{
  return 1;
}


