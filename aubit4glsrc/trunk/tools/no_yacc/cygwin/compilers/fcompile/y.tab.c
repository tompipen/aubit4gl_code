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
/*#define YYLEX_PARAM yystate */
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
     KW_NOSHOW = 448,
     KW_TEXTEDIT = 449,
     KW_BUTTONEDIT = 450,
     KW_LABEL = 451,
     KW_EDIT = 452,
     KW_DATEEDIT = 453,
     KW_SCROLL = 454,
     KW_IMAGE = 455,
     KW_FONTPITCH = 456,
     KW_FIXED = 457,
     KW_VARIABLE = 458,
     KW_WANTRETURNS = 459,
     KW_WANTNORETURNS = 460,
     KW_WANTTABS = 461,
     KW_AUTOSCALE = 462,
     KW_PIXELWIDTH = 463,
     KW_PIXELHEIGHT = 464,
     KW_BORDER = 465,
     KW_SCROLLBARS_BOTH = 466,
     KW_SCROLLBARS_V = 467,
     KW_SCROLLBARS_H = 468,
     KW_STRETCH_Y = 469,
     KW_STRETCH_BOTH = 470,
     KW_ITEMS = 471,
     KW_VALUEMAX = 472,
     KW_VALUEMIN = 473,
     KW_PROGRESSBAR = 474,
     KW_COMBOBOX = 475,
     OPTIONS = 476,
     KW_BROWSER = 477,
     KW_VALUECHECKED = 478,
     KW_VALUEUNCHECKED = 479,
     KW_CHECKBOX = 480,
     KW_LINEISODD = 481,
     KW_LINEISEVEN = 482
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
#define KW_NOSHOW 448
#define KW_TEXTEDIT 449
#define KW_BUTTONEDIT 450
#define KW_LABEL 451
#define KW_EDIT 452
#define KW_DATEEDIT 453
#define KW_SCROLL 454
#define KW_IMAGE 455
#define KW_FONTPITCH 456
#define KW_FIXED 457
#define KW_VARIABLE 458
#define KW_WANTRETURNS 459
#define KW_WANTNORETURNS 460
#define KW_WANTTABS 461
#define KW_AUTOSCALE 462
#define KW_PIXELWIDTH 463
#define KW_PIXELHEIGHT 464
#define KW_BORDER 465
#define KW_SCROLLBARS_BOTH 466
#define KW_SCROLLBARS_V 467
#define KW_SCROLLBARS_H 468
#define KW_STRETCH_Y 469
#define KW_STRETCH_BOTH 470
#define KW_ITEMS 471
#define KW_VALUEMAX 472
#define KW_VALUEMIN 473
#define KW_PROGRESSBAR 474
#define KW_COMBOBOX 475
#define OPTIONS 476
#define KW_BROWSER 477
#define KW_VALUECHECKED 478
#define KW_VALUEUNCHECKED 479
#define KW_CHECKBOX 480
#define KW_LINEISODD 481
#define KW_LINEISEVEN 482




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 83 "screen.yacc"

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
#line 673 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 685 "y.tab.c"

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
#define YYLAST   902

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  228
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  165
/* YYNRULES -- Number of rules.  */
#define YYNRULES  498
/* YYNRULES -- Number of states.  */
#define YYNSTATES  820

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   482

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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227
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
     128,   133,   137,   139,   141,   143,   147,   151,   153,   157,
     161,   163,   166,   170,   171,   173,   175,   178,   180,   182,
     184,   186,   188,   190,   191,   197,   199,   202,   203,   207,
     208,   213,   214,   215,   216,   226,   227,   229,   230,   233,
     238,   239,   241,   243,   246,   248,   250,   252,   254,   256,
     258,   260,   262,   264,   266,   268,   270,   273,   274,   279,
     281,   282,   287,   288,   292,   294,   297,   301,   304,   305,
     308,   310,   314,   318,   324,   328,   332,   336,   338,   341,
     342,   344,   346,   348,   350,   352,   354,   356,   358,   360,
     362,   364,   365,   371,   373,   376,   380,   382,   384,   385,
     386,   393,   394,   398,   404,   408,   410,   411,   417,   421,
     424,   429,   432,   437,   441,   443,   448,   451,   452,   454,
     456,   460,   464,   466,   470,   472,   476,   478,   483,   486,
     488,   491,   492,   495,   497,   501,   503,   508,   511,   516,
     520,   524,   528,   532,   538,   542,   548,   550,   552,   556,
     562,   566,   570,   574,   576,   581,   583,   585,   587,   589,
     593,   597,   599,   601,   603,   605,   607,   609,   611,   613,
     616,   619,   621,   623,   625,   627,   629,   631,   635,   639,
     641,   645,   649,   653,   657,   661,   665,   667,   669,   671,
     673,   675,   681,   685,   689,   693,   695,   699,   703,   707,
     711,   715,   719,   723,   725,   727,   729,   731,   733,   736,
     738,   740,   742,   744,   746,   748,   750,   752,   754,   756,
     758,   760,   762,   764,   766,   768,   769,   773,   775,   778,
     780,   783,   786,   788,   789,   799,   812,   814,   816,   817,
     820,   821,   823,   824,   826,   828,   833,   835,   839,   840,
     842,   844,   848,   852,   856,   860,   862,   866,   868,   870,
     871,   873,   875,   878,   880,   882,   884,   885,   890,   892,
     897,   899,   901,   903,   905,   907,   910,   913,   916,   919,
     921,   923,   925,   927,   929,   931,   935,   937,   941,   943,
     946,   949,   951,   953,   955,   957,   959,   961,   965,   969,
     971,   973,   975,   977,   979,   980,   984,   990,   991,   995,
     996,  1000,  1002,  1005,  1007,  1009,  1011,  1013,  1015,  1017,
    1020,  1022,  1023,  1027,  1029,  1031,  1033,  1035,  1037,  1039,
    1041,  1043,  1046,  1047,  1051,  1052,  1054,  1057,  1059,  1063,
    1067,  1069,  1071,  1075,  1079,  1083,  1087,  1092,  1096,  1099,
    1102,  1104,  1110,  1116,  1119,  1123,  1125,  1127,  1129,  1131,
    1133,  1135,  1139,  1142,  1144,  1147,  1155,  1157,  1161,  1165,
    1167,  1169,  1171,  1177,  1183,  1186,  1189,  1191,  1193,  1195,
    1197,  1199,  1201,  1203,  1209,  1210,  1213,  1215,  1220,  1223,
    1227,  1230,  1234,  1238,  1240,  1243,  1246,  1250,  1254,  1259,
    1261,  1264,  1266,  1269,  1271,  1273,  1275,  1277,  1279,  1281,
    1283,  1285,  1287,  1289,  1291,  1295,  1299,  1301,  1306,  1307,
    1314,  1315,  1317,  1319,  1323,  1325,  1327,  1331,  1333,  1335,
    1338,  1341,  1343,  1346,  1350,  1355,  1359,  1363,  1367,  1371,
    1375,  1379,  1383,  1387,  1391,  1396,  1400,  1403,  1406,  1412,
    1418,  1425,  1427,  1429,  1431,  1433,  1435,  1437,  1439
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     229,     0,    -1,   231,   230,   236,   280,   285,   312,    -1,
      -1,    48,    47,    -1,    21,    35,    -1,    21,   235,    41,
      42,    43,    -1,    21,    35,    41,    42,    43,    -1,    21,
     235,    -1,    30,    -1,    34,    -1,    30,    -1,    34,    -1,
      30,    -1,    34,    -1,   180,    -1,   180,    39,   233,    -1,
     232,    -1,   232,    39,   233,    -1,   261,    -1,   259,    -1,
     184,   243,   252,   256,    27,    -1,   183,   243,   252,   256,
      27,    -1,   186,   243,   252,   256,    27,    -1,   188,   243,
     252,   241,    27,    -1,   242,    -1,   241,   242,    -1,   182,
     243,   252,   256,    27,    -1,    -1,   233,    -1,    -1,    -1,
      -1,   185,   245,   243,   252,    31,   246,   272,    32,   247,
      27,    -1,    -1,    -1,    -1,   187,   249,   243,   252,    31,
     250,   272,    32,   251,    27,    -1,    -1,    -1,    53,   253,
     255,    54,    -1,   189,    46,    47,    -1,   191,    -1,   193,
      -1,   192,    -1,   116,    46,    47,    -1,   181,    46,    30,
      -1,   210,    -1,   209,    46,    29,    -1,   208,    46,    29,
      -1,   254,    -1,   255,   254,    -1,   255,    60,   254,    -1,
      -1,   257,    -1,   258,    -1,   257,   258,    -1,   237,    -1,
     238,    -1,   239,    -1,   240,    -1,   244,    -1,   248,    -1,
      -1,   190,   252,   260,   258,   271,    -1,   262,    -1,   261,
     262,    -1,    -1,    24,   263,   265,    -1,    -1,    23,    47,
     264,   265,    -1,    -1,    -1,    -1,   270,   266,   269,    31,
     267,   272,    32,   268,   271,    -1,    -1,   179,    -1,    -1,
      25,    29,    -1,    25,    29,    22,    29,    -1,    -1,    27,
      -1,   274,    -1,   272,   274,    -1,    30,    -1,   273,    -1,
     276,    -1,   153,    -1,    17,    -1,    45,    -1,    47,    -1,
     275,    -1,   152,    -1,   124,    -1,   119,    -1,    16,    -1,
     275,    16,    -1,    -1,    26,   277,   278,    28,    -1,   330,
      -1,    -1,   278,    45,   279,   330,    -1,    -1,    44,   281,
     271,    -1,   282,    -1,   281,   282,    -1,   281,    60,   282,
      -1,   233,   283,    -1,    -1,    46,   284,    -1,   233,    -1,
     233,    38,   233,    -1,   233,    39,   233,    -1,   233,    39,
     233,    38,   233,    -1,   233,    40,   233,    -1,    47,    40,
     233,    -1,    20,   286,   271,    -1,   288,    -1,   286,   288,
      -1,    -1,   197,    -1,   194,    -1,   196,    -1,   198,    -1,
     195,    -1,   148,    -1,   200,    -1,   219,    -1,   220,    -1,
     225,    -1,   222,    -1,    -1,   287,   329,   289,   290,    49,
      -1,   292,    -1,   290,   292,    -1,   290,    49,   292,    -1,
      46,    -1,    38,    -1,    -1,    -1,   291,   293,   298,   295,
     294,   306,    -1,    -1,    26,    29,    28,    -1,    26,    29,
      60,    29,    28,    -1,   297,   130,    42,    -1,   297,    -1,
      -1,    62,    74,   233,    40,   233,    -1,    62,    74,   233,
      -1,    62,   332,    -1,    35,    40,   325,   296,    -1,   150,
     296,    -1,   150,   151,    43,   296,    -1,   233,    40,   233,
      -1,   233,    -1,    55,   233,    40,   233,    -1,    55,   233,
      -1,    -1,   300,    -1,   301,    -1,   300,    60,   301,    -1,
     302,    46,   303,    -1,   329,    -1,   233,    40,   233,    -1,
     233,    -1,   233,    40,   233,    -1,   233,    -1,    55,   233,
      40,   233,    -1,    55,   233,    -1,    51,    -1,    60,    51,
      -1,    -1,    60,   307,    -1,   308,    -1,   307,    60,   308,
      -1,    90,    -1,    91,    46,   310,   351,    -1,    52,   304,
      -1,    50,   299,   305,   304,    -1,    92,    46,    47,    -1,
      93,    46,   309,    -1,   221,    46,   309,    -1,    95,    74,
     233,    -1,    95,    74,   233,    40,   233,    -1,    94,    74,
     233,    -1,    94,    74,   233,    40,   233,    -1,    96,    -1,
      97,    -1,    98,    46,    47,    -1,    99,    46,    53,   333,
      54,    -1,   122,    46,    47,    -1,   123,    46,    47,    -1,
     181,    46,   233,    -1,   100,    -1,    37,    25,    46,    29,
      -1,    37,    -1,   121,    -1,   102,    -1,   101,    -1,   103,
      46,    47,    -1,   104,    46,    47,    -1,   105,    -1,   113,
      -1,    84,    -1,   107,    -1,   106,    -1,   178,    -1,   177,
      -1,   108,    -1,   108,   109,    -1,   108,   110,    -1,   191,
      -1,   193,    -1,   207,    -1,   205,    -1,   204,    -1,   206,
      -1,   201,    46,   202,    -1,   201,    46,   203,    -1,   199,
      -1,   200,    46,    47,    -1,   143,    46,    85,    -1,   143,
      46,   177,    -1,   143,    46,   144,    -1,   209,    46,    29,
      -1,   208,    46,    29,    -1,   211,    -1,   212,    -1,   213,
      -1,   214,    -1,   215,    -1,   216,    46,    53,   334,    54,
      -1,   145,    46,    29,    -1,   217,    46,    29,    -1,   218,
      46,    29,    -1,   146,    -1,   223,    46,    47,    -1,   224,
      46,    47,    -1,   223,    46,    29,    -1,   224,    46,    29,
      -1,   116,    46,    47,    -1,   120,    46,    47,    -1,   189,
      46,    47,    -1,    47,    -1,    29,    -1,    30,    -1,   118,
      -1,   311,    -1,   310,   311,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    29,    -1,    84,    -1,    89,    -1,    83,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    -1,    19,
     313,   271,    -1,   314,    -1,   313,   314,    -1,   315,    -1,
     315,    49,    -1,    63,    47,    -1,   365,    -1,    -1,    24,
      59,   316,   320,    53,   321,    54,   317,   319,    -1,   149,
      53,    29,    60,    29,    54,   111,    53,    29,    60,    29,
      54,    -1,   358,    -1,   381,    -1,    -1,   112,   147,    -1,
      -1,    55,    -1,    -1,    49,    -1,   233,    -1,   233,    26,
      29,    28,    -1,   324,    -1,   321,   322,   324,    -1,    -1,
      60,    -1,   233,    -1,   233,    40,   233,    -1,    35,    40,
     233,    -1,   233,    40,    55,    -1,    35,    40,    55,    -1,
     323,    -1,   323,    61,   323,    -1,   233,    -1,    27,    -1,
      -1,   327,    -1,   328,    -1,   327,   328,    -1,   152,    -1,
     153,    -1,   234,    -1,    -1,   326,   234,   331,   326,    -1,
      64,    -1,    64,    53,    29,    54,    -1,    65,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,   339,    -1,
      71,   339,    -1,    72,   346,    -1,    73,   340,    -1,   114,
      -1,   115,    -1,   116,    -1,   117,    -1,   148,    -1,   337,
      -1,   333,    60,   337,    -1,   336,    -1,   334,    60,   336,
      -1,    29,    -1,    57,    29,    -1,    58,    29,    -1,    47,
      -1,    30,    -1,    16,    -1,   335,    -1,    42,    -1,   338,
      -1,   338,   111,   338,    -1,   338,    38,   338,    -1,    47,
      -1,    30,    -1,    16,    -1,   335,    -1,    42,    -1,    -1,
      53,    29,    54,    -1,    53,    29,    60,    29,    54,    -1,
      -1,   343,   111,   345,    -1,    -1,    53,    29,    54,    -1,
      29,    -1,   344,   341,    -1,   136,    -1,   137,    -1,   138,
      -1,   139,    -1,   140,    -1,   141,    -1,   142,   350,    -1,
     344,    -1,    -1,   347,   111,   348,    -1,   349,    -1,   349,
      -1,   136,    -1,   137,    -1,   138,    -1,   139,    -1,   140,
      -1,   141,    -1,   142,   350,    -1,    -1,    53,   342,    54,
      -1,    -1,   352,    -1,   129,   353,    -1,   354,    -1,   354,
     127,   354,    -1,   354,   126,   354,    -1,   226,    -1,   227,
      -1,   355,   125,   355,    -1,   355,     8,   355,    -1,   355,
       9,   355,    -1,   355,    74,   355,    -1,   355,   130,    74,
     355,    -1,   355,    46,   355,    -1,   355,   134,    -1,   355,
     135,    -1,   355,    -1,   355,   131,   355,   127,   355,    -1,
     355,   132,    53,   357,    54,    -1,   130,   354,    -1,    53,
     354,    54,    -1,   356,    -1,    29,    -1,    47,    -1,   133,
      -1,    30,    -1,   355,    -1,   357,    60,   355,    -1,    18,
     359,    -1,   360,    -1,   359,   360,    -1,     8,   361,     9,
     318,     8,   361,     9,    -1,   362,    -1,   361,    60,   362,
      -1,   363,    40,   364,    -1,   364,    -1,   233,    -1,   232,
      -1,   155,   375,   160,   379,   373,    -1,   156,   376,   160,
     379,   373,    -1,   165,   382,    -1,   164,   382,    -1,   369,
      -1,   374,    -1,   367,    -1,   370,    -1,   371,    -1,   382,
      -1,   372,    -1,   172,   387,   173,   366,   368,    -1,    -1,
     174,   366,    -1,   168,    -1,   169,   329,    46,   387,    -1,
     171,   329,    -1,   171,    46,   329,    -1,   171,   170,    -1,
     171,    46,   170,    -1,   175,   373,    27,    -1,   366,    -1,
     373,   366,    -1,    92,    47,    -1,    92,   167,    47,    -1,
      92,    84,    47,    -1,    92,   167,    84,    47,    -1,   377,
      -1,   375,   377,    -1,   378,    -1,   376,   378,    -1,   157,
      -1,   158,    -1,   159,    -1,   157,    -1,   161,    -1,   162,
      -1,   163,    -1,   159,    -1,    95,    -1,   158,    -1,   380,
      -1,   379,   322,   380,    -1,   363,    40,   364,    -1,   364,
      -1,   363,   154,   363,   319,    -1,    -1,   166,   233,    53,
     383,   384,    54,    -1,    -1,   385,    -1,   386,    -1,   385,
      60,   386,    -1,   387,    -1,   389,    -1,   387,   388,   387,
      -1,   127,    -1,   126,    -1,    58,   387,    -1,    57,   387,
      -1,   391,    -1,   130,   387,    -1,    53,   387,    54,    -1,
     390,    53,   384,    54,    -1,   176,   160,   329,    -1,   387,
     125,   387,    -1,   387,     8,   387,    -1,   387,     9,   387,
      -1,   387,    55,   387,    -1,   387,    57,   387,    -1,   387,
      58,   387,    -1,   387,    56,   387,    -1,   387,    74,   387,
      -1,   387,   130,    74,   387,    -1,   387,    46,   387,    -1,
     387,   134,    -1,   387,   135,    -1,   387,   131,   387,   127,
     387,    -1,   387,   132,    53,   392,    54,    -1,   387,   130,
     132,    53,   392,    54,    -1,   233,    -1,   329,    -1,    29,
      -1,    47,    -1,   133,    -1,    42,    -1,   391,    -1,   392,
      60,   391,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   154,   154,   163,   164,   170,   173,   179,   182,   193,
     194,   199,   200,   204,   209,   214,   215,   216,   217,   222,
     226,   233,   243,   252,   265,   273,   283,   291,   304,   305,
     312,   315,   318,   311,   334,   337,   340,   333,   354,   357,
     357,   363,   366,   369,   372,   375,   378,   381,   384,   385,
     389,   390,   391,   395,   404,   410,   420,   427,   429,   431,
     433,   435,   437,   442,   442,   452,   452,   455,   455,   468,
     468,   487,   489,   492,   487,   497,   497,   502,   503,   504,
     516,   517,   522,   523,   526,   541,   553,   554,   565,   576,
     589,   601,   612,   617,   620,   628,   629,   635,   634,   659,
     662,   662,   680,   681,   684,   685,   686,   689,   696,   697,
     700,   701,   702,   704,   705,   706,   712,   716,   716,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   737,   736,   767,   768,   769,   772,   772,   775,   779,
     775,  1111,  1112,  1118,  1128,  1129,  1132,  1133,  1136,  1139,
    1144,  1155,  1169,  1183,  1192,  1214,  1223,  1235,  1240,  1246,
    1255,  1264,  1271,  1273,  1276,  1282,  1283,  1284,  1285,  1288,
    1289,  1293,  1294,  1298,  1298,  1301,  1306,  1328,  1352,  1360,
    1361,  1362,  1363,  1368,  1373,  1378,  1383,  1384,  1385,  1386,
    1387,  1388,  1389,  1390,  1391,  1396,  1401,  1403,  1405,  1406,
    1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,  1416,
    1420,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,
    1436,  1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,
    1446,  1447,  1448,  1449,  1450,  1451,  1453,  1454,  1455,  1456,
    1457,  1458,  1459,  1465,  1466,  1467,  1468,  1480,  1481,  1485,
    1486,  1487,  1488,  1489,  1490,  1491,  1492,  1494,  1529,  1530,
    1531,  1532,  1533,  1534,  1535,  1539,  1540,  1543,  1543,  1545,
    1545,  1548,  1558,  1564,  1564,  1567,  1568,  1569,  1573,  1573,
    1575,  1575,  1578,  1578,  1580,  1583,  1589,  1592,  1596,  1597,
    1601,  1605,  1609,  1613,  1617,  1624,  1624,  1628,  1631,  1635,
    1635,  1638,  1638,  1642,  1643,  1656,  1668,  1668,  1681,  1685,
    1689,  1693,  1697,  1701,  1705,  1709,  1715,  1719,  1723,  1727,
    1731,  1735,  1739,  1742,  1749,  1749,  1753,  1753,  1758,  1758,
    1758,  1762,  1769,  1770,  1771,  1772,  1779,  1780,  1783,  1789,
    1796,  1797,  1798,  1799,  1805,  1808,  1813,  1816,  1817,  1824,
    1828,  1835,  1843,  1846,  1847,  1848,  1849,  1850,  1851,  1852,
    1860,  1862,  1863,  1866,  1869,  1873,  1874,  1875,  1876,  1877,
    1878,  1879,  1887,  1891,  1900,  1900,  1906,  1912,  1913,  1916,
    1925,  1926,  1927,  1928,  1929,  1930,  1931,  1932,  1933,  1934,
    1935,  1936,  1937,  1938,  1939,  1942,  1949,  1950,  1951,  1956,
    1959,  1963,  1975,  1978,  1979,  1983,  1993,  2000,  2009,  2012,
    2024,  2027,  2031,  2038,  2046,  2051,  2059,  2063,  2068,  2073,
    2078,  2083,  2088,  2097,  2106,  2107,  2112,  2115,  2123,  2129,
    2135,  2141,  2150,  2155,  2165,  2175,  2181,  2187,  2193,  2203,
    2215,  2223,  2235,  2243,  2244,  2245,  2249,  2250,  2251,  2252,
    2253,  2254,  2255,  2258,  2265,  2276,  2280,  2287,  2295,  2295,
    2313,  2314,  2320,  2326,  2334,  2341,  2342,  2347,  2348,  2364,
    2366,  2367,  2368,  2369,  2370,  2373,  2374,  2375,  2376,  2377,
    2378,  2379,  2380,  2381,  2382,  2383,  2384,  2385,  2386,  2387,
    2388,  2391,  2394,  2395,  2396,  2397,  2398,  2401,  2405
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
  "KW_HIDDEN", "KW_AUTOSIZE", "KW_NOSHOW", "KW_TEXTEDIT", "KW_BUTTONEDIT",
  "KW_LABEL", "KW_EDIT", "KW_DATEEDIT", "KW_SCROLL", "KW_IMAGE",
  "KW_FONTPITCH", "KW_FIXED", "KW_VARIABLE", "KW_WANTRETURNS",
  "KW_WANTNORETURNS", "KW_WANTTABS", "KW_AUTOSCALE", "KW_PIXELWIDTH",
  "KW_PIXELHEIGHT", "KW_BORDER", "KW_SCROLLBARS_BOTH", "KW_SCROLLBARS_V",
  "KW_SCROLLBARS_H", "KW_STRETCH_Y", "KW_STRETCH_BOTH", "KW_ITEMS",
  "KW_VALUEMAX", "KW_VALUEMIN", "KW_PROGRESSBAR", "KW_COMBOBOX", "OPTIONS",
  "KW_BROWSER", "KW_VALUECHECKED", "KW_VALUEUNCHECKED", "KW_CHECKBOX",
  "KW_LINEISODD", "KW_LINEISEVEN", "$accept", "form_def",
  "encoding_section", "database_section", "named_or_kw_st_pc",
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
     475,   476,   477,   478,   479,   480,   481,   482
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   228,   229,   230,   230,   231,   231,   231,   231,   232,
     232,   233,   233,   234,   234,   235,   235,   235,   235,   236,
     236,   237,   238,   239,   240,   241,   241,   242,   243,   243,
     245,   246,   247,   244,   249,   250,   251,   248,   252,   253,
     252,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     255,   255,   255,   256,   256,   257,   257,   258,   258,   258,
     258,   258,   258,   260,   259,   261,   261,   263,   262,   264,
     262,   266,   267,   268,   265,   269,   269,   270,   270,   270,
     271,   271,   272,   272,   273,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   275,   275,   277,   276,   278,
     279,   278,   280,   280,   281,   281,   281,   282,   283,   283,
     284,   284,   284,   284,   284,   284,   285,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   289,   288,   290,   290,   290,   291,   291,   293,   294,
     292,   295,   295,   295,   296,   296,   297,   297,   297,   297,
     298,   298,   298,   298,   298,   298,   298,   299,   299,   300,
     300,   301,   302,   303,   303,   304,   304,   304,   304,   305,
     305,   306,   306,   307,   307,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   309,   309,   309,   309,   310,   310,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   312,   312,   313,   313,   314,
     314,   315,   315,   316,   315,   315,   315,   315,   317,   317,
     318,   318,   319,   319,   320,   320,   321,   321,   322,   322,
     323,   323,   323,   323,   323,   324,   324,   325,   325,   326,
     326,   327,   327,   328,   328,   329,   331,   330,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   333,   333,   334,   334,   335,   335,
     335,   336,   336,   336,   336,   336,   337,   337,   337,   338,
     338,   338,   338,   338,   339,   339,   339,   340,   340,   341,
     341,   342,   343,   344,   344,   344,   344,   344,   344,   344,
     345,   346,   346,   347,   348,   349,   349,   349,   349,   349,
     349,   349,   350,   350,   351,   351,   352,   353,   353,   353,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   355,   355,   355,   355,   356,
     357,   357,   358,   359,   359,   360,   361,   361,   362,   362,
     363,   364,   365,   365,   365,   365,   366,   366,   366,   366,
     366,   366,   366,   367,   368,   368,   369,   370,   371,   371,
     371,   371,   372,   373,   373,   374,   374,   374,   374,   375,
     375,   376,   376,   377,   377,   377,   378,   378,   378,   378,
     378,   378,   378,   379,   379,   380,   380,   381,   383,   382,
     384,   384,   385,   385,   386,   387,   387,   388,   388,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   390,   391,   391,   391,   391,   391,   392,   392
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     5,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     5,     5,     5,     5,     1,     2,     5,     0,     1,
       0,     0,     0,    10,     0,     0,     0,    10,     0,     0,
       4,     3,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     2,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     0,     5,     1,     2,     0,     3,     0,
       4,     0,     0,     0,     9,     0,     1,     0,     2,     4,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     4,     1,
       0,     4,     0,     3,     1,     2,     3,     2,     0,     2,
       1,     3,     3,     5,     3,     3,     3,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     1,     2,     3,     1,     1,     0,     0,
       6,     0,     3,     5,     3,     1,     0,     5,     3,     2,
       4,     2,     4,     3,     1,     4,     2,     0,     1,     1,
       3,     3,     1,     3,     1,     3,     1,     4,     2,     1,
       2,     0,     2,     1,     3,     1,     4,     2,     4,     3,
       3,     3,     3,     5,     3,     5,     1,     1,     3,     5,
       3,     3,     3,     1,     4,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     5,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     1,     2,     1,
       2,     2,     1,     0,     9,    12,     1,     1,     0,     2,
       0,     1,     0,     1,     1,     4,     1,     3,     0,     1,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     0,     4,     1,     4,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     0,     3,     5,     0,     3,     0,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     0,     1,     2,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     4,     3,     2,     2,
       1,     5,     5,     2,     3,     1,     1,     1,     1,     1,
       1,     3,     2,     1,     2,     7,     1,     3,     3,     1,
       1,     1,     5,     5,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     5,     0,     2,     1,     4,     2,     3,
       2,     3,     3,     1,     2,     2,     3,     3,     4,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     4,     0,     6,
       0,     1,     1,     3,     1,     1,     3,     1,     1,     2,
       2,     1,     2,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     2,     2,     5,     5,
       6,     1,     1,     1,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     3,     9,    10,     5,    15,    17,     8,
       1,     0,     0,     0,     0,     0,     0,     4,     0,    67,
      38,   102,    20,    19,    65,     0,    11,    12,    16,    18,
       0,    69,    77,    39,    63,     0,     0,    66,     7,     6,
      77,     0,    68,    71,     0,     0,   108,    80,   104,   119,
     265,    70,    78,    75,     0,     0,     0,    42,    44,    43,
       0,     0,    47,    50,     0,    28,    28,    30,    28,    34,
      28,    57,    58,    59,    60,    61,    62,    80,     0,   107,
      81,     0,   103,   105,   125,   121,   124,   122,   120,   123,
     126,   127,   128,   130,   129,    80,     0,   117,     0,     2,
       0,    76,     0,     0,     0,     0,     0,     0,    40,     0,
      51,    29,    38,    38,    28,    38,    28,    38,    64,     0,
     110,   109,   106,   116,   118,    13,    14,   305,   131,     0,
       0,     0,     0,     0,     0,     0,     0,   410,    80,   267,
     269,   276,     0,   272,   277,    79,    72,    45,    46,    41,
      49,    48,    52,    53,    53,    38,    53,    38,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   273,   271,     0,
     443,   444,   445,     0,   439,   451,   446,   452,   450,   447,
     448,   449,     0,   441,     0,   415,   414,   266,   268,   270,
       0,     0,     0,    54,    55,     0,     0,     0,     0,    28,
       0,    25,   115,   111,   112,   114,   137,   136,     0,   138,
     133,     9,    10,   411,     0,   406,     0,   409,   404,     0,
       0,     0,   440,     0,   442,     0,   282,    95,    88,    97,
      84,    89,    90,    94,    93,    92,    87,     0,    85,    82,
      91,    86,    22,    56,    21,    31,    23,    35,    38,    24,
      26,     0,   132,   134,     0,   280,     0,     0,   284,     0,
       0,     0,   456,   288,   453,   288,   458,   283,   457,   299,
      73,    83,    96,     0,     0,    53,   113,   135,     0,     0,
     146,   154,   141,   281,     0,   407,   408,     0,     0,     0,
       0,   289,     0,   426,     0,     0,     0,     0,     0,   433,
     418,   416,   419,   420,   422,   412,   417,   421,   413,   460,
     303,   304,     0,     0,   300,   301,    99,    80,     0,     0,
       0,     0,   156,     0,     0,   151,   145,     0,     0,   139,
       0,     0,     0,   290,   288,   295,   286,     0,   455,   435,
       0,     0,     0,     0,   430,   428,   493,    13,    14,   496,
     494,     0,     0,     0,     0,   495,     0,   491,   492,     0,
     465,     0,   471,     0,   454,   434,     0,   461,   462,   464,
      98,   100,   306,   302,    74,    32,    36,    27,   298,   297,
     146,     0,   308,   310,   311,   312,   313,   314,   344,   344,
     361,   347,     0,   319,   320,   321,   322,   323,   149,   146,
       0,   153,     0,   171,     0,   285,     0,     0,   278,     0,
       0,     0,   437,   436,     0,     0,   431,   429,     0,   470,
     469,   472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,   467,     0,     0,     0,   486,   487,     0,
       0,   460,   432,   459,     0,   299,   299,     0,     0,   150,
     155,     0,     0,   315,   316,   365,   366,   367,   368,   369,
     370,   372,   317,     0,   363,   353,   354,   355,   356,   357,
     358,   372,   318,     0,   349,   148,   152,   144,   142,     0,
       0,   140,   405,   294,   292,   293,   291,     0,   282,   287,
     296,     0,   438,   427,   473,   475,   477,   478,   485,   479,
     482,   480,   481,   483,   476,     0,     0,     0,     0,   424,
     466,     0,   463,   101,   307,    33,    37,     0,     0,     0,
     371,     0,   359,     0,     0,   352,     0,     0,   195,   157,
       0,   203,   175,     0,     0,     0,     0,     0,   186,   187,
       0,     0,   193,   198,   197,     0,     0,   201,   205,   204,
     208,   202,     0,     0,   196,     0,     0,     0,     0,   235,
     207,   206,     0,     0,   211,   212,   219,     0,     0,   215,
     214,   216,   213,     0,     0,   226,   227,   228,   229,   230,
       0,     0,     0,     0,     0,     0,   172,   173,   279,   274,
       0,   484,     0,     0,   497,     0,     0,   423,   474,   309,
     345,     0,   351,     0,   362,   364,   360,   348,     0,   147,
     143,     0,     0,   158,   159,     0,   162,     0,   166,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,   489,     0,   425,     0,   373,   350,     0,
     169,     0,     0,     0,     0,   168,     0,   257,   249,   250,
     251,   252,   253,   254,   255,   256,   260,   258,   261,   262,
     263,   264,   259,   374,   247,   179,   244,   245,   243,   246,
     180,   184,   182,   188,     0,   199,   200,   240,   241,   190,
     191,   221,   223,   222,   232,   192,   242,   220,   217,   218,
     225,   224,     0,   233,   234,   181,   238,   236,   239,   237,
     174,     0,   490,   498,   346,   194,   170,   178,   160,   164,
     161,     0,   165,     0,   248,   176,   375,     0,     0,   341,
     328,   340,   343,   339,     0,     0,     0,   342,   324,   336,
     333,   332,   335,   331,     0,   334,   326,   275,     0,   167,
     396,   399,   397,     0,     0,   398,   380,   381,   376,   377,
     390,   395,   185,   183,   329,   330,   189,     0,     0,     0,
     231,     0,   163,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   388,   389,   325,   338,   337,
     327,   394,   379,   378,   383,   384,   387,   385,   382,     0,
       0,     0,   386,     0,   400,     0,   391,   392,     0,   401
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,     3,   213,   357,   127,     9,    21,    71,
      72,    73,    74,   200,   201,   112,    75,   114,   273,   447,
      76,   116,   274,   448,    34,    44,    63,    64,   192,   193,
     194,    22,    45,    23,    24,    32,    40,    42,    53,   191,
     317,   102,    43,    82,   237,   238,   239,   240,   241,   269,
     312,   445,    36,    47,    48,    79,   121,    50,    95,    96,
      97,   163,   208,   209,   210,   254,   403,   329,   325,   326,
     282,   612,   613,   614,   615,   730,   619,   662,   481,   586,
     587,   690,   683,   684,    99,   138,   139,   140,   219,   488,
     284,   268,   259,   334,   298,   335,   336,   380,   313,   314,
     315,   358,   316,   446,   398,   746,   754,   747,   756,   748,
     749,   453,   472,   525,   603,   473,   474,   607,   462,   463,
     604,   464,   520,   735,   736,   768,   769,   770,   771,   815,
     141,   165,   166,   214,   215,   216,   217,   143,   299,   300,
     597,   301,   302,   303,   304,   305,   306,   173,   182,   174,
     183,   263,   264,   144,   307,   309,   366,   367,   368,   369,
     440,   360,   361,   362,   595
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -693
static const yytype_int16 yypact[] =
{
      41,   -18,    97,    68,  -693,  -693,    91,   122,   130,   173,
    -693,   148,   -16,   156,   319,   319,   186,  -693,   187,  -693,
     219,   233,  -693,    48,  -693,   237,  -693,  -693,  -693,  -693,
     249,  -693,   257,  -693,  -693,   319,   277,  -693,  -693,  -693,
     257,   282,  -693,  -693,   490,   369,   276,   176,  -693,   494,
     306,  -693,   305,   189,   335,   340,   342,  -693,  -693,  -693,
     357,   359,  -693,  -693,   294,   319,   319,  -693,   319,  -693,
     319,  -693,  -693,  -693,  -693,  -693,  -693,   380,   228,  -693,
    -693,   319,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,    -4,   343,  -693,   154,  -693,
     386,  -693,   378,   371,   397,   382,   402,   420,  -693,   490,
    -693,  -693,   219,   219,   319,   219,   319,   219,  -693,   419,
     101,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,   453,
     411,   424,   423,   240,   609,   311,   311,  -693,   345,  -693,
     431,  -693,   318,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,   369,   369,   219,   369,   219,   299,   319,
     319,   319,   319,    81,   346,   453,  -693,  -693,  -693,   455,
    -693,  -693,  -693,   307,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,   579,  -693,   319,  -693,  -693,  -693,  -693,  -693,
     319,   452,   478,   369,  -693,   481,   461,   488,   486,   319,
     -22,  -693,  -693,  -693,   480,  -693,  -693,  -693,   255,  -693,
    -693,   484,   485,  -693,    28,  -693,   489,  -693,  -693,   319,
     468,   346,  -693,   346,  -693,   477,   482,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,    78,  -693,  -693,
     520,  -693,  -693,  -693,  -693,  -693,  -693,  -693,   219,  -693,
    -693,   319,    81,  -693,    14,   491,   346,   353,   514,   495,
     518,   509,  -693,   366,  -693,   366,  -693,  -693,  -693,   198,
    -693,  -693,  -693,   452,   452,   369,  -693,  -693,   510,   319,
     -52,   522,   540,  -693,   562,  -693,  -693,   543,   336,   519,
     353,  -693,    12,  -693,   343,    -5,    56,   414,   346,  -693,
    -693,  -693,  -693,  -693,  -693,   414,  -693,  -693,   414,    56,
    -693,  -693,   250,   343,   198,  -693,  -693,   380,   270,   374,
     547,   192,   535,   661,   534,  -693,   448,   319,   552,  -693,
     346,   556,   548,   553,   194,   526,  -693,   483,  -693,  -693,
     551,    -7,   555,     5,  -693,  -693,  -693,   558,   567,  -693,
    -693,    56,    56,    56,    56,  -693,   464,  -693,  -693,   125,
    -693,   572,  -693,    95,  -693,  -693,   554,   566,  -693,   433,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
     565,   319,   576,  -693,  -693,  -693,  -693,  -693,   581,   581,
     610,   643,   319,  -693,  -693,  -693,  -693,  -693,  -693,   565,
     589,  -693,    47,   585,    46,  -693,    87,   174,   529,   336,
     336,   593,  -693,  -693,   591,    56,  -693,  -693,   465,   433,
     433,   433,   343,    56,    56,    56,    56,    56,    56,    56,
      56,    56,  -693,  -693,    -6,    56,   594,  -693,  -693,   414,
      56,    56,  -693,  -693,    56,   198,   198,   605,   622,  -693,
    -693,   639,   640,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,   598,  -693,   559,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,   598,  -693,   561,   620,   636,  -693,  -693,  -693,   648,
     239,  -693,  -693,  -693,  -693,  -693,  -693,   531,   482,  -693,
    -693,   651,  -693,   433,  -693,  -693,   629,   629,   433,   433,
     433,   433,   433,   433,   433,    56,   642,   487,    16,   523,
     433,   647,  -693,  -693,  -693,  -693,  -693,   652,   225,   664,
    -693,   610,  -693,   643,   667,  -693,   319,   674,   680,   343,
     190,  -693,  -693,   662,   663,   665,   638,   641,  -693,  -693,
     672,   675,  -693,  -693,  -693,   676,   699,  -693,  -693,  -693,
     292,  -693,   707,   711,  -693,   712,   716,   719,   723,  -693,
    -693,  -693,   727,   728,  -693,  -693,  -693,   740,   741,  -693,
    -693,  -693,  -693,   742,   759,  -693,  -693,  -693,  -693,  -693,
     760,   761,   762,   769,   773,   774,   650,  -693,  -693,  -693,
     660,   433,    16,    56,  -693,   245,   414,  -693,  -693,  -693,
    -693,   792,  -693,   768,  -693,  -693,  -693,  -693,   770,  -693,
    -693,   777,     6,   765,  -693,   780,  -693,   319,   787,  -693,
     714,   781,    13,   319,   319,   782,   778,   786,   790,  -693,
    -693,   791,   793,   795,   796,   -57,   810,   319,   797,   800,
     209,   819,   820,   798,   821,   823,    13,    54,   206,   239,
     824,   252,   433,  -693,    16,  -693,   801,  -693,  -693,   825,
    -693,   805,   190,   343,   319,   817,   319,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,   578,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,   818,   822,  -693,   586,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,   788,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,   806,  -693,  -693,  -693,  -693,  -693,  -693,  -693,   826,
    -693,   319,  -693,   -15,  -693,  -693,  -693,   319,   319,  -693,
    -693,  -693,  -693,  -693,   830,   832,   254,  -693,  -693,   -19,
    -693,  -693,  -693,  -693,   266,  -693,  -693,  -693,   319,  -693,
    -693,  -693,  -693,   -15,   -15,  -693,  -693,  -693,  -693,   287,
     505,  -693,  -693,  -693,  -693,  -693,  -693,   586,   586,   586,
    -693,   788,  -693,   809,  -693,   -15,   -15,    44,    44,    44,
      44,    44,   794,    44,   811,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,    44,
     738,    44,  -693,    44,  -693,   304,  -693,  -693,    44,  -693
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -693,  -693,  -693,  -693,   866,   -14,   557,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,   669,   157,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,   126,  -693,   -33,  -693,  -145,  -693,
     -27,  -693,  -693,  -693,   848,  -693,  -693,   833,  -693,  -693,
    -693,  -693,  -693,   -73,   151,  -693,  -190,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,   -11,  -693,  -693,  -693,  -693,  -693,
     779,  -693,  -693,  -693,  -174,  -693,  -693,  -693,  -287,  -693,
    -693,  -693,  -693,   212,  -693,  -693,   210,  -693,  -693,  -693,
     227,   231,  -693,   195,  -693,  -693,   743,  -693,  -693,  -693,
    -693,   391,  -693,  -693,   546,   472,   474,  -693,   438,  -693,
     571,   -94,   441,  -693,  -693,  -693,  -693,  -692,   106,   111,
    -345,   500,  -693,  -693,  -693,  -693,   367,  -693,  -693,  -693,
    -693,   370,   421,  -693,  -693,  -693,  -517,    23,  -693,  -693,
    -693,  -693,   729,   563,   644,   -85,    67,  -693,  -302,  -693,
    -693,  -693,  -693,  -693,  -693,  -130,  -693,  -693,  -693,   722,
     715,   673,   600,  -693,   301,  -693,   458,  -693,   457,  -272,
    -693,  -693,  -693,  -481,   310
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -120
static const yytype_int16 yytable[] =
{
      28,    29,   128,   365,   118,   249,   365,    18,    19,   195,
     323,   197,     4,   142,   760,   761,     5,     6,    77,   778,
     755,    46,   123,    80,   359,   125,  -119,   594,   701,   126,
    -119,   110,   762,    46,   253,   125,    83,   255,   763,   126,
     413,   343,   686,   687,    26,   346,   125,   271,    27,   278,
     126,   111,   111,   142,   111,   482,   111,   660,   349,   339,
     688,   365,     1,   350,   120,   187,   661,    46,   505,   279,
     122,    18,    19,   760,   761,   478,   152,   414,   277,   418,
     419,   420,   421,   716,   137,   346,   347,   702,   256,   755,
     348,   762,   779,   449,   227,   228,   340,    10,   349,   324,
     111,   717,   111,   350,   229,   226,   256,   479,   230,   351,
     270,   594,   476,   352,   353,   764,    11,    26,   765,   206,
     703,    27,   442,   231,   137,   232,   506,   207,   271,   271,
     320,   689,    13,   423,   424,   308,   261,   509,   261,   160,
     161,   162,   483,   493,    84,   202,   203,   204,   205,   355,
     137,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     199,    14,     7,   507,   280,   344,   243,   363,   510,    15,
     225,   425,   129,   723,    20,   416,   137,   765,   130,   341,
     426,   427,   428,   429,    26,   111,   354,   292,    27,   355,
      85,    86,    87,    88,    89,    17,    90,   233,    25,   430,
     342,   345,   234,    80,    26,   258,    26,   137,    27,   137,
      27,   766,   767,   261,    16,    91,    92,   131,    93,   378,
      26,    94,    26,   113,    27,   115,    27,   117,    30,   485,
     235,   236,   356,   591,    31,   718,    81,   276,   153,   154,
     281,   156,   137,   158,   374,   617,   783,   784,   408,   417,
     431,   432,   433,   719,   291,   434,   435,   436,    26,   437,
     438,   184,    27,   293,   294,   322,   295,   296,   802,   803,
     297,   155,    33,   157,   333,   119,   528,    35,   370,   600,
      38,   196,    41,   198,   137,   601,   227,   228,   262,   529,
     262,   530,    39,   206,   655,   371,   229,    49,   439,   653,
     230,   207,   375,   132,   252,   654,   722,   379,   776,   133,
     134,    52,   654,   401,   777,   231,   137,   232,   135,   136,
     780,   652,    78,   531,   286,    98,   781,   100,   495,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   108,    26,
     310,   311,   551,    27,   109,   552,   248,   338,   817,   553,
     554,   555,   556,   129,   818,   262,    26,   450,   101,   130,
      27,   332,    80,   125,   275,    26,   211,   126,   475,    27,
     212,   103,   557,     4,   558,   559,   104,     5,   105,   233,
     227,   228,   484,   486,   234,   333,   333,   170,   171,   172,
     229,   629,   630,   106,   230,   107,   376,    80,   131,   146,
      54,   708,   709,   785,   786,   145,   560,   561,   147,   231,
     562,   232,   235,   236,   318,   319,   291,   148,   563,   149,
     564,   150,   565,   798,   799,   616,   185,   186,   566,   567,
     568,   423,   424,   569,   570,   571,   572,   573,   574,   151,
     575,   576,   577,   578,   579,   580,   581,   582,   292,   159,
     583,   164,   584,   585,   170,   171,   172,   221,   227,   228,
     167,   168,   190,   423,   424,    55,   169,   184,   229,   425,
     189,   199,   230,    56,   220,    57,    58,    59,   426,   427,
     428,   429,   245,   233,   132,   423,   424,   231,   234,   232,
     133,   134,    60,    61,    62,   242,   292,   430,   244,   135,
     136,   425,   609,   787,   788,   246,   618,   247,   251,   494,
     426,   427,   428,   429,   -11,   -12,   235,   236,   260,   257,
     266,   267,   184,   425,   293,   294,   272,   295,   296,   430,
     287,   297,   426,   427,   428,   429,   283,   289,   288,   290,
     321,   789,    65,    66,    67,    68,    69,    70,   431,   432,
     433,   430,   327,   434,   435,   436,   328,   437,   438,   616,
     330,   233,   331,   337,   377,   381,   234,   399,   400,   790,
     184,   402,   293,   294,   405,   295,   296,   410,   406,   297,
     431,   432,   433,   407,   411,   434,   435,   436,   412,   437,
     438,   415,   739,   665,   235,   236,    54,   667,   443,   691,
     692,   -11,   431,   432,   593,   740,   741,   434,   435,   436,
     -12,   437,   438,   705,   422,   441,   444,   323,   742,   451,
     791,   477,   515,   743,   452,   792,   793,   794,   492,   795,
     796,   487,    84,   744,   745,   480,   491,   508,   618,   516,
     729,   519,   732,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   517,   518,
     521,    55,   523,   524,   175,   425,   526,   527,   588,    56,
     590,    57,    58,    59,   426,   427,   428,   429,    85,    86,
      87,    88,    89,   602,    90,   592,   608,   596,    60,    61,
      62,   598,   610,   430,   175,   611,   599,   733,   620,   621,
     649,   622,   623,    91,    92,   624,    93,   759,   625,    94,
     650,   626,   627,   772,   773,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   176,   177,   178,   223,
     179,   180,   181,   667,   782,   628,   455,   456,   457,   458,
     459,   460,   461,   631,   431,   432,   433,   632,   633,   434,
     435,   436,   634,   437,   438,   635,   176,   177,   178,   636,
     179,   180,   181,   637,   638,   393,   394,   395,   396,   465,
     466,   467,   468,   469,   470,   471,   639,   640,   641,   668,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   750,   642,   643,   644,   645,   397,
     804,   805,   806,   807,   808,   646,   810,   740,   751,   647,
     648,   656,   657,   659,   658,   663,   664,   666,   685,   693,
     752,   694,   812,   695,   814,   753,   816,   696,   697,   704,
     698,   819,   699,   700,   706,   744,   745,   707,   710,   711,
     713,   712,   714,   721,   725,   724,   726,   731,   737,   774,
     757,   775,   738,   801,   811,   813,   758,     8,   809,   250,
     372,    37,   727,    51,   124,   728,   720,   715,   734,   589,
     409,   188,   490,   489,   514,   373,   513,   800,   797,   454,
     606,   605,   522,   404,   218,   222,   265,   224,   364,   511,
     285,   512,   651
};

static const yytype_uint16 yycheck[] =
{
      14,    15,    96,   305,    77,    27,   308,    23,    24,   154,
      62,   156,    30,    98,    29,    30,    34,    35,    45,    38,
     712,    35,    95,    27,   296,    30,    30,   508,    85,    34,
      34,    64,    47,    47,   208,    30,    47,     9,    53,    34,
      47,    46,    29,    30,    30,    29,    30,   237,    34,    35,
      34,    65,    66,   138,    68,     9,    70,    51,    42,    47,
      47,   363,    21,    47,    78,   138,    60,    81,    74,    55,
      81,    23,    24,    29,    30,    28,   109,    84,   252,   351,
     352,   353,   354,    29,    98,    29,    30,   144,    60,   781,
      34,    47,   111,   380,    16,    17,    84,     0,    42,   151,
     114,    47,   116,    47,    26,   190,    60,    60,    30,    53,
      32,   592,   399,    57,    58,   130,    48,    30,   133,    38,
     177,    34,    27,    45,   138,    47,   132,    46,   318,   319,
     275,   118,    41,     8,     9,   265,   221,   439,   223,    38,
      39,    40,    55,   415,   148,   159,   160,   161,   162,   133,
     164,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     182,    39,   180,   435,   150,   170,   193,   297,   440,    39,
     184,    46,    18,   654,   190,   170,   190,   133,    24,   167,
      55,    56,    57,    58,    30,   199,   130,    92,    34,   133,
     194,   195,   196,   197,   198,    47,   200,   119,    42,    74,
     294,   295,   124,    27,    30,   219,    30,   221,    34,   223,
      34,   226,   227,   298,    41,   219,   220,    63,   222,    27,
      30,   225,    30,    66,    34,    68,    34,    70,    42,    55,
     152,   153,   176,   505,    47,    29,    60,   251,   112,   113,
     254,   115,   256,   117,   317,    55,   763,   764,    54,   343,
     125,   126,   127,    47,    60,   130,   131,   132,    30,   134,
     135,   166,    34,   168,   169,   279,   171,   172,   785,   786,
     175,   114,    53,   116,   288,    47,    37,    44,    28,    54,
      43,   155,    25,   157,   298,    60,    16,    17,   221,    50,
     223,    52,    43,    38,   596,    45,    26,    20,   173,    54,
      30,    46,    32,   149,    49,    60,    54,   321,    54,   155,
     156,    29,    60,   327,    60,    45,   330,    47,   164,   165,
      54,   593,    46,    84,   257,    19,    60,    22,   422,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    54,    30,
     152,   153,   113,    34,    60,   116,   199,   290,    54,   120,
     121,   122,   123,    18,    60,   298,    30,   381,   179,    24,
      34,    35,    27,    30,   248,    30,    30,    34,   392,    34,
      34,    46,   143,    30,   145,   146,    46,    34,    46,   119,
      16,    17,   406,   407,   124,   409,   410,   157,   158,   159,
      26,   109,   110,    46,    30,    46,    32,    27,    63,    31,
     116,   202,   203,   126,   127,    29,   177,   178,    47,    45,
     181,    47,   152,   153,   273,   274,    60,    30,   189,    47,
     191,    29,   193,   778,   779,   529,   135,   136,   199,   200,
     201,     8,     9,   204,   205,   206,   207,   208,   209,    29,
     211,   212,   213,   214,   215,   216,   217,   218,    92,    40,
     221,     8,   223,   224,   157,   158,   159,   160,    16,    17,
      59,    47,   154,     8,     9,   181,    53,   166,    26,    46,
      49,   182,    30,   189,    29,   191,   192,   193,    55,    56,
      57,    58,    31,   119,   149,     8,     9,    45,   124,    47,
     155,   156,   208,   209,   210,    27,    92,    74,    27,   164,
     165,    46,   526,     8,     9,    27,   530,    31,    38,    54,
      55,    56,    57,    58,    40,    40,   152,   153,    60,    40,
      53,    49,   166,    46,   168,   169,    16,   171,   172,    74,
      26,   175,    55,    56,    57,    58,    55,    29,    53,    40,
      40,    46,   183,   184,   185,   186,   187,   188,   125,   126,
     127,    74,    40,   130,   131,   132,    26,   134,   135,   663,
       8,   119,    29,    54,    27,    40,   124,    43,   130,    74,
     166,    29,   168,   169,    28,   171,   172,    61,    40,   175,
     125,   126,   127,    40,   111,   130,   131,   132,    47,   134,
     135,    46,    16,   617,   152,   153,   116,    29,    54,   623,
     624,    53,   125,   126,   127,    29,    30,   130,   131,   132,
      53,   134,   135,   637,   160,    53,    60,    62,    42,    53,
     125,    42,    27,    47,    53,   130,   131,   132,    47,   134,
     135,   112,   148,    57,    58,    60,    53,    53,   662,    27,
     664,    53,   666,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    29,    29,
     111,   181,   111,    53,    95,    46,    40,    29,   147,   189,
      29,   191,   192,   193,    55,    56,    57,    58,   194,   195,
     196,   197,   198,    29,   200,    53,    29,   174,   208,   209,
     210,    54,    28,    74,    95,    25,    54,   129,    46,    46,
      60,    46,    74,   219,   220,    74,   222,   731,    46,   225,
      60,    46,    46,   737,   738,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   157,   158,   159,   160,
     161,   162,   163,    29,   758,    46,   136,   137,   138,   139,
     140,   141,   142,    46,   125,   126,   127,    46,    46,   130,
     131,   132,    46,   134,   135,    46,   157,   158,   159,    46,
     161,   162,   163,    46,    46,   114,   115,   116,   117,   136,
     137,   138,   139,   140,   141,   142,    46,    46,    46,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    16,    46,    46,    46,    46,   148,
     787,   788,   789,   790,   791,    46,   793,    29,    30,    46,
      46,    29,    54,    46,    54,    60,    46,    40,    47,    47,
      42,    53,   809,    47,   811,    47,   813,    47,    47,    29,
      47,   818,    47,    47,    47,    57,    58,    47,    29,    29,
      29,    53,    29,    29,    29,    54,    51,    40,    40,    29,
      54,    29,    40,    54,    53,   127,    40,     1,    74,   200,
     313,    23,   662,    40,    95,   663,   649,   646,   683,   488,
     334,   138,   410,   409,   446,   314,   445,   781,   777,   389,
     523,   521,   471,   330,   165,   173,   223,   182,   298,   441,
     256,   444,   592
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   229,   231,    30,    34,    35,   180,   232,   235,
       0,    48,   230,    41,    39,    39,    41,    47,    23,    24,
     190,   236,   259,   261,   262,    42,    30,    34,   233,   233,
      42,    47,   263,    53,   252,    44,   280,   262,    43,    43,
     264,    25,   265,   270,   253,   260,   233,   281,   282,    20,
     285,   265,    29,   266,   116,   181,   189,   191,   192,   193,
     208,   209,   210,   254,   255,   183,   184,   185,   186,   187,
     188,   237,   238,   239,   240,   244,   248,   258,    46,   283,
      27,    60,   271,   282,   148,   194,   195,   196,   197,   198,
     200,   219,   220,   222,   225,   286,   287,   288,    19,   312,
      22,   179,   269,    46,    46,    46,    46,    46,    54,    60,
     254,   233,   243,   243,   245,   243,   249,   243,   271,    47,
     233,   284,   282,   271,   288,    30,    34,   234,   329,    18,
      24,    63,   149,   155,   156,   164,   165,   233,   313,   314,
     315,   358,   363,   365,   381,    29,    31,    47,    30,    47,
      29,    29,   254,   252,   252,   243,   252,   243,   252,    40,
      38,    39,    40,   289,     8,   359,   360,    59,    47,    53,
     157,   158,   159,   375,   377,    95,   157,   158,   159,   161,
     162,   163,   376,   378,   166,   382,   382,   271,   314,    49,
     154,   267,   256,   257,   258,   256,   252,   256,   252,   182,
     241,   242,   233,   233,   233,   233,    38,    46,   290,   291,
     292,    30,    34,   232,   361,   362,   363,   364,   360,   316,
      29,   160,   377,   160,   378,   233,   363,    16,    17,    26,
      30,    45,    47,   119,   124,   152,   153,   272,   273,   274,
     275,   276,    27,   258,    27,    31,    27,    31,   243,    27,
     242,    38,    49,   292,   293,     9,    60,    40,   233,   320,
      60,   363,   364,   379,   380,   379,    53,    49,   319,   277,
      32,   274,    16,   246,   250,   252,   233,   292,    35,    55,
     150,   233,   298,    55,   318,   362,   364,    26,    53,    29,
      40,    60,    92,   168,   169,   171,   172,   175,   322,   366,
     367,   369,   370,   371,   372,   373,   374,   382,   373,   383,
     152,   153,   278,   326,   327,   328,   330,   268,   272,   272,
     256,    40,   233,    62,   151,   296,   297,    40,    26,   295,
       8,    29,    35,   233,   321,   323,   324,    54,   364,    47,
      84,   167,   329,    46,   170,   329,    29,    30,    34,    42,
      47,    53,    57,    58,   130,   133,   176,   233,   329,   387,
     389,   390,   391,   373,   380,   366,   384,   385,   386,   387,
      28,    45,   234,   328,   271,    32,    32,    27,    27,   233,
     325,    40,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   114,   115,   116,   117,   148,   332,    43,
     130,   233,    29,   294,   361,    28,    40,    40,    54,   322,
      61,   111,    47,    47,    84,    46,   170,   329,   387,   387,
     387,   387,   160,     8,     9,    46,    55,    56,    57,    58,
      74,   125,   126,   127,   130,   131,   132,   134,   135,   173,
     388,    53,    27,    54,    60,   279,   331,   247,   251,   296,
     233,    53,    53,   339,   339,   136,   137,   138,   139,   140,
     141,   142,   346,   347,   349,   136,   137,   138,   139,   140,
     141,   142,   340,   343,   344,   233,   296,    42,    28,    60,
      60,   306,     9,    55,   233,    55,   233,   112,   317,   324,
     323,    53,    47,   387,    54,   329,   387,   387,   387,   387,
     387,   387,   387,   387,   387,    74,   132,   387,    53,   366,
     387,   384,   386,   330,   326,    27,    27,    29,    29,    53,
     350,   111,   350,   111,    53,   341,    40,    29,    37,    50,
      52,    84,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   113,   116,   120,   121,   122,   123,   143,   145,   146,
     177,   178,   181,   189,   191,   193,   199,   200,   201,   204,
     205,   206,   207,   208,   209,   211,   212,   213,   214,   215,
     216,   217,   218,   221,   223,   224,   307,   308,   147,   319,
      29,   387,    53,   127,   391,   392,   174,   368,    54,    54,
      54,    60,    29,   342,   348,   349,   344,   345,    29,   233,
      28,    25,   299,   300,   301,   302,   329,    55,   233,   304,
      46,    46,    46,    74,    74,    46,    46,    46,    46,   109,
     110,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    60,
      60,   392,   387,    54,    60,   366,    29,    54,    54,    46,
      51,    60,   305,    60,    46,   233,    40,    29,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   310,   311,    47,    29,    30,    47,   118,
     309,   233,   233,    47,    53,    47,    47,    47,    47,    47,
      47,    85,   144,   177,    29,   233,    47,    47,   202,   203,
      29,    29,    53,    29,    29,   309,    29,    47,    29,    47,
     308,    29,    54,   391,    54,    29,    51,   304,   301,   233,
     303,    40,   233,   129,   311,   351,   352,    40,    40,    16,
      29,    30,    42,    47,    57,    58,   333,   335,   337,   338,
      16,    30,    42,    47,   334,   335,   336,    54,    40,   233,
      29,    30,    47,    53,   130,   133,   226,   227,   353,   354,
     355,   356,   233,   233,    29,    29,    54,    60,    38,   111,
      54,    60,   233,   354,   354,   126,   127,     8,     9,    46,
      74,   125,   130,   131,   132,   134,   135,   337,   338,   338,
     336,    54,   354,   354,   355,   355,   355,   355,   355,    74,
     355,    53,   355,   127,   355,   357,   355,    54,    60,   355
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
# define YYLEX yylex (yystate)
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
#line 154 "screen.yacc"
    {
A4GL_check_compiled_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
A4GL_write_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 163 "screen.yacc"
    {the_form.encoding="";}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 164 "screen.yacc"
    {
		the_form.encoding=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
	}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 170 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");
the_form.allowNullInput=1;
}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 173 "screen.yacc"
    {the_form.dbname=acl_strdup((yyvsp[(2) - (5)].str));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=0;
}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 179 "screen.yacc"
    {the_form.dbname=("formonly");
the_form.allowNullInput=0;
}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 182 "screen.yacc"
    {the_form.dbname=acl_strdup((yyvsp[(2) - (2)].str));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=1;
}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 193 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));A4GL_make_downshift((yyval.str)); }
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 194 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 199 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));A4GL_make_downshift((yyval.str)); }
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 200 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 204 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));
 		if (tagCaseInsensitive) {
                		A4GL_make_downshift((yyval.str));
        		}
	}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 209 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 214 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 215 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 217 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 222 "screen.yacc"
    {
			the_form.layout=NULL;
			the_form.layout_attrib=NULL;
	}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 226 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 233 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 243 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_HBOX;
	}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 252 "screen.yacc"
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
#line 265 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 273 "screen.yacc"
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
#line 283 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 291 "screen.yacc"
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
#line 304 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 305 "screen.yacc"
    {
		{strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
	}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 312 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 315 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 318 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 319 "screen.yacc"
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
#line 334 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 337 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 340 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 341 "screen.yacc"
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
#line 354 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 357 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 357 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 363 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 366 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 369 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_NOSHOW);
	}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 372 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 375 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 378 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_ACTION, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 381 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_BORDER);
	}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 384 "screen.yacc"
    { add_str_layout_attrib(FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 385 "screen.yacc"
    { add_str_layout_attrib(FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 395 "screen.yacc"
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

  case 54:

/* Line 1464 of yacc.c  */
#line 404 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 410 "screen.yacc"
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

  case 56:

/* Line 1464 of yacc.c  */
#line 420 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 428 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 430 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 432 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 434 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 436 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 438 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 442 "screen.yacc"
    { 
		the_form.layout_attrib=(yyvsp[(2) - (2)].layout_attrib);
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 444 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(4) - (5)].layout);
	}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 455 "screen.yacc"
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

  case 69:

/* Line 1464 of yacc.c  */
#line 468 "screen.yacc"
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

  case 71:

/* Line 1464 of yacc.c  */
#line 487 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 489 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 492 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 497 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 504 "screen.yacc"
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

  case 84:

/* Line 1464 of yacc.c  */
#line 526 "screen.yacc"
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

  case 85:

/* Line 1464 of yacc.c  */
#line 541 "screen.yacc"
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

  case 86:

/* Line 1464 of yacc.c  */
#line 553 "screen.yacc"
    { ltab=0; }
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 554 "screen.yacc"
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

  case 88:

/* Line 1464 of yacc.c  */
#line 565 "screen.yacc"
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

  case 89:

/* Line 1464 of yacc.c  */
#line 576 "screen.yacc"
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

  case 90:

/* Line 1464 of yacc.c  */
#line 589 "screen.yacc"
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
#line 601 "screen.yacc"
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

  case 92:

/* Line 1464 of yacc.c  */
#line 612 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 617 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 620 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 628 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 629 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 635 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 642 "screen.yacc"
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

  case 99:

/* Line 1464 of yacc.c  */
#line 659 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 662 "screen.yacc"
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

  case 101:

/* Line 1464 of yacc.c  */
#line 673 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 689 "screen.yacc"
    { 
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 696 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 697 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 700 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 701 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 703 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 704 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 705 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 721 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 722 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 723 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 724 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 725 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 726 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 727 "screen.yacc"
    {strcpy((yyval.str),"Button");}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 728 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 729 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 730 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 731 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 732 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 737 "screen.yacc"
    {
			if (tagCaseInsensitive) {
				A4GL_make_downshift((yyvsp[(2) - (2)].str));
			}
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 745 "screen.yacc"
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

  case 138:

/* Line 1464 of yacc.c  */
#line 775 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 779 "screen.yacc"
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

  case 140:

/* Line 1464 of yacc.c  */
#line 793 "screen.yacc"
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

  case 142:

/* Line 1464 of yacc.c  */
#line 1112 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1118 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1128 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1129 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1132 "screen.yacc"
    {strcpy((yyval.str),"0"); dtype_size=0;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1133 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str),1));
		}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1136 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),"",1));
		}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1139 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1144 "screen.yacc"
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

  case 151:

/* Line 1464 of yacc.c  */
#line 1155 "screen.yacc"
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

  case 152:

/* Line 1464 of yacc.c  */
#line 1169 "screen.yacc"
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

  case 153:

/* Line 1464 of yacc.c  */
#line 1183 "screen.yacc"
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

  case 154:

/* Line 1464 of yacc.c  */
#line 1192 "screen.yacc"
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

  case 155:

/* Line 1464 of yacc.c  */
#line 1214 "screen.yacc"
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

  case 156:

/* Line 1464 of yacc.c  */
#line 1223 "screen.yacc"
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

  case 157:

/* Line 1464 of yacc.c  */
#line 1235 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;
	}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1240 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (1)].lookups);
		}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1246 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1255 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1264 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1273 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1276 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1282 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1283 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1284 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 1285 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1301 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 1306 "screen.yacc"
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

  case 177:

/* Line 1464 of yacc.c  */
#line 1328 "screen.yacc"
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

  case 178:

/* Line 1464 of yacc.c  */
#line 1352 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1360 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 1361 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 1362 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 1363 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 1368 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 1373 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 1378 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1383 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 1384 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1385 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 1386 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1387 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 1388 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 1389 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1390 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1391 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); 
#ifdef DEBUG
A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); 
#endif
}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1396 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; 
#ifdef DEBUG
A4GL_debug("dynamic=-1"); 
#endif
}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 1401 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1403 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1405 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1406 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1407 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1408 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1409 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 1410 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 1411 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1412 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 1413 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1414 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1415 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1416 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1420 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 1427 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1428 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOSHOW); }
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1429 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1430 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1431 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTRETURNS); }
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1432 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1433 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1434 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1435 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1436 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 1437 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"left"); }
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 1438 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"right"); }
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1439 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"center"); }
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1440 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1441 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1442 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1443 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1444 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1445 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1446 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1447 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1448 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,(yyvsp[(3) - (3)].str)); }
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1449 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1450 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1451 "screen.yacc"
    { A4GL_get_fld()->not_null=1;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1453 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 1454 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 1455 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1456 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1457 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1458 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_HEADER,(yyvsp[(3) - (3)].str)); }
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1459 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1465 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1466 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1467 "screen.yacc"
    {sprintf((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1468 "screen.yacc"
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

  case 248:

/* Line 1464 of yacc.c  */
#line 1481 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1485 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1486 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 1487 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1488 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1489 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1490 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1491 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1492 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1494 "screen.yacc"
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

  case 258:

/* Line 1464 of yacc.c  */
#line 1529 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1530 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1531 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1532 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1533 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1534 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1535 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1548 "screen.yacc"
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

  case 272:

/* Line 1464 of yacc.c  */
#line 1558 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1564 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1575 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 1575 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1580 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 1583 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 1589 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1592 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 1602 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 1606 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 1610 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 1614 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 1618 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 1624 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 1628 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 1631 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 1635 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 1635 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 1642 "screen.yacc"
    {colno++;}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 1643 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 1656 "screen.yacc"
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

  case 306:

/* Line 1464 of yacc.c  */
#line 1668 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 1670 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 1681 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 1685 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=atol((yyvsp[(3) - (4)].str));
}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 1689 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 1693 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 1697 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 1701 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 1705 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 1709 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 1715 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 1719 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 1723 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 1727 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 1731 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 1735 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 1739 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 1742 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 1749 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 1753 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 1758 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 1762 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 1769 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 1770 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 1772 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 1780 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 1783 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 1789 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 1796 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 1797 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 1798 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 1799 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 1805 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 1808 "screen.yacc"
    {
		int n;
		 n=atol(acl_getenv("A4GL_DEFDECPREC"));
		sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str)))<<8)+n);
	}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 1813 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 1816 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 1818 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 1824 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 1828 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
#endif
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 1835 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 1843 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 1846 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 1847 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 1848 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 1849 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 1850 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 1851 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 1853 "screen.yacc"
    {
#ifdef DEBUG
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
#endif
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 1862 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 1863 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 1866 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 1869 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 1873 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 1874 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 1875 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 1876 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 1877 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 1878 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 1880 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
#endif
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 1887 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 1891 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
#endif
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 1900 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 1900 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 1906 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 1913 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 1916 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 1925 "screen.yacc"
    { (yyval.expr)=create_expr_oddline();}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 1926 "screen.yacc"
    { (yyval.expr)=create_expr_evenline(); }
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 1927 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 1928 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 1929 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 1930 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 1931 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 1932 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 1933 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 1934 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 1935 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 1936 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 1937 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 1938 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 1939 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 1942 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 1949 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 1950 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 1951 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 1959 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 1963 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 1983 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 1993 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2000 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2009 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2012 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"",0);
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2031 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2038 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2046 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2051 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2059 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2063 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2068 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 2073 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2078 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2083 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2088 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2097 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2106 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2107 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2116 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2124 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2130 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2136 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2142 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 2150 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 2155 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 2165 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 2175 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2181 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2187 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 2193 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 2203 "screen.yacc"
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

  case 440:

/* Line 1464 of yacc.c  */
#line 2215 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2223 "screen.yacc"
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

  case 442:

/* Line 1464 of yacc.c  */
#line 2235 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 2243 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 2244 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 2245 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 2249 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 447:

/* Line 1464 of yacc.c  */
#line 2250 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 448:

/* Line 1464 of yacc.c  */
#line 2251 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2252 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2253 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2254 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2255 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2258 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2265 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2276 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2280 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2287 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2295 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2301 "screen.yacc"
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

  case 460:

/* Line 1464 of yacc.c  */
#line 2313 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2314 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2320 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2326 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2334 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2342 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str));}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2347 "screen.yacc"
    {strcpy((yyval.str),"AND");}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2348 "screen.yacc"
    {strcpy((yyval.str),"OR");}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2364 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2366 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2367 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2368 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2369 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2370 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2373 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2374 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2375 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2376 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2377 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2378 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2379 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2380 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2381 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2382 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2383 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2384 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2385 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2386 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2387 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2388 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2394 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2395 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2396 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2397 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2398 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2401 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2405 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1464 of yacc.c  */
#line 7043 "y.tab.c"
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
#line 2417 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




