%{

#define _BISON_SIMPLE_INCL_

#define _NO_FORM_X_H_
#define _NO_WINDOWS_H_

/* FIXME: this should be a4gl_xgen_int.h */
#define NOSTRCPYMAP
#include "a4gl_libaubit4gl.h"

#define YYDEBUG 1
int lineno=0;
int colno=0;
int enumv=0;
FILE *cfo;
FILE *cfio;
FILE *cfi;
FILE *hf;
FILE *hsf;
FILE *ccrf;

char sw_elem[256];

struct mode {
	int pointer;
	int type;
	int size;
	char name[128];
};


char cu[20][256]={"",""};
int cu_cnt=0;

extern void yyerror (char *s); /* in main.c */
int 	yylex 			(void);
int buffpos(void);

void print_elem_out(char *type,char *s,struct mode m);
void print_elem_in(char *type,char *s,struct mode m);
void print_elem_sh(char *type,char *s,struct mode m);
void print_elem(char *type,char *s,struct mode m);

void print_elem(char *type,char *s,struct mode m) {
	print_elem_out(type,s,m);
	print_elem_in(type,s,m);
	print_elem_sh(type,s,m);
}


void print_elem_sh(char *type,char *s,struct mode m) {
char buff[256];
char buff2[256];



if (strcmp(type,"string")==0) { m.type=0; }
if (
strcmp(type,"struct")==0||
strcmp(type,"istypedefed")==0||
strcmp(type,"enum")==0||
strcmp(type,"union")==0
) {
	sprintf(buff,"%s %s",type,s);
} else  {
	if (strcmp(type,"string")==0) {
		strcpy(buff,"char *");
	} else {
		strcpy(buff,type);
	}
}

if (m.pointer) { strcat(buff," *"); }
if (m.type==1) { strcat(buff," *"); }

strcat(buff," ");
strcat(buff,m.name);
if (m.type==2) { sprintf(buff2,"[%d]",m.size); strcat(buff,buff2);}

if (m.type==0) {
	fprintf(hsf,"%s;\n",buff);
	return;
}


if (m.type==1) { 
	fprintf(hsf,"struct {\n"); 
	fprintf(hsf," unsigned int %s_len;\n",m.name);
	fprintf(hsf," %s_val;\n",buff);
	fprintf(hsf,"} %s;\n",m.name);
	return;
}

if (m.type==2) {
	fprintf(hsf,"%s;\n",buff);
	return;
}


fprintf(hsf,"/* %s %s mt=%d ms=%d mn=%s mp=%d */\n",type,s,m.type,m.size,m.name,m.pointer);

return;
	if (m.type==0) {
		
		fprintf(hsf,"/* %s %s mt=%d ms=%d mn=%s mp=%d */\n",type,s,m.type,m.size,m.name,m.pointer);
	}

	if (m.type==1) {
		fprintf(hsf,"/* %s %s mt=%d ms=%d mn=%s mp=%d */\n",type,s,m.type,m.size,m.name,m.pointer);
	}

	if (m.type==2) {
		fprintf(hsf,"/* %s %s mt=%d ms=%d mn=%s mp=%d */\n",type,s,m.type,m.size,m.name,m.pointer);
	}

	if (m.type==3) {
		fprintf(hsf,"/* %s %s mt=%d ms=%d mn=%s mp=%d */\n",type,s,m.type,m.size,m.name,m.pointer);
	}
}

void print_elem_out(char *type,char *s,struct mode m) {
char buff[256];
if (strcmp(type,"string")==0) { m.type=0; }

sprintf(buff,"%s%s /* cu_cnt=%d */",cu[cu_cnt],m.name,cu_cnt);

/* Simple types */
	if (m.type==0) {
		if (m.pointer==0) fprintf(cfo,"   if (!output_%s(\"%s\",r.%s,0,-1)) return 0;\n",s,m.name,buff);
		if (m.pointer==1) {
			fprintf(cfo,"   if (r.%s) {output_okptr(\"%s\");if (!output_%s(\"%s\",*r.%s,1,-1)) return 0;}\n",buff,m.name,s,m.name,buff);
			fprintf(cfo,"   else      {if (!output_nullptr(\"%s\")) return 0;}\n",m.name);

			/*to prevent control reaches end of non-void function warning: */
			/*fprintf(cfo,"return 99;\n"); */
		}
		return;
	}

/* Flexible length array */
	if (m.type==1) {
		fprintf(cfo,"   if (!output_start_array(\"%s\",1,r.%s.%s_len)) return 0;\n",m.name,buff,m.name);
		fprintf(cfo,"   {\n");
		fprintf(cfo,"      int cnt;\n");
	        fprintf(cfo,"      for (cnt=0;cnt<r.%s.%s_len;cnt++) {\n",buff,m.name);
		if (m.pointer==0) fprintf(cfo,"         if (!output_%s(\"%s\",r.%s.%s_val[cnt],0,cnt)) return 0;\n",s,m.name,buff,m.name);
		if (m.pointer==1) {
			fprintf(cfo,"   if (r.%s.%s_val[cnt]) {output_okptr(\"%s\");if (!output_%s(\"%s\",*r.%s.%s_val[cnt],1,cnt)) return 0;}\n",
				buff,m.name,m.name,
				s,m.name,buff,m.name);
			fprintf(cfo,"   else     { if (!output_nullptr(\"%s\")) return 0;}\n",m.name);
		}
	        fprintf(cfo,"      }\n");
		fprintf(cfo,"   }\n");
		fprintf(cfo,"   if (!output_end_array(\"%s\",1)) return 0;\n",s);
		/*to prevent control reaches end of non-void function warning: */
		/*fprintf(cfo,"return 98;\n"); */

		return;
	}

/* Fixed length array */
	if (m.type==2) { 
		fprintf(cfo,"   if (!output_start_array(\"%s\",2,%d)) return 0;\n",m.name,m.size);
		fprintf(cfo,"   {\n");
		fprintf(cfo,"      int cnt;\n");
	        fprintf(cfo,"      for (cnt=0;cnt<%d;cnt++) {\n",m.size);
		if (m.pointer==0) fprintf(cfo,"   if (!output_%s(\"%s\",r.%s[cnt],0,-1)) return 0;\n",s,m.name,m.name);
		if (m.pointer==1) {
			fprintf(cfo,"   if (r.%s[cnt]) {output_okptr(\"\");if (!output_%s(\"%s\",*r.%s[cnt],0,cnt)) return 0;}\n",m.name,s,m.name,m.name);
			fprintf(cfo,"   else      {if (!output_nullptr(\"%s\")) return 0;}\n",m.name);
		}
		fprintf(cfo,"      }\n");
		fprintf(cfo,"   }\n");
		fprintf(cfo,"   if (!output_end_array(\"%s\",2)) return 0;\n",s);
		/*to prevent control reaches end of non-void function warning: */
		/*fprintf(cfo,"return 97;\n"); */
		return;
	}

	if (m.type==3) {
		if (m.pointer==0) {
				fprintf(cfo,"   if (!output_%s(\"%s\",r,0,-1)) return 0;\n",s,m.name); /* ,buff); */
				/*to prevent warning: */
				fprintf(cfo,"return 0;\n");
        }
		if (m.pointer==1) {
			fprintf(cfo,"   if (r) {output_okptr(\"\");if (!output_%s(\"%s\",*r,1,-1)) return 0;}\n",buff,s); /* ,m.name,buff); */
			fprintf(cfo,"   else      {if (!output_nullptr(\"%s\")) return 0;}\n",m.name);

			/*to prevent control reaches end of non-void function warning: (OK) */
			fprintf(cfo,"return 96;\n");


		}
		return;
	}

	printf("Unable to handle %s %s\n",type,s);
	exit(0);

}

void print_elem_in(char *type,char *s,struct mode m) {
char buff[256];
if (strcmp(type,"string")==0) { m.type=0; }
sprintf(buff,"%s%s",cu[cu_cnt],m.name);


/* Simple types */
	if (m.type==0) {
		if (m.pointer==0) fprintf(cfi,"   if (!input_%s(\"%s\",&r->%s,0,-1)) return 0;\n",s,m.name,buff);
		if (m.pointer==1) {
			fprintf(cfi,"\n   if (!input_ptr_ok()) r->%s=0;\n",buff); 
			fprintf(cfi,"   else r->%s=acl_malloc2(sizeof(%s));\n",buff,s); 
			fprintf(cfi,"   if (!input_%s(\"%s\",r->%s,1,-1)) return 0;\n\n",s,m.name,buff);
		}
		return;
	}

/* Flexible length array */
	if (m.type==1) { 
		fprintf(cfi,"   if (!input_start_array(\"%s\",1,&r->%s.%s_len)) return 0;\n",m.name,buff,m.name);
		fprintf(cfi,"   {\n");
		fprintf(cfi,"      int cnt; if (r->%s.%s_len) {\n",buff,m.name);
	        fprintf(cfi,"      r->%s.%s_val=acl_malloc2(r->%s.%s_len*sizeof(r->%s.%s_val[0]));\n", buff,m.name, buff,m.name, buff,m.name);
	        fprintf(cfi,"      for (cnt=0;cnt<r->%s.%s_len;cnt++) {\n",buff,m.name);
		if (m.pointer==0) fprintf(cfi,"         if (!input_%s(\"%s\",(void *)&r->%s.%s_val[cnt],0,cnt)) return 0; /*MJALI2*/\n",s,m.name,buff,m.name);
		if (m.pointer==1) {
			fprintf(cfi,"\n   if (!input_ptr_ok()) r->%s.%s_val[cnt]=0;\n",buff,m.name);
			fprintf(cfi,"   else r->%s.%s_val[cnt]=acl_malloc2(sizeof(%s));\n",buff,m.name,s);
			fprintf(cfi,"   if (!input_%s(\"%s\",&r->%s.%s_val[cnt],1,cnt)) return 0; /*MJALI1*/\n\n",
				s,m.name,buff,m.name);
		}
	        fprintf(cfi,"      }\n");
	        fprintf(cfi,"   } else {r->%s.%s_val=0;}\n",buff,m.name);
		fprintf(cfi,"   }\n");
		fprintf(cfi,"   if (!input_end_array(\"%s\",1)) return 0;\n",s);
		return;
	}

/* Fixed length array */
	if (m.type==2) { 
		fprintf(cfi,"   {\n");
		fprintf(cfi,"      int cnt,mcnt;\n");
		fprintf(cfi,"   if (!input_start_array(\"%s\",2,&mcnt)) return 0;\n",m.name);
	        fprintf(cfi,"      for (cnt=0;cnt<mcnt;cnt++) {\n");
		if (m.pointer==0) fprintf(cfi,"   if (!input_%s(\"%s\",&r->%s[cnt],0,-1)) return 0;/*MJALI3*/\n",s,m.name,buff);
		if (m.pointer==1) {
			fprintf(cfi,"\n   if (!input_ptr_ok()) r->%s[cnt]=0;\n",m.name);
			fprintf(cfi,"   else r->%s[cnt]=acl_malloc2(sizeof(%s));\n",m.name,s);
			fprintf(cfi,"   if (!input_%s(\"%s\",&r->%s[cnt],0,cnt)) return 0;\n\n",s,m.name,buff);
		}
		fprintf(cfi,"      }\n");
		fprintf(cfi,"   }\n");
		fprintf(cfi,"   if (!input_end_array(\"%s\",2)) return 0;\n",s);
		return;
	}

/* typedefs */
	if (m.type==3) {
		if (m.pointer==0) {
			fprintf(cfi,"   if (!input_%s(\"%s\",&r,0,-1)) return 0;\n",m.name,buff);
			/*to prevent warning: */
			fprintf(cfi,"return 0;\n");
        }
		if (m.pointer==1) {
			fprintf(cfi,"   if (!input_%s(\"%s\",r,1,-1)) return 0;\n",m.name,buff);
			/*to prevetn warning: */
			fprintf(cfi,"return 0;\n");
		}
		return;
	}

	printf("Unable to handle %s %s\n",type,s);
	exit(0);

}





%}
%start x



