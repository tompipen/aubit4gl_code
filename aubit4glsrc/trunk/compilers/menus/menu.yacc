%{
#include "menu_x.h"
#include "../../lib/libincl/compiler.h"
#include "../../lib/libincl/debug.h"
#include <stdio.h>
#include <string.h>

extern int ignorekw;
extern int lineno;
extern int colno;
extern int scr;

char *img_val="";

long fileseek=0;
menu_list the_menus;
extern int menu_cnt;
char sbuff[256];
menu_option_item *o;
extern char *outputfilename;
extern FILE *yyin;
struct menu *m;

/* Functions prototipes */
menu *nmenu();
menu_option_item *new_option(menu *m);
void *get_menu();
char *char_val (char *s);

%}
%start menu_def

%union	  {
	char	str[1024];
}

%token NAMED
%token KW_MENU
%token KW_SUBMENU
%token KW_OPTION
%token KW_RIGHT
%token KW_CHECK
%token KW_USE
%token KW_IMAGE
%token KW_KEY
%token KW_HIDDEN
%token OPEN_SQUARE
%token KW_END
%token CLOSE_SQUARE
%token NUMBER_VALUE
%token CHAR_VALUE
%token OPEN_BRACE
%token CLOSE_BRACE
%token ATSIGN
%token COLON
%token DOT
%token PIPE
%token EQUAL
%token OPEN_BRACKET
%token CLOSE_BRACKET
%token STAR
%token COMMA
%token BLACK
%token BLUE
%token WHITE
%token YELLOW
%token RED
%token GREEN
%token CYAN
%token MAGENTA
%token COLOR
%token CH
%token ATTRIBUTES
%%

/* rules */
menu_def: menu_sec {write_menu();}
;

menu_sec :  
	menu | menu_sec menu 
;

menu:
	KW_MENU identifier {
		m=nmenu();
		m->id=strdup($<str>2);
		push_menu(m);
	}  menu_rest KW_END KW_MENU {pop_menu();}
; 

menu_rest :
	menu_item | menu_rest menu_item
;

identifier: NAMED
;

menu_item :
	KW_OPTION identifier op_image op_string op_key op_attr {
		menu_option_item *o;
		printf("New option %s for menu %p\n",$<str>2,get_menu());
		o=new_option(get_menu());
		o->id=strdup($<str>2);
		o->caption=strdup($<str>4);
		o->image=img_val;
		o->key_list=strdup($<str>5);
		o->align=atoi($<str>6);
	 	printf("Ok option\n"); }
	| KW_SUBMENU identifier op_image op_string op_key op_attr KW_USE identifier {
		menu_option_item *o;
		printf("Submenu with use\n");
		o=new_option(get_menu());
		o->id=strdup($<str>2);
		o->image=img_val;
		o->caption=strdup($<str>4);
		o->submenu_id=strdup($<str>8);
		o->key_list=strdup($<str>5);
		o->align=atoi($<str>6);
	}
	| KW_SUBMENU identifier op_image op_string op_key op_attr {
		menu_option_item *o;
		printf("Submenu without use\n");
		o=new_option(get_menu());
		o->id=strdup($<str>2);
		o->image=img_val;
		o->caption=strdup($<str>4);
		o->key_list=strdup($<str>5);
		o->align=atoi($<str>6);
		//sprintf(sbuff,"_menuid%d",menu_cnt);
		o->submenu_id=strdup($<str>2);
		m=nmenu();
		m->id=strdup($<str>2);
		push_menu(m);

	} menu_rest KW_END KW_SUBMENU  {pop_menu();}
;

op_string: {strcpy($<str>$,"");} 
| CHAR_VALUE { strcpy($<str>$,char_val($<str>1));}
| CHAR_VALUE CHAR_VALUE { sprintf($<str>$,"%s\n%s",strdup(char_val($<str>1)),strdup(char_val($<str>2)));}
;

op_key : {strcpy($<str>$,"");} | key
;

key :
	KW_KEY CHAR_VALUE {
	strcpy($<str>$,char_val($<str>2));}
;

op_attr: {strcpy($<str>$,"");} | ATTRIBUTES OPEN_BRACKET attr CLOSE_BRACKET
{strcpy($<str>$,$<str>3);}
;

attr : 
	attr_elem | attr COMMA attr_elem 
	
;

attr_elem:
	KW_RIGHT
;
op_image  : {
		img_val="";
	} | KW_IMAGE EQUAL CHAR_VALUE {
		img_val=strdup(char_val($<str>3));
	}
;
%%
#include "lex.yy.c"







