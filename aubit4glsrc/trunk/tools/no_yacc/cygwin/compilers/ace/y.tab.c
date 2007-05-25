/* A Bison parser, made by GNU Bison 2.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
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
     KW_OR = 260,
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
     TIME = 309,
     DATETIME = 310,
     DAY = 311,
     DECIMAL = 312,
     DEFINE = 313,
     DELIMITER = 314,
     DESC = 315,
     DISTINCT = 316,
     DO = 317,
     DOLLAR = 318,
     DOT = 319,
     ELSE = 320,
     END = 321,
     ESCAPE = 322,
     EVERY = 323,
     EXISTS = 324,
     EXTERNAL = 325,
     FIRST = 326,
     FLOAT = 327,
     PIPE = 328,
     FOR = 329,
     FORMAT = 330,
     FRACTION = 331,
     FROM = 332,
     FUNCTION = 333,
     GROUP = 334,
     GROUP_BY = 335,
     HAVING = 336,
     HEADER = 337,
     HOUR = 338,
     IF = 339,
     IN = 340,
     INPUT = 341,
     INTEGER = 342,
     INTERVAL = 343,
     INTO = 344,
     INTVAL = 345,
     KW_FALSE = 346,
     KW_TRUE = 347,
     LAST = 348,
     LEFT = 349,
     LENGTH = 350,
     LET = 351,
     LINES = 352,
     MARGIN = 353,
     MINUTE = 354,
     MONEY = 355,
     MONTH = 356,
     NAMED = 357,
     NEED = 358,
     NOT_EXISTS = 359,
     NOT_IN = 360,
     NUMBER_VALUE = 361,
     NUMERIC = 362,
     KW_OF = 363,
     ON = 364,
     OPEN_BRACKET = 365,
     OPEN_SQUARE = 366,
     ORDER_BY = 367,
     ORDER_EXTERNAL_BY = 368,
     OUTER = 369,
     OUTPUT = 370,
     PAGE = 371,
     PAGE_HEADER = 372,
     PAGE_TRAILER = 373,
     PARAM = 374,
     PAUSE = 375,
     PERCENT = 376,
     POW = 377,
     PRINT = 378,
     PRINTER = 379,
     PRINT_FILE = 380,
     PROMPT = 381,
     READ = 382,
     REPORT = 383,
     RIGHT = 384,
     ROW = 385,
     SECOND = 386,
     SELECT = 387,
     SEMICOLON = 388,
     SKIP = 389,
     SMALLFLOAT = 390,
     SMALLINT = 391,
     SOME = 392,
     SPACES = 393,
     STEP = 394,
     SUM = 395,
     TEMP = 396,
     THEN = 397,
     TO = 398,
     TOP = 399,
     TOP_OF_PAGE = 400,
     TOTAL = 401,
     TRAILER = 402,
     UNION = 403,
     UNIQUE = 404,
     UNITS_DAY = 405,
     UNITS_HOUR = 406,
     UNITS_MINUTE = 407,
     UNITS_MONTH = 408,
     UNITS_SECOND = 409,
     UNITS_YEAR = 410,
     UPDATE = 411,
     USER = 412,
     VARCHAR = 413,
     VARIABLE = 414,
     WHILE = 415,
     WITH_NO_LOG = 416,
     XBEGIN = 417,
     XMAX = 418,
     XMIN = 419,
     YEAR = 420
   };
#endif
/* Tokens.  */
#define USING 258
#define WHERE 259
#define KW_OR 260
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
#define TIME 309
#define DATETIME 310
#define DAY 311
#define DECIMAL 312
#define DEFINE 313
#define DELIMITER 314
#define DESC 315
#define DISTINCT 316
#define DO 317
#define DOLLAR 318
#define DOT 319
#define ELSE 320
#define END 321
#define ESCAPE 322
#define EVERY 323
#define EXISTS 324
#define EXTERNAL 325
#define FIRST 326
#define FLOAT 327
#define PIPE 328
#define FOR 329
#define FORMAT 330
#define FRACTION 331
#define FROM 332
#define FUNCTION 333
#define GROUP 334
#define GROUP_BY 335
#define HAVING 336
#define HEADER 337
#define HOUR 338
#define IF 339
#define IN 340
#define INPUT 341
#define INTEGER 342
#define INTERVAL 343
#define INTO 344
#define INTVAL 345
#define KW_FALSE 346
#define KW_TRUE 347
#define LAST 348
#define LEFT 349
#define LENGTH 350
#define LET 351
#define LINES 352
#define MARGIN 353
#define MINUTE 354
#define MONEY 355
#define MONTH 356
#define NAMED 357
#define NEED 358
#define NOT_EXISTS 359
#define NOT_IN 360
#define NUMBER_VALUE 361
#define NUMERIC 362
#define KW_OF 363
#define ON 364
#define OPEN_BRACKET 365
#define OPEN_SQUARE 366
#define ORDER_BY 367
#define ORDER_EXTERNAL_BY 368
#define OUTER 369
#define OUTPUT 370
#define PAGE 371
#define PAGE_HEADER 372
#define PAGE_TRAILER 373
#define PARAM 374
#define PAUSE 375
#define PERCENT 376
#define POW 377
#define PRINT 378
#define PRINTER 379
#define PRINT_FILE 380
#define PROMPT 381
#define READ 382
#define REPORT 383
#define RIGHT 384
#define ROW 385
#define SECOND 386
#define SELECT 387
#define SEMICOLON 388
#define SKIP 389
#define SMALLFLOAT 390
#define SMALLINT 391
#define SOME 392
#define SPACES 393
#define STEP 394
#define SUM 395
#define TEMP 396
#define THEN 397
#define TO 398
#define TOP 399
#define TOP_OF_PAGE 400
#define TOTAL 401
#define TRAILER 402
#define UNION 403
#define UNIQUE 404
#define UNITS_DAY 405
#define UNITS_HOUR 406
#define UNITS_MINUTE 407
#define UNITS_MONTH 408
#define UNITS_SECOND 409
#define UNITS_YEAR 410
#define UPDATE 411
#define USER 412
#define VARCHAR 413
#define VARIABLE 414
#define WHILE 415
#define WITH_NO_LOG 416
#define XBEGIN 417
#define XMAX 418
#define XMIN 419
#define YEAR 420




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
	ptr=acl_malloc2(l);
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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 74 "ace.yacc"
{
	char	str[30000];
	struct command cmd;
	struct expr expr;
	struct commands commands;
	struct agg_val agg_val;
}
/* Line 187 of yacc.c.  */
#line 511 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 524 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
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
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  166
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  126
/* YYNRULES -- Number of rules.  */
#define YYNRULES  436
/* YYNRULES -- Number of states.  */
#define YYNSTATES  729

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   420

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
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
     296,   298,   299,   303,   305,   309,   312,   314,   316,   317,
     319,   321,   324,   327,   329,   333,   336,   339,   341,   345,
     347,   350,   355,   357,   360,   362,   366,   371,   372,   374,
     375,   377,   378,   380,   382,   386,   388,   392,   394,   397,
     399,   403,   406,   409,   414,   418,   420,   422,   424,   426,
     428,   431,   433,   435,   441,   445,   451,   455,   457,   461,
     462,   464,   468,   472,   476,   480,   487,   493,   495,   497,
     499,   501,   503,   505,   507,   509,   511,   513,   515,   517,
     519,   521,   523,   524,   526,   528,   530,   532,   534,   538,
     542,   544,   546,   547,   551,   557,   560,   565,   569,   571,
     573,   576,   577,   584,   586,   592,   593,   597,   599,   604,
     610,   611,   613,   615,   622,   623,   625,   627,   629,   631,
     635,   637,   640,   642,   644,   646,   648,   650,   652,   654,
     657,   659,   661,   666,   673,   680,   689,   692,   696,   700,
     702,   704,   706,   708,   712,   717,   722,   727,   732,   737,
     742,   748,   754,   760,   766,   772,   775,   778,   781,   783,
     786,   789,   792,   794,   797,   800,   802,   806,   807,   809,
     811,   814,   816,   818,   820,   822,   824,   826,   828,   830,
     832,   834,   838,   844,   846,   848,   850,   852,   854,   864,
     865,   868,   874,   875,   878,   883,   891,   901,   902,   904,
     906,   910,   914,   917,   921,   922,   924,   927,   931,   935,
     940,   942,   944,   946,   948,   950,   952,   954,   956,   958,
     960,   962,   964,   966,   968,   970,   972,   974,   976,   978,
     980,   982,   984,   986,   988,   990,   992,   994,   996,   998,
    1000,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1018,
    1020,  1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,
    1040,  1042,  1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,
    1060,  1062,  1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,
    1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,  1098,
    1100,  1102,  1104,  1106,  1108,  1110,  1112,  1116,  1119,  1124,
    1126,  1128,  1132,  1136,  1140,  1144,  1148,  1151,  1155,  1159,
    1163,  1167,  1171,  1175,  1179,  1183,  1187,  1189,  1193,  1195,
    1197,  1199,  1201,  1203,  1208,  1213,  1218,  1223,  1228,  1232,
    1235,  1238,  1241,  1244,  1247,  1250,  1253,  1255,  1257,  1259,
    1261,  1263,  1267,  1268,  1270,  1272,  1274
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,   168,   169,   177,   181,   185,   189,    -1,
      52,    31,    66,    -1,    52,   102,    66,    -1,    -1,   170,
      -1,    58,   171,    66,    -1,   172,    -1,   171,   172,    -1,
      31,   174,    -1,   159,   175,   176,    -1,   119,   111,   280,
      45,   175,   176,    -1,    78,   173,    -1,   102,    -1,   175,
     176,    -1,   174,    48,   175,   176,    -1,   102,    -1,    78,
      -1,    87,    -1,    41,    -1,    41,   110,   280,    44,    -1,
     158,    -1,   158,   110,   280,    44,    -1,    53,    -1,    72,
      -1,   135,    -1,   136,    -1,    55,    -1,    88,    -1,   100,
      -1,   100,   110,   280,    44,    -1,   100,   110,   280,    48,
     280,    44,    -1,    57,    -1,    57,   110,   280,    44,    -1,
      57,   110,   280,    48,   280,    44,    -1,    -1,   178,    -1,
      86,   179,    66,    -1,   180,    -1,   179,   180,    -1,   126,
      74,   175,     3,   281,    -1,    -1,   182,    -1,   115,   183,
      66,    -1,   184,    -1,   183,   184,    -1,   128,   143,   124,
     281,    -1,   128,   143,   124,    -1,   128,   143,   281,    -1,
     128,   143,    73,   281,    -1,    94,    98,   280,    -1,    37,
      98,   280,    -1,   144,    98,   280,    -1,   116,    95,   280,
      -1,   129,    98,   280,    -1,   145,   281,    -1,   187,    66,
      -1,   186,    66,    -1,   244,    -1,   186,   133,   244,    -1,
     127,   281,   188,   195,    -1,    -1,    59,   281,    -1,    75,
      68,   130,    66,    -1,    75,   191,   190,    -1,    -1,    66,
      -1,   192,    -1,   191,   192,    -1,    71,   116,    82,   262,
      -1,   116,   147,   262,    -1,   116,    82,   262,    -1,   109,
      68,   130,   262,    -1,   109,    93,   130,   262,    -1,    35,
      79,   108,   194,   262,    -1,    26,    79,   108,   194,   262,
      -1,   102,   111,   284,    48,   284,    45,    -1,   102,   111,
     284,    45,    -1,   102,    -1,   193,    -1,    90,    -1,    -1,
     196,    -1,    -1,   112,   197,   201,    -1,   113,   201,    -1,
      42,    -1,   107,    -1,   243,    -1,    90,    -1,    -1,   112,
     200,   201,    -1,   202,    -1,   201,    48,   202,    -1,   203,
     204,    -1,    90,    -1,   241,    -1,    -1,    30,    -1,    60,
      -1,    81,   218,    -1,    80,   207,    -1,   255,    -1,   207,
      48,   255,    -1,     4,   218,    -1,    77,   210,    -1,   211,
      -1,   210,    48,   211,    -1,   212,    -1,   114,   212,    -1,
     114,   110,   213,    44,    -1,   237,    -1,   237,   242,    -1,
     211,    -1,   213,    48,   211,    -1,   209,   215,   216,   217,
      -1,    -1,   208,    -1,    -1,   206,    -1,    -1,   205,    -1,
     219,    -1,   218,     5,   219,    -1,   220,    -1,   219,     6,
     220,    -1,   221,    -1,     7,   221,    -1,   235,    -1,   110,
     218,    44,    -1,    69,   251,    -1,   104,   251,    -1,   257,
     234,   224,   251,    -1,   251,   234,   257,    -1,   225,    -1,
     226,    -1,    28,    -1,   137,    -1,    29,    -1,    67,   229,
      -1,   261,    -1,   261,    -1,   257,    85,   110,   231,    44,
      -1,   257,    85,   251,    -1,   257,   105,   110,   231,    44,
      -1,   257,   105,   251,    -1,   261,    -1,   231,    48,   261,
      -1,    -1,     7,    -1,   257,   232,     8,    -1,   257,   232,
       9,    -1,   257,   234,   257,    -1,   257,   234,   251,    -1,
     257,   232,    36,   257,     6,   257,    -1,   257,   232,    17,
     228,   227,    -1,    11,    -1,    50,    -1,    10,    -1,    13,
      -1,    15,    -1,    18,    -1,    16,    -1,    19,    -1,    17,
      -1,    12,    -1,    14,    -1,   233,    -1,   230,    -1,   223,
      -1,   222,    -1,    -1,    28,    -1,    61,    -1,   149,    -1,
      42,    -1,   239,    -1,   238,    46,   239,    -1,    42,    64,
     239,    -1,   282,    -1,   282,    -1,    -1,   111,    90,    45,
      -1,   111,    90,    48,    90,    45,    -1,   282,   240,    -1,
     237,    64,   282,   240,    -1,   237,    64,    23,    -1,   282,
      -1,   106,    -1,    64,    90,    -1,    -1,   132,   245,   252,
     253,   214,   248,    -1,   247,    -1,   132,   252,   253,   214,
     248,    -1,    -1,   148,   236,   246,    -1,   199,    -1,    89,
     141,   250,   249,    -1,   199,    89,   141,   250,   249,    -1,
      -1,   161,    -1,   282,    -1,   110,   132,   252,   253,   214,
      44,    -1,    -1,    28,    -1,    61,    -1,   149,    -1,   254,
      -1,   253,    48,   254,    -1,   257,    -1,   257,   102,    -1,
     257,    -1,   155,    -1,   153,    -1,   150,    -1,   151,    -1,
     152,    -1,   154,    -1,   257,   258,    -1,   198,    -1,   282,
      -1,   282,   111,   280,    45,    -1,   282,   111,   280,    48,
     280,    45,    -1,   282,    64,   282,   111,   280,    45,    -1,
     282,    64,   282,   111,   280,    48,   280,    45,    -1,    63,
     282,    -1,   282,    64,   282,    -1,   282,    64,    23,    -1,
      92,    -1,    91,    -1,   157,    -1,    23,    -1,   110,   257,
      44,    -1,    53,   110,   260,    44,    -1,    56,   110,   260,
      44,    -1,   101,   110,   260,    44,    -1,   165,   110,   260,
      44,    -1,   282,   110,   260,    44,    -1,    51,   110,    23,
      44,    -1,    34,   110,   236,   257,    44,    -1,   163,   110,
     236,   257,    44,    -1,   164,   110,   236,   257,    44,    -1,
     140,   110,   236,   257,    44,    -1,    51,   110,   236,   257,
      44,    -1,    22,   259,    -1,    24,   259,    -1,   122,   259,
      -1,   256,    -1,    23,   259,    -1,    21,   259,    -1,    20,
     259,    -1,   257,    -1,    21,   257,    -1,    20,   257,    -1,
     257,    -1,   260,    48,   257,    -1,    -1,   198,    -1,   263,
      -1,   262,   263,    -1,   266,    -1,   268,    -1,   279,    -1,
     270,    -1,   273,    -1,   274,    -1,   278,    -1,   275,    -1,
     277,    -1,   264,    -1,   162,   262,    66,    -1,    39,   265,
     110,   288,    44,    -1,    53,    -1,   101,    -1,   165,    -1,
      56,    -1,   282,    -1,    74,   175,    11,   284,   143,   284,
     267,    62,   263,    -1,    -1,   139,   284,    -1,    84,   284,
     142,   263,   269,    -1,    -1,    65,   263,    -1,    96,   102,
      11,   272,    -1,    96,   102,   111,   284,    45,    11,   272,
      -1,    96,   102,   111,   284,    48,   284,    45,    11,   272,
      -1,    -1,   272,    -1,   284,    -1,   272,    48,   284,    -1,
     103,   280,    97,    -1,   120,   281,    -1,   123,   271,   276,
      -1,    -1,   133,    -1,   125,   281,    -1,   134,   280,    97,
      -1,   134,   143,   145,    -1,   160,   284,    62,   263,    -1,
      90,    -1,    42,    -1,   102,    -1,   283,    -1,    26,    -1,
      30,    -1,    27,    -1,    35,    -1,    36,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    43,    -1,
      47,    -1,    49,    -1,    50,    -1,    52,    -1,    55,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    62,    -1,
      65,    -1,    67,    -1,    68,    -1,    70,    -1,    71,    -1,
      72,    -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    93,    -1,    94,    -1,    95,    -1,
      96,    -1,    17,    -1,    97,    -1,    98,    -1,    99,    -1,
     100,    -1,   103,    -1,   108,    -1,   109,    -1,   115,    -1,
     116,    -1,   119,    -1,   120,    -1,   122,    -1,   124,    -1,
     126,    -1,   127,    -1,   128,    -1,   129,    -1,   130,    -1,
     131,    -1,   134,    -1,   135,    -1,   136,    -1,   138,    -1,
     139,    -1,   141,    -1,   142,    -1,   143,    -1,   144,    -1,
     146,    -1,   147,    -1,   156,    -1,   158,    -1,   159,    -1,
     160,    -1,   162,    -1,   163,    -1,   164,    -1,   287,    -1,
     286,    -1,   286,     4,   284,    -1,    79,   286,    -1,    79,
     286,     4,   284,    -1,    51,    -1,   121,    -1,    33,   108,
     284,    -1,   146,   108,   284,    -1,    34,   108,   284,    -1,
     164,   108,   284,    -1,   163,   108,   284,    -1,    20,   287,
      -1,   287,    22,   287,    -1,   287,   122,   287,    -1,   287,
      24,   287,    -1,   287,    23,   287,    -1,   287,    21,   287,
      -1,   287,     6,   287,    -1,   287,     5,   287,    -1,   287,
      20,   287,    -1,   287,     3,   287,    -1,   291,    -1,   287,
     234,   287,    -1,    92,    -1,    91,    -1,   157,    -1,    53,
      -1,    54,    -1,    53,   110,   289,    44,    -1,   101,   110,
     289,    44,    -1,   165,   110,   289,    44,    -1,    56,   110,
     289,    44,    -1,   102,   110,   289,    44,    -1,   110,   287,
      44,    -1,    47,   287,    -1,    31,   287,    -1,   287,   138,
      -1,   287,     8,    -1,   287,     9,    -1,   287,    43,    -1,
     287,   256,    -1,   193,    -1,   285,    -1,   290,    -1,   289,
      -1,   287,    -1,   289,    48,   287,    -1,    -1,    42,    -1,
     107,    -1,   243,    -1,    90,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   240,   240,   248,   251,   260,   262,   267,   271,   271,
     275,   279,   282,   285,   290,   293,   293,   296,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   328,   329,   332,   336,
     336,   339,   344,   344,   347,   350,   350,   354,   355,   356,
     357,   358,   361,   364,   367,   370,   373,   380,   380,   384,
     385,   389,   392,   392,   396,   402,   406,   406,   410,   410,
     414,   418,   422,   426,   430,   434,   438,   446,   447,   448,
     452,   452,   463,   463,   466,   466,   469,   479,   482,   483,
     484,   502,   502,   506,   507,   512,   514,   519,   526,   527,
     528,   533,   539,   544,   545,   551,   556,   560,   561,   566,
     567,   568,   571,   572,   580,   580,   584,   595,   596,   599,
     600,   603,   604,   609,   610,   615,   616,   621,   622,   627,
     628,   634,   635,   640,   642,   649,   650,   653,   657,   658,
     666,   671,   675,   680,   682,   684,   686,   692,   693,   697,
     698,   703,   705,   707,   709,   711,   713,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   735,   736,
     737,   738,   740,   741,   742,   743,   773,   774,   775,   776,
     782,   786,   790,   791,   792,   795,   796,   797,   803,   808,
     808,   823,   823,   841,   844,   851,   852,   855,   856,   860,
     868,   868,   872,   889,   893,   894,   895,   896,   900,   901,
     905,   908,   915,   918,   919,   920,   921,   922,   923,   927,
     930,   931,   932,   933,   934,   935,   936,   941,   943,   945,
     946,   947,   948,   949,   950,   951,   952,   953,   954,   955,
     957,   959,   961,   963,   965,   970,   971,   972,   973,   974,
     975,   976,   979,   980,   981,   985,   985,   991,   992,  1004,
    1009,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,
    1030,  1031,  1068,  1079,  1080,  1081,  1082,  1083,  1086,  1095,
    1096,  1100,  1108,  1111,  1116,  1127,  1138,  1151,  1155,  1158,
    1158,  1170,  1176,  1183,  1191,  1191,  1194,  1200,  1205,  1212,
    1221,  1224,  1228,  1229,  1234,  1235,  1236,  1238,  1239,  1240,
    1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,
    1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,
    1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,
    1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,  1280,
    1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,  1290,
    1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,
    1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,
    1311,  1312,  1313,  1314,  1341,  1345,  1349,  1354,  1358,  1366,
    1371,  1376,  1381,  1386,  1391,  1396,  1404,  1423,  1431,  1438,
    1447,  1454,  1461,  1469,  1478,  1485,  1492,  1494,  1501,  1505,
    1509,  1513,  1522,  1532,  1539,  1545,  1551,  1558,  1564,  1565,
    1571,  1577,  1584,  1590,  1598,  1605,  1609,  1619,  1625,  1636,
    1643,  1650,  1659,  1665,  1669,  1673,  1677
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "USING", "WHERE", "KW_OR", "AND", "NOT",
  "IS_NULL", "IS_NOT_NULL", "NOT_EQUAL", "EQUAL", "LESS_THAN_EQ",
  "LESS_THAN", "GREATER_THAN_EQ", "GREATER_THAN", "NOT_LIKE", "LIKE",
  "NOT_MATCHES", "MATCHES", "MINUS", "PLUS", "DIVIDE", "MULTIPLY", "MOD",
  "POWER", "AFTER", "AFTGROUP", "ALL", "ANY", "ASC", "ASCII", "ATSIGN",
  "AVERAGE", "AVG", "BEFORE", "BETWEEN", "BOTTOM", "BY", "KW_CALL", "CH",
  "CHAR", "CHAR_VALUE", "CLIPPED", "CLOSE_BRACKET", "CLOSE_SQUARE",
  "COLON", "COLUMN", "COMMA", "COMMANDS", "COMPARISON", "COUNT",
  "DATABASE", "DATE", "TIME", "DATETIME", "DAY", "DECIMAL", "DEFINE",
  "DELIMITER", "DESC", "DISTINCT", "DO", "DOLLAR", "DOT", "ELSE", "END",
  "ESCAPE", "EVERY", "EXISTS", "EXTERNAL", "FIRST", "FLOAT", "PIPE", "FOR",
  "FORMAT", "FRACTION", "FROM", "FUNCTION", "GROUP", "GROUP_BY", "HAVING",
  "HEADER", "HOUR", "IF", "IN", "INPUT", "INTEGER", "INTERVAL", "INTO",
  "INTVAL", "KW_FALSE", "KW_TRUE", "LAST", "LEFT", "LENGTH", "LET",
  "LINES", "MARGIN", "MINUTE", "MONEY", "MONTH", "NAMED", "NEED",
  "NOT_EXISTS", "NOT_IN", "NUMBER_VALUE", "NUMERIC", "KW_OF", "ON",
  "OPEN_BRACKET", "OPEN_SQUARE", "ORDER_BY", "ORDER_EXTERNAL_BY", "OUTER",
  "OUTPUT", "PAGE", "PAGE_HEADER", "PAGE_TRAILER", "PARAM", "PAUSE",
  "PERCENT", "POW", "PRINT", "PRINTER", "PRINT_FILE", "PROMPT", "READ",
  "REPORT", "RIGHT", "ROW", "SECOND", "SELECT", "SEMICOLON", "SKIP",
  "SMALLFLOAT", "SMALLINT", "SOME", "SPACES", "STEP", "SUM", "TEMP",
  "THEN", "TO", "TOP", "TOP_OF_PAGE", "TOTAL", "TRAILER", "UNION",
  "UNIQUE", "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE", "UNITS_MONTH",
  "UNITS_SECOND", "UNITS_YEAR", "UPDATE", "USER", "VARCHAR", "VARIABLE",
  "WHILE", "WITH_NO_LOG", "XBEGIN", "XMAX", "XMIN", "YEAR", "$accept",
  "ace_report", "db_section", "op_define_section", "define_section",
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
  "val_expr_next", "value_expression_s", "value_expr_list",
  "value_specification", "commands", "command", "call_command",
  "func_identifier", "for_command", "op_step", "if_command", "op_else",
  "let_command", "op_expr_concat", "expr_concat", "need_command",
  "pause_command", "print_command", "op_semi", "print_file_command",
  "skip_command", "while_command", "int_val", "string", "identifier",
  "reserved_word", "expr", "aggregate", "aggregate_elem", "val_expression",
  "op_val_expr_list", "val_expr_list", "null_expr", "literal_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
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
     415,   416,   417,   418,   419,   420
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   166,   167,   168,   168,   169,   169,   170,   171,   171,
     172,   172,   172,   172,   173,   174,   174,   175,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   177,   177,   178,   179,
     179,   180,   181,   181,   182,   183,   183,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   185,   185,   186,
     186,   187,   188,   188,   189,   189,   190,   190,   191,   191,
     192,   192,   192,   192,   192,   192,   192,   193,   193,   193,
     194,   194,   195,   195,   197,   196,   196,   198,   198,   198,
     198,   200,   199,   201,   201,   202,   203,   203,   204,   204,
     204,   205,   206,   207,   207,   208,   209,   210,   210,   211,
     211,   211,   212,   212,   213,   213,   214,   215,   215,   216,
     216,   217,   217,   218,   218,   219,   219,   220,   220,   221,
     221,   222,   222,   223,   223,   224,   224,   225,   226,   226,
     227,   228,   229,   230,   230,   230,   230,   231,   231,   232,
     232,   233,   233,   233,   233,   233,   233,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   235,   235,
     235,   235,   236,   236,   236,   236,   237,   237,   237,   237,
     238,   239,   240,   240,   240,   241,   241,   241,   242,   243,
     243,   245,   244,   246,   247,   248,   248,   248,   248,   248,
     249,   249,   250,   251,   252,   252,   252,   252,   253,   253,
     254,   254,   255,   256,   256,   256,   256,   256,   256,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   258,   258,   258,   258,   258,
     258,   258,   259,   259,   259,   260,   260,   261,   261,   262,
     262,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   264,   265,   265,   265,   265,   265,   266,   267,
     267,   268,   269,   269,   270,   270,   270,   271,   271,   272,
     272,   273,   274,   275,   276,   276,   277,   278,   278,   279,
     280,   281,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   284,   285,   285,   285,   285,   286,
     286,   286,   286,   286,   286,   286,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   288,   288,
     289,   289,   290,   291,   291,   291,   291
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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
       1,     0,     3,     1,     3,     2,     1,     1,     0,     1,
       1,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       2,     4,     1,     2,     1,     3,     4,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     5,     3,     5,     3,     1,     3,     0,
       1,     3,     3,     3,     3,     6,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     0,     3,     5,     2,     4,     3,     1,     1,
       2,     0,     6,     1,     5,     0,     3,     1,     4,     5,
       0,     1,     1,     6,     0,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     4,     6,     6,     8,     2,     3,     3,     1,
       1,     1,     1,     3,     4,     4,     4,     4,     4,     4,
       5,     5,     5,     5,     5,     2,     2,     2,     1,     2,
       2,     2,     1,     2,     2,     1,     3,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     1,     1,     1,     1,     1,     9,     0,
       2,     5,     0,     2,     4,     7,     9,     0,     1,     1,
       3,     3,     2,     3,     0,     1,     2,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     4,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     3,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     5,     0,     0,     1,     0,    36,     6,
       3,     4,     0,     0,     0,     0,     0,     8,     0,    42,
      37,    17,    10,     0,    14,    13,     0,     0,     7,     9,
       0,     0,    39,     0,     0,    43,     0,    20,    24,    28,
      33,    25,    18,    19,    29,    30,    26,    27,    22,    15,
     300,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,   191,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   301,    56,    44,    46,    62,   204,
       0,     2,    58,     0,    57,    16,     0,     0,     0,     0,
       0,     0,    52,    51,    54,     0,    48,    49,    55,    53,
       0,    82,   205,   206,   207,     0,     0,     0,     0,     0,
       0,     0,    66,    68,    60,    21,    34,     0,    31,     0,
      23,    12,    41,    50,    47,    63,    84,     0,    61,    83,
     346,   232,   304,   306,   305,     0,   307,   308,   309,   310,
     311,   312,   313,    87,   314,   315,   316,   317,     0,   318,
       0,   319,     0,   320,   321,   322,   323,   324,     0,     0,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,    90,   230,   229,
     342,   343,   344,   345,   347,   348,   349,   350,     0,   302,
     351,   189,    88,   352,   353,     0,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,     0,   371,   372,   373,   374,   375,   376,
     377,   231,   378,   379,   380,   381,   382,   383,     0,   220,
      89,     0,   208,   210,   221,   303,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    65,    69,     0,     0,     0,
     176,    96,   382,   383,    86,    93,    98,     0,     0,   177,
      97,   182,   172,   172,     0,     0,   226,   190,     0,     0,
     172,   172,   172,     0,     0,     0,   117,   195,     0,     0,
       0,     0,     0,   211,     0,   215,   216,   217,   214,   218,
     213,   248,   219,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,    72,   259,   270,   261,   262,   264,   265,
     266,   268,   269,   267,   263,    71,    35,    32,    85,     0,
       0,    99,   100,    95,     0,     0,     0,   185,   173,   174,
     175,     0,     0,     0,   255,     0,     0,     0,   233,     0,
       0,     0,     0,   209,     0,   106,   107,   109,   112,   181,
       0,   118,   119,     0,    91,   172,   197,   192,     0,     0,
     252,   251,   250,   245,   249,   246,   247,   228,   227,     0,
       0,    81,    79,    80,     0,     0,    70,    73,    74,   273,
     276,   274,   275,     0,   277,     0,     0,     0,     0,     0,
     433,     0,   389,   411,   412,     0,     0,   436,   409,   408,
       0,    79,   434,     0,   390,     0,   410,     0,     0,     0,
     426,   435,     0,   427,   385,   384,   406,     0,     0,   292,
     294,   288,   289,   296,     0,     0,     0,     0,   260,   179,
     181,    94,   187,   182,   178,     0,     0,   239,     0,   234,
       0,   235,   236,     0,     0,     0,   237,     0,   110,     0,
     113,   188,     0,     0,     0,     0,   105,   123,   125,   127,
     171,   170,   169,   168,   129,     0,   149,     0,   120,   121,
       0,     0,     0,     0,   254,   253,     0,   238,   222,     0,
       0,    76,    75,   432,     0,   396,   420,     0,     0,   419,
       0,     0,   387,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,   423,   159,   157,   166,
     160,   167,   161,   163,   165,   162,   164,     0,     0,     0,
       0,     0,   424,   158,     0,   421,     0,   425,     0,     0,
     291,   295,   293,     0,   298,   297,     0,   271,   186,   183,
       0,   240,   244,   256,   243,   241,   242,   114,     0,   108,
     128,     0,   131,   132,   204,     0,   149,     0,     0,     0,
     150,     0,     0,     0,     0,   102,   103,   212,     0,   122,
     116,   200,   202,    92,   204,   196,   193,     0,     0,     0,
       0,   430,     0,   429,   428,     0,   391,   393,     0,     0,
       0,     0,     0,   418,   392,   395,   394,     0,   282,   386,
     405,   403,   402,   404,   401,   397,   400,   399,   398,   407,
     284,     0,   290,   299,     0,   111,     0,     0,   130,   124,
     126,   134,   257,   144,   257,   146,   151,   152,   257,     0,
     137,   139,     0,   138,     0,   135,   136,   154,   153,     0,
     101,   201,   198,     0,   200,   224,     0,   223,    78,     0,
     272,     0,     0,   413,   416,   388,   414,   417,   415,     0,
     281,     0,     0,   184,   115,     0,   258,     0,   147,     0,
       0,   141,     0,   133,   104,     0,   199,     0,     0,   431,
     279,   283,     0,     0,     0,   143,   257,   145,   257,   156,
       0,   195,   225,    77,     0,     0,   285,     0,   203,   148,
     140,   142,   155,   194,   280,     0,     0,   278,   286
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   255,   122,   123,   430,   394,   138,
     139,   259,   239,   376,   491,   264,   265,   266,   343,   589,
     488,   585,   371,   286,   365,   366,   367,   568,   287,   372,
     489,   590,   476,   477,   478,   479,   480,   481,   654,   655,
     656,   709,   690,   720,   482,   687,   583,   483,   546,   484,
     351,   368,   268,   269,   347,   270,   470,   240,    70,    89,
     595,   596,   377,   662,   591,   485,   115,   241,   242,   586,
     301,   380,   302,   381,   355,   688,   323,   324,   325,   403,
     326,   715,   327,   680,   328,   440,   441,   329,   330,   331,
     552,   332,   333,   334,    51,    85,   244,   245,   442,   433,
     434,   435,   602,   603,   604,   436
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -602
static const yytype_int16 yypact[] =
{
      10,    -3,    98,    42,    41,    52,  -602,    -5,    48,  -602,
    -602,  -602,    34,    90,    96,    34,    -6,  -602,    99,   101,
    -602,  -602,   185,  2013,  -602,  -602,   152,  2013,  -602,  -602,
     173,   -16,  -602,   125,     5,  -602,    34,   149,  -602,  -602,
     151,  -602,  -602,  -602,  -602,   164,  -602,  -602,   186,  -602,
    -602,   235,  -602,    34,  -602,  -602,   190,   205,   232,   192,
     231,   278,   344,   236,  -602,   344,  -602,   327,   -24,   337,
    -602,  2013,   152,   152,   152,   152,    34,   405,   152,   152,
     152,    -2,   152,   152,  -602,  -602,  -602,  -602,   351,     7,
     333,  -602,  -602,   285,  -602,  -602,   374,   170,   178,   375,
    2013,   344,  -602,  -602,  -602,   344,   344,  -602,  -602,  -602,
     344,   111,  -602,  -602,  -602,  1687,   356,   362,   318,   335,
      12,    14,    86,  -602,  -602,  -602,  -602,   152,  -602,   152,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  2120,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,   342,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,   343,  -602,
     345,  -602,   347,  -602,  -602,  -602,  -602,  -602,  2828,   364,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,   349,  -602,
    -602,  -602,  -602,  -602,  -602,  1687,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,   350,  -602,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,   355,   358,   366,  -602,
    -602,    26,  -602,   423,    62,  -602,   348,   363,   400,   397,
     354,   359,   965,   965,  -602,  -602,  -602,   428,   436,  2120,
     417,  -602,  -602,  -602,   437,  -602,    65,   426,   445,  -602,
    -602,    55,     9,    16,  1687,  1687,  -602,  -602,  1687,  1898,
       9,     9,     9,  1687,  1687,  2260,   489,   -10,  1255,  1255,
    1255,  1255,  1255,  -602,  1255,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  2544,  1687,   152,    39,    39,  -602,   965,
     965,   965,  1831,    34,  2996,   393,   152,   344,  2996,   344,
     -27,  2996,   965,   965,  -602,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,   965,  -602,  -602,   437,  2828,
    2120,  -602,  -602,  -602,  2688,  2828,   406,  -602,  -602,  -602,
    -602,  1687,   453,  1687,   846,   195,   212,   249,  -602,  1687,
    1687,  1687,   274,  -602,  2400,   450,  -602,  -602,  2828,   460,
     718,  -602,   419,   368,  -602,     9,   418,  -602,  1687,  1687,
     846,  -602,  -602,  -602,  -602,  -602,  -602,  -602,   410,   280,
     132,  -602,   413,  -602,   965,   965,   965,   965,   965,  -602,
    -602,  -602,  -602,   416,  -602,   516,  2996,  2996,   420,   421,
    -602,  2996,  -602,   422,  -602,   425,    18,  -602,  -602,  -602,
     429,   184,  -602,  2996,  -602,   430,  -602,   432,   433,   439,
    -602,  -602,   389,  -602,   529,   924,  -602,    22,   446,  -602,
     403,   494,  -602,  -602,   402,   467,   488,  1959,  -602,  -602,
    -602,  -602,  -602,   454,  -602,   289,  2997,  -602,  3033,  -602,
    1687,  -602,  -602,  3041,  3047,  3060,  -602,  2260,  -602,  2260,
    -602,  -602,  1399,   447,   447,   574,   561,   562,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,   900,   942,  1687,  -602,   486,
    2828,  2120,   438,   431,   188,   188,   152,  -602,  -602,   152,
    2996,   965,   965,  2996,  2996,    33,   261,  2996,  2996,   408,
    2996,  2996,   565,  2996,  2996,   881,  2996,  2996,  2996,  2996,
     965,  2996,  2996,  2996,  2996,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  2996,  2996,  2996,
    2996,  2996,  -602,  -602,  2996,  -602,  2996,  -602,  2996,  2996,
    -602,  -602,  -602,  2996,  -602,  -602,   965,  -602,  -602,  -602,
     481,  -602,  -602,   846,  -602,  -602,  -602,  -602,   288,  -602,
    -602,   448,  -602,  -602,     7,    76,  1990,   718,   718,  1687,
    -602,   469,   472,   241,  1106,   535,  -602,   846,   718,  -602,
    -602,   424,  -602,   437,     7,  -602,  -602,  2828,   299,   539,
     313,   924,   542,   540,  -602,   444,  -602,  -602,   325,   340,
    2996,   361,   382,  -602,  -602,  -602,  -602,   385,   524,  -602,
     924,   967,  2985,    33,    33,    -7,    -7,   261,   924,   924,
     494,   346,  -602,  -602,   547,  -602,  2260,  1687,  -602,   562,
    -602,   846,   193,  -602,   193,  -602,  -602,  -602,   256,  1687,
    -602,  -602,  1543,  -602,   447,  -602,  -602,  -602,   846,  1687,
     561,  -602,  -602,  1687,   424,  -602,   152,  -602,  -602,  2996,
    -602,  2996,  2996,  -602,  -602,  -602,  -602,  -602,  -602,   965,
    -602,   582,  2996,  -602,  -602,    26,  -602,   388,  -602,   390,
     527,  -602,   401,  -602,  -602,    26,  -602,   551,   554,   924,
     463,  -602,  2996,   558,   563,  -602,   256,  -602,   256,  -602,
    1687,   -10,  -602,  -602,  2996,   543,   494,   595,  -602,  -602,
    -602,  -602,   846,  -602,  -602,   965,  2996,  -602,   494
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -602,  -602,  -602,  -602,  -602,  -602,   602,  -602,  -602,   -12,
       4,  -602,  -602,  -602,   588,  -602,  -602,  -602,   557,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,   500,    60,   321,  -602,
    -602,  -602,  -329,  -602,  -602,  -251,   300,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -446,   283,  -602,  -601,  -602,
    -602,  -602,  -453,    77,    83,   183,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,    19,  -602,  -602,  -398,  -602,
    -235,  -135,  -602,  -146,   209,  -602,  -602,  -232,   586,  -602,
    -602,  -602,   -26,    23,    89,  -454,  -477,  -552,   404,    32,
    -109,  -115,  -602,    59,   -77,  -600,  -244,  -305,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,  -532,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,   -68,   -52,  -136,  -602,  -287,  -602,
     276,   -36,  -602,  -121,  -602,  -602
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -182
static const yytype_int16 yytable[] =
{
     243,   271,   267,    27,    96,    97,    98,    99,   338,   335,
     102,   103,   104,    88,   108,   109,   630,   541,   448,   572,
     573,   567,   575,   569,    71,    12,    12,   432,     4,   107,
     448,    52,   276,   548,   446,   112,   542,   348,   353,   352,
      84,    77,    92,   543,   348,   359,   360,   361,   691,   132,
      54,   408,   409,   133,   134,   539,   540,   541,   135,   257,
      28,   258,     1,    50,   100,   396,   397,   398,   113,   412,
     349,   105,    13,    13,   284,    95,   542,   349,   447,   373,
     250,   577,   431,   543,   704,   685,   431,   579,   584,   431,
     279,   448,   448,   448,   711,   341,   252,   637,     6,     5,
       7,  -180,   374,   285,   131,   251,   719,    10,   721,    93,
      30,   695,   116,    14,    14,   544,   444,   663,    11,  -181,
     638,   117,   106,   271,   267,   342,   303,   643,   645,   391,
     657,   545,    65,   549,    18,   660,    21,    66,   375,   424,
     492,   392,   448,   295,   296,   297,   298,   299,   300,   369,
     501,   502,   254,    15,    15,   544,   114,   119,   350,   354,
     354,   253,    56,   354,   425,   350,   346,   388,   354,   243,
     716,   545,   304,   305,   431,   431,   404,   498,   584,   431,
     499,   427,   428,   295,   296,   297,   298,   299,   300,   354,
     684,   431,    24,   449,   728,   120,   448,   448,   356,   454,
     693,   357,   121,   450,   271,   267,   362,    26,   453,   450,
     290,   291,   292,   600,   126,   618,    33,   605,   127,    57,
     606,   607,   128,   136,   137,    30,   129,   389,   369,   614,
     615,   616,   471,    36,   619,   153,   456,   390,   458,   459,
     593,    58,    50,   460,   463,   464,   465,    53,   438,   646,
     647,   633,   445,    59,    60,   486,   461,   169,   648,    72,
     460,    73,   631,   494,   495,   439,   632,   443,   431,    61,
      62,   431,   431,    56,    74,   431,   431,   649,   431,   431,
      76,   431,   431,   187,   431,   431,   431,   431,    78,   431,
     431,   431,   431,   462,   514,   500,    75,   460,   153,   201,
     202,   405,    86,    79,   542,   431,   431,   431,   431,   431,
     294,   543,   431,   686,   431,   686,   431,   431,   466,   686,
     169,   431,   460,   675,   497,   574,   547,    80,   460,    82,
      57,   369,   635,   369,   559,    81,   636,   560,   295,   296,
     297,   298,   299,   300,   665,   563,   187,   666,   382,   383,
     384,   385,    58,   386,   592,   271,   267,   486,   668,   116,
     576,   669,   201,   202,    59,    60,   393,   393,   117,   673,
     505,   506,   587,   671,   701,   509,    83,   686,   431,   686,
      61,    62,   698,   544,   674,   700,    84,   515,   671,   608,
     609,   681,   611,   612,   682,   703,   547,   547,   617,   545,
     547,   118,    90,    94,   119,   676,   547,   710,   101,   671,
     110,   295,   296,   297,   298,   299,   300,    66,   125,   130,
     727,   288,   289,   290,   291,   292,   677,   724,   598,   678,
     671,   599,   705,   671,   707,   246,   706,   431,   706,   431,
     431,   247,   120,   288,   289,   290,   291,   292,   248,   121,
     431,   249,   272,   273,   277,   274,   306,   275,   543,   278,
     280,   592,   486,   486,   641,   281,   308,   601,   282,   658,
     431,   307,   336,   486,   601,   601,   283,   601,   601,   309,
     337,   339,   431,   601,   310,   340,   620,   621,   622,   311,
     344,   345,   547,   370,   431,   437,   455,   457,   469,   487,
     369,   623,   624,   625,   626,   627,  -180,   493,   628,   490,
     629,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   496,   243,   294,   500,   293,   503,   504,   507,   508,
     544,   520,   510,   521,   692,   511,   551,   279,   516,   513,
     517,   518,   553,   550,   587,   294,   545,   554,   243,   519,
     556,   295,   296,   297,   298,   299,   300,   571,   295,   296,
     297,   298,   299,   300,   555,   346,   577,   588,   578,   610,
     594,   634,   597,   295,   296,   297,   298,   299,   300,   642,
     574,   472,   644,   659,   667,   661,   670,   672,   671,   679,
     547,   140,   683,   702,   708,   722,   712,   141,   697,   713,
     142,   143,   714,   717,   144,   725,   726,   718,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    29,    55,
      87,   155,   256,   156,   157,   158,   159,   160,   395,   161,
     162,   163,   164,   165,   166,   699,   167,   168,   169,   170,
     451,   171,   172,   473,   173,   174,   175,   468,   176,   177,
     178,   179,   180,   181,   639,   570,   182,   183,   184,   185,
     186,   640,   558,   689,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   474,   124,
     201,   202,   203,   204,   475,   723,   664,   696,   363,   206,
     207,   694,   512,   208,   209,     0,   210,     0,   211,     0,
     212,   213,   214,   215,   216,   217,   574,     0,   218,   219,
     220,     0,   221,   222,   223,   224,   225,   226,   227,     0,
     228,   229,     0,     0,     0,   472,     0,     0,     0,     0,
     230,   231,   232,   233,   234,   140,   235,   236,   237,   238,
       0,   141,     0,     0,   142,   143,     0,     0,   144,     0,
       0,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   155,     0,   156,   157,   158,
     159,   160,     0,   161,   162,   163,   164,   165,   166,     0,
     167,   168,   169,   170,     0,   171,   172,   473,   173,   174,
     175,     0,   176,   177,   178,   179,   180,   181,     0,     0,
     182,   183,   184,   185,   186,     0,     0,     0,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   474,     0,   201,   202,   203,   204,   475,     0,
       0,     0,     0,   206,   207,     0,     0,   208,   209,     0,
     210,     0,   211,     0,   212,   213,   214,   215,   216,   217,
       0,     0,   218,   219,   220,     0,   221,   222,   223,   224,
     225,   226,   227,     0,   228,   229,   288,   289,   290,   291,
     292,     0,     0,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,   522,     0,   523,   524,     0,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,     0,     0,     0,     0,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
       0,     0,     0,     0,   542,   613,     0,   522,     0,   523,
     524,   543,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   580,
     543,     0,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   288,   289,   290,   291,   292,   542,   294,     0,
       0,     0,     0,   524,   543,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   543,     0,     0,     0,   295,   296,   297,   298,
     299,   300,     0,   544,   312,     0,     0,     0,     0,     0,
     542,     0,     0,     0,     0,     0,     0,   543,     0,   545,
       0,     0,     0,     0,     0,     0,     0,   581,     0,     0,
       0,   295,   296,   297,   298,   299,   300,     0,     0,   313,
       0,     0,     0,     0,     0,     0,   544,   582,     0,   314,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,   545,     0,   294,     0,     0,     0,   316,     0,
       0,     0,     0,     0,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,     0,   317,     0,     0,   318,   544,
     319,     0,   295,   296,   297,   298,   299,   300,     0,   320,
       0,     0,     0,     0,     0,   545,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   296,   297,
     298,   299,   300,   140,     0,   321,     0,   322,     0,   141,
       0,     0,   142,   143,   650,   651,   144,     0,     0,     0,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
       0,     0,     0,   155,     0,   156,   157,   158,   159,   160,
       0,   161,   162,   163,   164,   165,   166,     0,   167,   168,
     169,   170,     0,   171,   172,     0,   173,   174,   175,     0,
     176,   177,   178,   179,   180,   181,     0,     0,   182,   183,
     184,   185,   186,     0,     0,     0,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
       0,     0,   201,   202,   203,   204,   652,     0,     0,     0,
       0,   206,   207,     0,     0,   208,   209,     0,   210,     0,
     211,     0,   212,   213,   214,   215,   216,   217,     0,     0,
     218,   219,   220,   653,   221,   222,   223,   224,   225,   226,
     227,     0,   228,   229,     0,     0,     0,     0,     0,     0,
       0,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,   140,     0,     0,   378,   379,     0,   141,     0,
       0,   142,   143,     0,     0,   144,     0,     0,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,   155,     0,   156,   157,   158,   159,   160,     0,
     161,   162,   163,   164,   165,   166,     0,   167,   168,   169,
     170,     0,   171,   172,     0,   173,   174,   175,     0,   176,
     177,   178,   179,   180,   181,     0,     0,   182,   183,   184,
     185,   186,     0,     0,     0,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,     0,
       0,   201,   202,   203,   204,   205,     0,     0,     0,     0,
     206,   207,     0,     0,   208,   209,     0,   210,     0,   211,
       0,   212,   213,   214,   215,   216,   217,     0,     0,   218,
     219,   220,     0,   221,   222,   223,   224,   225,   226,   227,
       0,   228,   229,     0,     0,     0,     0,     0,     0,     0,
       0,   230,   231,   232,   233,   234,   140,   235,   236,   237,
     238,     0,   141,     0,     0,   142,   143,     0,     0,   144,
       0,     0,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,     0,   155,     0,   156,   157,
     158,   159,   160,     0,   161,   162,   163,   164,   165,   166,
       0,   167,   168,   169,   170,     0,   171,   172,   473,   173,
     174,   175,     0,   176,   177,   178,   179,   180,   181,     0,
       0,   182,   183,   184,   185,   186,     0,     0,     0,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   474,     0,   201,   202,   203,   204,   475,
       0,     0,     0,     0,   206,   207,     0,     0,   208,   209,
       0,   210,     0,   211,     0,   212,   213,   214,   215,   216,
     217,     0,     0,   218,   219,   220,     0,   221,   222,   223,
     224,   225,   226,   227,     0,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,   230,   231,   232,   233,   234,
     140,   235,   236,   237,   238,     0,   141,     0,     0,   142,
     143,     0,     0,   144,     0,     0,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,     0,     0,
     155,     0,   156,   157,   158,   159,   160,     0,   161,   162,
     163,   164,   165,   166,     0,   167,   168,   169,   170,     0,
     171,   172,     0,   173,   174,   175,     0,   176,   177,   178,
     179,   180,   181,     0,     0,   182,   183,   184,   185,   186,
       0,     0,     0,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,     0,     0,   201,
     202,   203,   204,   205,     0,     0,     0,     0,   206,   207,
       0,     0,   208,   209,     0,   210,     0,   211,     0,   212,
     213,   214,   215,   216,   217,   574,     0,   218,   219,   220,
       0,   221,   222,   223,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,   140,   235,   236,   237,   238,     0,
     141,     0,     0,   142,   143,     0,     0,   144,     0,     0,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,   155,     0,   156,   157,   158,   159,
     160,     0,   161,   162,   163,   164,   165,   166,     0,   167,
     168,   169,   170,     0,   171,   172,     0,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,     0,     0,   182,
     183,   184,   185,   186,     0,     0,     0,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     0,     0,   201,   202,   203,   204,   205,     0,     0,
       0,     0,   206,   207,     0,     0,   208,   209,     0,   210,
       0,   211,     0,   212,   213,   214,   215,   216,   217,     0,
       0,   218,   219,   220,     0,   221,   222,   223,   224,   225,
     226,   227,     0,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,   234,   140,   235,
     236,   237,   238,     0,     0,     0,     0,   142,   143,     0,
       0,   144,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,     0,   154,     0,     0,     0,   155,     0,
     156,   157,     0,   159,   399,     0,   161,   400,   163,   164,
     165,   166,     0,   167,     0,     0,   170,     0,   171,   172,
       0,   173,   174,   175,     0,   176,   177,   178,   179,   180,
     181,     0,     0,   182,   183,   184,   185,   186,   288,   289,
     290,   291,   292,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   401,   199,   200,     0,     0,     0,     0,   203,
     204,     0,   358,     0,     0,     0,   206,   207,     0,     0,
     208,   209,     0,   210,     0,   211,     0,   212,   213,   214,
     215,   216,   217,     0,     0,   218,   219,   220,     0,   221,
     222,     0,   224,   225,   226,   227,     0,   228,   229,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,   232,
     233,   234,     0,   235,   262,   263,   402,   580,   312,     0,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     288,   289,   290,   291,   292,     0,     0,     0,     0,     0,
     294,     0,     0,     0,     0,   557,     0,     0,     0,     0,
       0,     0,     0,   313,   358,     0,     0,     0,     0,     0,
     543,     0,     0,   314,     0,     0,     0,     0,   295,   296,
     297,   298,   299,   300,    37,   315,     0,     0,     0,     0,
       0,     0,   316,     0,     0,     0,    38,     0,    39,     0,
      40,     0,     0,     0,     0,   581,     0,     0,     0,   317,
       0,     0,   318,     0,   319,    41,     0,     0,     0,     0,
       0,    42,     0,   320,     0,   582,     0,     0,     0,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   294,    45,     0,     0,     0,     0,     0,   321,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
     295,   296,   297,   298,   299,   300,   142,   143,    46,    47,
     144,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,   152,   260,   154,     0,     0,     0,   155,     0,   156,
     157,    48,   159,     0,     0,   161,     0,   163,   164,   165,
     166,     0,   167,     0,     0,   170,     0,   171,   172,     0,
     173,   174,   175,     0,   176,   177,   178,   179,   180,   181,
       0,     0,   182,   183,   184,   185,   186,     0,     0,     0,
     261,     0,     0,   190,   191,   192,   193,   194,   195,   196,
     197,     0,   199,   200,     0,     0,     0,     0,   203,   204,
       0,     0,     0,     0,     0,   206,   207,     0,     0,   208,
     209,     0,   210,     0,   211,     0,   212,   213,   214,   215,
     216,   217,     0,     0,   218,   219,   220,     0,   221,   222,
       0,   224,   225,   226,   227,     0,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   140,   232,   233,
     234,     0,   235,   262,   263,     0,   142,   143,     0,     0,
     144,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,   152,   260,   154,     0,     0,     0,   155,     0,   156,
     157,     0,   159,     0,     0,   161,     0,   163,   164,   165,
     166,     0,   167,     0,     0,   170,     0,   171,   172,     0,
     173,   174,   175,     0,   176,   177,   178,   179,   180,   181,
       0,     0,   182,   183,   184,   185,   186,     0,     0,     0,
       0,     0,     0,   190,   191,   192,   193,   194,   195,   196,
     197,     0,   199,   200,     0,     0,     0,     0,   203,   204,
       0,     0,     0,     0,   364,   206,   207,     0,     0,   208,
     209,     0,   210,     0,   211,     0,   212,   213,   214,   215,
     216,   217,     0,     0,   218,   219,   220,     0,   221,   222,
       0,   224,   225,   226,   227,     0,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   140,   232,   233,
     234,     0,   235,   262,   263,     0,   142,   143,     0,     0,
     144,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,   152,   260,   154,     0,     0,     0,   155,     0,   156,
     157,     0,   159,     0,     0,   161,     0,   163,   164,   165,
     166,     0,   167,     0,     0,   170,     0,   171,   172,     0,
     173,   174,   175,     0,   176,   177,   178,   179,   180,   181,
       0,     0,   182,   183,   184,   185,   186,     0,     0,     0,
       0,     0,     0,   190,   191,   192,   193,   194,   195,   196,
     197,     0,   199,   200,     0,     0,     0,     0,   203,   204,
     467,     0,     0,     0,     0,   206,   207,     0,     0,   208,
     209,     0,   210,     0,   211,     0,   212,   213,   214,   215,
     216,   217,     0,     0,   218,   219,   220,     0,   221,   222,
       0,   224,   225,   226,   227,     0,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,   230,     0,   232,   233,
     234,   140,   235,   262,   263,     0,     0,   387,     0,     0,
     142,   143,     0,     0,   144,     0,     0,     0,     0,   146,
     147,   148,   149,   150,   151,   152,     0,   154,     0,     0,
       0,   155,     0,   156,   157,     0,   159,     0,     0,   161,
       0,   163,   164,   165,   166,     0,   167,     0,     0,   170,
       0,   171,   172,     0,   173,   174,   175,     0,   176,   177,
     178,   179,   180,   181,     0,     0,   182,   183,   184,   185,
     186,     0,     0,     0,     0,     0,     0,   190,   191,   192,
     193,   194,   195,   196,   197,     0,   199,   200,     0,     0,
       0,     0,   203,   204,     0,     0,     0,     0,     0,   206,
     207,     0,     0,   208,   209,     0,   210,     0,   211,     0,
     212,   213,   214,   215,   216,   217,     0,     0,   218,   219,
     220,     0,   221,   222,     0,   224,   225,   226,   227,     0,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,   232,   233,   234,   140,   235,   262,   263,     0,
       0,   452,     0,     0,   142,   143,     0,     0,   144,     0,
       0,     0,     0,   146,   147,   148,   149,   150,   151,   152,
       0,   154,     0,     0,     0,   155,     0,   156,   157,     0,
     159,     0,     0,   161,     0,   163,   164,   165,   166,     0,
     167,     0,     0,   170,     0,   171,   172,     0,   173,   174,
     175,     0,   176,   177,   178,   179,   180,   181,     0,     0,
     182,   183,   184,   185,   186,     0,     0,     0,     0,     0,
       0,   190,   191,   192,   193,   194,   195,   196,   197,     0,
     199,   200,     0,     0,     0,     0,   203,   204,     0,     0,
       0,     0,     0,   206,   207,     0,     0,   208,   209,     0,
     210,     0,   211,     0,   212,   213,   214,   215,   216,   217,
       0,     0,   218,   219,   220,     0,   221,   222,     0,   224,
     225,   226,   227,     0,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   140,   232,   233,   234,     0,
     235,   262,   263,     0,   142,   143,     0,     0,   144,     0,
       0,     0,     0,   146,   147,   148,   149,   150,   151,   152,
       0,   154,     0,     0,     0,   155,     0,   156,   157,     0,
     159,     0,     0,   161,     0,   163,   164,   165,   166,     0,
     167,     0,     0,   170,     0,   171,   172,     0,   173,   174,
     175,     0,   176,   177,   178,   179,   180,   181,     0,     0,
     182,   183,   184,   185,   186,     0,     0,     0,     0,     0,
       0,   190,   191,   192,   193,   194,   195,   196,   197,     0,
     199,   200,     0,     0,     0,     0,   203,   204,     0,     0,
       0,     0,     0,   206,   207,     0,     0,   208,   209,     0,
     210,     0,   211,     0,   212,   213,   214,   215,   216,   217,
       0,     0,   218,   219,   220,     0,   221,   222,     0,   224,
     225,   226,   227,     0,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   230,     0,   232,   233,   234,     0,
     235,   262,   263,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
       0,     0,     0,     0,     0,     0,   406,   288,   289,   290,
     291,   292,     0,     0,     0,     0,     0,   407,   542,   408,
     409,     0,     0,     0,     0,   543,     0,     0,   410,     0,
       0,   561,     0,   411,     0,     0,     0,   412,     0,   413,
     414,     0,   415,   288,   289,   290,   291,   292,     0,     0,
     169,   288,   289,   290,   291,   292,     0,   288,   289,   290,
     291,   292,     0,     0,     0,   416,     0,   562,     0,     0,
     288,   289,   290,   291,   292,   564,   417,   418,   419,     0,
       0,   565,     0,     0,     0,     0,     0,   420,   421,     0,
       0,     0,   201,   422,   566,     0,   423,   544,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   424,     0,   294,
       0,     0,     0,   545,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   295,   296,   297,   298,   299,
     300,     0,   425,     0,     0,     0,     0,   295,   296,   297,
     298,   299,   300,   426,     0,   294,     0,     0,     0,   427,
     428,   429,     0,   294,     0,     0,     0,     0,     0,   294,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,   299,   300,     0,
       0,   295,   296,   297,   298,   299,   300,   295,   296,   297,
     298,   299,   300,     0,     0,     0,     0,     0,     0,     0,
     295,   296,   297,   298,   299,   300
};

static const yytype_int16 yycheck[] =
{
     115,   137,   137,    15,    72,    73,    74,    75,   259,   253,
      78,    79,    80,    65,    82,    83,   548,    24,   323,   473,
     474,   467,   475,   469,    36,    31,    31,   314,    31,    81,
     335,    27,   168,    11,   321,    28,    43,    28,   273,    23,
      42,    53,    66,    50,    28,   280,   281,   282,   648,   101,
      66,    33,    34,   105,   106,    22,    23,    24,   110,   127,
      66,   129,    52,    90,    76,   309,   310,   311,    61,    51,
      61,    73,    78,    78,    48,    71,    43,    61,   322,    89,
      68,     5,   314,    50,   685,   637,   318,   485,   486,   321,
     205,   396,   397,   398,   695,    30,    82,   574,     0,   102,
      58,    46,   112,    77,   100,    93,   706,    66,   708,   133,
     126,   663,    26,   119,   119,   122,   143,   594,    66,    64,
      44,    35,   124,   259,   259,    60,    64,   581,   582,    90,
     584,   138,   127,   111,    86,   588,   102,   132,   148,   121,
     375,   102,   447,   150,   151,   152,   153,   154,   155,   285,
     394,   395,    66,   159,   159,   122,   149,    71,   149,   274,
     275,   147,    37,   278,   146,   149,   111,   303,   283,   284,
     702,   138,   110,   111,   406,   407,   312,    45,   576,   411,
      48,   163,   164,   150,   151,   152,   153,   154,   155,   304,
     636,   423,   102,   339,   726,   109,   501,   502,   275,   345,
     654,   278,   116,   339,   340,   340,   283,   111,   344,   345,
      22,    23,    24,   500,    44,   520,   115,   504,    48,    94,
     507,   508,    44,   112,   113,   126,    48,   304,   364,   516,
     517,   518,   368,    48,   521,    42,   351,   305,   353,    44,
     491,   116,    90,    48,   359,   360,   361,    74,   316,     8,
       9,   556,   320,   128,   129,   370,    44,    64,    17,   110,
      48,   110,   549,   378,   379,   317,   553,   319,   500,   144,
     145,   503,   504,    37,   110,   507,   508,    36,   510,   511,
      45,   513,   514,    90,   516,   517,   518,   519,    98,   521,
     522,   523,   524,    44,   110,   111,   110,    48,    42,   106,
     107,   313,    66,    98,    43,   537,   538,   539,   540,   541,
     122,    50,   544,   642,   546,   644,   548,   549,    44,   648,
      64,   553,    48,   610,    44,   132,   435,    95,    48,    98,
      94,   467,    44,   469,    45,   143,    48,    48,   150,   151,
     152,   153,   154,   155,    45,   460,    90,    48,   289,   290,
     291,   292,   116,   294,   490,   491,   491,   472,    45,    26,
     475,    48,   106,   107,   128,   129,   306,   307,    35,    44,
     406,   407,   487,    48,   679,   411,    98,   706,   610,   708,
     144,   145,   669,   122,    44,   672,    42,   423,    48,   510,
     511,    45,   513,   514,    48,   682,   505,   506,   519,   138,
     509,    68,    75,    66,    71,    44,   515,     6,     3,    48,
      59,   150,   151,   152,   153,   154,   155,   132,    44,    44,
     725,    20,    21,    22,    23,    24,    44,   714,   496,    44,
      48,   499,    44,    48,    44,    79,    48,   669,    48,   671,
     672,    79,   109,    20,    21,    22,    23,    24,   130,   116,
     682,   116,   110,   110,    90,   110,   108,   110,    50,   110,
     110,   597,   577,   578,   579,   110,    66,   503,   110,   584,
     702,   108,    44,   588,   510,   511,   110,   513,   514,    82,
      44,    64,   714,   519,   130,    48,   522,   523,   524,   130,
      64,    46,   601,     4,   726,   102,    90,    44,    48,    80,
     636,   537,   538,   539,   540,   541,    46,    89,   544,   141,
     546,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   111,   637,   122,   111,   102,   110,    11,   108,   108,
     122,   142,   110,     4,   649,   110,   133,   652,   108,   110,
     108,   108,    48,    97,   659,   122,   138,   145,   663,   110,
      62,   150,   151,   152,   153,   154,   155,   110,   150,   151,
     152,   153,   154,   155,    97,   111,     5,    81,     6,     4,
     132,    90,   141,   150,   151,   152,   153,   154,   155,   110,
     132,     7,   110,    48,    45,   161,    44,   143,    48,    65,
     699,    17,    45,    11,    67,   710,    45,    23,   666,    45,
      26,    27,   139,    45,    30,    62,    11,    44,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    16,    31,
      63,    47,   122,    49,    50,    51,    52,    53,   307,    55,
      56,    57,    58,    59,    60,   671,    62,    63,    64,    65,
     340,    67,    68,    69,    70,    71,    72,   364,    74,    75,
      76,    77,    78,    79,   577,   472,    82,    83,    84,    85,
      86,   578,   453,   644,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    93,
     106,   107,   108,   109,   110,   711,   597,   664,   284,   115,
     116,   659,   416,   119,   120,    -1,   122,    -1,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,    -1,   138,   139,   140,   141,   142,   143,   144,    -1,
     146,   147,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,   160,    17,   162,   163,   164,   165,
      -1,    23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    -1,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    84,    85,    86,    -1,    -1,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,   106,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,   115,   116,    -1,    -1,   119,   120,    -1,
     122,    -1,   124,    -1,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,    -1,   138,   139,   140,   141,
     142,   143,   144,    -1,   146,   147,    20,    21,    22,    23,
      24,    -1,    -1,    -1,   156,   157,   158,   159,   160,    -1,
     162,   163,   164,   165,     3,    -1,     5,     6,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    43,    44,    -1,     3,    -1,     5,
       6,    50,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     7,
      50,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    43,   122,    -1,
      -1,    -1,    -1,     6,    50,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    50,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,    -1,   122,    39,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   105,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,   138,    -1,   122,    -1,    -1,    -1,   103,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,   123,   122,
     125,    -1,   150,   151,   152,   153,   154,   155,    -1,   134,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,    17,    -1,   160,    -1,   162,    -1,    23,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    47,    -1,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    67,    68,    -1,    70,    71,    72,    -1,
      74,    75,    76,    77,    78,    79,    -1,    -1,    82,    83,
      84,    85,    86,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,   115,   116,    -1,    -1,   119,   120,    -1,   122,    -1,
     124,    -1,   126,   127,   128,   129,   130,   131,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,   160,    -1,   162,   163,
     164,   165,    17,    -1,    -1,    20,    21,    -1,    23,    -1,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    47,    -1,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    67,    68,    -1,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    -1,    -1,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
     115,   116,    -1,    -1,   119,   120,    -1,   122,    -1,   124,
      -1,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,    -1,   138,   139,   140,   141,   142,   143,   144,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,   160,    17,   162,   163,   164,
     165,    -1,    23,    -1,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    -1,    67,    68,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    -1,
      -1,    82,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,   115,   116,    -1,    -1,   119,   120,
      -1,   122,    -1,   124,    -1,   126,   127,   128,   129,   130,
     131,    -1,    -1,   134,   135,   136,    -1,   138,   139,   140,
     141,   142,   143,   144,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
      17,   162,   163,   164,   165,    -1,    23,    -1,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      67,    68,    -1,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,   106,
     107,   108,   109,   110,    -1,    -1,    -1,    -1,   115,   116,
      -1,    -1,   119,   120,    -1,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
      -1,   138,   139,   140,   141,   142,   143,   144,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,    17,   162,   163,   164,   165,    -1,
      23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    -1,    67,    68,    -1,    70,    71,    72,
      -1,    74,    75,    76,    77,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    -1,    -1,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,   115,   116,    -1,    -1,   119,   120,    -1,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,    -1,
      -1,   134,   135,   136,    -1,   138,   139,   140,   141,   142,
     143,   144,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,    17,   162,
     163,   164,   165,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    -1,    -1,    -1,    47,    -1,
      49,    50,    -1,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    -1,    62,    -1,    -1,    65,    -1,    67,    68,
      -1,    70,    71,    72,    -1,    74,    75,    76,    77,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    20,    21,
      22,    23,    24,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,    -1,    44,    -1,    -1,    -1,   115,   116,    -1,    -1,
     119,   120,    -1,   122,    -1,   124,    -1,   126,   127,   128,
     129,   130,   131,    -1,    -1,   134,   135,   136,    -1,   138,
     139,    -1,   141,   142,   143,   144,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,   158,
     159,   160,    -1,   162,   163,   164,   165,     7,    39,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    44,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    84,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,   155,    41,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    53,    -1,    55,    -1,
      57,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,   120,
      -1,    -1,   123,    -1,   125,    72,    -1,    -1,    -1,    -1,
      -1,    78,    -1,   134,    -1,   105,    -1,    -1,    -1,    -1,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   100,    -1,    -1,    -1,    -1,    -1,   160,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
     150,   151,   152,   153,   154,   155,    26,    27,   135,   136,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,    49,
      50,   158,    52,    -1,    -1,    55,    -1,    57,    58,    59,
      60,    -1,    62,    -1,    -1,    65,    -1,    67,    68,    -1,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,   115,   116,    -1,    -1,   119,
     120,    -1,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,    -1,   138,   139,
      -1,   141,   142,   143,   144,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    17,   158,   159,
     160,    -1,   162,   163,   164,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,    49,
      50,    -1,    52,    -1,    -1,    55,    -1,    57,    58,    59,
      60,    -1,    62,    -1,    -1,    65,    -1,    67,    68,    -1,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,   114,   115,   116,    -1,    -1,   119,
     120,    -1,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,    -1,   138,   139,
      -1,   141,   142,   143,   144,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    17,   158,   159,
     160,    -1,   162,   163,   164,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,    49,
      50,    -1,    52,    -1,    -1,    55,    -1,    57,    58,    59,
      60,    -1,    62,    -1,    -1,    65,    -1,    67,    68,    -1,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,   115,   116,    -1,    -1,   119,
     120,    -1,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,    -1,    -1,   134,   135,   136,    -1,   138,   139,
      -1,   141,   142,   143,   144,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,   158,   159,
     160,    17,   162,   163,   164,    -1,    -1,    23,    -1,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    -1,
      -1,    47,    -1,    49,    50,    -1,    52,    -1,    -1,    55,
      -1,    57,    58,    59,    60,    -1,    62,    -1,    -1,    65,
      -1,    67,    68,    -1,    70,    71,    72,    -1,    74,    75,
      76,    77,    78,    79,    -1,    -1,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   102,   103,    -1,    -1,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,   115,
     116,    -1,    -1,   119,   120,    -1,   122,    -1,   124,    -1,
     126,   127,   128,   129,   130,   131,    -1,    -1,   134,   135,
     136,    -1,   138,   139,    -1,   141,   142,   143,   144,    -1,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,   158,   159,   160,    17,   162,   163,   164,    -1,
      -1,    23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,
      52,    -1,    -1,    55,    -1,    57,    58,    59,    60,    -1,
      62,    -1,    -1,    65,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
     102,   103,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,   115,   116,    -1,    -1,   119,   120,    -1,
     122,    -1,   124,    -1,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,    -1,   138,   139,    -1,   141,
     142,   143,   144,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    17,   158,   159,   160,    -1,
     162,   163,   164,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,
      52,    -1,    -1,    55,    -1,    57,    58,    59,    60,    -1,
      62,    -1,    -1,    65,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,    84,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
     102,   103,    -1,    -1,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,   115,   116,    -1,    -1,   119,   120,    -1,
     122,    -1,   124,    -1,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,    -1,   138,   139,    -1,   141,
     142,   143,   144,    -1,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,   160,    -1,
     162,   163,   164,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    31,    43,    33,
      34,    -1,    -1,    -1,    -1,    50,    -1,    -1,    42,    -1,
      -1,    44,    -1,    47,    -1,    -1,    -1,    51,    -1,    53,
      54,    -1,    56,    20,    21,    22,    23,    24,    -1,    -1,
      64,    20,    21,    22,    23,    24,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    79,    -1,    44,    -1,    -1,
      20,    21,    22,    23,    24,    44,    90,    91,    92,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,    -1,   106,   107,    44,    -1,   110,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,   122,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
     155,    -1,   146,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,   157,    -1,   122,    -1,    -1,    -1,   163,
     164,   165,    -1,   122,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   150,   151,   152,   153,   154,   155,    -1,
      -1,   150,   151,   152,   153,   154,   155,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    52,   167,   168,    31,   102,     0,    58,   169,   170,
      66,    66,    31,    78,   119,   159,   171,   172,    86,   177,
     178,   102,   174,   175,   102,   173,   111,   175,    66,   172,
     126,   179,   180,   115,   181,   182,    48,    41,    53,    55,
      57,    72,    78,    87,    88,   100,   135,   136,   158,   176,
      90,   280,   176,    74,    66,   180,    37,    94,   116,   128,
     129,   144,   145,   183,   184,   127,   132,   185,   186,   187,
     244,   175,   110,   110,   110,   110,    45,   175,    98,    98,
      95,   143,    98,    98,    42,   281,    66,   184,   281,   245,
      75,   189,    66,   133,    66,   176,   280,   280,   280,   280,
     175,     3,   280,   280,   280,    73,   124,   281,   280,   280,
      59,   188,    28,    61,   149,   252,    26,    35,    68,    71,
     109,   116,   191,   192,   244,    44,    44,    48,    44,    48,
      44,   176,   281,   281,   281,   281,   112,   113,   195,   196,
      17,    23,    26,    27,    30,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    47,    49,    50,    51,    52,
      53,    55,    56,    57,    58,    59,    60,    62,    63,    64,
      65,    67,    68,    70,    71,    72,    74,    75,    76,    77,
      78,    79,    82,    83,    84,    85,    86,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   106,   107,   108,   109,   110,   115,   116,   119,   120,
     122,   124,   126,   127,   128,   129,   130,   131,   134,   135,
     136,   138,   139,   140,   141,   142,   143,   144,   146,   147,
     156,   157,   158,   159,   160,   162,   163,   164,   165,   198,
     243,   253,   254,   257,   282,   283,    79,    79,   130,   116,
      68,    93,    82,   147,    66,   190,   192,   280,   280,   197,
      42,    90,   163,   164,   201,   202,   203,   237,   238,   239,
     241,   282,   110,   110,   110,   110,   282,    90,   110,   257,
     110,   110,   110,   110,    48,    77,   209,   214,    20,    21,
      22,    23,    24,   102,   122,   150,   151,   152,   153,   154,
     155,   256,   258,    64,   110,   111,   108,   108,    66,    82,
     130,   130,    39,    74,    84,    96,   103,   120,   123,   125,
     134,   160,   162,   262,   263,   264,   266,   268,   270,   273,
     274,   275,   277,   278,   279,   262,    44,    44,   201,    64,
      48,    30,    60,   204,    64,    46,   111,   240,    28,    61,
     149,   236,    23,   236,   257,   260,   260,   260,    44,   236,
     236,   236,   260,   254,   114,   210,   211,   212,   237,   282,
       4,   208,   215,    89,   112,   148,   199,   248,    20,    21,
     257,   259,   259,   259,   259,   259,   259,    23,   282,   260,
     280,    90,   102,   193,   194,   194,   262,   262,   262,    53,
      56,   101,   165,   265,   282,   175,    20,    31,    33,    34,
      42,    47,    51,    53,    54,    56,    79,    90,    91,    92,
     101,   102,   107,   110,   121,   146,   157,   163,   164,   165,
     193,   243,   284,   285,   286,   287,   291,   102,   280,   281,
     271,   272,   284,   281,   143,   280,   284,   262,   263,   239,
     282,   202,    23,   282,   239,    90,   257,    44,   257,    44,
      48,    44,    44,   257,   257,   257,    44,   110,   212,    48,
     242,   282,     7,    69,   104,   110,   218,   219,   220,   221,
     222,   223,   230,   233,   235,   251,   257,    80,   206,   216,
     141,   200,   236,    89,   257,   257,   111,    44,    45,    48,
     111,   262,   262,   110,    11,   287,   287,   108,   108,   287,
     110,   110,   286,   110,   110,   287,   108,   108,   108,   110,
     142,     4,     3,     5,     6,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    43,    50,   122,   138,   234,   256,    11,   111,
      97,   133,   276,    48,   145,    97,    62,    66,   240,    45,
      48,    44,    44,   257,    44,    44,    44,   211,   213,   211,
     221,   110,   251,   251,   132,   218,   257,     5,     6,   234,
       7,    85,   105,   232,   234,   207,   255,   257,    81,   205,
     217,   250,   282,   201,   132,   246,   247,   141,   280,   280,
     284,   287,   288,   289,   290,   284,   284,   284,   289,   289,
       4,   289,   289,    44,   284,   284,   284,   289,   263,   284,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     272,   284,   284,   263,    90,    44,    48,   252,    44,   219,
     220,   257,   110,   251,   110,   251,     8,     9,    17,    36,
      28,    29,   110,   137,   224,   225,   226,   251,   257,    48,
     218,   161,   249,   252,   250,    45,    48,    45,    45,    48,
      44,    48,   143,    44,    44,   284,    44,    44,    44,    65,
     269,    45,    48,    45,   211,   253,   198,   231,   261,   231,
     228,   261,   257,   251,   255,   253,   249,   280,   284,   287,
     284,   263,    11,   284,   214,    44,    48,    44,    67,   227,
       6,   214,    45,    45,   139,   267,   272,    45,    44,   261,
     229,   261,   257,   248,   284,    62,    11,   263,   272
};

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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    const YYSTYPE * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    const YYSTYPE * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, 
		   int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule
		   )
    YYSTYPE *yyvsp;
    
		   int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 248 "ace.yacc"
    {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
    break;

  case 4:
#line 251 "ace.yacc"
    {
		this_report.dbname=acl_strdup((yyvsp[(2) - (3)].str));
		A4GLSQL_init_connection ((yyvsp[(2) - (3)].str));
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
    break;

  case 10:
#line 275 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:
#line 279 "ace.yacc"
    {
		ace_add_variable((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str),CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:
#line 282 "ace.yacc"
    {
		ace_add_variable((yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str),CAT_PARAM,atoi((yyvsp[(3) - (6)].str)),-1,0);
	}
    break;

  case 13:
#line 285 "ace.yacc"
    {
		add_function((yyvsp[(2) - (2)].str));
	}
    break;

  case 17:
#line 296 "ace.yacc"
    {
	char buff[256];
	int a;
	strcpy(buff,(yyvsp[(1) - (1)].str));
	for (a=0;a<strlen(buff);a++) {
		buff[a]=toupper(buff[a]);
	}
	strcpy((yyval.str),buff);
	}
    break;

  case 19:
#line 309 "ace.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 20:
#line 310 "ace.yacc"
    {strcpy((yyval.str),"CHAR");}
    break;

  case 21:
#line 311 "ace.yacc"
    {sprintf((yyval.str),"CHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 22:
#line 312 "ace.yacc"
    {strcpy((yyval.str),"VARCHAR");}
    break;

  case 23:
#line 313 "ace.yacc"
    {sprintf((yyval.str),"VARCHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 24:
#line 314 "ace.yacc"
    {strcpy((yyval.str),"DATE");}
    break;

  case 25:
#line 315 "ace.yacc"
    {strcpy((yyval.str),"FLOAT");}
    break;

  case 26:
#line 316 "ace.yacc"
    {strcpy((yyval.str),"SMALLFLOAT");}
    break;

  case 27:
#line 317 "ace.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 28:
#line 318 "ace.yacc"
    {strcpy((yyval.str),"DATETIME");}
    break;

  case 29:
#line 319 "ace.yacc"
    {strcpy((yyval.str),"INTERVAL");}
    break;

  case 30:
#line 320 "ace.yacc"
    {strcpy((yyval.str),"MONEY");}
    break;

  case 31:
#line 321 "ace.yacc"
    {sprintf((yyval.str),"MONEY (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 32:
#line 322 "ace.yacc"
    {sprintf((yyval.str),"MONEY (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 33:
#line 323 "ace.yacc"
    {strcpy((yyval.str),"DECIMAL");}
    break;

  case 34:
#line 324 "ace.yacc"
    {sprintf((yyval.str),"DECIMAL (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 35:
#line 325 "ace.yacc"
    {sprintf((yyval.str),"DECIMAL (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 41:
#line 339 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes((yyvsp[(5) - (5)].str)),(yyvsp[(3) - (5)].str));
}
    break;

  case 47:
#line 354 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str));}
    break;

  case 48:
#line 355 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:
#line 356 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup((yyvsp[(3) - (3)].str)); }
    break;

  case 50:
#line 357 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str)); }
    break;

  case 51:
#line 358 "ace.yacc"
    {
		this_report.output.left_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 52:
#line 361 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 53:
#line 364 "ace.yacc"
    {
		this_report.output.top_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 54:
#line 367 "ace.yacc"
    {
		this_report.output.page_length=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 55:
#line 370 "ace.yacc"
    {
		this_report.output.right_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 56:
#line 373 "ace.yacc"
    {
		this_report.output.top_of_page=acl_strdup((yyvsp[(2) - (2)].str));
	}
    break;

  case 58:
#line 380 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:
#line 384 "ace.yacc"
    { add_select((yyvsp[(1) - (1)].str),temp_tab_name); }
    break;

  case 60:
#line 385 "ace.yacc"
    { add_select((yyvsp[(3) - (3)].str),temp_tab_name); }
    break;

  case 64:
#line 396 "ace.yacc"
    {
		struct commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,"",cmd);
	  }
    break;

  case 70:
#line 415 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,"",(yyvsp[(4) - (4)].commands));
	}
    break;

  case 71:
#line 419 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,"",(yyvsp[(3) - (3)].commands));
	}
    break;

  case 72:
#line 423 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,"",(yyvsp[(3) - (3)].commands));
	}
    break;

  case 73:
#line 427 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,"",(yyvsp[(4) - (4)].commands));
	}
    break;

  case 74:
#line 431 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,"",(yyvsp[(4) - (4)].commands));
	}
    break;

  case 75:
#line 435 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 76:
#line 439 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 81:
#line 452 "ace.yacc"
    {
int vid;
int a;
a=atoi((yyvsp[(1) - (1)].str));
vid = find_sql_var (a);
sprintf((yyval.str),this_report.variables.variables_val[vid].name);
}
    break;

  case 82:
#line 463 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 84:
#line 466 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:
#line 466 "ace.yacc"
    {
	printf("speclist : %s ",(yyvsp[(3) - (3)].str));
	sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str));}
    break;

  case 86:
#line 470 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:
#line 479 "ace.yacc"
    {
		sprintf((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));
	}
    break;

  case 91:
#line 502 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 92:
#line 502 "ace.yacc"
    { sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str)); }
    break;

  case 94:
#line 507 "ace.yacc"
    {
sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 96:
#line 514 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"I%d",atoi((yyvsp[(1) - (1)].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 97:
#line 519 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"C%s",(yyvsp[(1) - (1)].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 98:
#line 526 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:
#line 534 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 102:
#line 540 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 104:
#line 546 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 105:
#line 551 "ace.yacc"
    {sprintf((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[(2) - (2)].str));}
    break;

  case 106:
#line 556 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 108:
#line 562 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 109:
#line 566 "ace.yacc"
    {sprintf((yyval.str)," %s ", (yyvsp[(1) - (1)].str));}
    break;

  case 110:
#line 567 "ace.yacc"
    {sprintf((yyval.str)," %s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 111:
#line 568 "ace.yacc"
    {sprintf((yyval.str)," %s (%s) ",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 113:
#line 572 "ace.yacc"
    {
		sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		ace_add_table((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 115:
#line 580 "ace.yacc"
    { sprintf((yyval.str)," %s,%s ",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 116:
#line 588 "ace.yacc"
    {
sprintf((yyval.str),"%s %s %s %s",
(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),
(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
}
    break;

  case 117:
#line 595 "ace.yacc"
    {strcpy((yyval.str),"\n0");}
    break;

  case 119:
#line 599 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 121:
#line 603 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 124:
#line 611 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 126:
#line 617 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 128:
#line 623 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 130:
#line 629 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 131:
#line 634 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 132:
#line 635 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 133:
#line 641 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 134:
#line 643 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 140:
#line 667 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 143:
#line 681 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 144:
#line 683 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 145:
#line 685 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 146:
#line 687 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 148:
#line 694 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 149:
#line 697 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 151:
#line 704 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 152:
#line 706 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 153:
#line 708 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 154:
#line 710 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 155:
#line 712 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 156:
#line 714 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 166:
#line 729 "ace.yacc"
    {sprintf((yyval.str),"<=");}
    break;

  case 167:
#line 730 "ace.yacc"
    {sprintf((yyval.str),">=");}
    break;

  case 172:
#line 740 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 176:
#line 773 "ace.yacc"
    { sprintf((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[(1) - (1)].str))); }
    break;

  case 177:
#line 774 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 178:
#line 775 "ace.yacc"
    { sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 179:
#line 776 "ace.yacc"
    { sprintf((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[(1) - (3)].str)),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 181:
#line 786 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 182:
#line 790 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 183:
#line 791 "ace.yacc"
    {sprintf((yyval.str),"[%s]",(yyvsp[(2) - (3)].str));}
    break;

  case 184:
#line 792 "ace.yacc"
    {sprintf((yyval.str),"[%s,%s]",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));}
    break;

  case 185:
#line 795 "ace.yacc"
    { sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 186:
#line 796 "ace.yacc"
    { sprintf((yyval.str),"%s.%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); }
    break;

  case 187:
#line 797 "ace.yacc"
    { sprintf((yyval.str),"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 190:
#line 808 "ace.yacc"
    {sprintf((yyval.str),"0.%s",(yyvsp[(2) - (2)].str));}
    break;

  case 191:
#line 823 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 192:
#line 826 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));
}
    break;

  case 194:
#line 847 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str) );}
    break;

  case 195:
#line 851 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 196:
#line 852 "ace.yacc"
    {
       sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
       }
    break;

  case 198:
#line 856 "ace.yacc"
    {
       sprintf((yyval.str),"INTO TEMP %s%s ",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (4)].str));
}
    break;

  case 199:
#line 860 "ace.yacc"
    {
       sprintf((yyval.str),"%s INTO TEMP %s%s ",(yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (5)].str));
}
    break;

  case 200:
#line 868 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 201:
#line 868 "ace.yacc"
    {strcpy((yyval.str)," WITH NO LOG");}
    break;

  case 203:
#line 890 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 204:
#line 893 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 205:
#line 894 "ace.yacc"
    {sprintf((yyval.str),"ALL");}
    break;

  case 206:
#line 895 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 207:
#line 896 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 209:
#line 901 "ace.yacc"
    { sprintf((yyval.str)," %s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 210:
#line 905 "ace.yacc"
    {
			add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
		}
    break;

  case 211:
#line 908 "ace.yacc"
    {
			sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_select_column((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 213:
#line 918 "ace.yacc"
    {sprintf((yyval.str),"UNITS YEAR");}
    break;

  case 214:
#line 919 "ace.yacc"
    {sprintf((yyval.str),"UNITS MONTH"); }
    break;

  case 215:
#line 920 "ace.yacc"
    {sprintf((yyval.str),"UNITS DAY);"); }
    break;

  case 216:
#line 921 "ace.yacc"
    {sprintf((yyval.str),"UNITS HOUR);"); }
    break;

  case 217:
#line 922 "ace.yacc"
    {sprintf((yyval.str),"UNITS MINUTE);"); }
    break;

  case 218:
#line 923 "ace.yacc"
    {sprintf((yyval.str),"UNITS SECOND);"); }
    break;

  case 219:
#line 927 "ace.yacc"
    {
			sprintf((yyval.str),"%s%s", (yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 222:
#line 932 "ace.yacc"
    {sprintf((yyval.str)," %s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 223:
#line 933 "ace.yacc"
    {sprintf((yyval.str)," %s[%s,%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 224:
#line 934 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 225:
#line 935 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s,%s]",(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str));}
    break;

  case 226:
#line 937 "ace.yacc"
    {
if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
sprintf((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
}
    break;

  case 227:
#line 942 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 228:
#line 944 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 232:
#line 948 "ace.yacc"
    {sprintf((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 233:
#line 949 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 234:
#line 950 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 235:
#line 951 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 236:
#line 952 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 237:
#line 953 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 238:
#line 954 "ace.yacc"
    {sprintf((yyval.str),"%s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 239:
#line 956 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 240:
#line 958 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 241:
#line 960 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 242:
#line 962 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 243:
#line 964 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 244:
#line 966 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 245:
#line 970 "ace.yacc"
    {sprintf((yyval.str),"/%s",(yyvsp[(2) - (2)].str));}
    break;

  case 246:
#line 971 "ace.yacc"
    {sprintf((yyval.str)," MOD %s",(yyvsp[(2) - (2)].str));}
    break;

  case 247:
#line 972 "ace.yacc"
    {sprintf((yyval.str)," POW %s",(yyvsp[(2) - (2)].str));}
    break;

  case 248:
#line 973 "ace.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 249:
#line 974 "ace.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 250:
#line 975 "ace.yacc"
    {sprintf((yyval.str),"+%s",(yyvsp[(2) - (2)].str));}
    break;

  case 251:
#line 976 "ace.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 256:
#line 986 "ace.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 259:
#line 1004 "ace.yacc"
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[(1) - (1)].cmd));
		}
    break;

  case 260:
#line 1009 "ace.yacc"
    {
		COPY((yyval.commands),(yyvsp[(1) - (2)].commands));
		(yyval.commands).commands.commands_len++;
		(yyval.commands).commands.commands_val=realloc(
		(yyval.commands).commands.commands_val,
		(yyval.commands).commands.commands_len*sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[ (yyval.commands).commands.commands_len-1 ],(yyvsp[(2) - (2)].cmd));
	}
    break;

  case 271:
#line 1031 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).command_u.commands.commands.commands_val=(yyvsp[(2) - (3)].commands).commands.commands_val;
		(yyval.cmd).command_u.commands.commands.commands_len=(yyvsp[(2) - (3)].commands).commands.commands_len;
	}
    break;

  case 272:
#line 1068 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[(2) - (5)].str));
	
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(4) - (5)].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).command_u.cmd_call.fcall->lexpr);
}
    break;

  case 278:
#line 1086 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_FOR;
		(yyval.cmd).command_u.cmd_for.varid=find_variable((yyvsp[(2) - (9)].str));
		(yyval.cmd).command_u.cmd_for.start=(yyvsp[(4) - (9)].expr);
		(yyval.cmd).command_u.cmd_for.finish=(yyvsp[(6) - (9)].expr);
		(yyval.cmd).command_u.cmd_for.step=(yyvsp[(7) - (9)].expr);
	}
    break;

  case 279:
#line 1095 "ace.yacc"
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
    break;

  case 280:
#line 1096 "ace.yacc"
    { (yyval.expr)=(yyvsp[(1) - (2)].expr);}
    break;

  case 281:
#line 1100 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_IF;
	(yyval.cmd).command_u.cmd_if.condition=(yyvsp[(2) - (5)].expr);
	(yyval.cmd).command_u.cmd_if.command=(struct command *)DUP((yyvsp[(4) - (5)].cmd));
	(yyval.cmd).command_u.cmd_if.elsecommand=(struct command *)DUP((yyvsp[(5) - (5)].cmd));
}
    break;

  case 282:
#line 1108 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).command_u.null=1;
	}
    break;

  case 283:
#line 1111 "ace.yacc"
    { COPY((yyval.cmd),(yyvsp[(2) - (2)].cmd)); }
    break;

  case 284:
#line 1116 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (4)].str));
		(yyval.cmd).command_u.cmd_let.varid=v;
		(yyval.cmd).command_u.cmd_let.value=(yyvsp[(4) - (4)].expr);
		set_expr_int(&(yyval.cmd).command_u.cmd_let.sub1,-1);
		set_expr_int(&(yyval.cmd).command_u.cmd_let.sub2,-1); 
	}
    break;

  case 285:
#line 1127 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (7)].str));
		(yyval.cmd).command_u.cmd_let.varid=v;
		(yyval.cmd).command_u.cmd_let.value=(yyvsp[(7) - (7)].expr);
		(yyval.cmd).command_u.cmd_let.sub1=(yyvsp[(4) - (7)].expr); 
		(yyval.cmd).command_u.cmd_let.sub2=(yyvsp[(4) - (7)].expr); 
	}
    break;

  case 286:
#line 1138 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (9)].str));
		(yyval.cmd).command_u.cmd_let.varid=v;
		(yyval.cmd).command_u.cmd_let.value=(yyvsp[(9) - (9)].expr);
		(yyval.cmd).command_u.cmd_let.sub1=(yyvsp[(4) - (9)].expr); 
		(yyval.cmd).command_u.cmd_let.sub2=(yyvsp[(6) - (9)].expr); 
	}
    break;

  case 287:
#line 1151 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
    break;

  case 290:
#line 1158 "ace.yacc"
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 291:
#line 1170 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).command_u.cmd_need.nlines=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 292:
#line 1176 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).command_u.cmd_pause.message=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 293:
#line 1183 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).command_u.cmd_print.printnl=atoi((yyvsp[(3) - (3)].str));
	(yyval.cmd).command_u.cmd_print.print=(yyvsp[(2) - (3)].expr);
}
    break;

  case 294:
#line 1191 "ace.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 295:
#line 1191 "ace.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 296:
#line 1194 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).command_u.cmd_printfile.filename=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 297:
#line 1200 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=atoi((yyvsp[(2) - (3)].str));

	}
    break;

  case 298:
#line 1205 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=-1;
	}
    break;

  case 299:
#line 1212 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		(yyval.cmd).command_u.cmd_while.condition=(yyvsp[(2) - (4)].expr);
		(yyval.cmd).command_u.cmd_while.command=(struct command *)DUP((yyvsp[(4) - (4)].cmd));
}
    break;

  case 385:
#line 1345 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (1)].agg_val));
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 386:
#line 1349 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (3)].agg_val));
		(yyval.agg_val).wexpr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 387:
#line 1354 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(2) - (2)].agg_val));
		(yyval.agg_val).isgroup=1;
	}
    break;

  case 388:
#line 1358 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(2) - (4)].agg_val));
		(yyval.agg_val).wexpr=(struct expr *)DUP((yyvsp[(4) - (4)].expr));
		(yyval.agg_val).isgroup=1;
	}
    break;

  case 389:
#line 1366 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 390:
#line 1371 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 391:
#line 1376 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 392:
#line 1381 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 393:
#line 1386 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 394:
#line 1391 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 395:
#line 1396 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 396:
#line 1404 "ace.yacc"
    {
		switch ( (yyvsp[(2) - (2)].expr).type) {
			case EXPRTYPE_DOUBLE:
					COPY((yyval.expr),(yyvsp[(2) - (2)].expr)); 
					(yyval.expr).expr_u.d=0.0-(yyval.expr).expr_u.d;
					break;
			case EXPRTYPE_INT:
					COPY((yyval.expr),(yyvsp[(2) - (2)].expr)); 
					(yyval.expr).expr_u.i=0-(yyval.expr).expr_u.i;
					break;
			default : 
					(yyval.expr).type=EXPRTYPE_COMPLEX;
					(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
					set_expr_int(&(yyval.expr).expr_u.expr->expr1, 0);
					COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
					(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
		}
	}
    break;

  case 397:
#line 1424 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 398:
#line 1432 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 399:
#line 1439 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 400:
#line 1448 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 401:
#line 1454 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 402:
#line 1461 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 403:
#line 1469 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 404:
#line 1478 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 405:
#line 1485 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 406:
#line 1492 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 407:
#line 1494 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(2) - (3)].str)); 
	}
    break;

  case 408:
#line 1501 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 409:
#line 1505 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 410:
#line 1509 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 411:
#line 1513 "ace.yacc"
    {
		int v;
		v=find_variable("today");
		(yyval.expr).type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[(1) - (1)].str));
		} 
		(yyval.expr).expr_u.varid=v;
	}
    break;

  case 412:
#line 1522 "ace.yacc"
    {
		int v;
		v=find_variable("time");
		(yyval.expr).type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[(1) - (1)].str));
		} 
		(yyval.expr).expr_u.varid=v;
	}
    break;

  case 413:
#line 1532 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 414:
#line 1539 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 415:
#line 1545 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 416:
#line 1551 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 417:
#line 1558 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 418:
#line 1564 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 419:
#line 1565 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 420:
#line 1571 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 421:
#line 1577 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 422:
#line 1584 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 423:
#line 1590 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 424:
#line 1598 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 425:
#line 1605 "ace.yacc"
    {
		printf("NIY\n");
		sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 426:
#line 1609 "ace.yacc"
    {
		int v;
		v=find_variable((yyvsp[(1) - (1)].str));
		(yyval.expr).type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[(1) - (1)].str));
		} 
		(yyval.expr).expr_u.varid=v;
	}
    break;

  case 427:
#line 1619 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 428:
#line 1625 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc(
			(yyval.expr).expr_u.lexpr->elem.elem_val,
			sizeof(struct expr)*(yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
		print_lexpr((yyval.expr).expr_u.lexpr);
	}
    break;

  case 429:
#line 1636 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 430:
#line 1643 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
	}
    break;

  case 431:
#line 1650 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 432:
#line 1659 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_NULL;
	}
    break;

  case 433:
#line 1665 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 434:
#line 1669 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 435:
#line 1673 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 436:
#line 1677 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4609 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}


#line 1703 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

