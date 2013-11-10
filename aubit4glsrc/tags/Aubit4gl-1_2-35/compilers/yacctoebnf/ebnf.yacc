%{
#include <stdio.h>
#include "data.h"
int lvl;
int gottocode=0;
int colno;
int lineno;
int ignorekw=0;
int icnt=1;

char *A4GL_strip_quotes(char *s);
struct s_parser_start *start;
struct s_nodes {
	int startnode;
	int endnode;
	};
%}


%start ebnf
%verbose
%name-prefix="a4gl_ebnf_yy"

%union	{
	char	str[30000];
	struct s_nodes nodes ;
	//int node;
}

%token DOT PIPE OPEN_SQUARE CLOSE_SQUARE OPEN_BRACE CLOSE_BRACE STRING OPEN_BRACKET CLOSE_BRACKET  NAMED EQUAL ERROR

%%

ebnf : 
	ebnf_entry
	| ebnf ebnf_entry
;

ebnf_entry :
	NAMED {
		printf("digraph {\n");
		printf("_r0 [ label=\"%s\" ]\n",$<str>1);
		printf("_rend [ label=\"|\" ]\n");
		}
		EQUAL rules DOT {
			printf("_r%d -> _rend [ label=\"\", dir=\"none\" ]\n",$<nodes>4.endnode /* the end of the node */);
			printf("}\n");
		}
;

rule: simple_list {
		printf("_r%d [label=\"%s\"]\n",icnt, $<str>1);
		$<nodes>$.startnode=icnt;
		$<nodes>$.endnode=icnt;
		icnt++;
	}
	| OPEN_SQUARE  { 
			printf("_r%d [ shape=\"point\",width=0, label=\"openbox\" ]\n",icnt);
			printf("_r%d [ shape=\"point\", width=0,label=\"closebox\" ]\n",icnt+1);
			printf("_r%d -> _r%d [ label=\"\", dir=\"none\" ]\n",icnt, icnt+1);
			$<nodes>$.startnode=icnt; 
			$<nodes>$.endnode=icnt+1; 
			push_node(icnt,icnt+1); 
			icnt+=2;
		} rules CLOSE_SQUARE	{
			printf("_r%d -> _r%d [ label=\"\", dir=\"none\" ] \n",$<nodes>3.endnode, $<nodes>2.endnode);
			pop_node(); 
			$<nodes>$.startnode=$<nodes>2.startnode;
			$<nodes>$.endnode=$<nodes>2.endnode;
		}
	| OPEN_BRACE   { 
			printf("_r%d [ shape=\"point\",width=0, label=\"openbrace\" ]\n",icnt);
			printf("_r%d [ shape=\"point\", width=0,label=\"closebrace\" ]\n",icnt+1);
			printf("_r%d -> _r%d [ label=\"\",  dir=\"none\" ]\n",icnt+1, icnt);
			$<nodes>$.startnode=icnt; 
			$<nodes>$.endnode=icnt+1; 
			push_node(icnt,icnt+1); 
			icnt+=2;
			} rules CLOSE_BRACE  		{
				printf("_r%d -> _r%d [ label=\"\", dir=\"none\" ] \n",$<nodes>3.endnode,  $<nodes>2.endnode);
			 	pop_node();
			$<nodes>$.startnode=$<nodes>2.startnode;
			$<nodes>$.endnode=$<nodes>2.endnode;
		
	}
	| OPEN_BRACKET { 
			printf("_r%d [ shape=\"point\", width=0, label=\"\" ]\n",icnt);
			printf("_r%d [ shape=\"point\", width=0, label=\"\" ]\n",icnt+1);
			$<nodes>$.startnode=icnt; 
			$<nodes>$.endnode=icnt+1; 
			 push_node(icnt,icnt+1); icnt+=2; 
			} ruleset CLOSE_BRACKET 	{ 
			pop_node();
			$<nodes>$.startnode=$<nodes>2.startnode;
			$<nodes>$.endnode=$<nodes>2.endnode;
	}

;

simple_list : 
	simple   {
		strcpy($<str>$,$<str>1);
	}
	| simple_list simple {
		sprintf($<str>$,"%s %s",$<str>1,$<str>2);
	}
;

simple : STRING  {strcpy($<str>$,$<str>1);}
	| NAMED {strcpy($<str>$,$<str>1);}
;

rules :
	rule  {
		printf("_r%d -> _r%d [label=\"\", dir=\"none\"] \n", last_node_start(),$<nodes>1.startnode);
			$<nodes>$.startnode=$<nodes>1.startnode;
			$<nodes>$.endnode=$<nodes>1.endnode;
	}
	| rules rule {
		printf("_r%d -> _r%d [label=\"\", dir=\"none\"]\n", $<nodes>1.endnode,$<nodes>2.startnode);
			$<nodes>$.startnode=$<nodes>2.startnode;
			$<nodes>$.endnode=$<nodes>2.endnode;
	}
;

ruleset: rules  {
		printf("_r%d -> _r%d [label=\"\", dir=\"none\"] \n", $<nodes>1.endnode, last_node_end());
	}
	| ruleset PIPE rules {
		printf("_r%d -> _r%d [label=\"\", dir=\"none\"] \n", $<nodes>3.endnode, last_node_end());
	}
;

%%


#include "lex.yyx.c"
