
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "simple.h"






struct element *list=0;
int list_cnt=0;

void clr_stmt() {
	if (list) free(list);
	list_cnt=0;
	list=0;
}


void add_stmt(struct element *e) {
if (e->type!='W') {
	list=realloc(list,(list_cnt+1)*sizeof(struct element));
	memcpy(&list[list_cnt],e,sizeof(struct element));
	//list[list_cnt].lineno=line;
	list_cnt++;
}
}

char *
make_sql_string (char *first, ...)
{
  va_list ap;
  char *ptr = 0;
  int l;
  char *next;
  int n;

  n = 0;
  va_start (ap, first);
  ptr = strdup (first);
  l = strlen (ptr);

  while (1)
    {
      n++;
      next = va_arg (ap, char *);
      if (next == 0)
        break;
      l += strlen (next);
      l++;                      // Extra space...
      ptr = realloc (ptr, l);
      strcat (ptr, next);
    }
  return ptr;
}


int yyparse() {
int line=1;
int in_stmt=0;
char *ptr=0;
char *ptr_new=0;
struct element *e=0;
int a;

	while (1) {
		a=yylex();

		if (a==0) break;
		/* Eat up comments */
		if (a==KW_OBRACE) {
			while (a&&a!=KW_CBRACE) a=yylex();
		}

		if (a==KW_MINUS_MINUS) {
			while (a!=NL) a=yylex();
		}

		if (a==NL) {
			line++;
		}

		if ((a==NL||a==SPACE)&&e==0) {
			continue;
		}

		if (a==KW_SEMI) { e->stmt=ptr; add_stmt(e); free(e); e=0; ptr=0;continue;}

		if (e==0) {
			e=malloc(sizeof(struct element));
			e->type='?';
		}


		if (e->type=='?') {
			if (a==KW_UPDATE) e->type='U';
			if (a==KW_SELECT) e->type='S';
			if (a==KW_INSERT) e->type='I';
			if (a==KW_DELETE) e->type='D';
			if (e->type=='?') e->type='O';
			e->lineno=line;
		}

		if (ptr==0) ptr_new=strdup(yylval.str);
		else        ptr_new=make_sql_string(ptr,yylval.str,0);

		if (ptr) {
			free(ptr);
		}
		ptr=ptr_new;
		

		
	}

if (e) {
			e->stmt=ptr;
	add_stmt(e);
	free(e);
	e=0;
}

}



