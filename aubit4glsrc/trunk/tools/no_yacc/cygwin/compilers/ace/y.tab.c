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
#define yyparse a4gl_ace_yyparse
#define yylex   a4gl_ace_yylex
#define yyerror a4gl_ace_yyerror
#define yylval  a4gl_ace_yylval
#define yychar  a4gl_ace_yychar
#define yydebug a4gl_ace_yydebug
#define yynerrs a4gl_ace_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     USING = 258,
     MINUS = 259,
     PLUS = 260,
     DIVIDE = 261,
     MULTIPLY = 262,
     AFTER = 263,
     AFTGROUP = 264,
     ALL = 265,
     AND = 266,
     ANY = 267,
     ASC = 268,
     ASCII = 269,
     ATSIGN = 270,
     AVERAGE = 271,
     AVG = 272,
     BEFORE = 273,
     BETWEEN = 274,
     BOTTOM = 275,
     BY = 276,
     KW_CALL = 277,
     CH = 278,
     CHAR = 279,
     CHAR_VALUE = 280,
     CLIPPED = 281,
     CLOSE_BRACKET = 282,
     CLOSE_SQUARE = 283,
     COLON = 284,
     COLUMN = 285,
     COMMA = 286,
     COMMANDS = 287,
     COMPARISON = 288,
     COUNT = 289,
     DATABASE = 290,
     DATE = 291,
     DATETIME = 292,
     DAY = 293,
     DECIMAL = 294,
     DEFINE = 295,
     DELIMITER = 296,
     DESC = 297,
     DISTINCT = 298,
     DO = 299,
     DOLLAR = 300,
     DOT = 301,
     ELSE = 302,
     END = 303,
     EQUAL = 304,
     ESCAPE = 305,
     EVERY = 306,
     EXISTS = 307,
     EXTERNAL = 308,
     FIRST = 309,
     FLOAT = 310,
     PIPE = 311,
     FOR = 312,
     FORMAT = 313,
     FRACTION = 314,
     FROM = 315,
     FUNCTION = 316,
     GREATER_THAN = 317,
     GREATER_THAN_EQ = 318,
     GROUP = 319,
     GROUP_BY = 320,
     HAVING = 321,
     HEADER = 322,
     HOUR = 323,
     IF = 324,
     IN = 325,
     INPUT = 326,
     INTEGER = 327,
     INTERVAL = 328,
     INTO = 329,
     INTVAL = 330,
     IS_NOT_NULL = 331,
     IS_NULL = 332,
     KW_FALSE = 333,
     KW_TRUE = 334,
     LAST = 335,
     LEFT = 336,
     LENGTH = 337,
     LESS_THAN = 338,
     LESS_THAN_EQ = 339,
     LET = 340,
     LIKE = 341,
     LINES = 342,
     MARGIN = 343,
     MATCHES = 344,
     MINUTE = 345,
     MOD = 346,
     MONEY = 347,
     MONTH = 348,
     NAMED = 349,
     NEED = 350,
     NOT = 351,
     NOT_EQUAL = 352,
     NOT_EXISTS = 353,
     NOT_IN = 354,
     NOT_LIKE = 355,
     NOT_MATCHES = 356,
     NUMBER_VALUE = 357,
     NUMERIC = 358,
     OF = 359,
     ON = 360,
     OPEN_BRACKET = 361,
     OPEN_SQUARE = 362,
     OR = 363,
     ORDER_BY = 364,
     ORDER_EXTERNAL_BY = 365,
     OUTER = 366,
     OUTPUT = 367,
     PAGE = 368,
     PAGE_HEADER = 369,
     PAGE_TRAILER = 370,
     PARAM = 371,
     PAUSE = 372,
     PERCENT = 373,
     POW = 374,
     PRINT = 375,
     PRINTER = 376,
     PRINT_FILE = 377,
     PROMPT = 378,
     READ = 379,
     REPORT = 380,
     RIGHT = 381,
     ROW = 382,
     SECOND = 383,
     SELECT = 384,
     SEMICOLON = 385,
     SKIP = 386,
     SMALLFLOAT = 387,
     SMALLINT = 388,
     SOME = 389,
     SPACES = 390,
     STEP = 391,
     SUM = 392,
     TEMP = 393,
     THEN = 394,
     TO = 395,
     TOP = 396,
     TOP_OF_PAGE = 397,
     TOTAL = 398,
     TRAILER = 399,
     UNION = 400,
     UNIQUE = 401,
     UNITS_DAY = 402,
     UNITS_HOUR = 403,
     UNITS_MINUTE = 404,
     UNITS_MONTH = 405,
     UNITS_SECOND = 406,
     UNITS_YEAR = 407,
     UPDATE = 408,
     USER = 409,
     VARCHAR = 410,
     VARIABLE = 411,
     WHERE = 412,
     WHILE = 413,
     WITH_NO_LOG = 414,
     XBEGIN = 415,
     XMAX = 416,
     XMIN = 417,
     YEAR = 418
   };
#endif
#define USING 258
#define MINUS 259
#define PLUS 260
#define DIVIDE 261
#define MULTIPLY 262
#define AFTER 263
#define AFTGROUP 264
#define ALL 265
#define AND 266
#define ANY 267
#define ASC 268
#define ASCII 269
#define ATSIGN 270
#define AVERAGE 271
#define AVG 272
#define BEFORE 273
#define BETWEEN 274
#define BOTTOM 275
#define BY 276
#define KW_CALL 277
#define CH 278
#define CHAR 279
#define CHAR_VALUE 280
#define CLIPPED 281
#define CLOSE_BRACKET 282
#define CLOSE_SQUARE 283
#define COLON 284
#define COLUMN 285
#define COMMA 286
#define COMMANDS 287
#define COMPARISON 288
#define COUNT 289
#define DATABASE 290
#define DATE 291
#define DATETIME 292
#define DAY 293
#define DECIMAL 294
#define DEFINE 295
#define DELIMITER 296
#define DESC 297
#define DISTINCT 298
#define DO 299
#define DOLLAR 300
#define DOT 301
#define ELSE 302
#define END 303
#define EQUAL 304
#define ESCAPE 305
#define EVERY 306
#define EXISTS 307
#define EXTERNAL 308
#define FIRST 309
#define FLOAT 310
#define PIPE 311
#define FOR 312
#define FORMAT 313
#define FRACTION 314
#define FROM 315
#define FUNCTION 316
#define GREATER_THAN 317
#define GREATER_THAN_EQ 318
#define GROUP 319
#define GROUP_BY 320
#define HAVING 321
#define HEADER 322
#define HOUR 323
#define IF 324
#define IN 325
#define INPUT 326
#define INTEGER 327
#define INTERVAL 328
#define INTO 329
#define INTVAL 330
#define IS_NOT_NULL 331
#define IS_NULL 332
#define KW_FALSE 333
#define KW_TRUE 334
#define LAST 335
#define LEFT 336
#define LENGTH 337
#define LESS_THAN 338
#define LESS_THAN_EQ 339
#define LET 340
#define LIKE 341
#define LINES 342
#define MARGIN 343
#define MATCHES 344
#define MINUTE 345
#define MOD 346
#define MONEY 347
#define MONTH 348
#define NAMED 349
#define NEED 350
#define NOT 351
#define NOT_EQUAL 352
#define NOT_EXISTS 353
#define NOT_IN 354
#define NOT_LIKE 355
#define NOT_MATCHES 356
#define NUMBER_VALUE 357
#define NUMERIC 358
#define OF 359
#define ON 360
#define OPEN_BRACKET 361
#define OPEN_SQUARE 362
#define OR 363
#define ORDER_BY 364
#define ORDER_EXTERNAL_BY 365
#define OUTER 366
#define OUTPUT 367
#define PAGE 368
#define PAGE_HEADER 369
#define PAGE_TRAILER 370
#define PARAM 371
#define PAUSE 372
#define PERCENT 373
#define POW 374
#define PRINT 375
#define PRINTER 376
#define PRINT_FILE 377
#define PROMPT 378
#define READ 379
#define REPORT 380
#define RIGHT 381
#define ROW 382
#define SECOND 383
#define SELECT 384
#define SEMICOLON 385
#define SKIP 386
#define SMALLFLOAT 387
#define SMALLINT 388
#define SOME 389
#define SPACES 390
#define STEP 391
#define SUM 392
#define TEMP 393
#define THEN 394
#define TO 395
#define TOP 396
#define TOP_OF_PAGE 397
#define TOTAL 398
#define TRAILER 399
#define UNION 400
#define UNIQUE 401
#define UNITS_DAY 402
#define UNITS_HOUR 403
#define UNITS_MINUTE 404
#define UNITS_MONTH 405
#define UNITS_SECOND 406
#define UNITS_YEAR 407
#define UPDATE 408
#define USER 409
#define VARCHAR 410
#define VARIABLE 411
#define WHERE 412
#define WHILE 413
#define WITH_NO_LOG 414
#define XBEGIN 415
#define XMAX 416
#define XMIN 417
#define YEAR 418




/* Copy the first part of user declarations.  */
#line 1 "ace.yacc"

#define _BISON_SIMPLE_INCL_

/*
=====================================================================
		                    Includes
=====================================================================
*/
#define YYDEBUG 1
#define _NO_YYPARSE_PROTO_
/* #define _NO_YYLEX_PROTO_ */
#include "a4gl_ace_int.h"
#include <ctype.h>

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern struct report this_report;
#ifdef OLD_INCL
	extern int a4gl_status;
#endif
extern int lineno;
extern int colno;
extern int ignorekw;
static char temp_tab_name[256]="";
char *ordby[256];
int ordbycnt=0;
void *memdup(void *p,int l);

#define DUP(x) memdup(&x,sizeof(x))
#define COPY(x,y) memcpy(&x,&y,sizeof(x))

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void add_fmt (int cat, char *col, struct commands commands);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

void *
memdup(void *p,int l)
{
	void *ptr;
	ptr=malloc(l);
	memcpy(ptr,p,l);
	return ptr;
}


