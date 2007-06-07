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
     NAME = 258,
     COMMA = 259,
     USING = 260,
     SPACES = 261,
     COLUMN = 262,
     ASCII = 263,
     WHERE = 264,
     KW_OR = 265,
     KW_AND = 266,
     CLIPPED = 267,
     NOT = 268,
     IS_NULL = 269,
     IS_NOT_NULL = 270,
     COMPARISON = 271,
     NOT_EQUAL = 272,
     EQUAL = 273,
     LESS_THAN_EQ = 274,
     LESS_THAN = 275,
     GREATER_THAN_EQ = 276,
     GREATER_THAN = 277,
     NOT_LIKE = 278,
     LIKE = 279,
     NOT_MATCHES = 280,
     MATCHES = 281,
     MINUS = 282,
     PLUS = 283,
     DIVIDE = 284,
     MULTIPLY = 285,
     MOD = 286,
     POW = 287,
     AFTER = 288,
     AFTGROUP = 289,
     ALL = 290,
     ANY = 291,
     ASC = 292,
     ATSIGN = 293,
     AVERAGE = 294,
     AVG = 295,
     BEFORE = 296,
     BETWEEN = 297,
     BOTTOM = 298,
     BY = 299,
     KW_CALL = 300,
     CH = 301,
     CHAR = 302,
     CHAR_VALUE = 303,
     CLOSE_BRACKET = 304,
     CLOSE_SQUARE = 305,
     COLON = 306,
     COMMANDS = 307,
     COUNT = 308,
     DATABASE = 309,
     DATE = 310,
     TIME = 311,
     DATETIME = 312,
     DAY = 313,
     DECIMAL = 314,
     DEFINE = 315,
     DELIMITER = 316,
     DESC = 317,
     DISTINCT = 318,
     DO = 319,
     DOLLAR = 320,
     DOT = 321,
     ELSE = 322,
     END = 323,
     ESCAPE = 324,
     EVERY = 325,
     EXISTS = 326,
     EXTERNAL = 327,
     FIRST = 328,
     FLOAT = 329,
     PIPE = 330,
     FOR = 331,
     FORMAT = 332,
     FRACTION = 333,
     FROM = 334,
     FUNCTION = 335,
     GROUP = 336,
     GROUP_BY = 337,
     HAVING = 338,
     HEADER = 339,
     HOUR = 340,
     IF = 341,
     IN = 342,
     INPUT = 343,
     INTEGER = 344,
     INTERVAL = 345,
     INTO = 346,
     INTVAL = 347,
     KW_FALSE = 348,
     KW_TRUE = 349,
     LAST = 350,
     LEFT = 351,
     LENGTH = 352,
     LET = 353,
     LINES = 354,
     MARGIN = 355,
     MINUTE = 356,
     MONEY = 357,
     MONTH = 358,
     NAMED = 359,
     NEED = 360,
     NOT_EXISTS = 361,
     NOT_IN = 362,
     NUMBER_VALUE = 363,
     NUMERIC = 364,
     KW_OF = 365,
     ON = 366,
     OPEN_BRACKET = 367,
     OPEN_SQUARE = 368,
     ORDER_BY = 369,
     ORDER_EXTERNAL_BY = 370,
     OUTER = 371,
     OUTPUT = 372,
     PAGE = 373,
     PAGE_HEADER = 374,
     PAGE_TRAILER = 375,
     PARAM = 376,
     PAUSE = 377,
     PERCENT = 378,
     PRINT = 379,
     PRINTER = 380,
     PRINT_FILE = 381,
     PROMPT = 382,
     READ = 383,
     REPORT = 384,
     RIGHT = 385,
     ROW = 386,
     SECOND = 387,
     SELECT = 388,
     SEMICOLON = 389,
     SKIP = 390,
     SMALLFLOAT = 391,
     SMALLINT = 392,
     SOME = 393,
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
#define NAME 258
#define COMMA 259
#define USING 260
#define SPACES 261
#define COLUMN 262
#define ASCII 263
#define WHERE 264
#define KW_OR 265
#define KW_AND 266
#define CLIPPED 267
#define NOT 268
#define IS_NULL 269
#define IS_NOT_NULL 270
#define COMPARISON 271
#define NOT_EQUAL 272
#define EQUAL 273
#define LESS_THAN_EQ 274
#define LESS_THAN 275
#define GREATER_THAN_EQ 276
#define GREATER_THAN 277
#define NOT_LIKE 278
#define LIKE 279
#define NOT_MATCHES 280
#define MATCHES 281
#define MINUS 282
#define PLUS 283
#define DIVIDE 284
#define MULTIPLY 285
#define MOD 286
#define POW 287
#define AFTER 288
#define AFTGROUP 289
#define ALL 290
#define ANY 291
#define ASC 292
#define ATSIGN 293
#define AVERAGE 294
#define AVG 295
#define BEFORE 296
#define BETWEEN 297
#define BOTTOM 298
#define BY 299
#define KW_CALL 300
#define CH 301
#define CHAR 302
#define CHAR_VALUE 303
#define CLOSE_BRACKET 304
#define CLOSE_SQUARE 305
#define COLON 306
#define COMMANDS 307
#define COUNT 308
#define DATABASE 309
#define DATE 310
#define TIME 311
#define DATETIME 312
#define DAY 313
#define DECIMAL 314
#define DEFINE 315
#define DELIMITER 316
#define DESC 317
#define DISTINCT 318
#define DO 319
#define DOLLAR 320
#define DOT 321
#define ELSE 322
#define END 323
#define ESCAPE 324
#define EVERY 325
#define EXISTS 326
#define EXTERNAL 327
#define FIRST 328
#define FLOAT 329
#define PIPE 330
#define FOR 331
#define FORMAT 332
#define FRACTION 333
#define FROM 334
#define FUNCTION 335
#define GROUP 336
#define GROUP_BY 337
#define HAVING 338
#define HEADER 339
#define HOUR 340
#define IF 341
#define IN 342
#define INPUT 343
#define INTEGER 344
#define INTERVAL 345
#define INTO 346
#define INTVAL 347
#define KW_FALSE 348
#define KW_TRUE 349
#define LAST 350
#define LEFT 351
#define LENGTH 352
#define LET 353
#define LINES 354
#define MARGIN 355
#define MINUTE 356
#define MONEY 357
#define MONTH 358
#define NAMED 359
#define NEED 360
#define NOT_EXISTS 361
#define NOT_IN 362
#define NUMBER_VALUE 363
#define NUMERIC 364
#define KW_OF 365
#define ON 366
#define OPEN_BRACKET 367
#define OPEN_SQUARE 368
#define ORDER_BY 369
#define ORDER_EXTERNAL_BY 370
#define OUTER 371
#define OUTPUT 372
#define PAGE 373
#define PAGE_HEADER 374
#define PAGE_TRAILER 375
#define PARAM 376
#define PAUSE 377
#define PERCENT 378
#define PRINT 379
#define PRINTER 380
#define PRINT_FILE 381
#define PROMPT 382
#define READ 383
#define REPORT 384
#define RIGHT 385
#define ROW 386
#define SECOND 387
#define SELECT 388
#define SEMICOLON 389
#define SKIP 390
#define SMALLFLOAT 391
#define SMALLINT 392
#define SOME 393
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

void add_fmt (int cat, struct expr *col, struct commands commands);

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
	char   str[30000];
	struct command cmd;
	struct expr expr;
	struct expr *exprptr;
	struct commands commands;
	struct agg_val agg_val;
	struct var_usage *var_usage;
}
/* Line 187 of yacc.c.  */
#line 513 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 526 "y.tab.c"

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
#define YYLAST   3275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  166
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  126
/* YYNRULES -- Number of rules.  */
#define YYNRULES  445
/* YYNRULES -- Number of states.  */
#define YYNSTATES  743

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
     428,   434,   438,   444,   448,   450,   454,   455,   457,   461,
     465,   469,   473,   480,   482,   484,   486,   488,   490,   492,
     494,   496,   498,   500,   502,   504,   506,   508,   510,   511,
     513,   515,   517,   519,   521,   525,   529,   531,   533,   534,
     538,   544,   547,   552,   556,   558,   560,   563,   564,   571,
     573,   579,   580,   584,   586,   591,   597,   598,   600,   602,
     609,   610,   612,   614,   616,   618,   622,   624,   627,   629,
     631,   633,   635,   637,   639,   641,   644,   646,   648,   653,
     660,   667,   676,   679,   683,   687,   689,   691,   693,   695,
     699,   704,   709,   714,   719,   724,   730,   736,   742,   748,
     754,   757,   760,   763,   765,   768,   771,   774,   777,   778,
     780,   782,   784,   788,   790,   792,   795,   797,   799,   801,
     803,   805,   807,   809,   811,   813,   815,   819,   825,   827,
     829,   831,   833,   835,   845,   846,   849,   855,   856,   859,
     864,   872,   882,   883,   885,   887,   891,   895,   898,   902,
     903,   905,   908,   912,   916,   921,   923,   925,   927,   929,
     931,   933,   935,   937,   939,   941,   943,   945,   947,   949,
     951,   953,   955,   957,   959,   961,   963,   965,   967,   969,
     971,   973,   975,   977,   979,   981,   983,   985,   987,   989,
     991,   993,   995,   997,   999,  1001,  1003,  1005,  1007,  1009,
    1011,  1013,  1015,  1017,  1019,  1021,  1023,  1025,  1027,  1029,
    1031,  1033,  1035,  1037,  1039,  1041,  1043,  1045,  1047,  1049,
    1051,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,  1069,
    1071,  1073,  1075,  1077,  1079,  1081,  1083,  1085,  1086,  1089,
    1092,  1095,  1097,  1099,  1102,  1105,  1108,  1111,  1114,  1117,
    1120,  1124,  1128,  1132,  1136,  1140,  1143,  1145,  1147,  1149,
    1151,  1153,  1155,  1160,  1165,  1170,  1175,  1180,  1184,  1187,
    1190,  1192,  1194,  1197,  1200,  1203,  1206,  1209,  1212,  1215,
    1218,  1221,  1224,  1227,  1230,  1233,  1236,  1239,  1242,  1245,
    1248,  1251,  1254,  1257,  1259,  1261,  1263,  1265,  1267,  1269,
    1271,  1275,  1276,  1278,  1280,  1282
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,   168,   169,   177,   181,   185,   189,    -1,
      54,     8,    68,    -1,    54,   104,    68,    -1,    -1,   170,
      -1,    60,   171,    68,    -1,   172,    -1,   171,   172,    -1,
       8,   174,    -1,   159,   175,   176,    -1,   121,   113,   278,
      50,   175,   176,    -1,    80,   173,    -1,   104,    -1,   175,
     176,    -1,   174,     4,   175,   176,    -1,   104,    -1,    80,
      -1,    89,    -1,    47,    -1,    47,   112,   278,    49,    -1,
     158,    -1,   158,   112,   278,    49,    -1,    55,    -1,    74,
      -1,   136,    -1,   137,    -1,    57,    -1,    90,    -1,   102,
      -1,   102,   112,   278,    49,    -1,   102,   112,   278,     4,
     278,    49,    -1,    59,    -1,    59,   112,   278,    49,    -1,
      59,   112,   278,     4,   278,    49,    -1,    -1,   178,    -1,
      88,   179,    68,    -1,   180,    -1,   179,   180,    -1,   127,
      76,   175,     5,   279,    -1,    -1,   182,    -1,   117,   183,
      68,    -1,   184,    -1,   183,   184,    -1,   129,   143,   125,
     279,    -1,   129,   143,   125,    -1,   129,   143,   279,    -1,
     129,   143,    75,   279,    -1,    96,   100,   278,    -1,    43,
     100,   278,    -1,   144,   100,   278,    -1,   118,    97,   278,
      -1,   130,   100,   278,    -1,   145,   279,    -1,   187,    68,
      -1,   186,    68,    -1,   241,    -1,   186,   134,   241,    -1,
     128,   279,   188,   195,    -1,    -1,    61,   279,    -1,    77,
      70,   131,    68,    -1,    77,   191,   190,    -1,    -1,    68,
      -1,   192,    -1,   191,   192,    -1,    73,   118,    84,   260,
      -1,   118,   147,   260,    -1,   118,    84,   260,    -1,   111,
      70,   131,   260,    -1,   111,    95,   131,   260,    -1,    41,
      81,   110,   194,   260,    -1,    33,    81,   110,   194,   260,
      -1,   104,   113,   286,     4,   286,    50,    -1,   104,   113,
     286,    50,    -1,   104,    -1,   193,    -1,    92,    -1,    -1,
     196,    -1,    -1,   114,   197,   201,    -1,   115,   201,    -1,
      48,    -1,   109,    -1,   240,    -1,    92,    -1,    -1,   114,
     200,   201,    -1,   202,    -1,   201,     4,   202,    -1,   203,
     204,    -1,    92,    -1,   238,    -1,    -1,    37,    -1,    62,
      -1,    83,   218,    -1,    82,   207,    -1,   252,    -1,   207,
       4,   252,    -1,     9,   218,    -1,    79,   210,    -1,   211,
      -1,   210,     4,   211,    -1,   212,    -1,   116,   212,    -1,
     116,   112,   213,    49,    -1,   234,    -1,   234,   239,    -1,
     211,    -1,   213,     4,   211,    -1,   209,   215,   216,   217,
      -1,    -1,   208,    -1,    -1,   206,    -1,    -1,   205,    -1,
     219,    -1,   218,    10,   219,    -1,   220,    -1,   219,    11,
     220,    -1,   221,    -1,    13,   221,    -1,   232,    -1,   112,
     218,    49,    -1,    71,   248,    -1,   106,   248,    -1,   254,
     231,   224,   248,    -1,   248,   231,   254,    -1,   225,    -1,
     226,    -1,    35,    -1,   138,    -1,    36,    -1,   254,    87,
     112,   228,    49,    -1,   254,    87,   248,    -1,   254,   107,
     112,   228,    49,    -1,   254,   107,   248,    -1,   259,    -1,
     228,     4,   259,    -1,    -1,    13,    -1,   254,   229,    14,
      -1,   254,   229,    15,    -1,   254,   231,   254,    -1,   254,
     231,   248,    -1,   254,   229,    42,   254,    11,   254,    -1,
      18,    -1,    16,    -1,    17,    -1,    20,    -1,    22,    -1,
      25,    -1,    23,    -1,    26,    -1,    24,    -1,    19,    -1,
      21,    -1,   230,    -1,   227,    -1,   223,    -1,   222,    -1,
      -1,    35,    -1,    63,    -1,   149,    -1,    48,    -1,   236,
      -1,   235,    51,   236,    -1,    48,    66,   236,    -1,   280,
      -1,   280,    -1,    -1,   113,    92,    50,    -1,   113,    92,
       4,    92,    50,    -1,   280,   237,    -1,   234,    66,   280,
     237,    -1,   234,    66,    30,    -1,   280,    -1,   108,    -1,
      66,    92,    -1,    -1,   133,   242,   249,   250,   214,   245,
      -1,   244,    -1,   133,   249,   250,   214,   245,    -1,    -1,
     148,   233,   243,    -1,   199,    -1,    91,   141,   247,   246,
      -1,   199,    91,   141,   247,   246,    -1,    -1,   161,    -1,
     280,    -1,   112,   133,   249,   250,   214,    49,    -1,    -1,
      35,    -1,    63,    -1,   149,    -1,   251,    -1,   250,     4,
     251,    -1,   254,    -1,   254,   104,    -1,   254,    -1,   155,
      -1,   153,    -1,   150,    -1,   151,    -1,   152,    -1,   154,
      -1,   254,   255,    -1,   198,    -1,   280,    -1,   280,   113,
     278,    50,    -1,   280,   113,   278,     4,   278,    50,    -1,
     280,    66,   280,   113,   278,    50,    -1,   280,    66,   280,
     113,   278,     4,   278,    50,    -1,    65,   280,    -1,   280,
      66,   280,    -1,   280,    66,    30,    -1,    94,    -1,    93,
      -1,   157,    -1,    30,    -1,   112,   254,    49,    -1,    55,
     112,   258,    49,    -1,    58,   112,   258,    49,    -1,   103,
     112,   258,    49,    -1,   165,   112,   258,    49,    -1,   280,
     112,   258,    49,    -1,    40,   112,   233,   254,    49,    -1,
     163,   112,   233,   254,    49,    -1,   164,   112,   233,   254,
      49,    -1,   140,   112,   233,   254,    49,    -1,    53,   112,
     233,   254,    49,    -1,    29,   256,    -1,    31,   256,    -1,
      32,   256,    -1,   253,    -1,    30,   256,    -1,    28,   256,
      -1,    27,   256,    -1,   257,   254,    -1,    -1,    28,    -1,
      27,    -1,   254,    -1,   258,     4,   254,    -1,   198,    -1,
     261,    -1,   260,   261,    -1,   264,    -1,   266,    -1,   277,
      -1,   268,    -1,   271,    -1,   272,    -1,   276,    -1,   273,
      -1,   275,    -1,   262,    -1,   162,   260,    68,    -1,    45,
     263,   112,   288,    49,    -1,    55,    -1,   103,    -1,   165,
      -1,    58,    -1,   280,    -1,    76,   175,    18,   286,   143,
     286,   265,    64,   261,    -1,    -1,   139,   286,    -1,    86,
     286,   142,   261,   267,    -1,    -1,    67,   261,    -1,    98,
     104,    18,   270,    -1,    98,   104,   113,   286,    50,    18,
     270,    -1,    98,   104,   113,   286,     4,   286,    50,    18,
     270,    -1,    -1,   270,    -1,   286,    -1,   270,     4,   286,
      -1,   105,   278,    99,    -1,   122,   279,    -1,   124,   269,
     274,    -1,    -1,   134,    -1,   126,   279,    -1,   135,   278,
      99,    -1,   135,   143,   145,    -1,   160,   286,    64,   261,
      -1,    92,    -1,    48,    -1,   104,    -1,   281,    -1,    33,
      -1,    37,    -1,    34,    -1,    41,    -1,    42,    -1,    43,
      -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,    12,
      -1,     7,    -1,    52,    -1,    16,    -1,    54,    -1,    57,
      -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,    64,
      -1,    67,    -1,    69,    -1,    70,    -1,    72,    -1,    73,
      -1,    74,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    95,    -1,    96,    -1,    97,
      -1,    98,    -1,    24,    -1,    99,    -1,   100,    -1,   101,
      -1,   102,    -1,   105,    -1,   110,    -1,   111,    -1,   117,
      -1,   118,    -1,   121,    -1,   122,    -1,    32,    -1,   125,
      -1,   127,    -1,   128,    -1,   129,    -1,   130,    -1,   131,
      -1,   132,    -1,   135,    -1,   136,    -1,   137,    -1,     6,
      -1,   139,    -1,   141,    -1,   142,    -1,   143,    -1,   144,
      -1,   146,    -1,   147,    -1,   156,    -1,   158,    -1,   159,
      -1,   160,    -1,   162,    -1,    -1,     9,   286,    -1,   285,
     282,    -1,   110,   286,    -1,    53,    -1,   123,    -1,    39,
     284,    -1,   146,   284,    -1,    40,   284,    -1,   164,   284,
      -1,   163,   284,    -1,    81,    53,    -1,    81,   123,    -1,
      81,    39,   284,    -1,    81,   146,   284,    -1,    81,    40,
     284,    -1,    81,   164,   284,    -1,    81,   163,   284,    -1,
      27,   286,    -1,   291,    -1,    94,    -1,    93,    -1,   157,
      -1,    55,    -1,    56,    -1,    55,   112,   289,    49,    -1,
     103,   112,   289,    49,    -1,   165,   112,   289,    49,    -1,
      58,   112,   289,    49,    -1,   104,   112,   289,    49,    -1,
     112,   286,    49,    -1,     7,   286,    -1,     8,   286,    -1,
     193,    -1,   283,    -1,   286,   287,    -1,    11,   286,    -1,
      10,   286,    -1,    29,   286,    -1,    32,   286,    -1,    31,
     286,    -1,    30,   286,    -1,    28,   286,    -1,    27,   286,
      -1,     5,   286,    -1,    18,   286,    -1,    16,   286,    -1,
      17,   286,    -1,    20,   286,    -1,    22,   286,    -1,    25,
     286,    -1,    23,   286,    -1,    26,   286,    -1,    24,   286,
      -1,    19,   286,    -1,    21,   286,    -1,     6,    -1,    14,
      -1,    15,    -1,    12,    -1,   290,    -1,   289,    -1,   286,
      -1,   289,     4,   286,    -1,    -1,    48,    -1,   109,    -1,
     240,    -1,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   237,   237,   245,   248,   257,   259,   264,   268,   268,
     272,   276,   279,   282,   287,   290,   290,   293,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   325,   326,   329,   333,
     333,   336,   341,   341,   344,   347,   347,   351,   352,   353,
     354,   355,   358,   361,   364,   367,   370,   377,   377,   381,
     382,   386,   389,   389,   393,   399,   403,   403,   407,   407,
     411,   415,   419,   423,   427,   430,   433,   440,   450,   460,
     475,   479,   487,   487,   490,   490,   493,   503,   506,   507,
     508,   513,   513,   517,   518,   523,   529,   534,   541,   542,
     543,   548,   554,   559,   560,   566,   571,   575,   576,   581,
     582,   583,   586,   587,   595,   595,   599,   610,   611,   614,
     615,   618,   619,   624,   625,   630,   631,   636,   637,   642,
     643,   649,   650,   655,   657,   664,   665,   668,   672,   673,
     695,   697,   699,   701,   707,   708,   712,   713,   718,   720,
     722,   724,   726,   732,   733,   734,   735,   736,   737,   738,
     739,   740,   741,   742,   747,   748,   749,   750,   752,   753,
     754,   755,   766,   767,   768,   769,   775,   779,   783,   784,
     785,   788,   789,   790,   796,   801,   801,   816,   816,   834,
     837,   844,   845,   848,   849,   853,   861,   861,   865,   882,
     886,   887,   888,   889,   893,   894,   898,   901,   908,   912,
     913,   914,   915,   916,   917,   921,   922,   923,   924,   925,
     926,   927,   928,   932,   934,   936,   937,   938,   939,   940,
     941,   942,   943,   944,   945,   947,   949,   951,   953,   955,
     960,   961,   962,   963,   964,   965,   966,   969,   972,   973,
     974,   978,   978,   985,   997,  1002,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1061,  1072,  1073,
    1074,  1075,  1076,  1079,  1088,  1089,  1093,  1101,  1104,  1109,
    1120,  1131,  1144,  1148,  1151,  1151,  1163,  1169,  1176,  1184,
    1184,  1187,  1193,  1198,  1205,  1214,  1217,  1221,  1222,  1227,
    1229,  1230,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1313,  1316,  1323,
    1332,  1338,  1344,  1350,  1356,  1362,  1368,  1374,  1381,  1387,
    1393,  1399,  1405,  1411,  1417,  1426,  1444,  1446,  1450,  1454,
    1458,  1467,  1477,  1484,  1490,  1496,  1503,  1509,  1510,  1516,
    1522,  1527,  1532,  1555,  1563,  1570,  1578,  1585,  1594,  1601,
    1610,  1617,  1625,  1631,  1637,  1643,  1649,  1655,  1661,  1667,
    1673,  1679,  1685,  1693,  1700,  1706,  1714,  1747,  1758,  1765,
    1772,  1781,  1787,  1791,  1795,  1799
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "COMMA", "USING", "SPACES",
  "COLUMN", "ASCII", "WHERE", "KW_OR", "KW_AND", "CLIPPED", "NOT",
  "IS_NULL", "IS_NOT_NULL", "COMPARISON", "NOT_EQUAL", "EQUAL",
  "LESS_THAN_EQ", "LESS_THAN", "GREATER_THAN_EQ", "GREATER_THAN",
  "NOT_LIKE", "LIKE", "NOT_MATCHES", "MATCHES", "MINUS", "PLUS", "DIVIDE",
  "MULTIPLY", "MOD", "POW", "AFTER", "AFTGROUP", "ALL", "ANY", "ASC",
  "ATSIGN", "AVERAGE", "AVG", "BEFORE", "BETWEEN", "BOTTOM", "BY",
  "KW_CALL", "CH", "CHAR", "CHAR_VALUE", "CLOSE_BRACKET", "CLOSE_SQUARE",
  "COLON", "COMMANDS", "COUNT", "DATABASE", "DATE", "TIME", "DATETIME",
  "DAY", "DECIMAL", "DEFINE", "DELIMITER", "DESC", "DISTINCT", "DO",
  "DOLLAR", "DOT", "ELSE", "END", "ESCAPE", "EVERY", "EXISTS", "EXTERNAL",
  "FIRST", "FLOAT", "PIPE", "FOR", "FORMAT", "FRACTION", "FROM",
  "FUNCTION", "GROUP", "GROUP_BY", "HAVING", "HEADER", "HOUR", "IF", "IN",
  "INPUT", "INTEGER", "INTERVAL", "INTO", "INTVAL", "KW_FALSE", "KW_TRUE",
  "LAST", "LEFT", "LENGTH", "LET", "LINES", "MARGIN", "MINUTE", "MONEY",
  "MONTH", "NAMED", "NEED", "NOT_EXISTS", "NOT_IN", "NUMBER_VALUE",
  "NUMERIC", "KW_OF", "ON", "OPEN_BRACKET", "OPEN_SQUARE", "ORDER_BY",
  "ORDER_EXTERNAL_BY", "OUTER", "OUTPUT", "PAGE", "PAGE_HEADER",
  "PAGE_TRAILER", "PARAM", "PAUSE", "PERCENT", "PRINT", "PRINTER",
  "PRINT_FILE", "PROMPT", "READ", "REPORT", "RIGHT", "ROW", "SECOND",
  "SELECT", "SEMICOLON", "SKIP", "SMALLFLOAT", "SMALLINT", "SOME", "STEP",
  "SUM", "TEMP", "THEN", "TO", "TOP", "TOP_OF_PAGE", "TOTAL", "TRAILER",
  "UNION", "UNIQUE", "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE",
  "UNITS_MONTH", "UNITS_SECOND", "UNITS_YEAR", "UPDATE", "USER", "VARCHAR",
  "VARIABLE", "WHILE", "WITH_NO_LOG", "XBEGIN", "XMAX", "XMIN", "YEAR",
  "$accept", "ace_report", "db_section", "op_define_section",
  "define_section", "define_element_list", "define_element", "ufunc_name",
  "def_ascii_list", "variable", "datatype", "op_input_section",
  "input_section", "prompt_section", "prompt_element", "op_output_section",
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
  "quantifier", "all", "some", "in_predicate", "in_value_list", "op_not",
  "comparison_predicate", "comp_op_sql", "predicate", "op_all",
  "table_name", "db_name", "table_identifier", "col_arr", "column_name",
  "correlation_name", "real_number", "select_statement", "@3",
  "select_statement2", "select_statement2_1", "sel_p2", "op_no_log",
  "tmp_tabname", "subquery", "op_ad", "sq_select_list",
  "value_expression_pls", "column_specification", "units_qual",
  "sql_value_expression", "sql_val_expr_next", "sql_value_expression_s",
  "op_prefix", "sql_value_expr_list", "value_specification", "commands",
  "command", "call_command", "func_identifier", "for_command", "op_step",
  "if_command", "op_else", "let_command", "op_expr_concat", "expr_concat",
  "need_command", "pause_command", "print_command", "op_semi",
  "print_file_command", "skip_command", "while_command", "int_val",
  "string", "identifier", "reserved_word", "op_where_agg", "aggregate",
  "of_expr", "aggregate_elem", "fmt_val_expression", "val_next",
  "op_fmt_val_expr_list", "fmt_val_expr_list", "null_expr", "literal_expr", 0
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
     227,   227,   227,   227,   228,   228,   229,   229,   230,   230,
     230,   230,   230,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   232,   232,   232,   232,   233,   233,
     233,   233,   234,   234,   234,   234,   235,   236,   237,   237,
     237,   238,   238,   238,   239,   240,   240,   242,   241,   243,
     244,   245,   245,   245,   245,   245,   246,   246,   247,   248,
     249,   249,   249,   249,   250,   250,   251,   251,   252,   253,
     253,   253,   253,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     255,   255,   255,   255,   255,   255,   255,   256,   257,   257,
     257,   258,   258,   259,   260,   260,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   262,   263,   263,
     263,   263,   263,   264,   265,   265,   266,   267,   267,   268,
     268,   268,   269,   269,   270,   270,   271,   272,   273,   274,
     274,   275,   276,   276,   277,   278,   279,   280,   280,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   282,   282,   283,
     284,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   288,   288,   289,
     289,   290,   291,   291,   291,   291
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
       5,     3,     5,     3,     1,     3,     0,     1,     3,     3,
       3,     3,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     0,     3,
       5,     2,     4,     3,     1,     1,     2,     0,     6,     1,
       5,     0,     3,     1,     4,     5,     0,     1,     1,     6,
       0,     1,     1,     1,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     4,     6,
       6,     8,     2,     3,     3,     1,     1,     1,     1,     3,
       4,     4,     4,     4,     4,     5,     5,     5,     5,     5,
       2,     2,     2,     1,     2,     2,     2,     2,     0,     1,
       1,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     5,     1,     1,
       1,     1,     1,     9,     0,     2,     5,     0,     2,     4,
       7,     9,     0,     1,     1,     3,     3,     2,     3,     0,
       1,     2,     3,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     2,
       2,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     3,     2,     2,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1
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
     295,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,   187,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   296,    56,    44,    46,    62,   200,
       0,     2,    58,     0,    57,    16,     0,     0,     0,     0,
       0,     0,    52,    51,    54,     0,    48,    49,    55,    53,
       0,    82,   201,   202,   203,     0,     0,     0,     0,     0,
       0,     0,    66,    68,    60,    21,     0,    34,     0,    31,
      23,    12,    41,    50,    47,    63,    84,     0,    61,    83,
     364,   310,   309,   312,   341,   228,   353,   299,   301,   300,
       0,   302,   303,   304,   305,   306,   307,   308,    87,   311,
       0,   313,     0,   314,     0,   315,   316,   317,   318,   319,
       0,     0,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,    90,
     226,   225,   337,   338,   339,   340,   342,   343,   344,   345,
       0,   297,   346,   185,    88,   347,   348,     0,   349,   350,
     351,   352,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   365,     0,   366,   367,   368,   369,   370,   371,
     372,   227,   373,   374,   375,   376,     0,     0,     0,   216,
      89,     0,   204,   206,   217,   298,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    65,    69,     0,     0,     0,
     172,    96,    86,    93,    98,     0,     0,   173,    97,   178,
     168,   168,     0,     0,   222,   186,     0,     0,   168,   168,
     168,     0,     0,     0,   117,   191,   248,   248,   248,   248,
     248,   248,   207,   211,   212,   213,   210,   214,   209,   243,
     215,     0,     0,     0,     0,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,     0,     0,
       0,    72,   254,   265,   256,   257,   259,   260,   261,   263,
     264,   262,   258,    71,    35,    32,    85,     0,     0,    99,
     100,    95,     0,     0,     0,   181,   169,   170,   171,     0,
       0,   251,     0,     0,     0,   229,     0,     0,     0,     0,
     205,     0,   106,   107,   109,   112,   177,     0,   118,   119,
       0,    91,   168,   193,   188,   250,   249,   246,     0,   245,
     240,   244,   241,   242,   224,   223,     0,     0,    81,    79,
      80,     0,     0,    70,    73,    74,   268,   271,   269,   270,
       0,   272,     0,     0,     0,     0,     0,     0,   442,   381,
     400,   401,     0,     0,   445,   398,   397,     0,    79,   443,
       0,   382,     0,   399,     0,     0,     0,   410,   444,   411,
     377,     0,   396,     0,     0,   287,   289,   283,   284,   291,
       0,     0,     0,     0,   255,   175,   177,    94,   183,   178,
     174,     0,     0,     0,     0,   230,   231,   232,     0,     0,
       0,   233,     0,   110,     0,   113,   184,     0,     0,     0,
       0,   105,   123,   125,   127,   167,   166,   165,   164,   129,
       0,   146,     0,   120,   121,     0,     0,     0,     0,   247,
       0,   234,     0,   218,     0,    76,    75,   441,     0,   408,
     409,   395,     0,   383,   385,     0,     0,     0,     0,   388,
     389,     0,     0,     0,     0,     0,     0,   384,   387,   386,
       0,     0,   379,     0,   433,     0,     0,   436,   434,   435,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   412,     0,
       0,   286,   290,   288,     0,   293,   292,     0,   266,   182,
       0,   179,   235,   239,   252,   238,   236,   237,   114,     0,
     108,   128,     0,   131,   132,   200,     0,   146,     0,     0,
     154,   155,   153,   162,   156,   163,   157,   159,   161,   158,
     160,     0,   147,     0,     0,     0,     0,   102,   103,   208,
       0,   122,   116,   196,   198,    92,   200,   192,   189,     0,
       0,     0,     0,   439,     0,   438,   437,     0,   380,     0,
       0,   390,   392,   391,   394,   393,     0,     0,   407,     0,
     378,   421,   414,   413,   423,   424,   422,   431,   425,   432,
     426,   428,   430,   427,   429,   420,   419,   415,   418,   417,
     416,   277,   279,     0,   285,   294,     0,     0,   111,     0,
     130,   124,   126,   134,     0,   141,     0,   143,   148,   149,
       0,   137,   139,     0,   138,     0,   135,   136,   151,   150,
       0,   101,   197,   194,     0,   196,     0,   220,   219,     0,
      78,   267,     0,     0,   402,   405,   403,   406,   404,     0,
     276,     0,     0,   180,   115,     0,   253,     0,   144,     0,
       0,   133,   104,     0,   195,     0,     0,   440,   274,   278,
       0,     0,     0,     0,   140,   142,     0,   191,   221,    77,
       0,     0,     0,   280,   199,   145,   152,   190,   275,     0,
       0,   273,   281
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   255,   122,   123,   427,   391,   138,
     139,   259,   239,   373,   486,   262,   263,   264,   341,   601,
     483,   597,   368,   284,   362,   363,   364,   569,   285,   369,
     484,   602,   471,   472,   473,   474,   475,   476,   675,   676,
     677,   477,   707,   595,   478,   596,   479,   349,   365,   266,
     267,   345,   268,   465,   428,    70,    89,   607,   608,   374,
     683,   603,   480,   115,   241,   242,   598,   299,   351,   300,
     377,   378,   352,   708,   321,   322,   323,   400,   324,   731,
     325,   700,   326,   436,   437,   327,   328,   329,   553,   330,
     331,   332,    51,    85,   244,   245,   522,   429,   503,   430,
     613,   548,   614,   615,   616,   432
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -637
static const yytype_int16 yypact[] =
{
       4,    17,   119,    85,   113,   121,  -637,    14,    95,  -637,
    -637,  -637,    89,   103,   102,    89,    10,  -637,   110,   118,
    -637,  -637,   264,  2828,  -637,  -637,   186,  2828,  -637,  -637,
     198,     5,  -637,   170,   -80,  -637,    89,   175,  -637,  -637,
     177,  -637,  -637,  -637,  -637,   181,  -637,  -637,   192,  -637,
    -637,   258,  -637,    89,  -637,  -637,   223,   230,   249,   206,
     247,   250,   303,    -7,  -637,   303,  -637,   286,   -24,   297,
    -637,  2828,   186,   186,   186,   186,    89,   361,   186,   186,
     186,    -8,   186,   186,  -637,  -637,  -637,  -637,   308,    -3,
     115,  -637,  -637,   235,  -637,  -637,   321,    46,    51,   322,
    2828,   303,  -637,  -637,  -637,   303,   303,  -637,  -637,  -637,
     303,   182,  -637,  -637,  -637,  1403,   291,   292,   244,   256,
     160,   -43,   106,  -637,  -637,  -637,   186,  -637,   186,  -637,
    -637,  -637,  -637,  -637,  -637,  -637,  -637,  1839,  -637,  -637,
    -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
     266,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
     267,  -637,   269,  -637,   270,  -637,  -637,  -637,  -637,  -637,
    2564,   293,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
    -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
    -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
     272,  -637,  -637,  -637,  -637,  -637,  -637,  1403,  -637,  -637,
    -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
    -637,  -637,  -637,   274,  -637,  -637,  -637,  -637,  -637,  -637,
    -637,  -637,  -637,  -637,  -637,  -637,   275,   276,   277,  -637,
    -637,    23,  -637,   307,    59,  -637,   281,   282,   325,   310,
     268,   271,  1697,  1697,  -637,  -637,  -637,   348,   349,  1839,
     335,  -637,   399,  -637,     9,   339,   355,  -637,  -637,    -4,
       3,     3,  1403,  1403,  -637,  -637,  1403,   313,     3,     3,
       3,  1403,  1403,  1984,   398,   -49,   285,   285,   285,   285,
     285,   285,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
    -637,  2274,  1403,   186,   -16,   -16,  -637,  1697,  1697,  1697,
    1563,    89,  1704,   304,   186,   303,  1704,   303,   -47,  1704,
    1697,  1697,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
    -637,  -637,  -637,  1697,  -637,  -637,   399,  2564,  1839,  -637,
    -637,  -637,  2419,  2564,   317,  -637,  -637,  -637,  -637,  1403,
    1403,  1625,   145,   151,   174,  -637,  1403,  1403,  1403,   176,
    -637,  2129,   406,  -637,  -637,  2564,   362,   763,  -637,   330,
     273,  -637,     3,   324,  -637,  -637,  -637,  -637,  1403,  -637,
    -637,  -637,  -637,  -637,  -637,   306,   178,    53,  -637,   309,
    -637,  1697,  1697,  1697,  1697,  1697,  -637,  -637,  -637,  -637,
     305,  -637,   403,  1704,  1704,  1704,   314,   314,  -637,  -637,
     319,  -637,   337,   -10,  -637,  -637,  -637,   338,   213,  -637,
    1704,  -637,   314,  -637,   314,   314,   341,  -637,  -637,  -637,
     407,  2786,  -637,    15,   327,  -637,   295,   450,  3177,  -637,
     326,   356,  2921,  1696,  -637,  -637,  -637,  -637,  -637,   357,
    -637,    83,   328,  1686,  1403,  -637,  -637,  -637,  2563,  2827,
    2841,  -637,  1984,  -637,  1984,  -637,  -637,  1083,   363,   363,
     603,   459,   463,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
    2729,  2746,  1403,  -637,   394,  2564,  1839,   351,   345,  1625,
     186,  -637,   186,  -637,  1704,  1697,  1697,  1704,  1704,  3177,
    3177,   227,  1704,  -637,  -637,  1704,  1704,   314,   314,  -637,
    -637,   314,   314,   314,  1704,  1704,  3141,  -637,  -637,  -637,
    1704,  1704,  -637,  1704,  -637,  1704,  1704,  -637,  -637,  -637,
    1704,  1704,  1704,  1704,  1704,  1704,  1704,  1704,  1704,  1704,
    1704,  1704,  1704,  1704,  1704,  1704,  1704,  1697,  -637,  1704,
    1704,  -637,  -637,  -637,  1704,  -637,  -637,  1697,  -637,  -637,
     395,  -637,  -637,  -637,  1625,  -637,  -637,  -637,  -637,   180,
    -637,  -637,   360,  -637,  -637,    -3,   108,  2712,   763,   763,
    -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,  -637,
    -637,  1403,  -637,   376,   377,   225,   923,   491,  -637,  1625,
     763,  -637,  -637,   336,  -637,   399,    -3,  -637,  -637,  2564,
     140,   446,  2993,  3177,   449,   495,  -637,   511,  3177,   187,
     204,  -637,  -637,  -637,  -637,  -637,   215,   216,  -637,   241,
    3200,  3177,  3222,  3243,  2756,  2756,  2756,  2756,  2756,  2756,
    2756,  2756,  2756,  2756,  2756,   227,   227,   296,   296,  -637,
    -637,   433,   450,  3030,  3177,  -637,   451,  1984,  -637,  1403,
    -637,   463,  -637,  1625,   -17,  -637,   -17,  -637,  -637,  -637,
    1403,  -637,  -637,  1243,  -637,   363,  -637,  -637,  -637,  1625,
    1403,   459,  -637,  -637,  1403,   336,   186,  -637,  -637,  1704,
    -637,  -637,  1704,  1704,  -637,  -637,  -637,  -637,  -637,  1697,
    -637,  1704,   484,  -637,  -637,    23,  -637,   243,  -637,   245,
     131,  -637,  -637,    23,  -637,   453,  3067,  3177,  2820,  -637,
    3104,  1704,   456,   168,  -637,  -637,  1403,   -49,  -637,  -637,
    1704,   442,   489,   450,  -637,  -637,  1625,  -637,  3177,  1697,
    1704,  -637,   450
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -637,  -637,  -637,  -637,  -637,  -637,   492,  -637,  -637,    -2,
       8,  -637,  -637,  -637,   479,  -637,  -637,  -637,   448,  -637,
    -637,  -637,  -637,  -637,  -637,  -637,   390,    28,   209,  -637,
    -637,  -637,  -594,  -637,  -637,  -245,   207,  -637,  -637,  -637,
    -637,  -637,  -637,  -637,  -637,  -445,   154,  -637,  -636,  -637,
    -637,  -637,  -449,   -60,   -59,    52,  -637,  -637,  -637,  -637,
    -637,  -637,  -122,  -637,  -637,    66,  -637,  -173,  -132,  -637,
    -213,    98,  -637,  -637,  -106,   455,  -637,  -637,  -637,  -178,
    -135,   -58,  -453,  -523,  -405,   279,  -128,  -637,   -87,  -637,
      30,  -637,    22,  -169,  -227,  -309,  -637,  -637,  -637,  -637,
    -637,  -637,  -637,  -637,  -529,  -637,  -637,  -637,  -637,  -637,
    -637,  -637,   -72,   -42,  -133,  -637,  -637,  -637,  -310,  -637,
     -98,  -637,  -637,  -204,  -637,  -637
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -178
static const yytype_int16 yytable[] =
{
      96,    97,    98,    99,   269,   265,   102,   103,   104,   240,
     108,   109,   444,    27,   336,   573,   574,   568,    12,   570,
     652,   576,    12,    88,   444,     4,   333,   282,   243,   507,
     508,   158,   112,   549,    71,    52,    56,   274,   346,   107,
      84,   252,   370,   509,    92,    50,   339,  -176,    65,   171,
     126,    77,   659,    66,   257,   128,   258,   492,     1,   132,
     113,    86,  -177,   133,   134,   371,   347,   105,   135,   722,
     706,   340,   706,    54,   100,   189,   388,   727,    28,    95,
     393,   394,   395,   684,   444,   444,   444,   560,   389,    57,
      13,   203,   204,   443,    13,   127,   440,   504,   350,   372,
     129,   240,   283,   493,   253,   356,   357,   358,   131,   344,
      93,    58,   517,   510,   518,   519,   575,   106,   578,     6,
     277,     5,    59,    60,   445,   301,   269,   265,   550,   706,
     450,    14,    30,   561,   444,    14,   511,    61,    62,   116,
     665,   667,   726,   678,   686,     7,   114,   117,   116,   454,
     366,   681,   348,   512,   513,   454,   117,   660,   286,   287,
     288,   289,   290,   291,   495,   496,   240,   240,   385,    15,
     240,   302,   303,    15,   254,   240,   240,   401,   454,   119,
     454,    10,   454,    18,   657,   118,   444,   444,   119,    11,
     687,   692,   733,    21,   455,   243,   240,   621,   622,   487,
     456,   623,   624,   625,   446,   269,   265,    24,   692,   449,
     446,   742,   704,    56,   431,    26,   158,   120,   438,   692,
     692,   442,   711,   457,   121,   461,   120,   491,   366,   658,
     250,   387,   466,   121,   171,    33,   694,    30,   651,   668,
     669,   605,   434,   240,   240,   692,   441,   723,   655,   723,
     240,   240,   240,   695,   705,   251,   543,   544,   545,   546,
     189,   240,   452,   453,   696,   697,    57,   670,    36,   458,
     459,   460,   240,   435,    53,   439,   203,   204,    50,   713,
     481,   293,   294,   295,   296,   297,   298,    72,    58,    73,
     698,   489,   724,    74,   725,   353,   136,   137,   354,    59,
      60,   619,   620,   359,    75,   499,   500,   501,    76,   402,
     626,   627,   375,   376,    61,    62,   629,   379,   380,   381,
     382,   383,   516,    78,   386,   515,   494,   545,   546,   366,
      79,   366,   390,   390,   286,   287,   288,   289,   290,   291,
     286,   287,   288,   289,   290,   291,    80,    82,   240,    81,
      83,    84,   604,   269,   265,   286,   287,   288,   289,   290,
     291,   240,   355,    90,   240,    94,   101,   564,    66,   110,
     125,   130,   246,   247,   249,   248,   240,   562,   270,   271,
     481,   272,   273,   577,   276,   275,   278,   279,   280,   281,
     719,   304,   305,   306,   307,   599,   612,   334,   335,   308,
     617,   337,   309,   338,   618,   342,   343,   367,   433,   451,
     464,   292,   482,  -176,   485,   488,   521,   497,   610,   490,
     611,   498,   494,   630,   502,   631,   551,   632,   633,   552,
     741,   505,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   650,   506,
     514,   438,   653,   520,   554,   556,   654,   293,   294,   295,
     296,   297,   298,   293,   294,   295,   296,   297,   298,   578,
     344,   555,   240,   240,   579,   572,   604,   600,   293,   294,
     295,   296,   297,   298,   606,   240,   609,   656,   664,   666,
     240,   481,   481,   575,   240,   680,   688,   682,   691,   692,
     699,   703,   721,   728,   663,   734,   739,   740,    29,   679,
      55,    87,   256,   481,   392,   463,   523,   524,   661,   571,
     662,   525,   526,   527,   366,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   709,   447,   591,   559,   124,   737,
     714,   685,   712,   240,   735,     0,     0,     0,   240,     0,
     240,   360,     0,     0,   240,     0,     0,   240,     0,     0,
       0,     0,   243,     0,   240,     0,     0,     0,   240,     0,
       0,     0,     0,   710,     0,     0,   277,     0,     0,     0,
       0,   716,     0,   599,   717,   718,     0,   243,     0,     0,
       0,     0,     0,   720,     0,     0,     0,     0,     0,   140,
     141,     0,     0,     0,   715,   142,   467,   240,     0,   143,
     240,     0,     0,   438,     0,     0,     0,   144,     0,     0,
       0,     0,   738,   145,     0,   146,   147,   148,     0,   736,
     149,     0,   438,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,   693,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,     0,   169,   170,   171,
     172,     0,   173,   174,   468,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,     0,     0,   184,   185,   186,
     187,   188,     0,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   469,
       0,   203,   204,   205,   206,   470,     0,     0,     0,     0,
     208,   209,     0,     0,   210,   211,     0,     0,   212,     0,
     213,   214,   215,   216,   217,   218,   575,     0,   219,   220,
     221,     0,   222,   223,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,   140,
     141,     0,     0,     0,     0,   142,   467,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,   145,     0,   146,   147,   148,     0,     0,
     149,     0,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,     0,   169,   170,   171,
     172,     0,   173,   174,   468,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,     0,     0,   184,   185,   186,
     187,   188,     0,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   469,
       0,   203,   204,   205,   206,   470,     0,     0,     0,     0,
     208,   209,     0,     0,   210,   211,     0,     0,   212,     0,
     213,   214,   215,   216,   217,   218,     0,     0,   219,   220,
     221,     0,   222,   223,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,   145,     0,   146,   147,   148,   671,   672,
     149,     0,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,     0,   169,   170,   171,
     172,     0,   173,   174,     0,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,     0,     0,   184,   185,   186,
     187,   188,     0,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,     0,
       0,   203,   204,   205,   206,   673,     0,     0,     0,     0,
     208,   209,     0,     0,   210,   211,     0,     0,   212,     0,
     213,   214,   215,   216,   217,   218,     0,     0,   219,   220,
     221,   674,   222,   223,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,   145,     0,   146,   147,   148,     0,     0,
     149,     0,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,     0,   169,   170,   171,
     172,     0,   173,   174,   468,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,     0,     0,   184,   185,   186,
     187,   188,     0,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   469,
       0,   203,   204,   205,   206,   470,     0,     0,     0,     0,
     208,   209,     0,     0,   210,   211,     0,     0,   212,     0,
     213,   214,   215,   216,   217,   218,     0,     0,   219,   220,
     221,     0,   222,   223,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,   145,     0,   146,   147,   148,     0,     0,
     149,     0,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,     0,   169,   170,   171,
     172,     0,   173,   174,     0,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,     0,     0,   184,   185,   186,
     187,   188,     0,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,     0,
       0,   203,   204,   205,   206,   207,     0,     0,     0,     0,
     208,   209,     0,     0,   210,   211,     0,     0,   212,     0,
     213,   214,   215,   216,   217,   218,   575,     0,   219,   220,
     221,     0,   222,   223,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,   145,     0,   146,   147,   148,     0,     0,
     149,     0,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,     0,     0,     0,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,     0,   169,   170,   171,
     172,     0,   173,   174,     0,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,     0,     0,   184,   185,   186,
     187,   188,     0,     0,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,     0,
       0,   203,   204,   205,   206,   207,     0,     0,     0,     0,
     208,   209,     0,     0,   210,   211,     0,     0,   212,     0,
     213,   214,   215,   216,   217,   218,     0,     0,   219,   220,
     221,     0,   222,   223,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,   146,   147,   148,     0,     0,
     149,     0,     0,     0,   151,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,   159,     0,   161,   396,     0,
     163,   397,   165,   166,   167,   168,     0,   169,     0,     0,
     172,     0,   173,   174,     0,   175,   176,   177,     0,   178,
     179,   180,   181,   182,   183,     0,     0,   184,   185,   186,
     187,   188,   286,   287,   288,   289,   290,   291,   192,   193,
     194,   195,   196,   197,   198,   199,   398,   201,   202,     0,
       0,     0,     0,   205,   206,     0,     0,     0,     0,     0,
     208,   209,     0,     0,   210,   211,     0,     0,   212,     0,
     213,   214,   215,   216,   217,   218,     0,     0,   219,   220,
     221,     0,   222,     0,   224,   225,   226,   227,     0,   228,
     229,   403,   404,   286,   287,   288,   289,   290,   291,   230,
       0,   232,   233,   234,     0,   235,     0,     0,   399,     0,
       0,   405,     0,     0,     0,   563,     0,     0,     0,     0,
       0,   310,   310,   406,   407,     0,     0,     0,     0,     0,
       0,     0,   408,     0,     0,     0,     0,   409,     0,   410,
     411,     0,   412,     0,   558,     0,     0,     0,     0,     0,
     171,     0,   311,   311,     0,   293,   294,   295,   296,   297,
     298,     0,   312,   312,     0,   413,     0,     0,     0,     0,
       0,     0,     0,     0,   313,   313,   414,   415,   416,     0,
       0,   314,   314,     0,     0,     0,     0,   417,   418,     0,
       0,     0,   203,   419,     0,     0,   420,     0,   315,   315,
     316,   316,   317,   317,     0,     0,     0,   421,     0,     0,
       0,   318,   318,     0,     0,     0,   293,   294,   295,   296,
     297,   298,     0,     0,     0,   140,   141,     0,     0,     0,
     422,   142,     0,     0,     0,   143,   319,   319,   320,   320,
       0,   423,     0,   144,     0,     0,     0,   424,   425,   426,
       0,   146,   147,   148,     0,     0,   149,     0,     0,     0,
     151,   152,   153,   154,   155,   156,   157,   260,     0,     0,
       0,   159,     0,   161,     0,     0,   163,     0,   165,   166,
     167,   168,     0,   169,     0,     0,   172,     0,   173,   174,
       0,   175,   176,   177,     0,   178,   179,   180,   181,   182,
     183,     0,     0,   184,   185,   186,   187,   188,     0,     0,
       0,   261,     0,     0,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   201,   202,     0,     0,     0,     0,   205,
     206,     0,     0,     0,     0,     0,   208,   209,     0,     0,
     210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
     217,   218,     0,     0,   219,   220,   221,     0,   222,     0,
     224,   225,   226,   227,     0,   228,   229,     0,     0,     0,
     140,   141,     0,     0,     0,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
       0,   149,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   260,     0,     0,     0,   159,     0,   161,     0,
       0,   163,     0,   165,   166,   167,   168,     0,   169,     0,
       0,   172,     0,   173,   174,     0,   175,   176,   177,     0,
     178,   179,   180,   181,   182,   183,     0,     0,   184,   185,
     186,   187,   188,     0,     0,     0,     0,     0,     0,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   201,   202,
       0,     0,     0,     0,   205,   206,     0,     0,     0,     0,
     361,   208,   209,     0,     0,   210,   211,     0,     0,   212,
       0,   213,   214,   215,   216,   217,   218,     0,     0,   219,
     220,   221,     0,   222,     0,   224,   225,   226,   227,     0,
     228,   229,     0,     0,     0,   140,   141,     0,     0,     0,
     230,   142,   232,   233,   234,   143,   235,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,     0,     0,   149,     0,     0,     0,
     151,   152,   153,   154,   155,   156,   157,   260,     0,     0,
       0,   159,     0,   161,     0,     0,   163,     0,   165,   166,
     167,   168,     0,   169,     0,     0,   172,     0,   173,   174,
       0,   175,   176,   177,     0,   178,   179,   180,   181,   182,
     183,     0,     0,   184,   185,   186,   187,   188,     0,     0,
       0,     0,     0,     0,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   201,   202,     0,     0,     0,     0,   205,
     206,   462,     0,     0,     0,     0,   208,   209,     0,     0,
     210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
     217,   218,     0,     0,   219,   220,   221,     0,   222,     0,
     224,   225,   226,   227,     0,   228,   229,     0,     0,     0,
     140,   141,     0,     0,     0,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,   384,     0,   146,   147,   148,     0,
       0,   149,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   157,     0,     0,     0,     0,   159,     0,   161,     0,
       0,   163,     0,   165,   166,   167,   168,     0,   169,     0,
       0,   172,     0,   173,   174,     0,   175,   176,   177,     0,
     178,   179,   180,   181,   182,   183,     0,     0,   184,   185,
     186,   187,   188,     0,     0,     0,     0,     0,     0,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   201,   202,
       0,     0,     0,     0,   205,   206,     0,     0,     0,     0,
       0,   208,   209,     0,     0,   210,   211,     0,     0,   212,
       0,   213,   214,   215,   216,   217,   218,     0,     0,   219,
     220,   221,     0,   222,     0,   224,   225,   226,   227,     0,
     228,   229,     0,     0,     0,   140,   141,     0,     0,     0,
     230,   142,   232,   233,   234,   143,   235,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,   448,
       0,   146,   147,   148,     0,     0,   149,     0,     0,     0,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
       0,   159,     0,   161,     0,     0,   163,     0,   165,   166,
     167,   168,     0,   169,     0,     0,   172,     0,   173,   174,
       0,   175,   176,   177,     0,   178,   179,   180,   181,   182,
     183,     0,     0,   184,   185,   186,   187,   188,     0,     0,
       0,     0,     0,     0,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   201,   202,     0,     0,     0,     0,   205,
     206,     0,     0,     0,     0,     0,   208,   209,     0,     0,
     210,   211,     0,     0,   212,     0,   213,   214,   215,   216,
     217,   218,     0,     0,   219,   220,   221,     0,   222,     0,
     224,   225,   226,   227,     0,   228,   229,     0,     0,     0,
     140,   141,     0,     0,     0,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,     0,
     286,   287,   288,   289,   290,   291,   146,   147,   148,     0,
       0,   149,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   157,   565,     0,     0,     0,   159,     0,   161,     0,
       0,   163,     0,   165,   166,   167,   168,     0,   169,     0,
       0,   172,     0,   173,   174,     0,   175,   176,   177,     0,
     178,   179,   180,   181,   182,   183,     0,     0,   184,   185,
     186,   187,   188,     0,     0,     0,     0,     0,     0,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   201,   202,
       0,     0,     0,     0,   205,   206,     0,     0,     0,     0,
       0,   208,   209,     0,     0,   210,   211,     0,     0,   212,
       0,   213,   214,   215,   216,   217,   218,     0,     0,   219,
     220,   221,     0,   222,     0,   224,   225,   226,   227,     0,
     228,   229,     0,   293,   294,   295,   296,   297,   298,     0,
     230,     0,   232,   233,   234,   592,   235,     0,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   286,
     287,   288,   289,   290,   291,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,     0,     0,     0,   592,
       0,   355,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   286,   287,   288,   289,   290,   291,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,     0,
       0,   523,   524,     0,     0,     0,   525,   526,   527,   593,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   594,
       0,     0,     0,     0,     0,   523,   524,     0,     0,     0,
     525,   526,   527,   593,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   594,   286,   287,   288,   289,   290,   291,
       0,     0,   293,   294,   295,   296,   297,   298,   286,   287,
     288,   289,   290,   291,     0,    37,   566,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    40,     0,     0,
     567,     0,     0,     0,     0,     0,   293,   294,   295,   296,
     297,   298,    41,     0,     0,     0,     0,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,   523,   524,   547,     0,
      45,   525,   526,   527,     0,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,     0,     0,     0,     0,     0,   730,
       0,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,   294,   295,
     296,   297,   298,     0,     0,   557,    48,     0,     0,     0,
       0,   293,   294,   295,   296,   297,   298,   689,   523,   524,
       0,     0,     0,   525,   526,   527,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,     0,     0,     0,     0,
       0,     0,     0,     0,   701,   523,   524,     0,     0,     0,
     525,   526,   527,   690,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,   524,     0,     0,     0,   525,   526,   527,
     702,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   523,
     524,     0,     0,     0,   525,   526,   527,   729,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,   524,     0,     0,
       0,   525,   526,   527,   732,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,     0,     0,     0,     0,     0,     0,
       0,     0,   523,   524,     0,     0,     0,   525,   526,   527,
     628,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     525,   526,   527,     0,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   526,   527,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   527,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546
};

static const yytype_int16 yycheck[] =
{
      72,    73,    74,    75,   137,   137,    78,    79,    80,   115,
      82,    83,   321,    15,   259,   468,   469,   462,     8,   464,
     549,   470,     8,    65,   333,     8,   253,     4,   115,    39,
      40,    48,    35,    18,    36,    27,    43,   170,    35,    81,
      48,    84,    91,    53,    68,    92,    37,    51,   128,    66,
       4,    53,   575,   133,   126,     4,   128,     4,    54,   101,
      63,    68,    66,   105,   106,   114,    63,    75,   110,   705,
     664,    62,   666,    68,    76,    92,    92,   713,    68,    71,
     307,   308,   309,   606,   393,   394,   395,     4,   104,    96,
      80,   108,   109,   320,    80,    49,   143,   407,   271,   148,
      49,   207,    79,    50,   147,   278,   279,   280,   100,   113,
     134,   118,   422,   123,   424,   425,   133,   125,    10,     0,
     207,   104,   129,   130,   337,    66,   259,   259,   113,   723,
     343,   121,   127,    50,   443,   121,   146,   144,   145,    33,
     593,   594,    11,   596,     4,    60,   149,    41,    33,     4,
     283,   600,   149,   163,   164,     4,    41,    49,    27,    28,
      29,    30,    31,    32,   391,   392,   272,   273,   301,   159,
     276,   112,   113,   159,    68,   281,   282,   310,     4,    73,
       4,    68,     4,    88,     4,    70,   495,   496,    73,    68,
      50,     4,   721,   104,    49,   282,   302,   507,   508,   372,
      49,   511,   512,   513,   337,   338,   338,   104,     4,   342,
     343,   740,   657,    43,   312,   113,    48,   111,   316,     4,
       4,   319,   675,    49,   118,    49,   111,    49,   361,    49,
      70,   303,   365,   118,    66,   117,    49,   127,   547,    14,
      15,   486,   314,   349,   350,     4,   318,     4,   557,     4,
     356,   357,   358,    49,   659,    95,    29,    30,    31,    32,
      92,   367,   349,   350,    49,    49,    96,    42,     4,   356,
     357,   358,   378,   315,    76,   317,   108,   109,    92,   684,
     367,   150,   151,   152,   153,   154,   155,   112,   118,   112,
      49,   378,    49,   112,    49,   273,   114,   115,   276,   129,
     130,   505,   506,   281,   112,   403,   404,   405,    50,   311,
     514,   515,    27,    28,   144,   145,   520,   287,   288,   289,
     290,   291,   420,   100,   302,   112,   113,    31,    32,   462,
     100,   464,   304,   305,    27,    28,    29,    30,    31,    32,
      27,    28,    29,    30,    31,    32,    97,   100,   454,   143,
     100,    48,   485,   486,   486,    27,    28,    29,    30,    31,
      32,   467,    49,    77,   470,    68,     5,   454,   133,    61,
      49,    49,    81,    81,   118,   131,   482,    49,   112,   112,
     467,   112,   112,   470,   112,    92,   112,   112,   112,   112,
     699,   110,   110,    68,    84,   482,   494,    49,    49,   131,
     498,    66,   131,     4,   502,    66,    51,     9,   104,    92,
       4,   104,    82,    51,   141,    91,     9,   112,   490,   113,
     492,    18,   113,   521,   110,   523,    99,   525,   526,   134,
     739,   112,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   112,
     112,   549,   550,   112,     4,    99,   554,   150,   151,   152,
     153,   154,   155,   150,   151,   152,   153,   154,   155,    10,
     113,   145,   578,   579,    11,   112,   609,    83,   150,   151,
     152,   153,   154,   155,   133,   591,   141,    92,   112,   112,
     596,   578,   579,   133,   600,     4,    50,   161,    49,     4,
      67,    50,    18,    50,   591,    49,    64,    18,    16,   596,
      31,    63,   122,   600,   305,   361,     5,     6,   578,   467,
     579,    10,    11,    12,   657,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   666,   338,   480,   449,    93,   727,
     685,   609,   680,   659,   723,    -1,    -1,    -1,   664,    -1,
     666,   282,    -1,    -1,   670,    -1,    -1,   673,    -1,    -1,
      -1,    -1,   659,    -1,   680,    -1,    -1,    -1,   684,    -1,
      -1,    -1,    -1,   670,    -1,    -1,   673,    -1,    -1,    -1,
      -1,   689,    -1,   680,   692,   693,    -1,   684,    -1,    -1,
      -1,    -1,    -1,   701,    -1,    -1,    -1,    -1,    -1,     6,
       7,    -1,    -1,    -1,   686,    12,    13,   723,    -1,    16,
     726,    -1,    -1,   721,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,   730,    30,    -1,    32,    33,    34,    -1,   726,
      37,    -1,   740,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,   143,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,   135,   136,
     137,    -1,   139,   140,   141,   142,   143,   144,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,     6,
       7,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,    -1,   139,   140,   141,   142,   143,   144,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    -1,    69,    70,    -1,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    -1,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,    -1,   139,   140,   141,   142,   143,   144,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    -1,    69,    70,    -1,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    -1,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,   135,   136,
     137,    -1,   139,   140,   141,   142,   143,   144,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    65,    66,
      67,    -1,    69,    70,    -1,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    -1,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,    -1,   139,   140,   141,   142,   143,   144,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,    -1,   162,   163,   164,   165,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    -1,    -1,    52,    -1,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    64,    -1,    -1,
      67,    -1,    69,    70,    -1,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    85,    86,
      87,    88,    27,    28,    29,    30,    31,    32,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    -1,
      -1,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,    -1,
     127,   128,   129,   130,   131,   132,    -1,    -1,   135,   136,
     137,    -1,   139,    -1,   141,   142,   143,   144,    -1,   146,
     147,     7,     8,    27,    28,    29,    30,    31,    32,   156,
      -1,   158,   159,   160,    -1,   162,    -1,    -1,   165,    -1,
      -1,    27,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    45,    45,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,    55,
      56,    -1,    58,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    76,    76,    -1,   150,   151,   152,   153,   154,
     155,    -1,    86,    86,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    98,    92,    93,    94,    -1,
      -1,   105,   105,    -1,    -1,    -1,    -1,   103,   104,    -1,
      -1,    -1,   108,   109,    -1,    -1,   112,    -1,   122,   122,
     124,   124,   126,   126,    -1,    -1,    -1,   123,    -1,    -1,
      -1,   135,   135,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
     146,    12,    -1,    -1,    -1,    16,   160,   160,   162,   162,
      -1,   157,    -1,    24,    -1,    -1,    -1,   163,   164,   165,
      -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    52,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    -1,    64,    -1,    -1,    67,    -1,    69,    70,
      -1,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    92,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,    -1,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,   137,    -1,   139,    -1,
     141,   142,   143,   144,    -1,   146,   147,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,   156,    12,   158,   159,   160,
      16,   162,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    52,    -1,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    -1,    64,    -1,
      -1,    67,    -1,    69,    70,    -1,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,
      -1,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,    -1,   139,    -1,   141,   142,   143,   144,    -1,
     146,   147,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
     156,    12,   158,   159,   160,    16,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    52,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    -1,    64,    -1,    -1,    67,    -1,    69,    70,
      -1,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,   112,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,    -1,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,   137,    -1,   139,    -1,
     141,   142,   143,   144,    -1,   146,   147,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,   156,    12,   158,   159,   160,
      16,   162,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    -1,    64,    -1,
      -1,    67,    -1,    69,    70,    -1,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,
      -1,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,    -1,   139,    -1,   141,   142,   143,   144,    -1,
     146,   147,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
     156,    12,   158,   159,   160,    16,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    52,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      61,    62,    -1,    64,    -1,    -1,    67,    -1,    69,    70,
      -1,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,   104,   105,    -1,    -1,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
     121,   122,    -1,    -1,   125,    -1,   127,   128,   129,   130,
     131,   132,    -1,    -1,   135,   136,   137,    -1,   139,    -1,
     141,   142,   143,   144,    -1,   146,   147,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,   156,    12,   158,   159,   160,
      16,   162,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      27,    28,    29,    30,    31,    32,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    49,    -1,    -1,    -1,    52,    -1,    54,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    -1,    64,    -1,
      -1,    67,    -1,    69,    70,    -1,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,   104,   105,
      -1,    -1,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,   121,   122,    -1,    -1,   125,
      -1,   127,   128,   129,   130,   131,   132,    -1,    -1,   135,
     136,   137,    -1,   139,    -1,   141,   142,   143,   144,    -1,
     146,   147,    -1,   150,   151,   152,   153,   154,   155,    -1,
     156,    -1,   158,   159,   160,    13,   162,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    13,
      -1,    49,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,    87,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   107,
      -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    87,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   107,    27,    28,    29,    30,    31,    32,
      -1,    -1,   150,   151,   152,   153,   154,   155,    27,    28,
      29,    30,    31,    32,    -1,    47,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    57,    -1,    59,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,   155,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,   142,    -1,
     102,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,    -1,    -1,    64,   158,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    50,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      50,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    50,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    50,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      49,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    54,   167,   168,     8,   104,     0,    60,   169,   170,
      68,    68,     8,    80,   121,   159,   171,   172,    88,   177,
     178,   104,   174,   175,   104,   173,   113,   175,    68,   172,
     127,   179,   180,   117,   181,   182,     4,    47,    55,    57,
      59,    74,    80,    89,    90,   102,   136,   137,   158,   176,
      92,   278,   176,    76,    68,   180,    43,    96,   118,   129,
     130,   144,   145,   183,   184,   128,   133,   185,   186,   187,
     241,   175,   112,   112,   112,   112,    50,   175,   100,   100,
      97,   143,   100,   100,    48,   279,    68,   184,   279,   242,
      77,   189,    68,   134,    68,   176,   278,   278,   278,   278,
     175,     5,   278,   278,   278,    75,   125,   279,   278,   278,
      61,   188,    35,    63,   149,   249,    33,    41,    70,    73,
     111,   118,   191,   192,   241,    49,     4,    49,     4,    49,
      49,   176,   279,   279,   279,   279,   114,   115,   195,   196,
       6,     7,    12,    16,    24,    30,    32,    33,    34,    37,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    52,
      53,    54,    55,    57,    58,    59,    60,    61,    62,    64,
      65,    66,    67,    69,    70,    72,    73,    74,    76,    77,
      78,    79,    80,    81,    84,    85,    86,    87,    88,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   108,   109,   110,   111,   112,   117,   118,
     121,   122,   125,   127,   128,   129,   130,   131,   132,   135,
     136,   137,   139,   140,   141,   142,   143,   144,   146,   147,
     156,   157,   158,   159,   160,   162,   163,   164,   165,   198,
     240,   250,   251,   254,   280,   281,    81,    81,   131,   118,
      70,    95,    84,   147,    68,   190,   192,   278,   278,   197,
      48,    92,   201,   202,   203,   234,   235,   236,   238,   280,
     112,   112,   112,   112,   280,    92,   112,   254,   112,   112,
     112,   112,     4,    79,   209,   214,    27,    28,    29,    30,
      31,    32,   104,   150,   151,   152,   153,   154,   155,   253,
     255,    66,   112,   113,   110,   110,    68,    84,   131,   131,
      45,    76,    86,    98,   105,   122,   124,   126,   135,   160,
     162,   260,   261,   262,   264,   266,   268,   271,   272,   273,
     275,   276,   277,   260,    49,    49,   201,    66,     4,    37,
      62,   204,    66,    51,   113,   237,    35,    63,   149,   233,
     233,   254,   258,   258,   258,    49,   233,   233,   233,   258,
     251,   116,   210,   211,   212,   234,   280,     9,   208,   215,
      91,   114,   148,   199,   245,    27,    28,   256,   257,   256,
     256,   256,   256,   256,    30,   280,   258,   278,    92,   104,
     193,   194,   194,   260,   260,   260,    55,    58,   103,   165,
     263,   280,   175,     7,     8,    27,    39,    40,    48,    53,
      55,    56,    58,    81,    92,    93,    94,   103,   104,   109,
     112,   123,   146,   157,   163,   164,   165,   193,   240,   283,
     285,   286,   291,   104,   278,   279,   269,   270,   286,   279,
     143,   278,   286,   260,   261,   236,   280,   202,    30,   280,
     236,    92,   254,   254,     4,    49,    49,    49,   254,   254,
     254,    49,   112,   212,     4,   239,   280,    13,    71,   106,
     112,   218,   219,   220,   221,   222,   223,   227,   230,   232,
     248,   254,    82,   206,   216,   141,   200,   233,    91,   254,
     113,    49,     4,    50,   113,   260,   260,   112,    18,   286,
     286,   286,   110,   284,   284,   112,   112,    39,    40,    53,
     123,   146,   163,   164,   112,   112,   286,   284,   284,   284,
     112,     9,   282,     5,     6,    10,    11,    12,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   142,   287,    18,
     113,    99,   134,   274,     4,   145,    99,    64,    68,   237,
       4,    50,    49,    49,   254,    49,    49,    49,   211,   213,
     211,   221,   112,   248,   248,   133,   218,   254,    10,    11,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   231,    13,    87,   107,   229,   231,   207,   252,   254,
      83,   205,   217,   247,   280,   201,   133,   243,   244,   141,
     278,   278,   286,   286,   288,   289,   290,   286,   286,   289,
     289,   284,   284,   284,   284,   284,   289,   289,    49,   289,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   261,   270,   286,   286,   261,    92,     4,    49,   249,
      49,   219,   220,   254,   112,   248,   112,   248,    14,    15,
      42,    35,    36,   112,   138,   224,   225,   226,   248,   254,
       4,   218,   161,   246,   249,   247,     4,    50,    50,     4,
      50,    49,     4,   143,    49,    49,    49,    49,    49,    67,
     267,     4,    50,    50,   211,   250,   198,   228,   259,   228,
     254,   248,   252,   250,   246,   278,   286,   286,   286,   261,
     286,    18,   214,     4,    49,    49,    11,   214,    50,    50,
     139,   265,    50,   270,    49,   259,   254,   245,   286,    64,
      18,   261,   270
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
#line 245 "ace.yacc"
    {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
    break;

  case 4:
#line 248 "ace.yacc"
    {
		this_report.dbname=acl_strdup((yyvsp[(2) - (3)].str));
		A4GLSQL_init_connection ((yyvsp[(2) - (3)].str));
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
    break;

  case 10:
#line 272 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:
#line 276 "ace.yacc"
    {
		ace_add_variable((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str),CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:
#line 279 "ace.yacc"
    {
		ace_add_variable((yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str),CAT_PARAM,atoi((yyvsp[(3) - (6)].str)),-1,0);
	}
    break;

  case 13:
#line 282 "ace.yacc"
    {
		add_function((yyvsp[(2) - (2)].str));
	}
    break;

  case 17:
#line 293 "ace.yacc"
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
#line 306 "ace.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 20:
#line 307 "ace.yacc"
    {strcpy((yyval.str),"CHAR");}
    break;

  case 21:
#line 308 "ace.yacc"
    {sprintf((yyval.str),"CHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 22:
#line 309 "ace.yacc"
    {strcpy((yyval.str),"VARCHAR");}
    break;

  case 23:
#line 310 "ace.yacc"
    {sprintf((yyval.str),"VARCHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 24:
#line 311 "ace.yacc"
    {strcpy((yyval.str),"DATE");}
    break;

  case 25:
#line 312 "ace.yacc"
    {strcpy((yyval.str),"FLOAT");}
    break;

  case 26:
#line 313 "ace.yacc"
    {strcpy((yyval.str),"SMALLFLOAT");}
    break;

  case 27:
#line 314 "ace.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 28:
#line 315 "ace.yacc"
    {strcpy((yyval.str),"DATETIME");}
    break;

  case 29:
#line 316 "ace.yacc"
    {strcpy((yyval.str),"INTERVAL");}
    break;

  case 30:
#line 317 "ace.yacc"
    {strcpy((yyval.str),"MONEY");}
    break;

  case 31:
#line 318 "ace.yacc"
    {sprintf((yyval.str),"MONEY (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 32:
#line 319 "ace.yacc"
    {sprintf((yyval.str),"MONEY (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 33:
#line 320 "ace.yacc"
    {strcpy((yyval.str),"DECIMAL");}
    break;

  case 34:
#line 321 "ace.yacc"
    {sprintf((yyval.str),"DECIMAL (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 35:
#line 322 "ace.yacc"
    {sprintf((yyval.str),"DECIMAL (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 41:
#line 336 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes((yyvsp[(5) - (5)].str)),(yyvsp[(3) - (5)].str));
}
    break;

  case 47:
#line 351 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str));}
    break;

  case 48:
#line 352 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:
#line 353 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup((yyvsp[(3) - (3)].str)); }
    break;

  case 50:
#line 354 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str)); }
    break;

  case 51:
#line 355 "ace.yacc"
    {
		this_report.output.left_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 52:
#line 358 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 53:
#line 361 "ace.yacc"
    {
		this_report.output.top_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 54:
#line 364 "ace.yacc"
    {
		this_report.output.page_length=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 55:
#line 367 "ace.yacc"
    {
		this_report.output.right_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 56:
#line 370 "ace.yacc"
    {
		this_report.output.top_of_page=acl_strdup((yyvsp[(2) - (2)].str));
	}
    break;

  case 58:
#line 377 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:
#line 381 "ace.yacc"
    { add_select((yyvsp[(1) - (1)].str),temp_tab_name); }
    break;

  case 60:
#line 382 "ace.yacc"
    { add_select((yyvsp[(3) - (3)].str),temp_tab_name); }
    break;

  case 64:
#line 393 "ace.yacc"
    {
		struct commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,NULL,cmd);
	  }
    break;

  case 70:
#line 412 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 71:
#line 416 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 72:
#line 420 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 73:
#line 424 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 74:
#line 427 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 75:
#line 430 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 76:
#line 433 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 77:
#line 440 "ace.yacc"
    {
		(yyval.var_usage)=malloc(sizeof(struct var_usage));
		(yyval.var_usage)->subscript1=DUP((yyvsp[(3) - (6)].expr));
		(yyval.var_usage)->subscript2=DUP((yyvsp[(5) - (6)].expr));
		(yyval.var_usage)->varname=strdup((yyvsp[(1) - (6)].str));
		(yyval.var_usage)->varid=find_variable((yyval.var_usage)->varname);
		if ( (yyval.var_usage)->varid==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[(1) - (6)].str));
		}
	}
    break;

  case 78:
#line 450 "ace.yacc"
    {
		(yyval.var_usage)=malloc(sizeof(struct var_usage));
		(yyval.var_usage)->subscript1=DUP((yyvsp[(3) - (4)].expr));
		(yyval.var_usage)->subscript2=NULL;
		(yyval.var_usage)->varname=strdup((yyvsp[(1) - (4)].str));
		(yyval.var_usage)->varid=find_variable((yyval.var_usage)->varname);
		if ( (yyval.var_usage)->varid==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[(1) - (4)].str));
		}
	}
    break;

  case 79:
#line 460 "ace.yacc"
    {
		
		(yyval.var_usage)=malloc(sizeof(struct var_usage));
		(yyval.var_usage)->subscript1=NULL;
		(yyval.var_usage)->subscript2=NULL;
		(yyval.var_usage)->varname=strdup((yyvsp[(1) - (1)].str));
		(yyval.var_usage)->varid=find_variable((yyval.var_usage)->varname);
		if ( (yyval.var_usage)->varid==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[(1) - (1)].str));
		}
	}
    break;

  case 80:
#line 475 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 81:
#line 479 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;

  case 82:
#line 487 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 84:
#line 490 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:
#line 490 "ace.yacc"
    {
	printf("speclist : %s ",(yyvsp[(3) - (3)].str));
	sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str));}
    break;

  case 86:
#line 494 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:
#line 503 "ace.yacc"
    {
		sprintf((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));
	}
    break;

  case 91:
#line 513 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 92:
#line 513 "ace.yacc"
    { sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str)); }
    break;

  case 94:
#line 518 "ace.yacc"
    {
sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 95:
#line 523 "ace.yacc"
    {
		if (strlen((yyvsp[(2) - (2)].str))) {
			sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 96:
#line 529 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"I%d",atoi((yyvsp[(1) - (1)].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 97:
#line 534 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"C%s",(yyvsp[(1) - (1)].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 98:
#line 541 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:
#line 549 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 102:
#line 555 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 104:
#line 561 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 105:
#line 566 "ace.yacc"
    {sprintf((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[(2) - (2)].str));}
    break;

  case 106:
#line 571 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 108:
#line 577 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 109:
#line 581 "ace.yacc"
    {sprintf((yyval.str)," %s ", (yyvsp[(1) - (1)].str));}
    break;

  case 110:
#line 582 "ace.yacc"
    {sprintf((yyval.str)," %s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 111:
#line 583 "ace.yacc"
    {sprintf((yyval.str)," %s (%s) ",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 113:
#line 587 "ace.yacc"
    {
		sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		ace_add_table((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 115:
#line 595 "ace.yacc"
    { sprintf((yyval.str)," %s,%s ",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 116:
#line 603 "ace.yacc"
    {
sprintf((yyval.str),"%s %s %s %s",
(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),
(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
}
    break;

  case 117:
#line 610 "ace.yacc"
    {strcpy((yyval.str),"\n0");}
    break;

  case 119:
#line 614 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 121:
#line 618 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 124:
#line 626 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 126:
#line 632 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 128:
#line 638 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 130:
#line 644 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 131:
#line 649 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 132:
#line 650 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 133:
#line 656 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 134:
#line 658 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 140:
#line 696 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 141:
#line 698 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 142:
#line 700 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 143:
#line 702 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 145:
#line 709 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 146:
#line 712 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 148:
#line 719 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 149:
#line 721 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 150:
#line 723 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 151:
#line 725 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 152:
#line 727 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 162:
#line 741 "ace.yacc"
    {sprintf((yyval.str),"<=");}
    break;

  case 163:
#line 742 "ace.yacc"
    {sprintf((yyval.str),">=");}
    break;

  case 168:
#line 752 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:
#line 766 "ace.yacc"
    { sprintf((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[(1) - (1)].str))); }
    break;

  case 173:
#line 767 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 174:
#line 768 "ace.yacc"
    { sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 175:
#line 769 "ace.yacc"
    { sprintf((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[(1) - (3)].str)),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 177:
#line 779 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 178:
#line 783 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 179:
#line 784 "ace.yacc"
    {sprintf((yyval.str),"[%s]",(yyvsp[(2) - (3)].str));}
    break;

  case 180:
#line 785 "ace.yacc"
    {sprintf((yyval.str),"[%s,%s]",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));}
    break;

  case 181:
#line 788 "ace.yacc"
    { sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 182:
#line 789 "ace.yacc"
    { sprintf((yyval.str),"%s.%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); }
    break;

  case 183:
#line 790 "ace.yacc"
    { sprintf((yyval.str),"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 186:
#line 801 "ace.yacc"
    {sprintf((yyval.str),"0.%s",(yyvsp[(2) - (2)].str));}
    break;

  case 187:
#line 816 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 188:
#line 819 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));
}
    break;

  case 190:
#line 840 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str) );}
    break;

  case 191:
#line 844 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 192:
#line 845 "ace.yacc"
    {
       sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
       }
    break;

  case 194:
#line 849 "ace.yacc"
    {
       sprintf((yyval.str),"INTO TEMP %s%s ",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (4)].str));
}
    break;

  case 195:
#line 853 "ace.yacc"
    {
       sprintf((yyval.str),"%s INTO TEMP %s%s ",(yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (5)].str));
}
    break;

  case 196:
#line 861 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 197:
#line 861 "ace.yacc"
    {strcpy((yyval.str)," WITH NO LOG");}
    break;

  case 199:
#line 883 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 200:
#line 886 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 201:
#line 887 "ace.yacc"
    {sprintf((yyval.str),"ALL");}
    break;

  case 202:
#line 888 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 203:
#line 889 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 205:
#line 894 "ace.yacc"
    { sprintf((yyval.str)," %s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 206:
#line 898 "ace.yacc"
    {
			add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
		}
    break;

  case 207:
#line 901 "ace.yacc"
    {
			sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_select_column((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 209:
#line 912 "ace.yacc"
    {sprintf((yyval.str),"UNITS YEAR");}
    break;

  case 210:
#line 913 "ace.yacc"
    {sprintf((yyval.str),"UNITS MONTH"); }
    break;

  case 211:
#line 914 "ace.yacc"
    {sprintf((yyval.str),"UNITS DAY);"); }
    break;

  case 212:
#line 915 "ace.yacc"
    {sprintf((yyval.str),"UNITS HOUR);"); }
    break;

  case 213:
#line 916 "ace.yacc"
    {sprintf((yyval.str),"UNITS MINUTE);"); }
    break;

  case 214:
#line 917 "ace.yacc"
    {sprintf((yyval.str),"UNITS SECOND);"); }
    break;

  case 215:
#line 921 "ace.yacc"
    { sprintf((yyval.str),"%s%s", (yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 218:
#line 924 "ace.yacc"
    {sprintf((yyval.str)," %s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 219:
#line 925 "ace.yacc"
    {sprintf((yyval.str)," %s[%s,%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 220:
#line 926 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 221:
#line 927 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s,%s]",(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str));}
    break;

  case 222:
#line 928 "ace.yacc"
    {
			if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
			sprintf((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
			}
    break;

  case 223:
#line 933 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 224:
#line 935 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 228:
#line 939 "ace.yacc"
    {sprintf((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 229:
#line 940 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 230:
#line 941 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 231:
#line 942 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 232:
#line 943 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 233:
#line 944 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 234:
#line 945 "ace.yacc"
    {sprintf((yyval.str),"%s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 235:
#line 948 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 236:
#line 950 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 237:
#line 952 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 238:
#line 954 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 239:
#line 956 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 240:
#line 960 "ace.yacc"
    {sprintf((yyval.str),"/%s",(yyvsp[(2) - (2)].str));}
    break;

  case 241:
#line 961 "ace.yacc"
    {sprintf((yyval.str)," MOD %s",(yyvsp[(2) - (2)].str));}
    break;

  case 242:
#line 962 "ace.yacc"
    {sprintf((yyval.str)," POW %s",(yyvsp[(2) - (2)].str));}
    break;

  case 243:
#line 963 "ace.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 244:
#line 964 "ace.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 245:
#line 965 "ace.yacc"
    {sprintf((yyval.str),"+%s",(yyvsp[(2) - (2)].str));}
    break;

  case 246:
#line 966 "ace.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 247:
#line 969 "ace.yacc"
    { sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 248:
#line 972 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 249:
#line 973 "ace.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 250:
#line 974 "ace.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 252:
#line 979 "ace.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 254:
#line 997 "ace.yacc"
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[(1) - (1)].cmd));
		}
    break;

  case 255:
#line 1002 "ace.yacc"
    {
		COPY((yyval.commands),(yyvsp[(1) - (2)].commands));
		(yyval.commands).commands.commands_len++;
		(yyval.commands).commands.commands_val=realloc(
		(yyval.commands).commands.commands_val,
		(yyval.commands).commands.commands_len*sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[ (yyval.commands).commands.commands_len-1 ],(yyvsp[(2) - (2)].cmd));
	}
    break;

  case 266:
#line 1024 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).command_u.commands.commands.commands_val=(yyvsp[(2) - (3)].commands).commands.commands_val;
		(yyval.cmd).command_u.commands.commands.commands_len=(yyvsp[(2) - (3)].commands).commands.commands_len;
	}
    break;

  case 267:
#line 1061 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[(2) - (5)].str));
	
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(4) - (5)].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).command_u.cmd_call.fcall->lexpr);
}
    break;

  case 273:
#line 1079 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_FOR;
		(yyval.cmd).command_u.cmd_for.varid=find_variable((yyvsp[(2) - (9)].str));
		COPY((yyval.cmd).command_u.cmd_for.start,(yyvsp[(4) - (9)].expr));
		COPY((yyval.cmd).command_u.cmd_for.finish,(yyvsp[(6) - (9)].expr));
		COPY((yyval.cmd).command_u.cmd_for.step,(yyvsp[(7) - (9)].expr));
	}
    break;

  case 274:
#line 1088 "ace.yacc"
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
    break;

  case 275:
#line 1089 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (2)].expr));}
    break;

  case 276:
#line 1093 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_IF;
	COPY((yyval.cmd).command_u.cmd_if.condition,(yyvsp[(2) - (5)].expr));
	(yyval.cmd).command_u.cmd_if.command=(struct command *)DUP((yyvsp[(4) - (5)].cmd));
	(yyval.cmd).command_u.cmd_if.elsecommand=(struct command *)DUP((yyvsp[(5) - (5)].cmd));
}
    break;

  case 277:
#line 1101 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).command_u.null=1;
	}
    break;

  case 278:
#line 1104 "ace.yacc"
    { COPY((yyval.cmd),(yyvsp[(2) - (2)].cmd)); }
    break;

  case 279:
#line 1109 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (4)].str));
		(yyval.cmd).command_u.cmd_let.varid=v;
		(yyval.cmd).command_u.cmd_let.value=DUP((yyvsp[(4) - (4)].expr));
		(yyval.cmd).command_u.cmd_let.sub1=0;
		(yyval.cmd).command_u.cmd_let.sub2=0; 
	}
    break;

  case 280:
#line 1120 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (7)].str));
		(yyval.cmd).command_u.cmd_let.varid=v;
		(yyval.cmd).command_u.cmd_let.value=DUP((yyvsp[(7) - (7)].expr));
		(yyval.cmd).command_u.cmd_let.sub1=DUP((yyvsp[(4) - (7)].expr)); 
		(yyval.cmd).command_u.cmd_let.sub2=0;
	}
    break;

  case 281:
#line 1131 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (9)].str));
		(yyval.cmd).command_u.cmd_let.varid=v;
		(yyval.cmd).command_u.cmd_let.value=DUP((yyvsp[(9) - (9)].expr));
		(yyval.cmd).command_u.cmd_let.sub1=DUP((yyvsp[(4) - (9)].expr)); 
		(yyval.cmd).command_u.cmd_let.sub2=DUP((yyvsp[(6) - (9)].expr)); 
	}
    break;

  case 282:
#line 1144 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
    break;

  case 285:
#line 1151 "ace.yacc"
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 286:
#line 1163 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).command_u.cmd_need.nlines=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 287:
#line 1169 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).command_u.cmd_pause.message=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 288:
#line 1176 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).command_u.cmd_print.printnl=atoi((yyvsp[(3) - (3)].str));
	(yyval.cmd).command_u.cmd_print.print=(yyvsp[(2) - (3)].expr);
}
    break;

  case 289:
#line 1184 "ace.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 290:
#line 1184 "ace.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 291:
#line 1187 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).command_u.cmd_printfile.filename=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 292:
#line 1193 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=atoi((yyvsp[(2) - (3)].str));

	}
    break;

  case 293:
#line 1198 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=-1;
	}
    break;

  case 294:
#line 1205 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		COPY((yyval.cmd).command_u.cmd_while.condition,(yyvsp[(2) - (4)].expr));
		(yyval.cmd).command_u.cmd_while.command=(struct command *)DUP((yyvsp[(4) - (4)].cmd));
}
    break;

  case 377:
#line 1313 "ace.yacc"
    {
			(yyval.exprptr)=0;
		}
    break;

  case 378:
#line 1317 "ace.yacc"
    { 
			(yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); 
		}
    break;

  case 379:
#line 1324 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (2)].agg_val));
		(yyval.agg_val).wexpr=(yyvsp[(2) - (2)].exprptr); 
		}
    break;

  case 380:
#line 1332 "ace.yacc"
    {
			(yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr));
	}
    break;

  case 381:
#line 1338 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 382:
#line 1344 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 383:
#line 1350 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 384:
#line 1356 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 385:
#line 1362 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 386:
#line 1368 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 387:
#line 1374 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 388:
#line 1381 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 389:
#line 1387 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 390:
#line 1393 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 391:
#line 1399 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 392:
#line 1405 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 393:
#line 1411 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 394:
#line 1417 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 395:
#line 1426 "ace.yacc"
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

  case 396:
#line 1444 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 397:
#line 1446 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 398:
#line 1450 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 399:
#line 1454 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 400:
#line 1458 "ace.yacc"
    {
		int v;
		v=find_variable("date");
		(yyval.expr).type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[(1) - (1)].str));
		} 
		(yyval.expr).expr_u.varid=v;
	}
    break;

  case 401:
#line 1467 "ace.yacc"
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

  case 402:
#line 1477 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 403:
#line 1484 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 404:
#line 1490 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 405:
#line 1496 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 406:
#line 1503 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 407:
#line 1509 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 408:
#line 1510 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 409:
#line 1516 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 410:
#line 1522 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 411:
#line 1527 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 412:
#line 1532 "ace.yacc"
    {
		struct expr *e1;
		COPY((yyval.expr),(yyvsp[(2) - (2)].expr));
		if ( (yyval.expr).type==EXPRTYPE_SIMPLE)  {
		  	COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		} else {
			if ( (yyval.expr).type==EXPRTYPE_COMPLEX ) {
				COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (2)].expr)); 
			} else {
				if ((yyval.expr).type==EXPRTYPE_COMPARE)  {
				COPY((yyval.expr).expr_u.cexpr->expr1,(yyvsp[(1) - (2)].expr)); 

				} else {
					printf("BAD -> %d\n", (yyval.expr).type);
				}
			}
		}
		e1=&(yyval.expr);
	}
    break;

  case 413:
#line 1555 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 414:
#line 1563 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 415:
#line 1571 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 416:
#line 1579 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 417:
#line 1586 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 418:
#line 1595 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 419:
#line 1601 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 420:
#line 1610 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 421:
#line 1617 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 422:
#line 1625 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 423:
#line 1631 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 424:
#line 1637 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 425:
#line 1643 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 426:
#line 1649 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 427:
#line 1655 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 428:
#line 1661 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 429:
#line 1667 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 430:
#line 1673 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 431:
#line 1679 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 432:
#line 1685 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 433:
#line 1693 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_SPACES; 
	}
    break;

  case 434:
#line 1700 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 435:
#line 1706 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 436:
#line 1714 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 437:
#line 1747 "ace.yacc"
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

  case 438:
#line 1758 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 439:
#line 1765 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
	}
    break;

  case 440:
#line 1772 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 441:
#line 1781 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_NULL;
	}
    break;

  case 442:
#line 1787 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 443:
#line 1791 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 444:
#line 1795 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 445:
#line 1799 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4875 "y.tab.c"
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


#line 1825 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

