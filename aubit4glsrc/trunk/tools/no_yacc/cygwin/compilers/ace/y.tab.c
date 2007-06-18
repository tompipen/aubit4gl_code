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
     SUM = 293,
     ATSIGN = 294,
     AVERAGE = 295,
     AVG = 296,
     BEFORE = 297,
     BETWEEN = 298,
     BOTTOM = 299,
     BY = 300,
     KW_CALL = 301,
     CH = 302,
     CHAR = 303,
     CHAR_VALUE = 304,
     CLOSE_BRACKET = 305,
     CLOSE_SQUARE = 306,
     COLON = 307,
     COMMANDS = 308,
     COUNT = 309,
     TOTAL = 310,
     DATABASE = 311,
     DATE = 312,
     TIME = 313,
     DATETIME = 314,
     DAY = 315,
     DECIMAL = 316,
     DEFINE = 317,
     DELIMITER = 318,
     DESC = 319,
     DISTINCT = 320,
     DO = 321,
     DOLLAR = 322,
     DOT = 323,
     ELSE = 324,
     END = 325,
     ESCAPE = 326,
     EVERY = 327,
     EXISTS = 328,
     EXTERNAL = 329,
     FIRST = 330,
     FLOAT = 331,
     PIPE = 332,
     FOR = 333,
     FORMAT = 334,
     FRACTION = 335,
     FROM = 336,
     FUNCTION = 337,
     GROUP = 338,
     GROUP_BY = 339,
     HAVING = 340,
     HEADER = 341,
     HOUR = 342,
     IF = 343,
     IN = 344,
     INPUT = 345,
     INTEGER = 346,
     INTERVAL = 347,
     INTO = 348,
     INTVAL = 349,
     KW_FALSE = 350,
     KW_TRUE = 351,
     LAST = 352,
     LEFT = 353,
     LENGTH = 354,
     LET = 355,
     LINES = 356,
     MARGIN = 357,
     MINUTE = 358,
     MONEY = 359,
     MONTH = 360,
     NAMED = 361,
     NEED = 362,
     NOT_EXISTS = 363,
     NOT_IN = 364,
     NUMBER_VALUE = 365,
     NUMERIC = 366,
     KW_OF = 367,
     ON = 368,
     OPEN_BRACKET = 369,
     OPEN_SQUARE = 370,
     ORDER_BY = 371,
     ORDER_EXTERNAL_BY = 372,
     OUTER = 373,
     OUTPUT = 374,
     PAGE = 375,
     PAGE_HEADER = 376,
     PAGE_TRAILER = 377,
     PARAM = 378,
     PAUSE = 379,
     PERCENT = 380,
     PRINT = 381,
     PRINTER = 382,
     PRINT_FILE = 383,
     PROMPT = 384,
     READ = 385,
     REPORT = 386,
     RIGHT = 387,
     ROW = 388,
     SECOND = 389,
     SELECT = 390,
     SEMICOLON = 391,
     SKIP = 392,
     SMALLFLOAT = 393,
     SMALLINT = 394,
     SOME = 395,
     STEP = 396,
     TEMP = 397,
     THEN = 398,
     TO = 399,
     TOP = 400,
     TOP_OF_PAGE = 401,
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
#define SUM 293
#define ATSIGN 294
#define AVERAGE 295
#define AVG 296
#define BEFORE 297
#define BETWEEN 298
#define BOTTOM 299
#define BY 300
#define KW_CALL 301
#define CH 302
#define CHAR 303
#define CHAR_VALUE 304
#define CLOSE_BRACKET 305
#define CLOSE_SQUARE 306
#define COLON 307
#define COMMANDS 308
#define COUNT 309
#define TOTAL 310
#define DATABASE 311
#define DATE 312
#define TIME 313
#define DATETIME 314
#define DAY 315
#define DECIMAL 316
#define DEFINE 317
#define DELIMITER 318
#define DESC 319
#define DISTINCT 320
#define DO 321
#define DOLLAR 322
#define DOT 323
#define ELSE 324
#define END 325
#define ESCAPE 326
#define EVERY 327
#define EXISTS 328
#define EXTERNAL 329
#define FIRST 330
#define FLOAT 331
#define PIPE 332
#define FOR 333
#define FORMAT 334
#define FRACTION 335
#define FROM 336
#define FUNCTION 337
#define GROUP 338
#define GROUP_BY 339
#define HAVING 340
#define HEADER 341
#define HOUR 342
#define IF 343
#define IN 344
#define INPUT 345
#define INTEGER 346
#define INTERVAL 347
#define INTO 348
#define INTVAL 349
#define KW_FALSE 350
#define KW_TRUE 351
#define LAST 352
#define LEFT 353
#define LENGTH 354
#define LET 355
#define LINES 356
#define MARGIN 357
#define MINUTE 358
#define MONEY 359
#define MONTH 360
#define NAMED 361
#define NEED 362
#define NOT_EXISTS 363
#define NOT_IN 364
#define NUMBER_VALUE 365
#define NUMERIC 366
#define KW_OF 367
#define ON 368
#define OPEN_BRACKET 369
#define OPEN_SQUARE 370
#define ORDER_BY 371
#define ORDER_EXTERNAL_BY 372
#define OUTER 373
#define OUTPUT 374
#define PAGE 375
#define PAGE_HEADER 376
#define PAGE_TRAILER 377
#define PARAM 378
#define PAUSE 379
#define PERCENT 380
#define PRINT 381
#define PRINTER 382
#define PRINT_FILE 383
#define PROMPT 384
#define READ 385
#define REPORT 386
#define RIGHT 387
#define ROW 388
#define SECOND 389
#define SELECT 390
#define SEMICOLON 391
#define SKIP 392
#define SMALLFLOAT 393
#define SMALLINT 394
#define SOME 395
#define STEP 396
#define TEMP 397
#define THEN 398
#define TO 399
#define TOP 400
#define TOP_OF_PAGE 401
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
#define YYLAST   3329

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  166
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  128
/* YYNRULES -- Number of rules.  */
#define YYNRULES  469
/* YYNRULES -- Number of states.  */
#define YYNSTATES  792

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
    1151,  1153,  1155,  1160,  1165,  1170,  1175,  1180,  1184,  1186,
    1189,  1192,  1194,  1196,  1198,  1200,  1202,  1204,  1209,  1214,
    1219,  1224,  1229,  1233,  1236,  1239,  1241,  1243,  1246,  1249,
    1252,  1255,  1258,  1261,  1264,  1267,  1270,  1272,  1275,  1278,
    1281,  1284,  1287,  1290,  1293,  1296,  1299,  1302,  1305,  1308,
    1311,  1314,  1317,  1320,  1323,  1326,  1329,  1332,  1334,  1336,
    1338,  1340,  1342,  1344,  1346,  1350,  1351,  1353,  1355,  1357
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     167,     0,    -1,   168,   169,   177,   181,   185,   189,    -1,
      56,     8,    70,    -1,    56,   106,    70,    -1,    -1,   170,
      -1,    62,   171,    70,    -1,   172,    -1,   171,   172,    -1,
       8,   174,    -1,   159,   175,   176,    -1,   123,   115,   278,
      51,   175,   176,    -1,    82,   173,    -1,   106,    -1,   175,
     176,    -1,   174,     4,   175,   176,    -1,   106,    -1,    82,
      -1,    91,    -1,    48,    -1,    48,   114,   278,    50,    -1,
     158,    -1,   158,   114,   278,    50,    -1,    57,    -1,    76,
      -1,   138,    -1,   139,    -1,    59,    -1,    92,    -1,   104,
      -1,   104,   114,   278,    50,    -1,   104,   114,   278,     4,
     278,    50,    -1,    61,    -1,    61,   114,   278,    50,    -1,
      61,   114,   278,     4,   278,    50,    -1,    -1,   178,    -1,
      90,   179,    70,    -1,   180,    -1,   179,   180,    -1,   129,
      78,   175,     5,   279,    -1,    -1,   182,    -1,   119,   183,
      70,    -1,   184,    -1,   183,   184,    -1,   131,   144,   127,
     279,    -1,   131,   144,   127,    -1,   131,   144,   279,    -1,
     131,   144,    77,   279,    -1,    98,   102,   278,    -1,    44,
     102,   278,    -1,   145,   102,   278,    -1,   120,    99,   278,
      -1,   132,   102,   278,    -1,   146,   279,    -1,   187,    70,
      -1,   186,    70,    -1,   241,    -1,   186,   136,   241,    -1,
     130,   279,   188,   195,    -1,    -1,    63,   279,    -1,    79,
      72,   133,    70,    -1,    79,   191,   190,    -1,    -1,    70,
      -1,   192,    -1,   191,   192,    -1,    75,   120,    86,   260,
      -1,   120,   147,   260,    -1,   120,    86,   260,    -1,   113,
      72,   133,   260,    -1,   113,    97,   133,   260,    -1,    42,
      83,   112,   194,   260,    -1,    33,    83,   112,   194,   260,
      -1,   106,   115,   287,     4,   287,    51,    -1,   106,   115,
     287,    51,    -1,   106,    -1,   193,    -1,    94,    -1,    -1,
     196,    -1,    -1,   116,   197,   201,    -1,   117,   201,    -1,
      49,    -1,   111,    -1,   240,    -1,    94,    -1,    -1,   116,
     200,   201,    -1,   202,    -1,   201,     4,   202,    -1,   203,
     204,    -1,    94,    -1,   238,    -1,    -1,    37,    -1,    64,
      -1,    85,   218,    -1,    84,   207,    -1,   252,    -1,   207,
       4,   252,    -1,     9,   218,    -1,    81,   210,    -1,   211,
      -1,   210,     4,   211,    -1,   212,    -1,   118,   212,    -1,
     118,   114,   213,    50,    -1,   234,    -1,   234,   239,    -1,
     211,    -1,   213,     4,   211,    -1,   209,   215,   216,   217,
      -1,    -1,   208,    -1,    -1,   206,    -1,    -1,   205,    -1,
     219,    -1,   218,    10,   219,    -1,   220,    -1,   219,    11,
     220,    -1,   221,    -1,    13,   221,    -1,   232,    -1,   114,
     218,    50,    -1,    73,   248,    -1,   108,   248,    -1,   254,
     231,   224,   248,    -1,   248,   231,   254,    -1,   225,    -1,
     226,    -1,    35,    -1,   140,    -1,    36,    -1,   254,    89,
     114,   228,    50,    -1,   254,    89,   248,    -1,   254,   109,
     114,   228,    50,    -1,   254,   109,   248,    -1,   259,    -1,
     228,     4,   259,    -1,    -1,    13,    -1,   254,   229,    14,
      -1,   254,   229,    15,    -1,   254,   231,   254,    -1,   254,
     231,   248,    -1,   254,   229,    43,   254,    11,   254,    -1,
      18,    -1,    16,    -1,    17,    -1,    20,    -1,    22,    -1,
      25,    -1,    23,    -1,    26,    -1,    24,    -1,    19,    -1,
      21,    -1,   230,    -1,   227,    -1,   223,    -1,   222,    -1,
      -1,    35,    -1,    65,    -1,   149,    -1,    49,    -1,   236,
      -1,   235,    52,   236,    -1,    49,    68,   236,    -1,   280,
      -1,   280,    -1,    -1,   115,    94,    51,    -1,   115,    94,
       4,    94,    51,    -1,   280,   237,    -1,   234,    68,   280,
     237,    -1,   234,    68,    30,    -1,   280,    -1,   110,    -1,
      68,    94,    -1,    -1,   135,   242,   249,   250,   214,   245,
      -1,   244,    -1,   135,   249,   250,   214,   245,    -1,    -1,
     148,   233,   243,    -1,   199,    -1,    93,   142,   247,   246,
      -1,   199,    93,   142,   247,   246,    -1,    -1,   161,    -1,
     280,    -1,   114,   135,   249,   250,   214,    50,    -1,    -1,
      35,    -1,    65,    -1,   149,    -1,   251,    -1,   250,     4,
     251,    -1,   254,    -1,   254,   106,    -1,   254,    -1,   155,
      -1,   153,    -1,   150,    -1,   151,    -1,   152,    -1,   154,
      -1,   254,   255,    -1,   198,    -1,   280,    -1,   280,   115,
     278,    51,    -1,   280,   115,   278,     4,   278,    51,    -1,
     280,    68,   280,   115,   278,    51,    -1,   280,    68,   280,
     115,   278,     4,   278,    51,    -1,    67,   280,    -1,   280,
      68,   280,    -1,   280,    68,    30,    -1,    96,    -1,    95,
      -1,   157,    -1,    30,    -1,   114,   254,    50,    -1,    57,
     114,   258,    50,    -1,    60,   114,   258,    50,    -1,   105,
     114,   258,    50,    -1,   165,   114,   258,    50,    -1,   280,
     114,   258,    50,    -1,    41,   114,   233,   254,    50,    -1,
     163,   114,   233,   254,    50,    -1,   164,   114,   233,   254,
      50,    -1,    38,   114,   233,   254,    50,    -1,    54,   114,
     233,   254,    50,    -1,    29,   256,    -1,    31,   256,    -1,
      32,   256,    -1,   253,    -1,    30,   256,    -1,    28,   256,
      -1,    27,   256,    -1,   257,   254,    -1,    -1,    28,    -1,
      27,    -1,   254,    -1,   258,     4,   254,    -1,   198,    -1,
     261,    -1,   260,   261,    -1,   264,    -1,   266,    -1,   277,
      -1,   268,    -1,   271,    -1,   272,    -1,   276,    -1,   273,
      -1,   275,    -1,   262,    -1,   162,   260,    70,    -1,    46,
     263,   114,   290,    50,    -1,    57,    -1,   105,    -1,   165,
      -1,    60,    -1,   280,    -1,    78,   175,    18,   287,   144,
     287,   265,    66,   261,    -1,    -1,   141,   287,    -1,    88,
     287,   143,   261,   267,    -1,    -1,    69,   261,    -1,   100,
     106,    18,   270,    -1,   100,   106,   115,   287,    51,    18,
     270,    -1,   100,   106,   115,   287,     4,   287,    51,    18,
     270,    -1,    -1,   270,    -1,   287,    -1,   270,     4,   287,
      -1,   107,   278,   101,    -1,   124,   279,    -1,   126,   269,
     274,    -1,    -1,   136,    -1,   128,   279,    -1,   137,   278,
     101,    -1,   137,   144,   146,    -1,   160,   287,    66,   261,
      -1,    94,    -1,    49,    -1,   106,    -1,   281,    -1,    33,
      -1,    37,    -1,    34,    -1,    42,    -1,    43,    -1,    44,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    12,
      -1,     7,    -1,    53,    -1,    16,    -1,    56,    -1,    59,
      -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,    66,
      -1,    69,    -1,    71,    -1,    72,    -1,    74,    -1,    75,
      -1,    76,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,    90,    -1,    97,    -1,    98,    -1,    99,
      -1,   100,    -1,    24,    -1,   101,    -1,   102,    -1,   103,
      -1,   104,    -1,   107,    -1,   112,    -1,   113,    -1,   119,
      -1,   120,    -1,   123,    -1,   124,    -1,    32,    -1,   127,
      -1,   129,    -1,   130,    -1,   131,    -1,   132,    -1,   133,
      -1,   134,    -1,   137,    -1,   138,    -1,   139,    -1,     6,
      -1,   141,    -1,   142,    -1,   143,    -1,   144,    -1,   145,
      -1,    55,    -1,   147,    -1,   156,    -1,   158,    -1,   159,
      -1,   160,    -1,   162,    -1,    -1,     9,   287,    -1,   285,
     282,    -1,   112,   286,    -1,    54,    -1,   125,    -1,    40,
     284,    -1,    55,   284,    -1,    41,   284,    -1,   164,   284,
      -1,   163,   284,    -1,    83,    54,    -1,    83,   125,    -1,
      83,    40,   284,    -1,    83,    55,   284,    -1,    83,    41,
     284,    -1,    83,   164,   284,    -1,    83,   163,   284,    -1,
      27,   286,    -1,   293,    -1,    96,    -1,    95,    -1,   157,
      -1,    57,    -1,    58,    -1,    57,   114,   291,    50,    -1,
     105,   114,   291,    50,    -1,   165,   114,   291,    50,    -1,
      60,   114,   291,    50,    -1,   106,   114,   291,    50,    -1,
     114,   287,    50,    -1,   193,    -1,   286,   288,    -1,    27,
     287,    -1,   293,    -1,    96,    -1,    95,    -1,   157,    -1,
      57,    -1,    58,    -1,    57,   114,   291,    50,    -1,   105,
     114,   291,    50,    -1,   165,   114,   291,    50,    -1,    60,
     114,   291,    50,    -1,   106,   114,   291,    50,    -1,   114,
     287,    50,    -1,     7,   287,    -1,     8,   287,    -1,   193,
      -1,   283,    -1,   287,   289,    -1,    11,   286,    -1,    10,
     286,    -1,    29,   286,    -1,    32,   286,    -1,    31,   286,
      -1,    30,   286,    -1,    28,   286,    -1,    27,   286,    -1,
      12,    -1,    11,   287,    -1,    10,   287,    -1,    29,   287,
      -1,    32,   287,    -1,    31,   287,    -1,    30,   287,    -1,
      28,   287,    -1,    27,   287,    -1,     5,   287,    -1,    18,
     287,    -1,    16,   287,    -1,    17,   287,    -1,    20,   287,
      -1,    22,   287,    -1,    25,   287,    -1,    23,   287,    -1,
      26,   287,    -1,    24,   287,    -1,    19,   287,    -1,    21,
     287,    -1,     6,    -1,    14,    -1,    15,    -1,    12,    -1,
     292,    -1,   291,    -1,   287,    -1,   291,     4,   287,    -1,
      -1,    49,    -1,   111,    -1,   240,    -1,    94,    -1
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
    1332,  1336,  1342,  1348,  1354,  1360,  1366,  1372,  1379,  1385,
    1391,  1397,  1403,  1409,  1415,  1425,  1443,  1445,  1449,  1453,
    1457,  1466,  1476,  1483,  1489,  1495,  1502,  1508,  1509,  1514,
    1536,  1554,  1556,  1560,  1564,  1568,  1577,  1587,  1594,  1600,
    1606,  1613,  1619,  1620,  1626,  1632,  1637,  1642,  1664,  1672,
    1679,  1687,  1694,  1703,  1710,  1719,  1726,  1735,  1743,  1750,
    1758,  1765,  1774,  1781,  1790,  1797,  1805,  1811,  1817,  1823,
    1829,  1835,  1841,  1847,  1853,  1859,  1865,  1873,  1880,  1886,
    1894,  1912,  1923,  1930,  1937,  1946,  1952,  1956,  1960,  1964
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
  "SUM", "ATSIGN", "AVERAGE", "AVG", "BEFORE", "BETWEEN", "BOTTOM", "BY",
  "KW_CALL", "CH", "CHAR", "CHAR_VALUE", "CLOSE_BRACKET", "CLOSE_SQUARE",
  "COLON", "COMMANDS", "COUNT", "TOTAL", "DATABASE", "DATE", "TIME",
  "DATETIME", "DAY", "DECIMAL", "DEFINE", "DELIMITER", "DESC", "DISTINCT",
  "DO", "DOLLAR", "DOT", "ELSE", "END", "ESCAPE", "EVERY", "EXISTS",
  "EXTERNAL", "FIRST", "FLOAT", "PIPE", "FOR", "FORMAT", "FRACTION",
  "FROM", "FUNCTION", "GROUP", "GROUP_BY", "HAVING", "HEADER", "HOUR",
  "IF", "IN", "INPUT", "INTEGER", "INTERVAL", "INTO", "INTVAL", "KW_FALSE",
  "KW_TRUE", "LAST", "LEFT", "LENGTH", "LET", "LINES", "MARGIN", "MINUTE",
  "MONEY", "MONTH", "NAMED", "NEED", "NOT_EXISTS", "NOT_IN",
  "NUMBER_VALUE", "NUMERIC", "KW_OF", "ON", "OPEN_BRACKET", "OPEN_SQUARE",
  "ORDER_BY", "ORDER_EXTERNAL_BY", "OUTER", "OUTPUT", "PAGE",
  "PAGE_HEADER", "PAGE_TRAILER", "PARAM", "PAUSE", "PERCENT", "PRINT",
  "PRINTER", "PRINT_FILE", "PROMPT", "READ", "REPORT", "RIGHT", "ROW",
  "SECOND", "SELECT", "SEMICOLON", "SKIP", "SMALLFLOAT", "SMALLINT",
  "SOME", "STEP", "TEMP", "THEN", "TO", "TOP", "TOP_OF_PAGE", "TRAILER",
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
  "of_expr", "aggregate_elem", "simple_fmt_val_expression",
  "fmt_val_expression", "simple_val_next", "val_next",
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
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   290,   290,   291,   291,   292,   293,   293,   293,   293
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
       1,     1,     4,     4,     4,     4,     4,     3,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     3,     2,     2,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     1,     1
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
       0,     0,   302,   303,   304,   305,   306,   307,   308,    87,
     311,     0,   370,   313,     0,   314,     0,   315,   316,   317,
     318,   319,     0,     0,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,    90,   226,   225,   337,   338,   339,   340,   342,   343,
     344,   345,     0,   297,   346,   185,    88,   347,   348,     0,
     349,   350,   351,   352,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   365,   366,   367,   368,   369,   371,
     372,   227,   373,   374,   375,   376,     0,     0,     0,   216,
      89,     0,   204,   206,   217,   298,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    65,    69,     0,     0,     0,
     172,    96,    86,    93,    98,     0,     0,   173,    97,   178,
     168,   168,   168,     0,     0,   222,   186,     0,     0,   168,
     168,     0,     0,     0,   117,   191,   248,   248,   248,   248,
     248,   248,   207,   211,   212,   213,   210,   214,   209,   243,
     215,     0,     0,     0,     0,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,     0,     0,     0,
       0,    72,   254,   265,   256,   257,   259,   260,   261,   263,
     264,   262,   258,    71,    35,    32,    85,     0,     0,    99,
     100,    95,     0,     0,     0,   181,   169,   170,   171,     0,
       0,     0,   251,     0,     0,     0,   229,     0,     0,     0,
     205,     0,   106,   107,   109,   112,   177,     0,   118,   119,
       0,    91,   168,   193,   188,   250,   249,   246,     0,   245,
     240,   244,   241,   242,   224,   223,     0,     0,    81,    79,
      80,     0,     0,    70,    73,    74,   268,   271,   269,   270,
       0,   272,     0,     0,     0,     0,     0,     0,   466,   381,
       0,   415,   416,     0,     0,   469,   413,   412,     0,    79,
     467,     0,   382,   414,     0,     0,     0,   425,   468,   426,
     377,     0,   411,     0,     0,   287,   289,   283,   284,   291,
       0,     0,     0,     0,   255,   175,   177,    94,   183,   178,
     174,     0,     0,     0,     0,     0,   230,   231,   232,     0,
       0,   233,     0,   110,     0,   113,   184,     0,     0,     0,
       0,   105,   123,   125,   127,   167,   166,   165,   164,   129,
       0,   146,     0,   120,   121,     0,     0,     0,     0,   247,
       0,   234,     0,   218,     0,    76,    75,   465,     0,   423,
     424,   410,     0,   383,   385,   384,     0,     0,     0,     0,
     388,     0,   389,     0,     0,     0,     0,     0,   387,   386,
       0,     0,   379,     0,   457,     0,     0,   460,   458,   459,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   427,     0,
       0,   286,   290,   288,     0,   293,   292,     0,   266,   182,
       0,   179,   238,   235,   239,   252,   236,   237,   114,     0,
     108,   128,     0,   131,   132,   200,     0,   146,     0,     0,
     154,   155,   153,   162,   156,   163,   157,   159,   161,   158,
     160,     0,   147,     0,     0,     0,     0,   102,   103,   208,
       0,   122,   116,   196,   198,    92,   200,   192,   189,     0,
       0,     0,     0,   463,     0,   462,   461,     0,     0,   400,
     401,     0,   398,   397,     0,    79,     0,   399,     0,   408,
     380,   396,     0,     0,   390,   392,   391,   394,   393,     0,
       0,   422,     0,   378,   445,   438,   437,   447,   448,   446,
     455,   449,   456,   450,   452,   454,   451,   453,   444,   443,
     439,   442,   441,   440,   277,   279,     0,   285,   294,     0,
       0,   111,     0,   130,   124,   126,   134,     0,   141,     0,
     143,   148,   149,     0,   137,   139,     0,   138,     0,   135,
     136,   151,   150,     0,   101,   197,   194,     0,   196,     0,
     220,   219,     0,    78,   267,     0,     0,   395,     0,     0,
       0,     0,     0,     0,     0,     0,   436,     0,     0,     0,
       0,     0,     0,   409,   417,   420,   418,   421,   419,     0,
     276,     0,     0,   180,   115,     0,   253,     0,   144,     0,
       0,   133,   104,     0,   195,     0,     0,   464,   274,     0,
       0,     0,     0,   407,     0,   429,   428,   435,   434,   430,
     433,   432,   431,   278,     0,     0,     0,     0,   140,   142,
       0,   191,   221,    77,     0,     0,   402,   405,   403,   406,
     404,     0,   280,   199,   145,   152,   190,   275,     0,     0,
     273,   281
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   255,   122,   123,   427,   391,   138,
     139,   259,   239,   373,   486,   262,   263,   264,   341,   601,
     483,   597,   368,   284,   362,   363,   364,   569,   285,   369,
     484,   602,   471,   472,   473,   474,   475,   476,   688,   689,
     690,   477,   737,   595,   478,   596,   479,   349,   365,   266,
     267,   345,   268,   465,   428,    70,    89,   607,   608,   374,
     696,   603,   480,   115,   241,   242,   598,   299,   352,   300,
     377,   378,   353,   738,   321,   322,   323,   400,   324,   775,
     325,   730,   326,   436,   437,   327,   328,   329,   553,   330,
     331,   332,    51,    85,   244,   245,   522,   429,   503,   430,
     630,   613,   723,   548,   614,   615,   616,   432
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -627
static const yytype_int16 yypact[] =
{
      -8,    16,   102,   123,   118,   122,  -627,    17,   114,  -627,
    -627,  -627,   112,   124,   117,   112,    14,  -627,   184,   213,
    -627,  -627,   337,  2856,  -627,  -627,   254,  2856,  -627,  -627,
     286,   -20,  -627,   -28,   121,  -627,   112,   237,  -627,  -627,
     239,  -627,  -627,  -627,  -627,   244,  -627,  -627,   252,  -627,
    -627,   314,  -627,   112,  -627,  -627,   267,   287,   293,   271,
     315,   319,   397,   435,  -627,   397,  -627,   369,    -9,   379,
    -627,  2856,   254,   254,   254,   254,   112,   446,   254,   254,
     254,   -15,   254,   254,  -627,  -627,  -627,  -627,   399,     6,
     195,  -627,  -627,   330,  -627,  -627,   417,    76,    82,   418,
    2856,   397,  -627,  -627,  -627,   397,   397,  -627,  -627,  -627,
     397,   -50,  -627,  -627,  -627,  1447,   388,   389,   341,   355,
     177,   -46,   100,  -627,  -627,  -627,   254,  -627,   254,  -627,
    -627,  -627,  -627,  -627,  -627,  -627,  -627,  1869,  -627,  -627,
    -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
     363,   364,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,   366,  -627,  -627,   370,  -627,   380,  -627,  -627,  -627,
    -627,  -627,  2594,   407,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,  -627,   392,  -627,  -627,  -627,  -627,  -627,  -627,  1447,
    -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,  -627,  -627,  -627,  -627,  -627,   393,   394,   404,  -627,
    -627,    43,  -627,    -1,    66,  -627,   390,   391,   423,   425,
     403,   405,  1728,  1728,  -627,  -627,  -627,   476,   487,  1869,
     471,  -627,   536,  -627,   290,   473,   490,  -627,  -627,   116,
      30,    30,    30,  1447,  1447,  -627,  -627,  1447,   460,    30,
      30,  1447,  1447,  2014,   535,   -38,   231,   231,   231,   231,
     231,   231,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,  2304,  1447,   254,   -37,   -37,  -627,  1728,  1728,  1728,
    1607,   112,  1735,   439,   254,   397,  1735,   397,   -19,  1735,
    1728,  1728,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,  -627,  -627,  1728,  -627,  -627,   536,  2594,  1869,  -627,
    -627,  -627,  2449,  2594,   452,  -627,  -627,  -627,  -627,  1447,
    1447,  1447,  2748,   165,   174,   207,  -627,  1447,  1447,   210,
    -627,  2159,   543,  -627,  -627,  2594,   496,   807,  -627,   465,
     408,  -627,    30,   458,  -627,  -627,  -627,  -627,  1447,  -627,
    -627,  -627,  -627,  -627,  -627,   437,   222,    77,  -627,   445,
    -627,  1728,  1728,  1728,  1728,  1728,  -627,  -627,  -627,  -627,
     447,  -627,   545,  1735,  1735,  1735,   453,   453,  -627,  -627,
     453,   455,  -627,   456,    36,  -627,  -627,  -627,   459,   246,
    -627,  1735,  -627,  -627,   453,   453,   461,  -627,  -627,  -627,
     563,  2818,  -627,    42,   478,  -627,   438,   573,  3231,  -627,
     440,   482,  2952,  1727,  -627,  -627,  -627,  -627,  -627,   469,
    -627,   152,   485,   493,  1606,  1447,  -627,  -627,  -627,  1671,
    2593,  -627,  2014,  -627,  2014,  -627,  -627,  1127,   477,   477,
     647,   575,   581,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    2796,   377,  1447,  -627,   508,  2594,  1869,   468,   454,  2748,
     254,  -627,   254,  -627,  1735,  1728,  1728,  1735,  1735,  3231,
    3231,   381,    25,  -627,  -627,  -627,  1735,  1735,   453,   453,
    -627,   453,  -627,   453,   453,  1735,  1735,  3157,  -627,  -627,
    1735,  1735,  -627,  1735,  -627,  1735,  1735,  -627,  -627,  -627,
    1735,  1735,  1735,  1735,  1735,  1735,  1735,  1735,  1735,  1735,
    1735,  1735,  1735,  1735,  1735,  1735,  1735,  1728,  -627,  1735,
    1735,  -627,  -627,  -627,  1735,  -627,  -627,  1728,  -627,  -627,
     500,  -627,  -627,  -627,  -627,  2748,  -627,  -627,  -627,   273,
    -627,  -627,   481,  -627,  -627,     6,   133,  2742,   807,   807,
    -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,  -627,
    -627,  1447,  -627,   486,   509,   251,   967,   621,  -627,  2748,
     807,  -627,  -627,   466,  -627,   536,     6,  -627,  -627,  2594,
     159,   579,  3005,  3231,   576,   624,  -627,  2779,    25,   517,
    -627,   518,  -627,  -627,   519,   248,  1735,  -627,   520,  -627,
    2012,  -627,   275,   279,  -627,  -627,  -627,  -627,  -627,   280,
     283,  -627,   318,  3254,  3231,  3276,  3297,  2857,  2857,  2857,
    2857,  2857,  2857,  2857,  2857,  2857,  2857,  2857,   381,   381,
     409,   409,  -627,  -627,   572,   573,  3043,  3231,  -627,   591,
    2014,  -627,  1447,  -627,   581,  -627,  2748,   170,  -627,   170,
    -627,  -627,  -627,  1447,  -627,  -627,  1287,  -627,   477,  -627,
    -627,  -627,  2748,  1447,   575,  -627,  -627,  1447,   466,   254,
    -627,  -627,  1735,  -627,  -627,  1735,  1735,   467,  1735,  1735,
    1735,  1735,  3194,  1735,    25,    25,  -627,    25,    25,    25,
      25,    25,    25,  -627,  -627,  -627,  -627,  -627,  -627,  1728,
    -627,  1735,   631,  -627,  -627,    43,  -627,   320,  -627,   331,
     166,  -627,  -627,    43,  -627,   599,  3081,  3231,  2847,   332,
     333,   334,   335,  -627,   338,   577,   590,   467,   467,   413,
     413,  -627,  -627,  -627,  3119,  1735,   601,   201,  -627,  -627,
    1447,   -38,  -627,  -627,  1735,   595,  -627,  -627,  -627,  -627,
    -627,   638,   573,  -627,  -627,  2748,  -627,  3231,  1728,  1735,
    -627,   573
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -627,  -627,  -627,  -627,  -627,  -627,   641,  -627,  -627,    -4,
       8,  -627,  -627,  -627,   633,  -627,  -627,  -627,   602,  -627,
    -627,  -627,  -627,  -627,  -627,  -627,   540,  -261,   361,  -627,
    -627,  -627,  -626,  -627,  -627,  -241,   340,  -627,  -627,  -627,
    -627,  -627,  -627,  -627,  -627,  -447,   307,  -627,  -496,  -627,
    -627,  -627,  -456,    91,    93,   203,  -627,  -627,  -627,  -627,
    -627,  -627,    -6,  -627,  -627,   196,  -627,  -234,  -130,  -627,
    -116,   226,  -627,  -627,  -115,   593,  -627,  -627,  -627,   -88,
     -11,    88,  -448,  -415,  -363,   416,    12,  -627,   -96,  -627,
      56,  -627,    29,   -68,  -220,  -279,  -627,  -627,  -627,  -627,
    -627,  -627,  -627,  -627,  -543,  -627,  -627,  -627,  -627,  -627,
    -627,  -627,   -70,   -42,  -136,  -627,  -627,  -627,    45,  -627,
    -342,  -107,  -627,  -627,  -627,  -409,  -627,  -429
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -178
static const yytype_int16 yytable[] =
{
     240,   269,    96,    97,    98,    99,   665,   265,   102,   103,
     104,    27,   108,   109,   576,   568,    56,   570,   336,   243,
     573,   574,    12,    88,     4,    12,   286,   287,   288,   289,
     290,   291,    71,   333,    84,    52,   275,   350,   351,   107,
     252,   112,   444,   390,   390,   357,   358,   282,     1,    77,
      54,   736,   618,   736,   444,   370,   257,   388,   258,   132,
     549,    92,   105,   133,   134,   346,   136,   137,   135,   389,
      57,   113,   100,   631,   408,    50,   508,   509,   371,    95,
     126,   492,   619,   620,    28,   621,   128,   393,   394,   395,
     510,   511,    58,   173,   240,   347,    13,   632,   633,    13,
     443,   253,     6,    59,    60,   292,   639,   640,   131,    30,
     372,   642,   106,   278,   444,   444,   444,    61,    62,   415,
     622,   623,     5,   269,   283,   440,   127,    93,   493,   265,
     624,   625,   129,   116,   301,   205,   420,    14,   487,   626,
      14,   736,   117,   578,   694,   678,   680,   366,   691,   293,
     294,   295,   296,   297,   298,   114,   560,   550,   240,   240,
     672,   512,   240,   699,   444,   385,   240,   240,  -176,   455,
     254,   495,   496,    15,   401,   119,    15,   770,   455,   348,
     302,   303,   627,   673,  -177,     7,   243,   240,    10,   631,
     628,   697,    11,   286,   287,   288,   289,   290,   291,   513,
     514,   446,   269,   561,    18,   431,   449,   446,   265,   438,
     700,   455,   442,   120,   455,   456,   444,   444,    21,   159,
     121,   445,   782,   734,   457,   366,   455,   450,   116,   466,
      24,   344,    26,   387,   240,   240,   240,   117,   173,   766,
     741,   629,   240,   240,   434,   605,   791,   771,   441,   250,
     159,    65,   240,   452,   453,   454,    66,   458,   375,   376,
     461,   459,   460,   240,   191,   681,   682,   118,   664,   173,
     119,   481,   491,   435,   251,   439,   707,   670,   668,   705,
     205,   206,   489,   705,   705,   631,   631,   705,   631,   631,
     631,   631,   631,   631,   683,   191,   499,   500,   501,   749,
     750,   751,   752,   354,   754,   575,   355,   402,   120,   735,
     359,   205,   206,    30,   517,   121,   293,   294,   295,   296,
     297,   298,   705,   671,   767,   724,   366,   339,   366,   725,
     726,   386,    33,   727,   743,   767,   705,   705,   705,   705,
     240,    36,   705,   379,   380,   381,   382,   383,    50,   604,
     269,    72,   240,    73,   340,   240,   265,   629,    74,   565,
     516,   494,   711,   494,    53,    76,    75,   240,   728,    78,
     768,   481,   755,   756,   577,   757,   758,   759,   760,   761,
     762,   769,   776,   777,   778,   779,   599,   612,   780,    79,
     592,   617,    80,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   286,   287,   288,   289,   290,   291,
     543,   544,   545,   546,   643,    81,   644,    82,   645,   646,
     610,    83,   611,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     545,   546,   438,   666,   721,   722,    84,   667,    90,    94,
     763,   101,   504,   629,   629,   505,   629,   629,   629,   629,
     629,   629,   110,   240,   240,    66,   593,   125,   130,   518,
     519,   246,   247,   604,   248,   249,   240,   270,   271,    56,
     272,   240,   481,   481,   273,   240,   594,   286,   287,   288,
     289,   290,   291,   306,   274,   676,   719,   720,   721,   722,
     692,   276,   304,   305,   481,    86,   277,   279,   280,   790,
     356,   307,   286,   287,   288,   289,   290,   291,   281,   712,
     286,   287,   288,   289,   290,   291,   334,   293,   294,   295,
     296,   297,   298,    57,   366,   562,   308,   335,   309,   337,
     338,   342,   343,   563,   367,   433,   451,   464,  -176,   482,
     485,   488,   490,   634,   635,    58,   636,   240,   637,   638,
     494,   497,   240,   498,   240,   502,    59,    60,   240,   506,
     507,   240,   521,   515,   552,   520,   243,   554,   240,   551,
      61,    62,   240,   556,   344,   578,   555,   740,   715,   716,
     278,   572,   579,   600,   669,   746,   609,   599,   747,   748,
     677,   243,   716,   606,   717,   718,   719,   720,   721,   722,
     293,   294,   295,   296,   297,   298,   575,   717,   718,   719,
     720,   721,   722,   679,   764,   693,   704,   695,   705,   745,
     701,   708,   709,   710,   713,   293,   294,   295,   296,   297,
     298,   729,   733,   293,   294,   295,   296,   297,   298,   765,
     772,   783,   240,   140,   141,   240,   789,    29,   438,   142,
     467,   788,   256,   143,    55,    87,   392,   787,   463,   674,
     571,   144,   675,   739,   785,   559,   591,   145,   447,   146,
     147,   148,   438,   786,   149,   150,   124,   744,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   698,   360,   784,
     160,   161,   162,   163,   164,   742,   165,   166,   167,   168,
     169,   170,     0,   171,   172,   173,   174,     0,   175,   176,
     468,   177,   178,   179,     0,   180,   181,   182,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   469,     0,   205,   206,   207,
     208,   470,     0,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,   575,     0,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,   234,     0,   235,
     236,   237,   238,   140,   141,     0,     0,     0,     0,   142,
     467,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,     0,     0,   149,   150,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,     0,     0,
     160,   161,   162,   163,   164,     0,   165,   166,   167,   168,
     169,   170,     0,   171,   172,   173,   174,     0,   175,   176,
     468,   177,   178,   179,     0,   180,   181,   182,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   469,     0,   205,   206,   207,
     208,   470,     0,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,     0,     0,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,   234,     0,   235,
     236,   237,   238,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,   684,   685,   149,   150,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,     0,     0,
     160,   161,   162,   163,   164,     0,   165,   166,   167,   168,
     169,   170,     0,   171,   172,   173,   174,     0,   175,   176,
       0,   177,   178,   179,     0,   180,   181,   182,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   686,     0,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,     0,     0,   221,   222,   223,   687,   224,   225,
     226,   227,   228,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,   234,     0,   235,
     236,   237,   238,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,     0,     0,   149,   150,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,     0,     0,
     160,   161,   162,   163,   164,     0,   165,   166,   167,   168,
     169,   170,     0,   171,   172,   173,   174,     0,   175,   176,
     468,   177,   178,   179,     0,   180,   181,   182,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   469,     0,   205,   206,   207,
     208,   470,     0,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,     0,     0,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,   234,     0,   235,
     236,   237,   238,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,     0,     0,   149,   150,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,     0,     0,
     160,   161,   162,   163,   164,     0,   165,   166,   167,   168,
     169,   170,     0,   171,   172,   173,   174,     0,   175,   176,
       0,   177,   178,   179,     0,   180,   181,   182,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   209,     0,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,   575,     0,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,   234,     0,   235,
     236,   237,   238,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,     0,     0,   149,   150,     0,     0,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,     0,     0,
     160,   161,   162,   163,   164,     0,   165,   166,   167,   168,
     169,   170,     0,   171,   172,   173,   174,     0,   175,   176,
       0,   177,   178,   179,     0,   180,   181,   182,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,     0,     0,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   209,     0,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,     0,     0,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,   234,     0,   235,
     236,   237,   238,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,   286,   287,   288,   289,   290,   291,   146,
     147,   148,     0,     0,   149,     0,     0,     0,     0,   152,
     153,   154,   155,   156,   157,   158,   564,     0,     0,     0,
     160,     0,   162,   163,   396,     0,   165,   397,   167,   168,
     169,   170,     0,   171,     0,     0,   174,     0,   175,   176,
       0,   177,   178,   179,     0,   180,   181,   182,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,   286,   287,
     288,   289,   290,   291,   194,   195,   196,   197,   198,   199,
     200,   201,   398,   203,   204,     0,     0,     0,     0,   207,
     208,   566,     0,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,   403,   404,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,   293,   294,   295,   296,
     297,   298,   405,   230,     0,   232,   233,   234,     0,   235,
       0,     0,   399,   310,   310,   406,   407,     0,     0,     0,
       0,     0,     0,     0,   408,     0,     0,     0,     0,   409,
     410,     0,   411,   412,     0,   413,     0,   558,     0,     0,
       0,     0,     0,   173,     0,   311,   311,     0,     0,     0,
       0,     0,     0,     0,     0,   312,   312,     0,   414,     0,
       0,   293,   294,   295,   296,   297,   298,   313,   313,   415,
     416,   417,     0,     0,   314,   314,     0,     0,     0,     0,
     418,   419,     0,     0,     0,   205,   420,     0,     0,   421,
       0,   315,   315,   316,   316,   317,   317,     0,     0,     0,
     422,     0,     0,     0,   318,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,     0,     0,     0,
       0,   142,     0,     0,     0,   143,     0,   319,   319,   320,
     320,     0,   423,   144,     0,     0,     0,     0,   424,   425,
     426,   146,   147,   148,     0,     0,   149,     0,     0,     0,
       0,   152,   153,   154,   155,   156,   157,   158,   260,     0,
       0,     0,   160,     0,   162,   163,     0,     0,   165,     0,
     167,   168,   169,   170,     0,   171,     0,     0,   174,     0,
     175,   176,     0,   177,   178,   179,     0,   180,   181,   182,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
       0,     0,     0,   261,     0,     0,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   203,   204,     0,     0,     0,
       0,   207,   208,     0,     0,     0,     0,     0,   210,   211,
       0,     0,   212,   213,     0,     0,   214,     0,   215,   216,
     217,   218,   219,   220,     0,     0,   221,   222,   223,     0,
     224,   225,   226,   227,   228,     0,   229,     0,     0,     0,
     140,   141,   714,   715,   716,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,   717,
     718,   719,   720,   721,   722,     0,   146,   147,   148,     0,
       0,   149,     0,     0,     0,     0,   152,   153,   154,   155,
     156,   157,   158,   260,     0,     0,     0,   160,     0,   162,
     163,     0,     0,   165,     0,   167,   168,   169,   170,     0,
     171,     0,     0,   174,     0,   175,   176,     0,   177,   178,
     179,     0,   180,   181,   182,   183,   184,   185,     0,     0,
     186,   187,   188,   189,   190,     0,     0,     0,     0,     0,
       0,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     203,   204,     0,     0,     0,     0,   207,   208,     0,     0,
       0,     0,   361,   210,   211,     0,     0,   212,   213,     0,
       0,   214,     0,   215,   216,   217,   218,   219,   220,     0,
       0,   221,   222,   223,     0,   224,   225,   226,   227,   228,
       0,   229,     0,     0,     0,   140,   141,     0,     0,     0,
     230,   142,   232,   233,   234,   143,   235,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,     0,     0,   149,     0,     0,     0,
       0,   152,   153,   154,   155,   156,   157,   158,   260,     0,
       0,     0,   160,     0,   162,   163,     0,     0,   165,     0,
     167,   168,   169,   170,     0,   171,     0,     0,   174,     0,
     175,   176,     0,   177,   178,   179,     0,   180,   181,   182,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
       0,     0,     0,     0,     0,     0,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   203,   204,     0,     0,     0,
       0,   207,   208,   462,     0,     0,     0,     0,   210,   211,
       0,     0,   212,   213,     0,     0,   214,     0,   215,   216,
     217,   218,   219,   220,     0,     0,   221,   222,   223,     0,
     224,   225,   226,   227,   228,     0,   229,     0,     0,     0,
     140,   141,     0,     0,     0,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,   384,     0,   146,   147,   148,     0,
       0,   149,     0,     0,     0,     0,   152,   153,   154,   155,
     156,   157,   158,     0,     0,     0,     0,   160,     0,   162,
     163,     0,     0,   165,     0,   167,   168,   169,   170,     0,
     171,     0,     0,   174,     0,   175,   176,     0,   177,   178,
     179,     0,   180,   181,   182,   183,   184,   185,     0,     0,
     186,   187,   188,   189,   190,     0,     0,     0,     0,     0,
       0,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     203,   204,     0,     0,     0,     0,   207,   208,     0,     0,
       0,     0,     0,   210,   211,     0,     0,   212,   213,     0,
       0,   214,     0,   215,   216,   217,   218,   219,   220,     0,
       0,   221,   222,   223,     0,   224,   225,   226,   227,   228,
       0,   229,     0,     0,     0,   140,   141,     0,     0,     0,
     230,   142,   232,   233,   234,   143,   235,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,   448,
       0,   146,   147,   148,     0,     0,   149,     0,     0,     0,
       0,   152,   153,   154,   155,   156,   157,   158,     0,     0,
       0,     0,   160,     0,   162,   163,     0,     0,   165,     0,
     167,   168,   169,   170,     0,   171,     0,     0,   174,     0,
     175,   176,     0,   177,   178,   179,     0,   180,   181,   182,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
       0,     0,     0,     0,     0,     0,   194,   195,   196,   197,
     198,   199,   200,   201,     0,   203,   204,     0,     0,     0,
       0,   207,   208,     0,     0,     0,     0,     0,   210,   211,
       0,     0,   212,   213,     0,     0,   214,     0,   215,   216,
     217,   218,   219,   220,     0,     0,   221,   222,   223,     0,
     224,   225,   226,   227,   228,     0,   229,     0,     0,     0,
     140,   141,     0,     0,     0,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,     0,
     286,   287,   288,   289,   290,   291,   146,   147,   148,     0,
       0,   149,     0,     0,     0,     0,   152,   153,   154,   155,
     156,   157,   158,   567,     0,     0,     0,   160,     0,   162,
     163,     0,     0,   165,     0,   167,   168,   169,   170,     0,
     171,     0,     0,   174,     0,   175,   176,     0,   177,   178,
     179,     0,   180,   181,   182,   183,   184,   185,     0,     0,
     186,   187,   188,   189,   190,     0,     0,     0,     0,     0,
       0,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     203,   204,     0,     0,     0,     0,   207,   208,     0,     0,
       0,     0,     0,   210,   211,     0,     0,   212,   213,     0,
       0,   214,     0,   215,   216,   217,   218,   219,   220,     0,
       0,   221,   222,   223,     0,   224,   225,   226,   227,   228,
       0,   229,     0,   293,   294,   295,   296,   297,   298,     0,
     230,     0,   232,   233,   234,   592,   235,     0,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   286,
     287,   288,   289,   290,   291,   286,   287,   288,   289,   290,
     291,     0,     0,     0,   523,   524,     0,     0,     0,   525,
     526,   527,   356,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   523,   524,     0,     0,     0,   525,   526,
     527,   593,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   594,   523,   524,     0,     0,     0,   525,   526,   527,
       0,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
       0,     0,   293,   294,   295,   296,   297,   298,   293,   294,
     295,   296,   297,   298,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    40,     0,     0,
       0,     0,     0,   706,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,     0,   523,   524,     0,
      45,   547,   525,   526,   527,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,     0,     0,     0,   774,     0,
       0,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   702,
     523,   524,     0,     0,    48,   525,   526,   527,   557,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   731,   523,   524,
       0,     0,     0,   525,   526,   527,   703,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,   524,     0,     0,
       0,   525,   526,   527,   732,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   523,   524,     0,     0,     0,   525,
     526,   527,   773,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,   524,     0,     0,     0,   525,   526,   527,
     781,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   523,
     524,     0,     0,     0,   525,   526,   527,   641,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,   524,     0,     0,
       0,   525,   526,   527,   753,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   525,   526,   527,     0,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   526,   527,     0,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   527,
       0,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546
};

static const yytype_int16 yycheck[] =
{
     115,   137,    72,    73,    74,    75,   549,   137,    78,    79,
      80,    15,    82,    83,   470,   462,    44,   464,   259,   115,
     468,   469,     8,    65,     8,     8,    27,    28,    29,    30,
      31,    32,    36,   253,    49,    27,   172,   271,   272,    81,
      86,    35,   321,   304,   305,   279,   280,     4,    56,    53,
      70,   677,    27,   679,   333,    93,   126,    94,   128,   101,
      18,    70,    77,   105,   106,    35,   116,   117,   110,   106,
      98,    65,    76,   502,    49,    94,    40,    41,   116,    71,
       4,     4,    57,    58,    70,    60,     4,   307,   308,   309,
      54,    55,   120,    68,   209,    65,    82,   506,   507,    82,
     320,   147,     0,   131,   132,   106,   515,   516,   100,   129,
     148,   520,   127,   209,   393,   394,   395,   145,   146,    94,
      95,    96,   106,   259,    81,   144,    50,   136,    51,   259,
     105,   106,    50,    33,    68,   110,   111,   123,   372,   114,
     123,   767,    42,    10,   600,   593,   594,   283,   596,   150,
     151,   152,   153,   154,   155,   149,     4,   115,   273,   274,
     575,   125,   277,     4,   443,   301,   281,   282,    52,     4,
      70,   391,   392,   159,   310,    75,   159,    11,     4,   149,
     114,   115,   157,    50,    68,    62,   282,   302,    70,   618,
     165,   606,    70,    27,    28,    29,    30,    31,    32,   163,
     164,   337,   338,    51,    90,   312,   342,   343,   338,   316,
      51,     4,   319,   113,     4,    50,   495,   496,   106,    49,
     120,   337,   765,   670,    50,   361,     4,   343,    33,   365,
     106,   115,   115,   303,   349,   350,   351,    42,    68,   735,
     688,   502,   357,   358,   314,   486,   789,   743,   318,    72,
      49,   130,   367,   349,   350,   351,   135,    50,    27,    28,
      50,   357,   358,   378,    94,    14,    15,    72,   547,    68,
      75,   367,    50,   315,    97,   317,   618,     4,   557,     4,
     110,   111,   378,     4,     4,   714,   715,     4,   717,   718,
     719,   720,   721,   722,    43,    94,   403,   404,   405,   708,
     709,   710,   711,   274,   713,   135,   277,   311,   113,   672,
     281,   110,   111,   129,   421,   120,   150,   151,   152,   153,
     154,   155,     4,    50,     4,    50,   462,    37,   464,    50,
      50,   302,   119,    50,   697,     4,     4,     4,     4,     4,
     455,     4,     4,   287,   288,   289,   290,   291,    94,   485,
     486,   114,   467,   114,    64,   470,   486,   618,   114,   455,
     114,   115,   114,   115,    78,    51,   114,   482,    50,   102,
      50,   467,   714,   715,   470,   717,   718,   719,   720,   721,
     722,    50,    50,    50,    50,    50,   482,   494,    50,   102,
      13,   498,    99,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      29,    30,    31,    32,   521,   144,   523,   102,   525,   526,
     490,   102,   492,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
      31,    32,   549,   550,    31,    32,    49,   554,    79,    70,
     729,     5,   407,   714,   715,   410,   717,   718,   719,   720,
     721,   722,    63,   578,   579,   135,    89,    50,    50,   424,
     425,    83,    83,   609,   133,   120,   591,   114,   114,    44,
     114,   596,   578,   579,   114,   600,   109,    27,    28,    29,
      30,    31,    32,    70,   114,   591,    29,    30,    31,    32,
     596,    94,   112,   112,   600,    70,   114,   114,   114,   788,
      50,    86,    27,    28,    29,    30,    31,    32,   114,   626,
      27,    28,    29,    30,    31,    32,    50,   150,   151,   152,
     153,   154,   155,    98,   670,    50,   133,    50,   133,    68,
       4,    68,    52,    50,     9,   106,    94,     4,    52,    84,
     142,    93,   115,   508,   509,   120,   511,   672,   513,   514,
     115,   114,   677,    18,   679,   112,   131,   132,   683,   114,
     114,   686,     9,   114,   136,   114,   672,     4,   693,   101,
     145,   146,   697,   101,   115,    10,   146,   683,    11,    12,
     686,   114,    11,    85,    94,   702,   142,   693,   705,   706,
     114,   697,    12,   135,    27,    28,    29,    30,    31,    32,
     150,   151,   152,   153,   154,   155,   135,    27,    28,    29,
      30,    31,    32,   114,   731,     4,    50,   161,     4,   699,
      51,   114,   114,   114,   114,   150,   151,   152,   153,   154,
     155,    69,    51,   150,   151,   152,   153,   154,   155,    18,
      51,    50,   767,     6,     7,   770,    18,    16,   765,    12,
      13,    66,   122,    16,    31,    63,   305,   774,   361,   578,
     467,    24,   579,   679,   770,   449,   480,    30,   338,    32,
      33,    34,   789,   771,    37,    38,    93,   698,    41,    42,
      43,    44,    45,    46,    47,    48,    49,   609,   282,   767,
      53,    54,    55,    56,    57,   693,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,    -1,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,    -1,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    71,    72,
      -1,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,    -1,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,   139,   140,   141,   142,
     143,   144,   145,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,    -1,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    71,    72,
      -1,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,    -1,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,   135,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    -1,    71,    72,
      -1,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,   110,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,    -1,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,    -1,    -1,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,    -1,   162,
     163,   164,   165,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    27,    28,    29,    30,    31,    32,    32,
      33,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    50,    -1,    -1,    -1,
      53,    -1,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    64,    -1,    66,    -1,    -1,    69,    -1,    71,    72,
      -1,    74,    75,    76,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    86,    87,    88,    89,    90,    27,    28,
      29,    30,    31,    32,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,    50,    -1,    -1,    -1,    -1,   119,   120,    -1,    -1,
     123,   124,    -1,    -1,   127,    -1,   129,   130,   131,   132,
     133,   134,     7,     8,   137,   138,   139,    -1,   141,   142,
     143,   144,   145,    -1,   147,    -1,   150,   151,   152,   153,
     154,   155,    27,   156,    -1,   158,   159,   160,    -1,   162,
      -1,    -1,   165,    46,    46,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    54,
      55,    -1,    57,    58,    -1,    60,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    78,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    88,    -1,    83,    -1,
      -1,   150,   151,   152,   153,   154,   155,   100,   100,    94,
      95,    96,    -1,    -1,   107,   107,    -1,    -1,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,    -1,    -1,   114,
      -1,   124,   124,   126,   126,   128,   128,    -1,    -1,    -1,
     125,    -1,    -1,    -1,   137,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    16,    -1,   160,   160,   162,
     162,    -1,   157,    24,    -1,    -1,    -1,    -1,   163,   164,
     165,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    55,    56,    -1,    -1,    59,    -1,
      61,    62,    63,    64,    -1,    66,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,    -1,   123,   124,    -1,    -1,   127,    -1,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,    -1,    -1,    -1,
       6,     7,    10,    11,    12,   156,    12,   158,   159,   160,
      16,   162,    -1,    -1,    -1,    -1,    -1,    -1,    24,    27,
      28,    29,    30,    31,    32,    -1,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,    55,
      56,    -1,    -1,    59,    -1,    61,    62,    63,    64,    -1,
      66,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
      -1,    -1,   118,   119,   120,    -1,    -1,   123,   124,    -1,
      -1,   127,    -1,   129,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
     156,    12,   158,   159,   160,    16,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    55,    56,    -1,    -1,    59,    -1,
      61,    62,    63,    64,    -1,    66,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,    -1,    -1,    -1,    -1,   119,   120,
      -1,    -1,   123,   124,    -1,    -1,   127,    -1,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,   156,    12,   158,   159,   160,
      16,   162,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    53,    -1,    55,
      56,    -1,    -1,    59,    -1,    61,    62,    63,    64,    -1,
      66,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
      -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,    -1,
      -1,   127,    -1,   129,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
     156,    12,   158,   159,   160,    16,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    -1,    53,    -1,    55,    56,    -1,    -1,    59,    -1,
      61,    62,    63,    64,    -1,    66,    -1,    -1,    69,    -1,
      71,    72,    -1,    74,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,    -1,    -1,    -1,    -1,    -1,   119,   120,
      -1,    -1,   123,   124,    -1,    -1,   127,    -1,   129,   130,
     131,   132,   133,   134,    -1,    -1,   137,   138,   139,    -1,
     141,   142,   143,   144,   145,    -1,   147,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,   156,    12,   158,   159,   160,
      16,   162,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      27,    28,    29,    30,    31,    32,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    50,    -1,    -1,    -1,    53,    -1,    55,
      56,    -1,    -1,    59,    -1,    61,    62,    63,    64,    -1,
      66,    -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
      -1,    -1,    -1,   119,   120,    -1,    -1,   123,   124,    -1,
      -1,   127,    -1,   129,   130,   131,   132,   133,   134,    -1,
      -1,   137,   138,   139,    -1,   141,   142,   143,   144,   145,
      -1,   147,    -1,   150,   151,   152,   153,   154,   155,    -1,
     156,    -1,   158,   159,   160,    13,   162,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    50,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    89,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   109,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,   150,   151,   152,   153,   154,   155,   150,   151,
     152,   153,   154,   155,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,
     104,   143,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,   141,    -1,
      -1,    -1,    -1,    -1,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,    -1,    -1,   158,    10,    11,    12,    66,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    12,    51,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    51,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    51,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      51,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    50,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    50,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    56,   167,   168,     8,   106,     0,    62,   169,   170,
      70,    70,     8,    82,   123,   159,   171,   172,    90,   177,
     178,   106,   174,   175,   106,   173,   115,   175,    70,   172,
     129,   179,   180,   119,   181,   182,     4,    48,    57,    59,
      61,    76,    82,    91,    92,   104,   138,   139,   158,   176,
      94,   278,   176,    78,    70,   180,    44,    98,   120,   131,
     132,   145,   146,   183,   184,   130,   135,   185,   186,   187,
     241,   175,   114,   114,   114,   114,    51,   175,   102,   102,
      99,   144,   102,   102,    49,   279,    70,   184,   279,   242,
      79,   189,    70,   136,    70,   176,   278,   278,   278,   278,
     175,     5,   278,   278,   278,    77,   127,   279,   278,   278,
      63,   188,    35,    65,   149,   249,    33,    42,    72,    75,
     113,   120,   191,   192,   241,    50,     4,    50,     4,    50,
      50,   176,   279,   279,   279,   279,   116,   117,   195,   196,
       6,     7,    12,    16,    24,    30,    32,    33,    34,    37,
      38,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      53,    54,    55,    56,    57,    59,    60,    61,    62,    63,
      64,    66,    67,    68,    69,    71,    72,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    86,    87,    88,    89,
      90,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   110,   111,   112,   113,   114,
     119,   120,   123,   124,   127,   129,   130,   131,   132,   133,
     134,   137,   138,   139,   141,   142,   143,   144,   145,   147,
     156,   157,   158,   159,   160,   162,   163,   164,   165,   198,
     240,   250,   251,   254,   280,   281,    83,    83,   133,   120,
      72,    97,    86,   147,    70,   190,   192,   278,   278,   197,
      49,    94,   201,   202,   203,   234,   235,   236,   238,   280,
     114,   114,   114,   114,   114,   280,    94,   114,   254,   114,
     114,   114,     4,    81,   209,   214,    27,    28,    29,    30,
      31,    32,   106,   150,   151,   152,   153,   154,   155,   253,
     255,    68,   114,   115,   112,   112,    70,    86,   133,   133,
      46,    78,    88,   100,   107,   124,   126,   128,   137,   160,
     162,   260,   261,   262,   264,   266,   268,   271,   272,   273,
     275,   276,   277,   260,    50,    50,   201,    68,     4,    37,
      64,   204,    68,    52,   115,   237,    35,    65,   149,   233,
     233,   233,   254,   258,   258,   258,    50,   233,   233,   258,
     251,   118,   210,   211,   212,   234,   280,     9,   208,   215,
      93,   116,   148,   199,   245,    27,    28,   256,   257,   256,
     256,   256,   256,   256,    30,   280,   258,   278,    94,   106,
     193,   194,   194,   260,   260,   260,    57,    60,   105,   165,
     263,   280,   175,     7,     8,    27,    40,    41,    49,    54,
      55,    57,    58,    60,    83,    94,    95,    96,   105,   106,
     111,   114,   125,   157,   163,   164,   165,   193,   240,   283,
     285,   287,   293,   106,   278,   279,   269,   270,   287,   279,
     144,   278,   287,   260,   261,   236,   280,   202,    30,   280,
     236,    94,   254,   254,   254,     4,    50,    50,    50,   254,
     254,    50,   114,   212,     4,   239,   280,    13,    73,   108,
     114,   218,   219,   220,   221,   222,   223,   227,   230,   232,
     248,   254,    84,   206,   216,   142,   200,   233,    93,   254,
     115,    50,     4,    51,   115,   260,   260,   114,    18,   287,
     287,   287,   112,   284,   284,   284,   114,   114,    40,    41,
      54,    55,   125,   163,   164,   114,   114,   287,   284,   284,
     114,     9,   282,     5,     6,    10,    11,    12,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   143,   289,    18,
     115,   101,   136,   274,     4,   146,   101,    66,    70,   237,
       4,    51,    50,    50,    50,   254,    50,    50,   211,   213,
     211,   221,   114,   248,   248,   135,   218,   254,    10,    11,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   231,    13,    89,   109,   229,   231,   207,   252,   254,
      85,   205,   217,   247,   280,   201,   135,   243,   244,   142,
     278,   278,   287,   287,   290,   291,   292,   287,    27,    57,
      58,    60,    95,    96,   105,   106,   114,   157,   165,   193,
     286,   293,   291,   291,   284,   284,   284,   284,   284,   291,
     291,    50,   291,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   261,   270,   287,   287,   261,    94,
       4,    50,   249,    50,   219,   220,   254,   114,   248,   114,
     248,    14,    15,    43,    35,    36,   114,   140,   224,   225,
     226,   248,   254,     4,   218,   161,   246,   249,   247,     4,
      51,    51,     4,    51,    50,     4,   144,   286,   114,   114,
     114,   114,   287,   114,    10,    11,    12,    27,    28,    29,
      30,    31,    32,   288,    50,    50,    50,    50,    50,    69,
     267,     4,    51,    51,   211,   250,   198,   228,   259,   228,
     254,   248,   252,   250,   246,   278,   287,   287,   287,   291,
     291,   291,   291,    50,   291,   286,   286,   286,   286,   286,
     286,   286,   286,   261,   287,    18,   214,     4,    50,    50,
      11,   214,    51,    51,   141,   265,    50,    50,    50,    50,
      50,    51,   270,    50,   259,   254,   245,   287,    66,    18,
     261,   270
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
    { (yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); }
    break;

  case 381:
#line 1336 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 382:
#line 1342 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 383:
#line 1348 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 384:
#line 1354 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 385:
#line 1360 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 386:
#line 1366 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 387:
#line 1372 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 388:
#line 1379 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 389:
#line 1385 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 390:
#line 1391 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 391:
#line 1397 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 392:
#line 1403 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 393:
#line 1409 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 394:
#line 1415 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 395:
#line 1425 "ace.yacc"
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
#line 1443 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 397:
#line 1445 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 398:
#line 1449 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 399:
#line 1453 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 400:
#line 1457 "ace.yacc"
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
#line 1466 "ace.yacc"
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
#line 1476 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 403:
#line 1483 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 404:
#line 1489 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 405:
#line 1495 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 406:
#line 1502 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 407:
#line 1508 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 408:
#line 1509 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 409:
#line 1514 "ace.yacc"
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

  case 410:
#line 1536 "ace.yacc"
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

  case 411:
#line 1554 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 412:
#line 1556 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 413:
#line 1560 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 414:
#line 1564 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 415:
#line 1568 "ace.yacc"
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

  case 416:
#line 1577 "ace.yacc"
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

  case 417:
#line 1587 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 418:
#line 1594 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 419:
#line 1600 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 420:
#line 1606 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 421:
#line 1613 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 422:
#line 1619 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 423:
#line 1620 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 424:
#line 1626 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 425:
#line 1632 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 426:
#line 1637 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 427:
#line 1642 "ace.yacc"
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

  case 428:
#line 1664 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 429:
#line 1672 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 430:
#line 1680 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 431:
#line 1688 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 432:
#line 1695 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 433:
#line 1704 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 434:
#line 1710 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 435:
#line 1719 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 436:
#line 1726 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 437:
#line 1735 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 438:
#line 1743 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 439:
#line 1751 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 440:
#line 1759 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 441:
#line 1766 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 442:
#line 1775 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 443:
#line 1781 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 444:
#line 1790 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 445:
#line 1797 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 446:
#line 1805 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 447:
#line 1811 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 448:
#line 1817 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 449:
#line 1823 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 450:
#line 1829 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 451:
#line 1835 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 452:
#line 1841 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 453:
#line 1847 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 454:
#line 1853 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 455:
#line 1859 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 456:
#line 1865 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 457:
#line 1873 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_SPACES; 
	}
    break;

  case 458:
#line 1880 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 459:
#line 1886 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 460:
#line 1894 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 461:
#line 1912 "ace.yacc"
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

  case 462:
#line 1923 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 463:
#line 1930 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
	}
    break;

  case 464:
#line 1937 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 465:
#line 1946 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_NULL;
	}
    break;

  case 466:
#line 1952 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 467:
#line 1956 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 468:
#line 1960 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 469:
#line 1964 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 5171 "y.tab.c"
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


#line 1990 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