void
set_expr_int(struct expr *e,int a)
{
	e->type=EXPRTYPE_INT;
	e->expr_u.i=a;
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
#line 74 "ace.yacc"
typedef union YYSTYPE {
	char	str[30000];
	struct command cmd;
	struct expr expr;
	struct commands commands;
	struct agg_val agg_val;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 487 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 499 "y.tab.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1671

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  122
/* YYNRULES -- Number of rules. */
#define YYNRULES  354
/* YYNRULES -- Number of states. */
#define YYNSTATES  646

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   418

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
     155,   156,   157,   158,   159,   160,   161,   162,   163
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,    10,    14,    18,    19,    21,    25,    27,
      30,    33,    37,    44,    47,    49,    52,    57,    59,    61,
      63,    65,    70,    72,    77,    79,    81,    83,    85,    87,
      89,    91,    96,   103,   105,   110,   117,   118,   120,   124,
     126,   129,   135,   136,   138,   142,   144,   147,   152,   156,
     160,   165,   169,   173,   177,   181,   185,   188,   191,   194,
     196,   200,   205,   206,   209,   214,   218,   219,   221,   223,
     226,   231,   235,   239,   244,   249,   255,   261,   268,   273,
     275,   277,   279,   280,   282,   283,   287,   290,   292,   294,
     296,   298,   301,   304,   307,   310,   311,   315,   317,   321,
     324,   326,   328,   329,   331,   333,   336,   339,   341,   345,
     348,   351,   353,   357,   359,   362,   367,   369,   372,   374,
     378,   383,   384,   386,   387,   389,   390,   392,   394,   398,
     400,   404,   406,   409,   411,   415,   418,   421,   426,   430,
     432,   434,   436,   438,   440,   443,   445,   447,   453,   457,
     463,   467,   469,   473,   474,   476,   480,   484,   488,   492,
     499,   505,   507,   509,   511,   513,   515,   517,   519,   521,
     523,   525,   527,   529,   531,   533,   535,   536,   538,   540,
     542,   544,   546,   550,   554,   556,   558,   559,   563,   569,
     572,   577,   581,   583,   585,   588,   589,   596,   598,   604,
     605,   609,   611,   616,   617,   619,   621,   628,   629,   631,
     633,   635,   637,   641,   643,   646,   648,   650,   652,   654,
     656,   658,   660,   664,   668,   672,   675,   679,   683,   687,
     689,   691,   696,   703,   710,   719,   722,   726,   730,   732,
     734,   736,   738,   742,   747,   752,   757,   762,   767,   772,
     778,   784,   790,   796,   802,   804,   808,   809,   811,   813,
     816,   818,   820,   822,   824,   826,   828,   830,   832,   834,
     836,   840,   846,   848,   850,   852,   854,   856,   866,   867,
     870,   876,   877,   880,   885,   893,   903,   905,   909,   913,
     916,   920,   921,   923,   926,   930,   934,   939,   941,   943,
     945,   947,   949,   953,   956,   961,   963,   965,   969,   973,
     977,   981,   985,   989,   993,   997,  1001,  1005,  1009,  1013,
    1017,  1021,  1023,  1027,  1029,  1031,  1033,  1035,  1040,  1045,
    1050,  1055,  1060,  1064,  1067,  1070,  1073,  1076,  1079,  1082,
    1085,  1087,  1089,  1091,  1093,  1095,  1099,  1100,  1102,  1104,
    1106,  1108,  1111,  1114,  1117
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     165,     0,    -1,   166,   167,   175,   179,   183,   187,    -1,
      35,    14,    48,    -1,    35,    94,    48,    -1,    -1,   168,
      -1,    40,   169,    48,    -1,   170,    -1,   169,   170,    -1,
      14,   172,    -1,   156,   173,   174,    -1,   116,   107,   275,
      28,   173,   174,    -1,    61,   171,    -1,    94,    -1,   173,
     174,    -1,   172,    31,   173,   174,    -1,    94,    -1,    61,
      -1,    72,    -1,    24,    -1,    24,   106,   275,    27,    -1,
     155,    -1,   155,   106,   275,    27,    -1,    36,    -1,    55,
      -1,   132,    -1,   133,    -1,    37,    -1,    73,    -1,    92,
      -1,    92,   106,   275,    27,    -1,    92,   106,   275,    31,
     275,    27,    -1,    39,    -1,    39,   106,   275,    27,    -1,
      39,   106,   275,    31,   275,    27,    -1,    -1,   176,    -1,
      71,   177,    48,    -1,   178,    -1,   177,   178,    -1,   123,
      57,   173,     3,   276,    -1,    -1,   180,    -1,   112,   181,
      48,    -1,   182,    -1,   181,   182,    -1,   125,   140,   121,
     276,    -1,   125,   140,   121,    -1,   125,   140,   276,    -1,
     125,   140,    56,   276,    -1,    81,    88,   275,    -1,    20,
      88,   275,    -1,   141,    88,   275,    -1,   113,    82,   275,
      -1,   126,    88,   275,    -1,   142,   276,    -1,   185,    48,
      -1,   184,    48,    -1,   242,    -1,   184,   130,   242,    -1,
     124,   276,   186,   193,    -1,    -1,    41,   276,    -1,    58,
      51,   127,    48,    -1,    58,   189,   188,    -1,    -1,    48,
      -1,   190,    -1,   189,   190,    -1,    54,   113,    67,   258,
      -1,   113,   144,   258,    -1,   113,    67,   258,    -1,   105,
      51,   127,   258,    -1,   105,    80,   127,   258,    -1,    18,
      64,   104,   192,   258,    -1,     8,    64,   104,   192,   258,
      -1,    94,   107,   278,    31,   278,    28,    -1,    94,   107,
     278,    28,    -1,    94,    -1,   191,    -1,    75,    -1,    -1,
     194,    -1,    -1,   109,   195,   199,    -1,   110,   199,    -1,
      25,    -1,   103,    -1,   241,    -1,    75,    -1,     5,   241,
      -1,     5,    75,    -1,     4,   241,    -1,     4,    75,    -1,
      -1,   109,   198,   199,    -1,   200,    -1,   199,    31,   200,
      -1,   201,   202,    -1,    75,    -1,   239,    -1,    -1,    13,
      -1,    42,    -1,    66,   216,    -1,    65,   205,    -1,   253,
      -1,   205,    31,   253,    -1,   157,   216,    -1,    60,   208,
      -1,   209,    -1,   208,    31,   209,    -1,   210,    -1,   111,
     210,    -1,   111,   106,   211,    27,    -1,   235,    -1,   235,
     240,    -1,   209,    -1,   211,    31,   209,    -1,   207,   213,
     214,   215,    -1,    -1,   206,    -1,    -1,   204,    -1,    -1,
     203,    -1,   217,    -1,   216,   108,   217,    -1,   218,    -1,
     217,    11,   218,    -1,   219,    -1,    96,   219,    -1,   233,
      -1,   106,   216,    27,    -1,    52,   249,    -1,    98,   249,
      -1,   255,   232,   222,   249,    -1,   249,   232,   255,    -1,
     223,    -1,   224,    -1,    10,    -1,   134,    -1,    12,    -1,
      50,   227,    -1,   257,    -1,   257,    -1,   255,    70,   106,
     229,    27,    -1,   255,    70,   249,    -1,   255,    99,   106,
     229,    27,    -1,   255,    99,   249,    -1,   257,    -1,   229,
      31,   257,    -1,    -1,    96,    -1,   255,   230,    77,    -1,
     255,   230,    76,    -1,   255,   232,   255,    -1,   255,   232,
     249,    -1,   255,   230,    19,   255,    11,   255,    -1,   255,
     230,    86,   226,   225,    -1,    49,    -1,    33,    -1,    97,
      -1,    83,    -1,    62,    -1,   101,    -1,   100,    -1,    89,
      -1,    86,    -1,    84,    -1,    63,    -1,   231,    -1,   228,
      -1,   221,    -1,   220,    -1,    -1,    10,    -1,    43,    -1,
     146,    -1,    25,    -1,   237,    -1,   236,    29,   237,    -1,
      25,    46,   237,    -1,   277,    -1,   277,    -1,    -1,   107,
      75,    28,    -1,   107,    75,    31,    75,    28,    -1,   277,
     238,    -1,   235,    46,   277,   238,    -1,   235,    46,     7,
      -1,   277,    -1,   102,    -1,    46,    75,    -1,    -1,   129,
     243,   250,   251,   212,   246,    -1,   245,    -1,   129,   250,
     251,   212,   246,    -1,    -1,   145,   234,   244,    -1,   197,
      -1,    74,   138,   248,   247,    -1,    -1,   159,    -1,   277,
      -1,   106,   129,   250,   251,   212,    27,    -1,    -1,    10,
      -1,    43,    -1,   146,    -1,   252,    -1,   251,    31,   252,
      -1,   255,    -1,   255,    94,    -1,   255,    -1,   152,    -1,
     150,    -1,   147,    -1,   148,    -1,   149,    -1,   151,    -1,
     255,     6,   255,    -1,   255,    91,   255,    -1,   255,   119,
     255,    -1,   255,   254,    -1,   255,     7,   255,    -1,   255,
       5,   255,    -1,   255,     4,   255,    -1,   196,    -1,   277,
      -1,   277,   107,   275,    28,    -1,   277,   107,   275,    31,
     275,    28,    -1,   277,    46,   277,   107,   275,    28,    -1,
     277,    46,   277,   107,   275,    31,   275,    28,    -1,    45,
     277,    -1,   277,    46,   277,    -1,   277,    46,     7,    -1,
      79,    -1,    78,    -1,   154,    -1,     7,    -1,   106,   255,
      27,    -1,    36,   106,   256,    27,    -1,    38,   106,   256,
      27,    -1,    93,   106,   256,    27,    -1,   163,   106,   256,
      27,    -1,   277,   106,   256,    27,    -1,    34,   106,     7,
      27,    -1,    17,   106,   234,   255,    27,    -1,   161,   106,
     234,   255,    27,    -1,   162,   106,   234,   255,    27,    -1,
     137,   106,   234,   255,    27,    -1,    34,   106,   234,   255,
      27,    -1,   255,    -1,   256,    31,   255,    -1,    -1,   196,
      -1,   259,    -1,   258,   259,    -1,   262,    -1,   264,    -1,
     274,    -1,   266,    -1,   268,    -1,   269,    -1,   273,    -1,
     270,    -1,   272,    -1,   260,    -1,   160,   258,    48,    -1,
      22,   261,   106,   282,    27,    -1,    36,    -1,    93,    -1,
     163,    -1,    38,    -1,   277,    -1,    57,   173,    49,   278,
     140,   278,   263,    44,   259,    -1,    -1,   136,   278,    -1,
      69,   278,   139,   259,   265,    -1,    -1,    47,   259,    -1,
      85,    94,    49,   267,    -1,    85,    94,   107,   278,    28,
      49,   267,    -1,    85,    94,   107,   278,    31,   278,    28,
      49,   267,    -1,   278,    -1,   267,    31,   278,    -1,    95,
     275,    87,    -1,   117,   276,    -1,   120,   267,   271,    -1,
      -1,   130,    -1,   122,   276,    -1,   131,   275,    87,    -1,
     131,   140,   142,    -1,   158,   278,    44,   259,    -1,    75,
      -1,    25,    -1,    94,    -1,   281,    -1,   280,    -1,   280,
     157,   278,    -1,    64,   280,    -1,    64,   280,   157,   278,
      -1,    34,    -1,   118,    -1,    16,   104,   278,    -1,   143,
     104,   278,    -1,    17,   104,   278,    -1,   162,   104,   278,
      -1,   161,   104,   278,    -1,   281,     6,   281,    -1,   281,
     119,   281,    -1,   281,    91,   281,    -1,   281,     7,   281,
      -1,   281,     5,   281,    -1,   281,    11,   281,    -1,   281,
     108,   281,    -1,   281,     4,   281,    -1,   281,     3,   281,
      -1,   285,    -1,   281,   232,   281,    -1,    79,    -1,    78,
      -1,   154,    -1,    36,    -1,    36,   106,   283,    27,    -1,
      93,   106,   283,    27,    -1,   163,   106,   283,    27,    -1,
      38,   106,   283,    27,    -1,    94,   106,   283,    27,    -1,
     106,   281,    27,    -1,    30,   281,    -1,    14,   281,    -1,
     281,   135,    -1,   281,    77,    -1,   281,    76,    -1,   281,
      26,    -1,   281,   254,    -1,   191,    -1,   279,    -1,   284,
      -1,   283,    -1,   281,    -1,   283,    31,   281,    -1,    -1,
      25,    -1,   103,    -1,   241,    -1,    75,    -1,     5,   241,
      -1,     5,    75,    -1,     4,   241,    -1,     4,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   244,   244,   252,   255,   264,   266,   271,   275,   275,
     279,   283,   286,   289,   294,   297,   297,   300,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   332,   333,   336,   340,
     340,   343,   348,   348,   351,   354,   354,   358,   359,   360,
     361,   362,   365,   368,   371,   374,   377,   384,   384,   388,
     389,   393,   396,   396,   400,   406,   410,   410,   414,   414,
     418,   422,   426,   430,   434,   438,   442,   450,   451,   452,
     456,   456,   467,   467,   470,   470,   473,   483,   486,   487,
     488,   489,   491,   493,   495,   504,   504,   514,   515,   520,
     522,   527,   534,   535,   536,   541,   547,   552,   553,   558,
     563,   567,   568,   573,   574,   575,   578,   579,   587,   587,
     591,   602,   603,   606,   607,   610,   611,   616,   617,   622,
     623,   628,   629,   634,   635,   641,   642,   647,   649,   656,
     657,   660,   664,   665,   673,   678,   682,   687,   689,   691,
     693,   699,   700,   704,   705,   710,   712,   714,   716,   718,
     720,   727,   728,   729,   730,   731,   732,   733,   734,   735,
     736,   737,   742,   743,   744,   745,   747,   748,   749,   750,
     780,   781,   782,   783,   788,   792,   796,   797,   798,   801,
     802,   803,   809,   814,   814,   829,   829,   847,   850,   857,
     858,   861,   862,   868,   868,   872,   889,   893,   894,   895,
     896,   900,   901,   905,   908,   915,   918,   919,   920,   921,
     922,   923,   927,   929,   931,   933,   935,   937,   939,   941,
     942,   943,   944,   945,   946,   947,   952,   954,   956,   957,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   968,
     970,   972,   974,   976,   982,   982,   988,   989,  1001,  1006,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1065,  1076,  1077,  1078,  1079,  1080,  1083,  1092,  1093,
    1097,  1105,  1108,  1113,  1124,  1135,  1148,  1148,  1160,  1166,
    1173,  1181,  1181,  1184,  1190,  1195,  1202,  1211,  1214,  1218,
    1222,  1226,  1230,  1235,  1239,  1247,  1252,  1257,  1262,  1267,
    1272,  1277,  1285,  1293,  1300,  1309,  1316,  1323,  1331,  1340,
    1347,  1354,  1356,  1363,  1367,  1371,  1375,  1385,  1392,  1398,
    1404,  1411,  1417,  1418,  1424,  1430,  1437,  1443,  1451,  1458,
    1462,  1472,  1478,  1489,  1496,  1503,  1512,  1518,  1522,  1526,
    1530,  1534,  1538,  1542,  1546
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "USING", "MINUS", "PLUS", "DIVIDE", 
  "MULTIPLY", "AFTER", "AFTGROUP", "ALL", "AND", "ANY", "ASC", "ASCII", 
  "ATSIGN", "AVERAGE", "AVG", "BEFORE", "BETWEEN", "BOTTOM", "BY", 
  "KW_CALL", "CH", "CHAR", "CHAR_VALUE", "CLIPPED", "CLOSE_BRACKET", 
  "CLOSE_SQUARE", "COLON", "COLUMN", "COMMA", "COMMANDS", "COMPARISON", 
  "COUNT", "DATABASE", "DATE", "DATETIME", "DAY", "DECIMAL", "DEFINE", 
  "DELIMITER", "DESC", "DISTINCT", "DO", "DOLLAR", "DOT", "ELSE", "END", 
  "EQUAL", "ESCAPE", "EVERY", "EXISTS", "EXTERNAL", "FIRST", "FLOAT", 
  "PIPE", "FOR", "FORMAT", "FRACTION", "FROM", "FUNCTION", "GREATER_THAN", 
  "GREATER_THAN_EQ", "GROUP", "GROUP_BY", "HAVING", "HEADER", "HOUR", 
  "IF", "IN", "INPUT", "INTEGER", "INTERVAL", "INTO", "INTVAL", 
  "IS_NOT_NULL", "IS_NULL", "KW_FALSE", "KW_TRUE", "LAST", "LEFT", 
  "LENGTH", "LESS_THAN", "LESS_THAN_EQ", "LET", "LIKE", "LINES", "MARGIN", 
  "MATCHES", "MINUTE", "MOD", "MONEY", "MONTH", "NAMED", "NEED", "NOT", 
  "NOT_EQUAL", "NOT_EXISTS", "NOT_IN", "NOT_LIKE", "NOT_MATCHES", 
  "NUMBER_VALUE", "NUMERIC", "OF", "ON", "OPEN_BRACKET", "OPEN_SQUARE", 
  "OR", "ORDER_BY", "ORDER_EXTERNAL_BY", "OUTER", "OUTPUT", "PAGE", 
  "PAGE_HEADER", "PAGE_TRAILER", "PARAM", "PAUSE", "PERCENT", "POW", 
  "PRINT", "PRINTER", "PRINT_FILE", "PROMPT", "READ", "REPORT", "RIGHT", 
  "ROW", "SECOND", "SELECT", "SEMICOLON", "SKIP", "SMALLFLOAT", 
  "SMALLINT", "SOME", "SPACES", "STEP", "SUM", "TEMP", "THEN", "TO", 
  "TOP", "TOP_OF_PAGE", "TOTAL", "TRAILER", "UNION", "UNIQUE", 
  "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE", "UNITS_MONTH", 
  "UNITS_SECOND", "UNITS_YEAR", "UPDATE", "USER", "VARCHAR", "VARIABLE", 
  "WHERE", "WHILE", "WITH_NO_LOG", "XBEGIN", "XMAX", "XMIN", "YEAR", 
  "$accept", "ace_report", "db_section", "op_define_section", 
  "define_section", "define_element_list", "define_element", "ufunc_name", 
  "def_ascii_list", "variable", "datatype", "op_input_section", 
  "input_section", "prompt_section", "prompt_element", 
  "op_output_section", "output_section", "output_element_list", 
  "output_element", "select_section", "sec_select_list", "read_list", 
  "op_delim", "format_section", "op_end", "format_actions", 
  "format_action", "variable_sub", "variable_sub_a", 
  "op_order_by_clause_read", "order_by_clause_read", "@1", "literal", 
  "order_by_clause", "@2", "sort_specification_list", 
  "sort_specification", "sort_spec", "op_asc_desc", "having_clause", 
  "group_by_clause", "column_specification_list", "where_clause", 
  "from_clause", "table_reference_list", "table_reference", "tname", 
  "tname_list", "table_expression", "op_where_clause", 
  "op_group_by_clause", "op_having_clause", "search_condition", 
  "boolean_term", "boolean_factor", "boolean_primary", "exists_predicate", 
  "quantified_predicate", "quantifier", "all", "some", "op_escape", 
  "pattern", "escape_character", "in_predicate", "in_value_list", 
  "op_not", "comparison_predicate", "comp_op", "predicate", "op_all", 
  "table_name", "db_name", "table_identifier", "col_arr", "column_name", 
  "correlation_name", "real_number", "select_statement", "@3", 
  "select_statement2", "select_statement2_1", "sel_p2", "op_no_log", 
  "tmp_tabname", "subquery", "op_ad", "sq_select_list", 
  "value_expression_pls", "column_specification", "units_qual", 
  "value_expression", "value_expr_list", "value_specification", 
  "commands", "command", "call_command", "func_identifier", "for_command", 
  "op_step", "if_command", "op_else", "let_command", "expr_concat", 
  "need_command", "pause_command", "print_command", "op_semi", 
  "print_file_command", "skip_command", "while_command", "int_val", 
  "string", "identifier", "expr", "aggregate", "aggregate_elem", 
  "val_expression", "op_val_expr_list", "val_expr_list", "null_expr", 
  "literal_expr", 0
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
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   164,   165,   166,   166,   167,   167,   168,   169,   169,
     170,   170,   170,   170,   171,   172,   172,   173,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   175,   175,   176,   177,
     177,   178,   179,   179,   180,   181,   181,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   183,   183,   184,
     184,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     190,   190,   190,   190,   190,   190,   190,   191,   191,   191,
     192,   192,   193,   193,   195,   194,   194,   196,   196,   196,
     196,   196,   196,   196,   196,   198,   197,   199,   199,   200,
     201,   201,   202,   202,   202,   203,   204,   205,   205,   206,
     207,   208,   208,   209,   209,   209,   210,   210,   211,   211,
     212,   213,   213,   214,   214,   215,   215,   216,   216,   217,
     217,   218,   218,   219,   219,   220,   220,   221,   221,   222,
     222,   223,   224,   224,   225,   226,   227,   228,   228,   228,
     228,   229,   229,   230,   230,   231,   231,   231,   231,   231,
     231,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   233,   233,   233,   233,   234,   234,   234,   234,
     235,   235,   235,   235,   236,   237,   238,   238,   238,   239,
     239,   239,   240,   241,   241,   243,   242,   244,   245,   246,
     246,   246,   246,   247,   247,   248,   249,   250,   250,   250,
     250,   251,   251,   252,   252,   253,   254,   254,   254,   254,
     254,   254,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   256,   256,   257,   257,   258,   258,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   260,   261,   261,   261,   261,   261,   262,   263,   263,
     264,   265,   265,   266,   266,   266,   267,   267,   268,   269,
     270,   271,   271,   272,   273,   273,   274,   275,   276,   277,
     278,   279,   279,   279,   279,   280,   280,   280,   280,   280,
     280,   280,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   282,   282,   283,   283,   284,   285,   285,   285,
     285,   285,   285,   285,   285
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     6,     3,     3,     0,     1,     3,     1,     2,
       2,     3,     6,     2,     1,     2,     4,     1,     1,     1,
       1,     4,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     1,     4,     6,     0,     1,     3,     1,
       2,     5,     0,     1,     3,     1,     2,     4,     3,     3,
       4,     3,     3,     3,     3,     3,     2,     2,     2,     1,
       3,     4,     0,     2,     4,     3,     0,     1,     1,     2,
       4,     3,     3,     4,     4,     5,     5,     6,     4,     1,
       1,     1,     0,     1,     0,     3,     2,     1,     1,     1,
       1,     2,     2,     2,     2,     0,     3,     1,     3,     2,
       1,     1,     0,     1,     1,     2,     2,     1,     3,     2,
       2,     1,     3,     1,     2,     4,     1,     2,     1,     3,
       4,     0,     1,     0,     1,     0,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     2,     2,     4,     3,     1,
       1,     1,     1,     1,     2,     1,     1,     5,     3,     5,
       3,     1,     3,     0,     1,     3,     3,     3,     3,     6,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     0,     3,     5,     2,
       4,     3,     1,     1,     2,     0,     6,     1,     5,     0,
       3,     1,     4,     0,     1,     1,     6,     0,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     2,     3,     3,     3,     1,
       1,     4,     6,     6,     8,     2,     3,     3,     1,     1,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     5,
       5,     5,     5,     5,     1,     3,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     5,     1,     1,     1,     1,     1,     9,     0,     2,
       5,     0,     2,     4,     7,     9,     1,     3,     3,     2,
       3,     0,     1,     2,     3,     3,     4,     1,     1,     1,
       1,     1,     3,     2,     4,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     3,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     2,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     5,     0,     0,     1,     0,    36,     6,
       3,     4,     0,     0,     0,     0,     0,     8,     0,    42,
      37,    17,    10,     0,    14,    13,     0,     0,     7,     9,
       0,     0,    39,     0,     0,    43,     0,    20,    24,    28,
      33,    25,    18,    19,    29,    30,    26,    27,    22,    15,
     297,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,   195,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,    56,    44,    46,    62,   207,
       0,     2,    58,     0,    57,    16,     0,     0,     0,     0,
       0,     0,    52,    51,    54,     0,    48,    49,    55,    53,
       0,    82,   208,   209,   210,     0,     0,     0,     0,     0,
       0,     0,    66,    68,    60,    21,    34,     0,    31,     0,
      23,    12,    41,    50,    47,    63,    84,     0,    61,    83,
       0,     0,   241,     0,    87,     0,     0,     0,     0,     0,
      90,   239,   238,     0,   299,   193,    88,     0,     0,   240,
       0,     0,     0,   229,    89,     0,   211,   213,   230,     0,
       0,     0,     0,     0,     0,     0,     0,    67,    65,    69,
       0,     0,     0,   180,   100,    86,    97,   102,     0,     0,
     181,   101,   186,    94,    93,    92,    91,   176,   176,     0,
       0,   235,   194,     0,     0,   176,   176,   176,     0,     0,
       0,   121,   199,     0,     0,     0,     0,     0,   214,     0,
     218,   219,   220,   217,   221,   216,   225,     0,     0,     0,
       0,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,   258,   269,
     260,   261,   263,   264,   265,   267,   268,   266,   262,    71,
      35,    32,    85,     0,     0,   103,   104,    99,     0,     0,
       0,   189,   177,   178,   179,     0,     0,     0,   254,     0,
       0,     0,   242,     0,     0,     0,     0,   212,     0,   110,
     111,   113,   116,   185,     0,   122,   123,     0,    95,   176,
     201,   196,   228,   227,   222,   226,   223,   224,   237,   236,
       0,     0,    81,    79,    80,     0,     0,    70,    73,    74,
     272,   275,   273,   274,     0,   276,     0,     0,     0,     0,
       0,     0,   347,     0,   305,   326,     0,     0,   350,   324,
     323,     0,    79,   348,     0,   306,     0,   325,     0,     0,
       0,   340,   349,     0,   341,   301,   300,   321,     0,     0,
     289,   291,   286,   293,     0,     0,     0,     0,   259,   183,
     185,    98,   191,   186,   182,     0,     0,   248,     0,   243,
       0,   244,   245,     0,     0,     0,   246,     0,   114,     0,
     117,   192,     0,     0,     0,     0,   109,   127,   129,   131,
     175,   174,   173,   172,   133,     0,   153,     0,   124,   125,
       0,     0,     0,     0,   247,   231,     0,     0,    76,    75,
     346,     0,   354,   353,   352,   351,   334,     0,     0,   333,
       0,     0,   303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   338,   162,
     161,   165,   171,   337,   336,   164,   170,   169,   168,     0,
     163,   167,   166,     0,     0,   335,     0,   339,     0,     0,
     288,     0,   292,   290,   295,   294,     0,   270,   190,   187,
       0,   249,   253,   255,   252,   250,   251,   118,     0,   112,
       0,   135,   132,   136,   207,     0,   153,     0,     0,     0,
       0,   154,     0,     0,     0,   106,   107,   215,     0,   126,
     120,   203,   205,    96,   207,   200,   197,     0,     0,     0,
     344,     0,   343,   342,     0,   307,   309,     0,     0,     0,
       0,     0,   332,   308,   311,   310,     0,   281,   302,   320,
     319,   316,   312,   315,   317,   314,   318,   313,   322,   283,
       0,   287,   296,     0,   115,     0,     0,   134,   128,   130,
     138,   256,   148,   256,   150,     0,   156,   155,   256,   141,
     143,     0,   142,     0,   139,   140,   158,   157,     0,   105,
     204,   202,     0,   233,     0,   232,    78,     0,   271,     0,
       0,   327,   330,   304,   328,   331,   329,     0,   280,     0,
       0,   188,   119,     0,   257,     0,   151,     0,     0,     0,
     145,   137,   108,     0,     0,     0,   345,   278,   282,     0,
       0,     0,   147,   256,   149,     0,   256,   160,   199,   234,
      77,     0,     0,   284,     0,   206,   152,   159,   144,   146,
     198,   279,     0,     0,   277,   285
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   178,   122,   123,   351,   315,   138,
     139,   182,   163,   300,   411,   185,   186,   187,   267,   509,
     408,   505,   295,   211,   289,   290,   291,   488,   212,   296,
     409,   510,   396,   397,   398,   399,   400,   401,   573,   574,
     575,   627,   609,   638,   402,   605,   503,   403,   466,   404,
     275,   292,   189,   190,   271,   191,   390,   352,    70,    89,
     515,   516,   301,   581,   511,   405,   115,   165,   166,   506,
     226,   278,   279,   606,   247,   248,   249,   324,   250,   632,
     251,   598,   252,   361,   253,   254,   255,   473,   256,   257,
     258,    51,    85,   168,   362,   354,   355,   356,   521,   522,
     523,   357
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -566
static const short yypact[] =
{
      -3,    66,    46,   103,     6,   139,  -566,    26,     0,  -566,
    -566,  -566,   130,   138,   140,   130,    -5,  -566,   154,   170,
    -566,  -566,   253,   402,  -566,  -566,   227,   402,  -566,  -566,
     247,    31,  -566,   397,    23,  -566,   130,   203,  -566,  -566,
     242,  -566,  -566,  -566,  -566,   257,  -566,  -566,   265,  -566,
    -566,   348,  -566,   130,  -566,  -566,   286,   297,   309,   252,
     305,   313,   382,   271,  -566,   382,  -566,   362,    14,   374,
    -566,   402,   227,   227,   227,   227,   130,   427,   227,   227,
     227,     8,   227,   227,  -566,  -566,  -566,  -566,   390,     7,
     151,  -566,  -566,   308,  -566,  -566,   415,   287,   294,   422,
     402,   382,  -566,  -566,  -566,   382,   382,  -566,  -566,  -566,
     382,   -40,  -566,  -566,  -566,   916,   395,   406,   338,   368,
     171,    34,    27,  -566,  -566,  -566,  -566,   227,  -566,   227,
    -566,  -566,  -566,  -566,  -566,  -566,  -566,   201,  -566,  -566,
     -10,   198,  -566,   376,  -566,   377,   379,   380,   399,   414,
    -566,  -566,  -566,   385,  -566,  -566,  -566,   916,   386,  -566,
     389,   391,   393,  -566,  -566,   236,  -566,   354,   182,   405,
     407,   469,   451,   392,   394,  1484,  1484,  -566,  -566,  -566,
     497,   499,   201,   481,  -566,   498,  -566,   224,   482,   501,
    -566,  -566,   164,  -566,  -566,  -566,  -566,    18,    17,   916,
     916,  -566,  -566,   916,   429,    18,    18,    18,   916,   916,
      19,   375,    67,   916,   916,   916,   916,   916,  -566,   916,
    -566,  -566,  -566,  -566,  -566,  -566,  -566,    16,   916,   227,
     223,   223,  -566,  1484,  1484,  1484,     3,   130,   558,   439,
     227,   382,   558,   382,    80,   558,  1484,  1484,  -566,  -566,
    -566,  -566,  -566,  -566,  -566,  -566,  -566,  -566,  -566,  1484,
    -566,  -566,   498,   399,   201,  -566,  -566,  -566,    22,   399,
     461,  -566,  -566,  -566,  -566,   916,   515,   916,  1179,   322,
     324,   341,  -566,   916,   916,   916,   346,  -566,    33,   512,
    -566,  -566,   399,   516,   593,  -566,   479,   408,  -566,    18,
    -566,  -566,  1074,  1074,   530,   530,  1179,  1179,  -566,   440,
     359,   183,  -566,   442,  -566,  1484,  1484,  1484,  1484,  1484,
    -566,  -566,  -566,  -566,   444,  -566,   502,   206,   241,   558,
     448,   450,  -566,   558,  -566,   447,   453,    78,  -566,  -566,
    -566,   455,    73,  -566,   558,  -566,   463,  -566,   465,   466,
     460,  -566,  -566,   432,  -566,   425,  1080,  -566,    -7,   486,
    -566,   -16,  -566,  -566,   443,   500,   540,  1407,  -566,  -566,
    -566,  -566,  -566,   488,  -566,   244,   738,  -566,   746,  -566,
     916,  -566,  -566,   754,   998,  1091,  -566,    19,  -566,    19,
    -566,  -566,   480,   773,   480,   462,   485,   578,  -566,  -566,
    -566,  -566,  -566,  -566,  -566,   557,  1361,   916,  -566,   535,
     399,   201,   473,   227,  -566,  -566,   227,   558,  1484,  1484,
     558,   558,  -566,  -566,  -566,  -566,  1080,   558,   558,  1080,
     558,   558,   446,   558,   558,   974,   558,   558,   558,   558,
    1484,   558,   558,   558,   558,   558,   558,   558,  -566,  -566,
    -566,  -566,  -566,  -566,  -566,  -566,  -566,  -566,  -566,   558,
    -566,  -566,  -566,   558,   558,  -566,   558,  -566,   558,   558,
    -566,   558,  -566,  -566,  -566,  -566,  1484,  -566,  -566,  -566,
     532,  -566,  -566,  1179,  -566,  -566,  -566,  -566,   396,  -566,
     476,  -566,  -566,  -566,     7,    25,  1290,   593,   593,   916,
     503,  -566,   505,   217,   693,   577,  -566,  1179,   593,  -566,
    -566,   454,  -566,   498,     7,  -566,  -566,   311,   584,   326,
    1080,   587,   586,  -566,   475,  -566,  -566,   398,   401,   558,
     413,   416,  -566,  -566,  -566,  -566,   423,   579,  -566,  1185,
    1442,  1442,  1519,  1519,  1080,  1080,  1080,  1080,  1080,   597,
     334,  -566,  -566,   602,  -566,    19,   916,  -566,   578,  -566,
    1179,   131,  -566,   131,  -566,   916,  -566,  -566,   204,  -566,
    -566,   836,  -566,   480,  -566,  -566,  -566,  1179,   916,   485,
    -566,  -566,   916,  -566,   227,  -566,  -566,   558,  -566,   558,
     558,  -566,  -566,  -566,  -566,  -566,  -566,  1484,  -566,   583,
     558,  -566,  -566,   236,  -566,   433,  -566,   449,   953,   585,
    -566,  -566,  -566,   236,   606,   614,  1080,   508,  -566,   558,
     619,   621,  -566,   204,  -566,   916,   204,  -566,    67,  -566,
    -566,   558,   609,   597,   601,  -566,  -566,  1179,  -566,  -566,
    -566,  -566,  1484,   558,  -566,   597
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -566,  -566,  -566,  -566,  -566,  -566,   639,  -566,  -566,    -2,
     174,  -566,  -566,  -566,   625,  -566,  -566,  -566,   596,  -566,
    -566,  -566,  -566,  -566,  -566,  -566,   541,    97,   431,  -566,
    -566,  -566,  -300,  -566,  -566,  -170,   403,  -566,  -566,  -566,
    -566,  -566,  -566,  -566,  -566,  -367,   378,  -566,  -565,  -566,
    -566,  -566,  -370,   168,   172,   276,  -566,  -566,  -566,  -566,
    -566,  -566,  -566,  -566,  -566,   110,  -566,  -566,  -338,  -566,
      48,  -133,  -566,    42,   301,  -566,  -566,  -110,   582,  -566,
    -566,  -566,    55,  -566,  -566,  -376,  -406,  -480,   483,   106,
    -210,   -94,   112,  -431,   -85,  -233,  -566,  -566,  -566,  -566,
    -566,  -566,  -566,  -449,  -566,  -566,  -566,  -566,  -566,  -566,
    -566,   -72,   -28,   -65,  -179,  -566,   351,   -64,  -566,   -15,
    -566,  -566
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const short yytable[] =
{
      96,    97,    98,    99,   188,   164,   102,   103,   104,    12,
     108,   109,   262,    27,   368,   471,   491,   112,   493,   549,
     487,   167,   489,   308,   276,   495,   368,   272,   272,   372,
     194,   196,     1,    84,    71,   116,   149,    88,   621,   320,
      12,   321,   468,    28,   183,   117,     6,   164,   628,   188,
     113,    77,   557,   107,    10,   180,    13,   181,   183,   353,
     273,   273,    92,   204,   105,   193,   366,   499,   504,   136,
     137,    18,   192,   132,   100,   177,   603,   133,   134,    54,
       4,   119,   135,   201,   368,   368,   368,    13,   556,   164,
     164,   259,   155,   164,   330,   331,   322,   154,   164,   164,
     469,   175,   613,   164,   164,   164,   164,   164,   582,   164,
     154,    14,   334,   154,   472,   167,   154,   192,   164,   302,
     303,   304,   305,   306,   562,   307,   564,   154,   576,   106,
     288,   188,   120,   497,   368,   140,   141,   610,   579,   387,
     121,   297,    14,     7,    93,   293,   467,    65,   317,   318,
     319,    15,    66,   114,    30,    50,   144,   311,   504,   116,
       5,   367,   309,   274,   274,   164,   323,   164,   359,   117,
     633,   325,   365,   164,   164,   164,   298,   149,   176,   434,
     417,   376,    15,   378,   164,   368,   368,    11,   602,   383,
     384,   385,   636,  -184,   645,   639,   345,   611,   370,   192,
     406,    52,   118,   373,   370,   119,   150,   537,   140,   141,
    -185,   415,   299,   360,   416,   363,   467,   423,   425,   467,
     364,   346,   173,   293,    21,   467,   183,   391,   227,   144,
     418,   419,    24,   155,   156,   326,   565,   265,   519,   348,
     349,   513,   524,   552,   149,    95,   277,    26,   525,   526,
     149,   174,   149,   283,   284,   285,   120,   533,   534,   535,
     494,   604,   538,   604,   121,   426,   266,   209,   604,   429,
     164,   270,   479,   195,   131,   480,   184,    30,   188,   150,
     435,   422,    33,   164,    36,   164,   483,   149,   228,   229,
     550,    56,   551,   566,   567,   154,   210,   164,   312,   406,
     155,   496,    50,   568,    53,   369,   155,   156,   155,    72,
     467,   374,   280,   507,   126,   281,   424,   313,   127,    86,
     286,   128,   293,   604,   293,   129,   604,   314,   314,   467,
     467,   467,   467,   467,   467,   467,   467,   467,   467,   583,
     310,   517,   584,   155,   518,   512,   192,   412,    73,   379,
     593,   381,    57,   380,   586,   380,   520,   587,   213,   214,
     215,   216,   599,    74,   618,   600,   520,   520,   382,   520,
     520,    75,   380,   386,    78,   520,    76,   380,   539,   540,
     541,   542,   543,   544,    58,    79,   414,   164,   164,   164,
     380,    80,    81,    82,   164,   545,    59,    60,   164,   546,
     547,    83,   548,   406,   406,   560,   467,    84,   615,   644,
     577,   617,    61,    62,   406,   527,   528,    56,   530,   531,
      90,   620,    94,   554,   536,   591,    37,   555,   592,   589,
     101,   110,   589,   213,   214,   215,   216,    66,    38,    39,
     594,    40,   125,   595,   589,   217,   164,   589,   218,   130,
     596,   164,   641,   164,   589,   164,   282,    41,   164,   169,
     622,   164,   167,    42,   623,   171,   140,   141,   164,   142,
     170,   608,   164,   219,    43,    44,   624,   204,    57,   143,
     623,   172,   197,   198,   507,   199,   200,   144,   167,   202,
     293,   203,   205,   154,    45,   206,   145,   207,   146,   208,
     147,   220,   221,   222,   223,   224,   225,   148,   149,   230,
      58,   231,   614,   164,   392,   164,   164,   232,   233,   234,
     217,   235,    59,    60,   260,   616,   261,   263,   268,   264,
     269,   637,   294,   358,    46,    47,   375,   150,    61,    62,
     151,   152,   377,   389,   407,  -184,   410,   413,   219,   417,
     420,   421,   427,   430,   428,   153,   154,    48,   393,   431,
     394,   433,   327,   328,   155,   156,   439,   436,   395,   437,
     438,   440,   329,   470,   330,   331,   220,   221,   222,   223,
     224,   225,   441,   332,   476,   474,   490,   475,   333,   498,
     449,   494,   334,   497,   335,   270,   336,   140,   141,   158,
     142,   508,   514,   529,   149,   494,   450,   553,   578,   561,
     143,   563,   585,   580,   588,   590,   159,   589,   144,   451,
     452,   217,   337,   160,   161,   162,   597,   145,   471,   146,
     601,   147,   619,   338,   629,   626,   339,   340,   148,   149,
     455,   456,   630,   457,   631,   392,   458,   634,   635,   219,
     643,   341,   342,   642,   460,    29,    55,   461,   462,    87,
     155,   343,   316,   179,   344,   558,   388,   371,   150,   492,
     559,   151,   152,   607,   478,   124,   345,   220,   221,   222,
     223,   224,   225,   640,   612,     0,   153,   154,   432,   393,
       0,   394,   287,     0,     0,   155,   156,   140,   141,   395,
     142,   346,     0,   569,     0,   570,     0,     0,     0,     0,
     143,     0,   347,     0,     0,     0,     0,     0,   144,   348,
     349,   350,     0,     0,     0,     0,     0,   145,     0,   146,
     158,   147,     0,     0,     0,     0,     0,     0,   148,   149,
       0,     0,   213,   214,   215,   216,     0,   159,     0,     0,
     213,   214,   215,   216,   160,   161,   162,     0,   213,   214,
     215,   216,     0,     0,     0,   481,     0,     0,   150,     0,
       0,   151,   152,   482,     0,     0,     0,   140,   141,     0,
     142,   484,     0,     0,     0,     0,   153,   154,     0,     0,
     143,     0,     0,     0,     0,   155,   156,     0,   144,   571,
       0,     0,     0,     0,     0,     0,     0,   145,     0,   146,
       0,   147,     0,     0,     0,     0,     0,     0,   148,   149,
       0,     0,     0,     0,     0,   392,     0,   572,     0,   217,
     158,     0,     0,     0,     0,     0,     0,   217,     0,     0,
     140,   141,     0,   142,     0,   217,     0,   159,   150,     0,
       0,   151,   152,   143,   160,   161,   162,   219,     0,     0,
       0,   144,     0,     0,     0,   219,   153,   154,     0,     0,
     145,   394,   146,   219,   147,   155,   156,     0,     0,   395,
       0,   148,   149,     0,     0,   220,   221,   222,   223,   224,
     225,     0,     0,   220,   221,   222,   223,   224,   225,     0,
       0,   220,   221,   222,   223,   224,   225,     0,     0,     0,
     158,   150,     0,     0,   151,   152,     0,     0,     0,     0,
     140,   141,     0,   142,     0,     0,     0,   159,     0,   153,
     154,     0,     0,   143,   160,   161,   162,     0,   155,   156,
       0,   144,   157,     0,     0,     0,     0,     0,     0,     0,
     145,     0,   146,     0,   147,     0,     0,   213,   214,   215,
     216,   148,   149,     0,   625,   494,     0,     0,     0,     0,
       0,     0,     0,   158,     0,     0,     0,   442,   443,   444,
     445,   446,     0,     0,     0,   447,     0,     0,     0,     0,
     159,   150,     0,     0,   151,   152,     0,   160,   161,   162,
     448,   532,   213,   214,   215,   216,     0,   449,     0,   153,
     154,     0,     0,     0,     0,     0,     0,     0,   155,   156,
       0,     0,   157,   450,     0,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   451,   452,     0,     0,
       0,     0,     0,     0,   217,     0,     0,     0,     0,     0,
     453,   454,     0,   158,     0,     0,     0,   455,   456,     0,
     457,     0,     0,   458,     0,   459,     0,     0,     0,     0,
     159,   460,   219,     0,   461,   462,     0,   160,   161,   162,
     215,   216,   463,   442,   443,   444,   445,   446,     0,   217,
       0,   447,     0,   464,     0,   213,   214,   215,   216,     0,
     220,   221,   222,   223,   224,   225,   448,     0,     0,   465,
       0,     0,     0,   449,     0,     0,     0,   219,   486,     0,
       0,   220,   221,   222,   223,   224,   225,     0,     0,   450,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   451,   452,     0,   220,   221,   222,   223,   224,
     225,     0,     0,     0,     0,     0,   453,   454,     0,     0,
       0,     0,     0,   455,   456,   217,   457,     0,     0,   458,
       0,   459,     0,     0,     0,     0,     0,   460,     0,     0,
     461,   462,   217,   213,   214,   215,   216,     0,   463,   443,
     444,   445,   446,   219,     0,     0,   447,     0,     0,   464,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     219,   448,     0,     0,     0,   465,     0,     0,   449,     0,
       0,   220,   221,   222,   223,   224,   225,   220,   221,   222,
     223,   224,   225,     0,   450,     0,     0,     0,   220,   221,
     222,   223,   224,   225,     0,     0,     0,   451,   452,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   453,   454,     0,     0,     0,     0,     0,   455,   456,
     217,   457,     0,     0,   458,     0,   459,     0,     0,     0,
       0,     0,   460,     0,     0,   461,   462,     0,     0,     0,
       0,     0,     0,   463,   213,   214,   215,   216,   219,     0,
       0,     0,     0,     0,   464,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
     465,     0,     0,   449,     0,     0,   220,   221,   222,   223,
     224,   225,   220,   221,   222,   223,   224,   225,     0,   450,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   451,   452,     0,     0,     0,     0,     0,     0,
     500,     0,     0,     0,     0,   213,   214,   215,   216,     0,
       0,     0,     0,   455,   456,     0,   457,     0,     0,   458,
       0,   217,     0,     0,     0,     0,   501,   460,     0,   502,
     461,   462,     0,     0,   449,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     450,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   451,   452,     0,     0,     0,     0,   236,
       0,   500,     0,     0,     0,     0,     0,   220,   221,   222,
     223,   224,   225,     0,   455,   456,     0,   457,   445,   446,
     458,     0,   217,   447,     0,   477,     0,   501,   460,     0,
     502,   461,   462,     0,   237,     0,     0,     0,   448,     0,
       0,     0,     0,     0,     0,   449,   238,     0,     0,     0,
     219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   450,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,   451,   452,   236,     0,   220,   221,
     222,   223,   224,   225,     0,     0,     0,     0,   453,   454,
       0,     0,     0,     0,   241,   455,   456,   242,   457,   243,
     447,   458,     0,   459,     0,     0,     0,     0,   244,   460,
       0,   237,   461,   462,     0,   448,     0,     0,     0,     0,
     463,     0,   449,   238,     0,     0,     0,     0,     0,     0,
       0,   464,     0,     0,     0,   245,     0,   246,   450,   239,
       0,     0,     0,     0,     0,     0,     0,   465,     0,   240,
       0,   451,   452,     0,     0,     0,     0,     0,     0,   220,
     221,   222,   223,   224,   225,   453,   454,     0,     0,     0,
       0,   241,   455,   456,   242,   457,   243,     0,   458,     0,
     459,     0,     0,     0,     0,   244,   460,     0,     0,   461,
     462,     0,     0,     0,     0,     0,     0,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,     0,
       0,     0,   245,     0,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   465,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
     224,   225
};

static const short yycheck[] =
{
      72,    73,    74,    75,   137,   115,    78,    79,    80,    14,
      82,    83,   182,    15,   247,    31,   392,    10,   394,   468,
     387,   115,   389,     7,     7,   395,   259,    10,    10,     7,
     140,   141,    35,    25,    36,     8,    46,    65,   603,    36,
      14,    38,    49,    48,    25,    18,     0,   157,   613,   182,
      43,    53,    27,    81,    48,   127,    61,   129,    25,   238,
      43,    43,    48,   157,    56,    75,   245,   405,   406,   109,
     110,    71,   137,   101,    76,    48,   556,   105,   106,    48,
      14,    54,   110,   148,   317,   318,   319,    61,   494,   199,
     200,   176,   102,   203,    16,    17,    93,    94,   208,   209,
     107,    67,   582,   213,   214,   215,   216,   217,   514,   219,
      94,   116,    34,    94,   130,   209,    94,   182,   228,   213,
     214,   215,   216,   217,   500,   219,   502,    94,   504,   121,
     111,   264,   105,   108,   367,     4,     5,   568,   508,   106,
     113,    74,   116,    40,   130,   210,   356,   124,   233,   234,
     235,   156,   129,   146,   123,    75,    25,   229,   496,     8,
      94,   246,   227,   146,   146,   275,   163,   277,   240,    18,
     619,   236,   244,   283,   284,   285,   109,    46,   144,   106,
     107,   275,   156,   277,   294,   418,   419,    48,   555,   283,
     284,   285,   623,    29,   643,   626,   118,   573,   263,   264,
     294,    27,    51,   268,   269,    54,    75,   440,     4,     5,
      46,    28,   145,   241,    31,   243,   426,   327,   328,   429,
     140,   143,    51,   288,    94,   435,    25,   292,    46,    25,
     315,   316,    94,   102,   103,   237,    19,    13,   417,   161,
     162,   411,   421,   476,    46,    71,   198,   107,   427,   428,
      46,    80,    46,   205,   206,   207,   105,   436,   437,   438,
     129,   561,   441,   563,   113,   329,    42,    31,   568,   333,
     380,   107,    28,    75,   100,    31,    75,   123,   411,    75,
     344,    75,   112,   393,    31,   395,   380,    46,   106,   107,
     469,    20,   471,    76,    77,    94,    60,   407,    75,   393,
     102,   395,    75,    86,    57,   263,   102,   103,   102,   106,
     520,   269,   200,   407,    27,   203,    75,    94,    31,    48,
     208,    27,   387,   623,   389,    31,   626,   230,   231,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,    28,
     228,   413,    31,   102,   416,   410,   411,   299,   106,    27,
     529,    27,    81,    31,    28,    31,   420,    31,     4,     5,
       6,     7,    28,   106,   597,    31,   430,   431,    27,   433,
     434,   106,    31,    27,    88,   439,    28,    31,   442,   443,
     444,   445,   446,   447,   113,    88,    27,   497,   498,   499,
      31,    82,   140,    88,   504,   459,   125,   126,   508,   463,
     464,    88,   466,   497,   498,   499,   616,    25,   587,   642,
     504,   590,   141,   142,   508,   430,   431,    20,   433,   434,
      58,   600,    48,    27,   439,    27,    24,    31,    27,    31,
       3,    41,    31,     4,     5,     6,     7,   129,    36,    37,
      27,    39,    27,    27,    31,    91,   556,    31,    94,    27,
      27,   561,   631,   563,    31,   565,    27,    55,   568,    64,
      27,   571,   556,    61,    31,   127,     4,     5,   578,     7,
      64,   565,   582,   119,    72,    73,    27,   571,    81,    17,
      31,   113,   106,   106,   578,   106,   106,    25,   582,    75,
     555,   106,   106,    94,    92,   106,    34,   106,    36,   106,
      38,   147,   148,   149,   150,   151,   152,    45,    46,   104,
     113,   104,   584,   623,    52,   625,   626,    48,    67,   127,
      91,   127,   125,   126,    27,   589,    27,    46,    46,    31,
      29,   625,   157,    94,   132,   133,    75,    75,   141,   142,
      78,    79,    27,    31,    65,    29,   138,   107,   119,   107,
     106,    49,   104,   106,   104,    93,    94,   155,    96,   106,
      98,   106,     4,     5,   102,   103,   106,   104,   106,   104,
     104,   139,    14,    87,    16,    17,   147,   148,   149,   150,
     151,   152,   157,    25,    44,   142,   106,    87,    30,    11,
      33,   129,    34,   108,    36,   107,    38,     4,     5,   137,
       7,    66,   129,   157,    46,   129,    49,    75,    31,   106,
      17,   106,    28,   159,    27,   140,   154,    31,    25,    62,
      63,    91,    64,   161,   162,   163,    47,    34,    31,    36,
      28,    38,    49,    75,    28,    50,    78,    79,    45,    46,
      83,    84,    28,    86,   136,    52,    89,    28,    27,   119,
      49,    93,    94,    44,    97,    16,    31,   100,   101,    63,
     102,   103,   231,   122,   106,   497,   288,   264,    75,   393,
     498,    78,    79,   563,   373,    93,   118,   147,   148,   149,
     150,   151,   152,   628,   578,    -1,    93,    94,   337,    96,
      -1,    98,   209,    -1,    -1,   102,   103,     4,     5,   106,
       7,   143,    -1,    10,    -1,    12,    -1,    -1,    -1,    -1,
      17,    -1,   154,    -1,    -1,    -1,    -1,    -1,    25,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,
     137,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,     4,     5,     6,     7,    -1,   154,    -1,    -1,
       4,     5,     6,     7,   161,   162,   163,    -1,     4,     5,
       6,     7,    -1,    -1,    -1,    27,    -1,    -1,    75,    -1,
      -1,    78,    79,    27,    -1,    -1,    -1,     4,     5,    -1,
       7,    27,    -1,    -1,    -1,    -1,    93,    94,    -1,    -1,
      17,    -1,    -1,    -1,    -1,   102,   103,    -1,    25,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,   134,    -1,    91,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
       4,     5,    -1,     7,    -1,    91,    -1,   154,    75,    -1,
      -1,    78,    79,    17,   161,   162,   163,   119,    -1,    -1,
      -1,    25,    -1,    -1,    -1,   119,    93,    94,    -1,    -1,
      34,    98,    36,   119,    38,   102,   103,    -1,    -1,   106,
      -1,    45,    46,    -1,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,   147,   148,   149,   150,   151,   152,    -1,
      -1,   147,   148,   149,   150,   151,   152,    -1,    -1,    -1,
     137,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
       4,     5,    -1,     7,    -1,    -1,    -1,   154,    -1,    93,
      94,    -1,    -1,    17,   161,   162,   163,    -1,   102,   103,
      -1,    25,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    36,    -1,    38,    -1,    -1,     4,     5,     6,
       7,    45,    46,    -1,    11,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
     154,    75,    -1,    -1,    78,    79,    -1,   161,   162,   163,
      26,    27,     4,     5,     6,     7,    -1,    33,    -1,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
      -1,    -1,   106,    49,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,   137,    -1,    -1,    -1,    83,    84,    -1,
      86,    -1,    -1,    89,    -1,    91,    -1,    -1,    -1,    -1,
     154,    97,   119,    -1,   100,   101,    -1,   161,   162,   163,
       6,     7,   108,     3,     4,     5,     6,     7,    -1,    91,
      -1,    11,    -1,   119,    -1,     4,     5,     6,     7,    -1,
     147,   148,   149,   150,   151,   152,    26,    -1,    -1,   135,
      -1,    -1,    -1,    33,    -1,    -1,    -1,   119,    27,    -1,
      -1,   147,   148,   149,   150,   151,   152,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    91,    86,    -1,    -1,    89,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
     100,   101,    91,     4,     5,     6,     7,    -1,   108,     4,
       5,     6,     7,   119,    -1,    -1,    11,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    26,    -1,    -1,    -1,   135,    -1,    -1,    33,    -1,
      -1,   147,   148,   149,   150,   151,   152,   147,   148,   149,
     150,   151,   152,    -1,    49,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      91,    86,    -1,    -1,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,   108,     4,     5,     6,     7,   119,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
     135,    -1,    -1,    33,    -1,    -1,   147,   148,   149,   150,
     151,   152,   147,   148,   149,   150,   151,   152,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,    89,
      -1,    91,    -1,    -1,    -1,    -1,    96,    97,    -1,    99,
     100,   101,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    22,
      -1,    70,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,    -1,    83,    84,    -1,    86,     6,     7,
      89,    -1,    91,    11,    -1,    48,    -1,    96,    97,    -1,
      99,   100,   101,    -1,    57,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    69,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    62,    63,    22,    -1,   147,   148,
     149,   150,   151,   152,    -1,    -1,    -1,    -1,    76,    77,
      -1,    -1,    -1,    -1,   117,    83,    84,   120,    86,   122,
      11,    89,    -1,    91,    -1,    -1,    -1,    -1,   131,    97,
      -1,    57,   100,   101,    -1,    26,    -1,    -1,    -1,    -1,
     108,    -1,    33,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,    -1,    -1,   158,    -1,   160,    49,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,    95,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,   152,    76,    77,    -1,    -1,    -1,
      -1,   117,    83,    84,   120,    86,   122,    -1,    89,    -1,
      91,    -1,    -1,    -1,    -1,   131,    97,    -1,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,   158,    -1,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,   152
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    35,   165,   166,    14,    94,     0,    40,   167,   168,
      48,    48,    14,    61,   116,   156,   169,   170,    71,   175,
     176,    94,   172,   173,    94,   171,   107,   173,    48,   170,
     123,   177,   178,   112,   179,   180,    31,    24,    36,    37,
      39,    55,    61,    72,    73,    92,   132,   133,   155,   174,
      75,   275,   174,    57,    48,   178,    20,    81,   113,   125,
     126,   141,   142,   181,   182,   124,   129,   183,   184,   185,
     242,   173,   106,   106,   106,   106,    28,   173,    88,    88,
      82,   140,    88,    88,    25,   276,    48,   182,   276,   243,
      58,   187,    48,   130,    48,   174,   275,   275,   275,   275,
     173,     3,   275,   275,   275,    56,   121,   276,   275,   275,
      41,   186,    10,    43,   146,   250,     8,    18,    51,    54,
     105,   113,   189,   190,   242,    27,    27,    31,    27,    31,
      27,   174,   276,   276,   276,   276,   109,   110,   193,   194,
       4,     5,     7,    17,    25,    34,    36,    38,    45,    46,
      75,    78,    79,    93,    94,   102,   103,   106,   137,   154,
     161,   162,   163,   196,   241,   251,   252,   255,   277,    64,
      64,   127,   113,    51,    80,    67,   144,    48,   188,   190,
     275,   275,   195,    25,    75,   199,   200,   201,   235,   236,
     237,   239,   277,    75,   241,    75,   241,   106,   106,   106,
     106,   277,    75,   106,   255,   106,   106,   106,   106,    31,
      60,   207,   212,     4,     5,     6,     7,    91,    94,   119,
     147,   148,   149,   150,   151,   152,   254,    46,   106,   107,
     104,   104,    48,    67,   127,   127,    22,    57,    69,    85,
      95,   117,   120,   122,   131,   158,   160,   258,   259,   260,
     262,   264,   266,   268,   269,   270,   272,   273,   274,   258,
      27,    27,   199,    46,    31,    13,    42,   202,    46,    29,
     107,   238,    10,    43,   146,   234,     7,   234,   255,   256,
     256,   256,    27,   234,   234,   234,   256,   252,   111,   208,
     209,   210,   235,   277,   157,   206,   213,    74,   109,   145,
     197,   246,   255,   255,   255,   255,   255,   255,     7,   277,
     256,   275,    75,    94,   191,   192,   192,   258,   258,   258,
      36,    38,    93,   163,   261,   277,   173,     4,     5,    14,
      16,    17,    25,    30,    34,    36,    38,    64,    75,    78,
      79,    93,    94,   103,   106,   118,   143,   154,   161,   162,
     163,   191,   241,   278,   279,   280,   281,   285,    94,   275,
     276,   267,   278,   276,   140,   275,   278,   258,   259,   237,
     277,   200,     7,   277,   237,    75,   255,    27,   255,    27,
      31,    27,    27,   255,   255,   255,    27,   106,   210,    31,
     240,   277,    52,    96,    98,   106,   216,   217,   218,   219,
     220,   221,   228,   231,   233,   249,   255,    65,   204,   214,
     138,   198,   234,   107,    27,    28,    31,   107,   258,   258,
     106,    49,    75,   241,    75,   241,   281,   104,   104,   281,
     106,   106,   280,   106,   106,   281,   104,   104,   104,   106,
     139,   157,     3,     4,     5,     6,     7,    11,    26,    33,
      49,    62,    63,    76,    77,    83,    84,    86,    89,    91,
      97,   100,   101,   108,   119,   135,   232,   254,    49,   107,
      87,    31,   130,   271,   142,    87,    44,    48,   238,    28,
      31,    27,    27,   255,    27,    27,    27,   209,   211,   209,
     106,   249,   219,   249,   129,   216,   255,   108,    11,   232,
      70,    96,    99,   230,   232,   205,   253,   255,    66,   203,
     215,   248,   277,   199,   129,   244,   245,   275,   275,   278,
     281,   282,   283,   284,   278,   278,   278,   283,   283,   157,
     283,   283,    27,   278,   278,   278,   283,   259,   278,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   267,
     278,   278,   259,    75,    27,    31,   250,    27,   217,   218,
     255,   106,   249,   106,   249,    19,    76,    77,    86,    10,
      12,   106,   134,   222,   223,   224,   249,   255,    31,   216,
     159,   247,   250,    28,    31,    28,    28,    31,    27,    31,
     140,    27,    27,   278,    27,    27,    27,    47,   265,    28,
      31,    28,   209,   251,   196,   229,   257,   229,   255,   226,
     257,   249,   253,   251,   275,   278,   281,   278,   259,    49,
     278,   212,    27,    31,    27,    11,    50,   225,   212,    28,
      28,   136,   263,   267,    28,    27,   257,   255,   227,   257,
     246,   278,    44,    49,   259,   267
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
        case 3:
#line 252 "ace.yacc"
    {
		this_report.dbname=strdup("!!ASCII!!");;
	}
    break;

  case 4:
#line 255 "ace.yacc"
    {
		this_report.dbname=strdup(yyvsp[-1].str);
		A4GLSQL_init_connection (yyvsp[-1].str);
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
    break;

  case 10:
#line 279 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:
#line 283 "ace.yacc"
    {
		ace_add_variable(yyvsp[-1].str,yyvsp[0].str,CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:
#line 286 "ace.yacc"
    {
		ace_add_variable(yyvsp[-1].str,yyvsp[0].str,CAT_PARAM,atoi(yyvsp[-3].str),-1,0);
	}
    break;

  case 13:
#line 289 "ace.yacc"
    {
		add_function(yyvsp[0].str);
	}
    break;

  case 17:
#line 300 "ace.yacc"
    {
	char buff[256];
	int a;
	strcpy(buff,yyvsp[0].str);
	for (a=0;a<strlen(buff);a++) {
		buff[a]=toupper(buff[a]);
	}
	strcpy(yyval.str,buff);
	}
    break;

  case 19:
#line 313 "ace.yacc"
    {strcpy(yyval.str,"INTEGER");}
    break;

  case 20:
#line 314 "ace.yacc"
    {strcpy(yyval.str,"CHAR");}
    break;

  case 21:
#line 315 "ace.yacc"
    {sprintf(yyval.str,"CHAR (%s)",yyvsp[-1].str);}
    break;

  case 22:
#line 316 "ace.yacc"
    {strcpy(yyval.str,"VARCHAR");}
    break;

  case 23:
#line 317 "ace.yacc"
    {sprintf(yyval.str,"VARCHAR (%s)",yyvsp[-1].str);}
    break;

  case 24:
#line 318 "ace.yacc"
    {strcpy(yyval.str,"DATE");}
    break;

  case 25:
#line 319 "ace.yacc"
    {strcpy(yyval.str,"FLOAT");}
    break;

  case 26:
#line 320 "ace.yacc"
    {strcpy(yyval.str,"SMALLFLOAT");}
    break;

  case 27:
#line 321 "ace.yacc"
    {strcpy(yyval.str,"SMALLINT");}
    break;

  case 28:
#line 322 "ace.yacc"
    {strcpy(yyval.str,"DATETIME");}
    break;

  case 29:
#line 323 "ace.yacc"
    {strcpy(yyval.str,"INTERVAL");}
    break;

  case 30:
#line 324 "ace.yacc"
    {strcpy(yyval.str,"MONEY");}
    break;

  case 31:
#line 325 "ace.yacc"
    {sprintf(yyval.str,"MONEY (%s,0)",yyvsp[-1].str);}
    break;

  case 32:
#line 326 "ace.yacc"
    {sprintf(yyval.str,"MONEY (%s,%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 33:
#line 327 "ace.yacc"
    {strcpy(yyval.str,"DECIMAL");}
    break;

  case 34:
#line 328 "ace.yacc"
    {sprintf(yyval.str,"DECIMAL (%s,0)",yyvsp[-1].str);}
    break;

  case 35:
#line 329 "ace.yacc"
    {sprintf(yyval.str,"DECIMAL (%s,%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 41:
#line 343 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes(yyvsp[0].str),yyvsp[-2].str);
}
    break;

  case 47:
#line 358 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=strdup(yyvsp[0].str);}
    break;

  case 48:
#line 359 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:
#line 360 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=strdup(yyvsp[0].str); }
    break;

  case 50:
#line 361 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=strdup(yyvsp[0].str); }
    break;

  case 51:
#line 362 "ace.yacc"
    {
		this_report.output.left_margin=atoi(yyvsp[0].str);
	}
    break;

  case 52:
#line 365 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi(yyvsp[0].str);
	}
    break;

  case 53:
#line 368 "ace.yacc"
    {
		this_report.output.top_margin=atoi(yyvsp[0].str);
	}
    break;

  case 54:
#line 371 "ace.yacc"
    {
		this_report.output.page_length=atoi(yyvsp[0].str);
	}
    break;

  case 55:
#line 374 "ace.yacc"
    {
		this_report.output.right_margin=atoi(yyvsp[0].str);
	}
    break;

  case 56:
#line 377 "ace.yacc"
    {
		this_report.output.top_of_page=strdup(yyvsp[0].str);
	}
    break;

  case 58:
#line 384 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:
#line 388 "ace.yacc"
    { add_select(yyvsp[0].str,temp_tab_name); }
    break;

  case 60:
#line 389 "ace.yacc"
    { add_select(yyvsp[0].str,temp_tab_name); }
    break;

  case 64:
#line 400 "ace.yacc"
    {
		struct commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,"",cmd);
	  }
    break;

  case 70:
#line 419 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,"",yyvsp[0].commands);
	}
    break;

  case 71:
#line 423 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,"",yyvsp[0].commands);
	}
    break;

  case 72:
#line 427 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,"",yyvsp[0].commands);
	}
    break;

  case 73:
#line 431 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,"",yyvsp[0].commands);
	}
    break;

  case 74:
#line 435 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,"",yyvsp[0].commands);
	}
    break;

  case 75:
#line 439 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,yyvsp[-1].str,yyvsp[0].commands);
	}
    break;

  case 76:
#line 443 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,yyvsp[-1].str,yyvsp[0].commands);
	}
    break;

  case 81:
#line 456 "ace.yacc"
    {
int vid;
int a;
a=atoi(yyvsp[0].str);
vid = find_sql_var (a);
sprintf(yyval.str,this_report.variables.variables_val[vid].name);
}
    break;

  case 82:
#line 467 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 84:
#line 470 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:
#line 470 "ace.yacc"
    {
	printf("speclist : %s ",yyvsp[0].str);
	sprintf(yyval.str,"ORDER BY %s",yyvsp[0].str);}
    break;

  case 86:
#line 474 "ace.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 87:
#line 483 "ace.yacc"
    {
		sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
	}
    break;

  case 91:
#line 490 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 92:
#line 492 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 93:
#line 494 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 94:
#line 496 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 95:
#line 504 "ace.yacc"
    {
		ordbycnt=0;
	}
    break;

  case 96:
#line 507 "ace.yacc"
    {
		sprintf(yyval.str,"ORDER BY %s",yyvsp[0].str);
		
	}
    break;

  case 98:
#line 515 "ace.yacc"
    {
sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 100:
#line 522 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"I%d",atoi(yyvsp[0].str));
		ordby[ordbycnt++]=strdup(buff);
	}
    break;

  case 101:
#line 527 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"C%s",yyvsp[0].str);
		ordby[ordbycnt++]=strdup(buff);
	}
    break;

  case 102:
#line 534 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 105:
#line 542 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 106:
#line 548 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 109:
#line 558 "ace.yacc"
    {sprintf(yyval.str,"WHERE \n0 (%s)\n0",yyvsp[0].str);}
    break;

  case 110:
#line 563 "ace.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 112:
#line 569 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 113:
#line 573 "ace.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 114:
#line 574 "ace.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 115:
#line 575 "ace.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 117:
#line 579 "ace.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		ace_add_table(yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 119:
#line 587 "ace.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 120:
#line 595 "ace.yacc"
    {
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 121:
#line 602 "ace.yacc"
    {strcpy(yyval.str,"\n0");}
    break;

  case 123:
#line 606 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 125:
#line 610 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 128:
#line 618 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 130:
#line 624 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 132:
#line 630 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 134:
#line 636 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 135:
#line 641 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 136:
#line 642 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 137:
#line 648 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 138:
#line 650 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 144:
#line 674 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 147:
#line 688 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 148:
#line 690 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 149:
#line 692 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 150:
#line 694 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 152:
#line 701 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 153:
#line 704 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 155:
#line 711 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 156:
#line 713 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 157:
#line 715 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 158:
#line 717 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 159:
#line 719 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 160:
#line 721 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 170:
#line 736 "ace.yacc"
    {sprintf(yyval.str,"<=");}
    break;

  case 171:
#line 737 "ace.yacc"
    {sprintf(yyval.str,">=");}
    break;

  case 176:
#line 747 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 180:
#line 780 "ace.yacc"
    { sprintf(yyval.str," %s",(char *)A4GL_strip_quotes(yyvsp[0].str)); }
    break;

  case 181:
#line 781 "ace.yacc"
    {sprintf(yyval.str,yyvsp[0].str); }
    break;

  case 182:
#line 782 "ace.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);  }
    break;

  case 183:
#line 783 "ace.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str);  }
    break;

  case 185:
#line 792 "ace.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 186:
#line 796 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 187:
#line 797 "ace.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 188:
#line 798 "ace.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 189:
#line 801 "ace.yacc"
    { sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 190:
#line 802 "ace.yacc"
    { sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 191:
#line 803 "ace.yacc"
    { sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 194:
#line 814 "ace.yacc"
    {sprintf(yyval.str,"0.%s",yyvsp[0].str);}
    break;

  case 195:
#line 829 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 196:
#line 832 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 198:
#line 853 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str );}
    break;

  case 199:
#line 857 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 200:
#line 858 "ace.yacc"
    {
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;

  case 202:
#line 862 "ace.yacc"
    {
       sprintf(yyval.str,"INTO TEMP %s%s ",yyvsp[-1].str,yyvsp[0].str);
	strcpy(temp_tab_name,yyvsp[-1].str);
}
    break;

  case 203:
#line 868 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 204:
#line 868 "ace.yacc"
    {strcpy(yyval.str," WITH NO LOG");}
    break;

  case 206:
#line 890 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 207:
#line 893 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 208:
#line 894 "ace.yacc"
    {sprintf(yyval.str,"ALL");}
    break;

  case 209:
#line 895 "ace.yacc"
    {sprintf(yyval.str,"DISTINCT");}
    break;

  case 210:
#line 896 "ace.yacc"
    {sprintf(yyval.str,"DISTINCT");}
    break;

  case 212:
#line 901 "ace.yacc"
    { sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 213:
#line 905 "ace.yacc"
    {
			add_select_column(yyvsp[0].str,yyvsp[0].str);
		}
    break;

  case 214:
#line 908 "ace.yacc"
    {
			sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
			add_select_column(yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 216:
#line 918 "ace.yacc"
    {sprintf(yyval.str,"UNITS YEAR");}
    break;

  case 217:
#line 919 "ace.yacc"
    {sprintf(yyval.str,"UNITS MONTH"); }
    break;

  case 218:
#line 920 "ace.yacc"
    {sprintf(yyval.str,"UNITS DAY);"); }
    break;

  case 219:
#line 921 "ace.yacc"
    {sprintf(yyval.str,"UNITS HOUR);"); }
    break;

  case 220:
#line 922 "ace.yacc"
    {sprintf(yyval.str,"UNITS MINUTE);"); }
    break;

  case 221:
#line 923 "ace.yacc"
    {sprintf(yyval.str,"UNITS SECOND);"); }
    break;

  case 222:
#line 928 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 223:
#line 930 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 224:
#line 932 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 225:
#line 934 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 226:
#line 936 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 227:
#line 938 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 228:
#line 940 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 231:
#line 943 "ace.yacc"
    {sprintf(yyval.str," %s[%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 232:
#line 944 "ace.yacc"
    {sprintf(yyval.str," %s[%s,%s]",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 233:
#line 945 "ace.yacc"
    {sprintf(yyval.str," %s.%s[%s]",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 234:
#line 946 "ace.yacc"
    {sprintf(yyval.str," %s.%s[%s,%s]",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 235:
#line 948 "ace.yacc"
    {
if (find_variable(yyvsp[0].str)==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
sprintf(yyval.str,"\n2(%d)",find_variable(yyvsp[0].str));
}
    break;

  case 236:
#line 953 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 237:
#line 955 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 241:
#line 959 "ace.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 242:
#line 960 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 243:
#line 961 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 244:
#line 962 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 245:
#line 963 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 246:
#line 964 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 247:
#line 965 "ace.yacc"
    {sprintf(yyval.str,"%s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 248:
#line 967 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 249:
#line 969 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 250:
#line 971 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 251:
#line 973 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 252:
#line 975 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 253:
#line 977 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 255:
#line 983 "ace.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 258:
#line 1001 "ace.yacc"
    {
		yyval.commands.commands.commands_len=1;
		yyval.commands.commands.commands_val=malloc(sizeof(struct command));
		COPY(yyval.commands.commands.commands_val[0],yyvsp[0].cmd);
		}
    break;

  case 259:
#line 1006 "ace.yacc"
    {
		COPY(yyval.commands,yyvsp[-1].commands);
		yyval.commands.commands.commands_len++;
		yyval.commands.commands.commands_val=realloc(
		yyval.commands.commands.commands_val,
		yyval.commands.commands.commands_len*sizeof(struct command));
		COPY(yyval.commands.commands.commands_val[ yyval.commands.commands.commands_len-1 ],yyvsp[0].cmd);
	}
    break;

  case 270:
#line 1028 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_BLOCK;
		yyval.cmd.command_u.commands.commands.commands_val=yyvsp[-1].commands.commands.commands_val;
		yyval.cmd.command_u.commands.commands.commands_len=yyvsp[-1].commands.commands.commands_len;
	}
    break;

  case 271:
#line 1065 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_CALL;
		yyval.cmd.command_u.cmd_call.fcall=malloc(sizeof(struct expr_call));
                yyval.cmd.command_u.cmd_call.fcall->fname=strdup(yyvsp[-3].str);
	
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
		print_lexpr( yyval.cmd.command_u.cmd_call.fcall->lexpr);
}
    break;

  case 277:
#line 1083 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_FOR;
		yyval.cmd.command_u.cmd_for.varid=find_variable(yyvsp[-7].str);
		yyval.cmd.command_u.cmd_for.start=yyvsp[-5].expr;
		yyval.cmd.command_u.cmd_for.finish=yyvsp[-3].expr;
		yyval.cmd.command_u.cmd_for.step=yyvsp[-2].expr;
	}
    break;

  case 278:
#line 1092 "ace.yacc"
    { yyval.expr.type=EXPRTYPE_INT; yyval.expr.expr_u.i=1; }
    break;

  case 279:
#line 1093 "ace.yacc"
    { yyval.expr=yyvsp[-1].expr;}
    break;

  case 280:
#line 1097 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_IF;
	yyval.cmd.command_u.cmd_if.condition=yyvsp[-3].expr;
	yyval.cmd.command_u.cmd_if.command=(struct command *)DUP(yyvsp[-1].cmd);
	yyval.cmd.command_u.cmd_if.elsecommand=(struct command *)DUP(yyvsp[0].cmd);
}
    break;

  case 281:
#line 1105 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_NULL;
		yyval.cmd.command_u.null=1;
	}
    break;

  case 282:
#line 1108 "ace.yacc"
    { COPY(yyval.cmd,yyvsp[0].cmd); }
    break;

  case 283:
#line 1113 "ace.yacc"
    {
		int v;
		yyval.cmd.cmd_type=CMD_LET;
		v=find_variable(yyvsp[-2].str);
		yyval.cmd.command_u.cmd_let.varid=v;
		yyval.cmd.command_u.cmd_let.value=yyvsp[0].expr;
		set_expr_int(&yyval.cmd.command_u.cmd_let.sub1,-1);
		set_expr_int(&yyval.cmd.command_u.cmd_let.sub2,-1); 
	}
    break;

  case 284:
#line 1124 "ace.yacc"
    {
		int v;
		yyval.cmd.cmd_type=CMD_LET;
		v=find_variable(yyvsp[-5].str);
		yyval.cmd.command_u.cmd_let.varid=v;
		yyval.cmd.command_u.cmd_let.value=yyvsp[0].expr;
		yyval.cmd.command_u.cmd_let.sub1=yyvsp[-3].expr; 
		yyval.cmd.command_u.cmd_let.sub2=yyvsp[-3].expr; 
	}
    break;

  case 285:
#line 1135 "ace.yacc"
    {
		int v;
		yyval.cmd.cmd_type=CMD_LET;
		v=find_variable(yyvsp[-7].str);
		yyval.cmd.command_u.cmd_let.varid=v;
		yyval.cmd.command_u.cmd_let.value=yyvsp[0].expr;
		yyval.cmd.command_u.cmd_let.sub1=yyvsp[-5].expr; 
		yyval.cmd.command_u.cmd_let.sub2=yyvsp[-3].expr; 
	}
    break;

  case 287:
#line 1148 "ace.yacc"
    {

	yyval.expr.type=EXPRTYPE_COMPLEX;
	yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr));
	COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr);
	COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr);
	yyval.expr.expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 288:
#line 1160 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_NEED;
	yyval.cmd.command_u.cmd_need.nlines=atoi(yyvsp[-1].str);
}
    break;

  case 289:
#line 1166 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PAUSE;
	yyval.cmd.command_u.cmd_pause.message=strdup(yyvsp[0].str);
}
    break;

  case 290:
#line 1173 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PRINT;
	yyval.cmd.command_u.cmd_print.printnl=atoi(yyvsp[0].str);
	yyval.cmd.command_u.cmd_print.print=yyvsp[-1].expr;
}
    break;

  case 291:
#line 1181 "ace.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 292:
#line 1181 "ace.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 293:
#line 1184 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PRINTFILE;
	yyval.cmd.command_u.cmd_printfile.filename=strdup(yyvsp[0].str);
}
    break;

  case 294:
#line 1190 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_SKIP;
		yyval.cmd.command_u.cmd_skip.nlines=atoi(yyvsp[-1].str);

	}
    break;

  case 295:
#line 1195 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_SKIP;
		yyval.cmd.command_u.cmd_skip.nlines=-1;
	}
    break;

  case 296:
#line 1202 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_WHILE;
		yyval.cmd.command_u.cmd_while.condition=yyvsp[-2].expr;
		yyval.cmd.command_u.cmd_while.command=(struct command *)DUP(yyvsp[0].cmd);
}
    break;

  case 301:
#line 1226 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[0].agg_val);
		yyval.agg_val.isgroup=0;
	}
    break;

  case 302:
#line 1230 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[-2].agg_val);
		yyval.agg_val.wexpr=(struct expr *)DUP(yyvsp[0].expr);
		yyval.agg_val.isgroup=0;
	}
    break;

  case 303:
#line 1235 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[0].agg_val);
		yyval.agg_val.isgroup=1;
	}
    break;

  case 304:
#line 1239 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[-2].agg_val);
		yyval.agg_val.wexpr=(struct expr *)DUP(yyvsp[0].expr);
		yyval.agg_val.isgroup=1;
	}
    break;

  case 305:
