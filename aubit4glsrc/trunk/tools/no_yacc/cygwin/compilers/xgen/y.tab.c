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
     NAMED = 266,
     UNION = 267,
     SWITCH = 268,
     TYPEDEF = 269,
     OPEN_BRACKET = 270,
     CLOSE_BRACKET = 271,
     CASE = 272,
     COLON = 273,
     LESS_THAN = 274,
     GREATER_THAN = 275,
     STRING = 276,
     INT = 277,
     LONG = 278,
     SHORT = 279,
     DOUBLE = 280,
     OPAQUE = 281,
     BOOL = 282,
     OPEN_SQUARE = 283,
     CLOSE_SQUARE = 284,
     INT_VAL = 285,
     STRING_VAL = 286,
     NUMBER_VAL = 287,
     EQUAL = 288,
     CH = 289
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
#define NAMED 266
#define UNION 267
#define SWITCH 268
#define TYPEDEF 269
#define OPEN_BRACKET 270
#define CLOSE_BRACKET 271
#define CASE 272
#define COLON 273
#define LESS_THAN 274
#define GREATER_THAN 275
#define STRING 276
#define INT 277
#define LONG 278
#define SHORT 279
#define DOUBLE 280
#define OPAQUE 281
#define BOOL 282
#define OPEN_SQUARE 283
#define CLOSE_SQUARE 284
#define INT_VAL 285
#define STRING_VAL 286
#define NUMBER_VAL 287
#define EQUAL 288
#define CH 289




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
#line 433 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 445 "y.tab.c"

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
#define YYLAST   116

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  26
/* YYNRULES -- Number of rules. */
#define YYNRULES  58
/* YYNRULES -- Number of states. */
#define YYNSTATES  121

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
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
     160,   161,   174,   176,   179,   180,   187,   189,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      36,     0,    -1,    37,    -1,    36,    37,    -1,    46,    -1,
      53,    -1,    44,    -1,    40,    -1,    38,    -1,    14,    39,
       8,    -1,     9,    11,    10,    11,    -1,     9,    11,    11,
      -1,    12,    11,    11,    -1,    12,    11,    10,    11,    -1,
      -1,     6,    11,    41,     3,    42,     4,     8,    -1,    43,
      -1,    42,     7,    43,    -1,    11,    -1,    11,    33,    30,
      -1,     5,    11,    33,    45,     8,    -1,    30,    -1,    11,
      -1,    60,    -1,    32,    -1,    -1,     9,    11,    47,     3,
      48,     4,     8,    -1,    50,    -1,    48,    50,    -1,    11,
      -1,    11,    19,    20,    -1,    11,    28,    30,    29,    -1,
      10,    11,    -1,    10,    11,    19,    20,    -1,    10,    11,
      28,    30,    29,    -1,    51,     8,    -1,     6,    11,    49,
      -1,     9,    11,    49,    -1,    11,    49,    -1,    27,    49,
      -1,    22,    49,    -1,    23,    49,    -1,    24,    49,    -1,
      21,    49,    -1,    26,    49,    -1,    25,    49,    -1,    11,
      11,    -1,    22,    11,    -1,     6,    11,    11,    -1,    -1,
      -1,    12,    11,    13,    15,    54,    52,    16,    55,     3,
      56,     4,     8,    -1,    57,    -1,    56,    57,    -1,    -1,
      17,    59,    18,    58,    51,     8,    -1,    11,    -1,    30,
      -1,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   328,   328,   328,   331,   332,   333,   334,   335,   340,
     344,   358,   369,   380,   393,   393,   418,   418,   421,   436,
     455,   461,   461,   461,   461,   464,   464,   502,   502,   505,
     511,   517,   523,   529,   535,   543,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   563,   569,   575,   583,
     610,   583,   629,   629,   632,   632,   642,   642,   646
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPEN_BRACE", "CLOSE_BRACE", "CONST", 
  "ENUM", "COMMA", "SEMICOLON", "STRUCT", "STAR", "NAMED", "UNION", 
  "SWITCH", "TYPEDEF", "OPEN_BRACKET", "CLOSE_BRACKET", "CASE", "COLON", 
  "LESS_THAN", "GREATER_THAN", "STRING", "INT", "LONG", "SHORT", "DOUBLE", 
  "OPAQUE", "BOOL", "OPEN_SQUARE", "CLOSE_SQUARE", "INT_VAL", 
  "STRING_VAL", "NUMBER_VAL", "EQUAL", "CH", "$accept", "x", "xset", 
  "typedef", "typedef_elem", "enum", "@1", "enum_list", "enum_element", 
  "const", "value", "struct", "@2", "struct_list", "vname", 
  "struct_element", "element", "switch_element", "union", "@3", "@4", 
  "union_list", "union_element", "@5", "case_val", "string", 0
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
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    38,
      39,    39,    39,    39,    41,    40,    42,    42,    43,    43,
      44,    45,    45,    45,    45,    47,    46,    48,    48,    49,
      49,    49,    49,    49,    49,    50,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    52,    54,
      55,    53,    56,    56,    58,    57,    59,    59,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       4,     3,     3,     4,     0,     7,     1,     3,     1,     3,
       5,     1,     1,     1,     1,     0,     7,     1,     2,     1,
       3,     4,     2,     4,     5,     2,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     0,
       0,    12,     1,     2,     0,     6,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     2,     8,     7,
       6,     4,     5,     0,    14,    25,     0,     0,     0,     0,
       1,     3,     0,     0,     0,     0,     0,     0,     9,    22,
      21,    58,    24,     0,    23,     0,     0,    49,     0,    11,
       0,    12,    20,    18,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      10,    13,     0,     0,     0,     0,     0,     0,    29,    38,
      43,    40,    41,    42,    45,    44,    39,     0,    28,    35,
       0,     0,     0,     0,    19,    15,    17,    36,    37,    32,
       0,     0,    26,     0,    46,    47,    50,     0,     0,    30,
       0,    48,     0,    33,     0,    31,     0,    34,     0,     0,
      52,    56,    57,     0,     0,    53,    54,    51,     0,     0,
      55
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     6,     7,     8,    19,     9,    23,    44,    45,    10,
      33,    11,    24,    56,    69,    57,    58,    83,    12,    59,
     102,   109,   110,   118,   113,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -19
static const yysigned_char yypact[] =
{
      59,    -7,    46,    51,    58,    -6,    49,   -19,   -19,   -19,
     -19,   -19,   -19,    39,   -19,   -19,    47,    63,    64,     7,
     -19,   -19,     2,    67,    73,    62,    35,    40,   -19,   -19,
     -19,   -19,   -19,    70,   -19,    68,     3,   -19,    69,   -19,
      71,   -19,   -19,    48,     4,   -19,    72,    74,    56,    56,
      56,    56,    56,    56,    56,    56,    -4,   -19,    76,    37,
     -19,   -19,    57,    78,    68,    56,    56,    77,   -18,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,    81,   -19,   -19,
      79,    80,    82,    83,   -19,   -19,   -19,   -19,   -19,    28,
      75,    66,   -19,    86,   -19,   -19,   -19,    84,    85,   -19,
      65,   -19,    89,   -19,    87,   -19,    88,   -19,     5,    27,
     -19,   -19,   -19,    90,    92,   -19,   -19,   -19,     3,    93,
     -19
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -19,   -19,    96,   -19,   -19,   -19,   -19,   -19,    34,   -19,
     -19,   -19,   -19,   -19,   -13,    50,   -15,   -19,   -19,   -19,
     -19,   -19,    -2,   -19,   -19,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      77,    90,    46,    17,    13,    47,    18,    48,    63,    46,
      91,    64,    47,    29,    48,    28,   111,    49,    50,    51,
      52,    53,    54,    55,    49,    50,    51,    52,    53,    54,
      55,   114,    30,    31,    32,   112,    70,    71,    72,    73,
      74,    75,    76,    80,   108,    38,    39,    97,    81,    20,
      40,    41,    87,    88,     1,     2,    98,    14,     3,    82,
      25,     4,    15,     5,     1,     2,    67,    68,     3,    16,
      35,     4,    22,     5,    26,    27,    36,    37,    42,    43,
      60,    62,    61,    65,    79,    66,    85,    84,    89,    92,
      93,    94,   106,    95,   105,    99,   100,   101,    86,    96,
     117,   120,    21,   119,   103,   108,    78,   115,   116,     0,
       0,     0,     0,     0,     0,   104,   107
};

static const yysigned_char yycheck[] =
{
       4,    19,     6,     9,    11,     9,    12,    11,     4,     6,
      28,     7,     9,    11,    11,     8,    11,    21,    22,    23,
      24,    25,    26,    27,    21,    22,    23,    24,    25,    26,
      27,     4,    30,    31,    32,    30,    49,    50,    51,    52,
      53,    54,    55,     6,    17,    10,    11,    19,    11,     0,
      10,    11,    65,    66,     5,     6,    28,    11,     9,    22,
      13,    12,    11,    14,     5,     6,    10,    11,     9,    11,
       3,    12,    33,    14,    11,    11,     3,    15,     8,    11,
      11,    33,    11,    11,     8,    11,     8,    30,    11,     8,
      11,    11,     3,    11,    29,    20,    30,    11,    64,    16,
       8,     8,     6,   118,    20,    17,    56,   109,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     5,     6,     9,    12,    14,    36,    37,    38,    40,
      44,    46,    53,    11,    11,    11,    11,     9,    12,    39,
       0,    37,    33,    41,    47,    13,    11,    11,     8,    11,
      30,    31,    32,    45,    60,     3,     3,    15,    10,    11,
      10,    11,     8,    11,    42,    43,     6,     9,    11,    21,
      22,    23,    24,    25,    26,    27,    48,    50,    51,    54,
      11,    11,    33,     4,     7,    11,    11,    10,    11,    49,
      49,    49,    49,    49,    49,    49,    49,     4,    50,     8,
       6,    11,    22,    52,    30,     8,    43,    49,    49,    11,
      19,    28,     8,    11,    11,    11,    16,    19,    28,    20,
      30,    11,    55,    20,    30,    29,     3,    29,    17,    56,
      57,    11,    30,    59,     4,    57,    18,     8,    58,    51,
       8
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
#line 344 "x.yacc"
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
#line 358 "x.yacc"
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
#line 369 "x.yacc"
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
#line 380 "x.yacc"
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
#line 393 "x.yacc"
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
	}
    break;

  case 15:
