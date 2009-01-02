#include <stdio.h>
#include <stdlib.h>
#include "a4gl_4glc_int.h"

extern struct module_definition this_module;


//struct file_description *files=0;
//int nfiles=0;



static int has_file(char *s) {
int a;
 	
	if (this_module.imported_files.imported_files_len==0) return -1;
	for (a=0;a<this_module.imported_files.imported_files_len;a++) {
		if (A4GL_aubit_strcasecmp(this_module.imported_files.imported_files_val[a].name,s)==0) return a;
	}
	return -1;
}

static int add_file(char *s) {
int a;
a=has_file(s);
if (a==-1) {
	a=this_module.imported_files.imported_files_len;
	this_module.imported_files.imported_files_len++;
	this_module.imported_files.imported_files_val=acl_realloc(this_module.imported_files.imported_files_val,sizeof(struct file_description)*this_module.imported_files.imported_files_len);
	this_module.imported_files.imported_files_val[this_module.imported_files.imported_files_len-1].name=acl_strdup(s);
	this_module.imported_files.imported_files_val[this_module.imported_files.imported_files_len-1].list.list_len=0;
	this_module.imported_files.imported_files_val[this_module.imported_files.imported_files_len-1].list.list_val=0;
}
return a;
}


#ifdef MOVED
int has_function(char *s,char *file,struct flist *ptr) {
int a;
int b;
static char buff[256];
for (a=0;a<this_module.imported_files.imported_files_len;a++) {
	for (b=0;b<this_module.imported_files.imported_files_val[a].list.list_len;b++) {
		if (A4GL_aubit_strcasecmp(s,this_module.imported_files.imported_files_val[a].list.list_val[b].name)==0) {
			if (file) {
				if (this_module.imported_files.imported_files_val[a].name[0]!=':') SPRINTF1 (buff,"\"%s\"",this_module.imported_files.imported_files_val[a].name);
				else SPRINTF1 (buff,"%s",&this_module.imported_files.imported_files_val[a].name[1]);
				strcpy(file,buff);
			}
			if (ptr) ptr=&this_module.imported_files.imported_files_val[a].list.list_val[b];
			return 1;
		}
	}
}
return 0;
}
#endif


static int add_function(int n, char *func,int type,char *special) {
	int nlist;
	nlist=this_module.imported_files.imported_files_val[n].list.list_len;
	this_module.imported_files.imported_files_val[n].list.list_len++;
	this_module.imported_files.imported_files_val[n].list.list_val=acl_realloc(this_module.imported_files.imported_files_val[n].list.list_val,(nlist+1)*sizeof(struct flist));


	this_module.imported_files.imported_files_val[n].list.list_val[nlist].name=acl_strdup(func);
	this_module.imported_files.imported_files_val[n].list.list_val[nlist].type=type;

	if (special) {
		this_module.imported_files.imported_files_val[n].list.list_val[nlist].special=acl_strdup(special);
	} else {
		this_module.imported_files.imported_files_val[n].list.list_val[nlist].special=0;
	}
	return 1;
}




int read_package_contents(FILE *f) {
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

#ifdef MOVED
int A4GL_open_class_dll(char *s) {
char buff[512];
FILE *f;
strcpy(buff,s);
strcat(buff,acl_getenv("A4GL_DLL_EXT"));
A4GL_debug("Looking for : %s\n",buff);
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
	if (A4GL_aubit_strcasecmp(s,"default") == 0 ) {
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
#endif