%union    {
        char    str[1024];
	struct mode mode;
}

%token OPEN_BRACE
%token CLOSE_BRACE
%token CONST
%token ENUM
%token COMMA
%token SEMICOLON
%token STRUCT
%token STAR
%token VOID
%token NAMED
%token UNION
%token SWITCH
%token TYPEDEF
%token OPEN_BRACKET
%token CLOSE_BRACKET
%token CASE
%token COLON
%token LESS_THAN
%token GREATER_THAN
%token STRING
%token INT
%token LONG
%token SHORT
%token DOUBLE
%token OPAQUE
%token BOOL
%token OPEN_SQUARE
%token CLOSE_SQUARE
%token INT_VAL
%token STRING_VAL
%token NUMBER_VAL
%token EQUAL
%token CH
%token HEX_INT_VAL
%token PROGRAM
%token VERSION
%%

x: xset | x xset
;

xset: 	  struct
	| union
	| const
	| enum
	| typedef
	| program
;


typedef:
	TYPEDEF typedef_elem SEMICOLON
;

typedef_elem:
	STRUCT NAMED STAR NAMED {
		fprintf(hf,"int output_%s(char *rn,struct %s *r,int isptr,int arr) ; /* typedef */\n",$<str>4,$<str>2);
		fprintf(cfo,"int output_%s(char *rn,struct %s *r,int isptr,int arr) { /* typedef */\n",$<str>4,$<str>2);

		fprintf(hf,"int input_%s(char *rn,struct %s *r,int isptr,int arr) ; /* typedef */\n",$<str>4,$<str>2);
		fprintf(cfi,"int input_%s(char *rn,struct %s *r,int isptr,int arr) { /* typedef */\n",$<str>4,$<str>2);

		$<mode>$.type=3; $<mode>$.size=0; $<mode>$.pointer=1; strcpy($<mode>$.name,$<str>2);
		print_elem("struct",$<str>2,$<mode>$); 
		fprintf(cfo,"}\n");
		fprintf(cfi,"}\n");
		fprintf(hsf,"typedef struct %s %s %s;\n",$<str>2,$<str>3,$<str>4);
	}
		
	| STRUCT NAMED NAMED {
		fprintf(hf,"int input_%s(char *rn,struct %s r,int isptr,int arr) ; /* typedef */\n",$<str>3,$<str>2);
		fprintf(cfi,"int input_%s(char *rn,struct %s r,int isptr,int arr) { /* typedef */\n",$<str>3,$<str>2);
		fprintf(hf,"int output_%s(char *rn,struct %s r,int isptr,int arr) ; /* typedef */\n",$<str>3,$<str>2);
		fprintf(cfo,"int output_%s(char *rn,struct %s r,int isptr,int arr) { /* typedef */\n",$<str>3,$<str>2);
		$<mode>$.type=3; $<mode>$.size=0; $<mode>$.pointer=0; strcpy($<mode>$.name,$<str>2);
		print_elem("struct",$<str>2,$<mode>$); 
		fprintf(cfo,"}\n");
		fprintf(cfi,"}\n");
		fprintf(hsf,"typedef %s %s;\n",$<str>2,$<str>3);
	}
	| UNION NAMED NAMED {
		fprintf(hf,"int input_%s(char *rn,struct %s r,int isptr,int arr) ;\n /* typedef */",$<str>3,$<str>2);
		fprintf(cfi,"int input_%s(char *rn,struct %s r,int isptr,int arr) {\n /* typedef */",$<str>3,$<str>2);
		fprintf(hf,"int output_%s(char *rn,struct %s r,int isptr,int arr) ;\n /* typedef */",$<str>3,$<str>2);
		fprintf(cfo,"int output_%s(char *rn,struct %s r,int isptr,int arr) {\n /* typedef */",$<str>3,$<str>2);
		$<mode>$.type=3; $<mode>$.size=0; $<mode>$.pointer=0; strcpy($<mode>$.name,$<str>2);
		print_elem("struct",$<str>2,$<mode>$); 
		fprintf(cfo,"}\n");
		fprintf(cfi,"}\n");
		fprintf(hsf,"typedef %s %s;\n",$<str>2,$<str>3);
	}
	| UNION NAMED STAR NAMED {
		fprintf(hf,"int input_%s(char *rn,struct %s *r,int isptr,int arr) ; /* typedef */\n",$<str>4,$<str>2);
		fprintf(cfi,"int input_%s(char *rn,struct %s *r,int isptr,int arr) { /* typedef */\n",$<str>4,$<str>2);
		fprintf(hf,"int output_%s(char *rn,struct %s *r,int isptr,int arr) ; /* typedef */\n",$<str>4,$<str>2);
		fprintf(cfo,"int output_%s(char *rn,struct %s *r,int isptr,int arr) { /* typedef */\n",$<str>4,$<str>2);
		$<mode>$.type=3; $<mode>$.size=0; $<mode>$.pointer=1; strcpy($<mode>$.name,$<str>2);
		print_elem("struct",$<str>2,$<mode>$); 
		fprintf(cfo,"}\n");
		fprintf(cfi,"}\n");
		fprintf(hsf,"typedef %s %s %s;\n",$<str>2,$<str>3,$<str>4);
	}
	| INT NAMED { fprintf(hsf,"typedef %s %s;\n",$<str>1,$<str>2); }
	| LONG NAMED { fprintf(hsf,"typedef %s %s;\n",$<str>1,$<str>2); }
	| STRING NAMED LESS_THAN GREATER_THAN {fprintf(hsf,"typedef char *%s;\n",$<str>2);}
;

enum: ENUM NAMED {
	cu_cnt++;
	strcpy(cu[cu_cnt],"");
	enumv=0;
	fprintf(hf,"int output_%s(char *rn,int r,int isptr,int arr);\n",$<str>2);
	fprintf(cfo,"int output_%s(char *rn,int r,int isptr,int arr){\n",$<str>2);

	fprintf(hf,"int input_%s(char *rn,enum %s *r,int isptr,int arr);\n",$<str>2,$<str>2);
	fprintf(cfi,"int input_%s(char *rn,enum %s *r,int isptr,int arr){\n",$<str>2,$<str>2);

	fprintf(cfo,"char *name=\"%s\";\nA4GL_debug(\"Writing %s\");\n",$<str>2,$<str>2);
/*	fprintf(cfi,"char *name=\"%s\";\n",$<str>2); */

	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",$<str>2);

	fprintf(hsf,"enum %s {",$<str>2);
	} OPEN_BRACE enum_list CLOSE_BRACE SEMICOLON {
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"   if (!input_enum(name,(int *)r)) return 0;\nreturn 1;\n}\n\n");
	fprintf(hsf,"\n};\ntypedef enum %s %s;\n\n",$<str>2,$<str>2);
	cu_cnt--;
}
;

enum_list: enum_element | enum_list COMMA enum_element
;

enum_element: NAMED {
		fprintf(cfo,"if (r==%d) {\n", enumv);
		fprintf(cfo,"  if (!output_enum(name,\"%s\",%d)) return 0;\n",$<str>1,enumv);
		fprintf(cfo,"}\n");

		/*fprintf(cfi,"if (r==%d) {\n", enumv); */
		/*fprintf(cfi,"  if (!input_enum(name,\"%s\",%d)) return 0;\n",$<str>1,enumv); */
		/*fprintf(cfi,"}\n"); */

		if (enumv) fprintf(hsf,",\n");
		else       fprintf(hsf,"\n");
		fprintf(hsf," %s = %d ",$<str>1,enumv);

		enumv++; 
	}
	| NAMED EQUAL INT_VAL {
		enumv=atoi($<str>3);
		fprintf(cfo,"if (r==%d) {\n", enumv);
		fprintf(cfo,"  if (!output_enum(name,\"%s\",%d)) return 0;\n",$<str>1,enumv);
		fprintf(cfo,"}\n");

		/*fprintf(cfi,"if (r==%d) {\n", enumv); */
		/*fprintf(cfi,"  if (!input_enum(name,\"%s\",%d)) return 0;\n",$<str>1,enumv); */
		/*fprintf(cfi,"}\n"); */
		
		if (enumv) fprintf(hsf,",\n");
		else       fprintf(hsf,"\n");
		fprintf(hsf," %s = %d ",$<str>1,enumv);

		enumv++; 
	}
;


const: CONST NAMED EQUAL value SEMICOLON {
	fprintf(hsf,"#define %s %s\n",$<str>2,$<str>4);
	}
 
;

value: INT_VAL | NAMED | string | NUMBER_VAL | HEX_INT_VAL
;

struct: STRUCT NAMED {
	cu_cnt++;
	strcpy(cu[cu_cnt],"");
	fprintf(hsf,"struct %s {\n",$<str>2);
	fprintf(hf,"int output_%s(char *rn,%s r,int isptr,int arr);\n",$<str>2,$<str>2);
	fprintf(cfo,"int output_%s(char *rn,%s r,int isptr,int arr) {\n",$<str>2,$<str>2);
	
/*	fprintf(cfo,"char *name=\"%s\";\n",$<str>2); */

    /* sepatately defining and initialising to prevent compiler watnings about
    unised variable: */
	fprintf(cfo,"char *name;\n");
	fprintf(cfo,"name=\"%s\";\n",$<str>2);

	fprintf(cfo,"if (!output_start_struct(\"%s\",rn,isptr,arr)) return 0;\n",$<str>2);

	fprintf(hf,"int input_%s(char *rn,%s *r,int isptr,int arr);\n",$<str>2,$<str>2);
	fprintf(cfi,"int input_%s(char *rn,%s *r,int isptr,int arr) {\n",$<str>2,$<str>2);
/*	fprintf(cfi,"char *name=\"%s\";\n",$<str>2); */
	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",$<str>2);


	fprintf(cfi,"if (isptr==1&&r==0) return 1; /* Its just a null pointer */\n"); /* ,$<str>2); */

	fprintf(cfi,"if (!input_start_struct(\"%s\",rn,isptr,arr)) return 0;\n",$<str>2);


} OPEN_BRACE struct_list CLOSE_BRACE SEMICOLON {
	fprintf(cfo,"if (!output_end_struct(\"%s\",rn)) return 0;\n",$<str>2);
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"if (!input_end_struct(\"%s\",rn)) return 0;\n",$<str>2);
	fprintf(cfi,"return 1;\n}\n\n");
	fprintf(hsf,"};\ntypedef struct %s %s;\n\n",$<str>2,$<str>2);
	cu_cnt--;
}

; 
struct_list: struct_element | struct_list struct_element
;

vname:    NAMED {
		$<mode>$.pointer=0;
		$<mode>$.type=0;
		$<mode>$.size=-1;
		strcpy($<mode>$.name,$<str>1);
	}
	| NAMED LESS_THAN GREATER_THAN {
		$<mode>$.pointer=0;
		$<mode>$.type=1;
		$<mode>$.size=-1;
		strcpy($<mode>$.name,$<str>1);
	}
	| NAMED OPEN_SQUARE INT_VAL CLOSE_SQUARE {
		$<mode>$.pointer=0;
		$<mode>$.type=2;
		$<mode>$.size=atoi($<str>3);
		strcpy($<mode>$.name,$<str>1);
	}
	| STAR NAMED  {
		$<mode>$.pointer=1;
		$<mode>$.type=0;
		$<mode>$.size=-1;
		strcpy($<mode>$.name,$<str>2);
	}
	| STAR NAMED LESS_THAN GREATER_THAN {
		$<mode>$.pointer=1;
		$<mode>$.type=1;
		$<mode>$.size=-1;
		strcpy($<mode>$.name,$<str>2);
	}
	| STAR NAMED OPEN_SQUARE INT_VAL CLOSE_SQUARE {
		$<mode>$.pointer=1;
		$<mode>$.type=2;
		$<mode>$.size=atoi($<str>4);
		strcpy($<mode>$.name,$<str>2);
	}
;

struct_element : element SEMICOLON 
;


element:
	ENUM NAMED vname  	{ print_elem("enum",$<str>2,$<mode>3); }
	| STRUCT NAMED vname 	{ print_elem("struct",$<str>2,$<mode>3); }
	| UNION NAMED vname 	{ print_elem("struct",$<str>2,$<mode>3); }
	| NAMED vname 		{ print_elem("istypedefed",$<str>1,$<mode>2); }
	| BOOL vname 		{ print_elem("bool","bool",$<mode>2); }
	| INT vname 		{ print_elem("int","int",$<mode>2); }
	| LONG vname 		{ print_elem("long","long",$<mode>2); }
	| SHORT vname 		{ print_elem("short","short",$<mode>2); }
	| STRING vname 		{ print_elem("string","string",$<mode>2); }
	| OPAQUE vname 		{ print_elem("opaque","opaque",$<mode>2); }
	| DOUBLE vname 		{ print_elem("double","double",$<mode>2); }
;



switch_element:
	NAMED NAMED { 
		fprintf(cfo,"if (!output_%s(\"%s\",r.%s,isptr,arr)) return 0;\n",$<str>1,$<str>2,$<str>2);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",$<str>1,$<str>2,$<str>2);
		sprintf(sw_elem,"%s %s",$<str>1,$<str>2);
		strcpy($<str>$,$<str>2);
	}
	| INT NAMED { 
		fprintf(cfo,"if (!output_int(\"%s\",r.%s,isptr,arr)) return 0;\n",$<str>2,$<str>2);
		fprintf(cfi,"if (!input_int(\"%s\",&r->%s,isptr,arr)) return 0;\n",$<str>2,$<str>2);
		sprintf(sw_elem,"%s %s",$<str>1,$<str>2);
		strcpy($<str>$,$<str>2);
	}
	| ENUM NAMED NAMED {
		fprintf(cfo,"if (!output_%s(\"%s\",r.%s,isptr,arr)) return 0;\n",$<str>2,$<str>2,$<str>3);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",$<str>2,$<str>2,$<str>3);
		strcpy($<str>$,$<str>3);
		sprintf(sw_elem,"%s %s %s",$<str>1,$<str>2,$<str>3);
	}
;

union: UNION NAMED SWITCH OPEN_BRACKET  {
	cu_cnt++;
	sprintf(cu[cu_cnt],"%s_u.",$<str>2);

	fprintf(hf,"int output_%s(char *rn,%s r,int isptr,int arr);\n",$<str>2,$<str>2);
	fprintf(cfo,"int output_%s(char *rn,%s r,int isptr,int arr) {\n",$<str>2,$<str>2);
/*	fprintf(cfo,"char *name=\"%s\";\n",$<str>2); */

    /* sepatately defining and initialising to prevent compiler watnings about
    unised variable: */
	fprintf(cfo,"char *name;\n");
	fprintf(cfo,"name=\"%s\";\n",$<str>2);


	fprintf(cfo,"if (!output_start_union(\"%s\",rn,isptr,arr)) return 0;\n",$<str>2);

	fprintf(hf,"int input_%s(char *rn,%s *r,int isptr,int arr);\n",$<str>2,$<str>2);
	fprintf(cfi,"int input_%s(char *rn,%s *r,int isptr,int arr) {\n",$<str>2,$<str>2);
/*	fprintf(cfi,"char *name=\"%s\";\n",$<str>2); */
	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",$<str>2);

	fprintf(cfi,"if (isptr==1&&r==0) return 1; /* Its just a null pointer */\n"); /* ,$<str>2); */
	fprintf(cfi,"if (!input_start_union(\"%s\",rn,isptr,arr)) return 0;\n",$<str>2);

	fprintf(hsf,"struct %s {\n",$<str>2);

	} switch_element CLOSE_BRACKET  {
	fprintf(cfo,"switch(r.%s) {\n",$<str>6);
	fprintf(cfi,"switch(r->%s) {\n",$<str>6);

	fprintf(hsf,"%s;\nunion {\n",sw_elem);

} OPEN_BRACE union_list CLOSE_BRACE SEMICOLON {
	fprintf(cfo,"} /* switch */\n");
	fprintf(cfo,"if (!output_end_union(\"%s\",rn)) return 0;\n",$<str>2);
	fprintf(cfo," return 1;\n}\n\n");

	fprintf(cfi,"} /* switch */\n");
	fprintf(cfi,"if (!input_end_union(\"%s\",rn)) return 0;\n",$<str>2);
	fprintf(cfi," return 1;\n}\n\n");
	fprintf(hsf,"} %s_u;\n};\ntypedef struct %s %s;\n",$<str>2,$<str>2,$<str>2);
	cu_cnt--;
}
;

union_list: union_element | union_list union_element
;

uelement : VOID | element
;


union_element:  CASE case_val COLON  {
	fprintf(cfo,"case %s:\n",$<str>2);
	fprintf(cfi,"case %s:\n",$<str>2);
	} op_union_element_desc

;

op_union_element_desc: | union_element_desc
;

union_element_desc:
	uelement SEMICOLON {
	fprintf(cfo,"         break;\n");
	fprintf(cfi,"         break;\n");
	}
;

case_val: NAMED | INT_VAL
;


string: STRING_VAL {
	char *ptr;
	ptr=acl_strdup($<str>1);
	ptr++;
	ptr[strlen(ptr)-1]=0;
	strcpy($<str>$,ptr);
	ptr--;
	free(ptr);
};


program_name: NAMED;
version_name: NAMED;

hex_int_value: INT_VAL 	| HEX_INT_VAL
;

function_def_list : 
	function_def | function_def_list function_def
;

func_rval	: NAMED | VOID;
pval 		: NAMED | VOID;
func_name	: NAMED;

function_def: 
	func_rval func_name OPEN_BRACKET pval CLOSE_BRACKET EQUAL INT_VAL SEMICOLON
;


program: 	
	PROGRAM program_name OPEN_BRACE
		VERSION version_name OPEN_BRACE
			function_def_list
		CLOSE_BRACE EQUAL hex_int_value SEMICOLON
	CLOSE_BRACE EQUAL hex_int_value SEMICOLON
;
%%


#include "lex.yy.c"
