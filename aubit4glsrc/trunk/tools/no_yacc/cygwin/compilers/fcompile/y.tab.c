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
     KW_COMPOSITES = 260,
     KW_LESS_THAN = 261,
     KW_GREATER_THAN = 262,
     INSTRUCTIONS = 263,
     ATTRIBUTES = 264,
     DATABASE = 265,
     BY = 266,
     KW_SCREEN_TITLE = 267,
     KW_SCREEN = 268,
     KW_SIZE = 269,
     OPEN_SQUARE = 270,
     KW_END = 271,
     CLOSE_SQUARE = 272,
     NUMBER_VALUE = 273,
     NAMED = 274,
     OPEN_BRACE = 275,
     CLOSE_BRACE = 276,
     TITLE = 277,
     FORMONLY = 278,
     COMMENT = 279,
     DYNAMIC = 280,
     COLON = 281,
     ATSIGN = 282,
     DOT = 283,
     WITHOUT = 284,
     KW_NULL = 285,
     INPUT = 286,
     TABLES = 287,
     PIPE = 288,
     EQUAL = 289,
     CHAR_VALUE = 290,
     SEMICOLON = 291,
     OPEN_BRACKET = 292,
     CLOSE_BRACKET = 293,
     STAR = 294,
     PLUS = 295,
     MINUS = 296,
     RECORD = 297,
     COMMA = 298,
     THROUGH = 299,
     TYPE = 300,
     DELIMITERS = 301,
     KW_CHAR = 302,
     KW_INT = 303,
     KW_DATE = 304,
     KW_FLOAT = 305,
     SMALLFLOAT = 306,
     SMALLINT = 307,
     KW_DECIMAL = 308,
     MONEY = 309,
     DATETIME = 310,
     INTERVAL = 311,
     LIKE = 312,
     BLACK = 313,
     BLUE = 314,
     GREEN = 315,
     CYAN = 316,
     RED = 317,
     MAGENTA = 318,
     WHITE = 319,
     YELLOW = 320,
     REVERSE = 321,
     LEFT = 322,
     BLINK = 323,
     UNDERLINE = 324,
     AUTONEXT = 325,
     COLOR = 326,
     COMMENTS = 327,
     DEFAULT = 328,
     VALIDATE = 329,
     DISPLAY = 330,
     DOWNSHIFT = 331,
     UPSHIFT = 332,
     FORMAT = 333,
     INCLUDE = 334,
     INVISIBLE = 335,
     NOENTRY = 336,
     PICTURE = 337,
     PROGRAM = 338,
     REQUIRED = 339,
     VERIFY = 340,
     WORDWRAP = 341,
     COMPRESS = 342,
     NONCOMPRESS = 343,
     TO = 344,
     AS = 345,
     SERIAL = 346,
     KW_BYTE = 347,
     KW_TEXT = 348,
     VARCHAR = 349,
     SQL_VAR = 350,
     KW_NONSPACE = 351,
     SQLONLY = 352,
     WIDGET = 353,
     CONFIG = 354,
     KW_NL = 355,
     COMPARISON = 356,
     KWOR = 357,
     KWAND = 358,
     KWWHERE = 359,
     KWNOT = 360,
     KWBETWEEN = 361,
     KWIN = 362,
     XVAL = 363,
     KWNULLCHK = 364,
     KWNOTNULLCHK = 365,
     YEAR = 366,
     MONTH = 367,
     DAY = 368,
     HOUR = 369,
     MINUTE = 370,
     SECOND = 371,
     FRACTION = 372,
     LISTBOX = 373,
     BUTTON = 374,
     KW_PANEL = 375,
     KW_WS = 376,
     KW_TAB = 377,
     KW_MASTER_OF = 378,
     KW_BEFORE = 379,
     KW_AFTER = 380,
     KW_EDITADD = 381,
     KW_EDITUPDATE = 382,
     KW_REMOVE = 383,
     KW_OF = 384,
     KW_ADD = 385,
     KW_DISPLAY = 386,
     KW_UPDATE = 387,
     KW_QUERY = 388,
     KW_ON_ENDING = 389,
     KW_ON_BEGINNING = 390,
     KW_CALL = 391,
     KW_BELL = 392,
     KW_ABORT = 393,
     KW_LET = 394,
     KW_EXITNOW = 395,
     KW_REVERSE = 396,
     KW_NEXTFIELD = 397,
     KW_IF = 398,
     KW_THEN = 399,
     KW_ELSE = 400
   };
#endif
#define CH 258
#define GRAPH_CH 259
#define KW_COMPOSITES 260
#define KW_LESS_THAN 261
#define KW_GREATER_THAN 262
#define INSTRUCTIONS 263
#define ATTRIBUTES 264
#define DATABASE 265
#define BY 266
#define KW_SCREEN_TITLE 267
#define KW_SCREEN 268
#define KW_SIZE 269
#define OPEN_SQUARE 270
#define KW_END 271
#define CLOSE_SQUARE 272
#define NUMBER_VALUE 273
#define NAMED 274
#define OPEN_BRACE 275
#define CLOSE_BRACE 276
#define TITLE 277
#define FORMONLY 278
#define COMMENT 279
#define DYNAMIC 280
#define COLON 281
#define ATSIGN 282
#define DOT 283
#define WITHOUT 284
#define KW_NULL 285
#define INPUT 286
#define TABLES 287
#define PIPE 288
#define EQUAL 289
#define CHAR_VALUE 290
#define SEMICOLON 291
#define OPEN_BRACKET 292
#define CLOSE_BRACKET 293
#define STAR 294
#define PLUS 295
#define MINUS 296
#define RECORD 297
#define COMMA 298
#define THROUGH 299
#define TYPE 300
#define DELIMITERS 301
#define KW_CHAR 302
#define KW_INT 303
#define KW_DATE 304
#define KW_FLOAT 305
#define SMALLFLOAT 306
#define SMALLINT 307
#define KW_DECIMAL 308
#define MONEY 309
#define DATETIME 310
#define INTERVAL 311
#define LIKE 312
#define BLACK 313
#define BLUE 314
#define GREEN 315
#define CYAN 316
#define RED 317
#define MAGENTA 318
#define WHITE 319
#define YELLOW 320
#define REVERSE 321
#define LEFT 322
#define BLINK 323
#define UNDERLINE 324
#define AUTONEXT 325
#define COLOR 326
#define COMMENTS 327
#define DEFAULT 328
#define VALIDATE 329
#define DISPLAY 330
#define DOWNSHIFT 331
#define UPSHIFT 332
#define FORMAT 333
#define INCLUDE 334
#define INVISIBLE 335
#define NOENTRY 336
#define PICTURE 337
#define PROGRAM 338
#define REQUIRED 339
#define VERIFY 340
#define WORDWRAP 341
#define COMPRESS 342
#define NONCOMPRESS 343
#define TO 344
#define AS 345
#define SERIAL 346
#define KW_BYTE 347
#define KW_TEXT 348
#define VARCHAR 349
#define SQL_VAR 350
#define KW_NONSPACE 351
#define SQLONLY 352
#define WIDGET 353
#define CONFIG 354
#define KW_NL 355
#define COMPARISON 356
#define KWOR 357
#define KWAND 358
#define KWWHERE 359
#define KWNOT 360
#define KWBETWEEN 361
#define KWIN 362
#define XVAL 363
#define KWNULLCHK 364
#define KWNOTNULLCHK 365
#define YEAR 366
#define MONTH 367
#define DAY 368
#define HOUR 369
#define MINUTE 370
#define SECOND 371
#define FRACTION 372
#define LISTBOX 373
#define BUTTON 374
#define KW_PANEL 375
#define KW_WS 376
#define KW_TAB 377
#define KW_MASTER_OF 378
#define KW_BEFORE 379
#define KW_AFTER 380
#define KW_EDITADD 381
#define KW_EDITUPDATE 382
#define KW_REMOVE 383
#define KW_OF 384
#define KW_ADD 385
#define KW_DISPLAY 386
#define KW_UPDATE 387
#define KW_QUERY 388
#define KW_ON_ENDING 389
#define KW_ON_BEGINNING 390
#define KW_CALL 391
#define KW_BELL 392
#define KW_ABORT 393
#define KW_LET 394
#define KW_EXITNOW 395
#define KW_REVERSE 396
#define KW_NEXTFIELD 397
#define KW_IF 398
#define KW_THEN 399
#define KW_ELSE 400




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
int ltab=0;
int replicate_bug=0;

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
#line 73 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 448 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 460 "y.tab.c"

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
#define YYLAST   1934

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  146
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  114
/* YYNRULES -- Number of rules. */
#define YYNRULES  380
/* YYNRULES -- Number of states. */
#define YYNSTATES  559

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   400

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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145
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
     106,   109,   110,   115,   117,   118,   123,   124,   128,   130,
     133,   137,   140,   141,   144,   146,   150,   154,   160,   164,
     168,   170,   173,   174,   179,   181,   184,   185,   186,   193,
     194,   198,   204,   208,   210,   211,   217,   221,   224,   229,
     233,   235,   236,   239,   241,   245,   247,   252,   256,   260,
     264,   270,   274,   280,   282,   284,   288,   294,   298,   302,
     304,   309,   311,   313,   315,   319,   323,   325,   327,   329,
     331,   334,   337,   339,   341,   343,   345,   348,   350,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   372,
     373,   374,   379,   381,   384,   386,   389,   392,   393,   403,
     416,   418,   420,   422,   423,   426,   427,   429,   430,   432,
     434,   439,   441,   445,   446,   448,   450,   454,   458,   462,
     466,   468,   472,   474,   475,   477,   479,   482,   484,   486,
     488,   489,   494,   496,   498,   500,   502,   504,   506,   509,
     512,   515,   518,   520,   522,   524,   526,   528,   530,   534,
     536,   539,   542,   544,   546,   550,   552,   554,   558,   562,
     564,   565,   569,   575,   576,   580,   581,   585,   587,   590,
     592,   594,   596,   598,   600,   602,   605,   607,   608,   612,
     614,   616,   618,   620,   622,   624,   626,   628,   631,   632,
     636,   637,   639,   642,   644,   648,   652,   656,   660,   665,
     669,   672,   675,   677,   683,   689,   692,   696,   698,   700,
     702,   704,   706,   708,   712,   721,   723,   727,   731,   733,
     735,   741,   747,   750,   753,   755,   757,   759,   761,   763,
     769,   770,   773,   775,   780,   783,   786,   789,   793,   797,
     799,   801,   803,   805,   807,   809,   811,   813,   815,   817,
     819,   823,   827,   829,   834,   839,   840,   842,   844,   848,
     850,   852,   854,   856,   858,   860,   862,   864,   866,   868,
     870,   872,   874,   876,   878,   880,   882,   884,   886,   888,
     890,   892,   894,   896,   898,   900,   902,   904,   906,   908,
     910,   912,   914,   916,   918,   920,   922,   924,   926,   928,
     930,   932,   934,   936,   938,   940,   942,   944,   946,   948,
     950,   952,   954,   956,   958,   960,   962,   964,   966,   968,
     970,   972,   974,   976,   978,   980,   982,   984,   986,   988,
     990,   992,   994,   996,   998,  1000,  1002,  1004,  1006,  1008,
    1010
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     147,     0,    -1,   148,   151,   169,   174,   192,    -1,    10,
      23,    -1,    10,   150,    29,    30,    31,    -1,    10,    23,
      29,    30,    31,    -1,    10,   150,    -1,    19,    -1,   259,
      -1,   149,    -1,   149,    27,   149,    -1,   152,    -1,   151,
     152,    -1,    -1,    13,   153,   155,    -1,    -1,    12,    35,
     154,   155,    -1,    -1,    -1,    -1,   159,   156,    20,   157,
     161,    21,   158,   160,    -1,    -1,    14,    18,    -1,    14,
      18,    11,    18,    -1,    -1,    16,    -1,   163,    -1,   161,
     163,    -1,   149,    -1,   162,    -1,   165,    -1,   122,    -1,
       4,    -1,    33,    -1,    35,    -1,   164,    -1,   121,    -1,
     100,    -1,    96,    -1,     3,    -1,   164,     3,    -1,    -1,
      15,   166,   167,    17,    -1,   211,    -1,    -1,   167,    33,
     168,   211,    -1,    -1,    32,   170,   160,    -1,   171,    -1,
     170,   171,    -1,   170,    43,   171,    -1,   149,   172,    -1,
      -1,    34,   173,    -1,   149,    -1,   149,    26,   149,    -1,
     149,    27,   149,    -1,   149,    27,   149,    26,   149,    -1,
     149,    28,   149,    -1,     9,   175,   160,    -1,   176,    -1,
     175,   176,    -1,    -1,   210,   177,   178,    36,    -1,   179,
      -1,   178,   179,    -1,    -1,    -1,    34,   180,   185,   182,
     181,   186,    -1,    -1,    15,    18,    17,    -1,    15,    18,
      43,    18,    17,    -1,   184,   105,    30,    -1,   184,    -1,
      -1,    45,    57,   149,    28,   149,    -1,    45,    57,   149,
      -1,    45,   213,    -1,    23,    28,   206,   183,    -1,   149,
      28,   149,    -1,   149,    -1,    -1,    43,   187,    -1,   188,
      -1,   187,    43,   188,    -1,    70,    -1,    71,    34,   190,
     229,    -1,    72,    34,    35,    -1,    73,    34,   189,    -1,
      75,    57,   149,    -1,    75,    57,   149,    28,   149,    -1,
      74,    57,   149,    -1,    74,    57,   149,    28,   149,    -1,
      76,    -1,    77,    -1,    78,    34,    35,    -1,    79,    34,
      37,   214,    38,    -1,    98,    34,    35,    -1,    99,    34,
      35,    -1,    80,    -1,    25,    14,    34,    18,    -1,    25,
      -1,    97,    -1,    81,    -1,    82,    34,    35,    -1,    83,
      34,    35,    -1,    84,    -1,    66,    -1,    85,    -1,    86,
      -1,    86,    87,    -1,    86,    88,    -1,    35,    -1,    18,
      -1,    95,    -1,   191,    -1,   190,   191,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
      69,    -1,    -1,    -1,     8,   193,   194,   160,    -1,   195,
      -1,   194,   195,    -1,   196,    -1,   196,    36,    -1,    46,
      35,    -1,    -1,    13,    42,   197,   201,    37,   202,    38,
     198,   200,    -1,   120,    37,    18,    43,    18,    38,    89,
      37,    18,    43,    18,    38,    -1,   236,    -1,   253,    -1,
     241,    -1,    -1,    90,   118,    -1,    -1,    39,    -1,    -1,
      36,    -1,   149,    -1,   149,    15,    18,    17,    -1,   205,
      -1,   202,   203,   205,    -1,    -1,    43,    -1,   149,    -1,
     149,    28,   149,    -1,    23,    28,   149,    -1,   149,    28,
      39,    -1,    23,    28,    39,    -1,   204,    -1,   204,    44,
     204,    -1,   149,    -1,    -1,   208,    -1,   209,    -1,   208,
     209,    -1,   121,    -1,   122,    -1,   149,    -1,    -1,   207,
     149,   212,   207,    -1,    47,    -1,    48,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,   217,    -1,    54,
     217,    -1,    55,   224,    -1,    56,   218,    -1,    91,    -1,
      92,    -1,    93,    -1,    94,    -1,   119,    -1,   216,    -1,
     214,    43,   216,    -1,    18,    -1,    40,    18,    -1,    41,
      18,    -1,    35,    -1,    19,    -1,    19,    89,    19,    -1,
       3,    -1,   215,    -1,   215,    89,   215,    -1,    35,    89,
      35,    -1,    30,    -1,    -1,    37,    18,    38,    -1,    37,
      18,    43,    18,    38,    -1,    -1,   221,    89,   223,    -1,
      -1,    37,    18,    38,    -1,    18,    -1,   222,   219,    -1,
     111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,
     116,    -1,   117,   228,    -1,   222,    -1,    -1,   225,    89,
     226,    -1,   227,    -1,   227,    -1,   111,    -1,   112,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   117,   228,
      -1,    -1,    37,   220,    38,    -1,    -1,   230,    -1,   104,
     231,    -1,   232,    -1,   232,   103,   232,    -1,   232,   102,
     232,    -1,   233,   101,   233,    -1,   233,    57,   233,    -1,
     233,   105,    57,   233,    -1,   233,    34,   233,    -1,   233,
     109,    -1,   233,   110,    -1,   233,    -1,   233,   106,   233,
     103,   233,    -1,   233,   107,    37,   235,    38,    -1,   105,
     232,    -1,    37,   232,    38,    -1,   234,    -1,    18,    -1,
      35,    -1,   108,    -1,    19,    -1,   233,    -1,   235,    43,
     233,    -1,     5,     6,   237,     7,   199,     6,   237,     7,
      -1,   238,    -1,   237,    43,   238,    -1,   239,    28,   240,
      -1,   149,    -1,   149,    -1,   124,   249,   129,   251,   242,
      -1,   125,   250,   129,   251,   242,    -1,   135,   254,    -1,
     134,   254,    -1,   245,    -1,   248,    -1,   243,    -1,   246,
      -1,   247,    -1,   143,   258,   144,   242,   244,    -1,    -1,
     145,   242,    -1,   138,    -1,   139,   176,    34,   258,    -1,
     142,   176,    -1,   142,   140,    -1,    72,    35,    -1,    72,
     137,    35,    -1,    72,   141,    35,    -1,   126,    -1,   127,
      -1,   128,    -1,   126,    -1,   130,    -1,   132,    -1,   133,
      -1,   128,    -1,   131,    -1,   127,    -1,   252,    -1,   251,
      43,   252,    -1,   239,    28,   240,    -1,   240,    -1,   239,
     123,   239,   200,    -1,   136,    37,   255,    38,    -1,    -1,
     256,    -1,   257,    -1,   256,    43,   257,    -1,   258,    -1,
     231,    -1,    90,    -1,    70,    -1,    58,    -1,    68,    -1,
      59,    -1,   102,    -1,   103,    -1,   101,    -1,   119,    -1,
      11,    -1,    71,    -1,    24,    -1,    72,    -1,    87,    -1,
      99,    -1,    61,    -1,    10,    -1,    55,    -1,    73,    -1,
      46,    -1,    76,    -1,    25,    -1,    78,    -1,    60,    -1,
      79,    -1,    31,    -1,    56,    -1,    80,    -1,    92,    -1,
      47,    -1,    49,    -1,    53,    -1,    50,    -1,    48,    -1,
      30,    -1,   120,    -1,    13,    -1,    12,    -1,    14,    -1,
      93,    -1,    67,    -1,   118,    -1,    63,    -1,    54,    -1,
      81,    -1,    88,    -1,   105,    -1,    82,    -1,    83,    -1,
      42,    -1,    62,    -1,    84,    -1,    66,    -1,    91,    -1,
      51,    -1,    52,    -1,    97,    -1,    95,    -1,    32,    -1,
      44,    -1,    22,    -1,    89,    -1,    69,    -1,    77,    -1,
      94,    -1,    85,    -1,    64,    -1,    98,    -1,    29,    -1,
      86,    -1,    65,    -1,    45,    -1,    57,    -1,   111,    -1,
     112,    -1,   113,    -1,   114,    -1,   115,    -1,   116,    -1,
     117,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   109,   109,   112,   113,   118,   119,   127,   128,   132,
     132,   135,   135,   138,   138,   151,   151,   171,   173,   176,
     170,   183,   184,   185,   197,   198,   203,   204,   207,   222,
     230,   231,   242,   252,   263,   271,   281,   286,   289,   297,
     298,   304,   303,   325,   328,   328,   346,   347,   350,   351,
     352,   355,   362,   363,   366,   367,   368,   370,   371,   377,
     381,   381,   385,   385,   394,   394,   397,   401,   397,   425,
     426,   430,   438,   439,   442,   443,   446,   449,   454,   463,
     471,   480,   481,   485,   485,   488,   489,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   524,   525,   526,   527,   528,   529,   532,   535,   538,
     541,   545,   551,   552,   553,   555,   555,   561,   564,   567,
     570,   573,   576,   579,   582,   585,   588,   591,   594,   598,
     599,   599,   604,   604,   606,   606,   609,   619,   619,   622,
     623,   624,   625,   629,   629,   631,   631,   633,   633,   636,
     639,   655,   658,   662,   663,   667,   669,   671,   673,   675,
     680,   680,   684,   690,   690,   693,   693,   697,   698,   711,
     719,   719,   728,   732,   736,   740,   744,   748,   752,   756,
     760,   764,   768,   772,   776,   780,   783,   790,   790,   795,
     795,   795,   800,   801,   802,   803,   804,   805,   808,   812,
     818,   819,   820,   823,   824,   831,   833,   838,   846,   849,
     850,   851,   852,   853,   854,   855,   861,   863,   864,   867,
     870,   874,   875,   876,   877,   878,   879,   880,   886,   888,
     895,   895,   901,   907,   908,   911,   917,   920,   923,   926,
     929,   934,   939,   943,   949,   952,   955,   960,   967,   970,
     971,   976,   979,   983,   995,   998,   999,  1002,  1005,  1007,
    1010,  1011,  1012,  1013,  1018,  1019,  1020,  1021,  1022,  1026,
    1028,  1028,  1031,  1033,  1035,  1036,  1040,  1041,  1042,  1049,
    1050,  1051,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1064,
    1065,  1069,  1070,  1074,  1077,  1080,  1080,  1084,  1084,  1087,
    1091,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,
    1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1174
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "GRAPH_CH", "KW_COMPOSITES", 
  "KW_LESS_THAN", "KW_GREATER_THAN", "INSTRUCTIONS", "ATTRIBUTES", 
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
  "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR", "KW_NONSPACE", 
  "SQLONLY", "WIDGET", "CONFIG", "KW_NL", "COMPARISON", "KWOR", "KWAND", 
  "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", 
  "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", 
  "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "KW_WS", "KW_TAB", 
  "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", "KW_EDITADD", "KW_EDITUPDATE", 
  "KW_REMOVE", "KW_OF", "KW_ADD", "KW_DISPLAY", "KW_UPDATE", "KW_QUERY", 
  "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL", "KW_BELL", "KW_ABORT", 
  "KW_LET", "KW_EXITNOW", "KW_REVERSE", "KW_NEXTFIELD", "KW_IF", 
  "KW_THEN", "KW_ELSE", "$accept", "form_def", "database_section", 
  "named_or_kw", "dbname", "screen_section", "screens_section", "@1", 
  "@2", "screens_rest", "@3", "@4", "@5", "op_size", "op_end", 
  "screen_layout", "some_text", "screen_element", "ch_list", "field", 
  "@6", "field_element", "@7", "op_table_section", "table_def_list", 
  "table_def", "opequal", "table_qualifier", "attribute_section", 
  "field_tag_list", "field_tag", "@8", "fpart_list", "fpart", "@9", "@10", 
  "op_att", "field_datatype_null", "field_datatype", "field_type", 
  "op_field_desc", "op_desc_list", "desc", "def_val", "colors", "color", 
  "op_instruction_section", "@11", "instruct_opts", "instruct_op_1", 
  "instruct_op", "@12", "op_ltype", "op_star", "op_semi", "srec_dim", 
  "srec_field_list", "op_comma", "field_list_item", "field_list_element", 
  "field_name", "op_ws", "ws", "ws_elem", "field_tag_name", 
  "field_tag_name_scr", "@13", "datatype", "incl_list", "number_value", 
  "incl_entry", "opt_dec_ext", "opt_int_ext", "opt_unit_size", "dtfrac", 
  "int_start", "int_start_unit", "int_end", "opt_dt_ext", "dt_start", 
  "dt_end", "dtime_val", "opt_frac", "op_where", "where_clause", 
  "clauses", "clause", "value", "fieldidentifier", "value_list", 
  "composites", "comp_list", "comp_item", "table_name", "column_name", 
  "control_block", "action", "if", "op_else", "abort", "let", "nextfield", 
  "comments", "bef_act", "aft_act", "column_list", "column_entry", 
  "master_of", "func_call", "op_func_call_args", "func_call_args", 
  "func_call_arg", "expression", "any_kword", 0
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   146,   147,   148,   148,   148,   148,   149,   149,   150,
     150,   151,   151,   153,   152,   154,   152,   156,   157,   158,
     155,   159,   159,   159,   160,   160,   161,   161,   162,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   164,
     164,   166,   165,   167,   168,   167,   169,   169,   170,   170,
     170,   171,   172,   172,   173,   173,   173,   173,   173,   174,
     175,   175,   177,   176,   178,   178,   180,   181,   179,   182,
     182,   182,   183,   183,   184,   184,   184,   184,   185,   185,
     185,   186,   186,   187,   187,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   189,   189,   189,   190,   190,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   192,
     193,   192,   194,   194,   195,   195,   196,   197,   196,   196,
     196,   196,   196,   198,   198,   199,   199,   200,   200,   201,
     201,   202,   202,   203,   203,   204,   204,   204,   204,   204,
     205,   205,   206,   207,   207,   208,   208,   209,   209,   210,
     212,   211,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   214,   214,   215,
     215,   215,   216,   216,   216,   216,   216,   216,   216,   216,
     217,   217,   217,   218,   218,   219,   219,   220,   221,   222,
     222,   222,   222,   222,   222,   222,   223,   224,   224,   225,
     226,   227,   227,   227,   227,   227,   227,   227,   228,   228,
     229,   229,   230,   231,   231,   231,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   233,   233,   233,
     233,   234,   235,   235,   236,   237,   237,   238,   239,   240,
     241,   241,   241,   241,   242,   242,   242,   242,   242,   243,
     244,   244,   245,   246,   247,   247,   248,   248,   248,   249,
     249,   249,   250,   250,   250,   250,   250,   250,   250,   251,
     251,   252,   252,   253,   254,   255,   255,   256,   256,   257,
     258,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     2,     0,     3,     0,     4,     0,     0,     0,
       8,     0,     2,     4,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     4,     1,     0,     4,     0,     3,     1,     2,
       3,     2,     0,     2,     1,     3,     3,     5,     3,     3,
       1,     2,     0,     4,     1,     2,     0,     0,     6,     0,
       3,     5,     3,     1,     0,     5,     3,     2,     4,     3,
       1,     0,     2,     1,     3,     1,     4,     3,     3,     3,
       5,     3,     5,     1,     1,     3,     5,     3,     3,     1,
       4,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     4,     1,     2,     1,     2,     2,     0,     9,    12,
       1,     1,     1,     0,     2,     0,     1,     0,     1,     1,
       4,     1,     3,     0,     1,     1,     3,     3,     3,     3,
       1,     3,     1,     0,     1,     1,     2,     1,     1,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     2,     1,     1,     3,     1,     1,     3,     3,     1,
       0,     3,     5,     0,     3,     0,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     3,
       0,     1,     2,     1,     3,     3,     3,     3,     4,     3,
       2,     2,     1,     5,     5,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     8,     1,     3,     3,     1,     1,
       5,     5,     2,     2,     1,     1,     1,     1,     1,     5,
       0,     2,     1,     4,     2,     2,     2,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     4,     4,     0,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   317,   310,   338,   337,   339,     7,
     361,     3,   312,   322,   369,   335,   326,   359,   350,   360,
     372,   320,   330,   334,   331,   333,   355,   356,   332,   344,
     318,   327,   373,   303,   305,   324,   316,   351,   343,   367,
     371,   353,   341,   304,   363,   302,   311,   313,   319,   321,
     364,   323,   325,   328,   345,   348,   349,   352,   366,   370,
     314,   346,   362,   301,   354,   329,   340,   365,   358,   357,
     368,   315,   308,   306,   307,   347,   374,   375,   376,   377,
     378,   379,   380,   342,   309,   336,     9,     6,     8,     1,
       0,    13,    46,    11,     0,     0,     0,    15,    21,     0,
      12,     0,     0,    10,     0,    21,     0,    14,    17,    52,
      24,    48,     0,   129,     5,     4,    16,    22,     0,     0,
      51,    25,     0,    47,    49,   169,    24,    60,    62,   130,
       2,     0,    18,    54,    53,    50,    59,    61,     0,     0,
      23,     0,     0,     0,     0,    66,     0,    64,     0,   337,
     320,   336,     0,     0,     0,     0,   258,    24,   132,   134,
     140,     0,   142,   141,    39,    32,    41,    33,    34,    38,
      37,    36,    31,    28,     0,    29,    26,    35,    30,    55,
      56,    58,     0,    63,    65,     0,   137,   136,     0,   279,
     280,   281,     0,   282,   288,   286,   283,   287,   284,   285,
       0,     0,   263,   262,   131,   133,   135,     0,   163,    19,
      27,    40,     0,     0,    80,    69,     0,   255,     0,     0,
       0,     0,     0,   295,   147,   167,   168,     0,     0,   164,
     165,    43,    24,    57,     0,     0,     0,    67,   145,     0,
       0,   149,     0,     0,   259,     0,   292,     0,   289,     0,
     248,   251,   249,     0,     0,   250,   300,   233,   242,   247,
       0,   296,   297,   299,   148,   293,    42,    44,   170,   166,
      20,   162,    74,    79,     0,    81,   146,     0,   256,   259,
     257,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       0,   260,   266,   264,   267,   268,   265,   261,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     294,     0,   163,   163,     0,    78,    73,    70,     0,     0,
      68,     0,     0,     0,   155,   153,   160,   151,     0,   291,
     290,   276,     0,     0,     0,   275,   274,     0,   246,   235,
     234,   239,   237,   236,     0,     0,     0,   298,    45,   171,
     172,   173,   174,   175,   176,   177,   200,   200,   217,   203,
       0,   182,   183,   184,   185,   186,    77,     0,     0,   101,
     107,    85,     0,     0,     0,     0,     0,    93,    94,     0,
       0,    99,   103,     0,     0,   106,   108,   109,   102,     0,
       0,    82,    83,     0,   150,     0,     0,   143,   154,     0,
       0,     0,   277,   278,     0,     0,   238,     0,   252,     0,
       0,   178,   179,   221,   222,   223,   224,   225,   226,   228,
     180,     0,   219,   209,   210,   211,   212,   213,   214,   228,
     181,     0,   205,    76,    72,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,     0,     0,
       0,   254,   159,   157,   158,   156,     0,   147,   152,   161,
       0,   273,   270,   243,   244,     0,     0,     0,   227,     0,
     215,     0,     0,   208,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   230,   115,
      87,   113,   112,   114,    88,    91,    89,    95,     0,   104,
     105,    97,    98,    84,   144,   138,     0,     0,   269,   253,
     201,     0,   207,     0,   218,   220,   216,   204,     0,    75,
     100,     0,   116,    86,   231,     0,     0,   195,   189,   193,
     199,   192,     0,     0,     0,   196,   187,     0,   271,     0,
     229,   206,   232,    92,    90,     0,     0,   190,   191,    96,
       0,     0,     0,   202,   194,   198,   188,   197,   139
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   156,    87,    92,    93,    98,   105,   107,
     118,   141,   232,   108,   123,   174,   175,   176,   177,   178,
     208,   227,   312,   101,   110,   111,   120,   134,   113,   126,
     127,   138,   146,   147,   182,   275,   237,   315,   316,   215,
     320,   391,   392,   494,   488,   489,   130,   139,   157,   158,
     159,   219,   457,   277,   265,   242,   325,   399,   326,   327,
     272,   228,   229,   230,   128,   231,   313,   366,   534,   535,
     536,   411,   430,   473,   513,   431,   432,   517,   420,   421,
     514,   422,   468,   523,   524,   256,   257,   258,   259,   409,
     160,   216,   217,   218,   246,   162,   291,   292,   508,   293,
     294,   295,   296,   192,   200,   247,   248,   163,   202,   260,
     261,   262,   263,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -301
static const short yypact[] =
{
      17,  1148,    48,    91,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,    22,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,    31,    41,  -301,  -301,
      27,  -301,    29,  -301,    46,  1814,    49,  -301,    72,  1814,
    -301,    88,    69,  -301,    77,    72,    92,  -301,  -301,    83,
    1037,  -301,  1814,   158,  -301,  -301,  -301,   163,   155,  1814,
    -301,  -301,  1814,  -301,  -301,  -301,  1259,  -301,  -301,  -301,
    -301,   159,  -301,   128,  -301,  -301,  -301,  -301,   142,   567,
    -301,   924,  1814,  1814,  1814,  -301,     0,  -301,   172,   137,
     145,   157,    43,   -59,    60,    60,  -301,   450,  -301,   161,
    -301,    75,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,   804,  -301,  -301,   196,  -301,  -301,
     174,  -301,  1370,  -301,  -301,  1814,  -301,  -301,   183,  -301,
    -301,  -301,    73,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
      74,   167,  -301,  -301,  -301,  -301,  -301,  1814,    -8,  -301,
    -301,  -301,  1814,   177,   178,   192,    14,  -301,   180,  1814,
     166,  1814,  1814,    -6,   176,  -301,  -301,     6,  1814,    -8,
    -301,  -301,   194,  -301,  1814,  1814,   195,  -301,   175,  1814,
    1814,   200,   179,   199,   191,   197,  -301,   -19,  -301,   -19,
    -301,  -301,  -301,    -6,    -6,  -301,  -301,    36,   -14,  -301,
     184,   181,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,   185,  -301,     9,   186,  -301,   217,  -301,  -301,
    -301,   208,  1481,   190,  1814,  1814,   -25,  -301,  1814,   684,
      -6,  -301,  -301,  -301,  -301,  -301,  -301,  -301,   193,  -301,
      -6,    -6,    -3,    -3,    -3,   201,    -3,   198,  -301,  -301,
    -301,    -6,    -8,    -8,   223,  -301,   127,  -301,   219,   170,
    -301,  1814,   221,   229,   232,     7,   218,  -301,   202,  -301,
    -301,  -301,   226,   228,   230,  -301,  -301,   121,  -301,  -301,
    -301,  -301,  -301,  -301,    -3,   182,    -3,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,   245,   245,    33,    47,
    1814,  -301,  -301,  -301,  -301,  -301,  -301,   236,   269,   275,
    -301,  -301,   256,   258,   259,   237,   238,  -301,  -301,   262,
     263,  -301,  -301,   264,   265,  -301,  -301,    64,  -301,   266,
     267,   260,  -301,    23,  -301,  1592,  1703,   212,  -301,  1481,
    1481,   268,  -301,  -301,    -6,   -58,  -301,    -3,  -301,    39,
     286,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,   270,
    -301,   220,  -301,  -301,  -301,  -301,  -301,  -301,  -301,   270,
    -301,   222,   271,   278,  -301,  -301,   276,   124,   277,    -7,
    1814,  1814,   283,   282,   285,   287,  -301,  -301,   288,   289,
     170,  -301,  -301,  -301,  -301,  -301,   203,   176,  -301,  -301,
     295,  -301,   187,  -301,  -301,    -3,    40,   307,  -301,    33,
    -301,    47,   308,  -301,  1814,   309,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,    68,  -301,
    -301,  -301,  -301,  -301,  -301,   300,   301,  -301,    19,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,   290,   -58,  -301,  -301,
    -301,   312,  -301,   293,  -301,  -301,  -301,  -301,   296,  -301,
    -301,    -6,  -301,  -301,  -301,  1814,  1814,  -301,  -301,   246,
    -301,   247,   319,   320,    63,   250,  -301,   322,  -301,   303,
    -301,  -301,  -301,  -301,  -301,   324,   310,  -301,  -301,  -301,
      19,    15,   306,  -301,  -301,  -301,  -301,  -301,  -301
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -301,  -301,  -301,    -1,  -301,  -301,   254,  -301,  -301,   242,
    -301,  -301,  -301,  -301,  -117,  -301,  -301,   188,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,   -75,  -301,  -301,  -301,  -301,
    -121,  -301,  -301,   204,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -102,  -301,  -301,  -139,  -301,  -301,  -301,   206,
    -301,  -301,  -301,  -301,  -106,  -301,  -301,  -301,   -48,   -46,
    -301,    42,  -301,   125,  -301,    44,  -301,  -301,  -301,  -194,
    -192,     3,  -301,  -301,  -301,  -301,  -110,  -301,  -301,  -301,
    -301,  -105,   -64,  -301,  -301,  -155,  -236,  -300,  -301,  -301,
    -301,    50,   129,  -132,  -221,  -301,  -248,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,   147,    82,  -301,   215,  -301,
    -301,    61,  -282,  -301
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -259
static const short yytable[] =
{
      86,   297,   341,   342,   343,   137,   345,   161,   337,   136,
     331,   491,   250,   251,   286,   250,   251,   298,   299,   280,
     302,   238,   527,   266,   285,   161,   317,     1,   492,   252,
     451,   253,   252,   528,   145,   124,   183,   528,   529,   267,
     204,    90,    91,   303,   406,   397,   408,   135,    89,   530,
     398,    94,   318,   286,   531,   532,   533,   239,    95,   532,
     533,    99,    97,   329,   339,   340,   239,   193,   194,   195,
      96,   196,   197,   198,   199,   224,   102,   464,   510,   104,
     287,   288,   465,   511,   289,   290,   106,   304,   493,   245,
     245,   305,   306,   307,   103,   308,   309,   112,   109,   254,
     114,   549,   255,    90,    91,   255,   550,   463,   115,   109,
     117,   125,   332,   225,   226,   270,   333,   119,   133,   287,
     288,   109,   461,   289,   290,   125,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   300,   301,
     173,   179,   180,   181,   413,   414,   415,   416,   417,   418,
     419,   446,   447,   245,   142,   143,   144,   462,   423,   424,
     425,   426,   427,   428,   429,   509,   129,   334,   336,   189,
     190,   191,   521,   173,   131,   132,   145,   140,   185,   186,
     187,   214,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   188,   369,   201,   206,   207,   211,
     212,   220,   221,   222,   223,   234,   235,   236,   240,   243,
     121,   233,   264,   274,   276,   281,   282,   283,   241,  -258,
     244,   244,   310,   321,   311,   284,   322,   268,   328,   319,
     314,   338,   367,   271,   273,   346,   370,   368,   394,   279,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   395,   344,   538,
     396,   402,   400,   403,   404,   405,   434,   388,   389,   390,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   324,   410,   279,   244,   407,   435,   125,   125,   436,
     437,   401,   438,   439,   440,   441,   442,   443,   444,   445,
     448,   449,   456,   450,   466,   460,   474,   467,   472,   469,
     475,   471,   490,   506,   361,   362,   363,   364,   497,   498,
     499,   504,   500,   501,   502,   512,   518,   520,   525,   526,
     539,   540,   507,   537,   541,   545,   546,   547,   548,   551,
     552,   553,   365,   554,   558,   555,   100,   116,   503,   522,
     184,   505,   459,   458,   269,   349,   348,   557,   556,   433,
     412,   516,   210,   205,   515,   470,   542,   330,   278,   249,
     203,   393,   347,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   453,   455,     0,     0,   324,   324,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       4,     5,     6,   149,     8,     0,   121,     0,     0,     9,
       0,     0,    10,   519,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    19,    20,   150,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   543,   544,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
       0,    72,    73,    74,     0,    75,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     151,     0,   148,     0,   152,   153,     0,     4,     5,     6,
     149,     8,     0,     0,   154,   155,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,   150,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,     0,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   151,     0,     0,
       0,   152,   153,     0,     4,     5,     6,     7,     8,     0,
       0,   154,   155,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     0,     0,   164,   165,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,   166,
       0,     0,     0,     9,   335,   209,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,   167,     0,   168,
       0,     0,     0,     0,     0,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     169,    69,    70,    71,   170,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   171,   172,   164,   165,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,   166,
       0,     0,     0,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,   167,     0,   168,
       0,     0,     0,     0,     0,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     169,    69,    70,    71,   170,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   171,   172,     4,     5,     6,
       7,     8,     0,   121,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
     122,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,     0,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,    11,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     4,
       5,     6,     7,     8,     0,   121,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,     0,
      72,    73,    74,     0,    75,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,    10,   213,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
       0,    72,    73,    74,     0,    75,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    10,   323,    12,    13,     0,     0,     0,
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
       0,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,   452,     0,     0,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,   454,     0,     0,    18,     0,    19,    20,    21,
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
       0,     0,     0,     0,     0,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85
};

static const short yycheck[] =
{
       1,   249,   302,   303,   304,   126,   306,   139,   290,   126,
      35,    18,    18,    19,    72,    18,    19,   253,   254,   240,
      34,     7,     3,    17,    43,   157,    17,    10,    35,    35,
       7,    37,    35,    18,    34,   110,    36,    18,    19,    33,
     157,    12,    13,    57,   344,    38,   346,   122,     0,    30,
      43,    29,    43,    72,    35,    40,    41,    43,    27,    40,
      41,    32,    35,   284,   300,   301,    43,   126,   127,   128,
      29,   130,   131,   132,   133,   207,    30,    38,    38,    30,
     138,   139,    43,    43,   142,   143,    14,   101,    95,   221,
     222,   105,   106,   107,    95,   109,   110,     9,    99,   105,
      31,    38,   108,    12,    13,   108,    43,   407,    31,   110,
      18,   112,   137,   121,   122,   232,   141,    34,   119,   138,
     139,   122,   404,   142,   143,   126,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   102,   103,
     141,   142,   143,   144,   111,   112,   113,   114,   115,   116,
     117,    87,    88,   285,    26,    27,    28,   405,   111,   112,
     113,   114,   115,   116,   117,   465,     8,   288,   289,   126,
     127,   128,   104,   174,    11,    20,    34,    18,     6,    42,
      35,   182,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    37,    25,   136,    36,   123,     3,
      26,    18,   129,   129,    37,    28,    28,    15,    28,    43,
      16,   212,    36,    18,    39,    15,    37,    18,   219,    28,
     221,   222,    38,     6,    43,    28,    18,   228,    38,    43,
      45,    38,   105,   234,   235,    37,    66,    18,    17,   240,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    28,    57,   507,
      28,    35,    44,    35,    34,   144,    30,    97,    98,    99,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   282,    37,   284,   285,   103,    17,   288,   289,    14,
      34,    89,    34,    34,    57,    57,    34,    34,    34,    34,
      34,    34,    90,    43,    18,    37,    28,    37,    37,    89,
      34,    89,    35,    18,    91,    92,    93,    94,    35,    37,
      35,   118,    35,    35,    35,    18,    18,    18,    28,    28,
      18,    38,   145,    43,    38,    89,    89,    18,    18,    89,
      18,    38,   119,    19,    38,    35,    92,   105,   450,   488,
     146,   457,   400,   399,   229,   313,   312,   551,   550,   360,
     357,   471,   174,   157,   469,   429,   521,   285,   239,   222,
     155,   321,   311,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   395,   396,    -1,    -1,   399,   400,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   440,
     441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    19,
      -1,    -1,    22,   474,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,   525,   526,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,     5,    -1,   124,   125,    -1,    10,    11,    12,
      13,    14,    -1,    -1,   134,   135,    19,    -1,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,   125,    -1,    10,    11,    12,    13,    14,    -1,
      -1,   134,   135,    19,    -1,    -1,    22,    -1,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,   140,    21,    22,    -1,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     3,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    10,    11,    12,
      13,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    97,    98,    99,    -1,   101,   102,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    19,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    -1,    97,    98,    99,    -1,   101,
     102,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    19,    -1,
      -1,    22,    -1,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    97,    98,    99,    -1,
     101,   102,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    -1,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    97,    98,
      99,    -1,   101,   102,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    22,    -1,    24,    25,    -1,    -1,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    97,
      98,    99,    -1,   101,   102,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    22,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    -1,
      97,    98,    99,    -1,   101,   102,   103,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    10,   147,   148,    10,    11,    12,    13,    14,    19,
      22,    23,    24,    25,    29,    30,    31,    32,    42,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    97,
      98,    99,   101,   102,   103,   105,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   149,   150,   259,     0,
      12,    13,   151,   152,    29,    27,    29,    35,   153,    32,
     152,   169,    30,   149,    30,   154,    14,   155,   159,   149,
     170,   171,     9,   174,    31,    31,   155,    18,   156,    34,
     172,    16,    43,   160,   171,   149,   175,   176,   210,     8,
     192,    11,    20,   149,   173,   171,   160,   176,   177,   193,
      18,   157,    26,    27,    28,    34,   178,   179,     5,    13,
      46,   120,   124,   125,   134,   135,   149,   194,   195,   196,
     236,   239,   241,   253,     3,     4,    15,    33,    35,    96,
     100,   121,   122,   149,   161,   162,   163,   164,   165,   149,
     149,   149,   180,    36,   179,     6,    42,    35,    37,   126,
     127,   128,   249,   126,   127,   128,   130,   131,   132,   133,
     250,   136,   254,   254,   160,   195,    36,   123,   166,    21,
     163,     3,    26,    23,   149,   185,   237,   238,   239,   197,
      18,   129,   129,    37,   239,   121,   122,   167,   207,   208,
     209,   211,   158,   149,    28,    28,    15,   182,     7,    43,
      28,   149,   201,    43,   149,   239,   240,   251,   252,   251,
      18,    19,    35,    37,   105,   108,   231,   232,   233,   234,
     255,   256,   257,   258,    36,   200,    17,    33,   149,   209,
     160,   149,   206,   149,    18,   181,    39,   199,   238,   149,
     240,    15,    37,    18,    28,    43,    72,   138,   139,   142,
     143,   242,   243,   245,   246,   247,   248,   242,   232,   232,
     102,   103,    34,    57,   101,   105,   106,   107,   109,   110,
      38,    43,   168,   212,    45,   183,   184,    17,    43,    43,
     186,     6,    18,    23,   149,   202,   204,   205,    38,   240,
     252,    35,   137,   141,   176,   140,   176,   258,    38,   232,
     232,   233,   233,   233,    57,   233,    37,   257,   211,   207,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    91,    92,    93,    94,   119,   213,   105,    18,    25,
      66,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    97,    98,
      99,   187,   188,   237,    17,    28,    28,    38,    43,   203,
      44,    89,    35,    35,    34,   144,   233,   103,   233,   235,
      37,   217,   217,   111,   112,   113,   114,   115,   116,   117,
     224,   225,   227,   111,   112,   113,   114,   115,   116,   117,
     218,   221,   222,   149,    30,    17,    14,    34,    34,    34,
      57,    57,    34,    34,    34,    34,    87,    88,    34,    34,
      43,     7,    39,   149,    39,   149,    90,   198,   205,   204,
      37,   258,   242,   233,    38,    43,    18,    37,   228,    89,
     228,    89,    37,   219,    28,    34,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   190,   191,
      35,    18,    35,    95,   189,   149,   149,    35,    37,    35,
      35,    35,    35,   188,   118,   200,    18,   145,   244,   233,
      38,    43,    18,   220,   226,   227,   222,   223,    18,   149,
      18,   104,   191,   229,   230,    28,    28,     3,    18,    19,
      30,    35,    40,    41,   214,   215,   216,    43,   242,    18,
      38,    38,   231,   149,   149,    89,    89,    18,    18,    38,
      43,    89,    18,    38,    19,    35,   216,   215,    38
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
#line 109 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 112 "screen.yacc"
    {the_form.dbname=strdup("formonly");}
    break;

  case 4:
#line 113 "screen.yacc"
    {the_form.dbname=(yyvsp[-3].str);
if (A4GLF_open_db(yyvsp[-3].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 118 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 119 "screen.yacc"
    {the_form.dbname=strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 10:
#line 132 "screen.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 13:
#line 138 "screen.yacc"
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
#line 151 "screen.yacc"
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
#line 171 "screen.yacc"
    { 
		lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 18:
#line 173 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 19:
#line 176 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 185 "screen.yacc"
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
#line 207 "screen.yacc"
    {
	int a;
	static char buff[256];
	strcpy(buff,yyvsp[0].str);
	if (!A4GL_isyes(acl_getenv("NORMSCORE"))) {
		for (a=0;a<strlen(buff);a++) {
			if (buff[a]=='_') buff[a]=' ';
		}
	}
	strcpy(yyval.str,buff);
}
    break;

  case 29:
#line 222 "screen.yacc"
    {
        //printf("%s %d %d %d %d %d %s\n","_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
        A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
}
    break;

  case 30:
#line 230 "screen.yacc"
    { ltab=0; }
    break;

  case 31:
#line 231 "screen.yacc"
    {
	if (colno==0&&replicate_bug) {colno=4; ltab=1;}
	else {
		if (colno==4&&replicate_bug) {colno=16;}
		else {
			colno++;
			while ((colno%8)!=0) {colno++;}
		}
		ltab=0;
	}
}
    break;

  case 32:
#line 242 "screen.yacc"
    {
	char buff[256];
	sprintf(buff,"\n%s",yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
}
    break;

  case 33:
#line 252 "screen.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
}
    break;

  case 34:
#line 263 "screen.yacc"
    {
	     A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
}
    break;

  case 35:
#line 271 "screen.yacc"
    {
	//char buff[256];
	//printf("str1=%s colno=%d\n",$<str>1,colno+1);
	A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	//printf("colno was %d for '%s'\n",colno,$<str>1);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
}
    break;

  case 36:
#line 281 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 37:
#line 286 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 38:
#line 289 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 39:
#line 297 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 40:
#line 298 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 41:
#line 304 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 42:
#line 311 "screen.yacc"
    {
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 43:
#line 325 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 44:
#line 328 "screen.yacc"
    {
				/* field elements = name x y width screen_no endswith'|' */
				colno++;
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

  case 45:
#line 339 "screen.yacc"
    {
				strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 51:
#line 355 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 52:
#line 362 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 53:
#line 363 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 54:
#line 366 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 55:
#line 367 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 56:
#line 369 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 57:
#line 370 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 58:
#line 371 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 62:
#line 385 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 66:
#line 397 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 67:
#line 401 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 68:
#line 411 "screen.yacc"
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

  case 70:
#line 426 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 71:
#line 430 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 72:
#line 438 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 73:
#line 439 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 74:
#line 442 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 75:
#line 443 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 76:
#line 446 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 77:
#line 449 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 78:
#line 454 "screen.yacc"
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

  case 79:
#line 463 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 80:
#line 471 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 85:
#line 488 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 86:
#line 489 "screen.yacc"
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

  case 87:
#line 509 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 88:
#line 510 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 89:
#line 511 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 90:
#line 512 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 91:
#line 513 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 92:
#line 514 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 93:
#line 515 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 94:
#line 516 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 95:
#line 517 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 96:
#line 518 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 97:
#line 519 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 98:
#line 520 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 99:
#line 521 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 100:
#line 522 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 101:
#line 524 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 102:
#line 525 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 103:
#line 526 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 104:
#line 527 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 105:
#line 528 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 106:
#line 529 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 107:
#line 532 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 108:
#line 535 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_VERIFY);
}
    break;

  case 109:
#line 538 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 110:
#line 541 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 111:
#line 545 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 114:
#line 553 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 116:
#line 555 "screen.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str));
}
    break;

  case 117:
#line 561 "screen.yacc"
    {
	strcpy(yyval.str,"0");
}
    break;

  case 118:
#line 564 "screen.yacc"
    {
	strcpy(yyval.str,"4");
}
    break;

  case 119:
#line 567 "screen.yacc"
    {
	strcpy(yyval.str,"2");
}
    break;

  case 120:
#line 570 "screen.yacc"
    {
	strcpy(yyval.str,"6"); 
}
    break;

  case 121:
#line 573 "screen.yacc"
    {
	strcpy(yyval.str,"1");
}
    break;

  case 122:
#line 576 "screen.yacc"
    {
	strcpy(yyval.str,"5"); 
}
    break;

  case 123:
#line 579 "screen.yacc"
    {
	strcpy(yyval.str,"7");
}
    break;

  case 124:
#line 582 "screen.yacc"
    {
	strcpy(yyval.str,"3");
}
    break;

  case 125:
#line 585 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE"));
}
    break;

  case 126:
#line 588 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT"));
}
    break;

  case 127:
#line 591 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK"));
}
    break;

  case 128:
#line 594 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE"));
}
    break;

  case 130:
#line 599 "screen.yacc"
    {
}
    break;

  case 136:
#line 609 "screen.yacc"
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

  case 137:
#line 619 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 149:
#line 636 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 150:
#line 639 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 151:
#line 655 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 152:
#line 658 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 155:
#line 668 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 156:
#line 670 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 157:
#line 672 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 158:
#line 674 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 159:
#line 676 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 161:
#line 680 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 162:
#line 684 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 163:
#line 690 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 164:
#line 690 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 167:
#line 697 "screen.yacc"
    {colno++;}
    break;

  case 168:
#line 698 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 169:
#line 711 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 170:
#line 719 "screen.yacc"
    {
	colno+=strlen(yyvsp[0].str);
}
    break;

  case 171:
#line 721 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-2].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 172:
#line 728 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 173:
#line 732 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 174:
#line 736 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 175:
#line 740 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 176:
#line 744 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 177:
#line 748 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 178:
#line 752 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 179:
#line 756 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 180:
#line 760 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 181:
#line 764 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 182:
#line 768 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 183:
#line 772 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 184:
#line 776 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 185:
#line 780 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 186:
#line 783 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 188:
#line 790 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 191:
#line 795 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 192:
#line 800 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 193:
#line 801 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 194:
#line 802 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 195:
#line 803 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 197:
#line 805 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 198:
#line 808 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 199:
#line 812 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 200:
#line 818 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 201:
#line 819 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 202:
#line 820 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 203:
#line 823 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 204:
#line 825 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 205:
#line 831 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 206:
#line 833 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 207:
#line 838 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 208:
#line 846 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 209:
#line 849 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 210:
#line 850 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 211:
#line 851 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 212:
#line 852 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 213:
#line 853 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 214:
#line 854 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 215:
#line 856 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 217:
#line 863 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 218:
#line 864 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 219:
#line 867 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 220:
#line 870 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 221:
#line 874 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 222:
#line 875 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 223:
#line 876 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 224:
#line 877 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 225:
#line 878 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 226:
#line 879 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 227:
#line 881 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 228:
#line 886 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 229:
#line 888 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 230:
#line 895 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 231:
#line 895 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 232:
#line 901 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 234:
#line 908 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 235:
#line 911 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 236:
#line 917 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 237:
#line 920 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 238:
#line 923 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE");
		}
    break;

  case 239:
#line 926 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
	}
    break;

  case 240:
#line 929 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL");
	}
    break;

  case 241:
#line 934 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNOTNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL");
	}
    break;

  case 242:
#line 939 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
			//create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
    break;

  case 243:
#line 943 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[-2].expr);
		add_list_expr(yyval.expr,yyvsp[0].expr);
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN");
	}
    break;

  case 244:
#line 949 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN");
	}
    break;

  case 245:
#line 952 "screen.yacc"
    {
		yyval.expr=create_not_expr(yyvsp[0].expr);
	}
    break;

  case 246:
#line 955 "screen.yacc"
    {
		yyval.expr=yyvsp[-1].expr;
	}
    break;

  case 247:
#line 960 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 248:
#line 967 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str));
printf("NUMBER VALUE : %s\n",yyvsp[0].str);
}
    break;

  case 249:
#line 970 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 250:
#line 971 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 252:
#line 979 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 253:
#line 983 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3594 "y.tab.c"

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


#line 108 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */





