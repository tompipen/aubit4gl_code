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
     LOOKUP_FROM = 305,
     OPEN_BRACKET = 306,
     CLOSE_BRACKET = 307,
     STAR = 308,
     DIVIDE = 309,
     PLUS = 310,
     MINUS = 311,
     RECORD = 312,
     COMMA = 313,
     THROUGH = 314,
     TYPE = 315,
     DELIMITERS = 316,
     KW_CHAR = 317,
     KW_INT = 318,
     KW_DATE = 319,
     KW_FLOAT = 320,
     SMALLFLOAT = 321,
     SMALLINT = 322,
     KW_DECIMAL = 323,
     MONEY = 324,
     DATETIME = 325,
     INTERVAL = 326,
     LIKE = 327,
     BLACK = 328,
     BLUE = 329,
     GREEN = 330,
     CYAN = 331,
     RED = 332,
     MAGENTA = 333,
     WHITE = 334,
     YELLOW = 335,
     NORMAL = 336,
     REVERSE = 337,
     LEFT = 338,
     BOLD = 339,
     BLINK = 340,
     UNDERLINE = 341,
     DIM = 342,
     AUTONEXT = 343,
     COLOR = 344,
     COMMENTS = 345,
     DEFAULT = 346,
     VALIDATE = 347,
     DISPLAY = 348,
     DOWNSHIFT = 349,
     UPSHIFT = 350,
     FORMAT = 351,
     INCLUDE = 352,
     INVISIBLE = 353,
     NOUPDATE = 354,
     NOENTRY = 355,
     PICTURE = 356,
     PROGRAM = 357,
     REQUIRED = 358,
     QUERYCLEAR = 359,
     VERIFY = 360,
     WORDWRAP = 361,
     COMPRESS = 362,
     NONCOMPRESS = 363,
     TO = 364,
     AS = 365,
     SERIAL = 366,
     KW_BYTE = 367,
     KW_TEXT = 368,
     VARCHAR = 369,
     SQL_VAR = 370,
     KW_NONSPACE = 371,
     SQLONLY = 372,
     WIDGET = 373,
     CONFIG = 374,
     KW_NL = 375,
     COMPARISON = 376,
     KWOR = 377,
     KWAND = 378,
     KWAND1 = 379,
     KWWHERE = 380,
     KWNOT = 381,
     KWBETWEEN = 382,
     KWIN = 383,
     XVAL = 384,
     KWNULLCHK = 385,
     KWNOTNULLCHK = 386,
     YEAR = 387,
     MONTH = 388,
     DAY = 389,
     HOUR = 390,
     MINUTE = 391,
     SECOND = 392,
     FRACTION = 393,
     LISTBOX = 394,
     BUTTON = 395,
     KW_PANEL = 396,
     DISPLAYONLY = 397,
     ALLOWING = 398,
     KW_WS = 399,
     KW_TAB = 400,
     KW_MASTER_OF = 401,
     KW_BEFORE = 402,
     KW_AFTER = 403,
     KW_EDITADD = 404,
     KW_EDITUPDATE = 405,
     KW_REMOVE = 406,
     KW_OF = 407,
     KW_ADD = 408,
     KW_UPDATE = 409,
     KW_QUERY = 410,
     KW_ON_ENDING = 411,
     KW_ON_BEGINNING = 412,
     KW_CALL = 413,
     KW_BELL = 414,
     KW_ABORT = 415,
     KW_LET = 416,
     KW_EXITNOW = 417,
     KW_NEXTFIELD = 418,
     KW_IF = 419,
     KW_THEN = 420,
     KW_ELSE = 421,
     KW_BEGIN = 422,
     KW_TOTAL = 423,
     KW_RIGHT = 424,
     KW_ZEROFILL = 425,
     KW_USES_EXTENDED = 426,
     SPECIAL_DBNAME = 427,
     KW_ACTION = 428
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
#define LOOKUP_FROM 305
#define OPEN_BRACKET 306
#define CLOSE_BRACKET 307
#define STAR 308
#define DIVIDE 309
#define PLUS 310
#define MINUS 311
#define RECORD 312
#define COMMA 313
#define THROUGH 314
#define TYPE 315
#define DELIMITERS 316
#define KW_CHAR 317
#define KW_INT 318
#define KW_DATE 319
#define KW_FLOAT 320
#define SMALLFLOAT 321
#define SMALLINT 322
#define KW_DECIMAL 323
#define MONEY 324
#define DATETIME 325
#define INTERVAL 326
#define LIKE 327
#define BLACK 328
#define BLUE 329
#define GREEN 330
#define CYAN 331
#define RED 332
#define MAGENTA 333
#define WHITE 334
#define YELLOW 335
#define NORMAL 336
#define REVERSE 337
#define LEFT 338
#define BOLD 339
#define BLINK 340
#define UNDERLINE 341
#define DIM 342
#define AUTONEXT 343
#define COLOR 344
#define COMMENTS 345
#define DEFAULT 346
#define VALIDATE 347
#define DISPLAY 348
#define DOWNSHIFT 349
#define UPSHIFT 350
#define FORMAT 351
#define INCLUDE 352
#define INVISIBLE 353
#define NOUPDATE 354
#define NOENTRY 355
#define PICTURE 356
#define PROGRAM 357
#define REQUIRED 358
#define QUERYCLEAR 359
#define VERIFY 360
#define WORDWRAP 361
#define COMPRESS 362
#define NONCOMPRESS 363
#define TO 364
#define AS 365
#define SERIAL 366
#define KW_BYTE 367
#define KW_TEXT 368
#define VARCHAR 369
#define SQL_VAR 370
#define KW_NONSPACE 371
#define SQLONLY 372
#define WIDGET 373
#define CONFIG 374
#define KW_NL 375
#define COMPARISON 376
#define KWOR 377
#define KWAND 378
#define KWAND1 379
#define KWWHERE 380
#define KWNOT 381
#define KWBETWEEN 382
#define KWIN 383
#define XVAL 384
#define KWNULLCHK 385
#define KWNOTNULLCHK 386
#define YEAR 387
#define MONTH 388
#define DAY 389
#define HOUR 390
#define MINUTE 391
#define SECOND 392
#define FRACTION 393
#define LISTBOX 394
#define BUTTON 395
#define KW_PANEL 396
#define DISPLAYONLY 397
#define ALLOWING 398
#define KW_WS 399
#define KW_TAB 400
#define KW_MASTER_OF 401
#define KW_BEFORE 402
#define KW_AFTER 403
#define KW_EDITADD 404
#define KW_EDITUPDATE 405
#define KW_REMOVE 406
#define KW_OF 407
#define KW_ADD 408
#define KW_UPDATE 409
#define KW_QUERY 410
#define KW_ON_ENDING 411
#define KW_ON_BEGINNING 412
#define KW_CALL 413
#define KW_BELL 414
#define KW_ABORT 415
#define KW_LET 416
#define KW_EXITNOW 417
#define KW_NEXTFIELD 418
#define KW_IF 419
#define KW_THEN 420
#define KW_ELSE 421
#define KW_BEGIN 422
#define KW_TOTAL 423
#define KW_RIGHT 424
#define KW_ZEROFILL 425
#define KW_USES_EXTENDED 426
#define SPECIAL_DBNAME 427
#define KW_ACTION 428




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
//int A4GL_get_attr_from_string (char *s);

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
//int A4GL_wcswidth(char *mbs);	/* utf8 */

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
#line 544 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 557 "y.tab.c"

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
#define YYLAST   4429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  174
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  135
/* YYNRULES -- Number of rules.  */
#define YYNRULES  645
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1008

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   428

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
     165,   166,   167,   168,   169,   170,   171,   172,   173
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
     322,   327,   330,   335,   339,   343,   347,   353,   357,   363,
     365,   367,   371,   377,   381,   385,   389,   391,   396,   398,
     400,   402,   404,   408,   412,   414,   416,   418,   420,   422,
     424,   426,   429,   432,   434,   436,   438,   440,   443,   445,
     447,   449,   451,   453,   455,   457,   459,   461,   463,   465,
     467,   469,   471,   473,   475,   476,   480,   482,   485,   487,
     490,   493,   495,   496,   506,   519,   521,   523,   524,   527,
     528,   530,   531,   533,   535,   540,   542,   546,   547,   549,
     551,   555,   559,   563,   567,   569,   573,   575,   577,   578,
     580,   582,   585,   587,   589,   591,   592,   597,   599,   601,
     603,   605,   607,   609,   612,   615,   618,   621,   623,   625,
     627,   629,   631,   633,   637,   639,   642,   645,   647,   649,
     653,   657,   659,   661,   665,   669,   673,   677,   679,   680,
     684,   690,   691,   695,   696,   700,   702,   705,   707,   709,
     711,   713,   715,   717,   720,   722,   723,   727,   729,   731,
     733,   735,   737,   739,   741,   743,   746,   747,   751,   752,
     754,   757,   759,   763,   767,   771,   775,   779,   783,   788,
     792,   795,   798,   800,   806,   812,   815,   819,   821,   823,
     825,   827,   829,   831,   835,   838,   840,   843,   851,   853,
     857,   861,   863,   865,   867,   873,   879,   882,   885,   887,
     889,   891,   893,   895,   897,   899,   905,   906,   909,   911,
     916,   919,   923,   926,   930,   934,   936,   939,   942,   946,
     950,   955,   957,   960,   962,   965,   967,   969,   971,   973,
     975,   977,   979,   981,   983,   985,   987,   991,   995,   997,
    1002,  1003,  1010,  1011,  1013,  1015,  1019,  1021,  1023,  1027,
    1031,  1032,  1034,  1036,  1040,  1043,  1046,  1048,  1051,  1055,
    1060,  1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,  1096,
    1101,  1105,  1108,  1111,  1117,  1123,  1130,  1132,  1134,  1136,
    1138,  1140,  1142,  1144,  1148,  1150,  1152,  1154,  1156,  1158,
    1160,  1162,  1164,  1166,  1168,  1170,  1172,  1174,  1176,  1178,
    1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,  1196,  1198,
    1200,  1202,  1204,  1206,  1208,  1210,  1212,  1214,  1216,  1218,
    1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,
    1240,  1242,  1244,  1246,  1248,  1250,  1252,  1254,  1256,  1258,
    1260,  1262,  1264,  1266,  1268,  1270,  1272,  1274,  1276,  1278,
    1280,  1282,  1284,  1286,  1288,  1290,  1292,  1294,  1296,  1298,
    1300,  1302,  1304,  1306,  1308,  1310,  1312,  1314,  1316,  1318,
    1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,  1338,
    1340,  1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,
    1360,  1362,  1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,
    1380,  1382,  1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,
    1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,
    1420,  1422,  1424,  1426,  1428,  1430,  1432,  1434,  1436,  1438,
    1440,  1442,  1444,  1446,  1448,  1450,  1452,  1454,  1456,  1458,
    1460,  1462,  1464,  1466,  1468,  1470,  1472,  1474,  1476,  1478,
    1480,  1482,  1484,  1486,  1488,  1490,  1492,  1494,  1496,  1498,
    1500,  1502,  1504,  1506,  1508,  1510,  1512,  1514,  1516,  1518,
    1520,  1522,  1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,
    1540,  1542,  1544,  1546,  1548,  1550,  1552,  1554,  1556,  1558,
    1560,  1562,  1564,  1566,  1568,  1570,  1572,  1574,  1576,  1578,
    1580,  1582,  1584,  1586,  1588,  1590,  1592,  1594,  1596,  1598,
    1600,  1602,  1604,  1606,  1608,  1610,  1612,  1614,  1616,  1618,
    1620,  1622,  1624,  1626,  1628,  1630,  1632,  1634,  1636,  1638,
    1640,  1642,  1644,  1646,  1648,  1650
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     175,     0,    -1,   176,   180,   199,   204,   228,    -1,    21,
      34,    -1,    21,   179,    40,    41,    42,    -1,    21,    34,
      40,    41,    42,    -1,    21,   179,    -1,    30,    -1,   307,
      -1,    30,    -1,   308,    -1,   172,    -1,   172,    38,   178,
      -1,   177,    -1,   177,    38,   178,    -1,   181,    -1,   180,
     181,    -1,    -1,    24,   182,   184,    -1,    -1,    23,    46,
     183,   184,    -1,    -1,    -1,    -1,   189,   185,   188,    31,
     186,   191,    32,   187,   190,    -1,    -1,   171,    -1,    -1,
      25,    29,    -1,    25,    29,    22,    29,    -1,    -1,    27,
      -1,   193,    -1,   191,   193,    -1,   178,    -1,   192,    -1,
     195,    -1,   145,    -1,    17,    -1,    44,    -1,    46,    -1,
     194,    -1,   144,    -1,   120,    -1,   116,    -1,    16,    -1,
     194,    16,    -1,    -1,    26,   196,   197,    28,    -1,   246,
      -1,    -1,   197,    44,   198,   246,    -1,    -1,    43,   200,
     190,    -1,   201,    -1,   200,   201,    -1,   200,    58,   201,
      -1,   178,   202,    -1,    -1,    45,   203,    -1,   178,    -1,
     178,    37,   178,    -1,   178,    38,   178,    -1,   178,    38,
     178,    37,   178,    -1,   178,    39,   178,    -1,    46,    39,
     178,    -1,    20,   205,   190,    -1,   206,    -1,   205,   206,
      -1,    -1,   245,   207,   208,    47,    -1,   209,    -1,   208,
     209,    -1,   208,    47,   209,    -1,    -1,    -1,    45,   210,
     215,   212,   211,   222,    -1,    -1,    26,    29,    28,    -1,
      26,    29,    58,    29,    28,    -1,   214,   126,    41,    -1,
     214,    -1,    -1,    60,    72,   178,    39,   178,    -1,    60,
      72,   178,    -1,    60,   248,    -1,    34,    39,   241,   213,
      -1,   142,   213,    -1,   142,   143,    42,   213,    -1,   178,
      39,   178,    -1,   178,    -1,    53,   178,    39,   178,    -1,
      53,   178,    -1,   217,    -1,   216,    58,   217,    -1,   218,
      45,   219,    -1,   245,    -1,   178,    39,   178,    -1,   178,
      -1,   178,    39,   178,    -1,   178,    -1,    53,   178,    39,
     178,    -1,    53,   178,    -1,    49,    -1,    58,    49,    -1,
      -1,    58,   223,    -1,   224,    -1,   223,    58,   224,    -1,
      88,    -1,    89,    45,   226,   264,    -1,    50,   220,    -1,
      48,   216,   221,   220,    -1,    90,    45,    46,    -1,    91,
      45,   225,    -1,    93,    72,   178,    -1,    93,    72,   178,
      39,   178,    -1,    92,    72,   178,    -1,    92,    72,   178,
      39,   178,    -1,    94,    -1,    95,    -1,    96,    45,    46,
      -1,    97,    45,    51,   249,    52,    -1,   118,    45,    46,
      -1,   119,    45,    46,    -1,   173,    45,   178,    -1,    98,
      -1,    36,    25,    45,    29,    -1,    36,    -1,   117,    -1,
     100,    -1,    99,    -1,   101,    45,    46,    -1,   102,    45,
      46,    -1,   103,    -1,    82,    -1,   105,    -1,   104,    -1,
     170,    -1,   169,    -1,   106,    -1,   106,   107,    -1,   106,
     108,    -1,    46,    -1,    29,    -1,   115,    -1,   227,    -1,
     226,   227,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    29,
      -1,    82,    -1,    87,    -1,    81,    -1,    83,    -1,    84,
      -1,    85,    -1,    86,    -1,    -1,    19,   229,   190,    -1,
     230,    -1,   229,   230,    -1,   231,    -1,   231,    47,    -1,
      61,    46,    -1,   278,    -1,    -1,    24,    57,   232,   236,
      51,   237,    52,   233,   235,    -1,   141,    51,    29,    58,
      29,    52,   109,    51,    29,    58,    29,    52,    -1,   271,
      -1,   294,    -1,    -1,   110,   139,    -1,    -1,    53,    -1,
      -1,    47,    -1,   178,    -1,   178,    26,    29,    28,    -1,
     240,    -1,   237,   238,   240,    -1,    -1,    58,    -1,   178,
      -1,   178,    39,   178,    -1,    34,    39,   178,    -1,   178,
      39,    53,    -1,    34,    39,    53,    -1,   239,    -1,   239,
      59,   239,    -1,   178,    -1,    27,    -1,    -1,   243,    -1,
     244,    -1,   243,   244,    -1,   144,    -1,   145,    -1,   178,
      -1,    -1,   242,   178,   247,   242,    -1,    62,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,
     252,    -1,    69,   252,    -1,    70,   259,    -1,    71,   253,
      -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,   140,
      -1,   251,    -1,   249,    58,   251,    -1,    29,    -1,    55,
      29,    -1,    56,    29,    -1,    46,    -1,    30,    -1,    30,
     109,    30,    -1,    30,    37,    30,    -1,    16,    -1,   250,
      -1,   250,   109,   250,    -1,   250,    37,   250,    -1,    46,
     109,    46,    -1,    46,    37,    46,    -1,    41,    -1,    -1,
      51,    29,    52,    -1,    51,    29,    58,    29,    52,    -1,
      -1,   256,   109,   258,    -1,    -1,    51,    29,    52,    -1,
      29,    -1,   257,   254,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,   263,    -1,
     257,    -1,    -1,   260,   109,   261,    -1,   262,    -1,   262,
      -1,   132,    -1,   133,    -1,   134,    -1,   135,    -1,   136,
      -1,   137,    -1,   138,   263,    -1,    -1,    51,   255,    52,
      -1,    -1,   265,    -1,   125,   266,    -1,   267,    -1,   267,
     123,   267,    -1,   267,   122,   267,    -1,   268,   121,   268,
      -1,   268,     8,   268,    -1,   268,     9,   268,    -1,   268,
      72,   268,    -1,   268,   126,    72,   268,    -1,   268,    45,
     268,    -1,   268,   130,    -1,   268,   131,    -1,   268,    -1,
     268,   127,   268,   123,   268,    -1,   268,   128,    51,   270,
      52,    -1,   126,   267,    -1,    51,   267,    52,    -1,   269,
      -1,    29,    -1,    46,    -1,   129,    -1,    30,    -1,   268,
      -1,   270,    58,   268,    -1,    18,   272,    -1,   273,    -1,
     272,   273,    -1,     8,   274,     9,   234,     8,   274,     9,
      -1,   275,    -1,   274,    58,   275,    -1,   276,    39,   277,
      -1,   277,    -1,   178,    -1,   177,    -1,   147,   288,   152,
     292,   286,    -1,   148,   289,   152,   292,   286,    -1,   157,
     295,    -1,   156,   295,    -1,   282,    -1,   287,    -1,   280,
      -1,   283,    -1,   284,    -1,   295,    -1,   285,    -1,   164,
     300,   165,   279,   281,    -1,    -1,   166,   279,    -1,   160,
      -1,   161,   245,    45,   300,    -1,   163,   245,    -1,   163,
      45,   245,    -1,   163,   162,    -1,   163,    45,   162,    -1,
     167,   286,    27,    -1,   279,    -1,   286,   279,    -1,    90,
      46,    -1,    90,   159,    46,    -1,    90,    82,    46,    -1,
      90,   159,    82,    46,    -1,   290,    -1,   288,   290,    -1,
     291,    -1,   289,   291,    -1,   149,    -1,   150,    -1,   151,
      -1,   149,    -1,   153,    -1,   154,    -1,   155,    -1,   151,
      -1,    93,    -1,   150,    -1,   293,    -1,   292,   238,   293,
      -1,   276,    39,   277,    -1,   277,    -1,   276,   146,   276,
     235,    -1,    -1,   158,   178,    51,   296,   297,    52,    -1,
      -1,   298,    -1,   299,    -1,   298,    58,   299,    -1,   300,
      -1,   303,    -1,   300,   123,   300,    -1,   300,   122,   300,
      -1,    -1,   302,    -1,   300,    -1,   302,    58,   300,    -1,
      56,   300,    -1,    55,   300,    -1,   305,    -1,   126,   300,
      -1,    51,   300,    52,    -1,   304,    51,   301,    52,    -1,
     168,   152,   245,    -1,   300,   121,   300,    -1,   300,     8,
     300,    -1,   300,     9,   300,    -1,   300,    53,   300,    -1,
     300,    55,   300,    -1,   300,    56,   300,    -1,   300,    54,
     300,    -1,   300,    72,   300,    -1,   300,   126,    72,   300,
      -1,   300,    45,   300,    -1,   300,   130,    -1,   300,   131,
      -1,   300,   127,   300,   123,   300,    -1,   300,   128,    51,
     306,    52,    -1,   300,   126,   128,    51,   306,    52,    -1,
     178,    -1,   245,    -1,    29,    -1,    46,    -1,   129,    -1,
      41,    -1,   305,    -1,   306,    58,   305,    -1,    18,    -1,
      20,    -1,    21,    -1,    22,    -1,    25,    -1,    19,    -1,
      27,    -1,    33,    -1,    35,    -1,    36,    -1,    41,    -1,
      42,    -1,    43,    -1,    48,    -1,    49,    -1,    57,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
      69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,
      89,    -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,
      94,    -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,   101,    -1,   102,    -1,   103,    -1,
     104,    -1,   105,    -1,   106,    -1,   107,    -1,   108,    -1,
     109,    -1,   110,    -1,   111,    -1,   112,    -1,   113,    -1,
     114,    -1,   115,    -1,   116,    -1,   117,    -1,   118,    -1,
     119,    -1,   121,    -1,     8,    -1,     9,    -1,   122,    -1,
     123,    -1,   125,    -1,   126,    -1,   127,    -1,   128,    -1,
     129,    -1,   130,    -1,   131,    -1,   132,    -1,   133,    -1,
     134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,
     139,    -1,   140,    -1,   141,    -1,   142,    -1,   143,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,
     151,    -1,   152,    -1,   153,    -1,   154,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,
     161,    -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,   169,    -1,   170,    -1,
     171,    -1,   173,    -1,    18,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    33,    -1,    34,    -1,
      35,    -1,    36,    -1,    40,    -1,    42,    -1,    43,    -1,
      48,    -1,    49,    -1,    57,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,
      66,    -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,
      71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
      76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,
      91,    -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,
      96,    -1,    97,    -1,    98,    -1,    99,    -1,   100,    -1,
     101,    -1,   102,    -1,   103,    -1,   104,    -1,   105,    -1,
     106,    -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,
     111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,
     117,    -1,   118,    -1,   119,    -1,   121,    -1,     8,    -1,
       9,    -1,   122,    -1,   123,    -1,   125,    -1,   126,    -1,
     127,    -1,   128,    -1,   130,    -1,   131,    -1,   132,    -1,
     133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,
     138,    -1,   139,    -1,   140,    -1,   141,    -1,   143,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,
     151,    -1,   152,    -1,   153,    -1,   154,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,
     161,    -1,   163,    -1,   164,    -1,   165,    -1,   166,    -1,
     167,    -1,   168,    -1,   169,    -1,   170,    -1,   171,    -1,
     173,    -1
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
     672,   692,   714,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   752,   758,   759,   760,   764,   765,   769,   770,
     771,   772,   773,   774,   775,   776,   778,   792,   793,   794,
     795,   796,   797,   798,   802,   803,   806,   806,   808,   808,
     811,   821,   827,   827,   830,   831,   832,   836,   836,   838,
     838,   841,   841,   843,   846,   852,   855,   859,   860,   864,
     866,   868,   870,   872,   877,   877,   881,   884,   888,   888,
     891,   891,   895,   896,   909,   917,   917,   926,   930,   934,
     938,   942,   946,   950,   956,   960,   964,   968,   972,   976,
     980,   983,   990,   990,   995,   995,   995,  1000,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1018,  1022,  1028,  1031,
    1032,  1035,  1036,  1043,  1045,  1050,  1058,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1073,  1075,  1076,  1079,  1082,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1098,  1100,  1107,  1107,
    1113,  1119,  1120,  1123,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,  1144,  1151,  1152,
    1153,  1158,  1161,  1165,  1177,  1180,  1181,  1185,  1195,  1202,
    1211,  1214,  1226,  1229,  1233,  1240,  1248,  1253,  1261,  1265,
    1270,  1275,  1280,  1285,  1290,  1299,  1308,  1309,  1314,  1317,
    1325,  1331,  1337,  1343,  1352,  1357,  1367,  1377,  1383,  1389,
    1395,  1405,  1417,  1425,  1437,  1445,  1446,  1447,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1460,  1467,  1478,  1482,  1489,
    1497,  1497,  1513,  1514,  1520,  1526,  1534,  1541,  1542,  1543,
    1548,  1549,  1552,  1553,  1557,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,
    1574,  1575,  1576,  1577,  1578,  1579,  1582,  1585,  1586,  1587,
    1588,  1589,  1592,  1596,  1607,  1609,  1610,  1611,  1612,  1613,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,
    1695,  1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,
    1705,  1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,
    1715,  1716,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,
    1735,  1736,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,
    1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,
    1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,
    1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,
    1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,
    1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,
    1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,
    1861,  1862,  1863,  1864,  1865,  1866
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
  "SEMICOLON", "LOOKUP", "JOINING", "LOOKUP_FROM", "OPEN_BRACKET",
  "CLOSE_BRACKET", "STAR", "DIVIDE", "PLUS", "MINUS", "RECORD", "COMMA",
  "THROUGH", "TYPE", "DELIMITERS", "KW_CHAR", "KW_INT", "KW_DATE",
  "KW_FLOAT", "SMALLFLOAT", "SMALLINT", "KW_DECIMAL", "MONEY", "DATETIME",
  "INTERVAL", "LIKE", "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA",
  "WHITE", "YELLOW", "NORMAL", "REVERSE", "LEFT", "BOLD", "BLINK",
  "UNDERLINE", "DIM", "AUTONEXT", "COLOR", "COMMENTS", "DEFAULT",
  "VALIDATE", "DISPLAY", "DOWNSHIFT", "UPSHIFT", "FORMAT", "INCLUDE",
  "INVISIBLE", "NOUPDATE", "NOENTRY", "PICTURE", "PROGRAM", "REQUIRED",
  "QUERYCLEAR", "VERIFY", "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO",
  "AS", "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR",
  "KW_NONSPACE", "SQLONLY", "WIDGET", "CONFIG", "KW_NL", "COMPARISON",
  "KWOR", "KWAND", "KWAND1", "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN",
  "XVAL", "KWNULLCHK", "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR",
  "MINUTE", "SECOND", "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL",
  "DISPLAYONLY", "ALLOWING", "KW_WS", "KW_TAB", "KW_MASTER_OF",
  "KW_BEFORE", "KW_AFTER", "KW_EDITADD", "KW_EDITUPDATE", "KW_REMOVE",
  "KW_OF", "KW_ADD", "KW_UPDATE", "KW_QUERY", "KW_ON_ENDING",
  "KW_ON_BEGINNING", "KW_CALL", "KW_BELL", "KW_ABORT", "KW_LET",
  "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF", "KW_THEN", "KW_ELSE", "KW_BEGIN",
  "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL", "KW_USES_EXTENDED",
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
     425,   426,   427,   428
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   174,   175,   176,   176,   176,   176,   177,   177,   178,
     178,   179,   179,   179,   179,   180,   180,   182,   181,   183,
     181,   185,   186,   187,   184,   188,   188,   189,   189,   189,
     190,   190,   191,   191,   192,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   194,   194,   196,   195,   197,
     198,   197,   199,   199,   200,   200,   200,   201,   202,   202,
     203,   203,   203,   203,   203,   203,   204,   205,   205,   207,
     206,   208,   208,   208,   210,   211,   209,   212,   212,   212,
     213,   213,   214,   214,   214,   214,   215,   215,   215,   215,
     215,   215,   215,   216,   216,   217,   218,   219,   219,   220,
     220,   220,   220,   221,   221,   222,   222,   223,   223,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   225,   225,   225,   226,   226,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   228,   228,   229,   229,   230,   230,
     231,   231,   232,   231,   231,   231,   231,   233,   233,   234,
     234,   235,   235,   236,   236,   237,   237,   238,   238,   239,
     239,   239,   239,   239,   240,   240,   241,   241,   242,   242,
     243,   243,   244,   244,   245,   247,   246,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   249,   249,   250,   250,   250,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   252,   252,
     252,   253,   253,   254,   254,   255,   256,   257,   257,   257,
     257,   257,   257,   257,   258,   259,   259,   260,   261,   262,
     262,   262,   262,   262,   262,   262,   263,   263,   264,   264,
     265,   266,   266,   266,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   268,   268,   268,
     268,   269,   270,   270,   271,   272,   272,   273,   274,   274,
     275,   275,   276,   277,   278,   278,   278,   278,   279,   279,
     279,   279,   279,   279,   279,   280,   281,   281,   282,   283,
     284,   284,   284,   284,   285,   286,   286,   287,   287,   287,
     287,   288,   288,   289,   289,   290,   290,   290,   291,   291,
     291,   291,   291,   291,   291,   292,   292,   293,   293,   294,
     296,   295,   297,   297,   298,   298,   299,   300,   300,   300,
     301,   301,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   304,   305,   305,   305,
     305,   305,   306,   306,   307,   307,   307,   307,   307,   307,
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
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308
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
       4,     2,     4,     3,     3,     3,     5,     3,     5,     1,
       1,     3,     5,     3,     3,     3,     1,     4,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     1,     2,     1,     2,
       2,     1,     0,     9,    12,     1,     1,     0,     2,     0,
       1,     0,     1,     1,     4,     1,     3,     0,     1,     1,
       3,     3,     3,     3,     1,     3,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     0,     3,
       5,     0,     3,     0,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     3,     0,     1,
       2,     1,     3,     3,     3,     3,     3,     3,     4,     3,
       2,     2,     1,     5,     5,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     2,     7,     1,     3,
       3,     1,     1,     1,     5,     5,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     0,     2,     1,     4,
       2,     3,     2,     3,     3,     1,     2,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     4,
       0,     6,     0,     1,     1,     3,     1,     1,     3,     3,
       0,     1,     1,     3,     2,     2,     1,     2,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     2,     2,     5,     5,     6,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,   472,   473,   394,   399,   395,   396,
     397,   398,   400,     7,   401,     3,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,    11,   521,    13,     6,     8,     1,     0,
      17,    52,    15,     0,     0,     0,     0,    19,    27,     0,
      16,     0,     0,   599,   600,   522,   523,   524,   525,   526,
     527,     9,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,    12,    10,
      14,     0,    27,     0,    18,    21,    58,    30,    54,     0,
     164,     5,     4,    20,    28,    25,     0,    57,    31,     0,
      53,    55,   204,    30,    67,    69,     0,     2,     0,    26,
       0,     0,    60,    59,    56,    66,    68,     0,   522,   526,
     540,   618,   621,   622,   630,   631,   302,    30,   166,   168,
     175,     0,   171,   176,    29,    22,     0,     0,     0,     0,
      74,     0,    71,     0,   294,   295,   172,   170,     0,   335,
     336,   337,     0,   331,   343,   338,   344,   342,   339,   340,
     341,     0,   333,     0,   307,   306,   165,   167,   169,     0,
       0,    65,    61,    62,    64,     0,    70,    72,   472,   473,
     394,   396,   397,   398,     7,   401,   402,   403,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     468,   469,   470,   471,   474,   475,   476,   477,   478,   479,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   303,
       0,   298,     0,   301,   296,     0,     0,     0,   332,     0,
     334,     0,   181,    45,    38,    47,    39,    40,    44,    43,
      42,    37,    34,     0,    35,    32,    41,    36,     0,   529,
       0,    82,    90,    77,    73,   179,     0,     0,   183,     0,
       0,     0,   348,   187,   345,   187,   350,   182,   349,   198,
      23,    33,    46,    63,     0,    92,     0,     0,    87,    81,
       0,     0,    75,   180,     0,   299,   300,     0,     0,     0,
       0,   188,     0,   318,     0,     0,     0,     0,     0,   325,
     310,   308,   311,   312,   314,   304,   309,   313,   305,   352,
     202,   203,     0,     0,   199,   200,    49,    30,   197,   196,
      82,     0,   207,   208,   209,   210,   211,   212,   238,   238,
     255,   241,     0,   217,   218,   219,   220,   221,    85,    82,
       0,    89,     0,   105,     0,     0,   529,   189,   187,   194,
     185,     0,   347,   327,     0,     0,     0,     0,   322,   320,
     388,   391,   389,     0,     0,     0,   604,   390,   641,   204,
     387,     0,   357,     0,   366,     0,   346,   326,     0,   353,
     354,   356,    48,    50,   205,   201,    24,    86,    91,     0,
     213,   214,   259,   260,   261,   262,   263,   264,   266,   215,
       0,   257,   247,   248,   249,   250,   251,   252,   266,   216,
       0,   243,    84,    88,    80,    78,     0,     0,    76,     0,
     184,     0,     0,   177,     0,     0,     0,   329,   328,     0,
       0,   323,   321,     0,   365,   364,   367,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,   382,     0,   360,   324,   351,     0,   198,
     198,     0,     0,   265,     0,   253,     0,     0,   246,     0,
       0,   128,     0,     0,   135,   109,     0,     0,     0,     0,
       0,   119,   120,     0,     0,   126,   131,   130,     0,     0,
     134,   137,   136,   140,   129,     0,     0,   139,   138,     0,
     106,   107,   297,   193,   191,   192,   190,     0,   181,   186,
     195,     0,   330,   319,   368,   370,   372,   373,   380,   374,
     377,   375,   376,   378,   371,   359,   358,     0,     0,     0,
       0,   316,   362,     0,   361,   355,    51,   206,   239,     0,
     245,     0,   256,   258,   254,   242,     0,    83,    79,     0,
       0,    93,     0,    96,     0,   100,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,   142,     0,     0,
       0,     0,   178,   173,     0,   379,     0,     0,   392,     0,
       0,   315,   369,     0,     0,   267,   244,     0,   103,     0,
       0,     0,   102,     0,   156,   148,   149,   150,   151,   152,
     153,   154,   155,   159,   157,   160,   161,   162,   163,   158,
     268,   146,   113,   144,   143,   145,   114,   117,   115,   121,
       0,   132,   133,   123,   124,   125,   108,     0,     0,   383,
     384,     0,   317,   363,   240,   127,   104,    94,   112,    98,
      95,     0,    99,     0,   147,   110,   269,     0,     0,   231,
     224,   228,   237,   227,     0,     0,     0,   232,   222,     0,
     385,   393,     0,   101,   288,   291,   289,     0,     0,   290,
     270,   271,   282,   287,   118,   116,     0,     0,     0,     0,
     225,   226,   122,     0,     0,     0,   174,    97,     0,   285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     280,   281,   230,   229,   236,   235,   223,   234,   233,   286,
     273,   272,   275,   276,   279,   277,   274,     0,     0,     0,
     278,     0,   292,     0,   283,   284,     0,   293
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   499,   649,   136,   141,   142,   148,   282,
     284,   295,   370,   597,   310,   285,   300,   523,   524,   525,
     526,   527,   549,   592,   739,   151,   287,   288,   297,   313,
     290,   303,   304,   317,   341,   342,   375,   623,   562,   558,
     559,   533,   830,   831,   832,   920,   836,   870,   698,   780,
     781,   896,   890,   891,   307,   327,   328,   329,   505,   788,
     564,   548,   539,   628,   578,   629,   630,   600,   593,   594,
     595,   650,   596,   740,   618,   936,   937,   938,   670,   689,
     748,   821,   690,   691,   825,   679,   680,   822,   681,   743,
     925,   926,   950,   951,   952,   953,  1003,   330,   344,   345,
     500,   501,   502,   503,   332,   579,   580,   861,   581,   582,
     583,   584,   585,   586,   352,   361,   353,   362,   543,   544,
     333,   587,   589,   658,   659,   660,   661,   813,   814,   652,
     653,   654,   859,   137,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -854
static const yytype_int16 yypact[] =
{
      26,  1434,    44,   137,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,    20,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,    25,  -854,    29,    68,  -854,  -854,    38,
    -854,    56,  -854,    75,  3758,  3758,    82,  -854,   102,  3758,
    -854,   138,   133,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   148,   102,   176,  -854,  -854,   169,  1932,  -854,  3758,
     199,  -854,  -854,  -854,   194,    61,  2430,  -854,  -854,  3758,
    -854,  -854,  -854,  2596,  -854,  -854,  3924,  -854,   195,  -854,
     217,   211,    97,  -854,  -854,  -854,  -854,   209,   270,   222,
     236,   242,    28,    47,   136,   136,  -854,  2762,  -854,   248,
    -854,   151,  -854,  -854,  -854,  -854,  3758,  3758,  3758,  3758,
    -854,    -5,  -854,  1102,   270,  -854,  -854,  -854,   269,  -854,
    -854,  -854,    71,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,    58,  -854,  3758,  -854,  -854,  -854,  -854,  -854,  3758,
     936,  -854,  -854,   263,  -854,  2098,   209,  -854,   262,   266,
     267,   268,   271,   273,   276,   277,   279,   280,   281,   282,
     283,   284,   299,   300,   302,   303,   304,   314,   315,   316,
     317,   318,   319,   323,   325,   327,   328,   329,   330,   331,
     332,   335,   336,   337,   338,   339,   341,   342,   343,   344,
     346,   348,   349,   350,   352,   358,   362,   369,   372,   373,
     374,   375,   376,   382,   383,   386,   387,   388,   389,   394,
     398,   399,   400,   401,   402,   403,   408,   409,   411,   412,
     414,   415,   416,   417,   419,   420,   421,   422,   424,   425,
     426,   427,   430,   431,   432,   436,   437,   444,   445,   449,
     450,   475,   476,   480,   483,   484,   485,   497,   503,   505,
     506,   507,   508,   510,   511,   512,   513,   514,   515,   516,
     517,   520,   524,   526,   528,   529,   530,   531,   533,  -854,
      14,  -854,   539,  -854,  -854,  3758,   244,  1102,  -854,  1102,
    -854,   257,   264,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,   770,  -854,  -854,   413,  -854,  3758,   540,
    3758,   -46,   541,   555,  -854,   532,  1102,  1600,   556,   535,
     361,   544,  -854,    24,  -854,    24,  -854,  -854,  -854,    83,
    -854,  -854,  -854,  -854,  2928,   548,   463,   546,  -854,   464,
    3758,   560,  -854,  -854,   583,  -854,  -854,   563,  4090,   542,
    1600,  -854,   -37,  -854,  3758,  2264,  1268,   -60,  1102,  -854,
    -854,  -854,  -854,  -854,  -854,   -60,  -854,  -854,   -60,  1268,
    -854,  -854,    18,  3758,    83,  -854,  -854,   566,  -854,  -854,
     536,  3758,  -854,  -854,  -854,  -854,  -854,  -854,   547,   547,
     197,   213,  3758,  -854,  -854,  -854,  -854,  -854,  -854,   536,
     554,  -854,     7,   543,  1102,   569,   561,   565,    23,   551,
    -854,   490,  -854,  -854,   567,   -18,   557,  3094,  -854,  -854,
    -854,  -854,  -854,  1268,  1268,  1268,  1268,  -854,   454,   564,
    -854,    -2,  -854,   568,  -854,   -14,  -854,  -854,   559,   549,
    -854,   351,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   585,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   570,  -854,
     509,  -854,  -854,  -854,  -854,  -854,  -854,  -854,   570,  -854,
     518,   571,   573,  -854,  -854,  -854,   587,   167,  -854,    16,
    -854,  3260,  3426,   519,  4090,  4090,   572,  -854,  -854,   574,
    1268,  -854,  -854,   272,   351,   351,   351,  3758,  1268,  1268,
    1268,  1268,  1268,  1268,  1268,  1268,  1268,  1268,  1268,   -55,
    1268,   575,  -854,  -854,   -60,  1268,  -854,  -854,  1268,    83,
      83,    53,   588,  -854,   197,  -854,   213,   595,  -854,  3758,
     597,   603,  3758,  3592,  -854,  -854,   586,   589,   590,   558,
     576,  -854,  -854,   591,   592,  -854,  -854,  -854,   593,   594,
    -854,  -854,  -854,   122,  -854,   596,   598,  -854,  -854,   599,
     582,  -854,  -854,  -854,  -854,  -854,  -854,   493,   264,  -854,
    -854,   604,  -854,   351,  -854,  -854,   390,   390,   351,   351,
     351,   351,   351,   351,   351,   351,   351,  1268,   600,   364,
    1766,   479,   351,   601,   584,  -854,  -854,  -854,  -854,   617,
    -854,   602,  -854,  -854,  -854,  -854,   605,  -854,  -854,   607,
      19,  -854,   610,  -854,  3758,   608,  -854,   160,   612,   -19,
    3758,  3758,   613,   609,   615,   616,  -854,  -854,   618,   619,
    3758,   167,  -854,  -854,   611,   351,  1766,  1268,  -854,    54,
     -60,  -854,  -854,  1268,   620,  -854,  -854,   621,  -854,  4256,
    3592,  3758,   624,  3758,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
     423,  -854,  -854,  -854,  -854,  -854,  -854,   628,   629,  -854,
     258,  -854,  -854,  -854,  -854,  -854,  -854,   627,    57,   351,
    -854,  1766,  -854,   351,  -854,  -854,   625,  -854,  -854,   632,
    -854,  3758,  -854,     4,  -854,  -854,  -854,  3758,  3758,  -854,
    -854,   -22,  -854,   -21,   644,   645,    96,   -16,  -854,   623,
    -854,  -854,  3758,  -854,  -854,  -854,  -854,     4,     4,  -854,
    -854,   129,    11,  -854,  -854,  -854,   646,   647,   633,   634,
    -854,  -854,  -854,   258,    30,    30,  -854,  -854,   626,  -854,
       4,     4,     2,     2,     2,     2,     2,   577,     2,   630,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,     2,   562,     2,
    -854,     2,  -854,   128,  -854,  -854,     2,  -854
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -854,  -854,  -854,   681,  -144,  -854,  -854,   545,  -854,  -854,
     405,  -854,  -854,  -854,  -854,  -854,  -301,  -854,  -854,   161,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -250,  -854,  -854,
    -854,  -854,   380,  -854,  -854,  -305,  -854,  -854,  -854,  -562,
    -854,  -854,  -854,  -181,  -854,  -854,  -179,  -854,  -854,  -854,
    -162,  -854,  -854,  -198,  -854,  -854,   366,  -854,  -854,  -854,
    -854,   -94,  -854,  -854,    67,    -7,    -4,  -854,   -41,  -854,
     107,  -285,   -36,  -854,  -854,  -854,  -688,  -261,    95,  -854,
    -854,  -854,  -854,   -39,  -854,  -854,  -854,  -854,   -35,    17,
    -854,  -854,  -854,  -853,  -435,  -854,  -854,  -854,  -854,   367,
      84,   174,  -303,  -468,  -854,  -577,  -854,  -854,  -854,  -854,
    -854,  -854,  -516,  -854,  -854,  -854,   363,   353,   204,   139,
    -854,   -33,  -854,  -854,  -854,   -20,  -554,  -854,  -854,  -854,
    -854,  -798,  -140,  -854,  -854
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -646
static const yytype_int16 yytable[] =
{
     278,   280,   315,   331,   305,   286,   718,   719,   657,   633,
     893,   657,   858,   736,   556,   956,   958,   807,   305,   972,
     973,   964,   651,   535,   331,   782,   366,   894,   708,   588,
     572,   944,   945,   944,   945,   695,   377,   301,   667,   542,
     340,   542,   376,   720,   138,   634,   662,     1,   946,   314,
     946,   721,   722,   723,   724,   947,   974,   693,   858,   930,
     143,   655,   663,   144,   709,   696,   512,   145,   868,   566,
     725,   534,   536,   808,   536,   703,   572,   869,   657,   139,
     140,   571,   571,   975,   147,   934,   935,   957,   959,   713,
     714,   715,   716,   965,   968,   969,   895,   557,   363,   149,
     573,   574,   632,   575,   576,   818,   910,   577,   146,   940,
     542,   819,   911,   941,   572,   911,   152,   990,   991,   726,
     727,   728,   635,   281,   729,   730,   731,   283,   732,   733,
     948,   949,   976,   949,   337,   338,   339,   977,   978,   979,
     354,   980,   981,   286,   363,   302,   573,   574,   962,   575,
     576,   354,   312,   577,   963,   286,   793,   811,   289,   302,
     139,   140,   326,   734,   796,   797,   798,   799,   800,   801,
     802,   803,   804,   805,   806,   291,   809,   349,   350,   351,
    1005,   812,   363,   326,   573,   574,  1006,   575,   576,   874,
     292,   577,   371,   372,   373,   374,   355,   356,   357,   326,
     358,   359,   360,   751,   541,   294,   541,   355,   356,   357,
     509,   358,   359,   360,   296,   752,   308,   753,   306,   511,
     349,   350,   351,   507,   334,   326,   522,   590,   591,   846,
     847,   532,   309,   875,   876,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   335,   754,
     336,   970,   971,   855,   340,   755,   756,   757,   758,   759,
     760,   761,   762,   763,   764,   765,   766,   767,   768,   769,
     770,   771,   772,   773,   929,   541,   987,   988,   343,   346,
     718,   719,   347,   912,   774,   775,   776,   930,   931,   636,
     639,   364,   365,   348,   363,   368,   666,   369,   506,   932,
     528,  -599,   540,   909,   933,  -600,  -522,  -523,   546,   913,
    -524,   547,  -527,   934,   935,    -9,  -528,   720,  -530,  -531,
    -533,  -534,  -535,  -536,   794,   721,   722,   723,   724,   672,
     673,   674,   675,   676,   677,   678,   777,   778,  -537,  -538,
     779,  -539,  -540,  -541,   725,   682,   683,   684,   685,   686,
     687,   688,   712,  -542,  -543,  -544,  -545,  -546,  -547,   718,
     719,   538,  -548,   326,  -549,   326,  -550,  -551,  -552,  -553,
    -554,  -555,   718,   719,  -556,  -557,  -558,  -559,  -560,   522,
    -561,  -562,  -563,  -564,   553,  -565,   555,  -566,  -567,  -568,
     569,  -569,   326,   726,   727,   728,   720,  -570,   729,   730,
     731,  -571,   732,   733,   721,   722,   723,   724,  -572,   720,
     599,  -573,  -574,  -575,  -576,  -577,   621,   721,   722,   723,
     724,  -578,  -579,   725,   627,  -580,  -581,  -582,  -583,   552,
     302,   302,   795,  -584,   326,   720,   725,  -585,  -586,  -587,
    -588,  -589,  -590,   721,   722,   723,   724,  -591,  -592,   664,
    -593,  -594,   874,  -595,  -596,  -597,  -598,   668,  -601,  -602,
    -603,  -604,   725,  -605,  -606,  -607,  -608,   833,   692,  -609,
    -610,  -611,   726,   727,   728,  -612,  -613,   729,   730,   731,
     326,   732,   733,  -614,  -615,   726,   727,   857,  -616,  -617,
     729,   730,   731,   302,   732,   733,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   887,   888,
     889,   726,   727,   728,  -618,  -619,   729,   730,   731,  -620,
     732,   733,  -621,  -622,  -623,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,  -624,   992,   993,   994,
     995,   996,  -625,   998,  -626,  -627,  -628,  -629,   923,  -630,
    -631,  -632,  -633,  -634,  -635,  -636,  -637,   784,   786,  -638,
     627,   627,  1000,  -639,  1002,  -640,  1004,  -641,  -642,  -643,
    -644,  1007,  -645,   302,   613,   614,   615,   616,   537,   554,
     560,   561,   567,   570,   833,   563,   568,   601,   619,   622,
     620,   624,   625,   298,   631,   694,   556,   700,   669,   706,
     701,   697,   710,   617,   702,   827,   717,   738,   302,   835,
     705,   737,   749,   707,   741,  -386,   750,   820,   744,   735,
     792,   742,   747,   791,   826,   828,   810,   746,   829,   787,
     840,   837,   852,   854,   838,   839,   842,   843,   844,   845,
     851,   848,   863,   849,   850,   860,   864,   873,   841,   997,
     915,   856,   867,   862,   865,   871,   939,   866,   892,   899,
     900,   901,   902,   921,   903,   904,   302,   927,   928,   907,
    -536,   942,   914,   960,   961,   966,   982,   983,   989,   984,
     985,   999,   135,   316,   551,  1001,   150,   293,   917,   906,
     872,   918,   924,   367,   853,   704,   897,   898,   790,   817,
     789,   665,   986,   816,   671,   745,   905,   824,   699,   823,
     565,   504,   302,   545,   510,   508,   908,   656,   815,     0,
       0,     0,     0,     0,     0,   302,   835,   919,     0,   922,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   943,   153,   154,
       0,     0,     0,   954,   955,     0,   513,   514,   155,     0,
       0,   156,   157,   158,   159,   160,   515,     0,   967,     0,
     161,     0,   550,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,   516,     0,   517,     0,   169,   170,
       0,     0,     0,     0,     0,     0,     0,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   518,   229,   230,   231,
     519,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,   520,   521,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,     0,   277,   153,   154,     0,     0,     0,     0,
       0,     0,   513,   514,   155,     0,     0,   156,   157,   158,
     159,   160,   515,     0,     0,     0,   161,     0,     0,   162,
     163,   164,   165,     0,     0,     0,   166,     0,   167,   168,
     516,     0,   517,     0,   169,   170,     0,     0,     0,     0,
       0,     0,     0,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   518,   229,   230,   231,   519,   232,   233,   234,
       0,   235,   236,   237,   238,     0,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
     520,   521,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   268,
     269,   270,   271,   272,   273,   274,   275,   276,     0,   277,
     378,   379,     0,     0,     0,     0,     0,     0,     0,     0,
     380,     7,     8,   381,   382,   158,   159,   383,     0,    12,
       0,     0,   384,     0,     0,   385,   163,   386,   387,     0,
       0,     0,   166,    18,   388,   389,     0,     0,     0,     0,
     390,   391,     0,     0,     0,     0,     0,     0,     0,   392,
       0,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,    81,   450,
     451,   452,     0,   453,   454,   455,     0,   456,   457,   458,
     459,    92,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   105,   472,     0,     0,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   123,   489,   490,   491,   492,   493,
     494,   495,   496,   497,     0,   498,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,   156,
     157,   158,   159,   160,     0,     0,     0,   640,   161,     0,
       0,   162,   163,   164,   165,     0,     0,     0,   166,   641,
     167,   168,     0,     0,   642,     0,   169,   170,     0,   643,
       0,     0,     0,   644,   645,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     0,   229,   230,   231,     0,   232,
     233,   234,     0,   235,   646,   237,   238,   647,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   648,   274,   275,   276,
       0,   277,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     9,    10,     0,     0,    11,
       0,    12,     0,     0,    13,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,    18,    19,    20,     0,     0,
       0,     0,    21,    22,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,    23,     0,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,    86,    87,     0,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   134,   153,   154,     0,     0,     0,     0,
       0,     0,     0,     0,   155,     0,     0,   156,   157,   158,
     159,   160,     0,     0,     0,   640,   161,     0,     0,   162,
     163,   164,   165,     0,     0,     0,   166,   641,   167,   168,
       0,     0,   642,     0,   169,   170,     0,     0,     0,     0,
       0,     0,     0,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
       0,   235,   236,   237,   238,   647,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       0,     0,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   268,
     269,   270,   271,   272,   273,   274,   275,   276,     0,   277,
     153,   154,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,   156,   157,   158,   159,   160,     0,   298,
       0,     0,   161,     0,     0,   162,   163,   164,   165,     0,
       0,     0,   166,     0,   167,   168,     0,     0,     0,     0,
     169,   170,     0,     0,     0,     0,     0,     0,     0,   171,
     299,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,     0,   235,   236,   237,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,   251,     0,     0,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,     0,   268,   269,   270,   271,   272,
     273,   274,   275,   276,     0,   277,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,   156,
     157,   158,   159,   160,     0,     0,     0,     0,   161,     0,
       0,   162,   529,   164,   165,     0,     0,     0,   166,     0,
     167,   168,     0,     0,     0,     0,   169,   170,     0,     0,
       0,   530,     0,     0,     0,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     0,   229,   230,   231,     0,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     531,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
       0,   277,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,   155,     0,     0,   156,   157,   158,   159,   160,
       0,     0,     0,     0,   161,     0,     0,   162,   163,   164,
     165,     0,     0,     0,   166,     0,   167,   168,     0,   637,
       0,     0,   169,   170,     0,     0,     0,     0,     0,     0,
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
     262,   263,   264,   265,   266,   267,   638,   268,   269,   270,
     271,   272,   273,   274,   275,   276,     0,   277,   153,   154,
       0,     0,     0,     0,     0,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,   160,     0,     0,     0,     0,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,   311,     0,   169,   170,
       0,     0,     0,     0,     0,     0,     0,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     0,   229,   230,   231,
       0,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,     0,   277,   153,   154,     0,     0,     0,     0,
       0,     0,     0,     0,   155,     0,     0,   156,   157,   158,
     159,   160,     0,   298,     0,     0,   161,     0,     0,   162,
     163,   164,   165,     0,     0,     0,   166,     0,   167,   168,
       0,     0,     0,     0,   169,   170,     0,     0,     0,     0,
       0,     0,     0,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
       0,   235,   236,   237,   238,     0,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       0,     0,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   268,
     269,   270,   271,   272,   273,   274,   275,   276,     0,   277,
     153,   154,     0,     0,     0,     0,     0,     0,     0,     0,
     318,     0,     0,   156,   157,   158,   319,   160,     0,   298,
       0,     0,   161,     0,     0,   162,   163,   164,   165,     0,
       0,     0,   166,     0,   167,   168,     0,     0,     0,     0,
     169,   170,     0,     0,     0,     0,     0,     0,     0,   171,
       0,   172,   173,   320,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,     0,   235,   236,   237,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   321,     0,   251,     0,     0,   252,   322,
     323,   255,   256,   257,   258,   259,   260,   261,   324,   325,
     264,   265,   266,   267,     0,   268,   269,   270,   271,   272,
     273,   274,   275,   276,     0,   277,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,   156,
     157,   158,   159,   160,     0,   598,     0,     0,   161,     0,
       0,   162,   163,   164,   165,     0,     0,     0,   166,     0,
     167,   168,     0,     0,     0,     0,   169,   170,     0,     0,
       0,     0,     0,     0,     0,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     0,   229,   230,   231,     0,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
       0,   277,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,   155,     0,     0,   156,   157,   158,   159,   160,
       0,     0,     0,     0,   161,     0,     0,   162,   163,   164,
     165,     0,     0,     0,   166,     0,   167,   168,     0,     0,
       0,     0,   169,   170,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   783,     0,     0,     0,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     0,   229,   230,   231,
       0,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,     0,   277,   153,   154,     0,     0,     0,     0,
       0,     0,     0,     0,   155,     0,     0,   156,   157,   158,
     159,   160,     0,     0,     0,     0,   161,     0,     0,   162,
     163,   164,   165,     0,     0,     0,   166,     0,   167,   168,
       0,     0,     0,     0,   169,   170,     0,     0,     0,   785,
       0,     0,     0,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
       0,   235,   236,   237,   238,     0,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       0,     0,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   268,
     269,   270,   271,   272,   273,   274,   275,   276,     0,   277,
     153,   154,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,   156,   157,   158,   159,   160,     0,     0,
       0,     0,   161,     0,     0,   162,   163,   164,   165,     0,
       0,     0,   166,     0,   167,   168,     0,     0,     0,     0,
     169,   170,     0,     0,     0,   834,     0,     0,     0,   171,
       0,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,     0,   235,   236,   237,
     238,     0,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,     0,   251,     0,     0,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,     0,   268,   269,   270,   271,   272,
     273,   274,   275,   276,     0,   277,   153,   154,     0,     0,
       0,     0,     0,     0,     0,     0,   155,     0,     0,   156,
     157,   158,   159,   160,     0,     0,     0,     0,   161,     0,
       0,   162,   163,   164,   165,     0,     0,     0,   166,     0,
     167,   168,     0,     0,     0,     0,   169,   170,     0,     0,
       0,     0,     0,     0,     0,   171,     0,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,     0,   229,   230,   231,     0,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
       0,   277,   153,   154,     0,     0,     0,     0,     0,     0,
       0,     0,   318,     0,     0,   156,   157,   158,   319,   160,
       0,     0,     0,     0,   161,     0,     0,   162,   163,   164,
     165,     0,     0,     0,   166,     0,   167,   168,     0,     0,
       0,     0,   169,   170,     0,     0,     0,     0,     0,     0,
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
       0,   156,   157,   158,   159,   160,     0,     0,     0,     0,
     161,     0,     0,   162,   626,   164,   165,     0,     0,     0,
     166,     0,   167,   168,     0,     0,     0,     0,   169,   170,
       0,     0,     0,     0,     0,     0,     0,   171,     0,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,     0,   229,   230,   231,
       0,   232,   233,   234,     0,   235,   236,   237,   238,     0,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     0,   251,     0,     0,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   269,   270,   271,   272,   273,   274,
     275,   276,     0,   277,   153,   154,     0,     0,     0,     0,
       0,     0,     0,     0,   155,     0,     0,   156,   157,   158,
     159,   160,     0,     0,     0,     0,   161,     0,     0,   162,
     163,   164,   165,     0,     0,     0,   166,     0,   167,   168,
       0,     0,     0,     0,   169,   916,     0,     0,     0,     0,
       0,     0,     0,   171,     0,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
       0,   235,   236,   237,   238,     0,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,     0,   251,
       0,     0,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   268,
     269,   270,   271,   272,   273,   274,   275,   276,     0,   277
};

static const yytype_int16 yycheck[] =
{
     144,   145,   303,   306,   289,   149,     8,     9,   585,    46,
      29,   588,   810,    27,    60,    37,    37,    72,   303,     8,
       9,    37,   576,     9,   327,     9,   327,    46,    46,   545,
      90,    29,    30,    29,    30,    28,   341,   287,   600,   507,
      45,   509,    47,    45,     0,    82,    28,    21,    46,   299,
      46,    53,    54,    55,    56,    51,    45,   619,   856,    29,
      40,   577,    44,    38,    82,    58,   369,    38,    49,   537,
      72,   376,    58,   128,    58,    52,    90,    58,   655,    23,
      24,    58,    58,    72,    46,    55,    56,   109,   109,   643,
     644,   645,   646,   109,   947,   948,   115,   143,   158,    43,
     160,   161,   570,   163,   164,    52,    52,   167,    40,    52,
     578,    58,    58,   911,    90,    58,    41,   970,   971,   121,
     122,   123,   159,    41,   126,   127,   128,    25,   130,   131,
     126,   129,   121,   129,    37,    38,    39,   126,   127,   128,
      93,   130,   131,   287,   158,   289,   160,   161,    52,   163,
     164,    93,   296,   167,    58,   299,   710,   734,    20,   303,
      23,    24,   306,   165,   718,   719,   720,   721,   722,   723,
     724,   725,   726,   727,   728,    42,   730,   149,   150,   151,
      52,   735,   158,   327,   160,   161,    58,   163,   164,    29,
      42,   167,   336,   337,   338,   339,   149,   150,   151,   343,
     153,   154,   155,    36,   507,    29,   509,   149,   150,   151,
     152,   153,   154,   155,    45,    48,    22,    50,    19,   363,
     149,   150,   151,   152,    29,   369,   370,   144,   145,   107,
     108,   375,   171,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    31,    82,
      39,   122,   123,   807,    45,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    16,   578,   964,   965,     8,    57,
       8,     9,    46,   860,   117,   118,   119,    29,    30,   574,
     575,   324,   325,    51,   158,    47,   597,   146,    29,    41,
      37,    39,    58,   857,    46,    39,    39,    39,    51,   863,
      39,    47,    39,    55,    56,    39,    39,    45,    39,    39,
      39,    39,    39,    39,    52,    53,    54,    55,    56,   132,
     133,   134,   135,   136,   137,   138,   169,   170,    39,    39,
     173,    39,    39,    39,    72,   132,   133,   134,   135,   136,
     137,   138,   637,    39,    39,    39,    39,    39,    39,     8,
       9,   505,    39,   507,    39,   509,    39,    39,    39,    39,
      39,    39,     8,     9,    39,    39,    39,    39,    39,   523,
      39,    39,    39,    39,   528,    39,   530,    39,    39,    39,
      29,    39,   536,   121,   122,   123,    45,    39,   126,   127,
     128,    39,   130,   131,    53,    54,    55,    56,    39,    45,
     554,    39,    39,    39,    39,    39,   560,    53,    54,    55,
      56,    39,    39,    72,   568,    39,    39,    39,    39,    16,
     574,   575,   717,    39,   578,    45,    72,    39,    39,    39,
      39,    39,    39,    53,    54,    55,    56,    39,    39,   593,
      39,    39,    29,    39,    39,    39,    39,   601,    39,    39,
      39,    39,    72,    39,    39,    39,    39,   752,   612,    39,
      39,    39,   121,   122,   123,    39,    39,   126,   127,   128,
     624,   130,   131,    39,    39,   121,   122,   123,    39,    39,
     126,   127,   128,   637,   130,   131,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   121,   122,   123,    39,    39,   126,   127,   128,    39,
     130,   131,    39,    39,    39,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    39,   972,   973,   974,
     975,   976,    39,   978,    39,    39,    39,    39,   125,    39,
      39,    39,    39,    39,    39,    39,    39,   701,   702,    39,
     704,   705,   997,    39,   999,    39,  1001,    39,    39,    39,
      39,  1006,    39,   717,   111,   112,   113,   114,    39,    39,
      39,    26,    26,    39,   869,    53,    51,    39,    42,    29,
     126,     8,    29,    27,    52,    41,    60,    28,    51,   109,
      39,    58,    45,   140,    39,   749,   152,    58,   752,   753,
      59,    52,    39,    46,    29,    51,    29,    29,   109,    51,
      46,    51,    51,    51,    29,    28,    51,   109,    25,   110,
      72,    45,   139,    29,    45,    45,    45,    45,    45,    45,
      58,    45,    58,    45,    45,   166,    29,    39,    72,    72,
      29,    51,    45,    52,    52,    45,    29,    52,    46,    46,
      51,    46,    46,    39,    46,    46,   810,    39,    39,    58,
      45,    39,    52,    29,    29,    52,    30,    30,    52,    46,
      46,    51,     1,   303,   523,   123,   141,   282,   869,   851,
     834,   870,   890,   327,   788,   628,   840,   841,   705,   740,
     704,   594,   963,   739,   609,   688,   850,   746,   624,   744,
     536,   344,   856,   509,   361,   352,   856,   578,   738,    -1,
      -1,    -1,    -1,    -1,    -1,   869,   870,   871,    -1,   873,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   911,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   921,     8,     9,
      -1,    -1,    -1,   927,   928,    -1,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    -1,   942,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,    -1,    46,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    -1,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,
      44,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    48,    49,    -1,    51,
      -1,    -1,    -1,    55,    56,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    -1,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,   121,   122,   123,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,   121,   122,   123,    -1,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,    45,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,    -1,   121,   122,   123,    -1,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    46,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,   118,   119,
      -1,   121,   122,   123,    -1,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,    -1,   121,   122,   123,    -1,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,   118,   119,
      -1,   121,   122,   123,    -1,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,    -1,   121,   122,   123,    -1,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,   118,   119,
      -1,   121,   122,   123,    -1,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   175,   176,     8,     9,    18,    19,    20,    21,
      22,    25,    27,    30,    33,    34,    35,    36,    41,    42,
      43,    48,    49,    57,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   121,   122,   123,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   177,   179,   307,     0,    23,
      24,   180,   181,    40,    38,    38,    40,    46,   182,    43,
     181,   199,    41,     8,     9,    18,    21,    22,    23,    24,
      25,    30,    33,    34,    35,    36,    40,    42,    43,    48,
      49,    57,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   117,
     118,   119,   121,   122,   123,   125,   126,   127,   128,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   143,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   173,   178,   308,
     178,    41,   183,    25,   184,   189,   178,   200,   201,    20,
     204,    42,    42,   184,    29,   185,    45,   202,    27,    58,
     190,   201,   178,   205,   206,   245,    19,   228,    22,   171,
     188,    46,   178,   203,   201,   190,   206,   207,    18,    24,
      61,   141,   147,   148,   156,   157,   178,   229,   230,   231,
     271,   276,   278,   294,    29,    31,    39,    37,    38,    39,
      45,   208,   209,     8,   272,   273,    57,    46,    51,   149,
     150,   151,   288,   290,    93,   149,   150,   151,   153,   154,
     155,   289,   291,   158,   295,   295,   190,   230,    47,   146,
     186,   178,   178,   178,   178,   210,    47,   209,     8,     9,
      18,    21,    22,    25,    30,    33,    35,    36,    42,    43,
      48,    49,    57,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     117,   118,   119,   121,   122,   123,   125,   126,   127,   128,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   143,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   173,   177,
     274,   275,   276,   277,   273,   232,    29,   152,   290,   152,
     291,   178,   276,    16,    17,    26,    44,    46,   116,   120,
     144,   145,   178,   191,   192,   193,   194,   195,    37,    34,
      53,   142,   178,   215,   209,     9,    58,    39,   178,   236,
      58,   276,   277,   292,   293,   292,    51,    47,   235,   196,
      32,   193,    16,   178,    39,   178,    60,   143,   213,   214,
      39,    26,   212,    53,   234,   275,   277,    26,    51,    29,
      39,    58,    90,   160,   161,   163,   164,   167,   238,   279,
     280,   282,   283,   284,   285,   286,   287,   295,   286,   296,
     144,   145,   197,   242,   243,   244,   246,   187,    27,   178,
     241,    39,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   111,   112,   113,   114,   140,   248,    42,
     126,   178,    29,   211,     8,    29,    34,   178,   237,   239,
     240,    52,   277,    46,    82,   159,   245,    45,   162,   245,
      29,    41,    46,    51,    55,    56,   126,   129,   168,   178,
     245,   300,   303,   304,   305,   286,   293,   279,   297,   298,
     299,   300,    28,    44,   178,   244,   190,   213,   178,    51,
     252,   252,   132,   133,   134,   135,   136,   137,   138,   259,
     260,   262,   132,   133,   134,   135,   136,   137,   138,   253,
     256,   257,   178,   213,    41,    28,    58,    58,   222,   274,
      28,    39,    39,    52,   238,    59,   109,    46,    46,    82,
      45,   162,   245,   300,   300,   300,   300,   152,     8,     9,
      45,    53,    54,    55,    56,    72,   121,   122,   123,   126,
     127,   128,   130,   131,   165,    51,    27,    52,    58,   198,
     247,    29,    51,   263,   109,   263,   109,    51,   254,    39,
      29,    36,    48,    50,    82,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   117,   118,   119,   169,   170,   173,
     223,   224,     9,    53,   178,    53,   178,   110,   233,   240,
     239,    51,    46,   300,    52,   245,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,    72,   128,   300,
      51,   279,   300,   301,   302,   299,   246,   242,    52,    58,
      29,   255,   261,   262,   257,   258,    29,   178,    28,    25,
     216,   217,   218,   245,    53,   178,   220,    45,    45,    45,
      72,    72,    45,    45,    45,    45,   107,   108,    45,    45,
      45,    58,   139,   235,    29,   300,    51,   123,   305,   306,
     166,   281,    52,    58,    29,    52,    52,    45,    49,    58,
     221,    45,   178,    39,    29,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     226,   227,    46,    29,    46,   115,   225,   178,   178,    46,
      51,    46,    46,    46,    46,   178,   224,    58,   306,   300,
      52,    58,   279,   300,    52,    29,    49,   217,   220,   178,
     219,    39,   178,   125,   227,   264,   265,    39,    39,    16,
      29,    30,    41,    46,    55,    56,   249,   250,   251,    29,
      52,   305,    39,   178,    29,    30,    46,    51,   126,   129,
     266,   267,   268,   269,   178,   178,    37,   109,    37,   109,
      29,    29,    52,    58,    37,   109,    52,   178,   267,   267,
     122,   123,     8,     9,    45,    72,   121,   126,   127,   128,
     130,   131,    30,    30,    46,    46,   251,   250,   250,    52,
     267,   267,   268,   268,   268,   268,   268,    72,   268,    51,
     268,   123,   268,   270,   268,    52,    58,   268
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
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 102:
#line 655 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
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
	   struct s_lookup  *l;
	   struct s_lookups *ls;
           l=malloc(sizeof(struct s_lookup));
           l->fieldtag=strdup("<<FROM>>");
           l->tabcol=strdup((yyvsp[(2) - (2)].str));

	   ls=malloc(sizeof(s_lookups));
	   ls->lookups.lookups_len=0;
	   ls->lookups.lookups_val=0;

	   ls->lookups.lookups_len++;
	   ls->lookups.lookups_val=realloc(ls->lookups.lookups_val, sizeof(ls->lookups.lookups_val[0])*ls->lookups.lookups_len);
  	   ls->lookups.lookups_val[ls->lookups.lookups_len-1]=l;
	   ls->joincol="<<FROM>>";

	   fld->lookup.lookups.lookups_len++;
	   fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	   fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=ls;


}
    break;

  case 112:
#line 714 "screen.yacc"
    {
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 113:
#line 720 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 114:
#line 721 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 115:
#line 722 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 116:
#line 723 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 117:
#line 724 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 118:
#line 725 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 119:
#line 726 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 120:
#line 727 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 121:
#line 728 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 122:
#line 729 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 123:
#line 730 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 124:
#line 731 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 125:
#line 732 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 126:
#line 733 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 127:
#line 734 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 128:
#line 735 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 129:
#line 736 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 130:
#line 737 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 131:
#line 738 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 132:
#line 739 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 133:
#line 740 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 134:
#line 741 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REQUIRED); }
    break;

  case 135:
#line 742 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REVERSE); }
    break;

  case 136:
#line 743 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 137:
#line 744 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_QUERYCLEAR); }
    break;

  case 138:
#line 745 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_ZEROFILL); }
    break;

  case 139:
#line 746 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_RIGHT); }
    break;

  case 140:
#line 747 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WORDWRAP); }
    break;

  case 141:
#line 748 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 142:
#line 752 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 143:
#line 758 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 144:
#line 759 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 145:
#line 760 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 147:
#line 765 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 148:
#line 769 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 149:
#line 770 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 150:
#line 771 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 151:
#line 772 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 152:
#line 773 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 153:
#line 774 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 154:
#line 775 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 155:
#line 776 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 156:
#line 778 "screen.yacc"
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

  case 157:
#line 792 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 158:
#line 793 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 159:
#line 794 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 160:
#line 795 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 161:
#line 796 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 162:
#line 797 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 163:
#line 798 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 170:
#line 811 "screen.yacc"
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

  case 171:
#line 821 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 172:
#line 827 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 179:
#line 838 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 180:
#line 838 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 183:
#line 843 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 184:
#line 846 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 185:
#line 852 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 186:
#line 855 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 189:
#line 865 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),""); }
    break;

  case 190:
#line 867 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); }
    break;

  case 191:
#line 869 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); }
    break;

  case 192:
#line 871 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); }
    break;

  case 193:
#line 873 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 195:
#line 877 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 196:
#line 881 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 197:
#line 884 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 198:
#line 888 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:
#line 888 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 202:
#line 895 "screen.yacc"
    {colno++;}
    break;

  case 203:
#line 896 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 204:
#line 909 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 205:
#line 917 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 206:
#line 919 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 207:
#line 926 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 208:
#line 930 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 209:
#line 934 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 210:
#line 938 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 211:
#line 942 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 212:
#line 946 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 213:
#line 950 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 214:
#line 956 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 215:
#line 960 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 216:
#line 964 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 217:
#line 968 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 218:
#line 972 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 219:
#line 976 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 220:
#line 980 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 221:
#line 983 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 223:
#line 990 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 226:
#line 995 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 227:
#line 1000 "screen.yacc"
    { 
	if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
		sprintf((yyval.str),"NULL");
	} else {
		strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
	}
}
    break;

  case 228:
#line 1007 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 229:
#line 1008 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 230:
#line 1009 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 231:
#line 1010 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 233:
#line 1012 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 234:
#line 1013 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 235:
#line 1014 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 236:
#line 1018 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 237:
#line 1022 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 238:
#line 1028 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 239:
#line 1031 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 240:
#line 1032 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 241:
#line 1035 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 242:
#line 1037 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 243:
#line 1043 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 244:
#line 1045 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 245:
#line 1050 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 246:
#line 1058 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 247:
#line 1061 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 248:
#line 1062 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 249:
#line 1063 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 250:
#line 1064 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 251:
#line 1065 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 252:
#line 1066 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 253:
#line 1068 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 255:
#line 1075 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 256:
#line 1076 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 257:
#line 1079 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 258:
#line 1082 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 259:
#line 1086 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 260:
#line 1087 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 261:
#line 1088 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 262:
#line 1089 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 263:
#line 1090 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 264:
#line 1091 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 265:
#line 1093 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 266:
#line 1098 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 267:
#line 1100 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 268:
#line 1107 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 269:
#line 1107 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 270:
#line 1113 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 272:
#line 1120 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 273:
#line 1123 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 274:
#line 1129 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 275:
#line 1130 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 276:
#line 1131 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 277:
#line 1132 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 278:
#line 1133 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 279:
#line 1134 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 280:
#line 1135 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 281:
#line 1136 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 282:
#line 1137 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 283:
#line 1138 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 284:
#line 1139 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 285:
#line 1140 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 286:
#line 1141 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 287:
#line 1144 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 288:
#line 1151 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 289:
#line 1152 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 290:
#line 1153 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 292:
#line 1161 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 293:
#line 1165 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 297:
#line 1185 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 298:
#line 1195 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 299:
#line 1202 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 300:
#line 1211 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 301:
#line 1214 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 304:
#line 1233 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 305:
#line 1240 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 306:
#line 1248 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 307:
#line 1253 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 308:
#line 1261 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 309:
#line 1265 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 310:
#line 1270 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 311:
#line 1275 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 312:
#line 1280 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 313:
#line 1285 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 314:
#line 1290 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 315:
#line 1299 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 316:
#line 1308 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 317:
#line 1309 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 319:
#line 1318 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 320:
#line 1326 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 321:
#line 1332 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 322:
#line 1338 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 323:
#line 1344 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 324:
#line 1352 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 325:
#line 1357 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 326:
#line 1367 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 327:
#line 1377 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 328:
#line 1383 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 329:
#line 1389 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 330:
#line 1395 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 331:
#line 1405 "screen.yacc"
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

  case 332:
#line 1417 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 333:
#line 1425 "screen.yacc"
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

  case 334:
#line 1437 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 335:
#line 1445 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 336:
#line 1446 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 337:
#line 1447 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 338:
#line 1451 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 339:
#line 1452 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 340:
#line 1453 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 341:
#line 1454 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 342:
#line 1455 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 343:
#line 1456 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 344:
#line 1457 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 345:
#line 1460 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 346:
#line 1467 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 347:
#line 1478 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 348:
#line 1482 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 349:
#line 1489 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 350:
#line 1497 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 351:
#line 1502 "screen.yacc"
    {
		if ((yyvsp[(5) - (6)].el)) {
			listitem *l;
			(yyval.fcall)->list_parameters.list_parameters_len=(yyvsp[(5) - (6)].el)->nlist;
			l=(yyvsp[(5) - (6)].el)->expr_list;
			(yyval.fcall)->list_parameters.list_parameters_val=l;
		}
	}
    break;

  case 352:
#line 1513 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 353:
#line 1514 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 354:
#line 1520 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 355:
#line 1526 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 356:
#line 1534 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 358:
#line 1542 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 359:
#line 1543 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 364:
#line 1557 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 365:
#line 1559 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 366:
#line 1560 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 367:
#line 1561 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 368:
#line 1562 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 369:
#line 1563 "screen.yacc"
    { (yyval.expr)=(yyvsp[(3) - (4)].expr); }
    break;

  case 370:
#line 1564 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 371:
#line 1565 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 372:
#line 1566 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 373:
#line 1567 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 374:
#line 1568 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 375:
#line 1569 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 376:
#line 1570 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 377:
#line 1571 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 378:
#line 1572 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 379:
#line 1573 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 380:
#line 1574 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 381:
#line 1575 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 382:
#line 1576 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 383:
#line 1577 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 384:
#line 1578 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 385:
#line 1579 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 387:
#line 1585 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 388:
#line 1586 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 389:
#line 1587 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 390:
#line 1588 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 391:
#line 1589 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 392:
#line 1592 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 393:
#line 1596 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 5768 "y.tab.c"
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


#line 1871 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




