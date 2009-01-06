
/* A Bison parser, made by GNU Bison 2.4.  */

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
#define YYBISON_VERSION "2.4"

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
#line 646 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 658 "y.tab.c"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   879

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  469
/* YYNRULES -- Number of states.  */
#define YYNSTATES  776

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
     889,   891,   895,   899,   901,   903,   905,   907,   909,   910,
     914,   920,   921,   925,   926,   930,   932,   935,   937,   939,
     941,   943,   945,   947,   950,   952,   953,   957,   959,   961,
     963,   965,   967,   969,   971,   973,   976,   977,   981,   982,
     984,   987,   989,   993,   997,  1001,  1005,  1009,  1013,  1018,
    1022,  1025,  1028,  1030,  1036,  1042,  1045,  1049,  1051,  1053,
    1055,  1057,  1059,  1061,  1065,  1068,  1070,  1073,  1081,  1083,
    1087,  1091,  1093,  1095,  1097,  1103,  1109,  1112,  1115,  1117,
    1119,  1121,  1123,  1125,  1127,  1129,  1135,  1136,  1139,  1141,
    1146,  1149,  1153,  1156,  1160,  1164,  1166,  1169,  1172,  1176,
    1180,  1185,  1187,  1190,  1192,  1195,  1197,  1199,  1201,  1203,
    1205,  1207,  1209,  1211,  1213,  1215,  1217,  1221,  1225,  1227,
    1232,  1233,  1240,  1241,  1243,  1245,  1249,  1251,  1253,  1257,
    1261,  1264,  1267,  1269,  1272,  1276,  1281,  1285,  1289,  1293,
    1297,  1301,  1305,  1309,  1313,  1317,  1322,  1326,  1329,  1332,
    1338,  1344,  1351,  1353,  1355,  1357,  1359,  1361,  1363,  1365
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     215,     0,    -1,   216,   220,   263,   268,   293,    -1,    21,
      34,    -1,    21,   219,    40,    41,    42,    -1,    21,    34,
      40,    41,    42,    -1,    21,   219,    -1,    30,    -1,   117,
      -1,    30,    -1,   117,    -1,   172,    -1,   172,    38,   218,
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
     291,   332,    -1,    50,   285,    -1,    48,   281,   286,   285,
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
      -1,   346,    -1,    -1,    24,    57,   297,   301,    51,   302,
      52,   298,   300,    -1,   141,    51,    29,    58,    29,    52,
     109,    51,    29,    58,    29,    52,    -1,   339,    -1,   362,
      -1,    -1,   110,   139,    -1,    -1,    53,    -1,    -1,    47,
      -1,   218,    -1,   218,    26,    29,    28,    -1,   305,    -1,
     302,   303,   305,    -1,    -1,    58,    -1,   218,    -1,   218,
      39,   218,    -1,    34,    39,   218,    -1,   218,    39,    53,
      -1,    34,    39,    53,    -1,   304,    -1,   304,    59,   304,
      -1,   218,    -1,    27,    -1,    -1,   308,    -1,   309,    -1,
     308,   309,    -1,   144,    -1,   145,    -1,   218,    -1,    -1,
     307,   218,   312,   307,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,   320,    -1,
      69,   320,    -1,    70,   327,    -1,    71,   321,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,    -1,   140,    -1,   318,
      -1,   314,    58,   318,    -1,   317,    -1,   315,    58,   317,
      -1,    29,    -1,    55,    29,    -1,    56,    29,    -1,    46,
      -1,    30,    -1,    16,    -1,   316,    -1,    41,    -1,   319,
      -1,   319,   109,   319,    -1,   319,    37,   319,    -1,    46,
      -1,    30,    -1,    16,    -1,   316,    -1,    41,    -1,    -1,
      51,    29,    52,    -1,    51,    29,    58,    29,    52,    -1,
      -1,   324,   109,   326,    -1,    -1,    51,    29,    52,    -1,
      29,    -1,   325,   322,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,   331,    -1,
     325,    -1,    -1,   328,   109,   329,    -1,   330,    -1,   330,
      -1,   132,    -1,   133,    -1,   134,    -1,   135,    -1,   136,
      -1,   137,    -1,   138,   331,    -1,    -1,    51,   323,    52,
      -1,    -1,   333,    -1,   125,   334,    -1,   335,    -1,   335,
     123,   335,    -1,   335,   122,   335,    -1,   336,   121,   336,
      -1,   336,     8,   336,    -1,   336,     9,   336,    -1,   336,
      72,   336,    -1,   336,   126,    72,   336,    -1,   336,    45,
     336,    -1,   336,   130,    -1,   336,   131,    -1,   336,    -1,
     336,   127,   336,   123,   336,    -1,   336,   128,    51,   338,
      52,    -1,   126,   335,    -1,    51,   335,    52,    -1,   337,
      -1,    29,    -1,    46,    -1,   129,    -1,    30,    -1,   336,
      -1,   338,    58,   336,    -1,    18,   340,    -1,   341,    -1,
     340,   341,    -1,     8,   342,     9,   299,     8,   342,     9,
      -1,   343,    -1,   342,    58,   343,    -1,   344,    39,   345,
      -1,   345,    -1,   218,    -1,   217,    -1,   147,   356,   152,
     360,   354,    -1,   148,   357,   152,   360,   354,    -1,   157,
     363,    -1,   156,   363,    -1,   350,    -1,   355,    -1,   348,
      -1,   351,    -1,   352,    -1,   363,    -1,   353,    -1,   164,
     368,   165,   347,   349,    -1,    -1,   166,   347,    -1,   160,
      -1,   161,   310,    45,   368,    -1,   163,   310,    -1,   163,
      45,   310,    -1,   163,   162,    -1,   163,    45,   162,    -1,
     167,   354,    27,    -1,   347,    -1,   354,   347,    -1,    90,
      46,    -1,    90,   159,    46,    -1,    90,    82,    46,    -1,
      90,   159,    82,    46,    -1,   358,    -1,   356,   358,    -1,
     359,    -1,   357,   359,    -1,   149,    -1,   150,    -1,   151,
      -1,   149,    -1,   153,    -1,   154,    -1,   155,    -1,   151,
      -1,    93,    -1,   150,    -1,   361,    -1,   360,   303,   361,
      -1,   344,    39,   345,    -1,   345,    -1,   344,   146,   344,
     300,    -1,    -1,   158,   218,    51,   364,   365,    52,    -1,
      -1,   366,    -1,   367,    -1,   366,    58,   367,    -1,   368,
      -1,   369,    -1,   368,   123,   368,    -1,   368,   122,   368,
      -1,    56,   368,    -1,    55,   368,    -1,   371,    -1,   126,
     368,    -1,    51,   368,    52,    -1,   370,    51,   365,    52,
      -1,   168,   152,   310,    -1,   368,   121,   368,    -1,   368,
       8,   368,    -1,   368,     9,   368,    -1,   368,    53,   368,
      -1,   368,    55,   368,    -1,   368,    56,   368,    -1,   368,
      54,   368,    -1,   368,    72,   368,    -1,   368,   126,    72,
     368,    -1,   368,    45,   368,    -1,   368,   130,    -1,   368,
     131,    -1,   368,   127,   368,   123,   368,    -1,   368,   128,
      51,   372,    52,    -1,   368,   126,   128,    51,   372,    52,
      -1,   218,    -1,   310,    -1,    29,    -1,    46,    -1,   129,
      -1,    41,    -1,   371,    -1,   372,    58,   371,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   157,   158,   163,   164,   173,   174,   178,
     179,   183,   184,   185,   186,   191,   194,   201,   211,   220,
     233,   241,   251,   259,   272,   273,   278,   281,   284,   277,
     300,   303,   306,   299,   320,   323,   323,   329,   332,   335,
     338,   344,   345,   346,   350,   359,   365,   375,   382,   384,
     386,   388,   390,   392,   397,   407,   407,   410,   410,   423,
     423,   442,   444,   447,   442,   452,   452,   457,   458,   459,
     471,   472,   477,   478,   481,   496,   508,   509,   520,   531,
     544,   556,   567,   572,   575,   583,   584,   590,   589,   611,
     614,   614,   632,   633,   636,   637,   638,   641,   650,   651,
     654,   655,   656,   658,   659,   660,   666,   670,   670,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     690,   689,   711,   712,   713,   717,   721,   717,   907,   908,
     914,   924,   925,   928,   929,   932,   935,   940,   951,   965,
     979,   988,   998,  1007,  1022,  1031,  1040,  1047,  1049,  1052,
    1058,  1059,  1060,  1061,  1064,  1065,  1069,  1070,  1074,  1074,
    1077,  1082,  1104,  1128,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1155,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1171,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1194,  1195,  1197,  1198,  1199,  1200,  1201,  1202,  1208,
    1209,  1210,  1214,  1215,  1219,  1220,  1221,  1222,  1223,  1224,
    1225,  1226,  1228,  1242,  1243,  1244,  1245,  1246,  1247,  1248,
    1252,  1253,  1256,  1256,  1258,  1258,  1261,  1271,  1277,  1277,
    1280,  1281,  1282,  1286,  1286,  1288,  1288,  1291,  1291,  1293,
    1296,  1302,  1305,  1309,  1310,  1314,  1318,  1322,  1326,  1330,
    1337,  1337,  1341,  1344,  1348,  1348,  1351,  1351,  1355,  1356,
    1369,  1377,  1377,  1386,  1390,  1394,  1398,  1402,  1406,  1410,
    1416,  1420,  1424,  1428,  1432,  1436,  1440,  1443,  1450,  1450,
    1454,  1454,  1459,  1459,  1459,  1463,  1470,  1471,  1472,  1473,
    1508,  1509,  1512,  1518,  1525,  1526,  1527,  1528,  1534,  1537,
    1538,  1541,  1542,  1549,  1551,  1556,  1564,  1567,  1568,  1569,
    1570,  1571,  1572,  1573,  1579,  1581,  1582,  1585,  1588,  1592,
    1593,  1594,  1595,  1596,  1597,  1598,  1604,  1606,  1613,  1613,
    1619,  1625,  1626,  1629,  1635,  1636,  1637,  1638,  1639,  1640,
    1641,  1642,  1643,  1644,  1645,  1646,  1647,  1650,  1657,  1658,
    1659,  1664,  1667,  1671,  1683,  1686,  1687,  1691,  1701,  1708,
    1717,  1720,  1732,  1735,  1739,  1746,  1754,  1759,  1767,  1771,
    1776,  1781,  1786,  1791,  1796,  1805,  1814,  1815,  1820,  1823,
    1831,  1837,  1843,  1849,  1858,  1863,  1873,  1883,  1889,  1895,
    1901,  1911,  1923,  1931,  1943,  1951,  1952,  1953,  1957,  1958,
    1959,  1960,  1961,  1962,  1963,  1966,  1973,  1984,  1988,  1995,
    2003,  2003,  2021,  2022,  2028,  2034,  2042,  2049,  2050,  2051,
    2069,  2071,  2072,  2073,  2074,  2075,  2078,  2079,  2080,  2081,
    2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,  2090,  2091,
    2092,  2093,  2096,  2099,  2100,  2101,  2102,  2103,  2106,  2110
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
     318,   318,   318,   319,   319,   319,   319,   319,   320,   320,
     320,   321,   321,   322,   322,   323,   324,   325,   325,   325,
     325,   325,   325,   325,   326,   327,   327,   328,   329,   330,
     330,   330,   330,   330,   330,   330,   331,   331,   332,   332,
     333,   334,   334,   334,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   336,   336,   336,
     336,   337,   338,   338,   339,   340,   340,   341,   342,   342,
     343,   343,   344,   345,   346,   346,   346,   346,   347,   347,
     347,   347,   347,   347,   347,   348,   349,   349,   350,   351,
     352,   352,   352,   352,   353,   354,   354,   355,   355,   355,
     355,   356,   356,   357,   357,   358,   358,   358,   359,   359,
     359,   359,   359,   359,   359,   360,   360,   361,   361,   362,
     364,   363,   365,   365,   366,   366,   367,   368,   368,   368,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   370,   371,   371,   371,   371,   371,   372,   372
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
       1,     3,     3,     1,     1,     1,     1,     1,     0,     3,
       5,     0,     3,     0,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     3,     0,     1,
       2,     1,     3,     3,     3,     3,     3,     3,     4,     3,
       2,     2,     1,     5,     5,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     2,     7,     1,     3,
       3,     1,     1,     1,     5,     5,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     0,     2,     1,     4,
       2,     3,     2,     3,     3,     1,     2,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     4,
       0,     6,     0,     1,     1,     3,     1,     1,     3,     3,
       2,     2,     1,     2,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     2,     2,     5,
       5,     6,     1,     1,     1,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     7,     3,     8,    11,    13,     6,
       1,     0,    57,     0,    92,    16,    15,    55,     0,     0,
       0,     0,    59,    67,    24,    24,    26,    24,    30,    24,
      48,    49,    50,    51,    52,    53,    70,     0,     0,    56,
       0,     9,    10,    12,    14,     0,    67,     0,    58,    61,
      25,    34,    34,    24,    34,    24,    34,    71,    54,    98,
      70,    94,   109,   240,     5,     4,    60,    68,    65,    35,
      44,    44,    34,    44,    34,     0,     0,    97,     0,    93,
      95,   111,   114,   112,   110,   113,   115,   116,   117,   119,
     118,    70,     0,   107,     0,     2,     0,    66,     0,     0,
       0,    45,    46,     0,     0,     0,     0,    24,     0,    21,
       0,   100,    99,    96,   106,   108,   280,   120,     0,     0,
       0,     0,     0,     0,     0,     0,   382,    70,   242,   244,
     251,     0,   247,   252,    69,    62,     0,     0,     0,    38,
      41,     0,    18,    47,    17,    27,    19,    31,    34,    20,
      22,     0,     0,     0,     0,     0,     0,   374,   375,   248,
     246,     0,   415,   416,   417,     0,   411,   423,   418,   424,
     422,   419,   420,   421,     0,   413,     0,   387,   386,   241,
     243,   245,     0,     0,     0,     0,     0,    36,     0,    42,
       0,     0,    44,   105,   101,   102,   104,   125,     0,   122,
       7,     8,   383,     0,   378,     0,   381,   376,     0,     0,
       0,   412,     0,   414,     0,   257,    85,    78,    87,    79,
      80,    84,    83,    82,    77,    74,     0,    75,    72,    81,
      76,    39,    40,    37,    43,     0,     0,     0,     0,     0,
     121,   123,   255,     0,     0,   259,     0,     0,     0,   428,
     263,   425,   263,   430,   258,   429,   274,    63,    73,    86,
      28,    32,    23,   103,     0,     0,   133,   141,   128,   124,
     256,     0,   379,   380,     0,     0,     0,     0,   264,     0,
     398,     0,     0,     0,     0,     0,   405,   390,   388,   391,
     392,   394,   384,   389,   393,   385,   432,   278,   279,     0,
       0,   275,   276,    89,    70,     0,     0,     0,   143,     0,
       0,   138,   132,     0,     0,   126,     0,     0,     0,   265,
     263,   270,   261,     0,   427,   407,     0,     0,     0,     0,
     402,   400,   464,   467,   465,     0,     0,     0,     0,   466,
       0,   280,   463,     0,   437,     0,   442,     0,   426,   406,
       0,   433,   434,   436,    88,    90,   281,   277,    64,    29,
      33,   273,   272,   133,     0,   283,   284,   285,   286,   287,
     288,   318,   318,   335,   321,     0,   293,   294,   295,   296,
     297,   136,   133,     0,   140,     0,   156,     0,   260,     0,
       0,   253,     0,     0,     0,   409,   408,     0,     0,   403,
     401,     0,   441,   440,   443,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,   458,     0,   432,   404,   431,     0,   274,   274,   137,
     142,     0,   289,   290,   339,   340,   341,   342,   343,   344,
     346,   291,     0,   337,   327,   328,   329,   330,   331,   332,
     346,   292,     0,   323,   135,   139,   131,   129,     0,     0,
     127,   377,   269,   267,   268,   266,     0,   257,   262,   271,
       0,   410,   399,   444,   446,   448,   449,   456,   450,   453,
     451,   452,   454,   447,   439,   438,     0,     0,     0,     0,
     396,     0,   435,    91,   282,     0,     0,   345,     0,   333,
       0,     0,   326,     0,     0,   180,     0,     0,   187,   160,
       0,     0,     0,     0,     0,   171,   172,     0,     0,   178,
     183,   182,     0,     0,   186,   189,   188,   192,     0,   181,
       0,     0,   191,   190,     0,     0,   195,   201,     0,     0,
     197,   198,   196,     0,     0,   205,   206,   207,   208,   209,
       0,     0,     0,     0,     0,     0,   157,   158,   254,   249,
       0,   455,     0,     0,   468,     0,     0,   395,   445,   319,
       0,   325,     0,   336,   338,   334,   322,     0,   134,   130,
       0,     0,   144,     0,   147,     0,   151,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   459,   460,     0,
     397,     0,   347,   324,     0,   154,     0,     0,     0,   153,
       0,   232,   224,   225,   226,   227,   228,   229,   230,   231,
     235,   233,   236,   237,   238,   239,   234,   348,   222,   164,
     220,   219,   221,   165,   169,   167,   173,     0,   184,   185,
     217,   175,   176,   177,   218,   202,   199,   200,   204,   203,
       0,   211,   212,   166,   215,   213,   216,   214,   159,     0,
     461,   469,   320,   179,   155,   145,   163,   149,   146,     0,
     150,     0,   223,   161,   349,     0,     0,   315,   302,   314,
     317,   313,     0,     0,     0,   316,   298,   310,   307,   306,
     309,   305,     0,   308,   300,   250,     0,   152,   368,   371,
     369,     0,     0,   370,   350,   351,   362,   367,   170,   168,
     303,   304,   174,     0,     0,     0,   210,     0,   148,     0,
     365,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,   361,   299,   312,   311,   301,   366,   353,   352,
     355,   356,   359,   357,   354,     0,     0,     0,   358,     0,
     372,     0,   363,   364,     0,   373
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   202,   341,     9,    14,    30,    31,    32,
      33,   108,   109,    51,    34,    53,   190,   305,    35,    55,
     191,   306,    70,    99,   140,   141,   100,   101,   102,    15,
      16,    17,    23,    46,    48,    68,   183,   304,    98,    49,
      58,   226,   227,   228,   229,   230,   256,   299,   427,    38,
      60,    61,    77,   112,    63,    91,    92,    93,   155,   198,
     199,   239,   386,   315,   311,   312,   268,   581,   582,   583,
     688,   587,   627,   460,   556,   557,   653,   647,   648,    95,
     127,   128,   129,   208,   467,   271,   255,   246,   320,   285,
     321,   322,   363,   300,   301,   302,   342,   303,   428,   381,
     704,   712,   705,   714,   706,   707,   432,   451,   502,   572,
     452,   453,   576,   441,   442,   573,   443,   497,   693,   694,
     724,   725,   726,   727,   771,   130,   157,   158,   203,   204,
     205,   206,   132,   286,   287,   567,   288,   289,   290,   291,
     292,   293,   165,   174,   166,   175,   250,   251,   133,   294,
     296,   350,   351,   352,   353,   344,   345,   346,   565
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -647
static const yytype_int16 yypact[] =
{
       4,   -17,    63,   -21,  -647,    91,  -647,   135,   149,   158,
    -647,   179,  -647,   289,    79,  -647,   205,  -647,   197,    57,
      57,   223,  -647,   253,    57,    57,  -647,    57,  -647,    57,
    -647,  -647,  -647,  -647,  -647,  -647,   249,    57,   260,  -647,
     247,  -647,  -647,  -647,  -647,   259,   253,   277,  -647,  -647,
    -647,   266,   266,    57,   266,    57,   266,  -647,  -647,   274,
      19,  -647,   652,   302,  -647,  -647,  -647,   319,   172,  -647,
     289,   289,   266,   289,   266,   174,    51,  -647,    57,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,    -7,    57,  -647,   345,  -647,   321,  -647,   330,   102,
     338,   289,  -647,   341,   365,   372,   374,    57,   -18,  -647,
     363,   371,  -647,  -647,  -647,  -647,  -647,  -647,   364,   359,
     376,   367,   263,   407,   262,   262,  -647,   241,  -647,   403,
    -647,   307,  -647,  -647,  -647,  -647,   411,   429,   433,  -647,
    -647,    40,  -647,  -647,  -647,  -647,  -647,  -647,   266,  -647,
    -647,    57,    57,    57,    57,   434,    59,   364,  -647,  -647,
    -647,   447,  -647,  -647,  -647,   101,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   378,  -647,    57,  -647,  -647,  -647,
    -647,  -647,    57,   509,   435,   450,   436,  -647,   102,  -647,
     509,   509,   289,  -647,  -647,   446,  -647,  -647,   167,  -647,
     452,   457,  -647,     7,  -647,   458,  -647,  -647,    57,   427,
      59,  -647,    59,  -647,   455,   451,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,   431,  -647,  -647,   491,
    -647,  -647,  -647,  -647,  -647,   473,   478,   482,    57,    42,
     434,  -647,   459,    59,    77,   485,   462,   486,   475,  -647,
     151,  -647,   151,  -647,  -647,  -647,   110,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,   477,    57,   -23,   479,   494,  -647,
    -647,   513,  -647,  -647,   505,    52,   471,    77,  -647,     8,
    -647,    57,     0,    -3,   291,    59,  -647,  -647,  -647,  -647,
    -647,  -647,   291,  -647,  -647,   291,    -3,  -647,  -647,    22,
      57,   110,  -647,  -647,   249,   510,   511,     2,   497,   710,
     498,  -647,   416,    57,   515,  -647,    59,   517,   507,   520,
     215,   490,  -647,   441,  -647,  -647,   506,   153,   518,    -2,
    -647,  -647,  -647,  -647,  -647,    -3,    -3,    -3,    -3,  -647,
     402,   514,  -647,   177,  -647,   516,  -647,    76,  -647,  -647,
     512,   519,  -647,   583,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   521,    57,  -647,  -647,  -647,  -647,  -647,
    -647,   523,   523,   651,   734,    57,  -647,  -647,  -647,  -647,
    -647,  -647,   521,   529,  -647,    27,   522,    55,  -647,    53,
      71,   461,    52,    52,   527,  -647,  -647,   533,    -3,  -647,
    -647,   560,   583,   583,   583,    57,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,   -32,    -3,   531,
    -647,  -647,   291,    -3,  -647,  -647,    -3,   110,   110,  -647,
    -647,   555,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     534,  -647,   487,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     534,  -647,   488,   535,   548,  -647,  -647,  -647,   559,   234,
    -647,  -647,  -647,  -647,  -647,  -647,   460,   451,  -647,  -647,
     572,  -647,   583,  -647,  -647,   640,   640,   583,   583,   583,
     583,   583,   583,   583,   583,   583,    -3,   551,   595,    75,
     440,   558,  -647,  -647,  -647,   238,   590,  -647,   651,  -647,
     734,   598,  -647,    57,   596,   605,    57,   152,  -647,  -647,
     586,   589,   597,   563,   569,  -647,  -647,   599,   600,  -647,
    -647,  -647,   607,   611,  -647,  -647,  -647,   184,   614,  -647,
     615,   616,  -647,  -647,   619,   620,  -647,  -647,   621,   623,
    -647,  -647,  -647,   624,   626,  -647,  -647,  -647,  -647,  -647,
     629,   630,   633,   634,   635,   644,   585,  -647,  -647,  -647,
     604,   583,    75,    -3,  -647,   297,   291,  -647,  -647,  -647,
     663,  -647,   646,  -647,  -647,  -647,  -647,   647,  -647,  -647,
     656,    60,  -647,   657,  -647,    57,   664,  -647,   730,   661,
      10,    57,    57,   662,   668,   669,   674,  -647,  -647,   678,
     681,   682,    57,   683,   684,   191,   702,   703,   685,   705,
     706,    10,   129,   181,   234,   708,   333,   583,  -647,    75,
    -647,   689,  -647,  -647,   731,  -647,   196,   152,    57,   725,
      57,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   671,  -647,  -647,
    -647,  -647,  -647,  -647,   726,   751,  -647,   231,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     617,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   717,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   752,  -647,    57,
    -647,   228,  -647,  -647,  -647,    57,    57,  -647,  -647,  -647,
    -647,  -647,   763,   764,   335,  -647,  -647,   -25,  -647,  -647,
    -647,  -647,   342,  -647,  -647,  -647,    57,  -647,  -647,  -647,
    -647,   228,   228,  -647,  -647,   304,   612,  -647,  -647,  -647,
    -647,  -647,  -647,   231,   231,   231,  -647,   617,  -647,   742,
    -647,   228,   228,    82,    82,    82,    82,    82,   723,    82,
     746,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,    82,   675,    82,  -647,    82,
    -647,   343,  -647,  -647,    82,  -647
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -647,  -647,  -647,   798,   -19,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   692,   337,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,     6,  -647,    54,  -647,   -40,  -647,     1,  -647,
    -647,   785,  -647,  -647,   756,  -647,  -647,  -647,  -647,  -647,
     -56,   251,  -647,   141,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   130,  -647,  -647,  -647,  -647,  -647,   727,  -647,  -647,
    -147,  -647,  -647,  -647,  -321,  -647,  -647,  -647,   193,  -647,
    -647,   198,  -647,  -647,  -647,   206,   221,  -647,   187,  -647,
    -647,   699,  -647,  -647,  -647,  -647,   368,  -647,  -647,   524,
     448,   453,  -647,   415,  -647,   545,   -85,   420,  -647,  -647,
    -647,  -647,  -646,   111,   119,  -275,   483,  -647,  -647,  -647,
    -647,   354,  -647,  -647,  -647,  -647,   358,   413,  -647,  -647,
    -647,  -362,    84,  -647,  -647,  -647,  -647,   700,   557,   618,
     -83,   134,  -647,  -273,  -647,  -647,  -647,  -647,  -647,  -647,
    -205,  -647,  -647,  -647,   709,   690,   665,   591,  -647,   348,
    -647,   456,  -647,   449,  -268,  -647,  -647,  -468,   316
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -463
static const yytype_int16 yytable[] =
{
      43,    44,    11,    12,    79,    50,    50,   117,    50,   149,
      50,   131,   734,     4,    36,   343,   242,     5,    59,   349,
      57,   564,   349,  -109,   713,     1,   332,    41,    41,   361,
      41,   103,    41,   105,    50,   114,    50,   309,   333,   650,
     486,    59,   429,   334,   131,   329,    57,   295,   335,    41,
     354,   241,   336,   337,   325,   457,   651,   111,    71,    59,
      73,   455,    75,    10,   461,   243,   355,   401,   402,   403,
     404,   179,    41,   116,   349,   126,   264,    78,   104,   347,
     106,    41,    41,    41,   735,   458,   318,    41,    50,   200,
     326,   713,   187,   269,   564,   265,   487,   110,   188,   215,
       6,    41,   143,   424,   332,    41,   462,     4,   126,   625,
    -109,   718,   719,   243,    42,    42,   333,    42,   626,    42,
     310,   334,    37,   338,   464,   652,   339,   248,   720,   248,
     472,    18,   193,   194,   195,   196,    42,   126,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   490,
     488,   681,   237,   136,   192,     7,   107,   214,   674,    42,
     399,    13,   330,   126,   225,   340,   279,   327,    42,    42,
      42,   225,   225,    19,    42,   675,   201,    81,    82,    83,
      84,    85,    41,    86,   266,   406,   407,    20,    42,   245,
      80,   126,    42,   126,     6,   189,   328,   331,    21,   396,
      87,    88,   248,    89,   339,   585,    90,   225,   113,   278,
     676,   723,   197,   137,   240,   136,   225,   225,   561,   263,
     267,   138,   408,   139,   126,    22,    41,   677,    11,    12,
     409,   410,   411,   412,   176,   397,   280,   281,    40,   282,
     283,   279,   234,   284,   400,   684,   308,   697,   358,   413,
     162,   163,   164,   210,   297,   298,   319,   718,   719,   118,
     698,   699,   116,   116,    45,   119,   126,   391,    57,    42,
     505,    41,   700,   278,   720,   137,    57,   701,    47,   721,
      62,   356,   506,   138,   507,   139,   702,   703,   362,    64,
     569,   597,   598,   620,   384,   617,   570,   126,   414,   415,
     416,    65,   120,   417,   418,   419,    67,   420,   421,   176,
     116,   280,   281,    42,   282,   283,   508,    69,   284,    76,
     474,    94,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,    96,   422,    97,   249,   430,   249,   528,   107,   618,
     134,   529,   530,   531,   722,   619,   454,   723,    42,   739,
     740,   135,    52,   118,    54,   142,    56,   258,   144,   119,
     463,   465,   156,   319,   319,    41,   258,   258,   273,   758,
     759,   279,   121,   666,   667,   680,   116,   732,   122,   123,
      72,   619,    74,   733,   736,   773,   145,   124,   125,   146,
     737,   774,   151,   532,   533,   147,   120,   534,   152,   153,
     154,   324,   162,   163,   164,   535,   159,   536,   161,   249,
     176,   584,   160,   537,   538,   539,   741,   742,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   235,   236,   553,   148,   554,   555,   216,   217,   176,
     181,   280,   281,   182,   282,   283,   184,   218,   284,   754,
     755,    41,    42,   257,    24,    25,    26,    27,    28,    29,
     116,   167,   177,   178,   185,   219,   209,   220,   186,   197,
     232,   231,   233,   238,   578,   247,   121,   116,   586,   216,
     217,    -9,   122,   123,   216,   217,   -10,   244,   254,   218,
     167,   124,   125,    41,   218,   260,   253,   259,    41,   262,
     261,   274,   270,   275,   277,   276,   307,   219,   313,   220,
     314,   316,   219,   323,   220,   216,   217,   168,   169,   170,
     212,   171,   172,   173,   317,   218,   364,   359,   360,    41,
     382,   584,   383,   116,   385,   388,   389,   221,    42,   393,
     394,   222,   395,   219,   405,   220,   168,   169,   170,   390,
     171,   172,   173,   398,   425,  -462,   629,   423,   406,   407,
     456,   466,   654,   655,   431,   223,   224,   426,   470,   471,
     459,   309,   489,   663,   495,   496,   501,   503,   504,   221,
      42,   406,   407,   222,   221,    42,   498,   500,   222,   558,
     116,   560,   562,   406,   407,   408,   566,   116,   586,   687,
     568,   690,   473,   409,   410,   411,   412,   223,   224,   571,
     743,   744,   223,   224,   579,   221,    42,   577,   408,   222,
     580,   588,   413,   708,   589,   591,   409,   410,   411,   412,
     408,   592,   590,   614,   593,   594,   698,   709,   409,   410,
     411,   412,   595,   223,   224,   413,   596,   745,   710,   599,
     600,   601,   615,   711,   602,   603,   604,   413,   605,   606,
     717,   607,   702,   703,   608,   609,   728,   729,   610,   611,
     612,   414,   415,   416,   746,   408,   417,   418,   419,   613,
     420,   421,   621,   409,   410,   411,   412,   738,   622,   623,
     631,   624,   628,   630,   414,   415,   416,   649,   656,   417,
     418,   419,   413,   420,   421,   658,   414,   415,   563,   657,
     659,   417,   418,   419,   660,   420,   421,   661,   662,   664,
     665,   668,   669,   747,   671,   672,   670,   679,   748,   749,
     750,   682,   751,   752,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   631,
     683,   414,   415,   416,   689,   695,   417,   418,   419,   715,
     420,   421,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   434,   435,   436,   437,   438,   439,   440,
     696,   716,   730,   731,   757,   765,   691,   767,   769,     8,
     150,    39,    66,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   115,   685,
     678,   376,   377,   378,   379,   686,   180,   760,   761,   762,
     763,   764,   673,   766,   692,   559,    81,    82,    83,    84,
      85,   469,    86,   494,   392,   468,   357,   493,   756,   768,
     380,   770,   753,   772,   575,   433,   574,   207,   775,    87,
      88,   272,    89,   499,   213,    90,   444,   445,   446,   447,
     448,   449,   450,   387,   211,   492,   348,   252,   616,   491
};

static const yytype_uint16 yycheck[] =
{
      19,    20,    23,    24,    60,    24,    25,    92,    27,    27,
      29,    94,    37,    30,    13,   283,     9,    34,    37,   292,
      27,   489,   295,    30,   670,    21,    29,    30,    30,    27,
      30,    71,    30,    73,    53,    91,    55,    60,    41,    29,
      72,    60,   363,    46,   127,    45,    27,   252,    51,    30,
      28,   198,    55,    56,    46,    28,    46,    76,    52,    78,
      54,   382,    56,     0,     9,    58,    44,   335,   336,   337,
     338,   127,    30,    92,   347,    94,    34,    58,    72,   284,
      74,    30,    30,    30,   109,    58,    34,    30,   107,    30,
      82,   737,    52,   240,   562,    53,   128,    46,    58,   182,
     117,    30,   101,    27,    29,    30,    53,    30,   127,    49,
     117,    29,    30,    58,   117,   117,    41,   117,    58,   117,
     143,    46,    43,   126,    53,   115,   129,   210,    46,   212,
     398,    40,   151,   152,   153,   154,   117,   156,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   422,
     418,   619,   192,   113,   148,   172,   174,   176,    29,   117,
     162,   182,   162,   182,   183,   168,    90,   159,   117,   117,
     117,   190,   191,    38,   117,    46,   117,   184,   185,   186,
     187,   188,    30,   190,   142,     8,     9,    38,   117,   208,
      60,   210,   117,   212,   117,   141,   281,   282,    40,    46,
     207,   208,   285,   210,   129,    53,   213,   226,    78,    58,
      29,   129,    45,   173,    47,   113,   235,   236,   486,   238,
     239,   181,    45,   183,   243,    46,    30,    46,    23,    24,
      53,    54,    55,    56,   158,    82,   160,   161,    41,   163,
     164,    90,   188,   167,   329,    49,   265,    16,   304,    72,
     149,   150,   151,   152,   144,   145,   275,    29,    30,    18,
      29,    30,   281,   282,    41,    24,   285,    52,    27,   117,
      36,    30,    41,    58,    46,   173,    27,    46,    25,    51,
      20,   300,    48,   181,    50,   183,    55,    56,   307,    42,
      52,   107,   108,   566,   313,   563,    58,   316,   121,   122,
     123,    42,    61,   126,   127,   128,    29,   130,   131,   158,
     329,   160,   161,   117,   163,   164,    82,    51,   167,    45,
     405,    19,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    22,   165,   171,   210,   364,   212,   113,   174,    52,
      29,   117,   118,   119,   126,    58,   375,   129,   117,   721,
     722,    31,    25,    18,    27,    27,    29,   226,    27,    24,
     389,   390,     8,   392,   393,    30,   235,   236,   244,   741,
     742,    90,   141,   192,   193,    52,   405,    52,   147,   148,
      53,    58,    55,    58,    52,    52,    31,   156,   157,    27,
      58,    58,    39,   169,   170,    31,    61,   173,    37,    38,
      39,   277,   149,   150,   151,   181,    57,   183,    51,   285,
     158,   506,    46,   189,   190,   191,   122,   123,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   190,   191,   209,   107,   211,   212,    16,    17,   158,
      47,   160,   161,   146,   163,   164,    45,    26,   167,   734,
     735,    30,   117,    32,   175,   176,   177,   178,   179,   180,
     489,    93,   124,   125,    45,    44,    29,    46,    45,    45,
      30,    46,    46,    37,   503,    58,   141,   506,   507,    16,
      17,    39,   147,   148,    16,    17,    39,    39,    47,    26,
      93,   156,   157,    30,    26,    32,    51,    16,    30,    27,
      32,    26,    53,    51,    39,    29,    39,    44,    39,    46,
      26,     8,    44,    52,    46,    16,    17,   149,   150,   151,
     152,   153,   154,   155,    29,    26,    39,    27,    27,    30,
      42,   626,   126,   562,    29,    28,    39,   116,   117,    59,
     109,   120,    46,    44,   152,    46,   149,   150,   151,    39,
     153,   154,   155,    45,    52,    51,   585,    51,     8,     9,
      41,   110,   591,   592,    51,   144,   145,    58,    51,    46,
      58,    60,    51,   602,    29,    51,    51,    39,    29,   116,
     117,     8,     9,   120,   116,   117,   109,   109,   120,   139,
     619,    29,    51,     8,     9,    45,   166,   626,   627,   628,
      52,   630,    52,    53,    54,    55,    56,   144,   145,    29,
       8,     9,   144,   145,    28,   116,   117,    29,    45,   120,
      25,    45,    72,    16,    45,    72,    53,    54,    55,    56,
      45,    72,    45,    58,    45,    45,    29,    30,    53,    54,
      55,    56,    45,   144,   145,    72,    45,    45,    41,    45,
      45,    45,    58,    46,    45,    45,    45,    72,    45,    45,
     689,    45,    55,    56,    45,    45,   695,   696,    45,    45,
      45,   121,   122,   123,    72,    45,   126,   127,   128,    45,
     130,   131,    29,    53,    54,    55,    56,   716,    52,    52,
      29,    45,    45,    39,   121,   122,   123,    46,    46,   126,
     127,   128,    72,   130,   131,    46,   121,   122,   123,    51,
      46,   126,   127,   128,    46,   130,   131,    46,    46,    46,
      46,    29,    29,   121,    29,    29,    51,    29,   126,   127,
     128,    52,   130,   131,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    29,
      29,   121,   122,   123,    39,    39,   126,   127,   128,    52,
     130,   131,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   132,   133,   134,   135,   136,   137,   138,
      39,    39,    29,    29,    52,    72,   125,    51,   123,     1,
     108,    16,    46,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    91,   626,
     614,   111,   112,   113,   114,   627,   127,   743,   744,   745,
     746,   747,   611,   749,   647,   467,   184,   185,   186,   187,
     188,   393,   190,   428,   320,   392,   301,   427,   737,   765,
     140,   767,   733,   769,   500,   372,   498,   157,   774,   207,
     208,   243,   210,   450,   174,   213,   132,   133,   134,   135,
     136,   137,   138,   316,   165,   426,   285,   212,   562,   423
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   215,   216,    30,    34,   117,   172,   217,   219,
       0,    23,    24,   182,   220,   243,   244,   245,    40,    38,
      38,    40,    46,   246,   175,   176,   177,   178,   179,   180,
     221,   222,   223,   224,   228,   232,   242,    43,   263,   245,
      41,    30,   117,   218,   218,    41,   247,    25,   248,   253,
     218,   227,   227,   229,   227,   233,   227,    27,   254,   218,
     264,   265,    20,   268,    42,    42,   248,    29,   249,    51,
     236,   236,   227,   236,   227,   236,    45,   266,    58,   254,
     265,   184,   185,   186,   187,   188,   190,   207,   208,   210,
     213,   269,   270,   271,    19,   293,    22,   171,   252,   237,
     240,   241,   242,   240,   236,   240,   236,   174,   225,   226,
      46,   218,   267,   265,   254,   271,   218,   310,    18,    24,
      61,   141,   147,   148,   156,   157,   218,   294,   295,   296,
     339,   344,   346,   362,    29,    31,   113,   173,   181,   183,
     238,   239,    27,   242,    27,    31,    27,    31,   227,    27,
     226,    39,    37,    38,    39,   272,     8,   340,   341,    57,
      46,    51,   149,   150,   151,   356,   358,    93,   149,   150,
     151,   153,   154,   155,   357,   359,   158,   363,   363,   254,
     295,    47,   146,   250,    45,    45,    45,    52,    58,   238,
     230,   234,   236,   218,   218,   218,   218,    45,   273,   274,
      30,   117,   217,   342,   343,   344,   345,   341,   297,    29,
     152,   358,   152,   359,   218,   344,    16,    17,    26,    44,
      46,   116,   120,   144,   145,   218,   255,   256,   257,   258,
     259,    46,    30,    46,   238,   255,   255,   240,    37,   275,
      47,   274,     9,    58,    39,   218,   301,    58,   344,   345,
     360,   361,   360,    51,    47,   300,   260,    32,   257,    16,
      32,    32,    27,   218,    34,    53,   142,   218,   280,   274,
      53,   299,   343,   345,    26,    51,    29,    39,    58,    90,
     160,   161,   163,   164,   167,   303,   347,   348,   350,   351,
     352,   353,   354,   355,   363,   354,   364,   144,   145,   261,
     307,   308,   309,   311,   251,   231,   235,    39,   218,    60,
     143,   278,   279,    39,    26,   277,     8,    29,    34,   218,
     302,   304,   305,    52,   345,    46,    82,   159,   310,    45,
     162,   310,    29,    41,    46,    51,    55,    56,   126,   129,
     168,   218,   310,   368,   369,   370,   371,   354,   361,   347,
     365,   366,   367,   368,    28,    44,   218,   309,   254,    27,
      27,    27,   218,   306,    39,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,   111,   112,   113,   114,
     140,   313,    42,   126,   218,    29,   276,   342,    28,    39,
      39,    52,   303,    59,   109,    46,    46,    82,    45,   162,
     310,   368,   368,   368,   368,   152,     8,     9,    45,    53,
      54,    55,    56,    72,   121,   122,   123,   126,   127,   128,
     130,   131,   165,    51,    27,    52,    58,   262,   312,   278,
     218,    51,   320,   320,   132,   133,   134,   135,   136,   137,
     138,   327,   328,   330,   132,   133,   134,   135,   136,   137,
     138,   321,   324,   325,   218,   278,    41,    28,    58,    58,
     287,     9,    53,   218,    53,   218,   110,   298,   305,   304,
      51,    46,   368,    52,   310,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,    72,   128,   368,    51,
     347,   365,   367,   311,   307,    29,    51,   331,   109,   331,
     109,    51,   322,    39,    29,    36,    48,    50,    82,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   113,   117,
     118,   119,   169,   170,   173,   181,   183,   189,   190,   191,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   209,   211,   212,   288,   289,   139,   300,
      29,   368,    51,   123,   371,   372,   166,   349,    52,    52,
      58,    29,   323,   329,   330,   325,   326,    29,   218,    28,
      25,   281,   282,   283,   310,    53,   218,   285,    45,    45,
      45,    72,    72,    45,    45,    45,    45,   107,   108,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    58,    58,   372,   368,    52,    58,
     347,    29,    52,    52,    45,    49,    58,   286,    45,   218,
      39,    29,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   291,   292,    46,
      29,    46,   115,   290,   218,   218,    46,    51,    46,    46,
      46,    46,    46,   218,    46,    46,   192,   193,    29,    29,
      51,    29,    29,   290,    29,    46,    29,    46,   289,    29,
      52,   371,    52,    29,    49,   282,   285,   218,   284,    39,
     218,   125,   292,   332,   333,    39,    39,    16,    29,    30,
      41,    46,    55,    56,   314,   316,   318,   319,    16,    30,
      41,    46,   315,   316,   317,    52,    39,   218,    29,    30,
      46,    51,   126,   129,   334,   335,   336,   337,   218,   218,
      29,    29,    52,    58,    37,   109,    52,    58,   218,   335,
     335,   122,   123,     8,     9,    45,    72,   121,   126,   127,
     128,   130,   131,   318,   319,   319,   317,    52,   335,   335,
     336,   336,   336,   336,   336,    72,   336,    51,   336,   123,
     336,   338,   336,    52,    58,   336
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

  case 11:

/* Line 1455 of yacc.c  */
#line 183 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 184 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 186 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 191 "screen.yacc"
    {
			the_form.layout=NULL;
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 194 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 201 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 211 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 220 "screen.yacc"
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
#line 233 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 241 "screen.yacc"
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
#line 251 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 259 "screen.yacc"
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
#line 272 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 278 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 281 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 284 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 285 "screen.yacc"
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
#line 300 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 303 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 306 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 307 "screen.yacc"
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
#line 320 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 323 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 323 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 329 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 332 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 335 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 338 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 350 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 359 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 365 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 375 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 383 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 385 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 387 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 389 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 391 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 393 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 399 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(2) - (3)].layout);
	}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 410 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 423 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 442 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 444 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 447 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 452 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 459 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 481 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 496 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 508 "screen.yacc"
    { ltab=0; }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 509 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 520 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 531 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 544 "screen.yacc"
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
#line 556 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 567 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 572 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 575 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 583 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 584 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 590 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 597 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 611 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 614 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 625 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 641 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 650 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 651 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 654 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 655 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 657 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 658 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 659 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 675 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 676 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 677 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 678 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 679 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 680 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 681 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 682 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 683 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 684 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 685 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 690 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 696 "screen.yacc"
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

  case 125:

/* Line 1455 of yacc.c  */
#line 717 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 721 "screen.yacc"
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

  case 127:

/* Line 1455 of yacc.c  */
#line 731 "screen.yacc"
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

  case 129:

/* Line 1455 of yacc.c  */
#line 908 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 914 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 924 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 925 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 928 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 929 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 932 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 935 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 940 "screen.yacc"
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

  case 138:

/* Line 1455 of yacc.c  */
#line 951 "screen.yacc"
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

  case 139:

/* Line 1455 of yacc.c  */
#line 965 "screen.yacc"
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

  case 140:

/* Line 1455 of yacc.c  */
#line 979 "screen.yacc"
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

  case 141:

/* Line 1455 of yacc.c  */
#line 988 "screen.yacc"
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

  case 142:

/* Line 1455 of yacc.c  */
#line 998 "screen.yacc"
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

  case 143:

/* Line 1455 of yacc.c  */
#line 1007 "screen.yacc"
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

  case 144:

/* Line 1455 of yacc.c  */
#line 1022 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 1031 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1040 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1049 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1052 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1058 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1059 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1060 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1061 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1077 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1082 "screen.yacc"
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

  case 162:

/* Line 1455 of yacc.c  */
#line 1104 "screen.yacc"
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

  case 163:

/* Line 1455 of yacc.c  */
#line 1128 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1136 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1137 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1138 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1139 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1140 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1141 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1142 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1143 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1144 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1145 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1146 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1147 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1148 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1149 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1150 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1151 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1152 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1153 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1155 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1157 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1158 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1159 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1160 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1161 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1162 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1163 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1164 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1165 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1166 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1167 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1171 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1178 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1179 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1180 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1181 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1182 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1183 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1184 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1185 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1186 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1187 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1188 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1189 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1190 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1191 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1192 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1193 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1194 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1195 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1197 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1198 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1199 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1200 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1201 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1202 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1208 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1209 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1210 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1215 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1219 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1220 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1221 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1222 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1223 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1224 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1225 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1226 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1228 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 1242 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1243 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1244 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1245 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1246 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1247 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1248 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1261 "screen.yacc"
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

/* Line 1455 of yacc.c  */
#line 1271 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1277 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1288 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1288 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1293 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1296 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1302 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1305 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1315 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1319 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1323 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1327 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1331 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1337 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1341 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1344 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1348 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1348 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1355 "screen.yacc"
    {colno++;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1356 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1369 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1377 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1379 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1386 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1390 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1394 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1398 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1402 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1406 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1410 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1416 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1420 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1424 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1428 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1432 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1436 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1440 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1443 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1450 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1454 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1459 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1463 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1470 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1471 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1473 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1509 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1512 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1518 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1525 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1526 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1527 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1528 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1534 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1537 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1538 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1541 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1543 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1549 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1551 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1556 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1564 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1567 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1568 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1569 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1570 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1571 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1572 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1574 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1581 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1582 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1585 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1588 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1592 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1593 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1594 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1595 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1596 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1597 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1599 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1604 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1606 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1613 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 1613 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1619 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1626 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1629 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 1635 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 1636 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 1637 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1638 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1639 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1640 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1641 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1642 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1643 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1644 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1645 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1646 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1647 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1650 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1657 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 1658 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1659 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 1667 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 1671 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1691 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1701 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1708 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 1717 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 1720 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1739 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1746 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1754 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1759 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1767 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1771 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1776 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1781 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1786 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1791 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1796 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1805 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 1814 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1815 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1824 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1832 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1838 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1844 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1850 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1858 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1863 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1873 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1883 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1889 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1895 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 1901 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1911 "screen.yacc"
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

  case 412:

/* Line 1455 of yacc.c  */
#line 1923 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1931 "screen.yacc"
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
#line 1943 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1951 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1952 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1953 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1957 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1958 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1959 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1960 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1961 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1962 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1963 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1966 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1973 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1984 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 1988 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 1995 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2003 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2009 "screen.yacc"
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

  case 432:

/* Line 1455 of yacc.c  */
#line 2021 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2022 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2028 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2034 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2042 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2050 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2051 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2069 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2071 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2072 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2073 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2074 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2075 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2078 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2079 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2080 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2081 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2082 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2083 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2084 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2085 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2086 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2087 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2088 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2089 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2090 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2091 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2092 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2093 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2099 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2100 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2101 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2102 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2103 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2106 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2110 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1455 of yacc.c  */
#line 6457 "y.tab.c"
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
#line 2122 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




