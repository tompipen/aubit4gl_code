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
     INSTRUCTIONS = 259,
     ATTRIBUTES = 260,
     DATABASE = 261,
     BY = 262,
     KW_SCREEN_TITLE = 263,
     KW_SCREEN = 264,
     KW_SIZE = 265,
     OPEN_SQUARE = 266,
     KW_END = 267,
     CLOSE_SQUARE = 268,
     NUMBER_VALUE = 269,
     NAMED = 270,
     OPEN_BRACE = 271,
     CLOSE_BRACE = 272,
     TITLE = 273,
     FORMONLY = 274,
     COMMENT = 275,
     DYNAMIC = 276,
     COLON = 277,
     ATSIGN = 278,
     DOT = 279,
     WITHOUT = 280,
     KW_NULL = 281,
     INPUT = 282,
     TABLES = 283,
     PIPE = 284,
     EQUAL = 285,
     CHAR_VALUE = 286,
     SEMICOLON = 287,
     OPEN_BRACKET = 288,
     CLOSE_BRACKET = 289,
     STAR = 290,
     PLUS = 291,
     MINUS = 292,
     RECORD = 293,
     COMMA = 294,
     THROUGH = 295,
     TYPE = 296,
     DELIMITERS = 297,
     KW_CHAR = 298,
     KW_INT = 299,
     KW_DATE = 300,
     KW_FLOAT = 301,
     SMALLFLOAT = 302,
     SMALLINT = 303,
     KW_DECIMAL = 304,
     MONEY = 305,
     DATETIME = 306,
     INTERVAL = 307,
     LIKE = 308,
     BLACK = 309,
     BLUE = 310,
     GREEN = 311,
     CYAN = 312,
     RED = 313,
     MAGENTA = 314,
     WHITE = 315,
     YELLOW = 316,
     REVERSE = 317,
     LEFT = 318,
     BLINK = 319,
     UNDERLINE = 320,
     AUTONEXT = 321,
     COLOR = 322,
     COMMENTS = 323,
     DEFAULT = 324,
     VALIDATE = 325,
     DISPLAY = 326,
     DOWNSHIFT = 327,
     UPSHIFT = 328,
     FORMAT = 329,
     INCLUDE = 330,
     INVISIBLE = 331,
     NOENTRY = 332,
     PICTURE = 333,
     PROGRAM = 334,
     REQUIRED = 335,
     VERIFY = 336,
     WORDWRAP = 337,
     COMPRESS = 338,
     NONCOMPRESS = 339,
     TO = 340,
     AS = 341,
     SERIAL = 342,
     KW_BYTE = 343,
     KW_TEXT = 344,
     VARCHAR = 345,
     SQL_VAR = 346,
     SQLONLY = 347,
     WIDGET = 348,
     CONFIG = 349,
     COMPARISON = 350,
     KWOR = 351,
     KWAND = 352,
     KWWHERE = 353,
     KWNOT = 354,
     KWBETWEEN = 355,
     KWIN = 356,
     XVAL = 357,
     KWNULLCHK = 358,
     KWNOTNULLCHK = 359,
     YEAR = 360,
     MONTH = 361,
     DAY = 362,
     HOUR = 363,
     MINUTE = 364,
     SECOND = 365,
     FRACTION = 366,
     LISTBOX = 367,
     BUTTON = 368,
     KW_PANEL = 369
   };
