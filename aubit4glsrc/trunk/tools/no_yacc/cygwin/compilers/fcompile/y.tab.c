/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 77 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 493 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 505 "y.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  96
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3132

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  162
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  131
/* YYNRULES -- Number of rules. */
#define YYNRULES  469
/* YYNRULES -- Number of states. */
#define YYNSTATES  706

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   416

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    35,    39,    41,    44,    45,    49,    50,    55,    56,
      57,    58,    68,    69,    71,    72,    75,    80,    81,    83,
      85,    88,    90,    92,    94,    96,    98,   100,   102,   104,
     106,   108,   110,   112,   115,   116,   121,   123,   124,   129,
     130,   134,   136,   139,   143,   146,   147,   150,   152,   156,
     160,   166,   170,   174,   178,   180,   183,   184,   189,   191,
     194,   198,   199,   200,   207,   208,   212,   218,   222,   224,
     225,   231,   235,   238,   243,   246,   251,   255,   257,   262,
     265,   267,   269,   273,   277,   281,   283,   287,   289,   294,
     297,   299,   302,   303,   306,   308,   312,   314,   319,   324,
     328,   332,   336,   342,   346,   352,   354,   356,   360,   366,
     370,   374,   378,   380,   385,   387,   389,   391,   393,   397,
     401,   403,   405,   407,   409,   411,   413,   415,   418,   421,
     423,   425,   427,   429,   432,   434,   436,   438,   440,   442,
     444,   446,   448,   450,   452,   454,   456,   458,   460,   462,
     464,   465,   466,   471,   473,   476,   478,   481,   484,   485,
     495,   508,   510,   512,   514,   515,   518,   519,   521,   522,
     524,   526,   531,   533,   537,   538,   540,   542,   546,   550,
     554,   558,   560,   564,   566,   568,   569,   571,   573,   576,
     578,   580,   582,   583,   588,   590,   592,   594,   596,   598,
     600,   603,   606,   609,   612,   614,   616,   618,   620,   622,
     624,   628,   630,   633,   636,   638,   640,   644,   648,   650,
     652,   656,   660,   664,   668,   670,   671,   675,   681,   682,
     686,   687,   691,   693,   696,   698,   700,   702,   704,   706,
     708,   711,   713,   714,   718,   720,   722,   724,   726,   728,
     730,   732,   734,   737,   738,   742,   743,   745,   748,   750,
     754,   758,   762,   766,   770,   774,   779,   783,   786,   789,
     791,   797,   803,   806,   810,   812,   814,   816,   818,   820,
     822,   826,   835,   837,   841,   845,   847,   849,   855,   861,
     864,   867,   869,   871,   873,   875,   877,   879,   881,   887,
     888,   891,   893,   898,   901,   905,   908,   912,   916,   918,
     921,   924,   928,   932,   934,   937,   939,   942,   944,   946,
     948,   950,   952,   954,   956,   958,   960,   962,   964,   968,
     972,   974,   979,   985,   986,   988,   990,   994,   996,   998,
    1002,  1006,  1007,  1009,  1011,  1015,  1018,  1021,  1023,  1026,
    1030,  1035,  1039,  1043,  1047,  1051,  1055,  1059,  1063,  1067,
    1071,  1076,  1080,  1083,  1086,  1092,  1098,  1100,  1102,  1104,
    1106,  1108,  1110,  1112,  1116,  1118,  1120,  1122,  1124,  1126,
    1128,  1130,  1132,  1134,  1136,  1138,  1140,  1142,  1144,  1146,
    1148,  1150,  1152,  1154,  1156,  1158,  1160,  1162,  1164,  1166,
    1168,  1170,  1172,  1174,  1176,  1178,  1180,  1182,  1184,  1186,
    1188,  1190,  1192,  1194,  1196,  1198,  1200,  1202,  1204,  1206,
    1208,  1210,  1212,  1214,  1216,  1218,  1220,  1222,  1224,  1226,
    1228,  1230,  1232,  1234,  1236,  1238,  1240,  1242,  1244,  1246,
    1248,  1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,
    1268,  1270,  1272,  1274,  1276,  1278,  1280,  1282,  1284,  1286
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     163,     0,    -1,   164,   167,   186,   191,   215,    -1,     8,
      21,    -1,     8,   166,    27,    28,    29,    -1,     8,    21,
      27,    28,    29,    -1,     8,   166,    -1,    17,    -1,   292,
      -1,   160,    -1,   165,    -1,   165,    25,   165,    -1,   168,
      -1,   167,   168,    -1,    -1,    11,   169,   171,    -1,    -1,
      10,    33,   170,   171,    -1,    -1,    -1,    -1,   176,   172,
     175,    18,   173,   178,    19,   174,   177,    -1,    -1,   159,
      -1,    -1,    12,    16,    -1,    12,    16,     9,    16,    -1,
      -1,    14,    -1,   180,    -1,   178,   180,    -1,   165,    -1,
     179,    -1,   182,    -1,   133,    -1,     4,    -1,    31,    -1,
      33,    -1,   181,    -1,   132,    -1,   106,    -1,   102,    -1,
       3,    -1,   181,     3,    -1,    -1,    13,   183,   184,    15,
      -1,   234,    -1,    -1,   184,    31,   185,   234,    -1,    -1,
      30,   187,   177,    -1,   188,    -1,   187,   188,    -1,   187,
      44,   188,    -1,   165,   189,    -1,    -1,    32,   190,    -1,
     165,    -1,   165,    24,   165,    -1,   165,    25,   165,    -1,
     165,    25,   165,    24,   165,    -1,   165,    26,   165,    -1,
      33,    26,   165,    -1,     7,   192,   177,    -1,   193,    -1,
     192,   193,    -1,    -1,   233,   194,   195,    34,    -1,   196,
      -1,   195,   196,    -1,   195,    34,   196,    -1,    -1,    -1,
      32,   197,   202,   199,   198,   209,    -1,    -1,    13,    16,
      15,    -1,    13,    16,    44,    16,    15,    -1,   201,   114,
      28,    -1,   201,    -1,    -1,    46,    58,   165,    26,   165,
      -1,    46,    58,   165,    -1,    46,   236,    -1,    21,    26,
     229,   200,    -1,   130,   200,    -1,   130,   131,    29,   200,
      -1,   165,    26,   165,    -1,   165,    -1,    39,   165,    26,
     165,    -1,    39,   165,    -1,   233,    -1,   205,    -1,   204,
      44,   205,    -1,   203,    32,   206,    -1,   165,    26,   165,
      -1,   165,    -1,   165,    26,   165,    -1,   165,    -1,    39,
     165,    26,   165,    -1,    39,   165,    -1,    36,    -1,    44,
      36,    -1,    -1,    44,   210,    -1,   211,    -1,   210,    44,
     211,    -1,    74,    -1,    75,    32,   213,   252,    -1,    35,
     204,   208,   207,    -1,    76,    32,    33,    -1,    77,    32,
     212,    -1,    79,    58,   165,    -1,    79,    58,   165,    26,
     165,    -1,    78,    58,   165,    -1,    78,    58,   165,    26,
     165,    -1,    80,    -1,    81,    -1,    82,    32,    33,    -1,
      83,    32,    37,   237,    38,    -1,   104,    32,    33,    -1,
     105,    32,    33,    -1,   161,    32,   165,    -1,    84,    -1,
      23,    12,    32,    16,    -1,    23,    -1,   103,    -1,    86,
      -1,    85,    -1,    87,    32,    33,    -1,    88,    32,    33,
      -1,    89,    -1,    68,    -1,    91,    -1,    90,    -1,   158,
      -1,   157,    -1,    92,    -1,    92,    93,    -1,    92,    94,
      -1,    33,    -1,    16,    -1,   101,    -1,   214,    -1,   213,
     214,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,    66,    -1,    16,    -1,
      68,    -1,    73,    -1,    67,    -1,    69,    -1,    70,    -1,
      71,    -1,    72,    -1,    -1,    -1,     6,   216,   217,   177,
      -1,   218,    -1,   217,   218,    -1,   219,    -1,   219,    34,
      -1,    47,    33,    -1,    -1,    11,    43,   220,   224,    37,
     225,    38,   221,   223,    -1,   129,    37,    16,    44,    16,
      38,    95,    37,    16,    44,    16,    38,    -1,   259,    -1,
     280,    -1,   264,    -1,    -1,    96,   127,    -1,    -1,    39,
      -1,    -1,    34,    -1,   165,    -1,   165,    13,    16,    15,
      -1,   228,    -1,   225,   226,   228,    -1,    -1,    44,    -1,
     165,    -1,   165,    26,   165,    -1,    21,    26,   165,    -1,
     165,    26,    39,    -1,    21,    26,    39,    -1,   227,    -1,
     227,    45,   227,    -1,   165,    -1,    14,    -1,    -1,   231,
      -1,   232,    -1,   231,   232,    -1,   132,    -1,   133,    -1,
     165,    -1,    -1,   230,   165,   235,   230,    -1,    48,    -1,
      49,    -1,    50,    -1,    51,    -1,    52,    -1,    53,    -1,
      54,   240,    -1,    55,   240,    -1,    56,   247,    -1,    57,
     241,    -1,    97,    -1,    98,    -1,    99,    -1,   100,    -1,
     128,    -1,   239,    -1,   237,    44,   239,    -1,    16,    -1,
      41,    16,    -1,    42,    16,    -1,    33,    -1,    17,    -1,
      17,    95,    17,    -1,    17,    24,    17,    -1,     3,    -1,
     238,    -1,   238,    95,   238,    -1,   238,    24,   238,    -1,
      33,    95,    33,    -1,    33,    24,    33,    -1,    28,    -1,
      -1,    37,    16,    38,    -1,    37,    16,    44,    16,    38,
      -1,    -1,   244,    95,   246,    -1,    -1,    37,    16,    38,
      -1,    16,    -1,   245,   242,    -1,   120,    -1,   121,    -1,
     122,    -1,   123,    -1,   124,    -1,   125,    -1,   126,   251,
      -1,   245,    -1,    -1,   248,    95,   249,    -1,   250,    -1,
     250,    -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,
     124,    -1,   125,    -1,   126,   251,    -1,    -1,    37,   243,
      38,    -1,    -1,   253,    -1,   113,   254,    -1,   255,    -1,
     255,   111,   255,    -1,   255,   110,   255,    -1,   256,   107,
     256,    -1,   256,   108,   256,    -1,   256,   109,   256,    -1,
     256,    58,   256,    -1,   256,   114,    58,   256,    -1,   256,
      32,   256,    -1,   256,   118,    -1,   256,   119,    -1,   256,
      -1,   256,   115,   256,   111,   256,    -1,   256,   116,    37,
     258,    38,    -1,   114,   255,    -1,    37,   255,    38,    -1,
     257,    -1,    16,    -1,    33,    -1,   117,    -1,    17,    -1,
     256,    -1,   258,    44,   256,    -1,     5,   108,   260,   109,
     222,   108,   260,   109,    -1,   261,    -1,   260,    44,   261,
      -1,   262,    26,   263,    -1,   165,    -1,   165,    -1,   135,
     274,   140,   278,   272,    -1,   136,   275,   140,   278,   272,
      -1,   145,   281,    -1,   144,   281,    -1,   268,    -1,   273,
      -1,   266,    -1,   269,    -1,   270,    -1,   281,    -1,   271,
      -1,   152,   285,   153,   265,   267,    -1,    -1,   154,   265,
      -1,   148,    -1,   149,   233,    32,   285,    -1,   151,   233,
      -1,   151,    32,   233,    -1,   151,   150,    -1,   151,    32,
     150,    -1,   155,   272,    14,    -1,   265,    -1,   272,   265,
      -1,    76,    33,    -1,    76,   147,    33,    -1,    76,    68,
      33,    -1,   276,    -1,   274,   276,    -1,   277,    -1,   275,
     277,    -1,   137,    -1,   138,    -1,   139,    -1,   137,    -1,
     141,    -1,   142,    -1,   143,    -1,   139,    -1,    79,    -1,
     138,    -1,   279,    -1,   278,    44,   279,    -1,   262,    26,
     263,    -1,   263,    -1,   262,   134,   262,   223,    -1,   146,
     165,    37,   282,    38,    -1,    -1,   283,    -1,   284,    -1,
     283,    44,   284,    -1,   285,    -1,   288,    -1,   285,   111,
     285,    -1,   285,   110,   285,    -1,    -1,   287,    -1,   285,
      -1,   287,    44,   285,    -1,    42,   285,    -1,    41,   285,
      -1,   290,    -1,   114,   285,    -1,    37,   285,    38,    -1,
     289,    37,   286,    38,    -1,   156,   140,   233,    -1,   285,
     107,   285,    -1,   285,   108,   285,    -1,   285,   109,   285,
      -1,   285,    39,   285,    -1,   285,    41,   285,    -1,   285,
      42,   285,    -1,   285,    40,   285,    -1,   285,    58,   285,
      -1,   285,   114,    58,   285,    -1,   285,    32,   285,    -1,
     285,   118,    -1,   285,   119,    -1,   285,   115,   285,   111,
     285,    -1,   285,   116,    37,   291,    38,    -1,   165,    -1,
     233,    -1,    16,    -1,    33,    -1,   117,    -1,    28,    -1,
     290,    -1,   291,    44,   290,    -1,    96,    -1,    74,    -1,
      59,    -1,    71,    -1,    70,    -1,    60,    -1,   110,    -1,
     111,    -1,   107,    -1,   128,    -1,     9,    -1,    75,    -1,
      22,    -1,    76,    -1,    93,    -1,   105,    -1,    62,    -1,
       8,    -1,    56,    -1,    77,    -1,    47,    -1,    80,    -1,
      23,    -1,    82,    -1,    61,    -1,    83,    -1,    29,    -1,
      57,    -1,    84,    -1,    98,    -1,    48,    -1,    50,    -1,
      54,    -1,    51,    -1,    49,    -1,   129,    -1,    11,    -1,
      10,    -1,    12,    -1,    99,    -1,    69,    -1,   127,    -1,
      64,    -1,    55,    -1,    86,    -1,    94,    -1,   114,    -1,
      87,    -1,    88,    -1,    43,    -1,    63,    -1,    89,    -1,
      68,    -1,    73,    -1,    67,    -1,    97,    -1,    52,    -1,
      53,    -1,   103,    -1,   101,    -1,    30,    -1,    45,    -1,
      20,    -1,    95,    -1,    72,    -1,    81,    -1,   100,    -1,
      91,    -1,    35,    -1,    36,    -1,    65,    -1,   104,    -1,
      27,    -1,    92,    -1,    90,    -1,    66,    -1,    46,    -1,
      58,    -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,
     124,    -1,   125,    -1,   126,    -1,   161,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   115,   115,   118,   119,   124,   125,   133,   134,   138,
     138,   138,   141,   141,   144,   144,   157,   157,   176,   178,
     181,   176,   186,   186,   191,   192,   193,   205,   206,   211,
     212,   215,   230,   240,   241,   252,   264,   277,   287,   296,
     301,   304,   312,   313,   319,   318,   340,   343,   343,   361,
     362,   365,   366,   367,   370,   377,   378,   381,   382,   383,
     385,   386,   387,   393,   397,   397,   401,   401,   411,   412,
     413,   417,   421,   417,   458,   459,   463,   471,   472,   475,
     476,   479,   482,   487,   496,   508,   520,   529,   537,   545,
     555,   559,   560,   563,   566,   567,   571,   572,   573,   574,
     577,   578,   582,   583,   587,   587,   590,   591,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   628,   629,   630,   631,   632,   633,
     634,   637,   640,   641,   642,   643,   644,   647,   651,   657,
     658,   659,   663,   664,   668,   669,   670,   671,   672,   673,
     674,   675,   677,   691,   692,   693,   694,   695,   696,   697,
     701,   702,   702,   707,   707,   709,   709,   712,   722,   722,
     725,   726,   727,   728,   732,   732,   734,   734,   736,   736,
     739,   742,   758,   761,   765,   766,   770,   772,   774,   776,
     778,   783,   783,   787,   790,   794,   794,   797,   797,   801,
     802,   815,   823,   823,   832,   836,   840,   844,   848,   852,
     856,   860,   864,   868,   872,   876,   880,   884,   887,   894,
     894,   899,   899,   899,   904,   905,   906,   907,   908,   909,
     910,   911,   912,   916,   920,   926,   927,   928,   931,   932,
     939,   941,   946,   954,   957,   958,   959,   960,   961,   962,
     963,   969,   971,   972,   975,   978,   982,   983,   984,   985,
     986,   987,   988,   994,   996,  1003,  1003,  1009,  1015,  1016,
    1019,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1036,  1037,  1040,  1047,  1048,  1049,  1054,  1057,
    1061,  1073,  1076,  1077,  1080,  1083,  1086,  1090,  1091,  1092,
    1093,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1108,  1112,
    1112,  1115,  1118,  1121,  1122,  1123,  1124,  1128,  1131,  1132,
    1137,  1138,  1139,  1144,  1144,  1148,  1148,  1152,  1153,  1154,
    1158,  1159,  1160,  1161,  1162,  1163,  1164,  1167,  1168,  1172,
    1173,  1177,  1180,  1183,  1183,  1187,  1187,  1190,  1195,  1196,
    1197,  1202,  1203,  1206,  1207,  1211,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,  1228,  1229,  1230,  1231,  1232,  1235,  1238,  1239,  1240,
    1241,  1242,  1245,  1249,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,
    1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,
    1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,
    1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
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
  "named_or_kw", "dbname", "screen_section", "screens_section", "@1", "@2",
  "screens_rest", "@3", "@4", "@5", "op_extended", "op_size", "op_end",
  "screen_layout", "some_text", "screen_element", "ch_list", "field", "@6",
  "field_element", "@7", "op_table_section", "table_def_list", "table_def",
  "opequal", "table_qualifier", "attribute_section", "field_tag_list",
  "field_tag", "@8", "fpart_list", "fpart", "@9", "@10", "op_att",
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
  "fcall_name", "evalue", "evalue_list", "any_kword", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
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
static const unsigned short int yyr1[] =
{
       0,   162,   163,   164,   164,   164,   164,   165,   165,   166,
     166,   166,   167,   167,   169,   168,   170,   168,   172,   173,
     174,   171,   175,   175,   176,   176,   176,   177,   177,   178,
     178,   179,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   181,   181,   183,   182,   184,   185,   184,   186,
     186,   187,   187,   187,   188,   189,   189,   190,   190,   190,
     190,   190,   190,   191,   192,   192,   194,   193,   195,   195,
     195,   197,   198,   196,   199,   199,   199,   200,   200,   201,
     201,   201,   201,   202,   202,   202,   202,   202,   202,   202,
     203,   204,   204,   205,   206,   206,   207,   207,   207,   207,
     208,   208,   209,   209,   210,   210,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   212,
     212,   212,   213,   213,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     215,   216,   215,   217,   217,   218,   218,   219,   220,   219,
     219,   219,   219,   219,   221,   221,   222,   222,   223,   223,
     224,   224,   225,   225,   226,   226,   227,   227,   227,   227,
     227,   228,   228,   229,   229,   230,   230,   231,   231,   232,
     232,   233,   235,   234,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   237,
     237,   238,   238,   238,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   240,   240,   240,   241,   241,
     242,   242,   243,   244,   245,   245,   245,   245,   245,   245,
     245,   246,   247,   247,   248,   249,   250,   250,   250,   250,
     250,   250,   250,   251,   251,   252,   252,   253,   254,   254,
     254,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   256,   256,   256,   256,   257,   258,
     258,   259,   260,   260,   261,   262,   263,   264,   264,   264,
     264,   265,   265,   265,   265,   265,   265,   265,   266,   267,
     267,   268,   269,   270,   270,   270,   270,   271,   272,   272,
     273,   273,   273,   274,   274,   275,   275,   276,   276,   276,
     277,   277,   277,   277,   277,   277,   277,   278,   278,   279,
     279,   280,   281,   282,   282,   283,   283,   284,   285,   285,
     285,   286,   286,   287,   287,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   289,   290,   290,   290,
     290,   290,   291,   291,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       1,     3,     1,     2,     0,     3,     0,     4,     0,     0,
       0,     9,     0,     1,     0,     2,     4,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     4,     1,     0,     4,     0,
       3,     1,     2,     3,     2,     0,     2,     1,     3,     3,
       5,     3,     3,     3,     1,     2,     0,     4,     1,     2,
       3,     0,     0,     6,     0,     3,     5,     3,     1,     0,
       5,     3,     2,     4,     2,     4,     3,     1,     4,     2,
       1,     1,     3,     3,     3,     1,     3,     1,     4,     2,
       1,     2,     0,     2,     1,     3,     1,     4,     4,     3,
       3,     3,     5,     3,     5,     1,     1,     3,     5,     3,
       3,     3,     1,     4,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     4,     1,     2,     1,     2,     2,     0,     9,
      12,     1,     1,     1,     0,     2,     0,     1,     0,     1,
       1,     4,     1,     3,     0,     1,     1,     3,     3,     3,
       3,     1,     3,     1,     1,     0,     1,     1,     2,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     2,     1,     1,     3,     3,     1,     1,
       3,     3,     3,     3,     1,     0,     3,     5,     0,     3,
       0,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     3,     0,     1,     2,     1,     3,
       3,     3,     3,     3,     3,     4,     3,     2,     2,     1,
       5,     5,     2,     3,     1,     1,     1,     1,     1,     1,
       3,     8,     1,     3,     3,     1,     1,     5,     5,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     5,     0,
       2,     1,     4,     2,     3,     2,     3,     3,     1,     2,
       2,     3,     3,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     4,     5,     0,     1,     1,     3,     1,     1,     3,
       3,     0,     1,     1,     3,     2,     2,     1,     2,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     2,     2,     5,     5,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
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
static const unsigned short int yydefact[] =
{
       0,     0,     0,     0,   401,   394,   421,   420,   422,     7,
     446,     3,   396,   406,   456,   410,   444,   452,   453,   433,
     445,   460,   404,   414,   418,   415,   417,   440,   441,   416,
     427,   402,   411,   461,   386,   389,   408,   400,   434,   426,
     454,   459,   438,   436,   424,   388,   387,   448,   437,   385,
     395,   397,   403,   405,   449,   407,   409,   412,   428,   431,
     432,   435,   458,   451,   457,   398,   429,   447,   384,   439,
     413,   423,   450,   443,   442,   455,   399,   392,   390,   391,
     430,   462,   463,   464,   465,   466,   467,   468,   425,   393,
     419,     9,   469,    10,     6,     8,     1,     0,    14,    49,
      12,     0,     0,     0,    16,    24,     0,    13,     0,     0,
      11,     0,    24,     0,    15,    18,    55,    27,    51,     0,
     160,     5,     4,    17,    25,    22,     0,    54,    28,     0,
      50,    52,   201,    27,    64,    66,   161,     2,     0,    23,
       0,     0,    57,    56,    53,    63,    65,     0,     0,    26,
      19,     0,     0,     0,     0,    71,     0,    68,     0,   420,
     404,   419,     0,     0,     0,     0,   295,    27,   163,   165,
     171,     0,   173,   172,     0,    62,    58,    59,    61,     0,
      67,    69,     0,   168,   167,     0,   327,   328,   329,     0,
     323,   335,   330,   336,   334,   331,   332,   333,     0,   325,
       0,   300,   299,   162,   164,   166,     0,    42,    35,    44,
      36,    37,    41,    40,    39,    34,    31,     0,    32,    29,
      38,    33,     0,     0,     0,    79,    87,    74,    70,     0,
     292,     0,     0,     0,     0,   324,     0,   326,     0,   178,
     195,    20,    30,    43,    60,     0,    89,     0,     0,    84,
      78,     0,     0,    72,     0,   176,     0,   180,     0,     0,
     296,     0,   340,     0,   337,     0,   343,   179,   341,   199,
     200,     0,     0,   196,   197,    46,    27,   194,   193,    79,
       0,   204,   205,   206,   207,   208,   209,   235,   235,   252,
     238,     0,   214,   215,   216,   217,   218,    82,    79,     0,
      86,     0,   102,   293,   177,     0,   296,   294,     0,     0,
       0,     0,     0,     0,   311,     0,     0,     0,     0,   318,
     303,   301,   304,   305,   307,   297,   302,   306,   298,   378,
     381,   379,     0,     0,     0,   430,   380,     0,   201,   377,
       0,   344,   345,   347,   348,     0,   357,    45,    47,   202,
     198,    21,    83,    88,     0,   210,   211,   256,   257,   258,
     259,   260,   261,   263,   212,     0,   254,   244,   245,   246,
     247,   248,   249,   263,   213,     0,   240,    81,    85,    77,
      75,     0,     0,    73,     0,     0,     0,   186,   184,   191,
     182,     0,   339,   338,   320,     0,     0,     0,     0,   315,
     313,     0,     0,   319,     0,   356,   355,   358,     0,   342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   372,   373,   351,   195,   195,
       0,     0,   262,     0,   250,     0,     0,   243,     0,     0,
     124,     0,   131,   106,     0,     0,     0,     0,     0,   115,
     116,     0,     0,   122,   127,   126,     0,     0,   130,   133,
     132,   136,   125,     0,     0,   135,   134,     0,   103,   104,
       0,   181,     0,     0,   174,   185,     0,     0,     0,   322,
     321,     0,   316,   314,     0,   317,   359,   361,   346,   371,
     365,   368,   366,   367,   369,   362,   363,   364,   350,   349,
       0,     0,     0,   353,     0,   352,    48,   203,   236,     0,
     242,     0,   253,   255,   251,   239,     0,    80,    76,     0,
       0,     0,    91,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   138,     0,     0,     0,     0,   291,
     190,   188,   189,   187,     0,   178,   183,   192,     0,   312,
     309,   370,     0,   382,     0,   360,     0,     0,   264,   241,
       0,     0,   100,     0,     0,   152,   144,   145,   146,   147,
     148,   149,   150,   151,   155,   153,   156,   157,   158,   159,
     154,   265,   142,   109,   140,   139,   141,   110,   113,   111,
     117,     0,   128,   129,   119,   120,   121,   105,   175,   169,
       0,     0,   308,   374,   375,     0,   354,   237,   123,    95,
      93,   101,    92,     0,    97,   108,     0,   143,   107,   266,
       0,     0,   228,   221,   225,   234,   224,     0,     0,     0,
     229,   219,     0,   310,   383,     0,    99,     0,   285,   288,
     286,     0,     0,   287,   267,   268,   279,   284,   114,   112,
       0,     0,     0,     0,   222,   223,   118,     0,     0,     0,
       0,    94,     0,    96,     0,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   278,   227,   226,
     233,   232,   220,   231,   230,   170,    98,   283,   270,   269,
     276,   274,   271,   272,   273,     0,     0,     0,   275,     0,
     289,     0,   280,   281,     0,   290
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,   338,    94,    99,   100,   105,   112,   114,
     125,   174,   276,   140,   115,   130,   217,   218,   219,   220,
     221,   240,   271,   428,   108,   117,   118,   127,   143,   120,
     133,   134,   147,   156,   157,   179,   302,   253,   249,   250,
     227,   520,   521,   522,   610,   615,   564,   383,   468,   469,
     587,   581,   582,   137,   148,   167,   168,   169,   232,   545,
     305,   268,   258,   388,   476,   389,   390,   279,   272,   273,
     274,   339,   275,   429,   297,   629,   630,   631,   355,   374,
     437,   511,   375,   376,   515,   364,   365,   512,   366,   432,
     618,   619,   644,   645,   646,   647,   701,   170,   229,   230,
     231,   262,   172,   319,   320,   602,   321,   322,   323,   324,
     325,   326,   189,   198,   190,   199,   263,   264,   173,   327,
     340,   341,   342,   343,   504,   505,   344,   345,   346,   554,
      95
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -604
static const short int yypact[] =
{
      25,  1503,    42,   161,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,    20,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,    35,    46,  -604,  -604,    43,  -604,    55,
    -604,    52,  2849,    60,  -604,    94,  2849,  -604,   107,    38,
    -604,    88,    94,   106,  -604,  -604,   111,  1625,  -604,  2849,
     132,  -604,  -604,  -604,   158,    15,  1869,  -604,  -604,  2849,
    -604,  -604,  -604,  1991,  -604,  -604,  -604,  -604,   188,  -604,
     202,   180,   138,  -604,  -604,  -604,  -604,   190,  1005,  -604,
    -604,  2849,  2849,  2849,  2849,  -604,    24,  -604,   124,   191,
     208,   206,    80,   -39,   103,   103,  -604,   876,  -604,   220,
    -604,   123,  -604,  -604,   747,  -604,  -604,   234,  -604,  1380,
     190,  -604,  2849,  -604,  -604,   243,  -604,  -604,  -604,    45,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,    70,  -604,
    2849,  -604,  -604,  -604,  -604,  -604,  2849,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,   620,  -604,  -604,
     257,  -604,  2849,   235,  2849,   -37,   236,   251,  -604,   -28,
    -604,   240,  2849,   224,  2849,  -604,  2849,  -604,   232,   239,
     -42,  -604,  -604,  -604,  -604,  2113,   244,   336,   245,  -604,
     162,  2849,   264,  -604,  2849,   238,  2849,   268,   248,   266,
     262,   263,  -604,   -25,  -604,   -25,  1135,  -604,  -604,  -604,
    -604,    19,  2849,   -42,  -604,  -604,   272,  -604,  -604,   241,
    2849,  -604,  -604,  -604,  -604,  -604,  -604,   254,   254,    34,
     104,  2849,  -604,  -604,  -604,  -604,  -604,  -604,   241,   267,
    -604,     8,   250,  -604,  -604,   189,  -604,  -604,   282,  2235,
     265,  2849,  2849,   -27,  -604,  2849,  1747,  1135,   -15,  -604,
    -604,  -604,  -604,  -604,  -604,   -15,  -604,  -604,   -15,  -604,
    -604,  -604,  1135,  1135,  1135,  1135,  -604,   164,   269,  -604,
     271,   273,  -604,   458,  -604,   270,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,   289,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,   275,  -604,   218,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,   275,  -604,   221,   283,   293,  -604,  -604,
    -604,   305,   261,  -604,  2849,   307,   297,   298,    30,   280,
    -604,   233,  -604,  -604,  -604,   299,   300,   302,  2357,  -604,
    -604,   260,    -7,  -604,   370,   458,   458,   458,  2849,  -604,
    1135,  1135,  1135,  1135,  1135,  1135,  1135,  1135,  1135,  1135,
    1135,  1135,   296,  1135,   318,  -604,  -604,  1135,   -42,   -42,
      39,   314,  -604,    34,  -604,   104,   340,  -604,  2849,   342,
     346,  2849,  -604,  -604,   327,   328,   329,   304,   315,  -604,
    -604,   331,   345,  -604,  -604,  -604,   348,   349,  -604,  -604,
    -604,   121,  -604,   350,   363,  -604,  -604,   364,   354,  -604,
     -23,  -604,  2481,  2604,   276,  -604,  2235,  2235,   362,  -604,
    -604,  1135,  -604,  -604,   -15,  -604,  -604,  -604,  -604,   458,
     458,   458,   458,   458,   458,   458,   458,   458,   458,   458,
    1135,   472,  1257,   458,   365,   356,  -604,  -604,  -604,   385,
    -604,   366,  -604,  -604,  -604,  -604,   367,  -604,  -604,   382,
     383,     0,  -604,  -604,   478,   384,    -6,  2849,  2849,   387,
     379,   388,   391,  -604,  -604,   392,   393,  2849,   261,  -604,
    -604,  -604,  -604,  -604,   303,   239,  -604,  -604,   407,   458,
     277,   458,  1135,  -604,    40,  -604,  1135,   389,  -604,  -604,
     413,  2849,  -604,  2971,  2727,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,   390,  -604,  -604,  -604,  -604,  -604,  -604,   406,   412,
    -604,    29,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
     395,   -15,  -604,   458,  -604,  1257,   458,  -604,  -604,   415,
    -604,   410,  -604,  2849,   417,  -604,    -2,  -604,  -604,  -604,
    2849,  2849,  -604,  -604,   -13,  -604,     1,   428,   429,    91,
       2,  -604,   430,  -604,  -604,  2849,   421,  2849,  -604,  -604,
    -604,    -2,    -2,  -604,  -604,   135,    61,  -604,  -604,  -604,
     448,   449,   434,   435,  -604,  -604,  -604,    29,    12,    12,
     431,  -604,  2849,  -604,   432,  -604,    -2,    -2,    -4,    -4,
      -4,    -4,    -4,   416,    -4,   436,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,  -604,
    -604,  -604,  -604,  -604,  -604,    -4,   371,    -4,  -604,    -4,
    -604,   159,  -604,  -604,    -4,  -604
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -604,  -604,  -604,    -1,  -604,  -604,   394,  -604,  -604,   375,
    -604,  -604,  -604,  -604,  -604,  -130,  -604,  -604,   274,  -604,
    -604,  -604,  -604,  -604,  -604,  -604,   -74,  -604,  -604,  -604,
    -604,   359,  -604,  -604,  -132,  -604,  -604,  -604,  -249,  -604,
    -604,  -604,  -604,   -80,  -604,  -604,  -604,  -604,  -604,   -43,
    -604,  -604,   -85,  -604,  -604,  -604,   335,  -604,  -604,  -604,
    -604,   -40,  -604,  -604,  -604,    31,    33,  -604,    77,  -604,
     237,  -115,    79,  -604,  -604,  -604,  -411,  -142,   229,  -604,
    -604,  -604,  -604,    83,  -604,  -604,  -604,  -604,    86,   147,
    -604,  -604,  -604,  -603,  -432,  -604,  -604,  -604,   137,   278,
    -147,  -239,  -604,  -323,  -604,  -604,  -604,  -604,  -604,  -604,
    -243,  -604,  -604,  -604,   333,   325,   288,   213,  -604,    87,
    -604,  -604,   118,  -225,  -604,  -604,  -604,  -604,  -494,  -604,
    -604
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -454
static const short int yytable[] =
{
      93,   171,   403,   145,   135,   403,   394,   485,   553,   247,
     584,   650,   638,   639,   638,   639,   254,   307,   135,   312,
     171,   254,   328,   380,   181,   652,   658,   585,   623,   640,
     352,   640,   622,     1,   347,   641,   562,   203,   664,   665,
     191,   395,    96,   131,   563,   623,   624,   101,   228,   378,
     348,   313,   381,   627,   628,   144,   155,   625,   180,   239,
     102,   313,   626,   688,   689,    97,    98,   121,   474,   313,
     627,   628,   392,   103,   475,   402,   104,   508,   604,   403,
     109,   255,   651,   509,   605,   106,   539,   261,   111,   261,
     269,   270,   401,   668,   248,   586,   653,   659,   192,   193,
     194,   110,   195,   196,   197,   116,   113,   404,   405,   406,
     407,   634,   642,   643,   119,   643,   116,   122,   132,   669,
     396,   200,   124,   314,   315,   142,   316,   317,   116,   656,
     318,   200,   132,   314,   315,   657,   316,   317,   136,   200,
     318,   314,   315,   126,   316,   317,   351,   166,   318,   191,
     175,   176,   177,   178,   357,   358,   359,   360,   361,   362,
     363,   550,   152,   153,   154,   261,   166,   138,   670,   671,
     672,    97,    98,   216,   139,   673,   674,   675,   226,   676,
     677,   166,   186,   187,   188,   234,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   703,   501,   238,
     397,   400,   503,   704,   149,   166,   151,   192,   193,   194,
     236,   195,   196,   197,   533,   534,   216,   186,   187,   188,
     150,   244,   155,   246,   367,   368,   369,   370,   371,   372,
     373,   257,   182,   260,   183,   260,   690,   691,   692,   693,
     694,   184,   696,   185,   278,   666,   667,   683,   684,   200,
     300,   201,   202,   166,   205,   306,   549,   206,   222,   233,
     243,   245,   251,   698,   252,   700,   256,   702,   259,   266,
     280,   349,   705,   267,   298,   551,   299,   304,   633,   353,
     301,   308,   310,   483,   440,   309,   128,   247,  -295,   311,
     377,   354,   411,   487,   382,   379,   441,   384,   385,   412,
     413,   414,   415,   391,   408,   430,  -376,   427,   387,   409,
     306,   260,   431,   433,   132,   132,   435,   410,   416,   438,
     436,   439,   471,   472,   473,   477,   523,   603,   478,   442,
     510,   606,   479,   480,   481,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   500,   502,   516,   518,   519,   524,
     525,   526,   527,   529,   462,   463,   464,   417,   418,   419,
     420,   421,   544,   528,   422,   423,   424,   530,   425,   426,
     531,   532,   535,   166,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   536,   537,   132,   538,   548,
     556,   557,   411,   555,   558,   559,   565,   132,   486,   412,
     413,   414,   415,   484,   560,   561,   591,   583,   465,   466,
     590,   592,   467,   600,   593,   594,   595,   607,   416,   608,
     598,   601,   620,   292,   293,   294,   295,   517,   621,   632,
     132,   635,  -453,   637,   654,   655,   660,   662,   523,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   296,   678,   679,   680,   681,   685,
     687,   541,   543,   697,   695,   387,   387,   417,   418,   419,
     420,   421,   699,   612,   422,   423,   424,   123,   425,   426,
     411,   242,   146,   107,   565,   597,   617,   412,   413,   414,
     415,   132,   204,   616,   411,   599,   507,   506,   547,   546,
     350,   412,   413,   414,   415,   682,   416,   356,   514,   513,
     434,   470,   235,   237,   265,   393,   588,   589,   488,     0,
     416,     0,   303,     0,     0,     0,   596,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,     0,     0,     0,     0,     0,     0,     0,     0,
     609,     0,   132,   614,     0,   417,   418,   419,   420,   421,
       0,     0,   422,   423,   424,     0,   425,   426,     0,   417,
     418,   419,   420,   552,     0,     0,   422,   423,   424,     0,
     425,   426,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,     0,     0,     0,     0,     0,
       0,     0,   636,     0,     0,     0,     0,     0,     0,   648,
     649,     0,     0,   207,   208,     0,     0,     0,     4,     5,
       6,     7,     8,   209,   661,     0,   663,     9,     0,   241,
      10,     0,    12,    13,     0,     0,     0,    14,     0,    15,
      16,   210,     0,   211,     0,    17,    18,     0,     0,     0,
       0,   686,     0,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,   212,    74,    75,    76,   213,    77,     0,     0,
      78,    79,     0,     0,    80,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     207,   208,   214,   215,     0,     4,     5,     6,     7,     8,
     209,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,     0,    15,    16,   210,     0,
     211,    92,    17,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   212,
      74,    75,    76,   213,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,   214,
     215,   158,     0,     0,     4,     5,     6,   159,     8,     0,
     128,     0,     0,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,     0,    15,    16,     0,    92,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,    19,
       0,    20,    21,   160,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,    77,     0,     0,    78,    79,     0,     0,
      80,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   161,     0,     0,     0,     0,
     158,   162,   163,     4,     5,     6,   159,     8,     0,     0,
     164,   165,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,     0,    15,    16,     0,    92,     0,     0,
      17,    18,     0,     0,     0,     0,     0,     0,    19,     0,
      20,    21,   160,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,    77,     0,     0,    78,    79,     0,     0,    80,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   161,     0,     0,     0,     0,     0,
     162,   163,     0,     4,     5,     6,     7,     8,     0,   164,
     165,   329,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,   330,    15,    16,    92,     0,   331,     0,
      17,    18,   332,     0,     0,     0,   333,   334,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,    77,     0,     0,    78,    79,     0,     0,   335,
       0,     0,   336,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     4,     5,     6,     7,     8,
       0,     0,     0,   329,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,   330,    15,    16,     0,     0,
     331,   337,    17,    18,     0,     0,    92,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,   336,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,   223,    12,    13,     0,     0,     0,    14,     0,    15,
      16,     0,     0,     0,     0,    17,    18,     0,    92,   224,
       0,     0,     0,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,    77,     0,     0,
      78,    79,     0,     0,    80,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     225,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    10,    11,    12,    13,     0,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,    17,    18,
       0,    92,     0,     0,     0,     0,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,     0,     0,    78,    79,     0,     0,    80,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     4,     5,     6,     7,     8,     0,   128,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,     0,    15,    16,     0,     0,     0,     0,
      17,    18,     0,    91,    92,     0,     0,     0,    19,   129,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,    77,     0,     0,    78,    79,     0,     0,    80,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,     0,    15,    16,     0,   398,
       0,     0,    17,    18,     0,     0,    92,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,   399,    15,    16,
       0,     0,   141,     0,    17,    18,     0,     0,    92,     0,
       0,     0,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,    77,     0,     0,    78,
      79,     0,     0,    80,     0,     0,     0,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     4,
       5,     6,     7,     8,     0,   128,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,     0,
      15,    16,     0,     0,     0,     0,    17,    18,     0,     0,
      92,     0,     0,     0,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,    77,     0,
       0,    78,    79,     0,     0,    80,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     4,     5,     6,     7,     8,     0,   277,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,    17,    18,
       0,     0,    92,     0,     0,     0,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,     0,     0,    78,    79,     0,     0,    80,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,   386,    12,    13,     0,
       0,     0,    14,     0,    15,    16,     0,     0,     0,     0,
      17,    18,     0,     0,    92,     0,     0,     0,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,    77,     0,     0,    78,    79,     0,     0,    80,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,     0,    15,    16,     0,     0,
       0,     0,    17,    18,     0,     0,    92,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,   482,    14,     0,
      15,    16,     0,     0,     0,     0,    17,    18,    92,     0,
     540,     0,     0,     0,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,    77,     0,
       0,    78,    79,     0,     0,    80,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,     0,    15,    16,     0,     0,     0,     0,    17,
      18,     0,    92,   542,     0,     0,     0,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,    53,    54,    55,    56,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,    77,     0,     0,    78,    79,     0,     0,    80,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,     0,    15,    16,     0,     0,
       0,     0,    17,    18,     0,    92,   613,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,     0,    15,    16,
       0,     0,     0,     0,    17,    18,     0,     0,    92,     0,
       0,     0,    19,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,    77,     0,     0,    78,
      79,     0,     0,    80,     0,     0,     0,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,     0,
      15,    16,     0,     0,     0,     0,    17,   611,     0,     0,
      92,     0,     0,     0,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,    77,     0,
       0,    78,    79,     0,     0,    80,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92
};

static const short int yycheck[] =
{
       1,   148,   325,   133,   119,   328,    33,    14,   502,    46,
      16,    24,    16,    17,    16,    17,    44,   256,   133,    44,
     167,    44,   265,    15,   156,    24,    24,    33,    16,    33,
     279,    33,     3,     8,    15,    37,    36,   167,   641,   642,
      79,    68,     0,   117,    44,    16,    17,    27,   180,   298,
      31,    76,    44,    41,    42,   129,    32,    28,    34,   206,
      25,    76,    33,   666,   667,    10,    11,    29,    38,    76,
      41,    42,   311,    27,    44,   318,    33,    38,    38,   402,
      28,   109,    95,    44,    44,    30,   109,   234,    28,   236,
     132,   133,   317,    32,   131,   101,    95,    95,   137,   138,
     139,   102,   141,   142,   143,   106,    12,   332,   333,   334,
     335,   605,   114,   117,     7,   117,   117,    29,   119,    58,
     147,   146,    16,   148,   149,   126,   151,   152,   129,    38,
     155,   146,   133,   148,   149,    44,   151,   152,     6,   146,
     155,   148,   149,    32,   151,   152,   276,   148,   155,    79,
     151,   152,   153,   154,   120,   121,   122,   123,   124,   125,
     126,   484,    24,    25,    26,   312,   167,     9,   107,   108,
     109,    10,    11,   174,   159,   114,   115,   116,   179,   118,
     119,   182,   137,   138,   139,   140,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,    38,   423,   200,
     315,   316,   427,    44,    16,   206,    26,   137,   138,   139,
     140,   141,   142,   143,    93,    94,   217,   137,   138,   139,
      18,   222,    32,   224,   120,   121,   122,   123,   124,   125,
     126,   232,   108,   234,    43,   236,   668,   669,   670,   671,
     672,    33,   674,    37,   245,   110,   111,   658,   659,   146,
     251,   164,   165,   254,    34,   256,   481,   134,    24,    16,
       3,    26,    26,   695,    13,   697,    26,   699,    44,    37,
      26,   272,   704,    34,    29,   500,   114,    39,   601,   280,
      16,    13,    16,   398,    23,    37,    14,    46,    26,    26,
     291,    37,    32,   408,    44,    28,    35,   108,    16,    39,
      40,    41,    42,    38,   140,    16,    37,    37,   309,    38,
     311,   312,    37,    95,   315,   316,    95,    44,    58,    26,
      37,    16,    15,    26,    26,    45,   441,   552,    95,    68,
      16,   556,    33,    33,    32,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    58,    37,    16,    15,    12,    32,
      32,    32,    58,    32,   103,   104,   105,   107,   108,   109,
     110,   111,    96,    58,   114,   115,   116,    32,   118,   119,
      32,    32,    32,   384,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    32,    32,   398,    44,    37,
      44,    16,    32,    38,    38,    38,    16,   408,    38,    39,
      40,    41,    42,   153,    32,    32,    37,    33,   157,   158,
      33,    33,   161,    16,    33,    33,    33,    38,    58,    16,
     127,   154,    26,    97,    98,    99,   100,   438,    26,    44,
     441,    26,    32,    26,    16,    16,    16,    26,   563,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,   128,    17,    17,    33,    33,    38,
      38,   472,   473,    37,    58,   476,   477,   107,   108,   109,
     110,   111,   111,   563,   114,   115,   116,   112,   118,   119,
      32,   217,   133,    99,    16,   538,   581,    39,    40,    41,
      42,   502,   167,   113,    32,   545,   429,   428,   477,   476,
     273,    39,    40,    41,    42,   657,    58,   288,   435,   433,
     373,   384,   189,   198,   236,   312,   527,   528,   410,    -1,
      58,    -1,   254,    -1,    -1,    -1,   537,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     561,    -1,   563,   564,    -1,   107,   108,   109,   110,   111,
      -1,    -1,   114,   115,   116,    -1,   118,   119,    -1,   107,
     108,   109,   110,   111,    -1,    -1,   114,   115,   116,    -1,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   605,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,   620,
     621,    -1,    -1,     3,     4,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,   635,    -1,   637,    17,    -1,    19,
      20,    -1,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,
      -1,   662,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,    -1,
     110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       3,     4,   132,   133,    -1,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    31,    -1,
      33,   161,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,    -1,   132,
     133,     5,    -1,    -1,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,
      -1,    -1,    -1,    27,    -1,    29,    30,    -1,   161,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
     104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
       5,   135,   136,     8,     9,    10,    11,    12,    -1,    -1,
     144,   145,    17,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,   161,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
     135,   136,    -1,     8,     9,    10,    11,    12,    -1,   144,
     145,    16,    17,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,   161,    -1,    33,    -1,
      35,    36,    37,    -1,    -1,    -1,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,
      -1,    -1,   117,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,
      33,   156,    35,    36,    -1,    -1,   161,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,   117,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,   161,    39,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,
     110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,   161,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
     107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,   160,   161,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    32,
      -1,    -1,    35,    36,    -1,    -1,   161,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,   150,    29,    30,
      -1,    -1,    33,    -1,    35,    36,    -1,    -1,   161,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
     161,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,   104,   105,    -1,   107,    -1,
      -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,   161,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
     107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,   161,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,   161,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,    -1,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,   150,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,   161,    -1,
      39,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,   104,   105,    -1,   107,    -1,
      -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,
      -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,   161,    39,    -1,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,   104,   105,
      -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,   161,    39,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,   161,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
     161,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,   104,   105,    -1,   107,    -1,
      -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,     8,   163,   164,     8,     9,    10,    11,    12,    17,
      20,    21,    22,    23,    27,    29,    30,    35,    36,    43,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    80,    81,    82,    83,    84,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   103,   104,   105,   107,   110,   111,
     114,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   160,   161,   165,   166,   292,     0,    10,    11,   167,
     168,    27,    25,    27,    33,   169,    30,   168,   186,    28,
     165,    28,   170,    12,   171,   176,   165,   187,   188,     7,
     191,    29,    29,   171,    16,   172,    32,   189,    14,    44,
     177,   188,   165,   192,   193,   233,     6,   215,     9,   159,
     175,    33,   165,   190,   188,   177,   193,   194,   216,    16,
      18,    26,    24,    25,    26,    32,   195,   196,     5,    11,
      47,   129,   135,   136,   144,   145,   165,   217,   218,   219,
     259,   262,   264,   280,   173,   165,   165,   165,   165,   197,
      34,   196,   108,    43,    33,    37,   137,   138,   139,   274,
     276,    79,   137,   138,   139,   141,   142,   143,   275,   277,
     146,   281,   281,   177,   218,    34,   134,     3,     4,    13,
      31,    33,   102,   106,   132,   133,   165,   178,   179,   180,
     181,   182,    24,    21,    39,   130,   165,   202,   196,   260,
     261,   262,   220,    16,   140,   276,   140,   277,   165,   262,
     183,    19,   180,     3,   165,    26,   165,    46,   131,   200,
     201,    26,    13,   199,    44,   109,    26,   165,   224,    44,
     165,   262,   263,   278,   279,   278,    37,    34,   223,   132,
     133,   184,   230,   231,   232,   234,   174,    14,   165,   229,
      26,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    97,    98,    99,   100,   128,   236,    29,   114,
     165,    16,   198,   261,    39,   222,   165,   263,    13,    37,
      16,    26,    44,    76,   148,   149,   151,   152,   155,   265,
     266,   268,   269,   270,   271,   272,   273,   281,   272,    16,
      28,    33,    37,    41,    42,   114,   117,   156,   165,   233,
     282,   283,   284,   285,   288,   289,   290,    15,    31,   165,
     232,   177,   200,   165,    37,   240,   240,   120,   121,   122,
     123,   124,   125,   126,   247,   248,   250,   120,   121,   122,
     123,   124,   125,   126,   241,   244,   245,   165,   200,    28,
      15,    44,    44,   209,   108,    16,    21,   165,   225,   227,
     228,    38,   263,   279,    33,    68,   147,   233,    32,   150,
     233,   285,   272,   265,   285,   285,   285,   285,   140,    38,
      44,    32,    39,    40,    41,    42,    58,   107,   108,   109,
     110,   111,   114,   115,   116,   118,   119,    37,   185,   235,
      16,    37,   251,    95,   251,    95,    37,   242,    26,    16,
      23,    35,    68,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   103,   104,   105,   157,   158,   161,   210,   211,
     260,    15,    26,    26,    38,    44,   226,    45,    95,    33,
      33,    32,   150,   233,   153,    14,    38,   233,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
      58,   285,    37,   285,   286,   287,   234,   230,    38,    44,
      16,   243,   249,   250,   245,   246,    16,   165,    15,    12,
     203,   204,   205,   233,    32,    32,    32,    58,    58,    32,
      32,    32,    32,    93,    94,    32,    32,    32,    44,   109,
      39,   165,    39,   165,    96,   221,   228,   227,    37,   285,
     265,   285,   111,   290,   291,    38,    44,    16,    38,    38,
      32,    32,    36,    44,   208,    16,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   213,   214,    33,    16,    33,   101,   212,   165,   165,
      33,    37,    33,    33,    33,    33,   165,   211,   127,   223,
      16,   154,   267,   285,    38,    44,   285,    38,    16,   165,
     206,    36,   205,    39,   165,   207,   113,   214,   252,   253,
      26,    26,     3,    16,    17,    28,    33,    41,    42,   237,
     238,   239,    44,   265,   290,    26,   165,    26,    16,    17,
      33,    37,   114,   117,   254,   255,   256,   257,   165,   165,
      24,    95,    24,    95,    16,    16,    38,    44,    24,    95,
      16,   165,    26,   165,   255,   255,   110,   111,    32,    58,
     107,   108,   109,   114,   115,   116,   118,   119,    17,    17,
      33,    33,   239,   238,   238,    38,   165,    38,   255,   255,
     256,   256,   256,   256,   256,    58,   256,    37,   256,   111,
     256,   258,   256,    38,    44,   256
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 115 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 118 "screen.yacc"
    {the_form.dbname=acl_strdup("formonly");}
    break;

  case 4:
#line 119 "screen.yacc"
    {the_form.dbname=((yyvsp[-3].str));
if (A4GLF_open_db((yyvsp[-3].str))) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 124 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 125 "screen.yacc"
    {the_form.dbname=acl_strdup((yyvsp[0].str));
if (A4GLF_open_db((yyvsp[0].str))) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 9:
#line 138 "screen.yacc"
    {sprintf((yyval.str),acl_getenv("DBNAME"));}
    break;

  case 11:
#line 138 "screen.yacc"
    {SPRINTF2((yyval.str),"%s@%s",(yyvsp[-2].str),(yyvsp[0].str));}
    break;

  case 14:
#line 144 "screen.yacc"
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

  case 16:
#line 157 "screen.yacc"
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
    break;

  case 18:
#line 176 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 19:
#line 178 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 20:
#line 181 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 186 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 26:
#line 193 "screen.yacc"
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
    break;

  case 31:
#line 215 "screen.yacc"
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
    break;

  case 32:
#line 230 "screen.yacc"
    {
        //printf("%s %d %d %d %d %d %s\n","_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	if (lineno) {
        A4GL_add_field("_label",colno+1,lineno,strlen((yyvsp[0].str)),scr,0,(yyvsp[0].str));
	colno+=strlen((yyvsp[0].str));
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 33:
#line 240 "screen.yacc"
    { ltab=0; }
    break;

  case 34:
#line 241 "screen.yacc"
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

  case 35:
#line 252 "screen.yacc"
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
    break;

  case 36:
#line 264 "screen.yacc"
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
    break;

  case 37:
#line 277 "screen.yacc"
    {
	if (lineno) {
	     A4GL_add_field("_label",colno+1,lineno,strlen((yyvsp[0].str)),scr,0,(yyvsp[0].str));
	colno+=strlen((yyvsp[0].str));
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 38:
#line 287 "screen.yacc"
    {
	if (lineno) {
	A4GL_add_field("_label",colno+1,lineno,strlen((yyvsp[0].str)),scr,0,(yyvsp[0].str));
	colno+=strlen((yyvsp[0].str));
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 39:
#line 296 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 40:
#line 301 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 41:
#line 304 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 42:
#line 312 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str));}
    break;

  case 43:
#line 313 "screen.yacc"
    {sprintf((yyval.str),"%s%s",(yyvsp[-1].str),(yyvsp[0].str));}
    break;

  case 44:
#line 319 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 45:
#line 326 "screen.yacc"
    {
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field((yyvsp[-1].str),fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field((yyvsp[-1].str),fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 46:
#line 340 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[0].str));
			}
    break;

  case 47:
#line 343 "screen.yacc"
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
    break;

  case 48:
#line 354 "screen.yacc"
    {
				strcpy((yyval.str),(yyvsp[0].str));
			}
    break;

  case 54:
#line 370 "screen.yacc"
    { 
A4GL_make_downshift((yyvsp[-1].str));
A4GL_make_downshift((yyvsp[0].str));
A4GL_add_table((yyvsp[0].str),(yyvsp[-1].str)); 
}
    break;

  case 55:
#line 377 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 56:
#line 378 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str)); }
    break;

  case 57:
#line 381 "screen.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[0].str));}
    break;

  case 58:
#line 382 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
    break;

  case 59:
#line 384 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
    break;

  case 60:
#line 385 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s%s%s", (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str),(yyvsp[-1].str),(yyvsp[0].str));}
    break;

  case 61:
#line 386 "screen.yacc"
    {sprintf((yyval.str),"%s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));}
    break;

  case 66:
#line 401 "screen.yacc"
    {
	A4GL_make_downshift((yyvsp[0].str));
	strcpy(currftag,(yyvsp[0].str));
	fldno=A4GL_find_field((yyvsp[0].str));
}
    break;

  case 71:
#line 417 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 72:
#line 421 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 73:
#line 431 "screen.yacc"
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

  case 75:
#line 459 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[-1].str));
}
    break;

  case 76:
#line 463 "screen.yacc"
    {
	fld->subscripts[0]=atoi((yyvsp[-3].str));
	fld->subscripts[1]=atoi((yyvsp[-1].str));
}
    break;

  case 77:
#line 471 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[-2].str))+256); }
    break;

  case 78:
#line 472 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[0].str)); }
    break;

  case 79:
#line 475 "screen.yacc"
    {strcpy((yyval.str),"0");}
    break;

  case 80:
#line 476 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[0].str),(yyvsp[-2].str)));
		}
    break;

  case 81:
#line 479 "screen.yacc"
    {
			sprintf((yyval.str),"%d",A4GLF_getdatatype_fcompile((yyvsp[0].str),""));
		}
    break;

  case 82:
#line 482 "screen.yacc"
    {
			strcpy((yyval.str),(yyvsp[0].str));
		}
    break;

  case 83:
#line 487 "screen.yacc"
    {
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup((yyvsp[-1].str));
        fld->datatype=atoi((yyvsp[0].str))&0xff;
	if (atoi((yyvsp[0].str))&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi((yyvsp[0].str))&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 84:
#line 496 "screen.yacc"
    {
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
    break;

  case 85:
#line 508 "screen.yacc"
    {
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
    break;

  case 86:
#line 520 "screen.yacc"
    {
	//printf("%s %s\n",$<str>1,$<str>3);
	fld->tabname=acl_strdup((yyvsp[-2].str)); 
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 87:
#line 529 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 88:
#line 537 "screen.yacc"
    {
	fld->tabname=acl_strdup((yyvsp[-2].str)); 
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 89:
#line 545 "screen.yacc"
    {
	fld->colname=acl_strdup((yyvsp[0].str));
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 106:
#line 590 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 107:
#line 591 "screen.yacc"
    {
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
    break;

  case 109:
#line 612 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,(yyvsp[0].str)); }
    break;

  case 110:
#line 613 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,(yyvsp[0].str)); }
    break;

  case 111:
#line 614 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 112:
#line 615 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 113:
#line 616 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 114:
#line 617 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 115:
#line 618 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 116:
#line 619 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 117:
#line 620 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,(yyvsp[0].str)); }
    break;

  case 118:
#line 621 "screen.yacc"
    { sprintf((yyval.str),"\n%s",(yyvsp[-1].str)); A4GL_add_str_attr(fld,FA_S_INCLUDE,(yyval.str)); }
    break;

  case 119:
#line 622 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,(yyvsp[0].str)); }
    break;

  case 120:
#line 623 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,(yyvsp[0].str)); }
    break;

  case 121:
#line 624 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_ACTION,(yyvsp[0].str)); }
    break;

  case 122:
#line 625 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 123:
#line 626 "screen.yacc"
    { fld->dynamic=atoi((yyvsp[0].str));
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 124:
#line 628 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 125:
#line 629 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",(yyvsp[0].str)); }
    break;

  case 126:
#line 630 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 127:
#line 631 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 128:
#line 632 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,(yyvsp[0].str)); }
    break;

  case 129:
#line 633 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,(yyvsp[0].str)); }
    break;

  case 130:
#line 634 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 131:
#line 637 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 132:
#line 640 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 136:
#line 644 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 137:
#line 647 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 138:
#line 651 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 139:
#line 657 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str));}
    break;

  case 140:
#line 658 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str));}
    break;

  case 141:
#line 659 "screen.yacc"
    {sprintf((yyval.str),"\n%s",(yyvsp[0].str));}
    break;

  case 143:
#line 664 "screen.yacc"
    { sprintf((yyval.str),"%d",atoi((yyvsp[-1].str))+atoi((yyvsp[0].str))); }
    break;

  case 144:
#line 668 "screen.yacc"
    { strcpy((yyval.str),"0"); }
    break;

  case 145:
#line 669 "screen.yacc"
    { strcpy((yyval.str),"4"); }
    break;

  case 146:
#line 670 "screen.yacc"
    { strcpy((yyval.str),"2"); }
    break;

  case 147:
#line 671 "screen.yacc"
    { strcpy((yyval.str),"6"); }
    break;

  case 148:
#line 672 "screen.yacc"
    { strcpy((yyval.str),"1"); }
    break;

  case 149:
#line 673 "screen.yacc"
    { strcpy((yyval.str),"5"); }
    break;

  case 150:
#line 674 "screen.yacc"
    { strcpy((yyval.str),"7"); }
    break;

  case 151:
#line 675 "screen.yacc"
    { strcpy((yyval.str),"3"); }
    break;

  case 152:
#line 677 "screen.yacc"
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
		strcpy((yyval.str),(yyvsp[0].str));
		}
    break;

  case 153:
#line 691 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 154:
#line 692 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 155:
#line 693 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 156:
#line 694 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 157:
#line 695 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 158:
#line 696 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 159:
#line 697 "screen.yacc"
    { sprintf((yyval.str),"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 161:
#line 702 "screen.yacc"
    {
}
    break;

  case 167:
#line 712 "screen.yacc"
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
    break;

  case 168:
#line 722 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 180:
#line 739 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[0].str),1);
}
    break;

  case 181:
#line 742 "screen.yacc"
    {
   A4GL_set_dim_srec((yyvsp[-3].str),atoi((yyvsp[-1].str)));
}
    break;

  case 182:
#line 758 "screen.yacc"
    {
	sprintf((yyval.str),"%s",(yyvsp[0].str));
}
    break;

  case 183:
#line 761 "screen.yacc"
    {
	sprintf((yyval.str),"%s,%s",(yyvsp[-2].str),(yyvsp[0].str));
}
    break;

  case 186:
#line 771 "screen.yacc"
    {A4GL_add_srec_attribute("",(yyvsp[0].str),""); }
    break;

  case 187:
#line 773 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[-2].str),(yyvsp[0].str),""); }
    break;

  case 188:
#line 775 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",(yyvsp[0].str),""); }
    break;

  case 189:
#line 777 "screen.yacc"
    {A4GL_add_srec_attribute((yyvsp[-2].str),"*",""); }
    break;

  case 190:
#line 779 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 192:
#line 783 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 193:
#line 787 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[0].str));
}
    break;

  case 194:
#line 790 "screen.yacc"
    { strcpy((yyval.str),(yyvsp[0].str)); }
    break;

  case 195:
#line 794 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 196:
#line 794 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str));}
    break;

  case 199:
#line 801 "screen.yacc"
    {colno++;}
    break;

  case 200:
#line 802 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 201:
#line 815 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[0].str));
	A4GL_make_downshift((yyval.str));
	colno+=strlen((yyvsp[0].str));
	}
    break;

  case 202:
#line 823 "screen.yacc"
    {
	colno+=strlen((yyvsp[0].str));
}
    break;

  case 203:
#line 825 "screen.yacc"
    {
	strcpy((yyval.str),(yyvsp[-2].str));
	A4GL_make_downshift((yyval.str));
	}
    break;

  case 204:
#line 832 "screen.yacc"
    {
	strcpy((yyval.str),"0");
	dtype_size=0;
}
    break;

  case 205:
#line 836 "screen.yacc"
    {
	strcpy((yyval.str),"2");
	dtype_size=0;
}
    break;

  case 206:
#line 840 "screen.yacc"
    {
	strcpy((yyval.str),"7");
	dtype_size=0;
}
    break;

  case 207:
#line 844 "screen.yacc"
    {
	strcpy((yyval.str),"3");
	dtype_size=0;
}
    break;

  case 208:
#line 848 "screen.yacc"
    {
	strcpy((yyval.str),"4");
	dtype_size=0;
}
    break;

  case 209:
#line 852 "screen.yacc"
    {
	strcpy((yyval.str),"1");
	dtype_size=0;
}
    break;

  case 210:
#line 856 "screen.yacc"
    {
	strcpy((yyval.str),"5");
	dtype_size=atoi((yyvsp[0].str));
}
    break;

  case 211:
#line 860 "screen.yacc"
    {
	strcpy((yyval.str),"8");
	dtype_size=atoi((yyvsp[0].str));
}
    break;

  case 212:
#line 864 "screen.yacc"
    {
	strcpy((yyval.str),"10");
	dtype_size=atoi((yyvsp[0].str));
}
    break;

  case 213:
#line 868 "screen.yacc"
    {
	strcpy((yyval.str),"14");
	dtype_size=atoi((yyvsp[0].str));
}
    break;

  case 214:
#line 872 "screen.yacc"
    {
	strcpy((yyval.str),"6");
	dtype_size=0;
}
    break;

  case 215:
#line 876 "screen.yacc"
    {
	strcpy((yyval.str),"11");
	dtype_size=0;
}
    break;

  case 216:
#line 880 "screen.yacc"
    {
	strcpy((yyval.str),"12");
	dtype_size=0;
}
    break;

  case 217:
#line 884 "screen.yacc"
    { strcpy((yyval.str),"13");
	dtype_size=0;
	}
    break;

  case 218:
#line 887 "screen.yacc"
    { strcpy((yyval.str),"90");
	dtype_size=0;
	}
    break;

  case 220:
#line 894 "screen.yacc"
    {
	sprintf((yyval.str),"%s\n%s",(yyvsp[-2].str),(yyvsp[0].str));
}
    break;

  case 223:
#line 899 "screen.yacc"
    {sprintf((yyval.str),"-%s",(yyvsp[0].str));}
    break;

  case 224:
#line 904 "screen.yacc"
    { strcpy((yyval.str),A4GL_char_val((yyvsp[0].str))); }
    break;

  case 225:
#line 905 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str)); }
    break;

  case 226:
#line 906 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[-2].str),(yyvsp[0].str)); }
    break;

  case 227:
#line 907 "screen.yacc"
    {sprintf((yyval.str),"%s\t%s",(yyvsp[-2].str),(yyvsp[0].str)); }
    break;

  case 228:
#line 908 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str));}
    break;

  case 230:
#line 910 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[-2].str),(yyvsp[0].str)); }
    break;

  case 231:
#line 911 "screen.yacc"
    { sprintf((yyval.str),"%s\t%s",(yyvsp[-2].str),(yyvsp[0].str)); }
    break;

  case 232:
#line 912 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[-2].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[0].str)));
}
    break;

  case 233:
#line 916 "screen.yacc"
    {
	sprintf((yyval.str),"%s\t",A4GL_char_val((yyvsp[-2].str)));
	sprintf((yyval.str),"%s%s",(yyval.str),A4GL_char_val((yyvsp[0].str)));
}
    break;

  case 234:
#line 920 "screen.yacc"
    {
	sprintf((yyval.str),"NULL");
}
    break;

  case 235:
#line 926 "screen.yacc"
    {sprintf((yyval.str),"%d",(16<<8) + 2);}
    break;

  case 236:
#line 927 "screen.yacc"
    {sprintf((yyval.str),"%d",((atoi((yyvsp[-1].str))+2)<<8)+2);}
    break;

  case 237:
#line 928 "screen.yacc"
    {sprintf((yyval.str),"%d",(atoi((yyvsp[-3].str))<<8)+atoi((yyvsp[-1].str)));}
    break;

  case 238:
#line 931 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 239:
#line 933 "screen.yacc"
    {
	sprintf((yyval.str),"%d",(atoi((yyvsp[-2].str))*16)+atoi((yyvsp[0].str)));
	}
    break;

  case 240:
#line 939 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 241:
#line 941 "screen.yacc"
    {
A4GL_debug("    %s",(yyvsp[-1].str));
strcpy((yyval.str),(yyvsp[-1].str));
}
    break;

  case 242:
#line 946 "screen.yacc"
    {
if (atoi((yyvsp[0].str))>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 243:
#line 954 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[0].str))*16+atoi((yyvsp[-1].str)));}
    break;

  case 244:
#line 957 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 245:
#line 958 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 246:
#line 959 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 247:
#line 960 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 248:
#line 961 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 249:
#line 962 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 250:
#line 964 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",(yyvsp[0].str));
  sprintf((yyval.str),"%d",atoi((yyvsp[0].str))+6); }
    break;

  case 252:
#line 971 "screen.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 253:
#line 972 "screen.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[-2].str))*16+atoi((yyvsp[0].str)));}
    break;

  case 254:
#line 975 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str));}
    break;

  case 255:
#line 978 "screen.yacc"
    {strcpy((yyval.str),(yyvsp[0].str));}
    break;

  case 256:
#line 982 "screen.yacc"
    {strcpy((yyval.str),"1");}
    break;

  case 257:
#line 983 "screen.yacc"
    {strcpy((yyval.str),"2");}
    break;

  case 258:
#line 984 "screen.yacc"
    {strcpy((yyval.str),"3");}
    break;

  case 259:
#line 985 "screen.yacc"
    {strcpy((yyval.str),"4");}
    break;

  case 260:
#line 986 "screen.yacc"
    {strcpy((yyval.str),"5");}
    break;

  case 261:
#line 987 "screen.yacc"
    {strcpy((yyval.str),"6");}
    break;

  case 262:
#line 989 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",(yyvsp[0].str));
sprintf((yyval.str),"%d",atoi((yyvsp[0].str))+6); }
    break;

  case 263:
#line 994 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy((yyval.str),"2");}
    break;

  case 264:
#line 996 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",(yyvsp[-1].str));
strcpy((yyval.str),(yyvsp[-1].str));
}
    break;

  case 265:
#line 1003 "screen.yacc"
    {(yyval.expr)=0;}
    break;

  case 266:
#line 1003 "screen.yacc"
    {
(yyval.expr)=(yyvsp[0].expr);
}
    break;

  case 267:
#line 1009 "screen.yacc"
    {
		(yyval.expr)=(yyvsp[0].expr);
	}
    break;

  case 269:
#line 1016 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),"AND");  
	}
    break;

  case 270:
#line 1019 "screen.yacc"
    {
		(yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),"OR");  
	}
    break;

  case 271:
#line 1025 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 272:
#line 1026 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 273:
#line 1027 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 274:
#line 1028 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 275:
#line 1029 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-3].expr),(yyvsp[0].expr),"NOTLIKE"); }
    break;

  case 276:
#line 1030 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 277:
#line 1031 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNULL"); }
    break;

  case 278:
#line 1032 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNOTNULL"); }
    break;

  case 279:
#line 1033 "screen.yacc"
    { (yyval.expr)=(yyvsp[0].expr); }
    break;

  case 280:
#line 1034 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[-2].expr)); add_list_expr((yyval.expr),(yyvsp[0].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 281:
#line 1035 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyvsp[-1].expr),"IN"); }
    break;

  case 282:
#line 1036 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[0].expr)); }
    break;

  case 283:
#line 1037 "screen.yacc"
    { (yyval.expr)=(yyvsp[-1].expr); }
    break;

  case 284:
#line 1040 "screen.yacc"
    {
(yyval.expr)=create_field_expr((yyvsp[0].str));
if (strcasecmp(currftag,(yyvsp[0].str))!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 285:
#line 1047 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[0].str))); printf("NUMBER VALUE : %s\n",(yyvsp[0].str)); }
    break;

  case 286:
#line 1048 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[0].str));}
    break;

  case 287:
#line 1049 "screen.yacc"
    {
	(yyval.expr)=create_special_expr((yyvsp[0].str));
}
    break;

  case 289:
#line 1057 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[0].expr));
	}
    break;

  case 290:
#line 1061 "screen.yacc"
    {
		add_list_expr((yyvsp[-2].expr),(yyvsp[0].expr));
		(yyval.expr)=(yyvsp[-2].expr);
	}
    break;

  case 349:
#line 1196 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),"AND");  }
    break;

  case 350:
#line 1197 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),"OR");  }
    break;

  case 355:
#line 1211 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[0].expr),"-"); }
    break;

  case 356:
#line 1213 "screen.yacc"
    { void *x; x=create_int_expr(0); (yyval.expr)=create_expr_comp_expr(x,(yyvsp[0].expr),"+"); }
    break;

  case 357:
#line 1214 "screen.yacc"
    { (yyval.expr)=(yyvsp[0].expr); }
    break;

  case 358:
#line 1215 "screen.yacc"
    { (yyval.expr)=create_not_expr((yyvsp[0].expr)); }
    break;

  case 359:
#line 1216 "screen.yacc"
    { (yyval.expr)=(yyvsp[-1].expr); }
    break;

  case 360:
#line 1217 "screen.yacc"
    { (yyval.expr)=(yyvsp[-1].expr); }
    break;

  case 361:
#line 1218 "screen.yacc"
    { (yyval.expr)=(yyvsp[0].expr); }
    break;

  case 362:
#line 1219 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 363:
#line 1220 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 364:
#line 1221 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 365:
#line 1222 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 366:
#line 1223 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 367:
#line 1224 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 368:
#line 1225 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 369:
#line 1226 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 370:
#line 1227 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-3].expr),(yyvsp[0].expr),"NOTLIKE"); }
    break;

  case 371:
#line 1228 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-2].expr),(yyvsp[0].expr),(yyvsp[-1].str)); }
    break;

  case 372:
#line 1229 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNULL"); }
    break;

  case 373:
#line 1230 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); (yyval.expr)=create_expr_comp_expr((yyvsp[-1].expr),p,"ISNOTNULL"); }
    break;

  case 374:
#line 1231 "screen.yacc"
    { (yyval.expr)=create_list_expr(); add_list_expr((yyval.expr),(yyvsp[-2].expr)); add_list_expr((yyval.expr),(yyvsp[0].expr)); (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyval.expr),"BETWEEN"); }
    break;

  case 375:
#line 1232 "screen.yacc"
    { (yyval.expr)=create_expr_comp_expr((yyvsp[-4].expr),(yyvsp[-1].expr),"IN"); }
    break;

  case 377:
#line 1238 "screen.yacc"
    { (yyval.expr)=create_field_expr((yyvsp[0].str)); }
    break;

  case 378:
#line 1239 "screen.yacc"
    {(yyval.expr)=create_int_expr(atoi((yyvsp[0].str))); }
    break;

  case 379:
#line 1240 "screen.yacc"
    {(yyval.expr)=create_char_expr((yyvsp[0].str));}
    break;

  case 380:
#line 1241 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[0].str)); }
    break;

  case 381:
#line 1242 "screen.yacc"
    { (yyval.expr)=create_special_expr((yyvsp[0].str));}
    break;

  case 382:
#line 1245 "screen.yacc"
    {
		(yyval.expr)=create_list_expr();
		add_list_expr((yyval.expr),(yyvsp[0].expr));
	}
    break;

  case 383:
#line 1249 "screen.yacc"
    {
		add_list_expr((yyvsp[-2].expr),(yyvsp[0].expr));
		(yyval.expr)=(yyvsp[-2].expr);
	}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 4370 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
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
	  yydestruct ("Error: discarding", yytoken, &yylval);
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
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1348 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */





