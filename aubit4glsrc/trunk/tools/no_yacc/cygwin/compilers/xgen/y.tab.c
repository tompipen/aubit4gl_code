
/*  A Bison parser, made from x.yacc
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	OPEN_BRACE	257
#define	CLOSE_BRACE	258
#define	CONST	259
#define	ENUM	260
#define	COMMA	261
#define	SEMICOLON	262
#define	STRUCT	263
#define	STAR	264
#define	NAMED	265
#define	UNION	266
#define	SWITCH	267
#define	TYPEDEF	268
#define	OPEN_BRACKET	269
#define	CLOSE_BRACKET	270
#define	CASE	271
#define	COLON	272
#define	LESS_THAN	273
#define	GREATER_THAN	274
#define	STRING	275
#define	INT	276
#define	LONG	277
#define	SHORT	278
#define	DOUBLE	279
#define	OPAQUE	280
#define	BOOL	281
#define	OPEN_SQUARE	282
#define	CLOSE_SQUARE	283
#define	INT_VAL	284
#define	STRING_VAL	285
#define	NUMBER_VAL	286
#define	EQUAL	287
#define	CH	288

#line 1 "x.yacc"


#define _BISON_SIMPLE_INCL_
/*
#include <stdio.h>
#include <string.h>
*/

/* FIXME: this should be a4gl_xgen_int.h */
#define _NO_FORM_X_H_
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

//fprintf(hsf,"// %s %s mt=%d ms=%d mn=%s mp=%d\n",type,s,m.type,m.size,m.name,m.pointer);


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


fprintf(hsf,"// %s %s mt=%d ms=%d mn=%s mp=%d\n",type,s,m.type,m.size,m.name,m.pointer);

return;
	if (m.type==0) {
		
		fprintf(hsf,"// %s %s mt=%d ms=%d mn=%s mp=%d\n",type,s,m.type,m.size,m.name,m.pointer);
	}

	if (m.type==1) {
		fprintf(hsf,"// %s %s mt=%d ms=%d mn=%s mp=%d\n",type,s,m.type,m.size,m.name,m.pointer);
	}

	if (m.type==2) {
		fprintf(hsf,"// %s %s mt=%d ms=%d mn=%s mp=%d\n",type,s,m.type,m.size,m.name,m.pointer);
	}

	if (m.type==3) {
		fprintf(hsf,"// %s %s mt=%d ms=%d mn=%s mp=%d\n",type,s,m.type,m.size,m.name,m.pointer);
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

			//to prevent control reaches end of non-void function warning:
			//fprintf(cfo,"return 99;\n");
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
		//to prevent control reaches end of non-void function warning:
		//fprintf(cfo,"return 98;\n");

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
		//to prevent control reaches end of non-void function warning:
		//fprintf(cfo,"return 97;\n");
		return;
	}

	if (m.type==3) {
		if (m.pointer==0) {
				fprintf(cfo,"   if (!output_%s(\"%s\",r,0,-1)) return 0;\n",s,m.name); /* ,buff); */
				//to prevent warning:
				fprintf(cfo,"return 0;\n");
        }
		if (m.pointer==1) {
			fprintf(cfo,"   if (r) {output_okptr(\"\");if (!output_%s(\"%s\",*r,1,-1)) return 0;}\n",buff,s); /* ,m.name,buff); */
			fprintf(cfo,"   else      {if (!output_nullptr(\"%s\")) return 0;}\n",m.name);

			//to prevent control reaches end of non-void function warning: (OK)
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
			fprintf(cfi,"   else r->%s=malloc(sizeof(%s));\n",buff,s); 
			fprintf(cfi,"   if (!input_%s(\"%s\",r->%s,1,-1)) return 0;\n\n",s,m.name,buff);
		}
		return;
	}

/* Flexible length array */
	if (m.type==1) { 
		fprintf(cfi,"   if (!input_start_array(\"%s\",1,&r->%s.%s_len)) return 0;\n",m.name,buff,m.name);
		fprintf(cfi,"   {\n");
		fprintf(cfi,"      int cnt;\n");
	        fprintf(cfi,"      r->%s.%s_val=malloc(r->%s.%s_len*sizeof(r->%s.%s_val[0]));\n", buff,m.name, buff,m.name, buff,m.name);
	        fprintf(cfi,"      for (cnt=0;cnt<r->%s.%s_len;cnt++) {\n",buff,m.name);
		
        /*

		form_x.xi.c: In function `input_u_expression':
		form_x.xi.c:336: warning: passing arg 2 of `input_listitem' from incompatible pointer type

        generated code:

		if (!input_listitem("list",&r->u_expression_u.list.list_val[cnt],0,cnt)) return 0;

        prototype:

		int input_listitem(char *rn,struct u_expression *r,int isptr,int arr) ;

        */

		if (m.pointer==0) fprintf(cfi,"         if (!input_%s(\"%s\",&r->%s.%s_val[cnt],0,cnt)) return 0;\n",s,m.name,buff,m.name);
		if (m.pointer==1) {
			fprintf(cfi,"\n   if (!input_ptr_ok()) r->%s.%s_val[cnt]=0;\n",buff,m.name);
			fprintf(cfi,"   else r->%s.%s_val[cnt]=malloc(sizeof(%s));\n",buff,m.name,s);
			fprintf(cfi,"   if (!input_%s(\"%s\",&r->%s.%s_val[cnt],1,cnt)) return 0;\n\n",
				s,m.name,buff,m.name);
		}
	        fprintf(cfi,"      }\n");
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
		if (m.pointer==0) fprintf(cfi,"   if (!input_%s(\"%s\",&r->%s[cnt],0,-1)) return 0;\n",s,m.name,buff);
		if (m.pointer==1) {
			fprintf(cfi,"\n   if (!input_ptr_ok()) r->%s[cnt]=0;\n",m.name);
			fprintf(cfi,"   else r->%s[cnt]=malloc(sizeof(%s));\n",m.name,s);
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
			//to prevent warning:
			fprintf(cfi,"return 0;\n");
        }
		if (m.pointer==1) {
			fprintf(cfi,"   if (!input_%s(\"%s\",r,1,-1)) return 0;\n",m.name,buff);
			//to prevetn warning:
			fprintf(cfi,"return 0;\n");
		}
		return;
	}

	printf("Unable to handle %s %s\n",type,s);
	exit(0);

}






#line 306 "x.yacc"
typedef union    {
        char    str[1024];
	struct mode mode;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		121
#define	YYFLAG		-32768
#define	YYNTBASE	35

#define YYTRANSLATE(x) ((unsigned)(x) <= 288 ? yytranslate[x] : 60)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,     9,    11,    13,    15,    19,    24,
    28,    32,    37,    38,    46,    48,    52,    54,    58,    64,
    66,    68,    70,    72,    73,    81,    83,    86,    88,    92,
    97,   100,   105,   111,   114,   118,   122,   125,   128,   131,
   134,   137,   140,   143,   146,   149,   152,   156,   157,   158,
   171,   173,   176,   177,   184,   186,   188
};

static const short yyrhs[] = {    36,
     0,    35,    36,     0,    45,     0,    52,     0,    43,     0,
    39,     0,    37,     0,    14,    38,     8,     0,     9,    11,
    10,    11,     0,     9,    11,    11,     0,    12,    11,    11,
     0,    12,    11,    10,    11,     0,     0,     6,    11,    40,
     3,    41,     4,     8,     0,    42,     0,    41,     7,    42,
     0,    11,     0,    11,    33,    30,     0,     5,    11,    33,
    44,     8,     0,    30,     0,    11,     0,    59,     0,    32,
     0,     0,     9,    11,    46,     3,    47,     4,     8,     0,
    49,     0,    47,    49,     0,    11,     0,    11,    19,    20,
     0,    11,    28,    30,    29,     0,    10,    11,     0,    10,
    11,    19,    20,     0,    10,    11,    28,    30,    29,     0,
    50,     8,     0,     6,    11,    48,     0,     9,    11,    48,
     0,    11,    48,     0,    27,    48,     0,    22,    48,     0,
    23,    48,     0,    24,    48,     0,    21,    48,     0,    26,
    48,     0,    25,    48,     0,    11,    11,     0,    22,    11,
     0,     6,    11,    11,     0,     0,     0,    12,    11,    13,
    15,    53,    51,    16,    54,     3,    55,     4,     8,     0,
    56,     0,    55,    56,     0,     0,    17,    58,    18,    57,
    50,     8,     0,    11,     0,    30,     0,    31,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   345,   345,   348,   349,   350,   351,   352,   356,   360,   375,
   386,   397,   410,   427,   435,   435,   438,   453,   472,   478,
   478,   478,   478,   481,   509,   519,   519,   522,   528,   534,
   540,   546,   552,   560,   564,   566,   567,   568,   569,   570,
   571,   572,   573,   574,   579,   586,   592,   600,   627,   633,
   646,   646,   649,   653,   659,   659,   663
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","OPEN_BRACE",
"CLOSE_BRACE","CONST","ENUM","COMMA","SEMICOLON","STRUCT","STAR","NAMED","UNION",
"SWITCH","TYPEDEF","OPEN_BRACKET","CLOSE_BRACKET","CASE","COLON","LESS_THAN",
"GREATER_THAN","STRING","INT","LONG","SHORT","DOUBLE","OPAQUE","BOOL","OPEN_SQUARE",
"CLOSE_SQUARE","INT_VAL","STRING_VAL","NUMBER_VAL","EQUAL","CH","x","xset","typedef",
"typedef_elem","enum","@1","enum_list","enum_element","const","value","struct",
"@2","struct_list","vname","struct_element","element","switch_element","union",
"@3","@4","union_list","union_element","@5","case_val","string", NULL
};
#endif

static const short yyr1[] = {     0,
    35,    35,    36,    36,    36,    36,    36,    37,    38,    38,
    38,    38,    40,    39,    41,    41,    42,    42,    43,    44,
    44,    44,    44,    46,    45,    47,    47,    48,    48,    48,
    48,    48,    48,    49,    50,    50,    50,    50,    50,    50,
    50,    50,    50,    50,    51,    51,    51,    53,    54,    52,
    55,    55,    57,    56,    58,    58,    59
};

static const short yyr2[] = {     0,
     1,     2,     1,     1,     1,     1,     1,     3,     4,     3,
     3,     4,     0,     7,     1,     3,     1,     3,     5,     1,
     1,     1,     1,     0,     7,     1,     2,     1,     3,     4,
     2,     4,     5,     2,     3,     3,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     3,     0,     0,    12,
     1,     2,     0,     6,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     0,     1,     7,     6,     5,
     3,     4,     0,    13,    24,     0,     0,     0,     0,     2,
     0,     0,     0,     0,     0,     0,     8,    21,    20,    57,
    23,     0,    22,     0,     0,    48,     0,    10,     0,    11,
    19,    17,     0,    15,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    26,     0,     0,     9,    12,
     0,     0,     0,     0,     0,     0,    28,    37,    42,    39,
    40,    41,    44,    43,    38,     0,    27,    34,     0,     0,
     0,     0,    18,    14,    16,    35,    36,    31,     0,     0,
    25,     0,    45,    46,    49,     0,     0,    29,     0,    47,
     0,    32,     0,    30,     0,    33,     0,     0,    51,    55,
    56,     0,     0,    52,    53,    50,     0,     0,    54,     0,
     0
};

static const short yydefgoto[] = {     6,
     7,     8,    19,     9,    22,    43,    44,    10,    32,    11,
    23,    55,    68,    56,    57,    82,    12,    58,   101,   108,
   109,   117,   112,    33
};

static const short yypact[] = {    59,
    40,    51,    55,    56,    -1,    49,-32768,-32768,-32768,-32768,
-32768,-32768,    36,-32768,-32768,    47,    61,    63,    62,-32768,
     2,    72,    73,    64,    -7,    35,-32768,-32768,-32768,-32768,
-32768,    69,-32768,    67,     3,-32768,    70,-32768,    71,-32768,
-32768,    50,    43,-32768,    74,    75,    46,    46,    46,    46,
    46,    46,    46,    46,    -4,-32768,    76,    37,-32768,-32768,
    57,    80,    67,    46,    46,    78,   -18,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    82,-32768,-32768,    81,    83,
    84,    77,-32768,-32768,-32768,-32768,-32768,   -13,    60,    66,
-32768,    86,-32768,-32768,-32768,    79,    68,-32768,    85,-32768,
    88,-32768,    87,-32768,    89,-32768,     5,    27,-32768,-32768,
-32768,    90,    92,-32768,-32768,-32768,     3,    93,-32768,   102,
-32768
};

static const short yypgoto[] = {-32768,
    97,-32768,-32768,-32768,-32768,-32768,    41,-32768,-32768,-32768,
-32768,-32768,   -12,    52,    -8,-32768,-32768,-32768,-32768,-32768,
    -3,-32768,-32768,-32768
};


#define	YYLAST		116


static const short yytable[] = {    76,
    89,    45,    37,    38,    46,    96,    47,    17,    45,    90,
    18,    46,    28,    47,    97,   110,    48,    49,    50,    51,
    52,    53,    54,    48,    49,    50,    51,    52,    53,    54,
   113,    29,    30,    31,   111,    69,    70,    71,    72,    73,
    74,    75,    79,   107,    39,    40,    62,    80,   120,    63,
    13,    86,    87,     1,     2,    66,    67,     3,    81,    24,
     4,    14,     5,     1,     2,    15,    16,     3,    21,    27,
     4,    25,     5,    26,    34,    35,    41,    42,    36,    98,
    59,    60,    61,    78,    64,    65,    83,    84,    88,    91,
   105,    92,    95,    93,    94,    99,   100,   103,   102,   116,
   119,   121,    20,    85,   114,   107,    77,   115,   118,     0,
     0,     0,     0,   104,     0,   106
};

static const short yycheck[] = {     4,
    19,     6,    10,    11,     9,    19,    11,     9,     6,    28,
    12,     9,    11,    11,    28,    11,    21,    22,    23,    24,
    25,    26,    27,    21,    22,    23,    24,    25,    26,    27,
     4,    30,    31,    32,    30,    48,    49,    50,    51,    52,
    53,    54,     6,    17,    10,    11,     4,    11,     0,     7,
    11,    64,    65,     5,     6,    10,    11,     9,    22,    13,
    12,    11,    14,     5,     6,    11,    11,     9,    33,     8,
    12,    11,    14,    11,     3,     3,     8,    11,    15,    20,
    11,    11,    33,     8,    11,    11,    30,     8,    11,     8,
     3,    11,    16,    11,    11,    30,    11,    30,    20,     8,
     8,     0,     6,    63,   108,    17,    55,    18,   117,    -1,
    -1,    -1,    -1,    29,    -1,    29
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/lib/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/lib/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 9:
#line 361 "x.yacc"
{
		fprintf(hf,"int output_%s(char *rn,struct %s *r,int isptr,int arr) ; /* typedef */\n",yyvsp[0].str,yyvsp[-2].str);
		fprintf(cfo,"int output_%s(char *rn,struct %s *r,int isptr,int arr) { /* typedef */\n",yyvsp[0].str,yyvsp[-2].str);

		fprintf(hf,"int input_%s(char *rn,struct %s *r,int isptr,int arr) ; /* typedef */\n",yyvsp[0].str,yyvsp[-2].str);
		fprintf(cfi,"int input_%s(char *rn,struct %s *r,int isptr,int arr) { /* typedef */\n",yyvsp[0].str,yyvsp[-2].str);

		yyval.mode.type=3; yyval.mode.size=0; yyval.mode.pointer=1; strcpy(yyval.mode.name,yyvsp[-2].str);
		print_elem("struct",yyvsp[-2].str,yyval.mode); 
		fprintf(cfo,"}\n");
		fprintf(cfi,"}\n");
		fprintf(hsf,"typedef struct %s %s %s;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	;
    break;}
case 10:
#line 375 "x.yacc"
{
		fprintf(hf,"int input_%s(char *rn,struct %s r,int isptr,int arr) ; /* typedef */\n",yyvsp[0].str,yyvsp[-1].str);
		fprintf(cfi,"int input_%s(char *rn,struct %s r,int isptr,int arr) { /* typedef */\n",yyvsp[0].str,yyvsp[-1].str);
		fprintf(hf,"int output_%s(char *rn,struct %s r,int isptr,int arr) ; /* typedef */\n",yyvsp[0].str,yyvsp[-1].str);
		fprintf(cfo,"int output_%s(char *rn,struct %s r,int isptr,int arr) { /* typedef */\n",yyvsp[0].str,yyvsp[-1].str);
		yyval.mode.type=3; yyval.mode.size=0; yyval.mode.pointer=0; strcpy(yyval.mode.name,yyvsp[-1].str);
		print_elem("struct",yyvsp[-1].str,yyval.mode); 
		fprintf(cfo,"}\n");
		fprintf(cfi,"}\n");
		fprintf(hsf,"typedef %s %s;\n",yyvsp[-1].str,yyvsp[0].str);
	;
    break;}
case 11:
#line 386 "x.yacc"
{
		fprintf(hf,"int input_%s(char *rn,struct %s r,int isptr,int arr) ;\n /* typedef */",yyvsp[0].str,yyvsp[-1].str);
		fprintf(cfi,"int input_%s(char *rn,struct %s r,int isptr,int arr) {\n /* typedef */",yyvsp[0].str,yyvsp[-1].str);
		fprintf(hf,"int output_%s(char *rn,struct %s r,int isptr,int arr) ;\n /* typedef */",yyvsp[0].str,yyvsp[-1].str);
		fprintf(cfo,"int output_%s(char *rn,struct %s r,int isptr,int arr) {\n /* typedef */",yyvsp[0].str,yyvsp[-1].str);
		yyval.mode.type=3; yyval.mode.size=0; yyval.mode.pointer=0; strcpy(yyval.mode.name,yyvsp[-1].str);
		print_elem("struct",yyvsp[-1].str,yyval.mode); 
		fprintf(cfo,"}\n");
		fprintf(cfi,"}\n");
		fprintf(hsf,"typedef %s %s;\n",yyvsp[-1].str,yyvsp[0].str);
	;
    break;}
case 12:
#line 397 "x.yacc"
{
		fprintf(hf,"int input_%s(char *rn,struct %s *r,int isptr,int arr) ; /* typedef */\n",yyvsp[0].str,yyvsp[-2].str);
		fprintf(cfi,"int input_%s(char *rn,struct %s *r,int isptr,int arr) { /* typedef */\n",yyvsp[0].str,yyvsp[-2].str);
		fprintf(hf,"int output_%s(char *rn,struct %s *r,int isptr,int arr) ; /* typedef */\n",yyvsp[0].str,yyvsp[-2].str);
		fprintf(cfo,"int output_%s(char *rn,struct %s *r,int isptr,int arr) { /* typedef */\n",yyvsp[0].str,yyvsp[-2].str);
		yyval.mode.type=3; yyval.mode.size=0; yyval.mode.pointer=1; strcpy(yyval.mode.name,yyvsp[-2].str);
		print_elem("struct",yyvsp[-2].str,yyval.mode); 
		fprintf(cfo,"}\n");
		fprintf(cfi,"}\n");
		fprintf(hsf,"typedef %s %s %s;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	;
    break;}
case 13:
#line 410 "x.yacc"
{
	cu_cnt++;
	strcpy(cu[cu_cnt],"");
	enumv=0;
	fprintf(hf,"int output_%s(char *rn,int r,int isptr,int arr);\n",yyvsp[0].str);
	fprintf(cfo,"int output_%s(char *rn,int r,int isptr,int arr){\n",yyvsp[0].str);

	fprintf(hf,"int input_%s(char *rn,enum %s *r,int isptr,int arr);\n",yyvsp[0].str,yyvsp[0].str);
	fprintf(cfi,"int input_%s(char *rn,enum %s *r,int isptr,int arr){\n",yyvsp[0].str,yyvsp[0].str);

	fprintf(cfo,"char *name=\"%s\";\ndebug(\"Writing %s\");\n",yyvsp[0].str,yyvsp[0].str);
//	fprintf(cfi,"char *name=\"%s\";\n",$<str>2);

	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",yyvsp[0].str);

	fprintf(hsf,"enum %s {",yyvsp[0].str);
	;
    break;}
case 14:
#line 427 "x.yacc"
{
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"   if (!input_enum(name,(int *)r)) return 0;\nreturn 1;\n}\n\n");
	fprintf(hsf,"\n};\ntypedef enum %s %s;\n\n",yyvsp[-5].str,yyvsp[-5].str);
	cu_cnt--;
;
    break;}
case 17:
#line 438 "x.yacc"
{
		fprintf(cfo,"if (r==%d) {\n", enumv);
		fprintf(cfo,"  if (!output_enum(name,\"%s\",%d)) return 0;\n",yyvsp[0].str,enumv);
		fprintf(cfo,"}\n");

		//fprintf(cfi,"if (r==%d) {\n", enumv);
		//fprintf(cfi,"  if (!input_enum(name,\"%s\",%d)) return 0;\n",$<str>1,enumv);
		//fprintf(cfi,"}\n");

		if (enumv) fprintf(hsf,",\n");
		else       fprintf(hsf,"\n");
		fprintf(hsf," %s = %d ",yyvsp[0].str,enumv);

		enumv++; 
	;
    break;}
case 18:
#line 453 "x.yacc"
{
		enumv=atoi(yyvsp[0].str);
		fprintf(cfo,"if (r==%d) {\n", enumv);
		fprintf(cfo,"  if (!output_enum(name,\"%s\",%d)) return 0;\n",yyvsp[-2].str,enumv);
		fprintf(cfo,"}\n");

		//fprintf(cfi,"if (r==%d) {\n", enumv);
		//fprintf(cfi,"  if (!input_enum(name,\"%s\",%d)) return 0;\n",$<str>1,enumv);
		//fprintf(cfi,"}\n");
		
		if (enumv) fprintf(hsf,",\n");
		else       fprintf(hsf,"\n");
		fprintf(hsf," %s = %d ",yyvsp[-2].str,enumv);

		enumv++; 
	;
    break;}
case 19:
#line 472 "x.yacc"
{
	fprintf(hsf,"#define %s %s\n",yyvsp[-3].str,yyvsp[-1].str);
	;
    break;}
case 24:
#line 481 "x.yacc"
{
	cu_cnt++;
	strcpy(cu[cu_cnt],"");
	fprintf(hsf,"struct %s {\n",yyvsp[0].str);
	fprintf(hf,"int output_%s(char *rn,%s r,int isptr,int arr);\n",yyvsp[0].str,yyvsp[0].str);
	fprintf(cfo,"int output_%s(char *rn,%s r,int isptr,int arr) {\n",yyvsp[0].str,yyvsp[0].str);
	
//	fprintf(cfo,"char *name=\"%s\";\n",$<str>2);

    /* sepatately defining and initialising to prevent compiler watnings about
    unised variable: */
	fprintf(cfo,"char *name;\n");
	fprintf(cfo,"name=\"%s\";\n",yyvsp[0].str);

	fprintf(cfo,"if (!output_start_struct(\"%s\",rn,isptr,arr)) return 0;\n",yyvsp[0].str);

	fprintf(hf,"int input_%s(char *rn,%s *r,int isptr,int arr);\n",yyvsp[0].str,yyvsp[0].str);
	fprintf(cfi,"int input_%s(char *rn,%s *r,int isptr,int arr) {\n",yyvsp[0].str,yyvsp[0].str);
//	fprintf(cfi,"char *name=\"%s\";\n",$<str>2);
	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",yyvsp[0].str);


	fprintf(cfi,"if (isptr==1&&r==0) return 1; /* Its just a null pointer */\n"); /* ,$<str>2); */

	fprintf(cfi,"if (!input_start_struct(\"%s\",rn,isptr,arr)) return 0;\n",yyvsp[0].str);


;
    break;}
case 25:
#line 509 "x.yacc"
{
	fprintf(cfo,"if (!output_end_struct(\"%s\",rn)) return 0;\n",yyvsp[-5].str);
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"if (!input_end_struct(\"%s\",rn)) return 0;\n",yyvsp[-5].str);
	fprintf(cfi,"return 1;\n}\n\n");
	fprintf(hsf,"};\ntypedef struct %s %s;\n\n",yyvsp[-5].str,yyvsp[-5].str);
	cu_cnt--;
;
    break;}
case 28:
#line 522 "x.yacc"
{
		yyval.mode.pointer=0;
		yyval.mode.type=0;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[0].str);
	;
    break;}
case 29:
#line 528 "x.yacc"
{
		yyval.mode.pointer=0;
		yyval.mode.type=1;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[-2].str);
	;
    break;}
case 30:
#line 534 "x.yacc"
{
		yyval.mode.pointer=0;
		yyval.mode.type=2;
		yyval.mode.size=atoi(yyvsp[-1].str);
		strcpy(yyval.mode.name,yyvsp[-3].str);
	;
    break;}
case 31:
#line 540 "x.yacc"
{
		yyval.mode.pointer=1;
		yyval.mode.type=0;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[0].str);
	;
    break;}
case 32:
#line 546 "x.yacc"
{
		yyval.mode.pointer=1;
		yyval.mode.type=1;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[-2].str);
	;
    break;}
case 33:
#line 552 "x.yacc"
{
		yyval.mode.pointer=1;
		yyval.mode.type=2;
		yyval.mode.size=atoi(yyvsp[-1].str);
		strcpy(yyval.mode.name,yyvsp[-3].str);
	;
    break;}
case 35:
#line 565 "x.yacc"
{ print_elem("enum",yyvsp[-1].str,yyvsp[0].mode); ;
    break;}
case 36:
#line 566 "x.yacc"
{ print_elem("struct",yyvsp[-1].str,yyvsp[0].mode); ;
    break;}
case 37:
#line 567 "x.yacc"
{ print_elem("istypedefed",yyvsp[-1].str,yyvsp[0].mode); ;
    break;}
case 38:
#line 568 "x.yacc"
{ print_elem("bool","bool",yyvsp[0].mode); ;
    break;}
case 39:
#line 569 "x.yacc"
{ print_elem("int","int",yyvsp[0].mode); ;
    break;}
case 40:
#line 570 "x.yacc"
{ print_elem("long","long",yyvsp[0].mode); ;
    break;}
case 41:
#line 571 "x.yacc"
{ print_elem("short","short",yyvsp[0].mode); ;
    break;}
case 42:
#line 572 "x.yacc"
{ print_elem("string","string",yyvsp[0].mode); ;
    break;}
case 43:
#line 573 "x.yacc"
{ print_elem("opaque","opaque",yyvsp[0].mode); ;
    break;}
case 44:
#line 574 "x.yacc"
{ print_elem("double","double",yyvsp[0].mode); ;
    break;}
case 45:
#line 580 "x.yacc"
{ 
		fprintf(cfo,"if (!output_%s(\"%s\",r.%s,isptr,arr)) return 0;\n",yyvsp[-1].str,yyvsp[0].str,yyvsp[0].str);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[-1].str,yyvsp[0].str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	;
    break;}
case 46:
#line 586 "x.yacc"
{ 
		fprintf(cfo,"if (!output_int(\"%s\",r.%s,isptr,arr)) return 0;\n",yyvsp[0].str,yyvsp[0].str);
		fprintf(cfi,"if (!input_int(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[0].str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	;
    break;}
case 47:
#line 592 "x.yacc"
{
		fprintf(cfo,"if (!output_%s(\"%s\",&r.%s,isptr,arr)) return 0;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[-1].str);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[-1].str);
		strcpy(yyval.str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	;
    break;}
case 48:
#line 600 "x.yacc"
{
	cu_cnt++;
	sprintf(cu[cu_cnt],"%s_u.",yyvsp[-2].str);

	fprintf(hf,"int output_%s(char *rn,%s r,int isptr,int arr);\n",yyvsp[-2].str,yyvsp[-2].str);
	fprintf(cfo,"int output_%s(char *rn,%s r,int isptr,int arr) {\n",yyvsp[-2].str,yyvsp[-2].str);
//	fprintf(cfo,"char *name=\"%s\";\n",$<str>2);

    /* sepatately defining and initialising to prevent compiler watnings about
    unised variable: */
	fprintf(cfo,"char *name;\n");
	fprintf(cfo,"name=\"%s\";\n",yyvsp[-2].str);


	fprintf(cfo,"if (!output_start_union(\"%s\",rn,isptr,arr)) return 0;\n",yyvsp[-2].str);

	fprintf(hf,"int input_%s(char *rn,%s *r,int isptr,int arr);\n",yyvsp[-2].str,yyvsp[-2].str);
	fprintf(cfi,"int input_%s(char *rn,%s *r,int isptr,int arr) {\n",yyvsp[-2].str,yyvsp[-2].str);
//	fprintf(cfi,"char *name=\"%s\";\n",$<str>2);
	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",yyvsp[-2].str);

	fprintf(cfi,"if (isptr==1&&r==0) return 1; /* Its just a null pointer */\n"); /* ,$<str>2); */
	fprintf(cfi,"if (!input_start_union(\"%s\",rn,isptr,arr)) return 0;\n",yyvsp[-2].str);

	fprintf(hsf,"struct %s {\n",yyvsp[-2].str);

	;
    break;}
case 49:
#line 627 "x.yacc"
{
	fprintf(cfo,"switch(r.%s) {\n",yyvsp[-1].str);
	fprintf(cfi,"switch(r->%s) {\n",yyvsp[-1].str);

	fprintf(hsf,"%s;\nunion {\n",sw_elem);

;
    break;}
case 50:
#line 633 "x.yacc"
{
	fprintf(cfo,"} /* switch */\n");
	fprintf(cfo,"if (!output_end_union(\"%s\",rn)) return 0;\n",yyvsp[-10].str);
	fprintf(cfo," return 1;\n}\n\n");

	fprintf(cfi,"} /* switch */\n");
	fprintf(cfi,"if (!input_end_union(\"%s\",rn)) return 0;\n",yyvsp[-10].str);
	fprintf(cfi," return 1;\n}\n\n");
	fprintf(hsf,"} %s_u;\n};\ntypedef struct %s %s;\n",yyvsp[-10].str,yyvsp[-10].str,yyvsp[-10].str);
	cu_cnt--;
;
    break;}
case 53:
#line 649 "x.yacc"
{
	fprintf(cfo,"case %s:\n",yyvsp[-1].str);
	fprintf(cfi,"case %s:\n",yyvsp[-1].str);
	;
    break;}
case 54:
#line 653 "x.yacc"
{
	fprintf(cfo,"         break;\n");
	fprintf(cfi,"         break;\n");
	;
    break;}
case 57:
#line 663 "x.yacc"
{
	char *ptr;
	ptr=strdup(yyvsp[0].str);
	ptr++;
	ptr[strlen(ptr)-1]=0;
	strcpy(yyval.str,ptr);
	ptr--;
	free(ptr);
;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/lib/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 674 "x.yacc"



#include "lex.yy.c"
