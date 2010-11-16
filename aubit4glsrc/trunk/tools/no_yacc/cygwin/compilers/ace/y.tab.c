/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.3"

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
#line 150 "y.tab.c"

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
     YEAR = 423,
     KW_CURRENT = 424,
     KW_EXTEND = 425
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
#define KW_CURRENT 424
#define KW_EXTEND 425




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
#line 538 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 550 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYLAST   3889

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  129
/* YYNRULES -- Number of rules.  */
#define YYNRULES  490
/* YYNRULES -- Number of states.  */
#define YYNSTATES  837

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   425

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
     165,   166,   167,   168,   169,   170
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
     589,   590,   595,   601,   602,   606,   608,   609,   611,   613,
     620,   621,   623,   625,   627,   629,   633,   635,   638,   642,
     644,   646,   648,   650,   652,   654,   656,   659,   661,   663,
     668,   675,   682,   691,   694,   698,   702,   704,   706,   708,
     710,   715,   719,   724,   729,   734,   739,   744,   750,   756,
     762,   768,   774,   780,   786,   791,   793,   795,   797,   799,
     801,   803,   805,   807,   809,   811,   813,   815,   817,   819,
     824,   827,   830,   833,   835,   838,   841,   844,   847,   848,
     850,   852,   854,   858,   860,   863,   865,   868,   870,   872,
     874,   876,   878,   880,   882,   884,   886,   888,   892,   898,
     900,   902,   904,   906,   908,   918,   919,   922,   928,   929,
     932,   937,   945,   955,   956,   958,   960,   964,   968,   971,
     975,   976,   978,   981,   984,   988,   992,   997,   999,  1001,
    1003,  1005,  1007,  1009,  1011,  1013,  1015,  1017,  1019,  1021,
    1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,  1041,
    1043,  1045,  1047,  1049,  1051,  1053,  1055,  1057,  1059,  1061,
    1063,  1065,  1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,
    1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,
    1103,  1105,  1107,  1109,  1111,  1113,  1115,  1117,  1119,  1121,
    1123,  1125,  1127,  1129,  1131,  1133,  1135,  1137,  1139,  1141,
    1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,  1159,  1161,
    1162,  1165,  1168,  1171,  1173,  1175,  1178,  1181,  1184,  1187,
    1190,  1193,  1196,  1200,  1204,  1208,  1212,  1216,  1219,  1221,
    1223,  1225,  1227,  1229,  1231,  1236,  1241,  1246,  1251,  1256,
    1260,  1262,  1265,  1268,  1270,  1272,  1274,  1276,  1278,  1280,
    1285,  1290,  1295,  1300,  1305,  1309,  1312,  1315,  1317,  1319,
    1322,  1325,  1328,  1331,  1334,  1337,  1340,  1343,  1346,  1348,
    1351,  1354,  1357,  1360,  1363,  1366,  1369,  1372,  1375,  1378,
    1381,  1384,  1387,  1390,  1393,  1396,  1399,  1402,  1405,  1408,
    1410,  1412,  1414,  1416,  1417,  1419,  1421,  1425,  1427,  1429,
    1431
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     172,     0,    -1,   173,   174,   182,   186,   190,   194,    -1,
      59,     8,    73,    -1,    59,   109,    73,    -1,    -1,   175,
      -1,    65,   176,    73,    -1,   177,    -1,   176,   177,    -1,
       8,   179,    -1,   162,   180,   181,    -1,   126,   118,   285,
      52,   180,   181,    -1,    85,   178,    -1,   109,    -1,   180,
     181,    -1,   179,     4,   180,   181,    -1,   109,    -1,    85,
      -1,    94,    -1,    49,    -1,    49,   117,   285,    51,    -1,
     161,    -1,   161,   117,   285,    51,    -1,    60,    -1,    79,
      -1,   141,    -1,   142,    -1,    62,    -1,    95,    -1,   107,
      -1,   107,   117,   285,    51,    -1,   107,   117,   285,     4,
     285,    51,    -1,    64,    -1,    64,   117,   285,    51,    -1,
      64,   117,   285,     4,   285,    51,    -1,    -1,   183,    -1,
      93,   184,    73,    -1,   185,    -1,   184,   185,    -1,   132,
      81,   180,     5,   286,    -1,    -1,   187,    -1,   122,   188,
      73,    -1,   189,    -1,   188,   189,    -1,   134,   147,   130,
     286,    -1,   134,   147,   130,    -1,   134,   147,   286,    -1,
     134,   147,    80,   286,    -1,   101,   105,   285,    -1,    45,
     105,   285,    -1,   148,   105,   285,    -1,   123,   102,   285,
      -1,   135,   105,   285,    -1,   149,   286,    -1,   192,    73,
      -1,   191,    73,    -1,   245,    -1,   191,   139,   245,    -1,
     133,   286,   193,   200,    -1,    -1,    66,   286,    -1,    82,
      75,   136,    73,    -1,    82,   196,   195,    -1,    -1,    73,
      -1,   197,    -1,   196,   197,    -1,    78,   123,    89,   267,
      -1,   123,   150,   267,    -1,   123,    89,   267,    -1,   116,
      75,   136,   267,    -1,   116,   100,   136,   267,    -1,    43,
      86,   115,   199,   267,    -1,    33,    86,   115,   199,   267,
      -1,   109,   118,   294,     4,   294,    52,    -1,   109,   118,
     294,    52,    -1,   109,    -1,   198,    -1,    97,    -1,    -1,
     201,    -1,    -1,   119,   202,   206,    -1,   120,   206,    -1,
      50,    -1,   114,    -1,   244,    -1,    97,    -1,    -1,   119,
     205,   206,    -1,   207,    -1,   206,     4,   207,    -1,   208,
     209,    -1,    97,    -1,   242,    -1,    -1,    37,    -1,    67,
      -1,    88,   222,    -1,    87,   212,    -1,   256,    -1,   212,
       4,   256,    -1,     9,   222,    -1,    84,   215,    -1,   217,
      -1,   215,     4,   217,    -1,   215,     4,   121,   217,    -1,
     215,     4,   121,   117,   215,    51,    -1,   215,    56,   216,
     116,   222,    -1,   215,    55,   216,   116,   222,    -1,   215,
      -1,   117,   215,    51,    -1,   238,    -1,   238,   243,    -1,
     214,   219,   220,   221,    -1,    -1,   213,    -1,    -1,   211,
      -1,    -1,   210,    -1,   223,    -1,   222,    10,   223,    -1,
     224,    -1,   223,    11,   224,    -1,   225,    -1,    13,   225,
      -1,   236,    -1,   117,   222,    51,    -1,    76,   252,    -1,
     111,   252,    -1,   258,   235,   228,   252,    -1,   252,   235,
     258,    -1,   229,    -1,   230,    -1,    35,    -1,   143,    -1,
      36,    -1,   258,    92,   117,   232,    51,    -1,   258,    92,
     252,    -1,   258,   112,   117,   232,    51,    -1,   258,   112,
     252,    -1,   266,    -1,   232,     4,   266,    -1,    -1,    13,
      -1,   258,   233,    14,    -1,   258,   233,    15,    -1,   258,
     235,   258,    -1,   258,   235,   252,    -1,   258,   233,    44,
     258,    11,   258,    -1,    18,    -1,    16,    -1,    17,    -1,
      20,    -1,    22,    -1,    25,    -1,    23,    -1,    26,    -1,
      24,    -1,    19,    -1,    21,    -1,   234,    -1,   231,    -1,
     227,    -1,   226,    -1,    -1,    35,    -1,    68,    -1,   152,
      -1,    50,    -1,   240,    -1,   239,    53,   240,    -1,    50,
      71,   240,    -1,   287,    -1,   287,    -1,    -1,   118,    97,
      52,    -1,   118,    97,     4,    97,    52,    -1,   287,   241,
      -1,   238,    71,   287,   241,    -1,   238,    71,    30,    -1,
     287,    -1,   113,    -1,    71,    97,    -1,    -1,   138,   246,
     253,   254,   214,   219,   220,   221,   249,   247,    -1,    -1,
      96,   145,   251,   250,    -1,   138,   253,   254,   218,   249,
      -1,    -1,   151,   237,   248,    -1,   204,    -1,    -1,   164,
      -1,   287,    -1,   117,   138,   253,   254,   218,    51,    -1,
      -1,    35,    -1,    68,    -1,   152,    -1,   255,    -1,   254,
       4,   255,    -1,   258,    -1,   258,   109,    -1,   258,    40,
     109,    -1,   258,    -1,   158,    -1,   156,    -1,   153,    -1,
     154,    -1,   155,    -1,   157,    -1,   258,   262,    -1,   203,
      -1,   287,    -1,   287,   118,   285,    52,    -1,   287,   118,
     285,     4,   285,    52,    -1,   287,    71,   287,   118,   285,
      52,    -1,   287,    71,   287,   118,   285,     4,   285,    52,
      -1,    70,   287,    -1,   287,    71,   287,    -1,   287,    71,
      30,    -1,    99,    -1,    98,    -1,   160,    -1,    30,    -1,
     170,   117,   259,    51,    -1,   117,   258,    51,    -1,    60,
     117,   265,    51,    -1,    63,   117,   265,    51,    -1,   108,
     117,   265,    51,    -1,   168,   117,   265,    51,    -1,   287,
     117,   265,    51,    -1,    42,   117,   237,   258,    51,    -1,
     166,   117,   237,   258,    51,    -1,   167,   117,   237,   258,
      51,    -1,    38,   117,   237,   258,    51,    -1,    57,   117,
     237,   258,    51,    -1,   169,     4,   260,   147,   261,    -1,
     258,     4,   260,   147,   261,    -1,   169,   260,   147,   261,
      -1,   168,    -1,   108,    -1,    63,    -1,    90,    -1,   106,
      -1,   137,    -1,    83,    -1,   168,    -1,   108,    -1,    63,
      -1,    90,    -1,   106,    -1,   137,    -1,    83,    -1,    83,
     117,    97,    51,    -1,    29,   263,    -1,    31,   263,    -1,
      32,   263,    -1,   257,    -1,    30,   263,    -1,    28,   263,
      -1,    27,   263,    -1,   264,   258,    -1,    -1,    28,    -1,
      27,    -1,   258,    -1,   265,     4,   258,    -1,   203,    -1,
      70,   287,    -1,   268,    -1,   267,   268,    -1,   271,    -1,
     273,    -1,   284,    -1,   275,    -1,   278,    -1,   279,    -1,
     283,    -1,   280,    -1,   282,    -1,   269,    -1,   165,   267,
      73,    -1,    47,   270,   117,   297,    51,    -1,    60,    -1,
     108,    -1,   168,    -1,    63,    -1,   287,    -1,    81,   180,
      18,   294,   147,   294,   272,    69,   268,    -1,    -1,   144,
     294,    -1,    91,   294,   146,   268,   274,    -1,    -1,    72,
     268,    -1,   103,   109,    18,   277,    -1,   103,   109,   118,
     294,    52,    18,   277,    -1,   103,   109,   118,   294,     4,
     294,    52,    18,   277,    -1,    -1,   277,    -1,   294,    -1,
     277,     4,   294,    -1,   110,   285,   104,    -1,   127,   286,
      -1,   129,   276,   281,    -1,    -1,   139,    -1,   131,   286,
      -1,   131,   198,    -1,   140,   285,   104,    -1,   140,   147,
     149,    -1,   163,   294,    69,   268,    -1,    97,    -1,    50,
      -1,   109,    -1,   288,    -1,    33,    -1,    37,    -1,    34,
      -1,    40,    -1,    43,    -1,    44,    -1,    45,    -1,    46,
      -1,    47,    -1,    48,    -1,    49,    -1,    12,    -1,     7,
      -1,    54,    -1,    16,    -1,    59,    -1,    62,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,    69,    -1,    72,
      -1,    74,    -1,    75,    -1,    77,    -1,    78,    -1,    79,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    89,    -1,    90,    -1,    91,    -1,    92,
      -1,    93,    -1,   100,    -1,   101,    -1,   102,    -1,   103,
      -1,    24,    -1,   104,    -1,   105,    -1,   106,    -1,   107,
      -1,   110,    -1,   115,    -1,   122,    -1,   123,    -1,   126,
      -1,   127,    -1,    32,    -1,   130,    -1,   132,    -1,   133,
      -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,   140,
      -1,   141,    -1,   142,    -1,     6,    -1,   144,    -1,   145,
      -1,   146,    -1,   147,    -1,   148,    -1,    58,    -1,   150,
      -1,   159,    -1,   161,    -1,   162,    -1,   163,    -1,   165,
      -1,    -1,     9,   294,    -1,   292,   289,    -1,   115,   293,
      -1,    57,    -1,   128,    -1,    41,   291,    -1,    58,   291,
      -1,    42,   291,    -1,   167,   291,    -1,   166,   291,    -1,
      86,    57,    -1,    86,   128,    -1,    86,    41,   291,    -1,
      86,    58,   291,    -1,    86,    42,   291,    -1,    86,   167,
     291,    -1,    86,   166,   291,    -1,    27,   293,    -1,   299,
      -1,    99,    -1,    98,    -1,   160,    -1,    60,    -1,    61,
      -1,    60,   117,   298,    51,    -1,   108,   117,   298,    51,
      -1,   168,   117,   298,    51,    -1,    63,   117,   298,    51,
      -1,   109,   117,   298,    51,    -1,   117,   294,    51,    -1,
     198,    -1,   293,   295,    -1,    27,   294,    -1,   299,    -1,
      99,    -1,    98,    -1,   160,    -1,    60,    -1,    61,    -1,
      60,   117,   298,    51,    -1,   108,   117,   298,    51,    -1,
     168,   117,   298,    51,    -1,    63,   117,   298,    51,    -1,
     109,   117,   298,    51,    -1,   117,   294,    51,    -1,     7,
     294,    -1,     8,   294,    -1,   198,    -1,   290,    -1,   294,
     296,    -1,    11,   293,    -1,    10,   293,    -1,    29,   293,
      -1,    32,   293,    -1,    31,   293,    -1,    30,   293,    -1,
      28,   293,    -1,    27,   293,    -1,    12,    -1,    11,   294,
      -1,    10,   294,    -1,    29,   294,    -1,    32,   294,    -1,
      31,   294,    -1,    30,   294,    -1,    28,   294,    -1,    27,
     294,    -1,     5,   294,    -1,    18,   294,    -1,    16,   294,
      -1,    17,   294,    -1,    20,   294,    -1,    22,   294,    -1,
      25,   294,    -1,    23,   294,    -1,    26,   294,    -1,    24,
     294,    -1,    19,   294,    -1,    21,   294,    -1,     6,    -1,
      14,    -1,    15,    -1,    12,    -1,    -1,   298,    -1,   294,
      -1,   298,     4,   294,    -1,    50,    -1,   114,    -1,   244,
      -1,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   242,   242,   250,   253,   262,   264,   269,   273,   273,
     277,   281,   284,   287,   292,   295,   295,   298,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   330,   331,   334,   338,
     338,   341,   346,   346,   349,   352,   352,   356,   357,   358,
     359,   360,   363,   366,   369,   372,   375,   382,   382,   386,
     387,   391,   394,   394,   398,   404,   408,   408,   412,   412,
     416,   420,   424,   428,   432,   435,   438,   445,   455,   465,
     480,   484,   492,   492,   495,   495,   498,   508,   511,   512,
     513,   518,   518,   522,   523,   528,   534,   539,   548,   549,
     550,   555,   561,   566,   567,   573,   578,   582,   583,   586,
     589,   592,   595,   600,   601,   605,   606,   616,   621,   622,
     625,   626,   629,   630,   635,   636,   642,   643,   648,   649,
     654,   655,   661,   662,   667,   669,   676,   677,   680,   684,
     685,   694,   696,   698,   700,   706,   707,   711,   712,   717,
     719,   721,   723,   725,   731,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   746,   747,   748,   749,   751,
     752,   753,   754,   765,   766,   767,   768,   774,   778,   782,
     783,   784,   787,   788,   789,   795,   800,   800,   806,   806,
     816,   818,   825,   832,   833,   834,   846,   846,   850,   856,
     860,   861,   862,   863,   867,   868,   872,   880,   884,   891,
     895,   896,   897,   898,   899,   900,   904,   905,   906,   907,
     908,   909,   910,   911,   915,   917,   919,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,   930,   932,   934,
     936,   938,   943,   946,   949,   954,   954,   954,   954,   954,
     954,   954,   955,   955,   955,   955,   955,   955,   955,   955,
     961,   962,   963,   964,   965,   966,   967,   970,   973,   974,
     975,   979,   979,   986,   987,  1003,  1008,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1040,  1051,
    1052,  1053,  1054,  1055,  1058,  1068,  1069,  1073,  1081,  1084,
    1089,  1100,  1111,  1124,  1128,  1131,  1131,  1143,  1149,  1156,
    1164,  1164,  1167,  1172,  1180,  1185,  1192,  1201,  1204,  1208,
    1209,  1214,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,
    1264,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,
    1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,
    1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1300,
    1303,  1310,  1319,  1323,  1329,  1335,  1341,  1347,  1353,  1359,
    1366,  1372,  1378,  1384,  1390,  1396,  1402,  1412,  1430,  1432,
    1436,  1440,  1444,  1453,  1463,  1470,  1476,  1482,  1489,  1495,
    1496,  1501,  1523,  1541,  1543,  1547,  1551,  1555,  1564,  1574,
    1581,  1587,  1593,  1600,  1606,  1607,  1613,  1619,  1624,  1629,
    1651,  1659,  1666,  1674,  1681,  1690,  1697,  1706,  1713,  1722,
    1730,  1737,  1745,  1752,  1761,  1768,  1777,  1784,  1792,  1798,
    1804,  1810,  1816,  1822,  1828,  1834,  1840,  1846,  1852,  1860,
    1867,  1873,  1881,  1891,  1907,  1914,  1921,  1932,  1936,  1940,
    1944
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
  "KW_CURRENT", "KW_EXTEND", "$accept", "ace_report", "db_section",
  "op_define_section", "define_section", "define_element_list",
  "define_element", "ufunc_name", "def_ascii_list", "variable", "datatype",
  "op_input_section", "input_section", "prompt_section", "prompt_element",
  "op_output_section", "output_section", "output_element_list",
  "output_element", "select_section", "sec_select_list", "read_list",
  "op_delim", "format_section", "op_end", "format_actions",
  "format_action", "variable_sub", "variable_sub_a",
  "op_order_by_clause_read", "order_by_clause_read", "$@1", "literal",
  "order_by_clause", "$@2", "sort_specification_list",
  "sort_specification", "sort_spec", "op_asc_desc", "having_clause",
  "group_by_clause", "column_specification_list", "where_clause",
  "from_clause", "table_reference_list", "op_bracket_table_reference_list",
  "tname", "table_expression", "op_where_clause", "op_group_by_clause",
  "op_having_clause", "search_condition", "boolean_term", "boolean_factor",
  "boolean_primary", "exists_predicate", "quantified_predicate",
  "quantifier", "all", "some", "in_predicate", "in_value_list", "op_not",
  "comparison_predicate", "comp_op_sql", "predicate", "op_all",
  "table_name", "db_name", "table_identifier", "col_arr", "column_name",
  "correlation_name", "real_number", "select_statement", "$@3",
  "op_into_temp", "select_statement2", "sel_p2", "op_no_log",
  "tmp_tabname", "subquery", "op_ad", "sq_select_list",
  "value_expression_pls", "column_specification", "units_qual",
  "sql_value_expression", "extend_from_to", "s_curr", "e_curr",
  "sql_val_expr_next", "sql_value_expression_s", "op_prefix",
  "sql_value_expr_list", "value_specification", "commands", "command",
  "call_command", "func_identifier", "for_command", "op_step",
  "if_command", "op_else", "let_command", "op_expr_concat", "expr_concat",
  "need_command", "pause_command", "print_command", "op_semi",
  "print_file_command", "skip_command", "while_command", "int_val",
  "string", "identifier", "reserved_word", "op_where_agg", "aggregate",
  "of_expr", "aggregate_elem", "simple_fmt_val_expression",
  "fmt_val_expression", "simple_val_next", "val_next",
  "op_fmt_val_expr_list", "fmt_val_expr_list", "literal_expr", 0
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   171,   172,   173,   173,   174,   174,   175,   176,   176,
     177,   177,   177,   177,   178,   179,   179,   180,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   182,   182,   183,   184,
     184,   185,   186,   186,   187,   188,   188,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   190,   190,   191,
     191,   192,   193,   193,   194,   194,   195,   195,   196,   196,
     197,   197,   197,   197,   197,   197,   197,   198,   198,   198,
     199,   199,   200,   200,   202,   201,   201,   203,   203,   203,
     203,   205,   204,   206,   206,   207,   208,   208,   209,   209,
     209,   210,   211,   212,   212,   213,   214,   215,   215,   215,
     215,   215,   215,   216,   216,   217,   217,   218,   219,   219,
     220,   220,   221,   221,   222,   222,   223,   223,   224,   224,
     225,   225,   226,   226,   227,   227,   228,   228,   229,   230,
     230,   231,   231,   231,   231,   232,   232,   233,   233,   234,
     234,   234,   234,   234,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   236,   236,   236,   236,   237,
     237,   237,   237,   238,   238,   238,   238,   239,   240,   241,
     241,   241,   242,   242,   242,   243,   244,   244,   246,   245,
     247,   247,   248,   249,   249,   249,   250,   250,   251,   252,
     253,   253,   253,   253,   254,   254,   255,   255,   255,   256,
     257,   257,   257,   257,   257,   257,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   259,   259,   259,   260,   260,   260,   260,   260,
     260,   260,   261,   261,   261,   261,   261,   261,   261,   261,
     262,   262,   262,   262,   262,   262,   262,   263,   264,   264,
     264,   265,   265,   266,   266,   267,   267,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   269,   270,
     270,   270,   270,   270,   271,   272,   272,   273,   274,   274,
     275,   275,   275,   276,   276,   277,   277,   278,   279,   280,
     281,   281,   282,   282,   283,   283,   284,   285,   286,   287,
     287,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   289,
     289,   290,   291,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   297,   297,   298,   298,   299,   299,   299,
     299
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
       3,     5,     2,     4,     3,     1,     1,     2,     0,    10,
       0,     4,     5,     0,     3,     1,     0,     1,     1,     6,
       0,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     4,
       6,     6,     8,     2,     3,     3,     1,     1,     1,     1,
       4,     3,     4,     4,     4,     4,     4,     5,     5,     5,
       5,     5,     5,     5,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     2,     2,     1,     2,     2,     2,     2,     0,     1,
       1,     1,     3,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     1,
       1,     1,     1,     1,     9,     0,     2,     5,     0,     2,
       4,     7,     9,     0,     1,     1,     3,     3,     2,     3,
       0,     1,     2,     2,     3,     3,     4,     1,     1,     1,
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
       1,     1,     1,     0,     1,     1,     3,     1,     1,     1,
       1
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
     317,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,   188,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   318,    56,    44,    46,    62,   200,
       0,     2,    58,     0,    57,    16,     0,     0,     0,     0,
       0,     0,    52,    51,    54,     0,    48,    49,    55,    53,
       0,    82,   201,   202,   203,     0,     0,     0,     0,     0,
       0,     0,    66,    68,    60,    21,     0,    34,     0,    31,
      23,    12,    41,    50,    47,    63,    84,     0,    61,    83,
     386,   333,   332,   335,   364,   229,   375,   321,   323,   322,
       0,   324,     0,   325,   326,   327,   328,   329,   330,   331,
      87,   334,     0,   392,   336,     0,   337,     0,   338,   339,
     340,   341,   342,     0,     0,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,    90,   227,   226,   360,   361,   362,   363,   365,
     366,   367,   368,     0,   319,   369,   186,    88,   370,     0,
     371,   372,   373,   374,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   387,   388,   389,   390,   391,   393,
     394,   228,   395,   396,   397,   398,     0,     0,     0,     0,
     217,    89,     0,   204,   206,   218,   320,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    65,    69,     0,     0,
       0,   173,    96,    86,    93,    98,     0,     0,   174,    97,
     179,   169,   169,   169,     0,     0,   223,   187,     0,     0,
     169,   169,     0,     0,     0,     0,   118,   268,   268,   268,
     268,   268,   268,     0,   207,   212,   213,   214,   211,   215,
     210,   263,   216,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,     0,
       0,     0,     0,    72,   275,   286,   277,   278,   280,   281,
     282,   284,   285,   283,   279,    71,    35,    32,    85,     0,
       0,    99,   100,    95,     0,     0,     0,   182,   170,   171,
     172,     0,     0,     0,   271,     0,     0,     0,   231,     0,
       0,     0,     0,     0,     0,   205,   106,   107,   115,   178,
       0,   119,   120,   270,   269,   266,     0,   265,   260,   264,
     261,   262,   208,   225,   224,     0,     0,    81,    79,    80,
       0,     0,    70,    73,    74,   289,   292,   290,   291,     0,
     293,     0,     0,     0,     0,     0,     0,   487,   403,     0,
     437,   438,     0,     0,   490,   435,   434,     0,    79,   488,
       0,   404,   436,     0,     0,     0,   447,   489,   448,   399,
       0,   433,     0,     0,   308,   310,   304,   305,   313,   312,
       0,     0,     0,     0,   276,   176,   178,    94,   184,   179,
     175,     0,     0,     0,     0,     0,   232,   233,   234,     0,
       0,   235,     0,   247,   251,   248,   249,   246,   250,   245,
       0,     0,   230,     0,     0,     0,   116,   185,     0,     0,
       0,     0,   105,   124,   126,   128,   168,   167,   166,   165,
     130,     0,   147,     0,   121,   122,   267,     0,   236,     0,
     219,     0,    76,    75,   483,     0,   445,   446,   432,     0,
     405,   407,   406,     0,     0,     0,     0,   410,     0,   411,
       0,     0,     0,     0,     0,   409,   408,     0,     0,   401,
       0,   479,     0,     0,   482,   480,   481,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   449,     0,     0,   307,   311,
     309,     0,   315,   314,     0,   287,   183,     0,   180,   240,
     237,   241,   272,   238,   239,     0,     0,     0,     0,   108,
       0,   113,     0,     0,   129,     0,   132,   133,   200,     0,
     147,     0,     0,   155,   156,   154,   163,   157,   164,   158,
     160,   162,   159,   161,     0,   148,     0,     0,     0,     0,
     102,   103,   209,     0,   123,   193,     0,     0,     0,   485,
       0,   484,     0,     0,   422,   423,     0,   420,   419,     0,
      79,     0,   421,     0,   430,   402,   418,     0,     0,   412,
     414,   413,   416,   415,     0,     0,   444,     0,   400,   467,
     460,   459,   469,   470,   468,   477,   471,   478,   472,   474,
     476,   473,   475,   466,   465,   461,   464,   463,   462,   298,
     300,     0,   306,   316,     0,     0,   254,   258,   255,   256,
     253,   257,   252,   244,     0,     0,   109,     0,     0,     0,
       0,   131,   125,   127,   135,     0,   142,     0,   144,   149,
     150,     0,   138,   140,     0,   139,     0,   136,   137,   152,
     151,     0,   101,    91,   169,   195,   190,     0,   221,   220,
       0,    78,   288,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,   458,     0,     0,     0,     0,     0,
       0,   431,   439,   442,   440,   443,   441,     0,   297,     0,
       0,   181,   242,     0,   243,     0,   114,   112,   111,     0,
       0,   273,     0,   145,     0,     0,   134,   104,     0,     0,
       0,   189,     0,     0,   486,   295,     0,     0,     0,     0,
     429,     0,   451,   450,   457,   456,   452,   455,   454,   453,
     299,     0,     0,     0,   110,   118,     0,   274,     0,   141,
     143,     0,    92,   200,   194,     0,   222,    77,     0,     0,
     424,   427,   425,   428,   426,     0,   301,   259,   120,   199,
     146,   153,     0,   196,   198,   296,     0,     0,   122,     0,
     197,   191,   294,   302,   117,   193,   192
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   256,   122,   123,   426,   390,   138,
     139,   260,   240,   715,   768,   263,   264,   265,   343,   614,
     494,   610,   371,   795,   581,   582,   367,   796,   372,   495,
     615,   482,   483,   484,   485,   486,   487,   706,   707,   708,
     488,   762,   608,   489,   609,   490,   351,   368,   267,   268,
     347,   269,   476,   427,    70,    89,   771,   804,   716,   831,
     823,   491,   115,   242,   243,   611,   301,   492,   364,   470,
     683,   302,   375,   376,   355,   763,   323,   324,   325,   399,
     326,   809,   327,   748,   328,   435,   436,   329,   330,   331,
     560,   332,   333,   334,    51,    85,   245,   246,   529,   428,
     510,   429,   635,   619,   741,   555,   620,   621,   431
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -682
static const yytype_int16 yypact[] =
{
       0,     6,    86,    31,    78,    82,  -682,    28,    -4,  -682,
    -682,  -682,    57,    66,    83,    57,    24,  -682,    60,    81,
    -682,  -682,   223,  3405,  -682,  -682,   143,  3405,  -682,  -682,
     175,    11,  -682,   492,   -71,  -682,    57,   145,  -682,  -682,
     160,  -682,  -682,  -682,  -682,   163,  -682,  -682,   181,  -682,
    -682,   248,  -682,    57,  -682,  -682,   207,   214,   227,   190,
     236,   246,   315,   578,  -682,   315,  -682,   310,   -38,   326,
    -682,  3405,   143,   143,   143,   143,    57,   400,   143,   143,
     143,     5,   143,   143,  -682,  -682,  -682,  -682,   340,   -15,
     412,  -682,  -682,   270,  -682,  -682,   359,    72,    91,   360,
    3405,   315,  -682,  -682,  -682,   315,   315,  -682,  -682,  -682,
     315,   127,  -682,  -682,  -682,  1735,   344,   345,   296,   318,
      77,   -42,   855,  -682,  -682,  -682,   143,  -682,   143,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  2048,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
     316,  -682,   329,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,   335,  -682,  -682,   337,  -682,   354,  -682,  -682,
    -682,  -682,  -682,  3084,   346,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,   355,  -682,  -682,  -682,  -682,  -682,  1735,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,   356,   362,   369,   374,
    -682,  -682,    34,  -682,   515,   155,  -682,   333,   377,   402,
     404,   361,   363,   187,   187,  -682,  -682,  -682,   444,   445,
    2048,   429,  -682,   500,  -682,    80,   460,   456,  -682,  -682,
      -7,    13,    13,    13,  1735,  1735,  -682,  -682,  1735,   407,
      13,    13,  1735,  1405,  1735,  2640,   524,   306,   306,   306,
     306,   306,   306,   427,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  2788,  1735,   143,   134,   134,  -682,   187,
     187,   187,  1900,    57,   550,   430,   143,   315,   550,    16,
     -41,   550,   187,   187,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,   187,  -682,  -682,   500,  3084,
    2048,  -682,  -682,  -682,  2936,  3084,   441,  -682,  -682,  -682,
    -682,  1735,  1735,  1735,  2137,   110,   154,   166,  -682,  1735,
    1735,   174,    20,   327,   489,  -682,    74,  -682,  3084,   488,
     910,  -682,   461,  -682,  -682,  -682,  1735,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,   453,   203,    38,  -682,   458,  -682,
     187,   187,   187,   187,   187,  -682,  -682,  -682,  -682,   442,
    -682,   560,   550,   550,   550,   464,   464,  -682,  -682,   464,
     466,  -682,   467,    63,  -682,  -682,  -682,   468,   243,  -682,
     550,  -682,  -682,   464,   464,   470,  -682,  -682,  -682,   572,
    3263,  -682,     9,   486,  -682,   455,   591,  3791,  -682,  -682,
     448,   497,  3499,   525,  -682,  -682,  -682,  -682,  -682,   485,
    -682,    50,  3083,  3151,  3285,  1735,  -682,  -682,  -682,  3293,
    3321,  -682,    56,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
     465,    56,  -682,  2196,  2344,  2344,  -682,  -682,  1240,   501,
     501,   745,   595,   603,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  3532,  3235,  1735,  -682,   529,  2137,   143,  -682,   143,
    -682,   550,   187,   187,   550,   550,  3791,  3791,   339,  3269,
    -682,  -682,  -682,   550,   550,   464,   464,  -682,   464,  -682,
     464,   464,   550,   550,  3715,  -682,  -682,   550,   550,  -682,
     550,  -682,   550,   550,  -682,  -682,  -682,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   187,  -682,   550,   550,  -682,  -682,
    -682,   550,  -682,  -682,   187,  -682,  -682,   522,  -682,  -682,
    -682,  -682,  2137,  -682,  -682,   473,   230,   475,  2492,  -682,
    2640,    74,   509,   513,  -682,   495,  -682,  -682,   -15,   102,
     396,   910,   910,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  1735,  -682,   517,   520,   328,  1075,
     626,  -682,  2137,   910,  -682,    -3,    84,   586,  3559,  3791,
     592,   638,   718,  3269,   527,  -682,   528,  -682,  -682,   533,
     256,   550,  -682,   536,  -682,  1898,  -682,   224,   231,  -682,
    -682,  -682,  -682,  -682,   238,   277,  -682,   279,  3814,  3791,
    3836,  3857,  3569,  3569,  3569,  3569,  3569,  3569,  3569,  3569,
    3569,  3569,  3569,   339,   339,   358,   358,  -682,  -682,   574,
     591,  3598,  3791,  -682,   605,   230,  -682,   538,  -682,  -682,
    -682,  -682,  -682,  -682,   230,  2640,  -682,    36,   910,   910,
    1735,  -682,   603,  -682,  2137,  1343,  -682,  1343,  -682,  -682,
    -682,  1735,  -682,  -682,  1570,  -682,   501,  -682,  -682,  -682,
    2137,  1735,   595,  -682,    13,  -682,   565,   143,  -682,  -682,
     550,  -682,  -682,   550,   550,   365,   550,   550,   550,   550,
    3753,   550,  3269,  3269,  -682,  3269,  3269,  3269,  3269,  3269,
    3269,  -682,  -682,  -682,  -682,  -682,  -682,   187,  -682,   550,
     644,  -682,  -682,   569,  -682,   167,  -682,   595,   595,    34,
    3084,  -682,   281,  -682,   288,   168,  -682,  -682,  2048,   537,
     532,  -682,   622,  3637,  3791,  3396,   297,   298,   311,   313,
    -682,   331,  2046,   438,   365,   365,   370,   370,  -682,  -682,
    -682,  3676,   550,   629,  -682,   524,   630,  -682,   182,  -682,
    -682,  1735,   500,   -15,  -682,  3084,  -682,  -682,   550,   613,
    -682,  -682,  -682,  -682,  -682,   666,   591,  -682,   461,  -682,
    -682,  2137,  1735,   521,  -682,  3791,   187,   550,   529,    34,
    -682,  -682,  -682,   591,  -682,    -3,  -682
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -682,  -682,  -682,  -682,  -682,  -682,   671,  -682,  -682,    -8,
      22,  -682,  -682,  -682,   658,  -682,  -682,  -682,   628,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,   570,  -276,   387,  -682,
    -682,  -682,  -658,  -682,  -682,  -241,   364,  -682,  -682,  -682,
    -682,  -682,  -682,   463,  -281,   220,  -440,  -131,   -95,  -116,
    -125,  -469,   115,   116,   233,  -682,  -682,  -682,  -682,  -682,
    -682,    12,  -682,  -682,   228,  -682,  -270,  -136,  -682,  -133,
     265,  -682,  -682,  -115,   632,  -682,  -682,  -682,  -120,  -682,
    -682,  -422,  -582,  -681,   437,    42,  -682,  -102,  -682,  -399,
    -602,  -682,   278,  -682,   125,   -67,  -177,  -294,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -551,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,   -57,   -31,  -129,  -682,  -682,  -682,
    2937,  -682,  -352,   -27,  -682,  -682,  -682,  -462,  -429
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -179
static const yytype_int16 yytable[] =
{
     241,   266,   352,   353,   366,   670,   690,    27,   270,   759,
     359,   360,   589,   244,     4,    96,    97,    98,    99,   338,
     112,   102,   103,   104,   462,   108,   109,   556,    71,   444,
     389,   389,    12,   579,    88,    92,    12,   761,   284,   761,
     473,   444,   499,   438,   276,    77,  -177,   253,   348,    52,
     107,   637,   638,   113,   567,    84,    50,   586,   587,     1,
     644,   645,    65,   575,  -178,   647,    84,    66,   100,   258,
     132,   259,   577,   752,   133,   134,   126,   335,   473,   135,
     636,   349,   754,   463,    54,   105,     6,   756,   717,    18,
     500,   474,   475,    95,   241,   128,     7,    28,   444,   444,
     444,    93,   568,   464,   515,   516,   440,   279,   254,    13,
     465,   346,   591,    13,   455,     5,   713,   341,   285,   463,
     517,   518,   131,   127,   266,   388,   466,   557,   467,   474,
     475,   270,   392,   393,   394,   106,   718,   114,   686,   464,
     761,   829,   129,    30,   712,   443,   465,   342,   714,   444,
      14,    10,   251,   691,    14,    11,   369,   468,   455,   241,
     241,   456,   466,   241,   467,   350,    21,   241,   241,   241,
     455,   473,   354,   354,   384,    24,   354,   252,   455,   801,
     354,   363,   244,   400,   696,   698,    15,   709,   469,   241,
      15,   519,    30,   468,   636,   287,   288,   289,   290,   291,
     292,    26,   354,    33,   266,   457,   445,   455,   444,   444,
     446,   270,   450,   502,   503,   449,   446,   458,   794,   757,
     758,   822,   474,   475,   469,   461,   303,    36,   723,   520,
     521,   387,   160,   634,   312,   723,   241,   241,   241,   477,
      50,   816,   723,   388,   241,   241,   136,   137,   386,   452,
     453,   454,   760,   174,   498,   241,    53,   459,   460,   433,
     669,   241,    72,   441,   776,   777,   778,   779,   313,   781,
     673,   725,   304,   305,   496,   742,   833,    73,   314,   192,
      74,   723,   743,   723,   766,   798,   434,   430,   439,   744,
     315,   437,   798,   676,   442,   206,   207,   316,    75,   687,
      76,   723,   723,   636,   636,   401,   636,   636,   636,   636,
     636,   636,    78,   677,   317,   723,   318,   723,   319,    79,
     678,   295,   296,   297,   298,   299,   300,   320,   745,    80,
     746,   471,   799,   373,   374,   723,   679,    81,   680,   800,
     241,    82,   699,   700,   369,   369,   369,   634,   810,   811,
     321,    83,   322,   572,   287,   288,   289,   290,   291,   292,
     523,   501,   812,   241,   813,    84,   241,   681,   550,   551,
     552,   553,   701,   729,   501,   506,   507,   508,   241,   590,
     782,   783,   814,   784,   785,   786,   787,   788,   789,   552,
     553,   612,    90,   524,   737,   738,   739,   740,   682,    94,
     356,   739,   740,   357,   755,   101,   110,   361,    66,   605,
     125,   130,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   287,   288,   289,   290,   291,   292,   385,
     247,   248,   249,   271,   287,   288,   289,   290,   291,   292,
     616,   250,   617,   277,   769,   116,   272,   358,   306,   369,
     734,   369,   273,   790,   274,   117,   634,   634,   358,   634,
     634,   634,   634,   634,   634,   735,   736,   737,   738,   739,
     740,   275,   278,   280,   618,   308,   241,   241,   622,   281,
     295,   296,   297,   298,   299,   300,   282,   118,   606,   241,
     119,   283,   307,   309,   241,   336,   337,   310,   241,   311,
     339,   648,   694,   649,   340,   650,   651,   710,   607,   345,
     652,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,   802,   120,   437,
     671,   344,   832,   370,   672,   121,   382,    56,   451,   432,
     472,  -177,   287,   288,   289,   290,   291,   292,   493,   295,
     296,   297,   298,   299,   300,   293,   369,   402,   403,   504,
     295,   296,   297,   298,   299,   300,   377,   378,   379,   380,
     381,   497,   312,   241,   241,   241,   501,   404,   505,   509,
     241,   528,   241,   513,   514,   522,   241,   527,   244,   241,
     558,   405,   406,    57,   559,   561,   241,   562,   565,   765,
     407,   563,   279,   346,   730,   591,   313,   408,   409,   612,
     410,   411,   576,   412,   592,    58,   314,   613,   585,   674,
     675,   174,   684,    56,   294,   688,    59,    60,   315,   689,
     711,   797,   266,   588,   695,   316,   413,   697,   719,   270,
      61,    62,   723,   722,   726,   727,   747,   414,   415,   416,
     728,    86,   317,   731,   318,   753,   319,   751,   417,   418,
     772,   770,   792,   206,   419,   320,   793,   420,   295,   296,
     297,   298,   299,   300,   806,   803,   824,   805,   421,    57,
     817,   819,   826,   241,   827,   830,   241,    29,   321,    55,
     322,    87,   257,   773,   391,   583,   774,   775,   835,   821,
     818,    58,   828,   834,   447,   286,   692,   241,   693,   764,
     422,   584,    59,    60,   566,   836,   423,   424,   425,   604,
     244,   365,   791,   530,   531,   124,    61,    62,   532,   533,
     534,   820,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   140,   141,   767,     0,     0,     0,   142,   478,     0,
       0,   143,     0,     0,     0,   437,     0,     0,     0,   144,
       0,     0,     0,     0,     0,   145,     0,   146,   147,   148,
       0,   825,   149,   150,     0,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,   161,
     437,     0,   162,   163,   164,   165,     0,   166,   167,   168,
     169,   170,   171,     0,   172,   173,   174,   175,     0,   176,
     177,   479,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   480,     0,   206,   207,
     208,     0,   481,     0,     0,   724,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,   588,     0,   221,   222,   223,   116,   224,
     225,   226,   227,   228,     0,   229,     0,     0,   117,     0,
       0,     0,     0,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   140,   141,     0,     0,
       0,     0,   142,   478,     0,     0,   143,     0,   255,     0,
       0,     0,     0,   119,   144,     0,     0,     0,     0,     0,
     145,     0,   146,   147,   148,     0,     0,   149,   150,     0,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,   161,     0,     0,   162,   163,   164,
     165,   120,   166,   167,   168,   169,   170,   171,   121,   172,
     173,   174,   175,     0,   176,   177,   479,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   480,     0,   206,   207,   208,     0,   481,     0,     0,
       0,     0,   210,   211,     0,     0,   212,   213,     0,     0,
     214,     0,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   140,   141,     0,     0,     0,     0,   142,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,   145,     0,   146,   147,   148,
     702,   703,   149,   150,     0,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,   161,
       0,     0,   162,   163,   164,   165,     0,   166,   167,   168,
     169,   170,   171,     0,   172,   173,   174,   175,     0,   176,
     177,     0,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,   206,   207,
     208,     0,   704,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,   705,   224,
     225,   226,   227,   228,     0,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   140,   141,     0,     0,
       0,     0,   142,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
     145,     0,   146,   147,   148,     0,     0,   149,   150,     0,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,   161,     0,     0,   162,   163,   164,
     165,     0,   166,   167,   168,   169,   170,   171,     0,   172,
     173,   174,   175,     0,   176,   177,   479,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   480,     0,   206,   207,   208,     0,   481,     0,     0,
       0,     0,   210,   211,     0,     0,   212,   213,     0,     0,
     214,     0,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
     229,     0,     0,   160,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   140,   141,   760,   174,     0,     0,   142,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,   145,     0,   146,   147,   148,
     192,     0,   149,   150,     0,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   206,   207,     0,   161,
       0,     0,   162,   163,   164,   165,     0,   166,   167,   168,
     169,   170,   171,     0,   172,   173,   174,   175,     0,   176,
     177,   588,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,   206,   207,
     208,     0,   209,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,   362,   239,   140,   141,     0,     0,
       0,     0,   142,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
     145,     0,   146,   147,   148,     0,     0,   149,   150,     0,
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,   161,     0,     0,   162,   163,   164,
     165,     0,   166,   167,   168,   169,   170,   171,     0,   172,
     173,   174,   175,     0,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,     0,     0,   206,   207,   208,     0,   209,     0,     0,
       0,     0,   210,   211,     0,     0,   212,   213,     0,     0,
     214,     0,   215,   216,   217,   218,   219,   220,   588,     0,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   140,   141,     0,     0,     0,     0,   142,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,   145,     0,   146,   147,   148,
       0,     0,   149,   150,     0,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,   161,
       0,     0,   162,   163,   164,   165,     0,   166,   167,   168,
     169,   170,   171,     0,   172,   173,   174,   175,     0,   176,
     177,     0,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,     0,     0,   206,   207,
     208,     0,   209,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   140,   141,   732,   733,
     734,     0,   142,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,   144,   735,   736,   737,   738,   739,
     740,     0,   146,   147,   148,     0,     0,   149,     0,     0,
     151,     0,     0,   153,   154,   155,   156,   157,   158,   159,
       0,     0,     0,     0,   161,     0,     0,     0,   163,   164,
     395,     0,   166,   396,   168,   169,   170,   171,     0,   172,
       0,     0,   175,     0,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   397,   204,
     205,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,   210,   211,     0,     0,   212,   213,     0,     0,
     214,     0,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
     229,     0,     0,     0,   140,   141,     0,   733,   734,   230,
     142,   232,   233,   234,   143,   235,     0,     0,   398,     0,
       0,     0,   144,   735,   736,   737,   738,   739,   740,     0,
     146,   147,   148,     0,     0,   149,     0,     0,   151,     0,
       0,   153,   154,   155,   156,   157,   158,   159,   261,     0,
       0,     0,   161,     0,     0,     0,   163,   164,     0,     0,
     166,     0,   168,   169,   170,   171,     0,   172,     0,     0,
     175,     0,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,   262,     0,     0,   195,   196,
     197,   198,   199,   200,   201,   202,     0,   204,   205,     0,
       0,     0,     0,   208,   287,   288,   289,   290,   291,   292,
     210,   211,     0,     0,   212,   213,     0,     0,   214,     0,
     215,   216,   217,   218,   219,   220,     0,     0,   221,   222,
     223,     0,   224,   225,   226,   227,   228,     0,   229,     0,
       0,     0,   140,   141,     0,     0,     0,   230,   142,   232,
     233,   234,   143,   235,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,     0,     0,   149,     0,     0,   151,     0,     0,   153,
     154,   155,   156,   157,   158,   159,   261,     0,     0,     0,
     161,     0,     0,     0,   163,   164,     0,     0,   166,     0,
     168,   169,   170,   171,     0,   172,     0,     0,   175,     0,
     176,   177,     0,   178,   179,   180,     0,   181,   182,   183,
     184,   185,   186,     0,     0,   187,   188,   189,   190,   191,
     295,   296,   297,   298,   299,   300,   195,   196,   197,   198,
     199,   200,   201,   202,     0,   204,   205,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,   578,   210,   211,
       0,     0,   212,   213,     0,     0,   214,     0,   215,   216,
     217,   218,   219,   220,     0,     0,   221,   222,   223,     0,
     224,   225,   226,   227,   228,     0,   229,     0,     0,     0,
     140,   141,     0,     0,     0,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,     0,
       0,   149,     0,     0,   151,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   261,     0,     0,     0,   161,     0,
       0,     0,   163,   164,     0,     0,   166,     0,   168,   169,
     170,   171,     0,   172,     0,     0,   175,     0,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,     0,     0,   187,   188,   189,   190,   191,     0,     0,
       0,     0,     0,     0,   195,   196,   197,   198,   199,   200,
     201,   202,     0,   204,   205,     0,     0,     0,     0,   208,
       0,   580,     0,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,     0,     0,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,     0,     0,   140,   141,
       0,     0,     0,   230,   142,   232,   233,   234,   143,   235,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,     0,     0,   149,
       0,     0,   151,     0,     0,   153,   154,   155,   156,   157,
     158,   159,   261,     0,     0,     0,   161,     0,     0,     0,
     163,   164,     0,     0,   166,     0,   168,   169,   170,   171,
       0,   172,     0,     0,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,     0,
       0,     0,   195,   196,   197,   198,   199,   200,   201,   202,
       0,   204,   205,     0,     0,     0,     0,   208,     0,   685,
       0,     0,     0,     0,   210,   211,     0,     0,   212,   213,
       0,     0,   214,     0,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,     0,   224,   225,   226,   227,
     228,     0,   229,     0,     0,     0,   140,   141,     0,     0,
       0,   230,   142,   232,   233,   234,   143,   235,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,     0,     0,   149,     0,     0,
     151,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     261,     0,     0,     0,   161,     0,     0,     0,   163,   164,
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
       0,     0,   144,     0,     0,     0,     0,     0,   383,     0,
     146,   147,   148,     0,     0,   149,     0,     0,   151,     0,
       0,   153,   154,   155,   156,   157,   158,   159,     0,     0,
       0,     0,   161,     0,     0,     0,   163,   164,     0,     0,
     166,     0,   168,   169,   170,   171,     0,   172,     0,     0,
     175,     0,   176,   177,     0,   178,   179,   180,     0,   181,
     182,   183,   184,   185,   186,     0,     0,   187,   188,   189,
     190,   191,     0,     0,     0,     0,     0,     0,   195,   196,
     197,   198,   199,   200,   201,   202,     0,   204,   205,     0,
       0,     0,     0,   208,     0,     0,     0,     0,     0,     0,
     210,   211,     0,     0,   212,   213,     0,     0,   214,     0,
     215,   216,   217,   218,   219,   220,     0,     0,   221,   222,
     223,     0,   224,   225,   226,   227,   228,     0,   229,     0,
       0,     0,   140,   141,     0,     0,     0,   230,   142,   232,
     233,   234,   143,   235,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,   448,     0,   146,   147,
     148,     0,     0,   149,     0,     0,   151,     0,     0,   153,
     154,   155,   156,   157,   158,   159,     0,     0,     0,     0,
     161,     0,     0,     0,   163,   164,     0,     0,   166,     0,
     168,   169,   170,   171,     0,   172,     0,     0,   175,     0,
     176,   177,     0,   178,   179,   180,     0,   181,   182,   183,
     184,   185,   186,     0,     0,   187,   188,   189,   190,   191,
       0,     0,     0,     0,     0,     0,   195,   196,   197,   198,
     199,   200,   201,   202,     0,   204,   205,     0,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,   210,   211,
       0,     0,   212,   213,     0,     0,   214,     0,   215,   216,
     217,   218,   219,   220,     0,     0,   221,   222,   223,     0,
     224,   225,   226,   227,   228,     0,   229,     0,     0,     0,
     140,   141,     0,     0,     0,   230,   142,   232,   233,   234,
     143,   235,     0,     0,     0,     0,     0,     0,   144,     0,
     287,   288,   289,   290,   291,   292,   146,   147,   148,     0,
       0,   149,     0,     0,   151,     0,     0,   153,   154,   155,
     156,   157,   158,   159,   569,     0,     0,     0,   161,     0,
       0,     0,   163,   164,     0,     0,   166,     0,   168,   169,
     170,   171,     0,   172,     0,     0,   175,     0,   176,   177,
       0,   178,   179,   180,     0,   181,   182,   183,   184,   185,
     186,     0,     0,   187,   188,   189,   190,   191,   287,   288,
     289,   290,   291,   292,   195,   196,   197,   198,   199,   200,
     201,   202,     0,   204,   205,     0,     0,     0,     0,   208,
       0,     0,   570,     0,     0,     0,   210,   211,     0,     0,
     212,   213,     0,     0,   214,     0,   215,   216,   217,   218,
     219,   220,     0,     0,   221,   222,   223,     0,   224,   225,
     226,   227,   228,     0,   229,     0,   295,   296,   297,   298,
     299,   300,     0,   230,     0,   232,   233,   234,   605,   235,
       0,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   287,   288,   289,   290,   291,   292,   530,   531,
       0,     0,     0,   532,   533,   534,     0,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   623,     0,     0,     0,
       0,     0,     0,     0,   295,   296,   297,   298,   299,   300,
       0,     0,   287,   288,   289,   290,   291,   292,     0,   407,
     287,   288,   289,   290,   291,   292,     0,   606,     0,   624,
     625,     0,   626,     0,     0,     0,   571,     0,     0,     0,
     174,     0,     0,   511,   573,     0,   512,   607,   287,   288,
     289,   290,   291,   292,     0,     0,     0,     0,     0,     0,
     525,   526,     0,     0,     0,     0,   414,   627,   628,     0,
       0,     0,   574,     0,     0,     0,     0,   629,   630,     0,
       0,     0,   206,   419,     0,     0,   631,     0,   295,   296,
     297,   298,   299,   300,     0,     0,     0,     0,     0,     0,
       0,   530,   531,     0,     0,     0,   532,   533,   534,   554,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   632,
       0,     0,     0,     0,     0,     0,     0,   633,   295,   296,
     297,   298,   299,   300,     0,     0,   295,   296,   297,   298,
     299,   300,   639,   640,    37,   641,     0,   642,   643,     0,
       0,     0,     0,     0,     0,    38,     0,    39,     0,    40,
       0,     0,     0,     0,   295,   296,   297,   298,   299,   300,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      44,     0,     0,     0,   530,   531,     0,     0,     0,   532,
     533,   534,    45,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,     0,     0,     0,     0,     0,     0,     0,     0,
     808,     0,     0,     0,     0,     0,    46,    47,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,     0,
       0,     0,     0,   720,   530,   531,    48,     0,   564,   532,
     533,   534,     0,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   749,   530,   531,     0,     0,     0,   532,   533,
     534,   721,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   530,   531,     0,     0,     0,   532,   533,   534,
     750,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   530,   531,     0,     0,     0,   532,   533,   534,   807,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     530,   531,     0,     0,     0,   532,   533,   534,   815,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   530,   531,
       0,     0,     0,   532,   533,   534,   646,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   530,   531,     0,     0,
       0,   532,   533,   534,   780,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   532,   533,   534,     0,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   533,   534,     0,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   534,
       0,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553
};

static const yytype_int16 yycheck[] =
{
     115,   137,   272,   273,   285,   556,   588,    15,   137,   690,
     280,   281,   481,   115,     8,    72,    73,    74,    75,   260,
      35,    78,    79,    80,     4,    82,    83,    18,    36,   323,
     306,   307,     8,   473,    65,    73,     8,   695,     4,   697,
       4,   335,     4,   319,   173,    53,    53,    89,    35,    27,
      81,   513,   514,    68,     4,    50,    97,   479,   480,    59,
     522,   523,   133,   462,    71,   527,    50,   138,    76,   126,
     101,   128,   471,   675,   105,   106,     4,   254,     4,   110,
     509,    68,   684,    63,    73,    80,     0,    51,     4,    93,
      52,    55,    56,    71,   209,     4,    65,    73,   392,   393,
     394,   139,    52,    83,    41,    42,   147,   209,   150,    85,
      90,   118,    10,    85,     4,   109,   119,    37,    84,    63,
      57,    58,   100,    51,   260,   109,   106,   118,   108,    55,
      56,   260,   309,   310,   311,   130,    52,   152,   578,    83,
     798,   822,    51,   132,   613,   322,    90,    67,   151,   443,
     126,    73,    75,    51,   126,    73,   285,   137,     4,   274,
     275,    51,   106,   278,   108,   152,   109,   282,   283,   284,
       4,     4,   274,   275,   303,   109,   278,   100,     4,    11,
     282,   283,   284,   312,   606,   607,   162,   609,   168,   304,
     162,   128,   132,   137,   623,    27,    28,    29,    30,    31,
      32,   118,   304,   122,   340,    51,   339,     4,   502,   503,
     339,   340,   345,   390,   391,   344,   345,    51,    51,   688,
     689,   803,    55,    56,   168,    51,    71,     4,     4,   166,
     167,    97,    50,   509,    47,     4,   351,   352,   353,   368,
      97,   792,     4,   109,   359,   360,   119,   120,   305,   351,
     352,   353,    70,    71,    51,   370,    81,   359,   360,   316,
     554,   376,   117,   320,   726,   727,   728,   729,    81,   731,
     564,   623,   117,   118,   376,    51,   827,   117,    91,    97,
     117,     4,    51,     4,   706,     4,   317,   314,   319,    51,
     103,   318,     4,    63,   321,   113,   114,   110,   117,   580,
      52,     4,     4,   732,   733,   313,   735,   736,   737,   738,
     739,   740,   105,    83,   127,     4,   129,     4,   131,   105,
      90,   153,   154,   155,   156,   157,   158,   140,    51,   102,
      51,     4,    51,    27,    28,     4,   106,   147,   108,    51,
     455,   105,    14,    15,   473,   474,   475,   623,    51,    51,
     163,   105,   165,   455,    27,    28,    29,    30,    31,    32,
     117,   118,    51,   478,    51,    50,   481,   137,    29,    30,
      31,    32,    44,   117,   118,   402,   403,   404,   493,   481,
     732,   733,    51,   735,   736,   737,   738,   739,   740,    31,
      32,   493,    82,   420,    29,    30,    31,    32,   168,    73,
     275,    31,    32,   278,   685,     5,    66,   282,   138,    13,
      51,    51,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   304,
      86,    86,   136,   117,    27,    28,    29,    30,    31,    32,
     497,   123,   499,    97,   714,    33,   117,    51,   115,   578,
      12,   580,   117,   747,   117,    43,   732,   733,    51,   735,
     736,   737,   738,   739,   740,    27,    28,    29,    30,    31,
      32,   117,   117,   117,   501,    73,   591,   592,   505,   117,
     153,   154,   155,   156,   157,   158,   117,    75,    92,   604,
      78,   117,   115,    89,   609,    51,    51,   136,   613,   136,
      71,   528,   604,   530,     4,   532,   533,   609,   112,    53,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   768,   116,   556,
     557,    71,   826,     9,   561,   123,   109,    45,    97,   109,
      51,    53,    27,    28,    29,    30,    31,    32,    87,   153,
     154,   155,   156,   157,   158,    40,   685,     7,     8,   117,
     153,   154,   155,   156,   157,   158,   288,   289,   290,   291,
     292,   118,    47,   688,   689,   690,   118,    27,    18,   115,
     695,     9,   697,   117,   117,   117,   701,   117,   690,   704,
     104,    41,    42,   101,   139,     4,   711,   149,    73,   701,
      50,   104,   704,   118,   631,    10,    81,    57,    58,   711,
      60,    61,   147,    63,    11,   123,    91,    88,   117,    97,
     147,    71,   147,    45,   109,   116,   134,   135,   103,   116,
       4,   760,   768,   138,   117,   110,    86,   117,    52,   768,
     148,   149,     4,    51,   117,   117,    72,    97,    98,    99,
     117,    73,   127,   117,   129,   117,   131,    52,   108,   109,
     717,    96,    18,   113,   114,   140,    97,   117,   153,   154,
     155,   156,   157,   158,    52,   138,   805,   145,   128,   101,
      51,    51,    69,   798,    18,   164,   801,    16,   163,    31,
     165,    63,   122,   720,   307,   475,   723,   724,   829,   801,
     795,   123,   818,   828,   340,   242,   591,   822,   592,   697,
     160,   478,   134,   135,   449,   835,   166,   167,   168,   491,
     822,   284,   749,     5,     6,    93,   148,   149,    10,    11,
      12,   798,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     6,     7,   711,    -1,    -1,    -1,    12,    13,    -1,
      -1,    16,    -1,    -1,    -1,   792,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      -1,   808,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
     827,    -1,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,   147,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,   138,    -1,   140,   141,   142,    33,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,   167,   168,    -1,   170,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    16,    -1,    73,    -1,
      -1,    -1,    -1,    78,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    -1,    -1,    37,    38,    -1,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,
      60,   116,    62,    63,    64,    65,    66,    67,   123,    69,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,   167,   168,    -1,
     170,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    -1,    74,
      75,    -1,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,   167,   168,    -1,   170,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    -1,    -1,    37,    38,    -1,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    -1,    74,    75,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,   167,   168,    -1,
     170,     6,     7,    70,    71,    -1,    -1,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      97,    -1,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,   113,   114,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    -1,    74,
      75,   138,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,   167,   168,   169,   170,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    -1,    -1,    37,    38,    -1,
      40,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    -1,    74,    75,    -1,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   113,   114,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,   138,    -1,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,   167,   168,    -1,
     170,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      -1,    -1,    37,    38,    -1,    40,    -1,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    -1,    74,
      75,    -1,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,   167,   168,    -1,   170,     6,     7,    10,    11,
      12,    -1,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    27,    28,    29,    30,    31,
      32,    -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    -1,    69,
      -1,    -1,    72,    -1,    74,    75,    -1,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,     6,     7,    -1,    11,    12,   159,
      12,   161,   162,   163,    16,   165,    -1,    -1,   168,    -1,
      -1,    -1,    24,    27,    28,    29,    30,    31,    32,    -1,
      32,    33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    67,    -1,    69,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    91,
      92,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,   115,    27,    28,    29,    30,    31,    32,
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
     153,   154,   155,   156,   157,   158,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
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
      -1,   117,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,
     126,   127,    -1,    -1,   130,    -1,   132,   133,   134,   135,
     136,   137,    -1,    -1,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,    -1,   150,    -1,    -1,    -1,     6,     7,
      -1,    -1,    -1,   159,    12,   161,   162,   163,    16,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    -1,    -1,    37,
      -1,    -1,    40,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      58,    59,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      -1,    69,    -1,    -1,    72,    -1,    74,    75,    -1,    77,
      78,    79,    -1,    81,    82,    83,    84,    85,    86,    -1,
      -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,   109,   110,    -1,    -1,    -1,    -1,   115,    -1,   117,
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
      -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,   159,
      12,   161,   162,   163,    16,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,
      62,    -1,    64,    65,    66,    67,    -1,    69,    -1,    -1,
      72,    -1,    74,    75,    -1,    77,    78,    79,    -1,    81,
      82,    83,    84,    85,    86,    -1,    -1,    89,    90,    91,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,    -1,    -1,   126,   127,    -1,    -1,   130,    -1,
     132,   133,   134,   135,   136,   137,    -1,    -1,   140,   141,
     142,    -1,   144,   145,   146,   147,   148,    -1,   150,    -1,
      -1,    -1,     6,     7,    -1,    -1,    -1,   159,    12,   161,
     162,   163,    16,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    58,    59,    -1,    -1,    62,    -1,
      64,    65,    66,    67,    -1,    69,    -1,    -1,    72,    -1,
      74,    75,    -1,    77,    78,    79,    -1,    81,    82,    83,
      84,    85,    86,    -1,    -1,    89,    90,    91,    92,    93,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
      -1,    -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,
     134,   135,   136,   137,    -1,    -1,   140,   141,   142,    -1,
     144,   145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,   159,    12,   161,   162,   163,
      16,   165,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      27,    28,    29,    30,    31,    32,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    51,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    58,    59,    -1,    -1,    62,    -1,    64,    65,
      66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,    75,
      -1,    77,    78,    79,    -1,    81,    82,    83,    84,    85,
      86,    -1,    -1,    89,    90,    91,    92,    93,    27,    28,
      29,    30,    31,    32,   100,   101,   102,   103,   104,   105,
     106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    51,    -1,    -1,    -1,   122,   123,    -1,    -1,
     126,   127,    -1,    -1,   130,    -1,   132,   133,   134,   135,
     136,   137,    -1,    -1,   140,   141,   142,    -1,   144,   145,
     146,   147,   148,    -1,   150,    -1,   153,   154,   155,   156,
     157,   158,    -1,   159,    -1,   161,   162,   163,    13,   165,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     5,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,   158,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,    50,
      27,    28,    29,    30,    31,    32,    -1,    92,    -1,    60,
      61,    -1,    63,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      71,    -1,    -1,   406,    51,    -1,   409,   112,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
     423,   424,    -1,    -1,    -1,    -1,    97,    98,    99,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,   108,   109,    -1,
      -1,    -1,   113,   114,    -1,    -1,   117,    -1,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,   146,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   153,   154,
     155,   156,   157,   158,    -1,    -1,   153,   154,   155,   156,
     157,   158,   515,   516,    49,   518,    -1,   520,   521,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    64,
      -1,    -1,    -1,    -1,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    10,
      11,    12,   107,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,    -1,    -1,    -1,   141,   142,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,     4,     5,     6,   161,    -1,    69,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    52,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    -1,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
      -1,    -1,    -1,    10,    11,    12,    51,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    51,    14,    15,    16,    17,    18,
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
       0,    59,   172,   173,     8,   109,     0,    65,   174,   175,
      73,    73,     8,    85,   126,   162,   176,   177,    93,   182,
     183,   109,   179,   180,   109,   178,   118,   180,    73,   177,
     132,   184,   185,   122,   186,   187,     4,    49,    60,    62,
      64,    79,    85,    94,    95,   107,   141,   142,   161,   181,
      97,   285,   181,    81,    73,   185,    45,   101,   123,   134,
     135,   148,   149,   188,   189,   133,   138,   190,   191,   192,
     245,   180,   117,   117,   117,   117,    52,   180,   105,   105,
     102,   147,   105,   105,    50,   286,    73,   189,   286,   246,
      82,   194,    73,   139,    73,   181,   285,   285,   285,   285,
     180,     5,   285,   285,   285,    80,   130,   286,   285,   285,
      66,   193,    35,    68,   152,   253,    33,    43,    75,    78,
     116,   123,   196,   197,   245,    51,     4,    51,     4,    51,
      51,   181,   286,   286,   286,   286,   119,   120,   200,   201,
       6,     7,    12,    16,    24,    30,    32,    33,    34,    37,
      38,    40,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    54,    57,    58,    59,    60,    62,    63,    64,    65,
      66,    67,    69,    70,    71,    72,    74,    75,    77,    78,
      79,    81,    82,    83,    84,    85,    86,    89,    90,    91,
      92,    93,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   113,   114,   115,   117,
     122,   123,   126,   127,   130,   132,   133,   134,   135,   136,
     137,   140,   141,   142,   144,   145,   146,   147,   148,   150,
     159,   160,   161,   162,   163,   165,   166,   167,   168,   170,
     203,   244,   254,   255,   258,   287,   288,    86,    86,   136,
     123,    75,   100,    89,   150,    73,   195,   197,   285,   285,
     202,    50,    97,   206,   207,   208,   238,   239,   240,   242,
     287,   117,   117,   117,   117,   117,   287,    97,   117,   258,
     117,   117,   117,   117,     4,    84,   214,    27,    28,    29,
      30,    31,    32,    40,   109,   153,   154,   155,   156,   157,
     158,   257,   262,    71,   117,   118,   115,   115,    73,    89,
     136,   136,    47,    81,    91,   103,   110,   127,   129,   131,
     140,   163,   165,   267,   268,   269,   271,   273,   275,   278,
     279,   280,   282,   283,   284,   267,    51,    51,   206,    71,
       4,    37,    67,   209,    71,    53,   118,   241,    35,    68,
     152,   237,   237,   237,   258,   265,   265,   265,    51,   237,
     237,   265,   169,   258,   259,   255,   215,   217,   238,   287,
       9,   213,   219,    27,    28,   263,   264,   263,   263,   263,
     263,   263,   109,    30,   287,   265,   285,    97,   109,   198,
     199,   199,   267,   267,   267,    60,    63,   108,   168,   270,
     287,   180,     7,     8,    27,    41,    42,    50,    57,    58,
      60,    61,    63,    86,    97,    98,    99,   108,   109,   114,
     117,   128,   160,   166,   167,   168,   198,   244,   290,   292,
     294,   299,   109,   285,   286,   276,   277,   294,   198,   286,
     147,   285,   294,   267,   268,   240,   287,   207,    30,   287,
     240,    97,   258,   258,   258,     4,    51,    51,    51,   258,
     258,    51,     4,    63,    83,    90,   106,   108,   137,   168,
     260,     4,    51,     4,    55,    56,   243,   287,    13,    76,
     111,   117,   222,   223,   224,   225,   226,   227,   231,   234,
     236,   252,   258,    87,   211,   220,   258,   118,    51,     4,
      52,   118,   267,   267,   117,    18,   294,   294,   294,   115,
     291,   291,   291,   117,   117,    41,    42,    57,    58,   128,
     166,   167,   117,   117,   294,   291,   291,   117,     9,   289,
       5,     6,    10,    11,    12,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   146,   296,    18,   118,   104,   139,
     281,     4,   149,   104,    69,    73,   241,     4,    52,    51,
      51,    51,   258,    51,    51,   260,   147,   260,   121,   217,
     117,   215,   216,   216,   225,   117,   252,   252,   138,   222,
     258,    10,    11,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   235,    13,    92,   112,   233,   235,
     212,   256,   258,    88,   210,   221,   285,   285,   294,   294,
     297,   298,   294,    27,    60,    61,    63,    98,    99,   108,
     109,   117,   160,   168,   198,   293,   299,   298,   298,   291,
     291,   291,   291,   291,   298,   298,    51,   298,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   268,
     277,   294,   294,   268,    97,   147,    63,    83,    90,   106,
     108,   137,   168,   261,   147,   117,   217,   215,   116,   116,
     253,    51,   223,   224,   258,   117,   252,   117,   252,    14,
      15,    44,    35,    36,   117,   143,   228,   229,   230,   252,
     258,     4,   222,   119,   151,   204,   249,     4,    52,    52,
       4,    52,    51,     4,   147,   293,   117,   117,   117,   117,
     294,   117,    10,    11,    12,    27,    28,    29,    30,    31,
      32,   295,    51,    51,    51,    51,    51,    72,   274,     4,
      52,    52,   261,   117,   261,   215,    51,   222,   222,   254,
      70,   203,   232,   266,   232,   258,   252,   256,   205,   237,
      96,   247,   285,   294,   294,   294,   298,   298,   298,   298,
      51,   298,   293,   293,   293,   293,   293,   293,   293,   293,
     268,   294,    18,    97,    51,   214,   218,   287,     4,    51,
      51,    11,   206,   138,   248,   145,    52,    52,   144,   272,
      51,    51,    51,    51,    51,    52,   277,    51,   219,    51,
     266,   258,   253,   251,   287,   294,    69,    18,   220,   254,
     164,   250,   268,   277,   221,   218,   249
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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

/* Line 1464 of yacc.c  */
#line 250 "ace.yacc"
    {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 253 "ace.yacc"
    {
		this_report.dbname=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_init_connection ((yyvsp[(2) - (3)].str));
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 277 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 281 "ace.yacc"
    {
		ace_add_variable((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str),CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 284 "ace.yacc"
    {
		ace_add_variable((yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str),CAT_PARAM,atoi((yyvsp[(3) - (6)].str)),-1,0);
	}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 287 "ace.yacc"
    {
		add_function((yyvsp[(2) - (2)].str));
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 298 "ace.yacc"
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

/* Line 1464 of yacc.c  */
#line 311 "ace.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 312 "ace.yacc"
    {strcpy((yyval.str),"CHAR");}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 313 "ace.yacc"
    {SPRINTF1((yyval.str),"CHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 314 "ace.yacc"
    {strcpy((yyval.str),"VARCHAR");}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 315 "ace.yacc"
    {SPRINTF1((yyval.str),"VARCHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 316 "ace.yacc"
    {strcpy((yyval.str),"DATE");}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 317 "ace.yacc"
    {strcpy((yyval.str),"FLOAT");}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 318 "ace.yacc"
    {strcpy((yyval.str),"SMALLFLOAT");}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 319 "ace.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 320 "ace.yacc"
    {strcpy((yyval.str),"DATETIME");}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 321 "ace.yacc"
    {strcpy((yyval.str),"INTERVAL");}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 322 "ace.yacc"
    {strcpy((yyval.str),"MONEY");}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 323 "ace.yacc"
    {SPRINTF1((yyval.str),"MONEY (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 324 "ace.yacc"
    {SPRINTF2((yyval.str),"MONEY (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 325 "ace.yacc"
    {strcpy((yyval.str),"DECIMAL");}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 326 "ace.yacc"
    {SPRINTF1((yyval.str),"DECIMAL (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 327 "ace.yacc"
    {SPRINTF2((yyval.str),"DECIMAL (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 341 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes((yyvsp[(5) - (5)].str)),(yyvsp[(3) - (5)].str));
}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 356 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str));}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 357 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 358 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup((yyvsp[(3) - (3)].str)); }
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 359 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str)); }
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 360 "ace.yacc"
    {
		this_report.output.left_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 363 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 366 "ace.yacc"
    {
		this_report.output.top_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 369 "ace.yacc"
    {
		this_report.output.page_length=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 372 "ace.yacc"
    {
		this_report.output.right_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 375 "ace.yacc"
    {
		this_report.output.top_of_page=acl_strdup((yyvsp[(2) - (2)].str));
	}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 382 "ace.yacc"
    { execute_selects(); }
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 398 "ace.yacc"
    {
		struct acerep_commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,NULL,cmd);
	  }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 417 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 421 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 425 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 429 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 432 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 435 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 438 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 445 "ace.yacc"
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

/* Line 1464 of yacc.c  */
#line 455 "ace.yacc"
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

/* Line 1464 of yacc.c  */
#line 465 "ace.yacc"
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

/* Line 1464 of yacc.c  */
#line 480 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 484 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 492 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 495 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 495 "ace.yacc"
    {
	printf("speclist : %s ",(yyvsp[(3) - (3)].str));
	SPRINTF1((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str));}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 499 "ace.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 508 "ace.yacc"
    {
		SPRINTF1((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 518 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 518 "ace.yacc"
    { SPRINTF1((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str)); }
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 523 "ace.yacc"
    {
SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 528 "ace.yacc"
    {
		if (strlen((yyvsp[(2) - (2)].str))) {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 534 "ace.yacc"
    {
		char buff[256];
		SPRINTF1(buff,"I%d",atoi((yyvsp[(1) - (1)].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 539 "ace.yacc"
    {
		char buff[256];
		SPRINTF1(buff,"C%s",(yyvsp[(1) - (1)].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 548 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 556 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 562 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 568 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 573 "ace.yacc"
    {SPRINTF1((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[(2) - (2)].str));}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 578 "ace.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 582 "ace.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 583 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
        }
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 586 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s, OUTER %s",(yyvsp[(1) - (4)].str),(yyvsp[(4) - (4)].str));
        }
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 589 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s, OUTER (%s)",(yyvsp[(1) - (6)].str),(yyvsp[(5) - (6)].str));
        }
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 592 "ace.yacc"
    {
		SPRINTF3((yyval.str),"%s LEFT OUTER JOIN %s ON %s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 595 "ace.yacc"
    {
		SPRINTF3((yyval.str),"%s INNER JOIN %s ON %s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 600 "ace.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); }
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 601 "ace.yacc"
    {SPRINTF1((yyval.str),"(%s)",(yyvsp[(2) - (3)].str)); }
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 606 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		ace_add_table((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 616 "ace.yacc"
    { 
		SPRINTF4((yyval.str),"%s %s %s %s", (yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 621 "ace.yacc"
    {strcpy((yyval.str),"\n0");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 625 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 629 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 636 "ace.yacc"
    {
			SPRINTF3((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 644 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 650 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 656 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 661 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 662 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 668 "ace.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 670 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 695 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 697 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 699 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 701 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 708 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 711 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 718 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 720 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 722 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 724 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 726 "ace.yacc"
    {SPRINTF6((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 740 "ace.yacc"
    {SPRINTF0((yyval.str),"<=");}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 741 "ace.yacc"
    {SPRINTF0((yyval.str),">=");}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 751 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 765 "ace.yacc"
    { SPRINTF1((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[(1) - (1)].str))); }
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 766 "ace.yacc"
    {SPRINTF0((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 767 "ace.yacc"
    { SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 768 "ace.yacc"
    { SPRINTF3((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[(1) - (3)].str)),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 778 "ace.yacc"
    {SPRINTF0((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 782 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 783 "ace.yacc"
    {SPRINTF1((yyval.str),"[%s]",(yyvsp[(2) - (3)].str));}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 784 "ace.yacc"
    {SPRINTF2((yyval.str),"[%s,%s]",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 787 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 788 "ace.yacc"
    { SPRINTF3((yyval.str),"%s.%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); }
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 789 "ace.yacc"
    { SPRINTF2((yyval.str),"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 800 "ace.yacc"
    {SPRINTF1((yyval.str),"0.%s",(yyvsp[(2) - (2)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 806 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 807 "ace.yacc"
    {
		char buff[100000];
		SPRINTF4(buff,"%s %s %s %s",(yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str),(yyvsp[(4) - (10)].str),(yyvsp[(5) - (10)].str));
		SPRINTF9((yyval.str),"%s %s %s %s %s %s %s %s %s",(yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str),(yyvsp[(4) - (10)].str),(yyvsp[(5) - (10)].str),(yyvsp[(6) - (10)].str),(yyvsp[(7) - (10)].str),(yyvsp[(8) - (10)].str),(yyvsp[(9) - (10)].str),(yyvsp[(10) - (10)].str));
 		add_select((yyval.str),buff, temp_tab_name,(yyvsp[(10) - (10)].str),(yyvsp[(7) - (10)].str)); 
	}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 816 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 818 "ace.yacc"
    {
       		SPRINTF2((yyval.str),"INTO TEMP %s%s ",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
		strcpy(temp_tab_name,(yyvsp[(3) - (4)].str));
	}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 828 "ace.yacc"
    {SPRINTF5((yyval.str),"%s %s %s %s %s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str) );}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 832 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 833 "ace.yacc"
    { SPRINTF3((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 846 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 846 "ace.yacc"
    {strcpy((yyval.str)," WITH NO LOG");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 857 "ace.yacc"
    {SPRINTF6((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 860 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 861 "ace.yacc"
    {SPRINTF0((yyval.str),"ALL");}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 862 "ace.yacc"
    {SPRINTF0((yyval.str),"DISTINCT");}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 863 "ace.yacc"
    {SPRINTF0((yyval.str),"DISTINCT");}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 868 "ace.yacc"
    { SPRINTF2((yyval.str)," %s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 872 "ace.yacc"
    {
			if (strcmp((yyvsp[(1) - (1)].str),"rowid")==0) {
				SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
				add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
			} else {
				add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
			}
		}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 880 "ace.yacc"
    {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_select_column((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 884 "ace.yacc"
    {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
			add_select_column((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 895 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS YEAR");}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 896 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS MONTH"); }
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 897 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS DAY);"); }
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 898 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS HOUR);"); }
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 899 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS MINUTE);"); }
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 900 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS SECOND);"); }
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 904 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s", (yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 907 "ace.yacc"
    {SPRINTF2((yyval.str)," %s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 908 "ace.yacc"
    {SPRINTF3((yyval.str)," %s[%s,%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 909 "ace.yacc"
    {SPRINTF3((yyval.str)," %s.%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 910 "ace.yacc"
    {SPRINTF4((yyval.str)," %s.%s[%s,%s]",(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str));}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 911 "ace.yacc"
    {
			if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
			SPRINTF1((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
			}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 916 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 918 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 922 "ace.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 923 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 924 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 925 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 926 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 927 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 928 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 929 "ace.yacc"
    {SPRINTF2((yyval.str),"%s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 931 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 933 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 935 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 937 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 939 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 943 "ace.yacc"
    {
			SPRINTF2((yyval.str),"CURRENT, %s TO %s",(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 946 "ace.yacc"
    {
			SPRINTF3((yyval.str),"%s, %s TO %s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 949 "ace.yacc"
    {
			SPRINTF3((yyval.str),"%s %s TO %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
        }
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 955 "ace.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 961 "ace.yacc"
    {SPRINTF1((yyval.str),"/%s",(yyvsp[(2) - (2)].str));}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 962 "ace.yacc"
    {SPRINTF1((yyval.str)," MOD %s",(yyvsp[(2) - (2)].str));}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 963 "ace.yacc"
    {SPRINTF1((yyval.str)," POW %s",(yyvsp[(2) - (2)].str));}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 964 "ace.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 965 "ace.yacc"
    {SPRINTF1((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 966 "ace.yacc"
    {SPRINTF1((yyval.str),"+%s",(yyvsp[(2) - (2)].str));}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 967 "ace.yacc"
    {SPRINTF1((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 970 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 973 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 974 "ace.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 975 "ace.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 980 "ace.yacc"
    {
	SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 987 "ace.yacc"
    {
                        if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
                        SPRINTF1((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
                        }
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1003 "ace.yacc"
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct acerep_command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[(1) - (1)].cmd));
		}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1008 "ace.yacc"
    {
		COPY((yyval.commands),(yyvsp[(1) - (2)].commands));
		(yyval.commands).commands.commands_len++;
		(yyval.commands).commands.commands_val=realloc(
		(yyval.commands).commands.commands_val,
		(yyval.commands).commands.commands_len*sizeof(struct acerep_command));
		COPY((yyval.commands).commands.commands_val[ (yyval.commands).commands.commands_len-1 ],(yyvsp[(2) - (2)].cmd));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1030 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).acerep_command_u.acerep_commands.commands.commands_val=(yyvsp[(2) - (3)].commands).commands.commands_val;
		(yyval.cmd).acerep_command_u.acerep_commands.commands.commands_len=(yyvsp[(2) - (3)].commands).commands.commands_len;
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1040 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).acerep_command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[(2) - (5)].str));
	
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(4) - (5)].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr);
}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 1058 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_FOR;
		(yyval.cmd).acerep_command_u.cmd_for.varid=find_variable((yyvsp[(2) - (9)].str));
		COPY((yyval.cmd).acerep_command_u.cmd_for.start,(yyvsp[(4) - (9)].expr));
		COPY((yyval.cmd).acerep_command_u.cmd_for.finish,(yyvsp[(6) - (9)].expr));
		COPY((yyval.cmd).acerep_command_u.cmd_for.step,(yyvsp[(7) - (9)].expr));
		(yyval.cmd).acerep_command_u.cmd_for.command=(struct acerep_command *)DUP((yyvsp[(9) - (9)].cmd));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 1068 "ace.yacc"
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 1069 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (2)].expr));}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 1073 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_IF;
	COPY((yyval.cmd).acerep_command_u.cmd_if.condition,(yyvsp[(2) - (5)].expr));
	(yyval.cmd).acerep_command_u.cmd_if.command=(struct acerep_command *)DUP((yyvsp[(4) - (5)].cmd));
	(yyval.cmd).acerep_command_u.cmd_if.elsecommand=(struct acerep_command *)DUP((yyvsp[(5) - (5)].cmd));
}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 1081 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).acerep_command_u.null=1;
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 1084 "ace.yacc"
    { COPY((yyval.cmd),(yyvsp[(2) - (2)].cmd)); }
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 1089 "ace.yacc"
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

  case 301:

/* Line 1464 of yacc.c  */
#line 1100 "ace.yacc"
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

  case 302:

/* Line 1464 of yacc.c  */
#line 1111 "ace.yacc"
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

  case 303:

/* Line 1464 of yacc.c  */
#line 1124 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 1131 "ace.yacc"
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 1143 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).acerep_command_u.cmd_need.nlines=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 1149 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).acerep_command_u.cmd_pause.message=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 1156 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).acerep_command_u.cmd_print.printnl=atoi((yyvsp[(3) - (3)].str));
	(yyval.cmd).acerep_command_u.cmd_print.print=(yyvsp[(2) - (3)].expr);
}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 1164 "ace.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 1164 "ace.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 1167 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename_expr.type=EXPRTYPE_STRING;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename_expr.expr_u.s=acl_strdup((yyvsp[(2) - (2)].str));
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 1172 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename_expr.type=EXPRTYPE_VARIABLE_SUB;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename_expr.expr_u.var_usage=(yyvsp[(2) - (2)].var_usage);
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 1180 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).acerep_command_u.cmd_skip.nlines=atoi((yyvsp[(2) - (3)].str));

	}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 1185 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).acerep_command_u.cmd_skip.nlines=-1;
	}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 1192 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		COPY((yyval.cmd).acerep_command_u.cmd_while.condition,(yyvsp[(2) - (4)].expr));
		(yyval.cmd).acerep_command_u.cmd_while.command=(struct acerep_command *)DUP((yyvsp[(4) - (4)].cmd));
}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 1300 "ace.yacc"
    {
			(yyval.exprptr)=0;
		}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 1304 "ace.yacc"
    { 
			(yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); 
		}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 1311 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (2)].agg_val));
		(yyval.agg_val).wexpr=(yyvsp[(2) - (2)].exprptr); 
		}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 1319 "ace.yacc"
    { (yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 1323 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 1329 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 1335 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 1341 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 1347 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 1353 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 1359 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 1366 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 1372 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 1378 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 1384 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 1390 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 1396 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 1402 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 1412 "ace.yacc"
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

  case 418:

/* Line 1464 of yacc.c  */
#line 1430 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 1432 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 1436 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 1440 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 1444 "ace.yacc"
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

  case 423:

/* Line 1464 of yacc.c  */
#line 1453 "ace.yacc"
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

  case 424:

/* Line 1464 of yacc.c  */
#line 1463 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 1470 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 1476 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 1482 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 1489 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 1495 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 1496 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 1501 "ace.yacc"
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

  case 432:

/* Line 1464 of yacc.c  */
#line 1523 "ace.yacc"
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

  case 433:

/* Line 1464 of yacc.c  */
#line 1541 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 1543 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 1547 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 1551 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 1555 "ace.yacc"
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

  case 438:

/* Line 1464 of yacc.c  */
#line 1564 "ace.yacc"
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

  case 439:

/* Line 1464 of yacc.c  */
#line 1574 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 1581 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 1587 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 1593 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 1600 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 1606 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 1607 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 1613 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 447:

/* Line 1464 of yacc.c  */
#line 1619 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 448:

/* Line 1464 of yacc.c  */
#line 1624 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 1629 "ace.yacc"
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

  case 450:

/* Line 1464 of yacc.c  */
#line 1651 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 1659 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 1667 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 1675 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 1682 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 1691 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 1697 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 1706 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 1713 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 1722 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 1730 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 1738 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 1746 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 1753 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 1762 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 1768 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 1777 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 1784 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 1792 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 1798 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 1804 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 1810 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 1816 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 1822 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 1828 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 1834 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 1840 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 1846 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 1852 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 1860 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_SPACES; 
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 1867 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 1873 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 1881 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 1891 "ace.yacc"
    {
		struct expr nullexpr;

		nullexpr.type=EXPRTYPE_NULL;


		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc(
			(yyval.expr).expr_u.lexpr->elem.elem_val,
			sizeof(struct expr)*(yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],nullexpr);
		print_lexpr((yyval.expr).expr_u.lexpr);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 1907 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 1914 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 1921 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 1932 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 1936 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 1940 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 1944 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;



/* Line 1464 of yacc.c  */
#line 6004 "y.tab.c"
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



/* Line 1684 of yacc.c  */
#line 1952 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

