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
     KW_WANTRETURNS = 458,
     KW_WANTNORETURNS = 459,
     KW_WANTTABS = 460,
     KW_AUTOSCALE = 461,
     KW_PIXELWIDTH = 462,
     KW_PIXELHEIGHT = 463,
     KW_BORDER = 464,
     KW_SCROLLBARS_BOTH = 465,
     KW_SCROLLBARS_V = 466,
     KW_SCROLLBARS_H = 467,
     KW_STRETCH_Y = 468,
     KW_STRETCH_BOTH = 469,
     KW_ITEMS = 470,
     KW_VALUEMAX = 471,
     KW_VALUEMIN = 472,
     KW_PROGRESSBAR = 473,
     KW_COMBOBOX = 474,
     OPTIONS = 475,
     KW_BROWSER = 476,
     KW_VALUECHECKED = 477,
     KW_VALUEUNCHECKED = 478,
     KW_CHECKBOX = 479
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
#define KW_WANTRETURNS 458
#define KW_WANTNORETURNS 459
#define KW_WANTTABS 460
#define KW_AUTOSCALE 461
#define KW_PIXELWIDTH 462
#define KW_PIXELHEIGHT 463
#define KW_BORDER 464
#define KW_SCROLLBARS_BOTH 465
#define KW_SCROLLBARS_V 466
#define KW_SCROLLBARS_H 467
#define KW_STRETCH_Y 468
#define KW_STRETCH_BOTH 469
#define KW_ITEMS 470
#define KW_VALUEMAX 471
#define KW_VALUEMIN 472
#define KW_PROGRESSBAR 473
#define KW_COMBOBOX 474
#define OPTIONS 475
#define KW_BROWSER 476
#define KW_VALUECHECKED 477
#define KW_VALUEUNCHECKED 478
#define KW_CHECKBOX 479




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
#line 667 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 679 "y.tab.c"

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
#define YYLAST   903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  225
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  165
/* YYNRULES -- Number of rules.  */
#define YYNRULES  494
/* YYNRULES -- Number of states.  */
#define YYNSTATES  816

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   479

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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224
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
     617,   619,   621,   623,   625,   627,   631,   635,   637,   641,
     645,   649,   653,   657,   661,   663,   665,   667,   669,   671,
     677,   681,   685,   689,   691,   695,   699,   703,   707,   711,
     715,   719,   721,   723,   725,   727,   729,   732,   734,   736,
     738,   740,   742,   744,   746,   748,   750,   752,   754,   756,
     758,   760,   762,   764,   765,   769,   771,   774,   776,   779,
     782,   784,   785,   795,   808,   810,   812,   813,   816,   817,
     819,   820,   822,   824,   829,   831,   835,   836,   838,   840,
     844,   848,   852,   856,   858,   862,   864,   866,   867,   869,
     871,   874,   876,   878,   880,   881,   886,   888,   893,   895,
     897,   899,   901,   903,   906,   909,   912,   915,   917,   919,
     921,   923,   925,   927,   931,   933,   937,   939,   942,   945,
     947,   949,   951,   953,   955,   957,   961,   965,   967,   969,
     971,   973,   975,   976,   980,   986,   987,   991,   992,   996,
     998,  1001,  1003,  1005,  1007,  1009,  1011,  1013,  1016,  1018,
    1019,  1023,  1025,  1027,  1029,  1031,  1033,  1035,  1037,  1039,
    1042,  1043,  1047,  1048,  1050,  1053,  1055,  1059,  1063,  1067,
    1071,  1075,  1079,  1084,  1088,  1091,  1094,  1096,  1102,  1108,
    1111,  1115,  1117,  1119,  1121,  1123,  1125,  1127,  1131,  1134,
    1136,  1139,  1147,  1149,  1153,  1157,  1159,  1161,  1163,  1169,
    1175,  1178,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1201,  1202,  1205,  1207,  1212,  1215,  1219,  1222,  1226,  1230,
    1232,  1235,  1238,  1242,  1246,  1251,  1253,  1256,  1258,  1261,
    1263,  1265,  1267,  1269,  1271,  1273,  1275,  1277,  1279,  1281,
    1283,  1287,  1291,  1293,  1298,  1299,  1306,  1307,  1309,  1311,
    1315,  1317,  1319,  1323,  1325,  1327,  1330,  1333,  1335,  1338,
    1342,  1347,  1351,  1355,  1359,  1363,  1367,  1371,  1375,  1379,
    1383,  1388,  1392,  1395,  1398,  1404,  1410,  1417,  1419,  1421,
    1423,  1425,  1427,  1429,  1431
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     226,     0,    -1,   228,   227,   233,   277,   282,   309,    -1,
      -1,    48,    47,    -1,    21,    35,    -1,    21,   232,    41,
      42,    43,    -1,    21,    35,    41,    42,    43,    -1,    21,
     232,    -1,    30,    -1,    34,    -1,    30,    -1,    34,    -1,
      30,    -1,    34,    -1,   180,    -1,   180,    39,   230,    -1,
     229,    -1,   229,    39,   230,    -1,   258,    -1,   256,    -1,
     184,   240,   249,   253,    27,    -1,   183,   240,   249,   253,
      27,    -1,   186,   240,   249,   253,    27,    -1,   188,   240,
     249,   238,    27,    -1,   239,    -1,   238,   239,    -1,   182,
     240,   249,   253,    27,    -1,    -1,   230,    -1,    -1,    -1,
      -1,   185,   242,   240,   249,    31,   243,   269,    32,   244,
      27,    -1,    -1,    -1,    -1,   187,   246,   240,   249,    31,
     247,   269,    32,   248,    27,    -1,    -1,    -1,    53,   250,
     252,    54,    -1,   189,    46,    47,    -1,   191,    -1,   192,
      -1,   116,    46,    47,    -1,   181,    46,    30,    -1,   209,
      -1,   208,    46,    29,    -1,   207,    46,    29,    -1,   251,
      -1,   252,   251,    -1,   252,    60,   251,    -1,    -1,   254,
      -1,   255,    -1,   254,   255,    -1,   234,    -1,   235,    -1,
     236,    -1,   237,    -1,   241,    -1,   245,    -1,    -1,   190,
     249,   257,   255,   268,    -1,   259,    -1,   258,   259,    -1,
      -1,    24,   260,   262,    -1,    -1,    23,    47,   261,   262,
      -1,    -1,    -1,    -1,   267,   263,   266,    31,   264,   269,
      32,   265,   268,    -1,    -1,   179,    -1,    -1,    25,    29,
      -1,    25,    29,    22,    29,    -1,    -1,    27,    -1,   271,
      -1,   269,   271,    -1,    30,    -1,   270,    -1,   273,    -1,
     153,    -1,    17,    -1,    45,    -1,    47,    -1,   272,    -1,
     152,    -1,   124,    -1,   119,    -1,    16,    -1,   272,    16,
      -1,    -1,    26,   274,   275,    28,    -1,   327,    -1,    -1,
     275,    45,   276,   327,    -1,    -1,    44,   278,   268,    -1,
     279,    -1,   278,   279,    -1,   278,    60,   279,    -1,   230,
     280,    -1,    -1,    46,   281,    -1,   230,    -1,   230,    38,
     230,    -1,   230,    39,   230,    -1,   230,    39,   230,    38,
     230,    -1,   230,    40,   230,    -1,    47,    40,   230,    -1,
      20,   283,   268,    -1,   285,    -1,   283,   285,    -1,    -1,
     196,    -1,   193,    -1,   195,    -1,   197,    -1,   194,    -1,
     148,    -1,   199,    -1,   218,    -1,   219,    -1,   224,    -1,
     221,    -1,    -1,   284,   326,   286,   287,    49,    -1,   289,
      -1,   287,   289,    -1,   287,    49,   289,    -1,    46,    -1,
      38,    -1,    -1,    -1,   288,   290,   295,   292,   291,   303,
      -1,    -1,    26,    29,    28,    -1,    26,    29,    60,    29,
      28,    -1,   294,   130,    42,    -1,   294,    -1,    -1,    62,
      74,   230,    40,   230,    -1,    62,    74,   230,    -1,    62,
     329,    -1,    35,    40,   322,   293,    -1,   150,   293,    -1,
     150,   151,    43,   293,    -1,   230,    40,   230,    -1,   230,
      -1,    55,   230,    40,   230,    -1,    55,   230,    -1,    -1,
     297,    -1,   298,    -1,   297,    60,   298,    -1,   299,    46,
     300,    -1,   326,    -1,   230,    40,   230,    -1,   230,    -1,
     230,    40,   230,    -1,   230,    -1,    55,   230,    40,   230,
      -1,    55,   230,    -1,    51,    -1,    60,    51,    -1,    -1,
      60,   304,    -1,   305,    -1,   304,    60,   305,    -1,    90,
      -1,    91,    46,   307,   348,    -1,    52,   301,    -1,    50,
     296,   302,   301,    -1,    92,    46,    47,    -1,    93,    46,
     306,    -1,   220,    46,   306,    -1,    95,    74,   230,    -1,
      95,    74,   230,    40,   230,    -1,    94,    74,   230,    -1,
      94,    74,   230,    40,   230,    -1,    96,    -1,    97,    -1,
      98,    46,    47,    -1,    99,    46,    53,   330,    54,    -1,
     122,    46,    47,    -1,   123,    46,    47,    -1,   181,    46,
     230,    -1,   100,    -1,    37,    25,    46,    29,    -1,    37,
      -1,   121,    -1,   102,    -1,   101,    -1,   103,    46,    47,
      -1,   104,    46,    47,    -1,   105,    -1,   113,    -1,    84,
      -1,   107,    -1,   106,    -1,   178,    -1,   177,    -1,   108,
      -1,   108,   109,    -1,   108,   110,    -1,   191,    -1,   206,
      -1,   204,    -1,   203,    -1,   205,    -1,   200,    46,   201,
      -1,   200,    46,   202,    -1,   198,    -1,   199,    46,    47,
      -1,   143,    46,    85,    -1,   143,    46,   177,    -1,   143,
      46,   144,    -1,   208,    46,    29,    -1,   207,    46,    29,
      -1,   210,    -1,   211,    -1,   212,    -1,   213,    -1,   214,
      -1,   215,    46,    53,   331,    54,    -1,   145,    46,    29,
      -1,   216,    46,    29,    -1,   217,    46,    29,    -1,   146,
      -1,   222,    46,    47,    -1,   223,    46,    47,    -1,   222,
      46,    29,    -1,   223,    46,    29,    -1,   116,    46,    47,
      -1,   120,    46,    47,    -1,   189,    46,    47,    -1,    47,
      -1,    29,    -1,    30,    -1,   118,    -1,   308,    -1,   307,
     308,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    29,    -1,
      84,    -1,    89,    -1,    83,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    -1,    19,   310,   268,    -1,   311,
      -1,   310,   311,    -1,   312,    -1,   312,    49,    -1,    63,
      47,    -1,   362,    -1,    -1,    24,    59,   313,   317,    53,
     318,    54,   314,   316,    -1,   149,    53,    29,    60,    29,
      54,   111,    53,    29,    60,    29,    54,    -1,   355,    -1,
     378,    -1,    -1,   112,   147,    -1,    -1,    55,    -1,    -1,
      49,    -1,   230,    -1,   230,    26,    29,    28,    -1,   321,
      -1,   318,   319,   321,    -1,    -1,    60,    -1,   230,    -1,
     230,    40,   230,    -1,    35,    40,   230,    -1,   230,    40,
      55,    -1,    35,    40,    55,    -1,   320,    -1,   320,    61,
     320,    -1,   230,    -1,    27,    -1,    -1,   324,    -1,   325,
      -1,   324,   325,    -1,   152,    -1,   153,    -1,   231,    -1,
      -1,   323,   231,   328,   323,    -1,    64,    -1,    64,    53,
      29,    54,    -1,    65,    -1,    66,    -1,    67,    -1,    68,
      -1,    69,    -1,    70,   336,    -1,    71,   336,    -1,    72,
     343,    -1,    73,   337,    -1,   114,    -1,   115,    -1,   116,
      -1,   117,    -1,   148,    -1,   334,    -1,   330,    60,   334,
      -1,   333,    -1,   331,    60,   333,    -1,    29,    -1,    57,
      29,    -1,    58,    29,    -1,    47,    -1,    30,    -1,    16,
      -1,   332,    -1,    42,    -1,   335,    -1,   335,   111,   335,
      -1,   335,    38,   335,    -1,    47,    -1,    30,    -1,    16,
      -1,   332,    -1,    42,    -1,    -1,    53,    29,    54,    -1,
      53,    29,    60,    29,    54,    -1,    -1,   340,   111,   342,
      -1,    -1,    53,    29,    54,    -1,    29,    -1,   341,   338,
      -1,   136,    -1,   137,    -1,   138,    -1,   139,    -1,   140,
      -1,   141,    -1,   142,   347,    -1,   341,    -1,    -1,   344,
     111,   345,    -1,   346,    -1,   346,    -1,   136,    -1,   137,
      -1,   138,    -1,   139,    -1,   140,    -1,   141,    -1,   142,
     347,    -1,    -1,    53,   339,    54,    -1,    -1,   349,    -1,
     129,   350,    -1,   351,    -1,   351,   127,   351,    -1,   351,
     126,   351,    -1,   352,   125,   352,    -1,   352,     8,   352,
      -1,   352,     9,   352,    -1,   352,    74,   352,    -1,   352,
     130,    74,   352,    -1,   352,    46,   352,    -1,   352,   134,
      -1,   352,   135,    -1,   352,    -1,   352,   131,   352,   127,
     352,    -1,   352,   132,    53,   354,    54,    -1,   130,   351,
      -1,    53,   351,    54,    -1,   353,    -1,    29,    -1,    47,
      -1,   133,    -1,    30,    -1,   352,    -1,   354,    60,   352,
      -1,    18,   356,    -1,   357,    -1,   356,   357,    -1,     8,
     358,     9,   315,     8,   358,     9,    -1,   359,    -1,   358,
      60,   359,    -1,   360,    40,   361,    -1,   361,    -1,   230,
      -1,   229,    -1,   155,   372,   160,   376,   370,    -1,   156,
     373,   160,   376,   370,    -1,   165,   379,    -1,   164,   379,
      -1,   366,    -1,   371,    -1,   364,    -1,   367,    -1,   368,
      -1,   379,    -1,   369,    -1,   172,   384,   173,   363,   365,
      -1,    -1,   174,   363,    -1,   168,    -1,   169,   326,    46,
     384,    -1,   171,   326,    -1,   171,    46,   326,    -1,   171,
     170,    -1,   171,    46,   170,    -1,   175,   370,    27,    -1,
     363,    -1,   370,   363,    -1,    92,    47,    -1,    92,   167,
      47,    -1,    92,    84,    47,    -1,    92,   167,    84,    47,
      -1,   374,    -1,   372,   374,    -1,   375,    -1,   373,   375,
      -1,   157,    -1,   158,    -1,   159,    -1,   157,    -1,   161,
      -1,   162,    -1,   163,    -1,   159,    -1,    95,    -1,   158,
      -1,   377,    -1,   376,   319,   377,    -1,   360,    40,   361,
      -1,   361,    -1,   360,   154,   360,   316,    -1,    -1,   166,
     230,    53,   380,   381,    54,    -1,    -1,   382,    -1,   383,
      -1,   382,    60,   383,    -1,   384,    -1,   386,    -1,   384,
     385,   384,    -1,   127,    -1,   126,    -1,    58,   384,    -1,
      57,   384,    -1,   388,    -1,   130,   384,    -1,    53,   384,
      54,    -1,   387,    53,   381,    54,    -1,   176,   160,   326,
      -1,   384,   125,   384,    -1,   384,     8,   384,    -1,   384,
       9,   384,    -1,   384,    55,   384,    -1,   384,    57,   384,
      -1,   384,    58,   384,    -1,   384,    56,   384,    -1,   384,
      74,   384,    -1,   384,   130,    74,   384,    -1,   384,    46,
     384,    -1,   384,   134,    -1,   384,   135,    -1,   384,   131,
     384,   127,   384,    -1,   384,   132,    53,   389,    54,    -1,
     384,   130,   132,    53,   389,    54,    -1,   230,    -1,   326,
      -1,    29,    -1,    47,    -1,   133,    -1,    42,    -1,   388,
      -1,   389,    60,   388,    -1
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
    1441,  1442,  1443,  1444,  1446,  1447,  1448,  1449,  1450,  1451,
    1452,  1458,  1459,  1460,  1461,  1473,  1474,  1478,  1479,  1480,
    1481,  1482,  1483,  1484,  1485,  1487,  1522,  1523,  1524,  1525,
    1526,  1527,  1528,  1532,  1533,  1536,  1536,  1538,  1538,  1541,
    1551,  1557,  1557,  1560,  1561,  1562,  1566,  1566,  1568,  1568,
    1571,  1571,  1573,  1576,  1582,  1585,  1589,  1590,  1594,  1598,
    1602,  1606,  1610,  1617,  1617,  1621,  1624,  1628,  1628,  1631,
    1631,  1635,  1636,  1649,  1661,  1661,  1674,  1678,  1682,  1686,
    1690,  1694,  1698,  1702,  1708,  1712,  1716,  1720,  1724,  1728,
    1732,  1735,  1742,  1742,  1746,  1746,  1751,  1751,  1751,  1755,
    1762,  1763,  1764,  1765,  1772,  1773,  1776,  1782,  1789,  1790,
    1791,  1792,  1798,  1801,  1806,  1809,  1810,  1817,  1821,  1828,
    1836,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1853,  1855,
    1856,  1859,  1862,  1866,  1867,  1868,  1869,  1870,  1871,  1872,
    1880,  1884,  1893,  1893,  1899,  1905,  1906,  1909,  1915,  1916,
    1917,  1918,  1919,  1920,  1921,  1922,  1923,  1924,  1925,  1926,
    1927,  1930,  1937,  1938,  1939,  1944,  1947,  1951,  1963,  1966,
    1967,  1971,  1981,  1988,  1997,  2000,  2012,  2015,  2019,  2026,
    2034,  2039,  2047,  2051,  2056,  2061,  2066,  2071,  2076,  2085,
    2094,  2095,  2100,  2103,  2111,  2117,  2123,  2129,  2138,  2143,
    2153,  2163,  2169,  2175,  2181,  2191,  2203,  2211,  2223,  2231,
    2232,  2233,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2246,
    2253,  2264,  2268,  2275,  2283,  2283,  2301,  2302,  2308,  2314,
    2322,  2329,  2330,  2335,  2336,  2352,  2354,  2355,  2356,  2357,
    2358,  2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,
    2370,  2371,  2372,  2373,  2374,  2375,  2376,  2379,  2382,  2383,
    2384,  2385,  2386,  2389,  2393
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
  "KW_FIXED", "KW_VARIABLE", "KW_WANTRETURNS", "KW_WANTNORETURNS",
  "KW_WANTTABS", "KW_AUTOSCALE", "KW_PIXELWIDTH", "KW_PIXELHEIGHT",
  "KW_BORDER", "KW_SCROLLBARS_BOTH", "KW_SCROLLBARS_V", "KW_SCROLLBARS_H",
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
     475,   476,   477,   478,   479
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   225,   226,   227,   227,   228,   228,   228,   228,   229,
     229,   230,   230,   231,   231,   232,   232,   232,   232,   233,
     233,   234,   235,   236,   237,   238,   238,   239,   240,   240,
     242,   243,   244,   241,   246,   247,   248,   245,   249,   250,
     249,   251,   251,   251,   251,   251,   251,   251,   251,   252,
     252,   252,   253,   253,   254,   254,   255,   255,   255,   255,
     255,   255,   257,   256,   258,   258,   260,   259,   261,   259,
     263,   264,   265,   262,   266,   266,   267,   267,   267,   268,
     268,   269,   269,   270,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   272,   272,   274,   273,   275,   276,
     275,   277,   277,   278,   278,   278,   279,   280,   280,   281,
     281,   281,   281,   281,   281,   282,   283,   283,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     286,   285,   287,   287,   287,   288,   288,   290,   291,   289,
     292,   292,   292,   293,   293,   294,   294,   294,   294,   295,
     295,   295,   295,   295,   295,   295,   296,   296,   297,   297,
     298,   299,   300,   300,   301,   301,   301,   301,   302,   302,
     303,   303,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   306,   306,   306,   306,   307,   307,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   309,   309,   310,   310,   311,   311,   312,
     312,   313,   312,   312,   312,   312,   314,   314,   315,   315,
     316,   316,   317,   317,   318,   318,   319,   319,   320,   320,
     320,   320,   320,   321,   321,   322,   322,   323,   323,   324,
     324,   325,   325,   326,   328,   327,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   330,   330,   331,   331,   332,   332,   332,   333,
     333,   333,   333,   333,   334,   334,   334,   335,   335,   335,
     335,   335,   336,   336,   336,   337,   337,   338,   338,   339,
     340,   341,   341,   341,   341,   341,   341,   341,   342,   343,
     343,   344,   345,   346,   346,   346,   346,   346,   346,   346,
     347,   347,   348,   348,   349,   350,   350,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   352,   352,   352,   352,   353,   354,   354,   355,   356,
     356,   357,   358,   358,   359,   359,   360,   361,   362,   362,
     362,   362,   363,   363,   363,   363,   363,   363,   363,   364,
     365,   365,   366,   367,   368,   368,   368,   368,   369,   370,
     370,   371,   371,   371,   371,   372,   372,   373,   373,   374,
     374,   374,   375,   375,   375,   375,   375,   375,   375,   376,
     376,   377,   377,   378,   380,   379,   381,   381,   382,   382,
     383,   384,   384,   385,   385,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   387,   388,   388,
     388,   388,   388,   389,   389
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
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     1,     2,     1,     2,     2,
       1,     0,     9,    12,     1,     1,     0,     2,     0,     1,
       0,     1,     1,     4,     1,     3,     0,     1,     1,     3,
       3,     3,     3,     1,     3,     1,     1,     0,     1,     1,
       2,     1,     1,     1,     0,     4,     1,     4,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     0,     3,     5,     0,     3,     0,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     4,     3,     2,     2,     1,     5,     5,     2,
       3,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       2,     7,     1,     3,     3,     1,     1,     1,     5,     5,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     5,
       0,     2,     1,     4,     2,     3,     2,     3,     3,     1,
       2,     2,     3,     3,     4,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     4,     0,     6,     0,     1,     1,     3,
       1,     1,     3,     1,     1,     2,     2,     1,     2,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     2,     2,     5,     5,     6,     1,     1,     1,
       1,     1,     1,     1,     3
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
     263,    69,    77,    74,     0,     0,     0,    42,    43,     0,
       0,    46,    49,     0,    28,    28,    30,    28,    34,    28,
      56,    57,    58,    59,    60,    61,    79,     0,   106,    80,
       0,   102,   104,   124,   120,   123,   121,   119,   122,   125,
     126,   127,   129,   128,    79,     0,   116,     0,     2,     0,
      75,     0,     0,     0,     0,     0,     0,    40,     0,    50,
      29,    38,    38,    28,    38,    28,    38,    63,     0,   109,
     108,   105,   115,   117,    13,    14,   303,   130,     0,     0,
       0,     0,     0,     0,     0,     0,   406,    79,   265,   267,
     274,     0,   270,   275,    78,    71,    44,    45,    41,    48,
      47,    51,    52,    52,    38,    52,    38,     0,     0,     0,
       0,     0,     0,     0,   398,   399,   271,   269,     0,   439,
     440,   441,     0,   435,   447,   442,   448,   446,   443,   444,
     445,     0,   437,     0,   411,   410,   264,   266,   268,     0,
       0,     0,    53,    54,     0,     0,     0,     0,    28,     0,
      25,   114,   110,   111,   113,   136,   135,     0,   137,   132,
       9,    10,   407,     0,   402,     0,   405,   400,     0,     0,
       0,   436,     0,   438,     0,   280,    94,    87,    96,    83,
      88,    89,    93,    92,    91,    86,     0,    84,    81,    90,
      85,    22,    55,    21,    31,    23,    35,    38,    24,    26,
       0,   131,   133,     0,   278,     0,     0,   282,     0,     0,
       0,   452,   286,   449,   286,   454,   281,   453,   297,    72,
      82,    95,     0,     0,    52,   112,   134,     0,     0,   145,
     153,   140,   279,     0,   403,   404,     0,     0,     0,     0,
     287,     0,   422,     0,     0,     0,     0,     0,   429,   414,
     412,   415,   416,   418,   408,   413,   417,   409,   456,   301,
     302,     0,     0,   298,   299,    98,    79,     0,     0,     0,
       0,   155,     0,     0,   150,   144,     0,     0,   138,     0,
       0,     0,   288,   286,   293,   284,     0,   451,   431,     0,
       0,     0,     0,   426,   424,   489,    13,    14,   492,   490,
       0,     0,     0,     0,   491,     0,   487,   488,     0,   461,
       0,   467,     0,   450,   430,     0,   457,   458,   460,    97,
      99,   304,   300,    73,    32,    36,    27,   296,   295,   145,
       0,   306,   308,   309,   310,   311,   312,   342,   342,   359,
     345,     0,   317,   318,   319,   320,   321,   148,   145,     0,
     152,     0,   170,     0,   283,     0,     0,   276,     0,     0,
       0,   433,   432,     0,     0,   427,   425,     0,   466,   465,
     468,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   463,     0,     0,     0,   482,   483,     0,     0,
     456,   428,   455,     0,   297,   297,     0,     0,   149,   154,
       0,     0,   313,   314,   363,   364,   365,   366,   367,   368,
     370,   315,     0,   361,   351,   352,   353,   354,   355,   356,
     370,   316,     0,   347,   147,   151,   143,   141,     0,     0,
     139,   401,   292,   290,   291,   289,     0,   280,   285,   294,
       0,   434,   423,   469,   471,   473,   474,   481,   475,   478,
     476,   477,   479,   472,     0,     0,     0,     0,   420,   462,
       0,   459,   100,   305,    33,    37,     0,     0,     0,   369,
       0,   357,     0,     0,   350,     0,     0,   194,   156,     0,
     202,   174,     0,     0,     0,     0,     0,   185,   186,     0,
       0,   192,   197,   196,     0,     0,   200,   204,   203,   207,
     201,     0,     0,   195,     0,     0,     0,     0,   233,   206,
     205,     0,     0,   210,   217,     0,     0,   213,   212,   214,
     211,     0,     0,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,     0,   171,   172,   277,   272,     0,   480,
       0,     0,   493,     0,     0,   419,   470,   307,   343,     0,
     349,     0,   360,   362,   358,   346,     0,   146,   142,     0,
       0,   157,   158,     0,   161,     0,   165,   176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,   209,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,   485,     0,   421,     0,   371,   348,     0,   168,     0,
       0,     0,     0,   167,     0,   255,   247,   248,   249,   250,
     251,   252,   253,   254,   258,   256,   259,   260,   261,   262,
     257,   372,   245,   178,   242,   243,   241,   244,   179,   183,
     181,   187,     0,   198,   199,   238,   239,   189,   190,   219,
     221,   220,   230,   191,   240,   218,   215,   216,   223,   222,
       0,   231,   232,   180,   236,   234,   237,   235,   173,     0,
     486,   494,   344,   193,   169,   177,   159,   163,   160,     0,
     164,     0,   246,   175,   373,     0,     0,   339,   326,   338,
     341,   337,     0,     0,     0,   340,   322,   334,   331,   330,
     333,   329,     0,   332,   324,   273,     0,   166,   392,   395,
     393,     0,     0,   394,   374,   375,   386,   391,   184,   182,
     327,   328,   188,     0,     0,     0,   229,     0,   162,     0,
     389,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   384,   385,   323,   336,   335,   325,   390,   377,   376,
     379,   380,   383,   381,   378,     0,     0,     0,   382,     0,
     396,     0,   387,   388,     0,   397
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
     281,   610,   611,   612,   613,   728,   617,   660,   480,   584,
     585,   688,   681,   682,    98,   137,   138,   139,   218,   487,
     283,   267,   258,   333,   297,   334,   335,   379,   312,   313,
     314,   357,   315,   445,   397,   744,   752,   745,   754,   746,
     747,   452,   471,   524,   601,   472,   473,   605,   461,   462,
     602,   463,   519,   733,   734,   764,   765,   766,   767,   811,
     140,   164,   165,   213,   214,   215,   216,   142,   298,   299,
     595,   300,   301,   302,   303,   304,   305,   172,   181,   173,
     182,   262,   263,   143,   306,   308,   365,   366,   367,   368,
     439,   359,   360,   361,   593
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -682
static const yytype_int16 yypact[] =
{
      15,   -20,   104,     8,  -682,  -682,    71,    86,   141,   151,
    -682,   160,   -16,   173,    84,    84,   183,  -682,   186,  -682,
     190,   215,  -682,   117,  -682,   209,  -682,  -682,  -682,  -682,
     229,  -682,   269,  -682,  -682,    84,   280,  -682,  -682,  -682,
     269,   282,  -682,  -682,    96,   573,   302,    12,  -682,   607,
     351,  -682,   361,   214,   378,   390,   394,  -682,  -682,   395,
     402,  -682,  -682,    22,    84,    84,  -682,    84,  -682,    84,
    -682,  -682,  -682,  -682,  -682,  -682,   431,   208,  -682,  -682,
      84,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,     0,   245,  -682,   153,  -682,   400,
    -682,   429,   416,   444,   433,   452,   455,  -682,    96,  -682,
    -682,   190,   190,    84,   190,    84,   190,  -682,   442,   383,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   478,   435,
     441,   439,   199,   206,   329,   329,  -682,   102,  -682,   447,
    -682,   343,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,   573,   573,   190,   573,   190,   319,    84,    84,
      84,    84,    29,   345,   478,  -682,  -682,  -682,   475,  -682,
    -682,  -682,   243,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,   546,  -682,    84,  -682,  -682,  -682,  -682,  -682,    84,
     473,   480,   573,  -682,   482,   474,   483,   485,    84,   -18,
    -682,  -682,  -682,   479,  -682,  -682,  -682,   171,  -682,  -682,
     481,   484,  -682,    17,  -682,   486,  -682,  -682,    84,   459,
     345,  -682,   345,  -682,   469,   492,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,   252,  -682,  -682,   507,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,   190,  -682,  -682,
      84,    29,  -682,    13,   472,   345,   356,   502,   476,   503,
     495,  -682,   365,  -682,   365,  -682,  -682,  -682,   228,  -682,
    -682,  -682,   473,   473,   573,  -682,  -682,   505,    84,   -38,
     508,   516,  -682,   535,  -682,  -682,   515,   290,   498,   356,
    -682,     5,  -682,   245,    -2,    58,   548,   345,  -682,  -682,
    -682,  -682,  -682,  -682,   548,  -682,  -682,   548,    58,  -682,
    -682,   145,   245,   228,  -682,  -682,   431,   453,   461,   522,
     226,   513,   679,   511,  -682,   425,    84,   528,  -682,   345,
     536,   523,   525,   194,   510,  -682,   458,  -682,  -682,   526,
     -30,   524,    28,  -682,  -682,  -682,   521,   529,  -682,  -682,
      58,    58,    58,    58,  -682,   415,  -682,  -682,   341,  -682,
     530,  -682,    10,  -682,  -682,   544,   519,  -682,   538,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   514,
      84,   547,  -682,  -682,  -682,  -682,  -682,   550,   550,   270,
     540,    84,  -682,  -682,  -682,  -682,  -682,  -682,   514,   557,
    -682,   106,   551,    50,  -682,   216,   231,   477,   290,   290,
     564,  -682,  -682,   571,    58,  -682,  -682,   504,   538,   538,
     538,   245,    58,    58,    58,    58,    58,    58,    58,    58,
      58,  -682,  -682,   -58,    58,   566,  -682,  -682,   548,    58,
      58,  -682,  -682,    58,   228,   228,   577,   593,  -682,  -682,
     594,   595,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
     569,  -682,   531,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
     569,  -682,   534,   574,   592,  -682,  -682,  -682,   620,   239,
    -682,  -682,  -682,  -682,  -682,  -682,   506,   492,  -682,  -682,
     622,  -682,   538,  -682,  -682,   655,   655,   538,   538,   538,
     538,   538,   538,   538,    58,   599,   601,   193,   487,   538,
     600,  -682,  -682,  -682,  -682,  -682,   606,   236,   626,  -682,
     270,  -682,   540,   633,  -682,    84,   638,   642,   245,   240,
    -682,  -682,   625,   628,   652,   650,   651,  -682,  -682,   653,
     654,  -682,  -682,  -682,   656,   684,  -682,  -682,  -682,   279,
    -682,   688,   692,  -682,   693,   694,   695,   708,  -682,  -682,
    -682,   716,   717,  -682,  -682,   733,   737,  -682,  -682,  -682,
    -682,   738,   742,  -682,  -682,  -682,  -682,  -682,   745,   746,
     751,   752,   753,   759,   747,  -682,  -682,  -682,   748,   538,
     193,    58,  -682,   238,   548,  -682,  -682,  -682,  -682,   780,
    -682,   761,  -682,  -682,  -682,  -682,   763,  -682,  -682,   772,
     177,   760,  -682,   773,  -682,    84,   781,  -682,   689,   775,
     233,    84,    84,   776,   771,   782,   783,  -682,  -682,   786,
     788,   790,   791,   -50,   810,    84,   793,   795,   212,   814,
     815,   792,   817,   818,   233,     2,   114,   239,   819,   253,
     538,  -682,   193,  -682,   796,  -682,  -682,   820,  -682,   800,
     240,   245,    84,   812,    84,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,   608,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   813,
     816,  -682,   509,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
     586,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,   801,
    -682,  -682,  -682,  -682,  -682,  -682,  -682,   821,  -682,    84,
    -682,    56,  -682,  -682,  -682,    84,    84,  -682,  -682,  -682,
    -682,  -682,   825,   828,   256,  -682,  -682,   -27,  -682,  -682,
    -682,  -682,   267,  -682,  -682,  -682,    84,  -682,  -682,  -682,
    -682,    56,    56,  -682,  -682,   292,   456,  -682,  -682,  -682,
    -682,  -682,  -682,   509,   509,   509,  -682,   586,  -682,   804,
    -682,    56,    56,    77,    77,    77,    77,    77,   785,    77,
     807,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,  -682,    77,   735,    77,  -682,    77,
    -682,   318,  -682,  -682,    77,  -682
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -682,  -682,  -682,  -682,   862,   -14,   552,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,   666,     4,  -682,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,   -21,  -682,   -44,  -682,  -135,  -682,
     -33,  -682,  -682,  -682,   843,  -682,  -682,   827,  -682,  -682,
    -682,  -682,  -682,   -72,   154,  -682,  -196,  -682,  -682,  -682,
    -682,  -682,  -682,  -682,    51,  -682,  -682,  -682,  -682,  -682,
     774,  -682,  -682,  -682,  -194,  -682,  -682,  -682,  -338,  -682,
    -682,  -682,  -682,   210,  -682,  -682,   213,  -682,  -682,  -682,
     222,   230,  -682,   189,  -682,  -682,   739,  -682,  -682,  -682,
    -682,   385,  -682,  -682,   542,   468,   470,  -682,   434,  -682,
     567,   -93,   437,  -682,  -682,  -682,  -682,  -681,   105,   110,
    -343,   496,  -682,  -682,  -682,  -682,   363,  -682,  -682,  -682,
    -682,   366,   417,  -682,  -682,  -682,  -408,    27,  -682,  -682,
    -682,  -682,   724,   560,   635,   -92,    25,  -682,  -301,  -682,
    -682,  -682,  -682,  -682,  -682,  -226,  -682,  -682,  -682,   719,
     711,   671,   597,  -682,   299,  -682,   457,  -682,   460,  -272,
    -682,  -682,  -682,  -482,   305
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -119
static const yytype_int16 yytable[] =
{
      28,    29,   127,   364,   117,   141,   364,    18,    19,   248,
       4,   774,    76,   252,     5,     6,   504,   412,   194,   109,
     196,    46,   122,   358,   322,   592,   254,    79,   124,   753,
    -118,   714,   125,    46,  -118,   699,     1,   441,   307,    79,
     270,   448,    26,    26,   342,   141,    27,    27,   277,   715,
     110,   110,   338,   110,   413,   110,    11,   276,   124,   481,
     475,   364,   125,   119,   151,   186,    46,   205,   278,   112,
     362,   114,    80,   116,   505,   206,   107,   255,   417,   418,
     419,   420,   108,   136,   775,   758,   759,   345,   346,   339,
     152,   153,   347,   155,   700,   157,   753,   225,    82,   110,
     348,   110,   291,   760,    10,   349,   758,   759,   592,   761,
     255,   350,    13,   323,    26,   351,   352,   154,    27,   156,
     128,   270,   270,   136,   760,    14,   129,   701,   260,    79,
     260,   121,    26,   195,   477,   197,    27,   508,    54,   319,
      18,    19,   492,   716,   201,   202,   203,   204,    83,   136,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   242,
       7,   717,   506,   279,   198,   130,   478,   509,   343,   224,
     721,   128,   340,   369,    20,   136,   183,   129,   292,   293,
      15,   294,   295,    26,   110,   296,   762,    27,   353,   763,
     370,   354,    16,    84,    85,    86,    87,    88,   415,    89,
     341,   344,   247,    55,   257,   260,   136,    17,   136,   205,
     763,    56,    54,    57,    58,    25,   130,   206,    90,    91,
     251,    92,   345,   124,    93,    30,   274,   125,   658,    59,
      60,    61,   589,    31,   355,   348,   275,   659,    26,   280,
     349,   136,    27,    33,   373,   261,    26,   261,   407,   416,
      27,   131,    38,   377,   290,   118,    26,   132,   133,    35,
      27,    26,   684,   685,   321,    27,   134,   135,   226,   227,
      26,   482,    39,   332,    27,   124,   527,    55,   228,   125,
     686,   285,   229,   136,   269,    56,   484,    57,    58,   528,
     598,   529,   651,   653,    41,   615,   599,   230,   652,   231,
      49,   174,   131,    59,    60,    61,   378,   720,   132,   133,
     772,    52,   400,   652,   337,   136,   773,   134,   135,   650,
      26,   776,   261,   530,    27,   331,   354,   777,   494,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,    77,   422,
     423,   687,   550,   779,   780,   551,   169,   170,   171,   552,
     553,   554,   555,   175,   176,   177,   449,   178,   179,   180,
      97,   232,   813,   798,   799,   210,   233,   474,   814,   211,
     309,   310,   556,    99,   557,   558,     4,   424,   627,   628,
       5,   483,   485,   100,   332,   332,   425,   426,   427,   428,
     169,   170,   171,   220,   234,   235,   454,   455,   456,   457,
     458,   459,   460,   706,   707,   429,   559,   560,   781,   782,
     561,   159,   160,   161,   102,   290,   317,   318,   562,   144,
     563,   794,   795,   184,   185,   614,   103,   564,   565,   566,
     104,   105,   567,   568,   569,   570,   571,   572,   106,   573,
     574,   575,   576,   577,   578,   579,   580,   291,    79,   581,
     145,   582,   583,   146,   783,   784,   430,   431,   432,   226,
     227,   433,   434,   435,   147,   436,   437,   226,   227,   228,
     148,   149,   158,   229,   150,   374,   163,   228,   167,   226,
     227,   229,   168,   375,   166,   183,   188,   189,   230,   228,
     231,   198,   785,   229,   219,   244,   230,   241,   231,   243,
     245,   607,   422,   423,   438,   616,   246,   250,   230,   259,
     231,   -11,   265,   271,   -12,   737,   256,   282,   286,   287,
     786,   183,   288,   292,   293,   289,   294,   295,   738,   739,
     296,   266,   327,   329,   330,   320,   422,   423,   326,   376,
     424,   740,   336,   380,   398,   399,   741,   401,   493,   425,
     426,   427,   428,   405,   404,   406,   742,   743,   614,   410,
     414,   409,   232,   411,   -11,   421,   322,   233,   429,   443,
     232,   787,   -12,   440,   424,   233,   788,   789,   790,   486,
     791,   792,   232,   425,   426,   427,   428,   233,   442,   476,
     450,   663,   748,   451,   514,   234,   235,   689,   690,   422,
     423,   479,   429,   234,   235,   738,   749,   490,   491,   507,
     515,   703,   518,   516,   517,   234,   235,   523,   750,   430,
     431,   432,   525,   751,   433,   434,   435,   665,   436,   437,
     291,   174,   520,   742,   743,   522,   616,   424,   727,   526,
     730,   588,   590,   586,   596,   600,   425,   426,   427,   428,
     597,   594,   606,   430,   431,   432,   608,   609,   433,   434,
     435,   618,   436,   437,   619,   429,   464,   465,   466,   467,
     468,   469,   470,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   620,   623,
     624,   424,   625,   175,   176,   177,   222,   178,   179,   180,
     425,   426,   427,   428,   183,   757,   292,   293,   665,   294,
     295,   768,   769,   296,   621,   622,   430,   431,   591,   429,
     626,   433,   434,   435,   629,   436,   437,   731,   630,   631,
     632,   633,   778,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   634,    83,    64,    65,    66,    67,
      68,    69,   635,   636,   666,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   637,
     430,   431,   432,   638,   639,   433,   434,   435,   640,   436,
     437,   641,   642,   392,   393,   394,   395,   643,   644,   645,
      84,    85,    86,    87,    88,   646,    89,   647,   648,   654,
     800,   801,   802,   803,   804,   655,   806,   656,   657,   662,
     661,   664,   683,   691,   692,    90,    91,   396,    92,   693,
     694,    93,   808,   695,   810,   696,   812,   697,   698,   702,
     704,   815,   705,   708,   709,   710,   711,   712,   719,   723,
     722,   724,   729,   735,   770,   755,   736,   771,   797,   805,
     807,   756,   809,     8,   371,   249,    37,    51,   123,   718,
     732,   726,   587,   725,   713,   408,   187,   489,   488,   513,
     372,   512,   796,   793,   453,   604,   603,   521,   217,   403,
     284,   221,   223,   264,   363,   649,     0,   510,     0,     0,
       0,     0,     0,   511
};

static const yytype_int16 yycheck[] =
{
      14,    15,    95,   304,    76,    97,   307,    23,    24,    27,
      30,    38,    45,   207,    34,    35,    74,    47,   153,    63,
     155,    35,    94,   295,    62,   507,     9,    27,    30,   710,
      30,    29,    34,    47,    34,    85,    21,    27,   264,    27,
     236,   379,    30,    30,    46,   137,    34,    34,    35,    47,
      64,    65,    47,    67,    84,    69,    48,   251,    30,     9,
     398,   362,    34,    77,   108,   137,    80,    38,    55,    65,
     296,    67,    60,    69,   132,    46,    54,    60,   350,   351,
     352,   353,    60,    97,   111,    29,    30,    29,    30,    84,
     111,   112,    34,   114,   144,   116,   777,   189,    47,   113,
      42,   115,    92,    47,     0,    47,    29,    30,   590,    53,
      60,    53,    41,   151,    30,    57,    58,   113,    34,   115,
      18,   317,   318,   137,    47,    39,    24,   177,   220,    27,
     222,    80,    30,   154,    28,   156,    34,   438,   116,   274,
      23,    24,   414,    29,   158,   159,   160,   161,   148,   163,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   192,
     180,    47,   434,   150,   182,    63,    60,   439,   170,   183,
     652,    18,   167,    28,   190,   189,   166,    24,   168,   169,
      39,   171,   172,    30,   198,   175,   130,    34,   130,   133,
      45,   133,    41,   193,   194,   195,   196,   197,   170,   199,
     293,   294,   198,   181,   218,   297,   220,    47,   222,    38,
     133,   189,   116,   191,   192,    42,    63,    46,   218,   219,
      49,   221,    29,    30,   224,    42,   247,    34,    51,   207,
     208,   209,   504,    47,   176,    42,   250,    60,    30,   253,
      47,   255,    34,    53,   316,   220,    30,   222,    54,   342,
      34,   149,    43,    27,    60,    47,    30,   155,   156,    44,
      34,    30,    29,    30,   278,    34,   164,   165,    16,    17,
      30,    55,    43,   287,    34,    30,    37,   181,    26,    34,
      47,   256,    30,   297,    32,   189,    55,   191,   192,    50,
      54,    52,    54,   594,    25,    55,    60,    45,    60,    47,
      20,    95,   149,   207,   208,   209,   320,    54,   155,   156,
      54,    29,   326,    60,   289,   329,    60,   164,   165,   591,
      30,    54,   297,    84,    34,    35,   133,    60,   421,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    46,     8,
       9,   118,   113,   761,   762,   116,   157,   158,   159,   120,
     121,   122,   123,   157,   158,   159,   380,   161,   162,   163,
      19,   119,    54,   781,   782,    30,   124,   391,    60,    34,
     152,   153,   143,    22,   145,   146,    30,    46,   109,   110,
      34,   405,   406,   179,   408,   409,    55,    56,    57,    58,
     157,   158,   159,   160,   152,   153,   136,   137,   138,   139,
     140,   141,   142,   201,   202,    74,   177,   178,   126,   127,
     181,    38,    39,    40,    46,    60,   272,   273,   189,    29,
     191,   774,   775,   134,   135,   528,    46,   198,   199,   200,
      46,    46,   203,   204,   205,   206,   207,   208,    46,   210,
     211,   212,   213,   214,   215,   216,   217,    92,    27,   220,
      31,   222,   223,    47,     8,     9,   125,   126,   127,    16,
      17,   130,   131,   132,    30,   134,   135,    16,    17,    26,
      47,    29,    40,    30,    29,    32,     8,    26,    47,    16,
      17,    30,    53,    32,    59,   166,    49,   154,    45,    26,
      47,   182,    46,    30,    29,    31,    45,    27,    47,    27,
      27,   525,     8,     9,   173,   529,    31,    38,    45,    60,
      47,    40,    53,    16,    40,    16,    40,    55,    26,    53,
      74,   166,    29,   168,   169,    40,   171,   172,    29,    30,
     175,    49,    26,     8,    29,    40,     8,     9,    40,    27,
      46,    42,    54,    40,    43,   130,    47,    29,    54,    55,
      56,    57,    58,    40,    28,    40,    57,    58,   661,   111,
      46,    61,   119,    47,    53,   160,    62,   124,    74,    60,
     119,   125,    53,    53,    46,   124,   130,   131,   132,   112,
     134,   135,   119,    55,    56,    57,    58,   124,    54,    42,
      53,   615,    16,    53,    27,   152,   153,   621,   622,     8,
       9,    60,    74,   152,   153,    29,    30,    53,    47,    53,
      27,   635,    53,    29,    29,   152,   153,    53,    42,   125,
     126,   127,    40,    47,   130,   131,   132,    29,   134,   135,
      92,    95,   111,    57,    58,   111,   660,    46,   662,    29,
     664,    29,    53,   147,    54,    29,    55,    56,    57,    58,
      54,   174,    29,   125,   126,   127,    28,    25,   130,   131,
     132,    46,   134,   135,    46,    74,   136,   137,   138,   139,
     140,   141,   142,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    46,    46,
      46,    46,    46,   157,   158,   159,   160,   161,   162,   163,
      55,    56,    57,    58,   166,   729,   168,   169,    29,   171,
     172,   735,   736,   175,    74,    74,   125,   126,   127,    74,
      46,   130,   131,   132,    46,   134,   135,   129,    46,    46,
      46,    46,   756,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    46,   148,   183,   184,   185,   186,
     187,   188,    46,    46,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    46,
     125,   126,   127,    46,    46,   130,   131,   132,    46,   134,
     135,    46,    46,   114,   115,   116,   117,    46,    46,    46,
     193,   194,   195,   196,   197,    46,   199,    60,    60,    29,
     783,   784,   785,   786,   787,    54,   789,    54,    46,    46,
      60,    40,    47,    47,    53,   218,   219,   148,   221,    47,
      47,   224,   805,    47,   807,    47,   809,    47,    47,    29,
      47,   814,    47,    29,    29,    53,    29,    29,    29,    29,
      54,    51,    40,    40,    29,    54,    40,    29,    54,    74,
      53,    40,   127,     1,   312,   199,    23,    40,    94,   647,
     681,   661,   487,   660,   644,   333,   137,   409,   408,   445,
     313,   444,   777,   773,   388,   522,   520,   470,   164,   329,
     255,   172,   181,   222,   297,   590,    -1,   440,    -1,    -1,
      -1,    -1,    -1,   443
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   226,   228,    30,    34,    35,   180,   229,   232,
       0,    48,   227,    41,    39,    39,    41,    47,    23,    24,
     190,   233,   256,   258,   259,    42,    30,    34,   230,   230,
      42,    47,   260,    53,   249,    44,   277,   259,    43,    43,
     261,    25,   262,   267,   250,   257,   230,   278,   279,    20,
     282,   262,    29,   263,   116,   181,   189,   191,   192,   207,
     208,   209,   251,   252,   183,   184,   185,   186,   187,   188,
     234,   235,   236,   237,   241,   245,   255,    46,   280,    27,
      60,   268,   279,   148,   193,   194,   195,   196,   197,   199,
     218,   219,   221,   224,   283,   284,   285,    19,   309,    22,
     179,   266,    46,    46,    46,    46,    46,    54,    60,   251,
     230,   240,   240,   242,   240,   246,   240,   268,    47,   230,
     281,   279,   268,   285,    30,    34,   231,   326,    18,    24,
      63,   149,   155,   156,   164,   165,   230,   310,   311,   312,
     355,   360,   362,   378,    29,    31,    47,    30,    47,    29,
      29,   251,   249,   249,   240,   249,   240,   249,    40,    38,
      39,    40,   286,     8,   356,   357,    59,    47,    53,   157,
     158,   159,   372,   374,    95,   157,   158,   159,   161,   162,
     163,   373,   375,   166,   379,   379,   268,   311,    49,   154,
     264,   253,   254,   255,   253,   249,   253,   249,   182,   238,
     239,   230,   230,   230,   230,    38,    46,   287,   288,   289,
      30,    34,   229,   358,   359,   360,   361,   357,   313,    29,
     160,   374,   160,   375,   230,   360,    16,    17,    26,    30,
      45,    47,   119,   124,   152,   153,   269,   270,   271,   272,
     273,    27,   255,    27,    31,    27,    31,   240,    27,   239,
      38,    49,   289,   290,     9,    60,    40,   230,   317,    60,
     360,   361,   376,   377,   376,    53,    49,   316,   274,    32,
     271,    16,   243,   247,   249,   230,   289,    35,    55,   150,
     230,   295,    55,   315,   359,   361,    26,    53,    29,    40,
      60,    92,   168,   169,   171,   172,   175,   319,   363,   364,
     366,   367,   368,   369,   370,   371,   379,   370,   380,   152,
     153,   275,   323,   324,   325,   327,   265,   269,   269,   253,
      40,   230,    62,   151,   293,   294,    40,    26,   292,     8,
      29,    35,   230,   318,   320,   321,    54,   361,    47,    84,
     167,   326,    46,   170,   326,    29,    30,    34,    42,    47,
      53,    57,    58,   130,   133,   176,   230,   326,   384,   386,
     387,   388,   370,   377,   363,   381,   382,   383,   384,    28,
      45,   231,   325,   268,    32,    32,    27,    27,   230,   322,
      40,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   114,   115,   116,   117,   148,   329,    43,   130,
     230,    29,   291,   358,    28,    40,    40,    54,   319,    61,
     111,    47,    47,    84,    46,   170,   326,   384,   384,   384,
     384,   160,     8,     9,    46,    55,    56,    57,    58,    74,
     125,   126,   127,   130,   131,   132,   134,   135,   173,   385,
      53,    27,    54,    60,   276,   328,   244,   248,   293,   230,
      53,    53,   336,   336,   136,   137,   138,   139,   140,   141,
     142,   343,   344,   346,   136,   137,   138,   139,   140,   141,
     142,   337,   340,   341,   230,   293,    42,    28,    60,    60,
     303,     9,    55,   230,    55,   230,   112,   314,   321,   320,
      53,    47,   384,    54,   326,   384,   384,   384,   384,   384,
     384,   384,   384,   384,    74,   132,   384,    53,   363,   384,
     381,   383,   327,   323,    27,    27,    29,    29,    53,   347,
     111,   347,   111,    53,   338,    40,    29,    37,    50,    52,
      84,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     113,   116,   120,   121,   122,   123,   143,   145,   146,   177,
     178,   181,   189,   191,   198,   199,   200,   203,   204,   205,
     206,   207,   208,   210,   211,   212,   213,   214,   215,   216,
     217,   220,   222,   223,   304,   305,   147,   316,    29,   384,
      53,   127,   388,   389,   174,   365,    54,    54,    54,    60,
      29,   339,   345,   346,   341,   342,    29,   230,    28,    25,
     296,   297,   298,   299,   326,    55,   230,   301,    46,    46,
      46,    74,    74,    46,    46,    46,    46,   109,   110,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    60,    60,   389,
     384,    54,    60,   363,    29,    54,    54,    46,    51,    60,
     302,    60,    46,   230,    40,    29,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   307,   308,    47,    29,    30,    47,   118,   306,   230,
     230,    47,    53,    47,    47,    47,    47,    47,    47,    85,
     144,   177,    29,   230,    47,    47,   201,   202,    29,    29,
      53,    29,    29,   306,    29,    47,    29,    47,   305,    29,
      54,   388,    54,    29,    51,   301,   298,   230,   300,    40,
     230,   129,   308,   348,   349,    40,    40,    16,    29,    30,
      42,    47,    57,    58,   330,   332,   334,   335,    16,    30,
      42,    47,   331,   332,   333,    54,    40,   230,    29,    30,
      47,    53,   130,   133,   350,   351,   352,   353,   230,   230,
      29,    29,    54,    60,    38,   111,    54,    60,   230,   351,
     351,   126,   127,     8,     9,    46,    74,   125,   130,   131,
     132,   134,   135,   334,   335,   335,   333,    54,   351,   351,
     352,   352,   352,   352,   352,    74,   352,    53,   352,   127,
     352,   354,   352,    54,    60,   352
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
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTRETURNS); }
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1425 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1426 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1427 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1428 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1429 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1430 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"left"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1431 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"right"); }
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 1432 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"center"); }
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 1433 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1434 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1435 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1436 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1437 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1438 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1439 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1440 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1441 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,(yyvsp[(3) - (3)].str)); }
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1442 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1443 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1444 "screen.yacc"
    { A4GL_get_fld()->not_null=1;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1446 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1447 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1448 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 1449 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 1450 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1451 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_HEADER,(yyvsp[(3) - (3)].str)); }
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1452 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1458 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1459 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1460 "screen.yacc"
    {sprintf((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1461 "screen.yacc"
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

  case 246:

/* Line 1464 of yacc.c  */
#line 1474 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1478 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1479 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1480 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1481 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 1482 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1483 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1484 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1485 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1487 "screen.yacc"
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

  case 256:

/* Line 1464 of yacc.c  */
#line 1522 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1523 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1524 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1525 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1526 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1527 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1528 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1541 "screen.yacc"
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

  case 270:

/* Line 1464 of yacc.c  */
#line 1551 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1557 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1568 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1568 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1573 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1576 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1582 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 1585 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1595 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1599 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 1603 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 1607 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 1611 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 1617 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 1621 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 1624 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 1628 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 1628 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 1635 "screen.yacc"
    {colno++;}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 1636 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 1649 "screen.yacc"
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

  case 304:

/* Line 1464 of yacc.c  */
#line 1661 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 1663 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 1674 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 1678 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=atol((yyvsp[(3) - (4)].str));
}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 1682 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 1686 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 1690 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 1694 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 1698 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 1702 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 1708 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 1712 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 1716 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 1720 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 1724 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 1728 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 1732 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 1735 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 1742 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 1746 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 328:

/* Line 1464 of yacc.c  */
#line 1751 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 1755 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 1762 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 1763 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 1765 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 1773 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 1776 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 1782 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
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
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 1792 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 1798 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 1801 "screen.yacc"
    {
		int n;
		 n=atol(acl_getenv("A4GL_DEFDECPREC"));
		sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str)))<<8)+n);
	}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 1806 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 1809 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 1811 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 1817 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 1821 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
#endif
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 1828 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 1836 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 1839 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 352:

/* Line 1464 of yacc.c  */
#line 1840 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 1841 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 1842 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 1843 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 1844 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 1846 "screen.yacc"
    {
#ifdef DEBUG
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
#endif
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 1855 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 1856 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 1859 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 1862 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 1866 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 1867 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 1868 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 1869 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 1870 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 1871 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 1873 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
#endif
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 1880 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 1884 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
#endif
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 1893 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 1893 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 1899 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 1906 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 1909 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 1915 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 1916 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 1917 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 1918 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 1919 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 1920 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 1921 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 1922 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 1923 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 1924 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 1925 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 1926 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 1927 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 1930 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 1937 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 1938 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 1939 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 1947 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 1951 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 1971 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 1981 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 1988 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 1997 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 2000 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"",0);
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2019 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2026 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2034 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2039 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2047 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2051 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2056 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2061 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2066 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2071 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2076 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 2085 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2094 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2095 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2104 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2112 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2118 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2124 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2130 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2138 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2143 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2153 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2163 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 2169 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 2175 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 2181 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 2191 "screen.yacc"
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

  case 436:

/* Line 1464 of yacc.c  */
#line 2203 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2211 "screen.yacc"
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

  case 438:

/* Line 1464 of yacc.c  */
#line 2223 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 2231 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2232 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2233 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2237 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 2238 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 2239 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 2240 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 2241 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 447:

/* Line 1464 of yacc.c  */
#line 2242 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 448:

/* Line 1464 of yacc.c  */
#line 2243 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2246 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2253 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2264 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2268 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2275 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2283 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2289 "screen.yacc"
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

  case 456:

/* Line 1464 of yacc.c  */
#line 2301 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2302 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2308 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2314 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2322 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2330 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str));}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2335 "screen.yacc"
    {strcpy((yyval.str),"AND");}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2336 "screen.yacc"
    {strcpy((yyval.str),"OR");}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2352 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2354 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2355 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2356 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2357 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2358 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2361 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2362 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2363 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2364 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2365 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2366 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2367 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2368 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2369 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2370 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2371 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2372 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2373 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2374 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2375 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2376 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2382 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2383 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2384 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2385 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2386 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2389 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2393 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1464 of yacc.c  */
#line 7004 "y.tab.c"
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
#line 2405 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




