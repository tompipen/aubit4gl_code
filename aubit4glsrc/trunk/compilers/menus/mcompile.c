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
# $Id: mcompile.c,v 1.8 2002-05-26 06:26:49 afalout Exp $
#*/

/**
 * @file
 * GUI mode menu definition compiler main entry.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>

#include "a4gl_compiler.h"
#include "a4gl_menuxw.h"
#include "a4gl_aubit_lib.h"

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


FILE *	mja_fopen		(char *name, char *mode);
FILE *	write_errfile	(FILE *f,char *s,long p,int l);
void    init_menu		(void);

// in lex.yy.c
extern int buffpos		(void);
//#define yyparse fgl_comp_parse
extern int 	yyparse		(void);

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define MAXMENUS 256

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

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
int ignorekw = 0;
int colno = 0;
int as_c=1;
int lineno = 0;
char *outputfilename;
char outputfile[132];
extern struct menu_list the_menus;
void *stackmenus[1000];
int menu_cnt=0;


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
 * This function is repeated in severall places.
 * @todo : Use only one function.
 *
 * @param str The file name 
 * @param str1 A pointer to the place where to return the left part.
 * @param str2 A pointer to the place where to return the right part.
 */
/* now in libaubit4gl
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
*/


/**
 *
 * @todo Describe function
 */
int
main (argc, argv)
     int argc;
     char *argv[];

	 {
  char a[128];
  char b[128];
  char c[128];
//  FILE *fopn;

	//load settings from config file(s):
	build_user_resources();

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

	  strcat (c, ".menu");

	}


      bname (c, a, b);

      strcpy (outputfilename, a);
 
      yyin = mja_fopen (c, "r");

    }

  else
    {

      printf ("Usage\n   %s filename[.menu]\n", argv[0]);

      exit (0);

    }

  yydebug = 1;

  if (yyin == 0)
    {

      printf ("Error opening file : %s\n", c);

      exit (0);

    }
  
  init_menu();

  return (yyparse ());

}


/**
 *
 * @todo Describe function
 */
int
yyerror (s)
     char *s;
{
char errfile[256];
FILE *f;
long ld = 0;

  ld=buffpos();


  sprintf(errfile,"%s.err",outputfile);
  f=write_errfile(yyin,errfile,ld-1,yylineno);
  fprintf (f, "| %s", s);
  write_cont(yyin);
  printf("Error compiling %s.menu - check %s.err (%d %d)\n",outputfile,outputfile,lineno,yylineno);
  exit (2);
}


/**
 *
 * @todo Describe function
 */
int
yywrap(void)
{
	return 1;
}


/**
 *
 * @todo Describe function
 */
void
init_menu(void)
{
	the_menus.menus.menus_len=0;
	the_menus.menus.menus_val=0;
	the_menus.menus.menus_val=malloc(sizeof(menu)*MAXMENUS); // MAX 256 Menus
}

/**
 *
 * @todo Describe function
 */
menu *
nmenu(void) 
{
menu *m;
int l;
	l=++the_menus.menus.menus_len;
	if (l>=MAXMENUS) {
		printf("Too many menus/submenus\n");
		exit(0);
	}
	//the_menus.menus.menus_val=realloc(the_menus.menus.menus_val,sizeof(menu)*l);
	m=&the_menus.menus.menus_val[l-1];
	m->id="";


	m->options.options_len=0;
	m->options.options_val=0;
	printf("New menu %p\n",m);
	return m;
}

/**
 *
 * @todo Describe function
 */
menu_option_item *
new_option(menu *m) 
{
menu_option_item *i;
	m->options.options_len++;
	if ( m->options.options_len>1000) {
		printf("Corrupt\n");
	exit(2);
	}
	m->options.options_val=realloc(m->options.options_val, m->options.options_len*sizeof(menu_option_item));
	i=&m->options.options_val[m->options.options_len-1];
	i->caption=strdup("");
	i->key_list=strdup("");
	i->checked=0;
	i->align=0;
	i->color=-1;
	i->submenu_id=strdup("");
	return i;
}

/**
 *
 * @todo Describe function
 */
void
push_menu(void *a) 
{
	stackmenus[menu_cnt++]=a;
}

/**
 *
 * @todo Describe function
 */
void
pop_menu(void)
{
	menu_cnt--;
}

/**
 *
 * @todo Describe function
 */
void *
get_menu(void) 
{
	return stackmenus[menu_cnt-1];
}


// ================================= EOF ===============================
