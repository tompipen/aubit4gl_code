   /* $Id: mcompile.c,v 1.1.1.1 2001-08-20 02:35:55 afalout Exp $
   /* */

#include "../../lib/libincl/compiler.h"
#include <stdio.h>
extern int as_c;
#include "menu_x.h"
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
#define MAXMENUS 256
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
  printf("Error compiling %s.menu - check %s.err (%d %d)\n",outputfile,outputfile,lineno,yylineno);
  exit (2);
}


yywrap(){
return 1;
}

extern struct menu_list the_menus;

init_menu() {
	the_menus.menus.menus_len=0;
	the_menus.menus.menus_val=0;
	the_menus.menus.menus_val=malloc(sizeof(menu)*MAXMENUS); // MAX 256 Menus
}

nmenu() {
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

menu_option_item *new_option(menu *m) {
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



void *stackmenus[1000];
int menu_cnt=0;

push_menu(void *a) {
	stackmenus[menu_cnt++]=a;
}

pop_menu() {
	menu_cnt--;
}

void *get_menu() {
	return stackmenus[menu_cnt-1];
}

