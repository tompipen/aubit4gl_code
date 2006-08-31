%{
#define _BISON_SIMPLE_INCL_

/*
=====================================================================
		                    Includes
=====================================================================
*/
#define YYDEBUG 1
#define _NO_YYPARSE_PROTO_
/* #define _NO_YYLEX_PROTO_ */
#include "a4gl_dbload_int.h"
#include <ctype.h>
#include <stdlib.h>

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

struct filedef *m_filedef=0;

%}

%start dbload

%name-prefix="a4gl_dbload_yy"

%union	  {
	char	str[30000];
	char *ptr;
	struct filedef *fileelem;
	struct insert *insertexpr;
	struct s_dbloadline *dbload;
	struct s_nposlist *nposlist;
	struct  s_field_pos *field_pos;
	struct s_pos_list *pos_list;
	struct s_field_pos_list *field_pos_list;
}


%token KW_FILE KW_DELIMITER KW_STRING KW_INSERT KW_INTO
%token KW_NAMED KW_FNAMED
%token KW_COMMA KW_NUMBER_VALUE
%token KW_SEMICOLON KW_INT_VALUE KW_OPEN_BRACKET KW_CLOSE_BRACKET KW_VALUES 
%token KW_NULL KW_MINUS KW_EQUAL KW_COLON

%%
dbload :
	dbload_entry
	| dbload dbload_entry
	;

dbload_entry:
	file_delim_entry { m_filedef=$<fileelem>1; } insert_entries
	;

insert_entries:
		insert_entry {
		$<dbload>$=malloc(sizeof(struct s_dbloadline));
		$<dbload>$->f=m_filedef;
		$<dbload>$->i=$<insertexpr>1;
		process_entry($<dbload>$);
	 } 
	| insert_entries insert_entry {
	                $<dbload>$=malloc(sizeof(struct s_dbloadline));
	                $<dbload>$->f=m_filedef;
	                $<dbload>$->i=$<insertexpr>2;
	                process_entry($<dbload>$);
	}
;


file_delim_entry: 
	KW_FILE fname KW_DELIMITER KW_STRING KW_INT_VALUE KW_SEMICOLON {
		$<fileelem>$=malloc(sizeof(struct filedef));
		$<fileelem>$->type=0;
		$<fileelem>$->field_pos_list=0;
		$<fileelem>$->fname=strdup($<str>2);
		$<fileelem>$->delim=strdup(A4GL_strip_quotes($<str>4));
		$<fileelem>$->nfields=atoi($<str>5);
	}
	| KW_FILE fname KW_OPEN_BRACKET field_pos_list KW_CLOSE_BRACKET KW_SEMICOLON {
		$<fileelem>$=malloc(sizeof(struct filedef));
		$<fileelem>$->type=1;
		$<fileelem>$->fname=strdup($<str>2);
		$<fileelem>$->delim=0;
		$<fileelem>$->field_pos_list=$<field_pos_list>4;
		$<fileelem>$->nfields=$<fileelem>$->field_pos_list->npos;
	}
	;

field_pos_list : 
	field_pos {
		$<field_pos_list>$=malloc(sizeof(struct s_field_pos_list));
		$<field_pos_list>$->npos=1;
		$<field_pos_list>$->pos=malloc(sizeof(struct s_field_pos*));
		$<field_pos_list>$->pos[0]=$<field_pos>1;
	}
	| field_pos_list KW_COMMA field_pos {
		$<field_pos_list>$=$<field_pos_list>1;
		$<field_pos_list>$->npos++;
		$<field_pos_list>$->pos=realloc($<field_pos_list>$->pos,sizeof(struct s_field_pos*)*$<field_pos_list>$->npos);
		$<field_pos_list>$->pos[$<field_pos_list>1->npos-1]=$<field_pos>3;
		}
;


field_pos : 
	field_name field_positions opt_null {
		$<field_pos>$=malloc(sizeof(struct s_field_pos));
		$<field_pos>$->name=strdup($<str>1);
		$<field_pos>$->null=$<ptr>3;
		$<field_pos>$->pos_list=$<nposlist>2;
	}
	;

