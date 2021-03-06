
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "simple.h"
#include "a4gl_libaubit4gl.h"


void clr_stmt(void) ;
void add_stmt(struct element *e);
char * make_sql_string (char *first, ...);
int yyparse(void) ;
int yylex(void);




struct element *list=0;
int list_cnt=0;

void clr_stmt(void) {
	if (list) free(list);
	list_cnt=0;
	list=0;
}


void add_stmt(struct element *e) {
//printf("%c %d '%s' fname='%s' delim='%s'\n",e->type,e->lineno,e->stmt,e->fname,e->delim);
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
  static char *ptr = 0;
  static int l=0;
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


int yyparse(void) {
int line=1;
//int in_stmt=0;
char *ptr=0;
char *ptr_new=0;
struct element *e=0;
int a;
int into_temp=0;
int need_fname=0;
int need_delim=0;
int need_tabname=0;

	while (1) {
		a=yylex();

		if (a==0) break;
		/* Eat up comments */
		//printf("-->%s (%d) %d\n",yylval.str,a,need_delim);

		if (need_fname) {
			if (a==KW_SPACE||a==KW_NL) continue;

			if (a==KW_IDENTIFIER||a==KW_STRING_LITERAL||a==KW_CONSTANT) {
				char buff[512];
				strcpy(buff,yylval.str);
				strcpy(buff,A4GL_strip_quotes(buff));
				e->fname=strdup(buff);
				// We also need to remove the UNLOAD ... bit...
				//printf("Scrapping %s\n",ptr);
				free(ptr); ptr=0;
				need_fname=0;
				continue;
			}
			printf("Unknown a when looking for filename %d\n",a);
		}

                if (need_delim&&(a==KW_IDENTIFIER||a==KW_STRING_LITERAL||a==KW_CONSTANT)) {
			//printf("Have delimiter : %s",yylval.str);
			if ((a==KW_STRING_LITERAL||a==KW_CONSTANT) &&(yylval.str[0]=='"'||yylval.str[0]=='\'')) {
                        	e->delim=strdup(&yylval.str[1]);
                        	e->delim[strlen(e->delim)-1]=0;
			} else {
                        	e->delim=strdup(yylval.str);
			}
			//printf("Have delimiter : %s (%d) %d %d %d",e->delim,a,KW_IDENTIFIER,KW_STRING_LITERAL,KW_CONSTANT);
                        free(ptr); ptr=0;
                        need_delim=0;
			continue;
                }

		if (need_tabname) {
			if (a==KW_IDENTIFIER) {
				e->fname=strdup(yylval.str);
                        	free(ptr);ptr=0;
				need_tabname=0;
				continue;
			}
		}


		if (a==KW_OBRACE) {
			while (a&&a!=KW_CBRACE) a=yylex();
			continue;
		}

		if (a==KW_WHERE) {
			e->type=tolower(e->type);
		}

		if (a==KW_DELIMITER) {
			//printf("NEED DELIM\n");
			need_delim=1;
			continue;
		}

		if (into_temp==1) {
			A4GL_debug("Got into_temp - a=%d",a);
			if (a==KW_TEMP||a==KW_SPACE||a==KW_NL) ;
			else into_temp=0;
		}

		if (a==KW_INTO&&into_temp==0) into_temp++;

		if (a==KW_TEMP&&into_temp==1) {
				A4GL_debug("TEMP TABLE ? e->type was %c",e->type);
				if (e->type=='S'||e->type=='s') e->type='T';
				A4GL_debug("TEMP TABLE ? e->type now %c",e->type);

		}

		if (a==KW_MINUS_MINUS) {
			while (a!=KW_NL) a=yylex();
		}

		if (a==KW_NL) {
			line++;
		}

		if ((a==KW_NL||a==KW_SPACE)&&e==0) {
			continue;
		}


		if (a==KW_SEMI) { e->stmt=ptr; add_stmt(e); free(e); e=0; ptr=0;continue;}

		if (e==0) {
			e=acl_malloc2(sizeof(struct element));
			e->type='?';
			e->delim=0;
			e->fname=0;
		}


		A4GL_assertion(e==0,"No element");

		if (e->type=='?') {
			if (a==KW_LOAD)   {e->type='L';need_fname=1;}
			if (a==KW_UNLOAD) {e->type='C';need_fname=1;}
			if (a==KW_UPDATE) e->type='U';
			if (a==KW_INSERT) e->type='I';
			if (a==KW_DELETE) e->type='D';
			if (a==KW_SELECT) e->type='S';
			if (a==KW_EXPLAIN) e->type='E';

			if (a==KW_INFO_COL) {e->type='1';need_tabname=1;}
			if (a==KW_INFO_STAT) {e->type='2';need_tabname=1;}
			if (a==KW_INFO_TABLES) e->type='3';
			if (a==KW_INFO_PRIV) {e->type='4';need_tabname=1;}
			if (a==KW_INFO_IDX) {e->type='5';need_tabname=1;}

			if (e->type=='?') e->type='O';

			e->lineno=line;
			into_temp=0;
		}

		if (ptr==0) ptr_new=strdup(yylval.str);
		else        ptr_new=make_sql_string(ptr,yylval.str,0);

		if (ptr) {
			free(ptr); ptr=0;
		}
		ptr=ptr_new;
		

		
	}

if (e) {
	e->stmt=ptr;
	add_stmt(e);
	free(e);
	e=0;
}
return 1;

}
