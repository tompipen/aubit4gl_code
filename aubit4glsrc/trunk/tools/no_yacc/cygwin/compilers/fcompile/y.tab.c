/* A Bison parser, made by GNU Bison 2.2.  */

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
#define YYBISON_VERSION "2.2"

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
     CH = 258,
     GRAPH_CH = 259,
     KW_COMPOSITES = 260,
     INSTRUCTIONS = 261,
     ATTRIBUTES = 262,
     DATABASE = 263,
     BY = 264,
     KW_SCREEN_TITLE = 265,
     KW_SCREEN = 266,
     KW_SIZE = 267,
     OPEN_SQUARE = 268,
     KW_END = 269,
     CLOSE_SQUARE = 270,
     NUMBER_VALUE = 271,
     NAMED = 272,
     OPEN_BRACE = 273,
     CLOSE_BRACE = 274,
     TITLE = 275,
     FORMONLY = 276,
     COMMENT = 277,
     DYNAMIC = 278,
     COLON = 279,
     ATSIGN = 280,
     DOT = 281,
     WITHOUT = 282,
     KW_NULL = 283,
     INPUT = 284,
     TABLES = 285,
     PIPE = 286,
     EQUAL = 287,
     CHAR_VALUE = 288,
     SEMICOLON = 289,
     LOOKUP = 290,
     JOINING = 291,
     OPEN_BRACKET = 292,
     CLOSE_BRACKET = 293,
     STAR = 294,
     DIVIDE = 295,
     PLUS = 296,
     MINUS = 297,
     RECORD = 298,
     COMMA = 299,
     THROUGH = 300,
     TYPE = 301,
     DELIMITERS = 302,
     KW_CHAR = 303,
     KW_INT = 304,
     KW_DATE = 305,
     KW_FLOAT = 306,
     SMALLFLOAT = 307,
     SMALLINT = 308,
     KW_DECIMAL = 309,
     MONEY = 310,
     DATETIME = 311,
     INTERVAL = 312,
     LIKE = 313,
     BLACK = 314,
     BLUE = 315,
     GREEN = 316,
     CYAN = 317,
     RED = 318,
     MAGENTA = 319,
     WHITE = 320,
     YELLOW = 321,
     NORMAL = 322,
     REVERSE = 323,
     LEFT = 324,
     BOLD = 325,
     BLINK = 326,
     UNDERLINE = 327,
     DIM = 328,
     AUTONEXT = 329,
     COLOR = 330,
     COMMENTS = 331,
     DEFAULT = 332,
     VALIDATE = 333,
     DISPLAY = 334,
     DOWNSHIFT = 335,
     UPSHIFT = 336,
     FORMAT = 337,
     INCLUDE = 338,
     INVISIBLE = 339,
     NOUPDATE = 340,
     NOENTRY = 341,
     PICTURE = 342,
     PROGRAM = 343,
     REQUIRED = 344,
     QUERYCLEAR = 345,
     VERIFY = 346,
     WORDWRAP = 347,
     COMPRESS = 348,
     NONCOMPRESS = 349,
     TO = 350,
     AS = 351,
     SERIAL = 352,
     KW_BYTE = 353,
     KW_TEXT = 354,
     VARCHAR = 355,
     SQL_VAR = 356,
     KW_NONSPACE = 357,
     SQLONLY = 358,
     WIDGET = 359,
     CONFIG = 360,
     KW_NL = 361,
     COMPARISON = 362,
     LESSTHAN = 363,
     GREATERTHAN = 364,
     KWOR = 365,
     KWAND = 366,
     KWAND1 = 367,
     KWWHERE = 368,
     KWNOT = 369,
     KWBETWEEN = 370,
     KWIN = 371,
     XVAL = 372,
     KWNULLCHK = 373,
     KWNOTNULLCHK = 374,
     YEAR = 375,
     MONTH = 376,
     DAY = 377,
     HOUR = 378,
     MINUTE = 379,
     SECOND = 380,
     FRACTION = 381,
     LISTBOX = 382,
     BUTTON = 383,
     KW_PANEL = 384,
     DISPLAYONLY = 385,
     ALLOWING = 386,
     KW_WS = 387,
     KW_TAB = 388,
     KW_MASTER_OF = 389,
     KW_BEFORE = 390,
     KW_AFTER = 391,
     KW_EDITADD = 392,
     KW_EDITUPDATE = 393,
     KW_REMOVE = 394,
     KW_OF = 395,
     KW_ADD = 396,
     KW_UPDATE = 397,
     KW_QUERY = 398,
     KW_ON_ENDING = 399,
     KW_ON_BEGINNING = 400,
     KW_CALL = 401,
     KW_BELL = 402,
     KW_ABORT = 403,
     KW_LET = 404,
     KW_EXITNOW = 405,
     KW_NEXTFIELD = 406,
     KW_IF = 407,
     KW_THEN = 408,
     KW_ELSE = 409,
     KW_BEGIN = 410,
     KW_TOTAL = 411,
     KW_RIGHT = 412,
     KW_ZEROFILL = 413,
     KW_USES_EXTENDED = 414,
     SPECIAL_DBNAME = 415,
     KW_ACTION = 416
   };
#endif
/* Tokens.  */
#define CH 258
#define GRAPH_CH 259
#define KW_COMPOSITES 260
#define INSTRUCTIONS 261
#define ATTRIBUTES 262
#define DATABASE 263
#define BY 264
#define KW_SCREEN_TITLE 265
#define KW_SCREEN 266
#define KW_SIZE 267
#define OPEN_SQUARE 268
#define KW_END 269
#define CLOSE_SQUARE 270
#define NUMBER_VALUE 271
#define NAMED 272
#define OPEN_BRACE 273
#define CLOSE_BRACE 274
#define TITLE 275
#define FORMONLY 276
#define COMMENT 277
#define DYNAMIC 278
#define COLON 279
#define ATSIGN 280
#define DOT 281
#define WITHOUT 282
#define KW_NULL 283
#define INPUT 284
#define TABLES 285
#define PIPE 286
#define EQUAL 287
#define CHAR_VALUE 288
#define SEMICOLON 289
#define LOOKUP 290
#define JOINING 291
#define OPEN_BRACKET 292
#define CLOSE_BRACKET 293
#define STAR 294
#define DIVIDE 295
#define PLUS 296
#define MINUS 297
#define RECORD 298
#define COMMA 299
#define THROUGH 300
#define TYPE 301
#define DELIMITERS 302
#define KW_CHAR 303
#define KW_INT 304
#define KW_DATE 305
#define KW_FLOAT 306
#define SMALLFLOAT 307
#define SMALLINT 308
#define KW_DECIMAL 309
#define MONEY 310
#define DATETIME 311
#define INTERVAL 312
#define LIKE 313
#define BLACK 314
#define BLUE 315
#define GREEN 316
#define CYAN 317
#define RED 318
#define MAGENTA 319
#define WHITE 320
#define YELLOW 321
#define NORMAL 322
#define REVERSE 323
#define LEFT 324
#define BOLD 325
#define BLINK 326
#define UNDERLINE 327
#define DIM 328
#define AUTONEXT 329
#define COLOR 330
#define COMMENTS 331
#define DEFAULT 332
#define VALIDATE 333
#define DISPLAY 334
#define DOWNSHIFT 335
#define UPSHIFT 336
#define FORMAT 337
#define INCLUDE 338
#define INVISIBLE 339
#define NOUPDATE 340
#define NOENTRY 341
#define PICTURE 342
#define PROGRAM 343
#define REQUIRED 344
#define QUERYCLEAR 345
#define VERIFY 346
#define WORDWRAP 347
#define COMPRESS 348
#define NONCOMPRESS 349
#define TO 350
#define AS 351
#define SERIAL 352
#define KW_BYTE 353
#define KW_TEXT 354
#define VARCHAR 355
#define SQL_VAR 356
#define KW_NONSPACE 357
#define SQLONLY 358
#define WIDGET 359
#define CONFIG 360
#define KW_NL 361
#define COMPARISON 362
#define LESSTHAN 363
#define GREATERTHAN 364
#define KWOR 365
#define KWAND 366
#define KWAND1 367
#define KWWHERE 368
#define KWNOT 369
#define KWBETWEEN 370
#define KWIN 371
#define XVAL 372
#define KWNULLCHK 373
#define KWNOTNULLCHK 374
#define YEAR 375
#define MONTH 376
#define DAY 377
#define HOUR 378
#define MINUTE 379
#define SECOND 380
#define FRACTION 381
#define LISTBOX 382
#define BUTTON 383
#define KW_PANEL 384
#define DISPLAYONLY 385
#define ALLOWING 386
#define KW_WS 387
#define KW_TAB 388
#define KW_MASTER_OF 389
#define KW_BEFORE 390
#define KW_AFTER 391
#define KW_EDITADD 392
#define KW_EDITUPDATE 393
#define KW_REMOVE 394
#define KW_OF 395
#define KW_ADD 396
#define KW_UPDATE 397
#define KW_QUERY 398
#define KW_ON_ENDING 399
#define KW_ON_BEGINNING 400
#define KW_CALL 401
#define KW_BELL 402
#define KW_ABORT 403
#define KW_LET 404
#define KW_EXITNOW 405
#define KW_NEXTFIELD 406
#define KW_IF 407
#define KW_THEN 408
#define KW_ELSE 409
#define KW_BEGIN 410
#define KW_TOTAL 411
#define KW_RIGHT 412
#define KW_ZEROFILL 413
#define KW_USES_EXTENDED 414
#define SPECIAL_DBNAME 415
#define KW_ACTION 416




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

#include <wchar.h>	/* utf8 */

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
int A4GL_get_attr_from_string (char *s);
/* extern FILE *yyin; */
int in_screen_section=0;
int dtype_size=0;
char *rm_dup_quotes(char *s) ;
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *chk_alias(char *s);
/* extern char *char_val(char*s); */
int A4GL_form_wcswidth(char *mbs);	/* utf8 */

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

int A4GL_form_wcswidth(char *mbs) {	/* utf8 */
    wchar_t *wstr;
    size_t retc, mlen, wlen, width;
    mlen = strlen(mbs);
    wstr = acl_malloc2((mlen+1)*sizeof(wchar_t));
    retc = mbstowcs(wstr, mbs, mlen+1);
    wlen = wcslen(wstr);
    width = wcswidth(wstr, wlen);
    free(wstr);
    return width;
}



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
#line 87 "screen.yacc"
{
	char	str[1024];
	u_expression *expr;
}
/* Line 193 of yacc.c.  */
#line 514 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 527 "y.tab.c"

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
#define YYLAST   3761

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  133
/* YYNRULES -- Number of rules.  */
#define YYNRULES  638
/* YYNRULES -- Number of states.  */
#define YYNSTATES  876

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   416

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
     155,   156,   157,   158,   159,   160,   161
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    35,    37,    41,    43,    47,    49,    52,    53,    57,
      58,    63,    64,    65,    66,    76,    77,    79,    80,    83,
      88,    89,    91,    93,    96,    98,   100,   102,   104,   106,
     108,   110,   112,   114,   116,   118,   120,   123,   124,   129,
     131,   132,   137,   138,   142,   144,   147,   151,   154,   155,
     158,   160,   164,   168,   174,   178,   182,   186,   188,   191,
     192,   197,   199,   202,   206,   207,   208,   215,   216,   220,
     226,   230,   232,   233,   239,   243,   246,   251,   254,   259,
     263,   265,   270,   273,   275,   277,   281,   285,   289,   291,
     295,   297,   302,   305,   307,   310,   311,   314,   316,   320,
     322,   327,   332,   336,   340,   344,   350,   354,   360,   362,
     364,   368,   374,   378,   382,   386,   388,   393,   395,   397,
     399,   401,   405,   409,   411,   413,   415,   417,   419,   421,
     423,   426,   429,   431,   433,   435,   437,   440,   442,   444,
     446,   448,   450,   452,   454,   456,   458,   460,   462,   464,
     466,   468,   470,   472,   473,   474,   479,   481,   484,   486,
     489,   492,   493,   503,   516,   518,   520,   522,   523,   526,
     527,   529,   530,   532,   534,   539,   541,   545,   546,   548,
     550,   554,   558,   562,   566,   568,   572,   574,   576,   577,
     579,   581,   584,   586,   588,   590,   591,   596,   598,   600,
     602,   604,   606,   608,   611,   614,   617,   620,   622,   624,
     626,   628,   630,   632,   636,   638,   641,   644,   646,   648,
     652,   656,   658,   660,   664,   668,   672,   676,   678,   679,
     683,   689,   690,   694,   695,   699,   701,   704,   706,   708,
     710,   712,   714,   716,   719,   721,   722,   726,   728,   730,
     732,   734,   736,   738,   740,   742,   745,   746,   750,   751,
     753,   756,   758,   762,   766,   770,   774,   778,   782,   787,
     791,   794,   797,   799,   805,   811,   814,   818,   820,   822,
     824,   826,   828,   830,   834,   843,   845,   849,   853,   855,
     857,   863,   869,   872,   875,   877,   879,   881,   883,   885,
     887,   889,   895,   896,   899,   901,   906,   909,   913,   916,
     920,   924,   926,   929,   932,   936,   940,   942,   945,   947,
     950,   952,   954,   956,   958,   960,   962,   964,   966,   968,
     970,   972,   976,   980,   982,   987,   993,   994,   996,   998,
    1002,  1004,  1006,  1010,  1014,  1015,  1017,  1019,  1023,  1026,
    1029,  1031,  1034,  1038,  1043,  1047,  1051,  1055,  1059,  1063,
    1067,  1071,  1075,  1079,  1084,  1088,  1091,  1094,  1100,  1106,
    1108,  1110,  1112,  1114,  1116,  1118,  1120,  1124,  1126,  1128,
    1130,  1132,  1134,  1136,  1138,  1140,  1142,  1144,  1146,  1148,
    1150,  1152,  1154,  1156,  1158,  1160,  1162,  1164,  1166,  1168,
    1170,  1172,  1174,  1176,  1178,  1180,  1182,  1184,  1186,  1188,
    1190,  1192,  1194,  1196,  1198,  1200,  1202,  1204,  1206,  1208,
    1210,  1212,  1214,  1216,  1218,  1220,  1222,  1224,  1226,  1228,
    1230,  1232,  1234,  1236,  1238,  1240,  1242,  1244,  1246,  1248,
    1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,  1268,
    1270,  1272,  1274,  1276,  1278,  1280,  1282,  1284,  1286,  1288,
    1290,  1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,  1308,
    1310,  1312,  1314,  1316,  1318,  1320,  1322,  1324,  1326,  1328,
    1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,  1348,
    1350,  1352,  1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,
    1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,
    1390,  1392,  1394,  1396,  1398,  1400,  1402,  1404,  1406,  1408,
    1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,
    1430,  1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,
    1450,  1452,  1454,  1456,  1458,  1460,  1462,  1464,  1466,  1468,
    1470,  1472,  1474,  1476,  1478,  1480,  1482,  1484,  1486,  1488,
    1490,  1492,  1494,  1496,  1498,  1500,  1502,  1504,  1506,  1508,
    1510,  1512,  1514,  1516,  1518,  1520,  1522,  1524,  1526,  1528,
    1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,
    1550,  1552,  1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,
    1570,  1572,  1574,  1576,  1578,  1580,  1582,  1584,  1586,  1588,
    1590,  1592,  1594,  1596,  1598,  1600,  1602,  1604,  1606,  1608,
    1610,  1612,  1614,  1616,  1618,  1620,  1622,  1624,  1626
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     163,     0,    -1,   164,   168,   187,   192,   216,    -1,     8,
      21,    -1,     8,   167,    27,    28,    29,    -1,     8,    21,
      27,    28,    29,    -1,     8,   167,    -1,    17,    -1,   293,
      -1,    17,    -1,   294,    -1,   160,    -1,   160,    25,   166,
      -1,   165,    -1,   165,    25,   166,    -1,   169,    -1,   168,
     169,    -1,    -1,    11,   170,   172,    -1,    -1,    10,    33,
     171,   172,    -1,    -1,    -1,    -1,   177,   173,   176,    18,
     174,   179,    19,   175,   178,    -1,    -1,   159,    -1,    -1,
      12,    16,    -1,    12,    16,     9,    16,    -1,    -1,    14,
      -1,   181,    -1,   179,   181,    -1,   166,    -1,   180,    -1,
     183,    -1,   133,    -1,     4,    -1,    31,    -1,    33,    -1,
     182,    -1,   132,    -1,   106,    -1,   102,    -1,     3,    -1,
     182,     3,    -1,    -1,    13,   184,   185,    15,    -1,   235,
      -1,    -1,   185,    31,   186,   235,    -1,    -1,    30,   188,
     178,    -1,   189,    -1,   188,   189,    -1,   188,    44,   189,
      -1,   166,   190,    -1,    -1,    32,   191,    -1,   166,    -1,
     166,    24,   166,    -1,   166,    25,   166,    -1,   166,    25,
     166,    24,   166,    -1,   166,    26,   166,    -1,    33,    26,
     166,    -1,     7,   193,   178,    -1,   194,    -1,   193,   194,
      -1,    -1,   234,   195,   196,    34,    -1,   197,    -1,   196,
     197,    -1,   196,    34,   197,    -1,    -1,    -1,    32,   198,
     203,   200,   199,   210,    -1,    -1,    13,    16,    15,    -1,
      13,    16,    44,    16,    15,    -1,   202,   114,    28,    -1,
     202,    -1,    -1,    46,    58,   166,    26,   166,    -1,    46,
      58,   166,    -1,    46,   237,    -1,    21,    26,   230,   201,
      -1,   130,   201,    -1,   130,   131,    29,   201,    -1,   166,
      26,   166,    -1,   166,    -1,    39,   166,    26,   166,    -1,
      39,   166,    -1,   234,    -1,   206,    -1,   205,    44,   206,
      -1,   204,    32,   207,    -1,   166,    26,   166,    -1,   166,
      -1,   166,    26,   166,    -1,   166,    -1,    39,   166,    26,
     166,    -1,    39,   166,    -1,    36,    -1,    44,    36,    -1,
      -1,    44,   211,    -1,   212,    -1,   211,    44,   212,    -1,
      74,    -1,    75,    32,   214,   253,    -1,    35,   205,   209,
     208,    -1,    76,    32,    33,    -1,    77,    32,   213,    -1,
      79,    58,   166,    -1,    79,    58,   166,    26,   166,    -1,
      78,    58,   166,    -1,    78,    58,   166,    26,   166,    -1,
      80,    -1,    81,    -1,    82,    32,    33,    -1,    83,    32,
      37,   238,    38,    -1,   104,    32,    33,    -1,   105,    32,
      33,    -1,   161,    32,   166,    -1,    84,    -1,    23,    12,
      32,    16,    -1,    23,    -1,   103,    -1,    86,    -1,    85,
      -1,    87,    32,    33,    -1,    88,    32,    33,    -1,    89,
      -1,    68,    -1,    91,    -1,    90,    -1,   158,    -1,   157,
      -1,    92,    -1,    92,    93,    -1,    92,    94,    -1,    33,
      -1,    16,    -1,   101,    -1,   215,    -1,   214,   215,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    16,    -1,    68,    -1,
      73,    -1,    67,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    -1,    -1,     6,   217,   218,   178,    -1,   219,
      -1,   218,   219,    -1,   220,    -1,   220,    34,    -1,    47,
      33,    -1,    -1,    11,    43,   221,   225,    37,   226,    38,
     222,   224,    -1,   129,    37,    16,    44,    16,    38,    95,
      37,    16,    44,    16,    38,    -1,   260,    -1,   281,    -1,
     265,    -1,    -1,    96,   127,    -1,    -1,    39,    -1,    -1,
      34,    -1,   166,    -1,   166,    13,    16,    15,    -1,   229,
      -1,   226,   227,   229,    -1,    -1,    44,    -1,   166,    -1,
     166,    26,   166,    -1,    21,    26,   166,    -1,   166,    26,
      39,    -1,    21,    26,    39,    -1,   228,    -1,   228,    45,
     228,    -1,   166,    -1,    14,    -1,    -1,   232,    -1,   233,
      -1,   232,   233,    -1,   132,    -1,   133,    -1,   166,    -1,
      -1,   231,   166,   236,   231,    -1,    48,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,   241,
      -1,    55,   241,    -1,    56,   248,    -1,    57,   242,    -1,
      97,    -1,    98,    -1,    99,    -1,   100,    -1,   128,    -1,
     240,    -1,   238,    44,   240,    -1,    16,    -1,    41,    16,
      -1,    42,    16,    -1,    33,    -1,    17,    -1,    17,    95,
      17,    -1,    17,    24,    17,    -1,     3,    -1,   239,    -1,
     239,    95,   239,    -1,   239,    24,   239,    -1,    33,    95,
      33,    -1,    33,    24,    33,    -1,    28,    -1,    -1,    37,
      16,    38,    -1,    37,    16,    44,    16,    38,    -1,    -1,
     245,    95,   247,    -1,    -1,    37,    16,    38,    -1,    16,
      -1,   246,   243,    -1,   120,    -1,   121,    -1,   122,    -1,
     123,    -1,   124,    -1,   125,    -1,   126,   252,    -1,   246,
      -1,    -1,   249,    95,   250,    -1,   251,    -1,   251,    -1,
     120,    -1,   121,    -1,   122,    -1,   123,    -1,   124,    -1,
     125,    -1,   126,   252,    -1,    -1,    37,   244,    38,    -1,
      -1,   254,    -1,   113,   255,    -1,   256,    -1,   256,   111,
     256,    -1,   256,   110,   256,    -1,   257,   107,   257,    -1,
     257,   108,   257,    -1,   257,   109,   257,    -1,   257,    58,
     257,    -1,   257,   114,    58,   257,    -1,   257,    32,   257,
      -1,   257,   118,    -1,   257,   119,    -1,   257,    -1,   257,
     115,   257,   111,   257,    -1,   257,   116,    37,   259,    38,
      -1,   114,   256,    -1,    37,   256,    38,    -1,   258,    -1,
      16,    -1,    33,    -1,   117,    -1,    17,    -1,   257,    -1,
     259,    44,   257,    -1,     5,   108,   261,   109,   223,   108,
     261,   109,    -1,   262,    -1,   261,    44,   262,    -1,   263,
      26,   264,    -1,   166,    -1,   166,    -1,   135,   275,   140,
     279,   273,    -1,   136,   276,   140,   279,   273,    -1,   145,
     282,    -1,   144,   282,    -1,   269,    -1,   274,    -1,   267,
      -1,   270,    -1,   271,    -1,   282,    -1,   272,    -1,   152,
     286,   153,   266,   268,    -1,    -1,   154,   266,    -1,   148,
      -1,   149,   234,    32,   286,    -1,   151,   234,    -1,   151,
      32,   234,    -1,   151,   150,    -1,   151,    32,   150,    -1,
     155,   273,    14,    -1,   266,    -1,   273,   266,    -1,    76,
      33,    -1,    76,   147,    33,    -1,    76,    68,    33,    -1,
     277,    -1,   275,   277,    -1,   278,    -1,   276,   278,    -1,
     137,    -1,   138,    -1,   139,    -1,   137,    -1,   141,    -1,
     142,    -1,   143,    -1,   139,    -1,    79,    -1,   138,    -1,
     280,    -1,   279,    44,   280,    -1,   263,    26,   264,    -1,
     264,    -1,   263,   134,   263,   224,    -1,   146,   166,    37,
     283,    38,    -1,    -1,   284,    -1,   285,    -1,   284,    44,
     285,    -1,   286,    -1,   289,    -1,   286,   111,   286,    -1,
     286,   110,   286,    -1,    -1,   288,    -1,   286,    -1,   288,
      44,   286,    -1,    42,   286,    -1,    41,   286,    -1,   291,
      -1,   114,   286,    -1,    37,   286,    38,    -1,   290,    37,
     287,    38,    -1,   156,   140,   234,    -1,   286,   107,   286,
      -1,   286,   108,   286,    -1,   286,   109,   286,    -1,   286,
      39,   286,    -1,   286,    41,   286,    -1,   286,    42,   286,
      -1,   286,    40,   286,    -1,   286,    58,   286,    -1,   286,
     114,    58,   286,    -1,   286,    32,   286,    -1,   286,   118,
      -1,   286,   119,    -1,   286,   115,   286,   111,   286,    -1,
     286,   116,    37,   292,    38,    -1,   166,    -1,   234,    -1,
      16,    -1,    33,    -1,   117,    -1,    28,    -1,   291,    -1,
     292,    44,   291,    -1,     5,    -1,     6,    -1,     7,    -1,
       8,    -1,     9,    -1,    12,    -1,    14,    -1,    20,    -1,
      22,    -1,    23,    -1,    28,    -1,    29,    -1,    30,    -1,
      35,    -1,    36,    -1,    43,    -1,    45,    -1,    46,    -1,
      47,    -1,    48,    -1,    49,    -1,    50,    -1,    51,    -1,
      52,    -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,
      62,    -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,
      67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,
      92,    -1,    93,    -1,    94,    -1,    95,    -1,    96,    -1,
      97,    -1,    98,    -1,    99,    -1,   100,    -1,   101,    -1,
     102,    -1,   103,    -1,   104,    -1,   105,    -1,   107,    -1,
     108,    -1,   109,    -1,   110,    -1,   111,    -1,   113,    -1,
     114,    -1,   115,    -1,   116,    -1,   117,    -1,   118,    -1,
     119,    -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,
     124,    -1,   125,    -1,   126,    -1,   127,    -1,   128,    -1,
     129,    -1,   130,    -1,   131,    -1,   134,    -1,   135,    -1,
     136,    -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,
     141,    -1,   142,    -1,   143,    -1,   144,    -1,   145,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   150,    -1,
     151,    -1,   152,    -1,   153,    -1,   154,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,   159,    -1,   161,    -1,
       5,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,
      27,    -1,    29,    -1,    30,    -1,    35,    -1,    36,    -1,
      43,    -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,
      49,    -1,    50,    -1,    51,    -1,    52,    -1,    53,    -1,
      54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
      69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,
      89,    -1,    90,    -1,    91,    -1,    92,    -1,    93,    -1,
      94,    -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,   101,    -1,   103,    -1,   104,    -1,
     105,    -1,   107,    -1,   108,    -1,   109,    -1,   110,    -1,
     111,    -1,   113,    -1,   114,    -1,   115,    -1,   116,    -1,
     118,    -1,   119,    -1,   120,    -1,   121,    -1,   122,    -1,
     123,    -1,   124,    -1,   125,    -1,   126,    -1,   127,    -1,
     128,    -1,   129,    -1,   131,    -1,   134,    -1,   135,    -1,
     136,    -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,
     141,    -1,   142,    -1,   143,    -1,   144,    -1,   145,    -1,
     146,    -1,   147,    -1,   148,    -1,   149,    -1,   151,    -1,
     152,    -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,
     157,    -1,   158,    -1,   159,    -1,   161,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   128,   129,   134,   135,   144,   145,   149,
     150,   154,   155,   156,   157,   160,   160,   163,   163,   176,
     176,   195,   197,   200,   195,   205,   205,   210,   211,   212,
     224,   225,   230,   231,   234,   249,   261,   262,   273,   284,
     297,   309,   320,   325,   328,   336,   337,   343,   342,   364,
     367,   367,   385,   386,   389,   390,   391,   394,   403,   404,
     407,   408,   409,   411,   412,   413,   419,   423,   423,   427,
     427,   437,   438,   439,   443,   447,   443,   484,   485,   489,
     497,   498,   501,   502,   505,   508,   513,   522,   534,   546,
     555,   563,   571,   581,   585,   586,   589,   592,   593,   597,
     598,   599,   600,   603,   604,   608,   609,   613,   613,   616,
     617,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   654,   655,   656,
     657,   658,   659,   660,   663,   666,   667,   668,   669,   670,
     673,   677,   683,   684,   685,   689,   690,   694,   695,   696,
     697,   698,   699,   700,   701,   703,   717,   718,   719,   720,
     721,   722,   723,   727,   728,   728,   733,   733,   735,   735,
     738,   748,   748,   751,   752,   753,   754,   758,   758,   760,
     760,   762,   762,   764,   767,   783,   786,   790,   791,   795,
     797,   799,   801,   803,   808,   808,   812,   815,   819,   819,
     822,   822,   826,   827,   840,   848,   848,   857,   861,   865,
     869,   873,   877,   881,   885,   889,   893,   897,   901,   905,
     909,   912,   919,   919,   924,   924,   924,   929,   936,   937,
     938,   939,   940,   941,   942,   943,   947,   951,   957,   958,
     959,   962,   963,   970,   972,   977,   985,   988,   989,   990,
     991,   992,   993,   994,  1000,  1002,  1003,  1006,  1009,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1025,  1027,  1034,  1034,
    1040,  1046,  1047,  1050,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,  1066,  1067,  1068,  1071,  1078,  1079,
    1080,  1085,  1088,  1092,  1104,  1107,  1108,  1111,  1114,  1117,
    1121,  1122,  1123,  1124,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1139,  1143,  1143,  1146,  1149,  1152,  1153,  1154,  1155,
    1159,  1162,  1163,  1168,  1169,  1170,  1175,  1175,  1179,  1179,
    1183,  1184,  1185,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
    1198,  1199,  1203,  1204,  1208,  1211,  1214,  1214,  1218,  1218,
    1221,  1226,  1227,  1228,  1233,  1234,  1237,  1238,  1242,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1266,
    1269,  1270,  1271,  1272,  1273,  1276,  1280,  1291,  1293,  1294,
    1295,  1296,  1297,  1299,  1300,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,
    1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,
    1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1356,  1357,  1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,
    1366,  1367,  1368,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1376,  1377,  1378,  1379,  1380,  1381,  1382,  1383,  1384,  1385,
    1386,  1387,  1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,
    1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,  1405,
    1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,
    1416,  1417,  1418,  1419,  1420,  1427,  1430,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1441,  1442,  1443,  1444,
    1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1453,  1454,
    1455,  1456,  1457,  1458,  1459,  1460,  1461,  1462,  1463,  1464,
    1465,  1466,  1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,
    1475,  1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,
    1485,  1486,  1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,
    1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,  1504,
    1505,  1506,  1507,  1508,  1509,  1510,  1511,  1512,  1513,  1514,
    1516,  1517,  1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,
    1526,  1527,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,
    1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1547,
    1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "GRAPH_CH", "KW_COMPOSITES",
  "INSTRUCTIONS", "ATTRIBUTES", "DATABASE", "BY", "KW_SCREEN_TITLE",
  "KW_SCREEN", "KW_SIZE", "OPEN_SQUARE", "KW_END", "CLOSE_SQUARE",
  "NUMBER_VALUE", "NAMED", "OPEN_BRACE", "CLOSE_BRACE", "TITLE",
  "FORMONLY", "COMMENT", "DYNAMIC", "COLON", "ATSIGN", "DOT", "WITHOUT",
  "KW_NULL", "INPUT", "TABLES", "PIPE", "EQUAL", "CHAR_VALUE", "SEMICOLON",
  "LOOKUP", "JOINING", "OPEN_BRACKET", "CLOSE_BRACKET", "STAR", "DIVIDE",
  "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", "TYPE", "DELIMITERS",
  "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", "SMALLFLOAT", "SMALLINT",
  "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", "LIKE", "BLACK", "BLUE",
  "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", "YELLOW", "NORMAL",
  "REVERSE", "LEFT", "BOLD", "BLINK", "UNDERLINE", "DIM", "AUTONEXT",
  "COLOR", "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY", "DOWNSHIFT",
  "UPSHIFT", "FORMAT", "INCLUDE", "INVISIBLE", "NOUPDATE", "NOENTRY",
  "PICTURE", "PROGRAM", "REQUIRED", "QUERYCLEAR", "VERIFY", "WORDWRAP",
  "COMPRESS", "NONCOMPRESS", "TO", "AS", "SERIAL", "KW_BYTE", "KW_TEXT",
  "VARCHAR", "SQL_VAR", "KW_NONSPACE", "SQLONLY", "WIDGET", "CONFIG",
  "KW_NL", "COMPARISON", "LESSTHAN", "GREATERTHAN", "KWOR", "KWAND",
  "KWAND1", "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK",
  "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND",
  "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY", "ALLOWING",
  "KW_WS", "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", "KW_EDITADD",
  "KW_EDITUPDATE", "KW_REMOVE", "KW_OF", "KW_ADD", "KW_UPDATE", "KW_QUERY",
  "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL", "KW_BELL", "KW_ABORT",
  "KW_LET", "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF", "KW_THEN", "KW_ELSE",
  "KW_BEGIN", "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL", "KW_USES_EXTENDED",
  "SPECIAL_DBNAME", "KW_ACTION", "$accept", "form_def", "database_section",
  "named_or_kw_st", "named_or_kw_any", "dbname", "screen_section",
  "screens_section", "@1", "@2", "screens_rest", "@3", "@4", "@5",
  "op_extended", "op_size", "op_end", "screen_layout", "some_text",
  "screen_element", "ch_list", "field", "@6", "field_element", "@7",
  "op_table_section", "table_def_list", "table_def", "opequal",
  "table_qualifier", "attribute_section", "field_tag_list", "field_tag",
  "@8", "fpart_list", "fpart", "@9", "@10", "op_att",
  "field_datatype_null", "field_datatype", "field_type", "lu_ft",
  "lu_ft_eq_c", "lu_ft_eq_c_i", "lu_fc", "lu_joincol", "lu_join",
  "op_field_desc", "op_desc_list", "desc", "def_val", "colors", "color",
  "op_instruction_section", "@11", "instruct_opts", "instruct_op_1",
  "instruct_op", "@12", "op_ltype", "op_star", "op_semi", "srec_dim",
  "srec_field_list", "op_comma", "field_list_item", "field_list_element",
  "field_name", "op_ws", "ws", "ws_elem", "field_tag_name",
  "field_tag_name_scr", "@13", "datatype", "incl_list", "number_value",
  "incl_entry", "opt_dec_ext", "opt_int_ext", "opt_unit_size", "dtfrac",
  "int_start", "int_start_unit", "int_end", "opt_dt_ext", "dt_start",
  "dt_end", "dtime_val", "opt_frac", "op_where", "where_clause", "clauses",
  "clause", "value", "fieldidentifier", "value_list", "composites",
  "comp_list", "comp_item", "table_name", "column_name", "control_block",
  "action", "if", "op_else", "abort", "let", "nextfield", "block",
  "actions", "comments", "bef_act_list", "aft_act_list", "bef_act",
  "aft_act", "column_list", "column_entry", "master_of", "func_call",
  "op_func_call_args", "func_call_args", "func_call_arg", "expression",
  "op_expression_list", "expression_list", "single_expression",
  "fcall_name", "evalue", "evalue_list", "st_kword", "any_kword", 0
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
     415,   416
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   162,   163,   164,   164,   164,   164,   165,   165,   166,
     166,   167,   167,   167,   167,   168,   168,   170,   169,   171,
     169,   173,   174,   175,   172,   176,   176,   177,   177,   177,
     178,   178,   179,   179,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   182,   182,   184,   183,   185,
     186,   185,   187,   187,   188,   188,   188,   189,   190,   190,
     191,   191,   191,   191,   191,   191,   192,   193,   193,   195,
     194,   196,   196,   196,   198,   199,   197,   200,   200,   200,
     201,   201,   202,   202,   202,   202,   203,   203,   203,   203,
     203,   203,   203,   204,   205,   205,   206,   207,   207,   208,
     208,   208,   208,   209,   209,   210,   210,   211,   211,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   213,   213,   213,   214,   214,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   216,   217,   216,   218,   218,   219,   219,
     220,   221,   220,   220,   220,   220,   220,   222,   222,   223,
     223,   224,   224,   225,   225,   226,   226,   227,   227,   228,
     228,   228,   228,   228,   229,   229,   230,   230,   231,   231,
     232,   232,   233,   233,   234,   236,   235,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   238,   238,   239,   239,   239,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   241,   241,
     241,   242,   242,   243,   243,   244,   245,   246,   246,   246,
     246,   246,   246,   246,   247,   248,   248,   249,   250,   251,
     251,   251,   251,   251,   251,   251,   252,   252,   253,   253,
     254,   255,   255,   255,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   257,   257,   257,
     257,   258,   259,   259,   260,   261,   261,   262,   263,   264,
     265,   265,   265,   265,   266,   266,   266,   266,   266,   266,
     266,   267,   268,   268,   269,   270,   271,   271,   271,   271,
     272,   273,   273,   274,   274,   274,   275,   275,   276,   276,
     277,   277,   277,   278,   278,   278,   278,   278,   278,   278,
     279,   279,   280,   280,   281,   282,   283,   283,   284,   284,
     285,   286,   286,   286,   287,   287,   288,   288,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   290,
     291,   291,   291,   291,   291,   292,   292,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     2,     0,     3,     0,
       4,     0,     0,     0,     9,     0,     1,     0,     2,     4,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     4,     1,
       0,     4,     0,     3,     1,     2,     3,     2,     0,     2,
       1,     3,     3,     5,     3,     3,     3,     1,     2,     0,
       4,     1,     2,     3,     0,     0,     6,     0,     3,     5,
       3,     1,     0,     5,     3,     2,     4,     2,     4,     3,
       1,     4,     2,     1,     1,     3,     3,     3,     1,     3,
       1,     4,     2,     1,     2,     0,     2,     1,     3,     1,
       4,     4,     3,     3,     3,     5,     3,     5,     1,     1,
       3,     5,     3,     3,     3,     1,     4,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     4,     1,     2,     1,     2,
       2,     0,     9,    12,     1,     1,     1,     0,     2,     0,
       1,     0,     1,     1,     4,     1,     3,     0,     1,     1,
       3,     3,     3,     3,     1,     3,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     0,     4,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     1,     3,
       3,     1,     1,     3,     3,     3,     3,     1,     0,     3,
       5,     0,     3,     0,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     3,     0,     1,
       2,     1,     3,     3,     3,     3,     3,     3,     4,     3,
       2,     2,     1,     5,     5,     2,     3,     1,     1,     1,
       1,     1,     1,     3,     8,     1,     3,     3,     1,     1,
       5,     5,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     2,     1,     4,     2,     3,     2,     3,
       3,     1,     2,     2,     3,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     4,     5,     0,     1,     1,     3,
       1,     1,     3,     3,     0,     1,     1,     3,     2,     2,
       1,     2,     3,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     2,     2,     5,     5,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,   387,   388,   389,   390,   391,   392,
     393,     7,   394,     3,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,    11,   514,    13,     6,     8,     1,     0,
      17,    52,    15,     0,     0,     0,     0,    19,    27,     0,
      16,     0,     0,   515,   516,   517,   518,   519,   520,     9,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,    12,    10,
      14,     0,    27,     0,    18,    21,    58,    30,    54,     0,
     163,     5,     4,    20,    28,    25,     0,    57,    31,     0,
      53,    55,   204,    30,    67,    69,   164,     2,     0,    26,
       0,     0,    60,    59,    56,    66,    68,     0,     0,    29,
      22,     0,     0,     0,     0,    74,     0,    71,   515,   519,
     533,   611,   614,   615,   623,   624,   298,    30,   166,   168,
     174,     0,   176,   175,     0,    65,    61,    62,    64,     0,
      70,    72,     0,   171,   170,     0,   330,   331,   332,     0,
     326,   338,   333,   339,   337,   334,   335,   336,     0,   328,
       0,   303,   302,   165,   167,   169,     0,    45,    38,    47,
      39,    40,    44,    43,    42,    37,    34,     0,    35,    32,
      41,    36,     0,   522,     0,    82,    90,    77,    73,     0,
     295,     0,     0,     0,     0,   327,     0,   329,     0,   181,
     198,    23,    33,    46,    63,     0,    92,     0,     0,    87,
      81,     0,     0,    75,     0,   179,     0,   183,     0,     0,
     299,     0,   343,     0,   340,     0,   346,   182,   344,   202,
     203,     0,     0,   199,   200,    49,    30,   197,   196,    82,
       0,   207,   208,   209,   210,   211,   212,   238,   238,   255,
     241,     0,   217,   218,   219,   220,   221,    85,    82,     0,
      89,     0,   105,   296,   180,     0,   299,   297,     0,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,   321,
     306,   304,   307,   308,   310,   300,   305,   309,   301,   381,
     384,   382,     0,     0,     0,   597,   383,   634,   204,   380,
       0,   347,   348,   350,   351,     0,   360,    48,    50,   205,
     201,    24,    86,    91,     0,   213,   214,   259,   260,   261,
     262,   263,   264,   266,   215,     0,   257,   247,   248,   249,
     250,   251,   252,   266,   216,     0,   243,    84,    88,    80,
      78,     0,     0,    76,     0,     0,   522,   189,   187,   194,
     185,     0,   342,   341,   323,     0,     0,     0,     0,   318,
     316,     0,     0,   322,     0,   359,   358,   361,     0,   345,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   375,   376,   354,   198,   198,
       0,     0,   265,     0,   253,     0,     0,   246,     0,     0,
     127,     0,   134,   109,     0,     0,     0,     0,     0,   118,
     119,     0,     0,   125,   130,   129,     0,     0,   133,   136,
     135,   139,   128,     0,     0,   138,   137,     0,   106,   107,
       0,   184,     0,     0,   177,   188,     0,     0,     0,   325,
     324,     0,   319,   317,     0,   320,   362,   364,   349,   374,
     368,   371,   369,   370,   372,   365,   366,   367,   353,   352,
       0,     0,     0,   356,     0,   355,    51,   206,   239,     0,
     245,     0,   256,   258,   254,   242,     0,    83,    79,     0,
       0,     0,    94,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   141,     0,     0,     0,     0,   294,
     193,   191,   192,   190,     0,   181,   186,   195,     0,   315,
     312,   373,     0,   385,     0,   363,     0,     0,   267,   244,
       0,     0,   103,     0,     0,   155,   147,   148,   149,   150,
     151,   152,   153,   154,   158,   156,   159,   160,   161,   162,
     157,   268,   145,   112,   143,   142,   144,   113,   116,   114,
     120,     0,   131,   132,   122,   123,   124,   108,   178,   172,
       0,     0,   311,   377,   378,     0,   357,   240,   126,    98,
      96,   104,    95,     0,   100,   111,     0,   146,   110,   269,
       0,     0,   231,   224,   228,   237,   227,     0,     0,     0,
     232,   222,     0,   313,   386,     0,   102,     0,   288,   291,
     289,     0,     0,   290,   270,   271,   282,   287,   117,   115,
       0,     0,     0,     0,   225,   226,   121,     0,     0,     0,
       0,    97,     0,    99,     0,   285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   280,   281,   230,   229,
     236,   235,   223,   234,   233,   173,   101,   286,   273,   272,
     279,   277,   274,   275,   276,     0,     0,     0,   278,     0,
     292,     0,   283,   284,     0,   293
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   135,   508,   136,   141,   142,   148,   282,
     284,   295,   344,   446,   310,   285,   300,   387,   388,   389,
     390,   391,   410,   441,   598,   151,   287,   288,   297,   313,
     290,   303,   304,   317,   326,   327,   349,   472,   423,   419,
     420,   397,   690,   691,   692,   780,   785,   734,   553,   638,
     639,   757,   751,   752,   307,   318,   337,   338,   339,   402,
     715,   475,   438,   428,   558,   646,   559,   560,   449,   442,
     443,   444,   509,   445,   599,   467,   799,   800,   801,   525,
     544,   607,   681,   545,   546,   685,   534,   535,   682,   536,
     602,   788,   789,   814,   815,   816,   817,   871,   340,   399,
     400,   401,   432,   342,   489,   490,   772,   491,   492,   493,
     494,   495,   496,   359,   368,   360,   369,   433,   434,   343,
     497,   510,   511,   512,   513,   674,   675,   514,   515,   516,
     724,   137,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -767
static const yytype_int16 yypact[] =
{
      26,  1118,    63,    68,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,    66,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,    75,  -767,    91,   101,  -767,  -767,   102,
    -767,    37,  -767,   111,  3135,  3135,   118,  -767,   137,  3135,
    -767,   151,   132,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,   134,   137,   149,  -767,  -767,   141,  1430,  -767,  3135,
     191,  -767,  -767,  -767,   167,    45,  1895,  -767,  -767,  3135,
    -767,  -767,  -767,  2050,  -767,  -767,  -767,  -767,   208,  -767,
     211,   204,   170,  -767,  -767,  -767,  -767,   199,  3290,  -767,
    -767,  3135,  3135,  3135,  3135,  -767,    58,  -767,   133,   197,
     214,   218,    64,   146,    99,    99,  -767,  2205,  -767,   215,
    -767,   122,  -767,  -767,   806,  -767,  -767,   233,  -767,  1585,
     199,  -767,  3135,  -767,  -767,   243,  -767,  -767,  -767,    30,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,    96,  -767,
    3135,  -767,  -767,  -767,  -767,  -767,  3135,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,   647,  -767,  -767,
     258,  -767,  3135,   238,  3135,   -36,   239,   253,  -767,   -23,
    -767,   241,  3135,   224,  3135,  -767,  3135,  -767,   232,   240,
     -58,  -767,  -767,  -767,  -767,  2360,   247,   387,   249,  -767,
     158,  3135,   259,  -767,  3135,   237,  3135,   273,   255,   274,
     267,   268,  -767,   -15,  -767,   -15,   961,  -767,  -767,  -767,
    -767,    27,  3135,   -58,  -767,  -767,   282,  -767,  -767,   251,
    3135,  -767,  -767,  -767,  -767,  -767,  -767,   262,   262,    61,
     246,  3135,  -767,  -767,  -767,  -767,  -767,  -767,   251,   276,
    -767,    18,   256,  -767,  -767,   193,  -767,  -767,   286,  3445,
     270,  3135,  3135,   -24,  -767,  3135,  1740,   961,   -64,  -767,
    -767,  -767,  -767,  -767,  -767,   -64,  -767,  -767,   -64,  -767,
    -767,  -767,   961,   961,   961,   961,  -767,   165,   277,  -767,
     278,   281,  -767,   212,  -767,   295,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,   299,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,   296,  -767,   223,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,   296,  -767,   248,   297,   310,  -767,  -767,
    -767,   328,   272,  -767,  3135,   330,   347,   348,    16,   338,
    -767,   289,  -767,  -767,  -767,   355,   358,   360,  2515,  -767,
    -767,    11,     5,  -767,   271,   212,   212,   212,  3135,  -767,
     961,   961,   961,   961,   961,   961,   961,   961,   961,   961,
     961,   961,   336,   961,   359,  -767,  -767,   961,   -58,   -58,
      39,   379,  -767,    61,  -767,   246,   381,  -767,  3135,   383,
     393,  3135,  -767,  -767,   367,   374,   375,   350,   351,  -767,
    -767,   380,   385,  -767,  -767,  -767,   386,   395,  -767,  -767,
    -767,    95,  -767,   396,   399,  -767,  -767,   400,   369,  -767,
      15,  -767,  2670,  2825,   315,  -767,  3445,  3445,   425,  -767,
    -767,   961,  -767,  -767,   -64,  -767,  -767,  -767,  -767,   212,
     212,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     961,   361,  1275,   212,   382,   419,  -767,  -767,  -767,   449,
    -767,   428,  -767,  -767,  -767,  -767,   435,  -767,  -767,   442,
     446,    32,  -767,  -767,   388,   450,    -3,  3135,  3135,   455,
     445,   456,   457,  -767,  -767,   458,   459,  3135,   272,  -767,
    -767,  -767,  -767,  -767,   366,   240,  -767,  -767,   480,   212,
     343,   212,   961,  -767,    94,  -767,   961,   462,  -767,  -767,
     485,  3135,  -767,  3600,  2980,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,   150,  -767,  -767,  -767,  -767,  -767,  -767,   479,   481,
    -767,   478,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
     460,   -64,  -767,   212,  -767,  1275,   212,  -767,  -767,   482,
    -767,   477,  -767,  3135,   484,  -767,    -2,  -767,  -767,  -767,
    3135,  3135,  -767,  -767,    -6,  -767,     2,   496,   497,   104,
       4,  -767,   498,  -767,  -767,  3135,   490,  3135,  -767,  -767,
    -767,    -2,    -2,  -767,  -767,    81,   307,  -767,  -767,  -767,
     500,   501,   493,   499,  -767,  -767,  -767,   478,    23,    23,
     491,  -767,  3135,  -767,   492,  -767,    -2,    -2,    24,    24,
      24,    24,    24,   473,    24,   502,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,  -767,
    -767,  -767,  -767,  -767,  -767,    24,   422,    24,  -767,    24,
    -767,   106,  -767,  -767,    24,  -767
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -767,  -767,  -767,  -767,  -144,  -767,  -767,   394,  -767,  -767,
     252,  -767,  -767,  -767,  -767,  -767,  -299,  -767,  -767,   153,
    -767,  -767,  -767,  -767,  -767,  -767,  -767,  -250,  -767,  -767,
    -767,  -767,   234,  -767,  -767,  -294,  -767,  -767,  -767,  -413,
    -767,  -767,  -767,  -767,  -197,  -767,  -767,  -767,  -767,  -767,
    -170,  -767,  -767,  -210,  -767,  -767,  -767,   205,  -767,  -767,
    -767,  -767,  -172,  -767,  -767,  -767,  -103,  -101,  -767,   -53,
    -767,   108,  -287,   -51,  -767,  -767,  -767,  -622,  -278,    97,
    -767,  -767,  -767,  -767,   -49,  -767,  -767,  -767,  -767,   -45,
      17,  -767,  -767,  -767,  -766,  -317,  -767,  -767,  -767,     7,
     135,  -310,  -409,  -767,  -492,  -767,  -767,  -767,  -767,  -767,
    -767,  -415,  -767,  -767,  -767,   203,   196,   159,    84,  -767,
    -107,  -767,  -767,   -13,  -480,  -767,  -767,  -767,  -767,  -661,
    -767,  -767,  -767
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -530
static const yytype_int16 yytable[] =
{
     278,   280,   305,   573,   315,   286,   573,   571,   341,   564,
     417,   723,   483,   754,   808,   809,   305,   477,   820,   655,
     498,   424,   574,   575,   576,   577,   822,   341,   828,   482,
     755,   810,   351,   550,     1,   811,   522,   301,   373,   793,
     808,   809,   517,   581,   565,   834,   835,   139,   140,   314,
     582,   583,   584,   585,   644,   548,   398,   810,   518,   424,
     645,   483,   551,   138,   797,   798,   409,   149,   732,   586,
     858,   859,   562,   572,   439,   440,   733,   678,   139,   140,
     573,   483,   370,   679,   484,   485,   425,   486,   487,   821,
     325,   488,   350,   143,   431,   418,   431,   823,   756,   829,
     144,   659,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   812,   671,   804,   813,   145,   673,   587,   588,
     589,   590,   591,   566,   709,   592,   593,   594,   146,   595,
     596,   370,   774,   484,   485,   147,   486,   487,   775,   152,
     488,   813,   826,   286,   873,   302,   281,   521,   827,   283,
     874,   370,   312,   484,   485,   286,   486,   487,   289,   302,
     488,   291,   720,   292,   654,   294,   735,   356,   357,   358,
     404,   719,   431,   296,   336,   361,   308,   345,   346,   347,
     348,   527,   528,   529,   530,   531,   532,   533,   703,   704,
     721,   836,   837,   336,   322,   323,   324,   306,   567,   570,
     386,   356,   357,   358,   309,   396,   853,   854,   336,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   319,   361,   408,   371,   372,   320,
     321,   325,   336,   362,   363,   364,   406,   365,   366,   367,
     353,   352,   773,   386,   581,   370,   776,   354,   414,   375,
     416,   582,   583,   584,   585,   355,   376,   392,   427,   403,
     430,   413,   430,   786,   415,   421,   422,   426,   429,   436,
     586,   448,   469,   450,   437,   471,   474,   470,   468,   803,
     336,   653,   476,   362,   363,   364,   478,   365,   366,   367,
     480,   657,   479,  -298,   481,   610,   298,   417,   519,   524,
     552,   554,   555,   581,   549,   578,   523,   611,   561,   656,
     582,   583,   584,   585,  -379,   600,   579,   547,   603,   587,
     588,   589,   590,   591,   693,   580,   592,   593,   594,   586,
     595,   596,   597,   601,   606,   557,   608,   476,   430,   838,
     612,   302,   302,   605,   609,   641,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   839,   537,   538,   539,   540,
     541,   542,   543,   642,   643,   632,   633,   634,   587,   588,
     589,   590,   591,   647,   648,   592,   593,   594,   649,   595,
     596,   650,   651,   581,   670,   680,   672,   686,   688,   694,
     582,   583,   584,   585,   735,   689,   695,   696,   697,   698,
     336,   714,   699,   708,   840,   841,   842,   700,   701,   586,
     725,   843,   844,   845,   302,   846,   847,   702,   705,   635,
     636,   706,   707,   637,   302,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   693,   736,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   747,   748,
     749,   750,   718,   726,   687,   727,   728,   302,   587,   588,
     589,   590,   722,   729,   730,   592,   593,   594,   731,   595,
     596,   792,   761,   753,   462,   463,   464,   465,   760,   762,
     763,   764,   765,   768,   793,   794,   770,   771,   711,   713,
     777,   778,   557,   557,   802,   790,   795,   791,   805,  -529,
     807,   796,   824,   825,   830,   466,   832,   848,   849,   797,
     798,   860,   861,   862,   863,   864,   850,   866,   302,   855,
     857,   865,   851,   869,   293,   150,   782,   316,   767,   867,
     412,   787,   374,   769,   717,   716,   677,   676,   868,   852,
     870,   520,   872,   758,   759,   526,   684,   875,   683,   473,
     604,   640,   405,   766,   407,   435,   563,   658,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   779,     0,   302,
     784,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,     0,     0,     0,     0,     0,     0,   806,
       0,     0,     0,     0,     0,     0,   818,   819,     0,     0,
     377,   378,   153,     0,     0,   154,   155,   156,   157,   158,
     379,   831,     0,   833,   159,     0,   411,   160,   161,   162,
     163,     0,     0,     0,   164,     0,   165,   166,   380,     0,
     381,     0,   167,   168,     0,     0,     0,     0,   856,     0,
     169,     0,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   382,
     227,   228,   229,   383,   230,   231,   232,   233,   234,     0,
     235,   236,   237,   238,     0,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,     0,   251,   384,
     385,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,     0,   268,   269,
     270,   271,   272,   273,   274,   275,   276,     0,   277,   377,
     378,   153,     0,     0,   154,   155,   156,   157,   158,   379,
       0,     0,     0,   159,     0,     0,   160,   161,   162,   163,
       0,     0,     0,   164,     0,   165,   166,   380,     0,   381,
       0,   167,   168,     0,     0,     0,     0,     0,     0,   169,
       0,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   382,   227,
     228,   229,   383,   230,   231,   232,   233,   234,     0,   235,
     236,   237,   238,     0,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,     0,   251,   384,   385,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,     0,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   153,   277,     0,   154,
     155,   156,   157,   158,     0,     0,     0,   499,   159,     0,
       0,   160,   161,   162,   163,     0,     0,     0,   164,   500,
     165,   166,     0,     0,   501,     0,   167,   168,   502,     0,
       0,     0,   503,   504,   169,     0,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,     0,   227,   228,   229,     0,   230,   231,
     232,   233,   234,     0,   235,   505,   237,   238,   506,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,     0,   251,     0,     0,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,     0,   268,   269,   270,   271,   272,   507,   274,   275,
     276,     0,   277,     4,     5,     6,     7,     8,     0,     0,
       9,     0,    10,     0,     0,    11,     0,     0,    12,    13,
      14,    15,     0,     0,     0,     0,    16,    17,    18,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     153,     0,     0,   154,   155,   156,   157,   158,     0,     0,
       0,   499,   159,     0,     0,   160,   161,   162,   163,     0,
       0,     0,   164,   500,   165,   166,     0,     0,   501,     0,
     167,   168,     0,     0,     0,     0,     0,     0,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,   506,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     0,     0,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   153,   277,     0,   154,   155,
     156,   157,   158,     0,   298,     0,     0,   159,     0,     0,
     160,   161,   162,   163,     0,     0,     0,   164,     0,   165,
     166,     0,     0,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,   169,   299,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,   227,   228,   229,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     153,   277,     0,   154,   155,   156,   157,   158,     0,     0,
       0,     0,   159,     0,     0,   160,   393,   162,   163,     0,
       0,     0,   164,     0,   165,   166,     0,     0,     0,     0,
     167,   168,     0,     0,   394,     0,     0,     0,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   395,   251,     0,     0,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   153,   277,     0,   154,   155,
     156,   157,   158,     0,     0,     0,     0,   159,     0,     0,
     160,   161,   162,   163,     0,     0,     0,   164,     0,   165,
     166,     0,   568,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,   169,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,   227,   228,   229,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     569,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     153,   277,     0,   154,   155,   156,   157,   158,     0,     0,
       0,     0,   159,     0,     0,   160,   161,   162,   163,     0,
       0,     0,   164,     0,   165,   166,     0,     0,   311,     0,
     167,   168,     0,     0,     0,     0,     0,     0,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     0,     0,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   153,   277,     0,   154,   155,
     156,   157,   158,     0,   298,     0,     0,   159,     0,     0,
     160,   161,   162,   163,     0,     0,     0,   164,     0,   165,
     166,     0,     0,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,   169,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,   227,   228,   229,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     328,   277,     0,   154,   155,   156,   329,   158,     0,   298,
       0,     0,   159,     0,     0,   160,   161,   162,   163,     0,
       0,     0,   164,     0,   165,   166,     0,     0,     0,     0,
     167,   168,     0,     0,     0,     0,     0,     0,   169,     0,
     170,   171,   330,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   331,     0,   251,     0,     0,   252,
     332,   333,   255,   256,   257,   258,   259,   260,   261,   334,
     335,   264,   265,   266,   267,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   153,   277,     0,   154,   155,
     156,   157,   158,     0,   447,     0,     0,   159,     0,     0,
     160,   161,   162,   163,     0,     0,     0,   164,     0,   165,
     166,     0,     0,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,   169,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,   227,   228,   229,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     153,   277,     0,   154,   155,   156,   157,   158,     0,     0,
       0,     0,   159,     0,     0,   160,   161,   162,   163,     0,
       0,     0,   164,     0,   165,   166,     0,     0,     0,     0,
     167,   168,     0,     0,     0,     0,     0,     0,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     0,     0,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   652,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   153,   277,     0,   154,   155,
     156,   157,   158,     0,     0,     0,     0,   159,     0,     0,
     160,   161,   162,   163,     0,     0,     0,   164,     0,   165,
     166,     0,     0,     0,     0,   167,   168,     0,     0,   710,
       0,     0,     0,   169,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,   227,   228,   229,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     153,   277,     0,   154,   155,   156,   157,   158,     0,     0,
       0,     0,   159,     0,     0,   160,   161,   162,   163,     0,
       0,     0,   164,     0,   165,   166,     0,     0,     0,     0,
     167,   168,     0,     0,   712,     0,     0,     0,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     0,     0,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   153,   277,     0,   154,   155,
     156,   157,   158,     0,     0,     0,     0,   159,     0,     0,
     160,   161,   162,   163,     0,     0,     0,   164,     0,   165,
     166,     0,     0,     0,     0,   167,   168,     0,     0,   783,
       0,     0,     0,   169,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,   227,   228,   229,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     153,   277,     0,   154,   155,   156,   157,   158,     0,     0,
       0,     0,   159,     0,     0,   160,   161,   162,   163,     0,
       0,     0,   164,     0,   165,   166,     0,     0,     0,     0,
     167,   168,     0,     0,     0,     0,     0,     0,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     0,     0,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   328,   277,     0,   154,   155,
     156,   329,   158,     0,     0,     0,     0,   159,     0,     0,
     160,   161,   162,   163,     0,     0,     0,   164,     0,   165,
     166,     0,     0,     0,     0,   167,   168,     0,     0,     0,
       0,     0,     0,   169,     0,   170,   171,   330,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,   227,   228,   229,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   331,
       0,   251,     0,     0,   252,   332,   333,   255,   256,   257,
     258,   259,   260,   261,   334,   335,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     153,   277,     0,   154,   155,   156,   157,   158,     0,     0,
       0,     0,   159,     0,     0,   160,   556,   162,   163,     0,
       0,     0,   164,     0,   165,   166,     0,     0,     0,     0,
     167,   168,     0,     0,     0,     0,     0,     0,   169,     0,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     0,   227,   228,
     229,     0,   230,   231,   232,   233,   234,     0,   235,   236,
     237,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,     0,   251,     0,     0,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,     0,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   153,   277,     0,   154,   155,
     156,   157,   158,     0,     0,     0,     0,   159,     0,     0,
     160,   161,   162,   163,     0,     0,     0,   164,     0,   165,
     166,     0,     0,     0,     0,   167,   781,     0,     0,     0,
       0,     0,     0,   169,     0,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,   227,   228,   229,     0,   230,   231,   232,
     233,   234,     0,   235,   236,   237,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       0,   251,     0,     0,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
       0,   268,   269,   270,   271,   272,   273,   274,   275,   276,
       0,   277
};

static const yytype_int16 yycheck[] =
{
     144,   145,   289,   495,   303,   149,   498,   487,   318,    33,
      46,   672,    76,    16,    16,    17,   303,   426,    24,    14,
     435,    44,   502,   503,   504,   505,    24,   337,    24,    44,
      33,    33,   326,    15,     8,    37,   449,   287,   337,    16,
      16,    17,    15,    32,    68,   811,   812,    10,    11,   299,
      39,    40,    41,    42,    38,   468,   350,    33,    31,    44,
      44,    76,    44,     0,    41,    42,   376,    30,    36,    58,
     836,   837,   481,   488,   132,   133,    44,    38,    10,    11,
     572,    76,   146,    44,   148,   149,   109,   151,   152,    95,
      32,   155,    34,    27,   404,   131,   406,    95,   101,    95,
      25,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   114,   593,   775,   117,    25,   597,   107,   108,
     109,   110,   111,   147,   109,   114,   115,   116,    27,   118,
     119,   146,    38,   148,   149,    33,   151,   152,    44,    28,
     155,   117,    38,   287,    38,   289,    28,   446,    44,    12,
      44,   146,   296,   148,   149,   299,   151,   152,     7,   303,
     155,    29,   654,    29,   153,    16,    16,   137,   138,   139,
     140,   651,   482,    32,   318,    79,     9,   321,   322,   323,
     324,   120,   121,   122,   123,   124,   125,   126,    93,    94,
     670,   110,   111,   337,    24,    25,    26,     6,   485,   486,
     344,   137,   138,   139,   159,   349,   828,   829,   352,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    16,    79,   370,   334,   335,    18,
      26,    32,   376,   137,   138,   139,   140,   141,   142,   143,
      43,   108,   722,   387,    32,   146,   726,    33,   392,    34,
     394,    39,    40,    41,    42,    37,   134,    24,   402,    16,
     404,     3,   406,   113,    26,    26,    13,    26,    44,    37,
      58,   415,   114,    26,    34,    16,    39,   421,    29,   771,
     424,   568,   426,   137,   138,   139,    13,   141,   142,   143,
      16,   578,    37,    26,    26,    23,    14,    46,   442,    37,
      44,   108,    16,    32,    28,   140,   450,    35,    38,    38,
      39,    40,    41,    42,    37,    16,    38,   461,    95,   107,
     108,   109,   110,   111,   611,    44,   114,   115,   116,    58,
     118,   119,    37,    37,    37,   479,    26,   481,   482,    32,
      68,   485,   486,    95,    16,    15,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    58,   120,   121,   122,   123,
     124,   125,   126,    26,    26,   103,   104,   105,   107,   108,
     109,   110,   111,    45,    95,   114,   115,   116,    33,   118,
     119,    33,    32,    32,    58,    16,    37,    16,    15,    32,
      39,    40,    41,    42,    16,    12,    32,    32,    58,    58,
     554,    96,    32,    44,   107,   108,   109,    32,    32,    58,
      38,   114,   115,   116,   568,   118,   119,    32,    32,   157,
     158,    32,    32,   161,   578,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   733,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    37,    44,   608,    16,    38,   611,   107,   108,
     109,   110,   111,    38,    32,   114,   115,   116,    32,   118,
     119,     3,    37,    33,    97,    98,    99,   100,    33,    33,
      33,    33,    33,   127,    16,    17,    16,   154,   642,   643,
      38,    16,   646,   647,    44,    26,    28,    26,    26,    32,
      26,    33,    16,    16,    16,   128,    26,    17,    17,    41,
      42,   838,   839,   840,   841,   842,    33,   844,   672,    38,
      38,    58,    33,   111,   282,   141,   733,   303,   708,    37,
     387,   751,   337,   715,   647,   646,   599,   598,   865,   827,
     867,   443,   869,   697,   698,   458,   605,   874,   603,   424,
     543,   554,   359,   707,   368,   406,   482,   580,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   731,    -1,   733,
     734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   775,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   783,
      -1,    -1,    -1,    -1,    -1,    -1,   790,   791,    -1,    -1,
       3,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,   805,    -1,   807,    17,    -1,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    -1,
      33,    -1,    35,    36,    -1,    -1,    -1,    -1,   832,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,   155,   156,   157,   158,   159,    -1,   161,     3,
       4,     5,    -1,    -1,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    27,    -1,    29,    30,    31,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,   113,
     114,   115,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,     5,   161,    -1,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,    28,
      29,    30,    -1,    -1,    33,    -1,    35,    36,    37,    -1,
      -1,    -1,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,   104,   105,    -1,   107,   108,
     109,   110,   111,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,   131,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,   151,   152,   153,   154,   155,   156,   157,   158,
     159,    -1,   161,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    14,    -1,    -1,    17,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    -1,   107,   108,   109,   110,   111,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
       5,    -1,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    16,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     5,   161,    -1,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       5,   161,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     5,   161,    -1,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       5,   161,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     5,   161,    -1,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       5,   161,    -1,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     5,   161,    -1,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       5,   161,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     5,   161,    -1,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       5,   161,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     5,   161,    -1,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       5,   161,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     5,   161,    -1,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       5,   161,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,    -1,   113,   114,
     115,   116,    -1,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,   131,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
     155,   156,   157,   158,   159,     5,   161,    -1,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,   108,   109,
     110,   111,    -1,   113,   114,   115,   116,    -1,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,   131,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,   155,   156,   157,   158,   159,
      -1,   161
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     8,   163,   164,     5,     6,     7,     8,     9,    12,
      14,    17,    20,    21,    22,    23,    28,    29,    30,    35,
      36,    43,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   107,   108,   109,   110,   111,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   165,   167,   293,     0,    10,
      11,   168,   169,    27,    25,    25,    27,    33,   170,    30,
     169,   187,    28,     5,     8,     9,    10,    11,    12,    17,
      20,    21,    22,    23,    27,    29,    30,    35,    36,    43,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   103,   104,   105,
     107,   108,   109,   110,   111,   113,   114,   115,   116,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   131,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   161,   166,   294,
     166,    28,   171,    12,   172,   177,   166,   188,   189,     7,
     192,    29,    29,   172,    16,   173,    32,   190,    14,    44,
     178,   189,   166,   193,   194,   234,     6,   216,     9,   159,
     176,    33,   166,   191,   189,   178,   194,   195,   217,    16,
      18,    26,    24,    25,    26,    32,   196,   197,     5,    11,
      47,   129,   135,   136,   144,   145,   166,   218,   219,   220,
     260,   263,   265,   281,   174,   166,   166,   166,   166,   198,
      34,   197,   108,    43,    33,    37,   137,   138,   139,   275,
     277,    79,   137,   138,   139,   141,   142,   143,   276,   278,
     146,   282,   282,   178,   219,    34,   134,     3,     4,    13,
      31,    33,   102,   106,   132,   133,   166,   179,   180,   181,
     182,   183,    24,    21,    39,   130,   166,   203,   197,   261,
     262,   263,   221,    16,   140,   277,   140,   278,   166,   263,
     184,    19,   181,     3,   166,    26,   166,    46,   131,   201,
     202,    26,    13,   200,    44,   109,    26,   166,   225,    44,
     166,   263,   264,   279,   280,   279,    37,    34,   224,   132,
     133,   185,   231,   232,   233,   235,   175,    14,   166,   230,
      26,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    97,    98,    99,   100,   128,   237,    29,   114,
     166,    16,   199,   262,    39,   223,   166,   264,    13,    37,
      16,    26,    44,    76,   148,   149,   151,   152,   155,   266,
     267,   269,   270,   271,   272,   273,   274,   282,   273,    16,
      28,    33,    37,    41,    42,   114,   117,   156,   166,   234,
     283,   284,   285,   286,   289,   290,   291,    15,    31,   166,
     233,   178,   201,   166,    37,   241,   241,   120,   121,   122,
     123,   124,   125,   126,   248,   249,   251,   120,   121,   122,
     123,   124,   125,   126,   242,   245,   246,   166,   201,    28,
      15,    44,    44,   210,   108,    16,    21,   166,   226,   228,
     229,    38,   264,   280,    33,    68,   147,   234,    32,   150,
     234,   286,   273,   266,   286,   286,   286,   286,   140,    38,
      44,    32,    39,    40,    41,    42,    58,   107,   108,   109,
     110,   111,   114,   115,   116,   118,   119,    37,   186,   236,
      16,    37,   252,    95,   252,    95,    37,   243,    26,    16,
      23,    35,    68,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   103,   104,   105,   157,   158,   161,   211,   212,
     261,    15,    26,    26,    38,    44,   227,    45,    95,    33,
      33,    32,   150,   234,   153,    14,    38,   234,   285,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
      58,   286,    37,   286,   287,   288,   235,   231,    38,    44,
      16,   244,   250,   251,   246,   247,    16,   166,    15,    12,
     204,   205,   206,   234,    32,    32,    32,    58,    58,    32,
      32,    32,    32,    93,    94,    32,    32,    32,    44,   109,
      39,   166,    39,   166,    96,   222,   229,   228,    37,   286,
     266,   286,   111,   291,   292,    38,    44,    16,    38,    38,
      32,    32,    36,    44,   209,    16,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   214,   215,    33,    16,    33,   101,   213,   166,   166,
      33,    37,    33,    33,    33,    33,   166,   212,   127,   224,
      16,   154,   268,   286,    38,    44,   286,    38,    16,   166,
     207,    36,   206,    39,   166,   208,   113,   215,   253,   254,
      26,    26,     3,    16,    17,    28,    33,    41,    42,   238,
     239,   240,    44,   266,   291,    26,   166,    26,    16,    17,
      33,    37,   114,   117,   255,   256,   257,   258,   166,   166,
      24,    95,    24,    95,    16,    16,    38,    44,    24,    95,
      16,   166,    26,   166,   256,   256,   110,   111,    32,    58,
     107,   108,   109,   114,   115,   116,   118,   119,    17,    17,
      33,    33,   240,   239,   239,    38,   166,    38,   256,   256,
     257,   257,   257,   257,   257,    58,   257,    37,   257,   111,
     257,   259,   257,    38,    44,   257
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
yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    const YYSTYPE * const yyvaluep;
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
yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    const YYSTYPE * const yyvaluep;
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
yy_reduce_print (YYSTYPE *yyvsp, 
		   int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule
		   )
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
#line 125 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 128 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:
#line 129 "screen.yacc"
    {the_form.dbname=((yyvsp[(2) - (5)].str));
if (A4GLF_open_db((yyvsp[(2) - (5)].str))) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 134 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 135 "screen.yacc"
    {the_form.dbname=acl_strdup((yyvsp[(2) - (2)].str));
if (A4GLF_open_db((yyvsp[(2) - (2)].str))) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 11:
#line 154 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 12:
#line 155 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 14:
#line 157 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 17:
#line 163 "screen.yacc"
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

  case 19:
#line 176 "screen.yacc"
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

  case 21:
#line 195 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 22:
#line 197 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 23:
#line 200 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 26:
#line 205 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 29:
#line 212 "screen.yacc"
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

  case 34:
#line 234 "screen.yacc"
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

  case 35:
#line 249 "screen.yacc"
    {
        //printf("%s %d %d %d %d %d %s\n","_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	if (lineno) {
        //A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
        A4GL_add_field("_label",colno+1,lineno,A4GL_form_wcswidth((yyvsp[(1) - (1)].str)),scr,0,(yyvsp[(1) - (1)].str)); /* utf8 */
	colno+=A4GL_form_wcswidth((yyvsp[(1) - (1)].str));		/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 36:
#line 261 "screen.yacc"
    { ltab=0; }
    break;

  case 37:
#line 262 "screen.yacc"
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

  case 38:
#line 273 "screen.yacc"
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

  case 39:
#line 284 "screen.yacc"
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

  case 40:
#line 297 "screen.yacc"
    {
	if (lineno) {
	//A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
	A4GL_add_field("_label",colno+1,lineno,A4GL_form_wcswidth((yyvsp[(1) - (1)].str)),scr,0,(yyvsp[(1) - (1)].str));	/* utf8 */
	colno+=A4GL_form_wcswidth((yyvsp[(1) - (1)].str));	/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 41:
#line 309 "screen.yacc"
    {
	if (lineno) {
	//A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
	A4GL_add_field("_label",colno+1,lineno,A4GL_form_wcswidth((yyvsp[(1) - (1)].str)),scr,0,(yyvsp[(1) - (1)].str));	/* utf8 */
	colno+=A4GL_form_wcswidth((yyvsp[(1) - (1)].str));	/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 42:
#line 320 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 43:
#line 325 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 44:
#line 328 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 45:
#line 336 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 46:
#line 337 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 47:
#line 343 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 48:
#line 350 "screen.yacc"
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

  case 49:
#line 364 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
			}
    break;

  case 50:
#line 367 "screen.yacc"
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

  case 51:
#line 378 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[(4) - (4)].str));
			}
    break;

  case 57:
#line 394 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[(1) - (2)].str));
A4GL_make_downshift((yyvsp[(2) - (2)].str));
clr_status();
A4GL_add_table((yyvsp[(2) - (2)].str),(yyvsp[(1) - (2)].str)); 
err_on_status();
}
    break;

  case 58:
#line 403 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 59:
#line 404 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(2) - (2)].str)); }
    break;

  case 60:
#line 407 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (1)].str));}
    break;

  case 61:
#line 408 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 62:
#line 410 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 63:
#line 411 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));}
    break;

  case 64:
#line 412 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));}
    break;

  case 69:
#line 427 "screen.yacc"
    {
	A4GL_make_downshift((yyvsp[(1) - (1)].str));
	strcpy(currftag,(yyvsp[(1) - (1)].str));
	fldno=A4GL_find_field((yyvsp[(1) - (1)].str));
}
    break;

  case 74:
#line 443 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 75:
#line 447 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 76:
#line 457 "screen.yacc"
    {
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

	A4GL_set_field(currftag,fld);
}
    break;

  case 78:
#line 485 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (3)].str));
}
    break;

  case 79:
#line 489 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[(2) - (5)].str));
	fld->subscripts[1]=atoi((yyvsp[(4) - (5)].str));
}
    break;

  case 80:
#line 497 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))+256); }
    break;

  case 81:
#line 498 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 82:
#line 501 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 83:
#line 502 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(5) - (5)].str),(yyvsp[(3) - (5)].str)));
		}
    break;

  case 84:
#line 505 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[(3) - (3)].str),""));
		}
    break;

  case 85:
#line 508 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[(2) - (2)].str));
		}
    break;

  case 86:
#line 513 "screen.yacc"
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

  case 87:
#line 522 "screen.yacc"
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

  case 88:
#line 534 "screen.yacc"
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

  case 89:
#line 546 "screen.yacc"
    {
	//printf("%s %s\n",$<str>1,$<str>3);
	fld->tabname=acl_strdup((yyvsp[(1) - (3)].str)); 
	fld->colname=acl_strdup((yyvsp[(3) - (3)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 90:
#line 555 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(1) - (1)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 91:
#line 563 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[(2) - (4)].str)); 
	fld->colname=acl_strdup((yyvsp[(4) - (4)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 92:
#line 571 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[(2) - (2)].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 109:
#line 616 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 110:
#line 617 "screen.yacc"
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

  case 112:
#line 638 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[(3) - (3)].str)); }
    break;

  case 113:
#line 639 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[(3) - (3)].str)); }
    break;

  case 114:
#line 640 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 115:
#line 641 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 116:
#line 642 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 117:
#line 643 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 118:
#line 644 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 119:
#line 645 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 120:
#line 646 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[(3) - (3)].str)); }
    break;

  case 121:
#line 647 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[(4) - (5)].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 122:
#line 648 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[(3) - (3)].str)); }
    break;

  case 123:
#line 649 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[(3) - (3)].str)); }
    break;

  case 124:
#line 650 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[(3) - (3)].str)); }
    break;

  case 125:
#line 651 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 126:
#line 652 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[(4) - (4)].str));
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 127:
#line 654 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 128:
#line 655 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 129:
#line 656 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 130:
#line 657 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 131:
#line 658 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[(3) - (3)].str)); }
    break;

  case 132:
#line 659 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[(3) - (3)].str)); }
    break;

  case 133:
#line 660 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 134:
#line 663 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 135:
#line 666 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 139:
#line 670 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 140:
#line 673 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 141:
#line 677 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 142:
#line 683 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 143:
#line 684 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 144:
#line 685 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[(1) - (1)].str));}
    break;

  case 146:
#line 690 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (2)].str))+atoi((yyvsp[(2) - (2)].str))); }
    break;

  case 147:
#line 694 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 148:
#line 695 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 149:
#line 696 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 150:
#line 697 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 151:
#line 698 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 152:
#line 699 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 153:
#line 700 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 154:
#line 701 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 155:
#line 703 "screen.yacc"
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

  case 156:
#line 717 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 157:
#line 718 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 158:
#line 719 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 159:
#line 720 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 160:
#line 721 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 161:
#line 722 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 162:
#line 723 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 164:
#line 728 "screen.yacc"
    {
}
    break;

  case 170:
#line 738 "screen.yacc"
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

  case 171:
#line 748 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 183:
#line 764 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (1)].str),1);
}
    break;

  case 184:
#line 767 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[(1) - (4)].str),atoi((yyvsp[(3) - (4)].str)));
}
    break;

  case 185:
#line 783 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[(1) - (1)].str));
}
    break;

  case 186:
#line 786 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 189:
#line 796 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[(1) - (1)].str),""); }
    break;

  case 190:
#line 798 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),""); }
    break;

  case 191:
#line 800 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[(3) - (3)].str),""); }
    break;

  case 192:
#line 802 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[(1) - (3)].str),"*",""); }
    break;

  case 193:
#line 804 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 195:
#line 808 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 196:
#line 812 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
}
    break;

  case 197:
#line 815 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 198:
#line 819 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:
#line 819 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 202:
#line 826 "screen.yacc"
    {colno++;}
    break;

  case 203:
#line 827 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 204:
#line 840 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[(1) - (1)].str));
	}
    break;

  case 205:
#line 848 "screen.yacc"
    {
	colno+=strlen((yyvsp[(2) - (2)].str));
}
    break;

  case 206:
#line 850 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (4)].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 207:
#line 857 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 208:
#line 861 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 209:
#line 865 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 210:
#line 869 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 211:
#line 873 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 212:
#line 877 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 213:
#line 881 "screen.yacc"
    {
	strcpy((yyval.str),"5");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 214:
#line 885 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 215:
#line 889 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 216:
#line 893 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[(2) - (2)].str));
}
    break;

  case 217:
#line 897 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 218:
#line 901 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 219:
#line 905 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 220:
#line 909 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 221:
#line 912 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 223:
#line 919 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
}
    break;

  case 226:
#line 924 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[(2) - (2)].str));}
    break;

  case 227:
#line 929 "screen.yacc"
    { 
	if (strlen((yyvsp[(1) - (1)].str))==2) {/* "" */
		sprintf((yyval.str),"NULL");
	} else {
		strcpy((yyval.str),A4GL_char_val((yyvsp[(1) - (1)].str))); 
	}
}
    break;

  case 228:
#line 936 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 229:
#line 937 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 230:
#line 938 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 231:
#line 939 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 233:
#line 941 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 234:
#line 942 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 235:
#line 943 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 236:
#line 947 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[(1) - (3)].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[(3) - (3)].str)));
}
    break;

  case 237:
#line 951 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 238:
#line 957 "screen.yacc"
    {sprintf((yyval.str),"%d",(16<<8) + 2);}
    break;

  case 239:
#line 958 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[(2) - (3)].str))+2)<<8)+2);}
    break;

  case 240:
#line 959 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[(2) - (5)].str))<<8)+atoi((yyvsp[(4) - (5)].str)));}
    break;

  case 241:
#line 962 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 242:
#line 964 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[(1) - (3)].str))*16)+atoi((yyvsp[(3) - (3)].str)));
	}
    break;

  case 243:
#line 970 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 244:
#line 972 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 245:
#line 977 "screen.yacc"
    {
if (atoi((yyvsp[(1) - (1)].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 246:
#line 985 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))*16+atoi((yyvsp[(1) - (2)].str)));}
    break;

  case 247:
#line 988 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 248:
#line 989 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 249:
#line 990 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 250:
#line 991 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 251:
#line 992 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 252:
#line 993 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 253:
#line 995 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 255:
#line 1002 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 256:
#line 1003 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (3)].str))*16+atoi((yyvsp[(3) - (3)].str)));}
    break;

  case 257:
#line 1006 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 258:
#line 1009 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 259:
#line 1013 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 260:
#line 1014 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 261:
#line 1015 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 262:
#line 1016 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 263:
#line 1017 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 264:
#line 1018 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 265:
#line 1020 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[(2) - (2)].str));
sprintf((yyval.str),"%d",atoi((yyvsp[(2) - (2)].str))+6); }
    break;

  case 266:
#line 1025 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 267:
#line 1027 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[(2) - (3)].str));
strcpy((yyval.str),(yyvsp[(2) - (3)].str));
}
    break;

  case 268:
#line 1034 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 269:
#line 1034 "screen.yacc"
    {
(yyval.expr)=(yyvsp[(1) - (1)].expr);
}
    break;

  case 270:
#line 1040 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[(2) - (2)].expr);
	}
    break;

  case 272:
#line 1047 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  
	}
    break;

  case 273:
#line 1050 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  
	}
    break;

  case 274:
#line 1056 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 275:
#line 1057 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 276:
#line 1058 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 277:
#line 1059 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 278:
#line 1060 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 279:
#line 1061 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 280:
#line 1062 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 281:
#line 1063 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 282:
#line 1064 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 283:
#line 1065 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 284:
#line 1066 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 285:
#line 1067 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 286:
#line 1068 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 287:
#line 1071 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str));
if (strcasecmp(currftag,(yyvsp[(1) - (1)].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 288:
#line 1078 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); printf("NUMBER VALUE : %s\n",(yyvsp[(1) - (1)].str)); }
    break;

  case 289:
#line 1079 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 290:
#line 1080 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));
}
    break;

  case 292:
#line 1088 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 293:
#line 1092 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;

  case 352:
#line 1227 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"AND");  }
    break;

  case 353:
#line 1228 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),"OR");  }
    break;

  case 358:
#line 1242 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"-"); }
    break;

  case 359:
#line 1244 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[(2) - (2)].expr),"+"); }
    break;

  case 360:
#line 1245 "screen.yacc"
    { (yyval.expr)=(yyvsp[(1) - (1)].expr); }
    break;

  case 361:
#line 1246 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[(2) - (2)].expr)); }
    break;

  case 362:
#line 1247 "screen.yacc"
    { (yyval.expr)=(yyvsp[(2) - (3)].expr); }
    break;

  case 363:
#line 1248 "screen.yacc"
    { (yyval.expr)=(yyvsp[(3) - (4)].expr); }
    break;

  case 364:
#line 1249 "screen.yacc"
    { (yyval.expr)=(yyvsp[(3) - (3)].expr); }
    break;

  case 365:
#line 1250 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 366:
#line 1251 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 367:
#line 1252 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 368:
#line 1253 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 369:
#line 1254 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 370:
#line 1255 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 371:
#line 1256 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 372:
#line 1257 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 373:
#line 1258 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (4)].expr),(yyvsp[(4) - (4)].expr),"NOTLIKE"); }
    break;

  case 374:
#line 1259 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr),(yyvsp[(2) - (3)].str)); }
    break;

  case 375:
#line 1260 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNULL"); }
    break;

  case 376:
#line 1261 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (2)].expr),p,"ISNOTNULL"); }
    break;

  case 377:
#line 1262 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[(3) - (5)].expr)); add_list_expr((yyval.expr),(yyvsp[(5) - (5)].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 378:
#line 1263 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[(1) - (5)].expr),(yyvsp[(4) - (5)].expr),"IN"); }
    break;

  case 380:
#line 1269 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 381:
#line 1270 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[(1) - (1)].str))); }
    break;

  case 382:
#line 1271 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[(1) - (1)].str));}
    break;

  case 383:
#line 1272 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str)); }
    break;

  case 384:
#line 1273 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[(1) - (1)].str));}
    break;

  case 385:
#line 1276 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[(1) - (1)].expr));
	}
    break;

  case 386:
#line 1280 "screen.yacc"
    {
		add_list_expr((yyvsp[(1) - (3)].expr),(yyvsp[(3) - (3)].expr));
		(yyval.expr)=(yyvsp[(1) - (3)].expr);
	}
    break;


/* Line 1267 of yacc.c.  */
#line 4900 "y.tab.c"
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
  return yyresult;
}


#line 1561 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




