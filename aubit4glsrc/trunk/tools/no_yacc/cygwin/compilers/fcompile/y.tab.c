
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
#define YYLAST   874

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  222
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  163
/* YYNRULES -- Number of rules.  */
#define YYNRULES  482
/* YYNRULES -- Number of states.  */
#define YYNSTATES  793

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
     160,   162,   164,   166,   168,   170,   172,   173,   179,   181,
     184,   185,   189,   190,   195,   196,   197,   198,   208,   209,
     211,   212,   215,   220,   221,   223,   225,   228,   230,   232,
     234,   236,   238,   240,   242,   244,   246,   248,   250,   252,
     255,   256,   261,   263,   264,   269,   270,   274,   276,   279,
     283,   286,   287,   290,   292,   296,   300,   306,   310,   314,
     318,   320,   323,   324,   326,   328,   330,   332,   334,   336,
     338,   340,   342,   344,   346,   347,   353,   355,   358,   362,
     364,   366,   367,   368,   375,   376,   380,   386,   390,   392,
     393,   399,   403,   406,   411,   414,   419,   423,   425,   430,
     433,   435,   439,   443,   445,   449,   451,   455,   457,   462,
     465,   467,   470,   471,   474,   476,   480,   482,   487,   490,
     495,   499,   503,   507,   511,   517,   521,   527,   529,   531,
     535,   541,   545,   549,   553,   555,   560,   562,   564,   566,
     568,   572,   576,   578,   580,   582,   584,   586,   588,   590,
     592,   595,   598,   600,   602,   604,   606,   610,   614,   616,
     620,   624,   628,   632,   636,   640,   642,   644,   646,   648,
     650,   656,   660,   664,   668,   670,   674,   678,   682,   686,
     690,   694,   696,   698,   700,   702,   705,   707,   709,   711,
     713,   715,   717,   719,   721,   723,   725,   727,   729,   731,
     733,   735,   737,   738,   742,   744,   747,   749,   752,   755,
     757,   758,   768,   781,   783,   785,   786,   789,   790,   792,
     793,   795,   797,   802,   804,   808,   809,   811,   813,   817,
     821,   825,   829,   831,   835,   837,   839,   840,   842,   844,
     847,   849,   851,   853,   854,   859,   861,   863,   865,   867,
     869,   871,   874,   877,   880,   883,   885,   887,   889,   891,
     893,   895,   899,   901,   905,   907,   910,   913,   915,   917,
     919,   921,   923,   925,   929,   933,   935,   937,   939,   941,
     943,   944,   948,   954,   955,   959,   960,   964,   966,   969,
     971,   973,   975,   977,   979,   981,   984,   986,   987,   991,
     993,   995,   997,   999,  1001,  1003,  1005,  1007,  1010,  1011,
    1015,  1016,  1018,  1021,  1023,  1027,  1031,  1035,  1039,  1043,
    1047,  1052,  1056,  1059,  1062,  1064,  1070,  1076,  1079,  1083,
    1085,  1087,  1089,  1091,  1093,  1095,  1099,  1102,  1104,  1107,
    1115,  1117,  1121,  1125,  1127,  1129,  1131,  1137,  1143,  1146,
    1149,  1151,  1153,  1155,  1157,  1159,  1161,  1163,  1169,  1170,
    1173,  1175,  1180,  1183,  1187,  1190,  1194,  1198,  1200,  1203,
    1206,  1210,  1214,  1219,  1221,  1224,  1226,  1229,  1231,  1233,
    1235,  1237,  1239,  1241,  1243,  1245,  1247,  1249,  1251,  1255,
    1259,  1261,  1266,  1267,  1274,  1275,  1277,  1279,  1283,  1285,
    1287,  1291,  1293,  1295,  1298,  1301,  1303,  1306,  1310,  1315,
    1319,  1323,  1327,  1331,  1335,  1339,  1343,  1347,  1351,  1356,
    1360,  1363,  1366,  1372,  1378,  1385,  1387,  1389,  1391,  1393,
    1395,  1397,  1399
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     223,     0,    -1,   225,   224,   229,   273,   278,   304,    -1,
      -1,    47,    46,    -1,    21,    34,    -1,    21,   228,    40,
      41,    42,    -1,    21,    34,    40,    41,    42,    -1,    21,
     228,    -1,    30,    -1,    30,    -1,   178,    -1,   178,    38,
     227,    -1,   226,    -1,   226,    38,   227,    -1,   254,    -1,
     252,    -1,   182,   236,   245,   249,    27,    -1,   181,   236,
     245,   249,    27,    -1,   184,   236,   245,   249,    27,    -1,
     186,   236,   245,   234,    27,    -1,   235,    -1,   234,   235,
      -1,   180,   236,   245,   249,    27,    -1,    -1,   227,    -1,
      -1,    -1,    -1,   183,   238,   236,   245,    31,   239,   265,
      32,   240,    27,    -1,    -1,    -1,    -1,   185,   242,   236,
     245,    31,   243,   265,    32,   244,    27,    -1,    -1,    -1,
      52,   246,   248,    53,    -1,   187,    45,    46,    -1,   189,
      -1,   190,    -1,   115,    45,    46,    -1,   179,    45,    30,
      -1,   206,    -1,   247,    -1,   248,   247,    -1,   248,    59,
     247,    -1,    -1,   250,    -1,   251,    -1,   250,   251,    -1,
     230,    -1,   231,    -1,   232,    -1,   233,    -1,   237,    -1,
     241,    -1,    -1,   188,   245,   253,   251,   264,    -1,   255,
      -1,   254,   255,    -1,    -1,    24,   256,   258,    -1,    -1,
      23,    46,   257,   258,    -1,    -1,    -1,    -1,   263,   259,
     262,    31,   260,   265,    32,   261,   264,    -1,    -1,   177,
      -1,    -1,    25,    29,    -1,    25,    29,    22,    29,    -1,
      -1,    27,    -1,   267,    -1,   265,   267,    -1,   227,    -1,
     266,    -1,   269,    -1,   151,    -1,    17,    -1,    44,    -1,
      46,    -1,   268,    -1,   150,    -1,   122,    -1,   118,    -1,
      16,    -1,   268,    16,    -1,    -1,    26,   270,   271,    28,
      -1,   322,    -1,    -1,   271,    44,   272,   322,    -1,    -1,
      43,   274,   264,    -1,   275,    -1,   274,   275,    -1,   274,
      59,   275,    -1,   227,   276,    -1,    -1,    45,   277,    -1,
     227,    -1,   227,    37,   227,    -1,   227,    38,   227,    -1,
     227,    38,   227,    37,   227,    -1,   227,    39,   227,    -1,
      46,    39,   227,    -1,    20,   279,   264,    -1,   281,    -1,
     279,   281,    -1,    -1,   194,    -1,   191,    -1,   193,    -1,
     195,    -1,   192,    -1,   146,    -1,   197,    -1,   215,    -1,
     216,    -1,   221,    -1,   218,    -1,    -1,   280,   321,   282,
     283,    48,    -1,   285,    -1,   283,   285,    -1,   283,    48,
     285,    -1,    45,    -1,    37,    -1,    -1,    -1,   284,   286,
     291,   288,   287,   298,    -1,    -1,    26,    29,    28,    -1,
      26,    29,    59,    29,    28,    -1,   290,   128,    41,    -1,
     290,    -1,    -1,    61,    73,   227,    39,   227,    -1,    61,
      73,   227,    -1,    61,   324,    -1,    34,    39,   317,   289,
      -1,   148,   289,    -1,   148,   149,    42,   289,    -1,   227,
      39,   227,    -1,   227,    -1,    54,   227,    39,   227,    -1,
      54,   227,    -1,   293,    -1,   292,    59,   293,    -1,   294,
      45,   295,    -1,   321,    -1,   227,    39,   227,    -1,   227,
      -1,   227,    39,   227,    -1,   227,    -1,    54,   227,    39,
     227,    -1,    54,   227,    -1,    50,    -1,    59,    50,    -1,
      -1,    59,   299,    -1,   300,    -1,   299,    59,   300,    -1,
      89,    -1,    90,    45,   302,   343,    -1,    51,   296,    -1,
      49,   292,   297,   296,    -1,    91,    45,    46,    -1,    92,
      45,   301,    -1,   217,    45,   301,    -1,    94,    73,   227,
      -1,    94,    73,   227,    39,   227,    -1,    93,    73,   227,
      -1,    93,    73,   227,    39,   227,    -1,    95,    -1,    96,
      -1,    97,    45,    46,    -1,    98,    45,    52,   325,    53,
      -1,   120,    45,    46,    -1,   121,    45,    46,    -1,   179,
      45,   227,    -1,    99,    -1,    36,    25,    45,    29,    -1,
      36,    -1,   119,    -1,   101,    -1,   100,    -1,   102,    45,
      46,    -1,   103,    45,    46,    -1,   104,    -1,   112,    -1,
      83,    -1,   106,    -1,   105,    -1,   176,    -1,   175,    -1,
     107,    -1,   107,   108,    -1,   107,   109,    -1,   189,    -1,
     203,    -1,   201,    -1,   202,    -1,   198,    45,   199,    -1,
     198,    45,   200,    -1,   196,    -1,   197,    45,    46,    -1,
     141,    45,    84,    -1,   141,    45,   175,    -1,   141,    45,
     142,    -1,   205,    45,    29,    -1,   204,    45,    29,    -1,
     207,    -1,   208,    -1,   209,    -1,   210,    -1,   211,    -1,
     212,    45,    52,   326,    53,    -1,   143,    45,    29,    -1,
     213,    45,    29,    -1,   214,    45,    29,    -1,   144,    -1,
     219,    45,    46,    -1,   220,    45,    46,    -1,   219,    45,
      29,    -1,   220,    45,    29,    -1,   115,    45,    46,    -1,
     187,    45,    46,    -1,    46,    -1,    29,    -1,   117,    -1,
     303,    -1,   302,   303,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    29,    -1,    83,    -1,    88,    -1,    82,    -1,    84,
      -1,    85,    -1,    86,    -1,    87,    -1,    -1,    19,   305,
     264,    -1,   306,    -1,   305,   306,    -1,   307,    -1,   307,
      48,    -1,    62,    46,    -1,   357,    -1,    -1,    24,    58,
     308,   312,    52,   313,    53,   309,   311,    -1,   147,    52,
      29,    59,    29,    53,   110,    52,    29,    59,    29,    53,
      -1,   350,    -1,   373,    -1,    -1,   111,   145,    -1,    -1,
      54,    -1,    -1,    48,    -1,   227,    -1,   227,    26,    29,
      28,    -1,   316,    -1,   313,   314,   316,    -1,    -1,    59,
      -1,   227,    -1,   227,    39,   227,    -1,    34,    39,   227,
      -1,   227,    39,    54,    -1,    34,    39,    54,    -1,   315,
      -1,   315,    60,   315,    -1,   227,    -1,    27,    -1,    -1,
     319,    -1,   320,    -1,   319,   320,    -1,   150,    -1,   151,
      -1,   227,    -1,    -1,   318,   227,   323,   318,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,
      -1,    69,   331,    -1,    70,   331,    -1,    71,   338,    -1,
      72,   332,    -1,   113,    -1,   114,    -1,   115,    -1,   116,
      -1,   146,    -1,   329,    -1,   325,    59,   329,    -1,   328,
      -1,   326,    59,   328,    -1,    29,    -1,    56,    29,    -1,
      57,    29,    -1,    46,    -1,    30,    -1,    16,    -1,   327,
      -1,    41,    -1,   330,    -1,   330,   110,   330,    -1,   330,
      37,   330,    -1,    46,    -1,    30,    -1,    16,    -1,   327,
      -1,    41,    -1,    -1,    52,    29,    53,    -1,    52,    29,
      59,    29,    53,    -1,    -1,   335,   110,   337,    -1,    -1,
      52,    29,    53,    -1,    29,    -1,   336,   333,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,    -1,   139,
      -1,   140,   342,    -1,   336,    -1,    -1,   339,   110,   340,
      -1,   341,    -1,   341,    -1,   134,    -1,   135,    -1,   136,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,   342,    -1,
      -1,    52,   334,    53,    -1,    -1,   344,    -1,   127,   345,
      -1,   346,    -1,   346,   125,   346,    -1,   346,   124,   346,
      -1,   347,   123,   347,    -1,   347,     8,   347,    -1,   347,
       9,   347,    -1,   347,    73,   347,    -1,   347,   128,    73,
     347,    -1,   347,    45,   347,    -1,   347,   132,    -1,   347,
     133,    -1,   347,    -1,   347,   129,   347,   125,   347,    -1,
     347,   130,    52,   349,    53,    -1,   128,   346,    -1,    52,
     346,    53,    -1,   348,    -1,    29,    -1,    46,    -1,   131,
      -1,    30,    -1,   347,    -1,   349,    59,   347,    -1,    18,
     351,    -1,   352,    -1,   351,   352,    -1,     8,   353,     9,
     310,     8,   353,     9,    -1,   354,    -1,   353,    59,   354,
      -1,   355,    39,   356,    -1,   356,    -1,   227,    -1,   226,
      -1,   153,   367,   158,   371,   365,    -1,   154,   368,   158,
     371,   365,    -1,   163,   374,    -1,   162,   374,    -1,   361,
      -1,   366,    -1,   359,    -1,   362,    -1,   363,    -1,   374,
      -1,   364,    -1,   170,   379,   171,   358,   360,    -1,    -1,
     172,   358,    -1,   166,    -1,   167,   321,    45,   379,    -1,
     169,   321,    -1,   169,    45,   321,    -1,   169,   168,    -1,
     169,    45,   168,    -1,   173,   365,    27,    -1,   358,    -1,
     365,   358,    -1,    91,    46,    -1,    91,   165,    46,    -1,
      91,    83,    46,    -1,    91,   165,    83,    46,    -1,   369,
      -1,   367,   369,    -1,   370,    -1,   368,   370,    -1,   155,
      -1,   156,    -1,   157,    -1,   155,    -1,   159,    -1,   160,
      -1,   161,    -1,   157,    -1,    94,    -1,   156,    -1,   372,
      -1,   371,   314,   372,    -1,   355,    39,   356,    -1,   356,
      -1,   355,   152,   355,   311,    -1,    -1,   164,   227,    52,
     375,   376,    53,    -1,    -1,   377,    -1,   378,    -1,   377,
      59,   378,    -1,   379,    -1,   381,    -1,   379,   380,   379,
      -1,   125,    -1,   124,    -1,    57,   379,    -1,    56,   379,
      -1,   383,    -1,   128,   379,    -1,    52,   379,    53,    -1,
     382,    52,   376,    53,    -1,   174,   158,   321,    -1,   379,
     123,   379,    -1,   379,     8,   379,    -1,   379,     9,   379,
      -1,   379,    54,   379,    -1,   379,    56,   379,    -1,   379,
      57,   379,    -1,   379,    55,   379,    -1,   379,    73,   379,
      -1,   379,   128,    73,   379,    -1,   379,    45,   379,    -1,
     379,   132,    -1,   379,   133,    -1,   379,   129,   379,   125,
     379,    -1,   379,   130,    52,   384,    53,    -1,   379,   128,
     130,    52,   384,    53,    -1,   227,    -1,   321,    -1,    29,
      -1,    46,    -1,   131,    -1,    41,    -1,   383,    -1,   384,
      59,   383,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   158,   159,   165,   168,   174,   177,   187,
     191,   195,   196,   197,   198,   203,   207,   214,   224,   233,
     246,   254,   264,   272,   285,   286,   291,   294,   297,   290,
     313,   316,   319,   312,   333,   336,   336,   342,   345,   348,
     351,   354,   357,   363,   364,   365,   369,   378,   384,   394,
     401,   403,   405,   407,   409,   411,   416,   416,   426,   426,
     429,   429,   442,   442,   461,   463,   466,   461,   471,   471,
     476,   477,   478,   490,   491,   496,   497,   500,   515,   527,
     528,   539,   550,   563,   575,   586,   591,   594,   602,   603,
     609,   608,   633,   636,   636,   654,   655,   658,   659,   660,
     663,   672,   673,   676,   677,   678,   680,   681,   682,   688,
     692,   692,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   713,   712,   741,   742,   743,   746,
     746,   749,   753,   749,  1075,  1076,  1082,  1092,  1093,  1096,
    1097,  1100,  1103,  1108,  1119,  1133,  1147,  1156,  1165,  1174,
    1189,  1198,  1207,  1214,  1216,  1219,  1225,  1226,  1227,  1228,
    1231,  1232,  1236,  1237,  1241,  1241,  1244,  1249,  1271,  1295,
    1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,  1320,  1322,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1339,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,
    1354,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,
    1364,  1365,  1366,  1367,  1368,  1370,  1371,  1372,  1373,  1374,
    1375,  1381,  1382,  1383,  1387,  1388,  1392,  1393,  1394,  1395,
    1396,  1397,  1398,  1399,  1401,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1446,  1447,  1450,  1450,  1452,  1452,  1455,  1465,
    1471,  1471,  1474,  1475,  1476,  1480,  1480,  1482,  1482,  1485,
    1485,  1487,  1490,  1496,  1499,  1503,  1504,  1508,  1512,  1516,
    1520,  1524,  1531,  1531,  1535,  1538,  1542,  1542,  1545,  1545,
    1549,  1550,  1563,  1571,  1571,  1580,  1584,  1588,  1592,  1596,
    1600,  1604,  1610,  1614,  1618,  1622,  1626,  1630,  1634,  1637,
    1644,  1644,  1648,  1648,  1653,  1653,  1653,  1657,  1664,  1665,
    1666,  1667,  1674,  1675,  1678,  1684,  1691,  1692,  1693,  1694,
    1700,  1703,  1704,  1707,  1708,  1715,  1717,  1722,  1730,  1733,
    1734,  1735,  1736,  1737,  1738,  1739,  1745,  1747,  1748,  1751,
    1754,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1770,  1772,
    1779,  1779,  1785,  1791,  1792,  1795,  1801,  1802,  1803,  1804,
    1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1816,
    1823,  1824,  1825,  1830,  1833,  1837,  1849,  1852,  1853,  1857,
    1867,  1874,  1883,  1886,  1898,  1901,  1905,  1912,  1920,  1925,
    1933,  1937,  1942,  1947,  1952,  1957,  1962,  1971,  1980,  1981,
    1986,  1989,  1997,  2003,  2009,  2015,  2024,  2029,  2039,  2049,
    2055,  2061,  2067,  2077,  2089,  2097,  2109,  2117,  2118,  2119,
    2123,  2124,  2125,  2126,  2127,  2128,  2129,  2132,  2139,  2150,
    2154,  2161,  2169,  2169,  2187,  2188,  2194,  2200,  2208,  2215,
    2216,  2221,  2222,  2238,  2240,  2241,  2242,  2243,  2244,  2247,
    2248,  2249,  2250,  2251,  2252,  2253,  2254,  2255,  2256,  2257,
    2258,  2259,  2260,  2261,  2262,  2265,  2268,  2269,  2270,  2271,
    2272,  2275,  2279
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
  "layout_container", "layout_section", "$@8", "screen_section",
  "screens_section", "$@9", "$@10", "screens_rest", "$@11", "$@12", "$@13",
  "op_extended", "op_size", "op_end", "screen_layout", "some_text",
  "screen_element", "ch_list", "field", "$@14", "field_element", "$@15",
  "op_table_section", "table_def_list", "table_def", "opequal",
  "table_qualifier", "attribute_section", "field_tag_list",
  "op_field_tag_type", "field_tag", "$@16", "fpart_list", "eq_or_colon",
  "fpart", "$@17", "$@18", "op_att", "field_datatype_null",
  "field_datatype", "field_type", "lu_ft_eq_c", "lu_ft_eq_c_i", "lu_ft",
  "lu_fc", "lu_joincol", "lu_join", "op_field_desc", "op_desc_list",
  "desc", "def_val", "colors", "color", "op_instruction_section",
  "instruct_opts", "instruct_op_1", "instruct_op", "$@19", "op_ltype",
  "op_star", "op_semi", "srec_dim", "srec_field_list", "op_comma",
  "field_list_item", "field_list_element", "field_name", "op_ws", "ws",
  "ws_elem", "field_tag_name", "field_tag_name_scr", "$@20", "datatype",
  "incl_list", "items_list", "number_value", "items_entry", "incl_entry",
  "incl_item", "opt_dec_ext", "opt_int_ext", "opt_unit_size", "dtfrac",
  "int_start", "int_start_unit", "int_end", "opt_dt_ext", "dt_start",
  "dt_end", "dtime_val", "opt_frac", "op_where", "where_clause", "clauses",
  "clause", "value", "fieldidentifier", "value_list", "composites",
  "composites_list", "composite_entry", "comp_list", "comp_item",
  "table_name", "column_name", "control_block", "action", "if", "op_else",
  "abort", "let", "nextfield", "block", "actions", "comments",
  "bef_act_list", "aft_act_list", "bef_act", "aft_act", "column_list",
  "column_entry", "master_of", "func_call", "@21", "op_func_call_args",
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
     251,   251,   251,   251,   251,   251,   253,   252,   254,   254,
     256,   255,   257,   255,   259,   260,   261,   258,   262,   262,
     263,   263,   263,   264,   264,   265,   265,   266,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   268,   268,
     270,   269,   271,   272,   271,   273,   273,   274,   274,   274,
     275,   276,   276,   277,   277,   277,   277,   277,   277,   278,
     279,   279,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   282,   281,   283,   283,   283,   284,
     284,   286,   287,   285,   288,   288,   288,   289,   289,   290,
     290,   290,   290,   291,   291,   291,   291,   291,   291,   291,
     292,   292,   293,   294,   295,   295,   296,   296,   296,   296,
     297,   297,   298,   298,   299,   299,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   301,   301,   301,   302,   302,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   304,   304,   305,   305,   306,   306,   307,   307,
     308,   307,   307,   307,   307,   309,   309,   310,   310,   311,
     311,   312,   312,   313,   313,   314,   314,   315,   315,   315,
     315,   315,   316,   316,   317,   317,   318,   318,   319,   319,
     320,   320,   321,   323,   322,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     325,   325,   326,   326,   327,   327,   327,   328,   328,   328,
     328,   328,   329,   329,   329,   330,   330,   330,   330,   330,
     331,   331,   331,   332,   332,   333,   333,   334,   335,   336,
     336,   336,   336,   336,   336,   336,   337,   338,   338,   339,
     340,   341,   341,   341,   341,   341,   341,   341,   342,   342,
     343,   343,   344,   345,   345,   345,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   347,
     347,   347,   347,   348,   349,   349,   350,   351,   351,   352,
     353,   353,   354,   354,   355,   356,   357,   357,   357,   357,
     358,   358,   358,   358,   358,   358,   358,   359,   360,   360,
     361,   362,   363,   363,   363,   363,   364,   365,   365,   366,
     366,   366,   366,   367,   367,   368,   368,   369,   369,   369,
     370,   370,   370,   370,   370,   370,   370,   371,   371,   372,
     372,   373,   375,   374,   376,   376,   377,   377,   378,   379,
     379,   380,   380,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   382,   383,   383,   383,   383,
     383,   384,   384
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     5,     5,     2,     1,
       1,     1,     3,     1,     3,     1,     1,     5,     5,     5,
       5,     1,     2,     5,     0,     1,     0,     0,     0,    10,
       0,     0,     0,    10,     0,     0,     4,     3,     1,     1,
       3,     3,     1,     1,     2,     3,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     0,     5,     1,     2,
       0,     3,     0,     4,     0,     0,     0,     9,     0,     1,
       0,     2,     4,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     4,     1,     0,     4,     0,     3,     1,     2,     3,
       2,     0,     2,     1,     3,     3,     5,     3,     3,     3,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     1,     2,     3,     1,
       1,     0,     0,     6,     0,     3,     5,     3,     1,     0,
       5,     3,     2,     4,     2,     4,     3,     1,     4,     2,
       1,     3,     3,     1,     3,     1,     3,     1,     4,     2,
       1,     2,     0,     2,     1,     3,     1,     4,     2,     4,
       3,     3,     3,     3,     5,     3,     5,     1,     1,     3,
       5,     3,     3,     3,     1,     4,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       5,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     1,     2,     1,     2,     2,     1,
       0,     9,    12,     1,     1,     0,     2,     0,     1,     0,
       1,     1,     4,     1,     3,     0,     1,     1,     3,     3,
       3,     3,     1,     3,     1,     1,     0,     1,     1,     2,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       0,     3,     5,     0,     3,     0,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     3,
       0,     1,     2,     1,     3,     3,     3,     3,     3,     3,
       4,     3,     2,     2,     1,     5,     5,     2,     3,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     2,     7,
       1,     3,     3,     1,     1,     1,     5,     5,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     5,     0,     2,
       1,     4,     2,     3,     2,     3,     3,     1,     2,     2,
       3,     3,     4,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     4,     0,     6,     0,     1,     1,     3,     1,     1,
       3,     1,     1,     2,     2,     1,     2,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       2,     2,     5,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     3,     9,     5,    11,    13,     8,     1,
       0,     0,     0,     0,     0,     0,     4,     0,    60,    34,
      95,    16,    15,    58,     0,    10,    12,    14,     0,    62,
      70,    35,    56,     0,     0,    59,     7,     6,    70,     0,
      61,    64,     0,     0,   101,    73,    97,   112,   252,    63,
      71,    68,     0,     0,     0,    38,    39,    42,    43,     0,
      24,    24,    26,    24,    30,    24,    50,    51,    52,    53,
      54,    55,    73,     0,   100,    74,     0,    96,    98,   118,
     114,   117,   115,   113,   116,   119,   120,   121,   123,   122,
      73,     0,   110,     0,     2,     0,    69,     0,     0,     0,
       0,    36,     0,    44,    25,    34,    34,    24,    34,    24,
      34,    57,     0,   103,   102,    99,   109,   111,   292,   124,
       0,     0,     0,     0,     0,     0,     0,     0,   394,    73,
     254,   256,   263,     0,   259,   264,    72,    65,    40,    41,
      37,    45,    46,    46,    34,    46,    34,     0,     0,     0,
       0,     0,     0,     0,   386,   387,   260,   258,     0,   427,
     428,   429,     0,   423,   435,   430,   436,   434,   431,   432,
     433,     0,   425,     0,   399,   398,   253,   255,   257,     0,
       0,     0,    47,    48,     0,     0,     0,     0,    24,     0,
      21,   108,   104,   105,   107,   130,   129,     0,   131,   126,
       9,   395,     0,   390,     0,   393,   388,     0,     0,     0,
     424,     0,   426,     0,   269,    88,    81,    90,    82,    83,
      87,    86,    85,    80,    77,     0,    78,    75,    84,    79,
      18,    49,    17,    27,    19,    31,    34,    20,    22,     0,
     125,   127,     0,   267,     0,     0,   271,     0,     0,     0,
     440,   275,   437,   275,   442,   270,   441,   286,    66,    76,
      89,     0,     0,    46,   106,   128,     0,     0,   139,   147,
     134,   268,     0,   391,   392,     0,     0,     0,     0,   276,
       0,   410,     0,     0,     0,     0,     0,   417,   402,   400,
     403,   404,   406,   396,   401,   405,   397,   444,   290,   291,
       0,     0,   287,   288,    92,    73,     0,     0,     0,     0,
     149,     0,     0,   144,   138,     0,     0,   132,     0,     0,
       0,   277,   275,   282,   273,     0,   439,   419,     0,     0,
       0,     0,   414,   412,   477,   480,   478,     0,     0,     0,
       0,   479,     0,   292,   476,     0,   449,     0,   455,     0,
     438,   418,     0,   445,   446,   448,    91,    93,   293,   289,
      67,    28,    32,    23,   285,   284,   139,     0,   295,   296,
     297,   298,   299,   300,   330,   330,   347,   333,     0,   305,
     306,   307,   308,   309,   142,   139,     0,   146,     0,   162,
       0,   272,     0,     0,   265,     0,     0,     0,   421,   420,
       0,     0,   415,   413,     0,   454,   453,   456,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,   451,
       0,     0,     0,   470,   471,     0,     0,   444,   416,   443,
       0,   286,   286,     0,     0,   143,   148,     0,   301,   302,
     351,   352,   353,   354,   355,   356,   358,   303,     0,   349,
     339,   340,   341,   342,   343,   344,   358,   304,     0,   335,
     141,   145,   137,   135,     0,     0,   133,   389,   281,   279,
     280,   278,     0,   269,   274,   283,     0,   422,   411,   457,
     459,   461,   462,   469,   463,   466,   464,   465,   467,   460,
       0,     0,     0,     0,   408,   450,     0,   447,    94,   294,
      29,    33,     0,     0,   357,     0,   345,     0,     0,   338,
       0,     0,   186,     0,     0,   194,   166,     0,     0,     0,
       0,     0,   177,   178,     0,     0,   184,   189,   188,     0,
       0,   192,   196,   195,   199,   193,     0,   187,     0,     0,
       0,     0,   224,   198,   197,     0,     0,   202,   208,     0,
       0,   204,   205,   203,     0,     0,   215,   216,   217,   218,
     219,     0,     0,     0,     0,     0,     0,   163,   164,   266,
     261,     0,   468,     0,     0,   481,     0,     0,   407,   458,
     331,     0,   337,     0,   348,   350,   346,   334,     0,   140,
     136,     0,     0,   150,     0,   153,     0,   157,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,   201,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     472,   473,     0,   409,     0,   359,   336,     0,   160,     0,
       0,     0,   159,     0,   244,   236,   237,   238,   239,   240,
     241,   242,   243,   247,   245,   248,   249,   250,   251,   246,
     360,   234,   170,   232,   231,   233,   171,   175,   173,   179,
       0,   190,   191,   229,   181,   182,   210,   212,   211,   221,
     183,   230,   209,   206,   207,   214,   213,     0,   222,   223,
     172,   227,   225,   228,   226,   165,     0,   474,   482,   332,
     185,   161,   151,   169,   155,   152,     0,   156,     0,   235,
     167,   361,     0,     0,   327,   314,   326,   329,   325,     0,
       0,     0,   328,   310,   322,   319,   318,   321,   317,     0,
     320,   312,   262,     0,   158,   380,   383,   381,     0,     0,
     382,   362,   363,   374,   379,   176,   174,   315,   316,   180,
       0,     0,     0,   220,     0,   154,     0,   377,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   372,   373,
     311,   324,   323,   313,   378,   365,   364,   367,   368,   371,
     369,   366,     0,     0,     0,   370,     0,   384,     0,   375,
     376,     0,   385
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,     3,   201,   343,     8,    20,    66,    67,
      68,    69,   189,   190,   105,    70,   107,   261,   433,    71,
     109,   262,   434,    32,    42,    58,    59,   181,   182,   183,
      21,    43,    22,    23,    30,    38,    40,    51,   180,   305,
      97,    41,    77,   225,   226,   227,   228,   229,   257,   300,
     431,    34,    45,    46,    74,   114,    48,    90,    91,    92,
     152,   197,   198,   199,   242,   389,   317,   313,   314,   270,
     592,   593,   594,   705,   598,   640,   466,   567,   568,   666,
     660,   661,    94,   129,   130,   131,   207,   473,   272,   256,
     247,   322,   286,   323,   324,   366,   301,   302,   303,   344,
     304,   432,   384,   721,   729,   722,   731,   723,   724,   438,
     457,   509,   583,   458,   459,   587,   447,   448,   584,   449,
     504,   710,   711,   741,   742,   743,   744,   788,   132,   154,
     155,   202,   203,   204,   205,   134,   287,   288,   578,   289,
     290,   291,   292,   293,   294,   162,   171,   163,   172,   251,
     252,   135,   295,   297,   352,   353,   354,   355,   426,   346,
     347,   348,   576
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -667
static const yytype_int16 yypact[] =
{
      15,   -21,    49,    50,  -667,    62,   139,   154,   163,  -667,
     159,   -16,   233,   204,   204,   236,  -667,   225,  -667,   227,
     244,  -667,   145,  -667,   247,  -667,  -667,  -667,   270,  -667,
     296,  -667,  -667,   204,   306,  -667,  -667,  -667,   296,   294,
    -667,  -667,    93,   439,   289,   193,  -667,   543,   325,  -667,
     329,   178,   312,   318,   336,  -667,  -667,  -667,  -667,   -28,
     204,   204,  -667,   204,  -667,   204,  -667,  -667,  -667,  -667,
    -667,  -667,   340,    -2,  -667,  -667,   204,  -667,  -667,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,
      24,   204,  -667,   223,  -667,   355,  -667,   384,   371,   390,
     385,  -667,    93,  -667,  -667,   227,   227,   204,   227,   204,
     227,  -667,   405,   396,  -667,  -667,  -667,  -667,  -667,  -667,
     441,   397,   412,   423,   322,   394,   317,   317,  -667,   206,
    -667,   436,  -667,   335,  -667,  -667,  -667,  -667,  -667,  -667,
    -667,  -667,   439,   439,   227,   439,   227,   309,   204,   204,
     204,   204,    63,   460,   441,  -667,  -667,  -667,   466,  -667,
    -667,  -667,   183,  -667,  -667,  -667,  -667,  -667,  -667,  -667,
    -667,   440,  -667,   204,  -667,  -667,  -667,  -667,  -667,   204,
     430,   471,   439,  -667,   472,   475,   480,   482,   204,   -24,
    -667,  -667,  -667,   465,  -667,  -667,  -667,   230,  -667,  -667,
     486,  -667,    48,  -667,   490,  -667,  -667,   204,   473,   460,
    -667,   460,  -667,   478,   485,  -667,  -667,  -667,  -667,  -667,
    -667,  -667,  -667,  -667,  -667,   303,  -667,  -667,   525,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,   227,  -667,  -667,   204,
      63,  -667,    25,   488,   460,   513,   518,   495,   528,   522,
    -667,   134,  -667,   134,  -667,  -667,  -667,   224,  -667,  -667,
    -667,   430,   430,   439,  -667,  -667,   523,   204,   -46,   526,
     553,  -667,   576,  -667,  -667,   556,   298,   533,   513,  -667,
      22,  -667,   204,     8,   -11,   144,   460,  -667,  -667,  -667,
    -667,  -667,  -667,   144,  -667,  -667,   144,   -11,  -667,  -667,
     218,   204,   224,  -667,  -667,   340,   320,   413,   561,   228,
     565,   658,   563,  -667,   481,   204,   585,  -667,   460,   589,
     579,   590,    36,   572,  -667,   524,  -667,  -667,   587,    -9,
     591,     3,  -667,  -667,  -667,  -667,  -667,   -11,   -11,   -11,
     -11,  -667,   477,   588,  -667,    56,  -667,   593,  -667,    40,
    -667,  -667,   595,   582,  -667,   514,  -667,  -667,  -667,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,   592,   204,  -667,  -667,
    -667,  -667,  -667,  -667,   597,   597,   327,   438,   204,  -667,
    -667,  -667,  -667,  -667,  -667,   592,   609,  -667,    55,   596,
      67,  -667,    69,    74,   540,   298,   298,   600,  -667,  -667,
     608,   -11,  -667,  -667,   483,   514,   514,   514,   204,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,  -667,  -667,
     -44,   -11,   605,  -667,  -667,   144,   -11,   -11,  -667,  -667,
     -11,   224,   224,   631,   632,  -667,  -667,   634,  -667,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,   616,  -667,   562,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,   616,  -667,   567,   626,
     640,  -667,  -667,  -667,   642,   307,  -667,  -667,  -667,  -667,
    -667,  -667,   535,   485,  -667,  -667,   653,  -667,   514,  -667,
    -667,   619,   619,   514,   514,   514,   514,   514,   514,   514,
     -11,   633,   537,    52,   511,   514,   641,  -667,  -667,  -667,
    -667,  -667,   179,   655,  -667,   327,  -667,   438,   666,  -667,
     204,   668,   672,   204,    76,  -667,  -667,   671,   673,   674,
     625,   644,  -667,  -667,   688,   694,  -667,  -667,  -667,   696,
     700,  -667,  -667,  -667,   285,  -667,   701,  -667,   705,   708,
     710,   711,  -667,  -667,  -667,   712,   715,  -667,  -667,   717,
     718,  -667,  -667,  -667,   720,   721,  -667,  -667,  -667,  -667,
    -667,   722,   723,   724,   725,   730,   731,   738,  -667,  -667,
    -667,   740,   514,    52,   -11,  -667,   231,   144,  -667,  -667,
    -667,   771,  -667,   748,  -667,  -667,  -667,  -667,   749,  -667,
    -667,   758,   105,  -667,   760,  -667,   204,   767,  -667,   703,
     761,    10,   204,   204,   762,   757,   764,   765,  -667,  -667,
     766,   769,   773,   -57,   784,   204,   774,   775,   237,   788,
     793,   772,   796,   797,    10,   168,   182,   307,   798,   256,
     514,  -667,    52,  -667,   776,  -667,  -667,   799,  -667,   124,
      76,   204,   791,   204,  -667,  -667,  -667,  -667,  -667,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,
     627,  -667,  -667,  -667,  -667,  -667,  -667,   792,   794,  -667,
     235,  -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,  -667,   332,  -667,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,   779,  -667,  -667,  -667,
    -667,  -667,  -667,  -667,   795,  -667,   204,  -667,   214,  -667,
    -667,  -667,   204,   204,  -667,  -667,  -667,  -667,  -667,   806,
     807,   263,  -667,  -667,   -20,  -667,  -667,  -667,  -667,   271,
    -667,  -667,  -667,   204,  -667,  -667,  -667,  -667,   214,   214,
    -667,  -667,   299,   558,  -667,  -667,  -667,  -667,  -667,  -667,
     235,   235,   235,  -667,   332,  -667,   785,  -667,   214,   214,
      -6,    -6,    -6,    -6,    -6,   768,    -6,   787,  -667,  -667,
    -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,  -667,
    -667,  -667,    -6,   719,    -6,  -667,    -6,  -667,   272,  -667,
    -667,    -6,  -667
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -667,  -667,  -667,  -667,   836,   -13,  -667,  -667,  -667,  -667,
    -667,  -667,  -667,   651,    12,  -667,  -667,  -667,  -667,  -667,
    -667,  -667,  -667,   151,  -667,    80,  -667,  -131,  -667,   -17,
    -667,  -667,  -667,   820,  -667,  -667,   805,  -667,  -667,  -667,
    -667,  -667,   -68,   211,  -667,  -116,  -667,  -667,  -667,  -667,
    -667,  -667,  -667,    39,  -667,  -667,  -667,  -667,  -667,   755,
    -667,  -667,  -667,   -45,  -667,  -667,  -667,  -323,  -667,  -667,
    -667,   208,  -667,  -667,   209,  -667,  -667,  -667,   219,   226,
    -667,   188,  -667,  -667,   726,  -667,  -667,  -667,  -667,   378,
    -667,  -667,   530,   457,   459,  -667,   424,  -667,   555,   -81,
     427,  -667,  -667,  -667,  -667,  -666,   106,   109,  -311,   487,
    -667,  -667,  -667,  -667,   354,  -667,  -667,  -667,  -667,   358,
     408,  -667,  -667,  -667,  -367,    32,  -667,  -667,  -667,  -667,
     713,   547,   622,   -87,   207,  -667,  -291,  -667,  -667,  -667,
    -667,  -667,  -667,  -219,  -667,  -667,  -667,   706,   698,   659,
     586,  -667,   342,  -667,   444,  -667,   443,  -268,  -667,  -667,
    -667,  -482,   301
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -476
static const yytype_int16 yytable[] =
{
      26,    27,   351,   237,   111,   351,   133,    17,    18,     4,
     119,   575,   184,     5,   186,   311,   345,   751,   334,    25,
      44,   730,   116,   735,   736,   101,    72,   676,    25,   490,
     335,   102,    44,    25,   296,   336,     1,   399,    25,   663,
     737,   337,   133,   435,   112,   338,   339,   104,   104,     9,
     104,    75,   104,   331,  -112,    25,   664,   243,   351,   266,
     113,   176,   461,    44,   409,   410,   349,   428,   327,   404,
     405,   406,   407,   106,   400,   108,   467,   110,   118,   267,
     128,   334,    25,   463,    78,   677,   491,    52,   730,   394,
     752,   575,   214,   335,   104,   279,   104,    10,   336,    25,
     195,   411,    12,   312,    25,   328,    25,   244,   196,   259,
     412,   413,   414,   415,   464,   115,   128,   340,   678,   144,
     341,   146,   249,   468,   249,   740,   244,   665,   470,   416,
     596,   280,   308,   478,   494,   191,   192,   193,   194,   103,
     128,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     698,    53,   241,   492,    25,   638,   188,     6,   495,    54,
     213,    55,    56,   342,   639,   231,   128,   224,    17,    18,
      79,   402,    19,   268,   701,   104,   332,    13,    57,   417,
     418,   419,   141,   341,   420,   421,   422,   329,   423,   424,
     259,   259,    14,   279,   246,   265,   128,   691,   128,   249,
     236,   330,   333,    15,   173,    16,   281,   282,    52,   283,
     284,   693,   224,   285,   692,    80,    81,    82,    83,    84,
      75,    85,   572,    25,   120,   280,   264,   425,   694,   269,
     121,   128,   580,    75,    25,   280,    25,   360,   581,    86,
      87,   120,    88,   735,   736,    89,   356,   121,   224,   224,
     403,   714,    76,    25,   310,   364,   142,   143,    25,   145,
     737,   147,   357,   321,   715,   716,   738,   195,   122,   118,
     118,    29,    53,   128,    24,   196,   717,    28,   240,    31,
      54,   718,    55,    56,   631,   122,   633,    33,   358,    36,
     632,   719,   720,   224,   224,   185,   365,   187,   173,    57,
     281,   282,   387,   283,   284,   128,   630,   285,   173,   697,
     281,   282,    37,   283,   284,   632,   749,   285,   118,   215,
     216,    39,   750,    50,   753,   790,    47,   480,    25,   217,
     754,   791,   320,    25,    73,   258,   215,   216,   159,   160,
     161,   209,   739,   512,    93,   740,   217,   218,   725,   219,
      25,    95,   361,   123,   436,    96,   513,    98,   514,   124,
     125,   715,   726,    99,   218,   460,   219,    75,   126,   127,
     123,   756,   757,   727,   298,   299,   124,   125,   728,   469,
     471,   100,   321,   321,   136,   126,   127,   263,   719,   720,
     515,   775,   776,   608,   609,   118,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   137,   250,   138,   250,   535,
     139,   220,   536,   758,   759,   221,   537,   538,   539,   215,
     216,   140,   595,   149,   150,   151,   683,   684,   220,   217,
     771,   772,   221,    25,   148,   362,   215,   216,   540,   153,
     541,   542,   274,   222,   223,   156,   217,   218,   157,   219,
      25,   440,   441,   442,   443,   444,   445,   446,   174,   175,
     222,   223,   306,   307,   218,   158,   219,   159,   160,   161,
     118,   173,   543,   544,   178,   326,   545,   179,   164,   188,
     200,   409,   410,   250,   546,   208,   547,   589,   230,   232,
     118,   597,   239,   548,   549,   550,   233,   234,   551,   552,
     553,   554,   555,   235,   556,   557,   558,   559,   560,   561,
     562,   563,   409,   410,   564,   -10,   565,   566,   411,   245,
     254,   220,   248,   255,   164,   221,   479,   412,   413,   414,
     415,   260,   271,     4,   275,   409,   410,   276,   220,   165,
     166,   167,   221,   168,   169,   170,   416,   277,   595,   411,
     118,   278,   309,   222,   223,   315,   760,   761,   412,   413,
     414,   415,   450,   451,   452,   453,   454,   455,   456,   316,
     222,   223,   411,   642,   318,   319,   325,   416,   363,   667,
     668,   412,   413,   414,   415,   165,   166,   167,   211,   168,
     169,   170,   680,   762,   367,   385,   417,   418,   419,   386,
     416,   420,   421,   422,   388,   423,   424,   391,   392,   118,
      60,    61,    62,    63,    64,    65,   118,   597,   704,   393,
     707,   763,   396,   398,   397,   408,   401,   417,   418,   419,
    -475,   430,   420,   421,   422,   427,   423,   424,   429,   437,
     462,   472,   476,   311,   477,   465,   644,   493,   500,   501,
     417,   418,   574,   502,   411,   420,   421,   422,   503,   423,
     424,   511,   505,   412,   413,   414,   415,   507,   508,   510,
     569,   764,   571,   577,   582,   573,   765,   766,   767,    79,
     768,   769,   416,   734,   579,   588,   590,   591,   602,   745,
     746,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   599,   603,   600,   601,
     755,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   644,   604,    80,    81,    82,    83,    84,   605,
      85,   606,   417,   418,   419,   607,   610,   420,   421,   422,
     611,   423,   424,   612,   708,   613,   614,   615,    86,    87,
     616,    88,   617,   618,    89,   619,   620,   621,   622,   623,
     624,   379,   380,   381,   382,   625,   626,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   777,   778,   779,   780,   781,   627,   783,   628,
     634,   635,   636,   637,   383,   641,   643,   662,   669,   670,
     671,   672,   673,   679,   785,   674,   787,   685,   789,   675,
     681,   682,   686,   792,   687,   688,   689,   696,   700,   699,
     706,   712,   732,   713,   733,   747,   748,     7,   774,   784,
     238,   782,    35,    49,   786,   117,   695,   702,   709,   703,
     690,   570,   395,   475,   474,   177,   499,   359,   498,   770,
     773,   586,   439,   585,   506,   390,   273,   206,   210,   212,
     253,   496,   350,   497,   629
};

static const yytype_uint16 yycheck[] =
{
      13,    14,   293,    27,    72,   296,    93,    23,    24,    30,
      91,   493,   143,    34,   145,    61,   284,    37,    29,    30,
      33,   687,    90,    29,    30,    53,    43,    84,    30,    73,
      41,    59,    45,    30,   253,    46,    21,    46,    30,    29,
      46,    52,   129,   366,    46,    56,    57,    60,    61,     0,
      63,    27,    65,    45,    30,    30,    46,     9,   349,    34,
      73,   129,   385,    76,     8,     9,   285,    27,    46,   337,
     338,   339,   340,    61,    83,    63,     9,    65,    91,    54,
      93,    29,    30,    28,    45,   142,   130,   115,   754,    53,
     110,   573,   179,    41,   107,    59,   109,    47,    46,    30,
      37,    45,    40,   149,    30,    83,    30,    59,    45,   225,
      54,    55,    56,    57,    59,    76,   129,   128,   175,   107,
     131,   109,   209,    54,   211,   131,    59,   117,    54,    73,
      54,    91,   263,   401,   425,   148,   149,   150,   151,    59,
     153,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     632,   179,   197,   421,    30,    50,   180,   178,   426,   187,
     173,   189,   190,   174,    59,   182,   179,   180,    23,    24,
     146,   168,   188,   148,    50,   188,   168,    38,   206,   123,
     124,   125,   102,   131,   128,   129,   130,   165,   132,   133,
     306,   307,    38,    59,   207,   240,   209,    29,   211,   286,
     188,   282,   283,    40,   164,    46,   166,   167,   115,   169,
     170,    29,   225,   173,    46,   191,   192,   193,   194,   195,
      27,   197,   490,    30,    18,    91,   239,   171,    46,   242,
      24,   244,    53,    27,    30,    91,    30,   305,    59,   215,
     216,    18,   218,    29,    30,   221,    28,    24,   261,   262,
     331,    16,    59,    30,   267,    27,   105,   106,    30,   108,
      46,   110,    44,   276,    29,    30,    52,    37,    62,   282,
     283,    46,   179,   286,    41,    45,    41,    41,    48,    52,
     187,    46,   189,   190,    53,    62,   577,    43,   301,    42,
      59,    56,    57,   306,   307,   144,   309,   146,   164,   206,
     166,   167,   315,   169,   170,   318,   574,   173,   164,    53,
     166,   167,    42,   169,   170,    59,    53,   173,   331,    16,
      17,    25,    59,    29,    53,    53,    20,   408,    30,    26,
      59,    59,    34,    30,    45,    32,    16,    17,   155,   156,
     157,   158,   128,    36,    19,   131,    26,    44,    16,    46,
      30,    22,    32,   147,   367,   177,    49,    45,    51,   153,
     154,    29,    30,    45,    44,   378,    46,    27,   162,   163,
     147,   738,   739,    41,   150,   151,   153,   154,    46,   392,
     393,    45,   395,   396,    29,   162,   163,   236,    56,    57,
      83,   758,   759,   108,   109,   408,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    31,   209,    46,   211,   112,
      30,   118,   115,   124,   125,   122,   119,   120,   121,    16,
      17,    46,   513,    37,    38,    39,   199,   200,   118,    26,
     751,   752,   122,    30,    39,    32,    16,    17,   141,     8,
     143,   144,   245,   150,   151,    58,    26,    44,    46,    46,
      30,   134,   135,   136,   137,   138,   139,   140,   126,   127,
     150,   151,   261,   262,    44,    52,    46,   155,   156,   157,
     493,   164,   175,   176,    48,   278,   179,   152,    94,   180,
      30,     8,     9,   286,   187,    29,   189,   510,    27,    27,
     513,   514,    37,   196,   197,   198,    31,    27,   201,   202,
     203,   204,   205,    31,   207,   208,   209,   210,   211,   212,
     213,   214,     8,     9,   217,    39,   219,   220,    45,    39,
      52,   118,    59,    48,    94,   122,    53,    54,    55,    56,
      57,    16,    54,    30,    26,     8,     9,    52,   118,   155,
     156,   157,   122,   159,   160,   161,    73,    29,   639,    45,
     573,    39,    39,   150,   151,    39,     8,     9,    54,    55,
      56,    57,   134,   135,   136,   137,   138,   139,   140,    26,
     150,   151,    45,   596,     8,    29,    53,    73,    27,   602,
     603,    54,    55,    56,    57,   155,   156,   157,   158,   159,
     160,   161,   615,    45,    39,    42,   123,   124,   125,   128,
      73,   128,   129,   130,    29,   132,   133,    28,    39,   632,
     181,   182,   183,   184,   185,   186,   639,   640,   641,    39,
     643,    73,    60,    46,   110,   158,    45,   123,   124,   125,
      52,    59,   128,   129,   130,    52,   132,   133,    53,    52,
      41,   111,    52,    61,    46,    59,    29,    52,    27,    27,
     123,   124,   125,    29,    45,   128,   129,   130,    52,   132,
     133,    29,   110,    54,    55,    56,    57,   110,    52,    39,
     145,   123,    29,   172,    29,    52,   128,   129,   130,   146,
     132,   133,    73,   706,    53,    29,    28,    25,    73,   712,
     713,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    45,    73,    45,    45,
     733,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    29,    45,   191,   192,   193,   194,   195,    45,
     197,    45,   123,   124,   125,    45,    45,   128,   129,   130,
      45,   132,   133,    45,   127,    45,    45,    45,   215,   216,
      45,   218,    45,    45,   221,    45,    45,    45,    45,    45,
      45,   113,   114,   115,   116,    45,    45,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   760,   761,   762,   763,   764,    59,   766,    59,
      29,    53,    53,    45,   146,    45,    39,    46,    46,    52,
      46,    46,    46,    29,   782,    46,   784,    29,   786,    46,
      46,    46,    29,   791,    52,    29,    29,    29,    29,    53,
      39,    39,    53,    39,    39,    29,    29,     1,    53,    52,
     189,    73,    22,    38,   125,    90,   627,   639,   660,   640,
     624,   473,   322,   396,   395,   129,   432,   302,   431,   750,
     754,   507,   375,   505,   456,   318,   244,   154,   162,   171,
     211,   427,   286,   430,   573
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   223,   225,    30,    34,   178,   226,   228,     0,
      47,   224,    40,    38,    38,    40,    46,    23,    24,   188,
     229,   252,   254,   255,    41,    30,   227,   227,    41,    46,
     256,    52,   245,    43,   273,   255,    42,    42,   257,    25,
     258,   263,   246,   253,   227,   274,   275,    20,   278,   258,
      29,   259,   115,   179,   187,   189,   190,   206,   247,   248,
     181,   182,   183,   184,   185,   186,   230,   231,   232,   233,
     237,   241,   251,    45,   276,    27,    59,   264,   275,   146,
     191,   192,   193,   194,   195,   197,   215,   216,   218,   221,
     279,   280,   281,    19,   304,    22,   177,   262,    45,    45,
      45,    53,    59,   247,   227,   236,   236,   238,   236,   242,
     236,   264,    46,   227,   277,   275,   264,   281,   227,   321,
      18,    24,    62,   147,   153,   154,   162,   163,   227,   305,
     306,   307,   350,   355,   357,   373,    29,    31,    46,    30,
      46,   247,   245,   245,   236,   245,   236,   245,    39,    37,
      38,    39,   282,     8,   351,   352,    58,    46,    52,   155,
     156,   157,   367,   369,    94,   155,   156,   157,   159,   160,
     161,   368,   370,   164,   374,   374,   264,   306,    48,   152,
     260,   249,   250,   251,   249,   245,   249,   245,   180,   234,
     235,   227,   227,   227,   227,    37,    45,   283,   284,   285,
      30,   226,   353,   354,   355,   356,   352,   308,    29,   158,
     369,   158,   370,   227,   355,    16,    17,    26,    44,    46,
     118,   122,   150,   151,   227,   265,   266,   267,   268,   269,
      27,   251,    27,    31,    27,    31,   236,    27,   235,    37,
      48,   285,   286,     9,    59,    39,   227,   312,    59,   355,
     356,   371,   372,   371,    52,    48,   311,   270,    32,   267,
      16,   239,   243,   245,   227,   285,    34,    54,   148,   227,
     291,    54,   310,   354,   356,    26,    52,    29,    39,    59,
      91,   166,   167,   169,   170,   173,   314,   358,   359,   361,
     362,   363,   364,   365,   366,   374,   365,   375,   150,   151,
     271,   318,   319,   320,   322,   261,   265,   265,   249,    39,
     227,    61,   149,   289,   290,    39,    26,   288,     8,    29,
      34,   227,   313,   315,   316,    53,   356,    46,    83,   165,
     321,    45,   168,   321,    29,    41,    46,    52,    56,    57,
     128,   131,   174,   227,   321,   379,   381,   382,   383,   365,
     372,   358,   376,   377,   378,   379,    28,    44,   227,   320,
     264,    32,    32,    27,    27,   227,   317,    39,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   113,
     114,   115,   116,   146,   324,    42,   128,   227,    29,   287,
     353,    28,    39,    39,    53,   314,    60,   110,    46,    46,
      83,    45,   168,   321,   379,   379,   379,   379,   158,     8,
       9,    45,    54,    55,    56,    57,    73,   123,   124,   125,
     128,   129,   130,   132,   133,   171,   380,    52,    27,    53,
      59,   272,   323,   240,   244,   289,   227,    52,   331,   331,
     134,   135,   136,   137,   138,   139,   140,   338,   339,   341,
     134,   135,   136,   137,   138,   139,   140,   332,   335,   336,
     227,   289,    41,    28,    59,    59,   298,     9,    54,   227,
      54,   227,   111,   309,   316,   315,    52,    46,   379,    53,
     321,   379,   379,   379,   379,   379,   379,   379,   379,   379,
      73,   130,   379,    52,   358,   379,   376,   378,   322,   318,
      27,    27,    29,    52,   342,   110,   342,   110,    52,   333,
      39,    29,    36,    49,    51,    83,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   112,   115,   119,   120,   121,
     141,   143,   144,   175,   176,   179,   187,   189,   196,   197,
     198,   201,   202,   203,   204,   205,   207,   208,   209,   210,
     211,   212,   213,   214,   217,   219,   220,   299,   300,   145,
     311,    29,   379,    52,   125,   383,   384,   172,   360,    53,
      53,    59,    29,   334,   340,   341,   336,   337,    29,   227,
      28,    25,   292,   293,   294,   321,    54,   227,   296,    45,
      45,    45,    73,    73,    45,    45,    45,    45,   108,   109,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    59,    59,   384,
     379,    53,    59,   358,    29,    53,    53,    45,    50,    59,
     297,    45,   227,    39,    29,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     302,   303,    46,    29,    46,   117,   301,   227,   227,    46,
      52,    46,    46,    46,    46,    46,    84,   142,   175,    29,
     227,    46,    46,   199,   200,    29,    29,    52,    29,    29,
     301,    29,    46,    29,    46,   300,    29,    53,   383,    53,
      29,    50,   293,   296,   227,   295,    39,   227,   127,   303,
     343,   344,    39,    39,    16,    29,    30,    41,    46,    56,
      57,   325,   327,   329,   330,    16,    30,    41,    46,   326,
     327,   328,    53,    39,   227,    29,    30,    46,    52,   128,
     131,   345,   346,   347,   348,   227,   227,    29,    29,    53,
      59,    37,   110,    53,    59,   227,   346,   346,   124,   125,
       8,     9,    45,    73,   123,   128,   129,   130,   132,   133,
     329,   330,   330,   328,    53,   346,   346,   347,   347,   347,
     347,   347,    73,   347,    52,   347,   125,   347,   349,   347,
      53,    59,   347
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
			the_form.layout_attrib=NULL;
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 207 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 214 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 224 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_HBOX;
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 233 "screen.yacc"
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
#line 246 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 254 "screen.yacc"
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
#line 264 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 272 "screen.yacc"
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
#line 285 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 291 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 294 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 297 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 298 "screen.yacc"
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
#line 313 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 316 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 319 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 320 "screen.yacc"
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
#line 333 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 336 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 336 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 342 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 345 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 348 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 351 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 354 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_ACTION, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 357 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_BORDER);
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 369 "screen.yacc"
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
#line 378 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 384 "screen.yacc"
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
#line 394 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 402 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 404 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 406 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 408 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 410 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 412 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 416 "screen.yacc"
    { 
		the_form.layout_attrib=(yyvsp[(2) - (2)].layout_attrib);
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 418 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(4) - (5)].layout);
	}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 429 "screen.yacc"
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

  case 62:

/* Line 1455 of yacc.c  */
#line 442 "screen.yacc"
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

  case 64:

/* Line 1455 of yacc.c  */
#line 461 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 463 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 466 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 471 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 478 "screen.yacc"
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

  case 77:

/* Line 1455 of yacc.c  */
#line 500 "screen.yacc"
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

  case 78:

/* Line 1455 of yacc.c  */
#line 515 "screen.yacc"
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

  case 79:

/* Line 1455 of yacc.c  */
#line 527 "screen.yacc"
    { ltab=0; }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 528 "screen.yacc"
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

  case 81:

/* Line 1455 of yacc.c  */
#line 539 "screen.yacc"
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

  case 82:

/* Line 1455 of yacc.c  */
#line 550 "screen.yacc"
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

  case 83:

/* Line 1455 of yacc.c  */
#line 563 "screen.yacc"
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
#line 575 "screen.yacc"
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

  case 85:

/* Line 1455 of yacc.c  */
#line 586 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 591 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 594 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 602 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 603 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 609 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 616 "screen.yacc"
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

  case 92:

/* Line 1455 of yacc.c  */
#line 633 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 636 "screen.yacc"
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

  case 94:

/* Line 1455 of yacc.c  */
#line 647 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 663 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 672 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 673 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 676 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 677 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 679 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 680 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 681 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 697 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 698 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 699 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 700 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 701 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 702 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 703 "screen.yacc"
    {strcpy((yyval.str),"Button");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 704 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 705 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 706 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 707 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 708 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 713 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 719 "screen.yacc"
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

  case 131:

/* Line 1455 of yacc.c  */
#line 749 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 753 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	if (fld->tabname) {
		A4GL_make_downshift(fld->tabname);
	}
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 765 "screen.yacc"
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

  case 135:

/* Line 1455 of yacc.c  */
#line 1076 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1082 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1092 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1093 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1096 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1097 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1100 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1103 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1108 "screen.yacc"
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

  case 144:

/* Line 1455 of yacc.c  */
#line 1119 "screen.yacc"
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

  case 145:

/* Line 1455 of yacc.c  */
#line 1133 "screen.yacc"
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

  case 146:

/* Line 1455 of yacc.c  */
#line 1147 "screen.yacc"
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

  case 147:

/* Line 1455 of yacc.c  */
#line 1156 "screen.yacc"
    {
	struct struct_scr_field *fld;
	fld=A4GL_get_fld();
	fld->tabname=acl_strdup("-");
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
        fld->datatype=DTYPE_CHAR ;
        fld->dtype_size=0;
}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1165 "screen.yacc"
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

  case 149:

/* Line 1455 of yacc.c  */
#line 1174 "screen.yacc"
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

  case 150:

/* Line 1455 of yacc.c  */
#line 1189 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1198 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1207 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1216 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1219 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1225 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1226 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1227 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1228 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1244 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1249 "screen.yacc"
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

  case 168:

/* Line 1455 of yacc.c  */
#line 1271 "screen.yacc"
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

  case 169:

/* Line 1455 of yacc.c  */
#line 1295 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1303 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1304 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1305 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1306 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1307 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1308 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1309 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1310 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1311 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1312 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1313 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1314 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1315 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1316 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1317 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1318 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1319 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1320 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1322 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1324 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1325 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1326 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1327 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1328 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1329 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1330 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1331 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1332 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1333 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1334 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1335 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1339 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1346 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1347 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1348 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1349 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1350 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1351 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1352 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1353 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1354 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"left"); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1355 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"right"); }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1356 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"center"); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1357 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1358 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1359 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1360 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1361 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1362 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1363 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1364 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1365 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,(yyvsp[(3) - (3)].str)); }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1366 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1367 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1368 "screen.yacc"
    { A4GL_get_fld()->not_null=1;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1370 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1371 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1372 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1373 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1374 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1375 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1381 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1382 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1383 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1388 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1392 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1393 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1394 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1395 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1396 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1397 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1398 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1399 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1401 "screen.yacc"
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

  case 245:

/* Line 1455 of yacc.c  */
#line 1436 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1437 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1438 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1439 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1440 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1441 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1442 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1455 "screen.yacc"
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

  case 259:

/* Line 1455 of yacc.c  */
#line 1465 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1471 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1482 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1482 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1487 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1490 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1496 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1499 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1509 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1513 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1517 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1521 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1525 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1531 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1535 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1538 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1542 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1542 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1549 "screen.yacc"
    {colno++;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1550 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1563 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1571 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1573 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1580 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1584 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1588 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1592 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1596 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1600 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1604 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1610 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1614 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1618 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1622 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1626 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1630 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1634 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1637 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1644 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1648 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1653 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1657 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1664 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1665 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1667 "screen.yacc"
    {
		strcpy((yyval.str),"");
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
#line 1678 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1684 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1691 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1692 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1693 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1694 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1700 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1703 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1704 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1707 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1709 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1715 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1717 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1722 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1730 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1733 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1734 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1735 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1736 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1737 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1738 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1740 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1747 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1748 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1751 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1754 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1758 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1759 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1760 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1761 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1762 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1763 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1765 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1770 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1772 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1779 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1779 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1785 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1792 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1795 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1801 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1802 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1803 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1804 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1805 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1806 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1807 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1808 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1809 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1810 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1811 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1812 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1813 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1816 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1823 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1824 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1825 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1833 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1837 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1857 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1867 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1874 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1883 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1886 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1905 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1912 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1920 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1925 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1933 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1937 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1942 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1947 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1952 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1957 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1962 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1971 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1980 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1981 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1990 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1998 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2004 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2010 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2016 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2024 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2029 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2039 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2049 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2055 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2061 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2067 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2077 "screen.yacc"
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

  case 424:

/* Line 1455 of yacc.c  */
#line 2089 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2097 "screen.yacc"
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

  case 426:

/* Line 1455 of yacc.c  */
#line 2109 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2117 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2118 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2119 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2123 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2124 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2125 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2126 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2127 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2128 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2129 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2132 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2139 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2150 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2154 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2161 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2169 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2175 "screen.yacc"
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

  case 444:

/* Line 1455 of yacc.c  */
#line 2187 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2188 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2194 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2200 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2208 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2216 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str));}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2221 "screen.yacc"
    {strcpy((yyval.str),"AND");}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2222 "screen.yacc"
    {strcpy((yyval.str),"OR");}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2238 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2240 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2241 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2242 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2243 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2244 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2247 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2248 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2249 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2250 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2251 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2252 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2253 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2254 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2255 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2256 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2257 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2258 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2259 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2260 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2261 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2262 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2268 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2269 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2270 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2271 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2272 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2275 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2279 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1455 of yacc.c  */
#line 6768 "y.tab.c"
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
#line 2291 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