opt_null : { $<ptr>$=0; }
	| KW_NULL KW_EQUAL KW_STRING {
			$<ptr>$=strdup(A4GL_strip_quotes($<str>3));
	}
	;


field_name: KW_NAMED {
	strcpy($<str>$,$<str>1);
	}
	;


field_positions  : 
	field_position {
		$<nposlist>$=malloc(sizeof(struct s_nposlist));
		$<nposlist>$->npos=1;
		$<nposlist>$->list_of_character_positions=malloc(sizeof(struct s_pos_list *));
		$<nposlist>$->list_of_character_positions[$<nposlist>$->npos-1]=$<pos_list>1;
		$<nposlist>$->memsz=$<pos_list>1->sz;
		}
	| field_positions KW_COLON field_position {
		$<nposlist>1->npos++;
		$<nposlist>1->list_of_character_positions=realloc($<nposlist>1->list_of_character_positions,sizeof(struct s_pos_list *)*$<nposlist>1->npos);
		$<nposlist>1->list_of_character_positions[$<nposlist>1->npos-1]=$<pos_list>3;
		$<nposlist>$=$<nposlist>1;
		$<nposlist>$->memsz+=$<pos_list>3->sz;
		}
;

field_position: 
	KW_INT_VALUE {
		$<pos_list>$=malloc(sizeof(struct s_pos_list));
		$<pos_list>$->start=atoi($<str>1);
		$<pos_list>$->end=0;
		$<pos_list>$->sz=1;
	}
	| KW_INT_VALUE KW_MINUS KW_INT_VALUE {
		$<pos_list>$=malloc(sizeof(struct s_pos_list));
		$<pos_list>$->start=atoi($<str>1);
		$<pos_list>$->end=atoi($<str>3);
		$<pos_list>$->sz=($<pos_list>$->end-$<pos_list>$->start+1);
		}

;




fname: KW_NAMED {
		strcpy($<str>$,$<str>1);
		}
	| KW_FNAMED  {
		strcpy($<str>$,$<str>1);
		}
	| KW_STRING {
			strcpy($<str>$,A4GL_strip_quotes($<str>1));
	}
;

insert_entry :
	KW_INSERT KW_INTO tabname opt_cols KW_SEMICOLON {
			$<insertexpr>$=malloc(sizeof(struct insert));
			$<insertexpr>$->tabname=strdup($<str>3);
			$<insertexpr>$->colexpr=strdup($<str>4);
	}
;

opt_cols : { strcpy($<str>$,""); }
	| KW_OPEN_BRACKET column_list KW_CLOSE_BRACKET KW_VALUES KW_OPEN_BRACKET values_list KW_CLOSE_BRACKET {
			sprintf($<str>$,"(%s) VALUES (%s)",$<str>2,$<str>6);
	}
	| KW_VALUES KW_OPEN_BRACKET values_list KW_CLOSE_BRACKET {
			sprintf($<str>$,"VALUES (%s)",$<str>3);
	}
	;

column_list : 
	column_name {
		strcpy($<str>$,$<str>1);
	}
	| column_list KW_COMMA column_name {
		sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
	}
	;

column_name : KW_NAMED {
	if (is_column_name($<str>1)) {
		char *ptr;
		ptr=$<str>1;
		ptr++;
		sprintf($<str>$,"\t%d\n",atoi(ptr));
	} else {
		strcpy($<str>$,$<str>1);
	}
	}
;

tabname: KW_NAMED
;

values_list:
	value_value {
		strcpy($<str>$,$<str>1);
		}
	| values_list KW_COMMA value_value {
		sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
		}
	;

value_value:
	KW_STRING {
			sprintf($<str>$,"\"%s\"",$<str>1);
		}
	| KW_INT_VALUE
	| KW_NUMBER_VALUE
	| KW_NAMED {
	        if (is_column_name($<str>1)) {
			char *ptr;
		        ptr=$<str>1;
		        ptr++;
		        sprintf($<str>$,"\t%d\n",atoi(ptr));
		} else {
			strcpy($<str>$,$<str>1);
		}
	}
	;

%%


#include "lex.yy.c"

