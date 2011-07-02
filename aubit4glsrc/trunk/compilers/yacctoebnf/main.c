#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "data.h"
#include "kw.h"
extern struct s_kw *hashed_list[];
int mainblock=-1;
int upto;

struct s_kwords {
	char *token;
	char *text;
};
struct s_kwords kwords[2000];
int nkwords=0;

//char *startnodename="pdf_report_def";
char *get_text(char *s) ;
char *has_rule(struct s_parser_start *parser_start, char *s) ;
void dumpit_one( struct s_parser_start *parser_start,  char *startnodename) ;
static void trimnl(char *s) ;


int nterminals=0;
struct s_term {
	char *fake_terminal;
	char *fake_terminal_text;
};
struct s_term *terminal_list=0;


void add_terminal(char *terminal, char *text) {
	nterminals++;
	terminal_list=realloc(terminal_list,sizeof(terminal_list[0])*nterminals);
	terminal_list[nterminals-1].fake_terminal=strdup(terminal);
	terminal_list[nterminals-1].fake_terminal_text=strdup(text);
}


void load_file(FILE *f) {
char buff[200];
char buff2[200];
if (f==NULL) {
	fprintf(stderr,"Unable to read file!!\n");
	exit(2);
}

while (1) {
	char *ptr;
	char *p2;
	if (feof(f)) break;
	strcpy(buff,"");
	fgets(buff,200,f);
	if (strlen(buff)==0) break;
	ptr=strchr(buff,'\t');
	if (ptr==0) {
		continue;
	}
	*ptr=0;
	ptr++;
	p2=strchr(ptr,'\n'); if (p2)*p2=0;
	p2=strchr(ptr,'\r'); if (p2)*p2=0;
	sprintf(buff2,"\"%s\"",ptr);
	add_terminal(buff,buff2);
}
}


void load_terminals() {
FILE *f;
	f=fopen("entries","r");
	load_file(f);
	f=fopen("commands","r");
	load_file(f);

	upto=nterminals-1;

	add_terminal("atline","");
	add_terminal("KW_DOT","\".\"");
	add_terminal("KW_COMMA","\",\"");
	add_terminal("OPEN_BRACKET","\"(\"");
	add_terminal("CLOSE_BRACKET","\")\"");


	add_terminal("NAMED","\"identifier\"");
	add_terminal("commands_as_list","\"[commands]\"");

/*
	add_terminal("expanded_ibind_var_list","\"[variable_list]\"");
	add_terminal("variable_usage","\"[variable]\"");
	add_terminal("variable_usage_expression","\"[variable]\"");
	add_terminal("pf_char_or_var","\"[character-expression]\"");
	add_terminal("identifier","\"identifier\"");
	add_terminal("INT_VALUE","\"<integer value>\"");
	add_terminal("NUMBER_VALUE","\"<numeric value>\"");
	add_terminal("USER_DTYPE_NEW","\"<userdefined datatype>\"");
	add_terminal("USER_DTYPE_ORIG","\"<olduserdefinedtype>\"");
	add_terminal("KW_CSTART","\"code\"");
	add_terminal("CLINE","\"<embedded c code>\"");
	add_terminal("KW_CEND","\"endcode\"");
	add_terminal("CHAR_VALUE","\"character-string\"");
	add_terminal("nval_number","\"number_value\"");
*/
}

int has_fake_terminal(char *s) {
int a;
for (a=0;a<nterminals;a++) {
	if (strcmp(s,terminal_list[a].fake_terminal)==0) {
		return a;
	}
}
return -1;
}


void dump_section_entry(struct s_parser_start *parser_start,char *buff, struct s_section_entry *e) {
int a;
	int printed=0;
for (a=0;a<e->nitems;a++) {
	char *data;
	int n;
	data=e->items[a]->data;

	if (printed) strcat(buff," ");

	// if we've got a fake terminal - lets use the synonym...
	n=has_fake_terminal(data);
	if (n!=-1) {
		data=terminal_list[n].fake_terminal_text;
	} else {
		char *rule_txt;
		rule_txt=has_rule(parser_start,data);
		if (rule_txt) data=rule_txt;
		else {
			data=get_text(data);
		}
	}
	if (strlen(data)) {
		strcat(buff,data); 
		printed=1;
	} else {
		printed=0;
	}
}
}


void dump_section_list(struct s_parser_start *parser_start,char *buff, struct s_section_list *l,int repeat) {
	int a;
	int printed=0;
	int ni;
	ni=0;
	for (a=0;a<l->nitems;a++) {
		//printf("%d\n", l->items[a]->nitems);
		if ( l->items[a]->nitems) ni++;
	}


	if (ni>1) { strcat(buff,"("); }

	for (a=0;a<l->nitems;a++) {
		if (a==repeat) continue;
		if (l->items[a]->nitems==0) continue;
		if (printed) strcat(buff, "| ");
		else strcat(buff, "  ");
		dump_section_entry(parser_start, buff, l->items[a]);
		printed++;
		strcat(buff, " ");
	}
	if (ni>1) { strcat(buff,")"); }
}