#line 1247 "ace.yacc"
    {
		yyval.agg_val.type=AGG_COUNT;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=0;
	}
    break;

  case 306:
#line 1252 "ace.yacc"
    {
		yyval.agg_val.type=AGG_PERCENT;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=0;
	}
    break;

  case 307:
#line 1257 "ace.yacc"
    {
		yyval.agg_val.type=AGG_AVG;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 308:
#line 1262 "ace.yacc"
    {
		yyval.agg_val.type=AGG_TOTAL;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 309:
#line 1267 "ace.yacc"
    {
		yyval.agg_val.type=AGG_AVG;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 310:
#line 1272 "ace.yacc"
    {
		yyval.agg_val.type=AGG_MIN;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 311:
#line 1277 "ace.yacc"
    {
		yyval.agg_val.type=AGG_MAX;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 312:
#line 1286 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 313:
#line 1294 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 314:
#line 1301 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 315:
#line 1310 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 316:
#line 1316 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 317:
#line 1323 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 318:
#line 1331 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 319:
#line 1340 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX;
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 320:
#line 1347 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX;
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 321:
#line 1354 "ace.yacc"
    { COPY(yyval.expr,yyvsp[0].expr); }
    break;

  case 322:
#line 1356 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_COMPARE;
		yyval.expr.expr_u.cexpr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.cexpr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.cexpr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.cexpr->method=strdup(yyvsp[-1].str); 
	}
    break;

  case 323:
#line 1363 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=1;
		}
    break;

  case 324:
#line 1367 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0;
		}
    break;

  case 325:
#line 1371 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_BUILTIN;
		yyval.expr.expr_u.name=strdup(yyvsp[0].str);
	}
    break;

  case 326:
#line 1375 "ace.yacc"
    {
		int v;
		v=find_variable("today");
		yyval.expr.type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",yyvsp[0].str);
		} 
		yyval.expr.expr_u.varid=v;
	}
    break;

  case 327:
#line 1385 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("DATE");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 328:
#line 1392 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("MONTH");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 329:
#line 1398 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("YEAR");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 330:
#line 1404 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("DAY");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 331:
#line 1411 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup(yyvsp[-3].str);
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 332:
#line 1417 "ace.yacc"
    { COPY(yyval.expr,yyvsp[-1].expr); }
    break;

  case 333:
#line 1418 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[0].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 334:
#line 1424 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[0].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 335:
#line 1430 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 336:
#line 1437 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 337:
#line 1443 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 338:
#line 1451 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 339:
#line 1458 "ace.yacc"
    {
		printf("NIY\n");
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 340:
#line 1462 "ace.yacc"
    {
		int v;
		v=find_variable(yyvsp[0].str);
		yyval.expr.type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",yyvsp[0].str);
		} 
		yyval.expr.expr_u.varid=v;
	}
    break;

  case 341:
#line 1472 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_AGG; 
		yyval.expr.expr_u.aggid=add_agg(yyvsp[0].agg_val);
	}
    break;

  case 342:
#line 1478 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_LIST;
		yyval.expr.expr_u.lexpr=malloc(sizeof(struct expr_list));
		yyval.expr.expr_u.lexpr->elem.elem_len=1;
		yyval.expr.expr_u.lexpr->elem.elem_val=0;
		yyval.expr.expr_u.lexpr->elem.elem_val=realloc(
			yyval.expr.expr_u.lexpr->elem.elem_val,
			sizeof(struct expr)*yyval.expr.expr_u.lexpr->elem.elem_len);
		COPY(yyval.expr.expr_u.lexpr->elem.elem_val[0],yyvsp[0].expr);
		print_lexpr(yyval.expr.expr_u.lexpr);
	}
    break;

  case 343:
#line 1489 "ace.yacc"
    {
		COPY(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 344:
#line 1496 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_LIST;
		yyval.expr.expr_u.lexpr=malloc(sizeof(struct expr_list));
		yyval.expr.expr_u.lexpr->elem.elem_len=1;
		yyval.expr.expr_u.lexpr->elem.elem_val=0;
		yyval.expr.expr_u.lexpr->elem.elem_val=realloc( yyval.expr.expr_u.lexpr->elem.elem_val,sizeof(struct expr)* yyval.expr.expr_u.lexpr->elem.elem_len);
		COPY(yyval.expr.expr_u.lexpr->elem.elem_val[0],yyvsp[0].expr);
	}
    break;

  case 345:
#line 1503 "ace.yacc"
    {
		COPY(yyval.expr,yyvsp[-2].expr);
		yyval.expr.expr_u.lexpr->elem.elem_len++;
		yyval.expr.expr_u.lexpr->elem.elem_val=realloc( yyval.expr.expr_u.lexpr->elem.elem_val,sizeof(struct expr)* yyval.expr.expr_u.lexpr->elem.elem_len);
		COPY(yyval.expr.expr_u.lexpr->elem.elem_val[ yyval.expr.expr_u.lexpr->elem.elem_len-1 ],yyvsp[0].expr);

	}
    break;

  case 346:
#line 1512 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_NULL;
	}
    break;

  case 347:
#line 1518 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_STRING;
		yyval.expr.expr_u.s=strdup(yyvsp[0].str);
	}
    break;

  case 348:
#line 1522 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_DOUBLE;
		yyval.expr.expr_u.d=atof(yyvsp[0].str);
	}
    break;

  case 349:
#line 1526 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_DOUBLE;
		yyval.expr.expr_u.d=atof(yyvsp[0].str);
	}
    break;

  case 350:
#line 1530 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 351:
#line 1534 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 352:
#line 1538 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 353:
#line 1542 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0-atoi(yyvsp[0].str);
	}
    break;

  case 354:
#line 1546 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0-atoi(yyvsp[0].str);
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3875 "y.tab.c"

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


#line 243 "ace.yacc"



#include "lex.yy.c"


