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
     AFTER = 258,
     AFTGROUP = 259,
     ALL = 260,
     AND = 261,
     ANY = 262,
     ASC = 263,
     ASCII = 264,
     ATSIGN = 265,
     AVERAGE = 266,
     AVG = 267,
     BEFORE = 268,
     BETWEEN = 269,
     BOTTOM = 270,
     BY = 271,
     KW_CALL = 272,
     CH = 273,
     CHAR = 274,
     CHAR_VALUE = 275,
     CLIPPED = 276,
     CLOSE_BRACKET = 277,
     CLOSE_SQUARE = 278,
     COLON = 279,
     COLUMN = 280,
     COMMA = 281,
     COMMANDS = 282,
     COMPARISON = 283,
     COUNT = 284,
     DATABASE = 285,
     DATE = 286,
     DATETIME = 287,
     DAY = 288,
     DECIMAL = 289,
     DEFINE = 290,
     DELIMITER = 291,
     DESC = 292,
     DISTINCT = 293,
     DIVIDE = 294,
     DO = 295,
     DOLLAR = 296,
     DOT = 297,
     ELSE = 298,
     END = 299,
     EQUAL = 300,
     ESCAPE = 301,
     EVERY = 302,
     EXISTS = 303,
     EXTERNAL = 304,
     FIRST = 305,
     FLOAT = 306,
     PIPE = 307,
     FOR = 308,
     FORMAT = 309,
     FRACTION = 310,
     FROM = 311,
     FUNCTION = 312,
     GREATER_THAN = 313,
     GREATER_THAN_EQ = 314,
     GROUP = 315,
     GROUP_BY = 316,
     HAVING = 317,
     HEADER = 318,
     HOUR = 319,
     IF = 320,
     IN = 321,
     INPUT = 322,
     INTEGER = 323,
     INTERVAL = 324,
     INTO = 325,
     INTVAL = 326,
     IS_NOT_NULL = 327,
     IS_NULL = 328,
     KW_FALSE = 329,
     KW_TRUE = 330,
     LAST = 331,
     LEFT = 332,
     LENGTH = 333,
     LESS_THAN = 334,
     LESS_THAN_EQ = 335,
     LET = 336,
     LIKE = 337,
     LINES = 338,
     MARGIN = 339,
     MATCHES = 340,
     MINUS = 341,
     MINUTE = 342,
     MOD = 343,
     MONEY = 344,
     MONTH = 345,
     MULTIPLY = 346,
     NAMED = 347,
     NEED = 348,
     NOT = 349,
     NOT_EQUAL = 350,
     NOT_EXISTS = 351,
     NOT_IN = 352,
     NOT_LIKE = 353,
     NOT_MATCHES = 354,
     NUMBER_VALUE = 355,
     NUMERIC = 356,
     OF = 357,
     ON = 358,
     ROW = 359,
     OPEN_BRACKET = 360,
     OPEN_SQUARE = 361,
     OR = 362,
     ORDER_BY = 363,
     ORDER_EXTERNAL_BY = 364,
     OUTER = 365,
     OUTPUT = 366,
     PAGE = 367,
     PAGE_HEADER = 368,
     PAGE_TRAILER = 369,
     PARAM = 370,
     PAUSE = 371,
     PERCENT = 372,
     PLUS = 373,
     POW = 374,
     PRINT = 375,
     PRINTER = 376,
     PRINT_FILE = 377,
     PROMPT = 378,
     READ = 379,
     REPORT = 380,
     RIGHT = 381,
     SECOND = 382,
     SELECT = 383,
     SEMICOLON = 384,
     SKIP = 385,
     SMALLFLOAT = 386,
     SMALLINT = 387,
     SOME = 388,
     SPACES = 389,
     STEP = 390,
     SUM = 391,
     TEMP = 392,
     THEN = 393,
     TO = 394,
     TOP = 395,
     TOP_OF_PAGE = 396,
     TOTAL = 397,
     TRAILER = 398,
     UNION = 399,
     UNIQUE = 400,
     UNITS_DAY = 401,
     UNITS_HOUR = 402,
     UNITS_MINUTE = 403,
     UNITS_MONTH = 404,
     UNITS_SECOND = 405,
     UNITS_YEAR = 406,
     UPDATE = 407,
     USER = 408,
     USING = 409,
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
#define AFTER 258
#define AFTGROUP 259
#define ALL 260
#define AND 261
#define ANY 262
#define ASC 263
#define ASCII 264
#define ATSIGN 265
#define AVERAGE 266
#define AVG 267
#define BEFORE 268
#define BETWEEN 269
#define BOTTOM 270
#define BY 271
#define KW_CALL 272
#define CH 273
#define CHAR 274
#define CHAR_VALUE 275
#define CLIPPED 276
#define CLOSE_BRACKET 277
#define CLOSE_SQUARE 278
#define COLON 279
#define COLUMN 280
#define COMMA 281
#define COMMANDS 282
#define COMPARISON 283
#define COUNT 284
#define DATABASE 285
#define DATE 286
#define DATETIME 287
#define DAY 288
#define DECIMAL 289
#define DEFINE 290
#define DELIMITER 291
#define DESC 292
#define DISTINCT 293
#define DIVIDE 294
#define DO 295
#define DOLLAR 296
#define DOT 297
#define ELSE 298
#define END 299
#define EQUAL 300
#define ESCAPE 301
#define EVERY 302
#define EXISTS 303
#define EXTERNAL 304
#define FIRST 305
#define FLOAT 306
#define PIPE 307
#define FOR 308
#define FORMAT 309
#define FRACTION 310
#define FROM 311
#define FUNCTION 312
#define GREATER_THAN 313
#define GREATER_THAN_EQ 314
#define GROUP 315
#define GROUP_BY 316
#define HAVING 317
#define HEADER 318
#define HOUR 319
#define IF 320
#define IN 321
#define INPUT 322
#define INTEGER 323
#define INTERVAL 324
#define INTO 325
#define INTVAL 326
#define IS_NOT_NULL 327
#define IS_NULL 328
#define KW_FALSE 329
#define KW_TRUE 330
#define LAST 331
#define LEFT 332
#define LENGTH 333
#define LESS_THAN 334
#define LESS_THAN_EQ 335
#define LET 336
#define LIKE 337
#define LINES 338
#define MARGIN 339
#define MATCHES 340
#define MINUS 341
#define MINUTE 342
#define MOD 343
#define MONEY 344
#define MONTH 345
#define MULTIPLY 346
#define NAMED 347
#define NEED 348
#define NOT 349
#define NOT_EQUAL 350
#define NOT_EXISTS 351
#define NOT_IN 352
#define NOT_LIKE 353
#define NOT_MATCHES 354
#define NUMBER_VALUE 355
#define NUMERIC 356
#define OF 357
#define ON 358
#define ROW 359
#define OPEN_BRACKET 360
#define OPEN_SQUARE 361
#define OR 362
#define ORDER_BY 363
#define ORDER_EXTERNAL_BY 364
#define OUTER 365
#define OUTPUT 366
#define PAGE 367
#define PAGE_HEADER 368
#define PAGE_TRAILER 369
#define PARAM 370
#define PAUSE 371
#define PERCENT 372
#define PLUS 373
#define POW 374
#define PRINT 375
#define PRINTER 376
#define PRINT_FILE 377
#define PROMPT 378
#define READ 379
#define REPORT 380
#define RIGHT 381
#define SECOND 382
#define SELECT 383
#define SEMICOLON 384
#define SKIP 385
#define SMALLFLOAT 386
#define SMALLINT 387
#define SOME 388
#define SPACES 389
#define STEP 390
#define SUM 391
#define TEMP 392
#define THEN 393
#define TO 394
#define TOP 395
#define TOP_OF_PAGE 396
#define TOTAL 397
#define TRAILER 398
#define UNION 399
#define UNIQUE 400
#define UNITS_DAY 401
#define UNITS_HOUR 402
#define UNITS_MINUTE 403
#define UNITS_MONTH 404
#define UNITS_SECOND 405
#define UNITS_YEAR 406
#define UPDATE 407
#define USER 408
#define USING 409
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
#line 72 "ace.yacc"
typedef union YYSTYPE {
	char	str[30000];
	struct command cmd;
	struct expr expr;
	struct commands commands;
	struct agg_val agg_val;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 485 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 497 "y.tab.c"

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
#define YYLAST   1649

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  121
/* YYNRULES -- Number of rules. */
#define YYNRULES  355
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
     431,   433,   435,   437,   439,   441,   444,   446,   448,   454,
     458,   464,   468,   470,   474,   475,   477,   481,   485,   489,
     493,   500,   506,   508,   510,   512,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   537,   539,
     541,   543,   545,   547,   551,   555,   557,   559,   560,   564,
     570,   573,   578,   582,   584,   586,   589,   590,   597,   599,
     605,   606,   610,   612,   617,   618,   620,   622,   629,   630,
     632,   634,   636,   638,   642,   644,   647,   649,   651,   653,
     655,   657,   659,   661,   665,   669,   673,   676,   680,   684,
     688,   690,   692,   697,   704,   711,   720,   723,   727,   731,
     733,   735,   737,   739,   743,   748,   753,   758,   763,   768,
     773,   779,   785,   791,   797,   803,   805,   809,   810,   812,
     814,   817,   819,   821,   823,   825,   827,   829,   831,   833,
     835,   837,   841,   847,   849,   851,   853,   855,   857,   867,
     868,   871,   877,   878,   881,   886,   894,   904,   906,   910,
     914,   917,   921,   922,   924,   927,   931,   935,   940,   942,
     944,   946,   948,   950,   954,   957,   962,   964,   966,   970,
     974,   978,   982,   986,   990,   994,   998,  1002,  1006,  1010,
    1014,  1018,  1022,  1024,  1028,  1030,  1032,  1034,  1036,  1041,
    1046,  1051,  1056,  1061,  1065,  1068,  1071,  1074,  1077,  1080,
    1083,  1086,  1088,  1090,  1092,  1094,  1096,  1100,  1101,  1103,
    1105,  1107,  1109,  1112,  1115,  1118
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     165,     0,    -1,   166,   167,   175,   179,   183,   187,    -1,
      30,     9,    44,    -1,    30,    92,    44,    -1,    -1,   168,
      -1,    35,   169,    44,    -1,   170,    -1,   169,   170,    -1,
       9,   172,    -1,   156,   173,   174,    -1,   115,   106,   274,
      23,   173,   174,    -1,    57,   171,    -1,    92,    -1,   173,
     174,    -1,   172,    26,   173,   174,    -1,    92,    -1,    57,
      -1,    68,    -1,    19,    -1,    19,   105,   274,    22,    -1,
     155,    -1,   155,   105,   274,    22,    -1,    31,    -1,    51,
      -1,   131,    -1,   132,    -1,    32,    -1,    69,    -1,    89,
      -1,    89,   105,   274,    22,    -1,    89,   105,   274,    26,
     274,    22,    -1,    34,    -1,    34,   105,   274,    22,    -1,
      34,   105,   274,    26,   274,    22,    -1,    -1,   176,    -1,
      67,   177,    44,    -1,   178,    -1,   177,   178,    -1,   123,
      53,   173,   154,   275,    -1,    -1,   180,    -1,   111,   181,
      44,    -1,   182,    -1,   181,   182,    -1,   125,   139,   121,
     275,    -1,   125,   139,   121,    -1,   125,   139,   275,    -1,
     125,   139,    52,   275,    -1,    77,    84,   274,    -1,    15,
      84,   274,    -1,   140,    84,   274,    -1,   112,    78,   274,
      -1,   126,    84,   274,    -1,   141,   275,    -1,   185,    44,
      -1,   184,    44,    -1,   242,    -1,   184,   129,   242,    -1,
     124,   275,   186,   193,    -1,    -1,    36,   275,    -1,    54,
      47,   104,    44,    -1,    54,   189,   188,    -1,    -1,    44,
      -1,   190,    -1,   189,   190,    -1,    50,   112,    63,   257,
      -1,   112,   143,   257,    -1,   112,    63,   257,    -1,   103,
      47,   104,   257,    -1,   103,    76,   104,   257,    -1,    13,
      60,   102,   192,   257,    -1,     3,    60,   102,   192,   257,
      -1,    92,   106,   277,    26,   277,    23,    -1,    92,   106,
     277,    23,    -1,    92,    -1,   191,    -1,    71,    -1,    -1,
     194,    -1,    -1,   108,   195,   199,    -1,   109,   199,    -1,
      20,    -1,   101,    -1,   241,    -1,    71,    -1,   118,   241,
      -1,   118,    71,    -1,    86,   241,    -1,    86,    71,    -1,
      -1,   108,   198,   199,    -1,   200,    -1,   199,    26,   200,
      -1,   201,   202,    -1,    71,    -1,   239,    -1,    -1,     8,
      -1,    37,    -1,    62,   216,    -1,    61,   205,    -1,   252,
      -1,   205,    26,   252,    -1,   157,   216,    -1,    56,   208,
      -1,   209,    -1,   208,    26,   209,    -1,   210,    -1,   110,
     210,    -1,   110,   105,   211,    22,    -1,   235,    -1,   235,
     240,    -1,   209,    -1,   211,    26,   209,    -1,   207,   213,
     214,   215,    -1,    -1,   206,    -1,    -1,   204,    -1,    -1,
     203,    -1,   217,    -1,   216,   107,   217,    -1,   218,    -1,
     217,     6,   218,    -1,   219,    -1,    94,   219,    -1,   233,
      -1,   105,   216,    22,    -1,    48,   249,    -1,    96,   249,
      -1,   254,   232,   222,   249,    -1,   249,   232,   254,    -1,
      -1,   223,    -1,   224,    -1,     5,    -1,   133,    -1,     7,
      -1,    46,   227,    -1,   256,    -1,   256,    -1,   254,    66,
     105,   229,    22,    -1,   254,    66,   249,    -1,   254,    97,
     105,   229,    22,    -1,   254,    97,   249,    -1,   256,    -1,
     229,    26,   256,    -1,    -1,    94,    -1,   254,   230,    73,
      -1,   254,   230,    72,    -1,   254,   232,   254,    -1,   254,
     232,   249,    -1,   254,   230,    14,   254,     6,   254,    -1,
     254,   230,    82,   226,   225,    -1,    45,    -1,    28,    -1,
      95,    -1,    79,    -1,    58,    -1,    99,    -1,    98,    -1,
      85,    -1,    82,    -1,    80,    -1,    59,    -1,   231,    -1,
     228,    -1,   221,    -1,   220,    -1,    -1,     5,    -1,    38,
      -1,   145,    -1,    20,    -1,   237,    -1,   236,    24,   237,
      -1,    20,    42,   237,    -1,   276,    -1,   276,    -1,    -1,
     106,    71,    23,    -1,   106,    71,    26,    71,    23,    -1,
     276,   238,    -1,   235,    42,   276,   238,    -1,   235,    42,
      91,    -1,   276,    -1,   100,    -1,    42,    71,    -1,    -1,
     128,   243,   250,   184,   212,   246,    -1,   245,    -1,   128,
     250,   184,   212,   246,    -1,    -1,   144,   234,   244,    -1,
     197,    -1,    70,   137,   248,   247,    -1,    -1,   159,    -1,
     276,    -1,   105,   128,   250,   184,   212,    22,    -1,    -1,
       5,    -1,    38,    -1,   145,    -1,   251,    -1,   184,    26,
     251,    -1,   254,    -1,   254,    92,    -1,   254,    -1,   151,
      -1,   149,    -1,   146,    -1,   147,    -1,   148,    -1,   150,
      -1,   254,    39,   254,    -1,   254,    88,   254,    -1,   254,
     119,   254,    -1,   254,   253,    -1,   254,    91,   254,    -1,
     254,   118,   254,    -1,   254,    86,   254,    -1,   196,    -1,
     276,    -1,   276,   106,   274,    23,    -1,   276,   106,   274,
      26,   274,    23,    -1,   276,    42,   276,   106,   274,    23,
      -1,   276,    42,   276,   106,   274,    26,   274,    23,    -1,
      41,   276,    -1,   276,    42,   276,    -1,   276,    42,    91,
      -1,    75,    -1,    74,    -1,   153,    -1,    91,    -1,   105,
     254,    22,    -1,    31,   105,   255,    22,    -1,    33,   105,
     255,    22,    -1,    90,   105,   255,    22,    -1,   163,   105,
     255,    22,    -1,   276,   105,   255,    22,    -1,    29,   105,
      91,    22,    -1,    12,   105,   234,   254,    22,    -1,   161,
     105,   234,   254,    22,    -1,   162,   105,   234,   254,    22,
      -1,   136,   105,   234,   254,    22,    -1,    29,   105,   234,
     254,    22,    -1,   254,    -1,   255,    26,   254,    -1,    -1,
     196,    -1,   258,    -1,   257,   258,    -1,   261,    -1,   263,
      -1,   273,    -1,   265,    -1,   267,    -1,   268,    -1,   272,
      -1,   269,    -1,   271,    -1,   259,    -1,   160,   257,    44,
      -1,    17,   260,   105,   281,    22,    -1,    31,    -1,    90,
      -1,   163,    -1,    33,    -1,   276,    -1,    53,   173,    45,
     277,   139,   277,   262,    40,   258,    -1,    -1,   135,   277,
      -1,    65,   277,   138,   258,   264,    -1,    -1,    43,   258,
      -1,    81,    92,    45,   266,    -1,    81,    92,   106,   277,
      23,    45,   266,    -1,    81,    92,   106,   277,    26,   277,
      23,    45,   266,    -1,   277,    -1,   266,    26,   277,    -1,
      93,   274,    83,    -1,   116,   275,    -1,   120,   266,   270,
      -1,    -1,   129,    -1,   122,   275,    -1,   130,   274,    83,
      -1,   130,   139,   141,    -1,   158,   277,    40,   258,    -1,
      71,    -1,    20,    -1,    92,    -1,   280,    -1,   279,    -1,
     279,   157,   277,    -1,    60,   279,    -1,    60,   279,   157,
     277,    -1,    29,    -1,   117,    -1,    11,   102,   277,    -1,
     142,   102,   277,    -1,    12,   102,   277,    -1,   162,   102,
     277,    -1,   161,   102,   277,    -1,   280,    39,   280,    -1,
     280,   119,   280,    -1,   280,    88,   280,    -1,   280,    91,
     280,    -1,   280,   118,   280,    -1,   280,     6,   280,    -1,
     280,   107,   280,    -1,   280,    86,   280,    -1,   280,   154,
     280,    -1,   284,    -1,   280,   232,   280,    -1,    75,    -1,
      74,    -1,   153,    -1,    31,    -1,    31,   105,   282,    22,
      -1,    90,   105,   282,    22,    -1,   163,   105,   282,    22,
      -1,    33,   105,   282,    22,    -1,    92,   105,   282,    22,
      -1,   105,   280,    22,    -1,    25,   280,    -1,     9,   280,
      -1,   280,   134,    -1,   280,    73,    -1,   280,    72,    -1,
     280,    21,    -1,   280,   253,    -1,   191,    -1,   278,    -1,
     283,    -1,   282,    -1,   280,    -1,   282,    26,   280,    -1,
      -1,    20,    -1,   101,    -1,   241,    -1,    71,    -1,   118,
     241,    -1,   118,    71,    -1,    86,   241,    -1,    86,    71,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   245,   245,   253,   256,   265,   267,   272,   276,   276,
     280,   284,   287,   290,   295,   298,   298,   301,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   333,   334,   337,   341,
     341,   344,   349,   349,   352,   355,   355,   359,   360,   361,
     362,   363,   366,   369,   372,   375,   378,   385,   385,   389,
     390,   394,   397,   397,   401,   407,   411,   411,   415,   415,
     419,   423,   427,   431,   435,   439,   443,   451,   452,   453,
     457,   457,   468,   468,   471,   471,   474,   484,   487,   488,
     489,   490,   492,   494,   496,   504,   504,   514,   515,   520,
     522,   527,   534,   535,   536,   541,   547,   552,   553,   558,
     563,   567,   568,   573,   574,   575,   578,   579,   586,   586,
     590,   601,   602,   605,   606,   609,   610,   615,   616,   621,
     622,   627,   628,   633,   634,   640,   641,   646,   648,   653,
     654,   655,   658,   662,   663,   671,   676,   680,   685,   687,
     689,   691,   697,   698,   702,   703,   708,   710,   712,   714,
     716,   718,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   740,   741,   742,   743,   745,   746,   747,
     748,   770,   771,   772,   773,   777,   781,   785,   786,   787,
     790,   791,   792,   798,   803,   803,   816,   816,   834,   837,
     844,   845,   848,   849,   855,   855,   859,   876,   880,   881,
     882,   883,   887,   888,   892,   895,   902,   905,   906,   907,
     908,   909,   910,   914,   916,   918,   920,   922,   924,   926,
     928,   929,   930,   931,   932,   933,   934,   939,   941,   943,
     944,   945,   946,   947,   948,   949,   950,   951,   952,   953,
     955,   957,   959,   961,   963,   969,   969,   975,   976,   988,
     993,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1050,  1061,  1062,  1063,  1064,  1065,  1068,  1077,
    1078,  1082,  1090,  1093,  1098,  1109,  1120,  1133,  1133,  1145,
    1151,  1158,  1166,  1166,  1169,  1175,  1180,  1187,  1196,  1199,
    1203,  1207,  1211,  1215,  1220,  1224,  1232,  1237,  1242,  1247,
    1252,  1257,  1262,  1270,  1278,  1285,  1294,  1301,  1308,  1316,
    1325,  1332,  1339,  1341,  1348,  1352,  1356,  1360,  1370,  1377,
    1383,  1389,  1396,  1402,  1403,  1409,  1415,  1422,  1428,  1436,
    1443,  1447,  1457,  1463,  1474,  1481,  1488,  1497,  1503,  1507,
    1511,  1515,  1519,  1523,  1527,  1531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AFTER", "AFTGROUP", "ALL", "AND", "ANY", 
  "ASC", "ASCII", "ATSIGN", "AVERAGE", "AVG", "BEFORE", "BETWEEN", 
  "BOTTOM", "BY", "KW_CALL", "CH", "CHAR", "CHAR_VALUE", "CLIPPED", 
  "CLOSE_BRACKET", "CLOSE_SQUARE", "COLON", "COLUMN", "COMMA", "COMMANDS", 
  "COMPARISON", "COUNT", "DATABASE", "DATE", "DATETIME", "DAY", "DECIMAL", 
  "DEFINE", "DELIMITER", "DESC", "DISTINCT", "DIVIDE", "DO", "DOLLAR", 
  "DOT", "ELSE", "END", "EQUAL", "ESCAPE", "EVERY", "EXISTS", "EXTERNAL", 
  "FIRST", "FLOAT", "PIPE", "FOR", "FORMAT", "FRACTION", "FROM", 
  "FUNCTION", "GREATER_THAN", "GREATER_THAN_EQ", "GROUP", "GROUP_BY", 
  "HAVING", "HEADER", "HOUR", "IF", "IN", "INPUT", "INTEGER", "INTERVAL", 
  "INTO", "INTVAL", "IS_NOT_NULL", "IS_NULL", "KW_FALSE", "KW_TRUE", 
  "LAST", "LEFT", "LENGTH", "LESS_THAN", "LESS_THAN_EQ", "LET", "LIKE", 
  "LINES", "MARGIN", "MATCHES", "MINUS", "MINUTE", "MOD", "MONEY", 
  "MONTH", "MULTIPLY", "NAMED", "NEED", "NOT", "NOT_EQUAL", "NOT_EXISTS", 
  "NOT_IN", "NOT_LIKE", "NOT_MATCHES", "NUMBER_VALUE", "NUMERIC", "OF", 
  "ON", "ROW", "OPEN_BRACKET", "OPEN_SQUARE", "OR", "ORDER_BY", 
  "ORDER_EXTERNAL_BY", "OUTER", "OUTPUT", "PAGE", "PAGE_HEADER", 
  "PAGE_TRAILER", "PARAM", "PAUSE", "PERCENT", "PLUS", "POW", "PRINT", 
  "PRINTER", "PRINT_FILE", "PROMPT", "READ", "REPORT", "RIGHT", "SECOND", 
  "SELECT", "SEMICOLON", "SKIP", "SMALLFLOAT", "SMALLINT", "SOME", 
  "SPACES", "STEP", "SUM", "TEMP", "THEN", "TO", "TOP", "TOP_OF_PAGE", 
  "TOTAL", "TRAILER", "UNION", "UNIQUE", "UNITS_DAY", "UNITS_HOUR", 
  "UNITS_MINUTE", "UNITS_MONTH", "UNITS_SECOND", "UNITS_YEAR", "UPDATE", 
  "USER", "USING", "VARCHAR", "VARIABLE", "WHERE", "WHILE", "WITH_NO_LOG", 
  "XBEGIN", "XMAX", "XMIN", "YEAR", "$accept", "ace_report", "db_section", 
  "op_define_section", "define_section", "define_element_list", 
  "define_element", "ufunc_name", "def_ascii_list", "variable", 
  "datatype", "op_input_section", "input_section", "prompt_section", 
  "prompt_element", "op_output_section", "output_section", 
  "output_element_list", "output_element", "select_section", 
  "select_list", "read_list", "op_delim", "format_section", "op_end", 
  "format_actions", "format_action", "variable_sub", "variable_sub_a", 
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
  "tmp_tabname", "subquery", "op_ad", "value_expression_pls", 
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
     222,   222,   223,   224,   224,   225,   226,   227,   228,   228,
     228,   228,   229,   229,   230,   230,   231,   231,   231,   231,
     231,   231,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   233,   233,   233,   233,   234,   234,   234,
     234,   235,   235,   235,   235,   236,   237,   238,   238,   238,
     239,   239,   239,   240,   241,   241,   243,   242,   244,   245,
     246,   246,   246,   246,   247,   247,   248,   249,   250,   250,
     250,   250,   184,   184,   251,   251,   252,   253,   253,   253,
     253,   253,   253,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   255,   255,   256,   256,   257,
     257,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   259,   260,   260,   260,   260,   260,   261,   262,
     262,   263,   264,   264,   265,   265,   265,   266,   266,   267,
     268,   269,   270,   270,   271,   272,   272,   273,   274,   275,
     276,   277,   278,   278,   278,   278,   279,   279,   279,   279,
     279,   279,   279,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   281,   281,   282,   282,   283,   284,   284,
     284,   284,   284,   284,   284,   284
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
       3,     1,     2,     1,     3,     2,     2,     4,     3,     0,
       1,     1,     1,     1,     1,     2,     1,     1,     5,     3,
       5,     3,     1,     3,     0,     1,     3,     3,     3,     3,
       6,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     0,     3,     5,
       2,     4,     3,     1,     1,     2,     0,     6,     1,     5,
       0,     3,     1,     4,     0,     1,     1,     6,     0,     1,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     2,     3,     3,     3,
       1,     1,     4,     6,     6,     8,     2,     3,     3,     1,
       1,     1,     1,     3,     4,     4,     4,     4,     4,     4,
       5,     5,     5,     5,     5,     1,     3,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     1,     1,     1,     1,     1,     9,     0,
       2,     5,     0,     2,     4,     7,     9,     1,     3,     3,
       2,     3,     0,     1,     2,     3,     3,     4,     1,     1,
       1,     1,     1,     3,     2,     4,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     3,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     2,     2,     2,     2
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
     298,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,    87,     0,     0,     0,
       0,     0,    90,   240,   239,     0,     0,   242,   300,   194,
      88,     0,     0,     0,   196,     0,   241,     0,     0,     0,
       0,     0,     0,   230,    89,    59,   212,   214,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   299,    56,    44,    46,   177,   177,     0,     0,
     236,   195,    94,    93,     0,     0,    92,    91,    62,   208,
     177,   177,   177,     0,     0,     2,     0,    58,     0,    57,
       0,     0,     0,     0,   215,     0,     0,   219,   220,   221,
     218,   222,   217,   226,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,    52,    51,    54,     0,    48,    49,
      55,    53,   178,   179,   180,     0,     0,     0,   255,     0,
       0,     0,   243,     0,    82,   209,   210,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      68,   213,    60,   223,   229,   224,   227,   228,   225,   238,
     237,     0,     0,    21,    34,     0,    31,     0,    23,    12,
      41,    50,    47,     0,   249,     0,   244,     0,   245,   246,
      63,    84,     0,    61,    83,     0,     0,     0,     0,   247,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    65,
      69,     0,   248,   232,     0,     0,     0,   250,   254,   256,
       0,   181,   100,    86,    97,   102,     0,     0,   182,   101,
     187,     0,   121,   200,   253,   251,   252,     0,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,   259,   270,   261,   262,   264,
     265,   266,   268,   269,   267,   263,    71,     0,     0,    35,
      32,    85,     0,     0,   103,   104,    99,     0,     0,     0,
     190,     0,   110,   111,   113,   116,   186,     0,   122,   123,
       0,    95,   177,   202,   197,    81,    79,    80,     0,     0,
      70,    73,    74,   273,   276,   274,   275,     0,   277,     0,
       0,     0,     0,   348,     0,   306,   327,     0,     0,   351,
     325,   324,     0,     0,    79,   349,     0,   307,     0,     0,
     326,     0,     0,     0,   341,   350,     0,   342,   302,   301,
     322,     0,     0,   290,   292,   287,   294,     0,     0,     0,
       0,   260,   234,     0,   233,   184,   186,    98,   192,   187,
     183,     0,     0,   114,     0,   117,   193,     0,     0,     0,
       0,   109,   127,   129,   131,   176,   175,   174,   173,   133,
       0,   154,     0,   124,   125,     0,     0,     0,     0,    76,
      75,   347,     0,   335,     0,     0,   334,     0,     0,   304,
     355,   354,     0,     0,     0,   353,   352,     0,     0,     0,
       0,     0,     0,     0,   339,   163,     0,   162,   166,   172,
     338,   337,   165,   171,   170,   169,     0,     0,     0,   164,
     168,   167,     0,     0,     0,   336,     0,     0,   340,     0,
       0,   289,     0,   293,   291,   296,   295,     0,   271,     0,
     191,   188,     0,   118,     0,   112,     0,   135,   132,   136,
     208,     0,   154,     0,     0,     0,     0,   155,     0,     0,
       0,   106,   107,   216,     0,   126,   120,   204,   206,    96,
     208,   201,   198,     0,   345,     0,   344,   343,     0,   308,
     310,     0,     0,     0,     0,     0,   333,   309,   312,   311,
       0,   282,   303,   318,   313,   320,   315,   316,   319,   317,
     314,   321,   323,   284,     0,   288,   297,   235,     0,   115,
       0,     0,   134,   128,   130,   138,   257,   149,   257,   151,
       0,   157,   156,   257,   142,   144,     0,   143,     0,   140,
     141,   159,   158,     0,   105,   205,   203,     0,    78,     0,
     272,     0,     0,   328,   331,   305,   329,   332,   330,     0,
     281,     0,     0,   189,   119,     0,   258,     0,   152,     0,
       0,     0,   146,   137,   108,     0,     0,   346,   279,   283,
       0,     0,     0,   148,   257,   150,     0,   257,   161,   200,
      77,     0,     0,   285,     0,   207,   153,   160,   145,   147,
     199,   280,     0,     0,   278,   286
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    90,
      91,    92,   184,   135,   249,   199,   200,   374,   338,   233,
     234,   260,    93,   333,   426,   263,   264,   265,   316,   515,
     423,   511,   328,   272,   322,   323,   324,   494,   273,   329,
     424,   516,   411,   412,   413,   414,   415,   416,   578,   579,
     580,   628,   611,   638,   417,   607,   509,   418,   477,   419,
     175,   325,   267,   268,   320,   269,   405,    94,    95,   129,
     521,   522,   334,   586,   517,   420,   188,    96,   512,   153,
      97,   179,   608,   294,   295,   296,   347,   297,   632,   298,
     600,   299,   384,   300,   301,   302,   484,   303,   304,   305,
      51,   113,    98,   385,   377,   378,   379,   525,   526,   527,
     380
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -537
static const short yypact[] =
{
       7,    67,    56,    46,    48,    64,  -537,    21,    79,  -537,
    -537,  -537,    87,   105,    28,    87,    36,  -537,    95,    60,
    -537,  -537,   217,   542,  -537,  -537,   178,   542,  -537,  -537,
     198,   -11,  -537,   307,   778,  -537,    87,   161,  -537,  -537,
     167,  -537,  -537,  -537,  -537,   181,  -537,  -537,   187,  -537,
    -537,   276,  -537,    87,  -537,  -537,   222,   240,   261,   190,
     265,   271,   338,   540,  -537,   266,  -537,   280,   282,   284,
     274,   343,  -537,  -537,  -537,   188,   312,  -537,  -537,  -537,
    -537,  1024,   218,   338,  -537,   315,  -537,   330,   335,   340,
     375,     8,   413,  -537,  -537,  -537,  -537,  1474,   232,   542,
     178,   178,   178,   178,    87,   305,   178,   178,   178,    37,
     178,   178,  -537,  -537,  -537,  -537,    20,     5,  1024,  1024,
    -537,  -537,  -537,  -537,  1024,  1286,  -537,  -537,   424,    49,
      20,    20,    20,  1024,   192,  -537,  1024,  -537,   333,  -537,
    1024,  1024,  1024,  1024,  -537,  1024,  1024,  -537,  -537,  -537,
    -537,  -537,  -537,  -537,   115,  1024,   178,  -537,   440,    42,
      68,   442,   542,   338,  -537,  -537,  -537,   338,   338,  -537,
    -537,  -537,  -537,  -537,  -537,  1024,   444,  1024,  1498,   212,
     219,   251,  -537,   338,   256,  -537,  -537,  -537,   901,  1024,
    1024,  1024,   258,   411,   414,   373,   366,    -6,    -8,   208,
    -537,  -537,  -537,  1498,  1498,  1498,  1498,  1498,  1498,  -537,
     376,   272,   206,  -537,  -537,   178,  -537,   178,  -537,  -537,
    -537,  -537,  -537,  1293,  -537,  1307,  -537,  1024,  -537,  -537,
    -537,  -537,   120,  -537,  -537,   -14,  1360,  1374,  1385,  -537,
     378,   379,   443,   421,   385,   387,   363,   363,  -537,  -537,
    -537,   178,  -537,  -537,   178,   464,   466,  -537,  -537,  1498,
     120,   450,  -537,   471,  -537,    65,   456,   475,  -537,  -537,
      35,    15,   345,    91,  -537,  -537,  -537,   -25,   -25,  -537,
     363,   363,   363,    53,    87,   529,   418,   178,   338,   529,
     338,   -35,   529,   363,   363,  -537,  -537,  -537,  -537,  -537,
    -537,  -537,  -537,  -537,  -537,  -537,   363,   255,   490,  -537,
    -537,   471,   274,   120,  -537,  -537,  -537,   303,   274,   447,
    -537,    52,   496,  -537,  -537,   274,   512,   695,  -537,   476,
     406,  -537,    20,  -537,  -537,  -537,   438,  -537,   363,   363,
     363,   363,   363,  -537,  -537,  -537,  -537,   445,  -537,   502,
     529,   446,   451,  -537,   529,  -537,   452,   454,   102,  -537,
    -537,  -537,   234,   459,   337,  -537,   529,  -537,   243,   463,
    -537,   467,   470,   461,  -537,  -537,   437,  -537,   420,  1194,
    -537,   -18,   495,  -537,     0,  -537,  -537,   439,   499,   541,
     498,  -537,  -537,   178,  -537,  -537,  -537,  -537,  -537,   477,
    -537,   293,    15,  -537,    15,  -537,  -537,   480,   862,   480,
     612,   479,   582,  -537,  -537,  -537,  -537,  -537,  -537,  -537,
     673,  1460,  1024,  -537,   528,   274,   120,   473,   529,   363,
     363,   529,   529,  1194,   529,   529,  1194,   529,   529,   435,
    -537,  -537,   529,   529,  1111,  -537,  -537,   529,   529,   529,
     529,   363,   529,   529,  -537,  -537,   529,  -537,  -537,  -537,
    -537,  -537,  -537,  -537,  -537,  -537,   529,   529,   529,  -537,
    -537,  -537,   529,   529,   529,  -537,   529,   529,  -537,   529,
     529,  -537,   529,  -537,  -537,  -537,  -537,   363,  -537,   571,
    -537,  -537,   527,  -537,   295,  -537,   474,  -537,  -537,  -537,
      49,    26,  1272,   695,   695,  1024,   500,  -537,   501,   164,
     434,   581,  -537,  1498,   695,  -537,  -537,   449,  -537,   471,
      49,  -537,  -537,   318,  1194,   587,   586,  -537,   483,  -537,
    -537,   357,   364,   529,   374,   384,  -537,  -537,  -537,  -537,
     400,   570,  -537,  1194,  1194,  1194,  1194,  1194,  1194,  1194,
    1194,  1194,  1194,   590,   324,  -537,  -537,  -537,   600,  -537,
      15,   901,  -537,   582,  -537,  1498,   122,  -537,   122,  -537,
    1024,  -537,  -537,   182,  -537,  -537,   985,  -537,   480,  -537,
    -537,  -537,  1498,  1024,   479,  -537,  -537,   901,  -537,   529,
    -537,   529,   529,  -537,  -537,  -537,  -537,  -537,  -537,   363,
    -537,   580,   529,  -537,  -537,   -14,  -537,   405,  -537,   429,
     382,   589,  -537,  -537,  -537,   -14,   603,  1194,   492,  -537,
     529,   610,   614,  -537,   182,  -537,  1024,   182,  -537,    91,
    -537,   529,   597,   590,   593,  -537,  -537,  1498,  -537,  -537,
    -537,  -537,   363,   529,  -537,   590
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -537,  -537,  -537,  -537,  -537,  -537,   623,  -537,  -537,   -13,
       1,  -537,  -537,  -537,   609,  -537,  -537,  -537,   579,  -537,
    -179,  -537,  -537,  -537,  -537,  -537,   458,   175,   370,  -537,
    -537,  -537,  -155,  -537,  -537,  -252,   331,  -537,  -537,  -537,
    -537,  -537,  -537,  -537,  -537,  -380,   328,  -537,  -536,  -537,
    -537,  -537,  -394,   147,   151,   253,  -537,  -537,  -537,  -537,
    -537,  -537,  -537,  -537,  -537,    83,  -537,  -537,  -254,  -537,
    -112,  -228,  -537,  -164,   260,  -537,  -537,   -75,   524,  -537,
    -537,  -537,    34,  -537,  -537,  -378,  -417,   531,    81,  -362,
     -80,   221,  -212,   156,  -291,  -537,  -537,  -537,  -537,  -537,
    -537,  -537,  -468,  -537,  -537,  -537,  -537,  -537,  -537,  -537,
      16,   -62,   -56,  -279,  -537,   310,  -141,  -537,    69,  -537,
    -537
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -187
static const short yytable[] =
{
     123,   125,    27,   391,   266,   177,   376,   127,   311,   235,
     172,   553,   136,   389,   120,   391,   501,   478,   189,   190,
     191,   128,   493,    99,   495,   172,   482,   479,    52,   497,
      12,   499,   266,    54,   136,   261,    50,     1,   178,   178,
     105,   244,   271,   173,   178,    12,   335,   169,   562,   391,
     391,   391,   137,   178,   185,   246,     6,   112,   173,  -185,
     203,   204,   205,   206,   214,   207,   208,   336,   215,   622,
     245,   478,   261,   314,   478,   178,     4,  -186,    13,   629,
      28,     7,   478,   561,   343,   266,   344,   186,   480,   167,
     216,   162,    10,    13,   217,   223,   176,   225,   210,   391,
     157,   220,   315,   587,   387,   221,   222,    78,    11,   236,
     237,   238,    30,   351,   352,   138,   158,   159,   160,   161,
     584,   230,   164,   165,   166,   321,   170,   171,   567,   483,
     569,   355,   581,   503,    26,   247,    14,   138,   391,   391,
     261,   319,    66,   345,    78,    78,    18,   259,   395,   523,
     174,    14,   633,   528,   400,   529,   530,   402,   168,     5,
     541,   330,   478,   219,    71,   174,   505,   510,   537,   538,
     539,    33,   212,   542,   519,   645,   270,    15,   570,    21,
     604,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   262,    15,    72,   187,   193,   556,    24,   266,   331,
     613,   554,    66,   555,   270,   194,   209,    78,    75,   433,
     375,   193,    78,   436,   375,   326,   346,   375,    30,   367,
     427,   194,    79,    80,    71,   444,   383,   348,   386,   253,
      71,   255,   254,   256,   226,   332,   571,   572,   227,   195,
      82,   228,   196,    36,   369,   227,   573,   421,   510,    50,
     500,    53,   248,    72,   595,   478,   396,   270,   196,   122,
      71,   399,   396,   371,   372,   326,   100,   307,    75,   406,
     308,   349,   101,   229,   154,   375,    71,   227,   392,   375,
     239,   393,    79,    80,   227,    71,   102,   441,    79,   126,
     524,   375,   103,   446,   252,   197,   524,   524,   227,   104,
      82,   524,   524,   382,   198,   440,   106,   388,   619,   524,
     616,   197,   543,   618,   445,   544,   491,   559,    79,   492,
     198,   560,    56,   621,   107,   545,   546,   547,   421,   109,
     502,   548,   549,   550,    79,   551,   552,   155,   156,   108,
     180,   588,   513,    79,   589,   181,   326,   601,   326,   110,
     602,   644,   641,   375,   192,   111,   375,   375,   112,   375,
     375,   612,   375,   375,   231,   232,    78,   375,   375,   518,
     270,   116,   375,   375,   375,   375,   211,   375,   375,   593,
     283,   375,   605,   591,    57,   117,   594,   118,   626,   119,
     591,   375,   375,   375,   398,    78,   596,   375,   375,   375,
     591,   375,   375,   306,   375,   375,   597,   375,   615,   489,
     591,   606,   636,   606,   121,   639,   284,   124,   606,    58,
     130,   140,   598,   421,   421,   565,   591,   623,   285,   134,
     582,   624,    59,    60,   421,   131,   340,   341,   342,   574,
     132,   575,   443,   428,   286,   133,    65,    61,    62,   390,
     617,   625,   337,   337,    66,   624,   287,   139,   375,   163,
     183,    84,   213,    67,   218,    68,   224,    69,   141,   606,
     142,   240,   606,   143,   241,    70,    71,   242,   243,   288,
     277,   278,   251,   289,   280,   290,   309,   279,   310,   281,
     610,   282,   312,   291,   429,   430,   125,   313,   317,   318,
     145,   146,   327,   513,   326,    72,   531,   532,    73,    74,
     381,   534,   535,   394,   375,   283,   375,   375,   401,   540,
      75,   292,   404,   293,    76,    77,    78,   375,   147,   148,
     149,   150,   151,   152,    79,    80,  -185,   422,   350,   576,
     351,   352,   488,   425,   428,   375,   637,   432,   434,   353,
     431,   284,    82,   435,   354,    56,   375,   437,   355,   438,
     356,    37,   357,   285,   442,   447,   450,   577,   375,   448,
      85,    71,   449,    38,    39,   451,    40,   452,   481,   286,
     485,   487,   486,   319,   114,   496,   503,    86,   504,   358,
     514,   287,   533,    41,   557,    87,    88,    89,   558,    42,
     359,   520,   500,   360,   361,   566,   568,   583,   585,   590,
      43,    44,   591,   599,   288,   362,   482,    57,   289,   363,
     290,   364,   592,   603,    65,   620,   630,   631,   291,    79,
     365,    45,    66,   634,   366,   627,   635,   642,   643,    29,
      55,    67,   115,    68,   397,    69,   367,   368,   339,   403,
     563,   609,    58,    70,    71,   564,   292,   250,   293,   490,
     407,   498,   202,   640,   614,    59,    60,   201,   439,     0,
       0,   369,     0,    46,    47,     0,     0,     0,     0,     0,
      61,    62,   370,    72,     0,     0,    73,    74,     0,     0,
     371,   372,   373,     0,     0,     0,     0,    48,    75,     0,
       0,   455,    76,    77,    78,     0,   408,    65,   409,     0,
       0,     0,    79,    80,     0,    66,     0,   410,   457,     0,
       0,     0,     0,     0,    67,     0,    68,     0,    69,     0,
      82,   458,   459,     0,     0,     0,    70,    71,     0,     0,
     500,     0,     0,   407,     0,     0,     0,     0,    85,     0,
       0,     0,   462,   463,     0,   464,     0,     0,   465,     0,
       0,     0,     0,     0,     0,    86,    72,     0,   469,    73,
      74,   470,   471,    87,    88,    89,     0,     0,     0,     0,
       0,    75,     0,     0,     0,    76,    77,    78,     0,   408,
      65,   409,     0,     0,     0,    79,    80,     0,    66,     0,
     410,     0,     0,     0,     0,     0,     0,    67,     0,    68,
       0,    69,     0,    82,     0,     0,     0,     0,     0,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    72,
       0,     0,    73,    74,     0,     0,    87,    88,    89,     0,
       0,     0,     0,     0,    75,     0,     0,     0,    76,    77,
      78,     0,     0,     0,    65,     0,     0,     0,    79,    80,
       0,     0,    66,    81,     0,     0,     0,     0,     0,     0,
       0,    67,     0,    68,     0,    69,    82,     0,     0,     0,
       0,     0,    83,    70,    71,     0,    84,     0,     0,     0,
     407,     0,     0,    65,    85,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    86,    68,    72,    69,     0,    73,    74,     0,    87,
      88,    89,    70,    71,     0,     0,     0,     0,    75,     0,
       0,     0,    76,    77,    78,     0,     0,     0,   409,     0,
       0,     0,    79,    80,     0,     0,     0,   410,     0,     0,
       0,     0,    72,     0,     0,    73,    74,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,    75,     0,     0,
       0,    76,    77,    78,     0,     0,     0,    65,    85,     0,
       0,    79,    80,     0,     0,    66,    81,     0,     0,     0,
       0,     0,     0,     0,    67,    86,    68,     0,    69,    82,
       0,     0,     0,    87,    88,    89,    70,    71,     0,    84,
       0,     0,     0,     0,     0,     0,    65,    85,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,    67,    86,    68,    72,    69,     0,    73,
      74,     0,    87,    88,    89,    70,    71,     0,     0,     0,
       0,    75,     0,     0,     0,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,    79,    80,     0,     0,     0,
      81,     0,     0,     0,     0,    72,     0,     0,    73,    74,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
      75,     0,     0,   500,    76,    77,    78,   453,     0,     0,
       0,    85,     0,     0,    79,    80,     0,     0,     0,    81,
       0,     0,   454,   536,     0,     0,     0,     0,    86,   455,
       0,     0,    82,     0,     0,     0,    87,    88,    89,     0,
     456,     0,     0,     0,     0,     0,   457,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,   458,
     459,     0,     0,     0,     0,     0,     0,    86,     0,     0,
       0,     0,     0,   460,   461,    87,    88,    89,     0,     0,
     462,   463,     0,   464,     0,     0,   465,   466,     0,   467,
     453,     0,   468,     0,     0,     0,   469,     0,     0,   470,
     471,     0,     0,     0,     0,   454,     0,     0,   472,     0,
       0,     0,   455,     0,     0,     0,     0,     0,     0,   473,
     474,     0,     0,   456,     0,     0,     0,     0,     0,   457,
       0,     0,     0,     0,     0,   475,     0,     0,     0,     0,
       0,     0,   458,   459,     0,     0,     0,   147,   148,   149,
     150,   151,   152,     0,     0,   476,   460,   461,     0,     0,
       0,     0,     0,   462,   463,     0,   464,     0,     0,   465,
     466,     0,   467,     0,     0,   468,     0,     0,     0,   469,
       0,     0,   470,   471,   182,     0,     0,     0,     0,     0,
     455,   472,     0,     0,     0,     0,     0,     0,   182,     0,
       0,   140,   473,   474,     0,   257,     0,   457,     0,     0,
       0,     0,     0,     0,     0,   140,     0,     0,   475,   258,
     458,   459,   140,     0,     0,     0,     0,     0,   506,     0,
     147,   148,   149,   150,   151,   152,   140,     0,   476,     0,
       0,   462,   463,     0,   464,     0,     0,   465,   141,     0,
     142,     0,     0,   143,     0,     0,   507,   469,     0,   508,
     470,   471,   141,     0,   142,     0,     0,   143,     0,   141,
       0,   142,   274,     0,   143,     0,     0,     0,     0,     0,
     145,   146,     0,   141,     0,   142,   275,     0,   143,   140,
       0,     0,     0,     0,   145,   146,     0,   276,     0,     0,
       0,   145,   146,   140,     0,     0,     0,     0,   147,   148,
     149,   150,   151,   152,   140,   145,   146,     0,     0,     0,
       0,     0,   147,   148,   149,   150,   151,   152,     0,   147,
     148,   149,   150,   151,   152,     0,   141,     0,   142,     0,
       0,   143,     0,   147,   148,   149,   150,   151,   152,     0,
     141,     0,   142,     0,     0,   143,     0,     0,     0,     0,
       0,   141,     0,   142,     0,     0,   143,     0,   145,   146,
       0,     0,     0,     0,     0,     0,     0,     0,   455,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,   140,
       0,     0,     0,   145,   146,   457,   147,   148,   149,   150,
     151,   152,     0,   140,     0,     0,     0,     0,   458,   459,
     147,   148,   149,   150,   151,   152,   506,     0,     0,     0,
       0,   147,   148,   149,   150,   151,   152,   140,     0,   462,
     463,     0,   464,     0,     0,   465,   141,     0,   142,     0,
       0,   143,     0,     0,   507,   469,     0,   508,   470,   471,
     141,     0,   142,     0,     0,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,   146,
       0,     0,     0,     0,   141,     0,   142,     0,     0,   143,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   148,   149,   150,
     151,   152,     0,     0,     0,     0,   145,   146,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   152
};

static const short yycheck[] =
{
      75,    81,    15,   294,   232,   117,   285,    82,   260,   188,
       5,   479,    26,   292,    70,   306,   410,   379,   130,   131,
     132,    83,   402,    36,   404,     5,    26,    45,    27,   407,
       9,   409,   260,    44,    26,    20,    71,    30,   118,   119,
      53,    47,    56,    38,   124,     9,    71,   109,    22,   340,
     341,   342,    44,   133,     5,    63,     0,    20,    38,    24,
     140,   141,   142,   143,    22,   145,   146,    92,    26,   605,
      76,   433,    20,     8,   436,   155,     9,    42,    57,   615,
      44,    35,   444,   500,    31,   313,    33,    38,   106,    52,
      22,   104,    44,    57,    26,   175,    91,   177,   154,   390,
      99,   163,    37,   520,   139,   167,   168,    92,    44,   189,
     190,   191,   123,    11,    12,   129,   100,   101,   102,   103,
     514,   183,   106,   107,   108,   110,   110,   111,   506,   129,
     508,    29,   510,   107,   106,   143,   115,   129,   429,   430,
      20,   106,    20,    90,    92,    92,    67,   227,   312,   428,
     145,   115,   620,   432,   318,   434,   435,   105,   121,    92,
     451,    70,   524,   162,    42,   145,   420,   421,   447,   448,
     449,   111,   156,   452,   426,   643,   232,   156,    14,    92,
     560,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,    71,   156,    71,   145,     3,   487,    92,   426,   108,
     578,   480,    20,   482,   260,    13,    91,    92,    86,   350,
     285,     3,    92,   354,   289,   271,   163,   292,   123,   117,
     332,    13,   100,   101,    42,   366,   288,   283,   290,    23,
      42,   215,    26,   217,    22,   144,    72,    73,    26,    47,
     118,    22,    50,    26,   142,    26,    82,   327,   502,    71,
     128,    53,    44,    71,   533,   617,   312,   313,    50,    71,
      42,   317,   318,   161,   162,   321,   105,   251,    86,   325,
     254,   284,   105,    22,    42,   350,    42,    26,    23,   354,
      22,    26,   100,   101,    26,    42,   105,   362,   100,    71,
     431,   366,   105,   368,    22,   103,   437,   438,    26,    23,
     118,   442,   443,   287,   112,    71,    84,   291,   599,   450,
     589,   103,   453,   592,    71,   456,    23,    22,   100,    26,
     112,    26,    15,   602,    84,   466,   467,   468,   408,   139,
     410,   472,   473,   474,   100,   476,   477,   105,   106,    78,
     119,    23,   422,   100,    26,   124,   402,    23,   404,    84,
      26,   642,   631,   428,   133,    84,   431,   432,    20,   434,
     435,   573,   437,   438,   108,   109,    92,   442,   443,   425,
     426,   105,   447,   448,   449,   450,   155,   452,   453,    22,
      17,   456,   561,    26,    77,   105,    22,   105,     6,   105,
      26,   466,   467,   468,    91,    92,    22,   472,   473,   474,
      26,   476,   477,   247,   479,   480,    22,   482,   587,   393,
      26,   566,   624,   568,    71,   627,    53,   105,   573,   112,
     105,    39,    22,   503,   504,   505,    26,    22,    65,    54,
     510,    26,   125,   126,   514,   105,   280,   281,   282,     5,
     105,     7,   105,   106,    81,   105,    12,   140,   141,   293,
     591,    22,   277,   278,    20,    26,    93,    44,   533,   154,
      36,   128,    22,    29,    22,    31,    22,    33,    86,   624,
      88,    60,   627,    91,    60,    41,    42,   104,   112,   116,
     102,   102,   106,   120,    63,   122,    22,    44,    22,   104,
     570,   104,    42,   130,   338,   339,   576,    26,    42,    24,
     118,   119,   157,   583,   560,    71,   437,   438,    74,    75,
      92,   442,   443,    23,   589,    17,   591,   592,    71,   450,
      86,   158,    26,   160,    90,    91,    92,   602,   146,   147,
     148,   149,   150,   151,   100,   101,    24,    61,     9,   105,
      11,    12,    44,   137,   106,   620,   626,    45,   102,    20,
     105,    53,   118,   102,    25,    15,   631,   105,    29,   105,
      31,    19,    33,    65,   105,   102,   105,   133,   643,   102,
     136,    42,   102,    31,    32,   138,    34,   157,    83,    81,
     141,    40,    83,   106,    44,   105,   107,   153,     6,    60,
      62,    93,   157,    51,    23,   161,   162,   163,    71,    57,
      71,   128,   128,    74,    75,   105,   105,    26,   159,    22,
      68,    69,    26,    43,   116,    86,    26,    77,   120,    90,
     122,    92,   139,    23,    12,    45,    23,   135,   130,   100,
     101,    89,    20,    23,   105,    46,    22,    40,    45,    16,
      31,    29,    63,    31,   313,    33,   117,   118,   278,   321,
     503,   568,   112,    41,    42,   504,   158,   199,   160,   399,
      48,   408,   138,   629,   583,   125,   126,   136,   358,    -1,
      -1,   142,    -1,   131,   132,    -1,    -1,    -1,    -1,    -1,
     140,   141,   153,    71,    -1,    -1,    74,    75,    -1,    -1,
     161,   162,   163,    -1,    -1,    -1,    -1,   155,    86,    -1,
      -1,    28,    90,    91,    92,    -1,    94,    12,    96,    -1,
      -1,    -1,   100,   101,    -1,    20,    -1,   105,    45,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,    -1,
     118,    58,    59,    -1,    -1,    -1,    41,    42,    -1,    -1,
     128,    -1,    -1,    48,    -1,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    79,    80,    -1,    82,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,   153,    71,    -1,    95,    74,
      75,    98,    99,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    91,    92,    -1,    94,
      12,    96,    -1,    -1,    -1,   100,   101,    -1,    20,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,
      -1,    33,    -1,   118,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,    71,
      -1,    -1,    74,    75,    -1,    -1,   161,   162,   163,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    90,    91,
      92,    -1,    -1,    -1,    12,    -1,    -1,    -1,   100,   101,
      -1,    -1,    20,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    -1,    33,   118,    -1,    -1,    -1,
      -1,    -1,   124,    41,    42,    -1,   128,    -1,    -1,    -1,
      48,    -1,    -1,    12,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,   153,    31,    71,    33,    -1,    74,    75,    -1,   161,
     162,   163,    41,    42,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    90,    91,    92,    -1,    -1,    -1,    96,    -1,
      -1,    -1,   100,   101,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    75,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    90,    91,    92,    -1,    -1,    -1,    12,   136,    -1,
      -1,   100,   101,    -1,    -1,    20,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,   153,    31,    -1,    33,   118,
      -1,    -1,    -1,   161,   162,   163,    41,    42,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    12,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,   153,    31,    71,    33,    -1,    74,
      75,    -1,   161,   162,   163,    41,    42,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    90,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,    -1,
     105,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,   128,    90,    91,    92,     6,    -1,    -1,
      -1,   136,    -1,    -1,   100,   101,    -1,    -1,    -1,   105,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,   153,    28,
      -1,    -1,   118,    -1,    -1,    -1,   161,   162,   163,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    72,    73,   161,   162,   163,    -1,    -1,
      79,    80,    -1,    82,    -1,    -1,    85,    86,    -1,    88,
       6,    -1,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    21,    -1,    -1,   107,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,   118,
     119,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,    -1,    -1,   154,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    80,    -1,    82,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      -1,    -1,    98,    99,    22,    -1,    -1,    -1,    -1,    -1,
      28,   107,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    39,   118,   119,    -1,    22,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,   134,    22,
      58,    59,    39,    -1,    -1,    -1,    -1,    -1,    66,    -1,
     146,   147,   148,   149,   150,   151,    39,    -1,   154,    -1,
      -1,    79,    80,    -1,    82,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    94,    95,    -1,    97,
      98,    99,    86,    -1,    88,    -1,    -1,    91,    -1,    86,
      -1,    88,    22,    -1,    91,    -1,    -1,    -1,    -1,    -1,
     118,   119,    -1,    86,    -1,    88,    22,    -1,    91,    39,
      -1,    -1,    -1,    -1,   118,   119,    -1,    22,    -1,    -1,
      -1,   118,   119,    39,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,    39,   118,   119,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,    -1,   146,
     147,   148,   149,   150,   151,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,   146,   147,   148,   149,   150,   151,    -1,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    88,    -1,    -1,    91,    -1,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,   118,   119,    45,   146,   147,   148,   149,
     150,   151,    -1,    39,    -1,    -1,    -1,    -1,    58,    59,
     146,   147,   148,   149,   150,   151,    66,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,    39,    -1,    79,
      80,    -1,    82,    -1,    -1,    85,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    94,    95,    -1,    97,    98,    99,
      86,    -1,    88,    -1,    -1,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,
      -1,    -1,    -1,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,
     146,   147,   148,   149,   150,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,   165,   166,     9,    92,     0,    35,   167,   168,
      44,    44,     9,    57,   115,   156,   169,   170,    67,   175,
     176,    92,   172,   173,    92,   171,   106,   173,    44,   170,
     123,   177,   178,   111,   179,   180,    26,    19,    31,    32,
      34,    51,    57,    68,    69,    89,   131,   132,   155,   174,
      71,   274,   174,    53,    44,   178,    15,    77,   112,   125,
     126,   140,   141,   181,   182,    12,    20,    29,    31,    33,
      41,    42,    71,    74,    75,    86,    90,    91,    92,   100,
     101,   105,   118,   124,   128,   136,   153,   161,   162,   163,
     183,   184,   185,   196,   241,   242,   251,   254,   276,   173,
     105,   105,   105,   105,    23,   173,    84,    84,    78,   139,
      84,    84,    20,   275,    44,   182,   105,   105,   105,   105,
     276,    71,    71,   241,   105,   254,    71,   241,   275,   243,
     105,   105,   105,   105,    54,   187,    26,    44,   129,    44,
      39,    86,    88,    91,    92,   118,   119,   146,   147,   148,
     149,   150,   151,   253,    42,   105,   106,   174,   274,   274,
     274,   274,   173,   154,   274,   274,   274,    52,   121,   275,
     274,   274,     5,    38,   145,   234,    91,   234,   254,   255,
     255,   255,    22,    36,   186,     5,    38,   145,   250,   234,
     234,   234,   255,     3,    13,    47,    50,   103,   112,   189,
     190,   251,   242,   254,   254,   254,   254,   254,   254,    91,
     276,   255,   274,    22,    22,    26,    22,    26,    22,   174,
     275,   275,   275,   254,    22,   254,    22,    26,    22,    22,
     275,   108,   109,   193,   194,   184,   254,   254,   254,    22,
      60,    60,   104,   112,    47,    76,    63,   143,    44,   188,
     190,   106,    22,    23,    26,   274,   274,    22,    22,   254,
     195,    20,    71,   199,   200,   201,   235,   236,   237,   239,
     276,    56,   207,   212,    22,    22,    22,   102,   102,    44,
      63,   104,   104,    17,    53,    65,    81,    93,   116,   120,
     122,   130,   158,   160,   257,   258,   259,   261,   263,   265,
     267,   268,   269,   271,   272,   273,   257,   274,   274,    22,
      22,   199,    42,    26,     8,    37,   202,    42,    24,   106,
     238,   110,   208,   209,   210,   235,   276,   157,   206,   213,
      70,   108,   144,   197,   246,    71,    92,   191,   192,   192,
     257,   257,   257,    31,    33,    90,   163,   260,   276,   173,
       9,    11,    12,    20,    25,    29,    31,    33,    60,    71,
      74,    75,    86,    90,    92,   101,   105,   117,   118,   142,
     153,   161,   162,   163,   191,   241,   277,   278,   279,   280,
     284,    92,   274,   275,   266,   277,   275,   139,   274,   277,
     257,   258,    23,    26,    23,   237,   276,   200,    91,   276,
     237,    71,   105,   210,    26,   240,   276,    48,    94,    96,
     105,   216,   217,   218,   219,   220,   221,   228,   231,   233,
     249,   254,    61,   204,   214,   137,   198,   234,   106,   257,
     257,   105,    45,   280,   102,   102,   280,   105,   105,   279,
      71,   241,   105,   105,   280,    71,   241,   102,   102,   102,
     105,   138,   157,     6,    21,    28,    39,    45,    58,    59,
      72,    73,    79,    80,    82,    85,    86,    88,    91,    95,
      98,    99,   107,   118,   119,   134,   154,   232,   253,    45,
     106,    83,    26,   129,   270,   141,    83,    40,    44,   274,
     238,    23,    26,   209,   211,   209,   105,   249,   219,   249,
     128,   216,   254,   107,     6,   232,    66,    94,    97,   230,
     232,   205,   252,   254,    62,   203,   215,   248,   276,   199,
     128,   244,   245,   277,   280,   281,   282,   283,   277,   277,
     277,   282,   282,   157,   282,   282,    22,   277,   277,   277,
     282,   258,   277,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   266,   277,   277,   258,    23,    71,    22,
      26,   250,    22,   217,   218,   254,   105,   249,   105,   249,
      14,    72,    73,    82,     5,     7,   105,   133,   222,   223,
     224,   249,   254,    26,   216,   159,   247,   250,    23,    26,
      22,    26,   139,    22,    22,   277,    22,    22,    22,    43,
     264,    23,    26,    23,   209,   184,   196,   229,   256,   229,
     254,   226,   256,   249,   252,   184,   277,   280,   277,   258,
      45,   277,   212,    22,    26,    22,     6,    46,   225,   212,
      23,   135,   262,   266,    23,    22,   256,   254,   227,   256,
     246,   277,    40,    45,   258,   266
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
#line 253 "ace.yacc"
    {
		this_report.dbname=strdup("!!ASCII!!");;
	}
    break;

  case 4:
#line 256 "ace.yacc"
    {
		this_report.dbname=strdup(yyvsp[-1].str);
		A4GLSQL_init_connection (yyvsp[-1].str);
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
    break;

  case 10:
#line 280 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:
#line 284 "ace.yacc"
    {
		ace_add_variable(yyvsp[-1].str,yyvsp[0].str,CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:
#line 287 "ace.yacc"
    {
		ace_add_variable(yyvsp[-1].str,yyvsp[0].str,CAT_PARAM,atoi(yyvsp[-3].str),-1,0);
	}
    break;

  case 13:
#line 290 "ace.yacc"
    {
		add_function(yyvsp[0].str);
	}
    break;

  case 17:
#line 301 "ace.yacc"
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
#line 314 "ace.yacc"
    {strcpy(yyval.str,"INTEGER");}
    break;

  case 20:
#line 315 "ace.yacc"
    {strcpy(yyval.str,"CHAR");}
    break;

  case 21:
#line 316 "ace.yacc"
    {sprintf(yyval.str,"CHAR (%s)",yyvsp[-1].str);}
    break;

  case 22:
#line 317 "ace.yacc"
    {strcpy(yyval.str,"VARCHAR");}
    break;

  case 23:
#line 318 "ace.yacc"
    {sprintf(yyval.str,"VARCHAR (%s)",yyvsp[-1].str);}
    break;

  case 24:
#line 319 "ace.yacc"
    {strcpy(yyval.str,"DATE");}
    break;

  case 25:
#line 320 "ace.yacc"
    {strcpy(yyval.str,"FLOAT");}
    break;

  case 26:
#line 321 "ace.yacc"
    {strcpy(yyval.str,"SMALLFLOAT");}
    break;

  case 27:
#line 322 "ace.yacc"
    {strcpy(yyval.str,"SMALLINT");}
    break;

  case 28:
#line 323 "ace.yacc"
    {strcpy(yyval.str,"DATETIME");}
    break;

  case 29:
#line 324 "ace.yacc"
    {strcpy(yyval.str,"INTERVAL");}
    break;

  case 30:
#line 325 "ace.yacc"
    {strcpy(yyval.str,"MONEY");}
    break;

  case 31:
#line 326 "ace.yacc"
    {sprintf(yyval.str,"MONEY (%s,0)",yyvsp[-1].str);}
    break;

  case 32:
#line 327 "ace.yacc"
    {sprintf(yyval.str,"MONEY (%s,%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 33:
#line 328 "ace.yacc"
    {strcpy(yyval.str,"DECIMAL");}
    break;

  case 34:
#line 329 "ace.yacc"
    {sprintf(yyval.str,"DECIMAL (%s,0)",yyvsp[-1].str);}
    break;

  case 35:
#line 330 "ace.yacc"
    {sprintf(yyval.str,"DECIMAL (%s,%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 41:
#line 344 "ace.yacc"
    {
	add_inputs((char *)strip_quotes(yyvsp[0].str),yyvsp[-2].str);
}
    break;

  case 47:
#line 359 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=strdup(yyvsp[0].str);}
    break;

  case 48:
#line 360 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:
#line 361 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=strdup(yyvsp[0].str); }
    break;

  case 50:
#line 362 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=strdup(yyvsp[0].str); }
    break;

  case 51:
#line 363 "ace.yacc"
    {
		this_report.output.left_margin=atoi(yyvsp[0].str);
	}
    break;

  case 52:
#line 366 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi(yyvsp[0].str);
	}
    break;

  case 53:
#line 369 "ace.yacc"
    {
		this_report.output.top_margin=atoi(yyvsp[0].str);
	}
    break;

  case 54:
#line 372 "ace.yacc"
    {
		this_report.output.page_length=atoi(yyvsp[0].str);
	}
    break;

  case 55:
#line 375 "ace.yacc"
    {
		this_report.output.right_margin=atoi(yyvsp[0].str);
	}
    break;

  case 56:
#line 378 "ace.yacc"
    {
		this_report.output.top_of_page=strdup(yyvsp[0].str);
	}
    break;

  case 58:
#line 385 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:
#line 389 "ace.yacc"
    { add_select(yyvsp[0].str,temp_tab_name); }
    break;

  case 60:
#line 390 "ace.yacc"
    { add_select(yyvsp[0].str,temp_tab_name); }
    break;

  case 64:
#line 401 "ace.yacc"
    {
		struct commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,"",cmd);
	  }
    break;

  case 70:
#line 420 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,"",yyvsp[0].commands);
	}
    break;

  case 71:
#line 424 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,"",yyvsp[0].commands);
	}
    break;

  case 72:
#line 428 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,"",yyvsp[0].commands);
	}
    break;

  case 73:
#line 432 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,"",yyvsp[0].commands);
	}
    break;

  case 74:
#line 436 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,"",yyvsp[0].commands);
	}
    break;

  case 75:
#line 440 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,yyvsp[-1].str,yyvsp[0].commands);
	}
    break;

  case 76:
#line 444 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,yyvsp[-1].str,yyvsp[0].commands);
	}
    break;

  case 81:
#line 457 "ace.yacc"
    {
int vid;
int a;
a=atoi(yyvsp[0].str);
vid = find_sql_var (a);
sprintf(yyval.str,this_report.variables.variables_val[vid].name);
}
    break;

  case 82:
#line 468 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 84:
#line 471 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:
#line 471 "ace.yacc"
    {
	printf("speclist : %s ",yyvsp[0].str);
	sprintf(yyval.str,"ORDER BY %s",yyvsp[0].str);}
    break;

  case 86:
#line 475 "ace.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 87:
#line 484 "ace.yacc"
    {
		sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
	}
    break;

  case 91:
#line 491 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 92:
#line 493 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 93:
#line 495 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 94:
#line 497 "ace.yacc"
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
#line 586 "ace.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 120:
#line 594 "ace.yacc"
    {
sprintf(yyval.str,"%s %s %s %s",
yyvsp[-3].str,yyvsp[-2].str,
yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 121:
#line 601 "ace.yacc"
    {strcpy(yyval.str,"\n0");}
    break;

  case 123:
#line 605 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 125:
#line 609 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 128:
#line 617 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 130:
#line 623 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 132:
#line 629 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 134:
#line 635 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 135:
#line 640 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 136:
#line 641 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 137:
#line 647 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 138:
#line 649 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 139:
#line 653 "ace.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 145:
#line 672 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 148:
#line 686 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 149:
#line 688 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 150:
#line 690 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 151:
#line 692 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 153:
#line 699 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 154:
#line 702 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 156:
#line 709 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 157:
#line 711 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 158:
#line 713 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 159:
#line 715 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 160:
#line 717 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 161:
#line 719 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 171:
#line 734 "ace.yacc"
    {sprintf(yyval.str,"<=");}
    break;

  case 172:
#line 735 "ace.yacc"
    {sprintf(yyval.str,">=");}
    break;

  case 177:
#line 745 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 181:
#line 770 "ace.yacc"
    { sprintf(yyval.str," %s",(char *)strip_quotes(yyvsp[0].str)); }
    break;

  case 182:
#line 771 "ace.yacc"
    {sprintf(yyval.str,yyvsp[0].str); }
    break;

  case 183:
#line 772 "ace.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);  }
    break;

  case 184:
#line 773 "ace.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",(char *)strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str);  }
    break;

  case 186:
#line 781 "ace.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 187:
#line 785 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 188:
#line 786 "ace.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 189:
#line 787 "ace.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 190:
#line 790 "ace.yacc"
    { sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 191:
#line 791 "ace.yacc"
    { sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 192:
#line 792 "ace.yacc"
    { sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 195:
#line 803 "ace.yacc"
    {sprintf(yyval.str,"0.%s",yyvsp[0].str);}
    break;

  case 196:
#line 816 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 197:
#line 819 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 199:
#line 840 "ace.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str );}
    break;

  case 200:
#line 844 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 201:
#line 845 "ace.yacc"
    {
       sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
       }
    break;

  case 203:
#line 849 "ace.yacc"
    {
       sprintf(yyval.str,"INTO TEMP %s%s ",yyvsp[-1].str,yyvsp[0].str);
	strcpy(temp_tab_name,yyvsp[-1].str);
}
    break;

  case 204:
#line 855 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 205:
#line 855 "ace.yacc"
    {strcpy(yyval.str," WITH NO LOG");}
    break;

  case 207:
#line 877 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 208:
#line 880 "ace.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 209:
#line 881 "ace.yacc"
    {sprintf(yyval.str,"ALL");}
    break;

  case 210:
#line 882 "ace.yacc"
    {sprintf(yyval.str,"DISTINCT");}
    break;

  case 211:
#line 883 "ace.yacc"
    {sprintf(yyval.str,"DISTINCT");}
    break;

  case 213:
#line 888 "ace.yacc"
    { sprintf(yyval.str," %s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 214:
#line 892 "ace.yacc"
    {
			add_select_column(yyvsp[0].str,yyvsp[0].str);
		}
    break;

  case 215:
#line 895 "ace.yacc"
    {
			sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
			add_select_column(yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 217:
#line 905 "ace.yacc"
    {sprintf(yyval.str,"UNITS YEAR");}
    break;

  case 218:
#line 906 "ace.yacc"
    {sprintf(yyval.str,"UNITS MONTH"); }
    break;

  case 219:
#line 907 "ace.yacc"
    {sprintf(yyval.str,"UNITS DAY);"); }
    break;

  case 220:
#line 908 "ace.yacc"
    {sprintf(yyval.str,"UNITS HOUR);"); }
    break;

  case 221:
#line 909 "ace.yacc"
    {sprintf(yyval.str,"UNITS MINUTE);"); }
    break;

  case 222:
#line 910 "ace.yacc"
    {sprintf(yyval.str,"UNITS SECOND);"); }
    break;

  case 223:
#line 915 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 224:
#line 917 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 225:
#line 919 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 226:
#line 921 "ace.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 227:
#line 923 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 228:
#line 925 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 229:
#line 927 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 232:
#line 930 "ace.yacc"
    {sprintf(yyval.str," %s[%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 233:
#line 931 "ace.yacc"
    {sprintf(yyval.str," %s[%s,%s]",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 234:
#line 932 "ace.yacc"
    {sprintf(yyval.str," %s.%s[%s]",yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 235:
#line 933 "ace.yacc"
    {sprintf(yyval.str," %s.%s[%s,%s]",yyvsp[-7].str,yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 236:
#line 935 "ace.yacc"
    {
if (find_variable(yyvsp[0].str)==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
sprintf(yyval.str,"\n2(%d)",find_variable(yyvsp[0].str));
}
    break;

  case 237:
#line 940 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 238:
#line 942 "ace.yacc"
    {sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 242:
#line 946 "ace.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 243:
#line 947 "ace.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 244:
#line 948 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 245:
#line 949 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 246:
#line 950 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 247:
#line 951 "ace.yacc"
    {sprintf(yyval.str," %s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 248:
#line 952 "ace.yacc"
    {sprintf(yyval.str,"%s(%s)",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 249:
#line 954 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 250:
#line 956 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 251:
#line 958 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 252:
#line 960 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 253:
#line 962 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 254:
#line 964 "ace.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 256:
#line 970 "ace.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 259:
#line 988 "ace.yacc"
    {
		yyval.commands.commands.commands_len=1;
		yyval.commands.commands.commands_val=malloc(sizeof(struct command));
		COPY(yyval.commands.commands.commands_val[0],yyvsp[0].cmd);
		}
    break;

  case 260:
#line 993 "ace.yacc"
    {
		COPY(yyval.commands,yyvsp[-1].commands);
		yyval.commands.commands.commands_len++;
		yyval.commands.commands.commands_val=realloc(
		yyval.commands.commands.commands_val,
		yyval.commands.commands.commands_len*sizeof(struct command));
		COPY(yyval.commands.commands.commands_val[ yyval.commands.commands.commands_len-1 ],yyvsp[0].cmd);
	}
    break;

  case 271:
#line 1015 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_BLOCK;
		yyval.cmd.command_u.commands.commands.commands_val=yyvsp[-1].commands.commands.commands_val;
		yyval.cmd.command_u.commands.commands.commands_len=yyvsp[-1].commands.commands.commands_len;
	}
    break;

  case 272:
#line 1050 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_CALL;
		yyval.cmd.command_u.cmd_call.fcall=malloc(sizeof(struct expr_call));
                yyval.cmd.command_u.cmd_call.fcall->fname=strdup(yyvsp[-3].str);
	
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
		print_lexpr( yyval.cmd.command_u.cmd_call.fcall->lexpr);
}
    break;

  case 278:
#line 1068 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_FOR;
		yyval.cmd.command_u.cmd_for.varid=find_variable(yyvsp[-7].str);
		yyval.cmd.command_u.cmd_for.start=yyvsp[-5].expr;
		yyval.cmd.command_u.cmd_for.finish=yyvsp[-3].expr;
		yyval.cmd.command_u.cmd_for.step=yyvsp[-2].expr;
	}
    break;

  case 279:
#line 1077 "ace.yacc"
    { yyval.expr.type=EXPRTYPE_INT; yyval.expr.expr_u.i=1; }
    break;

  case 280:
#line 1078 "ace.yacc"
    { yyval.expr=yyvsp[-1].expr;}
    break;

  case 281:
#line 1082 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_IF;
	yyval.cmd.command_u.cmd_if.condition=yyvsp[-3].expr;
	yyval.cmd.command_u.cmd_if.command=(struct command *)DUP(yyvsp[-1].cmd);
	yyval.cmd.command_u.cmd_if.elsecommand=(struct command *)DUP(yyvsp[0].cmd);
}
    break;

  case 282:
#line 1090 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_NULL;
		yyval.cmd.command_u.null=1;
	}
    break;

  case 283:
#line 1093 "ace.yacc"
    { COPY(yyval.cmd,yyvsp[0].cmd); }
    break;

  case 284:
#line 1098 "ace.yacc"
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

  case 285:
#line 1109 "ace.yacc"
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

  case 286:
#line 1120 "ace.yacc"
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

  case 288:
#line 1133 "ace.yacc"
    {

	yyval.expr.type=EXPRTYPE_COMPLEX;
	yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr));
	COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr);
	COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr);
	yyval.expr.expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 289:
#line 1145 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_NEED;
	yyval.cmd.command_u.cmd_need.nlines=atoi(yyvsp[-1].str);
}
    break;

  case 290:
#line 1151 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PAUSE;
	yyval.cmd.command_u.cmd_pause.message=strdup(yyvsp[0].str);
}
    break;

  case 291:
#line 1158 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PRINT;
	yyval.cmd.command_u.cmd_print.printnl=atoi(yyvsp[0].str);
	yyval.cmd.command_u.cmd_print.print=yyvsp[-1].expr;
}
    break;

  case 292:
#line 1166 "ace.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 293:
#line 1166 "ace.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 294:
#line 1169 "ace.yacc"
    {
	yyval.cmd.cmd_type=CMD_PRINTFILE;
	yyval.cmd.command_u.cmd_printfile.filename=strdup(yyvsp[0].str);
}
    break;

  case 295:
#line 1175 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_SKIP;
		yyval.cmd.command_u.cmd_skip.nlines=atoi(yyvsp[-1].str);

	}
    break;

  case 296:
#line 1180 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_SKIP;
		yyval.cmd.command_u.cmd_skip.nlines=-1;
	}
    break;

  case 297:
#line 1187 "ace.yacc"
    {
		yyval.cmd.cmd_type=CMD_WHILE;
		yyval.cmd.command_u.cmd_while.condition=yyvsp[-2].expr;
		yyval.cmd.command_u.cmd_while.command=(struct command *)DUP(yyvsp[0].cmd);
}
    break;

  case 302:
#line 1211 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[0].agg_val);
		yyval.agg_val.isgroup=0;
	}
    break;

  case 303:
#line 1215 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[-2].agg_val);
		yyval.agg_val.wexpr=(struct expr *)DUP(yyvsp[0].expr);
		yyval.agg_val.isgroup=0;
	}
    break;

  case 304:
#line 1220 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[0].agg_val);
		yyval.agg_val.isgroup=1;
	}
    break;

  case 305:
#line 1224 "ace.yacc"
    {
		COPY(yyval.agg_val,yyvsp[-2].agg_val);
		yyval.agg_val.wexpr=(struct expr *)DUP(yyvsp[0].expr);
		yyval.agg_val.isgroup=1;
	}
    break;

  case 306:
#line 1232 "ace.yacc"
    {
		yyval.agg_val.type=AGG_COUNT;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=0;
	}
    break;

  case 307:
#line 1237 "ace.yacc"
    {
		yyval.agg_val.type=AGG_PERCENT;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=0;
	}
    break;

  case 308:
#line 1242 "ace.yacc"
    {
		yyval.agg_val.type=AGG_AVG;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 309:
#line 1247 "ace.yacc"
    {
		yyval.agg_val.type=AGG_TOTAL;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 310:
#line 1252 "ace.yacc"
    {
		yyval.agg_val.type=AGG_AVG;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 311:
#line 1257 "ace.yacc"
    {
		yyval.agg_val.type=AGG_MIN;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 312:
#line 1262 "ace.yacc"
    {
		yyval.agg_val.type=AGG_MAX;
		yyval.agg_val.wexpr=0;
		yyval.agg_val.expr=(struct expr *)DUP(yyvsp[0].expr);
	}
    break;

  case 313:
#line 1271 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 314:
#line 1279 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 315:
#line 1286 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 316:
#line 1295 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 317:
#line 1301 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 318:
#line 1308 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 319:
#line 1316 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX; 
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 320:
#line 1325 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX;
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 321:
#line 1332 "ace.yacc"
    { 
		yyval.expr.type=EXPRTYPE_COMPLEX;
		yyval.expr.expr_u.expr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.expr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.expr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 322:
#line 1339 "ace.yacc"
    { COPY(yyval.expr,yyvsp[0].expr); }
    break;

  case 323:
#line 1341 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_COMPARE;
		yyval.expr.expr_u.cexpr=malloc(sizeof(struct complex_expr)); 
		COPY(yyval.expr.expr_u.cexpr->expr1,yyvsp[-2].expr); 
		COPY(yyval.expr.expr_u.cexpr->expr2,yyvsp[0].expr); 
		yyval.expr.expr_u.cexpr->method=strdup(yyvsp[-1].str); 
	}
    break;

  case 324:
#line 1348 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=1;
		}
    break;

  case 325:
#line 1352 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0;
		}
    break;

  case 326:
#line 1356 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_BUILTIN;
		yyval.expr.expr_u.name=strdup(yyvsp[0].str);
	}
    break;

  case 327:
#line 1360 "ace.yacc"
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

  case 328:
#line 1370 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("DATE");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 329:
#line 1377 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("MONTH");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 330:
#line 1383 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("YEAR");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 331:
#line 1389 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup("DAY");
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 332:
#line 1396 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_FCALL; 
		yyval.expr.expr_u.fcall=malloc(sizeof(struct expr_call));
		yyval.expr.expr_u.fcall->fname=strdup(yyvsp[-3].str);
                yyval.cmd.command_u.cmd_call.fcall->lexpr=yyvsp[-1].expr.expr_u.lexpr;
	}
    break;

  case 333:
#line 1402 "ace.yacc"
    { COPY(yyval.expr,yyvsp[-1].expr); }
    break;

  case 334:
#line 1403 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[0].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 335:
#line 1409 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[0].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 336:
#line 1415 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 337:
#line 1422 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 338:
#line 1428 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 339:
#line 1436 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_SIMPLE; 
		yyval.expr.expr_u.sexpr=malloc(sizeof(struct simple_expr)); 
		COPY(yyval.expr.expr_u.sexpr->expr,yyvsp[-1].expr); 
		yyval.expr.expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 340:
#line 1443 "ace.yacc"
    {
		printf("NIY\n");
		sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 341:
#line 1447 "ace.yacc"
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

  case 342:
#line 1457 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_AGG; 
		yyval.expr.expr_u.aggid=add_agg(yyvsp[0].agg_val);
	}
    break;

  case 343:
#line 1463 "ace.yacc"
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

  case 344:
#line 1474 "ace.yacc"
    {
		COPY(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 345:
#line 1481 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_LIST;
		yyval.expr.expr_u.lexpr=malloc(sizeof(struct expr_list));
		yyval.expr.expr_u.lexpr->elem.elem_len=1;
		yyval.expr.expr_u.lexpr->elem.elem_val=0;
		yyval.expr.expr_u.lexpr->elem.elem_val=realloc( yyval.expr.expr_u.lexpr->elem.elem_val,sizeof(struct expr)* yyval.expr.expr_u.lexpr->elem.elem_len);
		COPY(yyval.expr.expr_u.lexpr->elem.elem_val[0],yyvsp[0].expr);
	}
    break;

  case 346:
#line 1488 "ace.yacc"
    {
		COPY(yyval.expr,yyvsp[-2].expr);
		yyval.expr.expr_u.lexpr->elem.elem_len++;
		yyval.expr.expr_u.lexpr->elem.elem_val=realloc( yyval.expr.expr_u.lexpr->elem.elem_val,sizeof(struct expr)* yyval.expr.expr_u.lexpr->elem.elem_len);
		COPY(yyval.expr.expr_u.lexpr->elem.elem_val[ yyval.expr.expr_u.lexpr->elem.elem_len-1 ],yyvsp[0].expr);

	}
    break;

  case 347:
#line 1497 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_NULL;
	}
    break;

  case 348:
#line 1503 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_STRING;
		yyval.expr.expr_u.s=strdup(yyvsp[0].str);
	}
    break;

  case 349:
#line 1507 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_DOUBLE;
		yyval.expr.expr_u.d=atof(yyvsp[0].str);
	}
    break;

  case 350:
#line 1511 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_DOUBLE;
		yyval.expr.expr_u.d=atof(yyvsp[0].str);
	}
    break;

  case 351:
#line 1515 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 352:
#line 1519 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 353:
#line 1523 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=atoi(yyvsp[0].str);
	}
    break;

  case 354:
#line 1527 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0-atoi(yyvsp[0].str);
	}
    break;

  case 355:
#line 1531 "ace.yacc"
    {
		yyval.expr.type=EXPRTYPE_INT;
		yyval.expr.expr_u.i=0-atoi(yyvsp[0].str);
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3871 "y.tab.c"

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


#line 1538 "ace.yacc"



#include "lex.yy.c"


