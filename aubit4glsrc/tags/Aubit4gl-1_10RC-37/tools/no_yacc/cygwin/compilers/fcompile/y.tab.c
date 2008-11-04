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
     KW_BROWSER = 465,
     KW_VALUECHECKED = 466,
     KW_VALUEUNCHECKED = 467,
     KW_CHECKBOX = 468
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
#define KW_VALUECHECKED 466
#define KW_VALUEUNCHECKED 467
#define KW_CHECKBOX 468




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

//struct local_expr_list { listitem *expr_list; int nlist; };


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
#line 75 "screen.yacc"
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
#line 623 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 636 "y.tab.c"

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
#define YYFINAL  140
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4929

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  160
/* YYNRULES -- Number of rules.  */
#define YYNRULES  728
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   468

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
     205,   206,   207,   208,   209,   210,   211,   212,   213
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
     336,   337,   343,   345,   348,   352,   353,   354,   361,   362,
     366,   372,   376,   378,   379,   385,   389,   392,   397,   400,
     405,   409,   411,   416,   419,   421,   425,   429,   431,   435,
     437,   441,   443,   448,   451,   453,   456,   457,   460,   462,
     466,   468,   473,   476,   481,   485,   489,   493,   497,   503,
     507,   513,   515,   517,   521,   527,   531,   535,   539,   541,
     546,   548,   550,   552,   554,   558,   562,   564,   566,   568,
     570,   572,   574,   576,   579,   582,   584,   586,   588,   590,
     594,   598,   600,   604,   608,   612,   614,   616,   618,   620,
     622,   628,   632,   636,   640,   644,   648,   652,   656,   660,
     662,   664,   666,   668,   671,   673,   675,   677,   679,   681,
     683,   685,   687,   689,   691,   693,   695,   697,   699,   701,
     703,   704,   708,   710,   713,   715,   718,   721,   723,   724,
     734,   747,   749,   751,   752,   755,   756,   758,   759,   761,
     763,   768,   770,   774,   775,   777,   779,   783,   787,   791,
     795,   797,   801,   803,   805,   806,   808,   810,   813,   815,
     817,   819,   820,   825,   827,   829,   831,   833,   835,   837,
     840,   843,   846,   849,   851,   853,   855,   857,   859,   861,
     865,   867,   871,   873,   876,   879,   881,   883,   885,   887,
     889,   891,   893,   897,   901,   903,   905,   909,   913,   917,
     921,   923,   924,   928,   934,   935,   939,   940,   944,   946,
     949,   951,   953,   955,   957,   959,   961,   964,   966,   967,
     971,   973,   975,   977,   979,   981,   983,   985,   987,   990,
     991,   995,   996,   998,  1001,  1003,  1007,  1011,  1015,  1019,
    1023,  1027,  1032,  1036,  1039,  1042,  1044,  1050,  1056,  1059,
    1063,  1065,  1067,  1069,  1071,  1073,  1075,  1079,  1082,  1084,
    1087,  1095,  1097,  1101,  1105,  1107,  1109,  1111,  1117,  1123,
    1126,  1129,  1131,  1133,  1135,  1137,  1139,  1141,  1143,  1149,
    1150,  1153,  1155,  1160,  1163,  1167,  1170,  1174,  1178,  1180,
    1183,  1186,  1190,  1194,  1199,  1201,  1204,  1206,  1209,  1211,
    1213,  1215,  1217,  1219,  1221,  1223,  1225,  1227,  1229,  1231,
    1235,  1239,  1241,  1246,  1247,  1254,  1255,  1257,  1259,  1263,
    1265,  1267,  1271,  1275,  1278,  1281,  1283,  1286,  1290,  1295,
    1299,  1303,  1307,  1311,  1315,  1319,  1323,  1327,  1331,  1336,
    1340,  1343,  1346,  1352,  1358,  1365,  1367,  1369,  1371,  1373,
    1375,  1377,  1379,  1383,  1385,  1387,  1389,  1391,  1393,  1395,
    1397,  1399,  1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,
    1417,  1419,  1421,  1423,  1425,  1427,  1429,  1431,  1433,  1435,
    1437,  1439,  1441,  1443,  1445,  1447,  1449,  1451,  1453,  1455,
    1457,  1459,  1461,  1463,  1465,  1467,  1469,  1471,  1473,  1475,
    1477,  1479,  1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,
    1497,  1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,
    1517,  1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,
    1537,  1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,
    1557,  1559,  1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,
    1577,  1579,  1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,
    1597,  1599,  1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,
    1617,  1619,  1621,  1623,  1625,  1627,  1629,  1631,  1633,  1635,
    1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,  1655,
    1657,  1659,  1661,  1663,  1665,  1667,  1669,  1671,  1673,  1675,
    1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,
    1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,  1715,
    1717,  1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,
    1737,  1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,
    1757,  1759,  1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,
    1777,  1779,  1781,  1783,  1785,  1787,  1789,  1791,  1793,  1795,
    1797,  1799,  1801,  1803,  1805,  1807,  1809,  1811,  1813,  1815,
    1817,  1819,  1821,  1823,  1825,  1827,  1829,  1831,  1833,  1835,
    1837,  1839,  1841,  1843,  1845,  1847,  1849,  1851,  1853,  1855,
    1857,  1859,  1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,
    1877,  1879,  1881,  1883,  1885,  1887,  1889,  1891,  1893
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     215,     0,    -1,   216,   220,   263,   268,   293,    -1,    21,
      34,    -1,    21,   219,    40,    41,    42,    -1,    21,    34,
      40,    41,    42,    -1,    21,   219,    -1,    30,    -1,   372,
      -1,    30,    -1,   373,    -1,   172,    -1,   172,    38,   218,
      -1,   217,    -1,   217,    38,   218,    -1,   244,    -1,   243,
      -1,   176,   227,   236,   240,    27,    -1,   175,   227,   236,
     240,    27,    -1,   178,   227,   236,   240,    27,    -1,   180,
     227,   236,   225,    27,    -1,   226,    -1,   225,   226,    -1,
     174,   227,   236,   240,    27,    -1,    -1,   218,    -1,    -1,
      -1,    -1,   177,   229,   227,   236,    31,   230,   255,    32,
     231,    27,    -1,    -1,    -1,    -1,   179,   233,   227,   236,
      31,   234,   255,    32,   235,    27,    -1,    -1,    -1,    51,
     237,   239,    52,    -1,   181,    45,    46,    -1,   183,    -1,
     113,    45,    46,    -1,   173,    45,    30,    -1,   238,    -1,
     239,   238,    -1,   239,    58,   238,    -1,    -1,   241,    -1,
     242,    -1,   241,   242,    -1,   221,    -1,   222,    -1,   223,
      -1,   224,    -1,   228,    -1,   232,    -1,   182,   242,   254,
      -1,   245,    -1,   244,   245,    -1,    -1,    24,   246,   248,
      -1,    -1,    23,    46,   247,   248,    -1,    -1,    -1,    -1,
     253,   249,   252,    31,   250,   255,    32,   251,   254,    -1,
      -1,   171,    -1,    -1,    25,    29,    -1,    25,    29,    22,
      29,    -1,    -1,    27,    -1,   257,    -1,   255,   257,    -1,
     218,    -1,   256,    -1,   259,    -1,   145,    -1,    17,    -1,
      44,    -1,    46,    -1,   258,    -1,   144,    -1,   120,    -1,
     116,    -1,    16,    -1,   258,    16,    -1,    -1,    26,   260,
     261,    28,    -1,   311,    -1,    -1,   261,    44,   262,   311,
      -1,    -1,    43,   264,   254,    -1,   265,    -1,   264,   265,
      -1,   264,    58,   265,    -1,   218,   266,    -1,    -1,    45,
     267,    -1,   218,    -1,   218,    37,   218,    -1,   218,    38,
     218,    -1,   218,    38,   218,    37,   218,    -1,   218,    39,
     218,    -1,    46,    39,   218,    -1,    20,   269,   254,    -1,
     271,    -1,   269,   271,    -1,    -1,   187,    -1,   184,    -1,
     186,    -1,   188,    -1,   185,    -1,   190,    -1,   207,    -1,
     208,    -1,   213,    -1,   210,    -1,    -1,   270,   310,   272,
     273,    47,    -1,   274,    -1,   273,   274,    -1,   273,    47,
     274,    -1,    -1,    -1,    45,   275,   280,   277,   276,   287,
      -1,    -1,    26,    29,    28,    -1,    26,    29,    58,    29,
      28,    -1,   279,   126,    41,    -1,   279,    -1,    -1,    60,
      72,   218,    39,   218,    -1,    60,    72,   218,    -1,    60,
     313,    -1,    34,    39,   306,   278,    -1,   142,   278,    -1,
     142,   143,    42,   278,    -1,   218,    39,   218,    -1,   218,
      -1,    53,   218,    39,   218,    -1,    53,   218,    -1,   282,
      -1,   281,    58,   282,    -1,   283,    45,   284,    -1,   310,
      -1,   218,    39,   218,    -1,   218,    -1,   218,    39,   218,
      -1,   218,    -1,    53,   218,    39,   218,    -1,    53,   218,
      -1,    49,    -1,    58,    49,    -1,    -1,    58,   288,    -1,
     289,    -1,   288,    58,   289,    -1,    88,    -1,    89,    45,
     291,   331,    -1,    50,   285,    -1,    48,   281,   286,   285,
      -1,    90,    45,    46,    -1,    91,    45,   290,    -1,   209,
      45,   290,    -1,    93,    72,   218,    -1,    93,    72,   218,
      39,   218,    -1,    92,    72,   218,    -1,    92,    72,   218,
      39,   218,    -1,    94,    -1,    95,    -1,    96,    45,    46,
      -1,    97,    45,    51,   314,    52,    -1,   118,    45,    46,
      -1,   119,    45,    46,    -1,   173,    45,   218,    -1,    98,
      -1,    36,    25,    45,    29,    -1,    36,    -1,   117,    -1,
     100,    -1,    99,    -1,   101,    45,    46,    -1,   102,    45,
      46,    -1,   103,    -1,    82,    -1,   105,    -1,   104,    -1,
     170,    -1,   169,    -1,   106,    -1,   106,   107,    -1,   106,
     108,    -1,   183,    -1,   196,    -1,   194,    -1,   195,    -1,
     191,    45,   192,    -1,   191,    45,   193,    -1,   189,    -1,
     190,    45,    46,    -1,   198,    45,    29,    -1,   197,    45,
      29,    -1,   199,    -1,   200,    -1,   201,    -1,   202,    -1,
     203,    -1,   204,    45,    51,   315,    52,    -1,   205,    45,
      29,    -1,   206,    45,    29,    -1,   211,    45,    46,    -1,
     212,    45,    46,    -1,   211,    45,    29,    -1,   212,    45,
      29,    -1,   113,    45,    46,    -1,   181,    45,    46,    -1,
      46,    -1,    29,    -1,   115,    -1,   292,    -1,   291,   292,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    80,    -1,    29,    -1,    82,
      -1,    87,    -1,    81,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    -1,    19,   294,   254,    -1,   295,    -1,
     294,   295,    -1,   296,    -1,   296,    47,    -1,    61,    46,
      -1,   345,    -1,    -1,    24,    57,   297,   301,    51,   302,
      52,   298,   300,    -1,   141,    51,    29,    58,    29,    52,
     109,    51,    29,    58,    29,    52,    -1,   338,    -1,   361,
      -1,    -1,   110,   139,    -1,    -1,    53,    -1,    -1,    47,
      -1,   218,    -1,   218,    26,    29,    28,    -1,   305,    -1,
     302,   303,   305,    -1,    -1,    58,    -1,   218,    -1,   218,
      39,   218,    -1,    34,    39,   218,    -1,   218,    39,    53,
      -1,    34,    39,    53,    -1,   304,    -1,   304,    59,   304,
      -1,   218,    -1,    27,    -1,    -1,   308,    -1,   309,    -1,
     308,   309,    -1,   144,    -1,   145,    -1,   218,    -1,    -1,
     307,   218,   312,   307,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,   319,    -1,
      69,   319,    -1,    70,   326,    -1,    71,   320,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,    -1,   140,    -1,   318,
      -1,   314,    58,   318,    -1,   317,    -1,   315,    58,   317,
      -1,    29,    -1,    55,    29,    -1,    56,    29,    -1,    46,
      -1,    30,    -1,    16,    -1,   316,    -1,    41,    -1,    46,
      -1,    30,    -1,    30,   109,    30,    -1,    30,    37,    30,
      -1,    16,    -1,   316,    -1,   316,   109,   316,    -1,   316,
      37,   316,    -1,    46,   109,    46,    -1,    46,    37,    46,
      -1,    41,    -1,    -1,    51,    29,    52,    -1,    51,    29,
      58,    29,    52,    -1,    -1,   323,   109,   325,    -1,    -1,
      51,    29,    52,    -1,    29,    -1,   324,   321,    -1,   132,
      -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,   138,   330,    -1,   324,    -1,    -1,   327,   109,   328,
      -1,   329,    -1,   329,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,   330,    -1,
      -1,    51,   322,    52,    -1,    -1,   332,    -1,   125,   333,
      -1,   334,    -1,   334,   123,   334,    -1,   334,   122,   334,
      -1,   335,   121,   335,    -1,   335,     8,   335,    -1,   335,
       9,   335,    -1,   335,    72,   335,    -1,   335,   126,    72,
     335,    -1,   335,    45,   335,    -1,   335,   130,    -1,   335,
     131,    -1,   335,    -1,   335,   127,   335,   123,   335,    -1,
     335,   128,    51,   337,    52,    -1,   126,   334,    -1,    51,
     334,    52,    -1,   336,    -1,    29,    -1,    46,    -1,   129,
      -1,    30,    -1,   335,    -1,   337,    58,   335,    -1,    18,
     339,    -1,   340,    -1,   339,   340,    -1,     8,   341,     9,
     299,     8,   341,     9,    -1,   342,    -1,   341,    58,   342,
      -1,   343,    39,   344,    -1,   344,    -1,   218,    -1,   217,
      -1,   147,   355,   152,   359,   353,    -1,   148,   356,   152,
     359,   353,    -1,   157,   362,    -1,   156,   362,    -1,   349,
      -1,   354,    -1,   347,    -1,   350,    -1,   351,    -1,   362,
      -1,   352,    -1,   164,   367,   165,   346,   348,    -1,    -1,
     166,   346,    -1,   160,    -1,   161,   310,    45,   367,    -1,
     163,   310,    -1,   163,    45,   310,    -1,   163,   162,    -1,
     163,    45,   162,    -1,   167,   353,    27,    -1,   346,    -1,
     353,   346,    -1,    90,    46,    -1,    90,   159,    46,    -1,
      90,    82,    46,    -1,    90,   159,    82,    46,    -1,   357,
      -1,   355,   357,    -1,   358,    -1,   356,   358,    -1,   149,
      -1,   150,    -1,   151,    -1,   149,    -1,   153,    -1,   154,
      -1,   155,    -1,   151,    -1,    93,    -1,   150,    -1,   360,
      -1,   359,   303,   360,    -1,   343,    39,   344,    -1,   344,
      -1,   343,   146,   343,   300,    -1,    -1,   158,   218,    51,
     363,   364,    52,    -1,    -1,   365,    -1,   366,    -1,   365,
      58,   366,    -1,   367,    -1,   368,    -1,   367,   123,   367,
      -1,   367,   122,   367,    -1,    56,   367,    -1,    55,   367,
      -1,   370,    -1,   126,   367,    -1,    51,   367,    52,    -1,
     369,    51,   364,    52,    -1,   168,   152,   310,    -1,   367,
     121,   367,    -1,   367,     8,   367,    -1,   367,     9,   367,
      -1,   367,    53,   367,    -1,   367,    55,   367,    -1,   367,
      56,   367,    -1,   367,    54,   367,    -1,   367,    72,   367,
      -1,   367,   126,    72,   367,    -1,   367,    45,   367,    -1,
     367,   130,    -1,   367,   131,    -1,   367,   127,   367,   123,
     367,    -1,   367,   128,    51,   371,    52,    -1,   367,   126,
     128,    51,   371,    52,    -1,   218,    -1,   310,    -1,    29,
      -1,    46,    -1,   129,    -1,    41,    -1,   370,    -1,   371,
      58,   370,    -1,    18,    -1,    20,    -1,    21,    -1,    22,
      -1,    25,    -1,    19,    -1,    27,    -1,    33,    -1,    35,
      -1,    36,    -1,    41,    -1,    42,    -1,    43,    -1,    48,
      -1,    49,    -1,    57,    -1,    59,    -1,    60,    -1,    61,
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
      -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,   116,
      -1,   117,    -1,   118,    -1,   209,    -1,   119,    -1,   121,
      -1,     8,    -1,     9,    -1,   122,    -1,   123,    -1,   125,
      -1,   126,    -1,   127,    -1,   128,    -1,   129,    -1,   130,
      -1,   131,    -1,   132,    -1,   133,    -1,   134,    -1,   135,
      -1,   136,    -1,   137,    -1,   138,    -1,   139,    -1,   140,
      -1,   141,    -1,   142,    -1,   143,    -1,   146,    -1,   147,
      -1,   148,    -1,   149,    -1,   150,    -1,   151,    -1,   152,
      -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,   157,
      -1,   158,    -1,   159,    -1,   160,    -1,   161,    -1,   162,
      -1,   163,    -1,   164,    -1,   165,    -1,   166,    -1,   167,
      -1,   168,    -1,   169,    -1,   170,    -1,   171,    -1,   173,
      -1,   204,    -1,    18,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    40,    -1,    42,    -1,    43,    -1,    48,
      -1,    49,    -1,    57,    -1,    59,    -1,    60,    -1,    61,
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
      -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,   117,
      -1,   118,    -1,   209,    -1,   119,    -1,   121,    -1,     8,
      -1,     9,    -1,   122,    -1,   123,    -1,   125,    -1,   126,
      -1,   127,    -1,   128,    -1,   130,    -1,   131,    -1,   132,
      -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,   138,    -1,   139,    -1,   140,    -1,   141,    -1,   143,
      -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,
      -1,   151,    -1,   152,    -1,   153,    -1,   154,    -1,   155,
      -1,   156,    -1,   157,    -1,   158,    -1,   159,    -1,   160,
      -1,   161,    -1,   163,    -1,   164,    -1,   165,    -1,   166,
      -1,   167,    -1,   168,    -1,   169,    -1,   170,    -1,   171,
      -1,   173,    -1,   204,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   149,   150,   155,   156,   165,   166,   170,
     171,   175,   176,   177,   178,   183,   186,   193,   203,   212,
     225,   233,   243,   251,   264,   265,   270,   273,   276,   269,
     292,   295,   298,   291,   312,   315,   315,   321,   324,   327,
     330,   336,   337,   338,   342,   351,   357,   367,   374,   376,
     378,   380,   382,   384,   389,   399,   399,   402,   402,   415,
     415,   434,   436,   439,   434,   444,   444,   449,   450,   451,
     463,   464,   469,   470,   473,   488,   500,   501,   512,   523,
     536,   548,   559,   564,   567,   575,   576,   582,   581,   603,
     606,   606,   624,   625,   628,   629,   630,   633,   642,   643,
     646,   647,   648,   650,   651,   652,   658,   662,   662,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     682,   681,   700,   701,   702,   706,   710,   706,   891,   892,
     896,   904,   905,   908,   909,   912,   915,   920,   929,   941,
     953,   960,   968,   975,   988,   997,  1006,  1013,  1015,  1018,
    1024,  1025,  1026,  1027,  1030,  1031,  1035,  1036,  1040,  1040,
    1043,  1044,  1064,  1086,  1092,  1093,  1094,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1111,  1113,  1114,  1115,  1116,  1117,  1118,  1119,
    1120,  1121,  1122,  1123,  1127,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,
    1149,  1150,  1151,  1153,  1154,  1155,  1156,  1157,  1158,  1164,
    1165,  1166,  1170,  1171,  1175,  1176,  1177,  1178,  1179,  1180,
    1181,  1182,  1184,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1208,  1209,  1212,  1212,  1214,  1214,  1217,  1227,  1233,  1233,
    1236,  1237,  1238,  1242,  1242,  1244,  1244,  1247,  1247,  1249,
    1252,  1258,  1261,  1265,  1266,  1270,  1272,  1274,  1276,  1278,
    1283,  1283,  1287,  1290,  1294,  1294,  1297,  1297,  1301,  1302,
    1315,  1323,  1323,  1332,  1336,  1340,  1344,  1348,  1352,  1356,
    1362,  1366,  1370,  1374,  1378,  1382,  1386,  1389,  1396,  1396,
    1400,  1400,  1405,  1405,  1405,  1409,  1416,  1417,  1418,  1419,
    1425,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1443,
    1447,  1452,  1455,  1456,  1459,  1460,  1467,  1469,  1474,  1482,
    1485,  1486,  1487,  1488,  1489,  1490,  1491,  1497,  1499,  1500,
    1503,  1506,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1522,
    1524,  1531,  1531,  1537,  1543,  1544,  1547,  1553,  1554,  1555,
    1556,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,
    1568,  1575,  1576,  1577,  1582,  1585,  1589,  1601,  1604,  1605,
    1609,  1619,  1626,  1635,  1638,  1650,  1653,  1657,  1664,  1672,
    1677,  1685,  1689,  1694,  1699,  1704,  1709,  1714,  1723,  1732,
    1733,  1738,  1741,  1749,  1755,  1761,  1767,  1776,  1781,  1791,
    1801,  1807,  1813,  1819,  1829,  1841,  1849,  1861,  1869,  1870,
    1871,  1875,  1876,  1877,  1878,  1879,  1880,  1881,  1884,  1891,
    1902,  1906,  1913,  1921,  1921,  1939,  1940,  1946,  1952,  1960,
    1967,  1968,  1969,  1983,  1985,  1986,  1987,  1988,  1989,  1992,
    1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,  2001,  2002,
    2003,  2004,  2005,  2006,  2007,  2010,  2013,  2014,  2015,  2016,
    2017,  2020,  2024,  2035,  2037,  2038,  2039,  2040,  2041,  2043,
    2044,  2045,  2046,  2047,  2048,  2049,  2050,  2051,  2052,  2053,
    2054,  2055,  2056,  2057,  2058,  2059,  2060,  2061,  2062,  2063,
    2064,  2065,  2066,  2067,  2068,  2069,  2070,  2071,  2072,  2073,
    2074,  2075,  2076,  2077,  2078,  2079,  2080,  2081,  2082,  2083,
    2084,  2085,  2086,  2087,  2088,  2089,  2090,  2091,  2092,  2093,
    2094,  2095,  2096,  2097,  2098,  2099,  2100,  2101,  2102,  2103,
    2104,  2105,  2106,  2107,  2108,  2109,  2110,  2111,  2112,  2113,
    2114,  2115,  2116,  2117,  2118,  2119,  2120,  2121,  2122,  2123,
    2124,  2125,  2126,  2127,  2128,  2129,  2130,  2131,  2132,  2133,
    2134,  2135,  2136,  2137,  2138,  2139,  2140,  2141,  2142,  2143,
    2144,  2145,  2146,  2147,  2148,  2149,  2150,  2151,  2152,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  2195,  2196,  2197,  2198,  2199,  2200,  2201,
    2202,  2203,  2204,  2205,  2206,  2207,  2208,  2209,  2210,  2211,
    2212,  2213,  2214,  2215,  2216,  2217,  2218,  2219,  2220,  2221,
    2222,  2223,  2224,  2225,  2226,  2227,  2228,  2229,  2230,  2231,
    2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239,  2240,  2241,
    2242,  2243,  2244,  2245,  2246,  2247,  2248,  2249,  2250,  2251,
    2252,  2253,  2254,  2255,  2256,  2257,  2258,  2259,  2260,  2261,
    2262,  2263,  2264,  2265,  2266,  2267,  2268,  2269,  2270,  2271,
    2272,  2273,  2274,  2275,  2276,  2277,  2278,  2279,  2280,  2281,
    2282,  2283,  2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,
    2292,  2293,  2294,  2295,  2296,  2297,  2298,  2299,  2300,  2301,
    2302,  2303,  2304,  2305,  2306,  2307,  2308,  2309,  2310,  2311,
    2312,  2313,  2314,  2315,  2316,  2317,  2318,  2319,  2320
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
  "KW_COMBOBOX", "OPTIONS", "KW_BROWSER", "KW_VALUECHECKED",
  "KW_VALUEUNCHECKED", "KW_CHECKBOX", "$accept", "form_def",
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
  "func_call_arg", "expression", "single_expression", "fcall_name",
  "evalue", "evalue_list", "st_kword", "any_kword", 0
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
     465,   466,   467,   468
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   214,   215,   216,   216,   216,   216,   217,   217,   218,
     218,   219,   219,   219,   219,   220,   220,   221,   222,   223,
     224,   225,   225,   226,   227,   227,   229,   230,   231,   228,
     233,   234,   235,   232,   236,   237,   236,   238,   238,   238,
     238,   239,   239,   239,   240,   240,   241,   241,   242,   242,
     242,   242,   242,   242,   243,   244,   244,   246,   245,   247,
     245,   249,   250,   251,   248,   252,   252,   253,   253,   253,
     254,   254,   255,   255,   256,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   258,   258,   260,   259,   261,
     262,   261,   263,   263,   264,   264,   264,   265,   266,   266,
     267,   267,   267,   267,   267,   267,   268,   269,   269,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     272,   271,   273,   273,   273,   275,   276,   274,   277,   277,
     277,   278,   278,   279,   279,   279,   279,   280,   280,   280,
     280,   280,   280,   280,   281,   281,   282,   283,   284,   284,
     285,   285,   285,   285,   286,   286,   287,   287,   288,   288,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   290,
     290,   290,   291,   291,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     293,   293,   294,   294,   295,   295,   296,   296,   297,   296,
     296,   296,   296,   298,   298,   299,   299,   300,   300,   301,
     301,   302,   302,   303,   303,   304,   304,   304,   304,   304,
     305,   305,   306,   306,   307,   307,   308,   308,   309,   309,
     310,   312,   311,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   314,
     315,   315,   316,   316,   316,   317,   317,   317,   317,   317,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   319,   319,   319,   320,   320,   321,   321,   322,   323,
     324,   324,   324,   324,   324,   324,   324,   325,   326,   326,
     327,   328,   329,   329,   329,   329,   329,   329,   329,   330,
     330,   331,   331,   332,   333,   333,   333,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     335,   335,   335,   335,   336,   337,   337,   338,   339,   339,
     340,   341,   341,   342,   342,   343,   344,   345,   345,   345,
     345,   346,   346,   346,   346,   346,   346,   346,   347,   348,
     348,   349,   350,   351,   351,   351,   351,   352,   353,   353,
     354,   354,   354,   354,   355,   355,   356,   356,   357,   357,
     357,   358,   358,   358,   358,   358,   358,   358,   359,   359,
     360,   360,   361,   363,   362,   364,   364,   365,   365,   366,
     367,   367,   367,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   369,   370,   370,   370,   370,
     370,   371,   371,   372,   372,   372,   372,   372,   372,   372,
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
     372,   372,   372,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     1,     2,     3,     0,     0,     6,     0,     3,
       5,     3,     1,     0,     5,     3,     2,     4,     2,     4,
       3,     1,     4,     2,     1,     3,     3,     1,     3,     1,
       3,     1,     4,     2,     1,     2,     0,     2,     1,     3,
       1,     4,     2,     4,     3,     3,     3,     3,     5,     3,
       5,     1,     1,     3,     5,     3,     3,     3,     1,     4,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     1,     2,     1,     2,     2,     1,     0,     9,
      12,     1,     1,     0,     2,     0,     1,     0,     1,     1,
       4,     1,     3,     0,     1,     1,     3,     3,     3,     3,
       1,     3,     1,     1,     0,     1,     1,     2,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     3,     3,     3,     3,
       1,     0,     3,     5,     0,     3,     0,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     0,     1,     2,     1,     3,     3,     3,     3,     3,
       3,     4,     3,     2,     2,     1,     5,     5,     2,     3,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     2,
       7,     1,     3,     3,     1,     1,     1,     5,     5,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     5,     0,
       2,     1,     4,     2,     3,     2,     3,     3,     1,     2,
       2,     3,     3,     4,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     4,     0,     6,     0,     1,     1,     3,     1,
       1,     3,     3,     2,     2,     1,     2,     3,     4,     3,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,   552,   553,   473,   478,   474,   475,
     476,   477,   479,     7,   480,     3,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   550,   551,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,    11,   601,   602,   549,    13,     6,     8,
       1,     0,    57,     0,    92,    16,    15,    55,     0,     0,
       0,     0,    59,    67,    24,    24,    26,    24,    30,    24,
      48,    49,    50,    51,    52,    53,    70,     0,     0,    56,
       0,   681,   682,   603,   604,   605,   606,   607,   608,     9,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   656,   657,   658,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   679,
     680,   683,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   714,   715,   716,   717,   718,   719,   720,   721,
     722,   723,   724,   725,   726,   727,   728,   678,    12,    10,
      14,     0,    67,     0,    58,    61,    25,    34,    34,    24,
      34,    24,    34,    71,    54,    98,    70,    94,   109,   240,
       5,     4,    60,    68,    65,    35,    44,    44,    34,    44,
      34,     0,     0,    97,     0,    93,    95,   111,   114,   112,
     110,   113,   115,   116,   117,   119,   118,   109,     0,   107,
       0,     2,     0,    66,     0,     0,     0,    45,    46,     0,
       0,     0,     0,    24,     0,    21,     0,   100,    99,    96,
     106,   108,   280,   120,   603,   607,   621,   700,   703,   704,
     712,   713,   385,    70,   242,   244,   251,     0,   247,   252,
      69,    62,     0,     0,     0,    38,    41,     0,    18,    47,
      17,    27,    19,    31,    34,    20,    22,     0,     0,     0,
       0,     0,     0,   377,   378,   248,   246,     0,   418,   419,
     420,     0,   414,   426,   421,   427,   425,   422,   423,   424,
       0,   416,     0,   390,   389,   241,   243,   245,     0,     0,
       0,     0,     0,    36,     0,    42,     0,     0,    44,   105,
     101,   102,   104,   125,     0,   122,   552,   553,   473,   475,
     476,   477,     7,   480,   481,   482,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   547,   548,
     550,   551,   554,   555,   556,   557,   558,   559,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   549,   386,
       0,   381,     0,   384,   379,     0,     0,     0,   415,     0,
     417,     0,   257,    85,    78,    87,    79,    80,    84,    83,
      82,    77,    74,     0,    75,    72,    81,    76,    39,    40,
      37,    43,     0,     0,     0,     0,     0,   121,   123,   255,
       0,     0,   259,     0,     0,     0,   431,   263,   428,   263,
     433,   258,   432,   274,    63,    73,    86,    28,    32,    23,
     103,   610,     0,   133,   141,   128,   124,   256,     0,   382,
     383,     0,     0,     0,     0,   264,     0,   401,     0,     0,
       0,     0,     0,   408,   393,   391,   394,   395,   397,   387,
     392,   396,   388,   435,   278,   279,     0,     0,   275,   276,
      89,    70,     0,     0,     0,   143,     0,     0,   138,   132,
       0,     0,   126,     0,     0,   610,   265,   263,   270,   261,
       0,   430,   410,     0,     0,     0,     0,   405,   403,   467,
     470,   468,     0,     0,     0,   686,   469,   723,   280,   466,
       0,   440,     0,   445,     0,   429,   409,     0,   436,   437,
     439,    88,    90,   281,   277,    64,    29,    33,   273,   272,
     133,     0,   283,   284,   285,   286,   287,   288,   321,   321,
     338,   324,     0,   293,   294,   295,   296,   297,   136,   133,
       0,   140,     0,   156,     0,   260,     0,     0,   253,     0,
       0,     0,   412,   411,     0,     0,   406,   404,     0,   444,
     443,   446,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   460,   461,     0,
     435,   407,   434,     0,   274,   274,   137,   142,     0,   289,
     290,   342,   343,   344,   345,   346,   347,   349,   291,     0,
     340,   330,   331,   332,   333,   334,   335,   349,   292,     0,
     326,   135,   139,   131,   129,     0,     0,   127,   380,   269,
     267,   268,   266,     0,   257,   262,   271,     0,   413,   402,
     447,   449,   451,   452,   459,   453,   456,   454,   455,   457,
     450,   442,   441,     0,     0,     0,     0,   399,     0,   438,
      91,   282,     0,     0,   348,     0,   336,     0,     0,   329,
       0,     0,   180,     0,     0,   187,   160,     0,     0,     0,
       0,     0,   171,   172,     0,     0,   178,   183,   182,     0,
       0,   186,   189,   188,   192,     0,   181,     0,     0,   191,
     190,     0,     0,   195,   201,     0,     0,   197,   198,   196,
       0,     0,   205,   206,   207,   208,   209,     0,     0,     0,
       0,     0,     0,   157,   158,   254,   249,     0,   458,     0,
       0,   471,     0,     0,   398,   448,   322,     0,   328,     0,
     339,   341,   337,   325,     0,   134,   130,     0,     0,   144,
       0,   147,     0,   151,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   193,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   462,   463,     0,   400,     0,   350,
     327,     0,   154,     0,     0,     0,   153,     0,   232,   224,
     225,   226,   227,   228,   229,   230,   231,   235,   233,   236,
     237,   238,   239,   234,   351,   222,   164,   220,   219,   221,
     165,   169,   167,   173,     0,   184,   185,   217,   175,   176,
     177,   218,   202,   199,   200,   204,   203,     0,   211,   212,
     166,   215,   213,   216,   214,   159,     0,   464,   472,   323,
     179,   155,   145,   163,   149,   146,     0,   150,     0,   223,
     161,   352,     0,     0,   314,   302,   311,   320,   310,     0,
       0,     0,   315,   298,   307,   306,   309,   305,     0,   308,
     300,   250,     0,   152,   371,   374,   372,     0,     0,   373,
     353,   354,   365,   370,   170,   168,     0,     0,     0,     0,
     303,   304,   174,     0,     0,     0,   210,     0,   148,     0,
     368,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   363,   364,   313,   312,   319,   318,   299,   317,   316,
     301,   369,   356,   355,   358,   359,   362,   360,   357,     0,
       0,     0,   361,     0,   375,     0,   366,   367,     0,   376
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   579,   718,   138,   144,   160,   161,   162,
     163,   364,   365,   307,   164,   309,   446,   682,   165,   311,
     447,   683,   326,   355,   396,   397,   356,   357,   358,   145,
     146,   147,   153,   302,   304,   324,   439,   681,   354,   305,
     314,   603,   604,   605,   606,   607,   633,   676,   804,   168,
     316,   317,   333,   368,   319,   347,   348,   349,   411,   454,
     455,   616,   763,   692,   688,   689,   645,   958,   959,   960,
    1065,   964,  1004,   837,   933,   934,  1030,  1024,  1025,   351,
     383,   384,   385,   585,   844,   648,   632,   623,   697,   662,
     698,   699,   740,   677,   678,   679,   719,   680,   805,   758,
    1081,  1088,  1082,  1090,  1083,   809,   828,   879,   949,   829,
     830,   953,   818,   819,   950,   820,   874,  1070,  1071,  1100,
    1101,  1102,  1103,  1155,   386,   413,   414,   580,   581,   582,
     583,   388,   663,   664,   944,   665,   666,   667,   668,   669,
     670,   421,   430,   422,   431,   627,   628,   389,   671,   673,
     727,   728,   729,   730,   721,   722,   723,   942,   139,   299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -957
static const yytype_int16 yypact[] =
{
      32,  1970,    73,     2,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,    87,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,   119,  -957,  -957,  -957,   127,   129,  -957,
    -957,   162,  -957,   347,   154,  -957,   100,  -957,   171,  4204,
    4204,   176,  -957,   197,  4204,  4204,  -957,  4204,  -957,  4204,
    -957,  -957,  -957,  -957,  -957,  -957,   206,  4204,   218,  -957,
     200,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,   220,   197,   248,  -957,  -957,  -957,   240,   240,  4204,
     240,  4204,   240,  -957,  -957,   260,  2484,  -957,   394,   296,
    -957,  -957,  -957,   314,   147,  -957,   347,   347,   240,   347,
     240,   190,  3000,  -957,  4204,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,    19,  4204,  -957,
    4376,  -957,   316,  -957,   325,   105,   338,   347,  -957,   339,
     341,   349,   352,  4204,   -11,  -957,   348,    47,  -957,  -957,
    -957,  -957,  -957,  -957,   372,   329,   343,   340,   180,   120,
     232,   232,  -957,  3172,  -957,   345,  -957,   255,  -957,  -957,
    -957,  -957,   363,   365,   368,  -957,  -957,   -17,  -957,  -957,
    -957,  -957,  -957,  -957,   240,  -957,  -957,  4204,  4204,  4204,
    4204,   371,  1626,   372,  -957,  -957,  -957,   388,  -957,  -957,
    -957,    30,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
     278,  -957,  4204,  -957,  -957,  -957,  -957,  -957,  4204,  1454,
     373,   367,   374,  -957,   105,  -957,  1454,  1454,   347,  -957,
    -957,   385,  -957,  -957,   151,  -957,   386,   387,   400,   402,
     403,   404,   406,   408,   409,   410,   411,   414,   416,   417,
     418,   419,   420,   423,   426,   429,   430,   431,   436,   437,
     441,   444,   445,   446,   452,   462,   463,   465,   466,   468,
     469,   472,   476,   478,   480,   490,   491,   492,   493,   494,
     495,   497,   498,   500,   501,   503,   504,   514,   515,   516,
     517,   538,   546,   547,   551,   552,   554,   555,   556,   557,
     558,   559,   560,   561,   566,   567,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   580,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   595,   596,   597,
     598,   599,   603,   605,   606,   607,   608,   609,   610,   611,
     613,   615,   616,   617,   618,   623,   624,   638,   639,   641,
     644,   645,   661,   662,   663,   664,   665,   666,   667,  -957,
      23,  -957,   668,  -957,  -957,  4204,   366,  1626,  -957,  1626,
    -957,   393,   669,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,   904,  -957,  -957,   692,  -957,  -957,  -957,
    -957,  -957,  1093,  1282,   425,  4204,  2656,   371,  -957,   656,
    1626,  2140,   684,   660,   683,   674,  -957,   221,  -957,   221,
    -957,  -957,  -957,   164,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,   675,  4204,   -45,   676,   693,  -957,  -957,   710,  -957,
    -957,   691,  4548,   670,  2140,  -957,   -33,  -957,  4204,  2828,
    1798,   251,  1626,  -957,  -957,  -957,  -957,  -957,  -957,   251,
    -957,  -957,   251,  1798,  -957,  -957,    24,  4204,   164,  -957,
    -957,   206,   694,   696,  3344,   685,   182,   686,  -957,   600,
    4204,   698,  -957,  1626,   697,   690,   699,   142,   671,  -957,
     627,  -957,  -957,   687,    -3,   695,  3516,  -957,  -957,  -957,
    -957,  -957,  1798,  1798,  1798,  1798,  -957,   594,   681,  -957,
      22,  -957,   688,  -957,    28,  -957,  -957,   689,   679,  -957,
     247,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
     682,  4204,  -957,  -957,  -957,  -957,  -957,  -957,   700,   700,
     362,   413,  4204,  -957,  -957,  -957,  -957,  -957,  -957,   682,
     702,  -957,    14,   701,    31,  -957,  3688,  3860,   634,  4548,
    4548,   703,  -957,  -957,   704,  1798,  -957,  -957,   212,   247,
     247,   247,  4204,  1798,  1798,  1798,  1798,  1798,  1798,  1798,
    1798,  1798,  1798,  1798,   -28,  1798,   705,  -957,  -957,   251,
    1798,  -957,  -957,  1798,   164,   164,  -957,  -957,   716,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,   706,  -957,   640,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,   706,  -957,   643,
     707,   708,  -957,  -957,  -957,   719,   470,  -957,  -957,  -957,
    -957,  -957,  -957,   614,   669,  -957,  -957,   726,  -957,   247,
    -957,  -957,   351,   351,   247,   247,   247,   247,   247,   247,
     247,   247,   247,  1798,   709,   272,  2312,   601,   711,  -957,
    -957,  -957,   167,   732,  -957,   362,  -957,   413,   733,  -957,
    4204,   736,   740,  4204,  4032,  -957,  -957,   721,   723,   724,
     712,   713,  -957,  -957,   725,   727,  -957,  -957,  -957,   728,
     729,  -957,  -957,  -957,   216,   730,  -957,   731,   734,  -957,
    -957,   735,   737,  -957,  -957,   738,   741,  -957,  -957,  -957,
     742,   743,  -957,  -957,  -957,  -957,  -957,   744,   746,   747,
     748,   749,   750,   720,  -957,  -957,  -957,   739,   247,  2312,
    1798,  -957,   172,   251,  -957,  -957,  -957,   752,  -957,   751,
    -957,  -957,  -957,  -957,   753,  -957,  -957,   754,   153,  -957,
     755,  -957,  4204,   757,  -957,   612,   756,    36,  4204,  4204,
     758,   759,   760,   761,  -957,  -957,   762,   763,   765,  4204,
     766,   768,   157,   769,   772,   764,   787,   788,    36,    18,
      34,   470,   789,   179,   247,  -957,  2312,  -957,   770,  -957,
    -957,   792,  -957,  4720,  4032,  4204,   784,  4204,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,    29,  -957,  -957,  -957,  -957,  -957,
    -957,   785,   786,  -957,   291,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,   405,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,   774,  -957,  -957,  -957,
    -957,   782,  -957,  -957,   790,  -957,  4204,  -957,    -1,  -957,
    -957,  -957,  4204,  4204,  -957,  -957,   -16,  -957,   -14,   799,
     802,   224,    11,  -957,  -957,  -957,  -957,  -957,   252,  -957,
    -957,  -957,  4204,  -957,  -957,  -957,  -957,    -1,    -1,  -957,
    -957,   229,   227,  -957,  -957,  -957,   803,   804,   791,   793,
    -957,  -957,  -957,   291,   117,   117,  -957,   405,  -957,   780,
    -957,    -1,    -1,    41,    41,    41,    41,    41,   771,    41,
     794,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,  -957,    41,
     648,    41,  -957,    41,  -957,   254,  -957,  -957,    41,  -957
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -957,  -957,  -957,   776,  -149,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,   471,  -135,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -957,  -211,  -957,  -370,  -957,  -293,  -957,  -134,  -957,
    -957,   714,  -957,  -957,   534,  -957,  -957,  -957,  -957,  -957,
    -314,   -87,  -957,  -435,  -957,  -957,  -957,  -957,  -957,  -957,
    -957,  -277,  -957,  -957,  -957,  -957,  -957,   499,  -957,  -957,
    -442,  -957,  -957,  -957,  -569,  -957,  -957,  -957,  -165,  -957,
    -957,  -164,  -957,  -957,  -957,  -150,  -146,  -957,  -180,  -957,
    -957,   467,  -957,  -957,  -957,  -957,     4,  -957,  -957,   152,
      81,    83,  -957,    48,  -957,   181,  -345,    53,  -957,  -957,
    -957,  -957,  -956,  -256,  -251,   114,  -957,  -957,  -957,  -957,
     -13,  -957,  -957,  -957,  -957,   -10,    39,  -957,  -957,  -957,
    -882,  -637,  -957,  -957,  -957,  -957,   454,   175,   249,  -346,
    -533,  -957,  -658,  -957,  -957,  -957,  -957,  -957,  -957,  -578,
    -957,  -957,  -957,   449,   442,   282,   211,  -957,   -18,  -957,
      74,  -957,    72,  -653,  -957,  -957,  -849,   -63,  -957,  -957
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -729
static const yytype_int16 yytable[] =
{
     298,   300,   335,   373,   387,   306,   306,   720,   306,   166,
     306,   726,   618,   702,   726,   686,   405,   941,   315,   -70,
     308,  1106,   310,  1108,   312,   141,   142,   445,  1094,  1095,
     783,   784,   619,   370,   359,   443,   361,   387,   -70,   336,
     838,   444,   834,   773,   863,  1096,   313,  1051,  1114,   703,
    1097,   672,   731,     1,   626,   801,   626,   369,  1008,   778,
     779,   780,   781,  1053,  1052,  1027,   726,   785,   732,   435,
    1094,  1095,   835,   140,   611,   786,   787,   788,   789,   774,
    1054,   620,  1028,   724,   408,   409,   410,  1096,   650,   620,
     941,  1089,   592,  1107,   790,  1109,   392,   327,   687,   329,
     864,   331,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,   360,   656,   362,
    1115,   701,   849,   141,   142,  1098,   704,   148,  1099,   626,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   861,
     862,   867,   865,   791,   792,   793,  1075,  1058,   794,   795,
     796,  1029,   797,   798,  1068,   614,   393,   149,  1138,  1139,
     306,  1089,   306,   363,   394,   150,   395,   315,   635,   151,
    1099,   806,  1079,  1080,   328,   646,   330,   635,   635,   418,
     419,   420,   587,   367,   143,   315,   432,   799,   657,   658,
     832,   659,   660,   448,   768,   661,   453,   167,   617,   372,
     655,   382,  1002,   337,   338,   339,   340,   341,   152,   342,
     938,  1003,   170,   423,   306,  1119,  1120,   301,   392,   946,
     783,   784,   303,   399,   995,   947,   343,   344,   404,   345,
     996,  1057,   346,   313,   382,  1123,  1124,   996,   318,  1142,
    1143,   625,   320,   625,   742,   743,   744,   745,   746,   747,
     748,   749,   750,   751,   752,   783,   784,   785,   449,   450,
     451,   452,   321,   382,   850,   786,   787,   788,   789,   424,
     425,   426,  1125,   427,   428,   429,  1112,   323,   393,   655,
     783,   784,  1113,   591,   790,   997,   394,   994,   395,   382,
     602,   325,   785,   753,   754,   755,   756,   602,   602,  1126,
     786,   787,   788,   789,  1116,   332,  1157,  1074,   674,   675,
    1117,   656,  1158,   705,   708,   350,   625,   785,   353,   790,
    1075,  1076,   757,   974,   975,   786,   787,   788,   789,   418,
     419,   420,  1077,   791,   792,   793,   352,  1078,   794,   795,
     796,   656,   797,   798,   790,   390,  1079,  1080,  1127,  1043,
    1044,  1121,  1122,  1128,  1129,  1130,   391,  1131,  1132,   612,
     613,   777,   433,   434,   363,   398,   400,   735,   791,   792,
     793,   423,   401,   794,   795,   796,   402,   797,   798,   432,
     412,   657,   658,   403,   659,   660,   415,   407,   661,   416,
     432,   417,   437,   791,   792,   940,   785,   609,   794,   795,
     796,   438,   797,   798,   786,   787,   788,   789,   440,   432,
     441,   657,   658,   442,   659,   660,   453,   586,   661,   608,
     610,  1084,   615,   790,   624,  -681,  -682,   424,   425,   426,
     589,   427,   428,   429,  1075,  1085,   622,   851,   382,  -603,
     382,  -604,  -605,  -608,   630,    -9,  1086,  -609,  -611,  -612,
    -614,  1087,   639,  -615,   602,  -616,  -617,  -618,  -619,  -620,
    1079,  1080,  -621,   602,   602,  -622,   640,   644,  -623,  -624,
    -625,   382,   791,   792,   793,  -626,  -627,   794,   795,   796,
    -628,   797,   798,  -629,  -630,  -631,  1144,  1145,  1146,  1147,
    1148,  -632,  1150,   685,   811,   812,   813,   814,   815,   816,
     817,  -633,  -634,   696,  -635,  -636,   882,  -637,  -638,   372,
     372,  -639,  1152,   382,  1154,  -640,  1156,  -641,   883,  -642,
     884,  1159,   154,   155,   156,   157,   158,   159,   733,  -643,
    -644,  -645,  -646,  -647,  -648,   739,  -649,  -650,   961,  -651,
    -652,   761,  -653,  -654,   382,   821,   822,   823,   824,   825,
     826,   827,   885,  -655,  -656,  -657,  -658,   372,   886,   887,
     888,   889,   890,   891,   892,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,  -659,   337,   338,
     339,   340,   341,   905,   342,  -660,  -661,   906,   907,   908,
    -662,  -663,   807,  -664,  -665,  -666,  -667,  -668,  -669,  -670,
    -671,   343,   344,   831,   345,  -672,  -673,   346,  -674,  -675,
    -676,  -677,  -679,  -680,  -683,  -684,  -685,   840,   842,  -686,
     696,   696,  -687,  -688,  -689,  -690,  -691,  -692,  -693,  -694,
    -695,  -696,  -697,   372,  -698,  -699,  -700,  -701,  -702,   909,
     910,  1008,  -703,   911,  -704,  -705,  -706,  -707,  -708,  -709,
    -710,   912,  -711,   913,  -712,  -713,  -714,  -715,   961,   914,
     915,   916,  -716,  -717,   917,   918,   919,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,  -718,  -719,   930,
    -720,   931,   932,  -721,  -722,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,
    -723,  -724,  -725,  -726,  -727,  -728,  -678,   621,   636,   647,
     651,   652,   653,   654,   684,   690,   631,   372,   693,   691,
     694,   736,   700,   737,   741,   765,   760,   762,   759,   766,
     770,   955,  -465,   772,   372,   963,   771,   803,   767,   800,
     775,   802,   686,   833,   843,   872,   782,   880,   881,   875,
     848,   808,   877,   935,   847,   937,   866,   873,   878,   836,
     939,   948,   954,   945,   956,   957,   965,   943,   966,   967,
     970,  1153,   971,   972,   973,   976,   977,   137,   991,   978,
     979,   998,   980,   981,   968,   969,   982,   983,   984,   985,
     372,   986,   987,   988,   989,   990,  1007,   992,  1045,  1001,
    1005,  1046,  1026,   999,  1033,  1000,  1035,  1036,  1037,  1038,
    1034,  1039,  1041,  1006,  1042,  1047,  1048,  1049,  1056,  1031,
    1032,  1060,  1059,  1066,  1072,  1073,  1091,  -617,  1110,  1092,
    1040,  1111,  1141,  1133,  1134,   406,   322,  1135,  1062,  1136,
    1063,  1055,  1050,  1149,  1069,  1151,   371,   372,   936,   769,
     436,   846,   845,   871,   372,   963,  1064,   870,  1067,   734,
     169,  1140,  1137,   810,   952,   951,   876,   584,   764,   649,
     588,   629,   590,   725,   868,   869,   993,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,  1093,     0,     0,
     593,   594,   173,  1104,  1105,   174,   175,   176,   177,   178,
     595,     0,     0,     0,   179,     0,   634,   180,   181,   182,
     183,     0,     0,  1118,   184,     0,   185,   186,   596,     0,
     597,     0,   187,   188,     0,     0,     0,     0,     0,     0,
       0,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     598,   247,   248,   249,   599,   250,   251,   252,     0,   253,
     254,   255,   256,     0,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,     0,   269,   600,   601,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,     0,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,     0,     0,     0,     0,     0,   296,   593,
     594,   173,     0,   297,   174,   175,   176,   177,   178,   595,
       0,     0,     0,   179,     0,   637,   180,   181,   182,   183,
       0,     0,     0,   184,     0,   185,   186,   596,     0,   597,
       0,   187,   188,     0,     0,     0,     0,     0,     0,     0,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   598,
     247,   248,   249,   599,   250,   251,   252,     0,   253,   254,
     255,   256,     0,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,     0,   269,   600,   601,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,     0,   286,   287,   288,   289,
     290,   291,   292,   293,   294,     0,   295,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,   172,     0,     0,     0,     0,     0,   296,   593,   594,
     173,     0,   297,   174,   175,   176,   177,   178,   595,     0,
       0,     0,   179,     0,   638,   180,   181,   182,   183,     0,
       0,     0,   184,     0,   185,   186,   596,     0,   597,     0,
     187,   188,     0,     0,     0,     0,     0,     0,     0,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   598,   247,
     248,   249,   599,   250,   251,   252,     0,   253,   254,   255,
     256,     0,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,     0,   269,   600,   601,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,     0,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,   295,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
     593,   594,   173,     0,     0,   174,   175,   176,   177,   178,
     595,     0,     0,     0,   179,     0,   296,   180,   181,   182,
     183,   297,     0,     0,   184,     0,   185,   186,   596,     0,
     597,     0,   187,   188,     0,     0,     0,     0,     0,     0,
       0,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     598,   247,   248,   249,   599,   250,   251,   252,     0,   253,
     254,   255,   256,     0,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,     0,   269,   600,   601,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,     0,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,   295,     0,     0,
       0,     0,     0,     0,   456,   457,     0,     0,     0,     0,
       0,     0,     0,     0,   458,     7,     8,   459,   460,   176,
     177,   461,     0,    12,     0,     0,   462,     0,   296,   463,
     181,   464,   465,   297,     0,     0,   184,    18,   466,   467,
       0,     0,     0,     0,   468,   469,     0,     0,     0,     0,
       0,     0,     0,   470,     0,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,    81,   528,   529,   530,     0,   531,   532,   533,
       0,   534,   535,   536,   537,    92,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   105,   550,
       0,     0,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   123,   567,
     568,   569,   570,   571,   572,   573,   574,   575,     0,   576,
       0,     0,     0,     0,     0,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,     0,   174,
     175,   176,   177,   178,     0,     0,     0,   709,   179,     0,
     577,   180,   181,   182,   183,   578,     0,     0,   184,   710,
     185,   186,     0,     0,   711,     0,   187,   188,     0,   712,
       0,     0,     0,   713,   714,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,   247,   248,   249,     0,   250,
     251,   252,     0,   253,   715,   255,   256,   716,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
       0,   269,     0,     0,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
       0,   286,   287,   288,   289,   290,   717,   292,   293,   294,
       0,   295,     0,     0,     0,     0,     0,     0,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,     0,     0,    11,     0,    12,     0,     0,
      13,     0,   296,    14,    15,    16,    17,   297,     0,     0,
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
     131,   132,   133,   134,     0,     0,     0,     0,     4,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,     0,     0,    11,     0,    12,     0,     0,
      13,     0,     0,    14,   135,    16,    17,     0,     0,   136,
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
     131,   132,     0,   134,     0,     0,     0,     0,     0,     0,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,   174,   175,   176,   177,   178,     0,     0,
       0,   709,   179,     0,   135,   180,   181,   182,   183,   136,
       0,     0,   184,   710,   185,   186,     0,     0,   711,     0,
     187,   188,     0,     0,     0,     0,     0,     0,     0,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,   247,
     248,   249,     0,   250,   251,   252,     0,   253,   254,   255,
     256,   716,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,     0,   269,     0,     0,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,     0,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,   295,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,   174,   175,   176,   177,   178,
       0,   313,     0,     0,   179,     0,   296,   180,   181,   182,
     183,   297,     0,     0,   184,     0,   185,   186,     0,     0,
       0,     0,   187,   188,     0,     0,     0,     0,     0,     0,
       0,   189,   334,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,   247,   248,   249,     0,   250,   251,   252,     0,   253,
     254,   255,   256,     0,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,     0,   269,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,     0,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,   295,     0,     0,
       0,     0,     0,     0,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,   173,     0,     0,   174,   175,   176,
     177,   178,     0,     0,     0,     0,   179,     0,   296,   180,
     641,   182,   183,   297,     0,     0,   184,     0,   185,   186,
       0,     0,     0,     0,   187,   188,     0,     0,     0,   642,
       0,     0,     0,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,   248,   249,     0,   250,   251,   252,
       0,   253,   254,   255,   256,     0,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   643,   269,
       0,     0,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,     0,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,   295,
       0,     0,     0,     0,     0,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,     0,   174,
     175,   176,   177,   178,     0,     0,     0,     0,   179,     0,
     296,   180,   181,   182,   183,   297,     0,     0,   184,     0,
     185,   186,     0,   706,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,   247,   248,   249,     0,   250,
     251,   252,     0,   253,   254,   255,   256,     0,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
       0,   269,     0,     0,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     707,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,   295,     0,     0,     0,     0,     0,     0,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,   174,   175,   176,   177,   178,     0,     0,     0,     0,
     179,     0,   296,   180,   181,   182,   183,   297,     0,     0,
     184,     0,   185,   186,     0,     0,   366,     0,   187,   188,
       0,     0,     0,     0,     0,     0,     0,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,   247,   248,   249,
       0,   250,   251,   252,     0,   253,   254,   255,   256,     0,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,     0,   269,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,     0,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,   295,     0,     0,     0,     0,     0,     0,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
     374,     0,     0,   174,   175,   176,   375,   178,     0,   313,
       0,     0,   179,     0,   296,   180,   181,   182,   183,   297,
       0,     0,   184,     0,   185,   186,     0,     0,     0,     0,
     187,   188,     0,     0,     0,     0,     0,     0,     0,   189,
       0,   190,   191,   376,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,   247,
     248,   249,     0,   250,   251,   252,     0,   253,   254,   255,
     256,     0,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   377,     0,   269,     0,     0,   270,   378,
     379,   273,   274,   275,   276,   277,   278,   279,   380,   381,
     282,   283,   284,   285,     0,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,   295,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,   174,   175,   176,   177,   178,
       0,   738,     0,     0,   179,     0,   296,   180,   181,   182,
     183,   297,     0,     0,   184,     0,   185,   186,     0,     0,
       0,     0,   187,   188,     0,     0,     0,     0,     0,     0,
       0,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,   247,   248,   249,     0,   250,   251,   252,     0,   253,
     254,   255,   256,     0,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,     0,   269,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,     0,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,   295,     0,     0,
       0,     0,     0,     0,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,   173,     0,     0,   174,   175,   176,
     177,   178,     0,     0,     0,     0,   179,     0,   296,   180,
     181,   182,   183,   297,     0,     0,   184,     0,   185,   186,
       0,     0,     0,     0,   187,   188,     0,     0,     0,     0,
       0,     0,     0,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,   248,   249,     0,   250,   251,   252,
       0,   253,   254,   255,   256,     0,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,     0,   269,
       0,     0,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   776,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,   295,
       0,     0,     0,     0,     0,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,     0,   174,
     175,   176,   177,   178,     0,     0,     0,     0,   179,     0,
     296,   180,   181,   182,   183,   297,     0,     0,   184,     0,
     185,   186,     0,     0,     0,     0,   187,   188,     0,     0,
       0,   839,     0,     0,     0,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,   247,   248,   249,     0,   250,
     251,   252,     0,   253,   254,   255,   256,     0,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
       0,   269,     0,     0,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
       0,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,   295,     0,     0,     0,     0,     0,     0,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,   174,   175,   176,   177,   178,     0,     0,     0,     0,
     179,     0,   296,   180,   181,   182,   183,   297,     0,     0,
     184,     0,   185,   186,     0,     0,     0,     0,   187,   188,
       0,     0,     0,   841,     0,     0,     0,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,   247,   248,   249,
       0,   250,   251,   252,     0,   253,   254,   255,   256,     0,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,     0,   269,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,     0,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,   295,     0,     0,     0,     0,     0,     0,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     0,     0,   174,   175,   176,   177,   178,     0,     0,
       0,     0,   179,     0,   296,   180,   181,   182,   183,   297,
       0,     0,   184,     0,   185,   186,     0,     0,     0,     0,
     187,   188,     0,     0,     0,   962,     0,     0,     0,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,   247,
     248,   249,     0,   250,   251,   252,     0,   253,   254,   255,
     256,     0,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,     0,   269,     0,     0,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,     0,   286,   287,   288,   289,   290,
     291,   292,   293,   294,     0,   295,     0,     0,     0,     0,
       0,     0,   171,   172,     0,     0,     0,     0,     0,     0,
       0,     0,   173,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,     0,   179,     0,   296,   180,   181,   182,
     183,   297,     0,     0,   184,     0,   185,   186,     0,     0,
       0,     0,   187,   188,     0,     0,     0,     0,     0,     0,
       0,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,   247,   248,   249,     0,   250,   251,   252,     0,   253,
     254,   255,   256,     0,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,     0,   269,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,     0,   286,   287,   288,
     289,   290,   291,   292,   293,   294,     0,   295,     0,     0,
       0,     0,     0,     0,   171,   172,     0,     0,     0,     0,
       0,     0,     0,     0,   374,     0,     0,   174,   175,   176,
     375,   178,     0,     0,     0,     0,   179,     0,   296,   180,
     181,   182,   183,   297,     0,     0,   184,     0,   185,   186,
       0,     0,     0,     0,   187,   188,     0,     0,     0,     0,
       0,     0,     0,   189,     0,   190,   191,   376,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,   247,   248,   249,     0,   250,   251,   252,
       0,   253,   254,   255,   256,     0,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   377,     0,   269,
       0,     0,   270,   378,   379,   273,   274,   275,   276,   277,
     278,   279,   380,   381,   282,   283,   284,   285,     0,   286,
     287,   288,   289,   290,   291,   292,   293,   294,     0,   295,
       0,     0,     0,     0,     0,     0,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,     0,   174,
     175,   176,   177,   178,     0,     0,     0,     0,   179,     0,
     296,   180,   695,   182,   183,   297,     0,     0,   184,     0,
     185,   186,     0,     0,     0,     0,   187,   188,     0,     0,
       0,     0,     0,     0,     0,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,   247,   248,   249,     0,   250,
     251,   252,     0,   253,   254,   255,   256,     0,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
       0,   269,     0,     0,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
       0,   286,   287,   288,   289,   290,   291,   292,   293,   294,
       0,   295,     0,     0,     0,     0,     0,     0,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,   174,   175,   176,   177,   178,     0,     0,     0,     0,
     179,     0,   296,   180,   181,   182,   183,   297,     0,     0,
     184,     0,   185,   186,     0,     0,     0,     0,   187,  1061,
       0,     0,     0,     0,     0,     0,     0,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,   247,   248,   249,
       0,   250,   251,   252,     0,   253,   254,   255,   256,     0,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,     0,   269,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,     0,   286,   287,   288,   289,   290,   291,   292,
     293,   294,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   296,     0,     0,     0,     0,   297
};

static const yytype_int16 yycheck[] =
{
     149,   150,   316,   348,   350,   154,   155,   660,   157,   143,
     159,   669,   454,    46,   672,    60,    27,   866,   167,     0,
     155,    37,   157,    37,   159,    23,    24,   397,    29,    30,
       8,     9,     9,   347,   327,    52,   329,   383,    19,   316,
       9,    58,    28,    46,    72,    46,    27,    29,    37,    82,
      51,   629,    28,    21,   587,    27,   589,   334,    29,   712,
     713,   714,   715,    29,    46,    29,   724,    45,    44,   383,
      29,    30,    58,     0,   444,    53,    54,    55,    56,    82,
      46,    58,    46,   661,    37,    38,    39,    46,   621,    58,
     939,  1047,   438,   109,    72,   109,   113,   308,   143,   310,
     128,   312,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   328,    90,   330,
     109,   654,   775,    23,    24,   126,   159,    40,   129,   662,
     783,   784,   785,   786,   787,   788,   789,   790,   791,   792,
     793,   799,   795,   121,   122,   123,    29,   996,   126,   127,
     128,   115,   130,   131,   125,   448,   173,    38,  1114,  1115,
     309,  1117,   311,   174,   181,    38,   183,   316,   603,    40,
     129,   740,    55,    56,   309,   617,   311,   612,   613,   149,
     150,   151,   152,   332,   182,   334,   158,   165,   160,   161,
     759,   163,   164,   404,    52,   167,    45,    43,    47,   348,
      58,   350,    49,   184,   185,   186,   187,   188,    46,   190,
     863,    58,    41,    93,   363,  1097,  1098,    41,   113,    52,
       8,     9,    25,   357,    52,    58,   207,   208,   363,   210,
      58,    52,   213,    27,   383,     8,     9,    58,    20,  1121,
    1122,   587,    42,   589,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     8,     9,    45,   407,   408,
     409,   410,    42,   412,    52,    53,    54,    55,    56,   149,
     150,   151,    45,   153,   154,   155,    52,    29,   173,    58,
       8,     9,    58,   432,    72,   943,   181,   940,   183,   438,
     439,    51,    45,   111,   112,   113,   114,   446,   447,    72,
      53,    54,    55,    56,    52,    45,    52,    16,   144,   145,
      58,    90,    58,   658,   659,    19,   662,    45,   171,    72,
      29,    30,   140,   107,   108,    53,    54,    55,    56,   149,
     150,   151,    41,   121,   122,   123,    22,    46,   126,   127,
     128,    90,   130,   131,    72,    29,    55,    56,   121,   192,
     193,   122,   123,   126,   127,   128,    31,   130,   131,   446,
     447,   706,   380,   381,   174,    27,    27,   681,   121,   122,
     123,    93,    31,   126,   127,   128,    27,   130,   131,   158,
       8,   160,   161,    31,   163,   164,    57,    39,   167,    46,
     158,    51,    47,   121,   122,   123,    45,    30,   126,   127,
     128,   146,   130,   131,    53,    54,    55,    56,    45,   158,
      45,   160,   161,    45,   163,   164,    45,    29,   167,    46,
      46,    16,    37,    72,    58,    39,    39,   149,   150,   151,
     152,   153,   154,   155,    29,    30,   585,   782,   587,    39,
     589,    39,    39,    39,    51,    39,    41,    39,    39,    39,
      39,    46,    27,    39,   603,    39,    39,    39,    39,    39,
      55,    56,    39,   612,   613,    39,   615,   616,    39,    39,
      39,   620,   121,   122,   123,    39,    39,   126,   127,   128,
      39,   130,   131,    39,    39,    39,  1123,  1124,  1125,  1126,
    1127,    39,  1129,   642,   132,   133,   134,   135,   136,   137,
     138,    39,    39,   652,    39,    39,    36,    39,    39,   658,
     659,    39,  1149,   662,  1151,    39,  1153,    39,    48,    39,
      50,  1158,   175,   176,   177,   178,   179,   180,   677,    39,
      39,    39,    39,    39,    39,   684,    39,    39,   883,    39,
      39,   690,    39,    39,   693,   132,   133,   134,   135,   136,
     137,   138,    82,    39,    39,    39,    39,   706,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    39,   184,   185,
     186,   187,   188,   113,   190,    39,    39,   117,   118,   119,
      39,    39,   741,    39,    39,    39,    39,    39,    39,    39,
      39,   207,   208,   752,   210,    39,    39,   213,    39,    39,
      39,    39,    39,    39,    39,    39,    39,   766,   767,    39,
     769,   770,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,   782,    39,    39,    39,    39,    39,   169,
     170,    29,    39,   173,    39,    39,    39,    39,    39,    39,
      39,   181,    39,   183,    39,    39,    39,    39,  1003,   189,
     190,   191,    39,    39,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    39,    39,   209,
      39,   211,   212,    39,    39,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      39,    39,    39,    39,    39,    39,    39,    39,    16,    53,
      26,    51,    29,    39,    39,    39,    47,   866,     8,    26,
      29,    27,    52,    27,    39,    28,   126,    29,    42,    39,
      59,   880,    51,    46,   883,   884,   109,    58,    39,    51,
      45,    52,    60,    41,   110,    29,   152,    39,    29,   109,
      46,    51,   109,   139,    51,    29,    51,    51,    51,    58,
      51,    29,    29,    52,    28,    25,    45,   166,    45,    45,
      45,   123,    45,    45,    45,    45,    45,     1,    58,    45,
      45,    29,    45,    45,    72,    72,    45,    45,    45,    45,
     939,    45,    45,    45,    45,    45,    39,    58,    29,    45,
      45,    29,    46,    52,    46,    52,    46,    46,    46,    46,
      51,    46,    46,   962,    46,    51,    29,    29,    29,   968,
     969,    29,    52,    39,    39,    39,    52,    45,    29,    39,
     979,    29,    52,    30,    30,   364,   302,    46,  1003,    46,
    1004,   991,   988,    72,  1024,    51,   347,   996,   844,   697,
     383,   770,   769,   805,  1003,  1004,  1005,   804,  1007,   678,
     146,  1117,  1113,   749,   877,   875,   827,   413,   693,   620,
     421,   589,   430,   662,   800,   803,   939,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,  1066,    -1,    -1,
      16,    17,    18,  1072,  1073,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,
      36,    -1,    -1,  1092,    40,    -1,    42,    43,    44,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,   204,    16,
      17,    18,    -1,   209,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    -1,    42,    43,    44,    -1,    46,
      -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    -1,   125,   126,
     127,   128,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,   204,    16,    17,
      18,    -1,   209,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    44,    -1,    46,    -1,
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
     168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,   204,    33,    34,    35,
      36,   209,    -1,    -1,    40,    -1,    42,    43,    44,    -1,
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
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,   204,    33,
      34,    35,    36,   209,    -1,    -1,    40,    41,    42,    43,
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
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    30,    -1,
     204,    33,    34,    35,    36,   209,    -1,    -1,    40,    41,
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
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,   204,    33,    34,    35,    36,   209,    -1,    -1,
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
     170,   171,   172,   173,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    -1,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,   204,    35,    36,    -1,    -1,   209,
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
     170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    30,    -1,   204,    33,    34,    35,    36,   209,
      -1,    -1,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,   204,    33,    34,    35,
      36,   209,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,
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
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,   204,    33,
      34,    35,    36,   209,    -1,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
     204,    33,    34,    35,    36,   209,    -1,    -1,    40,    -1,
      42,    43,    -1,    45,    -1,    -1,    48,    49,    -1,    -1,
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
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,   204,    33,    34,    35,    36,   209,    -1,    -1,
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
     170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,   204,    33,    34,    35,    36,   209,
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
     168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,   204,    33,    34,    35,
      36,   209,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,
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
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,   204,    33,
      34,    35,    36,   209,    -1,    -1,    40,    -1,    42,    43,
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
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
     204,    33,    34,    35,    36,   209,    -1,    -1,    40,    -1,
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
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,   204,    33,    34,    35,    36,   209,    -1,    -1,
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
     170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,   204,    33,    34,    35,    36,   209,
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
     168,   169,   170,   171,    -1,   173,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,   204,    33,    34,    35,
      36,   209,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,
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
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,   204,    33,
      34,    35,    36,   209,    -1,    -1,    40,    -1,    42,    43,
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
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
     204,    33,    34,    35,    36,   209,    -1,    -1,    40,    -1,
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
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,   204,    33,    34,    35,    36,   209,    -1,    -1,
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
     170,   171,    -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,   209
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   215,   216,     8,     9,    18,    19,    20,    21,
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
     169,   170,   171,   172,   173,   204,   209,   217,   219,   372,
       0,    23,    24,   182,   220,   243,   244,   245,    40,    38,
      38,    40,    46,   246,   175,   176,   177,   178,   179,   180,
     221,   222,   223,   224,   228,   232,   242,    43,   263,   245,
      41,     8,     9,    18,    21,    22,    23,    24,    25,    30,
      33,    34,    35,    36,    40,    42,    43,    48,    49,    57,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   117,   118,   119,
     121,   122,   123,   125,   126,   127,   128,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   143,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   173,   204,   209,   218,   373,
     218,    41,   247,    25,   248,   253,   218,   227,   227,   229,
     227,   233,   227,    27,   254,   218,   264,   265,    20,   268,
      42,    42,   248,    29,   249,    51,   236,   236,   227,   236,
     227,   236,    45,   266,    58,   254,   265,   184,   185,   186,
     187,   188,   190,   207,   208,   210,   213,   269,   270,   271,
      19,   293,    22,   171,   252,   237,   240,   241,   242,   240,
     236,   240,   236,   174,   225,   226,    46,   218,   267,   265,
     254,   271,   218,   310,    18,    24,    61,   141,   147,   148,
     156,   157,   218,   294,   295,   296,   338,   343,   345,   361,
      29,    31,   113,   173,   181,   183,   238,   239,    27,   242,
      27,    31,    27,    31,   227,    27,   226,    39,    37,    38,
      39,   272,     8,   339,   340,    57,    46,    51,   149,   150,
     151,   355,   357,    93,   149,   150,   151,   153,   154,   155,
     356,   358,   158,   362,   362,   254,   295,    47,   146,   250,
      45,    45,    45,    52,    58,   238,   230,   234,   236,   218,
     218,   218,   218,    45,   273,   274,     8,     9,    18,    21,
      22,    25,    30,    33,    35,    36,    42,    43,    48,    49,
      57,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   117,   118,
     119,   121,   122,   123,   125,   126,   127,   128,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     143,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   173,   204,   209,   217,
     341,   342,   343,   344,   340,   297,    29,   152,   357,   152,
     358,   218,   343,    16,    17,    26,    44,    46,   116,   120,
     144,   145,   218,   255,   256,   257,   258,   259,    46,    30,
      46,   238,   255,   255,   240,    37,   275,    47,   274,     9,
      58,    39,   218,   301,    58,   343,   344,   359,   360,   359,
      51,    47,   300,   260,    32,   257,    16,    32,    32,    27,
     218,    34,    53,   142,   218,   280,   274,    53,   299,   342,
     344,    26,    51,    29,    39,    58,    90,   160,   161,   163,
     164,   167,   303,   346,   347,   349,   350,   351,   352,   353,
     354,   362,   353,   363,   144,   145,   261,   307,   308,   309,
     311,   251,   231,   235,    39,   218,    60,   143,   278,   279,
      39,    26,   277,     8,    29,    34,   218,   302,   304,   305,
      52,   344,    46,    82,   159,   310,    45,   162,   310,    29,
      41,    46,    51,    55,    56,   126,   129,   168,   218,   310,
     367,   368,   369,   370,   353,   360,   346,   364,   365,   366,
     367,    28,    44,   218,   309,   254,    27,    27,    27,   218,
     306,    39,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   111,   112,   113,   114,   140,   313,    42,
     126,   218,    29,   276,   341,    28,    39,    39,    52,   303,
      59,   109,    46,    46,    82,    45,   162,   310,   367,   367,
     367,   367,   152,     8,     9,    45,    53,    54,    55,    56,
      72,   121,   122,   123,   126,   127,   128,   130,   131,   165,
      51,    27,    52,    58,   262,   312,   278,   218,    51,   319,
     319,   132,   133,   134,   135,   136,   137,   138,   326,   327,
     329,   132,   133,   134,   135,   136,   137,   138,   320,   323,
     324,   218,   278,    41,    28,    58,    58,   287,     9,    53,
     218,    53,   218,   110,   298,   305,   304,    51,    46,   367,
      52,   310,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,    72,   128,   367,    51,   346,   364,   366,
     311,   307,    29,    51,   330,   109,   330,   109,    51,   321,
      39,    29,    36,    48,    50,    82,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   113,   117,   118,   119,   169,
     170,   173,   181,   183,   189,   190,   191,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     209,   211,   212,   288,   289,   139,   300,    29,   367,    51,
     123,   370,   371,   166,   348,    52,    52,    58,    29,   322,
     328,   329,   324,   325,    29,   218,    28,    25,   281,   282,
     283,   310,    53,   218,   285,    45,    45,    45,    72,    72,
      45,    45,    45,    45,   107,   108,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    58,    58,   371,   367,    52,    58,   346,    29,    52,
      52,    45,    49,    58,   286,    45,   218,    39,    29,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   291,   292,    46,    29,    46,   115,
     290,   218,   218,    46,    51,    46,    46,    46,    46,    46,
     218,    46,    46,   192,   193,    29,    29,    51,    29,    29,
     290,    29,    46,    29,    46,   289,    29,    52,   370,    52,
      29,    49,   282,   285,   218,   284,    39,   218,   125,   292,
     331,   332,    39,    39,    16,    29,    30,    41,    46,    55,
      56,   314,   316,   318,    16,    30,    41,    46,   315,   316,
     317,    52,    39,   218,    29,    30,    46,    51,   126,   129,
     333,   334,   335,   336,   218,   218,    37,   109,    37,   109,
      29,    29,    52,    58,    37,   109,    52,    58,   218,   334,
     334,   122,   123,     8,     9,    45,    72,   121,   126,   127,
     128,   130,   131,    30,    30,    46,    46,   318,   316,   316,
     317,    52,   334,   334,   335,   335,   335,   335,   335,    72,
     335,    51,   335,   123,   335,   337,   335,    52,    58,   335
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
#line 144 "screen.yacc"
    {
A4GL_check_compiled_form();
A4GL_write_form();}
    break;

  case 3:
#line 149 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:
#line 150 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 155 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 156 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 11:
#line 175 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:
#line 176 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:
#line 178 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 15:
#line 183 "screen.yacc"
    {
			the_form.layout=NULL;
	}
    break;

  case 16:
#line 186 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 17:
#line 193 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 18:
#line 203 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 19:
#line 212 "screen.yacc"
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
#line 225 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 21:
#line 233 "screen.yacc"
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
#line 243 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 23:
#line 251 "screen.yacc"
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
#line 264 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 26:
#line 270 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 27:
#line 273 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 28:
#line 276 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 29:
#line 277 "screen.yacc"
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
#line 292 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 31:
#line 295 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:
#line 298 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:
#line 299 "screen.yacc"
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
#line 312 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 35:
#line 315 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 36:
#line 315 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 37:
#line 321 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 38:
#line 324 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 39:
#line 327 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 40:
#line 330 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 44:
#line 342 "screen.yacc"
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
#line 351 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 46:
#line 357 "screen.yacc"
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
#line 367 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 48:
#line 375 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 49:
#line 377 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 50:
#line 379 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 51:
#line 381 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:
#line 383 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 53:
#line 385 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 54:
#line 391 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(2) - (3)].layout);
	}
    break;

  case 57:
#line 402 "screen.yacc"
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
#line 415 "screen.yacc"
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
#line 434 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 62:
#line 436 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 63:
#line 439 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 66:
#line 444 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 69:
#line 451 "screen.yacc"
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
#line 473 "screen.yacc"
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
#line 488 "screen.yacc"
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
#line 500 "screen.yacc"
    { ltab=0; }
    break;

  case 77:
#line 501 "screen.yacc"
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
#line 512 "screen.yacc"
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
#line 523 "screen.yacc"
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
#line 536 "screen.yacc"
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
#line 548 "screen.yacc"
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
#line 559 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 83:
#line 564 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 84:
#line 567 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 85:
#line 575 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 86:
#line 576 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:
#line 582 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 88:
#line 589 "screen.yacc"
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
#line 603 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 90:
#line 606 "screen.yacc"
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
#line 617 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 97:
#line 633 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 98:
#line 642 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 99:
#line 643 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 100:
#line 646 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 101:
#line 647 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 102:
#line 649 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 103:
#line 650 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 104:
#line 651 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 109:
#line 667 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 110:
#line 668 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 111:
#line 669 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 112:
#line 670 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 113:
#line 671 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 114:
#line 672 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 115:
#line 673 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 116:
#line 674 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 117:
#line 675 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 118:
#line 676 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 119:
#line 677 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 120:
#line 682 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 121:
#line 688 "screen.yacc"
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

  case 125:
#line 706 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 126:
#line 710 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 127:
#line 718 "screen.yacc"
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

  case 129:
#line 892 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 130:
#line 896 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 131:
#line 904 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 132:
#line 905 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 133:
#line 908 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 134:
#line 909 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 135:
#line 912 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 136:
#line 915 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 137:
#line 920 "screen.yacc"
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

  case 138:
#line 929 "screen.yacc"
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

  case 139:
#line 941 "screen.yacc"
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

  case 140:
#line 953 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 141:
#line 960 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 142:
#line 968 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 143:
#line 975 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 144:
#line 988 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 145:
#line 997 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 146:
#line 1006 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 148:
#line 1015 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 149:
#line 1018 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 150:
#line 1024 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 151:
#line 1025 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 152:
#line 1026 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 153:
#line 1027 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 160:
#line 1043 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 161:
#line 1044 "screen.yacc"
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

  case 162:
#line 1064 "screen.yacc"
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

  case 163:
#line 1086 "screen.yacc"
    {
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 164:
#line 1092 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 165:
#line 1093 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 166:
#line 1094 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 167:
#line 1095 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 168:
#line 1096 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 169:
#line 1097 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 170:
#line 1098 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 171:
#line 1099 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 172:
#line 1100 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 173:
#line 1101 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 174:
#line 1102 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 175:
#line 1103 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 176:
#line 1104 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 177:
#line 1105 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 178:
#line 1106 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 179:
#line 1107 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 180:
#line 1108 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 181:
#line 1109 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 182:
#line 1111 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 183:
#line 1113 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 184:
#line 1114 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 185:
#line 1115 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 186:
#line 1116 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REQUIRED); }
    break;

  case 187:
#line 1117 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REVERSE); }
    break;

  case 188:
#line 1118 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 189:
#line 1119 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_QUERYCLEAR); }
    break;

  case 190:
#line 1120 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_ZEROFILL); }
    break;

  case 191:
#line 1121 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_RIGHT); }
    break;

  case 192:
#line 1122 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WORDWRAP); }
    break;

  case 193:
#line 1123 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 194:
#line 1127 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 195:
#line 1134 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_HIDDEN); }
    break;

  case 196:
#line 1135 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTOSCALE); }
    break;

  case 197:
#line 1136 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WANTNORETURNS); }
    break;

  case 198:
#line 1137 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WANTTABS); }
    break;

  case 199:
#line 1138 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_FONTPITCHFIXED); }
    break;

  case 200:
#line 1139 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_FONTPITCHVARIABLE); }
    break;

  case 201:
#line 1140 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLL); }
    break;

  case 202:
#line 1141 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 203:
#line 1142 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 204:
#line 1143 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 205:
#line 1144 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_BOTH); }
    break;

  case 206:
#line 1145 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 207:
#line 1146 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 208:
#line 1147 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_STRETCH_Y); }
    break;

  case 209:
#line 1148 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_STRETCH_BOTH); }
    break;

  case 210:
#line 1149 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 211:
#line 1150 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 212:
#line 1151 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 213:
#line 1153 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 214:
#line 1154 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 215:
#line 1155 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 216:
#line 1156 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 217:
#line 1157 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 218:
#line 1158 "screen.yacc"
    { A4GL_add_str_attr(fld, FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 219:
#line 1164 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 220:
#line 1165 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 221:
#line 1166 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 223:
#line 1171 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 224:
#line 1175 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 225:
#line 1176 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 226:
#line 1177 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 227:
#line 1178 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 228:
#line 1179 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 229:
#line 1180 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 230:
#line 1181 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 231:
#line 1182 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 232:
#line 1184 "screen.yacc"
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

  case 233:
#line 1198 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 234:
#line 1199 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 235:
#line 1200 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 236:
#line 1201 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 237:
#line 1202 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 238:
#line 1203 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 239:
#line 1204 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 246:
#line 1217 "screen.yacc"
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

  case 247:
#line 1227 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 248:
#line 1233 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 255:
#line 1244 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 256:
#line 1244 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 259:
#line 1249 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 260:
#line 1252 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 261:
#line 1258 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 262:
#line 1261 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 265:
#line 1271 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),""); }
    break;

  case 266:
#line 1273 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); }
    break;

  case 267:
#line 1275 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); }
    break;

  case 268:
#line 1277 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); }
    break;

  case 269:
#line 1279 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 271:
#line 1283 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 272:
#line 1287 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 273:
#line 1290 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 274:
#line 1294 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:
#line 1294 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 278:
#line 1301 "screen.yacc"
    {colno++;}
    break;

  case 279:
#line 1302 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 280:
#line 1315 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 281:
#line 1323 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 282:
#line 1325 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 283:
#line 1332 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 284:
#line 1336 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 285:
#line 1340 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 286:
#line 1344 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 287:
#line 1348 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 288:
#line 1352 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 289:
#line 1356 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 290:
#line 1362 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 291:
#line 1366 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 292:
#line 1370 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 293:
#line 1374 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 294:
#line 1378 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 295:
#line 1382 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 296:
#line 1386 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 297:
#line 1389 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 299:
#line 1396 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 301:
#line 1400 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 304:
#line 1405 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 305:
#line 1409 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 306:
#line 1416 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 307:
#line 1417 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 309:
#line 1419 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 310:
#line 1425 "screen.yacc"
    { 
	if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
		sprintf((yyval.str),"NULL");
	} else {
		strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
	}
}
    break;

  case 311:
#line 1432 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 312:
#line 1433 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 313:
#line 1434 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 314:
#line 1435 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 316:
#line 1437 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 317:
#line 1438 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 318:
#line 1439 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 319:
#line 1443 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 320:
#line 1447 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 321:
#line 1452 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 322:
#line 1455 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 323:
#line 1456 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 324:
#line 1459 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 325:
#line 1461 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 326:
#line 1467 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 327:
#line 1469 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 328:
#line 1474 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 329:
#line 1482 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 330:
#line 1485 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 331:
#line 1486 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 332:
#line 1487 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 333:
#line 1488 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 334:
#line 1489 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 335:
#line 1490 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 336:
#line 1492 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 338:
#line 1499 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 339:
#line 1500 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 340:
#line 1503 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 341:
#line 1506 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 342:
#line 1510 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 343:
#line 1511 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 344:
#line 1512 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 345:
#line 1513 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 346:
#line 1514 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 347:
#line 1515 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 348:
#line 1517 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 349:
#line 1522 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 350:
#line 1524 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 351:
#line 1531 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 352:
#line 1531 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 353:
#line 1537 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 355:
#line 1544 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 356:
#line 1547 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 357:
#line 1553 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 358:
#line 1554 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 359:
#line 1555 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 360:
#line 1556 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 361:
#line 1557 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 362:
#line 1558 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 363:
#line 1559 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 364:
#line 1560 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 365:
#line 1561 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 366:
#line 1562 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 367:
#line 1563 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 368:
#line 1564 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 369:
#line 1565 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 370:
#line 1568 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 371:
#line 1575 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 372:
#line 1576 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 373:
#line 1577 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 375:
#line 1585 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 376:
#line 1589 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 380:
#line 1609 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 381:
#line 1619 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 382:
#line 1626 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 383:
#line 1635 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 384:
#line 1638 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 387:
#line 1657 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 388:
#line 1664 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 389:
#line 1672 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 390:
#line 1677 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 391:
#line 1685 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 392:
#line 1689 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 393:
#line 1694 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 394:
#line 1699 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 395:
#line 1704 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 396:
#line 1709 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 397:
#line 1714 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 398:
#line 1723 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 399:
#line 1732 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 400:
#line 1733 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 402:
#line 1742 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 403:
#line 1750 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 404:
#line 1756 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 405:
#line 1762 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 406:
#line 1768 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 407:
#line 1776 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 408:
#line 1781 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 409:
#line 1791 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 410:
#line 1801 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 411:
#line 1807 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 412:
#line 1813 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 413:
#line 1819 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 414:
#line 1829 "screen.yacc"
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

  case 415:
#line 1841 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 416:
#line 1849 "screen.yacc"
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

  case 417:
#line 1861 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 418:
#line 1869 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 419:
#line 1870 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 420:
#line 1871 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 421:
#line 1875 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 422:
#line 1876 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 423:
#line 1877 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 424:
#line 1878 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 425:
#line 1879 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 426:
#line 1880 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 427:
#line 1881 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 428:
#line 1884 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 429:
#line 1891 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 430:
#line 1902 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 431:
#line 1906 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 432:
#line 1913 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 433:
#line 1921 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 434:
#line 1927 "screen.yacc"
    {
		(yyval.fcall)=(yyvsp[(4) - (6)].fcall);
		if ((yyvsp[(5) - (6)].el)) {
			listitem *l;
			(yyval.fcall)->list_parameters.list_parameters_len=(yyvsp[(5) - (6)].el)->nlist;
			l=(yyvsp[(5) - (6)].el)->expr_list;
			(yyval.fcall)->list_parameters.list_parameters_val=l;
		}
	}
    break;

  case 435:
#line 1939 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 436:
#line 1940 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 437:
#line 1946 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 438:
#line 1952 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 439:
#line 1960 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 441:
#line 1968 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 442:
#line 1969 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 443:
#line 1983 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 444:
#line 1985 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 445:
#line 1986 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 446:
#line 1987 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 447:
#line 1988 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 448:
#line 1989 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 449:
#line 1992 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 450:
#line 1993 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 451:
#line 1994 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 452:
#line 1995 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 453:
#line 1996 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 454:
#line 1997 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 455:
#line 1998 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 456:
#line 1999 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 457:
#line 2000 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 458:
#line 2001 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 459:
#line 2002 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 460:
#line 2003 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 461:
#line 2004 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 462:
#line 2005 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 463:
#line 2006 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 464:
#line 2007 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 466:
#line 2013 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 467:
#line 2014 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 468:
#line 2015 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 469:
#line 2016 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 470:
#line 2017 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 471:
#line 2020 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 472:
#line 2024 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 6710 "y.tab.c"
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


#line 2349 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */



