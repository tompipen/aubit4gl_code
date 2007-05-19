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
     KW_OF = 362,
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
#define KW_OF 362
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
#line 509 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 522 "y.tab.c"

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
#define YYLAST   3169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  126
/* YYNRULES -- Number of rules.  */
#define YYNRULES  435
/* YYNRULES -- Number of states.  */
#define YYNSTATES  728

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164
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
    1197,  1199,  1201,  1206,  1211,  1216,  1221,  1226,  1230,  1233,
    1236,  1239,  1242,  1245,  1248,  1251,  1253,  1255,  1257,  1259,
    1261,  1265,  1266,  1268,  1270,  1272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     166,     0,    -1,   167,   168,   176,   180,   184,   188,    -1,
      52,    31,    65,    -1,    52,   101,    65,    -1,    -1,   169,
      -1,    57,   170,    65,    -1,   171,    -1,   170,   171,    -1,
      31,   173,    -1,   158,   174,   175,    -1,   118,   110,   279,
      45,   174,   175,    -1,    77,   172,    -1,   101,    -1,   174,
     175,    -1,   173,    48,   174,   175,    -1,   101,    -1,    77,
      -1,    86,    -1,    41,    -1,    41,   109,   279,    44,    -1,
     157,    -1,   157,   109,   279,    44,    -1,    53,    -1,    71,
      -1,   134,    -1,   135,    -1,    54,    -1,    87,    -1,    99,
      -1,    99,   109,   279,    44,    -1,    99,   109,   279,    48,
     279,    44,    -1,    56,    -1,    56,   109,   279,    44,    -1,
      56,   109,   279,    48,   279,    44,    -1,    -1,   177,    -1,
      85,   178,    65,    -1,   179,    -1,   178,   179,    -1,   125,
      73,   174,     3,   280,    -1,    -1,   181,    -1,   114,   182,
      65,    -1,   183,    -1,   182,   183,    -1,   127,   142,   123,
     280,    -1,   127,   142,   123,    -1,   127,   142,   280,    -1,
     127,   142,    72,   280,    -1,    93,    97,   279,    -1,    37,
      97,   279,    -1,   143,    97,   279,    -1,   115,    94,   279,
      -1,   128,    97,   279,    -1,   144,   280,    -1,   186,    65,
      -1,   185,    65,    -1,   243,    -1,   185,   132,   243,    -1,
     126,   280,   187,   194,    -1,    -1,    58,   280,    -1,    74,
      67,   129,    65,    -1,    74,   190,   189,    -1,    -1,    65,
      -1,   191,    -1,   190,   191,    -1,    70,   115,    81,   261,
      -1,   115,   146,   261,    -1,   115,    81,   261,    -1,   108,
      67,   129,   261,    -1,   108,    92,   129,   261,    -1,    35,
      78,   107,   193,   261,    -1,    26,    78,   107,   193,   261,
      -1,   101,   110,   283,    48,   283,    45,    -1,   101,   110,
     283,    45,    -1,   101,    -1,   192,    -1,    89,    -1,    -1,
     195,    -1,    -1,   111,   196,   200,    -1,   112,   200,    -1,
      42,    -1,   106,    -1,   242,    -1,    89,    -1,    -1,   111,
     199,   200,    -1,   201,    -1,   200,    48,   201,    -1,   202,
     203,    -1,    89,    -1,   240,    -1,    -1,    30,    -1,    59,
      -1,    80,   217,    -1,    79,   206,    -1,   254,    -1,   206,
      48,   254,    -1,     4,   217,    -1,    76,   209,    -1,   210,
      -1,   209,    48,   210,    -1,   211,    -1,   113,   211,    -1,
     113,   109,   212,    44,    -1,   236,    -1,   236,   241,    -1,
     210,    -1,   212,    48,   210,    -1,   208,   214,   215,   216,
      -1,    -1,   207,    -1,    -1,   205,    -1,    -1,   204,    -1,
     218,    -1,   217,     5,   218,    -1,   219,    -1,   218,     6,
     219,    -1,   220,    -1,     7,   220,    -1,   234,    -1,   109,
     217,    44,    -1,    68,   250,    -1,   103,   250,    -1,   256,
     233,   223,   250,    -1,   250,   233,   256,    -1,   224,    -1,
     225,    -1,    28,    -1,   136,    -1,    29,    -1,    66,   228,
      -1,   260,    -1,   260,    -1,   256,    84,   109,   230,    44,
      -1,   256,    84,   250,    -1,   256,   104,   109,   230,    44,
      -1,   256,   104,   250,    -1,   260,    -1,   230,    48,   260,
      -1,    -1,     7,    -1,   256,   231,     8,    -1,   256,   231,
       9,    -1,   256,   233,   256,    -1,   256,   233,   250,    -1,
     256,   231,    36,   256,     6,   256,    -1,   256,   231,    17,
     227,   226,    -1,    11,    -1,    50,    -1,    10,    -1,    13,
      -1,    15,    -1,    18,    -1,    16,    -1,    19,    -1,    17,
      -1,    12,    -1,    14,    -1,   232,    -1,   229,    -1,   222,
      -1,   221,    -1,    -1,    28,    -1,    60,    -1,   148,    -1,
      42,    -1,   238,    -1,   237,    46,   238,    -1,    42,    63,
     238,    -1,   281,    -1,   281,    -1,    -1,   110,    89,    45,
      -1,   110,    89,    48,    89,    45,    -1,   281,   239,    -1,
     236,    63,   281,   239,    -1,   236,    63,    23,    -1,   281,
      -1,   105,    -1,    63,    89,    -1,    -1,   131,   244,   251,
     252,   213,   247,    -1,   246,    -1,   131,   251,   252,   213,
     247,    -1,    -1,   147,   235,   245,    -1,   198,    -1,    88,
     140,   249,   248,    -1,   198,    88,   140,   249,   248,    -1,
      -1,   160,    -1,   281,    -1,   109,   131,   251,   252,   213,
      44,    -1,    -1,    28,    -1,    60,    -1,   148,    -1,   253,
      -1,   252,    48,   253,    -1,   256,    -1,   256,   101,    -1,
     256,    -1,   154,    -1,   152,    -1,   149,    -1,   150,    -1,
     151,    -1,   153,    -1,   256,   257,    -1,   197,    -1,   281,
      -1,   281,   110,   279,    45,    -1,   281,   110,   279,    48,
     279,    45,    -1,   281,    63,   281,   110,   279,    45,    -1,
     281,    63,   281,   110,   279,    48,   279,    45,    -1,    62,
     281,    -1,   281,    63,   281,    -1,   281,    63,    23,    -1,
      91,    -1,    90,    -1,   156,    -1,    23,    -1,   109,   256,
      44,    -1,    53,   109,   259,    44,    -1,    55,   109,   259,
      44,    -1,   100,   109,   259,    44,    -1,   164,   109,   259,
      44,    -1,   281,   109,   259,    44,    -1,    51,   109,    23,
      44,    -1,    34,   109,   235,   256,    44,    -1,   162,   109,
     235,   256,    44,    -1,   163,   109,   235,   256,    44,    -1,
     139,   109,   235,   256,    44,    -1,    51,   109,   235,   256,
      44,    -1,    22,   258,    -1,    24,   258,    -1,   121,   258,
      -1,   255,    -1,    23,   258,    -1,    21,   258,    -1,    20,
     258,    -1,   256,    -1,    21,   256,    -1,    20,   256,    -1,
     256,    -1,   259,    48,   256,    -1,    -1,   197,    -1,   262,
      -1,   261,   262,    -1,   265,    -1,   267,    -1,   278,    -1,
     269,    -1,   272,    -1,   273,    -1,   277,    -1,   274,    -1,
     276,    -1,   263,    -1,   161,   261,    65,    -1,    39,   264,
     109,   287,    44,    -1,    53,    -1,   100,    -1,   164,    -1,
      55,    -1,   281,    -1,    73,   174,    11,   283,   142,   283,
     266,    61,   262,    -1,    -1,   138,   283,    -1,    83,   283,
     141,   262,   268,    -1,    -1,    64,   262,    -1,    95,   101,
      11,   271,    -1,    95,   101,   110,   283,    45,    11,   271,
      -1,    95,   101,   110,   283,    48,   283,    45,    11,   271,
      -1,    -1,   271,    -1,   283,    -1,   271,    48,   283,    -1,
     102,   279,    96,    -1,   119,   280,    -1,   122,   270,   275,
      -1,    -1,   132,    -1,   124,   280,    -1,   133,   279,    96,
      -1,   133,   142,   144,    -1,   159,   283,    61,   262,    -1,
      89,    -1,    42,    -1,   101,    -1,   282,    -1,    26,    -1,
      30,    -1,    27,    -1,    35,    -1,    36,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    43,    -1,
      47,    -1,    49,    -1,    50,    -1,    52,    -1,    54,    -1,
      56,    -1,    57,    -1,    58,    -1,    59,    -1,    61,    -1,
      64,    -1,    66,    -1,    67,    -1,    69,    -1,    70,    -1,
      71,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    17,    -1,    96,    -1,    97,    -1,    98,    -1,
      99,    -1,   102,    -1,   107,    -1,   108,    -1,   114,    -1,
     115,    -1,   118,    -1,   119,    -1,   121,    -1,   123,    -1,
     125,    -1,   126,    -1,   127,    -1,   128,    -1,   129,    -1,
     130,    -1,   133,    -1,   134,    -1,   135,    -1,   137,    -1,
     138,    -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,
     145,    -1,   146,    -1,   155,    -1,   157,    -1,   158,    -1,
     159,    -1,   161,    -1,   162,    -1,   163,    -1,   286,    -1,
     285,    -1,   285,     4,   283,    -1,    78,   285,    -1,    78,
     285,     4,   283,    -1,    51,    -1,   120,    -1,    33,   107,
     283,    -1,   145,   107,   283,    -1,    34,   107,   283,    -1,
     163,   107,   283,    -1,   162,   107,   283,    -1,    20,   286,
      -1,   286,    22,   286,    -1,   286,   121,   286,    -1,   286,
      24,   286,    -1,   286,    23,   286,    -1,   286,    21,   286,
      -1,   286,     6,   286,    -1,   286,     5,   286,    -1,   286,
      20,   286,    -1,   286,     3,   286,    -1,   290,    -1,   286,
     233,   286,    -1,    91,    -1,    90,    -1,   156,    -1,    53,
      -1,    53,   109,   288,    44,    -1,   100,   109,   288,    44,
      -1,   164,   109,   288,    44,    -1,    55,   109,   288,    44,
      -1,   101,   109,   288,    44,    -1,   109,   286,    44,    -1,
      47,   286,    -1,    31,   286,    -1,   286,   137,    -1,   286,
       8,    -1,   286,     9,    -1,   286,    43,    -1,   286,   255,
      -1,   192,    -1,   284,    -1,   289,    -1,   288,    -1,   286,
      -1,   288,    48,   286,    -1,    -1,    42,    -1,   106,    -1,
     242,    -1,    89,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
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
     483,   501,   501,   505,   506,   511,   513,   518,   525,   526,
     527,   532,   538,   543,   544,   550,   555,   559,   560,   565,
     566,   567,   570,   571,   579,   579,   583,   594,   595,   598,
     599,   602,   603,   608,   609,   614,   615,   620,   621,   626,
     627,   633,   634,   639,   641,   648,   649,   652,   656,   657,
     665,   670,   674,   679,   681,   683,   685,   691,   692,   696,
     697,   702,   704,   706,   708,   710,   712,   719,   720,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   734,   735,
     736,   737,   739,   740,   741,   742,   772,   773,   774,   775,
     781,   785,   789,   790,   791,   794,   795,   796,   802,   807,
     807,   822,   822,   840,   843,   850,   851,   854,   855,   859,
     867,   867,   871,   888,   892,   893,   894,   895,   899,   900,
     904,   907,   914,   917,   918,   919,   920,   921,   922,   926,
     929,   930,   931,   932,   933,   934,   935,   940,   942,   944,
     945,   946,   947,   948,   949,   950,   951,   952,   953,   954,
     956,   958,   960,   962,   964,   969,   970,   971,   972,   973,
     974,   975,   978,   979,   980,   984,   984,   990,   991,  1003,
    1008,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    1029,  1030,  1067,  1078,  1079,  1080,  1081,  1082,  1085,  1094,
    1095,  1099,  1107,  1110,  1115,  1126,  1137,  1150,  1154,  1157,
    1157,  1169,  1175,  1182,  1190,  1190,  1193,  1199,  1204,  1211,
    1220,  1223,  1227,  1228,  1233,  1234,  1235,  1237,  1238,  1239,
    1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,  1311,  1312,  1313,  1340,  1344,  1348,  1353,  1357,  1365,
    1370,  1375,  1380,  1385,  1390,  1395,  1403,  1422,  1430,  1437,
    1446,  1453,  1460,  1468,  1477,  1484,  1491,  1493,  1500,  1504,
    1508,  1512,  1522,  1529,  1535,  1541,  1548,  1554,  1555,  1561,
    1567,  1574,  1580,  1588,  1595,  1599,  1609,  1615,  1626,  1633,
    1640,  1649,  1655,  1659,  1663,  1667
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
  "DATABASE", "DATE", "DATETIME", "DAY", "DECIMAL", "DEFINE", "DELIMITER",
  "DESC", "DISTINCT", "DO", "DOLLAR", "DOT", "ELSE", "END", "ESCAPE",
  "EVERY", "EXISTS", "EXTERNAL", "FIRST", "FLOAT", "PIPE", "FOR", "FORMAT",
  "FRACTION", "FROM", "FUNCTION", "GROUP", "GROUP_BY", "HAVING", "HEADER",
  "HOUR", "IF", "IN", "INPUT", "INTEGER", "INTERVAL", "INTO", "INTVAL",
  "KW_FALSE", "KW_TRUE", "LAST", "LEFT", "LENGTH", "LET", "LINES",
  "MARGIN", "MINUTE", "MONEY", "MONTH", "NAMED", "NEED", "NOT_EXISTS",
  "NOT_IN", "NUMBER_VALUE", "NUMERIC", "KW_OF", "ON", "OPEN_BRACKET",
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
     415,   416,   417,   418,   419
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
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
     197,   199,   198,   200,   200,   201,   202,   202,   203,   203,
     203,   204,   205,   206,   206,   207,   208,   209,   209,   210,
     210,   210,   211,   211,   212,   212,   213,   214,   214,   215,
     215,   216,   216,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   224,   225,   225,
     226,   227,   228,   229,   229,   229,   229,   230,   230,   231,
     231,   232,   232,   232,   232,   232,   232,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   234,
     234,   234,   235,   235,   235,   235,   236,   236,   236,   236,
     237,   238,   239,   239,   239,   240,   240,   240,   241,   242,
     242,   244,   243,   245,   246,   247,   247,   247,   247,   247,
     248,   248,   249,   250,   251,   251,   251,   251,   252,   252,
     253,   253,   254,   255,   255,   255,   255,   255,   255,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   257,   257,   257,   257,   257,
     257,   257,   258,   258,   258,   259,   259,   260,   260,   261,
     261,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   263,   264,   264,   264,   264,   264,   265,   266,
     266,   267,   268,   268,   269,   269,   269,   270,   270,   271,
     271,   272,   273,   274,   275,   275,   276,   277,   277,   278,
     279,   280,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   283,   284,   284,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   287,   287,   288,
     288,   289,   290,   290,   290,   290
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
       1,     1,     4,     4,     4,     4,     4,     3,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
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
     432,     0,   389,   411,     0,     0,   435,   409,   408,     0,
      79,   433,     0,   390,     0,   410,     0,     0,     0,   425,
     434,     0,   426,   385,   384,   406,     0,     0,   292,   294,
     288,   289,   296,     0,     0,     0,     0,   260,   179,   181,
      94,   187,   182,   178,     0,     0,   239,     0,   234,     0,
     235,   236,     0,     0,     0,   237,     0,   110,     0,   113,
     188,     0,     0,     0,     0,   105,   123,   125,   127,   171,
     170,   169,   168,   129,     0,   149,     0,   120,   121,     0,
       0,     0,     0,   254,   253,     0,   238,   222,     0,     0,
      76,    75,   431,     0,   396,   419,     0,     0,   418,     0,
       0,   387,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   421,   422,   159,   157,   166,   160,
     167,   161,   163,   165,   162,   164,     0,     0,     0,     0,
       0,   423,   158,     0,   420,     0,   424,     0,     0,   291,
     295,   293,     0,   298,   297,     0,   271,   186,   183,     0,
     240,   244,   256,   243,   241,   242,   114,     0,   108,   128,
       0,   131,   132,   204,     0,   149,     0,     0,     0,   150,
       0,     0,     0,     0,   102,   103,   212,     0,   122,   116,
     200,   202,    92,   204,   196,   193,     0,     0,     0,     0,
     429,     0,   428,   427,     0,   391,   393,     0,     0,     0,
       0,     0,   417,   392,   395,   394,     0,   282,   386,   405,
     403,   402,   404,   401,   397,   400,   399,   398,   407,   284,
       0,   290,   299,     0,   111,     0,     0,   130,   124,   126,
     134,   257,   144,   257,   146,   151,   152,   257,     0,   137,
     139,     0,   138,     0,   135,   136,   154,   153,     0,   101,
     201,   198,     0,   200,   224,     0,   223,    78,     0,   272,
       0,     0,   412,   415,   388,   413,   416,   414,     0,   281,
       0,     0,   184,   115,     0,   258,     0,   147,     0,     0,
     141,     0,   133,   104,     0,   199,     0,     0,   430,   279,
     283,     0,     0,     0,   143,   257,   145,   257,   156,     0,
     195,   225,    77,     0,     0,   285,     0,   203,   148,   140,
     142,   155,   194,   280,     0,     0,   278,   286
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   255,   122,   123,   429,   394,   138,
     139,   259,   239,   376,   490,   264,   265,   266,   343,   588,
     487,   584,   371,   286,   365,   366,   367,   567,   287,   372,
     488,   589,   475,   476,   477,   478,   479,   480,   653,   654,
     655,   708,   689,   719,   481,   686,   582,   482,   545,   483,
     351,   368,   268,   269,   347,   270,   469,   240,    70,    89,
     594,   595,   377,   661,   590,   484,   115,   241,   242,   585,
     301,   380,   302,   381,   355,   687,   323,   324,   325,   403,
     326,   714,   327,   679,   328,   439,   440,   329,   330,   331,
     551,   332,   333,   334,    51,    85,   244,   245,   441,   432,
     433,   434,   601,   602,   603,   435
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -618
static const yytype_int16 yypact[] =
{
      21,     2,    62,    68,    55,    77,  -618,   -14,    67,  -618,
    -618,  -618,    64,    90,    88,    64,    -5,  -618,   115,   128,
    -618,  -618,   203,   307,  -618,  -618,   202,   307,  -618,  -618,
     220,    23,  -618,   192,    76,  -618,    64,   147,  -618,  -618,
     201,  -618,  -618,  -618,  -618,   208,  -618,  -618,   215,  -618,
    -618,   281,  -618,    64,  -618,  -618,   236,   243,   257,   240,
     260,   265,   360,   975,  -618,   360,  -618,   330,   -36,   340,
    -618,   307,   202,   202,   202,   202,    64,   410,   202,   202,
     202,    14,   202,   202,  -618,  -618,  -618,  -618,   356,    -3,
      91,  -618,  -618,   284,  -618,  -618,   372,   127,   182,   373,
     307,   360,  -618,  -618,  -618,   360,   360,  -618,  -618,  -618,
     360,   188,  -618,  -618,  -618,  1671,   342,   348,   289,   313,
     119,   -34,   983,  -618,  -618,  -618,  -618,   202,  -618,   202,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  2101,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,   320,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,   326,  -618,
     329,  -618,   331,  -618,  -618,  -618,  -618,  -618,  2804,   344,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,   334,  -618,
    -618,  -618,  -618,  -618,  -618,  1671,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,   337,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,   339,   343,   345,  -618,
    -618,    86,  -618,   377,   -15,  -618,   332,   346,   379,   374,
     327,   328,   954,   954,  -618,  -618,  -618,   414,   415,  2101,
     402,  -618,  -618,  -618,   418,  -618,    79,   406,   425,  -618,
    -618,    83,    37,    16,  1671,  1671,  -618,  -618,  1671,   388,
      37,    37,    37,  1671,  1671,  2240,   469,    63,  1242,  1242,
    1242,  1242,  1242,  -618,  1242,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  2522,  1671,   202,    46,    46,  -618,   954,
     954,   954,  1814,    64,  2971,   380,   202,   360,  2971,   360,
     -23,  2971,   954,   954,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,   954,  -618,  -618,   418,  2804,
    2101,  -618,  -618,  -618,  2665,  2804,   385,  -618,  -618,  -618,
    -618,  1671,   431,  1671,   237,   183,   205,   222,  -618,  1671,
    1671,  1671,   223,  -618,  2379,   432,  -618,  -618,  2804,   436,
     708,  -618,   409,   349,  -618,    37,   397,  -618,  1671,  1671,
     237,  -618,  -618,  -618,  -618,  -618,  -618,  -618,   384,   250,
     167,  -618,   390,  -618,   954,   954,   954,   954,   954,  -618,
    -618,  -618,  -618,   392,  -618,   491,  2971,  2971,   398,   399,
    -618,  2971,  -618,   395,   407,    -6,  -618,  -618,  -618,   411,
     206,  -618,  2971,  -618,   400,  -618,   408,   416,   423,  -618,
    -618,   367,  -618,   514,   913,  -618,    11,   428,  -618,   393,
     486,  -618,  -618,   405,   448,   484,  1941,  -618,  -618,  -618,
    -618,  -618,   451,  -618,   229,   401,  -618,  1880,  -618,  1671,
    -618,  -618,  2972,  3007,  3015,  -618,  2240,  -618,  2240,  -618,
    -618,  1385,   437,   437,   565,   553,   556,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,   889,   931,  1671,  -618,   483,  2804,
    2101,   435,   429,   836,   836,   202,  -618,  -618,   202,  2971,
     954,   954,  2971,  2971,   427,  1888,  2971,  2971,  2904,  2971,
    2971,   563,  2971,  2971,   870,  2971,  2971,  2971,  2971,   954,
    2971,  2971,  2971,  2971,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  2971,  2971,  2971,  2971,
    2971,  -618,  -618,  2971,  -618,  2971,  -618,  2971,  2971,  -618,
    -618,  -618,  2971,  -618,  -618,   954,  -618,  -618,  -618,   479,
    -618,  -618,   237,  -618,  -618,  -618,  -618,   264,  -618,  -618,
     439,  -618,  -618,    -3,    41,  1972,   708,   708,  1671,  -618,
     462,   464,   226,  1094,   526,  -618,   237,   708,  -618,  -618,
     424,  -618,   418,    -3,  -618,  -618,  2804,   286,   530,   304,
     913,   539,   537,  -618,   444,  -618,  -618,   279,   297,  2971,
     299,   302,  -618,  -618,  -618,  -618,   324,   523,  -618,   913,
     956,  2960,   427,   427,  1957,  1957,  1888,   913,   913,   486,
     347,  -618,  -618,   544,  -618,  2240,  1671,  -618,   556,  -618,
     237,   191,  -618,   191,  -618,  -618,  -618,    26,  1671,  -618,
    -618,  1528,  -618,   437,  -618,  -618,  -618,   237,  1671,   553,
    -618,  -618,  1671,   424,  -618,   202,  -618,  -618,  2971,  -618,
    2971,  2971,  -618,  -618,  -618,  -618,  -618,  -618,   954,  -618,
     579,  2971,  -618,  -618,    86,  -618,   335,  -618,   359,   527,
    -618,    29,  -618,  -618,    86,  -618,   551,   564,   913,   460,
    -618,  2971,   566,   569,  -618,    26,  -618,    26,  -618,  1671,
      63,  -618,  -618,  2971,   549,   486,   614,  -618,  -618,  -618,
    -618,   237,  -618,  -618,   954,  2971,  -618,   486
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -618,  -618,  -618,  -618,  -618,  -618,   621,  -618,  -618,   -12,
      10,  -618,  -618,  -618,   599,  -618,  -618,  -618,   582,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,   529,    70,   362,  -618,
    -618,  -618,  -607,  -618,  -618,  -251,   312,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -445,   311,  -618,  -617,  -618,
    -618,  -618,  -465,   100,   101,   210,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,    34,  -618,  -618,  -442,  -618,
    -174,  -135,  -618,   -98,   230,  -618,  -618,  -234,   560,  -618,
    -618,  -618,   -25,    24,    93,  -453,  -518,  -496,   413,    43,
    -403,  -115,  -618,    75,   -91,  -589,  -240,  -305,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -531,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,   -68,   -27,  -136,  -618,  -178,  -618,
     294,   -26,  -618,    47,  -618,  -618
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -182
static const yytype_int16 yytable[] =
{
     243,   271,   267,    27,    96,    97,    98,    99,   338,   574,
     102,   103,   104,   335,   108,   109,   629,    12,   447,   571,
     572,   566,   547,   568,    71,   112,    12,   408,   409,    92,
     447,   546,   276,     4,   685,   709,   685,    52,    88,   352,
     685,    77,   578,   583,   348,   412,   576,   252,   303,   288,
     289,   290,   291,   292,   107,   636,    84,   113,   690,   257,
      28,   258,     6,    13,   100,   348,    50,   703,   153,   396,
     397,   398,    13,     1,   132,   662,   349,   710,   133,   134,
     430,    95,   446,   135,   430,   637,   105,   430,    54,   169,
     279,   447,   447,   447,   304,   305,    93,   349,   685,   353,
     685,   546,   546,     5,    14,   546,   359,   360,   361,   341,
     131,   546,   253,    14,   423,   187,   718,   116,   720,   443,
      10,   548,   659,   271,   267,     7,   117,   642,   644,  -180,
     656,   201,   202,   583,   284,   391,   431,   106,   342,   424,
     684,   447,    11,   445,    15,   114,  -181,   392,    30,   369,
     294,   373,    18,    15,   500,   501,   426,   427,   118,   354,
     354,   119,   285,   354,   350,    21,   694,   388,   354,   243,
     715,   126,   430,   430,   374,   127,   404,   430,   295,   296,
     297,   298,   299,   300,   356,   350,   250,   357,   430,   354,
     683,    24,   362,   346,   727,   447,   447,   546,    26,   120,
     692,   491,    65,   449,   271,   267,   121,    66,   452,   449,
     375,   251,   497,   389,   617,   498,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   128,   458,   369,    56,
     129,   459,   470,   153,   645,   646,   455,   390,   457,   592,
      30,   448,    33,   647,   462,   463,   464,   453,   437,   460,
     632,    36,   444,   459,   169,   485,    72,   288,   289,   290,
     291,   292,   648,   493,   494,   430,   461,   465,   430,   430,
     459,   459,   430,   430,   558,   430,   430,   559,   430,   430,
     187,   430,   430,   430,   430,    57,   430,   430,   430,   430,
     438,    50,   442,    53,   496,   546,   201,   202,   459,   136,
     137,   405,   430,   430,   430,   430,   430,    58,   634,   430,
      73,   430,   635,   430,   430,   513,   499,    74,   430,    59,
      60,   599,   573,   672,    75,   604,    76,   670,   605,   606,
     369,   664,   369,    78,   665,    61,    62,   613,   614,   615,
      79,   673,   618,   675,   562,   670,   676,   670,    37,   667,
     670,    80,   668,   591,   271,   267,   485,    82,   294,   575,
      38,    39,    83,    40,   382,   383,   384,   385,   677,   386,
     630,   586,   670,   700,   631,   430,   393,   393,    41,   704,
     504,   505,    81,   705,    42,   508,   295,   296,   297,   298,
     299,   300,   680,    43,    44,   681,   514,   288,   289,   290,
     291,   292,    84,   706,    90,    94,    45,   705,   288,   289,
     290,   291,   292,   101,   110,    66,   125,   130,   248,   726,
     246,   288,   289,   290,   291,   292,   247,   597,   249,   272,
     598,   674,   358,   277,   430,   273,   430,   430,   274,   306,
     275,    46,    47,   278,   308,   560,   280,   430,   281,   538,
     539,   540,   282,   307,   283,   309,   310,   311,   336,   337,
     591,   485,   485,   640,    48,   339,   340,   430,   657,   344,
     541,   345,   485,   370,   454,   456,   600,   542,   293,   430,
     468,   436,  -180,   600,   600,   492,   600,   600,   486,   489,
     697,   430,   600,   699,   495,   619,   620,   621,   294,   369,
     499,   502,   503,   702,   509,   506,   507,   515,   519,   294,
     622,   623,   624,   625,   626,   516,   510,   627,   520,   628,
     512,   243,   294,   517,   549,   550,   295,   296,   297,   298,
     299,   300,   518,   691,   552,   723,   279,   295,   296,   297,
     298,   299,   300,   586,   554,   555,   570,   243,   543,   553,
     295,   296,   297,   298,   299,   300,   607,   608,   576,   610,
     611,   346,   577,   587,   544,   616,   593,   609,   633,   596,
     573,   641,   471,   643,   658,   666,   295,   296,   297,   298,
     299,   300,   140,   669,   660,   670,   671,   678,   141,   682,
     701,   142,   143,   707,   721,   144,   711,   696,   713,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   712,
     724,   716,   155,   717,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   725,   167,   168,   169,   170,
      55,   171,   172,   472,   173,   174,   175,    29,   176,   177,
     178,   179,   180,   181,   698,    87,   182,   183,   184,   185,
     186,   256,   450,   124,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   473,   395,
     201,   202,   203,   204,   474,   467,   638,   688,   639,   206,
     207,   569,   557,   208,   209,   722,   210,   695,   211,   663,
     212,   213,   214,   215,   216,   217,   573,   363,   218,   219,
     220,   693,   221,   222,   223,   224,   225,   226,   227,   511,
     228,   229,     0,     0,     0,   471,     0,     0,     0,     0,
     230,   231,   232,   233,   234,   140,   235,   236,   237,   238,
       0,   141,     0,     0,   142,   143,     0,     0,   144,     0,
       0,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     0,   167,
     168,   169,   170,     0,   171,   172,   472,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,     0,     0,   182,
     183,   184,   185,   186,     0,     0,     0,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   473,     0,   201,   202,   203,   204,   474,     0,     0,
       0,     0,   206,   207,     0,     0,   208,   209,     0,   210,
       0,   211,     0,   212,   213,   214,   215,   216,   217,     0,
       0,   218,   219,   220,     0,   221,   222,   223,   224,   225,
     226,   227,     0,   228,   229,     0,     0,     0,   290,   291,
     292,     0,     0,   230,   231,   232,   233,   234,     0,   235,
     236,   237,   238,   521,     0,   522,   523,     0,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,     0,     0,     0,     0,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,     0,
       0,     0,     0,   541,   612,     0,   521,     0,   522,   523,
     542,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   579,   542,
       0,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   288,   289,   290,   291,   292,   541,   294,     0,     0,
       0,     0,   523,   542,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   542,     0,     0,     0,   295,   296,   297,   298,   299,
     300,   543,     0,   312,     0,     0,     0,     0,     0,   541,
       0,     0,     0,     0,     0,     0,   542,   544,     0,   116,
       0,     0,    56,     0,     0,   580,     0,     0,   117,   295,
     296,   297,   298,   299,   300,     0,     0,   313,     0,     0,
       0,     0,     0,     0,   543,   581,     0,   314,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,   254,   315,
     544,     0,   294,   119,     0,     0,   316,     0,     0,     0,
       0,     0,   295,   296,   297,   298,   299,   300,    57,     0,
       0,     0,     0,   317,     0,     0,   318,   543,   319,     0,
     295,   296,   297,   298,   299,   300,     0,   320,     0,     0,
      58,   120,     0,   544,     0,     0,     0,     0,   121,     0,
       0,     0,    59,    60,     0,   295,   296,   297,   298,   299,
     300,   140,     0,   321,     0,   322,     0,   141,    61,    62,
     142,   143,   649,   650,   144,     0,     0,     0,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,     0,     0,
       0,   155,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,     0,   167,   168,   169,   170,     0,
     171,   172,     0,   173,   174,   175,     0,   176,   177,   178,
     179,   180,   181,     0,     0,   182,   183,   184,   185,   186,
       0,     0,     0,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,     0,     0,   201,
     202,   203,   204,   651,     0,     0,     0,     0,   206,   207,
       0,     0,   208,   209,     0,   210,     0,   211,     0,   212,
     213,   214,   215,   216,   217,     0,     0,   218,   219,   220,
     652,   221,   222,   223,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,   140,
       0,     0,   378,   379,     0,   141,     0,     0,   142,   143,
       0,     0,   144,     0,     0,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,     0,     0,     0,   155,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,     0,   167,   168,   169,   170,     0,   171,   172,
       0,   173,   174,   175,     0,   176,   177,   178,   179,   180,
     181,     0,     0,   182,   183,   184,   185,   186,     0,     0,
       0,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,     0,     0,   201,   202,   203,
     204,   205,     0,     0,     0,     0,   206,   207,     0,     0,
     208,   209,     0,   210,     0,   211,     0,   212,   213,   214,
     215,   216,   217,     0,     0,   218,   219,   220,     0,   221,
     222,   223,   224,   225,   226,   227,     0,   228,   229,     0,
       0,     0,     0,     0,     0,     0,     0,   230,   231,   232,
     233,   234,   140,   235,   236,   237,   238,     0,   141,     0,
       0,   142,   143,     0,     0,   144,     0,     0,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
       0,     0,   155,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,   167,   168,   169,   170,
       0,   171,   172,   472,   173,   174,   175,     0,   176,   177,
     178,   179,   180,   181,     0,     0,   182,   183,   184,   185,
     186,     0,     0,     0,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   473,     0,
     201,   202,   203,   204,   474,     0,     0,     0,     0,   206,
     207,     0,     0,   208,   209,     0,   210,     0,   211,     0,
     212,   213,   214,   215,   216,   217,     0,     0,   218,   219,
     220,     0,   221,   222,   223,   224,   225,   226,   227,     0,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
     230,   231,   232,   233,   234,   140,   235,   236,   237,   238,
       0,   141,     0,     0,   142,   143,     0,     0,   144,     0,
       0,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,     0,     0,     0,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     0,   167,
     168,   169,   170,     0,   171,   172,     0,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,     0,     0,   182,
     183,   184,   185,   186,     0,     0,     0,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,     0,     0,   201,   202,   203,   204,   205,     0,     0,
       0,     0,   206,   207,     0,     0,   208,   209,     0,   210,
       0,   211,     0,   212,   213,   214,   215,   216,   217,   573,
       0,   218,   219,   220,     0,   221,   222,   223,   224,   225,
     226,   227,     0,   228,   229,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,   234,   140,   235,
     236,   237,   238,     0,   141,     0,     0,   142,   143,     0,
       0,   144,     0,     0,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,   167,   168,   169,   170,     0,   171,   172,     0,
     173,   174,   175,     0,   176,   177,   178,   179,   180,   181,
       0,     0,   182,   183,   184,   185,   186,     0,     0,     0,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,     0,     0,   201,   202,   203,   204,
     205,     0,     0,     0,     0,   206,   207,     0,     0,   208,
     209,     0,   210,     0,   211,     0,   212,   213,   214,   215,
     216,   217,     0,     0,   218,   219,   220,     0,   221,   222,
     223,   224,   225,   226,   227,     0,   228,   229,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   231,   232,   233,
     234,   140,   235,   236,   237,   238,     0,     0,     0,     0,
     142,   143,     0,     0,   144,     0,     0,     0,     0,   146,
     147,   148,   149,   150,   151,   152,     0,   154,     0,     0,
       0,   155,     0,   156,   157,     0,   159,   399,   161,   400,
     163,   164,   165,   166,     0,   167,     0,     0,   170,     0,
     171,   172,     0,   173,   174,   175,     0,   176,   177,   178,
     179,   180,   181,     0,     0,   182,   183,   184,   185,   186,
     288,   289,   290,   291,   292,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   401,   199,   200,     0,     0,     0,
       0,   203,   204,     0,   561,     0,     0,     0,   206,   207,
       0,   541,   208,   209,     0,   210,     0,   211,   542,   212,
     213,   214,   215,   216,   217,     0,     0,   218,   219,   220,
       0,   221,   222,     0,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
       0,   232,   233,   234,     0,   235,   262,   263,   402,   579,
     312,   540,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   288,   289,   290,   291,   292,     0,     0,     0,
     541,   294,     0,     0,     0,     0,   556,   542,     0,   543,
       0,     0,     0,     0,   313,     0,   358,     0,     0,     0,
       0,     0,   542,     0,   314,   544,     0,     0,     0,   295,
     296,   297,   298,   299,   300,     0,   315,   295,   296,   297,
     298,   299,   300,   316,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   580,     0,     0,     0,
     317,     0,     0,   318,     0,   319,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,   581,     0,   543,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   544,     0,     0,     0,     0,     0,
     321,     0,   322,     0,     0,     0,   295,   296,   297,   298,
     299,   300,     0,     0,     0,     0,     0,     0,   140,     0,
       0,   295,   296,   297,   298,   299,   300,   142,   143,     0,
       0,   144,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   260,   154,     0,     0,     0,   155,     0,
     156,   157,     0,   159,     0,   161,     0,   163,   164,   165,
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
     157,     0,   159,     0,   161,     0,   163,   164,   165,   166,
       0,   167,     0,     0,   170,     0,   171,   172,     0,   173,
     174,   175,     0,   176,   177,   178,   179,   180,   181,     0,
       0,   182,   183,   184,   185,   186,     0,     0,     0,     0,
       0,     0,   190,   191,   192,   193,   194,   195,   196,   197,
       0,   199,   200,     0,     0,     0,     0,   203,   204,     0,
       0,     0,     0,   364,   206,   207,     0,     0,   208,   209,
       0,   210,     0,   211,     0,   212,   213,   214,   215,   216,
     217,     0,     0,   218,   219,   220,     0,   221,   222,     0,
     224,   225,   226,   227,     0,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,   230,   140,   232,   233,   234,
       0,   235,   262,   263,     0,   142,   143,     0,     0,   144,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
     152,   260,   154,     0,     0,     0,   155,     0,   156,   157,
       0,   159,     0,   161,     0,   163,   164,   165,   166,     0,
     167,     0,     0,   170,     0,   171,   172,     0,   173,   174,
     175,     0,   176,   177,   178,   179,   180,   181,     0,     0,
     182,   183,   184,   185,   186,     0,     0,     0,     0,     0,
       0,   190,   191,   192,   193,   194,   195,   196,   197,     0,
     199,   200,     0,     0,     0,     0,   203,   204,   466,     0,
       0,     0,     0,   206,   207,     0,     0,   208,   209,     0,
     210,     0,   211,     0,   212,   213,   214,   215,   216,   217,
       0,     0,   218,   219,   220,     0,   221,   222,     0,   224,
     225,   226,   227,     0,   228,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   230,     0,   232,   233,   234,   140,
     235,   262,   263,     0,     0,   387,     0,     0,   142,   143,
       0,     0,   144,     0,     0,     0,     0,   146,   147,   148,
     149,   150,   151,   152,     0,   154,     0,     0,     0,   155,
       0,   156,   157,     0,   159,     0,   161,     0,   163,   164,
     165,   166,     0,   167,     0,     0,   170,     0,   171,   172,
       0,   173,   174,   175,     0,   176,   177,   178,   179,   180,
     181,     0,     0,   182,   183,   184,   185,   186,     0,     0,
       0,     0,     0,     0,   190,   191,   192,   193,   194,   195,
     196,   197,     0,   199,   200,     0,     0,     0,     0,   203,
     204,     0,     0,     0,     0,     0,   206,   207,     0,     0,
     208,   209,     0,   210,     0,   211,     0,   212,   213,   214,
     215,   216,   217,     0,     0,   218,   219,   220,     0,   221,
     222,     0,   224,   225,   226,   227,     0,   228,   229,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,   232,
     233,   234,   140,   235,   262,   263,     0,     0,   451,     0,
       0,   142,   143,     0,     0,   144,     0,     0,     0,     0,
     146,   147,   148,   149,   150,   151,   152,     0,   154,     0,
       0,     0,   155,     0,   156,   157,     0,   159,     0,   161,
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
     230,   140,   232,   233,   234,     0,   235,   262,   263,     0,
     142,   143,     0,     0,   144,     0,     0,     0,     0,   146,
     147,   148,   149,   150,   151,   152,     0,   154,     0,     0,
       0,   155,     0,   156,   157,     0,   159,     0,   161,     0,
     163,   164,   165,   166,     0,   167,     0,     0,   170,     0,
     171,   172,     0,   173,   174,   175,     0,   176,   177,   178,
     179,   180,   181,     0,     0,   182,   183,   184,   185,   186,
       0,     0,     0,     0,     0,     0,   190,   191,   192,   193,
     194,   195,   196,   197,     0,   199,   200,     0,     0,     0,
       0,   203,   204,     0,     0,     0,     0,     0,   206,   207,
       0,     0,   208,   209,     0,   210,     0,   211,     0,   212,
     213,   214,   215,   216,   217,     0,     0,   218,   219,   220,
       0,   221,   222,     0,   224,   225,   226,   227,     0,   228,
     229,     0,     0,     0,   542,     0,     0,     0,     0,   230,
       0,   232,   233,   234,     0,   235,   262,   263,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,     0,     0,     0,     0,     0,
       0,   406,   288,   289,   290,   291,   292,     0,     0,     0,
       0,     0,   407,   541,   408,   409,     0,     0,     0,     0,
     542,     0,     0,   410,     0,     0,   563,     0,   411,     0,
       0,     0,   412,     0,   413,   543,   414,   288,   289,   290,
     291,   292,     0,     0,   169,   288,   289,   290,   291,   292,
       0,   544,     0,     0,     0,     0,     0,     0,     0,   415,
       0,   564,     0,   295,   296,   297,   298,   299,   300,   565,
     416,   417,   418,     0,     0,     0,     0,     0,     0,     0,
       0,   419,   420,     0,     0,     0,   201,   421,     0,     0,
     422,   543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,   294,     0,     0,     0,   544,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
     296,   297,   298,   299,   300,     0,   424,     0,     0,     0,
       0,   295,   296,   297,   298,   299,   300,   425,   294,     0,
       0,     0,     0,   426,   427,   428,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,   296,   297,   298,
     299,   300,     0,     0,   295,   296,   297,   298,   299,   300
};

static const yytype_int16 yycheck[] =
{
     115,   137,   137,    15,    72,    73,    74,    75,   259,   474,
      78,    79,    80,   253,    82,    83,   547,    31,   323,   472,
     473,   466,    11,   468,    36,    28,    31,    33,    34,    65,
     335,   434,   168,    31,   641,     6,   643,    27,    65,    23,
     647,    53,   484,   485,    28,    51,     5,    81,    63,    20,
      21,    22,    23,    24,    81,   573,    42,    60,   647,   127,
      65,   129,     0,    77,    76,    28,    89,   684,    42,   309,
     310,   311,    77,    52,   101,   593,    60,   694,   105,   106,
     314,    71,   322,   110,   318,    44,    72,   321,    65,    63,
     205,   396,   397,   398,   109,   110,   132,    60,   705,   273,
     707,   504,   505,   101,   118,   508,   280,   281,   282,    30,
     100,   514,   146,   118,   120,    89,   705,    26,   707,   142,
      65,   110,   587,   259,   259,    57,    35,   580,   581,    46,
     583,   105,   106,   575,    48,    89,   314,   123,    59,   145,
     636,   446,    65,   321,   158,   148,    63,   101,   125,   285,
     121,    88,    85,   158,   394,   395,   162,   163,    67,   274,
     275,    70,    76,   278,   148,   101,   662,   303,   283,   284,
     701,    44,   406,   407,   111,    48,   312,   411,   149,   150,
     151,   152,   153,   154,   275,   148,    67,   278,   422,   304,
     635,   101,   283,   110,   725,   500,   501,   600,   110,   108,
     653,   375,   126,   339,   340,   340,   115,   131,   344,   345,
     147,    92,    45,   304,   519,    48,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,    44,    44,   364,    37,
      48,    48,   368,    42,     8,     9,   351,   305,   353,   490,
     125,   339,   114,    17,   359,   360,   361,   345,   316,    44,
     555,    48,   320,    48,    63,   370,   109,    20,    21,    22,
      23,    24,    36,   378,   379,   499,    44,    44,   502,   503,
      48,    48,   506,   507,    45,   509,   510,    48,   512,   513,
      89,   515,   516,   517,   518,    93,   520,   521,   522,   523,
     317,    89,   319,    73,    44,   698,   105,   106,    48,   111,
     112,   313,   536,   537,   538,   539,   540,   115,    44,   543,
     109,   545,    48,   547,   548,   109,   110,   109,   552,   127,
     128,   499,   131,    44,   109,   503,    45,    48,   506,   507,
     466,    45,   468,    97,    48,   143,   144,   515,   516,   517,
      97,    44,   520,    44,   459,    48,    44,    48,    41,    45,
      48,    94,    48,   489,   490,   490,   471,    97,   121,   474,
      53,    54,    97,    56,   289,   290,   291,   292,    44,   294,
     548,   486,    48,   678,   552,   609,   306,   307,    71,    44,
     406,   407,   142,    48,    77,   411,   149,   150,   151,   152,
     153,   154,    45,    86,    87,    48,   422,    20,    21,    22,
      23,    24,    42,    44,    74,    65,    99,    48,    20,    21,
      22,    23,    24,     3,    58,   131,    44,    44,   129,   724,
      78,    20,    21,    22,    23,    24,    78,   495,   115,   109,
     498,   609,    44,    89,   668,   109,   670,   671,   109,   107,
     109,   134,   135,   109,    65,    44,   109,   681,   109,    22,
      23,    24,   109,   107,   109,    81,   129,   129,    44,    44,
     596,   576,   577,   578,   157,    63,    48,   701,   583,    63,
      43,    46,   587,     4,    89,    44,   502,    50,   101,   713,
      48,   101,    46,   509,   510,    88,   512,   513,    79,   140,
     668,   725,   518,   671,   110,   521,   522,   523,   121,   635,
     110,   109,    11,   681,   109,   107,   107,   107,   141,   121,
     536,   537,   538,   539,   540,   107,   109,   543,     4,   545,
     109,   636,   121,   107,    96,   132,   149,   150,   151,   152,
     153,   154,   109,   648,    48,   713,   651,   149,   150,   151,
     152,   153,   154,   658,    96,    61,   109,   662,   121,   144,
     149,   150,   151,   152,   153,   154,   509,   510,     5,   512,
     513,   110,     6,    80,   137,   518,   131,     4,    89,   140,
     131,   109,     7,   109,    48,    45,   149,   150,   151,   152,
     153,   154,    17,    44,   160,    48,   142,    64,    23,    45,
      11,    26,    27,    66,   709,    30,    45,   665,   138,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    45,
      61,    45,    47,    44,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    11,    61,    62,    63,    64,
      31,    66,    67,    68,    69,    70,    71,    16,    73,    74,
      75,    76,    77,    78,   670,    63,    81,    82,    83,    84,
      85,   122,   340,    93,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   307,
     105,   106,   107,   108,   109,   364,   576,   643,   577,   114,
     115,   471,   452,   118,   119,   710,   121,   663,   123,   596,
     125,   126,   127,   128,   129,   130,   131,   284,   133,   134,
     135,   658,   137,   138,   139,   140,   141,   142,   143,   415,
     145,   146,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,
     155,   156,   157,   158,   159,    17,   161,   162,   163,   164,
      -1,    23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,   115,    -1,    -1,   118,   119,    -1,   121,
      -1,   123,    -1,   125,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,    -1,   137,   138,   139,   140,   141,
     142,   143,    -1,   145,   146,    -1,    -1,    -1,    22,    23,
      24,    -1,    -1,   155,   156,   157,   158,   159,    -1,   161,
     162,   163,   164,     3,    -1,     5,     6,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    43,    44,    -1,     3,    -1,     5,     6,
      50,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     7,    50,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    43,   121,    -1,    -1,
      -1,    -1,     6,    50,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    50,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,   121,    -1,    39,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,   137,    -1,    26,
      -1,    -1,    37,    -1,    -1,    84,    -1,    -1,    35,   149,
     150,   151,   152,   153,   154,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   104,    -1,    83,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    95,
     137,    -1,   121,    70,    -1,    -1,   102,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    93,    -1,
      -1,    -1,    -1,   119,    -1,    -1,   122,   121,   124,    -1,
     149,   150,   151,   152,   153,   154,    -1,   133,    -1,    -1,
     115,   108,    -1,   137,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,   127,   128,    -1,   149,   150,   151,   152,   153,
     154,    17,    -1,   159,    -1,   161,    -1,    23,   143,   144,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    -1,
      66,    67,    -1,    69,    70,    71,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,   105,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,   115,
      -1,    -1,   118,   119,    -1,   121,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,    -1,    -1,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
     156,   157,   158,   159,    -1,   161,   162,   163,   164,    17,
      -1,    -1,    20,    21,    -1,    23,    -1,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    47,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    -1,    66,    67,
      -1,    69,    70,    71,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,   105,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,
     118,   119,    -1,   121,    -1,   123,    -1,   125,   126,   127,
     128,   129,   130,    -1,    -1,   133,   134,   135,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,   145,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,
     158,   159,    17,   161,   162,   163,   164,    -1,    23,    -1,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    47,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    71,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
     105,   106,   107,   108,   109,    -1,    -1,    -1,    -1,   114,
     115,    -1,    -1,   118,   119,    -1,   121,    -1,   123,    -1,
     125,   126,   127,   128,   129,   130,    -1,    -1,   133,   134,
     135,    -1,   137,   138,   139,   140,   141,   142,   143,    -1,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   156,   157,   158,   159,    17,   161,   162,   163,   164,
      -1,    23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    -1,    66,    67,    -1,    69,    70,    71,
      -1,    73,    74,    75,    76,    77,    78,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,   114,   115,    -1,    -1,   118,   119,    -1,   121,
      -1,   123,    -1,   125,   126,   127,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,   138,   139,   140,   141,
     142,   143,    -1,   145,   146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,   159,    17,   161,
     162,   163,   164,    -1,    23,    -1,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    64,    -1,    66,    67,    -1,
      69,    70,    71,    -1,    73,    74,    75,    76,    77,    78,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,   105,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,   118,
     119,    -1,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,    -1,    -1,   133,   134,   135,    -1,   137,   138,
     139,   140,   141,   142,   143,    -1,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,   158,
     159,    17,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    -1,
      -1,    47,    -1,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    -1,    -1,    64,    -1,
      66,    67,    -1,    69,    70,    71,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    81,    82,    83,    84,    85,
      20,    21,    22,    23,    24,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,   107,   108,    -1,    44,    -1,    -1,    -1,   114,   115,
      -1,    43,   118,   119,    -1,   121,    -1,   123,    50,   125,
     126,   127,   128,   129,   130,    -1,    -1,   133,   134,   135,
      -1,   137,   138,    -1,   140,   141,   142,   143,    -1,   145,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,   157,   158,   159,    -1,   161,   162,   163,   164,     7,
      39,    24,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      43,   121,    -1,    -1,    -1,    -1,    65,    50,    -1,   121,
      -1,    -1,    -1,    -1,    73,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    83,   137,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,    95,   149,   150,   151,
     152,   153,   154,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
     119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,   104,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   137,    -1,    -1,    -1,    -1,    -1,
     159,    -1,   161,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,   149,   150,   151,   152,   153,   154,    26,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,
      49,    50,    -1,    52,    -1,    54,    -1,    56,    57,    58,
      59,    -1,    61,    -1,    -1,    64,    -1,    66,    67,    -1,
      69,    70,    71,    -1,    73,    74,    75,    76,    77,    78,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,   118,
     119,    -1,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,    -1,    -1,   133,   134,   135,    -1,   137,   138,
      -1,   140,   141,   142,   143,    -1,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    17,   157,   158,
     159,    -1,   161,   162,   163,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,    49,
      50,    -1,    52,    -1,    54,    -1,    56,    57,    58,    59,
      -1,    61,    -1,    -1,    64,    -1,    66,    67,    -1,    69,
      70,    71,    -1,    73,    74,    75,    76,    77,    78,    -1,
      -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,   101,   102,    -1,    -1,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,   118,   119,
      -1,   121,    -1,   123,    -1,   125,   126,   127,   128,   129,
     130,    -1,    -1,   133,   134,   135,    -1,   137,   138,    -1,
     140,   141,   142,   143,    -1,   145,   146,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,    17,   157,   158,   159,
      -1,   161,   162,   163,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    47,    -1,    49,    50,
      -1,    52,    -1,    54,    -1,    56,    57,    58,    59,    -1,
      61,    -1,    -1,    64,    -1,    66,    67,    -1,    69,    70,
      71,    -1,    73,    74,    75,    76,    77,    78,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
     101,   102,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    -1,    -1,   114,   115,    -1,    -1,   118,   119,    -1,
     121,    -1,   123,    -1,   125,   126,   127,   128,   129,   130,
      -1,    -1,   133,   134,   135,    -1,   137,   138,    -1,   140,
     141,   142,   143,    -1,   145,   146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,   157,   158,   159,    17,
     161,   162,   163,    -1,    -1,    23,    -1,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    -1,    -1,    -1,    47,
      -1,    49,    50,    -1,    52,    -1,    54,    -1,    56,    57,
      58,    59,    -1,    61,    -1,    -1,    64,    -1,    66,    67,
      -1,    69,    70,    71,    -1,    73,    74,    75,    76,    77,
      78,    -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,
     118,   119,    -1,   121,    -1,   123,    -1,   125,   126,   127,
     128,   129,   130,    -1,    -1,   133,   134,   135,    -1,   137,
     138,    -1,   140,   141,   142,   143,    -1,   145,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   157,
     158,   159,    17,   161,   162,   163,    -1,    -1,    23,    -1,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    -1,
      -1,    -1,    47,    -1,    49,    50,    -1,    52,    -1,    54,
      -1,    56,    57,    58,    59,    -1,    61,    -1,    -1,    64,
      -1,    66,    67,    -1,    69,    70,    71,    -1,    73,    74,
      75,    76,    77,    78,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,    -1,   101,   102,    -1,    -1,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,    -1,   118,   119,    -1,   121,    -1,   123,    -1,
     125,   126,   127,   128,   129,   130,    -1,    -1,   133,   134,
     135,    -1,   137,   138,    -1,   140,   141,   142,   143,    -1,
     145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    17,   157,   158,   159,    -1,   161,   162,   163,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    -1,
      -1,    47,    -1,    49,    50,    -1,    52,    -1,    54,    -1,
      56,    57,    58,    59,    -1,    61,    -1,    -1,    64,    -1,
      66,    67,    -1,    69,    70,    71,    -1,    73,    74,    75,
      76,    77,    78,    -1,    -1,    81,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,   101,   102,    -1,    -1,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,    -1,   118,   119,    -1,   121,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,    -1,    -1,   133,   134,   135,
      -1,   137,   138,    -1,   140,   141,   142,   143,    -1,   145,
     146,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,   155,
      -1,   157,   158,   159,    -1,   161,   162,   163,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    31,    43,    33,    34,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    42,    -1,    -1,    44,    -1,    47,    -1,
      -1,    -1,    51,    -1,    53,   121,    55,    20,    21,    22,
      23,    24,    -1,    -1,    63,    20,    21,    22,    23,    24,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    44,    -1,   149,   150,   151,   152,   153,   154,    44,
      89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,    -1,   105,   106,    -1,    -1,
     109,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,   121,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   145,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,   156,   121,    -1,
      -1,    -1,    -1,   162,   163,   164,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,   149,   150,   151,   152,   153,   154
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    52,   166,   167,    31,   101,     0,    57,   168,   169,
      65,    65,    31,    77,   118,   158,   170,   171,    85,   176,
     177,   101,   173,   174,   101,   172,   110,   174,    65,   171,
     125,   178,   179,   114,   180,   181,    48,    41,    53,    54,
      56,    71,    77,    86,    87,    99,   134,   135,   157,   175,
      89,   279,   175,    73,    65,   179,    37,    93,   115,   127,
     128,   143,   144,   182,   183,   126,   131,   184,   185,   186,
     243,   174,   109,   109,   109,   109,    45,   174,    97,    97,
      94,   142,    97,    97,    42,   280,    65,   183,   280,   244,
      74,   188,    65,   132,    65,   175,   279,   279,   279,   279,
     174,     3,   279,   279,   279,    72,   123,   280,   279,   279,
      58,   187,    28,    60,   148,   251,    26,    35,    67,    70,
     108,   115,   190,   191,   243,    44,    44,    48,    44,    48,
      44,   175,   280,   280,   280,   280,   111,   112,   194,   195,
      17,    23,    26,    27,    30,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    47,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,    62,    63,
      64,    66,    67,    69,    70,    71,    73,    74,    75,    76,
      77,    78,    81,    82,    83,    84,    85,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   105,   106,   107,   108,   109,   114,   115,   118,   119,
     121,   123,   125,   126,   127,   128,   129,   130,   133,   134,
     135,   137,   138,   139,   140,   141,   142,   143,   145,   146,
     155,   156,   157,   158,   159,   161,   162,   163,   164,   197,
     242,   252,   253,   256,   281,   282,    78,    78,   129,   115,
      67,    92,    81,   146,    65,   189,   191,   279,   279,   196,
      42,    89,   162,   163,   200,   201,   202,   236,   237,   238,
     240,   281,   109,   109,   109,   109,   281,    89,   109,   256,
     109,   109,   109,   109,    48,    76,   208,   213,    20,    21,
      22,    23,    24,   101,   121,   149,   150,   151,   152,   153,
     154,   255,   257,    63,   109,   110,   107,   107,    65,    81,
     129,   129,    39,    73,    83,    95,   102,   119,   122,   124,
     133,   159,   161,   261,   262,   263,   265,   267,   269,   272,
     273,   274,   276,   277,   278,   261,    44,    44,   200,    63,
      48,    30,    59,   203,    63,    46,   110,   239,    28,    60,
     148,   235,    23,   235,   256,   259,   259,   259,    44,   235,
     235,   235,   259,   253,   113,   209,   210,   211,   236,   281,
       4,   207,   214,    88,   111,   147,   198,   247,    20,    21,
     256,   258,   258,   258,   258,   258,   258,    23,   281,   259,
     279,    89,   101,   192,   193,   193,   261,   261,   261,    53,
      55,   100,   164,   264,   281,   174,    20,    31,    33,    34,
      42,    47,    51,    53,    55,    78,    89,    90,    91,   100,
     101,   106,   109,   120,   145,   156,   162,   163,   164,   192,
     242,   283,   284,   285,   286,   290,   101,   279,   280,   270,
     271,   283,   280,   142,   279,   283,   261,   262,   238,   281,
     201,    23,   281,   238,    89,   256,    44,   256,    44,    48,
      44,    44,   256,   256,   256,    44,   109,   211,    48,   241,
     281,     7,    68,   103,   109,   217,   218,   219,   220,   221,
     222,   229,   232,   234,   250,   256,    79,   205,   215,   140,
     199,   235,    88,   256,   256,   110,    44,    45,    48,   110,
     261,   261,   109,    11,   286,   286,   107,   107,   286,   109,
     109,   285,   109,   109,   286,   107,   107,   107,   109,   141,
       4,     3,     5,     6,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    43,    50,   121,   137,   233,   255,    11,   110,    96,
     132,   275,    48,   144,    96,    61,    65,   239,    45,    48,
      44,    44,   256,    44,    44,    44,   210,   212,   210,   220,
     109,   250,   250,   131,   217,   256,     5,     6,   233,     7,
      84,   104,   231,   233,   206,   254,   256,    80,   204,   216,
     249,   281,   200,   131,   245,   246,   140,   279,   279,   283,
     286,   287,   288,   289,   283,   283,   283,   288,   288,     4,
     288,   288,    44,   283,   283,   283,   288,   262,   283,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   271,
     283,   283,   262,    89,    44,    48,   251,    44,   218,   219,
     256,   109,   250,   109,   250,     8,     9,    17,    36,    28,
      29,   109,   136,   223,   224,   225,   250,   256,    48,   217,
     160,   248,   251,   249,    45,    48,    45,    45,    48,    44,
      48,   142,    44,    44,   283,    44,    44,    44,    64,   268,
      45,    48,    45,   210,   252,   197,   230,   260,   230,   227,
     260,   256,   250,   254,   252,   248,   279,   283,   286,   283,
     262,    11,   283,   213,    44,    48,    44,    66,   226,     6,
     213,    45,    45,   138,   266,   271,    45,    44,   260,   228,
     260,   256,   247,   283,    61,    11,   262,   271
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
#line 247 "ace.yacc"
    {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
    break;

  case 4:
#line 250 "ace.yacc"
    {
		this_report.dbname=acl_strdup((yyvsp[(2) - (3)].str));
		A4GLSQL_init_connection ((yyvsp[(2) - (3)].str));
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
		ace_add_variable((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str),CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:
#line 281 "ace.yacc"
    {
		ace_add_variable((yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str),CAT_PARAM,atoi((yyvsp[(3) - (6)].str)),-1,0);
	}
    break;

  case 13:
#line 284 "ace.yacc"
    {
		add_function((yyvsp[(2) - (2)].str));
	}
    break;

  case 17:
#line 295 "ace.yacc"
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
#line 308 "ace.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 20:
#line 309 "ace.yacc"
    {strcpy((yyval.str),"CHAR");}
    break;

  case 21:
#line 310 "ace.yacc"
    {sprintf((yyval.str),"CHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 22:
#line 311 "ace.yacc"
    {strcpy((yyval.str),"VARCHAR");}
    break;

  case 23:
#line 312 "ace.yacc"
    {sprintf((yyval.str),"VARCHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 24:
#line 313 "ace.yacc"
    {strcpy((yyval.str),"DATE");}
    break;

  case 25:
#line 314 "ace.yacc"
    {strcpy((yyval.str),"FLOAT");}
    break;

  case 26:
#line 315 "ace.yacc"
    {strcpy((yyval.str),"SMALLFLOAT");}
    break;

  case 27:
#line 316 "ace.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 28:
#line 317 "ace.yacc"
    {strcpy((yyval.str),"DATETIME");}
    break;

  case 29:
#line 318 "ace.yacc"
    {strcpy((yyval.str),"INTERVAL");}
    break;

  case 30:
#line 319 "ace.yacc"
    {strcpy((yyval.str),"MONEY");}
    break;

  case 31:
#line 320 "ace.yacc"
    {sprintf((yyval.str),"MONEY (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 32:
#line 321 "ace.yacc"
    {sprintf((yyval.str),"MONEY (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 33:
#line 322 "ace.yacc"
    {strcpy((yyval.str),"DECIMAL");}
    break;

  case 34:
#line 323 "ace.yacc"
    {sprintf((yyval.str),"DECIMAL (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 35:
#line 324 "ace.yacc"
    {sprintf((yyval.str),"DECIMAL (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 41:
#line 338 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes((yyvsp[(5) - (5)].str)),(yyvsp[(3) - (5)].str));
}
    break;

  case 47:
#line 353 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str));}
    break;

  case 48:
#line 354 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:
#line 355 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup((yyvsp[(3) - (3)].str)); }
    break;

  case 50:
#line 356 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str)); }
    break;

  case 51:
#line 357 "ace.yacc"
    {
		this_report.output.left_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 52:
#line 360 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 53:
#line 363 "ace.yacc"
    {
		this_report.output.top_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 54:
#line 366 "ace.yacc"
    {
		this_report.output.page_length=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 55:
#line 369 "ace.yacc"
    {
		this_report.output.right_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 56:
#line 372 "ace.yacc"
    {
		this_report.output.top_of_page=acl_strdup((yyvsp[(2) - (2)].str));
	}
    break;

  case 58:
#line 379 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:
#line 383 "ace.yacc"
    { add_select((yyvsp[(1) - (1)].str),temp_tab_name); }
    break;

  case 60:
#line 384 "ace.yacc"
    { add_select((yyvsp[(3) - (3)].str),temp_tab_name); }
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
		add_fmt(FORMAT_FIRST_PAGE_HEADER,"",(yyvsp[(4) - (4)].commands));
	}
    break;

  case 71:
#line 418 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,"",(yyvsp[(3) - (3)].commands));
	}
    break;

  case 72:
#line 422 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,"",(yyvsp[(3) - (3)].commands));
	}
    break;

  case 73:
#line 426 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,"",(yyvsp[(4) - (4)].commands));
	}
    break;

  case 74:
#line 430 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,"",(yyvsp[(4) - (4)].commands));
	}
    break;

  case 75:
#line 434 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 76:
#line 438 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 81:
#line 451 "ace.yacc"
    {
int vid;
int a;
a=atoi((yyvsp[(1) - (1)].str));
vid = find_sql_var (a);
sprintf((yyval.str),this_report.variables.variables_val[vid].name);
}
    break;

  case 82:
#line 462 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 84:
#line 465 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:
#line 465 "ace.yacc"
    {
	printf("speclist : %s ",(yyvsp[(3) - (3)].str));
	sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str));}
    break;

  case 86:
#line 469 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:
#line 478 "ace.yacc"
    {
		sprintf((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));
	}
    break;

  case 91:
#line 501 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 92:
#line 501 "ace.yacc"
    { sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str)); }
    break;

  case 94:
#line 506 "ace.yacc"
    {
sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 96:
#line 513 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"I%d",atoi((yyvsp[(1) - (1)].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 97:
#line 518 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"C%s",(yyvsp[(1) - (1)].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 98:
#line 525 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:
#line 533 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 102:
#line 539 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 104:
#line 545 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 105:
#line 550 "ace.yacc"
    {sprintf((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[(2) - (2)].str));}
    break;

  case 106:
#line 555 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 108:
#line 561 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 109:
#line 565 "ace.yacc"
    {sprintf((yyval.str)," %s ", (yyvsp[(1) - (1)].str));}
    break;

  case 110:
#line 566 "ace.yacc"
    {sprintf((yyval.str)," %s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 111:
#line 567 "ace.yacc"
    {sprintf((yyval.str)," %s (%s) ",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 113:
#line 571 "ace.yacc"
    {
		sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		ace_add_table((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 115:
#line 579 "ace.yacc"
    { sprintf((yyval.str)," %s,%s ",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 116:
#line 587 "ace.yacc"
    {
sprintf((yyval.str),"%s %s %s %s",
(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),
(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
}
    break;

  case 117:
#line 594 "ace.yacc"
    {strcpy((yyval.str),"\n0");}
    break;

  case 119:
#line 598 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 121:
#line 602 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 124:
#line 610 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 126:
#line 616 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 128:
#line 622 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 130:
#line 628 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 131:
#line 633 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 132:
#line 634 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 133:
#line 640 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 134:
#line 642 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 140:
#line 666 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 143:
#line 680 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 144:
#line 682 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 145:
#line 684 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 146:
#line 686 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 148:
#line 693 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 149:
#line 696 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 151:
#line 703 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 152:
#line 705 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 153:
#line 707 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 154:
#line 709 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 155:
#line 711 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 156:
#line 713 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 166:
#line 728 "ace.yacc"
    {sprintf((yyval.str),"<=");}
    break;

  case 167:
#line 729 "ace.yacc"
    {sprintf((yyval.str),">=");}
    break;

  case 172:
#line 739 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 176:
#line 772 "ace.yacc"
    { sprintf((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[(1) - (1)].str))); }
    break;

  case 177:
#line 773 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 178:
#line 774 "ace.yacc"
    { sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 179:
#line 775 "ace.yacc"
    { sprintf((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[(1) - (3)].str)),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 181:
#line 785 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 182:
#line 789 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 183:
#line 790 "ace.yacc"
    {sprintf((yyval.str),"[%s]",(yyvsp[(2) - (3)].str));}
    break;

  case 184:
#line 791 "ace.yacc"
    {sprintf((yyval.str),"[%s,%s]",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));}
    break;

  case 185:
#line 794 "ace.yacc"
    { sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 186:
#line 795 "ace.yacc"
    { sprintf((yyval.str),"%s.%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); }
    break;

  case 187:
#line 796 "ace.yacc"
    { sprintf((yyval.str),"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 190:
#line 807 "ace.yacc"
    {sprintf((yyval.str),"0.%s",(yyvsp[(2) - (2)].str));}
    break;

  case 191:
#line 822 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 192:
#line 825 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));
}
    break;

  case 194:
#line 846 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str) );}
    break;

  case 195:
#line 850 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 196:
#line 851 "ace.yacc"
    {
       sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
       }
    break;

  case 198:
#line 855 "ace.yacc"
    {
       sprintf((yyval.str),"INTO TEMP %s%s ",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (4)].str));
}
    break;

  case 199:
#line 859 "ace.yacc"
    {
       sprintf((yyval.str),"%s INTO TEMP %s%s ",(yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (5)].str));
}
    break;

  case 200:
#line 867 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 201:
#line 867 "ace.yacc"
    {strcpy((yyval.str)," WITH NO LOG");}
    break;

  case 203:
#line 889 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 204:
#line 892 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 205:
#line 893 "ace.yacc"
    {sprintf((yyval.str),"ALL");}
    break;

  case 206:
#line 894 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 207:
#line 895 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 209:
#line 900 "ace.yacc"
    { sprintf((yyval.str)," %s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 210:
#line 904 "ace.yacc"
    {
			add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
		}
    break;

  case 211:
#line 907 "ace.yacc"
    {
			sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_select_column((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 213:
#line 917 "ace.yacc"
    {sprintf((yyval.str),"UNITS YEAR");}
    break;

  case 214:
#line 918 "ace.yacc"
    {sprintf((yyval.str),"UNITS MONTH"); }
    break;

  case 215:
#line 919 "ace.yacc"
    {sprintf((yyval.str),"UNITS DAY);"); }
    break;

  case 216:
#line 920 "ace.yacc"
    {sprintf((yyval.str),"UNITS HOUR);"); }
    break;

  case 217:
#line 921 "ace.yacc"
    {sprintf((yyval.str),"UNITS MINUTE);"); }
    break;

  case 218:
#line 922 "ace.yacc"
    {sprintf((yyval.str),"UNITS SECOND);"); }
    break;

  case 219:
#line 926 "ace.yacc"
    {
			sprintf((yyval.str),"%s%s", (yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 222:
#line 931 "ace.yacc"
    {sprintf((yyval.str)," %s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 223:
#line 932 "ace.yacc"
    {sprintf((yyval.str)," %s[%s,%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 224:
#line 933 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 225:
#line 934 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s,%s]",(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str));}
    break;

  case 226:
#line 936 "ace.yacc"
    {
if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
sprintf((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
}
    break;

  case 227:
#line 941 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 228:
#line 943 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 232:
#line 947 "ace.yacc"
    {sprintf((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 233:
#line 948 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 234:
#line 949 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 235:
#line 950 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 236:
#line 951 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 237:
#line 952 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 238:
#line 953 "ace.yacc"
    {sprintf((yyval.str),"%s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 239:
#line 955 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 240:
#line 957 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 241:
#line 959 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 242:
#line 961 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 243:
#line 963 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 244:
#line 965 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 245:
#line 969 "ace.yacc"
    {sprintf((yyval.str),"/%s",(yyvsp[(2) - (2)].str));}
    break;

  case 246:
#line 970 "ace.yacc"
    {sprintf((yyval.str)," MOD %s",(yyvsp[(2) - (2)].str));}
    break;

  case 247:
#line 971 "ace.yacc"
    {sprintf((yyval.str)," POW %s",(yyvsp[(2) - (2)].str));}
    break;

  case 248:
#line 972 "ace.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 249:
#line 973 "ace.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 250:
#line 974 "ace.yacc"
    {sprintf((yyval.str),"+%s",(yyvsp[(2) - (2)].str));}
    break;

  case 251:
#line 975 "ace.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 256:
#line 985 "ace.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 259:
#line 1003 "ace.yacc"
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[(1) - (1)].cmd));
		}
    break;

  case 260:
#line 1008 "ace.yacc"
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
#line 1030 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).command_u.commands.commands.commands_val=(yyvsp[(2) - (3)].commands).commands.commands_val;
		(yyval.cmd).command_u.commands.commands.commands_len=(yyvsp[(2) - (3)].commands).commands.commands_len;
	}
    break;

  case 272:
#line 1067 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[(2) - (5)].str));
	
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(4) - (5)].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).command_u.cmd_call.fcall->lexpr);
}
    break;

  case 278:
#line 1085 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_FOR;
		(yyval.cmd).command_u.cmd_for.varid=find_variable((yyvsp[(2) - (9)].str));
		(yyval.cmd).command_u.cmd_for.start=(yyvsp[(4) - (9)].expr);
		(yyval.cmd).command_u.cmd_for.finish=(yyvsp[(6) - (9)].expr);
		(yyval.cmd).command_u.cmd_for.step=(yyvsp[(7) - (9)].expr);
	}
    break;

  case 279:
#line 1094 "ace.yacc"
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
    break;

  case 280:
#line 1095 "ace.yacc"
    { (yyval.expr)=(yyvsp[(1) - (2)].expr);}
    break;

  case 281:
#line 1099 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_IF;
	(yyval.cmd).command_u.cmd_if.condition=(yyvsp[(2) - (5)].expr);
	(yyval.cmd).command_u.cmd_if.command=(struct command *)DUP((yyvsp[(4) - (5)].cmd));
	(yyval.cmd).command_u.cmd_if.elsecommand=(struct command *)DUP((yyvsp[(5) - (5)].cmd));
}
    break;

  case 282:
#line 1107 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).command_u.null=1;
	}
    break;

  case 283:
#line 1110 "ace.yacc"
    { COPY((yyval.cmd),(yyvsp[(2) - (2)].cmd)); }
    break;

  case 284:
#line 1115 "ace.yacc"
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
#line 1126 "ace.yacc"
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
#line 1137 "ace.yacc"
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
#line 1150 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
    break;

  case 290:
#line 1157 "ace.yacc"
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 291:
#line 1169 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).command_u.cmd_need.nlines=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 292:
#line 1175 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).command_u.cmd_pause.message=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 293:
#line 1182 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).command_u.cmd_print.printnl=atoi((yyvsp[(3) - (3)].str));
	(yyval.cmd).command_u.cmd_print.print=(yyvsp[(2) - (3)].expr);
}
    break;

  case 294:
#line 1190 "ace.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 295:
#line 1190 "ace.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 296:
#line 1193 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).command_u.cmd_printfile.filename=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 297:
#line 1199 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=atoi((yyvsp[(2) - (3)].str));

	}
    break;

  case 298:
#line 1204 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=-1;
	}
    break;

  case 299:
#line 1211 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		(yyval.cmd).command_u.cmd_while.condition=(yyvsp[(2) - (4)].expr);
		(yyval.cmd).command_u.cmd_while.command=(struct command *)DUP((yyvsp[(4) - (4)].cmd));
}
    break;

  case 385:
#line 1344 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (1)].agg_val));
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 386:
#line 1348 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (3)].agg_val));
		(yyval.agg_val).wexpr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 387:
#line 1353 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(2) - (2)].agg_val));
		(yyval.agg_val).isgroup=1;
	}
    break;

  case 388:
#line 1357 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(2) - (4)].agg_val));
		(yyval.agg_val).wexpr=(struct expr *)DUP((yyvsp[(4) - (4)].expr));
		(yyval.agg_val).isgroup=1;
	}
    break;

  case 389:
#line 1365 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 390:
#line 1370 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 391:
#line 1375 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 392:
#line 1380 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 393:
#line 1385 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 394:
#line 1390 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 395:
#line 1395 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 396:
#line 1403 "ace.yacc"
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
#line 1423 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 398:
#line 1431 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 399:
#line 1438 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 400:
#line 1447 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 401:
#line 1453 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 402:
#line 1460 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 403:
#line 1468 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 404:
#line 1477 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 405:
#line 1484 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 406:
#line 1491 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 407:
#line 1493 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(2) - (3)].str)); 
	}
    break;

  case 408:
#line 1500 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 409:
#line 1504 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 410:
#line 1508 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 411:
#line 1512 "ace.yacc"
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
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 413:
#line 1529 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 414:
#line 1535 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 415:
#line 1541 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 416:
#line 1548 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 417:
#line 1554 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 418:
#line 1555 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 419:
#line 1561 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 420:
#line 1567 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 421:
#line 1574 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 422:
#line 1580 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 423:
#line 1588 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 424:
#line 1595 "ace.yacc"
    {
		printf("NIY\n");
		sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 425:
#line 1599 "ace.yacc"
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

  case 426:
#line 1609 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 427:
#line 1615 "ace.yacc"
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

  case 428:
#line 1626 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 429:
#line 1633 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
	}
    break;

  case 430:
#line 1640 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 431:
#line 1649 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_NULL;
	}
    break;

  case 432:
#line 1655 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 433:
#line 1659 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 434:
#line 1663 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 435:
#line 1667 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4583 "y.tab.c"
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


#line 1693 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

