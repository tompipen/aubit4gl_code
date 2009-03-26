
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
     KW_AUTOSIZE = 439,
     KW_TEXTEDIT = 440,
     KW_BUTTONEDIT = 441,
     KW_LABEL = 442,
     KW_EDIT = 443,
     KW_DATEEDIT = 444,
     KW_SCROLL = 445,
     KW_IMAGE = 446,
     KW_FONTPITCH = 447,
     KW_FIXED = 448,
     KW_VARIABLE = 449,
     KW_WANTNORETURNS = 450,
     KW_WANTTABS = 451,
     KW_AUTOSCALE = 452,
     KW_PIXELWIDTH = 453,
     KW_PIXELHEIGHT = 454,
     KW_SCROLLBARS_BOTH = 455,
     KW_SCROLLBARS_V = 456,
     KW_SCROLLBARS_H = 457,
     KW_STRETCH_Y = 458,
     KW_STRETCH_BOTH = 459,
     KW_ITEMS = 460,
     KW_VALUEMAX = 461,
     KW_VALUEMIN = 462,
     KW_PROGRESSBAR = 463,
     KW_COMBOBOX = 464,
     OPTIONS = 465,
     KW_BROWSER = 466,
     KW_VALUECHECKED = 467,
     KW_VALUEUNCHECKED = 468,
     KW_CHECKBOX = 469
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
#define KW_AUTOSIZE 439
#define KW_TEXTEDIT 440
#define KW_BUTTONEDIT 441
#define KW_LABEL 442
#define KW_EDIT 443
#define KW_DATEEDIT 444
#define KW_SCROLL 445
#define KW_IMAGE 446
#define KW_FONTPITCH 447
#define KW_FIXED 448
#define KW_VARIABLE 449
#define KW_WANTNORETURNS 450
#define KW_WANTTABS 451
#define KW_AUTOSCALE 452
#define KW_PIXELWIDTH 453
#define KW_PIXELHEIGHT 454
#define KW_SCROLLBARS_BOTH 455
#define KW_SCROLLBARS_V 456
#define KW_SCROLLBARS_H 457
#define KW_STRETCH_Y 458
#define KW_STRETCH_BOTH 459
#define KW_ITEMS 460
#define KW_VALUEMAX 461
#define KW_VALUEMIN 462
#define KW_PROGRESSBAR 463
#define KW_COMBOBOX 464
#define OPTIONS 465
#define KW_BROWSER 466
#define KW_VALUECHECKED 467
#define KW_VALUEUNCHECKED 468
#define KW_CHECKBOX 469




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
#line 648 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 660 "y.tab.c"

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
#define YYLAST   864

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  215
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  468
/* YYNRULES -- Number of states.  */
#define YYNSTATES  774

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   469

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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    37,    39,    43,    45,    47,    53,    59,    65,    71,
      73,    76,    82,    83,    85,    86,    87,    88,    99,   100,
     101,   102,   113,   114,   115,   120,   124,   126,   128,   132,
     136,   138,   141,   145,   146,   148,   150,   153,   155,   157,
     159,   161,   163,   165,   169,   171,   174,   175,   179,   180,
     185,   186,   187,   188,   198,   199,   201,   202,   205,   210,
     211,   213,   215,   218,   220,   222,   224,   226,   228,   230,
     232,   234,   236,   238,   240,   242,   245,   246,   251,   253,
     254,   259,   260,   264,   266,   269,   273,   276,   277,   280,
     282,   286,   290,   296,   300,   304,   308,   310,   313,   314,
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
     626,   630,   634,   638,   642,   646,   650,   654,   658,   660,
     662,   664,   666,   669,   671,   673,   675,   677,   679,   681,
     683,   685,   687,   689,   691,   693,   695,   697,   699,   701,
     702,   706,   708,   711,   713,   716,   719,   721,   722,   732,
     745,   747,   749,   750,   753,   754,   756,   757,   759,   761,
     766,   768,   772,   773,   775,   777,   781,   785,   789,   793,
     795,   799,   801,   803,   804,   806,   808,   811,   813,   815,
     817,   818,   823,   825,   827,   829,   831,   833,   835,   838,
     841,   844,   847,   849,   851,   853,   855,   857,   859,   863,
     865,   869,   871,   874,   877,   879,   881,   883,   885,   887,
     889,   893,   897,   899,   901,   903,   905,   907,   908,   912,
     918,   919,   923,   924,   928,   930,   933,   935,   937,   939,
     941,   943,   945,   948,   950,   951,   955,   957,   959,   961,
     963,   965,   967,   969,   971,   974,   975,   979,   980,   982,
     985,   987,   991,   995,   999,  1003,  1007,  1011,  1016,  1020,
    1023,  1026,  1028,  1034,  1040,  1043,  1047,  1049,  1051,  1053,
    1055,  1057,  1059,  1063,  1066,  1068,  1071,  1079,  1081,  1085,
    1089,  1091,  1093,  1095,  1101,  1107,  1110,  1113,  1115,  1117,
    1119,  1121,  1123,  1125,  1127,  1133,  1134,  1137,  1139,  1144,
    1147,  1151,  1154,  1158,  1162,  1164,  1167,  1170,  1174,  1178,
    1183,  1185,  1188,  1190,  1193,  1195,  1197,  1199,  1201,  1203,
    1205,  1207,  1209,  1211,  1213,  1215,  1219,  1223,  1225,  1230,
    1231,  1238,  1239,  1241,  1243,  1247,  1249,  1251,  1255,  1259,
    1262,  1265,  1267,  1270,  1274,  1279,  1283,  1287,  1291,  1295,
    1299,  1303,  1307,  1311,  1315,  1320,  1324,  1327,  1330,  1336,
    1342,  1349,  1351,  1353,  1355,  1357,  1359,  1361,  1363
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     216,     0,    -1,   217,   221,   264,   269,   294,    -1,    21,
      34,    -1,    21,   220,    40,    41,    42,    -1,    21,    34,
      40,    41,    42,    -1,    21,   220,    -1,    30,    -1,    30,
      -1,   172,    -1,   172,    38,   219,    -1,   218,    -1,   218,
      38,   219,    -1,   245,    -1,   244,    -1,   176,   228,   237,
     241,    27,    -1,   175,   228,   237,   241,    27,    -1,   178,
     228,   237,   241,    27,    -1,   180,   228,   237,   226,    27,
      -1,   227,    -1,   226,   227,    -1,   174,   228,   237,   241,
      27,    -1,    -1,   219,    -1,    -1,    -1,    -1,   177,   230,
     228,   237,    31,   231,   256,    32,   232,    27,    -1,    -1,
      -1,    -1,   179,   234,   228,   237,    31,   235,   256,    32,
     236,    27,    -1,    -1,    -1,    51,   238,   240,    52,    -1,
     181,    45,    46,    -1,   183,    -1,   184,    -1,   113,    45,
      46,    -1,   173,    45,    30,    -1,   239,    -1,   240,   239,
      -1,   240,    58,   239,    -1,    -1,   242,    -1,   243,    -1,
     242,   243,    -1,   222,    -1,   223,    -1,   224,    -1,   225,
      -1,   229,    -1,   233,    -1,   182,   243,   255,    -1,   246,
      -1,   245,   246,    -1,    -1,    24,   247,   249,    -1,    -1,
      23,    46,   248,   249,    -1,    -1,    -1,    -1,   254,   250,
     253,    31,   251,   256,    32,   252,   255,    -1,    -1,   171,
      -1,    -1,    25,    29,    -1,    25,    29,    22,    29,    -1,
      -1,    27,    -1,   258,    -1,   256,   258,    -1,   219,    -1,
     257,    -1,   260,    -1,   145,    -1,    17,    -1,    44,    -1,
      46,    -1,   259,    -1,   144,    -1,   120,    -1,   116,    -1,
      16,    -1,   259,    16,    -1,    -1,    26,   261,   262,    28,
      -1,   312,    -1,    -1,   262,    44,   263,   312,    -1,    -1,
      43,   265,   255,    -1,   266,    -1,   265,   266,    -1,   265,
      58,   266,    -1,   219,   267,    -1,    -1,    45,   268,    -1,
     219,    -1,   219,    37,   219,    -1,   219,    38,   219,    -1,
     219,    38,   219,    37,   219,    -1,   219,    39,   219,    -1,
      46,    39,   219,    -1,    20,   270,   255,    -1,   272,    -1,
     270,   272,    -1,    -1,   188,    -1,   185,    -1,   187,    -1,
     189,    -1,   186,    -1,   191,    -1,   208,    -1,   209,    -1,
     214,    -1,   211,    -1,    -1,   271,   311,   273,   274,    47,
      -1,   275,    -1,   274,   275,    -1,   274,    47,   275,    -1,
      -1,    -1,    45,   276,   281,   278,   277,   288,    -1,    -1,
      26,    29,    28,    -1,    26,    29,    58,    29,    28,    -1,
     280,   126,    41,    -1,   280,    -1,    -1,    60,    72,   219,
      39,   219,    -1,    60,    72,   219,    -1,    60,   314,    -1,
      34,    39,   307,   279,    -1,   142,   279,    -1,   142,   143,
      42,   279,    -1,   219,    39,   219,    -1,   219,    -1,    53,
     219,    39,   219,    -1,    53,   219,    -1,   283,    -1,   282,
      58,   283,    -1,   284,    45,   285,    -1,   311,    -1,   219,
      39,   219,    -1,   219,    -1,   219,    39,   219,    -1,   219,
      -1,    53,   219,    39,   219,    -1,    53,   219,    -1,    49,
      -1,    58,    49,    -1,    -1,    58,   289,    -1,   290,    -1,
     289,    58,   290,    -1,    88,    -1,    89,    45,   292,   333,
      -1,    50,   286,    -1,    48,   282,   287,   286,    -1,    90,
      45,    46,    -1,    91,    45,   291,    -1,   210,    45,   291,
      -1,    93,    72,   219,    -1,    93,    72,   219,    39,   219,
      -1,    92,    72,   219,    -1,    92,    72,   219,    39,   219,
      -1,    94,    -1,    95,    -1,    96,    45,    46,    -1,    97,
      45,    51,   315,    52,    -1,   118,    45,    46,    -1,   119,
      45,    46,    -1,   173,    45,   219,    -1,    98,    -1,    36,
      25,    45,    29,    -1,    36,    -1,   117,    -1,   100,    -1,
      99,    -1,   101,    45,    46,    -1,   102,    45,    46,    -1,
     103,    -1,    82,    -1,   105,    -1,   104,    -1,   170,    -1,
     169,    -1,   106,    -1,   106,   107,    -1,   106,   108,    -1,
     183,    -1,   197,    -1,   195,    -1,   196,    -1,   192,    45,
     193,    -1,   192,    45,   194,    -1,   190,    -1,   191,    45,
      46,    -1,   199,    45,    29,    -1,   198,    45,    29,    -1,
     200,    -1,   201,    -1,   202,    -1,   203,    -1,   204,    -1,
     205,    45,    51,   316,    52,    -1,   206,    45,    29,    -1,
     207,    45,    29,    -1,   212,    45,    46,    -1,   213,    45,
      46,    -1,   212,    45,    29,    -1,   213,    45,    29,    -1,
     113,    45,    46,    -1,   181,    45,    46,    -1,    46,    -1,
      29,    -1,   115,    -1,   293,    -1,   292,   293,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    29,    -1,    82,    -1,    87,
      -1,    81,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    -1,    19,   295,   255,    -1,   296,    -1,   295,   296,
      -1,   297,    -1,   297,    47,    -1,    61,    46,    -1,   347,
      -1,    -1,    24,    57,   298,   302,    51,   303,    52,   299,
     301,    -1,   141,    51,    29,    58,    29,    52,   109,    51,
      29,    58,    29,    52,    -1,   340,    -1,   363,    -1,    -1,
     110,   139,    -1,    -1,    53,    -1,    -1,    47,    -1,   219,
      -1,   219,    26,    29,    28,    -1,   306,    -1,   303,   304,
     306,    -1,    -1,    58,    -1,   219,    -1,   219,    39,   219,
      -1,    34,    39,   219,    -1,   219,    39,    53,    -1,    34,
      39,    53,    -1,   305,    -1,   305,    59,   305,    -1,   219,
      -1,    27,    -1,    -1,   309,    -1,   310,    -1,   309,   310,
      -1,   144,    -1,   145,    -1,   219,    -1,    -1,   308,   219,
     313,   308,    -1,    62,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    67,    -1,    68,   321,    -1,    69,   321,
      -1,    70,   328,    -1,    71,   322,    -1,   111,    -1,   112,
      -1,   113,    -1,   114,    -1,   140,    -1,   319,    -1,   315,
      58,   319,    -1,   318,    -1,   316,    58,   318,    -1,    29,
      -1,    55,    29,    -1,    56,    29,    -1,    46,    -1,    30,
      -1,    16,    -1,   317,    -1,    41,    -1,   320,    -1,   320,
     109,   320,    -1,   320,    37,   320,    -1,    46,    -1,    30,
      -1,    16,    -1,   317,    -1,    41,    -1,    -1,    51,    29,
      52,    -1,    51,    29,    58,    29,    52,    -1,    -1,   325,
     109,   327,    -1,    -1,    51,    29,    52,    -1,    29,    -1,
     326,   323,    -1,   132,    -1,   133,    -1,   134,    -1,   135,
      -1,   136,    -1,   137,    -1,   138,   332,    -1,   326,    -1,
      -1,   329,   109,   330,    -1,   331,    -1,   331,    -1,   132,
      -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,   138,   332,    -1,    -1,    51,   324,    52,    -1,    -1,
     334,    -1,   125,   335,    -1,   336,    -1,   336,   123,   336,
      -1,   336,   122,   336,    -1,   337,   121,   337,    -1,   337,
       8,   337,    -1,   337,     9,   337,    -1,   337,    72,   337,
      -1,   337,   126,    72,   337,    -1,   337,    45,   337,    -1,
     337,   130,    -1,   337,   131,    -1,   337,    -1,   337,   127,
     337,   123,   337,    -1,   337,   128,    51,   339,    52,    -1,
     126,   336,    -1,    51,   336,    52,    -1,   338,    -1,    29,
      -1,    46,    -1,   129,    -1,    30,    -1,   337,    -1,   339,
      58,   337,    -1,    18,   341,    -1,   342,    -1,   341,   342,
      -1,     8,   343,     9,   300,     8,   343,     9,    -1,   344,
      -1,   343,    58,   344,    -1,   345,    39,   346,    -1,   346,
      -1,   219,    -1,   218,    -1,   147,   357,   152,   361,   355,
      -1,   148,   358,   152,   361,   355,    -1,   157,   364,    -1,
     156,   364,    -1,   351,    -1,   356,    -1,   349,    -1,   352,
      -1,   353,    -1,   364,    -1,   354,    -1,   164,   369,   165,
     348,   350,    -1,    -1,   166,   348,    -1,   160,    -1,   161,
     311,    45,   369,    -1,   163,   311,    -1,   163,    45,   311,
      -1,   163,   162,    -1,   163,    45,   162,    -1,   167,   355,
      27,    -1,   348,    -1,   355,   348,    -1,    90,    46,    -1,
      90,   159,    46,    -1,    90,    82,    46,    -1,    90,   159,
      82,    46,    -1,   359,    -1,   357,   359,    -1,   360,    -1,
     358,   360,    -1,   149,    -1,   150,    -1,   151,    -1,   149,
      -1,   153,    -1,   154,    -1,   155,    -1,   151,    -1,    93,
      -1,   150,    -1,   362,    -1,   361,   304,   362,    -1,   345,
      39,   346,    -1,   346,    -1,   345,   146,   345,   301,    -1,
      -1,   158,   219,    51,   365,   366,    52,    -1,    -1,   367,
      -1,   368,    -1,   367,    58,   368,    -1,   369,    -1,   370,
      -1,   369,   123,   369,    -1,   369,   122,   369,    -1,    56,
     369,    -1,    55,   369,    -1,   372,    -1,   126,   369,    -1,
      51,   369,    52,    -1,   371,    51,   366,    52,    -1,   168,
     152,   311,    -1,   369,   121,   369,    -1,   369,     8,   369,
      -1,   369,     9,   369,    -1,   369,    53,   369,    -1,   369,
      55,   369,    -1,   369,    56,   369,    -1,   369,    54,   369,
      -1,   369,    72,   369,    -1,   369,   126,    72,   369,    -1,
     369,    45,   369,    -1,   369,   130,    -1,   369,   131,    -1,
     369,   127,   369,   123,   369,    -1,   369,   128,    51,   373,
      52,    -1,   369,   126,   128,    51,   373,    52,    -1,   219,
      -1,   311,    -1,    29,    -1,    46,    -1,   129,    -1,    41,
      -1,   372,    -1,   373,    58,   372,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   157,   158,   163,   164,   173,   177,   181,
     182,   183,   184,   189,   192,   199,   209,   218,   231,   239,
     249,   257,   270,   271,   276,   279,   282,   275,   298,   301,
     304,   297,   318,   321,   321,   327,   330,   333,   336,   339,
     345,   346,   347,   351,   360,   366,   376,   383,   385,   387,
     389,   391,   393,   398,   408,   408,   411,   411,   424,   424,
     443,   445,   448,   443,   453,   453,   458,   459,   460,   472,
     473,   478,   479,   482,   497,   509,   510,   521,   532,   545,
     557,   568,   573,   576,   584,   585,   591,   590,   612,   615,
     615,   633,   634,   637,   638,   639,   642,   651,   652,   655,
     656,   657,   659,   660,   661,   667,   671,   671,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   691,
     690,   712,   713,   714,   718,   722,   718,   908,   909,   915,
     925,   926,   929,   930,   933,   936,   941,   952,   966,   980,
     989,   999,  1008,  1023,  1032,  1041,  1048,  1050,  1053,  1059,
    1060,  1061,  1062,  1065,  1066,  1070,  1071,  1075,  1075,  1078,
    1083,  1105,  1129,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,
    1154,  1156,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1172,  1179,  1180,  1181,  1182,  1183,  1184,
    1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,
    1195,  1196,  1198,  1199,  1200,  1201,  1202,  1203,  1209,  1210,
    1211,  1215,  1216,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,  1229,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1253,
    1254,  1257,  1257,  1259,  1259,  1262,  1272,  1278,  1278,  1281,
    1282,  1283,  1287,  1287,  1289,  1289,  1292,  1292,  1294,  1297,
    1303,  1306,  1310,  1311,  1315,  1319,  1323,  1327,  1331,  1338,
    1338,  1342,  1345,  1349,  1349,  1352,  1352,  1356,  1357,  1370,
    1378,  1378,  1387,  1391,  1395,  1399,  1403,  1407,  1411,  1417,
    1421,  1425,  1429,  1433,  1437,  1441,  1444,  1451,  1451,  1455,
    1455,  1460,  1460,  1460,  1464,  1471,  1472,  1473,  1474,  1509,
    1510,  1513,  1519,  1526,  1527,  1528,  1529,  1535,  1538,  1539,
    1542,  1543,  1550,  1552,  1557,  1565,  1568,  1569,  1570,  1571,
    1572,  1573,  1574,  1580,  1582,  1583,  1586,  1589,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1605,  1607,  1614,  1614,  1620,
    1626,  1627,  1630,  1636,  1637,  1638,  1639,  1640,  1641,  1642,
    1643,  1644,  1645,  1646,  1647,  1648,  1651,  1658,  1659,  1660,
    1665,  1668,  1672,  1684,  1687,  1688,  1692,  1702,  1709,  1718,
    1721,  1733,  1736,  1740,  1747,  1755,  1760,  1768,  1772,  1777,
    1782,  1787,  1792,  1797,  1806,  1815,  1816,  1821,  1824,  1832,
    1838,  1844,  1850,  1859,  1864,  1874,  1884,  1890,  1896,  1902,
    1912,  1924,  1932,  1944,  1952,  1953,  1954,  1958,  1959,  1960,
    1961,  1962,  1963,  1964,  1967,  1974,  1985,  1989,  1996,  2004,
    2004,  2022,  2023,  2029,  2035,  2043,  2050,  2051,  2052,  2070,
    2072,  2073,  2074,  2075,  2076,  2079,  2080,  2081,  2082,  2083,
    2084,  2085,  2086,  2087,  2088,  2089,  2090,  2091,  2092,  2093,
    2094,  2097,  2100,  2101,  2102,  2103,  2104,  2107,  2111
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
  "KW_HIDDEN", "KW_AUTOSIZE", "KW_TEXTEDIT", "KW_BUTTONEDIT", "KW_LABEL",
  "KW_EDIT", "KW_DATEEDIT", "KW_SCROLL", "KW_IMAGE", "KW_FONTPITCH",
  "KW_FIXED", "KW_VARIABLE", "KW_WANTNORETURNS", "KW_WANTTABS",
  "KW_AUTOSCALE", "KW_PIXELWIDTH", "KW_PIXELHEIGHT", "KW_SCROLLBARS_BOTH",
  "KW_SCROLLBARS_V", "KW_SCROLLBARS_H", "KW_STRETCH_Y", "KW_STRETCH_BOTH",
  "KW_ITEMS", "KW_VALUEMAX", "KW_VALUEMIN", "KW_PROGRESSBAR",
  "KW_COMBOBOX", "OPTIONS", "KW_BROWSER", "KW_VALUECHECKED",
  "KW_VALUEUNCHECKED", "KW_CHECKBOX", "$accept", "form_def",
  "database_section", "named_or_kw_st", "named_or_kw_any", "dbname",
  "screen_or_layout_section", "vbox_section", "hbox_section",
  "group_section", "folder_section", "pages", "page", "opt_layout_ident",
  "grid_section", "@1", "$@2", "$@3", "table_section", "@4", "$@5", "$@6",
  "layout_attributes", "$@7", "layout_attribute", "layout_attribute_list",
  "op_layout_items", "layout_items", "layout_container", "layout_section",
  "screen_section", "screens_section", "$@8", "$@9", "screens_rest",
  "$@10", "$@11", "$@12", "op_extended", "op_size", "op_end",
  "screen_layout", "some_text", "screen_element", "ch_list", "field",
  "$@13", "field_element", "$@14", "op_table_section", "table_def_list",
  "table_def", "opequal", "table_qualifier", "attribute_section",
  "field_tag_list", "op_field_tag_type", "field_tag", "$@15", "fpart_list",
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
     465,   466,   467,   468,   469
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   215,   216,   217,   217,   217,   217,   218,   219,   220,
     220,   220,   220,   221,   221,   222,   223,   224,   225,   226,
     226,   227,   228,   228,   230,   231,   232,   229,   234,   235,
     236,   233,   237,   238,   237,   239,   239,   239,   239,   239,
     240,   240,   240,   241,   241,   242,   242,   243,   243,   243,
     243,   243,   243,   244,   245,   245,   247,   246,   248,   246,
     250,   251,   252,   249,   253,   253,   254,   254,   254,   255,
     255,   256,   256,   257,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   259,   259,   261,   260,   262,   263,
     262,   264,   264,   265,   265,   265,   266,   267,   267,   268,
     268,   268,   268,   268,   268,   269,   270,   270,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   273,
     272,   274,   274,   274,   276,   277,   275,   278,   278,   278,
     279,   279,   280,   280,   280,   280,   281,   281,   281,   281,
     281,   281,   281,   282,   282,   283,   284,   285,   285,   286,
     286,   286,   286,   287,   287,   288,   288,   289,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   291,   291,
     291,   292,   292,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   294,
     294,   295,   295,   296,   296,   297,   297,   298,   297,   297,
     297,   297,   299,   299,   300,   300,   301,   301,   302,   302,
     303,   303,   304,   304,   305,   305,   305,   305,   305,   306,
     306,   307,   307,   308,   308,   309,   309,   310,   310,   311,
     313,   312,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   315,   315,   316,
     316,   317,   317,   317,   318,   318,   318,   318,   318,   319,
     319,   319,   320,   320,   320,   320,   320,   321,   321,   321,
     322,   322,   323,   323,   324,   325,   326,   326,   326,   326,
     326,   326,   326,   327,   328,   328,   329,   330,   331,   331,
     331,   331,   331,   331,   331,   332,   332,   333,   333,   334,
     335,   335,   335,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   337,   337,   337,   337,
     338,   339,   339,   340,   341,   341,   342,   343,   343,   344,
     344,   345,   346,   347,   347,   347,   347,   348,   348,   348,
     348,   348,   348,   348,   349,   350,   350,   351,   352,   353,
     353,   353,   353,   354,   355,   355,   356,   356,   356,   356,
     357,   357,   358,   358,   359,   359,   359,   360,   360,   360,
     360,   360,   360,   360,   361,   361,   362,   362,   363,   365,
     364,   366,   366,   367,   367,   368,   369,   369,   369,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   371,   372,   372,   372,   372,   372,   373,   373
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     3,     1,     1,     5,     5,     5,     5,     1,
       2,     5,     0,     1,     0,     0,     0,    10,     0,     0,
       0,    10,     0,     0,     4,     3,     1,     1,     3,     3,
       1,     2,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     0,     3,     0,     4,
       0,     0,     0,     9,     0,     1,     0,     2,     4,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     4,     1,     0,
       4,     0,     3,     1,     2,     3,     2,     0,     2,     1,
       3,     3,     5,     3,     3,     3,     1,     2,     0,     1,
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
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     2,     1,     2,     2,     1,     0,     9,    12,
       1,     1,     0,     2,     0,     1,     0,     1,     1,     4,
       1,     3,     0,     1,     1,     3,     3,     3,     3,     1,
       3,     1,     1,     0,     1,     1,     2,     1,     1,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     0,     3,     5,
       0,     3,     0,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     3,     0,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     4,     3,     2,
       2,     1,     5,     5,     2,     3,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     2,     7,     1,     3,     3,
       1,     1,     1,     5,     5,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     5,     0,     2,     1,     4,     2,
       3,     2,     3,     3,     1,     2,     2,     3,     3,     4,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     4,     0,
       6,     0,     1,     1,     3,     1,     1,     3,     3,     2,
       2,     1,     2,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     2,     2,     5,     5,
       6,     1,     1,     1,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     7,     3,     9,    11,     6,     1,
       0,    56,     0,    91,    14,    13,    54,     0,     0,     0,
       0,    58,    66,    22,    22,    24,    22,    28,    22,    47,
      48,    49,    50,    51,    52,    69,     0,     0,    55,     0,
       8,    10,    12,     0,    66,     0,    57,    60,    23,    32,
      32,    22,    32,    22,    32,    70,    53,    97,    69,    93,
     108,   239,     5,     4,    59,    67,    64,    33,    43,    43,
      32,    43,    32,     0,     0,    96,     0,    92,    94,   110,
     113,   111,   109,   112,   114,   115,   116,   118,   117,    69,
       0,   106,     0,     2,     0,    65,     0,     0,     0,    44,
      45,     0,     0,     0,     0,    22,     0,    19,     0,    99,
      98,    95,   105,   107,   279,   119,     0,     0,     0,     0,
       0,     0,     0,     0,   381,    69,   241,   243,   250,     0,
     246,   251,    68,    61,     0,     0,     0,    36,    37,    40,
       0,    16,    46,    15,    25,    17,    29,    32,    18,    20,
       0,     0,     0,     0,     0,     0,   373,   374,   247,   245,
       0,   414,   415,   416,     0,   410,   422,   417,   423,   421,
     418,   419,   420,     0,   412,     0,   386,   385,   240,   242,
     244,     0,     0,     0,     0,     0,    34,     0,    41,     0,
       0,    43,   104,   100,   101,   103,   124,     0,   121,     7,
     382,     0,   377,     0,   380,   375,     0,     0,     0,   411,
       0,   413,     0,   256,    84,    77,    86,    78,    79,    83,
      82,    81,    76,    73,     0,    74,    71,    80,    75,    38,
      39,    35,    42,     0,     0,     0,     0,     0,   120,   122,
     254,     0,     0,   258,     0,     0,     0,   427,   262,   424,
     262,   429,   257,   428,   273,    62,    72,    85,    26,    30,
      21,   102,     0,     0,   132,   140,   127,   123,   255,     0,
     378,   379,     0,     0,     0,     0,   263,     0,   397,     0,
       0,     0,     0,     0,   404,   389,   387,   390,   391,   393,
     383,   388,   392,   384,   431,   277,   278,     0,     0,   274,
     275,    88,    69,     0,     0,     0,   142,     0,     0,   137,
     131,     0,     0,   125,     0,     0,     0,   264,   262,   269,
     260,     0,   426,   406,     0,     0,     0,     0,   401,   399,
     463,   466,   464,     0,     0,     0,     0,   465,     0,   279,
     462,     0,   436,     0,   441,     0,   425,   405,     0,   432,
     433,   435,    87,    89,   280,   276,    63,    27,    31,   272,
     271,   132,     0,   282,   283,   284,   285,   286,   287,   317,
     317,   334,   320,     0,   292,   293,   294,   295,   296,   135,
     132,     0,   139,     0,   155,     0,   259,     0,     0,   252,
       0,     0,     0,   408,   407,     0,     0,   402,   400,     0,
     440,   439,   442,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,   457,
       0,   431,   403,   430,     0,   273,   273,   136,   141,     0,
     288,   289,   338,   339,   340,   341,   342,   343,   345,   290,
       0,   336,   326,   327,   328,   329,   330,   331,   345,   291,
       0,   322,   134,   138,   130,   128,     0,     0,   126,   376,
     268,   266,   267,   265,     0,   256,   261,   270,     0,   409,
     398,   443,   445,   447,   448,   455,   449,   452,   450,   451,
     453,   446,   438,   437,     0,     0,     0,     0,   395,     0,
     434,    90,   281,     0,     0,   344,     0,   332,     0,     0,
     325,     0,     0,   179,     0,     0,   186,   159,     0,     0,
       0,     0,     0,   170,   171,     0,     0,   177,   182,   181,
       0,     0,   185,   188,   187,   191,     0,   180,     0,     0,
     190,   189,     0,     0,   194,   200,     0,     0,   196,   197,
     195,     0,     0,   204,   205,   206,   207,   208,     0,     0,
       0,     0,     0,     0,   156,   157,   253,   248,     0,   454,
       0,     0,   467,     0,     0,   394,   444,   318,     0,   324,
       0,   335,   337,   333,   321,     0,   133,   129,     0,     0,
     143,     0,   146,     0,   150,   161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   458,   459,     0,   396,     0,
     346,   323,     0,   153,     0,     0,     0,   152,     0,   231,
     223,   224,   225,   226,   227,   228,   229,   230,   234,   232,
     235,   236,   237,   238,   233,   347,   221,   163,   219,   218,
     220,   164,   168,   166,   172,     0,   183,   184,   216,   174,
     175,   176,   217,   201,   198,   199,   203,   202,     0,   210,
     211,   165,   214,   212,   215,   213,   158,     0,   460,   468,
     319,   178,   154,   144,   162,   148,   145,     0,   149,     0,
     222,   160,   348,     0,     0,   314,   301,   313,   316,   312,
       0,     0,     0,   315,   297,   309,   306,   305,   308,   304,
       0,   307,   299,   249,     0,   151,   367,   370,   368,     0,
       0,   369,   349,   350,   361,   366,   169,   167,   302,   303,
     173,     0,     0,     0,   209,     0,   147,     0,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   298,   311,   310,   300,   365,   352,   351,   354,   355,
     358,   356,   353,     0,     0,     0,   357,     0,   371,     0,
     362,   363,     0,   372
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   200,   339,     8,    13,    29,    30,    31,
      32,   106,   107,    49,    33,    51,   189,   303,    34,    53,
     190,   304,    68,    97,   139,   140,    98,    99,   100,    14,
      15,    16,    22,    44,    46,    66,   182,   302,    96,    47,
      56,   224,   225,   226,   227,   228,   254,   297,   425,    37,
      58,    59,    75,   110,    61,    89,    90,    91,   154,   197,
     198,   237,   384,   313,   309,   310,   266,   579,   580,   581,
     686,   585,   625,   458,   554,   555,   651,   645,   646,    93,
     125,   126,   127,   206,   465,   269,   253,   244,   318,   283,
     319,   320,   361,   298,   299,   300,   340,   301,   426,   379,
     702,   710,   703,   712,   704,   705,   430,   449,   500,   570,
     450,   451,   574,   439,   440,   571,   441,   495,   691,   692,
     722,   723,   724,   725,   769,   128,   156,   157,   201,   202,
     203,   204,   130,   284,   285,   565,   286,   287,   288,   289,
     290,   291,   164,   173,   165,   174,   248,   249,   131,   292,
     294,   348,   349,   350,   351,   342,   343,   344,   563
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -645
static const yytype_int16 yypact[] =
{
      17,     7,    62,    -9,  -645,    43,    72,    79,    90,  -645,
      97,  -645,   204,   156,  -645,   163,  -645,   169,   190,   190,
     209,  -645,   210,   190,   190,  -645,   190,  -645,   190,  -645,
    -645,  -645,  -645,  -645,  -645,   236,   190,   261,  -645,   226,
    -645,  -645,  -645,   252,   210,   268,  -645,  -645,  -645,   257,
     257,   190,   257,   190,   257,  -645,  -645,   256,    30,  -645,
     631,   287,  -645,  -645,  -645,   289,   148,  -645,   204,   204,
     257,   204,   257,   147,    73,  -645,   190,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,   -11,
     190,  -645,   249,  -645,   313,  -645,   323,   -60,   330,   204,
    -645,   333,   332,   347,   336,   190,    -6,  -645,   337,   311,
    -645,  -645,  -645,  -645,  -645,  -645,   384,   341,   348,   372,
     260,   407,   254,   254,  -645,   230,  -645,   380,  -645,   282,
    -645,  -645,  -645,  -645,   397,   398,   408,  -645,  -645,  -645,
     131,  -645,  -645,  -645,  -645,  -645,  -645,   257,  -645,  -645,
     190,   190,   190,   190,   409,   425,   384,  -645,  -645,  -645,
     427,  -645,  -645,  -645,   250,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,   473,  -645,   190,  -645,  -645,  -645,  -645,
    -645,   190,   475,   411,   429,   414,  -645,   -60,  -645,   475,
     475,   204,  -645,  -645,   426,  -645,  -645,   219,  -645,   433,
    -645,     8,  -645,   434,  -645,  -645,   190,   410,   425,  -645,
     425,  -645,   415,   438,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,   432,  -645,  -645,   464,  -645,  -645,
    -645,  -645,  -645,   435,   458,   455,   190,     2,   409,  -645,
     436,   425,   476,   477,   457,   480,   471,  -645,   198,  -645,
     198,  -645,  -645,  -645,   132,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,   472,   190,   -35,   474,   486,  -645,  -645,   512,
    -645,  -645,   495,    31,   478,   476,  -645,   -39,  -645,   190,
     -17,    85,   111,   425,  -645,  -645,  -645,  -645,  -645,  -645,
     111,  -645,  -645,   111,    85,  -645,  -645,   181,   190,   132,
    -645,  -645,   236,   498,   500,   194,   489,   675,   487,  -645,
     413,   190,   508,  -645,   425,   513,   501,   504,    60,   485,
    -645,   437,  -645,  -645,   499,   -15,   502,    19,  -645,  -645,
    -645,  -645,  -645,    85,    85,    85,    85,  -645,   401,   503,
    -645,    39,  -645,   522,  -645,    69,  -645,  -645,   497,   492,
    -645,   514,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,   515,   190,  -645,  -645,  -645,  -645,  -645,  -645,   530,
     530,   361,   552,   190,  -645,  -645,  -645,  -645,  -645,  -645,
     515,   523,  -645,    22,   505,    21,  -645,    16,    51,   484,
      31,    31,   536,  -645,  -645,   550,    85,  -645,  -645,   462,
     514,   514,   514,   190,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,   -46,    85,   546,  -645,  -645,
     111,    85,  -645,  -645,    85,   132,   132,  -645,  -645,   569,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,   549,  -645,
     496,  -645,  -645,  -645,  -645,  -645,  -645,  -645,   549,  -645,
     506,   553,   562,  -645,  -645,  -645,   580,   234,  -645,  -645,
    -645,  -645,  -645,  -645,   479,   438,  -645,  -645,   582,  -645,
     514,  -645,  -645,   593,   593,   514,   514,   514,   514,   514,
     514,   514,   514,   514,    85,   561,   605,    56,   450,   565,
    -645,  -645,  -645,   176,   592,  -645,   361,  -645,   552,   600,
    -645,   190,   602,   606,   190,   154,  -645,  -645,   587,   588,
     589,   567,   579,  -645,  -645,   607,   609,  -645,  -645,  -645,
     610,   617,  -645,  -645,  -645,   178,   618,  -645,   619,   621,
    -645,  -645,   622,   625,  -645,  -645,   626,   629,  -645,  -645,
    -645,   633,   634,  -645,  -645,  -645,  -645,  -645,   635,   636,
     646,   647,   648,   649,   614,  -645,  -645,  -645,   637,   514,
      56,    85,  -645,   179,   111,  -645,  -645,  -645,   684,  -645,
     665,  -645,  -645,  -645,  -645,   666,  -645,  -645,   677,   164,
    -645,   680,  -645,   190,   690,  -645,   683,   688,    13,   190,
     190,   702,   679,   704,   705,  -645,  -645,   706,   707,   708,
     190,   709,   726,    96,   749,   751,   730,   753,   754,    13,
      70,   162,   234,   761,   188,   514,  -645,    56,  -645,   739,
    -645,  -645,   763,  -645,    24,   154,   190,   759,   190,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,   624,  -645,  -645,  -645,  -645,
    -645,  -645,   764,   766,  -645,   627,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,   755,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,   741,  -645,  -645,
    -645,  -645,  -645,  -645,  -645,   767,  -645,   190,  -645,   166,
    -645,  -645,  -645,   190,   190,  -645,  -645,  -645,  -645,  -645,
     765,   771,   191,  -645,  -645,    -8,  -645,  -645,  -645,  -645,
     247,  -645,  -645,  -645,   190,  -645,  -645,  -645,  -645,   166,
     166,  -645,  -645,   223,   405,  -645,  -645,  -645,  -645,  -645,
    -645,   627,   627,   627,  -645,   755,  -645,   750,  -645,   166,
     166,    76,    76,    76,    76,    76,   735,    76,   757,  -645,
    -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,  -645,    76,   686,    76,  -645,    76,  -645,   255,
    -645,  -645,    76,  -645
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -645,  -645,  -645,   811,   -18,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,   715,   340,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,  -645,   248,  -645,   -89,  -645,   -49,  -645,   -10,  -645,
    -645,   798,  -645,  -645,   770,  -645,  -645,  -645,  -645,  -645,
     -55,   199,  -645,    18,  -645,  -645,  -645,  -645,  -645,  -645,
    -645,   -13,  -645,  -645,  -645,  -645,  -645,   734,  -645,  -645,
    -170,  -645,  -645,  -645,  -271,  -645,  -645,  -645,   200,  -645,
    -645,   201,  -645,  -645,  -645,   213,   218,  -645,   183,  -645,
    -645,   710,  -645,  -645,  -645,  -645,   364,  -645,  -645,   516,
     439,   441,  -645,   406,  -645,   534,   -86,   412,  -645,  -645,
    -645,  -645,  -644,   101,   107,  -313,   481,  -645,  -645,  -645,
    -645,   343,  -645,  -645,  -645,  -645,   350,   395,  -645,  -645,
    -645,  -481,    32,  -645,  -645,  -645,  -645,   691,   535,   603,
     -81,   133,  -645,  -281,  -645,  -645,  -645,  -645,  -645,  -645,
    -211,  -645,  -645,  -645,   689,   681,   638,   572,  -645,   299,
    -645,   431,  -645,   440,  -258,  -645,  -645,  -435,   290
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -462
static const yytype_int16 yytable[] =
{
      41,    42,    35,    77,   115,    48,    48,   323,    48,   347,
      48,   129,   347,    40,    10,    11,    55,   240,    57,  -108,
     101,   148,   103,   341,   711,   307,   484,   239,   327,   732,
     459,   394,    40,    48,   112,    48,   262,     4,     1,   293,
      57,     5,   648,   324,   129,    78,    40,   404,   405,    40,
     455,   188,   562,   134,    40,   263,   109,    55,    57,   649,
      40,    40,     9,   111,   347,   316,   241,   395,   267,   460,
     178,   345,   114,   682,   124,   399,   400,   401,   402,   241,
     456,    40,   485,    17,   406,   330,    40,    48,    76,   142,
     427,   711,   407,   408,   409,   410,   422,   331,   232,   672,
     213,   733,   332,    40,   462,   716,   717,   124,   308,   453,
      18,   411,   389,   135,   330,    40,   673,    19,   276,   108,
     325,   136,   718,   137,   138,   562,   331,   246,   650,   246,
      20,   332,   192,   193,   194,   195,   333,   124,   470,   488,
     334,   335,   235,    21,   264,   328,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   212,   486,   277,
     412,   413,   414,   124,   223,   415,   416,   417,   105,   418,
     419,   223,   223,    12,    79,    80,    81,    82,    83,     6,
      84,   397,   679,   186,    40,   337,    10,    11,   243,   187,
     124,   674,   124,   326,   329,   716,   717,    85,    86,    36,
      87,   277,   246,    88,   420,   721,   223,   583,   675,   352,
      39,   336,   718,   623,   337,   223,   223,   719,   261,   265,
      40,   359,   624,   124,    40,   353,   559,   175,   567,   278,
     279,   616,   280,   281,   568,    45,   282,   617,   737,   738,
     678,   398,   256,   730,   134,   306,   617,   356,   116,   731,
      43,   256,   256,   338,   117,   317,   276,    55,   756,   757,
      40,   114,   114,    55,   196,   124,   238,   116,    62,   175,
     503,   278,   279,   117,   280,   281,   295,   296,   282,    40,
     354,    60,   504,   618,   505,   595,   596,   360,   277,   664,
     665,   118,   720,   382,    63,   721,   124,    65,    69,   734,
      71,    74,    73,   615,   135,   735,    92,   771,    67,   114,
     118,    94,   136,   772,   137,   138,   506,   472,   102,    95,
     104,   105,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   247,   132,   247,   428,   739,   740,   526,   151,   152,
     153,   527,   528,   529,   133,   452,   175,   141,   278,   279,
     143,   280,   281,   144,    50,   282,    52,   146,    54,   461,
     463,   119,   317,   317,   145,   271,   150,   120,   121,    23,
      24,    25,    26,    27,    28,   114,   122,   123,   233,   234,
     119,    70,   155,    72,   159,   191,   120,   121,   158,   161,
     162,   163,   208,   530,   531,   122,   123,   532,   322,   161,
     162,   163,   175,   741,   742,   533,   247,   534,   582,   752,
     753,   176,   177,   160,   535,   536,   537,   180,   181,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   183,   184,   551,   147,   552,   553,   214,   215,
     743,   214,   215,   185,   196,   199,   207,   229,   216,   230,
     231,   216,    40,   236,   255,    40,   251,   258,   245,   114,
     404,   405,    -8,   242,   214,   215,   217,   744,   218,   217,
     257,   218,   260,   576,   216,   252,   114,   584,    40,   268,
     259,   214,   215,   432,   433,   434,   435,   436,   437,   438,
     166,   216,   217,   272,   218,    40,     4,   406,   273,   274,
     275,   305,   312,   311,   471,   407,   408,   409,   410,   217,
     314,   218,   404,   405,   315,   357,   745,   358,   362,   380,
     321,   746,   747,   748,   411,   749,   750,   383,   582,   381,
     387,   386,   114,   388,   391,   393,   392,   396,   219,   423,
     424,   219,   220,   403,  -461,   220,   167,   168,   169,   406,
     170,   171,   172,   457,   454,   627,   166,   407,   408,   409,
     410,   652,   653,   421,   219,   307,   221,   222,   220,   221,
     222,   429,   661,   412,   413,   414,   411,   468,   415,   416,
     417,   219,   418,   419,   464,   220,   469,   487,   493,   114,
     494,   501,   221,   222,   499,   496,   114,   584,   685,   502,
     688,   558,   560,   404,   405,   498,   564,   566,   556,   221,
     222,   569,   167,   168,   169,   210,   170,   171,   172,   575,
     577,   578,   586,   587,   588,   412,   413,   414,   406,   589,
     415,   416,   417,   695,   418,   419,   407,   408,   409,   410,
     406,   590,   591,   629,   592,   593,   696,   697,   407,   408,
     409,   410,   594,   597,   598,   411,   599,   600,   698,   715,
     601,   602,   612,   699,   603,   726,   727,   411,   604,   605,
     606,   607,   700,   701,   442,   443,   444,   445,   446,   447,
     448,   608,   609,   610,   611,   613,   736,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   644,   629,   619,   412,   413,   414,   620,   621,   415,
     416,   417,   622,   418,   419,   626,   412,   413,   561,   628,
     655,   415,   416,   417,   647,   418,   419,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   654,   689,
     656,   657,   658,   659,   660,   662,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   706,   663,   758,   759,   760,   761,   762,   666,   764,
     667,   668,   669,   670,   696,   707,   374,   375,   376,   377,
     677,   680,   681,   713,   728,   766,   708,   768,   687,   770,
     729,   709,   755,   693,   773,   694,   714,   763,   765,   767,
     700,   701,     7,    38,    64,   378,    79,    80,    81,    82,
      83,   149,    84,   113,   683,   676,   684,   671,   690,   557,
     467,   466,   492,   355,   390,   179,   754,   491,   751,    85,
      86,   573,    87,   497,   270,    88,   572,   205,   250,   385,
     614,   431,   489,   209,   211,   346,     0,     0,     0,     0,
       0,     0,     0,     0,   490
};

static const yytype_int16 yycheck[] =
{
      18,    19,    12,    58,    90,    23,    24,    46,    26,   290,
      28,    92,   293,    30,    23,    24,    27,     9,    36,    30,
      69,    27,    71,   281,   668,    60,    72,   197,    45,    37,
       9,    46,    30,    51,    89,    53,    34,    30,    21,   250,
      58,    34,    29,    82,   125,    58,    30,     8,     9,    30,
      28,   140,   487,   113,    30,    53,    74,    27,    76,    46,
      30,    30,     0,    76,   345,    34,    58,    82,   238,    53,
     125,   282,    90,    49,    92,   333,   334,   335,   336,    58,
      58,    30,   128,    40,    45,    29,    30,   105,    58,    99,
     361,   735,    53,    54,    55,    56,    27,    41,   187,    29,
     181,   109,    46,    30,    53,    29,    30,   125,   143,   380,
      38,    72,    52,   173,    29,    30,    46,    38,    58,    46,
     159,   181,    46,   183,   184,   560,    41,   208,   115,   210,
      40,    46,   150,   151,   152,   153,    51,   155,   396,   420,
      55,    56,   191,    46,   142,   162,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   175,   416,    90,
     121,   122,   123,   181,   182,   126,   127,   128,   174,   130,
     131,   189,   190,   182,   185,   186,   187,   188,   189,   172,
     191,   162,   617,    52,    30,   129,    23,    24,   206,    58,
     208,    29,   210,   279,   280,    29,    30,   208,   209,    43,
     211,    90,   283,   214,   165,   129,   224,    53,    46,    28,
      41,   126,    46,    49,   129,   233,   234,    51,   236,   237,
      30,    27,    58,   241,    30,    44,   484,   158,    52,   160,
     161,    52,   163,   164,    58,    25,   167,    58,   719,   720,
      52,   327,   224,    52,   113,   263,    58,   302,    18,    58,
      41,   233,   234,   168,    24,   273,    58,    27,   739,   740,
      30,   279,   280,    27,    45,   283,    47,    18,    42,   158,
      36,   160,   161,    24,   163,   164,   144,   145,   167,    30,
     298,    20,    48,   564,    50,   107,   108,   305,    90,   193,
     194,    61,   126,   311,    42,   129,   314,    29,    50,    52,
      52,    45,    54,   561,   173,    58,    19,    52,    51,   327,
      61,    22,   181,    58,   183,   184,    82,   403,    70,   171,
      72,   174,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   208,    29,   210,   362,   122,   123,   113,    37,    38,
      39,   117,   118,   119,    31,   373,   158,    27,   160,   161,
      27,   163,   164,    31,    24,   167,    26,    31,    28,   387,
     388,   141,   390,   391,    27,   242,    39,   147,   148,   175,
     176,   177,   178,   179,   180,   403,   156,   157,   189,   190,
     141,    51,     8,    53,    46,   147,   147,   148,    57,   149,
     150,   151,   152,   169,   170,   156,   157,   173,   275,   149,
     150,   151,   158,     8,     9,   181,   283,   183,   504,   732,
     733,   122,   123,    51,   190,   191,   192,    47,   146,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    45,    45,   210,   105,   212,   213,    16,    17,
      45,    16,    17,    45,    45,    30,    29,    46,    26,    30,
      46,    26,    30,    37,    32,    30,    51,    32,    58,   487,
       8,     9,    39,    39,    16,    17,    44,    72,    46,    44,
      16,    46,    27,   501,    26,    47,   504,   505,    30,    53,
      32,    16,    17,   132,   133,   134,   135,   136,   137,   138,
      93,    26,    44,    26,    46,    30,    30,    45,    51,    29,
      39,    39,    26,    39,    52,    53,    54,    55,    56,    44,
       8,    46,     8,     9,    29,    27,   121,    27,    39,    42,
      52,   126,   127,   128,    72,   130,   131,    29,   624,   126,
      39,    28,   560,    39,    59,    46,   109,    45,   116,    52,
      58,   116,   120,   152,    51,   120,   149,   150,   151,    45,
     153,   154,   155,    58,    41,   583,    93,    53,    54,    55,
      56,   589,   590,    51,   116,    60,   144,   145,   120,   144,
     145,    51,   600,   121,   122,   123,    72,    51,   126,   127,
     128,   116,   130,   131,   110,   120,    46,    51,    29,   617,
      51,    39,   144,   145,    51,   109,   624,   625,   626,    29,
     628,    29,    51,     8,     9,   109,   166,    52,   139,   144,
     145,    29,   149,   150,   151,   152,   153,   154,   155,    29,
      28,    25,    45,    45,    45,   121,   122,   123,    45,    72,
     126,   127,   128,    16,   130,   131,    53,    54,    55,    56,
      45,    72,    45,    29,    45,    45,    29,    30,    53,    54,
      55,    56,    45,    45,    45,    72,    45,    45,    41,   687,
      45,    45,    58,    46,    45,   693,   694,    72,    45,    45,
      45,    45,    55,    56,   132,   133,   134,   135,   136,   137,
     138,    45,    45,    45,    45,    58,   714,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    29,    29,   121,   122,   123,    52,    52,   126,
     127,   128,    45,   130,   131,    45,   121,   122,   123,    39,
      51,   126,   127,   128,    46,   130,   131,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    46,   125,
      46,    46,    46,    46,    46,    46,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    16,    46,   741,   742,   743,   744,   745,    29,   747,
      29,    51,    29,    29,    29,    30,   111,   112,   113,   114,
      29,    52,    29,    52,    29,   763,    41,   765,    39,   767,
      29,    46,    52,    39,   772,    39,    39,    72,    51,   123,
      55,    56,     1,    15,    44,   140,   185,   186,   187,   188,
     189,   106,   191,    89,   624,   612,   625,   609,   645,   465,
     391,   390,   426,   299,   318,   125,   735,   425,   731,   208,
     209,   498,   211,   448,   241,   214,   496,   156,   210,   314,
     560,   370,   421,   164,   173,   283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   424
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   216,   217,    30,    34,   172,   218,   220,     0,
      23,    24,   182,   221,   244,   245,   246,    40,    38,    38,
      40,    46,   247,   175,   176,   177,   178,   179,   180,   222,
     223,   224,   225,   229,   233,   243,    43,   264,   246,    41,
      30,   219,   219,    41,   248,    25,   249,   254,   219,   228,
     228,   230,   228,   234,   228,    27,   255,   219,   265,   266,
      20,   269,    42,    42,   249,    29,   250,    51,   237,   237,
     228,   237,   228,   237,    45,   267,    58,   255,   266,   185,
     186,   187,   188,   189,   191,   208,   209,   211,   214,   270,
     271,   272,    19,   294,    22,   171,   253,   238,   241,   242,
     243,   241,   237,   241,   237,   174,   226,   227,    46,   219,
     268,   266,   255,   272,   219,   311,    18,    24,    61,   141,
     147,   148,   156,   157,   219,   295,   296,   297,   340,   345,
     347,   363,    29,    31,   113,   173,   181,   183,   184,   239,
     240,    27,   243,    27,    31,    27,    31,   228,    27,   227,
      39,    37,    38,    39,   273,     8,   341,   342,    57,    46,
      51,   149,   150,   151,   357,   359,    93,   149,   150,   151,
     153,   154,   155,   358,   360,   158,   364,   364,   255,   296,
      47,   146,   251,    45,    45,    45,    52,    58,   239,   231,
     235,   237,   219,   219,   219,   219,    45,   274,   275,    30,
     218,   343,   344,   345,   346,   342,   298,    29,   152,   359,
     152,   360,   219,   345,    16,    17,    26,    44,    46,   116,
     120,   144,   145,   219,   256,   257,   258,   259,   260,    46,
      30,    46,   239,   256,   256,   241,    37,   276,    47,   275,
       9,    58,    39,   219,   302,    58,   345,   346,   361,   362,
     361,    51,    47,   301,   261,    32,   258,    16,    32,    32,
      27,   219,    34,    53,   142,   219,   281,   275,    53,   300,
     344,   346,    26,    51,    29,    39,    58,    90,   160,   161,
     163,   164,   167,   304,   348,   349,   351,   352,   353,   354,
     355,   356,   364,   355,   365,   144,   145,   262,   308,   309,
     310,   312,   252,   232,   236,    39,   219,    60,   143,   279,
     280,    39,    26,   278,     8,    29,    34,   219,   303,   305,
     306,    52,   346,    46,    82,   159,   311,    45,   162,   311,
      29,    41,    46,    51,    55,    56,   126,   129,   168,   219,
     311,   369,   370,   371,   372,   355,   362,   348,   366,   367,
     368,   369,    28,    44,   219,   310,   255,    27,    27,    27,
     219,   307,    39,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   111,   112,   113,   114,   140,   314,
      42,   126,   219,    29,   277,   343,    28,    39,    39,    52,
     304,    59,   109,    46,    46,    82,    45,   162,   311,   369,
     369,   369,   369,   152,     8,     9,    45,    53,    54,    55,
      56,    72,   121,   122,   123,   126,   127,   128,   130,   131,
     165,    51,    27,    52,    58,   263,   313,   279,   219,    51,
     321,   321,   132,   133,   134,   135,   136,   137,   138,   328,
     329,   331,   132,   133,   134,   135,   136,   137,   138,   322,
     325,   326,   219,   279,    41,    28,    58,    58,   288,     9,
      53,   219,    53,   219,   110,   299,   306,   305,    51,    46,
     369,    52,   311,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,    72,   128,   369,    51,   348,   366,
     368,   312,   308,    29,    51,   332,   109,   332,   109,    51,
     323,    39,    29,    36,    48,    50,    82,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   113,   117,   118,   119,
     169,   170,   173,   181,   183,   190,   191,   192,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   210,   212,   213,   289,   290,   139,   301,    29,   369,
      51,   123,   372,   373,   166,   350,    52,    52,    58,    29,
     324,   330,   331,   326,   327,    29,   219,    28,    25,   282,
     283,   284,   311,    53,   219,   286,    45,    45,    45,    72,
      72,    45,    45,    45,    45,   107,   108,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    58,    58,   373,   369,    52,    58,   348,    29,
      52,    52,    45,    49,    58,   287,    45,   219,    39,    29,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,   292,   293,    46,    29,    46,
     115,   291,   219,   219,    46,    51,    46,    46,    46,    46,
      46,   219,    46,    46,   193,   194,    29,    29,    51,    29,
      29,   291,    29,    46,    29,    46,   290,    29,    52,   372,
      52,    29,    49,   283,   286,   219,   285,    39,   219,   125,
     293,   333,   334,    39,    39,    16,    29,    30,    41,    46,
      55,    56,   315,   317,   319,   320,    16,    30,    41,    46,
     316,   317,   318,    52,    39,   219,    29,    30,    46,    51,
     126,   129,   335,   336,   337,   338,   219,   219,    29,    29,
      52,    58,    37,   109,    52,    58,   219,   336,   336,   122,
     123,     8,     9,    45,    72,   121,   126,   127,   128,   130,
     131,   319,   320,   320,   318,    52,   336,   336,   337,   337,
     337,   337,   337,    72,   337,    51,   337,   123,   337,   339,
     337,    52,    58,   337
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
#line 157 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 158 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 163 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 164 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 181 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 182 "screen.yacc"
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 184 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 189 "screen.yacc"
    {
			the_form.layout=NULL;
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 192 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 199 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 209 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_HBOX;
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 218 "screen.yacc"
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

  case 18:

/* Line 1455 of yacc.c  */
#line 231 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 239 "screen.yacc"
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

  case 20:

/* Line 1455 of yacc.c  */
#line 249 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 257 "screen.yacc"
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

  case 22:

/* Line 1455 of yacc.c  */
#line 270 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 276 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 279 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 282 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 283 "screen.yacc"
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

  case 28:

/* Line 1455 of yacc.c  */
#line 298 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 301 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 304 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 305 "screen.yacc"
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

  case 32:

/* Line 1455 of yacc.c  */
#line 318 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 321 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 321 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 327 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 330 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 333 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 336 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 339 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_ACTION, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 351 "screen.yacc"
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

  case 44:

/* Line 1455 of yacc.c  */
#line 360 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 366 "screen.yacc"
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

  case 46:

/* Line 1455 of yacc.c  */
#line 376 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 384 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 386 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 388 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 390 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 392 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 394 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 400 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(2) - (3)].layout);
	}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 411 "screen.yacc"
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

  case 58:

/* Line 1455 of yacc.c  */
#line 424 "screen.yacc"
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

  case 60:

/* Line 1455 of yacc.c  */
#line 443 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 445 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 448 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 453 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 460 "screen.yacc"
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

  case 73:

/* Line 1455 of yacc.c  */
#line 482 "screen.yacc"
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

  case 74:

/* Line 1455 of yacc.c  */
#line 497 "screen.yacc"
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

  case 75:

/* Line 1455 of yacc.c  */
#line 509 "screen.yacc"
    { ltab=0; }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 510 "screen.yacc"
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

  case 77:

/* Line 1455 of yacc.c  */
#line 521 "screen.yacc"
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

  case 78:

/* Line 1455 of yacc.c  */
#line 532 "screen.yacc"
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

  case 79:

/* Line 1455 of yacc.c  */
#line 545 "screen.yacc"
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

  case 80:

/* Line 1455 of yacc.c  */
#line 557 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 568 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 573 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 576 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 584 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 585 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 591 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 598 "screen.yacc"
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

  case 88:

/* Line 1455 of yacc.c  */
#line 612 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 615 "screen.yacc"
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

  case 90:

/* Line 1455 of yacc.c  */
#line 626 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 642 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 651 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 652 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 655 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 656 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 658 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 659 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 660 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 676 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 677 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 678 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 679 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 680 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 681 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 682 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 683 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 684 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 685 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 686 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 691 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 697 "screen.yacc"
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
		}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 718 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 722 "screen.yacc"
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

  case 126:

/* Line 1455 of yacc.c  */
#line 732 "screen.yacc"
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
}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 909 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 915 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 925 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 926 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 929 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 930 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 933 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 936 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 941 "screen.yacc"
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

  case 137:

/* Line 1455 of yacc.c  */
#line 952 "screen.yacc"
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

  case 138:

/* Line 1455 of yacc.c  */
#line 966 "screen.yacc"
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

  case 139:

/* Line 1455 of yacc.c  */
#line 980 "screen.yacc"
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

  case 140:

/* Line 1455 of yacc.c  */
#line 989 "screen.yacc"
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

  case 141:

/* Line 1455 of yacc.c  */
#line 999 "screen.yacc"
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

  case 142:

/* Line 1455 of yacc.c  */
#line 1008 "screen.yacc"
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

  case 143:

/* Line 1455 of yacc.c  */
#line 1023 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 1032 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1041 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1050 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1053 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1059 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1060 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1061 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1062 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1078 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1083 "screen.yacc"
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

  case 161:

/* Line 1455 of yacc.c  */
#line 1105 "screen.yacc"
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

  case 162:

/* Line 1455 of yacc.c  */
#line 1129 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1137 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1138 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1139 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1140 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1141 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1142 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1143 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1144 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1145 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1146 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1147 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1148 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1149 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1150 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1151 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1152 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1153 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1154 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1156 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1158 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1159 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1160 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1161 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1162 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1163 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1164 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1165 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1166 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1167 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1168 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1172 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1179 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1180 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1181 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1182 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1183 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1184 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1185 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1186 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1187 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1188 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1189 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1190 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1191 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1192 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1193 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1194 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1195 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1196 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1198 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1199 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1200 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1201 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1202 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1203 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1209 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1210 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1211 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1216 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1220 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1221 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1222 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1223 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1224 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1225 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1226 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1227 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1229 "screen.yacc"
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

  case 232:

/* Line 1455 of yacc.c  */
#line 1243 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1244 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1245 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1246 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1247 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1248 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1249 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1262 "screen.yacc"
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

  case 246:

/* Line 1455 of yacc.c  */
#line 1272 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1278 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1289 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1289 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1294 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1297 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1303 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1306 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1316 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1320 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1324 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1328 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1332 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1338 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1342 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1345 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1349 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1349 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1356 "screen.yacc"
    {colno++;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1357 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1370 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1378 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1380 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1387 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1391 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1395 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1399 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1403 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1407 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1411 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1417 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1421 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1425 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1429 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1433 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1437 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1441 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1444 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1451 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1455 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1460 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1464 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1471 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1472 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1474 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1510 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1513 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1519 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1526 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1527 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1528 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1529 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1535 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1538 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1539 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1542 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1544 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1550 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1552 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1557 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1565 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1568 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1569 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1570 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1571 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1572 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1573 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1575 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1582 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1583 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1586 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1589 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1593 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1594 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1595 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1596 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1597 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1598 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1600 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1605 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1607 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1614 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1614 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1620 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1627 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1630 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1636 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1637 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1638 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1639 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1640 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1641 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1642 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1643 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1644 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1645 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1646 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1647 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1648 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1651 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1658 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1659 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1660 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1668 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1672 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1692 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1702 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1709 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1718 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1721 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1740 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1747 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1755 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1760 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1768 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1772 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1777 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1782 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1787 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1792 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1797 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1806 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1815 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1816 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1825 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1833 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1839 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1845 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1851 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1859 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1864 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1874 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1884 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1890 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1896 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1902 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1912 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 1924 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 1932 "screen.yacc"
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

  case 413:

/* Line 1455 of yacc.c  */
#line 1944 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1952 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1953 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1954 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1958 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1959 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1960 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1961 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1962 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1963 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1964 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1967 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1974 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1985 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1989 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1996 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2004 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2010 "screen.yacc"
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

  case 431:

/* Line 1455 of yacc.c  */
#line 2022 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2023 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2029 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2035 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2043 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2051 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2052 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2070 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2072 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2073 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2074 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2075 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2076 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2079 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2080 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2081 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2082 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2083 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2084 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2085 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2086 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2087 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2088 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2089 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2090 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2091 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2092 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2093 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2094 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2100 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2101 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2102 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2103 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2104 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2107 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2111 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1455 of yacc.c  */
#line 6466 "y.tab.c"
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
#line 2123 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




