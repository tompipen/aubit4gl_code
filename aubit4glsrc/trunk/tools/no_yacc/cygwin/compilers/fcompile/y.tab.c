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
     KW_ZEROFILL = 413
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
#line 76 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 477 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 489 "y.tab.c"

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
#define YYFINAL  95
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2849

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  159
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  130
/* YYNRULES -- Number of rules. */
#define YYNRULES  457
/* YYNRULES -- Number of states. */
#define YYNSTATES  685

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   413

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
     155,   156,   157,   158
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
     440,   442,   444,   446,   448,   450,   451,   452,   457,   459,
     462,   464,   467,   470,   471,   481,   494,   496,   498,   500,
     501,   504,   505,   507,   508,   510,   512,   517,   519,   523,
     524,   526,   528,   532,   536,   540,   544,   546,   550,   552,
     553,   555,   557,   560,   562,   564,   566,   567,   572,   574,
     576,   578,   580,   582,   584,   587,   590,   593,   596,   598,
     600,   602,   604,   606,   608,   612,   614,   617,   620,   622,
     624,   628,   630,   632,   636,   640,   642,   643,   647,   653,
     654,   658,   659,   663,   665,   668,   670,   672,   674,   676,
     678,   680,   683,   685,   686,   690,   692,   694,   696,   698,
     700,   702,   704,   706,   709,   710,   714,   715,   717,   720,
     722,   726,   730,   734,   738,   742,   746,   751,   755,   758,
     761,   763,   769,   775,   778,   782,   784,   786,   788,   790,
     792,   794,   798,   807,   809,   813,   817,   819,   821,   827,
     833,   836,   839,   841,   843,   845,   847,   849,   851,   853,
     859,   860,   863,   865,   870,   873,   877,   880,   884,   888,
     890,   893,   896,   900,   904,   906,   909,   911,   914,   916,
     918,   920,   922,   924,   926,   928,   930,   932,   934,   936,
     940,   944,   946,   951,   957,   958,   960,   962,   966,   968,
     970,   974,   978,   979,   981,   983,   987,   991,   995,   999,
    1003,  1007,  1011,  1015,  1019,  1024,  1028,  1031,  1034,  1036,
    1042,  1048,  1051,  1055,  1060,  1064,  1066,  1068,  1070,  1072,
    1074,  1076,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,
    1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,
    1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,  1132,  1134,
    1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,  1152,  1154,
    1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,  1172,  1174,
    1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,
    1196,  1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,  1214,
    1216,  1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,
    1236,  1238,  1240,  1242,  1244,  1246,  1248,  1250
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     160,     0,    -1,   161,   164,   182,   187,   211,    -1,     8,
      21,    -1,     8,   163,    27,    28,    29,    -1,     8,    21,
      27,    28,    29,    -1,     8,   163,    -1,    17,    -1,   288,
      -1,   162,    -1,   162,    25,   162,    -1,   165,    -1,   164,
     165,    -1,    -1,    11,   166,   168,    -1,    -1,    10,    33,
     167,   168,    -1,    -1,    -1,    -1,   172,   169,    18,   170,
     174,    19,   171,   173,    -1,    -1,    12,    16,    -1,    12,
      16,     9,    16,    -1,    -1,    14,    -1,   176,    -1,   174,
     176,    -1,   162,    -1,   175,    -1,   178,    -1,   133,    -1,
       4,    -1,    31,    -1,    33,    -1,   177,    -1,   132,    -1,
     106,    -1,   102,    -1,     3,    -1,   177,     3,    -1,    -1,
      13,   179,   180,    15,    -1,   230,    -1,    -1,   180,    31,
     181,   230,    -1,    -1,    30,   183,   173,    -1,   184,    -1,
     183,   184,    -1,   183,    44,   184,    -1,   162,   185,    -1,
      -1,    32,   186,    -1,   162,    -1,   162,    24,   162,    -1,
     162,    25,   162,    -1,   162,    25,   162,    24,   162,    -1,
     162,    26,   162,    -1,     7,   188,   173,    -1,   189,    -1,
     188,   189,    -1,    -1,   229,   190,   191,    34,    -1,   192,
      -1,   191,   192,    -1,   191,    34,   192,    -1,    -1,    -1,
      32,   193,   198,   195,   194,   205,    -1,    -1,    13,    16,
      15,    -1,    13,    16,    44,    16,    15,    -1,   197,   114,
      28,    -1,   197,    -1,    -1,    46,    58,   162,    26,   162,
      -1,    46,    58,   162,    -1,    46,   232,    -1,    21,    26,
     225,   196,    -1,   130,   196,    -1,   130,   131,    29,   196,
      -1,   162,    26,   162,    -1,   162,    -1,    39,   162,    26,
     162,    -1,    39,   162,    -1,   229,    -1,   201,    -1,   200,
      44,   201,    -1,   199,    32,   202,    -1,   162,    26,   162,
      -1,   162,    -1,   162,    26,   162,    -1,   162,    -1,    39,
     162,    26,   162,    -1,    39,   162,    -1,    36,    -1,    44,
      36,    -1,    -1,    44,   206,    -1,   207,    -1,   206,    44,
     207,    -1,    74,    -1,    75,    32,   209,   248,    -1,    35,
     200,   204,   203,    -1,    76,    32,    33,    -1,    77,    32,
     208,    -1,    79,    58,   162,    -1,    79,    58,   162,    26,
     162,    -1,    78,    58,   162,    -1,    78,    58,   162,    26,
     162,    -1,    80,    -1,    81,    -1,    82,    32,    33,    -1,
      83,    32,    37,   233,    38,    -1,   104,    32,    33,    -1,
     105,    32,    33,    -1,    84,    -1,    23,    12,    32,    16,
      -1,    23,    -1,   103,    -1,    86,    -1,    85,    -1,    87,
      32,    33,    -1,    88,    32,    33,    -1,    89,    -1,    68,
      -1,    91,    -1,    90,    -1,   158,    -1,   157,    -1,    92,
      -1,    92,    93,    -1,    92,    94,    -1,    33,    -1,    16,
      -1,   101,    -1,   210,    -1,   209,   210,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    16,    -1,    68,    -1,    73,    -1,
      67,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      -1,    -1,     6,   212,   213,   173,    -1,   214,    -1,   213,
     214,    -1,   215,    -1,   215,    34,    -1,    47,    33,    -1,
      -1,    11,    43,   216,   220,    37,   221,    38,   217,   219,
      -1,   129,    37,    16,    44,    16,    38,    95,    37,    16,
      44,    16,    38,    -1,   255,    -1,   276,    -1,   260,    -1,
      -1,    96,   127,    -1,    -1,    39,    -1,    -1,    34,    -1,
     162,    -1,   162,    13,    16,    15,    -1,   224,    -1,   221,
     222,   224,    -1,    -1,    44,    -1,   162,    -1,   162,    26,
     162,    -1,    21,    26,   162,    -1,   162,    26,    39,    -1,
      21,    26,    39,    -1,   223,    -1,   223,    45,   223,    -1,
     162,    -1,    -1,   227,    -1,   228,    -1,   227,   228,    -1,
     132,    -1,   133,    -1,   162,    -1,    -1,   226,   162,   231,
     226,    -1,    48,    -1,    49,    -1,    50,    -1,    51,    -1,
      52,    -1,    53,    -1,    54,   236,    -1,    55,   236,    -1,
      56,   243,    -1,    57,   237,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,   128,    -1,   235,    -1,   233,    44,
     235,    -1,    16,    -1,    41,    16,    -1,    42,    16,    -1,
      33,    -1,    17,    -1,    17,    95,    17,    -1,     3,    -1,
     234,    -1,   234,    95,   234,    -1,    33,    95,    33,    -1,
      28,    -1,    -1,    37,    16,    38,    -1,    37,    16,    44,
      16,    38,    -1,    -1,   240,    95,   242,    -1,    -1,    37,
      16,    38,    -1,    16,    -1,   241,   238,    -1,   120,    -1,
     121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,    -1,
     126,   247,    -1,   241,    -1,    -1,   244,    95,   245,    -1,
     246,    -1,   246,    -1,   120,    -1,   121,    -1,   122,    -1,
     123,    -1,   124,    -1,   125,    -1,   126,   247,    -1,    -1,
      37,   239,    38,    -1,    -1,   249,    -1,   113,   250,    -1,
     251,    -1,   251,   111,   251,    -1,   251,   110,   251,    -1,
     252,   107,   252,    -1,   252,   108,   252,    -1,   252,   109,
     252,    -1,   252,    58,   252,    -1,   252,   114,    58,   252,
      -1,   252,    32,   252,    -1,   252,   118,    -1,   252,   119,
      -1,   252,    -1,   252,   115,   252,   111,   252,    -1,   252,
     116,    37,   254,    38,    -1,   114,   251,    -1,    37,   251,
      38,    -1,   253,    -1,    16,    -1,    33,    -1,   117,    -1,
      17,    -1,   252,    -1,   254,    44,   252,    -1,     5,   108,
     256,   109,   218,   108,   256,   109,    -1,   257,    -1,   256,
      44,   257,    -1,   258,    26,   259,    -1,   162,    -1,   162,
      -1,   135,   270,   140,   274,   268,    -1,   136,   271,   140,
     274,   268,    -1,   145,   277,    -1,   144,   277,    -1,   264,
      -1,   269,    -1,   262,    -1,   265,    -1,   266,    -1,   277,
      -1,   267,    -1,   152,   281,   153,   261,   263,    -1,    -1,
     154,   261,    -1,   148,    -1,   149,   229,    32,   281,    -1,
     151,   229,    -1,   151,    32,   229,    -1,   151,   150,    -1,
     151,    32,   150,    -1,   155,   268,    14,    -1,   261,    -1,
     268,   261,    -1,    76,    33,    -1,    76,   147,    33,    -1,
      76,    68,    33,    -1,   272,    -1,   270,   272,    -1,   273,
      -1,   271,   273,    -1,   137,    -1,   138,    -1,   139,    -1,
     137,    -1,   141,    -1,   142,    -1,   143,    -1,   139,    -1,
      79,    -1,   138,    -1,   275,    -1,   274,    44,   275,    -1,
     258,    26,   259,    -1,   259,    -1,   258,   134,   258,   219,
      -1,   146,   162,    37,   278,    38,    -1,    -1,   279,    -1,
     280,    -1,   279,    44,   280,    -1,   281,    -1,   284,    -1,
     281,   111,   281,    -1,   281,   110,   281,    -1,    -1,   283,
      -1,   281,    -1,   283,    44,   281,    -1,   281,   107,   281,
      -1,   281,   108,   281,    -1,   281,   109,   281,    -1,   281,
      39,   281,    -1,   281,    41,   281,    -1,   281,    42,   281,
      -1,   281,    40,   281,    -1,   281,    58,   281,    -1,   281,
     114,    58,   281,    -1,   281,    32,   281,    -1,   281,   118,
      -1,   281,   119,    -1,   286,    -1,   281,   115,   281,   111,
     281,    -1,   281,   116,    37,   287,    38,    -1,   114,   281,
      -1,    37,   281,    38,    -1,   285,    37,   282,    38,    -1,
     156,   140,   229,    -1,   162,    -1,   229,    -1,    16,    -1,
      33,    -1,   117,    -1,   286,    -1,   287,    44,   286,    -1,
      96,    -1,    74,    -1,    59,    -1,    71,    -1,    70,    -1,
      60,    -1,   110,    -1,   111,    -1,   107,    -1,   128,    -1,
       9,    -1,    75,    -1,    22,    -1,    76,    -1,    93,    -1,
     105,    -1,    62,    -1,     8,    -1,    56,    -1,    77,    -1,
      47,    -1,    80,    -1,    23,    -1,    82,    -1,    61,    -1,
      83,    -1,    29,    -1,    57,    -1,    84,    -1,    98,    -1,
      48,    -1,    50,    -1,    54,    -1,    51,    -1,    49,    -1,
      28,    -1,   129,    -1,    11,    -1,    10,    -1,    12,    -1,
      99,    -1,    69,    -1,   127,    -1,    64,    -1,    55,    -1,
      86,    -1,    94,    -1,   114,    -1,    87,    -1,    88,    -1,
      43,    -1,    63,    -1,    89,    -1,    68,    -1,    73,    -1,
      67,    -1,    97,    -1,    52,    -1,    53,    -1,   103,    -1,
     101,    -1,    30,    -1,    45,    -1,    20,    -1,    95,    -1,
      72,    -1,    81,    -1,   100,    -1,    91,    -1,    35,    -1,
      36,    -1,    65,    -1,   104,    -1,    27,    -1,    92,    -1,
      90,    -1,    66,    -1,    46,    -1,    58,    -1,   120,    -1,
     121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,    -1,
     126,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   112,   112,   115,   116,   121,   122,   130,   131,   135,
     135,   138,   138,   141,   141,   154,   154,   174,   176,   179,
     173,   186,   187,   188,   200,   201,   206,   207,   210,   225,
     235,   236,   247,   259,   272,   282,   291,   296,   299,   307,
     308,   314,   313,   335,   338,   338,   356,   357,   360,   361,
     362,   365,   372,   373,   376,   377,   378,   380,   381,   387,
     391,   391,   395,   395,   405,   406,   407,   411,   415,   411,
     452,   453,   457,   465,   466,   469,   470,   473,   476,   481,
     490,   502,   514,   522,   530,   538,   548,   552,   553,   556,
     559,   560,   564,   565,   566,   567,   570,   571,   575,   576,
     580,   580,   583,   584,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   620,
     621,   622,   623,   624,   625,   626,   629,   632,   633,   634,
     635,   636,   639,   643,   649,   650,   651,   655,   656,   660,
     661,   662,   663,   664,   665,   666,   667,   669,   683,   684,
     685,   686,   687,   688,   689,   693,   694,   694,   699,   699,
     701,   701,   704,   714,   714,   717,   718,   719,   720,   724,
     724,   726,   726,   728,   728,   731,   734,   750,   753,   757,
     758,   762,   764,   766,   768,   770,   775,   775,   779,   785,
     785,   788,   788,   792,   793,   806,   814,   814,   823,   827,
     831,   835,   839,   843,   847,   851,   855,   859,   863,   867,
     871,   875,   878,   885,   885,   890,   890,   890,   895,   896,
     897,   898,   899,   900,   903,   907,   913,   914,   915,   918,
     919,   926,   928,   933,   941,   944,   945,   946,   947,   948,
     949,   950,   956,   958,   959,   962,   965,   969,   970,   971,
     972,   973,   974,   975,   981,   983,   990,   990,   996,  1002,
    1003,  1006,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1027,  1034,  1035,  1036,  1041,
    1044,  1048,  1060,  1063,  1064,  1067,  1070,  1073,  1077,  1078,
    1079,  1080,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1095,
    1099,  1099,  1102,  1105,  1108,  1109,  1110,  1111,  1115,  1118,
    1119,  1124,  1125,  1126,  1131,  1131,  1135,  1135,  1139,  1140,
    1141,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1154,  1155,
    1159,  1160,  1164,  1167,  1170,  1170,  1174,  1174,  1177,  1182,
    1183,  1184,  1187,  1188,  1191,  1192,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,  1214,  1217,  1220,  1221,  1222,  1223,
    1226,  1230,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,  1269,
    1270,  1271,  1272,  1273,  1274,  1275,  1276,  1277,  1278,  1279,
    1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,  1298,  1299,
    1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,  1308,  1309,
    1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,  1318,  1319,
    1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327
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
  "NORMAL", "REVERSE", "LEFT", "BOLD", "BLINK", "UNDERLINE", "DIM", 
  "AUTONEXT", "COLOR", "COMMENTS", "DEFAULT", "VALIDATE", "DISPLAY", 
  "DOWNSHIFT", "UPSHIFT", "FORMAT", "INCLUDE", "INVISIBLE", "NOUPDATE", 
  "NOENTRY", "PICTURE", "PROGRAM", "REQUIRED", "QUERYCLEAR", "VERIFY", 
  "WORDWRAP", "COMPRESS", "NONCOMPRESS", "TO", "AS", "SERIAL", "KW_BYTE", 
  "KW_TEXT", "VARCHAR", "SQL_VAR", "KW_NONSPACE", "SQLONLY", "WIDGET", 
  "CONFIG", "KW_NL", "COMPARISON", "LESSTHAN", "GREATERTHAN", "KWOR", 
  "KWAND", "KWAND1", "KWWHERE", "KWNOT", "KWBETWEEN", "KWIN", "XVAL", 
  "KWNULLCHK", "KWNOTNULLCHK", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", 
  "SECOND", "FRACTION", "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY", 
  "ALLOWING", "KW_WS", "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", 
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
     405,   406,   407,   408,   409,   410,   411,   412,   413
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   159,   160,   161,   161,   161,   161,   162,   162,   163,
     163,   164,   164,   166,   165,   167,   165,   169,   170,   171,
     168,   172,   172,   172,   173,   173,   174,   174,   175,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   177,
     177,   179,   178,   180,   181,   180,   182,   182,   183,   183,
     183,   184,   185,   185,   186,   186,   186,   186,   186,   187,
     188,   188,   190,   189,   191,   191,   191,   193,   194,   192,
     195,   195,   195,   196,   196,   197,   197,   197,   197,   198,
     198,   198,   198,   198,   198,   198,   199,   200,   200,   201,
     202,   202,   203,   203,   203,   203,   204,   204,   205,   205,
     206,   206,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   208,   208,   208,   209,   209,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   211,   212,   211,   213,   213,
     214,   214,   215,   216,   215,   215,   215,   215,   215,   217,
     217,   218,   218,   219,   219,   220,   220,   221,   221,   222,
     222,   223,   223,   223,   223,   223,   224,   224,   225,   226,
     226,   227,   227,   228,   228,   229,   231,   230,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   233,   233,   234,   234,   234,   235,   235,
     235,   235,   235,   235,   235,   235,   236,   236,   236,   237,
     237,   238,   238,   239,   240,   241,   241,   241,   241,   241,
     241,   241,   242,   243,   243,   244,   245,   246,   246,   246,
     246,   246,   246,   246,   247,   247,   248,   248,   249,   250,
     250,   250,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   252,   252,   252,   252,   253,
     254,   254,   255,   256,   256,   257,   258,   259,   260,   260,
     260,   260,   261,   261,   261,   261,   261,   261,   261,   262,
     263,   263,   264,   265,   266,   266,   266,   266,   267,   268,
     268,   269,   269,   269,   270,   270,   271,   271,   272,   272,
     272,   273,   273,   273,   273,   273,   273,   273,   274,   274,
     275,   275,   276,   277,   278,   278,   279,   279,   280,   281,
     281,   281,   282,   282,   283,   283,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   285,   286,   286,   286,   286,
     287,   287,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288
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
       1,     1,     1,     1,     1,     0,     0,     4,     1,     2,
       1,     2,     2,     0,     9,    12,     1,     1,     1,     0,
       2,     0,     1,     0,     1,     1,     4,     1,     3,     0,
       1,     1,     3,     3,     3,     3,     1,     3,     1,     0,
       1,     1,     2,     1,     1,     1,     0,     4,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     2,     1,     1,
       3,     1,     1,     3,     3,     1,     0,     3,     5,     0,
       3,     0,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     0,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     4,     3,     2,     2,
       1,     5,     5,     2,     3,     1,     1,     1,     1,     1,
       1,     3,     8,     1,     3,     3,     1,     1,     5,     5,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     5,
       0,     2,     1,     4,     2,     3,     2,     3,     3,     1,
       2,     2,     3,     3,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     4,     5,     0,     1,     1,     3,     1,     1,
       3,     3,     0,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     2,     2,     1,     5,
       5,     2,     3,     4,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   389,   382,   410,   409,   411,     7,
     435,     3,   384,   394,   445,   407,   398,   433,   441,   442,
     422,   434,   449,   392,   402,   406,   403,   405,   429,   430,
     404,   416,   390,   399,   450,   374,   377,   396,   388,   423,
     415,   443,   448,   427,   425,   413,   376,   375,   437,   426,
     373,   383,   385,   391,   393,   438,   395,   397,   400,   417,
     420,   421,   424,   447,   440,   446,   386,   418,   436,   372,
     428,   401,   412,   439,   432,   431,   444,   387,   380,   378,
     379,   419,   451,   452,   453,   454,   455,   456,   457,   414,
     381,   408,     9,     6,     8,     1,     0,    13,    46,    11,
       0,     0,     0,    15,    21,     0,    12,     0,     0,    10,
       0,    21,     0,    14,    17,    52,    24,    48,     0,   155,
       5,     4,    16,    22,     0,     0,    51,    25,     0,    47,
      49,   195,    24,    60,    62,   156,     2,     0,    18,    54,
      53,    50,    59,    61,     0,     0,    23,     0,     0,     0,
       0,    67,     0,    64,     0,   409,   392,   408,     0,     0,
       0,     0,   286,    24,   158,   160,   166,     0,   168,   167,
      39,    32,    41,    33,    34,    38,    37,    36,    31,    28,
       0,    29,    26,    35,    30,    55,    56,    58,     0,    63,
      65,     0,   163,   162,     0,   318,   319,   320,     0,   314,
     326,   321,   327,   325,   322,   323,   324,     0,   316,     0,
     291,   290,   157,   159,   161,     0,   189,    19,    27,    40,
       0,     0,     0,    75,    83,    70,    66,     0,   283,     0,
       0,     0,     0,   315,     0,   317,     0,   173,   193,   194,
       0,     0,   190,   191,    43,    24,    57,     0,    85,     0,
       0,    80,    74,     0,     0,    68,     0,   171,     0,   175,
       0,     0,   287,     0,   331,     0,   328,     0,   334,   174,
     332,    42,    44,   196,   192,    20,   188,    75,     0,   198,
     199,   200,   201,   202,   203,   226,   226,   243,   229,     0,
     208,   209,   210,   211,   212,    78,    75,     0,    82,     0,
      98,   284,   172,     0,   287,   285,     0,     0,     0,     0,
       0,     0,   302,     0,     0,     0,     0,   309,   294,   292,
     295,   296,   298,   288,   293,   297,   289,   367,   368,     0,
     419,   369,     0,   195,   366,     0,   335,   336,   338,   339,
       0,   358,   189,   189,    79,    84,     0,   204,   205,   247,
     248,   249,   250,   251,   252,   254,   206,     0,   245,   235,
     236,   237,   238,   239,   240,   254,   207,     0,   231,    77,
      81,    73,    71,     0,     0,    69,     0,     0,     0,   181,
     179,   186,   177,     0,   330,   329,   311,     0,     0,     0,
       0,   306,   304,     0,     0,   310,     0,   361,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,   357,   342,    45,   197,
       0,     0,   253,     0,   241,     0,     0,   234,     0,     0,
     119,     0,   126,   102,     0,     0,     0,     0,     0,   111,
     112,     0,     0,   117,   122,   121,     0,     0,   125,   128,
     127,   131,   120,     0,     0,   130,   129,    99,   100,     0,
     176,     0,     0,   169,   180,     0,     0,     0,   313,   312,
       0,   307,   305,     0,   308,   362,   364,   337,   355,   349,
     352,   350,   351,   353,   346,   347,   348,   341,   340,     0,
       0,     0,   344,     0,   343,   227,     0,   233,     0,   244,
     246,   242,   230,     0,    76,    72,     0,     0,     0,    87,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     132,   133,     0,     0,     0,   282,   185,   183,   184,   182,
       0,   173,   178,   187,     0,   303,   300,   354,     0,   370,
       0,   363,     0,     0,   255,   232,     0,     0,    96,     0,
       0,   147,   139,   140,   141,   142,   143,   144,   145,   146,
     150,   148,   151,   152,   153,   154,   149,   256,   137,   105,
     135,   134,   136,   106,   109,   107,   113,     0,   123,   124,
     115,   116,   101,   170,   164,     0,     0,   299,   359,   360,
       0,   345,   228,   118,    91,    89,    97,    88,     0,    93,
     104,     0,   138,   103,   257,     0,     0,   221,   215,   219,
     225,   218,     0,     0,     0,   222,   213,     0,   301,   371,
       0,    95,     0,   276,   279,   277,     0,     0,   278,   258,
     259,   270,   275,   110,   108,     0,     0,   216,   217,   114,
       0,     0,     0,    90,     0,    92,     0,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   269,
     220,   224,   214,   223,   165,    94,   274,   261,   260,   267,
     265,   262,   263,   264,     0,     0,     0,   266,     0,   280,
       0,   271,   272,     0,   281
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   333,    93,    98,    99,   104,   111,   113,
     124,   147,   245,   114,   129,   180,   181,   182,   183,   184,
     216,   240,   342,   107,   116,   117,   126,   140,   119,   132,
     133,   144,   152,   153,   188,   300,   255,   251,   252,   225,
     507,   508,   509,   595,   600,   550,   375,   457,   458,   573,
     567,   568,   136,   145,   163,   164,   165,   230,   531,   303,
     270,   260,   380,   465,   381,   382,   277,   241,   242,   243,
     334,   244,   343,   295,   614,   615,   616,   347,   366,   427,
     498,   367,   368,   502,   356,   357,   499,   358,   422,   603,
     604,   629,   630,   631,   632,   680,   166,   227,   228,   229,
     264,   168,   317,   318,   587,   319,   320,   321,   322,   323,
     324,   198,   207,   199,   208,   265,   266,   169,   325,   335,
     336,   337,   338,   493,   494,   339,   340,   341,   540,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -587
