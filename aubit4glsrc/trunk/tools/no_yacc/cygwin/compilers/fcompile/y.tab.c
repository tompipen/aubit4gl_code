/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
     REVERSE = 322,
     LEFT = 323,
     BLINK = 324,
     UNDERLINE = 325,
     AUTONEXT = 326,
     COLOR = 327,
     COMMENTS = 328,
     DEFAULT = 329,
     VALIDATE = 330,
     DISPLAY = 331,
     DOWNSHIFT = 332,
     UPSHIFT = 333,
     FORMAT = 334,
     INCLUDE = 335,
     INVISIBLE = 336,
     NOUPDATE = 337,
     NOENTRY = 338,
     PICTURE = 339,
     PROGRAM = 340,
     REQUIRED = 341,
     QUERYCLEAR = 342,
     VERIFY = 343,
     WORDWRAP = 344,
     COMPRESS = 345,
     NONCOMPRESS = 346,
     TO = 347,
     AS = 348,
     SERIAL = 349,
     KW_BYTE = 350,
     KW_TEXT = 351,
     VARCHAR = 352,
     SQL_VAR = 353,
     KW_NONSPACE = 354,
     SQLONLY = 355,
     WIDGET = 356,
     CONFIG = 357,
     KW_NL = 358,
     COMPARISON = 359,
     LESSTHAN = 360,
     GREATERTHAN = 361,
     KWOR = 362,
     KWAND = 363,
     KWAND1 = 364,
     KWWHERE = 365,
     KWNOT = 366,
     KWBETWEEN = 367,
     KWIN = 368,
     XVAL = 369,
     KWNULLCHK = 370,
     KWNOTNULLCHK = 371,
     YEAR = 372,
     MONTH = 373,
     DAY = 374,
     HOUR = 375,
     MINUTE = 376,
     SECOND = 377,
     FRACTION = 378,
     LISTBOX = 379,
     BUTTON = 380,
     KW_PANEL = 381,
     DISPLAYONLY = 382,
     ALLOWING = 383,
     KW_WS = 384,
     KW_TAB = 385,
     KW_MASTER_OF = 386,
     KW_BEFORE = 387,
     KW_AFTER = 388,
     KW_EDITADD = 389,
     KW_EDITUPDATE = 390,
     KW_REMOVE = 391,
     KW_OF = 392,
     KW_ADD = 393,
     KW_UPDATE = 394,
     KW_QUERY = 395,
     KW_ON_ENDING = 396,
     KW_ON_BEGINNING = 397,
     KW_CALL = 398,
     KW_BELL = 399,
     KW_ABORT = 400,
     KW_LET = 401,
     KW_EXITNOW = 402,
     KW_NEXTFIELD = 403,
     KW_IF = 404,
     KW_THEN = 405,
     KW_ELSE = 406,
     KW_BEGIN = 407,
     KW_TOTAL = 408,
     KW_RIGHT = 409,
     KW_ZEROFILL = 410
   };
#endif
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
#define REVERSE 322
#define LEFT 323
#define BLINK 324
#define UNDERLINE 325
#define AUTONEXT 326
#define COLOR 327
#define COMMENTS 328
#define DEFAULT 329
#define VALIDATE 330
#define DISPLAY 331
#define DOWNSHIFT 332
#define UPSHIFT 333
#define FORMAT 334
#define INCLUDE 335
#define INVISIBLE 336
#define NOUPDATE 337
#define NOENTRY 338
#define PICTURE 339
#define PROGRAM 340
#define REQUIRED 341
#define QUERYCLEAR 342
#define VERIFY 343
#define WORDWRAP 344
#define COMPRESS 345
#define NONCOMPRESS 346
#define TO 347
#define AS 348
#define SERIAL 349
#define KW_BYTE 350
#define KW_TEXT 351
#define VARCHAR 352
#define SQL_VAR 353
#define KW_NONSPACE 354
#define SQLONLY 355
#define WIDGET 356
#define CONFIG 357
#define KW_NL 358
#define COMPARISON 359
#define LESSTHAN 360
#define GREATERTHAN 361
#define KWOR 362
#define KWAND 363
#define KWAND1 364
#define KWWHERE 365
#define KWNOT 366
#define KWBETWEEN 367
#define KWIN 368
#define XVAL 369
#define KWNULLCHK 370
#define KWNOTNULLCHK 371
#define YEAR 372
#define MONTH 373
#define DAY 374
#define HOUR 375
#define MINUTE 376
#define SECOND 377
#define FRACTION 378
#define LISTBOX 379
#define BUTTON 380
#define KW_PANEL 381
#define DISPLAYONLY 382
#define ALLOWING 383
#define KW_WS 384
#define KW_TAB 385
#define KW_MASTER_OF 386
#define KW_BEFORE 387
#define KW_AFTER 388
#define KW_EDITADD 389
#define KW_EDITUPDATE 390
#define KW_REMOVE 391
#define KW_OF 392
#define KW_ADD 393
#define KW_UPDATE 394
#define KW_QUERY 395
#define KW_ON_ENDING 396
#define KW_ON_BEGINNING 397
#define KW_CALL 398
#define KW_BELL 399
#define KW_ABORT 400
#define KW_LET 401
#define KW_EXITNOW 402
#define KW_NEXTFIELD 403
#define KW_IF 404
#define KW_THEN 405
#define KW_ELSE 406
#define KW_BEGIN 407
#define KW_TOTAL 408
#define KW_RIGHT 409
#define KW_ZEROFILL 410




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

