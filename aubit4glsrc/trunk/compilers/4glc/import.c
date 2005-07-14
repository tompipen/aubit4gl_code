#include <stdio.h>
#include <stdlib.h>
#include "a4gl_4glc_int.h"



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
	files=acl_realloc(files,sizeof(struct file_description)*nfiles);
	files[nfiles-1].name=acl_strdup(s);
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
	files[n].list=acl_realloc(files[n].list,(nlist+1)*sizeof(struct flist));


	files[n].list[nlist].name=acl_strdup(func);
	files[n].list[nlist].type=type;
	if (special) {
		files[n].list[nlist].special=acl_strdup(special);
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
        A4GL_debug("Import %s, %s\n",module,function);
	a=add_file(module);
	add_function(a,function,FLIST_NORMAL,0);
}

return 1;
}

int A4GL_open_class_dll(char *s) {
char buff[512];
FILE *f;
strcpy(buff,s);
strcat(buff,acl_getenv("A4GL_DLL_EXT"));
printf("Looking for : %s\n",buff);
f=A4GL_open_file_classpath(buff);

if (f) { // We've found our dll...
	fclose(f);
	// 
	read_class(s,0);
} else {
	return 0;
}


return 1;
}


void import_package(char *s) {
FILE *f;
f=A4GL_open_file_classpath(s);
if (f==0 ) {
	int ok=0;
	if (strcmp(s,"default") == 0 ) {
		// We don't care if this one isn't there...
		return;
	}

	ok=A4GL_open_class_dll(s) ;

	if (!ok) {
        	a4gl_yyerror("Unable to open package description");
	}
        return;
}
read_package_contents(f);

}