#endif
#define CH 258
#define INSTRUCTIONS 259
#define ATTRIBUTES 260
#define DATABASE 261
#define BY 262
#define KW_SCREEN_TITLE 263
#define KW_SCREEN 264
#define KW_SIZE 265
#define OPEN_SQUARE 266
#define KW_END 267
#define CLOSE_SQUARE 268
#define NUMBER_VALUE 269
#define NAMED 270
#define OPEN_BRACE 271
#define CLOSE_BRACE 272
#define TITLE 273
#define FORMONLY 274
#define COMMENT 275
#define DYNAMIC 276
#define COLON 277
#define ATSIGN 278
#define DOT 279
#define WITHOUT 280
#define KW_NULL 281
#define INPUT 282
#define TABLES 283
#define PIPE 284
#define EQUAL 285
#define CHAR_VALUE 286
#define SEMICOLON 287
#define OPEN_BRACKET 288
#define CLOSE_BRACKET 289
#define STAR 290
#define PLUS 291
#define MINUS 292
#define RECORD 293
#define COMMA 294
#define THROUGH 295
#define TYPE 296
#define DELIMITERS 297
#define KW_CHAR 298
#define KW_INT 299
#define KW_DATE 300
#define KW_FLOAT 301
#define SMALLFLOAT 302
#define SMALLINT 303
#define KW_DECIMAL 304
#define MONEY 305
#define DATETIME 306
#define INTERVAL 307
#define LIKE 308
#define BLACK 309
#define BLUE 310
#define GREEN 311
#define CYAN 312
#define RED 313
#define MAGENTA 314
#define WHITE 315
#define YELLOW 316
#define REVERSE 317
#define LEFT 318
#define BLINK 319
#define UNDERLINE 320
#define AUTONEXT 321
#define COLOR 322
#define COMMENTS 323
#define DEFAULT 324
#define VALIDATE 325
#define DISPLAY 326
#define DOWNSHIFT 327
#define UPSHIFT 328
#define FORMAT 329
#define INCLUDE 330
#define INVISIBLE 331
#define NOENTRY 332
#define PICTURE 333
#define PROGRAM 334
#define REQUIRED 335
#define VERIFY 336
#define WORDWRAP 337
#define COMPRESS 338
#define NONCOMPRESS 339
#define TO 340
#define AS 341
#define SERIAL 342
#define KW_BYTE 343
#define KW_TEXT 344
#define VARCHAR 345
#define SQL_VAR 346
#define SQLONLY 347
#define WIDGET 348
#define CONFIG 349
#define COMPARISON 350
#define KWOR 351
#define KWAND 352
#define KWWHERE 353
#define KWNOT 354
#define KWBETWEEN 355
#define KWIN 356
#define XVAL 357
#define KWNULLCHK 358
#define KWNOTNULLCHK 359
#define YEAR 360
#define MONTH 361
#define DAY 362
#define HOUR 363
#define MINUTE 364
#define SECOND 365
#define FRACTION 366
#define LISTBOX 367
#define BUTTON 368
#define KW_PANEL 369




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
/* extern FILE *yyin; */
int in_screen_section=0;
int dtype_size=0;

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
#line 69 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 382 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 394 "y.tab.c"

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
#define YYLAST   1441

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  84
/* YYNRULES -- Number of rules. */
#define YYNRULES  313
/* YYNRULES -- Number of states. */
#define YYNSTATES  451

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   369

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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    37,    39,    42,    43,    47,    48,    53,    54,    55,
      56,    65,    66,    69,    74,    75,    77,    79,    82,    84,
      86,    88,    90,    92,    94,    95,   100,   102,   103,   108,
     109,   113,   115,   118,   122,   125,   126,   129,   131,   135,
     139,   145,   149,   153,   155,   158,   159,   164,   166,   169,
     170,   171,   178,   179,   183,   189,   193,   195,   196,   202,
     206,   209,   214,   218,   220,   221,   224,   226,   230,   232,
     237,   241,   245,   249,   255,   259,   265,   267,   269,   273,
     279,   283,   287,   289,   294,   296,   298,   300,   304,   308,
     310,   312,   314,   316,   319,   322,   324,   326,   328,   330,
     333,   335,   337,   339,   341,   343,   345,   347,   349,   351,
     353,   355,   357,   358,   359,   364,   366,   369,   371,   374,
     377,   378,   388,   401,   402,   405,   406,   408,   410,   415,
     417,   421,   422,   424,   426,   430,   434,   438,   442,   444,
     448,   450,   452,   454,   456,   458,   460,   462,   464,   467,
     470,   473,   476,   478,   480,   482,   484,   486,   488,   492,
     494,   497,   500,   502,   504,   508,   510,   512,   516,   520,
     522,   523,   527,   533,   534,   538,   539,   543,   545,   548,
     550,   552,   554,   556,   558,   560,   563,   565,   566,   570,
     572,   574,   576,   578,   580,   582,   584,   586,   589,   590,
     594,   595,   597,   600,   602,   606,   610,   614,   618,   623,
     627,   630,   633,   635,   641,   647,   650,   654,   656,   658,
     660,   662,   664,   666,   670,   672,   674,   676,   678,   680,
     682,   684,   686,   688,   690,   692,   694,   696,   698,   700,
     702,   704,   706,   708,   710,   712,   714,   716,   718,   720,
     722,   724,   726,   728,   730,   732,   734,   736,   738,   740,
     742,   744,   746,   748,   750,   752,   754,   756,   758,   760,
     762,   764,   766,   768,   770,   772,   774,   776,   778,   780,
     782,   784,   786,   788,   790,   792,   794,   796,   798,   800,
     802,   804,   806,   808,   810,   812,   814,   816,   818,   820,
     822,   824,   826,   828
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     116,     0,    -1,   117,   120,   137,   142,   160,    -1,     6,
      19,    -1,     6,   119,    25,    26,    27,    -1,     6,    19,
      25,    26,    27,    -1,     6,   119,    -1,    15,    -1,   198,
      -1,   118,    -1,   118,    23,   118,    -1,   121,    -1,   120,
     121,    -1,    -1,     9,   122,   124,    -1,    -1,     8,    31,
     123,   124,    -1,    -1,    -1,    -1,   128,   125,    16,   126,
     130,    17,   127,   129,    -1,    -1,    10,    14,    -1,    10,
      14,     7,    14,    -1,    -1,    12,    -1,   132,    -1,   130,
     132,    -1,   118,    -1,   131,    -1,   133,    -1,     3,    -1,
      29,    -1,    31,    -1,    -1,    11,   134,   135,    13,    -1,
     174,    -1,    -1,   135,    29,   136,   174,    -1,    -1,    28,
     138,   129,    -1,   139,    -1,   138,   139,    -1,   138,    39,
     139,    -1,   118,   140,    -1,    -1,    30,   141,    -1,   118,
      -1,   118,    22,   118,    -1,   118,    23,   118,    -1,   118,
      23,   118,    22,   118,    -1,   118,    24,   118,    -1,     5,
     143,   129,    -1,   144,    -1,   143,   144,    -1,    -1,   174,
     145,   146,    32,    -1,   147,    -1,   146,   147,    -1,    -1,
      -1,    30,   148,   153,   150,   149,   154,    -1,    -1,    11,
      14,    13,    -1,    11,    14,    39,    14,    13,    -1,   152,
      99,    26,    -1,   152,    -1,    -1,    41,    53,   118,    24,
     118,    -1,    41,    53,   118,    -1,    41,   175,    -1,    19,
      24,   173,   151,    -1,   118,    24,   118,    -1,   118,    -1,
      -1,    39,   155,    -1,   156,    -1,   155,    39,   156,    -1,
      66,    -1,    67,    30,   158,   191,    -1,    68,    30,    31,
      -1,    69,    30,   157,    -1,    71,    53,   118,    -1,    71,
      53,   118,    24,   118,    -1,    70,    53,   118,    -1,    70,
      53,   118,    24,   118,    -1,    72,    -1,    73,    -1,    74,
      30,    31,    -1,    75,    30,    33,   176,    34,    -1,    93,
      30,    31,    -1,    94,    30,    31,    -1,    76,    -1,    21,
      10,    30,    14,    -1,    21,    -1,    92,    -1,    77,    -1,
      78,    30,    31,    -1,    79,    30,    31,    -1,    80,    -1,
      62,    -1,    81,    -1,    82,    -1,    82,    83,    -1,    82,
      84,    -1,    31,    -1,    14,    -1,    91,    -1,   159,    -1,
     158,   159,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    64,    -1,    65,    -1,    -1,    -1,     4,
     161,   162,   129,    -1,   163,    -1,   162,   163,    -1,   164,
      -1,   164,    32,    -1,    42,    31,    -1,    -1,     9,    38,
     165,   168,    33,   169,    34,   166,   167,    -1,   114,    33,
      14,    39,    14,    34,    85,    33,    14,    39,    14,    34,
      -1,    -1,    86,   112,    -1,    -1,    32,    -1,   118,    -1,
     118,    11,    14,    13,    -1,   172,    -1,   169,   170,   172,
      -1,    -1,    39,    -1,   118,    -1,   118,    24,   118,    -1,
      19,    24,   118,    -1,   118,    24,    35,    -1,    19,    24,
      35,    -1,   171,    -1,   171,    40,   171,    -1,   118,    -1,
     118,    -1,    43,    -1,    44,    -1,    45,    -1,    46,    -1,
      47,    -1,    48,    -1,    49,   179,    -1,    50,   179,    -1,
      51,   186,    -1,    52,   180,    -1,    87,    -1,    88,    -1,
      89,    -1,    90,    -1,   113,    -1,   178,    -1,   176,    39,
     178,    -1,    14,    -1,    36,    14,    -1,    37,    14,    -1,
      31,    -1,    15,    -1,    15,    85,    15,    -1,     3,    -1,
     177,    -1,   177,    85,   177,    -1,    31,    85,    31,    -1,
      26,    -1,    -1,    33,    14,    34,    -1,    33,    14,    39,
      14,    34,    -1,    -1,   183,    85,   185,    -1,    -1,    33,
      14,    34,    -1,    14,    -1,   184,   181,    -1,   105,    -1,
     106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,
     111,   190,    -1,   184,    -1,    -1,   187,    85,   188,    -1,
     189,    -1,   189,    -1,   105,    -1,   106,    -1,   107,    -1,
     108,    -1,   109,    -1,   110,    -1,   111,   190,    -1,    -1,
      33,   182,    34,    -1,    -1,   192,    -1,    98,   193,    -1,
     194,    -1,   194,    97,   194,    -1,   194,    96,   194,    -1,
     195,    95,   195,    -1,   195,    53,   195,    -1,   195,    99,
      53,   195,    -1,   195,    30,   195,    -1,   195,   103,    -1,
     195,   104,    -1,   195,    -1,   195,   100,   195,    97,   195,
      -1,   195,   101,    33,   197,    34,    -1,    99,   194,    -1,
      33,   194,    34,    -1,   196,    -1,    14,    -1,    31,    -1,
     102,    -1,    15,    -1,   195,    -1,   197,    39,   195,    -1,
      86,    -1,    66,    -1,    54,    -1,    64,    -1,    55,    -1,
      96,    -1,    97,    -1,    95,    -1,   113,    -1,     7,    -1,
      67,    -1,    20,    -1,    68,    -1,    83,    -1,    94,    -1,
      57,    -1,     6,    -1,    51,    -1,    69,    -1,    42,    -1,
      72,    -1,    21,    -1,    74,    -1,    56,    -1,    75,    -1,
      27,    -1,    52,    -1,    76,    -1,    88,    -1,    43,    -1,
      45,    -1,    49,    -1,    46,    -1,    44,    -1,    26,    -1,
     114,    -1,     9,    -1,     8,    -1,    10,    -1,    89,    -1,
      63,    -1,   112,    -1,    59,    -1,    50,    -1,    77,    -1,
      84,    -1,    99,    -1,    78,    -1,    79,    -1,    38,    -1,
      58,    -1,    80,    -1,    62,    -1,    87,    -1,    47,    -1,
      48,    -1,    92,    -1,    91,    -1,    28,    -1,    40,    -1,
      18,    -1,    85,    -1,    65,    -1,    73,    -1,    90,    -1,
      81,    -1,    60,    -1,    93,    -1,    25,    -1,    82,    -1,
      61,    -1,    41,    -1,    53,    -1,   105,    -1,   106,    -1,
     107,    -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    95,    95,    98,    99,   104,   105,   113,   114,   118,
     118,   121,   121,   124,   124,   137,   137,   157,   159,   162,
     156,   169,   170,   171,   183,   184,   189,   190,   193,   206,
     211,   212,   220,   230,   241,   240,   258,   263,   262,   283,
     284,   287,   288,   289,   292,   299,   300,   303,   304,   305,
     307,   308,   314,   318,   318,   322,   322,   331,   331,   334,
     338,   334,   362,   363,   367,   375,   376,   379,   380,   383,
     386,   391,   400,   408,   417,   418,   422,   422,   425,   426,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   461,   462,   463,   464,   465,   466,
     469,   472,   475,   478,   482,   488,   489,   490,   492,   492,
     498,   501,   504,   507,   510,   513,   516,   519,   522,   525,
     528,   531,   535,   536,   536,   541,   541,   543,   543,   546,
     556,   556,   559,   562,   562,   564,   564,   567,   570,   585,
     588,   592,   593,   597,   599,   601,   603,   605,   610,   610,
     614,   620,   627,   631,   635,   639,   643,   647,   651,   655,
     659,   663,   667,   671,   675,   679,   682,   689,   689,   694,
     694,   694,   699,   700,   701,   702,   703,   704,   707,   711,
     717,   718,   719,   722,   723,   730,   732,   737,   745,   748,
     749,   750,   751,   752,   753,   754,   760,   762,   763,   766,
     769,   773,   774,   775,   776,   777,   778,   779,   785,   787,
     794,   794,   800,   806,   807,   810,   816,   819,   822,   825,
     828,   833,   838,   842,   848,   851,   854,   859,   866,   869,
     870,   875,   878,   882,   890,   891,   892,   893,   894,   895,
     896,   897,   898,   899,   900,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,   917,   918,   919,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   931,   932,   933,   934,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   951,   952,   953,   954,   955,
     956,   957,   958,   959,   960,   961,   962,   963,   964,   965,
     966,   967,   968,   969
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "INSTRUCTIONS", "ATTRIBUTES", 
  "DATABASE", "BY", "KW_SCREEN_TITLE", "KW_SCREEN", "KW_SIZE", 
  "OPEN_SQUARE", "KW_END", "CLOSE_SQUARE", "NUMBER_VALUE", "NAMED", 
  "OPEN_BRACE", "CLOSE_BRACE", "TITLE", "FORMONLY", "COMMENT", "DYNAMIC", 
  "COLON", "ATSIGN", "DOT", "WITHOUT", "KW_NULL", "INPUT", "TABLES", 
  "PIPE", "EQUAL", "CHAR_VALUE", "SEMICOLON", "OPEN_BRACKET", 
  "CLOSE_BRACKET", "STAR", "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", 
  "TYPE", "DELIMITERS", "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", 
  "SMALLFLOAT", "SMALLINT", "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", 
  "LIKE", "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", 
  "YELLOW", "REVERSE", "LEFT", "BLINK", "UNDERLINE", "AUTONEXT", "COLOR", 
  "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY", "DOWNSHIFT", "UPSHIFT", 
  "FORMAT", "INCLUDE", "INVISIBLE", "NOENTRY", "PICTURE", "PROGRAM", 
  "REQUIRED", "VERIFY", "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO", "AS", 
  "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR", "SQLONLY", 
  "WIDGET", "CONFIG", "COMPARISON", "KWOR", "KWAND", "KWWHERE", "KWNOT", 
  "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", "KWNOTNULLCHK", "YEAR", 
  "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", "FRACTION", "LISTBOX", 
  "BUTTON", "KW_PANEL", "$accept", "form_def", "database_section", 
  "named_or_kw", "dbname", "screen_section", "screens_section", "@1", 
  "@2", "screens_rest", "@3", "@4", "@5", "op_size", "op_end", 
  "screen_layout", "some_text", "screen_element", "field", "@6", 
  "field_element", "@7", "op_table_section", "table_def_list", 
  "table_def", "opequal", "table_qualifier", "attribute_section", 
  "field_tag_list", "field_tag", "@8", "fpart_list", "fpart", "@9", "@10", 
  "op_att", "field_datatype_null", "field_datatype", "field_type", 
  "op_field_desc", "op_desc_list", "desc", "def_val", "colors", "color", 
  "op_instruction_section", "@11", "instruct_opts", "instruct_op_1", 
  "instruct_op", "@12", "op_ltype", "op_semi", "srec_dim", 
  "srec_field_list", "op_comma", "field_list_item", "field_list_element", 
  "field_name", "field_tag_name", "datatype", "incl_list", "number_value", 
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
     365,   366,   367,   368,   369
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   115,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   122,   121,   123,   121,   125,   126,   127,
     124,   128,   128,   128,   129,   129,   130,   130,   131,   132,
     132,   132,   132,   132,   134,   133,   135,   136,   135,   137,
     137,   138,   138,   138,   139,   140,   140,   141,   141,   141,
     141,   141,   142,   143,   143,   145,   144,   146,   146,   148,
     149,   147,   150,   150,   150,   151,   151,   152,   152,   152,
     152,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   157,   157,   158,   158,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   160,   161,   160,   162,   162,   163,   163,   164,
     165,   164,   164,   166,   166,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   171,   171,   171,   171,   172,   172,
     173,   174,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   176,   176,   177,
     177,   177,   178,   178,   178,   178,   178,   178,   178,   178,
     179,   179,   179,   180,   180,   181,   181,   182,   183,   184,
     184,   184,   184,   184,   184,   184,   185,   186,   186,   187,
     188,   189,   189,   189,   189,   189,   189,   189,   190,   190,
     191,   191,   192,   193,   193,   193,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   195,   195,   195,
     195,   196,   197,   197,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     2,     0,     3,     0,     4,     0,     0,     0,
       8,     0,     2,     4,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     0,     4,     0,
       3,     1,     2,     3,     2,     0,     2,     1,     3,     3,
       5,     3,     3,     1,     2,     0,     4,     1,     2,     0,
       0,     6,     0,     3,     5,     3,     1,     0,     5,     3,
       2,     4,     3,     1,     0,     2,     1,     3,     1,     4,
       3,     3,     3,     5,     3,     5,     1,     1,     3,     5,
       3,     3,     1,     4,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     4,     1,     2,     1,     2,     2,
       0,     9,    12,     0,     2,     0,     1,     1,     4,     1,
       3,     0,     1,     1,     3,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
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
       0,     0,     0,     0,   250,   243,   271,   270,   272,     7,
     294,     3,   245,   255,   302,   268,   259,   292,   283,   293,
     305,   253,   263,   267,   264,   266,   288,   289,   265,   277,
     251,   260,   306,   236,   238,   257,   249,   284,   276,   300,
     304,   286,   274,   237,   296,   235,   244,   246,   252,   254,
     297,   256,   258,   261,   278,   281,   282,   285,   299,   303,
     247,   279,   295,   234,   287,   262,   273,   298,   291,   290,
     301,   248,   241,   239,   240,   280,   307,   308,   309,   310,
     311,   312,   313,   275,   242,   269,     9,     6,     8,     1,
       0,    13,    39,    11,     0,     0,     0,    15,    21,     0,
      12,     0,     0,    10,     0,    21,     0,    14,    17,    45,
      24,    41,     0,   122,     5,     4,    16,    22,     0,     0,
      44,    25,     0,    40,    42,   151,    24,    53,    55,   123,
       2,     0,    18,    47,    46,    43,    52,    54,     0,     0,
      23,     0,     0,     0,     0,    59,     0,    57,     0,     0,
       0,    24,   125,   127,    31,    34,    32,    33,    28,     0,
      29,    26,    30,    48,    49,    51,     0,    56,    58,   130,
     129,     0,   124,   126,   128,     0,    19,    27,     0,     0,
      73,    62,     0,     0,     0,    36,    24,    50,     0,     0,
       0,    60,   137,     0,     0,    35,    37,    20,   150,    67,
      72,     0,    74,     0,     0,     0,     0,     0,    71,    66,
      63,     0,     0,    61,     0,     0,   143,   141,   148,   139,
       0,    38,   152,   153,   154,   155,   156,   157,   180,   180,
     197,   183,     0,   162,   163,   164,   165,   166,    70,     0,
       0,    94,   100,    78,     0,     0,     0,     0,     0,    86,
      87,     0,     0,    92,    96,     0,     0,    99,   101,   102,
      95,     0,     0,    75,    76,   138,     0,     0,   133,   142,
       0,     0,     0,     0,   158,   159,   201,   202,   203,   204,
     205,   206,   208,   160,     0,   199,   189,   190,   191,   192,
     193,   194,   208,   161,     0,   185,    69,    65,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     104,     0,     0,     0,   147,   145,   146,   144,     0,   135,
     140,   149,     0,     0,     0,   207,     0,   195,     0,     0,
     188,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   210,   108,    80,   106,   105,
     107,    81,    84,    82,    88,     0,    97,    98,    90,    91,
      77,   134,   136,   131,     0,   181,     0,   187,     0,   198,
     200,   196,   184,     0,    68,    93,     0,   109,    79,   211,
       0,     0,   175,   169,   173,   179,   172,     0,     0,     0,
     176,   167,     0,     0,   209,   186,   228,   231,   229,     0,
       0,   230,   212,   213,   222,   227,    85,    83,     0,     0,
     170,   171,    89,     0,     0,     0,   182,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   174,
     178,   168,   177,   132,   226,   215,   214,   219,   217,   216,
       0,     0,     0,   218,     0,   232,     0,   223,   224,     0,
     233
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   125,    87,    92,    93,    98,   105,   107,
     118,   141,   186,   108,   123,   159,   160,   161,   162,   175,
     184,   206,   101,   110,   111,   120,   134,   113,   126,   127,
     138,   146,   147,   166,   202,   191,   208,   209,   181,   213,
     263,   264,   351,   345,   346,   130,   139,   151,   152,   153,
     182,   319,   363,   193,   217,   270,   218,   219,   199,   128,
     238,   389,   390,   391,   274,   293,   330,   368,   294,   295,
     372,   283,   284,   369,   285,   325,   378,   379,   402,   403,
     404,   405,   446,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -412
