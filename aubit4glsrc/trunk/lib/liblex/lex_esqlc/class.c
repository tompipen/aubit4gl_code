#include <stdio.h>
#include <string.h>

#include "a4gl_lib_lex_esqlc_int.h"

extern char infilename[];
struct s_method {
	char *name;
	char *sig;
};

struct s_method *methods=0;
int nmethods=0;

struct s_parent_method {
	char *name;
	char *sig;
};

struct s_parent_method *parent_methods=0;
int nparent_methods=0;


char class_name[256]="";
char parent_name[256]="";

void CLASS_set_class_name(char *name) {
char buff[1024];
char *ptr;
ptr=strrchr(infilename,"/");
if (ptr) {
	ptr++;
} else {
	ptr=infilename;
}
strcpy(buff,ptr);

ptr=strrchr(buff,'.');
if (ptr) { *ptr=0; }
	A4GL_convlower(name);
	strcpy(class_name,name);
	if (infilename) {
		printf("%s\n",name);
		printf("%s\n",infilename);
		printf("%s\n",buff);
	}
	if (strcmp(buff,name)!=0) {
		printf("WARNING : Class names to not match filename\n");
		exit(2);
	}
}

void CLASS_set_parent_name(char *name) {
	A4GL_convlower(name);
	strcpy(parent_name,name);
}


void CLASS_add_method(char *name,char *sig) {
nmethods++;
methods=realloc(methods,sizeof(struct s_method)*nmethods);
methods[nmethods-1].name=strdup(name);
methods[nmethods-1].sig=strdup(sig);
}



void CLASS_print_reflector() {
int a;
int b;
char **parents;
int nparents;
printc("");
printcomment("/* Parent Members */");
if (strlen(parent_name)) {
	char **buff;
	int redirect=0;
	parents=CLASS_get_members (parent_name);
	if (parents==-1) { 
		nparents=0;
	} else {
		for (a=0;parents[a];a++) ;
		nparents=a;
	}
	buff=malloc(nparents*sizeof(char *));
	memcpy(buff,parents,nparents*sizeof(char *));
	printf("Parent has %d methods\n",nparents);

	for (a=0;a<nparents;a++)  {
		redirect=1;
		A4GL_debug("   %s\n",parents[a]);
		for (b=0;b<nmethods;b++) {
			if (strcmp(parents[a],methods[b].name)==0) { // We're overloading
				redirect=0;
				break;
			} 
			
		}
		if (redirect==1) {
			CLASS_add_method(parents[a],"") ;
			printc("int aclfgl_%s(int n) { printf(\"REDIRECT : %%s %%s %%d\",\"%s\",\"%s\",n);}",parents[a],parent_name,parents[a]);
		}
	}
}



printc("int aclfglclass__sizeof(){ return sizeof(struct this_class_var);}");
printc("char *aclfglclass__alloc(){ return malloc(aclfglclass__sizeof());}");
printc("void aclfglclass__free(void *ptr) { free(ptr);}");
printc("void aclfglclass__copy(void *dest,void *src) { memcpy(dest,src,aclfglclass__sizeof());}");
printc("char *aclfglclass__parent(){ static char *tmp=\"%s\"; return tmp;}",parent_name);





printc("char **aclfglclass__methods() {");
printc("static char *tmp[]={");
for (a=0;a<nmethods;a++) {
	printc("%c\"%s\"",a?',':' ',methods[a].name);
}

printc(",0}; return tmp;}");

}



void CLASS_print_class_variable_type(char *s) {
char *ptr;
char *ptr2;
char *news;
news=malloc(strlen(s)+2);
strcpy(news,s);
strcat(news,"\n");
ptr=news;
ptr2=strchr(ptr,'\n');
printc("char **aclfglclass__get_variable(void) {");
printc("static char *tmp[]={");
while (ptr2) {
	*ptr2=0;
	if (strlen(ptr)) printc("   \"%s\",",ptr);
	ptr=ptr2+1;
	ptr2=strchr(ptr,'\n');
}
printc("0};");
printc("return tmp;");
printc("}");
free(news);
}


char ** CLASS_get_variable (char *s) {
char **b;
b=(char **)A4GL_call_4gl_dll (s, "aclfglclass__get_variable", 0);
return b;
}

char ** CLASS_get_members (char *s) {
char **b;
b=(char **)A4GL_call_4gl_dll (s, "aclfglclass__methods", 0);
return b;
}
