#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>

FILE *yyxin;

int main(int argc,char *argv[]) {
       	//yyin=stdin;
	yyxin=fopen("dump_nodes","r");
	push_node(0);
        a4gl_ebnf_yyparse();
	return 0;
}

int nodestackstart[256];
int nodestackend[256];
int nodecnt=0;

int last_node_start() {
	return nodestackstart[nodecnt-1];
}
int last_node_end() {
	return nodestackend[nodecnt-1];
}
int push_node(int n1,int n2) {
	nodestackstart[nodecnt]=n1;
	nodestackend[nodecnt]=n2;
	nodecnt++;
	return 1;
}

int pop_node() {
	nodecnt--;
	return 1;
}


int yyxwrap() {
        return 1;
}

int a4gl_ebnf_yylex() {
	return yyxlex();
}

extern char *yytext;

int a4gl_ebnf_yyerror(char *s) {
                extern int lineno;
                extern int colno;
                printf("%s %d %d\n",s,lineno,colno);
        exit(2);
}


char *A4GL_strip_quotes(char *s) {
        return s;
}



