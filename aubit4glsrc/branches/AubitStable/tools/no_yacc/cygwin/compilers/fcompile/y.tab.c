/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
     KW_ZEROFILL = 413,
     KW_USES_EXTENDED = 414,
     SPECIAL_DBNAME = 415
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
#define KW_USES_EXTENDED 414
#define SPECIAL_DBNAME 415




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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 77 "screen.yacc"
typedef union YYSTYPE {
	char	str[1024];
	u_expression *expr;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 483 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 495 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
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
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
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
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  95
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3090

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  131
/* YYNRULES -- Number of rules. */
#define YYNRULES  467
/* YYNRULES -- Number of states. */
#define YYNSTATES  702

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   415

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
     155,   156,   157,   158,   159,   160
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
     370,   374,   376,   381,   383,   385,   387,   389,   393,   397,
     399,   401,   403,   405,   407,   409,   411,   414,   417,   419,
     421,   423,   425,   428,   430,   432,   434,   436,   438,   440,
     442,   444,   446,   448,   450,   452,   454,   456,   458,   460,
     461,   462,   467,   469,   472,   474,   477,   480,   481,   491,
     504,   506,   508,   510,   511,   514,   515,   517,   518,   520,
     522,   527,   529,   533,   534,   536,   538,   542,   546,   550,
     554,   556,   560,   562,   564,   565,   567,   569,   572,   574,
     576,   578,   579,   584,   586,   588,   590,   592,   594,   596,
     599,   602,   605,   608,   610,   612,   614,   616,   618,   620,
     624,   626,   629,   632,   634,   636,   640,   644,   646,   648,
     652,   656,   660,   664,   666,   667,   671,   677,   678,   682,
     683,   687,   689,   692,   694,   696,   698,   700,   702,   704,
     707,   709,   710,   714,   716,   718,   720,   722,   724,   726,
     728,   730,   733,   734,   738,   739,   741,   744,   746,   750,
     754,   758,   762,   766,   770,   775,   779,   782,   785,   787,
     793,   799,   802,   806,   808,   810,   812,   814,   816,   818,
     822,   831,   833,   837,   841,   843,   845,   851,   857,   860,
     863,   865,   867,   869,   871,   873,   875,   877,   883,   884,
     887,   889,   894,   897,   901,   904,   908,   912,   914,   917,
     920,   924,   928,   930,   933,   935,   938,   940,   942,   944,
     946,   948,   950,   952,   954,   956,   958,   960,   964,   968,
     970,   975,   981,   982,   984,   986,   990,   992,   994,   998,
    1002,  1003,  1005,  1007,  1011,  1014,  1017,  1019,  1022,  1026,
    1031,  1035,  1039,  1043,  1047,  1051,  1055,  1059,  1063,  1067,
    1072,  1076,  1079,  1082,  1088,  1094,  1096,  1098,  1100,  1102,
    1104,  1106,  1108,  1112,  1114,  1116,  1118,  1120,  1122,  1124,
    1126,  1128,  1130,  1132,  1134,  1136,  1138,  1140,  1142,  1144,
    1146,  1148,  1150,  1152,  1154,  1156,  1158,  1160,  1162,  1164,
    1166,  1168,  1170,  1172,  1174,  1176,  1178,  1180,  1182,  1184,
    1186,  1188,  1190,  1192,  1194,  1196,  1198,  1200,  1202,  1204,
    1206,  1208,  1210,  1212,  1214,  1216,  1218,  1220,  1222,  1224,
    1226,  1228,  1230,  1232,  1234,  1236,  1238,  1240,  1242,  1244,
    1246,  1248,  1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,
    1266,  1268,  1270,  1272,  1274,  1276,  1278,  1280
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     162,     0,    -1,   163,   166,   185,   190,   214,    -1,     8,
      21,    -1,     8,   165,    27,    28,    29,    -1,     8,    21,
      27,    28,    29,    -1,     8,   165,    -1,    17,    -1,   291,
      -1,   160,    -1,   164,    -1,   164,    25,   164,    -1,   167,
      -1,   166,   167,    -1,    -1,    11,   168,   170,    -1,    -1,
      10,    33,   169,   170,    -1,    -1,    -1,    -1,   175,   171,
     174,    18,   172,   177,    19,   173,   176,    -1,    -1,   159,
      -1,    -1,    12,    16,    -1,    12,    16,     9,    16,    -1,
      -1,    14,    -1,   179,    -1,   177,   179,    -1,   164,    -1,
     178,    -1,   181,    -1,   133,    -1,     4,    -1,    31,    -1,
      33,    -1,   180,    -1,   132,    -1,   106,    -1,   102,    -1,
       3,    -1,   180,     3,    -1,    -1,    13,   182,   183,    15,
      -1,   233,    -1,    -1,   183,    31,   184,   233,    -1,    -1,
      30,   186,   176,    -1,   187,    -1,   186,   187,    -1,   186,
      44,   187,    -1,   164,   188,    -1,    -1,    32,   189,    -1,
     164,    -1,   164,    24,   164,    -1,   164,    25,   164,    -1,
     164,    25,   164,    24,   164,    -1,   164,    26,   164,    -1,
      33,    26,   164,    -1,     7,   191,   176,    -1,   192,    -1,
     191,   192,    -1,    -1,   232,   193,   194,    34,    -1,   195,
      -1,   194,   195,    -1,   194,    34,   195,    -1,    -1,    -1,
      32,   196,   201,   198,   197,   208,    -1,    -1,    13,    16,
      15,    -1,    13,    16,    44,    16,    15,    -1,   200,   114,
      28,    -1,   200,    -1,    -1,    46,    58,   164,    26,   164,
      -1,    46,    58,   164,    -1,    46,   235,    -1,    21,    26,
     228,   199,    -1,   130,   199,    -1,   130,   131,    29,   199,
      -1,   164,    26,   164,    -1,   164,    -1,    39,   164,    26,
     164,    -1,    39,   164,    -1,   232,    -1,   204,    -1,   203,
      44,   204,    -1,   202,    32,   205,    -1,   164,    26,   164,
      -1,   164,    -1,   164,    26,   164,    -1,   164,    -1,    39,
     164,    26,   164,    -1,    39,   164,    -1,    36,    -1,    44,
      36,    -1,    -1,    44,   209,    -1,   210,    -1,   209,    44,
     210,    -1,    74,    -1,    75,    32,   212,   251,    -1,    35,
     203,   207,   206,    -1,    76,    32,    33,    -1,    77,    32,
     211,    -1,    79,    58,   164,    -1,    79,    58,   164,    26,
     164,    -1,    78,    58,   164,    -1,    78,    58,   164,    26,
     164,    -1,    80,    -1,    81,    -1,    82,    32,    33,    -1,
      83,    32,    37,   236,    38,    -1,   104,    32,    33,    -1,
     105,    32,    33,    -1,    84,    -1,    23,    12,    32,    16,
      -1,    23,    -1,   103,    -1,    86,    -1,    85,    -1,    87,
      32,    33,    -1,    88,    32,    33,    -1,    89,    -1,    68,
      -1,    91,    -1,    90,    -1,   158,    -1,   157,    -1,    92,
      -1,    92,    93,    -1,    92,    94,    -1,    33,    -1,    16,
      -1,   101,    -1,   213,    -1,   212,   213,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    16,    -1,    68,    -1,    73,    -1,
      67,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      -1,    -1,     6,   215,   216,   176,    -1,   217,    -1,   216,
     217,    -1,   218,    -1,   218,    34,    -1,    47,    33,    -1,
      -1,    11,    43,   219,   223,    37,   224,    38,   220,   222,
      -1,   129,    37,    16,    44,    16,    38,    95,    37,    16,
      44,    16,    38,    -1,   258,    -1,   279,    -1,   263,    -1,
      -1,    96,   127,    -1,    -1,    39,    -1,    -1,    34,    -1,
     164,    -1,   164,    13,    16,    15,    -1,   227,    -1,   224,
     225,   227,    -1,    -1,    44,    -1,   164,    -1,   164,    26,
     164,    -1,    21,    26,   164,    -1,   164,    26,    39,    -1,
      21,    26,    39,    -1,   226,    -1,   226,    45,   226,    -1,
     164,    -1,    14,    -1,    -1,   230,    -1,   231,    -1,   230,
     231,    -1,   132,    -1,   133,    -1,   164,    -1,    -1,   229,
     164,   234,   229,    -1,    48,    -1,    49,    -1,    50,    -1,
      51,    -1,    52,    -1,    53,    -1,    54,   239,    -1,    55,
     239,    -1,    56,   246,    -1,    57,   240,    -1,    97,    -1,
      98,    -1,    99,    -1,   100,    -1,   128,    -1,   238,    -1,
     236,    44,   238,    -1,    16,    -1,    41,    16,    -1,    42,
      16,    -1,    33,    -1,    17,    -1,    17,    95,    17,    -1,
      17,    24,    17,    -1,     3,    -1,   237,    -1,   237,    95,
     237,    -1,   237,    24,   237,    -1,    33,    95,    33,    -1,
      33,    24,    33,    -1,    28,    -1,    -1,    37,    16,    38,
      -1,    37,    16,    44,    16,    38,    -1,    -1,   243,    95,
     245,    -1,    -1,    37,    16,    38,    -1,    16,    -1,   244,
     241,    -1,   120,    -1,   121,    -1,   122,    -1,   123,    -1,
     124,    -1,   125,    -1,   126,   250,    -1,   244,    -1,    -1,
     247,    95,   248,    -1,   249,    -1,   249,    -1,   120,    -1,
     121,    -1,   122,    -1,   123,    -1,   124,    -1,   125,    -1,
     126,   250,    -1,    -1,    37,   242,    38,    -1,    -1,   252,
      -1,   113,   253,    -1,   254,    -1,   254,   111,   254,    -1,
     254,   110,   254,    -1,   255,   107,   255,    -1,   255,   108,
     255,    -1,   255,   109,   255,    -1,   255,    58,   255,    -1,
     255,   114,    58,   255,    -1,   255,    32,   255,    -1,   255,
     118,    -1,   255,   119,    -1,   255,    -1,   255,   115,   255,
     111,   255,    -1,   255,   116,    37,   257,    38,    -1,   114,
     254,    -1,    37,   254,    38,    -1,   256,    -1,    16,    -1,
      33,    -1,   117,    -1,    17,    -1,   255,    -1,   257,    44,
     255,    -1,     5,   108,   259,   109,   221,   108,   259,   109,
      -1,   260,    -1,   259,    44,   260,    -1,   261,    26,   262,
      -1,   164,    -1,   164,    -1,   135,   273,   140,   277,   271,
      -1,   136,   274,   140,   277,   271,    -1,   145,   280,    -1,
     144,   280,    -1,   267,    -1,   272,    -1,   265,    -1,   268,
      -1,   269,    -1,   280,    -1,   270,    -1,   152,   284,   153,
     264,   266,    -1,    -1,   154,   264,    -1,   148,    -1,   149,
     232,    32,   284,    -1,   151,   232,    -1,   151,    32,   232,
      -1,   151,   150,    -1,   151,    32,   150,    -1,   155,   271,
      14,    -1,   264,    -1,   271,   264,    -1,    76,    33,    -1,
      76,   147,    33,    -1,    76,    68,    33,    -1,   275,    -1,
     273,   275,    -1,   276,    -1,   274,   276,    -1,   137,    -1,
     138,    -1,   139,    -1,   137,    -1,   141,    -1,   142,    -1,
     143,    -1,   139,    -1,    79,    -1,   138,    -1,   278,    -1,
     277,    44,   278,    -1,   261,    26,   262,    -1,   262,    -1,
     261,   134,   261,   222,    -1,   146,   164,    37,   281,    38,
      -1,    -1,   282,    -1,   283,    -1,   282,    44,   283,    -1,
     284,    -1,   287,    -1,   284,   111,   284,    -1,   284,   110,
     284,    -1,    -1,   286,    -1,   284,    -1,   286,    44,   284,
      -1,    42,   284,    -1,    41,   284,    -1,   289,    -1,   114,
     284,    -1,    37,   284,    38,    -1,   288,    37,   285,    38,
      -1,   156,   140,   232,    -1,   284,   107,   284,    -1,   284,
     108,   284,    -1,   284,   109,   284,    -1,   284,    39,   284,
      -1,   284,    41,   284,    -1,   284,    42,   284,    -1,   284,
      40,   284,    -1,   284,    58,   284,    -1,   284,   114,    58,
     284,    -1,   284,    32,   284,    -1,   284,   118,    -1,   284,
     119,    -1,   284,   115,   284,   111,   284,    -1,   284,   116,
      37,   290,    38,    -1,   164,    -1,   232,    -1,    16,    -1,
      33,    -1,   117,    -1,    28,    -1,   289,    -1,   290,    44,
     289,    -1,    96,    -1,    74,    -1,    59,    -1,    71,    -1,
      70,    -1,    60,    -1,   110,    -1,   111,    -1,   107,    -1,
     128,    -1,     9,    -1,    75,    -1,    22,    -1,    76,    -1,
      93,    -1,   105,    -1,    62,    -1,     8,    -1,    56,    -1,
      77,    -1,    47,    -1,    80,    -1,    23,    -1,    82,    -1,
      61,    -1,    83,    -1,    29,    -1,    57,    -1,    84,    -1,
      98,    -1,    48,    -1,    50,    -1,    54,    -1,    51,    -1,
      49,    -1,   129,    -1,    11,    -1,    10,    -1,    12,    -1,
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
static const unsigned short int yyrline[] =
{
       0,   114,   114,   117,   118,   123,   124,   132,   133,   137,
     137,   137,   140,   140,   143,   143,   156,   156,   175,   177,
     180,   175,   185,   185,   190,   191,   192,   204,   205,   210,
     211,   214,   229,   239,   240,   251,   263,   276,   286,   295,
     300,   303,   311,   312,   318,   317,   339,   342,   342,   360,
     361,   364,   365,   366,   369,   376,   377,   380,   381,   382,
     384,   385,   386,   392,   396,   396,   400,   400,   410,   411,
     412,   416,   420,   416,   457,   458,   462,   470,   471,   474,
     475,   478,   481,   486,   495,   507,   519,   528,   536,   544,
     554,   558,   559,   562,   565,   566,   570,   571,   572,   573,
     576,   577,   581,   582,   586,   586,   589,   590,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   626,   627,   628,   629,   630,   631,   632,
     635,   638,   639,   640,   641,   642,   645,   649,   655,   656,
     657,   661,   662,   666,   667,   668,   669,   670,   671,   672,
     673,   675,   689,   690,   691,   692,   693,   694,   695,   699,
     700,   700,   705,   705,   707,   707,   710,   720,   720,   723,
     724,   725,   726,   730,   730,   732,   732,   734,   734,   737,
     740,   756,   759,   763,   764,   768,   770,   772,   774,   776,
     781,   781,   785,   788,   792,   792,   795,   795,   799,   800,
     813,   821,   821,   830,   834,   838,   842,   846,   850,   854,
     858,   862,   866,   870,   874,   878,   882,   885,   892,   892,
     897,   897,   897,   902,   903,   904,   905,   906,   907,   908,
     909,   910,   914,   918,   924,   925,   926,   929,   930,   937,
     939,   944,   952,   955,   956,   957,   958,   959,   960,   961,
     967,   969,   970,   973,   976,   980,   981,   982,   983,   984,
     985,   986,   992,   994,  1001,  1001,  1007,  1013,  1014,  1017,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1038,  1045,  1046,  1047,  1052,  1055,  1059,
    1071,  1074,  1075,  1078,  1081,  1084,  1088,  1089,  1090,  1091,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1106,  1110,  1110,
    1113,  1116,  1119,  1120,  1121,  1122,  1126,  1129,  1130,  1135,
    1136,  1137,  1142,  1142,  1146,  1146,  1150,  1151,  1152,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,  1165,  1166,  1170,  1171,
    1175,  1178,  1181,  1181,  1185,  1185,  1188,  1193,  1194,  1195,
    1200,  1201,  1204,  1205,  1209,  1211,  1212,  1213,  1214,  1215,
    1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,
    1226,  1227,  1228,  1229,  1230,  1233,  1236,  1237,  1238,  1239,
    1240,  1243,  1247,  1259,  1260,  1261,  1262,  1263,  1264,  1265,
    1266,  1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,
    1286,  1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,
    1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,  1338,  1339,  1340,  1341,  1342,  1343
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
  "SPECIAL_DBNAME", "$accept", "form_def", "database_section",
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
     415
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   161,   162,   163,   163,   163,   163,   164,   164,   165,
     165,   165,   166,   166,   168,   167,   169,   167,   171,   172,
     173,   170,   174,   174,   175,   175,   175,   176,   176,   177,
     177,   178,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   180,   180,   182,   181,   183,   184,   183,   185,
     185,   186,   186,   186,   187,   188,   188,   189,   189,   189,
     189,   189,   189,   190,   191,   191,   193,   192,   194,   194,
     194,   196,   197,   195,   198,   198,   198,   199,   199,   200,
     200,   200,   200,   201,   201,   201,   201,   201,   201,   201,
     202,   203,   203,   204,   205,   205,   206,   206,   206,   206,
     207,   207,   208,   208,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   211,   211,
     211,   212,   212,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   214,
     215,   214,   216,   216,   217,   217,   218,   219,   218,   218,
     218,   218,   218,   220,   220,   221,   221,   222,   222,   223,
     223,   224,   224,   225,   225,   226,   226,   226,   226,   226,
     227,   227,   228,   228,   229,   229,   230,   230,   231,   231,
     232,   234,   233,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   236,
     237,   237,   237,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   239,   239,   239,   240,   240,   241,
     241,   242,   243,   244,   244,   244,   244,   244,   244,   244,
     245,   246,   246,   247,   248,   249,   249,   249,   249,   249,
     249,   249,   250,   250,   251,   251,   252,   253,   253,   253,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   255,   255,   255,   255,   256,   257,   257,
     258,   259,   259,   260,   261,   262,   263,   263,   263,   263,
     264,   264,   264,   264,   264,   264,   264,   265,   266,   266,
     267,   268,   269,   269,   269,   269,   270,   271,   271,   272,
     272,   272,   273,   273,   274,   274,   275,   275,   275,   276,
     276,   276,   276,   276,   276,   276,   277,   277,   278,   278,
     279,   280,   281,   281,   282,   282,   283,   284,   284,   284,
     285,   285,   286,   286,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   288,   289,   289,   289,   289,
     289,   290,   290,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291
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
       3,     1,     4,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     4,     1,     2,     1,     2,     2,     0,     9,    12,
       1,     1,     1,     0,     2,     0,     1,     0,     1,     1,
       4,     1,     3,     0,     1,     1,     3,     3,     3,     3,
       1,     3,     1,     1,     0,     1,     1,     2,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     1,     3,     3,     1,     1,     3,
       3,     3,     3,     1,     0,     3,     5,     0,     3,     0,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     0,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     4,     3,     2,     2,     1,     5,
       5,     2,     3,     1,     1,     1,     1,     1,     1,     3,
       8,     1,     3,     3,     1,     1,     5,     5,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     5,     0,     2,
       1,     4,     2,     3,     2,     3,     3,     1,     2,     2,
       3,     3,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       4,     5,     0,     1,     1,     3,     1,     1,     3,     3,
       0,     1,     1,     3,     2,     2,     1,     2,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     2,     2,     5,     5,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
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
static const unsigned short int yydefact[] =
{
       0,     0,     0,     0,   400,   393,   420,   419,   421,     7,
     445,     3,   395,   405,   455,   409,   443,   451,   452,   432,
     444,   459,   403,   413,   417,   414,   416,   439,   440,   415,
     426,   401,   410,   460,   385,   388,   407,   399,   433,   425,
     453,   458,   437,   435,   423,   387,   386,   447,   436,   384,
     394,   396,   402,   404,   448,   406,   408,   411,   427,   430,
     431,   434,   457,   450,   456,   397,   428,   446,   383,   438,
     412,   422,   449,   442,   441,   454,   398,   391,   389,   390,
     429,   461,   462,   463,   464,   465,   466,   467,   424,   392,
     418,     9,    10,     6,     8,     1,     0,    14,    49,    12,
       0,     0,     0,    16,    24,     0,    13,     0,     0,    11,
       0,    24,     0,    15,    18,    55,    27,    51,     0,   159,
       5,     4,    17,    25,    22,     0,    54,    28,     0,    50,
      52,   200,    27,    64,    66,   160,     2,     0,    23,     0,
       0,    57,    56,    53,    63,    65,     0,     0,    26,    19,
       0,     0,     0,     0,    71,     0,    68,     0,   419,   403,
     418,     0,     0,     0,     0,   294,    27,   162,   164,   170,
       0,   172,   171,     0,    62,    58,    59,    61,     0,    67,
      69,     0,   167,   166,     0,   326,   327,   328,     0,   322,
     334,   329,   335,   333,   330,   331,   332,     0,   324,     0,
     299,   298,   161,   163,   165,     0,    42,    35,    44,    36,
      37,    41,    40,    39,    34,    31,     0,    32,    29,    38,
      33,     0,     0,     0,    79,    87,    74,    70,     0,   291,
       0,     0,     0,     0,   323,     0,   325,     0,   177,   194,
      20,    30,    43,    60,     0,    89,     0,     0,    84,    78,
       0,     0,    72,     0,   175,     0,   179,     0,     0,   295,
       0,   339,     0,   336,     0,   342,   178,   340,   198,   199,
       0,     0,   195,   196,    46,    27,   193,   192,    79,     0,
     203,   204,   205,   206,   207,   208,   234,   234,   251,   237,
       0,   213,   214,   215,   216,   217,    82,    79,     0,    86,
       0,   102,   292,   176,     0,   295,   293,     0,     0,     0,
       0,     0,     0,   310,     0,     0,     0,     0,   317,   302,
     300,   303,   304,   306,   296,   301,   305,   297,   377,   380,
     378,     0,     0,     0,   429,   379,     0,   200,   376,     0,
     343,   344,   346,   347,     0,   356,    45,    47,   201,   197,
      21,    83,    88,     0,   209,   210,   255,   256,   257,   258,
     259,   260,   262,   211,     0,   253,   243,   244,   245,   246,
     247,   248,   262,   212,     0,   239,    81,    85,    77,    75,
       0,     0,    73,     0,     0,     0,   185,   183,   190,   181,
       0,   338,   337,   319,     0,     0,     0,     0,   314,   312,
       0,     0,   318,     0,   355,   354,   357,     0,   341,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   371,   372,   350,   194,   194,     0,
       0,   261,     0,   249,     0,     0,   242,     0,     0,   123,
       0,   130,   106,     0,     0,     0,     0,     0,   115,   116,
       0,     0,   121,   126,   125,     0,     0,   129,   132,   131,
     135,   124,     0,     0,   134,   133,   103,   104,     0,   180,
       0,     0,   173,   184,     0,     0,     0,   321,   320,     0,
     315,   313,     0,   316,   358,   360,   345,   370,   364,   367,
     365,   366,   368,   361,   362,   363,   349,   348,     0,     0,
       0,   352,     0,   351,    48,   202,   235,     0,   241,     0,
     252,   254,   250,   238,     0,    80,    76,     0,     0,     0,
      91,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   136,   137,     0,     0,     0,   290,   189,   187,   188,
     186,     0,   177,   182,   191,     0,   311,   308,   369,     0,
     381,     0,   359,     0,     0,   263,   240,     0,     0,   100,
       0,     0,   151,   143,   144,   145,   146,   147,   148,   149,
     150,   154,   152,   155,   156,   157,   158,   153,   264,   141,
     109,   139,   138,   140,   110,   113,   111,   117,     0,   127,
     128,   119,   120,   105,   174,   168,     0,     0,   307,   373,
     374,     0,   353,   236,   122,    95,    93,   101,    92,     0,
      97,   108,     0,   142,   107,   265,     0,     0,   227,   220,
     224,   233,   223,     0,     0,     0,   228,   218,     0,   309,
     382,     0,    99,     0,   284,   287,   285,     0,     0,   286,
     266,   267,   278,   283,   114,   112,     0,     0,     0,     0,
     221,   222,   118,     0,     0,     0,     0,    94,     0,    96,
       0,   281,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,   277,   226,   225,   232,   231,   219,   230,
     229,   169,    98,   282,   269,   268,   275,   273,   270,   271,
     272,     0,     0,     0,   274,     0,   288,     0,   279,   280,
       0,   289
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     3,   337,    93,    98,    99,   104,   111,   113,
     124,   173,   275,   139,   114,   129,   216,   217,   218,   219,
     220,   239,   270,   427,   107,   116,   117,   126,   142,   119,
     132,   133,   146,   155,   156,   178,   301,   252,   248,   249,
     226,   518,   519,   520,   606,   611,   561,   382,   466,   467,
     584,   578,   579,   136,   147,   166,   167,   168,   231,   542,
     304,   267,   257,   387,   474,   388,   389,   278,   271,   272,
     273,   338,   274,   428,   296,   625,   626,   627,   354,   373,
     436,   509,   374,   375,   513,   363,   364,   510,   365,   431,
     614,   615,   640,   641,   642,   643,   697,   169,   228,   229,
     230,   261,   171,   318,   319,   598,   320,   321,   322,   323,
     324,   325,   188,   197,   189,   198,   262,   263,   172,   326,
     339,   340,   341,   342,   502,   503,   343,   344,   345,   551,
      94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -605
static const short int yypact[] =
{
      29,   616,    50,    82,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,    37,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,    59,    91,  -605,  -605,    64,  -605,    33,  -605,
      92,  2839,    95,  -605,   120,  2839,  -605,   135,   116,  -605,
     127,   120,   160,  -605,  -605,   146,  1863,  -605,  2839,   173,
    -605,  -605,  -605,   172,    51,  1985,  -605,  -605,  2839,  -605,
    -605,  -605,  2107,  -605,  -605,  -605,  -605,   181,  -605,   193,
     187,   104,  -605,  -605,  -605,  -605,   175,  1236,  -605,  -605,
    2839,  2839,  2839,  2839,  -605,    48,  -605,   106,   174,   183,
     182,   100,    32,    77,    77,  -605,  1107,  -605,   195,  -605,
      87,  -605,  -605,  1492,  -605,  -605,   207,  -605,  1618,   175,
    -605,  2839,  -605,  -605,   217,  -605,  -605,  -605,    -3,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,   189,  -605,  2839,
    -605,  -605,  -605,  -605,  -605,  2839,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  1365,  -605,  -605,   232,
    -605,  2839,   214,  2839,   -33,   215,   233,  -605,   -28,  -605,
     219,  2839,   203,  2839,  -605,  2839,  -605,   211,   216,    21,
    -605,  -605,  -605,  -605,  2229,   225,   452,   224,  -605,   142,
    2839,   239,  -605,  2839,   230,  2839,   258,   235,   257,   249,
     250,  -605,     9,  -605,     9,   738,  -605,  -605,  -605,  -605,
      36,  2839,    21,  -605,  -605,   263,  -605,  -605,   234,  2839,
    -605,  -605,  -605,  -605,  -605,  -605,   242,   242,   -51,   141,
    2839,  -605,  -605,  -605,  -605,  -605,  -605,   234,   253,  -605,
      10,   240,  -605,  -605,   177,  -605,  -605,   267,  2351,   248,
    2839,  2839,   -26,  -605,  2839,   860,   738,    57,  -605,  -605,
    -605,  -605,  -605,  -605,    57,  -605,  -605,    57,  -605,  -605,
    -605,   738,   738,   738,   738,  -605,   147,   251,  -605,   252,
     247,  -605,   422,  -605,   261,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,   287,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,   262,  -605,   213,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,   262,  -605,   220,   274,   286,  -605,  -605,  -605,
     300,   283,  -605,  2839,   302,   293,   294,    11,   276,  -605,
     227,  -605,  -605,  -605,   290,   291,   301,   982,  -605,  -605,
     375,    -8,  -605,   186,   422,   422,   422,  2839,  -605,   738,
     738,   738,   738,   738,   738,   738,   738,   738,   738,   738,
     738,   277,   738,   297,  -605,  -605,   738,    21,    21,    39,
     331,  -605,   -51,  -605,   141,   333,  -605,  2839,   335,   341,
    2839,  -605,  -605,   322,   323,   324,   318,   319,  -605,  -605,
     346,   347,  -605,  -605,  -605,   348,   349,  -605,  -605,  -605,
      69,  -605,   351,   352,  -605,  -605,   345,  -605,   -22,  -605,
    2473,  2595,   289,  -605,  2351,  2351,   353,  -605,  -605,   738,
    -605,  -605,    57,  -605,  -605,  -605,  -605,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   738,   456,
    1741,   422,   360,   355,  -605,  -605,  -605,   384,  -605,   363,
    -605,  -605,  -605,  -605,   364,  -605,  -605,   371,   372,     2,
    -605,  -605,   523,   376,    -2,  2839,  2839,   377,   374,   379,
     380,  -605,  -605,   386,   388,   283,  -605,  -605,  -605,  -605,
    -605,   281,   216,  -605,  -605,   407,   422,   271,   422,   738,
    -605,    70,  -605,   738,   390,  -605,  -605,   410,  2839,  -605,
    2961,  2717,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,   123,  -605,
    -605,  -605,  -605,  -605,  -605,   403,   404,  -605,    24,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,   387,    57,  -605,   422,
    -605,  1741,   422,  -605,  -605,   406,  -605,   402,  -605,  2839,
     409,  -605,    -7,  -605,  -605,  -605,  2839,  2839,  -605,  -605,
      -9,  -605,    -6,   421,   426,    75,    -4,  -605,   427,  -605,
    -605,  2839,   412,  2839,  -605,  -605,  -605,    -7,    -7,  -605,
    -605,    15,   -13,  -605,  -605,  -605,   429,   430,   411,   415,
    -605,  -605,  -605,    24,    20,    20,   413,  -605,  2839,  -605,
     414,  -605,    -7,    -7,    -5,    -5,    -5,    -5,    -5,   391,
      -5,   416,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,  -605,
    -605,    -5,   339,    -5,  -605,    -5,  -605,    78,  -605,  -605,
      -5,  -605
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -605,  -605,  -605,    -1,  -605,  -605,   357,  -605,  -605,   354,
    -605,  -605,  -605,  -605,  -605,  -127,  -605,  -605,   241,  -605,
    -605,  -605,  -605,  -605,  -605,  -605,   -81,  -605,  -605,  -605,
    -605,   326,  -605,  -605,  -123,  -605,  -605,  -605,  -249,  -605,
    -605,  -605,  -605,  -104,  -605,  -605,  -605,  -605,  -605,   -76,
    -605,  -605,  -118,  -605,  -605,  -605,   305,  -605,  -605,  -605,
    -605,   -75,  -605,  -605,  -605,     1,     3,  -605,    40,  -605,
     194,  -115,    45,  -605,  -605,  -605,  -487,  -175,   200,  -605,
    -605,  -605,  -605,    47,  -605,  -605,  -605,  -605,    60,   139,
    -605,  -605,  -605,  -604,  -273,  -605,  -605,  -605,   129,   260,
    -145,  -231,  -605,  -323,  -605,  -605,  -605,  -605,  -605,  -605,
    -241,  -605,  -605,  -605,   327,   320,   284,   205,  -605,    38,
    -605,  -605,   109,   -74,  -605,  -605,  -605,  -605,  -492,  -605,
    -605
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -453
static const short int yytable[] =
{
      92,   402,   170,   134,   402,   144,   483,   393,   550,   634,
     635,   634,   635,   246,   581,   646,   253,   134,   648,   664,
     654,   170,   253,   327,   306,   379,   636,   618,   636,   351,
     637,   582,   180,   660,   661,   130,   619,     1,   559,   202,
     619,   620,   394,    96,    97,   665,   560,   143,   377,   472,
      95,   346,   621,   311,   380,   473,   227,   622,   684,   685,
     238,   623,   624,   105,   100,   623,   624,   347,   312,   356,
     357,   358,   359,   360,   361,   362,   401,   506,   402,   391,
     154,   254,   179,   507,   101,   312,   647,   536,   260,   649,
     260,   655,    96,    97,   666,   667,   668,   103,   247,   583,
     109,   669,   670,   671,   115,   672,   673,   638,   600,   630,
     639,   190,   639,   652,   601,   115,   699,   131,   102,   653,
     108,   395,   700,   110,   141,   662,   663,   115,   151,   152,
     153,   131,   112,   312,   185,   186,   187,   233,   199,   562,
     313,   314,   118,   315,   316,   120,   165,   317,   350,   174,
     175,   176,   177,   268,   269,   199,   121,   313,   314,   547,
     315,   316,   531,   532,   317,   165,   260,   679,   680,   191,
     192,   193,   215,   194,   195,   196,   123,   225,   125,   135,
     165,   137,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   148,   237,   396,
     399,   200,   201,   199,   165,   313,   314,   154,   315,   316,
     138,   149,   317,   150,   181,   215,   183,   182,   410,   184,
     243,   205,   245,   199,   484,   411,   412,   413,   414,   204,
     256,   221,   259,   232,   259,   242,   612,   185,   186,   187,
     244,   250,   400,   277,   415,   255,   251,   258,   265,   299,
     266,   279,   165,   297,   305,   300,   298,   403,   404,   405,
     406,   366,   367,   368,   369,   370,   371,   372,   190,   303,
     348,   307,   308,   309,   629,  -294,   310,   127,   352,   353,
     246,   378,   481,   384,   381,   383,   390,   407,  -375,   376,
     408,   409,   485,   416,   417,   418,   419,   420,   426,   430,
     421,   422,   423,   429,   424,   425,   439,   386,   432,   305,
     259,   435,   437,   131,   131,   434,   438,   469,   440,   470,
     471,   475,   476,   477,   478,   521,   191,   192,   193,   235,
     194,   195,   196,   479,   500,   498,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   508,   499,   514,
     516,   441,   501,   517,   522,   523,   524,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   525,   526,   527,   528,
     529,   530,   165,   533,   534,   541,   461,   462,   463,   535,
     545,   686,   687,   688,   689,   690,   131,   692,   552,   553,
     554,   555,   556,   557,   558,   546,   131,   410,   594,   580,
     587,   588,   589,   590,   411,   412,   413,   414,   694,   591,
     696,   592,   698,   596,   548,   597,   604,   701,   603,   616,
     617,   628,   631,   415,  -452,   633,   515,   650,   658,   131,
     464,   465,   651,   656,   676,   521,   674,   675,   677,   691,
     695,   681,   683,   693,   410,   106,   608,   241,   145,   593,
     613,   411,   412,   413,   414,   122,   349,   595,   505,   538,
     540,   203,   504,   386,   386,   599,   544,   543,   678,   602,
     415,   512,   416,   417,   418,   419,   420,   355,   410,   421,
     422,   423,   511,   424,   425,   411,   412,   413,   414,   131,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   433,   468,   302,   415,   234,   392,   236,   486,   264,
       0,     0,     0,     0,   585,   586,     0,     0,   482,   416,
     417,   418,   419,   420,     0,     0,   421,   422,   423,   562,
     424,   425,     0,     0,     0,     0,     0,     0,     0,   291,
     292,   293,   294,     0,     0,     0,     0,   605,     0,   131,
     610,     0,     0,   416,   417,   418,   419,   549,     0,     0,
     421,   422,   423,     0,   424,   425,     0,     0,     0,     0,
     295,     0,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,     0,   632,     0,
       0,     0,     0,     0,     0,   644,   645,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     0,
     657,     0,   659,     9,     0,     0,    10,    11,    12,    13,
       0,     0,     0,    14,     0,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,   682,     0,    19,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,    77,     0,     0,    78,    79,     0,     0,
      80,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     4,     5,     6,     7,
       8,     0,     0,     0,   328,     9,     0,     0,    10,     0,
      12,    13,     0,     0,     0,    14,   329,    15,    16,     0,
       0,   330,     0,    17,    18,   331,    91,     0,     0,   332,
     333,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,    77,     0,     0,    78,    79,
       0,     0,   334,     0,     0,   335,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,     0,
      10,     0,    12,    13,     0,     0,     0,    14,     0,    15,
      16,     0,   397,     0,   336,    17,    18,     0,     0,     0,
       0,     0,     0,    19,     0,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,    77,     0,     0,
      78,    79,     0,     0,    80,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
     398,    15,    16,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,     0,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,    77,
       0,     0,    78,    79,     0,     0,    80,     0,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,   157,     0,     0,     4,     5,     6,   158,     8,
       0,   127,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,   480,     0,    14,     0,    15,    16,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,   159,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,   160,     0,     0,     0,
       0,   157,   161,   162,     4,     5,     6,   158,     8,     0,
       0,   163,   164,     9,     0,     0,    10,     0,    12,    13,
       0,     0,     0,    14,     0,    15,    16,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,     0,    19,
       0,    20,    21,   159,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,    77,     0,     0,    78,    79,     0,     0,
      80,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   160,     0,     0,   206,   207,
       0,   161,   162,     4,     5,     6,     7,     8,   208,     0,
     163,   164,     9,     0,   240,    10,     0,    12,    13,     0,
       0,     0,    14,     0,    15,    16,   209,     0,   210,     0,
      17,    18,     0,     0,     0,     0,     0,     0,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,   211,    74,    75,
      76,   212,    77,     0,     0,    78,    79,     0,     0,    80,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,   206,   207,   213,   214,     0,
       4,     5,     6,     7,     8,   208,     0,     0,     0,     9,
       0,     0,    10,     0,    12,    13,     0,     0,     0,    14,
       0,    15,    16,   209,     0,   210,     0,    17,    18,     0,
       0,     0,     0,     0,     0,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,    53,    54,    55,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,   211,    74,    75,    76,   212,    77,
       0,     0,    78,    79,     0,     0,    80,     0,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,   213,   214,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     9,     0,     0,    10,   222,
      12,    13,     0,     0,     0,    14,     0,    15,    16,     0,
       0,     0,     0,    17,    18,     0,     0,   223,     0,     0,
       0,    19,     0,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,    77,     0,     0,    78,    79,
       0,     0,    80,     0,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   224,     4,
       5,     6,     7,     8,     0,     0,     0,   328,     9,     0,
       0,    10,     0,    12,    13,     0,     0,     0,    14,   329,
      15,    16,     0,     0,   330,     0,    17,    18,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,    77,     0,
       0,    78,    79,     0,     0,    80,     0,     0,   335,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     4,     5,     6,     7,     8,     0,   127,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,    17,    18,
       0,     0,     0,     0,     0,     0,    19,   128,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,     0,     0,    78,    79,     0,     0,    80,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,     0,    15,    16,     0,     0,   140,     0,
      17,    18,     0,     0,     0,     0,     0,     0,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,    53,    54,    55,    56,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,    77,     0,     0,    78,    79,     0,     0,    80,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     4,     5,     6,     7,     8,
       0,   127,     0,     0,     9,     0,     0,    10,     0,    12,
      13,     0,     0,     0,    14,     0,    15,    16,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,    77,     0,     0,    78,    79,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     4,     5,     6,
       7,     8,     0,   276,     0,     0,     9,     0,     0,    10,
       0,    12,    13,     0,     0,     0,    14,     0,    15,    16,
       0,     0,     0,     0,    17,    18,     0,     0,     0,     0,
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
       0,    10,   385,    12,    13,     0,     0,     0,    14,     0,
      15,    16,     0,     0,     0,     0,    17,    18,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,    77,     0,
       0,    78,    79,     0,     0,    80,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,    10,     0,    12,    13,     0,     0,     0,
      14,     0,    15,    16,     0,     0,     0,     0,    17,    18,
       0,     0,   537,     0,     0,     0,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,    53,    54,    55,    56,    57,     0,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,     0,     0,    78,    79,     0,     0,    80,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,     0,    12,    13,     0,
       0,     0,    14,     0,    15,    16,     0,     0,     0,     0,
      17,    18,     0,     0,   539,     0,     0,     0,    19,     0,
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
       0,     0,    17,    18,     0,     0,   609,     0,     0,     0,
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
       0,     0,     0,     0,    17,    18,     0,     0,     0,     0,
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
      15,    16,     0,     0,     0,     0,    17,   607,     0,     0,
       0,     0,     0,     0,    19,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,    77,     0,
       0,    78,    79,     0,     0,    80,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90
};

static const short int yycheck[] =
{
       1,   324,   147,   118,   327,   132,    14,    33,   500,    16,
      17,    16,    17,    46,    16,    24,    44,   132,    24,    32,
      24,   166,    44,   264,   255,    15,    33,     3,    33,   278,
      37,    33,   155,   637,   638,   116,    16,     8,    36,   166,
      16,    17,    68,    10,    11,    58,    44,   128,   297,    38,
       0,    15,    28,    44,    44,    44,   179,    33,   662,   663,
     205,    41,    42,    30,    27,    41,    42,    31,    76,   120,
     121,   122,   123,   124,   125,   126,   317,    38,   401,   310,
      32,   109,    34,    44,    25,    76,    95,   109,   233,    95,
     235,    95,    10,    11,   107,   108,   109,    33,   131,   101,
     101,   114,   115,   116,   105,   118,   119,   114,    38,   601,
     117,    79,   117,    38,    44,   116,    38,   118,    27,    44,
      28,   147,    44,    28,   125,   110,   111,   128,    24,    25,
      26,   132,    12,    76,   137,   138,   139,   140,   146,    16,
     148,   149,     7,   151,   152,    29,   147,   155,   275,   150,
     151,   152,   153,   132,   133,   146,    29,   148,   149,   482,
     151,   152,    93,    94,   155,   166,   311,   654,   655,   137,
     138,   139,   173,   141,   142,   143,    16,   178,    32,     6,
     181,     9,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    16,   199,   314,
     315,   163,   164,   146,   205,   148,   149,    32,   151,   152,
     159,    18,   155,    26,   108,   216,    33,    43,    32,    37,
     221,   134,   223,   146,    38,    39,    40,    41,    42,    34,
     231,    24,   233,    16,   235,     3,   113,   137,   138,   139,
      26,    26,   316,   244,    58,    26,    13,    44,    37,   250,
      34,    26,   253,    29,   255,    16,   114,   331,   332,   333,
     334,   120,   121,   122,   123,   124,   125,   126,    79,    39,
     271,    13,    37,    16,   597,    26,    26,    14,   279,    37,
      46,    28,   397,    16,    44,   108,    38,   140,    37,   290,
      38,    44,   407,   107,   108,   109,   110,   111,    37,    37,
     114,   115,   116,    16,   118,   119,    23,   308,    95,   310,
     311,    37,    26,   314,   315,    95,    16,    15,    35,    26,
      26,    45,    95,    33,    33,   440,   137,   138,   139,   140,
     141,   142,   143,    32,    37,    58,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,    16,   422,    16,
      15,    68,   426,    12,    32,    32,    32,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    58,    58,    32,    32,
      32,    32,   383,    32,    32,    96,   103,   104,   105,    44,
      37,   664,   665,   666,   667,   668,   397,   670,    38,    44,
      16,    38,    38,    32,    32,   479,   407,    32,   127,    33,
      33,    37,    33,    33,    39,    40,    41,    42,   691,    33,
     693,    33,   695,    16,   498,   154,    16,   700,    38,    26,
      26,    44,    26,    58,    32,    26,   437,    16,    26,   440,
     157,   158,    16,    16,    33,   560,    17,    17,    33,    58,
     111,    38,    38,    37,    32,    98,   560,   216,   132,   535,
     578,    39,    40,    41,    42,   111,   272,   542,   428,   470,
     471,   166,   427,   474,   475,   549,   475,   474,   653,   553,
      58,   434,   107,   108,   109,   110,   111,   287,    32,   114,
     115,   116,   432,   118,   119,    39,    40,    41,    42,   500,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   372,   383,   253,    58,   188,   311,   197,   409,   235,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,   153,   107,
     108,   109,   110,   111,    -1,    -1,   114,   115,   116,    16,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,   558,    -1,   560,
     561,    -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,
     114,   115,   116,    -1,   118,   119,    -1,    -1,    -1,    -1,
     128,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
     601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   609,    -1,
      -1,    -1,    -1,    -1,    -1,   616,   617,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    10,    11,    12,    -1,
     631,    -1,   633,    17,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,   658,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
     104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,
      22,    23,    -1,    -1,    -1,    27,    28,    29,    30,    -1,
      -1,    33,    -1,    35,    36,    37,   160,    -1,    -1,    41,
      42,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,   111,
      -1,    -1,   114,    -1,    -1,   117,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    -1,    22,    23,    -1,    -1,    -1,    27,    -1,    29,
      30,    -1,    32,    -1,   156,    35,    36,    -1,    -1,    -1,
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
     150,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    -1,   103,   104,   105,    -1,   107,
      -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,     5,    -1,    -1,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,   150,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,     5,   135,   136,     8,     9,    10,    11,    12,    -1,
      -1,   144,   145,    17,    -1,    -1,    20,    -1,    22,    23,
      -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
     104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    -1,    -1,     3,     4,
      -1,   135,   136,     8,     9,    10,    11,    12,    13,    -1,
     144,   145,    17,    -1,    19,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    31,    -1,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,   110,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     3,     4,   132,   133,    -1,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,
      -1,    29,    30,    31,    -1,    33,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
      -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,   132,   133,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,   103,   104,   105,    -1,   107,    -1,    -1,   110,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    20,    -1,    22,    23,    -1,    -1,    -1,    27,    28,
      29,    30,    -1,    -1,    33,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,   104,   105,    -1,   107,    -1,
      -1,   110,   111,    -1,    -1,   114,    -1,    -1,   117,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
     107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    33,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,   103,   104,
     105,    -1,   107,    -1,    -1,   110,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,     8,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    17,    -1,    -1,    20,    -1,    22,
      23,    -1,    -1,    -1,    27,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,   114,    -1,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    17,    -1,    -1,    20,
      -1,    22,    23,    -1,    -1,    -1,    27,    -1,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
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
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    27,    -1,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,   104,   105,    -1,   107,    -1,
      -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    23,    -1,    -1,    -1,
      27,    -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,   103,   104,   105,    -1,
     107,    -1,    -1,   110,   111,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    22,    23,    -1,
      -1,    -1,    27,    -1,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    43,    -1,
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
      -1,    -1,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,   103,   104,   105,    -1,   107,    -1,
      -1,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,     8,   162,   163,     8,     9,    10,    11,    12,    17,
      20,    21,    22,    23,    27,    29,    30,    35,    36,    43,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    80,    81,    82,    83,    84,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   103,   104,   105,   107,   110,   111,
     114,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   160,   164,   165,   291,     0,    10,    11,   166,   167,
      27,    25,    27,    33,   168,    30,   167,   185,    28,   164,
      28,   169,    12,   170,   175,   164,   186,   187,     7,   190,
      29,    29,   170,    16,   171,    32,   188,    14,    44,   176,
     187,   164,   191,   192,   232,     6,   214,     9,   159,   174,
      33,   164,   189,   187,   176,   192,   193,   215,    16,    18,
      26,    24,    25,    26,    32,   194,   195,     5,    11,    47,
     129,   135,   136,   144,   145,   164,   216,   217,   218,   258,
     261,   263,   279,   172,   164,   164,   164,   164,   196,    34,
     195,   108,    43,    33,    37,   137,   138,   139,   273,   275,
      79,   137,   138,   139,   141,   142,   143,   274,   276,   146,
     280,   280,   176,   217,    34,   134,     3,     4,    13,    31,
      33,   102,   106,   132,   133,   164,   177,   178,   179,   180,
     181,    24,    21,    39,   130,   164,   201,   195,   259,   260,
     261,   219,    16,   140,   275,   140,   276,   164,   261,   182,
      19,   179,     3,   164,    26,   164,    46,   131,   199,   200,
      26,    13,   198,    44,   109,    26,   164,   223,    44,   164,
     261,   262,   277,   278,   277,    37,    34,   222,   132,   133,
     183,   229,   230,   231,   233,   173,    14,   164,   228,    26,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    97,    98,    99,   100,   128,   235,    29,   114,   164,
      16,   197,   260,    39,   221,   164,   262,    13,    37,    16,
      26,    44,    76,   148,   149,   151,   152,   155,   264,   265,
     267,   268,   269,   270,   271,   272,   280,   271,    16,    28,
      33,    37,    41,    42,   114,   117,   156,   164,   232,   281,
     282,   283,   284,   287,   288,   289,    15,    31,   164,   231,
     176,   199,   164,    37,   239,   239,   120,   121,   122,   123,
     124,   125,   126,   246,   247,   249,   120,   121,   122,   123,
     124,   125,   126,   240,   243,   244,   164,   199,    28,    15,
      44,    44,   208,   108,    16,    21,   164,   224,   226,   227,
      38,   262,   278,    33,    68,   147,   232,    32,   150,   232,
     284,   271,   264,   284,   284,   284,   284,   140,    38,    44,
      32,    39,    40,    41,    42,    58,   107,   108,   109,   110,
     111,   114,   115,   116,   118,   119,    37,   184,   234,    16,
      37,   250,    95,   250,    95,    37,   241,    26,    16,    23,
      35,    68,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,   103,   104,   105,   157,   158,   209,   210,   259,    15,
      26,    26,    38,    44,   225,    45,    95,    33,    33,    32,
     150,   232,   153,    14,    38,   232,   283,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,    58,   284,
      37,   284,   285,   286,   233,   229,    38,    44,    16,   242,
     248,   249,   244,   245,    16,   164,    15,    12,   202,   203,
     204,   232,    32,    32,    32,    58,    58,    32,    32,    32,
      32,    93,    94,    32,    32,    44,   109,    39,   164,    39,
     164,    96,   220,   227,   226,    37,   284,   264,   284,   111,
     289,   290,    38,    44,    16,    38,    38,    32,    32,    36,
      44,   207,    16,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   212,   213,
      33,    16,    33,   101,   211,   164,   164,    33,    37,    33,
      33,    33,    33,   210,   127,   222,    16,   154,   266,   284,
      38,    44,   284,    38,    16,   164,   205,    36,   204,    39,
     164,   206,   113,   213,   251,   252,    26,    26,     3,    16,
      17,    28,    33,    41,    42,   236,   237,   238,    44,   264,
     289,    26,   164,    26,    16,    17,    33,    37,   114,   117,
     253,   254,   255,   256,   164,   164,    24,    95,    24,    95,
      16,    16,    38,    44,    24,    95,    16,   164,    26,   164,
     254,   254,   110,   111,    32,    58,   107,   108,   109,   114,
     115,   116,   118,   119,    17,    17,    33,    33,   238,   237,
     237,    38,   164,    38,   254,   254,   255,   255,   255,   255,
     255,    58,   255,    37,   255,   111,   255,   257,   255,    38,
      44,   255
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
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
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

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
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
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

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
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
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
    {the_form.dbname=acl_strdup("formonly");}
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
    {the_form.dbname=acl_strdup(yyvsp[0].str);
if (A4GLF_open_db(yyvsp[0].str)) {
		yyerror("Unable to connect to database\n");
}
}
    break;

  case 9:
#line 137 "screen.yacc"
    {sprintf(yyval.str,acl_getenv("DBNAME"));}
    break;

  case 11:
#line 137 "screen.yacc"
    {SPRINTF2(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 14:
#line 143 "screen.yacc"
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
			the_form.snames.snames_len-1].name =acl_strdup(ptr);

	in_screen_section=1; 
	}
    break;

  case 18:
#line 175 "screen.yacc"
    { lineno=0; scr++; if (scr>1) newscreen=1; }
    break;

  case 19:
#line 177 "screen.yacc"
    { ignorekw=1; lineno=0; }
    break;

  case 20:
#line 180 "screen.yacc"
    { ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;}
    break;

  case 23:
#line 185 "screen.yacc"
    { extended_graphics=1; }
    break;

  case 26:
#line 192 "screen.yacc"
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

  case 31:
#line 214 "screen.yacc"
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

  case 32:
#line 229 "screen.yacc"
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

  case 33:
#line 239 "screen.yacc"
    { ltab=0; }
    break;

  case 34:
#line 240 "screen.yacc"
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
#line 251 "screen.yacc"
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

  case 36:
#line 263 "screen.yacc"
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

  case 37:
#line 276 "screen.yacc"
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

  case 38:
#line 286 "screen.yacc"
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

  case 39:
#line 295 "screen.yacc"
    {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
    break;

  case 40:
#line 300 "screen.yacc"
    {colno=0;lineno++;
	ltab=0;
}
    break;

  case 41:
#line 303 "screen.yacc"
    {
	ltab=0;
}
    break;

  case 42:
#line 311 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 43:
#line 312 "screen.yacc"
    {sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 44:
#line 318 "screen.yacc"
    {
	colno++;
	fstart=colno;
	openwith='[';
}
    break;

  case 45:
#line 325 "screen.yacc"
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

  case 46:
#line 339 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 47:
#line 342 "screen.yacc"
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

  case 48:
#line 353 "screen.yacc"
    {
				strcpy(yyval.str,yyvsp[0].str);
			}
    break;

  case 54:
#line 369 "screen.yacc"
    { 
A4GL_make_downshift(yyvsp[-1].str);
A4GL_make_downshift(yyvsp[0].str);
A4GL_add_table(yyvsp[0].str,yyvsp[-1].str); 
}
    break;

  case 55:
#line 376 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 56:
#line 377 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 57:
#line 380 "screen.yacc"
    {sprintf(yyval.str,"%s", yyvsp[0].str);}
    break;

  case 58:
#line 381 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 59:
#line 383 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 60:
#line 384 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s%s%s", yyvsp[-4].str, yyvsp[-3].str, yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 61:
#line 385 "screen.yacc"
    {sprintf(yyval.str,"%s%s%s", yyvsp[-2].str, yyvsp[-1].str, yyvsp[0].str);}
    break;

  case 66:
#line 400 "screen.yacc"
    {
	A4GL_make_downshift(yyvsp[0].str);
	strcpy(currftag,yyvsp[0].str);
	fldno=A4GL_find_field(yyvsp[0].str);
}
    break;

  case 71:
#line 416 "screen.yacc"
    { 
A4GL_init_fld();
}
    break;

  case 72:
#line 420 "screen.yacc"
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
#line 430 "screen.yacc"
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
#line 458 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-1].str);
}
    break;

  case 76:
#line 462 "screen.yacc"
    {
	fld->subscripts[0]=atoi(yyvsp[-3].str);
	fld->subscripts[1]=atoi(yyvsp[-1].str);
}
    break;

  case 77:
#line 470 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)+256); }
    break;

  case 78:
#line 471 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 79:
#line 474 "screen.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 80:
#line 475 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,yyvsp[-2].str));
		}
    break;

  case 81:
#line 478 "screen.yacc"
    {
			sprintf(yyval.str,"%d",A4GLF_getdatatype_fcompile(yyvsp[0].str,""));
		}
    break;

  case 82:
#line 481 "screen.yacc"
    {
			strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 83:
#line 486 "screen.yacc"
    {
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(yyvsp[-1].str);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 84:
#line 495 "screen.yacc"
    {
	static int xdo=0;
	char buff[256];
	sprintf(buff,"_do_%d",xdo++);
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(buff);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 85:
#line 507 "screen.yacc"
    {
	static int di=0;
	char buff[256];
	sprintf(buff,"_di_%d",di++);
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(buff);
        fld->datatype=atoi(yyvsp[0].str)&0xff;
	if (atoi(yyvsp[0].str)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi(yyvsp[0].str)&0xff;
        fld->dtype_size=dtype_size;
}
    break;

  case 86:
#line 519 "screen.yacc"
    {
	//printf("%s %s\n",$<str>1,$<str>3);
	fld->tabname=acl_strdup(yyvsp[-2].str); 
	fld->colname=acl_strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 87:
#line 528 "screen.yacc"
    {
	fld->colname=acl_strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 88:
#line 536 "screen.yacc"
    {
	fld->tabname=acl_strdup(yyvsp[-2].str); 
	fld->colname=acl_strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
    break;

  case 89:
#line 544 "screen.yacc"
    {
	fld->colname=acl_strdup(yyvsp[0].str);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
    break;

  case 106:
#line 589 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
    break;

  case 107:
#line 590 "screen.yacc"
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

  case 109:
#line 611 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_COMMENTS,yyvsp[0].str); }
    break;

  case 110:
#line 612 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_DEFAULT,yyvsp[0].str); }
    break;

  case 111:
#line 613 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 112:
#line 614 "screen.yacc"
    {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
    break;

  case 113:
#line 615 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 114:
#line 616 "screen.yacc"
    {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
    break;

  case 115:
#line 617 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
    break;

  case 116:
#line 618 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
    break;

  case 117:
#line 619 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_FORMAT,yyvsp[0].str); }
    break;

  case 118:
#line 620 "screen.yacc"
    { sprintf(yyval.str,"\n%s",yyvsp[-1].str); A4GL_add_str_attr(fld,FA_S_INCLUDE,yyval.str); }
    break;

  case 119:
#line 621 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_WIDGET,yyvsp[0].str); }
    break;

  case 120:
#line 622 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_CONFIG,yyvsp[0].str); }
    break;

  case 121:
#line 623 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
    break;

  case 122:
#line 624 "screen.yacc"
    { fld->dynamic=atoi(yyvsp[0].str);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
    break;

  case 123:
#line 626 "screen.yacc"
    { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
    break;

  case 124:
#line 627 "screen.yacc"
    { printf("Warning %s is not implemented for 4GL\n",yyvsp[0].str); }
    break;

  case 125:
#line 628 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
    break;

  case 126:
#line 629 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
    break;

  case 127:
#line 630 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PICTURE,yyvsp[0].str); }
    break;

  case 128:
#line 631 "screen.yacc"
    { A4GL_add_str_attr(fld,FA_S_PROGRAM,yyvsp[0].str); }
    break;

  case 129:
#line 632 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
    break;

  case 130:
#line 635 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
    break;

  case 131:
#line 638 "screen.yacc"
    { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
    break;

  case 135:
#line 642 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 136:
#line 645 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
    break;

  case 137:
#line 649 "screen.yacc"
    {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
    break;

  case 138:
#line 655 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 139:
#line 656 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 140:
#line 657 "screen.yacc"
    {sprintf(yyval.str,"\n%s",yyvsp[0].str);}
    break;

  case 142:
#line 662 "screen.yacc"
    { sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+atoi(yyvsp[0].str)); }
    break;

  case 143:
#line 666 "screen.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 144:
#line 667 "screen.yacc"
    { strcpy(yyval.str,"4"); }
    break;

  case 145:
#line 668 "screen.yacc"
    { strcpy(yyval.str,"2"); }
    break;

  case 146:
#line 669 "screen.yacc"
    { strcpy(yyval.str,"6"); }
    break;

  case 147:
#line 670 "screen.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 148:
#line 671 "screen.yacc"
    { strcpy(yyval.str,"5"); }
    break;

  case 149:
#line 672 "screen.yacc"
    { strcpy(yyval.str,"7"); }
    break;

  case 150:
#line 673 "screen.yacc"
    { strcpy(yyval.str,"3"); }
    break;

  case 151:
#line 675 "screen.yacc"
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

  case 152:
#line 689 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("REVERSE")); }
    break;

  case 153:
#line 690 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("DIM")); }
    break;

  case 154:
#line 691 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("NORMAL")); }
    break;

  case 155:
#line 692 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("LEFT")); }
    break;

  case 156:
#line 693 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BOLD")); }
    break;

  case 157:
#line 694 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("BLINK")); }
    break;

  case 158:
#line 695 "screen.yacc"
    { sprintf(yyval.str,"%d",A4GL_get_attr_from_string("UNDERLINE")); }
    break;

  case 160:
#line 700 "screen.yacc"
    {
}
    break;

  case 166:
#line 710 "screen.yacc"
    {
	char buff[4];
	strcpy(buff,A4GL_char_val(yyvsp[0].str));
	if (strlen(buff)==1) {
		buff[1]=buff[0];
		buff[2]=buff[0];
		buff[3]=0;
	}
	the_form.delim=acl_strdup(buff);
}
    break;

  case 167:
#line 720 "screen.yacc"
    {
A4GL_add_srec();
}
    break;

  case 179:
#line 737 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[0].str,1);
}
    break;

  case 180:
#line 740 "screen.yacc"
    {
   A4GL_set_dim_srec(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 181:
#line 756 "screen.yacc"
    {
	sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 182:
#line 759 "screen.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 185:
#line 769 "screen.yacc"
    {A4GL_add_srec_attribute("",yyvsp[0].str,""); }
    break;

  case 186:
#line 771 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,yyvsp[0].str,""); }
    break;

  case 187:
#line 773 "screen.yacc"
    {A4GL_add_srec_attribute("formonly",yyvsp[0].str,""); }
    break;

  case 188:
#line 775 "screen.yacc"
    {A4GL_add_srec_attribute(yyvsp[-2].str,"*",""); }
    break;

  case 189:
#line 777 "screen.yacc"
    {A4GL_add_srec_attribute("formonly","*",""); }
    break;

  case 191:
#line 781 "screen.yacc"
    {A4GL_add_srec_attribute("","","THROUGH");}
    break;

  case 192:
#line 785 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 193:
#line 788 "screen.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 194:
#line 792 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 195:
#line 792 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 198:
#line 799 "screen.yacc"
    {colno++;}
    break;

  case 199:
#line 800 "screen.yacc"
    {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
    break;

  case 200:
#line 813 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
	A4GL_make_downshift(yyval.str);
	colno+=strlen(yyvsp[0].str);
	}
    break;

  case 201:
#line 821 "screen.yacc"
    {
	colno+=strlen(yyvsp[0].str);
}
    break;

  case 202:
#line 823 "screen.yacc"
    {
	strcpy(yyval.str,yyvsp[-2].str);
	A4GL_make_downshift(yyval.str);
	}
    break;

  case 203:
#line 830 "screen.yacc"
    {
	strcpy(yyval.str,"0");
	dtype_size=0;
}
    break;

  case 204:
#line 834 "screen.yacc"
    {
	strcpy(yyval.str,"2");
	dtype_size=0;
}
    break;

  case 205:
#line 838 "screen.yacc"
    {
	strcpy(yyval.str,"7");
	dtype_size=0;
}
    break;

  case 206:
#line 842 "screen.yacc"
    {
	strcpy(yyval.str,"3");
	dtype_size=0;
}
    break;

  case 207:
#line 846 "screen.yacc"
    {
	strcpy(yyval.str,"4");
	dtype_size=0;
}
    break;

  case 208:
#line 850 "screen.yacc"
    {
	strcpy(yyval.str,"1");
	dtype_size=0;
}
    break;

  case 209:
#line 854 "screen.yacc"
    {
	strcpy(yyval.str,"5");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 210:
#line 858 "screen.yacc"
    {
	strcpy(yyval.str,"8");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 211:
#line 862 "screen.yacc"
    {
	strcpy(yyval.str,"10");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 212:
#line 866 "screen.yacc"
    {
	strcpy(yyval.str,"14");
	dtype_size=atoi(yyvsp[0].str);
}
    break;

  case 213:
#line 870 "screen.yacc"
    {
	strcpy(yyval.str,"6");
	dtype_size=0;
}
    break;

  case 214:
#line 874 "screen.yacc"
    {
	strcpy(yyval.str,"11");
	dtype_size=0;
}
    break;

  case 215:
#line 878 "screen.yacc"
    {
	strcpy(yyval.str,"12");
	dtype_size=0;
}
    break;

  case 216:
#line 882 "screen.yacc"
    { strcpy(yyval.str,"13");
	dtype_size=0;
	}
    break;

  case 217:
#line 885 "screen.yacc"
    { strcpy(yyval.str,"90");
	dtype_size=0;
	}
    break;

  case 219:
#line 892 "screen.yacc"
    {
	sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 222:
#line 897 "screen.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 223:
#line 902 "screen.yacc"
    { strcpy(yyval.str,A4GL_char_val(yyvsp[0].str)); }
    break;

  case 224:
#line 903 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 225:
#line 904 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 226:
#line 905 "screen.yacc"
    {sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 227:
#line 906 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 229:
#line 908 "screen.yacc"
    { sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 230:
#line 909 "screen.yacc"
    { sprintf(yyval.str,"%s\t%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 231:
#line 910 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 232:
#line 914 "screen.yacc"
    {
	sprintf(yyval.str,"%s\t",A4GL_char_val(yyvsp[-2].str));
	sprintf(yyval.str,"%s%s",yyval.str,A4GL_char_val(yyvsp[0].str));
}
    break;

  case 233:
#line 918 "screen.yacc"
    {
	sprintf(yyval.str,"NULL");
}
    break;

  case 234:
#line 924 "screen.yacc"
    {sprintf(yyval.str,"%d",(16<<8) + 2);}
    break;

  case 235:
#line 925 "screen.yacc"
    {sprintf(yyval.str,"%d",((atoi(yyvsp[-1].str)+2)<<8)+2);}
    break;

  case 236:
#line 926 "screen.yacc"
    {sprintf(yyval.str,"%d",(atoi(yyvsp[-3].str)<<8)+atoi(yyvsp[-1].str));}
    break;

  case 237:
#line 929 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 238:
#line 931 "screen.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str));
	}
    break;

  case 239:
#line 937 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 240:
#line 939 "screen.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 241:
#line 944 "screen.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 242:
#line 952 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 243:
#line 955 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 244:
#line 956 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 245:
#line 957 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 246:
#line 958 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 247:
#line 959 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 248:
#line 960 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 249:
#line 962 "screen.yacc"
    {
  A4GL_debug("opt_frac returns %s",yyvsp[0].str);
  sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 251:
#line 969 "screen.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 252:
#line 970 "screen.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 253:
#line 973 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 254:
#line 976 "screen.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 255:
#line 980 "screen.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 256:
#line 981 "screen.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 257:
#line 982 "screen.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 258:
#line 983 "screen.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 259:
#line 984 "screen.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 260:
#line 985 "screen.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 261:
#line 987 "screen.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 262:
#line 992 "screen.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 263:
#line 994 "screen.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 264:
#line 1001 "screen.yacc"
    {yyval.expr=0;}
    break;

  case 265:
#line 1001 "screen.yacc"
    {
yyval.expr=yyvsp[0].expr;
}
    break;

  case 266:
#line 1007 "screen.yacc"
    {
		yyval.expr=yyvsp[0].expr;
	}
    break;

  case 268:
#line 1014 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  
	}
    break;

  case 269:
#line 1017 "screen.yacc"
    {
		yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  
	}
    break;

  case 270:
#line 1023 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 271:
#line 1024 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 272:
#line 1025 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 273:
#line 1026 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 274:
#line 1027 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 275:
#line 1028 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 276:
#line 1029 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 277:
#line 1030 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 278:
#line 1031 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 279:
#line 1032 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 280:
#line 1033 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 281:
#line 1034 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 282:
#line 1035 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 283:
#line 1038 "screen.yacc"
    {
yyval.expr=create_field_expr(yyvsp[0].str);
if (strcasecmp(currftag,yyvsp[0].str)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
    break;

  case 284:
#line 1045 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); printf("NUMBER VALUE : %s\n",yyvsp[0].str); }
    break;

  case 285:
#line 1046 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 286:
#line 1047 "screen.yacc"
    {
	yyval.expr=create_special_expr(yyvsp[0].str);
}
    break;

  case 288:
#line 1055 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 289:
#line 1059 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;

  case 348:
#line 1194 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"AND");  }
    break;

  case 349:
#line 1195 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,"OR");  }
    break;

  case 354:
#line 1209 "screen.yacc"
    { void *x; x=create_int_expr(0); yyval.expr=create_expr_comp_expr(x,yyvsp[0].expr,"-"); }
    break;

  case 355:
#line 1211 "screen.yacc"
    { void *x; x=create_int_expr(0); yyval.expr=create_expr_comp_expr(x,yyvsp[0].expr,"+"); }
    break;

  case 356:
#line 1212 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 357:
#line 1213 "screen.yacc"
    { yyval.expr=create_not_expr(yyvsp[0].expr); }
    break;

  case 358:
#line 1214 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 359:
#line 1215 "screen.yacc"
    { yyval.expr=yyvsp[-1].expr; }
    break;

  case 360:
#line 1216 "screen.yacc"
    { yyval.expr=yyvsp[0].expr; }
    break;

  case 361:
#line 1217 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 362:
#line 1218 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 363:
#line 1219 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 364:
#line 1220 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 365:
#line 1221 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 366:
#line 1222 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 367:
#line 1223 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 368:
#line 1224 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 369:
#line 1225 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-3].expr,yyvsp[0].expr,"NOTLIKE"); }
    break;

  case 370:
#line 1226 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-2].expr,yyvsp[0].expr,yyvsp[-1].str); }
    break;

  case 371:
#line 1227 "screen.yacc"
    { void *p; p=create_char_expr("ISNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNULL"); }
    break;

  case 372:
#line 1228 "screen.yacc"
    { void *p; p=create_char_expr("ISNOTNULL"); yyval.expr=create_expr_comp_expr(yyvsp[-1].expr,p,"ISNOTNULL"); }
    break;

  case 373:
#line 1229 "screen.yacc"
    { yyval.expr=create_list_expr(); add_list_expr(yyval.expr,yyvsp[-2].expr); add_list_expr(yyval.expr,yyvsp[0].expr); yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyval.expr,"BETWEEN"); }
    break;

  case 374:
#line 1230 "screen.yacc"
    { yyval.expr=create_expr_comp_expr(yyvsp[-4].expr,yyvsp[-1].expr,"IN"); }
    break;

  case 376:
#line 1236 "screen.yacc"
    { yyval.expr=create_field_expr(yyvsp[0].str); }
    break;

  case 377:
#line 1237 "screen.yacc"
    {yyval.expr=create_int_expr(atoi(yyvsp[0].str)); }
    break;

  case 378:
#line 1238 "screen.yacc"
    {yyval.expr=create_char_expr(yyvsp[0].str);}
    break;

  case 379:
#line 1239 "screen.yacc"
    { yyval.expr=create_special_expr(yyvsp[0].str); }
    break;

  case 380:
#line 1240 "screen.yacc"
    { yyval.expr=create_special_expr(yyvsp[0].str);}
    break;

  case 381:
#line 1243 "screen.yacc"
    {
		yyval.expr=create_list_expr();
		add_list_expr(yyval.expr,yyvsp[0].expr);
	}
    break;

  case 382:
#line 1247 "screen.yacc"
    {
		add_list_expr(yyvsp[-2].expr,yyvsp[0].expr);
		yyval.expr=yyvsp[-2].expr;
	}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 4243 "y.tab.c"

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

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
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

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
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


#line 1346 "screen.yacc"



#include "lex.yy.c"



/* =========================== EOF ============================ */





