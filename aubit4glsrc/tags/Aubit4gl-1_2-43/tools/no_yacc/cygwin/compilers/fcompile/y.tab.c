/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

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
    KW_TEXTEDIT = 449,
    KW_BUTTONEDIT = 450,
    KW_LABEL = 451,
    KW_EDIT = 452,
    KW_DATEEDIT = 453,
    KW_SCROLL = 454,
    KW_IMAGE = 455,
    KW_FONTPITCH = 456,
    KW_FIXED = 457,
    KW_VARIABLE = 458,
    KW_WANTRETURNS = 459,
    KW_WANTNORETURNS = 460,
    KW_WANTTABS = 461,
    KW_AUTOSCALE = 462,
    KW_PIXELWIDTH = 463,
    KW_PIXELHEIGHT = 464,
    KW_BORDER = 465,
    KW_SCROLLBARS_BOTH = 466,
    KW_SCROLLBARS_V = 467,
    KW_SCROLLBARS_H = 468,
    KW_STRETCH_Y = 469,
    KW_STRETCH_BOTH = 470,
    KW_ITEMS = 471,
    KW_VALUEMAX = 472,
    KW_VALUEMIN = 473,
    KW_PROGRESSBAR = 474,
    KW_COMBOBOX = 475,
    OPTIONS = 476,
    KW_BROWSER = 477,
    KW_VALUECHECKED = 478,
    KW_VALUEUNCHECKED = 479,
    KW_CHECKBOX = 480,
    KW_LINEISODD = 481,
    KW_LINEISEVEN = 482
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
#define KW_TEXTEDIT 449
#define KW_BUTTONEDIT 450
#define KW_LABEL 451
#define KW_EDIT 452
#define KW_DATEEDIT 453
#define KW_SCROLL 454
#define KW_IMAGE 455
#define KW_FONTPITCH 456
#define KW_FIXED 457
#define KW_VARIABLE 458
#define KW_WANTRETURNS 459
#define KW_WANTNORETURNS 460
#define KW_WANTTABS 461
#define KW_AUTOSCALE 462
#define KW_PIXELWIDTH 463
#define KW_PIXELHEIGHT 464
#define KW_BORDER 465
#define KW_SCROLLBARS_BOTH 466
#define KW_SCROLLBARS_V 467
#define KW_SCROLLBARS_H 468
#define KW_STRETCH_Y 469
#define KW_STRETCH_BOTH 470
#define KW_ITEMS 471
#define KW_VALUEMAX 472
#define KW_VALUEMIN 473
#define KW_PROGRESSBAR 474
#define KW_COMBOBOX 475
#define OPTIONS 476
#define KW_BROWSER 477
#define KW_VALUECHECKED 478
#define KW_VALUEUNCHECKED 479
#define KW_CHECKBOX 480
#define KW_LINEISODD 481
#define KW_LINEISEVEN 482

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
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

#line 668 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE a4gl_form_yylval;

int a4gl_form_yyparse (void);

#endif /* !YY_A4GL_FORM_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 683 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   902

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  228
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  165
/* YYNRULES -- Number of rules.  */
#define YYNRULES  498
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  820

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   482

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
     225,   226,   227
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   154,   154,   163,   164,   170,   173,   179,   182,   193,
     194,   199,   200,   204,   209,   214,   215,   216,   217,   222,
     226,   233,   243,   252,   265,   273,   283,   291,   304,   305,
     312,   315,   318,   311,   334,   337,   340,   333,   354,   357,
     357,   363,   366,   369,   372,   375,   378,   381,   384,   385,
     389,   390,   391,   395,   404,   410,   420,   427,   429,   431,
     433,   435,   437,   442,   442,   452,   452,   455,   455,   468,
     468,   487,   489,   492,   487,   497,   497,   502,   503,   504,
     516,   517,   522,   523,   526,   541,   553,   554,   565,   576,
     589,   601,   612,   617,   620,   628,   629,   635,   634,   659,
     662,   662,   680,   681,   684,   685,   686,   689,   696,   697,
     700,   701,   702,   704,   705,   706,   712,   716,   716,   721,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   737,   736,   767,   768,   769,   772,   772,   775,   779,
     775,  1111,  1112,  1118,  1128,  1129,  1132,  1133,  1137,  1141,
    1147,  1158,  1172,  1186,  1195,  1217,  1226,  1238,  1243,  1249,
    1258,  1267,  1274,  1276,  1279,  1285,  1286,  1287,  1288,  1291,
    1292,  1296,  1297,  1301,  1301,  1304,  1309,  1331,  1355,  1363,
    1364,  1365,  1366,  1371,  1376,  1381,  1386,  1387,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1399,  1404,  1406,  1408,  1409,
    1410,  1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,
    1423,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,
    1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1454,  1456,  1457,  1458,  1459,
    1460,  1461,  1462,  1468,  1469,  1470,  1471,  1483,  1484,  1488,
    1489,  1490,  1491,  1492,  1493,  1494,  1495,  1497,  1532,  1533,
    1534,  1535,  1536,  1537,  1538,  1542,  1543,  1546,  1546,  1548,
    1548,  1551,  1561,  1567,  1567,  1570,  1571,  1572,  1576,  1576,
    1578,  1578,  1581,  1581,  1583,  1586,  1592,  1595,  1599,  1600,
    1604,  1608,  1612,  1616,  1620,  1627,  1627,  1631,  1634,  1638,
    1638,  1641,  1641,  1645,  1646,  1659,  1671,  1671,  1684,  1688,
    1692,  1696,  1700,  1704,  1708,  1712,  1718,  1722,  1726,  1730,
    1734,  1738,  1742,  1745,  1752,  1752,  1756,  1756,  1761,  1761,
    1761,  1765,  1772,  1773,  1774,  1775,  1782,  1783,  1786,  1792,
    1799,  1800,  1801,  1802,  1808,  1811,  1816,  1819,  1820,  1827,
    1831,  1838,  1846,  1849,  1850,  1851,  1852,  1853,  1854,  1855,
    1863,  1865,  1866,  1869,  1872,  1876,  1877,  1878,  1879,  1880,
    1881,  1882,  1890,  1894,  1903,  1903,  1909,  1915,  1916,  1919,
    1928,  1929,  1930,  1931,  1932,  1933,  1934,  1935,  1936,  1937,
    1938,  1939,  1940,  1941,  1942,  1945,  1952,  1953,  1954,  1959,
    1962,  1966,  1978,  1981,  1982,  1986,  1996,  2003,  2012,  2015,
    2027,  2030,  2034,  2041,  2049,  2054,  2062,  2066,  2071,  2076,
    2081,  2086,  2091,  2100,  2109,  2110,  2115,  2118,  2126,  2132,
    2138,  2144,  2153,  2158,  2168,  2178,  2184,  2190,  2196,  2206,
    2218,  2226,  2238,  2246,  2247,  2248,  2252,  2253,  2254,  2255,
    2256,  2257,  2258,  2261,  2268,  2279,  2283,  2290,  2298,  2298,
    2316,  2317,  2323,  2329,  2337,  2344,  2345,  2350,  2351,  2367,
    2369,  2370,  2371,  2372,  2373,  2376,  2377,  2378,  2379,  2380,
    2381,  2382,  2383,  2384,  2385,  2386,  2387,  2388,  2389,  2390,
    2391,  2394,  2397,  2398,  2399,  2400,  2401,  2404,  2408
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
  "KW_HIDDEN", "KW_AUTOSIZE", "KW_NOSHOW", "KW_TEXTEDIT", "KW_BUTTONEDIT",
  "KW_LABEL", "KW_EDIT", "KW_DATEEDIT", "KW_SCROLL", "KW_IMAGE",
  "KW_FONTPITCH", "KW_FIXED", "KW_VARIABLE", "KW_WANTRETURNS",
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
     475,   476,   477,   478,   479,   480,   481,   482
};
# endif

#define YYPACT_NINF -693

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-693)))

#define YYTABLE_NINF -120

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      34,   -18,    70,    27,  -693,  -693,    65,    77,    88,    98,
    -693,   114,   -16,    99,   190,   190,   127,  -693,   148,  -693,
     145,   203,  -693,   327,  -693,   191,  -693,  -693,  -693,  -693,
     256,  -693,   243,  -693,  -693,   190,   262,  -693,  -693,  -693,
     243,   282,  -693,  -693,   490,   369,   246,   176,  -693,   494,
     301,  -693,   300,   146,   322,   330,   337,  -693,  -693,  -693,
     357,   359,  -693,  -693,   294,   190,   190,  -693,   190,  -693,
     190,  -693,  -693,  -693,  -693,  -693,  -693,   380,   228,  -693,
    -693,   190,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,    -4,   263,  -693,   154,  -693,
     382,  -693,   378,   371,   397,   384,   400,   420,  -693,   490,
    -693,  -693,   145,   145,   190,   145,   190,   145,  -693,   419,
     348,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,   461,
     402,   424,   423,   240,   609,   306,   306,  -693,   345,  -693,
     428,  -693,   326,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,   369,   369,   145,   369,   145,   299,   190,
     190,   190,   190,    94,   319,   461,  -693,  -693,  -693,   455,
    -693,  -693,  -693,   255,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,   579,  -693,   190,  -693,  -693,  -693,  -693,  -693,
     190,   452,   478,   369,  -693,   481,   484,   491,   486,   190,
     -22,  -693,  -693,  -693,   454,  -693,  -693,  -693,   231,  -693,
    -693,   485,   488,  -693,    23,  -693,   489,  -693,  -693,   190,
     464,   319,  -693,   319,  -693,   477,   482,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,    78,  -693,  -693,
     520,  -693,  -693,  -693,  -693,  -693,  -693,  -693,   145,  -693,
    -693,   190,    94,  -693,    14,   492,   319,   343,   514,   493,
     519,   509,  -693,   366,  -693,   366,  -693,  -693,  -693,   249,
    -693,  -693,  -693,   452,   452,   369,  -693,  -693,   510,   190,
     -52,   522,   540,  -693,   561,  -693,  -693,   543,   336,   521,
     343,  -693,    12,  -693,   263,    -5,    56,   414,   319,  -693,
    -693,  -693,  -693,  -693,  -693,   414,  -693,  -693,   414,    56,
    -693,  -693,   200,   263,   249,  -693,  -693,   380,   270,   374,
     546,   192,   534,   661,   535,  -693,   447,   190,   552,  -693,
     319,   556,   547,   548,   194,   532,  -693,   483,  -693,  -693,
     551,    -7,   555,     5,  -693,  -693,  -693,   558,   567,  -693,
    -693,    56,    56,    56,    56,  -693,   448,  -693,  -693,   125,
    -693,   571,  -693,    95,  -693,  -693,   572,   565,  -693,   433,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
     569,   190,   574,  -693,  -693,  -693,  -693,  -693,   576,   576,
     610,   643,   190,  -693,  -693,  -693,  -693,  -693,  -693,   569,
     590,  -693,   107,   581,    28,  -693,    42,    87,   526,   336,
     336,   592,  -693,  -693,   587,    56,  -693,  -693,   465,   433,
     433,   433,   263,    56,    56,    56,    56,    56,    56,    56,
      56,    56,  -693,  -693,    -6,    56,   593,  -693,  -693,   414,
      56,    56,  -693,  -693,    56,   249,   249,   620,   622,  -693,
    -693,   639,   640,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,   598,  -693,   559,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,   598,  -693,   562,   619,   636,  -693,  -693,  -693,   648,
     239,  -693,  -693,  -693,  -693,  -693,  -693,   531,   482,  -693,
    -693,   651,  -693,   433,  -693,  -693,   629,   629,   433,   433,
     433,   433,   433,   433,   433,    56,   642,   487,    16,   523,
     433,   647,  -693,  -693,  -693,  -693,  -693,   652,   218,   664,
    -693,   610,  -693,   643,   667,  -693,   190,   674,   680,   263,
     174,  -693,  -693,   662,   663,   665,   638,   641,  -693,  -693,
     672,   675,  -693,  -693,  -693,   676,   699,  -693,  -693,  -693,
     271,  -693,   707,   711,  -693,   712,   716,   719,   723,  -693,
    -693,  -693,   727,   728,  -693,  -693,  -693,   740,   741,  -693,
    -693,  -693,  -693,   742,   759,  -693,  -693,  -693,  -693,  -693,
     760,   761,   762,   764,   765,   766,   650,  -693,  -693,  -693,
     660,   433,    16,    56,  -693,   225,   414,  -693,  -693,  -693,
    -693,   784,  -693,   767,  -693,  -693,  -693,  -693,   768,  -693,
    -693,   769,     6,   754,  -693,   770,  -693,   190,   779,  -693,
     714,   773,    13,   190,   190,   776,   771,   785,   786,  -693,
    -693,   787,   789,   790,   791,   -57,   810,   190,   793,   794,
     222,   813,   814,   795,   815,   821,    13,    72,   206,   239,
     823,   241,   433,  -693,    16,  -693,   799,  -693,  -693,   825,
    -693,   804,   174,   263,   190,   817,   190,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,   578,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,   818,   819,  -693,   586,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,   788,  -693,  -693,  -693,  -693,  -693,  -693,  -693,
    -693,   806,  -693,  -693,  -693,  -693,  -693,  -693,  -693,   822,
    -693,   190,  -693,   -15,  -693,  -693,  -693,   190,   190,  -693,
    -693,  -693,  -693,  -693,   832,   834,   252,  -693,  -693,   -19,
    -693,  -693,  -693,  -693,   254,  -693,  -693,  -693,   190,  -693,
    -693,  -693,  -693,   -15,   -15,  -693,  -693,  -693,  -693,   307,
     505,  -693,  -693,  -693,  -693,  -693,  -693,   586,   586,   586,
    -693,   788,  -693,   811,  -693,   -15,   -15,    44,    44,    44,
      44,    44,   792,    44,   816,  -693,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,  -693,    44,
     737,    44,  -693,    44,  -693,   304,  -693,  -693,    44,  -693
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     3,     9,    10,     5,    15,    17,     8,
       1,     0,     0,     0,     0,     0,     0,     4,     0,    67,
      38,   102,    20,    19,    65,     0,    11,    12,    16,    18,
       0,    69,    77,    39,    63,     0,     0,    66,     7,     6,
      77,     0,    68,    71,     0,     0,   108,    80,   104,   119,
     265,    70,    78,    75,     0,     0,     0,    42,    44,    43,
       0,     0,    47,    50,     0,    28,    28,    30,    28,    34,
      28,    57,    58,    59,    60,    61,    62,    80,     0,   107,
      81,     0,   103,   105,   125,   121,   124,   122,   120,   123,
     126,   127,   128,   130,   129,    80,     0,   117,     0,     2,
       0,    76,     0,     0,     0,     0,     0,     0,    40,     0,
      51,    29,    38,    38,    28,    38,    28,    38,    64,     0,
     110,   109,   106,   116,   118,    13,    14,   305,   131,     0,
       0,     0,     0,     0,     0,     0,     0,   410,    80,   267,
     269,   276,     0,   272,   277,    79,    72,    45,    46,    41,
      49,    48,    52,    53,    53,    38,    53,    38,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   273,   271,     0,
     443,   444,   445,     0,   439,   451,   446,   452,   450,   447,
     448,   449,     0,   441,     0,   415,   414,   266,   268,   270,
       0,     0,     0,    54,    55,     0,     0,     0,     0,    28,
       0,    25,   115,   111,   112,   114,   137,   136,     0,   138,
     133,     9,    10,   411,     0,   406,     0,   409,   404,     0,
       0,     0,   440,     0,   442,     0,   282,    95,    88,    97,
      84,    89,    90,    94,    93,    92,    87,     0,    85,    82,
      91,    86,    22,    56,    21,    31,    23,    35,    38,    24,
      26,     0,   132,   134,     0,   280,     0,     0,   284,     0,
       0,     0,   456,   288,   453,   288,   458,   283,   457,   299,
      73,    83,    96,     0,     0,    53,   113,   135,     0,     0,
     146,   154,   141,   281,     0,   407,   408,     0,     0,     0,
       0,   289,     0,   426,     0,     0,     0,     0,     0,   433,
     418,   416,   419,   420,   422,   412,   417,   421,   413,   460,
     303,   304,     0,     0,   300,   301,    99,    80,     0,     0,
       0,     0,   156,     0,     0,   151,   145,     0,     0,   139,
       0,     0,     0,   290,   288,   295,   286,     0,   455,   435,
       0,     0,     0,     0,   430,   428,   493,    13,    14,   496,
     494,     0,     0,     0,     0,   495,     0,   491,   492,     0,
     465,     0,   471,     0,   454,   434,     0,   461,   462,   464,
      98,   100,   306,   302,    74,    32,    36,    27,   298,   297,
     146,     0,   308,   310,   311,   312,   313,   314,   344,   344,
     361,   347,     0,   319,   320,   321,   322,   323,   149,   146,
       0,   153,     0,   171,     0,   285,     0,     0,   278,     0,
       0,     0,   437,   436,     0,     0,   431,   429,     0,   470,
     469,   472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,   467,     0,     0,     0,   486,   487,     0,
       0,   460,   432,   459,     0,   299,   299,     0,     0,   150,
     155,     0,     0,   315,   316,   365,   366,   367,   368,   369,
     370,   372,   317,     0,   363,   353,   354,   355,   356,   357,
     358,   372,   318,     0,   349,   148,   152,   144,   142,     0,
       0,   140,   405,   294,   292,   293,   291,     0,   282,   287,
     296,     0,   438,   427,   473,   475,   478,   477,   485,   479,
     482,   480,   481,   483,   476,     0,     0,     0,     0,   424,
     466,     0,   463,   101,   307,    33,    37,     0,     0,     0,
     371,     0,   359,     0,     0,   352,     0,     0,   195,   157,
       0,   203,   175,     0,     0,     0,     0,     0,   186,   187,
       0,     0,   193,   198,   197,     0,     0,   201,   205,   204,
     208,   202,     0,     0,   196,     0,     0,     0,     0,   235,
     207,   206,     0,     0,   211,   212,   219,     0,     0,   215,
     214,   216,   213,     0,     0,   226,   227,   228,   229,   230,
       0,     0,     0,     0,     0,     0,   172,   173,   279,   274,
       0,   484,     0,     0,   497,     0,     0,   423,   474,   309,
     345,     0,   351,     0,   362,   364,   360,   348,     0,   147,
     143,     0,     0,   158,   159,     0,   162,     0,   166,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,   489,     0,   425,     0,   373,   350,     0,
     169,     0,     0,     0,     0,   168,     0,   257,   249,   250,
     251,   252,   253,   254,   255,   256,   260,   258,   261,   262,
     263,   264,   259,   374,   247,   179,   244,   245,   243,   246,
     180,   184,   182,   188,     0,   199,   200,   240,   241,   190,
     191,   221,   223,   222,   232,   192,   242,   220,   217,   218,
     225,   224,     0,   233,   234,   181,   238,   236,   239,   237,
     174,     0,   490,   498,   346,   194,   170,   178,   160,   164,
     161,     0,   165,     0,   248,   176,   375,     0,     0,   341,
     328,   340,   343,   339,     0,     0,     0,   342,   324,   336,
     333,   332,   335,   331,     0,   334,   326,   275,     0,   167,
     396,   399,   397,     0,     0,   398,   380,   381,   376,   377,
     390,   395,   185,   183,   329,   330,   189,     0,     0,     0,
     231,     0,   163,     0,   393,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   388,   389,   325,   338,   337,
     327,   394,   379,   378,   384,   383,   387,   385,   382,     0,
       0,     0,   386,     0,   400,     0,   391,   392,     0,   401
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -693,  -693,  -693,  -693,   866,   -14,   557,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,   668,   157,  -693,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,   126,  -693,    -2,  -693,  -145,  -693,
     -27,  -693,  -693,  -693,   848,  -693,  -693,   833,  -693,  -693,
    -693,  -693,  -693,   -73,   163,  -693,  -190,  -693,  -693,  -693,
    -693,  -693,  -693,  -693,   -10,  -693,  -693,  -693,  -693,  -693,
     777,  -693,  -693,  -693,  -174,  -693,  -693,  -693,  -287,  -693,
    -693,  -693,  -693,   211,  -693,  -693,   213,  -693,  -693,  -693,
     227,   232,  -693,   196,  -693,  -693,   739,  -693,  -693,  -693,
    -693,   392,  -693,  -693,   549,   471,   473,  -693,   438,  -693,
     573,   -94,   440,  -693,  -693,  -693,  -693,  -692,   105,   111,
    -314,   500,  -693,  -693,  -693,  -693,   367,  -693,  -693,  -693,
    -693,   370,   421,  -693,  -693,  -693,  -459,    38,  -693,  -693,
    -693,  -693,   729,   563,   644,   -85,    67,  -693,  -302,  -693,
    -693,  -693,  -693,  -693,  -693,   -51,  -693,  -693,  -693,   722,
     715,   673,   600,  -693,   331,  -693,   458,  -693,   457,  -272,
    -693,  -693,  -693,  -481,   310
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,     3,   213,   357,   127,     9,    21,    71,
      72,    73,    74,   200,   201,   112,    75,   114,   273,   447,
      76,   116,   274,   448,    34,    44,    63,    64,   192,   193,
     194,    22,    45,    23,    24,    32,    40,    42,    53,   191,
     317,   102,    43,    82,   237,   238,   239,   240,   241,   269,
     312,   445,    36,    47,    48,    79,   121,    50,    95,    96,
      97,   163,   208,   209,   210,   254,   403,   329,   325,   326,
     282,   612,   613,   614,   615,   730,   619,   662,   481,   586,
     587,   690,   683,   684,    99,   138,   139,   140,   219,   488,
     284,   268,   259,   334,   298,   335,   336,   380,   313,   314,
     315,   358,   316,   446,   398,   746,   754,   747,   756,   748,
     749,   453,   472,   525,   603,   473,   474,   607,   462,   463,
     604,   464,   520,   735,   736,   768,   769,   770,   771,   815,
     141,   165,   166,   214,   215,   216,   217,   143,   299,   300,
     597,   301,   302,   303,   304,   305,   306,   173,   182,   174,
     183,   263,   264,   144,   307,   309,   366,   367,   368,   369,
     440,   360,   361,   362,   595
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    29,   128,   365,   118,   249,   365,    18,    19,   195,
     323,   197,     4,   142,   760,   761,     5,     6,    77,   778,
     755,    46,   123,    80,   359,   125,  -119,   594,   701,   126,
    -119,   255,   762,    46,   253,   125,   482,    83,   763,   126,
     413,   343,   686,   687,    26,   346,   125,   271,    27,   278,
     126,   111,   111,   142,   111,     1,   111,   660,   349,   339,
     688,   365,   110,   350,   120,   187,   661,    46,   505,   279,
      10,   122,    26,   760,   761,    11,    27,   414,   277,   418,
     419,   420,   421,   256,   137,   346,   347,   702,   256,   755,
     348,   762,   779,   449,   227,   228,   340,   483,   349,   324,
     111,   716,   111,   350,   229,   226,    13,   152,   230,   351,
     270,   594,   476,   352,   353,   764,    14,    26,   765,   717,
     703,    27,   442,   231,   137,   232,   506,    15,   271,   271,
     320,   689,   206,   423,   424,   478,   261,   509,   261,    16,
     207,    25,   485,   493,    84,   202,   203,   204,   205,   355,
     137,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     199,    17,     7,   507,   280,   344,   243,   479,   510,    30,
     225,   425,   129,   723,    20,   416,   137,   765,   130,   341,
     426,   427,   428,   429,    26,   111,   354,   292,    27,   355,
      85,    86,    87,    88,    89,    31,    90,   233,    33,   430,
     342,   345,   234,    80,    26,   258,    26,   137,    27,   137,
      27,   766,   767,   261,   308,    91,    92,   131,    93,   378,
      26,    94,    26,   113,    27,   115,    27,   117,   370,   617,
     235,   236,   356,   591,    38,   718,    81,   276,   153,   154,
     281,   156,   137,   158,   374,   371,   363,    35,   408,   417,
     431,   432,   433,   719,   291,   434,   435,   436,    26,   437,
     438,   184,    27,   293,   294,   322,   295,   296,    41,   206,
     297,   155,   600,   157,   333,   119,   528,   207,   601,   653,
     252,   196,    49,   198,   137,   654,   227,   228,   262,   529,
     262,   530,    78,   125,   655,   722,   229,   126,   439,    39,
     230,   654,   375,   132,   783,   784,   776,   379,   780,   133,
     134,    52,   777,   401,   781,   231,   137,   232,   135,   136,
      98,   652,   100,   531,   286,   101,   802,   803,   495,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   108,   211,
      18,    19,   551,   212,   109,   552,   248,   338,   817,   553,
     554,   555,   556,   129,   818,   262,    26,   450,   103,   130,
      27,   332,    80,     4,   275,    26,   104,     5,   475,    27,
     629,   630,   557,   105,   558,   559,   160,   161,   162,   233,
     227,   228,   484,   486,   234,   333,   333,   170,   171,   172,
     229,   310,   311,   106,   230,   107,   376,    80,   131,   146,
      54,   145,   170,   171,   172,   221,   560,   561,   147,   231,
     562,   232,   235,   236,   708,   709,   291,   148,   563,   150,
     564,   149,   565,   785,   786,   616,   318,   319,   566,   567,
     568,   423,   424,   569,   570,   571,   572,   573,   574,   151,
     575,   576,   577,   578,   579,   580,   581,   582,   292,   159,
     583,   167,   584,   585,   798,   799,   185,   186,   227,   228,
     164,   168,   184,   423,   424,    55,   169,   189,   229,   425,
     190,   199,   230,    56,   220,    57,    58,    59,   426,   427,
     428,   429,   251,   233,   132,   423,   424,   231,   234,   232,
     133,   134,    60,    61,    62,   242,   292,   430,   244,   135,
     136,   425,   609,   787,   788,   245,   618,   247,   246,   494,
     426,   427,   428,   429,   260,   -11,   235,   236,   -12,   257,
     266,   267,   184,   425,   293,   294,   272,   295,   296,   430,
     287,   297,   426,   427,   428,   429,   288,   283,   289,   290,
     321,   789,    65,    66,    67,    68,    69,    70,   431,   432,
     433,   430,   327,   434,   435,   436,   328,   437,   438,   616,
     330,   233,   331,   377,   381,   337,   234,   400,   399,   790,
     184,   402,   293,   294,   405,   295,   296,   406,   407,   297,
     431,   432,   433,   410,   411,   434,   435,   436,   412,   437,
     438,   415,   739,   665,   235,   236,    54,   667,   422,   691,
     692,   -11,   431,   432,   593,   740,   741,   434,   435,   436,
     -12,   437,   438,   705,   441,   444,   443,   451,   742,   452,
     791,   323,   477,   743,   492,   792,   793,   794,   487,   795,
     796,   480,    84,   744,   745,   491,   508,   515,   618,   516,
     729,   519,   732,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   517,   518,
     521,    55,   524,   523,   175,   425,   526,   527,   588,    56,
     590,    57,    58,    59,   426,   427,   428,   429,    85,    86,
      87,    88,    89,   602,    90,   592,   608,   596,    60,    61,
      62,   598,   610,   430,   175,   611,   599,   733,   620,   621,
     649,   622,   623,    91,    92,   624,    93,   759,   625,    94,
     650,   626,   627,   772,   773,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   176,   177,   178,   223,
     179,   180,   181,   667,   782,   628,   455,   456,   457,   458,
     459,   460,   461,   631,   431,   432,   433,   632,   633,   434,
     435,   436,   634,   437,   438,   635,   176,   177,   178,   636,
     179,   180,   181,   637,   638,   393,   394,   395,   396,   465,
     466,   467,   468,   469,   470,   471,   639,   640,   641,   668,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   750,   642,   643,   644,   645,   397,
     646,   647,   648,   656,   663,   659,   664,   740,   751,   666,
     685,   657,   658,   693,   694,   804,   805,   806,   807,   808,
     752,   810,   695,   696,   697,   753,   698,   699,   700,   704,
     706,   707,   710,   711,   713,   744,   745,   812,   712,   814,
     714,   816,   721,   724,   725,   726,   819,   731,   737,   738,
     757,   774,   758,   775,   813,   801,   809,     8,   250,   811,
     372,    37,   124,    51,   728,   727,   720,   188,   715,   734,
     589,   490,   489,   409,   514,   513,   800,   373,   797,   454,
     606,   605,   522,   404,   218,   222,   265,   224,   364,   511,
     285,   512,   651
};

static const yytype_uint16 yycheck[] =
{
      14,    15,    96,   305,    77,    27,   308,    23,    24,   154,
      62,   156,    30,    98,    29,    30,    34,    35,    45,    38,
     712,    35,    95,    27,   296,    30,    30,   508,    85,    34,
      34,     8,    47,    47,   208,    30,     8,    47,    53,    34,
      47,    46,    29,    30,    30,    29,    30,   237,    34,    35,
      34,    65,    66,   138,    68,    21,    70,    51,    42,    47,
      47,   363,    64,    47,    78,   138,    60,    81,    74,    55,
       0,    81,    30,    29,    30,    48,    34,    84,   252,   351,
     352,   353,   354,    60,    98,    29,    30,   144,    60,   781,
      34,    47,   111,   380,    16,    17,    84,    55,    42,   151,
     114,    29,   116,    47,    26,   190,    41,   109,    30,    53,
      32,   592,   399,    57,    58,   130,    39,    30,   133,    47,
     177,    34,    27,    45,   138,    47,   132,    39,   318,   319,
     275,   118,    38,     8,     9,    28,   221,   439,   223,    41,
      46,    42,    55,   415,   148,   159,   160,   161,   162,   133,
     164,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     182,    47,   180,   435,   150,   170,   193,    60,   440,    42,
     184,    46,    18,   654,   190,   170,   190,   133,    24,   167,
      55,    56,    57,    58,    30,   199,   130,    92,    34,   133,
     194,   195,   196,   197,   198,    47,   200,   119,    53,    74,
     294,   295,   124,    27,    30,   219,    30,   221,    34,   223,
      34,   226,   227,   298,   265,   219,   220,    63,   222,    27,
      30,   225,    30,    66,    34,    68,    34,    70,    28,    55,
     152,   153,   176,   505,    43,    29,    60,   251,   112,   113,
     254,   115,   256,   117,   317,    45,   297,    44,    54,   343,
     125,   126,   127,    47,    60,   130,   131,   132,    30,   134,
     135,   166,    34,   168,   169,   279,   171,   172,    25,    38,
     175,   114,    54,   116,   288,    47,    37,    46,    60,    54,
      49,   155,    20,   157,   298,    60,    16,    17,   221,    50,
     223,    52,    46,    30,   596,    54,    26,    34,   173,    43,
      30,    60,    32,   149,   763,   764,    54,   321,    54,   155,
     156,    29,    60,   327,    60,    45,   330,    47,   164,   165,
      19,   593,    22,    84,   257,   179,   785,   786,   422,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    54,    30,
      23,    24,   113,    34,    60,   116,   199,   290,    54,   120,
     121,   122,   123,    18,    60,   298,    30,   381,    46,    24,
      34,    35,    27,    30,   248,    30,    46,    34,   392,    34,
     109,   110,   143,    46,   145,   146,    38,    39,    40,   119,
      16,    17,   406,   407,   124,   409,   410,   157,   158,   159,
      26,   152,   153,    46,    30,    46,    32,    27,    63,    31,
     116,    29,   157,   158,   159,   160,   177,   178,    47,    45,
     181,    47,   152,   153,   202,   203,    60,    30,   189,    29,
     191,    47,   193,   126,   127,   529,   273,   274,   199,   200,
     201,     8,     9,   204,   205,   206,   207,   208,   209,    29,
     211,   212,   213,   214,   215,   216,   217,   218,    92,    40,
     221,    59,   223,   224,   778,   779,   135,   136,    16,    17,
       9,    47,   166,     8,     9,   181,    53,    49,    26,    46,
     154,   182,    30,   189,    29,   191,   192,   193,    55,    56,
      57,    58,    38,   119,   149,     8,     9,    45,   124,    47,
     155,   156,   208,   209,   210,    27,    92,    74,    27,   164,
     165,    46,   526,     8,     9,    31,   530,    31,    27,    54,
      55,    56,    57,    58,    60,    40,   152,   153,    40,    40,
      53,    49,   166,    46,   168,   169,    16,   171,   172,    74,
      26,   175,    55,    56,    57,    58,    53,    55,    29,    40,
      40,    46,   183,   184,   185,   186,   187,   188,   125,   126,
     127,    74,    40,   130,   131,   132,    26,   134,   135,   663,
       9,   119,    29,    27,    40,    54,   124,   130,    43,    74,
     166,    29,   168,   169,    28,   171,   172,    40,    40,   175,
     125,   126,   127,    61,   111,   130,   131,   132,    47,   134,
     135,    46,    16,   617,   152,   153,   116,    29,   160,   623,
     624,    53,   125,   126,   127,    29,    30,   130,   131,   132,
      53,   134,   135,   637,    53,    60,    54,    53,    42,    53,
     125,    62,    42,    47,    47,   130,   131,   132,   112,   134,
     135,    60,   148,    57,    58,    53,    53,    27,   662,    27,
     664,    53,   666,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    29,    29,
     111,   181,    53,   111,    95,    46,    40,    29,   147,   189,
      29,   191,   192,   193,    55,    56,    57,    58,   194,   195,
     196,   197,   198,    29,   200,    53,    29,   174,   208,   209,
     210,    54,    28,    74,    95,    25,    54,   129,    46,    46,
      60,    46,    74,   219,   220,    74,   222,   731,    46,   225,
      60,    46,    46,   737,   738,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   157,   158,   159,   160,
     161,   162,   163,    29,   758,    46,   136,   137,   138,   139,
     140,   141,   142,    46,   125,   126,   127,    46,    46,   130,
     131,   132,    46,   134,   135,    46,   157,   158,   159,    46,
     161,   162,   163,    46,    46,   114,   115,   116,   117,   136,
     137,   138,   139,   140,   141,   142,    46,    46,    46,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    16,    46,    46,    46,    46,   148,
      46,    46,    46,    29,    60,    46,    46,    29,    30,    40,
      47,    54,    54,    47,    53,   787,   788,   789,   790,   791,
      42,   793,    47,    47,    47,    47,    47,    47,    47,    29,
      47,    47,    29,    29,    29,    57,    58,   809,    53,   811,
      29,   813,    29,    54,    29,    51,   818,    40,    40,    40,
      54,    29,    40,    29,   127,    54,    74,     1,   200,    53,
     313,    23,    95,    40,   663,   662,   649,   138,   646,   683,
     488,   410,   409,   334,   446,   445,   781,   314,   777,   389,
     523,   521,   471,   330,   165,   173,   223,   182,   298,   441,
     256,   444,   592
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   229,   231,    30,    34,    35,   180,   232,   235,
       0,    48,   230,    41,    39,    39,    41,    47,    23,    24,
     190,   236,   259,   261,   262,    42,    30,    34,   233,   233,
      42,    47,   263,    53,   252,    44,   280,   262,    43,    43,
     264,    25,   265,   270,   253,   260,   233,   281,   282,    20,
     285,   265,    29,   266,   116,   181,   189,   191,   192,   193,
     208,   209,   210,   254,   255,   183,   184,   185,   186,   187,
     188,   237,   238,   239,   240,   244,   248,   258,    46,   283,
      27,    60,   271,   282,   148,   194,   195,   196,   197,   198,
     200,   219,   220,   222,   225,   286,   287,   288,    19,   312,
      22,   179,   269,    46,    46,    46,    46,    46,    54,    60,
     254,   233,   243,   243,   245,   243,   249,   243,   271,    47,
     233,   284,   282,   271,   288,    30,    34,   234,   329,    18,
      24,    63,   149,   155,   156,   164,   165,   233,   313,   314,
     315,   358,   363,   365,   381,    29,    31,    47,    30,    47,
      29,    29,   254,   252,   252,   243,   252,   243,   252,    40,
      38,    39,    40,   289,     9,   359,   360,    59,    47,    53,
     157,   158,   159,   375,   377,    95,   157,   158,   159,   161,
     162,   163,   376,   378,   166,   382,   382,   271,   314,    49,
     154,   267,   256,   257,   258,   256,   252,   256,   252,   182,
     241,   242,   233,   233,   233,   233,    38,    46,   290,   291,
     292,    30,    34,   232,   361,   362,   363,   364,   360,   316,
      29,   160,   377,   160,   378,   233,   363,    16,    17,    26,
      30,    45,    47,   119,   124,   152,   153,   272,   273,   274,
     275,   276,    27,   258,    27,    31,    27,    31,   243,    27,
     242,    38,    49,   292,   293,     8,    60,    40,   233,   320,
      60,   363,   364,   379,   380,   379,    53,    49,   319,   277,
      32,   274,    16,   246,   250,   252,   233,   292,    35,    55,
     150,   233,   298,    55,   318,   362,   364,    26,    53,    29,
      40,    60,    92,   168,   169,   171,   172,   175,   322,   366,
     367,   369,   370,   371,   372,   373,   374,   382,   373,   383,
     152,   153,   278,   326,   327,   328,   330,   268,   272,   272,
     256,    40,   233,    62,   151,   296,   297,    40,    26,   295,
       9,    29,    35,   233,   321,   323,   324,    54,   364,    47,
      84,   167,   329,    46,   170,   329,    29,    30,    34,    42,
      47,    53,    57,    58,   130,   133,   176,   233,   329,   387,
     389,   390,   391,   373,   380,   366,   384,   385,   386,   387,
      28,    45,   234,   328,   271,    32,    32,    27,    27,   233,
     325,    40,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   114,   115,   116,   117,   148,   332,    43,
     130,   233,    29,   294,   361,    28,    40,    40,    54,   322,
      61,   111,    47,    47,    84,    46,   170,   329,   387,   387,
     387,   387,   160,     8,     9,    46,    55,    56,    57,    58,
      74,   125,   126,   127,   130,   131,   132,   134,   135,   173,
     388,    53,    27,    54,    60,   279,   331,   247,   251,   296,
     233,    53,    53,   339,   339,   136,   137,   138,   139,   140,
     141,   142,   346,   347,   349,   136,   137,   138,   139,   140,
     141,   142,   340,   343,   344,   233,   296,    42,    28,    60,
      60,   306,     8,    55,   233,    55,   233,   112,   317,   324,
     323,    53,    47,   387,    54,   329,   387,   387,   387,   387,
     387,   387,   387,   387,   387,    74,   132,   387,    53,   366,
     387,   384,   386,   330,   326,    27,    27,    29,    29,    53,
     350,   111,   350,   111,    53,   341,    40,    29,    37,    50,
      52,    84,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   113,   116,   120,   121,   122,   123,   143,   145,   146,
     177,   178,   181,   189,   191,   193,   199,   200,   201,   204,
     205,   206,   207,   208,   209,   211,   212,   213,   214,   215,
     216,   217,   218,   221,   223,   224,   307,   308,   147,   319,
      29,   387,    53,   127,   391,   392,   174,   368,    54,    54,
      54,    60,    29,   342,   348,   349,   344,   345,    29,   233,
      28,    25,   299,   300,   301,   302,   329,    55,   233,   304,
      46,    46,    46,    74,    74,    46,    46,    46,    46,   109,
     110,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    60,
      60,   392,   387,    54,    60,   366,    29,    54,    54,    46,
      51,    60,   305,    60,    46,   233,    40,    29,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   310,   311,    47,    29,    30,    47,   118,
     309,   233,   233,    47,    53,    47,    47,    47,    47,    47,
      47,    85,   144,   177,    29,   233,    47,    47,   202,   203,
      29,    29,    53,    29,    29,   309,    29,    47,    29,    47,
     308,    29,    54,   391,    54,    29,    51,   304,   301,   233,
     303,    40,   233,   129,   311,   351,   352,    40,    40,    16,
      29,    30,    42,    47,    57,    58,   333,   335,   337,   338,
      16,    30,    42,    47,   334,   335,   336,    54,    40,   233,
      29,    30,    47,    53,   130,   133,   226,   227,   353,   354,
     355,   356,   233,   233,    29,    29,    54,    60,    38,   111,
      54,    60,   233,   354,   354,   126,   127,     8,     9,    46,
      74,   125,   130,   131,   132,   134,   135,   337,   338,   338,
     336,    54,   354,   354,   355,   355,   355,   355,   355,    74,
     355,    53,   355,   127,   355,   357,   355,    54,    60,   355
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   228,   229,   230,   230,   231,   231,   231,   231,   232,
     232,   233,   233,   234,   234,   235,   235,   235,   235,   236,
     236,   237,   238,   239,   240,   241,   241,   242,   243,   243,
     245,   246,   247,   244,   249,   250,   251,   248,   252,   253,
     252,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     255,   255,   255,   256,   256,   257,   257,   258,   258,   258,
     258,   258,   258,   260,   259,   261,   261,   263,   262,   264,
     262,   266,   267,   268,   265,   269,   269,   270,   270,   270,
     271,   271,   272,   272,   273,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   275,   275,   277,   276,   278,
     279,   278,   280,   280,   281,   281,   281,   282,   283,   283,
     284,   284,   284,   284,   284,   284,   285,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   289,   288,   290,   290,   290,   291,   291,   293,   294,
     292,   295,   295,   295,   296,   296,   297,   297,   297,   297,
     298,   298,   298,   298,   298,   298,   298,   299,   299,   300,
     300,   301,   302,   303,   303,   304,   304,   304,   304,   305,
     305,   306,   306,   307,   307,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   309,   309,   309,   309,   310,   310,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   312,   312,   313,   313,   314,
     314,   315,   315,   316,   315,   315,   315,   315,   317,   317,
     318,   318,   319,   319,   320,   320,   321,   321,   322,   322,
     323,   323,   323,   323,   323,   324,   324,   325,   325,   326,
     326,   327,   327,   328,   328,   329,   331,   330,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   333,   333,   334,   334,   335,   335,
     335,   336,   336,   336,   336,   336,   337,   337,   337,   338,
     338,   338,   338,   338,   339,   339,   339,   340,   340,   341,
     341,   342,   343,   344,   344,   344,   344,   344,   344,   344,
     345,   346,   346,   347,   348,   349,   349,   349,   349,   349,
     349,   349,   350,   350,   351,   351,   352,   353,   353,   353,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   355,   355,   355,   355,   356,
     357,   357,   358,   359,   359,   360,   361,   361,   362,   362,
     363,   364,   365,   365,   365,   365,   366,   366,   366,   366,
     366,   366,   366,   367,   368,   368,   369,   370,   371,   371,
     371,   371,   372,   373,   373,   374,   374,   374,   374,   375,
     375,   376,   376,   377,   377,   377,   378,   378,   378,   378,
     378,   378,   378,   379,   379,   380,   380,   381,   383,   382,
     384,   384,   385,   385,   386,   387,   387,   388,   388,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   390,   391,   391,   391,   391,   391,   392,   392
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     2,     2,     5,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     5,     5,     5,     5,     1,     2,     5,     0,     1,
       0,     0,     0,    10,     0,     0,     0,    10,     0,     0,
       4,     3,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     2,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     0,     5,     1,     2,     0,     3,     0,
       4,     0,     0,     0,     9,     0,     1,     0,     2,     4,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     4,     1,
       0,     4,     0,     3,     1,     2,     3,     2,     0,     2,
       1,     3,     3,     5,     3,     3,     3,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     1,     2,     3,     1,     1,     0,     0,
       6,     0,     3,     5,     3,     1,     0,     5,     3,     2,
       4,     2,     4,     3,     1,     4,     2,     0,     1,     1,
       3,     3,     1,     3,     1,     3,     1,     4,     2,     1,
       2,     0,     2,     1,     3,     1,     4,     2,     4,     3,
       3,     3,     3,     5,     3,     5,     1,     1,     3,     5,
       3,     3,     3,     1,     4,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     5,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     1,     2,     1,
       2,     2,     1,     0,     9,    12,     1,     1,     0,     2,
       0,     1,     0,     1,     1,     4,     1,     3,     0,     1,
       1,     3,     3,     3,     3,     1,     3,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     0,     4,     1,     4,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     0,     3,     5,     0,     3,     0,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     0,     1,     2,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     4,     3,     2,     2,
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
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 163 "screen.yacc" /* yacc.c:1646  */
    {the_form.encoding="";}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 164 "screen.yacc" /* yacc.c:1646  */
    {
		the_form.encoding=strdup(A4GL_strip_quotes((yyvsp[0].str)));
	}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 170 "screen.yacc" /* yacc.c:1646  */
    {the_form.dbname=acl_strdup("formonly");
the_form.allowNullInput=1;
}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 173 "screen.yacc" /* yacc.c:1646  */
    {the_form.dbname=acl_strdup((yyvsp[-3].str));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=0;
}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 179 "screen.yacc" /* yacc.c:1646  */
    {the_form.dbname=("formonly");
the_form.allowNullInput=0;
}
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 182 "screen.yacc" /* yacc.c:1646  */
    {the_form.dbname=acl_strdup((yyvsp[0].str));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=1;
}
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 193 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));A4GL_make_downshift((yyval.str)); }
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 194 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 199 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));A4GL_make_downshift((yyval.str)); }
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 200 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 204 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));
 		if (tagCaseInsensitive) {
                		A4GL_make_downshift((yyval.str));
        		}
	}
#line 2559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 209 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 214 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 215 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),acl_getenv("DBNAME"));}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 217 "screen.yacc" /* yacc.c:1646  */
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[-2].str),(yyvsp[0].str));}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "screen.yacc" /* yacc.c:1646  */
    {
			the_form.layout=NULL;
			the_form.layout_attrib=NULL;
	}
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 226 "screen.yacc" /* yacc.c:1646  */
    {
			the_form.layout=(yyvsp[0].layout);
	}
#line 2600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 233 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.layout)=(yyvsp[-1].layout);
			(yyval.layout)->id=strdup((yyvsp[-3].str));
			(yyval.layout)->attrib=(yyvsp[-2].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_VBOX;
	}
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 243 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.layout)=(yyvsp[-1].layout);
			(yyval.layout)->id=strdup((yyvsp[-3].str));
			(yyval.layout)->attrib=(yyvsp[-2].layout_attrib);
			(yyval.layout)->layout_type=LAYOUT_HBOX;
	}
#line 2622 "y.tab.c" /* yacc.c:1646  */
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
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 265 "screen.yacc" /* yacc.c:1646  */
    {
		 (yyval.layout)=(yyvsp[-1].layout);
		 (yyval.layout)->id=strdup((yyvsp[-3].str));
		 (yyval.layout)->attrib=(yyvsp[-2].layout_attrib);
	}
#line 2647 "y.tab.c" /* yacc.c:1646  */
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
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 283 "screen.yacc" /* yacc.c:1646  */
    {
		add_child((yyvsp[-1].layout), (yyvsp[0].layout));
		(yyval.layout)=(yyvsp[-1].layout);
	}
#line 2671 "y.tab.c" /* yacc.c:1646  */
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
#line 2685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 304 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 2691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 305 "screen.yacc" /* yacc.c:1646  */
    {
		{strcpy((yyval.str),(yyvsp[0].str));}
	}
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 312 "screen.yacc" /* yacc.c:1646  */
    { in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf((yyval.str),"%d", scr); }
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 315 "screen.yacc" /* yacc.c:1646  */
    { ignorekw=1; lineno=0; }
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 318 "screen.yacc" /* yacc.c:1646  */
    {ignorekw=0; in_screen_section=0;}
#line 2717 "y.tab.c" /* yacc.c:1646  */
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
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 334 "screen.yacc" /* yacc.c:1646  */
    { in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf((yyval.str),"%d", scr);}
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 337 "screen.yacc" /* yacc.c:1646  */
    { ignorekw=1; lineno=0; }
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 340 "screen.yacc" /* yacc.c:1646  */
    {ignorekw=0; in_screen_section=0;}
#line 2749 "y.tab.c" /* yacc.c:1646  */
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
#line 2764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 354 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout_attrib)=0;
		}
#line 2772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 357 "screen.yacc" /* yacc.c:1646  */
    { new_layout_attribs(); }
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 357 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout_attrib)=get_layout_attrib();
	}
#line 2786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 363 "screen.yacc" /* yacc.c:1646  */
    {
		add_str_layout_attrib(FA_S_STYLE, (yyvsp[0].str));
	}
#line 2794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 366 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 369 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_NOSHOW);
	}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 372 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
#line 2818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 375 "screen.yacc" /* yacc.c:1646  */
    {
		add_str_layout_attrib(FA_S_TEXT, (yyvsp[0].str)); 
	}
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 378 "screen.yacc" /* yacc.c:1646  */
    {
		add_str_layout_attrib(FA_S_ACTION, (yyvsp[0].str)); 
	}
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 381 "screen.yacc" /* yacc.c:1646  */
    {
		add_bool_layout_attrib(FA_B_BORDER);
	}
#line 2842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 384 "screen.yacc" /* yacc.c:1646  */
    { add_str_layout_attrib(FA_S_PIXELHEIGHT,(yyvsp[0].str)); }
#line 2848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 385 "screen.yacc" /* yacc.c:1646  */
    { add_str_layout_attrib(FA_S_PIXELWIDTH,(yyvsp[0].str)); }
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 395 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout)=malloc(sizeof(struct s_layout));
		                (yyval.layout)->layout_type=LAYOUT_NOTSET;
                		(yyval.layout)->id="NOTSET";
                		(yyval.layout)->attrib=0;
                		(yyval.layout)->screen_no=-1;
                		(yyval.layout)->children.children_val=0;
                		(yyval.layout)->children.children_len=0;
		}
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 404 "screen.yacc" /* yacc.c:1646  */
    {(yyval.layout)=(yyvsp[0].layout);}
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 410 "screen.yacc" /* yacc.c:1646  */
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
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 420 "screen.yacc" /* yacc.c:1646  */
    {
		add_child((yyvsp[-1].layout), (yyvsp[0].layout));
		(yyval.layout)=(yyvsp[-1].layout);
	}
#line 2898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 428 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout); }
#line 2904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 430 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 432 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 434 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 436 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 438 "screen.yacc" /* yacc.c:1646  */
    { (yyval.layout)=(yyvsp[0].layout);}
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 442 "screen.yacc" /* yacc.c:1646  */
    { 
		the_form.layout_attrib=(yyvsp[0].layout_attrib);
	}
#line 2942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 444 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.layout)=(yyvsp[-1].layout);
	}
#line 2950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 455 "screen.yacc" /* yacc.c:1646  */
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
#line 2968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 468 "screen.yacc" /* yacc.c:1646  */
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
#line 2990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 487 "screen.yacc" /* yacc.c:1646  */
    { lineno=0; scr++; if (scr>1) newscreen=1; }
#line 2996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 489 "screen.yacc" /* yacc.c:1646  */
    { ignorekw=1; lineno=0; }
#line 3002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 492 "screen.yacc" /* yacc.c:1646  */
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
#line 3008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 497 "screen.yacc" /* yacc.c:1646  */
    { extended_graphics=1; }
#line 3014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 504 "screen.yacc" /* yacc.c:1646  */
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
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 526 "screen.yacc" /* yacc.c:1646  */
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
#line 3045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 541 "screen.yacc" /* yacc.c:1646  */
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
#line 3062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 553 "screen.yacc" /* yacc.c:1646  */
    { ltab=0; }
#line 3068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 554 "screen.yacc" /* yacc.c:1646  */
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
#line 3084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 565 "screen.yacc" /* yacc.c:1646  */
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
#line 3100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 576 "screen.yacc" /* yacc.c:1646  */
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
#line 3116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 589 "screen.yacc" /* yacc.c:1646  */
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
#line 3132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 601 "screen.yacc" /* yacc.c:1646  */
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
#line 3148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 612 "screen.yacc" /* yacc.c:1646  */
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
#line 3158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 617 "screen.yacc" /* yacc.c:1646  */
    {colno=0;lineno++;
	ltab=0;
}
#line 3166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 620 "screen.yacc" /* yacc.c:1646  */
    {
	ltab=0;
}
#line 3174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 628 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 3180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 629 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 3186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 635 "screen.yacc" /* yacc.c:1646  */
    {
	colno++;
	fstart=colno;
	openwith='[';
}
#line 3196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 642 "screen.yacc" /* yacc.c:1646  */
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
#line 3213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 659 "screen.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str),(yyvsp[0].str));
			}
#line 3221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 662 "screen.yacc" /* yacc.c:1646  */
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
#line 3238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 673 "screen.yacc" /* yacc.c:1646  */
    {
				strcpy((yyval.str),(yyvsp[0].str));
			}
#line 3246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 689 "screen.yacc" /* yacc.c:1646  */
    { 
clr_status();
A4GL_add_table((yyvsp[0].str),(yyvsp[-1].str)); 
err_on_status();
}
#line 3256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 696 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 3262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 697 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 3268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 700 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s", (yyvsp[0].str));}
#line 3274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 701 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 3280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 703 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 3286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 704 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
#line 3292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 705 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
#line 3298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 721 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Edit");}
#line 3304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 722 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Edit");}
#line 3310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 723 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"TextEdit");}
#line 3316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 724 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Label");}
#line 3322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 725 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"DateEdit");}
#line 3328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 726 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"ButtonEdit");}
#line 3334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 727 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Button");}
#line 3340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 728 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Image");}
#line 3346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 729 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"ProgressBar");}
#line 3352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 730 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"ComboBox");}
#line 3358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 731 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"CheckBox");}
#line 3364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 732 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"Browser");}
#line 3370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 737 "screen.yacc" /* yacc.c:1646  */
    {
			if (tagCaseInsensitive) {
				A4GL_make_downshift((yyvsp[0].str));
			}
			strcpy(currftag,(yyvsp[0].str));
			fldno=A4GL_find_field((yyvsp[0].str));
		}
#line 3382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 745 "screen.yacc" /* yacc.c:1646  */
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
#line 3406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 775 "screen.yacc" /* yacc.c:1646  */
    { 
	A4GL_init_fld();
}
#line 3414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 779 "screen.yacc" /* yacc.c:1646  */
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
#line 3432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 793 "screen.yacc" /* yacc.c:1646  */
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
#line 3751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1112 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[-1].str));
}
#line 3761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1118 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi((yyvsp[-3].str));
	fld->subscripts[1]=atoi((yyvsp[-1].str));
}
#line 3772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1128 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",atoi((yyvsp[-2].str))+256); }
#line 3778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1129 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[0].str)); }
#line 3784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1132 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"0"); dtype_size=0;}
#line 3790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1133 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[0].str),(yyvsp[-2].str),1));
        		dtype_size=A4GL_get_dtype_size();
		}
#line 3799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1137 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[0].str),"",1));
        		dtype_size=A4GL_get_dtype_size();
		}
#line 3808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1141 "screen.yacc" /* yacc.c:1646  */
    {
			strcpy((yyval.str),(yyvsp[0].str));
			
		}
#line 3817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1147 "screen.yacc" /* yacc.c:1646  */
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
#line 3833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1158 "screen.yacc" /* yacc.c:1646  */
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
#line 3852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1172 "screen.yacc" /* yacc.c:1646  */
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
#line 3871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1186 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup((yyvsp[-2].str)); 
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        fld->dtype_size=A4GL_get_dtype_size();
}
#line 3885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1195 "screen.yacc" /* yacc.c:1646  */
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
#line 3911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1217 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup((yyvsp[-2].str)); 
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        fld->dtype_size=A4GL_get_dtype_size();
}
#line 3925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1226 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"",0);
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
#line 3939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1238 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;
	}
#line 3949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1243 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookups)=(yyvsp[0].lookups);
		}
#line 3957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1249 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookups)=malloc(sizeof(s_lookups));
		(yyval.lookups)->lookups.lookups_len=0;
		(yyval.lookups)->lookups.lookups_val=0;

		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[0].lookup);
	}
#line 3971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1258 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookups)=(yyvsp[-2].lookups);
		(yyval.lookups)->lookups.lookups_len++;
		(yyval.lookups)->lookups.lookups_val=realloc((yyval.lookups)->lookups.lookups_val, sizeof((yyval.lookups)->lookups.lookups_val[0])*(yyval.lookups)->lookups.lookups_len);
		(yyval.lookups)->lookups.lookups_val[(yyval.lookups)->lookups.lookups_len-1]=(yyvsp[0].lookup);
	}
#line 3982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1267 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.lookup)=malloc(sizeof(struct s_lookup));
		(yyval.lookup)->fieldtag=strdup((yyvsp[-2].str));
		(yyval.lookup)->tabcol=strdup((yyvsp[0].str));
}
#line 3992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1276 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%s.%s", (yyvsp[-2].str),(yyvsp[0].str));
		}
#line 4000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1279 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%s", (yyvsp[0].str));
	}
#line 4008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1285 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s.%s", (yyvsp[-2].str),(yyvsp[0].str));}
#line 4014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1286 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%s",(yyvsp[0].str));}
#line 4020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1287 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"*%s.%s", (yyvsp[-2].str),(yyvsp[0].str));}
#line 4026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1288 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"*%s",(yyvsp[0].str));}
#line 4032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1304 "screen.yacc" /* yacc.c:1646  */
    { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
#line 4042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1309 "screen.yacc" /* yacc.c:1646  */
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
#line 4069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1331 "screen.yacc" /* yacc.c:1646  */
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
#line 4098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1355 "screen.yacc" /* yacc.c:1646  */
    {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	(yyvsp[-2].lookups)->joincol=strdup((yyvsp[0].str));
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=(yyvsp[-2].lookups);
}
#line 4111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1363 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,(yyvsp[0].str)); }
#line 4117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1364 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,(yyvsp[0].str)); }
#line 4123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1365 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,(yyvsp[0].str)); }
#line 4129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1366 "screen.yacc" /* yacc.c:1646  */
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
#line 4139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1371 "screen.yacc" /* yacc.c:1646  */
    {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
#line 4149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1376 "screen.yacc" /* yacc.c:1646  */
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
#line 4159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1381 "screen.yacc" /* yacc.c:1646  */
    {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
#line 4169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1386 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
#line 4175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1387 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
#line 4181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1388 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,(yyvsp[0].str)); }
#line 4187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1389 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"\n%s",(yyvsp[-1].str)); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,(yyval.str)); }
#line 4193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1390 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,(yyvsp[0].str)); }
#line 4199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1391 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,(yyvsp[0].str)); }
#line 4205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1392 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,(yyvsp[0].str)); }
#line 4211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1393 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
#line 4217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1394 "screen.yacc" /* yacc.c:1646  */
    { A4GL_get_fld()->dynamic=atoi((yyvsp[0].str)); 
#ifdef DEBUG
A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); 
#endif
}
#line 4227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1399 "screen.yacc" /* yacc.c:1646  */
    { A4GL_get_fld()->dynamic=-1; 
#ifdef DEBUG
A4GL_debug("dynamic=-1"); 
#endif
}
#line 4237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1404 "screen.yacc" /* yacc.c:1646  */
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[0].str)); }
#line 4243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1406 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }
#line 4249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1408 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
#line 4255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1409 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,(yyvsp[0].str)); }
#line 4261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1410 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,(yyvsp[0].str)); }
#line 4267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1411 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
#line 4273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1412 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
#line 4279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1413 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
#line 4285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1414 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
#line 4291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1415 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
#line 4297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1416 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
#line 4303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1417 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
#line 4309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1418 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
#line 4315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1419 "screen.yacc" /* yacc.c:1646  */
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
#line 4324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1423 "screen.yacc" /* yacc.c:1646  */
    {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}
#line 4332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1430 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
#line 4338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1431 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOSHOW); }
#line 4344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1432 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
#line 4350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1433 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
#line 4356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1434 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTRETURNS); }
#line 4362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1435 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
#line 4368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1436 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
#line 4374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1437 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
#line 4380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1438 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
#line 4386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1439 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,(yyvsp[0].str)); }
#line 4392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1440 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"left"); }
#line 4398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1441 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"right"); }
#line 4404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1442 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"center"); }
#line 4410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1443 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,(yyvsp[0].str)); }
#line 4416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1444 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,(yyvsp[0].str)); }
#line 4422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1445 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); }
#line 4428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1446 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); }
#line 4434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1447 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); }
#line 4440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1448 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); }
#line 4446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1449 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); }
#line 4452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1450 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,(yyvsp[-1].str)); }
#line 4458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1451 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,(yyvsp[0].str)); }
#line 4464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1452 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,(yyvsp[0].str)); }
#line 4470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1453 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,(yyvsp[0].str)); }
#line 4476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1454 "screen.yacc" /* yacc.c:1646  */
    { A4GL_get_fld()->not_null=1;}
#line 4482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1456 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[0].str)); }
#line 4488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1457 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[0].str)); }
#line 4494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1458 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,(yyvsp[0].str)); }
#line 4500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1459 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,(yyvsp[0].str)); }
#line 4506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1460 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,(yyvsp[0].str)); }
#line 4512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1461 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(),FA_S_HEADER,(yyvsp[0].str)); }
#line 4518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1462 "screen.yacc" /* yacc.c:1646  */
    { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, (yyvsp[0].str)); }
#line 4524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1468 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 4530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1469 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 4536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1470 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"\"%s\"",(yyvsp[0].str));}
#line 4542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1471 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"\n%s",(yyvsp[0].str));
	if (strcasecmp((yyvsp[0].str),"current")==0) {
		int a;
		if (((A4GL_get_fld()->datatype)&DTYPE_MASK)==DTYPE_DTIME) {
			a=A4GL_get_fld()->dtype_size;
			sprintf((yyval.str),"\n%s%x",(yyvsp[0].str), a);
		}
	}
}
#line 4556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1484 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",atoi((yyvsp[-1].str))+atoi((yyvsp[0].str))); }
#line 4562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1488 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"0"); }
#line 4568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1489 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"4"); }
#line 4574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1490 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"2"); }
#line 4580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1491 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"6"); }
#line 4586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1492 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"1"); }
#line 4592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1493 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"5"); }
#line 4598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1494 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"7"); }
#line 4604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1495 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"3"); }
#line 4610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1497 "screen.yacc" /* yacc.c:1646  */
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
#line 4649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1532 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
#line 4655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1533 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
#line 4661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1534 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
#line 4667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1535 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
#line 4673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1536 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
#line 4679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1537 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
#line 4685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1538 "screen.yacc" /* yacc.c:1646  */
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
#line 4691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1551 "screen.yacc" /* yacc.c:1646  */
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
#line 4706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1561 "screen.yacc" /* yacc.c:1646  */
    {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], (yyvsp[0].control_block),sizeof(struct s_control_block));
;
}
#line 4717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1567 "screen.yacc" /* yacc.c:1646  */
    {
A4GL_add_srec();
}
#line 4725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1578 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=0;}
#line 4731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1578 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=1;}
#line 4737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1583 "screen.yacc" /* yacc.c:1646  */
    {
   A4GL_set_dim_srec((yyvsp[0].str),1);
}
#line 4745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1586 "screen.yacc" /* yacc.c:1646  */
    {
   A4GL_set_dim_srec((yyvsp[-3].str),atoi((yyvsp[-1].str)));
}
#line 4753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1592 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%s",(yyvsp[0].str));
}
#line 4761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1595 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str));
}
#line 4769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1605 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute("",(yyvsp[0].str),"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
#line 4777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1609 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute((yyvsp[-2].str),(yyvsp[0].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 4785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1613 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute("formonly",(yyvsp[0].str),""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 4793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1617 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute((yyvsp[-2].str),"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 4801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1621 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
#line 4809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1627 "screen.yacc" /* yacc.c:1646  */
    {A4GL_add_srec_attribute("","","THROUGH");}
#line 4815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1631 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),(yyvsp[0].str));
}
#line 4823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1634 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),(yyvsp[0].str)); }
#line 4829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1638 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 4835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1638 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 4841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1645 "screen.yacc" /* yacc.c:1646  */
    {colno++;}
#line 4847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1646 "screen.yacc" /* yacc.c:1646  */
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
#line 4860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1659 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),(yyvsp[0].str));
/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
	colno+=strlen((yyvsp[0].str));
	}
#line 4874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1671 "screen.yacc" /* yacc.c:1646  */
    {
	colno+=strlen((yyvsp[0].str));
}
#line 4882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1673 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),(yyvsp[-2].str));
	/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
}
#line 4895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1684 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
#line 4904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1688 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"0");
	dtype_size=atol((yyvsp[-1].str));
}
#line 4913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1692 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
#line 4922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1696 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
#line 4931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1700 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
#line 4940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1704 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
#line 4949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1708 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
#line 4958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1712 "screen.yacc" /* yacc.c:1646  */
    {
		int i;
		i=atoi((yyvsp[0].str));
		strcpy((yyval.str),"5");
		dtype_size=i;
}
#line 4969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1718 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[0].str));
}
#line 4978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1722 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[0].str));
}
#line 4987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1726 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[0].str));
}
#line 4996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1730 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
#line 5005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1734 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
#line 5014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1738 "screen.yacc" /* yacc.c:1646  */
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
#line 5023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1742 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
#line 5031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1745 "screen.yacc" /* yacc.c:1646  */
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
#line 5039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1752 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[-2].str),(yyvsp[0].str));
}
#line 5047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1756 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[-2].str),(yyvsp[0].str));
}
#line 5055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1761 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"-%s",(yyvsp[0].str));}
#line 5061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1765 "screen.yacc" /* yacc.c:1646  */
    { 
		if (strlen((yyvsp[0].str))==2) { /* "" */
			strcpy((yyval.str),"");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[0].str))); 
		}
	}
#line 5073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1772 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str)); }
#line 5079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1773 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1775 "screen.yacc" /* yacc.c:1646  */
    {
		strcpy((yyval.str),"");
	}
#line 5093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1783 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[-2].str),(yyvsp[0].str)); 
	}
#line 5101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1786 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"%s\t%s",(yyvsp[-2].str),(yyvsp[0].str)); 
	}
#line 5109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1792 "screen.yacc" /* yacc.c:1646  */
    {
		if (strlen((yyvsp[0].str))==2) {/* "" */
			sprintf((yyval.str),"NULL");
		} else {
			strcpy((yyval.str),A4GL_char_val((yyvsp[0].str)));
		}
	}
#line 5121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1799 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1800 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1801 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1802 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"NULL");}
#line 5145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1808 "screen.yacc" /* yacc.c:1646  */
    {
			sprintf((yyval.str),"0");
		}
#line 5153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1811 "screen.yacc" /* yacc.c:1646  */
    {
		int n;
		 n=atol(acl_getenv("A4GL_DEFDECPREC"));
		sprintf((yyval.str),"%d",((atoi((yyvsp[-1].str)))<<8)+n);
	}
#line 5163 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1816 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%d",(atoi((yyvsp[-3].str))<<8)+atoi((yyvsp[-1].str)));}
#line 5169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1819 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1821 "screen.yacc" /* yacc.c:1646  */
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[-2].str))*16)+atoi((yyvsp[0].str)));
	}
#line 5183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1827 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
#line 5193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1831 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("    %s",(yyvsp[-1].str));
#endif
strcpy((yyval.str),(yyvsp[-1].str));
}
#line 5204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1838 "screen.yacc" /* yacc.c:1646  */
    {
if (atoi((yyvsp[0].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
#line 5215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1846 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%d",atoi((yyvsp[0].str))*16+atoi((yyvsp[-1].str)));}
#line 5221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1849 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"1");}
#line 5227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1850 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"2");}
#line 5233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1851 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"3");}
#line 5239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1852 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"4");}
#line 5245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1853 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"5");}
#line 5251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1854 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"6");}
#line 5257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1856 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
  A4GL_debug("opt_frac returns %s",(yyvsp[0].str));
#endif
  sprintf((yyval.str),"%d",atoi((yyvsp[0].str))+6); }
#line 5267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1865 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"");}
#line 5273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1866 "screen.yacc" /* yacc.c:1646  */
    {sprintf((yyval.str),"%d",atoi((yyvsp[-2].str))*16+atoi((yyvsp[0].str)));}
#line 5279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1869 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1872 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),(yyvsp[0].str));}
#line 5291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1876 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"1");}
#line 5297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1877 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"2");}
#line 5303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1878 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"3");}
#line 5309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1879 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"4");}
#line 5315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1880 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"5");}
#line 5321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1881 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"6");}
#line 5327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1883 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("opt_frac returns %s",(yyvsp[0].str));
#endif
sprintf((yyval.str),"%d",atoi((yyvsp[0].str))+6); }
#line 5337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1890 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy((yyval.str),"2");}
#line 5347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1894 "screen.yacc" /* yacc.c:1646  */
    {
#ifdef DEBUG
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[-1].str));
#endif
strcpy((yyval.str),(yyvsp[-1].str));
}
#line 5359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1903 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=0;}
#line 5365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1903 "screen.yacc" /* yacc.c:1646  */
    {
(yyval.expr)=(yyvsp[0].expr);
}
#line 5373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1909 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=(yyvsp[0].expr);
	}
#line 5381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1916 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),"AND");  
	}
#line 5389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1919 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),"OR");  
	}
#line 5397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1928 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_oddline();}
#line 5403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1929 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_evenline(); }
#line 5409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1930 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5415 "y.tab.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1931 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1932 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1933 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1934 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-3].expr),(yyvsp[0].expr),"NOTLIKE"); }
#line 5439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1935 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 5445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1936 "screen.yacc" /* yacc.c:1646  */
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNULL"); }
#line 5451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1937 "screen.yacc" /* yacc.c:1646  */
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNOTNULL"); }
#line 5457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1938 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].expr); }
#line 5463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1939 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[-2].expr)); add_list_expr((yyval.expr),(yyvsp[0].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyval.expr),"BETWEEN"); }
#line 5469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1940 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyvsp[-1].expr),"IN"); }
#line 5475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1941 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_not_expr((yyvsp[0].expr)); }
#line 5481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1942 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[-1].expr); }
#line 5487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1945 "screen.yacc" /* yacc.c:1646  */
    {
(yyval.expr)=create_field_expr((yyvsp[0].str));
if (strcasecmp(currftag,(yyvsp[0].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
#line 5499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1952 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=create_int_expr(atoi((yyvsp[0].str))); printf("NUMBER VALUE : %s\n",(yyvsp[0].str)); }
#line 5505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1953 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=create_char_expr((yyvsp[0].str));}
#line 5511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1954 "screen.yacc" /* yacc.c:1646  */
    {
	(yyval.expr)=create_special_expr((yyvsp[0].str));
}
#line 5519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1962 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[0].expr));
	}
#line 5528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1966 "screen.yacc" /* yacc.c:1646  */
    {
		add_list_expr((yyvsp[-2].expr),(yyvsp[0].expr));
		(yyval.expr)=(yyvsp[-2].expr);
	}
#line 5537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1986 "screen.yacc" /* yacc.c:1646  */
    {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=(yyvsp[-5].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=(yyvsp[-1].col_list);
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=(yyvsp[-3].intval);
	}
#line 5550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1996 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[0].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[0].column).colname;
	}
#line 5562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2003 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.col_list)=(yyvsp[-2].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[0].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[0].column).colname;
	}
#line 5574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2012 "screen.yacc" /* yacc.c:1646  */
    {
	(yyval.column).tabname=strdup((yyvsp[-2].str));
	(yyval.column).colname=strdup((yyvsp[0].str));
}
#line 5583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2015 "screen.yacc" /* yacc.c:1646  */
    {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile((yyvsp[0].str),"",0);
        tabname=A4GL_get_found_in_tab();

	(yyval.column).tabname=strdup(tabname);
	(yyval.column).colname=strdup((yyvsp[0].str));
}
#line 5597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2034 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_BEFORE;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[-3].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[-1].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[0].at_block);
	}
#line 5609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2041 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_AFTER;
		(yyval.control_block)->s_control_block_u.befaft=(yyvsp[-3].befact);
		(yyval.control_block)->s_control_block_u.befaft->column_list=(yyvsp[-1].col_list);
		(yyval.control_block)->s_control_block_u.befaft->cmds=(yyvsp[0].at_block);

	}
#line 5622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2049 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONBEGINNING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[0].fcall);
	}
#line 5632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2054 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.control_block)=malloc(sizeof(struct s_control_block));
		(yyval.control_block)->cbtype=E_CB_ONENDING;
		(yyval.control_block)->s_control_block_u.onbegend=(yyvsp[0].fcall);
	}
#line 5642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2062 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_ABORT;
	}
#line 5651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2066 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_COMMENTS;
		(yyval.at_action)->u_action_u.cmd_comment=(yyvsp[0].at_comments);
	}
#line 5661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2071 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_IF;
		(yyval.at_action)->u_action_u.cmd_if=(yyvsp[0].at_if);
	}
#line 5671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2076 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_LET;
		(yyval.at_action)->u_action_u.cmd_let=(yyvsp[0].at_let);
	}
#line 5681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2081 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_NEXTFIELD;
		(yyval.at_action)->u_action_u.cmd_nextfield=(yyvsp[0].at_nextfield);
	}
#line 5691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2086 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_FUNC_CALL;
		(yyval.at_action)->u_action_u.cmd_call=(yyvsp[0].fcall);
	}
#line 5701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2091 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_action)=malloc(sizeof(struct u_action));
		(yyval.at_action)->type=ACTION_TYPE_BLOCK;
		(yyval.at_action)->u_action_u.cmd_block=(yyvsp[0].at_block);

	}
#line 5712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2100 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_if)=malloc(sizeof(struct s_at_if));
		(yyval.at_if)->test_condition=(yyvsp[-3].expr);
		(yyval.at_if)->if_true=(yyvsp[-1].at_action);
		(yyval.at_if)->if_false=(yyvsp[0].at_action);
	}
#line 5723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2109 "screen.yacc" /* yacc.c:1646  */
    {(yyval.at_action)=0;}
#line 5729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2110 "screen.yacc" /* yacc.c:1646  */
    {	
		(yyval.at_action)=(yyvsp[0].at_action);
	}
#line 5737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2119 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_let)=malloc(sizeof(struct s_at_let));
			(yyval.at_let)->field_tag=create_field_expr((yyvsp[-2].str));
			(yyval.at_let)->value=(yyvsp[0].expr);
		}
#line 5747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2127 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[0].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
#line 5757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2133 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=create_field_expr((yyvsp[0].str));
			(yyval.at_nextfield)->isexitnow=0;
		}
#line 5767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2139 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
#line 5777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2145 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.at_nextfield)=malloc(sizeof(struct s_at_nextfield));
			(yyval.at_nextfield)->field_tag=0;
			(yyval.at_nextfield)->isexitnow=1;
		}
#line 5787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2153 "screen.yacc" /* yacc.c:1646  */
    {
		 (yyval.at_block)= (yyvsp[-1].at_block);
	}
#line 5795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2158 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_block)=malloc(sizeof(struct s_at_block));
		(yyval.at_block)->actions.actions_len=0;
		(yyval.at_block)->actions.actions_val=0;

		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[0].at_action);

	}
#line 5810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2168 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_block)=(yyvsp[-1].at_block);
		(yyval.at_block)->actions.actions_len++;
		(yyval.at_block)->actions.actions_val=realloc( (yyval.at_block)->actions.actions_val, sizeof((yyval.at_block)->actions.actions_val[0])*(yyval.at_block)->actions.actions_len);
		(yyval.at_block)->actions.actions_val[(yyval.at_block)->actions.actions_len-1].uaction=(yyvsp[0].at_action);
		}
#line 5821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2178 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[0].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=0;
	}
#line 5832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2184 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[0].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=0;
	}
#line 5843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2190 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[0].str)));
		(yyval.at_comments)->hasbell=0;
		(yyval.at_comments)->isreverse=1;
	}
#line 5854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2196 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.at_comments)=malloc(sizeof(struct s_at_comments));
		(yyval.at_comments)->comment=strdup(A4GL_strip_quotes((yyvsp[0].str)));
		(yyval.at_comments)->hasbell=1;
		(yyval.at_comments)->isreverse=1;
	}
#line 5865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2206 "screen.yacc" /* yacc.c:1646  */
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
#line 5882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2218 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[0].intval);
	}
#line 5892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2226 "screen.yacc" /* yacc.c:1646  */
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
#line 5909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2238 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.befact)->befaftlist.befaftlist_len++;
		(yyval.befact)->befaftlist.befaftlist_val=realloc((yyval.befact)->befaftlist.befaftlist_val, sizeof((yyval.befact)->befaftlist.befaftlist_val[0])*(yyval.befact)->befaftlist.befaftlist_len);
		(yyval.befact)->befaftlist.befaftlist_val[(yyval.befact)->befaftlist.befaftlist_len-1]=(yyvsp[0].intval);
	}
#line 5919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2246 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_EDITADD;}
#line 5925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2247 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_EDITUPDATE;}
#line 5931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2248 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_REMOVE;}
#line 5937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2252 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_EDITADD;}
#line 5943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2253 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_ADD;}
#line 5949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2254 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_UPDATE;}
#line 5955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2255 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_QUERY;}
#line 5961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2256 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_REMOVE;}
#line 5967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2257 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_DISPLAY;}
#line 5973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2258 "screen.yacc" /* yacc.c:1646  */
    {(yyval.intval)=E_BA_EDITUPDATE;}
#line 5979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2261 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.col_list)=malloc(sizeof(struct s_column_list));
		(yyval.col_list)->columns.columns_len=1;
		(yyval.col_list)->columns.columns_val=malloc(sizeof(struct s_column));
		(yyval.col_list)->columns.columns_val[0].tabname=(yyvsp[0].column).tabname;
		(yyval.col_list)->columns.columns_val[0].colname=(yyvsp[0].column).colname;
	}
#line 5991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2268 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.col_list)=(yyvsp[-2].col_list);
		(yyval.col_list)->columns.columns_len++;
		(yyval.col_list)->columns.columns_val=realloc((yyval.col_list)->columns.columns_val, sizeof(struct s_column)*(yyval.col_list)->columns.columns_len);
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].tabname=(yyvsp[0].column).tabname;
		(yyval.col_list)->columns.columns_val[(yyval.col_list)->columns.columns_len-1].colname=(yyvsp[0].column).colname;
	}
#line 6003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2279 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.column).tabname=strdup((yyvsp[-2].str));
		(yyval.column).colname=strdup((yyvsp[0].str));
	}
#line 6012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2283 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.column).tabname=strdup("");
		(yyval.column).colname=strdup((yyvsp[0].str));
	}
#line 6021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2290 "screen.yacc" /* yacc.c:1646  */
    {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup((yyvsp[-3].str));
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup((yyvsp[-1].str));
	}
#line 6032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2298 "screen.yacc" /* yacc.c:1646  */
    {
			(yyval.fcall)=malloc(sizeof(struct s_at_call));
			memset((yyval.fcall),0,sizeof(struct s_at_call));
			(yyval.fcall)->fname=strdup((yyvsp[-1].str));
			(yyval.fcall)->list_parameters.list_parameters_len=0;
			(yyval.fcall)->list_parameters.list_parameters_val=0;
	}
#line 6044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2304 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.fcall)=(yyvsp[-2].fcall);
		if ((yyvsp[-1].el)) {
			listitem *l;
			(yyval.fcall)->list_parameters.list_parameters_len=(yyvsp[-1].el)->nlist;
			l=(yyvsp[-1].el)->expr_list;
			(yyval.fcall)->list_parameters.list_parameters_val=l;
		}
	}
#line 6058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2316 "screen.yacc" /* yacc.c:1646  */
    {(yyval.el)=0;}
#line 6064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2317 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.el)=(yyvsp[0].el);
	}
#line 6072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2323 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.el)=malloc(sizeof(struct local_expr_list));
		(yyval.el)->nlist=1;
		(yyval.el)->expr_list=malloc(sizeof((yyval.el)->expr_list[0]));
		(yyval.el)->expr_list[0]=(yyvsp[0].expr);
	}
#line 6083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2329 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.el)=(yyvsp[-2].el);
		(yyval.el)->nlist++;
		(yyval.el)->expr_list=realloc((yyval.el)->expr_list, sizeof((yyval.el)->expr_list[0])*(yyval.el)->nlist);
		(yyval.el)->expr_list[(yyval.el)->nlist-1]=(yyvsp[0].expr);
	}
#line 6094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2337 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=(yyvsp[0].expr);
	}
#line 6102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2345 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str));}
#line 6108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2350 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"AND");}
#line 6114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2351 "screen.yacc" /* yacc.c:1646  */
    {strcpy((yyval.str),"OR");}
#line 6120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2367 "screen.yacc" /* yacc.c:1646  */
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[0].expr),"-"); }
#line 6126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2369 "screen.yacc" /* yacc.c:1646  */
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[0].expr),"+"); }
#line 6132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 2370 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].expr); }
#line 6138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 2371 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_not_expr((yyvsp[0].expr)); }
#line 6144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 2372 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[-1].expr); }
#line 6150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 2373 "screen.yacc" /* yacc.c:1646  */
    { 
			(yyval.expr)=create_fcall((yyvsp[-3].str),(yyvsp[-1].el));
	}
#line 6158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 2376 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_field_expr((yyvsp[0].str)); }
#line 6164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 2377 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 2378 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 2379 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 2380 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 2381 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 2382 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 2383 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 2384 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 2385 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-3].expr),(yyvsp[0].expr),"NOTLIKE"); }
#line 6218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 2386 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
#line 6224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 2387 "screen.yacc" /* yacc.c:1646  */
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNULL"); }
#line 6230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 2388 "screen.yacc" /* yacc.c:1646  */
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNOTNULL"); }
#line 6236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 2389 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[-2].expr)); add_list_expr((yyval.expr),(yyvsp[0].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyval.expr),"BETWEEN"); }
#line 6242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 2390 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyvsp[-1].expr),"IN"); }
#line 6248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 2391 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-5].expr),(yyvsp[-1].expr),"NOTIN"); }
#line 6254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 2397 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_field_expr((yyvsp[0].str)); }
#line 6260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 2398 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=create_int_expr(atoi((yyvsp[0].str))); }
#line 6266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 2399 "screen.yacc" /* yacc.c:1646  */
    {(yyval.expr)=create_char_expr((yyvsp[0].str));}
#line 6272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 2400 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_special_expr((yyvsp[0].str)); }
#line 6278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 2401 "screen.yacc" /* yacc.c:1646  */
    { (yyval.expr)=create_special_expr((yyvsp[0].str));}
#line 6284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 2404 "screen.yacc" /* yacc.c:1646  */
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[0].expr));
	}
#line 6293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 2408 "screen.yacc" /* yacc.c:1646  */
    {
		add_list_expr((yyvsp[-2].expr),(yyvsp[0].expr));
		(yyval.expr)=(yyvsp[-2].expr);
	}
#line 6302 "y.tab.c" /* yacc.c:1646  */
    break;


#line 6306 "y.tab.c" /* yacc.c:1646  */
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
#line 2420 "screen.yacc" /* yacc.c:1906  */



#include "lex.a4gl_form_yy.c"



/* =========================== EOF ============================ */



