#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileschema.x.h"
#include "a4gl_libaubit4gl.h"

struct s_idx_tables tables;


static int compare_tabnames(const void *va, const void *vb) {
const struct s_idx_table *a;
const struct s_idx_table *b;
a=(const struct s_idx_table *)va;
b=(const struct s_idx_table *)vb;

	return strcmp(a->tablename,b->tablename);
}


static void create_table(char *tableName) {
char buff[200];
int tabid=0;
int partnum=0;
strcpy(buff,tableName);
A4GL_trim(buff);
if (strchr(buff,' ')) {
	char t[200];
	sscanf(buff,"%s %d %d",t,&tabid,&partnum);
	strcpy(buff,t);
}

tables.tables.tables_len++;
tables.tables.tables_val=realloc( tables.tables.tables_val, sizeof(tables.tables.tables_val[0])*tables.tables.tables_len);

tables.tables.tables_val[tables.tables.tables_len-1].tablename=strdup(buff);
tables.tables.tables_val[tables.tables.tables_len-1].tabid=tabid;
tables.tables.tables_val[tables.tables.tables_len-1].partnum=partnum;
tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_len=0;
tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_val=NULL;

}

static void add_to_table(char *colName,int dtype,int size) {
tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_len++;
tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_val=
		realloc(tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_val, 
			tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_len*sizeof(tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_val[0]));
tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_val[tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_len-1].columnName=strdup(colName);
tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_val[tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_len-1].datatype=dtype;
tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_val[tables.tables.tables_val[tables.tables.tables_len-1].columns.columns_len-1].size=size;

}


int main(int argc,char *argv[]) {
char fileName[256];
char fileNameIn[256];
char fileNameOut[256];
char buff[300];
char *ptr;
FILE *fin;
char *ext;
int pastHeader=0;

tables.tables.tables_len=0;
tables.tables.tables_val=NULL;
A4GL_build_user_resources();
ext=acl_getenv_not_set_as_0("A4GL_SCHEMA_EXT");


if (ext==0) {
	ext=".schema";
}

if (argc!=2) {
	printf("Usage :\n %s filename[%s]\n",argv[0],ext);
	exit(2);
}

// remove any existing extension
strcpy(fileName,argv[1]);
ptr=strstr(fileName,ext);

if (ptr) {
	*ptr=0;
}

strcpy(fileNameIn,fileName);
strcpy(fileNameOut,fileName);
// Now - ensure we have a .schema extention
  strcat(fileNameIn,ext);

ext=acl_getenv_not_set_as_0("A4GL_INDXSCHEMA_EXT");
if (ext!=0) {
  strcat(fileNameOut,ext);
} else {
  strcat(fileNameOut,".schidx");
}
  fin=fopen(fileNameIn,"r");

  if (fin==0) {
	fprintf(stderr,"Unable to open input file :%s\n", fileNameIn);
	exit (2);
  }

  rewind (fin);

  while (1)
    {
	char tname[300];
      if (feof (fin)) {
	break;
	}

      strcpy(buff,"");

      if (fgets (buff, 255, fin)==NULL) continue;
      A4GL_trim_nl(buff);
	if (strlen(buff)==0) continue;
      A4GL_debug("%s\n", buff);

      if (buff[0] == '[')
	{
	  char *ptr;
	  strcpy (tname, &buff[1]);
	  ptr = strchr (tname, ']');
	  if (!ptr)
	    {
	      fprintf (stderr, "Parse error in schema file - no ']'");
	      return 0;
	    }

	  *ptr = 0;
	  ptr = strchr (tname, ' ');
	  if (ptr)
	    *ptr = 0;

	create_table(tname);
		pastHeader=1;

	  continue;
	} else {
		char cname[200];
		int dtype;
		int size;
		int a;
  		a = sscanf (buff, "%s %d %d", cname, &dtype, &size);
  		if (a == 3)  {
			add_to_table(cname,dtype&DTYPE_MASK,size);
		} else {
			if (pastHeader) {
				fprintf(stderr,"Cant understand :%s\n", buff);
			}
		}
	}

    }

qsort(tables.tables.tables_val, tables.tables.tables_len, sizeof(tables.tables.tables_val[0]),compare_tabnames);


if (write_s_idx_tables(&tables,fileNameOut)) {
	printf("Processed %d tables\n", tables.tables.tables_len);
	exit(0);
} else {
	exit(1);
	}
}


/* =============================== EOF ============================== */
