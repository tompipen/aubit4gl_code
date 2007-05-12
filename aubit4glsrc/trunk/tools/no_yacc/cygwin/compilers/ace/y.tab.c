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
#define YYLAST   3122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  437
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
     870,   876,   877,   880,   885,   893,   903,   904,   906,   908,
     912,   916,   919,   923,   924,   926,   929,   933,   937,   942,
     944,   946,   948,   950,   952,   954,   956,   958,   960,   962,
     964,   966,   968,   970,   972,   974,   976,   978,   980,   982,
     984,   986,   988,   990,   992,   994,   996,   998,  1000,  1002,
    1004,  1006,  1008,  1010,  1012,  1014,  1016,  1018,  1020,  1022,
    1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,  1042,
    1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,
    1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,
    1084,  1086,  1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,
    1104,  1106,  1108,  1110,  1112,  1114,  1118,  1121,  1126,  1128,
    1130,  1134,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,
    1170,  1174,  1178,  1182,  1186,  1188,  1192,  1194,  1196,  1198,
    1200,  1205,  1210,  1215,  1220,  1225,  1229,  1232,  1235,  1238,
    1241,  1244,  1247,  1250,  1252,  1254,  1256,  1258,  1260,  1264,
    1265,  1267,  1269,  1271,  1273,  1276,  1279,  1282
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     166,     0,    -1,   167,   168,   176,   180,   184,   188,    -1,
      52,    31,    65,    -1,    52,   101,    65,    -1,    -1,   169,
      -1,    57,   170,    65,    -1,   171,    -1,   170,   171,    -1,
      31,   173,    -1,   158,   174,   175,    -1,   118,   110,   277,
      45,   174,   175,    -1,    77,   172,    -1,   101,    -1,   174,
     175,    -1,   173,    48,   174,   175,    -1,   101,    -1,    77,
      -1,    86,    -1,    41,    -1,    41,   109,   277,    44,    -1,
     157,    -1,   157,   109,   277,    44,    -1,    53,    -1,    71,
      -1,   134,    -1,   135,    -1,    54,    -1,    87,    -1,    99,
      -1,    99,   109,   277,    44,    -1,    99,   109,   277,    48,
     277,    44,    -1,    56,    -1,    56,   109,   277,    44,    -1,
      56,   109,   277,    48,   277,    44,    -1,    -1,   177,    -1,
      85,   178,    65,    -1,   179,    -1,   178,   179,    -1,   125,
      73,   174,     3,   278,    -1,    -1,   181,    -1,   114,   182,
      65,    -1,   183,    -1,   182,   183,    -1,   127,   142,   123,
     278,    -1,   127,   142,   123,    -1,   127,   142,   278,    -1,
     127,   142,    72,   278,    -1,    93,    97,   277,    -1,    37,
      97,   277,    -1,   143,    97,   277,    -1,   115,    94,   277,
      -1,   128,    97,   277,    -1,   144,   278,    -1,   186,    65,
      -1,   185,    65,    -1,   243,    -1,   185,   132,   243,    -1,
     126,   278,   187,   194,    -1,    -1,    58,   278,    -1,    74,
      67,   129,    65,    -1,    74,   190,   189,    -1,    -1,    65,
      -1,   191,    -1,   190,   191,    -1,    70,   115,    81,   259,
      -1,   115,   146,   259,    -1,   115,    81,   259,    -1,   108,
      67,   129,   259,    -1,   108,    92,   129,   259,    -1,    35,
      78,   107,   193,   259,    -1,    26,    78,   107,   193,   259,
      -1,   101,   110,   281,    48,   281,    45,    -1,   101,   110,
     281,    45,    -1,   101,    -1,   192,    -1,    89,    -1,    -1,
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
      42,    63,   238,    -1,   279,    -1,   279,    -1,    -1,   110,
      89,    45,    -1,   110,    89,    48,    89,    45,    -1,   279,
     239,    -1,   236,    63,   279,   239,    -1,   236,    63,    23,
      -1,   279,    -1,   105,    -1,    63,    89,    -1,    -1,   131,
     244,   251,   252,   213,   247,    -1,   246,    -1,   131,   251,
     252,   213,   247,    -1,    -1,   147,   235,   245,    -1,   198,
      -1,    88,   140,   249,   248,    -1,    -1,   160,    -1,   279,
      -1,   109,   131,   251,   252,   213,    44,    -1,    -1,    28,
      -1,    60,    -1,   148,    -1,   253,    -1,   252,    48,   253,
      -1,   256,    -1,   256,   101,    -1,   256,    -1,   154,    -1,
     152,    -1,   149,    -1,   150,    -1,   151,    -1,   153,    -1,
     256,    22,   256,    -1,   256,    24,   256,    -1,   256,   121,
     256,    -1,   256,   255,    -1,   256,    23,   256,    -1,   256,
      21,   256,    -1,   256,    20,   256,    -1,   197,    -1,   279,
      -1,   279,   110,   277,    45,    -1,   279,   110,   277,    48,
     277,    45,    -1,   279,    63,   279,   110,   277,    45,    -1,
     279,    63,   279,   110,   277,    48,   277,    45,    -1,    62,
     279,    -1,   279,    63,   279,    -1,   279,    63,    23,    -1,
      91,    -1,    90,    -1,   156,    -1,    23,    -1,   109,   256,
      44,    -1,    53,   109,   257,    44,    -1,    55,   109,   257,
      44,    -1,   100,   109,   257,    44,    -1,   164,   109,   257,
      44,    -1,   279,   109,   257,    44,    -1,    51,   109,    23,
      44,    -1,    34,   109,   235,   256,    44,    -1,   162,   109,
     235,   256,    44,    -1,   163,   109,   235,   256,    44,    -1,
     139,   109,   235,   256,    44,    -1,    51,   109,   235,   256,
      44,    -1,   256,    -1,   257,    48,   256,    -1,    -1,   197,
      -1,   260,    -1,   259,   260,    -1,   263,    -1,   265,    -1,
     276,    -1,   267,    -1,   270,    -1,   271,    -1,   275,    -1,
     272,    -1,   274,    -1,   261,    -1,   161,   259,    65,    -1,
      39,   262,   109,   285,    44,    -1,    53,    -1,   100,    -1,
     164,    -1,    55,    -1,   279,    -1,    73,   174,    11,   281,
     142,   281,   264,    61,   260,    -1,    -1,   138,   281,    -1,
      83,   281,   141,   260,   266,    -1,    -1,    64,   260,    -1,
      95,   101,    11,   269,    -1,    95,   101,   110,   281,    45,
      11,   269,    -1,    95,   101,   110,   281,    48,   281,    45,
      11,   269,    -1,    -1,   269,    -1,   281,    -1,   269,    48,
     281,    -1,   102,   277,    96,    -1,   119,   278,    -1,   122,
     268,   273,    -1,    -1,   132,    -1,   124,   278,    -1,   133,
     277,    96,    -1,   133,   142,   144,    -1,   159,   281,    61,
     260,    -1,    89,    -1,    42,    -1,   101,    -1,   280,    -1,
      26,    -1,    30,    -1,    27,    -1,    35,    -1,    36,    -1,
      37,    -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,
      43,    -1,    47,    -1,    49,    -1,    50,    -1,    52,    -1,
      54,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      61,    -1,    64,    -1,    66,    -1,    67,    -1,    69,    -1,
      70,    -1,    71,    -1,    73,    -1,    74,    -1,    75,    -1,
      76,    -1,    77,    -1,    78,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    92,    -1,    93,    -1,
      94,    -1,    95,    -1,    17,    -1,    96,    -1,    97,    -1,
      98,    -1,    99,    -1,   102,    -1,   107,    -1,   108,    -1,
     114,    -1,   115,    -1,   118,    -1,   119,    -1,   121,    -1,
     123,    -1,   125,    -1,   126,    -1,   127,    -1,   128,    -1,
     129,    -1,   130,    -1,   133,    -1,   134,    -1,   135,    -1,
     137,    -1,   138,    -1,   140,    -1,   141,    -1,   142,    -1,
     143,    -1,   145,    -1,   146,    -1,   155,    -1,   157,    -1,
     158,    -1,   159,    -1,   161,    -1,   162,    -1,   163,    -1,
     284,    -1,   283,    -1,   283,     4,   281,    -1,    78,   283,
      -1,    78,   283,     4,   281,    -1,    51,    -1,   120,    -1,
      33,   107,   281,    -1,   145,   107,   281,    -1,    34,   107,
     281,    -1,   163,   107,   281,    -1,   162,   107,   281,    -1,
     284,    22,   284,    -1,   284,   121,   284,    -1,   284,    24,
     284,    -1,   284,    23,   284,    -1,   284,    21,   284,    -1,
     284,     6,   284,    -1,   284,     5,   284,    -1,   284,    20,
     284,    -1,   284,     3,   284,    -1,   288,    -1,   284,   233,
     284,    -1,    91,    -1,    90,    -1,   156,    -1,    53,    -1,
      53,   109,   286,    44,    -1,   100,   109,   286,    44,    -1,
     164,   109,   286,    44,    -1,    55,   109,   286,    44,    -1,
     101,   109,   286,    44,    -1,   109,   284,    44,    -1,    47,
     284,    -1,    31,   284,    -1,   284,   137,    -1,   284,     8,
      -1,   284,     9,    -1,   284,    43,    -1,   284,   255,    -1,
     192,    -1,   282,    -1,   287,    -1,   286,    -1,   284,    -1,
     286,    48,   284,    -1,    -1,    42,    -1,   106,    -1,   242,
      -1,    89,    -1,    21,   242,    -1,    21,    89,    -1,    20,
     242,    -1,    20,    89,    -1
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
     483,   484,   486,   488,   490,   499,   499,   509,   510,   515,
     517,   522,   529,   530,   531,   536,   542,   547,   548,   554,
     559,   563,   564,   569,   570,   571,   574,   575,   583,   583,
     587,   598,   599,   602,   603,   606,   607,   612,   613,   618,
     619,   624,   625,   630,   631,   637,   638,   643,   645,   652,
     653,   656,   660,   661,   669,   674,   678,   683,   685,   687,
     689,   695,   696,   700,   701,   706,   708,   710,   712,   714,
     716,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   738,   739,   740,   741,   743,   744,   745,   746,
     776,   777,   778,   779,   785,   789,   793,   794,   795,   798,
     799,   800,   806,   811,   811,   826,   826,   844,   847,   854,
     855,   858,   859,   865,   865,   869,   886,   890,   891,   892,
     893,   897,   898,   902,   905,   912,   915,   916,   917,   918,
     919,   920,   924,   926,   928,   930,   932,   934,   936,   938,
     939,   940,   941,   942,   943,   944,   949,   951,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   965,
     967,   969,   971,   973,   979,   979,   985,   986,   998,  1003,
    1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,
    1025,  1062,  1073,  1074,  1075,  1076,  1077,  1080,  1089,  1090,
    1094,  1102,  1105,  1110,  1121,  1132,  1145,  1149,  1152,  1152,
    1164,  1170,  1177,  1185,  1185,  1188,  1194,  1199,  1206,  1215,
    1218,  1222,  1223,  1228,  1229,  1230,  1232,  1233,  1234,  1235,
    1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,
    1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1335,  1339,  1343,  1348,  1352,  1360,  1365,
    1370,  1375,  1380,  1385,  1390,  1398,  1406,  1413,  1422,  1429,
    1436,  1444,  1453,  1460,  1467,  1469,  1476,  1480,  1484,  1488,
    1498,  1505,  1511,  1517,  1524,  1530,  1531,  1537,  1543,  1550,
    1556,  1564,  1571,  1575,  1585,  1591,  1602,  1609,  1616,  1625,
    1631,  1635,  1639,  1643,  1647,  1651,  1655,  1659
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
  "value_expr_list", "value_specification", "commands", "command",
  "call_command", "func_identifier", "for_command", "op_step",
  "if_command", "op_else", "let_command", "op_expr_concat", "expr_concat",
  "need_command", "pause_command", "print_command", "op_semi",
  "print_file_command", "skip_command", "while_command", "int_val",
  "string", "identifier", "reserved_word", "expr", "aggregate",
  "aggregate_elem", "val_expression", "op_val_expr_list", "val_expr_list",
  "null_expr", "literal_expr", 0
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
     265,   266,   266,   267,   267,   267,   268,   268,   269,   269,
     270,   271,   272,   273,   273,   274,   275,   275,   276,   277,
     278,   279,   279,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   281,   282,   282,   282,   282,   283,   283,
     283,   283,   283,   283,   283,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   285,   285,   286,   286,   287,
     288,   288,   288,   288,   288,   288,   288,   288
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
       5,     0,     2,     4,     7,     9,     0,     1,     1,     3,
       3,     2,     3,     0,     1,     2,     3,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     4,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     3,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     1,     1,     2,     2,     2,     2
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
     299,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,   195,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   300,    56,    44,    46,    62,   207,
       0,     2,    58,     0,    57,    16,     0,     0,     0,     0,
       0,     0,    52,    51,    54,     0,    48,    49,    55,    53,
       0,    82,   208,   209,   210,     0,     0,     0,     0,     0,
       0,     0,    66,    68,    60,    21,    34,     0,    31,     0,
      23,    12,    41,    50,    47,    63,    84,     0,    61,    83,
     345,     0,     0,   241,   303,   305,   304,     0,   306,   307,
     308,   309,   310,   311,   312,    87,   313,   314,   315,   316,
       0,   317,     0,   318,     0,   319,   320,   321,   322,   323,
       0,     0,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,    90,
     239,   238,   341,   342,   343,   344,   346,   347,   348,   349,
       0,   301,   350,   193,    88,   351,   352,     0,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,     0,   370,   371,   372,   373,
     374,   375,   376,   240,   377,   378,   379,   380,   381,   382,
       0,   229,    89,     0,   211,   213,   230,   302,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    65,    69,     0,
       0,     0,   180,   100,   381,   382,    86,    97,   102,     0,
       0,   181,   101,   186,    94,    93,    92,    91,   176,   176,
       0,     0,   235,   194,     0,     0,   176,   176,   176,     0,
       0,     0,   121,   199,     0,     0,     0,     0,     0,   214,
       0,   218,   219,   220,   217,   221,   216,   225,     0,     0,
       0,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,     0,     0,     0,     0,    72,   258,
     269,   260,   261,   263,   264,   265,   267,   268,   266,   262,
      71,    35,    32,    85,     0,     0,   103,   104,    99,     0,
       0,     0,   189,   177,   178,   179,     0,     0,     0,   254,
       0,     0,     0,   242,     0,     0,     0,     0,   212,     0,
     110,   111,   113,   116,   185,     0,   122,   123,     0,    95,
     176,   201,   196,   228,   227,   222,   226,   223,   224,   237,
     236,     0,     0,    81,    79,    80,     0,     0,    70,    73,
      74,   272,   275,   273,   274,     0,   276,     0,     0,     0,
       0,     0,     0,   430,     0,   388,   409,     0,     0,   433,
     407,   406,     0,    79,   431,     0,   389,     0,   408,     0,
       0,     0,   423,   432,     0,   424,   384,   383,   404,     0,
       0,   291,   293,   287,   288,   295,     0,     0,     0,     0,
     259,   183,   185,    98,   191,   186,   182,     0,     0,   248,
       0,   243,     0,   244,   245,     0,     0,     0,   246,     0,
     114,     0,   117,   192,     0,     0,     0,     0,   109,   127,
     129,   131,   175,   174,   173,   172,   133,     0,   153,     0,
     124,   125,     0,     0,     0,     0,   247,   231,     0,     0,
      76,    75,   429,     0,   437,   436,   435,   434,   417,     0,
       0,   416,     0,     0,   386,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   419,   420,   163,
     161,   170,   164,   171,   165,   167,   169,   166,   168,     0,
       0,     0,     0,     0,   421,   162,     0,   418,     0,   422,
       0,     0,   290,   294,   292,     0,   297,   296,     0,   270,
     190,   187,     0,   249,   253,   255,   252,   250,   251,   118,
       0,   112,   132,     0,   135,   136,   207,     0,   153,     0,
       0,     0,   154,     0,     0,     0,     0,   106,   107,   215,
       0,   126,   120,   203,   205,    96,   207,   200,   197,     0,
       0,     0,   427,     0,   426,   425,     0,   390,   392,     0,
       0,     0,     0,     0,   415,   391,   394,   393,     0,   281,
     385,   403,   401,   400,   402,   399,   395,   398,   397,   396,
     405,   283,     0,   289,   298,     0,   115,     0,     0,   134,
     128,   130,   138,   256,   148,   256,   150,   155,   156,   256,
       0,   141,   143,     0,   142,     0,   139,   140,   158,   157,
       0,   105,   204,   202,     0,   233,     0,   232,    78,     0,
     271,     0,     0,   410,   413,   387,   411,   414,   412,     0,
     280,     0,     0,   188,   119,     0,   257,     0,   151,     0,
       0,   145,     0,   137,   108,     0,     0,     0,   428,   278,
     282,     0,     0,     0,   147,   256,   149,   256,   160,     0,
     199,   234,    77,     0,     0,   284,     0,   206,   152,   144,
     146,   159,   198,   279,     0,     0,   277,   285
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   257,   122,   123,   432,   396,   138,
     139,   261,   241,   381,   493,   266,   267,   268,   348,   591,
     490,   587,   376,   292,   370,   371,   372,   570,   293,   377,
     491,   592,   478,   479,   480,   481,   482,   483,   655,   656,
     657,   708,   690,   719,   484,   687,   585,   485,   548,   486,
     356,   373,   270,   271,   352,   272,   472,   433,    70,    89,
     597,   598,   382,   663,   593,   487,   115,   243,   244,   588,
     307,   359,   360,   688,   328,   329,   330,   405,   331,   714,
     332,   680,   333,   442,   443,   334,   335,   336,   554,   337,
     338,   339,    51,    85,   246,   247,   444,   435,   436,   437,
     603,   604,   605,   438
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -593
static const yytype_int16 yypact[] =
{
      27,    -2,    93,    66,    99,   128,  -593,   -17,   119,  -593,
    -593,  -593,   107,   144,   137,   107,   -16,  -593,   136,   158,
    -593,  -593,   256,   964,  -593,  -593,   217,   964,  -593,  -593,
     243,   -20,  -593,   182,    31,  -593,   107,   202,  -593,  -593,
     218,  -593,  -593,  -593,  -593,   220,  -593,  -593,   226,  -593,
    -593,   299,  -593,   107,  -593,  -593,   246,   258,   272,   225,
     295,   300,   356,    33,  -593,   356,  -593,   338,   -48,   349,
    -593,   964,   217,   217,   217,   217,   107,   415,   217,   217,
     217,   -29,   217,   217,  -593,  -593,  -593,  -593,   363,    -4,
     238,  -593,  -593,   291,  -593,  -593,   379,    59,   142,   380,
     964,   356,  -593,  -593,  -593,   356,   356,  -593,  -593,  -593,
     356,   114,  -593,  -593,  -593,  1561,   367,   381,   297,   319,
     160,     1,   485,  -593,  -593,  -593,  -593,   217,  -593,   217,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  1991,  -593,  -593,
    -593,    67,   150,  -593,  -593,  -593,  -593,   318,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
     352,  -593,   365,  -593,   369,  -593,  -593,  -593,  -593,  -593,
    2694,   371,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
     375,  -593,  -593,  -593,  -593,  -593,  -593,  1561,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,   383,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,   384,   385,
     386,  -593,  -593,   -13,  -593,   420,   172,  -593,   366,   396,
     407,   409,   359,   390,  1815,  1815,  -593,  -593,  -593,   468,
     478,  1991,   461,  -593,  -593,  -593,   477,  -593,    -8,   463,
     483,  -593,  -593,   100,  -593,  -593,  -593,  -593,    11,    -5,
    1561,  1561,  -593,  -593,  1561,  1770,    11,    11,    11,  1561,
    1561,  2130,   527,   101,  1561,  1561,  1561,  1561,  1561,  -593,
    1561,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  2412,  1561,
     217,   169,   169,  -593,  1815,  1815,  1815,  1704,   107,  2861,
     431,   217,   356,  2861,   356,   -78,  2861,  1815,  1815,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,
    1815,  -593,  -593,   477,  2694,  1991,  -593,  -593,  -593,  2555,
    2694,   444,  -593,  -593,  -593,  -593,  1561,   493,  1561,   364,
     173,   180,   270,  -593,  1561,  1561,  1561,   292,  -593,  2269,
     492,  -593,  -593,  2694,   496,   731,  -593,   464,   404,  -593,
      11,  -593,  -593,   348,   348,   -15,   -15,   355,   364,  -593,
     436,   294,   110,  -593,   437,  -593,  1815,  1815,  1815,  1815,
    1815,  -593,  -593,  -593,  -593,   448,  -593,   545,   157,   223,
    2861,   451,   452,  -593,  2861,  -593,   453,   454,    25,  -593,
    -593,  -593,   457,   168,  -593,  2861,  -593,   460,  -593,   475,
     479,   459,  -593,  -593,   419,  -593,   571,   936,  -593,     8,
     488,  -593,   455,   540,  -593,  -593,   445,   495,   535,  1831,
    -593,  -593,  -593,  -593,  -593,   487,  -593,   208,  2897,  -593,
    2905,  -593,  1561,  -593,  -593,  2911,  2924,  2968,  -593,  2130,
    -593,  2130,  -593,  -593,  1265,   494,   494,   578,   597,   600,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,   912,   954,  1561,
    -593,   529,  2694,  1991,   476,   217,  -593,  -593,   217,  2861,
    1815,  1815,  2861,  2861,  -593,  -593,  -593,  -593,   427,  2861,
    2861,   -40,  2861,  2861,   607,  2861,  2861,   893,  2861,  2861,
    2861,  2861,  1815,  2861,  2861,  2861,  2861,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  -593,  2861,
    2861,  2861,  2861,  2861,  -593,  -593,  2861,  -593,  2861,  -593,
    2861,  2861,  -593,  -593,  -593,  2861,  -593,  -593,  1815,  -593,
    -593,  -593,   533,  -593,  -593,   364,  -593,  -593,  -593,  -593,
     301,  -593,  -593,   507,  -593,  -593,    -4,    42,  1862,   731,
     731,  1561,  -593,   514,   517,   322,  1117,   595,  -593,   364,
     731,  -593,  -593,   490,  -593,   477,    -4,  -593,  -593,   334,
     612,   351,   936,   614,   616,  -593,   523,  -593,  -593,   306,
     312,  2861,   320,   332,  -593,  -593,  -593,  -593,   333,   602,
    -593,   936,   979,  2850,   298,   298,  1847,  1847,   427,   936,
     936,   540,   368,  -593,  -593,   637,  -593,  2130,  1561,  -593,
     600,  -593,   364,   331,  -593,   331,  -593,  -593,  -593,   447,
    1561,  -593,  -593,  1413,  -593,   494,  -593,  -593,  -593,   364,
    1561,   597,  -593,  -593,  1561,  -593,   217,  -593,  -593,  2861,
    -593,  2861,  2861,  -593,  -593,  -593,  -593,  -593,  -593,  1815,
    -593,   677,  2861,  -593,  -593,   -13,  -593,   345,  -593,   347,
     623,  -593,   279,  -593,  -593,   -13,   645,   646,   936,   556,
    -593,  2861,   650,   654,  -593,   447,  -593,   447,  -593,  1561,
     101,  -593,  -593,  2861,   639,   540,   691,  -593,  -593,  -593,
    -593,   364,  -593,  -593,  1815,  2861,  -593,   540
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -593,  -593,  -593,  -593,  -593,  -593,   694,  -593,  -593,   -11,
      17,  -593,  -593,  -593,   683,  -593,  -593,  -593,   659,  -593,
    -593,  -593,  -593,  -593,  -593,  -593,   603,   -24,   414,  -593,
    -593,  -593,  -554,  -593,  -593,  -259,   382,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,  -464,   360,  -593,  -411,  -593,
    -593,  -593,  -471,   149,   151,   269,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -593,    85,  -593,  -593,  -410,  -593,
    -213,  -136,  -593,  -254,   277,  -593,  -593,  -115,   651,  -593,
    -593,  -593,    35,  -593,  -593,  -455,  -542,  -592,   456,    87,
    -219,   -99,  -157,  -465,  -247,  -278,  -593,  -593,  -593,  -593,
    -593,  -593,  -593,  -593,  -547,  -593,  -593,  -593,  -593,  -593,
    -593,  -593,   -42,   -53,   -54,  -593,  -186,  -593,   335,  -310,
    -593,   -58,  -593,  -593
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const yytype_int16 yytable[] =
{
     242,   269,   343,   631,    27,   569,   577,   571,   340,   298,
     545,    50,    88,    84,    12,    12,   245,    92,   357,   550,
     574,   575,   346,   353,   112,    71,   275,   277,   107,     4,
      96,    97,    98,    99,   638,   290,   102,   103,   104,   353,
     108,   109,    77,   105,    52,    54,   685,   579,   132,    28,
     450,   347,   133,   134,   664,   354,   113,   135,   411,   412,
      13,    13,   450,   291,   446,   100,   358,   398,   399,   400,
      56,   354,   695,   364,   365,   366,   415,   581,   586,     1,
     449,   546,   254,   273,    93,   259,   639,   260,    95,   686,
     451,   686,   242,     6,   106,   686,   456,   547,    86,     5,
     508,    14,    14,   126,   511,    30,   300,   127,   285,   301,
     302,   303,   304,   305,   306,   517,   282,   131,   551,   661,
     450,   450,   450,     7,   361,   269,    57,   362,   644,   646,
     171,   658,   367,   434,   301,   302,   303,   304,   305,   306,
     448,    15,    15,   355,   114,   426,  -184,   255,    58,   500,
     501,   686,   391,   686,   715,   497,   274,    65,   498,   355,
      59,    60,    66,  -185,    10,   242,   242,   494,   586,   242,
     427,   450,   203,   684,   242,   242,    61,    62,   727,   242,
     242,   242,   242,   242,   691,   242,   128,   429,   430,   378,
     129,   245,   602,    11,   242,   383,   384,   385,   386,   387,
     693,   388,   602,   602,    18,   602,   602,   273,    21,   269,
     351,   602,   379,   171,   621,   622,   623,   461,   549,    56,
     171,   462,   450,   450,   463,   136,   137,   252,   462,   624,
     625,   626,   627,   628,   595,   308,   629,   374,   630,   276,
     718,   242,   720,   242,   619,    24,   504,    26,   380,   242,
     242,   242,   253,   561,   390,   203,   562,   458,   393,   460,
     242,    30,   203,   406,   116,   465,   466,   467,   392,   441,
     394,   445,    33,   117,   703,    57,   488,   516,   499,   440,
     634,   309,   310,   447,   710,   709,   171,   395,   395,   549,
     452,   273,   549,   505,   507,   455,   452,    58,   549,   294,
     295,   296,   297,   298,    36,   118,    50,   407,   119,    59,
      60,    72,   506,   601,   464,   374,    53,   606,   462,   473,
     541,   542,   543,   607,   608,    61,    62,    73,   203,    74,
     647,   648,   615,   616,   617,    75,   468,   620,   496,   649,
     462,   544,   462,    78,    76,   636,   120,   242,   545,   637,
     673,   141,   142,   121,   671,    79,   674,   269,   650,   242,
     671,   698,   242,   565,   676,   632,    80,    81,   671,   633,
     296,   297,   298,   155,   242,   488,   677,   678,   578,   665,
     671,   671,   666,   549,   294,   295,   296,   297,   298,   704,
     589,   706,    82,   705,   171,   705,   668,    83,    84,   669,
     300,   700,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,    90,   681,    94,   374,   682,   374,   101,   546,
     189,   110,    66,   125,   130,   675,   250,   278,   301,   302,
     303,   304,   305,   306,   251,   547,   203,   204,   594,   273,
     294,   295,   296,   297,   298,   248,   726,   301,   302,   303,
     304,   305,   306,   599,   609,   610,   600,   612,   613,   249,
     283,   279,   576,   618,   242,   242,   242,   141,   142,   300,
     544,   242,   313,   311,   280,   242,   300,   545,   281,   549,
     488,   488,   642,   697,   284,   300,   699,   659,   315,   155,
     314,   488,   286,   287,   288,   289,   702,   301,   302,   303,
     304,   305,   306,   312,   301,   302,   303,   304,   305,   306,
     171,   116,   341,   301,   302,   303,   304,   305,   306,   316,
     117,   299,   342,   242,   344,   345,   349,   723,   242,   350,
     242,   375,   439,   457,   242,   242,   189,   459,   242,   245,
     471,   300,  -184,   489,   492,   242,   495,   499,   546,   242,
     256,   692,   203,   204,   285,   119,   503,   502,   509,   510,
     522,   589,   512,   513,   547,   245,   515,   518,   521,   301,
     302,   303,   304,   305,   306,   523,   301,   302,   303,   304,
     305,   306,   519,   374,   552,   474,   520,   553,   555,   556,
     242,   557,   242,   120,   242,   140,   558,   351,   141,   142,
     121,   143,   579,   573,   144,   145,   580,   596,   146,   590,
     721,   611,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   635,   643,   696,   157,   645,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   576,   169,
     170,   171,   172,   660,   173,   174,   475,   175,   176,   177,
     662,   178,   179,   180,   181,   182,   183,   667,   670,   184,
     185,   186,   187,   188,   671,   672,   679,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   476,   683,   203,   204,   205,   206,   477,   701,   707,
     711,   712,   208,   209,   713,   716,   210,   211,   717,   212,
     724,   213,   725,   214,   215,   216,   217,   218,   219,   576,
      29,   220,   221,   222,    55,   223,   224,   225,   226,   227,
     228,   229,    87,   230,   231,   258,   397,   453,   640,   470,
     689,   641,   560,   232,   233,   234,   235,   236,   474,   237,
     238,   239,   240,   572,   124,   722,   368,   694,   140,     0,
       0,   141,   142,   514,   143,     0,     0,   144,   145,     0,
       0,   146,     0,     0,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     0,     0,     0,   157,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     0,   169,   170,   171,   172,     0,   173,   174,   475,
     175,   176,   177,     0,   178,   179,   180,   181,   182,   183,
       0,     0,   184,   185,   186,   187,   188,     0,     0,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   476,     0,   203,   204,   205,   206,
     477,     0,     0,     0,     0,   208,   209,     0,     0,   210,
     211,     0,   212,     0,   213,     0,   214,   215,   216,   217,
     218,   219,     0,     0,   220,   221,   222,     0,   223,   224,
     225,   226,   227,   228,   229,     0,   230,   231,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   233,   234,   235,
     236,     0,   237,   238,   239,   240,   524,     0,   525,   526,
       0,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,     0,     0,
       0,     0,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,     0,     0,     0,     0,   544,   614,     0,   524,
       0,   525,   526,   545,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   582,   545,     0,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   294,   295,   296,   297,   298,   544,
       0,     0,     0,     0,     0,   526,   545,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   545,    37,     0,     0,     0,     0,
       0,     0,     0,     0,   546,     0,     0,    38,    39,     0,
      40,     0,   544,     0,     0,     0,     0,     0,     0,   545,
     547,     0,     0,     0,     0,    41,     0,     0,   583,     0,
       0,    42,   301,   302,   303,   304,   305,   306,     0,     0,
      43,    44,     0,     0,     0,     0,     0,   546,   584,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   547,     0,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,   302,   303,   304,   305,
     306,     0,     0,     0,     0,     0,     0,     0,    46,    47,
     546,     0,     0,   301,   302,   303,   304,   305,   306,     0,
       0,     0,     0,     0,     0,     0,   547,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   301,   302,
     303,   304,   305,   306,   140,     0,     0,   141,   142,     0,
     143,     0,     0,   144,   145,   651,   652,   146,     0,     0,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,     0,     0,     0,   157,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,     0,   169,   170,
     171,   172,     0,   173,   174,     0,   175,   176,   177,     0,
     178,   179,   180,   181,   182,   183,     0,     0,   184,   185,
     186,   187,   188,     0,     0,     0,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
       0,     0,   203,   204,   205,   206,   653,     0,     0,     0,
       0,   208,   209,     0,     0,   210,   211,     0,   212,     0,
     213,     0,   214,   215,   216,   217,   218,   219,     0,     0,
     220,   221,   222,   654,   223,   224,   225,   226,   227,   228,
     229,     0,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,   232,   233,   234,   235,   236,     0,   237,   238,
     239,   240,   140,     0,     0,   141,   142,     0,   143,     0,
       0,   144,   145,     0,     0,   146,     0,     0,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,     0,
       0,     0,   157,     0,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,     0,   169,   170,   171,   172,
       0,   173,   174,   475,   175,   176,   177,     0,   178,   179,
     180,   181,   182,   183,     0,     0,   184,   185,   186,   187,
     188,     0,     0,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   476,     0,
     203,   204,   205,   206,   477,     0,     0,     0,     0,   208,
     209,     0,     0,   210,   211,     0,   212,     0,   213,     0,
     214,   215,   216,   217,   218,   219,     0,     0,   220,   221,
     222,     0,   223,   224,   225,   226,   227,   228,   229,     0,
     230,   231,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   234,   235,   236,     0,   237,   238,   239,   240,
     140,     0,     0,   141,   142,     0,   143,     0,     0,   144,
     145,     0,     0,   146,     0,     0,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,     0,     0,
     157,     0,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,     0,   169,   170,   171,   172,     0,   173,
     174,     0,   175,   176,   177,     0,   178,   179,   180,   181,
     182,   183,     0,     0,   184,   185,   186,   187,   188,     0,
       0,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,     0,     0,   203,   204,
     205,   206,   207,     0,     0,     0,     0,   208,   209,     0,
       0,   210,   211,     0,   212,     0,   213,     0,   214,   215,
     216,   217,   218,   219,   576,     0,   220,   221,   222,     0,
     223,   224,   225,   226,   227,   228,   229,     0,   230,   231,
       0,     0,     0,     0,     0,     0,     0,     0,   232,   233,
     234,   235,   236,     0,   237,   238,   239,   240,   140,     0,
       0,   141,   142,     0,   143,     0,     0,   144,   145,     0,
       0,   146,     0,     0,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,     0,     0,     0,   157,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,     0,   169,   170,   171,   172,     0,   173,   174,     0,
     175,   176,   177,     0,   178,   179,   180,   181,   182,   183,
       0,     0,   184,   185,   186,   187,   188,     0,     0,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,     0,     0,   203,   204,   205,   206,
     207,     0,     0,     0,     0,   208,   209,     0,     0,   210,
     211,     0,   212,     0,   213,     0,   214,   215,   216,   217,
     218,   219,     0,     0,   220,   221,   222,     0,   223,   224,
     225,   226,   227,   228,   229,     0,   230,   231,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   233,   234,   235,
     236,   140,   237,   238,   239,   240,     0,     0,     0,     0,
     144,   145,     0,     0,   146,     0,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,     0,   156,     0,     0,
       0,   157,     0,   158,   159,     0,   161,   401,   163,   402,
     165,   166,   167,   168,     0,   169,     0,     0,   172,     0,
     173,   174,     0,   175,   176,   177,     0,   178,   179,   180,
     181,   182,   183,     0,     0,   184,   185,   186,   187,   188,
     294,   295,   296,   297,   298,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   403,   201,   202,     0,     0,     0,
       0,   205,   206,     0,   363,     0,     0,     0,   208,   209,
       0,     0,   210,   211,     0,   212,     0,   213,     0,   214,
     215,   216,   217,   218,   219,     0,     0,   220,   221,   222,
       0,   223,   224,     0,   226,   227,   228,   229,     0,   230,
     231,     0,     0,     0,   317,     0,     0,     0,     0,   232,
       0,   234,   235,   236,     0,   237,   264,   265,   404,   582,
     317,   543,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   294,   295,   296,   297,   298,     0,   318,     0,
     544,   300,     0,     0,     0,     0,   559,   545,   319,     0,
       0,     0,     0,     0,   318,     0,   363,     0,     0,     0,
     320,     0,   545,     0,   319,     0,     0,   321,     0,   301,
     302,   303,   304,   305,   306,     0,   320,     0,     0,     0,
       0,     0,     0,   321,   322,     0,     0,   323,     0,   324,
       0,     0,     0,     0,     0,     0,   583,     0,   325,     0,
     322,     0,     0,   323,     0,   324,     0,     0,     0,     0,
       0,     0,     0,     0,   325,     0,   584,     0,   546,     0,
       0,     0,     0,     0,   326,     0,   327,     0,     0,     0,
       0,     0,     0,   300,   547,     0,     0,     0,     0,     0,
     326,     0,   327,     0,     0,     0,   301,   302,   303,   304,
     305,   306,     0,     0,     0,     0,     0,     0,   140,     0,
       0,   301,   302,   303,   304,   305,   306,   144,   145,     0,
       0,   146,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,   154,   262,   156,     0,     0,     0,   157,     0,
     158,   159,     0,   161,     0,   163,     0,   165,   166,   167,
     168,     0,   169,     0,     0,   172,     0,   173,   174,     0,
     175,   176,   177,     0,   178,   179,   180,   181,   182,   183,
       0,     0,   184,   185,   186,   187,   188,     0,     0,     0,
     263,     0,     0,   192,   193,   194,   195,   196,   197,   198,
     199,     0,   201,   202,     0,     0,     0,     0,   205,   206,
       0,     0,     0,     0,     0,   208,   209,     0,     0,   210,
     211,     0,   212,     0,   213,     0,   214,   215,   216,   217,
     218,   219,     0,     0,   220,   221,   222,     0,   223,   224,
       0,   226,   227,   228,   229,     0,   230,   231,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   140,   234,   235,
     236,     0,   237,   264,   265,     0,   144,   145,     0,     0,
     146,     0,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   262,   156,     0,     0,     0,   157,     0,   158,
     159,     0,   161,     0,   163,     0,   165,   166,   167,   168,
       0,   169,     0,     0,   172,     0,   173,   174,     0,   175,
     176,   177,     0,   178,   179,   180,   181,   182,   183,     0,
       0,   184,   185,   186,   187,   188,     0,     0,     0,     0,
       0,     0,   192,   193,   194,   195,   196,   197,   198,   199,
       0,   201,   202,     0,     0,     0,     0,   205,   206,     0,
       0,     0,     0,   369,   208,   209,     0,     0,   210,   211,
       0,   212,     0,   213,     0,   214,   215,   216,   217,   218,
     219,     0,     0,   220,   221,   222,     0,   223,   224,     0,
     226,   227,   228,   229,     0,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,   232,   140,   234,   235,   236,
       0,   237,   264,   265,     0,   144,   145,     0,     0,   146,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   262,   156,     0,     0,     0,   157,     0,   158,   159,
       0,   161,     0,   163,     0,   165,   166,   167,   168,     0,
     169,     0,     0,   172,     0,   173,   174,     0,   175,   176,
     177,     0,   178,   179,   180,   181,   182,   183,     0,     0,
     184,   185,   186,   187,   188,     0,     0,     0,     0,     0,
       0,   192,   193,   194,   195,   196,   197,   198,   199,     0,
     201,   202,     0,     0,     0,     0,   205,   206,   469,     0,
       0,     0,     0,   208,   209,     0,     0,   210,   211,     0,
     212,     0,   213,     0,   214,   215,   216,   217,   218,   219,
       0,     0,   220,   221,   222,     0,   223,   224,     0,   226,
     227,   228,   229,     0,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,   234,   235,   236,   140,
     237,   264,   265,     0,     0,   389,     0,     0,   144,   145,
       0,     0,   146,     0,     0,     0,     0,   148,   149,   150,
     151,   152,   153,   154,     0,   156,     0,     0,     0,   157,
       0,   158,   159,     0,   161,     0,   163,     0,   165,   166,
     167,   168,     0,   169,     0,     0,   172,     0,   173,   174,
       0,   175,   176,   177,     0,   178,   179,   180,   181,   182,
     183,     0,     0,   184,   185,   186,   187,   188,     0,     0,
       0,     0,     0,     0,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   201,   202,     0,     0,     0,     0,   205,
     206,     0,     0,     0,     0,     0,   208,   209,     0,     0,
     210,   211,     0,   212,     0,   213,     0,   214,   215,   216,
     217,   218,   219,     0,     0,   220,   221,   222,     0,   223,
     224,     0,   226,   227,   228,   229,     0,   230,   231,     0,
       0,     0,     0,     0,     0,     0,     0,   232,     0,   234,
     235,   236,   140,   237,   264,   265,     0,     0,   454,     0,
       0,   144,   145,     0,     0,   146,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,   154,     0,   156,     0,
       0,     0,   157,     0,   158,   159,     0,   161,     0,   163,
       0,   165,   166,   167,   168,     0,   169,     0,     0,   172,
       0,   173,   174,     0,   175,   176,   177,     0,   178,   179,
     180,   181,   182,   183,     0,     0,   184,   185,   186,   187,
     188,     0,     0,     0,     0,     0,     0,   192,   193,   194,
     195,   196,   197,   198,   199,     0,   201,   202,     0,     0,
       0,     0,   205,   206,     0,     0,     0,     0,     0,   208,
     209,     0,     0,   210,   211,     0,   212,     0,   213,     0,
     214,   215,   216,   217,   218,   219,     0,     0,   220,   221,
     222,     0,   223,   224,     0,   226,   227,   228,   229,     0,
     230,   231,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   140,   234,   235,   236,     0,   237,   264,   265,     0,
     144,   145,     0,     0,   146,     0,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,     0,   156,     0,     0,
       0,   157,     0,   158,   159,     0,   161,     0,   163,     0,
     165,   166,   167,   168,     0,   169,     0,     0,   172,     0,
     173,   174,     0,   175,   176,   177,     0,   178,   179,   180,
     181,   182,   183,     0,     0,   184,   185,   186,   187,   188,
       0,     0,     0,     0,     0,     0,   192,   193,   194,   195,
     196,   197,   198,   199,     0,   201,   202,     0,     0,     0,
       0,   205,   206,     0,     0,     0,     0,     0,   208,   209,
       0,     0,   210,   211,     0,   212,     0,   213,     0,   214,
     215,   216,   217,   218,   219,     0,     0,   220,   221,   222,
       0,   223,   224,     0,   226,   227,   228,   229,     0,   230,
     231,     0,     0,     0,     0,     0,     0,     0,     0,   232,
       0,   234,   235,   236,     0,   237,   264,   265,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,     0,     0,     0,     0,     0,
       0,   408,   409,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   410,   544,   411,   412,     0,     0,     0,     0,
     545,     0,     0,   413,     0,     0,     0,     0,   414,     0,
       0,     0,   415,     0,   416,     0,   417,   294,   295,   296,
     297,   298,     0,     0,   171,   294,   295,   296,   297,   298,
       0,   294,   295,   296,   297,   298,     0,     0,     0,   418,
       0,   563,     0,     0,   294,   295,   296,   297,   298,   564,
     419,   420,   421,     0,     0,   566,     0,     0,     0,     0,
       0,   422,   423,     0,     0,     0,   203,   424,   567,     0,
     425,   546,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,   547,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,     0,   301,
     302,   303,   304,   305,   306,     0,   427,     0,     0,     0,
       0,     0,   568,     0,     0,     0,     0,   428,   300,     0,
       0,     0,     0,   429,   430,   431,   300,     0,     0,     0,
       0,     0,   300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   300,   301,   302,   303,   304,
     305,   306,     0,     0,   301,   302,   303,   304,   305,   306,
     301,   302,   303,   304,   305,   306,     0,     0,     0,     0,
       0,     0,     0,   301,   302,   303,   304,   305,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   301,   302,   303,
     304,   305,   306
};

static const yytype_int16 yycheck[] =
{
     115,   137,   261,   550,    15,   469,   477,   471,   255,    24,
      50,    89,    65,    42,    31,    31,   115,    65,    23,    11,
     475,   476,    30,    28,    28,    36,   141,   142,    81,    31,
      72,    73,    74,    75,   576,    48,    78,    79,    80,    28,
      82,    83,    53,    72,    27,    65,   638,     5,   101,    65,
     328,    59,   105,   106,   596,    60,    60,   110,    33,    34,
      77,    77,   340,    76,   142,    76,   279,   314,   315,   316,
      37,    60,   664,   286,   287,   288,    51,   487,   488,    52,
     327,   121,    81,   137,   132,   127,    44,   129,    71,   643,
     344,   645,   207,     0,   123,   649,   350,   137,    65,   101,
     410,   118,   118,    44,   414,   125,   121,    48,   207,   149,
     150,   151,   152,   153,   154,   425,   170,   100,   110,   590,
     398,   399,   400,    57,   281,   261,    93,   284,   583,   584,
      63,   586,   289,   319,   149,   150,   151,   152,   153,   154,
     326,   158,   158,   148,   148,   120,    46,   146,   115,   396,
     397,   705,   309,   707,   701,    45,    89,   126,    48,   148,
     127,   128,   131,    63,    65,   280,   281,   380,   578,   284,
     145,   449,   105,   637,   289,   290,   143,   144,   725,   294,
     295,   296,   297,   298,   649,   300,    44,   162,   163,    88,
      48,   290,   502,    65,   309,   294,   295,   296,   297,   298,
     655,   300,   512,   513,    85,   515,   516,   261,   101,   345,
     110,   521,   111,    63,   524,   525,   526,    44,   437,    37,
      63,    48,   500,   501,    44,   111,   112,    67,    48,   539,
     540,   541,   542,   543,   493,    63,   546,   291,   548,    89,
     705,   356,   707,   358,   522,   101,    89,   110,   147,   364,
     365,   366,    92,    45,   308,   105,    48,   356,    89,   358,
     375,   125,   105,   317,    26,   364,   365,   366,   310,   322,
     101,   324,   114,    35,   685,    93,   375,   109,   110,   321,
     558,   109,   110,   325,   695,     6,    63,   311,   312,   508,
     344,   345,   511,   408,   409,   349,   350,   115,   517,    20,
      21,    22,    23,    24,    48,    67,    89,   318,    70,   127,
     128,   109,    89,   499,    44,   369,    73,   503,    48,   373,
      22,    23,    24,   509,   510,   143,   144,   109,   105,   109,
       8,     9,   518,   519,   520,   109,    44,   523,    44,    17,
      48,    43,    48,    97,    45,    44,   108,   462,    50,    48,
      44,    20,    21,   115,    48,    97,    44,   493,    36,   474,
      48,   671,   477,   462,    44,   551,    94,   142,    48,   555,
      22,    23,    24,    42,   489,   474,    44,    44,   477,    45,
      48,    48,    48,   602,    20,    21,    22,    23,    24,    44,
     489,    44,    97,    48,    63,    48,    45,    97,    42,    48,
     121,   679,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,    74,    45,    65,   469,    48,   471,     3,   121,
      89,    58,   131,    44,    44,   611,   129,   109,   149,   150,
     151,   152,   153,   154,   115,   137,   105,   106,   492,   493,
      20,    21,    22,    23,    24,    78,   724,   149,   150,   151,
     152,   153,   154,   495,   512,   513,   498,   515,   516,    78,
      89,   109,   131,   521,   579,   580,   581,    20,    21,   121,
      43,   586,    65,   107,   109,   590,   121,    50,   109,   698,
     579,   580,   581,   669,   109,   121,   672,   586,   129,    42,
      81,   590,   109,   109,   109,   109,   682,   149,   150,   151,
     152,   153,   154,   107,   149,   150,   151,   152,   153,   154,
      63,    26,    44,   149,   150,   151,   152,   153,   154,   129,
      35,   101,    44,   638,    63,    48,    63,   713,   643,    46,
     645,     4,   101,    89,   649,   650,    89,    44,   653,   638,
      48,   121,    46,    79,   140,   660,   110,   110,   121,   664,
      65,   650,   105,   106,   653,    70,    11,   109,   107,   107,
     141,   660,   109,   109,   137,   664,   109,   107,   109,   149,
     150,   151,   152,   153,   154,     4,   149,   150,   151,   152,
     153,   154,   107,   637,    96,     7,   107,   132,    48,   144,
     705,    96,   707,   108,   709,    17,    61,   110,    20,    21,
     115,    23,     5,   109,    26,    27,     6,   131,    30,    80,
     709,     4,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    89,   109,   666,    47,   109,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,   131,    61,
      62,    63,    64,    48,    66,    67,    68,    69,    70,    71,
     160,    73,    74,    75,    76,    77,    78,    45,    44,    81,
      82,    83,    84,    85,    48,   142,    64,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    45,   105,   106,   107,   108,   109,    11,    66,
      45,    45,   114,   115,   138,    45,   118,   119,    44,   121,
      61,   123,    11,   125,   126,   127,   128,   129,   130,   131,
      16,   133,   134,   135,    31,   137,   138,   139,   140,   141,
     142,   143,    63,   145,   146,   122,   312,   345,   579,   369,
     645,   580,   455,   155,   156,   157,   158,   159,     7,   161,
     162,   163,   164,   474,    93,   710,   290,   660,    17,    -1,
      -1,    20,    21,   418,    23,    -1,    -1,    26,    27,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    71,    -1,    73,    74,    75,    76,    77,    78,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    -1,   105,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,   118,
     119,    -1,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,    -1,    -1,   133,   134,   135,    -1,   137,   138,
     139,   140,   141,   142,   143,    -1,   145,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,   156,   157,   158,
     159,    -1,   161,   162,   163,   164,     3,    -1,     5,     6,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    43,    44,    -1,     3,
      -1,     5,     6,    50,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     7,    50,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    43,
      -1,    -1,    -1,    -1,    -1,     6,    50,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    50,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    53,    54,    -1,
      56,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
     137,    -1,    -1,    -1,    -1,    71,    -1,    -1,    84,    -1,
      -1,    77,   149,   150,   151,   152,   153,   154,    -1,    -1,
      86,    87,    -1,    -1,    -1,    -1,    -1,   121,   104,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     121,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    17,    -1,    -1,    20,    21,    -1,
      23,    -1,    -1,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    64,    -1,    66,    67,    -1,    69,    70,    71,    -1,
      73,    74,    75,    76,    77,    78,    -1,    -1,    81,    82,
      83,    84,    85,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,   105,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,   114,   115,    -1,    -1,   118,   119,    -1,   121,    -1,
     123,    -1,   125,   126,   127,   128,   129,   130,    -1,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   156,   157,   158,   159,    -1,   161,   162,
     163,   164,    17,    -1,    -1,    20,    21,    -1,    23,    -1,
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
     155,   156,   157,   158,   159,    -1,   161,   162,   163,   164,
      17,    -1,    -1,    20,    21,    -1,    23,    -1,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    -1,    66,
      67,    -1,    69,    70,    71,    -1,    73,    74,    75,    76,
      77,    78,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,   105,   106,
     107,   108,   109,    -1,    -1,    -1,    -1,   114,   115,    -1,
      -1,   118,   119,    -1,   121,    -1,   123,    -1,   125,   126,
     127,   128,   129,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,   140,   141,   142,   143,    -1,   145,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   156,
     157,   158,   159,    -1,   161,   162,   163,   164,    17,    -1,
      -1,    20,    21,    -1,    23,    -1,    -1,    26,    27,    -1,
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
      -1,    -1,   118,   119,    -1,   121,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,    -1,    -1,   133,   134,   135,
      -1,   137,   138,    -1,   140,   141,   142,   143,    -1,   145,
     146,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,   155,
      -1,   157,   158,   159,    -1,   161,   162,   163,   164,     7,
      39,    24,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    73,    -1,
      43,   121,    -1,    -1,    -1,    -1,    65,    50,    83,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    44,    -1,    -1,    -1,
      95,    -1,    50,    -1,    83,    -1,    -1,   102,    -1,   149,
     150,   151,   152,   153,   154,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   119,    -1,    -1,   122,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,   133,    -1,
     119,    -1,    -1,   122,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,   104,    -1,   121,    -1,
      -1,    -1,    -1,    -1,   159,    -1,   161,    -1,    -1,    -1,
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
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,   157,   158,   159,    -1,   161,   162,   163,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    43,    33,    34,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    51,    -1,    53,    -1,    55,    20,    21,    22,
      23,    24,    -1,    -1,    63,    20,    21,    22,    23,    24,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    78,
      -1,    44,    -1,    -1,    20,    21,    22,    23,    24,    44,
      89,    90,    91,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,   100,   101,    -1,    -1,    -1,   105,   106,    44,    -1,
     109,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,   137,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,   156,   121,    -1,
      -1,    -1,    -1,   162,   163,   164,   121,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   149,   150,   151,   152,
     153,   154,    -1,    -1,   149,   150,   151,   152,   153,   154,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154
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
      89,   277,   175,    73,    65,   179,    37,    93,   115,   127,
     128,   143,   144,   182,   183,   126,   131,   184,   185,   186,
     243,   174,   109,   109,   109,   109,    45,   174,    97,    97,
      94,   142,    97,    97,    42,   278,    65,   183,   278,   244,
      74,   188,    65,   132,    65,   175,   277,   277,   277,   277,
     174,     3,   277,   277,   277,    72,   123,   278,   277,   277,
      58,   187,    28,    60,   148,   251,    26,    35,    67,    70,
     108,   115,   190,   191,   243,    44,    44,    48,    44,    48,
      44,   175,   278,   278,   278,   278,   111,   112,   194,   195,
      17,    20,    21,    23,    26,    27,    30,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    47,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    61,
      62,    63,    64,    66,    67,    69,    70,    71,    73,    74,
      75,    76,    77,    78,    81,    82,    83,    84,    85,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   105,   106,   107,   108,   109,   114,   115,
     118,   119,   121,   123,   125,   126,   127,   128,   129,   130,
     133,   134,   135,   137,   138,   139,   140,   141,   142,   143,
     145,   146,   155,   156,   157,   158,   159,   161,   162,   163,
     164,   197,   242,   252,   253,   256,   279,   280,    78,    78,
     129,   115,    67,    92,    81,   146,    65,   189,   191,   277,
     277,   196,    42,    89,   162,   163,   200,   201,   202,   236,
     237,   238,   240,   279,    89,   242,    89,   242,   109,   109,
     109,   109,   279,    89,   109,   256,   109,   109,   109,   109,
      48,    76,   208,   213,    20,    21,    22,    23,    24,   101,
     121,   149,   150,   151,   152,   153,   154,   255,    63,   109,
     110,   107,   107,    65,    81,   129,   129,    39,    73,    83,
      95,   102,   119,   122,   124,   133,   159,   161,   259,   260,
     261,   263,   265,   267,   270,   271,   272,   274,   275,   276,
     259,    44,    44,   200,    63,    48,    30,    59,   203,    63,
      46,   110,   239,    28,    60,   148,   235,    23,   235,   256,
     257,   257,   257,    44,   235,   235,   235,   257,   253,   113,
     209,   210,   211,   236,   279,     4,   207,   214,    88,   111,
     147,   198,   247,   256,   256,   256,   256,   256,   256,    23,
     279,   257,   277,    89,   101,   192,   193,   193,   259,   259,
     259,    53,    55,   100,   164,   262,   279,   174,    20,    21,
      31,    33,    34,    42,    47,    51,    53,    55,    78,    89,
      90,    91,   100,   101,   106,   109,   120,   145,   156,   162,
     163,   164,   192,   242,   281,   282,   283,   284,   288,   101,
     277,   278,   268,   269,   281,   278,   142,   277,   281,   259,
     260,   238,   279,   201,    23,   279,   238,    89,   256,    44,
     256,    44,    48,    44,    44,   256,   256,   256,    44,   109,
     211,    48,   241,   279,     7,    68,   103,   109,   217,   218,
     219,   220,   221,   222,   229,   232,   234,   250,   256,    79,
     205,   215,   140,   199,   235,   110,    44,    45,    48,   110,
     259,   259,   109,    11,    89,   242,    89,   242,   284,   107,
     107,   284,   109,   109,   283,   109,   109,   284,   107,   107,
     107,   109,   141,     4,     3,     5,     6,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    43,    50,   121,   137,   233,   255,
      11,   110,    96,   132,   273,    48,   144,    96,    61,    65,
     239,    45,    48,    44,    44,   256,    44,    44,    44,   210,
     212,   210,   220,   109,   250,   250,   131,   217,   256,     5,
       6,   233,     7,    84,   104,   231,   233,   206,   254,   256,
      80,   204,   216,   249,   279,   200,   131,   245,   246,   277,
     277,   281,   284,   285,   286,   287,   281,   281,   281,   286,
     286,     4,   286,   286,    44,   281,   281,   281,   286,   260,
     281,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   269,   281,   281,   260,    89,    44,    48,   251,    44,
     218,   219,   256,   109,   250,   109,   250,     8,     9,    17,
      36,    28,    29,   109,   136,   223,   224,   225,   250,   256,
      48,   217,   160,   248,   251,    45,    48,    45,    45,    48,
      44,    48,   142,    44,    44,   281,    44,    44,    44,    64,
     266,    45,    48,    45,   210,   252,   197,   230,   258,   230,
     227,   258,   256,   250,   254,   252,   277,   281,   284,   281,
     260,    11,   281,   213,    44,    48,    44,    66,   226,     6,
     213,    45,    45,   138,   264,   269,    45,    44,   258,   228,
     258,   256,   247,   281,    61,    11,   260,   269
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
#line 485 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 92:
#line 487 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 93:
#line 489 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 94:
#line 491 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
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
		sprintf((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str));
		
	}
    break;

  case 98:
#line 510 "ace.yacc"
    {
sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 100:
#line 517 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"I%d",atoi((yyvsp[(1) - (1)].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 101:
#line 522 "ace.yacc"
    {
		char buff[256];
		sprintf(buff,"C%s",(yyvsp[(1) - (1)].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 102:
#line 529 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 105:
#line 537 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 106:
#line 543 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 108:
#line 549 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 109:
#line 554 "ace.yacc"
    {sprintf((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[(2) - (2)].str));}
    break;

  case 110:
#line 559 "ace.yacc"
    {sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 112:
#line 565 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 113:
#line 569 "ace.yacc"
    {sprintf((yyval.str)," %s ", (yyvsp[(1) - (1)].str));}
    break;

  case 114:
#line 570 "ace.yacc"
    {sprintf((yyval.str)," %s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 115:
#line 571 "ace.yacc"
    {sprintf((yyval.str)," %s (%s) ",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 117:
#line 575 "ace.yacc"
    {
		sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		ace_add_table((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 119:
#line 583 "ace.yacc"
    { sprintf((yyval.str)," %s,%s ",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 120:
#line 591 "ace.yacc"
    {
sprintf((yyval.str),"%s %s %s %s",
(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),
(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
}
    break;

  case 121:
#line 598 "ace.yacc"
    {strcpy((yyval.str),"\n0");}
    break;

  case 123:
#line 602 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 125:
#line 606 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 128:
#line 614 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 130:
#line 620 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 132:
#line 626 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 134:
#line 632 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 135:
#line 637 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 136:
#line 638 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 137:
#line 644 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 138:
#line 646 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 144:
#line 670 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 147:
#line 684 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 148:
#line 686 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 149:
#line 688 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 150:
#line 690 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 152:
#line 697 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 153:
#line 700 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 155:
#line 707 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 156:
#line 709 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 157:
#line 711 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 158:
#line 713 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 159:
#line 715 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 160:
#line 717 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 170:
#line 732 "ace.yacc"
    {sprintf((yyval.str),"<=");}
    break;

  case 171:
#line 733 "ace.yacc"
    {sprintf((yyval.str),">=");}
    break;

  case 176:
#line 743 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 180:
#line 776 "ace.yacc"
    { sprintf((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[(1) - (1)].str))); }
    break;

  case 181:
#line 777 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 182:
#line 778 "ace.yacc"
    { sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 183:
#line 779 "ace.yacc"
    { sprintf((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[(1) - (3)].str)),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 185:
#line 789 "ace.yacc"
    {sprintf((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 186:
#line 793 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 187:
#line 794 "ace.yacc"
    {sprintf((yyval.str),"[%s]",(yyvsp[(2) - (3)].str));}
    break;

  case 188:
#line 795 "ace.yacc"
    {sprintf((yyval.str),"[%s,%s]",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));}
    break;

  case 189:
#line 798 "ace.yacc"
    { sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 190:
#line 799 "ace.yacc"
    { sprintf((yyval.str),"%s.%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); }
    break;

  case 191:
#line 800 "ace.yacc"
    { sprintf((yyval.str),"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 194:
#line 811 "ace.yacc"
    {sprintf((yyval.str),"0.%s",(yyvsp[(2) - (2)].str));}
    break;

  case 195:
#line 826 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 196:
#line 829 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));
}
    break;

  case 198:
#line 850 "ace.yacc"
    {sprintf((yyval.str),"%s %s %s %s %s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str) );}
    break;

  case 199:
#line 854 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 200:
#line 855 "ace.yacc"
    {
       sprintf((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
       }
    break;

  case 202:
#line 859 "ace.yacc"
    {
       sprintf((yyval.str),"INTO TEMP %s%s ",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (4)].str));
}
    break;

  case 203:
#line 865 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 204:
#line 865 "ace.yacc"
    {strcpy((yyval.str)," WITH NO LOG");}
    break;

  case 206:
#line 887 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 207:
#line 890 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 208:
#line 891 "ace.yacc"
    {sprintf((yyval.str),"ALL");}
    break;

  case 209:
#line 892 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 210:
#line 893 "ace.yacc"
    {sprintf((yyval.str),"DISTINCT");}
    break;

  case 212:
#line 898 "ace.yacc"
    { sprintf((yyval.str)," %s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:
#line 902 "ace.yacc"
    {
			add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
		}
    break;

  case 214:
#line 905 "ace.yacc"
    {
			sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_select_column((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 216:
#line 915 "ace.yacc"
    {sprintf((yyval.str),"UNITS YEAR");}
    break;

  case 217:
#line 916 "ace.yacc"
    {sprintf((yyval.str),"UNITS MONTH"); }
    break;

  case 218:
#line 917 "ace.yacc"
    {sprintf((yyval.str),"UNITS DAY);"); }
    break;

  case 219:
#line 918 "ace.yacc"
    {sprintf((yyval.str),"UNITS HOUR);"); }
    break;

  case 220:
#line 919 "ace.yacc"
    {sprintf((yyval.str),"UNITS MINUTE);"); }
    break;

  case 221:
#line 920 "ace.yacc"
    {sprintf((yyval.str),"UNITS SECOND);"); }
    break;

  case 222:
#line 925 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 223:
#line 927 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 224:
#line 929 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 225:
#line 931 "ace.yacc"
    {sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 226:
#line 933 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 227:
#line 935 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 228:
#line 937 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 231:
#line 940 "ace.yacc"
    {sprintf((yyval.str)," %s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 232:
#line 941 "ace.yacc"
    {sprintf((yyval.str)," %s[%s,%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 233:
#line 942 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 234:
#line 943 "ace.yacc"
    {sprintf((yyval.str)," %s.%s[%s,%s]",(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str));}
    break;

  case 235:
#line 945 "ace.yacc"
    {
if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
sprintf((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
}
    break;

  case 236:
#line 950 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 237:
#line 952 "ace.yacc"
    {sprintf((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 241:
#line 956 "ace.yacc"
    {sprintf((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 242:
#line 957 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 243:
#line 958 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 244:
#line 959 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 245:
#line 960 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 246:
#line 961 "ace.yacc"
    {sprintf((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 247:
#line 962 "ace.yacc"
    {sprintf((yyval.str),"%s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 248:
#line 964 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 249:
#line 966 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 250:
#line 968 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 251:
#line 970 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 252:
#line 972 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 253:
#line 974 "ace.yacc"
    {sprintf((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 255:
#line 980 "ace.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 258:
#line 998 "ace.yacc"
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[(1) - (1)].cmd));
		}
    break;

  case 259:
#line 1003 "ace.yacc"
    {
		COPY((yyval.commands),(yyvsp[(1) - (2)].commands));
		(yyval.commands).commands.commands_len++;
		(yyval.commands).commands.commands_val=realloc(
		(yyval.commands).commands.commands_val,
		(yyval.commands).commands.commands_len*sizeof(struct command));
		COPY((yyval.commands).commands.commands_val[ (yyval.commands).commands.commands_len-1 ],(yyvsp[(2) - (2)].cmd));
	}
    break;

  case 270:
#line 1025 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).command_u.commands.commands.commands_val=(yyvsp[(2) - (3)].commands).commands.commands_val;
		(yyval.cmd).command_u.commands.commands.commands_len=(yyvsp[(2) - (3)].commands).commands.commands_len;
	}
    break;

  case 271:
#line 1062 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[(2) - (5)].str));
	
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(4) - (5)].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).command_u.cmd_call.fcall->lexpr);
}
    break;

  case 277:
#line 1080 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_FOR;
		(yyval.cmd).command_u.cmd_for.varid=find_variable((yyvsp[(2) - (9)].str));
		(yyval.cmd).command_u.cmd_for.start=(yyvsp[(4) - (9)].expr);
		(yyval.cmd).command_u.cmd_for.finish=(yyvsp[(6) - (9)].expr);
		(yyval.cmd).command_u.cmd_for.step=(yyvsp[(7) - (9)].expr);
	}
    break;

  case 278:
#line 1089 "ace.yacc"
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
    break;

  case 279:
#line 1090 "ace.yacc"
    { (yyval.expr)=(yyvsp[(1) - (2)].expr);}
    break;

  case 280:
#line 1094 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_IF;
	(yyval.cmd).command_u.cmd_if.condition=(yyvsp[(2) - (5)].expr);
	(yyval.cmd).command_u.cmd_if.command=(struct command *)DUP((yyvsp[(4) - (5)].cmd));
	(yyval.cmd).command_u.cmd_if.elsecommand=(struct command *)DUP((yyvsp[(5) - (5)].cmd));
}
    break;

  case 281:
#line 1102 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).command_u.null=1;
	}
    break;

  case 282:
#line 1105 "ace.yacc"
    { COPY((yyval.cmd),(yyvsp[(2) - (2)].cmd)); }
    break;

  case 283:
#line 1110 "ace.yacc"
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

  case 284:
#line 1121 "ace.yacc"
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

  case 285:
#line 1132 "ace.yacc"
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

  case 286:
#line 1145 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
    break;

  case 289:
#line 1152 "ace.yacc"
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 290:
#line 1164 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).command_u.cmd_need.nlines=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 291:
#line 1170 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).command_u.cmd_pause.message=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 292:
#line 1177 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).command_u.cmd_print.printnl=atoi((yyvsp[(3) - (3)].str));
	(yyval.cmd).command_u.cmd_print.print=(yyvsp[(2) - (3)].expr);
}
    break;

  case 293:
#line 1185 "ace.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 294:
#line 1185 "ace.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 295:
#line 1188 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).command_u.cmd_printfile.filename=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 296:
#line 1194 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=atoi((yyvsp[(2) - (3)].str));

	}
    break;

  case 297:
#line 1199 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).command_u.cmd_skip.nlines=-1;
	}
    break;

  case 298:
#line 1206 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		(yyval.cmd).command_u.cmd_while.condition=(yyvsp[(2) - (4)].expr);
		(yyval.cmd).command_u.cmd_while.command=(struct command *)DUP((yyvsp[(4) - (4)].cmd));
}
    break;

  case 384:
#line 1339 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (1)].agg_val));
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 385:
#line 1343 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (3)].agg_val));
		(yyval.agg_val).wexpr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 386:
#line 1348 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(2) - (2)].agg_val));
		(yyval.agg_val).isgroup=1;
	}
    break;

  case 387:
#line 1352 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(2) - (4)].agg_val));
		(yyval.agg_val).wexpr=(struct expr *)DUP((yyvsp[(4) - (4)].expr));
		(yyval.agg_val).isgroup=1;
	}
    break;

  case 388:
#line 1360 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 389:
#line 1365 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 390:
#line 1370 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 391:
#line 1375 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 392:
#line 1380 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 393:
#line 1385 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 394:
#line 1390 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(struct expr *)DUP((yyvsp[(3) - (3)].expr));
	}
    break;

  case 395:
#line 1399 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 396:
#line 1407 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 397:
#line 1414 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 398:
#line 1423 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 399:
#line 1429 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 400:
#line 1436 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 401:
#line 1444 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 402:
#line 1453 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 403:
#line 1460 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 404:
#line 1467 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 405:
#line 1469 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr1,(yyvsp[(1) - (3)].expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(3) - (3)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(2) - (3)].str)); 
	}
    break;

  case 406:
#line 1476 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 407:
#line 1480 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 408:
#line 1484 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 409:
#line 1488 "ace.yacc"
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

  case 410:
#line 1498 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 411:
#line 1505 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 412:
#line 1511 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 413:
#line 1517 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 414:
#line 1524 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 415:
#line 1530 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 416:
#line 1531 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 417:
#line 1537 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 418:
#line 1543 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 419:
#line 1550 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 420:
#line 1556 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 421:
#line 1564 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(1) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 422:
#line 1571 "ace.yacc"
    {
		printf("NIY\n");
		sprintf((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 423:
#line 1575 "ace.yacc"
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

  case 424:
#line 1585 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 425:
#line 1591 "ace.yacc"
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

  case 426:
#line 1602 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 427:
#line 1609 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
	}
    break;

  case 428:
#line 1616 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 429:
#line 1625 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_NULL;
	}
    break;

  case 430:
#line 1631 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 431:
#line 1635 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 432:
#line 1639 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 433:
#line 1643 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;

  case 434:
#line 1647 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(2) - (2)].str));
	}
    break;

  case 435:
#line 1651 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(2) - (2)].str));
	}
    break;

  case 436:
#line 1655 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0-atoi((yyvsp[(2) - (2)].str));
	}
    break;

  case 437:
#line 1659 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0-atoi((yyvsp[(2) - (2)].str));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4596 "y.tab.c"
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


#line 1666 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

