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

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse a4gl_form_yyparse
#define yylex   a4gl_form_yylex
#define yyerror a4gl_form_yyerror
#define yylval  a4gl_form_yylval
#define yychar  a4gl_form_yychar
#define yydebug a4gl_form_yydebug
#define yynerrs a4gl_form_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CH = 258,
     GRAPH_CH = 259,
     INSTRUCTIONS = 260,
     ATTRIBUTES = 261,
     DATABASE = 262,
     BY = 263,
     KW_SCREEN_TITLE = 264,
     KW_SCREEN = 265,
     KW_SIZE = 266,
     OPEN_SQUARE = 267,
     KW_END = 268,
     CLOSE_SQUARE = 269,
     NUMBER_VALUE = 270,
     NAMED = 271,
     OPEN_BRACE = 272,
     CLOSE_BRACE = 273,
     TITLE = 274,
     FORMONLY = 275,
     COMMENT = 276,
     DYNAMIC = 277,
     COLON = 278,
     ATSIGN = 279,
     DOT = 280,
     WITHOUT = 281,
     KW_NULL = 282,
     INPUT = 283,
     TABLES = 284,
     PIPE = 285,
     EQUAL = 286,
     CHAR_VALUE = 287,
     SEMICOLON = 288,
     OPEN_BRACKET = 289,
     CLOSE_BRACKET = 290,
     STAR = 291,
     PLUS = 292,
     MINUS = 293,
     RECORD = 294,
     COMMA = 295,
     THROUGH = 296,
     TYPE = 297,
     DELIMITERS = 298,
     KW_CHAR = 299,
     KW_INT = 300,
     KW_DATE = 301,
     KW_FLOAT = 302,
     SMALLFLOAT = 303,
     SMALLINT = 304,
     KW_DECIMAL = 305,
     MONEY = 306,
     DATETIME = 307,
     INTERVAL = 308,
     LIKE = 309,
     BLACK = 310,
     BLUE = 311,
     GREEN = 312,
     CYAN = 313,
     RED = 314,
     MAGENTA = 315,
     WHITE = 316,
     YELLOW = 317,
     REVERSE = 318,
     LEFT = 319,
     BLINK = 320,
     UNDERLINE = 321,
     AUTONEXT = 322,
     COLOR = 323,
     COMMENTS = 324,
     DEFAULT = 325,
     VALIDATE = 326,
     DISPLAY = 327,
     DOWNSHIFT = 328,
     UPSHIFT = 329,
     FORMAT = 330,
     INCLUDE = 331,
     INVISIBLE = 332,
     NOENTRY = 333,
     PICTURE = 334,
     PROGRAM = 335,
     REQUIRED = 336,
     VERIFY = 337,
     WORDWRAP = 338,
     COMPRESS = 339,
     NONCOMPRESS = 340,
     TO = 341,
     AS = 342,
     SERIAL = 343,
     KW_BYTE = 344,
     KW_TEXT = 345,
     VARCHAR = 346,
     SQL_VAR = 347,
     KW_NONSPACE = 348,
     SQLONLY = 349,
     WIDGET = 350,
     CONFIG = 351,
     KW_NL = 352,
     COMPARISON = 353,
     KWOR = 354,
     KWAND = 355,
     KWWHERE = 356,
     KWNOT = 357,
     KWBETWEEN = 358,
     KWIN = 359,
     XVAL = 360,
     KWNULLCHK = 361,
     KWNOTNULLCHK = 362,
     YEAR = 363,
     MONTH = 364,
     DAY = 365,
     HOUR = 366,
     MINUTE = 367,
     SECOND = 368,
     FRACTION = 369,
     LISTBOX = 370,
     BUTTON = 371,
     KW_PANEL = 372,
     KW_WS = 373
   };
#endif
#define CH 258
#define GRAPH_CH 259
#define INSTRUCTIONS 260
#define ATTRIBUTES 261
#define DATABASE 262
#define BY 263
#define KW_SCREEN_TITLE 264
#define KW_SCREEN 265
#define KW_SIZE 266
#define OPEN_SQUARE 267
#define KW_END 268
#define CLOSE_SQUARE 269
#define NUMBER_VALUE 270
#define NAMED 271
#define OPEN_BRACE 272
#define CLOSE_BRACE 273
#define TITLE 274
#define FORMONLY 275
#define COMMENT 276
#define DYNAMIC 277
#define COLON 278
#define ATSIGN 279
#define DOT 280
#define WITHOUT 281
#define KW_NULL 282
#define INPUT 283
#define TABLES 284
#define PIPE 285
#define EQUAL 286
#define CHAR_VALUE 287
#define SEMICOLON 288
#define OPEN_BRACKET 289
#define CLOSE_BRACKET 290
#define STAR 291
#define PLUS 292
#define MINUS 293
#define RECORD 294
#define COMMA 295
#define THROUGH 296
#define TYPE 297
#define DELIMITERS 298
#define KW_CHAR 299
#define KW_INT 300
#define KW_DATE 301
#define KW_FLOAT 302
#define SMALLFLOAT 303
#define SMALLINT 304
#define KW_DECIMAL 305
#define MONEY 306
#define DATETIME 307
#define INTERVAL 308
#define LIKE 309
#define BLACK 310
#define BLUE 311
#define GREEN 312
#define CYAN 313
#define RED 314
#define MAGENTA 315
#define WHITE 316
#define YELLOW 317
#define REVERSE 318
#define LEFT 319
#define BLINK 320
#define UNDERLINE 321
#define AUTONEXT 322
#define COLOR 323
#define COMMENTS 324
#define DEFAULT 325
#define VALIDATE 326
#define DISPLAY 327
#define DOWNSHIFT 328
#define UPSHIFT 329
#define FORMAT 330
#define INCLUDE 331
#define INVISIBLE 332
#define NOENTRY 333
#define PICTURE 334
#define PROGRAM 335
#define REQUIRED 336
#define VERIFY 337
#define WORDWRAP 338
#define COMPRESS 339
#define NONCOMPRESS 340
#define TO 341
#define AS 342
#define SERIAL 343
#define KW_BYTE 344
#define KW_TEXT 345
#define VARCHAR 346
#define SQL_VAR 347
#define KW_NONSPACE 348
#define SQLONLY 349
#define WIDGET 350
#define CONFIG 351
#define KW_NL 352
#define COMPARISON 353
#define KWOR 354
#define KWAND 355
#define KWWHERE 356
#define KWNOT 357
#define KWBETWEEN 358
#define KWIN 359
#define XVAL 360
#define KWNULLCHK 361
#define KWNOTNULLCHK 362
#define YEAR 363
#define MONTH 364
#define DAY 365
#define HOUR 366
#define MINUTE 367
#define SECOND 368
#define FRACTION 369
#define LISTBOX 370
#define BUTTON 371
#define KW_PANEL 372
#define KW_WS 373




/* Copy the first part of user declarations.  */
#line 1 "screen.yacc"

#define YYDEBUG 1
/*
	y.tab.c was generated from screen.yacc using yacc
*/


/*
=====================================================================
		                    Includes
=====================================================================
*/

/* prevent warning for redundant declaration of yyparse / fgl_comp_parse: */
#define _BISON_SIMPLE_INCL_
#define _NO_WINDOWS_H_

#include "a4gl_fcompile_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern struct struct_scr_field *fld;
int graphics_mode=0;
extern int ignorekw;
extern int lineno;
extern int colno;
extern int scr;
int in_comment;
long fileseek=0;

dll_import struct_form the_form;

extern int newscreen;
extern int fldno;
extern int fstart;
extern int openwith;
extern char currftag[256];
extern char *outputfilename;
extern char *tablist[];
int A4GL_get_dtype_size(void) ;
int A4GL_get_attr_from_string (char *s);
/* extern FILE *yyin; */
int in_screen_section=0;
int dtype_size=0;
char *rm_dup_quotes(char *s) ;
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *chk_alias(char *s);
/* extern char *char_val(char*s); */

/*
=====================================================================
                    Functions definitions
=====================================================================
*/




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
#line 71 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 392 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 404 "y.tab.c"

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
#define YYFINAL  89
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1476

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  88
/* YYNRULES -- Number of rules. */
#define YYNRULES  324
/* YYNRULES -- Number of states. */
#define YYNSTATES  463

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   373

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    37,    39,    42,    43,    47,    48,    53,    54,    55,
      56,    65,    66,    69,    74,    75,    77,    79,    82,    84,
      86,    88,    90,    92,    94,    96,    98,   100,   102,   104,
     107,   108,   113,   115,   116,   121,   122,   126,   128,   131,
     135,   138,   139,   142,   144,   148,   152,   158,   162,   166,
     168,   171,   172,   177,   179,   182,   183,   184,   191,   192,
     196,   202,   206,   208,   209,   215,   219,   222,   227,   231,
     233,   234,   237,   239,   243,   245,   250,   254,   258,   262,
     268,   272,   278,   280,   282,   286,   292,   296,   300,   302,
     307,   309,   311,   313,   317,   321,   323,   325,   327,   329,
     332,   335,   337,   339,   341,   343,   346,   348,   350,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   371,
     372,   377,   379,   382,   384,   387,   390,   391,   401,   414,
     415,   418,   419,   421,   423,   428,   430,   434,   435,   437,
     439,   443,   447,   451,   455,   457,   461,   463,   464,   466,
     468,   471,   473,   477,   479,   481,   483,   485,   487,   489,
     492,   495,   498,   501,   503,   505,   507,   509,   511,   513,
     517,   519,   522,   525,   527,   529,   533,   535,   537,   541,
     545,   547,   548,   552,   558,   559,   563,   564,   568,   570,
     573,   575,   577,   579,   581,   583,   585,   588,   590,   591,
     595,   597,   599,   601,   603,   605,   607,   609,   611,   614,
     615,   619,   620,   622,   625,   627,   631,   635,   639,   643,
     648,   652,   655,   658,   660,   666,   672,   675,   679,   681,
     683,   685,   687,   689,   691,   695,   697,   699,   701,   703,
     705,   707,   709,   711,   713,   715,   717,   719,   721,   723,
     725,   727,   729,   731,   733,   735,   737,   739,   741,   743,
     745,   747,   749,   751,   753,   755,   757,   759,   761,   763,
     765,   767,   769,   771,   773,   775,   777,   779,   781,   783,
     785,   787,   789,   791,   793,   795,   797,   799,   801,   803,
     805,   807,   809,   811,   813,   815,   817,   819,   821,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   851,   853
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     120,     0,    -1,   121,   124,   142,   147,   165,    -1,     7,
      20,    -1,     7,   123,    26,    27,    28,    -1,     7,    20,
      26,    27,    28,    -1,     7,   123,    -1,    16,    -1,   206,
      -1,   122,    -1,   122,    24,   122,    -1,   125,    -1,   124,
     125,    -1,    -1,    10,   126,   128,    -1,    -1,     9,    32,
     127,   128,    -1,    -1,    -1,    -1,   132,   129,    17,   130,
     134,    18,   131,   133,    -1,    -1,    11,    15,    -1,    11,
      15,     8,    15,    -1,    -1,    13,    -1,   136,    -1,   134,
     136,    -1,   122,    -1,   135,    -1,   138,    -1,     4,    -1,
      30,    -1,    32,    -1,   137,    -1,   118,    -1,    97,    -1,
      93,    -1,     3,    -1,   137,     3,    -1,    -1,    12,   139,
     140,    14,    -1,   182,    -1,    -1,   140,    30,   141,   182,
      -1,    -1,    29,   143,   133,    -1,   144,    -1,   143,   144,
      -1,   143,    40,   144,    -1,   122,   145,    -1,    -1,    31,
     146,    -1,   122,    -1,   122,    23,   122,    -1,   122,    24,
     122,    -1,   122,    24,   122,    23,   122,    -1,   122,    25,
     122,    -1,     6,   148,   133,    -1,   149,    -1,   148,   149,
      -1,    -1,   181,   150,   151,    33,    -1,   152,    -1,   151,
     152,    -1,    -1,    -1,    31,   153,   158,   155,   154,   159,
      -1,    -1,    12,    15,    14,    -1,    12,    15,    40,    15,
      14,    -1,   157,   102,    27,    -1,   157,    -1,    -1,    42,
      54,   122,    25,   122,    -1,    42,    54,   122,    -1,    42,
     183,    -1,    20,    25,   178,   156,    -1,   122,    25,   122,
      -1,   122,    -1,    -1,    40,   160,    -1,   161,    -1,   160,
      40,   161,    -1,    67,    -1,    68,    31,   163,   199,    -1,
      69,    31,    32,    -1,    70,    31,   162,    -1,    72,    54,
     122,    -1,    72,    54,   122,    25,   122,    -1,    71,    54,
     122,    -1,    71,    54,   122,    25,   122,    -1,    73,    -1,
      74,    -1,    75,    31,    32,    -1,    76,    31,    34,   184,
      35,    -1,    95,    31,    32,    -1,    96,    31,    32,    -1,
      77,    -1,    22,    11,    31,    15,    -1,    22,    -1,    94,
      -1,    78,    -1,    79,    31,    32,    -1,    80,    31,    32,
      -1,    81,    -1,    63,    -1,    82,    -1,    83,    -1,    83,
      84,    -1,    83,    85,    -1,    32,    -1,    15,    -1,    92,
      -1,   164,    -1,   163,   164,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,
      62,    -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,
      -1,    -1,     5,   166,   167,   133,    -1,   168,    -1,   167,
     168,    -1,   169,    -1,   169,    33,    -1,    43,    32,    -1,
      -1,    10,    39,   170,   173,    34,   174,    35,   171,   172,
      -1,   117,    34,    15,    40,    15,    35,    86,    34,    15,
      40,    15,    35,    -1,    -1,    87,   115,    -1,    -1,    33,
      -1,   122,    -1,   122,    12,    15,    14,    -1,   177,    -1,
     174,   175,   177,    -1,    -1,    40,    -1,   122,    -1,   122,
      25,   122,    -1,    20,    25,   122,    -1,   122,    25,    36,
      -1,    20,    25,    36,    -1,   176,    -1,   176,    41,   176,
      -1,   122,    -1,    -1,   180,    -1,   118,    -1,   180,   118,
      -1,   122,    -1,   179,   122,   179,    -1,    44,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,
     187,    -1,    51,   187,    -1,    52,   194,    -1,    53,   188,
      -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,   116,
      -1,   186,    -1,   184,    40,   186,    -1,    15,    -1,    37,
      15,    -1,    38,    15,    -1,    32,    -1,    16,    -1,    16,
      86,    16,    -1,     3,    -1,   185,    -1,   185,    86,   185,
      -1,    32,    86,    32,    -1,    27,    -1,    -1,    34,    15,
      35,    -1,    34,    15,    40,    15,    35,    -1,    -1,   191,
      86,   193,    -1,    -1,    34,    15,    35,    -1,    15,    -1,
     192,   189,    -1,   108,    -1,   109,    -1,   110,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,   198,    -1,   192,    -1,
      -1,   195,    86,   196,    -1,   197,    -1,   197,    -1,   108,
      -1,   109,    -1,   110,    -1,   111,    -1,   112,    -1,   113,
      -1,   114,   198,    -1,    -1,    34,   190,    35,    -1,    -1,
     200,    -1,   101,   201,    -1,   202,    -1,   202,   100,   202,
      -1,   202,    99,   202,    -1,   203,    98,   203,    -1,   203,
      54,   203,    -1,   203,   102,    54,   203,    -1,   203,    31,
     203,    -1,   203,   106,    -1,   203,   107,    -1,   203,    -1,
     203,   103,   203,   100,   203,    -1,   203,   104,    34,   205,
      35,    -1,   102,   202,    -1,    34,   202,    35,    -1,   204,
      -1,    15,    -1,    32,    -1,   105,    -1,    16,    -1,   203,
      -1,   205,    40,   203,    -1,    87,    -1,    67,    -1,    55,
      -1,    65,    -1,    56,    -1,    99,    -1,   100,    -1,    98,
      -1,   116,    -1,     8,    -1,    68,    -1,    21,    -1,    69,
      -1,    84,    -1,    96,    -1,    58,    -1,     7,    -1,    52,
      -1,    70,    -1,    43,    -1,    73,    -1,    22,    -1,    75,
      -1,    57,    -1,    76,    -1,    28,    -1,    53,    -1,    77,
      -1,    89,    -1,    44,    -1,    46,    -1,    50,    -1,    47,
      -1,    45,    -1,    27,    -1,   117,    -1,    10,    -1,     9,
      -1,    11,    -1,    90,    -1,    64,    -1,   115,    -1,    60,
      -1,    51,    -1,    78,    -1,    85,    -1,   102,    -1,    79,
      -1,    80,    -1,    39,    -1,    59,    -1,    81,    -1,    63,
      -1,    88,    -1,    48,    -1,    49,    -1,    94,    -1,    92,
      -1,    29,    -1,    41,    -1,    19,    -1,    86,    -1,    66,
      -1,    74,    -1,    91,    -1,    82,    -1,    61,    -1,    95,
      -1,    26,    -1,    83,    -1,    62,    -1,    42,    -1,    54,
      -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,
      -1,   113,    -1,   114,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    99,    99,   102,   103,   108,   109,   117,   118,   122,
     122,   125,   125,   128,   128,   141,   141,   161,   163,   166,
     160,   173,   174,   175,   187,   188,   193,   194,   197,   211,
     217,   219,   228,   238,   245,   253,   254,   255,   261,   262,
     268,   267,   285,   290,   289,   310,   311,   314,   315,   316,
     319,   326,   327,   330,   331,   332,   334,   335,   341,   345,
     345,   349,   349,   358,   358,   361,   365,   361,   389,   390,
     394,   402,   403,   406,   407,   410,   413,   418,   427,   435,
     444,   445,   449,   449,   452,   453,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     488,   489,   490,   491,   492,   493,   496,   499,   502,   505,
     509,   515,   516,   517,   519,   519,   525,   528,   531,   534,
     537,   540,   543,   546,   549,   552,   555,   558,   562,   563,
     563,   568,   568,   570,   570,   573,   583,   583,   586,   589,
     589,   591,   591,   594,   597,   613,   616,   620,   621,   625,
     627,   629,   631,   633,   638,   638,   642,   648,   648,   651,
     651,   657,   665,   673,   677,   681,   685,   689,   693,   697,
     701,   705,   709,   713,   717,   721,   725,   728,   735,   735,
     740,   740,   740,   745,   746,   747,   748,   749,   750,   753,
     757,   763,   764,   765,   768,   769,   776,   778,   783,   791,
     794,   795,   796,   797,   798,   799,   800,   806,   808,   809,
     812,   815,   819,   820,   821,   822,   823,   824,   825,   831,
     833,   840,   840,   846,   852,   853,   856,   862,   865,   868,
     871,   874,   879,   884,   888,   894,   897,   900,   905,   912,
     915,   916,   921,   924,   928,   936,   937,   938,   939,   940,
     941,   942,   943,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   966,   967,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982,   983,   984,   985,   986,   987,   988,   989,   990,
     991,   992,   993,   994,   995,   996,   997,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,
    1011,  1012,  1013,  1014,  1015
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "GRAPH_CH", "INSTRUCTIONS", 
  "ATTRIBUTES", "DATABASE", "BY", "KW_SCREEN_TITLE", "KW_SCREEN", 
  "KW_SIZE", "OPEN_SQUARE", "KW_END", "CLOSE_SQUARE", "NUMBER_VALUE", 
  "NAMED", "OPEN_BRACE", "CLOSE_BRACE", "TITLE", "FORMONLY", "COMMENT", 
  "DYNAMIC", "COLON", "ATSIGN", "DOT", "WITHOUT", "KW_NULL", "INPUT", 
  "TABLES", "PIPE", "EQUAL", "CHAR_VALUE", "SEMICOLON", "OPEN_BRACKET", 
  "CLOSE_BRACKET", "STAR", "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", 
  "TYPE", "DELIMITERS", "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", 
  "SMALLFLOAT", "SMALLINT", "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", 
  "LIKE", "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", 
  "YELLOW", "REVERSE", "LEFT", "BLINK", "UNDERLINE", "AUTONEXT", "COLOR", 
  "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY", "DOWNSHIFT", "UPSHIFT", 
  "FORMAT", "INCLUDE", "INVISIBLE", "NOENTRY", "PICTURE", "PROGRAM", 
  "REQUIRED", "VERIFY", "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO", "AS", 
  "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR", "KW_NONSPACE", 
  "SQLONLY", "WIDGET", "CONFIG", "KW_NL", "COMPARISON", "KWOR", "KWAND", 
  "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", 
  "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", 
  "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "KW_WS", "$accept", 
  "form_def", "database_section", "named_or_kw", "dbname", 
  "screen_section", "screens_section", "@1", "@2", "screens_rest", "@3", 
  "@4", "@5", "op_size", "op_end", "screen_layout", "some_text", 
  "screen_element", "ch_list", "field", "@6", "field_element", "@7", 
  "op_table_section", "table_def_list", "table_def", "opequal", 
  "table_qualifier", "attribute_section", "field_tag_list", "field_tag", 
  "@8", "fpart_list", "fpart", "@9", "@10", "op_att", 
  "field_datatype_null", "field_datatype", "field_type", "op_field_desc", 
  "op_desc_list", "desc", "def_val", "colors", "color", 
  "op_instruction_section", "@11", "instruct_opts", "instruct_op_1", 
  "instruct_op", "@12", "op_ltype", "op_semi", "srec_dim", 
  "srec_field_list", "op_comma", "field_list_item", "field_list_element", 
  "field_name", "op_ws", "ws", "field_tag_name", "field_tag_name_scr", 
  "datatype", "incl_list", "number_value", "incl_entry", "opt_dec_ext", 
  "opt_int_ext", "opt_unit_size", "dtfrac", "int_start", "int_start_unit", 
  "int_end", "opt_dt_ext", "dt_start", "dt_end", "dtime_val", "opt_frac", 
  "op_where", "where_clause", "clauses", "clause", "value", 
  "fieldidentifier", "value_list", "any_kword", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   119,   120,   121,   121,   121,   121,   122,   122,   123,
     123,   124,   124,   126,   125,   127,   125,   129,   130,   131,
     128,   132,   132,   132,   133,   133,   134,   134,   135,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   137,   137,
     139,   138,   140,   141,   140,   142,   142,   143,   143,   143,
     144,   145,   145,   146,   146,   146,   146,   146,   147,   148,
     148,   150,   149,   151,   151,   153,   154,   152,   155,   155,
     155,   156,   156,   157,   157,   157,   157,   158,   158,   158,
     159,   159,   160,   160,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   162,   162,   162,   163,   163,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   165,   166,
     165,   167,   167,   168,   168,   169,   170,   169,   169,   171,
     171,   172,   172,   173,   173,   174,   174,   175,   175,   176,
     176,   176,   176,   176,   177,   177,   178,   179,   179,   180,
     180,   181,   182,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   184,   184,
     185,   185,   185,   186,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   187,   188,   188,   189,   189,   190,   191,
     192,   192,   192,   192,   192,   192,   192,   193,   194,   194,
     195,   196,   197,   197,   197,   197,   197,   197,   197,   198,
     198,   199,   199,   200,   201,   201,   201,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   203,   203,
     203,   203,   204,   205,   205,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     2,     0,     3,     0,     4,     0,     0,     0,
       8,     0,     2,     4,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     4,     1,     0,     4,     0,     3,     1,     2,     3,
       2,     0,     2,     1,     3,     3,     5,     3,     3,     1,
       2,     0,     4,     1,     2,     0,     0,     6,     0,     3,
       5,     3,     1,     0,     5,     3,     2,     4,     3,     1,
       0,     2,     1,     3,     1,     4,     3,     3,     3,     5,
       3,     5,     1,     1,     3,     5,     3,     3,     1,     4,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       4,     1,     2,     1,     2,     2,     0,     9,    12,     0,
       2,     0,     1,     1,     4,     1,     3,     0,     1,     1,
       3,     3,     3,     3,     1,     3,     1,     0,     1,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     1,     3,     1,     1,     3,     3,
       1,     0,     3,     5,     0,     3,     0,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     0,     1,     2,     1,     3,     3,     3,     3,     4,
       3,     2,     2,     1,     5,     5,     2,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   261,   254,   282,   281,   283,     7,
     305,     3,   256,   266,   313,   279,   270,   303,   294,   304,
     316,   264,   274,   278,   275,   277,   299,   300,   276,   288,
     262,   271,   317,   247,   249,   268,   260,   295,   287,   311,
     315,   297,   285,   248,   307,   246,   255,   257,   263,   265,
     308,   267,   269,   272,   289,   292,   293,   296,   310,   314,
     258,   290,   306,   245,   298,   273,   284,   309,   302,   301,
     312,   259,   252,   250,   251,   291,   318,   319,   320,   321,
     322,   323,   324,   286,   253,   280,     9,     6,     8,     1,
       0,    13,    45,    11,     0,     0,     0,    15,    21,     0,
      12,     0,     0,    10,     0,    21,     0,    14,    17,    51,
      24,    47,     0,   128,     5,     4,    16,    22,     0,     0,
      50,    25,     0,    46,    48,   161,    24,    59,    61,   129,
       2,     0,    18,    53,    52,    49,    58,    60,     0,     0,
      23,     0,     0,     0,     0,    65,     0,    63,     0,     0,
       0,    24,   131,   133,    38,    31,    40,    32,    33,    37,
      36,    35,    28,     0,    29,    26,    34,    30,    54,    55,
      57,     0,    62,    64,   136,   135,     0,   130,   132,   134,
     157,    19,    27,    39,     0,     0,    79,    68,     0,     0,
     159,     0,     0,   158,    42,    24,    56,     0,     0,     0,
      66,   143,     0,     0,    41,    43,   157,   160,    20,   156,
      73,    78,     0,    80,     0,     0,     0,   157,   162,     0,
      77,    72,    69,     0,     0,    67,     0,     0,   149,   147,
     154,   145,     0,    44,   163,   164,   165,   166,   167,   168,
     191,   191,   208,   194,     0,   173,   174,   175,   176,   177,
      76,     0,     0,   100,   106,    84,     0,     0,     0,     0,
       0,    92,    93,     0,     0,    98,   102,     0,     0,   105,
     107,   108,   101,     0,     0,    81,    82,   144,     0,     0,
     139,   148,     0,     0,     0,     0,   169,   170,   212,   213,
     214,   215,   216,   217,   219,   171,     0,   210,   200,   201,
     202,   203,   204,   205,   219,   172,     0,   196,    75,    71,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,     0,     0,     0,   153,   151,   152,   150,
       0,   141,   146,   155,     0,     0,     0,   218,     0,   206,
       0,     0,   199,     0,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   221,   114,    86,
     112,   111,   113,    87,    90,    88,    94,     0,   103,   104,
      96,    97,    83,   140,   142,   137,     0,   192,     0,   198,
       0,   209,   211,   207,   195,     0,    74,    99,     0,   115,
      85,   222,     0,     0,   186,   180,   184,   190,   183,     0,
       0,     0,   187,   178,     0,     0,   220,   197,   239,   242,
     240,     0,     0,   241,   223,   224,   233,   238,    91,    89,
       0,     0,   181,   182,    95,     0,     0,     0,   193,     0,
     236,     0,     0,     0,     0,     0,     0,     0,     0,   231,
     232,   185,   189,   179,   188,   138,   237,   226,   225,   230,
     228,   227,     0,     0,     0,   229,     0,   243,     0,   234,
     235,     0,   244
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   109,    87,    92,    93,    98,   105,   107,
     118,   141,   195,   108,   123,   163,   164,   165,   166,   167,
     180,   191,   217,   101,   110,   111,   120,   134,   113,   126,
     127,   138,   146,   147,   171,   213,   200,   220,   221,   187,
     225,   275,   276,   363,   357,   358,   130,   139,   151,   152,
     153,   188,   331,   375,   202,   229,   282,   230,   231,   210,
     192,   193,   128,   194,   250,   401,   402,   403,   286,   305,
     342,   380,   306,   307,   384,   295,   296,   381,   297,   337,
     390,   391,   414,   415,   416,   417,   458,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -313
static const short yypact[] =
{
      16,   693,    27,    20,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,    29,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,    51,    52,  -313,  -313,
      65,  -313,     9,  -313,    60,  1359,    80,  -313,    99,  1359,
    -313,   108,    87,  -313,    93,    99,   109,  -313,  -313,    92,
     582,  -313,  1359,   121,  -313,  -313,  -313,   124,   117,  1359,
    -313,  -313,  1359,  -313,  -313,  -313,   804,  -313,  -313,  -313,
    -313,   120,  -313,    18,  -313,  -313,  -313,  -313,   105,    -8,
    -313,   470,  1359,  1359,  1359,  -313,   -18,  -313,    98,   106,
     110,    -9,  -313,   112,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,   354,  -313,  -313,   136,  -313,  -313,   123,
    -313,   915,  -313,  -313,  -313,  -313,   132,  -313,  -313,  -313,
      31,  -313,  -313,  -313,  1359,   126,   128,   142,  1359,   115,
    -313,    -2,  1359,    38,  -313,   145,  -313,  1359,  1359,   144,
    -313,   148,   127,   156,  -313,  -313,    31,  -313,  -313,  -313,
     131,  -313,    -3,   134,   160,  1026,   141,    31,  -313,     0,
    -313,    75,  -313,   163,   150,  -313,   165,   155,   157,   -19,
     140,  -313,   100,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
     151,   151,   -40,    55,  1359,  -313,  -313,  -313,  -313,  -313,
    -313,   161,   170,   178,  -313,  -313,   159,   162,   164,   138,
     158,  -313,  -313,   179,   180,  -313,  -313,   184,   185,  -313,
    -313,    19,  -313,   203,   204,   154,  -313,  -313,  1137,  1248,
     149,  -313,  1026,  1026,   205,   222,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,   206,  -313,   152,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,   206,  -313,   166,   207,   217,  -313,
    -313,   216,   143,   218,   -12,  1359,  1359,   219,   214,   221,
     223,  -313,  -313,   224,   225,   150,  -313,  -313,  -313,  -313,
     139,   226,  -313,  -313,   234,    -4,   243,  -313,   -40,  -313,
      55,   245,  -313,  1359,   246,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,     1,  -313,  -313,
    -313,  -313,  -313,  -313,   237,   238,  -313,    90,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,   227,  -313,   249,  -313,
     230,  -313,  -313,  -313,  -313,   231,  -313,  -313,   -10,  -313,
    -313,  -313,  1359,  1359,  -313,  -313,   182,  -313,   183,   255,
     256,    44,   186,  -313,   258,   239,  -313,  -313,  -313,  -313,
    -313,   -10,   -10,  -313,  -313,    13,   -21,  -313,  -313,  -313,
     259,   244,  -313,  -313,  -313,    90,     2,   248,  -313,   250,
    -313,   -10,   -10,    -7,    -7,    -7,   232,    -7,   253,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,    -7,   188,    -7,  -313,    -7,  -313,    61,  -313,
    -313,    -7,  -313
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -313,  -313,  -313,    -1,  -313,  -313,   187,  -313,  -313,   175,
    -313,  -313,  -313,  -313,  -119,  -313,  -313,   129,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,   -96,  -313,  -313,  -313,  -313,
     167,  -313,  -313,   153,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,   -41,  -313,  -313,   -68,  -313,  -313,  -313,   146,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,     7,    12,  -313,
      85,  -313,  -313,    78,  -313,  -313,  -130,  -127,    59,  -313,
    -313,  -313,  -313,   -39,  -313,  -313,  -313,  -313,   -36,     3,
    -313,  -313,  -313,  -312,  -304,  -313,  -313,  -313
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      86,   148,   148,   360,   121,   408,   409,   136,   408,   409,
     433,   222,   204,   145,   124,   172,   280,   395,    90,    91,
     361,   281,   410,     1,   411,   410,   135,    89,   205,    90,
      91,   377,   177,   434,   149,   149,   378,   223,    99,   399,
     400,   142,   143,   144,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    94,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   288,   289,
     290,   291,   292,   293,   294,    95,   208,   435,    96,   424,
     362,   436,   437,   438,   425,   439,   440,   102,   245,   246,
     247,   248,   412,   394,   103,   413,   460,    97,   413,   429,
     430,   461,   388,   321,   322,   395,   396,   104,   150,   150,
     106,   125,   431,   432,   112,   114,   249,   397,   133,   447,
     448,   115,   398,   119,   117,   125,   129,   399,   400,   449,
     450,   451,   131,   453,   132,   140,   145,   174,   175,   183,
     162,   168,   169,   170,   176,   179,   184,   189,   455,   190,
     457,   197,   459,   198,   199,   203,   207,   462,   121,   212,
     214,   215,   162,   298,   299,   300,   301,   302,   303,   304,
     186,   216,   253,   219,   224,   226,   232,   251,   252,   277,
     278,   283,   279,   196,   310,   285,   284,   201,   309,   311,
     312,   206,   315,   313,   325,   314,   209,   211,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     317,   318,   316,   254,   228,   319,   320,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   323,   324,   330,   335,   338,   334,
     336,   341,   343,   308,   272,   273,   274,   344,   367,   376,
     359,   366,   340,   368,   373,   369,   370,   371,   379,   374,
     385,   387,   392,   393,   405,   406,   407,   404,   420,   421,
     422,   423,   426,   427,   428,   441,   442,   327,   329,   100,
     116,   228,   228,   445,   372,   446,   452,   454,   456,   389,
     333,   218,   182,   137,   332,   233,   444,   178,   443,   173,
     287,   383,   382,     0,     0,     0,     0,   339,     0,     0,
       0,     0,     0,     0,   364,   365,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   386,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   155,     0,
       0,     4,     5,     6,     7,     8,   156,     0,     0,     0,
       9,     0,   181,    10,     0,    12,    13,     0,     0,     0,
      14,    15,    16,    17,   157,     0,   158,     0,     0,     0,
       0,   418,   419,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   159,    69,    70,
      71,   160,    72,    73,    74,     0,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   161,   154,   155,     0,     0,     4,     5,     6,
       7,     8,   156,     0,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
     157,     0,   158,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   159,    69,    70,    71,   160,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   161,     4,
       5,     6,     7,     8,     0,   121,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,   122,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,     0,
      72,    73,    74,     0,    75,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,    10,    11,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
       0,    72,    73,    74,     0,    75,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     4,     5,     6,     7,     8,     0,   121,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,     0,    72,    73,    74,     0,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,   185,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,   227,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,     0,    72,    73,    74,     0,    75,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,   326,     0,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,   328,     0,     0,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,     0,    72,    73,    74,
       0,    75,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85
};

