/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

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

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
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
     INSTRUCTIONS = 260,
     ATTRIBUTES = 261,
     DATABASE = 262,
     BY = 263,
     KW_SCREEN_TITLE = 264,
     KW_SCREEN = 265,
     KW_SIZE = 266,
     OPEN_SQUARE = 267,
     KW_END = 268,
     CLOSE_SQUARE = 269,
     NUMBER_VALUE = 270,
     NAMED = 271,
     OPEN_BRACE = 272,
     CLOSE_BRACE = 273,
     TITLE = 274,
     FORMONLY = 275,
     COMMENT = 276,
     DYNAMIC = 277,
     COLON = 278,
     ATSIGN = 279,
     DOT = 280,
     WITHOUT = 281,
     KW_NULL = 282,
     INPUT = 283,
     TABLES = 284,
     PIPE = 285,
     EQUAL = 286,
     CHAR_VALUE = 287,
     SEMICOLON = 288,
     OPEN_BRACKET = 289,
     CLOSE_BRACKET = 290,
     STAR = 291,
     PLUS = 292,
     MINUS = 293,
     RECORD = 294,
     COMMA = 295,
     THROUGH = 296,
     TYPE = 297,
     DELIMITERS = 298,
     KW_CHAR = 299,
     KW_INT = 300,
     KW_DATE = 301,
     KW_FLOAT = 302,
     SMALLFLOAT = 303,
     SMALLINT = 304,
     KW_DECIMAL = 305,
     MONEY = 306,
     DATETIME = 307,
     INTERVAL = 308,
     LIKE = 309,
     BLACK = 310,
     BLUE = 311,
     GREEN = 312,
     CYAN = 313,
     RED = 314,
     MAGENTA = 315,
     WHITE = 316,
     YELLOW = 317,
     REVERSE = 318,
     LEFT = 319,
     BLINK = 320,
     UNDERLINE = 321,
     AUTONEXT = 322,
     COLOR = 323,
     COMMENTS = 324,
     DEFAULT = 325,
     VALIDATE = 326,
     DISPLAY = 327,
     DOWNSHIFT = 328,
     UPSHIFT = 329,
     FORMAT = 330,
     INCLUDE = 331,
     INVISIBLE = 332,
     NOENTRY = 333,
     PICTURE = 334,
     PROGRAM = 335,
     REQUIRED = 336,
     VERIFY = 337,
     WORDWRAP = 338,
     COMPRESS = 339,
     NONCOMPRESS = 340,
     TO = 341,
     AS = 342,
     SERIAL = 343,
     KW_BYTE = 344,
     KW_TEXT = 345,
     VARCHAR = 346,
     SQL_VAR = 347,
     KW_NONSPACE = 348,
     SQLONLY = 349,
     WIDGET = 350,
     CONFIG = 351,
     KW_NL = 352,
     COMPARISON = 353,
     KWOR = 354,
     KWAND = 355,
     KWWHERE = 356,
     KWNOT = 357,
     KWBETWEEN = 358,
     KWIN = 359,
     XVAL = 360,
     KWNULLCHK = 361,
     KWNOTNULLCHK = 362,
     YEAR = 363,
     MONTH = 364,
     DAY = 365,
     HOUR = 366,
     MINUTE = 367,
     SECOND = 368,
     FRACTION = 369,
     LISTBOX = 370,
     BUTTON = 371,
     KW_PANEL = 372,
     KW_WS = 373,
     KW_TAB = 374
   };
#endif
#define CH 258
#define GRAPH_CH 259
#define INSTRUCTIONS 260
#define ATTRIBUTES 261
#define DATABASE 262
#define BY 263
#define KW_SCREEN_TITLE 264
#define KW_SCREEN 265
#define KW_SIZE 266
#define OPEN_SQUARE 267
#define KW_END 268
#define CLOSE_SQUARE 269
#define NUMBER_VALUE 270
#define NAMED 271
#define OPEN_BRACE 272
#define CLOSE_BRACE 273
#define TITLE 274
#define FORMONLY 275
#define COMMENT 276
#define DYNAMIC 277
#define COLON 278
#define ATSIGN 279
#define DOT 280
#define WITHOUT 281
#define KW_NULL 282
#define INPUT 283
#define TABLES 284
#define PIPE 285
#define EQUAL 286
#define CHAR_VALUE 287
#define SEMICOLON 288
#define OPEN_BRACKET 289
#define CLOSE_BRACKET 290
#define STAR 291
#define PLUS 292
#define MINUS 293
#define RECORD 294
#define COMMA 295
#define THROUGH 296
#define TYPE 297
#define DELIMITERS 298
#define KW_CHAR 299
#define KW_INT 300
#define KW_DATE 301
#define KW_FLOAT 302
#define SMALLFLOAT 303
#define SMALLINT 304
#define KW_DECIMAL 305
#define MONEY 306
#define DATETIME 307
#define INTERVAL 308
#define LIKE 309
#define BLACK 310
#define BLUE 311
#define GREEN 312
#define CYAN 313
#define RED 314
#define MAGENTA 315
#define WHITE 316
#define YELLOW 317
#define REVERSE 318
#define LEFT 319
#define BLINK 320
#define UNDERLINE 321
#define AUTONEXT 322
#define COLOR 323
#define COMMENTS 324
#define DEFAULT 325
#define VALIDATE 326
#define DISPLAY 327
#define DOWNSHIFT 328
#define UPSHIFT 329
#define FORMAT 330
#define INCLUDE 331
#define INVISIBLE 332
#define NOENTRY 333
#define PICTURE 334
#define PROGRAM 335
#define REQUIRED 336
#define VERIFY 337
#define WORDWRAP 338
#define COMPRESS 339
#define NONCOMPRESS 340
#define TO 341
#define AS 342
#define SERIAL 343
#define KW_BYTE 344
#define KW_TEXT 345
#define VARCHAR 346
#define SQL_VAR 347
#define KW_NONSPACE 348
#define SQLONLY 349
#define WIDGET 350
#define CONFIG 351
#define KW_NL 352
#define COMPARISON 353
#define KWOR 354
#define KWAND 355
#define KWWHERE 356
#define KWNOT 357
#define KWBETWEEN 358
#define KWIN 359
#define XVAL 360
#define KWNULLCHK 361
#define KWNOTNULLCHK 362
#define YEAR 363
#define MONTH 364
#define DAY 365
#define HOUR 366
#define MINUTE 367
#define SECOND 368
#define FRACTION 369
#define LISTBOX 370
#define BUTTON 371
#define KW_PANEL 372
#define KW_WS 373
#define KW_TAB 374




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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 71 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 394 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 406 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
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
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  89
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1479

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  120
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  88
/* YYNRULES -- Number of rules. */
#define YYNRULES  325
/* YYNRULES -- Number of states. */
#define YYNSTATES  464

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   374

#define YYTRANSLATE(YYX) 						\
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
     115,   116,   117,   118,   119
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    37,    39,    42,    43,    47,    48,    53,    54,    55,
      56,    65,    66,    69,    74,    75,    77,    79,    82,    84,
      86,    88,    90,    92,    94,    96,    98,   100,   102,   104,
     106,   109,   110,   115,   117,   118,   123,   124,   128,   130,
     133,   137,   140,   141,   144,   146,   150,   154,   160,   164,
     168,   170,   173,   174,   179,   181,   184,   185,   186,   193,
     194,   198,   204,   208,   210,   211,   217,   221,   224,   229,
     233,   235,   236,   239,   241,   245,   247,   252,   256,   260,
     264,   270,   274,   280,   282,   284,   288,   294,   298,   302,
     304,   309,   311,   313,   315,   319,   323,   325,   327,   329,
     331,   334,   337,   339,   341,   343,   345,   348,   350,   352,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   372,
     373,   374,   379,   381,   384,   386,   389,   392,   393,   403,
     416,   417,   420,   421,   423,   425,   430,   432,   436,   437,
     439,   441,   445,   449,   453,   457,   459,   463,   465,   466,
     468,   470,   473,   475,   479,   481,   483,   485,   487,   489,
     491,   494,   497,   500,   503,   505,   507,   509,   511,   513,
     515,   519,   521,   524,   527,   529,   531,   535,   537,   539,
     543,   547,   549,   550,   554,   560,   561,   565,   566,   570,
     572,   575,   577,   579,   581,   583,   585,   587,   590,   592,
     593,   597,   599,   601,   603,   605,   607,   609,   611,   613,
     616,   617,   621,   622,   624,   627,   629,   633,   637,   641,
     645,   650,   654,   657,   660,   662,   668,   674,   677,   681,
     683,   685,   687,   689,   691,   693,   697,   699,   701,   703,
     705,   707,   709,   711,   713,   715,   717,   719,   721,   723,
     725,   727,   729,   731,   733,   735,   737,   739,   741,   743,
     745,   747,   749,   751,   753,   755,   757,   759,   761,   763,
     765,   767,   769,   771,   773,   775,   777,   779,   781,   783,
     785,   787,   789,   791,   793,   795,   797,   799,   801,   803,
     805,   807,   809,   811,   813,   815,   817,   819,   821,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   851,   853,   855
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     121,     0,    -1,   122,   125,   143,   148,   166,    -1,     7,
      20,    -1,     7,   124,    26,    27,    28,    -1,     7,    20,
      26,    27,    28,    -1,     7,   124,    -1,    16,    -1,   207,
      -1,   123,    -1,   123,    24,   123,    -1,   126,    -1,   125,
     126,    -1,    -1,    10,   127,   129,    -1,    -1,     9,    32,
     128,   129,    -1,    -1,    -1,    -1,   133,   130,    17,   131,
     135,    18,   132,   134,    -1,    -1,    11,    15,    -1,    11,
      15,     8,    15,    -1,    -1,    13,    -1,   137,    -1,   135,
     137,    -1,   123,    -1,   136,    -1,   139,    -1,   119,    -1,
       4,    -1,    30,    -1,    32,    -1,   138,    -1,   118,    -1,
      97,    -1,    93,    -1,     3,    -1,   138,     3,    -1,    -1,
      12,   140,   141,    14,    -1,   183,    -1,    -1,   141,    30,
     142,   183,    -1,    -1,    29,   144,   134,    -1,   145,    -1,
     144,   145,    -1,   144,    40,   145,    -1,   123,   146,    -1,
      -1,    31,   147,    -1,   123,    -1,   123,    23,   123,    -1,
     123,    24,   123,    -1,   123,    24,   123,    23,   123,    -1,
     123,    25,   123,    -1,     6,   149,   134,    -1,   150,    -1,
     149,   150,    -1,    -1,   182,   151,   152,    33,    -1,   153,
      -1,   152,   153,    -1,    -1,    -1,    31,   154,   159,   156,
     155,   160,    -1,    -1,    12,    15,    14,    -1,    12,    15,
      40,    15,    14,    -1,   158,   102,    27,    -1,   158,    -1,
      -1,    42,    54,   123,    25,   123,    -1,    42,    54,   123,
      -1,    42,   184,    -1,    20,    25,   179,   157,    -1,   123,
      25,   123,    -1,   123,    -1,    -1,    40,   161,    -1,   162,
      -1,   161,    40,   162,    -1,    67,    -1,    68,    31,   164,
     200,    -1,    69,    31,    32,    -1,    70,    31,   163,    -1,
      72,    54,   123,    -1,    72,    54,   123,    25,   123,    -1,
      71,    54,   123,    -1,    71,    54,   123,    25,   123,    -1,
      73,    -1,    74,    -1,    75,    31,    32,    -1,    76,    31,
      34,   185,    35,    -1,    95,    31,    32,    -1,    96,    31,
      32,    -1,    77,    -1,    22,    11,    31,    15,    -1,    22,
      -1,    94,    -1,    78,    -1,    79,    31,    32,    -1,    80,
      31,    32,    -1,    81,    -1,    63,    -1,    82,    -1,    83,
      -1,    83,    84,    -1,    83,    85,    -1,    32,    -1,    15,
      -1,    92,    -1,   165,    -1,   164,   165,    -1,    55,    -1,
      56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,
      66,    -1,    -1,    -1,     5,   167,   168,   134,    -1,   169,
      -1,   168,   169,    -1,   170,    -1,   170,    33,    -1,    43,
      32,    -1,    -1,    10,    39,   171,   174,    34,   175,    35,
     172,   173,    -1,   117,    34,    15,    40,    15,    35,    86,
      34,    15,    40,    15,    35,    -1,    -1,    87,   115,    -1,
      -1,    33,    -1,   123,    -1,   123,    12,    15,    14,    -1,
     178,    -1,   175,   176,   178,    -1,    -1,    40,    -1,   123,
      -1,   123,    25,   123,    -1,    20,    25,   123,    -1,   123,
      25,    36,    -1,    20,    25,    36,    -1,   177,    -1,   177,
      41,   177,    -1,   123,    -1,    -1,   181,    -1,   118,    -1,
     181,   118,    -1,   123,    -1,   180,   123,   180,    -1,    44,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,    50,   188,    -1,    51,   188,    -1,    52,   195,    -1,
      53,   189,    -1,    88,    -1,    89,    -1,    90,    -1,    91,
      -1,   116,    -1,   187,    -1,   185,    40,   187,    -1,    15,
      -1,    37,    15,    -1,    38,    15,    -1,    32,    -1,    16,
      -1,    16,    86,    16,    -1,     3,    -1,   186,    -1,   186,
      86,   186,    -1,    32,    86,    32,    -1,    27,    -1,    -1,
      34,    15,    35,    -1,    34,    15,    40,    15,    35,    -1,
      -1,   192,    86,   194,    -1,    -1,    34,    15,    35,    -1,
      15,    -1,   193,   190,    -1,   108,    -1,   109,    -1,   110,
      -1,   111,    -1,   112,    -1,   113,    -1,   114,   199,    -1,
     193,    -1,    -1,   196,    86,   197,    -1,   198,    -1,   198,
      -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,   112,
      -1,   113,    -1,   114,   199,    -1,    -1,    34,   191,    35,
      -1,    -1,   201,    -1,   101,   202,    -1,   203,    -1,   203,
     100,   203,    -1,   203,    99,   203,    -1,   204,    98,   204,
      -1,   204,    54,   204,    -1,   204,   102,    54,   204,    -1,
     204,    31,   204,    -1,   204,   106,    -1,   204,   107,    -1,
     204,    -1,   204,   103,   204,   100,   204,    -1,   204,   104,
      34,   206,    35,    -1,   102,   203,    -1,    34,   203,    35,
      -1,   205,    -1,    15,    -1,    32,    -1,   105,    -1,    16,
      -1,   204,    -1,   206,    40,   204,    -1,    87,    -1,    67,
      -1,    55,    -1,    65,    -1,    56,    -1,    99,    -1,   100,
      -1,    98,    -1,   116,    -1,     8,    -1,    68,    -1,    21,
      -1,    69,    -1,    84,    -1,    96,    -1,    58,    -1,     7,
      -1,    52,    -1,    70,    -1,    43,    -1,    73,    -1,    22,
      -1,    75,    -1,    57,    -1,    76,    -1,    28,    -1,    53,
      -1,    77,    -1,    89,    -1,    44,    -1,    46,    -1,    50,
      -1,    47,    -1,    45,    -1,    27,    -1,   117,    -1,    10,
      -1,     9,    -1,    11,    -1,    90,    -1,    64,    -1,   115,
      -1,    60,    -1,    51,    -1,    78,    -1,    85,    -1,   102,
      -1,    79,    -1,    80,    -1,    39,    -1,    59,    -1,    81,
      -1,    63,    -1,    88,    -1,    48,    -1,    49,    -1,    94,
      -1,    92,    -1,    29,    -1,    41,    -1,    19,    -1,    86,
      -1,    66,    -1,    74,    -1,    91,    -1,    82,    -1,    61,
      -1,    95,    -1,    26,    -1,    83,    -1,    62,    -1,    42,
      -1,    54,    -1,   108,    -1,   109,    -1,   110,    -1,   111,
      -1,   112,    -1,   113,    -1,   114,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    99,    99,   102,   103,   108,   109,   117,   118,   122,
     122,   125,   125,   128,   128,   141,   141,   161,   163,   166,
     160,   173,   174,   175,   187,   188,   193,   194,   197,   211,
     217,   218,   222,   231,   241,   248,   256,   257,   258,   264,
     265,   271,   270,   288,   293,   292,   313,   314,   317,   318,
     319,   322,   329,   330,   333,   334,   335,   337,   338,   344,
     348,   348,   352,   352,   361,   361,   364,   368,   364,   392,
     393,   397,   405,   406,   409,   410,   413,   416,   421,   430,
     438,   447,   448,   452,   452,   455,   456,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   491,   492,   493,   494,   495,   496,   499,   502,   505,
     508,   512,   518,   519,   520,   522,   522,   528,   531,   534,
     537,   540,   543,   546,   549,   552,   555,   558,   561,   565,
     566,   566,   571,   571,   573,   573,   576,   586,   586,   589,
     592,   592,   594,   594,   597,   600,   616,   619,   623,   624,
     628,   630,   632,   634,   636,   641,   641,   645,   651,   651,
     654,   654,   660,   668,   676,   680,   684,   688,   692,   696,
     700,   704,   708,   712,   716,   720,   724,   728,   731,   738,
     738,   743,   743,   743,   748,   749,   750,   751,   752,   753,
     756,   760,   766,   767,   768,   771,   772,   779,   781,   786,
     794,   797,   798,   799,   800,   801,   802,   803,   809,   811,
     812,   815,   818,   822,   823,   824,   825,   826,   827,   828,
     834,   836,   843,   843,   849,   855,   856,   859,   865,   868,
     871,   874,   877,   882,   887,   891,   897,   900,   903,   908,
     915,   918,   919,   924,   927,   931,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   949,   950,   951,   952,
     953,   954,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,   989,   990,   991,   992,
     993,   994,   995,   996,   997,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,
    1013,  1014,  1015,  1016,  1017,  1018
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "GRAPH_CH", "INSTRUCTIONS", 
  "ATTRIBUTES", "DATABASE", "BY", "KW_SCREEN_TITLE", "KW_SCREEN", 
  "KW_SIZE", "OPEN_SQUARE", "KW_END", "CLOSE_SQUARE", "NUMBER_VALUE", 
  "NAMED", "OPEN_BRACE", "CLOSE_BRACE", "TITLE", "FORMONLY", "COMMENT", 
  "DYNAMIC", "COLON", "ATSIGN", "DOT", "WITHOUT", "KW_NULL", "INPUT", 
  "TABLES", "PIPE", "EQUAL", "CHAR_VALUE", "SEMICOLON", "OPEN_BRACKET", 
  "CLOSE_BRACKET", "STAR", "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", 
  "TYPE", "DELIMITERS", "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", 
  "SMALLFLOAT", "SMALLINT", "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", 
  "LIKE", "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", 
  "YELLOW", "REVERSE", "LEFT", "BLINK", "UNDERLINE", "AUTONEXT", "COLOR", 
  "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY", "DOWNSHIFT", "UPSHIFT", 
  "FORMAT", "INCLUDE", "INVISIBLE", "NOENTRY", "PICTURE", "PROGRAM", 
  "REQUIRED", "VERIFY", "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO", "AS", 
  "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR", "KW_NONSPACE", 
  "SQLONLY", "WIDGET", "CONFIG", "KW_NL", "COMPARISON", "KWOR", "KWAND", 
  "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", 
  "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", 
  "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "KW_WS", "KW_TAB", 
  "$accept", "form_def", "database_section", "named_or_kw", "dbname", 
  "screen_section", "screens_section", "@1", "@2", "screens_rest", "@3", 
  "@4", "@5", "op_size", "op_end", "screen_layout", "some_text", 
  "screen_element", "ch_list", "field", "@6", "field_element", "@7", 
  "op_table_section", "table_def_list", "table_def", "opequal", 
  "table_qualifier", "attribute_section", "field_tag_list", "field_tag", 
  "@8", "fpart_list", "fpart", "@9", "@10", "op_att", 
  "field_datatype_null", "field_datatype", "field_type", "op_field_desc", 
  "op_desc_list", "desc", "def_val", "colors", "color", 
  "op_instruction_section", "@11", "instruct_opts", "instruct_op_1", 
  "instruct_op", "@12", "op_ltype", "op_semi", "srec_dim", 
  "srec_field_list", "op_comma", "field_list_item", "field_list_element", 
  "field_name", "op_ws", "ws", "field_tag_name", "field_tag_name_scr", 
  "datatype", "incl_list", "number_value", "incl_entry", "opt_dec_ext", 
  "opt_int_ext", "opt_unit_size", "dtfrac", "int_start", "int_start_unit", 
  "int_end", "opt_dt_ext", "dt_start", "dt_end", "dtime_val", "opt_frac", 
  "op_where", "where_clause", "clauses", "clause", "value", 
  "fieldidentifier", "value_list", "any_kword", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   120,   121,   122,   122,   122,   122,   123,   123,   124,
     124,   125,   125,   127,   126,   128,   126,   130,   131,   132,
     129,   133,   133,   133,   134,   134,   135,   135,   136,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   138,
     138,   140,   139,   141,   142,   141,   143,   143,   144,   144,
     144,   145,   146,   146,   147,   147,   147,   147,   147,   148,
     149,   149,   151,   150,   152,   152,   154,   155,   153,   156,
     156,   156,   157,   157,   158,   158,   158,   158,   159,   159,
     159,   160,   160,   161,   161,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   163,   163,   163,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   166,
     167,   166,   168,   168,   169,   169,   170,   171,   170,   170,
     172,   172,   173,   173,   174,   174,   175,   175,   176,   176,
     177,   177,   177,   177,   177,   178,   178,   179,   180,   180,
     181,   181,   182,   183,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   185,
     185,   186,   186,   186,   187,   187,   187,   187,   187,   187,
     187,   187,   188,   188,   188,   189,   189,   190,   190,   191,
     192,   193,   193,   193,   193,   193,   193,   193,   194,   195,
     195,   196,   197,   198,   198,   198,   198,   198,   198,   198,
     199,   199,   200,   200,   201,   202,   202,   202,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   204,
     204,   204,   204,   205,   206,   206,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     2,     0,     3,     0,     4,     0,     0,     0,
       8,     0,     2,     4,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     4,     1,     0,     4,     0,     3,     1,     2,
       3,     2,     0,     2,     1,     3,     3,     5,     3,     3,
       1,     2,     0,     4,     1,     2,     0,     0,     6,     0,
       3,     5,     3,     1,     0,     5,     3,     2,     4,     3,
       1,     0,     2,     1,     3,     1,     4,     3,     3,     3,
       5,     3,     5,     1,     1,     3,     5,     3,     3,     1,
       4,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     4,     1,     2,     1,     2,     2,     0,     9,    12,
       0,     2,     0,     1,     1,     4,     1,     3,     0,     1,
       1,     3,     3,     3,     3,     1,     3,     1,     0,     1,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     2,     1,     1,     3,     1,     1,     3,
       3,     1,     0,     3,     5,     0,     3,     0,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     1,     2,     1,     3,     3,     3,     3,
       4,     3,     2,     2,     1,     5,     5,     2,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   262,   255,   283,   282,   284,     7,
     306,     3,   257,   267,   314,   280,   271,   304,   295,   305,
     317,   265,   275,   279,   276,   278,   300,   301,   277,   289,
     263,   272,   318,   248,   250,   269,   261,   296,   288,   312,
     316,   298,   286,   249,   308,   247,   256,   258,   264,   266,
     309,   268,   270,   273,   290,   293,   294,   297,   311,   315,
     259,   291,   307,   246,   299,   274,   285,   310,   303,   302,
     313,   260,   253,   251,   252,   292,   319,   320,   321,   322,
     323,   324,   325,   287,   254,   281,     9,     6,     8,     1,
       0,    13,    46,    11,     0,     0,     0,    15,    21,     0,
      12,     0,     0,    10,     0,    21,     0,    14,    17,    52,
      24,    48,     0,   129,     5,     4,    16,    22,     0,     0,
      51,    25,     0,    47,    49,   162,    24,    60,    62,   130,
       2,     0,    18,    54,    53,    50,    59,    61,     0,     0,
      23,     0,     0,     0,     0,    66,     0,    64,     0,     0,
       0,    24,   132,   134,    39,    32,    41,    33,    34,    38,
      37,    36,    31,    28,     0,    29,    26,    35,    30,    55,
      56,    58,     0,    63,    65,   137,   136,     0,   131,   133,
     135,   158,    19,    27,    40,     0,     0,    80,    69,     0,
       0,   160,     0,     0,   159,    43,    24,    57,     0,     0,
       0,    67,   144,     0,     0,    42,    44,   158,   161,    20,
     157,    74,    79,     0,    81,     0,     0,     0,   158,   163,
       0,    78,    73,    70,     0,     0,    68,     0,     0,   150,
     148,   155,   146,     0,    45,   164,   165,   166,   167,   168,
     169,   192,   192,   209,   195,     0,   174,   175,   176,   177,
     178,    77,     0,     0,   101,   107,    85,     0,     0,     0,
       0,     0,    93,    94,     0,     0,    99,   103,     0,     0,
     106,   108,   109,   102,     0,     0,    82,    83,   145,     0,
       0,   140,   149,     0,     0,     0,     0,   170,   171,   213,
     214,   215,   216,   217,   218,   220,   172,     0,   211,   201,
     202,   203,   204,   205,   206,   220,   173,     0,   197,    76,
      72,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,     0,     0,     0,   154,   152,   153,
     151,     0,   142,   147,   156,     0,     0,     0,   219,     0,
     207,     0,     0,   200,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   222,   115,
      87,   113,   112,   114,    88,    91,    89,    95,     0,   104,
     105,    97,    98,    84,   141,   143,   138,     0,   193,     0,
     199,     0,   210,   212,   208,   196,     0,    75,   100,     0,
     116,    86,   223,     0,     0,   187,   181,   185,   191,   184,
       0,     0,     0,   188,   179,     0,     0,   221,   198,   240,
     243,   241,     0,     0,   242,   224,   225,   234,   239,    92,
      90,     0,     0,   182,   183,    96,     0,     0,     0,   194,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,   186,   190,   180,   189,   139,   238,   227,   226,
     231,   229,   228,     0,     0,     0,   230,     0,   244,     0,
     235,   236,     0,   245
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   109,    87,    92,    93,    98,   105,   107,
     118,   141,   196,   108,   123,   164,   165,   166,   167,   168,
     181,   192,   218,   101,   110,   111,   120,   134,   113,   126,
     127,   138,   146,   147,   172,   214,   201,   221,   222,   188,
     226,   276,   277,   364,   358,   359,   130,   139,   151,   152,
     153,   189,   332,   376,   203,   230,   283,   231,   232,   211,
     193,   194,   128,   195,   251,   402,   403,   404,   287,   306,
     343,   381,   307,   308,   385,   296,   297,   382,   298,   338,
     391,   392,   415,   416,   417,   418,   459,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -314
static const short yypact[] =
{
      16,   696,    27,    33,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,    12,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,     8,    29,  -314,  -314,
      55,  -314,     7,  -314,    70,  1362,    76,  -314,    93,  1362,
    -314,   107,    86,  -314,    95,    93,   106,  -314,  -314,   101,
     585,  -314,  1362,   119,  -314,  -314,  -314,   118,   117,  1362,
    -314,  -314,  1362,  -314,  -314,  -314,   807,  -314,  -314,  -314,
    -314,   120,  -314,     6,  -314,  -314,  -314,  -314,   105,    -8,
    -314,   472,  1362,  1362,  1362,  -314,   -18,  -314,    98,   112,
     104,    -9,  -314,   113,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,   355,  -314,  -314,   136,  -314,  -314,
     122,  -314,   918,  -314,  -314,  -314,  -314,   132,  -314,  -314,
    -314,    31,  -314,  -314,  -314,  1362,   126,   128,   142,  1362,
     115,  -314,    -2,  1362,    38,  -314,   145,  -314,  1362,  1362,
     146,  -314,   147,   138,   159,  -314,  -314,    31,  -314,  -314,
    -314,   133,  -314,    -3,   137,   161,  1029,   125,    31,  -314,
       0,  -314,    60,  -314,   163,   151,  -314,   165,   155,   156,
     -14,   141,  -314,    97,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,   152,   152,   -40,    56,  1362,  -314,  -314,  -314,  -314,
    -314,  -314,   158,   173,   178,  -314,  -314,   160,   162,   164,
     140,   157,  -314,  -314,   181,   182,  -314,  -314,   185,   186,
    -314,  -314,    -6,  -314,   204,   205,   150,  -314,  -314,  1140,
    1251,   109,  -314,  1029,  1029,   203,   223,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   206,  -314,   153,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   206,  -314,   166,   207,   217,
    -314,  -314,   212,   144,   216,   -12,  1362,  1362,   218,   215,
     219,   221,  -314,  -314,   222,   224,   151,  -314,  -314,  -314,
    -314,   143,   226,  -314,  -314,   240,    61,   242,  -314,   -40,
    -314,    56,   245,  -314,  1362,   246,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,     1,  -314,
    -314,  -314,  -314,  -314,  -314,   237,   238,  -314,    90,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,   225,  -314,   249,
    -314,   231,  -314,  -314,  -314,  -314,   232,  -314,  -314,   -10,
    -314,  -314,  -314,  1362,  1362,  -314,  -314,   183,  -314,   184,
     253,   256,    72,   187,  -314,   257,   239,  -314,  -314,  -314,
    -314,  -314,   -10,   -10,  -314,  -314,   -24,   -21,  -314,  -314,
    -314,   259,   244,  -314,  -314,  -314,    90,     3,   250,  -314,
     251,  -314,   -10,   -10,    -7,    -7,    -7,   227,    -7,   243,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,    -7,   180,    -7,  -314,    -7,  -314,    75,
    -314,  -314,    -7,  -314
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -314,  -314,  -314,    -1,  -314,  -314,   192,  -314,  -314,   188,
    -314,  -314,  -314,  -314,  -112,  -314,  -314,   123,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -103,  -314,  -314,  -314,  -314,
     168,  -314,  -314,   149,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,   -38,  -314,  -314,   -69,  -314,  -314,  -314,   139,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,    13,     9,  -314,
      84,  -314,  -314,    78,  -314,  -314,  -129,  -127,    58,  -314,
    -314,  -314,  -314,   -39,  -314,  -314,  -314,  -314,   -36,    -4,
    -314,  -314,  -314,  -313,  -305,  -314,  -314,  -314
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      86,   148,   148,   361,   121,   409,   410,   124,   409,   410,
     434,   223,   205,   145,   136,   173,    90,    91,   396,   135,
     362,   281,   411,     1,   412,   411,   282,    89,   206,   142,
     143,   144,    95,   435,   149,   149,    99,   224,    94,   178,
     400,   401,    90,    91,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    96,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   289,   290,
     291,   292,   293,   294,   295,   432,   433,   436,   322,   323,
     363,   437,   438,   439,   209,   440,   441,    97,   246,   247,
     248,   249,   413,   395,   103,   414,   378,   102,   414,   430,
     431,   379,   389,   104,   106,   396,   397,   425,   150,   150,
     461,   125,   426,   112,   114,   462,   250,   398,   133,   448,
     449,   117,   399,   115,   129,   125,   131,   400,   401,   450,
     451,   452,   119,   454,   132,   140,   145,   175,   177,   184,
     163,   169,   170,   171,   176,   185,   180,   190,   456,   191,
     458,   198,   460,   199,   200,   204,   208,   463,   121,   215,
     233,   213,   252,   163,   299,   300,   301,   302,   303,   304,
     305,   187,   216,   254,   217,   220,   227,   225,   253,   278,
     279,   280,   284,   285,   197,   310,   286,   311,   202,   312,
     326,   313,   207,   314,   316,   315,   331,   210,   212,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   317,   318,   319,   255,   229,   320,   321,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   324,   325,   335,   336,   339,
     337,   342,   344,   345,   309,   273,   274,   275,   360,   368,
     367,   369,   341,   370,   371,   377,   372,   380,   374,   375,
     386,   388,   393,   394,   406,   405,   407,   408,   423,   421,
     422,   424,   428,   427,   429,   442,   443,   455,   328,   330,
     457,   453,   229,   229,   100,   446,   447,   183,   373,   390,
     179,   219,   333,   116,   137,   174,   234,   334,   445,   444,
     288,   340,   384,   383,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,   366,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   387,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,   155,
       0,     0,     4,     5,     6,     7,     8,   156,     0,     0,
       0,     9,     0,   182,    10,     0,    12,    13,     0,     0,
       0,    14,    15,    16,    17,   157,     0,   158,     0,     0,
       0,     0,   419,   420,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   159,    69,
      70,    71,   160,    72,    73,    74,     0,    75,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,   161,   162,   154,   155,     0,     0,     4,
       5,     6,     7,     8,   156,     0,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,   157,     0,   158,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   159,    69,    70,    71,   160,
      72,    73,    74,     0,    75,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
     161,   162,     4,     5,     6,     7,     8,     0,   121,     0,
       0,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,   122,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,    11,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,     0,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,     0,    72,    73,    74,     0,    75,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     4,     5,     6,     7,     8,     0,
     121,     0,     0,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,   186,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     0,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,   228,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,     0,    72,    73,    74,
       0,    75,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,   327,     0,     0,    18,
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     0,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,     0,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,     0,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,   329,     0,     0,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,     0,
      72,    73,    74,     0,    75,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85
};

static const short yycheck[] =
{
       1,    10,    10,    15,    13,    15,    16,   110,    15,    16,
      31,    14,    14,    31,   126,    33,     9,    10,    15,   122,
      32,    35,    32,     7,    34,    32,    40,     0,    30,    23,
      24,    25,    24,    54,    43,    43,    29,    40,    26,   151,
      37,    38,     9,    10,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    26,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,   108,   109,
     110,   111,   112,   113,   114,    99,   100,    98,    84,    85,
      92,   102,   103,   104,   196,   106,   107,    32,    88,    89,
      90,    91,   102,     3,    95,   105,    35,    27,   105,   412,
     413,    40,   101,    27,    11,    15,    16,    35,   117,   117,
      35,   112,    40,     6,    28,    40,   116,    27,   119,   432,
     433,    15,    32,    28,     5,   126,     8,    37,    38,   434,
     435,   436,    31,   438,    17,    15,    31,    39,    34,     3,
     141,   142,   143,   144,    32,    23,    33,    15,   453,   118,
     455,    25,   457,    25,    12,    40,   118,   462,    13,    12,
      35,    15,   102,   164,   108,   109,   110,   111,   112,   113,
     114,   172,    34,    22,    15,    42,    15,    40,    15,    14,
      25,    25,    41,    86,   185,    27,    34,    14,   189,    11,
      40,    31,   193,    31,    54,    31,    87,   198,   199,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    54,    31,    31,    63,   216,    31,    31,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    31,    31,    34,    15,    86,
      34,    34,    25,    31,   245,    94,    95,    96,    32,    34,
      32,    32,    86,    32,    32,    15,    32,    15,   115,    33,
      15,    15,    25,    25,    15,    40,    35,    35,    15,    86,
      86,    15,    15,    86,    35,    16,    32,    34,   279,   280,
     100,    54,   283,   284,    92,    35,    35,   164,   326,   358,
     151,   207,   283,   105,   126,   146,   218,   284,   427,   426,
     242,   305,   341,   339,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   316,   317,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   344,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    -1,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    16,    -1,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,   393,   394,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     3,     4,    -1,    -1,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     7,     8,     9,    10,    11,    -1,    13,    -1,
      -1,    16,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    -1,    -1,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    -1,    98,    99,   100,    -1,   102,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    -1,    98,    99,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,     7,     8,     9,    10,    11,    -1,
      13,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    -1,    98,    99,   100,    -1,   102,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    -1,    98,    99,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    -1,    98,    99,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,    19,
      -1,    21,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    -1,    98,    99,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      19,    -1,    21,    22,    -1,    -1,    -1,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    -1,    98,
      99,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    -1,
      98,    99,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     7,   121,   122,     7,     8,     9,    10,    11,    16,
      19,    20,    21,    22,    26,    27,    28,    29,    39,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    96,    98,    99,   100,   102,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   123,   124,   207,     0,
       9,    10,   125,   126,    26,    24,    26,    32,   127,    29,
     126,   143,    27,   123,    27,   128,    11,   129,   133,   123,
     144,   145,     6,   148,    28,    28,   129,    15,   130,    31,
     146,    13,    40,   134,   145,   123,   149,   150,   182,     5,
     166,     8,    17,   123,   147,   145,   134,   150,   151,   167,
      15,   131,    23,    24,    25,    31,   152,   153,    10,    43,
     117,   168,   169,   170,     3,     4,    12,    30,    32,    93,
      97,   118,   119,   123,   135,   136,   137,   138,   139,   123,
     123,   123,   154,    33,   153,    39,    32,    34,   134,   169,
      33,   140,    18,   137,     3,    23,    20,   123,   159,   171,
      15,   118,   141,   180,   181,   183,   132,   123,    25,    25,
      12,   156,   123,   174,    40,    14,    30,   123,   118,   134,
     123,   179,   123,    15,   155,    12,    34,    15,   142,   180,
      42,   157,   158,    14,    40,    40,   160,    15,    20,   123,
     175,   177,   178,    35,   183,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    88,    89,    90,    91,
     116,   184,   102,    15,    22,    63,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    94,    95,    96,   161,   162,    14,    25,
      25,    35,    40,   176,    41,    86,    34,   188,   188,   108,
     109,   110,   111,   112,   113,   114,   195,   196,   198,   108,
     109,   110,   111,   112,   113,   114,   189,   192,   193,   123,
      27,    14,    11,    31,    31,    31,    54,    54,    31,    31,
      31,    31,    84,    85,    31,    31,    40,    36,   123,    36,
     123,    87,   172,   178,   177,    34,    15,    34,   199,    86,
     199,    86,    34,   190,    25,    31,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,   164,   165,
      32,    15,    32,    92,   163,   123,   123,    32,    34,    32,
      32,    32,    32,   162,   115,    33,   173,    15,    35,    40,
      15,   191,   197,   198,   193,   194,    15,   123,    15,   101,
     165,   200,   201,    25,    25,     3,    15,    16,    27,    32,
      37,    38,   185,   186,   187,    40,    15,    35,    35,    15,
      16,    32,    34,   102,   105,   202,   203,   204,   205,   123,
     123,    86,    86,    15,    15,    35,    40,    86,    15,    35,
     203,   203,    99,   100,    31,    54,    98,   102,   103,   104,
     106,   107,    16,    32,   187,   186,    35,    35,   203,   203,
     204,   204,   204,    54,   204,    34,   204,   100,   204,   206,
     204,    35,    40,   204
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
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
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
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
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

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
  register const char *yys = yystr;

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
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



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
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

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
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



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
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

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
#line 99 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 102 "screen.yacc"
    {the_form.dbname=strdup("formonly");}
    break;

  case 4:
#line 103 "screen.yacc"
    {the_form.dbname=(yyvsp[-3].str);
if (A4GLF_open_db(yyvsp[-3].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 108 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 109 "screen.yacc"
    {the_form.dbname=strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 10:
#line 122 "screen.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 13:
#line 128 "screen.yacc"
    {
	char buff[256];
	sprintf(buff,"Screen %d", the_form.snames.snames_len);
		the_form.snames.snames_len++;the_form.snames.snames_val=
			realloc(the_form.snames.snames_val,
				(the_form.snames.snames_len)*
					sizeof(struct screen_name));

		the_form.snames.snames_val[the_form.snames.snames_len-1].name=
				strdup(buff);

		in_screen_section=1; 
	}
    break;

  case 15:
#line 141 "screen.yacc"
    {
	char buff[256];
	char *ptr;
	the_form.snames.snames_len++;the_form.snames.snames_val=
		realloc(the_form.snames.snames_val, 
			(the_form.snames.snames_len)*
				sizeof(struct screen_name));
		sprintf(buff,"%s", yyvsp[0].str);
		ptr=buff;
		ptr++;
		ptr[strlen(ptr)-1]=0;

		the_form.snames.snames_val[
			the_form.snames.snames_len-1].name =strdup(ptr);

	in_screen_section=1; 
	}
    break;

  case 17:
#line 161 "screen.yacc"
    { 
		lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 18:
#line 163 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 19:
#line 166 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 175 "screen.yacc"
    {
	int c;
	int l;
	if (A4GL_isyes(acl_getenv("USE_FORM_SIZE"))) {
		c=atoi(yyvsp[0].str);
		l=atoi(yyvsp[-2].str);
        	if (c>the_form.maxcol) the_form.maxcol=c;
        	if (l>the_form.maxline) the_form.maxline=l;
	}
}
    break;

  case 28:
#line 197 "screen.yacc"
    {
	int a;
	static char buff[256];
	strcpy(buff,yyvsp[0].str);

	for (a=0;a<strlen(buff);a++) {
		if (buff[a]=='_') buff[a]=' ';
	}
	strcpy(yyval.str,buff);
}
    break;

  case 29:
#line 211 "screen.yacc"
    {
        A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 31:
#line 218 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}
}
    break;

  case 32:
#line 222 "screen.yacc"
    {
	char buff[256];
	sprintf(buff,"\n%s",yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 33:
#line 231 "screen.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 34:
#line 241 "screen.yacc"
    {
	     A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 35:
#line 248 "screen.yacc"
    {
	//char buff[256];
	A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	//printf("colno was %d for '%s'\n",colno,$<str>1);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
}
    break;

  case 36:
#line 256 "screen.yacc"
    {colno++;}
    break;

  case 37:
#line 257 "screen.yacc"
    {colno=0;lineno++;}
    break;

  case 39:
#line 264 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 40:
#line 265 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 41:
#line 271 "screen.yacc"
    {
	fstart=colno;
	openwith='[';
}
    break;

  case 42:
#line 277 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 43:
#line 288 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 44:
#line 293 "screen.yacc"
    {
	/* 
field elements = name x y width screen_no endswith'|' 
*/
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,1,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,0,"");
	fstart=colno;
	openwith='|';
}
    break;

  case 45:
#line 307 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 51:
#line 322 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 52:
#line 329 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 53:
#line 330 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 54:
#line 333 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 55:
#line 334 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 56:
#line 336 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 57:
#line 337 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 58:
#line 338 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 62:
#line 352 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 66:
#line 364 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 67:
#line 368 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 68:
#line 378 "screen.yacc"
    {
	if (fld->datatype==90&&!(A4GL_has_str_attribute(fld,FA_S_DEFAULT)))
	{
	        extern FILE *yyin;

			A4GL_debug("Currpos = %ld\n",ftell(yyin));
	        yyerror("A button must have a default value for its caption");
	        YYERROR;
	}
	A4GL_set_field(currftag,fld);
}
    break;

  case 70:
#line 393 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 71:
#line 397 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 72:
#line 405 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 73:
#line 406 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 74:
#line 409 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 75:
#line 410 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 76:
#line 413 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 77:
#line 416 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 78:
#line 421 "screen.yacc"
    {
	fld->tabname=strdup("formonly");
	fld->colname=strdup(yyvsp[-1].str);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 79:
#line 430 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 80:
#line 438 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 85:
#line 455 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 86:
#line 456 "screen.yacc"
    {
		if (yyvsp[0].expr==0)  {
			int a;
			struct  u_expression *e_true;
  			e_true=create_int_expr(1);
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi(yyvsp[-1].str);
			fld->colours.colours_val[a-1].whereexpr=e_true;
		} else  {
			int a;
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi(yyvsp[-1].str);
			fld->colours.colours_val[a-1].whereexpr=yyvsp[0].expr;

		}
}
    break;

  case 87:
#line 476 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 88:
#line 477 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 89:
#line 478 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 90:
#line 479 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 91:
#line 480 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 92:
#line 481 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 93:
#line 482 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 94:
#line 483 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 95:
#line 484 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 96:
#line 485 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 97:
#line 486 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 98:
#line 487 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 99:
#line 488 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 100:
#line 489 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 101:
#line 491 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 102:
#line 492 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 103:
#line 493 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 104:
#line 494 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 105:
#line 495 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 106:
#line 496 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 107:
#line 499 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 108:
#line 502 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_VERIFY);
}
    break;

  case 109:
#line 505 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 110:
#line 508 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 111:
#line 512 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 114:
#line 520 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 116:
#line 522 "screen.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str));
}
    break;

  case 117:
#line 528 "screen.yacc"
    {
	strcpy(yyval.str,"0");
}
    break;

  case 118:
#line 531 "screen.yacc"
    {
	strcpy(yyval.str,"4");
}
    break;

  case 119:
#line 534 "screen.yacc"
    {
	strcpy(yyval.str,"2");
}
    break;

  case 120:
#line 537 "screen.yacc"
    {
	strcpy(yyval.str,"6"); 
}
    break;

  case 121:
#line 540 "screen.yacc"
    {
	strcpy(yyval.str,"1");
}
    break;

  case 122:
#line 543 "screen.yacc"
    {
	strcpy(yyval.str,"5"); 
}
    break;

  case 123:
#line 546 "screen.yacc"
    {
	strcpy(yyval.str,"7");
}
    break;

  case 124:
#line 549 "screen.yacc"
    {
	strcpy(yyval.str,"3");
}
    break;

  case 125:
#line 552 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE"));
}
    break;

  case 126:
#line 555 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT"));
}
    break;

  case 127:
#line 558 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK"));
}
    break;

  case 128:
#line 561 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE"));
}
    break;

  case 130:
#line 566 "screen.yacc"
    {
}
    break;

  case 136:
#line 576 "screen.yacc"
    {
	char buff[4];
	strcpy(buff,A4GL_char_val(yyvsp[0].str));
	if (strlen(buff)==1) {
		buff[1]=buff[0];
		buff[2]=buff[0];
		buff[3]=0;
	}
	the_form.delim=strdup(buff);
}
    break;

  case 137:
#line 586 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 144:
#line 597 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 145:
#line 600 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 146:
#line 616 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 147:
#line 619 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 150:
#line 629 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 151:
#line 631 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 152:
#line 633 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 153:
#line 635 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 154:
#line 637 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 156:
#line 641 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 157:
#line 645 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 160:
#line 654 "screen.yacc"
    {colno++;}
    break;

  case 161:
#line 654 "screen.yacc"
    {colno++;}
    break;

  case 162:
#line 660 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 163:
#line 668 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-1].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[-1].str);
	}
    break;

  case 164:
#line 676 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 165:
#line 680 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 166:
#line 684 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 167:
#line 688 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 168:
#line 692 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 169:
#line 696 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 170:
#line 700 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 171:
#line 704 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 172:
#line 708 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 173:
#line 712 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 174:
#line 716 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 175:
#line 720 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 176:
#line 724 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 177:
#line 728 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 178:
#line 731 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 180:
#line 738 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 183:
#line 743 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 184:
#line 748 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 185:
#line 749 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 186:
#line 750 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 187:
#line 751 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 189:
#line 753 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 190:
#line 756 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 191:
#line 760 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 192:
#line 766 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 193:
#line 767 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 194:
#line 768 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 195:
#line 771 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 196:
#line 773 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 197:
#line 779 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 198:
#line 781 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 199:
#line 786 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 200:
#line 794 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 201:
#line 797 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 202:
#line 798 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 203:
#line 799 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 204:
#line 800 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 205:
#line 801 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 206:
#line 802 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 207:
#line 804 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 209:
#line 811 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 210:
#line 812 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 211:
#line 815 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 212:
#line 818 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 213:
#line 822 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 214:
#line 823 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 215:
#line 824 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 216:
#line 825 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 217:
#line 826 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 218:
#line 827 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 219:
#line 829 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 220:
#line 834 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 221:
#line 836 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 222:
#line 843 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 223:
#line 843 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 224:
#line 849 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 226:
#line 856 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 227:
#line 859 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 228:
#line 865 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 229:
#line 868 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 230:
#line 871 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE");
		}
    break;

  case 231:
#line 874 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
	}
    break;

  case 232:
#line 877 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL");
	}
    break;

  case 233:
#line 882 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNOTNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL");
	}
    break;

  case 234:
#line 887 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
			//create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
    break;

  case 235:
#line 891 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[-2].expr);
		add_list_expr(yyval.expr,yyvsp[0].expr);
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN");
	}
    break;

  case 236:
#line 897 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN");
	}
    break;

  case 237:
#line 900 "screen.yacc"
    {
		yyval.expr=create_not_expr(yyvsp[0].expr);
	}
    break;

  case 238:
#line 903 "screen.yacc"
    {
		yyval.expr=yyvsp[-1].expr;
	}
    break;

  case 239:
#line 908 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 240:
#line 915 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str));
printf("NUMBER VALUE : %s\n",yyvsp[0].str);
}
    break;

  case 241:
#line 918 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 242:
#line 919 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 244:
#line 927 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 245:
#line 931 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3302 "y.tab.c"

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
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 98 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




