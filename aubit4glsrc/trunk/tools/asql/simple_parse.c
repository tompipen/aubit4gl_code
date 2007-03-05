
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "simple.h"
#include "a4gl_libaubit4gl.h"


void clr_stmt(void) ;
void add_stmt(struct element *e);
char * make_sql_string (char *first, ...);
int my_pretend_yyparse(void) ;
int asql_yylex(void);




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


int my_pretend_yyparse(void) {
int line=1;
//int in_stmt=0;
char *ptr=0;
char *ptr_new=0;
struct element *elem=0;
int a;
int into_temp=0;
int need_fname=0;
int need_delim=0;
int need_tabname=0;
int in_create_procedure;

	while (1) {
		a=asql_yylex();

		if (a==0) break;
		/* Eat up comments */
		//printf("-->%s (%d) %d\n",yylval.str,a,need_delim);

		if (need_fname) {
			if (a==KW_SPACE||a==KW_NL) continue;

			if (a==KW_IDENTIFIER||a==KW_STRING_LITERAL||a==KW_CONSTANT) {
				char buff[512];
				strcpy(buff,yylval.str);
				strcpy(buff,A4GL_strip_quotes(buff));
				elem->fname=strdup(buff);
				// We also need to remove the UNLOAD ... bit...
				//printf("Scrapping %s\n",ptr);
				free(ptr); ptr=0;
				need_fname=0;
				continue;
			}
			printf("Unknown a when looking for filename %d\n",a);
		}


		if (a==KW_CREATE_PROCEDURE) {
			static char buff[20000];
			struct element *elem_crp=0;
			strcpy(buff,yylval.str);
			while (1) {
				a=asql_yylex();
				if (a==0) break;
				strcat(buff,yylval.str);
				if (a==KW_END_PROCEDURE) {
					break;
				}
			}
			elem_crp=acl_malloc2(sizeof(struct element));
			elem_crp->type='?';
			elem_crp->delim=0;
			elem_crp->fname=0;
			elem_crp->stmt=strdup(buff);
			add_stmt(elem_crp);
			free(elem_crp);
			continue;
		}

                if (need_delim&&(a==KW_IDENTIFIER||a==KW_STRING_LITERAL||a==KW_CONSTANT)) {
			//printf("Have delimiter : %s",yylval.str);
			if ((a==KW_STRING_LITERAL||a==KW_CONSTANT) &&(yylval.str[0]=='"'||yylval.str[0]=='\'')) {
                        	elem->delim=strdup(&yylval.str[1]);
                        	elem->delim[strlen(elem->delim)-1]=0;
			} else {
                        	elem->delim=strdup(yylval.str);
			}
			//printf("Have delimiter : %s (%d) %d %d %d",e->delim,a,KW_IDENTIFIER,KW_STRING_LITERAL,KW_CONSTANT);
                        free(ptr); ptr=0;
                        need_delim=0;
			continue;
                }

		if (need_tabname) {
			if (a==KW_IDENTIFIER) {
				elem->fname=strdup(yylval.str);
                        	free(ptr);ptr=0;
				need_tabname=0;
				continue;
			}
		}


		if (a==KW_OBRACE) {
			while (a&&a!=KW_CBRACE) {
				a=asql_yylex();
			}
			continue;
		}

		if (a==KW_WHERE) {
			elem->type=tolower(elem->type);
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
				A4GL_debug("TEMP TABLE ? e->type was %c",elem->type);
				if (elem->type=='S'||elem->type=='s') elem->type='T';
				A4GL_debug("TEMP TABLE ? e->type now %c",elem->type);

		}

		if (a==KW_MINUS_MINUS) {
			while (a!=KW_NL) a=asql_yylex();
		}

		if (a==KW_NL) {
			line++;
		}

		if ((a==KW_NL||a==KW_SPACE)&&elem==0) {
			continue;
		}


		if (a==KW_SEMI) { 
			if (ptr) {
				elem->stmt=ptr; 
				add_stmt(elem); 
				free(elem); 
			}
			elem=0; ptr=0;continue;
		}

		if (elem==0) {
			elem=acl_malloc2(sizeof(struct element));
			elem->type='?';
			elem->delim=0;
			elem->fname=0;
		}


		A4GL_assertion(elem==0,"No element");

		if (elem->type=='?') {
			if (a==KW_LOAD)   {elem->type='L';need_fname=1;}
			if (a==KW_UNLOAD) {elem->type='C';need_fname=1;}
			if (a==KW_UPDATE) elem->type='U';
			if (a==KW_INSERT) elem->type='I';
			if (a==KW_DELETE) elem->type='D';
			if (a==KW_SELECT) elem->type='S';
			if (a==KW_EXPLAIN) elem->type='E';

			if (a==KW_INFO_COL) {elem->type='1';need_tabname=1;}
			if (a==KW_INFO_STAT) {elem->type='2';need_tabname=1;}
			if (a==KW_INFO_TABLES) elem->type='3';
			if (a==KW_INFO_PRIV) {elem->type='4';need_tabname=1;}
			if (a==KW_INFO_IDX) {elem->type='5';need_tabname=1;}

			if (elem->type=='?') {
				if (A4GL_aubit_strcasecmp(yylval.str,"SHOW")==0) {
					elem->type='S';
				} else {
					elem->type='O';
				}
			}

			elem->lineno=line;
			into_temp=0;
		}

		if (ptr==0) ptr_new=strdup(yylval.str);
		else        ptr_new=make_sql_string(ptr,yylval.str,0);

		if (ptr) {
			free(ptr); ptr=0;
		}
		ptr=ptr_new;
		

		
	}

if (elem) {
	elem->stmt=ptr;
	add_stmt(elem);
	free(elem);
	elem=0;
}
return 1;

}
