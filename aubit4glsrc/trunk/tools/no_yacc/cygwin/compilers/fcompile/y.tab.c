/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
     NOUPDATE = 336,
     NOENTRY = 337,
     PICTURE = 338,
     PROGRAM = 339,
     REQUIRED = 340,
     VERIFY = 341,
     WORDWRAP = 342,
     COMPRESS = 343,
     NONCOMPRESS = 344,
     TO = 345,
     AS = 346,
     SERIAL = 347,
     KW_BYTE = 348,
     KW_TEXT = 349,
     VARCHAR = 350,
     SQL_VAR = 351,
     KW_NONSPACE = 352,
     SQLONLY = 353,
     WIDGET = 354,
     CONFIG = 355,
     KW_NL = 356,
     COMPARISON = 357,
     KWOR = 358,
     KWAND = 359,
     KWWHERE = 360,
     KWNOT = 361,
     KWBETWEEN = 362,
     KWIN = 363,
     XVAL = 364,
     KWNULLCHK = 365,
     KWNOTNULLCHK = 366,
     YEAR = 367,
     MONTH = 368,
     DAY = 369,
     HOUR = 370,
     MINUTE = 371,
     SECOND = 372,
     FRACTION = 373,
     LISTBOX = 374,
     BUTTON = 375,
     KW_PANEL = 376,
     KW_WS = 377,
     KW_TAB = 378,
     KW_MASTER_OF = 379,
     KW_BEFORE = 380,
     KW_AFTER = 381,
     KW_EDITADD = 382,
     KW_EDITUPDATE = 383,
     KW_REMOVE = 384,
     KW_OF = 385,
     KW_ADD = 386,
     KW_DISPLAY = 387,
     KW_UPDATE = 388,
     KW_QUERY = 389,
     KW_ON_ENDING = 390,
     KW_ON_BEGINNING = 391,
     KW_CALL = 392,
     KW_BELL = 393,
     KW_ABORT = 394,
     KW_LET = 395,
     KW_EXITNOW = 396,
     KW_REVERSE = 397,
     KW_NEXTFIELD = 398,
     KW_IF = 399,
     KW_THEN = 400,
     KW_ELSE = 401
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
#define NOUPDATE 336
#define NOENTRY 337
#define PICTURE 338
#define PROGRAM 339
#define REQUIRED 340
#define VERIFY 341
#define WORDWRAP 342
#define COMPRESS 343
#define NONCOMPRESS 344
#define TO 345
#define AS 346
#define SERIAL 347
#define KW_BYTE 348
#define KW_TEXT 349
#define VARCHAR 350
#define SQL_VAR 351
#define KW_NONSPACE 352
#define SQLONLY 353
#define WIDGET 354
#define CONFIG 355
#define KW_NL 356
#define COMPARISON 357
#define KWOR 358
#define KWAND 359
#define KWWHERE 360
#define KWNOT 361
#define KWBETWEEN 362
#define KWIN 363
#define XVAL 364
#define KWNULLCHK 365
#define KWNOTNULLCHK 366
#define YEAR 367
#define MONTH 368
#define DAY 369
#define HOUR 370
#define MINUTE 371
#define SECOND 372
#define FRACTION 373
#define LISTBOX 374
#define BUTTON 375
#define KW_PANEL 376
#define KW_WS 377
#define KW_TAB 378
#define KW_MASTER_OF 379
#define KW_BEFORE 380
#define KW_AFTER 381
#define KW_EDITADD 382
#define KW_EDITUPDATE 383
#define KW_REMOVE 384
#define KW_OF 385
#define KW_ADD 386
#define KW_DISPLAY 387
#define KW_UPDATE 388
#define KW_QUERY 389
#define KW_ON_ENDING 390
#define KW_ON_BEGINNING 391
#define KW_CALL 392
#define KW_BELL 393
#define KW_ABORT 394
#define KW_LET 395
#define KW_EXITNOW 396
#define KW_REVERSE 397
#define KW_NEXTFIELD 398
#define KW_IF 399
#define KW_THEN 400
#define KW_ELSE 401




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
#line 451 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 463 "y.tab.c"

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
#define YYLAST   1948

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  114
/* YYNRULES -- Number of rules. */
#define YYNRULES  381
/* YYNRULES -- Number of states. */
#define YYNSTATES  560

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   401

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
     145,   146
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
     304,   309,   311,   313,   315,   317,   321,   325,   327,   329,
     331,   333,   336,   339,   341,   343,   345,   347,   350,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   375,   376,   381,   383,   386,   388,   391,   394,   395,
     405,   418,   420,   422,   424,   425,   428,   429,   431,   432,
     434,   436,   441,   443,   447,   448,   450,   452,   456,   460,
     464,   468,   470,   474,   476,   477,   479,   481,   484,   486,
     488,   490,   491,   496,   498,   500,   502,   504,   506,   508,
     511,   514,   517,   520,   522,   524,   526,   528,   530,   532,
     536,   538,   541,   544,   546,   548,   552,   554,   556,   560,
     564,   566,   567,   571,   577,   578,   582,   583,   587,   589,
     592,   594,   596,   598,   600,   602,   604,   607,   609,   610,
     614,   616,   618,   620,   622,   624,   626,   628,   630,   633,
     634,   638,   639,   641,   644,   646,   650,   654,   658,   662,
     667,   671,   674,   677,   679,   685,   691,   694,   698,   700,
     702,   704,   706,   708,   710,   714,   723,   725,   729,   733,
     735,   737,   743,   749,   752,   755,   757,   759,   761,   763,
     765,   771,   772,   775,   777,   782,   785,   788,   791,   795,
     799,   801,   803,   805,   807,   809,   811,   813,   815,   817,
     819,   821,   825,   829,   831,   836,   841,   842,   844,   846,
     850,   852,   854,   856,   858,   860,   862,   864,   866,   868,
     870,   872,   874,   876,   878,   880,   882,   884,   886,   888,
     890,   892,   894,   896,   898,   900,   902,   904,   906,   908,
     910,   912,   914,   916,   918,   920,   922,   924,   926,   928,
     930,   932,   934,   936,   938,   940,   942,   944,   946,   948,
     950,   952,   954,   956,   958,   960,   962,   964,   966,   968,
     970,   972,   974,   976,   978,   980,   982,   984,   986,   988,
     990,   992,   994,   996,   998,  1000,  1002,  1004,  1006,  1008,
    1010,  1012
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     148,     0,    -1,   149,   152,   170,   175,   193,    -1,    10,
      23,    -1,    10,   151,    29,    30,    31,    -1,    10,    23,
      29,    30,    31,    -1,    10,   151,    -1,    19,    -1,   260,
      -1,   150,    -1,   150,    27,   150,    -1,   153,    -1,   152,
     153,    -1,    -1,    13,   154,   156,    -1,    -1,    12,    35,
     155,   156,    -1,    -1,    -1,    -1,   160,   157,    20,   158,
     162,    21,   159,   161,    -1,    -1,    14,    18,    -1,    14,
      18,    11,    18,    -1,    -1,    16,    -1,   164,    -1,   162,
     164,    -1,   150,    -1,   163,    -1,   166,    -1,   123,    -1,
       4,    -1,    33,    -1,    35,    -1,   165,    -1,   122,    -1,
     101,    -1,    97,    -1,     3,    -1,   165,     3,    -1,    -1,
      15,   167,   168,    17,    -1,   212,    -1,    -1,   168,    33,
     169,   212,    -1,    -1,    32,   171,   161,    -1,   172,    -1,
     171,   172,    -1,   171,    43,   172,    -1,   150,   173,    -1,
      -1,    34,   174,    -1,   150,    -1,   150,    26,   150,    -1,
     150,    27,   150,    -1,   150,    27,   150,    26,   150,    -1,
     150,    28,   150,    -1,     9,   176,   161,    -1,   177,    -1,
     176,   177,    -1,    -1,   211,   178,   179,    36,    -1,   180,
      -1,   179,   180,    -1,    -1,    -1,    34,   181,   186,   183,
     182,   187,    -1,    -1,    15,    18,    17,    -1,    15,    18,
      43,    18,    17,    -1,   185,   106,    30,    -1,   185,    -1,
      -1,    45,    57,   150,    28,   150,    -1,    45,    57,   150,
      -1,    45,   214,    -1,    23,    28,   207,   184,    -1,   150,
      28,   150,    -1,   150,    -1,    -1,    43,   188,    -1,   189,
      -1,   188,    43,   189,    -1,    70,    -1,    71,    34,   191,
     230,    -1,    72,    34,    35,    -1,    73,    34,   190,    -1,
      75,    57,   150,    -1,    75,    57,   150,    28,   150,    -1,
      74,    57,   150,    -1,    74,    57,   150,    28,   150,    -1,
      76,    -1,    77,    -1,    78,    34,    35,    -1,    79,    34,
      37,   215,    38,    -1,    99,    34,    35,    -1,   100,    34,
      35,    -1,    80,    -1,    25,    14,    34,    18,    -1,    25,
      -1,    98,    -1,    82,    -1,    81,    -1,    83,    34,    35,
      -1,    84,    34,    35,    -1,    85,    -1,    66,    -1,    86,
      -1,    87,    -1,    87,    88,    -1,    87,    89,    -1,    35,
      -1,    18,    -1,    96,    -1,   192,    -1,   191,   192,    -1,
      58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    -1,    -1,     8,   194,   195,   161,
      -1,   196,    -1,   195,   196,    -1,   197,    -1,   197,    36,
      -1,    46,    35,    -1,    -1,    13,    42,   198,   202,    37,
     203,    38,   199,   201,    -1,   121,    37,    18,    43,    18,
      38,    90,    37,    18,    43,    18,    38,    -1,   237,    -1,
     254,    -1,   242,    -1,    -1,    91,   119,    -1,    -1,    39,
      -1,    -1,    36,    -1,   150,    -1,   150,    15,    18,    17,
      -1,   206,    -1,   203,   204,   206,    -1,    -1,    43,    -1,
     150,    -1,   150,    28,   150,    -1,    23,    28,   150,    -1,
     150,    28,    39,    -1,    23,    28,    39,    -1,   205,    -1,
     205,    44,   205,    -1,   150,    -1,    -1,   209,    -1,   210,
      -1,   209,   210,    -1,   122,    -1,   123,    -1,   150,    -1,
      -1,   208,   150,   213,   208,    -1,    47,    -1,    48,    -1,
      49,    -1,    50,    -1,    51,    -1,    52,    -1,    53,   218,
      -1,    54,   218,    -1,    55,   225,    -1,    56,   219,    -1,
      92,    -1,    93,    -1,    94,    -1,    95,    -1,   120,    -1,
     217,    -1,   215,    43,   217,    -1,    18,    -1,    40,    18,
      -1,    41,    18,    -1,    35,    -1,    19,    -1,    19,    90,
      19,    -1,     3,    -1,   216,    -1,   216,    90,   216,    -1,
      35,    90,    35,    -1,    30,    -1,    -1,    37,    18,    38,
      -1,    37,    18,    43,    18,    38,    -1,    -1,   222,    90,
     224,    -1,    -1,    37,    18,    38,    -1,    18,    -1,   223,
     220,    -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,
     116,    -1,   117,    -1,   118,   229,    -1,   223,    -1,    -1,
     226,    90,   227,    -1,   228,    -1,   228,    -1,   112,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,
     118,   229,    -1,    -1,    37,   221,    38,    -1,    -1,   231,
      -1,   105,   232,    -1,   233,    -1,   233,   104,   233,    -1,
     233,   103,   233,    -1,   234,   102,   234,    -1,   234,    57,
     234,    -1,   234,   106,    57,   234,    -1,   234,    34,   234,
      -1,   234,   110,    -1,   234,   111,    -1,   234,    -1,   234,
     107,   234,   104,   234,    -1,   234,   108,    37,   236,    38,
      -1,   106,   233,    -1,    37,   233,    38,    -1,   235,    -1,
      18,    -1,    35,    -1,   109,    -1,    19,    -1,   234,    -1,
     236,    43,   234,    -1,     5,     6,   238,     7,   200,     6,
     238,     7,    -1,   239,    -1,   238,    43,   239,    -1,   240,
      28,   241,    -1,   150,    -1,   150,    -1,   125,   250,   130,
     252,   243,    -1,   126,   251,   130,   252,   243,    -1,   136,
     255,    -1,   135,   255,    -1,   246,    -1,   249,    -1,   244,
      -1,   247,    -1,   248,    -1,   144,   259,   145,   243,   245,
      -1,    -1,   146,   243,    -1,   139,    -1,   140,   177,    34,
     259,    -1,   143,   177,    -1,   143,   141,    -1,    72,    35,
      -1,    72,   138,    35,    -1,    72,   142,    35,    -1,   127,
      -1,   128,    -1,   129,    -1,   127,    -1,   131,    -1,   133,
      -1,   134,    -1,   129,    -1,   132,    -1,   128,    -1,   253,
      -1,   252,    43,   253,    -1,   240,    28,   241,    -1,   241,
      -1,   240,   124,   240,   201,    -1,   137,    37,   256,    38,
      -1,    -1,   257,    -1,   258,    -1,   257,    43,   258,    -1,
     259,    -1,   232,    -1,    91,    -1,    70,    -1,    58,    -1,
      68,    -1,    59,    -1,   103,    -1,   104,    -1,   102,    -1,
     120,    -1,    11,    -1,    71,    -1,    24,    -1,    72,    -1,
      88,    -1,   100,    -1,    61,    -1,    10,    -1,    55,    -1,
      73,    -1,    46,    -1,    76,    -1,    25,    -1,    78,    -1,
      60,    -1,    79,    -1,    31,    -1,    56,    -1,    80,    -1,
      93,    -1,    47,    -1,    49,    -1,    53,    -1,    50,    -1,
      48,    -1,    30,    -1,   121,    -1,    13,    -1,    12,    -1,
      14,    -1,    94,    -1,    67,    -1,   119,    -1,    63,    -1,
      54,    -1,    82,    -1,    89,    -1,   106,    -1,    83,    -1,
      84,    -1,    42,    -1,    62,    -1,    85,    -1,    66,    -1,
      92,    -1,    51,    -1,    52,    -1,    98,    -1,    96,    -1,
      32,    -1,    44,    -1,    22,    -1,    90,    -1,    69,    -1,
      77,    -1,    95,    -1,    86,    -1,    64,    -1,    99,    -1,
      29,    -1,    87,    -1,    65,    -1,    45,    -1,    57,    -1,
     112,    -1,   113,    -1,   114,    -1,   115,    -1,   116,    -1,
     117,    -1,   118,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   109,   109,   112,   113,   118,   119,   127,   128,   132,
     132,   135,   135,   138,   138,   151,   151,   171,   173,   176,
     170,   183,   184,   185,   197,   198,   203,   204,   207,   222,
     232,   233,   244,   256,   269,   279,   288,   293,   296,   304,
     305,   311,   310,   332,   335,   335,   353,   354,   357,   358,
     359,   362,   369,   370,   373,   374,   375,   377,   378,   384,
     388,   388,   392,   392,   401,   401,   404,   408,   404,   444,
     445,   449,   457,   458,   461,   462,   465,   468,   473,   482,
     490,   499,   500,   504,   504,   507,   508,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   543,   544,   545,   546,   547,   548,   549,   552,   555,
     558,   561,   565,   571,   572,   573,   575,   575,   581,   584,
     587,   590,   593,   596,   599,   602,   605,   608,   611,   614,
     618,   619,   619,   624,   624,   626,   626,   629,   639,   639,
     642,   643,   644,   645,   649,   649,   651,   651,   653,   653,
     656,   659,   675,   678,   682,   683,   687,   689,   691,   693,
     695,   700,   700,   704,   710,   710,   713,   713,   717,   718,
     731,   739,   739,   748,   752,   756,   760,   764,   768,   772,
     776,   780,   784,   788,   792,   796,   800,   803,   810,   810,
     815,   815,   815,   820,   821,   822,   823,   824,   825,   828,
     832,   838,   839,   840,   843,   844,   851,   853,   858,   866,
     869,   870,   871,   872,   873,   874,   875,   881,   883,   884,
     887,   890,   894,   895,   896,   897,   898,   899,   900,   906,
     908,   915,   915,   921,   927,   928,   931,   937,   940,   943,
     946,   949,   954,   959,   963,   969,   972,   975,   980,   987,
     990,   991,   996,   999,  1003,  1015,  1018,  1019,  1022,  1025,
    1027,  1030,  1031,  1032,  1033,  1038,  1039,  1040,  1041,  1042,
    1046,  1048,  1048,  1051,  1053,  1055,  1056,  1060,  1061,  1062,
    1069,  1070,  1071,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1084,  1085,  1089,  1090,  1094,  1097,  1100,  1100,  1104,  1104,
    1107,  1111,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1194
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
  "FORMAT", "INCLUDE", "INVISIBLE", "NOUPDATE", "NOENTRY", "PICTURE", 
  "PROGRAM", "REQUIRED", "VERIFY", "WORDWRAP", "COMPRESS", "NONCOMPRESS", 
  "TO", "AS", "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR", 
  "KW_NONSPACE", "SQLONLY", "WIDGET", "CONFIG", "KW_NL", "COMPARISON", 
  "KWOR", "KWAND", "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", 
  "KWNULLCHK", "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", 
  "SECOND", "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "KW_WS", 
  "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", "KW_EDITADD", 
  "KW_EDITUPDATE", "KW_REMOVE", "KW_OF", "KW_ADD", "KW_DISPLAY", 
  "KW_UPDATE", "KW_QUERY", "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL", 
  "KW_BELL", "KW_ABORT", "KW_LET", "KW_EXITNOW", "KW_REVERSE", 
  "KW_NEXTFIELD", "KW_IF", "KW_THEN", "KW_ELSE", "$accept", "form_def", 
  "database_section", "named_or_kw", "dbname", "screen_section", 
  "screens_section", "@1", "@2", "screens_rest", "@3", "@4", "@5", 
  "op_size", "op_end", "screen_layout", "some_text", "screen_element", 
  "ch_list", "field", "@6", "field_element", "@7", "op_table_section", 
  "table_def_list", "table_def", "opequal", "table_qualifier", 
  "attribute_section", "field_tag_list", "field_tag", "@8", "fpart_list", 
  "fpart", "@9", "@10", "op_att", "field_datatype_null", "field_datatype", 
  "field_type", "op_field_desc", "op_desc_list", "desc", "def_val", 
  "colors", "color", "op_instruction_section", "@11", "instruct_opts", 
  "instruct_op_1", "instruct_op", "@12", "op_ltype", "op_star", "op_semi", 
  "srec_dim", "srec_field_list", "op_comma", "field_list_item", 
  "field_list_element", "field_name", "op_ws", "ws", "ws_elem", 
  "field_tag_name", "field_tag_name_scr", "@13", "datatype", "incl_list", 
  "number_value", "incl_entry", "opt_dec_ext", "opt_int_ext", 
  "opt_unit_size", "dtfrac", "int_start", "int_start_unit", "int_end", 
  "opt_dt_ext", "dt_start", "dt_end", "dtime_val", "opt_frac", "op_where", 
  "where_clause", "clauses", "clause", "value", "fieldidentifier", 
  "value_list", "composites", "comp_list", "comp_item", "table_name", 
  "column_name", "control_block", "action", "if", "op_else", "abort", 
  "let", "nextfield", "comments", "bef_act", "aft_act", "column_list", 
  "column_entry", "master_of", "func_call", "op_func_call_args", 
  "func_call_args", "func_call_arg", "expression", "any_kword", 0
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
     395,   396,   397,   398,   399,   400,   401
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   147,   148,   149,   149,   149,   149,   150,   150,   151,
     151,   152,   152,   154,   153,   155,   153,   157,   158,   159,
     156,   160,   160,   160,   161,   161,   162,   162,   163,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   165,
     165,   167,   166,   168,   169,   168,   170,   170,   171,   171,
     171,   172,   173,   173,   174,   174,   174,   174,   174,   175,
     176,   176,   178,   177,   179,   179,   181,   182,   180,   183,
     183,   183,   184,   184,   185,   185,   185,   185,   186,   186,
     186,   187,   187,   188,   188,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   190,   190,   190,   191,   191,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     193,   194,   193,   195,   195,   196,   196,   197,   198,   197,
     197,   197,   197,   197,   199,   199,   200,   200,   201,   201,
     202,   202,   203,   203,   204,   204,   205,   205,   205,   205,
     205,   206,   206,   207,   208,   208,   209,   209,   210,   210,
     211,   213,   212,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   215,   215,
     216,   216,   216,   217,   217,   217,   217,   217,   217,   217,
     217,   218,   218,   218,   219,   219,   220,   220,   221,   222,
     223,   223,   223,   223,   223,   223,   223,   224,   225,   225,
     226,   227,   228,   228,   228,   228,   228,   228,   228,   229,
     229,   230,   230,   231,   232,   232,   232,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   234,
     234,   234,   235,   236,   236,   237,   238,   238,   239,   240,
     241,   242,   242,   242,   242,   243,   243,   243,   243,   243,
     244,   245,   245,   246,   247,   248,   248,   249,   249,   249,
     250,   250,   250,   251,   251,   251,   251,   251,   251,   251,
     252,   252,   253,   253,   254,   255,   256,   256,   257,   257,
     258,   259,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260
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
       4,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     4,     1,     2,     1,     2,     2,     0,     9,
      12,     1,     1,     1,     0,     2,     0,     1,     0,     1,
       1,     4,     1,     3,     0,     1,     1,     3,     3,     3,
       3,     1,     3,     1,     0,     1,     1,     2,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     1,     3,     1,     1,     3,     3,
       1,     0,     3,     5,     0,     3,     0,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     0,     1,     2,     1,     3,     3,     3,     3,     4,
       3,     2,     2,     1,     5,     5,     2,     3,     1,     1,
       1,     1,     1,     1,     3,     8,     1,     3,     3,     1,
       1,     5,     5,     2,     2,     1,     1,     1,     1,     1,
       5,     0,     2,     1,     4,     2,     2,     2,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     4,     4,     0,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   318,   311,   339,   338,   340,     7,
     362,     3,   313,   323,   370,   336,   327,   360,   351,   361,
     373,   321,   331,   335,   332,   334,   356,   357,   333,   345,
     319,   328,   374,   304,   306,   325,   317,   352,   344,   368,
     372,   354,   342,   305,   364,   303,   312,   314,   320,   322,
     365,   324,   326,   329,   346,   349,   350,   353,   367,   371,
     315,   347,   363,   302,   355,   330,   341,   366,   359,   358,
     369,   316,   309,   307,   308,   348,   375,   376,   377,   378,
     379,   380,   381,   343,   310,   337,     9,     6,     8,     1,
       0,    13,    46,    11,     0,     0,     0,    15,    21,     0,
      12,     0,     0,    10,     0,    21,     0,    14,    17,    52,
      24,    48,     0,   130,     5,     4,    16,    22,     0,     0,
      51,    25,     0,    47,    49,   170,    24,    60,    62,   131,
       2,     0,    18,    54,    53,    50,    59,    61,     0,     0,
      23,     0,     0,     0,     0,    66,     0,    64,     0,   338,
     321,   337,     0,     0,     0,     0,   259,    24,   133,   135,
     141,     0,   143,   142,    39,    32,    41,    33,    34,    38,
      37,    36,    31,    28,     0,    29,    26,    35,    30,    55,
      56,    58,     0,    63,    65,     0,   138,   137,     0,   280,
     281,   282,     0,   283,   289,   287,   284,   288,   285,   286,
       0,     0,   264,   263,   132,   134,   136,     0,   164,    19,
      27,    40,     0,     0,    80,    69,     0,   256,     0,     0,
       0,     0,     0,   296,   148,   168,   169,     0,     0,   165,
     166,    43,    24,    57,     0,     0,     0,    67,   146,     0,
       0,   150,     0,     0,   260,     0,   293,     0,   290,     0,
     249,   252,   250,     0,     0,   251,   301,   234,   243,   248,
       0,   297,   298,   300,   149,   294,    42,    44,   171,   167,
      20,   163,    74,    79,     0,    81,   147,     0,   257,   260,
     258,     0,     0,     0,     0,     0,     0,   273,     0,     0,
       0,   261,   267,   265,   268,   269,   266,   262,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   242,
     295,     0,   164,   164,     0,    78,    73,    70,     0,     0,
      68,     0,     0,     0,   156,   154,   161,   152,     0,   292,
     291,   277,     0,     0,     0,   276,   275,     0,   247,   236,
     235,   240,   238,   237,     0,     0,     0,   299,    45,   172,
     173,   174,   175,   176,   177,   178,   201,   201,   218,   204,
       0,   183,   184,   185,   186,   187,    77,     0,     0,   101,
     108,    85,     0,     0,     0,     0,     0,    93,    94,     0,
       0,    99,   104,   103,     0,     0,   107,   109,   110,   102,
       0,     0,    82,    83,     0,   151,     0,     0,   144,   155,
       0,     0,     0,   278,   279,     0,     0,   239,     0,   253,
       0,     0,   179,   180,   222,   223,   224,   225,   226,   227,
     229,   181,     0,   220,   210,   211,   212,   213,   214,   215,
     229,   182,     0,   206,    76,    72,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,     0,
       0,     0,   255,   160,   158,   159,   157,     0,   148,   153,
     162,     0,   274,   271,   244,   245,     0,     0,     0,   228,
       0,   216,     0,     0,   209,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   231,
     116,    87,   114,   113,   115,    88,    91,    89,    95,     0,
     105,   106,    97,    98,    84,   145,   139,     0,     0,   270,
     254,   202,     0,   208,     0,   219,   221,   217,   205,     0,
      75,   100,     0,   117,    86,   232,     0,     0,   196,   190,
     194,   200,   193,     0,     0,     0,   197,   188,     0,   272,
       0,   230,   207,   233,    92,    90,     0,     0,   191,   192,
      96,     0,     0,     0,   203,   195,   199,   189,   198,   140
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   156,    87,    92,    93,    98,   105,   107,
     118,   141,   232,   108,   123,   174,   175,   176,   177,   178,
     208,   227,   312,   101,   110,   111,   120,   134,   113,   126,
     127,   138,   146,   147,   182,   275,   237,   315,   316,   215,
     320,   392,   393,   495,   489,   490,   130,   139,   157,   158,
     159,   219,   458,   277,   265,   242,   325,   400,   326,   327,
     272,   228,   229,   230,   128,   231,   313,   366,   535,   536,
     537,   412,   431,   474,   514,   432,   433,   518,   421,   422,
     515,   423,   469,   524,   525,   256,   257,   258,   259,   410,
     160,   216,   217,   218,   246,   162,   291,   292,   509,   293,
     294,   295,   296,   192,   200,   247,   248,   163,   202,   260,
     261,   262,   263,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -301
static const short yypact[] =
{
      31,  1155,    66,    89,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,    20,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,    50,    51,  -301,  -301,
      58,  -301,    11,  -301,    65,  1827,    67,  -301,    85,  1827,
    -301,    98,    79,  -301,    84,    85,   104,  -301,  -301,    90,
    1043,  -301,  1827,   121,  -301,  -301,  -301,   124,   118,  1827,
    -301,  -301,  1827,  -301,  -301,  -301,  1267,  -301,  -301,  -301,
    -301,   133,  -301,    12,  -301,  -301,  -301,  -301,   120,   569,
    -301,   929,  1827,  1827,  1827,  -301,    42,  -301,   146,   113,
     122,   119,   -74,   -60,    33,    33,  -301,   451,  -301,   135,
    -301,    45,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,   808,  -301,  -301,   169,  -301,  -301,
     148,  -301,  1379,  -301,  -301,  1827,  -301,  -301,   157,  -301,
    -301,  -301,    46,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
      48,   140,  -301,  -301,  -301,  -301,  -301,  1827,   -18,  -301,
    -301,  -301,  1827,   151,   154,   168,    19,  -301,   174,  1827,
     160,  1827,  1827,    -6,   170,  -301,  -301,     4,  1827,   -18,
    -301,  -301,   188,  -301,  1827,  1827,   187,  -301,   171,  1827,
    1827,   192,   172,   190,   189,   191,  -301,   -13,  -301,   -13,
    -301,  -301,  -301,    -6,    -6,  -301,  -301,    16,    26,  -301,
     177,   173,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,   178,  -301,     5,   179,  -301,   218,  -301,  -301,
    -301,   207,  1491,   193,  1827,  1827,   -26,  -301,  1827,   687,
      -6,  -301,  -301,  -301,  -301,  -301,  -301,  -301,   194,  -301,
      -6,    -6,    -3,    -3,    -3,   180,    -3,   198,  -301,  -301,
    -301,    -6,   -18,   -18,   197,  -301,   123,  -301,   208,   114,
    -301,  1827,   211,   202,   210,    18,   196,  -301,   152,  -301,
    -301,  -301,   201,   206,   209,  -301,  -301,   110,  -301,  -301,
    -301,  -301,  -301,  -301,    -3,   153,    -3,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,   219,   219,    32,    47,
    1827,  -301,  -301,  -301,  -301,  -301,  -301,   228,   242,   259,
    -301,  -301,   240,   241,   243,   221,   222,  -301,  -301,   246,
     248,  -301,  -301,  -301,   251,   252,  -301,  -301,    25,  -301,
     271,   272,   233,  -301,    27,  -301,  1603,  1715,   216,  -301,
    1491,  1491,   273,  -301,  -301,    -6,   -58,  -301,    -3,  -301,
      41,   291,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
     274,  -301,   223,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
     274,  -301,   224,   275,   287,  -301,  -301,   282,   235,   283,
      -8,  1827,  1827,   284,   285,   286,   288,  -301,  -301,   289,
     290,   114,  -301,  -301,  -301,  -301,  -301,   212,   170,  -301,
    -301,   302,  -301,   181,  -301,  -301,    -3,    49,   308,  -301,
      32,  -301,    47,   310,  -301,  1827,   311,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,   203,
    -301,  -301,  -301,  -301,  -301,  -301,   304,   305,  -301,    17,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,   292,   -58,  -301,
    -301,  -301,   312,  -301,   296,  -301,  -301,  -301,  -301,   298,
    -301,  -301,    -6,  -301,  -301,  -301,  1827,  1827,  -301,  -301,
     247,  -301,   249,   320,   322,    53,   253,  -301,   323,  -301,
     306,  -301,  -301,  -301,  -301,  -301,   326,   307,  -301,  -301,
    -301,    17,    10,   309,  -301,  -301,  -301,  -301,  -301,  -301
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -301,  -301,  -301,    -1,  -301,  -301,   254,  -301,  -301,   244,
    -301,  -301,  -301,  -301,  -115,  -301,  -301,   176,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,   -77,  -301,  -301,  -301,  -301,
    -121,  -301,  -301,   205,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -103,  -301,  -301,  -137,  -301,  -301,  -301,   199,
    -301,  -301,  -301,  -301,  -105,  -301,  -301,  -301,   -47,   -45,
    -301,    44,  -301,   129,  -301,    52,  -301,  -301,  -301,  -192,
    -190,     6,  -301,  -301,  -301,  -301,  -110,  -301,  -301,  -301,
    -301,  -104,   -65,  -301,  -301,  -155,  -236,  -300,  -301,  -301,
    -301,    54,   130,  -132,  -221,  -301,  -248,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,   149,    83,  -301,   215,  -301,
    -301,    61,  -282,  -301
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -260
static const short yytable[] =
{
      86,   297,   341,   342,   343,   137,   345,   161,   337,   331,
     492,   136,   250,   251,   286,   250,   251,   298,   299,   280,
     528,   266,   317,    90,    91,   161,   238,   493,   529,   252,
     285,   253,   252,   124,   452,   529,   530,   267,   142,   143,
     144,     1,   204,    99,   407,   135,   409,   531,   318,    94,
     533,   534,   532,   189,   190,   191,   398,   533,   534,   286,
     302,   399,   239,   329,   339,   340,    89,   193,   194,   195,
     239,   196,   197,   198,   199,   224,   145,    95,   183,   465,
      96,   287,   288,   303,   466,   289,   290,   511,   494,   245,
     245,   550,   512,    97,   103,   102,   551,   104,   109,   106,
     254,    90,    91,   255,   225,   226,   255,   112,   464,   109,
     114,   125,   332,   447,   448,   115,   333,   270,   133,   300,
     301,   109,   117,   462,   119,   125,   287,   288,   304,   129,
     289,   290,   305,   306,   307,   131,   308,   309,   132,   369,
     173,   179,   180,   181,   414,   415,   416,   417,   418,   419,
     420,   140,   185,   245,   145,   186,   188,   187,   463,   424,
     425,   426,   427,   428,   429,   430,   510,   334,   336,   207,
     201,   206,   211,   173,   212,   220,   221,   223,   222,   234,
     370,   214,   235,   236,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   240,   243,   121,   274,   264,   281,   283,   282,
     276,   233,   389,   390,   391,   310,   311,  -259,   241,   284,
     244,   244,   319,   314,   321,   322,   368,   268,   395,   367,
     396,   328,   338,   271,   273,   346,   403,   344,   397,   279,
     401,   404,   402,   405,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   406,   411,   408,   435,   436,
     539,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   437,   438,   439,   451,   440,   441,   442,
     443,   324,   444,   279,   244,   445,   446,   125,   125,   361,
     362,   363,   364,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   449,   450,   457,   522,   467,
     461,   468,   473,   470,   472,   475,   476,   365,   491,   498,
     507,   500,   499,   501,   502,   503,   513,   508,   519,   521,
     540,   505,   526,   527,   541,   538,   542,   546,   548,   547,
     549,   553,   556,   552,   554,   555,   100,   559,   504,   116,
     210,   184,   523,   506,   460,   459,   205,   349,   269,   434,
     558,   557,   517,   413,   348,   471,   516,   543,   330,   278,
     203,   249,   347,     0,     0,   394,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   454,   456,     0,     0,   324,
     324,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,   497,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     4,     5,     6,   149,     8,     0,   121,     0,     0,
       9,     0,     0,    10,   520,    12,    13,     0,     0,     0,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,    19,    20,   150,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   544,   545,    49,    50,    51,
      52,    53,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   151,     0,   148,     0,   152,   153,     0,     4,
       5,     6,   149,     8,     0,     0,   154,   155,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    20,   150,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
       0,    72,    73,    74,     0,    75,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
     151,     0,     0,     0,   152,   153,     0,     4,     5,     6,
       7,     8,     0,     0,   154,   155,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,    51,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     0,
       0,   164,   165,     0,     0,     0,     0,     0,     4,     5,
       6,     7,     8,   166,     0,     0,     0,     9,   335,   209,
      10,     0,    12,    13,     0,     0,     0,    14,    15,    16,
      17,   167,     0,   168,     0,     0,     0,     0,     0,     0,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,     0,    49,    50,    51,    52,    53,     0,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   169,    69,    70,    71,   170,
      72,    73,    74,     0,    75,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
     171,   172,   164,   165,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,   166,     0,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,   167,     0,   168,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   169,    69,    70,    71,
     170,    72,    73,    74,     0,    75,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   171,   172,     4,     5,     6,     7,     8,     0,   121,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,   122,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,     0,    49,
      50,    51,    52,    53,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,    11,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,    49,    50,    51,    52,    53,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,     0,    72,    73,    74,
       0,    75,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     4,     5,     6,
       7,     8,     0,   121,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,    51,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,    10,   213,    12,    13,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
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
      52,    53,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,   453,     0,     0,    18,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,     0,    49,
      50,    51,    52,    53,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,   455,     0,     0,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,    49,    50,    51,    52,    53,     0,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,     0,    72,    73,    74,
       0,    75,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,    51,    52,    53,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85
};

static const short yycheck[] =
{
       1,   249,   302,   303,   304,   126,   306,   139,   290,    35,
      18,   126,    18,    19,    72,    18,    19,   253,   254,   240,
       3,    17,    17,    12,    13,   157,     7,    35,    18,    35,
      43,    37,    35,   110,     7,    18,    19,    33,    26,    27,
      28,    10,   157,    32,   344,   122,   346,    30,    43,    29,
      40,    41,    35,   127,   128,   129,    38,    40,    41,    72,
      34,    43,    43,   284,   300,   301,     0,   127,   128,   129,
      43,   131,   132,   133,   134,   207,    34,    27,    36,    38,
      29,   139,   140,    57,    43,   143,   144,    38,    96,   221,
     222,    38,    43,    35,    95,    30,    43,    30,    99,    14,
     106,    12,    13,   109,   122,   123,   109,     9,   408,   110,
      31,   112,   138,    88,    89,    31,   142,   232,   119,   103,
     104,   122,    18,   405,    34,   126,   139,   140,   102,     8,
     143,   144,   106,   107,   108,    11,   110,   111,    20,    25,
     141,   142,   143,   144,   112,   113,   114,   115,   116,   117,
     118,    18,     6,   285,    34,    42,    37,    35,   406,   112,
     113,   114,   115,   116,   117,   118,   466,   288,   289,   124,
     137,    36,     3,   174,    26,    18,   130,    37,   130,    28,
      66,   182,    28,    15,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    28,    43,    16,    18,    36,    15,    18,    37,
      39,   212,    98,    99,   100,    38,    43,    28,   219,    28,
     221,   222,    43,    45,     6,    18,    18,   228,    17,   106,
      28,    38,    38,   234,   235,    37,    35,    57,    28,   240,
      44,    35,    90,    34,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   145,    37,   104,    30,    17,
     508,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    14,    34,    34,    43,    34,    57,    57,
      34,   282,    34,   284,   285,    34,    34,   288,   289,    92,
      93,    94,    95,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    34,    34,    91,   105,    18,
      37,    37,    37,    90,    90,    28,    34,   120,    35,    35,
      18,    35,    37,    35,    35,    35,    18,   146,    18,    18,
      18,   119,    28,    28,    38,    43,    38,    90,    18,    90,
      18,    18,    35,    90,    38,    19,    92,    38,   451,   105,
     174,   146,   489,   458,   401,   400,   157,   313,   229,   360,
     552,   551,   472,   357,   312,   430,   470,   522,   285,   239,
     155,   222,   311,    -1,    -1,   321,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   396,   397,    -1,    -1,   400,
     401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     441,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      19,    -1,    -1,    22,   475,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   526,   527,    76,    77,    78,
      79,    80,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,    -1,   102,   103,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,     5,    -1,   125,   126,    -1,    10,
      11,    12,    13,    14,    -1,    -1,   135,   136,    19,    -1,
      -1,    22,    -1,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,   102,   103,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,   125,   126,    -1,    10,    11,    12,
      13,    14,    -1,    -1,   135,   136,    19,    -1,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,   102,
     103,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,   141,    21,
      22,    -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     3,     4,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    22,    -1,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    19,    -1,    -1,    22,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,   102,   103,   104,    -1,   106,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,   102,   103,   104,
      -1,   106,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    10,    11,    12,
      13,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,   102,
     103,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    10,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,   102,   103,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,    -1,   102,   103,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    22,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,   102,   103,   104,    -1,   106,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    22,    -1,    24,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,   102,   103,   104,
      -1,   106,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    19,    -1,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    -1,    98,    99,   100,    -1,   102,
     103,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    10,   148,   149,    10,    11,    12,    13,    14,    19,
      22,    23,    24,    25,    29,    30,    31,    32,    42,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    76,
      77,    78,    79,    80,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    98,
      99,   100,   102,   103,   104,   106,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   150,   151,   260,     0,
      12,    13,   152,   153,    29,    27,    29,    35,   154,    32,
     153,   170,    30,   150,    30,   155,    14,   156,   160,   150,
     171,   172,     9,   175,    31,    31,   156,    18,   157,    34,
     173,    16,    43,   161,   172,   150,   176,   177,   211,     8,
     193,    11,    20,   150,   174,   172,   161,   177,   178,   194,
      18,   158,    26,    27,    28,    34,   179,   180,     5,    13,
      46,   121,   125,   126,   135,   136,   150,   195,   196,   197,
     237,   240,   242,   254,     3,     4,    15,    33,    35,    97,
     101,   122,   123,   150,   162,   163,   164,   165,   166,   150,
     150,   150,   181,    36,   180,     6,    42,    35,    37,   127,
     128,   129,   250,   127,   128,   129,   131,   132,   133,   134,
     251,   137,   255,   255,   161,   196,    36,   124,   167,    21,
     164,     3,    26,    23,   150,   186,   238,   239,   240,   198,
      18,   130,   130,    37,   240,   122,   123,   168,   208,   209,
     210,   212,   159,   150,    28,    28,    15,   183,     7,    43,
      28,   150,   202,    43,   150,   240,   241,   252,   253,   252,
      18,    19,    35,    37,   106,   109,   232,   233,   234,   235,
     256,   257,   258,   259,    36,   201,    17,    33,   150,   210,
     161,   150,   207,   150,    18,   182,    39,   200,   239,   150,
     241,    15,    37,    18,    28,    43,    72,   139,   140,   143,
     144,   243,   244,   246,   247,   248,   249,   243,   233,   233,
     103,   104,    34,    57,   102,   106,   107,   108,   110,   111,
      38,    43,   169,   213,    45,   184,   185,    17,    43,    43,
     187,     6,    18,    23,   150,   203,   205,   206,    38,   241,
     253,    35,   138,   142,   177,   141,   177,   259,    38,   233,
     233,   234,   234,   234,    57,   234,    37,   258,   212,   208,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    92,    93,    94,    95,   120,   214,   106,    18,    25,
      66,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    98,
      99,   100,   188,   189,   238,    17,    28,    28,    38,    43,
     204,    44,    90,    35,    35,    34,   145,   234,   104,   234,
     236,    37,   218,   218,   112,   113,   114,   115,   116,   117,
     118,   225,   226,   228,   112,   113,   114,   115,   116,   117,
     118,   219,   222,   223,   150,    30,    17,    14,    34,    34,
      34,    57,    57,    34,    34,    34,    34,    88,    89,    34,
      34,    43,     7,    39,   150,    39,   150,    91,   199,   206,
     205,    37,   259,   243,   234,    38,    43,    18,    37,   229,
      90,   229,    90,    37,   220,    28,    34,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,   191,
     192,    35,    18,    35,    96,   190,   150,   150,    35,    37,
      35,    35,    35,    35,   189,   119,   201,    18,   146,   245,
     234,    38,    43,    18,   221,   227,   228,   223,   224,    18,
     150,    18,   105,   192,   230,   231,    28,    28,     3,    18,
      19,    30,    35,    40,    41,   215,   216,   217,    43,   243,
      18,    38,    38,   232,   150,   150,    90,    90,    18,    18,
      38,    43,    90,    18,    38,    19,    35,   217,   216,    38
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
	if (lineno) {
        A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 30:
#line 232 "screen.yacc"
    { ltab=0; }
    break;

  case 31:
#line 233 "screen.yacc"
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
#line 244 "screen.yacc"
    {
	char buff[256];
	if (lineno) {
	sprintf(buff,"\n%s",yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 33:
#line 256 "screen.yacc"
    {
	char buff[256];
	if (lineno) {
	strcpy(buff,yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 34:
#line 269 "screen.yacc"
    {
	if (lineno) {
	     A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 35:
#line 279 "screen.yacc"
    {
	if (lineno) {
	A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 36:
#line 288 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 37:
#line 293 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 38:
#line 296 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 39:
#line 304 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 40:
#line 305 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 41:
#line 311 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 42:
#line 318 "screen.yacc"
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
#line 332 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 44:
#line 335 "screen.yacc"
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
#line 346 "screen.yacc"
    {
				strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 51:
#line 362 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 52:
#line 369 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 53:
#line 370 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 54:
#line 373 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 55:
#line 374 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 56:
#line 376 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 57:
#line 377 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 58:
#line 378 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 62:
#line 392 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 66:
#line 404 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 67:
#line 408 "screen.yacc"
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
#line 418 "screen.yacc"
    {
	if (fld->datatype==90&&!(A4GL_has_str_attribute(fld,FA_S_DEFAULT)))
	{
	        extern FILE *yyin;

			A4GL_debug("Currpos = %ld\n",ftell(yyin));
	        yyerror("A button must have a default value for its caption");
	        YYERROR;
	}
	if (!(A4GL_has_str_attribute(fld,FA_S_PICTURE)) && strcmp(the_form.dbname,"formonly")!=0 ) {
		char *p;
	
		p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"PICTURE");
		if (p) {
			// Theres a picture in syscolval - but nothing in the form -
			// Use the syscolval one...
			A4GL_add_str_attr(fld,FA_S_PICTURE,p);
			printf("Setting field picture from syscolval (%s)\n",p);
		}
	}

	A4GL_set_field(currftag,fld);
}
    break;

  case 70:
#line 445 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 71:
#line 449 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 72:
#line 457 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 73:
#line 458 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 74:
#line 461 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 75:
#line 462 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 76:
#line 465 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 77:
#line 468 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 78:
#line 473 "screen.yacc"
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
#line 482 "screen.yacc"
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
#line 490 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 85:
#line 507 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 86:
#line 508 "screen.yacc"
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
#line 528 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 88:
#line 529 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 89:
#line 530 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 90:
#line 531 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 91:
#line 532 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 92:
#line 533 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 93:
#line 534 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 94:
#line 535 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 95:
#line 536 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 96:
#line 537 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 97:
#line 538 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 98:
#line 539 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 99:
#line 540 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 100:
#line 541 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 101:
#line 543 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 102:
#line 544 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 103:
#line 545 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 104:
#line 546 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 105:
#line 547 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 106:
#line 548 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 107:
#line 549 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 108:
#line 552 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 109:
#line 555 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_VERIFY);
}
    break;

  case 110:
#line 558 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 111:
#line 561 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 112:
#line 565 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 113:
#line 571 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 114:
#line 572 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 115:
#line 573 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 117:
#line 575 "screen.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str));
}
    break;

  case 118:
#line 581 "screen.yacc"
    {
	strcpy(yyval.str,"0");
}
    break;

  case 119:
#line 584 "screen.yacc"
    {
	strcpy(yyval.str,"4");
}
    break;

  case 120:
#line 587 "screen.yacc"
    {
	strcpy(yyval.str,"2");
}
    break;

  case 121:
#line 590 "screen.yacc"
    {
	strcpy(yyval.str,"6"); 
}
    break;

  case 122:
#line 593 "screen.yacc"
    {
	strcpy(yyval.str,"1");
}
    break;

  case 123:
#line 596 "screen.yacc"
    {
	strcpy(yyval.str,"5"); 
}
    break;

  case 124:
#line 599 "screen.yacc"
    {
	strcpy(yyval.str,"7");
}
    break;

  case 125:
#line 602 "screen.yacc"
    {
	strcpy(yyval.str,"3");
}
    break;

  case 126:
#line 605 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE"));
}
    break;

  case 127:
#line 608 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT"));
}
    break;

  case 128:
#line 611 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK"));
}
    break;

  case 129:
#line 614 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE"));
}
    break;

  case 131:
#line 619 "screen.yacc"
    {
}
    break;

  case 137:
#line 629 "screen.yacc"
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

  case 138:
#line 639 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 150:
#line 656 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 151:
#line 659 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 152:
#line 675 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 153:
#line 678 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 156:
#line 688 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 157:
#line 690 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 158:
#line 692 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 159:
#line 694 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 160:
#line 696 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 162:
#line 700 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 163:
#line 704 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 164:
#line 710 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 165:
#line 710 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 168:
#line 717 "screen.yacc"
    {colno++;}
    break;

  case 169:
#line 718 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 170:
#line 731 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 171:
#line 739 "screen.yacc"
    {
	colno+=strlen(yyvsp[0].str);
}
    break;

  case 172:
#line 741 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-2].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 173:
#line 748 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 174:
#line 752 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 175:
#line 756 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 176:
#line 760 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 177:
#line 764 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 178:
#line 768 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 179:
#line 772 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 180:
#line 776 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 181:
#line 780 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 182:
#line 784 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 183:
#line 788 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 184:
#line 792 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 185:
#line 796 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 186:
#line 800 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 187:
#line 803 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 189:
#line 810 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 192:
#line 815 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 193:
#line 820 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 194:
#line 821 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 195:
#line 822 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 196:
#line 823 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 198:
#line 825 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 199:
#line 828 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 200:
#line 832 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 201:
#line 838 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 202:
#line 839 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 203:
#line 840 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 204:
#line 843 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 205:
#line 845 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 206:
#line 851 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 207:
#line 853 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 208:
#line 858 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 209:
#line 866 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 210:
#line 869 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 211:
#line 870 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 212:
#line 871 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 213:
#line 872 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 214:
#line 873 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 215:
#line 874 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 216:
#line 876 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 218:
#line 883 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 219:
#line 884 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 220:
#line 887 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 221:
#line 890 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 222:
#line 894 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 223:
#line 895 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 224:
#line 896 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 225:
#line 897 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 226:
#line 898 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 227:
#line 899 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 228:
#line 901 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 229:
#line 906 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 230:
#line 908 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 231:
#line 915 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 232:
#line 915 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 233:
#line 921 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 235:
#line 928 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 236:
#line 931 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 237:
#line 937 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 238:
#line 940 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 239:
#line 943 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE");
		}
    break;

  case 240:
#line 946 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
	}
    break;

  case 241:
#line 949 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL");
	}
    break;

  case 242:
#line 954 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNOTNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL");
	}
    break;

  case 243:
#line 959 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
			//create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
    break;

  case 244:
#line 963 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[-2].expr);
		add_list_expr(yyval.expr,yyvsp[0].expr);
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN");
	}
    break;

  case 245:
#line 969 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN");
	}
    break;

  case 246:
#line 972 "screen.yacc"
    {
		yyval.expr=create_not_expr(yyvsp[0].expr);
	}
    break;

  case 247:
#line 975 "screen.yacc"
    {
		yyval.expr=yyvsp[-1].expr;
	}
    break;

  case 248:
#line 980 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 249:
#line 987 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str));
printf("NUMBER VALUE : %s\n",yyvsp[0].str);
}
    break;

  case 250:
#line 990 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 251:
#line 991 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 253:
#line 999 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 254:
#line 1003 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 999 of yacc.c.  */
#line 3634 "y.tab.c"

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
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
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


#line 1197 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */





