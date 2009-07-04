
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
     LISTBOX = 396,
     BUTTON = 397,
     KW_PANEL = 398,
     DISPLAYONLY = 399,
     ALLOWING = 400,
     KW_WS = 401,
     KW_TAB = 402,
     KW_MASTER_OF = 403,
     KW_BEFORE = 404,
     KW_AFTER = 405,
     KW_EDITADD = 406,
     KW_EDITUPDATE = 407,
     KW_REMOVE = 408,
     KW_OF = 409,
     KW_ADD = 410,
     KW_UPDATE = 411,
     KW_QUERY = 412,
     KW_ON_ENDING = 413,
     KW_ON_BEGINNING = 414,
     KW_CALL = 415,
     KW_BELL = 416,
     KW_ABORT = 417,
     KW_LET = 418,
     KW_EXITNOW = 419,
     KW_NEXTFIELD = 420,
     KW_IF = 421,
     KW_THEN = 422,
     KW_ELSE = 423,
     KW_BEGIN = 424,
     KW_TOTAL = 425,
     KW_RIGHT = 426,
     KW_ZEROFILL = 427,
     KW_USES_EXTENDED = 428,
     SPECIAL_DBNAME = 429,
     KW_ACTION = 430,
     KW_PAGE = 431,
     KW_HBOX = 432,
     KW_VBOX = 433,
     KW_GRID = 434,
     KW_GROUP = 435,
     KW_TABLE = 436,
     KW_FOLDER = 437,
     KW_STYLE = 438,
     KW_LAYOUT = 439,
     KW_HIDDEN = 440,
     KW_AUTOSIZE = 441,
     KW_TEXTEDIT = 442,
     KW_BUTTONEDIT = 443,
     KW_LABEL = 444,
     KW_EDIT = 445,
     KW_DATEEDIT = 446,
     KW_SCROLL = 447,
     KW_IMAGE = 448,
     KW_FONTPITCH = 449,
     KW_FIXED = 450,
     KW_VARIABLE = 451,
     KW_WANTNORETURNS = 452,
     KW_WANTTABS = 453,
     KW_AUTOSCALE = 454,
     KW_PIXELWIDTH = 455,
     KW_PIXELHEIGHT = 456,
     KW_BORDER = 457,
     KW_SCROLLBARS_BOTH = 458,
     KW_SCROLLBARS_V = 459,
     KW_SCROLLBARS_H = 460,
     KW_STRETCH_Y = 461,
     KW_STRETCH_BOTH = 462,
     KW_ITEMS = 463,
     KW_VALUEMAX = 464,
     KW_VALUEMIN = 465,
     KW_PROGRESSBAR = 466,
     KW_COMBOBOX = 467,
     OPTIONS = 468,
     KW_BROWSER = 469,
     KW_VALUECHECKED = 470,
     KW_VALUEUNCHECKED = 471,
     KW_CHECKBOX = 472
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
#define LISTBOX 396
#define BUTTON 397
#define KW_PANEL 398
#define DISPLAYONLY 399
#define ALLOWING 400
#define KW_WS 401
#define KW_TAB 402
#define KW_MASTER_OF 403
#define KW_BEFORE 404
#define KW_AFTER 405
#define KW_EDITADD 406
#define KW_EDITUPDATE 407
#define KW_REMOVE 408
#define KW_OF 409
#define KW_ADD 410
#define KW_UPDATE 411
#define KW_QUERY 412
#define KW_ON_ENDING 413
#define KW_ON_BEGINNING 414
#define KW_CALL 415
#define KW_BELL 416
#define KW_ABORT 417
#define KW_LET 418
#define KW_EXITNOW 419
#define KW_NEXTFIELD 420
#define KW_IF 421
#define KW_THEN 422
#define KW_ELSE 423
#define KW_BEGIN 424
#define KW_TOTAL 425
#define KW_RIGHT 426
#define KW_ZEROFILL 427
#define KW_USES_EXTENDED 428
#define SPECIAL_DBNAME 429
#define KW_ACTION 430
#define KW_PAGE 431
#define KW_HBOX 432
#define KW_VBOX 433
#define KW_GRID 434
#define KW_GROUP 435
#define KW_TABLE 436
#define KW_FOLDER 437
#define KW_STYLE 438
#define KW_LAYOUT 439
#define KW_HIDDEN 440
#define KW_AUTOSIZE 441
#define KW_TEXTEDIT 442
#define KW_BUTTONEDIT 443
#define KW_LABEL 444
#define KW_EDIT 445
#define KW_DATEEDIT 446
#define KW_SCROLL 447
#define KW_IMAGE 448
#define KW_FONTPITCH 449
#define KW_FIXED 450
#define KW_VARIABLE 451
#define KW_WANTNORETURNS 452
#define KW_WANTTABS 453
#define KW_AUTOSCALE 454
#define KW_PIXELWIDTH 455
#define KW_PIXELHEIGHT 456
#define KW_BORDER 457
#define KW_SCROLLBARS_BOTH 458
#define KW_SCROLLBARS_V 459
#define KW_SCROLLBARS_H 460
#define KW_STRETCH_Y 461
#define KW_STRETCH_BOTH 462
#define KW_ITEMS 463
#define KW_VALUEMAX 464
#define KW_VALUEMIN 465
#define KW_PROGRESSBAR 466
#define KW_COMBOBOX 467
#define OPTIONS 468
#define KW_BROWSER 469
#define KW_VALUECHECKED 470
#define KW_VALUEUNCHECKED 471
#define KW_CHECKBOX 472




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
#line 654 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 666 "y.tab.c"

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
#define YYLAST   863

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  218
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  161
/* YYNRULES -- Number of rules.  */
#define YYNRULES  474
/* YYNRULES -- Number of states.  */
#define YYNSTATES  781

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   472

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
     215,   216,   217
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
     160,   162,   164,   166,   168,   170,   172,   176,   178,   181,
     182,   186,   187,   192,   193,   194,   195,   205,   206,   208,
     209,   212,   217,   218,   220,   222,   225,   227,   229,   231,
     233,   235,   237,   239,   241,   243,   245,   247,   249,   252,
     253,   258,   260,   261,   266,   267,   271,   273,   276,   280,
     283,   284,   287,   289,   293,   297,   303,   307,   311,   315,
     317,   320,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   342,   348,   350,   353,   357,   359,   361,
     362,   363,   370,   371,   375,   381,   385,   387,   388,   394,
     398,   401,   406,   409,   414,   418,   420,   425,   428,   430,
     434,   438,   440,   444,   446,   450,   452,   457,   460,   462,
     465,   466,   469,   471,   475,   477,   482,   485,   490,   494,
     498,   502,   506,   512,   516,   522,   524,   526,   530,   536,
     540,   544,   548,   550,   555,   557,   559,   561,   563,   567,
     571,   573,   575,   577,   579,   581,   583,   585,   587,   590,
     593,   595,   597,   599,   601,   605,   609,   611,   615,   619,
     623,   625,   627,   629,   631,   633,   639,   643,   647,   651,
     655,   659,   663,   667,   671,   673,   675,   677,   679,   682,
     684,   686,   688,   690,   692,   694,   696,   698,   700,   702,
     704,   706,   708,   710,   712,   714,   715,   719,   721,   724,
     726,   729,   732,   734,   735,   745,   758,   760,   762,   763,
     766,   767,   769,   770,   772,   774,   779,   781,   785,   786,
     788,   790,   794,   798,   802,   806,   808,   812,   814,   816,
     817,   819,   821,   824,   826,   828,   830,   831,   836,   838,
     840,   842,   844,   846,   848,   851,   854,   857,   860,   862,
     864,   866,   868,   870,   872,   876,   878,   882,   884,   887,
     890,   892,   894,   896,   898,   900,   902,   906,   910,   912,
     914,   916,   918,   920,   921,   925,   931,   932,   936,   937,
     941,   943,   946,   948,   950,   952,   954,   956,   958,   961,
     963,   964,   968,   970,   972,   974,   976,   978,   980,   982,
     984,   987,   988,   992,   993,   995,   998,  1000,  1004,  1008,
    1012,  1016,  1020,  1024,  1029,  1033,  1036,  1039,  1041,  1047,
    1053,  1056,  1060,  1062,  1064,  1066,  1068,  1070,  1072,  1076,
    1079,  1081,  1084,  1092,  1094,  1098,  1102,  1104,  1106,  1108,
    1114,  1120,  1123,  1126,  1128,  1130,  1132,  1134,  1136,  1138,
    1140,  1146,  1147,  1150,  1152,  1157,  1160,  1164,  1167,  1171,
    1175,  1177,  1180,  1183,  1187,  1191,  1196,  1198,  1201,  1203,
    1206,  1208,  1210,  1212,  1214,  1216,  1218,  1220,  1222,  1224,
    1226,  1228,  1232,  1236,  1238,  1243,  1244,  1251,  1252,  1254,
    1256,  1260,  1262,  1264,  1268,  1272,  1275,  1278,  1280,  1283,
    1287,  1292,  1296,  1300,  1304,  1308,  1312,  1316,  1320,  1324,
    1328,  1333,  1337,  1340,  1343,  1349,  1355,  1362,  1364,  1366,
    1368,  1370,  1372,  1374,  1376
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     219,     0,    -1,   221,   220,   225,   268,   273,   299,    -1,
      -1,    47,    46,    -1,    21,    34,    -1,    21,   224,    40,
      41,    42,    -1,    21,    34,    40,    41,    42,    -1,    21,
     224,    -1,    30,    -1,    30,    -1,   174,    -1,   174,    38,
     223,    -1,   222,    -1,   222,    38,   223,    -1,   249,    -1,
     248,    -1,   178,   232,   241,   245,    27,    -1,   177,   232,
     241,   245,    27,    -1,   180,   232,   241,   245,    27,    -1,
     182,   232,   241,   230,    27,    -1,   231,    -1,   230,   231,
      -1,   176,   232,   241,   245,    27,    -1,    -1,   223,    -1,
      -1,    -1,    -1,   179,   234,   232,   241,    31,   235,   260,
      32,   236,    27,    -1,    -1,    -1,    -1,   181,   238,   232,
     241,    31,   239,   260,    32,   240,    27,    -1,    -1,    -1,
      52,   242,   244,    53,    -1,   183,    45,    46,    -1,   185,
      -1,   186,    -1,   115,    45,    46,    -1,   175,    45,    30,
      -1,   202,    -1,   243,    -1,   244,   243,    -1,   244,    59,
     243,    -1,    -1,   246,    -1,   247,    -1,   246,   247,    -1,
     226,    -1,   227,    -1,   228,    -1,   229,    -1,   233,    -1,
     237,    -1,   184,   247,   259,    -1,   250,    -1,   249,   250,
      -1,    -1,    24,   251,   253,    -1,    -1,    23,    46,   252,
     253,    -1,    -1,    -1,    -1,   258,   254,   257,    31,   255,
     260,    32,   256,   259,    -1,    -1,   173,    -1,    -1,    25,
      29,    -1,    25,    29,    22,    29,    -1,    -1,    27,    -1,
     262,    -1,   260,   262,    -1,   223,    -1,   261,    -1,   264,
      -1,   147,    -1,    17,    -1,    44,    -1,    46,    -1,   263,
      -1,   146,    -1,   122,    -1,   118,    -1,    16,    -1,   263,
      16,    -1,    -1,    26,   265,   266,    28,    -1,   317,    -1,
      -1,   266,    44,   267,   317,    -1,    -1,    43,   269,   259,
      -1,   270,    -1,   269,   270,    -1,   269,    59,   270,    -1,
     223,   271,    -1,    -1,    45,   272,    -1,   223,    -1,   223,
      37,   223,    -1,   223,    38,   223,    -1,   223,    38,   223,
      37,   223,    -1,   223,    39,   223,    -1,    46,    39,   223,
      -1,    20,   274,   259,    -1,   276,    -1,   274,   276,    -1,
      -1,   190,    -1,   187,    -1,   189,    -1,   191,    -1,   188,
      -1,   193,    -1,   211,    -1,   212,    -1,   217,    -1,   214,
      -1,    -1,   275,   316,   277,   278,    48,    -1,   280,    -1,
     278,   280,    -1,   278,    48,   280,    -1,    45,    -1,    37,
      -1,    -1,    -1,   279,   281,   286,   283,   282,   293,    -1,
      -1,    26,    29,    28,    -1,    26,    29,    59,    29,    28,
      -1,   285,   128,    41,    -1,   285,    -1,    -1,    61,    73,
     223,    39,   223,    -1,    61,    73,   223,    -1,    61,   319,
      -1,    34,    39,   312,   284,    -1,   144,   284,    -1,   144,
     145,    42,   284,    -1,   223,    39,   223,    -1,   223,    -1,
      54,   223,    39,   223,    -1,    54,   223,    -1,   288,    -1,
     287,    59,   288,    -1,   289,    45,   290,    -1,   316,    -1,
     223,    39,   223,    -1,   223,    -1,   223,    39,   223,    -1,
     223,    -1,    54,   223,    39,   223,    -1,    54,   223,    -1,
      50,    -1,    59,    50,    -1,    -1,    59,   294,    -1,   295,
      -1,   294,    59,   295,    -1,    89,    -1,    90,    45,   297,
     338,    -1,    51,   291,    -1,    49,   287,   292,   291,    -1,
      91,    45,    46,    -1,    92,    45,   296,    -1,   213,    45,
     296,    -1,    94,    73,   223,    -1,    94,    73,   223,    39,
     223,    -1,    93,    73,   223,    -1,    93,    73,   223,    39,
     223,    -1,    95,    -1,    96,    -1,    97,    45,    46,    -1,
      98,    45,    52,   320,    53,    -1,   120,    45,    46,    -1,
     121,    45,    46,    -1,   175,    45,   223,    -1,    99,    -1,
      36,    25,    45,    29,    -1,    36,    -1,   119,    -1,   101,
      -1,   100,    -1,   102,    45,    46,    -1,   103,    45,    46,
      -1,   104,    -1,   112,    -1,    83,    -1,   106,    -1,   105,
      -1,   172,    -1,   171,    -1,   107,    -1,   107,   108,    -1,
     107,   109,    -1,   185,    -1,   199,    -1,   197,    -1,   198,
      -1,   194,    45,   195,    -1,   194,    45,   196,    -1,   192,
      -1,   193,    45,    46,    -1,   201,    45,    29,    -1,   200,
      45,    29,    -1,   203,    -1,   204,    -1,   205,    -1,   206,
      -1,   207,    -1,   208,    45,    52,   321,    53,    -1,   209,
      45,    29,    -1,   210,    45,    29,    -1,   215,    45,    46,
      -1,   216,    45,    46,    -1,   215,    45,    29,    -1,   216,
      45,    29,    -1,   115,    45,    46,    -1,   183,    45,    46,
      -1,    46,    -1,    29,    -1,   117,    -1,   298,    -1,   297,
     298,    -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,    29,    -1,
      83,    -1,    88,    -1,    82,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    -1,    19,   300,   259,    -1,   301,
      -1,   300,   301,    -1,   302,    -1,   302,    48,    -1,    62,
      46,    -1,   352,    -1,    -1,    24,    58,   303,   307,    52,
     308,    53,   304,   306,    -1,   143,    52,    29,    59,    29,
      53,   110,    52,    29,    59,    29,    53,    -1,   345,    -1,
     368,    -1,    -1,   111,   141,    -1,    -1,    54,    -1,    -1,
      48,    -1,   223,    -1,   223,    26,    29,    28,    -1,   311,
      -1,   308,   309,   311,    -1,    -1,    59,    -1,   223,    -1,
     223,    39,   223,    -1,    34,    39,   223,    -1,   223,    39,
      54,    -1,    34,    39,    54,    -1,   310,    -1,   310,    60,
     310,    -1,   223,    -1,    27,    -1,    -1,   314,    -1,   315,
      -1,   314,   315,    -1,   146,    -1,   147,    -1,   223,    -1,
      -1,   313,   223,   318,   313,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,   326,
      -1,    70,   326,    -1,    71,   333,    -1,    72,   327,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   142,    -1,
     324,    -1,   320,    59,   324,    -1,   323,    -1,   321,    59,
     323,    -1,    29,    -1,    56,    29,    -1,    57,    29,    -1,
      46,    -1,    30,    -1,    16,    -1,   322,    -1,    41,    -1,
     325,    -1,   325,   110,   325,    -1,   325,    37,   325,    -1,
      46,    -1,    30,    -1,    16,    -1,   322,    -1,    41,    -1,
      -1,    52,    29,    53,    -1,    52,    29,    59,    29,    53,
      -1,    -1,   330,   110,   332,    -1,    -1,    52,    29,    53,
      -1,    29,    -1,   331,   328,    -1,   134,    -1,   135,    -1,
     136,    -1,   137,    -1,   138,    -1,   139,    -1,   140,   337,
      -1,   331,    -1,    -1,   334,   110,   335,    -1,   336,    -1,
     336,    -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,
     138,    -1,   139,    -1,   140,   337,    -1,    -1,    52,   329,
      53,    -1,    -1,   339,    -1,   127,   340,    -1,   341,    -1,
     341,   125,   341,    -1,   341,   124,   341,    -1,   342,   123,
     342,    -1,   342,     8,   342,    -1,   342,     9,   342,    -1,
     342,    73,   342,    -1,   342,   128,    73,   342,    -1,   342,
      45,   342,    -1,   342,   132,    -1,   342,   133,    -1,   342,
      -1,   342,   129,   342,   125,   342,    -1,   342,   130,    52,
     344,    53,    -1,   128,   341,    -1,    52,   341,    53,    -1,
     343,    -1,    29,    -1,    46,    -1,   131,    -1,    30,    -1,
     342,    -1,   344,    59,   342,    -1,    18,   346,    -1,   347,
      -1,   346,   347,    -1,     8,   348,     9,   305,     8,   348,
       9,    -1,   349,    -1,   348,    59,   349,    -1,   350,    39,
     351,    -1,   351,    -1,   223,    -1,   222,    -1,   149,   362,
     154,   366,   360,    -1,   150,   363,   154,   366,   360,    -1,
     159,   369,    -1,   158,   369,    -1,   356,    -1,   361,    -1,
     354,    -1,   357,    -1,   358,    -1,   369,    -1,   359,    -1,
     166,   374,   167,   353,   355,    -1,    -1,   168,   353,    -1,
     162,    -1,   163,   316,    45,   374,    -1,   165,   316,    -1,
     165,    45,   316,    -1,   165,   164,    -1,   165,    45,   164,
      -1,   169,   360,    27,    -1,   353,    -1,   360,   353,    -1,
      91,    46,    -1,    91,   161,    46,    -1,    91,    83,    46,
      -1,    91,   161,    83,    46,    -1,   364,    -1,   362,   364,
      -1,   365,    -1,   363,   365,    -1,   151,    -1,   152,    -1,
     153,    -1,   151,    -1,   155,    -1,   156,    -1,   157,    -1,
     153,    -1,    94,    -1,   152,    -1,   367,    -1,   366,   309,
     367,    -1,   350,    39,   351,    -1,   351,    -1,   350,   148,
     350,   306,    -1,    -1,   160,   223,    52,   370,   371,    53,
      -1,    -1,   372,    -1,   373,    -1,   372,    59,   373,    -1,
     374,    -1,   375,    -1,   374,   125,   374,    -1,   374,   124,
     374,    -1,    57,   374,    -1,    56,   374,    -1,   377,    -1,
     128,   374,    -1,    52,   374,    53,    -1,   376,    52,   371,
      53,    -1,   170,   154,   316,    -1,   374,   123,   374,    -1,
     374,     8,   374,    -1,   374,     9,   374,    -1,   374,    54,
     374,    -1,   374,    56,   374,    -1,   374,    57,   374,    -1,
     374,    55,   374,    -1,   374,    73,   374,    -1,   374,   128,
      73,   374,    -1,   374,    45,   374,    -1,   374,   132,    -1,
     374,   133,    -1,   374,   129,   374,   125,   374,    -1,   374,
     130,    52,   378,    53,    -1,   374,   128,   130,    52,   378,
      53,    -1,   223,    -1,   316,    -1,    29,    -1,    46,    -1,
     131,    -1,    41,    -1,   377,    -1,   378,    59,   377,    -1
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
     705,   706,   711,   710,   739,   740,   741,   744,   744,   747,
     751,   747,  1071,  1072,  1078,  1088,  1089,  1092,  1093,  1096,
    1099,  1104,  1115,  1129,  1143,  1152,  1162,  1171,  1186,  1195,
    1204,  1211,  1213,  1216,  1222,  1223,  1224,  1225,  1228,  1229,
    1233,  1234,  1238,  1238,  1241,  1246,  1268,  1292,  1300,  1301,
    1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,
    1312,  1313,  1314,  1315,  1316,  1317,  1319,  1321,  1322,  1323,
    1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1336,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,
    1353,  1354,  1355,  1356,  1357,  1358,  1359,  1360,  1362,  1363,
    1364,  1365,  1366,  1367,  1373,  1374,  1375,  1379,  1380,  1384,
    1385,  1386,  1387,  1388,  1389,  1390,  1391,  1393,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1438,  1439,  1442,  1442,  1444,
    1444,  1447,  1457,  1463,  1463,  1466,  1467,  1468,  1472,  1472,
    1474,  1474,  1477,  1477,  1479,  1482,  1488,  1491,  1495,  1496,
    1500,  1504,  1508,  1512,  1516,  1523,  1523,  1527,  1530,  1534,
    1534,  1537,  1537,  1541,  1542,  1555,  1563,  1563,  1572,  1576,
    1580,  1584,  1588,  1592,  1596,  1602,  1606,  1610,  1614,  1618,
    1622,  1626,  1629,  1636,  1636,  1640,  1640,  1645,  1645,  1645,
    1649,  1656,  1657,  1658,  1659,  1666,  1667,  1670,  1676,  1683,
    1684,  1685,  1686,  1692,  1695,  1696,  1699,  1700,  1707,  1709,
    1714,  1722,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1737,
    1739,  1740,  1743,  1746,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1762,  1764,  1771,  1771,  1777,  1783,  1784,  1787,  1793,
    1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,
    1804,  1805,  1808,  1815,  1816,  1817,  1822,  1825,  1829,  1841,
    1844,  1845,  1849,  1859,  1866,  1875,  1878,  1890,  1893,  1897,
    1904,  1912,  1917,  1925,  1929,  1934,  1939,  1944,  1949,  1954,
    1963,  1972,  1973,  1978,  1981,  1989,  1995,  2001,  2007,  2016,
    2021,  2031,  2041,  2047,  2053,  2059,  2069,  2081,  2089,  2101,
    2109,  2110,  2111,  2115,  2116,  2117,  2118,  2119,  2120,  2121,
    2124,  2131,  2142,  2146,  2153,  2161,  2161,  2179,  2180,  2186,
    2192,  2200,  2207,  2208,  2209,  2227,  2229,  2230,  2231,  2232,
    2233,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,
    2245,  2246,  2247,  2248,  2249,  2250,  2251,  2254,  2257,  2258,
    2259,  2260,  2261,  2264,  2268
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
  "MINUTE", "SECOND", "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL",
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
  "func_call_args", "func_call_arg", "expression", "single_expression",
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
     465,   466,   467,   468,   469,   470,   471,   472
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   218,   219,   220,   220,   221,   221,   221,   221,   222,
     223,   224,   224,   224,   224,   225,   225,   226,   227,   228,
     229,   230,   230,   231,   232,   232,   234,   235,   236,   233,
     238,   239,   240,   237,   241,   242,   241,   243,   243,   243,
     243,   243,   243,   244,   244,   244,   245,   245,   246,   246,
     247,   247,   247,   247,   247,   247,   248,   249,   249,   251,
     250,   252,   250,   254,   255,   256,   253,   257,   257,   258,
     258,   258,   259,   259,   260,   260,   261,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   263,   263,   265,
     264,   266,   267,   266,   268,   268,   269,   269,   269,   270,
     271,   271,   272,   272,   272,   272,   272,   272,   273,   274,
     274,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   277,   276,   278,   278,   278,   279,   279,   281,
     282,   280,   283,   283,   283,   284,   284,   285,   285,   285,
     285,   286,   286,   286,   286,   286,   286,   286,   287,   287,
     288,   289,   290,   290,   291,   291,   291,   291,   292,   292,
     293,   293,   294,   294,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   296,   296,   296,   297,   297,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   299,   299,   300,   300,   301,
     301,   302,   302,   303,   302,   302,   302,   302,   304,   304,
     305,   305,   306,   306,   307,   307,   308,   308,   309,   309,
     310,   310,   310,   310,   310,   311,   311,   312,   312,   313,
     313,   314,   314,   315,   315,   316,   318,   317,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   320,   320,   321,   321,   322,   322,   322,
     323,   323,   323,   323,   323,   324,   324,   324,   325,   325,
     325,   325,   325,   326,   326,   326,   327,   327,   328,   328,
     329,   330,   331,   331,   331,   331,   331,   331,   331,   332,
     333,   333,   334,   335,   336,   336,   336,   336,   336,   336,
     336,   337,   337,   338,   338,   339,   340,   340,   340,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   342,   342,   342,   342,   343,   344,   344,   345,
     346,   346,   347,   348,   348,   349,   349,   350,   351,   352,
     352,   352,   352,   353,   353,   353,   353,   353,   353,   353,
     354,   355,   355,   356,   357,   358,   358,   358,   358,   359,
     360,   360,   361,   361,   361,   361,   362,   362,   363,   363,
     364,   364,   364,   365,   365,   365,   365,   365,   365,   365,
     366,   366,   367,   367,   368,   370,   369,   371,   371,   372,
     372,   373,   374,   374,   374,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   376,   377,   377,
     377,   377,   377,   378,   378
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     5,     5,     2,     1,
       1,     1,     3,     1,     3,     1,     1,     5,     5,     5,
       5,     1,     2,     5,     0,     1,     0,     0,     0,    10,
       0,     0,     0,    10,     0,     0,     4,     3,     1,     1,
       3,     3,     1,     1,     2,     3,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     0,
       3,     0,     4,     0,     0,     0,     9,     0,     1,     0,
       2,     4,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       4,     1,     0,     4,     0,     3,     1,     2,     3,     2,
       0,     2,     1,     3,     3,     5,     3,     3,     3,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     1,     2,     3,     1,     1,     0,
       0,     6,     0,     3,     5,     3,     1,     0,     5,     3,
       2,     4,     2,     4,     3,     1,     4,     2,     1,     3,
       3,     1,     3,     1,     3,     1,     4,     2,     1,     2,
       0,     2,     1,     3,     1,     4,     2,     4,     3,     3,
       3,     3,     5,     3,     5,     1,     1,     3,     5,     3,
       3,     3,     1,     4,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     1,     1,     1,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     1,     2,     1,
       2,     2,     1,     0,     9,    12,     1,     1,     0,     2,
       0,     1,     0,     1,     1,     4,     1,     3,     0,     1,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     0,     4,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     0,     3,     5,     0,     3,     0,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     3,     0,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     4,     3,     2,     2,     1,     5,     5,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     2,     7,     1,     3,     3,     1,     1,     1,     5,
       5,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       5,     0,     2,     1,     4,     2,     3,     2,     3,     3,
       1,     2,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     4,     0,     6,     0,     1,     1,
       3,     1,     1,     3,     3,     2,     2,     1,     2,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     2,     2,     5,     5,     6,     1,     1,     1,
       1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     3,     9,     5,    11,    13,     8,     1,
       0,     0,     0,     0,     0,     0,     4,     0,    59,     0,
      94,    16,    15,    57,     0,    10,    12,    14,     0,    61,
      69,    24,    24,    26,    24,    30,    24,    50,    51,    52,
      53,    54,    55,    72,     0,     0,    58,     7,     6,    69,
       0,    60,    63,    25,    34,    34,    24,    34,    24,    34,
      73,    56,   100,    72,    96,   111,   245,    62,    70,    67,
      35,    46,    46,    34,    46,    34,     0,     0,    99,     0,
      95,    97,   113,   116,   114,   112,   115,   117,   118,   119,
     121,   120,    72,     0,   109,     0,     2,     0,    68,     0,
       0,     0,    47,    48,     0,     0,     0,     0,    24,     0,
      21,     0,   102,   101,    98,   108,   110,   285,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   387,    72,   247,
     249,   256,     0,   252,   257,    71,    64,     0,     0,     0,
      38,    39,    42,    43,     0,    18,    49,    17,    27,    19,
      31,    34,    20,    22,     0,     0,     0,     0,     0,     0,
     379,   380,   253,   251,     0,   420,   421,   422,     0,   416,
     428,   423,   429,   427,   424,   425,   426,     0,   418,     0,
     392,   391,   246,   248,   250,     0,     0,     0,     0,     0,
      36,     0,    44,     0,     0,    46,   107,   103,   104,   106,
     128,   127,     0,   129,   124,     9,   388,     0,   383,     0,
     386,   381,     0,     0,     0,   417,     0,   419,     0,   262,
      87,    80,    89,    81,    82,    86,    85,    84,    79,    76,
       0,    77,    74,    83,    78,    40,    41,    37,    45,     0,
       0,     0,     0,   123,   125,     0,   260,     0,     0,   264,
       0,     0,     0,   433,   268,   430,   268,   435,   263,   434,
     279,    65,    75,    88,    28,    32,    23,   105,   126,     0,
       0,   137,   145,   132,   261,     0,   384,   385,     0,     0,
       0,     0,   269,     0,   403,     0,     0,     0,     0,     0,
     410,   395,   393,   396,   397,   399,   389,   394,   398,   390,
     437,   283,   284,     0,     0,   280,   281,    91,    72,     0,
       0,     0,   147,     0,     0,   142,   136,     0,     0,   130,
       0,     0,     0,   270,   268,   275,   266,     0,   432,   412,
       0,     0,     0,     0,   407,   405,   469,   472,   470,     0,
       0,     0,     0,   471,     0,   285,   468,     0,   442,     0,
     447,     0,   431,   411,     0,   438,   439,   441,    90,    92,
     286,   282,    66,    29,    33,   278,   277,   137,     0,   288,
     289,   290,   291,   292,   293,   323,   323,   340,   326,     0,
     298,   299,   300,   301,   302,   140,   137,     0,   144,     0,
     160,     0,   265,     0,     0,   258,     0,     0,     0,   414,
     413,     0,     0,   408,   406,     0,   446,   445,   448,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   462,   463,     0,   437,   409,   436,
       0,   279,   279,   141,   146,     0,   294,   295,   344,   345,
     346,   347,   348,   349,   351,   296,     0,   342,   332,   333,
     334,   335,   336,   337,   351,   297,     0,   328,   139,   143,
     135,   133,     0,     0,   131,   382,   274,   272,   273,   271,
       0,   262,   267,   276,     0,   415,   404,   449,   451,   453,
     454,   461,   455,   458,   456,   457,   459,   452,   444,   443,
       0,     0,     0,     0,   401,     0,   440,    93,   287,     0,
       0,   350,     0,   338,     0,     0,   331,     0,     0,   184,
       0,     0,   192,   164,     0,     0,     0,     0,     0,   175,
     176,     0,     0,   182,   187,   186,     0,     0,   190,   194,
     193,   197,   191,     0,   185,     0,     0,   196,   195,     0,
       0,   200,   206,     0,     0,   202,   203,   201,     0,     0,
     210,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,   161,   162,   259,   254,     0,   460,     0,     0,   473,
       0,     0,   400,   450,   324,     0,   330,     0,   341,   343,
     339,   327,     0,   138,   134,     0,     0,   148,     0,   151,
       0,   155,   166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,   199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   465,     0,   402,     0,   352,   329,     0,
     158,     0,     0,     0,   157,     0,   237,   229,   230,   231,
     232,   233,   234,   235,   236,   240,   238,   241,   242,   243,
     244,   239,   353,   227,   168,   225,   224,   226,   169,   173,
     171,   177,     0,   188,   189,   222,   179,   180,   181,   223,
     207,   204,   205,   209,   208,     0,   216,   217,   170,   220,
     218,   221,   219,   163,     0,   466,   474,   325,   183,   159,
     149,   167,   153,   150,     0,   154,     0,   228,   165,   354,
       0,     0,   320,   307,   319,   322,   318,     0,     0,     0,
     321,   303,   315,   312,   311,   314,   310,     0,   313,   305,
     255,     0,   156,   373,   376,   374,     0,     0,   375,   355,
     356,   367,   372,   174,   172,   308,   309,   178,     0,     0,
       0,   215,     0,   152,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   365,   366,   304,   317,
     316,   306,   371,   358,   357,   360,   361,   364,   362,   359,
       0,     0,     0,   363,     0,   377,     0,   368,   369,     0,
     378
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,     3,   206,   345,     8,    20,    37,    38,
      39,    40,   109,   110,    54,    41,    56,   193,   309,    42,
      58,   194,   310,    71,   100,   143,   144,   101,   102,   103,
      21,    22,    23,    30,    49,    51,    69,   186,   308,    99,
      52,    61,   230,   231,   232,   233,   234,   260,   303,   431,
      45,    63,    64,    78,   113,    66,    92,    93,    94,   158,
     202,   203,   204,   245,   390,   319,   315,   316,   273,   586,
     587,   588,   693,   592,   632,   464,   561,   562,   658,   652,
     653,    96,   128,   129,   130,   212,   471,   275,   259,   250,
     324,   289,   325,   326,   367,   304,   305,   306,   346,   307,
     432,   385,   709,   717,   710,   719,   711,   712,   436,   455,
     506,   577,   456,   457,   581,   445,   446,   578,   447,   501,
     698,   699,   729,   730,   731,   732,   776,   131,   160,   161,
     207,   208,   209,   210,   133,   290,   291,   572,   292,   293,
     294,   295,   296,   297,   168,   177,   169,   178,   254,   255,
     134,   298,   300,   354,   355,   356,   357,   348,   349,   350,
     570
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -647
static const yytype_int16 yypact[] =
{
      21,   -18,    70,    34,  -647,    77,    84,    86,   128,  -647,
     133,   -15,   141,   162,   162,   182,  -647,   264,  -647,   498,
     185,  -647,   181,  -647,   272,  -647,  -647,  -647,   299,  -647,
     325,   162,   162,  -647,   162,  -647,   162,  -647,  -647,  -647,
    -647,  -647,  -647,   333,   162,   348,  -647,  -647,  -647,   325,
     347,  -647,  -647,  -647,   330,   330,   162,   330,   162,   330,
    -647,  -647,   340,   211,  -647,   605,   376,  -647,   394,   245,
    -647,   498,   498,   330,   498,   330,   270,    33,  -647,   162,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,    -3,   162,  -647,   153,  -647,   405,  -647,   413,
     104,   424,   498,  -647,   425,   422,   427,   429,   162,   -21,
    -647,   416,   355,  -647,  -647,  -647,  -647,  -647,  -647,   450,
     406,   421,   417,   247,   380,   318,   318,  -647,   213,  -647,
     420,  -647,   335,  -647,  -647,  -647,  -647,   442,   443,   447,
    -647,  -647,  -647,  -647,    50,  -647,  -647,  -647,  -647,  -647,
    -647,   330,  -647,  -647,   162,   162,   162,   162,   241,   455,
     450,  -647,  -647,  -647,   461,  -647,  -647,  -647,   236,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   349,  -647,   162,
    -647,  -647,  -647,  -647,  -647,   162,   445,   449,   463,   453,
    -647,   104,  -647,   445,   445,   498,  -647,  -647,   459,  -647,
    -647,  -647,   268,  -647,  -647,   468,  -647,    16,  -647,   471,
    -647,  -647,   162,   452,   455,  -647,   455,  -647,   460,   465,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
      75,  -647,  -647,   501,  -647,  -647,  -647,  -647,  -647,   433,
     440,   487,   162,   241,  -647,   -19,   462,   455,   489,   494,
     469,   493,   486,  -647,   180,  -647,   180,  -647,  -647,  -647,
     -94,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   499,
     162,   -48,   502,   513,  -647,   534,  -647,  -647,   514,   258,
     491,   489,  -647,   -12,  -647,   162,   -25,   345,    98,   455,
    -647,  -647,  -647,  -647,  -647,  -647,    98,  -647,  -647,    98,
     345,  -647,  -647,   218,   162,   -94,  -647,  -647,   333,   522,
     523,   140,   517,   632,   510,  -647,   437,   162,   524,  -647,
     455,   529,   527,   537,   206,   508,  -647,   451,  -647,  -647,
     532,     5,   536,   -16,  -647,  -647,  -647,  -647,  -647,   345,
     345,   345,   345,  -647,   428,   533,  -647,    29,  -647,   538,
    -647,    85,  -647,  -647,   540,   530,  -647,   515,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   539,   162,  -647,
    -647,  -647,  -647,  -647,  -647,   543,   543,   274,   615,   162,
    -647,  -647,  -647,  -647,  -647,  -647,   539,   558,  -647,   132,
     545,    35,  -647,    24,    60,   496,   258,   258,   556,  -647,
    -647,   567,   345,  -647,  -647,   473,   515,   515,   515,   162,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   -32,   345,   563,  -647,  -647,    98,   345,  -647,  -647,
     345,   -94,   -94,  -647,  -647,   587,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   565,  -647,   511,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   565,  -647,   521,   572,   588,  -647,
    -647,  -647,   606,   232,  -647,  -647,  -647,  -647,  -647,  -647,
     495,   465,  -647,  -647,   612,  -647,   515,  -647,  -647,   637,
     637,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     345,   582,   601,    19,   481,   597,  -647,  -647,  -647,   221,
     622,  -647,   274,  -647,   615,   625,  -647,   162,   655,   659,
     162,   110,  -647,  -647,   640,   641,   644,   617,   633,  -647,
    -647,   662,   664,  -647,  -647,  -647,   666,   673,  -647,  -647,
    -647,   147,  -647,   675,  -647,   676,   677,  -647,  -647,   678,
     682,  -647,  -647,   683,   691,  -647,  -647,  -647,   693,   695,
    -647,  -647,  -647,  -647,  -647,   696,   697,   698,   711,   712,
     713,   700,  -647,  -647,  -647,   704,   515,    19,   345,  -647,
     295,    98,  -647,  -647,  -647,   735,  -647,   715,  -647,  -647,
    -647,  -647,   718,  -647,  -647,   727,    61,  -647,   728,  -647,
     162,   736,  -647,   703,   730,    -7,   162,   162,   751,   747,
     754,   755,  -647,  -647,   756,   757,   758,   162,   759,   760,
     105,   778,   779,   761,   780,   781,    -7,   178,   184,   232,
     782,   306,   515,  -647,    19,  -647,   762,  -647,  -647,   783,
    -647,    17,   110,   162,   775,   162,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   585,  -647,  -647,  -647,  -647,  -647,  -647,   784,
     785,  -647,   518,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,   596,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   765,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   786,  -647,   162,  -647,    47,  -647,  -647,  -647,
     162,   162,  -647,  -647,  -647,  -647,  -647,   791,   792,   308,
    -647,  -647,     3,  -647,  -647,  -647,  -647,   311,  -647,  -647,
    -647,   162,  -647,  -647,  -647,  -647,    47,    47,  -647,  -647,
     281,   500,  -647,  -647,  -647,  -647,  -647,  -647,   518,   518,
     518,  -647,   596,  -647,   773,  -647,    47,    47,    43,    43,
      43,    43,    43,   763,    43,   776,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
      43,   702,    43,  -647,    43,  -647,   320,  -647,  -647,    43,
    -647
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -647,  -647,  -647,  -647,   828,   -13,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   721,   261,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   143,  -647,   -83,  -647,   -44,  -647,    -2,
    -647,  -647,   809,  -647,  -647,   788,  -647,  -647,  -647,  -647,
    -647,   -59,   227,  -647,    69,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   190,  -647,  -647,  -647,  -647,  -647,   740,  -647,
    -647,  -647,  -156,  -647,  -647,  -647,  -263,  -647,  -647,  -647,
     202,  -647,  -647,   203,  -647,  -647,  -647,   215,   222,  -647,
     187,  -647,  -647,   714,  -647,  -647,  -647,  -647,   369,  -647,
    -647,   519,   444,   448,  -647,   414,  -647,   542,   -91,   418,
    -647,  -647,  -647,  -647,  -646,   103,   112,  -317,   472,  -647,
    -647,  -647,  -647,   350,  -647,  -647,  -647,  -647,   351,   397,
    -647,  -647,  -647,  -369,   -35,  -647,  -647,  -647,  -647,   692,
     535,   609,   -69,    -4,  -647,  -289,  -647,  -647,  -647,  -647,
    -647,  -647,  -220,  -647,  -647,  -647,   689,   681,   643,   571,
    -647,   302,  -647,   434,  -647,   432,  -284,  -647,  -647,  -461,
     296
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -468
static const yytype_int16 yytable[] =
{
      26,    27,   118,   347,    80,    25,   152,   353,    17,    18,
     353,    25,     4,   313,    25,   269,     5,    43,    53,    53,
     333,    53,   655,    53,    60,   246,   132,  -111,   104,   718,
     106,    62,   569,   115,   329,   270,   299,   410,   411,   656,
     739,   490,     1,    53,   465,    53,   244,    25,   336,    25,
      62,   400,   301,   302,    25,   405,   406,   407,   408,   132,
     337,   192,   353,    25,   112,   338,    62,   689,   351,   182,
       9,   330,   723,   724,   412,   247,   723,   724,   466,   111,
     117,    10,   127,   413,   414,   415,   416,   268,   401,   725,
      25,   220,   221,   725,   247,    53,   718,   314,   491,   726,
     146,   222,   417,   190,   433,    25,   569,   261,   238,   191,
     657,   630,   428,   740,   468,   127,   219,    12,   476,   223,
     631,   224,    13,   459,    14,   271,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   494,   492,   334,
      25,   196,   197,   198,   199,   252,   127,   252,   403,   331,
     343,   241,   418,   419,   420,   108,     6,   421,   422,   423,
     461,   424,   425,   686,   590,   137,   218,   365,    15,    19,
      25,   119,   127,   229,   728,   727,   283,   120,   728,    16,
     229,   229,    24,    25,    82,    83,    84,    85,    86,   283,
      87,   462,    25,   225,   332,   335,   426,   226,    72,   249,
      74,   127,    76,   127,    17,    18,   566,   679,    88,    89,
     253,    90,   253,   681,    91,   121,   105,   229,   107,   137,
     252,   227,   228,    28,   680,   138,   229,   229,    44,   267,
     682,   119,   272,   139,   127,   140,   141,   120,    60,   282,
      60,    25,   404,    25,   277,   179,   358,   284,   285,   362,
     286,   287,   142,    81,   288,   602,   603,   312,   179,   395,
     284,   285,   359,   286,   287,   282,   323,   288,   509,   114,
      79,   283,   117,   117,   574,   121,   127,   328,   200,   138,
     575,   510,   625,   511,   622,   253,   201,   139,    25,   140,
     141,   360,   322,    55,   195,    57,   122,    59,   366,   262,
     671,   672,   123,   124,   388,   200,   142,   127,   262,   262,
      29,   125,   126,   201,    47,   512,   243,    73,   478,    75,
     117,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     179,    48,   284,   285,   532,   286,   287,   533,   623,   288,
      50,   534,   535,   536,   624,   434,   122,   744,   745,   685,
      60,   737,   123,   124,   741,   624,   458,   738,    65,   151,
     742,   125,   126,   778,   336,    25,    68,   763,   764,   779,
     467,   469,    70,   323,   323,    77,   337,   165,   166,   167,
     214,   338,   155,   156,   157,    95,   117,   339,   165,   166,
     167,   340,   341,   537,   538,   746,   747,   539,   438,   439,
     440,   441,   442,   443,   444,   540,    97,   541,    98,   589,
     239,   240,   759,   760,   542,   543,   544,   180,   181,   545,
     546,   547,   548,   549,   135,   550,   551,   552,   553,   554,
     555,   556,   557,   170,   136,   558,   108,   559,   560,   220,
     221,   145,   147,   148,   149,   154,   220,   221,   159,   222,
     150,   220,   221,    25,   162,   264,   222,   163,   184,   164,
      25,   222,   265,   342,   170,    25,   343,   223,   179,   224,
     117,   410,   411,   185,   223,   205,   224,   187,   188,   223,
     213,   224,   189,   236,   583,   235,   242,   117,   591,   237,
     171,   172,   173,   216,   174,   175,   176,   -10,   748,   749,
     248,   251,   257,   258,   266,   344,   274,   263,   412,     4,
     278,   279,   280,   410,   411,   281,   477,   413,   414,   415,
     416,   171,   172,   173,   702,   174,   175,   176,   311,   318,
     589,   317,   320,   321,   327,   750,   417,   703,   704,   363,
     364,   225,   386,   389,   117,   226,   368,   392,   225,   705,
     412,   398,   226,   225,   706,   387,   393,   226,   397,   413,
     414,   415,   416,   751,   707,   708,   394,   634,   399,   227,
     228,   402,   409,   659,   660,  -467,   227,   228,   417,   430,
     427,   227,   228,   429,   668,   435,   418,   419,   420,   460,
     313,   421,   422,   423,   463,   424,   425,   470,   474,   410,
     411,   117,   713,   475,   636,   493,   499,   500,   117,   591,
     692,   502,   695,   752,   505,   703,   714,   507,   753,   754,
     755,   504,   756,   757,   567,   508,   563,   715,   418,   419,
     420,   565,   716,   421,   422,   423,   412,   424,   425,   571,
     573,   576,   707,   708,   582,   413,   414,   415,   416,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   417,    31,    32,    33,    34,    35,
      36,   722,   412,   584,   585,   593,   594,   733,   734,   595,
     596,   413,   414,   415,   416,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   597,   598,   743,   599,
     417,   600,   696,   765,   766,   767,   768,   769,   601,   771,
     604,   605,   606,   607,   418,   419,   568,   608,   609,   421,
     422,   423,   636,   424,   425,   773,   610,   775,   611,   777,
     612,   613,   614,   615,   780,   380,   381,   382,   383,   448,
     449,   450,   451,   452,   453,   454,   616,   617,   618,   619,
     418,   419,   420,   620,   626,   421,   422,   423,   627,   424,
     425,   628,   629,   633,   384,   635,   654,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   651,    82,    83,    84,    85,    86,   661,    87,   662,
     663,   664,   665,   666,   667,   669,   670,   673,   674,   676,
     677,   684,   688,   675,   694,   687,    88,    89,   720,    90,
     735,   736,    91,   700,   701,   721,   762,   774,   772,     7,
     153,    46,   116,   690,   683,   691,   770,    67,   678,   697,
     564,   473,   183,   396,   472,   761,   498,   361,   437,   497,
     758,   503,   211,   579,   580,   391,   276,   215,   217,   256,
     352,   495,   496,   621
};

static const yytype_uint16 yycheck[] =
{
      13,    14,    93,   287,    63,    30,    27,   296,    23,    24,
     299,    30,    30,    61,    30,    34,    34,    19,    31,    32,
      45,    34,    29,    36,    27,     9,    95,    30,    72,   675,
      74,    44,   493,    92,    46,    54,   256,     8,     9,    46,
      37,    73,    21,    56,     9,    58,   202,    30,    29,    30,
      63,    46,   146,   147,    30,   339,   340,   341,   342,   128,
      41,   144,   351,    30,    77,    46,    79,    50,   288,   128,
       0,    83,    29,    30,    45,    59,    29,    30,    54,    46,
      93,    47,    95,    54,    55,    56,    57,   243,    83,    46,
      30,    16,    17,    46,    59,   108,   742,   145,   130,    52,
     102,    26,    73,    53,   367,    30,   567,    32,   191,    59,
     117,    50,    27,   110,    54,   128,   185,    40,   402,    44,
      59,    46,    38,   386,    38,   144,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   426,   422,   164,
      30,   154,   155,   156,   157,   214,   159,   216,   164,   161,
     131,   195,   123,   124,   125,   176,   174,   128,   129,   130,
      28,   132,   133,   624,    54,   115,   179,    27,    40,   184,
      30,    18,   185,   186,   131,   128,    91,    24,   131,    46,
     193,   194,    41,    30,   187,   188,   189,   190,   191,    91,
     193,    59,    30,   118,   285,   286,   167,   122,    55,   212,
      57,   214,    59,   216,    23,    24,   490,    29,   211,   212,
     214,   214,   216,    29,   217,    62,    73,   230,    75,   115,
     289,   146,   147,    41,    46,   175,   239,   240,    43,   242,
      46,    18,   245,   183,   247,   185,   186,    24,    27,    59,
      27,    30,   333,    30,   248,   160,    28,   162,   163,   308,
     165,   166,   202,    63,   169,   108,   109,   270,   160,    53,
     162,   163,    44,   165,   166,    59,   279,   169,    36,    79,
      59,    91,   285,   286,    53,    62,   289,   281,    37,   175,
      59,    49,   571,    51,   568,   289,    45,   183,    30,   185,
     186,   304,    34,    32,   151,    34,   143,    36,   311,   230,
     195,   196,   149,   150,   317,    37,   202,   320,   239,   240,
      46,   158,   159,    45,    42,    83,    48,    56,   409,    58,
     333,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     160,    42,   162,   163,   112,   165,   166,   115,    53,   169,
      25,   119,   120,   121,    59,   368,   143,   726,   727,    53,
      27,    53,   149,   150,    53,    59,   379,    59,    20,   108,
      59,   158,   159,    53,    29,    30,    29,   746,   747,    59,
     393,   394,    52,   396,   397,    45,    41,   151,   152,   153,
     154,    46,    37,    38,    39,    19,   409,    52,   151,   152,
     153,    56,    57,   171,   172,   124,   125,   175,   134,   135,
     136,   137,   138,   139,   140,   183,    22,   185,   173,   510,
     193,   194,   739,   740,   192,   193,   194,   125,   126,   197,
     198,   199,   200,   201,    29,   203,   204,   205,   206,   207,
     208,   209,   210,    94,    31,   213,   176,   215,   216,    16,
      17,    27,    27,    31,    27,    39,    16,    17,     8,    26,
      31,    16,    17,    30,    58,    32,    26,    46,    48,    52,
      30,    26,    32,   128,    94,    30,   131,    44,   160,    46,
     493,     8,     9,   148,    44,    30,    46,    45,    45,    44,
      29,    46,    45,    30,   507,    46,    37,   510,   511,    46,
     151,   152,   153,   154,   155,   156,   157,    39,     8,     9,
      39,    59,    52,    48,    27,   170,    54,    16,    45,    30,
      26,    52,    29,     8,     9,    39,    53,    54,    55,    56,
      57,   151,   152,   153,    16,   155,   156,   157,    39,    26,
     631,    39,     8,    29,    53,    45,    73,    29,    30,    27,
      27,   118,    42,    29,   567,   122,    39,    28,   118,    41,
      45,   110,   122,   118,    46,   128,    39,   122,    60,    54,
      55,    56,    57,    73,    56,    57,    39,   590,    46,   146,
     147,    45,   154,   596,   597,    52,   146,   147,    73,    59,
      52,   146,   147,    53,   607,    52,   123,   124,   125,    41,
      61,   128,   129,   130,    59,   132,   133,   111,    52,     8,
       9,   624,    16,    46,    29,    52,    29,    52,   631,   632,
     633,   110,   635,   123,    52,    29,    30,    39,   128,   129,
     130,   110,   132,   133,    52,    29,   141,    41,   123,   124,
     125,    29,    46,   128,   129,   130,    45,   132,   133,   168,
      53,    29,    56,    57,    29,    54,    55,    56,    57,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    73,   177,   178,   179,   180,   181,
     182,   694,    45,    28,    25,    45,    45,   700,   701,    45,
      73,    54,    55,    56,    57,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    73,    45,   721,    45,
      73,    45,   127,   748,   749,   750,   751,   752,    45,   754,
      45,    45,    45,    45,   123,   124,   125,    45,    45,   128,
     129,   130,    29,   132,   133,   770,    45,   772,    45,   774,
      45,    45,    45,    45,   779,   113,   114,   115,   116,   134,
     135,   136,   137,   138,   139,   140,    45,    45,    45,    59,
     123,   124,   125,    59,    29,   128,   129,   130,    53,   132,
     133,    53,    45,    45,   142,    39,    46,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   187,   188,   189,   190,   191,    46,   193,    52,
      46,    46,    46,    46,    46,    46,    46,    29,    29,    29,
      29,    29,    29,    52,    39,    53,   211,   212,    53,   214,
      29,    29,   217,    39,    39,    39,    53,   125,    52,     1,
     109,    22,    92,   631,   619,   632,    73,    49,   616,   652,
     471,   397,   128,   324,   396,   742,   432,   305,   376,   431,
     738,   454,   160,   502,   504,   320,   247,   168,   177,   216,
     289,   427,   430,   567
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   219,   221,    30,    34,   174,   222,   224,     0,
      47,   220,    40,    38,    38,    40,    46,    23,    24,   184,
     225,   248,   249,   250,    41,    30,   223,   223,    41,    46,
     251,   177,   178,   179,   180,   181,   182,   226,   227,   228,
     229,   233,   237,   247,    43,   268,   250,    42,    42,   252,
      25,   253,   258,   223,   232,   232,   234,   232,   238,   232,
      27,   259,   223,   269,   270,    20,   273,   253,    29,   254,
      52,   241,   241,   232,   241,   232,   241,    45,   271,    59,
     259,   270,   187,   188,   189,   190,   191,   193,   211,   212,
     214,   217,   274,   275,   276,    19,   299,    22,   173,   257,
     242,   245,   246,   247,   245,   241,   245,   241,   176,   230,
     231,    46,   223,   272,   270,   259,   276,   223,   316,    18,
      24,    62,   143,   149,   150,   158,   159,   223,   300,   301,
     302,   345,   350,   352,   368,    29,    31,   115,   175,   183,
     185,   186,   202,   243,   244,    27,   247,    27,    31,    27,
      31,   232,    27,   231,    39,    37,    38,    39,   277,     8,
     346,   347,    58,    46,    52,   151,   152,   153,   362,   364,
      94,   151,   152,   153,   155,   156,   157,   363,   365,   160,
     369,   369,   259,   301,    48,   148,   255,    45,    45,    45,
      53,    59,   243,   235,   239,   241,   223,   223,   223,   223,
      37,    45,   278,   279,   280,    30,   222,   348,   349,   350,
     351,   347,   303,    29,   154,   364,   154,   365,   223,   350,
      16,    17,    26,    44,    46,   118,   122,   146,   147,   223,
     260,   261,   262,   263,   264,    46,    30,    46,   243,   260,
     260,   245,    37,    48,   280,   281,     9,    59,    39,   223,
     307,    59,   350,   351,   366,   367,   366,    52,    48,   306,
     265,    32,   262,    16,    32,    32,    27,   223,   280,    34,
      54,   144,   223,   286,    54,   305,   349,   351,    26,    52,
      29,    39,    59,    91,   162,   163,   165,   166,   169,   309,
     353,   354,   356,   357,   358,   359,   360,   361,   369,   360,
     370,   146,   147,   266,   313,   314,   315,   317,   256,   236,
     240,    39,   223,    61,   145,   284,   285,    39,    26,   283,
       8,    29,    34,   223,   308,   310,   311,    53,   351,    46,
      83,   161,   316,    45,   164,   316,    29,    41,    46,    52,
      56,    57,   128,   131,   170,   223,   316,   374,   375,   376,
     377,   360,   367,   353,   371,   372,   373,   374,    28,    44,
     223,   315,   259,    27,    27,    27,   223,   312,    39,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
     113,   114,   115,   116,   142,   319,    42,   128,   223,    29,
     282,   348,    28,    39,    39,    53,   309,    60,   110,    46,
      46,    83,    45,   164,   316,   374,   374,   374,   374,   154,
       8,     9,    45,    54,    55,    56,    57,    73,   123,   124,
     125,   128,   129,   130,   132,   133,   167,    52,    27,    53,
      59,   267,   318,   284,   223,    52,   326,   326,   134,   135,
     136,   137,   138,   139,   140,   333,   334,   336,   134,   135,
     136,   137,   138,   139,   140,   327,   330,   331,   223,   284,
      41,    28,    59,    59,   293,     9,    54,   223,    54,   223,
     111,   304,   311,   310,    52,    46,   374,    53,   316,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
      73,   130,   374,    52,   353,   371,   373,   317,   313,    29,
      52,   337,   110,   337,   110,    52,   328,    39,    29,    36,
      49,    51,    83,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   112,   115,   119,   120,   121,   171,   172,   175,
     183,   185,   192,   193,   194,   197,   198,   199,   200,   201,
     203,   204,   205,   206,   207,   208,   209,   210,   213,   215,
     216,   294,   295,   141,   306,    29,   374,    52,   125,   377,
     378,   168,   355,    53,    53,    59,    29,   329,   335,   336,
     331,   332,    29,   223,    28,    25,   287,   288,   289,   316,
      54,   223,   291,    45,    45,    45,    73,    73,    45,    45,
      45,    45,   108,   109,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    59,
      59,   378,   374,    53,    59,   353,    29,    53,    53,    45,
      50,    59,   292,    45,   223,    39,    29,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   297,   298,    46,    29,    46,   117,   296,   223,
     223,    46,    52,    46,    46,    46,    46,    46,   223,    46,
      46,   195,   196,    29,    29,    52,    29,    29,   296,    29,
      46,    29,    46,   295,    29,    53,   377,    53,    29,    50,
     288,   291,   223,   290,    39,   223,   127,   298,   338,   339,
      39,    39,    16,    29,    30,    41,    46,    56,    57,   320,
     322,   324,   325,    16,    30,    41,    46,   321,   322,   323,
      53,    39,   223,    29,    30,    46,    52,   128,   131,   340,
     341,   342,   343,   223,   223,    29,    29,    53,    59,    37,
     110,    53,    59,   223,   341,   341,   124,   125,     8,     9,
      45,    73,   123,   128,   129,   130,   132,   133,   324,   325,
     325,   323,    53,   341,   341,   342,   342,   342,   342,   342,
      73,   342,    52,   342,   125,   342,   344,   342,    53,    59,
     342
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
		(yyval.layout)=(yyvsp[(2) - (3)].layout);
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
    {strcpy((yyval.str),"Image");}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 703 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 704 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 705 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 706 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 711 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 717 "screen.yacc"
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

  case 129:

/* Line 1455 of yacc.c  */
#line 747 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 751 "screen.yacc"
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

  case 131:

/* Line 1455 of yacc.c  */
#line 761 "screen.yacc"
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

  case 133:

/* Line 1455 of yacc.c  */
#line 1072 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1078 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1088 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1089 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1092 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1093 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1096 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1099 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1104 "screen.yacc"
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

  case 142:

/* Line 1455 of yacc.c  */
#line 1115 "screen.yacc"
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

  case 143:

/* Line 1455 of yacc.c  */
#line 1129 "screen.yacc"
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

  case 144:

/* Line 1455 of yacc.c  */
#line 1143 "screen.yacc"
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

  case 145:

/* Line 1455 of yacc.c  */
#line 1152 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 146:

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

  case 147:

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

  case 148:

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

  case 149:

/* Line 1455 of yacc.c  */
#line 1195 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1204 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1213 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1216 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1222 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1223 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1224 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1225 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1241 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 165:

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

  case 166:

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

  case 167:

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

  case 168:

/* Line 1455 of yacc.c  */
#line 1300 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1301 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1302 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1303 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1304 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1305 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1306 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1307 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1308 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1309 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1310 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1311 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1312 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1313 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1314 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1315 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1316 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1317 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1319 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1321 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1322 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1323 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1324 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1325 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1326 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1327 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1328 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1329 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1330 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1331 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1332 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1336 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1343 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1344 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1345 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1346 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1347 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1348 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1349 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1350 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1351 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1352 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1353 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1354 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1355 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1356 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1357 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1358 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1359 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1360 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1362 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1363 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1364 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1365 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1366 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1367 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1373 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1374 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1375 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1380 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1384 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1385 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1386 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1387 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1388 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1389 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1390 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1391 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1393 "screen.yacc"
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

  case 238:

/* Line 1455 of yacc.c  */
#line 1428 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1429 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1430 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1431 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1432 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1433 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1434 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1447 "screen.yacc"
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

  case 252:

/* Line 1455 of yacc.c  */
#line 1457 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1463 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1474 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1474 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1479 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1482 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1488 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1491 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1501 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1505 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1509 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1513 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1517 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1523 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1527 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1530 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1534 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1534 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1541 "screen.yacc"
    {colno++;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1542 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1555 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1563 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1565 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1572 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1576 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1580 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1584 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1588 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1592 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1596 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1602 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1606 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1610 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1614 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1618 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1622 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1626 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1629 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1636 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1640 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1645 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1649 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1656 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1657 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1659 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1667 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1670 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1676 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1683 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1684 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1685 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1686 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1692 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1695 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1696 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1699 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1701 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1707 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1709 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1714 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1722 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1725 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1726 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1727 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1728 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1729 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1730 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1732 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1739 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1740 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1743 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1746 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1750 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1751 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1752 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1753 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1754 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1755 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1757 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1762 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1764 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1771 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1771 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1777 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1784 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1787 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1793 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1794 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1795 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1796 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1797 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1798 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1799 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1800 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1801 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1802 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1803 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1804 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1805 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1808 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1815 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1816 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1817 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1825 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1829 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1849 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1859 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1866 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1875 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1878 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1897 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1904 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1912 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1917 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1925 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1929 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1934 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1939 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1944 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1949 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1954 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1963 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1972 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1973 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1982 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1990 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1996 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2002 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2008 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2016 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2021 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2031 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2041 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2047 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2053 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2059 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2069 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 2081 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2089 "screen.yacc"
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

  case 419:

/* Line 1455 of yacc.c  */
#line 2101 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2109 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2110 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2111 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2115 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2116 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2117 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2118 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2119 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2120 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2121 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2124 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2131 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2142 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2146 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2153 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2161 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2167 "screen.yacc"
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

  case 437:

/* Line 1455 of yacc.c  */
#line 2179 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2180 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2186 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2192 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2200 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2208 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2209 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2227 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2229 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2230 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2231 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2232 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2233 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2236 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2237 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2238 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2239 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2240 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2241 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2242 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2243 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2244 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2245 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2246 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2247 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2248 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2249 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2250 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2251 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2257 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2258 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2259 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2260 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2261 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2264 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2268 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1455 of yacc.c  */
#line 6687 "y.tab.c"
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
#line 2280 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