static const short yypact[] =
{
       9,   673,    30,    10,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,     1,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,    43,    48,  -412,  -412,
      46,  -412,    63,  -412,    69,  1327,    82,  -412,   103,  1327,
    -412,   111,    93,  -412,    97,   103,   113,  -412,  -412,    98,
     564,  -412,  1327,   125,  -412,  -412,  -412,   123,   116,  1327,
    -412,  -412,  1327,  -412,  -412,  -412,   782,  -412,  -412,  -412,
    -412,   119,  -412,    88,  -412,  -412,  -412,  -412,   104,    -7,
    -412,   455,  1327,  1327,  1327,  -412,    87,  -412,   101,   107,
     102,    -8,  -412,   124,  -412,  -412,  -412,  -412,  -412,   343,
    -412,  -412,  -412,  -412,   135,  -412,   891,  -412,  -412,  -412,
    -412,   145,  -412,  -412,  -412,  1327,  -412,  -412,  1327,   136,
     138,   152,  1327,   134,     8,  -412,   162,  -412,  1327,  1327,
     150,  -412,   164,   143,   165,  -412,  -412,  -412,  -412,   137,
    -412,    14,   141,   168,  1000,   149,  1327,    12,  -412,    85,
    -412,   171,   140,  -412,   173,   172,   174,    36,   157,  -412,
     114,  -412,  -412,  -412,  -412,  -412,  -412,  -412,   167,   167,
      61,    84,  1327,  -412,  -412,  -412,  -412,  -412,  -412,   175,
     191,   195,  -412,  -412,   193,   194,   196,   176,   177,  -412,
    -412,   197,   198,  -412,  -412,   205,   206,  -412,  -412,    21,
    -412,   207,   208,   186,  -412,  -412,  1109,  1218,   153,  -412,
    1000,  1000,   209,   226,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,   210,  -412,   156,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,   210,  -412,   159,   212,   222,  -412,  -412,   217,
      90,   218,   -11,  1327,  1327,   219,   215,   220,   221,  -412,
    -412,   223,   224,   140,  -412,  -412,  -412,  -412,   144,   225,
    -412,  -412,   239,    40,   244,  -412,    61,  -412,    84,   245,
    -412,  1327,   246,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,   -13,  -412,  -412,  -412,  -412,
    -412,  -412,   237,   238,  -412,   100,  -412,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,   228,  -412,   249,  -412,   230,  -412,
    -412,  -412,  -412,   234,  -412,  -412,    -9,  -412,  -412,  -412,
    1327,  1327,  -412,  -412,   187,  -412,   188,   257,   260,    42,
     190,  -412,   262,   243,  -412,  -412,  -412,  -412,  -412,    -9,
      -9,  -412,  -412,    26,   -17,  -412,  -412,  -412,   263,   248,
    -412,  -412,  -412,   100,     3,   247,  -412,   250,  -412,    -9,
      -9,    -6,    -6,    -6,   227,    -6,   252,  -412,  -412,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
      -6,   185,    -6,  -412,    -6,  -412,    58,  -412,  -412,    -6,
    -412
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -412,  -412,  -412,    -1,  -412,  -412,   199,  -412,  -412,   178,
    -412,  -412,  -412,  -412,  -119,  -412,  -412,   127,  -412,  -412,
    -412,  -412,  -412,  -412,   -94,  -412,  -412,  -412,  -412,   161,
    -412,  -412,   142,  -412,  -412,  -412,  -412,  -412,  -412,  -412,
    -412,   -24,  -412,  -412,   -55,  -412,  -412,  -412,   146,  -412,
    -412,  -412,  -412,  -412,  -412,  -412,    22,    24,  -412,  -152,
    -412,  -412,  -122,  -118,    67,  -412,  -412,  -412,  -412,   -30,
    -412,  -412,  -412,  -412,   -27,    13,  -412,  -412,  -412,  -331,
    -411,  -412,  -412,  -412
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      86,   148,   148,   348,   121,   396,   397,   136,   396,   397,
     437,   438,   439,   421,   441,     1,   124,   383,    90,    91,
     349,   195,   398,   185,   399,   398,    94,   210,   135,   443,
      89,   445,   172,   447,   149,   149,   422,   196,   450,   387,
     388,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   211,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    95,   197,   417,   418,
     268,    90,    91,    96,   365,   269,   412,    97,   423,   366,
     350,   413,   424,   425,   426,   376,   427,   428,   435,   436,
     400,    99,   448,   401,   103,   102,   401,   449,   109,   233,
     234,   235,   236,   382,   309,   310,   150,   150,   104,   109,
     142,   143,   144,   106,   383,   384,   112,   145,   133,   167,
     114,   109,   419,   420,   115,   237,   385,   117,   119,   129,
     131,   386,   132,   140,   145,   171,   387,   388,   170,   169,
     158,   163,   164,   165,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   174,   178,   158,   183,
     188,   241,   189,   190,   201,   180,   276,   277,   278,   279,
     280,   281,   282,   194,   121,   203,   204,   187,   207,   205,
     212,   192,   214,   220,   239,   240,   265,   198,   200,   286,
     287,   288,   289,   290,   291,   292,   266,   271,   267,   272,
     273,   297,   242,   216,   298,   299,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   300,   301,   313,   302,   305,   306,   303,
     304,   296,   260,   261,   262,   307,   308,   311,   312,   318,
     323,   326,   322,   324,   328,   329,   331,   332,   355,   347,
     354,   356,   357,   364,   358,   359,   361,   362,   367,   373,
     375,   380,   381,   393,   394,   315,   317,   392,   395,   216,
     216,   410,   408,   409,   411,   414,   415,   416,   429,   430,
     440,   433,   444,   116,   434,   442,   177,   137,   168,   360,
     377,   100,   432,   321,   320,   431,   275,   173,   371,   370,
       0,     0,   352,   353,     0,   327,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     374,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,     4,
       5,     6,     7,     8,   155,     0,     0,     0,     9,     0,
     176,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,   156,     0,   157,     0,     0,     0,     0,   406,
     407,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   154,     0,
       0,     4,     5,     6,     7,     8,   155,     0,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,    15,    16,    17,   156,     0,   157,     0,     0,     0,
       0,     0,     0,    18,     0,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,    75,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       4,     5,     6,     7,     8,     0,   121,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,   122,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,    75,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,    10,    11,    12,    13,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     4,     5,
       6,     7,     8,     0,   121,     0,     0,     9,     0,     0,
      10,     0,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,    75,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
     179,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,   215,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,   314,     0,     0,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,    75,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,   316,     0,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,    75,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85
};

static const short yycheck[] =
{
       1,     9,     9,    14,    12,    14,    15,   126,    14,    15,
     421,   422,   423,    30,   425,     6,   110,    14,     8,     9,
      31,    13,    31,   175,    33,    31,    25,    13,   122,   440,
       0,   442,   151,   444,    42,    42,    53,    29,   449,    36,
      37,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    39,   206,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    23,   186,   399,   400,
      34,     8,     9,    25,    34,    39,    34,    31,    95,    39,
      91,    39,    99,   100,   101,    98,   103,   104,   419,   420,
      99,    28,    34,   102,    95,    26,   102,    39,    99,    87,
      88,    89,    90,     3,    83,    84,   114,   114,    26,   110,
      22,    23,    24,    10,    14,    15,     5,    30,   119,    32,
      27,   122,    96,    97,    27,   113,    26,    14,    30,     4,
       7,    31,    16,    14,    30,    33,    36,    37,    31,    38,
     141,   142,   143,   144,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    32,    22,   159,    14,
      24,    21,    24,    11,    14,   166,   105,   106,   107,   108,
     109,   110,   111,    39,    12,    11,    33,   178,    41,    14,
      39,   182,    14,    34,    99,    14,    13,   188,   189,   105,
     106,   107,   108,   109,   110,   111,    24,    40,    24,    85,
      33,    26,    62,   204,    13,    10,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    30,    30,    39,    30,    30,    30,    53,
      53,   232,    92,    93,    94,    30,    30,    30,    30,    86,
      14,    85,    33,    33,    85,    33,    24,    30,    33,    31,
      31,    31,    31,    14,    31,    31,   112,    32,    14,    14,
      14,    24,    24,    14,    34,   266,   267,    39,    34,   270,
     271,    14,    85,    85,    14,    85,    14,    34,    15,    31,
      53,    34,    97,   105,    34,    33,   159,   126,   146,   313,
     345,    92,   414,   271,   270,   413,   229,   151,   328,   326,
      -1,    -1,   303,   304,    -1,   292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    -1,    31,    -1,    -1,    -1,    -1,   380,
     381,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     3,    -1,
      -1,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       6,     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    18,    19,    20,    21,    -1,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     6,     7,
       8,     9,    10,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    18,
      19,    20,    21,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    15,    -1,    -1,    18,    -1,    20,
      21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    18,    -1,    20,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     6,   116,   117,     6,     7,     8,     9,    10,    15,
      18,    19,    20,    21,    25,    26,    27,    28,    38,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    99,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   118,   119,   198,     0,
       8,     9,   120,   121,    25,    23,    25,    31,   122,    28,
     121,   137,    26,   118,    26,   123,    10,   124,   128,   118,
     138,   139,     5,   142,    27,    27,   124,    14,   125,    30,
     140,    12,    39,   129,   139,   118,   143,   144,   174,     4,
     160,     7,    16,   118,   141,   139,   129,   144,   145,   161,
      14,   126,    22,    23,    24,    30,   146,   147,     9,    42,
     114,   162,   163,   164,     3,    11,    29,    31,   118,   130,
     131,   132,   133,   118,   118,   118,   148,    32,   147,    38,
      31,    33,   129,   163,    32,   134,    17,   132,    22,    19,
     118,   153,   165,    14,   135,   174,   127,   118,    24,    24,
      11,   150,   118,   168,    39,    13,    29,   129,   118,   173,
     118,    14,   149,    11,    33,    14,   136,    41,   151,   152,
      13,    39,    39,   154,    14,    19,   118,   169,   171,   172,
      34,   174,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    87,    88,    89,    90,   113,   175,    99,
      14,    21,    62,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      92,    93,    94,   155,   156,    13,    24,    24,    34,    39,
     170,    40,    85,    33,   179,   179,   105,   106,   107,   108,
     109,   110,   111,   186,   187,   189,   105,   106,   107,   108,
     109,   110,   111,   180,   183,   184,   118,    26,    13,    10,
      30,    30,    30,    53,    53,    30,    30,    30,    30,    83,
      84,    30,    30,    39,    35,   118,    35,   118,    86,   166,
     172,   171,    33,    14,    33,   190,    85,   190,    85,    33,
     181,    24,    30,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   158,   159,    31,    14,    31,
      91,   157,   118,   118,    31,    33,    31,    31,    31,    31,
     156,   112,    32,   167,    14,    34,    39,    14,   182,   188,
     189,   184,   185,    14,   118,    14,    98,   159,   191,   192,
      24,    24,     3,    14,    15,    26,    31,    36,    37,   176,
     177,   178,    39,    14,    34,    34,    14,    15,    31,    33,
      99,   102,   193,   194,   195,   196,   118,   118,    85,    85,
      14,    14,    34,    39,    85,    14,    34,   194,   194,    96,
      97,    30,    53,    95,    99,   100,   101,   103,   104,    15,
      31,   178,   177,    34,    34,   194,   194,   195,   195,   195,
      53,   195,    33,   195,    97,   195,   197,   195,    34,    39,
     195
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
#line 95 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 98 "screen.yacc"
    {the_form.dbname=strdup("formonly");}
    break;

  case 4:
#line 99 "screen.yacc"
    {the_form.dbname=(yyvsp[-3].str);
if (A4GLF_open_db(yyvsp[-3].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 104 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 105 "screen.yacc"
    {the_form.dbname=strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 10:
#line 118 "screen.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 13:
#line 124 "screen.yacc"
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
#line 137 "screen.yacc"
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
#line 157 "screen.yacc"
    { ignorekw=1; 
		lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 18:
#line 159 "screen.yacc"
    { lineno=0; }
    break;

  case 19:
#line 162 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 171 "screen.yacc"
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
#line 193 "screen.yacc"
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
#line 206 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	     A4GL_add_field("_label",1+colno-strlen(yyvsp[0].str),lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
}
    break;

  case 31:
#line 212 "screen.yacc"
    {
	char buff[256];
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	strcpy(buff,yyvsp[0].str);
	if (buff[0]=='\n') A4GL_add_field("_label",1+colno-1,lineno,1,scr,0,yyvsp[0].str);
	else A4GL_add_field("_label",1+colno-strlen(yyvsp[0].str),lineno,1,scr,0,yyvsp[0].str);
}
    break;

  case 32:
#line 220 "screen.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (buff[0]=='\n') A4GL_add_field("_label",1+colno-1,lineno,1,scr,0,yyvsp[0].str);
	else A4GL_add_field("_label",1+colno-strlen(yyvsp[0].str),lineno,1,scr,0,yyvsp[0].str);
}
    break;

  case 33:
#line 230 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	     A4GL_add_field("_label",1+colno-strlen(yyvsp[0].str),lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
}
    break;

  case 34:
#line 241 "screen.yacc"
    {
	fstart=colno;
	openwith='[';
}
    break;

  case 35:
#line 247 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 36:
#line 258 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 37:
#line 263 "screen.yacc"
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

  case 38:
#line 277 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 44:
#line 292 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 45:
#line 299 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 46:
#line 300 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 47:
#line 303 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 48:
#line 304 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 49:
#line 306 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 50:
#line 307 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 51:
#line 308 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 55:
#line 322 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 59:
#line 334 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 60:
#line 338 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 61:
#line 348 "screen.yacc"
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

  case 63:
#line 363 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 64:
#line 367 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 65:
#line 375 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 66:
#line 376 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 67:
#line 379 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 68:
#line 380 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 69:
#line 383 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 70:
#line 386 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 71:
#line 391 "screen.yacc"
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

  case 72:
#line 400 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 73:
#line 408 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 78:
#line 425 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 79:
#line 426 "screen.yacc"
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

  case 80:
#line 446 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 81:
#line 447 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 82:
#line 448 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 83:
#line 449 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 84:
#line 450 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 85:
#line 451 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 86:
#line 452 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 87:
#line 453 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 88:
#line 454 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 89:
#line 455 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 90:
#line 456 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 91:
#line 457 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 92:
#line 458 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 93:
#line 459 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 94:
#line 461 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 95:
#line 462 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 96:
#line 463 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 97:
#line 464 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 98:
#line 465 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 99:
#line 466 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 100:
#line 469 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 101:
#line 472 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_VERIFY);
}
    break;

  case 102:
#line 475 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 103:
#line 478 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 104:
#line 482 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 107:
#line 490 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 109:
#line 492 "screen.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str));
}
    break;

  case 110:
#line 498 "screen.yacc"
    {
	strcpy(yyval.str,"0");
}
    break;

  case 111:
#line 501 "screen.yacc"
    {
	strcpy(yyval.str,"4");
}
    break;

  case 112:
#line 504 "screen.yacc"
    {
	strcpy(yyval.str,"2");
}
    break;

  case 113:
#line 507 "screen.yacc"
    {
	strcpy(yyval.str,"6"); 
}
    break;

  case 114:
#line 510 "screen.yacc"
    {
	strcpy(yyval.str,"1");
}
    break;

  case 115:
#line 513 "screen.yacc"
    {
	strcpy(yyval.str,"5"); 
}
    break;

  case 116:
#line 516 "screen.yacc"
    {
	strcpy(yyval.str,"7");
}
    break;

  case 117:
#line 519 "screen.yacc"
    {
	strcpy(yyval.str,"3");
}
    break;

  case 118:
#line 522 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE"));
}
    break;

  case 119:
#line 525 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT"));
}
    break;

  case 120:
#line 528 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK"));
}
    break;

  case 121:
#line 531 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE"));
}
    break;

  case 123:
#line 536 "screen.yacc"
    {
}
    break;

  case 129:
#line 546 "screen.yacc"
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

  case 130:
#line 556 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 137:
#line 567 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 138:
#line 570 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 139:
#line 585 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 140:
#line 588 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 143:
#line 598 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 144:
#line 600 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 145:
#line 602 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 146:
#line 604 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 147:
#line 606 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 149:
#line 610 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 150:
#line 614 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 151:
#line 620 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 152:
#line 627 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 153:
#line 631 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 154:
#line 635 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 155:
#line 639 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 156:
#line 643 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 157:
#line 647 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 158:
#line 651 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 159:
#line 655 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 160:
#line 659 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 161:
#line 663 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 162:
#line 667 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 163:
#line 671 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 164:
#line 675 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 165:
#line 679 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 166:
#line 682 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 168:
#line 689 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 171:
#line 694 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 172:
#line 699 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 173:
#line 700 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 174:
#line 701 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 175:
#line 702 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 177:
#line 704 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 178:
#line 707 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 179:
#line 711 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 180:
#line 717 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 181:
#line 718 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 182:
#line 719 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 183:
#line 722 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 184:
#line 724 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 185:
#line 730 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 186:
#line 732 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 187:
#line 737 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 188:
#line 745 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 189:
#line 748 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 190:
#line 749 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 191:
#line 750 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 192:
#line 751 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 193:
#line 752 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 194:
#line 753 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 195:
#line 755 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 197:
#line 762 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 198:
#line 763 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 199:
#line 766 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 200:
#line 769 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 201:
#line 773 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 202:
#line 774 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 203:
#line 775 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 204:
#line 776 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 205:
#line 777 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 206:
#line 778 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 207:
#line 780 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 208:
#line 785 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 209:
#line 787 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 210:
#line 794 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 211:
#line 794 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 212:
#line 800 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 214:
#line 807 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 215:
#line 810 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 216:
#line 816 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 217:
#line 819 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 218:
#line 822 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE");
		}
    break;

  case 219:
#line 825 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
	}
    break;

  case 220:
#line 828 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL");
	}
    break;

  case 221:
#line 833 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNOTNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL");
	}
    break;

  case 222:
#line 838 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
			//create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
    break;

  case 223:
#line 842 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[-2].expr);
		add_list_expr(yyval.expr,yyvsp[0].expr);
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN");
	}
    break;

  case 224:
#line 848 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN");
	}
    break;

  case 225:
#line 851 "screen.yacc"
    {
		yyval.expr=create_not_expr(yyvsp[0].expr);
	}
    break;

  case 226:
#line 854 "screen.yacc"
    {
		yyval.expr=yyvsp[-1].expr;
	}
    break;

  case 227:
#line 859 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 228:
#line 866 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str));
printf("NUMBER VALUE : %s\n",yyvsp[0].str);
}
    break;

  case 229:
#line 869 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 230:
#line 870 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 232:
#line 878 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 233:
#line 882 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3210 "y.tab.c"

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


#line 972 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




