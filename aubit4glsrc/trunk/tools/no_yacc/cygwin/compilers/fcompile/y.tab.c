/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         a4gl_form_yyparse
#define yylex           a4gl_form_yylex
#define yyerror         a4gl_form_yyerror
#define yydebug         a4gl_form_yydebug
#define yynerrs         a4gl_form_yynerrs

#define yylval          a4gl_form_yylval
#define yychar          a4gl_form_yychar

/* Copy the first part of user declarations.  */
#line 1 "screen.yacc" /* yacc.c:339  */

#define YYDEBUG 1
#ifdef YYPURE
#undef YYPURE
#endif
#define YYPURE 1
/*#define YYLEX_PARAM yystate */
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


#line 152 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_A4GL_FORM_YY_Y_TAB_H_INCLUDED
# define YY_A4GL_FORM_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int a4gl_form_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_OR = 258,
    KW_AND = 259,
    KW_NOT = 260,
    IS_NULL = 261,
    IS_NOT_NULL = 262,
    GREATERTHAN = 263,
    LESSTHAN = 264,
    KW_MINUS = 265,
    KW_PLUS = 266,
    KW_DIVIDE = 267,
    KW_MULTIPLY = 268,
    KW_POWER = 269,
    KW_MOD = 270,
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
    KW_NOSHOW = 448,
    KW_NOHIDEMENU = 449,
    KW_TEXTEDIT = 450,
    KW_BUTTONEDIT = 451,
    KW_LABEL = 452,
    KW_EDIT = 453,
    KW_DATEEDIT = 454,
    KW_SCROLL = 455,
    KW_IMAGE = 456,
    KW_FONTPITCH = 457,
    KW_FIXED = 458,
    KW_VARIABLE = 459,
    KW_WANTRETURNS = 460,
    KW_WANTNORETURNS = 461,
    KW_WANTTABS = 462,
    KW_AUTOSCALE = 463,
    KW_PIXELWIDTH = 464,
    KW_PIXELHEIGHT = 465,
    KW_BORDER = 466,
    KW_SCROLLBARS_BOTH = 467,
    KW_SCROLLBARS_V = 468,
    KW_SCROLLBARS_H = 469,
    KW_STRETCH_Y = 470,
    KW_STRETCH_BOTH = 471,
    KW_ITEMS = 472,
    KW_VALUEMAX = 473,
    KW_VALUEMIN = 474,
    KW_PROGRESSBAR = 475,
    KW_COMBOBOX = 476,
    OPTIONS = 477,
    KW_BROWSER = 478,
    KW_VALUECHECKED = 479,
    KW_VALUEUNCHECKED = 480,
    KW_CHECKBOX = 481,
    KW_LINEISODD = 482,
    KW_LINEISEVEN = 483
  };
#endif
/* Tokens.  */
#define KW_OR 258
#define KW_AND 259
#define KW_NOT 260
#define IS_NULL 261
#define IS_NOT_NULL 262
#define GREATERTHAN 263
#define LESSTHAN 264
#define KW_MINUS 265
#define KW_PLUS 266
#define KW_DIVIDE 267
#define KW_MULTIPLY 268
#define KW_POWER 269
#define KW_MOD 270
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
#define KW_NOSHOW 448
#define KW_NOHIDEMENU 449
#define KW_TEXTEDIT 450
#define KW_BUTTONEDIT 451
#define KW_LABEL 452
#define KW_EDIT 453
#define KW_DATEEDIT 454
#define KW_SCROLL 455
#define KW_IMAGE 456
#define KW_FONTPITCH 457
#define KW_FIXED 458
#define KW_VARIABLE 459
#define KW_WANTRETURNS 460
#define KW_WANTNORETURNS 461
#define KW_WANTTABS 462
#define KW_AUTOSCALE 463
#define KW_PIXELWIDTH 464
#define KW_PIXELHEIGHT 465
#define KW_BORDER 466
#define KW_SCROLLBARS_BOTH 467
#define KW_SCROLLBARS_V 468
#define KW_SCROLLBARS_H 469
#define KW_STRETCH_Y 470
#define KW_STRETCH_BOTH 471
#define KW_ITEMS 472
#define KW_VALUEMAX 473
#define KW_VALUEMIN 474
#define KW_PROGRESSBAR 475
#define KW_COMBOBOX 476
#define OPTIONS 477
#define KW_BROWSER 478
#define KW_VALUECHECKED 479
#define KW_VALUEUNCHECKED 480
#define KW_CHECKBOX 481
#define KW_LINEISODD 482
#define KW_LINEISEVEN 483

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 83 "screen.yacc" /* yacc.c:355  */

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

#line 670 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE a4gl_form_yylval;

int a4gl_form_yyparse (void);

#endif /* !YY_A4GL_FORM_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 687 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   906

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  229
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  165
/* YYNRULES -- Number of rules.  */
#define YYNRULES  500
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  822

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   483

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   154,   154,   163,   164,   170,   173,   179,   182,   193,
     194,   199,   200,   204,   209,   214,   215,   216,   217,   222,
     226,   233,   243,   252,   265,   273,   283,   291,   304,   305,
     312,   315,   318,   311,   334,   337,   340,   333,   354,   357,
     357,   363,   366,   369,   372,   375,   378,   381,   384,   387,
     388,   392,   393,   394,   398,   407,   413,   423,   430,   432,
     434,   436,   438,   440,   445,   445,   455,   455,   458,   458,
     471,   471,   490,   492,   495,   490,   500,   500,   505,   506,
     507,   519,   520,   525,   526,   529,   544,   556,   557,   568,
     579,   592,   604,   615,   620,   623,   631,   632,   638,   637,
     662,   665,   665,   683,   684,   687,   688,   689,   692,   699,
     700,   703,   704,   705,   707,   708,   709,   715,   719,   719,
     724,   725,   726,   727,   728,   729,   730,   731,   732,   733,
     734,   735,   740,   739,   770,   771,   772,   775,   775,   778,
     782,   778,  1114,  1115,  1121,  1131,  1132,  1135,  1136,  1140,
    1144,  1150,  1161,  1175,  1189,  1198,  1220,  1229,  1241,  1246,
    1252,  1261,  1270,  1277,  1279,  1282,  1288,  1289,  1290,  1291,
    1294,  1295,  1299,  1300,  1304,  1304,  1307,  1312,  1334,  1358,
    1366,  1367,  1368,  1369,  1374,  1379,  1384,  1389,  1390,  1391,
    1392,  1393,  1394,  1395,  1396,  1397,  1402,  1407,  1409,  1411,
    1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,
    1422,  1426,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1472,  1473,  1474,  1475,  1487,
    1488,  1492,  1493,  1494,  1495,  1496,  1497,  1498,  1499,  1501,
    1536,  1537,  1538,  1539,  1540,  1541,  1542,  1546,  1547,  1550,
    1550,  1552,  1552,  1555,  1565,  1571,  1571,  1574,  1575,  1576,
    1580,  1580,  1582,  1582,  1585,  1585,  1587,  1590,  1596,  1599,
    1603,  1604,  1608,  1612,  1616,  1620,  1624,  1631,  1631,  1635,
    1638,  1642,  1642,  1645,  1645,  1649,  1650,  1663,  1675,  1675,
    1688,  1692,  1696,  1700,  1704,  1708,  1712,  1716,  1722,  1726,
    1730,  1734,  1738,  1742,  1746,  1749,  1756,  1756,  1760,  1760,
    1765,  1765,  1765,  1769,  1776,  1777,  1778,  1779,  1786,  1787,
    1790,  1796,  1803,  1804,  1805,  1806,  1812,  1815,  1820,  1823,
    1824,  1831,  1835,  1842,  1850,  1853,  1854,  1855,  1856,  1857,
    1858,  1859,  1867,  1869,  1870,  1873,  1876,  1880,  1881,  1882,
    1883,  1884,  1885,  1886,  1894,  1898,  1907,  1907,  1913,  1919,
    1920,  1923,  1932,  1933,  1934,  1935,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1943,  1944,  1945,  1946,  1949,  1956,  1957,
    1958,  1963,  1966,  1970,  1982,  1985,  1986,  1990,  2000,  2007,
    2016,  2019,  2031,  2034,  2038,  2045,  2053,  2058,  2066,  2070,
    2075,  2080,  2085,  2090,  2095,  2104,  2113,  2114,  2119,  2122,
    2130,  2136,  2142,  2148,  2157,  2162,  2172,  2182,  2188,  2194,
    2200,  2210,  2222,  2230,  2242,  2250,  2251,  2252,  2256,  2257,
    2258,  2259,  2260,  2261,  2262,  2265,  2272,  2283,  2287,  2294,
    2302,  2302,  2320,  2321,  2327,  2333,  2341,  2348,  2349,  2354,
    2355,  2371,  2373,  2374,  2375,  2376,  2377,  2380,  2381,  2382,
    2383,  2384,  2385,  2386,  2387,  2388,  2389,  2390,  2391,  2392,
    2393,  2394,  2395,  2398,  2401,  2402,  2403,  2404,  2405,  2408,
    2412
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_OR", "KW_AND", "KW_NOT", "IS_NULL",
  "IS_NOT_NULL", "GREATERTHAN", "LESSTHAN", "KW_MINUS", "KW_PLUS",
  "KW_DIVIDE", "KW_MULTIPLY", "KW_POWER", "KW_MOD", "CH", "GRAPH_CH",
  "KW_COMPOSITES", "INSTRUCTIONS", "ATTRIBUTES", "DATABASE", "BY",
  "KW_SCREEN_TITLE", "KW_SCREEN", "KW_SIZE", "OPEN_SQUARE", "KW_END",
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
  "KW_HIDDEN", "KW_AUTOSIZE", "KW_NOSHOW", "KW_NOHIDEMENU", "KW_TEXTEDIT",
  "KW_BUTTONEDIT", "KW_LABEL", "KW_EDIT", "KW_DATEEDIT", "KW_SCROLL",
  "KW_IMAGE", "KW_FONTPITCH", "KW_FIXED", "KW_VARIABLE", "KW_WANTRETURNS",
  "KW_WANTNORETURNS", "KW_WANTTABS", "KW_AUTOSCALE", "KW_PIXELWIDTH",
  "KW_PIXELHEIGHT", "KW_BORDER", "KW_SCROLLBARS_BOTH", "KW_SCROLLBARS_V",
  "KW_SCROLLBARS_H", "KW_STRETCH_Y", "KW_STRETCH_BOTH", "KW_ITEMS",
  "KW_VALUEMAX", "KW_VALUEMIN", "KW_PROGRESSBAR", "KW_COMBOBOX", "OPTIONS",
  "KW_BROWSER", "KW_VALUECHECKED", "KW_VALUEUNCHECKED", "KW_CHECKBOX",
  "KW_LINEISODD", "KW_LINEISEVEN", "$accept", "form_def",
  "encoding_section", "database_section", "named_or_kw_st_pc",
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
  "fcall_name", "evalue", "evalue_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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
     475,   476,   477,   478,   479,   480,   481,   482,   483
};
# endif

#define YYPACT_NINF -666

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-666)))

#define YYTABLE_NINF -121

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,   -19,   136,   -11,  -666,  -666,   151,   158,   163,   178,
    -666,   231,   -15,   287,   286,   286,   310,  -666,   280,  -666,
     311,   328,  -666,    55,  -666,   332,  -666,  -666,  -666,  -666,
     337,  -666,   357,  -666,  -666,   286,   369,  -666,  -666,  -666,
     357,   366,  -666,  -666,   370,   615,   352,   291,  -666,   596,
     389,  -666,   397,   232,   382,   384,   386,  -666,  -666,  -666,
    -666,   392,   393,  -666,  -666,    63,   286,   286,  -666,   286,
    -666,   286,  -666,  -666,  -666,  -666,  -666,  -666,   417,   199,
    -666,  -666,   286,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,  -666,  -666,    -8,   292,  -666,    72,
    -666,   432,  -666,   436,   416,   438,   422,   441,   453,  -666,
     370,  -666,  -666,   311,   311,   286,   311,   286,   311,  -666,
     449,   319,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
     476,   431,   444,   443,   255,   208,   334,   334,  -666,   235,
    -666,   452,  -666,   351,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,   615,   615,   311,   615,   311,   327,
     286,   286,   286,   286,   201,   347,   476,  -666,  -666,  -666,
     482,  -666,  -666,  -666,    23,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,   371,  -666,   286,  -666,  -666,  -666,  -666,
    -666,   286,   490,   488,   615,  -666,   491,   493,   494,   495,
     286,   -17,  -666,  -666,  -666,   484,  -666,  -666,  -666,   230,
    -666,  -666,   487,   496,  -666,    34,  -666,   498,  -666,  -666,
     286,   480,   347,  -666,   347,  -666,   489,   501,  -666,  -666,
    -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,   254,  -666,
    -666,   527,  -666,  -666,  -666,  -666,  -666,  -666,  -666,   311,
    -666,  -666,   286,   201,  -666,    54,   492,   347,   375,   526,
     500,   528,   516,  -666,   125,  -666,   125,  -666,  -666,  -666,
      79,  -666,  -666,  -666,   490,   490,   615,  -666,  -666,   518,
     286,   -38,   531,   534,  -666,   556,  -666,  -666,   537,    29,
     519,   375,  -666,   -43,  -666,   292,     0,   445,   138,   347,
    -666,  -666,  -666,  -666,  -666,  -666,   138,  -666,  -666,   138,
     445,  -666,  -666,    98,   292,    79,  -666,  -666,   417,   467,
     478,   547,   285,   536,   696,   541,  -666,   447,   286,   558,
    -666,   347,   557,   548,   552,    62,   532,  -666,   483,  -666,
    -666,   549,    13,   553,     2,  -666,  -666,  -666,   542,   545,
    -666,  -666,   445,   445,   445,   445,  -666,   440,  -666,  -666,
     346,  -666,   550,  -666,    92,  -666,  -666,   554,   544,  -666,
     560,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,   539,   286,   569,  -666,  -666,  -666,  -666,  -666,   570,
     570,   520,   648,   286,  -666,  -666,  -666,  -666,  -666,  -666,
     539,   565,  -666,    16,   564,    40,  -666,    20,    37,   514,
      29,    29,   575,  -666,  -666,   563,   445,  -666,  -666,   581,
     560,   560,   560,   292,   445,   445,   445,   445,   445,   445,
     445,   445,   445,  -666,  -666,   -34,   445,   576,  -666,  -666,
     138,   445,   445,  -666,  -666,   445,    79,    79,   586,   613,
    -666,  -666,   612,   634,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,   591,  -666,   555,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,   591,  -666,   561,   600,   625,  -666,  -666,  -666,
     635,   240,  -666,  -666,  -666,  -666,  -666,  -666,   521,   501,
    -666,  -666,   644,  -666,   560,  -666,  -666,   647,   647,   560,
     560,   560,   560,   560,   560,   560,   445,   621,   624,   169,
     503,   560,   630,  -666,  -666,  -666,  -666,  -666,   642,   160,
     646,  -666,   520,  -666,   648,   649,  -666,   286,   660,   664,
     292,   108,  -666,  -666,   651,   653,   655,   626,   636,  -666,
    -666,   663,   668,  -666,  -666,  -666,   671,   672,  -666,  -666,
    -666,   278,  -666,   674,   676,  -666,   677,   678,   681,   682,
    -666,  -666,  -666,   699,   701,  -666,  -666,  -666,  -666,   702,
     706,  -666,  -666,  -666,  -666,   707,   711,  -666,  -666,  -666,
    -666,  -666,   725,   729,   730,   750,   758,   759,   746,  -666,
    -666,  -666,   747,   560,   169,   445,  -666,   188,   138,  -666,
    -666,  -666,  -666,   779,  -666,   755,  -666,  -666,  -666,  -666,
     760,  -666,  -666,   769,    69,   761,  -666,   772,  -666,   286,
     780,  -666,   751,   776,     9,   286,   286,   777,   788,   778,
     795,  -666,  -666,   796,   798,   799,   800,     1,   819,   286,
     802,   803,   146,   822,   823,   801,   824,   826,     9,   121,
     147,   240,   827,   227,   560,  -666,   169,  -666,   804,  -666,
    -666,   828,  -666,   808,   108,   292,   286,   820,   286,  -666,
    -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,  -666,   654,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,   821,   825,  -666,   193,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,   525,  -666,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,   809,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,   829,  -666,   286,  -666,    -2,  -666,  -666,  -666,   286,
     286,  -666,  -666,  -666,  -666,  -666,   833,   835,   228,  -666,
    -666,    -7,  -666,  -666,  -666,  -666,   229,  -666,  -666,  -666,
     286,  -666,  -666,  -666,  -666,    -2,    -2,  -666,  -666,  -666,
    -666,   289,   414,  -666,  -666,  -666,  -666,  -666,  -666,   193,
     193,   193,  -666,   525,  -666,   812,  -666,    -2,    -2,   -12,
     -12,   -12,   -12,   -12,   793,   -12,   815,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,  -666,
    -666,   -12,   743,   -12,  -666,   -12,  -666,   251,  -666,  -666,
     -12,  -666
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     3,     9,    10,     5,    15,    17,     8,
       1,     0,     0,     0,     0,     0,     0,     4,     0,    68,
      38,   103,    20,    19,    66,     0,    11,    12,    16,    18,
       0,    70,    78,    39,    64,     0,     0,    67,     7,     6,
      78,     0,    69,    72,     0,     0,   109,    81,   105,   120,
     267,    71,    79,    76,     0,     0,     0,    42,    45,    43,
      44,     0,     0,    48,    51,     0,    28,    28,    30,    28,
      34,    28,    58,    59,    60,    61,    62,    63,    81,     0,
     108,    82,     0,   104,   106,   126,   122,   125,   123,   121,
     124,   127,   128,   129,   131,   130,    81,     0,   118,     0,
       2,     0,    77,     0,     0,     0,     0,     0,     0,    40,
       0,    52,    29,    38,    38,    28,    38,    28,    38,    65,
       0,   111,   110,   107,   117,   119,    13,    14,   307,   132,
       0,     0,     0,     0,     0,     0,     0,     0,   412,    81,
     269,   271,   278,     0,   274,   279,    80,    73,    46,    47,
      41,    50,    49,    53,    54,    54,    38,    54,    38,     0,
       0,     0,     0,     0,     0,     0,   404,   405,   275,   273,
       0,   445,   446,   447,     0,   441,   453,   448,   454,   452,
     449,   450,   451,     0,   443,     0,   417,   416,   268,   270,
     272,     0,     0,     0,    55,    56,     0,     0,     0,     0,
      28,     0,    25,   116,   112,   113,   115,   138,   137,     0,
     139,   134,     9,    10,   413,     0,   408,     0,   411,   406,
       0,     0,     0,   442,     0,   444,     0,   284,    96,    89,
      98,    85,    90,    91,    95,    94,    93,    88,     0,    86,
      83,    92,    87,    22,    57,    21,    31,    23,    35,    38,
      24,    26,     0,   133,   135,     0,   282,     0,     0,   286,
       0,     0,     0,   458,   290,   455,   290,   460,   285,   459,
     301,    74,    84,    97,     0,     0,    54,   114,   136,     0,
       0,   147,   155,   142,   283,     0,   409,   410,     0,     0,
       0,     0,   291,     0,   428,     0,     0,     0,     0,     0,
     435,   420,   418,   421,   422,   424,   414,   419,   423,   415,
     462,   305,   306,     0,     0,   302,   303,   100,    81,     0,
       0,     0,     0,   157,     0,     0,   152,   146,     0,     0,
     140,     0,     0,     0,   292,   290,   297,   288,     0,   457,
     437,     0,     0,     0,     0,   432,   430,   495,    13,    14,
     498,   496,     0,     0,     0,     0,   497,     0,   493,   494,
       0,   467,     0,   473,     0,   456,   436,     0,   463,   464,
     466,    99,   101,   308,   304,    75,    32,    36,    27,   300,
     299,   147,     0,   310,   312,   313,   314,   315,   316,   346,
     346,   363,   349,     0,   321,   322,   323,   324,   325,   150,
     147,     0,   154,     0,   172,     0,   287,     0,     0,   280,
       0,     0,     0,   439,   438,     0,     0,   433,   431,     0,
     472,   471,   474,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   470,   469,     0,     0,     0,   488,   489,
       0,     0,   462,   434,   461,     0,   301,   301,     0,     0,
     151,   156,     0,     0,   317,   318,   367,   368,   369,   370,
     371,   372,   374,   319,     0,   365,   355,   356,   357,   358,
     359,   360,   374,   320,     0,   351,   149,   153,   145,   143,
       0,     0,   141,   407,   296,   294,   295,   293,     0,   284,
     289,   298,     0,   440,   429,   475,   477,   480,   479,   487,
     481,   484,   482,   483,   485,   478,     0,     0,     0,     0,
     426,   468,     0,   465,   102,   309,    33,    37,     0,     0,
       0,   373,     0,   361,     0,     0,   354,     0,     0,   196,
     158,     0,   204,   176,     0,     0,     0,     0,     0,   187,
     188,     0,     0,   194,   199,   198,     0,     0,   202,   206,
     205,   209,   203,     0,     0,   197,     0,     0,     0,     0,
     237,   208,   207,     0,     0,   212,   213,   214,   221,     0,
       0,   217,   216,   218,   215,     0,     0,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,     0,   173,   174,
     281,   276,     0,   486,     0,     0,   499,     0,     0,   425,
     476,   311,   347,     0,   353,     0,   364,   366,   362,   350,
       0,   148,   144,     0,     0,   159,   160,     0,   163,     0,
     167,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,   211,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   490,   491,     0,   427,     0,   375,
     352,     0,   170,     0,     0,     0,     0,   169,     0,   259,
     251,   252,   253,   254,   255,   256,   257,   258,   262,   260,
     263,   264,   265,   266,   261,   376,   249,   180,   246,   247,
     245,   248,   181,   185,   183,   189,     0,   200,   201,   242,
     243,   191,   192,   223,   225,   224,   234,   193,   244,   222,
     219,   220,   227,   226,     0,   235,   236,   182,   240,   238,
     241,   239,   175,     0,   492,   500,   348,   195,   171,   179,
     161,   165,   162,     0,   166,     0,   250,   177,   377,     0,
       0,   343,   330,   342,   345,   341,     0,     0,     0,   344,
     326,   338,   335,   334,   337,   333,     0,   336,   328,   277,
       0,   168,   398,   401,   399,     0,     0,   400,   382,   383,
     378,   379,   392,   397,   186,   184,   331,   332,   190,     0,
       0,     0,   233,     0,   164,     0,   395,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   390,   391,   327,
     340,   339,   329,   396,   381,   380,   386,   385,   389,   387,
     384,     0,     0,     0,   388,     0,   402,     0,   393,   394,
       0,   403
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -666,  -666,  -666,  -666,   870,   -14,   559,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,   673,    24,  -666,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,   -44,  -666,    -3,  -666,  -143,  -666,
     -32,  -666,  -666,  -666,   849,  -666,  -666,   836,  -666,  -666,
    -666,  -666,  -666,   -73,   150,  -666,  -209,  -666,  -666,  -666,
    -666,  -666,  -666,  -666,    26,  -666,  -666,  -666,  -666,  -666,
     781,  -666,  -666,  -666,  -166,  -666,  -666,  -666,  -323,  -666,
    -666,  -666,  -666,   210,  -666,  -666,   214,  -666,  -666,  -666,
     233,   234,  -666,   194,  -666,  -666,   741,  -666,  -666,  -666,
    -666,   394,  -666,  -666,   546,   474,   477,  -666,   439,  -666,
     573,   -95,   446,  -666,  -666,  -666,  -666,  -665,   106,   111,
    -354,   504,  -666,  -666,  -666,  -666,   367,  -666,  -666,  -666,
    -666,   373,   421,  -666,  -666,  -666,  -592,  -144,  -666,  -666,
    -666,  -666,   731,   567,   639,   -92,   152,  -666,  -303,  -666,
    -666,  -666,  -666,  -666,  -666,  -132,  -666,  -666,  -666,   726,
     716,   679,   602,  -666,   300,  -666,   460,  -666,   459,  -272,
    -666,  -666,  -666,  -489,   312
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,     3,   214,   358,   128,     9,    21,    72,
      73,    74,    75,   201,   202,   113,    76,   115,   274,   448,
      77,   117,   275,   449,    34,    44,    64,    65,   193,   194,
     195,    22,    45,    23,    24,    32,    40,    42,    53,   192,
     318,   103,    43,    83,   238,   239,   240,   241,   242,   270,
     313,   446,    36,    47,    48,    80,   122,    50,    96,    97,
      98,   164,   209,   210,   211,   255,   404,   330,   326,   327,
     283,   614,   615,   616,   617,   732,   621,   664,   482,   588,
     589,   692,   685,   686,   100,   139,   140,   141,   220,   489,
     285,   269,   260,   335,   299,   336,   337,   381,   314,   315,
     316,   359,   317,   447,   399,   748,   756,   749,   758,   750,
     751,   454,   473,   526,   605,   474,   475,   609,   463,   464,
     606,   465,   521,   737,   738,   770,   771,   772,   773,   817,
     142,   166,   167,   215,   216,   217,   218,   144,   300,   301,
     599,   302,   303,   304,   305,   306,   307,   174,   183,   175,
     184,   264,   265,   145,   308,   310,   367,   368,   369,   370,
     441,   361,   362,   363,   597
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    29,   129,   366,   340,   119,   366,   143,    18,    19,
     250,     4,   196,    78,   198,     5,     6,   762,   763,    81,
     596,    46,  -120,   124,   324,   360,  -120,   762,   763,   272,
     126,   780,   126,    46,   127,   764,   127,    11,   688,   689,
     506,   341,   256,   254,   479,   764,   344,   143,   483,   757,
      26,   765,   112,   112,    27,   112,   690,   112,   450,    26,
     414,   366,   111,    27,   333,   121,   188,    26,    46,   154,
     155,    27,   157,    84,   159,   484,   480,   477,    18,    19,
     419,   420,   421,   422,    26,   138,   703,   278,    27,   279,
     130,   114,   486,   116,   257,   118,   131,   415,   507,   227,
     257,   112,    26,   112,   781,   596,    27,   153,   123,   280,
     272,   272,   197,   325,   199,     1,   409,   109,   757,   443,
     662,   767,   292,   110,   342,   138,   371,   691,   766,   663,
     262,   767,   262,   321,   309,   132,    10,   510,    26,   156,
      85,   158,    27,   372,   494,   704,   203,   204,   205,   206,
     718,   138,   497,   498,   499,   500,   501,   502,   503,   504,
     505,     7,   244,   619,   508,   200,   364,   725,   719,   511,
     345,   226,   417,   785,   786,    20,   720,   138,   705,    54,
     171,   172,   173,   222,   293,   292,   112,    86,    87,    88,
      89,    90,    13,    91,   721,   804,   805,    14,   347,   126,
     343,   346,    15,   127,   281,   276,   259,   262,   138,   741,
     138,   350,    92,    93,   602,    94,   351,   293,    95,    16,
     603,   133,   742,   743,   249,   768,   769,   134,   135,    26,
     293,   311,   312,    27,   593,   744,   136,   137,   277,   207,
     745,   282,   655,   138,    55,   375,   120,   208,   656,   418,
     746,   747,    56,   130,    57,    58,    59,    60,   185,   131,
     294,   295,    81,   296,   297,    26,   323,   298,   207,    27,
     228,   229,    61,    62,    63,   334,   208,   529,    17,   253,
     230,   724,   778,   782,   231,   138,   271,   656,   779,   783,
     530,   185,   531,   294,   295,   657,   296,   297,   132,   232,
     298,   233,   356,   176,   185,   819,   294,   295,   380,   296,
     297,   820,   379,   298,   402,    26,    26,   138,    81,    27,
      27,    26,   126,   654,   532,    27,   127,    31,   496,    25,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   710,
     711,    82,    30,   552,   424,   425,   553,   161,   162,   163,
     554,   555,   556,   557,    33,   177,   178,   179,   451,   180,
     181,   182,    35,   234,   263,    38,   263,   212,   235,   476,
      39,   213,    41,   558,   133,   559,   560,   631,   632,    49,
     134,   135,   426,   485,   487,    52,   334,   334,    79,   136,
     137,   427,   428,   429,   430,     4,   236,   237,    99,     5,
     287,   102,   171,   172,   173,   787,   788,   561,   562,   101,
     431,   563,   789,   790,   319,   320,   800,   801,   104,   564,
     105,   565,   106,   566,   567,   618,   186,   187,   107,   108,
     568,   569,   570,   339,    81,   571,   572,   573,   574,   575,
     576,   263,   577,   578,   579,   580,   581,   582,   583,   584,
     791,   146,   585,   148,   586,   587,   176,   147,   149,   150,
     151,   432,   433,   434,   347,   348,   435,   436,   437,   349,
     438,   439,   152,   228,   229,   165,    54,   350,   792,   160,
     168,   169,   351,   230,   228,   229,   170,   231,   352,   376,
     185,   190,   353,   354,   230,   191,   228,   229,   231,   200,
     377,   221,   232,   611,   233,   243,   230,   620,   245,   440,
     231,   247,   252,   232,   246,   233,   248,   -11,   177,   178,
     179,   224,   180,   181,   182,   232,   -12,   233,   258,   793,
     261,   752,   267,   273,   794,   795,   796,   284,   797,   798,
     268,    55,   288,   289,   742,   753,   291,   290,   322,    56,
     329,    57,    58,    59,    60,   331,   332,   754,   424,   425,
     618,   328,   755,   338,   378,   355,   382,   401,   356,    61,
      62,    63,   746,   747,   400,   406,   234,   403,   407,   424,
     425,   235,   408,   411,   412,   -11,   413,   234,   -12,   416,
     423,   324,   235,   442,   445,   667,   426,   478,   444,   234,
     493,   693,   694,   516,   235,   427,   428,   429,   430,   236,
     237,   357,   452,   453,   481,   707,   488,   426,   492,   509,
     236,   237,   424,   425,   431,   495,   427,   428,   429,   430,
     517,   518,   236,   237,   520,   806,   807,   808,   809,   810,
     620,   812,   731,   525,   734,   431,   456,   457,   458,   459,
     460,   461,   462,   519,   528,   527,   522,   814,   590,   816,
     426,   818,   524,   592,   594,   604,   821,   598,   610,   427,
     428,   429,   430,   669,   600,   432,   433,   434,   612,   613,
     435,   436,   437,   426,   438,   439,   601,   622,   431,   623,
     625,   624,   427,   428,   429,   430,   432,   433,   434,   627,
     626,   435,   436,   437,   628,   438,   439,   629,   630,   761,
     633,   431,   634,   635,   636,   774,   775,   637,   638,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,    85,   639,   784,   640,   641,   432,
     433,   595,   642,   643,   435,   436,   437,   644,   438,   439,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   645,   432,   433,   434,   646,   647,   435,   436,   437,
     669,   438,   439,   735,   466,   467,   468,   469,   470,   471,
     472,    86,    87,    88,    89,    90,   648,    91,    66,    67,
      68,    69,    70,    71,   649,   650,   651,   652,   658,   659,
     394,   395,   396,   397,   660,   661,    92,    93,   666,    94,
     668,   665,    95,   687,   695,   697,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   696,   698,   699,   398,   700,   701,   702,   706,   708,
     709,   712,   713,   715,   714,   716,   723,   727,   726,   728,
     733,   739,   776,   759,   777,   740,   803,   811,   813,   760,
     815,     8,    37,   373,   251,   730,    51,   125,   729,   736,
     189,   410,   717,   591,   722,   491,   515,   490,   374,   802,
     799,   608,   514,   523,   455,   607,   286,   219,   405,   225,
     223,   365,   512,   266,   513,     0,   653
};

static const yytype_int16 yycheck[] =
{
      14,    15,    97,   306,    47,    78,   309,    99,    23,    24,
      27,    30,   155,    45,   157,    34,    35,    29,    30,    27,
     509,    35,    30,    96,    62,   297,    34,    29,    30,   238,
      30,    38,    30,    47,    34,    47,    34,    48,    29,    30,
      74,    84,     8,   209,    28,    47,    46,   139,     8,   714,
      30,    53,    66,    67,    34,    69,    47,    71,   381,    30,
      47,   364,    65,    34,    35,    79,   139,    30,    82,   113,
     114,    34,   116,    47,   118,    55,    60,   400,    23,    24,
     352,   353,   354,   355,    30,    99,    85,   253,    34,    35,
      18,    67,    55,    69,    60,    71,    24,    84,   132,   191,
      60,   115,    30,   117,   111,   594,    34,   110,    82,    55,
     319,   320,   156,   151,   158,    21,    54,    54,   783,    27,
      51,   133,    60,    60,   167,   139,    28,   118,   130,    60,
     222,   133,   224,   276,   266,    63,     0,   440,    30,   115,
     148,   117,    34,    45,   416,   144,   160,   161,   162,   163,
      29,   165,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   180,   194,    55,   436,   182,   298,   656,    47,   441,
     170,   185,   170,   765,   766,   190,    29,   191,   177,   116,
     157,   158,   159,   160,    92,    60,   200,   195,   196,   197,
     198,   199,    41,   201,    47,   787,   788,    39,    29,    30,
     295,   296,    39,    34,   150,   249,   220,   299,   222,    16,
     224,    42,   220,   221,    54,   223,    47,    92,   226,    41,
      60,   149,    29,    30,   200,   227,   228,   155,   156,    30,
      92,   152,   153,    34,   506,    42,   164,   165,   252,    38,
      47,   255,    54,   257,   181,   318,    47,    46,    60,   344,
      57,    58,   189,    18,   191,   192,   193,   194,   166,    24,
     168,   169,    27,   171,   172,    30,   280,   175,    38,    34,
      16,    17,   209,   210,   211,   289,    46,    37,    47,    49,
      26,    54,    54,    54,    30,   299,    32,    60,    60,    60,
      50,   166,    52,   168,   169,   598,   171,   172,    63,    45,
     175,    47,   133,    95,   166,    54,   168,   169,   322,   171,
     172,    60,    27,   175,   328,    30,    30,   331,    27,    34,
      34,    30,    30,   595,    84,    34,    34,    47,   423,    42,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   203,
     204,    60,    42,   113,     8,     9,   116,    38,    39,    40,
     120,   121,   122,   123,    53,   157,   158,   159,   382,   161,
     162,   163,    44,   119,   222,    43,   224,    30,   124,   393,
      43,    34,    25,   143,   149,   145,   146,   109,   110,    20,
     155,   156,    46,   407,   408,    29,   410,   411,    46,   164,
     165,    55,    56,    57,    58,    30,   152,   153,    19,    34,
     258,   179,   157,   158,   159,   126,   127,   177,   178,    22,
      74,   181,     8,     9,   274,   275,   780,   781,    46,   189,
      46,   191,    46,   193,   194,   530,   136,   137,    46,    46,
     200,   201,   202,   291,    27,   205,   206,   207,   208,   209,
     210,   299,   212,   213,   214,   215,   216,   217,   218,   219,
      46,    29,   222,    47,   224,   225,    95,    31,    30,    47,
      29,   125,   126,   127,    29,    30,   130,   131,   132,    34,
     134,   135,    29,    16,    17,     9,   116,    42,    74,    40,
      59,    47,    47,    26,    16,    17,    53,    30,    53,    32,
     166,    49,    57,    58,    26,   154,    16,    17,    30,   182,
      32,    29,    45,   527,    47,    27,    26,   531,    27,   173,
      30,    27,    38,    45,    31,    47,    31,    40,   157,   158,
     159,   160,   161,   162,   163,    45,    40,    47,    40,   125,
      60,    16,    53,    16,   130,   131,   132,    55,   134,   135,
      49,   181,    26,    53,    29,    30,    40,    29,    40,   189,
      26,   191,   192,   193,   194,     9,    29,    42,     8,     9,
     665,    40,    47,    54,    27,   130,    40,   130,   133,   209,
     210,   211,    57,    58,    43,    28,   119,    29,    40,     8,
       9,   124,    40,    61,   111,    53,    47,   119,    53,    46,
     160,    62,   124,    53,    60,   619,    46,    42,    54,   119,
      47,   625,   626,    27,   124,    55,    56,    57,    58,   152,
     153,   176,    53,    53,    60,   639,   112,    46,    53,    53,
     152,   153,     8,     9,    74,    54,    55,    56,    57,    58,
      27,    29,   152,   153,    53,   789,   790,   791,   792,   793,
     664,   795,   666,    53,   668,    74,   136,   137,   138,   139,
     140,   141,   142,    29,    29,    40,   111,   811,   147,   813,
      46,   815,   111,    29,    53,    29,   820,   174,    29,    55,
      56,    57,    58,    29,    54,   125,   126,   127,    28,    25,
     130,   131,   132,    46,   134,   135,    54,    46,    74,    46,
      74,    46,    55,    56,    57,    58,   125,   126,   127,    46,
      74,   130,   131,   132,    46,   134,   135,    46,    46,   733,
      46,    74,    46,    46,    46,   739,   740,    46,    46,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   148,    46,   760,    46,    46,   125,
     126,   127,    46,    46,   130,   131,   132,    46,   134,   135,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    46,   125,   126,   127,    46,    46,   130,   131,   132,
      29,   134,   135,   129,   136,   137,   138,   139,   140,   141,
     142,   195,   196,   197,   198,   199,    46,   201,   183,   184,
     185,   186,   187,   188,    46,    46,    60,    60,    29,    54,
     114,   115,   116,   117,    54,    46,   220,   221,    46,   223,
      40,    60,   226,    47,    47,    47,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    53,    47,    47,   148,    47,    47,    47,    29,    47,
      47,    29,    29,    29,    53,    29,    29,    29,    54,    51,
      40,    40,    29,    54,    29,    40,    54,    74,    53,    40,
     127,     1,    23,   314,   201,   665,    40,    96,   664,   685,
     139,   335,   648,   489,   651,   411,   447,   410,   315,   783,
     779,   524,   446,   472,   390,   522,   257,   166,   331,   183,
     174,   299,   442,   224,   445,    -1,   594
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   230,   232,    30,    34,    35,   180,   233,   236,
       0,    48,   231,    41,    39,    39,    41,    47,    23,    24,
     190,   237,   260,   262,   263,    42,    30,    34,   234,   234,
      42,    47,   264,    53,   253,    44,   281,   263,    43,    43,
     265,    25,   266,   271,   254,   261,   234,   282,   283,    20,
     286,   266,    29,   267,   116,   181,   189,   191,   192,   193,
     194,   209,   210,   211,   255,   256,   183,   184,   185,   186,
     187,   188,   238,   239,   240,   241,   245,   249,   259,    46,
     284,    27,    60,   272,   283,   148,   195,   196,   197,   198,
     199,   201,   220,   221,   223,   226,   287,   288,   289,    19,
     313,    22,   179,   270,    46,    46,    46,    46,    46,    54,
      60,   255,   234,   244,   244,   246,   244,   250,   244,   272,
      47,   234,   285,   283,   272,   289,    30,    34,   235,   330,
      18,    24,    63,   149,   155,   156,   164,   165,   234,   314,
     315,   316,   359,   364,   366,   382,    29,    31,    47,    30,
      47,    29,    29,   255,   253,   253,   244,   253,   244,   253,
      40,    38,    39,    40,   290,     9,   360,   361,    59,    47,
      53,   157,   158,   159,   376,   378,    95,   157,   158,   159,
     161,   162,   163,   377,   379,   166,   383,   383,   272,   315,
      49,   154,   268,   257,   258,   259,   257,   253,   257,   253,
     182,   242,   243,   234,   234,   234,   234,    38,    46,   291,
     292,   293,    30,    34,   233,   362,   363,   364,   365,   361,
     317,    29,   160,   378,   160,   379,   234,   364,    16,    17,
      26,    30,    45,    47,   119,   124,   152,   153,   273,   274,
     275,   276,   277,    27,   259,    27,    31,    27,    31,   244,
      27,   243,    38,    49,   293,   294,     8,    60,    40,   234,
     321,    60,   364,   365,   380,   381,   380,    53,    49,   320,
     278,    32,   275,    16,   247,   251,   253,   234,   293,    35,
      55,   150,   234,   299,    55,   319,   363,   365,    26,    53,
      29,    40,    60,    92,   168,   169,   171,   172,   175,   323,
     367,   368,   370,   371,   372,   373,   374,   375,   383,   374,
     384,   152,   153,   279,   327,   328,   329,   331,   269,   273,
     273,   257,    40,   234,    62,   151,   297,   298,    40,    26,
     296,     9,    29,    35,   234,   322,   324,   325,    54,   365,
      47,    84,   167,   330,    46,   170,   330,    29,    30,    34,
      42,    47,    53,    57,    58,   130,   133,   176,   234,   330,
     388,   390,   391,   392,   374,   381,   367,   385,   386,   387,
     388,    28,    45,   235,   329,   272,    32,    32,    27,    27,
     234,   326,    40,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   114,   115,   116,   117,   148,   333,
      43,   130,   234,    29,   295,   362,    28,    40,    40,    54,
     323,    61,   111,    47,    47,    84,    46,   170,   330,   388,
     388,   388,   388,   160,     8,     9,    46,    55,    56,    57,
      58,    74,   125,   126,   127,   130,   131,   132,   134,   135,
     173,   389,    53,    27,    54,    60,   280,   332,   248,   252,
     297,   234,    53,    53,   340,   340,   136,   137,   138,   139,
     140,   141,   142,   347,   348,   350,   136,   137,   138,   139,
     140,   141,   142,   341,   344,   345,   234,   297,    42,    28,
      60,    60,   307,     8,    55,   234,    55,   234,   112,   318,
     325,   324,    53,    47,   388,    54,   330,   388,   388,   388,
     388,   388,   388,   388,   388,   388,    74,   132,   388,    53,
     367,   388,   385,   387,   331,   327,    27,    27,    29,    29,
      53,   351,   111,   351,   111,    53,   342,    40,    29,    37,
      50,    52,    84,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   113,   116,   120,   121,   122,   123,   143,   145,
     146,   177,   178,   181,   189,   191,   193,   194,   200,   201,
     202,   205,   206,   207,   208,   209,   210,   212,   213,   214,
     215,   216,   217,   218,   219,   222,   224,   225,   308,   309,
     147,   320,    29,   388,    53,   127,   392,   393,   174,   369,
      54,    54,    54,    60,    29,   343,   349,   350,   345,   346,
      29,   234,    28,    25,   300,   301,   302,   303,   330,    55,
     234,   305,    46,    46,    46,    74,    74,    46,    46,    46,
      46,   109,   110,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    60,    60,   393,   388,    54,    60,   367,    29,    54,
      54,    46,    51,    60,   306,    60,    46,   234,    40,    29,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   311,   312,    47,    29,    30,
      47,   118,   310,   234,   234,    47,    53,    47,    47,    47,
      47,    47,    47,    85,   144,   177,    29,   234,    47,    47,
     203,   204,    29,    29,    53,    29,    29,   310,    29,    47,
      29,    47,   309,    29,    54,   392,    54,    29,    51,   305,
     302,   234,   304,    40,   234,   129,   312,   352,   353,    40,
      40,    16,    29,    30,    42,    47,    57,    58,   334,   336,
     338,   339,    16,    30,    42,    47,   335,   336,   337,    54,
      40,   234,    29,    30,    47,    53,   130,   133,   227,   228,
     354,   355,   356,   357,   234,   234,    29,    29,    54,    60,
      38,   111,    54,    60,   234,   355,   355,   126,   127,     8,
       9,    46,    74,   125,   130,   131,   132,   134,   135,   338,
     339,   339,   337,    54,   355,   355,   356,   356,   356,   356,
     356,    74,   356,    53,   356,   127,   356,   358,   356,    54,
      60,   356
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   229,   230,   231,   231,   232,   232,   232,   232,   233,
     233,   234,   234,   235,   235,   236,   236,   236,   236,   237,
     237,   238,   239,   240,   241,   242,   242,   243,   244,   244,
     246,   247,   248,   245,   250,   251,   252,   249,   253,   254,
     253,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   256,   256,   256,   257,   257,   258,   258,   259,   259,
     259,   259,   259,   259,   261,   260,   262,   262,   264,   263,
     265,   263,   267,   268,   269,   266,   270,   270,   271,   271,
     271,   272,   272,   273,   273,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   276,   278,   277,
     279,   280,   279,   281,   281,   282,   282,   282,   283,   284,
     284,   285,   285,   285,   285,   285,   285,   286,   287,   287,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   290,   289,   291,   291,   291,   292,   292,   294,
     295,   293,   296,   296,   296,   297,   297,   298,   298,   298,
     298,   299,   299,   299,   299,   299,   299,   299,   300,   300,
     301,   301,   302,   303,   304,   304,   305,   305,   305,   305,
     306,   306,   307,   307,   308,   308,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   310,   310,   310,   310,   311,
     311,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   313,   313,   314,
     314,   315,   315,   316,   316,   317,   316,   316,   316,   316,
     318,   318,   319,   319,   320,   320,   321,   321,   322,   322,
     323,   323,   324,   324,   324,   324,   324,   325,   325,   326,
     326,   327,   327,   328,   328,   329,   329,   330,   332,   331,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   334,   334,   335,   335,
     336,   336,   336,   337,   337,   337,   337,   337,   338,   338,
     338,   339,   339,   339,   339,   339,   340,   340,   340,   341,
     341,   342,   342,   343,   344,   345,   345,   345,   345,   345,
     345,   345,   346,   347,   347,   348,   349,   350,   350,   350,
     350,   350,   350,   350,   351,   351,   352,   352,   353,   354,
     354,   354,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   356,   356,   356,
     356,   357,   358,   358,   359,   360,   360,   361,   362,   362,
     363,   363,   364,   365,   366,   366,   366,   366,   367,   367,
     367,   367,   367,   367,   367,   368,   369,   369,   370,   371,
     372,   372,   372,   372,   373,   374,   374,   375,   375,   375,
     375,   376,   376,   377,   377,   378,   378,   378,   379,   379,
     379,   379,   379,   379,   379,   380,   380,   381,   381,   382,
     384,   383,   385,   385,   386,   386,   387,   388,   388,   389,
     389,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   391,   392,   392,   392,   392,   392,   393,
     393
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     5,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     5,     5,     5,     5,     1,     2,     5,     0,     1,
       0,     0,     0,    10,     0,     0,     0,    10,     0,     0,
       4,     3,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     1,     2,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     0,     5,     1,     2,     0,     3,
       0,     4,     0,     0,     0,     9,     0,     1,     0,     2,
       4,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     4,
       1,     0,     4,     0,     3,     1,     2,     3,     2,     0,
       2,     1,     3,     3,     5,     3,     3,     3,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     1,     2,     3,     1,     1,     0,
       0,     6,     0,     3,     5,     3,     1,     0,     5,     3,
       2,     4,     2,     4,     3,     1,     4,     2,     0,     1,
       1,     3,     3,     1,     3,     1,     3,     1,     4,     2,
       1,     2,     0,     2,     1,     3,     1,     4,     2,     4,
       3,     3,     3,     3,     5,     3,     5,     1,     1,     3,
       5,     3,     3,     3,     1,     4,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     5,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       2,     1,     2,     2,     1,     0,     9,    12,     1,     1,
       0,     2,     0,     1,     0,     1,     1,     4,     1,     3,
       0,     1,     1,     3,     3,     3,     3,     1,     3,     1,
       1,     0,     1,     1,     2,     1,     1,     1,     0,     4,
       1,     4,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     0,     3,     5,     0,
       3,     0,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     0,     1,     2,     1,
       3,     3,     1,     1,     3,     3,     3,     3,     4,     3,
       2,     2,     1,     5,     5,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     2,     7,     1,     3,
       3,     1,     1,     1,     5,     5,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     0,     2,     1,     4,
       2,     3,     2,     3,     3,     1,     2,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     4,
       0,     6,     0,     1,     1,     3,     1,     1,     3,     1,
       1,     2,     2,     1,     2,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     2,     2,
       5,     5,     6,     1,     1,     1,     1,     1,     1,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (yystate);
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 154 "screen.yacc" /* yacc.c:1646  */
    {
A4GL_check_compiled_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
A4GL_write_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 163 "screen.yacc" /* yacc.c:1646  */
    {the_form.encoding="";}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 164 "screen.yacc" /* yacc.c:1646  */
    {
		the_form.encoding=strdup(A4GL_strip_quotes((yyvsp[0].str)));
	}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 170 "screen.yacc" /* yacc.c:1646  */
    {the_form.dbname=acl_strdup("formonly");
the_form.allowNullInput=1;
}
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 173 "screen.yacc" /* yacc.c:1646  */
    {the_form.dbname=acl_strdup((yyvsp[-3].str));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=0;
}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 179 "screen.yacc" /* yacc.c:1646  */
    {the_form.dbname=("formonly");
the_form.allowNullInput=0;
}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 182 "screen.yacc" /* yacc.c:1646  */
    {the_form.dbname=acl_strdup((yyvsp[0].str));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=1;
}
#line 2535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 193 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));A4GL_make_downshift((yyval.str)); }
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 194 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 2547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 199 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));A4GL_make_downshift((yyval.str)); }
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 200 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 204 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));
 		if (tagCaseInsensitive) {
                		A4GL_make_downshift((yyval.str));
        		}
	}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 209 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 214 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 215 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
#line 2587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 217 "screen.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "screen.yacc" /* yacc.c:1646  */
    {
			the_form.layout=NULL;
			the_form.layout_attrib=NULL;
	}
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 226 "screen.yacc" /* yacc.c:1646  */
    {
			the_form.layout=(yyvsp[0].layout);
	}
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 233 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.layout)=(yyvsp[-1].layout);
			(yyval.layout)->id=strdup((yyvsp[-3].str));
			(yyval.layout)->attrib=(yyvsp[-2].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 243 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.layout)=(yyvsp[-1].layout);
			(yyval.layout)->id=strdup((yyvsp[-3].str));
			(yyval.layout)->attrib=(yyvsp[-2].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_HBOX;
	}
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 252 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.layout)=(yyvsp[-1].layout);
			(yyval.layout)->id=strdup((yyvsp[-3].str));
			(yyval.layout)->attrib=(yyvsp[-2].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_GROUP;
			/* only one item in a group */
			if ( (yyval.layout)->children.children_len!=1) {
				yyerror("A GROUP must contain 1 and only 1 child item");
			}
	}
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 265 "screen.yacc" /* yacc.c:1646  */
    {
		 (yyval.layout)=(yyvsp[-1].layout);
		 (yyval.layout)->id=strdup((yyvsp[-3].str));
		 (yyval.layout)->attrib=(yyvsp[-2].layout_attrib);
	}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 273 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		(yyval.layout)->layout_type=LAYOUT_FOLDER;
		(yyval.layout)->id="NOTSET";
		(yyval.layout)->attrib=0;
		(yyval.layout)->screen_no=-1;
		(yyval.layout)->children.children_val=0;
		(yyval.layout)->children.children_len=0;
		add_child((yyval.layout), (yyvsp[0].layout));
	}
#line 2672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 283 "screen.yacc" /* yacc.c:1646  */
    {
		add_child((yyvsp[-1].layout), (yyvsp[0].layout));
		(yyval.layout)=(yyvsp[-1].layout);
	}
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 291 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.layout)=(yyvsp[-1].layout);
			(yyval.layout)->id=strdup((yyvsp[-3].str));
			(yyval.layout)->attrib=(yyvsp[-2].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_PAGE;
			if ( (yyval.layout)->children.children_len!=1) {
				yyerror("A PAGE must contain 1 and only 1 child item");
			}
	}
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 304 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 305 "screen.yacc" /* yacc.c:1646  */
    {
		{strcpy((yyval.str),(yyvsp[0].str));}
	}
#line 2709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 312 "screen.yacc" /* yacc.c:1646  */
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
#line 2715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 315 "screen.yacc" /* yacc.c:1646  */
    { ignorekw=1; lineno=0; }
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 318 "screen.yacc" /* yacc.c:1646  */
    {ignorekw=0; in_screen_section=0;}
#line 2727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 319 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		(yyval.layout)->layout_type=LAYOUT_GRID;
		(yyval.layout)->id=strdup((yyvsp[-7].str));
		(yyval.layout)->attrib=(yyvsp[-6].layout_attrib);
		(yyval.layout)->screen_no=atol((yyvsp[-8].str));
		(yyval.layout)->children.children_val=0;
		(yyval.layout)->children.children_len=0;
	}
#line 2741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 334 "screen.yacc" /* yacc.c:1646  */
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
#line 2747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 337 "screen.yacc" /* yacc.c:1646  */
    { ignorekw=1; lineno=0; }
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 340 "screen.yacc" /* yacc.c:1646  */
    {ignorekw=0; in_screen_section=0;}
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 341 "screen.yacc" /* yacc.c:1646  */
    {
		//strcpy($<str>$,$<str>2);
		(yyval.layout)=malloc(sizeof(struct s_layout));
		(yyval.layout)->layout_type=LAYOUT_TABLE;
		(yyval.layout)->id=strdup((yyvsp[-7].str));
		(yyval.layout)->attrib=(yyvsp[-6].layout_attrib);
		(yyval.layout)->screen_no=atol((yyvsp[-8].str));
		(yyval.layout)->children.children_val=0;
		(yyval.layout)->children.children_len=0;
	}
#line 2774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 354 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout_attrib)=0;
		}
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 357 "screen.yacc" /* yacc.c:1646  */
    { new_layout_attribs(); }
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 357 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 363 "screen.yacc" /* yacc.c:1646  */
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[0].str));
	}
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 366 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
#line 2812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 369 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_NOSHOW);
	}
#line 2820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 372 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_NOHIDEMENU);
	}
#line 2828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 375 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 378 "screen.yacc" /* yacc.c:1646  */
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[0].str)); 
	}
#line 2844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 381 "screen.yacc" /* yacc.c:1646  */
    {
		add_str_layout_attrib(FA_S_ACTION, (yyvsp[0].str)); 
	}
#line 2852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 384 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_BORDER);
	}
#line 2860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 387 "screen.yacc" /* yacc.c:1646  */
    { add_str_layout_attrib(FA_S_PIXELHEIGHT,(yyvsp[0].str)); }
#line 2866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 388 "screen.yacc" /* yacc.c:1646  */
    { add_str_layout_attrib(FA_S_PIXELWIDTH,(yyvsp[0].str)); }
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 398 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		                (yyval.layout)->layout_type=LAYOUT_NOTSET;
                		(yyval.layout)->id="NOTSET";
                		(yyval.layout)->attrib=0;
                		(yyval.layout)->screen_no=-1;
                		(yyval.layout)->children.children_val=0;
                		(yyval.layout)->children.children_len=0;
		}
#line 2886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 407 "screen.yacc" /* yacc.c:1646  */
    {(yyval.layout)=(yyvsp[0].layout);}
#line 2892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 413 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		(yyval.layout)->layout_type=LAYOUT_NOTSET;
		(yyval.layout)->id="NOTSET";
		(yyval.layout)->attrib=0;
		(yyval.layout)->screen_no=-1;
		(yyval.layout)->children.children_val=0;
		(yyval.layout)->children.children_len=0;
		add_child((yyval.layout), (yyvsp[0].layout));
	}
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 423 "screen.yacc" /* yacc.c:1646  */
    {
		add_child((yyvsp[-1].layout), (yyvsp[0].layout));
		(yyval.layout)=(yyvsp[-1].layout);
	}
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 431 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout); }
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 433 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 435 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 437 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 439 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 441 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 445 "screen.yacc" /* yacc.c:1646  */
    { 
		the_form.layout_attrib=(yyvsp[0].layout_attrib);
	}
#line 2960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 447 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout)=(yyvsp[-1].layout);
	}
#line 2968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 458 "screen.yacc" /* yacc.c:1646  */
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
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 471 "screen.yacc" /* yacc.c:1646  */
    {
	char buff[256];
	char *ptr;
	the_form.snames.snames_len++;the_form.snames.snames_val=
		realloc(the_form.snames.snames_val, 
			(the_form.snames.snames_len)*
				sizeof(struct screen_name));
		sprintf(buff,"%s", (yyvsp[0].str));
		ptr=buff;
		ptr++;
		ptr[strlen(ptr)-1]=0;

		the_form.snames.snames_val[
			the_form.snames.snames_len-1].name =acl_strdup(ptr);

	in_screen_section=1; 
	}
#line 3008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 490 "screen.yacc" /* yacc.c:1646  */
    { lineno=0; scr++; if (scr>1) newscreen=1; }
#line 3014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 492 "screen.yacc" /* yacc.c:1646  */
    { ignorekw=1; lineno=0; }
#line 3020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 495 "screen.yacc" /* yacc.c:1646  */
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
#line 3026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 500 "screen.yacc" /* yacc.c:1646  */
    { extended_graphics=1; }
#line 3032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 507 "screen.yacc" /* yacc.c:1646  */
    {
	int c;
	int l;
	if (A4GL_isyes(acl_getenv("USE_FORM_SIZE"))) {
		c=atoi((yyvsp[0].str));
		l=atoi((yyvsp[-2].str));
        	if (c>the_form.maxcol) the_form.maxcol=c;
        	if (l>the_form.maxline) the_form.maxline=l;
	}
}
#line 3047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 529 "screen.yacc" /* yacc.c:1646  */
    {
	int a;
	static char buff[256];
	strcpy(buff,(yyvsp[0].str));
	if (A4GL_isyes(acl_getenv("SPACESCORE"))) {
		for (a=0;a<strlen(buff);a++) {
			if (buff[a]=='_') buff[a]=' ';
		}
	}
	strcpy((yyval.str),buff);
}
#line 3063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 544 "screen.yacc" /* yacc.c:1646  */
    {
        //printf("%s %d %d %d %d %d %s\n","_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	if (lineno) {
        //A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
        A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth((yyvsp[0].str)),scr,0,(yyvsp[0].str)); /* utf8 */
	colno+=A4GL_wcswidth((yyvsp[0].str));		/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
#line 3080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 556 "screen.yacc" /* yacc.c:1646  */
    { ltab=0; }
#line 3086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 557 "screen.yacc" /* yacc.c:1646  */
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
#line 3102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 568 "screen.yacc" /* yacc.c:1646  */
    {
	char buff[256];
	if (lineno) {
	sprintf(buff,"\n%s",(yyvsp[0].str));
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,(yyvsp[0].str));
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
#line 3118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 579 "screen.yacc" /* yacc.c:1646  */
    {
	char buff[256];
	if (lineno) {
	strcpy(buff,(yyvsp[0].str));
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,(yyvsp[0].str));
	colno+=strlen((yyvsp[0].str));
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
#line 3134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 592 "screen.yacc" /* yacc.c:1646  */
    {
	if (lineno) {
	//A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
	A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth((yyvsp[0].str)),scr,0,(yyvsp[0].str));	/* utf8 */
	colno+=A4GL_wcswidth((yyvsp[0].str));	/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 604 "screen.yacc" /* yacc.c:1646  */
    {
	if (lineno) {
	//A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
	A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth((yyvsp[0].str)),scr,0,(yyvsp[0].str));	/* utf8 */
	colno+=A4GL_wcswidth((yyvsp[0].str));	/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
#line 3166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 615 "screen.yacc" /* yacc.c:1646  */
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
#line 3176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 620 "screen.yacc" /* yacc.c:1646  */
    {colno=0;lineno++;
	ltab=0;
}
#line 3184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 623 "screen.yacc" /* yacc.c:1646  */
    {
	ltab=0;
}
#line 3192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 631 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 3198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 632 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 638 "screen.yacc" /* yacc.c:1646  */
    {
	colno++;
	fstart=colno;
	openwith='[';
}
#line 3214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 645 "screen.yacc" /* yacc.c:1646  */
    {
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field((yyvsp[-1].str),fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field((yyvsp[-1].str),fstart+1,lineno,colno-fstart-1,scr,2,"");

       fstart=-1;

}
#line 3231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 662 "screen.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str),(yyvsp[0].str));
			}
#line 3239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 665 "screen.yacc" /* yacc.c:1646  */
    {
				/* field elements = name x y width screen_no endswith'|' */
				colno++;
				if (colno>the_form.maxcol) the_form.maxcol=colno; 
				if (lineno>the_form.maxline) the_form.maxline=lineno;
				if (openwith=='[')
					A4GL_add_field((yyvsp[-1].str),fstart+1,lineno,colno-fstart-1,scr,1,"");
				else
					A4GL_add_field((yyvsp[-1].str),fstart+1,lineno,colno-fstart-1,scr,0,"");
				fstart=colno;
				openwith='|';
			}
#line 3256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 676 "screen.yacc" /* yacc.c:1646  */
    {
				strcpy((yyval.str),(yyvsp[0].str));
			}
#line 3264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 692 "screen.yacc" /* yacc.c:1646  */
    { 
clr_status();
A4GL_add_table((yyvsp[0].str),(yyvsp[-1].str)); 
err_on_status();
}
#line 3274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 699 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 700 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 3286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 703 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s", (yyvsp[0].str));}
#line 3292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 704 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 3298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 706 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 3304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 707 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 708 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 3316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 724 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Edit");}
#line 3322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 725 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Edit");}
#line 3328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 726 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"TextEdit");}
#line 3334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 727 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Label");}
#line 3340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 728 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"DateEdit");}
#line 3346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 729 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"ButtonEdit");}
#line 3352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 730 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Button");}
#line 3358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 731 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Image");}
#line 3364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 732 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"ProgressBar");}
#line 3370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 733 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"ComboBox");}
#line 3376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 734 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"CheckBox");}
#line 3382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 735 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Browser");}
#line 3388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 740 "screen.yacc" /* yacc.c:1646  */
    {
			if (tagCaseInsensitive) {
				A4GL_make_downshift((yyvsp[0].str));
			}
			strcpy(currftag,(yyvsp[0].str));
			fldno=A4GL_find_field((yyvsp[0].str));
		}
#line 3400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 748 "screen.yacc" /* yacc.c:1646  */
    {
			if (strcmp((yyvsp[-4].str),"Edit")!=0) {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

				if (A4GL_has_str_attribute(fld,FA_S_WIDGET)) {
					yyerror("Field already has a widget");
				} else {
					A4GL_add_str_attr(fld,FA_S_WIDGETTYPE,(yyvsp[-4].str));
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
#line 3424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 778 "screen.yacc" /* yacc.c:1646  */
    { 
	A4GL_init_fld();
}
#line 3432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 782 "screen.yacc" /* yacc.c:1646  */
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
#line 3450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 796 "screen.yacc" /* yacc.c:1646  */
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
	        extern FILE *a4gl_form_yyin;

#ifdef DEBUG
			A4GL_debug("Currpos = %ld\n",ftell(a4gl_form_yyin));
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
#line 3769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1115 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[-1].str));
}
#line 3779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1121 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[-3].str));
	fld->subscripts[1]=atoi((yyvsp[-1].str));
}
#line 3790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1131 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",atoi((yyvsp[-2].str))+256); }
#line 3796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1132 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[0].str)); }
#line 3802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1135 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"0"); dtype_size=0;}
#line 3808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1136 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[0].str),(yyvsp[-2].str),1));
        		dtype_size=A4GL_get_dtype_size();
		}
#line 3817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1140 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[0].str),"",1));
        		dtype_size=A4GL_get_dtype_size();
		}
#line 3826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1144 "screen.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str),(yyvsp[0].str));
			
		}
#line 3835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1150 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup((yyvsp[-1].str));
        fld->datatype=atoi((yyvsp[0].str))&0xff;
	if (atoi((yyvsp[0].str))&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi((yyvsp[0].str))&0xff;
        fld->dtype_size=dtype_size;
}
#line 3851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1161 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	static int xdo=0;
	char buff[256];
	sprintf(buff,"_do_%d",xdo++);
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(buff);
        fld->datatype=atoi((yyvsp[0].str))&0xff;
	if (atoi((yyvsp[0].str))&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi((yyvsp[0].str))&0xff;
        fld->dtype_size=dtype_size;
}
#line 3870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1175 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	static int di=0;
	char buff[256];
	sprintf(buff,"_di_%d",di++);
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(buff);
        fld->datatype=atoi((yyvsp[0].str))&0xff;
	if (atoi((yyvsp[0].str))&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi((yyvsp[0].str))&0xff;
        fld->dtype_size=dtype_size;
}
#line 3889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1189 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup((yyvsp[-2].str)); 
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        fld->dtype_size=A4GL_get_dtype_size();
}
#line 3903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1198 "screen.yacc" /* yacc.c:1646  */
    {
	struct struct_scr_field *fld;
	char *tab;
	fld=A4GL_get_fld();
	tab=fcompile_find_table((yyvsp[0].str));
	if (tab) {
		fld->tabname=strdup(fcompile_find_table((yyvsp[0].str)));
	} else {
		fld->tabname=0;
	}
	fld->colname=acl_strdup((yyvsp[0].str));
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
#line 3929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1220 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup((yyvsp[-2].str)); 
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        fld->dtype_size=A4GL_get_dtype_size();
}
#line 3943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1229 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"",0);
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
#line 3957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1241 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;
	}
#line 3967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1246 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookups)=(yyvsp[0].lookups);
		}
#line 3975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1252 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[0].lookup);
	}
#line 3989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1261 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookups)=(yyvsp[-2].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[0].lookup);
	}
#line 4000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1270 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[-2].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[0].str));
}
#line 4010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1279 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[-2].str),(yyvsp[0].str));
		}
#line 4018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1282 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%s", (yyvsp[0].str));
	}
#line 4026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1288 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s.%s", (yyvsp[-2].str),(yyvsp[0].str));}
#line 4032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1289 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 4038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1290 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"*%s.%s", (yyvsp[-2].str),(yyvsp[0].str));}
#line 4044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1291 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"*%s",(yyvsp[0].str));}
#line 4050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1307 "screen.yacc" /* yacc.c:1646  */
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
#line 4060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1312 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
		if ((yyvsp[0].expr)==0)  {
			int a;
			struct  u_expression *e_true;
  			e_true=create_int_expr(1);
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi((yyvsp[-1].str));
			fld->colours.colours_val[a-1].whereexpr=e_true;
		} else  {
			int a;
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi((yyvsp[-1].str));
			fld->colours.colours_val[a-1].whereexpr=(yyvsp[0].expr);

		}
}
#line 4087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1334 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	   struct s_lookup  *l;
	   struct s_lookups *ls;
           l=malloc(sizeof(struct s_lookup));
           l->fieldtag=strdup("<<FROM>>");
           l->tabcol=strdup((yyvsp[0].str));

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
#line 4116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1358 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[-2].lookups)->joincol=strdup((yyvsp[0].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[-2].lookups);
}
#line 4129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1366 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[0].str)); }
#line 4135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1367 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[0].str)); }
#line 4141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1368 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[0].str)); }
#line 4147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1369 "screen.yacc" /* yacc.c:1646  */
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
#line 4157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1374 "screen.yacc" /* yacc.c:1646  */
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
#line 4167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1379 "screen.yacc" /* yacc.c:1646  */
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
#line 4177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1384 "screen.yacc" /* yacc.c:1646  */
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
#line 4187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1389 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
#line 4193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1390 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
#line 4199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1391 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[0].str)); }
#line 4205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1392 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"\n%s",(yyvsp[-1].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
#line 4211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1393 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[0].str)); }
#line 4217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1394 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[0].str)); }
#line 4223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1395 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[0].str)); }
#line 4229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1396 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
#line 4235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1397 "screen.yacc" /* yacc.c:1646  */
    { A4GL_get_fld()->dynamic=atoi((yyvsp[0].str)); 
#ifdef DEBUG
A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); 
#endif
}
#line 4245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1402 "screen.yacc" /* yacc.c:1646  */
    { A4GL_get_fld()->dynamic=-1; 
#ifdef DEBUG
A4GL_debug("dynamic=-1"); 
#endif
}
#line 4255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1407 "screen.yacc" /* yacc.c:1646  */
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[0].str)); }
#line 4261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1409 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
#line 4267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1411 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
#line 4273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1412 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[0].str)); }
#line 4279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1413 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[0].str)); }
#line 4285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1414 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
#line 4291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1415 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
#line 4297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1416 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
#line 4303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1417 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
#line 4309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1418 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
#line 4315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1419 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
#line 4321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1420 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
#line 4327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1421 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
#line 4333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1422 "screen.yacc" /* yacc.c:1646  */
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
#line 4342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1426 "screen.yacc" /* yacc.c:1646  */
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
#line 4350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1433 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
#line 4356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1434 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOSHOW); }
#line 4362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1435 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOHIDEMENU); }
#line 4368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1436 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
#line 4374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1437 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
#line 4380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1438 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTRETURNS); }
#line 4386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1439 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
#line 4392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1440 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
#line 4398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1441 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
#line 4404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1442 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
#line 4410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1443 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[0].str)); }
#line 4416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1444 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"left"); }
#line 4422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1445 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"right"); }
#line 4428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1446 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"center"); }
#line 4434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1447 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[0].str)); }
#line 4440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1448 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[0].str)); }
#line 4446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1449 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
#line 4452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1450 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
#line 4458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1451 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
#line 4464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1452 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
#line 4470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1453 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
#line 4476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1454 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[-1].str)); }
#line 4482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1455 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,(yyvsp[0].str)); }
#line 4488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1456 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[0].str)); }
#line 4494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1457 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[0].str)); }
#line 4500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1458 "screen.yacc" /* yacc.c:1646  */
    { A4GL_get_fld()->not_null=1;}
#line 4506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1460 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[0].str)); }
#line 4512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1461 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[0].str)); }
#line 4518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1462 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[0].str)); }
#line 4524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1463 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[0].str)); }
#line 4530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1464 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[0].str)); }
#line 4536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1465 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_HEADER,(yyvsp[0].str)); }
#line 4542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1466 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[0].str)); }
#line 4548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1472 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 4554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1473 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 4560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1474 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"\"%s\"",(yyvsp[0].str));}
#line 4566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1475 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"\n%s",(yyvsp[0].str));
	if (strcasecmp((yyvsp[0].str),"current")==0) {
		int a;
		if (((A4GL_get_fld()->datatype)&DTYPE_MASK)==DTYPE_DTIME) {
			a=A4GL_get_fld()->dtype_size;
			sprintf((yyval.str),"\n%s%x",(yyvsp[0].str), a);
		}
	}
}
#line 4580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1488 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",atoi((yyvsp[-1].str))+atoi((yyvsp[0].str))); }
#line 4586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1492 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"0"); }
#line 4592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1493 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"4"); }
#line 4598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1494 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"2"); }
#line 4604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1495 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"6"); }
#line 4610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1496 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"1"); }
#line 4616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1497 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"5"); }
#line 4622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1498 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"7"); }
#line 4628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1499 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"3"); }
#line 4634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1501 "screen.yacc" /* yacc.c:1646  */
    { 
			char *ptr;
			
			ptr=(yyvsp[0].str);
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
#line 4673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1536 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
#line 4679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1537 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
#line 4685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1538 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
#line 4691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1539 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
#line 4697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1540 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
#line 4703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1541 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
#line 4709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1542 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
#line 4715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1555 "screen.yacc" /* yacc.c:1646  */
    {
	char buff[4];
	strcpy(buff,A4GL_char_val((yyvsp[0].str)));
	if (strlen(buff)==1) {
		buff[1]=buff[0];
		buff[2]=buff[0];
		buff[3]=0;
	}
	the_form.delim=acl_strdup(buff);
}
#line 4730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1565 "screen.yacc" /* yacc.c:1646  */
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[0].control_block),sizeof(struct s_control_block));
;
}
#line 4741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1571 "screen.yacc" /* yacc.c:1646  */
    {
A4GL_add_srec();
}
#line 4749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1582 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=0;}
#line 4755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1582 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=1;}
#line 4761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1587 "screen.yacc" /* yacc.c:1646  */
    {
   A4GL_set_dim_srec((yyvsp[0].str),1);
}
#line 4769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1590 "screen.yacc" /* yacc.c:1646  */
    {
   A4GL_set_dim_srec((yyvsp[-3].str),atoi((yyvsp[-1].str)));
}
#line 4777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1596 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%s",(yyvsp[0].str));
}
#line 4785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1599 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str));
}
#line 4793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1609 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute("",(yyvsp[0].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
#line 4801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1613 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute((yyvsp[-2].str),(yyvsp[0].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 4809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1617 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute("formonly",(yyvsp[0].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 4817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1621 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute((yyvsp[-2].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 4825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1625 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 4833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1631 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute("","","THROUGH");}
#line 4839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1635 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),(yyvsp[0].str));
}
#line 4847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1638 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[0].str)); }
#line 4853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1642 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1642 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 4865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1649 "screen.yacc" /* yacc.c:1646  */
    {colno++;}
#line 4871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1650 "screen.yacc" /* yacc.c:1646  */
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
#line 4884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1663 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),(yyvsp[0].str));
/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
	colno+=strlen((yyvsp[0].str));
	}
#line 4898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1675 "screen.yacc" /* yacc.c:1646  */
    {
	colno+=strlen((yyvsp[0].str));
}
#line 4906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1677 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),(yyvsp[-2].str));
	/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
}
#line 4919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1688 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
#line 4928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1692 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"0");
	dtype_size=atol((yyvsp[-1].str));
}
#line 4937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1696 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
#line 4946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1700 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
#line 4955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1704 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
#line 4964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1708 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
#line 4973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1712 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
#line 4982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1716 "screen.yacc" /* yacc.c:1646  */
    {
		int i;
		i=atoi((yyvsp[0].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
#line 4993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1722 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[0].str));
}
#line 5002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1726 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[0].str));
}
#line 5011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1730 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[0].str));
}
#line 5020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1734 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
#line 5029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1738 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
#line 5038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1742 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
#line 5047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1746 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
#line 5055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1749 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
#line 5063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1756 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[-2].str),(yyvsp[0].str));
}
#line 5071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1760 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[-2].str),(yyvsp[0].str));
}
#line 5079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1765 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"-%s",(yyvsp[0].str));}
#line 5085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1769 "screen.yacc" /* yacc.c:1646  */
    { 
		if (strlen((yyvsp[0].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[0].str))); 
		}
	}
#line 5097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1776 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 5103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1777 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1779 "screen.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str),"");
	}
#line 5117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1787 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[-2].str),(yyvsp[0].str)); 
	}
#line 5125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1790 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[-2].str),(yyvsp[0].str)); 
	}
#line 5133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1796 "screen.yacc" /* yacc.c:1646  */
    {
		if (strlen((yyvsp[0].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[0].str)));
		}
	}
#line 5145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1803 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1804 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1805 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1806 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"NULL");}
#line 5169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1812 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"0");
		}
#line 5177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1815 "screen.yacc" /* yacc.c:1646  */
    {
		int n;
		 n=atol(acl_getenv("A4GL_DEFDECPREC"));
		sprintf((yyval.str),"%d",((atoi((yyvsp[-1].str)))<<8)+n);
	}
#line 5187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1820 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%d",(atoi((yyvsp[-3].str))<<8)+atoi((yyvsp[-1].str)));}
#line 5193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1823 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1825 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[-2].str))*16)+atoi((yyvsp[0].str)));
	}
#line 5207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1831 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
#line 5217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1835 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("    %s",(yyvsp[-1].str));
#endif
strcpy((yyval.str),(yyvsp[-1].str));
}
#line 5228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1842 "screen.yacc" /* yacc.c:1646  */
    {
if (atoi((yyvsp[0].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
#line 5239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1850 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%d",atoi((yyvsp[0].str))*16+atoi((yyvsp[-1].str)));}
#line 5245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1853 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"1");}
#line 5251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1854 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"2");}
#line 5257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1855 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"3");}
#line 5263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1856 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"4");}
#line 5269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1857 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"5");}
#line 5275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1858 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"6");}
#line 5281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1860 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
  A4GL_debug("opt_frac returns %s",(yyvsp[0].str));
#endif
  sprintf((yyval.str),"%d",atoi((yyvsp[0].str))+6); }
#line 5291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1869 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1870 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%d",atoi((yyvsp[-2].str))*16+atoi((yyvsp[0].str)));}
#line 5303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1873 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1876 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1880 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"1");}
#line 5321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1881 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"2");}
#line 5327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1882 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"3");}
#line 5333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1883 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"4");}
#line 5339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1884 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"5");}
#line 5345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1885 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"6");}
#line 5351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1887 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("opt_frac returns %s",(yyvsp[0].str));
#endif
sprintf((yyval.str),"%d",atoi((yyvsp[0].str))+6); }
#line 5361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1894 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
#line 5371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1898 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[-1].str));
#endif
strcpy((yyval.str),(yyvsp[-1].str));
}
#line 5383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1907 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=0;}
#line 5389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1907 "screen.yacc" /* yacc.c:1646  */
    {
(yyval.expr)=(yyvsp[0].expr);
}
#line 5397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1913 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=(yyvsp[0].expr);
	}
#line 5405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1920 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),"AND");  
	}
#line 5413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1923 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),"OR");  
	}
#line 5421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1932 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_oddline();}
#line 5427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1933 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_evenline(); }
#line 5433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1934 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1935 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1936 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1937 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1938 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-3].expr),(yyvsp[0].expr),"NOTLIKE"); }
#line 5463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1939 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1940 "screen.yacc" /* yacc.c:1646  */
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNULL"); }
#line 5475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1941 "screen.yacc" /* yacc.c:1646  */
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNOTNULL"); }
#line 5481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1942 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].expr); }
#line 5487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1943 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[-2].expr)); add_list_expr((yyval.expr),(yyvsp[0].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyval.expr),"BETWEEN"); }
#line 5493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1944 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyvsp[-1].expr),"IN"); }
#line 5499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1945 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_not_expr((yyvsp[0].expr)); }
#line 5505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1946 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[-1].expr); }
#line 5511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1949 "screen.yacc" /* yacc.c:1646  */
    {
(yyval.expr)=create_field_expr((yyvsp[0].str));
if (strcasecmp(currftag,(yyvsp[0].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
#line 5523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1956 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=create_int_expr(atoi((yyvsp[0].str))); printf("NUMBER VALUE : %s\n",(yyvsp[0].str)); }
#line 5529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1957 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=create_char_expr((yyvsp[0].str));}
#line 5535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1958 "screen.yacc" /* yacc.c:1646  */
    {
	(yyval.expr)=create_special_expr((yyvsp[0].str));
}
#line 5543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1966 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[0].expr));
	}
#line 5552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1970 "screen.yacc" /* yacc.c:1646  */
    {
		add_list_expr((yyvsp[-2].expr),(yyvsp[0].expr));
		(yyval.expr)=(yyvsp[-2].expr);
	}
#line 5561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1990 "screen.yacc" /* yacc.c:1646  */
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[-5].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[-1].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[-3].intval);
	}
#line 5574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2000 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[0].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[0].column).colname;
	}
#line 5586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2007 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.col_list)=(yyvsp[-2].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[0].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[0].column).colname;
	}
#line 5598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2016 "screen.yacc" /* yacc.c:1646  */
    {
	(yyval.column).tabname=strdup((yyvsp[-2].str));
	(yyval.column).colname=strdup((yyvsp[0].str));
}
#line 5607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2019 "screen.yacc" /* yacc.c:1646  */
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[0].str),"",0);
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[0].str));
}
#line 5621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2038 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[-3].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[-1].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[0].at_block);
	}
#line 5633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2045 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[-3].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[-1].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[0].at_block);

	}
#line 5646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2053 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[0].fcall);
	}
#line 5656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2058 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[0].fcall);
	}
#line 5666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2066 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
#line 5675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2070 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[0].at_comments);
	}
#line 5685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2075 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[0].at_if);
	}
#line 5695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2080 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[0].at_let);
	}
#line 5705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2085 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[0].at_nextfield);
	}
#line 5715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2090 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[0].fcall);
	}
#line 5725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2095 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[0].at_block);

	}
#line 5736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2104 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[-3].expr);
		(yyval.at_if)->if_true=(yyvsp[-1].at_action);
		(yyval.at_if)->if_false=(yyvsp[0].at_action);
	}
#line 5747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2113 "screen.yacc" /* yacc.c:1646  */
    {(yyval.at_action)=0;}
#line 5753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2114 "screen.yacc" /* yacc.c:1646  */
    {	
		(yyval.at_action)=(yyvsp[0].at_action);
	}
#line 5761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2123 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[-2].str));
			(yyval.at_let)->value=(yyvsp[0].expr);
		}
#line 5771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2131 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[0].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
#line 5781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2137 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[0].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
#line 5791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2143 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
#line 5801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2149 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
#line 5811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2157 "screen.yacc" /* yacc.c:1646  */
    {
		 (yyval.at_block)= (yyvsp[-1].at_block);
	}
#line 5819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2162 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[0].at_action);

	}
#line 5834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2172 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_block)=(yyvsp[-1].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[0].at_action);
		}
#line 5845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2182 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[0].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
#line 5856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2188 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[0].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
#line 5867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2194 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[0].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
#line 5878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2200 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[0].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
#line 5889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2210 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.befact)=malloc(sizeof(struct s_bef_aft));
		(yyval.befact)->cmds=0;
		(yyval.befact)->column_list=0;
		(yyval.befact)->befaftlist.befaftlist_len=0;
		(yyval.befact)->befaftlist.befaftlist_val=0;		

		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[0].intval);

	}
#line 5906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2222 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[0].intval);
	}
#line 5916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2230 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.befact)=malloc(sizeof(struct s_bef_aft));
		(yyval.befact)->cmds=0;
		(yyval.befact)->column_list=0;
		(yyval.befact)->befaftlist.befaftlist_len=0;
		(yyval.befact)->befaftlist.befaftlist_val=0;		

		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[0].intval);

	}
#line 5933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2242 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[0].intval);
	}
#line 5943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2250 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_EDITADD;}
#line 5949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2251 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_EDITUPDATE;}
#line 5955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2252 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_REMOVE;}
#line 5961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2256 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_EDITADD;}
#line 5967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2257 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_ADD;}
#line 5973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2258 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_UPDATE;}
#line 5979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2259 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_QUERY;}
#line 5985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2260 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_REMOVE;}
#line 5991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2261 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_DISPLAY;}
#line 5997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2262 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_EDITUPDATE;}
#line 6003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2265 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[0].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[0].column).colname;
	}
#line 6015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2272 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.col_list)=(yyvsp[-2].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[0].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[0].column).colname;
	}
#line 6027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2283 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.column).tabname=strdup((yyvsp[-2].str));
		(yyval.column).colname=strdup((yyvsp[0].str));
	}
#line 6036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2287 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[0].str));
	}
#line 6045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2294 "screen.yacc" /* yacc.c:1646  */
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[-3].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[-1].str));
	}
#line 6056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2302 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[-1].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
#line 6068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2308 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.fcall)=(yyvsp[-2].fcall);
		if ((yyvsp[-1].el)) {
			listitem *l;
			(yyval.fcall)->list_parameters.list_parameters_len=(yyvsp[-1].el)->nlist;
			l=(yyvsp[-1].el)->expr_list;
			(yyval.fcall)->list_parameters.list_parameters_val=l;
		}
	}
#line 6082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2320 "screen.yacc" /* yacc.c:1646  */
    {(yyval.el)=0;}
#line 6088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2321 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.el)=(yyvsp[0].el);
	}
#line 6096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2327 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[0].expr);
	}
#line 6107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2333 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.el)=(yyvsp[-2].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[0].expr);
	}
#line 6118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2341 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=(yyvsp[0].expr);
	}
#line 6126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2349 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str));}
#line 6132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2354 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"AND");}
#line 6138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2355 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"OR");}
#line 6144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 2371 "screen.yacc" /* yacc.c:1646  */
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[0].expr),"-"); }
#line 6150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2373 "screen.yacc" /* yacc.c:1646  */
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[0].expr),"+"); }
#line 6156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2374 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].expr); }
#line 6162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2375 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_not_expr((yyvsp[0].expr)); }
#line 6168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 2376 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[-1].expr); }
#line 6174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 2377 "screen.yacc" /* yacc.c:1646  */
    { 
			(yyval.expr)=create_fcall((yyvsp[-3].str),(yyvsp[-1].el));
	}
#line 6182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 2380 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_field_expr((yyvsp[0].str)); }
#line 6188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 2381 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 2382 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2383 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2384 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 2385 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 2386 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 2387 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 2388 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 2389 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-3].expr),(yyvsp[0].expr),"NOTLIKE"); }
#line 6242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 2390 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 2391 "screen.yacc" /* yacc.c:1646  */
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNULL"); }
#line 6254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 2392 "screen.yacc" /* yacc.c:1646  */
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNOTNULL"); }
#line 6260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 2393 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[-2].expr)); add_list_expr((yyval.expr),(yyvsp[0].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyval.expr),"BETWEEN"); }
#line 6266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 2394 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyvsp[-1].expr),"IN"); }
#line 6272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 2395 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-5].expr),(yyvsp[-1].expr),"NOTIN"); }
#line 6278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 2401 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_field_expr((yyvsp[0].str)); }
#line 6284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 2402 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=create_int_expr(atoi((yyvsp[0].str))); }
#line 6290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 2403 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=create_char_expr((yyvsp[0].str));}
#line 6296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 2404 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_special_expr((yyvsp[0].str)); }
#line 6302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 2405 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_special_expr((yyvsp[0].str));}
#line 6308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 2408 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[0].expr));
	}
#line 6317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 2412 "screen.yacc" /* yacc.c:1646  */
    {
		add_list_expr((yyvsp[-2].expr),(yyvsp[0].expr));
		(yyval.expr)=(yyvsp[-2].expr);
	}
#line 6326 "y.tab.c" /* yacc.c:1646  */
    break;


#line 6330 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 2424 "screen.yacc" /* yacc.c:1906  */



#include "lex.a4gl_form_yy.c"



/* =========================== EOF ============================ */



