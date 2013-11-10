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
int tagCaseInsensitive=1;
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
#line 159 "y.tab.c"

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
     NAMED_CASE_SPECIFIC = 289,
     FORMONLY = 290,
     COMMENT = 291,
     DYNAMIC = 292,
     COLON = 293,
     ATSIGN = 294,
     DOT = 295,
     WITHOUT = 296,
     KW_NULL = 297,
     INPUT = 298,
     TABLES = 299,
     PIPE = 300,
     EQUAL = 301,
     CHAR_VALUE = 302,
     CHARACTER_ENCODING = 303,
     SEMICOLON = 304,
     LOOKUP = 305,
     JOINING = 306,
     LOOKUP_FROM = 307,
     OPEN_BRACKET = 308,
     CLOSE_BRACKET = 309,
     STAR = 310,
     DIVIDE = 311,
     PLUS = 312,
     MINUS = 313,
     RECORD = 314,
     COMMA = 315,
     THROUGH = 316,
     TYPE = 317,
     DELIMITERS = 318,
     KW_CHAR = 319,
     KW_INT = 320,
     KW_DATE = 321,
     KW_FLOAT = 322,
     SMALLFLOAT = 323,
     SMALLINT = 324,
     KW_DECIMAL = 325,
     MONEY = 326,
     DATETIME = 327,
     INTERVAL = 328,
     LIKE = 329,
     BLACK = 330,
     BLUE = 331,
     GREEN = 332,
     CYAN = 333,
     RED = 334,
     MAGENTA = 335,
     WHITE = 336,
     YELLOW = 337,
     NORMAL = 338,
     REVERSE = 339,
     LEFT = 340,
     BOLD = 341,
     BLINK = 342,
     UNDERLINE = 343,
     DIM = 344,
     AUTONEXT = 345,
     COLOR = 346,
     COMMENTS = 347,
     DEFAULT = 348,
     VALIDATE = 349,
     DISPLAY = 350,
     DOWNSHIFT = 351,
     UPSHIFT = 352,
     FORMAT = 353,
     INCLUDE = 354,
     INVISIBLE = 355,
     NOUPDATE = 356,
     NOENTRY = 357,
     PICTURE = 358,
     PROGRAM = 359,
     REQUIRED = 360,
     QUERYCLEAR = 361,
     VERIFY = 362,
     WORDWRAP = 363,
     COMPRESS = 364,
     NONCOMPRESS = 365,
     TO = 366,
     AS = 367,
     UNHIDABLE = 368,
     SERIAL = 369,
     KW_BYTE = 370,
     KW_TEXT = 371,
     VARCHAR = 372,
     SQL_VAR = 373,
     KW_NONSPACE = 374,
     KW_HEADER = 375,
     SQLONLY = 376,
     WIDGET = 377,
     CONFIG = 378,
     KW_NL = 379,
     COMPARISON = 380,
     KWOR = 381,
     KWAND = 382,
     KWAND1 = 383,
     KWWHERE = 384,
     KWNOT = 385,
     KWBETWEEN = 386,
     KWIN = 387,
     XVAL = 388,
     KWNULLCHK = 389,
     KWNOTNULLCHK = 390,
     YEAR = 391,
     MONTH = 392,
     DAY = 393,
     HOUR = 394,
     MINUTE = 395,
     SECOND = 396,
     FRACTION = 397,
     KW_JUSTIFY = 398,
     KW_CENTER = 399,
     KW_TABINDEX = 400,
     KW_NOT_NULL = 401,
     LISTBOX = 402,
     BUTTON = 403,
     KW_PANEL = 404,
     DISPLAYONLY = 405,
     ALLOWING = 406,
     KW_WS = 407,
     KW_TAB = 408,
     KW_MASTER_OF = 409,
     KW_BEFORE = 410,
     KW_AFTER = 411,
     KW_EDITADD = 412,
     KW_EDITUPDATE = 413,
     KW_REMOVE = 414,
     KW_OF = 415,
     KW_ADD = 416,
     KW_UPDATE = 417,
     KW_QUERY = 418,
     KW_ON_ENDING = 419,
     KW_ON_BEGINNING = 420,
     KW_CALL = 421,
     KW_BELL = 422,
     KW_ABORT = 423,
     KW_LET = 424,
     KW_EXITNOW = 425,
     KW_NEXTFIELD = 426,
     KW_IF = 427,
     KW_THEN = 428,
     KW_ELSE = 429,
     KW_BEGIN = 430,
     KW_TOTAL = 431,
     KW_RIGHT = 432,
     KW_ZEROFILL = 433,
     KW_USES_EXTENDED = 434,
     SPECIAL_DBNAME = 435,
     KW_ACTION = 436,
     KW_PAGE = 437,
     KW_HBOX = 438,
     KW_VBOX = 439,
     KW_GRID = 440,
     KW_GROUP = 441,
     KW_TABLE = 442,
     KW_FOLDER = 443,
     KW_STYLE = 444,
     KW_LAYOUT = 445,
     KW_HIDDEN = 446,
     KW_AUTOSIZE = 447,
     KW_TEXTEDIT = 448,
     KW_BUTTONEDIT = 449,
     KW_LABEL = 450,
     KW_EDIT = 451,
     KW_DATEEDIT = 452,
     KW_SCROLL = 453,
     KW_IMAGE = 454,
     KW_FONTPITCH = 455,
     KW_FIXED = 456,
     KW_VARIABLE = 457,
     KW_WANTNORETURNS = 458,
     KW_WANTTABS = 459,
     KW_AUTOSCALE = 460,
     KW_PIXELWIDTH = 461,
     KW_PIXELHEIGHT = 462,
     KW_BORDER = 463,
     KW_SCROLLBARS_BOTH = 464,
     KW_SCROLLBARS_V = 465,
     KW_SCROLLBARS_H = 466,
     KW_STRETCH_Y = 467,
     KW_STRETCH_BOTH = 468,
     KW_ITEMS = 469,
     KW_VALUEMAX = 470,
     KW_VALUEMIN = 471,
     KW_PROGRESSBAR = 472,
     KW_COMBOBOX = 473,
     OPTIONS = 474,
     KW_BROWSER = 475,
     KW_VALUECHECKED = 476,
     KW_VALUEUNCHECKED = 477,
     KW_CHECKBOX = 478
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
#define NAMED_CASE_SPECIFIC 289
#define FORMONLY 290
#define COMMENT 291
#define DYNAMIC 292
#define COLON 293
#define ATSIGN 294
#define DOT 295
#define WITHOUT 296
#define KW_NULL 297
#define INPUT 298
#define TABLES 299
#define PIPE 300
#define EQUAL 301
#define CHAR_VALUE 302
#define CHARACTER_ENCODING 303
#define SEMICOLON 304
#define LOOKUP 305
#define JOINING 306
#define LOOKUP_FROM 307
#define OPEN_BRACKET 308
#define CLOSE_BRACKET 309
#define STAR 310
#define DIVIDE 311
#define PLUS 312
#define MINUS 313
#define RECORD 314
#define COMMA 315
#define THROUGH 316
#define TYPE 317
#define DELIMITERS 318
#define KW_CHAR 319
#define KW_INT 320
#define KW_DATE 321
#define KW_FLOAT 322
#define SMALLFLOAT 323
#define SMALLINT 324
#define KW_DECIMAL 325
#define MONEY 326
#define DATETIME 327
#define INTERVAL 328
#define LIKE 329
#define BLACK 330
#define BLUE 331
#define GREEN 332
#define CYAN 333
#define RED 334
#define MAGENTA 335
#define WHITE 336
#define YELLOW 337
#define NORMAL 338
#define REVERSE 339
#define LEFT 340
#define BOLD 341
#define BLINK 342
#define UNDERLINE 343
#define DIM 344
#define AUTONEXT 345
#define COLOR 346
#define COMMENTS 347
#define DEFAULT 348
#define VALIDATE 349
#define DISPLAY 350
#define DOWNSHIFT 351
#define UPSHIFT 352
#define FORMAT 353
#define INCLUDE 354
#define INVISIBLE 355
#define NOUPDATE 356
#define NOENTRY 357
#define PICTURE 358
#define PROGRAM 359
#define REQUIRED 360
#define QUERYCLEAR 361
#define VERIFY 362
#define WORDWRAP 363
#define COMPRESS 364
#define NONCOMPRESS 365
#define TO 366
#define AS 367
#define UNHIDABLE 368
#define SERIAL 369
#define KW_BYTE 370
#define KW_TEXT 371
#define VARCHAR 372
#define SQL_VAR 373
#define KW_NONSPACE 374
#define KW_HEADER 375
#define SQLONLY 376
#define WIDGET 377
#define CONFIG 378
#define KW_NL 379
#define COMPARISON 380
#define KWOR 381
#define KWAND 382
#define KWAND1 383
#define KWWHERE 384
#define KWNOT 385
#define KWBETWEEN 386
#define KWIN 387
#define XVAL 388
#define KWNULLCHK 389
#define KWNOTNULLCHK 390
#define YEAR 391
#define MONTH 392
#define DAY 393
#define HOUR 394
#define MINUTE 395
#define SECOND 396
#define FRACTION 397
#define KW_JUSTIFY 398
#define KW_CENTER 399
#define KW_TABINDEX 400
#define KW_NOT_NULL 401
#define LISTBOX 402
#define BUTTON 403
#define KW_PANEL 404
#define DISPLAYONLY 405
#define ALLOWING 406
#define KW_WS 407
#define KW_TAB 408
#define KW_MASTER_OF 409
#define KW_BEFORE 410
#define KW_AFTER 411
#define KW_EDITADD 412
#define KW_EDITUPDATE 413
#define KW_REMOVE 414
#define KW_OF 415
#define KW_ADD 416
#define KW_UPDATE 417
#define KW_QUERY 418
#define KW_ON_ENDING 419
#define KW_ON_BEGINNING 420
#define KW_CALL 421
#define KW_BELL 422
#define KW_ABORT 423
#define KW_LET 424
#define KW_EXITNOW 425
#define KW_NEXTFIELD 426
#define KW_IF 427
#define KW_THEN 428
#define KW_ELSE 429
#define KW_BEGIN 430
#define KW_TOTAL 431
#define KW_RIGHT 432
#define KW_ZEROFILL 433
#define KW_USES_EXTENDED 434
#define SPECIAL_DBNAME 435
#define KW_ACTION 436
#define KW_PAGE 437
#define KW_HBOX 438
#define KW_VBOX 439
#define KW_GRID 440
#define KW_GROUP 441
#define KW_TABLE 442
#define KW_FOLDER 443
#define KW_STYLE 444
#define KW_LAYOUT 445
#define KW_HIDDEN 446
#define KW_AUTOSIZE 447
#define KW_TEXTEDIT 448
#define KW_BUTTONEDIT 449
#define KW_LABEL 450
#define KW_EDIT 451
#define KW_DATEEDIT 452
#define KW_SCROLL 453
#define KW_IMAGE 454
#define KW_FONTPITCH 455
#define KW_FIXED 456
#define KW_VARIABLE 457
#define KW_WANTNORETURNS 458
#define KW_WANTTABS 459
#define KW_AUTOSCALE 460
#define KW_PIXELWIDTH 461
#define KW_PIXELHEIGHT 462
#define KW_BORDER 463
#define KW_SCROLLBARS_BOTH 464
#define KW_SCROLLBARS_V 465
#define KW_SCROLLBARS_H 466
#define KW_STRETCH_Y 467
#define KW_STRETCH_BOTH 468
#define KW_ITEMS 469
#define KW_VALUEMAX 470
#define KW_VALUEMIN 471
#define KW_PROGRESSBAR 472
#define KW_COMBOBOX 473
#define OPTIONS 474
#define KW_BROWSER 475
#define KW_VALUECHECKED 476
#define KW_VALUEUNCHECKED 477
#define KW_CHECKBOX 478




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
#line 665 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 677 "y.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   898

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  224
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  165
/* YYNRULES -- Number of rules.  */
#define YYNRULES  493
/* YYNRULES -- Number of states.  */
#define YYNSTATES  815

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   478

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
     215,   216,   217,   218,   219,   220,   221,   222,   223
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    11,    14,    17,    23,    29,    32,
      34,    36,    38,    40,    42,    44,    46,    50,    52,    56,
      58,    60,    66,    72,    78,    84,    86,    89,    95,    96,
      98,    99,   100,   101,   112,   113,   114,   115,   126,   127,
     128,   133,   137,   139,   141,   145,   149,   151,   155,   159,
     161,   164,   168,   169,   171,   173,   176,   178,   180,   182,
     184,   186,   188,   189,   195,   197,   200,   201,   205,   206,
     211,   212,   213,   214,   224,   225,   227,   228,   231,   236,
     237,   239,   241,   244,   246,   248,   250,   252,   254,   256,
     258,   260,   262,   264,   266,   268,   271,   272,   277,   279,
     280,   285,   286,   290,   292,   295,   299,   302,   303,   306,
     308,   312,   316,   322,   326,   330,   334,   336,   339,   340,
     342,   344,   346,   348,   350,   352,   354,   356,   358,   360,
     362,   363,   369,   371,   374,   378,   380,   382,   383,   384,
     391,   392,   396,   402,   406,   408,   409,   415,   419,   422,
     427,   430,   435,   439,   441,   446,   449,   450,   452,   454,
     458,   462,   464,   468,   470,   474,   476,   481,   484,   486,
     489,   490,   493,   495,   499,   501,   506,   509,   514,   518,
     522,   526,   530,   536,   540,   546,   548,   550,   554,   560,
     564,   568,   572,   574,   579,   581,   583,   585,   587,   591,
     595,   597,   599,   601,   603,   605,   607,   609,   611,   614,
     617,   619,   621,   623,   625,   629,   633,   635,   639,   643,
     647,   651,   655,   659,   661,   663,   665,   667,   669,   675,
     679,   683,   687,   689,   693,   697,   701,   705,   709,   713,
     717,   719,   721,   723,   725,   727,   730,   732,   734,   736,
     738,   740,   742,   744,   746,   748,   750,   752,   754,   756,
     758,   760,   762,   763,   767,   769,   772,   774,   777,   780,
     782,   783,   793,   806,   808,   810,   811,   814,   815,   817,
     818,   820,   822,   827,   829,   833,   834,   836,   838,   842,
     846,   850,   854,   856,   860,   862,   864,   865,   867,   869,
     872,   874,   876,   878,   879,   884,   886,   891,   893,   895,
     897,   899,   901,   904,   907,   910,   913,   915,   917,   919,
     921,   923,   925,   929,   931,   935,   937,   940,   943,   945,
     947,   949,   951,   953,   955,   959,   963,   965,   967,   969,
     971,   973,   974,   978,   984,   985,   989,   990,   994,   996,
     999,  1001,  1003,  1005,  1007,  1009,  1011,  1014,  1016,  1017,
    1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1040,
    1041,  1045,  1046,  1048,  1051,  1053,  1057,  1061,  1065,  1069,
    1073,  1077,  1082,  1086,  1089,  1092,  1094,  1100,  1106,  1109,
    1113,  1115,  1117,  1119,  1121,  1123,  1125,  1129,  1132,  1134,
    1137,  1145,  1147,  1151,  1155,  1157,  1159,  1161,  1167,  1173,
    1176,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1199,
    1200,  1203,  1205,  1210,  1213,  1217,  1220,  1224,  1228,  1230,
    1233,  1236,  1240,  1244,  1249,  1251,  1254,  1256,  1259,  1261,
    1263,  1265,  1267,  1269,  1271,  1273,  1275,  1277,  1279,  1281,
    1285,  1289,  1291,  1296,  1297,  1304,  1305,  1307,  1309,  1313,
    1315,  1317,  1321,  1323,  1325,  1328,  1331,  1333,  1336,  1340,
    1345,  1349,  1353,  1357,  1361,  1365,  1369,  1373,  1377,  1381,
    1386,  1390,  1393,  1396,  1402,  1408,  1415,  1417,  1419,  1421,
    1423,  1425,  1427,  1429
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     225,     0,    -1,   227,   226,   232,   276,   281,   308,    -1,
      -1,    48,    47,    -1,    21,    35,    -1,    21,   231,    41,
      42,    43,    -1,    21,    35,    41,    42,    43,    -1,    21,
     231,    -1,    30,    -1,    34,    -1,    30,    -1,    34,    -1,
      30,    -1,    34,    -1,   180,    -1,   180,    39,   229,    -1,
     228,    -1,   228,    39,   229,    -1,   257,    -1,   255,    -1,
     184,   239,   248,   252,    27,    -1,   183,   239,   248,   252,
      27,    -1,   186,   239,   248,   252,    27,    -1,   188,   239,
     248,   237,    27,    -1,   238,    -1,   237,   238,    -1,   182,
     239,   248,   252,    27,    -1,    -1,   229,    -1,    -1,    -1,
      -1,   185,   241,   239,   248,    31,   242,   268,    32,   243,
      27,    -1,    -1,    -1,    -1,   187,   245,   239,   248,    31,
     246,   268,    32,   247,    27,    -1,    -1,    -1,    53,   249,
     251,    54,    -1,   189,    46,    47,    -1,   191,    -1,   192,
      -1,   116,    46,    47,    -1,   181,    46,    30,    -1,   208,
      -1,   207,    46,    29,    -1,   206,    46,    29,    -1,   250,
      -1,   251,   250,    -1,   251,    60,   250,    -1,    -1,   253,
      -1,   254,    -1,   253,   254,    -1,   233,    -1,   234,    -1,
     235,    -1,   236,    -1,   240,    -1,   244,    -1,    -1,   190,
     248,   256,   254,   267,    -1,   258,    -1,   257,   258,    -1,
      -1,    24,   259,   261,    -1,    -1,    23,    47,   260,   261,
      -1,    -1,    -1,    -1,   266,   262,   265,    31,   263,   268,
      32,   264,   267,    -1,    -1,   179,    -1,    -1,    25,    29,
      -1,    25,    29,    22,    29,    -1,    -1,    27,    -1,   270,
      -1,   268,   270,    -1,    30,    -1,   269,    -1,   272,    -1,
     153,    -1,    17,    -1,    45,    -1,    47,    -1,   271,    -1,
     152,    -1,   124,    -1,   119,    -1,    16,    -1,   271,    16,
      -1,    -1,    26,   273,   274,    28,    -1,   326,    -1,    -1,
     274,    45,   275,   326,    -1,    -1,    44,   277,   267,    -1,
     278,    -1,   277,   278,    -1,   277,    60,   278,    -1,   229,
     279,    -1,    -1,    46,   280,    -1,   229,    -1,   229,    38,
     229,    -1,   229,    39,   229,    -1,   229,    39,   229,    38,
     229,    -1,   229,    40,   229,    -1,    47,    40,   229,    -1,
      20,   282,   267,    -1,   284,    -1,   282,   284,    -1,    -1,
     196,    -1,   193,    -1,   195,    -1,   197,    -1,   194,    -1,
     148,    -1,   199,    -1,   217,    -1,   218,    -1,   223,    -1,
     220,    -1,    -1,   283,   325,   285,   286,    49,    -1,   288,
      -1,   286,   288,    -1,   286,    49,   288,    -1,    46,    -1,
      38,    -1,    -1,    -1,   287,   289,   294,   291,   290,   302,
      -1,    -1,    26,    29,    28,    -1,    26,    29,    60,    29,
      28,    -1,   293,   130,    42,    -1,   293,    -1,    -1,    62,
      74,   229,    40,   229,    -1,    62,    74,   229,    -1,    62,
     328,    -1,    35,    40,   321,   292,    -1,   150,   292,    -1,
     150,   151,    43,   292,    -1,   229,    40,   229,    -1,   229,
      -1,    55,   229,    40,   229,    -1,    55,   229,    -1,    -1,
     296,    -1,   297,    -1,   296,    60,   297,    -1,   298,    46,
     299,    -1,   325,    -1,   229,    40,   229,    -1,   229,    -1,
     229,    40,   229,    -1,   229,    -1,    55,   229,    40,   229,
      -1,    55,   229,    -1,    51,    -1,    60,    51,    -1,    -1,
      60,   303,    -1,   304,    -1,   303,    60,   304,    -1,    90,
      -1,    91,    46,   306,   347,    -1,    52,   300,    -1,    50,
     295,   301,   300,    -1,    92,    46,    47,    -1,    93,    46,
     305,    -1,   219,    46,   305,    -1,    95,    74,   229,    -1,
      95,    74,   229,    40,   229,    -1,    94,    74,   229,    -1,
      94,    74,   229,    40,   229,    -1,    96,    -1,    97,    -1,
      98,    46,    47,    -1,    99,    46,    53,   329,    54,    -1,
     122,    46,    47,    -1,   123,    46,    47,    -1,   181,    46,
     229,    -1,   100,    -1,    37,    25,    46,    29,    -1,    37,
      -1,   121,    -1,   102,    -1,   101,    -1,   103,    46,    47,
      -1,   104,    46,    47,    -1,   105,    -1,   113,    -1,    84,
      -1,   107,    -1,   106,    -1,   178,    -1,   177,    -1,   108,
      -1,   108,   109,    -1,   108,   110,    -1,   191,    -1,   205,
      -1,   203,    -1,   204,    -1,   200,    46,   201,    -1,   200,
      46,   202,    -1,   198,    -1,   199,    46,    47,    -1,   143,
      46,    85,    -1,   143,    46,   177,    -1,   143,    46,   144,
      -1,   207,    46,    29,    -1,   206,    46,    29,    -1,   209,
      -1,   210,    -1,   211,    -1,   212,    -1,   213,    -1,   214,
      46,    53,   330,    54,    -1,   145,    46,    29,    -1,   215,
      46,    29,    -1,   216,    46,    29,    -1,   146,    -1,   221,
      46,    47,    -1,   222,    46,    47,    -1,   221,    46,    29,
      -1,   222,    46,    29,    -1,   116,    46,    47,    -1,   120,
      46,    47,    -1,   189,    46,    47,    -1,    47,    -1,    29,
      -1,    30,    -1,   118,    -1,   307,    -1,   306,   307,    -1,
      75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    81,    -1,    82,    -1,    29,    -1,    84,    -1,
      89,    -1,    83,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    -1,    19,   309,   267,    -1,   310,    -1,   309,
     310,    -1,   311,    -1,   311,    49,    -1,    63,    47,    -1,
     361,    -1,    -1,    24,    59,   312,   316,    53,   317,    54,
     313,   315,    -1,   149,    53,    29,    60,    29,    54,   111,
      53,    29,    60,    29,    54,    -1,   354,    -1,   377,    -1,
      -1,   112,   147,    -1,    -1,    55,    -1,    -1,    49,    -1,
     229,    -1,   229,    26,    29,    28,    -1,   320,    -1,   317,
     318,   320,    -1,    -1,    60,    -1,   229,    -1,   229,    40,
     229,    -1,    35,    40,   229,    -1,   229,    40,    55,    -1,
      35,    40,    55,    -1,   319,    -1,   319,    61,   319,    -1,
     229,    -1,    27,    -1,    -1,   323,    -1,   324,    -1,   323,
     324,    -1,   152,    -1,   153,    -1,   230,    -1,    -1,   322,
     230,   327,   322,    -1,    64,    -1,    64,    53,    29,    54,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,   335,    -1,    71,   335,    -1,    72,   342,    -1,
      73,   336,    -1,   114,    -1,   115,    -1,   116,    -1,   117,
      -1,   148,    -1,   333,    -1,   329,    60,   333,    -1,   332,
      -1,   330,    60,   332,    -1,    29,    -1,    57,    29,    -1,
      58,    29,    -1,    47,    -1,    30,    -1,    16,    -1,   331,
      -1,    42,    -1,   334,    -1,   334,   111,   334,    -1,   334,
      38,   334,    -1,    47,    -1,    30,    -1,    16,    -1,   331,
      -1,    42,    -1,    -1,    53,    29,    54,    -1,    53,    29,
      60,    29,    54,    -1,    -1,   339,   111,   341,    -1,    -1,
      53,    29,    54,    -1,    29,    -1,   340,   337,    -1,   136,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,   141,
      -1,   142,   346,    -1,   340,    -1,    -1,   343,   111,   344,
      -1,   345,    -1,   345,    -1,   136,    -1,   137,    -1,   138,
      -1,   139,    -1,   140,    -1,   141,    -1,   142,   346,    -1,
      -1,    53,   338,    54,    -1,    -1,   348,    -1,   129,   349,
      -1,   350,    -1,   350,   127,   350,    -1,   350,   126,   350,
      -1,   351,   125,   351,    -1,   351,     8,   351,    -1,   351,
       9,   351,    -1,   351,    74,   351,    -1,   351,   130,    74,
     351,    -1,   351,    46,   351,    -1,   351,   134,    -1,   351,
     135,    -1,   351,    -1,   351,   131,   351,   127,   351,    -1,
     351,   132,    53,   353,    54,    -1,   130,   350,    -1,    53,
     350,    54,    -1,   352,    -1,    29,    -1,    47,    -1,   133,
      -1,    30,    -1,   351,    -1,   353,    60,   351,    -1,    18,
     355,    -1,   356,    -1,   355,   356,    -1,     8,   357,     9,
     314,     8,   357,     9,    -1,   358,    -1,   357,    60,   358,
      -1,   359,    40,   360,    -1,   360,    -1,   229,    -1,   228,
      -1,   155,   371,   160,   375,   369,    -1,   156,   372,   160,
     375,   369,    -1,   165,   378,    -1,   164,   378,    -1,   365,
      -1,   370,    -1,   363,    -1,   366,    -1,   367,    -1,   378,
      -1,   368,    -1,   172,   383,   173,   362,   364,    -1,    -1,
     174,   362,    -1,   168,    -1,   169,   325,    46,   383,    -1,
     171,   325,    -1,   171,    46,   325,    -1,   171,   170,    -1,
     171,    46,   170,    -1,   175,   369,    27,    -1,   362,    -1,
     369,   362,    -1,    92,    47,    -1,    92,   167,    47,    -1,
      92,    84,    47,    -1,    92,   167,    84,    47,    -1,   373,
      -1,   371,   373,    -1,   374,    -1,   372,   374,    -1,   157,
      -1,   158,    -1,   159,    -1,   157,    -1,   161,    -1,   162,
      -1,   163,    -1,   159,    -1,    95,    -1,   158,    -1,   376,
      -1,   375,   318,   376,    -1,   359,    40,   360,    -1,   360,
      -1,   359,   154,   359,   315,    -1,    -1,   166,   229,    53,
     379,   380,    54,    -1,    -1,   381,    -1,   382,    -1,   381,
      60,   382,    -1,   383,    -1,   385,    -1,   383,   384,   383,
      -1,   127,    -1,   126,    -1,    58,   383,    -1,    57,   383,
      -1,   387,    -1,   130,   383,    -1,    53,   383,    54,    -1,
     386,    53,   380,    54,    -1,   176,   160,   325,    -1,   383,
     125,   383,    -1,   383,     8,   383,    -1,   383,     9,   383,
      -1,   383,    55,   383,    -1,   383,    57,   383,    -1,   383,
      58,   383,    -1,   383,    56,   383,    -1,   383,    74,   383,
      -1,   383,   130,    74,   383,    -1,   383,    46,   383,    -1,
     383,   134,    -1,   383,   135,    -1,   383,   131,   383,   127,
     383,    -1,   383,   132,    53,   388,    54,    -1,   383,   130,
     132,    53,   388,    54,    -1,   229,    -1,   325,    -1,    29,
      -1,    47,    -1,   133,    -1,    42,    -1,   387,    -1,   388,
      60,   387,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   160,   161,   167,   170,   176,   179,   190,
     191,   196,   197,   201,   206,   211,   212,   213,   214,   219,
     223,   230,   240,   249,   262,   270,   280,   288,   301,   302,
     309,   312,   315,   308,   331,   334,   337,   330,   351,   354,
     354,   360,   363,   366,   369,   372,   375,   378,   379,   383,
     384,   385,   389,   398,   404,   414,   421,   423,   425,   427,
     429,   431,   436,   436,   446,   446,   449,   449,   462,   462,
     481,   483,   486,   481,   491,   491,   496,   497,   498,   510,
     511,   516,   517,   520,   535,   547,   548,   559,   570,   583,
     595,   606,   611,   614,   622,   623,   629,   628,   653,   656,
     656,   674,   675,   678,   679,   680,   683,   690,   691,   694,
     695,   696,   698,   699,   700,   706,   710,   710,   715,   716,
     717,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     731,   730,   761,   762,   763,   766,   766,   769,   773,   769,
    1105,  1106,  1112,  1122,  1123,  1126,  1127,  1130,  1133,  1138,
    1149,  1163,  1177,  1186,  1208,  1217,  1229,  1234,  1240,  1249,
    1258,  1265,  1267,  1270,  1276,  1277,  1278,  1279,  1282,  1283,
    1287,  1288,  1292,  1292,  1295,  1300,  1322,  1346,  1354,  1355,
    1356,  1357,  1362,  1367,  1372,  1377,  1378,  1379,  1380,  1381,
    1382,  1383,  1384,  1385,  1390,  1395,  1397,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1414,
    1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,
    1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1443,  1445,  1446,  1447,  1448,  1449,  1450,  1451,
    1457,  1458,  1459,  1460,  1472,  1473,  1477,  1478,  1479,  1480,
    1481,  1482,  1483,  1484,  1486,  1521,  1522,  1523,  1524,  1525,
    1526,  1527,  1531,  1532,  1535,  1535,  1537,  1537,  1540,  1550,
    1556,  1556,  1559,  1560,  1561,  1565,  1565,  1567,  1567,  1570,
    1570,  1572,  1575,  1581,  1584,  1588,  1589,  1593,  1597,  1601,
    1605,  1609,  1616,  1616,  1620,  1623,  1627,  1627,  1630,  1630,
    1634,  1635,  1648,  1660,  1660,  1673,  1677,  1681,  1685,  1689,
    1693,  1697,  1701,  1707,  1711,  1715,  1719,  1723,  1727,  1731,
    1734,  1741,  1741,  1745,  1745,  1750,  1750,  1750,  1754,  1761,
    1762,  1763,  1764,  1771,  1772,  1775,  1781,  1788,  1789,  1790,
    1791,  1797,  1800,  1801,  1804,  1805,  1812,  1816,  1823,  1831,
    1834,  1835,  1836,  1837,  1838,  1839,  1840,  1848,  1850,  1851,
    1854,  1857,  1861,  1862,  1863,  1864,  1865,  1866,  1867,  1875,
    1879,  1888,  1888,  1894,  1900,  1901,  1904,  1910,  1911,  1912,
    1913,  1914,  1915,  1916,  1917,  1918,  1919,  1920,  1921,  1922,
    1925,  1932,  1933,  1934,  1939,  1942,  1946,  1958,  1961,  1962,
    1966,  1976,  1983,  1992,  1995,  2007,  2010,  2014,  2021,  2029,
    2034,  2042,  2046,  2051,  2056,  2061,  2066,  2071,  2080,  2089,
    2090,  2095,  2098,  2106,  2112,  2118,  2124,  2133,  2138,  2148,
    2158,  2164,  2170,  2176,  2186,  2198,  2206,  2218,  2226,  2227,
    2228,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2241,  2248,
    2259,  2263,  2270,  2278,  2278,  2296,  2297,  2303,  2309,  2317,
    2324,  2325,  2330,  2331,  2347,  2349,  2350,  2351,  2352,  2353,
    2356,  2357,  2358,  2359,  2360,  2361,  2362,  2363,  2364,  2365,
    2366,  2367,  2368,  2369,  2370,  2371,  2374,  2377,  2378,  2379,
    2380,  2381,  2384,  2388
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
  "TITLE", "NAMED_CASE_SPECIFIC", "FORMONLY", "COMMENT", "DYNAMIC",
  "COLON", "ATSIGN", "DOT", "WITHOUT", "KW_NULL", "INPUT", "TABLES",
  "PIPE", "EQUAL", "CHAR_VALUE", "CHARACTER_ENCODING", "SEMICOLON",
  "LOOKUP", "JOINING", "LOOKUP_FROM", "OPEN_BRACKET", "CLOSE_BRACKET",
  "STAR", "DIVIDE", "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", "TYPE",
  "DELIMITERS", "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", "SMALLFLOAT",
  "SMALLINT", "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", "LIKE",
  "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", "YELLOW",
  "NORMAL", "REVERSE", "LEFT", "BOLD", "BLINK", "UNDERLINE", "DIM",
  "AUTONEXT", "COLOR", "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY",
  "DOWNSHIFT", "UPSHIFT", "FORMAT", "INCLUDE", "INVISIBLE", "NOUPDATE",
  "NOENTRY", "PICTURE", "PROGRAM", "REQUIRED", "QUERYCLEAR", "VERIFY",
  "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO", "AS", "UNHIDABLE", "SERIAL",
  "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR", "KW_NONSPACE", "KW_HEADER",
  "SQLONLY", "WIDGET", "CONFIG", "KW_NL", "COMPARISON", "KWOR", "KWAND",
  "KWAND1", "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK",
  "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND",
  "FRACTION", "KW_JUSTIFY", "KW_CENTER", "KW_TABINDEX", "KW_NOT_NULL",
  "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY", "ALLOWING", "KW_WS",
  "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", "KW_EDITADD",
  "KW_EDITUPDATE", "KW_REMOVE", "KW_OF", "KW_ADD", "KW_UPDATE", "KW_QUERY",
  "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL", "KW_BELL", "KW_ABORT",
  "KW_LET", "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF", "KW_THEN", "KW_ELSE",
  "KW_BEGIN", "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL", "KW_USES_EXTENDED",
  "SPECIAL_DBNAME", "KW_ACTION", "KW_PAGE", "KW_HBOX", "KW_VBOX",
  "KW_GRID", "KW_GROUP", "KW_TABLE", "KW_FOLDER", "KW_STYLE", "KW_LAYOUT",
  "KW_HIDDEN", "KW_AUTOSIZE", "KW_TEXTEDIT", "KW_BUTTONEDIT", "KW_LABEL",
  "KW_EDIT", "KW_DATEEDIT", "KW_SCROLL", "KW_IMAGE", "KW_FONTPITCH",
  "KW_FIXED", "KW_VARIABLE", "KW_WANTNORETURNS", "KW_WANTTABS",
  "KW_AUTOSCALE", "KW_PIXELWIDTH", "KW_PIXELHEIGHT", "KW_BORDER",
  "KW_SCROLLBARS_BOTH", "KW_SCROLLBARS_V", "KW_SCROLLBARS_H",
  "KW_STRETCH_Y", "KW_STRETCH_BOTH", "KW_ITEMS", "KW_VALUEMAX",
  "KW_VALUEMIN", "KW_PROGRESSBAR", "KW_COMBOBOX", "OPTIONS", "KW_BROWSER",
  "KW_VALUECHECKED", "KW_VALUEUNCHECKED", "KW_CHECKBOX", "$accept",
  "form_def", "encoding_section", "database_section", "named_or_kw_st_pc",
  "named_or_kw_any_pc", "named_or_kw_any_tag", "dbname",
  "screen_or_layout_section", "vbox_section", "hbox_section",
  "group_section", "folder_section", "pages", "page", "opt_layout_ident",
  "grid_section", "@1", "$@2", "$@3", "table_section", "@4", "$@5", "$@6",
  "layout_attributes", "$@7", "layout_attribute", "layout_attribute_list",
  "op_layout_items", "layout_items", "layout_container", "layout_section",
  "$@8", "screen_section", "screens_section", "$@9", "$@10",
  "screens_rest", "$@11", "$@12", "$@13", "op_extended", "op_size",
  "op_end", "screen_layout", "some_text", "screen_element", "ch_list",
  "field", "$@14", "field_element", "$@15", "op_table_section",
  "table_def_list", "table_def", "opequal", "table_qualifier",
  "attribute_section", "field_tag_list", "op_field_tag_type", "field_tag",
  "$@16", "fpart_list", "eq_or_colon", "fpart", "$@17", "$@18", "op_att",
  "field_datatype_null", "field_datatype", "field_type", "op_lu_ft_eq_c",
  "lu_ft_eq_c", "lu_ft_eq_c_i", "lu_ft", "lu_fc", "lu_joincol", "lu_join",
  "op_field_desc", "op_desc_list", "desc", "def_val", "colors", "color",
  "op_instruction_section", "instruct_opts", "instruct_op_1",
  "instruct_op", "$@19", "op_ltype", "op_star", "op_semi", "srec_dim",
  "srec_field_list", "op_comma", "field_list_item", "field_list_element",
  "field_name", "op_ws", "ws", "ws_elem", "field_tag_name",
  "field_tag_name_scr", "$@20", "datatype", "incl_list", "items_list",
  "number_value", "items_entry", "incl_entry", "incl_item", "opt_dec_ext",
  "opt_int_ext", "opt_unit_size", "dtfrac", "int_start", "int_start_unit",
  "int_end", "opt_dt_ext", "dt_start", "dt_end", "dtime_val", "opt_frac",
  "op_where", "where_clause", "clauses", "clause", "value",
  "fieldidentifier", "value_list", "composites", "composites_list",
  "composite_entry", "comp_list", "comp_item", "table_name", "column_name",
  "control_block", "action", "if", "op_else", "abort", "let", "nextfield",
  "block", "actions", "comments", "bef_act_list", "aft_act_list",
  "bef_act", "aft_act", "column_list", "column_entry", "master_of",
  "func_call", "@21", "op_func_call_args", "func_call_args",
  "func_call_arg", "expression", "and_or", "single_expression",
  "fcall_name", "evalue", "evalue_list", 0
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
     475,   476,   477,   478
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   224,   225,   226,   226,   227,   227,   227,   227,   228,
     228,   229,   229,   230,   230,   231,   231,   231,   231,   232,
     232,   233,   234,   235,   236,   237,   237,   238,   239,   239,
     241,   242,   243,   240,   245,   246,   247,   244,   248,   249,
     248,   250,   250,   250,   250,   250,   250,   250,   250,   251,
     251,   251,   252,   252,   253,   253,   254,   254,   254,   254,
     254,   254,   256,   255,   257,   257,   259,   258,   260,   258,
     262,   263,   264,   261,   265,   265,   266,   266,   266,   267,
     267,   268,   268,   269,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   271,   271,   273,   272,   274,   275,
     274,   276,   276,   277,   277,   277,   278,   279,   279,   280,
     280,   280,   280,   280,   280,   281,   282,   282,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     285,   284,   286,   286,   286,   287,   287,   289,   290,   288,
     291,   291,   291,   292,   292,   293,   293,   293,   293,   294,
     294,   294,   294,   294,   294,   294,   295,   295,   296,   296,
     297,   298,   299,   299,   300,   300,   300,   300,   301,   301,
     302,   302,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     305,   305,   305,   305,   306,   306,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   308,   308,   309,   309,   310,   310,   311,   311,
     312,   311,   311,   311,   311,   313,   313,   314,   314,   315,
     315,   316,   316,   317,   317,   318,   318,   319,   319,   319,
     319,   319,   320,   320,   321,   321,   322,   322,   323,   323,
     324,   324,   325,   327,   326,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   329,   329,   330,   330,   331,   331,   331,   332,   332,
     332,   332,   332,   333,   333,   333,   334,   334,   334,   334,
     334,   335,   335,   335,   336,   336,   337,   337,   338,   339,
     340,   340,   340,   340,   340,   340,   340,   341,   342,   342,
     343,   344,   345,   345,   345,   345,   345,   345,   345,   346,
     346,   347,   347,   348,   349,   349,   349,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     351,   351,   351,   351,   352,   353,   353,   354,   355,   355,
     356,   357,   357,   358,   358,   359,   360,   361,   361,   361,
     361,   362,   362,   362,   362,   362,   362,   362,   363,   364,
     364,   365,   366,   367,   367,   367,   367,   368,   369,   369,
     370,   370,   370,   370,   371,   371,   372,   372,   373,   373,
     373,   374,   374,   374,   374,   374,   374,   374,   375,   375,
     376,   376,   377,   379,   378,   380,   380,   381,   381,   382,
     383,   383,   384,   384,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   386,   387,   387,   387,
     387,   387,   388,   388
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     5,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     5,     5,     5,     5,     1,     2,     5,     0,     1,
       0,     0,     0,    10,     0,     0,     0,    10,     0,     0,
       4,     3,     1,     1,     3,     3,     1,     3,     3,     1,
       2,     3,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     0,     5,     1,     2,     0,     3,     0,     4,
       0,     0,     0,     9,     0,     1,     0,     2,     4,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     4,     1,     0,
       4,     0,     3,     1,     2,     3,     2,     0,     2,     1,
       3,     3,     5,     3,     3,     3,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     1,     2,     3,     1,     1,     0,     0,     6,
       0,     3,     5,     3,     1,     0,     5,     3,     2,     4,
       2,     4,     3,     1,     4,     2,     0,     1,     1,     3,
       3,     1,     3,     1,     3,     1,     4,     2,     1,     2,
       0,     2,     1,     3,     1,     4,     2,     4,     3,     3,
       3,     3,     5,     3,     5,     1,     1,     3,     5,     3,
       3,     3,     1,     4,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     5,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     1,     2,     1,     2,     2,     1,
       0,     9,    12,     1,     1,     0,     2,     0,     1,     0,
       1,     1,     4,     1,     3,     0,     1,     1,     3,     3,
       3,     3,     1,     3,     1,     1,     0,     1,     1,     2,
       1,     1,     1,     0,     4,     1,     4,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
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
       1,     3,     1,     1,     2,     2,     1,     2,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     2,     2,     5,     5,     6,     1,     1,     1,     1,
       1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     3,     9,    10,     5,    15,    17,     8,
       1,     0,     0,     0,     0,     0,     0,     4,     0,    66,
      38,   101,    20,    19,    64,     0,    11,    12,    16,    18,
       0,    68,    76,    39,    62,     0,     0,    65,     7,     6,
      76,     0,    67,    70,     0,     0,   107,    79,   103,   118,
     262,    69,    77,    74,     0,     0,     0,    42,    43,     0,
       0,    46,    49,     0,    28,    28,    30,    28,    34,    28,
      56,    57,    58,    59,    60,    61,    79,     0,   106,    80,
       0,   102,   104,   124,   120,   123,   121,   119,   122,   125,
     126,   127,   129,   128,    79,     0,   116,     0,     2,     0,
      75,     0,     0,     0,     0,     0,     0,    40,     0,    50,
      29,    38,    38,    28,    38,    28,    38,    63,     0,   109,
     108,   105,   115,   117,    13,    14,   302,   130,     0,     0,
       0,     0,     0,     0,     0,     0,   405,    79,   264,   266,
     273,     0,   269,   274,    78,    71,    44,    45,    41,    48,
      47,    51,    52,    52,    38,    52,    38,     0,     0,     0,
       0,     0,     0,     0,   397,   398,   270,   268,     0,   438,
     439,   440,     0,   434,   446,   441,   447,   445,   442,   443,
     444,     0,   436,     0,   410,   409,   263,   265,   267,     0,
       0,     0,    53,    54,     0,     0,     0,     0,    28,     0,
      25,   114,   110,   111,   113,   136,   135,     0,   137,   132,
       9,    10,   406,     0,   401,     0,   404,   399,     0,     0,
       0,   435,     0,   437,     0,   279,    94,    87,    96,    83,
      88,    89,    93,    92,    91,    86,     0,    84,    81,    90,
      85,    22,    55,    21,    31,    23,    35,    38,    24,    26,
       0,   131,   133,     0,   277,     0,     0,   281,     0,     0,
       0,   451,   285,   448,   285,   453,   280,   452,   296,    72,
      82,    95,     0,     0,    52,   112,   134,     0,     0,   145,
     153,   140,   278,     0,   402,   403,     0,     0,     0,     0,
     286,     0,   421,     0,     0,     0,     0,     0,   428,   413,
     411,   414,   415,   417,   407,   412,   416,   408,   455,   300,
     301,     0,     0,   297,   298,    98,    79,     0,     0,     0,
       0,   155,     0,     0,   150,   144,     0,     0,   138,     0,
       0,     0,   287,   285,   292,   283,     0,   450,   430,     0,
       0,     0,     0,   425,   423,   488,    13,    14,   491,   489,
       0,     0,     0,     0,   490,     0,   486,   487,     0,   460,
       0,   466,     0,   449,   429,     0,   456,   457,   459,    97,
      99,   303,   299,    73,    32,    36,    27,   295,   294,   145,
       0,   305,   307,   308,   309,   310,   311,   341,   341,   358,
     344,     0,   316,   317,   318,   319,   320,   148,   145,     0,
     152,     0,   170,     0,   282,     0,     0,   275,     0,     0,
       0,   432,   431,     0,     0,   426,   424,     0,   465,   464,
     467,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   463,   462,     0,     0,     0,   481,   482,     0,     0,
     455,   427,   454,     0,   296,   296,     0,     0,   149,   154,
       0,     0,   312,   313,   362,   363,   364,   365,   366,   367,
     369,   314,     0,   360,   350,   351,   352,   353,   354,   355,
     369,   315,     0,   346,   147,   151,   143,   141,     0,     0,
     139,   400,   291,   289,   290,   288,     0,   279,   284,   293,
       0,   433,   422,   468,   470,   472,   473,   480,   474,   477,
     475,   476,   478,   471,     0,     0,     0,     0,   419,   461,
       0,   458,   100,   304,    33,    37,     0,     0,     0,   368,
       0,   356,     0,     0,   349,     0,     0,   194,   156,     0,
     202,   174,     0,     0,     0,     0,     0,   185,   186,     0,
       0,   192,   197,   196,     0,     0,   200,   204,   203,   207,
     201,     0,     0,   195,     0,     0,     0,     0,   232,   206,
     205,     0,     0,   210,   216,     0,     0,   212,   213,   211,
       0,     0,   223,   224,   225,   226,   227,     0,     0,     0,
       0,     0,     0,   171,   172,   276,   271,     0,   479,     0,
       0,   492,     0,     0,   418,   469,   306,   342,     0,   348,
       0,   359,   361,   357,   345,     0,   146,   142,     0,     0,
     157,   158,     0,   161,     0,   165,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   483,
     484,     0,   420,     0,   370,   347,     0,   168,     0,     0,
       0,     0,   167,     0,   254,   246,   247,   248,   249,   250,
     251,   252,   253,   257,   255,   258,   259,   260,   261,   256,
     371,   244,   178,   241,   242,   240,   243,   179,   183,   181,
     187,     0,   198,   199,   237,   238,   189,   190,   218,   220,
     219,   229,   191,   239,   217,   214,   215,   222,   221,     0,
     230,   231,   180,   235,   233,   236,   234,   173,     0,   485,
     493,   343,   193,   169,   177,   159,   163,   160,     0,   164,
       0,   245,   175,   372,     0,     0,   338,   325,   337,   340,
     336,     0,     0,     0,   339,   321,   333,   330,   329,   332,
     328,     0,   331,   323,   272,     0,   166,   391,   394,   392,
       0,     0,   393,   373,   374,   385,   390,   184,   182,   326,
     327,   188,     0,     0,     0,   228,     0,   162,     0,   388,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     383,   384,   322,   335,   334,   324,   389,   376,   375,   378,
     379,   382,   380,   377,     0,     0,     0,   381,     0,   395,
       0,   386,   387,     0,   396
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,     3,   212,   356,   126,     9,    21,    70,
      71,    72,    73,   199,   200,   111,    74,   113,   272,   446,
      75,   115,   273,   447,    34,    44,    62,    63,   191,   192,
     193,    22,    45,    23,    24,    32,    40,    42,    53,   190,
     316,   101,    43,    81,   236,   237,   238,   239,   240,   268,
     311,   444,    36,    47,    48,    78,   120,    50,    94,    95,
      96,   162,   207,   208,   209,   253,   402,   328,   324,   325,
     281,   609,   610,   611,   612,   727,   616,   659,   480,   583,
     584,   687,   680,   681,    98,   137,   138,   139,   218,   487,
     283,   267,   258,   333,   297,   334,   335,   379,   312,   313,
     314,   357,   315,   445,   397,   743,   751,   744,   753,   745,
     746,   452,   471,   524,   600,   472,   473,   604,   461,   462,
     601,   463,   519,   732,   733,   763,   764,   765,   766,   810,
     140,   164,   165,   213,   214,   215,   216,   142,   298,   299,
     594,   300,   301,   302,   303,   304,   305,   172,   181,   173,
     182,   262,   263,   143,   306,   308,   365,   366,   367,   368,
     439,   359,   360,   361,   592
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -681
static const yytype_int16 yypact[] =
{
      31,   -20,    62,    19,  -681,  -681,    71,    86,   122,   146,
    -681,   126,   -16,   147,   245,   245,   179,  -681,   188,  -681,
     194,   221,  -681,   298,  -681,   268,  -681,  -681,  -681,  -681,
     281,  -681,   283,  -681,  -681,   245,   307,  -681,  -681,  -681,
     283,   319,  -681,  -681,   366,   473,   305,   247,  -681,   585,
     346,  -681,   349,   184,   329,   337,   340,  -681,  -681,   343,
     358,  -681,  -681,    22,   245,   245,  -681,   245,  -681,   245,
    -681,  -681,  -681,  -681,  -681,  -681,   402,   136,  -681,  -681,
     245,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,     0,   270,  -681,   254,  -681,   405,
    -681,   416,   389,   429,   422,   436,   441,  -681,   366,  -681,
    -681,   194,   194,   245,   194,   245,   194,  -681,   434,   362,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,   471,   421,
     437,   430,   222,   538,   320,   320,  -681,   102,  -681,   445,
    -681,   336,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,   473,   473,   194,   473,   194,   315,   245,   245,
     245,   245,   199,   334,   471,  -681,  -681,  -681,   470,  -681,
    -681,  -681,   248,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,   526,  -681,   245,  -681,  -681,  -681,  -681,  -681,   245,
     479,   474,   473,  -681,   476,   469,   480,   481,   245,   -18,
    -681,  -681,  -681,   475,  -681,  -681,  -681,   214,  -681,  -681,
     478,   482,  -681,     8,  -681,   483,  -681,  -681,   245,   450,
     334,  -681,   334,  -681,   463,   493,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,   269,  -681,  -681,   504,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,   194,  -681,  -681,
     245,   199,  -681,    40,   466,   334,   344,   499,   491,   522,
     514,  -681,   201,  -681,   201,  -681,  -681,  -681,   259,  -681,
    -681,  -681,   479,   479,   473,  -681,  -681,   516,   245,   -43,
     520,   540,  -681,   555,  -681,  -681,   541,   323,   515,   344,
    -681,   -36,  -681,   270,     1,    58,   393,   334,  -681,  -681,
    -681,  -681,  -681,  -681,   393,  -681,  -681,   393,    58,  -681,
    -681,   203,   270,   259,  -681,  -681,   402,   461,   472,   544,
     275,   535,   658,   533,  -681,   447,   245,   549,  -681,   334,
     551,   542,   546,    81,   523,  -681,   477,  -681,  -681,   550,
       7,   553,     2,  -681,  -681,  -681,   534,   548,  -681,  -681,
      58,    58,    58,    58,  -681,   442,  -681,  -681,   341,  -681,
     552,  -681,    10,  -681,  -681,   554,   556,  -681,   537,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,   547,
     245,   557,  -681,  -681,  -681,  -681,  -681,   559,   559,   680,
     687,   245,  -681,  -681,  -681,  -681,  -681,  -681,   547,   562,
    -681,    -3,   558,    34,  -681,   185,   216,   503,   323,   323,
     564,  -681,  -681,   572,    58,  -681,  -681,   581,   537,   537,
     537,   270,    58,    58,    58,    58,    58,    58,    58,    58,
      58,  -681,  -681,   -34,    58,   569,  -681,  -681,   393,    58,
      58,  -681,  -681,    58,   259,   259,   596,   599,  -681,  -681,
     601,   605,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
     587,  -681,   530,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
     587,  -681,   531,   590,   604,  -681,  -681,  -681,   617,   239,
    -681,  -681,  -681,  -681,  -681,  -681,   501,   493,  -681,  -681,
     621,  -681,   537,  -681,  -681,   635,   635,   537,   537,   537,
     537,   537,   537,   537,    58,   598,   620,    30,   496,   537,
     600,  -681,  -681,  -681,  -681,  -681,   611,   132,   623,  -681,
     680,  -681,   687,   624,  -681,   245,   645,   649,   270,   225,
    -681,  -681,   633,   634,   636,   628,   629,  -681,  -681,   652,
     659,  -681,  -681,  -681,   664,   671,  -681,  -681,  -681,   304,
    -681,   672,   673,  -681,   688,   689,   690,   691,  -681,  -681,
    -681,   692,   694,  -681,  -681,   696,   697,  -681,  -681,  -681,
     698,   702,  -681,  -681,  -681,  -681,  -681,   703,   707,   711,
     712,   713,   717,   644,  -681,  -681,  -681,   704,   537,    30,
      58,  -681,   162,   393,  -681,  -681,  -681,  -681,   727,  -681,
     714,  -681,  -681,  -681,  -681,   722,  -681,  -681,   725,   243,
     723,  -681,   731,  -681,   245,   760,  -681,   710,   754,     9,
     245,   245,   757,   761,   783,   785,  -681,  -681,   787,   789,
     790,   791,   -59,   778,   245,   792,   794,   223,   813,   814,
     793,   815,   816,     9,   151,   195,   239,   818,   208,   537,
    -681,    30,  -681,   795,  -681,  -681,   819,  -681,   799,   225,
     270,   245,   811,   245,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
     452,  -681,  -681,  -681,  -681,  -681,  -681,  -681,   812,   817,
    -681,   196,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,   240,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,   800,  -681,
    -681,  -681,  -681,  -681,  -681,  -681,   820,  -681,   245,  -681,
     180,  -681,  -681,  -681,   245,   245,  -681,  -681,  -681,  -681,
    -681,   824,   826,   236,  -681,  -681,   -22,  -681,  -681,  -681,
    -681,   265,  -681,  -681,  -681,   245,  -681,  -681,  -681,  -681,
     180,   180,  -681,  -681,   306,   418,  -681,  -681,  -681,  -681,
    -681,  -681,   196,   196,   196,  -681,   240,  -681,   802,  -681,
     180,   180,    74,    74,    74,    74,    74,   784,    74,   806,
    -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,    74,   734,    74,  -681,    74,  -681,
     266,  -681,  -681,    74,  -681
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -681,  -681,  -681,  -681,   861,   -14,   560,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,   665,     4,  -681,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,   -70,  -681,   -50,  -681,  -135,  -681,
     -33,  -681,  -681,  -681,   840,  -681,  -681,   825,  -681,  -681,
    -681,  -681,  -681,   -72,   168,  -681,  -208,  -681,  -681,  -681,
    -681,  -681,  -681,  -681,    60,  -681,  -681,  -681,  -681,  -681,
     772,  -681,  -681,  -681,  -158,  -681,  -681,  -681,  -255,  -681,
    -681,  -681,  -681,   207,  -681,  -681,   209,  -681,  -681,  -681,
     224,   226,  -681,   191,  -681,  -681,   736,  -681,  -681,  -681,
    -681,   387,  -681,  -681,   543,   468,   467,  -681,   433,  -681,
     566,   -93,   438,  -681,  -681,  -681,  -681,  -680,   104,   109,
    -317,   495,  -681,  -681,  -681,  -681,   363,  -681,  -681,  -681,
    -681,   364,   417,  -681,  -681,  -681,  -647,    27,  -681,  -681,
    -681,  -681,   724,   561,   631,   -92,   134,  -681,  -301,  -681,
    -681,  -681,  -681,  -681,  -681,  -174,  -681,  -681,  -681,   719,
     708,   670,   597,  -681,   328,  -681,   453,  -681,   454,  -272,
    -681,  -681,  -681,  -483,   309
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -119
static const yytype_int16 yytable[] =
{
      28,    29,   127,   364,   117,   141,   364,    18,    19,   248,
       4,   338,    76,   109,     5,     6,   773,   254,   194,   322,
     196,    46,   122,   358,   591,   477,   698,    79,   270,   752,
    -118,   124,   124,    46,  -118,   125,   125,   441,   683,   684,
     504,   152,   153,   481,   155,   141,   157,   342,   339,   252,
     110,   110,     1,   110,   412,   110,   685,   478,   151,   345,
     124,   364,    10,   119,   125,   186,    46,    11,   255,   112,
      26,   114,   348,   116,    27,   277,   107,   349,   417,   418,
     419,   420,   108,   136,   195,   699,   197,   345,   346,   774,
     307,   413,   347,   276,   255,   278,   752,   225,   505,   110,
     348,   110,   291,   757,   758,   349,   591,    82,   323,   270,
     270,   350,    13,   778,   779,   351,   352,   154,   700,   156,
     128,   759,   362,   136,   448,    14,   129,   686,   260,    79,
     260,   340,    26,   797,   798,   407,    27,   508,    54,   319,
     121,   290,   492,   475,   201,   202,   203,   204,    83,   136,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   242,
       7,    15,   506,   354,   198,   130,    26,   509,   720,   224,
      27,   343,   415,    17,    20,   136,   183,   274,   292,   293,
     713,   294,   295,   118,   110,   296,   597,    16,   353,    25,
     279,   354,   598,    84,    85,    86,    87,    88,   714,    89,
     341,   344,   247,    55,   257,   260,   136,   762,   136,   757,
     758,    56,   736,    57,    58,    26,   650,    90,    91,    27,
      92,    30,   651,    93,   715,   737,   738,   759,    59,    60,
      61,   369,   588,   760,   355,    31,   275,   205,   739,   280,
     482,   136,   716,   740,   373,   206,    26,    33,   370,   416,
      27,   131,   205,   741,   742,    26,   747,   132,   133,    27,
     206,   290,   719,   251,   321,    35,   134,   135,   651,   737,
     748,   484,   128,   332,    79,    26,   527,    26,   129,    27,
     614,    27,   749,   136,    26,   226,   227,   750,    27,   528,
     771,   529,   652,   291,   657,   228,   772,   741,   742,   229,
     124,   269,   377,   658,   125,    26,   378,    80,    41,    27,
     761,    38,   400,   762,   230,   136,   231,   130,   649,   775,
     812,    18,    19,   530,    39,   776,   813,    49,   494,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,    52,   422,
     423,    77,   550,    26,   261,   551,   261,    27,   331,   552,
     553,   554,   555,   100,   210,    97,   449,   183,   211,   292,
     293,    99,   294,   295,     4,   102,   296,   474,     5,   169,
     170,   171,   556,   103,   557,   558,   104,   424,   232,   105,
     285,   483,   485,   233,   332,   332,   425,   426,   427,   428,
     159,   160,   161,   131,   106,   169,   170,   171,   220,   132,
     133,   309,   310,   626,   627,   429,   559,   560,   134,   135,
     561,   234,   235,   337,   705,   706,   782,   783,   562,    79,
     563,   261,   780,   781,   144,   613,   146,   564,   565,   566,
     317,   318,   567,   568,   569,   570,   571,   145,   572,   573,
     574,   575,   576,   577,   578,   579,   793,   794,   580,   147,
     581,   582,   184,   185,   784,   149,   430,   431,   432,   148,
     150,   433,   434,   435,   158,   436,   437,   226,   227,   163,
     166,   664,    54,   168,   167,   291,   183,   228,   226,   227,
     189,   229,   785,   374,   188,   226,   227,   198,   228,   219,
     244,   241,   229,   243,   375,   228,   230,   245,   231,   229,
     259,   606,   246,   250,   438,   615,   265,   230,   -11,   231,
     271,   282,   -12,   256,   230,   286,   231,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   266,   786,   287,   422,   423,    55,   787,   788,
     789,   288,   790,   791,   289,    56,   320,    57,    58,   183,
     326,   292,   293,   329,   294,   295,   327,   613,   296,   336,
     330,   376,    59,    60,    61,   380,   398,   399,   401,   404,
     232,   730,   405,   424,   409,   233,   406,   -11,   410,   422,
     423,   232,   425,   426,   427,   428,   233,   411,   232,   414,
     662,   -12,   421,   233,   476,   440,   688,   689,   442,   322,
     450,   429,   451,   234,   235,   486,   443,   490,   479,   491,
     702,   174,   507,   514,   234,   235,   515,   424,   422,   423,
     516,   234,   235,   174,   517,   493,   425,   426,   427,   428,
     518,   520,   522,   523,   525,   615,   526,   726,   585,   729,
     587,   589,   599,   605,   595,   429,    64,    65,    66,    67,
      68,    69,   430,   431,   432,   596,   424,   433,   434,   435,
     593,   436,   437,   607,   608,   425,   426,   427,   428,   617,
     618,   424,   619,   175,   176,   177,   222,   178,   179,   180,
     425,   426,   427,   428,   429,   175,   176,   177,   622,   178,
     179,   180,   620,   621,   646,   623,   430,   431,   432,   429,
     624,   433,   434,   435,   756,   436,   437,   625,   628,   629,
     767,   768,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,    83,   630,   631,   632,   633,   634,   664,
     635,   777,   636,   637,   638,   430,   431,   590,   639,   640,
     433,   434,   435,   641,   436,   437,   653,   642,   643,   644,
     430,   431,   432,   645,   647,   433,   434,   435,   654,   436,
     437,   656,   392,   393,   394,   395,   655,   661,    84,    85,
      86,    87,    88,   660,    89,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,   675,   676,   677,   678,   679,
     663,   682,    90,    91,   690,    92,   396,   701,    93,   799,
     800,   801,   802,   803,   691,   805,   454,   455,   456,   457,
     458,   459,   460,   464,   465,   466,   467,   468,   469,   470,
     692,   807,   693,   809,   694,   811,   695,   696,   697,   703,
     814,   704,   707,   708,   710,   711,   709,   718,   722,   721,
     723,   728,   734,   769,   754,   770,   796,   735,   804,   806,
     755,   808,     8,    37,   249,    51,   123,   725,   724,   712,
     717,   731,   371,   187,   586,   488,   408,   489,   513,   372,
     795,   792,   512,   453,   602,   603,   284,   521,   217,   223,
     403,   221,   264,   510,   363,     0,     0,   511,   648
};

static const yytype_int16 yycheck[] =
{
      14,    15,    95,   304,    76,    97,   307,    23,    24,    27,
      30,    47,    45,    63,    34,    35,    38,     9,   153,    62,
     155,    35,    94,   295,   507,    28,    85,    27,   236,   709,
      30,    30,    30,    47,    34,    34,    34,    27,    29,    30,
      74,   111,   112,     9,   114,   137,   116,    46,    84,   207,
      64,    65,    21,    67,    47,    69,    47,    60,   108,    29,
      30,   362,     0,    77,    34,   137,    80,    48,    60,    65,
      30,    67,    42,    69,    34,    35,    54,    47,   350,   351,
     352,   353,    60,    97,   154,   144,   156,    29,    30,   111,
     264,    84,    34,   251,    60,    55,   776,   189,   132,   113,
      42,   115,    92,    29,    30,    47,   589,    47,   151,   317,
     318,    53,    41,   760,   761,    57,    58,   113,   177,   115,
      18,    47,   296,   137,   379,    39,    24,   118,   220,    27,
     222,   167,    30,   780,   781,    54,    34,   438,   116,   274,
      80,    60,   414,   398,   158,   159,   160,   161,   148,   163,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   192,
     180,    39,   434,   133,   182,    63,    30,   439,   651,   183,
      34,   170,   170,    47,   190,   189,   166,   247,   168,   169,
      29,   171,   172,    47,   198,   175,    54,    41,   130,    42,
     150,   133,    60,   193,   194,   195,   196,   197,    47,   199,
     293,   294,   198,   181,   218,   297,   220,   133,   222,    29,
      30,   189,    16,   191,   192,    30,    54,   217,   218,    34,
     220,    42,    60,   223,    29,    29,    30,    47,   206,   207,
     208,    28,   504,    53,   176,    47,   250,    38,    42,   253,
      55,   255,    47,    47,   316,    46,    30,    53,    45,   342,
      34,   149,    38,    57,    58,    30,    16,   155,   156,    34,
      46,    60,    54,    49,   278,    44,   164,   165,    60,    29,
      30,    55,    18,   287,    27,    30,    37,    30,    24,    34,
      55,    34,    42,   297,    30,    16,    17,    47,    34,    50,
      54,    52,   593,    92,    51,    26,    60,    57,    58,    30,
      30,    32,    27,    60,    34,    30,   320,    60,    25,    34,
     130,    43,   326,   133,    45,   329,    47,    63,   590,    54,
      54,    23,    24,    84,    43,    60,    60,    20,   421,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    29,     8,
       9,    46,   113,    30,   220,   116,   222,    34,    35,   120,
     121,   122,   123,   179,    30,    19,   380,   166,    34,   168,
     169,    22,   171,   172,    30,    46,   175,   391,    34,   157,
     158,   159,   143,    46,   145,   146,    46,    46,   119,    46,
     256,   405,   406,   124,   408,   409,    55,    56,    57,    58,
      38,    39,    40,   149,    46,   157,   158,   159,   160,   155,
     156,   152,   153,   109,   110,    74,   177,   178,   164,   165,
     181,   152,   153,   289,   201,   202,     8,     9,   189,    27,
     191,   297,   126,   127,    29,   528,    47,   198,   199,   200,
     272,   273,   203,   204,   205,   206,   207,    31,   209,   210,
     211,   212,   213,   214,   215,   216,   773,   774,   219,    30,
     221,   222,   134,   135,    46,    29,   125,   126,   127,    47,
      29,   130,   131,   132,    40,   134,   135,    16,    17,     8,
      59,    29,   116,    53,    47,    92,   166,    26,    16,    17,
     154,    30,    74,    32,    49,    16,    17,   182,    26,    29,
      31,    27,    30,    27,    32,    26,    45,    27,    47,    30,
      60,   525,    31,    38,   173,   529,    53,    45,    40,    47,
      16,    55,    40,    40,    45,    26,    47,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    49,   125,    53,     8,     9,   181,   130,   131,
     132,    29,   134,   135,    40,   189,    40,   191,   192,   166,
      40,   168,   169,     8,   171,   172,    26,   660,   175,    54,
      29,    27,   206,   207,   208,    40,    43,   130,    29,    28,
     119,   129,    40,    46,    61,   124,    40,    53,   111,     8,
       9,   119,    55,    56,    57,    58,   124,    47,   119,    46,
     614,    53,   160,   124,    42,    53,   620,   621,    54,    62,
      53,    74,    53,   152,   153,   112,    60,    53,    60,    47,
     634,    95,    53,    27,   152,   153,    27,    46,     8,     9,
      29,   152,   153,    95,    29,    54,    55,    56,    57,    58,
      53,   111,   111,    53,    40,   659,    29,   661,   147,   663,
      29,    53,    29,    29,    54,    74,   183,   184,   185,   186,
     187,   188,   125,   126,   127,    54,    46,   130,   131,   132,
     174,   134,   135,    28,    25,    55,    56,    57,    58,    46,
      46,    46,    46,   157,   158,   159,   160,   161,   162,   163,
      55,    56,    57,    58,    74,   157,   158,   159,    46,   161,
     162,   163,    74,    74,    60,    46,   125,   126,   127,    74,
      46,   130,   131,   132,   728,   134,   135,    46,    46,    46,
     734,   735,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   148,    46,    46,    46,    46,    46,    29,
      46,   755,    46,    46,    46,   125,   126,   127,    46,    46,
     130,   131,   132,    46,   134,   135,    29,    46,    46,    46,
     125,   126,   127,    46,    60,   130,   131,   132,    54,   134,
     135,    46,   114,   115,   116,   117,    54,    46,   193,   194,
     195,   196,   197,    60,   199,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      40,    47,   217,   218,    47,   220,   148,    29,   223,   782,
     783,   784,   785,   786,    53,   788,   136,   137,   138,   139,
     140,   141,   142,   136,   137,   138,   139,   140,   141,   142,
      47,   804,    47,   806,    47,   808,    47,    47,    47,    47,
     813,    47,    29,    29,    29,    29,    53,    29,    29,    54,
      51,    40,    40,    29,    54,    29,    54,    40,    74,    53,
      40,   127,     1,    23,   199,    40,    94,   660,   659,   643,
     646,   680,   312,   137,   487,   408,   333,   409,   445,   313,
     776,   772,   444,   388,   520,   522,   255,   470,   164,   181,
     329,   172,   222,   440,   297,    -1,    -1,   443,   589
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   225,   227,    30,    34,    35,   180,   228,   231,
       0,    48,   226,    41,    39,    39,    41,    47,    23,    24,
     190,   232,   255,   257,   258,    42,    30,    34,   229,   229,
      42,    47,   259,    53,   248,    44,   276,   258,    43,    43,
     260,    25,   261,   266,   249,   256,   229,   277,   278,    20,
     281,   261,    29,   262,   116,   181,   189,   191,   192,   206,
     207,   208,   250,   251,   183,   184,   185,   186,   187,   188,
     233,   234,   235,   236,   240,   244,   254,    46,   279,    27,
      60,   267,   278,   148,   193,   194,   195,   196,   197,   199,
     217,   218,   220,   223,   282,   283,   284,    19,   308,    22,
     179,   265,    46,    46,    46,    46,    46,    54,    60,   250,
     229,   239,   239,   241,   239,   245,   239,   267,    47,   229,
     280,   278,   267,   284,    30,    34,   230,   325,    18,    24,
      63,   149,   155,   156,   164,   165,   229,   309,   310,   311,
     354,   359,   361,   377,    29,    31,    47,    30,    47,    29,
      29,   250,   248,   248,   239,   248,   239,   248,    40,    38,
      39,    40,   285,     8,   355,   356,    59,    47,    53,   157,
     158,   159,   371,   373,    95,   157,   158,   159,   161,   162,
     163,   372,   374,   166,   378,   378,   267,   310,    49,   154,
     263,   252,   253,   254,   252,   248,   252,   248,   182,   237,
     238,   229,   229,   229,   229,    38,    46,   286,   287,   288,
      30,    34,   228,   357,   358,   359,   360,   356,   312,    29,
     160,   373,   160,   374,   229,   359,    16,    17,    26,    30,
      45,    47,   119,   124,   152,   153,   268,   269,   270,   271,
     272,    27,   254,    27,    31,    27,    31,   239,    27,   238,
      38,    49,   288,   289,     9,    60,    40,   229,   316,    60,
     359,   360,   375,   376,   375,    53,    49,   315,   273,    32,
     270,    16,   242,   246,   248,   229,   288,    35,    55,   150,
     229,   294,    55,   314,   358,   360,    26,    53,    29,    40,
      60,    92,   168,   169,   171,   172,   175,   318,   362,   363,
     365,   366,   367,   368,   369,   370,   378,   369,   379,   152,
     153,   274,   322,   323,   324,   326,   264,   268,   268,   252,
      40,   229,    62,   151,   292,   293,    40,    26,   291,     8,
      29,    35,   229,   317,   319,   320,    54,   360,    47,    84,
     167,   325,    46,   170,   325,    29,    30,    34,    42,    47,
      53,    57,    58,   130,   133,   176,   229,   325,   383,   385,
     386,   387,   369,   376,   362,   380,   381,   382,   383,    28,
      45,   230,   324,   267,    32,    32,    27,    27,   229,   321,
      40,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   114,   115,   116,   117,   148,   328,    43,   130,
     229,    29,   290,   357,    28,    40,    40,    54,   318,    61,
     111,    47,    47,    84,    46,   170,   325,   383,   383,   383,
     383,   160,     8,     9,    46,    55,    56,    57,    58,    74,
     125,   126,   127,   130,   131,   132,   134,   135,   173,   384,
      53,    27,    54,    60,   275,   327,   243,   247,   292,   229,
      53,    53,   335,   335,   136,   137,   138,   139,   140,   141,
     142,   342,   343,   345,   136,   137,   138,   139,   140,   141,
     142,   336,   339,   340,   229,   292,    42,    28,    60,    60,
     302,     9,    55,   229,    55,   229,   112,   313,   320,   319,
      53,    47,   383,    54,   325,   383,   383,   383,   383,   383,
     383,   383,   383,   383,    74,   132,   383,    53,   362,   383,
     380,   382,   326,   322,    27,    27,    29,    29,    53,   346,
     111,   346,   111,    53,   337,    40,    29,    37,    50,    52,
      84,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     113,   116,   120,   121,   122,   123,   143,   145,   146,   177,
     178,   181,   189,   191,   198,   199,   200,   203,   204,   205,
     206,   207,   209,   210,   211,   212,   213,   214,   215,   216,
     219,   221,   222,   303,   304,   147,   315,    29,   383,    53,
     127,   387,   388,   174,   364,    54,    54,    54,    60,    29,
     338,   344,   345,   340,   341,    29,   229,    28,    25,   295,
     296,   297,   298,   325,    55,   229,   300,    46,    46,    46,
      74,    74,    46,    46,    46,    46,   109,   110,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    60,    60,   388,   383,
      54,    60,   362,    29,    54,    54,    46,    51,    60,   301,
      60,    46,   229,    40,    29,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     306,   307,    47,    29,    30,    47,   118,   305,   229,   229,
      47,    53,    47,    47,    47,    47,    47,    47,    85,   144,
     177,    29,   229,    47,    47,   201,   202,    29,    29,    53,
      29,    29,   305,    29,    47,    29,    47,   304,    29,    54,
     387,    54,    29,    51,   300,   297,   229,   299,    40,   229,
     129,   307,   347,   348,    40,    40,    16,    29,    30,    42,
      47,    57,    58,   329,   331,   333,   334,    16,    30,    42,
      47,   330,   331,   332,    54,    40,   229,    29,    30,    47,
      53,   130,   133,   349,   350,   351,   352,   229,   229,    29,
      29,    54,    60,    38,   111,    54,    60,   229,   350,   350,
     126,   127,     8,     9,    46,    74,   125,   130,   131,   132,
     134,   135,   333,   334,   334,   332,    54,   350,   350,   351,
     351,   351,   351,   351,    74,   351,    53,   351,   127,   351,
     353,   351,    54,    60,   351
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
        case 2:

/* Line 1464 of yacc.c  */
#line 151 "screen.yacc"
    {
A4GL_check_compiled_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
A4GL_write_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 160 "screen.yacc"
    {the_form.encoding="";}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 161 "screen.yacc"
    {
		the_form.encoding=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
	}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 167 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");
the_form.allowNullInput=1;
}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 170 "screen.yacc"
    {the_form.dbname=acl_strdup((yyvsp[(2) - (5)].str));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=0;
}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 176 "screen.yacc"
    {the_form.dbname=("formonly");
the_form.allowNullInput=0;
}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 179 "screen.yacc"
    {the_form.dbname=acl_strdup((yyvsp[(2) - (2)].str));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=1;
}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 190 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));A4GL_make_downshift((yyval.str)); }
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 191 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 196 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));A4GL_make_downshift((yyval.str)); }
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 197 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 201 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));
 		if (tagCaseInsensitive) {
                		A4GL_make_downshift((yyval.str));
        		}
	}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 206 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 211 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 212 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 214 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 219 "screen.yacc"
    {
			the_form.layout=NULL;
			the_form.layout_attrib=NULL;
	}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 223 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 230 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 240 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_HBOX;
	}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 249 "screen.yacc"
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

  case 24:

/* Line 1464 of yacc.c  */
#line 262 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 270 "screen.yacc"
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

  case 26:

/* Line 1464 of yacc.c  */
#line 280 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 288 "screen.yacc"
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

  case 28:

/* Line 1464 of yacc.c  */
#line 301 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 302 "screen.yacc"
    {
		{strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
	}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 309 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 312 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 315 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 316 "screen.yacc"
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

  case 34:

/* Line 1464 of yacc.c  */
#line 331 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 334 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 337 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 338 "screen.yacc"
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

  case 38:

/* Line 1464 of yacc.c  */
#line 351 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 354 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 354 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 360 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 363 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 366 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 369 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 372 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_ACTION, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 375 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_BORDER);
	}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 378 "screen.yacc"
    { add_str_layout_attrib(FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 379 "screen.yacc"
    { add_str_layout_attrib(FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 389 "screen.yacc"
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

  case 53:

/* Line 1464 of yacc.c  */
#line 398 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 404 "screen.yacc"
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

  case 55:

/* Line 1464 of yacc.c  */
#line 414 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 422 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 424 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 426 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 428 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 430 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 432 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 436 "screen.yacc"
    { 
		the_form.layout_attrib=(yyvsp[(2) - (2)].layout_attrib);
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 438 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(4) - (5)].layout);
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 449 "screen.yacc"
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

  case 68:

/* Line 1464 of yacc.c  */
#line 462 "screen.yacc"
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

  case 70:

/* Line 1464 of yacc.c  */
#line 481 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 483 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 486 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 491 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 498 "screen.yacc"
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

  case 83:

/* Line 1464 of yacc.c  */
#line 520 "screen.yacc"
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

  case 84:

/* Line 1464 of yacc.c  */
#line 535 "screen.yacc"
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

  case 85:

/* Line 1464 of yacc.c  */
#line 547 "screen.yacc"
    { ltab=0; }
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 548 "screen.yacc"
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

  case 87:

/* Line 1464 of yacc.c  */
#line 559 "screen.yacc"
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

  case 88:

/* Line 1464 of yacc.c  */
#line 570 "screen.yacc"
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

  case 89:

/* Line 1464 of yacc.c  */
#line 583 "screen.yacc"
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

  case 90:

/* Line 1464 of yacc.c  */
#line 595 "screen.yacc"
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

  case 91:

/* Line 1464 of yacc.c  */
#line 606 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 611 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 614 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 622 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 623 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 629 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 636 "screen.yacc"
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

  case 98:

/* Line 1464 of yacc.c  */
#line 653 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 656 "screen.yacc"
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

  case 100:

/* Line 1464 of yacc.c  */
#line 667 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 683 "screen.yacc"
    { 
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 690 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 691 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 694 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 695 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 697 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 698 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 699 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 715 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 716 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 717 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 718 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 719 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 720 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 721 "screen.yacc"
    {strcpy((yyval.str),"Button");}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 722 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 723 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 724 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 725 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 726 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 731 "screen.yacc"
    {
			if (tagCaseInsensitive) {
				A4GL_make_downshift((yyvsp[(2) - (2)].str));
			}
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 739 "screen.yacc"
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

  case 137:

/* Line 1464 of yacc.c  */
#line 769 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 773 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	//if (fld->tabname) {
		//A4GL_make_downshift(fld->tabname);
	//}
	//A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
#ifdef DEBUG
	A4GL_debug("add color %d\n",FA_C_WHITE);
#endif
}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 787 "screen.yacc"
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
		printf("dtype=%d col=%s\n",dtype,fld->colname);
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
			} else {
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

#ifdef DEBUG
			A4GL_debug("Currpos = %ld\n",ftell(yyin));
#endif
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
						// Characters can be spaces - everything else would have to be null
						// but nulls are not allowed - so it must be 'required' as well
						if (A4GL_isyes(acl_getenv("SPCNOTNULLCHAR"))) {
							break;
						}
						// drop through...
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

  case 141:

/* Line 1464 of yacc.c  */
#line 1106 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1112 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1122 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1123 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1126 "screen.yacc"
    {strcpy((yyval.str),"0"); dtype_size=0;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1127 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str),1));
		}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1130 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),"",1));
		}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1133 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1138 "screen.yacc"
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

  case 150:

/* Line 1464 of yacc.c  */
#line 1149 "screen.yacc"
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

  case 151:

/* Line 1464 of yacc.c  */
#line 1163 "screen.yacc"
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

  case 152:

/* Line 1464 of yacc.c  */
#line 1177 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1186 "screen.yacc"
    {
	struct struct_scr_field *fld;
	char *tab;
	fld=A4GL_get_fld();
	tab=fcompile_find_table((yyvsp[(1) - (1)].str));
	if (tab) {
		fld->tabname=strdup(fcompile_find_table((yyvsp[(1) - (1)].str)));
	} else {
		fld->tabname=0;
	}
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	if (fld->tabname!=0) {
		fld->not_null=0;
        	fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        	fld->dtype_size=A4GL_get_dtype_size();
	} else {
		fld->tabname=acl_strdup("-");
        	fld->dtype_size=1;
		fld->datatype=DTYPE_CHAR;
	}
}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1208 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1217 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"",0);
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1229 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;
	}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1234 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (1)].lookups);
		}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1240 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1249 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1258 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1267 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1270 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1276 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1277 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1278 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1279 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1295 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1300 "screen.yacc"
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

  case 176:

/* Line 1464 of yacc.c  */
#line 1322 "screen.yacc"
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

  case 177:

/* Line 1464 of yacc.c  */
#line 1346 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1354 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1355 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 1356 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 1357 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 1362 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 1367 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 1372 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 1377 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1378 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 1379 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1380 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 1381 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1382 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 1383 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 1384 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1385 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); 
#ifdef DEBUG
A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); 
#endif
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1390 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; 
#ifdef DEBUG
A4GL_debug("dynamic=-1"); 
#endif
}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1395 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 1397 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1399 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1400 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1401 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1402 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1403 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1404 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 1405 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 1406 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1407 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 1408 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1409 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1410 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1414 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1421 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 1422 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1423 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1424 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1425 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1426 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1427 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1428 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1429 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"left"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1430 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"right"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1431 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"center"); }
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 1432 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 1433 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1434 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1435 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1436 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1437 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1438 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1439 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1440 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,(yyvsp[(3) - (3)].str)); }
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1441 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1442 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1443 "screen.yacc"
    { A4GL_get_fld()->not_null=1;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1445 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1446 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1447 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1448 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 1449 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 1450 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_HEADER,(yyvsp[(3) - (3)].str)); }
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1451 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1457 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1458 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1459 "screen.yacc"
    {sprintf((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1460 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));
	if (strcasecmp((yyvsp[(1) - (1)].str),"current")==0) {
		int a;
		if (((A4GL_get_fld()->datatype)&DTYPE_MASK)==DTYPE_DTIME) {
			a=A4GL_get_fld()->dtype_size;
			sprintf((yyval.str),"\n%s%x",(yyvsp[(1) - (1)].str), a);
		}
	}
}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1473 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1477 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1478 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1479 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1480 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1481 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 1482 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1483 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1484 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1486 "screen.yacc"
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

  case 255:

/* Line 1464 of yacc.c  */
#line 1521 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1522 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1523 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1524 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1525 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1526 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1527 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1540 "screen.yacc"
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

  case 269:

/* Line 1464 of yacc.c  */
#line 1550 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1556 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1567 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1567 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 1572 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1575 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1581 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1584 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1594 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1598 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1602 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 1606 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 1610 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 1616 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 1620 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 1623 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 1627 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 1627 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 1634 "screen.yacc"
    {colno++;}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 1635 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 1648 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 1660 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 1662 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 1673 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 1677 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=atol((yyvsp[(3) - (4)].str));
}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 1681 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 1685 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 1689 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 1693 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 1697 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 1701 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 1707 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 1711 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 1715 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 1719 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 1723 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 1727 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 1731 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 1734 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 1741 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 1745 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 1750 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 1754 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 1761 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 1762 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 1764 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 1772 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 1775 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 1781 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 1788 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 1789 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 1790 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 1791 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 1797 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 1800 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 1801 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 1804 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 1806 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 1812 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 1816 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
#endif
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 1823 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 1831 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 1834 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 1835 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 1836 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 1837 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 1838 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 1839 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 1841 "screen.yacc"
    {
#ifdef DEBUG
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
#endif
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 1850 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 1851 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 1854 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 1857 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 1861 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 1862 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 1863 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 1864 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 1865 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 1866 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 1868 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
#endif
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 1875 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 1879 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
#endif
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 1888 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 1888 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 1894 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 1901 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 1904 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 1910 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 1911 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 1912 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 1913 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 1914 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 1915 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 1916 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 1917 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 1918 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 1919 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 1920 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 1921 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 1922 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 1925 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 1932 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 1933 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 1934 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 1942 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 1946 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 1966 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 1976 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 1983 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 1992 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 1995 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"",0);
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2014 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2021 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2029 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2034 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2042 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2046 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2051 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2056 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2061 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2066 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2071 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2080 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 2089 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2090 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2099 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2107 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2113 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2119 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2125 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2133 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2138 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2148 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2158 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2164 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 2170 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 2176 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 2186 "screen.yacc"
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

  case 435:

/* Line 1464 of yacc.c  */
#line 2198 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2206 "screen.yacc"
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

  case 437:

/* Line 1464 of yacc.c  */
#line 2218 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 2226 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 2227 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2228 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2232 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2233 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 2234 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 2235 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 2236 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 2237 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 447:

/* Line 1464 of yacc.c  */
#line 2238 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 448:

/* Line 1464 of yacc.c  */
#line 2241 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2248 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2259 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2263 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2270 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2278 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2284 "screen.yacc"
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

  case 455:

/* Line 1464 of yacc.c  */
#line 2296 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2297 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2303 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2309 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2317 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2325 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str));}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2330 "screen.yacc"
    {strcpy((yyval.str),"AND");}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2331 "screen.yacc"
    {strcpy((yyval.str),"OR");}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2347 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2349 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2350 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2351 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2352 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2353 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2356 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2357 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2358 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2359 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2360 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2361 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2362 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2363 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2364 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2365 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2366 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2367 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2368 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2369 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2370 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2371 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2377 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2378 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2379 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2380 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2381 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2384 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2388 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1464 of yacc.c  */
#line 6989 "y.tab.c"
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
#line 2400 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




