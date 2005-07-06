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
     INSTRUCTIONS = 261,
     ATTRIBUTES = 262,
     DATABASE = 263,
     BY = 264,
     KW_SCREEN_TITLE = 265,
     KW_SCREEN = 266,
     KW_SIZE = 267,
     OPEN_SQUARE = 268,
     KW_END = 269,
     CLOSE_SQUARE = 270,
     NUMBER_VALUE = 271,
     NAMED = 272,
     OPEN_BRACE = 273,
     CLOSE_BRACE = 274,
     TITLE = 275,
     FORMONLY = 276,
     COMMENT = 277,
     DYNAMIC = 278,
     COLON = 279,
     ATSIGN = 280,
     DOT = 281,
     WITHOUT = 282,
     KW_NULL = 283,
     INPUT = 284,
     TABLES = 285,
     PIPE = 286,
     EQUAL = 287,
     CHAR_VALUE = 288,
     SEMICOLON = 289,
     LOOKUP = 290,
     JOINING = 291,
     OPEN_BRACKET = 292,
     CLOSE_BRACKET = 293,
     STAR = 294,
     DIVIDE = 295,
     PLUS = 296,
     MINUS = 297,
     RECORD = 298,
     COMMA = 299,
     THROUGH = 300,
     TYPE = 301,
     DELIMITERS = 302,
     KW_CHAR = 303,
     KW_INT = 304,
     KW_DATE = 305,
     KW_FLOAT = 306,
     SMALLFLOAT = 307,
     SMALLINT = 308,
     KW_DECIMAL = 309,
     MONEY = 310,
     DATETIME = 311,
     INTERVAL = 312,
     LIKE = 313,
     BLACK = 314,
     BLUE = 315,
     GREEN = 316,
     CYAN = 317,
     RED = 318,
     MAGENTA = 319,
     WHITE = 320,
     YELLOW = 321,
     NORMAL = 322,
     REVERSE = 323,
     LEFT = 324,
     BOLD = 325,
     BLINK = 326,
     UNDERLINE = 327,
     DIM = 328,
     AUTONEXT = 329,
     COLOR = 330,
     COMMENTS = 331,
     DEFAULT = 332,
     VALIDATE = 333,
     DISPLAY = 334,
     DOWNSHIFT = 335,
     UPSHIFT = 336,
     FORMAT = 337,
     INCLUDE = 338,
     INVISIBLE = 339,
     NOUPDATE = 340,
     NOENTRY = 341,
     PICTURE = 342,
     PROGRAM = 343,
     REQUIRED = 344,
     QUERYCLEAR = 345,
     VERIFY = 346,
     WORDWRAP = 347,
     COMPRESS = 348,
     NONCOMPRESS = 349,
     TO = 350,
     AS = 351,
     SERIAL = 352,
     KW_BYTE = 353,
     KW_TEXT = 354,
     VARCHAR = 355,
     SQL_VAR = 356,
     KW_NONSPACE = 357,
     SQLONLY = 358,
     WIDGET = 359,
     CONFIG = 360,
     KW_NL = 361,
     COMPARISON = 362,
     LESSTHAN = 363,
     GREATERTHAN = 364,
     KWOR = 365,
     KWAND = 366,
     KWAND1 = 367,
     KWWHERE = 368,
     KWNOT = 369,
     KWBETWEEN = 370,
     KWIN = 371,
     XVAL = 372,
     KWNULLCHK = 373,
     KWNOTNULLCHK = 374,
     YEAR = 375,
     MONTH = 376,
     DAY = 377,
     HOUR = 378,
     MINUTE = 379,
     SECOND = 380,
     FRACTION = 381,
     LISTBOX = 382,
     BUTTON = 383,
     KW_PANEL = 384,
     DISPLAYONLY = 385,
     ALLOWING = 386,
     KW_WS = 387,
     KW_TAB = 388,
     KW_MASTER_OF = 389,
     KW_BEFORE = 390,
     KW_AFTER = 391,
     KW_EDITADD = 392,
     KW_EDITUPDATE = 393,
     KW_REMOVE = 394,
     KW_OF = 395,
     KW_ADD = 396,
     KW_UPDATE = 397,
     KW_QUERY = 398,
     KW_ON_ENDING = 399,
     KW_ON_BEGINNING = 400,
     KW_CALL = 401,
     KW_BELL = 402,
     KW_ABORT = 403,
     KW_LET = 404,
     KW_EXITNOW = 405,
     KW_NEXTFIELD = 406,
     KW_IF = 407,
     KW_THEN = 408,
     KW_ELSE = 409,
     KW_BEGIN = 410,
     KW_TOTAL = 411,
     KW_RIGHT = 412,
     KW_ZEROFILL = 413,
     KW_USES_EXTENDED = 414
   };
#endif
#define CH 258
#define GRAPH_CH 259
#define KW_COMPOSITES 260
#define INSTRUCTIONS 261
#define ATTRIBUTES 262
#define DATABASE 263
#define BY 264
#define KW_SCREEN_TITLE 265
#define KW_SCREEN 266
#define KW_SIZE 267
#define OPEN_SQUARE 268
#define KW_END 269
#define CLOSE_SQUARE 270
#define NUMBER_VALUE 271
#define NAMED 272
#define OPEN_BRACE 273
#define CLOSE_BRACE 274
#define TITLE 275
#define FORMONLY 276
#define COMMENT 277
#define DYNAMIC 278
#define COLON 279
#define ATSIGN 280
#define DOT 281
#define WITHOUT 282
#define KW_NULL 283
#define INPUT 284
#define TABLES 285
#define PIPE 286
#define EQUAL 287
#define CHAR_VALUE 288
#define SEMICOLON 289
#define LOOKUP 290
#define JOINING 291
#define OPEN_BRACKET 292
#define CLOSE_BRACKET 293
#define STAR 294
#define DIVIDE 295
#define PLUS 296
#define MINUS 297
#define RECORD 298
#define COMMA 299
#define THROUGH 300
#define TYPE 301
#define DELIMITERS 302
#define KW_CHAR 303
#define KW_INT 304
#define KW_DATE 305
#define KW_FLOAT 306
#define SMALLFLOAT 307
#define SMALLINT 308
#define KW_DECIMAL 309
#define MONEY 310
#define DATETIME 311
#define INTERVAL 312
#define LIKE 313
#define BLACK 314
#define BLUE 315
#define GREEN 316
#define CYAN 317
#define RED 318
#define MAGENTA 319
#define WHITE 320
#define YELLOW 321
#define NORMAL 322
#define REVERSE 323
#define LEFT 324
#define BOLD 325
#define BLINK 326
#define UNDERLINE 327
#define DIM 328
#define AUTONEXT 329
#define COLOR 330
#define COMMENTS 331
#define DEFAULT 332
#define VALIDATE 333
#define DISPLAY 334
#define DOWNSHIFT 335
#define UPSHIFT 336
#define FORMAT 337
#define INCLUDE 338
#define INVISIBLE 339
#define NOUPDATE 340
#define NOENTRY 341
#define PICTURE 342
#define PROGRAM 343
#define REQUIRED 344
#define QUERYCLEAR 345
#define VERIFY 346
#define WORDWRAP 347
#define COMPRESS 348
#define NONCOMPRESS 349
#define TO 350
#define AS 351
#define SERIAL 352
#define KW_BYTE 353
#define KW_TEXT 354
#define VARCHAR 355
#define SQL_VAR 356
#define KW_NONSPACE 357
#define SQLONLY 358
#define WIDGET 359
#define CONFIG 360
#define KW_NL 361
#define COMPARISON 362
#define LESSTHAN 363
#define GREATERTHAN 364
#define KWOR 365
#define KWAND 366
#define KWAND1 367
#define KWWHERE 368
#define KWNOT 369
#define KWBETWEEN 370
#define KWIN 371
#define XVAL 372
#define KWNULLCHK 373
#define KWNOTNULLCHK 374
#define YEAR 375
#define MONTH 376
#define DAY 377
#define HOUR 378
#define MINUTE 379
#define SECOND 380
#define FRACTION 381
#define LISTBOX 382
#define BUTTON 383
#define KW_PANEL 384
#define DISPLAYONLY 385
#define ALLOWING 386
#define KW_WS 387
#define KW_TAB 388
#define KW_MASTER_OF 389
#define KW_BEFORE 390
#define KW_AFTER 391
#define KW_EDITADD 392
#define KW_EDITUPDATE 393
#define KW_REMOVE 394
#define KW_OF 395
#define KW_ADD 396
#define KW_UPDATE 397
#define KW_QUERY 398
#define KW_ON_ENDING 399
#define KW_ON_BEGINNING 400
#define KW_CALL 401
#define KW_BELL 402
#define KW_ABORT 403
#define KW_LET 404
#define KW_EXITNOW 405
#define KW_NEXTFIELD 406
#define KW_IF 407
#define KW_THEN 408
#define KW_ELSE 409
#define KW_BEGIN 410
#define KW_TOTAL 411
#define KW_RIGHT 412
#define KW_ZEROFILL 413
#define KW_USES_EXTENDED 414




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
int extended_graphics=0;

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
#line 77 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 481 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 493 "y.tab.c"

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
#define YYFINAL  94
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2853

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  160
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  131
/* YYNRULES -- Number of rules. */
#define YYNRULES  461
/* YYNRULES -- Number of states. */
#define YYNSTATES  691

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   414

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
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    37,    39,    42,    43,    47,    48,    53,    54,    55,
      56,    66,    67,    69,    70,    73,    78,    79,    81,    83,
      86,    88,    90,    92,    94,    96,    98,   100,   102,   104,
     106,   108,   110,   113,   114,   119,   121,   122,   127,   128,
     132,   134,   137,   141,   144,   145,   148,   150,   154,   158,
     164,   168,   172,   174,   177,   178,   183,   185,   188,   192,
     193,   194,   201,   202,   206,   212,   216,   218,   219,   225,
     229,   232,   237,   240,   245,   249,   251,   256,   259,   261,
     263,   267,   271,   275,   277,   281,   283,   288,   291,   293,
     296,   297,   300,   302,   306,   308,   313,   318,   322,   326,
     330,   336,   340,   346,   348,   350,   354,   360,   364,   368,
     370,   375,   377,   379,   381,   383,   387,   391,   393,   395,
     397,   399,   401,   403,   405,   408,   411,   413,   415,   417,
     419,   422,   424,   426,   428,   430,   432,   434,   436,   438,
     440,   442,   444,   446,   448,   450,   452,   454,   455,   456,
     461,   463,   466,   468,   471,   474,   475,   485,   498,   500,
     502,   504,   505,   508,   509,   511,   512,   514,   516,   521,
     523,   527,   528,   530,   532,   536,   540,   544,   548,   550,
     554,   556,   557,   559,   561,   564,   566,   568,   570,   571,
     576,   578,   580,   582,   584,   586,   588,   591,   594,   597,
     600,   602,   604,   606,   608,   610,   612,   616,   618,   621,
     624,   626,   628,   632,   634,   636,   640,   644,   646,   647,
     651,   657,   658,   662,   663,   667,   669,   672,   674,   676,
     678,   680,   682,   684,   687,   689,   690,   694,   696,   698,
     700,   702,   704,   706,   708,   710,   713,   714,   718,   719,
     721,   724,   726,   730,   734,   738,   742,   746,   750,   755,
     759,   762,   765,   767,   773,   779,   782,   786,   788,   790,
     792,   794,   796,   798,   802,   811,   813,   817,   821,   823,
     825,   831,   837,   840,   843,   845,   847,   849,   851,   853,
     855,   857,   863,   864,   867,   869,   874,   877,   881,   884,
     888,   892,   894,   897,   900,   904,   908,   910,   913,   915,
     918,   920,   922,   924,   926,   928,   930,   932,   934,   936,
     938,   940,   944,   948,   950,   955,   961,   962,   964,   966,
     970,   972,   974,   978,   982,   983,   985,   987,   991,   994,
     997,   999,  1002,  1006,  1011,  1015,  1019,  1023,  1027,  1031,
    1035,  1039,  1043,  1047,  1052,  1056,  1059,  1062,  1068,  1074,
    1076,  1078,  1080,  1082,  1084,  1086,  1088,  1092,  1094,  1096,
    1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,  1116,
    1118,  1120,  1122,  1124,  1126,  1128,  1130,  1132,  1134,  1136,
    1138,  1140,  1142,  1144,  1146,  1148,  1150,  1152,  1154,  1156,
    1158,  1160,  1162,  1164,  1166,  1168,  1170,  1172,  1174,  1176,
    1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,  1196,
    1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,  1214,  1216,
    1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,  1236,
    1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1256,
    1258,  1260
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     161,     0,    -1,   162,   165,   184,   189,   213,    -1,     8,
      21,    -1,     8,   164,    27,    28,    29,    -1,     8,    21,
      27,    28,    29,    -1,     8,   164,    -1,    17,    -1,   290,
      -1,   163,    -1,   163,    25,   163,    -1,   166,    -1,   165,
     166,    -1,    -1,    11,   167,   169,    -1,    -1,    10,    33,
     168,   169,    -1,    -1,    -1,    -1,   174,   170,   173,    18,
     171,   176,    19,   172,   175,    -1,    -1,   159,    -1,    -1,
      12,    16,    -1,    12,    16,     9,    16,    -1,    -1,    14,
      -1,   178,    -1,   176,   178,    -1,   163,    -1,   177,    -1,
     180,    -1,   133,    -1,     4,    -1,    31,    -1,    33,    -1,
     179,    -1,   132,    -1,   106,    -1,   102,    -1,     3,    -1,
     179,     3,    -1,    -1,    13,   181,   182,    15,    -1,   232,
      -1,    -1,   182,    31,   183,   232,    -1,    -1,    30,   185,
     175,    -1,   186,    -1,   185,   186,    -1,   185,    44,   186,
      -1,   163,   187,    -1,    -1,    32,   188,    -1,   163,    -1,
     163,    24,   163,    -1,   163,    25,   163,    -1,   163,    25,
     163,    24,   163,    -1,   163,    26,   163,    -1,     7,   190,
     175,    -1,   191,    -1,   190,   191,    -1,    -1,   231,   192,
     193,    34,    -1,   194,    -1,   193,   194,    -1,   193,    34,
     194,    -1,    -1,    -1,    32,   195,   200,   197,   196,   207,
      -1,    -1,    13,    16,    15,    -1,    13,    16,    44,    16,
      15,    -1,   199,   114,    28,    -1,   199,    -1,    -1,    46,
      58,   163,    26,   163,    -1,    46,    58,   163,    -1,    46,
     234,    -1,    21,    26,   227,   198,    -1,   130,   198,    -1,
     130,   131,    29,   198,    -1,   163,    26,   163,    -1,   163,
      -1,    39,   163,    26,   163,    -1,    39,   163,    -1,   231,
      -1,   203,    -1,   202,    44,   203,    -1,   201,    32,   204,
      -1,   163,    26,   163,    -1,   163,    -1,   163,    26,   163,
      -1,   163,    -1,    39,   163,    26,   163,    -1,    39,   163,
      -1,    36,    -1,    44,    36,    -1,    -1,    44,   208,    -1,
     209,    -1,   208,    44,   209,    -1,    74,    -1,    75,    32,
     211,   250,    -1,    35,   202,   206,   205,    -1,    76,    32,
      33,    -1,    77,    32,   210,    -1,    79,    58,   163,    -1,
      79,    58,   163,    26,   163,    -1,    78,    58,   163,    -1,
      78,    58,   163,    26,   163,    -1,    80,    -1,    81,    -1,
      82,    32,    33,    -1,    83,    32,    37,   235,    38,    -1,
     104,    32,    33,    -1,   105,    32,    33,    -1,    84,    -1,
      23,    12,    32,    16,    -1,    23,    -1,   103,    -1,    86,
      -1,    85,    -1,    87,    32,    33,    -1,    88,    32,    33,
      -1,    89,    -1,    68,    -1,    91,    -1,    90,    -1,   158,
      -1,   157,    -1,    92,    -1,    92,    93,    -1,    92,    94,
      -1,    33,    -1,    16,    -1,   101,    -1,   212,    -1,   211,
     212,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    16,    -1,
      68,    -1,    73,    -1,    67,    -1,    69,    -1,    70,    -1,
      71,    -1,    72,    -1,    -1,    -1,     6,   214,   215,   175,
      -1,   216,    -1,   215,   216,    -1,   217,    -1,   217,    34,
      -1,    47,    33,    -1,    -1,    11,    43,   218,   222,    37,
     223,    38,   219,   221,    -1,   129,    37,    16,    44,    16,
      38,    95,    37,    16,    44,    16,    38,    -1,   257,    -1,
     278,    -1,   262,    -1,    -1,    96,   127,    -1,    -1,    39,
      -1,    -1,    34,    -1,   163,    -1,   163,    13,    16,    15,
      -1,   226,    -1,   223,   224,   226,    -1,    -1,    44,    -1,
     163,    -1,   163,    26,   163,    -1,    21,    26,   163,    -1,
     163,    26,    39,    -1,    21,    26,    39,    -1,   225,    -1,
     225,    45,   225,    -1,   163,    -1,    -1,   229,    -1,   230,
      -1,   229,   230,    -1,   132,    -1,   133,    -1,   163,    -1,
      -1,   228,   163,   233,   228,    -1,    48,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,   238,
      -1,    55,   238,    -1,    56,   245,    -1,    57,   239,    -1,
      97,    -1,    98,    -1,    99,    -1,   100,    -1,   128,    -1,
     237,    -1,   235,    44,   237,    -1,    16,    -1,    41,    16,
      -1,    42,    16,    -1,    33,    -1,    17,    -1,    17,    95,
      17,    -1,     3,    -1,   236,    -1,   236,    95,   236,    -1,
      33,    95,    33,    -1,    28,    -1,    -1,    37,    16,    38,
      -1,    37,    16,    44,    16,    38,    -1,    -1,   242,    95,
     244,    -1,    -1,    37,    16,    38,    -1,    16,    -1,   243,
     240,    -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,
     124,    -1,   125,    -1,   126,   249,    -1,   243,    -1,    -1,
     246,    95,   247,    -1,   248,    -1,   248,    -1,   120,    -1,
     121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,    -1,
     126,   249,    -1,    -1,    37,   241,    38,    -1,    -1,   251,
      -1,   113,   252,    -1,   253,    -1,   253,   111,   253,    -1,
     253,   110,   253,    -1,   254,   107,   254,    -1,   254,   108,
     254,    -1,   254,   109,   254,    -1,   254,    58,   254,    -1,
     254,   114,    58,   254,    -1,   254,    32,   254,    -1,   254,
     118,    -1,   254,   119,    -1,   254,    -1,   254,   115,   254,
     111,   254,    -1,   254,   116,    37,   256,    38,    -1,   114,
     253,    -1,    37,   253,    38,    -1,   255,    -1,    16,    -1,
      33,    -1,   117,    -1,    17,    -1,   254,    -1,   256,    44,
     254,    -1,     5,   108,   258,   109,   220,   108,   258,   109,
      -1,   259,    -1,   258,    44,   259,    -1,   260,    26,   261,
      -1,   163,    -1,   163,    -1,   135,   272,   140,   276,   270,
      -1,   136,   273,   140,   276,   270,    -1,   145,   279,    -1,
     144,   279,    -1,   266,    -1,   271,    -1,   264,    -1,   267,
      -1,   268,    -1,   279,    -1,   269,    -1,   152,   283,   153,
     263,   265,    -1,    -1,   154,   263,    -1,   148,    -1,   149,
     231,    32,   283,    -1,   151,   231,    -1,   151,    32,   231,
      -1,   151,   150,    -1,   151,    32,   150,    -1,   155,   270,
      14,    -1,   263,    -1,   270,   263,    -1,    76,    33,    -1,
      76,   147,    33,    -1,    76,    68,    33,    -1,   274,    -1,
     272,   274,    -1,   275,    -1,   273,   275,    -1,   137,    -1,
     138,    -1,   139,    -1,   137,    -1,   141,    -1,   142,    -1,
     143,    -1,   139,    -1,    79,    -1,   138,    -1,   277,    -1,
     276,    44,   277,    -1,   260,    26,   261,    -1,   261,    -1,
     260,   134,   260,   221,    -1,   146,   163,    37,   280,    38,
      -1,    -1,   281,    -1,   282,    -1,   281,    44,   282,    -1,
     283,    -1,   286,    -1,   283,   111,   283,    -1,   283,   110,
     283,    -1,    -1,   285,    -1,   283,    -1,   285,    44,   283,
      -1,    42,   283,    -1,    41,   283,    -1,   288,    -1,   114,
     283,    -1,    37,   283,    38,    -1,   287,    37,   284,    38,
      -1,   156,   140,   231,    -1,   283,   107,   283,    -1,   283,
     108,   283,    -1,   283,   109,   283,    -1,   283,    39,   283,
      -1,   283,    41,   283,    -1,   283,    42,   283,    -1,   283,
      40,   283,    -1,   283,    58,   283,    -1,   283,   114,    58,
     283,    -1,   283,    32,   283,    -1,   283,   118,    -1,   283,
     119,    -1,   283,   115,   283,   111,   283,    -1,   283,   116,
      37,   289,    38,    -1,   163,    -1,   231,    -1,    16,    -1,
      33,    -1,   117,    -1,    28,    -1,   288,    -1,   289,    44,
     288,    -1,    96,    -1,    74,    -1,    59,    -1,    71,    -1,
      70,    -1,    60,    -1,   110,    -1,   111,    -1,   107,    -1,
     128,    -1,     9,    -1,    75,    -1,    22,    -1,    76,    -1,
      93,    -1,   105,    -1,    62,    -1,     8,    -1,    56,    -1,
      77,    -1,    47,    -1,    80,    -1,    23,    -1,    82,    -1,
      61,    -1,    83,    -1,    29,    -1,    57,    -1,    84,    -1,
      98,    -1,    48,    -1,    50,    -1,    54,    -1,    51,    -1,
      49,    -1,   129,    -1,    11,    -1,    10,    -1,    12,    -1,
      99,    -1,    69,    -1,   127,    -1,    64,    -1,    55,    -1,
      86,    -1,    94,    -1,   114,    -1,    87,    -1,    88,    -1,
      43,    -1,    63,    -1,    89,    -1,    68,    -1,    73,    -1,
      67,    -1,    97,    -1,    52,    -1,    53,    -1,   103,    -1,
     101,    -1,    30,    -1,    45,    -1,    20,    -1,    95,    -1,
      72,    -1,    81,    -1,   100,    -1,    91,    -1,    35,    -1,
      36,    -1,    65,    -1,   104,    -1,    27,    -1,    92,    -1,
      90,    -1,    66,    -1,    46,    -1,    58,    -1,   120,    -1,
     121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,    -1,
     126,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   114,   114,   117,   118,   123,   124,   132,   133,   137,
     137,   140,   140,   143,   143,   156,   156,   175,   177,   180,
     175,   185,   185,   190,   191,   192,   204,   205,   210,   211,
     214,   229,   239,   240,   251,   263,   276,   286,   295,   300,
     303,   311,   312,   318,   317,   339,   342,   342,   360,   361,
     364,   365,   366,   369,   376,   377,   380,   381,   382,   384,
     385,   391,   395,   395,   399,   399,   409,   410,   411,   415,
     419,   415,   456,   457,   461,   469,   470,   473,   474,   477,
     480,   485,   494,   506,   518,   527,   535,   543,   553,   557,
     558,   561,   564,   565,   569,   570,   571,   572,   575,   576,
     580,   581,   585,   585,   588,   589,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   625,   626,   627,   628,   629,   630,   631,   634,   637,
     638,   639,   640,   641,   644,   648,   654,   655,   656,   660,
     661,   665,   666,   667,   668,   669,   670,   671,   672,   674,
     688,   689,   690,   691,   692,   693,   694,   698,   699,   699,
     704,   704,   706,   706,   709,   719,   719,   722,   723,   724,
     725,   729,   729,   731,   731,   733,   733,   736,   739,   755,
     758,   762,   763,   767,   769,   771,   773,   775,   780,   780,
     784,   790,   790,   793,   793,   797,   798,   811,   819,   819,
     828,   832,   836,   840,   844,   848,   852,   856,   860,   864,
     868,   872,   876,   880,   883,   890,   890,   895,   895,   895,
     900,   901,   902,   903,   904,   905,   908,   912,   918,   919,
     920,   923,   924,   931,   933,   938,   946,   949,   950,   951,
     952,   953,   954,   955,   961,   963,   964,   967,   970,   974,
     975,   976,   977,   978,   979,   980,   986,   988,   995,   995,
    1001,  1007,  1008,  1011,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1032,  1039,  1040,
    1041,  1046,  1049,  1053,  1065,  1068,  1069,  1072,  1075,  1078,
    1082,  1083,  1084,  1085,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1100,  1104,  1104,  1107,  1110,  1113,  1114,  1115,  1116,
    1120,  1123,  1124,  1129,  1130,  1131,  1136,  1136,  1140,  1140,
    1144,  1145,  1146,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1159,  1160,  1164,  1165,  1169,  1172,  1175,  1175,  1179,  1179,
    1182,  1187,  1188,  1189,  1194,  1195,  1198,  1199,  1203,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1227,
    1230,  1231,  1232,  1233,  1234,  1237,  1241,  1253,  1254,  1255,
    1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,
    1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,
    1336,  1337
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "GRAPH_CH", "KW_COMPOSITES",
  "INSTRUCTIONS", "ATTRIBUTES", "DATABASE", "BY", "KW_SCREEN_TITLE",
  "KW_SCREEN", "KW_SIZE", "OPEN_SQUARE", "KW_END", "CLOSE_SQUARE",
  "NUMBER_VALUE", "NAMED", "OPEN_BRACE", "CLOSE_BRACE", "TITLE",
  "FORMONLY", "COMMENT", "DYNAMIC", "COLON", "ATSIGN", "DOT", "WITHOUT",
  "KW_NULL", "INPUT", "TABLES", "PIPE", "EQUAL", "CHAR_VALUE", "SEMICOLON",
  "LOOKUP", "JOINING", "OPEN_BRACKET", "CLOSE_BRACKET", "STAR", "DIVIDE",
  "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", "TYPE", "DELIMITERS",
  "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", "SMALLFLOAT", "SMALLINT",
  "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", "LIKE", "BLACK", "BLUE",
  "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", "YELLOW", "NORMAL",
  "REVERSE", "LEFT", "BOLD", "BLINK", "UNDERLINE", "DIM", "AUTONEXT",
  "COLOR", "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY", "DOWNSHIFT",
  "UPSHIFT", "FORMAT", "INCLUDE", "INVISIBLE", "NOUPDATE", "NOENTRY",
  "PICTURE", "PROGRAM", "REQUIRED", "QUERYCLEAR", "VERIFY", "WORDWRAP",
  "COMPRESS", "NONCOMPRESS", "TO", "AS", "SERIAL", "KW_BYTE", "KW_TEXT",
  "VARCHAR", "SQL_VAR", "KW_NONSPACE", "SQLONLY", "WIDGET", "CONFIG",
  "KW_NL", "COMPARISON", "LESSTHAN", "GREATERTHAN", "KWOR", "KWAND",
  "KWAND1", "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK",
  "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND",
  "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY", "ALLOWING",
  "KW_WS", "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", "KW_EDITADD",
  "KW_EDITUPDATE", "KW_REMOVE", "KW_OF", "KW_ADD", "KW_UPDATE", "KW_QUERY",
  "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL", "KW_BELL", "KW_ABORT",
  "KW_LET", "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF", "KW_THEN", "KW_ELSE",
  "KW_BEGIN", "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL", "KW_USES_EXTENDED",
  "$accept", "form_def", "database_section", "named_or_kw", "dbname",
  "screen_section", "screens_section", "@1", "@2", "screens_rest", "@3",
  "@4", "@5", "op_extended", "op_size", "op_end", "screen_layout",
  "some_text", "screen_element", "ch_list", "field", "@6", "field_element",
  "@7", "op_table_section", "table_def_list", "table_def", "opequal",
  "table_qualifier", "attribute_section", "field_tag_list", "field_tag",
  "@8", "fpart_list", "fpart", "@9", "@10", "op_att",
  "field_datatype_null", "field_datatype", "field_type", "lu_ft",
  "lu_ft_eq_c", "lu_ft_eq_c_i", "lu_fc", "lu_joincol", "lu_join",
  "op_field_desc", "op_desc_list", "desc", "def_val", "colors", "color",
  "op_instruction_section", "@11", "instruct_opts", "instruct_op_1",
  "instruct_op", "@12", "op_ltype", "op_star", "op_semi", "srec_dim",
  "srec_field_list", "op_comma", "field_list_item", "field_list_element",
  "field_name", "op_ws", "ws", "ws_elem", "field_tag_name",
  "field_tag_name_scr", "@13", "datatype", "incl_list", "number_value",
  "incl_entry", "opt_dec_ext", "opt_int_ext", "opt_unit_size", "dtfrac",
  "int_start", "int_start_unit", "int_end", "opt_dt_ext", "dt_start",
  "dt_end", "dtime_val", "opt_frac", "op_where", "where_clause", "clauses",
  "clause", "value", "fieldidentifier", "value_list", "composites",
  "comp_list", "comp_item", "table_name", "column_name", "control_block",
  "action", "if", "op_else", "abort", "let", "nextfield", "block",
  "actions", "comments", "bef_act_list", "aft_act_list", "bef_act",
  "aft_act", "column_list", "column_entry", "master_of", "func_call",
  "op_func_call_args", "func_call_args", "func_call_arg", "expression",
  "op_expression_list", "expression_list", "single_expression",
  "fcall_name", "evalue", "evalue_list", "any_kword", 0
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
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   160,   161,   162,   162,   162,   162,   163,   163,   164,
     164,   165,   165,   167,   166,   168,   166,   170,   171,   172,
     169,   173,   173,   174,   174,   174,   175,   175,   176,   176,
     177,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   179,   179,   181,   180,   182,   183,   182,   184,   184,
     185,   185,   185,   186,   187,   187,   188,   188,   188,   188,
     188,   189,   190,   190,   192,   191,   193,   193,   193,   195,
     196,   194,   197,   197,   197,   198,   198,   199,   199,   199,
     199,   200,   200,   200,   200,   200,   200,   200,   201,   202,
     202,   203,   204,   204,   205,   205,   205,   205,   206,   206,
     207,   207,   208,   208,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   210,   210,   210,   211,
     211,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   213,   214,   213,
     215,   215,   216,   216,   217,   218,   217,   217,   217,   217,
     217,   219,   219,   220,   220,   221,   221,   222,   222,   223,
     223,   224,   224,   225,   225,   225,   225,   225,   226,   226,
     227,   228,   228,   229,   229,   230,   230,   231,   233,   232,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   235,   235,   236,   236,   236,
     237,   237,   237,   237,   237,   237,   237,   237,   238,   238,
     238,   239,   239,   240,   240,   241,   242,   243,   243,   243,
     243,   243,   243,   243,   244,   245,   245,   246,   247,   248,
     248,   248,   248,   248,   248,   248,   249,   249,   250,   250,
     251,   252,   252,   252,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   254,   254,   254,
     254,   255,   256,   256,   257,   258,   258,   259,   260,   261,
     262,   262,   262,   262,   263,   263,   263,   263,   263,   263,
     263,   264,   265,   265,   266,   267,   268,   268,   268,   268,
     269,   270,   270,   271,   271,   271,   272,   272,   273,   273,
     274,   274,   274,   275,   275,   275,   275,   275,   275,   275,
     276,   276,   277,   277,   278,   279,   280,   280,   281,   281,
     282,   283,   283,   283,   284,   284,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   287,
     288,   288,   288,   288,   288,   289,   289,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     2,     0,     3,     0,     4,     0,     0,     0,
       9,     0,     1,     0,     2,     4,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     4,     1,     0,     4,     0,     3,
       1,     2,     3,     2,     0,     2,     1,     3,     3,     5,
       3,     3,     1,     2,     0,     4,     1,     2,     3,     0,
       0,     6,     0,     3,     5,     3,     1,     0,     5,     3,
       2,     4,     2,     4,     3,     1,     4,     2,     1,     1,
       3,     3,     3,     1,     3,     1,     4,     2,     1,     2,
       0,     2,     1,     3,     1,     4,     4,     3,     3,     3,
       5,     3,     5,     1,     1,     3,     5,     3,     3,     1,
       4,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     4,
       1,     2,     1,     2,     2,     0,     9,    12,     1,     1,
       1,     0,     2,     0,     1,     0,     1,     1,     4,     1,
       3,     0,     1,     1,     3,     3,     3,     3,     1,     3,
       1,     0,     1,     1,     2,     1,     1,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     2,
       1,     1,     3,     1,     1,     3,     3,     1,     0,     3,
       5,     0,     3,     0,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     3,     0,     1,
       2,     1,     3,     3,     3,     3,     3,     3,     4,     3,
       2,     2,     1,     5,     5,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     8,     1,     3,     3,     1,     1,
       5,     5,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     2,     1,     4,     2,     3,     2,     3,
       3,     1,     2,     2,     3,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     4,     5,     0,     1,     1,     3,
       1,     1,     3,     3,     0,     1,     1,     3,     2,     2,
       1,     2,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     2,     2,     5,     5,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
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
static const unsigned short int yydefact[] =
{
       0,     0,     0,     0,   394,   387,   414,   413,   415,     7,
     439,     3,   389,   399,   449,   403,   437,   445,   446,   426,
     438,   453,   397,   407,   411,   408,   410,   433,   434,   409,
     420,   395,   404,   454,   379,   382,   401,   393,   427,   419,
     447,   452,   431,   429,   417,   381,   380,   441,   430,   378,
     388,   390,   396,   398,   442,   400,   402,   405,   421,   424,
     425,   428,   451,   444,   450,   391,   422,   440,   377,   432,
     406,   416,   443,   436,   435,   448,   392,   385,   383,   384,
     423,   455,   456,   457,   458,   459,   460,   461,   418,   386,
     412,     9,     6,     8,     1,     0,    13,    48,    11,     0,
       0,     0,    15,    23,     0,    12,     0,     0,    10,     0,
      23,     0,    14,    17,    54,    26,    50,     0,   157,     5,
       4,    16,    24,    21,     0,    53,    27,     0,    49,    51,
     197,    26,    62,    64,   158,     2,     0,    22,     0,    56,
      55,    52,    61,    63,     0,     0,    25,    18,     0,     0,
       0,    69,     0,    66,     0,   413,   397,   412,     0,     0,
       0,     0,   288,    26,   160,   162,   168,     0,   170,   169,
       0,    57,    58,    60,     0,    65,    67,     0,   165,   164,
       0,   320,   321,   322,     0,   316,   328,   323,   329,   327,
     324,   325,   326,     0,   318,     0,   293,   292,   159,   161,
     163,     0,    41,    34,    43,    35,    36,    40,    39,    38,
      33,    30,     0,    31,    28,    37,    32,     0,     0,     0,
      77,    85,    72,    68,     0,   285,     0,     0,     0,     0,
     317,     0,   319,     0,   175,   191,    19,    29,    42,    59,
       0,    87,     0,     0,    82,    76,     0,     0,    70,     0,
     173,     0,   177,     0,     0,   289,     0,   333,     0,   330,
       0,   336,   176,   334,   195,   196,     0,     0,   192,   193,
      45,    26,   190,    77,     0,   200,   201,   202,   203,   204,
     205,   228,   228,   245,   231,     0,   210,   211,   212,   213,
     214,    80,    77,     0,    84,     0,   100,   286,   174,     0,
     289,   287,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,   311,   296,   294,   297,   298,   300,   290,
     295,   299,   291,   371,   374,   372,     0,     0,     0,   423,
     373,     0,   197,   370,     0,   337,   338,   340,   341,     0,
     350,    44,    46,   198,   194,    20,    81,    86,     0,   206,
     207,   249,   250,   251,   252,   253,   254,   256,   208,     0,
     247,   237,   238,   239,   240,   241,   242,   256,   209,     0,
     233,    79,    83,    75,    73,     0,     0,    71,     0,     0,
       0,   183,   181,   188,   179,     0,   332,   331,   313,     0,
       0,     0,     0,   308,   306,     0,     0,   312,     0,   349,
     348,   351,     0,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   365,
     366,   344,   191,   191,     0,     0,   255,     0,   243,     0,
       0,   236,     0,     0,   121,     0,   128,   104,     0,     0,
       0,     0,     0,   113,   114,     0,     0,   119,   124,   123,
       0,     0,   127,   130,   129,   133,   122,     0,     0,   132,
     131,   101,   102,     0,   178,     0,     0,   171,   182,     0,
       0,     0,   315,   314,     0,   309,   307,     0,   310,   352,
     354,   339,   364,   358,   361,   359,   360,   362,   355,   356,
     357,   343,   342,     0,     0,     0,   346,     0,   345,    47,
     199,   229,     0,   235,     0,   246,   248,   244,   232,     0,
      78,    74,     0,     0,     0,    89,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,     0,     0,
       0,   284,   187,   185,   186,   184,     0,   175,   180,   189,
       0,   305,   302,   363,     0,   375,     0,   353,     0,     0,
     257,   234,     0,     0,    98,     0,     0,   149,   141,   142,
     143,   144,   145,   146,   147,   148,   152,   150,   153,   154,
     155,   156,   151,   258,   139,   107,   137,   136,   138,   108,
     111,   109,   115,     0,   125,   126,   117,   118,   103,   172,
     166,     0,     0,   301,   367,   368,     0,   347,   230,   120,
      93,    91,    99,    90,     0,    95,   106,     0,   140,   105,
     259,     0,     0,   223,   217,   221,   227,   220,     0,     0,
       0,   224,   215,     0,   303,   376,     0,    97,     0,   278,
     281,   279,     0,     0,   280,   260,   261,   272,   277,   112,
     110,     0,     0,   218,   219,   116,     0,     0,     0,    92,
       0,    94,     0,   275,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   271,   222,   226,   216,   225,
     167,    96,   276,   263,   262,   269,   267,   264,   265,   266,
       0,     0,     0,   268,     0,   282,     0,   273,   274,     0,
     283
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,   332,    92,    97,    98,   103,   110,   112,
     123,   170,   271,   138,   113,   128,   212,   213,   214,   215,
     216,   235,   266,   422,   106,   115,   116,   125,   140,   118,
     131,   132,   144,   152,   153,   174,   296,   248,   244,   245,
     222,   513,   514,   515,   601,   606,   556,   377,   461,   462,
     579,   573,   574,   135,   145,   163,   164,   165,   227,   537,
     299,   263,   253,   382,   469,   383,   384,   273,   267,   268,
     269,   333,   270,   423,   291,   620,   621,   622,   349,   368,
     431,   504,   369,   370,   508,   358,   359,   505,   360,   426,
     609,   610,   635,   636,   637,   638,   686,   166,   224,   225,
     226,   257,   168,   313,   314,   593,   315,   316,   317,   318,
     319,   320,   184,   193,   185,   194,   258,   259,   169,   321,
     334,   335,   336,   337,   497,   498,   338,   339,   340,   546,
      93
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -571
static const short int yypact[] =
{
      31,  1870,    51,    36,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,    60,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,    80,    75,  -571,  -571,    96,  -571,    23,  -571,    82,
    2602,   108,  -571,   129,  2602,  -571,   185,   164,  -571,   168,
     129,   182,  -571,  -571,   167,  1748,  -571,  2602,   195,  -571,
    -571,  -571,   193,    47,  2602,  -571,  -571,  2602,  -571,  -571,
    -571,  1992,  -571,  -571,  -571,  -571,   196,  -571,   192,    93,
    -571,  -571,  -571,  -571,   187,  1121,  -571,  -571,  2602,  2602,
    2602,  -571,   138,  -571,   109,   180,   211,   190,    29,    66,
      83,    83,  -571,   992,  -571,   212,  -571,   113,  -571,  -571,
    1377,  -571,   225,  -571,  1503,   187,  -571,  2602,  -571,  -571,
     235,  -571,  -571,  -571,   103,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,   -66,  -571,  2602,  -571,  -571,  -571,  -571,
    -571,  2602,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  1250,  -571,  -571,   254,  -571,  2602,   233,  2602,
     -20,   236,   248,  -571,   -29,  -571,   237,  2602,   220,  2602,
    -571,  2602,  -571,   230,   234,   -67,  -571,  -571,  -571,  -571,
    2602,   243,   490,   241,  -571,   157,  2602,   256,  -571,  2602,
     238,  2602,   262,   239,   263,   255,   257,  -571,     5,  -571,
       5,   623,  -571,  -571,  -571,  -571,    33,  2602,   -67,  -571,
    -571,   266,  -571,   240,  2602,  -571,  -571,  -571,  -571,  -571,
    -571,   245,   245,   169,   194,  2602,  -571,  -571,  -571,  -571,
    -571,  -571,   240,   259,  -571,    17,   252,  -571,  -571,   177,
    -571,  -571,   281,  2114,   260,  2602,  2602,   -27,  -571,  2602,
     745,   623,   -24,  -571,  -571,  -571,  -571,  -571,  -571,   -24,
    -571,  -571,   -24,  -571,  -571,  -571,   623,   623,   623,   623,
    -571,   159,   269,  -571,   265,   267,  -571,   398,  -571,   270,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,   284,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,   273,  -571,   217,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,   273,  -571,   227,
     286,   298,  -571,  -571,  -571,   309,   278,  -571,  2602,   311,
     301,   302,    69,   285,  -571,   247,  -571,  -571,  -571,   296,
     312,   316,   867,  -571,  -571,   -18,    -9,  -571,   370,   398,
     398,   398,  2602,  -571,   623,   623,   623,   623,   623,   623,
     623,   623,   623,   623,   623,   623,   291,   623,   307,  -571,
    -571,   623,   -67,   -67,    77,   334,  -571,   169,  -571,   194,
     335,  -571,  2602,   356,   360,  2602,  -571,  -571,   341,   342,
     343,   318,   320,  -571,  -571,   347,   348,  -571,  -571,  -571,
     352,   353,  -571,  -571,  -571,    39,  -571,   354,   355,  -571,
    -571,   344,  -571,   -26,  -571,  2236,  2358,   293,  -571,  2114,
    2114,   357,  -571,  -571,   623,  -571,  -571,   -24,  -571,  -571,
    -571,  -571,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   623,   418,  1626,   398,   358,   346,  -571,
    -571,  -571,   376,  -571,   359,  -571,  -571,  -571,  -571,   361,
    -571,  -571,   363,   366,     1,  -571,  -571,   499,   371,     3,
    2602,  2602,   372,   369,   374,   380,  -571,  -571,   381,   382,
     278,  -571,  -571,  -571,  -571,  -571,   276,   234,  -571,  -571,
     377,   398,   264,   398,   623,  -571,   114,  -571,   623,   378,
    -571,  -571,   401,  2602,  -571,  2724,  2480,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,   118,  -571,  -571,  -571,  -571,  -571,  -571,
     394,   395,  -571,    27,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,   379,   -24,  -571,   398,  -571,  1626,   398,  -571,  -571,
     396,  -571,   392,  -571,  2602,   399,  -571,    -8,  -571,  -571,
    -571,  2602,  2602,  -571,  -571,   331,  -571,   332,   413,   416,
     117,   338,  -571,   426,  -571,  -571,  2602,   417,  2602,  -571,
    -571,  -571,    -8,    -8,  -571,  -571,   -16,   106,  -571,  -571,
    -571,   427,   412,  -571,  -571,  -571,    27,    15,   408,  -571,
    2602,  -571,   409,  -571,    -8,    -8,    -5,    -5,    -5,    -5,
      -5,   390,    -5,   414,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
      -5,   350,    -5,  -571,    -5,  -571,   127,  -571,  -571,    -5,
    -571
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -571,  -571,  -571,    -1,  -571,  -571,   365,  -571,  -571,   339,
    -571,  -571,  -571,  -571,  -571,  -121,  -571,  -571,   242,  -571,
    -571,  -571,  -571,  -571,  -571,  -571,   -77,  -571,  -571,  -571,
    -571,   321,  -571,  -571,   -93,  -571,  -571,  -571,  -238,  -571,
    -571,  -571,  -571,  -102,  -571,  -571,  -571,  -571,  -571,   -75,
    -571,  -571,  -110,  -571,  -571,  -571,   303,  -571,  -571,  -571,
    -571,   -70,  -571,  -571,  -571,     2,     4,  -571,    48,  -571,
     207,  -114,    61,  -571,  -571,  -571,  -165,  -159,   208,  -571,
    -571,  -571,  -571,    62,  -571,  -571,  -571,  -571,    65,   126,
    -571,  -571,  -571,  -570,  -424,  -571,  -571,  -571,   119,   246,
    -143,  -235,  -571,  -318,  -571,  -571,  -571,  -571,  -571,  -571,
    -233,  -571,  -571,  -571,   314,   306,   271,   197,  -571,    14,
    -571,  -571,    92,   -74,  -571,  -571,  -571,  -571,  -488,  -571,
    -571
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -447
static const short int yytable[] =
{
      91,   397,   167,   133,   397,   478,   388,   545,   629,   630,
     142,   629,   630,   186,   405,   249,   301,   133,   249,   576,
     167,   406,   407,   408,   409,   631,   242,   322,   631,   632,
     613,   614,   374,    95,    96,   346,   577,   554,   129,     1,
     410,   389,   198,   614,   615,   555,    95,    96,   341,   306,
     141,    94,   307,   104,   372,   616,   618,   619,   234,   176,
     617,   375,   652,   653,   342,   264,   265,   307,   618,   619,
     386,   187,   188,   189,   231,   190,   191,   192,   397,   396,
     250,   307,   223,   531,   673,   674,   256,    99,   256,   411,
     412,   413,   414,   415,   654,   655,   416,   417,   418,   108,
     419,   420,   101,   114,   578,   100,   633,   467,   625,   634,
     107,   243,   634,   468,   114,   501,   130,   148,   149,   150,
     390,   502,   195,   139,   308,   309,   114,   310,   311,   102,
     130,   312,   526,   527,   557,   477,   109,   195,   656,   308,
     309,   111,   310,   311,   162,   186,   312,   171,   172,   173,
     345,   195,   595,   308,   309,   645,   310,   311,   596,   542,
     312,   646,   162,   256,   657,   688,   181,   182,   183,   211,
     151,   689,   175,   221,   196,   197,   162,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   117,   119,   233,   391,   394,   120,   122,   124,
     162,   134,   136,   187,   188,   189,   137,   190,   191,   192,
     147,   211,   146,   658,   659,   660,   239,   177,   241,   151,
     661,   662,   663,   178,   664,   665,   252,   180,   255,   195,
     255,   607,   675,   676,   677,   678,   679,   395,   681,   272,
     181,   182,   183,   229,   179,   294,   200,   201,   162,   217,
     300,   228,   398,   399,   400,   401,   683,   238,   685,   240,
     687,   247,   246,   251,   254,   690,   343,   261,   262,   274,
     292,   293,   295,   347,   624,   302,   303,   298,   476,   304,
     126,  -288,   348,   305,   371,   378,   242,   373,   480,   351,
     352,   353,   354,   355,   356,   357,   376,   379,   385,   402,
     424,   434,   381,   403,   300,   255,  -369,   421,   130,   130,
     425,   404,   427,   435,   361,   362,   363,   364,   365,   366,
     367,   516,   429,   430,   432,   433,   464,   465,   466,   472,
     470,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   471,   494,   495,   473,   436,   496,   474,   493,
     503,   509,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   511,   512,   517,   518,   519,   520,   162,   521,   522,
     523,   456,   457,   458,   524,   525,   528,   529,   530,   536,
     548,   130,   549,   591,   540,   552,   547,   550,   553,   551,
     541,   130,   405,   589,   575,   582,   583,   584,   479,   406,
     407,   408,   409,   585,   586,   587,   598,   599,   592,   543,
     611,   612,   626,   623,  -446,   628,   641,   642,   410,   643,
     405,   510,   644,   647,   130,   459,   460,   406,   407,   408,
     409,   516,   648,   650,   666,   667,   670,   672,   680,   121,
     405,   682,   143,   603,   237,   588,   410,   406,   407,   408,
     409,   684,   105,   608,   533,   535,   199,   590,   381,   381,
     594,   500,   539,   538,   597,   344,   410,   411,   412,   413,
     414,   415,   669,   499,   416,   417,   418,   668,   419,   420,
     350,   507,   506,   428,   130,   297,   481,   463,   230,   232,
       0,     0,   260,   387,     0,   411,   412,   413,   414,   415,
       0,     0,   416,   417,   418,   557,   419,   420,     0,   580,
     581,     0,     0,     0,     0,   411,   412,   413,   414,   544,
       0,     0,   416,   417,   418,     0,   419,   420,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,     0,
       0,     0,   600,     0,   130,   605,     0,     0,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   287,   288,
     289,     0,     0,     0,     0,   130,     0,     0,     0,     0,
       0,     0,     0,   627,     0,     0,     0,     0,     0,     0,
     639,   640,     0,     0,     0,     0,     0,     0,   290,     0,
       0,     0,     0,     0,     0,   649,     0,   651,     0,     0,
       0,     4,     5,     6,     7,     8,     0,     0,     0,   323,
       9,     0,     0,    10,     0,    12,    13,     0,     0,   671,
      14,   324,    15,    16,     0,     0,   325,     0,    17,    18,
     326,     0,     0,     0,   327,   328,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,     0,     0,    78,    79,     0,     0,   329,     0,     0,
     330,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,     0,    15,    16,     0,   392,     0,   331,
      17,    18,     0,     0,     0,     0,     0,     0,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,    77,     0,     0,    78,    79,     0,     0,    80,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,   393,    15,    16,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   154,     0,     0,
       4,     5,     6,   155,     8,     0,   126,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,   475,     0,    14,
       0,    15,    16,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,     0,    19,     0,    20,    21,   156,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,    77,
       0,     0,    78,    79,     0,     0,    80,     0,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   157,     0,     0,     0,     0,   154,   158,   159,     4,
       5,     6,   155,     8,     0,     0,   160,   161,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,     0,
      15,    16,     0,     0,     0,     0,    17,    18,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    21,   156,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,    77,     0,
       0,    78,    79,     0,     0,    80,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     157,     0,     0,   202,   203,     0,   158,   159,     4,     5,
       6,     7,     8,   204,     0,   160,   161,     9,     0,   236,
      10,     0,    12,    13,     0,     0,     0,    14,     0,    15,
      16,   205,     0,   206,     0,    17,    18,     0,     0,     0,
       0,     0,     0,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,   207,    74,    75,    76,   208,    77,     0,     0,
      78,    79,     0,     0,    80,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     202,   203,   209,   210,     0,     4,     5,     6,     7,     8,
     204,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,     0,    15,    16,   205,     0,
     206,     0,    17,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   207,
      74,    75,    76,   208,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,   209,
     210,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    10,   218,    12,    13,     0,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,    17,    18,
       0,     0,   219,     0,     0,     0,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,     0,     0,    78,    79,     0,     0,    80,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   220,     4,     5,     6,     7,     8,     0,
       0,     0,   323,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,   324,    15,    16,     0,     0,   325,
       0,    17,    18,     0,     0,     0,     0,     0,     0,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,    77,     0,     0,    78,    79,     0,     0,
      80,     0,     0,   330,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     4,     5,     6,     7,
       8,     0,   126,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,     0,    15,    16,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,     0,
       0,    19,   127,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,    77,     0,     0,    78,    79,
       0,     0,    80,     0,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,    11,    12,    13,     0,     0,     0,    14,     0,    15,
      16,     0,     0,     0,     0,    17,    18,     0,     0,     0,
       0,     0,     0,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,    77,     0,     0,
      78,    79,     0,     0,    80,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       4,     5,     6,     7,     8,     0,   126,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
       0,    15,    16,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,     0,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,    77,
       0,     0,    78,    79,     0,     0,    80,     0,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,   380,    12,    13,     0,     0,
       0,    14,     0,    15,    16,     0,     0,     0,     0,    17,
      18,     0,     0,     0,     0,     0,     0,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,    77,     0,     0,    78,    79,     0,     0,    80,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,     0,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,   532,     0,     0,     0,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,    77,     0,     0,    78,    79,     0,     0,
      80,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,     0,    15,    16,     0,
       0,     0,     0,    17,    18,     0,     0,   534,     0,     0,
       0,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,    77,     0,     0,    78,    79,
       0,     0,    80,     0,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,     0,    12,    13,     0,     0,     0,    14,     0,    15,
      16,     0,     0,     0,     0,    17,    18,     0,     0,   604,
       0,     0,     0,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,    77,     0,     0,
      78,    79,     0,     0,    80,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
       0,    15,    16,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,     0,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,    77,
       0,     0,    78,    79,     0,     0,    80,     0,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,     0,    15,    16,     0,     0,     0,     0,    17,
     602,     0,     0,     0,     0,     0,     0,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,    77,     0,     0,    78,    79,     0,     0,    80,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90
};

static const short int yycheck[] =
{
       1,   319,   145,   117,   322,    14,    33,   495,    16,    17,
     131,    16,    17,    79,    32,    44,   251,   131,    44,    16,
     163,    39,    40,    41,    42,    33,    46,   260,    33,    37,
       3,    16,    15,    10,    11,   273,    33,    36,   115,     8,
      58,    68,   163,    16,    17,    44,    10,    11,    15,    44,
     127,     0,    76,    30,   292,    28,    41,    42,   201,   152,
      33,    44,   632,   633,    31,   132,   133,    76,    41,    42,
     305,   137,   138,   139,   140,   141,   142,   143,   396,   312,
     109,    76,   175,   109,   654,   655,   229,    27,   231,   107,
     108,   109,   110,   111,   110,   111,   114,   115,   116,   100,
     118,   119,    27,   104,   101,    25,   114,    38,   596,   117,
      28,   131,   117,    44,   115,    38,   117,    24,    25,    26,
     147,    44,   146,   124,   148,   149,   127,   151,   152,    33,
     131,   155,    93,    94,    16,   153,    28,   146,    32,   148,
     149,    12,   151,   152,   145,    79,   155,   148,   149,   150,
     271,   146,    38,   148,   149,    38,   151,   152,    44,   477,
     155,    44,   163,   306,    58,    38,   137,   138,   139,   170,
      32,    44,    34,   174,   160,   161,   177,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     7,    29,   195,   309,   310,    29,    16,    32,
     201,     6,     9,   137,   138,   139,   159,   141,   142,   143,
      18,   212,    16,   107,   108,   109,   217,   108,   219,    32,
     114,   115,   116,    43,   118,   119,   227,    37,   229,   146,
     231,   113,   656,   657,   658,   659,   660,   311,   662,   240,
     137,   138,   139,   140,    33,   246,    34,   134,   249,    24,
     251,    16,   326,   327,   328,   329,   680,     3,   682,    26,
     684,    13,    26,    26,    44,   689,   267,    37,    34,    26,
      29,   114,    16,   274,   592,    13,    37,    39,   392,    16,
      14,    26,    37,    26,   285,   108,    46,    28,   402,   120,
     121,   122,   123,   124,   125,   126,    44,    16,    38,   140,
      16,    23,   303,    38,   305,   306,    37,    37,   309,   310,
      37,    44,    95,    35,   120,   121,   122,   123,   124,   125,
     126,   435,    95,    37,    26,    16,    15,    26,    26,    33,
      45,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,    95,   417,    37,    33,    68,   421,    32,    58,
      16,    16,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    15,    12,    32,    32,    32,    58,   378,    58,    32,
      32,   103,   104,   105,    32,    32,    32,    32,    44,    96,
      44,   392,    16,    16,    37,    32,    38,    38,    32,    38,
     474,   402,    32,   127,    33,    33,    37,    33,    38,    39,
      40,    41,    42,    33,    33,    33,    38,    16,   154,   493,
      26,    26,    26,    44,    32,    26,    95,    95,    58,    16,
      32,   432,    16,    95,   435,   157,   158,    39,    40,    41,
      42,   555,    16,    26,    17,    33,    38,    38,    58,   110,
      32,    37,   131,   555,   212,   530,    58,    39,    40,    41,
      42,   111,    97,   573,   465,   466,   163,   537,   469,   470,
     544,   423,   470,   469,   548,   268,    58,   107,   108,   109,
     110,   111,   647,   422,   114,   115,   116,   646,   118,   119,
     282,   429,   427,   367,   495,   249,   404,   378,   184,   193,
      -1,    -1,   231,   306,    -1,   107,   108,   109,   110,   111,
      -1,    -1,   114,   115,   116,    16,   118,   119,    -1,   520,
     521,    -1,    -1,    -1,    -1,   107,   108,   109,   110,   111,
      -1,    -1,   114,   115,   116,    -1,   118,   119,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,   553,    -1,   555,   556,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,    -1,    -1,    -1,    -1,   596,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,    -1,
     611,   612,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    -1,    -1,    -1,   626,    -1,   628,    -1,    -1,
      -1,     8,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,   650,
      27,    28,    29,    30,    -1,    -1,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    41,    42,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
     107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,
     117,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    32,    -1,   156,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,   150,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     5,    -1,    -1,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    -1,   150,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
      -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,     5,   135,   136,     8,
       9,    10,    11,    12,    -1,    -1,   144,   145,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,   104,   105,    -1,   107,    -1,
      -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,     3,     4,    -1,   135,   136,     8,     9,
      10,    11,    12,    13,    -1,   144,   145,    17,    -1,    19,
      20,    -1,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,    -1,
     110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       3,     4,   132,   133,    -1,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    -1,
      33,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,    -1,   132,
     133,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
     107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    16,    17,    -1,    -1,    20,    -1,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
     104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,
     114,    -1,    -1,   117,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,
     110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
      -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,   104,   105,
      -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,
      -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
     104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    -1,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,
     110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
      -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,
      -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,   104,   105,
      -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,     8,   161,   162,     8,     9,    10,    11,    12,    17,
      20,    21,    22,    23,    27,    29,    30,    35,    36,    43,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    80,    81,    82,    83,    84,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   103,   104,   105,   107,   110,   111,
     114,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   163,   164,   290,     0,    10,    11,   165,   166,    27,
      25,    27,    33,   167,    30,   166,   184,    28,   163,    28,
     168,    12,   169,   174,   163,   185,   186,     7,   189,    29,
      29,   169,    16,   170,    32,   187,    14,    44,   175,   186,
     163,   190,   191,   231,     6,   213,     9,   159,   173,   163,
     188,   186,   175,   191,   192,   214,    16,    18,    24,    25,
      26,    32,   193,   194,     5,    11,    47,   129,   135,   136,
     144,   145,   163,   215,   216,   217,   257,   260,   262,   278,
     171,   163,   163,   163,   195,    34,   194,   108,    43,    33,
      37,   137,   138,   139,   272,   274,    79,   137,   138,   139,
     141,   142,   143,   273,   275,   146,   279,   279,   175,   216,
      34,   134,     3,     4,    13,    31,    33,   102,   106,   132,
     133,   163,   176,   177,   178,   179,   180,    24,    21,    39,
     130,   163,   200,   194,   258,   259,   260,   218,    16,   140,
     274,   140,   275,   163,   260,   181,    19,   178,     3,   163,
      26,   163,    46,   131,   198,   199,    26,    13,   197,    44,
     109,    26,   163,   222,    44,   163,   260,   261,   276,   277,
     276,    37,    34,   221,   132,   133,   182,   228,   229,   230,
     232,   172,   163,   227,    26,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    97,    98,    99,   100,
     128,   234,    29,   114,   163,    16,   196,   259,    39,   220,
     163,   261,    13,    37,    16,    26,    44,    76,   148,   149,
     151,   152,   155,   263,   264,   266,   267,   268,   269,   270,
     271,   279,   270,    16,    28,    33,    37,    41,    42,   114,
     117,   156,   163,   231,   280,   281,   282,   283,   286,   287,
     288,    15,    31,   163,   230,   175,   198,   163,    37,   238,
     238,   120,   121,   122,   123,   124,   125,   126,   245,   246,
     248,   120,   121,   122,   123,   124,   125,   126,   239,   242,
     243,   163,   198,    28,    15,    44,    44,   207,   108,    16,
      21,   163,   223,   225,   226,    38,   261,   277,    33,    68,
     147,   231,    32,   150,   231,   283,   270,   263,   283,   283,
     283,   283,   140,    38,    44,    32,    39,    40,    41,    42,
      58,   107,   108,   109,   110,   111,   114,   115,   116,   118,
     119,    37,   183,   233,    16,    37,   249,    95,   249,    95,
      37,   240,    26,    16,    23,    35,    68,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,   103,   104,   105,   157,
     158,   208,   209,   258,    15,    26,    26,    38,    44,   224,
      45,    95,    33,    33,    32,   150,   231,   153,    14,    38,
     231,   282,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,    58,   283,    37,   283,   284,   285,   232,
     228,    38,    44,    16,   241,   247,   248,   243,   244,    16,
     163,    15,    12,   201,   202,   203,   231,    32,    32,    32,
      58,    58,    32,    32,    32,    32,    93,    94,    32,    32,
      44,   109,    39,   163,    39,   163,    96,   219,   226,   225,
      37,   283,   263,   283,   111,   288,   289,    38,    44,    16,
      38,    38,    32,    32,    36,    44,   206,    16,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,   211,   212,    33,    16,    33,   101,   210,
     163,   163,    33,    37,    33,    33,    33,    33,   209,   127,
     221,    16,   154,   265,   283,    38,    44,   283,    38,    16,
     163,   204,    36,   203,    39,   163,   205,   113,   212,   250,
     251,    26,    26,     3,    16,    17,    28,    33,    41,    42,
     235,   236,   237,    44,   263,   288,    26,   163,    26,    16,
      17,    33,    37,   114,   117,   252,   253,   254,   255,   163,
     163,    95,    95,    16,    16,    38,    44,    95,    16,   163,
      26,   163,   253,   253,   110,   111,    32,    58,   107,   108,
     109,   114,   115,   116,   118,   119,    17,    33,   237,   236,
      38,   163,    38,   253,   253,   254,   254,   254,   254,   254,
      58,   254,    37,   254,   111,   254,   256,   254,    38,    44,
     254
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
        case 2:
#line 114 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 117 "screen.yacc"
    {the_form.dbname=strdup("formonly");}
    break;

  case 4:
#line 118 "screen.yacc"
    {the_form.dbname=(yyvsp[-3].str);
if (A4GLF_open_db(yyvsp[-3].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 123 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 124 "screen.yacc"
    {the_form.dbname=strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 10:
#line 137 "screen.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 13:
#line 143 "screen.yacc"
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
#line 156 "screen.yacc"
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
#line 175 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 18:
#line 177 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 19:
#line 180 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 22:
#line 185 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 25:
#line 192 "screen.yacc"
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

  case 30:
#line 214 "screen.yacc"
    {
	int a;
	static char buff[256];
	strcpy(buff,yyvsp[0].str);
	if (A4GL_isyes(acl_getenv("SPACESCORE"))) {
		for (a=0;a<strlen(buff);a++) {
			if (buff[a]=='_') buff[a]=' ';
		}
	}
	strcpy(yyval.str,buff);
}
    break;

  case 31:
#line 229 "screen.yacc"
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

  case 32:
#line 239 "screen.yacc"
    { ltab=0; }
    break;

  case 33:
#line 240 "screen.yacc"
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

  case 34:
#line 251 "screen.yacc"
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

  case 35:
#line 263 "screen.yacc"
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

  case 36:
#line 276 "screen.yacc"
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

  case 37:
#line 286 "screen.yacc"
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

  case 38:
#line 295 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 39:
#line 300 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 40:
#line 303 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 41:
#line 311 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 42:
#line 312 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 43:
#line 318 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 44:
#line 325 "screen.yacc"
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

  case 45:
#line 339 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 46:
#line 342 "screen.yacc"
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

  case 47:
#line 353 "screen.yacc"
    {
				strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 53:
#line 369 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 54:
#line 376 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 55:
#line 377 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 56:
#line 380 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 57:
#line 381 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 58:
#line 383 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 59:
#line 384 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 60:
#line 385 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 64:
#line 399 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 69:
#line 415 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 70:
#line 419 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 71:
#line 429 "screen.yacc"
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
			//printf("Setting field picture from syscolval (%s)\n",p);
		}
	}

	A4GL_set_field(currftag,fld);
}
    break;

  case 73:
#line 457 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 74:
#line 461 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 75:
#line 469 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 76:
#line 470 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 77:
#line 473 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 78:
#line 474 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 79:
#line 477 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 80:
#line 480 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 81:
#line 485 "screen.yacc"
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

  case 82:
#line 494 "screen.yacc"
    {
	static int xdo=0;
	char buff[256];
	sprintf(buff,"_do_%d",xdo++);
	fld->tabname=strdup("formonly");
	fld->colname=strdup(buff);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 83:
#line 506 "screen.yacc"
    {
	static int di=0;
	char buff[256];
	sprintf(buff,"_di_%d",di++);
	fld->tabname=strdup("formonly");
	fld->colname=strdup(buff);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 84:
#line 518 "screen.yacc"
    {
	//printf("%s %s\n",$<str>1,$<str>3);
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 85:
#line 527 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 86:
#line 535 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 87:
#line 543 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 104:
#line 588 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 105:
#line 589 "screen.yacc"
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

  case 107:
#line 610 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 108:
#line 611 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 109:
#line 612 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 110:
#line 613 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 111:
#line 614 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 112:
#line 615 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 113:
#line 616 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 114:
#line 617 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 115:
#line 618 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 116:
#line 619 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 117:
#line 620 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 118:
#line 621 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 119:
#line 622 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 120:
#line 623 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 121:
#line 625 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 122:
#line 626 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 123:
#line 627 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 124:
#line 628 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 125:
#line 629 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 126:
#line 630 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 127:
#line 631 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 128:
#line 634 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 129:
#line 637 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 133:
#line 641 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 134:
#line 644 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 135:
#line 648 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 136:
#line 654 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 137:
#line 655 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 138:
#line 656 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 140:
#line 661 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str)); }
    break;

  case 141:
#line 665 "screen.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 142:
#line 666 "screen.yacc"
    { strcpy(yyval.str,"4"); }
    break;

  case 143:
#line 667 "screen.yacc"
    { strcpy(yyval.str,"2"); }
    break;

  case 144:
#line 668 "screen.yacc"
    { strcpy(yyval.str,"6"); }
    break;

  case 145:
#line 669 "screen.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 146:
#line 670 "screen.yacc"
    { strcpy(yyval.str,"5"); }
    break;

  case 147:
#line 671 "screen.yacc"
    { strcpy(yyval.str,"7"); }
    break;

  case 148:
#line 672 "screen.yacc"
    { strcpy(yyval.str,"3"); }
    break;

  case 149:
#line 674 "screen.yacc"
    { 
			char *ptr;
			
			ptr=yyvsp[0].str;
			if (strlen(ptr) > 1) {
	        		yyerror("Colour number out of range 0-7");
			}
			if (*ptr>='0'||*ptr<='7') ;
			else {
	        		yyerror("Colour number out of range 0-7");
			}
		strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 150:
#line 688 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 151:
#line 689 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 152:
#line 690 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 153:
#line 691 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 154:
#line 692 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 155:
#line 693 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 156:
#line 694 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 158:
#line 699 "screen.yacc"
    {
}
    break;

  case 164:
#line 709 "screen.yacc"
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

  case 165:
#line 719 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 177:
#line 736 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 178:
#line 739 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 179:
#line 755 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 180:
#line 758 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 183:
#line 768 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 184:
#line 770 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 185:
#line 772 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 186:
#line 774 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 187:
#line 776 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 189:
#line 780 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 190:
#line 784 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 191:
#line 790 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 192:
#line 790 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 195:
#line 797 "screen.yacc"
    {colno++;}
    break;

  case 196:
#line 798 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 197:
#line 811 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 198:
#line 819 "screen.yacc"
    {
	colno+=strlen(yyvsp[0].str);
}
    break;

  case 199:
#line 821 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-2].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 200:
#line 828 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 201:
#line 832 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 202:
#line 836 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 203:
#line 840 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 204:
#line 844 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 205:
#line 848 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 206:
#line 852 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 207:
#line 856 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 208:
#line 860 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 209:
#line 864 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 210:
#line 868 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 211:
#line 872 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 212:
#line 876 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 213:
#line 880 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 214:
#line 883 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 216:
#line 890 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 219:
#line 895 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 220:
#line 900 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 221:
#line 901 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 222:
#line 902 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 223:
#line 903 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 225:
#line 905 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 226:
#line 908 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 227:
#line 912 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 228:
#line 918 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 229:
#line 919 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 230:
#line 920 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 231:
#line 923 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 232:
#line 925 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 233:
#line 931 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 234:
#line 933 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 235:
#line 938 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 236:
#line 946 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 237:
#line 949 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 238:
#line 950 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 239:
#line 951 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 240:
#line 952 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 241:
#line 953 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 242:
#line 954 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 243:
#line 956 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 245:
#line 963 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 246:
#line 964 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 247:
#line 967 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 248:
#line 970 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 249:
#line 974 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 250:
#line 975 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 251:
#line 976 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 252:
#line 977 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 253:
#line 978 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 254:
#line 979 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 255:
#line 981 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 256:
#line 986 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 257:
#line 988 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 258:
#line 995 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 259:
#line 995 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 260:
#line 1001 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 262:
#line 1008 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 263:
#line 1011 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 264:
#line 1017 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 265:
#line 1018 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 266:
#line 1019 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 267:
#line 1020 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 268:
#line 1021 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 269:
#line 1022 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 270:
#line 1023 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 271:
#line 1024 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 272:
#line 1025 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 273:
#line 1026 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 274:
#line 1027 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 275:
#line 1028 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 276:
#line 1029 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 277:
#line 1032 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 278:
#line 1039 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); printf("NUMBER VALUE : %s\n",yyvsp[0].str); }
    break;

  case 279:
#line 1040 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 280:
#line 1041 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 282:
#line 1049 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 283:
#line 1053 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;

  case 342:
#line 1188 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  }
    break;

  case 343:
#line 1189 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  }
    break;

  case 348:
#line 1203 "screen.yacc"
    { void *x; x=create_int_expr(0); yyval.expr=create_expr_comp_expr(x,yyvsp[0].expr,"-"); }
    break;

  case 349:
#line 1205 "screen.yacc"
    { void *x; x=create_int_expr(0); yyval.expr=create_expr_comp_expr(x,yyvsp[0].expr,"+"); }
    break;

  case 350:
#line 1206 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 351:
#line 1207 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 352:
#line 1208 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 353:
#line 1209 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 354:
#line 1210 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 355:
#line 1211 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 356:
#line 1212 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 357:
#line 1213 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 358:
#line 1214 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 359:
#line 1215 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 360:
#line 1216 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 361:
#line 1217 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 362:
#line 1218 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 363:
#line 1219 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 364:
#line 1220 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 365:
#line 1221 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 366:
#line 1222 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 367:
#line 1223 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 368:
#line 1224 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 370:
#line 1230 "screen.yacc"
    { yyval.expr=create_field_expr(yyvsp[0].str); }
    break;

  case 371:
#line 1231 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); }
    break;

  case 372:
#line 1232 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 373:
#line 1233 "screen.yacc"
    { yyval.expr=create_special_expr(yyvsp[0].str); }
    break;

  case 374:
#line 1234 "screen.yacc"
    { yyval.expr=create_special_expr(yyvsp[0].str);}
    break;

  case 375:
#line 1237 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 376:
#line 1241 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 4161 "y.tab.c"

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


#line 1340 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */





