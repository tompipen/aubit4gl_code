
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
#define MAXLOADCOLS 256
#define MAXCOLLENGTH 32
#define LOADBUFFSIZE 32000


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* Buffer that contains the current line being loaded */
char loadbuff[LOADBUFFSIZE];

/* Column name list where information is to be loaded */
char col_list[MAXLOADCOLS][MAXCOLLENGTH];

/* Array with pointers to each delimiter in current load line */
char *colptr[MAXLOADCOLS];



extern FILE *unloadFile;
char delims[256];
char *delim;
FILE *loadFile=0;




int asql_unload_data(struct element *e) {
int raffected;
int b;
	delim=&delims[0];
	strcpy(delim,"|");

	if (e->delim) {
		if (strlen(e->delim)) {
			strcpy(delim,e->delim);
		}
	}

	unloadFile=fopen(e->fname,"w");

	if (unloadFile==0) {
		sqlca.sqlcode=-806;
		return 0;
	}

	raffected=0;
	display_mode_unload(1);
	if (execute_select_prepare()) {
		while (sqlca.sqlcode==0) {
			b=execute_sql_fetch(&raffected);
			if (b!=0) break;
		}
		if (sqlca.sqlcode!=100)  raffected=-1;
	} else {
		raffected=-1;
	}
	if (unloadFile) fclose(unloadFile);
	unloadFile=0;
	display_mode_unload(0);
	return raffected;
}

static int
find_delims (char delim)
{
  int cnt = 1;
  int a;
  colptr[0] = &loadbuff[0];

  for (a = 0; a < strlen (loadbuff); a++)
    {
      if ((loadbuff[a] == delim && loadbuff[a-1]!='\\') || loadbuff[a] == 0)
        {
          colptr[cnt++] = &loadbuff[a + 1];
        }
    }

  cnt--;

  for (a = 1; a <= cnt; a++)
    *(colptr[a] - 1) = 0;

  for (a = 0; a < cnt; a++)
    {
      A4GL_debug ("Field %d = %s", a, colptr[a]);
    }
  return cnt;
}

static void
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


int asql_load_data(struct element *e) {
EXEC SQL BEGIN DECLARE SECTION;
char ins_str[32000];
EXEC SQL END DECLARE SECTION;
int raffected;
int b;
int a;
int ok;
char smbuff[2048];

int nfields;
int lineno=0;
        delim=&delims[0];
        strcpy(delim,"|");

	if (loadFile) fclose(loadFile);

        if (e->delim) {
                if (strlen(e->delim)) {
                        strcpy(delim,e->delim);
                }
        }

        loadFile=fopen(e->fname,"r");

        if (loadFile==0) {
		sqlca.sqlcode=-805;
                return 0;
        }
	ok=0;

	while (1) {
      		fgets (loadbuff, LOADBUFFSIZE - 1, loadFile);
	        if (feof (loadFile)) {
          		A4GL_debug ("Got to end of the file");
          		break;
        	}
      		lineno++;
		stripnlload (loadbuff, delim[0]);
		nfields = find_delims (delim[0]);
		sprintf(ins_str,e->stmt);
		strcat(ins_str," values (");
		for (a=0;a<nfields;a++) {
			if (a) strcat(ins_str,",");
			sprintf(smbuff,"'%s'",safe_quotes(colptr[a]));
			if (strcmp(smbuff,"''")==0) {strcpy(smbuff,"NULL");}
			strcat(ins_str,smbuff);
		}
		strcat(ins_str,")");

		EXEC SQL prepare p_loadit from :ins_str;
		EXEC SQL execute p_loadit;
		if (sqlca.sqlcode!=0) {
			break;
		}
	}
	fclose(loadFile);
	loadFile=0;
	return lineno;

}


static char *safe_quotes(char *s) {
static char *p=0;
char *p2=0;
static int plen=0;
int a;
int c=0;

if(strlen(s)>plen) {
	plen=strlen(s);
	p=realloc(p,plen+1000);
}

c=0;
for (a=0;a<strlen(s);a++) {
	if (s[a]!='\\')   {p[c++]=s[a];continue;}
	continue;
}
p[c]=0;
p2=strdup(p);

c=0;
// First - escape any quotes
for(a=0;a<strlen(p2);a++) {
		if (p2[a]!='\'') {p[c++]=p2[a];continue;}
		p[c++]='\\';
		p[c++]='\'';
}
p[c]=0;
free(p2);
return p;
}




char *escape_delim(char *s) {
static char*ptr=0;
int a;
int c;
c=0;
for (a=0;a<strlen(s);a++) {
	if (s[a]==delim[0]) c++;
	if (s[a]=='\\') c++;
}
if (c==0) return s;

if (ptr) free(ptr);

ptr=malloc(strlen(s)+c+1000);

c=0;
for (a=0;a<strlen(s);a++) {
if (s[a]==delim[0]||s[a]=='\\') {
	ptr[c++]='\\';
}
ptr[c++]=s[a];
}
ptr[c]=0;
return ptr;



}



endcode
