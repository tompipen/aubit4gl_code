/* A Bison parser, made by GNU Bison 2.3.  */

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
#define YYBISON_VERSION "2.3"

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
     KW_AS = 295,
     AVERAGE = 296,
     AVG = 297,
     BEFORE = 298,
     BETWEEN = 299,
     BOTTOM = 300,
     BY = 301,
     KW_CALL = 302,
     CH = 303,
     CHAR = 304,
     CHAR_VALUE = 305,
     CLOSE_BRACKET = 306,
     CLOSE_SQUARE = 307,
     COLON = 308,
     COMMANDS = 309,
     COUNT = 310,
     TOTAL = 311,
     DATABASE = 312,
     DATE = 313,
     TIME = 314,
     DATETIME = 315,
     DAY = 316,
     DECIMAL = 317,
     DEFINE = 318,
     DELIMITER = 319,
     DESC = 320,
     DISTINCT = 321,
     DO = 322,
     DOLLAR = 323,
     DOT = 324,
     ELSE = 325,
     END = 326,
     ESCAPE = 327,
     EVERY = 328,
     EXISTS = 329,
     EXTERNAL = 330,
     FIRST = 331,
     FLOAT = 332,
     PIPE = 333,
     FOR = 334,
     FORMAT = 335,
     FRACTION = 336,
     FROM = 337,
     FUNCTION = 338,
     GROUP = 339,
     GROUP_BY = 340,
     HAVING = 341,
     HEADER = 342,
     HOUR = 343,
     IF = 344,
     IN = 345,
     INPUT = 346,
     INTEGER = 347,
     INTERVAL = 348,
     INTO = 349,
     INTVAL = 350,
     KW_FALSE = 351,
     KW_TRUE = 352,
     LAST = 353,
     LEFT = 354,
     LENGTH = 355,
     LET = 356,
     LINES = 357,
     MARGIN = 358,
     MINUTE = 359,
     MONEY = 360,
     MONTH = 361,
     NAMED = 362,
     NEED = 363,
     NOT_EXISTS = 364,
     NOT_IN = 365,
     NUMBER_VALUE = 366,
     NUMERIC = 367,
     KW_OF = 368,
     ON = 369,
     OPEN_BRACKET = 370,
     OPEN_SQUARE = 371,
     ORDER_BY = 372,
     ORDER_EXTERNAL_BY = 373,
     OUTER = 374,
     OUTPUT = 375,
     PAGE = 376,
     PAGE_HEADER = 377,
     PAGE_TRAILER = 378,
     PARAM = 379,
     PAUSE = 380,
     PERCENT = 381,
     PRINT = 382,
     PRINTER = 383,
     PRINT_FILE = 384,
     PROMPT = 385,
     READ = 386,
     REPORT = 387,
     RIGHT = 388,
     ROW = 389,
     SECOND = 390,
     SELECT = 391,
     SEMICOLON = 392,
     SKIP = 393,
     SMALLFLOAT = 394,
     SMALLINT = 395,
     SOME = 396,
     STEP = 397,
     TEMP = 398,
     THEN = 399,
     TO = 400,
     TOP = 401,
     TOP_OF_PAGE = 402,
     TRAILER = 403,
     UNION = 404,
     UNIQUE = 405,
     UNITS_DAY = 406,
     UNITS_HOUR = 407,
     UNITS_MINUTE = 408,
     UNITS_MONTH = 409,
     UNITS_SECOND = 410,
     UNITS_YEAR = 411,
     UPDATE = 412,
     USER = 413,
     VARCHAR = 414,
     VARIABLE = 415,
     WHILE = 416,
     WITH_NO_LOG = 417,
     XBEGIN = 418,
     XMAX = 419,
     XMIN = 420,
     YEAR = 421
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
#define KW_AS 295
#define AVERAGE 296
#define AVG 297
#define BEFORE 298
#define BETWEEN 299
#define BOTTOM 300
#define BY 301
#define KW_CALL 302
#define CH 303
#define CHAR 304
#define CHAR_VALUE 305
#define CLOSE_BRACKET 306
#define CLOSE_SQUARE 307
#define COLON 308
#define COMMANDS 309
#define COUNT 310
#define TOTAL 311
#define DATABASE 312
#define DATE 313
#define TIME 314
#define DATETIME 315
#define DAY 316
#define DECIMAL 317
#define DEFINE 318
#define DELIMITER 319
#define DESC 320
#define DISTINCT 321
#define DO 322
#define DOLLAR 323
#define DOT 324
#define ELSE 325
#define END 326
#define ESCAPE 327
#define EVERY 328
#define EXISTS 329
#define EXTERNAL 330
#define FIRST 331
#define FLOAT 332
#define PIPE 333
#define FOR 334
#define FORMAT 335
#define FRACTION 336
#define FROM 337
#define FUNCTION 338
#define GROUP 339
#define GROUP_BY 340
#define HAVING 341
#define HEADER 342
#define HOUR 343
#define IF 344
#define IN 345
#define INPUT 346
#define INTEGER 347
#define INTERVAL 348
#define INTO 349
#define INTVAL 350
#define KW_FALSE 351
#define KW_TRUE 352
#define LAST 353
#define LEFT 354
#define LENGTH 355
#define LET 356
#define LINES 357
#define MARGIN 358
#define MINUTE 359
#define MONEY 360
#define MONTH 361
#define NAMED 362
#define NEED 363
#define NOT_EXISTS 364
#define NOT_IN 365
#define NUMBER_VALUE 366
#define NUMERIC 367
#define KW_OF 368
#define ON 369
#define OPEN_BRACKET 370
#define OPEN_SQUARE 371
#define ORDER_BY 372
#define ORDER_EXTERNAL_BY 373
#define OUTER 374
#define OUTPUT 375
#define PAGE 376
#define PAGE_HEADER 377
#define PAGE_TRAILER 378
#define PARAM 379
#define PAUSE 380
#define PERCENT 381
#define PRINT 382
#define PRINTER 383
#define PRINT_FILE 384
#define PROMPT 385
#define READ 386
#define REPORT 387
#define RIGHT 388
#define ROW 389
#define SECOND 390
#define SELECT 391
#define SEMICOLON 392
#define SKIP 393
#define SMALLFLOAT 394
#define SMALLINT 395
#define SOME 396
#define STEP 397
#define TEMP 398
#define THEN 399
#define TO 400
#define TOP 401
#define TOP_OF_PAGE 402
#define TRAILER 403
#define UNION 404
#define UNIQUE 405
#define UNITS_DAY 406
#define UNITS_HOUR 407
#define UNITS_MINUTE 408
#define UNITS_MONTH 409
#define UNITS_SECOND 410
#define UNITS_YEAR 411
#define UPDATE 412
#define USER 413
#define VARCHAR 414
#define VARIABLE 415
#define WHILE 416
#define WITH_NO_LOG 417
#define XBEGIN 418
#define XMAX 419
#define XMIN 420
#define YEAR 421




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
#line 515 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 528 "y.tab.c"

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
#define YYLAST   3333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  167
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  128
/* YYNRULES -- Number of rules.  */
#define YYNRULES  471
/* YYNRULES -- Number of states.  */
#define YYNSTATES  795

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   421

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
     165,   166
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
     609,   610,   612,   614,   616,   618,   622,   624,   627,   631,
     633,   635,   637,   639,   641,   643,   645,   648,   650,   652,
     657,   664,   671,   680,   683,   687,   691,   693,   695,   697,
     699,   703,   708,   713,   718,   723,   728,   734,   740,   746,
     752,   758,   761,   764,   767,   769,   772,   775,   778,   781,
     782,   784,   786,   788,   792,   794,   796,   799,   801,   803,
     805,   807,   809,   811,   813,   815,   817,   819,   823,   829,
     831,   833,   835,   837,   839,   849,   850,   853,   859,   860,
     863,   868,   876,   886,   887,   889,   891,   895,   899,   902,
     906,   907,   909,   912,   916,   920,   925,   927,   929,   931,
     933,   935,   937,   939,   941,   943,   945,   947,   949,   951,
     953,   955,   957,   959,   961,   963,   965,   967,   969,   971,
     973,   975,   977,   979,   981,   983,   985,   987,   989,   991,
     993,   995,   997,   999,  1001,  1003,  1005,  1007,  1009,  1011,
    1013,  1015,  1017,  1019,  1021,  1023,  1025,  1027,  1029,  1031,
    1033,  1035,  1037,  1039,  1041,  1043,  1045,  1047,  1049,  1051,
    1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,  1069,  1071,
    1073,  1075,  1077,  1079,  1081,  1083,  1085,  1087,  1089,  1091,
    1092,  1095,  1098,  1101,  1103,  1105,  1108,  1111,  1114,  1117,
    1120,  1123,  1126,  1130,  1134,  1138,  1142,  1146,  1149,  1151,
    1153,  1155,  1157,  1159,  1161,  1166,  1171,  1176,  1181,  1186,
    1190,  1192,  1195,  1198,  1200,  1202,  1204,  1206,  1208,  1210,
    1215,  1220,  1225,  1230,  1235,  1239,  1242,  1245,  1247,  1249,
    1252,  1255,  1258,  1261,  1264,  1267,  1270,  1273,  1276,  1278,
    1281,  1284,  1287,  1290,  1293,  1296,  1299,  1302,  1305,  1308,
    1311,  1314,  1317,  1320,  1323,  1326,  1329,  1332,  1335,  1338,
    1340,  1342,  1344,  1346,  1348,  1350,  1352,  1356,  1357,  1359,
    1361,  1363
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     168,     0,    -1,   169,   170,   178,   182,   186,   190,    -1,
      57,     8,    71,    -1,    57,   107,    71,    -1,    -1,   171,
      -1,    63,   172,    71,    -1,   173,    -1,   172,   173,    -1,
       8,   175,    -1,   160,   176,   177,    -1,   124,   116,   279,
      52,   176,   177,    -1,    83,   174,    -1,   107,    -1,   176,
     177,    -1,   175,     4,   176,   177,    -1,   107,    -1,    83,
      -1,    92,    -1,    49,    -1,    49,   115,   279,    51,    -1,
     159,    -1,   159,   115,   279,    51,    -1,    58,    -1,    77,
      -1,   139,    -1,   140,    -1,    60,    -1,    93,    -1,   105,
      -1,   105,   115,   279,    51,    -1,   105,   115,   279,     4,
     279,    51,    -1,    62,    -1,    62,   115,   279,    51,    -1,
      62,   115,   279,     4,   279,    51,    -1,    -1,   179,    -1,
      91,   180,    71,    -1,   181,    -1,   180,   181,    -1,   130,
      79,   176,     5,   280,    -1,    -1,   183,    -1,   120,   184,
      71,    -1,   185,    -1,   184,   185,    -1,   132,   145,   128,
     280,    -1,   132,   145,   128,    -1,   132,   145,   280,    -1,
     132,   145,    78,   280,    -1,    99,   103,   279,    -1,    45,
     103,   279,    -1,   146,   103,   279,    -1,   121,   100,   279,
      -1,   133,   103,   279,    -1,   147,   280,    -1,   188,    71,
      -1,   187,    71,    -1,   242,    -1,   187,   137,   242,    -1,
     131,   280,   189,   196,    -1,    -1,    64,   280,    -1,    80,
      73,   134,    71,    -1,    80,   192,   191,    -1,    -1,    71,
      -1,   193,    -1,   192,   193,    -1,    76,   121,    87,   261,
      -1,   121,   148,   261,    -1,   121,    87,   261,    -1,   114,
      73,   134,   261,    -1,   114,    98,   134,   261,    -1,    43,
      84,   113,   195,   261,    -1,    33,    84,   113,   195,   261,
      -1,   107,   116,   288,     4,   288,    52,    -1,   107,   116,
     288,    52,    -1,   107,    -1,   194,    -1,    95,    -1,    -1,
     197,    -1,    -1,   117,   198,   202,    -1,   118,   202,    -1,
      50,    -1,   112,    -1,   241,    -1,    95,    -1,    -1,   117,
     201,   202,    -1,   203,    -1,   202,     4,   203,    -1,   204,
     205,    -1,    95,    -1,   239,    -1,    -1,    37,    -1,    65,
      -1,    86,   219,    -1,    85,   208,    -1,   253,    -1,   208,
       4,   253,    -1,     9,   219,    -1,    82,   211,    -1,   212,
      -1,   211,     4,   212,    -1,   213,    -1,   119,   213,    -1,
     119,   115,   214,    51,    -1,   235,    -1,   235,   240,    -1,
     212,    -1,   214,     4,   212,    -1,   210,   216,   217,   218,
      -1,    -1,   209,    -1,    -1,   207,    -1,    -1,   206,    -1,
     220,    -1,   219,    10,   220,    -1,   221,    -1,   220,    11,
     221,    -1,   222,    -1,    13,   222,    -1,   233,    -1,   115,
     219,    51,    -1,    74,   249,    -1,   109,   249,    -1,   255,
     232,   225,   249,    -1,   249,   232,   255,    -1,   226,    -1,
     227,    -1,    35,    -1,   141,    -1,    36,    -1,   255,    90,
     115,   229,    51,    -1,   255,    90,   249,    -1,   255,   110,
     115,   229,    51,    -1,   255,   110,   249,    -1,   260,    -1,
     229,     4,   260,    -1,    -1,    13,    -1,   255,   230,    14,
      -1,   255,   230,    15,    -1,   255,   232,   255,    -1,   255,
     232,   249,    -1,   255,   230,    44,   255,    11,   255,    -1,
      18,    -1,    16,    -1,    17,    -1,    20,    -1,    22,    -1,
      25,    -1,    23,    -1,    26,    -1,    24,    -1,    19,    -1,
      21,    -1,   231,    -1,   228,    -1,   224,    -1,   223,    -1,
      -1,    35,    -1,    66,    -1,   150,    -1,    50,    -1,   237,
      -1,   236,    53,   237,    -1,    50,    69,   237,    -1,   281,
      -1,   281,    -1,    -1,   116,    95,    52,    -1,   116,    95,
       4,    95,    52,    -1,   281,   238,    -1,   235,    69,   281,
     238,    -1,   235,    69,    30,    -1,   281,    -1,   111,    -1,
      69,    95,    -1,    -1,   136,   243,   250,   251,   215,   246,
      -1,   245,    -1,   136,   250,   251,   215,   246,    -1,    -1,
     149,   234,   244,    -1,   200,    -1,    94,   143,   248,   247,
      -1,   200,    94,   143,   248,   247,    -1,    -1,   162,    -1,
     281,    -1,   115,   136,   250,   251,   215,    51,    -1,    -1,
      35,    -1,    66,    -1,   150,    -1,   252,    -1,   251,     4,
     252,    -1,   255,    -1,   255,   107,    -1,   255,    40,   107,
      -1,   255,    -1,   156,    -1,   154,    -1,   151,    -1,   152,
      -1,   153,    -1,   155,    -1,   255,   256,    -1,   199,    -1,
     281,    -1,   281,   116,   279,    52,    -1,   281,   116,   279,
       4,   279,    52,    -1,   281,    69,   281,   116,   279,    52,
      -1,   281,    69,   281,   116,   279,     4,   279,    52,    -1,
      68,   281,    -1,   281,    69,   281,    -1,   281,    69,    30,
      -1,    97,    -1,    96,    -1,   158,    -1,    30,    -1,   115,
     255,    51,    -1,    58,   115,   259,    51,    -1,    61,   115,
     259,    51,    -1,   106,   115,   259,    51,    -1,   166,   115,
     259,    51,    -1,   281,   115,   259,    51,    -1,    42,   115,
     234,   255,    51,    -1,   164,   115,   234,   255,    51,    -1,
     165,   115,   234,   255,    51,    -1,    38,   115,   234,   255,
      51,    -1,    55,   115,   234,   255,    51,    -1,    29,   257,
      -1,    31,   257,    -1,    32,   257,    -1,   254,    -1,    30,
     257,    -1,    28,   257,    -1,    27,   257,    -1,   258,   255,
      -1,    -1,    28,    -1,    27,    -1,   255,    -1,   259,     4,
     255,    -1,   199,    -1,   262,    -1,   261,   262,    -1,   265,
      -1,   267,    -1,   278,    -1,   269,    -1,   272,    -1,   273,
      -1,   277,    -1,   274,    -1,   276,    -1,   263,    -1,   163,
     261,    71,    -1,    47,   264,   115,   291,    51,    -1,    58,
      -1,   106,    -1,   166,    -1,    61,    -1,   281,    -1,    79,
     176,    18,   288,   145,   288,   266,    67,   262,    -1,    -1,
     142,   288,    -1,    89,   288,   144,   262,   268,    -1,    -1,
      70,   262,    -1,   101,   107,    18,   271,    -1,   101,   107,
     116,   288,    52,    18,   271,    -1,   101,   107,   116,   288,
       4,   288,    52,    18,   271,    -1,    -1,   271,    -1,   288,
      -1,   271,     4,   288,    -1,   108,   279,   102,    -1,   125,
     280,    -1,   127,   270,   275,    -1,    -1,   137,    -1,   129,
     280,    -1,   138,   279,   102,    -1,   138,   145,   147,    -1,
     161,   288,    67,   262,    -1,    95,    -1,    50,    -1,   107,
      -1,   282,    -1,    33,    -1,    37,    -1,    34,    -1,    40,
      -1,    43,    -1,    44,    -1,    45,    -1,    46,    -1,    47,
      -1,    48,    -1,    49,    -1,    12,    -1,     7,    -1,    54,
      -1,    16,    -1,    57,    -1,    60,    -1,    62,    -1,    63,
      -1,    64,    -1,    65,    -1,    67,    -1,    70,    -1,    72,
      -1,    73,    -1,    75,    -1,    76,    -1,    77,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,
      -1,    98,    -1,    99,    -1,   100,    -1,   101,    -1,    24,
      -1,   102,    -1,   103,    -1,   104,    -1,   105,    -1,   108,
      -1,   113,    -1,   114,    -1,   120,    -1,   121,    -1,   124,
      -1,   125,    -1,    32,    -1,   128,    -1,   130,    -1,   131,
      -1,   132,    -1,   133,    -1,   134,    -1,   135,    -1,   138,
      -1,   139,    -1,   140,    -1,     6,    -1,   142,    -1,   143,
      -1,   144,    -1,   145,    -1,   146,    -1,    56,    -1,   148,
      -1,   157,    -1,   159,    -1,   160,    -1,   161,    -1,   163,
      -1,    -1,     9,   288,    -1,   286,   283,    -1,   113,   287,
      -1,    55,    -1,   126,    -1,    41,   285,    -1,    56,   285,
      -1,    42,   285,    -1,   165,   285,    -1,   164,   285,    -1,
      84,    55,    -1,    84,   126,    -1,    84,    41,   285,    -1,
      84,    56,   285,    -1,    84,    42,   285,    -1,    84,   165,
     285,    -1,    84,   164,   285,    -1,    27,   287,    -1,   294,
      -1,    97,    -1,    96,    -1,   158,    -1,    58,    -1,    59,
      -1,    58,   115,   292,    51,    -1,   106,   115,   292,    51,
      -1,   166,   115,   292,    51,    -1,    61,   115,   292,    51,
      -1,   107,   115,   292,    51,    -1,   115,   288,    51,    -1,
     194,    -1,   287,   289,    -1,    27,   288,    -1,   294,    -1,
      97,    -1,    96,    -1,   158,    -1,    58,    -1,    59,    -1,
      58,   115,   292,    51,    -1,   106,   115,   292,    51,    -1,
     166,   115,   292,    51,    -1,    61,   115,   292,    51,    -1,
     107,   115,   292,    51,    -1,   115,   288,    51,    -1,     7,
     288,    -1,     8,   288,    -1,   194,    -1,   284,    -1,   288,
     290,    -1,    11,   287,    -1,    10,   287,    -1,    29,   287,
      -1,    32,   287,    -1,    31,   287,    -1,    30,   287,    -1,
      28,   287,    -1,    27,   287,    -1,    12,    -1,    11,   288,
      -1,    10,   288,    -1,    29,   288,    -1,    32,   288,    -1,
      31,   288,    -1,    30,   288,    -1,    28,   288,    -1,    27,
     288,    -1,     5,   288,    -1,    18,   288,    -1,    16,   288,
      -1,    17,   288,    -1,    20,   288,    -1,    22,   288,    -1,
      25,   288,    -1,    23,   288,    -1,    26,   288,    -1,    24,
     288,    -1,    19,   288,    -1,    21,   288,    -1,     6,    -1,
      14,    -1,    15,    -1,    12,    -1,   293,    -1,   292,    -1,
     288,    -1,   292,     4,   288,    -1,    -1,    50,    -1,   112,
      -1,   241,    -1,    95,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   238,   238,   246,   249,   258,   260,   265,   269,   269,
     273,   277,   280,   283,   288,   291,   291,   294,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   326,   327,   330,   334,
     334,   337,   342,   342,   345,   348,   348,   352,   353,   354,
     355,   356,   359,   362,   365,   368,   371,   378,   378,   382,
     383,   387,   390,   390,   394,   400,   404,   404,   408,   408,
     412,   416,   420,   424,   428,   431,   434,   441,   451,   461,
     476,   480,   488,   488,   491,   491,   494,   504,   507,   508,
     509,   514,   514,   518,   519,   524,   530,   535,   542,   543,
     544,   549,   555,   560,   561,   567,   572,   576,   577,   582,
     583,   584,   587,   588,   596,   596,   600,   611,   612,   615,
     616,   619,   620,   625,   626,   631,   632,   637,   638,   643,
     644,   650,   651,   656,   658,   665,   666,   669,   673,   674,
     696,   698,   700,   702,   708,   709,   713,   714,   719,   721,
     723,   725,   727,   733,   734,   735,   736,   737,   738,   739,
     740,   741,   742,   743,   748,   749,   750,   751,   753,   754,
     755,   756,   767,   768,   769,   770,   776,   780,   784,   785,
     786,   789,   790,   791,   797,   802,   802,   817,   817,   835,
     838,   845,   846,   849,   850,   854,   862,   862,   866,   883,
     887,   888,   889,   890,   894,   895,   899,   902,   906,   913,
     917,   918,   919,   920,   921,   922,   926,   927,   928,   929,
     930,   931,   932,   933,   937,   939,   941,   942,   943,   944,
     945,   946,   947,   948,   949,   950,   952,   954,   956,   958,
     960,   965,   966,   967,   968,   969,   970,   971,   974,   977,
     978,   979,   983,   983,   990,  1002,  1007,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1066,  1077,
    1078,  1079,  1080,  1081,  1084,  1094,  1095,  1099,  1107,  1110,
    1115,  1126,  1137,  1150,  1154,  1157,  1157,  1169,  1175,  1182,
    1190,  1190,  1193,  1199,  1204,  1211,  1220,  1223,  1227,  1228,
    1233,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,
    1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,
    1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,
    1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,
    1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1319,
    1322,  1329,  1338,  1342,  1348,  1354,  1360,  1366,  1372,  1378,
    1385,  1391,  1397,  1403,  1409,  1415,  1421,  1431,  1449,  1451,
    1455,  1459,  1463,  1472,  1482,  1489,  1495,  1501,  1508,  1514,
    1515,  1520,  1542,  1560,  1562,  1566,  1570,  1574,  1583,  1593,
    1600,  1606,  1612,  1619,  1625,  1626,  1632,  1638,  1643,  1648,
    1670,  1678,  1685,  1693,  1700,  1709,  1716,  1725,  1732,  1741,
    1749,  1756,  1764,  1771,  1780,  1787,  1796,  1803,  1811,  1817,
    1823,  1829,  1835,  1841,  1847,  1853,  1859,  1865,  1871,  1879,
    1886,  1892,  1900,  1918,  1929,  1936,  1943,  1952,  1958,  1962,
    1966,  1970
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
  "SUM", "ATSIGN", "KW_AS", "AVERAGE", "AVG", "BEFORE", "BETWEEN",
  "BOTTOM", "BY", "KW_CALL", "CH", "CHAR", "CHAR_VALUE", "CLOSE_BRACKET",
  "CLOSE_SQUARE", "COLON", "COMMANDS", "COUNT", "TOTAL", "DATABASE",
  "DATE", "TIME", "DATETIME", "DAY", "DECIMAL", "DEFINE", "DELIMITER",
  "DESC", "DISTINCT", "DO", "DOLLAR", "DOT", "ELSE", "END", "ESCAPE",
  "EVERY", "EXISTS", "EXTERNAL", "FIRST", "FLOAT", "PIPE", "FOR", "FORMAT",
  "FRACTION", "FROM", "FUNCTION", "GROUP", "GROUP_BY", "HAVING", "HEADER",
  "HOUR", "IF", "IN", "INPUT", "INTEGER", "INTERVAL", "INTO", "INTVAL",
  "KW_FALSE", "KW_TRUE", "LAST", "LEFT", "LENGTH", "LET", "LINES",
  "MARGIN", "MINUTE", "MONEY", "MONTH", "NAMED", "NEED", "NOT_EXISTS",
  "NOT_IN", "NUMBER_VALUE", "NUMERIC", "KW_OF", "ON", "OPEN_BRACKET",
  "OPEN_SQUARE", "ORDER_BY", "ORDER_EXTERNAL_BY", "OUTER", "OUTPUT",
  "PAGE", "PAGE_HEADER", "PAGE_TRAILER", "PARAM", "PAUSE", "PERCENT",
  "PRINT", "PRINTER", "PRINT_FILE", "PROMPT", "READ", "REPORT", "RIGHT",
  "ROW", "SECOND", "SELECT", "SEMICOLON", "SKIP", "SMALLFLOAT", "SMALLINT",
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
     415,   416,   417,   418,   419,   420,   421
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   167,   168,   169,   169,   170,   170,   171,   172,   172,
     173,   173,   173,   173,   174,   175,   175,   176,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   178,   178,   179,   180,
     180,   181,   182,   182,   183,   184,   184,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   186,   186,   187,
     187,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   193,   193,   193,   193,   193,   194,   194,   194,
     195,   195,   196,   196,   198,   197,   197,   199,   199,   199,
     199,   201,   200,   202,   202,   203,   204,   204,   205,   205,
     205,   206,   207,   208,   208,   209,   210,   211,   211,   212,
     212,   212,   213,   213,   214,   214,   215,   216,   216,   217,
     217,   218,   218,   219,   219,   220,   220,   221,   221,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   227,   227,
     228,   228,   228,   228,   229,   229,   230,   230,   231,   231,
     231,   231,   231,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   233,   233,   233,   233,   234,   234,
     234,   234,   235,   235,   235,   235,   236,   237,   238,   238,
     238,   239,   239,   239,   240,   241,   241,   243,   242,   244,
     245,   246,   246,   246,   246,   246,   247,   247,   248,   249,
     250,   250,   250,   250,   251,   251,   252,   252,   252,   253,
     254,   254,   254,   254,   254,   254,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   256,   256,   256,   256,   256,   256,   256,   257,   258,
     258,   258,   259,   259,   260,   261,   261,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   264,
     264,   264,   264,   264,   265,   266,   266,   267,   268,   268,
     269,   269,   269,   270,   270,   271,   271,   272,   273,   274,
     275,   275,   276,   277,   277,   278,   279,   280,   281,   281,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   283,
     283,   284,   285,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   291,   291,   292,   292,   293,   294,   294,
     294,   294
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
       0,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     4,
       6,     6,     8,     2,     3,     3,     1,     1,     1,     1,
       3,     4,     4,     4,     4,     4,     5,     5,     5,     5,
       5,     2,     2,     2,     1,     2,     2,     2,     2,     0,
       1,     1,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     1,
       1,     1,     1,     1,     9,     0,     2,     5,     0,     2,
       4,     7,     9,     0,     1,     1,     3,     3,     2,     3,
       0,     1,     2,     3,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     2,     2,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     3,     2,     2,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1
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
     296,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,   187,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,    56,    44,    46,    62,   200,
       0,     2,    58,     0,    57,    16,     0,     0,     0,     0,
       0,     0,    52,    51,    54,     0,    48,    49,    55,    53,
       0,    82,   201,   202,   203,     0,     0,     0,     0,     0,
       0,     0,    66,    68,    60,    21,     0,    34,     0,    31,
      23,    12,    41,    50,    47,    63,    84,     0,    61,    83,
     366,   312,   311,   314,   343,   229,   355,   300,   302,   301,
       0,   303,     0,   304,   305,   306,   307,   308,   309,   310,
      87,   313,     0,   372,   315,     0,   316,     0,   317,   318,
     319,   320,   321,     0,     0,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,    90,   227,   226,   339,   340,   341,   342,   344,
     345,   346,   347,     0,   298,   348,   185,    88,   349,   350,
       0,   351,   352,   353,   354,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   367,   368,   369,   370,   371,
     373,   374,   228,   375,   376,   377,   378,     0,     0,     0,
     217,    89,     0,   204,   206,   218,   299,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    65,    69,     0,     0,
       0,   172,    96,    86,    93,    98,     0,     0,   173,    97,
     178,   168,   168,   168,     0,     0,   223,   186,     0,     0,
     168,   168,     0,     0,     0,   117,   191,   249,   249,   249,
     249,   249,   249,     0,   207,   212,   213,   214,   211,   215,
     210,   244,   216,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   283,     0,
       0,     0,     0,    72,   255,   266,   257,   258,   260,   261,
     262,   264,   265,   263,   259,    71,    35,    32,    85,     0,
       0,    99,   100,    95,     0,     0,     0,   181,   169,   170,
     171,     0,     0,     0,   252,     0,     0,     0,   230,     0,
       0,     0,   205,     0,   106,   107,   109,   112,   177,     0,
     118,   119,     0,    91,   168,   193,   188,   251,   250,   247,
       0,   246,   241,   245,   242,   243,   208,   225,   224,     0,
       0,    81,    79,    80,     0,     0,    70,    73,    74,   269,
     272,   270,   271,     0,   273,     0,     0,     0,     0,     0,
       0,   468,   383,     0,   417,   418,     0,     0,   471,   415,
     414,     0,    79,   469,     0,   384,   416,     0,     0,     0,
     427,   470,   428,   379,     0,   413,     0,     0,   288,   290,
     284,   285,   292,     0,     0,     0,     0,   256,   175,   177,
      94,   183,   178,   174,     0,     0,     0,     0,     0,   231,
     232,   233,     0,     0,   234,     0,   110,     0,   113,   184,
       0,     0,     0,     0,   105,   123,   125,   127,   167,   166,
     165,   164,   129,     0,   146,     0,   120,   121,     0,     0,
       0,     0,   248,     0,   235,     0,   219,     0,    76,    75,
     467,     0,   425,   426,   412,     0,   385,   387,   386,     0,
       0,     0,     0,   390,     0,   391,     0,     0,     0,     0,
       0,   389,   388,     0,     0,   381,     0,   459,     0,     0,
     462,   460,   461,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   429,     0,     0,   287,   291,   289,     0,   294,   293,
       0,   267,   182,     0,   179,   239,   236,   240,   253,   237,
     238,   114,     0,   108,   128,     0,   131,   132,   200,     0,
     146,     0,     0,   154,   155,   153,   162,   156,   163,   157,
     159,   161,   158,   160,     0,   147,     0,     0,     0,     0,
     102,   103,   209,     0,   122,   116,   196,   198,    92,   200,
     192,   189,     0,     0,     0,     0,   465,     0,   464,   463,
       0,     0,   402,   403,     0,   400,   399,     0,    79,     0,
     401,     0,   410,   382,   398,     0,     0,   392,   394,   393,
     396,   395,     0,     0,   424,     0,   380,   447,   440,   439,
     449,   450,   448,   457,   451,   458,   452,   454,   456,   453,
     455,   446,   445,   441,   444,   443,   442,   278,   280,     0,
     286,   295,     0,     0,   111,     0,   130,   124,   126,   134,
       0,   141,     0,   143,   148,   149,     0,   137,   139,     0,
     138,     0,   135,   136,   151,   150,     0,   101,   197,   194,
       0,   196,     0,   221,   220,     0,    78,   268,     0,     0,
     397,     0,     0,     0,     0,     0,     0,     0,     0,   438,
       0,     0,     0,     0,     0,     0,   411,   419,   422,   420,
     423,   421,     0,   277,     0,     0,   180,   115,     0,   254,
       0,   144,     0,     0,   133,   104,     0,   195,     0,     0,
     466,   275,     0,     0,     0,     0,   409,     0,   431,   430,
     437,   436,   432,   435,   434,   433,   279,     0,     0,     0,
       0,   140,   142,     0,   191,   222,    77,     0,     0,   404,
     407,   405,   408,   406,     0,   281,   199,   145,   152,   190,
     276,     0,     0,   274,   282
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   256,   122,   123,   430,   394,   138,
     139,   260,   240,   375,   489,   263,   264,   265,   343,   604,
     486,   600,   370,   285,   364,   365,   366,   572,   286,   371,
     487,   605,   474,   475,   476,   477,   478,   479,   691,   692,
     693,   480,   740,   598,   481,   599,   482,   351,   367,   267,
     268,   347,   269,   468,   431,    70,    89,   610,   611,   376,
     699,   606,   483,   115,   242,   243,   601,   301,   354,   302,
     379,   380,   355,   741,   323,   324,   325,   403,   326,   778,
     327,   733,   328,   439,   440,   329,   330,   331,   556,   332,
     333,   334,    51,    85,   245,   246,   525,   432,   506,   433,
     633,   616,   726,   551,   617,   618,   619,   435
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -696
static const yytype_int16 yypact[] =
{
      66,     8,    65,    71,    83,   137,  -696,    21,    51,  -696,
    -696,  -696,   119,   121,   123,   119,    -2,  -696,   100,   128,
    -696,  -696,   249,    36,  -696,  -696,   163,    36,  -696,  -696,
     188,   -23,  -696,   504,    74,  -696,   119,   161,  -696,  -696,
     174,  -696,  -696,  -696,  -696,   191,  -696,  -696,   196,  -696,
    -696,   285,  -696,   119,  -696,  -696,   237,   239,   252,   203,
     254,   258,   317,   498,  -696,   317,  -696,   291,   -31,   307,
    -696,    36,   163,   163,   163,   163,   119,   376,   163,   163,
     163,   -26,   163,   163,  -696,  -696,  -696,  -696,   352,     0,
     463,  -696,  -696,   282,  -696,  -696,   369,   135,   158,   392,
      36,   317,  -696,  -696,  -696,   317,   317,  -696,  -696,  -696,
     317,     3,  -696,  -696,  -696,  1455,   363,   364,   320,   330,
      32,   -61,   507,  -696,  -696,  -696,   163,  -696,   163,  -696,
    -696,  -696,  -696,  -696,  -696,  -696,  -696,  1880,  -696,  -696,
    -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,
     347,  -696,   348,  -696,  -696,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,   350,  -696,  -696,   360,  -696,   365,  -696,  -696,
    -696,  -696,  -696,  2610,   381,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,   366,  -696,  -696,  -696,  -696,  -696,  -696,
    1455,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  -696,  -696,  -696,  -696,   367,   372,   378,
    -696,  -696,    27,  -696,   487,    10,  -696,   382,   384,   406,
     404,   368,   370,   491,   491,  -696,  -696,  -696,   443,   448,
    1880,   431,  -696,   501,  -696,   151,   439,   458,  -696,  -696,
      17,     1,     1,     1,  1455,  1455,  -696,  -696,  1455,   142,
       1,     1,  1455,  1455,  2026,   512,   -14,   190,   190,   190,
     190,   190,   190,   421,  -696,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  2318,  1455,   163,   -46,   -46,  -696,   491,
     491,   491,  1616,   119,  1745,   422,   163,   317,  1745,   317,
      49,  1745,   491,   491,  -696,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  -696,  -696,   491,  -696,  -696,   501,  2610,
    1880,  -696,  -696,  -696,  2464,  2610,   418,  -696,  -696,  -696,
    -696,  1455,  1455,  1455,  2765,   178,   208,   209,  -696,  1455,
    1455,   211,  -696,  2172,   533,  -696,  -696,  2610,   488,   811,
    -696,   457,   401,  -696,     1,   460,  -696,  -696,  -696,  -696,
    1455,  -696,  -696,  -696,  -696,  -696,  -696,  -696,   429,   257,
      56,  -696,   435,  -696,   491,   491,   491,   491,   491,  -696,
    -696,  -696,  -696,   437,  -696,   537,  1745,  1745,  1745,   446,
     446,  -696,  -696,   446,   441,  -696,   449,    -9,  -696,  -696,
    -696,   453,   117,  -696,  1745,  -696,  -696,   446,   446,   461,
    -696,  -696,  -696,   552,  2797,  -696,    16,   470,  -696,   436,
     571,  3235,  -696,   440,   480,  2939,  1737,  -696,  -696,  -696,
    -696,  -696,   472,  -696,   114,  1615,  1681,  2609,  1455,  -696,
    -696,  -696,  2843,  2849,  -696,  2026,  -696,  2026,  -696,  -696,
    1133,   471,   471,   650,   579,   580,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  2866,   379,  1455,  -696,   510,  2610,  1880,
     469,   464,  2765,   163,  -696,   163,  -696,  1745,   491,   491,
    1745,  1745,  3235,  3235,   240,   451,  -696,  -696,  -696,  1745,
    1745,   446,   446,  -696,   446,  -696,   446,   446,  1745,  1745,
    3159,  -696,  -696,  1745,  1745,  -696,  1745,  -696,  1745,  1745,
    -696,  -696,  -696,  1745,  1745,  1745,  1745,  1745,  1745,  1745,
    1745,  1745,  1745,  1745,  1745,  1745,  1745,  1745,  1745,  1745,
     491,  -696,  1745,  1745,  -696,  -696,  -696,  1745,  -696,  -696,
     491,  -696,  -696,   511,  -696,  -696,  -696,  -696,  2765,  -696,
    -696,  -696,   287,  -696,  -696,   486,  -696,  -696,     0,   106,
    2759,   811,   811,  -696,  -696,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  -696,  1455,  -696,   493,   508,   400,   972,
     620,  -696,  2765,   811,  -696,  -696,   473,  -696,   501,     0,
    -696,  -696,  2610,   127,   574,  3003,  3235,   582,   630,  -696,
     304,   451,   531,  -696,   532,  -696,  -696,   534,   248,  1745,
    -696,   538,  -696,  2024,  -696,   288,   298,  -696,  -696,  -696,
    -696,  -696,   299,   300,  -696,   303,  3258,  3235,  3280,  3301,
    1853,  1853,  1853,  1853,  1853,  1853,  1853,  1853,  1853,  1853,
    1853,   240,   240,   341,   341,  -696,  -696,   578,   571,  3042,
    3235,  -696,   607,  2026,  -696,  1455,  -696,   580,  -696,  2765,
      41,  -696,    41,  -696,  -696,  -696,  1455,  -696,  -696,  1294,
    -696,   471,  -696,  -696,  -696,  2765,  1455,   579,  -696,  -696,
    1455,   473,   163,  -696,  -696,  1745,  -696,  -696,  1745,  1745,
     494,  1745,  1745,  1745,  1745,  3197,  1745,   451,   451,  -696,
     451,   451,   451,   451,   451,   451,  -696,  -696,  -696,  -696,
    -696,  -696,   491,  -696,  1745,   642,  -696,  -696,    27,  -696,
     308,  -696,   309,    46,  -696,  -696,    27,  -696,   612,  3081,
    3235,  2836,   337,   340,   342,   361,  -696,   362,  2170,   583,
     494,   494,   344,   344,  -696,  -696,  -696,  3120,  1745,   614,
     111,  -696,  -696,  1455,   -14,  -696,  -696,  1745,   600,  -696,
    -696,  -696,  -696,  -696,   651,   571,  -696,  -696,  2765,  -696,
    3235,   491,  1745,  -696,   571
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -696,  -696,  -696,  -696,  -696,  -696,   652,  -696,  -696,    -8,
      11,  -696,  -696,  -696,   640,  -696,  -696,  -696,   609,  -696,
    -696,  -696,  -696,  -696,  -696,  -696,   551,  -265,   371,  -696,
    -696,  -696,  -643,  -696,  -696,  -240,   335,  -696,  -696,  -696,
    -696,  -696,  -696,  -696,  -696,  -442,   313,  -696,  -695,  -696,
    -696,  -696,  -455,    98,    99,   216,  -696,  -696,  -696,  -696,
    -696,  -696,     7,  -696,  -696,   218,  -696,  -209,  -136,  -696,
    -202,   250,  -696,  -696,  -115,   598,  -696,  -696,  -696,   -71,
      15,    97,  -450,  -375,  -479,   438,    39,  -696,   -96,  -696,
     182,  -696,   186,   -42,  -210,  -308,  -696,  -696,  -696,  -696,
    -696,  -696,  -696,  -696,  -541,  -696,  -696,  -696,  -696,  -696,
    -696,  -696,   -70,   -51,  -120,  -696,  -696,  -696,  2319,  -696,
    -338,  -107,  -696,  -696,  -696,  -426,  -696,  -443
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -178
static const yytype_int16 yytable[] =
{
     241,   266,    96,    97,    98,    99,    12,    27,   102,   103,
     104,   668,   108,   109,    88,   447,     4,   270,   579,   244,
     338,   576,   577,   571,    84,   573,   253,   447,    71,    12,
     107,   283,   511,   512,   552,   112,   348,   739,    52,   739,
      92,   393,   393,   769,   335,    77,   513,   514,    54,   391,
     132,   774,   105,   276,   133,   134,   258,   773,   259,   135,
     495,   392,   634,   352,   353,     6,   113,   349,   100,    28,
    -176,   359,   360,   287,   288,   289,   290,   291,   292,   303,
     372,    13,    95,   635,   636,    37,  -177,   254,   447,   447,
     447,   160,   642,   643,    38,   241,    39,   645,    40,   396,
     397,   398,   106,   373,    13,   251,    93,    30,   496,   284,
     174,   131,   446,    41,   279,     5,   581,   515,   563,    42,
     136,   137,    14,     1,   266,   304,   305,   739,    43,    44,
     252,   702,   553,   346,     7,   374,   192,   448,   447,   126,
     270,    45,    18,   453,    50,    14,   681,   683,   697,   694,
     114,   350,   206,   207,    10,   516,   517,   676,    15,   241,
     241,   160,   128,   241,   368,   490,   564,   241,   241,   287,
     288,   289,   290,   291,   292,    46,    47,   578,   634,   703,
     174,    15,   458,   388,   498,   499,   127,   244,   341,   241,
     447,   447,   404,   358,   443,    48,   738,   295,   296,   297,
     298,   299,   300,   675,   266,    65,   192,   434,    11,   129,
      66,   441,   458,   458,   445,   458,   342,   377,   378,   449,
     270,   746,   206,   207,   452,   449,    21,   785,    24,   459,
      30,   737,   519,   497,   700,   390,   241,   241,   241,    26,
     632,   744,   667,   368,   241,   241,   437,   469,    33,   608,
     444,   794,   671,    36,   241,   455,   456,   457,    50,   460,
     461,   458,   464,   462,   463,   241,   438,    53,   442,   546,
     547,   548,   549,   484,   634,   634,    72,   634,   634,   634,
     634,   634,   634,   710,   492,   752,   753,   754,   755,    73,
     757,   673,   708,   295,   296,   297,   298,   299,   300,   502,
     503,   504,   708,   708,   708,   405,    74,   708,   494,   526,
     527,    75,   770,   770,   528,   529,   530,   520,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,    76,   674,   727,
      78,   708,    79,   241,   708,   368,   708,   368,    81,   728,
     729,   730,    80,   266,   731,   241,   632,    82,   241,   771,
     772,    83,   568,   714,   497,   708,   708,    84,   607,   270,
     241,    90,   548,   549,   484,   724,   725,   580,    94,   758,
     759,   101,   760,   761,   762,   763,   764,   765,   779,   602,
     615,   780,   595,   781,   620,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   287,   288,   289,   290,
     291,   292,   782,   783,   684,   685,   110,   646,    66,   647,
     125,   648,   649,   613,   766,   614,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   130,   686,   441,   669,   247,   248,   709,
     670,   250,   632,   632,   249,   632,   632,   632,   632,   632,
     632,   356,   271,   272,   357,   273,   241,   241,   361,   596,
     381,   382,   383,   384,   385,   274,   277,   308,   621,   241,
     275,   278,   280,   793,   241,   484,   484,   281,   241,   597,
     389,   309,   607,   282,   336,   306,   116,   307,   679,   337,
     339,   411,   310,   695,   311,   340,   117,   484,   344,   622,
     623,   345,   624,   454,   287,   288,   289,   290,   291,   292,
     174,   369,   715,   722,   723,   724,   725,   293,   386,   436,
     295,   296,   297,   298,   299,   300,   118,   467,   312,   119,
     116,  -176,   485,    56,   488,   493,   418,   625,   626,    56,
     117,   497,   500,   368,   491,   501,   509,   627,   628,   505,
     241,   524,   206,   423,   510,   241,   629,   241,   518,    86,
     313,   241,   554,   555,   241,   557,   523,   120,   255,   244,
     314,   241,   559,   119,   121,   241,   575,   558,   346,   581,
     743,   582,   315,   279,   294,   719,   603,    57,   749,   316,
     602,   750,   751,    57,   244,   609,   672,   612,   680,   630,
     720,   721,   722,   723,   724,   725,   317,   631,   318,    58,
     319,   120,   578,   682,   696,    58,   704,   767,   121,   320,
      59,    60,   748,   707,   708,   698,    59,    60,   295,   296,
     297,   298,   299,   300,    61,    62,   711,   712,   732,   713,
      61,    62,   321,   716,   322,   241,   140,   141,   241,   736,
     768,   441,   142,   470,   775,   786,   143,   791,    29,   792,
     790,    55,    87,   257,   144,   450,   466,   788,   395,   677,
     145,   678,   146,   147,   148,   441,   574,   149,   150,   742,
     151,   124,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   594,   562,   789,   161,   162,   163,   164,   165,   701,
     166,   167,   168,   169,   170,   171,   747,   172,   173,   174,
     175,   362,   176,   177,   471,   178,   179,   180,   787,   181,
     182,   183,   184,   185,   186,   745,     0,   187,   188,   189,
     190,   191,     0,     0,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   472,
       0,   206,   207,   208,   209,   473,     0,     0,     0,     0,
     211,   212,     0,     0,   213,   214,     0,     0,   215,     0,
     216,   217,   218,   219,   220,   221,   578,     0,   222,   223,
     224,     0,   225,   226,   227,   228,   229,     0,   230,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   232,   233,
     234,   235,     0,   236,   237,   238,   239,   140,   141,     0,
       0,     0,     0,   142,   470,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,   145,     0,   146,   147,   148,     0,     0,   149,   150,
       0,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,     0,     0,     0,   161,   162,   163,   164,   165,
       0,   166,   167,   168,   169,   170,   171,     0,   172,   173,
     174,   175,     0,   176,   177,   471,   178,   179,   180,     0,
     181,   182,   183,   184,   185,   186,     0,     0,   187,   188,
     189,   190,   191,     0,     0,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     472,     0,   206,   207,   208,   209,   473,     0,     0,     0,
       0,   211,   212,     0,     0,   213,   214,     0,     0,   215,
       0,   216,   217,   218,   219,   220,   221,     0,     0,   222,
     223,   224,     0,   225,   226,   227,   228,   229,     0,   230,
       0,     0,     0,     0,     0,     0,     0,     0,   231,   232,
     233,   234,   235,     0,   236,   237,   238,   239,   140,   141,
       0,     0,     0,     0,   142,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,   145,     0,   146,   147,   148,   687,   688,   149,
     150,     0,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,   161,   162,   163,   164,
     165,     0,   166,   167,   168,   169,   170,   171,     0,   172,
     173,   174,   175,     0,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,     0,     0,   206,   207,   208,   209,   689,     0,     0,
       0,     0,   211,   212,     0,     0,   213,   214,     0,     0,
     215,     0,   216,   217,   218,   219,   220,   221,     0,     0,
     222,   223,   224,   690,   225,   226,   227,   228,   229,     0,
     230,     0,     0,     0,     0,     0,     0,     0,     0,   231,
     232,   233,   234,   235,     0,   236,   237,   238,   239,   140,
     141,     0,     0,     0,     0,   142,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,   145,     0,   146,   147,   148,     0,     0,
     149,   150,     0,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,     0,     0,     0,   161,   162,   163,
     164,   165,     0,   166,   167,   168,   169,   170,   171,     0,
     172,   173,   174,   175,     0,   176,   177,   471,   178,   179,
     180,     0,   181,   182,   183,   184,   185,   186,     0,     0,
     187,   188,   189,   190,   191,     0,     0,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   472,     0,   206,   207,   208,   209,   473,     0,
       0,     0,     0,   211,   212,     0,     0,   213,   214,     0,
       0,   215,     0,   216,   217,   218,   219,   220,   221,     0,
       0,   222,   223,   224,     0,   225,   226,   227,   228,   229,
       0,   230,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,   235,     0,   236,   237,   238,   239,
     140,   141,     0,     0,     0,     0,   142,     0,     0,     0,
     143,     0,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,   145,     0,   146,   147,   148,     0,
       0,   149,   150,     0,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,   161,   162,
     163,   164,   165,     0,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,     0,     0,   206,   207,   208,   209,   210,
       0,     0,     0,     0,   211,   212,     0,     0,   213,   214,
       0,     0,   215,     0,   216,   217,   218,   219,   220,   221,
     578,     0,   222,   223,   224,     0,   225,   226,   227,   228,
     229,     0,   230,     0,     0,     0,     0,     0,     0,     0,
       0,   231,   232,   233,   234,   235,     0,   236,   237,   238,
     239,   140,   141,     0,     0,     0,     0,   142,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,   145,     0,   146,   147,   148,
       0,     0,   149,   150,     0,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,   161,
     162,   163,   164,   165,     0,   166,   167,   168,   169,   170,
     171,     0,   172,   173,   174,   175,     0,   176,   177,     0,
     178,   179,   180,     0,   181,   182,   183,   184,   185,   186,
       0,     0,   187,   188,   189,   190,   191,     0,     0,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,     0,     0,   206,   207,   208,   209,
     210,     0,     0,     0,     0,   211,   212,     0,     0,   213,
     214,     0,     0,   215,     0,   216,   217,   218,   219,   220,
     221,     0,     0,   222,   223,   224,     0,   225,   226,   227,
     228,   229,     0,   230,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   232,   233,   234,   235,     0,   236,   237,
     238,   239,   140,   141,     0,     0,     0,     0,   142,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
     144,     0,   287,   288,   289,   290,   291,   292,   146,   147,
     148,     0,     0,   149,     0,     0,   151,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   565,     0,     0,     0,
     161,     0,   163,   164,   399,     0,   166,   400,   168,   169,
     170,   171,     0,   172,     0,     0,   175,     0,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,     0,     0,   187,   188,   189,   190,   191,   287,   288,
     289,   290,   291,   292,   195,   196,   197,   198,   199,   200,
     201,   202,   401,   204,   205,     0,     0,     0,     0,   208,
     209,     0,   566,     0,     0,     0,   211,   212,     0,     0,
     213,   214,     0,     0,   215,     0,   216,   217,   218,   219,
     220,   221,   406,   407,   222,   223,   224,     0,   225,   226,
     227,   228,   229,     0,   230,     0,   295,   296,   297,   298,
     299,   300,   408,   231,     0,   233,   234,   235,     0,   236,
       0,     0,   402,     0,   312,     0,   409,   410,     0,     0,
       0,     0,     0,     0,     0,   411,     0,     0,     0,     0,
     412,   413,     0,   414,   415,     0,   416,     0,   561,     0,
       0,     0,     0,     0,   174,     0,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,   417,
       0,     0,   295,   296,   297,   298,   299,   300,   315,     0,
     418,   419,   420,     0,     0,   316,     0,     0,     0,     0,
       0,   421,   422,     0,     0,     0,   206,   423,     0,     0,
     424,     0,   317,     0,   318,     0,   319,     0,     0,     0,
       0,   425,     0,     0,     0,   320,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   140,   141,     0,     0,
       0,     0,   142,     0,     0,     0,   143,     0,   321,     0,
     322,     0,     0,   426,   144,     0,     0,     0,     0,   427,
     428,   429,   146,   147,   148,     0,     0,   149,     0,     0,
     151,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     261,     0,     0,     0,   161,     0,   163,   164,     0,     0,
     166,     0,   168,   169,   170,   171,     0,   172,     0,     0,
     175,     0,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,   262,     0,     0,   195,   196,
     197,   198,   199,   200,   201,   202,     0,   204,   205,     0,
       0,     0,     0,   208,   209,     0,     0,     0,     0,     0,
     211,   212,     0,     0,   213,   214,     0,     0,   215,     0,
     216,   217,   218,   219,   220,   221,     0,     0,   222,   223,
     224,     0,   225,   226,   227,   228,   229,     0,   230,     0,
       0,     0,   140,   141,   717,   718,   719,   231,   142,   233,
     234,   235,   143,   236,     0,     0,     0,     0,     0,     0,
     144,   720,   721,   722,   723,   724,   725,     0,   146,   147,
     148,     0,     0,   149,     0,     0,   151,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   261,     0,     0,     0,
     161,     0,   163,   164,     0,     0,   166,     0,   168,   169,
     170,   171,     0,   172,     0,     0,   175,     0,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,     0,     0,   187,   188,   189,   190,   191,     0,     0,
       0,     0,     0,     0,   195,   196,   197,   198,   199,   200,
     201,   202,     0,   204,   205,     0,     0,     0,     0,   208,
     209,     0,     0,     0,     0,   363,   211,   212,     0,     0,
     213,   214,     0,     0,   215,     0,   216,   217,   218,   219,
     220,   221,     0,     0,   222,   223,   224,     0,   225,   226,
     227,   228,   229,     0,   230,     0,     0,     0,   140,   141,
       0,   718,   719,   231,   142,   233,   234,   235,   143,   236,
       0,     0,     0,     0,     0,     0,   144,   720,   721,   722,
     723,   724,   725,     0,   146,   147,   148,     0,     0,   149,
       0,     0,   151,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   261,     0,     0,     0,   161,     0,   163,   164,
       0,     0,   166,     0,   168,   169,   170,   171,     0,   172,
       0,     0,   175,     0,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,   202,     0,   204,
     205,     0,     0,     0,     0,   208,   209,   465,     0,     0,
       0,     0,   211,   212,     0,     0,   213,   214,     0,     0,
     215,     0,   216,   217,   218,   219,   220,   221,     0,     0,
     222,   223,   224,     0,   225,   226,   227,   228,   229,     0,
     230,     0,     0,     0,   140,   141,     0,     0,     0,   231,
     142,   233,   234,   235,   143,   236,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,   387,     0,
     146,   147,   148,     0,     0,   149,     0,     0,   151,     0,
       0,   153,   154,   155,   156,   157,   158,   159,     0,     0,
       0,     0,   161,     0,   163,   164,     0,     0,   166,     0,
     168,   169,   170,   171,     0,   172,     0,     0,   175,     0,
     176,   177,     0,   178,   179,   180,     0,   181,   182,   183,
     184,   185,   186,     0,     0,   187,   188,   189,   190,   191,
       0,     0,     0,     0,     0,     0,   195,   196,   197,   198,
     199,   200,   201,   202,     0,   204,   205,     0,     0,     0,
       0,   208,   209,     0,     0,     0,     0,     0,   211,   212,
       0,     0,   213,   214,     0,     0,   215,     0,   216,   217,
     218,   219,   220,   221,     0,     0,   222,   223,   224,     0,
     225,   226,   227,   228,   229,     0,   230,     0,     0,     0,
     140,   141,     0,     0,     0,   231,   142,   233,   234,   235,
     143,   236,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,   451,     0,   146,   147,   148,     0,
       0,   149,     0,     0,   151,     0,     0,   153,   154,   155,
     156,   157,   158,   159,     0,     0,     0,     0,   161,     0,
     163,   164,     0,     0,   166,     0,   168,   169,   170,   171,
       0,   172,     0,     0,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,     0,
       0,     0,   195,   196,   197,   198,   199,   200,   201,   202,
       0,   204,   205,     0,     0,     0,     0,   208,   209,     0,
       0,     0,     0,     0,   211,   212,     0,     0,   213,   214,
       0,     0,   215,     0,   216,   217,   218,   219,   220,   221,
       0,     0,   222,   223,   224,     0,   225,   226,   227,   228,
     229,     0,   230,     0,     0,     0,   140,   141,     0,     0,
       0,   231,   142,   233,   234,   235,   143,   236,     0,     0,
       0,     0,     0,     0,   144,     0,   287,   288,   289,   290,
     291,   292,   146,   147,   148,     0,     0,   149,     0,     0,
     151,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     567,     0,     0,     0,   161,     0,   163,   164,     0,     0,
     166,     0,   168,   169,   170,   171,     0,   172,     0,     0,
     175,     0,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,     0,     0,     0,   195,   196,
     197,   198,   199,   200,   201,   202,     0,   204,   205,     0,
       0,     0,     0,   208,   209,     0,     0,     0,     0,   507,
     211,   212,   508,     0,   213,   214,     0,     0,   215,     0,
     216,   217,   218,   219,   220,   221,   521,   522,   222,   223,
     224,     0,   225,   226,   227,   228,   229,     0,   230,     0,
     295,   296,   297,   298,   299,   300,     0,   231,     0,   233,
     234,   235,   595,   236,     0,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   287,   288,   289,   290,
     291,   292,   287,   288,   289,   290,   291,   292,     0,     0,
       0,     0,   526,   527,     0,     0,     0,   528,   529,   530,
     358,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     637,   638,     0,   639,     0,   640,   641,     0,     0,     0,
       0,   526,   527,     0,     0,     0,   528,   529,   530,   596,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   597,
     287,   288,   289,   290,   291,   292,   287,   288,   289,   290,
     291,   292,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,     0,   569,     0,     0,     0,     0,     0,
     570,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   296,   297,   298,   299,   300,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   550,     0,     0,   526,   527,     0,     0,     0,   528,
     529,   530,     0,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,     0,     0,     0,     0,     0,     0,   777,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   296,   297,   298,   299,   300,
     295,   296,   297,   298,   299,   300,   560,   705,   526,   527,
       0,     0,     0,   528,   529,   530,     0,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   734,   526,   527,     0,
       0,     0,   528,   529,   530,   706,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,   527,     0,     0,
       0,   528,   529,   530,   735,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,   527,     0,     0,     0,
     528,   529,   530,   776,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   526,   527,     0,     0,     0,   528,
     529,   530,   784,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   526,   527,     0,     0,     0,   528,   529,   530,
     644,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     526,   527,     0,     0,     0,   528,   529,   530,   756,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   528,   529,
     530,     0,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   529,   530,     0,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   530,     0,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549
};

static const yytype_int16 yycheck[] =
{
     115,   137,    72,    73,    74,    75,     8,    15,    78,    79,
      80,   552,    82,    83,    65,   323,     8,   137,   473,   115,
     260,   471,   472,   465,    50,   467,    87,   335,    36,     8,
      81,     4,    41,    42,    18,    35,    35,   680,    27,   682,
      71,   306,   307,   738,   254,    53,    55,    56,    71,    95,
     101,   746,    78,   173,   105,   106,   126,    11,   128,   110,
       4,   107,   505,   272,   273,     0,    66,    66,    76,    71,
      53,   280,   281,    27,    28,    29,    30,    31,    32,    69,
      94,    83,    71,   509,   510,    49,    69,   148,   396,   397,
     398,    50,   518,   519,    58,   210,    60,   523,    62,   309,
     310,   311,   128,   117,    83,    73,   137,   130,    52,    82,
      69,   100,   322,    77,   210,   107,    10,   126,     4,    83,
     117,   118,   124,    57,   260,   115,   116,   770,    92,    93,
      98,     4,   116,   116,    63,   149,    95,   339,   446,     4,
     260,   105,    91,   345,    95,   124,   596,   597,   603,   599,
     150,   150,   111,   112,    71,   164,   165,    51,   160,   274,
     275,    50,     4,   278,   284,   374,    52,   282,   283,    27,
      28,    29,    30,    31,    32,   139,   140,   136,   621,    52,
      69,   160,     4,   303,   394,   395,    51,   283,    37,   304,
     498,   499,   312,    51,   145,   159,   675,   151,   152,   153,
     154,   155,   156,   578,   340,   131,    95,   314,    71,    51,
     136,   318,     4,     4,   321,     4,    65,    27,    28,   339,
     340,   700,   111,   112,   344,   345,   107,   768,   107,    51,
     130,   673,   115,   116,   609,   305,   351,   352,   353,   116,
     505,   691,   550,   363,   359,   360,   316,   367,   120,   489,
     320,   792,   560,     4,   369,   351,   352,   353,    95,    51,
      51,     4,    51,   359,   360,   380,   317,    79,   319,    29,
      30,    31,    32,   369,   717,   718,   115,   720,   721,   722,
     723,   724,   725,   621,   380,   711,   712,   713,   714,   115,
     716,     4,     4,   151,   152,   153,   154,   155,   156,   406,
     407,   408,     4,     4,     4,   313,   115,     4,    51,     5,
       6,   115,     4,     4,    10,    11,    12,   424,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    52,    51,    51,
     103,     4,   103,   458,     4,   465,     4,   467,   145,    51,
      51,    51,   100,   489,    51,   470,   621,   103,   473,    51,
      51,   103,   458,   115,   116,     4,     4,    50,   488,   489,
     485,    80,    31,    32,   470,    31,    32,   473,    71,   717,
     718,     5,   720,   721,   722,   723,   724,   725,    51,   485,
     497,    51,    13,    51,   501,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    51,    51,    14,    15,    64,   524,   136,   526,
      51,   528,   529,   493,   732,   495,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,    51,    44,   552,   553,    84,    84,   145,
     557,   121,   717,   718,   134,   720,   721,   722,   723,   724,
     725,   275,   115,   115,   278,   115,   581,   582,   282,    90,
     288,   289,   290,   291,   292,   115,    95,    71,    27,   594,
     115,   115,   115,   791,   599,   581,   582,   115,   603,   110,
     304,    87,   612,   115,    51,   113,    33,   113,   594,    51,
      69,    50,   134,   599,   134,     4,    43,   603,    69,    58,
      59,    53,    61,    95,    27,    28,    29,    30,    31,    32,
      69,     9,   629,    29,    30,    31,    32,    40,   107,   107,
     151,   152,   153,   154,   155,   156,    73,     4,    47,    76,
      33,    53,    85,    45,   143,   116,    95,    96,    97,    45,
      43,   116,   115,   673,    94,    18,   115,   106,   107,   113,
     675,     9,   111,   112,   115,   680,   115,   682,   115,    71,
      79,   686,   102,   137,   689,     4,   115,   114,    71,   675,
      89,   696,   102,    76,   121,   700,   115,   147,   116,    10,
     686,    11,   101,   689,   107,    12,    86,    99,   705,   108,
     696,   708,   709,    99,   700,   136,    95,   143,   115,   158,
      27,    28,    29,    30,    31,    32,   125,   166,   127,   121,
     129,   114,   136,   115,     4,   121,    52,   734,   121,   138,
     132,   133,   702,    51,     4,   162,   132,   133,   151,   152,
     153,   154,   155,   156,   146,   147,   115,   115,    70,   115,
     146,   147,   161,   115,   163,   770,     6,     7,   773,    52,
      18,   768,    12,    13,    52,    51,    16,    67,    16,    18,
     777,    31,    63,   122,    24,   340,   363,   773,   307,   581,
      30,   582,    32,    33,    34,   792,   470,    37,    38,   682,
      40,    93,    42,    43,    44,    45,    46,    47,    48,    49,
      50,   483,   452,   774,    54,    55,    56,    57,    58,   612,
      60,    61,    62,    63,    64,    65,   701,    67,    68,    69,
      70,   283,    72,    73,    74,    75,    76,    77,   770,    79,
      80,    81,    82,    83,    84,   696,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
      -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
     120,   121,    -1,    -1,   124,   125,    -1,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,    -1,   138,   139,
     140,    -1,   142,   143,   144,   145,   146,    -1,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    -1,    72,    73,    74,    75,    76,    77,    -1,
      79,    80,    81,    82,    83,    84,    -1,    -1,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,   120,   121,    -1,    -1,   124,   125,    -1,    -1,   128,
      -1,   130,   131,   132,   133,   134,   135,    -1,    -1,   138,
     139,   140,    -1,   142,   143,   144,   145,   146,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,    -1,   163,   164,   165,   166,     6,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    -1,    60,    61,    62,    63,    64,    65,    -1,    67,
      68,    69,    70,    -1,    72,    73,    -1,    75,    76,    77,
      -1,    79,    80,    81,    82,    83,    84,    -1,    -1,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,    -1,    -1,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,   120,   121,    -1,    -1,   124,   125,    -1,    -1,
     128,    -1,   130,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    -1,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,     6,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,
      37,    38,    -1,    40,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    -1,    72,    73,    74,    75,    76,
      77,    -1,    79,    80,    81,    82,    83,    84,    -1,    -1,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    -1,   111,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,   120,   121,    -1,    -1,   124,   125,    -1,
      -1,   128,    -1,   130,   131,   132,   133,   134,   135,    -1,
      -1,   138,   139,   140,    -1,   142,   143,   144,   145,   146,
      -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,    -1,   163,   164,   165,   166,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,
      -1,    37,    38,    -1,    40,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    65,
      -1,    67,    68,    69,    70,    -1,    72,    73,    -1,    75,
      76,    77,    -1,    79,    80,    81,    82,    83,    84,    -1,
      -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    -1,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,   120,   121,    -1,    -1,   124,   125,
      -1,    -1,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    -1,    72,    73,    -1,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,    84,
      -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,   124,
     125,    -1,    -1,   128,    -1,   130,   131,   132,   133,   134,
     135,    -1,    -1,   138,   139,   140,    -1,   142,   143,   144,
     145,   146,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    27,    28,    29,    30,    31,    32,    32,    33,
      34,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    51,    -1,    -1,    -1,
      54,    -1,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    65,    -1,    67,    -1,    -1,    70,    -1,    72,    73,
      -1,    75,    76,    77,    -1,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    88,    89,    90,    91,    27,    28,
      29,    30,    31,    32,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,    -1,    51,    -1,    -1,    -1,   120,   121,    -1,    -1,
     124,   125,    -1,    -1,   128,    -1,   130,   131,   132,   133,
     134,   135,     7,     8,   138,   139,   140,    -1,   142,   143,
     144,   145,   146,    -1,   148,    -1,   151,   152,   153,   154,
     155,   156,    27,   157,    -1,   159,   160,   161,    -1,   163,
      -1,    -1,   166,    -1,    47,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      55,    56,    -1,    58,    59,    -1,    61,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    84,
      -1,    -1,   151,   152,   153,   154,   155,   156,   101,    -1,
      95,    96,    97,    -1,    -1,   108,    -1,    -1,    -1,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,   112,    -1,    -1,
     115,    -1,   125,    -1,   127,    -1,   129,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,   138,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    16,    -1,   161,    -1,
     163,    -1,    -1,   158,    24,    -1,    -1,    -1,    -1,   164,
     165,   166,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    56,    57,    -1,    -1,
      60,    -1,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    77,    -1,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,    -1,    -1,   124,   125,    -1,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,    -1,    -1,   138,   139,
     140,    -1,   142,   143,   144,   145,   146,    -1,   148,    -1,
      -1,    -1,     6,     7,    10,    11,    12,   157,    12,   159,
     160,   161,    16,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    27,    28,    29,    30,    31,    32,    -1,    32,    33,
      34,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      54,    -1,    56,    57,    -1,    -1,    60,    -1,    62,    63,
      64,    65,    -1,    67,    -1,    -1,    70,    -1,    72,    73,
      -1,    75,    76,    77,    -1,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,    -1,    -1,    -1,    -1,   119,   120,   121,    -1,    -1,
     124,   125,    -1,    -1,   128,    -1,   130,   131,   132,   133,
     134,   135,    -1,    -1,   138,   139,   140,    -1,   142,   143,
     144,   145,   146,    -1,   148,    -1,    -1,    -1,     6,     7,
      -1,    11,    12,   157,    12,   159,   160,   161,    16,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    27,    28,    29,
      30,    31,    32,    -1,    32,    33,    34,    -1,    -1,    37,
      -1,    -1,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    57,
      -1,    -1,    60,    -1,    62,    63,    64,    65,    -1,    67,
      -1,    -1,    70,    -1,    72,    73,    -1,    75,    76,    77,
      -1,    79,    80,    81,    82,    83,    84,    -1,    -1,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,   120,   121,    -1,    -1,   124,   125,    -1,    -1,
     128,    -1,   130,   131,   132,   133,   134,   135,    -1,    -1,
     138,   139,   140,    -1,   142,   143,   144,   145,   146,    -1,
     148,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,   157,
      12,   159,   160,   161,    16,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    56,    57,    -1,    -1,    60,    -1,
      62,    63,    64,    65,    -1,    67,    -1,    -1,    70,    -1,
      72,    73,    -1,    75,    76,    77,    -1,    79,    80,    81,
      82,    83,    84,    -1,    -1,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,
      -1,    -1,   124,   125,    -1,    -1,   128,    -1,   130,   131,
     132,   133,   134,   135,    -1,    -1,   138,   139,   140,    -1,
     142,   143,   144,   145,   146,    -1,   148,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,   157,    12,   159,   160,   161,
      16,   163,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
      56,    57,    -1,    -1,    60,    -1,    62,    63,    64,    65,
      -1,    67,    -1,    -1,    70,    -1,    72,    73,    -1,    75,
      76,    77,    -1,    79,    80,    81,    82,    83,    84,    -1,
      -1,    87,    88,    89,    90,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,    -1,
      -1,    -1,    -1,    -1,   120,   121,    -1,    -1,   124,   125,
      -1,    -1,   128,    -1,   130,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,    -1,   148,    -1,    -1,    -1,     6,     7,    -1,    -1,
      -1,   157,    12,   159,   160,   161,    16,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    27,    28,    29,    30,
      31,    32,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      51,    -1,    -1,    -1,    54,    -1,    56,    57,    -1,    -1,
      60,    -1,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      70,    -1,    72,    73,    -1,    75,    76,    77,    -1,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,    -1,    -1,    -1,    -1,   410,
     120,   121,   413,    -1,   124,   125,    -1,    -1,   128,    -1,
     130,   131,   132,   133,   134,   135,   427,   428,   138,   139,
     140,    -1,   142,   143,   144,   145,   146,    -1,   148,    -1,
     151,   152,   153,   154,   155,   156,    -1,   157,    -1,   159,
     160,   161,    13,   163,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      51,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     511,   512,    -1,   514,    -1,   516,   517,    -1,    -1,    -1,
      -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,    90,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   110,
      27,    28,    29,    30,    31,    32,    27,    28,    29,    30,
      31,    32,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   154,   155,   156,   151,   152,   153,   154,
     155,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,   156,
     151,   152,   153,   154,   155,   156,    67,     4,     5,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    52,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    52,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    52,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    52,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      51,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,    -1,    -1,    -1,    10,    11,    12,    51,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    57,   168,   169,     8,   107,     0,    63,   170,   171,
      71,    71,     8,    83,   124,   160,   172,   173,    91,   178,
     179,   107,   175,   176,   107,   174,   116,   176,    71,   173,
     130,   180,   181,   120,   182,   183,     4,    49,    58,    60,
      62,    77,    83,    92,    93,   105,   139,   140,   159,   177,
      95,   279,   177,    79,    71,   181,    45,    99,   121,   132,
     133,   146,   147,   184,   185,   131,   136,   186,   187,   188,
     242,   176,   115,   115,   115,   115,    52,   176,   103,   103,
     100,   145,   103,   103,    50,   280,    71,   185,   280,   243,
      80,   190,    71,   137,    71,   177,   279,   279,   279,   279,
     176,     5,   279,   279,   279,    78,   128,   280,   279,   279,
      64,   189,    35,    66,   150,   250,    33,    43,    73,    76,
     114,   121,   192,   193,   242,    51,     4,    51,     4,    51,
      51,   177,   280,   280,   280,   280,   117,   118,   196,   197,
       6,     7,    12,    16,    24,    30,    32,    33,    34,    37,
      38,    40,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    54,    55,    56,    57,    58,    60,    61,    62,    63,
      64,    65,    67,    68,    69,    70,    72,    73,    75,    76,
      77,    79,    80,    81,    82,    83,    84,    87,    88,    89,
      90,    91,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   111,   112,   113,   114,
     115,   120,   121,   124,   125,   128,   130,   131,   132,   133,
     134,   135,   138,   139,   140,   142,   143,   144,   145,   146,
     148,   157,   158,   159,   160,   161,   163,   164,   165,   166,
     199,   241,   251,   252,   255,   281,   282,    84,    84,   134,
     121,    73,    98,    87,   148,    71,   191,   193,   279,   279,
     198,    50,    95,   202,   203,   204,   235,   236,   237,   239,
     281,   115,   115,   115,   115,   115,   281,    95,   115,   255,
     115,   115,   115,     4,    82,   210,   215,    27,    28,    29,
      30,    31,    32,    40,   107,   151,   152,   153,   154,   155,
     156,   254,   256,    69,   115,   116,   113,   113,    71,    87,
     134,   134,    47,    79,    89,   101,   108,   125,   127,   129,
     138,   161,   163,   261,   262,   263,   265,   267,   269,   272,
     273,   274,   276,   277,   278,   261,    51,    51,   202,    69,
       4,    37,    65,   205,    69,    53,   116,   238,    35,    66,
     150,   234,   234,   234,   255,   259,   259,   259,    51,   234,
     234,   259,   252,   119,   211,   212,   213,   235,   281,     9,
     209,   216,    94,   117,   149,   200,   246,    27,    28,   257,
     258,   257,   257,   257,   257,   257,   107,    30,   281,   259,
     279,    95,   107,   194,   195,   195,   261,   261,   261,    58,
      61,   106,   166,   264,   281,   176,     7,     8,    27,    41,
      42,    50,    55,    56,    58,    59,    61,    84,    95,    96,
      97,   106,   107,   112,   115,   126,   158,   164,   165,   166,
     194,   241,   284,   286,   288,   294,   107,   279,   280,   270,
     271,   288,   280,   145,   279,   288,   261,   262,   237,   281,
     203,    30,   281,   237,    95,   255,   255,   255,     4,    51,
      51,    51,   255,   255,    51,   115,   213,     4,   240,   281,
      13,    74,   109,   115,   219,   220,   221,   222,   223,   224,
     228,   231,   233,   249,   255,    85,   207,   217,   143,   201,
     234,    94,   255,   116,    51,     4,    52,   116,   261,   261,
     115,    18,   288,   288,   288,   113,   285,   285,   285,   115,
     115,    41,    42,    55,    56,   126,   164,   165,   115,   115,
     288,   285,   285,   115,     9,   283,     5,     6,    10,    11,
      12,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
     144,   290,    18,   116,   102,   137,   275,     4,   147,   102,
      67,    71,   238,     4,    52,    51,    51,    51,   255,    51,
      51,   212,   214,   212,   222,   115,   249,   249,   136,   219,
     255,    10,    11,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   232,    13,    90,   110,   230,   232,
     208,   253,   255,    86,   206,   218,   248,   281,   202,   136,
     244,   245,   143,   279,   279,   288,   288,   291,   292,   293,
     288,    27,    58,    59,    61,    96,    97,   106,   107,   115,
     158,   166,   194,   287,   294,   292,   292,   285,   285,   285,
     285,   285,   292,   292,    51,   292,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   262,   271,   288,
     288,   262,    95,     4,    51,   250,    51,   220,   221,   255,
     115,   249,   115,   249,    14,    15,    44,    35,    36,   115,
     141,   225,   226,   227,   249,   255,     4,   219,   162,   247,
     250,   248,     4,    52,    52,     4,    52,    51,     4,   145,
     287,   115,   115,   115,   115,   288,   115,    10,    11,    12,
      27,    28,    29,    30,    31,    32,   289,    51,    51,    51,
      51,    51,    70,   268,     4,    52,    52,   212,   251,   199,
     229,   260,   229,   255,   249,   253,   251,   247,   279,   288,
     288,   288,   292,   292,   292,   292,    51,   292,   287,   287,
     287,   287,   287,   287,   287,   287,   262,   288,    18,   215,
       4,    51,    51,    11,   215,    52,    52,   142,   266,    51,
      51,    51,    51,    51,    52,   271,    51,   260,   255,   246,
     288,    67,    18,   262,   271
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
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
#line 246 "ace.yacc"
    {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
    break;

  case 4:
#line 249 "ace.yacc"
    {
		this_report.dbname=acl_strdup((yyvsp[(2) - (3)].str));
		A4GLSQL_init_connection ((yyvsp[(2) - (3)].str));
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
    break;

  case 10:
#line 273 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:
#line 277 "ace.yacc"
    {
		ace_add_variable((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str),CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:
#line 280 "ace.yacc"
    {
		ace_add_variable((yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str),CAT_PARAM,atoi((yyvsp[(3) - (6)].str)),-1,0);
	}
    break;

  case 13:
#line 283 "ace.yacc"
    {
		add_function((yyvsp[(2) - (2)].str));
	}
    break;

  case 17:
#line 294 "ace.yacc"
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
#line 307 "ace.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 20:
#line 308 "ace.yacc"
    {strcpy((yyval.str),"CHAR");}
    break;

  case 21:
#line 309 "ace.yacc"
    {sprintf((yyval.str),"CHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 22:
#line 310 "ace.yacc"
    {strcpy((yyval.str),"VARCHAR");}
    break;

  case 23:
#line 311 "ace.yacc"
    {sprintf((yyval.str),"VARCHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 24:
#line 312 "ace.yacc"
    {strcpy((yyval.str),"DATE");}
    break;

  case 25:
#line 313 "ace.yacc"
    {strcpy((yyval.str),"FLOAT");}
    break;

  case 26:
#line 314 "ace.yacc"
    {strcpy((yyval.str),"SMALLFLOAT");}
    break;

  case 27:
#line 315 "ace.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 28:
#line 316 "ace.yacc"
    {strcpy((yyval.str),"DATETIME");}
    break;

  case 29:
#line 317 "ace.yacc"
    {strcpy((yyval.str),"INTERVAL");}
    break;

  case 30:
#line 318 "ace.yacc"
    {strcpy((yyval.str),"MONEY");}
    break;

  case 31:
#line 319 "ace.yacc"
    {sprintf((yyval.str),"MONEY (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 32:
#line 320 "ace.yacc"
    {sprintf((yyval.str),"MONEY (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 33:
#line 321 "ace.yacc"
    {strcpy((yyval.str),"DECIMAL");}
    break;

  case 34:
#line 322 "ace.yacc"
    {sprintf((yyval.str),"DECIMAL (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 35:
#line 323 "ace.yacc"
    {sprintf((yyval.str),"DECIMAL (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 41:
#line 337 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes((yyvsp[(5) - (5)].str)),(yyvsp[(3) - (5)].str));
}
    break;

  case 47:
#line 352 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str));}
    break;

  case 48:
#line 353 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:
#line 354 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup((yyvsp[(3) - (3)].str)); }
    break;

  case 50:
#line 355 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str)); }
    break;

  case 51:
#line 356 "ace.yacc"
    {
		this_report.output.left_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 52:
#line 359 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 53:
#line 362 "ace.yacc"
    {
		this_report.output.top_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 54:
#line 365 "ace.yacc"
    {
		this_report.output.page_length=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 55:
#line 368 "ace.yacc"
    {
		this_report.output.right_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 56:
#line 371 "ace.yacc"
    {
		this_report.output.top_of_page=acl_strdup((yyvsp[(2) - (2)].str));
	}
    break;

  case 58:
#line 378 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:
#line 382 "ace.yacc"
    { add_select((yyvsp[(1) - (1)].str),temp_tab_name); }
    break;

  case 60:
#line 383 "ace.yacc"
    { add_select((yyvsp[(3) - (3)].str),temp_tab_name); }
    break;

  case 64:
#line 394 "ace.yacc"
    {
		struct commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,NULL,cmd);
	  }
    break;

  case 70:
#line 413 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 71:
#line 417 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 72:
#line 421 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 73:
#line 425 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 74:
#line 428 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 75:
#line 431 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 76:
#line 434 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 77:
#line 441 "ace.yacc"
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
#line 451 "ace.yacc"
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
#line 461 "ace.yacc"
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
#line 476 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 81:
#line 480 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;

  case 82:
#line 488 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 84:
#line 491 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:
#line 491 "ace.yacc"
    {
	printf("speclist : %s ",(yyvsp[(3) - (3)].str));
	sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str));}
    break;

  case 86:
#line 495 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:
#line 504 "ace.yacc"
    {
		sprintf((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));
	}
    break;

  case 91:
#line 514 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 92:
#line 514 "ace.yacc"
    { sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str)); }
    break;

  case 94:
#line 519 "ace.yacc"
    {
sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 95:
#line 524 "ace.yacc"
    {
		if (strlen((yyvsp[(2) - (2)].str))) {
			sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 96:
#line 530 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"I%d",atoi((yyvsp[(1) - (1)].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 97:
#line 535 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"C%s",(yyvsp[(1) - (1)].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 98:
#line 542 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:
#line 550 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 102:
#line 556 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 104:
#line 562 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 105:
#line 567 "ace.yacc"
    {sprintf((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[(2) - (2)].str));}
    break;

  case 106:
#line 572 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 108:
#line 578 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 109:
#line 582 "ace.yacc"
    {sprintf((yyval.str)," %s ", (yyvsp[(1) - (1)].str));}
    break;

  case 110:
#line 583 "ace.yacc"
    {sprintf((yyval.str)," %s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 111:
#line 584 "ace.yacc"
    {sprintf((yyval.str)," %s (%s) ",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 113:
#line 588 "ace.yacc"
    {
		sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		ace_add_table((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 115:
#line 596 "ace.yacc"
    { sprintf((yyval.str)," %s,%s ",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 116:
#line 604 "ace.yacc"
    {
sprintf((yyval.str),"%s %s %s %s",
(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),
(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
}
    break;

  case 117:
#line 611 "ace.yacc"
    {strcpy((yyval.str),"\n0");}
    break;

  case 119:
#line 615 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 121:
#line 619 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 124:
#line 627 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 126:
#line 633 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 128:
#line 639 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 130:
#line 645 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 131:
#line 650 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 132:
#line 651 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 133:
#line 657 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 134:
#line 659 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 140:
#line 697 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 141:
#line 699 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 142:
#line 701 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 143:
#line 703 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 145:
#line 710 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 146:
#line 713 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 148:
#line 720 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 149:
#line 722 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 150:
#line 724 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 151:
#line 726 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 152:
#line 728 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 162:
#line 742 "ace.yacc"
    {sprintf((yyval.str),"<=");}
    break;

  case 163:
#line 743 "ace.yacc"
    {sprintf((yyval.str),">=");}
    break;

  case 168:
#line 753 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:
#line 767 "ace.yacc"
    { sprintf((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[(1) - (1)].str))); }
    break;

  case 173:
#line 768 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 174:
#line 769 "ace.yacc"
    { sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 175:
#line 770 "ace.yacc"
    { sprintf((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[(1) - (3)].str)),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 177:
#line 780 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 178:
#line 784 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 179:
#line 785 "ace.yacc"
    {sprintf((yyval.str),"[%s]",(yyvsp[(2) - (3)].str));}
    break;

  case 180:
#line 786 "ace.yacc"
    {sprintf((yyval.str),"[%s,%s]",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));}
    break;

  case 181:
#line 789 "ace.yacc"
    { sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 182:
#line 790 "ace.yacc"
    { sprintf((yyval.str),"%s.%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); }
    break;

  case 183:
#line 791 "ace.yacc"
    { sprintf((yyval.str),"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 186:
#line 802 "ace.yacc"
    {sprintf((yyval.str),"0.%s",(yyvsp[(2) - (2)].str));}
    break;

  case 187:
#line 817 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 188:
#line 820 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));
}
    break;

  case 190:
#line 841 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str) );}
    break;

  case 191:
#line 845 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 192:
#line 846 "ace.yacc"
    {
       sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
       }
    break;

  case 194:
#line 850 "ace.yacc"
    {
       sprintf((yyval.str),"INTO TEMP %s%s ",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (4)].str));
}
    break;

  case 195:
#line 854 "ace.yacc"
    {
       sprintf((yyval.str),"%s INTO TEMP %s%s ",(yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (5)].str));
}
    break;

  case 196:
#line 862 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 197:
#line 862 "ace.yacc"
    {strcpy((yyval.str)," WITH NO LOG");}
    break;

  case 199:
#line 884 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 200:
#line 887 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 201:
#line 888 "ace.yacc"
    {sprintf((yyval.str),"ALL");}
    break;

  case 202:
#line 889 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 203:
#line 890 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 205:
#line 895 "ace.yacc"
    { sprintf((yyval.str)," %s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 206:
#line 899 "ace.yacc"
    {
			add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
		}
    break;

  case 207:
#line 902 "ace.yacc"
    {
			sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_select_column((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 208:
#line 906 "ace.yacc"
    {
			sprintf((yyval.str)," %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
			add_select_column((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 210:
#line 917 "ace.yacc"
    {sprintf((yyval.str),"UNITS YEAR");}
    break;

  case 211:
#line 918 "ace.yacc"
    {sprintf((yyval.str),"UNITS MONTH"); }
    break;

  case 212:
#line 919 "ace.yacc"
    {sprintf((yyval.str),"UNITS DAY);"); }
    break;

  case 213:
#line 920 "ace.yacc"
    {sprintf((yyval.str),"UNITS HOUR);"); }
    break;

  case 214:
#line 921 "ace.yacc"
    {sprintf((yyval.str),"UNITS MINUTE);"); }
    break;

  case 215:
#line 922 "ace.yacc"
    {sprintf((yyval.str),"UNITS SECOND);"); }
    break;

  case 216:
#line 926 "ace.yacc"
    { sprintf((yyval.str),"%s%s", (yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 219:
#line 929 "ace.yacc"
    {sprintf((yyval.str)," %s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 220:
#line 930 "ace.yacc"
    {sprintf((yyval.str)," %s[%s,%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 221:
#line 931 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 222:
#line 932 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s,%s]",(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str));}
    break;

  case 223:
#line 933 "ace.yacc"
    {
			if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
			sprintf((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
			}
    break;

  case 224:
#line 938 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 225:
#line 940 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 229:
#line 944 "ace.yacc"
    {sprintf((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 230:
#line 945 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 231:
#line 946 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 232:
#line 947 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 233:
#line 948 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 234:
#line 949 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 235:
#line 950 "ace.yacc"
    {sprintf((yyval.str),"%s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 236:
#line 953 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 237:
#line 955 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 238:
#line 957 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 239:
#line 959 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 240:
#line 961 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 241:
#line 965 "ace.yacc"
    {sprintf((yyval.str),"/%s",(yyvsp[(2) - (2)].str));}
    break;

  case 242:
#line 966 "ace.yacc"
    {sprintf((yyval.str)," MOD %s",(yyvsp[(2) - (2)].str));}
    break;

  case 243:
#line 967 "ace.yacc"
    {sprintf((yyval.str)," POW %s",(yyvsp[(2) - (2)].str));}
    break;

  case 244:
#line 968 "ace.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 245:
#line 969 "ace.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 246:
#line 970 "ace.yacc"
    {sprintf((yyval.str),"+%s",(yyvsp[(2) - (2)].str));}
    break;

  case 247:
#line 971 "ace.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 248:
#line 974 "ace.yacc"
    { sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 249:
#line 977 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 250:
#line 978 "ace.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 251:
#line 979 "ace.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 253:
#line 984 "ace.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 255:
#line 1002 "ace.yacc"
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[(1) - (1)].cmd));
		}
    break;

  case 256:
#line 1007 "ace.yacc"
    {
		COPY((yyval.commands),(yyvsp[(1) - (2)].commands));
		(yyval.commands).commands.commands_len++;
		(yyval.commands).commands.commands_val=realloc(
		(yyval.commands).commands.commands_val,
		(yyval.commands).commands.commands_len*sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[ (yyval.commands).commands.commands_len-1 ],(yyvsp[(2) - (2)].cmd));
	}
    break;

  case 267:
#line 1029 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).command_u.commands.commands.commands_val=(yyvsp[(2) - (3)].commands).commands.commands_val;
		(yyval.cmd).command_u.commands.commands.commands_len=(yyvsp[(2) - (3)].commands).commands.commands_len;
	}
    break;

  case 268:
#line 1066 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[(2) - (5)].str));
	
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(4) - (5)].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).command_u.cmd_call.fcall->lexpr);
}
    break;

  case 274:
#line 1084 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_FOR;
		(yyval.cmd).command_u.cmd_for.varid=find_variable((yyvsp[(2) - (9)].str));
		COPY((yyval.cmd).command_u.cmd_for.start,(yyvsp[(4) - (9)].expr));
		COPY((yyval.cmd).command_u.cmd_for.finish,(yyvsp[(6) - (9)].expr));
		COPY((yyval.cmd).command_u.cmd_for.step,(yyvsp[(7) - (9)].expr));
		(yyval.cmd).command_u.cmd_for.command=(struct command *)DUP((yyvsp[(9) - (9)].cmd));
	}
    break;

  case 275:
#line 1094 "ace.yacc"
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
    break;

  case 276:
#line 1095 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (2)].expr));}
    break;

  case 277:
#line 1099 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_IF;
	COPY((yyval.cmd).command_u.cmd_if.condition,(yyvsp[(2) - (5)].expr));
	(yyval.cmd).command_u.cmd_if.command=(struct command *)DUP((yyvsp[(4) - (5)].cmd));
	(yyval.cmd).command_u.cmd_if.elsecommand=(struct command *)DUP((yyvsp[(5) - (5)].cmd));
}
    break;

  case 278:
#line 1107 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).command_u.null=1;
	}
    break;

  case 279:
#line 1110 "ace.yacc"
    { COPY((yyval.cmd),(yyvsp[(2) - (2)].cmd)); }
    break;

  case 280:
#line 1115 "ace.yacc"
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

  case 281:
#line 1126 "ace.yacc"
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

  case 282:
#line 1137 "ace.yacc"
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

  case 283:
#line 1150 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
    break;

  case 286:
#line 1157 "ace.yacc"
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 287:
#line 1169 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).command_u.cmd_need.nlines=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 288:
#line 1175 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).command_u.cmd_pause.message=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 289:
#line 1182 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).command_u.cmd_print.printnl=atoi((yyvsp[(3) - (3)].str));
	(yyval.cmd).command_u.cmd_print.print=(yyvsp[(2) - (3)].expr);
}
    break;

  case 290:
#line 1190 "ace.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 291:
#line 1190 "ace.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 292:
#line 1193 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).command_u.cmd_printfile.filename=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 293:
#line 1199 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=atoi((yyvsp[(2) - (3)].str));

	}
    break;

  case 294:
#line 1204 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=-1;
	}
    break;

  case 295:
#line 1211 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		COPY((yyval.cmd).command_u.cmd_while.condition,(yyvsp[(2) - (4)].expr));
		(yyval.cmd).command_u.cmd_while.command=(struct command *)DUP((yyvsp[(4) - (4)].cmd));
}
    break;

  case 379:
#line 1319 "ace.yacc"
    {
			(yyval.exprptr)=0;
		}
    break;

  case 380:
#line 1323 "ace.yacc"
    { 
			(yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); 
		}
    break;

  case 381:
#line 1330 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (2)].agg_val));
		(yyval.agg_val).wexpr=(yyvsp[(2) - (2)].exprptr); 
		}
    break;

  case 382:
#line 1338 "ace.yacc"
    { (yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); }
    break;

  case 383:
#line 1342 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 384:
#line 1348 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 385:
#line 1354 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 386:
#line 1360 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 387:
#line 1366 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 388:
#line 1372 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 389:
#line 1378 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 390:
#line 1385 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 391:
#line 1391 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 392:
#line 1397 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 393:
#line 1403 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 394:
#line 1409 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 395:
#line 1415 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 396:
#line 1421 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 397:
#line 1431 "ace.yacc"
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

  case 398:
#line 1449 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 399:
#line 1451 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 400:
#line 1455 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 401:
#line 1459 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 402:
#line 1463 "ace.yacc"
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

  case 403:
#line 1472 "ace.yacc"
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

  case 404:
#line 1482 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 405:
#line 1489 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 406:
#line 1495 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 407:
#line 1501 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 408:
#line 1508 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 409:
#line 1514 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 410:
#line 1515 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 411:
#line 1520 "ace.yacc"
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

  case 412:
#line 1542 "ace.yacc"
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

  case 413:
#line 1560 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 414:
#line 1562 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 415:
#line 1566 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 416:
#line 1570 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 417:
#line 1574 "ace.yacc"
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

  case 418:
#line 1583 "ace.yacc"
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

  case 419:
#line 1593 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 420:
#line 1600 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 421:
#line 1606 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 422:
#line 1612 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 423:
#line 1619 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 424:
#line 1625 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 425:
#line 1626 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 426:
#line 1632 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 427:
#line 1638 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 428:
#line 1643 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 429:
#line 1648 "ace.yacc"
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

  case 430:
#line 1670 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 431:
#line 1678 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 432:
#line 1686 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 433:
#line 1694 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 434:
#line 1701 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 435:
#line 1710 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 436:
#line 1716 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 437:
#line 1725 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 438:
#line 1732 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 439:
#line 1741 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 440:
#line 1749 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 441:
#line 1757 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 442:
#line 1765 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 443:
#line 1772 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 444:
#line 1781 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 445:
#line 1787 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 446:
#line 1796 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 447:
#line 1803 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 448:
#line 1811 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 449:
#line 1817 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 450:
#line 1823 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 451:
#line 1829 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 452:
#line 1835 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 453:
#line 1841 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 454:
#line 1847 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 455:
#line 1853 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 456:
#line 1859 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 457:
#line 1865 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 458:
#line 1871 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 459:
#line 1879 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_SPACES; 
	}
    break;

  case 460:
#line 1886 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 461:
#line 1892 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 462:
#line 1900 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 463:
#line 1918 "ace.yacc"
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

  case 464:
#line 1929 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 465:
#line 1936 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
	}
    break;

  case 466:
#line 1943 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 467:
#line 1952 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_NULL;
	}
    break;

  case 468:
#line 1958 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 469:
#line 1962 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 470:
#line 1966 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 471:
#line 1970 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 5186 "y.tab.c"
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1996 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

