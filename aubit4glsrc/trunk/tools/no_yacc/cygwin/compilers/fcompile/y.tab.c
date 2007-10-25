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
#define yyparse a4gl_form_yyparse
#define yylex   a4gl_form_yylex
#define yyerror a4gl_form_yyerror
#define yylval  a4gl_form_yylval
#define yychar  a4gl_form_yychar
#define yydebug a4gl_form_yydebug
#define yynerrs a4gl_form_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CH = 258,
     GRAPH_CH = 259,
     KW_COMPOSITES = 260,
     INSTRUCTIONS = 261,
     ATTRIBUTES = 262,
     DATABASE = 263,
     BY = 264,
     KW_SCREEN_TITLE = 265,
     KW_SCREEN = 266,
     KW_SIZE = 267,
     OPEN_SQUARE = 268,
     KW_END = 269,
     CLOSE_SQUARE = 270,
     NUMBER_VALUE = 271,
     NAMED = 272,
     OPEN_BRACE = 273,
     CLOSE_BRACE = 274,
     TITLE = 275,
     FORMONLY = 276,
     COMMENT = 277,
     DYNAMIC = 278,
     COLON = 279,
     ATSIGN = 280,
     DOT = 281,
     WITHOUT = 282,
     KW_NULL = 283,
     INPUT = 284,
     TABLES = 285,
     PIPE = 286,
     EQUAL = 287,
     CHAR_VALUE = 288,
     SEMICOLON = 289,
     LOOKUP = 290,
     JOINING = 291,
     OPEN_BRACKET = 292,
     CLOSE_BRACKET = 293,
     STAR = 294,
     DIVIDE = 295,
     PLUS = 296,
     MINUS = 297,
     RECORD = 298,
     COMMA = 299,
     THROUGH = 300,
     TYPE = 301,
     DELIMITERS = 302,
     KW_CHAR = 303,
     KW_INT = 304,
     KW_DATE = 305,
     KW_FLOAT = 306,
     SMALLFLOAT = 307,
     SMALLINT = 308,
     KW_DECIMAL = 309,
     MONEY = 310,
     DATETIME = 311,
     INTERVAL = 312,
     LIKE = 313,
     BLACK = 314,
     BLUE = 315,
     GREEN = 316,
     CYAN = 317,
     RED = 318,
     MAGENTA = 319,
     WHITE = 320,
     YELLOW = 321,
     NORMAL = 322,
     REVERSE = 323,
     LEFT = 324,
     BOLD = 325,
     BLINK = 326,
     UNDERLINE = 327,
     DIM = 328,
     AUTONEXT = 329,
     COLOR = 330,
     COMMENTS = 331,
     DEFAULT = 332,
     VALIDATE = 333,
     DISPLAY = 334,
     DOWNSHIFT = 335,
     UPSHIFT = 336,
     FORMAT = 337,
     INCLUDE = 338,
     INVISIBLE = 339,
     NOUPDATE = 340,
     NOENTRY = 341,
     PICTURE = 342,
     PROGRAM = 343,
     REQUIRED = 344,
     QUERYCLEAR = 345,
     VERIFY = 346,
     WORDWRAP = 347,
     COMPRESS = 348,
     NONCOMPRESS = 349,
     TO = 350,
     AS = 351,
     SERIAL = 352,
     KW_BYTE = 353,
     KW_TEXT = 354,
     VARCHAR = 355,
     SQL_VAR = 356,
     KW_NONSPACE = 357,
     SQLONLY = 358,
     WIDGET = 359,
     CONFIG = 360,
     KW_NL = 361,
     COMPARISON = 362,
     LESSTHAN = 363,
     GREATERTHAN = 364,
     KWOR = 365,
     KWAND = 366,
     KWAND1 = 367,
     KWWHERE = 368,
     KWNOT = 369,
     KWBETWEEN = 370,
     KWIN = 371,
     XVAL = 372,
     KWNULLCHK = 373,
     KWNOTNULLCHK = 374,
     YEAR = 375,
     MONTH = 376,
     DAY = 377,
     HOUR = 378,
     MINUTE = 379,
     SECOND = 380,
     FRACTION = 381,
     LISTBOX = 382,
     BUTTON = 383,
     KW_PANEL = 384,
     DISPLAYONLY = 385,
     ALLOWING = 386,
     KW_WS = 387,
     KW_TAB = 388,
     KW_MASTER_OF = 389,
     KW_BEFORE = 390,
     KW_AFTER = 391,
     KW_EDITADD = 392,
     KW_EDITUPDATE = 393,
     KW_REMOVE = 394,
     KW_OF = 395,
     KW_ADD = 396,
     KW_UPDATE = 397,
     KW_QUERY = 398,
     KW_ON_ENDING = 399,
     KW_ON_BEGINNING = 400,
     KW_CALL = 401,
     KW_BELL = 402,
     KW_ABORT = 403,
     KW_LET = 404,
     KW_EXITNOW = 405,
     KW_NEXTFIELD = 406,
     KW_IF = 407,
     KW_THEN = 408,
     KW_ELSE = 409,
     KW_BEGIN = 410,
     KW_TOTAL = 411,
     KW_RIGHT = 412,
     KW_ZEROFILL = 413,
     KW_USES_EXTENDED = 414,
     SPECIAL_DBNAME = 415,
     KW_ACTION = 416
   };
#endif
/* Tokens.  */
#define CH 258
#define GRAPH_CH 259
#define KW_COMPOSITES 260
#define INSTRUCTIONS 261
#define ATTRIBUTES 262
#define DATABASE 263
#define BY 264
#define KW_SCREEN_TITLE 265
#define KW_SCREEN 266
#define KW_SIZE 267
#define OPEN_SQUARE 268
#define KW_END 269
#define CLOSE_SQUARE 270
#define NUMBER_VALUE 271
#define NAMED 272
#define OPEN_BRACE 273
#define CLOSE_BRACE 274
#define TITLE 275
#define FORMONLY 276
#define COMMENT 277
#define DYNAMIC 278
#define COLON 279
#define ATSIGN 280
#define DOT 281
#define WITHOUT 282
#define KW_NULL 283
#define INPUT 284
#define TABLES 285
#define PIPE 286
#define EQUAL 287
#define CHAR_VALUE 288
#define SEMICOLON 289
#define LOOKUP 290
#define JOINING 291
#define OPEN_BRACKET 292
#define CLOSE_BRACKET 293
#define STAR 294
#define DIVIDE 295
#define PLUS 296
#define MINUS 297
#define RECORD 298
#define COMMA 299
#define THROUGH 300
#define TYPE 301
#define DELIMITERS 302
#define KW_CHAR 303
#define KW_INT 304
#define KW_DATE 305
#define KW_FLOAT 306
#define SMALLFLOAT 307
#define SMALLINT 308
#define KW_DECIMAL 309
#define MONEY 310
#define DATETIME 311
#define INTERVAL 312
#define LIKE 313
#define BLACK 314
#define BLUE 315
#define GREEN 316
#define CYAN 317
#define RED 318
#define MAGENTA 319
#define WHITE 320
#define YELLOW 321
#define NORMAL 322
#define REVERSE 323
#define LEFT 324
#define BOLD 325
#define BLINK 326
#define UNDERLINE 327
#define DIM 328
#define AUTONEXT 329
#define COLOR 330
#define COMMENTS 331
#define DEFAULT 332
#define VALIDATE 333
#define DISPLAY 334
#define DOWNSHIFT 335
#define UPSHIFT 336
#define FORMAT 337
#define INCLUDE 338
#define INVISIBLE 339
#define NOUPDATE 340
#define NOENTRY 341
#define PICTURE 342
#define PROGRAM 343
#define REQUIRED 344
#define QUERYCLEAR 345
#define VERIFY 346
#define WORDWRAP 347
#define COMPRESS 348
#define NONCOMPRESS 349
#define TO 350
#define AS 351
#define SERIAL 352
#define KW_BYTE 353
#define KW_TEXT 354
#define VARCHAR 355
#define SQL_VAR 356
#define KW_NONSPACE 357
#define SQLONLY 358
#define WIDGET 359
#define CONFIG 360
#define KW_NL 361
#define COMPARISON 362
#define LESSTHAN 363
#define GREATERTHAN 364
#define KWOR 365
#define KWAND 366
#define KWAND1 367
#define KWWHERE 368
#define KWNOT 369
#define KWBETWEEN 370
#define KWIN 371
#define XVAL 372
#define KWNULLCHK 373
#define KWNOTNULLCHK 374
#define YEAR 375
#define MONTH 376
#define DAY 377
#define HOUR 378
#define MINUTE 379
#define SECOND 380
#define FRACTION 381
#define LISTBOX 382
#define BUTTON 383
#define KW_PANEL 384
#define DISPLAYONLY 385
#define ALLOWING 386
#define KW_WS 387
#define KW_TAB 388
#define KW_MASTER_OF 389
#define KW_BEFORE 390
#define KW_AFTER 391
#define KW_EDITADD 392
#define KW_EDITUPDATE 393
#define KW_REMOVE 394
#define KW_OF 395
#define KW_ADD 396
#define KW_UPDATE 397
#define KW_QUERY 398
#define KW_ON_ENDING 399
#define KW_ON_BEGINNING 400
#define KW_CALL 401
#define KW_BELL 402
#define KW_ABORT 403
#define KW_LET 404
#define KW_EXITNOW 405
#define KW_NEXTFIELD 406
#define KW_IF 407
#define KW_THEN 408
#define KW_ELSE 409
#define KW_BEGIN 410
#define KW_TOTAL 411
#define KW_RIGHT 412
#define KW_ZEROFILL 413
#define KW_USES_EXTENDED 414
#define SPECIAL_DBNAME 415
#define KW_ACTION 416




/* Copy the first part of user declarations.  */
#line 1 "screen.yacc"

#define YYDEBUG 1
/*
	y.tab.c was generated from screen.yacc using yacc
*/


/*
=====================================================================
		                    Includes
=====================================================================
*/

/* prevent warning for redundant declaration of yyparse / fgl_comp_parse: */
#define _BISON_SIMPLE_INCL_
#define _NO_WINDOWS_H_
#include "a4gl_fcompile_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern struct struct_scr_field *fld;
int graphics_mode=0;
extern int ignorekw;
extern int lineno;
extern int colno;
extern int scr;
int in_comment;
long fileseek=0;
int ltab=0;
int replicate_bug=0;
int extended_graphics=0;

dll_import struct_form the_form;

extern int newscreen;
extern int fldno;
extern int fstart;
extern int openwith;
extern char currftag[256];
extern char *outputfilename;
extern char *tablist[];
int A4GL_get_dtype_size(void) ;
int A4GL_get_attr_from_string (char *s);

struct local_expr_list {
	listitem *expr_list;
	int nlist;
};


int in_screen_section=0;
int dtype_size=0;
char *rm_dup_quotes(char *s) ;
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *chk_alias(char *s);
int A4GL_wcswidth(char *mbs);	/* utf8 */

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



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
#line 78 "screen.yacc"
{
	char	str[1024];
	u_expression *expr;
	int intval;
	struct s_column_list *col_list;
	struct s_column column;
	struct local_expr_list *el;
	struct s_at_comments *at_comments;
	struct s_at_if *at_if;
	struct s_at_let *at_let;
	struct s_at_nextfield *at_nextfield;
	struct s_at_call *fcall;
	struct s_at_block *at_block;
	struct u_action *at_action;
	struct s_bef_aft *befact;
	struct s_control_block *control_block;
	struct s_lookups *lookups;
	struct s_lookup *lookup;
}
/* Line 187 of yacc.c.  */
#line 520 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 533 "y.tab.c"

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
#define YYFINAL  138
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3768

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  135
/* YYNRULES -- Number of rules.  */
#define YYNRULES  643
/* YYNRULES -- Number of states.  */
#define YYNSTATES  882

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   416

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
     155,   156,   157,   158,   159,   160,   161
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    35,    37,    41,    43,    47,    49,    52,    53,    57,
      58,    63,    64,    65,    66,    76,    77,    79,    80,    83,
      88,    89,    91,    93,    96,    98,   100,   102,   104,   106,
     108,   110,   112,   114,   116,   118,   120,   123,   124,   129,
     131,   132,   137,   138,   142,   144,   147,   151,   154,   155,
     158,   160,   164,   168,   174,   178,   182,   186,   188,   191,
     192,   197,   199,   202,   206,   207,   208,   215,   216,   220,
     226,   230,   232,   233,   239,   243,   246,   251,   254,   259,
     263,   265,   270,   273,   275,   279,   283,   285,   289,   291,
     295,   297,   302,   305,   307,   310,   311,   314,   316,   320,
     322,   327,   332,   336,   340,   344,   350,   354,   360,   362,
     364,   368,   374,   378,   382,   386,   388,   393,   395,   397,
     399,   401,   405,   409,   411,   413,   415,   417,   419,   421,
     423,   426,   429,   431,   433,   435,   437,   440,   442,   444,
     446,   448,   450,   452,   454,   456,   458,   460,   462,   464,
     466,   468,   470,   472,   473,   477,   479,   482,   484,   487,
     490,   492,   493,   503,   516,   518,   520,   521,   524,   525,
     527,   528,   530,   532,   537,   539,   543,   544,   546,   548,
     552,   556,   560,   564,   566,   570,   572,   574,   575,   577,
     579,   582,   584,   586,   588,   589,   594,   596,   598,   600,
     602,   604,   606,   609,   612,   615,   618,   620,   622,   624,
     626,   628,   630,   634,   636,   639,   642,   644,   646,   650,
     654,   656,   658,   662,   666,   670,   674,   676,   677,   681,
     687,   688,   692,   693,   697,   699,   702,   704,   706,   708,
     710,   712,   714,   717,   719,   720,   724,   726,   728,   730,
     732,   734,   736,   738,   740,   743,   744,   748,   749,   751,
     754,   756,   760,   764,   768,   772,   776,   780,   785,   789,
     792,   795,   797,   803,   809,   812,   816,   818,   820,   822,
     824,   826,   828,   832,   835,   837,   840,   848,   850,   854,
     858,   860,   862,   864,   870,   876,   879,   882,   884,   886,
     888,   890,   892,   894,   896,   902,   903,   906,   908,   913,
     916,   920,   923,   927,   931,   933,   936,   939,   943,   947,
     952,   954,   957,   959,   962,   964,   966,   968,   970,   972,
     974,   976,   978,   980,   982,   984,   988,   992,   994,   999,
    1000,  1007,  1008,  1010,  1012,  1016,  1018,  1020,  1024,  1028,
    1029,  1031,  1033,  1037,  1040,  1043,  1045,  1048,  1052,  1057,
    1061,  1065,  1069,  1073,  1077,  1081,  1085,  1089,  1093,  1098,
    1102,  1105,  1108,  1114,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1134,  1138,  1140,  1142,  1144,  1146,  1148,  1150,  1152,
    1154,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,  1172,
    1174,  1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,
    1194,  1196,  1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,
    1214,  1216,  1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,
    1234,  1236,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1252,
    1254,  1256,  1258,  1260,  1262,  1264,  1266,  1268,  1270,  1272,
    1274,  1276,  1278,  1280,  1282,  1284,  1286,  1288,  1290,  1292,
    1294,  1296,  1298,  1300,  1302,  1304,  1306,  1308,  1310,  1312,
    1314,  1316,  1318,  1320,  1322,  1324,  1326,  1328,  1330,  1332,
    1334,  1336,  1338,  1340,  1342,  1344,  1346,  1348,  1350,  1352,
    1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,  1372,
    1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,  1392,
    1394,  1396,  1398,  1400,  1402,  1404,  1406,  1408,  1410,  1412,
    1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,  1430,  1432,
    1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,  1452,
    1454,  1456,  1458,  1460,  1462,  1464,  1466,  1468,  1470,  1472,
    1474,  1476,  1478,  1480,  1482,  1484,  1486,  1488,  1490,  1492,
    1494,  1496,  1498,  1500,  1502,  1504,  1506,  1508,  1510,  1512,
    1514,  1516,  1518,  1520,  1522,  1524,  1526,  1528,  1530,  1532,
    1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,  1572,
    1574,  1576,  1578,  1580,  1582,  1584,  1586,  1588,  1590,  1592,
    1594,  1596,  1598,  1600,  1602,  1604,  1606,  1608,  1610,  1612,
    1614,  1616,  1618,  1620,  1622,  1624,  1626,  1628,  1630,  1632,
    1634,  1636,  1638,  1640
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     163,     0,    -1,   164,   168,   187,   192,   216,    -1,     8,
      21,    -1,     8,   167,    27,    28,    29,    -1,     8,    21,
      27,    28,    29,    -1,     8,   167,    -1,    17,    -1,   295,
      -1,    17,    -1,   296,    -1,   160,    -1,   160,    25,   166,
      -1,   165,    -1,   165,    25,   166,    -1,   169,    -1,   168,
     169,    -1,    -1,    11,   170,   172,    -1,    -1,    10,    33,
     171,   172,    -1,    -1,    -1,    -1,   177,   173,   176,    18,
     174,   179,    19,   175,   178,    -1,    -1,   159,    -1,    -1,
      12,    16,    -1,    12,    16,     9,    16,    -1,    -1,    14,
      -1,   181,    -1,   179,   181,    -1,   166,    -1,   180,    -1,
     183,    -1,   133,    -1,     4,    -1,    31,    -1,    33,    -1,
     182,    -1,   132,    -1,   106,    -1,   102,    -1,     3,    -1,
     182,     3,    -1,    -1,    13,   184,   185,    15,    -1,   234,
      -1,    -1,   185,    31,   186,   234,    -1,    -1,    30,   188,
     178,    -1,   189,    -1,   188,   189,    -1,   188,    44,   189,
      -1,   166,   190,    -1,    -1,    32,   191,    -1,   166,    -1,
     166,    24,   166,    -1,   166,    25,   166,    -1,   166,    25,
     166,    24,   166,    -1,   166,    26,   166,    -1,    33,    26,
     166,    -1,     7,   193,   178,    -1,   194,    -1,   193,   194,
      -1,    -1,   233,   195,   196,    34,    -1,   197,    -1,   196,
     197,    -1,   196,    34,   197,    -1,    -1,    -1,    32,   198,
     203,   200,   199,   210,    -1,    -1,    13,    16,    15,    -1,
      13,    16,    44,    16,    15,    -1,   202,   114,    28,    -1,
     202,    -1,    -1,    46,    58,   166,    26,   166,    -1,    46,
      58,   166,    -1,    46,   236,    -1,    21,    26,   229,   201,
      -1,   130,   201,    -1,   130,   131,    29,   201,    -1,   166,
      26,   166,    -1,   166,    -1,    39,   166,    26,   166,    -1,
      39,   166,    -1,   205,    -1,   204,    44,   205,    -1,   206,
      32,   207,    -1,   233,    -1,   166,    26,   166,    -1,   166,
      -1,   166,    26,   166,    -1,   166,    -1,    39,   166,    26,
     166,    -1,    39,   166,    -1,    36,    -1,    44,    36,    -1,
      -1,    44,   211,    -1,   212,    -1,   211,    44,   212,    -1,
      74,    -1,    75,    32,   214,   252,    -1,    35,   204,   209,
     208,    -1,    76,    32,    33,    -1,    77,    32,   213,    -1,
      79,    58,   166,    -1,    79,    58,   166,    26,   166,    -1,
      78,    58,   166,    -1,    78,    58,   166,    26,   166,    -1,
      80,    -1,    81,    -1,    82,    32,    33,    -1,    83,    32,
      37,   237,    38,    -1,   104,    32,    33,    -1,   105,    32,
      33,    -1,   161,    32,   166,    -1,    84,    -1,    23,    12,
      32,    16,    -1,    23,    -1,   103,    -1,    86,    -1,    85,
      -1,    87,    32,    33,    -1,    88,    32,    33,    -1,    89,
      -1,    68,    -1,    91,    -1,    90,    -1,   158,    -1,   157,
      -1,    92,    -1,    92,    93,    -1,    92,    94,    -1,    33,
      -1,    16,    -1,   101,    -1,   215,    -1,   214,   215,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    16,    -1,    68,    -1,
      73,    -1,    67,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    -1,     6,   217,   178,    -1,   218,    -1,   217,
     218,    -1,   219,    -1,   219,    34,    -1,    47,    33,    -1,
     266,    -1,    -1,    11,    43,   220,   224,    37,   225,    38,
     221,   223,    -1,   129,    37,    16,    44,    16,    38,    95,
      37,    16,    44,    16,    38,    -1,   259,    -1,   282,    -1,
      -1,    96,   127,    -1,    -1,    39,    -1,    -1,    34,    -1,
     166,    -1,   166,    13,    16,    15,    -1,   228,    -1,   225,
     226,   228,    -1,    -1,    44,    -1,   166,    -1,   166,    26,
     166,    -1,    21,    26,   166,    -1,   166,    26,    39,    -1,
      21,    26,    39,    -1,   227,    -1,   227,    45,   227,    -1,
     166,    -1,    14,    -1,    -1,   231,    -1,   232,    -1,   231,
     232,    -1,   132,    -1,   133,    -1,   166,    -1,    -1,   230,
     166,   235,   230,    -1,    48,    -1,    49,    -1,    50,    -1,
      51,    -1,    52,    -1,    53,    -1,    54,   240,    -1,    55,
     240,    -1,    56,   247,    -1,    57,   241,    -1,    97,    -1,
      98,    -1,    99,    -1,   100,    -1,   128,    -1,   239,    -1,
     237,    44,   239,    -1,    16,    -1,    41,    16,    -1,    42,
      16,    -1,    33,    -1,    17,    -1,    17,    95,    17,    -1,
      17,    24,    17,    -1,     3,    -1,   238,    -1,   238,    95,
     238,    -1,   238,    24,   238,    -1,    33,    95,    33,    -1,
      33,    24,    33,    -1,    28,    -1,    -1,    37,    16,    38,
      -1,    37,    16,    44,    16,    38,    -1,    -1,   244,    95,
     246,    -1,    -1,    37,    16,    38,    -1,    16,    -1,   245,
     242,    -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,
     124,    -1,   125,    -1,   126,   251,    -1,   245,    -1,    -1,
     248,    95,   249,    -1,   250,    -1,   250,    -1,   120,    -1,
     121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,    -1,
     126,   251,    -1,    -1,    37,   243,    38,    -1,    -1,   253,
      -1,   113,   254,    -1,   255,    -1,   255,   111,   255,    -1,
     255,   110,   255,    -1,   256,   107,   256,    -1,   256,   108,
     256,    -1,   256,   109,   256,    -1,   256,    58,   256,    -1,
     256,   114,    58,   256,    -1,   256,    32,   256,    -1,   256,
     118,    -1,   256,   119,    -1,   256,    -1,   256,   115,   256,
     111,   256,    -1,   256,   116,    37,   258,    38,    -1,   114,
     255,    -1,    37,   255,    38,    -1,   257,    -1,    16,    -1,
      33,    -1,   117,    -1,    17,    -1,   256,    -1,   258,    44,
     256,    -1,     5,   260,    -1,   261,    -1,   260,   261,    -1,
     108,   262,   109,   222,   108,   262,   109,    -1,   263,    -1,
     262,    44,   263,    -1,   264,    26,   265,    -1,   265,    -1,
     166,    -1,   166,    -1,   135,   276,   140,   280,   274,    -1,
     136,   277,   140,   280,   274,    -1,   145,   283,    -1,   144,
     283,    -1,   270,    -1,   275,    -1,   268,    -1,   271,    -1,
     272,    -1,   283,    -1,   273,    -1,   152,   288,   153,   267,
     269,    -1,    -1,   154,   267,    -1,   148,    -1,   149,   233,
      32,   288,    -1,   151,   233,    -1,   151,    32,   233,    -1,
     151,   150,    -1,   151,    32,   150,    -1,   155,   274,    14,
      -1,   267,    -1,   274,   267,    -1,    76,    33,    -1,    76,
     147,    33,    -1,    76,    68,    33,    -1,    76,   147,    68,
      33,    -1,   278,    -1,   276,   278,    -1,   279,    -1,   277,
     279,    -1,   137,    -1,   138,    -1,   139,    -1,   137,    -1,
     141,    -1,   142,    -1,   143,    -1,   139,    -1,    79,    -1,
     138,    -1,   281,    -1,   280,   226,   281,    -1,   264,    26,
     265,    -1,   265,    -1,   264,   134,   264,   223,    -1,    -1,
     146,   166,    37,   284,   285,    38,    -1,    -1,   286,    -1,
     287,    -1,   286,    44,   287,    -1,   288,    -1,   291,    -1,
     288,   111,   288,    -1,   288,   110,   288,    -1,    -1,   290,
      -1,   288,    -1,   290,    44,   288,    -1,    42,   288,    -1,
      41,   288,    -1,   293,    -1,   114,   288,    -1,    37,   288,
      38,    -1,   292,    37,   289,    38,    -1,   156,   140,   233,
      -1,   288,   107,   288,    -1,   288,   108,   288,    -1,   288,
     109,   288,    -1,   288,    39,   288,    -1,   288,    41,   288,
      -1,   288,    42,   288,    -1,   288,    40,   288,    -1,   288,
      58,   288,    -1,   288,   114,    58,   288,    -1,   288,    32,
     288,    -1,   288,   118,    -1,   288,   119,    -1,   288,   115,
     288,   111,   288,    -1,   288,   116,    37,   294,    38,    -1,
     166,    -1,   233,    -1,    16,    -1,    33,    -1,   117,    -1,
      28,    -1,   293,    -1,   294,    44,   293,    -1,     5,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    12,    -1,
      14,    -1,    20,    -1,    22,    -1,    23,    -1,    28,    -1,
      29,    -1,    30,    -1,    35,    -1,    36,    -1,    43,    -1,
      45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,    98,    -1,    99,    -1,
     100,    -1,   101,    -1,   102,    -1,   103,    -1,   104,    -1,
     105,    -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,
     111,    -1,   113,    -1,   114,    -1,   115,    -1,   116,    -1,
     117,    -1,   118,    -1,   119,    -1,   120,    -1,   121,    -1,
     122,    -1,   123,    -1,   124,    -1,   125,    -1,   126,    -1,
     127,    -1,   128,    -1,   129,    -1,   130,    -1,   131,    -1,
     134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,
     139,    -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,
     144,    -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,
     159,    -1,   161,    -1,     5,    -1,     8,    -1,     9,    -1,
      10,    -1,    11,    -1,    12,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    27,    -1,    29,    -1,    30,    -1,
      35,    -1,    36,    -1,    43,    -1,    45,    -1,    46,    -1,
      47,    -1,    48,    -1,    49,    -1,    50,    -1,    51,    -1,
      52,    -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,
      62,    -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,
      67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,
      92,    -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,
      97,    -1,    98,    -1,    99,    -1,   100,    -1,   101,    -1,
     103,    -1,   104,    -1,   105,    -1,   107,    -1,   108,    -1,
     109,    -1,   110,    -1,   111,    -1,   113,    -1,   114,    -1,
     115,    -1,   116,    -1,   118,    -1,   119,    -1,   120,    -1,
     121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,    -1,
     126,    -1,   127,    -1,   128,    -1,   129,    -1,   131,    -1,
     134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,
     139,    -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,
     144,    -1,   145,    -1,   146,    -1,   147,    -1,   148,    -1,
     149,    -1,   151,    -1,   152,    -1,   153,    -1,   154,    -1,
     155,    -1,   156,    -1,   157,    -1,   158,    -1,   159,    -1,
     161,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   137,   138,   143,   144,   153,   154,   158,
     159,   163,   164,   165,   166,   169,   169,   172,   172,   185,
     185,   204,   206,   209,   204,   214,   214,   219,   220,   221,
     233,   234,   239,   240,   243,   258,   270,   271,   282,   293,
     306,   318,   329,   334,   337,   345,   346,   352,   351,   373,
     376,   376,   394,   395,   398,   399,   400,   403,   412,   413,
     416,   417,   418,   420,   421,   422,   428,   432,   432,   436,
     436,   446,   447,   448,   452,   456,   452,   511,   512,   516,
     524,   525,   528,   529,   532,   535,   540,   549,   561,   573,
     580,   587,   594,   606,   615,   624,   631,   633,   636,   642,
     643,   644,   645,   648,   649,   653,   654,   658,   658,   661,
     662,   682,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   720,   726,   727,   728,   732,   733,   737,   738,   739,
     740,   741,   742,   743,   744,   746,   760,   761,   762,   763,
     764,   765,   766,   770,   771,   774,   774,   776,   776,   779,
     789,   795,   795,   798,   799,   800,   804,   804,   806,   806,
     809,   809,   811,   814,   820,   823,   827,   828,   832,   834,
     836,   838,   840,   845,   845,   849,   852,   856,   856,   859,
     859,   863,   864,   877,   885,   885,   894,   898,   902,   906,
     910,   914,   918,   924,   928,   932,   936,   940,   944,   948,
     951,   958,   958,   963,   963,   963,   968,   975,   976,   977,
     978,   979,   980,   981,   982,   986,   990,   996,   999,  1000,
    1003,  1004,  1011,  1013,  1018,  1026,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1041,  1043,  1044,  1047,  1050,  1054,  1055,
    1056,  1057,  1058,  1059,  1060,  1066,  1068,  1075,  1075,  1081,
    1087,  1088,  1091,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1112,  1119,  1120,  1121,
    1126,  1129,  1133,  1145,  1148,  1149,  1153,  1163,  1170,  1179,
    1182,  1190,  1193,  1197,  1204,  1212,  1217,  1225,  1229,  1234,
    1239,  1244,  1249,  1254,  1263,  1272,  1273,  1278,  1281,  1289,
    1295,  1301,  1307,  1316,  1321,  1331,  1341,  1347,  1353,  1359,
    1369,  1381,  1389,  1401,  1409,  1410,  1411,  1415,  1416,  1417,
    1418,  1419,  1420,  1421,  1424,  1431,  1442,  1446,  1453,  1461,
    1461,  1477,  1478,  1484,  1490,  1498,  1505,  1506,  1507,  1512,
    1513,  1516,  1517,  1521,  1523,  1524,  1525,  1526,  1527,  1528,
    1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,
    1539,  1540,  1541,  1542,  1545,  1548,  1549,  1550,  1551,  1552,
    1555,  1559,  1570,  1572,  1573,  1574,  1575,  1576,  1578,  1579,
    1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,  1589,
    1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,  1599,
    1600,  1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,
    1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,  1619,
    1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,
    1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,  1639,
    1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,  1649,
    1650,  1651,  1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,
    1660,  1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,
    1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,  1679,
    1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,
    1690,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,
    1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,  1715,
    1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,
    1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,
    1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,  1775,
    1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,
    1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795,
    1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,
    1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,
    1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,
    1826,  1827,  1828,  1829
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "GRAPH_CH", "KW_COMPOSITES",
  "INSTRUCTIONS", "ATTRIBUTES", "DATABASE", "BY", "KW_SCREEN_TITLE",
  "KW_SCREEN", "KW_SIZE", "OPEN_SQUARE", "KW_END", "CLOSE_SQUARE",
  "NUMBER_VALUE", "NAMED", "OPEN_BRACE", "CLOSE_BRACE", "TITLE",
  "FORMONLY", "COMMENT", "DYNAMIC", "COLON", "ATSIGN", "DOT", "WITHOUT",
  "KW_NULL", "INPUT", "TABLES", "PIPE", "EQUAL", "CHAR_VALUE", "SEMICOLON",
  "LOOKUP", "JOINING", "OPEN_BRACKET", "CLOSE_BRACKET", "STAR", "DIVIDE",
  "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", "TYPE", "DELIMITERS",
  "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", "SMALLFLOAT", "SMALLINT",
  "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", "LIKE", "BLACK", "BLUE",
  "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", "YELLOW", "NORMAL",
  "REVERSE", "LEFT", "BOLD", "BLINK", "UNDERLINE", "DIM", "AUTONEXT",
  "COLOR", "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY", "DOWNSHIFT",
  "UPSHIFT", "FORMAT", "INCLUDE", "INVISIBLE", "NOUPDATE", "NOENTRY",
  "PICTURE", "PROGRAM", "REQUIRED", "QUERYCLEAR", "VERIFY", "WORDWRAP",
  "COMPRESS", "NONCOMPRESS", "TO", "AS", "SERIAL", "KW_BYTE", "KW_TEXT",
  "VARCHAR", "SQL_VAR", "KW_NONSPACE", "SQLONLY", "WIDGET", "CONFIG",
  "KW_NL", "COMPARISON", "LESSTHAN", "GREATERTHAN", "KWOR", "KWAND",
  "KWAND1", "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK",
  "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND",
  "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY", "ALLOWING",
  "KW_WS", "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", "KW_EDITADD",
  "KW_EDITUPDATE", "KW_REMOVE", "KW_OF", "KW_ADD", "KW_UPDATE", "KW_QUERY",
  "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL", "KW_BELL", "KW_ABORT",
  "KW_LET", "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF", "KW_THEN", "KW_ELSE",
  "KW_BEGIN", "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL", "KW_USES_EXTENDED",
  "SPECIAL_DBNAME", "KW_ACTION", "$accept", "form_def", "database_section",
  "named_or_kw_st", "named_or_kw_any", "dbname", "screen_section",
  "screens_section", "@1", "@2", "screens_rest", "@3", "@4", "@5",
  "op_extended", "op_size", "op_end", "screen_layout", "some_text",
  "screen_element", "ch_list", "field", "@6", "field_element", "@7",
  "op_table_section", "table_def_list", "table_def", "opequal",
  "table_qualifier", "attribute_section", "field_tag_list", "field_tag",
  "@8", "fpart_list", "fpart", "@9", "@10", "op_att",
  "field_datatype_null", "field_datatype", "field_type", "lu_ft_eq_c",
  "lu_ft_eq_c_i", "lu_ft", "lu_fc", "lu_joincol", "lu_join",
  "op_field_desc", "op_desc_list", "desc", "def_val", "colors", "color",
  "op_instruction_section", "instruct_opts", "instruct_op_1",
  "instruct_op", "@11", "op_ltype", "op_star", "op_semi", "srec_dim",
  "srec_field_list", "op_comma", "field_list_item", "field_list_element",
  "field_name", "op_ws", "ws", "ws_elem", "field_tag_name",
  "field_tag_name_scr", "@12", "datatype", "incl_list", "number_value",
  "incl_entry", "opt_dec_ext", "opt_int_ext", "opt_unit_size", "dtfrac",
  "int_start", "int_start_unit", "int_end", "opt_dt_ext", "dt_start",
  "dt_end", "dtime_val", "opt_frac", "op_where", "where_clause", "clauses",
  "clause", "value", "fieldidentifier", "value_list", "composites",
  "composites_list", "composite_entry", "comp_list", "comp_item",
  "table_name", "column_name", "control_block", "action", "if", "op_else",
  "abort", "let", "nextfield", "block", "actions", "comments",
  "bef_act_list", "aft_act_list", "bef_act", "aft_act", "column_list",
  "column_entry", "master_of", "func_call", "@13", "op_func_call_args",
  "func_call_args", "func_call_arg", "expression", "op_expression_list",
  "expression_list", "single_expression", "fcall_name", "evalue",
  "evalue_list", "st_kword", "any_kword", 0
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
     415,   416
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   162,   163,   164,   164,   164,   164,   165,   165,   166,
     166,   167,   167,   167,   167,   168,   168,   170,   169,   171,
     169,   173,   174,   175,   172,   176,   176,   177,   177,   177,
     178,   178,   179,   179,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   182,   182,   184,   183,   185,
     186,   185,   187,   187,   188,   188,   188,   189,   190,   190,
     191,   191,   191,   191,   191,   191,   192,   193,   193,   195,
     194,   196,   196,   196,   198,   199,   197,   200,   200,   200,
     201,   201,   202,   202,   202,   202,   203,   203,   203,   203,
     203,   203,   203,   204,   204,   205,   206,   207,   207,   208,
     208,   208,   208,   209,   209,   210,   210,   211,   211,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   213,   213,   213,   214,   214,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   216,   216,   217,   217,   218,   218,   219,
     219,   220,   219,   219,   219,   219,   221,   221,   222,   222,
     223,   223,   224,   224,   225,   225,   226,   226,   227,   227,
     227,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   235,   234,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   237,   237,   238,   238,   238,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   240,   240,   240,
     241,   241,   242,   242,   243,   244,   245,   245,   245,   245,
     245,   245,   245,   246,   247,   247,   248,   249,   250,   250,
     250,   250,   250,   250,   250,   251,   251,   252,   252,   253,
     254,   254,   254,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   256,   256,   256,   256,
     257,   258,   258,   259,   260,   260,   261,   262,   262,   263,
     263,   264,   265,   266,   266,   266,   266,   267,   267,   267,
     267,   267,   267,   267,   268,   269,   269,   270,   271,   272,
     272,   272,   272,   273,   274,   274,   275,   275,   275,   275,
     276,   276,   277,   277,   278,   278,   278,   279,   279,   279,
     279,   279,   279,   279,   280,   280,   281,   281,   282,   284,
     283,   285,   285,   286,   286,   287,   288,   288,   288,   289,
     289,   290,   290,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   292,   293,   293,   293,   293,   293,
     294,   294,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     2,     0,     3,     0,
       4,     0,     0,     0,     9,     0,     1,     0,     2,     4,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     4,     1,
       0,     4,     0,     3,     1,     2,     3,     2,     0,     2,
       1,     3,     3,     5,     3,     3,     3,     1,     2,     0,
       4,     1,     2,     3,     0,     0,     6,     0,     3,     5,
       3,     1,     0,     5,     3,     2,     4,     2,     4,     3,
       1,     4,     2,     1,     3,     3,     1,     3,     1,     3,
       1,     4,     2,     1,     2,     0,     2,     1,     3,     1,
       4,     4,     3,     3,     3,     5,     3,     5,     1,     1,
       3,     5,     3,     3,     3,     1,     4,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     1,     2,     1,     2,     2,
       1,     0,     9,    12,     1,     1,     0,     2,     0,     1,
       0,     1,     1,     4,     1,     3,     0,     1,     1,     3,
       3,     3,     3,     1,     3,     1,     1,     0,     1,     1,
       2,     1,     1,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     2,     1,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     1,     0,     3,     5,
       0,     3,     0,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     3,     0,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     4,     3,     2,
       2,     1,     5,     5,     2,     3,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     2,     7,     1,     3,     3,
       1,     1,     1,     5,     5,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     5,     0,     2,     1,     4,     2,
       3,     2,     3,     3,     1,     2,     2,     3,     3,     4,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     4,     0,
       6,     0,     1,     1,     3,     1,     1,     3,     3,     0,
       1,     1,     3,     2,     2,     1,     2,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       2,     2,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,   392,   393,   394,   395,   396,   397,
     398,     7,   399,     3,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,    11,   519,    13,     6,     8,     1,     0,
      17,    52,    15,     0,     0,     0,     0,    19,    27,     0,
      16,     0,     0,   520,   521,   522,   523,   524,   525,     9,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,    12,    10,
      14,     0,    27,     0,    18,    21,    58,    30,    54,     0,
     163,     5,     4,    20,    28,    25,     0,    57,    31,     0,
      53,    55,   203,    30,    67,    69,     0,     2,     0,    26,
       0,     0,    60,    59,    56,    66,    68,     0,   520,   524,
     538,   616,   619,   620,   628,   629,   301,    30,   165,   167,
     174,     0,   170,   175,    29,    22,     0,     0,     0,     0,
      74,     0,    71,     0,   293,   294,   171,   169,     0,   334,
     335,   336,     0,   330,   342,   337,   343,   341,   338,   339,
     340,     0,   332,     0,   306,   305,   164,   166,   168,     0,
       0,    65,    61,    62,    64,     0,    70,    72,   302,     0,
     297,     0,   300,   295,     0,     0,     0,   331,     0,   333,
       0,   180,    45,    38,    47,    39,    40,    44,    43,    42,
      37,    34,     0,    35,    32,    41,    36,     0,   527,     0,
      82,    90,    77,    73,     0,   178,     0,   182,     0,     0,
       0,   347,   186,   344,   186,   349,   181,   348,   197,    23,
      33,    46,    63,     0,    92,     0,     0,    87,    81,     0,
       0,    75,   298,   179,     0,   302,   299,     0,     0,     0,
       0,   187,     0,   317,     0,     0,     0,     0,     0,   324,
     309,   307,   310,   311,   313,   303,   308,   312,   304,   351,
     201,   202,     0,     0,   198,   199,    49,    30,   196,   195,
      82,     0,   206,   207,   208,   209,   210,   211,   237,   237,
     254,   240,     0,   216,   217,   218,   219,   220,    85,    82,
       0,    89,     0,   105,     0,     0,   527,   188,   186,   193,
     184,     0,   346,   326,     0,     0,     0,     0,   321,   319,
     386,   389,   387,     0,     0,     0,   602,   388,   639,   203,
     385,     0,   356,     0,   365,     0,   345,   325,     0,   352,
     353,   355,    48,    50,   204,   200,    24,    86,    91,     0,
     212,   213,   258,   259,   260,   261,   262,   263,   265,   214,
       0,   256,   246,   247,   248,   249,   250,   251,   265,   215,
       0,   242,    84,    88,    80,    78,     0,     0,    76,     0,
     183,     0,     0,   176,     0,     0,     0,   328,   327,     0,
       0,   322,   320,     0,   364,   363,   366,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   380,   381,     0,   359,   323,   350,     0,   197,
     197,     0,     0,   264,     0,   252,     0,     0,   245,     0,
       0,   127,     0,   134,   109,     0,     0,     0,     0,     0,
     118,   119,     0,     0,   125,   130,   129,     0,     0,   133,
     136,   135,   139,   128,     0,     0,   138,   137,     0,   106,
     107,   296,   192,   190,   191,   189,     0,   180,   185,   194,
       0,   329,   318,   367,   369,   379,   373,   376,   374,   375,
     377,   370,   371,   372,   358,   357,     0,     0,     0,   315,
     361,     0,   360,   354,    51,   205,   238,     0,   244,     0,
     255,   257,   253,   241,     0,    83,    79,     0,     0,    93,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,     0,     0,     0,     0,   177,   172,     0,
     378,     0,   390,     0,     0,   314,   368,     0,     0,   266,
     243,     0,   103,     0,     0,     0,   155,   147,   148,   149,
     150,   151,   152,   153,   154,   158,   156,   159,   160,   161,
     162,   157,   267,   145,   112,   143,   142,   144,   113,   116,
     114,   120,     0,   131,   132,   122,   123,   124,   108,     0,
     382,   383,     0,   316,   362,   239,   126,   104,    94,     0,
     100,   111,    98,    95,     0,   146,   110,   268,     0,     0,
     230,   223,   227,   236,   226,     0,     0,     0,   231,   221,
       0,   391,   102,     0,     0,   287,   290,   288,     0,     0,
     289,   269,   270,   281,   286,   117,   115,     0,     0,     0,
       0,   224,   225,   121,     0,     0,     0,   173,     0,    99,
      97,     0,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,   280,   229,   228,   235,   234,   222,
     233,   232,   101,   285,   272,   271,   278,   276,   273,   274,
     275,     0,     0,     0,   277,     0,   291,     0,   282,   283,
       0,   292
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   135,   529,   136,   141,   142,   148,   282,
     284,   295,   370,   477,   310,   285,   300,   402,   403,   404,
     405,   406,   428,   472,   619,   151,   287,   288,   297,   313,
     290,   303,   304,   317,   341,   342,   375,   503,   441,   437,
     438,   412,   708,   709,   710,   793,   791,   744,   578,   659,
     660,   768,   762,   763,   307,   327,   328,   329,   384,   667,
     444,   427,   418,   508,   458,   509,   510,   480,   473,   474,
     475,   530,   476,   620,   498,   807,   808,   809,   550,   569,
     628,   699,   570,   571,   703,   559,   560,   700,   561,   623,
     796,   797,   821,   822,   823,   824,   877,   330,   344,   345,
     379,   380,   381,   382,   332,   459,   460,   735,   461,   462,
     463,   464,   465,   466,   352,   361,   353,   362,   422,   423,
     333,   467,   469,   538,   539,   540,   541,   691,   692,   532,
     533,   534,   733,   137,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -785
static const yytype_int16 yypact[] =
{
      21,  1125,    33,   153,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,    13,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,    11,  -785,    58,    84,  -785,  -785,    20,
    -785,    27,  -785,    87,  3142,  3142,   111,  -785,   134,  3142,
    -785,   158,   139,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,   162,   134,   166,  -785,  -785,   164,  1437,  -785,  3142,
     192,  -785,  -785,  -785,   207,    59,  1902,  -785,  -785,  3142,
    -785,  -785,  -785,  2057,  -785,  -785,  3297,  -785,   205,  -785,
     225,   197,    47,  -785,  -785,  -785,  -785,   215,   144,   210,
     221,   218,    63,   141,   113,   113,  -785,  2212,  -785,   222,
    -785,   126,  -785,  -785,  -785,  -785,  3142,  3142,  3142,  3142,
    -785,   115,  -785,  3142,   144,  -785,  -785,  -785,   241,  -785,
    -785,  -785,    41,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,    96,  -785,  3142,  -785,  -785,  -785,  -785,  -785,  3142,
     813,  -785,  -785,   237,  -785,  1592,   215,  -785,   236,   -24,
    -785,   238,  -785,  -785,  3142,   224,  3142,  -785,  3142,  -785,
     229,   235,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,   654,  -785,  -785,   268,  -785,  3142,   247,  3142,
       3,   248,   262,  -785,  3142,   242,  3142,   264,   249,   269,
     261,  -785,     2,  -785,     2,  -785,  -785,  -785,    39,  -785,
    -785,  -785,  -785,  2367,   265,   456,   259,  -785,   176,  3142,
     276,  -785,  -785,  -785,   190,  -785,  -785,   285,  3452,   267,
    3142,  -785,   -25,  -785,  3142,  1747,   968,   148,  3142,  -785,
    -785,  -785,  -785,  -785,  -785,   148,  -785,  -785,   148,   968,
    -785,  -785,    51,  3142,    39,  -785,  -785,   288,  -785,  -785,
     263,  3142,  -785,  -785,  -785,  -785,  -785,  -785,   270,   270,
      64,   233,  3142,  -785,  -785,  -785,  -785,  -785,  -785,   263,
     280,  -785,     8,   271,  3142,   298,   295,   296,    26,   297,
    -785,   244,  -785,  -785,   307,   -14,   309,  2522,  -785,  -785,
    -785,  -785,  -785,   968,   968,   968,   968,  -785,   203,   293,
    -785,   209,  -785,   308,  -785,   -11,  -785,  -785,   311,   302,
    -785,   357,  -785,  -785,  -785,  -785,  -785,  -785,  -785,   334,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,   314,  -785,
     266,  -785,  -785,  -785,  -785,  -785,  -785,  -785,   314,  -785,
     275,   326,   338,  -785,  -785,  -785,   356,    16,  -785,   -20,
    -785,  2677,  2832,   318,  3452,  3452,   353,  -785,  -785,   359,
     968,  -785,  -785,   294,   357,   357,   357,  3142,   968,   968,
     968,   968,   968,   968,   968,   968,   968,   968,   968,   336,
     968,   370,  -785,  -785,   148,   968,  -785,  -785,   968,    39,
      39,    37,   395,  -785,    64,  -785,   233,   401,  -785,  3142,
     406,   410,  3142,  -785,  -785,   386,   397,   398,   369,   374,
    -785,  -785,   402,   407,  -785,  -785,  -785,   411,   414,  -785,
    -785,  -785,   110,  -785,   415,   416,  -785,  -785,   417,   389,
    -785,  -785,  -785,  -785,  -785,  -785,   323,   235,  -785,  -785,
     419,  -785,   357,  -785,  -785,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   968,   384,  1282,   300,
     357,   413,   408,  -785,  -785,  -785,  -785,   439,  -785,   418,
    -785,  -785,  -785,  -785,   421,  -785,  -785,   425,    32,  -785,
     428,  -785,   458,   429,    28,  3142,  3142,   430,   424,   436,
     437,  -785,  -785,   444,   445,  3142,    16,  -785,  -785,   435,
     357,   968,  -785,    98,   148,  -785,  -785,   968,   442,  -785,
    -785,   465,  -785,  3607,  2987,  3142,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,   315,  -785,  -785,  -785,  -785,  -785,  -785,   457,
     460,  -785,   403,  -785,  -785,  -785,  -785,  -785,  -785,   466,
     357,  -785,  1282,  -785,   357,  -785,  -785,   452,  -785,  3142,
     461,  -785,   463,  -785,    -5,  -785,  -785,  -785,  3142,  3142,
    -785,  -785,   -15,  -785,    18,   474,   480,   122,    31,  -785,
     459,  -785,   475,  3142,  3142,  -785,  -785,  -785,    -5,    -5,
    -785,  -785,   117,     9,  -785,  -785,  -785,   498,   499,   500,
     501,  -785,  -785,  -785,   403,     6,     6,  -785,  3142,  -785,
    -785,   494,  -785,    -5,    -5,    -3,    -3,    -3,    -3,    -3,
     477,    -3,   502,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,  -785,
    -785,    -3,   426,    -3,  -785,    -3,  -785,   123,  -785,  -785,
      -3,  -785
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -785,  -785,  -785,  -785,  -144,  -785,  -785,   399,  -785,  -785,
     254,  -785,  -785,  -785,  -785,  -785,  -301,  -785,  -785,   136,
    -785,  -785,  -785,  -785,  -785,  -785,  -785,  -225,  -785,  -785,
    -785,  -785,   239,  -785,  -785,  -320,  -785,  -785,  -785,  -449,
    -785,  -785,  -785,  -202,  -785,  -785,  -785,  -785,  -785,  -785,
    -183,  -785,  -785,  -217,  -785,  -785,   219,  -785,  -785,  -785,
    -785,  -120,  -785,  -785,    40,   -36,   -34,  -785,   -69,  -785,
      78,  -285,   -62,  -785,  -785,  -785,  -606,  -276,    70,  -785,
    -785,  -785,  -785,   -66,  -785,  -785,  -785,  -785,   -63,    -6,
    -785,  -785,  -785,  -784,  -480,  -785,  -785,  -785,  -785,   220,
      61,   149,  -300,  -371,  -785,  -458,  -785,  -785,  -785,  -785,
    -785,  -785,  -399,  -785,  -785,  -785,   214,   206,   180,   112,
    -785,   -79,  -785,  -785,  -785,   -49,  -393,  -785,  -785,  -785,
    -785,  -672,  -785,  -785,  -785
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -535
static const yytype_int16 yytable[] =
{
     278,   280,   315,   616,   305,   286,   331,   537,   513,   827,
     537,   815,   816,   815,   816,   421,   732,   421,   305,   588,
     414,   377,   801,   575,   414,   468,   366,   331,   817,     1,
     817,   547,   818,   138,   841,   842,   144,   139,   140,   631,
     143,   845,   829,   514,   765,   446,   451,   805,   806,   435,
     573,   632,   576,   147,   589,   835,   413,   149,   535,   864,
     865,   766,   301,   531,   583,   452,   542,   846,   742,   391,
     451,   337,   338,   339,   314,   696,   743,   537,   452,   512,
     828,   697,   543,   145,   633,   415,   420,   421,   420,   661,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   819,
     811,   146,   820,   830,   820,   152,   847,   848,   849,   653,
     654,   655,   515,   850,   851,   852,   836,   853,   854,   767,
     593,   594,   595,   596,   436,   363,   781,   453,   454,   281,
     455,   456,   782,   286,   457,   302,   283,   340,   363,   376,
     453,   454,   312,   455,   456,   286,   689,   457,   420,   302,
     833,   879,   326,   139,   140,   289,   834,   880,   291,   516,
     519,   470,   471,   656,   657,   354,   546,   658,   349,   350,
     351,   386,   294,   326,   552,   553,   554,   555,   556,   557,
     558,   292,   371,   372,   373,   374,   296,   672,   306,   378,
     349,   350,   351,   721,   722,   675,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   685,   308,   687,   309,   390,
     354,   334,   690,   336,   452,   326,   401,   843,   844,   860,
     861,   411,   592,   355,   356,   357,   388,   358,   359,   360,
     417,   598,   378,   335,   378,   364,   365,   340,   599,   600,
     601,   602,   343,   346,   347,   348,   368,   385,   401,   363,
     369,   407,  -301,   432,   416,   434,   425,   603,   419,   426,
     378,   431,   445,   433,   439,   440,   783,   447,   355,   356,
     357,   443,   358,   359,   360,   449,   448,   450,   499,   479,
     500,   481,   502,   730,   363,   501,   453,   454,   504,   455,
     456,   505,   298,   457,   507,   511,   445,   549,   574,   435,
     302,   302,   674,   580,   378,   577,   604,   605,   606,   607,
     608,   581,   582,   609,   610,   611,   598,   612,   613,   544,
    -384,   746,   673,   599,   600,   601,   602,   548,   780,   586,
     587,   590,   585,   597,   784,   615,   618,   711,   572,   617,
     621,   622,   603,   562,   563,   564,   565,   566,   567,   568,
     378,   624,   614,   627,   629,   866,   867,   868,   869,   870,
     626,   872,   630,   302,   747,   748,   749,   750,   751,   752,
     753,   754,   755,   756,   757,   758,   759,   760,   761,   598,
     670,   874,   671,   876,   686,   878,   599,   600,   601,   602,
     881,   604,   605,   606,   607,   608,   800,   688,   609,   610,
     611,   698,   612,   613,   666,   603,   598,   704,   712,   801,
     802,   706,   707,   599,   600,   601,   602,   715,   794,   713,
     714,   803,   716,   726,   717,   729,   804,   663,   665,   718,
     507,   507,   603,   719,   805,   806,   720,   723,   724,   725,
     727,   736,   737,   302,   734,   738,   739,   741,   711,   740,
     745,   772,   764,   771,   604,   605,   606,   607,   608,   773,
     774,   609,   610,   611,   746,   612,   613,   775,   776,   779,
     785,   786,   810,   798,  -534,   705,   799,   813,   302,   814,
     831,   604,   605,   606,   607,   731,   832,   837,   609,   610,
     611,   838,   612,   613,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   855,   856,   747,   748,   749,
     750,   751,   752,   753,   754,   755,   756,   757,   758,   759,
     760,   761,   863,   857,   858,   871,   293,   875,   430,   873,
     150,   788,   316,   778,   302,   795,   367,   728,   584,   669,
     668,   695,   545,   493,   494,   495,   496,   694,   859,   551,
     702,   701,   625,   442,   383,   579,   387,   389,   424,   693,
     536,   769,   770,     0,     0,     0,     0,     0,     0,     0,
       0,   777,     0,     0,   497,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   302,
     790,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,   812,     0,     0,     0,     0,
       0,     0,     0,     0,   825,   826,     0,   392,   393,   153,
       0,     0,   154,   155,   156,   157,   158,   394,     0,   839,
     840,   159,     0,   429,   160,   161,   162,   163,     0,     0,
       0,   164,     0,   165,   166,   395,     0,   396,     0,   167,
     168,     0,     0,     0,   862,     0,     0,   169,     0,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   397,   227,   228,   229,
     398,   230,   231,   232,   233,   234,     0,   235,   236,   237,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,   251,   399,   400,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,     0,   268,   269,   270,   271,   272,
     273,   274,   275,   276,     0,   277,   392,   393,   153,     0,
       0,   154,   155,   156,   157,   158,   394,     0,     0,     0,
     159,     0,     0,   160,   161,   162,   163,     0,     0,     0,
     164,     0,   165,   166,   395,     0,   396,     0,   167,   168,
       0,     0,     0,     0,     0,     0,   169,     0,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   397,   227,   228,   229,   398,
     230,   231,   232,   233,   234,     0,   235,   236,   237,   238,
       0,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,     0,   251,   399,   400,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,     0,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   153,   277,     0,   154,   155,   156,   157,
     158,     0,     0,     0,   520,   159,     0,     0,   160,   161,
     162,   163,     0,     0,     0,   164,   521,   165,   166,     0,
       0,   522,     0,   167,   168,   523,     0,     0,     0,   524,
     525,   169,     0,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
       0,   227,   228,   229,     0,   230,   231,   232,   233,   234,
       0,   235,   526,   237,   238,   527,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       0,     0,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   268,
     269,   270,   271,   272,   528,   274,   275,   276,     0,   277,
       4,     5,     6,     7,     8,     0,     0,     9,     0,    10,
       0,     0,    11,     0,     0,    12,    13,    14,    15,     0,
       0,     0,     0,    16,    17,    18,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,     0,    21,     0,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,    83,    84,    85,    86,    87,     0,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   153,     0,     0,
     154,   155,   156,   157,   158,     0,     0,     0,   520,   159,
       0,     0,   160,   161,   162,   163,     0,     0,     0,   164,
     521,   165,   166,     0,     0,   522,     0,   167,   168,     0,
       0,     0,     0,     0,     0,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,   227,   228,   229,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,   527,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   153,   277,     0,   154,   155,   156,   157,   158,
       0,   298,     0,     0,   159,     0,     0,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,     0,     0,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
     169,   299,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     227,   228,   229,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     0,
       0,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   153,   277,     0,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   159,
       0,     0,   160,   408,   162,   163,     0,     0,     0,   164,
       0,   165,   166,     0,     0,     0,     0,   167,   168,     0,
       0,   409,     0,     0,     0,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,   227,   228,   229,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   410,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   153,   277,     0,   154,   155,   156,   157,   158,
       0,     0,     0,     0,   159,     0,     0,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,     0,   517,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
     169,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     227,   228,   229,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     0,
       0,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   518,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   153,   277,     0,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   159,
       0,     0,   160,   161,   162,   163,     0,     0,     0,   164,
       0,   165,   166,     0,     0,   311,     0,   167,   168,     0,
       0,     0,     0,     0,     0,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,   227,   228,   229,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   153,   277,     0,   154,   155,   156,   157,   158,
       0,   298,     0,     0,   159,     0,     0,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,     0,     0,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
     169,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     227,   228,   229,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     0,
       0,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   318,   277,     0,
     154,   155,   156,   319,   158,     0,   298,     0,     0,   159,
       0,     0,   160,   161,   162,   163,     0,     0,     0,   164,
       0,   165,   166,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,   169,     0,   170,   171,   320,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,   227,   228,   229,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   321,     0,   251,     0,     0,   252,   322,   323,   255,
     256,   257,   258,   259,   260,   261,   324,   325,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   153,   277,     0,   154,   155,   156,   157,   158,
       0,   478,     0,     0,   159,     0,     0,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,     0,     0,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
     169,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     227,   228,   229,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     0,
       0,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   153,   277,     0,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   159,
       0,     0,   160,   161,   162,   163,     0,     0,     0,   164,
       0,   165,   166,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,   227,   228,   229,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   591,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   153,   277,     0,   154,   155,   156,   157,   158,
       0,     0,     0,     0,   159,     0,     0,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,     0,     0,
       0,     0,   167,   168,     0,     0,   662,     0,     0,     0,
     169,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     227,   228,   229,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     0,
       0,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   153,   277,     0,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   159,
       0,     0,   160,   161,   162,   163,     0,     0,     0,   164,
       0,   165,   166,     0,     0,     0,     0,   167,   168,     0,
       0,   664,     0,     0,     0,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,   227,   228,   229,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   153,   277,     0,   154,   155,   156,   157,   158,
       0,     0,     0,     0,   159,     0,     0,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,     0,     0,
       0,     0,   167,   168,     0,     0,   789,     0,     0,     0,
     169,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     227,   228,   229,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     0,
       0,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   153,   277,     0,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   159,
       0,     0,   160,   161,   162,   163,     0,     0,     0,   164,
       0,   165,   166,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,   227,   228,   229,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   318,   277,     0,   154,   155,   156,   319,   158,
       0,     0,     0,     0,   159,     0,     0,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,     0,     0,
       0,     0,   167,   168,     0,     0,     0,     0,     0,     0,
     169,     0,   170,   171,   320,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     227,   228,   229,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   321,     0,   251,     0,
       0,   252,   322,   323,   255,   256,   257,   258,   259,   260,
     261,   324,   325,   264,   265,   266,   267,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   153,   277,     0,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   159,
       0,     0,   160,   506,   162,   163,     0,     0,     0,   164,
       0,   165,   166,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,   169,     0,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,     0,   227,   228,   229,     0,   230,
     231,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   153,   277,     0,   154,   155,   156,   157,   158,
       0,     0,     0,     0,   159,     0,     0,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,     0,     0,
       0,     0,   167,   787,     0,     0,     0,     0,     0,     0,
     169,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     227,   228,   229,     0,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,     0,
       0,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,     0,   277
};

static const yytype_int16 yycheck[] =
{
     144,   145,   303,    14,   289,   149,   306,   465,    33,    24,
     468,    16,    17,    16,    17,   386,   688,   388,   303,    33,
      44,   341,    16,    15,    44,   424,   327,   327,    33,     8,
      33,   480,    37,     0,   818,   819,    25,    10,    11,    23,
      27,    32,    24,    68,    16,   416,    44,    41,    42,    46,
     499,    35,    44,    33,    68,    24,   376,    30,   457,   843,
     844,    33,   287,   456,    38,    76,    15,    58,    36,   369,
      44,    24,    25,    26,   299,    38,    44,   535,    76,   450,
      95,    44,    31,    25,    68,   109,   386,   458,   388,   109,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   114,
     782,    27,   117,    95,   117,    28,   107,   108,   109,   103,
     104,   105,   147,   114,   115,   116,    95,   118,   119,   101,
     523,   524,   525,   526,   131,   146,    38,   148,   149,    28,
     151,   152,    44,   287,   155,   289,    12,    32,   146,    34,
     148,   149,   296,   151,   152,   299,   614,   155,   458,   303,
      38,    38,   306,    10,    11,     7,    44,    44,    29,   454,
     455,   132,   133,   157,   158,    79,   477,   161,   137,   138,
     139,   140,    16,   327,   120,   121,   122,   123,   124,   125,
     126,    29,   336,   337,   338,   339,    32,   590,     6,   343,
     137,   138,   139,    93,    94,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,     9,   610,   159,   363,
      79,    16,   615,    26,    76,   369,   370,   110,   111,   835,
     836,   375,   517,   137,   138,   139,   140,   141,   142,   143,
     384,    32,   386,    18,   388,   324,   325,    32,    39,    40,
      41,    42,   108,    43,    33,    37,    34,    16,   402,   146,
     134,    24,    26,   407,    26,   409,    37,    58,    44,    34,
     414,     3,   416,    26,    26,    13,   734,    13,   137,   138,
     139,    39,   141,   142,   143,    16,    37,    26,    29,   433,
     114,    26,    16,   686,   146,   439,   148,   149,   108,   151,
     152,    16,    14,   155,   448,    38,   450,    37,    28,    46,
     454,   455,   597,    15,   458,    44,   107,   108,   109,   110,
     111,    26,    26,   114,   115,   116,    32,   118,   119,   473,
      37,    16,    38,    39,    40,    41,    42,   481,   731,    95,
      33,    32,    45,   140,   737,    37,    44,   632,   492,    38,
      16,    37,    58,   120,   121,   122,   123,   124,   125,   126,
     504,    95,   153,    37,    26,   845,   846,   847,   848,   849,
      95,   851,    16,   517,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    32,
      37,   871,    33,   873,    58,   875,    39,    40,    41,    42,
     880,   107,   108,   109,   110,   111,     3,    37,   114,   115,
     116,    16,   118,   119,    96,    58,    32,    16,    32,    16,
      17,    15,    12,    39,    40,    41,    42,    58,   113,    32,
      32,    28,    58,    44,    32,    16,    33,   581,   582,    32,
     584,   585,    58,    32,    41,    42,    32,    32,    32,    32,
     127,    38,    44,   597,   154,    16,    38,    32,   743,    38,
      32,    37,    33,    33,   107,   108,   109,   110,   111,    33,
      33,   114,   115,   116,    16,   118,   119,    33,    33,    44,
      38,    16,    16,    26,    32,   629,    26,    26,   632,    26,
      16,   107,   108,   109,   110,   111,    16,    38,   114,   115,
     116,    26,   118,   119,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    17,    17,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    38,    33,    33,    58,   282,   111,   402,    37,
     141,   743,   303,   726,   688,   762,   327,   667,   508,   585,
     584,   620,   474,    97,    98,    99,   100,   619,   834,   489,
     626,   624,   568,   414,   344,   504,   352,   361,   388,   618,
     458,   715,   716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   725,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   743,
     744,   745,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   782,    -1,
      -1,    -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   798,   799,    -1,     3,     4,     5,
      -1,    -1,     8,     9,    10,    11,    12,    13,    -1,   813,
     814,    17,    -1,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    27,    -1,    29,    30,    31,    -1,    33,    -1,    35,
      36,    -1,    -1,    -1,   838,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,   113,   114,   115,
     116,    -1,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,   159,    -1,   161,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      27,    -1,    29,    30,    31,    -1,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    -1,   113,   114,   115,   116,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     5,   161,    -1,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    16,    17,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      -1,    33,    -1,    35,    36,    37,    -1,    -1,    -1,    41,
      42,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,   107,   108,   109,   110,   111,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,   131,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
     152,   153,   154,   155,   156,   157,   158,   159,    -1,   161,
       5,     6,     7,     8,     9,    -1,    -1,    12,    -1,    14,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,     5,    -1,    -1,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     5,   161,    -1,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     5,   161,    -1,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     5,   161,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    32,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     5,   161,    -1,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     5,   161,    -1,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     5,   161,    -1,
       8,     9,    10,    11,    12,    -1,    14,    -1,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     5,   161,    -1,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     5,   161,    -1,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     5,   161,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     5,   161,    -1,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     5,   161,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     5,   161,    -1,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     5,   161,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     5,   161,    -1,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
     108,   109,   110,   111,    -1,   113,   114,   115,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,   131,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     5,   161,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    -1,   161
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     8,   163,   164,     5,     6,     7,     8,     9,    12,
      14,    17,    20,    21,    22,    23,    28,    29,    30,    35,
      36,    43,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   107,   108,   109,   110,   111,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   165,   167,   295,     0,    10,
      11,   168,   169,    27,    25,    25,    27,    33,   170,    30,
     169,   187,    28,     5,     8,     9,    10,    11,    12,    17,
      20,    21,    22,    23,    27,    29,    30,    35,    36,    43,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   103,   104,   105,
     107,   108,   109,   110,   111,   113,   114,   115,   116,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   131,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   161,   166,   296,
     166,    28,   171,    12,   172,   177,   166,   188,   189,     7,
     192,    29,    29,   172,    16,   173,    32,   190,    14,    44,
     178,   189,   166,   193,   194,   233,     6,   216,     9,   159,
     176,    33,   166,   191,   189,   178,   194,   195,     5,    11,
      47,   129,   135,   136,   144,   145,   166,   217,   218,   219,
     259,   264,   266,   282,    16,    18,    26,    24,    25,    26,
      32,   196,   197,   108,   260,   261,    43,    33,    37,   137,
     138,   139,   276,   278,    79,   137,   138,   139,   141,   142,
     143,   277,   279,   146,   283,   283,   178,   218,    34,   134,
     174,   166,   166,   166,   166,   198,    34,   197,   166,   262,
     263,   264,   265,   261,   220,    16,   140,   278,   140,   279,
     166,   264,     3,     4,    13,    31,    33,   102,   106,   132,
     133,   166,   179,   180,   181,   182,   183,    24,    21,    39,
     130,   166,   203,   197,    44,   109,    26,   166,   224,    44,
     264,   265,   280,   281,   280,    37,    34,   223,   184,    19,
     181,     3,   166,    26,   166,    46,   131,   201,   202,    26,
      13,   200,   263,    39,   222,   166,   265,    13,    37,    16,
      26,    44,    76,   148,   149,   151,   152,   155,   226,   267,
     268,   270,   271,   272,   273,   274,   275,   283,   274,   284,
     132,   133,   185,   230,   231,   232,   234,   175,    14,   166,
     229,    26,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    97,    98,    99,   100,   128,   236,    29,
     114,   166,    16,   199,   108,    16,    21,   166,   225,   227,
     228,    38,   265,    33,    68,   147,   233,    32,   150,   233,
      16,    28,    33,    37,    41,    42,   114,   117,   156,   166,
     233,   288,   291,   292,   293,   274,   281,   267,   285,   286,
     287,   288,    15,    31,   166,   232,   178,   201,   166,    37,
     240,   240,   120,   121,   122,   123,   124,   125,   126,   247,
     248,   250,   120,   121,   122,   123,   124,   125,   126,   241,
     244,   245,   166,   201,    28,    15,    44,    44,   210,   262,
      15,    26,    26,    38,   226,    45,    95,    33,    33,    68,
      32,   150,   233,   288,   288,   288,   288,   140,    32,    39,
      40,    41,    42,    58,   107,   108,   109,   110,   111,   114,
     115,   116,   118,   119,   153,    37,    14,    38,    44,   186,
     235,    16,    37,   251,    95,   251,    95,    37,   242,    26,
      16,    23,    35,    68,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   103,   104,   105,   157,   158,   161,   211,
     212,   109,    39,   166,    39,   166,    96,   221,   228,   227,
      37,    33,   288,    38,   233,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,    58,   288,    37,   267,
     288,   289,   290,   287,   234,   230,    38,    44,    16,   243,
     249,   250,   245,   246,    16,   166,    15,    12,   204,   205,
     206,   233,    32,    32,    32,    58,    58,    32,    32,    32,
      32,    93,    94,    32,    32,    32,    44,   127,   223,    16,
     288,   111,   293,   294,   154,   269,    38,    44,    16,    38,
      38,    32,    36,    44,   209,    32,    16,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,   214,   215,    33,    16,    33,   101,   213,   166,
     166,    33,    37,    33,    33,    33,    33,   166,   212,    44,
     288,    38,    44,   267,   288,    38,    16,    36,   205,    39,
     166,   208,   166,   207,   113,   215,   252,   253,    26,    26,
       3,    16,    17,    28,    33,    41,    42,   237,   238,   239,
      16,   293,   166,    26,    26,    16,    17,    33,    37,   114,
     117,   254,   255,   256,   257,   166,   166,    24,    95,    24,
      95,    16,    16,    38,    44,    24,    95,    38,    26,   166,
     166,   255,   255,   110,   111,    32,    58,   107,   108,   109,
     114,   115,   116,   118,   119,    17,    17,    33,    33,   239,
     238,   238,   166,    38,   255,   255,   256,   256,   256,   256,
     256,    58,   256,    37,   256,   111,   256,   258,   256,    38,
      44,   256
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
        case 2:
#line 132 "screen.yacc"
    {
A4GL_check_compiled_form();
A4GL_write_form();}
    break;

  case 3:
#line 137 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:
#line 138 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 143 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 144 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 11:
#line 163 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:
#line 164 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:
#line 166 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 17:
#line 172 "screen.yacc"
    {
	char buff[256];
	sprintf(buff,"Screen %d", the_form.snames.snames_len);
		the_form.snames.snames_len++;the_form.snames.snames_val=
			realloc(the_form.snames.snames_val,
				(the_form.snames.snames_len)*
					sizeof(struct screen_name));

		the_form.snames.snames_val[the_form.snames.snames_len-1].name=
				acl_strdup(buff);

		in_screen_section=1; 
	}
    break;

  case 19:
#line 185 "screen.yacc"
    {
	char buff[256];
	char *ptr;
	the_form.snames.snames_len++;the_form.snames.snames_val=
		realloc(the_form.snames.snames_val, 
			(the_form.snames.snames_len)*
				sizeof(struct screen_name));
		sprintf(buff,"%s", (yyvsp[(2) - (2)].str));
		ptr=buff;
		ptr++;
		ptr[strlen(ptr)-1]=0;

		the_form.snames.snames_val[
			the_form.snames.snames_len-1].name =acl_strdup(ptr);

	in_screen_section=1; 
	}
    break;

  case 21:
#line 204 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 22:
#line 206 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 23:
#line 209 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 26:
#line 214 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 29:
#line 221 "screen.yacc"
    {
	int c;
	int l;
	if (A4GL_isyes(acl_getenv("USE_FORM_SIZE"))) {
		c=atoi((yyvsp[(4) - (4)].str));
		l=atoi((yyvsp[(2) - (4)].str));
        	if (c>the_form.maxcol) the_form.maxcol=c;
        	if (l>the_form.maxline) the_form.maxline=l;
	}
}
    break;

  case 34:
#line 243 "screen.yacc"
    {
	int a;
	static char buff[256];
	strcpy(buff,(yyvsp[(1) - (1)].str));
	if (A4GL_isyes(acl_getenv("SPACESCORE"))) {
		for (a=0;a<strlen(buff);a++) {
			if (buff[a]=='_') buff[a]=' ';
		}
	}
	strcpy((yyval.str),buff);
}
    break;

  case 35:
#line 258 "screen.yacc"
    {
        //printf("%s %d %d %d %d %d %s\n","_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	if (lineno) {
        //A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
        A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth((yyvsp[(1) - (1)].str)),scr,0,(yyvsp[(1) - (1)].str)); /* utf8 */
	colno+=A4GL_wcswidth((yyvsp[(1) - (1)].str));		/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 36:
#line 270 "screen.yacc"
    { ltab=0; }
    break;

  case 37:
#line 271 "screen.yacc"
    {
	if (colno==0&&replicate_bug) {colno=4; ltab=1;}
	else {
		if (colno==4&&replicate_bug) {colno=16;}
		else {
			colno++;
			while ((colno%8)!=0) {colno++;}
		}
		ltab=0;
	}
}
    break;

  case 38:
#line 282 "screen.yacc"
    {
	char buff[256];
	if (lineno) {
	sprintf(buff,"\n%s",(yyvsp[(1) - (1)].str));
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,(yyvsp[(1) - (1)].str));
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 39:
#line 293 "screen.yacc"
    {
	char buff[256];
	if (lineno) {
	strcpy(buff,(yyvsp[(1) - (1)].str));
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,(yyvsp[(1) - (1)].str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 40:
#line 306 "screen.yacc"
    {
	if (lineno) {
	//A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
	A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth((yyvsp[(1) - (1)].str)),scr,0,(yyvsp[(1) - (1)].str));	/* utf8 */
	colno+=A4GL_wcswidth((yyvsp[(1) - (1)].str));	/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 41:
#line 318 "screen.yacc"
    {
	if (lineno) {
	//A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
	A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth((yyvsp[(1) - (1)].str)),scr,0,(yyvsp[(1) - (1)].str));	/* utf8 */
	colno+=A4GL_wcswidth((yyvsp[(1) - (1)].str));	/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 42:
#line 329 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 43:
#line 334 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 44:
#line 337 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 45:
#line 345 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 46:
#line 346 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 47:
#line 352 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 48:
#line 359 "screen.yacc"
    {
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field((yyvsp[(3) - (4)].str),fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field((yyvsp[(3) - (4)].str),fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 49:
#line 373 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 50:
#line 376 "screen.yacc"
    {
				/* field elements = name x y width screen_no endswith'|' */
				colno++;
				if (colno>the_form.maxcol) the_form.maxcol=colno; 
				if (lineno>the_form.maxline) the_form.maxline=lineno;
				if (openwith=='[')
					A4GL_add_field((yyvsp[(1) - (2)].str),fstart+1,lineno,colno-fstart-1,scr,1,"");
				else
					A4GL_add_field((yyvsp[(1) - (2)].str),fstart+1,lineno,colno-fstart-1,scr,0,"");
				fstart=colno;
				openwith='|';
			}
    break;

  case 51:
#line 387 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 57:
#line 403 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 58:
#line 412 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 59:
#line 413 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 60:
#line 416 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 61:
#line 417 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 62:
#line 419 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 63:
#line 420 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 64:
#line 421 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 69:
#line 436 "screen.yacc"
    {
	A4GL_make_downshift((yyvsp[(1) - (1)].str));
	strcpy(currftag,(yyvsp[(1) - (1)].str));
	fldno=A4GL_find_field((yyvsp[(1) - (1)].str));
}
    break;

  case 74:
#line 452 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 75:
#line 456 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 76:
#line 464 "screen.yacc"
    {
	if (A4GL_has_str_attribute(fld,FA_S_FORMAT)) {
		int dtype;
		dtype=fld->datatype & DTYPE_MASK;

		if (dtype!=DTYPE_INT  &&
		    dtype!=DTYPE_SMINT  &&
		    dtype!=DTYPE_FLOAT  &&
		    dtype!=DTYPE_SMFLOAT  &&
		    dtype!=DTYPE_DATE  &&
		    dtype!=DTYPE_DECIMAL  &&
		    dtype!=DTYPE_MONEY) {
	        		yyerror("A FORMAT cannot be applied to this fields because of the datatype");
	        		YYERROR;
				printf("X1\n");
		}
	}

	if (fld->datatype==90&&!(A4GL_has_str_attribute(fld,FA_S_DEFAULT)))
	{
	        extern FILE *yyin;

			A4GL_debug("Currpos = %ld\n",ftell(yyin));
	        yyerror("A button must have a default value for its caption");
	        YYERROR;
	}
	if (!(A4GL_has_str_attribute(fld,FA_S_PICTURE)) && strcmp(the_form.dbname,"formonly")!=0 ) {
		char *p;
	
		p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"PICTURE");
		if (p) {
			// Theres a picture in syscolval - but nothing in the form -
			// Use the syscolval one...
			A4GL_add_str_attr(fld,FA_S_PICTURE,p);
			//printf("Setting field picture from syscolval (%s)\n",p);
		}
	}
	a4gl_status=0;
	A4GL_set_field(currftag,fld);
	if (a4gl_status!=0) {
		yyerror(A4GL_get_fcompile_err());
	}
}
    break;

  case 78:
#line 512 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 79:
#line 516 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 80:
#line 524 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 81:
#line 525 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 82:
#line 528 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 83:
#line 529 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 84:
#line 532 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 85:
#line 535 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 86:
#line 540 "screen.yacc"
    {
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup((yyvsp[(3) - (4)].str));
        fld->datatype=atoi((yyvsp[(4) - (4)].str))&0xff;
	if (atoi((yyvsp[(4) - (4)].str))&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi((yyvsp[(4) - (4)].str))&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 87:
#line 549 "screen.yacc"
    {
	static int xdo=0;
	char buff[256];
	sprintf(buff,"_do_%d",xdo++);
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(buff);
        fld->datatype=atoi((yyvsp[(2) - (2)].str))&0xff;
	if (atoi((yyvsp[(2) - (2)].str))&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi((yyvsp[(2) - (2)].str))&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 88:
#line 561 "screen.yacc"
    {
	static int di=0;
	char buff[256];
	sprintf(buff,"_di_%d",di++);
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(buff);
        fld->datatype=atoi((yyvsp[(4) - (4)].str))&0xff;
	if (atoi((yyvsp[(4) - (4)].str))&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi((yyvsp[(4) - (4)].str))&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 89:
#line 573 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 90:
#line 580 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 91:
#line 587 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 92:
#line 594 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 93:
#line 606 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 94:
#line 615 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 95:
#line 624 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 97:
#line 633 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 98:
#line 636 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 99:
#line 642 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 100:
#line 643 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 101:
#line 644 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 102:
#line 645 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(1) - (2)].str));}
    break;

  case 109:
#line 661 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 110:
#line 662 "screen.yacc"
    {
		if ((yyvsp[(4) - (4)].expr)==0)  {
			int a;
			struct  u_expression *e_true;
  			e_true=create_int_expr(1);
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi((yyvsp[(3) - (4)].str));
			fld->colours.colours_val[a-1].whereexpr=e_true;
		} else  {
			int a;
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi((yyvsp[(3) - (4)].str));
			fld->colours.colours_val[a-1].whereexpr=(yyvsp[(4) - (4)].expr);

		}
}
    break;

  case 111:
#line 682 "screen.yacc"
    {
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 112:
#line 688 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 113:
#line 689 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 114:
#line 690 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 115:
#line 691 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 116:
#line 692 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 117:
#line 693 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 118:
#line 694 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 119:
#line 695 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 120:
#line 696 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 121:
#line 697 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 122:
#line 698 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 123:
#line 699 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 124:
#line 700 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 125:
#line 701 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 126:
#line 702 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 127:
#line 703 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 128:
#line 704 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 129:
#line 705 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 130:
#line 706 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 131:
#line 707 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 132:
#line 708 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 133:
#line 709 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REQUIRED); }
    break;

  case 134:
#line 710 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REVERSE); }
    break;

  case 135:
#line 711 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 136:
#line 712 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_QUERYCLEAR); }
    break;

  case 137:
#line 713 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_ZEROFILL); }
    break;

  case 138:
#line 714 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_RIGHT); }
    break;

  case 139:
#line 715 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WORDWRAP); }
    break;

  case 140:
#line 716 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 141:
#line 720 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 142:
#line 726 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 143:
#line 727 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 144:
#line 728 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 146:
#line 733 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 147:
#line 737 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 148:
#line 738 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 149:
#line 739 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 150:
#line 740 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 151:
#line 741 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 152:
#line 742 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 153:
#line 743 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 154:
#line 744 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 155:
#line 746 "screen.yacc"
    { 
			char *ptr;
			
			ptr=(yyvsp[(1) - (1)].str);
			if (strlen(ptr) > 1) {
	        		yyerror("Colour number out of range 0-7");
			}
			if (*ptr>='0'||*ptr<='7') ;
			else {
	        		yyerror("Colour number out of range 0-7");
			}
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
		}
    break;

  case 156:
#line 760 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 157:
#line 761 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 158:
#line 762 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 159:
#line 763 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 160:
#line 764 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 161:
#line 765 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 162:
#line 766 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 169:
#line 779 "screen.yacc"
    {
	char buff[4];
	strcpy(buff,A4GL_char_val((yyvsp[(2) - (2)].str)));
	if (strlen(buff)==1) {
		buff[1]=buff[0];
		buff[2]=buff[0];
		buff[3]=0;
	}
	the_form.delim=acl_strdup(buff);
}
    break;

  case 170:
#line 789 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 171:
#line 795 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 178:
#line 806 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 179:
#line 806 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 182:
#line 811 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 183:
#line 814 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 184:
#line 820 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 185:
#line 823 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 188:
#line 833 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),""); }
    break;

  case 189:
#line 835 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); }
    break;

  case 190:
#line 837 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); }
    break;

  case 191:
#line 839 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); }
    break;

  case 192:
#line 841 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 194:
#line 845 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 195:
#line 849 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 196:
#line 852 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 197:
#line 856 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 198:
#line 856 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 201:
#line 863 "screen.yacc"
    {colno++;}
    break;

  case 202:
#line 864 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 203:
#line 877 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 204:
#line 885 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 205:
#line 887 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 206:
#line 894 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 207:
#line 898 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 208:
#line 902 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 209:
#line 906 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 210:
#line 910 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 211:
#line 914 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 212:
#line 918 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 213:
#line 924 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 214:
#line 928 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 215:
#line 932 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 216:
#line 936 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 217:
#line 940 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 218:
#line 944 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 219:
#line 948 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 220:
#line 951 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 222:
#line 958 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 225:
#line 963 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 226:
#line 968 "screen.yacc"
    { 
	if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
		sprintf((yyval.str),"NULL");
	} else {
		strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
	}
}
    break;

  case 227:
#line 975 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 228:
#line 976 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 229:
#line 977 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 230:
#line 978 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 232:
#line 980 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 233:
#line 981 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 234:
#line 982 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 235:
#line 986 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 236:
#line 990 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 237:
#line 996 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 238:
#line 999 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 239:
#line 1000 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 240:
#line 1003 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 241:
#line 1005 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 242:
#line 1011 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 243:
#line 1013 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 244:
#line 1018 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 245:
#line 1026 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 246:
#line 1029 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 247:
#line 1030 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 248:
#line 1031 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 249:
#line 1032 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 250:
#line 1033 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 251:
#line 1034 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 252:
#line 1036 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 254:
#line 1043 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 255:
#line 1044 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 256:
#line 1047 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 257:
#line 1050 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 258:
#line 1054 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 259:
#line 1055 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 260:
#line 1056 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 261:
#line 1057 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 262:
#line 1058 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 263:
#line 1059 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 264:
#line 1061 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 265:
#line 1066 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 266:
#line 1068 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 267:
#line 1075 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 268:
#line 1075 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 269:
#line 1081 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 271:
#line 1088 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 272:
#line 1091 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 273:
#line 1097 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 274:
#line 1098 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 275:
#line 1099 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 276:
#line 1100 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 277:
#line 1101 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 278:
#line 1102 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 279:
#line 1103 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 280:
#line 1104 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 281:
#line 1105 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 282:
#line 1106 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 283:
#line 1107 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 284:
#line 1108 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 285:
#line 1109 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 286:
#line 1112 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 287:
#line 1119 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 288:
#line 1120 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 289:
#line 1121 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 291:
#line 1129 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 292:
#line 1133 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 296:
#line 1153 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 297:
#line 1163 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 298:
#line 1170 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 299:
#line 1179 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 300:
#line 1183 "screen.yacc"
    {
	(yyval.column).tabname=strdup("");
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 303:
#line 1197 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 304:
#line 1204 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 305:
#line 1212 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 306:
#line 1217 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 307:
#line 1225 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 308:
#line 1229 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 309:
#line 1234 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 310:
#line 1239 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 311:
#line 1244 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 312:
#line 1249 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 313:
#line 1254 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 314:
#line 1263 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 315:
#line 1272 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 316:
#line 1273 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 318:
#line 1282 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 319:
#line 1290 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 320:
#line 1296 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 321:
#line 1302 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 322:
#line 1308 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 323:
#line 1316 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 324:
#line 1321 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 325:
#line 1331 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 326:
#line 1341 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 327:
#line 1347 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 328:
#line 1353 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 329:
#line 1359 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 330:
#line 1369 "screen.yacc"
    {
		(yyval.befact)=malloc(sizeof(struct s_bef_aft));
		(yyval.befact)->cmds=0;
		(yyval.befact)->column_list=0;
		(yyval.befact)->befaftlist.befaftlist_len=0;
		(yyval.befact)->befaftlist.befaftlist_val=0;		

		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(1) - (1)].intval);

	}
    break;

  case 331:
#line 1381 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 332:
#line 1389 "screen.yacc"
    {
		(yyval.befact)=malloc(sizeof(struct s_bef_aft));
		(yyval.befact)->cmds=0;
		(yyval.befact)->column_list=0;
		(yyval.befact)->befaftlist.befaftlist_len=0;
		(yyval.befact)->befaftlist.befaftlist_val=0;		

		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(1) - (1)].intval);

	}
    break;

  case 333:
#line 1401 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 334:
#line 1409 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 335:
#line 1410 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 336:
#line 1411 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 337:
#line 1415 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 338:
#line 1416 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 339:
#line 1417 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 340:
#line 1418 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 341:
#line 1419 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 342:
#line 1420 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 343:
#line 1421 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 344:
#line 1424 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 345:
#line 1431 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 346:
#line 1442 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 347:
#line 1446 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 348:
#line 1453 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 349:
#line 1461 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 350:
#line 1466 "screen.yacc"
    {
		if ((yyvsp[(5) - (6)].el)) {
			listitem *l;
			(yyval.fcall)->list_parameters.list_parameters_len=(yyvsp[(5) - (6)].el)->nlist;
			l=(yyvsp[(5) - (6)].el)->expr_list;
			(yyval.fcall)->list_parameters.list_parameters_val=l;
		}
	}
    break;

  case 351:
#line 1477 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 352:
#line 1478 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 353:
#line 1484 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 354:
#line 1490 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 355:
#line 1498 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 357:
#line 1506 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 358:
#line 1507 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 363:
#line 1521 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 364:
#line 1523 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 365:
#line 1524 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 366:
#line 1525 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 367:
#line 1526 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 368:
#line 1527 "screen.yacc"
    { (yyval.expr)=(yyvsp[(3) - (4)].expr); }
    break;

  case 369:
#line 1528 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 370:
#line 1529 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 371:
#line 1530 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 372:
#line 1531 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 373:
#line 1532 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 374:
#line 1533 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 375:
#line 1534 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 376:
#line 1535 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 377:
#line 1536 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 378:
#line 1537 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 379:
#line 1538 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 380:
#line 1539 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 381:
#line 1540 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 382:
#line 1541 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 383:
#line 1542 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 385:
#line 1548 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 386:
#line 1549 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 387:
#line 1550 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 388:
#line 1551 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 389:
#line 1552 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 390:
#line 1555 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 391:
#line 1559 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 5532 "y.tab.c"
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


#line 1834 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