static const short yycheck[] =
{
       1,    10,    10,    15,    13,    15,    16,   126,    15,    16,
      31,    14,    14,    31,   110,    33,    35,    15,     9,    10,
      32,    40,    32,     7,    34,    32,   122,     0,    30,     9,
      10,    35,   151,    54,    43,    43,    40,    40,    29,    37,
      38,    23,    24,    25,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    26,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,   108,   109,
     110,   111,   112,   113,   114,    24,   195,    98,    26,    35,
      92,   102,   103,   104,    40,   106,   107,    27,    88,    89,
      90,    91,   102,     3,    95,   105,    35,    32,   105,   411,
     412,    40,   101,    84,    85,    15,    16,    27,   117,   117,
      11,   112,    99,   100,     6,    28,   116,    27,   119,   431,
     432,    28,    32,    31,    15,   126,     5,    37,    38,   433,
     434,   435,     8,   437,    17,    15,    31,    39,    32,     3,
     141,   142,   143,   144,    34,    33,    23,    15,   452,   118,
     454,    25,   456,    25,    12,    40,   118,   461,    13,    15,
      12,    34,   163,   108,   109,   110,   111,   112,   113,   114,
     171,    15,    22,    42,    40,    15,    35,   102,    15,    14,
      25,    41,    25,   184,    14,    34,    86,   188,    27,    11,
      31,   192,    54,    31,    40,    31,   197,   198,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      31,    31,    54,    63,   215,    31,    31,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    31,    31,    87,    15,    86,    34,
      34,    34,    25,   244,    94,    95,    96,    31,    34,    15,
      32,    32,    86,    32,   115,    32,    32,    32,    15,    33,
      15,    15,    25,    25,    15,    35,    35,    40,    86,    86,
      15,    15,    86,    15,    35,    16,    32,   278,   279,    92,
     105,   282,   283,    35,   325,    35,    54,    34,   100,   357,
     283,   206,   163,   126,   282,   217,   426,   151,   425,   146,
     241,   340,   338,    -1,    -1,    -1,    -1,   304,    -1,    -1,
      -1,    -1,    -1,    -1,   315,   316,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    -1,    18,    19,    -1,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,   392,   393,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     3,     4,    -1,    -1,     7,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    19,
      -1,    21,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,     7,
       8,     9,    10,    11,    -1,    13,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    -1,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    -1,    -1,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      -1,    98,    99,   100,    -1,   102,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     7,     8,     9,    10,    11,    -1,    13,    -1,    -1,
      16,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    -1,    98,    99,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    -1,    98,    99,   100,    -1,   102,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    -1,    98,    99,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    -1,    98,    99,   100,    -1,   102,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    -1,    98,    99,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    -1,    98,    99,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     7,   120,   121,     7,     8,     9,    10,    11,    16,
      19,    20,    21,    22,    26,    27,    28,    29,    39,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    96,    98,    99,   100,   102,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   122,   123,   206,     0,
       9,    10,   124,   125,    26,    24,    26,    32,   126,    29,
     125,   142,    27,   122,    27,   127,    11,   128,   132,   122,
     143,   144,     6,   147,    28,    28,   128,    15,   129,    31,
     145,    13,    40,   133,   144,   122,   148,   149,   181,     5,
     165,     8,    17,   122,   146,   144,   133,   149,   150,   166,
      15,   130,    23,    24,    25,    31,   151,   152,    10,    43,
     117,   167,   168,   169,     3,     4,    12,    30,    32,    93,
      97,   118,   122,   134,   135,   136,   137,   138,   122,   122,
     122,   153,    33,   152,    39,    32,    34,   133,   168,    33,
     139,    18,   136,     3,    23,    20,   122,   158,   170,    15,
     118,   140,   179,   180,   182,   131,   122,    25,    25,    12,
     155,   122,   173,    40,    14,    30,   122,   118,   133,   122,
     178,   122,    15,   154,    12,    34,    15,   141,   179,    42,
     156,   157,    14,    40,    40,   159,    15,    20,   122,   174,
     176,   177,    35,   182,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    88,    89,    90,    91,   116,
     183,   102,    15,    22,    63,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    94,    95,    96,   160,   161,    14,    25,    25,
      35,    40,   175,    41,    86,    34,   187,   187,   108,   109,
     110,   111,   112,   113,   114,   194,   195,   197,   108,   109,
     110,   111,   112,   113,   114,   188,   191,   192,   122,    27,
      14,    11,    31,    31,    31,    54,    54,    31,    31,    31,
      31,    84,    85,    31,    31,    40,    36,   122,    36,   122,
      87,   171,   177,   176,    34,    15,    34,   198,    86,   198,
      86,    34,   189,    25,    31,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,   163,   164,    32,
      15,    32,    92,   162,   122,   122,    32,    34,    32,    32,
      32,    32,   161,   115,    33,   172,    15,    35,    40,    15,
     190,   196,   197,   192,   193,    15,   122,    15,   101,   164,
     199,   200,    25,    25,     3,    15,    16,    27,    32,    37,
      38,   184,   185,   186,    40,    15,    35,    35,    15,    16,
      32,    34,   102,   105,   201,   202,   203,   204,   122,   122,
      86,    86,    15,    15,    35,    40,    86,    15,    35,   202,
     202,    99,   100,    31,    54,    98,   102,   103,   104,   106,
     107,    16,    32,   186,   185,    35,    35,   202,   202,   203,
     203,   203,    54,   203,    34,   203,   100,   203,   205,   203,
      35,    40,   203
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
        case 2:
#line 99 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 102 "screen.yacc"
    {the_form.dbname=strdup("formonly");}
    break;

  case 4:
#line 103 "screen.yacc"
    {the_form.dbname=(yyvsp[-3].str);
if (A4GLF_open_db(yyvsp[-3].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 108 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 109 "screen.yacc"
    {the_form.dbname=strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 10:
#line 122 "screen.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 13:
#line 128 "screen.yacc"
    {
	char buff[256];
	sprintf(buff,"Screen %d", the_form.snames.snames_len);
		the_form.snames.snames_len++;the_form.snames.snames_val=
			realloc(the_form.snames.snames_val,
				(the_form.snames.snames_len)*
					sizeof(struct screen_name));

		the_form.snames.snames_val[the_form.snames.snames_len-1].name=
				strdup(buff);

		in_screen_section=1; 
	}
    break;

  case 15:
#line 141 "screen.yacc"
    {
	char buff[256];
	char *ptr;
	the_form.snames.snames_len++;the_form.snames.snames_val=
		realloc(the_form.snames.snames_val, 
			(the_form.snames.snames_len)*
				sizeof(struct screen_name));
		sprintf(buff,"%s", yyvsp[0].str);
		ptr=buff;
		ptr++;
		ptr[strlen(ptr)-1]=0;

		the_form.snames.snames_val[
			the_form.snames.snames_len-1].name =strdup(ptr);

	in_screen_section=1; 
	}
    break;

  case 17:
#line 161 "screen.yacc"
    { 
		lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 18:
#line 163 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 19:
#line 166 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 175 "screen.yacc"
    {
	int c;
	int l;
	if (A4GL_isyes(acl_getenv("USE_FORM_SIZE"))) {
		c=atoi(yyvsp[0].str);
		l=atoi(yyvsp[-2].str);
        	if (c>the_form.maxcol) the_form.maxcol=c;
        	if (l>the_form.maxline) the_form.maxline=l;
	}
}
    break;

  case 28:
#line 197 "screen.yacc"
    {
	int a;
	static char buff[256];
	strcpy(buff,yyvsp[0].str);

	for (a=0;a<strlen(buff);a++) {
		if (buff[a]=='_') buff[a]=' ';
	}
	strcpy(yyval.str,buff);
}
    break;

  case 29:
#line 211 "screen.yacc"
    {
        A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 31:
#line 219 "screen.yacc"
    {
	char buff[256];
	sprintf(buff,"\n%s",yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 32:
#line 228 "screen.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 33:
#line 238 "screen.yacc"
    {
	     A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 34:
#line 245 "screen.yacc"
    {
	//char buff[256];
	A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	//printf("colno was %d for '%s'\n",colno,$<str>1);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 35:
#line 253 "screen.yacc"
    {colno++;}
    break;

  case 36:
#line 254 "screen.yacc"
    {colno=0;lineno++;}
    break;

  case 38:
#line 261 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 39:
#line 262 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 40:
#line 268 "screen.yacc"
    {
	fstart=colno;
	openwith='[';
}
    break;

  case 41:
#line 274 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 42:
#line 285 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 43:
#line 290 "screen.yacc"
    {
	/* 
field elements = name x y width screen_no endswith'|' 
*/
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,1,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,0,"");
	fstart=colno;
	openwith='|';
}
    break;

  case 44:
#line 304 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 50:
#line 319 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 51:
#line 326 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 52:
#line 327 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 53:
#line 330 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 54:
#line 331 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 55:
#line 333 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 56:
#line 334 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 57:
#line 335 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 61:
#line 349 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 65:
#line 361 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 66:
#line 365 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 67:
#line 375 "screen.yacc"
    {
	if (fld->datatype==90&&!(A4GL_has_str_attribute(fld,FA_S_DEFAULT)))
	{
	        extern FILE *yyin;

			A4GL_debug("Currpos = %ld\n",ftell(yyin));
	        yyerror("A button must have a default value for its caption");
	        YYERROR;
	}
	A4GL_set_field(currftag,fld);
}
    break;

  case 69:
#line 390 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 70:
#line 394 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 71:
#line 402 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 72:
#line 403 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 73:
#line 406 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 74:
#line 407 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 75:
#line 410 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 76:
#line 413 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 77:
#line 418 "screen.yacc"
    {
	fld->tabname=strdup("formonly");
	fld->colname=strdup(yyvsp[-1].str);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 78:
#line 427 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 79:
#line 435 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 84:
#line 452 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 85:
#line 453 "screen.yacc"
    {
		if (yyvsp[0].expr==0)  {
			int a;
			struct  u_expression *e_true;
  			e_true=create_int_expr(1);
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi(yyvsp[-1].str);
			fld->colours.colours_val[a-1].whereexpr=e_true;
		} else  {
			int a;
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi(yyvsp[-1].str);
			fld->colours.colours_val[a-1].whereexpr=yyvsp[0].expr;

		}
}
    break;

  case 86:
#line 473 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 87:
#line 474 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 88:
#line 475 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 89:
#line 476 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 90:
#line 477 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 91:
#line 478 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 92:
#line 479 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 93:
#line 480 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 94:
#line 481 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 95:
#line 482 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 96:
#line 483 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 97:
#line 484 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 98:
#line 485 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 99:
#line 486 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 100:
#line 488 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 101:
#line 489 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 102:
#line 490 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 103:
#line 491 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 104:
#line 492 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 105:
#line 493 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 106:
#line 496 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 107:
#line 499 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_VERIFY);
}
    break;

  case 108:
#line 502 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 109:
#line 505 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 110:
#line 509 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 113:
#line 517 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 115:
#line 519 "screen.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str));
}
    break;

  case 116:
#line 525 "screen.yacc"
    {
	strcpy(yyval.str,"0");
}
    break;

  case 117:
#line 528 "screen.yacc"
    {
	strcpy(yyval.str,"4");
}
    break;

  case 118:
#line 531 "screen.yacc"
    {
	strcpy(yyval.str,"2");
}
    break;

  case 119:
#line 534 "screen.yacc"
    {
	strcpy(yyval.str,"6"); 
}
    break;

  case 120:
#line 537 "screen.yacc"
    {
	strcpy(yyval.str,"1");
}
    break;

  case 121:
#line 540 "screen.yacc"
    {
	strcpy(yyval.str,"5"); 
}
    break;

  case 122:
#line 543 "screen.yacc"
    {
	strcpy(yyval.str,"7");
}
    break;

  case 123:
#line 546 "screen.yacc"
    {
	strcpy(yyval.str,"3");
}
    break;

  case 124:
#line 549 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE"));
}
    break;

  case 125:
#line 552 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT"));
}
    break;

  case 126:
#line 555 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK"));
}
    break;

  case 127:
#line 558 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE"));
}
    break;

  case 129:
#line 563 "screen.yacc"
    {
}
    break;

  case 135:
#line 573 "screen.yacc"
    {
	char buff[4];
	strcpy(buff,A4GL_char_val(yyvsp[0].str));
	if (strlen(buff)==1) {
		buff[1]=buff[0];
		buff[2]=buff[0];
		buff[3]=0;
	}
	the_form.delim=strdup(buff);
}
    break;

  case 136:
#line 583 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 143:
#line 594 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 144:
#line 597 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 145:
#line 613 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 146:
#line 616 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 149:
#line 626 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 150:
#line 628 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 151:
#line 630 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 152:
#line 632 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 153:
#line 634 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 155:
#line 638 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 156:
#line 642 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 159:
#line 651 "screen.yacc"
    {colno++;}
    break;

  case 160:
#line 651 "screen.yacc"
    {colno++;}
    break;

  case 161:
#line 657 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 162:
#line 665 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-1].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[-1].str);
	}
    break;

  case 163:
#line 673 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 164:
#line 677 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 165:
#line 681 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 166:
#line 685 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 167:
#line 689 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 168:
#line 693 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 169:
#line 697 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 170:
#line 701 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 171:
#line 705 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 172:
#line 709 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 173:
#line 713 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 174:
#line 717 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 175:
#line 721 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 176:
#line 725 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 177:
#line 728 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 179:
#line 735 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 182:
#line 740 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 183:
#line 745 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 184:
#line 746 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 185:
#line 747 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 186:
#line 748 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 188:
#line 750 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 189:
#line 753 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 190:
#line 757 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 191:
#line 763 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 192:
#line 764 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 193:
#line 765 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 194:
#line 768 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 195:
#line 770 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 196:
#line 776 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 197:
#line 778 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 198:
#line 783 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 199:
#line 791 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 200:
#line 794 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 201:
#line 795 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 202:
#line 796 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 203:
#line 797 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 204:
#line 798 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 205:
#line 799 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 206:
#line 801 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 208:
#line 808 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 209:
#line 809 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 210:
#line 812 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 211:
#line 815 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 212:
#line 819 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 213:
#line 820 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 214:
#line 821 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 215:
#line 822 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 216:
#line 823 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 217:
#line 824 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 218:
#line 826 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 219:
#line 831 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 220:
#line 833 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 221:
#line 840 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 222:
#line 840 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 223:
#line 846 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 225:
#line 853 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 226:
#line 856 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 227:
#line 862 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 228:
#line 865 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 229:
#line 868 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE");
		}
    break;

  case 230:
#line 871 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
	}
    break;

  case 231:
#line 874 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL");
	}
    break;

  case 232:
#line 879 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNOTNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL");
	}
    break;

  case 233:
#line 884 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
			//create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
    break;

  case 234:
#line 888 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[-2].expr);
		add_list_expr(yyval.expr,yyvsp[0].expr);
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN");
	}
    break;

  case 235:
#line 894 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN");
	}
    break;

  case 236:
#line 897 "screen.yacc"
    {
		yyval.expr=create_not_expr(yyvsp[0].expr);
	}
    break;

  case 237:
#line 900 "screen.yacc"
    {
		yyval.expr=yyvsp[-1].expr;
	}
    break;

  case 238:
#line 905 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 239:
#line 912 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str));
printf("NUMBER VALUE : %s\n",yyvsp[0].str);
}
    break;

  case 240:
#line 915 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 241:
#line 916 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 243:
#line 924 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 244:
#line 928 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3292 "y.tab.c"

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


#line 98 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




