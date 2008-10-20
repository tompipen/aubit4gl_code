/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse a4gl_form_yyparse
#define yylex   a4gl_form_yylex
#define yyerror a4gl_form_yyerror
#define yylval  a4gl_form_yylval
#define yychar  a4gl_form_yychar
#define yydebug a4gl_form_yydebug
#define yynerrs a4gl_form_yynerrs


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




/* Copy the first part of user declarations.  */
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

extern struct struct_scr_field *fld;
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 83 "screen.yacc"
{
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
}
/* Line 187 of yacc.c.  */
#line 631 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 644 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   895

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  158
/* YYNRULES -- Number of rules.  */
#define YYNRULES  472
/* YYNRULES -- Number of states.  */
#define YYNSTATES  783

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
     889,   891,   893,   897,   901,   903,   905,   909,   913,   917,
     921,   923,   924,   928,   934,   935,   939,   940,   944,   946,
     949,   951,   953,   955,   957,   959,   961,   964,   966,   967,
     971,   973,   975,   977,   979,   981,   983,   985,   987,   990,
     991,   995,   996,   998,  1001,  1003,  1007,  1011,  1015,  1019,
    1023,  1027,  1032,  1036,  1039,  1042,  1044,  1050,  1056,  1059,
    1063,  1065,  1067,  1069,  1071,  1073,  1075,  1079,  1082,  1084,
    1087,  1095,  1097,  1101,  1105,  1107,  1109,  1111,  1117,  1123,
    1126,  1129,  1131,  1133,  1135,  1137,  1139,  1141,  1143,  1149,
    1150,  1153,  1155,  1160,  1163,  1167,  1170,  1174,  1178,  1180,
    1183,  1186,  1190,  1194,  1199,  1201,  1204,  1206,  1209,  1211,
    1213,  1215,  1217,  1219,  1221,  1223,  1225,  1227,  1229,  1231,
    1235,  1239,  1241,  1246,  1247,  1254,  1255,  1257,  1259,  1263,
    1265,  1267,  1271,  1275,  1278,  1281,  1283,  1286,  1290,  1295,
    1299,  1303,  1307,  1311,  1315,  1319,  1323,  1327,  1331,  1336,
    1340,  1343,  1346,  1352,  1358,  1365,  1367,  1369,  1371,  1373,
    1375,  1377,  1379
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
     291,   331,    -1,    50,   285,    -1,    48,   281,   286,   285,
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
      -1,   345,    -1,    -1,    24,    57,   297,   301,    51,   302,
      52,   298,   300,    -1,   141,    51,    29,    58,    29,    52,
     109,    51,    29,    58,    29,    52,    -1,   338,    -1,   361,
      -1,    -1,   110,   139,    -1,    -1,    53,    -1,    -1,    47,
      -1,   218,    -1,   218,    26,    29,    28,    -1,   305,    -1,
     302,   303,   305,    -1,    -1,    58,    -1,   218,    -1,   218,
      39,   218,    -1,    34,    39,   218,    -1,   218,    39,    53,
      -1,    34,    39,    53,    -1,   304,    -1,   304,    59,   304,
      -1,   218,    -1,    27,    -1,    -1,   308,    -1,   309,    -1,
     308,   309,    -1,   144,    -1,   145,    -1,   218,    -1,    -1,
     307,   218,   312,   307,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,   319,    -1,
      69,   319,    -1,    70,   326,    -1,    71,   320,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,    -1,   140,    -1,   318,
      -1,   314,    58,   318,    -1,   317,    -1,   315,    58,   317,
      -1,    29,    -1,    55,    29,    -1,    56,    29,    -1,    46,
      -1,    30,    -1,    16,    -1,   316,    -1,    41,    -1,    46,
      -1,    30,    -1,    30,   109,    30,    -1,    30,    37,    30,
      -1,    16,    -1,   316,    -1,   316,   109,   316,    -1,   316,
      37,   316,    -1,    46,   109,    46,    -1,    46,    37,    46,
      -1,    41,    -1,    -1,    51,    29,    52,    -1,    51,    29,
      58,    29,    52,    -1,    -1,   323,   109,   325,    -1,    -1,
      51,    29,    52,    -1,    29,    -1,   324,   321,    -1,   132,
      -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,   138,   330,    -1,   324,    -1,    -1,   327,   109,   328,
      -1,   329,    -1,   329,    -1,   132,    -1,   133,    -1,   134,
      -1,   135,    -1,   136,    -1,   137,    -1,   138,   330,    -1,
      -1,    51,   322,    52,    -1,    -1,   332,    -1,   125,   333,
      -1,   334,    -1,   334,   123,   334,    -1,   334,   122,   334,
      -1,   335,   121,   335,    -1,   335,     8,   335,    -1,   335,
       9,   335,    -1,   335,    72,   335,    -1,   335,   126,    72,
     335,    -1,   335,    45,   335,    -1,   335,   130,    -1,   335,
     131,    -1,   335,    -1,   335,   127,   335,   123,   335,    -1,
     335,   128,    51,   337,    52,    -1,   126,   334,    -1,    51,
     334,    52,    -1,   336,    -1,    29,    -1,    46,    -1,   129,
      -1,    30,    -1,   335,    -1,   337,    58,   335,    -1,    18,
     339,    -1,   340,    -1,   339,   340,    -1,     8,   341,     9,
     299,     8,   341,     9,    -1,   342,    -1,   341,    58,   342,
      -1,   343,    39,   344,    -1,   344,    -1,   218,    -1,   217,
      -1,   147,   355,   152,   359,   353,    -1,   148,   356,   152,
     359,   353,    -1,   157,   362,    -1,   156,   362,    -1,   349,
      -1,   354,    -1,   347,    -1,   350,    -1,   351,    -1,   362,
      -1,   352,    -1,   164,   367,   165,   346,   348,    -1,    -1,
     166,   346,    -1,   160,    -1,   161,   310,    45,   367,    -1,
     163,   310,    -1,   163,    45,   310,    -1,   163,   162,    -1,
     163,    45,   162,    -1,   167,   353,    27,    -1,   346,    -1,
     353,   346,    -1,    90,    46,    -1,    90,   159,    46,    -1,
      90,    82,    46,    -1,    90,   159,    82,    46,    -1,   357,
      -1,   355,   357,    -1,   358,    -1,   356,   358,    -1,   149,
      -1,   150,    -1,   151,    -1,   149,    -1,   153,    -1,   154,
      -1,   155,    -1,   151,    -1,    93,    -1,   150,    -1,   360,
      -1,   359,   303,   360,    -1,   343,    39,   344,    -1,   344,
      -1,   343,   146,   343,   300,    -1,    -1,   158,   218,    51,
     363,   364,    52,    -1,    -1,   365,    -1,   366,    -1,   365,
      58,   366,    -1,   367,    -1,   368,    -1,   367,   123,   367,
      -1,   367,   122,   367,    -1,    56,   367,    -1,    55,   367,
      -1,   370,    -1,   126,   367,    -1,    51,   367,    52,    -1,
     369,    51,   364,    52,    -1,   168,   152,   310,    -1,   367,
     121,   367,    -1,   367,     8,   367,    -1,   367,     9,   367,
      -1,   367,    53,   367,    -1,   367,    55,   367,    -1,   367,
      56,   367,    -1,   367,    54,   367,    -1,   367,    72,   367,
      -1,   367,   126,    72,   367,    -1,   367,    45,   367,    -1,
     367,   130,    -1,   367,   131,    -1,   367,   127,   367,   123,
     367,    -1,   367,   128,    51,   371,    52,    -1,   367,   126,
     128,    51,   371,    52,    -1,   218,    -1,   310,    -1,    29,
      -1,    46,    -1,   129,    -1,    41,    -1,   370,    -1,   371,
      58,   370,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   157,   158,   163,   164,   173,   174,   178,
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
     690,   689,   708,   709,   710,   714,   718,   714,   899,   900,
     904,   912,   913,   916,   917,   920,   923,   928,   937,   949,
     961,   968,   976,   983,   996,  1005,  1014,  1021,  1023,  1026,
    1032,  1033,  1034,  1035,  1038,  1039,  1043,  1044,  1048,  1048,
    1051,  1052,  1072,  1094,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1119,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
    1128,  1129,  1130,  1131,  1135,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1161,  1162,  1163,  1164,  1165,  1166,  1172,
    1173,  1174,  1178,  1179,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1192,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1216,  1217,  1220,  1220,  1222,  1222,  1225,  1235,  1241,  1241,
    1244,  1245,  1246,  1250,  1250,  1252,  1252,  1255,  1255,  1257,
    1260,  1266,  1269,  1273,  1274,  1278,  1280,  1282,  1284,  1286,
    1291,  1291,  1295,  1298,  1302,  1302,  1305,  1305,  1309,  1310,
    1323,  1331,  1331,  1340,  1344,  1348,  1352,  1356,  1360,  1364,
    1370,  1374,  1378,  1382,  1386,  1390,  1394,  1397,  1404,  1404,
    1408,  1408,  1413,  1413,  1413,  1417,  1424,  1425,  1426,  1427,
    1433,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1451,
    1455,  1460,  1463,  1464,  1467,  1468,  1475,  1477,  1482,  1490,
    1493,  1494,  1495,  1496,  1497,  1498,  1499,  1505,  1507,  1508,
    1511,  1514,  1518,  1519,  1520,  1521,  1522,  1523,  1524,  1530,
    1532,  1539,  1539,  1545,  1551,  1552,  1555,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573,
    1576,  1583,  1584,  1585,  1590,  1593,  1597,  1609,  1612,  1613,
    1617,  1627,  1634,  1643,  1646,  1658,  1661,  1665,  1672,  1680,
    1685,  1693,  1697,  1702,  1707,  1712,  1717,  1722,  1731,  1740,
    1741,  1746,  1749,  1757,  1763,  1769,  1775,  1784,  1789,  1799,
    1809,  1815,  1821,  1827,  1837,  1849,  1857,  1869,  1877,  1878,
    1879,  1883,  1884,  1885,  1886,  1887,  1888,  1889,  1892,  1899,
    1910,  1914,  1921,  1929,  1929,  1947,  1948,  1954,  1960,  1968,
    1975,  1976,  1977,  1991,  1993,  1994,  1995,  1996,  1997,  2000,
    2001,  2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,
    2011,  2012,  2013,  2014,  2015,  2018,  2021,  2022,  2023,  2024,
    2025,  2028,  2032
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
  "grid_section", "@1", "@2", "@3", "table_section", "@4", "@5", "@6",
  "layout_attributes", "@7", "layout_attribute", "layout_attribute_list",
  "op_layout_items", "layout_items", "layout_container", "layout_section",
  "screen_section", "screens_section", "@8", "@9", "screens_rest", "@10",
  "@11", "@12", "op_extended", "op_size", "op_end", "screen_layout",
  "some_text", "screen_element", "ch_list", "field", "@13",
  "field_element", "@14", "op_table_section", "table_def_list",
  "table_def", "opequal", "table_qualifier", "attribute_section",
  "field_tag_list", "op_field_tag_type", "field_tag", "@15", "fpart_list",
  "fpart", "@16", "@17", "op_att", "field_datatype_null", "field_datatype",
  "field_type", "lu_ft_eq_c", "lu_ft_eq_c_i", "lu_ft", "lu_fc",
  "lu_joincol", "lu_join", "op_field_desc", "op_desc_list", "desc",
  "def_val", "colors", "color", "op_instruction_section", "instruct_opts",
  "instruct_op_1", "instruct_op", "@18", "op_ltype", "op_star", "op_semi",
  "srec_dim", "srec_field_list", "op_comma", "field_list_item",
  "field_list_element", "field_name", "op_ws", "ws", "ws_elem",
  "field_tag_name", "field_tag_name_scr", "@19", "datatype", "incl_list",
  "items_list", "number_value", "items_entry", "incl_entry", "opt_dec_ext",
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
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   319,   319,   319,   320,   320,   321,   321,   322,   323,
     324,   324,   324,   324,   324,   324,   324,   325,   326,   326,
     327,   328,   329,   329,   329,   329,   329,   329,   329,   330,
     330,   331,   331,   332,   333,   333,   333,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     335,   335,   335,   335,   336,   337,   337,   338,   339,   339,
     340,   341,   341,   342,   342,   343,   344,   345,   345,   345,
     345,   346,   346,   346,   346,   346,   346,   346,   347,   348,
     348,   349,   350,   351,   351,   351,   351,   352,   353,   353,
     354,   354,   354,   354,   355,   355,   356,   356,   357,   357,
     357,   358,   358,   358,   358,   358,   358,   358,   359,   359,
     360,   360,   361,   363,   362,   364,   364,   365,   365,   366,
     367,   367,   367,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   369,   370,   370,   370,   370,
     370,   371,   371
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
       1,     1,     3,     3,     1,     1,     3,     3,     3,     3,
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
       1,     3,     3,     2,     2,     1,     2,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       2,     2,     5,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     3
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
       0,     0,     0,     0,     0,     0,   385,    70,   242,   244,
     251,     0,   247,   252,    69,    62,     0,     0,     0,    38,
      41,     0,    18,    47,    17,    27,    19,    31,    34,    20,
      22,     0,     0,     0,     0,     0,     0,   377,   378,   248,
     246,     0,   418,   419,   420,     0,   414,   426,   421,   427,
     425,   422,   423,   424,     0,   416,     0,   390,   389,   241,
     243,   245,     0,     0,     0,     0,     0,    36,     0,    42,
       0,     0,    44,   105,   101,   102,   104,   125,     0,   122,
       7,     8,   386,     0,   381,     0,   384,   379,     0,     0,
       0,   415,     0,   417,     0,   257,    85,    78,    87,    79,
      80,    84,    83,    82,    77,    74,     0,    75,    72,    81,
      76,    39,    40,    37,    43,     0,     0,     0,     0,     0,
     121,   123,   255,     0,     0,   259,     0,     0,     0,   431,
     263,   428,   263,   433,   258,   432,   274,    63,    73,    86,
      28,    32,    23,   103,     0,     0,   133,   141,   128,   124,
     256,     0,   382,   383,     0,     0,     0,     0,   264,     0,
     401,     0,     0,     0,     0,     0,   408,   393,   391,   394,
     395,   397,   387,   392,   396,   388,   435,   278,   279,     0,
       0,   275,   276,    89,    70,     0,     0,     0,   143,     0,
       0,   138,   132,     0,     0,   126,     0,     0,     0,   265,
     263,   270,   261,     0,   430,   410,     0,     0,     0,     0,
     405,   403,   467,   470,   468,     0,     0,     0,     0,   469,
       0,   280,   466,     0,   440,     0,   445,     0,   429,   409,
       0,   436,   437,   439,    88,    90,   281,   277,    64,    29,
      33,   273,   272,   133,     0,   283,   284,   285,   286,   287,
     288,   321,   321,   338,   324,     0,   293,   294,   295,   296,
     297,   136,   133,     0,   140,     0,   156,     0,   260,     0,
       0,   253,     0,     0,     0,   412,   411,     0,     0,   406,
     404,     0,   444,   443,   446,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     460,   461,     0,   435,   407,   434,     0,   274,   274,   137,
     142,     0,   289,   290,   342,   343,   344,   345,   346,   347,
     349,   291,     0,   340,   330,   331,   332,   333,   334,   335,
     349,   292,     0,   326,   135,   139,   131,   129,     0,     0,
     127,   380,   269,   267,   268,   266,     0,   257,   262,   271,
       0,   413,   402,   447,   449,   451,   452,   459,   453,   456,
     454,   455,   457,   450,   442,   441,     0,     0,     0,     0,
     399,     0,   438,    91,   282,     0,     0,   348,     0,   336,
       0,     0,   329,     0,     0,   180,     0,     0,   187,   160,
       0,     0,     0,     0,     0,   171,   172,     0,     0,   178,
     183,   182,     0,     0,   186,   189,   188,   192,     0,   181,
       0,     0,   191,   190,     0,     0,   195,   201,     0,     0,
     197,   198,   196,     0,     0,   205,   206,   207,   208,   209,
       0,     0,     0,     0,     0,     0,   157,   158,   254,   249,
       0,   458,     0,     0,   471,     0,     0,   398,   448,   322,
       0,   328,     0,   339,   341,   337,   325,     0,   134,   130,
       0,     0,   144,     0,   147,     0,   151,   162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   462,   463,     0,
     400,     0,   350,   327,     0,   154,     0,     0,     0,   153,
       0,   232,   224,   225,   226,   227,   228,   229,   230,   231,
     235,   233,   236,   237,   238,   239,   234,   351,   222,   164,
     220,   219,   221,   165,   169,   167,   173,     0,   184,   185,
     217,   175,   176,   177,   218,   202,   199,   200,   204,   203,
       0,   211,   212,   166,   215,   213,   216,   214,   159,     0,
     464,   472,   323,   179,   155,   145,   163,   149,   146,     0,
     150,     0,   223,   161,   352,     0,     0,   314,   302,   311,
     320,   310,     0,     0,     0,   315,   298,   307,   306,   309,
     305,     0,   308,   300,   250,     0,   152,   371,   374,   372,
       0,     0,   373,   353,   354,   365,   370,   170,   168,     0,
       0,     0,     0,   303,   304,   174,     0,     0,     0,   210,
       0,   148,     0,   368,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,   364,   313,   312,   319,   318,
     299,   317,   316,   301,   369,   356,   355,   358,   359,   362,
     360,   357,     0,     0,     0,   361,     0,   375,     0,   366,
     367,     0,   376
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
     704,   711,   705,   713,   706,   432,   451,   502,   572,   452,
     453,   576,   441,   442,   573,   443,   497,   693,   694,   723,
     724,   725,   726,   778,   130,   157,   158,   203,   204,   205,
     206,   132,   286,   287,   567,   288,   289,   290,   291,   292,
     293,   165,   174,   166,   175,   250,   251,   133,   294,   296,
     350,   351,   352,   353,   344,   345,   346,   565
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -469
static const yytype_int16 yypact[] =
{
       4,   -17,    64,   -21,  -469,    91,  -469,   135,   137,   147,
    -469,    -6,  -469,   289,   155,  -469,   237,  -469,   184,    57,
      57,   188,  -469,   217,    57,    57,  -469,    57,  -469,    57,
    -469,  -469,  -469,  -469,  -469,  -469,   225,    57,   230,  -469,
     222,  -469,  -469,  -469,  -469,   247,   217,   272,  -469,  -469,
    -469,   255,   255,    57,   255,    57,   255,  -469,  -469,   231,
      19,  -469,   682,   298,  -469,  -469,  -469,   299,   148,  -469,
     289,   289,   255,   289,   255,   167,    51,  -469,    57,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,    -7,    57,  -469,   345,  -469,   314,  -469,   317,   102,
     323,   289,  -469,   334,   341,   338,   349,    57,   -18,  -469,
     352,   371,  -469,  -469,  -469,  -469,  -469,  -469,   360,   359,
     353,   354,   263,   407,   260,   260,  -469,   241,  -469,   373,
    -469,   276,  -469,  -469,  -469,  -469,   405,   408,   411,  -469,
    -469,    40,  -469,  -469,  -469,  -469,  -469,  -469,   255,  -469,
    -469,    57,    57,    57,    57,   414,    59,   360,  -469,  -469,
    -469,   445,  -469,  -469,  -469,   329,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,   378,  -469,    57,  -469,  -469,  -469,
    -469,  -469,    57,   509,   430,   452,   437,  -469,   102,  -469,
     509,   509,   289,  -469,  -469,   423,  -469,  -469,    16,  -469,
     446,   457,  -469,     7,  -469,   458,  -469,  -469,    57,   433,
      59,  -469,    59,  -469,   447,   459,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,   431,  -469,  -469,   491,
    -469,  -469,  -469,  -469,  -469,   473,   478,   482,    57,    42,
     414,  -469,   460,    59,    77,   485,   461,   486,   475,  -469,
     151,  -469,   151,  -469,  -469,  -469,   128,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,   477,    57,   -23,   479,   494,  -469,
    -469,   513,  -469,  -469,   505,    52,   471,    77,  -469,     8,
    -469,    57,     0,    -3,   291,    59,  -469,  -469,  -469,  -469,
    -469,  -469,   291,  -469,  -469,   291,    -3,  -469,  -469,   223,
      57,   128,  -469,  -469,   225,   510,   511,     2,   497,   709,
     498,  -469,   416,    57,   515,  -469,    59,   517,   507,   520,
     238,   490,  -469,   441,  -469,  -469,   506,   153,   518,    -2,
    -469,  -469,  -469,  -469,  -469,    -3,    -3,    -3,    -3,  -469,
     402,   514,  -469,   177,  -469,   516,  -469,    76,  -469,  -469,
     512,   519,  -469,   583,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,   521,    57,  -469,  -469,  -469,  -469,  -469,
    -469,   523,   523,   655,   665,    57,  -469,  -469,  -469,  -469,
    -469,  -469,   521,   529,  -469,    27,   522,    33,  -469,    53,
      71,   468,    52,    52,   528,  -469,  -469,   525,    -3,  -469,
    -469,   560,   583,   583,   583,    57,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    86,    -3,   531,
    -469,  -469,   291,    -3,  -469,  -469,    -3,   128,   128,  -469,
    -469,   555,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
     534,  -469,   487,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
     534,  -469,   488,   535,   548,  -469,  -469,  -469,   559,   234,
    -469,  -469,  -469,  -469,  -469,  -469,   462,   459,  -469,  -469,
     570,  -469,   583,  -469,  -469,   714,   714,   583,   583,   583,
     583,   583,   583,   583,   583,   583,    -3,   551,   595,    75,
     440,   558,  -469,  -469,  -469,   297,   590,  -469,   655,  -469,
     665,   598,  -469,    57,   596,   605,    57,   152,  -469,  -469,
     586,   589,   597,   563,   569,  -469,  -469,   599,   600,  -469,
    -469,  -469,   607,   611,  -469,  -469,  -469,   179,   614,  -469,
     615,   616,  -469,  -469,   619,   620,  -469,  -469,   621,   623,
    -469,  -469,  -469,   624,   626,  -469,  -469,  -469,  -469,  -469,
     629,   630,   633,   634,   635,   640,   585,  -469,  -469,  -469,
     604,   583,    75,    -3,  -469,   327,   291,  -469,  -469,  -469,
     660,  -469,   641,  -469,  -469,  -469,  -469,   642,  -469,  -469,
     647,    60,  -469,   650,  -469,    57,   658,  -469,   731,   652,
      10,    57,    57,   653,   651,   657,   661,  -469,  -469,   662,
     666,   669,    57,   673,   674,    99,   672,   695,   676,   699,
     700,    10,   166,   209,   234,   701,   335,   583,  -469,    75,
    -469,   679,  -469,  -469,   703,  -469,   196,   152,    57,   696,
      57,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,   671,  -469,  -469,
    -469,  -469,  -469,  -469,   697,   698,  -469,   617,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
     809,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,   689,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,   722,  -469,    57,
    -469,   228,  -469,  -469,  -469,    57,    57,  -469,  -469,   -25,
    -469,   -13,   705,   733,   342,    13,  -469,  -469,  -469,  -469,
    -469,   343,  -469,  -469,  -469,    57,  -469,  -469,  -469,  -469,
     228,   228,  -469,  -469,   304,   612,  -469,  -469,  -469,   734,
     735,   717,   720,  -469,  -469,  -469,   617,   198,   198,  -469,
     809,  -469,   730,  -469,   228,   228,    82,    82,    82,    82,
      82,   711,    82,   743,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,    82,   708,    82,  -469,    82,  -469,   344,  -469,
    -469,    82,  -469
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -469,  -469,  -469,   783,   -19,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,   677,   337,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,  -469,     6,  -469,   -75,  -469,   -40,  -469,     1,  -469,
    -469,   779,  -469,  -469,   773,  -469,  -469,  -469,  -469,  -469,
     -56,   251,  -469,   141,  -469,  -469,  -469,  -469,  -469,  -469,
    -469,   130,  -469,  -469,  -469,  -469,  -469,   742,  -469,  -469,
    -147,  -469,  -469,  -469,  -135,  -469,  -469,  -469,   208,  -469,
    -469,   197,  -469,  -469,  -469,   229,   235,  -469,   200,  -469,
    -469,   721,  -469,  -469,  -469,  -469,   384,  -469,  -469,   533,
     464,   466,  -469,   432,  -469,   561,   -85,   436,  -469,  -469,
    -469,  -469,  -460,   119,   138,   499,  -469,  -469,  -469,  -469,
     375,  -469,  -469,  -469,  -469,   379,   426,  -469,  -469,  -469,
    -361,    80,  -469,  -469,  -469,  -469,   716,   562,   636,   -83,
     134,  -469,  -273,  -469,  -469,  -469,  -469,  -469,  -469,  -205,
    -469,  -469,  -469,   715,   707,   670,   601,  -469,   348,  -469,
     465,  -469,   467,  -268,  -469,  -469,  -468,   321
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -466
static const yytype_int16 yytable[] =
{
      43,    44,    11,    12,    79,    50,    50,   117,    50,   149,
      50,   131,   729,     4,    36,   343,   242,     5,    59,   349,
      57,   564,   349,  -109,   731,     1,   332,    41,    41,   361,
      41,   103,    41,   105,    50,   114,    50,   309,   333,   650,
      22,    59,   461,   334,   131,   329,    57,   295,   335,    41,
     737,   241,   336,   337,   325,   457,   651,   111,    71,    59,
      73,   197,    75,   240,    10,   243,   189,   401,   402,   403,
     404,   179,    41,   116,   349,   126,   264,    78,   104,   347,
     106,    41,    41,    41,   730,   458,   318,    41,    50,   200,
     326,   243,   187,   269,   564,   265,   732,   110,   188,   215,
       6,    41,   143,   424,   332,    41,   462,     4,   126,   625,
    -109,   717,   718,   234,    42,    42,   333,    42,   626,    42,
     310,   334,   738,   338,   464,   652,   339,   248,   719,   248,
     472,    18,   193,   194,   195,   196,    42,   126,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   490,
     488,   681,   237,   136,   192,     7,   107,   214,   486,    42,
     399,    13,   330,   126,   225,   340,   279,   327,    42,    42,
      42,   225,   225,    19,    42,    20,   201,    81,    82,    83,
      84,    85,    41,    86,   266,   406,   407,    21,    42,   245,
      80,   126,    42,   126,     6,   674,   328,   331,    37,   396,
      87,    88,   248,    89,   339,   585,    90,   225,   113,   278,
     712,   722,   675,   137,   487,   136,   225,   225,   561,   263,
     267,   138,   408,   139,   126,    40,    41,   698,   429,    45,
     409,   410,   411,   412,   176,   397,   280,   281,   676,   282,
     283,   279,    47,   284,   400,   684,   308,   455,   358,   413,
      62,   354,    57,   702,   703,   677,   319,   717,   718,   118,
      11,    12,   116,   116,    64,   119,   126,   355,    57,    42,
     505,    41,   297,   298,   719,   137,    76,   761,   762,   720,
     712,   356,   506,   138,   507,   139,   597,   598,   362,    65,
     391,   666,   667,   620,   384,   617,   278,   126,   414,   415,
     416,    67,   120,   417,   418,   419,    69,   420,   421,   176,
     116,   280,   281,    42,   282,   283,   508,    94,   284,    97,
     474,    96,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   107,   422,   134,   249,   430,   249,   528,   135,   569,
     142,   529,   530,   531,   721,   570,   454,   722,    42,   742,
     743,   144,    52,   118,    54,   146,    56,   258,   156,   119,
     463,   465,   145,   319,   319,    41,   258,   258,   273,   618,
     147,   279,   121,   765,   766,   619,   116,   680,   122,   123,
      72,   151,    74,   619,   735,   739,   780,   124,   125,   160,
     736,   740,   781,   532,   533,   161,   120,   534,   152,   153,
     154,   324,   162,   163,   164,   535,   159,   536,   176,   249,
     181,   584,   182,   537,   538,   539,   744,   745,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   235,   236,   553,   148,   554,   555,   216,   217,   176,
     184,   280,   281,   185,   282,   283,   186,   218,   284,   197,
     238,    41,    42,   257,    24,    25,    26,    27,    28,    29,
     116,   167,   177,   178,   209,   219,   231,   220,   162,   163,
     164,   210,   232,   233,   578,    -9,   121,   116,   586,   216,
     217,   247,   122,   123,   216,   217,   -10,   244,   253,   218,
     167,   124,   125,    41,   218,   260,   254,   259,    41,   262,
     261,   274,   275,   270,   277,   276,   307,   219,   313,   220,
     314,   316,   219,   323,   220,   216,   217,   168,   169,   170,
     212,   171,   172,   173,   317,   218,   364,   359,   360,    41,
     382,   584,   383,   116,   385,   388,   389,   221,    42,   393,
     394,   222,   395,   219,   405,   220,   168,   169,   170,   390,
     171,   172,   173,   398,   425,  -465,   629,   423,   406,   407,
     456,   471,   654,   655,   431,   223,   224,   426,   466,   470,
     459,   309,   489,   663,   495,   496,   501,   503,   504,   221,
      42,   406,   407,   222,   221,    42,   498,   500,   222,   560,
     116,   558,   562,   406,   407,   408,   566,   116,   586,   687,
     568,   690,   473,   409,   410,   411,   412,   223,   224,   571,
     746,   747,   223,   224,   579,   221,    42,   577,   408,   222,
     580,   588,   413,   697,   589,   591,   409,   410,   411,   412,
     408,   592,   590,   614,   593,   594,   698,   699,   409,   410,
     411,   412,   595,   223,   224,   413,   596,   748,   700,   599,
     600,   601,   615,   701,   602,   603,   604,   413,   605,   606,
     716,   607,   702,   703,   608,   609,   727,   728,   610,   611,
     612,   414,   415,   416,   749,   613,   417,   418,   419,   621,
     420,   421,   624,   622,   623,   628,   741,   630,   649,   656,
     631,   668,   657,   658,   414,   415,   416,   659,   660,   417,
     418,   419,   661,   420,   421,   662,   414,   415,   563,   664,
     665,   417,   418,   419,   669,   420,   421,   670,   671,   672,
     679,   682,   683,   750,   733,   689,   695,   696,   751,   752,
     753,   714,   754,   755,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   408,
     631,   715,   734,   758,   756,   757,   759,   409,   410,   411,
     412,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   764,   772,     8,   150,   413,   434,   435,   436,
     437,   438,   439,   440,   774,    39,   691,   444,   445,   446,
     447,   448,   449,   450,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,    66,
     376,   377,   378,   379,   686,   707,   767,   768,   769,   770,
     771,   776,   773,   115,   685,   414,   415,   416,   698,   708,
     417,   418,   419,   678,   420,   421,   673,   692,   180,   380,
     709,   559,   775,   392,   777,   710,   779,   469,   468,   763,
     494,   782,   357,   493,   702,   703,    81,    82,    83,    84,
      85,   433,    86,   207,   760,   575,   499,   574,   387,   272,
     211,   213,   252,   616,     0,     0,   348,     0,   491,    87,
      88,     0,    89,   492,     0,    90
};

static const yytype_int16 yycheck[] =
{
      19,    20,    23,    24,    60,    24,    25,    92,    27,    27,
      29,    94,    37,    30,    13,   283,     9,    34,    37,   292,
      27,   489,   295,    30,    37,    21,    29,    30,    30,    27,
      30,    71,    30,    73,    53,    91,    55,    60,    41,    29,
      46,    60,     9,    46,   127,    45,    27,   252,    51,    30,
      37,   198,    55,    56,    46,    28,    46,    76,    52,    78,
      54,    45,    56,    47,     0,    58,   141,   335,   336,   337,
     338,   127,    30,    92,   347,    94,    34,    58,    72,   284,
      74,    30,    30,    30,   109,    58,    34,    30,   107,    30,
      82,    58,    52,   240,   562,    53,   109,    46,    58,   182,
     117,    30,   101,    27,    29,    30,    53,    30,   127,    49,
     117,    29,    30,   188,   117,   117,    41,   117,    58,   117,
     143,    46,   109,   126,    53,   115,   129,   210,    46,   212,
     398,    40,   151,   152,   153,   154,   117,   156,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   422,
     418,   619,   192,   113,   148,   172,   174,   176,    72,   117,
     162,   182,   162,   182,   183,   168,    90,   159,   117,   117,
     117,   190,   191,    38,   117,    38,   117,   184,   185,   186,
     187,   188,    30,   190,   142,     8,     9,    40,   117,   208,
      60,   210,   117,   212,   117,    29,   281,   282,    43,    46,
     207,   208,   285,   210,   129,    53,   213,   226,    78,    58,
     670,   129,    46,   173,   128,   113,   235,   236,   486,   238,
     239,   181,    45,   183,   243,    41,    30,    29,   363,    41,
      53,    54,    55,    56,   158,    82,   160,   161,    29,   163,
     164,    90,    25,   167,   329,    49,   265,   382,   304,    72,
      20,    28,    27,    55,    56,    46,   275,    29,    30,    18,
      23,    24,   281,   282,    42,    24,   285,    44,    27,   117,
      36,    30,   144,   145,    46,   173,    45,   737,   738,    51,
     740,   300,    48,   181,    50,   183,   107,   108,   307,    42,
      52,   192,   193,   566,   313,   563,    58,   316,   121,   122,
     123,    29,    61,   126,   127,   128,    51,   130,   131,   158,
     329,   160,   161,   117,   163,   164,    82,    19,   167,   171,
     405,    22,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   174,   165,    29,   210,   364,   212,   113,    31,    52,
      27,   117,   118,   119,   126,    58,   375,   129,   117,   720,
     721,    27,    25,    18,    27,    27,    29,   226,     8,    24,
     389,   390,    31,   392,   393,    30,   235,   236,   244,    52,
      31,    90,   141,   744,   745,    58,   405,    52,   147,   148,
      53,    39,    55,    58,    52,    52,    52,   156,   157,    46,
      58,    58,    58,   169,   170,    51,    61,   173,    37,    38,
      39,   277,   149,   150,   151,   181,    57,   183,   158,   285,
      47,   506,   146,   189,   190,   191,   122,   123,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   190,   191,   209,   107,   211,   212,    16,    17,   158,
      45,   160,   161,    45,   163,   164,    45,    26,   167,    45,
      37,    30,   117,    32,   175,   176,   177,   178,   179,   180,
     489,    93,   124,   125,    29,    44,    46,    46,   149,   150,
     151,   152,    30,    46,   503,    39,   141,   506,   507,    16,
      17,    58,   147,   148,    16,    17,    39,    39,    51,    26,
      93,   156,   157,    30,    26,    32,    47,    16,    30,    27,
      32,    26,    51,    53,    39,    29,    39,    44,    39,    46,
      26,     8,    44,    52,    46,    16,    17,   149,   150,   151,
     152,   153,   154,   155,    29,    26,    39,    27,    27,    30,
      42,   626,   126,   562,    29,    28,    39,   116,   117,    59,
     109,   120,    46,    44,   152,    46,   149,   150,   151,    39,
     153,   154,   155,    45,    52,    51,   585,    51,     8,     9,
      41,    46,   591,   592,    51,   144,   145,    58,   110,    51,
      58,    60,    51,   602,    29,    51,    51,    39,    29,   116,
     117,     8,     9,   120,   116,   117,   109,   109,   120,    29,
     619,   139,    51,     8,     9,    45,   166,   626,   627,   628,
      52,   630,    52,    53,    54,    55,    56,   144,   145,    29,
       8,     9,   144,   145,    28,   116,   117,    29,    45,   120,
      25,    45,    72,    16,    45,    72,    53,    54,    55,    56,
      45,    72,    45,    58,    45,    45,    29,    30,    53,    54,
      55,    56,    45,   144,   145,    72,    45,    45,    41,    45,
      45,    45,    58,    46,    45,    45,    45,    72,    45,    45,
     689,    45,    55,    56,    45,    45,   695,   696,    45,    45,
      45,   121,   122,   123,    72,    45,   126,   127,   128,    29,
     130,   131,    45,    52,    52,    45,   715,    39,    46,    46,
      29,    29,    51,    46,   121,   122,   123,    46,    46,   126,
     127,   128,    46,   130,   131,    46,   121,   122,   123,    46,
      46,   126,   127,   128,    29,   130,   131,    51,    29,    29,
      29,    52,    29,   121,    29,    39,    39,    39,   126,   127,
     128,    52,   130,   131,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    45,
      29,    39,    29,    46,    30,    30,    46,    53,    54,    55,
      56,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    52,    72,     1,   108,    72,   132,   133,   134,
     135,   136,   137,   138,    51,    16,   125,   132,   133,   134,
     135,   136,   137,   138,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    46,
     111,   112,   113,   114,   627,    16,   746,   747,   748,   749,
     750,   123,   752,    91,   626,   121,   122,   123,    29,    30,
     126,   127,   128,   614,   130,   131,   611,   647,   127,   140,
      41,   467,   772,   320,   774,    46,   776,   393,   392,   740,
     428,   781,   301,   427,    55,    56,   184,   185,   186,   187,
     188,   372,   190,   157,   736,   500,   450,   498,   316,   243,
     165,   174,   212,   562,    -1,    -1,   285,    -1,   423,   207,
     208,    -1,   210,   426,    -1,   213
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
     338,   343,   345,   361,    29,    31,   113,   173,   181,   183,
     238,   239,    27,   242,    27,    31,    27,    31,   227,    27,
     226,    39,    37,    38,    39,   272,     8,   339,   340,    57,
      46,    51,   149,   150,   151,   355,   357,    93,   149,   150,
     151,   153,   154,   155,   356,   358,   158,   362,   362,   254,
     295,    47,   146,   250,    45,    45,    45,    52,    58,   238,
     230,   234,   236,   218,   218,   218,   218,    45,   273,   274,
      30,   117,   217,   341,   342,   343,   344,   340,   297,    29,
     152,   357,   152,   358,   218,   343,    16,    17,    26,    44,
      46,   116,   120,   144,   145,   218,   255,   256,   257,   258,
     259,    46,    30,    46,   238,   255,   255,   240,    37,   275,
      47,   274,     9,    58,    39,   218,   301,    58,   343,   344,
     359,   360,   359,    51,    47,   300,   260,    32,   257,    16,
      32,    32,    27,   218,    34,    53,   142,   218,   280,   274,
      53,   299,   342,   344,    26,    51,    29,    39,    58,    90,
     160,   161,   163,   164,   167,   303,   346,   347,   349,   350,
     351,   352,   353,   354,   362,   353,   363,   144,   145,   261,
     307,   308,   309,   311,   251,   231,   235,    39,   218,    60,
     143,   278,   279,    39,    26,   277,     8,    29,    34,   218,
     302,   304,   305,    52,   344,    46,    82,   159,   310,    45,
     162,   310,    29,    41,    46,    51,    55,    56,   126,   129,
     168,   218,   310,   367,   368,   369,   370,   353,   360,   346,
     364,   365,   366,   367,    28,    44,   218,   309,   254,    27,
      27,    27,   218,   306,    39,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,   111,   112,   113,   114,
     140,   313,    42,   126,   218,    29,   276,   341,    28,    39,
      39,    52,   303,    59,   109,    46,    46,    82,    45,   162,
     310,   367,   367,   367,   367,   152,     8,     9,    45,    53,
      54,    55,    56,    72,   121,   122,   123,   126,   127,   128,
     130,   131,   165,    51,    27,    52,    58,   262,   312,   278,
     218,    51,   319,   319,   132,   133,   134,   135,   136,   137,
     138,   326,   327,   329,   132,   133,   134,   135,   136,   137,
     138,   320,   323,   324,   218,   278,    41,    28,    58,    58,
     287,     9,    53,   218,    53,   218,   110,   298,   305,   304,
      51,    46,   367,    52,   310,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,    72,   128,   367,    51,
     346,   364,   366,   311,   307,    29,    51,   330,   109,   330,
     109,    51,   321,    39,    29,    36,    48,    50,    82,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   113,   117,
     118,   119,   169,   170,   173,   181,   183,   189,   190,   191,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   209,   211,   212,   288,   289,   139,   300,
      29,   367,    51,   123,   370,   371,   166,   348,    52,    52,
      58,    29,   322,   328,   329,   324,   325,    29,   218,    28,
      25,   281,   282,   283,   310,    53,   218,   285,    45,    45,
      45,    72,    72,    45,    45,    45,    45,   107,   108,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    58,    58,   371,   367,    52,    58,
     346,    29,    52,    52,    45,    49,    58,   286,    45,   218,
      39,    29,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   291,   292,    46,
      29,    46,   115,   290,   218,   218,    46,    51,    46,    46,
      46,    46,    46,   218,    46,    46,   192,   193,    29,    29,
      51,    29,    29,   290,    29,    46,    29,    46,   289,    29,
      52,   370,    52,    29,    49,   282,   285,   218,   284,    39,
     218,   125,   292,   331,   332,    39,    39,    16,    29,    30,
      41,    46,    55,    56,   314,   316,   318,    16,    30,    41,
      46,   315,   316,   317,    52,    39,   218,    29,    30,    46,
      51,   126,   129,   333,   334,   335,   336,   218,   218,    37,
     109,    37,   109,    29,    29,    52,    58,    37,   109,    52,
      58,   218,   334,   334,   122,   123,     8,     9,    45,    72,
     121,   126,   127,   128,   130,   131,    30,    30,    46,    46,
     318,   316,   316,   317,    52,   334,   334,   335,   335,   335,
     335,   335,    72,   335,    51,   335,   123,   335,   337,   335,
      52,    58,   335
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 152 "screen.yacc"
    {
A4GL_check_compiled_form();
A4GL_write_form();}
    break;

  case 3:
#line 157 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:
#line 158 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 163 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 164 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 11:
#line 183 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:
#line 184 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:
#line 186 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 15:
#line 191 "screen.yacc"
    {
			the_form.layout=NULL;
	}
    break;

  case 16:
#line 194 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 17:
#line 201 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 18:
#line 211 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 19:
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
#line 233 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 21:
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
#line 251 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 23:
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
#line 272 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 26:
#line 278 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 27:
#line 281 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 28:
#line 284 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 29:
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
#line 300 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 31:
#line 303 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:
#line 306 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:
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
#line 320 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 35:
#line 323 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 36:
#line 323 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 37:
#line 329 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 38:
#line 332 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 39:
#line 335 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 40:
#line 338 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 44:
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
#line 359 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 46:
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
#line 375 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 48:
#line 383 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 49:
#line 385 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 50:
#line 387 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 51:
#line 389 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:
#line 391 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 53:
#line 393 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 54:
#line 399 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(2) - (3)].layout);
	}
    break;

  case 57:
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
#line 442 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 62:
#line 444 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 63:
#line 447 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 66:
#line 452 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 69:
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
#line 508 "screen.yacc"
    { ltab=0; }
    break;

  case 77:
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
#line 567 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 83:
#line 572 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 84:
#line 575 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 85:
#line 583 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 86:
#line 584 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 87:
#line 590 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 88:
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
#line 611 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 90:
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
#line 625 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 97:
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
#line 650 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 99:
#line 651 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 100:
#line 654 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 101:
#line 655 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 102:
#line 657 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 103:
#line 658 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 104:
#line 659 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 109:
#line 675 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 110:
#line 676 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 111:
#line 677 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 112:
#line 678 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 113:
#line 679 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 114:
#line 680 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 115:
#line 681 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 116:
#line 682 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 117:
#line 683 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 118:
#line 684 "screen.yacc"
    {strcpy((yyval.str),"CheckBox");}
    break;

  case 119:
#line 685 "screen.yacc"
    {strcpy((yyval.str),"Browser");}
    break;

  case 120:
#line 690 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 121:
#line 696 "screen.yacc"
    {
			if (strcmp((yyvsp[(1) - (5)].str),"Edit")!=0) {
				if (A4GL_has_str_attribute(fld,FA_S_WIDGET)) {
					yyerror("Field already has a widget");
				} else {
					A4GL_add_str_attr(fld,FA_S_WIDGETTYPE,(yyvsp[(1) - (5)].str));
				}
			}
		}
    break;

  case 125:
#line 714 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 126:
#line 718 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 127:
#line 726 "screen.yacc"
    {
	int cnt;
	if (A4GL_has_str_attribute(fld,FA_S_FORMAT)) {
		int dtype;
		dtype=fld->datatype & DTYPE_MASK;

		if (dtype!=DTYPE_INT  &&
		    dtype!=DTYPE_SMINT  &&
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
#line 900 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 130:
#line 904 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 131:
#line 912 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 132:
#line 913 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 133:
#line 916 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 134:
#line 917 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 135:
#line 920 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 136:
#line 923 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 137:
#line 928 "screen.yacc"
    {
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
#line 937 "screen.yacc"
    {
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
#line 949 "screen.yacc"
    {
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
#line 961 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 141:
#line 968 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 142:
#line 976 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 143:
#line 983 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 144:
#line 996 "screen.yacc"
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
#line 1005 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 146:
#line 1014 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 148:
#line 1023 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 149:
#line 1026 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 150:
#line 1032 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 151:
#line 1033 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 152:
#line 1034 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 153:
#line 1035 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 160:
#line 1051 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 161:
#line 1052 "screen.yacc"
    {
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
#line 1072 "screen.yacc"
    {
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
#line 1094 "screen.yacc"
    {
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 164:
#line 1100 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 165:
#line 1101 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 166:
#line 1102 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_OPTIONS,(yyvsp[(3) - (3)].str)); }
    break;

  case 167:
#line 1103 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 168:
#line 1104 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 169:
#line 1105 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 170:
#line 1106 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 171:
#line 1107 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 172:
#line 1108 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 173:
#line 1109 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 174:
#line 1110 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 175:
#line 1111 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 176:
#line 1112 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 177:
#line 1113 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 178:
#line 1114 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 179:
#line 1115 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 180:
#line 1116 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 181:
#line 1117 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 182:
#line 1119 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 183:
#line 1121 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 184:
#line 1122 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 185:
#line 1123 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 186:
#line 1124 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REQUIRED); }
    break;

  case 187:
#line 1125 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REVERSE); }
    break;

  case 188:
#line 1126 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 189:
#line 1127 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_QUERYCLEAR); }
    break;

  case 190:
#line 1128 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_ZEROFILL); }
    break;

  case 191:
#line 1129 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_RIGHT); }
    break;

  case 192:
#line 1130 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WORDWRAP); }
    break;

  case 193:
#line 1131 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 194:
#line 1135 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 195:
#line 1142 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_HIDDEN); }
    break;

  case 196:
#line 1143 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTOSCALE); }
    break;

  case 197:
#line 1144 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WANTNORETURNS); }
    break;

  case 198:
#line 1145 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WANTTABS); }
    break;

  case 199:
#line 1146 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_FONTPITCHFIXED); }
    break;

  case 200:
#line 1147 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_FONTPITCHVARIABLE); }
    break;

  case 201:
#line 1148 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLL); }
    break;

  case 202:
#line 1149 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 203:
#line 1150 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 204:
#line 1151 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 205:
#line 1152 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_BOTH); }
    break;

  case 206:
#line 1153 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 207:
#line 1154 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 208:
#line 1155 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_STRETCH_Y); }
    break;

  case 209:
#line 1156 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_STRETCH_BOTH); }
    break;

  case 210:
#line 1157 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 211:
#line 1158 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 212:
#line 1159 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 213:
#line 1161 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 214:
#line 1162 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 215:
#line 1163 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUECHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 216:
#line 1164 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEUNCHECKED,(yyvsp[(3) - (3)].str)); }
    break;

  case 217:
#line 1165 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_TEXT,(yyvsp[(3) - (3)].str)); }
    break;

  case 218:
#line 1166 "screen.yacc"
    { A4GL_add_str_attr(fld, FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 219:
#line 1172 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 220:
#line 1173 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 221:
#line 1174 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 223:
#line 1179 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 224:
#line 1183 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 225:
#line 1184 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 226:
#line 1185 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 227:
#line 1186 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 228:
#line 1187 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 229:
#line 1188 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 230:
#line 1189 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 231:
#line 1190 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 232:
#line 1192 "screen.yacc"
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
#line 1206 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 234:
#line 1207 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 235:
#line 1208 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 236:
#line 1209 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 237:
#line 1210 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 238:
#line 1211 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 239:
#line 1212 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 246:
#line 1225 "screen.yacc"
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
#line 1235 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 248:
#line 1241 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 255:
#line 1252 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 256:
#line 1252 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 259:
#line 1257 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 260:
#line 1260 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 261:
#line 1266 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 262:
#line 1269 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 265:
#line 1279 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),""); }
    break;

  case 266:
#line 1281 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); }
    break;

  case 267:
#line 1283 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); }
    break;

  case 268:
#line 1285 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); }
    break;

  case 269:
#line 1287 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 271:
#line 1291 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 272:
#line 1295 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 273:
#line 1298 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 274:
#line 1302 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:
#line 1302 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 278:
#line 1309 "screen.yacc"
    {colno++;}
    break;

  case 279:
#line 1310 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 280:
#line 1323 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 281:
#line 1331 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 282:
#line 1333 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 283:
#line 1340 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 284:
#line 1344 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 285:
#line 1348 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 286:
#line 1352 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 287:
#line 1356 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 288:
#line 1360 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 289:
#line 1364 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 290:
#line 1370 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 291:
#line 1374 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 292:
#line 1378 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 293:
#line 1382 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 294:
#line 1386 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 295:
#line 1390 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 296:
#line 1394 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 297:
#line 1397 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 299:
#line 1404 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 301:
#line 1408 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 304:
#line 1413 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 305:
#line 1417 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 306:
#line 1424 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 307:
#line 1425 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 309:
#line 1427 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 310:
#line 1433 "screen.yacc"
    { 
	if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
		sprintf((yyval.str),"NULL");
	} else {
		strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
	}
}
    break;

  case 311:
#line 1440 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 312:
#line 1441 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 313:
#line 1442 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 314:
#line 1443 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 316:
#line 1445 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 317:
#line 1446 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 318:
#line 1447 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 319:
#line 1451 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 320:
#line 1455 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 321:
#line 1460 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 322:
#line 1463 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 323:
#line 1464 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 324:
#line 1467 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 325:
#line 1469 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 326:
#line 1475 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 327:
#line 1477 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 328:
#line 1482 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 329:
#line 1490 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 330:
#line 1493 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 331:
#line 1494 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 332:
#line 1495 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 333:
#line 1496 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 334:
#line 1497 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 335:
#line 1498 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 336:
#line 1500 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 338:
#line 1507 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 339:
#line 1508 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 340:
#line 1511 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 341:
#line 1514 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 342:
#line 1518 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 343:
#line 1519 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 344:
#line 1520 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 345:
#line 1521 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 346:
#line 1522 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 347:
#line 1523 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 348:
#line 1525 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 349:
#line 1530 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 350:
#line 1532 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 351:
#line 1539 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 352:
#line 1539 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 353:
#line 1545 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 355:
#line 1552 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 356:
#line 1555 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 357:
#line 1561 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 358:
#line 1562 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 359:
#line 1563 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 360:
#line 1564 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 361:
#line 1565 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 362:
#line 1566 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 363:
#line 1567 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 364:
#line 1568 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 365:
#line 1569 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 366:
#line 1570 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 367:
#line 1571 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 368:
#line 1572 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 369:
#line 1573 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 370:
#line 1576 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 371:
#line 1583 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 372:
#line 1584 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 373:
#line 1585 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 375:
#line 1593 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 376:
#line 1597 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 380:
#line 1617 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 381:
#line 1627 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 382:
#line 1634 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 383:
#line 1643 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 384:
#line 1646 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 387:
#line 1665 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 388:
#line 1672 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 389:
#line 1680 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 390:
#line 1685 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 391:
#line 1693 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 392:
#line 1697 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 393:
#line 1702 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 394:
#line 1707 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 395:
#line 1712 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 396:
#line 1717 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 397:
#line 1722 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 398:
#line 1731 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 399:
#line 1740 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 400:
#line 1741 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 402:
#line 1750 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 403:
#line 1758 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 404:
#line 1764 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 405:
#line 1770 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 406:
#line 1776 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 407:
#line 1784 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 408:
#line 1789 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 409:
#line 1799 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 410:
#line 1809 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 411:
#line 1815 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 412:
#line 1821 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 413:
#line 1827 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 414:
#line 1837 "screen.yacc"
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

  case 415:
#line 1849 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 416:
#line 1857 "screen.yacc"
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
#line 1869 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 418:
#line 1877 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 419:
#line 1878 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 420:
#line 1879 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 421:
#line 1883 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 422:
#line 1884 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 423:
#line 1885 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 424:
#line 1886 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 425:
#line 1887 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 426:
#line 1888 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 427:
#line 1889 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 428:
#line 1892 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 429:
#line 1899 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 430:
#line 1910 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 431:
#line 1914 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 432:
#line 1921 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 433:
#line 1929 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 434:
#line 1935 "screen.yacc"
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

  case 435:
#line 1947 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 436:
#line 1948 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 437:
#line 1954 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 438:
#line 1960 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 439:
#line 1968 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 441:
#line 1976 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 442:
#line 1977 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 443:
#line 1991 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 444:
#line 1993 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 445:
#line 1994 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 446:
#line 1995 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 447:
#line 1996 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 448:
#line 1997 "screen.yacc"
    { 
			(yyval.expr)=create_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].el));
	}
    break;

  case 449:
#line 2000 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 450:
#line 2001 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 451:
#line 2002 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 452:
#line 2003 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 453:
#line 2004 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 454:
#line 2005 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 455:
#line 2006 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 456:
#line 2007 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 457:
#line 2008 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 458:
#line 2009 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 459:
#line 2010 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 460:
#line 2011 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 461:
#line 2012 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 462:
#line 2013 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 463:
#line 2014 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 464:
#line 2015 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 466:
#line 2021 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 467:
#line 2022 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 468:
#line 2023 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 469:
#line 2024 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 470:
#line 2025 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 471:
#line 2028 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 472:
#line 2032 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 5650 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 2044 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