void contains (struct s_parse_entry *e, char *name,int *optional, int *repeat,int *comma) {
//printf("Contains %s\n",name);
	int a;
	*repeat=-1;
	*comma=0;

	*optional=0;

	for (a=0;a<e->item->nitems;a++) {
			struct s_section_entry *l;
			l=e->item->items[a];
			if (l->nitems==0) {
				*optional=*optional+1;
					//printf("Break\n");
				continue; // No point checking any names - it doesn't have any...
			}
			//printf("-->%s\n",l->items[0]->data);
			
			if (strcmp(e->name, l->items[0]->data)==0) {*repeat=a;}
			if (l->nitems>=2) {
				if (strcmp("KW_COMMA", l->items[1]->data)==0) {
					*comma=1;
				}
			}
	
	}
}

void dump_parse_entry(struct s_parser_start *parser_start,struct s_parse_entry *e) {
char buff[200000]="";
	if (e->result==0) {
			int repeatition=0;
			int optional;
			int comma;
			contains(e, e->name, &optional,&repeatition,&comma);
			strcpy(buff,"");
			//sprintf(buff,"%s=",e->name);
			if (optional) strcat(buff,"[");
			if (comma==0 || repeatition==0) {
				if (repeatition>=0) strcat(buff,"{");
				dump_section_list(parser_start, buff, e->item,repeatition);
				if (repeatition>=0) strcat(buff,"}");
			} else {
				if (repeatition>=0) strcat(buff,"(");
				dump_section_list(parser_start, buff, e->item,repeatition);
				if (repeatition>=0) strcat(buff," ");
				if (repeatition>=0) strcat(buff,"[( \",\" ");
				dump_section_list(parser_start, buff, e->item,repeatition);
				if (repeatition>=0) strcat(buff,")+])");
			}
			if (optional) strcat(buff, "]");
			e->result=strdup(buff);
	} 
	if (e->printed==0) {
			e->printed=1;
	}
}


char *has_rule(struct s_parser_start *parser_start, char *s) {
int a;
for (a=0;a<parser_start->nitems;a++) {
	if (strcmp(parser_start->items[a]->name,s)==0) return (parser_start->items[a]->result);
}
return NULL;
}

int walktree(struct s_parser_start *parser_start, char *name, char *calledby,int lvl) {
	int a,b,c;

if (lvl>14) {
	return 0 ; // too deep...
}


	for (a=0;a<parser_start->nitems;a++) {
		if (strcmp(parser_start->items[a]->name, name)==0) {
			// We always want to print our 'main'...
			if (strcmp(calledby,"[main]")==0) {
				parser_start->items[a]->printed=1;
				mainblock=a;
			}
			if ((parser_start->items[a]->printed==1)) {
				struct s_section_list *l;
				struct s_section_entry *e;
				// reset it..
				parser_start->items[a]->printed=0;
				parser_start->items[a]->calledby=strdup(calledby);
				l=parser_start->items[a]->item;
				// and use anything it uses...
				for (b=0;b<l->nitems;b++) {
					e=l->items[b];
					for (c=0;c<e->nitems;c++) {
						// Only walk if we've not explicitly excluded this branch...
						if (has_fake_terminal(e->items[c]->data)==-1) {
							if (!walktree(parser_start,e->items[c]->data, name,lvl+1)) return 0;
						}
					}
				}
				dump_parse_entry(parser_start, parser_start->items[a]);
			}
		
		}
	}
return 1;
}

void dumpit(struct s_parser_start *parser_start) {
int a;
for (a=0;a<=upto;a++) {
	dumpit_one( parser_start, terminal_list[a].fake_terminal);
}
}

void dumpit_one( struct s_parser_start *parser_start,  char *startnodename) {
int a;
for (a=0;a<parser_start->nitems;a++) {
	// pretend we've already printed this 
	// we'll reset this to zero for anything we actually need to print.
	parser_start->items[a]->printed=1;
	parser_start->items[a]->calledby="";
	parser_start->items[a]->result=0;
}

	if (walktree(parser_start,startnodename,"[main]",0) ) {

		if (mainblock>=0) {
			printf("%s=%s\n", startnodename, parser_start->items[mainblock]->result);
		} else {
			printf("No main block (%s)?!\n",startnodename);
		}
	
		printf(".\n");
	} else {
		fprintf(stderr,"Too deep for %s\n", startnodename);
	}


}




int main(int argc,char *argv[]) {
        extern FILE *yyin;
	int a;
	for (a=0;a<2000;a++) {
		kwords[a].token=NULL;
		kwords[a].text=NULL;
	}
        if (argc>1) {
		FILE *kwords_file;
        	yyin=fopen(argv[1],"r");
		kwords_file=fopen("keywords","r");
		if (kwords_file) {
		int a=0;
			while (1) {
				char buff[256];
				char *ptr;
				strcpy(buff,"");
				fgets(buff,255,kwords_file);
				if( feof(kwords_file)) break;
				if( strlen(buff) ){
					trimnl(buff);
					ptr=strchr(buff,'	');
					if (ptr) { *ptr=0;ptr++;
						kwords[a].token=strdup(buff);
						kwords[a].text=strdup(ptr);
						a++;
					}
				}
			}
			nkwords=a;
			fclose(kwords_file);
		}
		
        } else {
        	yyin=fopen("../4glc/rules/generated/fgl.infx.yacc","r");
        }

	load_terminals();
        if (!yyin) {
                printf("Unable to open input\n");
                exit(2);
        }
        a4gl_parser_yyparse();
	return 0;
}

int yywrap() {
        return 1;
}


extern char *yytext;
int a4gl_parser_yyerror(char *s) {
                extern int lineno;
                extern int colno;
                printf("%s %d %d\n",s,lineno,colno);
        exit(2);
}


char *A4GL_strip_quotes(char *s) {
        return s;
}





/*
struct s_section_item {
	int type;
	char *data;
};


struct s_section_entry {
	int nitems;
	struct s_section_item *items;
};

struct s_section_list {
	int nitems;
	struct s_section_entry *items;
};

struct s_parse_entry {
	char *name;
	struct s_section_list *item;
} ;


struct s_parser_start {
	int nitems;
	struct s_parse_entry *items;
};

*/


struct s_parser_start *new_parser_start  (struct s_parser_start *list, struct s_parse_entry *a1)  {
	if (list==NULL) {
		list=malloc(sizeof(struct s_parser_start));
		list->nitems=0;
		list->items=0;
	}
	list->nitems++;
	list->items=realloc(list->items, list->nitems*sizeof(list->items[0]));
	list->items[list->nitems-1]=a1;
	return list;
}

struct s_parse_entry *new_parse_entry    (char *name,struct s_section_list *a2) {
	struct s_parse_entry *entry;
	entry=malloc(sizeof(struct s_parse_entry));
	entry->name=strdup(name);
	entry->printed=0;
	entry->item=a2;
	return entry;
}


struct s_section_list *new_section_list  (struct s_section_list *list, 	struct s_section_entry *a1)  {
	if (list==NULL) {
		list=malloc(sizeof(struct s_section_list));
		list->nitems=0;
		list->items=0;
	}
	list->nitems++;
	list->items=realloc(list->items, list->nitems*sizeof(list->items[0]));
	list->items[list->nitems-1]=a1;
	return list;
}

struct s_section_entry *new_section_entry(struct s_section_entry *list, struct s_section_item *a1)  {
	if (list==NULL) {
		list=malloc(sizeof(struct s_section_entry));
		list->nitems=0;
		list->items=0;
	}
	if (a1==NULL) return list;
	list->nitems++;
	list->items=realloc(list->items, list->nitems*sizeof(list->items[0]));
	list->items[list->nitems-1]=a1;
	return list;
}

struct s_section_item *new_section_item__1(char *s)  {
	struct s_section_item *rval;
	rval=malloc(sizeof(struct s_section_item));
	rval->type=1;
	rval->data=strdup(s);
	//printf("new_section_item__1 %s\n",s);
	return rval;
}


struct s_section_item *new_section_item__2(char *s)  {
	struct s_section_item *rval;
	rval=malloc(sizeof(struct s_section_item));
	rval->type=1;

	//printf("new_section_item__2 %s\n",s);

	rval->data=strdup(s);
	return rval;
}



/*
static int
get_hash_val (char *s)
{
  int c;
  c = toupper (s[0]);
  if (c >= 'A' && c <= 'Z')
    {

      c = c - 'A' + 1;
    }
  else
    {
      c = 0;
    }

  return c;
}
*/

void *A4GL_lexer_get_hashed_list(int a) {
        return (void *)hashed_list[a];
}


char *
get_text (char *s)
{
  static char buff[2000]="";
  //int arr;
  struct s_kw *local_kwords;
  int a;
  int c;
if (nkwords) {
	// Explicit keyword list - rather than the 4gl parser one..
	for (a=0;a<nkwords;a++) {
		if (strcmp(kwords[a].token,s)==0) {
			return kwords[a].text;
		}
	}
}

strcpy(buff,"");
  for (c=0;;c++) {

  	local_kwords = A4GL_lexer_get_hashed_list (c);

	if (local_kwords==0) break;

  for (a = 0; local_kwords[a].id > 0; a++)
    {
      if (strcmp (local_kwords[a].name, s) == 0)
	{
	  int b;
	  if (strlen(buff)) {
			strcat(buff,"|");
	  }

	  for (b = 0; local_kwords[a].vals[b]; b++)
	    {

		  if (b) strcat (buff, " ");
		  else {
			strcat (buff, "\"");
		  }
	      strcat (buff, local_kwords[a].vals[b]);
	    }
	strcat(buff,"\"");
	  //return buff;
	}
    }


    }
  if (strlen(buff)) {
	if (strstr(buff,"|")) {
		char buff2[2000];
	
		sprintf(buff2,"(%s)",buff);
		strcpy(buff,buff2);
	}
		return buff;
	}

  return s;
}


static void trimnl(char *s) {
int a;
for (a=0;a<strlen(s);a++) {
	if (s[a]=='\n' || s[a]=='\r') {
		s[a]=0; break;
	}
}
}
