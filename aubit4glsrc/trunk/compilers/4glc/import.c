#include <stdio.h>
#include <stdlib.h>
#include "a4gl_4glc_int.h"


enum flist_type {
	FLIST_NORMAL,
	FLIST_SPECIAL
};


struct flist {
	char *name;
	int type;
	char *special;
};


struct file_description {
	char *name;
	struct flist *list;
	int nlist;
};


struct file_description *files=0;
int nfiles=0;



static int has_file(char *s) {
int a;
	if (nfiles==0) return -1;
	for (a=0;a<nfiles;a++) {
		if (strcmp(files[a].name,s)==0) return a;
	}
	return -1;
}

static int add_file(char *s) {
int a;
a=has_file(s);
if (a==-1) {
	a=nfiles;
	nfiles++;
	files=realloc(files,sizeof(struct file_description)*nfiles);
	files[nfiles-1].name=strdup(s);
	files[nfiles-1].list=0;
	files[nfiles-1].nlist=0;
}
return a;
}



int has_function(char *s,char *file,struct flist *ptr) {
int a;
int b;
static char buff[256];
for (a=0;a<nfiles;a++) {
	for (b=0;b<files[a].nlist;b++) {
		if (strcmp(s,files[a].list[b].name)==0) {
			if (file) {
				if (files[a].name[0]!=':') sprintf(buff,"\"%s\"",files[a].name);
				else sprintf(buff,"%s",&files[a].name[1]);
				strcpy(file,buff);
			}
			if (ptr) ptr=&files[a].list[b];
			return 1;

		}
	}
}
return 0;
}

static int add_function(int n, char *func,int type,char *special) {
	int nlist;
	
	nlist=files[n].nlist;
	files[n].nlist++;
	files[n].list=realloc(files[n].list,(nlist+1)*sizeof(struct flist));


	files[n].list[nlist].name=strdup(func);
	files[n].list[nlist].type=type;
	if (special) {
		files[n].list[nlist].special=strdup(special);
	} else {
		files[n].list[nlist].special=0;
	}
	return 1;
}




static int read_package_contents(FILE *f) {
char buff[1024];
char module[128];
char function[128];
int a;
if (f==0) return 0;

while (fgets(buff,255,f)) {
	if (buff[0]=='#') continue;
        sscanf(buff,"%s %s",module,function);
        printf("Import %s, %s\n",module,function);
	a=add_file(module);
	add_function(a,function,FLIST_NORMAL,0);
}

return 1;
}



void import_package(char *s) {
char buff[256];
FILE *f;

sprintf(buff,"%s/import/%s",acl_getenv("AUBITETC"),s);
f=fopen(buff,"r");
	A4GL_debug("Try : %s = %p\n",buff,f);

if (f==0) {
        sprintf(buff,"%s/etc/import/%s",acl_getenv("AUBITDIR"),s);
        f=fopen(buff,"r");
	A4GL_debug("Try : %s = %p\n",buff,f);
}


if (f==0 ) {
	if (strcmp(s,"default") == 0 ) {
		// We don't care if this one isn't there...
		return;
	}

        a4gl_yyerror("Unable to open package description");
        return;
}


read_package_contents(f);

}
