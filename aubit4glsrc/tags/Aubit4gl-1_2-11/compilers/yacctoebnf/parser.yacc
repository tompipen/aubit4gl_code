%{
#include <stdio.h>
#include "data.h"
int lvl;
int gottocode=0;
int colno;
int lineno;
int ignorekw=0;

char *A4GL_strip_quotes(char *s);
struct s_parser_start *start;
%}


%start parser
%verbose
%name-prefix="a4gl_parser_yy"

%union	  {
	char	str[30000];
	struct s_section_item *s_section_item;
	struct s_section_entry *s_section_entry;
	struct s_section_list *s_section_list;
	struct s_parse_entry *s_parse_entry;
	struct s_parser_start *s_parser_start;
}

%token NAMED INTVAL CHAR_VALUE NUMBER_VALUE CH OPTIONAL PREC ERROR

%%


parser: parser_start {
		dumpit($<s_parser_start>1);
	}
;


parser_start :
		parse_entry   {$<s_parser_start>$=new_parser_start(NULL, $<s_parse_entry>1);}
		| parser_start parse_entry  {$<s_parser_start>$=new_parser_start($<s_parser_start>1,$<s_parse_entry>2);}
;


parse_entry:
	identifier ':'  section_list ';' {
		$<s_parse_entry>$=new_parse_entry($<str>1,$<s_section_list>3);
	}
;
	
section_list : 
	section_entry  			 {$<s_section_list>$=new_section_list(NULL, $<s_section_entry>1);}
	| section_list '|' section_entry {$<s_section_list>$=new_section_list($<s_section_list>1,$<s_section_entry>3);}
;


section_entry : section_item  		{$<s_section_entry>$=new_section_entry(NULL, $<s_section_item>1);}
	| section_entry section_item 	{$<s_section_entry>$=new_section_entry($<s_section_entry>1,$<s_section_item>2);}
;


section_item : 	NAMED 		{$<s_section_item>$=new_section_item__1($<str>1);}
	|       CHAR_VALUE 	{$<s_section_item>$=new_section_item__2($<str>1);}
	|       OPTIONAL 	{$<s_section_item>$=new_section_item__2($<str>1);}
	| 	ERROR  {$<s_section_item>$=NULL;}
	|       PREC NAMED	{
				char buff[100];
				sprintf(buff,"%%prec PGKW_%s",$<str>2);
				$<s_section_item>$=new_section_item__2(buff);
				}
	|       	{$<s_section_item>$=NULL;}
	;

identifier : NAMED;

%%


#include "lex.yy.c"