static const short yypact[] =
{
      80,  1866,    30,    65,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,    44,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,    89,    91,  -587,  -587,    10,  -587,    24,  -587,
      88,  2598,   105,  -587,   123,  2598,  -587,   130,   114,  -587,
     140,   123,   160,  -587,  -587,   146,  1744,  -587,  2598,   178,
    -587,  -587,  -587,   177,   170,  2598,  -587,  -587,  2598,  -587,
    -587,  -587,  1988,  -587,  -587,  -587,  -587,   173,  -587,   129,
    -587,  -587,  -587,  -587,   167,  1117,  -587,  1373,  2598,  2598,
    2598,  -587,     4,  -587,    93,   161,   174,   175,    26,   -56,
      67,    67,  -587,   988,  -587,   176,  -587,    82,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    1246,  -587,  -587,   214,  -587,  -587,   194,  -587,  1499,   167,
    -587,  2598,  -587,  -587,   204,  -587,  -587,  -587,    35,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,   200,  -587,  2598,
    -587,  -587,  -587,  -587,  -587,  2598,    18,  -587,  -587,  -587,
    2598,   201,  2598,   -18,   202,   219,  -587,   -32,  -587,   208,
    2598,   191,  2598,  -587,  2598,  -587,   199,   203,  -587,  -587,
      17,  2598,    18,  -587,  -587,   224,  -587,  2598,   213,   443,
     215,  -587,   128,  2598,   227,  -587,  2598,   206,  2598,   234,
     211,   233,   225,   228,  -587,   -23,  -587,   -23,   617,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,   207,  2598,  -587,
    -587,  -587,  -587,  -587,  -587,   221,   221,   260,   313,  2598,
    -587,  -587,  -587,  -587,  -587,  -587,   207,   222,  -587,    11,
     212,  -587,  -587,   151,  -587,  -587,   254,  2110,   236,  2598,
    2598,   -26,  -587,  2598,   739,   617,    54,  -587,  -587,  -587,
    -587,  -587,  -587,    54,  -587,  -587,    54,  -587,  -587,   617,
     617,  -587,   135,   239,  -587,   242,   238,  -587,   337,  -587,
     246,  -587,    18,    18,  -587,  -587,   268,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,   248,  -587,   192,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,   248,  -587,   205,   249,   263,
    -587,  -587,  -587,   279,   243,  -587,  2598,   281,   277,   278,
      20,   265,  -587,   210,  -587,  -587,  -587,   282,   283,   312,
     863,  -587,  -587,   183,   -10,  -587,   153,   337,  2598,  -587,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   287,   617,   328,  -587,  -587,   617,  -587,  -587,
      34,   333,  -587,   260,  -587,   313,   351,  -587,  2598,   353,
     358,  2598,  -587,  -587,   339,   340,   341,   316,   329,  -587,
    -587,   356,   359,  -587,  -587,  -587,   360,   361,  -587,  -587,
    -587,    63,  -587,   362,   364,  -587,  -587,   346,  -587,   -30,
    -587,  2232,  2354,   303,  -587,  2110,  2110,   365,  -587,  -587,
     617,  -587,  -587,    54,  -587,  -587,  -587,  -587,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   617,
     366,  1622,   337,   387,   382,  -587,   412,  -587,   391,  -587,
    -587,  -587,  -587,   393,  -587,  -587,   371,   408,    16,  -587,
    -587,   350,   409,     6,  2598,  2598,   410,   404,   416,   417,
    -587,  -587,   421,   424,   243,  -587,  -587,  -587,  -587,  -587,
     331,   203,  -587,  -587,   446,   337,   305,   337,   617,  -587,
      36,  -587,   617,   425,  -587,  -587,   450,  2598,  -587,  2720,
    2476,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,   291,  -587,  -587,
    -587,  -587,  -587,  -587,   441,   442,  -587,    28,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,   426,    54,  -587,   337,  -587,
    1622,   337,  -587,  -587,   445,  -587,   437,  -587,  2598,   452,
    -587,    -8,  -587,  -587,  -587,  2598,  2598,  -587,  -587,   377,
    -587,   384,   467,   470,    64,   392,  -587,   472,  -587,  -587,
    2598,   463,  2598,  -587,  -587,  -587,    -8,    -8,  -587,  -587,
      70,    52,  -587,  -587,  -587,   490,   476,  -587,  -587,  -587,
      28,     8,   473,  -587,  2598,  -587,   474,  -587,    -8,    -8,
      -6,    -6,    -6,    -6,    -6,   457,    -6,   479,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,    -6,   399,    -6,  -587,    -6,  -587,
      96,  -587,  -587,    -6,  -587
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -587,  -587,  -587,    -1,  -587,  -587,   419,  -587,  -587,   407,
    -587,  -587,  -587,  -587,  -126,  -587,  -587,   342,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,   -69,  -587,  -587,  -587,  -587,
     388,  -587,  -587,  -132,  -587,  -587,  -587,  -231,  -587,  -587,
    -587,  -587,   -28,  -587,  -587,  -587,  -587,  -587,    -5,  -587,
    -587,   -44,  -587,  -587,  -587,   368,  -587,  -587,  -587,  -587,
      -7,  -587,  -587,  -587,    59,    62,  -587,   186,  -587,   290,
    -117,   195,  -587,  -587,  -587,  -108,  -106,   250,  -587,  -587,
    -587,  -587,   113,  -587,  -587,  -587,  -587,   116,   179,  -587,
    -587,  -587,  -586,  -148,  -587,  -587,  -587,   169,   294,  -112,
    -242,  -587,  -321,  -587,  -587,  -587,  -587,  -587,  -587,  -248,
    -587,  -587,  -587,   349,   344,   318,   244,  -587,    22,  -587,
    -587,   155,  -312,  -587,  -587,  -587,  -587,  -478,  -587,  -587
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -443
static const short yytable[] =
{
      92,   134,   395,   393,   474,   395,   142,   386,   623,   624,
     623,   624,   256,   539,   256,   134,   305,   396,   397,   326,
     190,   310,   570,   200,   608,   625,   372,   625,   249,   626,
      95,   607,   271,   167,    96,    97,   151,   212,   189,   571,
     646,   647,   387,   103,   608,   609,   344,   130,   272,   612,
     613,   167,   548,   311,   105,   373,   610,   226,   463,   141,
     549,   611,   667,   668,   464,   370,   311,   384,   394,   612,
     613,   100,   495,   395,   589,    96,    97,   257,   496,   525,
     590,   201,   202,   203,   650,   204,   205,   206,     1,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     109,   490,   639,   237,   115,   492,   627,   572,   640,   628,
     651,   628,   619,   250,   101,   115,   108,   131,   102,   275,
     263,   388,   263,   209,   139,   312,   313,   115,   314,   315,
     311,   131,   316,   110,   682,   112,   209,   118,   312,   313,
     683,   314,   315,   120,   162,   316,   179,   185,   186,   187,
     238,   239,   536,   148,   149,   150,   520,   521,   535,   652,
     653,   654,   162,   195,   196,   197,   655,   656,   657,   121,
     658,   659,   195,   196,   197,   232,   123,   537,   125,   179,
     648,   649,   210,   211,   135,   401,   137,   224,   138,   146,
     162,   475,   402,   403,   404,   405,   389,   392,   263,   151,
     209,   191,   312,   313,   192,   314,   315,   193,   236,   316,
     214,   406,   194,   209,   162,   401,   215,   219,   220,   246,
     231,   248,   402,   403,   404,   405,   588,   247,   253,   259,
     591,   262,   254,   262,   258,   261,   268,   269,   127,   278,
     273,   406,   297,   299,   296,   302,   276,   306,   307,   308,
     371,  -286,   298,   249,   309,   162,   374,   304,   346,   376,
     407,   408,   409,   410,   411,   618,   430,   412,   413,   414,
     377,   415,   416,   472,   383,   398,  -365,   345,   431,   200,
     399,   476,   400,   417,   420,   421,   426,   423,   369,   428,
     407,   408,   409,   410,   411,   429,   460,   412,   413,   414,
     425,   415,   416,   461,   462,   467,   379,   551,   304,   262,
     466,   432,   131,   131,   510,   468,   469,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   473,   201,   202,   203,
     234,   204,   205,   206,   470,   489,   452,   453,   454,   497,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   491,   551,   503,   505,   401,
     506,   511,   512,   513,   514,   162,   402,   403,   404,   405,
     349,   350,   351,   352,   353,   354,   355,   515,   516,   131,
     524,   517,   518,   519,   522,   406,   523,   131,   401,   530,
     455,   456,   534,   546,   601,   402,   403,   404,   405,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   406,   541,   542,   504,   543,   544,
     131,   545,   510,   359,   360,   361,   362,   363,   364,   365,
     547,   577,   569,   576,   407,   408,   409,   410,   411,   578,
     579,   412,   413,   414,   580,   415,   416,   581,   583,   586,
     527,   529,   585,   592,   379,   379,   593,   605,   606,  -442,
     617,   620,   635,   407,   408,   409,   410,   538,   622,   636,
     412,   413,   414,   637,   415,   416,   638,   641,   642,   644,
     131,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   669,   670,   671,   672,   673,   660,   675,   661,
     678,   664,   666,   574,   575,   674,   676,   106,   122,   582,
     143,   597,   218,   602,   584,   533,   677,   532,   679,   419,
     681,   213,   274,   663,   662,   684,   348,   418,   501,   500,
     290,   291,   292,   293,   424,   459,   594,   233,   131,   599,
     301,   235,   267,     0,   385,   477,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,     0,   633,   634,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   643,
       0,   645,     0,     0,     0,     4,     5,     6,     7,     8,
       0,     0,     0,   327,     9,     0,     0,    10,     0,    12,
      13,     0,     0,   665,    14,    15,    16,    17,     0,     0,
     328,     0,    18,    19,   329,     0,     0,     0,     0,     0,
      20,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,    54,    55,    56,
      57,    58,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      75,    76,    77,     0,    78,     0,     0,    79,    80,     0,
       0,   330,     0,     0,   331,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,   390,     0,   332,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,    54,
      55,    56,    57,    58,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,    78,     0,     0,    79,
      80,     0,     0,    81,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,   391,
      14,    15,    16,    17,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,     0,     0,    20,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,    54,    55,    56,    57,    58,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,    75,    76,    77,     0,
      78,     0,     0,    79,    80,     0,     0,    81,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   154,     0,     0,     4,     5,     6,   155,
       8,     0,   127,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,   471,     0,    14,    15,    16,    17,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,     0,
       0,    20,     0,    21,    22,   156,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,    55,
      56,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,    75,    76,    77,     0,    78,     0,     0,    79,    80,
       0,     0,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   157,     0,     0,
       0,     0,   154,   158,   159,     4,     5,     6,   155,     8,
       0,     0,   160,   161,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,    18,    19,     0,     0,     0,     0,     0,     0,
      20,     0,    21,    22,   156,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,    54,    55,    56,
      57,    58,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      75,    76,    77,     0,    78,     0,     0,    79,    80,     0,
       0,    81,     0,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   157,     0,     0,   170,
     171,     0,   158,   159,     4,     5,     6,     7,     8,   172,
       0,   160,   161,     9,     0,   217,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,   173,     0,   174,
       0,    18,    19,     0,     0,     0,     0,     0,     0,    20,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   175,    75,
      76,    77,   176,    78,     0,     0,    79,    80,     0,     0,
      81,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   170,   171,   177,   178,
       0,     4,     5,     6,     7,     8,   172,     0,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,    15,    16,    17,   173,     0,   174,     0,    18,    19,
       0,     0,     0,     0,     0,     0,    20,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,    54,    55,    56,    57,    58,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   175,    75,    76,    77,   176,
      78,     0,     0,    79,    80,     0,     0,    81,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,   177,   178,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
     221,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,    18,    19,     0,     0,   222,     0,
       0,     0,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     0,    54,
      55,    56,    57,    58,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,    78,     0,     0,    79,
      80,     0,     0,    81,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   223,
       4,     5,     6,     7,     8,     0,     0,     0,   327,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,   328,     0,    18,    19,     0,
       0,     0,     0,     0,     0,    20,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    54,    55,    56,    57,    58,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,    75,    76,    77,     0,    78,
       0,     0,    79,    80,     0,     0,    81,     0,     0,   331,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     4,     5,     6,     7,     8,     0,   127,     0,
       0,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,     0,     0,    20,   128,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,    75,    76,    77,
       0,    78,     0,     0,    79,    80,     0,     0,    81,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     9,     0,     0,    10,    11,    12,    13,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,     0,     0,     0,     0,     0,     0,    20,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,    75,
      76,    77,     0,    78,     0,     0,    79,    80,     0,     0,
      81,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     4,     5,     6,     7,
       8,     0,   127,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,     0,
       0,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,    55,
      56,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,    75,    76,    77,     0,    78,     0,     0,    79,    80,
       0,     0,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,   378,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,     0,     0,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,    55,    56,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,    75,    76,    77,     0,    78,     0,     0,
      79,    80,     0,     0,    81,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,    18,    19,     0,
       0,   526,     0,     0,     0,    20,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
       0,     0,    54,    55,    56,    57,    58,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,    75,    76,    77,     0,    78,
       0,     0,    79,    80,     0,     0,    81,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,    18,
      19,     0,     0,   528,     0,     0,     0,    20,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     0,     0,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,    75,    76,    77,
       0,    78,     0,     0,    79,    80,     0,     0,    81,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,    15,    16,    17,     0,     0,     0,
       0,    18,    19,     0,     0,   598,     0,     0,     0,    20,
       0,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,     0,     0,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,    75,
      76,    77,     0,    78,     0,     0,    79,    80,     0,     0,
      81,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,     0,
       0,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,    55,
      56,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,    75,    76,    77,     0,    78,     0,     0,    79,    80,
       0,     0,    81,     0,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,     0,    12,    13,     0,     0,     0,    14,    15,    16,
      17,     0,     0,     0,     0,    18,   596,     0,     0,     0,
       0,     0,     0,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,     0,     0,
      54,    55,    56,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,    75,    76,    77,     0,    78,     0,     0,
      79,    80,     0,     0,    81,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91
};

static const short yycheck[] =
{
       1,   118,   323,   315,    14,   326,   132,    33,    16,    17,
      16,    17,    44,   491,    44,   132,   258,   329,   330,   267,
     152,    44,    16,    79,    16,    33,    15,    33,    46,    37,
       0,     3,    15,   145,    10,    11,    32,   163,    34,    33,
     626,   627,    68,    33,    16,    17,   277,   116,    31,    41,
      42,   163,    36,    76,    30,    44,    28,   189,    38,   128,
      44,    33,   648,   649,    44,   296,    76,   309,   316,    41,
      42,    27,    38,   394,    38,    10,    11,   109,    44,   109,
      44,   137,   138,   139,    32,   141,   142,   143,     8,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     101,   413,    38,   215,   105,   417,   114,   101,    44,   117,
      58,   117,   590,   131,    25,   116,    28,   118,    27,   245,
     232,   147,   234,   146,   125,   148,   149,   128,   151,   152,
      76,   132,   155,    28,    38,    12,   146,     7,   148,   149,
      44,   151,   152,    29,   145,   155,   147,   148,   149,   150,
     132,   133,   473,    24,    25,    26,    93,    94,   470,   107,
     108,   109,   163,   137,   138,   139,   114,   115,   116,    29,
     118,   119,   137,   138,   139,   140,    16,   489,    32,   180,
     110,   111,   160,   161,     6,    32,     9,   188,    18,    16,
     191,    38,    39,    40,    41,    42,   313,   314,   310,    32,
     146,   108,   148,   149,    43,   151,   152,    33,   209,   155,
      34,    58,    37,   146,   215,    32,   134,     3,    24,   220,
      16,   222,    39,    40,    41,    42,   538,    26,    26,   230,
     542,   232,    13,   234,    26,    44,    37,    34,    14,    26,
     241,    58,   114,    16,    29,    39,   247,    13,    37,    16,
      28,    26,   253,    46,    26,   256,    44,   258,    37,   108,
     107,   108,   109,   110,   111,   586,    23,   114,   115,   116,
      16,   118,   119,   390,    38,   140,    37,   278,    35,    79,
      38,   398,    44,    37,    16,    37,    37,    95,   289,    26,
     107,   108,   109,   110,   111,    16,    15,   114,   115,   116,
      95,   118,   119,    26,    26,    95,   307,    16,   309,   310,
      45,    68,   313,   314,   431,    33,    33,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,   153,   137,   138,   139,
     140,   141,   142,   143,    32,    58,   103,   104,   105,    16,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    37,    16,    16,    15,    32,
      12,    32,    32,    32,    58,   376,    39,    40,    41,    42,
     120,   121,   122,   123,   124,   125,   126,    58,    32,   390,
      44,    32,    32,    32,    32,    58,    32,   398,    32,    96,
     157,   158,    37,    32,   113,    39,    40,    41,    42,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    58,    38,    44,   428,    16,    38,
     431,    38,   549,   120,   121,   122,   123,   124,   125,   126,
      32,    37,    33,    33,   107,   108,   109,   110,   111,    33,
      33,   114,   115,   116,    33,   118,   119,    33,   127,   154,
     461,   462,    16,    38,   465,   466,    16,    26,    26,    32,
      44,    26,    95,   107,   108,   109,   110,   111,    26,    95,
     114,   115,   116,    16,   118,   119,    16,    95,    16,    26,
     491,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,   650,   651,   652,   653,   654,    17,   656,    33,
     111,    38,    38,   514,   515,    58,    37,    98,   111,   524,
     132,   549,   180,   567,   531,   466,   674,   465,   676,   343,
     678,   163,   242,   641,   640,   683,   286,   342,   425,   423,
      97,    98,    99,   100,   365,   376,   547,   198,   549,   550,
     256,   207,   234,    -1,   310,   400,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   598,    -1,    -1,
      -1,    -1,    -1,    -1,   605,   606,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   620,
      -1,   622,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,   644,    27,    28,    29,    30,    -1,    -1,
      33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,   117,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    32,    -1,   156,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,    -1,
      -1,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,   150,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
     107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     5,    -1,    -1,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    -1,   150,    -1,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,     5,   135,   136,     8,     9,    10,    11,    12,
      -1,    -1,   144,   145,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,    -1,     3,
       4,    -1,   135,   136,     8,     9,    10,    11,    12,    13,
      -1,   144,   145,    17,    -1,    19,    20,    -1,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,    33,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,    -1,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     3,     4,   132,   133,
      -1,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,    -1,    -1,   132,   133,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      21,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,
     111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
      -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
      -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,   117,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,   104,   105,
      -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
     104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,
     110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
      -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,   104,   105,
      -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,
      -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
     104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    -1,   103,   104,   105,    -1,   107,    -1,    -1,
     110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     8,   160,   161,     8,     9,    10,    11,    12,    17,
      20,    21,    22,    23,    27,    28,    29,    30,    35,    36,
      43,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    80,    81,    82,    83,    84,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   103,   104,   105,   107,   110,
     111,   114,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   162,   163,   288,     0,    10,    11,   164,   165,
      27,    25,    27,    33,   166,    30,   165,   182,    28,   162,
      28,   167,    12,   168,   172,   162,   183,   184,     7,   187,
      29,    29,   168,    16,   169,    32,   185,    14,    44,   173,
     184,   162,   188,   189,   229,     6,   211,     9,    18,   162,
     186,   184,   173,   189,   190,   212,    16,   170,    24,    25,
      26,    32,   191,   192,     5,    11,    47,   129,   135,   136,
     144,   145,   162,   213,   214,   215,   255,   258,   260,   276,
       3,     4,    13,    31,    33,   102,   106,   132,   133,   162,
     174,   175,   176,   177,   178,   162,   162,   162,   193,    34,
     192,   108,    43,    33,    37,   137,   138,   139,   270,   272,
      79,   137,   138,   139,   141,   142,   143,   271,   273,   146,
     277,   277,   173,   214,    34,   134,   179,    19,   176,     3,
      24,    21,    39,   130,   162,   198,   192,   256,   257,   258,
     216,    16,   140,   272,   140,   273,   162,   258,   132,   133,
     180,   226,   227,   228,   230,   171,   162,    26,   162,    46,
     131,   196,   197,    26,    13,   195,    44,   109,    26,   162,
     220,    44,   162,   258,   259,   274,   275,   274,    37,    34,
     219,    15,    31,   162,   228,   173,   162,   225,    26,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      97,    98,    99,   100,   128,   232,    29,   114,   162,    16,
     194,   257,    39,   218,   162,   259,    13,    37,    16,    26,
      44,    76,   148,   149,   151,   152,   155,   261,   262,   264,
     265,   266,   267,   268,   269,   277,   268,    16,    33,    37,
     114,   117,   156,   162,   229,   278,   279,   280,   281,   284,
     285,   286,   181,   231,   196,   162,    37,   236,   236,   120,
     121,   122,   123,   124,   125,   126,   243,   244,   246,   120,
     121,   122,   123,   124,   125,   126,   237,   240,   241,   162,
     196,    28,    15,    44,    44,   205,   108,    16,    21,   162,
     221,   223,   224,    38,   259,   275,    33,    68,   147,   229,
      32,   150,   229,   281,   268,   261,   281,   281,   140,    38,
      44,    32,    39,    40,    41,    42,    58,   107,   108,   109,
     110,   111,   114,   115,   116,   118,   119,    37,   230,   226,
      16,    37,   247,    95,   247,    95,    37,   238,    26,    16,
      23,    35,    68,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   103,   104,   105,   157,   158,   206,   207,   256,
      15,    26,    26,    38,    44,   222,    45,    95,    33,    33,
      32,   150,   229,   153,    14,    38,   229,   280,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,    58,
     281,    37,   281,   282,   283,    38,    44,    16,   239,   245,
     246,   241,   242,    16,   162,    15,    12,   199,   200,   201,
     229,    32,    32,    32,    58,    58,    32,    32,    32,    32,
      93,    94,    32,    32,    44,   109,    39,   162,    39,   162,
      96,   217,   224,   223,    37,   281,   261,   281,   111,   286,
     287,    38,    44,    16,    38,    38,    32,    32,    36,    44,
     204,    16,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,   209,   210,    33,
      16,    33,   101,   208,   162,   162,    33,    37,    33,    33,
      33,    33,   207,   127,   219,    16,   154,   263,   281,    38,
      44,   281,    38,    16,   162,   202,    36,   201,    39,   162,
     203,   113,   210,   248,   249,    26,    26,     3,    16,    17,
      28,    33,    41,    42,   233,   234,   235,    44,   261,   286,
      26,   162,    26,    16,    17,    33,    37,   114,   117,   250,
     251,   252,   253,   162,   162,    95,    95,    16,    16,    38,
      44,    95,    16,   162,    26,   162,   251,   251,   110,   111,
      32,    58,   107,   108,   109,   114,   115,   116,   118,   119,
      17,    33,   235,   234,    38,   162,    38,   251,   251,   252,
     252,   252,   252,   252,    58,   252,    37,   252,   111,   252,
     254,   252,    38,    44,   252
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
#line 112 "screen.yacc"
    {A4GL_write_form();}
    break;

  case 3:
#line 115 "screen.yacc"
    {the_form.dbname=strdup("formonly");}
    break;

  case 4:
#line 116 "screen.yacc"
    {the_form.dbname=(yyvsp[-3].str);
if (A4GLF_open_db(yyvsp[-3].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 5:
#line 121 "screen.yacc"
    {the_form.dbname=("formonly");}
    break;

  case 6:
#line 122 "screen.yacc"
    {the_form.dbname=strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 10:
#line 135 "screen.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 13:
#line 141 "screen.yacc"
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
#line 154 "screen.yacc"
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
#line 174 "screen.yacc"
    { 
		lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 18:
#line 176 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 19:
#line 179 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 188 "screen.yacc"
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
#line 210 "screen.yacc"
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
#line 225 "screen.yacc"
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
#line 235 "screen.yacc"
    { ltab=0; }
    break;

  case 31:
#line 236 "screen.yacc"
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
#line 247 "screen.yacc"
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
#line 259 "screen.yacc"
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
#line 272 "screen.yacc"
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
#line 282 "screen.yacc"
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
#line 291 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 37:
#line 296 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 38:
#line 299 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 39:
#line 307 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 40:
#line 308 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 41:
#line 314 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 42:
#line 321 "screen.yacc"
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
#line 335 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 44:
#line 338 "screen.yacc"
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
#line 349 "screen.yacc"
    {
				strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 51:
#line 365 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 52:
#line 372 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 53:
#line 373 "screen.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 54:
#line 376 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 55:
#line 377 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 56:
#line 379 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 57:
#line 380 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 58:
#line 381 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 62:
#line 395 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 67:
#line 411 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 68:
#line 415 "screen.yacc"
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
#line 425 "screen.yacc"
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
#line 453 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 72:
#line 457 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 73:
#line 465 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 74:
#line 466 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 75:
#line 469 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 76:
#line 470 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 77:
#line 473 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 78:
#line 476 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 79:
#line 481 "screen.yacc"
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
#line 490 "screen.yacc"
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
#line 502 "screen.yacc"
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
#line 514 "screen.yacc"
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
#line 522 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 84:
#line 530 "screen.yacc"
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
#line 538 "screen.yacc"
    {
	fld->colname=strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 102:
#line 583 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 103:
#line 584 "screen.yacc"
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
#line 605 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 106:
#line 606 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 107:
#line 607 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 108:
#line 608 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 109:
#line 609 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 110:
#line 610 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 111:
#line 611 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 112:
#line 612 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 113:
#line 613 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 114:
#line 614 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 115:
#line 615 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 116:
#line 616 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 117:
#line 617 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 118:
#line 618 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 119:
#line 620 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 120:
#line 621 "screen.yacc"
    { printf("Warining %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 121:
#line 622 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 122:
#line 623 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 123:
#line 624 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 124:
#line 625 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 125:
#line 626 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 126:
#line 629 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 127:
#line 632 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 131:
#line 636 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 132:
#line 639 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 133:
#line 643 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 134:
#line 649 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 135:
#line 650 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 136:
#line 651 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 138:
#line 656 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str)); }
    break;

  case 139:
#line 660 "screen.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 140:
#line 661 "screen.yacc"
    { strcpy(yyval.str,"4"); }
    break;

  case 141:
#line 662 "screen.yacc"
    { strcpy(yyval.str,"2"); }
    break;

  case 142:
#line 663 "screen.yacc"
    { strcpy(yyval.str,"6"); }
    break;

  case 143:
#line 664 "screen.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 144:
#line 665 "screen.yacc"
    { strcpy(yyval.str,"5"); }
    break;

  case 145:
#line 666 "screen.yacc"
    { strcpy(yyval.str,"7"); }
    break;

  case 146:
#line 667 "screen.yacc"
    { strcpy(yyval.str,"3"); }
    break;

  case 147:
#line 669 "screen.yacc"
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
#line 683 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 149:
#line 684 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 150:
#line 685 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 151:
#line 686 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 152:
#line 687 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 153:
#line 688 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 154:
#line 689 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 156:
#line 694 "screen.yacc"
    {
}
    break;

  case 162:
#line 704 "screen.yacc"
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

  case 163:
#line 714 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 175:
#line 731 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 176:
#line 734 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 177:
#line 750 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 178:
#line 753 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 181:
#line 763 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 182:
#line 765 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 183:
#line 767 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 184:
#line 769 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 185:
#line 771 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 187:
#line 775 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 188:
#line 779 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 189:
#line 785 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 190:
#line 785 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 193:
#line 792 "screen.yacc"
    {colno++;}
    break;

  case 194:
#line 793 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 195:
#line 806 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 196:
#line 814 "screen.yacc"
    {
	colno+=strlen(yyvsp[0].str);
}
    break;

  case 197:
#line 816 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-2].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 198:
#line 823 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 199:
#line 827 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 200:
#line 831 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 201:
#line 835 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 202:
#line 839 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 203:
#line 843 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 204:
#line 847 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 205:
#line 851 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 206:
#line 855 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 207:
#line 859 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 208:
#line 863 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 209:
#line 867 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 210:
#line 871 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 211:
#line 875 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 212:
#line 878 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 214:
#line 885 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 217:
#line 890 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 218:
#line 895 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 219:
#line 896 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 220:
#line 897 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 221:
#line 898 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 223:
#line 900 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 224:
#line 903 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 225:
#line 907 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 226:
#line 913 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 227:
#line 914 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 228:
#line 915 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 229:
#line 918 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 230:
#line 920 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 231:
#line 926 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 232:
#line 928 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 233:
#line 933 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 234:
#line 941 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 235:
#line 944 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 236:
#line 945 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 237:
#line 946 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 238:
#line 947 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 239:
#line 948 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 240:
#line 949 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 241:
#line 951 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 243:
#line 958 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 244:
#line 959 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 245:
#line 962 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 246:
#line 965 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 247:
#line 969 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 248:
#line 970 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 249:
#line 971 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 250:
#line 972 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 251:
#line 973 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 252:
#line 974 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 253:
#line 976 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 254:
#line 981 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 255:
#line 983 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 256:
#line 990 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 257:
#line 990 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 258:
#line 996 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 260:
#line 1003 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 261:
#line 1006 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 262:
#line 1012 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 263:
#line 1013 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 264:
#line 1014 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 265:
#line 1015 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 266:
#line 1016 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 267:
#line 1017 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 268:
#line 1018 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 269:
#line 1019 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 270:
#line 1020 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 271:
#line 1021 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 272:
#line 1022 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 273:
#line 1023 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 274:
#line 1024 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 275:
#line 1027 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 276:
#line 1034 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); printf("NUMBER VALUE : %s\n",yyvsp[0].str); }
    break;

  case 277:
#line 1035 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 278:
#line 1036 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 280:
#line 1044 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 281:
#line 1048 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;

  case 340:
#line 1183 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  }
    break;

  case 341:
#line 1184 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  }
    break;

  case 346:
#line 1196 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 347:
#line 1197 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 348:
#line 1198 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 349:
#line 1199 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 350:
#line 1200 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 351:
#line 1201 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 352:
#line 1202 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 353:
#line 1203 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 354:
#line 1204 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 355:
#line 1205 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 356:
#line 1206 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 357:
#line 1207 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 358:
#line 1208 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 359:
#line 1209 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 360:
#line 1210 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 361:
#line 1211 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 362:
#line 1212 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 363:
#line 1213 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 364:
#line 1214 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 366:
#line 1220 "screen.yacc"
    { yyval.expr=create_field_expr(yyvsp[0].str); }
    break;

  case 367:
#line 1221 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); }
    break;

  case 368:
#line 1222 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 369:
#line 1223 "screen.yacc"
    { yyval.expr=create_special_expr(yyvsp[0].str); }
    break;

  case 370:
#line 1226 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 371:
#line 1230 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 991 of yacc.c.  */
#line 4116 "y.tab.c"

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


#line 1330 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */





