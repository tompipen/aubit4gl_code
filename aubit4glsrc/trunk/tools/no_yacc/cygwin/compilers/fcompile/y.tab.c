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
     KW_OR = 258,
     KW_AND = 259,
     KW_NOT = 260,
     IS_NOT_NULL = 261,
     IS_NULL = 262,
     LESSTHAN = 263,
     GREATERTHAN = 264,
     KW_PLUS = 265,
     KW_MINUS = 266,
     KW_MULTIPLY = 267,
     KW_DIVIDE = 268,
     KW_MOD = 269,
     KW_POWER = 270,
     CH = 271,
     GRAPH_CH = 272,
     KW_COMPOSITES = 273,
     INSTRUCTIONS = 274,
     ATTRIBUTES = 275,
     DATABASE = 276,
     BY = 277,
     KW_SCREEN_TITLE = 278,
     KW_SCREEN = 279,
     KW_SIZE = 280,
     OPEN_SQUARE = 281,
     KW_END = 282,
     CLOSE_SQUARE = 283,
     NUMBER_VALUE = 284,
     NAMED = 285,
     OPEN_BRACE = 286,
     CLOSE_BRACE = 287,
     TITLE = 288,
     FORMONLY = 289,
     COMMENT = 290,
     DYNAMIC = 291,
     COLON = 292,
     ATSIGN = 293,
     DOT = 294,
     WITHOUT = 295,
     KW_NULL = 296,
     INPUT = 297,
     TABLES = 298,
     PIPE = 299,
     EQUAL = 300,
     CHAR_VALUE = 301,
     SEMICOLON = 302,
     LOOKUP = 303,
     JOINING = 304,
     OPEN_BRACKET = 305,
     CLOSE_BRACKET = 306,
     STAR = 307,
     DIVIDE = 308,
     PLUS = 309,
     MINUS = 310,
     RECORD = 311,
     COMMA = 312,
     THROUGH = 313,
     TYPE = 314,
     DELIMITERS = 315,
     KW_CHAR = 316,
     KW_INT = 317,
     KW_DATE = 318,
     KW_FLOAT = 319,
     SMALLFLOAT = 320,
     SMALLINT = 321,
     KW_DECIMAL = 322,
     MONEY = 323,
     DATETIME = 324,
     INTERVAL = 325,
     LIKE = 326,
     BLACK = 327,
     BLUE = 328,
     GREEN = 329,
     CYAN = 330,
     RED = 331,
     MAGENTA = 332,
     WHITE = 333,
     YELLOW = 334,
     NORMAL = 335,
     REVERSE = 336,
     LEFT = 337,
     BOLD = 338,
     BLINK = 339,
     UNDERLINE = 340,
     DIM = 341,
     AUTONEXT = 342,
     COLOR = 343,
     COMMENTS = 344,
     DEFAULT = 345,
     VALIDATE = 346,
     DISPLAY = 347,
     DOWNSHIFT = 348,
     UPSHIFT = 349,
     FORMAT = 350,
     INCLUDE = 351,
     INVISIBLE = 352,
     NOUPDATE = 353,
     NOENTRY = 354,
     PICTURE = 355,
     PROGRAM = 356,
     REQUIRED = 357,
     QUERYCLEAR = 358,
     VERIFY = 359,
     WORDWRAP = 360,
     COMPRESS = 361,
     NONCOMPRESS = 362,
     TO = 363,
     AS = 364,
     SERIAL = 365,
     KW_BYTE = 366,
     KW_TEXT = 367,
     VARCHAR = 368,
     SQL_VAR = 369,
     KW_NONSPACE = 370,
     SQLONLY = 371,
     WIDGET = 372,
     CONFIG = 373,
     KW_NL = 374,
     COMPARISON = 375,
     KWOR = 376,
     KWAND = 377,
     KWAND1 = 378,
     KWWHERE = 379,
     KWNOT = 380,
     KWBETWEEN = 381,
     KWIN = 382,
     XVAL = 383,
     KWNULLCHK = 384,
     KWNOTNULLCHK = 385,
     YEAR = 386,
     MONTH = 387,
     DAY = 388,
     HOUR = 389,
     MINUTE = 390,
     SECOND = 391,
     FRACTION = 392,
     LISTBOX = 393,
     BUTTON = 394,
     KW_PANEL = 395,
     DISPLAYONLY = 396,
     ALLOWING = 397,
     KW_WS = 398,
     KW_TAB = 399,
     KW_MASTER_OF = 400,
     KW_BEFORE = 401,
     KW_AFTER = 402,
     KW_EDITADD = 403,
     KW_EDITUPDATE = 404,
     KW_REMOVE = 405,
     KW_OF = 406,
     KW_ADD = 407,
     KW_UPDATE = 408,
     KW_QUERY = 409,
     KW_ON_ENDING = 410,
     KW_ON_BEGINNING = 411,
     KW_CALL = 412,
     KW_BELL = 413,
     KW_ABORT = 414,
     KW_LET = 415,
     KW_EXITNOW = 416,
     KW_NEXTFIELD = 417,
     KW_IF = 418,
     KW_THEN = 419,
     KW_ELSE = 420,
     KW_BEGIN = 421,
     KW_TOTAL = 422,
     KW_RIGHT = 423,
     KW_ZEROFILL = 424,
     KW_USES_EXTENDED = 425,
     SPECIAL_DBNAME = 426,
     KW_ACTION = 427
   };
#endif
/* Tokens.  */
#define KW_OR 258
#define KW_AND 259
#define KW_NOT 260
#define IS_NOT_NULL 261
#define IS_NULL 262
#define LESSTHAN 263
#define GREATERTHAN 264
#define KW_PLUS 265
#define KW_MINUS 266
#define KW_MULTIPLY 267
#define KW_DIVIDE 268
#define KW_MOD 269
#define KW_POWER 270
#define CH 271
#define GRAPH_CH 272
#define KW_COMPOSITES 273
#define INSTRUCTIONS 274
#define ATTRIBUTES 275
#define DATABASE 276
#define BY 277
#define KW_SCREEN_TITLE 278
#define KW_SCREEN 279
#define KW_SIZE 280
#define OPEN_SQUARE 281
#define KW_END 282
#define CLOSE_SQUARE 283
#define NUMBER_VALUE 284
#define NAMED 285
#define OPEN_BRACE 286
#define CLOSE_BRACE 287
#define TITLE 288
#define FORMONLY 289
#define COMMENT 290
#define DYNAMIC 291
#define COLON 292
#define ATSIGN 293
#define DOT 294
#define WITHOUT 295
#define KW_NULL 296
#define INPUT 297
#define TABLES 298
#define PIPE 299
#define EQUAL 300
#define CHAR_VALUE 301
#define SEMICOLON 302
#define LOOKUP 303
#define JOINING 304
#define OPEN_BRACKET 305
#define CLOSE_BRACKET 306
#define STAR 307
#define DIVIDE 308
#define PLUS 309
#define MINUS 310
#define RECORD 311
#define COMMA 312
#define THROUGH 313
#define TYPE 314
#define DELIMITERS 315
#define KW_CHAR 316
#define KW_INT 317
#define KW_DATE 318
#define KW_FLOAT 319
#define SMALLFLOAT 320
#define SMALLINT 321
#define KW_DECIMAL 322
#define MONEY 323
#define DATETIME 324
#define INTERVAL 325
#define LIKE 326
#define BLACK 327
#define BLUE 328
#define GREEN 329
#define CYAN 330
#define RED 331
#define MAGENTA 332
#define WHITE 333
#define YELLOW 334
#define NORMAL 335
#define REVERSE 336
#define LEFT 337
#define BOLD 338
#define BLINK 339
#define UNDERLINE 340
#define DIM 341
#define AUTONEXT 342
#define COLOR 343
#define COMMENTS 344
#define DEFAULT 345
#define VALIDATE 346
#define DISPLAY 347
#define DOWNSHIFT 348
#define UPSHIFT 349
#define FORMAT 350
#define INCLUDE 351
#define INVISIBLE 352
#define NOUPDATE 353
#define NOENTRY 354
#define PICTURE 355
#define PROGRAM 356
#define REQUIRED 357
#define QUERYCLEAR 358
#define VERIFY 359
#define WORDWRAP 360
#define COMPRESS 361
#define NONCOMPRESS 362
#define TO 363
#define AS 364
#define SERIAL 365
#define KW_BYTE 366
#define KW_TEXT 367
#define VARCHAR 368
#define SQL_VAR 369
#define KW_NONSPACE 370
#define SQLONLY 371
#define WIDGET 372
#define CONFIG 373
#define KW_NL 374
#define COMPARISON 375
#define KWOR 376
#define KWAND 377
#define KWAND1 378
#define KWWHERE 379
#define KWNOT 380
#define KWBETWEEN 381
#define KWIN 382
#define XVAL 383
#define KWNULLCHK 384
#define KWNOTNULLCHK 385
#define YEAR 386
#define MONTH 387
#define DAY 388
#define HOUR 389
#define MINUTE 390
#define SECOND 391
#define FRACTION 392
#define LISTBOX 393
#define BUTTON 394
#define KW_PANEL 395
#define DISPLAYONLY 396
#define ALLOWING 397
#define KW_WS 398
#define KW_TAB 399
#define KW_MASTER_OF 400
#define KW_BEFORE 401
#define KW_AFTER 402
#define KW_EDITADD 403
#define KW_EDITUPDATE 404
#define KW_REMOVE 405
#define KW_OF 406
#define KW_ADD 407
#define KW_UPDATE 408
#define KW_QUERY 409
#define KW_ON_ENDING 410
#define KW_ON_BEGINNING 411
#define KW_CALL 412
#define KW_BELL 413
#define KW_ABORT 414
#define KW_LET 415
#define KW_EXITNOW 416
#define KW_NEXTFIELD 417
#define KW_IF 418
#define KW_THEN 419
#define KW_ELSE 420
#define KW_BEGIN 421
#define KW_TOTAL 422
#define KW_RIGHT 423
#define KW_ZEROFILL 424
#define KW_USES_EXTENDED 425
#define SPECIAL_DBNAME 426
#define KW_ACTION 427




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
#line 542 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 555 "y.tab.c"

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
#define YYLAST   4402

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  173
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  135
/* YYNRULES -- Number of rules.  */
#define YYNRULES  644
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1006

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   427

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
     165,   166,   167,   168,   169,   170,   171,   172
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
    1102,  1105,  1108,  1114,  1120,  1127,  1129,  1131,  1133,  1135,
    1137,  1139,  1141,  1145,  1147,  1149,  1151,  1153,  1155,  1157,
    1159,  1161,  1163,  1165,  1167,  1169,  1171,  1173,  1175,  1177,
    1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,  1197,
    1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,  1215,  1217,
    1219,  1221,  1223,  1225,  1227,  1229,  1231,  1233,  1235,  1237,
    1239,  1241,  1243,  1245,  1247,  1249,  1251,  1253,  1255,  1257,
    1259,  1261,  1263,  1265,  1267,  1269,  1271,  1273,  1275,  1277,
    1279,  1281,  1283,  1285,  1287,  1289,  1291,  1293,  1295,  1297,
    1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,
    1319,  1321,  1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,
    1339,  1341,  1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,
    1359,  1361,  1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,
    1379,  1381,  1383,  1385,  1387,  1389,  1391,  1393,  1395,  1397,
    1399,  1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1417,
    1419,  1421,  1423,  1425,  1427,  1429,  1431,  1433,  1435,  1437,
    1439,  1441,  1443,  1445,  1447,  1449,  1451,  1453,  1455,  1457,
    1459,  1461,  1463,  1465,  1467,  1469,  1471,  1473,  1475,  1477,
    1479,  1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1497,
    1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,  1517,
    1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,  1537,
    1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,  1557,
    1559,  1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,  1577,
    1579,  1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,  1597,
    1599,  1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,  1617,
    1619,  1621,  1623,  1625,  1627,  1629,  1631,  1633,  1635,  1637,
    1639,  1641,  1643,  1645,  1647
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     174,     0,    -1,   175,   179,   198,   203,   227,    -1,    21,
      34,    -1,    21,   178,    40,    41,    42,    -1,    21,    34,
      40,    41,    42,    -1,    21,   178,    -1,    30,    -1,   306,
      -1,    30,    -1,   307,    -1,   171,    -1,   171,    38,   177,
      -1,   176,    -1,   176,    38,   177,    -1,   180,    -1,   179,
     180,    -1,    -1,    24,   181,   183,    -1,    -1,    23,    46,
     182,   183,    -1,    -1,    -1,    -1,   188,   184,   187,    31,
     185,   190,    32,   186,   189,    -1,    -1,   170,    -1,    -1,
      25,    29,    -1,    25,    29,    22,    29,    -1,    -1,    27,
      -1,   192,    -1,   190,   192,    -1,   177,    -1,   191,    -1,
     194,    -1,   144,    -1,    17,    -1,    44,    -1,    46,    -1,
     193,    -1,   143,    -1,   119,    -1,   115,    -1,    16,    -1,
     193,    16,    -1,    -1,    26,   195,   196,    28,    -1,   245,
      -1,    -1,   196,    44,   197,   245,    -1,    -1,    43,   199,
     189,    -1,   200,    -1,   199,   200,    -1,   199,    57,   200,
      -1,   177,   201,    -1,    -1,    45,   202,    -1,   177,    -1,
     177,    37,   177,    -1,   177,    38,   177,    -1,   177,    38,
     177,    37,   177,    -1,   177,    39,   177,    -1,    46,    39,
     177,    -1,    20,   204,   189,    -1,   205,    -1,   204,   205,
      -1,    -1,   244,   206,   207,    47,    -1,   208,    -1,   207,
     208,    -1,   207,    47,   208,    -1,    -1,    -1,    45,   209,
     214,   211,   210,   221,    -1,    -1,    26,    29,    28,    -1,
      26,    29,    57,    29,    28,    -1,   213,   125,    41,    -1,
     213,    -1,    -1,    59,    71,   177,    39,   177,    -1,    59,
      71,   177,    -1,    59,   247,    -1,    34,    39,   240,   212,
      -1,   141,   212,    -1,   141,   142,    42,   212,    -1,   177,
      39,   177,    -1,   177,    -1,    52,   177,    39,   177,    -1,
      52,   177,    -1,   216,    -1,   215,    57,   216,    -1,   217,
      45,   218,    -1,   244,    -1,   177,    39,   177,    -1,   177,
      -1,   177,    39,   177,    -1,   177,    -1,    52,   177,    39,
     177,    -1,    52,   177,    -1,    49,    -1,    57,    49,    -1,
      -1,    57,   222,    -1,   223,    -1,   222,    57,   223,    -1,
      87,    -1,    88,    45,   225,   263,    -1,    48,   215,   220,
     219,    -1,    89,    45,    46,    -1,    90,    45,   224,    -1,
      92,    71,   177,    -1,    92,    71,   177,    39,   177,    -1,
      91,    71,   177,    -1,    91,    71,   177,    39,   177,    -1,
      93,    -1,    94,    -1,    95,    45,    46,    -1,    96,    45,
      50,   248,    51,    -1,   117,    45,    46,    -1,   118,    45,
      46,    -1,   172,    45,   177,    -1,    97,    -1,    36,    25,
      45,    29,    -1,    36,    -1,   116,    -1,    99,    -1,    98,
      -1,   100,    45,    46,    -1,   101,    45,    46,    -1,   102,
      -1,    81,    -1,   104,    -1,   103,    -1,   169,    -1,   168,
      -1,   105,    -1,   105,   106,    -1,   105,   107,    -1,    46,
      -1,    29,    -1,   114,    -1,   226,    -1,   225,   226,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    29,    -1,    81,    -1,
      86,    -1,    80,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    -1,    19,   228,   189,    -1,   229,    -1,   228,
     229,    -1,   230,    -1,   230,    47,    -1,    60,    46,    -1,
     277,    -1,    -1,    24,    56,   231,   235,    50,   236,    51,
     232,   234,    -1,   140,    50,    29,    57,    29,    51,   108,
      50,    29,    57,    29,    51,    -1,   270,    -1,   293,    -1,
      -1,   109,   138,    -1,    -1,    52,    -1,    -1,    47,    -1,
     177,    -1,   177,    26,    29,    28,    -1,   239,    -1,   236,
     237,   239,    -1,    -1,    57,    -1,   177,    -1,   177,    39,
     177,    -1,    34,    39,   177,    -1,   177,    39,    52,    -1,
      34,    39,    52,    -1,   238,    -1,   238,    58,   238,    -1,
     177,    -1,    27,    -1,    -1,   242,    -1,   243,    -1,   242,
     243,    -1,   143,    -1,   144,    -1,   177,    -1,    -1,   241,
     177,   246,   241,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,   251,    -1,    68,
     251,    -1,    69,   258,    -1,    70,   252,    -1,   110,    -1,
     111,    -1,   112,    -1,   113,    -1,   139,    -1,   250,    -1,
     248,    57,   250,    -1,    29,    -1,    54,    29,    -1,    55,
      29,    -1,    46,    -1,    30,    -1,    30,   108,    30,    -1,
      30,    37,    30,    -1,    16,    -1,   249,    -1,   249,   108,
     249,    -1,   249,    37,   249,    -1,    46,   108,    46,    -1,
      46,    37,    46,    -1,    41,    -1,    -1,    50,    29,    51,
      -1,    50,    29,    57,    29,    51,    -1,    -1,   255,   108,
     257,    -1,    -1,    50,    29,    51,    -1,    29,    -1,   256,
     253,    -1,   131,    -1,   132,    -1,   133,    -1,   134,    -1,
     135,    -1,   136,    -1,   137,   262,    -1,   256,    -1,    -1,
     259,   108,   260,    -1,   261,    -1,   261,    -1,   131,    -1,
     132,    -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,
     137,   262,    -1,    -1,    50,   254,    51,    -1,    -1,   264,
      -1,   124,   265,    -1,   266,    -1,   266,   122,   266,    -1,
     266,   121,   266,    -1,   267,   120,   267,    -1,   267,     8,
     267,    -1,   267,     9,   267,    -1,   267,    71,   267,    -1,
     267,   125,    71,   267,    -1,   267,    45,   267,    -1,   267,
     129,    -1,   267,   130,    -1,   267,    -1,   267,   126,   267,
     122,   267,    -1,   267,   127,    50,   269,    51,    -1,   125,
     266,    -1,    50,   266,    51,    -1,   268,    -1,    29,    -1,
      46,    -1,   128,    -1,    30,    -1,   267,    -1,   269,    57,
     267,    -1,    18,   271,    -1,   272,    -1,   271,   272,    -1,
       8,   273,     9,   233,     8,   273,     9,    -1,   274,    -1,
     273,    57,   274,    -1,   275,    39,   276,    -1,   276,    -1,
     177,    -1,   176,    -1,   146,   287,   151,   291,   285,    -1,
     147,   288,   151,   291,   285,    -1,   156,   294,    -1,   155,
     294,    -1,   281,    -1,   286,    -1,   279,    -1,   282,    -1,
     283,    -1,   294,    -1,   284,    -1,   163,   299,   164,   278,
     280,    -1,    -1,   165,   278,    -1,   159,    -1,   160,   244,
      45,   299,    -1,   162,   244,    -1,   162,    45,   244,    -1,
     162,   161,    -1,   162,    45,   161,    -1,   166,   285,    27,
      -1,   278,    -1,   285,   278,    -1,    89,    46,    -1,    89,
     158,    46,    -1,    89,    81,    46,    -1,    89,   158,    81,
      46,    -1,   289,    -1,   287,   289,    -1,   290,    -1,   288,
     290,    -1,   148,    -1,   149,    -1,   150,    -1,   148,    -1,
     152,    -1,   153,    -1,   154,    -1,   150,    -1,    92,    -1,
     149,    -1,   292,    -1,   291,   237,   292,    -1,   275,    39,
     276,    -1,   276,    -1,   275,   145,   275,   234,    -1,    -1,
     157,   177,    50,   295,   296,    51,    -1,    -1,   297,    -1,
     298,    -1,   297,    57,   298,    -1,   299,    -1,   302,    -1,
     299,   122,   299,    -1,   299,   121,   299,    -1,    -1,   301,
      -1,   299,    -1,   301,    57,   299,    -1,    55,   299,    -1,
      54,   299,    -1,   304,    -1,   125,   299,    -1,    50,   299,
      51,    -1,   303,    50,   300,    51,    -1,   167,   151,   244,
      -1,   299,   120,   299,    -1,   299,     8,   299,    -1,   299,
       9,   299,    -1,   299,    52,   299,    -1,   299,    54,   299,
      -1,   299,    55,   299,    -1,   299,    53,   299,    -1,   299,
      71,   299,    -1,   299,   125,    71,   299,    -1,   299,    45,
     299,    -1,   299,   129,    -1,   299,   130,    -1,   299,   126,
     299,   122,   299,    -1,   299,   127,    50,   305,    51,    -1,
     299,   125,   127,    50,   305,    51,    -1,   177,    -1,   244,
      -1,    29,    -1,    46,    -1,   128,    -1,    41,    -1,   304,
      -1,   305,    57,   304,    -1,    18,    -1,    20,    -1,    21,
      -1,    22,    -1,    25,    -1,    19,    -1,    27,    -1,    33,
      -1,    35,    -1,    36,    -1,    41,    -1,    42,    -1,    43,
      -1,    48,    -1,    49,    -1,    56,    -1,    58,    -1,    59,
      -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,    99,
      -1,   100,    -1,   101,    -1,   102,    -1,   103,    -1,   104,
      -1,   105,    -1,   106,    -1,   107,    -1,   108,    -1,   109,
      -1,   110,    -1,   111,    -1,   112,    -1,   113,    -1,   114,
      -1,   115,    -1,   116,    -1,   117,    -1,   118,    -1,   120,
      -1,     8,    -1,     9,    -1,   121,    -1,   122,    -1,   124,
      -1,   125,    -1,   126,    -1,   127,    -1,   128,    -1,   129,
      -1,   130,    -1,   131,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,   139,
      -1,   140,    -1,   141,    -1,   142,    -1,   145,    -1,   146,
      -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,   151,
      -1,   152,    -1,   153,    -1,   154,    -1,   155,    -1,   156,
      -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,   161,
      -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,   166,
      -1,   167,    -1,   168,    -1,   169,    -1,   170,    -1,   172,
      -1,    18,    -1,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    25,    -1,    33,    -1,    34,    -1,    35,    -1,    36,
      -1,    40,    -1,    42,    -1,    43,    -1,    48,    -1,    49,
      -1,    56,    -1,    58,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,
      -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    97,    -1,    98,    -1,    99,    -1,   100,    -1,   101,
      -1,   102,    -1,   103,    -1,   104,    -1,   105,    -1,   106,
      -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,    -1,   116,    -1,   117,
      -1,   118,    -1,   120,    -1,     8,    -1,     9,    -1,   121,
      -1,   122,    -1,   124,    -1,   125,    -1,   126,    -1,   127,
      -1,   129,    -1,   130,    -1,   131,    -1,   132,    -1,   133,
      -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,
      -1,   139,    -1,   140,    -1,   142,    -1,   145,    -1,   146,
      -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,   151,
      -1,   152,    -1,   153,    -1,   154,    -1,   155,    -1,   156,
      -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,   162,
      -1,   163,    -1,   164,    -1,   165,    -1,   166,    -1,   167,
      -1,   168,    -1,   169,    -1,   170,    -1,   172,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   145,   146,   151,   152,   161,   162,   166,
     167,   171,   172,   173,   174,   177,   177,   180,   180,   193,
     193,   212,   214,   217,   212,   222,   222,   227,   228,   229,
     241,   242,   247,   248,   251,   266,   278,   279,   290,   301,
     314,   326,   337,   342,   345,   353,   354,   360,   359,   381,
     384,   384,   402,   403,   406,   407,   408,   411,   420,   421,
     424,   425,   426,   428,   429,   430,   436,   440,   440,   444,
     444,   454,   455,   456,   460,   464,   460,   519,   520,   524,
     532,   533,   536,   537,   540,   543,   548,   557,   569,   581,
     588,   596,   603,   616,   625,   634,   641,   643,   646,   652,
     653,   654,   655,   658,   659,   663,   664,   668,   668,   671,
     672,   692,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   724,   725,
     726,   730,   736,   737,   738,   742,   743,   747,   748,   749,
     750,   751,   752,   753,   754,   756,   770,   771,   772,   773,
     774,   775,   776,   780,   781,   784,   784,   786,   786,   789,
     799,   805,   805,   808,   809,   810,   814,   814,   816,   816,
     819,   819,   821,   824,   830,   833,   837,   838,   842,   844,
     846,   848,   850,   855,   855,   859,   862,   866,   866,   869,
     869,   873,   874,   887,   895,   895,   904,   908,   912,   916,
     920,   924,   928,   934,   938,   942,   946,   950,   954,   958,
     961,   968,   968,   973,   973,   973,   978,   985,   986,   987,
     988,   989,   990,   991,   992,   996,  1000,  1006,  1009,  1010,
    1013,  1014,  1021,  1023,  1028,  1036,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1051,  1053,  1054,  1057,  1060,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1076,  1078,  1085,  1085,  1091,
    1097,  1098,  1101,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1122,  1129,  1130,  1131,
    1136,  1139,  1143,  1155,  1158,  1159,  1163,  1173,  1180,  1189,
    1192,  1200,  1203,  1207,  1214,  1222,  1227,  1235,  1239,  1244,
    1249,  1254,  1259,  1264,  1273,  1282,  1283,  1288,  1291,  1299,
    1305,  1311,  1317,  1326,  1331,  1341,  1351,  1357,  1363,  1369,
    1379,  1391,  1399,  1411,  1419,  1420,  1421,  1425,  1426,  1427,
    1428,  1429,  1430,  1431,  1434,  1441,  1452,  1456,  1463,  1471,
    1471,  1487,  1488,  1494,  1500,  1508,  1515,  1516,  1517,  1522,
    1523,  1526,  1527,  1531,  1533,  1534,  1535,  1536,  1537,  1538,
    1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,
    1549,  1550,  1551,  1552,  1553,  1556,  1559,  1560,  1561,  1562,
    1563,  1566,  1570,  1581,  1583,  1584,  1585,  1586,  1587,  1589,
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
    1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,
    1710,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,
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
    1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,
    1836,  1837,  1838,  1839,  1840
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_OR", "KW_AND", "KW_NOT",
  "IS_NOT_NULL", "IS_NULL", "LESSTHAN", "GREATERTHAN", "KW_PLUS",
  "KW_MINUS", "KW_MULTIPLY", "KW_DIVIDE", "KW_MOD", "KW_POWER", "CH",
  "GRAPH_CH", "KW_COMPOSITES", "INSTRUCTIONS", "ATTRIBUTES", "DATABASE",
  "BY", "KW_SCREEN_TITLE", "KW_SCREEN", "KW_SIZE", "OPEN_SQUARE", "KW_END",
  "CLOSE_SQUARE", "NUMBER_VALUE", "NAMED", "OPEN_BRACE", "CLOSE_BRACE",
  "TITLE", "FORMONLY", "COMMENT", "DYNAMIC", "COLON", "ATSIGN", "DOT",
  "WITHOUT", "KW_NULL", "INPUT", "TABLES", "PIPE", "EQUAL", "CHAR_VALUE",
  "SEMICOLON", "LOOKUP", "JOINING", "OPEN_BRACKET", "CLOSE_BRACKET",
  "STAR", "DIVIDE", "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", "TYPE",
  "DELIMITERS", "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", "SMALLFLOAT",
  "SMALLINT", "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", "LIKE",
  "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", "YELLOW",
  "NORMAL", "REVERSE", "LEFT", "BOLD", "BLINK", "UNDERLINE", "DIM",
  "AUTONEXT", "COLOR", "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY",
  "DOWNSHIFT", "UPSHIFT", "FORMAT", "INCLUDE", "INVISIBLE", "NOUPDATE",
  "NOENTRY", "PICTURE", "PROGRAM", "REQUIRED", "QUERYCLEAR", "VERIFY",
  "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO", "AS", "SERIAL", "KW_BYTE",
  "KW_TEXT", "VARCHAR", "SQL_VAR", "KW_NONSPACE", "SQLONLY", "WIDGET",
  "CONFIG", "KW_NL", "COMPARISON", "KWOR", "KWAND", "KWAND1", "KWWHERE",
  "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", "KWNOTNULLCHK",
  "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", "FRACTION",
  "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY", "ALLOWING", "KW_WS",
  "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", "KW_EDITADD",
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
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   173,   174,   175,   175,   175,   175,   176,   176,   177,
     177,   178,   178,   178,   178,   179,   179,   181,   180,   182,
     180,   184,   185,   186,   183,   187,   187,   188,   188,   188,
     189,   189,   190,   190,   191,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   193,   193,   195,   194,   196,
     197,   196,   198,   198,   199,   199,   199,   200,   201,   201,
     202,   202,   202,   202,   202,   202,   203,   204,   204,   206,
     205,   207,   207,   207,   209,   210,   208,   211,   211,   211,
     212,   212,   213,   213,   213,   213,   214,   214,   214,   214,
     214,   214,   214,   215,   215,   216,   217,   218,   218,   219,
     219,   219,   219,   220,   220,   221,   221,   222,   222,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   224,   224,   224,   225,   225,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   227,   227,   228,   228,   229,   229,   230,
     230,   231,   230,   230,   230,   230,   232,   232,   233,   233,
     234,   234,   235,   235,   236,   236,   237,   237,   238,   238,
     238,   238,   238,   239,   239,   240,   240,   241,   241,   242,
     242,   243,   243,   244,   246,   245,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   248,   248,   249,   249,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   251,   251,   251,
     252,   252,   253,   253,   254,   255,   256,   256,   256,   256,
     256,   256,   256,   257,   258,   258,   259,   260,   261,   261,
     261,   261,   261,   261,   261,   262,   262,   263,   263,   264,
     265,   265,   265,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   267,   267,   267,   267,
     268,   269,   269,   270,   271,   271,   272,   273,   273,   274,
     274,   275,   276,   277,   277,   277,   277,   278,   278,   278,
     278,   278,   278,   278,   279,   280,   280,   281,   282,   283,
     283,   283,   283,   284,   285,   285,   286,   286,   286,   286,
     287,   287,   288,   288,   289,   289,   289,   290,   290,   290,
     290,   290,   290,   290,   291,   291,   292,   292,   293,   295,
     294,   296,   296,   297,   297,   298,   299,   299,   299,   300,
     300,   301,   301,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   304,   304,   304,   304,
     304,   305,   305,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307
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
       2,     2,     5,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,   471,   472,   393,   398,   394,   395,
     396,   397,   399,     7,   400,     3,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,    11,   520,    13,     6,     8,     1,     0,
      17,    52,    15,     0,     0,     0,     0,    19,    27,     0,
      16,     0,     0,   598,   599,   521,   522,   523,   524,   525,
     526,     9,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,    12,    10,
      14,     0,    27,     0,    18,    21,    58,    30,    54,     0,
     163,     5,     4,    20,    28,    25,     0,    57,    31,     0,
      53,    55,   203,    30,    67,    69,     0,     2,     0,    26,
       0,     0,    60,    59,    56,    66,    68,     0,   521,   525,
     539,   617,   620,   621,   629,   630,   301,    30,   165,   167,
     174,     0,   170,   175,    29,    22,     0,     0,     0,     0,
      74,     0,    71,     0,   293,   294,   171,   169,     0,   334,
     335,   336,     0,   330,   342,   337,   343,   341,   338,   339,
     340,     0,   332,     0,   306,   305,   164,   166,   168,     0,
       0,    65,    61,    62,    64,     0,    70,    72,   471,   472,
     393,   395,   396,   397,     7,   400,   401,   402,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     467,   468,   469,   470,   473,   474,   475,   476,   477,   478,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   302,
       0,   297,     0,   300,   295,     0,     0,     0,   331,     0,
     333,     0,   180,    45,    38,    47,    39,    40,    44,    43,
      42,    37,    34,     0,    35,    32,    41,    36,     0,   528,
       0,    82,    90,    77,    73,   178,     0,     0,   182,     0,
       0,     0,   347,   186,   344,   186,   349,   181,   348,   197,
      23,    33,    46,    63,     0,    92,     0,     0,    87,    81,
       0,     0,    75,   179,     0,   298,   299,     0,     0,     0,
       0,   187,     0,   317,     0,     0,     0,     0,     0,   324,
     309,   307,   310,   311,   313,   303,   308,   312,   304,   351,
     201,   202,     0,     0,   198,   199,    49,    30,   196,   195,
      82,     0,   206,   207,   208,   209,   210,   211,   237,   237,
     254,   240,     0,   216,   217,   218,   219,   220,    85,    82,
       0,    89,     0,   105,     0,     0,   528,   188,   186,   193,
     184,     0,   346,   326,     0,     0,     0,     0,   321,   319,
     387,   390,   388,     0,     0,     0,   603,   389,   640,   203,
     386,     0,   356,     0,   365,     0,   345,   325,     0,   352,
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
       0,   329,   318,   367,   369,   371,   372,   379,   373,   376,
     374,   375,   377,   370,   358,   357,     0,     0,     0,     0,
     315,   361,     0,   360,   354,    51,   205,   238,     0,   244,
       0,   255,   257,   253,   241,     0,    83,    79,     0,     0,
      93,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   141,     0,     0,     0,     0,   177,   172,
       0,   378,     0,     0,   391,     0,     0,   314,   368,     0,
       0,   266,   243,     0,   103,     0,     0,     0,   155,   147,
     148,   149,   150,   151,   152,   153,   154,   158,   156,   159,
     160,   161,   162,   157,   267,   145,   112,   143,   142,   144,
     113,   116,   114,   120,     0,   131,   132,   122,   123,   124,
     108,     0,     0,   382,   383,     0,   316,   362,   239,   126,
     104,    94,     0,   100,   111,    98,    95,     0,   146,   110,
     268,     0,     0,   230,   223,   227,   236,   226,     0,     0,
       0,   231,   221,     0,   384,   392,   102,     0,     0,   287,
     290,   288,     0,     0,   289,   269,   270,   281,   286,   117,
     115,     0,     0,     0,     0,   224,   225,   121,     0,     0,
       0,   173,     0,    99,    97,     0,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,   280,   229,
     228,   235,   234,   222,   233,   232,   101,   285,   272,   271,
     274,   275,   278,   276,   273,     0,     0,     0,   277,     0,
     291,     0,   282,   283,     0,   292
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   499,   649,   136,   141,   142,   148,   282,
     284,   295,   370,   597,   310,   285,   300,   523,   524,   525,
     526,   527,   549,   592,   739,   151,   287,   288,   297,   313,
     290,   303,   304,   317,   341,   342,   375,   623,   562,   558,
     559,   533,   829,   830,   831,   916,   914,   866,   698,   779,
     780,   890,   884,   885,   307,   327,   328,   329,   505,   787,
     564,   548,   539,   628,   578,   629,   630,   600,   593,   594,
     595,   650,   596,   740,   618,   930,   931,   932,   670,   689,
     748,   820,   690,   691,   824,   679,   680,   821,   681,   743,
     919,   920,   945,   946,   947,   948,  1001,   330,   344,   345,
     500,   501,   502,   503,   332,   579,   580,   857,   581,   582,
     583,   584,   585,   586,   352,   361,   353,   362,   543,   544,
     333,   587,   589,   658,   659,   660,   661,   812,   813,   652,
     653,   654,   855,   137,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -910
static const yytype_int16 yypact[] =
{
      34,  1425,    72,    19,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,    54,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,    61,  -910,    65,   111,  -910,  -910,   117,
    -910,    27,  -910,   134,  3735,  3735,   136,  -910,   162,  3735,
    -910,   176,   156,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,   158,   162,   186,  -910,  -910,   160,  1920,  -910,  3735,
     199,  -910,  -910,  -910,   198,    53,  2415,  -910,  -910,  3735,
    -910,  -910,  -910,  2580,  -910,  -910,  3900,  -910,   195,  -910,
     201,   204,   191,  -910,  -910,  -910,  -910,   205,   241,   200,
     211,   209,  -111,   206,   103,   103,  -910,  2745,  -910,   214,
    -910,   118,  -910,  -910,  -910,  -910,  3735,  3735,  3735,  3735,
    -910,    82,  -910,  1095,   241,  -910,  -910,  -910,   233,  -910,
    -910,  -910,    91,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,   177,  -910,  3735,  -910,  -910,  -910,  -910,  -910,  3735,
     930,  -910,  -910,   234,  -910,  2085,   205,  -910,   231,   235,
     238,   239,   242,   243,   244,   247,   248,   249,   253,   254,
     255,   256,   258,   261,   262,   267,   271,   277,   282,   285,
     293,   297,   298,   302,   309,   318,   323,   325,   328,   329,
     330,   331,   335,   338,   339,   341,   342,   343,   344,   346,
     348,   349,   350,   351,   352,   354,   370,   372,   373,   375,
     376,   378,   379,   381,   382,   384,   386,   394,   405,   411,
     412,   414,   415,   416,   417,   419,   420,   423,   424,   425,
     426,   427,   448,   450,   451,   453,   458,   459,   463,   466,
     467,   468,   470,   472,   474,   475,   476,   477,   483,   484,
     500,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     520,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   535,   536,   537,   538,   539,   540,   542,  -910,
      11,  -910,   543,  -910,  -910,  3735,   215,  1095,  -910,  1095,
    -910,   223,   366,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,   765,  -910,  -910,   264,  -910,  3735,   544,
    3735,   -49,   545,   259,  -910,   396,  1095,  1590,   319,   441,
     556,   547,  -910,   187,  -910,   187,  -910,  -910,  -910,   -69,
    -910,  -910,  -910,  -910,  2910,   548,   408,   546,  -910,   464,
    3735,   561,  -910,  -910,   583,  -910,  -910,   563,  4065,   549,
    1590,  -910,   -34,  -910,  3735,  2250,  1260,   -80,  1095,  -910,
    -910,  -910,  -910,  -910,  -910,   -80,  -910,  -910,   -80,  1260,
    -910,  -910,    57,  3735,   -69,  -910,  -910,   566,  -910,  -910,
     550,  3735,  -910,  -910,  -910,  -910,  -910,  -910,   551,   551,
     306,   409,  3735,  -910,  -910,  -910,  -910,  -910,  -910,   550,
     553,  -910,     3,   541,  1095,   567,   557,   558,   -16,   552,
    -910,   491,  -910,  -910,   560,   -27,   559,  3075,  -910,  -910,
    -910,  -910,  -910,  1260,  1260,  1260,  1260,  -910,   456,   562,
    -910,    87,  -910,   564,  -910,   -13,  -910,  -910,   565,   554,
    -910,   193,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   573,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   568,  -910,
     495,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   568,  -910,
     505,   569,   576,  -910,  -910,  -910,   588,    17,  -910,    14,
    -910,  3240,  3405,   518,  4065,  4065,   570,  -910,  -910,   575,
    1260,  -910,  -910,   182,   193,   193,   193,  3735,  1260,  1260,
    1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,  1260,   -64,
    1260,   572,  -910,  -910,   -80,  1260,  -910,  -910,  1260,   -69,
     -69,    74,   594,  -910,   306,  -910,   409,   595,  -910,  3735,
     597,   601,  3735,  -910,  -910,   584,   585,   586,   571,   574,
    -910,  -910,   587,   589,  -910,  -910,  -910,   590,   591,  -910,
    -910,  -910,    30,  -910,   592,   593,  -910,  -910,   596,   582,
    -910,  -910,  -910,  -910,  -910,  -910,   490,   366,  -910,  -910,
     604,  -910,   193,  -910,  -910,   374,   374,   193,   193,   193,
     193,   193,   193,   193,   193,   193,  1260,   598,   213,  1755,
     478,   193,   599,   600,  -910,  -910,  -910,  -910,   611,  -910,
     602,  -910,  -910,  -910,  -910,   603,  -910,  -910,   606,    24,
    -910,   607,  -910,   452,   609,   -14,  3735,  3735,   610,   608,
     613,   614,  -910,  -910,   615,   616,  3735,    17,  -910,  -910,
     612,   193,  1755,  1260,  -910,    97,   -80,  -910,  -910,  1260,
     617,  -910,  -910,   618,  -910,  4230,  3570,  3735,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,   322,  -910,  -910,  -910,  -910,  -910,
    -910,   605,   624,  -910,   406,  -910,  -910,  -910,  -910,  -910,
    -910,   620,   127,   193,  -910,  1755,  -910,   193,  -910,  -910,
     619,  -910,  3735,   627,  -910,   628,  -910,    -2,  -910,  -910,
    -910,  3735,  3735,  -910,  -910,   -24,  -910,   -21,   641,   642,
     131,   -20,  -910,   621,  -910,  -910,   634,  3735,  3735,  -910,
    -910,  -910,    -2,    -2,  -910,  -910,    39,   246,  -910,  -910,
    -910,   644,   645,   630,   631,  -910,  -910,  -910,   406,     7,
       7,  -910,  3735,  -910,  -910,   629,  -910,    -2,    -2,     0,
       0,     0,     0,     0,   623,     0,   632,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,     0,   577,     0,  -910,     0,
    -910,   146,  -910,  -910,     0,  -910
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -910,  -910,  -910,   677,  -144,  -910,  -910,   555,  -910,  -910,
     364,  -910,  -910,  -910,  -910,  -910,  -301,  -910,  -910,   161,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -247,  -910,  -910,
    -910,  -910,   380,  -910,  -910,  -320,  -910,  -910,  -910,  -555,
    -910,  -910,  -910,  -186,  -910,  -910,  -910,  -910,  -910,  -910,
    -166,  -910,  -910,  -199,  -910,  -910,   359,  -910,  -910,  -910,
    -910,  -100,  -910,  -910,    60,   -15,    -9,  -910,   -51,  -910,
     104,  -285,   -48,  -910,  -910,  -910,  -780,  -261,    92,  -910,
    -910,  -910,  -910,   -46,  -910,  -910,  -910,  -910,   -41,    16,
    -910,  -910,  -910,  -909,  -487,  -910,  -910,  -910,  -910,   361,
      83,   170,  -303,  -440,  -910,  -577,  -910,  -910,  -910,  -910,
    -910,  -910,  -520,  -910,  -910,  -910,   357,   353,   202,   132,
    -910,  -114,  -910,  -910,  -910,   -26,  -554,  -910,  -910,  -910,
    -910,  -803,  -139,  -910,  -910
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -645
static const yytype_int16 yytable[] =
{
     278,   280,   315,   331,   305,   286,   854,   806,   657,   572,
     556,   657,   633,   951,   736,   887,   953,   959,   305,   708,
     535,   377,   651,   781,   331,   588,   366,   939,   940,   939,
     940,   695,   888,   965,   966,   703,   924,   349,   350,   351,
     301,   571,   139,   140,   941,   667,   941,   634,   942,   854,
     139,   140,   314,   751,   709,     1,   534,   655,   988,   989,
     696,   928,   929,   807,   693,   752,   512,   542,   536,   542,
     149,   536,   138,   864,   590,   591,   572,   363,   657,   573,
     574,   865,   575,   576,   952,   662,   577,   954,   960,   713,
     714,   715,   716,   557,   143,   718,   719,   566,   753,   144,
     889,   663,   935,   145,   754,   755,   756,   757,   758,   759,
     760,   761,   762,   763,   764,   765,   766,   767,   768,   769,
     770,   771,   772,   943,   635,   817,   944,   340,   944,   376,
     632,   818,   720,   773,   774,   775,   842,   843,   542,   721,
     722,   723,   724,   286,   363,   302,   573,   574,   904,   575,
     576,   146,   312,   577,   905,   286,   792,   810,   725,   302,
     967,   968,   326,   147,   795,   796,   797,   798,   799,   800,
     801,   802,   803,   804,   805,   152,   808,   281,   934,   984,
     985,   811,   957,   326,   905,   776,   777,   283,   958,   778,
     718,   719,   371,   372,   373,   374,   289,  1003,   291,   326,
     292,   718,   719,  1004,   541,   296,   541,   726,   727,   728,
     364,   365,   729,   730,   731,   294,   732,   733,   306,   511,
     308,   718,   719,   309,   334,   326,   522,   720,   337,   338,
     339,   532,   335,   793,   721,   722,   723,   724,   720,   349,
     350,   351,   507,   336,   571,   721,   722,   723,   724,   343,
     340,   734,   851,   725,   969,   970,   346,   347,   720,   348,
     363,   368,   506,   369,   725,   721,   722,   723,   724,   354,
    -598,   528,   540,   546,  -599,   541,   572,  -521,  -522,   906,
     552,  -523,  -526,    -9,   725,   561,  -527,  -529,  -530,   636,
     639,   971,  -532,  -533,  -534,  -535,   666,  -536,   354,   903,
    -537,  -538,   726,   727,   728,   907,  -539,   729,   730,   731,
    -540,   732,   733,   726,   727,   728,  -541,   972,   729,   730,
     731,  -542,   732,   733,  -543,   355,   356,   357,   509,   358,
     359,   360,  -544,   726,   727,   853,  -545,  -546,   729,   730,
     731,  -547,   732,   733,   363,   567,   573,   574,  -548,   575,
     576,   868,   712,   577,   355,   356,   357,  -549,   358,   359,
     360,   538,  -550,   326,  -551,   326,   973,  -552,  -553,  -554,
    -555,   974,   975,   976,  -556,   977,   978,  -557,  -558,   522,
    -559,  -560,  -561,  -562,   553,  -563,   555,  -564,  -565,  -566,
    -567,  -568,   326,  -569,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   883,  -570,
     599,  -571,  -572,   547,  -573,  -574,   621,  -575,  -576,   720,
    -577,  -578,   923,  -579,   627,  -580,   721,   722,   723,   724,
     302,   302,   794,  -581,   326,   924,   925,   672,   673,   674,
     675,   676,   677,   678,  -582,   725,   917,   926,   563,   664,
    -583,  -584,   927,  -585,  -586,  -587,  -588,   668,  -589,  -590,
     928,   929,  -591,  -592,  -593,  -594,  -595,   832,   692,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     326,   868,   990,   991,   992,   993,   994,  -596,   996,  -597,
    -600,   568,  -601,   302,   726,   727,   728,  -602,  -603,   729,
     730,   731,  -604,   732,   733,  -605,  -606,  -607,   998,  -608,
    1000,  -609,  1002,  -610,  -611,  -612,  -613,  1005,   613,   614,
     615,   616,  -614,  -615,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   883,  -616,
     682,   683,   684,   685,   686,   687,   688,   617,  -617,  -618,
    -619,  -620,  -621,  -622,  -623,  -624,  -625,   783,   785,  -626,
     627,   627,  -627,  -628,  -629,  -630,  -631,  -632,  -633,  -634,
    -635,  -636,  -637,   302,  -638,  -639,  -640,  -641,  -642,  -643,
     832,  -644,   537,   554,   560,   569,   570,   601,   619,   620,
     622,   624,   625,   298,   694,   700,   701,   702,   697,   706,
     631,   669,   741,   744,   710,   826,   707,   717,   302,   556,
     705,   738,  -385,   746,   735,   749,   737,   750,   742,   747,
     790,   791,   809,   819,   825,   827,   828,   786,   848,   833,
     834,   835,   838,   850,   839,   840,   841,   844,   845,   847,
     860,   846,   836,   856,   921,   837,   293,   909,   852,   933,
     858,   863,   867,   861,   862,   886,   893,   859,   894,   895,
     896,   897,   898,   922,  -535,   302,   937,   938,   908,   901,
     955,   956,   961,   962,   979,   980,   981,   982,   135,   911,
     987,   900,   997,   316,   551,   918,   367,   849,   704,   816,
     789,   815,   891,   892,   995,   788,   150,   983,   665,   999,
     823,   671,   899,   822,   745,   504,   565,   699,   302,   508,
     656,   545,   814,   902,   510,     0,     0,     0,     0,     0,
       0,   302,   913,   915,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,     0,     0,     0,     0,     0,   936,     0,
       0,     0,     0,   153,   154,     0,     0,   949,   950,     0,
       0,   513,   514,   155,     0,     0,   156,   157,   158,   159,
     160,   515,     0,   963,   964,   161,     0,   550,   162,   163,
     164,   165,     0,     0,     0,   166,     0,   167,   168,   516,
       0,   517,     0,   169,   170,     0,     0,     0,   986,     0,
       0,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     518,   229,   230,   231,   519,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,   520,   521,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,   513,   514,   155,     0,
       0,   156,   157,   158,   159,   160,   515,     0,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,   516,     0,   517,     0,   169,   170,
       0,     0,     0,     0,     0,     0,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   518,   229,   230,   231,   519,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,   520,   521,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277,   378,   379,     0,     0,     0,     0,     0,
       0,     0,     0,   380,     7,     8,   381,   382,   158,   159,
     383,     0,    12,     0,     0,   384,     0,     0,   385,   163,
     386,   387,     0,     0,     0,   166,    18,   388,   389,     0,
       0,     0,     0,   390,   391,     0,     0,     0,     0,     0,
       0,   392,     0,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
      81,   450,   451,   452,     0,   453,   454,   455,     0,   456,
     457,   458,   459,    92,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   105,   472,     0,     0,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   123,   489,   490,   491,
     492,   493,   494,   495,   496,   497,     0,   498,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,     0,     0,   640,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,   641,   167,   168,     0,     0,   642,     0,   169,   170,
     643,     0,     0,     0,   644,   645,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   646,   237,   238,   647,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   648,   274,   275,
     276,     0,   277,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     8,     9,    10,     0,     0,
      11,     0,    12,     0,     0,    13,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,    18,    19,    20,     0,
       0,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,    23,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,    86,    87,     0,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,     0,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,     0,     0,    11,     0,    12,     0,     0,
      13,     0,     0,    14,     0,    16,    17,     0,     0,     0,
       0,    18,    19,    20,     0,     0,     0,     0,    21,    22,
       0,     0,     0,     0,     0,     0,    23,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,    86,    87,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,     0,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,     0,   134,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
     160,     0,     0,     0,   640,   161,     0,     0,   162,   163,
     164,   165,     0,     0,     0,   166,   641,   167,   168,     0,
       0,   642,     0,   169,   170,     0,     0,     0,     0,     0,
       0,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,   229,   230,   231,     0,   232,   233,   234,     0,   235,
     236,   237,   238,   647,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,     0,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,   298,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,   171,   299,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   161,     0,     0,   162,   529,
     164,   165,     0,     0,     0,   166,     0,   167,   168,     0,
       0,     0,     0,   169,   170,     0,     0,   530,     0,     0,
       0,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,   229,   230,   231,     0,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   531,   251,     0,     0,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,     0,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,   637,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   638,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   161,     0,     0,   162,   163,
     164,   165,     0,     0,     0,   166,     0,   167,   168,     0,
       0,   311,     0,   169,   170,     0,     0,     0,     0,     0,
       0,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,   229,   230,   231,     0,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,     0,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,   298,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   318,     0,     0,   156,   157,   158,   319,
     160,     0,   298,     0,     0,   161,     0,     0,   162,   163,
     164,   165,     0,     0,     0,   166,     0,   167,   168,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,   171,     0,   172,   173,   320,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,   229,   230,   231,     0,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   321,     0,   251,     0,     0,
     252,   322,   323,   255,   256,   257,   258,   259,   260,   261,
     324,   325,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,   598,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   161,     0,     0,   162,   163,
     164,   165,     0,     0,     0,   166,     0,   167,   168,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,   229,   230,   231,     0,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,     0,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   711,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,     0,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,     0,     0,   169,   170,
       0,     0,   782,     0,     0,     0,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   161,     0,     0,   162,   163,
     164,   165,     0,     0,     0,   166,     0,   167,   168,     0,
       0,     0,     0,   169,   170,     0,     0,   784,     0,     0,
       0,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,   229,   230,   231,     0,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,     0,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,     0,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,     0,     0,   169,   170,
       0,     0,   912,     0,     0,     0,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   161,     0,     0,   162,   163,
     164,   165,     0,     0,     0,   166,     0,   167,   168,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,   229,   230,   231,     0,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,     0,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   318,     0,
       0,   156,   157,   158,   319,   160,     0,     0,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,   171,     0,   172,   173,
     320,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     321,     0,   251,     0,     0,   252,   322,   323,   255,   256,
     257,   258,   259,   260,   261,   324,   325,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   161,     0,     0,   162,   626,
     164,   165,     0,     0,     0,   166,     0,   167,   168,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,     0,
       0,   171,     0,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
       0,   229,   230,   231,     0,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,     0,     0,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,     0,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,     0,     0,   169,   910,
       0,     0,     0,     0,     0,     0,   171,     0,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,     0,   235,   236,   237,   238,     0,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,     0,   277
};

static const yytype_int16 yycheck[] =
{
     144,   145,   303,   306,   289,   149,   809,    71,   585,    89,
      59,   588,    46,    37,    27,    29,    37,    37,   303,    46,
       9,   341,   576,     9,   327,   545,   327,    29,    30,    29,
      30,    28,    46,   942,   943,    51,    29,   148,   149,   150,
     287,    57,    23,    24,    46,   600,    46,    81,    50,   852,
      23,    24,   299,    36,    81,    21,   376,   577,   967,   968,
      57,    54,    55,   127,   619,    48,   369,   507,    57,   509,
      43,    57,     0,    49,   143,   144,    89,   157,   655,   159,
     160,    57,   162,   163,   108,    28,   166,   108,   108,   643,
     644,   645,   646,   142,    40,     8,     9,   537,    81,    38,
     114,    44,   905,    38,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   125,   158,    51,   128,    45,   128,    47,
     570,    57,    45,   116,   117,   118,   106,   107,   578,    52,
      53,    54,    55,   287,   157,   289,   159,   160,    51,   162,
     163,    40,   296,   166,    57,   299,   710,   734,    71,   303,
     121,   122,   306,    46,   718,   719,   720,   721,   722,   723,
     724,   725,   726,   727,   728,    41,   730,    41,    51,   959,
     960,   735,    51,   327,    57,   168,   169,    25,    57,   172,
       8,     9,   336,   337,   338,   339,    20,    51,    42,   343,
      42,     8,     9,    57,   507,    45,   509,   120,   121,   122,
     324,   325,   125,   126,   127,    29,   129,   130,    19,   363,
      22,     8,     9,   170,    29,   369,   370,    45,    37,    38,
      39,   375,    31,    51,    52,    53,    54,    55,    45,   148,
     149,   150,   151,    39,    57,    52,    53,    54,    55,     8,
      45,   164,   806,    71,     8,     9,    56,    46,    45,    50,
     157,    47,    29,   145,    71,    52,    53,    54,    55,    92,
      39,    37,    57,    50,    39,   578,    89,    39,    39,   856,
      16,    39,    39,    39,    71,    26,    39,    39,    39,   574,
     575,    45,    39,    39,    39,    39,   597,    39,    92,   853,
      39,    39,   120,   121,   122,   859,    39,   125,   126,   127,
      39,   129,   130,   120,   121,   122,    39,    71,   125,   126,
     127,    39,   129,   130,    39,   148,   149,   150,   151,   152,
     153,   154,    39,   120,   121,   122,    39,    39,   125,   126,
     127,    39,   129,   130,   157,    26,   159,   160,    39,   162,
     163,    29,   637,   166,   148,   149,   150,    39,   152,   153,
     154,   505,    39,   507,    39,   509,   120,    39,    39,    39,
      39,   125,   126,   127,    39,   129,   130,    39,    39,   523,
      39,    39,    39,    39,   528,    39,   530,    39,    39,    39,
      39,    39,   536,    39,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    39,
     554,    39,    39,    47,    39,    39,   560,    39,    39,    45,
      39,    39,    16,    39,   568,    39,    52,    53,    54,    55,
     574,   575,   717,    39,   578,    29,    30,   131,   132,   133,
     134,   135,   136,   137,    39,    71,   124,    41,    52,   593,
      39,    39,    46,    39,    39,    39,    39,   601,    39,    39,
      54,    55,    39,    39,    39,    39,    39,   752,   612,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     624,    29,   969,   970,   971,   972,   973,    39,   975,    39,
      39,    50,    39,   637,   120,   121,   122,    39,    39,   125,
     126,   127,    39,   129,   130,    39,    39,    39,   995,    39,
     997,    39,   999,    39,    39,    39,    39,  1004,   110,   111,
     112,   113,    39,    39,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    39,
     131,   132,   133,   134,   135,   136,   137,   139,    39,    39,
      39,    39,    39,    39,    39,    39,    39,   701,   702,    39,
     704,   705,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,   717,    39,    39,    39,    39,    39,    39,
     865,    39,    39,    39,    39,    29,    39,    39,    42,   125,
      29,     8,    29,    27,    41,    28,    39,    39,    57,   108,
      51,    50,    29,   108,    45,   749,    46,   151,   752,    59,
      58,    57,    50,   108,    50,    39,    51,    29,    50,    50,
      50,    46,    50,    29,    29,    28,    25,   109,   138,    45,
      45,    45,    45,    29,    45,    45,    45,    45,    45,    57,
      29,    45,    71,   165,    39,    71,   282,    29,    50,    29,
      51,    45,    45,    51,    51,    46,    46,    57,    50,    46,
      46,    46,    46,    39,    45,   809,    39,    39,    51,    57,
      29,    29,    51,    39,    30,    30,    46,    46,     1,   865,
      51,   847,    50,   303,   523,   884,   327,   787,   628,   740,
     705,   739,   836,   837,    71,   704,   141,   958,   594,   122,
     746,   609,   846,   744,   688,   344,   536,   624,   852,   352,
     578,   509,   738,   852,   361,    -1,    -1,    -1,    -1,    -1,
      -1,   865,   866,   867,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   905,    -1,    -1,    -1,    -1,    -1,    -1,   912,    -1,
      -1,    -1,    -1,     8,     9,    -1,    -1,   921,   922,    -1,
      -1,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    -1,   937,   938,    30,    -1,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    44,
      -1,    46,    -1,    48,    49,    -1,    -1,    -1,   962,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,    -1,    46,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    48,    49,
      50,    -1,    -1,    -1,    54,    55,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      25,    -1,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    42,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    52,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    45,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,
      -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    52,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    52,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   116,   117,   118,    -1,   120,   121,   122,    -1,   124,
     125,   126,   127,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,   142,    -1,    -1,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,   118,    -1,
     120,   121,   122,    -1,   124,   125,   126,   127,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,   142,    -1,    -1,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    -1,   172
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   174,   175,     8,     9,    18,    19,    20,    21,
      22,    25,    27,    30,    33,    34,    35,    36,    41,    42,
      43,    48,    49,    56,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   120,   121,   122,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   176,   178,   306,     0,    23,
      24,   179,   180,    40,    38,    38,    40,    46,   181,    43,
     180,   198,    41,     8,     9,    18,    21,    22,    23,    24,
      25,    30,    33,    34,    35,    36,    40,    42,    43,    48,
      49,    56,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   116,
     117,   118,   120,   121,   122,   124,   125,   126,   127,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   142,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   172,   177,   307,
     177,    41,   182,    25,   183,   188,   177,   199,   200,    20,
     203,    42,    42,   183,    29,   184,    45,   201,    27,    57,
     189,   200,   177,   204,   205,   244,    19,   227,    22,   170,
     187,    46,   177,   202,   200,   189,   205,   206,    18,    24,
      60,   140,   146,   147,   155,   156,   177,   228,   229,   230,
     270,   275,   277,   293,    29,    31,    39,    37,    38,    39,
      45,   207,   208,     8,   271,   272,    56,    46,    50,   148,
     149,   150,   287,   289,    92,   148,   149,   150,   152,   153,
     154,   288,   290,   157,   294,   294,   189,   229,    47,   145,
     185,   177,   177,   177,   177,   209,    47,   208,     8,     9,
      18,    21,    22,    25,    30,    33,    35,    36,    42,    43,
      48,    49,    56,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     116,   117,   118,   120,   121,   122,   124,   125,   126,   127,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   142,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   172,   176,
     273,   274,   275,   276,   272,   231,    29,   151,   289,   151,
     290,   177,   275,    16,    17,    26,    44,    46,   115,   119,
     143,   144,   177,   190,   191,   192,   193,   194,    37,    34,
      52,   141,   177,   214,   208,     9,    57,    39,   177,   235,
      57,   275,   276,   291,   292,   291,    50,    47,   234,   195,
      32,   192,    16,   177,    39,   177,    59,   142,   212,   213,
      39,    26,   211,    52,   233,   274,   276,    26,    50,    29,
      39,    57,    89,   159,   160,   162,   163,   166,   237,   278,
     279,   281,   282,   283,   284,   285,   286,   294,   285,   295,
     143,   144,   196,   241,   242,   243,   245,   186,    27,   177,
     240,    39,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,   110,   111,   112,   113,   139,   247,    42,
     125,   177,    29,   210,     8,    29,    34,   177,   236,   238,
     239,    51,   276,    46,    81,   158,   244,    45,   161,   244,
      29,    41,    46,    50,    54,    55,   125,   128,   167,   177,
     244,   299,   302,   303,   304,   285,   292,   278,   296,   297,
     298,   299,    28,    44,   177,   243,   189,   212,   177,    50,
     251,   251,   131,   132,   133,   134,   135,   136,   137,   258,
     259,   261,   131,   132,   133,   134,   135,   136,   137,   252,
     255,   256,   177,   212,    41,    28,    57,    57,   221,   273,
      28,    39,    39,    51,   237,    58,   108,    46,    46,    81,
      45,   161,   244,   299,   299,   299,   299,   151,     8,     9,
      45,    52,    53,    54,    55,    71,   120,   121,   122,   125,
     126,   127,   129,   130,   164,    50,    27,    51,    57,   197,
     246,    29,    50,   262,   108,   262,   108,    50,   253,    39,
      29,    36,    48,    81,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   116,   117,   118,   168,   169,   172,   222,
     223,     9,    52,   177,    52,   177,   109,   232,   239,   238,
      50,    46,   299,    51,   244,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,    71,   127,   299,    50,
     278,   299,   300,   301,   298,   245,   241,    51,    57,    29,
     254,   260,   261,   256,   257,    29,   177,    28,    25,   215,
     216,   217,   244,    45,    45,    45,    71,    71,    45,    45,
      45,    45,   106,   107,    45,    45,    45,    57,   138,   234,
      29,   299,    50,   122,   304,   305,   165,   280,    51,    57,
      29,    51,    51,    45,    49,    57,   220,    45,    29,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,   225,   226,    46,    29,    46,   114,
     224,   177,   177,    46,    50,    46,    46,    46,    46,   177,
     223,    57,   305,   299,    51,    57,   278,   299,    51,    29,
      49,   216,    52,   177,   219,   177,   218,   124,   226,   263,
     264,    39,    39,    16,    29,    30,    41,    46,    54,    55,
     248,   249,   250,    29,    51,   304,   177,    39,    39,    29,
      30,    46,    50,   125,   128,   265,   266,   267,   268,   177,
     177,    37,   108,    37,   108,    29,    29,    51,    57,    37,
     108,    51,    39,   177,   177,   266,   266,   121,   122,     8,
       9,    45,    71,   120,   125,   126,   127,   129,   130,    30,
      30,    46,    46,   250,   249,   249,   177,    51,   266,   266,
     267,   267,   267,   267,   267,    71,   267,    50,   267,   122,
     267,   269,   267,    51,    57,   267
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
#line 140 "screen.yacc"
    {
A4GL_check_compiled_form();
A4GL_write_form();}
    break;

  case 3:
#line 145 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:
#line 146 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 151 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 152 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 11:
#line 171 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:
#line 172 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:
#line 174 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 17:
#line 180 "screen.yacc"
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
#line 193 "screen.yacc"
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
#line 212 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 22:
#line 214 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 23:
#line 217 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 26:
#line 222 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 29:
#line 229 "screen.yacc"
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
#line 251 "screen.yacc"
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
#line 266 "screen.yacc"
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
#line 278 "screen.yacc"
    { ltab=0; }
    break;

  case 37:
#line 279 "screen.yacc"
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
#line 290 "screen.yacc"
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
#line 301 "screen.yacc"
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
#line 314 "screen.yacc"
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
#line 326 "screen.yacc"
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
#line 337 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 43:
#line 342 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 44:
#line 345 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 45:
#line 353 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 46:
#line 354 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 47:
#line 360 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 48:
#line 367 "screen.yacc"
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
#line 381 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 50:
#line 384 "screen.yacc"
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
#line 395 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 57:
#line 411 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 58:
#line 420 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 59:
#line 421 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 60:
#line 424 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 61:
#line 425 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 62:
#line 427 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 63:
#line 428 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 64:
#line 429 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 69:
#line 444 "screen.yacc"
    {
	A4GL_make_downshift((yyvsp[(1) - (1)].str));
	strcpy(currftag,(yyvsp[(1) - (1)].str));
	fldno=A4GL_find_field((yyvsp[(1) - (1)].str));
}
    break;

  case 74:
#line 460 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 75:
#line 464 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 76:
#line 472 "screen.yacc"
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
#line 520 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 79:
#line 524 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 80:
#line 532 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 81:
#line 533 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 82:
#line 536 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 83:
#line 537 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 84:
#line 540 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 85:
#line 543 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 86:
#line 548 "screen.yacc"
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
#line 557 "screen.yacc"
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
#line 569 "screen.yacc"
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
#line 581 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 90:
#line 588 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 91:
#line 596 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 92:
#line 603 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 93:
#line 616 "screen.yacc"
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
#line 625 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 95:
#line 634 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 97:
#line 643 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 98:
#line 646 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 99:
#line 652 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 100:
#line 653 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 101:
#line 654 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));}
    break;

  case 102:
#line 655 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(1) - (2)].str));}
    break;

  case 109:
#line 671 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 110:
#line 672 "screen.yacc"
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
#line 692 "screen.yacc"
    {
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 112:
#line 698 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 113:
#line 699 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 114:
#line 700 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 115:
#line 701 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 116:
#line 702 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 117:
#line 703 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 118:
#line 704 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 119:
#line 705 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 120:
#line 706 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 121:
#line 707 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 122:
#line 708 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 123:
#line 709 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 124:
#line 710 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 125:
#line 711 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 126:
#line 712 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 127:
#line 713 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 128:
#line 714 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 129:
#line 715 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 130:
#line 716 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 131:
#line 717 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 132:
#line 718 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 133:
#line 719 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REQUIRED); }
    break;

  case 134:
#line 720 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REVERSE); }
    break;

  case 135:
#line 721 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 136:
#line 722 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_QUERYCLEAR); }
    break;

  case 137:
#line 723 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_ZEROFILL); }
    break;

  case 138:
#line 724 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_RIGHT); }
    break;

  case 139:
#line 725 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WORDWRAP); }
    break;

  case 140:
#line 726 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 141:
#line 730 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 142:
#line 736 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 143:
#line 737 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 144:
#line 738 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 146:
#line 743 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 147:
#line 747 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 148:
#line 748 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 149:
#line 749 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 150:
#line 750 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 151:
#line 751 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 152:
#line 752 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 153:
#line 753 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 154:
#line 754 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 155:
#line 756 "screen.yacc"
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
#line 770 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 157:
#line 771 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 158:
#line 772 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 159:
#line 773 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 160:
#line 774 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 161:
#line 775 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 162:
#line 776 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 169:
#line 789 "screen.yacc"
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
#line 799 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 171:
#line 805 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 178:
#line 816 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 179:
#line 816 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 182:
#line 821 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 183:
#line 824 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 184:
#line 830 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 185:
#line 833 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 188:
#line 843 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),""); }
    break;

  case 189:
#line 845 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); }
    break;

  case 190:
#line 847 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); }
    break;

  case 191:
#line 849 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); }
    break;

  case 192:
#line 851 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 194:
#line 855 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 195:
#line 859 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 196:
#line 862 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 197:
#line 866 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 198:
#line 866 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 201:
#line 873 "screen.yacc"
    {colno++;}
    break;

  case 202:
#line 874 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 203:
#line 887 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 204:
#line 895 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 205:
#line 897 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 206:
#line 904 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 207:
#line 908 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 208:
#line 912 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 209:
#line 916 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 210:
#line 920 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 211:
#line 924 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 212:
#line 928 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 213:
#line 934 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 214:
#line 938 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 215:
#line 942 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 216:
#line 946 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 217:
#line 950 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 218:
#line 954 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 219:
#line 958 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 220:
#line 961 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 222:
#line 968 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 225:
#line 973 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 226:
#line 978 "screen.yacc"
    { 
	if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
		sprintf((yyval.str),"NULL");
	} else {
		strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
	}
}
    break;

  case 227:
#line 985 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 228:
#line 986 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 229:
#line 987 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 230:
#line 988 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 232:
#line 990 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 233:
#line 991 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 234:
#line 992 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 235:
#line 996 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 236:
#line 1000 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 237:
#line 1006 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 238:
#line 1009 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 239:
#line 1010 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 240:
#line 1013 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 241:
#line 1015 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 242:
#line 1021 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 243:
#line 1023 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 244:
#line 1028 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 245:
#line 1036 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 246:
#line 1039 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 247:
#line 1040 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 248:
#line 1041 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 249:
#line 1042 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 250:
#line 1043 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 251:
#line 1044 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 252:
#line 1046 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 254:
#line 1053 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 255:
#line 1054 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 256:
#line 1057 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 257:
#line 1060 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 258:
#line 1064 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 259:
#line 1065 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 260:
#line 1066 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 261:
#line 1067 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 262:
#line 1068 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 263:
#line 1069 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 264:
#line 1071 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 265:
#line 1076 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 266:
#line 1078 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 267:
#line 1085 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 268:
#line 1085 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 269:
#line 1091 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 271:
#line 1098 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 272:
#line 1101 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 273:
#line 1107 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 274:
#line 1108 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 275:
#line 1109 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 276:
#line 1110 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 277:
#line 1111 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 278:
#line 1112 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 279:
#line 1113 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 280:
#line 1114 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 281:
#line 1115 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 282:
#line 1116 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 283:
#line 1117 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 284:
#line 1118 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 285:
#line 1119 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 286:
#line 1122 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 287:
#line 1129 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 288:
#line 1130 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 289:
#line 1131 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 291:
#line 1139 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 292:
#line 1143 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 296:
#line 1163 "screen.yacc"
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
#line 1173 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 298:
#line 1180 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 299:
#line 1189 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 300:
#line 1193 "screen.yacc"
    {
	(yyval.column).tabname=strdup("");
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 303:
#line 1207 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 304:
#line 1214 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 305:
#line 1222 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 306:
#line 1227 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 307:
#line 1235 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 308:
#line 1239 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 309:
#line 1244 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 310:
#line 1249 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 311:
#line 1254 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 312:
#line 1259 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 313:
#line 1264 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 314:
#line 1273 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 315:
#line 1282 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 316:
#line 1283 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 318:
#line 1292 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 319:
#line 1300 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 320:
#line 1306 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 321:
#line 1312 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 322:
#line 1318 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 323:
#line 1326 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 324:
#line 1331 "screen.yacc"
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
#line 1341 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 326:
#line 1351 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 327:
#line 1357 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 328:
#line 1363 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 329:
#line 1369 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 330:
#line 1379 "screen.yacc"
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
#line 1391 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 332:
#line 1399 "screen.yacc"
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
#line 1411 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 334:
#line 1419 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 335:
#line 1420 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 336:
#line 1421 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 337:
#line 1425 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 338:
#line 1426 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 339:
#line 1427 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 340:
#line 1428 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 341:
#line 1429 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 342:
#line 1430 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 343:
#line 1431 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 344:
#line 1434 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 345:
#line 1441 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 346:
#line 1452 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 347:
#line 1456 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 348:
#line 1463 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 349:
#line 1471 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 350:
#line 1476 "screen.yacc"
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
#line 1487 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 352:
#line 1488 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 353:
#line 1494 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 354:
#line 1500 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 355:
#line 1508 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 357:
#line 1516 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 358:
#line 1517 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 363:
#line 1531 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 364:
#line 1533 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 365:
#line 1534 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 366:
#line 1535 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 367:
#line 1536 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 368:
#line 1537 "screen.yacc"
    { (yyval.expr)=(yyvsp[(3) - (4)].expr); }
    break;

  case 369:
#line 1538 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 370:
#line 1539 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 371:
#line 1540 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 372:
#line 1541 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 373:
#line 1542 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 374:
#line 1543 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 375:
#line 1544 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 376:
#line 1545 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 377:
#line 1546 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 378:
#line 1547 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 379:
#line 1548 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 380:
#line 1549 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 381:
#line 1550 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 382:
#line 1551 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 383:
#line 1552 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 384:
#line 1553 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 386:
#line 1559 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 387:
#line 1560 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 388:
#line 1561 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 389:
#line 1562 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 390:
#line 1563 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 391:
#line 1566 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 392:
#line 1570 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 5729 "y.tab.c"
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


#line 1845 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




