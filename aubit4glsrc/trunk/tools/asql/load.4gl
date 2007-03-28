
code
/*

struct element {
	int lineno;
	char type;
	char *stmt;
	char *delim;
	char *fname;
};

*/


#include "simple.h"


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


#ifdef MOVED
#define LOADBUFFSIZE 32000
char loadbuff[LOADBUFFSIZE];
#define MAXLOADCOLS 256
#define MAXCOLLENGTH 32
/* Column name list where information is to be loaded */
char col_list[MAXLOADCOLS][MAXCOLLENGTH];
/* Array with pointers to each delimiter in current load line */
char *colptr[MAXLOADCOLS];
#endif



char delims[256];
char *LoadUnload_delim;
//FILE *loadFile=0;

static char *safe_quotes(char *s);

extern FILE *f_unloadFile;



int asql_unload_data(struct element *e, int *errat) {
int raffected;
int b;
	LoadUnload_delim=&delims[0];
	strcpy(LoadUnload_delim,"|");

	if (e->delim) {
		if (strlen(e->delim)) {
			strcpy(LoadUnload_delim,e->delim);
		}
	}

	if (can_do_unload()) {
		raffected=0;
		if (do_unload(e,&raffected)) {
			return raffected;
		} else {
			return 0;
		}
	}

	f_unloadFile=fopen(e->fname,"w");

	if (f_unloadFile==0) {
		set_sqlcode(-806);
		return 0;
	}

	raffected=0;
	display_mode_unload(1);
	if (execute_select_prepare(errat)) {
		while (get_sqlcode()==0) {
			b=execute_sql_fetch(&raffected);
			if (b!=0) break;
		}
		if (get_sqlcode()!=100)  raffected=-1;
	} else {
		raffected=-1;
	}
	if (f_unloadFile) fclose(f_unloadFile);
	f_unloadFile=0;
	display_mode_unload(0);
	return raffected;
}


void
stripnlload (char *s, char delim)
{
  int a;
  a = strlen (s);
  if (s[a - 1] == '\n')
    {
      if (s[a - 2] != delim)
        s[a - 1] = delim;
      else
        s[a - 1] = 0;
    }
}



char *escape_delim(char *s) {
static char*ptr=0;
int a;
int c;
c=0;
for (a=0;a<strlen(s);a++) {
	if (s[a]==LoadUnload_delim[0]) c++;
	if (s[a]=='\\') c++;
}
if (c==0) return s;

if (ptr) free(ptr);

ptr=malloc(strlen(s)+c+1000);

c=0;
for (a=0;a<strlen(s);a++) {
if (s[a]==LoadUnload_delim[0]||s[a]=='\\') {
	ptr[c++]='\\';
}
ptr[c++]=s[a];
}
ptr[c]=0;
return ptr;



}



endcode
