
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
#line 539 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 551 "y.tab.c"

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
#define YYLAST   3836

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  129
/* YYNRULES -- Number of rules.  */
#define YYNRULES  489
/* YYNRULES -- Number of states.  */
#define YYNSTATES  835

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
     585,   587,   593,   594,   598,   600,   605,   611,   612,   614,
     616,   623,   624,   626,   628,   630,   632,   636,   638,   641,
     645,   647,   649,   651,   653,   655,   657,   659,   662,   664,
     666,   671,   678,   685,   694,   697,   701,   705,   707,   709,
     711,   713,   718,   722,   727,   732,   737,   742,   747,   753,
     759,   765,   771,   777,   783,   789,   794,   796,   798,   800,
     802,   804,   806,   808,   810,   812,   814,   816,   818,   820,
     822,   827,   830,   833,   836,   838,   841,   844,   847,   850,
     851,   853,   855,   857,   861,   863,   865,   868,   870,   872,
     874,   876,   878,   880,   882,   884,   886,   888,   892,   898,
     900,   902,   904,   906,   908,   918,   919,   922,   928,   929,
     932,   937,   945,   955,   956,   958,   960,   964,   968,   971,
     975,   976,   978,   981,   985,   989,   994,   996,   998,  1000,
    1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1018,  1020,
    1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,
    1042,  1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,
    1062,  1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,
    1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,  1098,  1100,
    1102,  1104,  1106,  1108,  1110,  1112,  1114,  1116,  1118,  1120,
    1122,  1124,  1126,  1128,  1130,  1132,  1134,  1136,  1138,  1140,
    1142,  1144,  1146,  1148,  1150,  1152,  1154,  1156,  1158,  1159,
    1162,  1165,  1168,  1170,  1172,  1175,  1178,  1181,  1184,  1187,
    1190,  1193,  1197,  1201,  1205,  1209,  1213,  1216,  1218,  1220,
    1222,  1224,  1226,  1228,  1233,  1238,  1243,  1248,  1253,  1257,
    1259,  1262,  1265,  1267,  1269,  1271,  1273,  1275,  1277,  1282,
    1287,  1292,  1297,  1302,  1306,  1309,  1312,  1314,  1316,  1319,
    1322,  1325,  1328,  1331,  1334,  1337,  1340,  1343,  1345,  1348,
    1351,  1354,  1357,  1360,  1363,  1366,  1369,  1372,  1375,  1378,
    1381,  1384,  1387,  1390,  1393,  1396,  1399,  1402,  1405,  1407,
    1409,  1411,  1413,  1414,  1416,  1418,  1422,  1424,  1426,  1428
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
     253,   254,   218,   249,    -1,   248,    -1,   138,   253,   254,
     218,   249,    -1,    -1,   151,   237,   247,    -1,   204,    -1,
      96,   145,   251,   250,    -1,   204,    96,   145,   251,   250,
      -1,    -1,   164,    -1,   287,    -1,   117,   138,   253,   254,
     218,    51,    -1,    -1,    35,    -1,    68,    -1,   152,    -1,
     255,    -1,   254,     4,   255,    -1,   258,    -1,   258,   109,
      -1,   258,    40,   109,    -1,   258,    -1,   158,    -1,   156,
      -1,   153,    -1,   154,    -1,   155,    -1,   157,    -1,   258,
     262,    -1,   203,    -1,   287,    -1,   287,   118,   285,    52,
      -1,   287,   118,   285,     4,   285,    52,    -1,   287,    71,
     287,   118,   285,    52,    -1,   287,    71,   287,   118,   285,
       4,   285,    52,    -1,    70,   287,    -1,   287,    71,   287,
      -1,   287,    71,    30,    -1,    99,    -1,    98,    -1,   160,
      -1,    30,    -1,   170,   117,   259,    51,    -1,   117,   258,
      51,    -1,    60,   117,   265,    51,    -1,    63,   117,   265,
      51,    -1,   108,   117,   265,    51,    -1,   168,   117,   265,
      51,    -1,   287,   117,   265,    51,    -1,    42,   117,   237,
     258,    51,    -1,   166,   117,   237,   258,    51,    -1,   167,
     117,   237,   258,    51,    -1,    38,   117,   237,   258,    51,
      -1,    57,   117,   237,   258,    51,    -1,   169,     4,   260,
     147,   261,    -1,   258,     4,   260,   147,   261,    -1,   169,
     260,   147,   261,    -1,   168,    -1,   108,    -1,    63,    -1,
      90,    -1,   106,    -1,   137,    -1,    83,    -1,   168,    -1,
     108,    -1,    63,    -1,    90,    -1,   106,    -1,   137,    -1,
      83,    -1,    83,   117,    97,    51,    -1,    29,   263,    -1,
      31,   263,    -1,    32,   263,    -1,   257,    -1,    30,   263,
      -1,    28,   263,    -1,    27,   263,    -1,   264,   258,    -1,
      -1,    28,    -1,    27,    -1,   258,    -1,   265,     4,   258,
      -1,   203,    -1,   268,    -1,   267,   268,    -1,   271,    -1,
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
      -1,   140,   285,   104,    -1,   140,   147,   149,    -1,   163,
     294,    69,   268,    -1,    97,    -1,    50,    -1,   109,    -1,
     288,    -1,    33,    -1,    37,    -1,    34,    -1,    40,    -1,
      43,    -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,
      48,    -1,    49,    -1,    12,    -1,     7,    -1,    54,    -1,
      16,    -1,    59,    -1,    62,    -1,    64,    -1,    65,    -1,
      66,    -1,    67,    -1,    69,    -1,    72,    -1,    74,    -1,
      75,    -1,    77,    -1,    78,    -1,    79,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      89,    -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,
     100,    -1,   101,    -1,   102,    -1,   103,    -1,    24,    -1,
     104,    -1,   105,    -1,   106,    -1,   107,    -1,   110,    -1,
     115,    -1,   122,    -1,   123,    -1,   126,    -1,   127,    -1,
      32,    -1,   130,    -1,   132,    -1,   133,    -1,   134,    -1,
     135,    -1,   136,    -1,   137,    -1,   140,    -1,   141,    -1,
     142,    -1,     6,    -1,   144,    -1,   145,    -1,   146,    -1,
     147,    -1,   148,    -1,    58,    -1,   150,    -1,   159,    -1,
     161,    -1,   162,    -1,   163,    -1,   165,    -1,    -1,     9,
     294,    -1,   292,   289,    -1,   115,   293,    -1,    57,    -1,
     128,    -1,    41,   291,    -1,    58,   291,    -1,    42,   291,
      -1,   167,   291,    -1,   166,   291,    -1,    86,    57,    -1,
      86,   128,    -1,    86,    41,   291,    -1,    86,    58,   291,
      -1,    86,    42,   291,    -1,    86,   167,   291,    -1,    86,
     166,   291,    -1,    27,   293,    -1,   299,    -1,    99,    -1,
      98,    -1,   160,    -1,    60,    -1,    61,    -1,    60,   117,
     298,    51,    -1,   108,   117,   298,    51,    -1,   168,   117,
     298,    51,    -1,    63,   117,   298,    51,    -1,   109,   117,
     298,    51,    -1,   117,   294,    51,    -1,   198,    -1,   293,
     295,    -1,    27,   294,    -1,   299,    -1,    99,    -1,    98,
      -1,   160,    -1,    60,    -1,    61,    -1,    60,   117,   298,
      51,    -1,   108,   117,   298,    51,    -1,   168,   117,   298,
      51,    -1,    63,   117,   298,    51,    -1,   109,   117,   298,
      51,    -1,   117,   294,    51,    -1,     7,   294,    -1,     8,
     294,    -1,   198,    -1,   290,    -1,   294,   296,    -1,    11,
     293,    -1,    10,   293,    -1,    29,   293,    -1,    32,   293,
      -1,    31,   293,    -1,    30,   293,    -1,    28,   293,    -1,
      27,   293,    -1,    12,    -1,    11,   294,    -1,    10,   294,
      -1,    29,   294,    -1,    32,   294,    -1,    31,   294,    -1,
      30,   294,    -1,    28,   294,    -1,    27,   294,    -1,     5,
     294,    -1,    18,   294,    -1,    16,   294,    -1,    17,   294,
      -1,    20,   294,    -1,    22,   294,    -1,    25,   294,    -1,
      23,   294,    -1,    26,   294,    -1,    24,   294,    -1,    19,
     294,    -1,    21,   294,    -1,     6,    -1,    14,    -1,    15,
      -1,    12,    -1,    -1,   298,    -1,   294,    -1,   298,     4,
     294,    -1,    50,    -1,   114,    -1,   244,    -1,    97,    -1
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
     589,   592,   595,   600,   601,   605,   606,   616,   627,   628,
     631,   632,   635,   636,   641,   642,   648,   649,   654,   655,
     660,   661,   667,   668,   673,   675,   682,   683,   686,   690,
     691,   700,   702,   704,   706,   712,   713,   717,   718,   723,
     725,   727,   729,   731,   737,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   752,   753,   754,   755,   757,
     758,   759,   760,   771,   772,   773,   774,   780,   784,   788,
     789,   790,   793,   794,   795,   801,   806,   806,   812,   812,
     821,   824,   831,   832,   835,   836,   840,   848,   848,   852,
     858,   862,   863,   864,   865,   869,   870,   874,   882,   886,
     893,   897,   898,   899,   900,   901,   902,   906,   907,   908,
     909,   910,   911,   912,   913,   917,   919,   921,   922,   923,
     924,   925,   926,   927,   928,   929,   930,   931,   932,   934,
     936,   938,   940,   945,   948,   951,   956,   956,   956,   956,
     956,   956,   956,   957,   957,   957,   957,   957,   957,   957,
     957,   963,   964,   965,   966,   967,   968,   969,   972,   975,
     976,   977,   981,   981,   988,  1000,  1005,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1037,  1048,
    1049,  1050,  1051,  1052,  1055,  1065,  1066,  1070,  1078,  1081,
    1086,  1097,  1108,  1121,  1125,  1128,  1128,  1140,  1146,  1153,
    1161,  1161,  1164,  1170,  1175,  1182,  1191,  1194,  1198,  1199,
    1204,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1290,  1293,
    1300,  1309,  1313,  1319,  1325,  1331,  1337,  1343,  1349,  1356,
    1362,  1368,  1374,  1380,  1386,  1392,  1402,  1420,  1422,  1426,
    1430,  1434,  1443,  1453,  1460,  1466,  1472,  1479,  1485,  1486,
    1491,  1513,  1531,  1533,  1537,  1541,  1545,  1554,  1564,  1571,
    1577,  1583,  1590,  1596,  1597,  1603,  1609,  1614,  1619,  1641,
    1649,  1656,  1664,  1671,  1680,  1687,  1696,  1703,  1712,  1720,
    1727,  1735,  1742,  1751,  1758,  1767,  1774,  1782,  1788,  1794,
    1800,  1806,  1812,  1818,  1824,  1830,  1836,  1842,  1850,  1857,
    1863,  1871,  1881,  1897,  1904,  1911,  1922,  1926,  1930,  1934
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
  "select_statement2", "select_statement2_1", "sel_p2", "op_no_log",
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
     247,   248,   249,   249,   249,   249,   249,   250,   250,   251,
     252,   253,   253,   253,   253,   254,   254,   255,   255,   255,
     256,   257,   257,   257,   257,   257,   257,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   259,   259,   259,   260,   260,   260,   260,
     260,   260,   260,   261,   261,   261,   261,   261,   261,   261,
     261,   262,   262,   262,   262,   262,   262,   262,   263,   264,
     264,   264,   265,   265,   266,   267,   267,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   269,   270,
     270,   270,   270,   270,   271,   272,   272,   273,   274,   274,
     275,   275,   275,   276,   276,   277,   277,   278,   279,   280,
     281,   281,   282,   283,   283,   284,   285,   286,   287,   287,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   289,   289,
     290,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   297,   297,   298,   298,   299,   299,   299,   299
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
       1,     4,     3,     4,     4,     4,     4,     4,     5,     5,
       5,     5,     5,     5,     5,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     2,     2,     1,     2,     2,     2,     2,     0,
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
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       2,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     3,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     3,     2,     2,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     0,     1,     1,     3,     1,     1,     1,     1
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
     316,     0,    11,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,   188,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   317,    56,    44,    46,    62,   201,
       0,     2,    58,     0,    57,    16,     0,     0,     0,     0,
       0,     0,    52,    51,    54,     0,    48,    49,    55,    53,
       0,    82,   202,   203,   204,     0,     0,     0,     0,     0,
       0,     0,    66,    68,    60,    21,     0,    34,     0,    31,
      23,    12,    41,    50,    47,    63,    84,     0,    61,    83,
     385,   332,   331,   334,   363,   230,   374,   320,   322,   321,
       0,   323,     0,   324,   325,   326,   327,   328,   329,   330,
      87,   333,     0,   391,   335,     0,   336,     0,   337,   338,
     339,   340,   341,     0,     0,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,    90,   228,   227,   359,   360,   361,   362,   364,
     365,   366,   367,     0,   318,   368,   186,    88,   369,     0,
     370,   371,   372,   373,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   386,   387,   388,   389,   390,   392,
     393,   229,   394,   395,   396,   397,     0,     0,     0,     0,
     218,    89,     0,   205,   207,   219,   319,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    65,    69,     0,     0,
       0,   173,    96,    86,    93,    98,     0,     0,   174,    97,
     179,   169,   169,   169,     0,     0,   224,   187,     0,     0,
     169,   169,     0,     0,     0,     0,   118,   192,   269,   269,
     269,   269,   269,   269,     0,   208,   213,   214,   215,   212,
     216,   211,   264,   217,     0,     0,     0,     0,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   303,
       0,     0,     0,     0,    72,   275,   286,   277,   278,   280,
     281,   282,   284,   285,   283,   279,    71,    35,    32,    85,
       0,     0,    99,   100,    95,     0,     0,     0,   182,   170,
     171,   172,     0,     0,     0,   272,     0,     0,     0,   232,
       0,     0,     0,     0,     0,     0,   206,   106,   107,   115,
     178,     0,   119,   120,     0,    91,   169,   194,   189,   271,
     270,   267,     0,   266,   261,   265,   262,   263,   209,   226,
     225,     0,     0,    81,    79,    80,     0,     0,    70,    73,
      74,   289,   292,   290,   291,     0,   293,     0,     0,     0,
       0,     0,     0,   486,   402,     0,   436,   437,     0,     0,
     489,   434,   433,     0,    79,   487,     0,   403,   435,     0,
       0,     0,   446,   488,   447,   398,     0,   432,     0,     0,
     308,   310,   304,   305,   312,     0,     0,     0,     0,   276,
     176,   178,    94,   184,   179,   175,     0,     0,     0,     0,
       0,   233,   234,   235,     0,     0,   236,     0,   248,   252,
     249,   250,   247,   251,   246,     0,     0,   231,     0,     0,
       0,   116,   185,     0,     0,     0,     0,   105,   124,   126,
     128,   168,   167,   166,   165,   130,     0,   147,     0,   121,
     122,     0,     0,     0,     0,   268,     0,   237,     0,   220,
       0,    76,    75,   482,     0,   444,   445,   431,     0,   404,
     406,   405,     0,     0,     0,     0,   409,     0,   410,     0,
       0,     0,     0,     0,   408,   407,     0,     0,   400,     0,
     478,     0,     0,   481,   479,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   448,     0,     0,   307,   311,   309,
       0,   314,   313,     0,   287,   183,     0,   180,   241,   238,
     242,   273,   239,   240,     0,     0,     0,     0,   108,     0,
     113,     0,     0,   129,     0,   132,   133,   201,     0,   147,
       0,     0,   155,   156,   154,   163,   157,   164,   158,   160,
     162,   159,   161,     0,   148,     0,     0,     0,     0,   102,
     103,   210,     0,   123,   117,   197,   199,    92,   201,   193,
     190,     0,     0,     0,     0,   484,     0,   483,     0,     0,
     421,   422,     0,   419,   418,     0,    79,     0,   420,     0,
     429,   401,   417,     0,     0,   411,   413,   412,   415,   414,
       0,     0,   443,     0,   399,   466,   459,   458,   468,   469,
     467,   476,   470,   477,   471,   473,   475,   472,   474,   465,
     464,   460,   463,   462,   461,   298,   300,     0,   306,   315,
       0,     0,   255,   259,   256,   257,   254,   258,   253,   245,
       0,     0,   109,     0,     0,     0,     0,   131,   125,   127,
     135,     0,   142,     0,   144,   149,   150,     0,   138,   140,
       0,   139,     0,   136,   137,   152,   151,     0,   101,   198,
     195,     0,   197,     0,   222,   221,     0,    78,   288,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
     457,     0,     0,     0,     0,     0,     0,   430,   438,   441,
     439,   442,   440,     0,   297,     0,     0,   181,   243,     0,
     244,     0,   114,   112,   111,     0,   274,     0,   145,     0,
       0,   134,   104,     0,   196,     0,     0,   485,   295,     0,
       0,     0,     0,   428,     0,   450,   449,   456,   455,   451,
     454,   453,   452,   299,     0,     0,     0,   110,     0,     0,
     141,   143,     0,   192,   223,    77,     0,     0,   423,   426,
     424,   427,   425,     0,   301,   260,   200,   146,   153,   191,
     296,     0,     0,   294,   302
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,     9,    16,    17,    25,    22,    23,
      49,    19,    20,    31,    32,    34,    35,    63,    64,    67,
      68,    69,   111,    91,   256,   122,   123,   432,   396,   138,
     139,   260,   240,   377,   502,   263,   264,   265,   344,   623,
     499,   619,   372,   286,   590,   591,   368,   287,   373,   500,
     624,   487,   488,   489,   490,   491,   492,   722,   723,   724,
     493,   777,   617,   494,   618,   495,   352,   369,   267,   268,
     348,   269,   481,   433,    70,    89,   629,   630,   378,   730,
     625,   496,   115,   242,   243,   620,   302,   497,   365,   475,
     699,   303,   381,   382,   356,   778,   324,   325,   326,   405,
     327,   817,   328,   764,   329,   441,   442,   330,   331,   332,
     569,   333,   334,   335,    51,    85,   245,   246,   538,   434,
     519,   435,   651,   635,   757,   564,   636,   637,   437
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -670
static const yytype_int16 yypact[] =
{
      -5,    13,    93,    -9,    81,    97,  -670,    25,   116,  -670,
    -670,  -670,    65,   124,   117,    65,     4,  -670,   112,   125,
    -670,  -670,   267,  1984,  -670,  -670,   164,  1984,  -670,  -670,
     192,   -45,  -670,   258,    -2,  -670,    65,   168,  -670,  -670,
     187,  -670,  -670,  -670,  -670,   197,  -670,  -670,   238,  -670,
    -670,   292,  -670,    65,  -670,  -670,   252,   268,   287,   272,
     299,   300,   370,  1927,  -670,   370,  -670,   327,   -37,   349,
    -670,  1984,   164,   164,   164,   164,    65,   418,   164,   164,
     164,    -7,   164,   164,  -670,  -670,  -670,  -670,   360,   -18,
     343,  -670,  -670,   289,  -670,  -670,   377,    67,   134,   392,
    1984,   370,  -670,  -670,  -670,   370,   370,  -670,  -670,  -670,
     370,   250,  -670,  -670,  -670,  1632,   361,   371,   320,   335,
     123,    -6,   752,  -670,  -670,  -670,   164,  -670,   164,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,  2065,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
     344,  -670,   346,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,   347,  -670,  -670,   356,  -670,   376,  -670,  -670,
    -670,  -670,  -670,  3101,   368,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,   384,  -670,  -670,  -670,  -670,  -670,  1632,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,   387,   389,   396,   397,
    -670,  -670,    28,  -670,  2746,    87,  -670,   400,   408,   451,
     436,   393,   419,  1920,  1920,  -670,  -670,  -670,   477,   517,
    2065,   498,  -670,   566,  -670,   104,   500,   520,  -670,  -670,
      15,   -15,   -15,   -15,  1632,  1632,  -670,  -670,  1632,   403,
     -15,   -15,  1632,  1302,  1632,  2657,   569,    10,    86,    86,
      86,    86,    86,    86,   466,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,  2805,  1632,   164,    23,    23,  -670,
    1920,  1920,  1920,  1797,    65,  1928,   471,   164,   370,  1928,
     370,     6,  1928,  1920,  1920,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  1920,  -670,  -670,   566,
    3101,  2065,  -670,  -670,  -670,  2953,  3101,   484,  -670,  -670,
    -670,  -670,  1632,  1632,  1632,  2154,   161,   171,   190,  -670,
    1632,  1632,   203,    18,   334,   531,  -670,   144,  -670,  3101,
     533,   807,  -670,   497,   442,  -670,   -15,   492,  -670,  -670,
    -670,  -670,  1632,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
     474,   224,    26,  -670,   476,  -670,  1920,  1920,  1920,  1920,
    1920,  -670,  -670,  -670,  -670,   478,  -670,   579,  1928,  1928,
    1928,   485,   485,  -670,  -670,   485,   482,  -670,   491,   -17,
    -670,  -670,  -670,   493,   229,  -670,  1928,  -670,  -670,   485,
     485,   496,  -670,  -670,  -670,   598,  3331,  -670,     9,   505,
    -670,   475,   613,  3761,  -670,   473,   516,  3500,   530,  -670,
    -670,  -670,  -670,  -670,   508,  -670,    27,   409,  1796,  1864,
    1632,  -670,  -670,  -670,  3100,  3168,  -670,    56,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,   480,    56,  -670,  2213,  2361,
    2361,  -670,  -670,  1137,   506,   506,   642,   618,   619,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  3269,  3288,  1632,  -670,
     543,  3101,  2065,   494,   489,  2154,   164,  -670,   164,  -670,
    1928,  1920,  1920,  1928,  1928,  3761,  3761,   348,  3341,  -670,
    -670,  -670,  1928,  1928,   485,   485,  -670,   485,  -670,   485,
     485,  1928,  1928,  3685,  -670,  -670,  1928,  1928,  -670,  1928,
    -670,  1928,  1928,  -670,  -670,  -670,  1928,  1928,  1928,  1928,
    1928,  1928,  1928,  1928,  1928,  1928,  1928,  1928,  1928,  1928,
    1928,  1928,  1928,  1920,  -670,  1928,  1928,  -670,  -670,  -670,
    1928,  -670,  -670,  1920,  -670,  -670,   540,  -670,  -670,  -670,
    -670,  2154,  -670,  -670,   495,  1020,   499,  2509,  -670,  2657,
     144,   523,   525,  -670,   507,  -670,  -670,   -18,    39,  3252,
     807,   807,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,  1632,  -670,   526,   527,   328,   972,   634,
    -670,  2154,   807,  -670,  -670,   483,  -670,   566,   -18,  -670,
    -670,  3101,    33,   599,  3529,  3761,   601,   646,   521,  3341,
     536,  -670,   539,  -670,  -670,   545,   257,  1928,  -670,   546,
    -670,  1965,  -670,   225,   226,  -670,  -670,  -670,  -670,  -670,
     227,   230,  -670,   251,  3403,  3761,  3783,  3804,  3346,  3346,
    3346,  3346,  3346,  3346,  3346,  3346,  3346,  3346,  3346,   348,
     348,   359,   359,  -670,  -670,   588,   613,  3568,  3761,  -670,
     612,  1020,  -670,   548,  -670,  -670,  -670,  -670,  -670,  -670,
    1020,  2657,  -670,   101,   807,   807,  1632,  -670,   619,  -670,
    2154,   358,  -670,   358,  -670,  -670,  -670,  1632,  -670,  -670,
    1467,  -670,   506,  -670,  -670,  -670,  2154,  1632,   618,  -670,
    -670,  1632,   483,   164,  -670,  -670,  1928,  -670,  -670,  1928,
    1928,   438,  1928,  1928,  1928,  1928,  3723,  1928,  3341,  3341,
    -670,  3341,  3341,  3341,  3341,  3341,  3341,  -670,  -670,  -670,
    -670,  -670,  -670,  1920,  -670,  1928,   649,  -670,  -670,   574,
    -670,   141,  -670,   618,   618,    28,  -670,   256,  -670,   261,
     321,  -670,  -670,    28,  -670,   621,  3607,  3761,  3464,   262,
     286,   305,   336,  -670,   337,   383,   490,   438,   438,   366,
     366,  -670,  -670,  -670,  3646,  1928,   626,  -670,   627,   522,
    -670,  -670,  1632,    10,  -670,  -670,  1928,   614,  -670,  -670,
    -670,  -670,  -670,   663,   613,  -670,  -670,  -670,  2154,  -670,
    3761,  1920,  1928,  -670,   613
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -670,  -670,  -670,  -670,  -670,  -670,   682,  -670,  -670,    19,
      21,  -670,  -670,  -670,   672,  -670,  -670,  -670,   652,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,   600,  -303,   421,  -670,
    -670,  -670,  -669,  -670,  -670,  -254,   395,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,  -284,   274,  -452,  -543,  -670,  -670,
    -670,  -479,   130,   136,   255,  -670,  -670,  -670,  -670,  -670,
    -670,    45,  -670,  -670,   264,  -670,  -234,  -135,  -670,    14,
     307,  -670,  -670,  -115,   669,  -670,  -670,  -670,   -50,    34,
     139,  -427,  -546,  -457,   487,    40,  -670,  -102,  -670,  -415,
    -591,  -670,   191,  -670,   301,   -28,  -195,  -301,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  -562,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,   -64,   -36,   -77,  -670,  -670,  -670,
     -30,  -670,  -535,  -231,  -670,  -670,  -670,  -456,  -455
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -179
static const yytype_int16 yytable[] =
{
     241,   367,   266,   686,   395,   395,   339,   598,    96,    97,
      98,    99,    12,   244,   102,   103,   104,   112,   108,   109,
     349,     4,   467,   449,   524,   525,   588,   565,    54,    88,
     508,   576,   284,    12,    27,   449,    92,   733,   353,   354,
     526,   527,   776,    84,   776,   107,   360,   361,    52,   600,
     113,   706,   584,   350,     1,    71,     7,   595,   596,   336,
     270,   586,   258,   652,   259,   132,   653,   654,  -177,   133,
     134,   126,    77,   105,   135,   660,   661,    28,   509,   577,
     663,   468,   731,   253,   436,   734,  -178,    30,   443,    13,
     707,   447,    95,     6,   241,   100,   276,   449,   449,   449,
     768,   469,    93,    50,   741,   478,   374,   279,   470,   770,
      13,   528,   285,   379,   380,   398,   399,   400,   127,   468,
     393,   131,     5,   106,   471,   266,   472,   566,   448,   375,
      14,    65,   394,   347,   114,   702,    66,   351,   128,   469,
     776,   342,   503,   728,   254,   478,   470,   449,   478,   529,
     530,    14,   772,   445,    10,   473,   479,   480,   304,   241,
     241,   376,   471,   241,   472,   460,    15,   241,   241,   241,
      11,   343,   355,   355,    21,   460,   355,   515,   516,   517,
     355,   364,   244,   270,   652,   129,   474,    15,   712,   714,
     241,   725,   807,   473,   460,   533,   479,   480,   251,   479,
     480,   511,   512,   355,   305,   306,   266,   460,   370,    18,
     449,   449,   461,   795,   796,   650,   797,   798,   799,   800,
     801,   802,   462,   252,   474,   773,   774,   390,   460,   739,
     739,   739,   808,    24,   739,    26,   406,   241,   241,   241,
     813,   463,   392,   824,    30,   241,   241,    33,   627,   775,
     457,   458,   459,   439,   466,   739,   241,   446,   464,   465,
     809,    50,   685,   451,   270,   809,   739,   241,   454,   451,
     834,    36,   689,    53,   783,   507,   758,   759,   760,   634,
     505,   761,   440,   638,   444,    72,   789,   790,   791,   792,
     739,   794,   482,   652,   652,   781,   652,   652,   652,   652,
     652,   652,   762,    56,    73,   703,   664,   810,   665,   739,
     666,   667,   811,   818,    74,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   812,   407,   443,   687,   650,   819,   476,   688,
     739,   739,   715,   716,    76,   241,   532,   510,   288,   289,
     290,   291,   292,   293,   450,    75,   820,    78,   581,    57,
     455,   288,   289,   290,   291,   292,   293,   266,   241,   136,
     137,   241,   717,    79,   745,   510,   116,   559,   560,   561,
     562,    58,   520,   241,   599,   521,   117,   821,   822,    80,
     561,   562,    59,    60,   749,   750,   621,   755,   756,   534,
     535,   370,   370,   370,    82,    83,    61,    62,   160,    90,
     751,   752,   753,   754,   755,   756,   746,   771,   118,    81,
      84,   119,    94,   101,   626,   270,   110,    66,   125,   174,
     288,   289,   290,   291,   292,   293,   288,   289,   290,   291,
     292,   293,   632,   130,   633,   650,   650,   247,   650,   650,
     650,   650,   650,   650,   359,   192,   249,   248,   250,   120,
     578,   271,   803,   272,   273,   277,   121,   753,   754,   755,
     756,   206,   207,   274,   296,   297,   298,   299,   300,   301,
     383,   384,   385,   386,   387,   241,   241,   296,   297,   298,
     299,   300,   301,   275,   655,   656,   597,   657,   241,   658,
     659,   278,   750,   241,   280,   786,   281,   241,   787,   788,
     370,   710,   370,   282,   283,   307,   726,   751,   752,   753,
     754,   755,   756,   308,   309,   310,   539,   540,   337,   311,
     833,   541,   542,   543,   804,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   626,   312,   296,   297,   298,   299,
     300,   301,   296,   297,   298,   299,   300,   301,   338,   340,
     341,   345,   160,   346,   443,   388,   357,   313,   371,   358,
     438,   456,   477,   362,   498,   830,  -177,   501,   504,   241,
     241,   241,   506,   174,   510,   513,   241,   514,   241,   522,
     518,   443,   241,   574,   244,   241,   391,   537,   523,   567,
     531,   314,   241,   536,   568,   780,   241,   570,   279,   192,
     572,   315,   571,   594,   370,   621,   347,   585,   600,   244,
     601,   622,   628,   316,   631,   206,   207,   690,   727,   704,
     317,   705,   691,   711,   713,   597,   700,   729,   140,   141,
     739,   735,   738,   742,   142,   483,   743,   318,   143,   319,
     763,   320,   744,   747,   767,   769,   144,   805,   740,   785,
     321,   806,   145,   814,   146,   147,   148,   825,   826,   149,
     150,   832,   151,   831,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   322,   241,   323,   161,   241,    29,   162,
     163,   164,   165,    55,   166,   167,   168,   169,   170,   171,
     828,   172,   173,   174,   175,    87,   176,   177,   484,   178,
     179,   180,   257,   181,   182,   183,   184,   185,   186,   397,
     708,   187,   188,   189,   190,   191,   452,   709,   593,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   485,   592,   206,   207,   208,   779,   486,
     613,   575,   124,   829,   210,   211,   784,   782,   212,   213,
     732,   366,   214,     0,   215,   216,   217,   218,   219,   220,
     597,   827,   221,   222,   223,   116,   224,   225,   226,   227,
     228,     0,   229,     0,     0,   117,     0,     0,     0,     0,
       0,   230,   231,   232,   233,   234,     0,   235,   236,   237,
     238,     0,   239,   140,   141,     0,     0,     0,     0,   142,
     483,     0,     0,   143,     0,   255,     0,     0,     0,     0,
     119,   144,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,     0,     0,   149,   150,     0,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
       0,   161,     0,     0,   162,   163,   164,   165,   120,   166,
     167,   168,   169,   170,   171,   121,   172,   173,   174,   175,
       0,   176,   177,   484,   178,   179,   180,     0,   181,   182,
     183,   184,   185,   186,     0,     0,   187,   188,   189,   190,
     191,     0,     0,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   485,     0,
     206,   207,   208,     0,   486,     0,     0,     0,     0,   210,
     211,     0,     0,   212,   213,     0,     0,   214,     0,   215,
     216,   217,   218,   219,   220,     0,     0,   221,   222,   223,
       0,   224,   225,   226,   227,   228,     0,   229,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   231,   232,   233,
     234,     0,   235,   236,   237,   238,     0,   239,   140,   141,
       0,     0,     0,     0,   142,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,   145,     0,   146,   147,   148,   718,   719,   149,
     150,     0,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,   161,     0,     0,   162,
     163,   164,   165,     0,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   692,     0,   206,   207,   208,     0,   720,
       0,     0,     0,     0,   210,   211,     0,     0,   212,   213,
       0,     0,   214,   693,   215,   216,   217,   218,   219,   220,
     694,     0,   221,   222,   223,   721,   224,   225,   226,   227,
     228,     0,   229,     0,     0,     0,   695,     0,   696,     0,
       0,   230,   231,   232,   233,   234,     0,   235,   236,   237,
     238,     0,   239,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,   697,     0,     0,
       0,   144,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,     0,     0,   149,   150,     0,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   698,     0,
       0,   161,     0,     0,   162,   163,   164,   165,     0,   166,
     167,   168,   169,   170,   171,     0,   172,   173,   174,   175,
       0,   176,   177,   484,   178,   179,   180,     0,   181,   182,
     183,   184,   185,   186,     0,     0,   187,   188,   189,   190,
     191,     0,     0,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   485,     0,
     206,   207,   208,     0,   486,     0,     0,     0,     0,   210,
     211,     0,     0,   212,   213,     0,     0,   214,     0,   215,
     216,   217,   218,   219,   220,     0,     0,   221,   222,   223,
       0,   224,   225,   226,   227,   228,     0,   229,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   231,   232,   233,
     234,     0,   235,   236,   237,   238,     0,   239,   140,   141,
       0,     0,     0,     0,   142,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,   145,     0,   146,   147,   148,     0,     0,   149,
     150,     0,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,   161,     0,     0,   162,
     163,   164,   165,     0,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,     0,     0,   206,   207,   208,     0,   209,
       0,     0,     0,     0,   210,   211,     0,     0,   212,   213,
       0,     0,   214,     0,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,     0,   224,   225,   226,   227,
     228,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,   230,   231,   232,   233,   234,     0,   235,   236,   237,
     238,   363,   239,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,     0,     0,   149,   150,     0,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,     0,
       0,   161,     0,     0,   162,   163,   164,   165,     0,   166,
     167,   168,   169,   170,   171,     0,   172,   173,   174,   175,
       0,   176,   177,     0,   178,   179,   180,     0,   181,   182,
     183,   184,   185,   186,     0,     0,   187,   188,   189,   190,
     191,     0,     0,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,     0,     0,
     206,   207,   208,     0,   209,     0,     0,     0,     0,   210,
     211,     0,     0,   212,   213,     0,     0,   214,     0,   215,
     216,   217,   218,   219,   220,   597,     0,   221,   222,   223,
       0,   224,   225,   226,   227,   228,     0,   229,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   231,   232,   233,
     234,     0,   235,   236,   237,   238,     0,   239,   140,   141,
       0,     0,     0,     0,   142,     0,     0,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,   145,     0,   146,   147,   148,     0,     0,   149,
     150,     0,   151,     0,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,   161,     0,     0,   162,
     163,   164,   165,     0,   166,   167,   168,   169,   170,   171,
       0,   172,   173,   174,   175,     0,   176,   177,     0,   178,
     179,   180,     0,   181,   182,   183,   184,   185,   186,     0,
       0,   187,   188,   189,   190,   191,     0,     0,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,     0,     0,   206,   207,   208,     0,   209,
       0,     0,     0,     0,   210,   211,     0,     0,   212,   213,
       0,     0,   214,     0,   215,   216,   217,   218,   219,   220,
       0,     0,   221,   222,   223,     0,   224,   225,   226,   227,
     228,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       0,   230,   231,   232,   233,   234,     0,   235,   236,   237,
     238,     0,   239,   140,   141,     0,     0,     0,     0,   142,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,   288,   289,   290,   291,   292,   293,   146,
     147,   148,     0,     0,   149,     0,     0,   151,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   579,     0,     0,
       0,   161,     0,     0,     0,   163,   164,   401,     0,   166,
     402,   168,   169,   170,   171,     0,   172,     0,     0,   175,
       0,   176,   177,     0,   178,   179,   180,     0,   181,   182,
     183,   184,   185,   186,     0,     0,   187,   188,   189,   190,
     191,   288,   289,   290,   291,   292,   293,   195,   196,   197,
     198,   199,   200,   201,   202,   403,   204,   205,     0,     0,
       0,     0,   208,     0,     0,   580,     0,     0,     0,   210,
     211,     0,     0,   212,   213,     0,     0,   214,     0,   215,
     216,   217,   218,   219,   220,   408,   409,   221,   222,   223,
       0,   224,   225,   226,   227,   228,     0,   229,     0,   296,
     297,   298,   299,   300,   301,   410,   230,     0,   232,   233,
     234,     0,   235,     0,     0,   404,     0,   313,     0,   411,
     412,     0,    56,     0,     0,   748,   749,   750,   413,     0,
       0,     0,     0,     0,     0,   414,   415,     0,   416,   417,
       0,   418,   751,   752,   753,   754,   755,   756,     0,   174,
      86,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,     0,     0,   419,     0,     0,   296,   297,   298,
     299,   300,   301,   316,     0,   420,   421,   422,    57,     0,
     317,     0,     0,    37,     0,     0,   423,   424,     0,     0,
       0,   206,   425,     0,    38,   426,    39,   318,    40,   319,
      58,   320,     0,     0,     0,     0,   427,     0,     0,     0,
     321,    59,    60,    41,     0,     0,     0,     0,     0,    42,
       0,   140,   141,     0,     0,    61,    62,   142,    43,    44,
       0,   143,     0,   322,     0,   323,     0,     0,   428,   144,
       0,    45,     0,     0,   429,   430,   431,   146,   147,   148,
       0,     0,   149,     0,     0,   151,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   261,     0,     0,     0,   161,
       0,     0,     0,   163,   164,    46,    47,   166,     0,   168,
     169,   170,   171,     0,   172,     0,     0,   175,     0,   176,
     177,     0,   178,   179,   180,    48,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   262,     0,     0,   195,   196,   197,   198,   199,
     200,   201,   202,     0,   204,   205,     0,     0,     0,     0,
     208,   288,   289,   290,   291,   292,   293,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,     0,     0,     0,   140,
     141,     0,     0,     0,   230,   142,   232,   233,   234,   143,
     235,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,     0,   146,   147,   148,     0,     0,
     149,     0,     0,   151,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   261,     0,     0,     0,   161,     0,     0,
       0,   163,   164,     0,     0,   166,     0,   168,   169,   170,
     171,     0,   172,     0,     0,   175,     0,   176,   177,     0,
     178,   179,   180,     0,   181,   182,   183,   184,   185,   186,
       0,     0,   187,   188,   189,   190,   191,   296,   297,   298,
     299,   300,   301,   195,   196,   197,   198,   199,   200,   201,
     202,     0,   204,   205,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,   587,   210,   211,     0,     0,   212,
     213,     0,     0,   214,     0,   215,   216,   217,   218,   219,
     220,     0,     0,   221,   222,   223,     0,   224,   225,   226,
     227,   228,     0,   229,     0,     0,     0,   140,   141,     0,
       0,     0,   230,   142,   232,   233,   234,   143,   235,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,     0,   146,   147,   148,     0,     0,   149,     0,
       0,   151,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   261,     0,     0,     0,   161,     0,     0,     0,   163,
     164,     0,     0,   166,     0,   168,   169,   170,   171,     0,
     172,     0,     0,   175,     0,   176,   177,     0,   178,   179,
     180,     0,   181,   182,   183,   184,   185,   186,     0,     0,
     187,   188,   189,   190,   191,     0,     0,     0,     0,     0,
       0,   195,   196,   197,   198,   199,   200,   201,   202,     0,
     204,   205,     0,     0,     0,     0,   208,     0,   589,     0,
       0,     0,     0,   210,   211,     0,     0,   212,   213,     0,
       0,   214,     0,   215,   216,   217,   218,   219,   220,     0,
       0,   221,   222,   223,     0,   224,   225,   226,   227,   228,
       0,   229,     0,     0,     0,   140,   141,     0,     0,     0,
     230,   142,   232,   233,   234,   143,   235,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,     0,     0,   149,     0,     0,   151,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   261,
       0,     0,     0,   161,     0,     0,     0,   163,   164,     0,
       0,   166,     0,   168,   169,   170,   171,     0,   172,     0,
       0,   175,     0,   176,   177,     0,   178,   179,   180,     0,
     181,   182,   183,   184,   185,   186,     0,     0,   187,   188,
     189,   190,   191,     0,     0,     0,     0,     0,     0,   195,
     196,   197,   198,   199,   200,   201,   202,     0,   204,   205,
       0,     0,     0,     0,   208,     0,   701,     0,     0,     0,
       0,   210,   211,     0,     0,   212,   213,     0,     0,   214,
       0,   215,   216,   217,   218,   219,   220,     0,     0,   221,
     222,   223,     0,   224,   225,   226,   227,   228,     0,   229,
       0,     0,     0,   140,   141,     0,     0,     0,   230,   142,
     232,   233,   234,   143,   235,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,     0,   146,
     147,   148,     0,     0,   149,     0,     0,   151,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   261,     0,     0,
       0,   161,     0,     0,     0,   163,   164,     0,     0,   166,
       0,   168,   169,   170,   171,     0,   172,     0,     0,   175,
       0,   176,   177,     0,   178,   179,   180,     0,   181,   182,
     183,   184,   185,   186,     0,     0,   187,   188,   189,   190,
     191,     0,     0,     0,     0,     0,     0,   195,   196,   197,
     198,   199,   200,   201,   202,     0,   204,   205,     0,     0,
       0,     0,   208,   288,   289,   290,   291,   292,   293,   210,
     211,     0,     0,   212,   213,     0,   294,   214,     0,   215,
     216,   217,   218,   219,   220,     0,     0,   221,   222,   223,
       0,   224,   225,   226,   227,   228,     0,   229,     0,     0,
       0,   140,   141,     0,     0,     0,   230,   142,   232,   233,
     234,   143,   235,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,   389,     0,   146,   147,   148,
       0,     0,   149,     0,     0,   151,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   295,     0,     0,     0,   161,
       0,     0,     0,   163,   164,     0,     0,   166,     0,   168,
     169,   170,   171,     0,   172,     0,     0,   175,     0,   176,
     177,     0,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,   296,
     297,   298,   299,   300,   301,   195,   196,   197,   198,   199,
     200,   201,   202,     0,   204,   205,     0,     0,     0,     0,
     208,     0,     0,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,     0,     0,     0,   140,
     141,     0,     0,     0,   230,   142,   232,   233,   234,   143,
     235,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,   453,     0,   146,   147,   148,     0,     0,
     149,     0,     0,   151,     0,     0,   153,   154,   155,   156,
     157,   158,   159,     0,     0,     0,     0,   161,     0,     0,
       0,   163,   164,     0,     0,   166,     0,   168,   169,   170,
     171,     0,   172,     0,     0,   175,     0,   176,   177,     0,
     178,   179,   180,     0,   181,   182,   183,   184,   185,   186,
       0,     0,   187,   188,   189,   190,   191,     0,     0,     0,
       0,     0,     0,   195,   196,   197,   198,   199,   200,   201,
     202,     0,   204,   205,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,   210,   211,     0,     0,   212,
     213,     0,     0,   214,     0,   215,   216,   217,   218,   219,
     220,     0,     0,   221,   222,   223,     0,   224,   225,   226,
     227,   228,     0,   229,     0,     0,     0,   140,   141,     0,
       0,     0,   230,   142,   232,   233,   234,   143,   235,     0,
       0,     0,     0,     0,     0,   144,     0,   288,   289,   290,
     291,   292,   293,   146,   147,   148,     0,     0,   149,     0,
       0,   151,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   582,     0,     0,     0,   161,     0,     0,     0,   163,
     164,     0,     0,   166,     0,   168,   169,   170,   171,     0,
     172,     0,     0,   175,     0,   176,   177,     0,   178,   179,
     180,     0,   181,   182,   183,   184,   185,   186,     0,     0,
     187,   188,   189,   190,   191,   288,   289,   290,   291,   292,
     293,   195,   196,   197,   198,   199,   200,   201,   202,     0,
     204,   205,     0,     0,     0,     0,   208,     0,     0,   583,
       0,     0,     0,   210,   211,     0,     0,   212,   213,     0,
       0,   214,     0,   215,   216,   217,   218,   219,   220,     0,
       0,   221,   222,   223,     0,   224,   225,   226,   227,   228,
       0,   229,     0,   296,   297,   298,   299,   300,   301,     0,
     230,     0,   232,   233,   234,   614,   235,     0,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   288,
     289,   290,   291,   292,   293,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,   614,     0,   359,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   288,   289,   290,   291,   292,
     293,   296,   297,   298,   299,   300,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   539,   540,     0,     0,
       0,   541,   542,   543,   615,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   616,     0,     0,     0,   639,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,     0,
     615,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   413,     0,     0,     0,     0,     0,     0,     0,     0,
     616,   640,   641,     0,   642,   296,   297,   298,   299,   300,
     301,     0,   174,   541,   542,   543,     0,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,     0,     0,   420,   643,
     644,   296,   297,   298,   299,   300,   301,     0,     0,   645,
     646,     0,     0,     0,   206,   425,     0,     0,   647,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   539,
     540,     0,     0,     0,   541,   542,   543,   563,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,     0,     0,     0,
       0,   648,     0,     0,     0,   539,   540,     0,     0,   649,
     541,   542,   543,     0,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   736,   539,   540,     0,     0,     0,   541,
     542,   543,     0,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,     0,     0,     0,     0,     0,     0,     0,   573,
       0,     0,   765,   539,   540,     0,     0,     0,   541,   542,
     543,   737,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,     0,     0,     0,     0,     0,     0,     0,   816,     0,
       0,     0,   539,   540,     0,     0,     0,   541,   542,   543,
     766,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   539,   540,     0,     0,     0,   541,   542,   543,   815,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     539,   540,     0,     0,     0,   541,   542,   543,   823,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   539,   540,
       0,     0,     0,   541,   542,   543,   662,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   539,   540,     0,     0,
       0,   541,   542,   543,   793,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   542,   543,     0,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   543,     0,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562
};

static const yytype_int16 yycheck[] =
{
     115,   285,   137,   565,   307,   308,   260,   486,    72,    73,
      74,    75,     8,   115,    78,    79,    80,    35,    82,    83,
      35,     8,     4,   324,    41,    42,   478,    18,    73,    65,
       4,     4,     4,     8,    15,   336,    73,     4,   272,   273,
      57,    58,   711,    50,   713,    81,   280,   281,    27,    10,
      68,   597,   467,    68,    59,    36,    65,   484,   485,   254,
     137,   476,   126,   518,   128,   101,   522,   523,    53,   105,
     106,     4,    53,    80,   110,   531,   532,    73,    52,    52,
     536,    63,   628,    89,   315,    52,    71,   132,   319,    85,
      51,   322,    71,     0,   209,    76,   173,   398,   399,   400,
     691,    83,   139,    97,   639,     4,    96,   209,    90,   700,
      85,   128,    84,    27,    28,   310,   311,   312,    51,    63,
      97,   100,   109,   130,   106,   260,   108,   118,   323,   119,
     126,   133,   109,   118,   152,   587,   138,   152,     4,    83,
     809,    37,   376,   622,   150,     4,    90,   448,     4,   166,
     167,   126,    51,   147,    73,   137,    55,    56,    71,   274,
     275,   151,   106,   278,   108,     4,   162,   282,   283,   284,
      73,    67,   274,   275,   109,     4,   278,   408,   409,   410,
     282,   283,   284,   260,   639,    51,   168,   162,   615,   616,
     305,   618,    51,   137,     4,   426,    55,    56,    75,    55,
      56,   396,   397,   305,   117,   118,   341,     4,   285,    93,
     511,   512,    51,   748,   749,   518,   751,   752,   753,   754,
     755,   756,    51,   100,   168,   704,   705,   304,     4,     4,
       4,     4,   775,   109,     4,   118,   313,   352,   353,   354,
     783,    51,   306,   805,   132,   360,   361,   122,   502,   706,
     352,   353,   354,   317,    51,     4,   371,   321,   360,   361,
       4,    97,   563,   340,   341,     4,     4,   382,   345,   346,
     832,     4,   573,    81,   731,    51,    51,    51,    51,   510,
     382,    51,   318,   514,   320,   117,   742,   743,   744,   745,
       4,   747,   369,   748,   749,   722,   751,   752,   753,   754,
     755,   756,    51,    45,   117,   589,   537,    51,   539,     4,
     541,   542,    51,    51,   117,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,    11,   314,   565,   566,   639,    51,     4,   570,
       4,     4,    14,    15,    52,   460,   117,   118,    27,    28,
      29,    30,    31,    32,   340,   117,    51,   105,   460,   101,
     346,    27,    28,    29,    30,    31,    32,   502,   483,   119,
     120,   486,    44,   105,   117,   118,    33,    29,    30,    31,
      32,   123,   412,   498,   486,   415,    43,    51,    51,   102,
      31,    32,   134,   135,    11,    12,   498,    31,    32,   429,
     430,   478,   479,   480,   105,   105,   148,   149,    50,    82,
      27,    28,    29,    30,    31,    32,   647,   701,    75,   147,
      50,    78,    73,     5,   501,   502,    66,   138,    51,    71,
      27,    28,    29,    30,    31,    32,    27,    28,    29,    30,
      31,    32,   506,    51,   508,   748,   749,    86,   751,   752,
     753,   754,   755,   756,    51,    97,   136,    86,   123,   116,
      51,   117,   763,   117,   117,    97,   123,    29,    30,    31,
      32,   113,   114,   117,   153,   154,   155,   156,   157,   158,
     289,   290,   291,   292,   293,   600,   601,   153,   154,   155,
     156,   157,   158,   117,   524,   525,   138,   527,   613,   529,
     530,   117,    12,   618,   117,   736,   117,   622,   739,   740,
     587,   613,   589,   117,   117,   115,   618,    27,    28,    29,
      30,    31,    32,   115,    73,    89,     5,     6,    51,   136,
     831,    10,    11,    12,   765,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   631,   136,   153,   154,   155,   156,
     157,   158,   153,   154,   155,   156,   157,   158,    51,    71,
       4,    71,    50,    53,   805,   109,   275,    47,     9,   278,
     109,    97,    51,   282,    87,   816,    53,   145,    96,   704,
     705,   706,   118,    71,   118,   117,   711,    18,   713,   117,
     115,   832,   717,    73,   706,   720,   305,     9,   117,   104,
     117,    81,   727,   117,   139,   717,   731,     4,   720,    97,
     104,    91,   149,   117,   701,   727,   118,   147,    10,   731,
      11,    88,   138,   103,   145,   113,   114,    97,     4,   116,
     110,   116,   147,   117,   117,   138,   147,   164,     6,     7,
       4,    52,    51,   117,    12,    13,   117,   127,    16,   129,
      72,   131,   117,   117,    52,   117,    24,    18,   147,   733,
     140,    97,    30,    52,    32,    33,    34,    51,    51,    37,
      38,    18,    40,    69,    42,    43,    44,    45,    46,    47,
      48,    49,    50,   163,   809,   165,    54,   812,    16,    57,
      58,    59,    60,    31,    62,    63,    64,    65,    66,    67,
     812,    69,    70,    71,    72,    63,    74,    75,    76,    77,
      78,    79,   122,    81,    82,    83,    84,    85,    86,   308,
     600,    89,    90,    91,    92,    93,   341,   601,   483,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   480,   113,   114,   115,   713,   117,
     496,   454,    93,   813,   122,   123,   732,   727,   126,   127,
     631,   284,   130,    -1,   132,   133,   134,   135,   136,   137,
     138,   809,   140,   141,   142,    33,   144,   145,   146,   147,
     148,    -1,   150,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,   167,
     168,    -1,   170,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,    16,    -1,    73,    -1,    -1,    -1,    -1,
      78,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    57,    58,    59,    60,   116,    62,
      63,    64,    65,    66,    67,   123,    69,    70,    71,    72,
      -1,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    -1,    -1,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,   126,   127,    -1,    -1,   130,    -1,   132,
     133,   134,   135,   136,   137,    -1,    -1,   140,   141,   142,
      -1,   144,   145,   146,   147,   148,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,   167,   168,    -1,   170,     6,     7,
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
     108,   109,   110,    63,    -1,   113,   114,   115,    -1,   117,
      -1,    -1,    -1,    -1,   122,   123,    -1,    -1,   126,   127,
      -1,    -1,   130,    83,   132,   133,   134,   135,   136,   137,
      90,    -1,   140,   141,   142,   143,   144,   145,   146,   147,
     148,    -1,   150,    -1,    -1,    -1,   106,    -1,   108,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,   167,
     168,    -1,   170,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,   168,    -1,
      -1,    54,    -1,    -1,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      -1,    74,    75,    76,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    -1,    -1,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,   126,   127,    -1,    -1,   130,    -1,   132,
     133,   134,   135,   136,   137,    -1,    -1,   140,   141,   142,
      -1,   144,   145,   146,   147,   148,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,   167,   168,    -1,   170,     6,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,    37,
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
      -1,    -1,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,   167,
     168,   169,   170,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    -1,    -1,    37,    38,    -1,    40,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      -1,    74,    75,    -1,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    -1,    -1,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
     113,   114,   115,    -1,   117,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,   126,   127,    -1,    -1,   130,    -1,   132,
     133,   134,   135,   136,   137,   138,    -1,   140,   141,   142,
      -1,   144,   145,   146,   147,   148,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,
     163,    -1,   165,   166,   167,   168,    -1,   170,     6,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,    37,
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
      -1,    -1,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,   162,   163,    -1,   165,   166,   167,
     168,    -1,   170,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    27,    28,    29,    30,    31,    32,    32,
      33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    51,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    59,    60,    -1,    62,
      63,    64,    65,    66,    67,    -1,    69,    -1,    -1,    72,
      -1,    74,    75,    -1,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    -1,    -1,    89,    90,    91,    92,
      93,    27,    28,    29,    30,    31,    32,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    51,    -1,    -1,    -1,   122,
     123,    -1,    -1,   126,   127,    -1,    -1,   130,    -1,   132,
     133,   134,   135,   136,   137,     7,     8,   140,   141,   142,
      -1,   144,   145,   146,   147,   148,    -1,   150,    -1,   153,
     154,   155,   156,   157,   158,    27,   159,    -1,   161,   162,
     163,    -1,   165,    -1,    -1,   168,    -1,    47,    -1,    41,
      42,    -1,    45,    -1,    -1,    10,    11,    12,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    -1,    60,    61,
      -1,    63,    27,    28,    29,    30,    31,    32,    -1,    71,
      73,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    86,    -1,    -1,   153,   154,   155,
     156,   157,   158,   103,    -1,    97,    98,    99,   101,    -1,
     110,    -1,    -1,    49,    -1,    -1,   108,   109,    -1,    -1,
      -1,   113,   114,    -1,    60,   117,    62,   127,    64,   129,
     123,   131,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,
     140,   134,   135,    79,    -1,    -1,    -1,    -1,    -1,    85,
      -1,     6,     7,    -1,    -1,   148,   149,    12,    94,    95,
      -1,    16,    -1,   163,    -1,   165,    -1,    -1,   160,    24,
      -1,   107,    -1,    -1,   166,   167,   168,    32,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,   141,   142,    62,    -1,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,
      75,    -1,    77,    78,    79,   161,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    27,    28,    29,    30,    31,    32,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,     6,
       7,    -1,    -1,    -1,   159,    12,   161,   162,   163,    16,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    40,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      67,    -1,    69,    -1,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      -1,    -1,    89,    90,    91,    92,    93,   153,   154,   155,
     156,   157,   158,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,   109,   110,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,   126,
     127,    -1,    -1,   130,    -1,   132,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,    -1,   144,   145,   146,
     147,   148,    -1,   150,    -1,    -1,    -1,     6,     7,    -1,
      -1,    -1,   159,    12,   161,   162,   163,    16,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    -1,    -1,    37,    -1,
      -1,    40,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      59,    -1,    -1,    62,    -1,    64,    65,    66,    67,    -1,
      69,    -1,    -1,    72,    -1,    74,    75,    -1,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
     109,   110,    -1,    -1,    -1,    -1,   115,    -1,   117,    -1,
      -1,    -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,
      -1,   130,    -1,   132,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,    -1,   144,   145,   146,   147,   148,
      -1,   150,    -1,    -1,    -1,     6,     7,    -1,    -1,    -1,
     159,    12,   161,   162,   163,    16,   165,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    40,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,    -1,
      -1,    62,    -1,    64,    65,    66,    67,    -1,    69,    -1,
      -1,    72,    -1,    74,    75,    -1,    77,    78,    79,    -1,
      81,    82,    83,    84,    85,    86,    -1,    -1,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,   109,   110,
      -1,    -1,    -1,    -1,   115,    -1,   117,    -1,    -1,    -1,
      -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,   130,
      -1,   132,   133,   134,   135,   136,   137,    -1,    -1,   140,
     141,   142,    -1,   144,   145,   146,   147,   148,    -1,   150,
      -1,    -1,    -1,     6,     7,    -1,    -1,    -1,   159,    12,
     161,   162,   163,    16,   165,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    -1,    -1,    37,    -1,    -1,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,    62,
      -1,    64,    65,    66,    67,    -1,    69,    -1,    -1,    72,
      -1,    74,    75,    -1,    77,    78,    79,    -1,    81,    82,
      83,    84,    85,    86,    -1,    -1,    89,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,   110,    -1,    -1,
      -1,    -1,   115,    27,    28,    29,    30,    31,    32,   122,
     123,    -1,    -1,   126,   127,    -1,    40,   130,    -1,   132,
     133,   134,   135,   136,   137,    -1,    -1,   140,   141,   142,
      -1,   144,   145,   146,   147,   148,    -1,   150,    -1,    -1,
      -1,     6,     7,    -1,    -1,    -1,   159,    12,   161,   162,
     163,    16,   165,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,   109,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    62,    -1,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,
      75,    -1,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,   153,
     154,   155,   156,   157,   158,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,     6,
       7,    -1,    -1,    -1,   159,    12,   161,   162,   163,    16,
     165,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    40,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    58,    59,    -1,    -1,    62,    -1,    64,    65,    66,
      67,    -1,    69,    -1,    -1,    72,    -1,    74,    75,    -1,
      77,    78,    79,    -1,    81,    82,    83,    84,    85,    86,
      -1,    -1,    89,    90,    91,    92,    93,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,   109,   110,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,   126,
     127,    -1,    -1,   130,    -1,   132,   133,   134,   135,   136,
     137,    -1,    -1,   140,   141,   142,    -1,   144,   145,   146,
     147,   148,    -1,   150,    -1,    -1,    -1,     6,     7,    -1,
      -1,    -1,   159,    12,   161,   162,   163,    16,   165,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    27,    28,    29,
      30,    31,    32,    32,    33,    34,    -1,    -1,    37,    -1,
      -1,    40,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    51,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      59,    -1,    -1,    62,    -1,    64,    65,    66,    67,    -1,
      69,    -1,    -1,    72,    -1,    74,    75,    -1,    77,    78,
      79,    -1,    81,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    91,    92,    93,    27,    28,    29,    30,    31,
      32,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
     109,   110,    -1,    -1,    -1,    -1,   115,    -1,    -1,    51,
      -1,    -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,
      -1,   130,    -1,   132,   133,   134,   135,   136,   137,    -1,
      -1,   140,   141,   142,    -1,   144,   145,   146,   147,   148,
      -1,   150,    -1,   153,   154,   155,   156,   157,   158,    -1,
     159,    -1,   161,   162,   163,    13,   165,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    51,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    10,    11,    12,    92,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   112,    -1,    -1,    -1,    27,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     112,    60,    61,    -1,    63,   153,   154,   155,   156,   157,
     158,    -1,    71,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    97,    98,
      99,   153,   154,   155,   156,   157,   158,    -1,    -1,   108,
     109,    -1,    -1,    -1,   113,   114,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    -1,    -1,    10,    11,    12,   146,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,   160,    -1,    -1,    -1,     5,     6,    -1,    -1,   168,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     4,     5,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,     4,     5,     6,    -1,    -1,    -1,    10,    11,
      12,    52,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
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
      29,    30,    31,    32,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32
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
     117,   117,   117,   117,     4,    84,   214,   218,    27,    28,
      29,    30,    31,    32,    40,   109,   153,   154,   155,   156,
     157,   158,   257,   262,    71,   117,   118,   115,   115,    73,
      89,   136,   136,    47,    81,    91,   103,   110,   127,   129,
     131,   140,   163,   165,   267,   268,   269,   271,   273,   275,
     278,   279,   280,   282,   283,   284,   267,    51,    51,   206,
      71,     4,    37,    67,   209,    71,    53,   118,   241,    35,
      68,   152,   237,   237,   237,   258,   265,   265,   265,    51,
     237,   237,   265,   169,   258,   259,   255,   215,   217,   238,
     287,     9,   213,   219,    96,   119,   151,   204,   249,    27,
      28,   263,   264,   263,   263,   263,   263,   263,   109,    30,
     287,   265,   285,    97,   109,   198,   199,   199,   267,   267,
     267,    60,    63,   108,   168,   270,   287,   180,     7,     8,
      27,    41,    42,    50,    57,    58,    60,    61,    63,    86,
      97,    98,    99,   108,   109,   114,   117,   128,   160,   166,
     167,   168,   198,   244,   290,   292,   294,   299,   109,   285,
     286,   276,   277,   294,   286,   147,   285,   294,   267,   268,
     240,   287,   207,    30,   287,   240,    97,   258,   258,   258,
       4,    51,    51,    51,   258,   258,    51,     4,    63,    83,
      90,   106,   108,   137,   168,   260,     4,    51,     4,    55,
      56,   243,   287,    13,    76,   111,   117,   222,   223,   224,
     225,   226,   227,   231,   234,   236,   252,   258,    87,   211,
     220,   145,   205,   237,    96,   258,   118,    51,     4,    52,
     118,   267,   267,   117,    18,   294,   294,   294,   115,   291,
     291,   291,   117,   117,    41,    42,    57,    58,   128,   166,
     167,   117,   117,   294,   291,   291,   117,     9,   289,     5,
       6,    10,    11,    12,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   146,   296,    18,   118,   104,   139,   281,
       4,   149,   104,    69,    73,   241,     4,    52,    51,    51,
      51,   258,    51,    51,   260,   147,   260,   121,   217,   117,
     215,   216,   216,   225,   117,   252,   252,   138,   222,   258,
      10,    11,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   235,    13,    92,   112,   233,   235,   212,
     256,   258,    88,   210,   221,   251,   287,   206,   138,   247,
     248,   145,   285,   285,   294,   294,   297,   298,   294,    27,
      60,    61,    63,    98,    99,   108,   109,   117,   160,   168,
     198,   293,   299,   298,   298,   291,   291,   291,   291,   291,
     298,   298,    51,   298,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   268,   277,   294,   294,   268,
      97,   147,    63,    83,    90,   106,   108,   137,   168,   261,
     147,   117,   217,   215,   116,   116,   253,    51,   223,   224,
     258,   117,   252,   117,   252,    14,    15,    44,    35,    36,
     117,   143,   228,   229,   230,   252,   258,     4,   222,   164,
     250,   253,   251,     4,    52,    52,     4,    52,    51,     4,
     147,   293,   117,   117,   117,   117,   294,   117,    10,    11,
      12,    27,    28,    29,    30,    31,    32,   295,    51,    51,
      51,    51,    51,    72,   274,     4,    52,    52,   261,   117,
     261,   215,    51,   222,   222,   254,   203,   232,   266,   232,
     258,   252,   256,   254,   250,   285,   294,   294,   294,   298,
     298,   298,   298,    51,   298,   293,   293,   293,   293,   293,
     293,   293,   293,   268,   294,    18,    97,    51,   218,     4,
      51,    51,    11,   218,    52,    52,   144,   272,    51,    51,
      51,    51,    51,    52,   277,    51,    51,   266,   258,   249,
     294,    69,    18,   268,   277
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
#line 250 "ace.yacc"
    {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 277 "ace.yacc"
    {
		printf("NIY\n");
		exit(0);
	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 281 "ace.yacc"
    {
		ace_add_variable((yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str),CAT_VARIABLE,0,-1,0);
	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 284 "ace.yacc"
    {
		ace_add_variable((yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str),CAT_PARAM,atoi((yyvsp[(3) - (6)].str)),-1,0);
	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 287 "ace.yacc"
    {
		add_function((yyvsp[(2) - (2)].str));
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 311 "ace.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 312 "ace.yacc"
    {strcpy((yyval.str),"CHAR");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 313 "ace.yacc"
    {SPRINTF1((yyval.str),"CHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 314 "ace.yacc"
    {strcpy((yyval.str),"VARCHAR");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 315 "ace.yacc"
    {SPRINTF1((yyval.str),"VARCHAR (%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 316 "ace.yacc"
    {strcpy((yyval.str),"DATE");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 317 "ace.yacc"
    {strcpy((yyval.str),"FLOAT");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 318 "ace.yacc"
    {strcpy((yyval.str),"SMALLFLOAT");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 319 "ace.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 320 "ace.yacc"
    {strcpy((yyval.str),"DATETIME");}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 321 "ace.yacc"
    {strcpy((yyval.str),"INTERVAL");}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 322 "ace.yacc"
    {strcpy((yyval.str),"MONEY");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 323 "ace.yacc"
    {SPRINTF1((yyval.str),"MONEY (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 324 "ace.yacc"
    {SPRINTF2((yyval.str),"MONEY (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 325 "ace.yacc"
    {strcpy((yyval.str),"DECIMAL");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 326 "ace.yacc"
    {SPRINTF1((yyval.str),"DECIMAL (%s,0)",(yyvsp[(3) - (4)].str));}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 327 "ace.yacc"
    {SPRINTF2((yyval.str),"DECIMAL (%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 341 "ace.yacc"
    {
	add_inputs((char *)A4GL_strip_quotes((yyvsp[(5) - (5)].str)),(yyvsp[(3) - (5)].str));
}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 356 "ace.yacc"
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str));}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 357 "ace.yacc"
    { this_report.output.report_to_where=1; }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 358 "ace.yacc"
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup((yyvsp[(3) - (3)].str)); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 359 "ace.yacc"
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup((yyvsp[(4) - (4)].str)); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 360 "ace.yacc"
    {
		this_report.output.left_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 363 "ace.yacc"
    {
		this_report.output.bottom_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 366 "ace.yacc"
    {
		this_report.output.top_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 369 "ace.yacc"
    {
		this_report.output.page_length=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 372 "ace.yacc"
    {
		this_report.output.right_margin=atoi((yyvsp[(3) - (3)].str));
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 375 "ace.yacc"
    {
		this_report.output.top_of_page=acl_strdup((yyvsp[(2) - (2)].str));
	}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 382 "ace.yacc"
    { execute_selects(); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 386 "ace.yacc"
    { add_select((yyvsp[(1) - (1)].str),temp_tab_name); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 387 "ace.yacc"
    { add_select((yyvsp[(3) - (3)].str),temp_tab_name); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 398 "ace.yacc"
    {
		struct acerep_commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,NULL,cmd);
	  }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 417 "ace.yacc"
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 421 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_TRAILER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 425 "ace.yacc"
    {
		add_fmt(FORMAT_PAGE_HEADER,NULL,(yyvsp[(3) - (3)].commands));
	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 429 "ace.yacc"
    {
		add_fmt(FORMAT_ON_EVERY_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 432 "ace.yacc"
    {
		add_fmt(FORMAT_ON_LAST_ROW,NULL,(yyvsp[(4) - (4)].commands));
	}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 435 "ace.yacc"
    {
		add_fmt(FORMAT_BEFORE_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 438 "ace.yacc"
    {
		add_fmt(FORMAT_AFTER_GROUP,DUP((yyvsp[(4) - (5)].expr)),(yyvsp[(5) - (5)].commands));
	}
    break;

  case 77:

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
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

/* Line 1455 of yacc.c  */
#line 480 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 484 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 492 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 495 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 495 "ace.yacc"
    {
	printf("speclist : %s ",(yyvsp[(3) - (3)].str));
	SPRINTF1((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str));}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 499 "ace.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 508 "ace.yacc"
    {
		SPRINTF1((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 518 "ace.yacc"
    { ordbycnt=0; }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 518 "ace.yacc"
    { SPRINTF1((yyval.str),"ORDER BY %s",(yyvsp[(3) - (3)].str)); }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 523 "ace.yacc"
    {
SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 528 "ace.yacc"
    {
		if (strlen((yyvsp[(2) - (2)].str))) {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 534 "ace.yacc"
    {
		char buff[256];
		SPRINTF1(buff,"I%d",atoi((yyvsp[(1) - (1)].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 539 "ace.yacc"
    {
		char buff[256];
		SPRINTF1(buff,"C%s",(yyvsp[(1) - (1)].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 548 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 556 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 562 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 568 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 573 "ace.yacc"
    {SPRINTF1((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[(2) - (2)].str));}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 578 "ace.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 582 "ace.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 583 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 586 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s, OUTER %s",(yyvsp[(1) - (4)].str),(yyvsp[(4) - (4)].str));
        }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 589 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s, OUTER (%s)",(yyvsp[(1) - (6)].str),(yyvsp[(5) - (6)].str));
        }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 592 "ace.yacc"
    {
		SPRINTF3((yyval.str),"%s LEFT OUTER JOIN %s ON %s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 595 "ace.yacc"
    {
		SPRINTF3((yyval.str),"%s INNER JOIN %s ON %s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 600 "ace.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 601 "ace.yacc"
    {SPRINTF1((yyval.str),"(%s)",(yyvsp[(2) - (3)].str)); }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 606 "ace.yacc"
    {
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		ace_add_table((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 620 "ace.yacc"
    {
SPRINTF4((yyval.str),"%s %s %s %s",
(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),
(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 627 "ace.yacc"
    {strcpy((yyval.str),"\n0");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 631 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 635 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 642 "ace.yacc"
    {
			SPRINTF3((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 650 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 656 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 662 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 667 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 668 "ace.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 674 "ace.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 676 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 701 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 703 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 705 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 707 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 714 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 717 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 724 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 726 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 728 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 730 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 732 "ace.yacc"
    {SPRINTF6((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 746 "ace.yacc"
    {SPRINTF0((yyval.str),"<=");}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 747 "ace.yacc"
    {SPRINTF0((yyval.str),">=");}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 757 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 771 "ace.yacc"
    { SPRINTF1((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[(1) - (1)].str))); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 772 "ace.yacc"
    {SPRINTF0((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 773 "ace.yacc"
    { SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 774 "ace.yacc"
    { SPRINTF3((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[(1) - (3)].str)),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));  }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 784 "ace.yacc"
    {SPRINTF0((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 788 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 789 "ace.yacc"
    {SPRINTF1((yyval.str),"[%s]",(yyvsp[(2) - (3)].str));}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 790 "ace.yacc"
    {SPRINTF2((yyval.str),"[%s,%s]",(yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 793 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 794 "ace.yacc"
    { SPRINTF3((yyval.str),"%s.%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 795 "ace.yacc"
    { SPRINTF2((yyval.str),"%s.%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 806 "ace.yacc"
    {SPRINTF1((yyval.str),"0.%s",(yyvsp[(2) - (2)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 812 "ace.yacc"
    {reset_sql_stuff();}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 815 "ace.yacc"
    {SPRINTF5((yyval.str),"%s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));
}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 827 "ace.yacc"
    {SPRINTF5((yyval.str),"%s %s %s %s %s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].str) );}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 831 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 832 "ace.yacc"
    {
       SPRINTF3((yyval.str),"%s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));
       }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 836 "ace.yacc"
    {
       SPRINTF2((yyval.str),"INTO TEMP %s%s ",(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (4)].str));
}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 840 "ace.yacc"
    {
       SPRINTF3((yyval.str),"%s INTO TEMP %s%s ",(yyvsp[(1) - (5)].str), (yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	strcpy(temp_tab_name,(yyvsp[(3) - (5)].str));
}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 848 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 848 "ace.yacc"
    {strcpy((yyval.str)," WITH NO LOG");}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 859 "ace.yacc"
    {SPRINTF6((yyval.str)," %s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 862 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 863 "ace.yacc"
    {SPRINTF0((yyval.str),"ALL");}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 864 "ace.yacc"
    {SPRINTF0((yyval.str),"DISTINCT");}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 865 "ace.yacc"
    {SPRINTF0((yyval.str),"DISTINCT");}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 870 "ace.yacc"
    { SPRINTF2((yyval.str)," %s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 874 "ace.yacc"
    {
			if (strcmp((yyvsp[(1) - (1)].str),"rowid")==0) {
				SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
				add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
			} else {
				add_select_column((yyvsp[(1) - (1)].str),(yyvsp[(1) - (1)].str));
			}
		}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 882 "ace.yacc"
    {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_select_column((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 886 "ace.yacc"
    {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
			add_select_column((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 897 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS YEAR");}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 898 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS MONTH"); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 899 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS DAY);"); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 900 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS HOUR);"); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 901 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS MINUTE);"); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 902 "ace.yacc"
    {SPRINTF0((yyval.str),"UNITS SECOND);"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 906 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s", (yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 909 "ace.yacc"
    {SPRINTF2((yyval.str)," %s[%s]",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 910 "ace.yacc"
    {SPRINTF3((yyval.str)," %s[%s,%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 911 "ace.yacc"
    {SPRINTF3((yyval.str)," %s.%s[%s]",(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 912 "ace.yacc"
    {SPRINTF4((yyval.str)," %s.%s[%s,%s]",(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str));}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 913 "ace.yacc"
    {
			if (find_variable((yyvsp[(2) - (2)].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
			SPRINTF1((yyval.str),"\n2(%d)",find_variable((yyvsp[(2) - (2)].str)));
			}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 918 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 920 "ace.yacc"
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 924 "ace.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 925 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 926 "ace.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 927 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 928 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 929 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 930 "ace.yacc"
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 931 "ace.yacc"
    {SPRINTF2((yyval.str),"%s(%s)",(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 933 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 935 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 937 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 939 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 941 "ace.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 945 "ace.yacc"
    {
			SPRINTF2((yyval.str),"CURRENT, %s TO %s",(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 948 "ace.yacc"
    {
			SPRINTF3((yyval.str),"%s, %s TO %s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
        }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 951 "ace.yacc"
    {
			SPRINTF3((yyval.str),"%s %s TO %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
        }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 957 "ace.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 963 "ace.yacc"
    {SPRINTF1((yyval.str),"/%s",(yyvsp[(2) - (2)].str));}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 964 "ace.yacc"
    {SPRINTF1((yyval.str)," MOD %s",(yyvsp[(2) - (2)].str));}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 965 "ace.yacc"
    {SPRINTF1((yyval.str)," POW %s",(yyvsp[(2) - (2)].str));}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 966 "ace.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 967 "ace.yacc"
    {SPRINTF1((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 968 "ace.yacc"
    {SPRINTF1((yyval.str),"+%s",(yyvsp[(2) - (2)].str));}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 969 "ace.yacc"
    {SPRINTF1((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 972 "ace.yacc"
    { SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 975 "ace.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 976 "ace.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 977 "ace.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 982 "ace.yacc"
    {
	SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1000 "ace.yacc"
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct acerep_command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[(1) - (1)].cmd));
		}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1005 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1027 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).acerep_command_u.acerep_commands.commands.commands_val=(yyvsp[(2) - (3)].commands).commands.commands_val;
		(yyval.cmd).acerep_command_u.acerep_commands.commands.commands_len=(yyvsp[(2) - (3)].commands).commands.commands_len;
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1037 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).acerep_command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[(2) - (5)].str));
	
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(4) - (5)].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr);
}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1055 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1065 "ace.yacc"
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1066 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (2)].expr));}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1070 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_IF;
	COPY((yyval.cmd).acerep_command_u.cmd_if.condition,(yyvsp[(2) - (5)].expr));
	(yyval.cmd).acerep_command_u.cmd_if.command=(struct acerep_command *)DUP((yyvsp[(4) - (5)].cmd));
	(yyval.cmd).acerep_command_u.cmd_if.elsecommand=(struct acerep_command *)DUP((yyvsp[(5) - (5)].cmd));
}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1078 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).acerep_command_u.null=1;
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1081 "ace.yacc"
    { COPY((yyval.cmd),(yyvsp[(2) - (2)].cmd)); }
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1086 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1097 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1108 "ace.yacc"
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

/* Line 1455 of yacc.c  */
#line 1121 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1128 "ace.yacc"
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[(1) - (3)].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(3) - (3)].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1140 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).acerep_command_u.cmd_need.nlines=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1146 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).acerep_command_u.cmd_pause.message=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1153 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).acerep_command_u.cmd_print.printnl=atoi((yyvsp[(3) - (3)].str));
	(yyval.cmd).acerep_command_u.cmd_print.print=(yyvsp[(2) - (3)].expr);
}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1161 "ace.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1161 "ace.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1164 "ace.yacc"
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename=acl_strdup((yyvsp[(2) - (2)].str));
}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1170 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).acerep_command_u.cmd_skip.nlines=atoi((yyvsp[(2) - (3)].str));

	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1175 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).acerep_command_u.cmd_skip.nlines=-1;
	}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1182 "ace.yacc"
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		COPY((yyval.cmd).acerep_command_u.cmd_while.condition,(yyvsp[(2) - (4)].expr));
		(yyval.cmd).acerep_command_u.cmd_while.command=(struct acerep_command *)DUP((yyvsp[(4) - (4)].cmd));
}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1290 "ace.yacc"
    {
			(yyval.exprptr)=0;
		}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1294 "ace.yacc"
    { 
			(yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); 
		}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1301 "ace.yacc"
    {
		COPY((yyval.agg_val),(yyvsp[(1) - (2)].agg_val));
		(yyval.agg_val).wexpr=(yyvsp[(2) - (2)].exprptr); 
		}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1309 "ace.yacc"
    { (yyval.exprptr)=DUP((yyvsp[(2) - (2)].expr)); }
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1313 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1319 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1325 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1331 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1337 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1343 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1349 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(2) - (2)].exprptr);
		(yyval.agg_val).isgroup=0;
	}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1356 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1362 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1368 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1374 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1380 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1386 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1392 "ace.yacc"
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[(3) - (3)].exprptr);
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1402 "ace.yacc"
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

  case 417:

/* Line 1455 of yacc.c  */
#line 1420 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1422 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1426 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1430 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1434 "ace.yacc"
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

  case 422:

/* Line 1455 of yacc.c  */
#line 1443 "ace.yacc"
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

  case 423:

/* Line 1455 of yacc.c  */
#line 1453 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1460 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1466 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1472 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1479 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1485 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1486 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 1491 "ace.yacc"
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

  case 431:

/* Line 1455 of yacc.c  */
#line 1513 "ace.yacc"
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

  case 432:

/* Line 1455 of yacc.c  */
#line 1531 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(1) - (1)].expr)); }
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 1533 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 1537 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 1541 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 1545 "ace.yacc"
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

  case 437:

/* Line 1455 of yacc.c  */
#line 1554 "ace.yacc"
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

  case 438:

/* Line 1455 of yacc.c  */
#line 1564 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 1571 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 1577 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 1583 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 1590 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[(1) - (4)].str));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[(3) - (4)].expr).expr_u.lexpr;
	}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 1596 "ace.yacc"
    { COPY((yyval.expr),(yyvsp[(2) - (3)].expr)); }
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 1597 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 1603 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 1609 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[(1) - (1)].var_usage);
	}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 1614 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[(1) - (1)].agg_val));
	}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 1619 "ace.yacc"
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

  case 449:

/* Line 1455 of yacc.c  */
#line 1641 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 1649 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 1657 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 1665 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 1672 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 1681 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 1687 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 1696 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 1703 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 1712 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 1720 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 1728 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 1736 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 1743 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 1752 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 1758 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 1767 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 1774 "ace.yacc"
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 1782 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 1788 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 1794 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 1800 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 1806 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 1812 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 1818 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 1824 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 1830 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 1836 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 1842 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[(2) - (2)].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[(1) - (2)].str)); 
		}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 1850 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_SPACES; 
	}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 1857 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 1863 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 1871 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 1881 "ace.yacc"
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

  case 483:

/* Line 1455 of yacc.c  */
#line 1897 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 1904 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[(1) - (1)].expr));
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 1911 "ace.yacc"
    {
		COPY((yyval.expr),(yyvsp[(1) - (3)].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[(3) - (3)].expr));

	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 1922 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 1926 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 1930 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[(1) - (1)].str));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 1934 "ace.yacc"
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[(1) - (1)].str));
	}
    break;



/* Line 1455 of yacc.c  */
#line 5976 "y.tab.c"
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
#line 1942 "ace.yacc"


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif

