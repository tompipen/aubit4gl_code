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
     KWWHERE = 364,
     KWNOT = 365,
     KWBETWEEN = 366,
     KWIN = 367,
     XVAL = 368,
     KWNULLCHK = 369,
     KWNOTNULLCHK = 370,
     YEAR = 371,
     MONTH = 372,
     DAY = 373,
     HOUR = 374,
     MINUTE = 375,
     SECOND = 376,
     FRACTION = 377,
     LISTBOX = 378,
     BUTTON = 379,
     KW_PANEL = 380,
     DISPLAYONLY = 381,
     ALLOWING = 382,
     KW_WS = 383,
     KW_TAB = 384,
     KW_MASTER_OF = 385,
     KW_BEFORE = 386,
     KW_AFTER = 387,
     KW_EDITADD = 388,
     KW_EDITUPDATE = 389,
     KW_REMOVE = 390,
     KW_OF = 391,
     KW_ADD = 392,
     KW_UPDATE = 393,
     KW_QUERY = 394,
     KW_ON_ENDING = 395,
     KW_ON_BEGINNING = 396,
     KW_CALL = 397,
     KW_BELL = 398,
     KW_ABORT = 399,
     KW_LET = 400,
     KW_EXITNOW = 401,
     KW_NEXTFIELD = 402,
     KW_IF = 403,
     KW_THEN = 404,
     KW_ELSE = 405,
     KW_BEGIN = 406,
     KW_TOTAL = 407,
     KW_RIGHT = 408,
     KW_ZEROFILL = 409
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
#define KWWHERE 364
#define KWNOT 365
#define KWBETWEEN 366
#define KWIN 367
#define XVAL 368
#define KWNULLCHK 369
#define KWNOTNULLCHK 370
#define YEAR 371
#define MONTH 372
#define DAY 373
#define HOUR 374
#define MINUTE 375
#define SECOND 376
#define FRACTION 377
#define LISTBOX 378
#define BUTTON 379
#define KW_PANEL 380
#define DISPLAYONLY 381
#define ALLOWING 382
#define KW_WS 383
#define KW_TAB 384
#define KW_MASTER_OF 385
#define KW_BEFORE 386
#define KW_AFTER 387
#define KW_EDITADD 388
#define KW_EDITUPDATE 389
#define KW_REMOVE 390
#define KW_OF 391
#define KW_ADD 392
#define KW_UPDATE 393
#define KW_QUERY 394
#define KW_ON_ENDING 395
#define KW_ON_BEGINNING 396
#define KW_CALL 397
#define KW_BELL 398
#define KW_ABORT 399
#define KW_LET 400
#define KW_EXITNOW 401
#define KW_NEXTFIELD 402
#define KW_IF 403
#define KW_THEN 404
#define KW_ELSE 405
#define KW_BEGIN 406
#define KW_TOTAL 407
#define KW_RIGHT 408
#define KW_ZEROFILL 409




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
#line 470 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 482 "y.tab.c"

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
#define YYLAST   2770

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  155
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  130
/* YYNRULES -- Number of rules. */
#define YYNRULES  450
/* YYNRULES -- Number of states. */
#define YYNSTATES  678

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   409

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
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154
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
     440,   442,   443,   444,   449,   451,   454,   456,   459,   462,
     463,   473,   486,   488,   490,   492,   493,   496,   497,   499,
     500,   502,   504,   509,   511,   515,   516,   518,   520,   524,
     528,   532,   536,   538,   542,   544,   545,   547,   549,   552,
     554,   556,   558,   559,   564,   566,   568,   570,   572,   574,
     576,   579,   582,   585,   588,   590,   592,   594,   596,   598,
     600,   604,   606,   609,   612,   614,   616,   620,   622,   624,
     628,   632,   634,   635,   639,   645,   646,   650,   651,   655,
     657,   660,   662,   664,   666,   668,   670,   672,   675,   677,
     678,   682,   684,   686,   688,   690,   692,   694,   696,   698,
     701,   702,   706,   707,   709,   712,   714,   718,   722,   726,
     730,   734,   738,   743,   747,   750,   753,   755,   761,   767,
     770,   774,   776,   778,   780,   782,   784,   786,   790,   799,
     801,   805,   809,   811,   813,   819,   825,   828,   831,   833,
     835,   837,   839,   841,   843,   845,   851,   852,   855,   857,
     862,   865,   869,   872,   876,   880,   882,   885,   888,   892,
     896,   898,   901,   903,   906,   908,   910,   912,   914,   916,
     918,   920,   922,   924,   926,   928,   932,   936,   938,   943,
     949,   950,   952,   954,   958,   960,   962,   966,   970,   971,
     973,   975,   979,   983,   987,   991,   995,   999,  1003,  1007,
    1011,  1016,  1020,  1023,  1026,  1028,  1034,  1040,  1043,  1047,
    1052,  1056,  1058,  1060,  1062,  1064,  1066,  1068,  1072,  1074,
    1076,  1078,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,
    1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,
    1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,  1132,  1134,
    1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,  1152,  1154,
    1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,  1172,  1174,
    1176,  1178,  1180,  1182,  1184,  1186,  1188,  1190,  1192,  1194,
    1196,  1198,  1200,  1202,  1204,  1206,  1208,  1210,  1212,  1214,
    1216,  1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,
    1236
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     156,     0,    -1,   157,   160,   178,   183,   207,    -1,     8,
      21,    -1,     8,   159,    27,    28,    29,    -1,     8,    21,
      27,    28,    29,    -1,     8,   159,    -1,    17,    -1,   284,
      -1,   158,    -1,   158,    25,   158,    -1,   161,    -1,   160,
     161,    -1,    -1,    11,   162,   164,    -1,    -1,    10,    33,
     163,   164,    -1,    -1,    -1,    -1,   168,   165,    18,   166,
     170,    19,   167,   169,    -1,    -1,    12,    16,    -1,    12,
      16,     9,    16,    -1,    -1,    14,    -1,   172,    -1,   170,
     172,    -1,   158,    -1,   171,    -1,   174,    -1,   129,    -1,
       4,    -1,    31,    -1,    33,    -1,   173,    -1,   128,    -1,
     103,    -1,    99,    -1,     3,    -1,   173,     3,    -1,    -1,
      13,   175,   176,    15,    -1,   226,    -1,    -1,   176,    31,
     177,   226,    -1,    -1,    30,   179,   169,    -1,   180,    -1,
     179,   180,    -1,   179,    44,   180,    -1,   158,   181,    -1,
      -1,    32,   182,    -1,   158,    -1,   158,    24,   158,    -1,
     158,    25,   158,    -1,   158,    25,   158,    24,   158,    -1,
     158,    26,   158,    -1,     7,   184,   169,    -1,   185,    -1,
     184,   185,    -1,    -1,   225,   186,   187,    34,    -1,   188,
      -1,   187,   188,    -1,   187,    34,   188,    -1,    -1,    -1,
      32,   189,   194,   191,   190,   201,    -1,    -1,    13,    16,
      15,    -1,    13,    16,    44,    16,    15,    -1,   193,   110,
      28,    -1,   193,    -1,    -1,    46,    58,   158,    26,   158,
      -1,    46,    58,   158,    -1,    46,   228,    -1,    21,    26,
     221,   192,    -1,   126,   192,    -1,   126,   127,    29,   192,
      -1,   158,    26,   158,    -1,   158,    -1,    39,   158,    26,
     158,    -1,    39,   158,    -1,   225,    -1,   197,    -1,   196,
      44,   197,    -1,   195,    32,   198,    -1,   158,    26,   158,
      -1,   158,    -1,   158,    26,   158,    -1,   158,    -1,    39,
     158,    26,   158,    -1,    39,   158,    -1,    36,    -1,    44,
      36,    -1,    -1,    44,   202,    -1,   203,    -1,   202,    44,
     203,    -1,    71,    -1,    72,    32,   205,   244,    -1,    35,
     196,   200,   199,    -1,    73,    32,    33,    -1,    74,    32,
     204,    -1,    76,    58,   158,    -1,    76,    58,   158,    26,
     158,    -1,    75,    58,   158,    -1,    75,    58,   158,    26,
     158,    -1,    77,    -1,    78,    -1,    79,    32,    33,    -1,
      80,    32,    37,   229,    38,    -1,   101,    32,    33,    -1,
     102,    32,    33,    -1,    81,    -1,    23,    12,    32,    16,
      -1,    23,    -1,   100,    -1,    83,    -1,    82,    -1,    84,
      32,    33,    -1,    85,    32,    33,    -1,    86,    -1,    67,
      -1,    88,    -1,    87,    -1,   154,    -1,   153,    -1,    89,
      -1,    89,    90,    -1,    89,    91,    -1,    33,    -1,    16,
      -1,    98,    -1,   206,    -1,   205,   206,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,
      70,    -1,    -1,    -1,     6,   208,   209,   169,    -1,   210,
      -1,   209,   210,    -1,   211,    -1,   211,    34,    -1,    47,
      33,    -1,    -1,    11,    43,   212,   216,    37,   217,    38,
     213,   215,    -1,   125,    37,    16,    44,    16,    38,    92,
      37,    16,    44,    16,    38,    -1,   251,    -1,   272,    -1,
     256,    -1,    -1,    93,   123,    -1,    -1,    39,    -1,    -1,
      34,    -1,   158,    -1,   158,    13,    16,    15,    -1,   220,
      -1,   217,   218,   220,    -1,    -1,    44,    -1,   158,    -1,
     158,    26,   158,    -1,    21,    26,   158,    -1,   158,    26,
      39,    -1,    21,    26,    39,    -1,   219,    -1,   219,    45,
     219,    -1,   158,    -1,    -1,   223,    -1,   224,    -1,   223,
     224,    -1,   128,    -1,   129,    -1,   158,    -1,    -1,   222,
     158,   227,   222,    -1,    48,    -1,    49,    -1,    50,    -1,
      51,    -1,    52,    -1,    53,    -1,    54,   232,    -1,    55,
     232,    -1,    56,   239,    -1,    57,   233,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,   124,    -1,   231,    -1,
     229,    44,   231,    -1,    16,    -1,    41,    16,    -1,    42,
      16,    -1,    33,    -1,    17,    -1,    17,    92,    17,    -1,
       3,    -1,   230,    -1,   230,    92,   230,    -1,    33,    92,
      33,    -1,    28,    -1,    -1,    37,    16,    38,    -1,    37,
      16,    44,    16,    38,    -1,    -1,   236,    92,   238,    -1,
      -1,    37,    16,    38,    -1,    16,    -1,   237,   234,    -1,
     116,    -1,   117,    -1,   118,    -1,   119,    -1,   120,    -1,
     121,    -1,   122,   243,    -1,   237,    -1,    -1,   240,    92,
     241,    -1,   242,    -1,   242,    -1,   116,    -1,   117,    -1,
     118,    -1,   119,    -1,   120,    -1,   121,    -1,   122,   243,
      -1,    -1,    37,   235,    38,    -1,    -1,   245,    -1,   109,
     246,    -1,   247,    -1,   247,   108,   247,    -1,   247,   107,
     247,    -1,   248,   104,   248,    -1,   248,   105,   248,    -1,
     248,   106,   248,    -1,   248,    58,   248,    -1,   248,   110,
      58,   248,    -1,   248,    32,   248,    -1,   248,   114,    -1,
     248,   115,    -1,   248,    -1,   248,   111,   248,   108,   248,
      -1,   248,   112,    37,   250,    38,    -1,   110,   247,    -1,
      37,   247,    38,    -1,   249,    -1,    16,    -1,    33,    -1,
     113,    -1,    17,    -1,   248,    -1,   250,    44,   248,    -1,
       5,   105,   252,   106,   214,   105,   252,   106,    -1,   253,
      -1,   252,    44,   253,    -1,   254,    26,   255,    -1,   158,
      -1,   158,    -1,   131,   266,   136,   270,   264,    -1,   132,
     267,   136,   270,   264,    -1,   141,   273,    -1,   140,   273,
      -1,   260,    -1,   265,    -1,   258,    -1,   261,    -1,   262,
      -1,   273,    -1,   263,    -1,   148,   277,   149,   257,   259,
      -1,    -1,   150,   257,    -1,   144,    -1,   145,   225,    32,
     277,    -1,   147,   225,    -1,   147,    32,   225,    -1,   147,
     146,    -1,   147,    32,   146,    -1,   151,   264,    14,    -1,
     257,    -1,   264,   257,    -1,    73,    33,    -1,    73,   143,
      33,    -1,    73,    67,    33,    -1,   268,    -1,   266,   268,
      -1,   269,    -1,   267,   269,    -1,   133,    -1,   134,    -1,
     135,    -1,   133,    -1,   137,    -1,   138,    -1,   139,    -1,
     135,    -1,    76,    -1,   134,    -1,   271,    -1,   270,    44,
     271,    -1,   254,    26,   255,    -1,   255,    -1,   254,   130,
     254,   215,    -1,   142,   158,    37,   274,    38,    -1,    -1,
     275,    -1,   276,    -1,   275,    44,   276,    -1,   277,    -1,
     280,    -1,   277,   108,   277,    -1,   277,   107,   277,    -1,
      -1,   279,    -1,   277,    -1,   279,    44,   277,    -1,   277,
     104,   277,    -1,   277,   105,   277,    -1,   277,   106,   277,
      -1,   277,    39,   277,    -1,   277,    41,   277,    -1,   277,
      42,   277,    -1,   277,    40,   277,    -1,   277,    58,   277,
      -1,   277,   110,    58,   277,    -1,   277,    32,   277,    -1,
     277,   114,    -1,   277,   115,    -1,   282,    -1,   277,   111,
     277,   108,   277,    -1,   277,   112,    37,   283,    38,    -1,
     110,   277,    -1,    37,   277,    38,    -1,   281,    37,   278,
      38,    -1,   152,   136,   225,    -1,   158,    -1,   225,    -1,
      16,    -1,    33,    -1,   113,    -1,   282,    -1,   283,    44,
     282,    -1,    93,    -1,    71,    -1,    59,    -1,    69,    -1,
      60,    -1,   107,    -1,   108,    -1,   104,    -1,   124,    -1,
       9,    -1,    72,    -1,    22,    -1,    73,    -1,    90,    -1,
     102,    -1,    62,    -1,     8,    -1,    56,    -1,    74,    -1,
      47,    -1,    77,    -1,    23,    -1,    79,    -1,    61,    -1,
      80,    -1,    29,    -1,    57,    -1,    81,    -1,    95,    -1,
      48,    -1,    50,    -1,    54,    -1,    51,    -1,    49,    -1,
      28,    -1,   125,    -1,    11,    -1,    10,    -1,    12,    -1,
      96,    -1,    68,    -1,   123,    -1,    64,    -1,    55,    -1,
      83,    -1,    91,    -1,   110,    -1,    84,    -1,    85,    -1,
      43,    -1,    63,    -1,    86,    -1,    67,    -1,    94,    -1,
      52,    -1,    53,    -1,   100,    -1,    98,    -1,    30,    -1,
      45,    -1,    20,    -1,    92,    -1,    70,    -1,    78,    -1,
      97,    -1,    88,    -1,    35,    -1,    36,    -1,    65,    -1,
     101,    -1,    27,    -1,    89,    -1,    87,    -1,    66,    -1,
      46,    -1,    58,    -1,   116,    -1,   117,    -1,   118,    -1,
     119,    -1,   120,    -1,   121,    -1,   122,    -1
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
     664,   667,   670,   673,   676,   679,   682,   685,   688,   691,
     694,   698,   699,   699,   704,   704,   706,   706,   709,   719,
     719,   722,   723,   724,   725,   729,   729,   731,   731,   733,
     733,   736,   739,   755,   758,   762,   763,   767,   769,   771,
     773,   775,   780,   780,   784,   790,   790,   793,   793,   797,
     798,   811,   819,   819,   828,   832,   836,   840,   844,   848,
     852,   856,   860,   864,   868,   872,   876,   880,   883,   890,
     890,   895,   895,   895,   900,   901,   902,   903,   904,   905,
     908,   912,   918,   919,   920,   923,   924,   931,   933,   938,
     946,   949,   950,   951,   952,   953,   954,   955,   961,   963,
     964,   967,   970,   974,   975,   976,   977,   978,   979,   980,
     986,   988,   995,   995,  1001,  1007,  1008,  1011,  1017,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    1029,  1032,  1039,  1040,  1041,  1046,  1049,  1053,  1065,  1068,
    1069,  1072,  1075,  1078,  1082,  1083,  1084,  1085,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1100,  1104,  1104,  1107,  1110,
    1113,  1114,  1115,  1116,  1120,  1123,  1124,  1129,  1130,  1131,
    1136,  1136,  1140,  1140,  1144,  1145,  1146,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1159,  1160,  1164,  1165,  1169,  1172,
    1175,  1175,  1179,  1179,  1182,  1187,  1188,  1191,  1196,  1197,
    1200,  1201,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,
    1223,  1226,  1229,  1230,  1231,  1232,  1235,  1239,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,
    1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1273,  1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,
    1283,  1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,
    1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,
    1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,
    1333
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
  "COMPARISON", "LESSTHAN", "GREATERTHAN", "KWOR", "KWAND", "KWWHERE", 
  "KWNOT", "KWBETWEEN", "KWIN", "XVAL", "KWNULLCHK", "KWNOTNULLCHK", 
  "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", "FRACTION", 
  "LISTBOX", "BUTTON", "KW_PANEL", "DISPLAYONLY", "ALLOWING", "KW_WS", 
  "KW_TAB", "KW_MASTER_OF", "KW_BEFORE", "KW_AFTER", "KW_EDITADD", 
  "KW_EDITUPDATE", "KW_REMOVE", "KW_OF", "KW_ADD", "KW_UPDATE", 
  "KW_QUERY", "KW_ON_ENDING", "KW_ON_BEGINNING", "KW_CALL", "KW_BELL", 
  "KW_ABORT", "KW_LET", "KW_EXITNOW", "KW_NEXTFIELD", "KW_IF", "KW_THEN", 
  "KW_ELSE", "KW_BEGIN", "KW_TOTAL", "KW_RIGHT", "KW_ZEROFILL", "$accept", 
  "form_def", "database_section", "named_or_kw", "dbname", 
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
     405,   406,   407,   408,   409
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   155,   156,   157,   157,   157,   157,   158,   158,   159,
     159,   160,   160,   162,   161,   163,   161,   165,   166,   167,
     164,   168,   168,   168,   169,   169,   170,   170,   171,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   173,
     173,   175,   174,   176,   177,   176,   178,   178,   179,   179,
     179,   180,   181,   181,   182,   182,   182,   182,   182,   183,
     184,   184,   186,   185,   187,   187,   187,   189,   190,   188,
     191,   191,   191,   192,   192,   193,   193,   193,   193,   194,
     194,   194,   194,   194,   194,   194,   195,   196,   196,   197,
     198,   198,   199,   199,   199,   199,   200,   200,   201,   201,
     202,   202,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   203,   203,   203,   203,   203,   203,
     203,   203,   203,   203,   204,   204,   204,   205,   205,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   207,   208,   207,   209,   209,   210,   210,   211,   212,
     211,   211,   211,   211,   211,   213,   213,   214,   214,   215,
     215,   216,   216,   217,   217,   218,   218,   219,   219,   219,
     219,   219,   220,   220,   221,   222,   222,   223,   223,   224,
     224,   225,   227,   226,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   229,
     229,   230,   230,   230,   231,   231,   231,   231,   231,   231,
     231,   231,   232,   232,   232,   233,   233,   234,   234,   235,
     236,   237,   237,   237,   237,   237,   237,   237,   238,   239,
     239,   240,   241,   242,   242,   242,   242,   242,   242,   242,
     243,   243,   244,   244,   245,   246,   246,   246,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   248,   248,   248,   248,   249,   250,   250,   251,   252,
     252,   253,   254,   255,   256,   256,   256,   256,   257,   257,
     257,   257,   257,   257,   257,   258,   259,   259,   260,   261,
     262,   262,   262,   262,   263,   264,   264,   265,   265,   265,
     266,   266,   267,   267,   268,   268,   268,   269,   269,   269,
     269,   269,   269,   269,   270,   270,   271,   271,   272,   273,
     274,   274,   275,   275,   276,   277,   277,   277,   278,   278,
     279,   279,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   281,   282,   282,   282,   282,   283,   283,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284
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
       1,     0,     0,     4,     1,     2,     1,     2,     2,     0,
       9,    12,     1,     1,     1,     0,     2,     0,     1,     0,
       1,     1,     4,     1,     3,     0,     1,     1,     3,     3,
       3,     3,     1,     3,     1,     0,     1,     1,     2,     1,
       1,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     2,     1,     1,     3,     1,     1,     3,
       3,     1,     0,     3,     5,     0,     3,     0,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     4,     3,     2,     2,     1,     5,     5,     2,
       3,     1,     1,     1,     1,     1,     1,     3,     8,     1,
       3,     3,     1,     1,     5,     5,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     0,     2,     1,     4,
       2,     3,     2,     3,     3,     1,     2,     2,     3,     3,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     4,     5,
       0,     1,     1,     3,     1,     1,     3,     3,     0,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     2,     2,     1,     5,     5,     2,     3,     4,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       0,     0,     0,     0,   384,   377,   405,   404,   406,     7,
     428,     3,   379,   389,   438,   402,   393,   426,   434,   435,
     417,   427,   442,   387,   397,   401,   398,   400,   422,   423,
     399,   411,   385,   394,   443,   370,   372,   391,   383,   418,
     410,   436,   441,   420,   408,   371,   430,   369,   378,   380,
     386,   388,   431,   390,   392,   395,   412,   415,   416,   419,
     440,   433,   439,   381,   413,   429,   368,   421,   396,   407,
     432,   425,   424,   437,   382,   375,   373,   374,   414,   444,
     445,   446,   447,   448,   449,   450,   409,   376,   403,     9,
       6,     8,     1,     0,    13,    46,    11,     0,     0,     0,
      15,    21,     0,    12,     0,     0,    10,     0,    21,     0,
      14,    17,    52,    24,    48,     0,   151,     5,     4,    16,
      22,     0,     0,    51,    25,     0,    47,    49,   191,    24,
      60,    62,   152,     2,     0,    18,    54,    53,    50,    59,
      61,     0,     0,    23,     0,     0,     0,     0,    67,     0,
      64,     0,   404,   387,   403,     0,     0,     0,     0,   282,
      24,   154,   156,   162,     0,   164,   163,    39,    32,    41,
      33,    34,    38,    37,    36,    31,    28,     0,    29,    26,
      35,    30,    55,    56,    58,     0,    63,    65,     0,   159,
     158,     0,   314,   315,   316,     0,   310,   322,   317,   323,
     321,   318,   319,   320,     0,   312,     0,   287,   286,   153,
     155,   157,     0,   185,    19,    27,    40,     0,     0,     0,
      75,    83,    70,    66,     0,   279,     0,     0,     0,     0,
     311,     0,   313,     0,   169,   189,   190,     0,     0,   186,
     187,    43,    24,    57,     0,    85,     0,     0,    80,    74,
       0,     0,    68,     0,   167,     0,   171,     0,     0,   283,
       0,   327,     0,   324,     0,   330,   170,   328,    42,    44,
     192,   188,    20,   184,    75,     0,   194,   195,   196,   197,
     198,   199,   222,   222,   239,   225,     0,   204,   205,   206,
     207,   208,    78,    75,     0,    82,     0,    98,   280,   168,
       0,   283,   281,     0,     0,     0,     0,     0,     0,   298,
       0,     0,     0,     0,   305,   290,   288,   291,   292,   294,
     284,   289,   293,   285,   363,   364,     0,   414,   365,     0,
     191,   362,     0,   331,   332,   334,   335,     0,   354,   185,
     185,    79,    84,     0,   200,   201,   243,   244,   245,   246,
     247,   248,   250,   202,     0,   241,   231,   232,   233,   234,
     235,   236,   250,   203,     0,   227,    77,    81,    73,    71,
       0,     0,    69,     0,     0,     0,   177,   175,   182,   173,
       0,   326,   325,   307,     0,     0,     0,     0,   302,   300,
       0,     0,   306,     0,   357,     0,   329,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   352,   353,   338,    45,   193,     0,     0,   249,
       0,   237,     0,     0,   230,     0,     0,   119,     0,   126,
     102,     0,     0,     0,     0,     0,   111,   112,     0,     0,
     117,   122,   121,     0,     0,   125,   128,   127,   131,   120,
       0,     0,   130,   129,    99,   100,     0,   172,     0,     0,
     165,   176,     0,     0,     0,   309,   308,     0,   303,   301,
       0,   304,   358,   360,   333,   351,   345,   348,   346,   347,
     349,   342,   343,   344,   337,   336,     0,     0,     0,   340,
       0,   339,   223,     0,   229,     0,   240,   242,   238,   226,
       0,    76,    72,     0,     0,     0,    87,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,   278,   181,   179,   180,   178,     0,   169,   174,
     183,     0,   299,   296,   350,     0,   366,     0,   359,     0,
       0,   251,   228,     0,     0,    96,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     252,   137,   105,   135,   134,   136,   106,   109,   107,   113,
       0,   123,   124,   115,   116,   101,   166,   160,     0,     0,
     295,   355,   356,     0,   341,   224,   118,    91,    89,    97,
      88,     0,    93,   104,     0,   138,   103,   253,     0,     0,
     217,   211,   215,   221,   214,     0,     0,     0,   218,   209,
       0,   297,   367,     0,    95,     0,   272,   275,   273,     0,
       0,   274,   254,   255,   266,   271,   110,   108,     0,     0,
     212,   213,   114,     0,     0,     0,    90,     0,    92,     0,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   265,   216,   220,   210,   219,   161,    94,   270,
     257,   256,   263,   261,   258,   259,   260,     0,     0,     0,
     262,     0,   276,     0,   267,   268,     0,   277
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,   330,    90,    95,    96,   101,   108,   110,
     121,   144,   242,   111,   126,   177,   178,   179,   180,   181,
     213,   237,   339,   104,   113,   114,   123,   137,   116,   129,
     130,   141,   149,   150,   185,   297,   252,   248,   249,   222,
     504,   505,   506,   588,   593,   547,   372,   454,   455,   566,
     560,   561,   133,   142,   160,   161,   162,   227,   528,   300,
     267,   257,   377,   462,   378,   379,   274,   238,   239,   240,
     331,   241,   340,   292,   607,   608,   609,   344,   363,   424,
     495,   364,   365,   499,   353,   354,   496,   355,   419,   596,
     597,   622,   623,   624,   625,   673,   163,   224,   225,   226,
     261,   165,   314,   315,   580,   316,   317,   318,   319,   320,
     321,   195,   204,   196,   205,   262,   263,   166,   322,   332,
     333,   334,   335,   490,   491,   336,   337,   338,   537,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -582
