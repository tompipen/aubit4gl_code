/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
     CH = 290,
     HEX_INT_VAL = 291,
     PROGRAM = 292,
     VERSION = 293
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
#define HEX_INT_VAL 291
#define PROGRAM 292
#define VERSION 293




/* Copy the first part of user declarations.  */
#line 1 "x.yacc"


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
#line 442 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 454 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
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
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  38
/* YYNRULES -- Number of rules. */
#define YYNRULES  81
/* YYNRULES -- Number of states. */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    24,    29,    33,    37,    42,    45,    48,    53,    54,
      62,    64,    68,    70,    74,    80,    82,    84,    86,    88,
      90,    91,    99,   101,   104,   106,   110,   115,   118,   123,
     129,   132,   136,   140,   143,   146,   149,   152,   155,   158,
     161,   164,   167,   170,   174,   175,   176,   189,   191,   194,
     196,   198,   199,   205,   206,   208,   211,   213,   215,   217,
     219,   221,   223,   225,   227,   230,   232,   234,   236,   238,
     240,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      40,     0,    -1,    41,    -1,    40,    41,    -1,    50,    -1,
      57,    -1,    48,    -1,    44,    -1,    42,    -1,    76,    -1,
      15,    43,     8,    -1,     9,    12,    10,    12,    -1,     9,
      12,    12,    -1,    13,    12,    12,    -1,    13,    12,    10,
      12,    -1,    23,    12,    -1,    24,    12,    -1,    22,    12,
      20,    21,    -1,    -1,     6,    12,    45,     3,    46,     4,
       8,    -1,    47,    -1,    46,     7,    47,    -1,    12,    -1,
      12,    34,    31,    -1,     5,    12,    34,    49,     8,    -1,
      31,    -1,    12,    -1,    67,    -1,    33,    -1,    36,    -1,
      -1,     9,    12,    51,     3,    52,     4,     8,    -1,    54,
      -1,    52,    54,    -1,    12,    -1,    12,    20,    21,    -1,
      12,    29,    31,    30,    -1,    10,    12,    -1,    10,    12,
      20,    21,    -1,    10,    12,    29,    31,    30,    -1,    55,
       8,    -1,     6,    12,    53,    -1,     9,    12,    53,    -1,
      12,    53,    -1,    28,    53,    -1,    23,    53,    -1,    24,
      53,    -1,    25,    53,    -1,    22,    53,    -1,    27,    53,
      -1,    26,    53,    -1,    12,    12,    -1,    23,    12,    -1,
       6,    12,    12,    -1,    -1,    -1,    13,    12,    14,    16,
      58,    56,    17,    59,     3,    60,     4,     8,    -1,    62,
      -1,    60,    62,    -1,    11,    -1,    55,    -1,    -1,    18,
      66,    19,    63,    64,    -1,    -1,    65,    -1,    61,     8,
      -1,    12,    -1,    31,    -1,    32,    -1,    12,    -1,    12,
      -1,    31,    -1,    36,    -1,    75,    -1,    71,    75,    -1,
      12,    -1,    11,    -1,    12,    -1,    11,    -1,    12,    -1,
      72,    74,    16,    73,    17,    34,    31,     8,    -1,    37,
      68,     3,    38,    69,     3,    71,     4,    34,    70,     8,
       4,    34,    70,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   332,   332,   332,   335,   336,   337,   338,   339,   340,
     345,   349,   363,   374,   385,   396,   397,   398,   401,   401,
     426,   426,   429,   444,   463,   469,   469,   469,   469,   469,
     472,   472,   510,   510,   513,   519,   525,   531,   537,   543,
     551,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   571,   577,   583,   591,   618,   591,   637,   637,   640,
     640,   644,   644,   651,   651,   655,   661,   661,   665,   676,
     677,   679,   679,   683,   683,   686,   686,   687,   687,   688,
     691,   696
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPEN_BRACE", "CLOSE_BRACE", "CONST",
  "ENUM", "COMMA", "SEMICOLON", "STRUCT", "STAR", "VOID", "NAMED", "UNION",
  "SWITCH", "TYPEDEF", "OPEN_BRACKET", "CLOSE_BRACKET", "CASE", "COLON",
  "LESS_THAN", "GREATER_THAN", "STRING", "INT", "LONG", "SHORT", "DOUBLE",
  "OPAQUE", "BOOL", "OPEN_SQUARE", "CLOSE_SQUARE", "INT_VAL", "STRING_VAL",
  "NUMBER_VAL", "EQUAL", "CH", "HEX_INT_VAL", "PROGRAM", "VERSION",
  "$accept", "x", "xset", "typedef", "typedef_elem", "enum", "@1",
  "enum_list", "enum_element", "const", "value", "struct", "@2",
  "struct_list", "vname", "struct_element", "element", "switch_element",
  "union", "@3", "@4", "union_list", "uelement", "union_element", "@5",
  "op_union_element_desc", "union_element_desc", "case_val", "string",
  "program_name", "version_name", "hex_int_value", "function_def_list",
  "func_rval", "pval", "func_name", "function_def", "program", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    41,    41,    41,
      42,    43,    43,    43,    43,    43,    43,    43,    45,    44,
      46,    46,    47,    47,    48,    49,    49,    49,    49,    49,
      51,    50,    52,    52,    53,    53,    53,    53,    53,    53,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56,    58,    59,    57,    60,    60,    61,
      61,    63,    62,    64,    64,    65,    66,    66,    67,    68,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      75,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     3,     4,     2,     2,     4,     0,     7,
       1,     3,     1,     3,     5,     1,     1,     1,     1,     1,
       0,     7,     1,     2,     1,     3,     4,     2,     4,     5,
       2,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     0,     0,    12,     1,     2,     1,
       1,     0,     5,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       8,    15
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     8,
       7,     6,     4,     5,     9,     0,    18,    30,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     1,     3,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    10,     0,
      26,    25,    68,    28,    29,     0,    27,     0,     0,    54,
       0,    12,     0,    13,     0,     0,    24,    22,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,    11,    14,    17,    70,     0,     0,
       0,     0,     0,     0,     0,    34,    43,    48,    45,    46,
      47,    50,    49,    44,     0,    33,    40,     0,     0,     0,
       0,     0,    23,    19,    21,    41,    42,    37,     0,     0,
      31,     0,    51,    52,    55,    76,    75,     0,     0,    73,
       0,     0,    35,     0,    53,     0,     0,    74,    79,     0,
      38,     0,    36,     0,     0,     0,    39,     0,     0,    57,
      71,    72,     0,    78,    77,     0,    66,    67,     0,     0,
      58,     0,     0,    61,    56,     0,     0,    63,     0,     0,
      59,    60,     0,    62,    64,     0,    80,    65,    81
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     7,     8,     9,    24,    10,    30,    58,    59,    11,
      45,    12,    31,    70,    86,    71,    72,   100,    13,    73,
     125,   138,   162,   139,   157,   163,   164,   148,    46,    26,
      78,   142,   117,   118,   145,   129,   119,    14
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -23
static const short int yypact[] =
{
       5,    -4,    24,    27,    47,    73,    61,     0,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -22,   -23,   -23,    85,    81,
      88,    89,    90,    91,    96,   -23,   102,   -23,   -23,   -10,
     103,   104,    92,    22,    50,    93,   -23,   -23,   -23,    71,
     -23,   -23,   -23,   -23,   -23,   106,   -23,    98,    52,   -23,
      99,   -23,   100,   -23,    94,   105,   -23,    84,    -3,   -23,
     107,   108,    82,    82,    82,    82,    82,    82,    82,    82,
      21,   -23,   113,    75,   -23,   -23,   -23,   -23,   119,    95,
     115,    98,    82,    82,   112,   -13,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   117,   -23,   -23,   116,   118,   120,
     110,    17,   -23,   -23,   -23,   -23,   -23,    43,   114,   109,
     -23,   121,   -23,   -23,   -23,   -23,   -23,    79,   122,   -23,
     123,   111,   -23,    86,   -23,   126,    97,   -23,   -23,   125,
     -23,   124,   -23,   127,   -12,    77,   -23,    19,    -1,   -23,
     -23,   -23,   128,   -23,   -23,   129,   -23,   -23,   130,   131,
     -23,   133,   132,   -23,   -23,   134,   136,    29,   -12,   135,
     -23,   -23,   139,   -23,   -23,   140,   -23,   -23,   -23
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -23,   -23,   143,   -23,   -23,   -23,   -23,   -23,    57,   -23,
     -23,   -23,   -23,   -23,     2,    83,    -6,   -23,   -23,   -23,
     -23,   -23,   -23,    14,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,    -2,   -23,   -23,   -23,   -23,    38,   -23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      27,    80,    40,   149,    81,     1,     2,   108,    15,     3,
       1,     2,    29,     4,     3,     5,   109,   137,     4,   140,
       5,    41,    42,    43,   141,    94,    44,    60,   115,   116,
      61,   146,    50,    62,    51,    60,    16,     6,    61,    17,
     160,    62,     6,    63,    64,    65,    66,    67,    68,    69,
     147,    63,    64,    65,    66,    67,    68,    69,    60,    18,
      52,    61,    53,   120,    62,    87,    88,    89,    90,    91,
      92,    93,   121,    25,    63,    64,    65,    66,    67,    68,
      69,    97,    19,   126,   105,   106,    20,    98,   143,   144,
     115,   116,    84,    33,    85,    21,    22,    23,    99,    32,
      34,    35,    36,    37,    38,    39,    47,    48,    49,    55,
      57,    74,    75,    54,    56,    76,   132,    77,    79,    82,
      83,    96,   101,   103,   107,   110,   102,   114,   111,   133,
     112,   134,   113,   124,   128,   122,   151,   155,   104,   154,
     123,   135,   131,   166,   130,   137,   152,   167,   168,   153,
      28,   161,   150,    95,   136,   127,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   156,   159,   158
};

static const short int yycheck[] =
{
       0,     4,    12,     4,     7,     5,     6,    20,    12,     9,
       5,     6,    34,    13,     9,    15,    29,    18,    13,    31,
      15,    31,    32,    33,    36,     4,    36,     6,    11,    12,
       9,    12,    10,    12,    12,     6,    12,    37,     9,    12,
      11,    12,    37,    22,    23,    24,    25,    26,    27,    28,
      31,    22,    23,    24,    25,    26,    27,    28,     6,    12,
      10,     9,    12,    20,    12,    63,    64,    65,    66,    67,
      68,    69,    29,    12,    22,    23,    24,    25,    26,    27,
      28,     6,     9,     4,    82,    83,    13,    12,    11,    12,
      11,    12,    10,    12,    12,    22,    23,    24,    23,    14,
      12,    12,    12,    12,     8,     3,     3,     3,    16,    38,
      12,    12,    12,    20,     8,    21,    30,    12,    34,    12,
      12,     8,     3,     8,    12,     8,    31,    17,    12,     3,
      12,    34,    12,    12,    12,    21,     8,     4,    81,     8,
      31,    16,    31,     8,    21,    18,    17,     8,     8,    19,
       7,   157,   138,    70,    30,   117,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    31,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     5,     6,     9,    13,    15,    37,    40,    41,    42,
      44,    48,    50,    57,    76,    12,    12,    12,    12,     9,
      13,    22,    23,    24,    43,    12,    68,     0,    41,    34,
      45,    51,    14,    12,    12,    12,    12,    12,     8,     3,
      12,    31,    32,    33,    36,    49,    67,     3,     3,    16,
      10,    12,    10,    12,    20,    38,     8,    12,    46,    47,
       6,     9,    12,    22,    23,    24,    25,    26,    27,    28,
      52,    54,    55,    58,    12,    12,    21,    12,    69,    34,
       4,     7,    12,    12,    10,    12,    53,    53,    53,    53,
      53,    53,    53,    53,     4,    54,     8,     6,    12,    23,
      56,     3,    31,     8,    47,    53,    53,    12,    20,    29,
       8,    12,    12,    12,    17,    11,    12,    71,    72,    75,
      20,    29,    21,    31,    12,    59,     4,    75,    12,    74,
      21,    31,    30,     3,    34,    16,    30,    18,    60,    62,
      31,    36,    70,    11,    12,    73,    12,    31,    66,     4,
      62,     8,    17,    19,     8,     4,    34,    63,    34,    31,
      11,    55,    61,    64,    65,    70,     8,     8,     8
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
#define YYERROR		goto yyerrorlab


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
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
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
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
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
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
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

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
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
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

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
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
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
        case 11:
#line 349 "x.yacc"
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

  case 12:
#line 363 "x.yacc"
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

  case 13:
#line 374 "x.yacc"
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

  case 14:
#line 385 "x.yacc"
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

  case 15:
#line 396 "x.yacc"
    { fprintf(hsf,"typedef %s %s;\n",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 16:
#line 397 "x.yacc"
    { fprintf(hsf,"typedef %s %s;\n",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 17:
#line 398 "x.yacc"
    {fprintf(hsf,"typedef char *%s;\n",yyvsp[-2].str);}
    break;

  case 18:
#line 401 "x.yacc"
    {
	cu_cnt++;
	strcpy(cu[cu_cnt],"");
	enumv=0;
	fprintf(hf,"int output_%s(char *rn,int r,int isptr,int arr);\n",yyvsp[0].str);
	fprintf(cfo,"int output_%s(char *rn,int r,int isptr,int arr){\n",yyvsp[0].str);

	fprintf(hf,"int input_%s(char *rn,enum %s *r,int isptr,int arr);\n",yyvsp[0].str,yyvsp[0].str);
	fprintf(cfi,"int input_%s(char *rn,enum %s *r,int isptr,int arr){\n",yyvsp[0].str,yyvsp[0].str);

	fprintf(cfo,"char *name=\"%s\";\nA4GL_debug(\"Writing %s\");\n",yyvsp[0].str,yyvsp[0].str);
/*	fprintf(cfi,"char *name=\"%s\";\n",$<str>2); */

	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",yyvsp[0].str);

	fprintf(hsf,"enum %s {",yyvsp[0].str);
	}
    break;

  case 19:
#line 418 "x.yacc"
    {
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"   if (!input_enum(name,(int *)r)) return 0;\nreturn 1;\n}\n\n");
	fprintf(hsf,"\n};\ntypedef enum %s %s;\n\n",yyvsp[-5].str,yyvsp[-5].str);
	cu_cnt--;
}
    break;

  case 22:
#line 429 "x.yacc"
    {
		fprintf(cfo,"if (r==%d) {\n", enumv);
		fprintf(cfo,"  if (!output_enum(name,\"%s\",%d)) return 0;\n",yyvsp[0].str,enumv);
		fprintf(cfo,"}\n");

		/*fprintf(cfi,"if (r==%d) {\n", enumv); */
		/*fprintf(cfi,"  if (!input_enum(name,\"%s\",%d)) return 0;\n",$<str>1,enumv); */
		/*fprintf(cfi,"}\n"); */

		if (enumv) fprintf(hsf,",\n");
		else       fprintf(hsf,"\n");
		fprintf(hsf," %s = %d ",yyvsp[0].str,enumv);

		enumv++; 
	}
    break;

  case 23:
#line 444 "x.yacc"
    {
		enumv=atoi(yyvsp[0].str);
		fprintf(cfo,"if (r==%d) {\n", enumv);
		fprintf(cfo,"  if (!output_enum(name,\"%s\",%d)) return 0;\n",yyvsp[-2].str,enumv);
		fprintf(cfo,"}\n");

		/*fprintf(cfi,"if (r==%d) {\n", enumv); */
		/*fprintf(cfi,"  if (!input_enum(name,\"%s\",%d)) return 0;\n",$<str>1,enumv); */
		/*fprintf(cfi,"}\n"); */
		
		if (enumv) fprintf(hsf,",\n");
		else       fprintf(hsf,"\n");
		fprintf(hsf," %s = %d ",yyvsp[-2].str,enumv);

		enumv++; 
	}
    break;

  case 24:
#line 463 "x.yacc"
    {
	fprintf(hsf,"#define %s %s\n",yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 30:
#line 472 "x.yacc"
    {
	cu_cnt++;
	strcpy(cu[cu_cnt],"");
	fprintf(hsf,"struct %s {\n",yyvsp[0].str);
	fprintf(hf,"int output_%s(char *rn,%s r,int isptr,int arr);\n",yyvsp[0].str,yyvsp[0].str);
	fprintf(cfo,"int output_%s(char *rn,%s r,int isptr,int arr) {\n",yyvsp[0].str,yyvsp[0].str);
	
/*	fprintf(cfo,"char *name=\"%s\";\n",$<str>2); */

    /* sepatately defining and initialising to prevent compiler watnings about
    unised variable: */
	fprintf(cfo,"char *name;\n");
	fprintf(cfo,"name=\"%s\";\n",yyvsp[0].str);

	fprintf(cfo,"if (!output_start_struct(\"%s\",rn,isptr,arr)) return 0;\n",yyvsp[0].str);

	fprintf(hf,"int input_%s(char *rn,%s *r,int isptr,int arr);\n",yyvsp[0].str,yyvsp[0].str);
	fprintf(cfi,"int input_%s(char *rn,%s *r,int isptr,int arr) {\n",yyvsp[0].str,yyvsp[0].str);
/*	fprintf(cfi,"char *name=\"%s\";\n",$<str>2); */
	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",yyvsp[0].str);


	fprintf(cfi,"if (isptr==1&&r==0) return 1; /* Its just a null pointer */\n"); /* ,$<str>2); */

	fprintf(cfi,"if (!input_start_struct(\"%s\",rn,isptr,arr)) return 0;\n",yyvsp[0].str);


}
    break;

  case 31:
#line 500 "x.yacc"
    {
	fprintf(cfo,"if (!output_end_struct(\"%s\",rn)) return 0;\n",yyvsp[-5].str);
	fprintf(cfo,"return 1;\n}\n\n");
	fprintf(cfi,"if (!input_end_struct(\"%s\",rn)) return 0;\n",yyvsp[-5].str);
	fprintf(cfi,"return 1;\n}\n\n");
	fprintf(hsf,"};\ntypedef struct %s %s;\n\n",yyvsp[-5].str,yyvsp[-5].str);
	cu_cnt--;
}
    break;

  case 34:
#line 513 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=0;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[0].str);
	}
    break;

  case 35:
#line 519 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=1;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[-2].str);
	}
    break;

  case 36:
#line 525 "x.yacc"
    {
		yyval.mode.pointer=0;
		yyval.mode.type=2;
		yyval.mode.size=atoi(yyvsp[-1].str);
		strcpy(yyval.mode.name,yyvsp[-3].str);
	}
    break;

  case 37:
#line 531 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=0;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[0].str);
	}
    break;

  case 38:
#line 537 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=1;
		yyval.mode.size=-1;
		strcpy(yyval.mode.name,yyvsp[-2].str);
	}
    break;

  case 39:
#line 543 "x.yacc"
    {
		yyval.mode.pointer=1;
		yyval.mode.type=2;
		yyval.mode.size=atoi(yyvsp[-1].str);
		strcpy(yyval.mode.name,yyvsp[-3].str);
	}
    break;

  case 41:
#line 556 "x.yacc"
    { print_elem("enum",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 42:
#line 557 "x.yacc"
    { print_elem("struct",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 43:
#line 558 "x.yacc"
    { print_elem("istypedefed",yyvsp[-1].str,yyvsp[0].mode); }
    break;

  case 44:
#line 559 "x.yacc"
    { print_elem("bool","bool",yyvsp[0].mode); }
    break;

  case 45:
#line 560 "x.yacc"
    { print_elem("int","int",yyvsp[0].mode); }
    break;

  case 46:
#line 561 "x.yacc"
    { print_elem("long","long",yyvsp[0].mode); }
    break;

  case 47:
#line 562 "x.yacc"
    { print_elem("short","short",yyvsp[0].mode); }
    break;

  case 48:
#line 563 "x.yacc"
    { print_elem("string","string",yyvsp[0].mode); }
    break;

  case 49:
#line 564 "x.yacc"
    { print_elem("opaque","opaque",yyvsp[0].mode); }
    break;

  case 50:
#line 565 "x.yacc"
    { print_elem("double","double",yyvsp[0].mode); }
    break;

  case 51:
#line 571 "x.yacc"
    { 
		fprintf(cfo,"if (!output_%s(\"%s\",r.%s,isptr,arr)) return 0;\n",yyvsp[-1].str,yyvsp[0].str,yyvsp[0].str);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[-1].str,yyvsp[0].str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 52:
#line 577 "x.yacc"
    { 
		fprintf(cfo,"if (!output_int(\"%s\",r.%s,isptr,arr)) return 0;\n",yyvsp[0].str,yyvsp[0].str);
		fprintf(cfi,"if (!input_int(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[0].str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 53:
#line 583 "x.yacc"
    {
		fprintf(cfo,"if (!output_%s(\"%s\",&r.%s,isptr,arr)) return 0;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[-1].str);
		fprintf(cfi,"if (!input_%s(\"%s\",&r->%s,isptr,arr)) return 0;\n",yyvsp[-2].str,yyvsp[-1].str,yyvsp[-1].str);
		strcpy(yyval.str,yyvsp[0].str);
		sprintf(sw_elem,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 54:
#line 591 "x.yacc"
    {
	cu_cnt++;
	sprintf(cu[cu_cnt],"%s_u.",yyvsp[-2].str);

	fprintf(hf,"int output_%s(char *rn,%s r,int isptr,int arr);\n",yyvsp[-2].str,yyvsp[-2].str);
	fprintf(cfo,"int output_%s(char *rn,%s r,int isptr,int arr) {\n",yyvsp[-2].str,yyvsp[-2].str);
/*	fprintf(cfo,"char *name=\"%s\";\n",$<str>2); */

    /* sepatately defining and initialising to prevent compiler watnings about
    unised variable: */
	fprintf(cfo,"char *name;\n");
	fprintf(cfo,"name=\"%s\";\n",yyvsp[-2].str);


	fprintf(cfo,"if (!output_start_union(\"%s\",rn,isptr,arr)) return 0;\n",yyvsp[-2].str);

	fprintf(hf,"int input_%s(char *rn,%s *r,int isptr,int arr);\n",yyvsp[-2].str,yyvsp[-2].str);
	fprintf(cfi,"int input_%s(char *rn,%s *r,int isptr,int arr) {\n",yyvsp[-2].str,yyvsp[-2].str);
/*	fprintf(cfi,"char *name=\"%s\";\n",$<str>2); */
	fprintf(cfi,"char *name;\n");
	fprintf(cfi,"name=\"%s\";\n",yyvsp[-2].str);

	fprintf(cfi,"if (isptr==1&&r==0) return 1; /* Its just a null pointer */\n"); /* ,$<str>2); */
	fprintf(cfi,"if (!input_start_union(\"%s\",rn,isptr,arr)) return 0;\n",yyvsp[-2].str);

	fprintf(hsf,"struct %s {\n",yyvsp[-2].str);

	}
    break;

  case 55:
#line 618 "x.yacc"
    {
	fprintf(cfo,"switch(r.%s) {\n",yyvsp[-1].str);
	fprintf(cfi,"switch(r->%s) {\n",yyvsp[-1].str);

	fprintf(hsf,"%s;\nunion {\n",sw_elem);

}
    break;

  case 56:
#line 624 "x.yacc"
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

  case 61:
#line 644 "x.yacc"
    {
	fprintf(cfo,"case %s:\n",yyvsp[-1].str);
	fprintf(cfi,"case %s:\n",yyvsp[-1].str);
	}
    break;

  case 65:
#line 655 "x.yacc"
    {
	fprintf(cfo,"         break;\n");
	fprintf(cfi,"         break;\n");
	}
    break;

  case 68:
#line 665 "x.yacc"
    {
	char *ptr;
	ptr=acl_strdup(yyvsp[0].str);
	ptr++;
	ptr[strlen(ptr)-1]=0;
	strcpy(yyval.str,ptr);
	ptr--;
	free(ptr);
}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 1912 "y.tab.c"

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
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
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

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
	  yychar = YYEMPTY;

	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
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
      YYPOPSTACK;
      yystate = *yyssp;
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


#line 702 "x.yacc"



#include "lex.yy.c"

