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
     WHERE = 259,
     OR = 260,
     AND = 261,
     NOT = 262,
     IS_NULL = 263,
     IS_NOT_NULL = 264,
     NOT_EQUAL = 265,
     EQUAL = 266,
     LESS_THAN_EQ = 267,
     LESS_THAN = 268,
     GREATER_THAN_EQ = 269,
     GREATER_THAN = 270,
     NOT_LIKE = 271,
     LIKE = 272,
     NOT_MATCHES = 273,
     MATCHES = 274,
     MINUS = 275,
     PLUS = 276,
     DIVIDE = 277,
     MULTIPLY = 278,
     MOD = 279,
     POWER = 280,
     AFTER = 281,
     AFTGROUP = 282,
     ALL = 283,
     ANY = 284,
     ASC = 285,
     ASCII = 286,
     ATSIGN = 287,
     AVERAGE = 288,
     AVG = 289,
     BEFORE = 290,
     BETWEEN = 291,
     BOTTOM = 292,
     BY = 293,
     KW_CALL = 294,
     CH = 295,
     CHAR = 296,
     CHAR_VALUE = 297,
     CLIPPED = 298,
     CLOSE_BRACKET = 299,
     CLOSE_SQUARE = 300,
     COLON = 301,
     COLUMN = 302,
     COMMA = 303,
     COMMANDS = 304,
     COMPARISON = 305,
     COUNT = 306,
     DATABASE = 307,
     DATE = 308,
     DATETIME = 309,
     DAY = 310,
     DECIMAL = 311,
     DEFINE = 312,
     DELIMITER = 313,
     DESC = 314,
     DISTINCT = 315,
     DO = 316,
     DOLLAR = 317,
     DOT = 318,
     ELSE = 319,
     END = 320,
     ESCAPE = 321,
     EVERY = 322,
     EXISTS = 323,
     EXTERNAL = 324,
     FIRST = 325,
     FLOAT = 326,
     PIPE = 327,
     FOR = 328,
     FORMAT = 329,
     FRACTION = 330,
     FROM = 331,
     FUNCTION = 332,
     GROUP = 333,
     GROUP_BY = 334,
     HAVING = 335,
     HEADER = 336,
     HOUR = 337,
     IF = 338,
     IN = 339,
     INPUT = 340,
     INTEGER = 341,
     INTERVAL = 342,
     INTO = 343,
     INTVAL = 344,
     KW_FALSE = 345,
     KW_TRUE = 346,
     LAST = 347,
     LEFT = 348,
     LENGTH = 349,
     LET = 350,
     LINES = 351,
     MARGIN = 352,
     MINUTE = 353,
     MONEY = 354,
     MONTH = 355,
     NAMED = 356,
     NEED = 357,
     NOT_EXISTS = 358,
     NOT_IN = 359,
     NUMBER_VALUE = 360,
     NUMERIC = 361,
     OF = 362,
     ON = 363,
     OPEN_BRACKET = 364,
     OPEN_SQUARE = 365,
     ORDER_BY = 366,
     ORDER_EXTERNAL_BY = 367,
     OUTER = 368,
     OUTPUT = 369,
     PAGE = 370,
     PAGE_HEADER = 371,
     PAGE_TRAILER = 372,
     PARAM = 373,
     PAUSE = 374,
     PERCENT = 375,
     POW = 376,
     PRINT = 377,
     PRINTER = 378,
     PRINT_FILE = 379,
     PROMPT = 380,
     READ = 381,
     REPORT = 382,
     RIGHT = 383,
     ROW = 384,
     SECOND = 385,
     SELECT = 386,
     SEMICOLON = 387,
     SKIP = 388,
     SMALLFLOAT = 389,
     SMALLINT = 390,
     SOME = 391,
     SPACES = 392,
     STEP = 393,
     SUM = 394,
     TEMP = 395,
     THEN = 396,
     TO = 397,
     TOP = 398,
     TOP_OF_PAGE = 399,
     TOTAL = 400,
     TRAILER = 401,
     UNION = 402,
     UNIQUE = 403,
     UNITS_DAY = 404,
     UNITS_HOUR = 405,
     UNITS_MINUTE = 406,
     UNITS_MONTH = 407,
     UNITS_SECOND = 408,
     UNITS_YEAR = 409,
     UPDATE = 410,
     USER = 411,
     VARCHAR = 412,
     VARIABLE = 413,
     WHILE = 414,
     WITH_NO_LOG = 415,
     XBEGIN = 416,
     XMAX = 417,
     XMIN = 418,
     YEAR = 419
   };
#endif
#define USING 258
#define WHERE 259
#define OR 260
#define AND 261
#define NOT 262
#define IS_NULL 263
#define IS_NOT_NULL 264
#define NOT_EQUAL 265
#define EQUAL 266
#define LESS_THAN_EQ 267
#define LESS_THAN 268
#define GREATER_THAN_EQ 269
#define GREATER_THAN 270
#define NOT_LIKE 271
#define LIKE 272
#define NOT_MATCHES 273
#define MATCHES 274
#define MINUS 275
#define PLUS 276
#define DIVIDE 277
#define MULTIPLY 278
#define MOD 279
#define POWER 280
#define AFTER 281
#define AFTGROUP 282
#define ALL 283
#define ANY 284
#define ASC 285
#define ASCII 286
#define ATSIGN 287
#define AVERAGE 288
#define AVG 289
#define BEFORE 290
#define BETWEEN 291
#define BOTTOM 292
#define BY 293
#define KW_CALL 294
#define CH 295
#define CHAR 296
#define CHAR_VALUE 297
#define CLIPPED 298
#define CLOSE_BRACKET 299
#define CLOSE_SQUARE 300
#define COLON 301
#define COLUMN 302
#define COMMA 303
#define COMMANDS 304
#define COMPARISON 305
#define COUNT 306
#define DATABASE 307
#define DATE 308
#define DATETIME 309
#define DAY 310
#define DECIMAL 311
#define DEFINE 312
#define DELIMITER 313
#define DESC 314
#define DISTINCT 315
#define DO 316
#define DOLLAR 317
#define DOT 318
#define ELSE 319
#define END 320
#define ESCAPE 321
#define EVERY 322
#define EXISTS 323
#define EXTERNAL 324
#define FIRST 325
#define FLOAT 326
#define PIPE 327
#define FOR 328
#define FORMAT 329
#define FRACTION 330
#define FROM 331
#define FUNCTION 332
#define GROUP 333
#define GROUP_BY 334
#define HAVING 335
#define HEADER 336
#define HOUR 337
#define IF 338
#define IN 339
#define INPUT 340
#define INTEGER 341
#define INTERVAL 342
#define INTO 343
#define INTVAL 344
#define KW_FALSE 345
#define KW_TRUE 346
#define LAST 347
#define LEFT 348
#define LENGTH 349
#define LET 350
#define LINES 351
#define MARGIN 352
#define MINUTE 353
#define MONEY 354
#define MONTH 355
#define NAMED 356
#define NEED 357
#define NOT_EXISTS 358
#define NOT_IN 359
#define NUMBER_VALUE 360
#define NUMERIC 361
#define OF 362
#define ON 363
#define OPEN_BRACKET 364
#define OPEN_SQUARE 365
#define ORDER_BY 366
#define ORDER_EXTERNAL_BY 367
#define OUTER 368
#define OUTPUT 369
#define PAGE 370
#define PAGE_HEADER 371
#define PAGE_TRAILER 372
#define PARAM 373
#define PAUSE 374
#define PERCENT 375
#define POW 376
#define PRINT 377
#define PRINTER 378
#define PRINT_FILE 379
#define PROMPT 380
#define READ 381
#define REPORT 382
#define RIGHT 383
#define ROW 384
#define SECOND 385
#define SELECT 386
#define SEMICOLON 387
#define SKIP 388
#define SMALLFLOAT 389
#define SMALLINT 390
#define SOME 391
#define SPACES 392
#define STEP 393
#define SUM 394
#define TEMP 395
#define THEN 396
#define TO 397
#define TOP 398
#define TOP_OF_PAGE 399
#define TOTAL 400
#define TRAILER 401
#define UNION 402
#define UNIQUE 403
#define UNITS_DAY 404
#define UNITS_HOUR 405
#define UNITS_MINUTE 406
#define UNITS_MONTH 407
#define UNITS_SECOND 408
#define UNITS_YEAR 409
#define UPDATE 410
#define USER 411
#define VARCHAR 412
#define VARIABLE 413
#define WHILE 414
#define WITH_NO_LOG 415
#define XBEGIN 416
#define XMAX 417
#define XMIN 418
#define YEAR 419




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
#line 490 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 502 "y.tab.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1470

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  122
/* YYNRULES -- Number of rules. */
#define YYNRULES  354
/* YYNRULES -- Number of states. */
#define YYNSTATES  646

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
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
static const short int yyrhs[] =
{
     166,     0,    -1,   167,   168,   176,   180,   184,   188,    -1,
      52,    31,    65,    -1,    52,   101,    65,    -1,    -1,   169,
      -1,    57,   170,    65,    -1,   171,    -1,   170,   171,    -1,
      31,   173,    -1,   158,   174,   175,    -1,   118,   110,   276,
      45,   174,   175,    -1,    77,   172,    -1,   101,    -1,   174,
     175,    -1,   173,    48,   174,   175,    -1,   101,    -1,    77,
      -1,    86,    -1,    41,    -1,    41,   109,   276,    44,    -1,
     157,    -1,   157,   109,   276,    44,    -1,    53,    -1,    71,
      -1,   134,    -1,   135,    -1,    54,    -1,    87,    -1,    99,
      -1,    99,   109,   276,    44,    -1,    99,   109,   276,    48,
     276,    44,    -1,    56,    -1,    56,   109,   276,    44,    -1,
      56,   109,   276,    48,   276,    44,    -1,    -1,   177,    -1,
      85,   178,    65,    -1,   179,    -1,   178,   179,    -1,   125,
      73,   174,     3,   277,    -1,    -1,   181,    -1,   114,   182,
      65,    -1,   183,    -1,   182,   183,    -1,   127,   142,   123,
     277,    -1,   127,   142,   123,    -1,   127,   142,   277,    -1,
     127,   142,    72,   277,    -1,    93,    97,   276,    -1,    37,
      97,   276,    -1,   143,    97,   276,    -1,   115,    94,   276,
      -1,   128,    97,   276,    -1,   144,   277,    -1,   186,    65,
      -1,   185,    65,    -1,   243,    -1,   185,   132,   243,    -1,
     126,   277,   187,   194,    -1,    -1,    58,   277,    -1,    74,
      67,   129,    65,    -1,    74,   190,   189,    -1,    -1,    65,
      -1,   191,    -1,   190,   191,    -1,    70,   115,    81,   259,
      -1,   115,   146,   259,    -1,   115,    81,   259,    -1,   108,
      67,   129,   259,    -1,   108,    92,   129,   259,    -1,    35,
      78,   107,   193,   259,    -1,    26,    78,   107,   193,   259,
      -1,   101,   110,   279,    48,   279,    45,    -1,   101,   110,
     279,    45,    -1,   101,    -1,   192,    -1,    89,    -1,    -1,
     195,    -1,    -1,   111,   196,   200,    -1,   112,   200,    -1,
      42,    -1,   106,    -1,   242,    -1,    89,    -1,    21,   242,
      -1,    21,    89,    -1,    20,   242,    -1,    20,    89,    -1,
      -1,   111,   199,   200,    -1,   201,    -1,   200,    48,   201,
      -1,   202,   203,    -1,    89,    -1,   240,    -1,    -1,    30,
      -1,    59,    -1,    80,   217,    -1,    79,   206,    -1,   254,
      -1,   206,    48,   254,    -1,     4,   217,    -1,    76,   209,
      -1,   210,    -1,   209,    48,   210,    -1,   211,    -1,   113,
     211,    -1,   113,   109,   212,    44,    -1,   236,    -1,   236,
     241,    -1,   210,    -1,   212,    48,   210,    -1,   208,   214,
     215,   216,    -1,    -1,   207,    -1,    -1,   205,    -1,    -1,
     204,    -1,   218,    -1,   217,     5,   218,    -1,   219,    -1,
     218,     6,   219,    -1,   220,    -1,     7,   220,    -1,   234,
      -1,   109,   217,    44,    -1,    68,   250,    -1,   103,   250,
      -1,   256,   233,   223,   250,    -1,   250,   233,   256,    -1,
     224,    -1,   225,    -1,    28,    -1,   136,    -1,    29,    -1,
      66,   228,    -1,   258,    -1,   258,    -1,   256,    84,   109,
     230,    44,    -1,   256,    84,   250,    -1,   256,   104,   109,
     230,    44,    -1,   256,   104,   250,    -1,   258,    -1,   230,
      48,   258,    -1,    -1,     7,    -1,   256,   231,     8,    -1,
     256,   231,     9,    -1,   256,   233,   256,    -1,   256,   233,
     250,    -1,   256,   231,    36,   256,     6,   256,    -1,   256,
     231,    17,   227,   226,    -1,    11,    -1,    50,    -1,    10,
      -1,    13,    -1,    15,    -1,    18,    -1,    16,    -1,    19,
      -1,    17,    -1,    12,    -1,    14,    -1,   232,    -1,   229,
      -1,   222,    -1,   221,    -1,    -1,    28,    -1,    60,    -1,
     148,    -1,    42,    -1,   238,    -1,   237,    46,   238,    -1,
      42,    63,   238,    -1,   278,    -1,   278,    -1,    -1,   110,
      89,    45,    -1,   110,    89,    48,    89,    45,    -1,   278,
     239,    -1,   236,    63,   278,   239,    -1,   236,    63,    23,
      -1,   278,    -1,   105,    -1,    63,    89,    -1,    -1,   131,
     244,   251,   252,   213,   247,    -1,   246,    -1,   131,   251,
     252,   213,   247,    -1,    -1,   147,   235,   245,    -1,   198,
      -1,    88,   140,   249,   248,    -1,    -1,   160,    -1,   278,
      -1,   109,   131,   251,   252,   213,    44,    -1,    -1,    28,
      -1,    60,    -1,   148,    -1,   253,    -1,   252,    48,   253,
      -1,   256,    -1,   256,   101,    -1,   256,    -1,   154,    -1,
     152,    -1,   149,    -1,   150,    -1,   151,    -1,   153,    -1,
     256,    22,   256,    -1,   256,    24,   256,    -1,   256,   121,
     256,    -1,   256,   255,    -1,   256,    23,   256,    -1,   256,
      21,   256,    -1,   256,    20,   256,    -1,   197,    -1,   278,
      -1,   278,   110,   276,    45,    -1,   278,   110,   276,    48,
     276,    45,    -1,   278,    63,   278,   110,   276,    45,    -1,
     278,    63,   278,   110,   276,    48,   276,    45,    -1,    62,
     278,    -1,   278,    63,   278,    -1,   278,    63,    23,    -1,
      91,    -1,    90,    -1,   156,    -1,    23,    -1,   109,   256,
      44,    -1,    53,   109,   257,    44,    -1,    55,   109,   257,
      44,    -1,   100,   109,   257,    44,    -1,   164,   109,   257,
      44,    -1,   278,   109,   257,    44,    -1,    51,   109,    23,
      44,    -1,    34,   109,   235,   256,    44,    -1,   162,   109,
     235,   256,    44,    -1,   163,   109,   235,   256,    44,    -1,
     139,   109,   235,   256,    44,    -1,    51,   109,   235,   256,
      44,    -1,   256,    -1,   257,    48,   256,    -1,    -1,   197,
      -1,   260,    -1,   259,   260,    -1,   263,    -1,   265,    -1,
     275,    -1,   267,    -1,   269,    -1,   270,    -1,   274,    -1,
     271,    -1,   273,    -1,   261,    -1,   161,   259,    65,    -1,
      39,   262,   109,   283,    44,    -1,    53,    -1,   100,    -1,
     164,    -1,    55,    -1,   278,    -1,    73,   174,    11,   279,
     142,   279,   264,    61,   260,    -1,    -1,   138,   279,    -1,
      83,   279,   141,   260,   266,    -1,    -1,    64,   260,    -1,
      95,   101,    11,   268,    -1,    95,   101,   110,   279,    45,
      11,   268,    -1,    95,   101,   110,   279,    48,   279,    45,
      11,   268,    -1,   279,    -1,   268,    48,   279,    -1,   102,
     276,    96,    -1,   119,   277,    -1,   122,   268,   272,    -1,
      -1,   132,    -1,   124,   277,    -1,   133,   276,    96,    -1,
     133,   142,   144,    -1,   159,   279,    61,   260,    -1,    89,
      -1,    42,    -1,   101,    -1,   282,    -1,   281,    -1,   281,
       4,   279,    -1,    78,   281,    -1,    78,   281,     4,   279,
      -1,    51,    -1,   120,    -1,    33,   107,   279,    -1,   145,
     107,   279,    -1,    34,   107,   279,    -1,   163,   107,   279,
      -1,   162,   107,   279,    -1,   282,    22,   282,    -1,   282,
     121,   282,    -1,   282,    24,   282,    -1,   282,    23,   282,
      -1,   282,    21,   282,    -1,   282,     6,   282,    -1,   282,
       5,   282,    -1,   282,    20,   282,    -1,   282,     3,   282,
      -1,   286,    -1,   282,   233,   282,    -1,    91,    -1,    90,
      -1,   156,    -1,    53,    -1,    53,   109,   284,    44,    -1,
     100,   109,   284,    44,    -1,   164,   109,   284,    44,    -1,
      55,   109,   284,    44,    -1,   101,   109,   284,    44,    -1,
     109,   282,    44,    -1,    47,   282,    -1,    31,   282,    -1,
     282,   137,    -1,   282,     8,    -1,   282,     9,    -1,   282,
      43,    -1,   282,   255,    -1,   192,    -1,   280,    -1,   285,
      -1,   284,    -1,   282,    -1,   284,    48,   282,    -1,    -1,
      42,    -1,   106,    -1,   242,    -1,    89,    -1,    21,   242,
      -1,    21,    89,    -1,    20,   242,    -1,    20,    89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   239,   239,   247,   250,   259,   261,   266,   270,   270,
     274,   278,   281,   284,   289,   292,   292,   295,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   327,   328,   331,   335,
     335,   338,   343,   343,   346,   349,   349,   353,   354,   355,
     356,   357,   360,   363,   366,   369,   372,   379,   379,   383,
     384,   388,   391,   391,   395,   401,   405,   405,   409,   409,
     413,   417,   421,   425,   429,   433,   437,   445,   446,   447,
     451,   451,   462,   462,   465,   465,   468,   478,   481,   482,
     483,   484,   486,   488,   490,   499,   499,   509,   510,   515,
     517,   522,   529,   530,   531,   536,   542,   547,   548,   553,
     558,   562,   563,   568,   569,   570,   573,   574,   582,   582,
     586,   597,   598,   601,   602,   605,   606,   611,   612,   617,
     618,   623,   624,   629,   630,   636,   637,   642,   644,   651,
     652,   655,   659,   660,   668,   673,   677,   682,   684,   686,
     688,   694,   695,   699,   700,   705,   707,   709,   711,   713,
     715,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   737,   738,   739,   740,   742,   743,   744,   745,
     775,   776,   777,   778,   783,   787,   791,   792,   793,   796,
     797,   798,   804,   809,   809,   824,   824,   842,   845,   852,
     853,   856,   857,   863,   863,   867,   884,   888,   889,   890,
     891,   895,   896,   900,   903,   910,   913,   914,   915,   916,
     917,   918,   922,   924,   926,   928,   930,   932,   934,   936,
     937,   938,   939,   940,   941,   942,   947,   949,   951,   952,
     953,   954,   955,   956,   957,   958,   959,   960,   961,   963,
     965,   967,   969,   971,   977,   977,   983,   984,   996,  1001,
    1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1060,  1071,  1072,  1073,  1074,  1075,  1078,  1087,  1088,
    1092,  1100,  1103,  1108,  1119,  1130,  1143,  1143,  1155,  1161,
    1168,  1176,  1176,  1179,  1185,  1190,  1197,  1206,  1209,  1213,
    1217,  1221,  1225,  1230,  1234,  1242,  1247,  1252,  1257,  1262,
    1267,  1272,  1280,  1288,  1295,  1304,  1311,  1318,  1326,  1335,
    1342,  1349,  1351,  1358,  1362,  1366,  1370,  1380,  1387,  1393,
    1399,  1406,  1412,  1413,  1419,  1425,  1432,  1438,  1446,  1453,
    1457,  1467,  1473,  1484,  1491,  1498,  1507,  1513,  1517,  1521,
    1525,  1529,  1533,  1537,  1541
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "USING", "WHERE", "OR", "AND", "NOT",
  "IS_NULL", "IS_NOT_NULL", "NOT_EQUAL", "EQUAL", "LESS_THAN_EQ",
  "LESS_THAN", "GREATER_THAN_EQ", "GREATER_THAN", "NOT_LIKE", "LIKE",
  "NOT_MATCHES", "MATCHES", "MINUS", "PLUS", "DIVIDE", "MULTIPLY", "MOD",
  "POWER", "AFTER", "AFTGROUP", "ALL", "ANY", "ASC", "ASCII", "ATSIGN",
  "AVERAGE", "AVG", "BEFORE", "BETWEEN", "BOTTOM", "BY", "KW_CALL", "CH",
  "CHAR", "CHAR_VALUE", "CLIPPED", "CLOSE_BRACKET", "CLOSE_SQUARE",
  "COLON", "COLUMN", "COMMA", "COMMANDS", "COMPARISON", "COUNT",
  "DATABASE", "DATE", "DATETIME", "DAY", "DECIMAL", "DEFINE", "DELIMITER",
  "DESC", "DISTINCT", "DO", "DOLLAR", "DOT", "ELSE", "END", "ESCAPE",
  "EVERY", "EXISTS", "EXTERNAL", "FIRST", "FLOAT", "PIPE", "FOR", "FORMAT",
  "FRACTION", "FROM", "FUNCTION", "GROUP", "GROUP_BY", "HAVING", "HEADER",
  "HOUR", "IF", "IN", "INPUT", "INTEGER", "INTERVAL", "INTO", "INTVAL",
  "KW_FALSE", "KW_TRUE", "LAST", "LEFT", "LENGTH", "LET", "LINES",
  "MARGIN", "MINUTE", "MONEY", "MONTH", "NAMED", "NEED", "NOT_EXISTS",
  "NOT_IN", "NUMBER_VALUE", "NUMERIC", "OF", "ON", "OPEN_BRACKET",
  "OPEN_SQUARE", "ORDER_BY", "ORDER_EXTERNAL_BY", "OUTER", "OUTPUT",
  "PAGE", "PAGE_HEADER", "PAGE_TRAILER", "PARAM", "PAUSE", "PERCENT",
  "POW", "PRINT", "PRINTER", "PRINT_FILE", "PROMPT", "READ", "REPORT",
  "RIGHT", "ROW", "SECOND", "SELECT", "SEMICOLON", "SKIP", "SMALLFLOAT",
  "SMALLINT", "SOME", "SPACES", "STEP", "SUM", "TEMP", "THEN", "TO", "TOP",
  "TOP_OF_PAGE", "TOTAL", "TRAILER", "UNION", "UNIQUE", "UNITS_DAY",
  "UNITS_HOUR", "UNITS_MINUTE", "UNITS_MONTH", "UNITS_SECOND",
  "UNITS_YEAR", "UPDATE", "USER", "VARCHAR", "VARIABLE", "WHILE",
  "WITH_NO_LOG", "XBEGIN", "XMAX", "XMIN", "YEAR", "$accept", "ace_report",
  "db_section", "op_define_section", "define_section",
  "define_element_list", "define_element", "ufunc_name", "def_ascii_list",
  "variable", "datatype", "op_input_section", "input_section",
  "prompt_section", "prompt_element", "op_output_section",
  "output_section", "output_element_list", "output_element",
  "select_section", "sec_select_list", "read_list", "op_delim",
  "format_section", "op_end", "format_actions", "format_action",
  "variable_sub", "variable_sub_a", "op_order_by_clause_read",
  "order_by_clause_read", "@1", "literal", "order_by_clause", "@2",
  "sort_specification_list", "sort_specification", "sort_spec",
  "op_asc_desc", "having_clause", "group_by_clause",
  "column_specification_list", "where_clause", "from_clause",
  "table_reference_list", "table_reference", "tname", "tname_list",
  "table_expression", "op_where_clause", "op_group_by_clause",
  "op_having_clause", "search_condition", "boolean_term", "boolean_factor",
  "boolean_primary", "exists_predicate", "quantified_predicate",
  "quantifier", "all", "some", "op_escape", "pattern", "escape_character",
  "in_predicate", "in_value_list", "op_not", "comparison_predicate",
  "comp_op", "predicate", "op_all", "table_name", "db_name",
  "table_identifier", "col_arr", "column_name", "correlation_name",
  "real_number", "select_statement", "@3", "select_statement2",
  "select_statement2_1", "sel_p2", "op_no_log", "tmp_tabname", "subquery",
  "op_ad", "sq_select_list", "value_expression_pls",
  "column_specification", "units_qual", "value_expression",
  "value_expr_list", "value_specification", "commands", "command",
  "call_command", "func_identifier", "for_command", "op_step",
  "if_command", "op_else", "let_command", "expr_concat", "need_command",
  "pause_command", "print_command", "op_semi", "print_file_command",
  "skip_command", "while_command", "int_val", "string", "identifier",
  "expr", "aggregate", "aggregate_elem", "val_expression",
  "op_val_expr_list", "val_expr_list", "null_expr", "literal_expr", 0
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
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   165,   166,   167,   167,   168,   168,   169,   170,   170,
     171,   171,   171,   171,   172,   173,   173,   174,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   176,   176,   177,   178,
     178,   179,   180,   180,   181,   182,   182,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   184,   184,   185,
     185,   186,   187,   187,   188,   188,   189,   189,   190,   190,
     191,   191,   191,   191,   191,   191,   191,   192,   192,   192,
     193,   193,   194,   194,   196,   195,   195,   197,   197,   197,
     197,   197,   197,   197,   197,   199,   198,   200,   200,   201,
     202,   202,   203,   203,   203,   204,   205,   206,   206,   207,
     208,   209,   209,   210,   210,   210,   211,   211,   212,   212,
     213,   214,   214,   215,   215,   216,   216,   217,   217,   218,
     218,   219,   219,   220,   220,   221,   221,   222,   222,   223,
     223,   224,   225,   225,   226,   227,   228,   229,   229,   229,
     229,   230,   230,   231,   231,   232,   232,   232,   232,   232,
     232,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   234,   234,   234,   234,   235,   235,   235,   235,
     236,   236,   236,   236,   237,   238,   239,   239,   239,   240,
     240,   240,   241,   242,   242,   244,   243,   245,   246,   247,
     247,   247,   247,   248,   248,   249,   250,   251,   251,   251,
     251,   252,   252,   253,   253,   254,   255,   255,   255,   255,
     255,   255,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   257,   257,   258,   258,   259,   259,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   261,   262,   262,   262,   262,   262,   263,   264,   264,
     265,   266,   266,   267,   267,   267,   268,   268,   269,   270,
     271,   272,   272,   273,   274,   274,   275,   276,   277,   278,
     279,   280,   280,   280,   280,   281,   281,   281,   281,   281,
     281,   281,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   283,   283,   284,   284,   285,   286,   286,   286,
     286,   286,   286,   286,   286
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
static const unsigned short int yydefact[] =
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
       0,     0,     0,     0,     0,   336,   337,   163,   161,   170,
     164,   171,   165,   167,   169,   166,   168,     0,     0,     0,
       0,     0,   338,   162,     0,   335,     0,   339,     0,     0,
     288,     0,   292,   290,   295,   294,     0,   270,   190,   187,
       0,   249,   253,   255,   252,   250,   251,   118,     0,   112,
     132,     0,   135,   136,   207,     0,   153,     0,     0,     0,
     154,     0,     0,     0,     0,   106,   107,   215,     0,   126,
     120,   203,   205,    96,   207,   200,   197,     0,     0,     0,
     344,     0,   343,   342,     0,   307,   309,     0,     0,     0,
       0,     0,   332,   308,   311,   310,     0,   281,   302,   320,
     318,   317,   319,   316,   312,   315,   314,   313,   322,   283,
       0,   287,   296,     0,   115,     0,     0,   134,   128,   130,
     138,   256,   148,   256,   150,   155,   156,   256,     0,   141,
     143,     0,   142,     0,   139,   140,   158,   157,     0,   105,
     204,   202,     0,   233,     0,   232,    78,     0,   271,     0,
       0,   327,   330,   304,   328,   331,   329,     0,   280,     0,
       0,   188,   119,     0,   257,     0,   151,     0,     0,   145,
       0,   137,   108,     0,     0,     0,   345,   278,   282,     0,
       0,     0,   147,   256,   149,   256,   160,     0,   199,   234,
      77,     0,     0,   284,     0,   206,   152,   144,   146,   159,
     198,   279,     0,     0,   277,   285
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   178,   122,   123,   351,   315,   138,
     139,   182,   163,   300,   411,   185,   186,   187,   267,   509,
     408,   505,   295,   211,   289,   290,   291,   488,   212,   296,
     409,   510,   396,   397,   398,   399,   400,   401,   573,   574,
     575,   626,   608,   637,   402,   605,   503,   403,   466,   404,
     275,   292,   189,   190,   271,   191,   390,   352,    70,    89,
     515,   516,   301,   581,   511,   405,   115,   165,   166,   506,
     226,   278,   279,   606,   247,   248,   249,   324,   250,   632,
     251,   598,   252,   361,   253,   254,   255,   473,   256,   257,
     258,    51,    85,   168,   362,   354,   355,   356,   521,   522,
     523,   357
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -504
static const short int yypact[] =
{
     -17,     8,    49,    14,    30,    88,  -504,     9,    90,  -504,
    -504,  -504,    80,    96,   121,    80,   -21,  -504,   114,    94,
    -504,  -504,   198,  1075,  -504,  -504,   193,  1075,  -504,  -504,
     217,    46,  -504,   848,   199,  -504,    80,   200,  -504,  -504,
     210,  -504,  -504,  -504,  -504,   238,  -504,  -504,   254,  -504,
    -504,   262,  -504,    80,  -504,  -504,   277,   278,   287,   244,
     291,   299,   355,  1080,  -504,   355,  -504,   341,    85,   378,
    -504,  1075,   193,   193,   193,   193,    80,   432,   193,   193,
     193,    83,   193,   193,  -504,  -504,  -504,  -504,   386,     1,
     369,  -504,  -504,   316,  -504,  -504,   411,   150,   152,   416,
    1075,   355,  -504,  -504,  -504,   355,   355,  -504,  -504,  -504,
     355,   186,  -504,  -504,  -504,  1284,   395,   400,   351,   372,
      99,   -66,   279,  -504,  -504,  -504,  -504,   193,  -504,   193,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,   132,  -504,  -504,
     100,   253,  -504,   379,  -504,   392,   397,   405,   403,   420,
    -504,  -504,  -504,   414,  -504,  -504,  -504,  1284,   415,  -504,
     429,   434,   445,  -504,  -504,   -28,  -504,   495,   190,   448,
     449,   460,   446,   435,   436,  1309,  1309,  -504,  -504,  -504,
     519,   523,   132,   508,  -504,   524,  -504,    -8,   512,   530,
    -504,  -504,   153,  -504,  -504,  -504,  -504,     3,    29,  1284,
    1284,  -504,  -504,  1284,   828,     3,     3,     3,  1284,  1284,
      -5,   573,    77,  1284,  1284,  1284,  1284,  1284,  -504,  1284,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,   -14,  1284,   193,
      63,    63,  -504,  1309,  1309,  1309,   -10,    80,   963,   480,
     193,   355,   963,   355,   -72,   963,  1309,  1309,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  1309,
    -504,  -504,   524,   403,   132,  -504,  -504,  -504,    23,   403,
     494,  -504,  -504,  -504,  -504,  1284,   547,  1284,   630,   214,
     285,   290,  -504,  1284,  1284,  1284,   312,  -504,   119,   544,
    -504,  -504,   403,   551,   566,  -504,   520,   458,  -504,     3,
    -504,  -504,   135,   135,    98,    98,   473,   630,  -504,   499,
     329,    17,  -504,   503,  -504,  1309,  1309,  1309,  1309,  1309,
    -504,  -504,  -504,  -504,   492,  -504,   619,   259,   303,   963,
     525,   526,  -504,   963,  -504,   522,   527,   -15,  -504,  -504,
    -504,   528,   208,  -504,   963,  -504,   531,  -504,   532,   533,
     549,  -504,  -504,   518,  -504,   656,   408,  -504,    -4,   565,
    -504,   -40,  -504,  -504,   521,   567,   601,  1305,  -504,  -504,
    -504,  -504,  -504,   554,  -504,   184,   836,  -504,   878,  -504,
    1284,  -504,  -504,  1014,  1160,  1245,  -504,    -5,  -504,    -5,
    -504,  -504,  1137,   559,   559,   479,   665,   667,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,   914,   819,  1284,  -504,   598,
     403,   132,   568,   193,  -504,  -504,   193,   963,  1309,  1309,
     963,   963,  -504,  -504,  -504,  -504,   399,   963,   963,   453,
     963,   963,   692,   963,   963,   671,   963,   963,   963,   963,
    1309,   963,   963,   963,   963,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,   963,   963,   963,
     963,   963,  -504,  -504,   963,  -504,   963,  -504,   963,   963,
    -504,   963,  -504,  -504,  -504,  -504,  1309,  -504,  -504,  -504,
     608,  -504,  -504,   630,  -504,  -504,  -504,  -504,   390,  -504,
    -504,   569,  -504,  -504,     1,    16,   743,   566,   566,  1284,
    -504,   589,   592,   258,  1050,   654,  -504,   630,   566,  -504,
    -504,   543,  -504,   524,     1,  -504,  -504,   283,   659,   317,
     408,   662,   660,  -504,   570,  -504,  -504,   406,   418,   963,
     437,   463,  -504,  -504,  -504,  -504,   478,   643,  -504,   408,
     725,   896,  1300,  1300,   218,   218,   399,   408,   408,   661,
     423,  -504,  -504,   666,  -504,    -5,  1284,  -504,   667,  -504,
     630,   215,  -504,   215,  -504,  -504,  -504,   370,  1284,  -504,
    -504,  1197,  -504,   559,  -504,  -504,  -504,   630,  1284,   665,
    -504,  -504,  1284,  -504,   193,  -504,  -504,   963,  -504,   963,
     963,  -504,  -504,  -504,  -504,  -504,  -504,  1309,  -504,   699,
     963,  -504,  -504,   -28,  -504,   491,  -504,   496,   647,  -504,
     120,  -504,  -504,   -28,   672,   673,   408,   578,  -504,   963,
     674,   676,  -504,   370,  -504,   370,  -504,  1284,    77,  -504,
    -504,   963,   663,   661,   712,  -504,  -504,  -504,  -504,   630,
    -504,  -504,  1309,   963,  -504,   661
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -504,  -504,  -504,  -504,  -504,  -504,   709,  -504,  -504,   -12,
       7,  -504,  -504,  -504,   695,  -504,  -504,  -504,   664,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,   610,   110,   538,  -504,
    -504,  -504,   -30,  -504,  -504,  -181,   488,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -383,   482,  -504,  -410,  -504,
    -504,  -504,  -362,   274,   275,   380,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,   211,  -504,  -504,  -393,  -504,
       4,  -135,  -504,  -231,   404,  -504,  -504,  -115,   683,  -504,
    -504,  -504,   157,  -504,  -504,  -366,  -250,  -503,   577,   212,
     -50,   -99,   237,  -380,  -101,  -236,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -463,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,    -6,   -51,    -9,  -126,  -504,   441,  -107,  -504,   181,
    -504,  -504
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const short int yytable[] =
{
     164,   262,   188,    27,   487,   549,   489,   468,   471,   308,
      12,   368,   499,   504,    88,   175,   167,    50,   330,   331,
     209,   497,   265,   368,    71,   194,   196,   492,   493,   112,
     107,   272,   369,   495,    52,     1,   334,   183,   374,     4,
      12,    77,   164,   320,    28,   321,   372,   188,   210,     6,
     132,   266,   276,   603,   133,   134,    13,   272,   204,   135,
     557,   113,   415,   273,   100,   416,    96,    97,    98,    99,
     364,     7,   102,   103,   104,   259,   108,   109,    95,   613,
     176,   368,   368,   368,   164,   164,    13,   154,   164,   273,
     322,   154,   472,   164,   164,    10,   154,    14,   164,   164,
     164,   164,   164,   504,   164,   345,   469,   131,   288,     5,
     167,    54,   353,   164,   302,   303,   304,   305,   306,   366,
     307,   180,   217,   181,   154,    84,   627,    14,   192,   188,
     346,   368,   317,   318,   319,   562,   564,    15,   576,   201,
     213,   214,   215,   216,   217,   367,   579,   348,   349,   114,
      92,   274,   312,    11,   323,   105,   633,   215,   216,   217,
     164,   183,   164,   149,   313,   297,   173,    15,   164,   164,
     164,    30,   602,   192,   183,    18,   376,   274,   378,   164,
     645,    21,   368,   368,   383,   384,   385,   609,   298,   193,
     360,   174,   363,   621,   126,   406,   128,    24,   127,  -184,
     129,   293,   277,   628,   537,   155,   106,   611,    33,   283,
     284,   285,   423,   425,   418,   419,  -185,    93,   309,   219,
     154,   184,   426,   311,   299,   326,   429,   325,   387,   479,
     513,    26,   480,   154,   359,   140,   141,   435,   365,    30,
     552,   219,   461,   636,   556,   638,    36,   220,   221,   222,
     223,   224,   225,   227,   370,   192,   219,   144,   379,   373,
     370,   462,   380,   270,   582,   164,   565,   566,   463,   220,
     221,   222,   223,   224,   225,   567,   188,   164,   149,   293,
     164,   483,    50,   391,   220,   221,   222,   223,   224,   225,
      53,   519,   164,   406,   568,   524,   496,   136,   137,   228,
     229,   525,   526,   412,   150,   116,   467,    76,   507,    72,
     533,   534,   535,   520,   117,   538,   149,   434,   417,    73,
     155,   156,   149,   520,   520,    65,   520,   520,   583,   381,
      66,   584,   520,   380,   382,   539,   540,   541,   380,   464,
     314,   314,   195,   550,   177,   551,   494,    74,   422,   119,
     542,   543,   544,   545,   546,   465,   386,   547,   155,   548,
     380,   618,   586,    75,   155,   587,   149,   220,   221,   222,
     223,   224,   225,   414,    78,    79,   467,   380,   293,   467,
     293,    80,   164,   164,   164,   467,    81,   120,    82,   164,
     140,   141,   424,   164,   121,   116,    83,    84,   406,   406,
     560,   512,   192,   593,   117,   577,   644,   517,   155,   406,
     518,   442,   144,   443,   444,    90,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   149,   554,   101,   118,   280,   555,   119,
     281,   164,   462,    94,   110,   286,   164,    66,   164,   463,
     591,   462,   164,   164,   589,   125,   164,   167,   463,   150,
     130,   615,   592,   164,   617,   310,   589,   164,   599,   610,
     467,   600,   204,   169,   620,   155,   156,   120,   170,   507,
     171,   594,   616,   167,   121,   589,   392,   172,   197,   467,
     467,   467,   467,   467,   467,   467,   467,   467,   467,   140,
     141,   198,   142,   463,   154,   641,   199,   595,   164,   202,
     164,   589,   164,   143,   200,   213,   214,   215,   216,   217,
     464,   144,   596,   203,   205,   232,   589,   233,   639,   464,
     145,   604,   146,   604,   147,   622,   465,   604,   206,   623,
     624,   148,   149,   207,   623,   465,   293,   393,   220,   221,
     222,   223,   224,   225,   208,   230,   231,   220,   221,   222,
     223,   224,   225,   260,   234,   235,   467,   261,   150,   151,
     152,   263,   264,   392,   464,   268,   269,   294,   614,   153,
     154,   358,   394,   375,   155,   156,   140,   141,   395,   142,
     465,   377,   389,   604,   219,   604,   218,  -184,   410,   407,
     143,   420,   220,   221,   222,   223,   224,   225,   144,   413,
     494,   527,   528,   417,   530,   531,   219,   145,   158,   146,
     536,   147,   220,   221,   222,   223,   224,   225,   148,   149,
     421,   430,   427,   428,   393,   159,   431,   433,   436,   437,
     438,   160,   161,   162,   220,   221,   222,   223,   224,   225,
     213,   214,   215,   216,   217,   150,   151,   152,   439,   440,
     441,   470,   476,   475,   270,   474,   153,   154,   491,   394,
     497,   155,   156,   498,   442,   395,   443,   444,   508,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   529,   553,   561,   514,
     494,   563,   578,   580,   585,   158,   588,   597,   589,   471,
     619,   601,   590,   625,   462,   532,   631,   629,   630,   634,
     635,   463,   159,   643,   642,    29,    55,    87,   160,   161,
     162,   444,   179,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     500,   219,   371,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   213,   214,   215,   216,   217,   462,   316,
     388,   558,   490,   559,   607,   463,   124,   478,   432,   220,
     221,   222,   223,   224,   225,   640,   287,   282,     0,     0,
     612,     0,   464,   463,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   465,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,   224,   225,   500,   501,     0,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   213,
     214,   215,   216,   217,     0,     0,   464,   502,   213,   214,
     215,   216,   217,     0,     0,     0,   213,   214,   215,   216,
     217,     0,   465,     0,   219,     0,     0,     0,     0,   463,
       0,     0,   282,     0,   220,   221,   222,   223,   224,   225,
     481,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,   224,   225,   213,   214,
     215,   216,   217,   501,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,     0,   482,   502,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,     0,     0,     0,     0,     0,   462,
     219,    57,     0,     0,     0,     0,   463,     0,     0,   219,
       0,     0,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,    58,   463,     0,     0,     0,   220,   221,
     222,   223,   224,   225,     0,    59,    60,   220,   221,   222,
     223,   224,   225,   327,   328,   220,   221,   222,   223,   224,
     225,    61,    62,     0,   329,     0,   330,   331,     0,   219,
       0,     0,     0,     0,     0,   332,     0,     0,     0,     0,
     333,     0,     0,     0,   334,     0,   335,   464,   336,     0,
       0,     0,     0,     0,     0,     0,   149,   220,   221,   222,
     223,   224,   225,   465,   213,   214,   215,   216,   217,     0,
       0,   337,     0,     0,     0,   220,   221,   222,   223,   224,
     225,     0,   338,   339,   340,     0,     0,     0,   484,     0,
       0,     0,     0,   341,   342,     0,     0,     0,   155,   343,
     140,   141,   344,   142,     0,     0,     0,     0,   569,   570,
       0,     0,     0,   345,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,   146,     0,   147,     0,     0,   346,     0,
       0,     0,   148,   149,     0,     0,    37,    56,     0,   347,
       0,     0,     0,     0,     0,   348,   349,   350,    38,    39,
       0,    40,     0,     0,     0,   219,     0,     0,     0,   150,
     151,   152,     0,     0,     0,    86,    41,     0,     0,     0,
     153,   154,    42,     0,     0,   155,   156,   140,   141,   571,
     142,    43,    44,   220,   221,   222,   223,   224,   225,     0,
       0,   143,     0,    57,    45,     0,     0,     0,     0,   144,
     213,   214,   215,   216,   217,     0,   572,     0,   145,   158,
     146,     0,   147,     0,     0,    58,     0,     0,     0,   148,
     149,     0,     0,     0,   485,   393,   159,    59,    60,    46,
      47,     0,   160,   161,   162,     0,     0,   140,   141,     0,
     142,     0,     0,    61,    62,     0,   150,   151,   152,     0,
       0,   143,    48,     0,     0,     0,     0,   153,   154,   144,
     394,     0,   155,   156,     0,     0,   395,     0,   145,     0,
     146,     0,   147,     0,     0,     0,     0,     0,     0,   148,
     149,     0,     0,     0,     0,   213,   214,   215,   216,   217,
       0,     0,     0,     0,     0,     0,   158,     0,     0,     0,
       0,   219,     0,     0,     0,     0,   150,   151,   152,   486,
       0,     0,     0,   159,     0,     0,     0,   153,   154,   160,
     161,   162,   155,   156,   140,   141,   157,   142,     0,   220,
     221,   222,   223,   224,   225,     0,     0,     0,   143,     0,
       0,     0,   459,   460,   461,     0,   144,     0,   494,     0,
       0,     0,     0,     0,     0,   145,   158,   146,     0,   147,
       0,     0,     0,   462,   236,     0,   148,   149,   236,     0,
     463,     0,     0,   159,     0,     0,     0,     0,     0,   160,
     161,   162,     0,     0,     0,     0,   219,     0,     0,     0,
     477,     0,     0,   150,   151,   152,     0,     0,   237,     0,
       0,     0,   237,     0,   153,   154,     0,     0,   238,   155,
     156,     0,   238,   157,   220,   221,   222,   223,   224,   225,
     239,     0,     0,     0,   239,     0,     0,   240,     0,     0,
       0,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,     0,   158,   241,     0,     0,   242,   241,   243,
       0,   242,     0,   243,     0,     0,     0,   465,   244,     0,
     159,     0,   244,     0,     0,     0,   160,   161,   162,   220,
     221,   222,   223,   224,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,     0,   246,     0,   245,     0,
     246
};

static const short int yycheck[] =
{
     115,   182,   137,    15,   387,   468,   389,    11,    48,    23,
      31,   247,   405,   406,    65,    81,   115,    89,    33,    34,
      48,     5,    30,   259,    36,   140,   141,   393,   394,    28,
      81,    28,   263,   395,    27,    52,    51,    42,   269,    31,
      31,    53,   157,    53,    65,    55,    23,   182,    76,     0,
     101,    59,    23,   556,   105,   106,    77,    28,   157,   110,
      44,    60,    45,    60,    76,    48,    72,    73,    74,    75,
     142,    57,    78,    79,    80,   176,    82,    83,    71,   582,
     146,   317,   318,   319,   199,   200,    77,   101,   203,    60,
     100,   101,   132,   208,   209,    65,   101,   118,   213,   214,
     215,   216,   217,   496,   219,   120,   110,   100,   113,   101,
     209,    65,   238,   228,   213,   214,   215,   216,   217,   245,
     219,   127,    24,   129,   101,    42,     6,   118,   137,   264,
     145,   367,   233,   234,   235,   501,   502,   158,   504,   148,
      20,    21,    22,    23,    24,   246,   508,   162,   163,   148,
      65,   148,    89,    65,   164,    72,   619,    22,    23,    24,
     275,    42,   277,    63,   101,    88,    67,   158,   283,   284,
     285,   125,   555,   182,    42,    85,   275,   148,   277,   294,
     643,   101,   418,   419,   283,   284,   285,   567,   111,    89,
     241,    92,   243,   603,    44,   294,    44,   101,    48,    46,
      48,   210,   198,   613,   440,   105,   123,   573,   114,   205,
     206,   207,   327,   328,   315,   316,    63,   132,   227,   121,
     101,    89,   329,   229,   147,   237,   333,   236,   109,    45,
     411,   110,    48,   101,   240,    20,    21,   344,   244,   125,
     476,   121,    24,   623,   494,   625,    48,   149,   150,   151,
     152,   153,   154,    63,   263,   264,   121,    42,    44,   268,
     269,    43,    48,   110,   514,   380,     8,     9,    50,   149,
     150,   151,   152,   153,   154,    17,   411,   392,    63,   288,
     395,   380,    89,   292,   149,   150,   151,   152,   153,   154,
      73,   417,   407,   392,    36,   421,   395,   111,   112,   109,
     110,   427,   428,   299,    89,    26,   356,    45,   407,   109,
     436,   437,   438,   420,    35,   441,    63,   109,   110,   109,
     105,   106,    63,   430,   431,   126,   433,   434,    45,    44,
     131,    48,   439,    48,    44,   442,   443,   444,    48,   121,
     230,   231,    89,   469,    65,   471,   131,   109,    89,    70,
     457,   458,   459,   460,   461,   137,    44,   464,   105,   466,
      48,   597,    45,   109,   105,    48,    63,   149,   150,   151,
     152,   153,   154,    44,    97,    97,   426,    48,   387,   429,
     389,    94,   497,   498,   499,   435,   142,   108,    97,   504,
      20,    21,    89,   508,   115,    26,    97,    42,   497,   498,
     499,   410,   411,   529,    35,   504,   642,   413,   105,   508,
     416,     3,    42,     5,     6,    74,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    63,    44,     3,    67,   200,    48,    70,
     203,   556,    43,    65,    58,   208,   561,   131,   563,    50,
      44,    43,   567,   568,    48,    44,   571,   556,    50,    89,
      44,   587,    44,   578,   590,   228,    48,   582,    45,   568,
     520,    48,   571,    78,   600,   105,   106,   108,    78,   578,
     129,    44,   589,   582,   115,    48,     7,   115,   109,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,    20,
      21,   109,    23,    50,   101,   631,   109,    44,   623,    89,
     625,    48,   627,    34,   109,    20,    21,    22,    23,    24,
     121,    42,    44,   109,   109,    65,    48,    81,   627,   121,
      51,   561,    53,   563,    55,    44,   137,   567,   109,    48,
      44,    62,    63,   109,    48,   137,   555,    68,   149,   150,
     151,   152,   153,   154,   109,   107,   107,   149,   150,   151,
     152,   153,   154,    44,   129,   129,   616,    44,    89,    90,
      91,    63,    48,     7,   121,    63,    46,     4,   584,   100,
     101,   101,   103,    89,   105,   106,    20,    21,   109,    23,
     137,    44,    48,   623,   121,   625,   101,    46,   140,    79,
      34,   109,   149,   150,   151,   152,   153,   154,    42,   110,
     131,   430,   431,   110,   433,   434,   121,    51,   139,    53,
     439,    55,   149,   150,   151,   152,   153,   154,    62,    63,
      11,   109,   107,   107,    68,   156,   109,   109,   107,   107,
     107,   162,   163,   164,   149,   150,   151,   152,   153,   154,
      20,    21,    22,    23,    24,    89,    90,    91,   109,   141,
       4,    96,    61,    96,   110,   144,   100,   101,   109,   103,
       5,   105,   106,     6,     3,   109,     5,     6,    80,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     4,    89,   109,   131,
     131,   109,    48,   160,    45,   139,    44,    64,    48,    48,
      11,    45,   142,    66,    43,    44,   138,    45,    45,    45,
      44,    50,   156,    11,    61,    16,    31,    63,   162,   163,
     164,     6,   122,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       7,   121,   264,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    43,   231,
     288,   497,   392,   498,   563,    50,    93,   373,   337,   149,
     150,   151,   152,   153,   154,   628,   209,    44,    -1,    -1,
     578,    -1,   121,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,     7,    84,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,   121,   104,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,   137,    -1,   121,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    44,    -1,   149,   150,   151,   152,   153,   154,
      44,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    20,    21,
      22,    23,    24,    84,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    44,   104,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    43,
     121,    93,    -1,    -1,    -1,    -1,    50,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,   115,    50,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,   127,   128,   149,   150,   151,
     152,   153,   154,    20,    21,   149,   150,   151,   152,   153,
     154,   143,   144,    -1,    31,    -1,    33,    34,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    51,    -1,    53,   121,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,   149,   150,   151,
     152,   153,   154,   137,    20,    21,    22,    23,    24,    -1,
      -1,    78,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,    89,    90,    91,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,   106,
      20,    21,   109,    23,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    -1,   120,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    -1,    55,    -1,    -1,   145,    -1,
      -1,    -1,    62,    63,    -1,    -1,    41,    37,    -1,   156,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,    53,    54,
      -1,    56,    -1,    -1,    -1,   121,    -1,    -1,    -1,    89,
      90,    91,    -1,    -1,    -1,    65,    71,    -1,    -1,    -1,
     100,   101,    77,    -1,    -1,   105,   106,    20,    21,   109,
      23,    86,    87,   149,   150,   151,   152,   153,   154,    -1,
      -1,    34,    -1,    93,    99,    -1,    -1,    -1,    -1,    42,
      20,    21,    22,    23,    24,    -1,   136,    -1,    51,   139,
      53,    -1,    55,    -1,    -1,   115,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    44,    68,   156,   127,   128,   134,
     135,    -1,   162,   163,   164,    -1,    -1,    20,    21,    -1,
      23,    -1,    -1,   143,   144,    -1,    89,    90,    91,    -1,
      -1,    34,   157,    -1,    -1,    -1,    -1,   100,   101,    42,
     103,    -1,   105,   106,    -1,    -1,   109,    -1,    51,    -1,
      53,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    89,    90,    91,    44,
      -1,    -1,    -1,   156,    -1,    -1,    -1,   100,   101,   162,
     163,   164,   105,   106,    20,    21,   109,    23,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    22,    23,    24,    -1,    42,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    51,   139,    53,    -1,    55,
      -1,    -1,    -1,    43,    39,    -1,    62,    63,    39,    -1,
      50,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      65,    -1,    -1,    89,    90,    91,    -1,    -1,    73,    -1,
      -1,    -1,    73,    -1,   100,   101,    -1,    -1,    83,   105,
     106,    -1,    83,   109,   149,   150,   151,   152,   153,   154,
      95,    -1,    -1,    -1,    95,    -1,    -1,   102,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   139,   119,    -1,    -1,   122,   119,   124,
      -1,   122,    -1,   124,    -1,    -1,    -1,   137,   133,    -1,
     156,    -1,   133,    -1,    -1,    -1,   162,   163,   164,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,   161,    -1,   159,    -1,
     161
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,    52,   166,   167,    31,   101,     0,    57,   168,   169,
      65,    65,    31,    77,   118,   158,   170,   171,    85,   176,
     177,   101,   173,   174,   101,   172,   110,   174,    65,   171,
     125,   178,   179,   114,   180,   181,    48,    41,    53,    54,
      56,    71,    77,    86,    87,    99,   134,   135,   157,   175,
      89,   276,   175,    73,    65,   179,    37,    93,   115,   127,
     128,   143,   144,   182,   183,   126,   131,   184,   185,   186,
     243,   174,   109,   109,   109,   109,    45,   174,    97,    97,
      94,   142,    97,    97,    42,   277,    65,   183,   277,   244,
      74,   188,    65,   132,    65,   175,   276,   276,   276,   276,
     174,     3,   276,   276,   276,    72,   123,   277,   276,   276,
      58,   187,    28,    60,   148,   251,    26,    35,    67,    70,
     108,   115,   190,   191,   243,    44,    44,    48,    44,    48,
      44,   175,   277,   277,   277,   277,   111,   112,   194,   195,
      20,    21,    23,    34,    42,    51,    53,    55,    62,    63,
      89,    90,    91,   100,   101,   105,   106,   109,   139,   156,
     162,   163,   164,   197,   242,   252,   253,   256,   278,    78,
      78,   129,   115,    67,    92,    81,   146,    65,   189,   191,
     276,   276,   196,    42,    89,   200,   201,   202,   236,   237,
     238,   240,   278,    89,   242,    89,   242,   109,   109,   109,
     109,   278,    89,   109,   256,   109,   109,   109,   109,    48,
      76,   208,   213,    20,    21,    22,    23,    24,   101,   121,
     149,   150,   151,   152,   153,   154,   255,    63,   109,   110,
     107,   107,    65,    81,   129,   129,    39,    73,    83,    95,
     102,   119,   122,   124,   133,   159,   161,   259,   260,   261,
     263,   265,   267,   269,   270,   271,   273,   274,   275,   259,
      44,    44,   200,    63,    48,    30,    59,   203,    63,    46,
     110,   239,    28,    60,   148,   235,    23,   235,   256,   257,
     257,   257,    44,   235,   235,   235,   257,   253,   113,   209,
     210,   211,   236,   278,     4,   207,   214,    88,   111,   147,
     198,   247,   256,   256,   256,   256,   256,   256,    23,   278,
     257,   276,    89,   101,   192,   193,   193,   259,   259,   259,
      53,    55,   100,   164,   262,   278,   174,    20,    21,    31,
      33,    34,    42,    47,    51,    53,    55,    78,    89,    90,
      91,   100,   101,   106,   109,   120,   145,   156,   162,   163,
     164,   192,   242,   279,   280,   281,   282,   286,   101,   276,
     277,   268,   279,   277,   142,   276,   279,   259,   260,   238,
     278,   201,    23,   278,   238,    89,   256,    44,   256,    44,
      48,    44,    44,   256,   256,   256,    44,   109,   211,    48,
     241,   278,     7,    68,   103,   109,   217,   218,   219,   220,
     221,   222,   229,   232,   234,   250,   256,    79,   205,   215,
     140,   199,   235,   110,    44,    45,    48,   110,   259,   259,
     109,    11,    89,   242,    89,   242,   282,   107,   107,   282,
     109,   109,   281,   109,   109,   282,   107,   107,   107,   109,
     141,     4,     3,     5,     6,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    43,    50,   121,   137,   233,   255,    11,   110,
      96,    48,   132,   272,   144,    96,    61,    65,   239,    45,
      48,    44,    44,   256,    44,    44,    44,   210,   212,   210,
     220,   109,   250,   250,   131,   217,   256,     5,     6,   233,
       7,    84,   104,   231,   233,   206,   254,   256,    80,   204,
     216,   249,   278,   200,   131,   245,   246,   276,   276,   279,
     282,   283,   284,   285,   279,   279,   279,   284,   284,     4,
     284,   284,    44,   279,   279,   279,   284,   260,   279,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   268,
     279,   279,   260,    89,    44,    48,   251,    44,   218,   219,
     256,   109,   250,   109,   250,     8,     9,    17,    36,    28,
      29,   109,   136,   223,   224,   225,   250,   256,    48,   217,
     160,   248,   251,    45,    48,    45,    45,    48,    44,    48,
     142,    44,    44,   279,    44,    44,    44,    64,   266,    45,
      48,    45,   210,   252,   197,   230,   258,   230,   227,   258,
     256,   250,   254,   252,   276,   279,   282,   279,   260,    11,
     279,   213,    44,    48,    44,    66,   226,     6,   213,    45,
      45,   138,   264,   268,    45,    44,   258,   228,   258,   256,
     247,   279,    61,    11,   260,   268
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
        case 3:
#line 247 "ace.yacc"
    {
		this_report.dbname=strdup("!!ASCII!!");;
	}
    break;

  case 4:
#line 250 "ace.yacc"
    {
		this_report.dbname=strdup(yyvsp[-1].str);
		A4GLSQL_init_connection (yyvsp[-1].str);
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
    break;

  case 10:
#line 274 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:
#line 278 "ace.yacc"
    {
		ace_add_variable(yyvsp[-1].str,yyvsp[0].str,CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:
#line 281 "ace.yacc"
    {
		ace_add_variable(yyvsp[-1].str,yyvsp[0].str,CAT_PARAM,atoi(yyvsp[-3].str),-1,0);
	}
    break;

  case 13:
#line 284 "ace.yacc"
    {
		add_function(yyvsp[0].str);
	}
    break;

  case 17:
#line 295 "ace.yacc"
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
#line 308 "ace.yacc"
    {strcpy(yyval.str,"INTEGER");}
    break;

  case 20:
#line 309 "ace.yacc"
    {strcpy(yyval.str,"CHAR");}
    break;

  case 21:
#line 310 "ace.yacc"
    {sprintf(yyval.str,"CHAR (%s)",yyvsp[-1].str);}
    break;

  case 22:
#line 311 "ace.yacc"
    {strcpy(yyval.str,"VARCHAR");}
    break;

  case 23:
#line 312 "ace.yacc"
    {sprintf(yyval.str,"VARCHAR (%s)",yyvsp[-1].str);}
    break;

  case 24:
#line 313 "ace.yacc"
    {strcpy(yyval.str,"DATE");}
    break;

  case 25:
#line 314 "ace.yacc"
    {strcpy(yyval.str,"FLOAT");}
    break;

  case 26:
#line 315 "ace.yacc"
    {strcpy(yyval.str,"SMALLFLOAT");}
    break;

  case 27:
#line 316 "ace.yacc"
    {strcpy(yyval.str,"SMALLINT");}
    break;

  case 28:
#line 317 "ace.yacc"
    {strcpy(yyval.str,"DATETIME");}
    break;

  case 29:
#line 318 "ace.yacc"
    {strcpy(yyval.str,"INTERVAL");}
    break;

  case 30:
#line 319 "ace.yacc"
    {strcpy(yyval.str,"MONEY");}
    break;

  case 31:
#line 320 "ace.yacc"
    {sprintf(yyval.str,"MONEY (%s,0)",yyvsp[-1].str);}
    break;

  case 32:
#line 321 "ace.yacc"
    {sprintf(yyval.str,"MONEY (%s,%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 33:
#line 322 "ace.yacc"
    {strcpy(yyval.str,"DECIMAL");}
    break;

  case 34:
#line 323 "ace.yacc"
    {sprintf(yyval.str,"DECIMAL (%s,0)",yyvsp[-1].str);}
    break;

  case 35:
#line 324 "ace.yacc"
    {sprintf(yyval.str,"DECIMAL (%s,%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 41:
#line 338 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes(yyvsp[0].str),yyvsp[-2].str);
}
    break;

  case 47:
#line 353 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=strdup(yyvsp[0].str);}
    break;

  case 48:
#line 354 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:
#line 355 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=strdup(yyvsp[0].str); }
    break;

  case 50:
#line 356 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=strdup(yyvsp[0].str); }
    break;

  case 51:
#line 357 "ace.yacc"
    {
		this_report.output.left_margin=atoi(yyvsp[0].str);
	}
    break;

  case 52:
#line 360 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi(yyvsp[0].str);
	}
    break;

  case 53:
#line 363 "ace.yacc"
    {
		this_report.output.top_margin=atoi(yyvsp[0].str);
	}
    break;

  case 54:
#line 366 "ace.yacc"
    {
		this_report.output.page_length=atoi(yyvsp[0].str);
	}
    break;

  case 55:
#line 369 "ace.yacc"
    {
		this_report.output.right_margin=atoi(yyvsp[0].str);
	}
    break;

  case 56:
#line 372 "ace.yacc"
    {
		this_report.output.top_of_page=strdup(yyvsp[0].str);
	}
    break;

  case 58:
#line 379 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:
#line 383 "ace.yacc"
    { add_select(yyvsp[0].str,temp_tab_name); }
    break;

  case 60:
#line 384 "ace.yacc"
    { add_select(yyvsp[0].str,temp_tab_name); }
    break;

  case 64:
#line 395 "ace.yacc"
    {
		struct commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,"",cmd);
	  }
    break;

  case 70:
#line 414 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,"",yyvsp[0].commands);
	}
    break;

  case 71:
#line 418 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,"",yyvsp[0].commands);
	}
    break;

  case 72:
#line 422 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,"",yyvsp[0].commands);
	}
    break;

  case 73:
#line 426 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,"",yyvsp[0].commands);
	}
    break;

  case 74:
#line 430 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,"",yyvsp[0].commands);
	}
    break;

  case 75:
#line 434 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,yyvsp[-1].str,yyvsp[0].commands);
	}
    break;

  case 76:
#line 438 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,yyvsp[-1].str,yyvsp[0].commands);
	}
    break;

  case 81:
#line 451 "ace.yacc"
    {
int vid;
int a;
a=atoi(yyvsp[0].str);
vid = find_sql_var (a);
sprintf(yyval.str,this_report.variables.variables_val[vid].name);
}
    break;

  case 82:
#line 462 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 84:
#line 465 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:
#line 465 "ace.yacc"
    {
	printf("speclist : %s ",yyvsp[0].str);
	sprintf(yyval.str,"ORDER BY %s",yyvsp[0].str);}
    break;

  case 86:
#line 469 "ace.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 87:
#line 478 "ace.yacc"
    {
		sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
	}
    break;

  case 91:
#line 485 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 92:
#line 487 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 93:
#line 489 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 94:
#line 491 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 95:
#line 499 "ace.yacc"
    {
		ordbycnt=0;
	}
    break;

  case 96:
#line 502 "ace.yacc"
    {
		sprintf(yyval.str,"ORDER BY %s",yyvsp[0].str);
		
	}
    break;

  case 98:
#line 510 "ace.yacc"
    {
sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 100:
#line 517 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"I%d",atoi(yyvsp[0].str));
		ordby[ordbycnt++]=strdup(buff);
	}
    break;

  case 101:
#line 522 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"C%s",yyvsp[0].str);
		ordby[ordbycnt++]=strdup(buff);
	}
    break;

  case 102:
#line 529 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 105:
#line 537 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 106:
#line 543 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 109:
#line 553 "ace.yacc"
    {sprintf(yyval.str,"WHERE \n0 (%s)\n0",yyvsp[0].str);}
    break;

  case 110:
#line 558 "ace.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 112:
#line 564 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 113:
#line 568 "ace.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 114:
#line 569 "ace.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 115:
#line 570 "ace.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 117:
#line 574 "ace.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		ace_add_table(yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 119:
#line 582 "ace.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 120:
#line 590 "ace.yacc"
    {
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 121:
#line 597 "ace.yacc"
    {strcpy(yyval.str,"\n0");}
    break;

  case 123:
#line 601 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 125:
#line 605 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 128:
#line 613 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 130:
#line 619 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 132:
#line 625 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 134:
#line 631 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 135:
#line 636 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 136:
#line 637 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 137:
#line 643 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 138:
#line 645 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 144:
#line 669 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 147:
#line 683 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 148:
#line 685 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 149:
#line 687 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 150:
#line 689 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 152:
#line 696 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 153:
#line 699 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 155:
#line 706 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 156:
#line 708 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 157:
#line 710 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 158:
#line 712 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 159:
#line 714 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 160:
#line 716 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 170:
#line 731 "ace.yacc"
    {sprintf(yyval.str,"<=");}
    break;

  case 171:
#line 732 "ace.yacc"
    {sprintf(yyval.str,">=");}
    break;

  case 176:
#line 742 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 180:
#line 775 "ace.yacc"
    { sprintf(yyval.str," %s",(char *)A4GL_strip_quotes(yyvsp[0].str)); }
    break;

  case 181:
#line 776 "ace.yacc"
    {sprintf(yyval.str,yyvsp[0].str); }
    break;

  case 182:
#line 777 "ace.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);  }
    break;

  case 183:
#line 778 "ace.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str);  }
    break;

  case 185:
#line 787 "ace.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 186:
#line 791 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 187:
#line 792 "ace.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 188:
#line 793 "ace.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 189:
#line 796 "ace.yacc"
    { sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 190:
#line 797 "ace.yacc"
    { sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 191:
#line 798 "ace.yacc"
    { sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 194:
#line 809 "ace.yacc"
    {sprintf(yyval.str,"0.%s",yyvsp[0].str);}
    break;

  case 195:
#line 824 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 196:
#line 827 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 198:
#line 848 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str );}
    break;

  case 199:
#line 852 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 200:
#line 853 "ace.yacc"
    {
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;

  case 202:
#line 857 "ace.yacc"
    {
       sprintf(yyval.str,"INTO TEMP %s%s ",yyvsp[-1].str,yyvsp[0].str);
	strcpy(temp_tab_name,yyvsp[-1].str);
}
    break;

  case 203:
#line 863 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 204:
#line 863 "ace.yacc"
    {strcpy(yyval.str," WITH NO LOG");}
    break;

  case 206:
#line 885 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 207:
#line 888 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 208:
#line 889 "ace.yacc"
    {sprintf(yyval.str,"ALL");}
    break;

  case 209:
#line 890 "ace.yacc"
    {sprintf(yyval.str,"DISTINCT");}
    break;

  case 210:
#line 891 "ace.yacc"
    {sprintf(yyval.str,"DISTINCT");}
    break;

  case 212:
#line 896 "ace.yacc"
    { sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 213:
#line 900 "ace.yacc"
    {
			add_select_column(yyvsp[0].str,yyvsp[0].str);
		}
    break;

  case 214:
#line 903 "ace.yacc"
    {
			sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
			add_select_column(yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 216:
#line 913 "ace.yacc"
    {sprintf(yyval.str,"UNITS YEAR");}
    break;

  case 217:
#line 914 "ace.yacc"
    {sprintf(yyval.str,"UNITS MONTH"); }
    break;

  case 218:
#line 915 "ace.yacc"
    {sprintf(yyval.str,"UNITS DAY);"); }
    break;

  case 219:
#line 916 "ace.yacc"
    {sprintf(yyval.str,"UNITS HOUR);"); }
    break;

  case 220:
#line 917 "ace.yacc"
    {sprintf(yyval.str,"UNITS MINUTE);"); }
    break;

  case 221:
#line 918 "ace.yacc"
    {sprintf(yyval.str,"UNITS SECOND);"); }
    break;

  case 222:
#line 923 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 223:
#line 925 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 224:
#line 927 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 225:
#line 929 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 226:
#line 931 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 227:
#line 933 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 228:
#line 935 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 231:
#line 938 "ace.yacc"
    {sprintf(yyval.str," %s[%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 232:
#line 939 "ace.yacc"
    {sprintf(yyval.str," %s[%s,%s]",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 233:
#line 940 "ace.yacc"
    {sprintf(yyval.str," %s.%s[%s]",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 234:
#line 941 "ace.yacc"
    {sprintf(yyval.str," %s.%s[%s,%s]",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 235:
#line 943 "ace.yacc"
    {
if (find_variable(yyvsp[0].str)==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
sprintf(yyval.str,"\n2(%d)",find_variable(yyvsp[0].str));
}
    break;

  case 236:
#line 948 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 237:
#line 950 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 241:
#line 954 "ace.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 242:
#line 955 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 243:
#line 956 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 244:
#line 957 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 245:
#line 958 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 246:
#line 959 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 247:
#line 960 "ace.yacc"
    {sprintf(yyval.str,"%s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 248:
#line 962 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 249:
#line 964 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 250:
#line 966 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 251:
#line 968 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 252:
#line 970 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 253:
#line 972 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 255:
#line 978 "ace.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 258:
#line 996 "ace.yacc"
    {
		yyval.commands.commands.commands_len=1;
		yyval.commands.commands.commands_val=malloc(sizeof(struct command));
		COPY(yyval.commands.commands.commands_val[0],yyvsp[0].cmd);
		}
    break;

  case 259:
#line 1001 "ace.yacc"
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
#line 1023 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_BLOCK;
		yyval.cmd.command_u.commands.commands.commands_val=yyvsp[-1].commands.commands.commands_val;
		yyval.cmd.command_u.commands.commands.commands_len=yyvsp[-1].commands.commands.commands_len;
	}
    break;

  case 271:
#line 1060 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_CALL;
		yyval.cmd.command_u.cmd_call.fcall=malloc(sizeof(struct expr_call));
                yyval.cmd.command_u.cmd_call.fcall->fname=strdup(yyvsp[-3].str);
	
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
		print_lexpr( yyval.cmd.command_u.cmd_call.fcall->lexpr);
}
    break;

  case 277:
#line 1078 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_FOR;
		yyval.cmd.command_u.cmd_for.varid=find_variable(yyvsp[-7].str);
		yyval.cmd.command_u.cmd_for.start=yyvsp[-5].expr;
		yyval.cmd.command_u.cmd_for.finish=yyvsp[-3].expr;
		yyval.cmd.command_u.cmd_for.step=yyvsp[-2].expr;
	}
    break;

  case 278:
#line 1087 "ace.yacc"
    { yyval.expr.type=EXPRTYPE_INT; yyval.expr.expr_u.i=1; }
    break;

  case 279:
#line 1088 "ace.yacc"
    { yyval.expr=yyvsp[-1].expr;}
    break;

  case 280:
#line 1092 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_IF;
	yyval.cmd.command_u.cmd_if.condition=yyvsp[-3].expr;
	yyval.cmd.command_u.cmd_if.command=(struct command *)DUP(yyvsp[-1].cmd);
	yyval.cmd.command_u.cmd_if.elsecommand=(struct command *)DUP(yyvsp[0].cmd);
}
    break;

  case 281:
#line 1100 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_NULL;
		yyval.cmd.command_u.null=1;
	}
    break;

  case 282:
#line 1103 "ace.yacc"
    { COPY(yyval.cmd,yyvsp[0].cmd); }
    break;

  case 283:
#line 1108 "ace.yacc"
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
#line 1119 "ace.yacc"
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
#line 1130 "ace.yacc"
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
#line 1143 "ace.yacc"
    {

	yyval.expr.type=EXPRTYPE_COMPLEX;
	yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr));
	COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr);
	COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr);
	yyval.expr.expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 288:
#line 1155 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_NEED;
	yyval.cmd.command_u.cmd_need.nlines=atoi(yyvsp[-1].str);
}
    break;

  case 289:
#line 1161 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PAUSE;
	yyval.cmd.command_u.cmd_pause.message=strdup(yyvsp[0].str);
}
    break;

  case 290:
#line 1168 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PRINT;
	yyval.cmd.command_u.cmd_print.printnl=atoi(yyvsp[0].str);
	yyval.cmd.command_u.cmd_print.print=yyvsp[-1].expr;
}
    break;

  case 291:
#line 1176 "ace.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 292:
#line 1176 "ace.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 293:
#line 1179 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PRINTFILE;
	yyval.cmd.command_u.cmd_printfile.filename=strdup(yyvsp[0].str);
}
    break;

  case 294:
#line 1185 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_SKIP;
		yyval.cmd.command_u.cmd_skip.nlines=atoi(yyvsp[-1].str);

	}
    break;

  case 295:
#line 1190 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_SKIP;
		yyval.cmd.command_u.cmd_skip.nlines=-1;
	}
    break;

  case 296:
#line 1197 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_WHILE;
		yyval.cmd.command_u.cmd_while.condition=yyvsp[-2].expr;
		yyval.cmd.command_u.cmd_while.command=(struct command *)DUP(yyvsp[0].cmd);
}
    break;

  case 301:
#line 1221 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[0].agg_val);
		yyval.agg_val.isgroup=0;
	}
    break;

  case 302:
#line 1225 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[-2].agg_val);
		yyval.agg_val.wexpr=(struct expr *)DUP(yyvsp[0].expr);
		yyval.agg_val.isgroup=0;
	}
    break;

  case 303:
#line 1230 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[0].agg_val);
		yyval.agg_val.isgroup=1;
	}
    break;

  case 304:
#line 1234 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[-2].agg_val);
		yyval.agg_val.wexpr=(struct expr *)DUP(yyvsp[0].expr);
		yyval.agg_val.isgroup=1;
	}
    break;

  case 305:
#line 1242 "ace.yacc"
    {
		yyval.agg_val.type=AGG_COUNT;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=0;
	}
    break;

  case 306:
#line 1247 "ace.yacc"
    {
		yyval.agg_val.type=AGG_PERCENT;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=0;
	}
    break;

  case 307:
#line 1252 "ace.yacc"
    {
		yyval.agg_val.type=AGG_AVG;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 308:
#line 1257 "ace.yacc"
    {
		yyval.agg_val.type=AGG_TOTAL;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 309:
#line 1262 "ace.yacc"
    {
		yyval.agg_val.type=AGG_AVG;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 310:
#line 1267 "ace.yacc"
    {
		yyval.agg_val.type=AGG_MIN;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 311:
#line 1272 "ace.yacc"
    {
		yyval.agg_val.type=AGG_MAX;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 312:
#line 1281 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 313:
#line 1289 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 314:
#line 1296 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 315:
#line 1305 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 316:
#line 1311 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 317:
#line 1318 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 318:
#line 1326 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 319:
#line 1335 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX;
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 320:
#line 1342 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX;
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 321:
#line 1349 "ace.yacc"
    { COPY(yyval.expr,yyvsp[0].expr); }
    break;

  case 322:
#line 1351 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_COMPARE;
		yyval.expr.expr_u.cexpr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.cexpr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.cexpr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.cexpr->method=strdup(yyvsp[-1].str); 
	}
    break;

  case 323:
#line 1358 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=1;
		}
    break;

  case 324:
#line 1362 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0;
		}
    break;

  case 325:
#line 1366 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_BUILTIN;
		yyval.expr.expr_u.name=strdup(yyvsp[0].str);
	}
    break;

  case 326:
#line 1370 "ace.yacc"
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
#line 1380 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("DATE");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 328:
#line 1387 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("MONTH");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 329:
#line 1393 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("YEAR");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 330:
#line 1399 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("DAY");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 331:
#line 1406 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup(yyvsp[-3].str);
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 332:
#line 1412 "ace.yacc"
    { COPY(yyval.expr,yyvsp[-1].expr); }
    break;

  case 333:
#line 1413 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[0].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 334:
#line 1419 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[0].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 335:
#line 1425 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 336:
#line 1432 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 337:
#line 1438 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 338:
#line 1446 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 339:
#line 1453 "ace.yacc"
    {
		printf("NIY\n");
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 340:
#line 1457 "ace.yacc"
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
#line 1467 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_AGG; 
		yyval.expr.expr_u.aggid=add_agg(yyvsp[0].agg_val);
	}
    break;

  case 342:
#line 1473 "ace.yacc"
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
#line 1484 "ace.yacc"
    {
		COPY(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 344:
#line 1491 "ace.yacc"
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
#line 1498 "ace.yacc"
    {
		COPY(yyval.expr,yyvsp[-2].expr);
		yyval.expr.expr_u.lexpr->elem.elem_len++;
		yyval.expr.expr_u.lexpr->elem.elem_val=realloc( yyval.expr.expr_u.lexpr->elem.elem_val,sizeof(struct expr)* yyval.expr.expr_u.lexpr->elem.elem_len);
		COPY(yyval.expr.expr_u.lexpr->elem.elem_val[ yyval.expr.expr_u.lexpr->elem.elem_len-1 ],yyvsp[0].expr);

	}
    break;

  case 346:
#line 1507 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_NULL;
	}
    break;

  case 347:
#line 1513 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_STRING;
		yyval.expr.expr_u.s=strdup(yyvsp[0].str);
	}
    break;

  case 348:
#line 1517 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_DOUBLE;
		yyval.expr.expr_u.d=atof(yyvsp[0].str);
	}
    break;

  case 349:
#line 1521 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_DOUBLE;
		yyval.expr.expr_u.d=atof(yyvsp[0].str);
	}
    break;

  case 350:
#line 1525 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 351:
#line 1529 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 352:
#line 1533 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 353:
#line 1537 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0-atoi(yyvsp[0].str);
	}
    break;

  case 354:
#line 1541 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0-atoi(yyvsp[0].str);
	}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 3846 "y.tab.c"

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


#line 1548 "ace.yacc"



#include "lex.yy.c"


