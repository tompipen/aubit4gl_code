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
     KW_ACTION = 428,
     KW_PAGE = 429,
     KW_HBOX = 430,
     KW_VBOX = 431,
     KW_GRID = 432,
     KW_GROUP = 433,
     KW_TABLE = 434,
     KW_FOLDER = 435,
     KW_STYLE = 436,
     KW_LAYOUT = 437,
     KW_HIDDEN = 438,
     KW_TEXTEDIT = 439,
     KW_BUTTONEDIT = 440,
     KW_LABEL = 441,
     KW_EDIT = 442,
     KW_DATEEDIT = 443,
     KW_SCROLL = 444,
     KW_IMAGE = 445,
     KW_FONTPITCH = 446,
     KW_FIXED = 447,
     KW_VARIABLE = 448,
     KW_WANTNORETURNS = 449,
     KW_WANTTABS = 450,
     KW_AUTOSCALE = 451,
     KW_PIXELWIDTH = 452,
     KW_PIXELHEIGHT = 453,
     KW_SCROLLBARS_BOTH = 454,
     KW_SCROLLBARS_V = 455,
     KW_SCROLLBARS_H = 456,
     KW_STRETCH_Y = 457,
     KW_STRETCH_BOTH = 458,
     KW_ITEMS = 459,
     KW_VALUEMAX = 460,
     KW_VALUEMIN = 461,
     KW_PROGRESSBAR = 462,
     KW_COMBOBOX = 463,
     OPTIONS = 464,
     KW_BROWSER = 465
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
#define KW_PAGE 429
#define KW_HBOX 430
#define KW_VBOX 431
#define KW_GRID 432
#define KW_GROUP 433
#define KW_TABLE 434
#define KW_FOLDER 435
#define KW_STYLE 436
#define KW_LAYOUT 437
#define KW_HIDDEN 438
#define KW_TEXTEDIT 439
#define KW_BUTTONEDIT 440
#define KW_LABEL 441
#define KW_EDIT 442
#define KW_DATEEDIT 443
#define KW_SCROLL 444
#define KW_IMAGE 445
#define KW_FONTPITCH 446
#define KW_FIXED 447
#define KW_VARIABLE 448
#define KW_WANTNORETURNS 449
#define KW_WANTTABS 450
#define KW_AUTOSCALE 451
#define KW_PIXELWIDTH 452
#define KW_PIXELHEIGHT 453
#define KW_SCROLLBARS_BOTH 454
#define KW_SCROLLBARS_V 455
#define KW_SCROLLBARS_H 456
#define KW_STRETCH_Y 457
#define KW_STRETCH_BOTH 458
#define KW_ITEMS 459
#define KW_VALUEMAX 460
#define KW_VALUEMIN 461
#define KW_PROGRESSBAR 462
#define KW_COMBOBOX 463
#define OPTIONS 464
#define KW_BROWSER 465




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
	struct  s_layout_attributes  *layout_attrib;
	struct s_layout *layout;
}
/* Line 187 of yacc.c.  */
#line 620 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 633 "y.tab.c"

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
#define YYFINAL  139
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4807

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  211
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  162
/* YYNRULES -- Number of rules.  */
#define YYNRULES  724
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1149

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   465

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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    35,    37,    41,    43,    47,    49,    51,    57,    63,
      69,    75,    77,    80,    86,    87,    89,    90,    91,    92,
     103,   104,   105,   106,   117,   118,   119,   124,   128,   130,
     134,   138,   140,   143,   147,   148,   150,   152,   155,   157,
     159,   161,   163,   165,   167,   171,   173,   176,   177,   181,
     182,   187,   188,   189,   190,   200,   201,   203,   204,   207,
     212,   213,   215,   217,   220,   222,   224,   226,   228,   230,
     232,   234,   236,   238,   240,   242,   244,   247,   248,   253,
     255,   256,   261,   262,   266,   268,   271,   275,   278,   279,
     282,   284,   288,   292,   298,   302,   306,   310,   312,   315,
     316,   318,   320,   322,   324,   326,   328,   330,   332,   334,
     335,   341,   343,   346,   350,   351,   352,   359,   360,   364,
     370,   374,   376,   377,   383,   387,   390,   395,   398,   403,
     407,   409,   414,   417,   419,   423,   427,   429,   433,   435,
     439,   441,   446,   449,   451,   454,   455,   458,   460,   464,
     466,   471,   474,   479,   483,   487,   491,   495,   501,   505,
     511,   513,   515,   519,   525,   529,   533,   537,   539,   544,
     546,   548,   550,   552,   556,   560,   562,   564,   566,   568,
     570,   572,   574,   577,   580,   582,   584,   586,   588,   592,
     596,   598,   602,   606,   610,   612,   614,   616,   618,   620,
     626,   630,   634,   638,   640,   642,   644,   646,   649,   651,
     653,   655,   657,   659,   661,   663,   665,   667,   669,   671,
     673,   675,   677,   679,   681,   682,   686,   688,   691,   693,
     696,   699,   701,   702,   712,   725,   727,   729,   730,   733,
     734,   736,   737,   739,   741,   746,   748,   752,   753,   755,
     757,   761,   765,   769,   773,   775,   779,   781,   783,   784,
     786,   788,   791,   793,   795,   797,   798,   803,   805,   807,
     809,   811,   813,   815,   818,   821,   824,   827,   829,   831,
     833,   835,   837,   839,   843,   845,   849,   851,   854,   857,
     859,   861,   863,   865,   867,   869,   871,   875,   879,   881,
     883,   887,   891,   895,   899,   901,   902,   906,   912,   913,
     917,   918,   922,   924,   927,   929,   931,   933,   935,   937,
     939,   942,   944,   945,   949,   951,   953,   955,   957,   959,
     961,   963,   965,   968,   969,   973,   974,   976,   979,   981,
     985,   989,   993,   997,  1001,  1005,  1010,  1014,  1017,  1020,
    1022,  1028,  1034,  1037,  1041,  1043,  1045,  1047,  1049,  1051,
    1053,  1057,  1060,  1062,  1065,  1073,  1075,  1079,  1083,  1085,
    1087,  1089,  1095,  1101,  1104,  1107,  1109,  1111,  1113,  1115,
    1117,  1119,  1121,  1127,  1128,  1131,  1133,  1138,  1141,  1145,
    1148,  1152,  1156,  1158,  1161,  1164,  1168,  1172,  1177,  1179,
    1182,  1184,  1187,  1189,  1191,  1193,  1195,  1197,  1199,  1201,
    1203,  1205,  1207,  1209,  1213,  1217,  1219,  1224,  1225,  1232,
    1233,  1235,  1237,  1241,  1243,  1245,  1249,  1253,  1254,  1256,
    1258,  1262,  1265,  1268,  1270,  1273,  1277,  1282,  1286,  1290,
    1294,  1298,  1302,  1306,  1310,  1314,  1318,  1323,  1327,  1330,
    1333,  1339,  1345,  1352,  1354,  1356,  1358,  1360,  1362,  1364,
    1366,  1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,  1386,
    1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,  1404,  1406,
    1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,
    1428,  1430,  1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,
    1448,  1450,  1452,  1454,  1456,  1458,  1460,  1462,  1464,  1466,
    1468,  1470,  1472,  1474,  1476,  1478,  1480,  1482,  1484,  1486,
    1488,  1490,  1492,  1494,  1496,  1498,  1500,  1502,  1504,  1506,
    1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,  1524,  1526,
    1528,  1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,
    1548,  1550,  1552,  1554,  1556,  1558,  1560,  1562,  1564,  1566,
    1568,  1570,  1572,  1574,  1576,  1578,  1580,  1582,  1584,  1586,
    1588,  1590,  1592,  1594,  1596,  1598,  1600,  1602,  1604,  1606,
    1608,  1610,  1612,  1614,  1616,  1618,  1620,  1622,  1624,  1626,
    1628,  1630,  1632,  1634,  1636,  1638,  1640,  1642,  1644,  1646,
    1648,  1650,  1652,  1654,  1656,  1658,  1660,  1662,  1664,  1666,
    1668,  1670,  1672,  1674,  1676,  1678,  1680,  1682,  1684,  1686,
    1688,  1690,  1692,  1694,  1696,  1698,  1700,  1702,  1704,  1706,
    1708,  1710,  1712,  1714,  1716,  1718,  1720,  1722,  1724,  1726,
    1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,  1746,
    1748,  1750,  1752,  1754,  1756,  1758,  1760,  1762,  1764,  1766,
    1768,  1770,  1772,  1774,  1776,  1778,  1780,  1782,  1784,  1786,
    1788,  1790,  1792,  1794,  1796,  1798,  1800,  1802,  1804,  1806,
    1808,  1810,  1812,  1814,  1816,  1818,  1820,  1822,  1824,  1826,
    1828,  1830,  1832,  1834,  1836,  1838,  1840,  1842,  1844,  1846,
    1848,  1850,  1852,  1854,  1856,  1858,  1860,  1862,  1864,  1866,
    1868,  1870,  1872,  1874,  1876
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     212,     0,    -1,   213,   217,   260,   265,   290,    -1,    21,
      34,    -1,    21,   216,    40,    41,    42,    -1,    21,    34,
      40,    41,    42,    -1,    21,   216,    -1,    30,    -1,   371,
      -1,    30,    -1,   372,    -1,   172,    -1,   172,    38,   215,
      -1,   214,    -1,   214,    38,   215,    -1,   241,    -1,   240,
      -1,   176,   224,   233,   237,    27,    -1,   175,   224,   233,
     237,    27,    -1,   178,   224,   233,   237,    27,    -1,   180,
     224,   233,   222,    27,    -1,   223,    -1,   222,   223,    -1,
     174,   224,   233,   237,    27,    -1,    -1,   215,    -1,    -1,
      -1,    -1,   177,   226,   224,   233,    31,   227,   252,    32,
     228,    27,    -1,    -1,    -1,    -1,   179,   230,   224,   233,
      31,   231,   252,    32,   232,    27,    -1,    -1,    -1,    51,
     234,   236,    52,    -1,   181,    45,    46,    -1,   183,    -1,
     113,    45,    46,    -1,   173,    45,    30,    -1,   235,    -1,
     236,   235,    -1,   236,    58,   235,    -1,    -1,   238,    -1,
     239,    -1,   238,   239,    -1,   218,    -1,   219,    -1,   220,
      -1,   221,    -1,   225,    -1,   229,    -1,   182,   239,   251,
      -1,   242,    -1,   241,   242,    -1,    -1,    24,   243,   245,
      -1,    -1,    23,    46,   244,   245,    -1,    -1,    -1,    -1,
     250,   246,   249,    31,   247,   252,    32,   248,   251,    -1,
      -1,   171,    -1,    -1,    25,    29,    -1,    25,    29,    22,
      29,    -1,    -1,    27,    -1,   254,    -1,   252,   254,    -1,
     215,    -1,   253,    -1,   256,    -1,   145,    -1,    17,    -1,
      44,    -1,    46,    -1,   255,    -1,   144,    -1,   120,    -1,
     116,    -1,    16,    -1,   255,    16,    -1,    -1,    26,   257,
     258,    28,    -1,   308,    -1,    -1,   258,    44,   259,   308,
      -1,    -1,    43,   261,   251,    -1,   262,    -1,   261,   262,
      -1,   261,    58,   262,    -1,   215,   263,    -1,    -1,    45,
     264,    -1,   215,    -1,   215,    37,   215,    -1,   215,    38,
     215,    -1,   215,    38,   215,    37,   215,    -1,   215,    39,
     215,    -1,    46,    39,   215,    -1,    20,   266,   251,    -1,
     268,    -1,   266,   268,    -1,    -1,   187,    -1,   184,    -1,
     186,    -1,   188,    -1,   185,    -1,   190,    -1,   207,    -1,
     208,    -1,   210,    -1,    -1,   267,   307,   269,   270,    47,
      -1,   271,    -1,   270,   271,    -1,   270,    47,   271,    -1,
      -1,    -1,    45,   272,   277,   274,   273,   284,    -1,    -1,
      26,    29,    28,    -1,    26,    29,    58,    29,    28,    -1,
     276,   126,    41,    -1,   276,    -1,    -1,    60,    72,   215,
      39,   215,    -1,    60,    72,   215,    -1,    60,   310,    -1,
      34,    39,   303,   275,    -1,   142,   275,    -1,   142,   143,
      42,   275,    -1,   215,    39,   215,    -1,   215,    -1,    53,
     215,    39,   215,    -1,    53,   215,    -1,   279,    -1,   278,
      58,   279,    -1,   280,    45,   281,    -1,   307,    -1,   215,
      39,   215,    -1,   215,    -1,   215,    39,   215,    -1,   215,
      -1,    53,   215,    39,   215,    -1,    53,   215,    -1,    49,
      -1,    58,    49,    -1,    -1,    58,   285,    -1,   286,    -1,
     285,    58,   286,    -1,    88,    -1,    89,    45,   288,   328,
      -1,    50,   282,    -1,    48,   278,   283,   282,    -1,    90,
      45,    46,    -1,    91,    45,   287,    -1,   209,    45,   287,
      -1,    93,    72,   215,    -1,    93,    72,   215,    39,   215,
      -1,    92,    72,   215,    -1,    92,    72,   215,    39,   215,
      -1,    94,    -1,    95,    -1,    96,    45,    46,    -1,    97,
      45,    51,   311,    52,    -1,   118,    45,    46,    -1,   119,
      45,    46,    -1,   173,    45,   215,    -1,    98,    -1,    36,
      25,    45,    29,    -1,    36,    -1,   117,    -1,   100,    -1,
      99,    -1,   101,    45,    46,    -1,   102,    45,    46,    -1,
     103,    -1,    82,    -1,   105,    -1,   104,    -1,   170,    -1,
     169,    -1,   106,    -1,   106,   107,    -1,   106,   108,    -1,
     183,    -1,   196,    -1,   194,    -1,   195,    -1,   191,    45,
     192,    -1,   191,    45,   193,    -1,   189,    -1,   190,    45,
      46,    -1,   198,    45,    29,    -1,   197,    45,    29,    -1,
     199,    -1,   200,    -1,   201,    -1,   202,    -1,   203,    -1,
     204,    45,    51,   312,    52,    -1,   205,    45,    29,    -1,
     206,    45,    29,    -1,   181,    45,    46,    -1,    46,    -1,
      29,    -1,   115,    -1,   289,    -1,   288,   289,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    29,    -1,    82,    -1,    87,
      -1,    81,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    -1,    19,   291,   251,    -1,   292,    -1,   291,   292,
      -1,   293,    -1,   293,    47,    -1,    61,    46,    -1,   342,
      -1,    -1,    24,    57,   294,   298,    51,   299,    52,   295,
     297,    -1,   141,    51,    29,    58,    29,    52,   109,    51,
      29,    58,    29,    52,    -1,   335,    -1,   358,    -1,    -1,
     110,   139,    -1,    -1,    53,    -1,    -1,    47,    -1,   215,
      -1,   215,    26,    29,    28,    -1,   302,    -1,   299,   300,
     302,    -1,    -1,    58,    -1,   215,    -1,   215,    39,   215,
      -1,    34,    39,   215,    -1,   215,    39,    53,    -1,    34,
      39,    53,    -1,   301,    -1,   301,    59,   301,    -1,   215,
      -1,    27,    -1,    -1,   305,    -1,   306,    -1,   305,   306,
      -1,   144,    -1,   145,    -1,   215,    -1,    -1,   304,   215,
     309,   304,    -1,    62,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    67,    -1,    68,   316,    -1,    69,   316,
      -1,    70,   323,    -1,    71,   317,    -1,   111,    -1,   112,
      -1,   113,    -1,   114,    -1,   140,    -1,   315,    -1,   311,
      58,   315,    -1,   314,    -1,   312,    58,   314,    -1,    29,
      -1,    55,    29,    -1,    56,    29,    -1,    46,    -1,    30,
      -1,    16,    -1,   313,    -1,    41,    -1,    46,    -1,    30,
      -1,    30,   109,    30,    -1,    30,    37,    30,    -1,    16,
      -1,   313,    -1,   313,   109,   313,    -1,   313,    37,   313,
      -1,    46,   109,    46,    -1,    46,    37,    46,    -1,    41,
      -1,    -1,    51,    29,    52,    -1,    51,    29,    58,    29,
      52,    -1,    -1,   320,   109,   322,    -1,    -1,    51,    29,
      52,    -1,    29,    -1,   321,   318,    -1,   132,    -1,   133,
      -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,
     327,    -1,   321,    -1,    -1,   324,   109,   325,    -1,   326,
      -1,   326,    -1,   132,    -1,   133,    -1,   134,    -1,   135,
      -1,   136,    -1,   137,    -1,   138,   327,    -1,    -1,    51,
     319,    52,    -1,    -1,   329,    -1,   125,   330,    -1,   331,
      -1,   331,   123,   331,    -1,   331,   122,   331,    -1,   332,
     121,   332,    -1,   332,     8,   332,    -1,   332,     9,   332,
      -1,   332,    72,   332,    -1,   332,   126,    72,   332,    -1,
     332,    45,   332,    -1,   332,   130,    -1,   332,   131,    -1,
     332,    -1,   332,   127,   332,   123,   332,    -1,   332,   128,
      51,   334,    52,    -1,   126,   331,    -1,    51,   331,    52,
      -1,   333,    -1,    29,    -1,    46,    -1,   129,    -1,    30,
      -1,   332,    -1,   334,    58,   332,    -1,    18,   336,    -1,
     337,    -1,   336,   337,    -1,     8,   338,     9,   296,     8,
     338,     9,    -1,   339,    -1,   338,    58,   339,    -1,   340,
      39,   341,    -1,   341,    -1,   215,    -1,   214,    -1,   147,
     352,   152,   356,   350,    -1,   148,   353,   152,   356,   350,
      -1,   157,   359,    -1,   156,   359,    -1,   346,    -1,   351,
      -1,   344,    -1,   347,    -1,   348,    -1,   359,    -1,   349,
      -1,   164,   364,   165,   343,   345,    -1,    -1,   166,   343,
      -1,   160,    -1,   161,   307,    45,   364,    -1,   163,   307,
      -1,   163,    45,   307,    -1,   163,   162,    -1,   163,    45,
     162,    -1,   167,   350,    27,    -1,   343,    -1,   350,   343,
      -1,    90,    46,    -1,    90,   159,    46,    -1,    90,    82,
      46,    -1,    90,   159,    82,    46,    -1,   354,    -1,   352,
     354,    -1,   355,    -1,   353,   355,    -1,   149,    -1,   150,
      -1,   151,    -1,   149,    -1,   153,    -1,   154,    -1,   155,
      -1,   151,    -1,    93,    -1,   150,    -1,   357,    -1,   356,
     300,   357,    -1,   340,    39,   341,    -1,   341,    -1,   340,
     146,   340,   297,    -1,    -1,   158,   215,    51,   360,   361,
      52,    -1,    -1,   362,    -1,   363,    -1,   362,    58,   363,
      -1,   364,    -1,   367,    -1,   364,   123,   364,    -1,   364,
     122,   364,    -1,    -1,   366,    -1,   364,    -1,   366,    58,
     364,    -1,    56,   364,    -1,    55,   364,    -1,   369,    -1,
     126,   364,    -1,    51,   364,    52,    -1,   368,    51,   365,
      52,    -1,   168,   152,   307,    -1,   364,   121,   364,    -1,
     364,     8,   364,    -1,   364,     9,   364,    -1,   364,    53,
     364,    -1,   364,    55,   364,    -1,   364,    56,   364,    -1,
     364,    54,   364,    -1,   364,    72,   364,    -1,   364,   126,
      72,   364,    -1,   364,    45,   364,    -1,   364,   130,    -1,
     364,   131,    -1,   364,   127,   364,   123,   364,    -1,   364,
     128,    51,   370,    52,    -1,   364,   126,   128,    51,   370,
      52,    -1,   215,    -1,   307,    -1,    29,    -1,    46,    -1,
     129,    -1,    41,    -1,   369,    -1,   370,    58,   369,    -1,
      18,    -1,    20,    -1,    21,    -1,    22,    -1,    25,    -1,
      19,    -1,    27,    -1,    33,    -1,    35,    -1,    36,    -1,
      41,    -1,    42,    -1,    43,    -1,    48,    -1,    49,    -1,
      57,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,    90,    -1,    91,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,
      98,    -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,
     103,    -1,   104,    -1,   105,    -1,   106,    -1,   107,    -1,
     108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,
     118,    -1,   209,    -1,   119,    -1,   121,    -1,     8,    -1,
       9,    -1,   122,    -1,   123,    -1,   125,    -1,   126,    -1,
     127,    -1,   128,    -1,   129,    -1,   130,    -1,   131,    -1,
     132,    -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,
     137,    -1,   138,    -1,   139,    -1,   140,    -1,   141,    -1,
     142,    -1,   143,    -1,   146,    -1,   147,    -1,   148,    -1,
     149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,
     159,    -1,   160,    -1,   161,    -1,   162,    -1,   163,    -1,
     164,    -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,
     169,    -1,   170,    -1,   171,    -1,   173,    -1,    18,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    40,    -1,
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
     114,    -1,   115,    -1,   117,    -1,   118,    -1,   209,    -1,
     119,    -1,   121,    -1,     8,    -1,     9,    -1,   122,    -1,
     123,    -1,   125,    -1,   126,    -1,   127,    -1,   128,    -1,
     130,    -1,   131,    -1,   132,    -1,   133,    -1,   134,    -1,
     135,    -1,   136,    -1,   137,    -1,   138,    -1,   139,    -1,
     140,    -1,   141,    -1,   143,    -1,   146,    -1,   147,    -1,
     148,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
     153,    -1,   154,    -1,   155,    -1,   156,    -1,   157,    -1,
     158,    -1,   159,    -1,   160,    -1,   161,    -1,   163,    -1,
     164,    -1,   165,    -1,   166,    -1,   167,    -1,   168,    -1,
     169,    -1,   170,    -1,   171,    -1,   173,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   152,   153,   158,   159,   168,   169,   173,
     174,   178,   179,   180,   181,   186,   189,   196,   206,   215,
     228,   236,   246,   254,   267,   268,   273,   276,   279,   272,
     295,   298,   301,   294,   315,   318,   318,   324,   327,   330,
     333,   339,   340,   341,   345,   354,   360,   370,   377,   379,
     381,   383,   385,   387,   392,   402,   402,   405,   405,   418,
     418,   437,   439,   442,   437,   447,   447,   452,   453,   454,
     466,   467,   472,   473,   476,   491,   503,   504,   515,   526,
     539,   551,   562,   567,   570,   578,   579,   585,   584,   606,
     609,   609,   627,   628,   631,   632,   633,   636,   645,   646,
     649,   650,   651,   653,   654,   655,   661,   665,   665,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   684,
     683,   702,   703,   704,   708,   712,   708,   893,   894,   898,
     906,   907,   910,   911,   914,   917,   922,   931,   943,   955,
     962,   970,   977,   990,   999,  1008,  1015,  1017,  1020,  1026,
    1027,  1028,  1029,  1032,  1033,  1037,  1038,  1042,  1042,  1045,
    1046,  1066,  1088,  1094,  1095,  1096,  1097,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1113,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1129,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1160,  1161,  1162,  1166,  1167,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1180,  1194,  1195,  1196,
    1197,  1198,  1199,  1200,  1204,  1205,  1208,  1208,  1210,  1210,
    1213,  1223,  1229,  1229,  1232,  1233,  1234,  1238,  1238,  1240,
    1240,  1243,  1243,  1245,  1248,  1254,  1257,  1261,  1262,  1266,
    1268,  1270,  1272,  1274,  1279,  1279,  1283,  1286,  1290,  1290,
    1293,  1293,  1297,  1298,  1311,  1319,  1319,  1328,  1332,  1336,
    1340,  1344,  1348,  1352,  1358,  1362,  1366,  1370,  1374,  1378,
    1382,  1385,  1392,  1392,  1396,  1396,  1401,  1401,  1401,  1405,
    1412,  1413,  1414,  1415,  1421,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1439,  1443,  1448,  1451,  1452,  1455,  1456,
    1463,  1465,  1470,  1478,  1481,  1482,  1483,  1484,  1485,  1486,
    1487,  1493,  1495,  1496,  1499,  1502,  1506,  1507,  1508,  1509,
    1510,  1511,  1512,  1518,  1520,  1527,  1527,  1533,  1539,  1540,
    1543,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,
    1558,  1559,  1560,  1561,  1564,  1571,  1572,  1573,  1578,  1581,
    1585,  1597,  1600,  1601,  1605,  1615,  1622,  1631,  1634,  1646,
    1649,  1653,  1660,  1668,  1673,  1681,  1685,  1690,  1695,  1700,
    1705,  1710,  1719,  1728,  1729,  1734,  1737,  1745,  1751,  1757,
    1763,  1772,  1777,  1787,  1797,  1803,  1809,  1815,  1825,  1837,
    1845,  1857,  1865,  1866,  1867,  1871,  1872,  1873,  1874,  1875,
    1876,  1877,  1880,  1887,  1898,  1902,  1909,  1917,  1917,  1933,
    1934,  1940,  1946,  1954,  1961,  1962,  1963,  1968,  1969,  1972,
    1973,  1977,  1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,
    1987,  1988,  1989,  1990,  1991,  1992,  1993,  1994,  1995,  1996,
    1997,  1998,  1999,  2002,  2005,  2006,  2007,  2008,  2009,  2012,
    2016,  2027,  2029,  2030,  2031,  2032,  2033,  2035,  2036,  2037,
    2038,  2039,  2040,  2041,  2042,  2043,  2044,  2045,  2046,  2047,
    2048,  2049,  2050,  2051,  2052,  2053,  2054,  2055,  2056,  2057,
    2058,  2059,  2060,  2061,  2062,  2063,  2064,  2065,  2066,  2067,
    2068,  2069,  2070,  2071,  2072,  2073,  2074,  2075,  2076,  2077,
    2078,  2079,  2080,  2081,  2082,  2083,  2084,  2085,  2086,  2087,
    2088,  2089,  2090,  2091,  2092,  2093,  2094,  2095,  2096,  2097,
    2098,  2099,  2100,  2101,  2102,  2103,  2104,  2105,  2106,  2107,
    2108,  2109,  2110,  2111,  2112,  2113,  2114,  2115,  2116,  2117,
    2118,  2119,  2120,  2121,  2122,  2123,  2124,  2125,  2126,  2127,
    2128,  2129,  2130,  2131,  2132,  2133,  2134,  2135,  2136,  2137,
    2138,  2139,  2140,  2141,  2142,  2143,  2144,  2145,  2146,  2147,
    2148,  2149,  2150,  2151,  2152,  2153,  2154,  2155,  2156,  2157,
    2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,
    2196,  2197,  2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,
    2206,  2207,  2208,  2209,  2210,  2211,  2212,  2213,  2214,  2215,
    2216,  2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,
    2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,  2235,
    2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,  2245,
    2246,  2247,  2248,  2249,  2250,  2251,  2252,  2253,  2254,  2255,
    2256,  2257,  2258,  2259,  2260,  2261,  2262,  2263,  2264,  2265,
    2266,  2267,  2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,
    2276,  2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,
    2286,  2287,  2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,
    2296,  2297,  2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305,
    2306,  2307,  2308,  2309,  2310
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
  "SPECIAL_DBNAME", "KW_ACTION", "KW_PAGE", "KW_HBOX", "KW_VBOX",
  "KW_GRID", "KW_GROUP", "KW_TABLE", "KW_FOLDER", "KW_STYLE", "KW_LAYOUT",
  "KW_HIDDEN", "KW_TEXTEDIT", "KW_BUTTONEDIT", "KW_LABEL", "KW_EDIT",
  "KW_DATEEDIT", "KW_SCROLL", "KW_IMAGE", "KW_FONTPITCH", "KW_FIXED",
  "KW_VARIABLE", "KW_WANTNORETURNS", "KW_WANTTABS", "KW_AUTOSCALE",
  "KW_PIXELWIDTH", "KW_PIXELHEIGHT", "KW_SCROLLBARS_BOTH",
  "KW_SCROLLBARS_V", "KW_SCROLLBARS_H", "KW_STRETCH_Y", "KW_STRETCH_BOTH",
  "KW_ITEMS", "KW_VALUEMAX", "KW_VALUEMIN", "KW_PROGRESSBAR",
  "KW_COMBOBOX", "OPTIONS", "KW_BROWSER", "$accept", "form_def",
  "database_section", "named_or_kw_st", "named_or_kw_any", "dbname",
  "screen_or_layout_section", "vbox_section", "hbox_section",
  "group_section", "folder_section", "pages", "page", "opt_layout_ident",
  "grid_section", "@1", "@2", "@3", "table_section", "@4", "@5", "@6",
  "layout_attributes", "@7", "layout_attribute", "layout_attribute_list",
  "op_layout_items", "layout_items", "layout_container", "layout_section",
  "screen_section", "screens_section", "@8", "@9", "screens_rest", "@10",
  "@11", "@12", "op_extended", "op_size", "op_end", "screen_layout",
  "some_text", "screen_element", "ch_list", "field", "@13",
  "field_element", "@14", "op_table_section", "table_def_list",
  "table_def", "opequal", "table_qualifier", "attribute_section",
  "field_tag_list", "op_field_tag_type", "field_tag", "@15", "fpart_list",
  "fpart", "@16", "@17", "op_att", "field_datatype_null", "field_datatype",
  "field_type", "lu_ft_eq_c", "lu_ft_eq_c_i", "lu_ft", "lu_fc",
  "lu_joincol", "lu_join", "op_field_desc", "op_desc_list", "desc",
  "def_val", "colors", "color", "op_instruction_section", "instruct_opts",
  "instruct_op_1", "instruct_op", "@18", "op_ltype", "op_star", "op_semi",
  "srec_dim", "srec_field_list", "op_comma", "field_list_item",
  "field_list_element", "field_name", "op_ws", "ws", "ws_elem",
  "field_tag_name", "field_tag_name_scr", "@19", "datatype", "incl_list",
  "items_list", "number_value", "items_entry", "incl_entry", "opt_dec_ext",
  "opt_int_ext", "opt_unit_size", "dtfrac", "int_start", "int_start_unit",
  "int_end", "opt_dt_ext", "dt_start", "dt_end", "dtime_val", "opt_frac",
  "op_where", "where_clause", "clauses", "clause", "value",
  "fieldidentifier", "value_list", "composites", "composites_list",
  "composite_entry", "comp_list", "comp_item", "table_name", "column_name",
  "control_block", "action", "if", "op_else", "abort", "let", "nextfield",
  "block", "actions", "comments", "bef_act_list", "aft_act_list",
  "bef_act", "aft_act", "column_list", "column_entry", "master_of",
  "func_call", "@20", "op_func_call_args", "func_call_args",
  "func_call_arg", "expression", "op_expression_list", "expression_list",
  "single_expression", "fcall_name", "evalue", "evalue_list", "st_kword",
  "any_kword", 0
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
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   211,   212,   213,   213,   213,   213,   214,   214,   215,
     215,   216,   216,   216,   216,   217,   217,   218,   219,   220,
     221,   222,   222,   223,   224,   224,   226,   227,   228,   225,
     230,   231,   232,   229,   233,   234,   233,   235,   235,   235,
     235,   236,   236,   236,   237,   237,   238,   238,   239,   239,
     239,   239,   239,   239,   240,   241,   241,   243,   242,   244,
     242,   246,   247,   248,   245,   249,   249,   250,   250,   250,
     251,   251,   252,   252,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   255,   255,   257,   256,   258,
     259,   258,   260,   260,   261,   261,   261,   262,   263,   263,
     264,   264,   264,   264,   264,   264,   265,   266,   266,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   269,
     268,   270,   270,   270,   272,   273,   271,   274,   274,   274,
     275,   275,   276,   276,   276,   276,   277,   277,   277,   277,
     277,   277,   277,   278,   278,   279,   280,   281,   281,   282,
     282,   282,   282,   283,   283,   284,   284,   285,   285,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   287,   288,   288,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   290,   290,   291,   291,   292,   292,
     293,   293,   294,   293,   293,   293,   293,   295,   295,   296,
     296,   297,   297,   298,   298,   299,   299,   300,   300,   301,
     301,   301,   301,   301,   302,   302,   303,   303,   304,   304,
     305,   305,   306,   306,   307,   309,   308,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   311,   311,   312,   312,   313,   313,   313,   314,
     314,   314,   314,   314,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   316,   316,   316,   317,   317,
     318,   318,   319,   320,   321,   321,   321,   321,   321,   321,
     321,   322,   323,   323,   324,   325,   326,   326,   326,   326,
     326,   326,   326,   327,   327,   328,   328,   329,   330,   330,
     330,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   332,   332,   332,   332,   333,   334,
     334,   335,   336,   336,   337,   338,   338,   339,   339,   340,
     341,   342,   342,   342,   342,   343,   343,   343,   343,   343,
     343,   343,   344,   345,   345,   346,   347,   348,   348,   348,
     348,   349,   350,   350,   351,   351,   351,   351,   352,   352,
     353,   353,   354,   354,   354,   355,   355,   355,   355,   355,
     355,   355,   356,   356,   357,   357,   358,   360,   359,   361,
     361,   362,   362,   363,   364,   364,   364,   365,   365,   366,
     366,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   368,   369,   369,   369,   369,   369,   370,
     370,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     5,     5,     5,
       5,     1,     2,     5,     0,     1,     0,     0,     0,    10,
       0,     0,     0,    10,     0,     0,     4,     3,     1,     3,
       3,     1,     2,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     0,     3,     0,
       4,     0,     0,     0,     9,     0,     1,     0,     2,     4,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     4,     1,
       0,     4,     0,     3,     1,     2,     3,     2,     0,     2,
       1,     3,     3,     5,     3,     3,     3,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     1,     2,     3,     0,     0,     6,     0,     3,     5,
       3,     1,     0,     5,     3,     2,     4,     2,     4,     3,
       1,     4,     2,     1,     3,     3,     1,     3,     1,     3,
       1,     4,     2,     1,     2,     0,     2,     1,     3,     1,
       4,     2,     4,     3,     3,     3,     3,     5,     3,     5,
       1,     1,     3,     5,     3,     3,     3,     1,     4,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     1,     2,     1,     2,
       2,     1,     0,     9,    12,     1,     1,     0,     2,     0,
       1,     0,     1,     1,     4,     1,     3,     0,     1,     1,
       3,     3,     3,     3,     1,     3,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     0,     3,     5,     0,     3,
       0,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     3,     0,     1,     2,     1,     3,
       3,     3,     3,     3,     3,     4,     3,     2,     2,     1,
       5,     5,     2,     3,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     2,     7,     1,     3,     3,     1,     1,
       1,     5,     5,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     5,     0,     2,     1,     4,     2,     3,     2,
       3,     3,     1,     2,     2,     3,     3,     4,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     4,     0,     6,     0,
       1,     1,     3,     1,     1,     3,     3,     0,     1,     1,
       3,     2,     2,     1,     2,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     2,     2,
       5,     5,     6,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       0,     0,     0,     0,   550,   551,   471,   476,   472,   473,
     474,   475,   477,     7,   478,     3,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   548,   549,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,    11,   599,   547,    13,     6,     8,     1,
       0,    57,     0,    92,    16,    15,    55,     0,     0,     0,
       0,    59,    67,    24,    24,    26,    24,    30,    24,    48,
      49,    50,    51,    52,    53,    70,     0,     0,    56,     0,
     678,   679,   600,   601,   602,   603,   604,   605,     9,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   676,   677,
     680,   681,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   698,   699,
     700,   701,   702,   703,   704,   705,   706,   707,   708,   709,
     710,   711,   712,   713,   714,   715,   716,   717,   718,   719,
     720,   721,   722,   723,   724,   675,    12,    10,    14,     0,
      67,     0,    58,    61,    25,    34,    34,    24,    34,    24,
      34,    71,    54,    98,    70,    94,   109,   234,     5,     4,
      60,    68,    65,    35,    44,    44,    34,    44,    34,     0,
       0,    97,     0,    93,    95,   111,   114,   112,   110,   113,
     115,   116,   117,   118,   109,     0,   107,     0,     2,     0,
      66,     0,     0,     0,    45,    46,     0,     0,     0,     0,
      24,     0,    21,     0,   100,    99,    96,   106,   108,   274,
     119,   600,   604,   618,   697,   700,   701,   709,   710,   379,
      70,   236,   238,   245,     0,   241,   246,    69,    62,     0,
       0,     0,    38,    41,     0,    18,    47,    17,    27,    19,
      31,    34,    20,    22,     0,     0,     0,     0,     0,     0,
     371,   372,   242,   240,     0,   412,   413,   414,     0,   408,
     420,   415,   421,   419,   416,   417,   418,     0,   410,     0,
     384,   383,   235,   237,   239,     0,     0,     0,     0,     0,
      36,     0,    42,     0,     0,    44,   105,   101,   102,   104,
     124,     0,   121,   550,   551,   471,   473,   474,   475,     7,
     478,   479,   480,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   545,   546,   548,   549,   552,
     553,   554,   555,   556,   557,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   547,   380,     0,   375,     0,   378,
     373,     0,     0,     0,   409,     0,   411,     0,   251,    85,
      78,    87,    79,    80,    84,    83,    82,    77,    74,     0,
      75,    72,    81,    76,    39,    40,    37,    43,     0,     0,
       0,     0,     0,   120,   122,   249,     0,     0,   253,     0,
       0,     0,   425,   257,   422,   257,   427,   252,   426,   268,
      63,    73,    86,    28,    32,    23,   103,   607,     0,   132,
     140,   127,   123,   250,     0,   376,   377,     0,     0,     0,
       0,   258,     0,   395,     0,     0,     0,     0,     0,   402,
     387,   385,   388,   389,   391,   381,   386,   390,   382,   429,
     272,   273,     0,     0,   269,   270,    89,    70,     0,     0,
       0,   142,     0,     0,   137,   131,     0,     0,   125,     0,
       0,   607,   259,   257,   264,   255,     0,   424,   404,     0,
       0,     0,     0,   399,   397,   465,   468,   466,     0,     0,
       0,   683,   467,   720,   274,   464,     0,   434,     0,   443,
       0,   423,   403,     0,   430,   431,   433,    88,    90,   275,
     271,    64,    29,    33,   267,   266,   132,     0,   277,   278,
     279,   280,   281,   282,   315,   315,   332,   318,     0,   287,
     288,   289,   290,   291,   135,   132,     0,   139,     0,   155,
       0,   254,     0,     0,   247,     0,     0,     0,   406,   405,
       0,     0,   400,   398,     0,   442,   441,   444,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   459,     0,   437,   401,   428,     0,
     268,   268,   136,   141,     0,   283,   284,   336,   337,   338,
     339,   340,   341,   343,   285,     0,   334,   324,   325,   326,
     327,   328,   329,   343,   286,     0,   320,   134,   138,   130,
     128,     0,     0,   126,   374,   263,   261,   262,   260,     0,
     251,   256,   265,     0,   407,   396,   445,   447,   449,   450,
     457,   451,   454,   452,   453,   455,   448,   436,   435,     0,
       0,     0,     0,   393,   439,     0,   438,   432,    91,   276,
       0,     0,   342,     0,   330,     0,     0,   323,     0,     0,
     179,     0,     0,   186,   159,     0,     0,     0,     0,     0,
     170,   171,     0,     0,   177,   182,   181,     0,     0,   185,
     188,   187,   191,   180,     0,     0,   190,   189,     0,     0,
     194,   200,     0,     0,   196,   197,   195,     0,     0,   204,
     205,   206,   207,   208,     0,     0,     0,     0,   156,   157,
     248,   243,     0,   456,     0,     0,   469,     0,     0,   392,
     446,     0,   316,     0,   322,     0,   333,   335,   331,   319,
       0,   133,   129,     0,     0,   143,     0,   146,     0,   150,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   460,   461,     0,
     394,   440,     0,   344,   321,     0,   153,     0,     0,     0,
     152,     0,   226,   218,   219,   220,   221,   222,   223,   224,
     225,   229,   227,   230,   231,   232,   233,   228,   345,   216,
     163,   214,   213,   215,   164,   168,   166,   172,     0,   183,
     184,   174,   175,   176,   212,   201,   198,   199,   203,   202,
       0,   210,   211,   165,   158,     0,   462,   470,   317,   178,
     154,   144,   162,   148,   145,     0,   149,     0,   217,   160,
     346,     0,     0,   308,   296,   305,   314,   304,     0,     0,
       0,   309,   292,   301,   300,   303,   299,     0,   302,   294,
     244,     0,   151,   365,   368,   366,     0,     0,   367,   347,
     348,   359,   364,   169,   167,     0,     0,     0,     0,   297,
     298,   173,     0,     0,     0,   209,     0,   147,     0,   362,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     357,   358,   307,   306,   313,   312,   293,   311,   310,   295,
     363,   350,   349,   352,   353,   356,   354,   351,     0,     0,
       0,   355,     0,   369,     0,   360,   361,     0,   370
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   575,   714,   137,   143,   159,   160,   161,
     162,   361,   362,   305,   163,   307,   443,   678,   164,   309,
     444,   679,   324,   352,   393,   394,   353,   354,   355,   144,
     145,   146,   152,   300,   302,   322,   436,   677,   351,   303,
     312,   599,   600,   601,   602,   603,   629,   672,   800,   167,
     314,   315,   331,   365,   317,   344,   345,   346,   408,   451,
     452,   612,   759,   688,   684,   685,   641,   954,   955,   956,
    1054,   960,   998,   833,   928,   929,  1024,  1018,  1019,   348,
     380,   381,   382,   581,   840,   644,   628,   619,   693,   658,
     694,   695,   736,   673,   674,   675,   715,   676,   801,   754,
    1070,  1077,  1071,  1079,  1072,   805,   824,   877,   945,   825,
     826,   949,   814,   815,   946,   816,   872,  1059,  1060,  1089,
    1090,  1091,  1092,  1144,   383,   410,   411,   576,   577,   578,
     579,   385,   659,   660,   939,   661,   662,   663,   664,   665,
     666,   418,   427,   419,   428,   623,   624,   386,   667,   669,
     723,   724,   725,   726,   865,   866,   717,   718,   719,   937,
     138,   297
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -978
static const yytype_int16 yypact[] =
{
      32,  1907,    86,     1,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,    62,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,    90,  -978,  -978,   113,   120,  -978,  -978,
     121,  -978,   399,   134,  -978,   215,  -978,   140,  4094,  4094,
     157,  -978,   184,  4094,  4094,  -978,  4094,  -978,  4094,  -978,
    -978,  -978,  -978,  -978,  -978,   193,  4094,   202,  -978,   218,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   223,
     184,   212,  -978,  -978,  -978,   234,   234,  4094,   234,  4094,
     234,  -978,  -978,   225,  2414,  -978,   148,   274,  -978,  -978,
    -978,   275,   132,  -978,   399,   399,   234,   399,   234,   131,
    2918,  -978,  4094,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,    16,  4094,  -978,  4262,  -978,   285,
    -978,   292,   -62,   297,   399,  -978,   301,   306,   312,   313,
    4094,   -12,  -978,   318,   239,  -978,  -978,  -978,  -978,  -978,
    -978,   351,   304,   316,   322,   151,    80,   205,   205,  -978,
    3086,  -978,   317,  -978,   221,  -978,  -978,  -978,  -978,   329,
     331,   332,  -978,  -978,   -18,  -978,  -978,  -978,  -978,  -978,
    -978,   234,  -978,  -978,  4094,  4094,  4094,  4094,   333,  1568,
     351,  -978,  -978,  -978,   350,  -978,  -978,  -978,    98,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,    64,  -978,  4094,
    -978,  -978,  -978,  -978,  -978,  4094,  1398,   335,   352,   337,
    -978,   -62,  -978,  1398,  1398,   399,  -978,  -978,   347,  -978,
    -978,   133,  -978,   349,   368,   369,   371,   372,   378,   388,
     392,   402,   404,   407,   411,   413,   418,   419,   420,   423,
     426,   427,   428,   430,   431,   432,   434,   450,   459,   460,
     462,   463,   465,   466,   469,   470,   472,   473,   474,   475,
     477,   479,   480,   481,   485,   490,   494,   495,   496,   497,
     498,   501,   511,   512,   513,   514,   541,   542,   543,   544,
     548,   549,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   562,   574,   577,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   592,   593,   594,   595,
     596,   599,   600,   602,   603,   604,   605,   606,   607,   608,
     610,   620,   621,   635,   636,   638,   639,   640,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,  -978,    11,  -978,   659,  -978,
    -978,  4094,   374,  1568,  -978,  1568,  -978,   340,   660,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   894,
    -978,  -978,   683,  -978,  -978,  -978,  -978,  -978,  1062,  1230,
     673,  4094,  2582,   333,  -978,   662,  1568,  2076,   675,   661,
     674,   663,  -978,   208,  -978,   208,  -978,  -978,  -978,   118,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,   665,  4094,   -43,
     666,   680,  -978,  -978,   700,  -978,  -978,   681,  4430,   664,
    2076,  -978,   -34,  -978,  4094,  2750,  1738,   -54,  1568,  -978,
    -978,  -978,  -978,  -978,  -978,   -54,  -978,  -978,   -54,  1738,
    -978,  -978,    30,  4094,   118,  -978,  -978,   193,   682,   684,
    3254,   678,   540,   671,  -978,   597,  4094,   689,  -978,  1568,
     691,   685,   686,    -6,   667,  -978,   611,  -978,  -978,   676,
     -17,   687,  3422,  -978,  -978,  -978,  -978,  -978,  1738,  1738,
    1738,  1738,  -978,   569,   677,  -978,    22,  -978,   688,  -978,
      28,  -978,  -978,   679,   669,  -978,   219,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,   690,  4094,  -978,  -978,
    -978,  -978,  -978,  -978,   692,   692,   359,   410,  4094,  -978,
    -978,  -978,  -978,  -978,  -978,   690,   694,  -978,    26,   693,
      29,  -978,  3590,  3758,   619,  4430,  4430,   695,  -978,  -978,
     696,  1738,  -978,  -978,   199,   219,   219,   219,  4094,  1738,
    1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,  1738,
     -31,  1738,   697,  -978,  -978,   -54,  1738,  -978,  -978,  1738,
     118,   118,  -978,  -978,   707,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,   698,  -978,   628,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,   698,  -978,   629,   701,   702,  -978,  -978,
    -978,   711,   467,  -978,  -978,  -978,  -978,  -978,  -978,   614,
     660,  -978,  -978,   715,  -978,   219,  -978,  -978,   400,   400,
     219,   219,   219,   219,   219,   219,   219,   219,   219,  1738,
     703,   298,  2246,   579,   219,   704,   699,  -978,  -978,  -978,
      65,   718,  -978,   359,  -978,   410,   726,  -978,  4094,   730,
     734,  4094,  3926,  -978,  -978,   716,   717,   719,   705,   706,
    -978,  -978,   720,   721,  -978,  -978,  -978,   722,   723,  -978,
    -978,  -978,   172,  -978,   724,   725,  -978,  -978,   727,   728,
    -978,  -978,   729,   731,  -978,  -978,  -978,   735,   736,  -978,
    -978,  -978,  -978,  -978,   737,   738,   739,   740,   713,  -978,
    -978,  -978,   732,   219,  2246,  1738,  -978,   106,   -54,  -978,
    -978,  1738,  -978,   746,  -978,   708,  -978,  -978,  -978,  -978,
     741,  -978,  -978,   742,    66,  -978,   743,  -978,  4094,   750,
    -978,   401,   733,    -7,  4094,  4094,   745,   712,   748,   749,
    -978,  -978,   751,   752,  4094,   753,   754,    97,   763,   767,
     755,   772,   773,    -7,   467,   774,   127,   219,  -978,  2246,
    -978,   219,   756,  -978,  -978,   775,  -978,  4598,  3926,  4094,
     766,  4094,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,   319,  -978,
    -978,  -978,  -978,  -978,  -978,   768,   770,  -978,   253,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
     393,  -978,  -978,  -978,  -978,   759,  -978,  -978,  -978,  -978,
     769,  -978,  -978,   776,  -978,  4094,  -978,    42,  -978,  -978,
    -978,  4094,  4094,  -978,  -978,    -4,  -978,     5,   783,   784,
     138,     7,  -978,  -978,  -978,  -978,  -978,   153,  -978,  -978,
    -978,  4094,  -978,  -978,  -978,  -978,    42,    42,  -978,  -978,
     188,   259,  -978,  -978,  -978,   788,   789,   777,   778,  -978,
    -978,  -978,   253,    35,    35,  -978,   393,  -978,   779,  -978,
      42,    42,    27,    27,    27,    27,    27,   757,    27,   771,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -978,  -978,  -978,  -978,  -978,  -978,    27,   709,
      27,  -978,    27,  -978,   185,  -978,  -978,    27,  -978
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -978,  -978,  -978,   819,  -148,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,   464,  -135,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -978,  -225,  -978,  -345,  -978,  -299,  -978,  -133,  -978,
    -978,   710,  -978,  -978,   521,  -978,  -978,  -978,  -978,  -978,
    -312,  -127,  -978,  -363,  -978,  -978,  -978,  -978,  -978,  -978,
    -978,  -234,  -978,  -978,  -978,  -978,  -978,   483,  -978,  -978,
    -438,  -978,  -978,  -978,  -666,  -978,  -978,  -978,  -169,  -978,
    -978,  -168,  -978,  -978,  -978,  -151,  -149,  -978,  -183,  -978,
    -978,   456,  -978,  -978,  -978,  -978,    -3,  -978,  -978,   145,
      73,    75,  -978,    41,  -978,   169,  -342,    44,  -978,  -978,
    -978,  -978,  -977,  -261,  -256,   102,  -978,  -978,  -978,  -978,
     -27,  -978,  -978,  -978,  -978,   -21,    31,  -978,  -978,  -978,
    -917,  -700,  -978,  -978,  -978,  -978,   446,   168,   242,  -343,
    -538,  -978,  -654,  -978,  -978,  -978,  -978,  -978,  -978,  -575,
    -978,  -978,  -978,   441,   433,   276,   204,  -978,   -59,  -978,
    -978,  -978,    67,  -649,  -978,  -978,  -978,  -978,  -835,   -71,
    -978,  -978
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -725
static const yytype_int16 yytable[] =
{
     296,   298,   333,   370,   384,   304,   304,   716,   304,   165,
     304,   722,   698,   614,   722,   402,   -70,   682,   313,   306,
     615,   308,  1021,   310,   140,   141,   356,   936,   358,   769,
     779,   780,   367,  1095,   440,   -70,   652,   384,   834,  1022,
     441,   859,  1097,   311,  1103,   622,   764,   622,   699,   442,
     668,   389,   651,     1,   830,   797,  1083,  1084,   727,   774,
     775,   776,   777,  1078,  1064,   770,   722,   781,   432,   616,
     802,  1083,  1084,  1085,   728,   782,   783,   784,   785,   646,
     334,   325,   720,   327,   831,   329,   139,   616,  1085,   828,
    1068,  1069,   588,  1086,   786,   389,   607,   860,   366,   936,
     683,   357,   147,   359,   429,  1096,   653,   654,  1023,   655,
     656,   390,   697,   657,  1098,   996,  1104,   942,   652,   391,
     622,   392,   845,   943,   997,   700,  1127,  1128,   148,  1078,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   857,
     858,   863,   861,   787,   788,   789,   610,   864,   790,   791,
     792,   149,   793,   794,  1047,   390,  1088,   420,   988,   304,
     150,   304,   360,   391,   989,   392,   313,   151,  1087,  1108,
    1109,  1088,   326,   420,   328,   642,   445,   166,   450,  1046,
     613,   169,   364,   142,   313,   989,   429,   795,   653,   654,
    1101,   655,   656,  1131,  1132,   657,  1102,   369,   299,   379,
     335,   336,   337,   338,   339,  1105,   340,   779,   780,   301,
     933,  1106,   304,   421,   422,   423,   585,   424,   425,   426,
     311,   396,   316,   341,   342,   401,   343,   779,   780,   421,
     422,   423,   379,   424,   425,   426,   631,  1146,   140,   141,
     621,   321,   621,  1147,   781,   631,   631,   415,   416,   417,
     583,   846,   782,   783,   784,   785,   446,   447,   448,   449,
     318,   379,   670,   671,   781,   319,   651,  1112,  1113,  1063,
     330,   786,   782,   783,   784,   785,   405,   406,   407,   970,
     971,   587,  1064,  1065,   990,   323,   987,   379,   598,  1036,
    1037,   786,   991,   347,  1066,   598,   598,   349,   652,  1067,
     415,   416,   417,   350,  1114,   360,   779,   780,  1068,  1069,
    1110,  1111,   701,   704,   387,   621,   608,   609,   430,   431,
     787,   788,   789,   388,   395,   790,   791,   792,   397,   793,
     794,  1115,   335,   336,   337,   338,   339,   398,   340,   399,
     787,   788,   789,   781,   400,   790,   791,   792,  1002,   793,
     794,   782,   783,   784,   785,   341,   342,   404,   343,   409,
     773,   412,   413,   429,   434,   731,   429,   435,   653,   654,
     786,   655,   656,   414,   437,   657,   438,   439,   450,   582,
    1116,   604,   605,   606,   611,  1117,  1118,  1119,  -678,  1120,
    1121,   626,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,
    1011,  1012,  1013,  1014,  1015,  1016,  1017,  -679,  -600,  1073,
    -601,  -602,  1133,  1134,  1135,  1136,  1137,  -605,  1139,   787,
     788,   935,  1064,  1074,   790,   791,   792,    -9,   793,   794,
    1002,  -606,   620,   618,  1075,   379,   847,   379,  1141,  1076,
    1143,  -608,  1145,  -609,  1057,   781,  -611,  1148,  1068,  1069,
    -612,   598,  -613,   782,   783,   784,   785,  -614,  -615,  -616,
     598,   598,  -617,   636,   640,  -618,  -619,  -620,   379,  -621,
    -622,  -623,   786,  -624,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  -625,
     681,   807,   808,   809,   810,   811,   812,   813,  -626,  -627,
     692,  -628,  -629,   880,  -630,  -631,   369,   369,  -632,  -633,
     379,  -634,  -635,  -636,  -637,   881,  -638,   882,  -639,  -640,
    -641,   787,   788,   789,  -642,   729,   790,   791,   792,  -643,
     793,   794,   735,  -644,  -645,  -646,  -647,  -648,   757,   957,
    -649,   379,   817,   818,   819,   820,   821,   822,   823,   883,
    -650,  -651,  -652,  -653,   369,   884,   885,   886,   887,   888,
     889,   890,   891,   892,   893,   894,   895,   896,   897,   898,
     899,   900,   901,   902,   153,   154,   155,   156,   157,   158,
    -654,  -655,  -656,  -657,   903,   904,   905,  -658,  -659,   803,
    -660,  -661,  -662,  -663,  -664,  -665,  -666,  -667,  -668,  -669,
     827,  -670,   738,   739,   740,   741,   742,   743,   744,   745,
     746,   747,   748,  -671,   836,   838,  -672,   692,   692,  -673,
    -674,  -676,  -677,  -680,  -681,  -682,  -683,  -684,  -685,  -686,
     369,  -687,  -688,  -689,  -690,  -691,   906,   907,  -692,  -693,
     908,  -694,  -695,  -696,  -697,  -698,  -699,  -700,   909,  -701,
     910,   749,   750,   751,   752,   957,   911,   912,   913,  -702,
    -703,   914,   915,   916,   917,   918,   919,   920,   921,   922,
     923,   924,   925,   926,  -704,  -705,   927,  -706,  -707,  -708,
     753,  -709,  -710,  -711,  -712,  -713,  -714,  -715,  -716,  -717,
    -718,  -719,  -720,  -721,  -722,  -723,  -724,  -675,   617,   632,
     635,   647,   650,   649,   680,   686,   687,   627,   689,   732,
     690,   733,   648,   755,   369,   643,   696,   737,   758,   761,
     767,   778,   768,   756,   762,   763,   766,   799,  -463,   839,
     951,   798,   771,   369,   959,   829,   870,   873,   875,   796,
     879,   878,   844,   804,   932,   938,   843,   944,   862,   871,
     682,   832,   876,   930,   934,   950,   940,   941,   952,   953,
     993,   961,   962,  1028,   963,   966,   967,   968,   969,   972,
     973,   984,   974,   975,   976,   992,   977,   964,   965,  1020,
     978,   979,   980,   981,   982,   983,   369,   995,   999,  1001,
     985,  1027,  1038,   994,  1029,  1030,  1039,  1031,  1032,  1034,
    1035,  1041,  1042,  1045,  1049,  1055,  1040,  1061,  1048,  1062,
    1000,  1080,  1099,  1100,  -614,  1081,  1025,  1026,  1122,  1123,
     136,   320,  1140,  1124,  1125,   403,  1033,   368,  1051,  1138,
    1052,  1130,  1142,  1044,  1043,  1058,   433,   931,   765,   842,
     841,   369,   869,   730,   868,  1129,  1126,   806,   948,   369,
     959,  1053,   947,  1056,   874,   168,   580,   760,   645,   584,
     586,   625,   721,   986,     0,     0,   867,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,   171,     0,     0,     0,  1082,     0,     0,
     589,   590,   172,  1093,  1094,   173,   174,   175,   176,   177,
     591,     0,     0,     0,   178,     0,   630,   179,   180,   181,
     182,     0,     0,  1107,   183,     0,   184,   185,   592,     0,
     593,     0,   186,   187,     0,     0,     0,     0,     0,     0,
       0,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     594,   246,   247,   248,   595,   249,   250,   251,     0,   252,
     253,   254,   255,     0,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   596,   597,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     0,   285,   286,   287,
     288,   289,   290,   291,   292,   293,     0,   294,     0,     0,
     170,   171,     0,     0,     0,     0,     0,     0,   589,   590,
     172,     0,     0,   173,   174,   175,   176,   177,   591,     0,
       0,     0,   178,     0,   633,   179,   180,   181,   182,     0,
       0,     0,   183,   295,   184,   185,   592,     0,   593,     0,
     186,   187,     0,     0,     0,     0,     0,     0,     0,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   594,   246,
     247,   248,   595,   249,   250,   251,     0,   252,   253,   254,
     255,     0,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,     0,   268,   596,   597,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,   285,   286,   287,   288,   289,
     290,   291,   292,   293,     0,   294,     0,     0,   170,   171,
       0,     0,     0,     0,     0,     0,   589,   590,   172,     0,
       0,   173,   174,   175,   176,   177,   591,     0,     0,     0,
     178,     0,   634,   179,   180,   181,   182,     0,     0,     0,
     183,   295,   184,   185,   592,     0,   593,     0,   186,   187,
       0,     0,     0,     0,     0,     0,     0,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   594,   246,   247,   248,
     595,   249,   250,   251,     0,   252,   253,   254,   255,     0,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,   596,   597,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,     0,   285,   286,   287,   288,   289,   290,   291,
     292,   293,     0,   294,     0,     0,   170,   171,     0,     0,
       0,     0,     0,     0,   589,   590,   172,     0,     0,   173,
     174,   175,   176,   177,   591,     0,     0,     0,   178,     0,
       0,   179,   180,   181,   182,     0,     0,     0,   183,   295,
     184,   185,   592,     0,   593,     0,   186,   187,     0,     0,
       0,     0,     0,     0,     0,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   594,   246,   247,   248,   595,   249,
     250,   251,     0,   252,   253,   254,   255,     0,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   596,   597,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
       0,   294,     0,     0,     0,     0,   453,   454,     0,     0,
       0,     0,     0,     0,     0,     0,   455,     7,     8,   456,
     457,   175,   176,   458,     0,    12,     0,     0,   459,     0,
       0,   460,   180,   461,   462,     0,     0,   295,   183,    18,
     463,   464,     0,     0,     0,     0,   465,   466,     0,     0,
       0,     0,     0,     0,     0,   467,     0,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,    81,   525,   526,   527,     0,   528,
     529,   530,     0,   531,   532,   533,   534,    92,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     105,   547,     0,     0,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     123,   564,   565,   566,   567,   568,   569,   570,   571,   572,
       0,   573,     0,     0,     0,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,   173,
     174,   175,   176,   177,     0,     0,     0,   705,   178,     0,
       0,   179,   180,   181,   182,     0,     0,   574,   183,   706,
     184,   185,     0,     0,   707,     0,   186,   187,     0,   708,
       0,     0,     0,   709,   710,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,   246,   247,   248,     0,   249,
     250,   251,     0,   252,   711,   254,   255,   712,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,     0,     0,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
       0,   285,   286,   287,   288,   289,   713,   291,   292,   293,
       0,   294,     0,     0,     0,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
       0,     0,    11,     0,    12,     0,     0,    13,     0,     0,
      14,    15,    16,    17,     0,     0,     0,   295,    18,    19,
      20,     0,     0,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,     0,    23,     0,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,     0,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     9,    10,     0,
       0,    11,     0,    12,     0,     0,    13,     0,     0,    14,
       0,    16,    17,     0,     0,     0,   135,    18,    19,    20,
       0,     0,     0,     0,    21,    22,     0,     0,     0,     0,
       0,     0,     0,    23,     0,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    86,    87,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,   134,
       0,     0,     0,     0,   170,   171,     0,     0,     0,     0,
       0,     0,     0,     0,   172,     0,     0,   173,   174,   175,
     176,   177,     0,     0,     0,   705,   178,     0,     0,   179,
     180,   181,   182,     0,     0,   135,   183,   706,   184,   185,
       0,     0,   707,     0,   186,   187,     0,     0,     0,     0,
       0,     0,     0,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,   246,   247,   248,     0,   249,   250,   251,
       0,   252,   253,   254,   255,   712,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   268,
       0,     0,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,     0,   285,
     286,   287,   288,   289,   290,   291,   292,   293,     0,   294,
       0,     0,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,   172,     0,     0,   173,   174,   175,   176,   177,
       0,   311,     0,     0,   178,     0,     0,   179,   180,   181,
     182,     0,     0,     0,   183,   295,   184,   185,     0,     0,
       0,     0,   186,   187,     0,     0,     0,     0,     0,     0,
       0,   188,   332,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,   246,   247,   248,     0,   249,   250,   251,     0,   252,
     253,   254,   255,     0,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,     0,     0,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     0,   285,   286,   287,
     288,   289,   290,   291,   292,   293,     0,   294,     0,     0,
     170,   171,     0,     0,     0,     0,     0,     0,     0,     0,
     172,     0,     0,   173,   174,   175,   176,   177,     0,     0,
       0,     0,   178,     0,     0,   179,   637,   181,   182,     0,
       0,     0,   183,   295,   184,   185,     0,     0,     0,     0,
     186,   187,     0,     0,     0,   638,     0,     0,     0,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,   246,
     247,   248,     0,   249,   250,   251,     0,   252,   253,   254,
     255,     0,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   639,   268,     0,     0,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,     0,   285,   286,   287,   288,   289,
     290,   291,   292,   293,     0,   294,     0,     0,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,   173,   174,   175,   176,   177,     0,     0,     0,     0,
     178,     0,     0,   179,   180,   181,   182,     0,     0,     0,
     183,   295,   184,   185,     0,   702,     0,     0,   186,   187,
       0,     0,     0,     0,     0,     0,     0,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,   247,   248,
       0,   249,   250,   251,     0,   252,   253,   254,   255,     0,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,     0,     0,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   703,   285,   286,   287,   288,   289,   290,   291,
     292,   293,     0,   294,     0,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,   173,
     174,   175,   176,   177,     0,     0,     0,     0,   178,     0,
       0,   179,   180,   181,   182,     0,     0,     0,   183,   295,
     184,   185,     0,     0,   363,     0,   186,   187,     0,     0,
       0,     0,     0,     0,     0,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,   246,   247,   248,     0,   249,
     250,   251,     0,   252,   253,   254,   255,     0,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,     0,     0,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
       0,   294,     0,     0,   170,   171,     0,     0,     0,     0,
       0,     0,     0,     0,   371,     0,     0,   173,   174,   175,
     372,   177,     0,   311,     0,     0,   178,     0,     0,   179,
     180,   181,   182,     0,     0,     0,   183,   295,   184,   185,
       0,     0,     0,     0,   186,   187,     0,     0,     0,     0,
       0,     0,     0,   188,     0,   189,   190,   373,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,   246,   247,   248,     0,   249,   250,   251,
       0,   252,   253,   254,   255,     0,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   374,     0,   268,
       0,     0,   269,   375,   376,   272,   273,   274,   275,   276,
     277,   278,   377,   378,   281,   282,   283,   284,     0,   285,
     286,   287,   288,   289,   290,   291,   292,   293,     0,   294,
       0,     0,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,   172,     0,     0,   173,   174,   175,   176,   177,
       0,   734,     0,     0,   178,     0,     0,   179,   180,   181,
     182,     0,     0,     0,   183,   295,   184,   185,     0,     0,
       0,     0,   186,   187,     0,     0,     0,     0,     0,     0,
       0,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,   246,   247,   248,     0,   249,   250,   251,     0,   252,
     253,   254,   255,     0,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,     0,     0,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     0,   285,   286,   287,
     288,   289,   290,   291,   292,   293,     0,   294,     0,     0,
     170,   171,     0,     0,     0,     0,     0,     0,     0,     0,
     172,     0,     0,   173,   174,   175,   176,   177,     0,     0,
       0,     0,   178,     0,     0,   179,   180,   181,   182,     0,
       0,     0,   183,   295,   184,   185,     0,     0,     0,     0,
     186,   187,     0,     0,     0,     0,     0,     0,     0,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,   246,
     247,   248,     0,   249,   250,   251,     0,   252,   253,   254,
     255,     0,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,     0,   268,     0,     0,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   772,   285,   286,   287,   288,   289,
     290,   291,   292,   293,     0,   294,     0,     0,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,   173,   174,   175,   176,   177,     0,     0,     0,     0,
     178,     0,     0,   179,   180,   181,   182,     0,     0,     0,
     183,   295,   184,   185,     0,     0,     0,     0,   186,   187,
       0,     0,     0,   835,     0,     0,     0,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,   247,   248,
       0,   249,   250,   251,     0,   252,   253,   254,   255,     0,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,     0,     0,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,     0,   285,   286,   287,   288,   289,   290,   291,
     292,   293,     0,   294,     0,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,   173,
     174,   175,   176,   177,     0,     0,     0,     0,   178,     0,
       0,   179,   180,   181,   182,     0,     0,     0,   183,   295,
     184,   185,     0,     0,     0,     0,   186,   187,     0,     0,
       0,   837,     0,     0,     0,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,   246,   247,   248,     0,   249,
     250,   251,     0,   252,   253,   254,   255,     0,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,     0,     0,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
       0,   294,     0,     0,   170,   171,     0,     0,     0,     0,
       0,     0,     0,     0,   172,     0,     0,   173,   174,   175,
     176,   177,     0,     0,     0,     0,   178,     0,     0,   179,
     180,   181,   182,     0,     0,     0,   183,   295,   184,   185,
       0,     0,     0,     0,   186,   187,     0,     0,     0,   958,
       0,     0,     0,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,   246,   247,   248,     0,   249,   250,   251,
       0,   252,   253,   254,   255,     0,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,     0,   268,
       0,     0,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,     0,   285,
     286,   287,   288,   289,   290,   291,   292,   293,     0,   294,
       0,     0,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,   172,     0,     0,   173,   174,   175,   176,   177,
       0,     0,     0,     0,   178,     0,     0,   179,   180,   181,
     182,     0,     0,     0,   183,   295,   184,   185,     0,     0,
       0,     0,   186,   187,     0,     0,     0,     0,     0,     0,
       0,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,   246,   247,   248,     0,   249,   250,   251,     0,   252,
     253,   254,   255,     0,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,     0,     0,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,     0,   285,   286,   287,
     288,   289,   290,   291,   292,   293,     0,   294,     0,     0,
     170,   171,     0,     0,     0,     0,     0,     0,     0,     0,
     371,     0,     0,   173,   174,   175,   372,   177,     0,     0,
       0,     0,   178,     0,     0,   179,   180,   181,   182,     0,
       0,     0,   183,   295,   184,   185,     0,     0,     0,     0,
     186,   187,     0,     0,     0,     0,     0,     0,     0,   188,
       0,   189,   190,   373,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,   246,
     247,   248,     0,   249,   250,   251,     0,   252,   253,   254,
     255,     0,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   374,     0,   268,     0,     0,   269,   375,
     376,   272,   273,   274,   275,   276,   277,   278,   377,   378,
     281,   282,   283,   284,     0,   285,   286,   287,   288,   289,
     290,   291,   292,   293,     0,   294,     0,     0,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,   173,   174,   175,   176,   177,     0,     0,     0,     0,
     178,     0,     0,   179,   691,   181,   182,     0,     0,     0,
     183,   295,   184,   185,     0,     0,     0,     0,   186,   187,
       0,     0,     0,     0,     0,     0,     0,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,   247,   248,
       0,   249,   250,   251,     0,   252,   253,   254,   255,     0,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,     0,   268,     0,     0,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,     0,   285,   286,   287,   288,   289,   290,   291,
     292,   293,     0,   294,     0,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,   173,
     174,   175,   176,   177,     0,     0,     0,     0,   178,     0,
       0,   179,   180,   181,   182,     0,     0,     0,   183,   295,
     184,   185,     0,     0,     0,     0,   186,  1050,     0,     0,
       0,     0,     0,     0,     0,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,   246,   247,   248,     0,   249,
     250,   251,     0,   252,   253,   254,   255,     0,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,     0,     0,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295
};

static const yytype_int16 yycheck[] =
{
     148,   149,   314,   345,   347,   153,   154,   656,   156,   142,
     158,   665,    46,   451,   668,    27,     0,    60,   166,   154,
       9,   156,    29,   158,    23,    24,   325,   862,   327,    46,
       8,     9,   344,    37,    52,    19,    90,   380,     9,    46,
      58,    72,    37,    27,    37,   583,    52,   585,    82,   394,
     625,   113,    58,    21,    28,    27,    29,    30,    28,   708,
     709,   710,   711,  1040,    29,    82,   720,    45,   380,    58,
     736,    29,    30,    46,    44,    53,    54,    55,    56,   617,
     314,   306,   657,   308,    58,   310,     0,    58,    46,   755,
      55,    56,   435,    51,    72,   113,   441,   128,   332,   934,
     143,   326,    40,   328,   158,   109,   160,   161,   115,   163,
     164,   173,   650,   167,   109,    49,   109,    52,    90,   181,
     658,   183,   771,    58,    58,   159,  1103,  1104,    38,  1106,
     779,   780,   781,   782,   783,   784,   785,   786,   787,   788,
     789,   795,   791,   121,   122,   123,   445,   796,   126,   127,
     128,    38,   130,   131,   989,   173,   129,    93,    52,   307,
      40,   309,   174,   181,    58,   183,   314,    46,   126,  1086,
    1087,   129,   307,    93,   309,   613,   401,    43,    45,    52,
      47,    41,   330,   182,   332,    58,   158,   165,   160,   161,
      52,   163,   164,  1110,  1111,   167,    58,   345,    41,   347,
     184,   185,   186,   187,   188,    52,   190,     8,     9,    25,
     859,    58,   360,   149,   150,   151,   152,   153,   154,   155,
      27,   354,    20,   207,   208,   360,   210,     8,     9,   149,
     150,   151,   380,   153,   154,   155,   599,    52,    23,    24,
     583,    29,   585,    58,    45,   608,   609,   149,   150,   151,
     152,    52,    53,    54,    55,    56,   404,   405,   406,   407,
      42,   409,   144,   145,    45,    42,    58,     8,     9,    16,
      45,    72,    53,    54,    55,    56,    37,    38,    39,   107,
     108,   429,    29,    30,   938,    51,   935,   435,   436,   192,
     193,    72,   941,    19,    41,   443,   444,    22,    90,    46,
     149,   150,   151,   171,    45,   174,     8,     9,    55,    56,
     122,   123,   654,   655,    29,   658,   443,   444,   377,   378,
     121,   122,   123,    31,    27,   126,   127,   128,    27,   130,
     131,    72,   184,   185,   186,   187,   188,    31,   190,    27,
     121,   122,   123,    45,    31,   126,   127,   128,    29,   130,
     131,    53,    54,    55,    56,   207,   208,    39,   210,     8,
     702,    57,    46,   158,    47,   677,   158,   146,   160,   161,
      72,   163,   164,    51,    45,   167,    45,    45,    45,    29,
     121,    46,    30,    46,    37,   126,   127,   128,    39,   130,
     131,    51,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    39,    39,    16,
      39,    39,  1112,  1113,  1114,  1115,  1116,    39,  1118,   121,
     122,   123,    29,    30,   126,   127,   128,    39,   130,   131,
      29,    39,    58,   581,    41,   583,   778,   585,  1138,    46,
    1140,    39,  1142,    39,   125,    45,    39,  1147,    55,    56,
      39,   599,    39,    53,    54,    55,    56,    39,    39,    39,
     608,   609,    39,   611,   612,    39,    39,    39,   616,    39,
      39,    39,    72,    39,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    39,
     638,   132,   133,   134,   135,   136,   137,   138,    39,    39,
     648,    39,    39,    36,    39,    39,   654,   655,    39,    39,
     658,    39,    39,    39,    39,    48,    39,    50,    39,    39,
      39,   121,   122,   123,    39,   673,   126,   127,   128,    39,
     130,   131,   680,    39,    39,    39,    39,    39,   686,   881,
      39,   689,   132,   133,   134,   135,   136,   137,   138,    82,
      39,    39,    39,    39,   702,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   175,   176,   177,   178,   179,   180,
      39,    39,    39,    39,   117,   118,   119,    39,    39,   737,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
     748,    39,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    39,   762,   763,    39,   765,   766,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
     778,    39,    39,    39,    39,    39,   169,   170,    39,    39,
     173,    39,    39,    39,    39,    39,    39,    39,   181,    39,
     183,   111,   112,   113,   114,   997,   189,   190,   191,    39,
      39,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    39,    39,   209,    39,    39,    39,
     140,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    16,
      27,    26,    39,    29,    39,    39,    26,    47,     8,    27,
      29,    27,    51,    42,   862,    53,    52,    39,    29,    28,
     109,   152,    46,   126,    39,    39,    59,    58,    51,   110,
     878,    52,    45,   881,   882,    41,    29,   109,   109,    51,
      29,    39,    46,    51,    29,   166,    51,    29,    51,    51,
      60,    58,    51,   139,    51,    29,    52,    58,    28,    25,
      52,    45,    45,    51,    45,    45,    45,    45,    45,    45,
      45,    58,    45,    45,    45,    29,    45,    72,    72,    46,
      45,    45,    45,    45,    45,    45,   934,    45,    45,    39,
      58,    46,    29,    52,    46,    46,    29,    46,    46,    46,
      46,    29,    29,    29,    29,    39,    51,    39,    52,    39,
     958,    52,    29,    29,    45,    39,   964,   965,    30,    30,
       1,   300,    51,    46,    46,   361,   974,   344,   997,    72,
     998,    52,   123,   984,   983,  1018,   380,   840,   693,   766,
     765,   989,   801,   674,   800,  1106,  1102,   745,   875,   997,
     998,   999,   873,  1001,   823,   145,   410,   689,   616,   418,
     427,   585,   658,   934,    -1,    -1,   799,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,  1055,    -1,    -1,
      16,    17,    18,  1061,  1062,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    -1,  1081,    40,    -1,    42,    43,    44,    -1,
      46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,   209,    42,    43,    44,    -1,    46,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,   209,    42,    43,    44,    -1,    46,    -1,    48,    49,
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
     170,   171,    -1,   173,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,   209,
      42,    43,    44,    -1,    46,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,   209,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,   209,    40,    41,
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
      -1,   173,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,    35,    36,    -1,    -1,    -1,   209,    41,    42,
      43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,   121,   122,
     123,    -1,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,
      -1,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,   209,    41,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,   209,    40,    41,    42,    43,
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
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,   209,    42,    43,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
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
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,   209,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,   209,    42,    43,    -1,    45,    -1,    -1,    48,    49,
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
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,   209,
      42,    43,    -1,    -1,    46,    -1,    48,    49,    -1,    -1,
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
      -1,   173,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,   209,    42,    43,
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
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,   209,    42,    43,    -1,    -1,
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
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,   209,    42,    43,    -1,    -1,    -1,    -1,
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
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,   209,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
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
     170,   171,    -1,   173,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,   209,
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
      -1,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,   209,    42,    43,
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
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,   209,    42,    43,    -1,    -1,
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
     166,   167,   168,   169,   170,   171,    -1,   173,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,   209,    42,    43,    -1,    -1,    -1,    -1,
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
     168,   169,   170,   171,    -1,   173,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,   209,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
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
     170,   171,    -1,   173,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,   209,
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
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   209
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   212,   213,     8,     9,    18,    19,    20,    21,
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
     169,   170,   171,   172,   173,   209,   214,   216,   371,     0,
      23,    24,   182,   217,   240,   241,   242,    40,    38,    38,
      40,    46,   243,   175,   176,   177,   178,   179,   180,   218,
     219,   220,   221,   225,   229,   239,    43,   260,   242,    41,
       8,     9,    18,    21,    22,    23,    24,    25,    30,    33,
      34,    35,    36,    40,    42,    43,    48,    49,    57,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   117,   118,   119,   121,
     122,   123,   125,   126,   127,   128,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   143,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   173,   209,   215,   372,   215,    41,
     244,    25,   245,   250,   215,   224,   224,   226,   224,   230,
     224,    27,   251,   215,   261,   262,    20,   265,    42,    42,
     245,    29,   246,    51,   233,   233,   224,   233,   224,   233,
      45,   263,    58,   251,   262,   184,   185,   186,   187,   188,
     190,   207,   208,   210,   266,   267,   268,    19,   290,    22,
     171,   249,   234,   237,   238,   239,   237,   233,   237,   233,
     174,   222,   223,    46,   215,   264,   262,   251,   268,   215,
     307,    18,    24,    61,   141,   147,   148,   156,   157,   215,
     291,   292,   293,   335,   340,   342,   358,    29,    31,   113,
     173,   181,   183,   235,   236,    27,   239,    27,    31,    27,
      31,   224,    27,   223,    39,    37,    38,    39,   269,     8,
     336,   337,    57,    46,    51,   149,   150,   151,   352,   354,
      93,   149,   150,   151,   153,   154,   155,   353,   355,   158,
     359,   359,   251,   292,    47,   146,   247,    45,    45,    45,
      52,    58,   235,   227,   231,   233,   215,   215,   215,   215,
      45,   270,   271,     8,     9,    18,    21,    22,    25,    30,
      33,    35,    36,    42,    43,    48,    49,    57,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   117,   118,   119,   121,   122,
     123,   125,   126,   127,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   143,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   173,   209,   214,   338,   339,   340,   341,
     337,   294,    29,   152,   354,   152,   355,   215,   340,    16,
      17,    26,    44,    46,   116,   120,   144,   145,   215,   252,
     253,   254,   255,   256,    46,    30,    46,   235,   252,   252,
     237,    37,   272,    47,   271,     9,    58,    39,   215,   298,
      58,   340,   341,   356,   357,   356,    51,    47,   297,   257,
      32,   254,    16,    32,    32,    27,   215,    34,    53,   142,
     215,   277,   271,    53,   296,   339,   341,    26,    51,    29,
      39,    58,    90,   160,   161,   163,   164,   167,   300,   343,
     344,   346,   347,   348,   349,   350,   351,   359,   350,   360,
     144,   145,   258,   304,   305,   306,   308,   248,   228,   232,
      39,   215,    60,   143,   275,   276,    39,    26,   274,     8,
      29,    34,   215,   299,   301,   302,    52,   341,    46,    82,
     159,   307,    45,   162,   307,    29,    41,    46,    51,    55,
      56,   126,   129,   168,   215,   307,   364,   367,   368,   369,
     350,   357,   343,   361,   362,   363,   364,    28,    44,   215,
     306,   251,    27,    27,    27,   215,   303,    39,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,   111,
     112,   113,   114,   140,   310,    42,   126,   215,    29,   273,
     338,    28,    39,    39,    52,   300,    59,   109,    46,    46,
      82,    45,   162,   307,   364,   364,   364,   364,   152,     8,
       9,    45,    53,    54,    55,    56,    72,   121,   122,   123,
     126,   127,   128,   130,   131,   165,    51,    27,    52,    58,
     259,   309,   275,   215,    51,   316,   316,   132,   133,   134,
     135,   136,   137,   138,   323,   324,   326,   132,   133,   134,
     135,   136,   137,   138,   317,   320,   321,   215,   275,    41,
      28,    58,    58,   284,     9,    53,   215,    53,   215,   110,
     295,   302,   301,    51,    46,   364,    52,   307,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   364,    72,
     128,   364,    51,   343,   364,   365,   366,   363,   308,   304,
      29,    51,   327,   109,   327,   109,    51,   318,    39,    29,
      36,    48,    50,    82,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   117,   118,   119,   169,   170,   173,   181,
     183,   189,   190,   191,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   209,   285,   286,
     139,   297,    29,   364,    51,   123,   369,   370,   166,   345,
      52,    58,    52,    58,    29,   319,   325,   326,   321,   322,
      29,   215,    28,    25,   278,   279,   280,   307,    53,   215,
     282,    45,    45,    45,    72,    72,    45,    45,    45,    45,
     107,   108,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    58,    58,   370,   364,    52,    58,
     343,   364,    29,    52,    52,    45,    49,    58,   283,    45,
     215,    39,    29,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,   288,   289,
      46,    29,    46,   115,   287,   215,   215,    46,    51,    46,
      46,    46,    46,   215,    46,    46,   192,   193,    29,    29,
      51,    29,    29,   287,   286,    29,    52,   369,    52,    29,
      49,   279,   282,   215,   281,    39,   215,   125,   289,   328,
     329,    39,    39,    16,    29,    30,    41,    46,    55,    56,
     311,   313,   315,    16,    30,    41,    46,   312,   313,   314,
      52,    39,   215,    29,    30,    46,    51,   126,   129,   330,
     331,   332,   333,   215,   215,    37,   109,    37,   109,    29,
      29,    52,    58,    37,   109,    52,    58,   215,   331,   331,
     122,   123,     8,     9,    45,    72,   121,   126,   127,   128,
     130,   131,    30,    30,    46,    46,   315,   313,   313,   314,
      52,   331,   331,   332,   332,   332,   332,   332,    72,   332,
      51,   332,   123,   332,   334,   332,    52,    58,   332
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
#line 147 "screen.yacc"
    {
A4GL_check_compiled_form();
A4GL_write_form();}
    break;

  case 3:
#line 152 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:
#line 153 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 158 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 159 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 11:
#line 178 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:
#line 179 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:
#line 181 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 15:
#line 186 "screen.yacc"
    {
			the_form.layout=NULL;
	}
    break;

  case 16:
#line 189 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 17:
#line 196 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 18:
#line 206 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 19:
#line 215 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_GROUP;
			/* only one item in a group */
			if ( (yyval.layout)->children.children_len!=1) {
				yyerror("A GROUP must contain 1 and only 1 child item");
			}
	}
    break;

  case 20:
#line 228 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 21:
#line 236 "screen.yacc"
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		(yyval.layout)->layout_type=LAYOUT_FOLDER;
		(yyval.layout)->id="NOTSET";
		(yyval.layout)->attrib=0;
		(yyval.layout)->screen_no=-1;
		(yyval.layout)->children.children_val=0;
		(yyval.layout)->children.children_len=0;
		add_child((yyval.layout), (yyvsp[(1) - (1)].layout));
	}
    break;

  case 22:
#line 246 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 23:
#line 254 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_PAGE;
			if ( (yyval.layout)->children.children_len!=1) {
				yyerror("A PAGE must contain 1 and only 1 child item");
			}
	}
    break;

  case 24:
#line 267 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 26:
#line 273 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 27:
#line 276 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 28:
#line 279 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 29:
#line 280 "screen.yacc"
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		(yyval.layout)->layout_type=LAYOUT_GRID;
		(yyval.layout)->id=strdup((yyvsp[(3) - (10)].str));
		(yyval.layout)->attrib=(yyvsp[(4) - (10)].layout_attrib);
		(yyval.layout)->screen_no=atol((yyvsp[(2) - (10)].str));
		(yyval.layout)->children.children_val=0;
		(yyval.layout)->children.children_len=0;
	}
    break;

  case 30:
#line 295 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 31:
#line 298 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:
#line 301 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:
#line 302 "screen.yacc"
    {
		//strcpy($<str>$,$<str>2);
		(yyval.layout)=malloc(sizeof(struct s_layout));
		(yyval.layout)->layout_type=LAYOUT_TABLE;
		(yyval.layout)->id=strdup((yyvsp[(3) - (10)].str));
		(yyval.layout)->attrib=(yyvsp[(4) - (10)].layout_attrib);
		(yyval.layout)->screen_no=atol((yyvsp[(2) - (10)].str));
		(yyval.layout)->children.children_val=0;
		(yyval.layout)->children.children_len=0;
	}
    break;

  case 34:
#line 315 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 35:
#line 318 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 36:
#line 318 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 37:
#line 324 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 38:
#line 327 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 39:
#line 330 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 40:
#line 333 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 44:
#line 345 "screen.yacc"
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		                (yyval.layout)->layout_type=LAYOUT_NOTSET;
                		(yyval.layout)->id="NOTSET";
                		(yyval.layout)->attrib=0;
                		(yyval.layout)->screen_no=-1;
                		(yyval.layout)->children.children_val=0;
                		(yyval.layout)->children.children_len=0;
		}
    break;

  case 45:
#line 354 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 46:
#line 360 "screen.yacc"
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		(yyval.layout)->layout_type=LAYOUT_NOTSET;
		(yyval.layout)->id="NOTSET";
		(yyval.layout)->attrib=0;
		(yyval.layout)->screen_no=-1;
		(yyval.layout)->children.children_val=0;
		(yyval.layout)->children.children_len=0;
		add_child((yyval.layout), (yyvsp[(1) - (1)].layout));
	}
    break;

  case 47:
#line 370 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 48:
#line 378 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 49:
#line 380 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 50:
#line 382 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 51:
#line 384 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:
#line 386 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 53:
#line 388 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 54:
#line 394 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(2) - (3)].layout);
	}
    break;

  case 57:
#line 405 "screen.yacc"
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

  case 59:
#line 418 "screen.yacc"
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

  case 61:
#line 437 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 62:
#line 439 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 63:
#line 442 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 66:
#line 447 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 69:
#line 454 "screen.yacc"
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

  case 74:
#line 476 "screen.yacc"
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

  case 75:
#line 491 "screen.yacc"
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

  case 76:
#line 503 "screen.yacc"
    { ltab=0; }
    break;

  case 77:
#line 504 "screen.yacc"
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

  case 78:
#line 515 "screen.yacc"
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

  case 79:
#line 526 "screen.yacc"
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

  case 80:
#line 539 "screen.yacc"
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

  case 81:
#line 551 "screen.yacc"
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

  case 82:
#line 562 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 83:
#line 567 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 84:
#line 570 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 85:
#line 578 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 86:
#line 579 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:
#line 585 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 88:
#line 592 "screen.yacc"
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

  case 89:
#line 606 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 90:
#line 609 "screen.yacc"
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

  case 91:
#line 620 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 97:
#line 636 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 98:
#line 645 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 99:
#line 646 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 100:
#line 649 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 101:
#line 650 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 102:
#line 652 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 103:
#line 653 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 104:
#line 654 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 109:
#line 670 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 110:
#line 671 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 111:
#line 672 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 112:
#line 673 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 113:
#line 674 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 114:
#line 675 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 115:
#line 676 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 116:
#line 677 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 117:
#line 678 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 118:
#line 679 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 119:
#line 684 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 120:
#line 690 "screen.yacc"
    {
			if (strcmp((yyvsp[(1) - (5)].str),"Edit")!=0) {
				if (A4GL_has_str_attribute(fld,FA_S_WIDGET)) {
					yyerror("Field already has a widget");
				} else {
					A4GL_add_str_attr(fld,FA_S_WIDGETTYPE,(yyvsp[(1) - (5)].str));
				}
			}
		}
    break;

  case 124:
#line 708 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 125:
#line 712 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 126:
#line 720 "screen.yacc"
    {
	int cnt;
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
		}
	} else {
		char *format;
		cnt=0;
		while (1) {
			if (strcmp(the_form.dbname,"formonly")==0) {
				format=0;
			} else {
				format=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt++,"def_format");
			}
			if (format==0) break;
			if (format && strlen(format)) {
				// Looks like we've found one in syscolatt instead...
				A4GL_trim(format);
				if (strlen(format)) {
					A4GL_add_str_attr(fld,FA_S_FORMAT,format);
				}
				break;
			}
		}
	}
	
	cnt=0;
	if (strcmp(the_form.dbname,"formonly")!=0) {
	while (1) {
		char *att_color;
		char *att_inverse;
		char *att_underline;
		char *att_blink;
		char *att_left;
		char *att_condition;
		int attr=0;
		int used=0;

		// format has already been handled...
		att_color=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"color");

		if (att_color) {
			used++;
			att_color=strdup(att_color);
			A4GL_trim(att_color);
			if (strlen(att_color)>0) {
				attr+=atoi(att_color);
			}
			free(att_color);
		}

		att_inverse=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"inverse");
		if (att_inverse) {
			used++;
			att_inverse=strdup(att_inverse);
			A4GL_trim(att_inverse);
			if (strlen(att_inverse)) {
				if (strcmp(att_inverse,"y")==0) {
					attr+=A4GL_get_attr_from_string("REVERSE");
				}
			}
		}

		att_underline=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"underline");
		if (att_underline) {
			used++;
			att_underline=strdup(att_underline);
			A4GL_trim(att_underline);
			if (strlen(att_underline)) {
				if (strcmp(att_underline,"y")==0) {
					attr+=A4GL_get_attr_from_string("UNDERLINE");
				}
			}
		}

		att_blink=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"blink");
		if (att_blink) {
			used++;
			att_blink=strdup(att_blink);
			if (strlen(att_blink)) {
				if (strcmp(att_blink,"y")==0) {
					attr+=A4GL_get_attr_from_string("BLINK");
				}
			}
		}

		att_left=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"left");
		if (att_left) {
			used++;
			att_left=strdup(att_left);
			A4GL_trim(att_left);
			if (strlen(att_left)) {
				if (strcmp(att_left,"y")==0) {
					attr+=A4GL_get_attr_from_string("LEFT");
				}
			}

		}

		att_condition=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"condition");
		if (att_condition) {
			used++;
			att_condition=strdup(att_condition);
			A4GL_trim(att_condition);
			if (strlen(att_condition)) {
				//printf("%s\n", att_condition);
				fprintf(stderr, "Conditions in upscol are not handled yet (%s)",att_condition);
			}
		}
		if (!used) {
				break;
		}

		if (attr) {
		        int a;
                        struct  u_expression *e_true;
                        e_true=create_int_expr(1);
                        fld->colours.colours_len++;
                        a=fld->colours.colours_len;
                        fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
                        fld->colours.colours_val[a-1].colour=attr;
                        fld->colours.colours_val[a-1].whereexpr=e_true;

		}

		cnt++;
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

  case 128:
#line 894 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 129:
#line 898 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 130:
#line 906 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 131:
#line 907 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 132:
#line 910 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 133:
#line 911 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 134:
#line 914 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 135:
#line 917 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 136:
#line 922 "screen.yacc"
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

  case 137:
#line 931 "screen.yacc"
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

  case 138:
#line 943 "screen.yacc"
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

  case 139:
#line 955 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 140:
#line 962 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 141:
#line 970 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 142:
#line 977 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 143:
#line 990 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 144:
#line 999 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 145:
#line 1008 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 147:
#line 1017 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 148:
#line 1020 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 149:
#line 1026 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 150:
#line 1027 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 151:
#line 1028 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 152:
#line 1029 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 159:
#line 1045 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 160:
#line 1046 "screen.yacc"
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

  case 161:
#line 1066 "screen.yacc"
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

  case 162:
#line 1088 "screen.yacc"
    {
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 163:
#line 1094 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 164:
#line 1095 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 165:
#line 1096 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 166:
#line 1097 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 167:
#line 1098 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 168:
#line 1099 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 169:
#line 1100 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 170:
#line 1101 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 171:
#line 1102 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 172:
#line 1103 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 173:
#line 1104 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 174:
#line 1105 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 175:
#line 1106 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 176:
#line 1107 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 177:
#line 1108 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 178:
#line 1109 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 179:
#line 1110 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 180:
#line 1111 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 181:
#line 1113 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 182:
#line 1115 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 183:
#line 1116 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 184:
#line 1117 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 185:
#line 1118 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REQUIRED); }
    break;

  case 186:
#line 1119 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REVERSE); }
    break;

  case 187:
#line 1120 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 188:
#line 1121 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_QUERYCLEAR); }
    break;

  case 189:
#line 1122 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_ZEROFILL); }
    break;

  case 190:
#line 1123 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_RIGHT); }
    break;

  case 191:
#line 1124 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WORDWRAP); }
    break;

  case 192:
#line 1125 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 193:
#line 1129 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 194:
#line 1136 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_HIDDEN); }
    break;

  case 195:
#line 1137 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTOSCALE); }
    break;

  case 196:
#line 1138 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WANTNORETURNS); }
    break;

  case 197:
#line 1139 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WANTTABS); }
    break;

  case 198:
#line 1140 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_FONTPITCHFIXED); }
    break;

  case 199:
#line 1141 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_FONTPITCHVARIABLE); }
    break;

  case 200:
#line 1142 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLL); }
    break;

  case 201:
#line 1143 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 202:
#line 1144 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 203:
#line 1145 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 204:
#line 1146 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_BOTH); }
    break;

  case 205:
#line 1147 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 206:
#line 1148 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 207:
#line 1149 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_STRETCH_Y); }
    break;

  case 208:
#line 1150 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_STRETCH_BOTH); }
    break;

  case 209:
#line 1151 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 210:
#line 1152 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 211:
#line 1153 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 212:
#line 1154 "screen.yacc"
    { A4GL_add_str_attr(fld, FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 213:
#line 1160 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 214:
#line 1161 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 215:
#line 1162 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 217:
#line 1167 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 218:
#line 1171 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 219:
#line 1172 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 220:
#line 1173 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 221:
#line 1174 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 222:
#line 1175 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 223:
#line 1176 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 224:
#line 1177 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 225:
#line 1178 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 226:
#line 1180 "screen.yacc"
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

  case 227:
#line 1194 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 228:
#line 1195 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 229:
#line 1196 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 230:
#line 1197 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 231:
#line 1198 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 232:
#line 1199 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 233:
#line 1200 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 240:
#line 1213 "screen.yacc"
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

  case 241:
#line 1223 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 242:
#line 1229 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 249:
#line 1240 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 250:
#line 1240 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 253:
#line 1245 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 254:
#line 1248 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 255:
#line 1254 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 256:
#line 1257 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 259:
#line 1267 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),""); }
    break;

  case 260:
#line 1269 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); }
    break;

  case 261:
#line 1271 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); }
    break;

  case 262:
#line 1273 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); }
    break;

  case 263:
#line 1275 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 265:
#line 1279 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 266:
#line 1283 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 267:
#line 1286 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 268:
#line 1290 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 269:
#line 1290 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 272:
#line 1297 "screen.yacc"
    {colno++;}
    break;

  case 273:
#line 1298 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 274:
#line 1311 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 275:
#line 1319 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 276:
#line 1321 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 277:
#line 1328 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 278:
#line 1332 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 279:
#line 1336 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 280:
#line 1340 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 281:
#line 1344 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 282:
#line 1348 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 283:
#line 1352 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 284:
#line 1358 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 285:
#line 1362 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 286:
#line 1366 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 287:
#line 1370 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 288:
#line 1374 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 289:
#line 1378 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 290:
#line 1382 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 291:
#line 1385 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 293:
#line 1392 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 295:
#line 1396 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 298:
#line 1401 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 299:
#line 1405 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 300:
#line 1412 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 301:
#line 1413 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 303:
#line 1415 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 304:
#line 1421 "screen.yacc"
    { 
	if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
		sprintf((yyval.str),"NULL");
	} else {
		strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
	}
}
    break;

  case 305:
#line 1428 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 306:
#line 1429 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 307:
#line 1430 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 308:
#line 1431 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 310:
#line 1433 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 311:
#line 1434 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 312:
#line 1435 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 313:
#line 1439 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 314:
#line 1443 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 315:
#line 1448 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 316:
#line 1451 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 317:
#line 1452 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 318:
#line 1455 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 319:
#line 1457 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 320:
#line 1463 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 321:
#line 1465 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 322:
#line 1470 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 323:
#line 1478 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 324:
#line 1481 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 325:
#line 1482 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 326:
#line 1483 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 327:
#line 1484 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 328:
#line 1485 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 329:
#line 1486 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 330:
#line 1488 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 332:
#line 1495 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 333:
#line 1496 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 334:
#line 1499 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 335:
#line 1502 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 336:
#line 1506 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 337:
#line 1507 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 338:
#line 1508 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 339:
#line 1509 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 340:
#line 1510 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 341:
#line 1511 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 342:
#line 1513 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 343:
#line 1518 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 344:
#line 1520 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 345:
#line 1527 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 346:
#line 1527 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 347:
#line 1533 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 349:
#line 1540 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 350:
#line 1543 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 351:
#line 1549 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 352:
#line 1550 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 353:
#line 1551 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 354:
#line 1552 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 355:
#line 1553 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 356:
#line 1554 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 357:
#line 1555 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 358:
#line 1556 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 359:
#line 1557 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 360:
#line 1558 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 361:
#line 1559 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 362:
#line 1560 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 363:
#line 1561 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 364:
#line 1564 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 365:
#line 1571 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 366:
#line 1572 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 367:
#line 1573 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 369:
#line 1581 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 370:
#line 1585 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 374:
#line 1605 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 375:
#line 1615 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 376:
#line 1622 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 377:
#line 1631 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 378:
#line 1634 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 381:
#line 1653 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 382:
#line 1660 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 383:
#line 1668 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 384:
#line 1673 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 385:
#line 1681 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 386:
#line 1685 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 387:
#line 1690 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 388:
#line 1695 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 389:
#line 1700 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 390:
#line 1705 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 391:
#line 1710 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 392:
#line 1719 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 393:
#line 1728 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 394:
#line 1729 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 396:
#line 1738 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 397:
#line 1746 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 398:
#line 1752 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 399:
#line 1758 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 400:
#line 1764 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 401:
#line 1772 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 402:
#line 1777 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 403:
#line 1787 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 404:
#line 1797 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 405:
#line 1803 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 406:
#line 1809 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 407:
#line 1815 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 408:
#line 1825 "screen.yacc"
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

  case 409:
#line 1837 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 410:
#line 1845 "screen.yacc"
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

  case 411:
#line 1857 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 412:
#line 1865 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 413:
#line 1866 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 414:
#line 1867 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 415:
#line 1871 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 416:
#line 1872 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 417:
#line 1873 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 418:
#line 1874 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 419:
#line 1875 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 420:
#line 1876 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 421:
#line 1877 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 422:
#line 1880 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 423:
#line 1887 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 424:
#line 1898 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 425:
#line 1902 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 426:
#line 1909 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 427:
#line 1917 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 428:
#line 1922 "screen.yacc"
    {
		if ((yyvsp[(5) - (6)].el)) {
			listitem *l;
			(yyval.fcall)->list_parameters.list_parameters_len=(yyvsp[(5) - (6)].el)->nlist;
			l=(yyvsp[(5) - (6)].el)->expr_list;
			(yyval.fcall)->list_parameters.list_parameters_val=l;
		}
	}
    break;

  case 429:
#line 1933 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 430:
#line 1934 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 431:
#line 1940 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 432:
#line 1946 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 433:
#line 1954 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 435:
#line 1962 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 436:
#line 1963 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 441:
#line 1977 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 442:
#line 1979 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 443:
#line 1980 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 444:
#line 1981 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 445:
#line 1982 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 446:
#line 1983 "screen.yacc"
    { (yyval.expr)=(yyvsp[(3) - (4)].expr); }
    break;

  case 447:
#line 1984 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 448:
#line 1985 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 449:
#line 1986 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 450:
#line 1987 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 451:
#line 1988 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 452:
#line 1989 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 453:
#line 1990 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 454:
#line 1991 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 455:
#line 1992 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 456:
#line 1993 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 457:
#line 1994 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 458:
#line 1995 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 459:
#line 1996 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 460:
#line 1997 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 461:
#line 1998 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 462:
#line 1999 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 464:
#line 2005 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 465:
#line 2006 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 466:
#line 2007 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 467:
#line 2008 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 468:
#line 2009 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 469:
#line 2012 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 470:
#line 2016 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 6646 "y.tab.c"
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


#line 2339 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




