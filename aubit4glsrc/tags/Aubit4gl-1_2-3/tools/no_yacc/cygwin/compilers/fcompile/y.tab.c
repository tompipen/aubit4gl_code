
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
#define yyparse         a4gl_form_yyparse
#define yylex           a4gl_form_yylex
#define yyerror         a4gl_form_yyerror
#define yylval          a4gl_form_yylval
#define yychar          a4gl_form_yychar
#define yydebug         a4gl_form_yydebug
#define yynerrs         a4gl_form_yynerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "screen.yacc"

#define YYDEBUG 1
#ifdef YYPURE
#undef YYPURE
#endif
#define YYPURE 1
#define YYLEX_PARAM yystate
#define YY_DECL int yylex(int yystate)

int ign_kw(int yystate,int kw);
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



/* Line 189 of yacc.c  */
#line 160 "y.tab.c"

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
     CHARACTER_ENCODING = 302,
     SEMICOLON = 303,
     LOOKUP = 304,
     JOINING = 305,
     LOOKUP_FROM = 306,
     OPEN_BRACKET = 307,
     CLOSE_BRACKET = 308,
     STAR = 309,
     DIVIDE = 310,
     PLUS = 311,
     MINUS = 312,
     RECORD = 313,
     COMMA = 314,
     THROUGH = 315,
     TYPE = 316,
     DELIMITERS = 317,
     KW_CHAR = 318,
     KW_INT = 319,
     KW_DATE = 320,
     KW_FLOAT = 321,
     SMALLFLOAT = 322,
     SMALLINT = 323,
     KW_DECIMAL = 324,
     MONEY = 325,
     DATETIME = 326,
     INTERVAL = 327,
     LIKE = 328,
     BLACK = 329,
     BLUE = 330,
     GREEN = 331,
     CYAN = 332,
     RED = 333,
     MAGENTA = 334,
     WHITE = 335,
     YELLOW = 336,
     NORMAL = 337,
     REVERSE = 338,
     LEFT = 339,
     BOLD = 340,
     BLINK = 341,
     UNDERLINE = 342,
     DIM = 343,
     AUTONEXT = 344,
     COLOR = 345,
     COMMENTS = 346,
     DEFAULT = 347,
     VALIDATE = 348,
     DISPLAY = 349,
     DOWNSHIFT = 350,
     UPSHIFT = 351,
     FORMAT = 352,
     INCLUDE = 353,
     INVISIBLE = 354,
     NOUPDATE = 355,
     NOENTRY = 356,
     PICTURE = 357,
     PROGRAM = 358,
     REQUIRED = 359,
     QUERYCLEAR = 360,
     VERIFY = 361,
     WORDWRAP = 362,
     COMPRESS = 363,
     NONCOMPRESS = 364,
     TO = 365,
     AS = 366,
     UNHIDABLE = 367,
     SERIAL = 368,
     KW_BYTE = 369,
     KW_TEXT = 370,
     VARCHAR = 371,
     SQL_VAR = 372,
     KW_NONSPACE = 373,
     SQLONLY = 374,
     WIDGET = 375,
     CONFIG = 376,
     KW_NL = 377,
     COMPARISON = 378,
     KWOR = 379,
     KWAND = 380,
     KWAND1 = 381,
     KWWHERE = 382,
     KWNOT = 383,
     KWBETWEEN = 384,
     KWIN = 385,
     XVAL = 386,
     KWNULLCHK = 387,
     KWNOTNULLCHK = 388,
     YEAR = 389,
     MONTH = 390,
     DAY = 391,
     HOUR = 392,
     MINUTE = 393,
     SECOND = 394,
     FRACTION = 395,
     KW_JUSTIFY = 396,
     KW_CENTER = 397,
     KW_TABINDEX = 398,
     KW_NOT_NULL = 399,
     LISTBOX = 400,
     BUTTON = 401,
     KW_PANEL = 402,
     DISPLAYONLY = 403,
     ALLOWING = 404,
     KW_WS = 405,
     KW_TAB = 406,
     KW_MASTER_OF = 407,
     KW_BEFORE = 408,
     KW_AFTER = 409,
     KW_EDITADD = 410,
     KW_EDITUPDATE = 411,
     KW_REMOVE = 412,
     KW_OF = 413,
     KW_ADD = 414,
     KW_UPDATE = 415,
     KW_QUERY = 416,
     KW_ON_ENDING = 417,
     KW_ON_BEGINNING = 418,
     KW_CALL = 419,
     KW_BELL = 420,
     KW_ABORT = 421,
     KW_LET = 422,
     KW_EXITNOW = 423,
     KW_NEXTFIELD = 424,
     KW_IF = 425,
     KW_THEN = 426,
     KW_ELSE = 427,
     KW_BEGIN = 428,
     KW_TOTAL = 429,
     KW_RIGHT = 430,
     KW_ZEROFILL = 431,
     KW_USES_EXTENDED = 432,
     SPECIAL_DBNAME = 433,
     KW_ACTION = 434,
     KW_PAGE = 435,
     KW_HBOX = 436,
     KW_VBOX = 437,
     KW_GRID = 438,
     KW_GROUP = 439,
     KW_TABLE = 440,
     KW_FOLDER = 441,
     KW_STYLE = 442,
     KW_LAYOUT = 443,
     KW_HIDDEN = 444,
     KW_AUTOSIZE = 445,
     KW_TEXTEDIT = 446,
     KW_BUTTONEDIT = 447,
     KW_LABEL = 448,
     KW_EDIT = 449,
     KW_DATEEDIT = 450,
     KW_SCROLL = 451,
     KW_IMAGE = 452,
     KW_FONTPITCH = 453,
     KW_FIXED = 454,
     KW_VARIABLE = 455,
     KW_WANTNORETURNS = 456,
     KW_WANTTABS = 457,
     KW_AUTOSCALE = 458,
     KW_PIXELWIDTH = 459,
     KW_PIXELHEIGHT = 460,
     KW_BORDER = 461,
     KW_SCROLLBARS_BOTH = 462,
     KW_SCROLLBARS_V = 463,
     KW_SCROLLBARS_H = 464,
     KW_STRETCH_Y = 465,
     KW_STRETCH_BOTH = 466,
     KW_ITEMS = 467,
     KW_VALUEMAX = 468,
     KW_VALUEMIN = 469,
     KW_PROGRESSBAR = 470,
     KW_COMBOBOX = 471,
     OPTIONS = 472,
     KW_BROWSER = 473,
     KW_VALUECHECKED = 474,
     KW_VALUEUNCHECKED = 475,
     KW_CHECKBOX = 476
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
#define CHARACTER_ENCODING 302
#define SEMICOLON 303
#define LOOKUP 304
#define JOINING 305
#define LOOKUP_FROM 306
#define OPEN_BRACKET 307
#define CLOSE_BRACKET 308
#define STAR 309
#define DIVIDE 310
#define PLUS 311
#define MINUS 312
#define RECORD 313
#define COMMA 314
#define THROUGH 315
#define TYPE 316
#define DELIMITERS 317
#define KW_CHAR 318
#define KW_INT 319
#define KW_DATE 320
#define KW_FLOAT 321
#define SMALLFLOAT 322
#define SMALLINT 323
#define KW_DECIMAL 324
#define MONEY 325
#define DATETIME 326
#define INTERVAL 327
#define LIKE 328
#define BLACK 329
#define BLUE 330
#define GREEN 331
#define CYAN 332
#define RED 333
#define MAGENTA 334
#define WHITE 335
#define YELLOW 336
#define NORMAL 337
#define REVERSE 338
#define LEFT 339
#define BOLD 340
#define BLINK 341
#define UNDERLINE 342
#define DIM 343
#define AUTONEXT 344
#define COLOR 345
#define COMMENTS 346
#define DEFAULT 347
#define VALIDATE 348
#define DISPLAY 349
#define DOWNSHIFT 350
#define UPSHIFT 351
#define FORMAT 352
#define INCLUDE 353
#define INVISIBLE 354
#define NOUPDATE 355
#define NOENTRY 356
#define PICTURE 357
#define PROGRAM 358
#define REQUIRED 359
#define QUERYCLEAR 360
#define VERIFY 361
#define WORDWRAP 362
#define COMPRESS 363
#define NONCOMPRESS 364
#define TO 365
#define AS 366
#define UNHIDABLE 367
#define SERIAL 368
#define KW_BYTE 369
#define KW_TEXT 370
#define VARCHAR 371
#define SQL_VAR 372
#define KW_NONSPACE 373
#define SQLONLY 374
#define WIDGET 375
#define CONFIG 376
#define KW_NL 377
#define COMPARISON 378
#define KWOR 379
#define KWAND 380
#define KWAND1 381
#define KWWHERE 382
#define KWNOT 383
#define KWBETWEEN 384
#define KWIN 385
#define XVAL 386
#define KWNULLCHK 387
#define KWNOTNULLCHK 388
#define YEAR 389
#define MONTH 390
#define DAY 391
#define HOUR 392
#define MINUTE 393
#define SECOND 394
#define FRACTION 395
#define KW_JUSTIFY 396
#define KW_CENTER 397
#define KW_TABINDEX 398
#define KW_NOT_NULL 399
#define LISTBOX 400
#define BUTTON 401
#define KW_PANEL 402
#define DISPLAYONLY 403
#define ALLOWING 404
#define KW_WS 405
#define KW_TAB 406
#define KW_MASTER_OF 407
#define KW_BEFORE 408
#define KW_AFTER 409
#define KW_EDITADD 410
#define KW_EDITUPDATE 411
#define KW_REMOVE 412
#define KW_OF 413
#define KW_ADD 414
#define KW_UPDATE 415
#define KW_QUERY 416
#define KW_ON_ENDING 417
#define KW_ON_BEGINNING 418
#define KW_CALL 419
#define KW_BELL 420
#define KW_ABORT 421
#define KW_LET 422
#define KW_EXITNOW 423
#define KW_NEXTFIELD 424
#define KW_IF 425
#define KW_THEN 426
#define KW_ELSE 427
#define KW_BEGIN 428
#define KW_TOTAL 429
#define KW_RIGHT 430
#define KW_ZEROFILL 431
#define KW_USES_EXTENDED 432
#define SPECIAL_DBNAME 433
#define KW_ACTION 434
#define KW_PAGE 435
#define KW_HBOX 436
#define KW_VBOX 437
#define KW_GRID 438
#define KW_GROUP 439
#define KW_TABLE 440
#define KW_FOLDER 441
#define KW_STYLE 442
#define KW_LAYOUT 443
#define KW_HIDDEN 444
#define KW_AUTOSIZE 445
#define KW_TEXTEDIT 446
#define KW_BUTTONEDIT 447
#define KW_LABEL 448
#define KW_EDIT 449
#define KW_DATEEDIT 450
#define KW_SCROLL 451
#define KW_IMAGE 452
#define KW_FONTPITCH 453
#define KW_FIXED 454
#define KW_VARIABLE 455
#define KW_WANTNORETURNS 456
#define KW_WANTTABS 457
#define KW_AUTOSCALE 458
#define KW_PIXELWIDTH 459
#define KW_PIXELHEIGHT 460
#define KW_BORDER 461
#define KW_SCROLLBARS_BOTH 462
#define KW_SCROLLBARS_V 463
#define KW_SCROLLBARS_H 464
#define KW_STRETCH_Y 465
#define KW_STRETCH_BOTH 466
#define KW_ITEMS 467
#define KW_VALUEMAX 468
#define KW_VALUEMIN 469
#define KW_PROGRESSBAR 470
#define KW_COMBOBOX 471
#define OPTIONS 472
#define KW_BROWSER 473
#define KW_VALUECHECKED 474
#define KW_VALUEUNCHECKED 475
#define KW_CHECKBOX 476




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 82 "screen.yacc"

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



/* Line 214 of yacc.c  */
#line 662 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 674 "y.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   881

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  222
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  162
/* YYNRULES -- Number of rules.  */
#define YYNRULES  481
/* YYNRULES -- Number of states.  */
#define YYNSTATES  794

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   476

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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    11,    14,    17,    23,    29,    32,
      34,    36,    38,    42,    44,    48,    50,    52,    58,    64,
      70,    76,    78,    81,    87,    88,    90,    91,    92,    93,
     104,   105,   106,   107,   118,   119,   120,   125,   129,   131,
     133,   137,   141,   143,   145,   148,   152,   153,   155,   157,
     160,   162,   164,   166,   168,   170,   172,   177,   179,   182,
     183,   187,   188,   193,   194,   195,   196,   206,   207,   209,
     210,   213,   218,   219,   221,   223,   226,   228,   230,   232,
     234,   236,   238,   240,   242,   244,   246,   248,   250,   253,
     254,   259,   261,   262,   267,   268,   272,   274,   277,   281,
     284,   285,   288,   290,   294,   298,   304,   308,   312,   316,
     318,   321,   322,   324,   326,   328,   330,   332,   334,   336,
     338,   340,   342,   344,   345,   351,   353,   356,   360,   362,
     364,   365,   366,   373,   374,   378,   384,   388,   390,   391,
     397,   401,   404,   409,   412,   417,   421,   423,   428,   431,
     433,   437,   441,   443,   447,   449,   453,   455,   460,   463,
     465,   468,   469,   472,   474,   478,   480,   485,   488,   493,
     497,   501,   505,   509,   515,   519,   525,   527,   529,   533,
     539,   543,   547,   551,   553,   558,   560,   562,   564,   566,
     570,   574,   576,   578,   580,   582,   584,   586,   588,   590,
     593,   596,   598,   600,   602,   604,   608,   612,   614,   618,
     622,   626,   630,   634,   638,   640,   642,   644,   646,   648,
     654,   658,   662,   666,   670,   674,   678,   682,   686,   690,
     694,   696,   698,   700,   702,   705,   707,   709,   711,   713,
     715,   717,   719,   721,   723,   725,   727,   729,   731,   733,
     735,   737,   738,   742,   744,   747,   749,   752,   755,   757,
     758,   768,   781,   783,   785,   786,   789,   790,   792,   793,
     795,   797,   802,   804,   808,   809,   811,   813,   817,   821,
     825,   829,   831,   835,   837,   839,   840,   842,   844,   847,
     849,   851,   853,   854,   859,   861,   863,   865,   867,   869,
     871,   874,   877,   880,   883,   885,   887,   889,   891,   893,
     895,   899,   901,   905,   907,   910,   913,   915,   917,   919,
     921,   923,   925,   929,   933,   935,   937,   939,   941,   943,
     944,   948,   954,   955,   959,   960,   964,   966,   969,   971,
     973,   975,   977,   979,   981,   984,   986,   987,   991,   993,
     995,   997,   999,  1001,  1003,  1005,  1007,  1010,  1011,  1015,
    1016,  1018,  1021,  1023,  1027,  1031,  1035,  1039,  1043,  1047,
    1052,  1056,  1059,  1062,  1064,  1070,  1076,  1079,  1083,  1085,
    1087,  1089,  1091,  1093,  1095,  1099,  1102,  1104,  1107,  1115,
    1117,  1121,  1125,  1127,  1129,  1131,  1137,  1143,  1146,  1149,
    1151,  1153,  1155,  1157,  1159,  1161,  1163,  1169,  1170,  1173,
    1175,  1180,  1183,  1187,  1190,  1194,  1198,  1200,  1203,  1206,
    1210,  1214,  1219,  1221,  1224,  1226,  1229,  1231,  1233,  1235,
    1237,  1239,  1241,  1243,  1245,  1247,  1249,  1251,  1255,  1259,
    1261,  1266,  1267,  1274,  1275,  1277,  1279,  1283,  1285,  1287,
    1291,  1293,  1295,  1298,  1301,  1303,  1306,  1310,  1315,  1319,
    1323,  1327,  1331,  1335,  1339,  1343,  1347,  1351,  1356,  1360,
    1363,  1366,  1372,  1378,  1385,  1387,  1389,  1391,  1393,  1395,
    1397,  1399
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     223,     0,    -1,   225,   224,   229,   272,   277,   303,    -1,
      -1,    47,    46,    -1,    21,    34,    -1,    21,   228,    40,
      41,    42,    -1,    21,    34,    40,    41,    42,    -1,    21,
     228,    -1,    30,    -1,    30,    -1,   178,    -1,   178,    38,
     227,    -1,   226,    -1,   226,    38,   227,    -1,   253,    -1,
     252,    -1,   182,   236,   245,   249,    27,    -1,   181,   236,
     245,   249,    27,    -1,   184,   236,   245,   249,    27,    -1,
     186,   236,   245,   234,    27,    -1,   235,    -1,   234,   235,
      -1,   180,   236,   245,   249,    27,    -1,    -1,   227,    -1,
      -1,    -1,    -1,   183,   238,   236,   245,    31,   239,   264,
      32,   240,    27,    -1,    -1,    -1,    -1,   185,   242,   236,
     245,    31,   243,   264,    32,   244,    27,    -1,    -1,    -1,
      52,   246,   248,    53,    -1,   187,    45,    46,    -1,   189,
      -1,   190,    -1,   115,    45,    46,    -1,   179,    45,    30,
      -1,   206,    -1,   247,    -1,   248,   247,    -1,   248,    59,
     247,    -1,    -1,   250,    -1,   251,    -1,   250,   251,    -1,
     230,    -1,   231,    -1,   232,    -1,   233,    -1,   237,    -1,
     241,    -1,   188,   245,   251,   263,    -1,   254,    -1,   253,
     254,    -1,    -1,    24,   255,   257,    -1,    -1,    23,    46,
     256,   257,    -1,    -1,    -1,    -1,   262,   258,   261,    31,
     259,   264,    32,   260,   263,    -1,    -1,   177,    -1,    -1,
      25,    29,    -1,    25,    29,    22,    29,    -1,    -1,    27,
      -1,   266,    -1,   264,   266,    -1,   227,    -1,   265,    -1,
     268,    -1,   151,    -1,    17,    -1,    44,    -1,    46,    -1,
     267,    -1,   150,    -1,   122,    -1,   118,    -1,    16,    -1,
     267,    16,    -1,    -1,    26,   269,   270,    28,    -1,   321,
      -1,    -1,   270,    44,   271,   321,    -1,    -1,    43,   273,
     263,    -1,   274,    -1,   273,   274,    -1,   273,    59,   274,
      -1,   227,   275,    -1,    -1,    45,   276,    -1,   227,    -1,
     227,    37,   227,    -1,   227,    38,   227,    -1,   227,    38,
     227,    37,   227,    -1,   227,    39,   227,    -1,    46,    39,
     227,    -1,    20,   278,   263,    -1,   280,    -1,   278,   280,
      -1,    -1,   194,    -1,   191,    -1,   193,    -1,   195,    -1,
     192,    -1,   146,    -1,   197,    -1,   215,    -1,   216,    -1,
     221,    -1,   218,    -1,    -1,   279,   320,   281,   282,    48,
      -1,   284,    -1,   282,   284,    -1,   282,    48,   284,    -1,
      45,    -1,    37,    -1,    -1,    -1,   283,   285,   290,   287,
     286,   297,    -1,    -1,    26,    29,    28,    -1,    26,    29,
      59,    29,    28,    -1,   289,   128,    41,    -1,   289,    -1,
      -1,    61,    73,   227,    39,   227,    -1,    61,    73,   227,
      -1,    61,   323,    -1,    34,    39,   316,   288,    -1,   148,
     288,    -1,   148,   149,    42,   288,    -1,   227,    39,   227,
      -1,   227,    -1,    54,   227,    39,   227,    -1,    54,   227,
      -1,   292,    -1,   291,    59,   292,    -1,   293,    45,   294,
      -1,   320,    -1,   227,    39,   227,    -1,   227,    -1,   227,
      39,   227,    -1,   227,    -1,    54,   227,    39,   227,    -1,
      54,   227,    -1,    50,    -1,    59,    50,    -1,    -1,    59,
     298,    -1,   299,    -1,   298,    59,   299,    -1,    89,    -1,
      90,    45,   301,   342,    -1,    51,   295,    -1,    49,   291,
     296,   295,    -1,    91,    45,    46,    -1,    92,    45,   300,
      -1,   217,    45,   300,    -1,    94,    73,   227,    -1,    94,
      73,   227,    39,   227,    -1,    93,    73,   227,    -1,    93,
      73,   227,    39,   227,    -1,    95,    -1,    96,    -1,    97,
      45,    46,    -1,    98,    45,    52,   324,    53,    -1,   120,
      45,    46,    -1,   121,    45,    46,    -1,   179,    45,   227,
      -1,    99,    -1,    36,    25,    45,    29,    -1,    36,    -1,
     119,    -1,   101,    -1,   100,    -1,   102,    45,    46,    -1,
     103,    45,    46,    -1,   104,    -1,   112,    -1,    83,    -1,
     106,    -1,   105,    -1,   176,    -1,   175,    -1,   107,    -1,
     107,   108,    -1,   107,   109,    -1,   189,    -1,   203,    -1,
     201,    -1,   202,    -1,   198,    45,   199,    -1,   198,    45,
     200,    -1,   196,    -1,   197,    45,    46,    -1,   141,    45,
      84,    -1,   141,    45,   175,    -1,   141,    45,   142,    -1,
     205,    45,    29,    -1,   204,    45,    29,    -1,   207,    -1,
     208,    -1,   209,    -1,   210,    -1,   211,    -1,   212,    45,
      52,   325,    53,    -1,   143,    45,    29,    -1,   213,    45,
      29,    -1,   214,    45,    29,    -1,   144,    45,    29,    -1,
     219,    45,    46,    -1,   220,    45,    46,    -1,   219,    45,
      29,    -1,   220,    45,    29,    -1,   115,    45,    46,    -1,
     187,    45,    46,    -1,    46,    -1,    29,    -1,   117,    -1,
     302,    -1,   301,   302,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    29,    -1,    83,    -1,    88,    -1,    82,    -1,    84,
      -1,    85,    -1,    86,    -1,    87,    -1,    -1,    19,   304,
     263,    -1,   305,    -1,   304,   305,    -1,   306,    -1,   306,
      48,    -1,    62,    46,    -1,   356,    -1,    -1,    24,    58,
     307,   311,    52,   312,    53,   308,   310,    -1,   147,    52,
      29,    59,    29,    53,   110,    52,    29,    59,    29,    53,
      -1,   349,    -1,   372,    -1,    -1,   111,   145,    -1,    -1,
      54,    -1,    -1,    48,    -1,   227,    -1,   227,    26,    29,
      28,    -1,   315,    -1,   312,   313,   315,    -1,    -1,    59,
      -1,   227,    -1,   227,    39,   227,    -1,    34,    39,   227,
      -1,   227,    39,    54,    -1,    34,    39,    54,    -1,   314,
      -1,   314,    60,   314,    -1,   227,    -1,    27,    -1,    -1,
     318,    -1,   319,    -1,   318,   319,    -1,   150,    -1,   151,
      -1,   227,    -1,    -1,   317,   227,   322,   317,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,
      -1,    69,   330,    -1,    70,   330,    -1,    71,   337,    -1,
      72,   331,    -1,   113,    -1,   114,    -1,   115,    -1,   116,
      -1,   146,    -1,   328,    -1,   324,    59,   328,    -1,   327,
      -1,   325,    59,   327,    -1,    29,    -1,    56,    29,    -1,
      57,    29,    -1,    46,    -1,    30,    -1,    16,    -1,   326,
      -1,    41,    -1,   329,    -1,   329,   110,   329,    -1,   329,
      37,   329,    -1,    46,    -1,    30,    -1,    16,    -1,   326,
      -1,    41,    -1,    -1,    52,    29,    53,    -1,    52,    29,
      59,    29,    53,    -1,    -1,   334,   110,   336,    -1,    -1,
      52,    29,    53,    -1,    29,    -1,   335,   332,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,   139,
      -1,   140,   341,    -1,   335,    -1,    -1,   338,   110,   339,
      -1,   340,    -1,   340,    -1,   134,    -1,   135,    -1,   136,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,   341,    -1,
      -1,    52,   333,    53,    -1,    -1,   343,    -1,   127,   344,
      -1,   345,    -1,   345,   125,   345,    -1,   345,   124,   345,
      -1,   346,   123,   346,    -1,   346,     8,   346,    -1,   346,
       9,   346,    -1,   346,    73,   346,    -1,   346,   128,    73,
     346,    -1,   346,    45,   346,    -1,   346,   132,    -1,   346,
     133,    -1,   346,    -1,   346,   129,   346,   125,   346,    -1,
     346,   130,    52,   348,    53,    -1,   128,   345,    -1,    52,
     345,    53,    -1,   347,    -1,    29,    -1,    46,    -1,   131,
      -1,    30,    -1,   346,    -1,   348,    59,   346,    -1,    18,
     350,    -1,   351,    -1,   350,   351,    -1,     8,   352,     9,
     309,     8,   352,     9,    -1,   353,    -1,   352,    59,   353,
      -1,   354,    39,   355,    -1,   355,    -1,   227,    -1,   226,
      -1,   153,   366,   158,   370,   364,    -1,   154,   367,   158,
     370,   364,    -1,   163,   373,    -1,   162,   373,    -1,   360,
      -1,   365,    -1,   358,    -1,   361,    -1,   362,    -1,   373,
      -1,   363,    -1,   170,   378,   171,   357,   359,    -1,    -1,
     172,   357,    -1,   166,    -1,   167,   320,    45,   378,    -1,
     169,   320,    -1,   169,    45,   320,    -1,   169,   168,    -1,
     169,    45,   168,    -1,   173,   364,    27,    -1,   357,    -1,
     364,   357,    -1,    91,    46,    -1,    91,   165,    46,    -1,
      91,    83,    46,    -1,    91,   165,    83,    46,    -1,   368,
      -1,   366,   368,    -1,   369,    -1,   367,   369,    -1,   155,
      -1,   156,    -1,   157,    -1,   155,    -1,   159,    -1,   160,
      -1,   161,    -1,   157,    -1,    94,    -1,   156,    -1,   371,
      -1,   370,   313,   371,    -1,   354,    39,   355,    -1,   355,
      -1,   354,   152,   354,   310,    -1,    -1,   164,   227,    52,
     374,   375,    53,    -1,    -1,   376,    -1,   377,    -1,   376,
      59,   377,    -1,   378,    -1,   380,    -1,   378,   379,   378,
      -1,   125,    -1,   124,    -1,    57,   378,    -1,    56,   378,
      -1,   382,    -1,   128,   378,    -1,    52,   378,    53,    -1,
     381,    52,   375,    53,    -1,   174,   158,   320,    -1,   378,
     123,   378,    -1,   378,     8,   378,    -1,   378,     9,   378,
      -1,   378,    54,   378,    -1,   378,    56,   378,    -1,   378,
      57,   378,    -1,   378,    55,   378,    -1,   378,    73,   378,
      -1,   378,   128,    73,   378,    -1,   378,    45,   378,    -1,
     378,   132,    -1,   378,   133,    -1,   378,   129,   378,   125,
     378,    -1,   378,   130,    52,   383,    53,    -1,   378,   128,
     130,    52,   383,    53,    -1,   227,    -1,   320,    -1,    29,
      -1,    46,    -1,   131,    -1,    41,    -1,   382,    -1,   383,
      59,   382,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   158,   159,   165,   168,   174,   177,   187,
     191,   195,   196,   197,   198,   203,   206,   213,   223,   232,
     245,   253,   263,   271,   284,   285,   290,   293,   296,   289,
     312,   315,   318,   311,   332,   335,   335,   341,   344,   347,
     350,   353,   356,   362,   363,   364,   368,   377,   383,   393,
     400,   402,   404,   406,   408,   410,   415,   425,   425,   428,
     428,   441,   441,   460,   462,   465,   460,   470,   470,   475,
     476,   477,   489,   490,   495,   496,   499,   514,   526,   527,
     538,   549,   562,   574,   585,   590,   593,   601,   602,   608,
     607,   632,   635,   635,   653,   654,   657,   658,   659,   662,
     671,   672,   675,   676,   677,   679,   680,   681,   687,   691,
     691,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   712,   711,   740,   741,   742,   745,   745,
     748,   752,   748,  1072,  1073,  1079,  1089,  1090,  1093,  1094,
    1097,  1100,  1105,  1116,  1130,  1144,  1153,  1162,  1171,  1186,
    1195,  1204,  1211,  1213,  1216,  1222,  1223,  1224,  1225,  1228,
    1229,  1233,  1234,  1238,  1238,  1241,  1246,  1268,  1292,  1300,
    1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,
    1311,  1312,  1313,  1314,  1315,  1316,  1317,  1319,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,
    1336,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,
    1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,
    1362,  1363,  1364,  1365,  1367,  1368,  1369,  1370,  1371,  1372,
    1378,  1379,  1380,  1384,  1385,  1389,  1390,  1391,  1392,  1393,
    1394,  1395,  1396,  1398,  1433,  1434,  1435,  1436,  1437,  1438,
    1439,  1443,  1444,  1447,  1447,  1449,  1449,  1452,  1462,  1468,
    1468,  1471,  1472,  1473,  1477,  1477,  1479,  1479,  1482,  1482,
    1484,  1487,  1493,  1496,  1500,  1501,  1505,  1509,  1513,  1517,
    1521,  1528,  1528,  1532,  1535,  1539,  1539,  1542,  1542,  1546,
    1547,  1560,  1568,  1568,  1577,  1581,  1585,  1589,  1593,  1597,
    1601,  1607,  1611,  1615,  1619,  1623,  1627,  1631,  1634,  1641,
    1641,  1645,  1645,  1650,  1650,  1650,  1654,  1661,  1662,  1663,
    1664,  1671,  1672,  1675,  1681,  1688,  1689,  1690,  1691,  1697,
    1700,  1701,  1704,  1705,  1712,  1714,  1719,  1727,  1730,  1731,
    1732,  1733,  1734,  1735,  1736,  1742,  1744,  1745,  1748,  1751,
    1755,  1756,  1757,  1758,  1759,  1760,  1761,  1767,  1769,  1776,
    1776,  1782,  1788,  1789,  1792,  1798,  1799,  1800,  1801,  1802,
    1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1813,  1820,
    1821,  1822,  1827,  1830,  1834,  1846,  1849,  1850,  1854,  1864,
    1871,  1880,  1883,  1895,  1898,  1902,  1909,  1917,  1922,  1930,
    1934,  1939,  1944,  1949,  1954,  1959,  1968,  1977,  1978,  1983,
    1986,  1994,  2000,  2006,  2012,  2021,  2026,  2036,  2046,  2052,
    2058,  2064,  2074,  2086,  2094,  2106,  2114,  2115,  2116,  2120,
    2121,  2122,  2123,  2124,  2125,  2126,  2129,  2136,  2147,  2151,
    2158,  2166,  2166,  2184,  2185,  2191,  2197,  2205,  2212,  2213,
    2218,  2219,  2235,  2237,  2238,  2239,  2240,  2241,  2244,  2245,
    2246,  2247,  2248,  2249,  2250,  2251,  2252,  2253,  2254,  2255,
    2256,  2257,  2258,  2259,  2262,  2265,  2266,  2267,  2268,  2269,
    2272,  2276
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
  "CHARACTER_ENCODING", "SEMICOLON", "LOOKUP", "JOINING", "LOOKUP_FROM",
  "OPEN_BRACKET", "CLOSE_BRACKET", "STAR", "DIVIDE", "PLUS", "MINUS",
  "RECORD", "COMMA", "THROUGH", "TYPE", "DELIMITERS", "KW_CHAR", "KW_INT",
  "KW_DATE", "KW_FLOAT", "SMALLFLOAT", "SMALLINT", "KW_DECIMAL", "MONEY",
  "DATETIME", "INTERVAL", "LIKE", "BLACK", "BLUE", "GREEN", "CYAN", "RED",
  "MAGENTA", "WHITE", "YELLOW", "NORMAL", "REVERSE", "LEFT", "BOLD",
  "BLINK", "UNDERLINE", "DIM", "AUTONEXT", "COLOR", "COMMENTS", "DEFAULT",
  "VALIDATE", "DISPLAY", "DOWNSHIFT", "UPSHIFT", "FORMAT", "INCLUDE",
  "INVISIBLE", "NOUPDATE", "NOENTRY", "PICTURE", "PROGRAM", "REQUIRED",
  "QUERYCLEAR", "VERIFY", "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO",
  "AS", "UNHIDABLE", "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR",
  "KW_NONSPACE", "SQLONLY", "WIDGET", "CONFIG", "KW_NL", "COMPARISON",
  "KWOR", "KWAND", "KWAND1", "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN",
  "XVAL", "KWNULLCHK", "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR",
  "MINUTE", "SECOND", "FRACTION", "KW_JUSTIFY", "KW_CENTER", "KW_TABINDEX",
  "KW_NOT_NULL", "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY",
  "ALLOWING", "KW_WS", "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER",
  "KW_EDITADD", "KW_EDITUPDATE", "KW_REMOVE", "KW_OF", "KW_ADD",
  "KW_UPDATE", "KW_QUERY", "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL",
  "KW_BELL", "KW_ABORT", "KW_LET", "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF",
  "KW_THEN", "KW_ELSE", "KW_BEGIN", "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL",
  "KW_USES_EXTENDED", "SPECIAL_DBNAME", "KW_ACTION", "KW_PAGE", "KW_HBOX",
  "KW_VBOX", "KW_GRID", "KW_GROUP", "KW_TABLE", "KW_FOLDER", "KW_STYLE",
  "KW_LAYOUT", "KW_HIDDEN", "KW_AUTOSIZE", "KW_TEXTEDIT", "KW_BUTTONEDIT",
  "KW_LABEL", "KW_EDIT", "KW_DATEEDIT", "KW_SCROLL", "KW_IMAGE",
  "KW_FONTPITCH", "KW_FIXED", "KW_VARIABLE", "KW_WANTNORETURNS",
  "KW_WANTTABS", "KW_AUTOSCALE", "KW_PIXELWIDTH", "KW_PIXELHEIGHT",
  "KW_BORDER", "KW_SCROLLBARS_BOTH", "KW_SCROLLBARS_V", "KW_SCROLLBARS_H",
  "KW_STRETCH_Y", "KW_STRETCH_BOTH", "KW_ITEMS", "KW_VALUEMAX",
  "KW_VALUEMIN", "KW_PROGRESSBAR", "KW_COMBOBOX", "OPTIONS", "KW_BROWSER",
  "KW_VALUECHECKED", "KW_VALUEUNCHECKED", "KW_CHECKBOX", "$accept",
  "form_def", "encoding_section", "database_section", "named_or_kw_st",
  "named_or_kw_any", "dbname", "screen_or_layout_section", "vbox_section",
  "hbox_section", "group_section", "folder_section", "pages", "page",
  "opt_layout_ident", "grid_section", "@1", "$@2", "$@3", "table_section",
  "@4", "$@5", "$@6", "layout_attributes", "$@7", "layout_attribute",
  "layout_attribute_list", "op_layout_items", "layout_items",
  "layout_container", "layout_section", "screen_section",
  "screens_section", "$@8", "$@9", "screens_rest", "$@10", "$@11", "$@12",
  "op_extended", "op_size", "op_end", "screen_layout", "some_text",
  "screen_element", "ch_list", "field", "$@13", "field_element", "$@14",
  "op_table_section", "table_def_list", "table_def", "opequal",
  "table_qualifier", "attribute_section", "field_tag_list",
  "op_field_tag_type", "field_tag", "$@15", "fpart_list", "eq_or_colon",
  "fpart", "$@16", "$@17", "op_att", "field_datatype_null",
  "field_datatype", "field_type", "lu_ft_eq_c", "lu_ft_eq_c_i", "lu_ft",
  "lu_fc", "lu_joincol", "lu_join", "op_field_desc", "op_desc_list",
  "desc", "def_val", "colors", "color", "op_instruction_section",
  "instruct_opts", "instruct_op_1", "instruct_op", "$@18", "op_ltype",
  "op_star", "op_semi", "srec_dim", "srec_field_list", "op_comma",
  "field_list_item", "field_list_element", "field_name", "op_ws", "ws",
  "ws_elem", "field_tag_name", "field_tag_name_scr", "$@19", "datatype",
  "incl_list", "items_list", "number_value", "items_entry", "incl_entry",
  "incl_item", "opt_dec_ext", "opt_int_ext", "opt_unit_size", "dtfrac",
  "int_start", "int_start_unit", "int_end", "opt_dt_ext", "dt_start",
  "dt_end", "dtime_val", "opt_frac", "op_where", "where_clause", "clauses",
  "clause", "value", "fieldidentifier", "value_list", "composites",
  "composites_list", "composite_entry", "comp_list", "comp_item",
  "table_name", "column_name", "control_block", "action", "if", "op_else",
  "abort", "let", "nextfield", "block", "actions", "comments",
  "bef_act_list", "aft_act_list", "bef_act", "aft_act", "column_list",
  "column_entry", "master_of", "func_call", "@20", "op_func_call_args",
  "func_call_args", "func_call_arg", "expression", "and_or",
  "single_expression", "fcall_name", "evalue", "evalue_list", 0
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   222,   223,   224,   224,   225,   225,   225,   225,   226,
     227,   228,   228,   228,   228,   229,   229,   230,   231,   232,
     233,   234,   234,   235,   236,   236,   238,   239,   240,   237,
     242,   243,   244,   241,   245,   246,   245,   247,   247,   247,
     247,   247,   247,   248,   248,   248,   249,   249,   250,   250,
     251,   251,   251,   251,   251,   251,   252,   253,   253,   255,
     254,   256,   254,   258,   259,   260,   257,   261,   261,   262,
     262,   262,   263,   263,   264,   264,   265,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   267,   267,   269,
     268,   270,   271,   270,   272,   272,   273,   273,   273,   274,
     275,   275,   276,   276,   276,   276,   276,   276,   277,   278,
     278,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   281,   280,   282,   282,   282,   283,   283,
     285,   286,   284,   287,   287,   287,   288,   288,   289,   289,
     289,   289,   290,   290,   290,   290,   290,   290,   290,   291,
     291,   292,   293,   294,   294,   295,   295,   295,   295,   296,
     296,   297,   297,   298,   298,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     300,   300,   300,   301,   301,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   303,   303,   304,   304,   305,   305,   306,   306,   307,
     306,   306,   306,   306,   308,   308,   309,   309,   310,   310,
     311,   311,   312,   312,   313,   313,   314,   314,   314,   314,
     314,   315,   315,   316,   316,   317,   317,   318,   318,   319,
     319,   320,   322,   321,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   324,
     324,   325,   325,   326,   326,   326,   327,   327,   327,   327,
     327,   328,   328,   328,   329,   329,   329,   329,   329,   330,
     330,   330,   331,   331,   332,   332,   333,   334,   335,   335,
     335,   335,   335,   335,   335,   336,   337,   337,   338,   339,
     340,   340,   340,   340,   340,   340,   340,   341,   341,   342,
     342,   343,   344,   344,   344,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   346,   346,
     346,   346,   347,   348,   348,   349,   350,   350,   351,   352,
     352,   353,   353,   354,   355,   356,   356,   356,   356,   357,
     357,   357,   357,   357,   357,   357,   358,   359,   359,   360,
     361,   362,   362,   362,   362,   363,   364,   364,   365,   365,
     365,   365,   366,   366,   367,   367,   368,   368,   368,   369,
     369,   369,   369,   369,   369,   369,   370,   370,   371,   371,
     372,   374,   373,   375,   375,   376,   376,   377,   378,   378,
     379,   379,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   381,   382,   382,   382,   382,   382,
     383,   383
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     5,     5,     2,     1,
       1,     1,     3,     1,     3,     1,     1,     5,     5,     5,
       5,     1,     2,     5,     0,     1,     0,     0,     0,    10,
       0,     0,     0,    10,     0,     0,     4,     3,     1,     1,
       3,     3,     1,     1,     2,     3,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     4,     1,     2,     0,
       3,     0,     4,     0,     0,     0,     9,     0,     1,     0,
       2,     4,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       4,     1,     0,     4,     0,     3,     1,     2,     3,     2,
       0,     2,     1,     3,     3,     5,     3,     3,     3,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     1,     2,     3,     1,     1,
       0,     0,     6,     0,     3,     5,     3,     1,     0,     5,
       3,     2,     4,     2,     4,     3,     1,     4,     2,     1,
       3,     3,     1,     3,     1,     3,     1,     4,     2,     1,
       2,     0,     2,     1,     3,     1,     4,     2,     4,     3,
       3,     3,     3,     5,     3,     5,     1,     1,     3,     5,
       3,     3,     3,     1,     4,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     1,     2,     1,     2,     2,     1,     0,
       9,    12,     1,     1,     0,     2,     0,     1,     0,     1,
       1,     4,     1,     3,     0,     1,     1,     3,     3,     3,
       3,     1,     3,     1,     1,     0,     1,     1,     2,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     0,
       3,     5,     0,     3,     0,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     3,     0,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     4,
       3,     2,     2,     1,     5,     5,     2,     3,     1,     1,
       1,     1,     1,     1,     3,     2,     1,     2,     7,     1,
       3,     3,     1,     1,     1,     5,     5,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     5,     0,     2,     1,
       4,     2,     3,     2,     3,     3,     1,     2,     2,     3,
       3,     4,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       4,     0,     6,     0,     1,     1,     3,     1,     1,     3,
       1,     1,     2,     2,     1,     2,     3,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     2,
       2,     5,     5,     6,     1,     1,     1,     1,     1,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     3,     9,     5,    11,    13,     8,     1,
       0,     0,     0,     0,     0,     0,     4,     0,    59,    34,
      94,    16,    15,    57,     0,    10,    12,    14,     0,    61,
      69,    35,     0,     0,     0,    58,     7,     6,    69,     0,
      60,    63,     0,    24,    24,    26,    24,    30,    24,    50,
      51,    52,    53,    54,    55,    72,   100,    72,    96,   111,
     251,    62,    70,    67,     0,     0,     0,    38,    39,    42,
      43,     0,    25,    34,    34,    24,    34,    24,    34,    73,
      56,     0,    99,     0,    95,    97,   117,   113,   116,   114,
     112,   115,   118,   119,   120,   122,   121,    72,     0,   109,
       0,     2,     0,    68,     0,     0,     0,     0,    36,     0,
      44,    46,    46,    34,    46,    34,     0,     0,   102,   101,
      98,   108,   110,   291,   123,     0,     0,     0,     0,     0,
       0,     0,     0,   393,    72,   253,   255,   262,     0,   258,
     263,    71,    64,    40,    41,    37,    45,     0,    47,    48,
       0,     0,     0,     0,    24,     0,    21,     0,     0,     0,
       0,     0,     0,   385,   386,   259,   257,     0,   426,   427,
     428,     0,   422,   434,   429,   435,   433,   430,   431,   432,
       0,   424,     0,   398,   397,   252,   254,   256,     0,     0,
      18,    49,    17,    27,    19,    31,    34,    20,    22,   107,
     103,   104,   106,   129,   128,     0,   130,   125,     9,   394,
       0,   389,     0,   392,   387,     0,     0,     0,   423,     0,
     425,     0,   268,    87,    80,    89,    81,    82,    86,    85,
      84,    79,    76,     0,    77,    74,    83,    78,     0,     0,
      46,     0,   124,   126,     0,   266,     0,     0,   270,     0,
       0,     0,   439,   274,   436,   274,   441,   269,   440,   285,
      65,    75,    88,     0,     0,     0,   105,   127,     0,     0,
     138,   146,   133,   267,     0,   390,   391,     0,     0,     0,
       0,   275,     0,   409,     0,     0,     0,     0,     0,   416,
     401,   399,   402,   403,   405,   395,   400,   404,   396,   443,
     289,   290,     0,     0,   286,   287,    91,    72,    28,    32,
      23,     0,   148,     0,     0,   143,   137,     0,     0,   131,
       0,     0,     0,   276,   274,   281,   272,     0,   438,   418,
       0,     0,     0,     0,   413,   411,   476,   479,   477,     0,
       0,     0,     0,   478,     0,   291,   475,     0,   448,     0,
     454,     0,   437,   417,     0,   444,   445,   447,    90,    92,
     292,   288,    66,     0,     0,   284,   283,   138,     0,   294,
     295,   296,   297,   298,   299,   329,   329,   346,   332,     0,
     304,   305,   306,   307,   308,   141,   138,     0,   145,     0,
     161,     0,   271,     0,     0,   264,     0,     0,     0,   420,
     419,     0,     0,   414,   412,     0,   453,   452,   455,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   451,
     450,     0,     0,     0,   469,   470,     0,     0,   443,   415,
     442,     0,   285,   285,    29,    33,   142,   147,     0,   300,
     301,   350,   351,   352,   353,   354,   355,   357,   302,     0,
     348,   338,   339,   340,   341,   342,   343,   357,   303,     0,
     334,   140,   144,   136,   134,     0,     0,   132,   388,   280,
     278,   279,   277,     0,   268,   273,   282,     0,   421,   410,
     456,   458,   460,   461,   468,   462,   465,   463,   464,   466,
     459,     0,     0,     0,     0,   407,   449,     0,   446,    93,
     293,     0,     0,   356,     0,   344,     0,     0,   337,     0,
       0,   185,     0,     0,   193,   165,     0,     0,     0,     0,
       0,   176,   177,     0,     0,   183,   188,   187,     0,     0,
     191,   195,   194,   198,   192,     0,   186,     0,     0,     0,
       0,     0,   197,   196,     0,     0,   201,   207,     0,     0,
     203,   204,   202,     0,     0,   214,   215,   216,   217,   218,
       0,     0,     0,     0,     0,     0,   162,   163,   265,   260,
       0,   467,     0,     0,   480,     0,     0,   406,   457,   330,
       0,   336,     0,   347,   349,   345,   333,     0,   139,   135,
       0,     0,   149,     0,   152,     0,   156,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   200,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,   472,     0,   408,     0,   358,   335,     0,   159,     0,
       0,     0,   158,     0,   243,   235,   236,   237,   238,   239,
     240,   241,   242,   246,   244,   247,   248,   249,   250,   245,
     359,   233,   169,   231,   230,   232,   170,   174,   172,   178,
       0,   189,   190,   228,   180,   181,   209,   211,   210,   220,
     223,   182,   229,   208,   205,   206,   213,   212,     0,   221,
     222,   171,   226,   224,   227,   225,   164,     0,   473,   481,
     331,   184,   160,   150,   168,   154,   151,     0,   155,     0,
     234,   166,   360,     0,     0,   326,   313,   325,   328,   324,
       0,     0,     0,   327,   309,   321,   318,   317,   320,   316,
       0,   319,   311,   261,     0,   157,   379,   382,   380,     0,
       0,   381,   361,   362,   373,   378,   175,   173,   314,   315,
     179,     0,     0,     0,   219,     0,   153,     0,   376,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
     372,   310,   323,   322,   312,   377,   364,   363,   366,   367,
     370,   368,   365,     0,     0,     0,   369,     0,   383,     0,
     374,   375,     0,   384
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,     3,   209,   345,     8,    20,    49,    50,
      51,    52,   155,   156,    73,    53,    75,   238,   363,    54,
      77,   239,   364,    32,    42,    70,    71,   147,   148,   149,
      21,    22,    23,    30,    38,    40,    63,   189,   307,   104,
      41,    80,   233,   234,   235,   236,   237,   259,   302,   432,
      34,    57,    58,    82,   119,    60,    97,    98,    99,   161,
     205,   206,   207,   244,   390,   319,   315,   316,   272,   591,
     592,   593,   706,   597,   640,   467,   566,   567,   666,   660,
     661,   101,   134,   135,   136,   215,   474,   274,   258,   249,
     324,   288,   325,   326,   367,   303,   304,   305,   346,   306,
     433,   385,   722,   730,   723,   732,   724,   725,   439,   458,
     508,   582,   459,   460,   586,   448,   449,   583,   450,   503,
     711,   712,   742,   743,   744,   745,   789,   137,   163,   164,
     210,   211,   212,   213,   139,   289,   290,   577,   291,   292,
     293,   294,   295,   296,   171,   180,   172,   181,   253,   254,
     140,   297,   299,   354,   355,   356,   357,   427,   348,   349,
     350,   575
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -664
static const yytype_int16 yypact[] =
{
      35,   -18,   107,    13,  -664,    85,    74,   148,   173,  -664,
     178,   -15,   186,   206,   206,   226,  -664,   223,  -664,   237,
     244,  -664,   235,  -664,   236,  -664,  -664,  -664,   266,  -664,
     274,  -664,   218,   206,   299,  -664,  -664,  -664,   274,   314,
    -664,  -664,   203,   206,   206,  -664,   206,  -664,   206,  -664,
    -664,  -664,  -664,  -664,  -664,   319,   305,    68,  -664,   612,
     335,  -664,   337,   185,   323,   327,   329,  -664,  -664,  -664,
    -664,    -7,  -664,   237,   237,   206,   237,   206,   237,  -664,
    -664,    72,  -664,   206,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,    24,   206,  -664,
     147,  -664,   349,  -664,   348,   339,   361,   364,  -664,   203,
    -664,   218,   218,   237,   218,   237,   215,   355,   210,  -664,
    -664,  -664,  -664,  -664,  -664,   398,   359,   374,   366,   140,
     360,   258,   258,  -664,    99,  -664,   375,  -664,   272,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,   399,   218,  -664,
     400,   394,   405,   407,   206,   -16,  -664,   206,   206,   206,
     206,    26,   417,   398,  -664,  -664,  -664,   419,  -664,  -664,
    -664,   257,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
     396,  -664,   206,  -664,  -664,  -664,  -664,  -664,   206,   488,
    -664,  -664,  -664,  -664,  -664,  -664,   237,  -664,  -664,  -664,
    -664,   413,  -664,  -664,  -664,   193,  -664,  -664,   414,  -664,
       8,  -664,   430,  -664,  -664,   206,   411,   417,  -664,   417,
    -664,   421,   423,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,   247,  -664,  -664,   459,  -664,   488,   488,
     218,   206,    26,  -664,   -12,   422,   417,   447,   453,   428,
     455,   443,  -664,   372,  -664,   372,  -664,  -664,  -664,   152,
    -664,  -664,  -664,   442,   481,   458,  -664,  -664,   448,   206,
     -40,   452,   466,  -664,   487,  -664,  -664,   472,   180,   449,
     447,  -664,   -33,  -664,   206,   -26,   437,   194,   417,  -664,
    -664,  -664,  -664,  -664,  -664,   194,  -664,  -664,   194,   437,
    -664,  -664,   146,   206,   152,  -664,  -664,   319,  -664,  -664,
    -664,    31,   467,   680,   468,  -664,   380,   206,   480,  -664,
     417,   484,   483,   485,    51,   463,  -664,   416,  -664,  -664,
     482,    11,   486,    -6,  -664,  -664,  -664,  -664,  -664,   437,
     437,   437,   437,  -664,   377,   492,  -664,   332,  -664,   494,
    -664,    28,  -664,  -664,   495,   474,  -664,   541,  -664,  -664,
    -664,  -664,  -664,   510,   513,  -664,  -664,   497,   206,  -664,
    -664,  -664,  -664,  -664,  -664,   509,   509,   523,   589,   206,
    -664,  -664,  -664,  -664,  -664,  -664,   497,   506,  -664,     6,
     503,    32,  -664,    49,    81,   456,   180,   180,   511,  -664,
    -664,   524,   437,  -664,  -664,   521,   541,   541,   541,   206,
     437,   437,   437,   437,   437,   437,   437,   437,   437,  -664,
    -664,   -44,   437,   517,  -664,  -664,   194,   437,   437,  -664,
    -664,   437,   152,   152,  -664,  -664,  -664,  -664,   542,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,   520,  -664,   469,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,   520,  -664,   470,
     529,   534,  -664,  -664,  -664,   554,   232,  -664,  -664,  -664,
    -664,  -664,  -664,   439,   423,  -664,  -664,   556,  -664,   541,
    -664,  -664,   659,   659,   541,   541,   541,   541,   541,   541,
     541,   437,   535,   632,     7,   418,   541,   538,  -664,  -664,
    -664,   126,   571,  -664,   523,  -664,   589,   572,  -664,   206,
     576,   580,   206,    86,  -664,  -664,   562,   563,   564,   539,
     540,  -664,  -664,   573,   575,  -664,  -664,  -664,   577,   578,
    -664,  -664,  -664,   197,  -664,   579,  -664,   584,   588,   590,
     591,   592,  -664,  -664,   598,   602,  -664,  -664,   603,   623,
    -664,  -664,  -664,   630,   631,  -664,  -664,  -664,  -664,  -664,
     634,   636,   639,   640,   645,   648,   558,  -664,  -664,  -664,
     566,   541,     7,   437,  -664,   170,   194,  -664,  -664,  -664,
     605,  -664,   568,  -664,  -664,  -664,  -664,   642,  -664,  -664,
     651,   128,  -664,   652,  -664,   206,   660,  -664,   761,   656,
      -3,   206,   206,   661,   646,   663,   664,  -664,  -664,   665,
     666,   671,   -70,   677,   691,   206,   685,   687,   112,   705,
     709,   689,   713,   725,    -3,   104,   176,   232,   730,   217,
     541,  -664,     7,  -664,   710,  -664,  -664,   737,  -664,    70,
      86,   206,   746,   206,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
     693,  -664,  -664,  -664,  -664,  -664,  -664,   747,   758,  -664,
     626,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,   662,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,   745,  -664,  -664,
    -664,  -664,  -664,  -664,  -664,   760,  -664,   206,  -664,   214,
    -664,  -664,  -664,   206,   206,  -664,  -664,  -664,  -664,  -664,
     771,   772,   221,  -664,  -664,   -14,  -664,  -664,  -664,  -664,
     229,  -664,  -664,  -664,   206,  -664,  -664,  -664,  -664,   214,
     214,  -664,  -664,   192,   607,  -664,  -664,  -664,  -664,  -664,
    -664,   626,   626,   626,  -664,   662,  -664,   749,  -664,   214,
     214,    60,    60,    60,    60,    60,   735,    60,   759,  -664,
    -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,    60,   688,    60,  -664,    60,  -664,   233,
    -664,  -664,    60,  -664
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -664,  -664,  -664,  -664,   809,   -13,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,   657,    53,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,  -664,     0,  -664,   -43,  -664,   -74,  -664,   -17,
    -664,  -664,   792,  -664,  -664,   777,  -664,  -664,  -664,  -664,
    -664,   -50,   110,  -664,   -52,  -664,  -664,  -664,  -664,  -664,
    -664,  -664,    -8,  -664,  -664,  -664,  -664,  -664,   719,  -664,
    -664,  -664,  -173,  -664,  -664,  -664,  -183,  -664,  -664,  -664,
     179,  -664,  -664,   177,  -664,  -664,  -664,   195,   199,  -664,
     159,  -664,  -664,   690,  -664,  -664,  -664,  -664,   347,  -664,
    -664,   501,   432,   435,  -664,   401,  -664,   528,   -96,   425,
    -664,  -664,  -664,  -664,  -663,   100,   108,  -396,   489,  -664,
    -664,  -664,  -664,   352,  -664,  -664,  -664,  -664,   356,   404,
    -664,  -664,  -664,  -505,    89,  -664,  -664,  -664,  -664,   699,
     543,   618,   -95,   -80,  -664,  -292,  -664,  -664,  -664,  -664,
    -664,  -664,  -210,  -664,  -664,  -664,   695,   697,   649,   581,
    -664,   239,  -664,   445,  -664,   436,  -259,  -664,  -664,  -664,
    -484,   298
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -475
static const yytype_int16 yytable[] =
{
      26,    27,   124,   353,    25,   138,   353,    84,    17,    18,
     574,   197,     4,   329,   676,    55,     5,   245,    25,   333,
      56,   313,   268,   752,    25,   731,   663,   347,   110,   491,
      72,    72,   243,    72,   464,    72,   336,    25,   150,   138,
     152,   468,   269,   664,    56,   298,   108,   121,   337,    85,
     330,    79,   109,   338,  -111,   429,     1,   400,   365,   353,
      10,    25,    72,   203,    72,   465,   146,   246,   118,   267,
      56,   204,   677,   111,   112,   120,   114,   351,   116,    25,
     405,   406,   407,   408,   185,   123,   492,   133,   574,   736,
     737,   246,   731,   222,   401,    79,   753,    74,    25,    76,
      25,    78,    25,   469,   395,   678,   738,     9,    64,   314,
     281,    25,    13,   151,   665,   153,    25,   125,   117,   282,
     702,   133,   251,   126,   251,    12,    79,    83,   113,    25,
     115,   191,   331,   692,   495,   471,   270,   252,   343,   252,
     595,    72,   334,   479,   199,   200,   201,   202,   699,   133,
     693,   482,   483,   484,   485,   486,   487,   488,   489,   490,
       6,   127,   403,   493,   154,   125,   265,   276,   496,   221,
      86,   126,    65,    19,   358,   133,   232,    25,   638,   579,
      66,   261,    67,    68,   436,   580,    14,   639,   332,   335,
     359,   741,   182,   251,   283,   284,   240,   285,   286,    69,
     328,   287,   248,   462,   133,   694,   133,   196,   252,   127,
      25,   261,   261,    15,   322,    87,    88,    89,    90,    91,
     232,    92,   695,   631,    16,   232,   232,    24,   266,   632,
     203,   271,   571,   133,   757,   758,    25,   404,   204,    93,
      94,   242,    95,   736,   737,    96,   128,   158,   159,   160,
     232,   232,   129,   130,   776,   777,   312,   362,    17,    18,
     738,   131,   132,   223,   224,   323,   739,    28,   511,    29,
     698,   123,   123,   225,   750,   133,   632,    25,    36,   260,
     751,   512,   754,   513,   633,   282,   791,    33,   755,    31,
     360,   226,   792,   227,   128,   168,   169,   170,   366,    39,
     129,   130,   300,   301,   388,   607,   608,   133,    37,   131,
     132,   684,   685,   481,   630,   514,   759,   760,    64,    59,
     123,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     410,   411,   740,    62,   534,   741,    79,   535,   263,   264,
      81,   536,   537,   538,   100,   437,   772,   773,   182,   102,
     283,   284,   103,   285,   286,   228,   461,   287,   105,   229,
     183,   184,   106,   539,   107,   540,   541,   412,   141,   142,
     470,   472,    65,   323,   323,   143,   413,   414,   415,   416,
      66,   144,    67,    68,   157,   154,   123,   230,   231,    43,
      44,    45,    46,    47,    48,   417,   162,   542,   543,    69,
     145,   544,   168,   169,   170,   217,   594,   165,   167,   545,
     166,   546,   182,   187,   188,   193,   190,   192,   547,   548,
     549,   281,   194,   550,   551,   552,   553,   554,   195,   555,
     556,   557,   558,   559,   560,   561,   562,   208,   216,   563,
     241,   564,   565,   -10,   173,   418,   419,   420,   223,   224,
     421,   422,   423,   282,   424,   425,   336,    25,   225,   247,
     250,   257,    25,   256,   308,   262,   273,     4,   337,   277,
     278,   123,   280,   338,   279,   310,   226,   311,   227,   339,
     173,   317,   318,   340,   341,   320,   588,   223,   224,   123,
     596,   321,   327,   426,   223,   224,   368,   225,   387,   389,
     386,    25,   392,   309,   225,   174,   175,   176,    25,   177,
     178,   179,   393,   397,   394,   226,   398,   227,   399,   410,
     411,   402,   226,   431,   227,   409,   182,   434,   283,   284,
     435,   285,   286,   594,  -474,   287,   428,   463,   430,   410,
     411,   174,   175,   176,   219,   177,   178,   179,   313,   123,
     228,   438,   466,   477,   229,   342,   412,   473,   343,   494,
     478,   501,   502,   509,   480,   413,   414,   415,   416,   504,
     506,   507,   642,   510,   568,   570,   412,   572,   667,   668,
     576,   578,   230,   231,   417,   413,   414,   415,   416,   228,
     581,   587,   681,   229,   589,   590,   228,   598,   599,   600,
     229,   344,   601,   602,   417,   761,   762,   627,   603,   123,
     604,   635,   605,   606,   609,   628,   123,   596,   705,   610,
     708,   230,   231,   611,   634,   612,   613,   614,   230,   231,
     410,   411,   715,   615,   418,   419,   420,   616,   617,   421,
     422,   423,   763,   424,   425,   716,   717,   441,   442,   443,
     444,   445,   446,   447,   418,   419,   420,   718,   618,   421,
     422,   423,   719,   424,   425,   619,   620,   412,   726,   621,
     764,   622,   720,   721,   623,   624,   413,   414,   415,   416,
     625,   716,   727,   626,   735,   636,   637,   641,   670,   643,
     746,   747,   662,   728,   412,   417,   679,   669,   729,   671,
     672,   673,   674,   413,   414,   415,   416,   675,   720,   721,
     680,   756,   644,   451,   452,   453,   454,   455,   456,   457,
     765,   682,   417,   683,   686,   766,   767,   768,   687,   769,
     770,   688,   689,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   690,   418,   419,   573,    86,   697,
     421,   422,   423,   700,   424,   425,   701,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   418,   419,   420,   707,   713,   421,   422,   423,
     644,   424,   425,   380,   381,   382,   383,   714,   733,   734,
     748,   749,   775,    87,    88,    89,    90,    91,   783,    92,
       7,   785,   198,   787,    35,    61,   122,   704,   703,   710,
     709,   569,   696,   691,   186,   396,   384,    93,    94,   476,
      95,   475,   361,    96,   500,   645,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     778,   779,   780,   781,   782,   774,   784,   499,   585,   771,
     584,   505,   214,   391,   275,   440,   218,   498,   255,   352,
     629,     0,   786,   497,   788,     0,   790,   220,     0,     0,
       0,   793
};

static const yytype_int16 yycheck[] =
{
      13,    14,    98,   295,    30,   100,   298,    57,    23,    24,
     494,    27,    30,    46,    84,    32,    34,     9,    30,    45,
      33,    61,    34,    37,    30,   688,    29,   286,    71,    73,
      43,    44,   205,    46,    28,    48,    29,    30,   112,   134,
     114,     9,    54,    46,    57,   255,    53,    97,    41,    57,
      83,    27,    59,    46,    30,    27,    21,    46,    27,   351,
      47,    30,    75,    37,    77,    59,   109,    59,    81,   242,
      83,    45,   142,    73,    74,    83,    76,   287,    78,    30,
     339,   340,   341,   342,   134,    98,   130,   100,   572,    29,
      30,    59,   755,   188,    83,    27,   110,    44,    30,    46,
      30,    48,    30,    54,    53,   175,    46,     0,   115,   149,
      59,    30,    38,   113,   117,   115,    30,    18,    46,    91,
      50,   134,   217,    24,   219,    40,    27,    59,    75,    30,
      77,   148,   165,    29,   426,    54,   148,   217,   131,   219,
      54,   154,   168,   402,   157,   158,   159,   160,   632,   162,
      46,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     178,    62,   168,   422,   180,    18,   240,   247,   427,   182,
     146,    24,   179,   188,    28,   188,   189,    30,    50,    53,
     187,   233,   189,   190,   367,    59,    38,    59,   284,   285,
      44,   131,   164,   288,   166,   167,   196,   169,   170,   206,
     280,   173,   215,   386,   217,    29,   219,   154,   288,    62,
      30,   263,   264,    40,    34,   191,   192,   193,   194,   195,
     233,   197,    46,    53,    46,   238,   239,    41,   241,    59,
      37,   244,   491,   246,   739,   740,    30,   333,    45,   215,
     216,    48,   218,    29,    30,   221,   147,    37,    38,    39,
     263,   264,   153,   154,   759,   760,   269,   307,    23,    24,
      46,   162,   163,    16,    17,   278,    52,    41,    36,    46,
      53,   284,   285,    26,    53,   288,    59,    30,    42,    32,
      59,    49,    53,    51,   576,    91,    53,    43,    59,    52,
     303,    44,    59,    46,   147,   155,   156,   157,   311,    25,
     153,   154,   150,   151,   317,   108,   109,   320,    42,   162,
     163,   199,   200,   409,   573,    83,   124,   125,   115,    20,
     333,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       8,     9,   128,    29,   112,   131,    27,   115,   238,   239,
      45,   119,   120,   121,    19,   368,   752,   753,   164,    22,
     166,   167,   177,   169,   170,   118,   379,   173,    45,   122,
     131,   132,    45,   141,    45,   143,   144,    45,    29,    31,
     393,   394,   179,   396,   397,    46,    54,    55,    56,    57,
     187,    30,   189,   190,    39,   180,   409,   150,   151,   181,
     182,   183,   184,   185,   186,    73,     8,   175,   176,   206,
      46,   179,   155,   156,   157,   158,   512,    58,    52,   187,
      46,   189,   164,    48,   152,    31,    27,    27,   196,   197,
     198,    59,    27,   201,   202,   203,   204,   205,    31,   207,
     208,   209,   210,   211,   212,   213,   214,    30,    29,   217,
      37,   219,   220,    39,    94,   123,   124,   125,    16,    17,
     128,   129,   130,    91,   132,   133,    29,    30,    26,    39,
      59,    48,    30,    52,    32,    16,    54,    30,    41,    26,
      52,   494,    39,    46,    29,    27,    44,    39,    46,    52,
      94,    39,    26,    56,    57,     8,   509,    16,    17,   512,
     513,    29,    53,   171,    16,    17,    39,    26,   128,    29,
      42,    30,    28,    32,    26,   155,   156,   157,    30,   159,
     160,   161,    39,    60,    39,    44,   110,    46,    46,     8,
       9,    45,    44,    59,    46,   158,   164,    27,   166,   167,
      27,   169,   170,   639,    52,   173,    52,    41,    53,     8,
       9,   155,   156,   157,   158,   159,   160,   161,    61,   572,
     118,    52,    59,    52,   122,   128,    45,   111,   131,    52,
      46,    29,    52,    39,    53,    54,    55,    56,    57,   110,
     110,    52,   595,    29,   145,    29,    45,    52,   601,   602,
     172,    53,   150,   151,    73,    54,    55,    56,    57,   118,
      29,    29,   615,   122,    28,    25,   118,    45,    45,    45,
     122,   174,    73,    73,    73,     8,     9,    59,    45,   632,
      45,    53,    45,    45,    45,    59,   639,   640,   641,    45,
     643,   150,   151,    45,    29,    45,    45,    45,   150,   151,
       8,     9,    16,    45,   123,   124,   125,    45,    45,   128,
     129,   130,    45,   132,   133,    29,    30,   134,   135,   136,
     137,   138,   139,   140,   123,   124,   125,    41,    45,   128,
     129,   130,    46,   132,   133,    45,    45,    45,    16,    45,
      73,    45,    56,    57,    45,    45,    54,    55,    56,    57,
      45,    29,    30,    45,   707,    53,    45,    45,    52,    39,
     713,   714,    46,    41,    45,    73,    29,    46,    46,    46,
      46,    46,    46,    54,    55,    56,    57,    46,    56,    57,
      29,   734,    29,   134,   135,   136,   137,   138,   139,   140,
     123,    46,    73,    46,    29,   128,   129,   130,    29,   132,
     133,    52,    29,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    29,   123,   124,   125,   146,    29,
     128,   129,   130,    53,   132,   133,    29,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   123,   124,   125,    39,    39,   128,   129,   130,
      29,   132,   133,   113,   114,   115,   116,    39,    53,    39,
      29,    29,    53,   191,   192,   193,   194,   195,    73,   197,
       1,    52,   155,   125,    22,    38,    97,   640,   639,   660,
     127,   474,   627,   624,   134,   324,   146,   215,   216,   397,
     218,   396,   304,   221,   433,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     761,   762,   763,   764,   765,   755,   767,   432,   506,   751,
     504,   457,   163,   320,   246,   376,   171,   431,   219,   288,
     572,    -1,   783,   428,   785,    -1,   787,   180,    -1,    -1,
      -1,   792
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   223,   225,    30,    34,   178,   226,   228,     0,
      47,   224,    40,    38,    38,    40,    46,    23,    24,   188,
     229,   252,   253,   254,    41,    30,   227,   227,    41,    46,
     255,    52,   245,    43,   272,   254,    42,    42,   256,    25,
     257,   262,   246,   181,   182,   183,   184,   185,   186,   230,
     231,   232,   233,   237,   241,   251,   227,   273,   274,    20,
     277,   257,    29,   258,   115,   179,   187,   189,   190,   206,
     247,   248,   227,   236,   236,   238,   236,   242,   236,    27,
     263,    45,   275,    59,   263,   274,   146,   191,   192,   193,
     194,   195,   197,   215,   216,   218,   221,   278,   279,   280,
      19,   303,    22,   177,   261,    45,    45,    45,    53,    59,
     247,   245,   245,   236,   245,   236,   245,    46,   227,   276,
     274,   263,   280,   227,   320,    18,    24,    62,   147,   153,
     154,   162,   163,   227,   304,   305,   306,   349,   354,   356,
     372,    29,    31,    46,    30,    46,   247,   249,   250,   251,
     249,   245,   249,   245,   180,   234,   235,    39,    37,    38,
      39,   281,     8,   350,   351,    58,    46,    52,   155,   156,
     157,   366,   368,    94,   155,   156,   157,   159,   160,   161,
     367,   369,   164,   373,   373,   263,   305,    48,   152,   259,
      27,   251,    27,    31,    27,    31,   236,    27,   235,   227,
     227,   227,   227,    37,    45,   282,   283,   284,    30,   226,
     352,   353,   354,   355,   351,   307,    29,   158,   368,   158,
     369,   227,   354,    16,    17,    26,    44,    46,   118,   122,
     150,   151,   227,   264,   265,   266,   267,   268,   239,   243,
     245,    37,    48,   284,   285,     9,    59,    39,   227,   311,
      59,   354,   355,   370,   371,   370,    52,    48,   310,   269,
      32,   266,    16,   264,   264,   249,   227,   284,    34,    54,
     148,   227,   290,    54,   309,   353,   355,    26,    52,    29,
      39,    59,    91,   166,   167,   169,   170,   173,   313,   357,
     358,   360,   361,   362,   363,   364,   365,   373,   364,   374,
     150,   151,   270,   317,   318,   319,   321,   260,    32,    32,
      27,    39,   227,    61,   149,   288,   289,    39,    26,   287,
       8,    29,    34,   227,   312,   314,   315,    53,   355,    46,
      83,   165,   320,    45,   168,   320,    29,    41,    46,    52,
      56,    57,   128,   131,   174,   227,   320,   378,   380,   381,
     382,   364,   371,   357,   375,   376,   377,   378,    28,    44,
     227,   319,   263,   240,   244,    27,   227,   316,    39,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
     113,   114,   115,   116,   146,   323,    42,   128,   227,    29,
     286,   352,    28,    39,    39,    53,   313,    60,   110,    46,
      46,    83,    45,   168,   320,   378,   378,   378,   378,   158,
       8,     9,    45,    54,    55,    56,    57,    73,   123,   124,
     125,   128,   129,   130,   132,   133,   171,   379,    52,    27,
      53,    59,   271,   322,    27,    27,   288,   227,    52,   330,
     330,   134,   135,   136,   137,   138,   139,   140,   337,   338,
     340,   134,   135,   136,   137,   138,   139,   140,   331,   334,
     335,   227,   288,    41,    28,    59,    59,   297,     9,    54,
     227,    54,   227,   111,   308,   315,   314,    52,    46,   378,
      53,   320,   378,   378,   378,   378,   378,   378,   378,   378,
     378,    73,   130,   378,    52,   357,   378,   375,   377,   321,
     317,    29,    52,   341,   110,   341,   110,    52,   332,    39,
      29,    36,    49,    51,    83,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   112,   115,   119,   120,   121,   141,
     143,   144,   175,   176,   179,   187,   189,   196,   197,   198,
     201,   202,   203,   204,   205,   207,   208,   209,   210,   211,
     212,   213,   214,   217,   219,   220,   298,   299,   145,   310,
      29,   378,    52,   125,   382,   383,   172,   359,    53,    53,
      59,    29,   333,   339,   340,   335,   336,    29,   227,    28,
      25,   291,   292,   293,   320,    54,   227,   295,    45,    45,
      45,    73,    73,    45,    45,    45,    45,   108,   109,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    59,    59,   383,
     378,    53,    59,   357,    29,    53,    53,    45,    50,    59,
     296,    45,   227,    39,    29,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     301,   302,    46,    29,    46,   117,   300,   227,   227,    46,
      52,    46,    46,    46,    46,    46,    84,   142,   175,    29,
      29,   227,    46,    46,   199,   200,    29,    29,    52,    29,
      29,   300,    29,    46,    29,    46,   299,    29,    53,   382,
      53,    29,    50,   292,   295,   227,   294,    39,   227,   127,
     302,   342,   343,    39,    39,    16,    29,    30,    41,    46,
      56,    57,   324,   326,   328,   329,    16,    30,    41,    46,
     325,   326,   327,    53,    39,   227,    29,    30,    46,    52,
     128,   131,   344,   345,   346,   347,   227,   227,    29,    29,
      53,    59,    37,   110,    53,    59,   227,   345,   345,   124,
     125,     8,     9,    45,    73,   123,   128,   129,   130,   132,
     133,   328,   329,   329,   327,    53,   345,   345,   346,   346,
     346,   346,   346,    73,   346,    52,   346,   125,   346,   348,
     346,    53,    59,   346
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
        case 2:

/* Line 1455 of yacc.c  */
#line 151 "screen.yacc"
    {
A4GL_check_compiled_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
A4GL_write_form();}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 158 "screen.yacc"
    {the_form.encoding="";}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 159 "screen.yacc"
    {
		the_form.encoding=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
	}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 165 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");
the_form.allowNullInput=1;
}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 168 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=0;
}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 174 "screen.yacc"
    {the_form.dbname=("formonly");
the_form.allowNullInput=0;
}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 177 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=1;
}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 195 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 196 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 198 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 203 "screen.yacc"
    {
			the_form.layout=NULL;
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 206 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 213 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 223 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_HBOX;
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 232 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 245 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 253 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 263 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 271 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 284 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 290 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 293 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 296 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 297 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 312 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 315 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 318 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 319 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 332 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 335 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 335 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 341 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 344 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 347 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 350 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 353 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_ACTION, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 356 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_BORDER);
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 368 "screen.yacc"
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

  case 47:

/* Line 1455 of yacc.c  */
#line 377 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 383 "screen.yacc"
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

  case 49:

/* Line 1455 of yacc.c  */
#line 393 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 401 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 403 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 405 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 407 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 409 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 411 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 417 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(3) - (4)].layout);
	}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 428 "screen.yacc"
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

  case 61:

/* Line 1455 of yacc.c  */
#line 441 "screen.yacc"
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

  case 63:

/* Line 1455 of yacc.c  */
#line 460 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 462 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 465 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 470 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 477 "screen.yacc"
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

  case 76:

/* Line 1455 of yacc.c  */
#line 499 "screen.yacc"
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

  case 77:

/* Line 1455 of yacc.c  */
#line 514 "screen.yacc"
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

  case 78:

/* Line 1455 of yacc.c  */
#line 526 "screen.yacc"
    { ltab=0; }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 527 "screen.yacc"
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

  case 80:

/* Line 1455 of yacc.c  */
#line 538 "screen.yacc"
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

  case 81:

/* Line 1455 of yacc.c  */
#line 549 "screen.yacc"
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

  case 82:

/* Line 1455 of yacc.c  */
#line 562 "screen.yacc"
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

  case 83:

/* Line 1455 of yacc.c  */
#line 574 "screen.yacc"
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

  case 84:

/* Line 1455 of yacc.c  */
#line 585 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 590 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 593 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 601 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 602 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 608 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 615 "screen.yacc"
    {
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field((yyvsp[(3) - (4)].str),fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field((yyvsp[(3) - (4)].str),fstart+1,lineno,colno-fstart-1,scr,2,"");

       fstart=-1;

}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 632 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 635 "screen.yacc"
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

  case 93:

/* Line 1455 of yacc.c  */
#line 646 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 662 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 671 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 672 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 675 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 676 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 678 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 679 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 680 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 696 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 697 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 698 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 699 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 700 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 701 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 702 "screen.yacc"
    {strcpy((yyval.str),"Button");}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 703 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 704 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 705 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 706 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 707 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 712 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 718 "screen.yacc"
    {
			if (strcmp((yyvsp[(1) - (5)].str),"Edit")!=0) {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

				if (A4GL_has_str_attribute(fld,FA_S_WIDGET)) {
					yyerror("Field already has a widget");
				} else {
					A4GL_add_str_attr(fld,FA_S_WIDGETTYPE,(yyvsp[(1) - (5)].str));
				}
			}
			if (the_form.allowNullInput==0) {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
				if (!A4GL_has_bool_attribute(fld,FA_B_NOTNULL)) {
					A4GL_add_bool_attr(fld,FA_B_NOTNULL);
				}
			}
		}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 748 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 752 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 762 "screen.yacc"
    {
	int cnt;
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	if (A4GL_has_str_attribute(fld,FA_S_FORMAT)) {
		int dtype;
		dtype=fld->datatype & DTYPE_MASK;

		if (dtype!=DTYPE_INT  &&
		    dtype!=DTYPE_SMINT  &&
		    dtype!=DTYPE_SERIAL  &&
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

		switch (att_color[0]) {
			/*
			0: WHITE/ NORMAL
			1: YELLOW/BOLD
			2: MAGENTA/BOLD
			3: RED/BOLD
			4: CYAN/DIM
			5: GREEN/DIM
			6: BLUE/DIM
			7: BLACK/DIM
			*/
			case '0': attr+=7; break;
			case '1': attr+=3; break;
			case '2': attr+=5; break;
			case '3': attr+=1; break;
			case '4': attr+=6; break;
			case '5': attr+=2; break;
			case '6': attr+=4; break;
			case '7': attr+=0; break;
		}
				
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
				fprintf(stderr, "Conditions in upscol are not handled yet (%s)\n",att_condition);
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
			// Theres a picture in syscolval - but nothing in the form - use the syscolval one...
			A4GL_add_str_attr(fld,FA_S_PICTURE,p);
		}
	}

		// COMMENTS
		// DEFAULT
		// PICTURE

		// INCLUDE

		// AUTONEXT
		// SHIFT
		// VERIFY


	if (strcmp(the_form.dbname,"formonly")!=0 ) {
		// String ...
		if (!(A4GL_has_str_attribute(fld,FA_S_PICTURE))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"PICTURE");
			if (p) {
				// Theres a picture in syscolval - but nothing in the form - use the syscolval one...
				A4GL_add_str_attr(fld,FA_S_PICTURE,p);
			}
		}

		if (!(A4GL_has_str_attribute(fld,FA_S_COMMENTS))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"COMMENTS");
			if (p) {
				A4GL_add_str_attr(fld,FA_S_COMMENTS,p);
			}
		}

		if (!(A4GL_has_str_attribute(fld,FA_S_DEFAULT))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"DEFAULT");
			if (p) {
				A4GL_add_str_attr(fld,FA_S_DEFAULT,p);
			}
		}

		if (!(A4GL_has_str_attribute(fld,FA_S_INCLUDE))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"INCLUDE");
			if (p) {
				p=process_include(p);
				A4GL_add_str_attr(fld,FA_S_INCLUDE,p);
			}
		}

	

		// Booleans...
		if (!(A4GL_has_bool_attribute(fld,FA_B_AUTONEXT))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"AUTONEXT");
			if (p) {
				// Theres a picture in syscolval - but nothing in the form - use the syscolval one...
				A4GL_add_bool_attr(fld,FA_B_AUTONEXT);
			}
		}

		if (!(A4GL_has_bool_attribute(fld,FA_B_VERIFY))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"VERIFY");
			if (p) {
				// Theres a picture in syscolval - but nothing in the form - use the syscolval one...
				A4GL_add_bool_attr(fld,FA_B_VERIFY);
			}
		}

		if (!A4GL_has_bool_attribute(fld,FA_B_UPSHIFT)  &&! A4GL_has_bool_attribute(fld,FA_B_DOWNSHIFT)) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"SHIFT");
			if (p) {
				if (strcmp(p,"UP")==0) {
					A4GL_add_bool_attr(fld,FA_B_UPSHIFT);
				}
				if (strcmp(p,"DOWN")==0) {
					A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT);
				}
			}
		}

	}






	a4gl_status=0;
	A4GL_set_field(currftag,fld);
	if (a4gl_status!=0) {
		yyerror(A4GL_get_fcompile_err());
	}


	if ((fld->datatype&256)==256) {
			fld->datatype-=256;
			if (!A4GL_has_bool_attribute(fld,FA_B_NOTNULL)) {
					A4GL_add_bool_attr(fld,FA_B_NOTNULL);
				}
			
			if (!A4GL_has_bool_attribute(fld,FA_B_REQUIRED)) {
				switch (fld->datatype&DTYPE_MASK) {
					case DTYPE_CHAR:
					case DTYPE_NCHAR:
					case DTYPE_VCHAR:
					case DTYPE_NVCHAR:
						break;
					// Characters can be spaces - everything else would have to be null
					// but nulls are not allowed - so it must be 'required' as well
					default : 
						if (!A4GL_has_bool_attribute(fld,FA_B_NOENTRY)) {
							// Forcing 'REQUIRED' on a 'NOENTRY' is just dumb...
							A4GL_add_bool_attr(fld,FA_B_REQUIRED);
						}
						break;
				}
			}
	}
}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1073 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1079 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1089 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1090 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1093 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1094 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1097 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1100 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1105 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup((yyvsp[(3) - (4)].str));
        fld->datatype=atoi((yyvsp[(4) - (4)].str))&0xff;
	if (atoi((yyvsp[(4) - (4)].str))&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi((yyvsp[(4) - (4)].str))&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1116 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
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

  case 144:

/* Line 1455 of yacc.c  */
#line 1130 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
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

  case 145:

/* Line 1455 of yacc.c  */
#line 1144 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1153 "screen.yacc"
    {
	struct struct_scr_field *fld;
	fld=A4GL_get_fld();
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
        fld->datatype=DTYPE_CHAR ;
        fld->dtype_size=0;
}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1162 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1171 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1186 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1195 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1204 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1213 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1216 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1222 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1223 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1224 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1225 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1241 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1246 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
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

  case 167:

/* Line 1455 of yacc.c  */
#line 1268 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
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

  case 168:

/* Line 1455 of yacc.c  */
#line 1292 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1300 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1301 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1302 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1303 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1304 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1305 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1306 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1307 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1308 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1309 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1310 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1311 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1312 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1313 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1314 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1315 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1316 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1317 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1319 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1321 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1322 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1323 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1324 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1325 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1326 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1327 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1328 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1329 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1330 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1331 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1332 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1336 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1343 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1344 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1345 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1346 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1347 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1348 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1349 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1350 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1351 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"LEFT"); }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1352 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"RIGHT"); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1353 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"CENTER"); }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1354 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1355 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1356 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1357 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1358 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1359 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1360 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1361 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1362 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,(yyvsp[(3) - (3)].str)); }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1363 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1364 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1365 "screen.yacc"
    { A4GL_get_fld()->not_null=1;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1367 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1368 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1369 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1370 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1371 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1372 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1378 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1379 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1380 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1385 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1389 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1390 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1391 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1392 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1393 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1394 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1395 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1396 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1398 "screen.yacc"
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

		/* Translate from Informix colour codes to Aubit ones...*/
		switch (*ptr) {
			/*
			0: WHITE/ NORMAL
			1: YELLOW/BOLD
			2: MAGENTA/BOLD
			3: RED/BOLD
			4: CYAN/DIM
			5: GREEN/DIM
			6: BLUE/DIM
			7: BLACK/DIM
			*/
			case '0': strcpy((yyval.str),"7"); break;
			case '1': strcpy((yyval.str),"3"); break;
			case '2': strcpy((yyval.str),"5"); break;
			case '3': strcpy((yyval.str),"1"); break;
			case '4': strcpy((yyval.str),"6"); break;
			case '5': strcpy((yyval.str),"2"); break;
			case '6': strcpy((yyval.str),"4"); break;
			case '7': strcpy((yyval.str),"0"); break;
		}
		}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1433 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1434 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1435 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1436 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1437 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1438 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1439 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1452 "screen.yacc"
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

  case 258:

/* Line 1455 of yacc.c  */
#line 1462 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1468 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1479 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1479 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1484 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1487 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1493 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1496 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1506 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1510 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1514 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1518 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1522 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1528 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1532 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1535 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1539 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1539 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1546 "screen.yacc"
    {colno++;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1547 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1560 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1568 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1570 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1577 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1581 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1585 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1589 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1593 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1597 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1601 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1607 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1611 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1615 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1619 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1623 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1627 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1631 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1634 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1641 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1645 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1650 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1654 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1661 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1662 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1664 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1672 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1675 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1681 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1688 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1689 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1690 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1691 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1697 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1700 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1701 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1704 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1706 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1712 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1714 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1719 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1727 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1730 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1731 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1732 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1733 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1734 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1735 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1737 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1744 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1745 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1748 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1751 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1755 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1756 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1757 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1758 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1759 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1760 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1762 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1767 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1769 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1776 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1776 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1782 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1789 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1792 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1798 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1799 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1800 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1801 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1802 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1803 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1804 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1805 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1806 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1807 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1808 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1809 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1810 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1813 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1820 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1821 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1822 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1830 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1834 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1854 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1864 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1871 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1880 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1883 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1902 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1909 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1917 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1922 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1930 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1934 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1939 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1944 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1949 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1954 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1959 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1968 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1977 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1978 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1987 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1995 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2001 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2007 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2013 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2021 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2026 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2036 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2046 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2052 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2058 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2064 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2074 "screen.yacc"
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

  case 423:

/* Line 1455 of yacc.c  */
#line 2086 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2094 "screen.yacc"
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

  case 425:

/* Line 1455 of yacc.c  */
#line 2106 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2114 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2115 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2116 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2120 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2121 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2122 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2123 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2124 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2125 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2126 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2129 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2136 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2147 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2151 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2158 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2166 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2172 "screen.yacc"
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

  case 443:

/* Line 1455 of yacc.c  */
#line 2184 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2185 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2191 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2197 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2205 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2213 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str));}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2218 "screen.yacc"
    {strcpy((yyval.str),"AND");}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2219 "screen.yacc"
    {strcpy((yyval.str),"OR");}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2235 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2237 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2238 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2239 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2240 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2241 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2244 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2245 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2246 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2247 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2248 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2249 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2250 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2251 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2252 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2253 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2254 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2255 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2256 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2257 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2258 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2259 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2265 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2266 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2267 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2268 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2269 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2272 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2276 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1455 of yacc.c  */
#line 6758 "y.tab.c"
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
#line 2288 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




