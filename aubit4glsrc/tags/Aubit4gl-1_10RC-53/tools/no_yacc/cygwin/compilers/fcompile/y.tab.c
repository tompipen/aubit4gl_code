
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   854

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  159
/* YYNRULES -- Number of rules.  */
#define YYNRULES  467
/* YYNRULES -- Number of states.  */
#define YYNSTATES  773

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
      33,    37,    39,    43,    45,    47,    53,    59,    65,    71,
      73,    76,    82,    83,    85,    86,    87,    88,    99,   100,
     101,   102,   113,   114,   115,   120,   124,   126,   130,   134,
     136,   139,   143,   144,   146,   148,   151,   153,   155,   157,
     159,   161,   163,   167,   169,   172,   173,   177,   178,   183,
     184,   185,   186,   196,   197,   199,   200,   203,   208,   209,
     211,   213,   216,   218,   220,   222,   224,   226,   228,   230,
     232,   234,   236,   238,   240,   243,   244,   249,   251,   252,
     257,   258,   262,   264,   267,   271,   274,   275,   278,   280,
     284,   288,   294,   298,   302,   306,   308,   311,   312,   314,
     316,   318,   320,   322,   324,   326,   328,   330,   332,   333,
     339,   341,   344,   348,   349,   350,   357,   358,   362,   368,
     372,   374,   375,   381,   385,   388,   393,   396,   401,   405,
     407,   412,   415,   417,   421,   425,   427,   431,   433,   437,
     439,   444,   447,   449,   452,   453,   456,   458,   462,   464,
     469,   472,   477,   481,   485,   489,   493,   499,   503,   509,
     511,   513,   517,   523,   527,   531,   535,   537,   542,   544,
     546,   548,   550,   554,   558,   560,   562,   564,   566,   568,
     570,   572,   575,   578,   580,   582,   584,   586,   590,   594,
     596,   600,   604,   608,   610,   612,   614,   616,   618,   624,
     628,   632,   636,   640,   644,   648,   652,   656,   658,   660,
     662,   664,   667,   669,   671,   673,   675,   677,   679,   681,
     683,   685,   687,   689,   691,   693,   695,   697,   699,   700,
     704,   706,   709,   711,   714,   717,   719,   720,   730,   743,
     745,   747,   748,   751,   752,   754,   755,   757,   759,   764,
     766,   770,   771,   773,   775,   779,   783,   787,   791,   793,
     797,   799,   801,   802,   804,   806,   809,   811,   813,   815,
     816,   821,   823,   825,   827,   829,   831,   833,   836,   839,
     842,   845,   847,   849,   851,   853,   855,   857,   861,   863,
     867,   869,   872,   875,   877,   879,   881,   883,   885,   887,
     891,   895,   897,   899,   901,   903,   905,   906,   910,   916,
     917,   921,   922,   926,   928,   931,   933,   935,   937,   939,
     941,   943,   946,   948,   949,   953,   955,   957,   959,   961,
     963,   965,   967,   969,   972,   973,   977,   978,   980,   983,
     985,   989,   993,   997,  1001,  1005,  1009,  1014,  1018,  1021,
    1024,  1026,  1032,  1038,  1041,  1045,  1047,  1049,  1051,  1053,
    1055,  1057,  1061,  1064,  1066,  1069,  1077,  1079,  1083,  1087,
    1089,  1091,  1093,  1099,  1105,  1108,  1111,  1113,  1115,  1117,
    1119,  1121,  1123,  1125,  1131,  1132,  1135,  1137,  1142,  1145,
    1149,  1152,  1156,  1160,  1162,  1165,  1168,  1172,  1176,  1181,
    1183,  1186,  1188,  1191,  1193,  1195,  1197,  1199,  1201,  1203,
    1205,  1207,  1209,  1211,  1213,  1217,  1221,  1223,  1228,  1229,
    1236,  1237,  1239,  1241,  1245,  1247,  1249,  1253,  1257,  1260,
    1263,  1265,  1268,  1272,  1277,  1281,  1285,  1289,  1293,  1297,
    1301,  1305,  1309,  1313,  1318,  1322,  1325,  1328,  1334,  1340,
    1347,  1349,  1351,  1353,  1355,  1357,  1359,  1361
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     215,     0,    -1,   216,   220,   263,   268,   293,    -1,    21,
      34,    -1,    21,   219,    40,    41,    42,    -1,    21,    34,
      40,    41,    42,    -1,    21,   219,    -1,    30,    -1,    30,
      -1,   172,    -1,   172,    38,   218,    -1,   217,    -1,   217,
      38,   218,    -1,   244,    -1,   243,    -1,   176,   227,   236,
     240,    27,    -1,   175,   227,   236,   240,    27,    -1,   178,
     227,   236,   240,    27,    -1,   180,   227,   236,   225,    27,
      -1,   226,    -1,   225,   226,    -1,   174,   227,   236,   240,
      27,    -1,    -1,   218,    -1,    -1,    -1,    -1,   177,   229,
     227,   236,    31,   230,   255,    32,   231,    27,    -1,    -1,
      -1,    -1,   179,   233,   227,   236,    31,   234,   255,    32,
     235,    27,    -1,    -1,    -1,    51,   237,   239,    52,    -1,
     181,    45,    46,    -1,   183,    -1,   113,    45,    46,    -1,
     173,    45,    30,    -1,   238,    -1,   239,   238,    -1,   239,
      58,   238,    -1,    -1,   241,    -1,   242,    -1,   241,   242,
      -1,   221,    -1,   222,    -1,   223,    -1,   224,    -1,   228,
      -1,   232,    -1,   182,   242,   254,    -1,   245,    -1,   244,
     245,    -1,    -1,    24,   246,   248,    -1,    -1,    23,    46,
     247,   248,    -1,    -1,    -1,    -1,   253,   249,   252,    31,
     250,   255,    32,   251,   254,    -1,    -1,   171,    -1,    -1,
      25,    29,    -1,    25,    29,    22,    29,    -1,    -1,    27,
      -1,   257,    -1,   255,   257,    -1,   218,    -1,   256,    -1,
     259,    -1,   145,    -1,    17,    -1,    44,    -1,    46,    -1,
     258,    -1,   144,    -1,   120,    -1,   116,    -1,    16,    -1,
     258,    16,    -1,    -1,    26,   260,   261,    28,    -1,   311,
      -1,    -1,   261,    44,   262,   311,    -1,    -1,    43,   264,
     254,    -1,   265,    -1,   264,   265,    -1,   264,    58,   265,
      -1,   218,   266,    -1,    -1,    45,   267,    -1,   218,    -1,
     218,    37,   218,    -1,   218,    38,   218,    -1,   218,    38,
     218,    37,   218,    -1,   218,    39,   218,    -1,    46,    39,
     218,    -1,    20,   269,   254,    -1,   271,    -1,   269,   271,
      -1,    -1,   187,    -1,   184,    -1,   186,    -1,   188,    -1,
     185,    -1,   190,    -1,   207,    -1,   208,    -1,   213,    -1,
     210,    -1,    -1,   270,   310,   272,   273,    47,    -1,   274,
      -1,   273,   274,    -1,   273,    47,   274,    -1,    -1,    -1,
      45,   275,   280,   277,   276,   287,    -1,    -1,    26,    29,
      28,    -1,    26,    29,    58,    29,    28,    -1,   279,   126,
      41,    -1,   279,    -1,    -1,    60,    72,   218,    39,   218,
      -1,    60,    72,   218,    -1,    60,   313,    -1,    34,    39,
     306,   278,    -1,   142,   278,    -1,   142,   143,    42,   278,
      -1,   218,    39,   218,    -1,   218,    -1,    53,   218,    39,
     218,    -1,    53,   218,    -1,   282,    -1,   281,    58,   282,
      -1,   283,    45,   284,    -1,   310,    -1,   218,    39,   218,
      -1,   218,    -1,   218,    39,   218,    -1,   218,    -1,    53,
     218,    39,   218,    -1,    53,   218,    -1,    49,    -1,    58,
      49,    -1,    -1,    58,   288,    -1,   289,    -1,   288,    58,
     289,    -1,    88,    -1,    89,    45,   291,   332,    -1,    50,
     285,    -1,    48,   281,   286,   285,    -1,    90,    45,    46,
      -1,    91,    45,   290,    -1,   209,    45,   290,    -1,    93,
      72,   218,    -1,    93,    72,   218,    39,   218,    -1,    92,
      72,   218,    -1,    92,    72,   218,    39,   218,    -1,    94,
      -1,    95,    -1,    96,    45,    46,    -1,    97,    45,    51,
     314,    52,    -1,   118,    45,    46,    -1,   119,    45,    46,
      -1,   173,    45,   218,    -1,    98,    -1,    36,    25,    45,
      29,    -1,    36,    -1,   117,    -1,   100,    -1,    99,    -1,
     101,    45,    46,    -1,   102,    45,    46,    -1,   103,    -1,
      82,    -1,   105,    -1,   104,    -1,   170,    -1,   169,    -1,
     106,    -1,   106,   107,    -1,   106,   108,    -1,   183,    -1,
     196,    -1,   194,    -1,   195,    -1,   191,    45,   192,    -1,
     191,    45,   193,    -1,   189,    -1,   190,    45,    46,    -1,
     198,    45,    29,    -1,   197,    45,    29,    -1,   199,    -1,
     200,    -1,   201,    -1,   202,    -1,   203,    -1,   204,    45,
      51,   315,    52,    -1,   205,    45,    29,    -1,   206,    45,
      29,    -1,   211,    45,    46,    -1,   212,    45,    46,    -1,
     211,    45,    29,    -1,   212,    45,    29,    -1,   113,    45,
      46,    -1,   181,    45,    46,    -1,    46,    -1,    29,    -1,
     115,    -1,   292,    -1,   291,   292,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    29,    -1,    82,    -1,    87,    -1,    81,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    -1,
      19,   294,   254,    -1,   295,    -1,   294,   295,    -1,   296,
      -1,   296,    47,    -1,    61,    46,    -1,   346,    -1,    -1,
      24,    57,   297,   301,    51,   302,    52,   298,   300,    -1,
     141,    51,    29,    58,    29,    52,   109,    51,    29,    58,
      29,    52,    -1,   339,    -1,   362,    -1,    -1,   110,   139,
      -1,    -1,    53,    -1,    -1,    47,    -1,   218,    -1,   218,
      26,    29,    28,    -1,   305,    -1,   302,   303,   305,    -1,
      -1,    58,    -1,   218,    -1,   218,    39,   218,    -1,    34,
      39,   218,    -1,   218,    39,    53,    -1,    34,    39,    53,
      -1,   304,    -1,   304,    59,   304,    -1,   218,    -1,    27,
      -1,    -1,   308,    -1,   309,    -1,   308,   309,    -1,   144,
      -1,   145,    -1,   218,    -1,    -1,   307,   218,   312,   307,
      -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,    66,
      -1,    67,    -1,    68,   320,    -1,    69,   320,    -1,    70,
     327,    -1,    71,   321,    -1,   111,    -1,   112,    -1,   113,
      -1,   114,    -1,   140,    -1,   318,    -1,   314,    58,   318,
      -1,   317,    -1,   315,    58,   317,    -1,    29,    -1,    55,
      29,    -1,    56,    29,    -1,    46,    -1,    30,    -1,    16,
      -1,   316,    -1,    41,    -1,   319,    -1,   319,   109,   319,
      -1,   319,    37,   319,    -1,    46,    -1,    30,    -1,    16,
      -1,   316,    -1,    41,    -1,    -1,    51,    29,    52,    -1,
      51,    29,    58,    29,    52,    -1,    -1,   324,   109,   326,
      -1,    -1,    51,    29,    52,    -1,    29,    -1,   325,   322,
      -1,   132,    -1,   133,    -1,   134,    -1,   135,    -1,   136,
      -1,   137,    -1,   138,   331,    -1,   325,    -1,    -1,   328,
     109,   329,    -1,   330,    -1,   330,    -1,   132,    -1,   133,
      -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,
     331,    -1,    -1,    51,   323,    52,    -1,    -1,   333,    -1,
     125,   334,    -1,   335,    -1,   335,   123,   335,    -1,   335,
     122,   335,    -1,   336,   121,   336,    -1,   336,     8,   336,
      -1,   336,     9,   336,    -1,   336,    72,   336,    -1,   336,
     126,    72,   336,    -1,   336,    45,   336,    -1,   336,   130,
      -1,   336,   131,    -1,   336,    -1,   336,   127,   336,   123,
     336,    -1,   336,   128,    51,   338,    52,    -1,   126,   335,
      -1,    51,   335,    52,    -1,   337,    -1,    29,    -1,    46,
      -1,   129,    -1,    30,    -1,   336,    -1,   338,    58,   336,
      -1,    18,   340,    -1,   341,    -1,   340,   341,    -1,     8,
     342,     9,   299,     8,   342,     9,    -1,   343,    -1,   342,
      58,   343,    -1,   344,    39,   345,    -1,   345,    -1,   218,
      -1,   217,    -1,   147,   356,   152,   360,   354,    -1,   148,
     357,   152,   360,   354,    -1,   157,   363,    -1,   156,   363,
      -1,   350,    -1,   355,    -1,   348,    -1,   351,    -1,   352,
      -1,   363,    -1,   353,    -1,   164,   368,   165,   347,   349,
      -1,    -1,   166,   347,    -1,   160,    -1,   161,   310,    45,
     368,    -1,   163,   310,    -1,   163,    45,   310,    -1,   163,
     162,    -1,   163,    45,   162,    -1,   167,   354,    27,    -1,
     347,    -1,   354,   347,    -1,    90,    46,    -1,    90,   159,
      46,    -1,    90,    82,    46,    -1,    90,   159,    82,    46,
      -1,   358,    -1,   356,   358,    -1,   359,    -1,   357,   359,
      -1,   149,    -1,   150,    -1,   151,    -1,   149,    -1,   153,
      -1,   154,    -1,   155,    -1,   151,    -1,    93,    -1,   150,
      -1,   361,    -1,   360,   303,   361,    -1,   344,    39,   345,
      -1,   345,    -1,   344,   146,   344,   300,    -1,    -1,   158,
     218,    51,   364,   365,    52,    -1,    -1,   366,    -1,   367,
      -1,   366,    58,   367,    -1,   368,    -1,   369,    -1,   368,
     123,   368,    -1,   368,   122,   368,    -1,    56,   368,    -1,
      55,   368,    -1,   371,    -1,   126,   368,    -1,    51,   368,
      52,    -1,   370,    51,   365,    52,    -1,   168,   152,   310,
      -1,   368,   121,   368,    -1,   368,     8,   368,    -1,   368,
       9,   368,    -1,   368,    53,   368,    -1,   368,    55,   368,
      -1,   368,    56,   368,    -1,   368,    54,   368,    -1,   368,
      72,   368,    -1,   368,   126,    72,   368,    -1,   368,    45,
     368,    -1,   368,   130,    -1,   368,   131,    -1,   368,   127,
     368,   123,   368,    -1,   368,   128,    51,   372,    52,    -1,
     368,   126,   128,    51,   372,    52,    -1,   218,    -1,   310,
      -1,    29,    -1,    46,    -1,   129,    -1,    41,    -1,   371,
      -1,   372,    58,   371,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   157,   158,   163,   164,   173,   177,   181,
     182,   183,   184,   189,   192,   199,   209,   218,   231,   239,
     249,   257,   270,   271,   276,   279,   282,   275,   298,   301,
     304,   297,   318,   321,   321,   327,   330,   333,   336,   342,
     343,   344,   348,   357,   363,   373,   380,   382,   384,   386,
     388,   390,   395,   405,   405,   408,   408,   421,   421,   440,
     442,   445,   440,   450,   450,   455,   456,   457,   469,   470,
     475,   476,   479,   494,   506,   507,   518,   529,   542,   554,
     565,   570,   573,   581,   582,   588,   587,   609,   612,   612,
     630,   631,   634,   635,   636,   639,   648,   649,   652,   653,
     654,   656,   657,   658,   664,   668,   668,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   688,   687,
     709,   710,   711,   715,   719,   715,   905,   906,   912,   922,
     923,   926,   927,   930,   933,   938,   949,   963,   977,   986,
     996,  1005,  1020,  1029,  1038,  1045,  1047,  1050,  1056,  1057,
    1058,  1059,  1062,  1063,  1067,  1068,  1072,  1072,  1075,  1080,
    1102,  1126,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1153,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1169,  1176,  1177,  1178,  1179,  1180,  1181,  1182,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1193,  1195,  1196,  1197,  1198,  1199,  1200,  1206,  1207,  1208,
    1212,  1213,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,
    1226,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1250,  1251,
    1254,  1254,  1256,  1256,  1259,  1269,  1275,  1275,  1278,  1279,
    1280,  1284,  1284,  1286,  1286,  1289,  1289,  1291,  1294,  1300,
    1303,  1307,  1308,  1312,  1316,  1320,  1324,  1328,  1335,  1335,
    1339,  1342,  1346,  1346,  1349,  1349,  1353,  1354,  1367,  1375,
    1375,  1384,  1388,  1392,  1396,  1400,  1404,  1408,  1414,  1418,
    1422,  1426,  1430,  1434,  1438,  1441,  1448,  1448,  1452,  1452,
    1457,  1457,  1457,  1461,  1468,  1469,  1470,  1471,  1506,  1507,
    1510,  1516,  1523,  1524,  1525,  1526,  1532,  1535,  1536,  1539,
    1540,  1547,  1549,  1554,  1562,  1565,  1566,  1567,  1568,  1569,
    1570,  1571,  1577,  1579,  1580,  1583,  1586,  1590,  1591,  1592,
    1593,  1594,  1595,  1596,  1602,  1604,  1611,  1611,  1617,  1623,
    1624,  1627,  1633,  1634,  1635,  1636,  1637,  1638,  1639,  1640,
    1641,  1642,  1643,  1644,  1645,  1648,  1655,  1656,  1657,  1662,
    1665,  1669,  1681,  1684,  1685,  1689,  1699,  1706,  1715,  1718,
    1730,  1733,  1737,  1744,  1752,  1757,  1765,  1769,  1774,  1779,
    1784,  1789,  1794,  1803,  1812,  1813,  1818,  1821,  1829,  1835,
    1841,  1847,  1856,  1861,  1871,  1881,  1887,  1893,  1899,  1909,
    1921,  1929,  1941,  1949,  1950,  1951,  1955,  1956,  1957,  1958,
    1959,  1960,  1961,  1964,  1971,  1982,  1986,  1993,  2001,  2001,
    2019,  2020,  2026,  2032,  2040,  2047,  2048,  2049,  2067,  2069,
    2070,  2071,  2072,  2073,  2076,  2077,  2078,  2079,  2080,  2081,
    2082,  2083,  2084,  2085,  2086,  2087,  2088,  2089,  2090,  2091,
    2094,  2097,  2098,  2099,  2100,  2101,  2104,  2108
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
       0,   214,   215,   216,   216,   216,   216,   217,   218,   219,
     219,   219,   219,   220,   220,   221,   222,   223,   224,   225,
     225,   226,   227,   227,   229,   230,   231,   228,   233,   234,
     235,   232,   236,   237,   236,   238,   238,   238,   238,   239,
     239,   239,   240,   240,   241,   241,   242,   242,   242,   242,
     242,   242,   243,   244,   244,   246,   245,   247,   245,   249,
     250,   251,   248,   252,   252,   253,   253,   253,   254,   254,
     255,   255,   256,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   258,   258,   260,   259,   261,   262,   261,
     263,   263,   264,   264,   264,   265,   266,   266,   267,   267,
     267,   267,   267,   267,   268,   269,   269,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   272,   271,
     273,   273,   273,   275,   276,   274,   277,   277,   277,   278,
     278,   279,   279,   279,   279,   280,   280,   280,   280,   280,
     280,   280,   281,   281,   282,   283,   284,   284,   285,   285,
     285,   285,   286,   286,   287,   287,   288,   288,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   290,   290,   290,
     291,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   293,   293,
     294,   294,   295,   295,   296,   296,   297,   296,   296,   296,
     296,   298,   298,   299,   299,   300,   300,   301,   301,   302,
     302,   303,   303,   304,   304,   304,   304,   304,   305,   305,
     306,   306,   307,   307,   308,   308,   309,   309,   310,   312,
     311,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   314,   314,   315,   315,
     316,   316,   316,   317,   317,   317,   317,   317,   318,   318,
     318,   319,   319,   319,   319,   319,   320,   320,   320,   321,
     321,   322,   322,   323,   324,   325,   325,   325,   325,   325,
     325,   325,   326,   327,   327,   328,   329,   330,   330,   330,
     330,   330,   330,   330,   331,   331,   332,   332,   333,   334,
     334,   334,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   336,   336,   336,   336,   337,
     338,   338,   339,   340,   340,   341,   342,   342,   343,   343,
     344,   345,   346,   346,   346,   346,   347,   347,   347,   347,
     347,   347,   347,   348,   349,   349,   350,   351,   352,   352,
     352,   352,   353,   354,   354,   355,   355,   355,   355,   356,
     356,   357,   357,   358,   358,   358,   359,   359,   359,   359,
     359,   359,   359,   360,   360,   361,   361,   362,   364,   363,
     365,   365,   366,   366,   367,   368,   368,   368,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     370,   371,   371,   371,   371,   371,   372,   372
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     3,     1,     1,     5,     5,     5,     5,     1,
       2,     5,     0,     1,     0,     0,     0,    10,     0,     0,
       0,    10,     0,     0,     4,     3,     1,     3,     3,     1,
       2,     3,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     0,     3,     0,     4,     0,
       0,     0,     9,     0,     1,     0,     2,     4,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     4,     1,     0,     4,
       0,     3,     1,     2,     3,     2,     0,     2,     1,     3,
       3,     5,     3,     3,     3,     1,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     2,     3,     0,     0,     6,     0,     3,     5,     3,
       1,     0,     5,     3,     2,     4,     2,     4,     3,     1,
       4,     2,     1,     3,     3,     1,     3,     1,     3,     1,
       4,     2,     1,     2,     0,     2,     1,     3,     1,     4,
       2,     4,     3,     3,     3,     3,     5,     3,     5,     1,
       1,     3,     5,     3,     3,     3,     1,     4,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     1,     1,     1,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
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
       0,     1,     1,     3,     1,     1,     3,     3,     2,     2,
       1,     2,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     2,     2,     5,     5,     6,
       1,     1,     1,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     7,     3,     9,    11,     6,     1,
       0,    55,     0,    90,    14,    13,    53,     0,     0,     0,
       0,    57,    65,    22,    22,    24,    22,    28,    22,    46,
      47,    48,    49,    50,    51,    68,     0,     0,    54,     0,
       8,    10,    12,     0,    65,     0,    56,    59,    23,    32,
      32,    22,    32,    22,    32,    69,    52,    96,    68,    92,
     107,   238,     5,     4,    58,    66,    63,    33,    42,    42,
      32,    42,    32,     0,     0,    95,     0,    91,    93,   109,
     112,   110,   108,   111,   113,   114,   115,   117,   116,    68,
       0,   105,     0,     2,     0,    64,     0,     0,     0,    43,
      44,     0,     0,     0,     0,    22,     0,    19,     0,    98,
      97,    94,   104,   106,   278,   118,     0,     0,     0,     0,
       0,     0,     0,     0,   380,    68,   240,   242,   249,     0,
     245,   250,    67,    60,     0,     0,     0,    36,    39,     0,
      16,    45,    15,    25,    17,    29,    32,    18,    20,     0,
       0,     0,     0,     0,     0,   372,   373,   246,   244,     0,
     413,   414,   415,     0,   409,   421,   416,   422,   420,   417,
     418,   419,     0,   411,     0,   385,   384,   239,   241,   243,
       0,     0,     0,     0,     0,    34,     0,    40,     0,     0,
      42,   103,    99,   100,   102,   123,     0,   120,     7,   381,
       0,   376,     0,   379,   374,     0,     0,     0,   410,     0,
     412,     0,   255,    83,    76,    85,    77,    78,    82,    81,
      80,    75,    72,     0,    73,    70,    79,    74,    37,    38,
      35,    41,     0,     0,     0,     0,     0,   119,   121,   253,
       0,     0,   257,     0,     0,     0,   426,   261,   423,   261,
     428,   256,   427,   272,    61,    71,    84,    26,    30,    21,
     101,     0,     0,   131,   139,   126,   122,   254,     0,   377,
     378,     0,     0,     0,     0,   262,     0,   396,     0,     0,
       0,     0,     0,   403,   388,   386,   389,   390,   392,   382,
     387,   391,   383,   430,   276,   277,     0,     0,   273,   274,
      87,    68,     0,     0,     0,   141,     0,     0,   136,   130,
       0,     0,   124,     0,     0,     0,   263,   261,   268,   259,
       0,   425,   405,     0,     0,     0,     0,   400,   398,   462,
     465,   463,     0,     0,     0,     0,   464,     0,   278,   461,
       0,   435,     0,   440,     0,   424,   404,     0,   431,   432,
     434,    86,    88,   279,   275,    62,    27,    31,   271,   270,
     131,     0,   281,   282,   283,   284,   285,   286,   316,   316,
     333,   319,     0,   291,   292,   293,   294,   295,   134,   131,
       0,   138,     0,   154,     0,   258,     0,     0,   251,     0,
       0,     0,   407,   406,     0,     0,   401,   399,     0,   439,
     438,   441,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   455,   456,     0,
     430,   402,   429,     0,   272,   272,   135,   140,     0,   287,
     288,   337,   338,   339,   340,   341,   342,   344,   289,     0,
     335,   325,   326,   327,   328,   329,   330,   344,   290,     0,
     321,   133,   137,   129,   127,     0,     0,   125,   375,   267,
     265,   266,   264,     0,   255,   260,   269,     0,   408,   397,
     442,   444,   446,   447,   454,   448,   451,   449,   450,   452,
     445,   437,   436,     0,     0,     0,     0,   394,     0,   433,
      89,   280,     0,     0,   343,     0,   331,     0,     0,   324,
       0,     0,   178,     0,     0,   185,   158,     0,     0,     0,
       0,     0,   169,   170,     0,     0,   176,   181,   180,     0,
       0,   184,   187,   186,   190,     0,   179,     0,     0,   189,
     188,     0,     0,   193,   199,     0,     0,   195,   196,   194,
       0,     0,   203,   204,   205,   206,   207,     0,     0,     0,
       0,     0,     0,   155,   156,   252,   247,     0,   453,     0,
       0,   466,     0,     0,   393,   443,   317,     0,   323,     0,
     334,   336,   332,   320,     0,   132,   128,     0,     0,   142,
       0,   145,     0,   149,   160,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   192,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   457,   458,     0,   395,     0,   345,
     322,     0,   152,     0,     0,     0,   151,     0,   230,   222,
     223,   224,   225,   226,   227,   228,   229,   233,   231,   234,
     235,   236,   237,   232,   346,   220,   162,   218,   217,   219,
     163,   167,   165,   171,     0,   182,   183,   215,   173,   174,
     175,   216,   200,   197,   198,   202,   201,     0,   209,   210,
     164,   213,   211,   214,   212,   157,     0,   459,   467,   318,
     177,   153,   143,   161,   147,   144,     0,   148,     0,   221,
     159,   347,     0,     0,   313,   300,   312,   315,   311,     0,
       0,     0,   314,   296,   308,   305,   304,   307,   303,     0,
     306,   298,   248,     0,   150,   366,   369,   367,     0,     0,
     368,   348,   349,   360,   365,   168,   166,   301,   302,   172,
       0,     0,     0,   208,     0,   146,     0,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   358,   359,
     297,   310,   309,   299,   364,   351,   350,   353,   354,   357,
     355,   352,     0,     0,     0,   356,     0,   370,     0,   361,
     362,     0,   371
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   199,   338,     8,    13,    29,    30,    31,
      32,   106,   107,    49,    33,    51,   188,   302,    34,    53,
     189,   303,    68,    97,   138,   139,    98,    99,   100,    14,
      15,    16,    22,    44,    46,    66,   181,   301,    96,    47,
      56,   223,   224,   225,   226,   227,   253,   296,   424,    37,
      58,    59,    75,   110,    61,    89,    90,    91,   153,   196,
     197,   236,   383,   312,   308,   309,   265,   578,   579,   580,
     685,   584,   624,   457,   553,   554,   650,   644,   645,    93,
     125,   126,   127,   205,   464,   268,   252,   243,   317,   282,
     318,   319,   360,   297,   298,   299,   339,   300,   425,   378,
     701,   709,   702,   711,   703,   704,   429,   448,   499,   569,
     449,   450,   573,   438,   439,   570,   440,   494,   690,   691,
     721,   722,   723,   724,   768,   128,   155,   156,   200,   201,
     202,   203,   130,   283,   284,   564,   285,   286,   287,   288,
     289,   290,   163,   172,   164,   173,   247,   248,   131,   291,
     293,   347,   348,   349,   350,   341,   342,   343,   562
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -659
static const yytype_int16 yypact[] =
{
      26,   -17,    62,     1,  -659,    15,    53,    74,   106,  -659,
      79,  -659,   134,   114,  -659,   303,  -659,   126,   160,   160,
     194,  -659,   214,   160,   160,  -659,   160,  -659,   160,  -659,
    -659,  -659,  -659,  -659,  -659,   222,   160,   223,  -659,   217,
    -659,  -659,  -659,   220,   214,   243,  -659,  -659,  -659,   226,
     226,   160,   226,   160,   226,  -659,  -659,   240,    55,  -659,
     625,   248,  -659,  -659,  -659,   313,   178,  -659,   134,   134,
     226,   134,   226,   183,    46,  -659,   160,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,    23,
     160,  -659,   100,  -659,   324,  -659,   329,   108,   340,   134,
    -659,   343,   342,   348,   347,   160,   -25,  -659,   355,   285,
    -659,  -659,  -659,  -659,  -659,  -659,   373,   338,   376,   367,
     182,   394,   261,   261,  -659,    12,  -659,   381,  -659,   277,
    -659,  -659,  -659,  -659,   389,   390,   397,  -659,  -659,    85,
    -659,  -659,  -659,  -659,  -659,  -659,   226,  -659,  -659,   160,
     160,   160,   160,   399,   420,   373,  -659,  -659,  -659,   422,
    -659,  -659,  -659,   188,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,   372,  -659,   160,  -659,  -659,  -659,  -659,  -659,
     160,   430,   406,   423,   408,  -659,   108,  -659,   430,   430,
     134,  -659,  -659,   418,  -659,  -659,   179,  -659,   419,  -659,
      48,  -659,   424,  -659,  -659,   160,   403,   420,  -659,   420,
    -659,   411,   417,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,   271,  -659,  -659,   450,  -659,  -659,  -659,
    -659,  -659,   304,   413,   440,   160,    -7,   399,  -659,   416,
     420,   441,   444,   421,   451,   434,  -659,    39,  -659,    39,
    -659,  -659,  -659,   197,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,   445,   160,   -45,   449,   453,  -659,  -659,   475,  -659,
    -659,   461,   204,   442,   441,  -659,   -39,  -659,   160,    -4,
      59,   216,   420,  -659,  -659,  -659,  -659,  -659,  -659,   216,
    -659,  -659,   216,    59,  -659,  -659,   168,   160,   197,  -659,
    -659,   222,   465,   466,   189,   457,   676,   458,  -659,   369,
     160,   472,  -659,   420,   490,   489,   491,   211,   473,  -659,
     425,  -659,  -659,   492,   -14,   486,   -10,  -659,  -659,  -659,
    -659,  -659,    59,    59,    59,    59,  -659,   383,   500,  -659,
     310,  -659,   502,  -659,   -13,  -659,  -659,   484,   496,  -659,
     531,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
     482,   160,  -659,  -659,  -659,  -659,  -659,  -659,   504,   504,
     456,   485,   160,  -659,  -659,  -659,  -659,  -659,  -659,   482,
     515,  -659,    17,   508,    50,  -659,    63,    91,   455,   204,
     204,   518,  -659,  -659,   526,    59,  -659,  -659,   507,   531,
     531,   531,   160,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,   -44,    59,   522,  -659,  -659,   216,
      59,  -659,  -659,    59,   197,   197,  -659,  -659,   548,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,   527,  -659,   471,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,   527,  -659,   474,
     544,   543,  -659,  -659,  -659,   567,   308,  -659,  -659,  -659,
    -659,  -659,  -659,   462,   417,  -659,  -659,   568,  -659,   531,
    -659,  -659,   571,   571,   531,   531,   531,   531,   531,   531,
     531,   531,   531,    59,   551,   559,    37,   476,   556,  -659,
    -659,  -659,   218,   581,  -659,   456,  -659,   485,   582,  -659,
     160,   604,   614,   160,   112,  -659,  -659,   595,   596,   599,
     578,   583,  -659,  -659,   611,   615,  -659,  -659,  -659,   619,
     620,  -659,  -659,  -659,   238,   621,  -659,   627,   628,  -659,
    -659,   632,   633,  -659,  -659,   638,   639,  -659,  -659,  -659,
     643,   646,  -659,  -659,  -659,  -659,  -659,   651,   655,   658,
     659,   660,   662,   612,  -659,  -659,  -659,   652,   531,    37,
      59,  -659,   232,   216,  -659,  -659,  -659,   679,  -659,   657,
    -659,  -659,  -659,  -659,   661,  -659,  -659,   666,   174,  -659,
     669,  -659,   160,   681,  -659,   677,   670,     2,   160,   160,
     703,   664,   719,   721,  -659,  -659,   723,   724,   725,   160,
     726,   727,   159,   745,   747,   732,   748,   749,     2,   191,
     196,   308,   755,   241,   531,  -659,    37,  -659,   733,  -659,
    -659,   757,  -659,    41,   112,   160,   753,   160,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,   650,  -659,  -659,  -659,  -659,  -659,
    -659,   756,   758,  -659,   750,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,   752,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,   742,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,   760,  -659,   160,  -659,   199,  -659,
    -659,  -659,   160,   160,  -659,  -659,  -659,  -659,  -659,   771,
     772,   242,  -659,  -659,    14,  -659,  -659,  -659,  -659,   244,
    -659,  -659,  -659,   160,  -659,  -659,  -659,  -659,   199,   199,
    -659,  -659,   239,   591,  -659,  -659,  -659,  -659,  -659,  -659,
     750,   750,   750,  -659,   752,  -659,   751,  -659,   199,   199,
      65,    65,    65,    65,    65,   730,    65,   763,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,    65,   694,    65,  -659,    65,  -659,   246,  -659,
    -659,    65,  -659
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -659,  -659,  -659,   803,   -18,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,   712,   254,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,   201,  -659,  -123,  -659,   -50,  -659,    10,  -659,
    -659,   804,  -659,  -659,   776,  -659,  -659,  -659,  -659,  -659,
     -55,   200,  -659,    42,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,   128,  -659,  -659,  -659,  -659,  -659,   734,  -659,  -659,
    -158,  -659,  -659,  -659,  -238,  -659,  -659,  -659,   198,  -659,
    -659,   202,  -659,  -659,  -659,   213,   219,  -659,   181,  -659,
    -659,   697,  -659,  -659,  -659,  -659,   364,  -659,  -659,   512,
     446,   448,  -659,   405,  -659,   533,   -86,   410,  -659,  -659,
    -659,  -659,  -638,   105,   110,  -346,   477,  -659,  -659,  -659,
    -659,   344,  -659,  -659,  -659,  -659,   349,   395,  -659,  -659,
    -659,  -658,   -95,  -659,  -659,  -659,  -659,   688,   532,   607,
     -81,  -155,  -659,  -280,  -659,  -659,  -659,  -659,  -659,  -659,
    -212,  -659,  -659,  -659,   685,   678,   640,   569,  -659,   270,
    -659,   432,  -659,   431,  -231,  -659,  -659,  -421,   294
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -461
static const yytype_int16 yytable[] =
{
      41,    42,   147,    77,   115,    48,    48,   322,    48,   346,
      48,   129,   346,     4,   421,   306,   187,     5,    57,   101,
      40,   103,    35,    40,    10,    11,    40,   261,   483,   710,
     116,   647,   393,    48,   112,    48,   117,   292,   238,    55,
      57,   326,    40,   323,   129,   454,   262,     1,   648,   340,
      55,   731,   246,  -107,   246,    17,   109,   239,    57,   458,
     736,   737,     9,   231,   346,   561,   329,    40,   394,   344,
     177,    40,   114,   118,   124,   455,    40,   276,   330,   266,
     755,   756,    55,   331,   484,    40,   270,    48,   329,    40,
     681,    18,   108,    40,   715,   716,   710,   275,   307,   212,
     330,   398,   399,   400,   401,   331,   240,   124,   240,   141,
     332,   717,    19,    76,   333,   334,   459,   649,   116,   321,
     324,    40,   426,   732,   117,    21,   245,   246,   245,   276,
      40,   191,   192,   193,   194,   263,   124,   185,   561,   487,
     234,   452,    40,   186,   461,   174,    20,   277,   278,   105,
     279,   280,   396,   119,   281,     6,   211,    36,   327,   120,
     121,   118,   124,   222,   469,   582,   336,    39,   122,   123,
     222,   222,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,    12,   485,   335,    78,   242,   336,   124,
      40,   124,   325,   328,   720,   678,   351,   174,   134,   277,
     278,   245,   279,   280,   111,   222,   281,    79,    80,    81,
      82,    83,   352,    84,   222,   222,   358,   260,   264,    40,
     671,   134,   124,   622,   195,   673,   237,   337,   715,   716,
      85,    86,   623,    87,    40,    43,    88,   672,   315,    45,
     397,   119,   674,    60,   305,   717,   355,   120,   121,    55,
     718,    69,   558,    71,   316,    73,   122,   123,   135,    62,
     114,   114,    63,   388,   124,   255,   136,    92,   137,   275,
     566,   102,    65,   104,   255,   255,   567,    67,    50,   353,
      52,   135,    54,   617,   615,    74,   359,   213,   214,   136,
     616,   137,   381,   677,   729,   124,   733,   215,   770,   616,
     730,    40,   734,   254,   771,    70,   276,    72,   114,    23,
      24,    25,    26,    27,    28,   216,   471,   217,   403,   404,
     213,   214,   150,   151,   152,   719,    10,    11,   720,   614,
     215,   160,   161,   162,    40,    94,   257,   160,   161,   162,
     207,   294,   295,   427,   502,   594,   595,   190,   216,    95,
     217,   663,   664,   132,   451,   405,   503,   105,   504,   146,
     133,   738,   739,   406,   407,   408,   409,   140,   460,   462,
     142,   316,   316,   143,   174,   144,   277,   278,   145,   279,
     280,   154,   410,   281,   114,   751,   752,   218,   232,   233,
     505,   219,   175,   176,   149,   157,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   220,   221,   581,   159,   174,
     218,   525,   158,   180,   219,   526,   527,   528,   179,   213,
     214,   411,   412,   413,   182,   183,   414,   415,   416,   215,
     417,   418,   184,    40,   195,   258,   213,   214,   220,   221,
     198,   206,   228,   229,   230,   235,   215,   216,    -8,   217,
      40,   244,   250,   241,   251,   165,   256,   259,   114,   267,
     271,     4,   272,   274,   216,   419,   217,   529,   530,   311,
     273,   531,   575,   313,   304,   114,   583,   165,   310,   532,
     314,   533,   356,   357,   320,   380,   361,   534,   535,   536,
     379,   382,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   403,   404,   550,   385,   551,
     552,   166,   167,   168,   209,   169,   170,   171,   386,   218,
     387,   395,   390,   219,   391,   402,   422,   581,   392,   403,
     404,   114,   306,   166,   167,   168,   218,   169,   170,   171,
     219,  -460,   405,   420,   423,   428,   453,   220,   221,   470,
     406,   407,   408,   409,   626,   463,   456,   403,   404,   467,
     651,   652,   468,   486,   220,   221,   405,   492,   493,   410,
     495,   660,   500,   497,   406,   407,   408,   409,   431,   432,
     433,   434,   435,   436,   437,   498,   501,   557,   114,   740,
     741,   555,   559,   410,   405,   114,   583,   684,   565,   687,
     568,   574,   406,   407,   408,   409,   405,   441,   442,   443,
     444,   445,   446,   447,   406,   407,   408,   409,   411,   412,
     413,   410,   576,   414,   415,   416,   742,   417,   418,   577,
     585,   586,   563,   410,   587,   757,   758,   759,   760,   761,
     588,   763,   411,   412,   413,   589,   590,   414,   415,   416,
     591,   417,   418,   743,   592,   593,   596,   765,   714,   767,
     611,   769,   597,   598,   725,   726,   772,   599,   600,   628,
     411,   412,   560,   601,   602,   414,   415,   416,   603,   417,
     418,   604,   411,   412,   413,   735,   605,   414,   415,   416,
     606,   417,   418,   607,   608,   609,   628,   610,   618,   619,
     612,   621,   744,   620,   625,   654,   646,   745,   746,   747,
     627,   748,   749,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   653,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   655,   694,   656,   705,   657,
     658,   659,   661,   662,   665,   688,   666,   668,   669,   695,
     696,   695,   706,   667,   676,   679,   680,   373,   374,   375,
     376,   697,   686,   707,   712,   692,   698,   693,   708,   713,
     727,   728,   762,   754,     7,   699,   700,   699,   700,    79,
      80,    81,    82,    83,   764,    84,   377,   766,   148,    38,
      64,   682,   178,   113,   675,   689,   683,   670,   556,   389,
     491,   354,    85,    86,   490,    87,   466,   465,    88,   753,
     750,   572,   496,   204,   571,   384,   430,   269,   208,   249,
     210,   345,   488,   613,   489
};

static const yytype_uint16 yycheck[] =
{
      18,    19,    27,    58,    90,    23,    24,    46,    26,   289,
      28,    92,   292,    30,    27,    60,   139,    34,    36,    69,
      30,    71,    12,    30,    23,    24,    30,    34,    72,   667,
      18,    29,    46,    51,    89,    53,    24,   249,   196,    27,
      58,    45,    30,    82,   125,    28,    53,    21,    46,   280,
      27,    37,   207,    30,   209,    40,    74,     9,    76,     9,
     718,   719,     0,   186,   344,   486,    29,    30,    82,   281,
     125,    30,    90,    61,    92,    58,    30,    90,    41,   237,
     738,   739,    27,    46,   128,    30,   241,   105,    29,    30,
      49,    38,    46,    30,    29,    30,   734,    58,   143,   180,
      41,   332,   333,   334,   335,    46,    58,   125,    58,    99,
      51,    46,    38,    58,    55,    56,    53,   115,    18,   274,
     159,    30,   360,   109,    24,    46,   207,   282,   209,    90,
      30,   149,   150,   151,   152,   142,   154,    52,   559,   419,
     190,   379,    30,    58,    53,   158,    40,   160,   161,   174,
     163,   164,   162,   141,   167,   172,   174,    43,   162,   147,
     148,    61,   180,   181,   395,    53,   129,    41,   156,   157,
     188,   189,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   182,   415,   126,    58,   205,   129,   207,
      30,   209,   278,   279,   129,   616,    28,   158,   113,   160,
     161,   282,   163,   164,    76,   223,   167,   184,   185,   186,
     187,   188,    44,   190,   232,   233,    27,   235,   236,    30,
      29,   113,   240,    49,    45,    29,    47,   168,    29,    30,
     207,   208,    58,   210,    30,    41,   213,    46,    34,    25,
     326,   141,    46,    20,   262,    46,   301,   147,   148,    27,
      51,    50,   483,    52,   272,    54,   156,   157,   173,    42,
     278,   279,    42,    52,   282,   223,   181,    19,   183,    58,
      52,    70,    29,    72,   232,   233,    58,    51,    24,   297,
      26,   173,    28,   563,    52,    45,   304,    16,    17,   181,
      58,   183,   310,    52,    52,   313,    52,    26,    52,    58,
      58,    30,    58,    32,    58,    51,    90,    53,   326,   175,
     176,   177,   178,   179,   180,    44,   402,    46,     8,     9,
      16,    17,    37,    38,    39,   126,    23,    24,   129,   560,
      26,   149,   150,   151,    30,    22,    32,   149,   150,   151,
     152,   144,   145,   361,    36,   107,   108,   146,    44,   171,
      46,   192,   193,    29,   372,    45,    48,   174,    50,   105,
      31,   122,   123,    53,    54,    55,    56,    27,   386,   387,
      27,   389,   390,    31,   158,    27,   160,   161,    31,   163,
     164,     8,    72,   167,   402,   731,   732,   116,   188,   189,
      82,   120,   122,   123,    39,    57,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   144,   145,   503,    51,   158,
     116,   113,    46,   146,   120,   117,   118,   119,    47,    16,
      17,   121,   122,   123,    45,    45,   126,   127,   128,    26,
     130,   131,    45,    30,    45,    32,    16,    17,   144,   145,
      30,    29,    46,    30,    46,    37,    26,    44,    39,    46,
      30,    58,    51,    39,    47,    93,    16,    27,   486,    53,
      26,    30,    51,    39,    44,   165,    46,   169,   170,    26,
      29,   173,   500,     8,    39,   503,   504,    93,    39,   181,
      29,   183,    27,    27,    52,   126,    39,   189,   190,   191,
      42,    29,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     8,     9,   209,    28,   211,
     212,   149,   150,   151,   152,   153,   154,   155,    39,   116,
      39,    45,    59,   120,   109,   152,    52,   623,    46,     8,
       9,   559,    60,   149,   150,   151,   116,   153,   154,   155,
     120,    51,    45,    51,    58,    51,    41,   144,   145,    52,
      53,    54,    55,    56,   582,   110,    58,     8,     9,    51,
     588,   589,    46,    51,   144,   145,    45,    29,    51,    72,
     109,   599,    39,   109,    53,    54,    55,    56,   132,   133,
     134,   135,   136,   137,   138,    51,    29,    29,   616,     8,
       9,   139,    51,    72,    45,   623,   624,   625,    52,   627,
      29,    29,    53,    54,    55,    56,    45,   132,   133,   134,
     135,   136,   137,   138,    53,    54,    55,    56,   121,   122,
     123,    72,    28,   126,   127,   128,    45,   130,   131,    25,
      45,    45,   166,    72,    45,   740,   741,   742,   743,   744,
      72,   746,   121,   122,   123,    72,    45,   126,   127,   128,
      45,   130,   131,    72,    45,    45,    45,   762,   686,   764,
      58,   766,    45,    45,   692,   693,   771,    45,    45,    29,
     121,   122,   123,    45,    45,   126,   127,   128,    45,   130,
     131,    45,   121,   122,   123,   713,    45,   126,   127,   128,
      45,   130,   131,    45,    45,    45,    29,    45,    29,    52,
      58,    45,   121,    52,    45,    51,    46,   126,   127,   128,
      39,   130,   131,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    46,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    46,    16,    46,    16,    46,
      46,    46,    46,    46,    29,   125,    29,    29,    29,    29,
      30,    29,    30,    51,    29,    52,    29,   111,   112,   113,
     114,    41,    39,    41,    52,    39,    46,    39,    46,    39,
      29,    29,    72,    52,     1,    55,    56,    55,    56,   184,
     185,   186,   187,   188,    51,   190,   140,   123,   106,    15,
      44,   623,   125,    89,   611,   644,   624,   608,   464,   317,
     425,   298,   207,   208,   424,   210,   390,   389,   213,   734,
     730,   497,   447,   155,   495,   313,   369,   240,   163,   209,
     172,   282,   420,   559,   423
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   215,   216,    30,    34,   172,   217,   219,     0,
      23,    24,   182,   220,   243,   244,   245,    40,    38,    38,
      40,    46,   246,   175,   176,   177,   178,   179,   180,   221,
     222,   223,   224,   228,   232,   242,    43,   263,   245,    41,
      30,   218,   218,    41,   247,    25,   248,   253,   218,   227,
     227,   229,   227,   233,   227,    27,   254,   218,   264,   265,
      20,   268,    42,    42,   248,    29,   249,    51,   236,   236,
     227,   236,   227,   236,    45,   266,    58,   254,   265,   184,
     185,   186,   187,   188,   190,   207,   208,   210,   213,   269,
     270,   271,    19,   293,    22,   171,   252,   237,   240,   241,
     242,   240,   236,   240,   236,   174,   225,   226,    46,   218,
     267,   265,   254,   271,   218,   310,    18,    24,    61,   141,
     147,   148,   156,   157,   218,   294,   295,   296,   339,   344,
     346,   362,    29,    31,   113,   173,   181,   183,   238,   239,
      27,   242,    27,    31,    27,    31,   227,    27,   226,    39,
      37,    38,    39,   272,     8,   340,   341,    57,    46,    51,
     149,   150,   151,   356,   358,    93,   149,   150,   151,   153,
     154,   155,   357,   359,   158,   363,   363,   254,   295,    47,
     146,   250,    45,    45,    45,    52,    58,   238,   230,   234,
     236,   218,   218,   218,   218,    45,   273,   274,    30,   217,
     342,   343,   344,   345,   341,   297,    29,   152,   358,   152,
     359,   218,   344,    16,    17,    26,    44,    46,   116,   120,
     144,   145,   218,   255,   256,   257,   258,   259,    46,    30,
      46,   238,   255,   255,   240,    37,   275,    47,   274,     9,
      58,    39,   218,   301,    58,   344,   345,   360,   361,   360,
      51,    47,   300,   260,    32,   257,    16,    32,    32,    27,
     218,    34,    53,   142,   218,   280,   274,    53,   299,   343,
     345,    26,    51,    29,    39,    58,    90,   160,   161,   163,
     164,   167,   303,   347,   348,   350,   351,   352,   353,   354,
     355,   363,   354,   364,   144,   145,   261,   307,   308,   309,
     311,   251,   231,   235,    39,   218,    60,   143,   278,   279,
      39,    26,   277,     8,    29,    34,   218,   302,   304,   305,
      52,   345,    46,    82,   159,   310,    45,   162,   310,    29,
      41,    46,    51,    55,    56,   126,   129,   168,   218,   310,
     368,   369,   370,   371,   354,   361,   347,   365,   366,   367,
     368,    28,    44,   218,   309,   254,    27,    27,    27,   218,
     306,    39,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   111,   112,   113,   114,   140,   313,    42,
     126,   218,    29,   276,   342,    28,    39,    39,    52,   303,
      59,   109,    46,    46,    82,    45,   162,   310,   368,   368,
     368,   368,   152,     8,     9,    45,    53,    54,    55,    56,
      72,   121,   122,   123,   126,   127,   128,   130,   131,   165,
      51,    27,    52,    58,   262,   312,   278,   218,    51,   320,
     320,   132,   133,   134,   135,   136,   137,   138,   327,   328,
     330,   132,   133,   134,   135,   136,   137,   138,   321,   324,
     325,   218,   278,    41,    28,    58,    58,   287,     9,    53,
     218,    53,   218,   110,   298,   305,   304,    51,    46,   368,
      52,   310,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,    72,   128,   368,    51,   347,   365,   367,
     311,   307,    29,    51,   331,   109,   331,   109,    51,   322,
      39,    29,    36,    48,    50,    82,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   113,   117,   118,   119,   169,
     170,   173,   181,   183,   189,   190,   191,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     209,   211,   212,   288,   289,   139,   300,    29,   368,    51,
     123,   371,   372,   166,   349,    52,    52,    58,    29,   323,
     329,   330,   325,   326,    29,   218,    28,    25,   281,   282,
     283,   310,    53,   218,   285,    45,    45,    45,    72,    72,
      45,    45,    45,    45,   107,   108,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    58,    58,   372,   368,    52,    58,   347,    29,    52,
      52,    45,    49,    58,   286,    45,   218,    39,    29,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   291,   292,    46,    29,    46,   115,
     290,   218,   218,    46,    51,    46,    46,    46,    46,    46,
     218,    46,    46,   192,   193,    29,    29,    51,    29,    29,
     290,    29,    46,    29,    46,   289,    29,    52,   371,    52,
      29,    49,   282,   285,   218,   284,    39,   218,   125,   292,
     332,   333,    39,    39,    16,    29,    30,    41,    46,    55,
      56,   314,   316,   318,   319,    16,    30,    41,    46,   315,
     316,   317,    52,    39,   218,    29,    30,    46,    51,   126,
     129,   334,   335,   336,   337,   218,   218,    29,    29,    52,
      58,    37,   109,    52,    58,   218,   335,   335,   122,   123,
       8,     9,    45,    72,   121,   126,   127,   128,   130,   131,
     318,   319,   319,   317,    52,   335,   335,   336,   336,   336,
     336,   336,    72,   336,    51,   336,   123,   336,   338,   336,
      52,    58,   336
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
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 182 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
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
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 336 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 348 "screen.yacc"
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

  case 43:

/* Line 1455 of yacc.c  */
#line 357 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 363 "screen.yacc"
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

  case 45:

/* Line 1455 of yacc.c  */
#line 373 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 381 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 383 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 385 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 387 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 389 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 391 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 397 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(2) - (3)].layout);
	}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 408 "screen.yacc"
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

  case 57:

/* Line 1455 of yacc.c  */
#line 421 "screen.yacc"
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

  case 59:

/* Line 1455 of yacc.c  */
#line 440 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 442 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 445 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 450 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 457 "screen.yacc"
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

  case 72:

/* Line 1455 of yacc.c  */
#line 479 "screen.yacc"
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

  case 73:

/* Line 1455 of yacc.c  */
#line 494 "screen.yacc"
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

  case 74:

/* Line 1455 of yacc.c  */
#line 506 "screen.yacc"
    { ltab=0; }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 507 "screen.yacc"
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

  case 76:

/* Line 1455 of yacc.c  */
#line 518 "screen.yacc"
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

  case 77:

/* Line 1455 of yacc.c  */
#line 529 "screen.yacc"
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

  case 78:

/* Line 1455 of yacc.c  */
#line 542 "screen.yacc"
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

  case 79:

/* Line 1455 of yacc.c  */
#line 554 "screen.yacc"
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
#line 565 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 570 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 573 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 581 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 582 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 588 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 595 "screen.yacc"
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

  case 87:

/* Line 1455 of yacc.c  */
#line 609 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 612 "screen.yacc"
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

  case 89:

/* Line 1455 of yacc.c  */
#line 623 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 639 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 648 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 649 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 652 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 653 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 655 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 656 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 657 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 673 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 674 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 675 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 676 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 677 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 678 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 679 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 680 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 681 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 682 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 683 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 688 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 694 "screen.yacc"
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

  case 123:

/* Line 1455 of yacc.c  */
#line 715 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 719 "screen.yacc"
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

  case 125:

/* Line 1455 of yacc.c  */
#line 729 "screen.yacc"
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

  case 127:

/* Line 1455 of yacc.c  */
#line 906 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 912 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 922 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 923 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 926 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 927 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 930 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 933 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 938 "screen.yacc"
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

  case 136:

/* Line 1455 of yacc.c  */
#line 949 "screen.yacc"
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

  case 137:

/* Line 1455 of yacc.c  */
#line 963 "screen.yacc"
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

  case 138:

/* Line 1455 of yacc.c  */
#line 977 "screen.yacc"
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

  case 139:

/* Line 1455 of yacc.c  */
#line 986 "screen.yacc"
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

  case 140:

/* Line 1455 of yacc.c  */
#line 996 "screen.yacc"
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

  case 141:

/* Line 1455 of yacc.c  */
#line 1005 "screen.yacc"
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

  case 142:

/* Line 1455 of yacc.c  */
#line 1020 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1029 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1038 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1047 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1050 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1056 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1057 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1058 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1059 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1075 "screen.yacc"
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1080 "screen.yacc"
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

  case 160:

/* Line 1455 of yacc.c  */
#line 1102 "screen.yacc"
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

  case 161:

/* Line 1455 of yacc.c  */
#line 1126 "screen.yacc"
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1134 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1135 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1136 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1137 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1138 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1139 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1140 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1141 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1142 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1143 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1144 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1145 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1146 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1147 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1148 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1149 "screen.yacc"
    { A4GL_get_fld()->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1150 "screen.yacc"
    { A4GL_get_fld()->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1151 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1153 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1155 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1156 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1157 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1158 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1159 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1160 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1161 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1162 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1163 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1164 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1165 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1169 "screen.yacc"
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1176 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1177 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1178 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1179 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1180 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1181 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1182 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1183 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1184 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1185 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1186 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1187 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1188 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1189 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1190 "screen.yacc"
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1191 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1192 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1193 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1195 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1196 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
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
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1200 "screen.yacc"
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1206 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1207 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1208 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1213 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1217 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1218 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1219 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1220 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1221 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1222 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1223 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1224 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1226 "screen.yacc"
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

  case 231:

/* Line 1455 of yacc.c  */
#line 1240 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1241 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1242 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1243 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1244 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1245 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1246 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1259 "screen.yacc"
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

  case 245:

/* Line 1455 of yacc.c  */
#line 1269 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1275 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1286 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1286 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1291 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1294 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1300 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1303 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1313 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1317 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1321 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1325 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1329 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1335 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1339 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1342 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1346 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1346 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1353 "screen.yacc"
    {colno++;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1354 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1367 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1375 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1377 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1384 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1388 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1392 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1396 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1400 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1404 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1408 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1414 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1418 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1422 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1426 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1430 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1434 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1438 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1441 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1448 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1452 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1457 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1461 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1468 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1469 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1471 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1507 "screen.yacc"
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); 
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
#line 1516 "screen.yacc"
    {
		if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str)));
		}
	}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1523 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1524 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1525 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1526 "screen.yacc"
    {strcpy((yyval.str),"NULL");}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1532 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1535 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1536 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1539 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1541 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1547 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1549 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1554 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1562 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1565 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1566 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1567 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1568 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1569 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1570 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1572 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1579 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1580 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1583 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1586 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 1590 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 1591 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 1592 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 1593 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 1594 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 1595 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 1597 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 1602 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 1604 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 1611 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 1611 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 1617 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 1624 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 1627 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 1633 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 1634 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
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
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 1638 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 1639 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 1640 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 1641 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 1642 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 1643 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 1644 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 1645 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 1648 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 1655 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 1656 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 1657 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 1665 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 1669 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 1689 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 376:

/* Line 1455 of yacc.c  */
#line 1699 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 1706 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 1715 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 1718 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 1737 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 1744 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 1752 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 1757 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 1765 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 1769 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 1774 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 1779 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 1784 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 1789 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 1794 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 1803 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 1812 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 1813 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 1822 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 1830 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 1836 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 1842 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 1848 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 1856 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 1861 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 1871 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 1881 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 1887 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 1893 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 1899 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 1909 "screen.yacc"
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

  case 410:

/* Line 1455 of yacc.c  */
#line 1921 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 1929 "screen.yacc"
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
#line 1941 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 1949 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 1950 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 1951 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 1955 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 1956 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 1957 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 1958 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 1959 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 1960 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 1961 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 1964 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 1971 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 1982 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 1986 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 1993 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2001 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2007 "screen.yacc"
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

  case 430:

/* Line 1455 of yacc.c  */
#line 2019 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2020 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2026 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2032 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2040 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2048 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2049 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2067 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2069 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2070 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2071 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2072 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2073 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2076 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2077 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2078 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
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
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2086 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2087 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2088 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2089 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2090 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2091 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2097 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2098 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2099 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2100 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2101 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2104 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2108 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;



/* Line 1455 of yacc.c  */
#line 6453 "y.tab.c"
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
#line 2120 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




