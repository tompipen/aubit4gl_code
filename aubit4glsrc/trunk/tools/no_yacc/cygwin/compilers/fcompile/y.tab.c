
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
     SERIAL = 367,
     KW_BYTE = 368,
     KW_TEXT = 369,
     VARCHAR = 370,
     SQL_VAR = 371,
     KW_NONSPACE = 372,
     SQLONLY = 373,
     WIDGET = 374,
     CONFIG = 375,
     KW_NL = 376,
     COMPARISON = 377,
     KWOR = 378,
     KWAND = 379,
     KWAND1 = 380,
     KWWHERE = 381,
     KWNOT = 382,
     KWBETWEEN = 383,
     KWIN = 384,
     XVAL = 385,
     KWNULLCHK = 386,
     KWNOTNULLCHK = 387,
     YEAR = 388,
     MONTH = 389,
     DAY = 390,
     HOUR = 391,
     MINUTE = 392,
     SECOND = 393,
     FRACTION = 394,
     LISTBOX = 395,
     BUTTON = 396,
     KW_PANEL = 397,
     DISPLAYONLY = 398,
     ALLOWING = 399,
     KW_WS = 400,
     KW_TAB = 401,
     KW_MASTER_OF = 402,
     KW_BEFORE = 403,
     KW_AFTER = 404,
     KW_EDITADD = 405,
     KW_EDITUPDATE = 406,
     KW_REMOVE = 407,
     KW_OF = 408,
     KW_ADD = 409,
     KW_UPDATE = 410,
     KW_QUERY = 411,
     KW_ON_ENDING = 412,
     KW_ON_BEGINNING = 413,
     KW_CALL = 414,
     KW_BELL = 415,
     KW_ABORT = 416,
     KW_LET = 417,
     KW_EXITNOW = 418,
     KW_NEXTFIELD = 419,
     KW_IF = 420,
     KW_THEN = 421,
     KW_ELSE = 422,
     KW_BEGIN = 423,
     KW_TOTAL = 424,
     KW_RIGHT = 425,
     KW_ZEROFILL = 426,
     KW_USES_EXTENDED = 427,
     SPECIAL_DBNAME = 428,
     KW_ACTION = 429,
     KW_PAGE = 430,
     KW_HBOX = 431,
     KW_VBOX = 432,
     KW_GRID = 433,
     KW_GROUP = 434,
     KW_TABLE = 435,
     KW_FOLDER = 436,
     KW_STYLE = 437,
     KW_LAYOUT = 438,
     KW_HIDDEN = 439,
     KW_AUTOSIZE = 440,
     KW_TEXTEDIT = 441,
     KW_BUTTONEDIT = 442,
     KW_LABEL = 443,
     KW_EDIT = 444,
     KW_DATEEDIT = 445,
     KW_SCROLL = 446,
     KW_IMAGE = 447,
     KW_FONTPITCH = 448,
     KW_FIXED = 449,
     KW_VARIABLE = 450,
     KW_WANTNORETURNS = 451,
     KW_WANTTABS = 452,
     KW_AUTOSCALE = 453,
     KW_PIXELWIDTH = 454,
     KW_PIXELHEIGHT = 455,
     KW_BORDER = 456,
     KW_SCROLLBARS_BOTH = 457,
     KW_SCROLLBARS_V = 458,
     KW_SCROLLBARS_H = 459,
     KW_STRETCH_Y = 460,
     KW_STRETCH_BOTH = 461,
     KW_ITEMS = 462,
     KW_VALUEMAX = 463,
     KW_VALUEMIN = 464,
     KW_PROGRESSBAR = 465,
     KW_COMBOBOX = 466,
     OPTIONS = 467,
     KW_BROWSER = 468,
     KW_VALUECHECKED = 469,
     KW_VALUEUNCHECKED = 470,
     KW_CHECKBOX = 471
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
#define SERIAL 367
#define KW_BYTE 368
#define KW_TEXT 369
#define VARCHAR 370
#define SQL_VAR 371
#define KW_NONSPACE 372
#define SQLONLY 373
#define WIDGET 374
#define CONFIG 375
#define KW_NL 376
#define COMPARISON 377
#define KWOR 378
#define KWAND 379
#define KWAND1 380
#define KWWHERE 381
#define KWNOT 382
#define KWBETWEEN 383
#define KWIN 384
#define XVAL 385
#define KWNULLCHK 386
#define KWNOTNULLCHK 387
#define YEAR 388
#define MONTH 389
#define DAY 390
#define HOUR 391
#define MINUTE 392
#define SECOND 393
#define FRACTION 394
#define LISTBOX 395
#define BUTTON 396
#define KW_PANEL 397
#define DISPLAYONLY 398
#define ALLOWING 399
#define KW_WS 400
#define KW_TAB 401
#define KW_MASTER_OF 402
#define KW_BEFORE 403
#define KW_AFTER 404
#define KW_EDITADD 405
#define KW_EDITUPDATE 406
#define KW_REMOVE 407
#define KW_OF 408
#define KW_ADD 409
#define KW_UPDATE 410
#define KW_QUERY 411
#define KW_ON_ENDING 412
#define KW_ON_BEGINNING 413
#define KW_CALL 414
#define KW_BELL 415
#define KW_ABORT 416
#define KW_LET 417
#define KW_EXITNOW 418
#define KW_NEXTFIELD 419
#define KW_IF 420
#define KW_THEN 421
#define KW_ELSE 422
#define KW_BEGIN 423
#define KW_TOTAL 424
#define KW_RIGHT 425
#define KW_ZEROFILL 426
#define KW_USES_EXTENDED 427
#define SPECIAL_DBNAME 428
#define KW_ACTION 429
#define KW_PAGE 430
#define KW_HBOX 431
#define KW_VBOX 432
#define KW_GRID 433
#define KW_GROUP 434
#define KW_TABLE 435
#define KW_FOLDER 436
#define KW_STYLE 437
#define KW_LAYOUT 438
#define KW_HIDDEN 439
#define KW_AUTOSIZE 440
#define KW_TEXTEDIT 441
#define KW_BUTTONEDIT 442
#define KW_LABEL 443
#define KW_EDIT 444
#define KW_DATEEDIT 445
#define KW_SCROLL 446
#define KW_IMAGE 447
#define KW_FONTPITCH 448
#define KW_FIXED 449
#define KW_VARIABLE 450
#define KW_WANTNORETURNS 451
#define KW_WANTTABS 452
#define KW_AUTOSCALE 453
#define KW_PIXELWIDTH 454
#define KW_PIXELHEIGHT 455
#define KW_BORDER 456
#define KW_SCROLLBARS_BOTH 457
#define KW_SCROLLBARS_V 458
#define KW_SCROLLBARS_H 459
#define KW_STRETCH_Y 460
#define KW_STRETCH_BOTH 461
#define KW_ITEMS 462
#define KW_VALUEMAX 463
#define KW_VALUEMIN 464
#define KW_PROGRESSBAR 465
#define KW_COMBOBOX 466
#define OPTIONS 467
#define KW_BROWSER 468
#define KW_VALUECHECKED 469
#define KW_VALUEUNCHECKED 470
#define KW_CHECKBOX 471




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
#line 652 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 664 "y.tab.c"

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
#define YYLAST   860

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  217
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  160
/* YYNRULES -- Number of rules.  */
#define YYNRULES  471
/* YYNRULES -- Number of states.  */
#define YYNSTATES  778

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   471

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
     215,   216
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
     337,   339,   341,   342,   348,   350,   353,   357,   358,   359,
     366,   367,   371,   377,   381,   383,   384,   390,   394,   397,
     402,   405,   410,   414,   416,   421,   424,   426,   430,   434,
     436,   440,   442,   446,   448,   453,   456,   458,   461,   462,
     465,   467,   471,   473,   478,   481,   486,   490,   494,   498,
     502,   508,   512,   518,   520,   522,   526,   532,   536,   540,
     544,   546,   551,   553,   555,   557,   559,   563,   567,   569,
     571,   573,   575,   577,   579,   581,   584,   587,   589,   591,
     593,   595,   599,   603,   605,   609,   613,   617,   619,   621,
     623,   625,   627,   633,   637,   641,   645,   649,   653,   657,
     661,   665,   667,   669,   671,   673,   676,   678,   680,   682,
     684,   686,   688,   690,   692,   694,   696,   698,   700,   702,
     704,   706,   708,   709,   713,   715,   718,   720,   723,   726,
     728,   729,   739,   752,   754,   756,   757,   760,   761,   763,
     764,   766,   768,   773,   775,   779,   780,   782,   784,   788,
     792,   796,   800,   802,   806,   808,   810,   811,   813,   815,
     818,   820,   822,   824,   825,   830,   832,   834,   836,   838,
     840,   842,   845,   848,   851,   854,   856,   858,   860,   862,
     864,   866,   870,   872,   876,   878,   881,   884,   886,   888,
     890,   892,   894,   896,   900,   904,   906,   908,   910,   912,
     914,   915,   919,   925,   926,   930,   931,   935,   937,   940,
     942,   944,   946,   948,   950,   952,   955,   957,   958,   962,
     964,   966,   968,   970,   972,   974,   976,   978,   981,   982,
     986,   987,   989,   992,   994,   998,  1002,  1006,  1010,  1014,
    1018,  1023,  1027,  1030,  1033,  1035,  1041,  1047,  1050,  1054,
    1056,  1058,  1060,  1062,  1064,  1066,  1070,  1073,  1075,  1078,
    1086,  1088,  1092,  1096,  1098,  1100,  1102,  1108,  1114,  1117,
    1120,  1122,  1124,  1126,  1128,  1130,  1132,  1134,  1140,  1141,
    1144,  1146,  1151,  1154,  1158,  1161,  1165,  1169,  1171,  1174,
    1177,  1181,  1185,  1190,  1192,  1195,  1197,  1200,  1202,  1204,
    1206,  1208,  1210,  1212,  1214,  1216,  1218,  1220,  1222,  1226,
    1230,  1232,  1237,  1238,  1245,  1246,  1248,  1250,  1254,  1256,
    1258,  1262,  1266,  1269,  1272,  1274,  1277,  1281,  1286,  1290,
    1294,  1298,  1302,  1306,  1310,  1314,  1318,  1322,  1327,  1331,
    1334,  1337,  1343,  1349,  1356,  1358,  1360,  1362,  1364,  1366,
    1368,  1370
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     218,     0,    -1,   220,   219,   224,   267,   272,   297,    -1,
      -1,    47,    46,    -1,    21,    34,    -1,    21,   223,    40,
      41,    42,    -1,    21,    34,    40,    41,    42,    -1,    21,
     223,    -1,    30,    -1,    30,    -1,   173,    -1,   173,    38,
     222,    -1,   221,    -1,   221,    38,   222,    -1,   248,    -1,
     247,    -1,   177,   231,   240,   244,    27,    -1,   176,   231,
     240,   244,    27,    -1,   179,   231,   240,   244,    27,    -1,
     181,   231,   240,   229,    27,    -1,   230,    -1,   229,   230,
      -1,   175,   231,   240,   244,    27,    -1,    -1,   222,    -1,
      -1,    -1,    -1,   178,   233,   231,   240,    31,   234,   259,
      32,   235,    27,    -1,    -1,    -1,    -1,   180,   237,   231,
     240,    31,   238,   259,    32,   239,    27,    -1,    -1,    -1,
      52,   241,   243,    53,    -1,   182,    45,    46,    -1,   184,
      -1,   185,    -1,   114,    45,    46,    -1,   174,    45,    30,
      -1,   201,    -1,   242,    -1,   243,   242,    -1,   243,    59,
     242,    -1,    -1,   245,    -1,   246,    -1,   245,   246,    -1,
     225,    -1,   226,    -1,   227,    -1,   228,    -1,   232,    -1,
     236,    -1,   183,   246,   258,    -1,   249,    -1,   248,   249,
      -1,    -1,    24,   250,   252,    -1,    -1,    23,    46,   251,
     252,    -1,    -1,    -1,    -1,   257,   253,   256,    31,   254,
     259,    32,   255,   258,    -1,    -1,   172,    -1,    -1,    25,
      29,    -1,    25,    29,    22,    29,    -1,    -1,    27,    -1,
     261,    -1,   259,   261,    -1,   222,    -1,   260,    -1,   263,
      -1,   146,    -1,    17,    -1,    44,    -1,    46,    -1,   262,
      -1,   145,    -1,   121,    -1,   117,    -1,    16,    -1,   262,
      16,    -1,    -1,    26,   264,   265,    28,    -1,   315,    -1,
      -1,   265,    44,   266,   315,    -1,    -1,    43,   268,   258,
      -1,   269,    -1,   268,   269,    -1,   268,    59,   269,    -1,
     222,   270,    -1,    -1,    45,   271,    -1,   222,    -1,   222,
      37,   222,    -1,   222,    38,   222,    -1,   222,    38,   222,
      37,   222,    -1,   222,    39,   222,    -1,    46,    39,   222,
      -1,    20,   273,   258,    -1,   275,    -1,   273,   275,    -1,
      -1,   189,    -1,   186,    -1,   188,    -1,   190,    -1,   187,
      -1,   192,    -1,   210,    -1,   211,    -1,   216,    -1,   213,
      -1,    -1,   274,   314,   276,   277,    48,    -1,   278,    -1,
     277,   278,    -1,   277,    48,   278,    -1,    -1,    -1,    45,
     279,   284,   281,   280,   291,    -1,    -1,    26,    29,    28,
      -1,    26,    29,    59,    29,    28,    -1,   283,   127,    41,
      -1,   283,    -1,    -1,    61,    73,   222,    39,   222,    -1,
      61,    73,   222,    -1,    61,   317,    -1,    34,    39,   310,
     282,    -1,   143,   282,    -1,   143,   144,    42,   282,    -1,
     222,    39,   222,    -1,   222,    -1,    54,   222,    39,   222,
      -1,    54,   222,    -1,   286,    -1,   285,    59,   286,    -1,
     287,    45,   288,    -1,   314,    -1,   222,    39,   222,    -1,
     222,    -1,   222,    39,   222,    -1,   222,    -1,    54,   222,
      39,   222,    -1,    54,   222,    -1,    50,    -1,    59,    50,
      -1,    -1,    59,   292,    -1,   293,    -1,   292,    59,   293,
      -1,    89,    -1,    90,    45,   295,   336,    -1,    51,   289,
      -1,    49,   285,   290,   289,    -1,    91,    45,    46,    -1,
      92,    45,   294,    -1,   212,    45,   294,    -1,    94,    73,
     222,    -1,    94,    73,   222,    39,   222,    -1,    93,    73,
     222,    -1,    93,    73,   222,    39,   222,    -1,    95,    -1,
      96,    -1,    97,    45,    46,    -1,    98,    45,    52,   318,
      53,    -1,   119,    45,    46,    -1,   120,    45,    46,    -1,
     174,    45,   222,    -1,    99,    -1,    36,    25,    45,    29,
      -1,    36,    -1,   118,    -1,   101,    -1,   100,    -1,   102,
      45,    46,    -1,   103,    45,    46,    -1,   104,    -1,    83,
      -1,   106,    -1,   105,    -1,   171,    -1,   170,    -1,   107,
      -1,   107,   108,    -1,   107,   109,    -1,   184,    -1,   198,
      -1,   196,    -1,   197,    -1,   193,    45,   194,    -1,   193,
      45,   195,    -1,   191,    -1,   192,    45,    46,    -1,   200,
      45,    29,    -1,   199,    45,    29,    -1,   202,    -1,   203,
      -1,   204,    -1,   205,    -1,   206,    -1,   207,    45,    52,
     319,    53,    -1,   208,    45,    29,    -1,   209,    45,    29,
      -1,   214,    45,    46,    -1,   215,    45,    46,    -1,   214,
      45,    29,    -1,   215,    45,    29,    -1,   114,    45,    46,
      -1,   182,    45,    46,    -1,    46,    -1,    29,    -1,   116,
      -1,   296,    -1,   295,   296,    -1,    74,    -1,    75,    -1,
      76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,    29,    -1,    83,    -1,    88,    -1,    82,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    -1,    19,
     298,   258,    -1,   299,    -1,   298,   299,    -1,   300,    -1,
     300,    48,    -1,    62,    46,    -1,   350,    -1,    -1,    24,
      58,   301,   305,    52,   306,    53,   302,   304,    -1,   142,
      52,    29,    59,    29,    53,   110,    52,    29,    59,    29,
      53,    -1,   343,    -1,   366,    -1,    -1,   111,   140,    -1,
      -1,    54,    -1,    -1,    48,    -1,   222,    -1,   222,    26,
      29,    28,    -1,   309,    -1,   306,   307,   309,    -1,    -1,
      59,    -1,   222,    -1,   222,    39,   222,    -1,    34,    39,
     222,    -1,   222,    39,    54,    -1,    34,    39,    54,    -1,
     308,    -1,   308,    60,   308,    -1,   222,    -1,    27,    -1,
      -1,   312,    -1,   313,    -1,   312,   313,    -1,   145,    -1,
     146,    -1,   222,    -1,    -1,   311,   222,   316,   311,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,   324,    -1,    70,   324,    -1,    71,   331,
      -1,    72,   325,    -1,   112,    -1,   113,    -1,   114,    -1,
     115,    -1,   141,    -1,   322,    -1,   318,    59,   322,    -1,
     321,    -1,   319,    59,   321,    -1,    29,    -1,    56,    29,
      -1,    57,    29,    -1,    46,    -1,    30,    -1,    16,    -1,
     320,    -1,    41,    -1,   323,    -1,   323,   110,   323,    -1,
     323,    37,   323,    -1,    46,    -1,    30,    -1,    16,    -1,
     320,    -1,    41,    -1,    -1,    52,    29,    53,    -1,    52,
      29,    59,    29,    53,    -1,    -1,   328,   110,   330,    -1,
      -1,    52,    29,    53,    -1,    29,    -1,   329,   326,    -1,
     133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,
     138,    -1,   139,   335,    -1,   329,    -1,    -1,   332,   110,
     333,    -1,   334,    -1,   334,    -1,   133,    -1,   134,    -1,
     135,    -1,   136,    -1,   137,    -1,   138,    -1,   139,   335,
      -1,    -1,    52,   327,    53,    -1,    -1,   337,    -1,   126,
     338,    -1,   339,    -1,   339,   124,   339,    -1,   339,   123,
     339,    -1,   340,   122,   340,    -1,   340,     8,   340,    -1,
     340,     9,   340,    -1,   340,    73,   340,    -1,   340,   127,
      73,   340,    -1,   340,    45,   340,    -1,   340,   131,    -1,
     340,   132,    -1,   340,    -1,   340,   128,   340,   124,   340,
      -1,   340,   129,    52,   342,    53,    -1,   127,   339,    -1,
      52,   339,    53,    -1,   341,    -1,    29,    -1,    46,    -1,
     130,    -1,    30,    -1,   340,    -1,   342,    59,   340,    -1,
      18,   344,    -1,   345,    -1,   344,   345,    -1,     8,   346,
       9,   303,     8,   346,     9,    -1,   347,    -1,   346,    59,
     347,    -1,   348,    39,   349,    -1,   349,    -1,   222,    -1,
     221,    -1,   148,   360,   153,   364,   358,    -1,   149,   361,
     153,   364,   358,    -1,   158,   367,    -1,   157,   367,    -1,
     354,    -1,   359,    -1,   352,    -1,   355,    -1,   356,    -1,
     367,    -1,   357,    -1,   165,   372,   166,   351,   353,    -1,
      -1,   167,   351,    -1,   161,    -1,   162,   314,    45,   372,
      -1,   164,   314,    -1,   164,    45,   314,    -1,   164,   163,
      -1,   164,    45,   163,    -1,   168,   358,    27,    -1,   351,
      -1,   358,   351,    -1,    91,    46,    -1,    91,   160,    46,
      -1,    91,    83,    46,    -1,    91,   160,    83,    46,    -1,
     362,    -1,   360,   362,    -1,   363,    -1,   361,   363,    -1,
     150,    -1,   151,    -1,   152,    -1,   150,    -1,   154,    -1,
     155,    -1,   156,    -1,   152,    -1,    94,    -1,   151,    -1,
     365,    -1,   364,   307,   365,    -1,   348,    39,   349,    -1,
     349,    -1,   348,   147,   348,   304,    -1,    -1,   159,   222,
      52,   368,   369,    53,    -1,    -1,   370,    -1,   371,    -1,
     370,    59,   371,    -1,   372,    -1,   373,    -1,   372,   124,
     372,    -1,   372,   123,   372,    -1,    57,   372,    -1,    56,
     372,    -1,   375,    -1,   127,   372,    -1,    52,   372,    53,
      -1,   374,    52,   369,    53,    -1,   169,   153,   314,    -1,
     372,   122,   372,    -1,   372,     8,   372,    -1,   372,     9,
     372,    -1,   372,    54,   372,    -1,   372,    56,   372,    -1,
     372,    57,   372,    -1,   372,    55,   372,    -1,   372,    73,
     372,    -1,   372,   127,    73,   372,    -1,   372,    45,   372,
      -1,   372,   131,    -1,   372,   132,    -1,   372,   128,   372,
     124,   372,    -1,   372,   129,    52,   376,    53,    -1,   372,
     127,   129,    52,   376,    53,    -1,   222,    -1,   314,    -1,
      29,    -1,    46,    -1,   130,    -1,    41,    -1,   375,    -1,
     376,    59,   375,    -1
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
     607,   629,   632,   632,   650,   651,   654,   655,   656,   659,
     668,   669,   672,   673,   674,   676,   677,   678,   684,   688,
     688,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   708,   707,   736,   737,   738,   742,   746,   742,
     975,   976,   982,   992,   993,   996,   997,  1000,  1003,  1008,
    1019,  1033,  1047,  1056,  1066,  1075,  1090,  1099,  1108,  1115,
    1117,  1120,  1126,  1127,  1128,  1129,  1132,  1133,  1137,  1138,
    1142,  1142,  1145,  1150,  1172,  1196,  1204,  1205,  1206,  1207,
    1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1223,  1225,  1226,  1227,  1228,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1239,  1246,  1247,  1248,
    1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,
    1259,  1260,  1261,  1262,  1263,  1265,  1266,  1267,  1268,  1269,
    1270,  1276,  1277,  1278,  1282,  1283,  1287,  1288,  1289,  1290,
    1291,  1292,  1293,  1294,  1296,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,  1341,  1342,  1345,  1345,  1347,  1347,  1350,  1360,
    1366,  1366,  1369,  1370,  1371,  1375,  1375,  1377,  1377,  1380,
    1380,  1382,  1385,  1391,  1394,  1398,  1399,  1403,  1407,  1411,
    1415,  1419,  1426,  1426,  1430,  1433,  1437,  1437,  1440,  1440,
    1444,  1445,  1458,  1466,  1466,  1475,  1479,  1483,  1487,  1491,
    1495,  1499,  1505,  1509,  1513,  1517,  1521,  1525,  1529,  1532,
    1539,  1539,  1543,  1543,  1548,  1548,  1548,  1552,  1559,  1560,
    1561,  1562,  1597,  1598,  1601,  1607,  1614,  1615,  1616,  1617,
    1623,  1626,  1627,  1630,  1631,  1638,  1640,  1645,  1653,  1656,
    1657,  1658,  1659,  1660,  1661,  1662,  1668,  1670,  1671,  1674,
    1677,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1693,  1695,
    1702,  1702,  1708,  1714,  1715,  1718,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1739,
    1746,  1747,  1748,  1753,  1756,  1760,  1772,  1775,  1776,  1780,
    1790,  1797,  1806,  1809,  1821,  1824,  1828,  1835,  1843,  1848,
    1856,  1860,  1865,  1870,  1875,  1880,  1885,  1894,  1903,  1904,
    1909,  1912,  1920,  1926,  1932,  1938,  1947,  1952,  1962,  1972,
    1978,  1984,  1990,  2000,  2012,  2020,  2032,  2040,  2041,  2042,
    2046,  2047,  2048,  2049,  2050,  2051,  2052,  2055,  2062,  2073,
    2077,  2084,  2092,  2092,  2110,  2111,  2117,  2123,  2131,  2138,
    2139,  2140,  2158,  2160,  2161,  2162,  2163,  2164,  2167,  2168,
    2169,  2170,  2171,  2172,  2173,  2174,  2175,  2176,  2177,  2178,
    2179,  2180,  2181,  2182,  2185,  2188,  2189,  2190,  2191,  2192,
    2195,  2199
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
  "op_field_tag_type", "field_tag", "$@15", "fpart_list", "fpart", "$@16",
  "$@17", "op_att", "field_datatype_null", "field_datatype", "field_type",
  "lu_ft_eq_c", "lu_ft_eq_c_i", "lu_ft", "lu_fc", "lu_joincol", "lu_join",
  "op_field_desc", "op_desc_list", "desc", "def_val", "colors", "color",
  "op_instruction_section", "instruct_opts", "instruct_op_1",
  "instruct_op", "$@18", "op_ltype", "op_star", "op_semi", "srec_dim",
  "srec_field_list", "op_comma", "field_list_item", "field_list_element",
  "field_name", "op_ws", "ws", "ws_elem", "field_tag_name",
  "field_tag_name_scr", "$@19", "datatype", "incl_list", "items_list",
  "number_value", "items_entry", "incl_entry", "incl_item", "opt_dec_ext",
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
  "evalue", "evalue_list", 0
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
     465,   466,   467,   468,   469,   470,   471
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   217,   218,   219,   219,   220,   220,   220,   220,   221,
     222,   223,   223,   223,   223,   224,   224,   225,   226,   227,
     228,   229,   229,   230,   231,   231,   233,   234,   235,   232,
     237,   238,   239,   236,   240,   241,   240,   242,   242,   242,
     242,   242,   242,   243,   243,   243,   244,   244,   245,   245,
     246,   246,   246,   246,   246,   246,   247,   248,   248,   250,
     249,   251,   249,   253,   254,   255,   252,   256,   256,   257,
     257,   257,   258,   258,   259,   259,   260,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   262,   262,   264,
     263,   265,   266,   265,   267,   267,   268,   268,   268,   269,
     270,   270,   271,   271,   271,   271,   271,   271,   272,   273,
     273,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   276,   275,   277,   277,   277,   279,   280,   278,
     281,   281,   281,   282,   282,   283,   283,   283,   283,   284,
     284,   284,   284,   284,   284,   284,   285,   285,   286,   287,
     288,   288,   289,   289,   289,   289,   290,   290,   291,   291,
     292,   292,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   294,   294,   294,   295,   295,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   297,   297,   298,   298,   299,   299,   300,   300,
     301,   300,   300,   300,   300,   302,   302,   303,   303,   304,
     304,   305,   305,   306,   306,   307,   307,   308,   308,   308,
     308,   308,   309,   309,   310,   310,   311,   311,   312,   312,
     313,   313,   314,   316,   315,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   318,   319,   319,   320,   320,   320,   321,   321,   321,
     321,   321,   322,   322,   322,   323,   323,   323,   323,   323,
     324,   324,   324,   325,   325,   326,   326,   327,   328,   329,
     329,   329,   329,   329,   329,   329,   330,   331,   331,   332,
     333,   334,   334,   334,   334,   334,   334,   334,   335,   335,
     336,   336,   337,   338,   338,   338,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   340,
     340,   340,   340,   341,   342,   342,   343,   344,   344,   345,
     346,   346,   347,   347,   348,   349,   350,   350,   350,   350,
     351,   351,   351,   351,   351,   351,   351,   352,   353,   353,
     354,   355,   356,   356,   356,   356,   357,   358,   358,   359,
     359,   359,   359,   360,   360,   361,   361,   362,   362,   362,
     363,   363,   363,   363,   363,   363,   363,   364,   364,   365,
     365,   366,   368,   367,   369,   369,   370,   370,   371,   372,
     372,   372,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   374,   375,   375,   375,   375,   375,
     376,   376
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
       1,     1,     0,     5,     1,     2,     3,     0,     0,     6,
       0,     3,     5,     3,     1,     0,     5,     3,     2,     4,
       2,     4,     3,     1,     4,     2,     1,     3,     3,     1,
       3,     1,     3,     1,     4,     2,     1,     2,     0,     2,
       1,     3,     1,     4,     2,     4,     3,     3,     3,     3,
       5,     3,     5,     1,     1,     3,     5,     3,     3,     3,
       1,     4,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       1,     1,     5,     3,     3,     3,     3,     3,     3,     3,
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
       3,     3,     2,     2,     1,     2,     3,     4,     3,     3,
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
       0,     0,     0,     0,     0,     0,     4,     0,    59,     0,
      94,    16,    15,    57,     0,    10,    12,    14,     0,    61,
      69,    24,    24,    26,    24,    30,    24,    50,    51,    52,
      53,    54,    55,    72,     0,     0,    58,     7,     6,    69,
       0,    60,    63,    25,    34,    34,    24,    34,    24,    34,
      73,    56,   100,    72,    96,   111,   242,    62,    70,    67,
      35,    46,    46,    34,    46,    34,     0,     0,    99,     0,
      95,    97,   113,   116,   114,   112,   115,   117,   118,   119,
     121,   120,    72,     0,   109,     0,     2,     0,    68,     0,
       0,     0,    47,    48,     0,     0,     0,     0,    24,     0,
      21,     0,   102,   101,    98,   108,   110,   282,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   384,    72,   244,
     246,   253,     0,   249,   254,    71,    64,     0,     0,     0,
      38,    39,    42,    43,     0,    18,    49,    17,    27,    19,
      31,    34,    20,    22,     0,     0,     0,     0,     0,     0,
     376,   377,   250,   248,     0,   417,   418,   419,     0,   413,
     425,   420,   426,   424,   421,   422,   423,     0,   415,     0,
     389,   388,   243,   245,   247,     0,     0,     0,     0,     0,
      36,     0,    44,     0,     0,    46,   107,   103,   104,   106,
     127,     0,   124,     9,   385,     0,   380,     0,   383,   378,
       0,     0,     0,   414,     0,   416,     0,   259,    87,    80,
      89,    81,    82,    86,    85,    84,    79,    76,     0,    77,
      74,    83,    78,    40,    41,    37,    45,     0,     0,     0,
       0,     0,   123,   125,   257,     0,     0,   261,     0,     0,
       0,   430,   265,   427,   265,   432,   260,   431,   276,    65,
      75,    88,    28,    32,    23,   105,     0,     0,   135,   143,
     130,   126,   258,     0,   381,   382,     0,     0,     0,     0,
     266,     0,   400,     0,     0,     0,     0,     0,   407,   392,
     390,   393,   394,   396,   386,   391,   395,   387,   434,   280,
     281,     0,     0,   277,   278,    91,    72,     0,     0,     0,
     145,     0,     0,   140,   134,     0,     0,   128,     0,     0,
       0,   267,   265,   272,   263,     0,   429,   409,     0,     0,
       0,     0,   404,   402,   466,   469,   467,     0,     0,     0,
       0,   468,     0,   282,   465,     0,   439,     0,   444,     0,
     428,   408,     0,   435,   436,   438,    90,    92,   283,   279,
      66,    29,    33,   275,   274,   135,     0,   285,   286,   287,
     288,   289,   290,   320,   320,   337,   323,     0,   295,   296,
     297,   298,   299,   138,   135,     0,   142,     0,   158,     0,
     262,     0,     0,   255,     0,     0,     0,   411,   410,     0,
       0,   405,   403,     0,   443,   442,   445,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   459,   460,     0,   434,   406,   433,     0,   276,
     276,   139,   144,     0,   291,   292,   341,   342,   343,   344,
     345,   346,   348,   293,     0,   339,   329,   330,   331,   332,
     333,   334,   348,   294,     0,   325,   137,   141,   133,   131,
       0,     0,   129,   379,   271,   269,   270,   268,     0,   259,
     264,   273,     0,   412,   401,   446,   448,   450,   451,   458,
     452,   455,   453,   454,   456,   449,   441,   440,     0,     0,
       0,     0,   398,     0,   437,    93,   284,     0,     0,   347,
       0,   335,     0,     0,   328,     0,     0,   182,     0,     0,
     189,   162,     0,     0,     0,     0,     0,   173,   174,     0,
       0,   180,   185,   184,     0,     0,   188,   191,   190,   194,
       0,   183,     0,     0,   193,   192,     0,     0,   197,   203,
       0,     0,   199,   200,   198,     0,     0,   207,   208,   209,
     210,   211,     0,     0,     0,     0,     0,     0,   159,   160,
     256,   251,     0,   457,     0,     0,   470,     0,     0,   397,
     447,   321,     0,   327,     0,   338,   340,   336,   324,     0,
     136,   132,     0,     0,   146,     0,   149,     0,   153,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
     462,     0,   399,     0,   349,   326,     0,   156,     0,     0,
       0,   155,     0,   234,   226,   227,   228,   229,   230,   231,
     232,   233,   237,   235,   238,   239,   240,   241,   236,   350,
     224,   166,   222,   221,   223,   167,   171,   169,   175,     0,
     186,   187,   219,   177,   178,   179,   220,   204,   201,   202,
     206,   205,     0,   213,   214,   168,   217,   215,   218,   216,
     161,     0,   463,   471,   322,   181,   157,   147,   165,   151,
     148,     0,   152,     0,   225,   163,   351,     0,     0,   317,
     304,   316,   319,   315,     0,     0,     0,   318,   300,   312,
     309,   308,   311,   307,     0,   310,   302,   252,     0,   154,
     370,   373,   371,     0,     0,   372,   352,   353,   364,   369,
     172,   170,   305,   306,   176,     0,     0,     0,   212,     0,
     150,     0,   367,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   362,   363,   301,   314,   313,   303,   368,
     355,   354,   357,   358,   361,   359,   356,     0,     0,     0,
     360,     0,   374,     0,   365,   366,     0,   375
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,     3,   204,   343,     8,    20,    37,    38,
      39,    40,   109,   110,    54,    41,    56,   193,   307,    42,
      58,   194,   308,    71,   100,   143,   144,   101,   102,   103,
      21,    22,    23,    30,    49,    51,    69,   186,   306,    99,
      52,    61,   228,   229,   230,   231,   232,   258,   301,   429,
      45,    63,    64,    78,   113,    66,    92,    93,    94,   158,
     201,   202,   241,   388,   317,   313,   314,   270,   583,   584,
     585,   690,   589,   629,   462,   558,   559,   655,   649,   650,
      96,   128,   129,   130,   210,   469,   273,   257,   248,   322,
     287,   323,   324,   365,   302,   303,   304,   344,   305,   430,
     383,   706,   714,   707,   716,   708,   709,   434,   453,   504,
     574,   454,   455,   578,   443,   444,   575,   445,   499,   695,
     696,   726,   727,   728,   729,   773,   131,   160,   161,   205,
     206,   207,   208,   133,   288,   289,   569,   290,   291,   292,
     293,   294,   295,   168,   177,   169,   178,   252,   253,   134,
     296,   298,   352,   353,   354,   355,   346,   347,   348,   567
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -648
static const yytype_int16 yypact[] =
{
      28,   -18,    81,   103,  -648,    20,   126,   131,   151,  -648,
     128,   -15,   178,   218,   218,   211,  -648,   191,  -648,   388,
     213,  -648,    97,  -648,   223,  -648,  -648,  -648,   236,  -648,
     233,   218,   218,  -648,   218,  -648,   218,  -648,  -648,  -648,
    -648,  -648,  -648,   261,   218,   270,  -648,  -648,  -648,   233,
     275,  -648,  -648,  -648,   247,   247,   218,   247,   218,   247,
    -648,  -648,   274,    41,  -648,   623,   294,  -648,   318,   170,
    -648,   388,   388,   247,   388,   247,   185,   166,  -648,   218,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,    -3,   218,  -648,   199,  -648,   334,  -648,   349,
     225,   360,   388,  -648,   363,   367,   373,   372,   218,   -16,
    -648,   365,   358,  -648,  -648,  -648,  -648,  -648,  -648,   398,
     350,   368,   364,   268,   407,   262,   262,  -648,   152,  -648,
     377,  -648,   285,  -648,  -648,  -648,  -648,   399,   402,   404,
    -648,  -648,  -648,  -648,    -7,  -648,  -648,  -648,  -648,  -648,
    -648,   247,  -648,  -648,   218,   218,   218,   218,   405,   422,
     398,  -648,  -648,  -648,   429,  -648,  -648,  -648,   134,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,   362,  -648,   218,
    -648,  -648,  -648,  -648,  -648,   218,   456,   408,   423,   414,
    -648,   225,  -648,   456,   456,   388,  -648,  -648,   427,  -648,
    -648,     3,  -648,   426,  -648,     4,  -648,   428,  -648,  -648,
     218,   409,   422,  -648,   422,  -648,   418,   413,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   342,  -648,
    -648,   461,  -648,  -648,  -648,  -648,  -648,   345,   425,   453,
     218,    45,   405,  -648,   430,   422,   455,   463,   441,   465,
     459,  -648,   445,  -648,   445,  -648,  -648,  -648,    59,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,   464,   218,   -47,   467,
     479,  -648,  -648,   501,  -648,  -648,   481,   192,   471,   455,
    -648,   -41,  -648,   218,    -1,   216,   -51,   422,  -648,  -648,
    -648,  -648,  -648,  -648,   -51,  -648,  -648,   -51,   216,  -648,
    -648,   172,   218,    59,  -648,  -648,   261,   500,   502,   214,
     487,   676,   486,  -648,   406,   218,   509,  -648,   422,   512,
     504,   506,   150,   488,  -648,   431,  -648,  -648,   503,    15,
     505,     0,  -648,  -648,  -648,  -648,  -648,   216,   216,   216,
     216,  -648,   394,   508,  -648,    29,  -648,   524,  -648,    74,
    -648,  -648,   525,   493,  -648,   499,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,   518,   218,  -648,  -648,  -648,
    -648,  -648,  -648,   530,   530,   534,   685,   218,  -648,  -648,
    -648,  -648,  -648,  -648,   518,   542,  -648,    50,   526,    13,
    -648,    86,    94,   473,   192,   192,   535,  -648,  -648,   540,
     216,  -648,  -648,   466,   499,   499,   499,   218,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   -38,
     216,   544,  -648,  -648,   -51,   216,  -648,  -648,   216,    59,
      59,  -648,  -648,   563,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,   551,  -648,   495,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,   551,  -648,   510,   559,   573,  -648,  -648,  -648,
     585,   231,  -648,  -648,  -648,  -648,  -648,  -648,   478,   413,
    -648,  -648,   595,  -648,   499,  -648,  -648,   604,   604,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   216,   577,
     591,    24,   468,   579,  -648,  -648,  -648,   196,   605,  -648,
     534,  -648,   685,   608,  -648,   218,   614,   615,   218,   117,
    -648,  -648,   588,   598,   599,   578,   580,  -648,  -648,   607,
     611,  -648,  -648,  -648,   617,   618,  -648,  -648,  -648,   257,
     629,  -648,   630,   631,  -648,  -648,   634,   635,  -648,  -648,
     636,   637,  -648,  -648,  -648,   638,   656,  -648,  -648,  -648,
    -648,  -648,   657,   658,   659,   662,   663,   664,   651,  -648,
    -648,  -648,   652,   499,    24,   216,  -648,   200,   -51,  -648,
    -648,  -648,   625,  -648,   668,  -648,  -648,  -648,  -648,   671,
    -648,  -648,   667,   184,  -648,   672,  -648,   218,   686,  -648,
     677,   670,   -12,   218,   218,   683,   678,   688,   691,  -648,
    -648,   704,   720,   722,   218,   723,   724,   113,   628,   742,
     725,   750,   753,   -12,    30,    93,   231,   754,   207,   499,
    -648,    24,  -648,   731,  -648,  -648,   756,  -648,    37,   117,
     218,   747,   218,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   612,
    -648,  -648,  -648,  -648,  -648,  -648,   748,   760,  -648,   609,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,   751,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,   740,  -648,  -648,  -648,  -648,  -648,  -648,  -648,   761,
    -648,   218,  -648,   246,  -648,  -648,  -648,   218,   218,  -648,
    -648,  -648,  -648,  -648,   766,   772,   210,  -648,  -648,    -5,
    -648,  -648,  -648,  -648,   244,  -648,  -648,  -648,   218,  -648,
    -648,  -648,  -648,   246,   246,  -648,  -648,   260,   403,  -648,
    -648,  -648,  -648,  -648,  -648,   609,   609,   609,  -648,   751,
    -648,   749,  -648,   246,   246,    60,    60,    60,    60,    60,
     732,    60,   752,  -648,  -648,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,  -648,  -648,  -648,  -648,    60,   682,    60,
    -648,    60,  -648,   253,  -648,  -648,    60,  -648
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -648,  -648,  -648,  -648,   813,   -13,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,   707,   259,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,  -648,   424,  -648,   -97,  -648,   -46,  -648,     1,
    -648,  -648,   803,  -648,  -648,   777,  -648,  -648,  -648,  -648,
    -648,   -59,   161,  -648,   -17,  -648,  -648,  -648,  -648,  -648,
    -648,  -648,   139,  -648,  -648,  -648,  -648,  -648,   735,  -648,
    -648,  -165,  -648,  -648,  -648,  -272,  -648,  -648,  -648,   201,
    -648,  -648,   202,  -648,  -648,  -648,   212,   217,  -648,   183,
    -648,  -648,   709,  -648,  -648,  -648,  -648,   366,  -648,  -648,
     516,   446,   448,  -648,   410,  -648,   541,   -91,   416,  -648,
    -648,  -648,  -648,  -647,   104,   111,  -367,   474,  -648,  -648,
    -648,  -648,   347,  -648,  -648,  -648,  -648,   351,   395,  -648,
    -648,  -648,  -493,    27,  -648,  -648,  -648,  -648,   690,   536,
     610,   -89,    65,  -648,  -287,  -648,  -648,  -648,  -648,  -648,
    -648,  -213,  -648,  -648,  -648,   684,   679,   639,   570,  -648,
     267,  -648,   433,  -648,   432,  -282,  -648,  -648,  -476,   295
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -465
static const yytype_int16 yytable[] =
{
      26,    27,   118,   345,    80,   327,   132,   351,    17,    18,
     351,   152,     4,   244,   311,   566,     5,   652,    53,    53,
      43,    53,   463,    53,    60,   715,   104,  -111,   106,    25,
      25,    62,   736,   115,   653,   488,   243,   408,   409,   132,
     281,   297,   328,    53,   331,    53,   190,   192,   200,     1,
      62,   242,   191,   334,    25,   403,   404,   405,   406,   676,
      12,   398,   351,   245,   112,   335,    62,    25,    60,   182,
     336,    25,   245,   349,   410,    25,   677,   271,   459,   266,
     117,     9,   127,   411,   412,   413,   414,   686,   566,   720,
     721,   489,   715,   431,   236,    53,   217,   312,   399,   267,
      79,   426,   415,   146,   654,   737,   722,   137,   179,   460,
     282,   283,   457,   284,   285,   127,    25,   286,   474,   329,
      17,    18,   678,   250,    25,   250,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   492,   490,   679,
     464,   196,   197,   198,   199,   683,   127,    25,   466,   239,
      10,   416,   417,   418,   341,     6,   419,   420,   421,   108,
     422,   423,   332,   401,    13,   281,   216,   138,    19,    14,
     119,   587,   127,   227,    16,   139,   120,   140,   141,    60,
     227,   227,    25,    82,    83,    84,    85,    86,   268,    87,
     725,    15,   330,   333,   142,   424,    25,   247,   250,   127,
     356,   127,    81,   393,   299,   300,   563,    88,    89,   280,
      90,   260,   111,    91,   121,   227,   357,   119,   114,    24,
     260,   260,    25,   120,   227,   227,   320,   265,   269,    25,
     741,   742,   127,   179,   627,   282,   283,    29,   284,   285,
     402,   363,   286,   628,    25,   334,    25,   360,    25,   571,
     760,   761,    28,   620,   310,   572,    44,   335,    50,   621,
     682,   121,   336,   734,   321,    47,   621,   507,   337,   735,
     117,   117,   338,   339,   127,   720,   721,   251,    48,   251,
     508,   622,   509,   619,   165,   166,   167,   212,    60,   358,
      65,    55,   722,    57,   122,    59,   364,   738,   723,    70,
     123,   124,   386,   739,    68,   127,   775,   668,   669,   125,
     126,   275,   776,    95,   510,    73,   476,    75,   117,    77,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   137,
      97,   122,    98,   340,   326,   530,   341,   123,   124,   531,
     532,   533,   251,   432,   237,   238,   125,   126,   218,   219,
     108,   218,   219,   135,   456,   599,   600,   151,   220,   756,
     757,   220,    25,   724,   259,    25,   725,   262,   465,   467,
     136,   321,   321,   743,   744,   342,   221,   145,   222,   221,
     147,   222,   180,   181,   117,   155,   156,   157,   148,   138,
     149,   534,   535,   150,   154,   536,   159,   139,   162,   140,
     141,   745,   746,   537,   163,   538,   164,   586,   165,   166,
     167,   179,   539,   540,   541,   184,   142,   542,   543,   544,
     545,   546,   185,   547,   548,   549,   550,   551,   552,   553,
     554,   218,   219,   555,   187,   556,   557,   188,   747,   189,
     200,   220,   203,   234,   233,    25,   170,   263,   211,   223,
     235,   256,   223,   224,   240,   -10,   224,   246,   249,   221,
     255,   222,   218,   219,   408,   409,   748,   261,   117,    72,
     264,    74,   220,    76,   272,     4,    25,   225,   226,   276,
     225,   226,   580,   277,   278,   117,   588,   105,   279,   107,
     221,   170,   222,   309,   280,   316,   315,   408,   409,   318,
     319,   410,   171,   172,   173,   214,   174,   175,   176,   475,
     411,   412,   413,   414,   325,   749,   366,   361,   384,   362,
     750,   751,   752,   385,   753,   754,   281,   586,   387,   415,
     390,   396,   223,   391,   410,   392,   224,   407,   395,   397,
     400,   117,   428,   411,   412,   413,   414,   171,   172,   173,
    -464,   174,   175,   176,    31,    32,    33,    34,    35,    36,
     225,   226,   415,   223,   631,   195,   425,   224,   427,   311,
     656,   657,   433,   458,   468,   461,   473,   472,   416,   417,
     418,   665,   497,   419,   420,   421,   491,   422,   423,   408,
     409,   225,   226,   498,   179,   500,   282,   283,   117,   284,
     285,   503,   505,   286,   506,   117,   588,   689,   560,   692,
     502,   416,   417,   418,   562,   699,   419,   420,   421,   564,
     422,   423,   570,   590,   573,   568,   410,   579,   700,   701,
     582,   633,   581,   591,   592,   411,   412,   413,   414,   410,
     702,   593,   595,   594,   623,   703,   596,   670,   411,   412,
     413,   414,   597,   598,   415,   704,   705,   436,   437,   438,
     439,   440,   441,   442,   601,   602,   603,   415,   719,   604,
     605,   606,   607,   608,   730,   731,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   609,   610,   611,   612,   740,   633,   613,   614,   615,
     616,   617,   626,   416,   417,   565,   651,   630,   419,   420,
     421,   624,   422,   423,   625,   632,   416,   417,   418,   658,
     659,   419,   420,   421,   660,   422,   423,   661,   693,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     662,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   663,   710,   664,   666,
     667,   671,   762,   763,   764,   765,   766,   672,   768,   673,
     700,   711,   674,   681,   684,   685,   691,   697,   378,   379,
     380,   381,   712,   717,   770,   732,   772,   713,   774,   698,
     718,   733,   759,   777,   769,   767,   771,   704,   705,    82,
      83,    84,    85,    86,     7,    87,   153,   382,   446,   447,
     448,   449,   450,   451,   452,    46,    67,   116,   680,   687,
     675,   688,   694,    88,    89,   561,    90,   183,   394,    91,
     496,   471,   470,   758,   359,   495,   755,   501,   435,   577,
     209,   576,   213,   254,   389,   274,   215,   350,   493,   618,
     494
};

static const yytype_uint16 yycheck[] =
{
      13,    14,    93,   285,    63,    46,    95,   294,    23,    24,
     297,    27,    30,     9,    61,   491,    34,    29,    31,    32,
      19,    34,     9,    36,    27,   672,    72,    30,    74,    30,
      30,    44,    37,    92,    46,    73,   201,     8,     9,   128,
      91,   254,    83,    56,    45,    58,    53,   144,    45,    21,
      63,    48,    59,    29,    30,   337,   338,   339,   340,    29,
      40,    46,   349,    59,    77,    41,    79,    30,    27,   128,
      46,    30,    59,   286,    45,    30,    46,   242,    28,    34,
      93,     0,    95,    54,    55,    56,    57,    50,   564,    29,
      30,   129,   739,   365,   191,   108,   185,   144,    83,    54,
      59,    27,    73,   102,   116,   110,    46,   114,   159,    59,
     161,   162,   384,   164,   165,   128,    30,   168,   400,   160,
      23,    24,    29,   212,    30,   214,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   424,   420,    46,
      54,   154,   155,   156,   157,   621,   159,    30,    54,   195,
      47,   122,   123,   124,   130,   173,   127,   128,   129,   175,
     131,   132,   163,   163,    38,    91,   179,   174,   183,    38,
      18,    54,   185,   186,    46,   182,    24,   184,   185,    27,
     193,   194,    30,   186,   187,   188,   189,   190,   143,   192,
     130,    40,   283,   284,   201,   166,    30,   210,   287,   212,
      28,   214,    63,    53,   145,   146,   488,   210,   211,    59,
     213,   228,    46,   216,    62,   228,    44,    18,    79,    41,
     237,   238,    30,    24,   237,   238,    34,   240,   241,    30,
     723,   724,   245,   159,    50,   161,   162,    46,   164,   165,
     331,    27,   168,    59,    30,    29,    30,   306,    30,    53,
     743,   744,    41,    53,   267,    59,    43,    41,    25,    59,
      53,    62,    46,    53,   277,    42,    59,    36,    52,    59,
     283,   284,    56,    57,   287,    29,    30,   212,    42,   214,
      49,   568,    51,   565,   150,   151,   152,   153,    27,   302,
      20,    32,    46,    34,   142,    36,   309,    53,    52,    52,
     148,   149,   315,    59,    29,   318,    53,   194,   195,   157,
     158,   246,    59,    19,    83,    56,   407,    58,   331,    45,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   114,
      22,   142,   172,   127,   279,   114,   130,   148,   149,   118,
     119,   120,   287,   366,   193,   194,   157,   158,    16,    17,
     175,    16,    17,    29,   377,   108,   109,   108,    26,   736,
     737,    26,    30,   127,    32,    30,   130,    32,   391,   392,
      31,   394,   395,   123,   124,   169,    44,    27,    46,    44,
      27,    46,   125,   126,   407,    37,    38,    39,    31,   174,
      27,   170,   171,    31,    39,   174,     8,   182,    58,   184,
     185,     8,     9,   182,    46,   184,    52,   508,   150,   151,
     152,   159,   191,   192,   193,    48,   201,   196,   197,   198,
     199,   200,   147,   202,   203,   204,   205,   206,   207,   208,
     209,    16,    17,   212,    45,   214,   215,    45,    45,    45,
      45,    26,    30,    30,    46,    30,    94,    32,    29,   117,
      46,    48,   117,   121,    37,    39,   121,    39,    59,    44,
      52,    46,    16,    17,     8,     9,    73,    16,   491,    55,
      27,    57,    26,    59,    54,    30,    30,   145,   146,    26,
     145,   146,   505,    52,    29,   508,   509,    73,    39,    75,
      44,    94,    46,    39,    59,    26,    39,     8,     9,     8,
      29,    45,   150,   151,   152,   153,   154,   155,   156,    53,
      54,    55,    56,    57,    53,   122,    39,    27,    42,    27,
     127,   128,   129,   127,   131,   132,    91,   628,    29,    73,
      28,   110,   117,    39,    45,    39,   121,   153,    60,    46,
      45,   564,    59,    54,    55,    56,    57,   150,   151,   152,
      52,   154,   155,   156,   176,   177,   178,   179,   180,   181,
     145,   146,    73,   117,   587,   151,    52,   121,    53,    61,
     593,   594,    52,    41,   111,    59,    46,    52,   122,   123,
     124,   604,    29,   127,   128,   129,    52,   131,   132,     8,
       9,   145,   146,    52,   159,   110,   161,   162,   621,   164,
     165,    52,    39,   168,    29,   628,   629,   630,   140,   632,
     110,   122,   123,   124,    29,    16,   127,   128,   129,    52,
     131,   132,    53,    45,    29,   167,    45,    29,    29,    30,
      25,    29,    28,    45,    45,    54,    55,    56,    57,    45,
      41,    73,    45,    73,    29,    46,    45,    29,    54,    55,
      56,    57,    45,    45,    73,    56,    57,   133,   134,   135,
     136,   137,   138,   139,    45,    45,    45,    73,   691,    45,
      45,    45,    45,    45,   697,   698,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    45,    45,    45,    45,   718,    29,    45,    45,    45,
      59,    59,    45,   122,   123,   124,    46,    45,   127,   128,
     129,    53,   131,   132,    53,    39,   122,   123,   124,    46,
      52,   127,   128,   129,    46,   131,   132,    46,   126,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      46,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    46,    16,    46,    46,
      46,    29,   745,   746,   747,   748,   749,    52,   751,    29,
      29,    30,    29,    29,    53,    29,    39,    39,   112,   113,
     114,   115,    41,    53,   767,    29,   769,    46,   771,    39,
      39,    29,    53,   776,    52,    73,   124,    56,    57,   186,
     187,   188,   189,   190,     1,   192,   109,   141,   133,   134,
     135,   136,   137,   138,   139,    22,    49,    92,   616,   628,
     613,   629,   649,   210,   211,   469,   213,   128,   322,   216,
     430,   395,   394,   739,   303,   429,   735,   452,   374,   502,
     160,   500,   168,   214,   318,   245,   177,   287,   425,   564,
     428
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   218,   220,    30,    34,   173,   221,   223,     0,
      47,   219,    40,    38,    38,    40,    46,    23,    24,   183,
     224,   247,   248,   249,    41,    30,   222,   222,    41,    46,
     250,   176,   177,   178,   179,   180,   181,   225,   226,   227,
     228,   232,   236,   246,    43,   267,   249,    42,    42,   251,
      25,   252,   257,   222,   231,   231,   233,   231,   237,   231,
      27,   258,   222,   268,   269,    20,   272,   252,    29,   253,
      52,   240,   240,   231,   240,   231,   240,    45,   270,    59,
     258,   269,   186,   187,   188,   189,   190,   192,   210,   211,
     213,   216,   273,   274,   275,    19,   297,    22,   172,   256,
     241,   244,   245,   246,   244,   240,   244,   240,   175,   229,
     230,    46,   222,   271,   269,   258,   275,   222,   314,    18,
      24,    62,   142,   148,   149,   157,   158,   222,   298,   299,
     300,   343,   348,   350,   366,    29,    31,   114,   174,   182,
     184,   185,   201,   242,   243,    27,   246,    27,    31,    27,
      31,   231,    27,   230,    39,    37,    38,    39,   276,     8,
     344,   345,    58,    46,    52,   150,   151,   152,   360,   362,
      94,   150,   151,   152,   154,   155,   156,   361,   363,   159,
     367,   367,   258,   299,    48,   147,   254,    45,    45,    45,
      53,    59,   242,   234,   238,   240,   222,   222,   222,   222,
      45,   277,   278,    30,   221,   346,   347,   348,   349,   345,
     301,    29,   153,   362,   153,   363,   222,   348,    16,    17,
      26,    44,    46,   117,   121,   145,   146,   222,   259,   260,
     261,   262,   263,    46,    30,    46,   242,   259,   259,   244,
      37,   279,    48,   278,     9,    59,    39,   222,   305,    59,
     348,   349,   364,   365,   364,    52,    48,   304,   264,    32,
     261,    16,    32,    32,    27,   222,    34,    54,   143,   222,
     284,   278,    54,   303,   347,   349,    26,    52,    29,    39,
      59,    91,   161,   162,   164,   165,   168,   307,   351,   352,
     354,   355,   356,   357,   358,   359,   367,   358,   368,   145,
     146,   265,   311,   312,   313,   315,   255,   235,   239,    39,
     222,    61,   144,   282,   283,    39,    26,   281,     8,    29,
      34,   222,   306,   308,   309,    53,   349,    46,    83,   160,
     314,    45,   163,   314,    29,    41,    46,    52,    56,    57,
     127,   130,   169,   222,   314,   372,   373,   374,   375,   358,
     365,   351,   369,   370,   371,   372,    28,    44,   222,   313,
     258,    27,    27,    27,   222,   310,    39,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   112,   113,
     114,   115,   141,   317,    42,   127,   222,    29,   280,   346,
      28,    39,    39,    53,   307,    60,   110,    46,    46,    83,
      45,   163,   314,   372,   372,   372,   372,   153,     8,     9,
      45,    54,    55,    56,    57,    73,   122,   123,   124,   127,
     128,   129,   131,   132,   166,    52,    27,    53,    59,   266,
     316,   282,   222,    52,   324,   324,   133,   134,   135,   136,
     137,   138,   139,   331,   332,   334,   133,   134,   135,   136,
     137,   138,   139,   325,   328,   329,   222,   282,    41,    28,
      59,    59,   291,     9,    54,   222,    54,   222,   111,   302,
     309,   308,    52,    46,   372,    53,   314,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,    73,   129,
     372,    52,   351,   369,   371,   315,   311,    29,    52,   335,
     110,   335,   110,    52,   326,    39,    29,    36,    49,    51,
      83,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     114,   118,   119,   120,   170,   171,   174,   182,   184,   191,
     192,   193,   196,   197,   198,   199,   200,   202,   203,   204,
     205,   206,   207,   208,   209,   212,   214,   215,   292,   293,
     140,   304,    29,   372,    52,   124,   375,   376,   167,   353,
      53,    53,    59,    29,   327,   333,   334,   329,   330,    29,
     222,    28,    25,   285,   286,   287,   314,    54,   222,   289,
      45,    45,    45,    73,    73,    45,    45,    45,    45,   108,
     109,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    59,    59,   376,   372,
      53,    59,   351,    29,    53,    53,    45,    50,    59,   290,
      45,   222,    39,    29,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   295,
     296,    46,    29,    46,   116,   294,   222,   222,    46,    52,
      46,    46,    46,    46,    46,   222,    46,    46,   194,   195,
      29,    29,    52,    29,    29,   294,    29,    46,    29,    46,
     293,    29,    53,   375,    53,    29,    50,   286,   289,   222,
     288,    39,   222,   126,   296,   336,   337,    39,    39,    16,
      29,    30,    41,    46,    56,    57,   318,   320,   322,   323,
      16,    30,    41,    46,   319,   320,   321,    53,    39,   222,
      29,    30,    46,    52,   127,   130,   338,   339,   340,   341,
     222,   222,    29,    29,    53,    59,    37,   110,    53,    59,
     222,   339,   339,   123,   124,     8,     9,    45,    73,   122,
     127,   128,   129,   131,   132,   322,   323,   323,   321,    53,
     339,   339,   340,   340,   340,   340,   340,    73,   340,    52,
     340,   124,   340,   342,   340,    53,    59,   340
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
}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 629 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 632 "screen.yacc"
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
#line 643 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 659 "screen.yacc"
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
#line 668 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 669 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 672 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 673 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 675 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 676 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 677 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 693 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 694 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 695 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 696 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 697 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 698 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 699 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 700 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 701 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 702 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 703 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 708 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 714 "screen.yacc"
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

  case 127:

/* Line 1455 of yacc.c  */
#line 742 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 746 "screen.yacc"
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

  case 129:

/* Line 1455 of yacc.c  */
#line 756 "screen.yacc"
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


	if ((fld->datatype&256)==256) {
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
						A4GL_add_bool_attr(fld,FA_B_REQUIRED);
						break;
				}
			}
	}
}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 976 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 982 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 992 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 993 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 996 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 997 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1000 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1003 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1008 "screen.yacc"
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

  case 140:

/* Line 1455 of yacc.c  */
#line 1019 "screen.yacc"
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

  case 141:

/* Line 1455 of yacc.c  */
#line 1033 "screen.yacc"
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

  case 142:

/* Line 1455 of yacc.c  */
#line 1047 "screen.yacc"
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

  case 143:

/* Line 1455 of yacc.c  */
#line 1056 "screen.yacc"
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

  case 144:

/* Line 1455 of yacc.c  */
#line 1066 "screen.yacc"
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

  case 145:

/* Line 1455 of yacc.c  */
#line 1075 "screen.yacc"
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

  case 146:

/* Line 1455 of yacc.c  */
#line 1090 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1099 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1108 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1117 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1120 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1126 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1127 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1128 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1129 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1145 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1150 "screen.yacc"
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

  case 164:

/* Line 1455 of yacc.c  */
#line 1172 "screen.yacc"
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

  case 165:

/* Line 1455 of yacc.c  */
#line 1196 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1204 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1205 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1206 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1207 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1208 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1209 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1210 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1211 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1212 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1213 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1214 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1215 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1216 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1217 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1218 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1219 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1220 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1221 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1223 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1225 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1226 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1227 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1228 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1229 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1230 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1231 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1232 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1233 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1234 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1235 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1239 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1246 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1247 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1248 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1249 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1250 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1251 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1252 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1253 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1254 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1255 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1256 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1257 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1258 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1259 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1260 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1261 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1262 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1263 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1265 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1266 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1267 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1268 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1269 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1270 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1276 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1277 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1278 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1283 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1287 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1288 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1289 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1290 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1291 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1292 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1293 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1294 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1296 "screen.yacc"
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

  case 235:

/* Line 1455 of yacc.c  */
#line 1331 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1332 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1333 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1334 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1335 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1336 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1337 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1350 "screen.yacc"
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

  case 249:

/* Line 1455 of yacc.c  */
#line 1360 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1366 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1377 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1377 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1382 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1385 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1391 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1394 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1404 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1408 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1412 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1416 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1420 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1426 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1430 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1433 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1437 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1437 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1444 "screen.yacc"
    {colno++;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1445 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1458 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1466 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1468 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1475 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1479 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1483 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1487 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1491 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1495 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1499 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1505 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1509 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1513 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1517 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1521 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1525 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1529 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1532 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1539 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1543 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1548 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1552 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1559 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1560 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1562 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1598 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1601 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1607 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1614 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1615 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1616 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1617 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1623 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1626 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1627 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1630 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1632 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1638 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1640 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1645 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1653 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1656 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1657 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1658 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1659 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1660 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1661 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1663 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1670 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1671 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1674 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1677 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1681 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1682 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1683 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1684 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1685 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1686 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1688 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1693 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1695 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1702 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1702 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1708 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1715 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1718 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1724 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1725 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1726 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1727 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1728 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1729 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1730 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1731 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1732 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1733 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1734 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1735 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1736 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1739 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1746 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1747 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1748 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 1756 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1760 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1780 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1790 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1797 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1806 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1809 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1828 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1835 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1843 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1848 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1856 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1860 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1865 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1870 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1875 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1880 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1885 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1894 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1903 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1904 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1913 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1921 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1927 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1933 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1939 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1947 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1952 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1962 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1972 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1978 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1984 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1990 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2000 "screen.yacc"
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

  case 414:

/* Line 1455 of yacc.c  */
#line 2012 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2020 "screen.yacc"
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

  case 416:

/* Line 1455 of yacc.c  */
#line 2032 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2040 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2041 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2042 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2046 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2047 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2048 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2049 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2050 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2051 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2052 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2055 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2062 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2073 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2077 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2084 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2092 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2098 "screen.yacc"
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

  case 434:

/* Line 1455 of yacc.c  */
#line 2110 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2111 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2117 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2123 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2131 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2139 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2140 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2158 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2160 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2161 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2162 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2163 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2164 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2167 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2168 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2169 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2170 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2171 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2172 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2173 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2174 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2175 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2176 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2177 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2178 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2179 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2180 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2181 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2182 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2188 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2189 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2190 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2191 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2192 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2195 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2199 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1455 of yacc.c  */
#line 6579 "y.tab.c"
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
#line 2211 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




