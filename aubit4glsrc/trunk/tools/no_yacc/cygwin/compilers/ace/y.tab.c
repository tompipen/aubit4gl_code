/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         a4gl_ace_yyparse
#define yylex           a4gl_ace_yylex
#define yyerror         a4gl_ace_yyerror
#define yydebug         a4gl_ace_yydebug
#define yynerrs         a4gl_ace_yynerrs

#define yylval          a4gl_ace_yylval
#define yychar          a4gl_ace_yychar

/* Copy the first part of user declarations.  */
#line 1 "ace.yacc" /* yacc.c:339  */

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



#line 143 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int a4gl_ace_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NAME = 258,
    COMMA = 259,
    ASCII = 260,
    COLUMN = 261,
    SPACES = 262,
    USING = 263,
    WHERE = 264,
    KW_OR = 265,
    KW_AND = 266,
    CLIPPED = 267,
    NOT = 268,
    IS_NOT_NULL = 269,
    IS_NULL = 270,
    GREATER_THAN = 271,
    GREATER_THAN_EQ = 272,
    LESS_THAN = 273,
    LESS_THAN_EQ = 274,
    EQUAL = 275,
    NOT_EQUAL = 276,
    COMPARISON = 277,
    MATCHES = 278,
    NOT_MATCHES = 279,
    LIKE = 280,
    NOT_LIKE = 281,
    PLUS = 282,
    MINUS = 283,
    MULTIPLY = 284,
    DIVIDE = 285,
    POW = 286,
    MOD = 287,
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
#define ASCII 260
#define COLUMN 261
#define SPACES 262
#define USING 263
#define WHERE 264
#define KW_OR 265
#define KW_AND 266
#define CLIPPED 267
#define NOT 268
#define IS_NOT_NULL 269
#define IS_NULL 270
#define GREATER_THAN 271
#define GREATER_THAN_EQ 272
#define LESS_THAN 273
#define LESS_THAN_EQ 274
#define EQUAL 275
#define NOT_EQUAL 276
#define COMPARISON 277
#define MATCHES 278
#define NOT_MATCHES 279
#define LIKE 280
#define NOT_LIKE 281
#define PLUS 282
#define MINUS 283
#define MULTIPLY 284
#define DIVIDE 285
#define POW 286
#define MOD 287
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 74 "ace.yacc" /* yacc.c:355  */

	char   str[30000];
	struct acerep_command cmd;
	struct expr expr;
	struct expr *exprptr;
	struct acerep_commands commands;
	struct agg_val agg_val;
	struct acerep_var_usage *var_usage;

#line 530 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE a4gl_ace_yylval;

int a4gl_ace_yyparse (void);



/* Copy the second part of user declarations.  */

#line 545 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3905

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  129
/* YYNRULES -- Number of rules.  */
#define YYNRULES  490
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  837

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   425

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "COMMA", "ASCII", "COLUMN",
  "SPACES", "USING", "WHERE", "KW_OR", "KW_AND", "CLIPPED", "NOT",
  "IS_NOT_NULL", "IS_NULL", "GREATER_THAN", "GREATER_THAN_EQ", "LESS_THAN",
  "LESS_THAN_EQ", "EQUAL", "NOT_EQUAL", "COMPARISON", "MATCHES",
  "NOT_MATCHES", "LIKE", "NOT_LIKE", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "POW", "MOD", "AFTER", "AFTGROUP", "ALL", "ANY", "ASC", "SUM", "ATSIGN",
  "KW_AS", "AVERAGE", "AVG", "BEFORE", "BETWEEN", "BOTTOM", "BY",
  "KW_CALL", "CH", "CHAR", "CHAR_VALUE", "CLOSE_BRACKET", "CLOSE_SQUARE",
  "COLON", "COMMANDS", "INNER_JOIN", "LEFT_JOIN", "COUNT", "TOTAL",
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
  "op_fmt_val_expr_list", "fmt_val_expr_list", "literal_expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -671

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-671)))

#define YYTABLE_NINF -179

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    30,   101,    -2,    60,    78,  -671,    28,    93,  -671,
    -671,  -671,    92,    96,   110,    92,     4,  -671,    82,   118,
    -671,  -671,   239,  3443,  -671,  -671,   159,  3443,  -671,  -671,
     190,   -17,  -671,   442,   135,  -671,    92,   160,  -671,  -671,
     178,  -671,  -671,  -671,  -671,   181,  -671,  -671,   183,  -671,
    -671,   282,  -671,    92,  -671,  -671,   234,   255,   260,   217,
     289,   290,   355,   510,  -671,   355,  -671,   325,   -33,   338,
    -671,  3443,   159,   159,   159,   159,    92,   421,   159,   159,
     159,     5,   159,   159,  -671,  -671,  -671,  -671,   364,    13,
     363,  -671,  -671,   299,  -671,  -671,   392,    58,   113,   394,
    3443,   355,  -671,  -671,  -671,   355,   355,  -671,  -671,  -671,
     355,    17,  -671,  -671,  -671,  1735,   360,   362,   314,   331,
      -3,   -42,   219,  -671,  -671,  -671,   159,  -671,   159,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  2045,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
     335,  -671,   341,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,   348,  -671,  -671,   350,  -671,   351,  -671,  -671,
    -671,  -671,  -671,  3060,   374,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,   379,  -671,  -671,  -671,  -671,  -671,  1735,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,   380,   382,   383,   386,
    -671,  -671,    34,  -671,  3297,   107,  -671,   357,   413,   402,
     420,   395,   397,   -15,   -15,  -671,  -671,  -671,   488,   489,
    2045,   470,  -671,   538,  -671,   180,   473,   492,  -671,  -671,
      -7,    18,    18,    18,  1735,  1735,  -671,  -671,  1735,   404,
      18,    18,  1735,  1405,  1735,  2625,   537,   301,   301,   301,
     301,   301,   301,   438,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  2770,  1735,   159,   -13,   -13,  -671,   -15,
     -15,   -15,  1900,    92,   564,   439,   159,   355,   564,    23,
     -55,   564,   -15,   -15,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,   -15,  -671,  -671,   538,  3060,
    2045,  -671,  -671,  -671,  2915,  3060,   466,  -671,  -671,  -671,
    -671,  1735,  1735,  1735,  3358,   202,   203,   227,  -671,  1735,
    1735,   228,    20,   327,   513,  -671,   137,  -671,  3060,   514,
     910,  -671,   479,  -671,  -671,  -671,  1735,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,   450,   230,    50,  -671,   453,  -671,
     -15,   -15,   -15,   -15,   -15,  -671,  -671,  -671,  -671,   455,
    -671,   558,   564,   564,   564,   464,   464,  -671,  -671,   464,
     467,  -671,   476,    63,  -671,  -671,  -671,   477,   220,  -671,
     564,  -671,  -671,   464,   464,   478,  -671,  -671,  -671,   572,
    3263,  -671,    16,   483,  -671,   458,   594,  3400,  -671,  -671,
     451,   497,  3591,  3415,  -671,  -671,  -671,  -671,  -671,   485,
    -671,   123,  3303,  3311,  3319,  1735,  -671,  -671,  -671,  3328,
    3344,  -671,   302,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
     463,   302,  -671,  2190,  2335,  2335,  -671,  -671,  1240,   491,
     491,   745,   602,   604,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  3419,  3211,  1735,  -671,   525,  3358,   159,  -671,   159,
    -671,   564,   -15,   -15,   564,   564,  3400,  3400,   461,   557,
    -671,  -671,  -671,   564,   564,   464,   464,  -671,   464,  -671,
     464,   464,   564,   564,  3776,  -671,  -671,   564,   564,  -671,
    -671,   564,   564,   564,  -671,  -671,  -671,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   -15,  -671,   564,   564,  -671,  -671,
    -671,   564,  -671,  -671,   -15,  -671,  -671,   519,  -671,  -671,
    -671,  -671,  3358,  -671,  -671,   472,   574,   482,  2480,  -671,
    2625,   137,   507,   518,  -671,   498,  -671,  -671,    13,    72,
     396,   910,   910,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  1735,  -671,   509,   521,   198,  1075,
     626,  -671,  3358,   910,  -671,   -92,   125,   588,  3620,  3400,
     590,   638,  3237,   557,   526,  -671,   529,  -671,  -671,   530,
     256,   564,  -671,   531,  -671,   340,  -671,   231,   242,  -671,
    -671,  -671,  -671,  -671,   276,   279,  -671,   281,  3542,  3400,
    3852,  3873,  3373,  3373,  3373,  3373,  3373,  3373,  3373,  3373,
    3373,  3373,  3373,   461,   461,   358,   358,  -671,  -671,   577,
     594,  3659,  3400,  -671,   599,   574,  -671,   535,  -671,  -671,
    -671,  -671,  -671,  -671,   574,  2625,  -671,    87,   910,   910,
    1735,  -671,   604,  -671,  3358,   648,  -671,   648,  -671,  -671,
    -671,  1735,  -671,  -671,  1570,  -671,   491,  -671,  -671,  -671,
    3358,  1735,   602,  -671,    18,  -671,   571,   159,  -671,  -671,
     564,  -671,  -671,   564,   564,   506,   564,   564,   564,   564,
    3814,   564,   557,   557,  -671,   557,   557,   557,   557,   557,
     557,  -671,  -671,  -671,  -671,  -671,  -671,   -15,  -671,   564,
     633,  -671,  -671,   578,  -671,   167,  -671,   602,   602,    34,
    3060,  -671,   292,  -671,   297,   168,  -671,  -671,  2045,   541,
     523,  -671,   617,  3698,  3400,  3290,   298,   310,   329,   332,
    -671,   337,   673,   709,   506,   506,   371,   371,  -671,  -671,
    -671,  3737,   564,   636,  -671,   537,   637,  -671,   658,  -671,
    -671,  1735,   538,    13,  -671,  3060,  -671,  -671,   564,   620,
    -671,  -671,  -671,  -671,  -671,   670,   594,  -671,   479,  -671,
    -671,  3358,  1735,   527,  -671,  3400,   -15,   564,   525,    34,
    -671,  -671,  -671,   594,  -671,   -92,  -671
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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
     333,   386,   332,   335,   364,   229,   375,   321,   323,   322,
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
       0,   119,   120,   269,   270,   265,     0,   266,   264,   260,
     262,   261,   208,   225,   224,     0,     0,    81,    79,    80,
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
     219,     0,    76,    75,   483,     0,   446,   445,   432,     0,
     405,   407,   406,     0,     0,     0,     0,   410,     0,   411,
       0,     0,     0,     0,     0,   409,   408,     0,     0,   401,
     479,     0,     0,     0,   482,   481,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   449,     0,     0,   307,   311,
     309,     0,   315,   314,     0,   287,   183,     0,   180,   240,
     237,   241,   272,   238,   239,     0,     0,     0,     0,   108,
       0,   113,     0,     0,   129,     0,   132,   133,   200,     0,
     147,     0,     0,   158,   164,   157,   163,   154,   156,   155,
     161,   159,   162,   160,     0,   148,     0,     0,     0,     0,
     102,   103,   209,     0,   123,   193,     0,     0,     0,   485,
       0,   484,     0,     0,   422,   423,     0,   420,   419,     0,
      79,     0,   421,     0,   430,   402,   418,     0,     0,   412,
     414,   413,   416,   415,     0,     0,   444,     0,   400,   467,
     460,   459,   472,   478,   471,   477,   468,   470,   469,   475,
     473,   476,   474,   465,   466,   464,   461,   462,   463,   298,
     300,     0,   306,   316,     0,     0,   254,   258,   255,   256,
     253,   257,   252,   244,     0,     0,   109,     0,     0,     0,
       0,   131,   125,   127,   135,     0,   142,     0,   144,   150,
     149,     0,   138,   140,     0,   139,     0,   136,   137,   152,
     151,     0,   101,    91,   169,   195,   190,     0,   221,   220,
       0,    78,   288,     0,     0,   417,     0,     0,     0,     0,
       0,     0,     0,     0,   458,     0,     0,     0,     0,     0,
       0,   431,   439,   442,   440,   443,   441,     0,   297,     0,
       0,   181,   242,     0,   243,     0,   114,   112,   111,     0,
       0,   273,     0,   145,     0,     0,   134,   104,     0,     0,
       0,   189,     0,     0,   486,   295,     0,     0,     0,     0,
     429,     0,   451,   450,   456,   457,   455,   452,   453,   454,
     299,     0,     0,     0,   110,   118,     0,   274,     0,   141,
     143,     0,    92,   200,   194,     0,   222,    77,     0,     0,
     424,   427,   425,   428,   426,     0,   301,   259,   120,   199,
     146,   153,     0,   196,   198,   296,     0,     0,   122,     0,
     197,   191,   294,   302,   117,   193,   192
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -671,  -671,  -671,  -671,  -671,  -671,   678,  -671,  -671,    -8,
      22,  -671,  -671,  -671,   664,  -671,  -671,  -671,   643,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,   587,  -276,   403,  -671,
    -671,  -671,  -658,  -671,  -671,  -241,   372,  -671,  -671,  -671,
    -671,  -671,  -671,   471,  -281,   240,  -459,  -113,   -81,   -95,
    -101,  -469,   142,   134,   257,  -671,  -671,  -671,  -671,  -671,
    -671,    37,  -671,  -671,   252,  -671,  -270,  -136,  -671,  -184,
     295,  -671,  -671,  -115,   653,  -671,  -671,  -671,   -88,  -671,
    -671,  -422,  -582,  -670,   465,    39,  -671,  -102,  -671,  -384,
    -522,  -671,   109,  -671,   191,   -50,  -164,  -294,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -551,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,   -57,   -31,  -129,  -671,  -671,  -671,
    -134,  -671,  -420,   -27,  -671,  -671,  -671,  -462,  -429
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     241,   266,   352,   353,   366,   670,   690,    27,   270,    12,
     359,   360,   589,   244,   579,    96,    97,    98,    99,   338,
     759,   102,   103,   104,   462,   108,   109,   713,    71,   444,
     389,   389,   312,    12,    88,     4,   556,   761,   284,   761,
      92,   444,    50,   438,   276,    77,  -177,   253,   112,    52,
     107,   637,   638,   348,   499,    84,    54,   586,   587,   714,
     644,   645,   126,     7,  -178,   647,   313,     1,   100,   258,
     132,   259,   251,    84,   133,   134,   314,    28,   575,   135,
     636,   113,   591,   463,   387,   105,   349,   577,   315,    13,
     335,   473,   440,    95,   241,   316,   388,   252,   444,   444,
     444,     6,   500,   464,   515,   516,    93,   279,   254,   127,
     465,   346,   317,    13,   318,    30,   319,   128,   285,   686,
     517,   518,   131,   691,   266,   320,   466,   567,   467,   717,
      14,   270,   388,    10,   557,   106,   136,   137,   756,     5,
     761,   473,   474,   475,   712,   392,   393,   394,   321,   444,
     322,    11,   829,   752,    14,   445,   369,   468,   443,   241,
     241,   450,   754,   241,   129,   114,    15,   241,   241,   241,
     350,   473,   354,   354,   384,   568,   354,   718,   303,   801,
     354,   363,   244,   400,   696,   698,    18,   709,   469,   241,
      15,   519,   474,   475,   636,   287,   288,   289,   290,   291,
     292,    21,   354,   725,   266,    24,   455,   455,   444,   444,
     446,   270,   699,   700,    30,   449,   446,   341,   794,   757,
     758,   822,   474,   475,   304,   305,   502,   503,    26,   520,
     521,   455,   455,   634,   455,   723,   241,   241,   241,   477,
      33,   816,   701,    36,   241,   241,   723,   342,   386,   452,
     453,   454,   116,   456,   457,   241,    50,   459,   460,   433,
     669,   241,   117,   441,   776,   777,   778,   779,    65,   781,
     673,    53,   511,    66,   496,   512,   833,    72,   458,   461,
     723,   498,   742,   723,   766,   723,   434,   430,   439,   525,
     526,   437,   255,   743,   442,    73,   798,   119,    74,   687,
      75,   798,   723,   636,   636,   401,   636,   636,   636,   636,
     636,   636,   782,   783,   723,   784,   785,   786,   787,   788,
     789,   295,   296,   297,   298,   299,   300,   744,   373,   374,
     745,   471,   746,   723,    76,   120,   723,   523,   501,    78,
     241,   723,   121,   799,   369,   369,   369,   634,   800,   810,
     732,   733,   734,   572,   287,   288,   289,   290,   291,   292,
      79,   811,    80,   241,    81,   463,   241,   735,   736,   737,
     738,   739,   740,   729,   501,   506,   507,   508,   241,   590,
     812,   639,   640,   813,   641,   464,   642,   643,   814,   552,
     553,   612,   465,   524,    82,    83,   116,   377,   378,   379,
     380,   381,   739,   740,   755,    84,   117,    90,   466,   605,
     467,    94,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   287,   288,   289,   290,   291,   292,   101,
     110,   287,   288,   289,   290,   291,   292,    66,   118,   468,
     616,   119,   617,   125,   769,   130,   247,   358,   248,   369,
     249,   369,   271,   790,   250,   358,   634,   634,   272,   634,
     634,   634,   634,   634,   634,   273,   356,   274,   275,   357,
     469,   277,   306,   361,   618,   308,   241,   241,   622,   120,
     295,   296,   297,   298,   299,   300,   121,    56,   606,   241,
     550,   551,   552,   553,   241,   385,   278,   280,   241,   281,
     282,   648,   694,   283,   649,   650,   651,   710,   607,   309,
     652,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,   802,   307,   437,
     671,   310,   832,   311,   672,   737,   738,   739,   740,   336,
     337,   339,   340,    57,   344,   345,   370,   382,   432,   295,
     296,   297,   298,   299,   300,    56,   369,   295,   296,   297,
     298,   299,   300,   451,   472,    58,   493,  -177,   497,   402,
     403,   501,   504,   241,   241,   241,    59,    60,   505,   509,
     241,   528,   241,    86,   513,   623,   241,   558,   244,   241,
      61,    62,   404,   514,   522,   527,   241,   559,   561,   765,
     562,   563,   279,   346,   730,   405,   406,   407,   585,   612,
     576,    57,   591,   613,   407,   592,   674,   624,   625,   675,
     626,   408,   409,   688,   410,   411,   695,   412,   174,   684,
     711,   797,   266,    58,   689,   174,   588,   676,   697,   270,
     719,   722,   723,   726,    59,    60,   727,   728,   731,   747,
     413,   751,   753,   792,   414,   627,   628,   677,    61,    62,
     772,   414,   415,   416,   678,   629,   630,   770,   805,   806,
     206,   419,   417,   418,   631,   793,   824,   206,   419,   803,
     679,   420,   680,   241,   733,   734,   241,   817,   819,   826,
     827,   830,   421,   773,    29,    55,   774,   775,   160,   821,
     735,   736,   737,   738,   739,   740,    87,   241,   160,   257,
     391,   681,   447,   286,   818,   583,   835,   632,   760,   174,
     244,   734,   791,   828,   422,   633,   693,   834,   760,   174,
     423,   424,   425,   692,   764,   584,   735,   736,   737,   738,
     739,   740,   682,   604,   566,   192,   124,   836,   820,   365,
     767,   140,   141,     0,     0,   192,     0,   142,   478,     0,
       0,   206,   207,     0,     0,   437,     0,   143,     0,     0,
     144,   206,   207,     0,   145,     0,   146,     0,   147,   148,
       0,   825,   149,   150,     0,   151,   588,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,   161,
     437,     0,   162,   163,   164,   165,     0,   166,   167,   168,
     169,   170,   171,     0,   172,   173,   174,   175,     0,   176,
     177,   479,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   480,     0,   206,   207,
     208,     0,   481,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,   588,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   140,   141,     0,     0,
       0,     0,   142,   478,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,   144,     0,     0,     0,   145,
       0,   146,     0,   147,   148,     0,     0,   149,   150,     0,
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
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   140,   141,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,     0,     0,
     144,     0,     0,     0,   145,     0,   146,     0,   147,   148,
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
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,   144,     0,     0,     0,   145,
       0,   146,     0,   147,   148,     0,     0,   149,   150,     0,
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
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   140,   141,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,     0,     0,
     144,     0,     0,     0,   145,     0,   146,     0,   147,   148,
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
     235,   236,   237,   238,   362,   239,   140,   141,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,   144,     0,     0,     0,   145,
       0,   146,     0,   147,   148,     0,     0,   149,   150,     0,
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
       0,     0,     0,     0,     0,     0,     0,   143,     0,     0,
     144,     0,     0,     0,   145,     0,   146,     0,   147,   148,
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
     235,   236,   237,   238,     0,   239,   140,   141,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,   144,     0,     0,     0,     0,
       0,   146,     0,   147,   148,     0,     0,   149,     0,     0,
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
     229,   140,   141,     0,     0,     0,     0,   142,     0,   230,
       0,   232,   233,   234,     0,   235,     0,   143,   398,     0,
     144,     0,     0,     0,     0,     0,   146,     0,   147,   148,
       0,     0,   149,     0,     0,   151,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   261,     0,     0,     0,   161,
       0,     0,     0,   163,   164,     0,     0,   166,     0,   168,
     169,   170,   171,     0,   172,     0,     0,   175,     0,   176,
     177,     0,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,   262,     0,     0,   195,   196,   197,   198,   199,
     200,   201,   202,     0,   204,   205,     0,     0,     0,     0,
     208,     0,     0,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,   140,   141,     0,     0,
       0,     0,   142,     0,   230,     0,   232,   233,   234,     0,
     235,     0,   143,     0,     0,   144,     0,     0,     0,     0,
       0,   146,     0,   147,   148,     0,     0,   149,     0,     0,
     151,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     261,     0,     0,     0,   161,     0,     0,     0,   163,   164,
       0,     0,   166,     0,   168,   169,   170,   171,     0,   172,
       0,     0,   175,     0,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,   202,     0,   204,
     205,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,   578,   210,   211,     0,     0,   212,   213,     0,     0,
     214,     0,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
     229,   140,   141,     0,     0,     0,     0,   142,     0,   230,
       0,   232,   233,   234,     0,   235,     0,   143,     0,     0,
     144,     0,     0,     0,     0,     0,   146,     0,   147,   148,
       0,     0,   149,     0,     0,   151,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   261,     0,     0,     0,   161,
       0,     0,     0,   163,   164,     0,     0,   166,     0,   168,
     169,   170,   171,     0,   172,     0,     0,   175,     0,   176,
     177,     0,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,     0,     0,     0,   195,   196,   197,   198,   199,
     200,   201,   202,     0,   204,   205,     0,     0,     0,     0,
     208,     0,   580,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,   140,   141,     0,     0,
       0,     0,   142,     0,   230,     0,   232,   233,   234,     0,
     235,     0,   143,     0,     0,   144,     0,     0,     0,     0,
       0,   146,     0,   147,   148,     0,     0,   149,     0,     0,
     151,     0,     0,   153,   154,   155,   156,   157,   158,   159,
     261,     0,     0,     0,   161,     0,     0,     0,   163,   164,
       0,     0,   166,     0,   168,   169,   170,   171,     0,   172,
       0,     0,   175,     0,   176,   177,     0,   178,   179,   180,
       0,   181,   182,   183,   184,   185,   186,     0,     0,   187,
     188,   189,   190,   191,     0,     0,     0,     0,     0,     0,
     195,   196,   197,   198,   199,   200,   201,   202,     0,   204,
     205,     0,     0,     0,     0,   208,     0,   685,     0,     0,
       0,     0,   210,   211,     0,     0,   212,   213,     0,     0,
     214,     0,   215,   216,   217,   218,   219,   220,     0,     0,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
     229,   140,   141,     0,     0,     0,     0,   142,     0,   230,
       0,   232,   233,   234,     0,   235,     0,   143,     0,     0,
     144,     0,     0,     0,     0,     0,   146,     0,   147,   148,
       0,     0,   149,     0,     0,   151,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   261,     0,     0,     0,   161,
       0,     0,     0,   163,   164,     0,     0,   166,     0,   168,
     169,   170,   171,     0,   172,     0,     0,   175,     0,   176,
     177,     0,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,     0,     0,     0,   195,   196,   197,   198,   199,
     200,   201,   202,     0,   204,   205,     0,     0,     0,     0,
     208,     0,     0,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,   140,   141,     0,     0,
       0,     0,   142,     0,   230,     0,   232,   233,   234,     0,
     235,     0,   143,     0,     0,   144,     0,     0,     0,   383,
       0,   146,     0,   147,   148,     0,     0,   149,     0,     0,
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
     229,   140,   141,     0,     0,     0,     0,   142,     0,   230,
       0,   232,   233,   234,     0,   235,     0,   143,     0,     0,
     144,     0,     0,     0,   448,     0,   146,     0,   147,   148,
       0,     0,   149,     0,     0,   151,     0,     0,   153,   154,
     155,   156,   157,   158,   159,     0,     0,     0,     0,   161,
       0,     0,     0,   163,   164,     0,     0,   166,     0,   168,
     169,   170,   171,     0,   172,     0,     0,   175,     0,   176,
     177,     0,   178,   179,   180,     0,   181,   182,   183,   184,
     185,   186,     0,     0,   187,   188,   189,   190,   191,     0,
       0,     0,     0,     0,     0,   195,   196,   197,   198,   199,
     200,   201,   202,     0,   204,   205,     0,     0,     0,     0,
     208,     0,     0,     0,     0,     0,     0,   210,   211,     0,
       0,   212,   213,     0,     0,   214,     0,   215,   216,   217,
     218,   219,   220,     0,     0,   221,   222,   223,     0,   224,
     225,   226,   227,   228,     0,   229,   140,   141,     0,     0,
       0,     0,   142,     0,   230,     0,   232,   233,   234,     0,
     235,     0,   143,     0,     0,   144,     0,     0,     0,     0,
       0,   146,     0,   147,   148,     0,     0,   149,     0,     0,
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
     229,     0,     0,     0,     0,     0,     0,     0,     0,   230,
       0,   232,   233,   234,   605,   235,     0,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   287,   288,
     289,   290,   291,   292,   530,   531,     0,   532,   533,   534,
       0,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     530,   531,     0,   532,   533,   534,     0,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,     0,   530,   531,     0,
     532,   533,   534,   606,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   607,   287,   288,   289,   290,   291,   292,
     287,   288,   289,   290,   291,   292,     0,   293,   287,   288,
     289,   290,   291,   292,     0,     0,   287,   288,   289,   290,
     291,   292,     0,     0,   569,   287,   288,   289,   290,   291,
     292,     0,   570,     0,   295,   296,   297,   298,   299,   300,
     571,   287,   288,   289,   290,   291,   292,     0,     0,   573,
       0,     0,     0,     0,   724,   287,   288,   289,   290,   291,
     292,     0,     0,     0,     0,   574,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   294,   530,   531,   554,
     532,   533,   534,     0,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,     0,   808,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,     0,     0,     0,     0,
     295,   296,   297,   298,   299,   300,   295,   296,   297,   298,
     299,   300,   312,     0,   295,   296,   297,   298,   299,   300,
       0,     0,   295,   296,   297,   298,   299,   300,     0,     0,
       0,   295,   296,   297,   298,   299,   300,     0,   565,     0,
       0,     0,    37,     0,     0,     0,   313,   295,   296,   297,
     298,   299,   300,    38,     0,    39,   314,    40,     0,     0,
       0,   295,   296,   297,   298,   299,   300,     0,   315,     0,
       0,     0,    41,     0,     0,   316,     0,     0,    42,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    44,     0,
       0,     0,   317,     0,   318,     0,   319,     0,     0,     0,
      45,     0,   532,   533,   534,   320,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,     0,     0,     0,   321,     0,
     322,     0,     0,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   530,   531,
       0,   532,   533,   534,    48,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   720,     0,     0,   530,   531,     0,
     532,   533,   534,     0,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,     0,     0,     0,     0,     0,     0,     0,
     564,     0,     0,   749,     0,     0,   530,   531,     0,   532,
     533,   534,   721,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   530,   531,     0,   532,   533,
     534,   750,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   530,   531,     0,   532,   533,   534,
     807,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   530,   531,     0,   532,   533,   534,   815,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   530,   531,     0,   532,   533,   534,   646,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   533,   534,   780,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   534,     0,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553
};

static const yytype_int16 yycheck[] =
{
     115,   137,   272,   273,   285,   556,   588,    15,   137,     5,
     280,   281,   481,   115,   473,    72,    73,    74,    75,   260,
     690,    78,    79,    80,     4,    82,    83,   119,    36,   323,
     306,   307,    47,     5,    65,     5,    20,   695,     4,   697,
      73,   335,    97,   319,   173,    53,    53,    89,    35,    27,
      81,   513,   514,    35,     4,    50,    73,   479,   480,   151,
     522,   523,     4,    65,    71,   527,    81,    59,    76,   126,
     101,   128,    75,    50,   105,   106,    91,    73,   462,   110,
     509,    68,    10,    63,    97,    80,    68,   471,   103,    85,
     254,     4,   147,    71,   209,   110,   109,   100,   392,   393,
     394,     0,    52,    83,    41,    42,   139,   209,   150,    51,
      90,   118,   127,    85,   129,   132,   131,     4,    84,   578,
      57,    58,   100,    51,   260,   140,   106,     4,   108,     4,
     126,   260,   109,    73,   118,   130,   119,   120,    51,   109,
     798,     4,    55,    56,   613,   309,   310,   311,   163,   443,
     165,    73,   822,   675,   126,   339,   285,   137,   322,   274,
     275,   345,   684,   278,    51,   152,   162,   282,   283,   284,
     152,     4,   274,   275,   303,    52,   278,    52,    71,    11,
     282,   283,   284,   312,   606,   607,    93,   609,   168,   304,
     162,   128,    55,    56,   623,    27,    28,    29,    30,    31,
      32,   109,   304,   623,   340,   109,     4,     4,   502,   503,
     339,   340,    14,    15,   132,   344,   345,    37,    51,   688,
     689,   803,    55,    56,   117,   118,   390,   391,   118,   166,
     167,     4,     4,   509,     4,     4,   351,   352,   353,   368,
     122,   792,    44,     4,   359,   360,     4,    67,   305,   351,
     352,   353,    33,    51,    51,   370,    97,   359,   360,   316,
     554,   376,    43,   320,   726,   727,   728,   729,   133,   731,
     564,    81,   406,   138,   376,   409,   827,   117,    51,    51,
       4,    51,    51,     4,   706,     4,   317,   314,   319,   423,
     424,   318,    73,    51,   321,   117,     4,    78,   117,   580,
     117,     4,     4,   732,   733,   313,   735,   736,   737,   738,
     739,   740,   732,   733,     4,   735,   736,   737,   738,   739,
     740,   153,   154,   155,   156,   157,   158,    51,    27,    28,
      51,     4,    51,     4,    52,   116,     4,   117,   118,   105,
     455,     4,   123,    51,   473,   474,   475,   623,    51,    51,
      10,    11,    12,   455,    27,    28,    29,    30,    31,    32,
     105,    51,   102,   478,   147,    63,   481,    27,    28,    29,
      30,    31,    32,   117,   118,   402,   403,   404,   493,   481,
      51,   515,   516,    51,   518,    83,   520,   521,    51,    31,
      32,   493,    90,   420,   105,   105,    33,   288,   289,   290,
     291,   292,    31,    32,   685,    50,    43,    82,   106,    13,
     108,    73,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     8,
      66,    27,    28,    29,    30,    31,    32,   138,    75,   137,
     497,    78,   499,    51,   714,    51,    86,    51,    86,   578,
     136,   580,   117,   747,   123,    51,   732,   733,   117,   735,
     736,   737,   738,   739,   740,   117,   275,   117,   117,   278,
     168,    97,   115,   282,   501,    73,   591,   592,   505,   116,
     153,   154,   155,   156,   157,   158,   123,    45,    92,   604,
      29,    30,    31,    32,   609,   304,   117,   117,   613,   117,
     117,   528,   604,   117,   531,   532,   533,   609,   112,    89,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   768,   115,   556,
     557,   136,   826,   136,   561,    29,    30,    31,    32,    51,
      51,    71,     4,   101,    71,    53,     9,   109,   109,   153,
     154,   155,   156,   157,   158,    45,   685,   153,   154,   155,
     156,   157,   158,    97,    51,   123,    87,    53,   118,     5,
       6,   118,   117,   688,   689,   690,   134,   135,    20,   115,
     695,     9,   697,    73,   117,    28,   701,   104,   690,   704,
     148,   149,    28,   117,   117,   117,   711,   139,     4,   701,
     149,   104,   704,   118,   631,    41,    42,    50,   117,   711,
     147,   101,    10,    88,    50,    11,    97,    60,    61,   147,
      63,    57,    58,   116,    60,    61,   117,    63,    71,   147,
       4,   760,   768,   123,   116,    71,   138,    63,   117,   768,
      52,    51,     4,   117,   134,   135,   117,   117,   117,    72,
      86,    52,   117,    20,    97,    98,    99,    83,   148,   149,
     717,    97,    98,    99,    90,   108,   109,    96,   145,    52,
     113,   114,   108,   109,   117,    97,   805,   113,   114,   138,
     106,   117,   108,   798,    11,    12,   801,    51,    51,    69,
      20,   164,   128,   720,    16,    31,   723,   724,    50,   801,
      27,    28,    29,    30,    31,    32,    63,   822,    50,   122,
     307,   137,   340,   242,   795,   475,   829,   160,    70,    71,
     822,    12,   749,   818,   160,   168,   592,   828,    70,    71,
     166,   167,   168,   591,   697,   478,    27,    28,    29,    30,
      31,    32,   168,   491,   449,    97,    93,   835,   798,   284,
     711,     6,     7,    -1,    -1,    97,    -1,    12,    13,    -1,
      -1,   113,   114,    -1,    -1,   792,    -1,    22,    -1,    -1,
      25,   113,   114,    -1,    29,    -1,    31,    -1,    33,    34,
      -1,   808,    37,    38,    -1,    40,   138,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
     827,    -1,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,   138,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,    -1,
     165,   166,   167,   168,    -1,   170,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    38,    -1,
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
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,   167,   168,    -1,
     170,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,    34,
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
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    38,    -1,
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
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,    -1,   165,   166,   167,   168,    -1,
     170,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,    34,
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
     165,   166,   167,   168,   169,   170,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    38,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,    34,
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
     165,   166,   167,   168,    -1,   170,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
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
     150,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,   159,
      -1,   161,   162,   163,    -1,   165,    -1,    22,   168,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    62,    -1,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,
      75,    -1,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,   159,    -1,   161,   162,   163,    -1,
     165,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
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
     150,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,   159,
      -1,   161,   162,   163,    -1,   165,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    62,    -1,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,
      75,    -1,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    -1,   117,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,   159,    -1,   161,   162,   163,    -1,
     165,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
      40,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,
      -1,    -1,    62,    -1,    64,    65,    66,    67,    -1,    69,
      -1,    -1,    72,    -1,    74,    75,    -1,    77,    78,    79,
      -1,    81,    82,    83,    84,    85,    86,    -1,    -1,    89,
      90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,   109,
     110,    -1,    -1,    -1,    -1,   115,    -1,   117,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,   126,   127,    -1,    -1,
     130,    -1,   132,   133,   134,   135,   136,   137,    -1,    -1,
     140,   141,   142,    -1,   144,   145,   146,   147,   148,    -1,
     150,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,   159,
      -1,   161,   162,   163,    -1,   165,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    62,    -1,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,
      75,    -1,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,   159,    -1,   161,   162,   163,    -1,
     165,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
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
     150,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,   159,
      -1,   161,   162,   163,    -1,   165,    -1,    22,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,    34,
      -1,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    62,    -1,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,
      75,    -1,    77,    78,    79,    -1,    81,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,   127,    -1,    -1,   130,    -1,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,    -1,   150,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,   159,    -1,   161,   162,   163,    -1,
     165,    -1,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    -1,    -1,    37,    -1,    -1,
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
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,   161,   162,   163,    13,   165,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     7,     8,    -1,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       7,     8,    -1,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,     7,     8,    -1,
      10,    11,    12,    92,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,   112,    27,    28,    29,    30,    31,    32,
      27,    28,    29,    30,    31,    32,    -1,    40,    27,    28,
      29,    30,    31,    32,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    51,    27,    28,    29,    30,    31,
      32,    -1,    51,    -1,   153,   154,   155,   156,   157,   158,
      51,    27,    28,    29,    30,    31,    32,    -1,    -1,    51,
      -1,    -1,    -1,    -1,   147,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    51,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   109,     7,     8,   146,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,   144,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
     153,   154,   155,   156,   157,   158,   153,   154,   155,   156,
     157,   158,    47,    -1,   153,   154,   155,   156,   157,   158,
      -1,    -1,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   153,   154,   155,   156,   157,   158,    -1,    73,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    81,   153,   154,   155,
     156,   157,   158,    60,    -1,    62,    91,    64,    -1,    -1,
      -1,   153,   154,   155,   156,   157,   158,    -1,   103,    -1,
      -1,    -1,    79,    -1,    -1,   110,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    -1,   127,    -1,   129,    -1,   131,    -1,    -1,    -1,
     107,    -1,    10,    11,    12,   140,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,   163,    -1,
     165,    -1,    -1,    -1,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
      -1,    10,    11,    12,   161,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     4,    -1,    -1,     7,     8,    -1,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,     4,    -1,    -1,     7,     8,    -1,    10,
      11,    12,    52,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,     8,    -1,    10,    11,
      12,    52,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      52,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,    -1,    10,    11,    12,    52,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,     8,    -1,    10,    11,    12,    51,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    51,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    59,   172,   173,     5,   109,     0,    65,   174,   175,
      73,    73,     5,    85,   126,   162,   176,   177,    93,   182,
     183,   109,   179,   180,   109,   178,   118,   180,    73,   177,
     132,   184,   185,   122,   186,   187,     4,    49,    60,    62,
      64,    79,    85,    94,    95,   107,   141,   142,   161,   181,
      97,   285,   181,    81,    73,   185,    45,   101,   123,   134,
     135,   148,   149,   188,   189,   133,   138,   190,   191,   192,
     245,   180,   117,   117,   117,   117,    52,   180,   105,   105,
     102,   147,   105,   105,    50,   286,    73,   189,   286,   246,
      82,   194,    73,   139,    73,   181,   285,   285,   285,   285,
     180,     8,   285,   285,   285,    80,   130,   286,   285,   285,
      66,   193,    35,    68,   152,   253,    33,    43,    75,    78,
     116,   123,   196,   197,   245,    51,     4,    51,     4,    51,
      51,   181,   286,   286,   286,   286,   119,   120,   200,   201,
       6,     7,    12,    22,    25,    29,    31,    33,    34,    37,
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
     263,   263,   109,    29,   287,   265,   285,    97,   109,   198,
     199,   199,   267,   267,   267,    60,    63,   108,   168,   270,
     287,   180,     5,     6,    28,    41,    42,    50,    57,    58,
      60,    61,    63,    86,    97,    98,    99,   108,   109,   114,
     117,   128,   160,   166,   167,   168,   198,   244,   290,   292,
     294,   299,   109,   285,   286,   276,   277,   294,   198,   286,
     147,   285,   294,   267,   268,   240,   287,   207,    29,   287,
     240,    97,   258,   258,   258,     4,    51,    51,    51,   258,
     258,    51,     4,    63,    83,    90,   106,   108,   137,   168,
     260,     4,    51,     4,    55,    56,   243,   287,    13,    76,
     111,   117,   222,   223,   224,   225,   226,   227,   231,   234,
     236,   252,   258,    87,   211,   220,   258,   118,    51,     4,
      52,   118,   267,   267,   117,    20,   294,   294,   294,   115,
     291,   291,   291,   117,   117,    41,    42,    57,    58,   128,
     166,   167,   117,   117,   294,   291,   291,   117,     9,   289,
       7,     8,    10,    11,    12,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,   146,   296,    20,   118,   104,   139,
     281,     4,   149,   104,    69,    73,   241,     4,    52,    51,
      51,    51,   258,    51,    51,   260,   147,   260,   121,   217,
     117,   215,   216,   216,   225,   117,   252,   252,   138,   222,
     258,    10,    11,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   235,    13,    92,   112,   233,   235,
     212,   256,   258,    88,   210,   221,   285,   285,   294,   294,
     297,   298,   294,    28,    60,    61,    63,    98,    99,   108,
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
     268,   294,    20,    97,    51,   214,   218,   287,     4,    51,
      51,    11,   206,   138,   248,   145,    52,    52,   144,   272,
      51,    51,    51,    51,    51,    52,   277,    51,   219,    51,
     266,   258,   253,   251,   287,   294,    69,    20,   220,   254,
     164,   250,   268,   277,   221,   218,   249
};

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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 250 "ace.yacc" /* yacc.c:1646  */
    {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
#line 2903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 253 "ace.yacc" /* yacc.c:1646  */
    {
		this_report.dbname=acl_strdup((yyvsp[-1].str));
		A4GL_init_connection ((yyvsp[-1].str));
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
#line 2915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 277 "ace.yacc" /* yacc.c:1646  */
    {
		printf("NIY\n");
		exit(0);
	}
#line 2924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 281 "ace.yacc" /* yacc.c:1646  */
    {
		ace_add_variable((yyvsp[-1].str),(yyvsp[0].str),CAT_VARIABLE,0,-1,0);
	}
#line 2932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 284 "ace.yacc" /* yacc.c:1646  */
    {
		ace_add_variable((yyvsp[-1].str),(yyvsp[0].str),CAT_PARAM,atoi((yyvsp[-3].str)),-1,0);
	}
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 287 "ace.yacc" /* yacc.c:1646  */
    {
		add_function((yyvsp[0].str));
	}
#line 2948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 298 "ace.yacc" /* yacc.c:1646  */
    {
	char buff[256];
	int a;
	strcpy(buff,(yyvsp[0].str));
	for (a=0;a<strlen(buff);a++) {
		buff[a]=toupper(buff[a]);
	}
	strcpy((yyval.str),buff);
	}
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 311 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"INTEGER");}
#line 2968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 312 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"CHAR");}
#line 2974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 313 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"CHAR (%s)",(yyvsp[-1].str));}
#line 2980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 314 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"VARCHAR");}
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 315 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"VARCHAR (%s)",(yyvsp[-1].str));}
#line 2992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 316 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"DATE");}
#line 2998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 317 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"FLOAT");}
#line 3004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 318 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"SMALLFLOAT");}
#line 3010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 319 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"SMALLINT");}
#line 3016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 320 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"DATETIME");}
#line 3022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 321 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"INTERVAL");}
#line 3028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 322 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"MONEY");}
#line 3034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 323 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"MONEY (%s,0)",(yyvsp[-1].str));}
#line 3040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 324 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"MONEY (%s,%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 325 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"DECIMAL");}
#line 3052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 326 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"DECIMAL (%s,0)",(yyvsp[-1].str));}
#line 3058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 327 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"DECIMAL (%s,%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 341 "ace.yacc" /* yacc.c:1646  */
    {
	add_inputs((char *)A4GL_strip_quotes((yyvsp[0].str)),(yyvsp[-2].str));
}
#line 3072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 356 "ace.yacc" /* yacc.c:1646  */
    { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup((yyvsp[0].str));}
#line 3078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 357 "ace.yacc" /* yacc.c:1646  */
    { this_report.output.report_to_where=1; }
#line 3084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 358 "ace.yacc" /* yacc.c:1646  */
    { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup((yyvsp[0].str)); }
#line 3090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 359 "ace.yacc" /* yacc.c:1646  */
    { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup((yyvsp[0].str)); }
#line 3096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 360 "ace.yacc" /* yacc.c:1646  */
    {
		this_report.output.left_margin=atoi((yyvsp[0].str));
	}
#line 3104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 363 "ace.yacc" /* yacc.c:1646  */
    {
		this_report.output.bottom_margin=atoi((yyvsp[0].str));
	}
#line 3112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 366 "ace.yacc" /* yacc.c:1646  */
    {
		this_report.output.top_margin=atoi((yyvsp[0].str));
	}
#line 3120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 369 "ace.yacc" /* yacc.c:1646  */
    {
		this_report.output.page_length=atoi((yyvsp[0].str));
	}
#line 3128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 372 "ace.yacc" /* yacc.c:1646  */
    {
		this_report.output.right_margin=atoi((yyvsp[0].str));
	}
#line 3136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 375 "ace.yacc" /* yacc.c:1646  */
    {
		this_report.output.top_of_page=acl_strdup((yyvsp[0].str));
	}
#line 3144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 382 "ace.yacc" /* yacc.c:1646  */
    { execute_selects(); }
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 398 "ace.yacc" /* yacc.c:1646  */
    {
		struct acerep_commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,NULL,cmd);
	  }
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 417 "ace.yacc" /* yacc.c:1646  */
    {
		add_fmt(FORMAT_FIRST_PAGE_HEADER,NULL,(yyvsp[0].commands));
	}
#line 3169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 421 "ace.yacc" /* yacc.c:1646  */
    {
		add_fmt(FORMAT_PAGE_TRAILER,NULL,(yyvsp[0].commands));
	}
#line 3177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 425 "ace.yacc" /* yacc.c:1646  */
    {
		add_fmt(FORMAT_PAGE_HEADER,NULL,(yyvsp[0].commands));
	}
#line 3185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 429 "ace.yacc" /* yacc.c:1646  */
    {
		add_fmt(FORMAT_ON_EVERY_ROW,NULL,(yyvsp[0].commands));
	}
#line 3193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 432 "ace.yacc" /* yacc.c:1646  */
    {
		add_fmt(FORMAT_ON_LAST_ROW,NULL,(yyvsp[0].commands));
	}
#line 3201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 435 "ace.yacc" /* yacc.c:1646  */
    {
		add_fmt(FORMAT_BEFORE_GROUP,DUP((yyvsp[-1].expr)),(yyvsp[0].commands));
	}
#line 3209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 438 "ace.yacc" /* yacc.c:1646  */
    {
		add_fmt(FORMAT_AFTER_GROUP,DUP((yyvsp[-1].expr)),(yyvsp[0].commands));
	}
#line 3217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 445 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.var_usage)=malloc(sizeof(struct acerep_var_usage));
		(yyval.var_usage)->subscript1=DUP((yyvsp[-3].expr));
		(yyval.var_usage)->subscript2=DUP((yyvsp[-1].expr));
		(yyval.var_usage)->varname=strdup((yyvsp[-5].str));
		(yyval.var_usage)->varid=find_variable((yyval.var_usage)->varname);
		if ( (yyval.var_usage)->varid==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[-5].str));
		}
	}
#line 3232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 455 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.var_usage)=malloc(sizeof(struct acerep_var_usage));
		(yyval.var_usage)->subscript1=DUP((yyvsp[-1].expr));
		(yyval.var_usage)->subscript2=NULL;
		(yyval.var_usage)->varname=strdup((yyvsp[-3].str));
		(yyval.var_usage)->varid=find_variable((yyval.var_usage)->varname);
		if ( (yyval.var_usage)->varid==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[-3].str));
		}
	}
#line 3247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 465 "ace.yacc" /* yacc.c:1646  */
    {
		
		(yyval.var_usage)=malloc(sizeof(struct acerep_var_usage));
		(yyval.var_usage)->subscript1=NULL;
		(yyval.var_usage)->subscript2=NULL;
		(yyval.var_usage)->varname=strdup((yyvsp[0].str));
		(yyval.var_usage)->varid=find_variable((yyval.var_usage)->varname);
		if ( (yyval.var_usage)->varid==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[0].str));
		}
	}
#line 3263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 480 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[0].var_usage);
	}
#line 3272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 484 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[0].str));
	}
#line 3281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 492 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 495 "ace.yacc" /* yacc.c:1646  */
    { ordbycnt=0; }
#line 3293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 495 "ace.yacc" /* yacc.c:1646  */
    {
	printf("speclist : %s ",(yyvsp[0].str));
	SPRINTF1((yyval.str),"ORDER BY %s",(yyvsp[0].str));}
#line 3301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 499 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 508 "ace.yacc" /* yacc.c:1646  */
    {
		SPRINTF1((yyval.str),"\"%s\"",(yyvsp[0].str));
	}
#line 3315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 518 "ace.yacc" /* yacc.c:1646  */
    { ordbycnt=0; }
#line 3321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 518 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF1((yyval.str),"ORDER BY %s",(yyvsp[0].str)); }
#line 3327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 523 "ace.yacc" /* yacc.c:1646  */
    {
SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
}
#line 3335 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 528 "ace.yacc" /* yacc.c:1646  */
    {
		if (strlen((yyvsp[0].str))) {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));
		}
	}
#line 3345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 534 "ace.yacc" /* yacc.c:1646  */
    {
		char buff[256];
		SPRINTF1(buff,"I%d",atoi((yyvsp[0].str)));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
#line 3355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 539 "ace.yacc" /* yacc.c:1646  */
    {
		char buff[256];
		SPRINTF1(buff,"C%s",(yyvsp[0].str));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
#line 3365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 548 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 556 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 562 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 568 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 573 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"WHERE \n0 (%s)\n0",(yyvsp[0].str));}
#line 3395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 578 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 582 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 3407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 583 "ace.yacc" /* yacc.c:1646  */
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str));
        }
#line 3415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 586 "ace.yacc" /* yacc.c:1646  */
    {
		SPRINTF2((yyval.str),"%s, OUTER %s",(yyvsp[-3].str),(yyvsp[0].str));
        }
#line 3423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 589 "ace.yacc" /* yacc.c:1646  */
    {
		SPRINTF2((yyval.str),"%s, OUTER (%s)",(yyvsp[-5].str),(yyvsp[-1].str));
        }
#line 3431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 592 "ace.yacc" /* yacc.c:1646  */
    {
		SPRINTF3((yyval.str),"%s LEFT OUTER JOIN %s ON %s",(yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str));
        }
#line 3439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 595 "ace.yacc" /* yacc.c:1646  */
    {
		SPRINTF3((yyval.str),"%s INNER JOIN %s ON %s",(yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str));
        }
#line 3447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 600 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"%s",(yyvsp[0].str)); }
#line 3453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 601 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"(%s)",(yyvsp[-1].str)); }
#line 3459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 606 "ace.yacc" /* yacc.c:1646  */
    {
		SPRINTF2((yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));
		ace_add_table((yyvsp[-1].str),(yyvsp[0].str));
		}
#line 3468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 616 "ace.yacc" /* yacc.c:1646  */
    { 
		SPRINTF4((yyval.str),"%s %s %s %s", (yyvsp[-3].str),(yyvsp[-2].str), (yyvsp[-1].str),(yyvsp[0].str));
	}
#line 3476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 621 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"\n0");}
#line 3482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 625 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 629 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 636 "ace.yacc" /* yacc.c:1646  */
    {
			SPRINTF3((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
		}
#line 3502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 644 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 650 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 656 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 661 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 662 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 668 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 670 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 695 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 697 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 699 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 701 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 708 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 711 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 718 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 720 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 722 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 724 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 726 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF6((yyval.str)," %s %s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 740 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"<=");}
#line 3616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 741 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),">=");}
#line 3622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 751 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 765 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF1((yyval.str)," %s",(char *)A4GL_strip_quotes((yyvsp[0].str))); }
#line 3634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 766 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),(yyvsp[0].str)); }
#line 3640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 767 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF3((yyval.str)," %s%s%s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));  }
#line 3646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 768 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF3((yyval.str),"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes((yyvsp[-2].str)),(yyvsp[-1].str),(yyvsp[0].str));  }
#line 3652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 778 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),(yyvsp[0].str));}
#line 3658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 782 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 783 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"[%s]",(yyvsp[-1].str));}
#line 3670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 784 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"[%s,%s]",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 787 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF2((yyval.str),"%s%s",(yyvsp[-1].str),(yyvsp[0].str)); }
#line 3682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 788 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF3((yyval.str),"%s.%s%s",(yyvsp[-3].str),(yyvsp[-1].str),(yyvsp[0].str)); }
#line 3688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 789 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF2((yyval.str),"%s.%s",(yyvsp[-2].str),(yyvsp[0].str)); }
#line 3694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 800 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"0.%s",(yyvsp[0].str));}
#line 3700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 806 "ace.yacc" /* yacc.c:1646  */
    {reset_sql_stuff();}
#line 3706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 807 "ace.yacc" /* yacc.c:1646  */
    {
		char buff[100000];
		SPRINTF4(buff,"%s %s %s %s",(yyvsp[-9].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str));
		SPRINTF9((yyval.str),"%s %s %s %s %s %s %s %s %s",(yyvsp[-9].str),(yyvsp[-7].str),(yyvsp[-6].str),(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));
 		add_select((yyval.str),buff, temp_tab_name,(yyvsp[0].str),(yyvsp[-3].str)); 
	}
#line 3717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 816 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 818 "ace.yacc" /* yacc.c:1646  */
    {
       		SPRINTF2((yyval.str),"INTO TEMP %s%s ",(yyvsp[-1].str),(yyvsp[0].str));
		strcpy(temp_tab_name,(yyvsp[-1].str));
	}
#line 3732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 828 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str),"%s %s %s %s %s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str) );}
#line 3738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 832 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 833 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF3((yyval.str),"%s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str)); }
#line 3750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 846 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 846 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str)," WITH NO LOG");}
#line 3762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 857 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF6((yyval.str)," %s %s %s %s %s %s",(yyvsp[-5].str),(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 860 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 861 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"ALL");}
#line 3780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 862 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"DISTINCT");}
#line 3786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 863 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"DISTINCT");}
#line 3792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 868 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF2((yyval.str)," %s,%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 3798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 872 "ace.yacc" /* yacc.c:1646  */
    {
			if (strcmp((yyvsp[0].str),"rowid")==0) {
				SPRINTF2((yyval.str)," %s %s",(yyvsp[0].str),(yyvsp[0].str));
				add_select_column((yyvsp[0].str),(yyvsp[0].str));
			} else {
				add_select_column((yyvsp[0].str),(yyvsp[0].str));
			}
		}
#line 3811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 880 "ace.yacc" /* yacc.c:1646  */
    {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[-1].str),(yyvsp[0].str));
			add_select_column((yyvsp[-1].str),(yyvsp[0].str));
		}
#line 3820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 884 "ace.yacc" /* yacc.c:1646  */
    {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[-2].str),(yyvsp[0].str));
			add_select_column((yyvsp[-2].str),(yyvsp[0].str));
		}
#line 3829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 895 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"UNITS YEAR");}
#line 3835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 896 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"UNITS MONTH"); }
#line 3841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 897 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"UNITS DAY);"); }
#line 3847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 898 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"UNITS HOUR);"); }
#line 3853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 899 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"UNITS MINUTE);"); }
#line 3859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 900 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF0((yyval.str),"UNITS SECOND);"); }
#line 3865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 904 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF2((yyval.str),"%s%s", (yyvsp[-1].str),(yyvsp[0].str)); }
#line 3871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 907 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s[%s]",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 908 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s[%s,%s]",(yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 909 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s.%s[%s]",(yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 910 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF4((yyval.str)," %s.%s[%s,%s]",(yyvsp[-7].str),(yyvsp[-5].str),(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 911 "ace.yacc" /* yacc.c:1646  */
    {
			if (find_variable((yyvsp[0].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
			SPRINTF1((yyval.str),"\n2(%d)",find_variable((yyvsp[0].str)));
			}
#line 3904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 916 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 918 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s%s%s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 922 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," %s ",(yyvsp[0].str));}
#line 3922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 923 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 924 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 925 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 926 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 927 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 928 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str)," %s(%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 929 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s(%s)",(yyvsp[-3].str),(yyvsp[-1].str));}
#line 3964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 931 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 933 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 935 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 937 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 939 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 943 "ace.yacc" /* yacc.c:1646  */
    {
			SPRINTF2((yyval.str),"CURRENT, %s TO %s",(yyvsp[-2].str),(yyvsp[0].str));
        }
#line 4002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 946 "ace.yacc" /* yacc.c:1646  */
    {
			SPRINTF3((yyval.str),"%s, %s TO %s",(yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str));
        }
#line 4010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 949 "ace.yacc" /* yacc.c:1646  */
    {
			SPRINTF3((yyval.str),"%s %s TO %s",(yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str));
        }
#line 4018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 955 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[-1].str));}
#line 4024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 961 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"/%s",(yyvsp[0].str));}
#line 4030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 962 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," MOD %s",(yyvsp[0].str));}
#line 4036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 963 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str)," POW %s",(yyvsp[0].str));}
#line 4042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 964 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"%s",(yyvsp[0].str));}
#line 4048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 965 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"*%s",(yyvsp[0].str));}
#line 4054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 966 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"+%s",(yyvsp[0].str));}
#line 4060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 967 "ace.yacc" /* yacc.c:1646  */
    {SPRINTF1((yyval.str),"-%s",(yyvsp[0].str));}
#line 4066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 970 "ace.yacc" /* yacc.c:1646  */
    { SPRINTF2((yyval.str),"%s%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 4072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 973 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 974 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"+");}
#line 4084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 975 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"-");}
#line 4090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 980 "ace.yacc" /* yacc.c:1646  */
    {
	SPRINTF2((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str));
}
#line 4098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 987 "ace.yacc" /* yacc.c:1646  */
    {
                        if (find_variable((yyvsp[0].str))==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
                        SPRINTF1((yyval.str),"\n2(%d)",find_variable((yyvsp[0].str)));
                        }
#line 4107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1003 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.commands).commands.commands_len=1;
		(yyval.commands).commands.commands_val=acl_malloc2(sizeof(struct acerep_command));
		COPY((yyval.commands).commands.commands_val[0],(yyvsp[0].cmd));
		}
#line 4117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1008 "ace.yacc" /* yacc.c:1646  */
    {
		COPY((yyval.commands),(yyvsp[-1].commands));
		(yyval.commands).commands.commands_len++;
		(yyval.commands).commands.commands_val=realloc(
		(yyval.commands).commands.commands_val,
		(yyval.commands).commands.commands_len*sizeof(struct acerep_command));
		COPY((yyval.commands).commands.commands_val[ (yyval.commands).commands.commands_len-1 ],(yyvsp[0].cmd));
	}
#line 4130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1030 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.cmd).cmd_type=CMD_BLOCK;
		(yyval.cmd).acerep_command_u.acerep_commands.commands.commands_val=(yyvsp[-1].commands).commands.commands_val;
		(yyval.cmd).acerep_command_u.acerep_commands.commands.commands_len=(yyvsp[-1].commands).commands.commands_len;
	}
#line 4140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1040 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.cmd).cmd_type=CMD_CALL;
		(yyval.cmd).acerep_command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->fname=acl_strdup((yyvsp[-3].str));
	
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
		print_lexpr( (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr);
}
#line 4153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1058 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.cmd).cmd_type=CMD_FOR;
		(yyval.cmd).acerep_command_u.cmd_for.varid=find_variable((yyvsp[-7].str));
		COPY((yyval.cmd).acerep_command_u.cmd_for.start,(yyvsp[-5].expr));
		COPY((yyval.cmd).acerep_command_u.cmd_for.finish,(yyvsp[-3].expr));
		COPY((yyval.cmd).acerep_command_u.cmd_for.step,(yyvsp[-2].expr));
		(yyval.cmd).acerep_command_u.cmd_for.command=(struct acerep_command *)DUP((yyvsp[0].cmd));
	}
#line 4166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1068 "ace.yacc" /* yacc.c:1646  */
    { (yyval.expr).type=EXPRTYPE_INT; (yyval.expr).expr_u.i=1; }
#line 4172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1069 "ace.yacc" /* yacc.c:1646  */
    { COPY((yyval.expr),(yyvsp[-1].expr));}
#line 4178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1073 "ace.yacc" /* yacc.c:1646  */
    {
	(yyval.cmd).cmd_type=CMD_IF;
	COPY((yyval.cmd).acerep_command_u.cmd_if.condition,(yyvsp[-3].expr));
	(yyval.cmd).acerep_command_u.cmd_if.command=(struct acerep_command *)DUP((yyvsp[-1].cmd));
	(yyval.cmd).acerep_command_u.cmd_if.elsecommand=(struct acerep_command *)DUP((yyvsp[0].cmd));
}
#line 4189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1081 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.cmd).cmd_type=CMD_NULL;
		(yyval.cmd).acerep_command_u.null=1;
	}
#line 4198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1084 "ace.yacc" /* yacc.c:1646  */
    { COPY((yyval.cmd),(yyvsp[0].cmd)); }
#line 4204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1089 "ace.yacc" /* yacc.c:1646  */
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[-2].str));
		(yyval.cmd).acerep_command_u.cmd_let.varid=v;
		(yyval.cmd).acerep_command_u.cmd_let.value=DUP((yyvsp[0].expr));
		(yyval.cmd).acerep_command_u.cmd_let.sub1=0;
		(yyval.cmd).acerep_command_u.cmd_let.sub2=0; 
	}
#line 4218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1100 "ace.yacc" /* yacc.c:1646  */
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[-5].str));
		(yyval.cmd).acerep_command_u.cmd_let.varid=v;
		(yyval.cmd).acerep_command_u.cmd_let.value=DUP((yyvsp[0].expr));
		(yyval.cmd).acerep_command_u.cmd_let.sub1=DUP((yyvsp[-3].expr)); 
		(yyval.cmd).acerep_command_u.cmd_let.sub2=0;
	}
#line 4232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1111 "ace.yacc" /* yacc.c:1646  */
    {
		int v;
		(yyval.cmd).cmd_type=CMD_LET;
		v=find_variable((yyvsp[-7].str));
		(yyval.cmd).acerep_command_u.cmd_let.varid=v;
		(yyval.cmd).acerep_command_u.cmd_let.value=DUP((yyvsp[0].expr));
		(yyval.cmd).acerep_command_u.cmd_let.sub1=DUP((yyvsp[-5].expr)); 
		(yyval.cmd).acerep_command_u.cmd_let.sub2=DUP((yyvsp[-3].expr)); 
	}
#line 4246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1124 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup("");
		}
#line 4255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1131 "ace.yacc" /* yacc.c:1646  */
    {

	(yyval.expr).type=EXPRTYPE_COMPLEX;
	(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[-2].expr));
	COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr));
	(yyval.expr).expr_u.expr->operand=EXPR_CONCAT;

	}
#line 4269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1143 "ace.yacc" /* yacc.c:1646  */
    {
	(yyval.cmd).cmd_type=CMD_NEED;
	(yyval.cmd).acerep_command_u.cmd_need.nlines=atoi((yyvsp[-1].str));
}
#line 4278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1149 "ace.yacc" /* yacc.c:1646  */
    {
	(yyval.cmd).cmd_type=CMD_PAUSE;
	(yyval.cmd).acerep_command_u.cmd_pause.message=acl_strdup((yyvsp[0].str));
}
#line 4287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1156 "ace.yacc" /* yacc.c:1646  */
    {
	(yyval.cmd).cmd_type=CMD_PRINT;
	(yyval.cmd).acerep_command_u.cmd_print.printnl=atoi((yyvsp[0].str));
	(yyval.cmd).acerep_command_u.cmd_print.print=(yyvsp[-1].expr);
}
#line 4297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1164 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"1");}
#line 4303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1164 "ace.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"0");}
#line 4309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1167 "ace.yacc" /* yacc.c:1646  */
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename_expr.type=EXPRTYPE_STRING;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename_expr.expr_u.s=acl_strdup((yyvsp[0].str));
	}
#line 4319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1172 "ace.yacc" /* yacc.c:1646  */
    {
	(yyval.cmd).cmd_type=CMD_PRINTFILE;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename_expr.type=EXPRTYPE_VARIABLE_SUB;
	(yyval.cmd).acerep_command_u.cmd_printfile.filename_expr.expr_u.var_usage=(yyvsp[0].var_usage);
	}
#line 4329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1180 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).acerep_command_u.cmd_skip.nlines=atoi((yyvsp[-1].str));

	}
#line 4339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1185 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.cmd).cmd_type=CMD_SKIP;
		(yyval.cmd).acerep_command_u.cmd_skip.nlines=-1;
	}
#line 4348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1192 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.cmd).cmd_type=CMD_WHILE;
		COPY((yyval.cmd).acerep_command_u.cmd_while.condition,(yyvsp[-2].expr));
		(yyval.cmd).acerep_command_u.cmd_while.command=(struct acerep_command *)DUP((yyvsp[0].cmd));
}
#line 4358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1300 "ace.yacc" /* yacc.c:1646  */
    {
			(yyval.exprptr)=0;
		}
#line 4366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1304 "ace.yacc" /* yacc.c:1646  */
    { 
			(yyval.exprptr)=DUP((yyvsp[0].expr)); 
		}
#line 4374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1311 "ace.yacc" /* yacc.c:1646  */
    {
		COPY((yyval.agg_val),(yyvsp[-1].agg_val));
		(yyval.agg_val).wexpr=(yyvsp[0].exprptr); 
		}
#line 4383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1319 "ace.yacc" /* yacc.c:1646  */
    { (yyval.exprptr)=DUP((yyvsp[0].expr)); }
#line 4389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1323 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
#line 4400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1329 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
		(yyval.agg_val).isgroup=0;
	}
#line 4411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1335 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
		(yyval.agg_val).isgroup=0;
	}
#line 4422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1341 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
		(yyval.agg_val).isgroup=0;
	}
#line 4433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1347 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
		(yyval.agg_val).isgroup=0;
	}
#line 4444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1353 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
		(yyval.agg_val).isgroup=0;
	}
#line 4455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 1359 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
		(yyval.agg_val).isgroup=0;
	}
#line 4466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 1366 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_COUNT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
#line 4477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1372 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_PERCENT;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=0;
	}
#line 4488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1378 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
	}
#line 4499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 1384 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_TOTAL;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
	}
#line 4510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 1390 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_AVG;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
	}
#line 4521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1396 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_MIN;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
	}
#line 4532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1402 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.agg_val).type=AGG_MAX;
		(yyval.agg_val).wexpr=0;
		(yyval.agg_val).isgroup=1;
		(yyval.agg_val).expr=(yyvsp[0].exprptr);
	}
#line 4543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1412 "ace.yacc" /* yacc.c:1646  */
    {
		switch ( (yyvsp[0].expr).type) {
			case EXPRTYPE_DOUBLE:
					COPY((yyval.expr),(yyvsp[0].expr)); 
					(yyval.expr).expr_u.d=0.0-(yyval.expr).expr_u.d;
					break;
			case EXPRTYPE_INT:
					COPY((yyval.expr),(yyvsp[0].expr)); 
					(yyval.expr).expr_u.i=0-(yyval.expr).expr_u.i;
					break;
			default : 
					(yyval.expr).type=EXPRTYPE_COMPLEX;
					(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
					set_expr_int(&(yyval.expr).expr_u.expr->expr1, 0);
					COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
					(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
		}
	}
#line 4566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 1430 "ace.yacc" /* yacc.c:1646  */
    { COPY((yyval.expr),(yyvsp[0].expr)); }
#line 4572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 1432 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
#line 4581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 1436 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
#line 4590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 1440 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[0].str));
	}
#line 4599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 1444 "ace.yacc" /* yacc.c:1646  */
    {
		int v;
		v=find_variable("date");
		(yyval.expr).type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[0].str));
		} 
		(yyval.expr).expr_u.varid=v;
	}
#line 4613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 1453 "ace.yacc" /* yacc.c:1646  */
    {
		int v;
		v=find_variable("time");
		(yyval.expr).type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[0].str));
		} 
		(yyval.expr).expr_u.varid=v;
	}
#line 4627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1463 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1470 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 1476 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 1482 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1489 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[-3].str));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 1495 "ace.yacc" /* yacc.c:1646  */
    { COPY((yyval.expr),(yyvsp[-1].expr)); }
#line 4688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 1496 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[0].var_usage);
	}
#line 4697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 1501 "ace.yacc" /* yacc.c:1646  */
    {
		struct expr *e1;
		COPY((yyval.expr),(yyvsp[0].expr));
		if ( (yyval.expr).type==EXPRTYPE_SIMPLE)  {
		  	COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[-1].expr)); 
		} else {
			if ( (yyval.expr).type==EXPRTYPE_COMPLEX ) {
				COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[-1].expr)); 
			} else {
				if ((yyval.expr).type==EXPRTYPE_COMPARE)  {
				COPY((yyval.expr).expr_u.cexpr->expr1,(yyvsp[-1].expr)); 

				} else {
					printf("BAD -> %d\n", (yyval.expr).type);
				}
			}
		}
		e1=&(yyval.expr);
	}
#line 4721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 1523 "ace.yacc" /* yacc.c:1646  */
    {
		switch ( (yyvsp[0].expr).type) {
			case EXPRTYPE_DOUBLE:
					COPY((yyval.expr),(yyvsp[0].expr)); 
					(yyval.expr).expr_u.d=0.0-(yyval.expr).expr_u.d;
					break;
			case EXPRTYPE_INT:
					COPY((yyval.expr),(yyvsp[0].expr)); 
					(yyval.expr).expr_u.i=0-(yyval.expr).expr_u.i;
					break;
			default : 
					(yyval.expr).type=EXPRTYPE_COMPLEX;
					(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
					set_expr_int(&(yyval.expr).expr_u.expr->expr1, 0);
					COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
					(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
		}
	}
#line 4744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 1541 "ace.yacc" /* yacc.c:1646  */
    { COPY((yyval.expr),(yyvsp[0].expr)); }
#line 4750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 1543 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=1;
		}
#line 4759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 1547 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=0;
		}
#line 4768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 1551 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_BUILTIN;
		(yyval.expr).expr_u.name=acl_strdup((yyvsp[0].str));
	}
#line 4777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 1555 "ace.yacc" /* yacc.c:1646  */
    {
		int v;
		v=find_variable("date");
		(yyval.expr).type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[0].str));
		} 
		(yyval.expr).expr_u.varid=v;
	}
#line 4791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 1564 "ace.yacc" /* yacc.c:1646  */
    {
		int v;
		v=find_variable("time");
		(yyval.expr).type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",(yyvsp[0].str));
		} 
		(yyval.expr).expr_u.varid=v;
	}
#line 4805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 1574 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DATE");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 1581 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("MONTH");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 1587 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("YEAR");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 1593 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup("DAY");
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 1600 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_FCALL; 
		(yyval.expr).expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		(yyval.expr).expr_u.fcall->fname=acl_strdup((yyvsp[-3].str));
                (yyval.cmd).acerep_command_u.cmd_call.fcall->lexpr=(yyvsp[-1].expr).expr_u.lexpr;
	}
#line 4860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 1606 "ace.yacc" /* yacc.c:1646  */
    { COPY((yyval.expr),(yyvsp[-1].expr)); }
#line 4866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 1607 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_COLUMN; 
	}
#line 4877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 1613 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.sexpr->operand=EXPR_ASCII; 
	}
#line 4888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 1619 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_VARIABLE_SUB;
		(yyval.expr).expr_u.var_usage=(yyvsp[0].var_usage);
	}
#line 4897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 1624 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_AGG; 
		(yyval.expr).expr_u.aggid=add_agg((yyvsp[0].agg_val));
	}
#line 4906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 1629 "ace.yacc" /* yacc.c:1646  */
    {
		struct expr *e1;
		COPY((yyval.expr),(yyvsp[0].expr));
		if ( (yyval.expr).type==EXPRTYPE_SIMPLE)  {
		  	COPY((yyval.expr).expr_u.sexpr->expr,(yyvsp[-1].expr)); 
		} else {
			if ( (yyval.expr).type==EXPRTYPE_COMPLEX ) {
				COPY((yyval.expr).expr_u.expr->expr1,(yyvsp[-1].expr)); 
			} else {
				if ((yyval.expr).type==EXPRTYPE_COMPARE)  {
				COPY((yyval.expr).expr_u.cexpr->expr1,(yyvsp[-1].expr)); 

				} else {
					printf("BAD -> %d\n", (yyval.expr).type);
				}
			}
		}
		e1=&(yyval.expr);
	}
#line 4930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1651 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
#line 4942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1659 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
#line 4954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 1667 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
#line 4965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 1675 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
#line 4976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 1682 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
#line 4987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 1691 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
#line 4998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 1697 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
#line 5010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 1706 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
#line 5022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 1713 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
#line 5033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 1722 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_AND; 
	}
#line 5045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1730 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_OR; 
	}
#line 5057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 1738 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_DIV; 
		}
#line 5068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 1746 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_POW; 
		}
#line 5079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1753 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MOD; 
		}
#line 5090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1762 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; (yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_MUL; 
		}
#line 5101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 1768 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX; 
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_ADD; 
	}
#line 5113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 1777 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_SUB; 
	}
#line 5125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 1784 "ace.yacc" /* yacc.c:1646  */
    { 
		(yyval.expr).type=EXPRTYPE_COMPLEX;
		(yyval.expr).expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY((yyval.expr).expr_u.expr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.expr->operand=EXPR_USING; 
	}
#line 5137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 1792 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 1798 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 1804 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 1810 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 1816 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 1822 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 1828 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 1834 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 1840 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 1846 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 1852 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_COMPARE;
		(yyval.expr).expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY((yyval.expr).expr_u.cexpr->expr2,(yyvsp[0].expr)); 
		(yyval.expr).expr_u.cexpr->method=acl_strdup((yyvsp[-1].str)); 
		}
#line 5258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 1860 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_SPACES; 
	}
#line 5269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 1867 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNULL; 
	}
#line 5280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 1873 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); */
		(yyval.expr).expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}
#line 5291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 1881 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_SIMPLE; 
		(yyval.expr).expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		(yyval.expr).expr_u.sexpr->operand=EXPR_CLIP; 
	}
#line 5302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 1891 "ace.yacc" /* yacc.c:1646  */
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
#line 5323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 1907 "ace.yacc" /* yacc.c:1646  */
    {
		COPY((yyval.expr),(yyvsp[0].expr));
	}
#line 5331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 1914 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_LIST;
		(yyval.expr).expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		(yyval.expr).expr_u.lexpr->elem.elem_len=1;
		(yyval.expr).expr_u.lexpr->elem.elem_val=0;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[0],(yyvsp[0].expr));
	}
#line 5344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 1921 "ace.yacc" /* yacc.c:1646  */
    {
		COPY((yyval.expr),(yyvsp[-2].expr));
		(yyval.expr).expr_u.lexpr->elem.elem_len++;
		(yyval.expr).expr_u.lexpr->elem.elem_val=realloc( (yyval.expr).expr_u.lexpr->elem.elem_val,sizeof(struct expr)* (yyval.expr).expr_u.lexpr->elem.elem_len);
		COPY((yyval.expr).expr_u.lexpr->elem.elem_val[ (yyval.expr).expr_u.lexpr->elem.elem_len-1 ],(yyvsp[0].expr));

	}
#line 5356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 1932 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_STRING;
		(yyval.expr).expr_u.s=acl_strdup((yyvsp[0].str));
	}
#line 5365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 1936 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[0].str));
	}
#line 5374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 1940 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_DOUBLE;
		(yyval.expr).expr_u.d=atof((yyvsp[0].str));
	}
#line 5383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 1944 "ace.yacc" /* yacc.c:1646  */
    {
		(yyval.expr).type=EXPRTYPE_INT;
		(yyval.expr).expr_u.i=atoi((yyvsp[0].str));
	}
#line 5392 "y.tab.c" /* yacc.c:1646  */
    break;


#line 5396 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
#line 1952 "ace.yacc" /* yacc.c:1906  */


#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif
