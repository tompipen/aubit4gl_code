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
     INSTRUCTIONS = 259,
     ATTRIBUTES = 260,
     DATABASE = 261,
     BY = 262,
     KW_SCREEN_TITLE = 263,
     KW_SCREEN = 264,
     KW_SIZE = 265,
     OPEN_SQUARE = 266,
     KW_END = 267,
     CLOSE_SQUARE = 268,
     NUMBER_VALUE = 269,
     NAMED = 270,
     OPEN_BRACE = 271,
     CLOSE_BRACE = 272,
     TITLE = 273,
     FORMONLY = 274,
     COMMENT = 275,
     DYNAMIC = 276,
     COLON = 277,
     ATSIGN = 278,
     DOT = 279,
     WITHOUT = 280,
     KW_NULL = 281,
     INPUT = 282,
     TABLES = 283,
     PIPE = 284,
     EQUAL = 285,
     CHAR_VALUE = 286,
     SEMICOLON = 287,
     OPEN_BRACKET = 288,
     CLOSE_BRACKET = 289,
     STAR = 290,
     PLUS = 291,
     MINUS = 292,
     RECORD = 293,
     COMMA = 294,
     THROUGH = 295,
     TYPE = 296,
     DELIMITERS = 297,
     KW_CHAR = 298,
     KW_INT = 299,
     KW_DATE = 300,
     KW_FLOAT = 301,
     SMALLFLOAT = 302,
     SMALLINT = 303,
     KW_DECIMAL = 304,
     MONEY = 305,
     DATETIME = 306,
     INTERVAL = 307,
     LIKE = 308,
     BLACK = 309,
     BLUE = 310,
     GREEN = 311,
     CYAN = 312,
     RED = 313,
     MAGENTA = 314,
     WHITE = 315,
     YELLOW = 316,
     REVERSE = 317,
     LEFT = 318,
     BLINK = 319,
     UNDERLINE = 320,
     AUTONEXT = 321,
     COLOR = 322,
     COMMENTS = 323,
     DEFAULT = 324,
     DISPLAY = 325,
     DOWNSHIFT = 326,
     UPSHIFT = 327,
     FORMAT = 328,
     INCLUDE = 329,
     INVISIBLE = 330,
     NOENTRY = 331,
     PICTURE = 332,
     PROGRAM = 333,
     REQUIRED = 334,
     VERIFY = 335,
     WORDWRAP = 336,
     COMPRESS = 337,
     NONCOMPRESS = 338,
     TO = 339,
     AS = 340,
     SERIAL = 341,
     KW_BYTE = 342,
     KW_TEXT = 343,
     VARCHAR = 344,
     SQL_VAR = 345,
     SQLONLY = 346,
     WIDGET = 347,
     CONFIG = 348,
     COMPARISON = 349,
     KWOR = 350,
     KWAND = 351,
     KWWHERE = 352,
     KWNOT = 353,
     KWBETWEEN = 354,
     KWIN = 355,
     XVAL = 356,
     KWNULLCHK = 357,
     KWNOTNULLCHK = 358,
     YEAR = 359,
     MONTH = 360,
     DAY = 361,
     HOUR = 362,
     MINUTE = 363,
     SECOND = 364,
     FRACTION = 365,
     LISTBOX = 366,
     BUTTON = 367,
     KW_PANEL = 368
   };
#endif
#define CH 258
#define INSTRUCTIONS 259
#define ATTRIBUTES 260
#define DATABASE 261
#define BY 262
#define KW_SCREEN_TITLE 263
#define KW_SCREEN 264
#define KW_SIZE 265
#define OPEN_SQUARE 266
#define KW_END 267
#define CLOSE_SQUARE 268
#define NUMBER_VALUE 269
#define NAMED 270
#define OPEN_BRACE 271
#define CLOSE_BRACE 272
#define TITLE 273
#define FORMONLY 274
#define COMMENT 275
#define DYNAMIC 276
#define COLON 277
#define ATSIGN 278
#define DOT 279
#define WITHOUT 280
#define KW_NULL 281
#define INPUT 282
#define TABLES 283
#define PIPE 284
#define EQUAL 285
#define CHAR_VALUE 286
#define SEMICOLON 287
#define OPEN_BRACKET 288
#define CLOSE_BRACKET 289
#define STAR 290
#define PLUS 291
#define MINUS 292
#define RECORD 293
#define COMMA 294
#define THROUGH 295
#define TYPE 296
#define DELIMITERS 297
#define KW_CHAR 298
#define KW_INT 299
#define KW_DATE 300
#define KW_FLOAT 301
#define SMALLFLOAT 302
#define SMALLINT 303
#define KW_DECIMAL 304
#define MONEY 305
#define DATETIME 306
#define INTERVAL 307
#define LIKE 308
#define BLACK 309
#define BLUE 310
#define GREEN 311
#define CYAN 312
#define RED 313
#define MAGENTA 314
#define WHITE 315
#define YELLOW 316
#define REVERSE 317
#define LEFT 318
#define BLINK 319
#define UNDERLINE 320
#define AUTONEXT 321
#define COLOR 322
#define COMMENTS 323
#define DEFAULT 324
#define DISPLAY 325
#define DOWNSHIFT 326
#define UPSHIFT 327
#define FORMAT 328
#define INCLUDE 329
#define INVISIBLE 330
#define NOENTRY 331
#define PICTURE 332
#define PROGRAM 333
#define REQUIRED 334
#define VERIFY 335
#define WORDWRAP 336
#define COMPRESS 337
#define NONCOMPRESS 338
#define TO 339
#define AS 340
#define SERIAL 341
#define KW_BYTE 342
#define KW_TEXT 343
#define VARCHAR 344
#define SQL_VAR 345
#define SQLONLY 346
#define WIDGET 347
#define CONFIG 348
#define COMPARISON 349
#define KWOR 350
#define KWAND 351
#define KWWHERE 352
#define KWNOT 353
#define KWBETWEEN 354
#define KWIN 355
#define XVAL 356
#define KWNULLCHK 357
#define KWNOTNULLCHK 358
#define YEAR 359
#define MONTH 360
#define DAY 361
#define HOUR 362
#define MINUTE 363
#define SECOND 364
#define FRACTION 365
#define LISTBOX 366
#define BUTTON 367
#define KW_PANEL 368




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
/* extern FILE *yyin; */
int in_screen_section=0;
int dtype_size=0;

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
#line 69 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 380 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 392 "y.tab.c"

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
#define YYLAST   1297

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  114
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  83
/* YYNRULES -- Number of rules. */
#define YYNRULES  309
/* YYNRULES -- Number of states. */
#define YYNSTATES  445

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   368

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
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     9,    12,    18,    24,    27,    29,    31,
      33,    37,    39,    42,    43,    47,    48,    53,    54,    55,
      56,    65,    66,    69,    74,    75,    77,    79,    82,    84,
      86,    88,    90,    92,    94,    95,   100,   102,   103,   108,
     109,   113,   115,   118,   122,   125,   126,   129,   131,   135,
     139,   145,   149,   153,   155,   158,   159,   164,   166,   169,
     170,   171,   178,   179,   183,   189,   193,   195,   196,   202,
     206,   209,   214,   218,   220,   221,   224,   226,   230,   232,
     237,   241,   245,   249,   255,   257,   259,   263,   269,   273,
     277,   279,   284,   286,   288,   290,   294,   298,   300,   302,
     304,   306,   309,   312,   314,   316,   318,   320,   323,   325,
     327,   329,   331,   333,   335,   337,   339,   341,   343,   345,
     347,   348,   349,   354,   356,   359,   361,   364,   367,   368,
     378,   391,   392,   395,   396,   398,   400,   405,   407,   411,
     413,   417,   421,   425,   429,   431,   435,   437,   439,   441,
     443,   445,   447,   449,   451,   454,   457,   460,   463,   465,
     467,   469,   471,   473,   475,   479,   481,   484,   487,   489,
     491,   495,   497,   499,   503,   507,   509,   510,   514,   520,
     521,   525,   526,   530,   532,   535,   537,   539,   541,   543,
     545,   547,   550,   552,   553,   557,   559,   561,   563,   565,
     567,   569,   571,   573,   576,   577,   581,   582,   584,   587,
     589,   593,   597,   601,   605,   610,   614,   617,   620,   622,
     628,   634,   637,   641,   643,   645,   647,   649,   651,   653,
     657,   659,   661,   663,   665,   667,   669,   671,   673,   675,
     677,   679,   681,   683,   685,   687,   689,   691,   693,   695,
     697,   699,   701,   703,   705,   707,   709,   711,   713,   715,
     717,   719,   721,   723,   725,   727,   729,   731,   733,   735,
     737,   739,   741,   743,   745,   747,   749,   751,   753,   755,
     757,   759,   761,   763,   765,   767,   769,   771,   773,   775,
     777,   779,   781,   783,   785,   787,   789,   791,   793,   795,
     797,   799,   801,   803,   805,   807,   809,   811,   813,   815
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     115,     0,    -1,   116,   119,   136,   141,   159,    -1,     6,
      19,    -1,     6,   118,    25,    26,    27,    -1,     6,    19,
      25,    26,    27,    -1,     6,   118,    -1,    15,    -1,   196,
      -1,   117,    -1,   117,    23,   117,    -1,   120,    -1,   119,
     120,    -1,    -1,     9,   121,   123,    -1,    -1,     8,    31,
     122,   123,    -1,    -1,    -1,    -1,   127,   124,    16,   125,
     129,    17,   126,   128,    -1,    -1,    10,    14,    -1,    10,
      14,     7,    14,    -1,    -1,    12,    -1,   131,    -1,   129,
     131,    -1,   117,    -1,   130,    -1,   132,    -1,     3,    -1,
      29,    -1,    31,    -1,    -1,    11,   133,   134,    13,    -1,
     172,    -1,    -1,   134,    29,   135,   172,    -1,    -1,    28,
     137,   128,    -1,   138,    -1,   137,   138,    -1,   137,    39,
     138,    -1,   117,   139,    -1,    -1,    30,   140,    -1,   117,
      -1,   117,    22,   117,    -1,   117,    23,   117,    -1,   117,
      23,   117,    22,   117,    -1,   117,    24,   117,    -1,     5,
     142,   128,    -1,   143,    -1,   142,   143,    -1,    -1,   172,
     144,   145,    32,    -1,   146,    -1,   145,   146,    -1,    -1,
      -1,    30,   147,   152,   149,   148,   153,    -1,    -1,    11,
      14,    13,    -1,    11,    14,    39,    14,    13,    -1,   151,
      98,    26,    -1,   151,    -1,    -1,    41,    53,   117,    24,
     117,    -1,    41,    53,   117,    -1,    41,   173,    -1,    19,
      24,   171,   150,    -1,   117,    24,   117,    -1,   117,    -1,
      -1,    39,   154,    -1,   155,    -1,   154,    39,   155,    -1,
      66,    -1,    67,    30,   157,   189,    -1,    68,    30,    31,
      -1,    69,    30,   156,    -1,    70,    53,   117,    -1,    70,
      53,   117,    24,   117,    -1,    71,    -1,    72,    -1,    73,
      30,    31,    -1,    74,    30,    33,   174,    34,    -1,    92,
      30,    31,    -1,    93,    30,    31,    -1,    75,    -1,    21,
      10,    30,    14,    -1,    21,    -1,    91,    -1,    76,    -1,
      77,    30,    31,    -1,    78,    30,    31,    -1,    79,    -1,
      62,    -1,    80,    -1,    81,    -1,    81,    82,    -1,    81,
      83,    -1,    31,    -1,    14,    -1,    90,    -1,   158,    -1,
     157,   158,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    64,    -1,    65,    -1,    -1,    -1,     4,
     160,   161,   128,    -1,   162,    -1,   161,   162,    -1,   163,
      -1,   163,    32,    -1,    42,    31,    -1,    -1,     9,    38,
     164,   167,    33,   168,    34,   165,   166,    -1,   113,    33,
      14,    39,    14,    34,    84,    33,    14,    39,    14,    34,
      -1,    -1,    85,   111,    -1,    -1,    32,    -1,   117,    -1,
     117,    11,    14,    13,    -1,   170,    -1,   168,    39,   170,
      -1,   117,    -1,   117,    24,   117,    -1,    19,    24,   117,
      -1,   117,    24,    35,    -1,    19,    24,    35,    -1,   169,
      -1,   169,    40,   169,    -1,   117,    -1,   117,    -1,    43,
      -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,
      -1,    49,   177,    -1,    50,   177,    -1,    51,   184,    -1,
      52,   178,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,   112,    -1,   176,    -1,   174,    39,   176,    -1,    14,
      -1,    36,    14,    -1,    37,    14,    -1,    31,    -1,    15,
      -1,    15,    84,    15,    -1,     3,    -1,   175,    -1,   175,
      84,   175,    -1,    31,    84,    31,    -1,    26,    -1,    -1,
      33,    14,    34,    -1,    33,    14,    39,    14,    34,    -1,
      -1,   181,    84,   183,    -1,    -1,    33,    14,    34,    -1,
      14,    -1,   182,   179,    -1,   104,    -1,   105,    -1,   106,
      -1,   107,    -1,   108,    -1,   109,    -1,   110,   188,    -1,
     182,    -1,    -1,   185,    84,   186,    -1,   187,    -1,   187,
      -1,   104,    -1,   105,    -1,   106,    -1,   107,    -1,   108,
      -1,   109,    -1,   110,   188,    -1,    -1,    33,   180,    34,
      -1,    -1,   190,    -1,    97,   191,    -1,   192,    -1,   192,
      96,   192,    -1,   192,    95,   192,    -1,   193,    94,   193,
      -1,   193,    53,   193,    -1,   193,    98,    53,   193,    -1,
     193,    30,   193,    -1,   193,   102,    -1,   193,   103,    -1,
     193,    -1,   193,    99,   193,    96,   193,    -1,   193,   100,
      33,   195,    34,    -1,    98,   192,    -1,    33,   192,    34,
      -1,   194,    -1,    14,    -1,    31,    -1,   101,    -1,    15,
      -1,   193,    -1,   195,    39,   193,    -1,    85,    -1,    66,
      -1,    54,    -1,    64,    -1,    55,    -1,    95,    -1,    96,
      -1,    94,    -1,   112,    -1,     7,    -1,    67,    -1,    20,
      -1,    68,    -1,    82,    -1,    93,    -1,    57,    -1,     6,
      -1,    51,    -1,    69,    -1,    42,    -1,    71,    -1,    21,
      -1,    73,    -1,    56,    -1,    74,    -1,    27,    -1,    52,
      -1,    75,    -1,    87,    -1,    43,    -1,    45,    -1,    49,
      -1,    46,    -1,    44,    -1,    26,    -1,   113,    -1,     9,
      -1,     8,    -1,    10,    -1,    88,    -1,    63,    -1,   111,
      -1,    59,    -1,    50,    -1,    76,    -1,    83,    -1,    98,
      -1,    77,    -1,    78,    -1,    38,    -1,    58,    -1,    79,
      -1,    62,    -1,    86,    -1,    47,    -1,    48,    -1,    91,
      -1,    90,    -1,    28,    -1,    40,    -1,    18,    -1,    84,
      -1,    65,    -1,    72,    -1,    89,    -1,    80,    -1,    60,
      -1,    92,    -1,    25,    -1,    81,    -1,    61,    -1,    41,
      -1,    53,    -1,   104,    -1,   105,    -1,   106,    -1,   107,
      -1,   108,    -1,   109,    -1,   110,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,    95,    95,    98,    99,   104,   105,   113,   114,   118,
     118,   121,   121,   124,   124,   137,   137,   157,   159,   162,
     156,   169,   170,   171,   183,   184,   189,   190,   193,   206,
     211,   212,   220,   230,   241,   240,   258,   263,   262,   283,
     284,   287,   288,   289,   292,   299,   300,   303,   304,   305,
     307,   308,   314,   318,   318,   322,   322,   331,   331,   334,
     338,   334,   362,   363,   367,   375,   376,   379,   380,   383,
     386,   391,   400,   407,   415,   416,   420,   420,   423,   424,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   457,   458,   459,   460,   461,   462,   465,   468,
     471,   474,   478,   484,   485,   486,   488,   488,   494,   497,
     500,   503,   506,   509,   512,   515,   518,   521,   524,   527,
     531,   532,   532,   537,   537,   539,   539,   542,   552,   552,
     555,   558,   558,   560,   560,   563,   566,   572,   575,   580,
     582,   584,   586,   588,   593,   593,   597,   603,   610,   614,
     618,   622,   626,   630,   634,   638,   642,   646,   650,   654,
     658,   662,   665,   672,   672,   677,   677,   677,   682,   683,
     684,   685,   686,   687,   690,   694,   700,   701,   702,   705,
     706,   713,   715,   720,   728,   731,   732,   733,   734,   735,
     736,   737,   743,   745,   746,   749,   752,   756,   757,   758,
     759,   760,   761,   762,   768,   770,   777,   777,   783,   789,
     790,   793,   799,   802,   805,   808,   811,   816,   821,   825,
     831,   834,   837,   842,   849,   852,   853,   858,   861,   865,
     873,   874,   875,   876,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,   887,   888,   889,   890,   891,   892,
     893,   894,   895,   896,   897,   898,   899,   900,   901,   902,
     903,   904,   905,   906,   907,   908,   909,   910,   911,   912,
     913,   914,   915,   916,   917,   918,   919,   920,   921,   922,
     923,   924,   925,   926,   927,   928,   929,   930,   931,   932,
     933,   934,   935,   936,   937,   938,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   949,   950,   951,   952
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "INSTRUCTIONS", "ATTRIBUTES", 
  "DATABASE", "BY", "KW_SCREEN_TITLE", "KW_SCREEN", "KW_SIZE", 
  "OPEN_SQUARE", "KW_END", "CLOSE_SQUARE", "NUMBER_VALUE", "NAMED", 
  "OPEN_BRACE", "CLOSE_BRACE", "TITLE", "FORMONLY", "COMMENT", "DYNAMIC", 
  "COLON", "ATSIGN", "DOT", "WITHOUT", "KW_NULL", "INPUT", "TABLES", 
  "PIPE", "EQUAL", "CHAR_VALUE", "SEMICOLON", "OPEN_BRACKET", 
  "CLOSE_BRACKET", "STAR", "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", 
  "TYPE", "DELIMITERS", "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", 
  "SMALLFLOAT", "SMALLINT", "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", 
  "LIKE", "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", 
  "YELLOW", "REVERSE", "LEFT", "BLINK", "UNDERLINE", "AUTONEXT", "COLOR", 
  "COMMENTS", "DEFAULT", "DISPLAY", "DOWNSHIFT", "UPSHIFT", "FORMAT", 
  "INCLUDE", "INVISIBLE", "NOENTRY", "PICTURE", "PROGRAM", "REQUIRED", 
  "VERIFY", "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO", "AS", "SERIAL", 
  "KW_BYTE", "KW_TEXT", "VARCHAR", "SQL_VAR", "SQLONLY", "WIDGET", 
  "CONFIG", "COMPARISON", "KWOR", "KWAND", "KWWHERE", "KWNOT", 
  "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", "KWNOTNULLCHK", "YEAR", 
  "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", "FRACTION", "LISTBOX", 
  "BUTTON", "KW_PANEL", "$accept", "form_def", "database_section", 
  "named_or_kw", "dbname", "screen_section", "screens_section", "@1", 
  "@2", "screens_rest", "@3", "@4", "@5", "op_size", "op_end", 
  "screen_layout", "some_text", "screen_element", "field", "@6", 
  "field_element", "@7", "op_table_section", "table_def_list", 
  "table_def", "opequal", "table_qualifier", "attribute_section", 
  "field_tag_list", "field_tag", "@8", "fpart_list", "fpart", "@9", "@10", 
  "op_att", "field_datatype_null", "field_datatype", "field_type", 
  "op_field_desc", "op_desc_list", "desc", "def_val", "colors", "color", 
  "op_instruction_section", "@11", "instruct_opts", "instruct_op_1", 
  "instruct_op", "@12", "op_ltype", "op_semi", "srec_dim", "field_list", 
  "field_list_item", "field_list_element", "field_name", "field_tag_name", 
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
     365,   366,   367,   368
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   114,   115,   116,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   121,   120,   122,   120,   124,   125,   126,
     123,   127,   127,   127,   128,   128,   129,   129,   130,   131,
     131,   131,   131,   131,   133,   132,   134,   135,   134,   136,
     136,   137,   137,   137,   138,   139,   139,   140,   140,   140,
     140,   140,   141,   142,   142,   144,   143,   145,   145,   147,
     148,   146,   149,   149,   149,   150,   150,   151,   151,   151,
     151,   152,   152,   152,   153,   153,   154,   154,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   156,   156,   156,   157,   157,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     159,   160,   159,   161,   161,   162,   162,   163,   164,   163,
     163,   165,   165,   166,   166,   167,   167,   168,   168,   169,
     169,   169,   169,   169,   170,   170,   171,   172,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   174,   174,   175,   175,   175,   176,   176,
     176,   176,   176,   176,   176,   176,   177,   177,   177,   178,
     178,   179,   179,   180,   181,   182,   182,   182,   182,   182,
     182,   182,   183,   184,   184,   185,   186,   187,   187,   187,
     187,   187,   187,   187,   188,   188,   189,   189,   190,   191,
     191,   191,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   193,   193,   193,   193,   194,   195,   195,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     5,     2,     5,     5,     2,     1,     1,     1,
       3,     1,     2,     0,     3,     0,     4,     0,     0,     0,
       8,     0,     2,     4,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     0,     4,     0,
       3,     1,     2,     3,     2,     0,     2,     1,     3,     3,
       5,     3,     3,     1,     2,     0,     4,     1,     2,     0,
       0,     6,     0,     3,     5,     3,     1,     0,     5,     3,
       2,     4,     3,     1,     0,     2,     1,     3,     1,     4,
       3,     3,     3,     5,     1,     1,     3,     5,     3,     3,
       1,     4,     1,     1,     1,     3,     3,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     4,     1,     2,     1,     2,     2,     0,     9,
      12,     0,     2,     0,     1,     1,     4,     1,     3,     1,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     2,     1,     1,
       3,     1,     1,     3,     3,     1,     0,     3,     5,     0,
       3,     0,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     0,     1,     2,     1,
       3,     3,     3,     3,     4,     3,     2,     2,     1,     5,
       5,     2,     3,     1,     1,     1,     1,     1,     1,     3,
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
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   246,   239,   267,   266,   268,     7,
     290,     3,   241,   251,   298,   264,   255,   288,   279,   289,
     301,   249,   259,   263,   260,   262,   284,   285,   261,   273,
     247,   256,   302,   232,   234,   253,   245,   280,   272,   296,
     300,   282,   270,   233,   292,   231,   240,   242,   248,   250,
     293,   252,   254,   257,   274,   277,   278,   281,   295,   299,
     243,   275,   291,   230,   283,   258,   269,   294,   287,   286,
     297,   244,   237,   235,   236,   276,   303,   304,   305,   306,
     307,   308,   309,   271,   238,   265,     9,     6,     8,     1,
       0,    13,    39,    11,     0,     0,     0,    15,    21,     0,
      12,     0,     0,    10,     0,    21,     0,    14,    17,    45,
      24,    41,     0,   120,     5,     4,    16,    22,     0,     0,
      44,    25,     0,    40,    42,   147,    24,    53,    55,   121,
       2,     0,    18,    47,    46,    43,    52,    54,     0,     0,
      23,     0,     0,     0,     0,    59,     0,    57,     0,     0,
       0,    24,   123,   125,    31,    34,    32,    33,    28,     0,
      29,    26,    30,    48,    49,    51,     0,    56,    58,   128,
     127,     0,   122,   124,   126,     0,    19,    27,     0,     0,
      73,    62,     0,     0,     0,    36,    24,    50,     0,     0,
       0,    60,   135,     0,     0,    35,    37,    20,   146,    67,
      72,     0,    74,     0,     0,     0,     0,     0,    71,    66,
      63,     0,     0,    61,     0,     0,   139,     0,   144,   137,
       0,    38,   148,   149,   150,   151,   152,   153,   176,   176,
     193,   179,     0,   158,   159,   160,   161,   162,    70,     0,
       0,    92,    98,    78,     0,     0,     0,     0,    84,    85,
       0,     0,    90,    94,     0,     0,    97,    99,   100,    93,
       0,     0,    75,    76,   136,     0,     0,   131,     0,     0,
       0,     0,   154,   155,   197,   198,   199,   200,   201,   202,
     204,   156,     0,   195,   185,   186,   187,   188,   189,   190,
     204,   157,     0,   181,    69,    65,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   101,   102,     0,     0,
       0,   143,   141,   142,   140,     0,   133,   138,   145,     0,
       0,     0,   203,     0,   191,     0,     0,   184,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   206,   106,    80,   104,   103,   105,    81,    82,
      86,     0,    95,    96,    88,    89,    77,   132,   134,   129,
       0,   177,     0,   183,     0,   194,   196,   192,   180,     0,
      68,    91,     0,   107,    79,   207,     0,   171,   165,   169,
     175,   168,     0,     0,     0,   172,   163,     0,     0,   205,
     182,   224,   227,   225,     0,     0,   226,   208,   209,   218,
     223,    83,     0,     0,   166,   167,    87,     0,     0,     0,
     178,     0,   221,     0,     0,     0,     0,     0,     0,     0,
       0,   216,   217,   170,   174,   164,   173,   130,   222,   211,
     210,   215,   213,   212,     0,     0,     0,   214,     0,   228,
       0,   219,   220,     0,   229
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   125,    87,    92,    93,    98,   105,   107,
     118,   141,   186,   108,   123,   159,   160,   161,   162,   175,
     184,   206,   101,   110,   111,   120,   134,   113,   126,   127,
     138,   146,   147,   166,   202,   191,   208,   209,   181,   213,
     262,   263,   348,   342,   343,   130,   139,   151,   152,   153,
     182,   316,   359,   193,   217,   218,   219,   199,   128,   238,
     384,   385,   386,   272,   291,   327,   364,   292,   293,   368,
     281,   282,   365,   283,   322,   374,   375,   397,   398,   399,
     400,   440,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -384
static const short yypact[] =
{
       2,   524,   120,     9,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,   101,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,     4,   105,  -384,  -384,
     104,  -384,   154,  -384,   113,  1172,   119,  -384,   161,  1172,
    -384,   170,   151,  -384,   157,   161,   171,  -384,  -384,   156,
      -5,  -384,  1172,   188,  -384,  -384,  -384,   187,   182,  1172,
    -384,  -384,  1172,  -384,  -384,  -384,   632,  -384,  -384,  -384,
    -384,   185,  -384,   110,  -384,  -384,  -384,  -384,   172,    23,
    -384,   416,  1172,  1172,  1172,  -384,   138,  -384,   166,   180,
     195,    83,  -384,   198,  -384,  -384,  -384,  -384,  -384,   305,
    -384,  -384,  -384,  -384,   207,  -384,   740,  -384,  -384,  -384,
    -384,   218,  -384,  -384,  -384,  1172,  -384,  -384,  1172,   209,
     210,   224,  1172,   219,    -4,  -384,   248,  -384,  1172,  1172,
     222,  -384,   250,   229,   249,  -384,  -384,  -384,  -384,   225,
    -384,    99,   230,   265,   848,   246,  1172,   197,  -384,   183,
    -384,   274,   146,  -384,   276,   266,   267,   -15,   254,  -384,
     211,  -384,  -384,  -384,  -384,  -384,  -384,  -384,   263,   263,
     147,   168,  1172,  -384,  -384,  -384,  -384,  -384,  -384,   271,
     285,   289,  -384,  -384,   272,   273,   275,   251,  -384,  -384,
     277,   280,  -384,  -384,   287,   288,  -384,  -384,    34,  -384,
     291,   294,   262,  -384,  -384,   956,  1064,   221,   848,   848,
     286,   314,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
     296,  -384,   253,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
     296,  -384,   255,   302,   316,  -384,  -384,   308,  1232,   310,
     100,  1172,   311,   369,   313,   373,  -384,  -384,   374,   375,
     146,  -384,  -384,  -384,  -384,   297,   388,  -384,  -384,   393,
      90,   407,  -384,   147,  -384,   168,   414,  -384,  1172,   415,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,    92,  -384,  -384,  -384,  -384,  -384,  -384,   406,
    -384,   256,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
     394,  -384,   418,  -384,   401,  -384,  -384,  -384,  -384,   404,
    -384,  -384,    82,  -384,  -384,  -384,  1172,  -384,  -384,   355,
    -384,   356,   432,   434,   127,   365,  -384,   436,   417,  -384,
    -384,  -384,  -384,  -384,    82,    82,  -384,  -384,    27,   107,
    -384,  -384,   437,   422,  -384,  -384,  -384,   256,    -8,   421,
    -384,   452,  -384,    82,    82,    96,    96,    96,   460,    96,
     482,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,    96,   420,    96,  -384,    96,  -384,
     130,  -384,  -384,    96,  -384
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -384,  -384,  -384,    -1,  -384,  -384,   425,  -384,  -384,   413,
    -384,  -384,  -384,  -384,    -7,  -384,  -384,   360,  -384,  -384,
    -384,  -384,  -384,  -384,   -96,  -384,  -384,  -384,  -384,   409,
    -384,  -384,   390,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,   227,  -384,  -384,   196,  -384,  -384,  -384,   389,  -384,
    -384,  -384,  -384,  -384,  -384,   278,   290,  -384,   -47,  -384,
    -384,   133,   139,   319,  -384,  -384,  -384,  -384,   228,  -384,
    -384,  -384,  -384,   231,   269,  -384,  -384,  -384,  -383,  -243,
    -384,  -384,  -384
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
      86,     4,     5,     6,     7,     8,   378,   121,     1,   195,
       9,   411,   412,    10,   124,    12,    13,    90,    91,   267,
      14,    15,    16,    17,   268,   196,   135,    95,   382,   383,
     429,   430,   148,    18,   122,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   149,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   148,    75,   103,   121,   391,   392,   109,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   109,
     391,   392,   210,   393,   345,   394,   306,   307,   133,   136,
      89,   109,   413,   414,   361,   149,    94,   393,   185,   362,
      96,   346,   142,   143,   144,    97,   150,   415,   211,   102,
     158,   163,   164,   165,   172,   104,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   158,   221,
     416,   406,    90,    91,   442,   180,   407,   241,   145,   443,
     167,   106,   431,   432,   433,   112,   435,   187,   114,   197,
     395,   192,    99,   396,   115,   117,   119,   198,   200,   372,
     347,   437,   129,   439,   131,   441,   150,   396,   132,   140,
     444,   417,   145,   216,   169,   418,   419,   420,   242,   421,
     422,   170,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   171,   178,
     174,   294,   183,   188,   189,   190,   201,   259,   260,   261,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   274,   275,   276,   277,   278,   279,   280,   194,   377,
     121,   203,   204,   205,   312,   314,   207,   216,   216,   212,
     378,   379,   284,   285,   286,   287,   288,   289,   290,   214,
     220,   239,   380,   233,   234,   235,   236,   381,   240,   264,
     265,   266,   382,   383,   269,   270,   271,   295,   296,   297,
     349,   310,   298,   299,   301,   300,   315,   302,   154,   237,
     303,     4,     5,     6,     7,     8,   155,   304,   305,   319,
       9,   308,   176,    10,   309,    12,    13,   370,   320,   321,
      14,    15,    16,    17,   156,   326,   157,   323,   329,   325,
     328,   344,   350,    18,   352,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   401,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   351,    75,   353,   354,   355,   360,   357,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   154,
     358,   363,     4,     5,     6,     7,     8,   155,   369,   371,
     376,     9,   388,   387,    10,   389,    12,    13,   390,   402,
     403,    14,    15,    16,    17,   156,   404,   157,   405,   408,
     409,   410,   423,   424,    18,   427,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   428,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   434,    75,   436,   438,   100,   116,   177,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       4,     5,     6,     7,     8,   137,   168,   356,   373,     9,
     173,   426,    10,    11,    12,    13,   425,   318,   273,    14,
      15,    16,    17,   367,   366,     0,     0,     0,   317,   324,
       0,     0,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     4,     5,
       6,     7,     8,     0,   121,     0,     0,     9,     0,     0,
      10,     0,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,   179,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,    75,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     9,     0,     0,    10,   215,    12,    13,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,    75,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,   311,     0,     0,    18,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,    75,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,   313,
       0,     0,    18,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,     0,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      75,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341
};

static const short yycheck[] =
{
       1,     6,     7,     8,     9,    10,    14,    12,     6,    13,
      15,   394,   395,    18,   110,    20,    21,     8,     9,    34,
      25,    26,    27,    28,    39,    29,   122,    23,    36,    37,
     413,   414,     9,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    42,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,     9,    98,    95,    12,    14,    15,    99,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   110,
      14,    15,    13,    31,    14,    33,    82,    83,   119,   126,
       0,   122,    95,    96,    34,    42,    25,    31,   175,    39,
      25,    31,    22,    23,    24,    31,   113,    30,    39,    26,
     141,   142,   143,   144,   151,    26,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   159,   206,
      53,    34,     8,     9,    34,   166,    39,    21,    30,    39,
      32,    10,   415,   416,   417,     5,   419,   178,    27,   186,
      98,   182,    28,   101,    27,    14,    30,   188,   189,    97,
      90,   434,     4,   436,     7,   438,   113,   101,    16,    14,
     443,    94,    30,   204,    38,    98,    99,   100,    62,   102,
     103,    31,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    33,    22,
      32,   232,    14,    24,    24,    11,    14,    91,    92,    93,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,   104,   105,   106,   107,   108,   109,   110,    39,     3,
      12,    11,    33,    14,   265,   266,    41,   268,   269,    39,
      14,    15,   104,   105,   106,   107,   108,   109,   110,    14,
      34,    98,    26,    86,    87,    88,    89,    31,    14,    13,
      24,    24,    36,    37,    40,    84,    33,    26,    13,    10,
     301,    39,    30,    30,    53,    30,    85,    30,     3,   112,
      30,     6,     7,     8,     9,    10,    11,    30,    30,    33,
      15,    30,    17,    18,    30,    20,    21,   328,    14,    33,
      25,    26,    27,    28,    29,    33,    31,    84,    30,    84,
      24,    31,    31,    38,    31,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,   376,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    33,    98,    31,    31,    31,    14,   111,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,     3,
      32,    14,     6,     7,     8,     9,    10,    11,    14,    14,
      24,    15,    14,    39,    18,    34,    20,    21,    34,    84,
      84,    25,    26,    27,    28,    29,    14,    31,    14,    84,
      14,    34,    15,    31,    38,    34,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    34,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    53,    98,    33,    96,    92,   105,   159,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       6,     7,     8,     9,    10,   126,   146,   310,   342,    15,
     151,   408,    18,    19,    20,    21,   407,   269,   229,    25,
      26,    27,    28,   325,   323,    -1,    -1,    -1,   268,   290,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     6,     7,
       8,     9,    10,    -1,    12,    -1,    -1,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    15,    -1,    -1,    18,    19,    20,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    18,    -1,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     6,   115,   116,     6,     7,     8,     9,    10,    15,
      18,    19,    20,    21,    25,    26,    27,    28,    38,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    98,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   117,   118,   196,     0,
       8,     9,   119,   120,    25,    23,    25,    31,   121,    28,
     120,   136,    26,   117,    26,   122,    10,   123,   127,   117,
     137,   138,     5,   141,    27,    27,   123,    14,   124,    30,
     139,    12,    39,   128,   138,   117,   142,   143,   172,     4,
     159,     7,    16,   117,   140,   138,   128,   143,   144,   160,
      14,   125,    22,    23,    24,    30,   145,   146,     9,    42,
     113,   161,   162,   163,     3,    11,    29,    31,   117,   129,
     130,   131,   132,   117,   117,   117,   147,    32,   146,    38,
      31,    33,   128,   162,    32,   133,    17,   131,    22,    19,
     117,   152,   164,    14,   134,   172,   126,   117,    24,    24,
      11,   149,   117,   167,    39,    13,    29,   128,   117,   171,
     117,    14,   148,    11,    33,    14,   135,    41,   150,   151,
      13,    39,    39,   153,    14,    19,   117,   168,   169,   170,
      34,   172,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    86,    87,    88,    89,   112,   173,    98,
      14,    21,    62,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    91,
      92,    93,   154,   155,    13,    24,    24,    34,    39,    40,
      84,    33,   177,   177,   104,   105,   106,   107,   108,   109,
     110,   184,   185,   187,   104,   105,   106,   107,   108,   109,
     110,   178,   181,   182,   117,    26,    13,    10,    30,    30,
      30,    53,    30,    30,    30,    30,    82,    83,    30,    30,
      39,    35,   117,    35,   117,    85,   165,   170,   169,    33,
      14,    33,   188,    84,   188,    84,    33,   179,    24,    30,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   157,   158,    31,    14,    31,    90,   156,   117,
      31,    33,    31,    31,    31,    31,   155,   111,    32,   166,
      14,    34,    39,    14,   180,   186,   187,   182,   183,    14,
     117,    14,    97,   158,   189,   190,    24,     3,    14,    15,
      26,    31,    36,    37,   174,   175,   176,    39,    14,    34,
      34,    14,    15,    31,    33,    98,   101,   191,   192,   193,
     194,   117,    84,    84,    14,    14,    34,    39,    84,    14,
      34,   192,   192,    95,    96,    30,    53,    94,    98,    99,
     100,   102,   103,    15,    31,   176,   175,    34,    34,   192,
     192,   193,   193,   193,    53,   193,    33,   193,    96,   193,
     195,   193,    34,    39,   193
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
#line 95 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 98 "screen.yacc"
    {the_form.dbname=strdup("formonly");}
    break;

  case 4:
#line 99 "screen.yacc"
    {the_form.dbname=(yyvsp[-3].str);
if (A4GLF_open_db(yyvsp[-3].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 104 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 105 "screen.yacc"
    {the_form.dbname=strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 10:
#line 118 "screen.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 13:
#line 124 "screen.yacc"
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
#line 137 "screen.yacc"
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
#line 157 "screen.yacc"
    { ignorekw=1; 
		lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 18:
#line 159 "screen.yacc"
    { lineno=0; }
    break;

  case 19:
#line 162 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 171 "screen.yacc"
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
#line 193 "screen.yacc"
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
#line 206 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	     A4GL_add_field("_label",1+colno-strlen(yyvsp[0].str),lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
}
    break;

  case 31:
#line 212 "screen.yacc"
    {
	char buff[256];
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	strcpy(buff,yyvsp[0].str);
	if (buff[0]=='\n') A4GL_add_field("_label",1+colno-1,lineno,1,scr,0,yyvsp[0].str);
	else A4GL_add_field("_label",1+colno-strlen(yyvsp[0].str),lineno,1,scr,0,yyvsp[0].str);
}
    break;

  case 32:
#line 220 "screen.yacc"
    {
	char buff[256];
	strcpy(buff,yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (buff[0]=='\n') A4GL_add_field("_label",1+colno-1,lineno,1,scr,0,yyvsp[0].str);
	else A4GL_add_field("_label",1+colno-strlen(yyvsp[0].str),lineno,1,scr,0,yyvsp[0].str);
}
    break;

  case 33:
#line 230 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	     A4GL_add_field("_label",1+colno-strlen(yyvsp[0].str),lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
}
    break;

  case 34:
#line 241 "screen.yacc"
    {
	fstart=colno;
	openwith='[';
}
    break;

  case 35:
#line 247 "screen.yacc"
    {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 36:
#line 258 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 37:
#line 263 "screen.yacc"
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

  case 38:
#line 277 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 44:
#line 292 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 45:
#line 299 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 46:
#line 300 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 47:
#line 303 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 48:
#line 304 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 49:
#line 306 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 50:
#line 307 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 51:
#line 308 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 55:
#line 322 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 59:
#line 334 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 60:
#line 338 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 61:
#line 348 "screen.yacc"
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

  case 63:
#line 363 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 64:
#line 367 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 65:
#line 375 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 66:
#line 376 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 67:
#line 379 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 68:
#line 380 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 69:
#line 383 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 70:
#line 386 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 71:
#line 391 "screen.yacc"
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

  case 72:
#line 400 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 73:
#line 407 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 78:
#line 423 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 79:
#line 424 "screen.yacc"
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

  case 80:
#line 444 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 81:
#line 445 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 82:
#line 446 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 83:
#line 447 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 84:
#line 448 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 85:
#line 449 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 86:
#line 450 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 87:
#line 451 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 88:
#line 452 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 89:
#line 453 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 90:
#line 454 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 91:
#line 455 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 92:
#line 457 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 93:
#line 458 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 94:
#line 459 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 95:
#line 460 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 96:
#line 461 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 97:
#line 462 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 98:
#line 465 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 99:
#line 468 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_VERIFY);
}
    break;

  case 100:
#line 471 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 101:
#line 474 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 102:
#line 478 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 105:
#line 486 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 107:
#line 488 "screen.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str));
}
    break;

  case 108:
#line 494 "screen.yacc"
    {
	strcpy(yyval.str,"0");
}
    break;

  case 109:
#line 497 "screen.yacc"
    {
	strcpy(yyval.str,"4");
}
    break;

  case 110:
#line 500 "screen.yacc"
    {
	strcpy(yyval.str,"2");
}
    break;

  case 111:
#line 503 "screen.yacc"
    {
	strcpy(yyval.str,"6"); 
}
    break;

  case 112:
#line 506 "screen.yacc"
    {
	strcpy(yyval.str,"1");
}
    break;

  case 113:
#line 509 "screen.yacc"
    {
	strcpy(yyval.str,"5"); 
}
    break;

  case 114:
#line 512 "screen.yacc"
    {
	strcpy(yyval.str,"7");
}
    break;

  case 115:
#line 515 "screen.yacc"
    {
	strcpy(yyval.str,"3");
}
    break;

  case 116:
#line 518 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE"));
}
    break;

  case 117:
#line 521 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT"));
}
    break;

  case 118:
#line 524 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK"));
}
    break;

  case 119:
#line 527 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE"));
}
    break;

  case 121:
#line 532 "screen.yacc"
    {
}
    break;

  case 127:
#line 542 "screen.yacc"
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

  case 128:
#line 552 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 135:
#line 563 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 136:
#line 566 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 137:
#line 572 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 138:
#line 575 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 139:
#line 581 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 140:
#line 583 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 141:
#line 585 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 142:
#line 587 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 143:
#line 589 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 145:
#line 593 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 146:
#line 597 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 147:
#line 603 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 148:
#line 610 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 149:
#line 614 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 150:
#line 618 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 151:
#line 622 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 152:
#line 626 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 153:
#line 630 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 154:
#line 634 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 155:
#line 638 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 156:
#line 642 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 157:
#line 646 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 158:
#line 650 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 159:
#line 654 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 160:
#line 658 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 161:
#line 662 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 162:
#line 665 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 164:
#line 672 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 167:
#line 677 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 168:
#line 682 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 169:
#line 683 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 170:
#line 684 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 171:
#line 685 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 173:
#line 687 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 174:
#line 690 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 175:
#line 694 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 176:
#line 700 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 701 "screen.yacc"
    {sprintf(yyval.str,"16.%d",atoi(yyvsp[-1].str));}
    break;

  case 178:
#line 702 "screen.yacc"
    {sprintf(yyval.str,"%d.%d",atoi(yyvsp[-3].str),atoi(yyvsp[-1].str));}
    break;

  case 179:
#line 705 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 180:
#line 707 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 181:
#line 713 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 182:
#line 715 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 183:
#line 720 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 184:
#line 728 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 185:
#line 731 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 186:
#line 732 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 187:
#line 733 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 188:
#line 734 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 189:
#line 735 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 190:
#line 736 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 191:
#line 738 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 193:
#line 745 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 194:
#line 746 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 195:
#line 749 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 196:
#line 752 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 197:
#line 756 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 198:
#line 757 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 199:
#line 758 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 200:
#line 759 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 201:
#line 760 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 202:
#line 761 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 203:
#line 763 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 204:
#line 768 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 205:
#line 770 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 206:
#line 777 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 207:
#line 777 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 208:
#line 783 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 210:
#line 790 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 211:
#line 793 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 212:
#line 799 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 213:
#line 802 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
		}
    break;

  case 214:
#line 805 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE");
		}
    break;

  case 215:
#line 808 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str);
	}
    break;

  case 216:
#line 811 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL");
	}
    break;

  case 217:
#line 816 "screen.yacc"
    {
		void *p;
		p=create_char_expr("ISNOTNULL");
		yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL");
	}
    break;

  case 218:
#line 821 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
			//create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
    break;

  case 219:
#line 825 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[-2].expr);
		add_list_expr(yyval.expr,yyvsp[0].expr);
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN");
	}
    break;

  case 220:
#line 831 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN");
	}
    break;

  case 221:
#line 834 "screen.yacc"
    {
		yyval.expr=create_not_expr(yyvsp[0].expr);
	}
    break;

  case 222:
#line 837 "screen.yacc"
    {
		yyval.expr=yyvsp[-1].expr;
	}
    break;

  case 223:
#line 842 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 224:
#line 849 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str));
printf("NUMBER VALUE : %s\n",yyvsp[0].str);
}
    break;

  case 225:
#line 852 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 226:
#line 853 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 228:
#line 861 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 229:
#line 865 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 3157 "y.tab.c"

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


#line 955 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */




