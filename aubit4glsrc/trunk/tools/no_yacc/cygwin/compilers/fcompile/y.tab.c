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
     KW_COMBOBOX = 463
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




/* Copy the first part of user declarations.  */
#line 1 "screen.yacc"

#define YYDEBUG 1
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

struct local_expr_list {
	listitem *expr_list;
	int nlist;
};


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
#line 78 "screen.yacc"
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
#line 616 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 629 "y.tab.c"

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
#define YYFINAL  138
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  209
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  162
/* YYNRULES -- Number of rules.  */
#define YYNRULES  719
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   463

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
     205,   206,   207,   208
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
     134,   138,   140,   143,   144,   146,   148,   151,   153,   155,
     157,   159,   161,   163,   167,   169,   172,   173,   177,   178,
     183,   184,   185,   186,   196,   197,   199,   200,   203,   208,
     209,   211,   213,   216,   218,   220,   222,   224,   226,   228,
     230,   232,   234,   236,   238,   240,   243,   244,   249,   251,
     252,   257,   258,   262,   264,   267,   271,   274,   275,   278,
     280,   284,   288,   294,   298,   302,   306,   308,   311,   312,
     314,   316,   318,   320,   322,   324,   326,   328,   329,   335,
     337,   340,   344,   345,   346,   353,   354,   358,   364,   368,
     370,   371,   377,   381,   384,   389,   392,   397,   401,   403,
     408,   411,   413,   417,   421,   423,   427,   429,   433,   435,
     440,   443,   445,   448,   449,   452,   454,   458,   460,   465,
     468,   473,   477,   481,   485,   491,   495,   501,   503,   505,
     509,   515,   519,   523,   527,   529,   534,   536,   538,   540,
     542,   546,   550,   552,   554,   556,   558,   560,   562,   564,
     567,   570,   572,   574,   576,   578,   582,   586,   588,   592,
     596,   600,   602,   604,   606,   608,   610,   616,   620,   624,
     628,   630,   632,   634,   636,   639,   641,   643,   645,   647,
     649,   651,   653,   655,   657,   659,   661,   663,   665,   667,
     669,   671,   672,   676,   678,   681,   683,   686,   689,   691,
     692,   702,   715,   717,   719,   720,   723,   724,   726,   727,
     729,   731,   736,   738,   742,   743,   745,   747,   751,   755,
     759,   763,   765,   769,   771,   773,   774,   776,   778,   781,
     783,   785,   787,   788,   793,   795,   797,   799,   801,   803,
     805,   808,   811,   814,   817,   819,   821,   823,   825,   827,
     829,   833,   835,   839,   841,   844,   847,   849,   851,   853,
     855,   857,   859,   861,   865,   869,   871,   873,   877,   881,
     885,   889,   891,   892,   896,   902,   903,   907,   908,   912,
     914,   917,   919,   921,   923,   925,   927,   929,   932,   934,
     935,   939,   941,   943,   945,   947,   949,   951,   953,   955,
     958,   959,   963,   964,   966,   969,   971,   975,   979,   983,
     987,   991,   995,  1000,  1004,  1007,  1010,  1012,  1018,  1024,
    1027,  1031,  1033,  1035,  1037,  1039,  1041,  1043,  1047,  1050,
    1052,  1055,  1063,  1065,  1069,  1073,  1075,  1077,  1079,  1085,
    1091,  1094,  1097,  1099,  1101,  1103,  1105,  1107,  1109,  1111,
    1117,  1118,  1121,  1123,  1128,  1131,  1135,  1138,  1142,  1146,
    1148,  1151,  1154,  1158,  1162,  1167,  1169,  1172,  1174,  1177,
    1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,  1197,
    1199,  1203,  1207,  1209,  1214,  1215,  1222,  1223,  1225,  1227,
    1231,  1233,  1235,  1239,  1243,  1244,  1246,  1248,  1252,  1255,
    1258,  1260,  1263,  1267,  1272,  1276,  1280,  1284,  1288,  1292,
    1296,  1300,  1304,  1308,  1313,  1317,  1320,  1323,  1329,  1335,
    1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,  1360,  1362,
    1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,
    1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,
    1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,
    1424,  1426,  1428,  1430,  1432,  1434,  1436,  1438,  1440,  1442,
    1444,  1446,  1448,  1450,  1452,  1454,  1456,  1458,  1460,  1462,
    1464,  1466,  1468,  1470,  1472,  1474,  1476,  1478,  1480,  1482,
    1484,  1486,  1488,  1490,  1492,  1494,  1496,  1498,  1500,  1502,
    1504,  1506,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,
    1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,  1540,  1542,
    1544,  1546,  1548,  1550,  1552,  1554,  1556,  1558,  1560,  1562,
    1564,  1566,  1568,  1570,  1572,  1574,  1576,  1578,  1580,  1582,
    1584,  1586,  1588,  1590,  1592,  1594,  1596,  1598,  1600,  1602,
    1604,  1606,  1608,  1610,  1612,  1614,  1616,  1618,  1620,  1622,
    1624,  1626,  1628,  1630,  1632,  1634,  1636,  1638,  1640,  1642,
    1644,  1646,  1648,  1650,  1652,  1654,  1656,  1658,  1660,  1662,
    1664,  1666,  1668,  1670,  1672,  1674,  1676,  1678,  1680,  1682,
    1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,  1700,  1702,
    1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,  1722,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1744,  1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1762,
    1764,  1766,  1768,  1770,  1772,  1774,  1776,  1778,  1780,  1782,
    1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,  1800,  1802,
    1804,  1806,  1808,  1810,  1812,  1814,  1816,  1818,  1820,  1822,
    1824,  1826,  1828,  1830,  1832,  1834,  1836,  1838,  1840,  1842,
    1844,  1846,  1848,  1850,  1852,  1854,  1856,  1858,  1860,  1862
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     210,     0,    -1,   211,   215,   258,   263,   288,    -1,    21,
      34,    -1,    21,   214,    40,    41,    42,    -1,    21,    34,
      40,    41,    42,    -1,    21,   214,    -1,    30,    -1,   369,
      -1,    30,    -1,   370,    -1,   172,    -1,   172,    38,   213,
      -1,   212,    -1,   212,    38,   213,    -1,   239,    -1,   238,
      -1,   176,   222,   231,   235,    27,    -1,   175,   222,   231,
     235,    27,    -1,   178,   222,   231,   235,    27,    -1,   180,
     222,   231,   220,    27,    -1,   221,    -1,   220,   221,    -1,
     174,   222,   231,   235,    27,    -1,    -1,   213,    -1,    -1,
      -1,    -1,   177,   224,   222,   231,    31,   225,   250,    32,
     226,    27,    -1,    -1,    -1,    -1,   179,   228,   222,   231,
      31,   229,   250,    32,   230,    27,    -1,    -1,    -1,    51,
     232,   234,    52,    -1,   181,    45,    46,    -1,   183,    -1,
     113,    45,    46,    -1,   173,    45,    30,    -1,   233,    -1,
     234,   233,    -1,    -1,   236,    -1,   237,    -1,   236,   237,
      -1,   216,    -1,   217,    -1,   218,    -1,   219,    -1,   223,
      -1,   227,    -1,   182,   237,   249,    -1,   240,    -1,   239,
     240,    -1,    -1,    24,   241,   243,    -1,    -1,    23,    46,
     242,   243,    -1,    -1,    -1,    -1,   248,   244,   247,    31,
     245,   250,    32,   246,   249,    -1,    -1,   171,    -1,    -1,
      25,    29,    -1,    25,    29,    22,    29,    -1,    -1,    27,
      -1,   252,    -1,   250,   252,    -1,   213,    -1,   251,    -1,
     254,    -1,   145,    -1,    17,    -1,    44,    -1,    46,    -1,
     253,    -1,   144,    -1,   120,    -1,   116,    -1,    16,    -1,
     253,    16,    -1,    -1,    26,   255,   256,    28,    -1,   306,
      -1,    -1,   256,    44,   257,   306,    -1,    -1,    43,   259,
     249,    -1,   260,    -1,   259,   260,    -1,   259,    58,   260,
      -1,   213,   261,    -1,    -1,    45,   262,    -1,   213,    -1,
     213,    37,   213,    -1,   213,    38,   213,    -1,   213,    38,
     213,    37,   213,    -1,   213,    39,   213,    -1,    46,    39,
     213,    -1,    20,   264,   249,    -1,   266,    -1,   264,   266,
      -1,    -1,   187,    -1,   184,    -1,   186,    -1,   188,    -1,
     185,    -1,   190,    -1,   207,    -1,   208,    -1,    -1,   265,
     305,   267,   268,    47,    -1,   269,    -1,   268,   269,    -1,
     268,    47,   269,    -1,    -1,    -1,    45,   270,   275,   272,
     271,   282,    -1,    -1,    26,    29,    28,    -1,    26,    29,
      58,    29,    28,    -1,   274,   126,    41,    -1,   274,    -1,
      -1,    60,    72,   213,    39,   213,    -1,    60,    72,   213,
      -1,    60,   308,    -1,    34,    39,   301,   273,    -1,   142,
     273,    -1,   142,   143,    42,   273,    -1,   213,    39,   213,
      -1,   213,    -1,    53,   213,    39,   213,    -1,    53,   213,
      -1,   277,    -1,   276,    58,   277,    -1,   278,    45,   279,
      -1,   305,    -1,   213,    39,   213,    -1,   213,    -1,   213,
      39,   213,    -1,   213,    -1,    53,   213,    39,   213,    -1,
      53,   213,    -1,    49,    -1,    58,    49,    -1,    -1,    58,
     283,    -1,   284,    -1,   283,    58,   284,    -1,    88,    -1,
      89,    45,   286,   326,    -1,    50,   280,    -1,    48,   276,
     281,   280,    -1,    90,    45,    46,    -1,    91,    45,   285,
      -1,    93,    72,   213,    -1,    93,    72,   213,    39,   213,
      -1,    92,    72,   213,    -1,    92,    72,   213,    39,   213,
      -1,    94,    -1,    95,    -1,    96,    45,    46,    -1,    97,
      45,    51,   309,    52,    -1,   118,    45,    46,    -1,   119,
      45,    46,    -1,   173,    45,   213,    -1,    98,    -1,    36,
      25,    45,    29,    -1,    36,    -1,   117,    -1,   100,    -1,
      99,    -1,   101,    45,    46,    -1,   102,    45,    46,    -1,
     103,    -1,    82,    -1,   105,    -1,   104,    -1,   170,    -1,
     169,    -1,   106,    -1,   106,   107,    -1,   106,   108,    -1,
     183,    -1,   196,    -1,   194,    -1,   195,    -1,   191,    45,
     192,    -1,   191,    45,   193,    -1,   189,    -1,   190,    45,
      46,    -1,   198,    45,    29,    -1,   197,    45,    29,    -1,
     199,    -1,   200,    -1,   201,    -1,   202,    -1,   203,    -1,
     204,    45,    51,   310,    52,    -1,   205,    45,    29,    -1,
     206,    45,    29,    -1,   181,    45,    46,    -1,    46,    -1,
      29,    -1,   115,    -1,   287,    -1,   286,   287,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    29,    -1,    82,    -1,    87,
      -1,    81,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    -1,    19,   289,   249,    -1,   290,    -1,   289,   290,
      -1,   291,    -1,   291,    47,    -1,    61,    46,    -1,   340,
      -1,    -1,    24,    57,   292,   296,    51,   297,    52,   293,
     295,    -1,   141,    51,    29,    58,    29,    52,   109,    51,
      29,    58,    29,    52,    -1,   333,    -1,   356,    -1,    -1,
     110,   139,    -1,    -1,    53,    -1,    -1,    47,    -1,   213,
      -1,   213,    26,    29,    28,    -1,   300,    -1,   297,   298,
     300,    -1,    -1,    58,    -1,   213,    -1,   213,    39,   213,
      -1,    34,    39,   213,    -1,   213,    39,    53,    -1,    34,
      39,    53,    -1,   299,    -1,   299,    59,   299,    -1,   213,
      -1,    27,    -1,    -1,   303,    -1,   304,    -1,   303,   304,
      -1,   144,    -1,   145,    -1,   213,    -1,    -1,   302,   213,
     307,   302,    -1,    62,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    67,    -1,    68,   314,    -1,    69,   314,
      -1,    70,   321,    -1,    71,   315,    -1,   111,    -1,   112,
      -1,   113,    -1,   114,    -1,   140,    -1,   313,    -1,   309,
      58,   313,    -1,   312,    -1,   310,    58,   312,    -1,    29,
      -1,    55,    29,    -1,    56,    29,    -1,    46,    -1,    30,
      -1,    16,    -1,   311,    -1,    41,    -1,    46,    -1,    30,
      -1,    30,   109,    30,    -1,    30,    37,    30,    -1,    16,
      -1,   311,    -1,   311,   109,   311,    -1,   311,    37,   311,
      -1,    46,   109,    46,    -1,    46,    37,    46,    -1,    41,
      -1,    -1,    51,    29,    52,    -1,    51,    29,    58,    29,
      52,    -1,    -1,   318,   109,   320,    -1,    -1,    51,    29,
      52,    -1,    29,    -1,   319,   316,    -1,   132,    -1,   133,
      -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,   138,
     325,    -1,   319,    -1,    -1,   322,   109,   323,    -1,   324,
      -1,   324,    -1,   132,    -1,   133,    -1,   134,    -1,   135,
      -1,   136,    -1,   137,    -1,   138,   325,    -1,    -1,    51,
     317,    52,    -1,    -1,   327,    -1,   125,   328,    -1,   329,
      -1,   329,   123,   329,    -1,   329,   122,   329,    -1,   330,
     121,   330,    -1,   330,     8,   330,    -1,   330,     9,   330,
      -1,   330,    72,   330,    -1,   330,   126,    72,   330,    -1,
     330,    45,   330,    -1,   330,   130,    -1,   330,   131,    -1,
     330,    -1,   330,   127,   330,   123,   330,    -1,   330,   128,
      51,   332,    52,    -1,   126,   329,    -1,    51,   329,    52,
      -1,   331,    -1,    29,    -1,    46,    -1,   129,    -1,    30,
      -1,   330,    -1,   332,    58,   330,    -1,    18,   334,    -1,
     335,    -1,   334,   335,    -1,     8,   336,     9,   294,     8,
     336,     9,    -1,   337,    -1,   336,    58,   337,    -1,   338,
      39,   339,    -1,   339,    -1,   213,    -1,   212,    -1,   147,
     350,   152,   354,   348,    -1,   148,   351,   152,   354,   348,
      -1,   157,   357,    -1,   156,   357,    -1,   344,    -1,   349,
      -1,   342,    -1,   345,    -1,   346,    -1,   357,    -1,   347,
      -1,   164,   362,   165,   341,   343,    -1,    -1,   166,   341,
      -1,   160,    -1,   161,   305,    45,   362,    -1,   163,   305,
      -1,   163,    45,   305,    -1,   163,   162,    -1,   163,    45,
     162,    -1,   167,   348,    27,    -1,   341,    -1,   348,   341,
      -1,    90,    46,    -1,    90,   159,    46,    -1,    90,    82,
      46,    -1,    90,   159,    82,    46,    -1,   352,    -1,   350,
     352,    -1,   353,    -1,   351,   353,    -1,   149,    -1,   150,
      -1,   151,    -1,   149,    -1,   153,    -1,   154,    -1,   155,
      -1,   151,    -1,    93,    -1,   150,    -1,   355,    -1,   354,
     298,   355,    -1,   338,    39,   339,    -1,   339,    -1,   338,
     146,   338,   295,    -1,    -1,   158,   213,    51,   358,   359,
      52,    -1,    -1,   360,    -1,   361,    -1,   360,    58,   361,
      -1,   362,    -1,   365,    -1,   362,   123,   362,    -1,   362,
     122,   362,    -1,    -1,   364,    -1,   362,    -1,   364,    58,
     362,    -1,    56,   362,    -1,    55,   362,    -1,   367,    -1,
     126,   362,    -1,    51,   362,    52,    -1,   366,    51,   363,
      52,    -1,   168,   152,   305,    -1,   362,   121,   362,    -1,
     362,     8,   362,    -1,   362,     9,   362,    -1,   362,    53,
     362,    -1,   362,    55,   362,    -1,   362,    56,   362,    -1,
     362,    54,   362,    -1,   362,    72,   362,    -1,   362,   126,
      72,   362,    -1,   362,    45,   362,    -1,   362,   130,    -1,
     362,   131,    -1,   362,   127,   362,   123,   362,    -1,   362,
     128,    51,   368,    52,    -1,   362,   126,   128,    51,   368,
      52,    -1,   213,    -1,   305,    -1,    29,    -1,    46,    -1,
     129,    -1,    41,    -1,   367,    -1,   368,    58,   367,    -1,
      18,    -1,    20,    -1,    21,    -1,    22,    -1,    25,    -1,
      19,    -1,    27,    -1,    33,    -1,    35,    -1,    36,    -1,
      41,    -1,    42,    -1,    43,    -1,    48,    -1,    49,    -1,
      57,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,    90,    -1,    91,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,
      98,    -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,
     103,    -1,   104,    -1,   105,    -1,   106,    -1,   107,    -1,
     108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,
     118,    -1,   119,    -1,   121,    -1,     8,    -1,     9,    -1,
     122,    -1,   123,    -1,   125,    -1,   126,    -1,   127,    -1,
     128,    -1,   129,    -1,   130,    -1,   131,    -1,   132,    -1,
     133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,    -1,
     138,    -1,   139,    -1,   140,    -1,   141,    -1,   142,    -1,
     143,    -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,
     150,    -1,   151,    -1,   152,    -1,   153,    -1,   154,    -1,
     155,    -1,   156,    -1,   157,    -1,   158,    -1,   159,    -1,
     160,    -1,   161,    -1,   162,    -1,   163,    -1,   164,    -1,
     165,    -1,   166,    -1,   167,    -1,   168,    -1,   169,    -1,
     170,    -1,   171,    -1,   173,    -1,    18,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    40,    -1,    42,    -1,
      43,    -1,    48,    -1,    49,    -1,    57,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,    98,    -1,    99,    -1,
     100,    -1,   101,    -1,   102,    -1,   103,    -1,   104,    -1,
     105,    -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,
     110,    -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,
     115,    -1,   117,    -1,   118,    -1,   119,    -1,   121,    -1,
       8,    -1,     9,    -1,   122,    -1,   123,    -1,   125,    -1,
     126,    -1,   127,    -1,   128,    -1,   130,    -1,   131,    -1,
     132,    -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,
     137,    -1,   138,    -1,   139,    -1,   140,    -1,   141,    -1,
     143,    -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,
     150,    -1,   151,    -1,   152,    -1,   153,    -1,   154,    -1,
     155,    -1,   156,    -1,   157,    -1,   158,    -1,   159,    -1,
     160,    -1,   161,    -1,   163,    -1,   164,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,   169,    -1,   170,    -1,
     171,    -1,   173,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   152,   153,   158,   159,   168,   169,   173,
     174,   178,   179,   180,   181,   186,   189,   196,   206,   215,
     228,   236,   246,   254,   267,   268,   273,   276,   279,   272,
     295,   298,   301,   294,   315,   318,   318,   324,   327,   330,
     333,   339,   340,   344,   353,   359,   369,   376,   378,   380,
     382,   384,   386,   391,   401,   401,   404,   404,   417,   417,
     436,   438,   441,   436,   446,   446,   451,   452,   453,   465,
     466,   471,   472,   475,   490,   502,   503,   514,   525,   538,
     550,   561,   566,   569,   577,   578,   584,   583,   605,   608,
     608,   626,   627,   630,   631,   632,   635,   644,   645,   648,
     649,   650,   652,   653,   654,   660,   664,   664,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   682,   681,   700,
     701,   702,   706,   710,   706,   891,   892,   896,   904,   905,
     908,   909,   912,   915,   920,   929,   941,   953,   960,   968,
     975,   988,   997,  1006,  1013,  1015,  1018,  1024,  1025,  1026,
    1027,  1030,  1031,  1035,  1036,  1040,  1040,  1043,  1044,  1064,
    1086,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1110,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1126,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1157,  1158,  1159,  1163,  1164,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1177,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1201,  1202,  1205,  1205,  1207,  1207,  1210,  1220,  1226,
    1226,  1229,  1230,  1231,  1235,  1235,  1237,  1237,  1240,  1240,
    1242,  1245,  1251,  1254,  1258,  1259,  1263,  1265,  1267,  1269,
    1271,  1276,  1276,  1280,  1283,  1287,  1287,  1290,  1290,  1294,
    1295,  1308,  1316,  1316,  1325,  1329,  1333,  1337,  1341,  1345,
    1349,  1355,  1359,  1363,  1367,  1371,  1375,  1379,  1382,  1389,
    1389,  1393,  1393,  1398,  1398,  1398,  1402,  1409,  1410,  1411,
    1412,  1418,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1436,  1440,  1445,  1448,  1449,  1452,  1453,  1460,  1462,  1467,
    1475,  1478,  1479,  1480,  1481,  1482,  1483,  1484,  1490,  1492,
    1493,  1496,  1499,  1503,  1504,  1505,  1506,  1507,  1508,  1509,
    1515,  1517,  1524,  1524,  1530,  1536,  1537,  1540,  1546,  1547,
    1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,
    1558,  1561,  1568,  1569,  1570,  1575,  1578,  1582,  1594,  1597,
    1598,  1602,  1612,  1619,  1628,  1631,  1643,  1646,  1650,  1657,
    1665,  1670,  1678,  1682,  1687,  1692,  1697,  1702,  1707,  1716,
    1725,  1726,  1731,  1734,  1742,  1748,  1754,  1760,  1769,  1774,
    1784,  1794,  1800,  1806,  1812,  1822,  1834,  1842,  1854,  1862,
    1863,  1864,  1868,  1869,  1870,  1871,  1872,  1873,  1874,  1877,
    1884,  1895,  1899,  1906,  1914,  1914,  1930,  1931,  1937,  1943,
    1951,  1958,  1959,  1960,  1965,  1966,  1969,  1970,  1974,  1976,
    1977,  1978,  1979,  1980,  1981,  1982,  1983,  1984,  1985,  1986,
    1987,  1988,  1989,  1990,  1991,  1992,  1993,  1994,  1995,  1996,
    1999,  2002,  2003,  2004,  2005,  2006,  2009,  2013,  2024,  2026,
    2027,  2028,  2029,  2030,  2032,  2033,  2034,  2035,  2036,  2037,
    2038,  2039,  2040,  2041,  2042,  2043,  2044,  2045,  2046,  2047,
    2048,  2049,  2050,  2051,  2052,  2053,  2054,  2055,  2056,  2057,
    2058,  2059,  2060,  2061,  2062,  2063,  2064,  2065,  2066,  2067,
    2068,  2069,  2070,  2071,  2072,  2073,  2074,  2075,  2076,  2077,
    2078,  2079,  2080,  2081,  2082,  2083,  2084,  2085,  2086,  2087,
    2088,  2089,  2090,  2091,  2092,  2093,  2094,  2095,  2096,  2097,
    2098,  2099,  2100,  2101,  2102,  2103,  2104,  2105,  2106,  2107,
    2108,  2109,  2110,  2111,  2112,  2113,  2114,  2115,  2116,  2117,
    2118,  2119,  2120,  2121,  2122,  2123,  2124,  2125,  2126,  2127,
    2128,  2129,  2130,  2131,  2132,  2133,  2134,  2135,  2136,  2137,
    2138,  2139,  2140,  2141,  2142,  2143,  2144,  2145,  2146,  2147,
    2148,  2149,  2150,  2151,  2152,  2153,  2182,  2183,  2184,  2185,
    2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,
    2196,  2197,  2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,
    2206,  2207,  2208,  2209,  2210,  2211,  2212,  2213,  2214,  2215,
    2216,  2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,
    2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,  2235,
    2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,  2244,  2245,
    2246,  2247,  2248,  2249,  2250,  2251,  2252,  2253,  2254,  2255,
    2256,  2257,  2258,  2259,  2260,  2261,  2262,  2263,  2264,  2265,
    2266,  2267,  2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,
    2276,  2277,  2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,
    2286,  2287,  2288,  2289,  2290,  2291,  2292,  2293,  2294,  2295,
    2296,  2297,  2298,  2299,  2300,  2301,  2302,  2303,  2304,  2305
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
  "KW_COMBOBOX", "$accept", "form_def", "database_section",
  "named_or_kw_st", "named_or_kw_any", "dbname",
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
  "func_call_arg", "expression", "op_expression_list", "expression_list",
  "single_expression", "fcall_name", "evalue", "evalue_list", "st_kword",
  "any_kword", 0
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
     455,   456,   457,   458,   459,   460,   461,   462,   463
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   209,   210,   211,   211,   211,   211,   212,   212,   213,
     213,   214,   214,   214,   214,   215,   215,   216,   217,   218,
     219,   220,   220,   221,   222,   222,   224,   225,   226,   223,
     228,   229,   230,   227,   231,   232,   231,   233,   233,   233,
     233,   234,   234,   235,   235,   236,   236,   237,   237,   237,
     237,   237,   237,   238,   239,   239,   241,   240,   242,   240,
     244,   245,   246,   243,   247,   247,   248,   248,   248,   249,
     249,   250,   250,   251,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   253,   253,   255,   254,   256,   257,
     256,   258,   258,   259,   259,   259,   260,   261,   261,   262,
     262,   262,   262,   262,   262,   263,   264,   264,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   267,   266,   268,
     268,   268,   270,   271,   269,   272,   272,   272,   273,   273,
     274,   274,   274,   274,   275,   275,   275,   275,   275,   275,
     275,   276,   276,   277,   278,   279,   279,   280,   280,   280,
     280,   281,   281,   282,   282,   283,   283,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     285,   285,   285,   286,   286,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   288,   288,   289,   289,   290,   290,   291,   291,   292,
     291,   291,   291,   291,   293,   293,   294,   294,   295,   295,
     296,   296,   297,   297,   298,   298,   299,   299,   299,   299,
     299,   300,   300,   301,   301,   302,   302,   303,   303,   304,
     304,   305,   307,   306,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   309,
     309,   310,   310,   311,   311,   311,   312,   312,   312,   312,
     312,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   314,   314,   314,   315,   315,   316,   316,   317,
     318,   319,   319,   319,   319,   319,   319,   319,   320,   321,
     321,   322,   323,   324,   324,   324,   324,   324,   324,   324,
     325,   325,   326,   326,   327,   328,   328,   328,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   330,   330,   330,   330,   331,   332,   332,   333,   334,
     334,   335,   336,   336,   337,   337,   338,   339,   340,   340,
     340,   340,   341,   341,   341,   341,   341,   341,   341,   342,
     343,   343,   344,   345,   346,   346,   346,   346,   347,   348,
     348,   349,   349,   349,   349,   350,   350,   351,   351,   352,
     352,   352,   353,   353,   353,   353,   353,   353,   353,   354,
     354,   355,   355,   356,   358,   357,   359,   359,   360,   360,
     361,   362,   362,   362,   363,   363,   364,   364,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     366,   367,   367,   367,   367,   367,   368,   368,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     5,     5,     5,
       5,     1,     2,     5,     0,     1,     0,     0,     0,    10,
       0,     0,     0,    10,     0,     0,     4,     3,     1,     3,
       3,     1,     2,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     0,     3,     0,     4,
       0,     0,     0,     9,     0,     1,     0,     2,     4,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     4,     1,     0,
       4,     0,     3,     1,     2,     3,     2,     0,     2,     1,
       3,     3,     5,     3,     3,     3,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     1,
       2,     3,     0,     0,     6,     0,     3,     5,     3,     1,
       0,     5,     3,     2,     4,     2,     4,     3,     1,     4,
       2,     1,     3,     3,     1,     3,     1,     3,     1,     4,
       2,     1,     2,     0,     2,     1,     3,     1,     4,     2,
       4,     3,     3,     3,     5,     3,     5,     1,     1,     3,
       5,     3,     3,     3,     1,     4,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     5,     3,     3,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     1,     2,     1,     2,     2,     1,     0,
       9,    12,     1,     1,     0,     2,     0,     1,     0,     1,
       1,     4,     1,     3,     0,     1,     1,     3,     3,     3,
       3,     1,     3,     1,     1,     0,     1,     1,     2,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     3,     3,     3,
       3,     1,     0,     3,     5,     0,     3,     0,     3,     1,
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
       1,     1,     3,     3,     0,     1,     1,     3,     2,     2,
       1,     2,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     2,     2,     5,     5,     6,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,   546,   547,   468,   473,   469,   470,
     471,   472,   474,     7,   475,     3,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,    11,   595,    13,     6,     8,     1,     0,
      56,     0,    91,    16,    15,    54,     0,     0,     0,     0,
      58,    66,    24,    24,    26,    24,    30,    24,    47,    48,
      49,    50,    51,    52,    69,     0,     0,    55,     0,   673,
     674,   596,   597,   598,   599,   600,   601,     9,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,    12,    10,    14,     0,    66,     0,
      57,    60,    25,    34,    34,    24,    34,    24,    34,    70,
      53,    97,    69,    93,   108,   231,     5,     4,    59,    67,
      64,    35,    43,    43,    34,    43,    34,     0,     0,    96,
       0,    92,    94,   110,   113,   111,   109,   112,   114,   115,
     116,   108,     0,   106,     0,     2,     0,    65,     0,     0,
       0,    44,    45,     0,     0,     0,     0,    24,     0,    21,
       0,    99,    98,    95,   105,   107,   271,   117,   596,   600,
     614,   692,   695,   696,   704,   705,   376,    69,   233,   235,
     242,     0,   238,   243,    68,    61,     0,     0,     0,    38,
      41,     0,    18,    46,    17,    27,    19,    31,    34,    20,
      22,     0,     0,     0,     0,     0,     0,   368,   369,   239,
     237,     0,   409,   410,   411,     0,   405,   417,   412,   418,
     416,   413,   414,   415,     0,   407,     0,   381,   380,   232,
     234,   236,     0,     0,     0,     0,     0,    36,    42,     0,
       0,    43,   104,   100,   101,   103,   122,     0,   119,   546,
     547,   468,   470,   471,   472,     7,   475,   476,   477,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   542,   543,   544,   545,   548,   549,   550,   551,   552,
     553,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     377,     0,   372,     0,   375,   370,     0,     0,     0,   406,
       0,   408,     0,   248,    84,    77,    86,    78,    79,    83,
      82,    81,    76,    73,     0,    74,    71,    80,    75,    39,
      40,    37,     0,     0,     0,     0,     0,   118,   120,   246,
       0,     0,   250,     0,     0,     0,   422,   254,   419,   254,
     424,   249,   423,   265,    62,    72,    85,    28,    32,    23,
     102,   603,     0,   130,   138,   125,   121,   247,     0,   373,
     374,     0,     0,     0,     0,   255,     0,   392,     0,     0,
       0,     0,     0,   399,   384,   382,   385,   386,   388,   378,
     383,   387,   379,   426,   269,   270,     0,     0,   266,   267,
      88,    69,     0,     0,     0,   140,     0,     0,   135,   129,
       0,     0,   123,     0,     0,   603,   256,   254,   261,   252,
       0,   421,   401,     0,     0,     0,     0,   396,   394,   462,
     465,   463,     0,     0,     0,   678,   464,   715,   271,   461,
       0,   431,     0,   440,     0,   420,   400,     0,   427,   428,
     430,    87,    89,   272,   268,    63,    29,    33,   264,   263,
     130,     0,   274,   275,   276,   277,   278,   279,   312,   312,
     329,   315,     0,   284,   285,   286,   287,   288,   133,   130,
       0,   137,     0,   153,     0,   251,     0,     0,   244,     0,
       0,     0,   403,   402,     0,     0,   397,   395,     0,   439,
     438,   441,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   455,   456,     0,
     434,   398,   425,     0,   265,   265,   134,   139,     0,   280,
     281,   333,   334,   335,   336,   337,   338,   340,   282,     0,
     331,   321,   322,   323,   324,   325,   326,   340,   283,     0,
     317,   132,   136,   128,   126,     0,     0,   124,   371,   260,
     258,   259,   257,     0,   248,   253,   262,     0,   404,   393,
     442,   444,   446,   447,   454,   448,   451,   449,   450,   452,
     445,   433,   432,     0,     0,     0,     0,   390,   436,     0,
     435,   429,    90,   273,     0,     0,   339,     0,   327,     0,
       0,   320,     0,     0,   176,     0,     0,   183,   157,     0,
       0,     0,     0,     0,   167,   168,     0,     0,   174,   179,
     178,     0,     0,   182,   185,   184,   188,   177,     0,     0,
     187,   186,     0,     0,   191,   197,     0,     0,   193,   194,
     192,     0,     0,   201,   202,   203,   204,   205,     0,     0,
       0,   154,   155,   245,   240,     0,   453,     0,     0,   466,
       0,     0,   389,   443,     0,   313,     0,   319,     0,   330,
     332,   328,   316,     0,   131,   127,     0,     0,   141,     0,
     144,     0,   148,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   457,
     458,     0,   391,   437,     0,   341,   318,     0,   151,     0,
       0,     0,   150,     0,   223,   215,   216,   217,   218,   219,
     220,   221,   222,   226,   224,   227,   228,   229,   230,   225,
     342,   213,   161,   211,   210,   212,   162,   165,   163,   169,
       0,   180,   181,   171,   172,   173,   209,   198,   195,   196,
     200,   199,     0,   207,   208,   156,     0,   459,   467,   314,
     175,   152,   142,   160,   146,   143,     0,   147,     0,   214,
     158,   343,     0,     0,   305,   293,   302,   311,   301,     0,
       0,     0,   306,   289,   298,   297,   300,   296,     0,   299,
     291,   241,     0,   149,   362,   365,   363,     0,     0,   364,
     344,   345,   356,   361,   166,   164,     0,     0,     0,     0,
     294,   295,   170,     0,     0,     0,   206,     0,   145,     0,
     359,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   355,   304,   303,   310,   309,   290,   308,   307,
     292,   360,   347,   346,   349,   350,   353,   351,   348,     0,
       0,     0,   352,     0,   366,     0,   357,   358,     0,   367
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   570,   708,   136,   142,   158,   159,   160,
     161,   358,   359,   303,   162,   305,   439,   672,   163,   307,
     440,   673,   322,   349,   390,   391,   350,   351,   352,   143,
     144,   145,   151,   298,   300,   320,   433,   671,   348,   301,
     310,   594,   595,   596,   597,   598,   623,   666,   794,   166,
     312,   313,   329,   362,   315,   341,   342,   343,   405,   447,
     448,   606,   753,   682,   678,   679,   635,   947,   948,   949,
    1045,   953,   990,   827,   921,   922,  1016,  1010,  1011,   345,
     377,   378,   379,   576,   834,   638,   622,   613,   687,   652,
     688,   689,   730,   667,   668,   669,   709,   670,   795,   748,
    1061,  1068,  1062,  1070,  1063,   799,   818,   871,   938,   819,
     820,   942,   808,   809,   939,   810,   866,  1050,  1051,  1080,
    1081,  1082,  1083,  1135,   380,   407,   408,   571,   572,   573,
     574,   382,   653,   654,   932,   655,   656,   657,   658,   659,
     660,   415,   424,   416,   425,   617,   618,   383,   661,   663,
     717,   718,   719,   720,   859,   860,   711,   712,   713,   930,
     137,   295
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -871
static const yytype_int16 yypact[] =
{
      27,  1882,    51,     0,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,    54,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,    34,  -871,   114,    86,  -871,  -871,    43,
    -871,   148,   113,  -871,    62,  -871,   123,  4040,  4040,   139,
    -871,   166,  4040,  4040,  -871,  4040,  -871,  4040,  -871,  -871,
    -871,  -871,  -871,  -871,   169,  4040,   184,  -871,   164,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,   171,   166,   186,
    -871,  -871,  -871,   167,   167,  4040,   167,  4040,   167,  -871,
    -871,   199,  2380,  -871,   161,   210,  -871,  -871,  -871,   236,
      89,  -871,   148,   148,   167,   148,   167,    91,  2878,  -871,
    4040,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,    15,  4040,  -871,  4206,  -871,   238,  -871,   239,   -93,
     251,   148,  -871,   254,   253,   260,   263,  4040,   -11,  -871,
     294,   201,  -871,  -871,  -871,  -871,  -871,  -871,   336,   293,
     314,   310,    97,   229,   205,   205,  -871,  3044,  -871,   317,
    -871,   230,  -871,  -871,  -871,  -871,   332,   340,   345,  -871,
    -871,   -30,  -871,  -871,  -871,  -871,  -871,  -871,   167,  -871,
    -871,  4040,  4040,  4040,  4040,   349,  1550,   336,  -871,  -871,
    -871,   352,  -871,  -871,  -871,   162,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,   152,  -871,  4040,  -871,  -871,  -871,
    -871,  -871,  4040,  1384,   366,   389,   374,  -871,  -871,  1384,
    1384,   148,  -871,  -871,   384,  -871,  -871,    78,  -871,   383,
     387,   388,   391,   396,   398,   399,   401,   403,   404,   406,
     407,   409,   410,   415,   418,   421,   422,   429,   434,   437,
     438,   441,   442,   443,   444,   445,   447,   453,   455,   457,
     458,   460,   461,   464,   465,   467,   468,   469,   470,   472,
     475,   477,   479,   480,   482,   484,   485,   486,   487,   489,
     490,   491,   492,   493,   495,   506,   507,   508,   509,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   543,
     544,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   572,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   587,   588,   589,   590,
     591,   594,   595,   597,   599,   600,   601,   602,   603,   605,
    -871,    21,  -871,   609,  -871,  -871,  4040,   365,  1550,  -871,
    1550,  -871,   377,   397,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,   886,  -871,  -871,   446,  -871,  -871,
    -871,  -871,  1052,  1218,   619,  4040,  2546,   349,  -871,   381,
    1550,  2048,   621,   604,   625,   611,  -871,   108,  -871,   108,
    -871,  -871,  -871,    88,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,   641,  4040,   -29,   657,   671,  -871,  -871,   690,  -871,
    -871,   670,  4372,   648,  2048,  -871,   -17,  -871,  4040,  2712,
    1716,   -43,  1550,  -871,  -871,  -871,  -871,  -871,  -871,   -43,
    -871,  -871,   -43,  1716,  -871,  -871,    49,  4040,    88,  -871,
    -871,   169,   674,   675,  3210,   664,   607,   662,  -871,   586,
    4040,   676,  -871,  1550,   678,   668,   669,   116,   651,  -871,
     606,  -871,  -871,   665,    -9,   672,  3376,  -871,  -871,  -871,
    -871,  -871,  1716,  1716,  1716,  1716,  -871,   570,   663,  -871,
     208,  -871,   673,  -871,    26,  -871,  -871,   661,   658,  -871,
     287,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
     666,  4040,  -871,  -871,  -871,  -871,  -871,  -871,   679,   679,
     269,   405,  4040,  -871,  -871,  -871,  -871,  -871,  -871,   666,
     682,  -871,    16,   677,    24,  -871,  3542,  3708,   617,  4372,
    4372,   680,  -871,  -871,   686,  1716,  -871,  -871,   265,   287,
     287,   287,  4040,  1716,  1716,  1716,  1716,  1716,  1716,  1716,
    1716,  1716,  1716,  1716,   -47,  1716,   683,  -871,  -871,   -43,
    1716,  -871,  -871,  1716,    88,    88,  -871,  -871,   704,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,   685,  -871,   628,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,   685,  -871,   629,
     688,   701,  -871,  -871,  -871,   712,   462,  -871,  -871,  -871,
    -871,  -871,  -871,   610,   397,  -871,  -871,   713,  -871,   287,
    -871,  -871,   244,   244,   287,   287,   287,   287,   287,   287,
     287,   287,   287,  1716,   692,   344,  2214,   592,   287,   693,
     694,  -871,  -871,  -871,   127,   715,  -871,   269,  -871,   405,
     717,  -871,  4040,   720,   725,  4040,  3874,  -871,  -871,   706,
     708,   709,   684,   687,  -871,  -871,   710,   716,  -871,  -871,
    -871,   718,   719,  -871,  -871,  -871,   144,  -871,   721,   722,
    -871,  -871,   723,   724,  -871,  -871,   726,   727,  -871,  -871,
    -871,   728,   729,  -871,  -871,  -871,  -871,  -871,   730,   731,
     732,   699,  -871,  -871,  -871,   702,   287,  2214,  1716,  -871,
     136,   -43,  -871,  -871,  1716,  -871,   733,  -871,   734,  -871,
    -871,  -871,  -871,   735,  -871,  -871,   736,    11,  -871,   737,
    -871,  4040,   739,  -871,   608,   738,    -3,  4040,  4040,   742,
     714,   743,   744,  -871,  -871,   745,   746,  4040,   747,   748,
      84,   741,   750,   749,   754,   756,   462,   766,   156,   287,
    -871,  2214,  -871,   287,   751,  -871,  -871,   767,  -871,  4538,
    3874,  4040,   758,  4040,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
      23,  -871,  -871,  -871,  -871,  -871,  -871,   759,   760,  -871,
     395,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,   423,  -871,  -871,  -871,   753,  -871,  -871,  -871,
    -871,   757,  -871,  -871,   762,  -871,  4040,  -871,    41,  -871,
    -871,  -871,  4040,  4040,  -871,  -871,     2,  -871,     4,   777,
     778,   168,    13,  -871,  -871,  -871,  -871,  -871,   176,  -871,
    -871,  -871,  4040,  -871,  -871,  -871,  -871,    41,    41,  -871,
    -871,   232,    19,  -871,  -871,  -871,   779,   782,   768,   769,
    -871,  -871,  -871,   395,    20,    20,  -871,   423,  -871,   761,
    -871,    41,    41,    32,    32,    32,    32,    32,   752,    32,
     765,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,  -871,    32,
     695,    32,  -871,    32,  -871,   179,  -871,  -871,    32,  -871
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -871,  -871,  -871,   807,  -147,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,   459,  -136,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -871,  -149,  -871,   428,  -871,  -287,  -871,  -132,  -871,
    -871,   681,  -871,  -871,   523,  -871,  -871,  -871,  -871,  -871,
    -309,   -82,  -871,  -548,  -871,  -871,  -871,  -871,  -871,  -871,
    -871,  -267,  -871,  -871,  -871,  -871,  -871,   481,  -871,  -871,
    -435,  -871,  -871,  -871,  -557,  -871,  -871,  -871,  -166,  -871,
    -871,  -164,  -871,  -871,  -871,  -148,  -871,  -871,  -183,  -871,
    -871,   452,  -871,  -871,  -871,  -871,    -4,  -871,  -871,   145,
      71,    74,  -871,    40,  -871,   170,  -340,    42,  -871,  -871,
    -871,  -871,  -870,  -260,  -254,   101,  -871,  -871,  -871,  -871,
     -28,  -871,  -871,  -871,  -871,   -22,    30,  -871,  -871,  -871,
    -866,  -616,  -871,  -871,  -871,  -871,   448,   165,   240,  -337,
    -402,  -871,  -648,  -871,  -871,  -871,  -871,  -871,  -871,  -584,
    -871,  -871,  -871,   436,   425,   272,   202,  -871,   -84,  -871,
    -871,  -871,    60,  -646,  -871,  -871,  -871,  -871,  -843,   -71,
    -871,  -871
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -720
static const yytype_int16 yytable[] =
{
     294,   296,   367,   331,   710,   302,   302,   381,   302,   164,
     302,   716,   608,   929,   716,   -69,   399,   304,   311,   306,
     386,   308,   437,   139,   140,   853,  1013,  1103,  1104,   692,
     609,   676,   364,   828,   -69,   662,   353,   763,   355,  1086,
     381,  1088,   309,  1014,   824,   332,   625,   646,     1,  1055,
    1094,   138,   994,   791,   625,   625,   768,   769,   770,   771,
     988,  1074,  1075,   363,  1105,   693,   716,   714,   429,   989,
    1074,  1075,   147,   764,   825,  1059,  1060,   721,  1076,   610,
     387,   854,   610,   386,   929,   139,   140,  1076,   388,   150,
     389,  1106,  1077,   722,   146,   583,   995,   996,   997,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1087,  1015,  1089,   677,   426,   646,   647,   648,   839,
     649,   650,  1095,   446,   651,   607,   149,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   852,  1038,   855,
    1107,   857,   694,   387,   858,  1108,  1109,  1110,  1048,  1111,
    1112,   388,   148,   389,   604,   323,   165,   325,   302,   327,
     302,  1079,  1069,   357,   168,   311,   645,  1078,   758,   324,
    1079,   326,   636,   796,   645,   354,   616,   356,   616,   935,
     297,   361,   141,   311,   426,   936,   647,   648,   980,   649,
     650,   299,   822,   651,   981,   366,   309,   376,   646,   333,
     334,   335,   336,   337,   314,   338,   316,   926,  1037,   640,
     302,  1099,  1100,   317,   981,   319,   773,   774,   321,   393,
    1092,   398,   339,   340,  1118,  1119,  1093,  1069,  1096,   344,
     376,  1137,   664,   665,  1097,  1122,  1123,  1138,   402,   403,
     404,   615,   691,   615,   328,   417,   412,   413,   414,   441,
     616,   963,   964,   775,   442,   443,   444,   445,   346,   376,
     347,   776,   777,   778,   779,   357,   426,   384,   647,   648,
     385,   649,   650,   773,   774,   651,  1028,  1029,   392,   582,
     780,   394,   979,   982,   395,   376,   593,   396,   983,   775,
     427,   428,   593,   593,   397,   773,   774,   776,   777,   778,
     779,   418,   419,   420,   580,   421,   422,   423,   695,   698,
     775,   412,   413,   414,   578,   615,   780,   840,   776,   777,
     778,   779,   417,   152,   153,   154,   155,   156,   157,   781,
     782,   783,   775,   401,   784,   785,   786,   780,   787,   788,
     776,   777,   778,   779,   406,   333,   334,   335,   336,   337,
     409,   338,   773,   774,  1101,  1102,   767,   602,   603,   780,
     410,   411,   725,   426,   431,   781,   782,   783,   339,   340,
     784,   785,   786,   789,   787,   788,   432,   434,   418,   419,
     420,   577,   421,   422,   423,   435,   781,   782,   783,   775,
     436,   784,   785,   786,   446,   787,   788,   776,   777,   778,
     779,   801,   802,   803,   804,   805,   806,   807,   781,   782,
     783,  1054,   599,   784,   785,   786,   780,   787,   788,   600,
     601,   605,  -673,   614,  1055,  1056,  -674,  -596,   620,   612,
    -597,   376,   841,   376,   637,  -598,  1057,  -601,    -9,  1064,
    -602,  1058,  -604,  -605,   621,  -607,  -608,   593,  -609,  -610,
    1059,  1060,  1055,  1065,  -611,   593,   593,  -612,   630,   634,
    -613,  -614,   626,   376,  1066,   781,   782,   928,  -615,  1067,
     784,   785,   786,  -616,   787,   788,  -617,  -618,  1059,  1060,
    -619,  -620,  -621,  -622,  -623,   675,  -624,  1124,  1125,  1126,
    1127,  1128,  -625,  1130,  -626,   686,  -627,  -628,   874,  -629,
    -630,   366,   366,  -631,  -632,   376,  -633,  -634,  -635,  -636,
     875,  -637,   876,  1132,  -638,  1134,  -639,  1136,  -640,  -641,
     723,  -642,  1139,  -643,  -644,  -645,  -646,   729,  -647,  -648,
    -649,  -650,  -651,   751,  -652,   950,   376,   811,   812,   813,
     814,   815,   816,   817,   877,  -653,  -654,  -655,  -656,   366,
     878,   879,   880,   881,   882,   883,   884,   885,   886,   887,
     888,   889,   890,   891,   892,   893,   894,   895,   896,  -657,
    -658,  -659,  -660,  -661,  -662,  -663,  -664,  -665,  -666,   897,
     898,   899,  -667,  -668,   797,  -669,  -670,  -671,  -672,  -675,
    -676,  -677,  -678,  -679,  -680,   821,  -681,  -682,  -683,  -684,
    -685,  -686,  -687,  -688,  -689,  -690,  -691,  -692,  -693,   830,
     832,  -694,   686,   686,  -695,  -696,  -697,  -698,  -699,  -700,
    -701,  -702,  -703,  -704,  -705,   366,  -706,  -707,  -708,  -709,
    -710,   900,   901,  -711,  -712,   902,  -713,   994,  -714,  -715,
    -716,  -717,  -718,   903,  -719,   904,   629,   641,   611,   950,
     644,   905,   906,   907,   643,   642,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,   919,   920,   732,
     733,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     674,   995,   996,   997,   998,   999,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1009,   680,   681,   683,   684,
     690,   726,   727,   731,   749,   752,   755,   756,   757,   366,
     760,   762,   750,   792,  -460,   761,   793,   765,   743,   744,
     745,   746,   772,   823,   790,   944,   676,   833,   366,   952,
     798,   837,   838,   864,   856,   826,   865,   867,   869,   870,
     872,   873,   925,   927,   937,   933,   943,   747,   945,   923,
     946,   954,   934,   955,   956,   959,   957,   976,   931,   958,
     977,   960,   984,   961,   962,  1020,   965,   966,   967,   968,
    1030,   969,   970,   971,   972,   973,   974,   975,   993,  1031,
     366,   987,   991,  1033,  1012,  1034,   985,   986,  1019,  1021,
    1022,  1023,  1024,  1026,  1027,  1036,  1040,  1046,  1052,  1053,
    1032,  1072,  -610,  1039,   992,  1071,  1090,  1091,   135,  1113,
    1017,  1018,  1114,  1121,  1115,  1116,  1131,   400,  1133,   438,
    1025,   318,   365,  1042,  1129,   167,  1043,  1049,  1035,   430,
     924,   836,   759,   835,   366,   863,   862,  1120,   724,  1117,
     800,   941,   366,   952,  1044,   940,  1047,   868,   754,   581,
     639,   579,   619,   861,   715,   575,   978,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,     0,     0,     0,  1073,
       0,     0,   584,   585,   171,  1084,  1085,   172,   173,   174,
     175,   176,   586,     0,     0,     0,   177,     0,   624,   178,
     179,   180,   181,     0,     0,  1098,   182,     0,   183,   184,
     587,     0,   588,     0,   185,   186,     0,     0,     0,     0,
       0,     0,     0,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   589,   245,   246,   247,   590,   248,   249,   250,
       0,   251,   252,   253,   254,     0,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,     0,   267,
     591,   592,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,     0,   284,
     285,   286,   287,   288,   289,   290,   291,   292,     0,   293,
     169,   170,     0,     0,     0,     0,     0,     0,   584,   585,
     171,     0,     0,   172,   173,   174,   175,   176,   586,     0,
       0,     0,   177,     0,   627,   178,   179,   180,   181,     0,
       0,     0,   182,     0,   183,   184,   587,     0,   588,     0,
     185,   186,     0,     0,     0,     0,     0,     0,     0,   187,
       0,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   589,   245,
     246,   247,   590,   248,   249,   250,     0,   251,   252,   253,
     254,     0,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,     0,   267,   591,   592,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,     0,   284,   285,   286,   287,   288,
     289,   290,   291,   292,     0,   293,   169,   170,     0,     0,
       0,     0,     0,     0,   584,   585,   171,     0,     0,   172,
     173,   174,   175,   176,   586,     0,     0,     0,   177,     0,
     628,   178,   179,   180,   181,     0,     0,     0,   182,     0,
     183,   184,   587,     0,   588,     0,   185,   186,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   589,   245,   246,   247,   590,   248,
     249,   250,     0,   251,   252,   253,   254,     0,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
       0,   267,   591,   592,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
       0,   284,   285,   286,   287,   288,   289,   290,   291,   292,
       0,   293,   169,   170,     0,     0,     0,     0,     0,     0,
     584,   585,   171,     0,     0,   172,   173,   174,   175,   176,
     586,     0,     0,     0,   177,     0,     0,   178,   179,   180,
     181,     0,     0,     0,   182,     0,   183,   184,   587,     0,
     588,     0,   185,   186,     0,     0,     0,     0,     0,     0,
       0,   187,     0,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     589,   245,   246,   247,   590,   248,   249,   250,     0,   251,
     252,   253,   254,     0,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,   267,   591,   592,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,     0,   284,   285,   286,
     287,   288,   289,   290,   291,   292,     0,   293,   449,   450,
       0,     0,     0,     0,     0,     0,     0,     0,   451,     7,
       8,   452,   453,   174,   175,   454,     0,    12,     0,     0,
     455,     0,     0,   456,   179,   457,   458,     0,     0,     0,
     182,    18,   459,   460,     0,     0,     0,     0,   461,   462,
       0,     0,     0,     0,     0,     0,     0,   463,     0,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,    81,   521,   522,   523,
       0,   524,   525,   526,     0,   527,   528,   529,   530,    92,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   105,   543,     0,     0,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   123,   560,   561,   562,   563,   564,   565,   566,
     567,   568,     0,   569,   169,   170,     0,     0,     0,     0,
       0,     0,     0,     0,   171,     0,     0,   172,   173,   174,
     175,   176,     0,     0,     0,   699,   177,     0,     0,   178,
     179,   180,   181,     0,     0,     0,   182,   700,   183,   184,
       0,     0,   701,     0,   185,   186,     0,   702,     0,     0,
       0,   703,   704,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       0,   251,   705,   253,   254,   706,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,     0,   267,
       0,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,     0,   284,
     285,   286,   287,   288,   707,   290,   291,   292,     0,   293,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     8,     9,    10,     0,     0,    11,     0,    12,
       0,     0,    13,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,    18,    19,    20,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,    23,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,    87,     0,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,     4,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
      10,     0,     0,    11,     0,    12,     0,     0,    13,     0,
       0,    14,     0,    16,    17,     0,     0,     0,     0,    18,
      19,    20,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,    23,     0,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
      86,    87,     0,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
       0,   134,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,   171,     0,     0,   172,   173,   174,   175,   176,
       0,     0,     0,   699,   177,     0,     0,   178,   179,   180,
     181,     0,     0,     0,   182,   700,   183,   184,     0,     0,
     701,     0,   185,   186,     0,     0,     0,     0,     0,     0,
       0,   187,     0,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,   245,   246,   247,     0,   248,   249,   250,     0,   251,
     252,   253,   254,   706,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,   267,     0,     0,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,     0,   284,   285,   286,
     287,   288,   289,   290,   291,   292,     0,   293,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,   171,     0,
       0,   172,   173,   174,   175,   176,     0,   309,     0,     0,
     177,     0,     0,   178,   179,   180,   181,     0,     0,     0,
     182,     0,   183,   184,     0,     0,     0,     0,   185,   186,
       0,     0,     0,     0,     0,     0,     0,   187,   330,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,   246,   247,
       0,   248,   249,   250,     0,   251,   252,   253,   254,     0,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,     0,   267,     0,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,     0,   284,   285,   286,   287,   288,   289,   290,
     291,   292,     0,   293,   169,   170,     0,     0,     0,     0,
       0,     0,     0,     0,   171,     0,     0,   172,   173,   174,
     175,   176,     0,     0,     0,     0,   177,     0,     0,   178,
     631,   180,   181,     0,     0,     0,   182,     0,   183,   184,
       0,     0,     0,     0,   185,   186,     0,     0,     0,   632,
       0,     0,     0,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       0,   251,   252,   253,   254,     0,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   633,   267,
       0,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,     0,   284,
     285,   286,   287,   288,   289,   290,   291,   292,     0,   293,
     169,   170,     0,     0,     0,     0,     0,     0,     0,     0,
     171,     0,     0,   172,   173,   174,   175,   176,     0,     0,
       0,     0,   177,     0,     0,   178,   179,   180,   181,     0,
       0,     0,   182,     0,   183,   184,     0,   696,     0,     0,
     185,   186,     0,     0,     0,     0,     0,     0,     0,   187,
       0,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,   245,
     246,   247,     0,   248,   249,   250,     0,   251,   252,   253,
     254,     0,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,     0,   267,     0,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   697,   284,   285,   286,   287,   288,
     289,   290,   291,   292,     0,   293,   169,   170,     0,     0,
       0,     0,     0,     0,     0,     0,   171,     0,     0,   172,
     173,   174,   175,   176,     0,     0,     0,     0,   177,     0,
       0,   178,   179,   180,   181,     0,     0,     0,   182,     0,
     183,   184,     0,     0,   360,     0,   185,   186,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,   245,   246,   247,     0,   248,
     249,   250,     0,   251,   252,   253,   254,     0,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
       0,   267,     0,     0,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
       0,   284,   285,   286,   287,   288,   289,   290,   291,   292,
       0,   293,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,   368,     0,     0,   172,   173,   174,   369,   176,
       0,   309,     0,     0,   177,     0,     0,   178,   179,   180,
     181,     0,     0,     0,   182,     0,   183,   184,     0,     0,
       0,     0,   185,   186,     0,     0,     0,     0,     0,     0,
       0,   187,     0,   188,   189,   370,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,   245,   246,   247,     0,   248,   249,   250,     0,   251,
     252,   253,   254,     0,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   371,     0,   267,     0,     0,
     268,   372,   373,   271,   272,   273,   274,   275,   276,   277,
     374,   375,   280,   281,   282,   283,     0,   284,   285,   286,
     287,   288,   289,   290,   291,   292,     0,   293,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,   171,     0,
       0,   172,   173,   174,   175,   176,     0,   728,     0,     0,
     177,     0,     0,   178,   179,   180,   181,     0,     0,     0,
     182,     0,   183,   184,     0,     0,     0,     0,   185,   186,
       0,     0,     0,     0,     0,     0,     0,   187,     0,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,   246,   247,
       0,   248,   249,   250,     0,   251,   252,   253,   254,     0,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,     0,   267,     0,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,     0,   284,   285,   286,   287,   288,   289,   290,
     291,   292,     0,   293,   169,   170,     0,     0,     0,     0,
       0,     0,     0,     0,   171,     0,     0,   172,   173,   174,
     175,   176,     0,     0,     0,     0,   177,     0,     0,   178,
     179,   180,   181,     0,     0,     0,   182,     0,   183,   184,
       0,     0,     0,     0,   185,   186,     0,     0,     0,     0,
       0,     0,     0,   187,     0,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       0,   251,   252,   253,   254,     0,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,     0,   267,
       0,     0,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   766,   284,
     285,   286,   287,   288,   289,   290,   291,   292,     0,   293,
     169,   170,     0,     0,     0,     0,     0,     0,     0,     0,
     171,     0,     0,   172,   173,   174,   175,   176,     0,     0,
       0,     0,   177,     0,     0,   178,   179,   180,   181,     0,
       0,     0,   182,     0,   183,   184,     0,     0,     0,     0,
     185,   186,     0,     0,     0,   829,     0,     0,     0,   187,
       0,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,   245,
     246,   247,     0,   248,   249,   250,     0,   251,   252,   253,
     254,     0,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,     0,   267,     0,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,     0,   284,   285,   286,   287,   288,
     289,   290,   291,   292,     0,   293,   169,   170,     0,     0,
       0,     0,     0,     0,     0,     0,   171,     0,     0,   172,
     173,   174,   175,   176,     0,     0,     0,     0,   177,     0,
       0,   178,   179,   180,   181,     0,     0,     0,   182,     0,
     183,   184,     0,     0,     0,     0,   185,   186,     0,     0,
       0,   831,     0,     0,     0,   187,     0,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,   245,   246,   247,     0,   248,
     249,   250,     0,   251,   252,   253,   254,     0,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
       0,   267,     0,     0,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
       0,   284,   285,   286,   287,   288,   289,   290,   291,   292,
       0,   293,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,   171,     0,     0,   172,   173,   174,   175,   176,
       0,     0,     0,     0,   177,     0,     0,   178,   179,   180,
     181,     0,     0,     0,   182,     0,   183,   184,     0,     0,
       0,     0,   185,   186,     0,     0,     0,   951,     0,     0,
       0,   187,     0,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,   245,   246,   247,     0,   248,   249,   250,     0,   251,
     252,   253,   254,     0,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,     0,   267,     0,     0,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,     0,   284,   285,   286,
     287,   288,   289,   290,   291,   292,     0,   293,   169,   170,
       0,     0,     0,     0,     0,     0,     0,     0,   171,     0,
       0,   172,   173,   174,   175,   176,     0,     0,     0,     0,
     177,     0,     0,   178,   179,   180,   181,     0,     0,     0,
     182,     0,   183,   184,     0,     0,     0,     0,   185,   186,
       0,     0,     0,     0,     0,     0,     0,   187,     0,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,   245,   246,   247,
       0,   248,   249,   250,     0,   251,   252,   253,   254,     0,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,     0,   267,     0,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,     0,   284,   285,   286,   287,   288,   289,   290,
     291,   292,     0,   293,   169,   170,     0,     0,     0,     0,
       0,     0,     0,     0,   368,     0,     0,   172,   173,   174,
     369,   176,     0,     0,     0,     0,   177,     0,     0,   178,
     179,   180,   181,     0,     0,     0,   182,     0,   183,   184,
       0,     0,     0,     0,   185,   186,     0,     0,     0,     0,
       0,     0,     0,   187,     0,   188,   189,   370,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,   245,   246,   247,     0,   248,   249,   250,
       0,   251,   252,   253,   254,     0,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   371,     0,   267,
       0,     0,   268,   372,   373,   271,   272,   273,   274,   275,
     276,   277,   374,   375,   280,   281,   282,   283,     0,   284,
     285,   286,   287,   288,   289,   290,   291,   292,     0,   293,
     169,   170,     0,     0,     0,     0,     0,     0,     0,     0,
     171,     0,     0,   172,   173,   174,   175,   176,     0,     0,
       0,     0,   177,     0,     0,   178,   685,   180,   181,     0,
       0,     0,   182,     0,   183,   184,     0,     0,     0,     0,
     185,   186,     0,     0,     0,     0,     0,     0,     0,   187,
       0,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,   245,
     246,   247,     0,   248,   249,   250,     0,   251,   252,   253,
     254,     0,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,     0,   267,     0,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,     0,   284,   285,   286,   287,   288,
     289,   290,   291,   292,     0,   293,   169,   170,     0,     0,
       0,     0,     0,     0,     0,     0,   171,     0,     0,   172,
     173,   174,   175,   176,     0,     0,     0,     0,   177,     0,
       0,   178,   179,   180,   181,     0,     0,     0,   182,     0,
     183,   184,     0,     0,     0,     0,   185,  1041,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,   245,   246,   247,     0,   248,
     249,   250,     0,   251,   252,   253,   254,     0,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
       0,   267,     0,     0,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
       0,   284,   285,   286,   287,   288,   289,   290,   291,   292,
       0,   293
};

static const yytype_int16 yycheck[] =
{
     147,   148,   342,   312,   650,   152,   153,   344,   155,   141,
     157,   659,   447,   856,   662,     0,    27,   153,   165,   155,
     113,   157,    52,    23,    24,    72,    29,     8,     9,    46,
       9,    60,   341,     9,    19,   619,   323,    46,   325,    37,
     377,    37,    27,    46,    28,   312,   594,    90,    21,    29,
      37,     0,    29,    27,   602,   603,   702,   703,   704,   705,
      49,    29,    30,   330,    45,    82,   714,   651,   377,    58,
      29,    30,    38,    82,    58,    55,    56,    28,    46,    58,
     173,   128,    58,   113,   927,    23,    24,    46,   181,    46,
     183,    72,    51,    44,    40,   432,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   109,   115,   109,   143,   158,    90,   160,   161,   765,
     163,   164,   109,    45,   167,    47,    40,   773,   774,   775,
     776,   777,   778,   779,   780,   781,   782,   783,   981,   785,
     121,   789,   159,   173,   790,   126,   127,   128,   125,   130,
     131,   181,    38,   183,   441,   304,    43,   306,   305,   308,
     307,   129,  1032,   174,    41,   312,    58,   126,    52,   305,
     129,   307,   607,   730,    58,   324,   578,   326,   580,    52,
      41,   328,   182,   330,   158,    58,   160,   161,    52,   163,
     164,    25,   749,   167,    58,   342,    27,   344,    90,   184,
     185,   186,   187,   188,    20,   190,    42,   853,    52,   611,
     357,  1077,  1078,    42,    58,    29,     8,     9,    51,   351,
      52,   357,   207,   208,  1094,  1095,    58,  1097,    52,    19,
     377,    52,   144,   145,    58,  1101,  1102,    58,    37,    38,
      39,   578,   644,   580,    45,    93,   149,   150,   151,   398,
     652,   107,   108,    45,   401,   402,   403,   404,    22,   406,
     171,    53,    54,    55,    56,   174,   158,    29,   160,   161,
      31,   163,   164,     8,     9,   167,   192,   193,    27,   426,
      72,    27,   928,   931,    31,   432,   433,    27,   934,    45,
     374,   375,   439,   440,    31,     8,     9,    53,    54,    55,
      56,   149,   150,   151,   152,   153,   154,   155,   648,   649,
      45,   149,   150,   151,   152,   652,    72,    52,    53,    54,
      55,    56,    93,   175,   176,   177,   178,   179,   180,   121,
     122,   123,    45,    39,   126,   127,   128,    72,   130,   131,
      53,    54,    55,    56,     8,   184,   185,   186,   187,   188,
      57,   190,     8,     9,   122,   123,   696,   439,   440,    72,
      46,    51,   671,   158,    47,   121,   122,   123,   207,   208,
     126,   127,   128,   165,   130,   131,   146,    45,   149,   150,
     151,    29,   153,   154,   155,    45,   121,   122,   123,    45,
      45,   126,   127,   128,    45,   130,   131,    53,    54,    55,
      56,   132,   133,   134,   135,   136,   137,   138,   121,   122,
     123,    16,    46,   126,   127,   128,    72,   130,   131,    30,
      46,    37,    39,    58,    29,    30,    39,    39,    51,   576,
      39,   578,   772,   580,    53,    39,    41,    39,    39,    16,
      39,    46,    39,    39,    47,    39,    39,   594,    39,    39,
      55,    56,    29,    30,    39,   602,   603,    39,   605,   606,
      39,    39,    16,   610,    41,   121,   122,   123,    39,    46,
     126,   127,   128,    39,   130,   131,    39,    39,    55,    56,
      39,    39,    39,    39,    39,   632,    39,  1103,  1104,  1105,
    1106,  1107,    39,  1109,    39,   642,    39,    39,    36,    39,
      39,   648,   649,    39,    39,   652,    39,    39,    39,    39,
      48,    39,    50,  1129,    39,  1131,    39,  1133,    39,    39,
     667,    39,  1138,    39,    39,    39,    39,   674,    39,    39,
      39,    39,    39,   680,    39,   875,   683,   132,   133,   134,
     135,   136,   137,   138,    82,    39,    39,    39,    39,   696,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,   117,
     118,   119,    39,    39,   731,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,   742,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,   756,
     757,    39,   759,   760,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,   772,    39,    39,    39,    39,
      39,   169,   170,    39,    39,   173,    39,    29,    39,    39,
      39,    39,    39,   181,    39,   183,    27,    26,    39,   989,
      39,   189,   190,   191,    29,    51,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      39,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    39,    26,     8,    29,
      52,    27,    27,    39,    42,    29,    28,    39,    39,   856,
      59,    46,   126,    52,    51,   109,    58,    45,   111,   112,
     113,   114,   152,    41,    51,   872,    60,   110,   875,   876,
      51,    51,    46,    29,    51,    58,    51,   109,   109,    51,
      39,    29,    29,    51,    29,    52,    29,   140,    28,   139,
      25,    45,    58,    45,    45,    45,    72,    58,   166,    72,
      58,    45,    29,    45,    45,    51,    45,    45,    45,    45,
      29,    45,    45,    45,    45,    45,    45,    45,    39,    29,
     927,    45,    45,    29,    46,    29,    52,    52,    46,    46,
      46,    46,    46,    46,    46,    29,    29,    39,    39,    39,
      51,    39,    45,    52,   951,    52,    29,    29,     1,    30,
     957,   958,    30,    52,    46,    46,    51,   358,   123,   391,
     967,   298,   341,   989,    72,   144,   990,  1010,   976,   377,
     834,   760,   687,   759,   981,   795,   794,  1097,   668,  1093,
     739,   869,   989,   990,   991,   867,   993,   817,   683,   424,
     610,   415,   580,   793,   652,   407,   927,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,  1046,
      -1,    -1,    16,    17,    18,  1052,  1053,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    -1,  1072,    40,    -1,    42,    43,
      44,    -1,    46,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    44,    -1,    46,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      42,    43,    44,    -1,    46,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    42,    43,    44,    -1,
      46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,   121,   122,   123,    -1,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    48,    49,    -1,    51,    -1,    -1,
      -1,    55,    56,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    -1,    -1,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    -1,    -1,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,    -1,   121,   122,   123,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,   118,   119,
      -1,   121,   122,   123,    -1,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    -1,    45,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      42,    43,    -1,    -1,    46,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,    -1,   121,   122,   123,    -1,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,   118,   119,
      -1,   121,   122,   123,    -1,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    57,    -1,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,    -1,   121,   122,   123,    -1,   125,
     126,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,    -1,   173,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,   117,   118,   119,
      -1,   121,   122,   123,    -1,   125,   126,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,   143,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,    -1,   173,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,   117,   118,   119,    -1,   121,   122,   123,
      -1,   125,   126,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    -1,   173,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,   117,
     118,   119,    -1,   121,   122,   123,    -1,   125,   126,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,    -1,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,   173,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,   117,   118,   119,    -1,   121,
     122,   123,    -1,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,   173
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   210,   211,     8,     9,    18,    19,    20,    21,
      22,    25,    27,    30,    33,    34,    35,    36,    41,    42,
      43,    48,    49,    57,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   121,   122,   123,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   212,   214,   369,     0,    23,
      24,   182,   215,   238,   239,   240,    40,    38,    38,    40,
      46,   241,   175,   176,   177,   178,   179,   180,   216,   217,
     218,   219,   223,   227,   237,    43,   258,   240,    41,     8,
       9,    18,    21,    22,    23,    24,    25,    30,    33,    34,
      35,    36,    40,    42,    43,    48,    49,    57,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   117,   118,   119,   121,   122,
     123,   125,   126,   127,   128,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   143,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   173,   213,   370,   213,    41,   242,    25,
     243,   248,   213,   222,   222,   224,   222,   228,   222,    27,
     249,   213,   259,   260,    20,   263,    42,    42,   243,    29,
     244,    51,   231,   231,   222,   231,   222,   231,    45,   261,
      58,   249,   260,   184,   185,   186,   187,   188,   190,   207,
     208,   264,   265,   266,    19,   288,    22,   171,   247,   232,
     235,   236,   237,   235,   231,   235,   231,   174,   220,   221,
      46,   213,   262,   260,   249,   266,   213,   305,    18,    24,
      61,   141,   147,   148,   156,   157,   213,   289,   290,   291,
     333,   338,   340,   356,    29,    31,   113,   173,   181,   183,
     233,   234,    27,   237,    27,    31,    27,    31,   222,    27,
     221,    39,    37,    38,    39,   267,     8,   334,   335,    57,
      46,    51,   149,   150,   151,   350,   352,    93,   149,   150,
     151,   153,   154,   155,   351,   353,   158,   357,   357,   249,
     290,    47,   146,   245,    45,    45,    45,    52,   233,   225,
     229,   231,   213,   213,   213,   213,    45,   268,   269,     8,
       9,    18,    21,    22,    25,    30,    33,    35,    36,    42,
      43,    48,    49,    57,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   117,   118,   119,   121,   122,   123,   125,   126,   127,
     128,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   143,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   173,
     212,   336,   337,   338,   339,   335,   292,    29,   152,   352,
     152,   353,   213,   338,    16,    17,    26,    44,    46,   116,
     120,   144,   145,   213,   250,   251,   252,   253,   254,    46,
      30,    46,   250,   250,   235,    37,   270,    47,   269,     9,
      58,    39,   213,   296,    58,   338,   339,   354,   355,   354,
      51,    47,   295,   255,    32,   252,    16,    32,    32,    27,
     213,    34,    53,   142,   213,   275,   269,    53,   294,   337,
     339,    26,    51,    29,    39,    58,    90,   160,   161,   163,
     164,   167,   298,   341,   342,   344,   345,   346,   347,   348,
     349,   357,   348,   358,   144,   145,   256,   302,   303,   304,
     306,   246,   226,   230,    39,   213,    60,   143,   273,   274,
      39,    26,   272,     8,    29,    34,   213,   297,   299,   300,
      52,   339,    46,    82,   159,   305,    45,   162,   305,    29,
      41,    46,    51,    55,    56,   126,   129,   168,   213,   305,
     362,   365,   366,   367,   348,   355,   341,   359,   360,   361,
     362,    28,    44,   213,   304,   249,    27,    27,    27,   213,
     301,    39,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,   111,   112,   113,   114,   140,   308,    42,
     126,   213,    29,   271,   336,    28,    39,    39,    52,   298,
      59,   109,    46,    46,    82,    45,   162,   305,   362,   362,
     362,   362,   152,     8,     9,    45,    53,    54,    55,    56,
      72,   121,   122,   123,   126,   127,   128,   130,   131,   165,
      51,    27,    52,    58,   257,   307,   273,   213,    51,   314,
     314,   132,   133,   134,   135,   136,   137,   138,   321,   322,
     324,   132,   133,   134,   135,   136,   137,   138,   315,   318,
     319,   213,   273,    41,    28,    58,    58,   282,     9,    53,
     213,    53,   213,   110,   293,   300,   299,    51,    46,   362,
      52,   305,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,    72,   128,   362,    51,   341,   362,   363,
     364,   361,   306,   302,    29,    51,   325,   109,   325,   109,
      51,   316,    39,    29,    36,    48,    50,    82,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   117,   118,   119,
     169,   170,   173,   181,   183,   189,   190,   191,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   283,   284,   139,   295,    29,   362,    51,   123,   367,
     368,   166,   343,    52,    58,    52,    58,    29,   317,   323,
     324,   319,   320,    29,   213,    28,    25,   276,   277,   278,
     305,    53,   213,   280,    45,    45,    45,    72,    72,    45,
      45,    45,    45,   107,   108,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    58,    58,   368,   362,
      52,    58,   341,   362,    29,    52,    52,    45,    49,    58,
     281,    45,   213,    39,    29,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     286,   287,    46,    29,    46,   115,   285,   213,   213,    46,
      51,    46,    46,    46,    46,   213,    46,    46,   192,   193,
      29,    29,    51,    29,    29,   284,    29,    52,   367,    52,
      29,    49,   277,   280,   213,   279,    39,   213,   125,   287,
     326,   327,    39,    39,    16,    29,    30,    41,    46,    55,
      56,   309,   311,   313,    16,    30,    41,    46,   310,   311,
     312,    52,    39,   213,    29,    30,    46,    51,   126,   129,
     328,   329,   330,   331,   213,   213,    37,   109,    37,   109,
      29,    29,    52,    58,    37,   109,    52,    58,   213,   329,
     329,   122,   123,     8,     9,    45,    72,   121,   126,   127,
     128,   130,   131,    30,    30,    46,    46,   313,   311,   311,
     312,    52,   329,   329,   330,   330,   330,   330,   330,    72,
     330,    51,   330,   123,   330,   332,   330,    52,    58,   330
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
#line 147 "screen.yacc"
    {
A4GL_check_compiled_form();
A4GL_write_form();}
    break;

  case 3:
#line 152 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:
#line 153 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (5)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 158 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 159 "screen.yacc"
    {the_form.dbname=acl_strdup(downshift((yyvsp[(2) - (2)].str)));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 11:
#line 178 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:
#line 179 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:
#line 181 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 15:
#line 186 "screen.yacc"
    {
			the_form.layout=NULL;
	}
    break;

  case 16:
#line 189 "screen.yacc"
    {
			the_form.layout=(yyvsp[(1) - (1)].layout);
	}
    break;

  case 17:
#line 196 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 18:
#line 206 "screen.yacc"
    {
			(yyval.layout)=(yyvsp[(4) - (5)].layout);
			(yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
			(yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
    break;

  case 19:
#line 215 "screen.yacc"
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
#line 228 "screen.yacc"
    {
		 (yyval.layout)=(yyvsp[(4) - (5)].layout);
		 (yyval.layout)->id=strdup((yyvsp[(2) - (5)].str));
		 (yyval.layout)->attrib=(yyvsp[(3) - (5)].layout_attrib);
	}
    break;

  case 21:
#line 236 "screen.yacc"
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
#line 246 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 23:
#line 254 "screen.yacc"
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
#line 267 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 26:
#line 273 "screen.yacc"
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
    break;

  case 27:
#line 276 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 28:
#line 279 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 29:
#line 280 "screen.yacc"
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
#line 295 "screen.yacc"
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
    break;

  case 31:
#line 298 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 32:
#line 301 "screen.yacc"
    {ignorekw=0; in_screen_section=0;}
    break;

  case 33:
#line 302 "screen.yacc"
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
#line 315 "screen.yacc"
    {
		(yyval.layout_attrib)=0;
		}
    break;

  case 35:
#line 318 "screen.yacc"
    { new_layout_attribs(); }
    break;

  case 36:
#line 318 "screen.yacc"
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
    break;

  case 37:
#line 324 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[(3) - (3)].str));
	}
    break;

  case 38:
#line 327 "screen.yacc"
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
    break;

  case 39:
#line 330 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 40:
#line 333 "screen.yacc"
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[(3) - (3)].str)); 
	}
    break;

  case 43:
#line 344 "screen.yacc"
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
#line 353 "screen.yacc"
    {(yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 45:
#line 359 "screen.yacc"
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
#line 369 "screen.yacc"
    {
		add_child((yyvsp[(1) - (2)].layout), (yyvsp[(2) - (2)].layout));
		(yyval.layout)=(yyvsp[(1) - (2)].layout);
	}
    break;

  case 47:
#line 377 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout); }
    break;

  case 48:
#line 379 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 49:
#line 381 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 50:
#line 383 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 51:
#line 385 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 52:
#line 387 "screen.yacc"
    { (yyval.layout)=(yyvsp[(1) - (1)].layout);}
    break;

  case 53:
#line 393 "screen.yacc"
    {
		(yyval.layout)=(yyvsp[(2) - (3)].layout);
	}
    break;

  case 56:
#line 404 "screen.yacc"
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
#line 417 "screen.yacc"
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
#line 436 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 61:
#line 438 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 62:
#line 441 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 65:
#line 446 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 68:
#line 453 "screen.yacc"
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
#line 475 "screen.yacc"
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
#line 490 "screen.yacc"
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
#line 502 "screen.yacc"
    { ltab=0; }
    break;

  case 76:
#line 503 "screen.yacc"
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
#line 514 "screen.yacc"
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
#line 525 "screen.yacc"
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
#line 538 "screen.yacc"
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
#line 550 "screen.yacc"
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
#line 561 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 82:
#line 566 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 83:
#line 569 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 84:
#line 577 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 85:
#line 578 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 86:
#line 584 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 87:
#line 591 "screen.yacc"
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
#line 605 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 89:
#line 608 "screen.yacc"
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
#line 619 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 96:
#line 635 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 97:
#line 644 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 98:
#line 645 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 99:
#line 648 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 100:
#line 649 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 101:
#line 651 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 102:
#line 652 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 103:
#line 653 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 108:
#line 669 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 109:
#line 670 "screen.yacc"
    {strcpy((yyval.str),"Edit");}
    break;

  case 110:
#line 671 "screen.yacc"
    {strcpy((yyval.str),"TextEdit");}
    break;

  case 111:
#line 672 "screen.yacc"
    {strcpy((yyval.str),"Label");}
    break;

  case 112:
#line 673 "screen.yacc"
    {strcpy((yyval.str),"DateEdit");}
    break;

  case 113:
#line 674 "screen.yacc"
    {strcpy((yyval.str),"ButtonEdit");}
    break;

  case 114:
#line 675 "screen.yacc"
    {strcpy((yyval.str),"Image");}
    break;

  case 115:
#line 676 "screen.yacc"
    {strcpy((yyval.str),"ProgressBar");}
    break;

  case 116:
#line 677 "screen.yacc"
    {strcpy((yyval.str),"ComboBox");}
    break;

  case 117:
#line 682 "screen.yacc"
    {
			A4GL_make_downshift((yyvsp[(2) - (2)].str));
			strcpy(currftag,(yyvsp[(2) - (2)].str));
			fldno=A4GL_find_field((yyvsp[(2) - (2)].str));
		}
    break;

  case 118:
#line 688 "screen.yacc"
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

  case 122:
#line 706 "screen.yacc"
    { 
	A4GL_init_fld();
}
    break;

  case 123:
#line 710 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 124:
#line 718 "screen.yacc"
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
				fprintf(stderr, "Conditions in upscol are not handled yet (%s)",att_condition);
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

  case 126:
#line 892 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 127:
#line 896 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 128:
#line 904 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 129:
#line 905 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 130:
#line 908 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 131:
#line 909 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 132:
#line 912 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 133:
#line 915 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 134:
#line 920 "screen.yacc"
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

  case 135:
#line 929 "screen.yacc"
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

  case 136:
#line 941 "screen.yacc"
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

  case 137:
#line 953 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 138:
#line 960 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 139:
#line 968 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 140:
#line 975 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 141:
#line 988 "screen.yacc"
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(1) - (1)].lookup);
	}
    break;

  case 142:
#line 997 "screen.yacc"
    {
		(yyval.lookups)=(yyvsp[(1) - (3)].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[(3) - (3)].lookup);
	}
    break;

  case 143:
#line 1006 "screen.yacc"
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[(1) - (3)].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 145:
#line 1015 "screen.yacc"
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
		}
    break;

  case 146:
#line 1018 "screen.yacc"
    {
			sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));
	}
    break;

  case 147:
#line 1024 "screen.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 148:
#line 1025 "screen.yacc"
    {sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 149:
#line 1026 "screen.yacc"
    {sprintf((yyval.str),"*%s.%s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 150:
#line 1027 "screen.yacc"
    {sprintf((yyval.str),"*%s",(yyvsp[(2) - (2)].str));}
    break;

  case 157:
#line 1043 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 158:
#line 1044 "screen.yacc"
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

  case 159:
#line 1064 "screen.yacc"
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

  case 160:
#line 1086 "screen.yacc"
    {
	(yyvsp[(2) - (4)].lookups)->joincol=strdup((yyvsp[(4) - (4)].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[(2) - (4)].lookups);
}
    break;

  case 161:
#line 1092 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 162:
#line 1093 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 163:
#line 1094 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 164:
#line 1095 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 165:
#line 1096 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 166:
#line 1097 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 167:
#line 1098 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 168:
#line 1099 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 169:
#line 1100 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 170:
#line 1101 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 171:
#line 1102 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 172:
#line 1103 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 173:
#line 1104 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 174:
#line 1105 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 175:
#line 1106 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[(4) - (4)].str)); A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 176:
#line 1107 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 177:
#line 1108 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 178:
#line 1110 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 179:
#line 1112 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 180:
#line 1113 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 181:
#line 1114 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 182:
#line 1115 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REQUIRED); }
    break;

  case 183:
#line 1116 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_REVERSE); }
    break;

  case 184:
#line 1117 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 185:
#line 1118 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_QUERYCLEAR); }
    break;

  case 186:
#line 1119 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_ZEROFILL); }
    break;

  case 187:
#line 1120 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_RIGHT); }
    break;

  case 188:
#line 1121 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WORDWRAP); }
    break;

  case 189:
#line 1122 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 190:
#line 1126 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 191:
#line 1133 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_HIDDEN); }
    break;

  case 192:
#line 1134 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTOSCALE); }
    break;

  case 193:
#line 1135 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WANTNORETURNS); }
    break;

  case 194:
#line 1136 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_WANTTABS); }
    break;

  case 195:
#line 1137 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_FONTPITCHFIXED); }
    break;

  case 196:
#line 1138 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_FONTPITCHVARIABLE); }
    break;

  case 197:
#line 1139 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLL); }
    break;

  case 198:
#line 1140 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_IMAGE,(yyvsp[(3) - (3)].str)); }
    break;

  case 199:
#line 1141 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PIXELHEIGHT,(yyvsp[(3) - (3)].str)); }
    break;

  case 200:
#line 1142 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PIXELWIDTH,(yyvsp[(3) - (3)].str)); }
    break;

  case 201:
#line 1143 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_BOTH); }
    break;

  case 202:
#line 1144 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_VERTICAL); }
    break;

  case 203:
#line 1145 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_SCROLLBARS_HORIZONAL); }
    break;

  case 204:
#line 1146 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_STRETCH_Y); }
    break;

  case 205:
#line 1147 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_STRETCH_BOTH); }
    break;

  case 206:
#line 1148 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ITEMS,(yyvsp[(4) - (5)].str)); }
    break;

  case 207:
#line 1149 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEMAX,(yyvsp[(3) - (3)].str)); }
    break;

  case 208:
#line 1150 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_VALUEMIN,(yyvsp[(3) - (3)].str)); }
    break;

  case 209:
#line 1151 "screen.yacc"
    { A4GL_add_str_attr(fld, FA_S_STYLE, (yyvsp[(3) - (3)].str)); }
    break;

  case 210:
#line 1157 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 211:
#line 1158 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 212:
#line 1159 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 214:
#line 1164 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 215:
#line 1168 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 216:
#line 1169 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 217:
#line 1170 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 218:
#line 1171 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 219:
#line 1172 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 220:
#line 1173 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 221:
#line 1174 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 222:
#line 1175 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 223:
#line 1177 "screen.yacc"
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

  case 224:
#line 1191 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 225:
#line 1192 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 226:
#line 1193 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 227:
#line 1194 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 228:
#line 1195 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 229:
#line 1196 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 230:
#line 1197 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 237:
#line 1210 "screen.yacc"
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

  case 238:
#line 1220 "screen.yacc"
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[(1) - (1)].control_block),sizeof(struct s_control_block));
;
}
    break;

  case 239:
#line 1226 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 246:
#line 1237 "screen.yacc"
    {(yyval.intval)=0;}
    break;

  case 247:
#line 1237 "screen.yacc"
    {(yyval.intval)=1;}
    break;

  case 250:
#line 1242 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 251:
#line 1245 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 252:
#line 1251 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 253:
#line 1254 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 256:
#line 1264 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),""); }
    break;

  case 257:
#line 1266 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); }
    break;

  case 258:
#line 1268 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); }
    break;

  case 259:
#line 1270 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); }
    break;

  case 260:
#line 1272 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 262:
#line 1276 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 263:
#line 1280 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 264:
#line 1283 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 265:
#line 1287 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 266:
#line 1287 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 269:
#line 1294 "screen.yacc"
    {colno++;}
    break;

  case 270:
#line 1295 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 271:
#line 1308 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 272:
#line 1316 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 273:
#line 1318 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 274:
#line 1325 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 275:
#line 1329 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 276:
#line 1333 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 277:
#line 1337 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 278:
#line 1341 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 279:
#line 1345 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 280:
#line 1349 "screen.yacc"
    {
		int i;
		i=atoi((yyvsp[(2) - (2)].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
    break;

  case 281:
#line 1355 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 282:
#line 1359 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 283:
#line 1363 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 284:
#line 1367 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 285:
#line 1371 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 286:
#line 1375 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 287:
#line 1379 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 288:
#line 1382 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 290:
#line 1389 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 292:
#line 1393 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 295:
#line 1398 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 296:
#line 1402 "screen.yacc"
    { 
		if (strlen((yyvsp[(1) - (1)].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
		}
	}
    break;

  case 297:
#line 1409 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 298:
#line 1410 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 300:
#line 1412 "screen.yacc"
    {
		strcpy((yyval.str),"");
	}
    break;

  case 301:
#line 1418 "screen.yacc"
    { 
	if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
		sprintf((yyval.str),"NULL");
	} else {
		strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
	}
}
    break;

  case 302:
#line 1425 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 303:
#line 1426 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 304:
#line 1427 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 305:
#line 1428 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 307:
#line 1430 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 308:
#line 1431 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 309:
#line 1432 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 310:
#line 1436 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 311:
#line 1440 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 312:
#line 1445 "screen.yacc"
    {
			sprintf((yyval.str),"0");
		}
    break;

  case 313:
#line 1448 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 314:
#line 1449 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 315:
#line 1452 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 316:
#line 1454 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 317:
#line 1460 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 318:
#line 1462 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 319:
#line 1467 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 320:
#line 1475 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 321:
#line 1478 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 322:
#line 1479 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 323:
#line 1480 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 324:
#line 1481 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 325:
#line 1482 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 326:
#line 1483 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 327:
#line 1485 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 329:
#line 1492 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 330:
#line 1493 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 331:
#line 1496 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 332:
#line 1499 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 333:
#line 1503 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 334:
#line 1504 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 335:
#line 1505 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 336:
#line 1506 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 337:
#line 1507 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 338:
#line 1508 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 339:
#line 1510 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 340:
#line 1515 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 341:
#line 1517 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 342:
#line 1524 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 343:
#line 1524 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 344:
#line 1530 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 346:
#line 1537 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 347:
#line 1540 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 348:
#line 1546 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 349:
#line 1547 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 350:
#line 1548 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 351:
#line 1549 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 352:
#line 1550 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 353:
#line 1551 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 354:
#line 1552 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 355:
#line 1553 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 356:
#line 1554 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 357:
#line 1555 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 358:
#line 1556 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 359:
#line 1557 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 360:
#line 1558 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 361:
#line 1561 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 362:
#line 1568 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 363:
#line 1569 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 364:
#line 1570 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 366:
#line 1578 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 367:
#line 1582 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 371:
#line 1602 "screen.yacc"
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[(2) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[(6) - (7)].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[(4) - (7)].intval);
	}
    break;

  case 372:
#line 1612 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 373:
#line 1619 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 374:
#line 1628 "screen.yacc"
    {
	(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
	(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
}
    break;

  case 375:
#line 1631 "screen.yacc"
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[(1) - (1)].str),"");
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
}
    break;

  case 378:
#line 1650 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);
	}
    break;

  case 379:
#line 1657 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[(2) - (5)].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[(4) - (5)].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[(5) - (5)].at_block);

	}
    break;

  case 380:
#line 1665 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 381:
#line 1670 "screen.yacc"
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[(2) - (2)].fcall);
	}
    break;

  case 382:
#line 1678 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
    break;

  case 383:
#line 1682 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[(1) - (1)].at_comments);
	}
    break;

  case 384:
#line 1687 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[(1) - (1)].at_if);
	}
    break;

  case 385:
#line 1692 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[(1) - (1)].at_let);
	}
    break;

  case 386:
#line 1697 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[(1) - (1)].at_nextfield);
	}
    break;

  case 387:
#line 1702 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[(1) - (1)].fcall);
	}
    break;

  case 388:
#line 1707 "screen.yacc"
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[(1) - (1)].at_block);

	}
    break;

  case 389:
#line 1716 "screen.yacc"
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[(2) - (5)].expr);
		(yyval.at_if)->if_true=(yyvsp[(4) - (5)].at_action);
		(yyval.at_if)->if_false=(yyvsp[(5) - (5)].at_action);
	}
    break;

  case 390:
#line 1725 "screen.yacc"
    {(yyval.at_action)=0;}
    break;

  case 391:
#line 1726 "screen.yacc"
    {	
		(yyval.at_action)=(yyvsp[(2) - (2)].at_action);
	}
    break;

  case 393:
#line 1735 "screen.yacc"
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[(2) - (4)].str));
			(yyval.at_let)->value=(yyvsp[(4) - (4)].expr);
		}
    break;

  case 394:
#line 1743 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(2) - (2)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 395:
#line 1749 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[(3) - (3)].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
    break;

  case 396:
#line 1755 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 397:
#line 1761 "screen.yacc"
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
    break;

  case 398:
#line 1769 "screen.yacc"
    {
		 (yyval.at_block)= (yyvsp[(2) - (3)].at_block);
	}
    break;

  case 399:
#line 1774 "screen.yacc"
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(1) - (1)].at_action);

	}
    break;

  case 400:
#line 1784 "screen.yacc"
    {
		(yyval.at_block)=(yyvsp[(1) - (2)].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[(2) - (2)].at_action);
		}
    break;

  case 401:
#line 1794 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(2) - (2)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 402:
#line 1800 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
    break;

  case 403:
#line 1806 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(3) - (3)].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 404:
#line 1812 "screen.yacc"
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[(4) - (4)].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
    break;

  case 405:
#line 1822 "screen.yacc"
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

  case 406:
#line 1834 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 407:
#line 1842 "screen.yacc"
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

  case 408:
#line 1854 "screen.yacc"
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[(2) - (2)].intval);
	}
    break;

  case 409:
#line 1862 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 410:
#line 1863 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 411:
#line 1864 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 412:
#line 1868 "screen.yacc"
    {(yyval.intval)=E_BA_EDITADD;}
    break;

  case 413:
#line 1869 "screen.yacc"
    {(yyval.intval)=E_BA_ADD;}
    break;

  case 414:
#line 1870 "screen.yacc"
    {(yyval.intval)=E_BA_UPDATE;}
    break;

  case 415:
#line 1871 "screen.yacc"
    {(yyval.intval)=E_BA_QUERY;}
    break;

  case 416:
#line 1872 "screen.yacc"
    {(yyval.intval)=E_BA_REMOVE;}
    break;

  case 417:
#line 1873 "screen.yacc"
    {(yyval.intval)=E_BA_DISPLAY;}
    break;

  case 418:
#line 1874 "screen.yacc"
    {(yyval.intval)=E_BA_EDITUPDATE;}
    break;

  case 419:
#line 1877 "screen.yacc"
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[(1) - (1)].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[(1) - (1)].column).colname;
	}
    break;

  case 420:
#line 1884 "screen.yacc"
    {
		(yyval.col_list)=(yyvsp[(1) - (3)].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[(3) - (3)].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[(3) - (3)].column).colname;
	}
    break;

  case 421:
#line 1895 "screen.yacc"
    {
		(yyval.column).tabname=strdup((yyvsp[(1) - (3)].str));
		(yyval.column).colname=strdup((yyvsp[(3) - (3)].str));
	}
    break;

  case 422:
#line 1899 "screen.yacc"
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 423:
#line 1906 "screen.yacc"
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[(1) - (4)].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[(3) - (4)].str));
	}
    break;

  case 424:
#line 1914 "screen.yacc"
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[(2) - (3)].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
    break;

  case 425:
#line 1919 "screen.yacc"
    {
		if ((yyvsp[(5) - (6)].el)) {
			listitem *l;
			(yyval.fcall)->list_parameters.list_parameters_len=(yyvsp[(5) - (6)].el)->nlist;
			l=(yyvsp[(5) - (6)].el)->expr_list;
			(yyval.fcall)->list_parameters.list_parameters_val=l;
		}
	}
    break;

  case 426:
#line 1930 "screen.yacc"
    {(yyval.el)=0;}
    break;

  case 427:
#line 1931 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (1)].el);
	}
    break;

  case 428:
#line 1937 "screen.yacc"
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 429:
#line 1943 "screen.yacc"
    {
		(yyval.el)=(yyvsp[(1) - (3)].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[(3) - (3)].expr);
	}
    break;

  case 430:
#line 1951 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(1) - (1)].expr);
	}
    break;

  case 432:
#line 1959 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 433:
#line 1960 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 438:
#line 1974 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 439:
#line 1976 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 440:
#line 1977 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 441:
#line 1978 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 442:
#line 1979 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 443:
#line 1980 "screen.yacc"
    { (yyval.expr)=(yyvsp[(3) - (4)].expr); }
    break;

  case 444:
#line 1981 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(3) - (3)].str)); }
    break;

  case 445:
#line 1982 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 446:
#line 1983 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 447:
#line 1984 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 448:
#line 1985 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 449:
#line 1986 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 450:
#line 1987 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 451:
#line 1988 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 452:
#line 1989 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 453:
#line 1990 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 454:
#line 1991 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 455:
#line 1992 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 456:
#line 1993 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 457:
#line 1994 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 458:
#line 1995 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 459:
#line 1996 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (6)].expr),(yyvsp[(5) - (6)].expr),"NOTIN"); }
    break;

  case 461:
#line 2002 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 462:
#line 2003 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 463:
#line 2004 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 464:
#line 2005 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 465:
#line 2006 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 466:
#line 2009 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 467:
#line 2013 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 6605 "y.tab.c"
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


#line 2334 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




