/**************************************************************/
/*
/* $Id: 4glc.c,v 1.5 2001-10-23 09:23:18 afalout Exp $
/**/
//#include "../libincl/compiler.h"
#include <stdio.h>
#ifdef YYDEBUG
extern int yydebug;
#else
int yydebug;
#endif
extern FILE *ferr;
extern int yylineno;
extern int yyleng;
char yytext[] = "";
FILE *write_errfile (FILE *, char *, int, int);
extern int chk4var;
extern int lcnt;
extern FILE *yyin;
extern int glob_only;
char *outputfilename;
char outputfile[132];
extern char infilename[132];
char errbuff[1024] = "";
FILE *mja_fopen (char *, char *);
#include "../../lib/libincl/pointers.h"

int globals_only=0;

int lineno = 1;

static
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


main (argc, argv)
     int argc;
     char *argv[];
{
  char a[128];
  char b[128];
  char c[128];
  int x;
  FILE *fopn;
  int fname_arg_no=1;
  init_states ();

  yydebug=0;

  if (argc > 1)
    {

      if (strcmp(argv[1],"-G")==0) {
		globals_only=1;
		fname_arg_no=2;
      }

      check_and_show_id ("4GL Compiler", argv[fname_arg_no]);

      outputfilename = outputfile;

      if (strcmp(acl_getenv ("YYDEBUG"),"")!=0)
	{
	  printf ("Yacc Debugging on\n");
	  yydebug = 1;
	}
      else
	{
	  //printf ("Yacc debugging off\n");
	  yydebug = 0;
	}

      strcpy (c, argv[fname_arg_no]);
      bname (c, a, b);
//printf("Split it\n");
      if (b[0] == 0)
	{
	  strcat (c, ".4gl");
	}
//printf("Split it again\n");
      bname (c, a, b);
//printf("gen fname\n");
//printf("c=%s b=%s a='%s'\n",c,b,a);
      strcpy (outputfilename, a);
//printf("Output to %s\n",outputfilename);
//printf("outputfilename = %s\n",outputfilename);
//printf("Got input : %s\n",c);
      yyin = fopen (c, "r");

      strcpy (infilename, c);
    }
  else
    {
      printf ("Usage %s filename[.4gl]\n", argv[0]);
      exit (1);
    }
  if (yyin == 0)
    {
      printf ("Error opening file : %s\n", c);
      exit (1);
    }

	if (yydebug) {
		printf("Opened : %s\n",c);
    }

  x = yyparse ();

	if (yydebug) {
		printf("Closing map : %s\n",x);
    }

  closemap ();

	if (yydebug) {
		printf("Exit\n");
    }


  exit (x);
}


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
  printc ("/***********************************************************/\n");
  return (yyparse ());
//printf("/***********************************************************/\n");
  printc ("/***********************************************************/\n");
  glob_only = 0;
  yyin = fin;
  return 0;
}

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

extern long fpos;
yyerror (s)
     char *s;
{
  char errfile[256];
  FILE *f;
  long ld;
  char a;

  ld = ftell (yyin);
  sprintf (errfile, "%s.err", outputfile);
  a = 0;
  fseek (yyin, fpos, SEEK_SET);
  //while (1) {
  //a=fgetc(yyin);
  //if (feof(yyin)) break;
  //if (a=='\n') break;
  //}

  //ld=ftell(yyin);
  f = write_errfile (yyin, errfile, ld, yylineno);
  fprintf (f, "| %s%s (%s)", s, errbuff, yytext);
  write_cont (yyin);
  printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
  exit (2);
}

adderr (s, p, q)
     char *s;
     char *p;
     char *q;
{
  sprintf (errbuff, s, p, q);
}


only_doing_globals() {
	if (globals_only) return 1;
	return 0;
}