int doing_4gl();



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
#line 77 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 473 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 485 "y.tab.c"

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
#define YYFINAL  92
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2789

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  156
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  130
/* YYNRULES -- Number of rules. */
#define YYNRULES  451
/* YYNRULES -- Number of states. */
#define YYNSTATES  679

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   410

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
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155
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
     168,   170,   173,   174,   179,   181,   184,   188,   189,   190,
     197,   198,   202,   208,   212,   214,   215,   221,   225,   228,
     233,   236,   241,   245,   247,   252,   255,   257,   259,   263,
     267,   271,   273,   277,   279,   284,   287,   289,   292,   293,
     296,   298,   302,   304,   309,   314,   318,   322,   326,   332,
     336,   342,   344,   346,   350,   356,   360,   364,   366,   371,
     373,   375,   377,   379,   383,   387,   389,   391,   393,   395,
     397,   399,   401,   404,   407,   409,   411,   413,   415,   418,
     420,   422,   424,   426,   428,   430,   432,   434,   436,   438,
     440,   442,   444,   445,   446,   451,   453,   456,   458,   461,
     464,   465,   475,   488,   490,   492,   494,   495,   498,   499,
     501,   502,   504,   506,   511,   513,   517,   518,   520,   522,
     526,   530,   534,   538,   540,   544,   546,   547,   549,   551,
     554,   556,   558,   560,   561,   566,   568,   570,   572,   574,
     576,   578,   581,   584,   587,   590,   592,   594,   596,   598,
     600,   602,   606,   608,   611,   614,   616,   618,   622,   624,
     626,   630,   634,   636,   637,   641,   647,   648,   652,   653,
     657,   659,   662,   664,   666,   668,   670,   672,   674,   677,
     679,   680,   684,   686,   688,   690,   692,   694,   696,   698,
     700,   703,   704,   708,   709,   711,   714,   716,   720,   724,
     728,   732,   736,   740,   745,   749,   752,   755,   757,   763,
     769,   772,   776,   778,   780,   782,   784,   786,   788,   792,
     801,   803,   807,   811,   813,   815,   821,   827,   830,   833,
     835,   837,   839,   841,   843,   845,   847,   853,   854,   857,
     859,   864,   867,   871,   874,   878,   882,   884,   887,   890,
     894,   898,   900,   903,   905,   908,   910,   912,   914,   916,
     918,   920,   922,   924,   926,   928,   930,   934,   938,   940,
     945,   951,   952,   954,   956,   960,   962,   964,   968,   972,
     973,   975,   977,   981,   985,   989,   993,   997,  1001,  1005,
    1009,  1013,  1018,  1022,  1025,  1028,  1030,  1036,  1042,  1045,
    1049,  1054,  1058,  1060,  1062,  1064,  1066,  1068,  1070,  1074,
    1076,  1078,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,
    1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,
    1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,  1132,  1134,
    1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,  1152,  1154,
    1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,  1172,  1174,
    1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,
    1196,  1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,  1214,
    1216,  1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,
    1236,  1238
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     157,     0,    -1,   158,   161,   179,   184,   208,    -1,     8,
      21,    -1,     8,   160,    27,    28,    29,    -1,     8,    21,
      27,    28,    29,    -1,     8,   160,    -1,    17,    -1,   285,
      -1,   159,    -1,   159,    25,   159,    -1,   162,    -1,   161,
     162,    -1,    -1,    11,   163,   165,    -1,    -1,    10,    33,
     164,   165,    -1,    -1,    -1,    -1,   169,   166,    18,   167,
     171,    19,   168,   170,    -1,    -1,    12,    16,    -1,    12,
      16,     9,    16,    -1,    -1,    14,    -1,   173,    -1,   171,
     173,    -1,   159,    -1,   172,    -1,   175,    -1,   130,    -1,
       4,    -1,    31,    -1,    33,    -1,   174,    -1,   129,    -1,
     103,    -1,    99,    -1,     3,    -1,   174,     3,    -1,    -1,
      13,   176,   177,    15,    -1,   227,    -1,    -1,   177,    31,
     178,   227,    -1,    -1,    30,   180,   170,    -1,   181,    -1,
     180,   181,    -1,   180,    44,   181,    -1,   159,   182,    -1,
      -1,    32,   183,    -1,   159,    -1,   159,    24,   159,    -1,
     159,    25,   159,    -1,   159,    25,   159,    24,   159,    -1,
     159,    26,   159,    -1,     7,   185,   170,    -1,   186,    -1,
     185,   186,    -1,    -1,   226,   187,   188,    34,    -1,   189,
      -1,   188,   189,    -1,   188,    34,   189,    -1,    -1,    -1,
      32,   190,   195,   192,   191,   202,    -1,    -1,    13,    16,
      15,    -1,    13,    16,    44,    16,    15,    -1,   194,   111,
      28,    -1,   194,    -1,    -1,    46,    58,   159,    26,   159,
      -1,    46,    58,   159,    -1,    46,   229,    -1,    21,    26,
     222,   193,    -1,   127,   193,    -1,   127,   128,    29,   193,
      -1,   159,    26,   159,    -1,   159,    -1,    39,   159,    26,
     159,    -1,    39,   159,    -1,   226,    -1,   198,    -1,   197,
      44,   198,    -1,   196,    32,   199,    -1,   159,    26,   159,
      -1,   159,    -1,   159,    26,   159,    -1,   159,    -1,    39,
     159,    26,   159,    -1,    39,   159,    -1,    36,    -1,    44,
      36,    -1,    -1,    44,   203,    -1,   204,    -1,   203,    44,
     204,    -1,    71,    -1,    72,    32,   206,   245,    -1,    35,
     197,   201,   200,    -1,    73,    32,    33,    -1,    74,    32,
     205,    -1,    76,    58,   159,    -1,    76,    58,   159,    26,
     159,    -1,    75,    58,   159,    -1,    75,    58,   159,    26,
     159,    -1,    77,    -1,    78,    -1,    79,    32,    33,    -1,
      80,    32,    37,   230,    38,    -1,   101,    32,    33,    -1,
     102,    32,    33,    -1,    81,    -1,    23,    12,    32,    16,
      -1,    23,    -1,   100,    -1,    83,    -1,    82,    -1,    84,
      32,    33,    -1,    85,    32,    33,    -1,    86,    -1,    67,
      -1,    88,    -1,    87,    -1,   155,    -1,   154,    -1,    89,
      -1,    89,    90,    -1,    89,    91,    -1,    33,    -1,    16,
      -1,    98,    -1,   207,    -1,   206,   207,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    16,    -1,    67,    -1,    68,    -1,
      69,    -1,    70,    -1,    -1,    -1,     6,   209,   210,   170,
      -1,   211,    -1,   210,   211,    -1,   212,    -1,   212,    34,
      -1,    47,    33,    -1,    -1,    11,    43,   213,   217,    37,
     218,    38,   214,   216,    -1,   126,    37,    16,    44,    16,
      38,    92,    37,    16,    44,    16,    38,    -1,   252,    -1,
     273,    -1,   257,    -1,    -1,    93,   124,    -1,    -1,    39,
      -1,    -1,    34,    -1,   159,    -1,   159,    13,    16,    15,
      -1,   221,    -1,   218,   219,   221,    -1,    -1,    44,    -1,
     159,    -1,   159,    26,   159,    -1,    21,    26,   159,    -1,
     159,    26,    39,    -1,    21,    26,    39,    -1,   220,    -1,
     220,    45,   220,    -1,   159,    -1,    -1,   224,    -1,   225,
      -1,   224,   225,    -1,   129,    -1,   130,    -1,   159,    -1,
      -1,   223,   159,   228,   223,    -1,    48,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,   233,
      -1,    55,   233,    -1,    56,   240,    -1,    57,   234,    -1,
      94,    -1,    95,    -1,    96,    -1,    97,    -1,   125,    -1,
     232,    -1,   230,    44,   232,    -1,    16,    -1,    41,    16,
      -1,    42,    16,    -1,    33,    -1,    17,    -1,    17,    92,
      17,    -1,     3,    -1,   231,    -1,   231,    92,   231,    -1,
      33,    92,    33,    -1,    28,    -1,    -1,    37,    16,    38,
      -1,    37,    16,    44,    16,    38,    -1,    -1,   237,    92,
     239,    -1,    -1,    37,    16,    38,    -1,    16,    -1,   238,
     235,    -1,   117,    -1,   118,    -1,   119,    -1,   120,    -1,
     121,    -1,   122,    -1,   123,   244,    -1,   238,    -1,    -1,
     241,    92,   242,    -1,   243,    -1,   243,    -1,   117,    -1,
     118,    -1,   119,    -1,   120,    -1,   121,    -1,   122,    -1,
     123,   244,    -1,    -1,    37,   236,    38,    -1,    -1,   246,
      -1,   110,   247,    -1,   248,    -1,   248,   108,   248,    -1,
     248,   107,   248,    -1,   249,   104,   249,    -1,   249,   105,
     249,    -1,   249,   106,   249,    -1,   249,    58,   249,    -1,
     249,   111,    58,   249,    -1,   249,    32,   249,    -1,   249,
     115,    -1,   249,   116,    -1,   249,    -1,   249,   112,   249,
     108,   249,    -1,   249,   113,    37,   251,    38,    -1,   111,
     248,    -1,    37,   248,    38,    -1,   250,    -1,    16,    -1,
      33,    -1,   114,    -1,    17,    -1,   249,    -1,   251,    44,
     249,    -1,     5,   105,   253,   106,   215,   105,   253,   106,
      -1,   254,    -1,   253,    44,   254,    -1,   255,    26,   256,
      -1,   159,    -1,   159,    -1,   132,   267,   137,   271,   265,
      -1,   133,   268,   137,   271,   265,    -1,   142,   274,    -1,
     141,   274,    -1,   261,    -1,   266,    -1,   259,    -1,   262,
      -1,   263,    -1,   274,    -1,   264,    -1,   149,   278,   150,
     258,   260,    -1,    -1,   151,   258,    -1,   145,    -1,   146,
     226,    32,   278,    -1,   148,   226,    -1,   148,    32,   226,
      -1,   148,   147,    -1,   148,    32,   147,    -1,   152,   265,
      14,    -1,   258,    -1,   265,   258,    -1,    73,    33,    -1,
      73,   144,    33,    -1,    73,    67,    33,    -1,   269,    -1,
     267,   269,    -1,   270,    -1,   268,   270,    -1,   134,    -1,
     135,    -1,   136,    -1,   134,    -1,   138,    -1,   139,    -1,
     140,    -1,   136,    -1,    76,    -1,   135,    -1,   272,    -1,
     271,    44,   272,    -1,   255,    26,   256,    -1,   256,    -1,
     255,   131,   255,   216,    -1,   143,   159,    37,   275,    38,
      -1,    -1,   276,    -1,   277,    -1,   276,    44,   277,    -1,
     278,    -1,   281,    -1,   278,   108,   278,    -1,   278,   107,
     278,    -1,    -1,   280,    -1,   278,    -1,   280,    44,   278,
      -1,   278,   104,   278,    -1,   278,   105,   278,    -1,   278,
     106,   278,    -1,   278,    39,   278,    -1,   278,    41,   278,
      -1,   278,    42,   278,    -1,   278,    40,   278,    -1,   278,
      58,   278,    -1,   278,   111,    58,   278,    -1,   278,    32,
     278,    -1,   278,   115,    -1,   278,   116,    -1,   283,    -1,
     278,   112,   278,   108,   278,    -1,   278,   113,    37,   284,
      38,    -1,   111,   278,    -1,    37,   278,    38,    -1,   282,
      37,   279,    38,    -1,   153,   137,   226,    -1,   159,    -1,
     226,    -1,    16,    -1,    33,    -1,   114,    -1,   283,    -1,
     284,    44,   283,    -1,    93,    -1,    71,    -1,    59,    -1,
      69,    -1,    60,    -1,   107,    -1,   108,    -1,   104,    -1,
     125,    -1,     9,    -1,    72,    -1,    22,    -1,    73,    -1,
      90,    -1,   102,    -1,    62,    -1,     8,    -1,    56,    -1,
      74,    -1,    47,    -1,    77,    -1,    23,    -1,    79,    -1,
      61,    -1,    80,    -1,    29,    -1,    57,    -1,    81,    -1,
      95,    -1,    48,    -1,    50,    -1,    54,    -1,    51,    -1,
      49,    -1,    28,    -1,   126,    -1,    11,    -1,    10,    -1,
      12,    -1,    96,    -1,    68,    -1,   124,    -1,    64,    -1,
      55,    -1,    83,    -1,    91,    -1,   111,    -1,    84,    -1,
      85,    -1,    43,    -1,    63,    -1,    86,    -1,    67,    -1,
      94,    -1,    52,    -1,    53,    -1,   100,    -1,    98,    -1,
      30,    -1,    45,    -1,    20,    -1,    92,    -1,    70,    -1,
      78,    -1,    97,    -1,    88,    -1,    35,    -1,    36,    -1,
      65,    -1,   101,    -1,    27,    -1,    89,    -1,    87,    -1,
      66,    -1,    46,    -1,    58,    -1,   117,    -1,   118,    -1,
     119,    -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   114,   114,   117,   118,   123,   124,   132,   133,   137,
     137,   140,   140,   143,   143,   156,   156,   176,   178,   181,
     175,   188,   189,   190,   202,   203,   208,   209,   212,   227,
     237,   238,   249,   261,   274,   284,   293,   298,   301,   309,
     310,   316,   315,   337,   340,   340,   358,   359,   362,   363,
     364,   367,   374,   375,   378,   379,   380,   382,   383,   389,
     393,   393,   397,   397,   407,   408,   409,   413,   417,   413,
     454,   455,   459,   467,   468,   471,   472,   475,   478,   483,
     492,   504,   516,   524,   532,   540,   550,   554,   555,   558,
     561,   562,   566,   567,   568,   569,   572,   573,   577,   578,
     582,   582,   585,   586,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   622,
     623,   624,   625,   626,   627,   628,   631,   634,   635,   636,
     637,   638,   641,   645,   651,   652,   653,   655,   655,   661,
     662,   663,   664,   665,   666,   667,   668,   670,   684,   685,
     686,   687,   691,   692,   692,   697,   697,   699,   699,   702,
     712,   712,   715,   716,   717,   718,   722,   722,   724,   724,
     726,   726,   729,   732,   748,   751,   755,   756,   760,   762,
     764,   766,   768,   773,   773,   777,   783,   783,   786,   786,
     790,   791,   804,   812,   812,   821,   825,   829,   833,   837,
     841,   845,   849,   853,   857,   861,   865,   869,   873,   876,
     883,   883,   888,   888,   888,   893,   894,   895,   896,   897,
     898,   901,   905,   911,   912,   913,   916,   917,   924,   926,
     931,   939,   942,   943,   944,   945,   946,   947,   948,   954,
     956,   957,   960,   963,   967,   968,   969,   970,   971,   972,
     973,   979,   981,   988,   988,   994,  1000,  1001,  1004,  1010,
    1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1025,  1032,  1033,  1034,  1039,  1042,  1046,  1058,
    1061,  1062,  1065,  1068,  1071,  1075,  1076,  1077,  1078,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1093,  1097,  1097,  1100,
    1103,  1106,  1107,  1108,  1109,  1113,  1116,  1117,  1122,  1123,
    1124,  1129,  1129,  1133,  1133,  1137,  1138,  1139,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1152,  1153,  1157,  1158,  1162,
    1165,  1168,  1168,  1172,  1172,  1175,  1180,  1181,  1184,  1189,
    1190,  1193,  1194,  1198,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1219,  1222,  1223,  1224,  1225,  1228,  1232,  1244,
    1245,  1246,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,
    1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,
    1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,
    1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,
    1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CH", "GRAPH_CH", "KW_COMPOSITES", 
  "INSTRUCTIONS", "ATTRIBUTES", "DATABASE", "BY", "KW_SCREEN_TITLE", 
  "KW_SCREEN", "KW_SIZE", "OPEN_SQUARE", "KW_END", "CLOSE_SQUARE", 
  "NUMBER_VALUE", "NAMED", "OPEN_BRACE", "CLOSE_BRACE", "TITLE", 
  "FORMONLY", "COMMENT", "DYNAMIC", "COLON", "ATSIGN", "DOT", "WITHOUT", 
  "KW_NULL", "INPUT", "TABLES", "PIPE", "EQUAL", "CHAR_VALUE", 
  "SEMICOLON", "LOOKUP", "JOINING", "OPEN_BRACKET", "CLOSE_BRACKET", 
  "STAR", "DIVIDE", "PLUS", "MINUS", "RECORD", "COMMA", "THROUGH", "TYPE", 
  "DELIMITERS", "KW_CHAR", "KW_INT", "KW_DATE", "KW_FLOAT", "SMALLFLOAT", 
  "SMALLINT", "KW_DECIMAL", "MONEY", "DATETIME", "INTERVAL", "LIKE", 
  "BLACK", "BLUE", "GREEN", "CYAN", "RED", "MAGENTA", "WHITE", "YELLOW", 
  "REVERSE", "LEFT", "BLINK", "UNDERLINE", "AUTONEXT", "COLOR", 
  "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY", "DOWNSHIFT", "UPSHIFT", 
  "FORMAT", "INCLUDE", "INVISIBLE", "NOUPDATE", "NOENTRY", "PICTURE", 
  "PROGRAM", "REQUIRED", "QUERYCLEAR", "VERIFY", "WORDWRAP", "COMPRESS", 
  "NONCOMPRESS", "TO", "AS", "SERIAL", "KW_BYTE", "KW_TEXT", "VARCHAR", 
  "SQL_VAR", "KW_NONSPACE", "SQLONLY", "WIDGET", "CONFIG", "KW_NL", 
  "COMPARISON", "LESSTHAN", "GREATERTHAN", "KWOR", "KWAND", "KWAND1", 
  "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", 
  "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", 
  "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY", "ALLOWING", 
  "KW_WS", "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", 
  "KW_EDITADD", "KW_EDITUPDATE", "KW_REMOVE", "KW_OF", "KW_ADD", 
  "KW_UPDATE", "KW_QUERY", "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL", 
  "KW_BELL", "KW_ABORT", "KW_LET", "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF", 
  "KW_THEN", "KW_ELSE", "KW_BEGIN", "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL", 
  "$accept", "form_def", "database_section", "named_or_kw", "dbname", 
  "screen_section", "screens_section", "@1", "@2", "screens_rest", "@3", 
  "@4", "@5", "op_size", "op_end", "screen_layout", "some_text", 
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
  "dt_end", "dtime_val", "opt_frac", "op_where", "where_clause", 
  "clauses", "clause", "value", "fieldidentifier", "value_list", 
  "composites", "comp_list", "comp_item", "table_name", "column_name", 
  "control_block", "action", "if", "op_else", "abort", "let", "nextfield", 
  "block", "actions", "comments", "bef_act_list", "aft_act_list", 
  "bef_act", "aft_act", "column_list", "column_entry", "master_of", 
  "func_call", "op_func_call_args", "func_call_args", "func_call_arg", 
  "expression", "op_expression_list", "expression_list", 
  "single_expression", "fcall_name", "evalue", "evalue_list", "any_kword", 0
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   156,   157,   158,   158,   158,   158,   159,   159,   160,
     160,   161,   161,   163,   162,   164,   162,   166,   167,   168,
     165,   169,   169,   169,   170,   170,   171,   171,   172,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   174,
     174,   176,   175,   177,   178,   177,   179,   179,   180,   180,
     180,   181,   182,   182,   183,   183,   183,   183,   183,   184,
     185,   185,   187,   186,   188,   188,   188,   190,   191,   189,
     192,   192,   192,   193,   193,   194,   194,   194,   194,   195,
     195,   195,   195,   195,   195,   195,   196,   197,   197,   198,
     199,   199,   200,   200,   200,   200,   201,   201,   202,   202,
     203,   203,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   205,   205,   205,   206,   206,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   208,   209,   208,   210,   210,   211,   211,   212,
     213,   212,   212,   212,   212,   212,   214,   214,   215,   215,
     216,   216,   217,   217,   218,   218,   219,   219,   220,   220,
     220,   220,   220,   221,   221,   222,   223,   223,   224,   224,
     225,   225,   226,   228,   227,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     230,   230,   231,   231,   231,   232,   232,   232,   232,   232,
     232,   232,   232,   233,   233,   233,   234,   234,   235,   235,
     236,   237,   238,   238,   238,   238,   238,   238,   238,   239,
     240,   240,   241,   242,   243,   243,   243,   243,   243,   243,
     243,   244,   244,   245,   245,   246,   247,   247,   247,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   249,   249,   249,   249,   250,   251,   251,   252,
     253,   253,   254,   255,   256,   257,   257,   257,   257,   258,
     258,   258,   258,   258,   258,   258,   259,   260,   260,   261,
     262,   263,   263,   263,   263,   264,   265,   265,   266,   266,
     266,   267,   267,   268,   268,   269,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   271,   271,   272,   272,   273,
     274,   275,   275,   276,   276,   277,   278,   278,   278,   279,
     279,   280,   280,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   282,   283,   283,   283,   283,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285
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
       1,     2,     0,     4,     1,     2,     3,     0,     0,     6,
       0,     3,     5,     3,     1,     0,     5,     3,     2,     4,
       2,     4,     3,     1,     4,     2,     1,     1,     3,     3,
       3,     1,     3,     1,     4,     2,     1,     2,     0,     2,
       1,     3,     1,     4,     4,     3,     3,     3,     5,     3,
       5,     1,     1,     3,     5,     3,     3,     1,     4,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     4,     1,     2,     1,     2,     2,
       0,     9,    12,     1,     1,     1,     0,     2,     0,     1,
       0,     1,     1,     4,     1,     3,     0,     1,     1,     3,
       3,     3,     3,     1,     3,     1,     0,     1,     1,     2,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     2,     1,     1,     3,     1,     1,
       3,     3,     1,     0,     3,     5,     0,     3,     0,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     3,     0,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     4,     3,     2,     2,     1,     5,     5,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     8,
       1,     3,     3,     1,     1,     5,     5,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     5,     0,     2,     1,
       4,     2,     3,     2,     3,     3,     1,     2,     2,     3,
       3,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     4,
       5,     0,     1,     1,     3,     1,     1,     3,     3,     0,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     2,     2,     1,     5,     5,     2,     3,
       4,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   385,   378,   406,   405,   407,     7,
     429,     3,   380,   390,   439,   403,   394,   427,   435,   436,
     418,   428,   443,   388,   398,   402,   399,   401,   423,   424,
     400,   412,   386,   395,   444,   371,   373,   392,   384,   419,
     411,   437,   442,   421,   409,   372,   431,   370,   379,   381,
     387,   389,   432,   391,   393,   396,   413,   416,   417,   420,
     441,   434,   440,   382,   414,   430,   369,   422,   397,   408,
     433,   426,   425,   438,   383,   376,   374,   375,   415,   445,
     446,   447,   448,   449,   450,   451,   410,   377,   404,     9,
       6,     8,     1,     0,    13,    46,    11,     0,     0,     0,
      15,    21,     0,    12,     0,     0,    10,     0,    21,     0,
      14,    17,    52,    24,    48,     0,   152,     5,     4,    16,
      22,     0,     0,    51,    25,     0,    47,    49,   192,    24,
      60,    62,   153,     2,     0,    18,    54,    53,    50,    59,
      61,     0,     0,    23,     0,     0,     0,     0,    67,     0,
      64,     0,   405,   388,   404,     0,     0,     0,     0,   283,
      24,   155,   157,   163,     0,   165,   164,    39,    32,    41,
      33,    34,    38,    37,    36,    31,    28,     0,    29,    26,
      35,    30,    55,    56,    58,     0,    63,    65,     0,   160,
     159,     0,   315,   316,   317,     0,   311,   323,   318,   324,
     322,   319,   320,   321,     0,   313,     0,   288,   287,   154,
     156,   158,     0,   186,    19,    27,    40,     0,     0,     0,
      75,    83,    70,    66,     0,   280,     0,     0,     0,     0,
     312,     0,   314,     0,   170,   190,   191,     0,     0,   187,
     188,    43,    24,    57,     0,    85,     0,     0,    80,    74,
       0,     0,    68,     0,   168,     0,   172,     0,     0,   284,
       0,   328,     0,   325,     0,   331,   171,   329,    42,    44,
     193,   189,    20,   185,    75,     0,   195,   196,   197,   198,
     199,   200,   223,   223,   240,   226,     0,   205,   206,   207,
     208,   209,    78,    75,     0,    82,     0,    98,   281,   169,
       0,   284,   282,     0,     0,     0,     0,     0,     0,   299,
       0,     0,     0,     0,   306,   291,   289,   292,   293,   295,
     285,   290,   294,   286,   364,   365,     0,   415,   366,     0,
     192,   363,     0,   332,   333,   335,   336,     0,   355,   186,
     186,    79,    84,     0,   201,   202,   244,   245,   246,   247,
     248,   249,   251,   203,     0,   242,   232,   233,   234,   235,
     236,   237,   251,   204,     0,   228,    77,    81,    73,    71,
       0,     0,    69,     0,     0,     0,   178,   176,   183,   174,
       0,   327,   326,   308,     0,     0,     0,     0,   303,   301,
       0,     0,   307,     0,   358,     0,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,   354,   339,    45,   194,     0,     0,   250,
       0,   238,     0,     0,   231,     0,     0,   119,     0,   126,
     102,     0,     0,     0,     0,     0,   111,   112,     0,     0,
     117,   122,   121,     0,     0,   125,   128,   127,   131,   120,
       0,     0,   130,   129,    99,   100,     0,   173,     0,     0,
     166,   177,     0,     0,     0,   310,   309,     0,   304,   302,
       0,   305,   359,   361,   334,   352,   346,   349,   347,   348,
     350,   343,   344,   345,   338,   337,     0,     0,     0,   341,
       0,   340,   224,     0,   230,     0,   241,   243,   239,   227,
       0,    76,    72,     0,     0,     0,    87,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,   279,   182,   180,   181,   179,     0,   170,   175,
     184,     0,   300,   297,   351,     0,   367,     0,   360,     0,
       0,   252,   229,     0,     0,    96,     0,     0,   147,   139,
     140,   141,   142,   143,   144,   145,   146,   148,   149,   150,
     151,   253,   137,   105,   135,   134,   136,   106,   109,   107,
     113,     0,   123,   124,   115,   116,   101,   167,   161,     0,
       0,   296,   356,   357,     0,   342,   225,   118,    91,    89,
      97,    88,     0,    93,   104,     0,   138,   103,   254,     0,
       0,   218,   212,   216,   222,   215,     0,     0,     0,   219,
     210,     0,   298,   368,     0,    95,     0,   273,   276,   274,
       0,     0,   275,   255,   256,   267,   272,   110,   108,     0,
       0,   213,   214,   114,     0,     0,     0,    90,     0,    92,
       0,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,   266,   217,   221,   211,   220,   162,    94,
     271,   258,   257,   264,   262,   259,   260,   261,     0,     0,
       0,   263,     0,   277,     0,   268,   269,     0,   278
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   330,    90,    95,    96,   101,   108,   110,
     121,   144,   242,   111,   126,   177,   178,   179,   180,   181,
     213,   237,   339,   104,   113,   114,   123,   137,   116,   129,
     130,   141,   149,   150,   185,   297,   252,   248,   249,   222,
     504,   505,   506,   589,   594,   547,   372,   454,   455,   567,
     561,   562,   133,   142,   160,   161,   162,   227,   528,   300,
     267,   257,   377,   462,   378,   379,   274,   238,   239,   240,
     331,   241,   340,   292,   608,   609,   610,   344,   363,   424,
     495,   364,   365,   499,   353,   354,   496,   355,   419,   597,
     598,   623,   624,   625,   626,   674,   163,   224,   225,   226,
     261,   165,   314,   315,   581,   316,   317,   318,   319,   320,
     321,   195,   204,   196,   205,   262,   263,   166,   322,   332,
     333,   334,   335,   490,   491,   336,   337,   338,   537,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -584
static const short yypact[] =
{
      22,  1830,    26,    64,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,    29,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,    44,
      63,  -584,  -584,    10,  -584,    31,  -584,    71,  2544,    76,
    -584,    99,  2544,  -584,   106,    86,  -584,    98,    99,   118,
    -584,  -584,   105,  1711,  -584,  2544,   134,  -584,  -584,  -584,
     138,   131,  2544,  -584,  -584,  2544,  -584,  -584,  -584,  1949,
    -584,  -584,  -584,  -584,   142,  -584,   136,  -584,  -584,  -584,
    -584,   145,  1099,  -584,  1349,  2544,  2544,  2544,  -584,    38,
    -584,    73,   143,   152,   154,    72,    54,    52,    52,  -584,
     973,  -584,   175,  -584,    79,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  1225,  -584,  -584,
     209,  -584,  -584,   189,  -584,  1472,   145,  -584,  2544,  -584,
    -584,   199,  -584,  -584,  -584,    46,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,   -54,  -584,  2544,  -584,  -584,  -584,
    -584,  -584,  2544,   -22,  -584,  -584,  -584,  2544,   191,  2544,
     -35,   201,   216,  -584,   -30,  -584,   205,  2544,   190,  2544,
    -584,  2544,  -584,   196,   202,  -584,  -584,    33,  2544,   -22,
    -584,  -584,   221,  -584,  2544,   212,   419,   210,  -584,   130,
    2544,   226,  -584,  2544,   214,  2544,   242,   219,   241,   232,
     233,  -584,   -23,  -584,   -23,   611,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,   215,  2544,  -584,  -584,  -584,  -584,
    -584,  -584,   223,   223,    81,   102,  2544,  -584,  -584,  -584,
    -584,  -584,  -584,   215,   235,  -584,     8,   220,  -584,  -584,
     160,  -584,  -584,   253,  2068,   228,  2544,  2544,   -27,  -584,
    2544,   730,   611,     5,  -584,  -584,  -584,  -584,  -584,  -584,
       5,  -584,  -584,     5,  -584,  -584,   611,   611,  -584,   139,
     234,  -584,   237,   236,  -584,   335,  -584,   246,  -584,   -22,
     -22,  -584,  -584,   262,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,   247,  -584,   204,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,   247,  -584,   207,   264,   276,  -584,  -584,  -584,
     291,   244,  -584,  2544,   297,   287,   308,     9,   290,  -584,
     245,  -584,  -584,  -584,   303,   305,   307,   851,  -584,  -584,
     250,   -10,  -584,   310,   335,  2544,  -584,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   282,
     611,   304,  -584,  -584,   611,  -584,  -584,    27,   327,  -584,
      81,  -584,   102,   331,  -584,  2544,   338,   348,  2544,  -584,
    -584,   332,   337,   339,   312,   315,  -584,  -584,   346,   347,
    -584,  -584,  -584,   349,   350,  -584,  -584,  -584,    28,  -584,
     351,   352,  -584,  -584,   336,  -584,   -19,  -584,  2187,  2306,
     292,  -584,  2068,  2068,   353,  -584,  -584,   611,  -584,  -584,
       5,  -584,  -584,  -584,  -584,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   611,   424,  1592,   335,
     354,   344,  -584,   371,  -584,   357,  -584,  -584,  -584,  -584,
     358,  -584,  -584,   359,   365,    18,  -584,  -584,   429,   356,
       2,  2544,  2544,   368,   382,   387,   395,  -584,  -584,   396,
     397,   244,  -584,  -584,  -584,  -584,  -584,   309,   202,  -584,
    -584,   415,   335,   283,   335,   611,  -584,    50,  -584,   611,
     398,  -584,  -584,   421,  2544,  -584,  2663,  2425,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,   343,  -584,  -584,  -584,  -584,  -584,  -584,   409,   412,
    -584,    16,  -584,  -584,  -584,  -584,  -584,  -584,  -584,   400,
       5,  -584,   335,  -584,  1592,   335,  -584,  -584,   423,  -584,
     420,  -584,  2544,   428,  -584,    -9,  -584,  -584,  -584,  2544,
    2544,  -584,  -584,   363,  -584,   367,   444,   462,    51,   388,
    -584,   463,  -584,  -584,  2544,   455,  2544,  -584,  -584,  -584,
      -9,    -9,  -584,  -584,    24,   182,  -584,  -584,  -584,   466,
     451,  -584,  -584,  -584,    16,     4,   447,  -584,  2544,  -584,
     448,  -584,    -9,    -9,    -4,    -4,    -4,    -4,    -4,   442,
      -4,   464,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,    -4,   394,
      -4,  -584,    -4,  -584,    65,  -584,  -584,    -4,  -584
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -584,  -584,  -584,    -1,  -584,  -584,   408,  -584,  -584,   399,
    -584,  -584,  -584,  -584,  -126,  -584,  -584,   328,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,   -74,  -584,  -584,  -584,  -584,
     375,  -584,  -584,  -118,  -584,  -584,  -584,  -238,  -584,  -584,
    -584,  -584,   -40,  -584,  -584,  -584,  -584,  -584,   -13,  -584,
    -584,   -52,  -584,  -584,  -584,   360,  -584,  -584,  -584,  -584,
     -16,  -584,  -584,  -584,    55,    57,  -584,   177,  -584,   284,
    -114,   183,  -584,  -584,  -584,  -111,  -113,   243,  -584,  -584,
    -584,  -584,   103,  -584,  -584,  -584,  -584,   107,   171,  -584,
    -584,  -584,  -583,  -400,  -584,  -584,  -584,   161,   285,  -133,
    -239,  -584,  -318,  -584,  -584,  -584,  -584,  -584,  -584,  -247,
    -584,  -584,  -584,   355,   345,   311,   240,  -584,    -2,  -584,
    -584,   144,  -235,  -584,  -584,  -584,  -584,  -478,  -584,  -584
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -437
static const short yytable[] =
{
      89,   131,   392,   139,   471,   392,   383,   617,   618,   164,
     536,   246,   617,   618,   253,   131,   302,   323,   564,   601,
     602,   307,   197,   369,   619,   253,    92,   164,   620,   619,
       1,   187,   602,   603,   209,   565,   341,   640,   641,   127,
     384,    93,    94,   100,   604,   606,   607,   460,   268,   605,
     308,   138,   370,   461,   545,   367,    97,   606,   607,   661,
     662,   102,   546,   308,   269,   492,   391,   381,   223,    98,
     148,   493,   186,   392,    93,    94,   254,   390,   308,   234,
     198,   199,   200,   231,   201,   202,   203,   522,   583,   633,
      99,   393,   394,   247,   584,   634,   260,   106,   260,   105,
     566,   112,   621,   676,   107,   622,   613,   235,   236,   677,
     622,   109,   112,   115,   128,   117,   272,   385,   517,   518,
     206,   136,   309,   310,   112,   311,   312,   118,   128,   313,
     197,   642,   643,   206,   120,   309,   310,   122,   311,   312,
     132,   159,   313,   176,   182,   183,   184,   134,   206,   135,
     309,   310,   533,   311,   312,   207,   208,   313,   143,   159,
     145,   146,   147,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   260,   487,   176,   148,   188,   489,
     192,   193,   194,   229,   221,   190,   189,   159,   198,   199,
     200,   191,   201,   202,   203,   206,   386,   389,   346,   347,
     348,   349,   350,   351,   352,   233,   192,   193,   194,   211,
     212,   159,   216,   217,   644,   228,   243,   244,   245,   356,
     357,   358,   359,   360,   361,   362,   256,   250,   259,   251,
     259,   255,   532,   265,   258,   124,   266,   270,   275,   293,
     645,   294,   296,   273,   663,   664,   665,   666,   667,   295,
     669,   534,   159,   299,   301,   303,   304,   305,  -283,   306,
     343,   246,   612,   368,   371,   373,   380,   427,   671,   374,
     673,  -362,   675,   469,   342,   396,   395,   678,   417,   428,
     397,   473,   398,   414,   418,   366,   646,   647,   648,   399,
     400,   401,   402,   649,   650,   651,   420,   652,   653,   422,
     582,   423,   425,   376,   585,   301,   259,   426,   403,   128,
     128,   429,   457,   458,   507,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   459,   463,   465,   464,   466,   467,
     486,   488,   398,   494,   449,   450,   451,   500,   472,   399,
     400,   401,   402,   502,   404,   405,   406,   407,   408,   548,
     503,   409,   410,   411,   508,   412,   413,   398,   403,   509,
     511,   510,   159,   512,   399,   400,   401,   402,   513,   514,
     521,   515,   516,   519,   520,   527,   128,   540,   539,   563,
     531,   543,   538,   403,   128,   541,   542,   544,   452,   453,
     470,   570,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   404,   405,   406,   407,   408,   571,
     572,   409,   410,   411,   501,   412,   413,   128,   573,   574,
     575,   579,   507,   577,   580,   599,   586,   587,   600,   404,
     405,   406,   407,   408,   611,   548,   409,   410,   411,   614,
     412,   413,  -436,   595,   616,   629,   398,   524,   526,   630,
     631,   376,   376,   399,   400,   401,   402,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   632,   636,
     635,   638,   403,   654,   655,   658,   660,   128,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     668,   670,   672,   103,   140,   215,   591,   119,   576,   596,
     568,   569,   578,   287,   288,   289,   290,   416,   530,   529,
     210,   656,   415,   271,   657,   498,   345,   497,   404,   405,
     406,   407,   535,   421,   456,   409,   410,   411,   298,   412,
     413,   474,   264,   588,   291,   128,   593,   382,     0,   232,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,   615,     0,     0,     0,     0,     0,     0,   627,   628,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   637,     0,   639,     0,     0,     0,     4,
       5,     6,     7,     8,     0,     0,     0,   324,     9,     0,
       0,    10,     0,    12,    13,     0,     0,   659,    14,    15,
      16,    17,     0,     0,   325,     0,    18,    19,   326,     0,
       0,     0,     0,     0,    20,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,     0,    51,    52,
      53,    54,    55,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,     0,    75,     0,     0,    76,    77,
       0,     0,   327,     0,     0,   328,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,     0,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,   387,     0,   329,    18,    19,     0,     0,     0,
       0,     0,     0,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     0,     0,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,     0,    75,     0,     0,    76,    77,     0,
       0,    78,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,   388,    14,    15,
      16,    17,     0,     0,     0,     0,    18,    19,     0,     0,
       0,     0,     0,     0,    20,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,     0,    51,    52,
      53,    54,    55,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,     0,    75,     0,     0,    76,    77,
       0,     0,    78,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   151,     0,
       0,     4,     5,     6,   152,     8,     0,   124,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,   468,     0,
      14,    15,    16,    17,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,     0,     0,    20,     0,    21,    22,
     153,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,     0,
      51,    52,    53,    54,    55,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
      76,    77,     0,     0,    78,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   154,
       0,     0,     0,     0,   151,   155,   156,     4,     5,     6,
     152,     8,     0,     0,   157,   158,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,   153,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,    76,    77,     0,     0,
      78,     0,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,   154,     0,     0,   167,   168,
       0,   155,   156,     4,     5,     6,     7,     8,   169,     0,
     157,   158,     9,     0,   214,    10,     0,    12,    13,     0,
       0,     0,    14,    15,    16,    17,   170,     0,   171,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    20,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,    51,    52,    53,    54,    55,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   172,    72,    73,    74,   173,    75,
       0,     0,    76,    77,     0,     0,    78,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   167,   168,   174,   175,     0,     4,     5,     6,
       7,     8,   169,     0,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
     170,     0,   171,     0,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   172,    72,
      73,    74,   173,    75,     0,     0,    76,    77,     0,     0,
      78,     0,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,   174,   175,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,    10,   218,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,    18,    19,     0,
       0,   219,     0,     0,     0,    20,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,    51,
      52,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,     0,    75,     0,     0,    76,
      77,     0,     0,    78,     0,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   220,
       4,     5,     6,     7,     8,     0,     0,     0,   324,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,   325,     0,    18,    19,     0,
       0,     0,     0,     0,     0,    20,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,    51,
      52,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,     0,    75,     0,     0,    76,
      77,     0,     0,    78,     0,     0,   328,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     4,
       5,     6,     7,     8,     0,   124,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,    18,    19,     0,     0,
       0,     0,     0,     0,    20,   125,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,     0,    51,    52,
      53,    54,    55,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,     0,    75,     0,     0,    76,    77,
       0,     0,    78,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,    11,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,     0,     0,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     0,     0,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,     0,    75,     0,     0,    76,    77,     0,
       0,    78,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     4,     5,     6,
       7,     8,     0,   124,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,    76,    77,     0,     0,
      78,     0,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,   375,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,     0,
       0,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     0,     0,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,     0,    75,     0,     0,    76,    77,     0,     0,    78,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,    18,    19,     0,     0,   523,     0,     0,     0,
      20,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,    52,    53,    54,    55,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
       0,    75,     0,     0,    76,    77,     0,     0,    78,     0,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,     0,     0,   525,     0,     0,     0,    20,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     0,     0,    51,    52,    53,    54,    55,     0,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,     0,
      75,     0,     0,    76,    77,     0,     0,    78,     0,     0,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
      18,    19,     0,     0,   592,     0,     0,     0,    20,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,    51,    52,    53,    54,    55,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,    76,    77,     0,     0,    78,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,     0,     0,    20,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,     0,    75,     0,
       0,    76,    77,     0,     0,    78,     0,     0,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,    15,    16,    17,     0,     0,     0,     0,    18,   590,
       0,     0,     0,     0,     0,     0,    20,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,     0,
      51,    52,    53,    54,    55,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
      76,    77,     0,     0,    78,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88
};

static const short yycheck[] =
{
       1,   115,   320,   129,    14,   323,    33,    16,    17,   142,
     488,    46,    16,    17,    44,   129,   255,   264,    16,     3,
      16,    44,    76,    15,    33,    44,     0,   160,    37,    33,
       8,   149,    16,    17,   160,    33,   274,   620,   621,   113,
      67,    10,    11,    33,    28,    41,    42,    38,    15,    33,
      73,   125,    44,    44,    36,   293,    27,    41,    42,   642,
     643,    30,    44,    73,    31,    38,   313,   306,   186,    25,
      32,    44,    34,   391,    10,    11,   106,   312,    73,   212,
     134,   135,   136,   137,   138,   139,   140,   106,    38,    38,
      27,   326,   327,   128,    44,    44,   229,    98,   231,    28,
      98,   102,   111,    38,    28,   114,   584,   129,   130,    44,
     114,    12,   113,     7,   115,    29,   242,   144,    90,    91,
     143,   122,   145,   146,   125,   148,   149,    29,   129,   152,
      76,   107,   108,   143,    16,   145,   146,    32,   148,   149,
       6,   142,   152,   144,   145,   146,   147,     9,   143,    18,
     145,   146,   470,   148,   149,   157,   158,   152,    16,   160,
      24,    25,    26,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   307,   410,   177,    32,   105,   414,
     134,   135,   136,   137,   185,    33,    43,   188,   134,   135,
     136,    37,   138,   139,   140,   143,   310,   311,   117,   118,
     119,   120,   121,   122,   123,   206,   134,   135,   136,    34,
     131,   212,     3,    24,    32,    16,   217,    26,   219,   117,
     118,   119,   120,   121,   122,   123,   227,    26,   229,    13,
     231,    26,   467,    37,    44,    14,    34,   238,    26,    29,
      58,   111,    16,   244,   644,   645,   646,   647,   648,   250,
     650,   486,   253,    39,   255,    13,    37,    16,    26,    26,
      37,    46,   580,    28,    44,   105,    38,    23,   668,    16,
     670,    37,   672,   387,   275,    38,   137,   677,    16,    35,
      44,   395,    32,    37,    37,   286,   104,   105,   106,    39,
      40,    41,    42,   111,   112,   113,    92,   115,   116,    92,
     535,    37,    26,   304,   539,   306,   307,    16,    58,   310,
     311,    67,    15,    26,   428,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    26,    45,    33,    92,    33,    32,
      58,    37,    32,    16,   100,   101,   102,    16,    38,    39,
      40,    41,    42,    15,   104,   105,   106,   107,   108,    16,
      12,   111,   112,   113,    32,   115,   116,    32,    58,    32,
      58,    32,   373,    58,    39,    40,    41,    42,    32,    32,
      44,    32,    32,    32,    32,    93,   387,    16,    44,    33,
      37,    32,    38,    58,   395,    38,    38,    32,   154,   155,
     150,    33,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   104,   105,   106,   107,   108,    37,
      33,   111,   112,   113,   425,   115,   116,   428,    33,    33,
      33,    16,   546,   124,   151,    26,    38,    16,    26,   104,
     105,   106,   107,   108,    44,    16,   111,   112,   113,    26,
     115,   116,    32,   110,    26,    92,    32,   458,   459,    92,
      16,   462,   463,    39,    40,    41,    42,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    16,    16,
      92,    26,    58,    17,    33,    38,    38,   488,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      58,    37,   108,    95,   129,   177,   546,   108,   521,   561,
     511,   512,   528,    94,    95,    96,    97,   340,   463,   462,
     160,   634,   339,   239,   635,   422,   283,   420,   104,   105,
     106,   107,   108,   362,   373,   111,   112,   113,   253,   115,
     116,   397,   231,   544,   125,   546,   547,   307,    -1,   204,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,   599,   600,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   614,    -1,   616,    -1,    -1,    -1,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,   638,    27,    28,
      29,    30,    -1,    -1,    33,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,   107,   108,
      -1,    -1,   111,    -1,    -1,   114,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    32,    -1,   153,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    79,
      80,    81,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,   107,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,   147,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,   107,   108,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     5,    -1,
      -1,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,   147,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,   104,    -1,    -1,
     107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      -1,    -1,    -1,    -1,     5,   132,   133,     8,     9,    10,
      11,    12,    -1,    -1,   141,   142,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,     3,     4,
      -1,   132,   133,     8,     9,    10,    11,    12,    13,    -1,
     141,   142,    17,    -1,    19,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     3,     4,   129,   130,    -1,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    -1,    -1,   129,   130,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,   104,    -1,    -1,   107,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
      -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,   104,    -1,    -1,   107,
     108,    -1,    -1,   111,    -1,    -1,   114,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,   107,   108,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    79,
      80,    81,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,   107,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,   107,   108,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,   107,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,   107,   108,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    77,    78,    79,    80,    81,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
     104,    -1,    -1,   107,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,   104,
      -1,    -1,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,   104,    -1,    -1,
     107,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     8,   157,   158,     8,     9,    10,    11,    12,    17,
      20,    21,    22,    23,    27,    28,    29,    30,    35,    36,
      43,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    77,    78,    79,    80,    81,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   100,   101,   102,   104,   107,   108,   111,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   159,
     160,   285,     0,    10,    11,   161,   162,    27,    25,    27,
      33,   163,    30,   162,   179,    28,   159,    28,   164,    12,
     165,   169,   159,   180,   181,     7,   184,    29,    29,   165,
      16,   166,    32,   182,    14,    44,   170,   181,   159,   185,
     186,   226,     6,   208,     9,    18,   159,   183,   181,   170,
     186,   187,   209,    16,   167,    24,    25,    26,    32,   188,
     189,     5,    11,    47,   126,   132,   133,   141,   142,   159,
     210,   211,   212,   252,   255,   257,   273,     3,     4,    13,
      31,    33,    99,   103,   129,   130,   159,   171,   172,   173,
     174,   175,   159,   159,   159,   190,    34,   189,   105,    43,
      33,    37,   134,   135,   136,   267,   269,    76,   134,   135,
     136,   138,   139,   140,   268,   270,   143,   274,   274,   170,
     211,    34,   131,   176,    19,   173,     3,    24,    21,    39,
     127,   159,   195,   189,   253,   254,   255,   213,    16,   137,
     269,   137,   270,   159,   255,   129,   130,   177,   223,   224,
     225,   227,   168,   159,    26,   159,    46,   128,   193,   194,
      26,    13,   192,    44,   106,    26,   159,   217,    44,   159,
     255,   256,   271,   272,   271,    37,    34,   216,    15,    31,
     159,   225,   170,   159,   222,    26,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    94,    95,    96,
      97,   125,   229,    29,   111,   159,    16,   191,   254,    39,
     215,   159,   256,    13,    37,    16,    26,    44,    73,   145,
     146,   148,   149,   152,   258,   259,   261,   262,   263,   264,
     265,   266,   274,   265,    16,    33,    37,   111,   114,   153,
     159,   226,   275,   276,   277,   278,   281,   282,   283,   178,
     228,   193,   159,    37,   233,   233,   117,   118,   119,   120,
     121,   122,   123,   240,   241,   243,   117,   118,   119,   120,
     121,   122,   123,   234,   237,   238,   159,   193,    28,    15,
      44,    44,   202,   105,    16,    21,   159,   218,   220,   221,
      38,   256,   272,    33,    67,   144,   226,    32,   147,   226,
     278,   265,   258,   278,   278,   137,    38,    44,    32,    39,
      40,    41,    42,    58,   104,   105,   106,   107,   108,   111,
     112,   113,   115,   116,    37,   227,   223,    16,    37,   244,
      92,   244,    92,    37,   235,    26,    16,    23,    35,    67,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   100,
     101,   102,   154,   155,   203,   204,   253,    15,    26,    26,
      38,    44,   219,    45,    92,    33,    33,    32,   147,   226,
     150,    14,    38,   226,   277,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,    58,   278,    37,   278,
     279,   280,    38,    44,    16,   236,   242,   243,   238,   239,
      16,   159,    15,    12,   196,   197,   198,   226,    32,    32,
      32,    58,    58,    32,    32,    32,    32,    90,    91,    32,
      32,    44,   106,    39,   159,    39,   159,    93,   214,   221,
     220,    37,   278,   258,   278,   108,   283,   284,    38,    44,
      16,    38,    38,    32,    32,    36,    44,   201,    16,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,   206,   207,    33,    16,    33,    98,   205,   159,   159,
      33,    37,    33,    33,    33,    33,   204,   124,   216,    16,
     151,   260,   278,    38,    44,   278,    38,    16,   159,   199,
      36,   198,    39,   159,   200,   110,   207,   245,   246,    26,
      26,     3,    16,    17,    28,    33,    41,    42,   230,   231,
     232,    44,   258,   283,    26,   159,    26,    16,    17,    33,
      37,   111,   114,   247,   248,   249,   250,   159,   159,    92,
      92,    16,    16,    38,    44,    92,    16,   159,    26,   159,
     248,   248,   107,   108,    32,    58,   104,   105,   106,   111,
     112,   113,   115,   116,    17,    33,   232,   231,    38,   159,
      38,   248,   248,   249,   249,   249,   249,   249,    58,   249,
      37,   249,   108,   249,   251,   249,    38,    44,   249
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
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
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
#line 114 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 117 "screen.yacc"
    {the_form.dbname=strdup("formonly");}
    break;

  case 4:
#line 118 "screen.yacc"
    {the_form.dbname=(yyvsp[-3].str);
if (A4GLF_open_db(yyvsp[-3].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 123 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 124 "screen.yacc"
    {the_form.dbname=strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 10:
#line 137 "screen.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 13:
#line 143 "screen.yacc"
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
#line 156 "screen.yacc"
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
#line 176 "screen.yacc"
    { 
		lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 18:
#line 178 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 19:
#line 181 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 190 "screen.yacc"
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
#line 212 "screen.yacc"
    {
	int a;
	static char buff[256];
	strcpy(buff,yyvsp[0].str);
	if (A4GL_isyes(acl_getenv("SPACESCORE"))) {
		for (a=0;a<strlen(buff);a++) {
			if (buff[a]=='_') buff[a]=' ';
		}
	}
	strcpy(yyval.str,buff);
}
    break;

  case 29:
#line 227 "screen.yacc"
    {
        //printf("%s %d %d %d %d %d %s\n","_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	if (lineno) {
        A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 30:
#line 237 "screen.yacc"
    { ltab=0; }
    break;

  case 31:
#line 238 "screen.yacc"
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

  case 32:
#line 249 "screen.yacc"
    {
	char buff[256];
	if (lineno) {
	sprintf(buff,"\n%s",yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 33:
#line 261 "screen.yacc"
    {
	char buff[256];
	if (lineno) {
	strcpy(buff,yyvsp[0].str);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 34:
#line 274 "screen.yacc"
    {
	if (lineno) {
	     A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 35:
#line 284 "screen.yacc"
    {
	if (lineno) {
	A4GL_add_field("_label",colno+1,lineno,strlen(yyvsp[0].str),scr,0,yyvsp[0].str);
	colno+=strlen(yyvsp[0].str);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
    break;

  case 36:
#line 293 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 37:
#line 298 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 38:
#line 301 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 39:
#line 309 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 40:
#line 310 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 41:
#line 316 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 42:
#line 323 "screen.yacc"
    {
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field(yyvsp[-1].str,fstart+1,lineno,colno-fstart-1,scr,2,"");
}
    break;

  case 43:
#line 337 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 44:
#line 340 "screen.yacc"
    {
				/* field elements = name x y width screen_no endswith'|' */
				colno++;
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
#line 351 "screen.yacc"
    {
				strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 51:
#line 367 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 52:
#line 374 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 53:
#line 375 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 54:
#line 378 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 55:
#line 379 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 56:
#line 381 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 57:
#line 382 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 58:
#line 383 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 62:
#line 397 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 67:
#line 413 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 68:
#line 417 "screen.yacc"
    {
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
    break;

  case 69:
#line 427 "screen.yacc"
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
			printf("Setting field picture from syscolval (%s)\n",p);
		}
	}

	A4GL_set_field(currftag,fld);
}
    break;

  case 71:
#line 455 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 72:
#line 459 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 73:
#line 467 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 74:
#line 468 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 75:
#line 471 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 76:
#line 472 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 77:
#line 475 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 78:
#line 478 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 79:
#line 483 "screen.yacc"
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

  case 80:
#line 492 "screen.yacc"
    {
	static int xdo=0;
	char buff[256];
	sprintf(buff,"_do_%d",xdo++);
	fld->tabname=strdup("formonly");
	fld->colname=strdup(buff);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 81:
#line 504 "screen.yacc"
    {
	static int di=0;
	char buff[256];
	sprintf(buff,"_di_%d",di++);
	fld->tabname=strdup("formonly");
	fld->colname=strdup(buff);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 82:
#line 516 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 83:
#line 524 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 84:
#line 532 "screen.yacc"
    {
	fld->tabname=strdup(yyvsp[-2].str); 
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 85:
#line 540 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 102:
#line 585 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 103:
#line 586 "screen.yacc"
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

  case 105:
#line 607 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 106:
#line 608 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 107:
#line 609 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 108:
#line 610 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 109:
#line 611 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 110:
#line 612 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 111:
#line 613 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 112:
#line 614 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 113:
#line 615 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 114:
#line 616 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 115:
#line 617 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 116:
#line 618 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 117:
#line 619 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 118:
#line 620 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 119:
#line 622 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 120:
#line 623 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 121:
#line 624 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 122:
#line 625 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 123:
#line 626 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 124:
#line 627 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 125:
#line 628 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 126:
#line 631 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 127:
#line 634 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 131:
#line 638 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 132:
#line 641 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 133:
#line 645 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 134:
#line 651 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 135:
#line 652 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 136:
#line 653 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 138:
#line 655 "screen.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str));
}
    break;

  case 139:
#line 661 "screen.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 140:
#line 662 "screen.yacc"
    { strcpy(yyval.str,"4"); }
    break;

  case 141:
#line 663 "screen.yacc"
    { strcpy(yyval.str,"2"); }
    break;

  case 142:
#line 664 "screen.yacc"
    { strcpy(yyval.str,"6"); }
    break;

  case 143:
#line 665 "screen.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 144:
#line 666 "screen.yacc"
    { strcpy(yyval.str,"5"); }
    break;

  case 145:
#line 667 "screen.yacc"
    { strcpy(yyval.str,"7"); }
    break;

  case 146:
#line 668 "screen.yacc"
    { strcpy(yyval.str,"3"); }
    break;

  case 147:
#line 670 "screen.yacc"
    { 
			char *ptr;
			
			ptr=yyvsp[0].str;
			if (strlen(ptr) > 1) {
	        		yyerror("Colour number out of range 0-7");
			}
			if (*ptr>='0'||*ptr<='7') ;
			else {
	        		yyerror("Colour number out of range 0-7");
			}
		strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 148:
#line 684 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 149:
#line 685 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 150:
#line 686 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 151:
#line 687 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 153:
#line 692 "screen.yacc"
    {
}
    break;

  case 159:
#line 702 "screen.yacc"
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

  case 160:
#line 712 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 172:
#line 729 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 173:
#line 732 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 174:
#line 748 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 175:
#line 751 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 178:
#line 761 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 179:
#line 763 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 180:
#line 765 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 181:
#line 767 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 182:
#line 769 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 184:
#line 773 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 185:
#line 777 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 186:
#line 783 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 187:
#line 783 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 190:
#line 790 "screen.yacc"
    {colno++;}
    break;

  case 191:
#line 791 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 192:
#line 804 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 193:
#line 812 "screen.yacc"
    {
	colno+=strlen(yyvsp[0].str);
}
    break;

  case 194:
#line 814 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-2].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 195:
#line 821 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 196:
#line 825 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 197:
#line 829 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 198:
#line 833 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 199:
#line 837 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 200:
#line 841 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 201:
#line 845 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 202:
#line 849 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 203:
#line 853 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 204:
#line 857 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 205:
#line 861 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 206:
#line 865 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 207:
#line 869 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 208:
#line 873 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 209:
#line 876 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 211:
#line 883 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 214:
#line 888 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 215:
#line 893 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 216:
#line 894 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 217:
#line 895 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 218:
#line 896 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 220:
#line 898 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 221:
#line 901 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 222:
#line 905 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 223:
#line 911 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 224:
#line 912 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 225:
#line 913 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 226:
#line 916 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 227:
#line 918 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 228:
#line 924 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 229:
#line 926 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 230:
#line 931 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 231:
#line 939 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 232:
#line 942 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 233:
#line 943 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 234:
#line 944 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 235:
#line 945 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 236:
#line 946 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 237:
#line 947 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 238:
#line 949 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 240:
#line 956 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 241:
#line 957 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 242:
#line 960 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 243:
#line 963 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 244:
#line 967 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 245:
#line 968 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 246:
#line 969 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 247:
#line 970 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 248:
#line 971 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 249:
#line 972 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 250:
#line 974 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 251:
#line 979 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 252:
#line 981 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 253:
#line 988 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 254:
#line 988 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 255:
#line 994 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 257:
#line 1001 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 258:
#line 1004 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 259:
#line 1010 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 260:
#line 1011 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 261:
#line 1012 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 262:
#line 1013 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 263:
#line 1014 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 264:
#line 1015 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 265:
#line 1016 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 266:
#line 1017 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 267:
#line 1018 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 268:
#line 1019 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 269:
#line 1020 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 270:
#line 1021 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 271:
#line 1022 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 272:
#line 1025 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 273:
#line 1032 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); printf("NUMBER VALUE : %s\n",yyvsp[0].str); }
    break;

  case 274:
#line 1033 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 275:
#line 1034 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 277:
#line 1042 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 278:
#line 1046 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;

  case 337:
#line 1181 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 338:
#line 1184 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 343:
#line 1198 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 344:
#line 1199 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 345:
#line 1200 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 346:
#line 1201 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 347:
#line 1202 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 348:
#line 1203 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 349:
#line 1204 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 350:
#line 1205 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 351:
#line 1206 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 352:
#line 1207 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 353:
#line 1208 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 354:
#line 1209 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 355:
#line 1210 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 356:
#line 1211 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 357:
#line 1212 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 358:
#line 1213 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 359:
#line 1214 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 360:
#line 1215 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 361:
#line 1216 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 363:
#line 1222 "screen.yacc"
    { yyval.expr=create_field_expr(yyvsp[0].str); }
    break;

  case 364:
#line 1223 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); }
    break;

  case 365:
#line 1224 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 366:
#line 1225 "screen.yacc"
    { yyval.expr=create_special_expr(yyvsp[0].str); }
    break;

  case 367:
#line 1228 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 368:
#line 1232 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 999 of yacc.c.  */
#line 4087 "y.tab.c"

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
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
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
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
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


#line 1329 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */





