
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         a4gl_ace_yyparse
#define yylex           a4gl_ace_yylex
#define yyerror         a4gl_ace_yyerror
#define yylval          a4gl_ace_yylval
#define yychar          a4gl_ace_yychar
#define yydebug         a4gl_ace_yydebug
#define yynerrs         a4gl_ace_yynerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
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

void add_fmt (int cat, struct expr *col, struct acerep_commands commands);

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




/* Line 189 of yacc.c  */
#line 151 "y.tab.c"

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
     INNER_JOIN = 310,
     LEFT_JOIN = 311,
     COUNT = 312,
     TOTAL = 313,
     DATABASE = 314,
     DATE = 315,
     TIME = 316,
     DATETIME = 317,
     DAY = 318,
     DECIMAL = 319,
     DEFINE = 320,
     DELIMITER = 321,
     DESC = 322,
     DISTINCT = 323,
     DO = 324,
     DOLLAR = 325,
     DOT = 326,
     ELSE = 327,
     END = 328,
     ESCAPE = 329,
     EVERY = 330,
     EXISTS = 331,
     EXTERNAL = 332,
     FIRST = 333,
     FLOAT = 334,
     PIPE = 335,
     FOR = 336,
     FORMAT = 337,
     FRACTION = 338,
     FROM = 339,
     FUNCTION = 340,
     GROUP = 341,
     GROUP_BY = 342,
     HAVING = 343,
     HEADER = 344,
     HOUR = 345,
     IF = 346,
     IN = 347,
     INPUT = 348,
     INTEGER = 349,
     INTERVAL = 350,
     INTO = 351,
     INTVAL = 352,
     KW_FALSE = 353,
     KW_TRUE = 354,
     LAST = 355,
     LEFT = 356,
     LENGTH = 357,
     LET = 358,
     LINES = 359,
     MARGIN = 360,
     MINUTE = 361,
     MONEY = 362,
     MONTH = 363,
     NAMED = 364,
     NEED = 365,
     NOT_EXISTS = 366,
     NOT_IN = 367,
     NUMBER_VALUE = 368,
     NUMERIC = 369,
     KW_OF = 370,
     ON = 371,
     OPEN_BRACKET = 372,
     OPEN_SQUARE = 373,
     ORDER_BY = 374,
     ORDER_EXTERNAL_BY = 375,
     OUTER = 376,
     OUTPUT = 377,
     PAGE = 378,
     PAGE_HEADER = 379,
     PAGE_TRAILER = 380,
     PARAM = 381,
     PAUSE = 382,
     PERCENT = 383,
     PRINT = 384,
     PRINTER = 385,
     PRINT_FILE = 386,
     PROMPT = 387,
     READ = 388,
     REPORT = 389,
     RIGHT = 390,
     ROW = 391,
     SECOND = 392,
     SELECT = 393,
     SEMICOLON = 394,
     SKIP = 395,
     SMALLFLOAT = 396,
     SMALLINT = 397,
     SOME = 398,
     STEP = 399,
     TEMP = 400,
     THEN = 401,
     TO = 402,
     TOP = 403,
     TOP_OF_PAGE = 404,
     TRAILER = 405,
     UNION = 406,
     UNIQUE = 407,
     UNITS_DAY = 408,
     UNITS_HOUR = 409,
     UNITS_MINUTE = 410,
     UNITS_MONTH = 411,
     UNITS_SECOND = 412,
     UNITS_YEAR = 413,
     UPDATE = 414,
     USER = 415,
     VARCHAR = 416,
     VARIABLE = 417,
     WHILE = 418,
     WITH_NO_LOG = 419,
     XBEGIN = 420,
     XMAX = 421,
     XMIN = 422,
     YEAR = 423
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
#define INNER_JOIN 310
#define LEFT_JOIN 311
#define COUNT 312
#define TOTAL 313
#define DATABASE 314
#define DATE 315
#define TIME 316
#define DATETIME 317
#define DAY 318
#define DECIMAL 319
#define DEFINE 320
#define DELIMITER 321
#define DESC 322
#define DISTINCT 323
#define DO 324
#define DOLLAR 325
#define DOT 326
#define ELSE 327
#define END 328
#define ESCAPE 329
#define EVERY 330
#define EXISTS 331
#define EXTERNAL 332
#define FIRST 333
#define FLOAT 334
#define PIPE 335
#define FOR 336
#define FORMAT 337
#define FRACTION 338
#define FROM 339
#define FUNCTION 340
#define GROUP 341
#define GROUP_BY 342
#define HAVING 343
#define HEADER 344
#define HOUR 345
#define IF 346
#define IN 347
#define INPUT 348
#define INTEGER 349
#define INTERVAL 350
#define INTO 351
#define INTVAL 352
#define KW_FALSE 353
#define KW_TRUE 354
#define LAST 355
#define LEFT 356
#define LENGTH 357
#define LET 358
#define LINES 359
#define MARGIN 360
#define MINUTE 361
#define MONEY 362
#define MONTH 363
#define NAMED 364
#define NEED 365
#define NOT_EXISTS 366
#define NOT_IN 367
#define NUMBER_VALUE 368
#define NUMERIC 369
#define KW_OF 370
#define ON 371
#define OPEN_BRACKET 372
#define OPEN_SQUARE 373
#define ORDER_BY 374
#define ORDER_EXTERNAL_BY 375
#define OUTER 376
#define OUTPUT 377
#define PAGE 378
#define PAGE_HEADER 379
#define PAGE_TRAILER 380
#define PARAM 381
#define PAUSE 382
#define PERCENT 383
#define PRINT 384
#define PRINTER 385
#define PRINT_FILE 386
#define PROMPT 387
#define READ 388
#define REPORT 389
#define RIGHT 390
#define ROW 391
#define SECOND 392
#define SELECT 393
#define SEMICOLON 394
#define SKIP 395
#define SMALLFLOAT 396
#define SMALLINT 397
#define SOME 398
#define STEP 399
#define TEMP 400
#define THEN 401
#define TO 402
#define TOP 403
#define TOP_OF_PAGE 404
#define TRAILER 405
#define UNION 406
#define UNIQUE 407
#define UNITS_DAY 408
#define UNITS_HOUR 409
#define UNITS_MINUTE 410
#define UNITS_MONTH 411
#define UNITS_SECOND 412
#define UNITS_YEAR 413
#define UPDATE 414
#define USER 415
#define VARCHAR 416
#define VARIABLE 417
#define WHILE 418
#define WITH_NO_LOG 419
#define XBEGIN 420
#define XMAX 421
#define XMIN 422
#define YEAR 423




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 74 "ace.yacc"

	char   str[30000];
	struct acerep_command cmd;
	struct expr expr;
	struct expr *exprptr;
	struct acerep_commands commands;
	struct agg_val agg_val;
	struct acerep_var_usage *var_usage;



/* Line 214 of yacc.c  */
#line 535 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 547 "y.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  169
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  127
/* YYNRULES -- Number of rules.  */
#define YYNRULES  471
/* YYNRULES -- Number of states.  */
#define YYNSTATES  802

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   423

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
     165,   166,   167,   168
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
     350,   357,   363,   369,   371,   375,   377,   380,   385,   386,
     388,   389,   391,   392,   394,   396,   400,   402,   406,   408,
     411,   413,   417,   420,   423,   428,   432,   434,   436,   438,
     440,   442,   448,   452,   458,   462,   464,   468,   469,   471,
     475,   479,   483,   487,   494,   496,   498,   500,   502,   504,
     506,   508,   510,   512,   514,   516,   518,   520,   522,   524,
     525,   527,   529,   531,   533,   535,   539,   543,   545,   547,
     548,   552,   558,   561,   566,   570,   572,   574,   577,   578,
     585,   587,   593,   594,   598,   600,   605,   611,   612,   614,
     616,   623,   624,   626,   628,   630,   632,   636,   638,   641,
     645,   647,   649,   651,   653,   655,   657,   659,   662,   664,
     666,   671,   678,   685,   694,   697,   701,   705,   707,   709,
     711,   713,   717,   722,   727,   732,   737,   742,   748,   754,
     760,   766,   772,   775,   778,   781,   783,   786,   789,   792,
     795,   796,   798,   800,   802,   806,   808,   810,   813,   815,
     817,   819,   821,   823,   825,   827,   829,   831,   833,   837,
     843,   845,   847,   849,   851,   853,   863,   864,   867,   873,
     874,   877,   882,   890,   900,   901,   903,   905,   909,   913,
     916,   920,   921,   923,   926,   930,   934,   939,   941,   943,
     945,   947,   949,   951,   953,   955,   957,   959,   961,   963,
     965,   967,   969,   971,   973,   975,   977,   979,   981,   983,
     985,   987,   989,   991,   993,   995,   997,   999,  1001,  1003,
    1005,  1007,  1009,  1011,  1013,  1015,  1017,  1019,  1021,  1023,
    1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,  1041,  1043,
    1045,  1047,  1049,  1051,  1053,  1055,  1057,  1059,  1061,  1063,
    1065,  1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,  1083,
    1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,  1103,
    1104,  1107,  1110,  1113,  1115,  1117,  1120,  1123,  1126,  1129,
    1132,  1135,  1138,  1142,  1146,  1150,  1154,  1158,  1161,  1163,
    1165,  1167,  1169,  1171,  1173,  1178,  1183,  1188,  1193,  1198,
    1202,  1204,  1207,  1210,  1212,  1214,  1216,  1218,  1220,  1222,
    1227,  1232,  1237,  1242,  1247,  1251,  1254,  1257,  1259,  1261,
    1264,  1267,  1270,  1273,  1276,  1279,  1282,  1285,  1288,  1290,
    1293,  1296,  1299,  1302,  1305,  1308,  1311,  1314,  1317,  1320,
    1323,  1326,  1329,  1332,  1335,  1338,  1341,  1344,  1347,  1350,
    1352,  1354,  1356,  1358,  1360,  1362,  1364,  1368,  1369,  1371,
    1373,  1375
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     170,     0,    -1,   171,   172,   180,   184,   188,   192,    -1,
      59,     8,    73,    -1,    59,   109,    73,    -1,    -1,   173,
      -1,    65,   174,    73,    -1,   175,    -1,   174,   175,    -1,
       8,   177,    -1,   162,   178,   179,    -1,   126,   118,   280,
      52,   178,   179,    -1,    85,   176,    -1,   109,    -1,   178,
     179,    -1,   177,     4,   178,   179,    -1,   109,    -1,    85,
      -1,    94,    -1,    49,    -1,    49,   117,   280,    51,    -1,
     161,    -1,   161,   117,   280,    51,    -1,    60,    -1,    79,
      -1,   141,    -1,   142,    -1,    62,    -1,    95,    -1,   107,
      -1,   107,   117,   280,    51,    -1,   107,   117,   280,     4,
     280,    51,    -1,    64,    -1,    64,   117,   280,    51,    -1,
      64,   117,   280,     4,   280,    51,    -1,    -1,   181,    -1,
      93,   182,    73,    -1,   183,    -1,   182,   183,    -1,   132,
      81,   178,     5,   281,    -1,    -1,   185,    -1,   122,   186,
      73,    -1,   187,    -1,   186,   187,    -1,   134,   147,   130,
     281,    -1,   134,   147,   130,    -1,   134,   147,   281,    -1,
     134,   147,    80,   281,    -1,   101,   105,   280,    -1,    45,
     105,   280,    -1,   148,   105,   280,    -1,   123,   102,   280,
      -1,   135,   105,   280,    -1,   149,   281,    -1,   190,    73,
      -1,   189,    73,    -1,   243,    -1,   189,   139,   243,    -1,
     133,   281,   191,   198,    -1,    -1,    66,   281,    -1,    82,
      75,   136,    73,    -1,    82,   194,   193,    -1,    -1,    73,
      -1,   195,    -1,   194,   195,    -1,    78,   123,    89,   262,
      -1,   123,   150,   262,    -1,   123,    89,   262,    -1,   116,
      75,   136,   262,    -1,   116,   100,   136,   262,    -1,    43,
      86,   115,   197,   262,    -1,    33,    86,   115,   197,   262,
      -1,   109,   118,   289,     4,   289,    52,    -1,   109,   118,
     289,    52,    -1,   109,    -1,   196,    -1,    97,    -1,    -1,
     199,    -1,    -1,   119,   200,   204,    -1,   120,   204,    -1,
      50,    -1,   114,    -1,   242,    -1,    97,    -1,    -1,   119,
     203,   204,    -1,   205,    -1,   204,     4,   205,    -1,   206,
     207,    -1,    97,    -1,   240,    -1,    -1,    37,    -1,    67,
      -1,    88,   220,    -1,    87,   210,    -1,   254,    -1,   210,
       4,   254,    -1,     9,   220,    -1,    84,   213,    -1,   215,
      -1,   213,     4,   215,    -1,   213,     4,   121,   215,    -1,
     213,     4,   121,   117,   213,    51,    -1,   213,    56,   214,
     116,   220,    -1,   213,    55,   214,   116,   220,    -1,   213,
      -1,   117,   213,    51,    -1,   236,    -1,   236,   241,    -1,
     212,   217,   218,   219,    -1,    -1,   211,    -1,    -1,   209,
      -1,    -1,   208,    -1,   221,    -1,   220,    10,   221,    -1,
     222,    -1,   221,    11,   222,    -1,   223,    -1,    13,   223,
      -1,   234,    -1,   117,   220,    51,    -1,    76,   250,    -1,
     111,   250,    -1,   256,   233,   226,   250,    -1,   250,   233,
     256,    -1,   227,    -1,   228,    -1,    35,    -1,   143,    -1,
      36,    -1,   256,    92,   117,   230,    51,    -1,   256,    92,
     250,    -1,   256,   112,   117,   230,    51,    -1,   256,   112,
     250,    -1,   261,    -1,   230,     4,   261,    -1,    -1,    13,
      -1,   256,   231,    14,    -1,   256,   231,    15,    -1,   256,
     233,   256,    -1,   256,   233,   250,    -1,   256,   231,    44,
     256,    11,   256,    -1,    18,    -1,    16,    -1,    17,    -1,
      20,    -1,    22,    -1,    25,    -1,    23,    -1,    26,    -1,
      24,    -1,    19,    -1,    21,    -1,   232,    -1,   229,    -1,
     225,    -1,   224,    -1,    -1,    35,    -1,    68,    -1,   152,
      -1,    50,    -1,   238,    -1,   237,    53,   238,    -1,    50,
      71,   238,    -1,   282,    -1,   282,    -1,    -1,   118,    97,
      52,    -1,   118,    97,     4,    97,    52,    -1,   282,   239,
      -1,   236,    71,   282,   239,    -1,   236,    71,    30,    -1,
     282,    -1,   113,    -1,    71,    97,    -1,    -1,   138,   244,
     251,   252,   216,   247,    -1,   246,    -1,   138,   251,   252,
     216,   247,    -1,    -1,   151,   235,   245,    -1,   202,    -1,
      96,   145,   249,   248,    -1,   202,    96,   145,   249,   248,
      -1,    -1,   164,    -1,   282,    -1,   117,   138,   251,   252,
     216,    51,    -1,    -1,    35,    -1,    68,    -1,   152,    -1,
     253,    -1,   252,     4,   253,    -1,   256,    -1,   256,   109,
      -1,   256,    40,   109,    -1,   256,    -1,   158,    -1,   156,
      -1,   153,    -1,   154,    -1,   155,    -1,   157,    -1,   256,
     257,    -1,   201,    -1,   282,    -1,   282,   118,   280,    52,
      -1,   282,   118,   280,     4,   280,    52,    -1,   282,    71,
     282,   118,   280,    52,    -1,   282,    71,   282,   118,   280,
       4,   280,    52,    -1,    70,   282,    -1,   282,    71,   282,
      -1,   282,    71,    30,    -1,    99,    -1,    98,    -1,   160,
      -1,    30,    -1,   117,   256,    51,    -1,    60,   117,   260,
      51,    -1,    63,   117,   260,    51,    -1,   108,   117,   260,
      51,    -1,   168,   117,   260,    51,    -1,   282,   117,   260,
      51,    -1,    42,   117,   235,   256,    51,    -1,   166,   117,
     235,   256,    51,    -1,   167,   117,   235,   256,    51,    -1,
      38,   117,   235,   256,    51,    -1,    57,   117,   235,   256,
      51,    -1,    29,   258,    -1,    31,   258,    -1,    32,   258,
      -1,   255,    -1,    30,   258,    -1,    28,   258,    -1,    27,
     258,    -1,   259,   256,    -1,    -1,    28,    -1,    27,    -1,
     256,    -1,   260,     4,   256,    -1,   201,    -1,   263,    -1,
     262,   263,    -1,   266,    -1,   268,    -1,   279,    -1,   270,
      -1,   273,    -1,   274,    -1,   278,    -1,   275,    -1,   277,
      -1,   264,    -1,   165,   262,    73,    -1,    47,   265,   117,
     292,    51,    -1,    60,    -1,   108,    -1,   168,    -1,    63,
      -1,   282,    -1,    81,   178,    18,   289,   147,   289,   267,
      69,   263,    -1,    -1,   144,   289,    -1,    91,   289,   146,
     263,   269,    -1,    -1,    72,   263,    -1,   103,   109,    18,
     272,    -1,   103,   109,   118,   289,    52,    18,   272,    -1,
     103,   109,   118,   289,     4,   289,    52,    18,   272,    -1,
      -1,   272,    -1,   289,    -1,   272,     4,   289,    -1,   110,
     280,   104,    -1,   127,   281,    -1,   129,   271,   276,    -1,
      -1,   139,    -1,   131,   281,    -1,   140,   280,   104,    -1,
     140,   147,   149,    -1,   163,   289,    69,   263,    -1,    97,
      -1,    50,    -1,   109,    -1,   283,    -1,    33,    -1,    37,
      -1,    34,    -1,    40,    -1,    43,    -1,    44,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    12,
      -1,     7,    -1,    54,    -1,    16,    -1,    59,    -1,    62,
      -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,    69,
      -1,    72,    -1,    74,    -1,    75,    -1,    77,    -1,    78,
      -1,    79,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    85,    -1,    86,    -1,    89,    -1,    90,    -1,    91,
      -1,    92,    -1,    93,    -1,   100,    -1,   101,    -1,   102,
      -1,   103,    -1,    24,    -1,   104,    -1,   105,    -1,   106,
      -1,   107,    -1,   110,    -1,   115,    -1,   122,    -1,   123,
      -1,   126,    -1,   127,    -1,    32,    -1,   130,    -1,   132,
      -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,   140,    -1,   141,    -1,   142,    -1,     6,    -1,   144,
      -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,    58,
      -1,   150,    -1,   159,    -1,   161,    -1,   162,    -1,   163,
      -1,   165,    -1,    -1,     9,   289,    -1,   287,   284,    -1,
     115,   288,    -1,    57,    -1,   128,    -1,    41,   286,    -1,
      58,   286,    -1,    42,   286,    -1,   167,   286,    -1,   166,
     286,    -1,    86,    57,    -1,    86,   128,    -1,    86,    41,
     286,    -1,    86,    58,   286,    -1,    86,    42,   286,    -1,
      86,   167,   286,    -1,    86,   166,   286,    -1,    27,   288,
      -1,   295,    -1,    99,    -1,    98,    -1,   160,    -1,    60,
      -1,    61,    -1,    60,   117,   293,    51,    -1,   108,   117,
     293,    51,    -1,   168,   117,   293,    51,    -1,    63,   117,
     293,    51,    -1,   109,   117,   293,    51,    -1,   117,   289,
      51,    -1,   196,    -1,   288,   290,    -1,    27,   289,    -1,
     295,    -1,    99,    -1,    98,    -1,   160,    -1,    60,    -1,
      61,    -1,    60,   117,   293,    51,    -1,   108,   117,   293,
      51,    -1,   168,   117,   293,    51,    -1,    63,   117,   293,
      51,    -1,   109,   117,   293,    51,    -1,   117,   289,    51,
      -1,     7,   289,    -1,     8,   289,    -1,   196,    -1,   285,
      -1,   289,   291,    -1,    11,   288,    -1,    10,   288,    -1,
      29,   288,    -1,    32,   288,    -1,    31,   288,    -1,    30,
     288,    -1,    28,   288,    -1,    27,   288,    -1,    12,    -1,
      11,   289,    -1,    10,   289,    -1,    29,   289,    -1,    32,
     289,    -1,    31,   289,    -1,    30,   289,    -1,    28,   289,
      -1,    27,   289,    -1,     5,   289,    -1,    18,   289,    -1,
      16,   289,    -1,    17,   289,    -1,    20,   289,    -1,    22,
     289,    -1,    25,   289,    -1,    23,   289,    -1,    26,   289,
      -1,    24,   289,    -1,    19,   289,    -1,    21,   289,    -1,
       6,    -1,    14,    -1,    15,    -1,    12,    -1,   294,    -1,
     293,    -1,   289,    -1,   293,     4,   289,    -1,    -1,    50,
      -1,   114,    -1,   242,    -1,    97,    -1
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
     414,   418,   422,   426,   430,   433,   436,   443,   453,   463,
     478,   482,   490,   490,   493,   493,   496,   506,   509,   510,
     511,   516,   516,   520,   521,   526,   532,   537,   546,   547,
     548,   553,   559,   564,   565,   571,   576,   580,   581,   584,
     587,   590,   593,   598,   599,   603,   604,   614,   625,   626,
     629,   630,   633,   634,   639,   640,   646,   647,   652,   653,
     658,   659,   665,   666,   671,   673,   680,   681,   684,   688,
     689,   711,   713,   715,   717,   723,   724,   728,   729,   734,
     736,   738,   740,   742,   748,   749,   750,   751,   752,   753,
     754,   755,   756,   757,   758,   763,   764,   765,   766,   768,
     769,   770,   771,   782,   783,   784,   785,   791,   795,   799,
     800,   801,   804,   805,   806,   812,   817,   817,   823,   823,
     832,   835,   842,   843,   846,   847,   851,   859,   859,   863,
     869,   873,   874,   875,   876,   880,   881,   885,   888,   892,
     899,   903,   904,   905,   906,   907,   908,   912,   913,   914,
     915,   916,   917,   918,   919,   923,   925,   927,   928,   929,
     930,   931,   932,   933,   934,   935,   936,   937,   939,   941,
     943,   945,   950,   951,   952,   953,   954,   955,   956,   959,
     962,   963,   964,   968,   968,   975,   987,   992,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1024,
    1035,  1036,  1037,  1038,  1039,  1042,  1052,  1053,  1057,  1065,
    1068,  1073,  1084,  1095,  1108,  1112,  1115,  1115,  1127,  1133,
    1140,  1148,  1148,  1151,  1157,  1162,  1169,  1178,  1181,  1185,
    1186,  1191,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,
    1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,
    1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,
    1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1239,  1240,
    1241,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,
    1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,
    1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1277,
    1280,  1287,  1296,  1300,  1306,  1312,  1318,  1324,  1330,  1336,
    1343,  1349,  1355,  1361,  1367,  1373,  1379,  1389,  1407,  1409,
    1413,  1417,  1421,  1430,  1440,  1447,  1453,  1459,  1466,  1472,
    1473,  1478,  1500,  1518,  1520,  1524,  1528,  1532,  1541,  1551,
    1558,  1564,  1570,  1577,  1583,  1584,  1590,  1596,  1601,  1606,
    1628,  1636,  1643,  1651,  1658,  1667,  1674,  1683,  1690,  1699,
    1707,  1714,  1722,  1729,  1738,  1745,  1754,  1761,  1769,  1775,
    1781,  1787,  1793,  1799,  1805,  1811,  1817,  1823,  1829,  1837,
    1844,  1850,  1858,  1868,  1879,  1886,  1893,  1902,  1908,  1912,
    1916,  1920
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
  "CLOSE_SQUARE", "COLON", "COMMANDS", "INNER_JOIN", "LEFT_JOIN", "COUNT",
  "TOTAL", "DATABASE", "DATE", "TIME", "DATETIME", "DAY", "DECIMAL",
  "DEFINE", "DELIMITER", "DESC", "DISTINCT", "DO", "DOLLAR", "DOT", "ELSE",
  "END", "ESCAPE", "EVERY", "EXISTS", "EXTERNAL", "FIRST", "FLOAT", "PIPE",
  "FOR", "FORMAT", "FRACTION", "FROM", "FUNCTION", "GROUP", "GROUP_BY",
  "HAVING", "HEADER", "HOUR", "IF", "IN", "INPUT", "INTEGER", "INTERVAL",
  "INTO", "INTVAL", "KW_FALSE", "KW_TRUE", "LAST", "LEFT", "LENGTH", "LET",
  "LINES", "MARGIN", "MINUTE", "MONEY", "MONTH", "NAMED", "NEED",
  "NOT_EXISTS", "NOT_IN", "NUMBER_VALUE", "NUMERIC", "KW_OF", "ON",
  "OPEN_BRACKET", "OPEN_SQUARE", "ORDER_BY", "ORDER_EXTERNAL_BY", "OUTER",
  "OUTPUT", "PAGE", "PAGE_HEADER", "PAGE_TRAILER", "PARAM", "PAUSE",
  "PERCENT", "PRINT", "PRINTER", "PRINT_FILE", "PROMPT", "READ", "REPORT",
  "RIGHT", "ROW", "SECOND", "SELECT", "SEMICOLON", "SKIP", "SMALLFLOAT",
  "SMALLINT", "SOME", "STEP", "TEMP", "THEN", "TO", "TOP", "TOP_OF_PAGE",
  "TRAILER", "UNION", "UNIQUE", "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE",
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
  "order_by_clause_read", "$@1", "literal", "order_by_clause", "$@2",
  "sort_specification_list", "sort_specification", "sort_spec",
  "op_asc_desc", "having_clause", "group_by_clause",
  "column_specification_list", "where_clause", "from_clause",
  "table_reference_list", "op_bracket_table_reference_list", "tname",
  "table_expression", "op_where_clause", "op_group_by_clause",
  "op_having_clause", "search_condition", "boolean_term", "boolean_factor",
  "boolean_primary", "exists_predicate", "quantified_predicate",
  "quantifier", "all", "some", "in_predicate", "in_value_list", "op_not",
  "comparison_predicate", "comp_op_sql", "predicate", "op_all",
  "table_name", "db_name", "table_identifier", "col_arr", "column_name",
  "correlation_name", "real_number", "select_statement", "$@3",
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
     415,   416,   417,   418,   419,   420,   421,   422,   423
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   169,   170,   171,   171,   172,   172,   173,   174,   174,
     175,   175,   175,   175,   176,   177,   177,   178,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   180,   180,   181,   182,
     182,   183,   184,   184,   185,   186,   186,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   188,   188,   189,
     189,   190,   191,   191,   192,   192,   193,   193,   194,   194,
     195,   195,   195,   195,   195,   195,   195,   196,   196,   196,
     197,   197,   198,   198,   200,   199,   199,   201,   201,   201,
     201,   203,   202,   204,   204,   205,   206,   206,   207,   207,
     207,   208,   209,   210,   210,   211,   212,   213,   213,   213,
     213,   213,   213,   214,   214,   215,   215,   216,   217,   217,
     218,   218,   219,   219,   220,   220,   221,   221,   222,   222,
     223,   223,   224,   224,   225,   225,   226,   226,   227,   228,
     228,   229,   229,   229,   229,   230,   230,   231,   231,   232,
     232,   232,   232,   232,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   234,   234,   234,   234,   235,
     235,   235,   235,   236,   236,   236,   236,   237,   238,   239,
     239,   239,   240,   240,   240,   241,   242,   242,   244,   243,
     245,   246,   247,   247,   247,   247,   247,   248,   248,   249,
     250,   251,   251,   251,   251,   252,   252,   253,   253,   253,
     254,   255,   255,   255,   255,   255,   255,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   257,   257,   257,   257,   257,   257,   257,   258,
     259,   259,   259,   260,   260,   261,   262,   262,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   264,
     265,   265,   265,   265,   265,   266,   267,   267,   268,   269,
     269,   270,   270,   270,   271,   271,   272,   272,   273,   274,
     275,   276,   276,   277,   278,   278,   279,   280,   281,   282,
     282,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   284,
     284,   285,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   292,   292,   293,   293,   294,   295,   295,
     295,   295
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
       1,     2,     2,     1,     3,     2,     2,     1,     3,     4,
       6,     5,     5,     1,     3,     1,     2,     4,     0,     1,
       0,     1,     0,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     2,     2,     4,     3,     1,     1,     1,     1,
       1,     5,     3,     5,     3,     1,     3,     0,     1,     3,
       3,     3,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     0,
       3,     5,     2,     4,     3,     1,     1,     2,     0,     6,
       1,     5,     0,     3,     1,     4,     5,     0,     1,     1,
       6,     0,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       4,     6,     6,     8,     2,     3,     3,     1,     1,     1,
       1,     3,     4,     4,     4,     4,     4,     5,     5,     5,
       5,     5,     2,     2,     2,     1,     2,     2,     2,     2,
       0,     1,     1,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       1,     1,     1,     1,     1,     9,     0,     2,     5,     0,
       2,     4,     7,     9,     0,     1,     1,     3,     3,     2,
       3,     0,     1,     2,     3,     3,     4,     1,     1,     1,
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
     297,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,   188,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,    56,    44,    46,    62,   201,
       0,     2,    58,     0,    57,    16,     0,     0,     0,     0,
       0,     0,    52,    51,    54,     0,    48,    49,    55,    53,
       0,    82,   202,   203,   204,     0,     0,     0,     0,     0,
       0,     0,    66,    68,    60,    21,     0,    34,     0,    31,
      23,    12,    41,    50,    47,    63,    84,     0,    61,    83,
     366,   313,   312,   315,   344,   230,   355,   301,   303,   302,
       0,   304,     0,   305,   306,   307,   308,   309,   310,   311,
      87,   314,     0,   372,   316,     0,   317,     0,   318,   319,
     320,   321,   322,     0,     0,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,    90,   228,   227,   340,   341,   342,   343,   345,
     346,   347,   348,     0,   299,   349,   186,    88,   350,     0,
     351,   352,   353,   354,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   367,   368,   369,   370,   371,   373,
     374,   229,   375,   376,   377,   378,     0,     0,     0,   218,
      89,     0,   205,   207,   219,   300,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    65,    69,     0,     0,     0,
     173,    96,    86,    93,    98,     0,     0,   174,    97,   179,
     169,   169,   169,     0,     0,   224,   187,     0,     0,   169,
     169,     0,     0,     0,   118,   192,   250,   250,   250,   250,
     250,   250,     0,   208,   213,   214,   215,   212,   216,   211,
     245,   217,     0,     0,     0,     0,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,     0,     0,
       0,     0,    72,   256,   267,   258,   259,   261,   262,   263,
     265,   266,   264,   260,    71,    35,    32,    85,     0,     0,
      99,   100,    95,     0,     0,     0,   182,   170,   171,   172,
       0,     0,     0,   253,     0,     0,     0,   231,     0,     0,
       0,   206,   106,   107,   115,   178,     0,   119,   120,     0,
      91,   169,   194,   189,   252,   251,   248,     0,   247,   242,
     246,   243,   244,   209,   226,   225,     0,     0,    81,    79,
      80,     0,     0,    70,    73,    74,   270,   273,   271,   272,
       0,   274,     0,     0,     0,     0,     0,     0,   468,   383,
       0,   417,   418,     0,     0,   471,   415,   414,     0,    79,
     469,     0,   384,   416,     0,     0,     0,   427,   470,   428,
     379,     0,   413,     0,     0,   289,   291,   285,   286,   293,
       0,     0,     0,     0,   257,   176,   178,    94,   184,   179,
     175,     0,     0,     0,     0,     0,   232,   233,   234,     0,
       0,   235,     0,     0,     0,   116,   185,     0,     0,     0,
       0,   105,   124,   126,   128,   168,   167,   166,   165,   130,
       0,   147,     0,   121,   122,     0,     0,     0,     0,   249,
       0,   236,     0,   220,     0,    76,    75,   467,     0,   425,
     426,   412,     0,   385,   387,   386,     0,     0,     0,     0,
     390,     0,   391,     0,     0,     0,     0,     0,   389,   388,
       0,     0,   381,     0,   459,     0,     0,   462,   460,   461,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   429,     0,
       0,   288,   292,   290,     0,   295,   294,     0,   268,   183,
       0,   180,   240,   237,   241,   254,   238,   239,     0,   108,
       0,   113,     0,     0,   129,     0,   132,   133,   201,     0,
     147,     0,     0,   155,   156,   154,   163,   157,   164,   158,
     160,   162,   159,   161,     0,   148,     0,     0,     0,     0,
     102,   103,   210,     0,   123,   117,   197,   199,    92,   201,
     193,   190,     0,     0,     0,     0,   465,     0,   464,   463,
       0,     0,   402,   403,     0,   400,   399,     0,    79,     0,
     401,     0,   410,   382,   398,     0,     0,   392,   394,   393,
     396,   395,     0,     0,   424,     0,   380,   447,   440,   439,
     449,   450,   448,   457,   451,   458,   452,   454,   456,   453,
     455,   446,   445,   441,   444,   443,   442,   279,   281,     0,
     287,   296,     0,     0,   109,     0,     0,     0,     0,   131,
     125,   127,   135,     0,   142,     0,   144,   149,   150,     0,
     138,   140,     0,   139,     0,   136,   137,   152,   151,     0,
     101,   198,   195,     0,   197,     0,   222,   221,     0,    78,
     269,     0,     0,   397,     0,     0,     0,     0,     0,     0,
       0,     0,   438,     0,     0,     0,     0,     0,     0,   411,
     419,   422,   420,   423,   421,     0,   278,     0,     0,   181,
       0,   114,   112,   111,     0,   255,     0,   145,     0,     0,
     134,   104,     0,   196,     0,     0,   466,   276,     0,     0,
       0,     0,   409,     0,   431,   430,   437,   436,   432,   435,
     434,   433,   280,     0,     0,   110,     0,     0,   141,   143,
       0,   192,   223,    77,     0,     0,   404,   407,   405,   408,
     406,     0,   282,   200,   146,   153,   191,   277,     0,     0,
     275,   283
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   255,   122,   123,   427,   391,   138,
     139,   259,   239,   372,   486,   262,   263,   264,   342,   604,
     483,   600,   367,   284,   571,   572,   363,   285,   368,   484,
     605,   471,   472,   473,   474,   475,   476,   694,   695,   696,
     477,   746,   598,   478,   599,   479,   350,   364,   266,   267,
     346,   268,   465,   428,    70,    89,   610,   611,   373,   702,
     606,   480,   115,   241,   242,   601,   300,   481,   301,   376,
     377,   354,   747,   322,   323,   324,   400,   325,   785,   326,
     736,   327,   436,   437,   328,   329,   330,   553,   331,   332,
     333,    51,    85,   244,   245,   522,   429,   503,   430,   633,
     616,   729,   548,   617,   618,   619,   432
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -640
static const yytype_int16 yypact[] =
{
      68,    10,   145,    98,    75,    92,  -640,     8,   112,  -640,
    -640,  -640,   117,   144,   141,   117,     2,  -640,   140,   175,
    -640,  -640,   298,  3179,  -640,  -640,   208,  3179,  -640,  -640,
     231,   -31,  -640,   200,   -80,  -640,   117,   213,  -640,  -640,
     216,  -640,  -640,  -640,  -640,   249,  -640,  -640,   261,  -640,
    -640,   336,  -640,   117,  -640,  -640,   282,   288,   297,   254,
     302,   307,   352,    76,  -640,   352,  -640,   321,   -54,   358,
    -640,  3179,   208,   208,   208,   208,   117,   429,   208,   208,
     208,   -21,   208,   208,  -640,  -640,  -640,  -640,   370,   -30,
     228,  -640,  -640,   301,  -640,  -640,   390,    33,    57,   394,
    3179,   352,  -640,  -640,  -640,   352,   352,  -640,  -640,  -640,
     352,     6,  -640,  -640,  -640,  1441,   361,   362,   315,   341,
     -19,   -64,   357,  -640,  -640,  -640,   208,  -640,   208,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  1872,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
     348,  -640,   351,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   355,  -640,  -640,   364,  -640,   365,  -640,  -640,
    -640,  -640,  -640,  2908,   372,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,   368,  -640,  -640,  -640,  -640,  -640,  1441,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,   373,   374,   377,  -640,
    -640,    36,  -640,  2553,   148,  -640,   356,   363,   401,   386,
     340,   347,  1728,  1728,  -640,  -640,  -640,   426,   436,  1872,
     418,  -640,   491,  -640,   202,   425,   445,  -640,  -640,    17,
     -29,   -29,   -29,  1441,  1441,  -640,  -640,  1441,  1567,   -29,
     -29,  1441,  1441,  2464,   490,   -39,   115,   115,   115,   115,
     115,   115,   391,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  2612,  1441,   208,   107,   107,  -640,  1728,  1728,
    1728,  1604,   117,  1735,   392,   208,   352,  1735,   352,   -37,
    1735,  1728,  1728,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  1728,  -640,  -640,   491,  2908,  1872,
    -640,  -640,  -640,  2760,  2908,   405,  -640,  -640,  -640,  -640,
    1441,  1441,  1441,  1671,   179,   182,   204,  -640,  1441,  1441,
     219,  -640,    85,  -640,  2908,   452,   789,  -640,   420,   393,
    -640,   -29,   412,  -640,  -640,  -640,  -640,  1441,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   395,   260,    50,  -640,   400,
    -640,  1728,  1728,  1728,  1728,  1728,  -640,  -640,  -640,  -640,
     422,  -640,   525,  1735,  1735,  1735,   430,   430,  -640,  -640,
     430,   427,  -640,   432,    74,  -640,  -640,  -640,   433,    97,
    -640,  1735,  -640,  -640,   430,   430,   437,  -640,  -640,  -640,
     537,  3138,  -640,    -1,   444,  -640,   414,   551,  3590,  -640,
     409,   455,  3282,  1727,  -640,  -640,  -640,  -640,  -640,   446,
    -640,   126,  1603,  2907,  2975,  1441,  -640,  -640,  -640,  3191,
    3203,  -640,  2020,  2168,  2168,  -640,  -640,  1115,   448,   448,
     626,   556,   558,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    3076,  3095,  1441,  -640,   479,  2908,  1872,   434,   428,  1671,
     208,  -640,   208,  -640,  1735,  1728,  1728,  1735,  1735,  3590,
    3590,   353,   443,  -640,  -640,  -640,  1735,  1735,   430,   430,
    -640,   430,  -640,   430,   430,  1735,  1735,  3514,  -640,  -640,
    1735,  1735,  -640,  1735,  -640,  1735,  1735,  -640,  -640,  -640,
    1735,  1735,  1735,  1735,  1735,  1735,  1735,  1735,  1735,  1735,
    1735,  1735,  1735,  1735,  1735,  1735,  1735,  1728,  -640,  1735,
    1735,  -640,  -640,  -640,  1735,  -640,  -640,  1728,  -640,  -640,
     474,  -640,  -640,  -640,  -640,  1671,  -640,  -640,  2316,  -640,
    2464,    85,   459,   462,  -640,   441,  -640,  -640,   -30,   136,
    3059,   789,   789,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  1441,  -640,   463,   464,   183,   952,
     578,  -640,  1671,   789,  -640,  -640,   419,  -640,   491,   -30,
    -640,  -640,  2908,   180,   533,  3358,  3590,   535,   585,  -640,
     505,   443,   475,  -640,   476,  -640,  -640,   483,   181,  1735,
    -640,   485,  -640,   594,  -640,   280,   292,  -640,  -640,  -640,
    -640,  -640,   303,   306,  -640,   310,  3613,  3590,  3635,  3656,
    3299,  3299,  3299,  3299,  3299,  3299,  3299,  3299,  3299,  3299,
    3299,   353,   353,   277,   277,  -640,  -640,   524,   551,  3397,
    3590,  -640,   555,  2464,  -640,   191,   789,   789,  1441,  -640,
     558,  -640,  1671,   -35,  -640,   -35,  -640,  -640,  -640,  1441,
    -640,  -640,  1278,  -640,   448,  -640,  -640,  -640,  1671,  1441,
     556,  -640,  -640,  1441,   419,   208,  -640,  -640,  1735,  -640,
    -640,  1735,  1735,   366,  1735,  1735,  1735,  1735,  3552,  1735,
     443,   443,  -640,   443,   443,   443,   443,   443,   443,  -640,
    -640,  -640,  -640,  -640,  -640,  1728,  -640,  1735,   590,  -640,
     290,  -640,   556,   556,    36,  -640,   328,  -640,   335,   162,
    -640,  -640,    36,  -640,   557,  3436,  3590,  3174,   338,   343,
     354,   359,  -640,   360,   587,   431,   366,   366,   344,   344,
    -640,  -640,  -640,  3475,  1735,  -640,   559,     0,  -640,  -640,
    1441,   -39,  -640,  -640,  1735,   543,  -640,  -640,  -640,  -640,
    -640,   595,   551,  -640,  -640,  1671,  -640,  3590,  1728,  1735,
    -640,   551
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -640,  -640,  -640,  -640,  -640,  -640,   611,  -640,  -640,   -12,
      24,  -640,  -640,  -640,   597,  -640,  -640,  -640,   566,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,   508,  -271,   325,  -640,
    -640,  -640,  -639,  -640,  -640,  -258,   295,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -281,   171,  -450,  -600,  -640,  -640,
    -640,  -456,    55,    58,   170,  -640,  -640,  -640,  -640,  -640,
    -640,   -44,  -640,  -640,   163,  -640,  -111,  -130,  -640,  -275,
     195,  -640,  -640,  -115,   552,  -640,  -640,  -640,  -135,   -57,
      37,  -460,  -296,  -613,   369,   -51,  -640,  -102,  -640,    83,
    -640,    88,  -123,  -210,  -289,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -545,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,   -52,   -33,  -126,  -640,  -640,  -640,  -358,  -640,  -399,
    -117,  -640,  -640,  -640,  -424,  -640,  -447
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -179
static const yytype_int16 yytable[] =
{
     240,   337,   362,    27,   668,   112,   347,   265,   576,   577,
      12,   269,   569,   243,   579,   160,    12,   549,     4,    92,
      96,    97,    98,    99,    71,   252,   102,   103,   104,    84,
     108,   109,    88,   444,   390,   390,   174,   126,   113,   348,
     282,    77,    54,   334,   745,   444,   745,   275,   107,   504,
     160,    52,   505,    65,   492,   634,   250,   369,    66,   105,
      50,   128,   192,   445,   100,   744,   518,   519,   132,   450,
    -177,   174,   133,   134,   257,    28,   258,   135,   206,   207,
     370,   251,   635,   636,   127,    93,   253,    13,  -178,   462,
     752,   642,   643,    13,   240,    95,   645,   192,   393,   394,
     395,    30,   493,   578,   444,   444,   444,   278,   129,   106,
     440,   443,   371,   206,   207,   508,   509,   550,   674,     5,
     283,    56,   114,   349,   131,   136,   137,     1,    14,   265,
     560,   510,   511,   269,    14,   345,   684,   686,   745,   697,
     463,   464,   374,   375,   776,     6,   581,   700,    10,    86,
     637,   638,   781,   639,   444,   640,   641,   365,   240,   240,
     351,   352,   240,     7,    15,    11,   240,   240,   358,   359,
      15,   353,   353,   780,   634,   353,   385,    57,   561,   353,
     243,   495,   496,   455,   705,   401,   455,   679,   240,   286,
     287,   288,   289,   290,   291,   462,   431,   687,   688,    58,
     438,   353,   512,   442,   388,    18,   444,   444,   455,   265,
      59,    60,   446,   269,   516,   494,   389,   449,   446,   302,
     742,   743,   713,   455,    61,    62,    21,   689,   608,   792,
     456,   632,   706,   457,   750,   240,   240,   240,   466,   340,
     513,   514,   741,   240,   240,    56,   463,   464,   452,   453,
     454,   240,   387,    24,   801,   458,   459,   460,   667,    26,
     487,   116,   240,   434,   455,   303,   304,   441,   671,   341,
     461,   117,    30,   634,   634,   489,   634,   634,   634,   634,
     634,   634,   678,   435,   711,   439,   499,   500,   501,   675,
     758,   759,   760,   761,   462,   763,   711,    33,   717,   494,
     402,    57,    36,   118,   517,    50,   119,   711,   545,   546,
     711,   491,    53,   703,   711,   294,   295,   296,   297,   298,
     299,   764,   765,    58,   766,   767,   768,   769,   770,   771,
      72,   730,   777,    73,    59,    60,   365,   365,   365,   777,
     240,   775,   711,   731,   120,   463,   464,   711,    61,    62,
     632,   121,   240,   565,   732,   240,   265,   733,   711,   607,
     269,   734,   355,   711,   711,   356,    74,   240,   580,   360,
     378,   379,   380,   381,   382,   727,   728,   615,    75,   778,
     602,   620,   543,   544,   545,   546,   779,    78,    76,   786,
     116,   386,   740,    79,   787,   725,   726,   727,   728,    80,
     117,    81,    84,    90,   646,   788,   647,    82,   648,   649,
     789,   790,    83,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     254,    94,   438,   669,   101,   119,   110,   670,   613,    66,
     614,   125,   365,   722,   365,   130,   772,   246,   247,   632,
     632,   248,   632,   632,   632,   632,   632,   632,   723,   724,
     725,   726,   727,   728,   249,   270,   240,   240,   271,   276,
     621,   305,   272,   120,   307,   308,   309,   335,   306,   240,
     121,   273,   274,   310,   240,   277,   607,   336,   240,   338,
     279,   280,   682,   408,   281,   339,   343,   698,   344,   366,
     383,   433,   451,   622,   623,  -177,   624,   482,   488,   800,
     523,   524,   718,   490,   174,   525,   526,   527,   494,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   485,   497,
     415,   625,   626,   498,   506,   502,   521,   365,   551,   507,
     515,   627,   628,   552,   520,   554,   206,   420,   555,   556,
     629,   240,   240,   240,   345,   575,   581,   603,   240,   582,
     240,   672,   609,   612,   240,   676,   243,   240,   677,   578,
     683,   685,   699,   701,   240,   707,   710,   749,   240,   711,
     278,   755,   714,   715,   756,   757,   735,   602,   721,   722,
     716,   243,   719,   630,   720,   721,   722,   739,   774,   782,
     793,   631,   798,   799,   723,   724,   725,   726,   727,   728,
     773,   723,   724,   725,   726,   727,   728,    29,    55,    87,
     256,   392,   140,   141,   447,   573,   680,   574,   142,   467,
     681,   748,   143,   594,   559,   124,   796,   753,   751,   704,
     144,   361,   712,   754,   794,     0,   145,   438,   146,   147,
     148,     0,   240,   149,   150,   240,   151,   797,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,   795,     0,
     161,     0,   438,   162,   163,   164,   165,     0,   166,   167,
     168,   169,   170,   171,     0,   172,   173,   174,   175,     0,
     176,   177,   468,   178,   179,   180,     0,   181,   182,   183,
     184,   185,   186,     0,     0,   187,   188,   189,   190,   191,
       0,     0,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   469,     0,   206,
     207,   208,     0,   470,     0,     0,     0,     0,   210,   211,
       0,     0,   212,   213,     0,     0,   214,     0,   215,   216,
     217,   218,   219,   220,   578,     0,   221,   222,   223,     0,
     224,   225,   226,   227,   228,     0,   229,     0,     0,     0,
       0,     0,     0,     0,     0,   230,   231,   232,   233,   234,
       0,   235,   236,   237,   238,   140,   141,     0,     0,     0,
       0,   142,   467,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,   145,
       0,   146,   147,   148,     0,     0,   149,   150,     0,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,     0,     0,   161,     0,     0,   162,   163,   164,   165,
       0,   166,   167,   168,   169,   170,   171,     0,   172,   173,
     174,   175,     0,   176,   177,   468,   178,   179,   180,     0,
     181,   182,   183,   184,   185,   186,     0,     0,   187,   188,
     189,   190,   191,     0,     0,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     469,     0,   206,   207,   208,     0,   470,     0,     0,     0,
       0,   210,   211,     0,     0,   212,   213,     0,     0,   214,
       0,   215,   216,   217,   218,   219,   220,     0,     0,   221,
     222,   223,     0,   224,   225,   226,   227,   228,     0,   229,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,   234,     0,   235,   236,   237,   238,   140,   141,
       0,     0,     0,     0,   142,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,   145,     0,   146,   147,   148,   690,   691,   149,
     150,     0,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,   161,     0,     0,   162,
     163,   164,   165,     0,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,     0,     0,   206,   207,   208,     0,   692,
       0,     0,     0,     0,   210,   211,     0,     0,   212,   213,
       0,     0,   214,     0,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,   693,   224,   225,   226,   227,
     228,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,   230,   231,   232,   233,   234,     0,   235,   236,   237,
     238,   140,   141,     0,     0,     0,     0,   142,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,   145,     0,   146,   147,   148,
       0,     0,   149,   150,     0,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,   161,
       0,     0,   162,   163,   164,   165,     0,   166,   167,   168,
     169,   170,   171,     0,   172,   173,   174,   175,     0,   176,
     177,   468,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   469,     0,   206,   207,
     208,     0,   470,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,   140,   141,     0,     0,     0,     0,
     142,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,   145,     0,
     146,   147,   148,     0,     0,   149,   150,     0,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,   161,     0,     0,   162,   163,   164,   165,     0,
     166,   167,   168,   169,   170,   171,     0,   172,   173,   174,
     175,     0,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,     0,
       0,   206,   207,   208,     0,   209,     0,     0,     0,     0,
     210,   211,     0,     0,   212,   213,     0,     0,   214,     0,
     215,   216,   217,   218,   219,   220,   578,     0,   221,   222,
     223,     0,   224,   225,   226,   227,   228,     0,   229,     0,
       0,     0,     0,     0,     0,     0,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,   140,   141,     0,
       0,     0,     0,   142,     0,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,   145,     0,   146,   147,   148,     0,     0,   149,   150,
       0,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,     0,     0,     0,   161,     0,     0,   162,   163,
     164,   165,     0,   166,   167,   168,   169,   170,   171,     0,
     172,   173,   174,   175,     0,   176,   177,     0,   178,   179,
     180,     0,   181,   182,   183,   184,   185,   186,     0,     0,
     187,   188,   189,   190,   191,     0,     0,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,     0,     0,   206,   207,   208,     0,   209,     0,
       0,     0,     0,   210,   211,     0,     0,   212,   213,     0,
       0,   214,     0,   215,   216,   217,   218,   219,   220,     0,
       0,   221,   222,   223,     0,   224,   225,   226,   227,   228,
       0,   229,     0,     0,   286,   287,   288,   289,   290,   291,
     230,   231,   232,   233,   234,     0,   235,   236,   237,   238,
     140,   141,     0,     0,     0,     0,   142,     0,   357,     0,
     143,     0,     0,     0,     0,     0,     0,     0,   144,     0,
     286,   287,   288,   289,   290,   291,   146,   147,   148,     0,
       0,   149,     0,     0,   151,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   562,     0,     0,     0,   161,     0,
       0,     0,   163,   164,   396,     0,   166,   397,   168,   169,
     170,   171,     0,   172,     0,     0,   175,     0,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,     0,     0,   187,   188,   189,   190,   191,   286,   287,
     288,   289,   290,   291,   195,   196,   197,   198,   199,   200,
     201,   202,   398,   204,   205,     0,     0,     0,     0,   208,
     294,   295,   296,   297,   298,   299,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,   403,   404,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,   294,   295,   296,   297,
     298,   299,   405,   230,     0,   232,   233,   234,     0,   235,
       0,     0,   399,     0,   311,   311,   406,   407,     0,     0,
       0,     0,     0,     0,     0,   408,     0,     0,     0,     0,
       0,     0,   409,   410,     0,   411,   412,     0,   413,     0,
     558,     0,     0,     0,     0,     0,   174,     0,   312,   312,
       0,     0,     0,     0,     0,     0,     0,     0,   313,   313,
       0,   414,     0,     0,   294,   295,   296,   297,   298,   299,
     314,   314,   415,   416,   417,     0,     0,   315,   315,     0,
       0,     0,     0,   418,   419,     0,     0,     0,   206,   420,
       0,     0,   421,     0,   316,   316,   317,   317,   318,   318,
       0,     0,     0,   422,     0,     0,     0,   319,   319,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   140,   141,
       0,     0,     0,     0,   142,     0,     0,     0,   143,     0,
     320,   320,   321,   321,     0,   423,   144,     0,     0,     0,
       0,   424,   425,   426,   146,   147,   148,     0,     0,   149,
       0,     0,   151,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   260,     0,     0,     0,   161,     0,     0,     0,
     163,   164,     0,     0,   166,     0,   168,   169,   170,   171,
       0,   172,     0,     0,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   261,
       0,     0,   195,   196,   197,   198,   199,   200,   201,   202,
       0,   204,   205,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,   210,   211,     0,     0,   212,   213,
       0,     0,   214,     0,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,     0,   224,   225,   226,   227,
     228,     0,   229,     0,     0,     0,   140,   141,     0,     0,
       0,   230,   142,   232,   233,   234,   143,   235,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,   149,     0,     0,
     151,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     260,     0,     0,     0,   161,     0,     0,     0,   163,   164,
       0,     0,   166,     0,   168,   169,   170,   171,     0,   172,
       0,     0,   175,     0,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,   202,     0,   204,
     205,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,   568,   210,   211,     0,     0,   212,   213,     0,     0,
     214,     0,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
     229,     0,     0,     0,   140,   141,     0,     0,     0,   230,
     142,   232,   233,   234,   143,   235,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,     0,     0,   149,     0,     0,   151,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   260,     0,
       0,     0,   161,     0,     0,     0,   163,   164,     0,     0,
     166,     0,   168,   169,   170,   171,     0,   172,     0,     0,
     175,     0,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,     0,     0,     0,   195,   196,
     197,   198,   199,   200,   201,   202,     0,   204,   205,     0,
       0,     0,     0,   208,     0,   570,     0,     0,     0,     0,
     210,   211,     0,     0,   212,   213,     0,     0,   214,     0,
     215,   216,   217,   218,   219,   220,     0,     0,   221,   222,
     223,     0,   224,   225,   226,   227,   228,     0,   229,     0,
       0,     0,   140,   141,     0,     0,     0,   230,   142,   232,
     233,   234,   143,   235,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,     0,     0,   149,     0,     0,   151,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   260,     0,     0,     0,
     161,     0,     0,     0,   163,   164,     0,     0,   166,     0,
     168,   169,   170,   171,     0,   172,     0,     0,   175,     0,
     176,   177,     0,   178,   179,   180,     0,   181,   182,   183,
     184,   185,   186,     0,     0,   187,   188,   189,   190,   191,
       0,     0,     0,     0,     0,     0,   195,   196,   197,   198,
     199,   200,   201,   202,     0,   204,   205,     0,     0,     0,
       0,   208,     0,   673,     0,     0,     0,     0,   210,   211,
       0,     0,   212,   213,     0,     0,   214,     0,   215,   216,
     217,   218,   219,   220,     0,     0,   221,   222,   223,     0,
     224,   225,   226,   227,   228,     0,   229,     0,     0,     0,
     140,   141,     0,     0,     0,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
       0,   149,     0,     0,   151,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   260,     0,     0,     0,   161,     0,
       0,     0,   163,   164,     0,     0,   166,     0,   168,   169,
     170,   171,     0,   172,     0,     0,   175,     0,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,     0,     0,   187,   188,   189,   190,   191,     0,     0,
       0,     0,     0,     0,   195,   196,   197,   198,   199,   200,
     201,   202,     0,   204,   205,     0,     0,     0,     0,   208,
     286,   287,   288,   289,   290,   291,   210,   211,     0,     0,
     212,   213,     0,   292,   214,     0,   215,   216,   217,   218,
     219,   220,     0,     0,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,     0,     0,   140,   141,
       0,     0,     0,   230,   142,   232,   233,   234,   143,   235,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,   384,     0,   146,   147,   148,     0,     0,   149,
       0,     0,   151,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   293,     0,     0,     0,   161,     0,     0,     0,
     163,   164,     0,     0,   166,     0,   168,   169,   170,   171,
       0,   172,     0,     0,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,   294,   295,   296,   297,
     298,   299,   195,   196,   197,   198,   199,   200,   201,   202,
       0,   204,   205,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,   210,   211,     0,     0,   212,   213,
       0,     0,   214,     0,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,     0,   224,   225,   226,   227,
     228,     0,   229,     0,     0,     0,   140,   141,     0,     0,
       0,   230,   142,   232,   233,   234,   143,   235,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
     448,     0,   146,   147,   148,     0,     0,   149,     0,     0,
     151,     0,     0,   153,   154,   155,   156,   157,   158,   159,
       0,     0,     0,     0,   161,     0,     0,     0,   163,   164,
       0,     0,   166,     0,   168,   169,   170,   171,     0,   172,
       0,     0,   175,     0,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,   202,     0,   204,
     205,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,   210,   211,     0,     0,   212,   213,     0,     0,
     214,     0,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
     229,     0,     0,     0,   140,   141,     0,     0,     0,   230,
     142,   232,   233,   234,   143,   235,     0,     0,     0,     0,
       0,     0,   144,     0,   286,   287,   288,   289,   290,   291,
     146,   147,   148,     0,     0,   149,     0,     0,   151,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   563,     0,
       0,     0,   161,     0,     0,     0,   163,   164,     0,     0,
     166,     0,   168,   169,   170,   171,     0,   172,     0,     0,
     175,     0,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,     0,     0,   187,   188,   189,
     190,   191,   286,   287,   288,   289,   290,   291,   195,   196,
     197,   198,   199,   200,   201,   202,     0,   204,   205,     0,
       0,     0,     0,   208,     0,     0,   564,     0,     0,     0,
     210,   211,     0,     0,   212,   213,     0,     0,   214,     0,
     215,   216,   217,   218,   219,   220,     0,     0,   221,   222,
     223,     0,   224,   225,   226,   227,   228,     0,   229,     0,
     294,   295,   296,   297,   298,   299,     0,   230,     0,   232,
     233,   234,   595,   235,     0,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   286,   287,   288,   289,
     290,   291,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,     0,     0,     0,   595,     0,
     357,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   286,   287,   288,   289,   290,   291,   294,   295,
     296,   297,   298,   299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   523,   524,     0,     0,     0,   525,   526,
     527,   596,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   597,     0,     0,     0,     0,     0,     0,     0,   523,
     524,     0,     0,     0,   525,   526,   527,   596,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   597,     0,     0,
       0,     0,   294,   295,   296,   297,   298,   299,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,    37,     0,
     286,   287,   288,   289,   290,   291,     0,     0,     0,    38,
       0,    39,   566,    40,     0,     0,     0,     0,   294,   295,
     296,   297,   298,   299,   567,     0,     0,     0,    41,     0,
       0,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   547,     0,    45,   523,   524,     0,
       0,     0,   525,   526,   527,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,     0,     0,     0,   784,     0,
      46,    47,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,   294,   295,   296,   297,   298,   299,
       0,   557,     0,     0,     0,     0,   294,   295,   296,   297,
     298,   299,   708,   523,   524,     0,     0,     0,   525,   526,
     527,     0,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   737,   523,   524,     0,     0,     0,   525,   526,   527,
     709,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   523,   524,     0,     0,     0,   525,   526,   527,   738,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     523,   524,     0,     0,     0,   525,   526,   527,   783,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   523,
     524,     0,     0,     0,   525,   526,   527,   791,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   523,   524,     0,
       0,     0,   525,   526,   527,   644,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   523,   524,     0,     0,     0,
     525,   526,   527,   762,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   525,   526,   527,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   526,   527,     0,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   527,     0,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546
};

static const yytype_int16 yycheck[] =
{
     115,   259,   283,    15,   549,    35,    35,   137,   468,   469,
       8,   137,   462,   115,   470,    50,     8,    18,     8,    73,
      72,    73,    74,    75,    36,    89,    78,    79,    80,    50,
      82,    83,    65,   322,   305,   306,    71,     4,    68,    68,
       4,    53,    73,   253,   683,   334,   685,   173,    81,   407,
      50,    27,   410,   133,     4,   502,    75,    96,   138,    80,
      97,     4,    97,   338,    76,   678,   424,   425,   101,   344,
      53,    71,   105,   106,   126,    73,   128,   110,   113,   114,
     119,   100,   506,   507,    51,   139,   150,    85,    71,     4,
     703,   515,   516,    85,   209,    71,   520,    97,   308,   309,
     310,   132,    52,   138,   393,   394,   395,   209,    51,   130,
     147,   321,   151,   113,   114,    41,    42,   118,   568,   109,
      84,    45,   152,   152,   100,   119,   120,    59,   126,   259,
       4,    57,    58,   259,   126,   118,   596,   597,   777,   599,
      55,    56,    27,    28,   744,     0,    10,   603,    73,    73,
     508,   509,   752,   511,   443,   513,   514,   283,   273,   274,
     271,   272,   277,    65,   162,    73,   281,   282,   279,   280,
     162,   273,   274,    11,   621,   277,   302,   101,    52,   281,
     282,   391,   392,     4,     4,   311,     4,    51,   303,    27,
      28,    29,    30,    31,    32,     4,   313,    14,    15,   123,
     317,   303,   128,   320,    97,    93,   495,   496,     4,   339,
     134,   135,   338,   339,   117,   118,   109,   343,   344,    71,
     676,   677,   621,     4,   148,   149,   109,    44,   486,   774,
      51,   502,    52,    51,   694,   350,   351,   352,   364,    37,
     166,   167,    51,   358,   359,    45,    55,    56,   350,   351,
     352,   366,   304,   109,   799,    51,   358,   359,   547,   118,
     371,    33,   377,   315,     4,   117,   118,   319,   557,    67,
      51,    43,   132,   720,   721,   377,   723,   724,   725,   726,
     727,   728,   578,   316,     4,   318,   403,   404,   405,   570,
     714,   715,   716,   717,     4,   719,     4,   122,   117,   118,
     312,   101,     4,    75,   421,    97,    78,     4,    31,    32,
       4,    51,    81,   609,     4,   153,   154,   155,   156,   157,
     158,   720,   721,   123,   723,   724,   725,   726,   727,   728,
     117,    51,     4,   117,   134,   135,   462,   463,   464,     4,
     455,    51,     4,    51,   116,    55,    56,     4,   148,   149,
     621,   123,   467,   455,    51,   470,   486,    51,     4,   485,
     486,    51,   274,     4,     4,   277,   117,   482,   470,   281,
     287,   288,   289,   290,   291,    31,    32,   494,   117,    51,
     482,   498,    29,    30,    31,    32,    51,   105,    52,    51,
      33,   303,   673,   105,    51,    29,    30,    31,    32,   102,
      43,   147,    50,    82,   521,    51,   523,   105,   525,   526,
      51,    51,   105,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
      73,    73,   549,   550,     5,    78,    66,   554,   490,   138,
     492,    51,   568,    12,   570,    51,   735,    86,    86,   720,
     721,   136,   723,   724,   725,   726,   727,   728,    27,    28,
      29,    30,    31,    32,   123,   117,   581,   582,   117,    97,
      27,   115,   117,   116,    73,    89,   136,    51,   115,   594,
     123,   117,   117,   136,   599,   117,   612,    51,   603,    71,
     117,   117,   594,    50,   117,     4,    71,   599,    53,     9,
     109,   109,    97,    60,    61,    53,    63,    87,    96,   798,
       5,     6,   629,   118,    71,    10,    11,    12,   118,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   145,   117,
      97,    98,    99,    18,   117,   115,     9,   673,   104,   117,
     117,   108,   109,   139,   117,     4,   113,   114,   149,   104,
     117,   676,   677,   678,   118,   117,    10,    88,   683,    11,
     685,    97,   138,   145,   689,   116,   678,   692,   116,   138,
     117,   117,     4,   164,   699,    52,    51,   689,   703,     4,
     692,   708,   117,   117,   711,   712,    72,   699,    11,    12,
     117,   703,   117,   160,    10,    11,    12,    52,    18,    52,
      51,   168,    69,    18,    27,    28,    29,    30,    31,    32,
     737,    27,    28,    29,    30,    31,    32,    16,    31,    63,
     122,   306,     6,     7,   339,   464,   581,   467,    12,    13,
     582,   685,    16,   480,   449,    93,   781,   704,   699,   612,
      24,   282,   147,   705,   777,    -1,    30,   774,    32,    33,
      34,    -1,   777,    37,    38,   780,    40,   784,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,   780,    -1,
      54,    -1,   799,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    -1,
      74,    75,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    -1,    -1,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,   113,
     114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,
      -1,    -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,
     134,   135,   136,   137,   138,    -1,   140,   141,   142,    -1,
     144,   145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
      -1,   165,   166,   167,   168,     6,     7,    -1,    -1,    -1,
      -1,    12,    13,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    -1,    -1,    37,    38,    -1,    40,
      -1,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    -1,    74,    75,    76,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    -1,    -1,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,
      -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,   130,
      -1,   132,   133,   134,   135,   136,   137,    -1,    -1,   140,
     141,   142,    -1,   144,   145,   146,   147,   148,    -1,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
     161,   162,   163,    -1,   165,   166,   167,   168,     6,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    -1,    74,    75,    -1,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    -1,
      -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,   123,    -1,    -1,   126,   127,
      -1,    -1,   130,    -1,   132,   133,   134,   135,   136,   137,
      -1,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,   167,
     168,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,   167,   168,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    -1,    -1,    37,    38,    -1,    40,    -1,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    -1,    74,    75,    -1,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    91,
      92,    93,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,
     122,   123,    -1,    -1,   126,   127,    -1,    -1,   130,    -1,
     132,   133,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,    -1,   144,   145,   146,   147,   148,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
     162,   163,    -1,   165,   166,   167,   168,     6,     7,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    -1,    -1,    37,    38,
      -1,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    -1,    74,    75,    -1,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,   113,   114,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,
      -1,   130,    -1,   132,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,    -1,   144,   145,   146,   147,   148,
      -1,   150,    -1,    -1,    27,    28,    29,    30,    31,    32,
     159,   160,   161,   162,   163,    -1,   165,   166,   167,   168,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    51,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      27,    28,    29,    30,    31,    32,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    51,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    58,    59,    60,    -1,    62,    63,    64,    65,
      66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,    75,
      -1,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    89,    90,    91,    92,    93,    27,    28,
      29,    30,    31,    32,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,   115,
     153,   154,   155,   156,   157,   158,   122,   123,    -1,    -1,
     126,   127,    -1,    -1,   130,    -1,   132,   133,   134,   135,
     136,   137,     7,     8,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,    -1,   150,    -1,   153,   154,   155,   156,
     157,   158,    27,   159,    -1,   161,   162,   163,    -1,   165,
      -1,    -1,   168,    -1,    47,    47,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,    60,    61,    -1,    63,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    71,    -1,    81,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    91,
      -1,    86,    -1,    -1,   153,   154,   155,   156,   157,   158,
     103,   103,    97,    98,    99,    -1,    -1,   110,   110,    -1,
      -1,    -1,    -1,   108,   109,    -1,    -1,    -1,   113,   114,
      -1,    -1,   117,    -1,   127,   127,   129,   129,   131,   131,
      -1,    -1,    -1,   128,    -1,    -1,    -1,   140,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,
     163,   163,   165,   165,    -1,   160,    24,    -1,    -1,    -1,
      -1,   166,   167,   168,    32,    33,    34,    -1,    -1,    37,
      -1,    -1,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      -1,    69,    -1,    -1,    72,    -1,    74,    75,    -1,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    -1,
      -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,   110,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,    -1,    -1,   126,   127,
      -1,    -1,   130,    -1,   132,   133,   134,   135,   136,   137,
      -1,    -1,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,    -1,   150,    -1,    -1,    -1,     6,     7,    -1,    -1,
      -1,   159,    12,   161,   162,   163,    16,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,
      -1,    -1,    62,    -1,    64,    65,    66,    67,    -1,    69,
      -1,    -1,    72,    -1,    74,    75,    -1,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,   159,
      12,   161,   162,   163,    16,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    67,    -1,    69,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    91,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,   115,    -1,   117,    -1,    -1,    -1,    -1,
     122,   123,    -1,    -1,   126,   127,    -1,    -1,   130,    -1,
     132,   133,   134,   135,   136,   137,    -1,    -1,   140,   141,
     142,    -1,   144,   145,   146,   147,   148,    -1,   150,    -1,
      -1,    -1,     6,     7,    -1,    -1,    -1,   159,    12,   161,
     162,   163,    16,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    58,    59,    -1,    -1,    62,    -1,
      64,    65,    66,    67,    -1,    69,    -1,    -1,    72,    -1,
      74,    75,    -1,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    -1,    -1,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,
      -1,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,
      -1,    -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,
     134,   135,   136,   137,    -1,    -1,   140,   141,   142,    -1,
     144,   145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,   159,    12,   161,   162,   163,
      16,   165,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    58,    59,    -1,    -1,    62,    -1,    64,    65,
      66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,    75,
      -1,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,   115,
      27,    28,    29,    30,    31,    32,   122,   123,    -1,    -1,
     126,   127,    -1,    40,   130,    -1,   132,   133,   134,   135,
     136,   137,    -1,    -1,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,    -1,   150,    -1,    -1,    -1,     6,     7,
      -1,    -1,    -1,   159,    12,   161,   162,   163,    16,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,    37,
      -1,    -1,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,   109,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      -1,    69,    -1,    -1,    72,    -1,    74,    75,    -1,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    -1,
      -1,    89,    90,    91,    92,    93,   153,   154,   155,   156,
     157,   158,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,   110,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,    -1,    -1,   126,   127,
      -1,    -1,   130,    -1,   132,   133,   134,   135,   136,   137,
      -1,    -1,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,    -1,   150,    -1,    -1,    -1,     6,     7,    -1,    -1,
      -1,   159,    12,   161,   162,   163,    16,   165,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,
      -1,    -1,    62,    -1,    64,    65,    66,    67,    -1,    69,
      -1,    -1,    72,    -1,    74,    75,    -1,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,   159,
      12,   161,   162,   163,    16,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    27,    28,    29,    30,    31,    32,
      32,    33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    51,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    67,    -1,    69,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    91,
      92,    93,    27,    28,    29,    30,    31,    32,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    51,    -1,    -1,    -1,
     122,   123,    -1,    -1,   126,   127,    -1,    -1,   130,    -1,
     132,   133,   134,   135,   136,   137,    -1,    -1,   140,   141,
     142,    -1,   144,   145,   146,   147,   148,    -1,   150,    -1,
     153,   154,   155,   156,   157,   158,    -1,   159,    -1,   161,
     162,   163,    13,   165,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      51,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    92,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    92,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   112,    -1,    -1,
      -1,    -1,   153,   154,   155,   156,   157,   158,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    49,    -1,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    60,
      -1,    62,    51,    64,    -1,    -1,    -1,    -1,   153,   154,
     155,   156,   157,   158,    51,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    -1,   107,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,   144,    -1,
     141,   142,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,   153,   154,   155,   156,   157,   158,
      -1,    69,    -1,    -1,    -1,    -1,   153,   154,   155,   156,
     157,   158,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,    -1,    -1,    -1,    10,    11,    12,
      52,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,    52,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,    -1,    -1,    -1,    10,    11,    12,    52,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    -1,    10,    11,    12,    52,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,
      -1,    -1,    10,    11,    12,    51,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,
      10,    11,    12,    51,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    59,   170,   171,     8,   109,     0,    65,   172,   173,
      73,    73,     8,    85,   126,   162,   174,   175,    93,   180,
     181,   109,   177,   178,   109,   176,   118,   178,    73,   175,
     132,   182,   183,   122,   184,   185,     4,    49,    60,    62,
      64,    79,    85,    94,    95,   107,   141,   142,   161,   179,
      97,   280,   179,    81,    73,   183,    45,   101,   123,   134,
     135,   148,   149,   186,   187,   133,   138,   188,   189,   190,
     243,   178,   117,   117,   117,   117,    52,   178,   105,   105,
     102,   147,   105,   105,    50,   281,    73,   187,   281,   244,
      82,   192,    73,   139,    73,   179,   280,   280,   280,   280,
     178,     5,   280,   280,   280,    80,   130,   281,   280,   280,
      66,   191,    35,    68,   152,   251,    33,    43,    75,    78,
     116,   123,   194,   195,   243,    51,     4,    51,     4,    51,
      51,   179,   281,   281,   281,   281,   119,   120,   198,   199,
       6,     7,    12,    16,    24,    30,    32,    33,    34,    37,
      38,    40,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    54,    57,    58,    59,    60,    62,    63,    64,    65,
      66,    67,    69,    70,    71,    72,    74,    75,    77,    78,
      79,    81,    82,    83,    84,    85,    86,    89,    90,    91,
      92,    93,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   113,   114,   115,   117,
     122,   123,   126,   127,   130,   132,   133,   134,   135,   136,
     137,   140,   141,   142,   144,   145,   146,   147,   148,   150,
     159,   160,   161,   162,   163,   165,   166,   167,   168,   201,
     242,   252,   253,   256,   282,   283,    86,    86,   136,   123,
      75,   100,    89,   150,    73,   193,   195,   280,   280,   200,
      50,    97,   204,   205,   206,   236,   237,   238,   240,   282,
     117,   117,   117,   117,   117,   282,    97,   117,   256,   117,
     117,   117,     4,    84,   212,   216,    27,    28,    29,    30,
      31,    32,    40,   109,   153,   154,   155,   156,   157,   158,
     255,   257,    71,   117,   118,   115,   115,    73,    89,   136,
     136,    47,    81,    91,   103,   110,   127,   129,   131,   140,
     163,   165,   262,   263,   264,   266,   268,   270,   273,   274,
     275,   277,   278,   279,   262,    51,    51,   204,    71,     4,
      37,    67,   207,    71,    53,   118,   239,    35,    68,   152,
     235,   235,   235,   256,   260,   260,   260,    51,   235,   235,
     260,   253,   213,   215,   236,   282,     9,   211,   217,    96,
     119,   151,   202,   247,    27,    28,   258,   259,   258,   258,
     258,   258,   258,   109,    30,   282,   260,   280,    97,   109,
     196,   197,   197,   262,   262,   262,    60,    63,   108,   168,
     265,   282,   178,     7,     8,    27,    41,    42,    50,    57,
      58,    60,    61,    63,    86,    97,    98,    99,   108,   109,
     114,   117,   128,   160,   166,   167,   168,   196,   242,   285,
     287,   289,   295,   109,   280,   281,   271,   272,   289,   281,
     147,   280,   289,   262,   263,   238,   282,   205,    30,   282,
     238,    97,   256,   256,   256,     4,    51,    51,    51,   256,
     256,    51,     4,    55,    56,   241,   282,    13,    76,   111,
     117,   220,   221,   222,   223,   224,   225,   229,   232,   234,
     250,   256,    87,   209,   218,   145,   203,   235,    96,   256,
     118,    51,     4,    52,   118,   262,   262,   117,    18,   289,
     289,   289,   115,   286,   286,   286,   117,   117,    41,    42,
      57,    58,   128,   166,   167,   117,   117,   289,   286,   286,
     117,     9,   284,     5,     6,    10,    11,    12,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   146,   291,    18,
     118,   104,   139,   276,     4,   149,   104,    69,    73,   239,
       4,    52,    51,    51,    51,   256,    51,    51,   121,   215,
     117,   213,   214,   214,   223,   117,   250,   250,   138,   220,
     256,    10,    11,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   233,    13,    92,   112,   231,   233,
     210,   254,   256,    88,   208,   219,   249,   282,   204,   138,
     245,   246,   145,   280,   280,   289,   289,   292,   293,   294,
     289,    27,    60,    61,    63,    98,    99,   108,   109,   117,
     160,   168,   196,   288,   295,   293,   293,   286,   286,   286,
     286,   286,   293,   293,    51,   293,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   263,   272,   289,
     289,   263,    97,   117,   215,   213,   116,   116,   251,    51,
     221,   222,   256,   117,   250,   117,   250,    14,    15,    44,
      35,    36,   117,   143,   226,   227,   228,   250,   256,     4,
     220,   164,   248,   251,   249,     4,    52,    52,     4,    52,
      51,     4,   147,   288,   117,   117,   117,   117,   289,   117,
      10,    11,    12,    27,    28,    29,    30,    31,    32,   290,
      51,    51,    51,    51,    51,    72,   269,     4,    52,    52,
     213,    51,   220,   220,   252,   201,   230,   261,   230,   256,
     250,   254,   252,   248,   280,   289,   289,   289,   293,   293,
     293,   293,    51,   293,   288,   288,   288,   288,   288,   288,
     288,   288,   263,   289,    18,    51,   216,     4,    51,    51,
      11,   216,    52,    52,   144,   267,    51,    51,    51,    51,
      51,    52,   272,    51,   261,   256,   247,   289,    69,    18,
     263,   272
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 248 "ace.yacc"
    {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 251 "ace.yacc"
    {
		this_report.dbname=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_init_connection ((yyvsp[(2) - (3)].str));
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 275 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 279 "ace.yacc"
    {
		ace_add_variable((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str),CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 282 "ace.yacc"
    {
		ace_add_variable((yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str),CAT_PARAM,atoi((yyvsp[(3) - (6)].str)),-1,0);
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 285 "ace.yacc"
    {
		add_function((yyvsp[(2) - (2)].str));
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 309 "ace.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 310 "ace.yacc"
    {strcpy((yyval.str),"CHAR");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 311 "ace.yacc"
    {SPRINTF1((yyval.str),"CHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 312 "ace.yacc"
    {strcpy((yyval.str),"VARCHAR");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 313 "ace.yacc"
    {SPRINTF1((yyval.str),"VARCHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 314 "ace.yacc"
    {strcpy((yyval.str),"DATE");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 315 "ace.yacc"
    {strcpy((yyval.str),"FLOAT");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 316 "ace.yacc"
    {strcpy((yyval.str),"SMALLFLOAT");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 317 "ace.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 318 "ace.yacc"
    {strcpy((yyval.str),"DATETIME");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 319 "ace.yacc"
    {strcpy((yyval.str),"INTERVAL");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 320 "ace.yacc"
    {strcpy((yyval.str),"MONEY");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 321 "ace.yacc"
    {SPRINTF1((yyval.str),"MONEY (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 322 "ace.yacc"
    {SPRINTF2((yyval.str),"MONEY (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 323 "ace.yacc"
    {strcpy((yyval.str),"DECIMAL");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 324 "ace.yacc"
    {SPRINTF1((yyval.str),"DECIMAL (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 325 "ace.yacc"
    {SPRINTF2((yyval.str),"DECIMAL (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 339 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes((yyvsp[(5) - (5)].str)),(yyvsp[(3) - (5)].str));
}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 354 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 355 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 356 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup((yyvsp[(3) - (3)].str)); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 357 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str)); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 358 "ace.yacc"
    {
		this_report.output.left_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 361 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 364 "ace.yacc"
    {
		this_report.output.top_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 367 "ace.yacc"
    {
		this_report.output.page_length=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 370 "ace.yacc"
    {
		this_report.output.right_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 373 "ace.yacc"
    {
		this_report.output.top_of_page=acl_strdup((yyvsp[(2) - (2)].str));
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 380 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 384 "ace.yacc"
    { add_select((yyvsp[(1) - (1)].str),temp_tab_name); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 385 "ace.yacc"
    { add_select((yyvsp[(3) - (3)].str),temp_tab_name); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 396 "ace.yacc"
    {
		struct acerep_commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,NULL,cmd);
	  }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 415 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 419 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 423 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 427 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 430 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 433 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 436 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 443 "ace.yacc"
    {
		(yyval.var_usage)=malloc(sizeof(struct acerep_var_usage));
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

/* Line 1455 of yacc.c  */
#line 453 "ace.yacc"
    {
		(yyval.var_usage)=malloc(sizeof(struct acerep_var_usage));
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

/* Line 1455 of yacc.c  */
#line 463 "ace.yacc"
    {
		
		(yyval.var_usage)=malloc(sizeof(struct acerep_var_usage));
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

/* Line 1455 of yacc.c  */
#line 478 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 482 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 490 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 493 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 493 "ace.yacc"
    {
	printf("speclist : %s ",(yyvsp[(3) - (3)].str));
	SPRINTF1((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str));}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 497 "ace.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 506 "ace.yacc"
    {
		SPRINTF1((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 516 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 516 "ace.yacc"
    { SPRINTF1((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str)); }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 521 "ace.yacc"
    {
SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 526 "ace.yacc"
    {
		if (strlen((yyvsp[(2) - (2)].str))) {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 532 "ace.yacc"
    {
		char buff[256];
		SPRINTF1(buff,"I%d",atoi((yyvsp[(1) - (1)].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 537 "ace.yacc"
    {
		char buff[256];
		SPRINTF1(buff,"C%s",(yyvsp[(1) - (1)].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 546 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 554 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 560 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 566 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 571 "ace.yacc"
    {SPRINTF1((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[(2) - (2)].str));}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 576 "ace.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 580 "ace.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 581 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 584 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s, OUTER %s",(yyvsp[(1) - (4)].str),(yyvsp[(4) - (4)].str));
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 587 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s, OUTER (%s)",(yyvsp[(1) - (6)].str),(yyvsp[(5) - (6)].str));
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 590 "ace.yacc"
    {
		SPRINTF3((yyval.str),"%s LEFT OUTER JOIN %s ON %s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 593 "ace.yacc"
    {
		SPRINTF3((yyval.str),"%s INNER JOIN %s ON %s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 598 "ace.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 599 "ace.yacc"
    {SPRINTF1((yyval.str),"(%s)",(yyvsp[(2) - (3)].str)); }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 604 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		ace_add_table((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 618 "ace.yacc"
    {
SPRINTF4((yyval.str),"%s %s %s %s",
(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),
(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 625 "ace.yacc"
    {strcpy((yyval.str),"\n0");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 629 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 633 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 640 "ace.yacc"
    {
			SPRINTF3((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 648 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 654 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 660 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 665 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 666 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 672 "ace.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 674 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 712 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 714 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 716 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 718 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 725 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 728 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 735 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 737 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 739 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 741 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 743 "ace.yacc"
    {SPRINTF6((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 757 "ace.yacc"
    {SPRINTF0((yyval.str),"<=");}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 758 "ace.yacc"
    {SPRINTF0((yyval.str),">=");}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 768 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 782 "ace.yacc"
    { SPRINTF1((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[(1) - (1)].str))); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 783 "ace.yacc"
    {SPRINTF0((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 784 "ace.yacc"
    { SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 785 "ace.yacc"
    { SPRINTF3((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[(1) - (3)].str)),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 795 "ace.yacc"
    {SPRINTF0((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 799 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 800 "ace.yacc"
    {SPRINTF1((yyval.str),"[%s]",(yyvsp[(2) - (3)].str));}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 801 "ace.yacc"
    {SPRINTF2((yyval.str),"[%s,%s]",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 804 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 805 "ace.yacc"
    { SPRINTF3((yyval.str),"%s.%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 806 "ace.yacc"
    { SPRINTF2((yyval.str),"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 817 "ace.yacc"
    {SPRINTF1((yyval.str),"0.%s",(yyvsp[(2) - (2)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 823 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 826 "ace.yacc"
    {SPRINTF5((yyval.str),"%s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));
}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 838 "ace.yacc"
    {SPRINTF5((yyval.str),"%s %s %s %s %s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str) );}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 842 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 843 "ace.yacc"
    {
       SPRINTF3((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
       }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 847 "ace.yacc"
    {
       SPRINTF2((yyval.str),"INTO TEMP %s%s ",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (4)].str));
}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 851 "ace.yacc"
    {
       SPRINTF3((yyval.str),"%s INTO TEMP %s%s ",(yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (5)].str));
}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 859 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 859 "ace.yacc"
    {strcpy((yyval.str)," WITH NO LOG");}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 870 "ace.yacc"
    {SPRINTF6((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 873 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 874 "ace.yacc"
    {SPRINTF0((yyval.str),"ALL");}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 875 "ace.yacc"
    {SPRINTF0((yyval.str),"DISTINCT");}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 876 "ace.yacc"
    {SPRINTF0((yyval.str),"DISTINCT");}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 881 "ace.yacc"
    { SPRINTF2((yyval.str)," %s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 885 "ace.yacc"
    {
			add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
		}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 888 "ace.yacc"
    {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_select_column((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 892 "ace.yacc"
    {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
			add_select_column((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 903 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS YEAR");}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 904 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS MONTH"); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 905 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS DAY);"); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 906 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS HOUR);"); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 907 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS MINUTE);"); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 908 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS SECOND);"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 912 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s", (yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 915 "ace.yacc"
    {SPRINTF2((yyval.str)," %s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 916 "ace.yacc"
    {SPRINTF3((yyval.str)," %s[%s,%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 917 "ace.yacc"
    {SPRINTF3((yyval.str)," %s.%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 918 "ace.yacc"
    {SPRINTF4((yyval.str)," %s.%s[%s,%s]",(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str));}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 919 "ace.yacc"
    {
			if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
			SPRINTF1((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
			}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 924 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 926 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 930 "ace.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 931 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 932 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 933 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 934 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 935 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 936 "ace.yacc"
    {SPRINTF2((yyval.str),"%s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 938 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 940 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 942 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 944 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 946 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 950 "ace.yacc"
    {SPRINTF1((yyval.str),"/%s",(yyvsp[(2) - (2)].str));}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 951 "ace.yacc"
    {SPRINTF1((yyval.str)," MOD %s",(yyvsp[(2) - (2)].str));}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 952 "ace.yacc"
    {SPRINTF1((yyval.str)," POW %s",(yyvsp[(2) - (2)].str));}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 953 "ace.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 954 "ace.yacc"
    {SPRINTF1((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 955 "ace.yacc"
    {SPRINTF1((yyval.str),"+%s",(yyvsp[(2) - (2)].str));}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 956 "ace.yacc"
    {SPRINTF1((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 959 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 962 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 963 "ace.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 964 "ace.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 969 "ace.yacc"
    {
	SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 987 "ace.yacc"
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct acerep_command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[(1) - (1)].cmd));
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 992 "ace.yacc"
    {
		COPY((yyval.commands),(yyvsp[(1) - (2)].commands));
		(yyval.commands).commands.commands_len++;
		(yyval.commands).commands.commands_val=realloc(
		(yyval.commands).commands.commands_val,
		(yyval.commands).commands.commands_len*sizeof(struct acerep_command));
		COPY((yyval.commands).commands.commands_val[ (yyval.commands).commands.commands_len-1 ],(yyvsp[(2) - (2)].cmd));
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1014 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).acerep_command_u.acerep_commands.commands.commands_val=(yyvsp[(2) - (3)].commands).commands.commands_val;
		(yyval.cmd).acerep_command_u.acerep_commands.commands.commands_len=(yyvsp[(2) - (3)].commands).commands.commands_len;
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1024 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).acerep_command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[(2) - (5)].str));
	
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(4) - (5)].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr);
}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1042 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_FOR;
		(yyval.cmd).acerep_command_u.cmd_for.varid=find_variable((yyvsp[(2) - (9)].str));
		COPY((yyval.cmd).acerep_command_u.cmd_for.start,(yyvsp[(4) - (9)].expr));
		COPY((yyval.cmd).acerep_command_u.cmd_for.finish,(yyvsp[(6) - (9)].expr));
		COPY((yyval.cmd).acerep_command_u.cmd_for.step,(yyvsp[(7) - (9)].expr));
		(yyval.cmd).acerep_command_u.cmd_for.command=(struct acerep_command *)DUP((yyvsp[(9) - (9)].cmd));
	}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1052 "ace.yacc"
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1053 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (2)].expr));}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1057 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_IF;
	COPY((yyval.cmd).acerep_command_u.cmd_if.condition,(yyvsp[(2) - (5)].expr));
	(yyval.cmd).acerep_command_u.cmd_if.command=(struct acerep_command *)DUP((yyvsp[(4) - (5)].cmd));
	(yyval.cmd).acerep_command_u.cmd_if.elsecommand=(struct acerep_command *)DUP((yyvsp[(5) - (5)].cmd));
}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1065 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).acerep_command_u.null=1;
	}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1068 "ace.yacc"
    { COPY((yyval.cmd),(yyvsp[(2) - (2)].cmd)); }
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1073 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (4)].str));
		(yyval.cmd).acerep_command_u.cmd_let.varid=v;
		(yyval.cmd).acerep_command_u.cmd_let.value=DUP((yyvsp[(4) - (4)].expr));
		(yyval.cmd).acerep_command_u.cmd_let.sub1=0;
		(yyval.cmd).acerep_command_u.cmd_let.sub2=0; 
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1084 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (7)].str));
		(yyval.cmd).acerep_command_u.cmd_let.varid=v;
		(yyval.cmd).acerep_command_u.cmd_let.value=DUP((yyvsp[(7) - (7)].expr));
		(yyval.cmd).acerep_command_u.cmd_let.sub1=DUP((yyvsp[(4) - (7)].expr)); 
		(yyval.cmd).acerep_command_u.cmd_let.sub2=0;
	}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1095 "ace.yacc"
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[(2) - (9)].str));
		(yyval.cmd).acerep_command_u.cmd_let.varid=v;
		(yyval.cmd).acerep_command_u.cmd_let.value=DUP((yyvsp[(9) - (9)].expr));
		(yyval.cmd).acerep_command_u.cmd_let.sub1=DUP((yyvsp[(4) - (9)].expr)); 
		(yyval.cmd).acerep_command_u.cmd_let.sub2=DUP((yyvsp[(6) - (9)].expr)); 
	}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1108 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1115 "ace.yacc"
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1127 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).acerep_command_u.cmd_need.nlines=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1133 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).acerep_command_u.cmd_pause.message=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1140 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).acerep_command_u.cmd_print.printnl=atoi((yyvsp[(3) - (3)].str));
	(yyval.cmd).acerep_command_u.cmd_print.print=(yyvsp[(2) - (3)].expr);
}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1148 "ace.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1148 "ace.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1151 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1157 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).acerep_command_u.cmd_skip.nlines=atoi((yyvsp[(2) - (3)].str));

	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1162 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).acerep_command_u.cmd_skip.nlines=-1;
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1169 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		COPY((yyval.cmd).acerep_command_u.cmd_while.condition,(yyvsp[(2) - (4)].expr));
		(yyval.cmd).acerep_command_u.cmd_while.command=(struct acerep_command *)DUP((yyvsp[(4) - (4)].cmd));
}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1277 "ace.yacc"
    {
			(yyval.exprptr)=0;
		}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1281 "ace.yacc"
    { 
			(yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); 
		}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1288 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (2)].agg_val));
		(yyval.agg_val).wexpr=(yyvsp[(2) - (2)].exprptr); 
		}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1296 "ace.yacc"
    { (yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); }
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1300 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1306 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1312 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1318 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1324 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1330 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1336 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1343 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1349 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1355 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1361 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1367 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1373 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1379 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1389 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1407 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1409 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1413 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1417 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1421 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1430 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1440 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1447 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1453 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1459 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1466 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1472 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1473 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1478 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1500 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1518 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1520 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1524 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1528 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1532 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1541 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1551 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1558 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1564 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1570 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1577 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1583 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1584 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1590 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1596 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1601 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1606 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1628 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 1636 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 1644 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1652 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1659 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1668 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1674 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 1683 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 1690 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1699 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1707 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1715 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 1723 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 1730 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 1739 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 1745 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 1754 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 1761 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 1769 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 1775 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 1781 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 1787 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 1793 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 1799 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 1805 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 1811 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 1817 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 1823 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 1829 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 1837 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_SPACES; 
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 1844 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 1850 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 1858 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 1868 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1879 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 1886 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1893 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 1902 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_NULL;
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 1908 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 1912 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 1916 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 1920 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;



/* Line 1455 of yacc.c  */
#line 5880 "y.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 1928 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

