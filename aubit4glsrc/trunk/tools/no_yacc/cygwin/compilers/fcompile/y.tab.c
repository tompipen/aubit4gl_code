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
     SQLONLY = 348,
     WIDGET = 349,
     CONFIG = 350,
     KW_NL = 351,
     COMPARISON = 352,
     KWOR = 353,
     KWAND = 354,
     KWWHERE = 355,
     KWNOT = 356,
     KWBETWEEN = 357,
     KWIN = 358,
     XVAL = 359,
     KWNULLCHK = 360,
     KWNOTNULLCHK = 361,
     YEAR = 362,
     MONTH = 363,
     DAY = 364,
     HOUR = 365,
     MINUTE = 366,
     SECOND = 367,
     FRACTION = 368,
     LISTBOX = 369,
     BUTTON = 370,
     KW_PANEL = 371,
     KW_WS = 372
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
#define SQLONLY 348
#define WIDGET 349
#define CONFIG 350
#define KW_NL 351
#define COMPARISON 352
#define KWOR 353
#define KWAND 354
#define KWWHERE 355
#define KWNOT 356
#define KWBETWEEN 357
#define KWIN 358
#define XVAL 359
#define KWNULLCHK 360
#define KWNOTNULLCHK 361
#define YEAR 362
#define MONTH 363
#define DAY 364
#define HOUR 365
#define MINUTE 366
#define SECOND 367
#define FRACTION 368
#define LISTBOX 369
#define BUTTON 370
#define KW_PANEL 371
#define KW_WS 372




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
#line 390 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 402 "y.tab.c"

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
#define YYLAST   1355

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  88
/* YYNRULES -- Number of rules. */
#define YYNRULES  323
/* YYNRULES -- Number of states. */
#define YYNSTATES  462

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   372

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
     115,   116,   117
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    37,    39,    42,    43,    47,    48,    53,    54,    55,
      56,    65,    66,    69,    74,    75,    77,    79,    82,    84,
      86,    88,    90,    92,    94,    96,    98,   100,   102,   105,
     106,   111,   113,   114,   119,   120,   124,   126,   129,   133,
     136,   137,   140,   142,   146,   150,   156,   160,   164,   166,
     169,   170,   175,   177,   180,   181,   182,   189,   190,   194,
     200,   204,   206,   207,   213,   217,   220,   225,   229,   231,
     232,   235,   237,   241,   243,   248,   252,   256,   260,   266,
     270,   276,   278,   280,   284,   290,   294,   298,   300,   305,
     307,   309,   311,   315,   319,   321,   323,   325,   327,   330,
     333,   335,   337,   339,   341,   344,   346,   348,   350,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   369,   370,
     375,   377,   380,   382,   385,   388,   389,   399,   412,   413,
     416,   417,   419,   421,   426,   428,   432,   433,   435,   437,
     441,   445,   449,   453,   455,   459,   461,   462,   464,   466,
     469,   471,   475,   477,   479,   481,   483,   485,   487,   490,
     493,   496,   499,   501,   503,   505,   507,   509,   511,   515,
     517,   520,   523,   525,   527,   531,   533,   535,   539,   543,
     545,   546,   550,   556,   557,   561,   562,   566,   568,   571,
     573,   575,   577,   579,   581,   583,   586,   588,   589,   593,
     595,   597,   599,   601,   603,   605,   607,   609,   612,   613,
     617,   618,   620,   623,   625,   629,   633,   637,   641,   646,
     650,   653,   656,   658,   664,   670,   673,   677,   679,   681,
     683,   685,   687,   689,   693,   695,   697,   699,   701,   703,
     705,   707,   709,   711,   713,   715,   717,   719,   721,   723,
     725,   727,   729,   731,   733,   735,   737,   739,   741,   743,
     745,   747,   749,   751,   753,   755,   757,   759,   761,   763,
     765,   767,   769,   771,   773,   775,   777,   779,   781,   783,
     785,   787,   789,   791,   793,   795,   797,   799,   801,   803,
     805,   807,   809,   811,   813,   815,   817,   819,   821,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   851
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     119,     0,    -1,   120,   123,   141,   146,   164,    -1,     7,
      20,    -1,     7,   122,    26,    27,    28,    -1,     7,    20,
      26,    27,    28,    -1,     7,   122,    -1,    16,    -1,   205,
      -1,   121,    -1,   121,    24,   121,    -1,   124,    -1,   123,
     124,    -1,    -1,    10,   125,   127,    -1,    -1,     9,    32,
     126,   127,    -1,    -1,    -1,    -1,   131,   128,    17,   129,
     133,    18,   130,   132,    -1,    -1,    11,    15,    -1,    11,
      15,     8,    15,    -1,    -1,    13,    -1,   135,    -1,   133,
     135,    -1,   121,    -1,   134,    -1,   137,    -1,     4,    -1,
      30,    -1,    32,    -1,   136,    -1,   117,    -1,    96,    -1,
       3,    -1,   136,     3,    -1,    -1,    12,   138,   139,    14,
      -1,   181,    -1,    -1,   139,    30,   140,   181,    -1,    -1,
      29,   142,   132,    -1,   143,    -1,   142,   143,    -1,   142,
      40,   143,    -1,   121,   144,    -1,    -1,    31,   145,    -1,
     121,    -1,   121,    23,   121,    -1,   121,    24,   121,    -1,
     121,    24,   121,    23,   121,    -1,   121,    25,   121,    -1,
       6,   147,   132,    -1,   148,    -1,   147,   148,    -1,    -1,
     180,   149,   150,    33,    -1,   151,    -1,   150,   151,    -1,
      -1,    -1,    31,   152,   157,   154,   153,   158,    -1,    -1,
      12,    15,    14,    -1,    12,    15,    40,    15,    14,    -1,
     156,   101,    27,    -1,   156,    -1,    -1,    42,    54,   121,
      25,   121,    -1,    42,    54,   121,    -1,    42,   182,    -1,
      20,    25,   177,   155,    -1,   121,    25,   121,    -1,   121,
      -1,    -1,    40,   159,    -1,   160,    -1,   159,    40,   160,
      -1,    67,    -1,    68,    31,   162,   198,    -1,    69,    31,
      32,    -1,    70,    31,   161,    -1,    72,    54,   121,    -1,
      72,    54,   121,    25,   121,    -1,    71,    54,   121,    -1,
      71,    54,   121,    25,   121,    -1,    73,    -1,    74,    -1,
      75,    31,    32,    -1,    76,    31,    34,   183,    35,    -1,
      94,    31,    32,    -1,    95,    31,    32,    -1,    77,    -1,
      22,    11,    31,    15,    -1,    22,    -1,    93,    -1,    78,
      -1,    79,    31,    32,    -1,    80,    31,    32,    -1,    81,
      -1,    63,    -1,    82,    -1,    83,    -1,    83,    84,    -1,
      83,    85,    -1,    32,    -1,    15,    -1,    92,    -1,   163,
      -1,   162,   163,    -1,    55,    -1,    56,    -1,    57,    -1,
      58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    -1,    -1,
       5,   165,   166,   132,    -1,   167,    -1,   166,   167,    -1,
     168,    -1,   168,    33,    -1,    43,    32,    -1,    -1,    10,
      39,   169,   172,    34,   173,    35,   170,   171,    -1,   116,
      34,    15,    40,    15,    35,    86,    34,    15,    40,    15,
      35,    -1,    -1,    87,   114,    -1,    -1,    33,    -1,   121,
      -1,   121,    12,    15,    14,    -1,   176,    -1,   173,   174,
     176,    -1,    -1,    40,    -1,   121,    -1,   121,    25,   121,
      -1,    20,    25,   121,    -1,   121,    25,    36,    -1,    20,
      25,    36,    -1,   175,    -1,   175,    41,   175,    -1,   121,
      -1,    -1,   179,    -1,   117,    -1,   179,   117,    -1,   121,
      -1,   178,   121,   178,    -1,    44,    -1,    45,    -1,    46,
      -1,    47,    -1,    48,    -1,    49,    -1,    50,   186,    -1,
      51,   186,    -1,    52,   193,    -1,    53,   187,    -1,    88,
      -1,    89,    -1,    90,    -1,    91,    -1,   115,    -1,   185,
      -1,   183,    40,   185,    -1,    15,    -1,    37,    15,    -1,
      38,    15,    -1,    32,    -1,    16,    -1,    16,    86,    16,
      -1,     3,    -1,   184,    -1,   184,    86,   184,    -1,    32,
      86,    32,    -1,    27,    -1,    -1,    34,    15,    35,    -1,
      34,    15,    40,    15,    35,    -1,    -1,   190,    86,   192,
      -1,    -1,    34,    15,    35,    -1,    15,    -1,   191,   188,
      -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,   111,
      -1,   112,    -1,   113,   197,    -1,   191,    -1,    -1,   194,
      86,   195,    -1,   196,    -1,   196,    -1,   107,    -1,   108,
      -1,   109,    -1,   110,    -1,   111,    -1,   112,    -1,   113,
     197,    -1,    -1,    34,   189,    35,    -1,    -1,   199,    -1,
     100,   200,    -1,   201,    -1,   201,    99,   201,    -1,   201,
      98,   201,    -1,   202,    97,   202,    -1,   202,    54,   202,
      -1,   202,   101,    54,   202,    -1,   202,    31,   202,    -1,
     202,   105,    -1,   202,   106,    -1,   202,    -1,   202,   102,
     202,    99,   202,    -1,   202,   103,    34,   204,    35,    -1,
     101,   201,    -1,    34,   201,    35,    -1,   203,    -1,    15,
      -1,    32,    -1,   104,    -1,    16,    -1,   202,    -1,   204,
      40,   202,    -1,    87,    -1,    67,    -1,    55,    -1,    65,
      -1,    56,    -1,    98,    -1,    99,    -1,    97,    -1,   115,
      -1,     8,    -1,    68,    -1,    21,    -1,    69,    -1,    84,
      -1,    95,    -1,    58,    -1,     7,    -1,    52,    -1,    70,
      -1,    43,    -1,    73,    -1,    22,    -1,    75,    -1,    57,
      -1,    76,    -1,    28,    -1,    53,    -1,    77,    -1,    89,
      -1,    44,    -1,    46,    -1,    50,    -1,    47,    -1,    45,
      -1,    27,    -1,   116,    -1,    10,    -1,     9,    -1,    11,
      -1,    90,    -1,    64,    -1,   114,    -1,    60,    -1,    51,
      -1,    78,    -1,    85,    -1,   101,    -1,    79,    -1,    80,
      -1,    39,    -1,    59,    -1,    81,    -1,    63,    -1,    88,
      -1,    48,    -1,    49,    -1,    93,    -1,    92,    -1,    29,
      -1,    41,    -1,    19,    -1,    86,    -1,    66,    -1,    74,
      -1,    91,    -1,    82,    -1,    61,    -1,    94,    -1,    26,
      -1,    83,    -1,    62,    -1,    42,    -1,    54,    -1,   107,
      -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,
      -1,   113,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    99,    99,   102,   103,   108,   109,   117,   118,   122,
     122,   125,   125,   128,   128,   141,   141,   161,   163,   166,
     160,   173,   174,   175,   187,   188,   193,   194,   197,   211,
     217,   219,   227,   237,   244,   252,   253,   259,   260,   266,
     265,   283,   288,   287,   308,   309,   312,   313,   314,   317,
     324,   325,   328,   329,   330,   332,   333,   339,   343,   343,
     347,   347,   356,   356,   359,   363,   359,   387,   388,   392,
     400,   401,   404,   405,   408,   411,   416,   425,   433,   442,
     443,   447,   447,   450,   451,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   486,
     487,   488,   489,   490,   491,   494,   497,   500,   503,   507,
     513,   514,   515,   517,   517,   523,   526,   529,   532,   535,
     538,   541,   544,   547,   550,   553,   556,   560,   561,   561,
     566,   566,   568,   568,   571,   581,   581,   584,   587,   587,
     589,   589,   592,   595,   611,   614,   618,   619,   623,   625,
     627,   629,   631,   636,   636,   640,   646,   646,   649,   649,
     655,   663,   671,   675,   679,   683,   687,   691,   695,   699,
     703,   707,   711,   715,   719,   723,   726,   733,   733,   738,
     738,   738,   743,   744,   745,   746,   747,   748,   751,   755,
     761,   762,   763,   766,   767,   774,   776,   781,   789,   792,
     793,   794,   795,   796,   797,   798,   804,   806,   807,   810,
     813,   817,   818,   819,   820,   821,   822,   823,   829,   831,
     838,   838,   844,   850,   851,   854,   860,   863,   866,   869,
     872,   877,   882,   886,   892,   895,   898,   903,   910,   913,
     914,   919,   922,   926,   934,   935,   936,   937,   938,   939,
     940,   941,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   991,   992,   993,   994,   995,   996,   997,   998,   999,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,
    1010,  1011,  1012,  1013
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
  "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR", "SQLONLY", 
  "WIDGET", "CONFIG", "KW_NL", "COMPARISON", "KWOR", "KWAND", "KWWHERE", 
  "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", "KWNOTNULLCHK", 
  "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", "FRACTION", 
  "LISTBOX", "BUTTON", "KW_PANEL", "KW_WS", "$accept", "form_def", 
  "database_section", "named_or_kw", "dbname", "screen_section", 
  "screens_section", "@1", "@2", "screens_rest", "@3", "@4", "@5", 
  "op_size", "op_end", "screen_layout", "some_text", "screen_element", 
  "ch_list", "field", "@6", "field_element", "@7", "op_table_section", 
  "table_def_list", "table_def", "opequal", "table_qualifier", 
  "attribute_section", "field_tag_list", "field_tag", "@8", "fpart_list", 
  "fpart", "@9", "@10", "op_att", "field_datatype_null", "field_datatype", 
  "field_type", "op_field_desc", "op_desc_list", "desc", "def_val", 
  "colors", "color", "op_instruction_section", "@11", "instruct_opts", 
  "instruct_op_1", "instruct_op", "@12", "op_ltype", "op_semi", 
  "srec_dim", "srec_field_list", "op_comma", "field_list_item", 
  "field_list_element", "field_name", "op_ws", "ws", "field_tag_name", 
  "field_tag_name_scr", "datatype", "incl_list", "number_value", 
  "incl_entry", "opt_dec_ext", "opt_int_ext", "opt_unit_size", "dtfrac", 
  "int_start", "int_start_unit", "int_end", "opt_dt_ext", "dt_start", 
  "dt_end", "dtime_val", "opt_frac", "op_where", "where_clause", 
  "clauses", "clause", "value", "fieldidentifier", "value_list", 
  "any_kword", 0
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
     365,   366,   367,   368,   369,   370,   371,   372
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   118,   119,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   123,   125,   124,   126,   124,   128,   129,   130,
     127,   131,   131,   131,   132,   132,   133,   133,   134,   135,
     135,   135,   135,   135,   135,   135,   135,   136,   136,   138,
     137,   139,   140,   139,   141,   141,   142,   142,   142,   143,
     144,   144,   145,   145,   145,   145,   145,   146,   147,   147,
     149,   148,   150,   150,   152,   153,   151,   154,   154,   154,
     155,   155,   156,   156,   156,   156,   157,   157,   157,   158,
     158,   159,   159,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     161,   161,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   164,   165,   164,
     166,   166,   167,   167,   168,   169,   168,   168,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   175,   175,
     175,   175,   175,   176,   176,   177,   178,   178,   179,   179,
     180,   181,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   183,   184,
     184,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     186,   186,   186,   187,   187,   188,   188,   189,   190,   191,
     191,   191,   191,   191,   191,   191,   192,   193,   193,   194,
     195,   196,   196,   196,   196,   196,   196,   196,   197,   197,
     198,   198,   199,   200,   200,   200,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   202,   202,   202,
     202,   203,   204,   204,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     2,     0,     3,     0,     4,     0,     0,     0,
       8,     0,     2,     4,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       4,     1,     0,     4,     0,     3,     1,     2,     3,     2,
       0,     2,     1,     3,     3,     5,     3,     3,     1,     2,
       0,     4,     1,     2,     0,     0,     6,     0,     3,     5,
       3,     1,     0,     5,     3,     2,     4,     3,     1,     0,
       2,     1,     3,     1,     4,     3,     3,     3,     5,     3,
       5,     1,     1,     3,     5,     3,     3,     1,     4,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     4,
       1,     2,     1,     2,     2,     0,     9,    12,     0,     2,
       0,     1,     1,     4,     1,     3,     0,     1,     1,     3,
       3,     3,     3,     1,     3,     1,     0,     1,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     2,     1,     1,     3,     1,     1,     3,     3,     1,
       0,     3,     5,     0,     3,     0,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     3,
       0,     1,     2,     1,     3,     3,     3,     3,     4,     3,
       2,     2,     1,     5,     5,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   260,   253,   281,   280,   282,     7,
     304,     3,   255,   265,   312,   278,   269,   302,   293,   303,
     315,   263,   273,   277,   274,   276,   298,   299,   275,   287,
     261,   270,   316,   246,   248,   267,   259,   294,   286,   310,
     314,   296,   284,   247,   306,   245,   254,   256,   262,   264,
     307,   266,   268,   271,   288,   291,   292,   295,   309,   313,
     257,   289,   305,   244,   297,   272,   283,   308,   301,   300,
     311,   258,   251,   249,   250,   290,   317,   318,   319,   320,
     321,   322,   323,   285,   252,   279,     9,     6,     8,     1,
       0,    13,    44,    11,     0,     0,     0,    15,    21,     0,
      12,     0,     0,    10,     0,    21,     0,    14,    17,    50,
      24,    46,     0,   127,     5,     4,    16,    22,     0,     0,
      49,    25,     0,    45,    47,   160,    24,    58,    60,   128,
       2,     0,    18,    52,    51,    48,    57,    59,     0,     0,
      23,     0,     0,     0,     0,    64,     0,    62,     0,     0,
       0,    24,   130,   132,    37,    31,    39,    32,    33,    36,
      35,    28,     0,    29,    26,    34,    30,    53,    54,    56,
       0,    61,    63,   135,   134,     0,   129,   131,   133,   156,
      19,    27,    38,     0,     0,    78,    67,     0,     0,   158,
       0,     0,   157,    41,    24,    55,     0,     0,     0,    65,
     142,     0,     0,    40,    42,   156,   159,    20,   155,    72,
      77,     0,    79,     0,     0,     0,   156,   161,     0,    76,
      71,    68,     0,     0,    66,     0,     0,   148,   146,   153,
     144,     0,    43,   162,   163,   164,   165,   166,   167,   190,
     190,   207,   193,     0,   172,   173,   174,   175,   176,    75,
       0,     0,    99,   105,    83,     0,     0,     0,     0,     0,
      91,    92,     0,     0,    97,   101,     0,     0,   104,   106,
     107,   100,     0,     0,    80,    81,   143,     0,     0,   138,
     147,     0,     0,     0,     0,   168,   169,   211,   212,   213,
     214,   215,   216,   218,   170,     0,   209,   199,   200,   201,
     202,   203,   204,   218,   171,     0,   195,    74,    70,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,     0,     0,     0,   152,   150,   151,   149,     0,
     140,   145,   154,     0,     0,     0,   217,     0,   205,     0,
       0,   198,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   220,   113,    85,   111,
     110,   112,    86,    89,    87,    93,     0,   102,   103,    95,
      96,    82,   139,   141,   136,     0,   191,     0,   197,     0,
     208,   210,   206,   194,     0,    73,    98,     0,   114,    84,
     221,     0,     0,   185,   179,   183,   189,   182,     0,     0,
       0,   186,   177,     0,     0,   219,   196,   238,   241,   239,
       0,     0,   240,   222,   223,   232,   237,    90,    88,     0,
       0,   180,   181,    94,     0,     0,     0,   192,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     184,   188,   178,   187,   137,   236,   225,   224,   229,   227,
     226,     0,     0,     0,   228,     0,   242,     0,   233,   234,
       0,   243
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   109,    87,    92,    93,    98,   105,   107,
     118,   141,   194,   108,   123,   162,   163,   164,   165,   166,
     179,   190,   216,   101,   110,   111,   120,   134,   113,   126,
     127,   138,   146,   147,   170,   212,   199,   219,   220,   186,
     224,   274,   275,   362,   356,   357,   130,   139,   151,   152,
     153,   187,   330,   374,   201,   228,   281,   229,   230,   209,
     191,   192,   128,   193,   249,   400,   401,   402,   285,   304,
     341,   379,   305,   306,   383,   294,   295,   380,   296,   336,
     389,   390,   413,   414,   415,   416,   457,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -254
static const short yypact[] =
{
       1,   579,    17,   150,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,    40,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,     3,    64,  -254,  -254,
      85,  -254,   110,  -254,    94,  1239,   105,  -254,   117,  1239,
    -254,   131,   137,  -254,   144,   117,   159,  -254,  -254,   145,
      -6,  -254,  1239,   170,  -254,  -254,  -254,   172,   164,  1239,
    -254,  -254,  1239,  -254,  -254,  -254,   689,  -254,  -254,  -254,
    -254,   176,  -254,   139,  -254,  -254,  -254,  -254,   161,    22,
    -254,   468,  1239,  1239,  1239,  -254,    93,  -254,   155,   165,
     166,    86,  -254,   168,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,   353,  -254,  -254,   195,  -254,  -254,   181,  -254,
     799,  -254,  -254,  -254,  -254,   184,  -254,  -254,  -254,    95,
    -254,  -254,  -254,  1239,   190,   191,   205,  1239,   196,  -254,
      -5,  1239,   118,  -254,   224,  -254,  1239,  1239,   223,  -254,
     247,   229,   249,  -254,  -254,    95,  -254,  -254,  -254,   226,
    -254,   116,   225,   251,   909,   234,    95,  -254,   203,  -254,
     169,  -254,   256,   151,  -254,   261,   253,   254,   -21,   231,
    -254,   197,  -254,  -254,  -254,  -254,  -254,  -254,  -254,   248,
     248,    98,   212,  1239,  -254,  -254,  -254,  -254,  -254,  -254,
     257,   272,   276,  -254,  -254,   278,   279,   280,   235,   262,
    -254,  -254,   281,   284,  -254,  -254,   286,   295,  -254,  -254,
      83,  -254,   296,   297,   289,  -254,  -254,  1019,  1129,   201,
    -254,   909,   909,   298,   315,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,   299,  -254,   245,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,   299,  -254,   250,   300,   310,  -254,  -254,
     306,   242,   307,   101,  1239,  1239,   308,   304,   311,   312,
    -254,  -254,   313,   314,   151,  -254,  -254,  -254,  -254,   228,
     316,  -254,  -254,   332,   -11,   333,  -254,    98,  -254,   212,
     335,  -254,  1239,   336,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,    89,  -254,  -254,  -254,
    -254,  -254,  -254,   327,   328,  -254,   258,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,   318,  -254,   339,  -254,   320,
    -254,  -254,  -254,  -254,   324,  -254,  -254,    -4,  -254,  -254,
    -254,  1239,  1239,  -254,  -254,   282,  -254,   287,   351,   352,
      -9,   290,  -254,   355,   342,  -254,  -254,  -254,  -254,  -254,
      -4,    -4,  -254,  -254,    72,    82,  -254,  -254,  -254,   362,
     354,  -254,  -254,  -254,   258,    97,   349,  -254,   358,  -254,
      -4,    -4,    99,    99,    99,   334,    99,   390,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,    99,   288,    99,  -254,    99,  -254,    87,  -254,  -254,
      99,  -254
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -254,  -254,  -254,    -1,  -254,  -254,   361,  -254,  -254,   350,
    -254,  -254,  -254,  -254,   -28,  -254,  -254,   227,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -104,  -254,  -254,  -254,  -254,
     330,  -254,  -254,   337,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,   133,  -254,  -254,    69,  -254,  -254,  -254,   322,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,   177,   193,  -254,
     277,  -254,  -254,   265,  -254,  -254,    33,    61,   246,  -254,
    -254,  -254,  -254,   149,  -254,  -254,  -254,  -254,   154,   189,
    -254,  -254,  -254,  -253,  -193,  -254,  -254,  -254
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      86,     4,     5,     6,     7,     8,   124,   121,     1,   203,
       9,   407,   408,    10,   279,    12,    13,    89,   135,   280,
      14,    15,    16,    17,   376,   204,   423,    95,   409,   377,
     410,   424,   148,    18,   122,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   149,    94,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      96,    72,    73,    74,   103,    75,   148,   411,   136,   121,
     412,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   125,   394,   432,   407,   408,   359,    97,   133,    90,
      91,   102,   459,   176,   145,   125,   171,   460,   106,   149,
     221,   409,   104,   360,   398,   399,   433,   112,   150,    99,
     161,   167,   168,   169,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   222,   428,   429,    90,
      91,   161,   142,   143,   144,   114,   207,   320,   321,   185,
     430,   431,   115,   252,   117,   129,   119,   446,   447,   434,
     131,   132,   195,   435,   436,   437,   200,   438,   439,   387,
     205,   140,   145,   361,   173,   208,   210,   174,   182,   188,
     175,   178,   150,   412,   183,   287,   288,   289,   290,   291,
     292,   293,   189,   227,   253,   196,   197,   198,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   206,   202,   121,   211,   448,
     449,   450,   307,   452,   271,   272,   273,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   454,   213,
     456,   393,   458,   214,   215,   223,   225,   461,   218,   231,
     250,   251,   282,   394,   395,   276,   326,   328,   277,   278,
     227,   227,   284,   283,   308,   396,   309,   310,   329,   314,
     397,   244,   245,   246,   247,   398,   399,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   311,
     312,   313,   316,   363,   364,   317,   315,   318,   248,   297,
     298,   299,   300,   301,   302,   303,   319,   322,   323,   324,
     334,   337,   333,   335,   340,   342,   339,   343,   366,   358,
     365,   385,   372,   367,   368,   369,   370,   375,   378,   373,
     384,   386,   391,   392,   404,   405,   154,   155,   403,   406,
       4,     5,     6,     7,     8,   156,   421,   422,   419,     9,
     426,   180,    10,   420,    12,    13,   425,   427,   440,    14,
      15,    16,    17,   157,   444,   158,   441,   455,   451,   181,
     417,   418,    18,   445,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   453,   388,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,   159,
      72,    73,    74,   100,    75,   116,   137,   371,   443,   332,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
     160,   154,   155,   177,   331,     4,     5,     6,     7,     8,
     156,   232,   217,   172,     9,   442,   286,    10,   382,    12,
      13,   381,   338,     0,    14,    15,    16,    17,   157,     0,
     158,     0,     0,     0,     0,     0,     0,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   159,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   160,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,    11,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,   121,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,   184,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,   226,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,   325,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,   327,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,     0,
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
      67,    68,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85
};

static const short yycheck[] =
{
       1,     7,     8,     9,    10,    11,   110,    13,     7,    14,
      16,    15,    16,    19,    35,    21,    22,     0,   122,    40,
      26,    27,    28,    29,    35,    30,    35,    24,    32,    40,
      34,    40,    10,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    43,    26,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      26,    97,    98,    99,    95,   101,    10,   101,   126,    13,
     104,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   112,    15,    31,    15,    16,    15,    32,   119,     9,
      10,    27,    35,   151,    31,   126,    33,    40,    11,    43,
      14,    32,    27,    32,    37,    38,    54,     6,   116,    29,
     141,   142,   143,   144,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    40,   410,   411,     9,
      10,   162,    23,    24,    25,    28,   194,    84,    85,   170,
      98,    99,    28,    22,    15,     5,    31,   430,   431,    97,
       8,    17,   183,   101,   102,   103,   187,   105,   106,   100,
     191,    15,    31,    92,    39,   196,   197,    32,     3,    15,
      34,    33,   116,   104,    23,   107,   108,   109,   110,   111,
     112,   113,   117,   214,    63,    25,    25,    12,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   117,    40,    13,    15,   432,
     433,   434,   243,   436,    93,    94,    95,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,   451,    12,
     453,     3,   455,    34,    15,    40,    15,   460,    42,    35,
     101,    15,    41,    15,    16,    14,   277,   278,    25,    25,
     281,   282,    34,    86,    27,    27,    14,    11,    87,    54,
      32,    88,    89,    90,    91,    37,    38,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    31,
      31,    31,    31,   314,   315,    31,    54,    31,   115,   107,
     108,   109,   110,   111,   112,   113,    31,    31,    31,    40,
      15,    86,    34,    34,    34,    25,    86,    31,    34,    32,
      32,   342,   114,    32,    32,    32,    32,    15,    15,    33,
      15,    15,    25,    25,    15,    35,     3,     4,    40,    35,
       7,     8,     9,    10,    11,    12,    15,    15,    86,    16,
      15,    18,    19,    86,    21,    22,    86,    35,    16,    26,
      27,    28,    29,    30,    35,    32,    32,    99,    54,   162,
     391,   392,    39,    35,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    34,   356,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    92,   101,   105,   126,   324,   425,   282,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,     3,     4,   151,   281,     7,     8,     9,    10,    11,
      12,   216,   205,   146,    16,   424,   240,    19,   339,    21,
      22,   337,   303,    -1,    26,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    -1,   101,
      -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     7,     8,     9,    10,
      11,    -1,    13,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     7,   119,   120,     7,     8,     9,    10,    11,    16,
      19,    20,    21,    22,    26,    27,    28,    29,    39,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    97,    98,    99,   101,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   121,   122,   205,     0,
       9,    10,   123,   124,    26,    24,    26,    32,   125,    29,
     124,   141,    27,   121,    27,   126,    11,   127,   131,   121,
     142,   143,     6,   146,    28,    28,   127,    15,   128,    31,
     144,    13,    40,   132,   143,   121,   147,   148,   180,     5,
     164,     8,    17,   121,   145,   143,   132,   148,   149,   165,
      15,   129,    23,    24,    25,    31,   150,   151,    10,    43,
     116,   166,   167,   168,     3,     4,    12,    30,    32,    96,
     117,   121,   133,   134,   135,   136,   137,   121,   121,   121,
     152,    33,   151,    39,    32,    34,   132,   167,    33,   138,
      18,   135,     3,    23,    20,   121,   157,   169,    15,   117,
     139,   178,   179,   181,   130,   121,    25,    25,    12,   154,
     121,   172,    40,    14,    30,   121,   117,   132,   121,   177,
     121,    15,   153,    12,    34,    15,   140,   178,    42,   155,
     156,    14,    40,    40,   158,    15,    20,   121,   173,   175,
     176,    35,   181,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    88,    89,    90,    91,   115,   182,
     101,    15,    22,    63,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    93,    94,    95,   159,   160,    14,    25,    25,    35,
      40,   174,    41,    86,    34,   186,   186,   107,   108,   109,
     110,   111,   112,   113,   193,   194,   196,   107,   108,   109,
     110,   111,   112,   113,   187,   190,   191,   121,    27,    14,
      11,    31,    31,    31,    54,    54,    31,    31,    31,    31,
      84,    85,    31,    31,    40,    36,   121,    36,   121,    87,
     170,   176,   175,    34,    15,    34,   197,    86,   197,    86,
      34,   188,    25,    31,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,   162,   163,    32,    15,
      32,    92,   161,   121,   121,    32,    34,    32,    32,    32,
      32,   160,   114,    33,   171,    15,    35,    40,    15,   189,
     195,   196,   191,   192,    15,   121,    15,   100,   163,   198,
     199,    25,    25,     3,    15,    16,    27,    32,    37,    38,
     183,   184,   185,    40,    15,    35,    35,    15,    16,    32,
      34,   101,   104,   200,   201,   202,   203,   121,   121,    86,
      86,    15,    15,    35,    40,    86,    15,    35,   201,   201,
      98,    99,    31,    54,    97,   101,   102,   103,   105,   106,
      16,    32,   185,   184,    35,    35,   201,   201,   202,   202,
     202,    54,   202,    34,   202,    99,   202,   204,   202,    35,
      40,   202
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
	A4GL_add_field("_label",1+colno-1,lineno,1,scr,0,yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 32:
#line 227 "screen.yacc"
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
#line 237 "screen.yacc"
    {
	     A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 34:
#line 244 "screen.yacc"
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
#line 252 "screen.yacc"
    {colno++;}
    break;

  case 36:
#line 253 "screen.yacc"
    {colno=0;lineno++;}
    break;

  case 37:
#line 259 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 38:
#line 260 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 39:
#line 266 "screen.yacc"
    {
	fstart=colno;
	openwith='[';
}
    break;

  case 40:
#line 272 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 41:
#line 283 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 42:
#line 288 "screen.yacc"
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

  case 43:
#line 302 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 49:
#line 317 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 50:
#line 324 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 51:
#line 325 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 52:
#line 328 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 53:
#line 329 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 54:
#line 331 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 55:
#line 332 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 56:
#line 333 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 60:
#line 347 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 64:
#line 359 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 65:
#line 363 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 66:
#line 373 "screen.yacc"
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

  case 68:
#line 388 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 69:
#line 392 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 70:
#line 400 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 71:
#line 401 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 72:
#line 404 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 73:
#line 405 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 74:
#line 408 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 75:
#line 411 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 76:
#line 416 "screen.yacc"
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

  case 77:
#line 425 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 78:
#line 433 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 83:
#line 450 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 84:
#line 451 "screen.yacc"
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

  case 85:
#line 471 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 86:
#line 472 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 87:
#line 473 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 88:
#line 474 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 89:
#line 475 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 90:
#line 476 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 91:
#line 477 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 92:
#line 478 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 93:
#line 479 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 94:
#line 480 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 95:
#line 481 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 96:
#line 482 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 97:
#line 483 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 98:
#line 484 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 99:
#line 486 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 100:
#line 487 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 101:
#line 488 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 102:
#line 489 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 103:
#line 490 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 104:
#line 491 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 105:
#line 494 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 106:
#line 497 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_VERIFY);
}
    break;

  case 107:
#line 500 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 108:
#line 503 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 109:
#line 507 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 112:
#line 515 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 114:
#line 517 "screen.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str));
}
    break;

  case 115:
#line 523 "screen.yacc"
    {
	strcpy(yyval.str,"0");
}
    break;

  case 116:
#line 526 "screen.yacc"
    {
	strcpy(yyval.str,"4");
}
    break;

  case 117:
#line 529 "screen.yacc"
    {
	strcpy(yyval.str,"2");
}
    break;

  case 118:
#line 532 "screen.yacc"
    {
	strcpy(yyval.str,"6"); 
}
    break;

  case 119:
#line 535 "screen.yacc"
    {
	strcpy(yyval.str,"1");
}
    break;

  case 120:
#line 538 "screen.yacc"
    {
	strcpy(yyval.str,"5"); 
}
    break;

  case 121:
#line 541 "screen.yacc"
    {
	strcpy(yyval.str,"7");
}
    break;

  case 122:
#line 544 "screen.yacc"
    {
	strcpy(yyval.str,"3");
}
    break;

  case 123:
#line 547 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE"));
}
    break;

  case 124:
#line 550 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT"));
}
    break;

  case 125:
#line 553 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK"));
}
    break;

  case 126:
#line 556 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE"));
}
    break;

  case 128:
#line 561 "screen.yacc"
    {
}
    break;

  case 134:
#line 571 "screen.yacc"
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

  case 135:
#line 581 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 142:
#line 592 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 143:
#line 595 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 144:
#line 611 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 145:
#line 614 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 148:
#line 624 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 149:
#line 626 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 150:
#line 628 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 151:
#line 630 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 152:
#line 632 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 154:
#line 636 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 155:
#line 640 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 158:
#line 649 "screen.yacc"
    {colno++;}
    break;

  case 159:
#line 649 "screen.yacc"
    {colno++;}
    break;

  case 160:
#line 655 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 161:
#line 663 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-1].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[-1].str);
	}
    break;

  case 162:
#line 671 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 163:
#line 675 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 164:
#line 679 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 165:
#line 683 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 166:
#line 687 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 167:
#line 691 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 168:
#line 695 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 169:
#line 699 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 170:
#line 703 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 171:
#line 707 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 172:
#line 711 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 173:
#line 715 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 174:
#line 719 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 175:
#line 723 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 176:
#line 726 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 178:
#line 733 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 181:
#line 738 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 182:
#line 743 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 183:
#line 744 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 184:
#line 745 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 185:
#line 746 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 187:
#line 748 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 188:
#line 751 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 189:
#line 755 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 190:
#line 761 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 191:
#line 762 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 192:
#line 763 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 193:
#line 766 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 194:
#line 768 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 195:
#line 774 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 196:
#line 776 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 197:
#line 781 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 198:
#line 789 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 199:
#line 792 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 200:
#line 793 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 201:
#line 794 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 202:
#line 795 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 203:
#line 796 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 204:
#line 797 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 205:
#line 799 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 207:
#line 806 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 208:
#line 807 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 209:
#line 810 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 210:
#line 813 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 211:
#line 817 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 212:
#line 818 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 213:
#line 819 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 214:
#line 820 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 215:
#line 821 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 216:
#line 822 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 217:
#line 824 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 218:
#line 829 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 219:
#line 831 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 220:
#line 838 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 221:
#line 838 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 222:
#line 844 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 224:
#line 851 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 225:
#line 854 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 226:
#line 860 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 227:
#line 863 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 228:
#line 866 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE");
		}
    break;

  case 229:
#line 869 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
	}
    break;

  case 230:
#line 872 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL");
	}
    break;

  case 231:
#line 877 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNOTNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL");
	}
    break;

  case 232:
#line 882 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
			//create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
    break;

  case 233:
#line 886 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[-2].expr);
		add_list_expr(yyval.expr,yyvsp[0].expr);
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN");
	}
    break;

  case 234:
#line 892 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN");
	}
    break;

  case 235:
#line 895 "screen.yacc"
    {
		yyval.expr=create_not_expr(yyvsp[0].expr);
	}
    break;

  case 236:
#line 898 "screen.yacc"
    {
		yyval.expr=yyvsp[-1].expr;
	}
    break;

  case 237:
#line 903 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 238:
#line 910 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str));
printf("NUMBER VALUE : %s\n",yyvsp[0].str);
}
    break;

  case 239:
#line 913 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 240:
#line 914 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 242:
#line 922 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 243:
#line 926 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3265 "y.tab.c"

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


#line 1016 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