#line 410 "x.yacc"
    {
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"   if (!input_enum(name,(int *)r)) return 0;\nreturn 1;\n}\n\n");
	fprintf(hsf,"\n};\ntypedef enum %s %s;\n\n",yyvsp[-5].str,yyvsp[-5].str);
	cu_cnt--;
}
    break;

  case 18:
#line 421 "x.yacc"
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
#line 436 "x.yacc"
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
#line 455 "x.yacc"
    {
	fprintf(hsf,"#define %s %s\n",yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 25:
#line 464 "x.yacc"
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
#line 492 "x.yacc"
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
#line 505 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=0;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[0].str);
	}
    break;

  case 30:
#line 511 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=1;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[-2].str);
	}
    break;

  case 31:
#line 517 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=2;
		yyval.mode.size=atoi(yyvsp[-1].str);
		strcpy(yyval.mode.name,yyvsp[-3].str);
	}
    break;

  case 32:
#line 523 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=0;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[0].str);
	}
    break;

  case 33:
#line 529 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=1;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[-2].str);
	}
    break;

  case 34:
#line 535 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=2;
		yyval.mode.size=atoi(yyvsp[-1].str);
		strcpy(yyval.mode.name,yyvsp[-3].str);
	}
    break;

  case 36:
#line 548 "x.yacc"
    { print_elem("enum",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 37:
#line 549 "x.yacc"
    { print_elem("struct",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 38:
#line 550 "x.yacc"
    { print_elem("istypedefed",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 39:
#line 551 "x.yacc"
    { print_elem("bool","bool",yyvsp[0].mode); }
    break;

  case 40:
#line 552 "x.yacc"
    { print_elem("int","int",yyvsp[0].mode); }
    break;

  case 41:
#line 553 "x.yacc"
    { print_elem("long","long",yyvsp[0].mode); }
    break;

  case 42:
#line 554 "x.yacc"
    { print_elem("short","short",yyvsp[0].mode); }
    break;

  case 43:
#line 555 "x.yacc"
    { print_elem("string","string",yyvsp[0].mode); }
    break;

  case 44:
#line 556 "x.yacc"
    { print_elem("opaque","opaque",yyvsp[0].mode); }
    break;

  case 45:
#line 557 "x.yacc"
    { print_elem("double","double",yyvsp[0].mode); }
    break;

  case 46:
#line 563 "x.yacc"
    { 
		fprintf(cfo,"if (!output_%s(\"%s\",r.%s,isptr,arr)) return 0;\n",yyvsp[-1].str,yyvsp[0].str,yyvsp[0].str);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[-1].str,yyvsp[0].str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 47:
#line 569 "x.yacc"
    { 
		fprintf(cfo,"if (!output_int(\"%s\",r.%s,isptr,arr)) return 0;\n",yyvsp[0].str,yyvsp[0].str);
		fprintf(cfi,"if (!input_int(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[0].str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 48:
#line 575 "x.yacc"
    {
		fprintf(cfo,"if (!output_%s(\"%s\",&r.%s,isptr,arr)) return 0;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[-1].str);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[-1].str);
		strcpy(yyval.str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 49:
#line 583 "x.yacc"
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
#line 610 "x.yacc"
    {
	fprintf(cfo,"switch(r.%s) {\n",yyvsp[-1].str);
	fprintf(cfi,"switch(r->%s) {\n",yyvsp[-1].str);

	fprintf(hsf,"%s;\nunion {\n",sw_elem);

}
    break;

  case 51:
#line 616 "x.yacc"
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

  case 54:
#line 632 "x.yacc"
    {
	fprintf(cfo,"case %s:\n",yyvsp[-1].str);
	fprintf(cfi,"case %s:\n",yyvsp[-1].str);
	}
    break;

  case 55:
#line 636 "x.yacc"
    {
	fprintf(cfo,"         break;\n");
	fprintf(cfi,"         break;\n");
	}
    break;

  case 58:
#line 646 "x.yacc"
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
#line 1832 "y.tab.c"

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


#line 657 "x.yacc"



#include "lex.yy.c"


