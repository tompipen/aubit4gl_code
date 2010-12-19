   /* $Id: fcompile.c,v 1.1.1.1 2001-08-20 02:35:50 afalout Exp $
   /* */

#include "../../lib/libincl/compiler.h"
#include <stdio.h>
extern int as_c;
#ifdef YYDEBUG
extern int yydebug;
FILE *write_errfile(FILE *f,char *s,long p,int l);


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

  FILE *fopn;

  if (argc > 1)
    {
      check_and_show_id("4GL Form Compiler",argv[1]);

      outputfilename = outputfile;

      if (strcmp(argv[1],"-c")==0)  {
		as_c=1;
      		strcpy (c, argv[2]);
	}
	else  {
		as_c=0;
      		strcpy (c, argv[1]);
	}


      bname (c, a, b);


      if (b[0] == 0)
	{

	  strcat (c, ".per");

	}


      bname (c, a, b);

      strcpy (outputfilename, a);
 
      yyin = mja_fopen (c, "r");

    }

  else
    {

      printf ("Usage\n   %s filename[.per]\n", argv[0]);

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


yyerror (s)
     char *s;
{
char errfile[256];
FILE *f;
long ld;

  ld=buffpos();
  sprintf(errfile,"%s.err",outputfile);
  f=write_errfile(yyin,errfile,ld-1,yylineno);
  fprintf (f, "| %s", s);
  write_cont(yyin);
  printf("Error compiling %s.per - check %s.err (%d %d)\n",outputfile,outputfile,lineno,yylineno);
  exit (2);
}


yywrap(){
return 1;
}


