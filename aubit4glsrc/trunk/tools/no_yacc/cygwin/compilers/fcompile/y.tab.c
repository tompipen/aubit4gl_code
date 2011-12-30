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
     KW_HEADER = 374,
     SQLONLY = 375,
     WIDGET = 376,
     CONFIG = 377,
     KW_NL = 378,
     COMPARISON = 379,
     KWOR = 380,
     KWAND = 381,
     KWAND1 = 382,
     KWWHERE = 383,
     KWNOT = 384,
     KWBETWEEN = 385,
     KWIN = 386,
     XVAL = 387,
     KWNULLCHK = 388,
     KWNOTNULLCHK = 389,
     YEAR = 390,
     MONTH = 391,
     DAY = 392,
     HOUR = 393,
     MINUTE = 394,
     SECOND = 395,
     FRACTION = 396,
     KW_JUSTIFY = 397,
     KW_CENTER = 398,
     KW_TABINDEX = 399,
     KW_NOT_NULL = 400,
     LISTBOX = 401,
     BUTTON = 402,
     KW_PANEL = 403,
     DISPLAYONLY = 404,
     ALLOWING = 405,
     KW_WS = 406,
     KW_TAB = 407,
     KW_MASTER_OF = 408,
     KW_BEFORE = 409,
     KW_AFTER = 410,
     KW_EDITADD = 411,
     KW_EDITUPDATE = 412,
     KW_REMOVE = 413,
     KW_OF = 414,
     KW_ADD = 415,
     KW_UPDATE = 416,
     KW_QUERY = 417,
     KW_ON_ENDING = 418,
     KW_ON_BEGINNING = 419,
     KW_CALL = 420,
     KW_BELL = 421,
     KW_ABORT = 422,
     KW_LET = 423,
     KW_EXITNOW = 424,
     KW_NEXTFIELD = 425,
     KW_IF = 426,
     KW_THEN = 427,
     KW_ELSE = 428,
     KW_BEGIN = 429,
     KW_TOTAL = 430,
     KW_RIGHT = 431,
     KW_ZEROFILL = 432,
     KW_USES_EXTENDED = 433,
     SPECIAL_DBNAME = 434,
     KW_ACTION = 435,
     KW_PAGE = 436,
     KW_HBOX = 437,
     KW_VBOX = 438,
     KW_GRID = 439,
     KW_GROUP = 440,
     KW_TABLE = 441,
     KW_FOLDER = 442,
     KW_STYLE = 443,
     KW_LAYOUT = 444,
     KW_HIDDEN = 445,
     KW_AUTOSIZE = 446,
     KW_TEXTEDIT = 447,
     KW_BUTTONEDIT = 448,
     KW_LABEL = 449,
     KW_EDIT = 450,
     KW_DATEEDIT = 451,
     KW_SCROLL = 452,
     KW_IMAGE = 453,
     KW_FONTPITCH = 454,
     KW_FIXED = 455,
     KW_VARIABLE = 456,
     KW_WANTNORETURNS = 457,
     KW_WANTTABS = 458,
     KW_AUTOSCALE = 459,
     KW_PIXELWIDTH = 460,
     KW_PIXELHEIGHT = 461,
     KW_BORDER = 462,
     KW_SCROLLBARS_BOTH = 463,
     KW_SCROLLBARS_V = 464,
     KW_SCROLLBARS_H = 465,
     KW_STRETCH_Y = 466,
     KW_STRETCH_BOTH = 467,
     KW_ITEMS = 468,
     KW_VALUEMAX = 469,
     KW_VALUEMIN = 470,
     KW_PROGRESSBAR = 471,
     KW_COMBOBOX = 472,
     OPTIONS = 473,
     KW_BROWSER = 474,
     KW_VALUECHECKED = 475,
     KW_VALUEUNCHECKED = 476,
     KW_CHECKBOX = 477
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
#define KW_HEADER 374
#define SQLONLY 375
#define WIDGET 376
#define CONFIG 377
#define KW_NL 378
#define COMPARISON 379
#define KWOR 380
#define KWAND 381
#define KWAND1 382
#define KWWHERE 383
#define KWNOT 384
#define KWBETWEEN 385
#define KWIN 386
#define XVAL 387
#define KWNULLCHK 388
#define KWNOTNULLCHK 389
#define YEAR 390
#define MONTH 391
#define DAY 392
#define HOUR 393
#define MINUTE 394
#define SECOND 395
#define FRACTION 396
#define KW_JUSTIFY 397
#define KW_CENTER 398
#define KW_TABINDEX 399
#define KW_NOT_NULL 400
#define LISTBOX 401
#define BUTTON 402
#define KW_PANEL 403
#define DISPLAYONLY 404
#define ALLOWING 405
#define KW_WS 406
#define KW_TAB 407
#define KW_MASTER_OF 408
#define KW_BEFORE 409
#define KW_AFTER 410
#define KW_EDITADD 411
#define KW_EDITUPDATE 412
#define KW_REMOVE 413
#define KW_OF 414
#define KW_ADD 415
#define KW_UPDATE 416
#define KW_QUERY 417
#define KW_ON_ENDING 418
#define KW_ON_BEGINNING 419
#define KW_CALL 420
#define KW_BELL 421
#define KW_ABORT 422
#define KW_LET 423
#define KW_EXITNOW 424
#define KW_NEXTFIELD 425
#define KW_IF 426
#define KW_THEN 427
#define KW_ELSE 428
#define KW_BEGIN 429
#define KW_TOTAL 430
#define KW_RIGHT 431
#define KW_ZEROFILL 432
#define KW_USES_EXTENDED 433
#define SPECIAL_DBNAME 434
#define KW_ACTION 435
#define KW_PAGE 436
#define KW_HBOX 437
#define KW_VBOX 438
#define KW_GRID 439
#define KW_GROUP 440
#define KW_TABLE 441
#define KW_FOLDER 442
#define KW_STYLE 443
#define KW_LAYOUT 444
#define KW_HIDDEN 445
#define KW_AUTOSIZE 446
#define KW_TEXTEDIT 447
#define KW_BUTTONEDIT 448
#define KW_LABEL 449
#define KW_EDIT 450
#define KW_DATEEDIT 451
#define KW_SCROLL 452
#define KW_IMAGE 453
#define KW_FONTPITCH 454
#define KW_FIXED 455
#define KW_VARIABLE 456
#define KW_WANTNORETURNS 457
#define KW_WANTTABS 458
#define KW_AUTOSCALE 459
#define KW_PIXELWIDTH 460
#define KW_PIXELHEIGHT 461
#define KW_BORDER 462
#define KW_SCROLLBARS_BOTH 463
#define KW_SCROLLBARS_V 464
#define KW_SCROLLBARS_H 465
#define KW_STRETCH_Y 466
#define KW_STRETCH_BOTH 467
#define KW_ITEMS 468
#define KW_VALUEMAX 469
#define KW_VALUEMIN 470
#define KW_PROGRESSBAR 471
#define KW_COMBOBOX 472
#define OPTIONS 473
#define KW_BROWSER 474
#define KW_VALUECHECKED 475
#define KW_VALUEUNCHECKED 476
#define KW_CHECKBOX 477




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
#line 663 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 675 "y.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   886

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  223
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  164
/* YYNRULES -- Number of rules.  */
#define YYNRULES  488
/* YYNRULES -- Number of states.  */
#define YYNSTATES  805

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   477

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
     215,   216,   217,   218,   219,   220,   221,   222
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
     133,   137,   141,   143,   147,   151,   153,   156,   160,   161,
     163,   165,   168,   170,   172,   174,   176,   178,   180,   181,
     187,   189,   192,   193,   197,   198,   203,   204,   205,   206,
     216,   217,   219,   220,   223,   228,   229,   231,   233,   236,
     238,   240,   242,   244,   246,   248,   250,   252,   254,   256,
     258,   260,   263,   264,   269,   271,   272,   277,   278,   282,
     284,   287,   291,   294,   295,   298,   300,   304,   308,   314,
     318,   322,   326,   328,   331,   332,   334,   336,   338,   340,
     342,   344,   346,   348,   350,   352,   354,   355,   361,   363,
     366,   370,   372,   374,   375,   376,   383,   384,   388,   394,
     398,   400,   401,   407,   411,   414,   419,   422,   427,   431,
     433,   438,   441,   442,   444,   446,   450,   454,   456,   460,
     462,   466,   468,   473,   476,   478,   481,   482,   485,   487,
     491,   493,   498,   501,   506,   510,   514,   518,   522,   528,
     532,   538,   540,   542,   546,   552,   556,   560,   564,   566,
     571,   573,   575,   577,   579,   583,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   606,   609,   611,   613,   615,
     617,   621,   625,   627,   631,   635,   639,   643,   647,   651,
     653,   655,   657,   659,   661,   667,   671,   675,   679,   681,
     685,   689,   693,   697,   701,   705,   709,   711,   713,   715,
     717,   719,   722,   724,   726,   728,   730,   732,   734,   736,
     738,   740,   742,   744,   746,   748,   750,   752,   754,   755,
     759,   761,   764,   766,   769,   772,   774,   775,   785,   798,
     800,   802,   803,   806,   807,   809,   810,   812,   814,   819,
     821,   825,   826,   828,   830,   834,   838,   842,   846,   848,
     852,   854,   856,   857,   859,   861,   864,   866,   868,   870,
     871,   876,   878,   880,   882,   884,   886,   888,   891,   894,
     897,   900,   902,   904,   906,   908,   910,   912,   916,   918,
     922,   924,   927,   930,   932,   934,   936,   938,   940,   942,
     946,   950,   952,   954,   956,   958,   960,   961,   965,   971,
     972,   976,   977,   981,   983,   986,   988,   990,   992,   994,
     996,   998,  1001,  1003,  1004,  1008,  1010,  1012,  1014,  1016,
    1018,  1020,  1022,  1024,  1027,  1028,  1032,  1033,  1035,  1038,
    1040,  1044,  1048,  1052,  1056,  1060,  1064,  1069,  1073,  1076,
    1079,  1081,  1087,  1093,  1096,  1100,  1102,  1104,  1106,  1108,
    1110,  1112,  1116,  1119,  1121,  1124,  1132,  1134,  1138,  1142,
    1144,  1146,  1148,  1154,  1160,  1163,  1166,  1168,  1170,  1172,
    1174,  1176,  1178,  1180,  1186,  1187,  1190,  1192,  1197,  1200,
    1204,  1207,  1211,  1215,  1217,  1220,  1223,  1227,  1231,  1236,
    1238,  1241,  1243,  1246,  1248,  1250,  1252,  1254,  1256,  1258,
    1260,  1262,  1264,  1266,  1268,  1272,  1276,  1278,  1283,  1284,
    1291,  1292,  1294,  1296,  1300,  1302,  1304,  1308,  1310,  1312,
    1315,  1318,  1320,  1323,  1327,  1332,  1336,  1340,  1344,  1348,
    1352,  1356,  1360,  1364,  1368,  1373,  1377,  1380,  1383,  1389,
    1395,  1402,  1404,  1406,  1408,  1410,  1412,  1414,  1416
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     224,     0,    -1,   226,   225,   230,   274,   279,   306,    -1,
      -1,    47,    46,    -1,    21,    34,    -1,    21,   229,    40,
      41,    42,    -1,    21,    34,    40,    41,    42,    -1,    21,
     229,    -1,    30,    -1,    30,    -1,   179,    -1,   179,    38,
     228,    -1,   227,    -1,   227,    38,   228,    -1,   255,    -1,
     253,    -1,   183,   237,   246,   250,    27,    -1,   182,   237,
     246,   250,    27,    -1,   185,   237,   246,   250,    27,    -1,
     187,   237,   246,   235,    27,    -1,   236,    -1,   235,   236,
      -1,   181,   237,   246,   250,    27,    -1,    -1,   228,    -1,
      -1,    -1,    -1,   184,   239,   237,   246,    31,   240,   266,
      32,   241,    27,    -1,    -1,    -1,    -1,   186,   243,   237,
     246,    31,   244,   266,    32,   245,    27,    -1,    -1,    -1,
      52,   247,   249,    53,    -1,   188,    45,    46,    -1,   190,
      -1,   191,    -1,   115,    45,    46,    -1,   180,    45,    30,
      -1,   207,    -1,   206,    45,    29,    -1,   205,    45,    29,
      -1,   248,    -1,   249,   248,    -1,   249,    59,   248,    -1,
      -1,   251,    -1,   252,    -1,   251,   252,    -1,   231,    -1,
     232,    -1,   233,    -1,   234,    -1,   238,    -1,   242,    -1,
      -1,   189,   246,   254,   252,   265,    -1,   256,    -1,   255,
     256,    -1,    -1,    24,   257,   259,    -1,    -1,    23,    46,
     258,   259,    -1,    -1,    -1,    -1,   264,   260,   263,    31,
     261,   266,    32,   262,   265,    -1,    -1,   178,    -1,    -1,
      25,    29,    -1,    25,    29,    22,    29,    -1,    -1,    27,
      -1,   268,    -1,   266,   268,    -1,   228,    -1,   267,    -1,
     270,    -1,   152,    -1,    17,    -1,    44,    -1,    46,    -1,
     269,    -1,   151,    -1,   123,    -1,   118,    -1,    16,    -1,
     269,    16,    -1,    -1,    26,   271,   272,    28,    -1,   324,
      -1,    -1,   272,    44,   273,   324,    -1,    -1,    43,   275,
     265,    -1,   276,    -1,   275,   276,    -1,   275,    59,   276,
      -1,   228,   277,    -1,    -1,    45,   278,    -1,   228,    -1,
     228,    37,   228,    -1,   228,    38,   228,    -1,   228,    38,
     228,    37,   228,    -1,   228,    39,   228,    -1,    46,    39,
     228,    -1,    20,   280,   265,    -1,   282,    -1,   280,   282,
      -1,    -1,   195,    -1,   192,    -1,   194,    -1,   196,    -1,
     193,    -1,   147,    -1,   198,    -1,   216,    -1,   217,    -1,
     222,    -1,   219,    -1,    -1,   281,   323,   283,   284,    48,
      -1,   286,    -1,   284,   286,    -1,   284,    48,   286,    -1,
      45,    -1,    37,    -1,    -1,    -1,   285,   287,   292,   289,
     288,   300,    -1,    -1,    26,    29,    28,    -1,    26,    29,
      59,    29,    28,    -1,   291,   129,    41,    -1,   291,    -1,
      -1,    61,    73,   228,    39,   228,    -1,    61,    73,   228,
      -1,    61,   326,    -1,    34,    39,   319,   290,    -1,   149,
     290,    -1,   149,   150,    42,   290,    -1,   228,    39,   228,
      -1,   228,    -1,    54,   228,    39,   228,    -1,    54,   228,
      -1,    -1,   294,    -1,   295,    -1,   294,    59,   295,    -1,
     296,    45,   297,    -1,   323,    -1,   228,    39,   228,    -1,
     228,    -1,   228,    39,   228,    -1,   228,    -1,    54,   228,
      39,   228,    -1,    54,   228,    -1,    50,    -1,    59,    50,
      -1,    -1,    59,   301,    -1,   302,    -1,   301,    59,   302,
      -1,    89,    -1,    90,    45,   304,   345,    -1,    51,   298,
      -1,    49,   293,   299,   298,    -1,    91,    45,    46,    -1,
      92,    45,   303,    -1,   218,    45,   303,    -1,    94,    73,
     228,    -1,    94,    73,   228,    39,   228,    -1,    93,    73,
     228,    -1,    93,    73,   228,    39,   228,    -1,    95,    -1,
      96,    -1,    97,    45,    46,    -1,    98,    45,    52,   327,
      53,    -1,   121,    45,    46,    -1,   122,    45,    46,    -1,
     180,    45,   228,    -1,    99,    -1,    36,    25,    45,    29,
      -1,    36,    -1,   120,    -1,   101,    -1,   100,    -1,   102,
      45,    46,    -1,   103,    45,    46,    -1,   104,    -1,   112,
      -1,    83,    -1,   106,    -1,   105,    -1,   177,    -1,   176,
      -1,   107,    -1,   107,   108,    -1,   107,   109,    -1,   190,
      -1,   204,    -1,   202,    -1,   203,    -1,   199,    45,   200,
      -1,   199,    45,   201,    -1,   197,    -1,   198,    45,    46,
      -1,   142,    45,    84,    -1,   142,    45,   176,    -1,   142,
      45,   143,    -1,   206,    45,    29,    -1,   205,    45,    29,
      -1,   208,    -1,   209,    -1,   210,    -1,   211,    -1,   212,
      -1,   213,    45,    52,   328,    53,    -1,   144,    45,    29,
      -1,   214,    45,    29,    -1,   215,    45,    29,    -1,   145,
      -1,   220,    45,    46,    -1,   221,    45,    46,    -1,   220,
      45,    29,    -1,   221,    45,    29,    -1,   115,    45,    46,
      -1,   119,    45,    46,    -1,   188,    45,    46,    -1,    46,
      -1,    29,    -1,    30,    -1,   117,    -1,   305,    -1,   304,
     305,    -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,    29,    -1,
      83,    -1,    88,    -1,    82,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    -1,    19,   307,   265,    -1,   308,
      -1,   307,   308,    -1,   309,    -1,   309,    48,    -1,    62,
      46,    -1,   359,    -1,    -1,    24,    58,   310,   314,    52,
     315,    53,   311,   313,    -1,   148,    52,    29,    59,    29,
      53,   110,    52,    29,    59,    29,    53,    -1,   352,    -1,
     375,    -1,    -1,   111,   146,    -1,    -1,    54,    -1,    -1,
      48,    -1,   228,    -1,   228,    26,    29,    28,    -1,   318,
      -1,   315,   316,   318,    -1,    -1,    59,    -1,   228,    -1,
     228,    39,   228,    -1,    34,    39,   228,    -1,   228,    39,
      54,    -1,    34,    39,    54,    -1,   317,    -1,   317,    60,
     317,    -1,   228,    -1,    27,    -1,    -1,   321,    -1,   322,
      -1,   321,   322,    -1,   151,    -1,   152,    -1,   228,    -1,
      -1,   320,   228,   325,   320,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,   333,
      -1,    70,   333,    -1,    71,   340,    -1,    72,   334,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   147,    -1,
     331,    -1,   327,    59,   331,    -1,   330,    -1,   328,    59,
     330,    -1,    29,    -1,    56,    29,    -1,    57,    29,    -1,
      46,    -1,    30,    -1,    16,    -1,   329,    -1,    41,    -1,
     332,    -1,   332,   110,   332,    -1,   332,    37,   332,    -1,
      46,    -1,    30,    -1,    16,    -1,   329,    -1,    41,    -1,
      -1,    52,    29,    53,    -1,    52,    29,    59,    29,    53,
      -1,    -1,   337,   110,   339,    -1,    -1,    52,    29,    53,
      -1,    29,    -1,   338,   335,    -1,   135,    -1,   136,    -1,
     137,    -1,   138,    -1,   139,    -1,   140,    -1,   141,   344,
      -1,   338,    -1,    -1,   341,   110,   342,    -1,   343,    -1,
     343,    -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,
     139,    -1,   140,    -1,   141,   344,    -1,    -1,    52,   336,
      53,    -1,    -1,   346,    -1,   128,   347,    -1,   348,    -1,
     348,   126,   348,    -1,   348,   125,   348,    -1,   349,   124,
     349,    -1,   349,     8,   349,    -1,   349,     9,   349,    -1,
     349,    73,   349,    -1,   349,   129,    73,   349,    -1,   349,
      45,   349,    -1,   349,   133,    -1,   349,   134,    -1,   349,
      -1,   349,   130,   349,   126,   349,    -1,   349,   131,    52,
     351,    53,    -1,   129,   348,    -1,    52,   348,    53,    -1,
     350,    -1,    29,    -1,    46,    -1,   132,    -1,    30,    -1,
     349,    -1,   351,    59,   349,    -1,    18,   353,    -1,   354,
      -1,   353,   354,    -1,     8,   355,     9,   312,     8,   355,
       9,    -1,   356,    -1,   355,    59,   356,    -1,   357,    39,
     358,    -1,   358,    -1,   228,    -1,   227,    -1,   154,   369,
     159,   373,   367,    -1,   155,   370,   159,   373,   367,    -1,
     164,   376,    -1,   163,   376,    -1,   363,    -1,   368,    -1,
     361,    -1,   364,    -1,   365,    -1,   376,    -1,   366,    -1,
     171,   381,   172,   360,   362,    -1,    -1,   173,   360,    -1,
     167,    -1,   168,   323,    45,   381,    -1,   170,   323,    -1,
     170,    45,   323,    -1,   170,   169,    -1,   170,    45,   169,
      -1,   174,   367,    27,    -1,   360,    -1,   367,   360,    -1,
      91,    46,    -1,    91,   166,    46,    -1,    91,    83,    46,
      -1,    91,   166,    83,    46,    -1,   371,    -1,   369,   371,
      -1,   372,    -1,   370,   372,    -1,   156,    -1,   157,    -1,
     158,    -1,   156,    -1,   160,    -1,   161,    -1,   162,    -1,
     158,    -1,    94,    -1,   157,    -1,   374,    -1,   373,   316,
     374,    -1,   357,    39,   358,    -1,   358,    -1,   357,   153,
     357,   313,    -1,    -1,   165,   228,    52,   377,   378,    53,
      -1,    -1,   379,    -1,   380,    -1,   379,    59,   380,    -1,
     381,    -1,   383,    -1,   381,   382,   381,    -1,   126,    -1,
     125,    -1,    57,   381,    -1,    56,   381,    -1,   385,    -1,
     129,   381,    -1,    52,   381,    53,    -1,   384,    52,   378,
      53,    -1,   175,   159,   323,    -1,   381,   124,   381,    -1,
     381,     8,   381,    -1,   381,     9,   381,    -1,   381,    54,
     381,    -1,   381,    56,   381,    -1,   381,    57,   381,    -1,
     381,    55,   381,    -1,   381,    73,   381,    -1,   381,   129,
      73,   381,    -1,   381,    45,   381,    -1,   381,   133,    -1,
     381,   134,    -1,   381,   130,   381,   126,   381,    -1,   381,
     131,    52,   386,    53,    -1,   381,   129,   131,    52,   386,
      53,    -1,   228,    -1,   323,    -1,    29,    -1,    46,    -1,
     132,    -1,    41,    -1,   385,    -1,   386,    59,   385,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   160,   161,   167,   170,   176,   179,   189,
     193,   197,   198,   199,   200,   205,   209,   216,   226,   235,
     248,   256,   266,   274,   287,   288,   293,   296,   299,   292,
     315,   318,   321,   314,   335,   338,   338,   344,   347,   350,
     353,   356,   359,   362,   363,   367,   368,   369,   373,   382,
     388,   398,   405,   407,   409,   411,   413,   415,   420,   420,
     430,   430,   433,   433,   446,   446,   465,   467,   470,   465,
     475,   475,   480,   481,   482,   494,   495,   500,   501,   504,
     519,   531,   532,   543,   554,   567,   579,   590,   595,   598,
     606,   607,   613,   612,   637,   640,   640,   658,   659,   662,
     663,   664,   667,   676,   677,   680,   681,   682,   684,   685,
     686,   692,   696,   696,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   717,   716,   747,   748,
     749,   752,   752,   755,   759,   755,  1091,  1092,  1098,  1108,
    1109,  1112,  1113,  1116,  1119,  1124,  1135,  1149,  1163,  1172,
    1194,  1203,  1215,  1220,  1226,  1235,  1244,  1251,  1253,  1256,
    1262,  1263,  1264,  1265,  1268,  1269,  1273,  1274,  1278,  1278,
    1281,  1286,  1308,  1332,  1340,  1341,  1342,  1343,  1348,  1353,
    1358,  1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,  1371,
    1376,  1381,  1383,  1385,  1386,  1387,  1388,  1389,  1390,  1391,
    1392,  1393,  1394,  1395,  1396,  1400,  1407,  1408,  1409,  1410,
    1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,
    1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1431,
    1432,  1433,  1434,  1435,  1436,  1437,  1443,  1444,  1445,  1446,
    1458,  1459,  1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,
    1472,  1507,  1508,  1509,  1510,  1511,  1512,  1513,  1517,  1518,
    1521,  1521,  1523,  1523,  1526,  1536,  1542,  1542,  1545,  1546,
    1547,  1551,  1551,  1553,  1553,  1556,  1556,  1558,  1561,  1567,
    1570,  1574,  1575,  1579,  1583,  1587,  1591,  1595,  1602,  1602,
    1606,  1609,  1613,  1613,  1616,  1616,  1620,  1621,  1634,  1644,
    1644,  1655,  1659,  1663,  1667,  1671,  1675,  1679,  1685,  1689,
    1693,  1697,  1701,  1705,  1709,  1712,  1719,  1719,  1723,  1723,
    1728,  1728,  1728,  1732,  1739,  1740,  1741,  1742,  1749,  1750,
    1753,  1759,  1766,  1767,  1768,  1769,  1775,  1778,  1779,  1782,
    1783,  1790,  1794,  1801,  1809,  1812,  1813,  1814,  1815,  1816,
    1817,  1818,  1826,  1828,  1829,  1832,  1835,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1853,  1857,  1866,  1866,  1872,  1878,
    1879,  1882,  1888,  1889,  1890,  1891,  1892,  1893,  1894,  1895,
    1896,  1897,  1898,  1899,  1900,  1903,  1910,  1911,  1912,  1917,
    1920,  1924,  1936,  1939,  1940,  1944,  1954,  1961,  1970,  1973,
    1985,  1988,  1992,  1999,  2007,  2012,  2020,  2024,  2029,  2034,
    2039,  2044,  2049,  2058,  2067,  2068,  2073,  2076,  2084,  2090,
    2096,  2102,  2111,  2116,  2126,  2136,  2142,  2148,  2154,  2164,
    2176,  2184,  2196,  2204,  2205,  2206,  2210,  2211,  2212,  2213,
    2214,  2215,  2216,  2219,  2226,  2237,  2241,  2248,  2256,  2256,
    2274,  2275,  2281,  2287,  2295,  2302,  2303,  2308,  2309,  2325,
    2327,  2328,  2329,  2330,  2331,  2334,  2335,  2336,  2337,  2338,
    2339,  2340,  2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,
    2349,  2352,  2355,  2356,  2357,  2358,  2359,  2362,  2366
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
  "KW_NONSPACE", "KW_HEADER", "SQLONLY", "WIDGET", "CONFIG", "KW_NL",
  "COMPARISON", "KWOR", "KWAND", "KWAND1", "KWWHERE", "KWNOT", "KWBETWEEN",
  "KWIN", "XVAL", "KWNULLCHK", "KWNOTNULLCHK", "YEAR", "MONTH", "DAY",
  "HOUR", "MINUTE", "SECOND", "FRACTION", "KW_JUSTIFY", "KW_CENTER",
  "KW_TABINDEX", "KW_NOT_NULL", "LISTBOX", "BUTTON", "KW_PANEL",
  "DISPLAYONLY", "ALLOWING", "KW_WS", "KW_TAB", "KW_MASTER_OF",
  "KW_BEFORE", "KW_AFTER", "KW_EDITADD", "KW_EDITUPDATE", "KW_REMOVE",
  "KW_OF", "KW_ADD", "KW_UPDATE", "KW_QUERY", "KW_ON_ENDING",
  "KW_ON_BEGINNING", "KW_CALL", "KW_BELL", "KW_ABORT", "KW_LET",
  "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF", "KW_THEN", "KW_ELSE", "KW_BEGIN",
  "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL", "KW_USES_EXTENDED",
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
  "form_def", "encoding_section", "database_section", "named_or_kw_st",
  "named_or_kw_any", "dbname", "screen_or_layout_section", "vbox_section",
  "hbox_section", "group_section", "folder_section", "pages", "page",
  "opt_layout_ident", "grid_section", "@1", "$@2", "$@3", "table_section",
  "@4", "$@5", "$@6", "layout_attributes", "$@7", "layout_attribute",
  "layout_attribute_list", "op_layout_items", "layout_items",
  "layout_container", "layout_section", "$@8", "screen_section",
  "screens_section", "$@9", "$@10", "screens_rest", "$@11", "$@12", "$@13",
  "op_extended", "op_size", "op_end", "screen_layout", "some_text",
  "screen_element", "ch_list", "field", "$@14", "field_element", "$@15",
  "op_table_section", "table_def_list", "table_def", "opequal",
  "table_qualifier", "attribute_section", "field_tag_list",
  "op_field_tag_type", "field_tag", "$@16", "fpart_list", "eq_or_colon",
  "fpart", "$@17", "$@18", "op_att", "field_datatype_null",
  "field_datatype", "field_type", "op_lu_ft_eq_c", "lu_ft_eq_c",
  "lu_ft_eq_c_i", "lu_ft", "lu_fc", "lu_joincol", "lu_join",
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
     475,   476,   477
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   223,   224,   225,   225,   226,   226,   226,   226,   227,
     228,   229,   229,   229,   229,   230,   230,   231,   232,   233,
     234,   235,   235,   236,   237,   237,   239,   240,   241,   238,
     243,   244,   245,   242,   246,   247,   246,   248,   248,   248,
     248,   248,   248,   248,   248,   249,   249,   249,   250,   250,
     251,   251,   252,   252,   252,   252,   252,   252,   254,   253,
     255,   255,   257,   256,   258,   256,   260,   261,   262,   259,
     263,   263,   264,   264,   264,   265,   265,   266,   266,   267,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     269,   269,   271,   270,   272,   273,   272,   274,   274,   275,
     275,   275,   276,   277,   277,   278,   278,   278,   278,   278,
     278,   279,   280,   280,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   283,   282,   284,   284,
     284,   285,   285,   287,   288,   286,   289,   289,   289,   290,
     290,   291,   291,   291,   291,   292,   292,   292,   292,   292,
     292,   292,   293,   293,   294,   294,   295,   296,   297,   297,
     298,   298,   298,   298,   299,   299,   300,   300,   301,   301,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   303,   303,   303,   303,
     304,   304,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   306,   306,
     307,   307,   308,   308,   309,   309,   310,   309,   309,   309,
     309,   311,   311,   312,   312,   313,   313,   314,   314,   315,
     315,   316,   316,   317,   317,   317,   317,   317,   318,   318,
     319,   319,   320,   320,   321,   321,   322,   322,   323,   325,
     324,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   327,   327,   328,   328,
     329,   329,   329,   330,   330,   330,   330,   330,   331,   331,
     331,   332,   332,   332,   332,   332,   333,   333,   333,   334,
     334,   335,   335,   336,   337,   338,   338,   338,   338,   338,
     338,   338,   339,   340,   340,   341,   342,   343,   343,   343,
     343,   343,   343,   343,   344,   344,   345,   345,   346,   347,
     347,   347,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   349,   349,   349,   349,   350,
     351,   351,   352,   353,   353,   354,   355,   355,   356,   356,
     357,   358,   359,   359,   359,   359,   360,   360,   360,   360,
     360,   360,   360,   361,   362,   362,   363,   364,   365,   365,
     365,   365,   366,   367,   367,   368,   368,   368,   368,   369,
     369,   370,   370,   371,   371,   371,   372,   372,   372,   372,
     372,   372,   372,   373,   373,   374,   374,   375,   377,   376,
     378,   378,   379,   379,   380,   381,   381,   382,   382,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   384,   385,   385,   385,   385,   385,   386,   386
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     5,     5,     2,     1,
       1,     1,     3,     1,     3,     1,     1,     5,     5,     5,
       5,     1,     2,     5,     0,     1,     0,     0,     0,    10,
       0,     0,     0,    10,     0,     0,     4,     3,     1,     1,
       3,     3,     1,     3,     3,     1,     2,     3,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     2,     0,     3,     0,     4,     0,     0,     0,     9,
       0,     1,     0,     2,     4,     0,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     4,     1,     0,     4,     0,     3,     1,
       2,     3,     2,     0,     2,     1,     3,     3,     5,     3,
       3,     3,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     1,     2,
       3,     1,     1,     0,     0,     6,     0,     3,     5,     3,
       1,     0,     5,     3,     2,     4,     2,     4,     3,     1,
       4,     2,     0,     1,     1,     3,     3,     1,     3,     1,
       3,     1,     4,     2,     1,     2,     0,     2,     1,     3,
       1,     4,     2,     4,     3,     3,     3,     3,     5,     3,
       5,     1,     1,     3,     5,     3,     3,     3,     1,     4,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     5,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       1,     2,     1,     2,     2,     1,     0,     9,    12,     1,
       1,     0,     2,     0,     1,     0,     1,     1,     4,     1,
       3,     0,     1,     1,     3,     3,     3,     3,     1,     3,
       1,     1,     0,     1,     1,     2,     1,     1,     1,     0,
       4,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     0,     3,     5,     0,
       3,     0,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     0,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     4,     3,     2,     2,
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
       0,     0,     0,     3,     9,     5,    11,    13,     8,     1,
       0,     0,     0,     0,     0,     0,     4,     0,    62,    34,
      97,    16,    15,    60,     0,    10,    12,    14,     0,    64,
      72,    35,    58,     0,     0,    61,     7,     6,    72,     0,
      63,    66,     0,     0,   103,    75,    99,   114,   258,    65,
      73,    70,     0,     0,     0,    38,    39,     0,     0,    42,
      45,     0,    24,    24,    26,    24,    30,    24,    52,    53,
      54,    55,    56,    57,    75,     0,   102,    76,     0,    98,
     100,   120,   116,   119,   117,   115,   118,   121,   122,   123,
     125,   124,    75,     0,   112,     0,     2,     0,    71,     0,
       0,     0,     0,     0,     0,    36,     0,    46,    25,    34,
      34,    24,    34,    24,    34,    59,     0,   105,   104,   101,
     111,   113,   298,   126,     0,     0,     0,     0,     0,     0,
       0,     0,   400,    75,   260,   262,   269,     0,   265,   270,
      74,    67,    40,    41,    37,    44,    43,    47,    48,    48,
      34,    48,    34,     0,     0,     0,     0,     0,     0,     0,
     392,   393,   266,   264,     0,   433,   434,   435,     0,   429,
     441,   436,   442,   440,   437,   438,   439,     0,   431,     0,
     405,   404,   259,   261,   263,     0,     0,     0,    49,    50,
       0,     0,     0,     0,    24,     0,    21,   110,   106,   107,
     109,   132,   131,     0,   133,   128,     9,   401,     0,   396,
       0,   399,   394,     0,     0,     0,   430,     0,   432,     0,
     275,    90,    83,    92,    84,    85,    89,    88,    87,    82,
      79,     0,    80,    77,    86,    81,    18,    51,    17,    27,
      19,    31,    34,    20,    22,     0,   127,   129,     0,   273,
       0,     0,   277,     0,     0,     0,   446,   281,   443,   281,
     448,   276,   447,   292,    68,    78,    91,     0,     0,    48,
     108,   130,     0,     0,   141,   149,   136,   274,     0,   397,
     398,     0,     0,     0,     0,   282,     0,   416,     0,     0,
       0,     0,     0,   423,   408,   406,   409,   410,   412,   402,
     407,   411,   403,   450,   296,   297,     0,     0,   293,   294,
      94,    75,     0,     0,     0,     0,   151,     0,     0,   146,
     140,     0,     0,   134,     0,     0,     0,   283,   281,   288,
     279,     0,   445,   425,     0,     0,     0,     0,   420,   418,
     483,   486,   484,     0,     0,     0,     0,   485,     0,   298,
     482,     0,   455,     0,   461,     0,   444,   424,     0,   451,
     452,   454,    93,    95,   299,   295,    69,    28,    32,    23,
     291,   290,   141,     0,   301,   302,   303,   304,   305,   306,
     336,   336,   353,   339,     0,   311,   312,   313,   314,   315,
     144,   141,     0,   148,     0,   166,     0,   278,     0,     0,
     271,     0,     0,     0,   427,   426,     0,     0,   421,   419,
       0,   460,   459,   462,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   458,   457,     0,     0,     0,   476,
     477,     0,     0,   450,   422,   449,     0,   292,   292,     0,
       0,   145,   150,     0,   307,   308,   357,   358,   359,   360,
     361,   362,   364,   309,     0,   355,   345,   346,   347,   348,
     349,   350,   364,   310,     0,   341,   143,   147,   139,   137,
       0,     0,   135,   395,   287,   285,   286,   284,     0,   275,
     280,   289,     0,   428,   417,   463,   465,   467,   468,   475,
     469,   472,   470,   471,   473,   466,     0,     0,     0,     0,
     414,   456,     0,   453,    96,   300,    29,    33,     0,     0,
     363,     0,   351,     0,     0,   344,     0,     0,   190,   152,
       0,   198,   170,     0,     0,     0,     0,     0,   181,   182,
       0,     0,   188,   193,   192,     0,     0,   196,   200,   199,
     203,   197,     0,     0,   191,     0,     0,     0,     0,   228,
     202,   201,     0,     0,   206,   212,     0,     0,   208,   209,
     207,     0,     0,   219,   220,   221,   222,   223,     0,     0,
       0,     0,     0,     0,   167,   168,   272,   267,     0,   474,
       0,     0,   487,     0,     0,   413,   464,   337,     0,   343,
       0,   354,   356,   352,   340,     0,   142,   138,     0,     0,
     153,   154,     0,   157,     0,   161,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   478,
     479,     0,   415,     0,   365,   342,     0,   164,     0,     0,
       0,     0,   163,     0,   250,   242,   243,   244,   245,   246,
     247,   248,   249,   253,   251,   254,   255,   256,   257,   252,
     366,   240,   174,   237,   238,   236,   239,   175,   179,   177,
     183,     0,   194,   195,   233,   234,   185,   186,   214,   216,
     215,   225,   187,   235,   213,   210,   211,   218,   217,     0,
     226,   227,   176,   231,   229,   232,   230,   169,     0,   480,
     488,   338,   189,   165,   173,   155,   159,   156,     0,   160,
       0,   241,   171,   367,     0,     0,   333,   320,   332,   335,
     331,     0,     0,     0,   334,   316,   328,   325,   324,   327,
     323,     0,   326,   318,   268,     0,   162,   386,   389,   387,
       0,     0,   388,   368,   369,   380,   385,   180,   178,   321,
     322,   184,     0,     0,     0,   224,     0,   158,     0,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     378,   379,   317,   330,   329,   319,   384,   371,   370,   373,
     374,   377,   375,   372,     0,     0,     0,   376,     0,   390,
       0,   381,   382,     0,   391
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,     3,   207,   349,     8,    20,    68,    69,
      70,    71,   195,   196,   109,    72,   111,   267,   439,    73,
     113,   268,   440,    32,    42,    60,    61,   187,   188,   189,
      21,    43,    22,    23,    30,    38,    40,    51,   186,   311,
      99,    41,    79,   231,   232,   233,   234,   235,   263,   306,
     437,    34,    45,    46,    76,   118,    48,    92,    93,    94,
     158,   203,   204,   205,   248,   395,   323,   319,   320,   276,
     599,   600,   601,   602,   717,   606,   649,   472,   574,   575,
     677,   670,   671,    96,   133,   134,   135,   213,   479,   278,
     262,   253,   328,   292,   329,   330,   372,   307,   308,   309,
     350,   310,   438,   390,   733,   741,   734,   743,   735,   736,
     444,   463,   515,   590,   464,   465,   594,   453,   454,   591,
     455,   510,   722,   723,   753,   754,   755,   756,   800,   136,
     160,   161,   208,   209,   210,   211,   138,   293,   294,   585,
     295,   296,   297,   298,   299,   300,   168,   177,   169,   178,
     257,   258,   139,   301,   303,   358,   359,   360,   361,   432,
     352,   353,   354,   583
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -662
static const yytype_int16 yypact[] =
{
      27,   -17,    19,   132,  -662,   150,   165,   174,   182,  -662,
     168,   -12,   176,   196,   196,   225,  -662,   201,  -662,   230,
     246,  -662,   220,  -662,   231,  -662,  -662,  -662,   249,  -662,
     268,  -662,  -662,   196,   278,  -662,  -662,  -662,   268,   276,
    -662,  -662,   343,   616,   264,    13,  -662,   566,   301,  -662,
     322,   169,   307,   309,   318,  -662,  -662,   325,   334,  -662,
    -662,    43,   196,   196,  -662,   196,  -662,   196,  -662,  -662,
    -662,  -662,  -662,  -662,   360,   163,  -662,  -662,   196,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,    -9,   196,  -662,   381,  -662,   361,  -662,   367,
     354,   374,   371,   389,   390,  -662,   343,  -662,  -662,   230,
     230,   196,   230,   196,   230,  -662,   382,   329,  -662,  -662,
    -662,  -662,  -662,  -662,   414,   365,   391,   375,   219,   469,
     271,   271,  -662,   335,  -662,   404,  -662,   300,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   616,   616,
     230,   616,   230,   274,   196,   196,   196,   196,    18,   429,
     414,  -662,  -662,  -662,   431,  -662,  -662,  -662,   273,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,   424,  -662,   196,
    -662,  -662,  -662,  -662,  -662,   196,   471,   442,   616,  -662,
     445,   444,   446,   450,   196,   -20,  -662,  -662,  -662,   439,
    -662,  -662,  -662,   208,  -662,  -662,   443,  -662,    26,  -662,
     452,  -662,  -662,   196,   425,   429,  -662,   429,  -662,   433,
     447,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,    78,  -662,  -662,   477,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,   230,  -662,  -662,   196,    18,  -662,    67,   451,
     429,   466,   474,   456,   473,   465,  -662,   136,  -662,   136,
    -662,  -662,  -662,   119,  -662,  -662,  -662,   471,   471,   616,
    -662,  -662,   475,   196,   -57,   480,   484,  -662,   504,  -662,
    -662,   487,    96,   467,   466,  -662,   -38,  -662,   196,     6,
     -15,   147,   429,  -662,  -662,  -662,  -662,  -662,  -662,   147,
    -662,  -662,   147,   -15,  -662,  -662,   177,   196,   119,  -662,
    -662,   360,   251,   448,   494,   164,   483,   679,   482,  -662,
     396,   196,   497,  -662,   429,   502,   493,   498,   204,   478,
    -662,   430,  -662,  -662,   495,    -2,   506,     9,  -662,  -662,
    -662,  -662,  -662,   -15,   -15,   -15,   -15,  -662,   380,   500,
    -662,   337,  -662,   501,  -662,     0,  -662,  -662,   505,   488,
    -662,   548,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,   499,   196,  -662,  -662,  -662,  -662,  -662,  -662,
     503,   503,   562,   636,   196,  -662,  -662,  -662,  -662,  -662,
    -662,   499,   520,  -662,    -3,   509,    44,  -662,    83,   103,
     454,    96,    96,   510,  -662,  -662,   531,   -15,  -662,  -662,
     519,   548,   548,   548,   196,   -15,   -15,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,  -662,  -662,   -44,   -15,   526,  -662,
    -662,   147,   -15,   -15,  -662,  -662,   -15,   119,   119,   560,
     563,  -662,  -662,   559,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,   543,  -662,   486,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,   543,  -662,   491,   556,   570,  -662,  -662,  -662,
     581,   236,  -662,  -662,  -662,  -662,  -662,  -662,   468,   447,
    -662,  -662,   583,  -662,   548,  -662,  -662,   684,   684,   548,
     548,   548,   548,   548,   548,   548,   -15,   567,   561,   379,
     440,   548,   571,  -662,  -662,  -662,  -662,  -662,   205,   591,
    -662,   562,  -662,   636,   603,  -662,   196,   605,   610,   196,
     126,  -662,  -662,   594,   596,   597,   573,   574,  -662,  -662,
     606,   609,  -662,  -662,  -662,   611,   612,  -662,  -662,  -662,
     241,  -662,   614,   615,  -662,   617,   621,   625,   626,  -662,
    -662,  -662,   630,   631,  -662,  -662,   635,   638,  -662,  -662,
    -662,   639,   643,  -662,  -662,  -662,  -662,  -662,   644,   648,
     651,   659,   661,   662,   602,  -662,  -662,  -662,   649,   548,
     379,   -15,  -662,   206,   147,  -662,  -662,  -662,   680,  -662,
     657,  -662,  -662,  -662,  -662,   677,  -662,  -662,   686,    68,
     674,  -662,   689,  -662,   196,   696,  -662,   755,   690,    28,
     196,   196,   691,   701,   708,   709,  -662,  -662,   717,   719,
     720,   721,   -51,   749,   196,   733,   734,   172,   758,   760,
     738,   762,   775,    28,    90,    94,   236,   776,   221,   548,
    -662,   379,  -662,   753,  -662,  -662,   778,  -662,   761,   126,
     196,   196,   773,   196,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
     640,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   777,   780,
    -662,   195,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   740,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   767,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,   782,  -662,   196,  -662,
     232,  -662,  -662,  -662,   196,   196,  -662,  -662,  -662,  -662,
    -662,   793,   794,   233,  -662,  -662,   -27,  -662,  -662,  -662,
    -662,   237,  -662,  -662,  -662,   196,  -662,  -662,  -662,  -662,
     232,   232,  -662,  -662,   258,   534,  -662,  -662,  -662,  -662,
    -662,  -662,   195,   195,   195,  -662,   740,  -662,   771,  -662,
     232,   232,    60,    60,    60,    60,    60,   582,    60,   797,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,    60,   699,    60,  -662,    60,  -662,
     263,  -662,  -662,    60,  -662
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -662,  -662,  -662,  -662,   826,   -13,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,   633,    21,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,   -43,  -662,   -45,  -662,   -81,  -662,   -19,
    -662,  -662,  -662,   829,  -662,  -662,   814,  -662,  -662,  -662,
    -662,  -662,   -69,   128,  -662,  -201,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,     1,  -662,  -662,  -662,  -662,  -662,   763,
    -662,  -662,  -662,  -130,  -662,  -662,  -662,  -209,  -662,  -662,
    -662,  -662,   203,  -662,  -662,   207,  -662,  -662,  -662,   218,
     224,  -662,   188,  -662,  -662,   726,  -662,  -662,  -662,  -662,
     383,  -662,  -662,   532,   459,   462,  -662,   426,  -662,   557,
     -91,   432,  -662,  -662,  -662,  -662,  -661,   101,   109,  -357,
     492,  -662,  -662,  -662,  -662,   359,  -662,  -662,  -662,  -662,
     363,   415,  -662,  -662,  -662,  -531,    72,  -662,  -662,  -662,
    -662,   716,   554,   629,   -86,   262,  -662,  -296,  -662,  -662,
    -662,  -662,  -662,  -662,  -231,  -662,  -662,  -662,   712,   704,
     665,   592,  -662,   284,  -662,   453,  -662,   449,  -268,  -662,
    -662,  -662,  -465,   303
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -482
static const yytype_int16 yytable[] =
{
      26,    27,   123,   357,   317,   115,   357,   243,   333,   137,
     763,    17,    18,     4,   340,    25,   107,     5,    77,     9,
      44,  -114,   351,   120,    74,   469,   341,   434,   302,   496,
     265,   342,    44,   688,   582,   249,    25,   343,   742,    25,
      77,   344,   345,    25,   405,   334,    80,   137,     1,   108,
     108,   337,   108,   473,   108,   201,   470,   673,   674,   357,
     355,   147,   117,   202,   182,    44,   148,   149,   190,   151,
     192,   153,    78,   247,   675,   410,   411,   412,   413,   119,
     122,   406,   132,   764,   110,   250,   112,   497,   114,   747,
     748,   286,   689,   318,   221,   222,   105,    25,   108,   220,
     108,   272,   106,   250,   223,   742,   749,   191,    25,   193,
     264,   265,   265,    25,   346,   582,   271,   347,   647,   703,
     132,   273,   224,   705,   225,   690,    25,   648,   335,   255,
     326,   255,   150,    25,   152,   500,   704,   474,    81,   484,
     706,   197,   198,   199,   200,   676,   132,   487,   488,   489,
     490,   491,   492,   493,   494,   495,    25,   476,    52,   498,
     348,   194,     6,   441,   501,   179,   219,   287,   288,   237,
     289,   290,   132,   230,   291,   338,   710,    19,   408,    10,
     604,   108,   467,    82,    83,    84,    85,    86,   314,    87,
      12,   370,   752,    25,    25,   285,   226,   336,   339,   269,
     252,   227,   132,    13,   132,   362,   255,    88,    89,   116,
      90,   726,    14,    91,    16,   242,   274,    24,   230,   768,
     769,   363,    15,    53,   727,   728,    25,   286,   579,   228,
     229,    54,   270,    55,    56,   275,   729,   132,   286,   787,
     788,   730,   366,    17,    18,   201,   409,    29,    57,    58,
      59,   731,   732,   202,   230,   230,   246,   400,   587,   640,
     316,   747,   748,   285,   588,   641,    28,   221,   222,   327,
     304,   305,   518,    36,   709,   122,   122,   223,   749,   132,
     641,    25,    31,   367,   750,   519,   761,   520,   642,    33,
     765,    37,   762,    39,   364,   224,   766,   225,    47,   230,
     230,   179,   371,   287,   288,    50,   289,   290,   393,    75,
     291,   132,   179,   639,   287,   288,   802,   289,   290,   521,
      95,   291,   803,   486,   122,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,    97,   415,   416,    98,   541,   616,
     617,   542,   100,   124,   101,   543,   544,   545,   546,   125,
     442,   751,    77,   102,   752,    25,   155,   156,   157,   226,
     103,   466,   695,   696,   227,   165,   166,   167,   547,   104,
     548,   549,   417,   770,   771,   475,   477,    77,   327,   327,
     140,   418,   419,   420,   421,   312,   313,   126,   141,   124,
     142,   122,   228,   229,   143,   125,   783,   784,   340,    25,
     422,    25,   550,   551,   180,   181,   552,   144,   145,   146,
     341,   154,   159,   162,   553,   342,   554,   164,   603,   165,
     166,   167,   215,   555,   556,   557,   179,   163,   558,   559,
     560,   561,   562,   126,   563,   564,   565,   566,   567,   568,
     569,   570,   184,   185,   571,   194,   572,   573,    52,   206,
     214,   423,   424,   425,   221,   222,   426,   427,   428,   236,
     429,   430,   238,   240,   223,   239,   245,   256,    25,   256,
     368,   241,   -10,   127,   254,   260,   122,   221,   222,   128,
     129,   251,   224,   266,   225,   261,     4,   223,   130,   131,
     281,    25,   283,   596,   284,   277,   122,   605,   282,   431,
     322,   347,   324,   280,   315,   224,   325,   225,   170,   321,
     331,   369,   373,    53,   391,   392,   394,   415,   416,   127,
     397,    54,   398,    55,    56,   128,   129,   399,   402,   414,
     403,   404,   772,   773,   130,   131,   332,   436,    57,    58,
      59,   407,  -481,   433,   256,   443,   415,   416,   435,   603,
     317,   468,   482,   170,   417,   478,   226,   122,   471,   415,
     416,   227,   485,   418,   419,   420,   421,   483,   499,   774,
     171,   172,   173,   217,   174,   175,   176,   506,   508,   226,
     507,   652,   422,   417,   227,   509,   511,   678,   679,   228,
     229,   513,   418,   419,   420,   421,   417,   775,   514,   516,
     517,   692,   578,   584,   576,   418,   419,   420,   421,   580,
     589,   422,   228,   229,   586,   171,   172,   173,   122,   174,
     175,   176,   595,   597,   422,   598,   605,   122,   716,   607,
     719,   608,   609,   423,   424,   425,   610,   611,   426,   427,
     428,   612,   429,   430,   613,   794,   614,   615,   776,   618,
     619,   636,   620,   777,   778,   779,   621,   780,   781,   654,
     622,   623,   423,   424,   425,   624,   625,   426,   427,   428,
     626,   429,   430,   627,   628,   423,   424,   581,   629,   630,
     426,   427,   428,   631,   429,   430,   632,   446,   447,   448,
     449,   450,   451,   452,   633,   746,   634,   635,   637,   643,
     644,   757,   758,    81,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   417,
     645,   646,   767,   650,   651,   653,   672,   680,   418,   419,
     420,   421,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   681,   682,   683,   737,   422,    82,    83,
      84,    85,    86,   684,    87,   685,   686,   687,   720,   727,
     738,   456,   457,   458,   459,   460,   461,   462,   691,   693,
     694,   739,    88,    89,   654,    90,   740,   697,    91,   698,
     699,   700,   385,   386,   387,   388,   731,   732,    62,    63,
      64,    65,    66,    67,   701,   708,   711,   712,   423,   424,
     425,   713,   718,   426,   427,   428,   724,   429,   430,   725,
     744,   745,   759,   760,   786,   798,   389,     7,   244,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   789,   790,   791,   792,   793,   796,
     795,    35,    49,   715,   707,   121,   714,   702,   721,   183,
     401,   481,   577,   480,   505,   365,   797,   785,   799,   504,
     801,   782,   593,   445,   592,   804,   212,   512,   396,   279,
     216,   218,   259,   638,   356,   503,   502
};

static const yytype_uint16 yycheck[] =
{
      13,    14,    93,   299,    61,    74,   302,    27,    46,    95,
      37,    23,    24,    30,    29,    30,    61,    34,    27,     0,
      33,    30,   290,    92,    43,    28,    41,    27,   259,    73,
     231,    46,    45,    84,   499,     9,    30,    52,   699,    30,
      27,    56,    57,    30,    46,    83,    45,   133,    21,    62,
      63,    45,    65,     9,    67,    37,    59,    29,    30,   355,
     291,   106,    75,    45,   133,    78,   109,   110,   149,   112,
     151,   114,    59,   203,    46,   343,   344,   345,   346,    78,
      93,    83,    95,   110,    63,    59,    65,   131,    67,    29,
      30,    91,   143,   150,    16,    17,    53,    30,   111,   185,
     113,    34,    59,    59,    26,   766,    46,   150,    30,   152,
      32,   312,   313,    30,   129,   580,   246,   132,    50,    29,
     133,    54,    44,    29,    46,   176,    30,    59,   166,   215,
      34,   217,   111,    30,   113,   431,    46,    54,   147,   407,
      46,   154,   155,   156,   157,   117,   159,   415,   416,   417,
     418,   419,   420,   421,   422,   423,    30,    54,   115,   427,
     175,   181,   179,   372,   432,   165,   179,   167,   168,   188,
     170,   171,   185,   186,   174,   169,   641,   189,   169,    47,
      54,   194,   391,   192,   193,   194,   195,   196,   269,   198,
      40,    27,   132,    30,    30,    59,   118,   288,   289,   242,
     213,   123,   215,    38,   217,    28,   292,   216,   217,    46,
     219,    16,    38,   222,    46,   194,   149,    41,   231,   750,
     751,    44,    40,   180,    29,    30,    30,    91,   496,   151,
     152,   188,   245,   190,   191,   248,    41,   250,    91,   770,
     771,    46,   311,    23,    24,    37,   337,    46,   205,   206,
     207,    56,    57,    45,   267,   268,    48,    53,    53,    53,
     273,    29,    30,    59,    59,    59,    41,    16,    17,   282,
     151,   152,    36,    42,    53,   288,   289,    26,    46,   292,
      59,    30,    52,    32,    52,    49,    53,    51,   584,    43,
      53,    42,    59,    25,   307,    44,    59,    46,    20,   312,
     313,   165,   315,   167,   168,    29,   170,   171,   321,    45,
     174,   324,   165,   581,   167,   168,    53,   170,   171,    83,
      19,   174,    59,   414,   337,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    22,     8,     9,   178,   112,   108,
     109,   115,    45,    18,    45,   119,   120,   121,   122,    24,
     373,   129,    27,    45,   132,    30,    37,    38,    39,   118,
      45,   384,   200,   201,   123,   156,   157,   158,   142,    45,
     144,   145,    45,   125,   126,   398,   399,    27,   401,   402,
      29,    54,    55,    56,    57,   267,   268,    62,    31,    18,
      46,   414,   151,   152,    30,    24,   763,   764,    29,    30,
      73,    30,   176,   177,   130,   131,   180,    46,    29,    29,
      41,    39,     8,    58,   188,    46,   190,    52,   519,   156,
     157,   158,   159,   197,   198,   199,   165,    46,   202,   203,
     204,   205,   206,    62,   208,   209,   210,   211,   212,   213,
     214,   215,    48,   153,   218,   181,   220,   221,   115,    30,
      29,   124,   125,   126,    16,    17,   129,   130,   131,    27,
     133,   134,    27,    27,    26,    31,    37,   215,    30,   217,
      32,    31,    39,   148,    59,    52,   499,    16,    17,   154,
     155,    39,    44,    16,    46,    48,    30,    26,   163,   164,
      26,    30,    29,   516,    39,    54,   519,   520,    52,   172,
      26,   132,     8,   251,    39,    44,    29,    46,    94,    39,
      53,    27,    39,   180,    42,   129,    29,     8,     9,   148,
      28,   188,    39,   190,   191,   154,   155,    39,    60,   159,
     110,    46,     8,     9,   163,   164,   284,    59,   205,   206,
     207,    45,    52,    52,   292,    52,     8,     9,    53,   650,
      61,    41,    52,    94,    45,   111,   118,   580,    59,     8,
       9,   123,    53,    54,    55,    56,    57,    46,    52,    45,
     156,   157,   158,   159,   160,   161,   162,    27,    29,   118,
      27,   604,    73,    45,   123,    52,   110,   610,   611,   151,
     152,   110,    54,    55,    56,    57,    45,    73,    52,    39,
      29,   624,    29,   173,   146,    54,    55,    56,    57,    52,
      29,    73,   151,   152,    53,   156,   157,   158,   641,   160,
     161,   162,    29,    28,    73,    25,   649,   650,   651,    45,
     653,    45,    45,   124,   125,   126,    73,    73,   129,   130,
     131,    45,   133,   134,    45,    73,    45,    45,   124,    45,
      45,    59,    45,   129,   130,   131,    45,   133,   134,    29,
      45,    45,   124,   125,   126,    45,    45,   129,   130,   131,
      45,   133,   134,    45,    45,   124,   125,   126,    45,    45,
     129,   130,   131,    45,   133,   134,    45,   135,   136,   137,
     138,   139,   140,   141,    45,   718,    45,    45,    59,    29,
      53,   724,   725,   147,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    45,
      53,    45,   745,    59,    45,    39,    46,    46,    54,    55,
      56,    57,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    52,    46,    46,    16,    73,   192,   193,
     194,   195,   196,    46,   198,    46,    46,    46,   128,    29,
      30,   135,   136,   137,   138,   139,   140,   141,    29,    46,
      46,    41,   216,   217,    29,   219,    46,    29,   222,    29,
      52,    29,   113,   114,   115,   116,    56,    57,   182,   183,
     184,   185,   186,   187,    29,    29,    53,    29,   124,   125,
     126,    50,    39,   129,   130,   131,    39,   133,   134,    39,
      53,    39,    29,    29,    53,   126,   147,     1,   195,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   772,   773,   774,   775,   776,    52,
     778,    22,    38,   650,   636,    92,   649,   633,   670,   133,
     328,   402,   479,   401,   438,   308,   794,   766,   796,   437,
     798,   762,   513,   381,   511,   803,   160,   462,   324,   250,
     168,   177,   217,   580,   292,   436,   433
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   224,   226,    30,    34,   179,   227,   229,     0,
      47,   225,    40,    38,    38,    40,    46,    23,    24,   189,
     230,   253,   255,   256,    41,    30,   228,   228,    41,    46,
     257,    52,   246,    43,   274,   256,    42,    42,   258,    25,
     259,   264,   247,   254,   228,   275,   276,    20,   279,   259,
      29,   260,   115,   180,   188,   190,   191,   205,   206,   207,
     248,   249,   182,   183,   184,   185,   186,   187,   231,   232,
     233,   234,   238,   242,   252,    45,   277,    27,    59,   265,
     276,   147,   192,   193,   194,   195,   196,   198,   216,   217,
     219,   222,   280,   281,   282,    19,   306,    22,   178,   263,
      45,    45,    45,    45,    45,    53,    59,   248,   228,   237,
     237,   239,   237,   243,   237,   265,    46,   228,   278,   276,
     265,   282,   228,   323,    18,    24,    62,   148,   154,   155,
     163,   164,   228,   307,   308,   309,   352,   357,   359,   375,
      29,    31,    46,    30,    46,    29,    29,   248,   246,   246,
     237,   246,   237,   246,    39,    37,    38,    39,   283,     8,
     353,   354,    58,    46,    52,   156,   157,   158,   369,   371,
      94,   156,   157,   158,   160,   161,   162,   370,   372,   165,
     376,   376,   265,   308,    48,   153,   261,   250,   251,   252,
     250,   246,   250,   246,   181,   235,   236,   228,   228,   228,
     228,    37,    45,   284,   285,   286,    30,   227,   355,   356,
     357,   358,   354,   310,    29,   159,   371,   159,   372,   228,
     357,    16,    17,    26,    44,    46,   118,   123,   151,   152,
     228,   266,   267,   268,   269,   270,    27,   252,    27,    31,
      27,    31,   237,    27,   236,    37,    48,   286,   287,     9,
      59,    39,   228,   314,    59,   357,   358,   373,   374,   373,
      52,    48,   313,   271,    32,   268,    16,   240,   244,   246,
     228,   286,    34,    54,   149,   228,   292,    54,   312,   356,
     358,    26,    52,    29,    39,    59,    91,   167,   168,   170,
     171,   174,   316,   360,   361,   363,   364,   365,   366,   367,
     368,   376,   367,   377,   151,   152,   272,   320,   321,   322,
     324,   262,   266,   266,   250,    39,   228,    61,   150,   290,
     291,    39,    26,   289,     8,    29,    34,   228,   315,   317,
     318,    53,   358,    46,    83,   166,   323,    45,   169,   323,
      29,    41,    46,    52,    56,    57,   129,   132,   175,   228,
     323,   381,   383,   384,   385,   367,   374,   360,   378,   379,
     380,   381,    28,    44,   228,   322,   265,    32,    32,    27,
      27,   228,   319,    39,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,   113,   114,   115,   116,   147,
     326,    42,   129,   228,    29,   288,   355,    28,    39,    39,
      53,   316,    60,   110,    46,    46,    83,    45,   169,   323,
     381,   381,   381,   381,   159,     8,     9,    45,    54,    55,
      56,    57,    73,   124,   125,   126,   129,   130,   131,   133,
     134,   172,   382,    52,    27,    53,    59,   273,   325,   241,
     245,   290,   228,    52,   333,   333,   135,   136,   137,   138,
     139,   140,   141,   340,   341,   343,   135,   136,   137,   138,
     139,   140,   141,   334,   337,   338,   228,   290,    41,    28,
      59,    59,   300,     9,    54,   228,    54,   228,   111,   311,
     318,   317,    52,    46,   381,    53,   323,   381,   381,   381,
     381,   381,   381,   381,   381,   381,    73,   131,   381,    52,
     360,   381,   378,   380,   324,   320,    27,    27,    29,    52,
     344,   110,   344,   110,    52,   335,    39,    29,    36,    49,
      51,    83,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   112,   115,   119,   120,   121,   122,   142,   144,   145,
     176,   177,   180,   188,   190,   197,   198,   199,   202,   203,
     204,   205,   206,   208,   209,   210,   211,   212,   213,   214,
     215,   218,   220,   221,   301,   302,   146,   313,    29,   381,
      52,   126,   385,   386,   173,   362,    53,    53,    59,    29,
     336,   342,   343,   338,   339,    29,   228,    28,    25,   293,
     294,   295,   296,   323,    54,   228,   298,    45,    45,    45,
      73,    73,    45,    45,    45,    45,   108,   109,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    59,    59,   386,   381,
      53,    59,   360,    29,    53,    53,    45,    50,    59,   299,
      59,    45,   228,    39,    29,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     304,   305,    46,    29,    30,    46,   117,   303,   228,   228,
      46,    52,    46,    46,    46,    46,    46,    46,    84,   143,
     176,    29,   228,    46,    46,   200,   201,    29,    29,    52,
      29,    29,   303,    29,    46,    29,    46,   302,    29,    53,
     385,    53,    29,    50,   298,   295,   228,   297,    39,   228,
     128,   305,   345,   346,    39,    39,    16,    29,    30,    41,
      46,    56,    57,   327,   329,   331,   332,    16,    30,    41,
      46,   328,   329,   330,    53,    39,   228,    29,    30,    46,
      52,   129,   132,   347,   348,   349,   350,   228,   228,    29,
      29,    53,    59,    37,   110,    53,    59,   228,   348,   348,
     125,   126,     8,     9,    45,    73,   124,   129,   130,   131,
     133,   134,   331,   332,   332,   330,    53,   348,   348,   349,
     349,   349,   349,   349,    73,   349,    52,   349,   126,   349,
     351,   349,    53,    59,   349
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
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
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
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=1;
}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 197 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 198 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 200 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 205 "screen.yacc"
    {
			the_form.layout=NULL;
			the_form.layout_attrib=NULL;
	}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 209 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 216 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 226 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_HBOX;
	}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 235 "screen.yacc"
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

/* Line 1464 of yacc.c  */
#line 248 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 256 "screen.yacc"
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

/* Line 1464 of yacc.c  */
#line 266 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 274 "screen.yacc"
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

/* Line 1464 of yacc.c  */
#line 287 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 293 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 296 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 299 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 300 "screen.yacc"
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

/* Line 1464 of yacc.c  */
#line 315 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 318 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 321 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 322 "screen.yacc"
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

/* Line 1464 of yacc.c  */
#line 335 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 338 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 338 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 344 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 347 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 350 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 353 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 356 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_ACTION, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 359 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_BORDER);
	}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 362 "screen.yacc"
    { add_str_layout_attrib(FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 363 "screen.yacc"
    { add_str_layout_attrib(FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 373 "screen.yacc"
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

  case 49:

/* Line 1464 of yacc.c  */
#line 382 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 388 "screen.yacc"
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

  case 51:

/* Line 1464 of yacc.c  */
#line 398 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 406 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 408 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 410 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 412 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 414 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 416 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 420 "screen.yacc"
    { 
		the_form.layout_attrib=(yyvsp[(2) - (2)].layout_attrib);
	}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 422 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(4) - (5)].layout);
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 433 "screen.yacc"
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

  case 64:

/* Line 1464 of yacc.c  */
#line 446 "screen.yacc"
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

  case 66:

/* Line 1464 of yacc.c  */
#line 465 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 467 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 470 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 475 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 482 "screen.yacc"
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

  case 79:

/* Line 1464 of yacc.c  */
#line 504 "screen.yacc"
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

  case 80:

/* Line 1464 of yacc.c  */
#line 519 "screen.yacc"
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

  case 81:

/* Line 1464 of yacc.c  */
#line 531 "screen.yacc"
    { ltab=0; }
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 532 "screen.yacc"
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

  case 83:

/* Line 1464 of yacc.c  */
#line 543 "screen.yacc"
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

  case 84:

/* Line 1464 of yacc.c  */
#line 554 "screen.yacc"
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

  case 85:

/* Line 1464 of yacc.c  */
#line 567 "screen.yacc"
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

  case 86:

/* Line 1464 of yacc.c  */
#line 579 "screen.yacc"
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

  case 87:

/* Line 1464 of yacc.c  */
#line 590 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 595 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 598 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 606 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 607 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 613 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 620 "screen.yacc"
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

  case 94:

/* Line 1464 of yacc.c  */
#line 637 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 640 "screen.yacc"
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

  case 96:

/* Line 1464 of yacc.c  */
#line 651 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 667 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 676 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 677 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 680 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 681 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 683 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 684 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 685 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 701 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 702 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 703 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 704 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 705 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 706 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 707 "screen.yacc"
    {strcpy((yyval.str),"Button");}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 708 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 709 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 710 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 711 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 712 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 717 "screen.yacc"
    {
			if (tagCaseInsensitive) {
				A4GL_make_downshift((yyvsp[(2) - (2)].str));
			}
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 725 "screen.yacc"
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

  case 133:

/* Line 1464 of yacc.c  */
#line 755 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 759 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	if (fld->tabname) {
		A4GL_make_downshift(fld->tabname);
	}
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
#ifdef DEBUG
	A4GL_debug("add color %d\n",FA_C_WHITE);
#endif
}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 773 "screen.yacc"
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

  case 137:

/* Line 1464 of yacc.c  */
#line 1092 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1098 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1108 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1109 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1112 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1113 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str),1));
		}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1116 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),"",1));
		}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1119 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1124 "screen.yacc"
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

  case 146:

/* Line 1464 of yacc.c  */
#line 1135 "screen.yacc"
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

  case 147:

/* Line 1464 of yacc.c  */
#line 1149 "screen.yacc"
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

  case 148:

/* Line 1464 of yacc.c  */
#line 1163 "screen.yacc"
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

  case 149:

/* Line 1464 of yacc.c  */
#line 1172 "screen.yacc"
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

  case 150:

/* Line 1464 of yacc.c  */
#line 1194 "screen.yacc"
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

  case 151:

/* Line 1464 of yacc.c  */
#line 1203 "screen.yacc"
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

  case 152:

/* Line 1464 of yacc.c  */
#line 1215 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1220 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (1)].lookups);
		}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1226 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1235 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1244 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1253 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1256 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1262 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1263 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1264 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1265 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 1281 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1286 "screen.yacc"
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

  case 172:

/* Line 1464 of yacc.c  */
#line 1308 "screen.yacc"
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

  case 173:

/* Line 1464 of yacc.c  */
#line 1332 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1340 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1341 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 1342 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 1343 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1348 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1353 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 1358 "screen.yacc"
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 1363 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 1364 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 1365 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 1366 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 1367 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1368 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 1369 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1370 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 1371 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); 
#ifdef DEBUG
A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); 
#endif
}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1376 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; 
#ifdef DEBUG
A4GL_debug("dynamic=-1"); 
#endif
}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 1381 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 1383 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1385 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1386 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1387 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 1388 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1389 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1390 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1391 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1392 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1393 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1394 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 1395 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 1396 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1400 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 1407 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1408 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1409 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1410 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1411 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 1412 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1413 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1414 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1415 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"left"); }
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1416 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"right"); }
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1417 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"center"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1418 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1419 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1420 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1421 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 1422 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 1423 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1424 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1425 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1426 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,(yyvsp[(3) - (3)].str)); }
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1427 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1428 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1429 "screen.yacc"
    { A4GL_get_fld()->not_null=1;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1431 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1432 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1433 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1434 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1435 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1436 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_HEADER,(yyvsp[(3) - (3)].str)); }
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1437 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1443 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 1444 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 1445 "screen.yacc"
    {sprintf((yyval.str),"\"%s\"",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1446 "screen.yacc"
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

  case 241:

/* Line 1464 of yacc.c  */
#line 1459 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1463 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1464 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1465 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1466 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1467 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1468 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1469 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1470 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1472 "screen.yacc"
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

  case 251:

/* Line 1464 of yacc.c  */
#line 1507 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1508 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1509 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1510 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1511 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1512 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1513 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1526 "screen.yacc"
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

  case 265:

/* Line 1464 of yacc.c  */
#line 1536 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1542 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1553 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1553 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1558 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1561 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1567 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1570 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1580 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1584 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 1588 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 1592 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1596 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1602 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 1606 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 1609 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 1613 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 1613 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 1620 "screen.yacc"
    {colno++;}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 1621 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 1634 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	if (tagCaseInsensitive) {
		A4GL_make_downshift((yyval.str));
	}
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 1644 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 1646 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	if (tagCaseInsensitive) {
		A4GL_make_downshift((yyval.str));
	}
}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 1655 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 1659 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 1663 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 1667 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 1671 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 1675 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 1679 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 1685 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 1689 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 1693 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 1697 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 1701 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 1705 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 1709 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 1712 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 1719 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 1723 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 1728 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 1732 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 1739 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 1740 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 1742 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 1750 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 1753 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 1759 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 1766 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 1767 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 1768 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 1769 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 336:

/* Line 1464 of yacc.c  */
#line 1775 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 1778 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 1779 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 1782 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 1784 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 1790 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 1794 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
#endif
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 1801 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 1809 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 1812 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 1813 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 1814 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 1815 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 1816 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 350:

/* Line 1464 of yacc.c  */
#line 1817 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 351:

/* Line 1464 of yacc.c  */
#line 1819 "screen.yacc"
    {
#ifdef DEBUG
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
#endif
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 1828 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 354:

/* Line 1464 of yacc.c  */
#line 1829 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 355:

/* Line 1464 of yacc.c  */
#line 1832 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 356:

/* Line 1464 of yacc.c  */
#line 1835 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 357:

/* Line 1464 of yacc.c  */
#line 1839 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 358:

/* Line 1464 of yacc.c  */
#line 1840 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 1841 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 1842 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 1843 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 1844 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 1846 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
#endif
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 1853 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 1857 "screen.yacc"
    {
#ifdef DEBUG
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
#endif
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 1866 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 1866 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 1872 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 1879 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 1882 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 1888 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 1889 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 1890 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 1891 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 376:

/* Line 1464 of yacc.c  */
#line 1892 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 377:

/* Line 1464 of yacc.c  */
#line 1893 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 1894 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 1895 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 1896 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 1897 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 382:

/* Line 1464 of yacc.c  */
#line 1898 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 383:

/* Line 1464 of yacc.c  */
#line 1899 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 384:

/* Line 1464 of yacc.c  */
#line 1900 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 1903 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 386:

/* Line 1464 of yacc.c  */
#line 1910 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 1911 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 388:

/* Line 1464 of yacc.c  */
#line 1912 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 390:

/* Line 1464 of yacc.c  */
#line 1920 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 1924 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 1944 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 1954 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 1961 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 1970 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 1973 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"",0);
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 1992 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 1999 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2007 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 2012 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2020 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2024 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2029 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2034 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2039 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2044 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2049 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2058 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2067 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2068 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2077 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2085 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 2091 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2097 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2103 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2111 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2116 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2126 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2136 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2142 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2148 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2154 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2164 "screen.yacc"
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

  case 430:

/* Line 1464 of yacc.c  */
#line 2176 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2184 "screen.yacc"
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

  case 432:

/* Line 1464 of yacc.c  */
#line 2196 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 433:

/* Line 1464 of yacc.c  */
#line 2204 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 2205 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 435:

/* Line 1464 of yacc.c  */
#line 2206 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2210 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2211 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 438:

/* Line 1464 of yacc.c  */
#line 2212 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 439:

/* Line 1464 of yacc.c  */
#line 2213 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2214 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2215 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2216 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 2219 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 2226 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 445:

/* Line 1464 of yacc.c  */
#line 2237 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 446:

/* Line 1464 of yacc.c  */
#line 2241 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 447:

/* Line 1464 of yacc.c  */
#line 2248 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 448:

/* Line 1464 of yacc.c  */
#line 2256 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2262 "screen.yacc"
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

  case 450:

/* Line 1464 of yacc.c  */
#line 2274 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2275 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2281 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2287 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2295 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2303 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str));}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2308 "screen.yacc"
    {strcpy((yyval.str),"AND");}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2309 "screen.yacc"
    {strcpy((yyval.str),"OR");}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2325 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2327 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2328 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2329 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2330 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2331 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2334 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2335 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2336 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2337 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2338 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2339 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2340 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2341 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2342 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2343 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2344 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2345 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2346 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2347 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2348 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2349 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2355 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2356 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2357 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2358 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2359 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2362 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2366 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1464 of yacc.c  */
#line 6909 "y.tab.c"
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
#line 2378 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




