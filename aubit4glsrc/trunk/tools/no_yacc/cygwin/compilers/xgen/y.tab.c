/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OPEN_BRACE = 258,
     CLOSE_BRACE = 259,
     CONST = 260,
     ENUM = 261,
     COMMA = 262,
     SEMICOLON = 263,
     STRUCT = 264,
     STAR = 265,
     VOID = 266,
     NAMED = 267,
     UNION = 268,
     SWITCH = 269,
     TYPEDEF = 270,
     OPEN_BRACKET = 271,
     CLOSE_BRACKET = 272,
     CASE = 273,
     COLON = 274,
     LESS_THAN = 275,
     GREATER_THAN = 276,
     STRING = 277,
     INT = 278,
     LONG = 279,
     SHORT = 280,
     DOUBLE = 281,
     OPAQUE = 282,
     BOOL = 283,
     OPEN_SQUARE = 284,
     CLOSE_SQUARE = 285,
     INT_VAL = 286,
     STRING_VAL = 287,
     NUMBER_VAL = 288,
     EQUAL = 289,
     CH = 290
   };
#endif
#define OPEN_BRACE 258
#define CLOSE_BRACE 259
#define CONST 260
#define ENUM 261
#define COMMA 262
#define SEMICOLON 263
#define STRUCT 264
#define STAR 265
#define VOID 266
#define NAMED 267
#define UNION 268
#define SWITCH 269
#define TYPEDEF 270
#define OPEN_BRACKET 271
#define CLOSE_BRACKET 272
#define CASE 273
#define COLON 274
#define LESS_THAN 275
#define GREATER_THAN 276
#define STRING 277
#define INT 278
#define LONG 279
#define SHORT 280
#define DOUBLE 281
#define OPAQUE 282
#define BOOL 283
#define OPEN_SQUARE 284
#define CLOSE_SQUARE 285
#define INT_VAL 286
#define STRING_VAL 287
#define NUMBER_VAL 288
#define EQUAL 289
#define CH 290




/* Copy the first part of user declarations.  */
#line 1 "x.yacc"


#define _BISON_SIMPLE_INCL_

#define _NO_FORM_X_H_
#define _NO_WINDOWS_H_

/* FIXME: this should be a4gl_xgen_int.h */
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
		fprintf(cfi,"      int cnt; if (r->%s.%s_len) {\n",buff,m.name);
	        fprintf(cfi,"      r->%s.%s_val=malloc(r->%s.%s_len*sizeof(r->%s.%s_val[0]));\n", buff,m.name, buff,m.name, buff,m.name);
	        fprintf(cfi,"      for (cnt=0;cnt<r->%s.%s_len;cnt++) {\n",buff,m.name);
		if (m.pointer==0) fprintf(cfi,"         if (!input_%s(\"%s\",&r->%s.%s_val[cnt],0,cnt)) return 0;\n",s,m.name,buff,m.name);
		if (m.pointer==1) {
			fprintf(cfi,"\n   if (!input_ptr_ok()) r->%s.%s_val[cnt]=0;\n",buff,m.name);
			fprintf(cfi,"   else r->%s.%s_val[cnt]=malloc(sizeof(%s));\n",buff,m.name,s);
			fprintf(cfi,"   if (!input_%s(\"%s\",&r->%s.%s_val[cnt],1,cnt)) return 0;\n\n",
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







/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 289 "x.yacc"
typedef union YYSTYPE {
        char    str[1024];
	struct mode mode;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 435 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 447 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  29
/* YYNRULES -- Number of rules. */
#define YYNRULES  63
/* YYNRULES -- Number of states. */
#define YYNSTATES  125

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      22,    27,    31,    35,    40,    41,    49,    51,    55,    57,
      61,    67,    69,    71,    73,    75,    76,    84,    86,    89,
      91,    95,   100,   103,   108,   114,   117,   121,   125,   128,
     131,   134,   137,   140,   143,   146,   149,   152,   155,   159,
     160,   161,   174,   176,   179,   181,   183,   184,   190,   191,
     193,   196,   198,   200
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      37,     0,    -1,    38,    -1,    37,    38,    -1,    47,    -1,
      54,    -1,    45,    -1,    41,    -1,    39,    -1,    15,    40,
       8,    -1,     9,    12,    10,    12,    -1,     9,    12,    12,
      -1,    13,    12,    12,    -1,    13,    12,    10,    12,    -1,
      -1,     6,    12,    42,     3,    43,     4,     8,    -1,    44,
      -1,    43,     7,    44,    -1,    12,    -1,    12,    34,    31,
      -1,     5,    12,    34,    46,     8,    -1,    31,    -1,    12,
      -1,    64,    -1,    33,    -1,    -1,     9,    12,    48,     3,
      49,     4,     8,    -1,    51,    -1,    49,    51,    -1,    12,
      -1,    12,    20,    21,    -1,    12,    29,    31,    30,    -1,
      10,    12,    -1,    10,    12,    20,    21,    -1,    10,    12,
      29,    31,    30,    -1,    52,     8,    -1,     6,    12,    50,
      -1,     9,    12,    50,    -1,    12,    50,    -1,    28,    50,
      -1,    23,    50,    -1,    24,    50,    -1,    25,    50,    -1,
      22,    50,    -1,    27,    50,    -1,    26,    50,    -1,    12,
      12,    -1,    23,    12,    -1,     6,    12,    12,    -1,    -1,
      -1,    13,    12,    14,    16,    55,    53,    17,    56,     3,
      57,     4,     8,    -1,    59,    -1,    57,    59,    -1,    11,
      -1,    52,    -1,    -1,    18,    63,    19,    60,    61,    -1,
      -1,    62,    -1,    58,     8,    -1,    12,    -1,    31,    -1,
      32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   329,   329,   329,   332,   333,   334,   335,   336,   341,
     345,   359,   370,   381,   394,   394,   419,   419,   422,   437,
     456,   462,   462,   462,   462,   465,   465,   503,   503,   506,
     512,   518,   524,   530,   536,   544,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   564,   570,   576,   584,
     611,   584,   630,   630,   633,   633,   637,   637,   644,   644,
     648,   654,   654,   658
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPEN_BRACE", "CLOSE_BRACE", "CONST", 
  "ENUM", "COMMA", "SEMICOLON", "STRUCT", "STAR", "VOID", "NAMED", 
  "UNION", "SWITCH", "TYPEDEF", "OPEN_BRACKET", "CLOSE_BRACKET", "CASE", 
  "COLON", "LESS_THAN", "GREATER_THAN", "STRING", "INT", "LONG", "SHORT", 
  "DOUBLE", "OPAQUE", "BOOL", "OPEN_SQUARE", "CLOSE_SQUARE", "INT_VAL", 
  "STRING_VAL", "NUMBER_VAL", "EQUAL", "CH", "$accept", "x", "xset", 
  "typedef", "typedef_elem", "enum", "@1", "enum_list", "enum_element", 
  "const", "value", "struct", "@2", "struct_list", "vname", 
  "struct_element", "element", "switch_element", "union", "@3", "@4", 
  "union_list", "uelement", "union_element", "@5", 
  "op_union_element_desc", "union_element_desc", "case_val", "string", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    38,    39,
      40,    40,    40,    40,    42,    41,    43,    43,    44,    44,
      45,    46,    46,    46,    46,    48,    47,    49,    49,    50,
      50,    50,    50,    50,    50,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    55,
      56,    54,    57,    57,    58,    58,    60,    59,    61,    61,
      62,    63,    63,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       4,     3,     3,     4,     0,     7,     1,     3,     1,     3,
       5,     1,     1,     1,     1,     0,     7,     1,     2,     1,
       3,     4,     2,     4,     5,     2,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     0,
       0,    12,     1,     2,     1,     1,     0,     5,     0,     1,
       2,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     2,     8,     7,
       6,     4,     5,     0,    14,    25,     0,     0,     0,     0,
       1,     3,     0,     0,     0,     0,     0,     0,     9,    22,
      21,    63,    24,     0,    23,     0,     0,    49,     0,    11,
       0,    12,    20,    18,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      10,    13,     0,     0,     0,     0,     0,     0,    29,    38,
      43,    40,    41,    42,    45,    44,    39,     0,    28,    35,
       0,     0,     0,     0,    19,    15,    17,    36,    37,    32,
       0,     0,    26,     0,    46,    47,    50,     0,     0,    30,
       0,    48,     0,    33,     0,    31,     0,    34,     0,     0,
      52,    61,    62,     0,     0,    53,    56,    51,    58,    54,
      55,     0,    57,    59,    60
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     6,     7,     8,    19,     9,    23,    44,    45,    10,
      33,    11,    24,    56,    69,    57,    58,    83,    12,    59,
     102,   109,   121,   110,   118,   122,   123,   113,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -20
static const yysigned_char yypact[] =
{
      28,    -6,     4,    35,    59,    -2,    73,   -20,   -20,   -20,
     -20,   -20,   -20,     6,   -20,   -20,    63,    62,    68,    76,
     -20,   -20,    24,    78,    82,    71,    34,    57,   -20,   -20,
     -20,   -20,   -20,    81,   -20,    79,    26,   -20,    80,   -20,
      83,   -20,   -20,    56,    38,   -20,    84,    85,    58,    58,
      58,    58,    58,    58,    58,    58,    -4,   -20,    86,    60,
     -20,   -20,    67,    91,    79,    58,    58,    88,   -19,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,    93,   -20,   -20,
      90,    92,    94,    95,   -20,   -20,   -20,   -20,   -20,   -16,
      72,    74,   -20,    96,   -20,   -20,   -20,    89,    87,   -20,
      77,   -20,   100,   -20,    97,   -20,    98,   -20,    27,    -1,
     -20,   -20,   -20,   101,   103,   -20,   -20,   -20,     3,   -20,
     -20,   105,   -20,   -20,   -20
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -20,   -20,   108,   -20,   -20,   -20,   -20,   -20,    45,   -20,
     -20,   -20,   -20,   -20,    10,    61,    -3,   -20,   -20,   -20,
     -20,   -20,   -20,    12,   -20,   -20,   -20,   -20,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      77,    90,    46,   114,    97,    47,    13,    17,    48,    46,
      91,    18,    47,    98,   119,    48,    14,   108,    49,    50,
      51,    52,    53,    54,    55,    49,    50,    51,    52,    53,
      54,    55,    46,     1,     2,    47,    29,     3,    48,   111,
      22,     4,    63,     5,    38,    64,    39,    15,    49,    50,
      51,    52,    53,    54,    55,    30,    31,    32,   112,    70,
      71,    72,    73,    74,    75,    76,    80,    40,    67,    41,
      68,    16,    81,    20,    26,    87,    88,    25,     1,     2,
      27,    35,     3,    82,    28,    36,     4,    37,     5,    42,
      62,    43,    60,    99,    79,    61,    65,    66,    84,    85,
      89,    92,    93,   106,    94,   100,    95,   105,   101,    86,
     103,   117,    96,   124,    21,   120,   108,    78,   104,     0,
     116,   115,     0,     0,     0,     0,     0,   107
};

static const yysigned_char yycheck[] =
{
       4,    20,     6,     4,    20,     9,    12,     9,    12,     6,
      29,    13,     9,    29,    11,    12,    12,    18,    22,    23,
      24,    25,    26,    27,    28,    22,    23,    24,    25,    26,
      27,    28,     6,     5,     6,     9,    12,     9,    12,    12,
      34,    13,     4,    15,    10,     7,    12,    12,    22,    23,
      24,    25,    26,    27,    28,    31,    32,    33,    31,    49,
      50,    51,    52,    53,    54,    55,     6,    10,    10,    12,
      12,    12,    12,     0,    12,    65,    66,    14,     5,     6,
      12,     3,     9,    23,     8,     3,    13,    16,    15,     8,
      34,    12,    12,    21,     8,    12,    12,    12,    31,     8,
      12,     8,    12,     3,    12,    31,    12,    30,    12,    64,
      21,     8,    17,     8,     6,   118,    18,    56,    31,    -1,
      19,   109,    -1,    -1,    -1,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     5,     6,     9,    13,    15,    37,    38,    39,    41,
      45,    47,    54,    12,    12,    12,    12,     9,    13,    40,
       0,    38,    34,    42,    48,    14,    12,    12,     8,    12,
      31,    32,    33,    46,    64,     3,     3,    16,    10,    12,
      10,    12,     8,    12,    43,    44,     6,     9,    12,    22,
      23,    24,    25,    26,    27,    28,    49,    51,    52,    55,
      12,    12,    34,     4,     7,    12,    12,    10,    12,    50,
      50,    50,    50,    50,    50,    50,    50,     4,    51,     8,
       6,    12,    23,    53,    31,     8,    44,    50,    50,    12,
      20,    29,     8,    12,    12,    12,    17,    20,    29,    21,
      31,    12,    56,    21,    31,    30,     3,    30,    18,    57,
      59,    12,    31,    63,     4,    59,    19,     8,    60,    11,
      52,    58,    61,    62,     8
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:
#line 345 "x.yacc"
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
	}
    break;

  case 11:
#line 359 "x.yacc"
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
	}
    break;

  case 12:
#line 370 "x.yacc"
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
	}
    break;

  case 13:
#line 381 "x.yacc"
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
	}
    break;

  case 14:
#line 394 "x.yacc"
    {
	cu_cnt++;
	strcpy(cu[cu_cnt],"");
	enumv=0;
	fprintf(hf,"int output_%s(char *rn,int r,int isptr,int arr);\n",yyvsp[0].str);
	fprintf(cfo,"int output_%s(char *rn,int r,int isptr,int arr){\n",yyvsp[0].str);

	fprintf(hf,"int input_%s(char *rn,enum %s *r,int isptr,int arr);\n",yyvsp[0].str,yyvsp[0].str);
	fprintf(cfi,"int input_%s(char *rn,enum %s *r,int isptr,int arr){\n",yyvsp[0].str,yyvsp[0].str);

	fprintf(cfo,"char *name=\"%s\";\nA4GL_debug(\"Writing %s\");\n",yyvsp[0].str,yyvsp[0].str);
//	fprintf(cfi,"char *name=\"%s\";\n",$<str>2);

	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",yyvsp[0].str);

	fprintf(hsf,"enum %s {",yyvsp[0].str);
	}
    break;

  case 15:
#line 411 "x.yacc"
    {
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"   if (!input_enum(name,(int *)r)) return 0;\nreturn 1;\n}\n\n");
	fprintf(hsf,"\n};\ntypedef enum %s %s;\n\n",yyvsp[-5].str,yyvsp[-5].str);
	cu_cnt--;
}
    break;

  case 18:
#line 422 "x.yacc"
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
	}
    break;

  case 19:
#line 437 "x.yacc"
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
	}
    break;

  case 20:
#line 456 "x.yacc"
    {
	fprintf(hsf,"#define %s %s\n",yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 25:
#line 465 "x.yacc"
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


}
    break;

  case 26:
#line 493 "x.yacc"
    {
	fprintf(cfo,"if (!output_end_struct(\"%s\",rn)) return 0;\n",yyvsp[-5].str);
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"if (!input_end_struct(\"%s\",rn)) return 0;\n",yyvsp[-5].str);
	fprintf(cfi,"return 1;\n}\n\n");
	fprintf(hsf,"};\ntypedef struct %s %s;\n\n",yyvsp[-5].str,yyvsp[-5].str);
	cu_cnt--;
}
    break;

  case 29:
#line 506 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=0;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[0].str);
	}
    break;

  case 30:
#line 512 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=1;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[-2].str);
	}
    break;

  case 31:
#line 518 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=2;
		yyval.mode.size=atoi(yyvsp[-1].str);
		strcpy(yyval.mode.name,yyvsp[-3].str);
	}
    break;

  case 32:
#line 524 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=0;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[0].str);
	}
    break;

  case 33:
#line 530 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=1;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[-2].str);
	}
    break;

  case 34:
#line 536 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=2;
		yyval.mode.size=atoi(yyvsp[-1].str);
		strcpy(yyval.mode.name,yyvsp[-3].str);
	}
    break;

  case 36:
#line 549 "x.yacc"
    { print_elem("enum",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 37:
#line 550 "x.yacc"
    { print_elem("struct",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 38:
#line 551 "x.yacc"
    { print_elem("istypedefed",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 39:
#line 552 "x.yacc"
    { print_elem("bool","bool",yyvsp[0].mode); }
    break;

  case 40:
#line 553 "x.yacc"
    { print_elem("int","int",yyvsp[0].mode); }
    break;

  case 41:
#line 554 "x.yacc"
    { print_elem("long","long",yyvsp[0].mode); }
    break;

  case 42:
#line 555 "x.yacc"
    { print_elem("short","short",yyvsp[0].mode); }
    break;

  case 43:
#line 556 "x.yacc"
    { print_elem("string","string",yyvsp[0].mode); }
    break;

  case 44:
#line 557 "x.yacc"
    { print_elem("opaque","opaque",yyvsp[0].mode); }
    break;

  case 45:
#line 558 "x.yacc"
    { print_elem("double","double",yyvsp[0].mode); }
    break;

  case 46:
#line 564 "x.yacc"
    { 
		fprintf(cfo,"if (!output_%s(\"%s\",r.%s,isptr,arr)) return 0;\n",yyvsp[-1].str,yyvsp[0].str,yyvsp[0].str);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[-1].str,yyvsp[0].str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 47:
#line 570 "x.yacc"
    { 
		fprintf(cfo,"if (!output_int(\"%s\",r.%s,isptr,arr)) return 0;\n",yyvsp[0].str,yyvsp[0].str);
		fprintf(cfi,"if (!input_int(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[0].str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 48:
#line 576 "x.yacc"
    {
		fprintf(cfo,"if (!output_%s(\"%s\",&r.%s,isptr,arr)) return 0;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[-1].str);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[-1].str);
		strcpy(yyval.str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 49:
#line 584 "x.yacc"
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

	}
    break;

  case 50:
#line 611 "x.yacc"
    {
	fprintf(cfo,"switch(r.%s) {\n",yyvsp[-1].str);
	fprintf(cfi,"switch(r->%s) {\n",yyvsp[-1].str);

	fprintf(hsf,"%s;\nunion {\n",sw_elem);

}
    break;

  case 51:
#line 617 "x.yacc"
    {
	fprintf(cfo,"} /* switch */\n");
	fprintf(cfo,"if (!output_end_union(\"%s\",rn)) return 0;\n",yyvsp[-10].str);
	fprintf(cfo," return 1;\n}\n\n");

	fprintf(cfi,"} /* switch */\n");
	fprintf(cfi,"if (!input_end_union(\"%s\",rn)) return 0;\n",yyvsp[-10].str);
	fprintf(cfi," return 1;\n}\n\n");
	fprintf(hsf,"} %s_u;\n};\ntypedef struct %s %s;\n",yyvsp[-10].str,yyvsp[-10].str,yyvsp[-10].str);
	cu_cnt--;
}
    break;

  case 56:
#line 637 "x.yacc"
    {
	fprintf(cfo,"case %s:\n",yyvsp[-1].str);
	fprintf(cfi,"case %s:\n",yyvsp[-1].str);
	}
    break;

  case 60:
#line 648 "x.yacc"
    {
	fprintf(cfo,"         break;\n");
	fprintf(cfi,"         break;\n");
	}
    break;

  case 63:
#line 658 "x.yacc"
    {
	char *ptr;
	ptr=strdup(yyvsp[0].str);
	ptr++;
	ptr[strlen(ptr)-1]=0;
	strcpy(yyval.str,ptr);
	ptr--;
	free(ptr);
}
    break;


    }

/* Line 991 of yacc.c.  */
#line 1843 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 669 "x.yacc"



#include "lex.yy.c"