static const short yypact[] =
{
      23,  1819,    74,    43,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,    30,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,    53,
      66,  -582,  -582,    77,  -582,    33,  -582,    79,  2527,    99,
    -582,   120,  2527,  -582,   128,   109,  -582,   110,   120,   126,
    -582,  -582,   119,  1701,  -582,  2527,   151,  -582,  -582,  -582,
     149,   142,  2527,  -582,  -582,  2527,  -582,  -582,  -582,  1937,
    -582,  -582,  -582,  -582,   145,  -582,   129,  -582,  -582,  -582,
    -582,   146,  1094,  -582,  1342,  2527,  2527,  2527,  -582,    81,
    -582,    72,   138,   155,   156,    57,    86,    52,    52,  -582,
     969,  -582,   161,  -582,    68,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  1219,  -582,  -582,
     196,  -582,  -582,   176,  -582,  1464,   146,  -582,  2527,  -582,
    -582,   185,  -582,  -582,  -582,    14,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,   -53,  -582,  2527,  -582,  -582,  -582,
    -582,  -582,  2527,   -87,  -582,  -582,  -582,  2527,   180,  2527,
     -28,   181,   201,  -582,   -34,  -582,   189,  2527,   173,  2527,
    -582,  2527,  -582,   190,   188,  -582,  -582,    21,  2527,   -87,
    -582,  -582,   215,  -582,  2527,   205,   440,   204,  -582,   124,
    2527,   219,  -582,  2527,   197,  2527,   232,   209,   231,   222,
     224,  -582,   -22,  -582,   -22,   610,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,   207,  2527,  -582,  -582,  -582,  -582,
    -582,  -582,   220,   220,   177,   218,  2527,  -582,  -582,  -582,
    -582,  -582,  -582,   207,   227,  -582,    11,   212,  -582,  -582,
     153,  -582,  -582,   243,  2055,   225,  2527,  2527,   -27,  -582,
    2527,   728,   610,    38,  -582,  -582,  -582,  -582,  -582,  -582,
      38,  -582,  -582,    38,  -582,  -582,   610,   610,  -582,   132,
     223,  -582,   234,   221,  -582,   334,  -582,   233,  -582,   -87,
     -87,  -582,  -582,   253,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,   238,  -582,   184,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,   238,  -582,   186,   240,   254,  -582,  -582,  -582,
     267,   244,  -582,  2527,   269,   260,   261,    26,   256,  -582,
     210,  -582,  -582,  -582,   255,   274,   280,   848,  -582,  -582,
     250,   -11,  -582,   311,   334,  2527,  -582,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   283,
     610,   276,  -582,  -582,   610,  -582,  -582,    27,   326,  -582,
     177,  -582,   218,   331,  -582,  2527,   333,   347,  2527,  -582,
    -582,   335,   336,   338,   305,   313,  -582,  -582,   345,   346,
    -582,  -582,  -582,   348,   349,  -582,  -582,  -582,    12,  -582,
     350,   351,  -582,  -582,   340,  -582,   -19,  -582,  2173,  2291,
     286,  -582,  2055,  2055,   352,  -582,  -582,   610,  -582,  -582,
      38,  -582,  -582,  -582,  -582,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   610,   370,  1583,   334,
     353,   341,  -582,   371,  -582,   355,  -582,  -582,  -582,  -582,
     357,  -582,  -582,   356,   358,    32,  -582,  -582,   488,   363,
      -3,  2527,  2527,   367,   364,   372,   373,  -582,  -582,   374,
     375,   244,  -582,  -582,  -582,  -582,  -582,   281,   188,  -582,
    -582,   387,   334,   263,   334,   610,  -582,    31,  -582,   610,
     376,  -582,  -582,   404,  2527,  -582,  2645,  2409,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
     453,  -582,  -582,  -582,  -582,  -582,  -582,   403,   405,  -582,
      17,  -582,  -582,  -582,  -582,  -582,  -582,  -582,   386,    38,
    -582,   334,  -582,  1583,   334,  -582,  -582,   407,  -582,   402,
    -582,  2527,   409,  -582,    -5,  -582,  -582,  -582,  2527,  2527,
    -582,  -582,   344,  -582,   359,   421,   427,    50,   360,  -582,
     431,  -582,  -582,  2527,   424,  2527,  -582,  -582,  -582,    -5,
      -5,  -582,  -582,   -18,    98,  -582,  -582,  -582,   436,   422,
    -582,  -582,  -582,    17,     5,   416,  -582,  2527,  -582,   418,
    -582,    -5,    -5,    -9,    -9,    -9,    -9,    -9,   401,    -9,
     423,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,  -582,  -582,    -9,   361,    -9,
    -582,    -9,  -582,    62,  -582,  -582,    -9,  -582
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -582,  -582,  -582,    -1,  -582,  -582,   368,  -582,  -582,   362,
    -582,  -582,  -582,  -582,  -125,  -582,  -582,   287,  -582,  -582,
    -582,  -582,  -582,  -582,  -582,   -76,  -582,  -582,  -582,  -582,
     337,  -582,  -582,  -130,  -582,  -582,  -582,  -245,  -582,  -582,
    -582,  -582,   -81,  -582,  -582,  -582,  -582,  -582,   -54,  -582,
    -582,   -92,  -582,  -582,  -582,   312,  -582,  -582,  -582,  -582,
     -57,  -582,  -582,  -582,    10,    24,  -582,   139,  -582,   262,
    -114,   144,  -582,  -582,  -582,  -135,  -131,   217,  -582,  -582,
    -582,  -582,    82,  -582,  -582,  -582,  -582,    83,   143,  -582,
    -582,  -582,  -581,  -405,  -582,  -582,  -582,   133,   271,  -133,
    -239,  -582,  -318,  -582,  -582,  -582,  -582,  -582,  -582,  -247,
    -582,  -582,  -582,   314,   303,   277,   226,  -582,   -39,  -582,
    -582,   130,  -235,  -582,  -582,  -582,  -582,  -474,  -582,  -582
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -436
static const short yytable[] =
{
      89,   131,   392,   471,   139,   392,   383,   616,   617,   164,
     253,   616,   617,   563,   536,   131,   302,   323,   246,   187,
     600,   601,   307,   197,   618,   253,   369,   164,   618,   341,
     564,     1,   619,   601,   602,   209,   268,   127,   639,   640,
     384,   235,   236,    93,    94,   603,   605,   606,   367,   138,
     604,   308,   269,    93,    94,   370,   223,    97,   605,   606,
     660,   661,   308,   102,   460,   492,   391,   381,   545,   582,
     461,   493,   254,   392,    92,   583,   546,   390,    98,   234,
     198,   199,   200,   231,   201,   202,   203,   522,   632,   641,
     642,   393,   394,    99,   633,   565,   260,   106,   260,   247,
     675,   112,   517,   518,   621,   620,   676,   105,   621,   612,
     100,   308,   112,   148,   128,   186,   385,   272,   207,   208,
     206,   136,   309,   310,   112,   311,   312,   107,   128,   313,
     643,   206,   109,   309,   310,   115,   311,   312,   117,   118,
     313,   159,   120,   176,   182,   183,   184,   192,   193,   194,
     229,   122,   533,   145,   146,   147,   644,   132,   134,   159,
     135,   143,   197,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   260,   487,   176,   188,   148,   489,
     206,   189,   309,   310,   221,   311,   312,   159,   190,   313,
     192,   193,   194,   191,   206,   211,   386,   389,   212,   216,
     217,   228,   645,   646,   647,   233,   244,   250,   648,   649,
     650,   159,   651,   652,   251,   255,   243,   258,   245,   198,
     199,   200,   266,   201,   202,   203,   256,   265,   259,   124,
     259,   275,   532,   293,   294,   296,   299,   270,   662,   663,
     664,   665,   666,   273,   668,   303,   304,   305,  -282,   295,
     306,   534,   159,   246,   301,   368,   371,   343,   373,   374,
    -361,   611,   670,   380,   672,   397,   674,   427,   395,   417,
     414,   677,   396,   469,   342,   418,   420,   423,   422,   428,
     425,   473,   398,   426,   457,   366,   458,   459,   465,   399,
     400,   401,   402,   346,   347,   348,   349,   350,   351,   352,
     581,   463,   464,   376,   584,   301,   259,   466,   403,   128,
     128,   429,   467,   488,   507,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   356,   357,   358,   359,   360,   361,
     362,   486,   494,   398,   449,   450,   451,   500,   502,   472,
     399,   400,   401,   402,   404,   405,   406,   407,   408,   503,
     409,   410,   411,   511,   412,   413,   398,   508,   509,   403,
     510,   512,   159,   399,   400,   401,   402,   513,   514,   527,
     515,   516,   519,   520,   521,   539,   128,   540,   543,   531,
     544,   538,   403,   541,   128,   542,   562,   452,   453,   470,
     569,   570,   398,   578,   576,   571,   572,   573,   574,   399,
     400,   401,   402,   579,   585,   404,   405,   406,   407,   408,
     586,   409,   410,   411,   501,   412,   413,   128,   403,   598,
     610,   599,   507,   613,  -435,   615,   628,   630,   404,   405,
     406,   407,   408,   631,   409,   410,   411,   635,   412,   413,
     637,   629,   634,   653,   657,   654,   659,   524,   526,   667,
     669,   376,   376,   103,   215,   590,   140,   575,   595,   671,
     119,   577,   210,   530,   404,   405,   406,   407,   535,   416,
     409,   410,   411,   415,   412,   413,   529,   128,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   656,
     345,   271,   655,   497,   498,   421,   456,   232,   264,   230,
     567,   568,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   298,     0,     0,   474,     0,     0,
       0,     0,     0,   382,   287,   288,   289,   290,     0,     0,
       0,     0,     0,   587,     0,   128,   592,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,     0,
       0,     0,   594,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,     0,   626,   627,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   636,     0,   638,     0,     0,     0,     4,     5,
       6,     7,     8,     0,     0,     0,   324,     9,     0,     0,
      10,     0,    12,    13,     0,     0,   658,    14,    15,    16,
      17,     0,     0,   325,     0,    18,    19,   326,     0,     0,
       0,     0,     0,    20,     0,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,     0,     0,    51,    52,    53,
      54,    55,     0,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,     0,    75,     0,     0,    76,    77,     0,
     327,     0,     0,   328,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,    15,    16,    17,     0,
     387,     0,   329,    18,    19,     0,     0,     0,     0,     0,
       0,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     0,     0,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,     0,    75,     0,     0,    76,    77,     0,    78,     0,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,     0,
      12,    13,     0,     0,   388,    14,    15,    16,    17,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,     0,
       0,    20,     0,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     0,     0,    51,    52,    53,    54,    55,
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,     0,    75,     0,     0,    76,    77,     0,    78,     0,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   151,     0,     0,     4,     5,     6,
     152,     8,     0,   124,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,   468,     0,    14,    15,    16,    17,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,   153,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,    76,    77,     0,    78,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,   154,     0,     0,     0,     0,   151,
     155,   156,     4,     5,     6,   152,     8,     0,     0,   157,
     158,     9,     0,     0,    10,     0,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,     0,     0,    20,     0,    21,
      22,   153,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,     0,    75,     0,
       0,    76,    77,     0,    78,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   154,
       0,     0,   167,   168,     0,   155,   156,     4,     5,     6,
       7,     8,   169,     0,   157,   158,     9,     0,   214,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
     170,     0,   171,     0,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,   172,    72,
      73,    74,   173,    75,     0,     0,    76,    77,     0,    78,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,   167,   168,   174,   175,     0,
       4,     5,     6,     7,     8,   169,     0,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
      15,    16,    17,   170,     0,   171,     0,    18,    19,     0,
       0,     0,     0,     0,     0,    20,     0,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,    51,
      52,    53,    54,    55,     0,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,   172,    72,    73,    74,   173,    75,     0,     0,    76,
      77,     0,    78,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     0,     0,
     174,   175,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,   218,    12,    13,     0,     0,
       0,    14,    15,    16,    17,     0,     0,     0,     0,    18,
      19,     0,     0,   219,     0,     0,     0,    20,     0,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,    51,    52,    53,    54,    55,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,    72,    73,    74,     0,    75,     0,
       0,    76,    77,     0,    78,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     220,     4,     5,     6,     7,     8,     0,     0,     0,   324,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,    15,    16,    17,     0,     0,   325,     0,    18,    19,
       0,     0,     0,     0,     0,     0,    20,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,     0,
      51,    52,    53,    54,    55,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
      76,    77,     0,    78,     0,     0,   328,     0,     0,    79,
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
       0,    78,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
      11,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
       0,     0,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,    76,    77,     0,    78,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     4,     5,     6,     7,     8,
       0,   124,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,    18,    19,     0,     0,     0,     0,     0,     0,
      20,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,    52,    53,    54,    55,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
       0,    75,     0,     0,    76,    77,     0,    78,     0,     0,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,   375,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
      18,    19,     0,     0,     0,     0,     0,     0,    20,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,    51,    52,    53,    54,    55,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,    76,    77,     0,    78,     0,     0,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,    15,    16,    17,     0,     0,     0,     0,    18,    19,
       0,     0,   523,     0,     0,     0,    20,     0,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,     0,
      51,    52,    53,    54,    55,     0,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,    72,    73,    74,     0,    75,     0,     0,
      76,    77,     0,    78,     0,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,     0,    18,    19,     0,     0,
     525,     0,     0,     0,    20,     0,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,     0,    51,    52,
      53,    54,    55,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,    72,    73,    74,     0,    75,     0,     0,    76,    77,
       0,    78,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,    15,    16,    17,
       0,     0,     0,     0,    18,    19,     0,     0,   591,     0,
       0,     0,    20,     0,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,    51,    52,    53,    54,
      55,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,     0,    75,     0,     0,    76,    77,     0,    78,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,    15,    16,    17,     0,     0,
       0,     0,    18,    19,     0,     0,     0,     0,     0,     0,
      20,     0,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,    52,    53,    54,    55,     0,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    72,    73,    74,
       0,    75,     0,     0,    76,    77,     0,    78,     0,     0,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,    15,    16,    17,     0,     0,     0,     0,
      18,   589,     0,     0,     0,     0,     0,     0,    20,     0,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,    51,    52,    53,    54,    55,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,     0,    75,
       0,     0,    76,    77,     0,    78,     0,     0,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88
};

static const short yycheck[] =
{
       1,   115,   320,    14,   129,   323,    33,    16,    17,   142,
      44,    16,    17,    16,   488,   129,   255,   264,    46,   149,
       3,    16,    44,    76,    33,    44,    15,   160,    33,   274,
      33,     8,    37,    16,    17,   160,    15,   113,   619,   620,
      67,   128,   129,    10,    11,    28,    41,    42,   293,   125,
      33,    73,    31,    10,    11,    44,   186,    27,    41,    42,
     641,   642,    73,    30,    38,    38,   313,   306,    36,    38,
      44,    44,   106,   391,     0,    44,    44,   312,    25,   212,
     133,   134,   135,   136,   137,   138,   139,   106,    38,   107,
     108,   326,   327,    27,    44,    98,   229,    98,   231,   127,
      38,   102,    90,    91,   113,   110,    44,    28,   113,   583,
      33,    73,   113,    32,   115,    34,   143,   242,   157,   158,
     142,   122,   144,   145,   125,   147,   148,    28,   129,   151,
      32,   142,    12,   144,   145,     7,   147,   148,    29,    29,
     151,   142,    16,   144,   145,   146,   147,   133,   134,   135,
     136,    32,   470,    24,    25,    26,    58,     6,     9,   160,
      18,    16,    76,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   307,   410,   177,   105,    32,   414,
     142,    43,   144,   145,   185,   147,   148,   188,    33,   151,
     133,   134,   135,    37,   142,    34,   310,   311,   130,     3,
      24,    16,   104,   105,   106,   206,    26,    26,   110,   111,
     112,   212,   114,   115,    13,    26,   217,    44,   219,   133,
     134,   135,    34,   137,   138,   139,   227,    37,   229,    14,
     231,    26,   467,    29,   110,    16,    39,   238,   643,   644,
     645,   646,   647,   244,   649,    13,    37,    16,    26,   250,
      26,   486,   253,    46,   255,    28,    44,    37,   105,    16,
      37,   579,   667,    38,   669,    44,   671,    23,   136,    16,
      37,   676,    38,   387,   275,    37,    92,    37,    92,    35,
      26,   395,    32,    16,    15,   286,    26,    26,    33,    39,
      40,    41,    42,   116,   117,   118,   119,   120,   121,   122,
     535,    45,    92,   304,   539,   306,   307,    33,    58,   310,
     311,    67,    32,    37,   428,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   116,   117,   118,   119,   120,   121,
     122,    58,    16,    32,   100,   101,   102,    16,    15,    38,
      39,    40,    41,    42,   104,   105,   106,   107,   108,    12,
     110,   111,   112,    58,   114,   115,    32,    32,    32,    58,
      32,    58,   373,    39,    40,    41,    42,    32,    32,    93,
      32,    32,    32,    32,    44,    44,   387,    16,    32,    37,
      32,    38,    58,    38,   395,    38,    33,   153,   154,   149,
      33,    37,    32,    16,   123,    33,    33,    33,    33,    39,
      40,    41,    42,   150,    38,   104,   105,   106,   107,   108,
      16,   110,   111,   112,   425,   114,   115,   428,    58,    26,
      44,    26,   546,    26,    32,    26,    92,    16,   104,   105,
     106,   107,   108,    16,   110,   111,   112,    16,   114,   115,
      26,    92,    92,    17,    38,    33,    38,   458,   459,    58,
      37,   462,   463,    95,   177,   546,   129,   521,   560,   108,
     108,   528,   160,   463,   104,   105,   106,   107,   108,   340,
     110,   111,   112,   339,   114,   115,   462,   488,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   634,
     283,   239,   633,   420,   422,   362,   373,   204,   231,   195,
     511,   512,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,   253,    -1,    -1,   397,    -1,    -1,
      -1,    -1,    -1,   307,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,   544,    -1,   546,   547,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    -1,
      -1,    -1,   109,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     591,    -1,    -1,    -1,    -1,    -1,    -1,   598,   599,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   613,    -1,   615,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    16,    17,    -1,    -1,
      20,    -1,    22,    23,    -1,    -1,   637,    27,    28,    29,
      30,    -1,    -1,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    79,
      80,    81,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,   104,    -1,    -1,   107,   108,    -1,
     110,    -1,    -1,   113,    -1,    -1,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      32,    -1,   152,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,   107,   108,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      22,    23,    -1,    -1,   146,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    79,    80,    81,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,   104,    -1,    -1,   107,   108,    -1,   110,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,     5,    -1,    -1,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,   146,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,   107,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,     5,
     131,   132,     8,     9,    10,    11,    12,    -1,    -1,   140,
     141,    17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,   107,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,     3,     4,    -1,   131,   132,     8,     9,    10,
      11,    12,    13,    -1,   140,   141,    17,    -1,    19,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,   107,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     3,     4,   128,   129,    -1,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
     108,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,    -1,    -1,
     128,   129,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,   104,    -1,
      -1,   107,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     8,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    -1,    33,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,   104,    -1,    -1,
     107,   108,    -1,   110,    -1,    -1,   113,    -1,    -1,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,     8,
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
      -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      21,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,   107,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,   107,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,   104,
      -1,    -1,   107,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    78,    79,    80,    81,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,   104,    -1,    -1,
     107,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    78,
      79,    80,    81,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,   104,    -1,    -1,   107,   108,
      -1,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      81,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,   104,    -1,    -1,   107,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,   104,    -1,    -1,   107,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    79,    80,    81,    -1,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,   104,
      -1,    -1,   107,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,     8,   156,   157,     8,     9,    10,    11,    12,    17,
      20,    21,    22,    23,    27,    28,    29,    30,    35,    36,
      43,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    77,    78,    79,    80,    81,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   100,   101,   102,   104,   107,   108,   110,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   158,
     159,   284,     0,    10,    11,   160,   161,    27,    25,    27,
      33,   162,    30,   161,   178,    28,   158,    28,   163,    12,
     164,   168,   158,   179,   180,     7,   183,    29,    29,   164,
      16,   165,    32,   181,    14,    44,   169,   180,   158,   184,
     185,   225,     6,   207,     9,    18,   158,   182,   180,   169,
     185,   186,   208,    16,   166,    24,    25,    26,    32,   187,
     188,     5,    11,    47,   125,   131,   132,   140,   141,   158,
     209,   210,   211,   251,   254,   256,   272,     3,     4,    13,
      31,    33,    99,   103,   128,   129,   158,   170,   171,   172,
     173,   174,   158,   158,   158,   189,    34,   188,   105,    43,
      33,    37,   133,   134,   135,   266,   268,    76,   133,   134,
     135,   137,   138,   139,   267,   269,   142,   273,   273,   169,
     210,    34,   130,   175,    19,   172,     3,    24,    21,    39,
     126,   158,   194,   188,   252,   253,   254,   212,    16,   136,
     268,   136,   269,   158,   254,   128,   129,   176,   222,   223,
     224,   226,   167,   158,    26,   158,    46,   127,   192,   193,
      26,    13,   191,    44,   106,    26,   158,   216,    44,   158,
     254,   255,   270,   271,   270,    37,    34,   215,    15,    31,
     158,   224,   169,   158,   221,    26,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    94,    95,    96,
      97,   124,   228,    29,   110,   158,    16,   190,   253,    39,
     214,   158,   255,    13,    37,    16,    26,    44,    73,   144,
     145,   147,   148,   151,   257,   258,   260,   261,   262,   263,
     264,   265,   273,   264,    16,    33,    37,   110,   113,   152,
     158,   225,   274,   275,   276,   277,   280,   281,   282,   177,
     227,   192,   158,    37,   232,   232,   116,   117,   118,   119,
     120,   121,   122,   239,   240,   242,   116,   117,   118,   119,
     120,   121,   122,   233,   236,   237,   158,   192,    28,    15,
      44,    44,   201,   105,    16,    21,   158,   217,   219,   220,
      38,   255,   271,    33,    67,   143,   225,    32,   146,   225,
     277,   264,   257,   277,   277,   136,    38,    44,    32,    39,
      40,    41,    42,    58,   104,   105,   106,   107,   108,   110,
     111,   112,   114,   115,    37,   226,   222,    16,    37,   243,
      92,   243,    92,    37,   234,    26,    16,    23,    35,    67,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   100,
     101,   102,   153,   154,   202,   203,   252,    15,    26,    26,
      38,    44,   218,    45,    92,    33,    33,    32,   146,   225,
     149,    14,    38,   225,   276,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,    58,   277,    37,   277,
     278,   279,    38,    44,    16,   235,   241,   242,   237,   238,
      16,   158,    15,    12,   195,   196,   197,   225,    32,    32,
      32,    58,    58,    32,    32,    32,    32,    90,    91,    32,
      32,    44,   106,    39,   158,    39,   158,    93,   213,   220,
     219,    37,   277,   257,   277,   108,   282,   283,    38,    44,
      16,    38,    38,    32,    32,    36,    44,   200,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     205,   206,    33,    16,    33,    98,   204,   158,   158,    33,
      37,    33,    33,    33,    33,   203,   123,   215,    16,   150,
     259,   277,    38,    44,   277,    38,    16,   158,   198,    36,
     197,    39,   158,   199,   109,   206,   244,   245,    26,    26,
       3,    16,    17,    28,    33,    41,    42,   229,   230,   231,
      44,   257,   282,    26,   158,    26,    16,    17,    33,    37,
     110,   113,   246,   247,   248,   249,   158,   158,    92,    92,
      16,    16,    38,    44,    92,    16,   158,    26,   158,   247,
     247,   107,   108,    32,    58,   104,   105,   106,   110,   111,
     112,   114,   115,    17,    33,   231,   230,    38,   158,    38,
     247,   247,   248,   248,   248,   248,   248,    58,   248,    37,
     248,   108,   248,   250,   248,    38,    44,   248
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
    {
	strcpy(yyval.str,"0");
}
    break;

  case 140:
#line 664 "screen.yacc"
    {
	strcpy(yyval.str,"4");
}
    break;

  case 141:
#line 667 "screen.yacc"
    {
	strcpy(yyval.str,"2");
}
    break;

  case 142:
#line 670 "screen.yacc"
    {
	strcpy(yyval.str,"6"); 
}
    break;

  case 143:
#line 673 "screen.yacc"
    {
	strcpy(yyval.str,"1");
}
    break;

  case 144:
#line 676 "screen.yacc"
    {
	strcpy(yyval.str,"5"); 
}
    break;

  case 145:
#line 679 "screen.yacc"
    {
	strcpy(yyval.str,"7");
}
    break;

  case 146:
#line 682 "screen.yacc"
    {
	strcpy(yyval.str,"3");
}
    break;

  case 147:
#line 685 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE"));
}
    break;

  case 148:
#line 688 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT"));
}
    break;

  case 149:
#line 691 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK"));
}
    break;

  case 150:
#line 694 "screen.yacc"
    {
	sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE"));
}
    break;

  case 152:
#line 699 "screen.yacc"
    {
}
    break;

  case 158:
#line 709 "screen.yacc"
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

  case 159:
#line 719 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 171:
#line 736 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 172:
#line 739 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 173:
#line 755 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 174:
#line 758 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 177:
#line 768 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 178:
#line 770 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 179:
#line 772 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 180:
#line 774 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 181:
#line 776 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 183:
#line 780 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 184:
#line 784 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 185:
#line 790 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 186:
#line 790 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 189:
#line 797 "screen.yacc"
    {colno++;}
    break;

  case 190:
#line 798 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 191:
#line 811 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 192:
#line 819 "screen.yacc"
    {
	colno+=strlen(yyvsp[0].str);
}
    break;

  case 193:
#line 821 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-2].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 194:
#line 828 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 195:
#line 832 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 196:
#line 836 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 197:
#line 840 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 198:
#line 844 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 199:
#line 848 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 200:
#line 852 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 201:
#line 856 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 202:
#line 860 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 203:
#line 864 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 204:
#line 868 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 205:
#line 872 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 206:
#line 876 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 207:
#line 880 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 208:
#line 883 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 210:
#line 890 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 213:
#line 895 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 214:
#line 900 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 215:
#line 901 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 216:
#line 902 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 217:
#line 903 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 219:
#line 905 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 220:
#line 908 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 221:
#line 912 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 222:
#line 918 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 223:
#line 919 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 224:
#line 920 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 225:
#line 923 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 226:
#line 925 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 227:
#line 931 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 228:
#line 933 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 229:
#line 938 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 230:
#line 946 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 231:
#line 949 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 232:
#line 950 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 233:
#line 951 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 234:
#line 952 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 235:
#line 953 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 236:
#line 954 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 237:
#line 956 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 239:
#line 963 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 240:
#line 964 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 241:
#line 967 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 242:
#line 970 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 243:
#line 974 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 244:
#line 975 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 245:
#line 976 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 246:
#line 977 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 247:
#line 978 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 248:
#line 979 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 249:
#line 981 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 250:
#line 986 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 251:
#line 988 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 252:
#line 995 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 253:
#line 995 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 254:
#line 1001 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 256:
#line 1008 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 257:
#line 1011 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 258:
#line 1017 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 259:
#line 1018 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 260:
#line 1019 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 261:
#line 1020 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 262:
#line 1021 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 263:
#line 1022 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 264:
#line 1023 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 265:
#line 1024 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 266:
#line 1025 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 267:
#line 1026 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 268:
#line 1027 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 269:
#line 1028 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 270:
#line 1029 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 271:
#line 1032 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 272:
#line 1039 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); printf("NUMBER VALUE : %s\n",yyvsp[0].str); }
    break;

  case 273:
#line 1040 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 274:
#line 1041 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 276:
#line 1049 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 277:
#line 1053 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;

  case 336:
#line 1188 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 337:
#line 1191 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 342:
#line 1205 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 343:
#line 1206 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 344:
#line 1207 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 345:
#line 1208 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 346:
#line 1209 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 347:
#line 1210 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 348:
#line 1211 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 349:
#line 1212 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 350:
#line 1213 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 351:
#line 1214 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 352:
#line 1215 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 353:
#line 1216 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 354:
#line 1217 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 355:
#line 1218 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 356:
#line 1219 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 357:
#line 1220 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 358:
#line 1221 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 359:
#line 1222 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 360:
#line 1223 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 362:
#line 1229 "screen.yacc"
    { yyval.expr=create_field_expr(yyvsp[0].str); }
    break;

  case 363:
#line 1230 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); }
    break;

  case 364:
#line 1231 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 365:
#line 1232 "screen.yacc"
    { yyval.expr=create_special_expr(yyvsp[0].str); }
    break;

  case 366:
#line 1235 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 367:
#line 1239 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 991 of yacc.c.  */
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


#line 1336 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */





