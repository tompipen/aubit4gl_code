
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         sqlparse_yyparse
#define yylex           sqlparse_yylex
#define yyerror         sqlparse_yyerror
#define yylval          sqlparse_yylval
#define yychar          sqlparse_yychar
#define yydebug         sqlparse_yydebug
#define yynerrs         sqlparse_yynerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sql.yacc"

#define YYLEX_PARAM yystate
#define YY_DECL int yylex(int yystate)
int sqlparse_yylex(int yystate);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a4gl_libaubit4gl.h"
#include "dataio/fgl.xs.h"
#include "a4gl_expr.h"
#include "alias.h"
//#include "sqlcompiler.h"

#define SQL_SET_EXPLAIN_OFF 1
#define SQL_SET_LOCK_MODE_WAIT_N 2
#define SQL_SET_LOCK_MODE_NOT_WAIT 3
#define SQL_SET_ISOLATION_DIRTY_READ 4
#define SQL_SET_ISOLATION_REPEATABLE_READ 5
#define SQL_SET_ISOLATION_CURSOR_STABILITY 6 
#define SQL_SET_ISOLATION_COMMITTED_READ 7


#define add_feature A4GL_add_feature
void add_sql_function(char *s);

int A4GL_cursor_current(expr_str *s);
struct s_select_list_item_list *expand_slil(struct s_select_list_item_list *l);
char *get_insert_cmd (struct struct_insert_cmd *insertCmd,int *converted);
char *get_update_cmd(struct struct_update_cmd *updateCmd, int *converted) ;
char * get_delete_cmd (struct struct_delete_cmd *deleteCmd, int *converted) ;

str_list *generate_update_column_list_for(char *tabname,struct s_select_list_item_list *valuelist);
extern int place_holder_cnt;
void A4GL_warn(char *s);

extern char *kw_space;
extern char *kw_comma;
extern char *kw_ob;
extern char *kw_cb;

int insql=0;
static char *make_sql_string_and_free(char *,...);
char last_tmp_name[256];
#define ADDMAP(x,y) addmap_runtime(x,y)
#define ADDMAP_MODULE(x,y) addmap_runtime(x,y)

int yylineno;
int table_cnt=0;
char* curr_func="";
char *infilename="";
int doing_declare=0;
#define YY_NEVER_INTERACTIVE 1

char current_upd_table[256];
char current_del_table[256];
#define DEFINED_INS_TABLE
char current_ins_table[256];

#define a4gl_yyerror sqlparse_yyerror


static void print_sql_commit (int n) ;
static void print_exec_sql (char *s) ;
static void print_exec_select (char *s)    ;
static void conn_db (char *s) ;
static void print_unable_to_parse(void) ;
static int A4GLSQLCV_process(void);
static int sqlparse_yyerror(char *s) ;
int A4GL_4glc_push_gen_expand(int n,char *v);



static void ansi_violation(char *s,int n);
static void addmap_runtime (char *s,char *f);

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#ifdef SIMPLIFIED
#include "y_tab.h"
#else
#include "y.tab.h"
#endif
struct s_select_list_item_list * local_new_select_list_item_list(  struct s_select_list_item *i) ;
struct s_select_list_item_list * local_add_select_list_item_list( struct s_select_list_item_list *p, struct s_select_list_item *i);

#define GEN_STACK_HERE
#include "a4gl_gen_stack.h"

int sql_string_cnt=0;
int this_sql_start=0;
char *Sql=0;
FILE *Sql_file;
int input_from_file=0;
extern char* yytext;

extern FILE *yyin;
extern int sqlparse_yydebug;
int process(void) ;
char *sql_string;
int sql_type;
int was_ok=0;
/*
struct sql_stmt {
        int type;
        char *val;
};

struct sql_stmt *stmts=0;
*/

int db_used=0;
//char *acl_getenv(char *s);



/* Line 189 of yacc.c  */
#line 199 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VALUE = 2205,
     NAMED = 2206,
     NAMED_GEN = 2207,
     CHAR_VALUE = 2208,
     NOT_USED_1 = 2209,
     NOT_USED_2 = 2210,
     NOT_USED_3 = 2211,
     NOT_USED_4 = 2212,
     NOT_USED_5 = 2213,
     NOT_USED_6 = 2214,
     NOT_USED_7 = 2215,
     NOT_USED_8 = 2216,
     NUMBER_VALUE = 2217,
     SEMICOLON = 2218,
     QUESTION_MARK = 2219,
     CLINE = 2220,
     CH = 2221,
     MARK_VAR = 2222,
     END_MARK_VAR = 2223,
     LEFT_JOIN = 1002,
     INNER_JOIN = 1005,
     USING_BTREE = 1028,
     USING_RTREE = 1029,
     SET_BUFFERED_LOG = 1054,
     SET_LOG = 1057,
     MDY = 1059,
     WEEKDAY = 1060,
     MODE_ANSI = 1063,
     START_DATABASE = 1064,
     WITH_LOG_IN = 1065,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1066,
     DATETIME_VALUE = 1079,
     INTERVAL_VALUE = 1080,
     RECOVER_TABLE = 1081,
     ROLLFORWARD_DATABASE = 1082,
     DROP_TRIGGER = 1098,
     DROP_AUDIT_FOR = 1099,
     CREATE_AUDIT_FOR = 1100,
     EXECUTE_PROCEDURE = 1104,
     ALTER_TABLE = 1111,
     ALTER_INDEX = 1112,
     NEXT_SIZE = 1113,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1150,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1151,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1152,
     XSET_MULTIPLY_EQUAL = 1153,
     XSET_OPEN_BRACKET = 1154,
     CREATE_DATABASE = 1157,
     DROP_DATABASE = 1158,
     ADD_CONSTRAINT = 1160,
     DROP_CONSTRAINT = 1161,
     DROP_SYNONYM = 1162,
     CONSTRAINT = 1163,
     NOT_FIELD_TOUCHED_CURRENT = 1166,
     FIELD_TOUCHED_CURRENT = 1167,
     DOUBLE_PRECISION = 1174,
     COUNT_MULTIPLY = 1175,
     MODIFY_NEXT_SIZE = 1195,
     LOCK_MODE_PAGE = 1196,
     LOCK_MODE_ROW = 1197,
     UNITS_YEAR = 1204,
     UNITS_MONTH = 1205,
     UNITS_DAY = 1206,
     UNITS_HOUR = 1207,
     UNITS_MINUTE = 1208,
     UNITS_SECOND = 1209,
     TO_CLUSTER = 1214,
     TO_NOT_CLUSTER = 1215,
     CREATE_UC_IDX = 1217,
     CREATE_U_IDX = 1218,
     CREATE_C_IDX = 1219,
     CREATE_IDX = 1220,
     DOUBLE_COLON = 1230,
     SQLSICS = 1236,
     CREATE_SCHEMA = 1237,
     SQLSIRR = 1238,
     UPDATESTATS_T = 1239,
     SQLSICR = 1240,
     SQLSIDR = 1251,
     CREATE_TEMP_TABLE = 1252,
     WITH_CHECK_OPTION = 1260,
     WITH_GRANT_OPTION = 1261,
     SQLSLMNW = 1262,
     WHERE_CURRENT_OF = 1268,
     NOT_NULL_UNIQUE = 1276,
     SQLSLMW = 1283,
     ALL_PRIVILEGES = 1285,
     CREATE_SYNONYM = 1289,
     DROP_TABLE = 1290,
     INEXCLUSIVE = 1292,
     UPDATESTATS = 1297,
     CREATE_TABLE = 1323,
     DEFAULT_NULL = 1324,
     DEFAULT_TODAY = 1325,
     DEFAULT_USER = 1326,
     UNLOCK_TABLE = 1339,
     ROLLBACK_W = 1347,
     SQLSEON = 1349,
     SQLSEOFF = 1350,
     CREATE_VIEW = 1354,
     DELETE_FROM = 1355,
     EXTENT_SIZE = 1362,
     FOREIGN_KEY = 1363,
     INSERT_INTO = 1366,
     IS_NOT_NULL = 1368,
     NOT_MATCHES = 1371,
     PRIMARY_KEY = 1377,
     USE_SESSION = 1384,
     WITH_NO_LOG = 1385,
     INSHARE = 1388,
     BEGIN_WORK = 1394,
     DROP_INDEX = 1399,
     FOR_UPDATE_OF = 1405,
     FOR_UPDATE = 1406,
     LOCK_TABLE = 1411,
     NOT_EXISTS = 1413,
     REFERENCES = 1415,
     RENCOL = 1416,
     SMALLFLOAT = 1418,
     COMMIT_W = 1429,
     RENTAB = 1436,
     KW_CHAR = 1439,
     NCHAR = 1440,
     NVARCHAR = 1441,
     DELIMITER = 1443,
     DROP_VIEW = 1445,
     EXCLUSIVE = 1448,
     GREATER_THAN_EQ = 1452,
     INTO_TEMP = 1454,
     DATABASE = 1478,
     DATETIME = 1479,
     DISTINCT = 1481,
     FRACTION = 1488,
     GROUP_BY = 1490,
     INTERVAL = 1491,
     NOT_LIKE = 1493,
     NOT_ILIKE = 1494,
     NOT_NULL = 1495,
     RESOURCE = 1501,
     SMALLINT = 1502,
     IS_NULL = 1508,
     LESS_THAN_EQ = 1509,
     BETWEEN = 1511,
     CLOSE_BRACKET = 1514,
     CONNECT = 1517,
     KW_CURRENT = 1518,
     KW_DECIMAL = 1520,
     DEFAULT = 1522,
     INTEGER = 1530,
     SERIAL8 = 1532,
     MATCHES = 1535,
     VARCHAR = 1548,
     CLOSE_SQUARE = 1551,
     GREATER_THAN = 1552,
     KW_FALSE = 1553,
     NOT_IN = 1554,
     OPEN_BRACKET = 1556,
     KW_DELETE = 1564,
     KW_ESCAPE = 1567,
     EXISTS = 1568,
     EXTEND = 1569,
     HAVING = 1573,
     KW_INSERT = 1575,
     MINUTE = 1579,
     MODIFY = 1580,
     EQUAL = 1582,
     NOT_EQUAL = 1583,
     OPEN_SQUARE = 1585,
     PUBLIC = 1589,
     REVOKE = 1593,
     SECOND = 1597,
     KW_SELECT = 1601,
     SERIAL = 1602,
     UNIQUE = 1605,
     KW_UPDATE = 1607,
     VALUES = 1608,
     KW_NULL = 1611,
     KW_TRUE = 1612,
     ALTER = 1614,
     CHECK = 1620,
     COUNT = 1624,
     KW_FIRST = 1629,
     KW_FLOAT = 1630,
     GRANT = 1633,
     INDEX = 1636,
     LESS_THAN = 1639,
     MONEY = 1641,
     MONTH = 1642,
     KW_MULTIPLY = 1644,
     ORDER = 1645,
     OUTER = 1646,
     UNION = 1655,
     WHERE = 1658,
     KW_BYTE = 1665,
     CASE = 1667,
     KW_DATE = 1669,
     DESC = 1670,
     KW_DIVIDE = 1671,
     DROP = 1674,
     ELSE = 1675,
     FROM = 1679,
     HOUR = 1685,
     INTO = 1686,
     LIKE = 1689,
     REAL = 1698,
     SOME = 1703,
     KW_TEXT = 1707,
     KW_THEN = 1708,
     USER = 1709,
     WHEN = 1711,
     YEAR = 1714,
     KW_DOW = 1715,
     XSET = 1717,
     ADD = 1718,
     ALL = 1719,
     KW_AND = 1720,
     ANY = 1721,
     ASC = 1722,
     AVG = 1723,
     COLON = 1724,
     KW_COMMA = 1725,
     DAY = 1726,
     DBA = 1727,
     KW_FOR = 1731,
     XMAX = 1736,
     XMIN = 1737,
     KW_MINUS = 1738,
     KW_MOD = 1739,
     KW_NOT = 1740,
     KW_SUM = 1747,
     ATSIGN = 1750,
     KW_PLUS = 1751,
     KW_AS = 1757,
     KW_BY = 1759,
     KW_DOT = 1760,
     KW_IN = 1763,
     KW_ON = 1765,
     KW_OR = 1766,
     KW_TO = 1767,
     BEFORE = 1805,
     END = 1809,
     TILDE = 1816,
     ILIKE = 1817,
     FILLFACTOR = 1820,
     TIME = 1825,
     KW_TODAY = 1832,
     KW_ROWID = 1833,
     TIMESTAMP = 2181,
     KW_TAG = 2202,
     LINTMODULEISLIBRARY = 2203
   };
#endif
/* Tokens.  */
#define INT_VALUE 2205
#define NAMED 2206
#define NAMED_GEN 2207
#define CHAR_VALUE 2208
#define NOT_USED_1 2209
#define NOT_USED_2 2210
#define NOT_USED_3 2211
#define NOT_USED_4 2212
#define NOT_USED_5 2213
#define NOT_USED_6 2214
#define NOT_USED_7 2215
#define NOT_USED_8 2216
#define NUMBER_VALUE 2217
#define SEMICOLON 2218
#define QUESTION_MARK 2219
#define CLINE 2220
#define CH 2221
#define MARK_VAR 2222
#define END_MARK_VAR 2223
#define LEFT_JOIN 1002
#define INNER_JOIN 1005
#define USING_BTREE 1028
#define USING_RTREE 1029
#define SET_BUFFERED_LOG 1054
#define SET_LOG 1057
#define MDY 1059
#define WEEKDAY 1060
#define MODE_ANSI 1063
#define START_DATABASE 1064
#define WITH_LOG_IN 1065
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1066
#define DATETIME_VALUE 1079
#define INTERVAL_VALUE 1080
#define RECOVER_TABLE 1081
#define ROLLFORWARD_DATABASE 1082
#define DROP_TRIGGER 1098
#define DROP_AUDIT_FOR 1099
#define CREATE_AUDIT_FOR 1100
#define EXECUTE_PROCEDURE 1104
#define ALTER_TABLE 1111
#define ALTER_INDEX 1112
#define NEXT_SIZE 1113
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1150
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1151
#define XSET_ident_DOT_MULTIPLY_EQUAL 1152
#define XSET_MULTIPLY_EQUAL 1153
#define XSET_OPEN_BRACKET 1154
#define CREATE_DATABASE 1157
#define DROP_DATABASE 1158
#define ADD_CONSTRAINT 1160
#define DROP_CONSTRAINT 1161
#define DROP_SYNONYM 1162
#define CONSTRAINT 1163
#define NOT_FIELD_TOUCHED_CURRENT 1166
#define FIELD_TOUCHED_CURRENT 1167
#define DOUBLE_PRECISION 1174
#define COUNT_MULTIPLY 1175
#define MODIFY_NEXT_SIZE 1195
#define LOCK_MODE_PAGE 1196
#define LOCK_MODE_ROW 1197
#define UNITS_YEAR 1204
#define UNITS_MONTH 1205
#define UNITS_DAY 1206
#define UNITS_HOUR 1207
#define UNITS_MINUTE 1208
#define UNITS_SECOND 1209
#define TO_CLUSTER 1214
#define TO_NOT_CLUSTER 1215
#define CREATE_UC_IDX 1217
#define CREATE_U_IDX 1218
#define CREATE_C_IDX 1219
#define CREATE_IDX 1220
#define DOUBLE_COLON 1230
#define SQLSICS 1236
#define CREATE_SCHEMA 1237
#define SQLSIRR 1238
#define UPDATESTATS_T 1239
#define SQLSICR 1240
#define SQLSIDR 1251
#define CREATE_TEMP_TABLE 1252
#define WITH_CHECK_OPTION 1260
#define WITH_GRANT_OPTION 1261
#define SQLSLMNW 1262
#define WHERE_CURRENT_OF 1268
#define NOT_NULL_UNIQUE 1276
#define SQLSLMW 1283
#define ALL_PRIVILEGES 1285
#define CREATE_SYNONYM 1289
#define DROP_TABLE 1290
#define INEXCLUSIVE 1292
#define UPDATESTATS 1297
#define CREATE_TABLE 1323
#define DEFAULT_NULL 1324
#define DEFAULT_TODAY 1325
#define DEFAULT_USER 1326
#define UNLOCK_TABLE 1339
#define ROLLBACK_W 1347
#define SQLSEON 1349
#define SQLSEOFF 1350
#define CREATE_VIEW 1354
#define DELETE_FROM 1355
#define EXTENT_SIZE 1362
#define FOREIGN_KEY 1363
#define INSERT_INTO 1366
#define IS_NOT_NULL 1368
#define NOT_MATCHES 1371
#define PRIMARY_KEY 1377
#define USE_SESSION 1384
#define WITH_NO_LOG 1385
#define INSHARE 1388
#define BEGIN_WORK 1394
#define DROP_INDEX 1399
#define FOR_UPDATE_OF 1405
#define FOR_UPDATE 1406
#define LOCK_TABLE 1411
#define NOT_EXISTS 1413
#define REFERENCES 1415
#define RENCOL 1416
#define SMALLFLOAT 1418
#define COMMIT_W 1429
#define RENTAB 1436
#define KW_CHAR 1439
#define NCHAR 1440
#define NVARCHAR 1441
#define DELIMITER 1443
#define DROP_VIEW 1445
#define EXCLUSIVE 1448
#define GREATER_THAN_EQ 1452
#define INTO_TEMP 1454
#define DATABASE 1478
#define DATETIME 1479
#define DISTINCT 1481
#define FRACTION 1488
#define GROUP_BY 1490
#define INTERVAL 1491
#define NOT_LIKE 1493
#define NOT_ILIKE 1494
#define NOT_NULL 1495
#define RESOURCE 1501
#define SMALLINT 1502
#define IS_NULL 1508
#define LESS_THAN_EQ 1509
#define BETWEEN 1511
#define CLOSE_BRACKET 1514
#define CONNECT 1517
#define KW_CURRENT 1518
#define KW_DECIMAL 1520
#define DEFAULT 1522
#define INTEGER 1530
#define SERIAL8 1532
#define MATCHES 1535
#define VARCHAR 1548
#define CLOSE_SQUARE 1551
#define GREATER_THAN 1552
#define KW_FALSE 1553
#define NOT_IN 1554
#define OPEN_BRACKET 1556
#define KW_DELETE 1564
#define KW_ESCAPE 1567
#define EXISTS 1568
#define EXTEND 1569
#define HAVING 1573
#define KW_INSERT 1575
#define MINUTE 1579
#define MODIFY 1580
#define EQUAL 1582
#define NOT_EQUAL 1583
#define OPEN_SQUARE 1585
#define PUBLIC 1589
#define REVOKE 1593
#define SECOND 1597
#define KW_SELECT 1601
#define SERIAL 1602
#define UNIQUE 1605
#define KW_UPDATE 1607
#define VALUES 1608
#define KW_NULL 1611
#define KW_TRUE 1612
#define ALTER 1614
#define CHECK 1620
#define COUNT 1624
#define KW_FIRST 1629
#define KW_FLOAT 1630
#define GRANT 1633
#define INDEX 1636
#define LESS_THAN 1639
#define MONEY 1641
#define MONTH 1642
#define KW_MULTIPLY 1644
#define ORDER 1645
#define OUTER 1646
#define UNION 1655
#define WHERE 1658
#define KW_BYTE 1665
#define CASE 1667
#define KW_DATE 1669
#define DESC 1670
#define KW_DIVIDE 1671
#define DROP 1674
#define ELSE 1675
#define FROM 1679
#define HOUR 1685
#define INTO 1686
#define LIKE 1689
#define REAL 1698
#define SOME 1703
#define KW_TEXT 1707
#define KW_THEN 1708
#define USER 1709
#define WHEN 1711
#define YEAR 1714
#define KW_DOW 1715
#define XSET 1717
#define ADD 1718
#define ALL 1719
#define KW_AND 1720
#define ANY 1721
#define ASC 1722
#define AVG 1723
#define COLON 1724
#define KW_COMMA 1725
#define DAY 1726
#define DBA 1727
#define KW_FOR 1731
#define XMAX 1736
#define XMIN 1737
#define KW_MINUS 1738
#define KW_MOD 1739
#define KW_NOT 1740
#define KW_SUM 1747
#define ATSIGN 1750
#define KW_PLUS 1751
#define KW_AS 1757
#define KW_BY 1759
#define KW_DOT 1760
#define KW_IN 1763
#define KW_ON 1765
#define KW_OR 1766
#define KW_TO 1767
#define BEFORE 1805
#define END 1809
#define TILDE 1816
#define ILIKE 1817
#define FILLFACTOR 1820
#define TIME 1825
#define KW_TODAY 1832
#define KW_ROWID 1833
#define TIMESTAMP 2181
#define KW_TAG 2202
#define LINTMODULEISLIBRARY 2203




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 119 "sql.yacc"

        char    str[8192];
   char *sql_string;
	struct  ilist int_list;
	struct s_table *u_table;
	struct s_select_finish *s_select_finish;
        struct s_select_list_item_list *s_select_list_item_list;
        struct s_select_list_item *s_select_list_item;
        struct s_select *s_select;
        int     integer_val;
        float   float_val;
	enum e_boolean e_boolean;
	 struct expr_str_list *ptr_list;
	        struct struct_update_cmd *update_cmd;
        struct struct_insert_cmd *insert_cmd;
        struct struct_delete_cmd *delete_cmd;
        struct s_update_pair *upd_pair;
        struct expr_str *ptr;
        struct str_list *str_list;





/* Line 214 of yacc.c  */
#line 764 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 776 "y.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  158
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2634

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  253
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  227
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2223

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
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    22,     2,     2,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    24,    25,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    26,     2,     2,    27,     2,    28,
      29,     2,     2,    30,    31,    32,    33,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      35,    36,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    39,
      40,     2,     2,     2,    41,     2,     2,     2,     2,     2,
       2,    42,    43,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,    47,    48,    49,     2,     2,    50,    51,     2,
      52,    53,    54,    55,     2,     2,    56,    57,     2,     2,
       2,     2,     2,     2,    58,    59,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    60,    61,    62,     2,     2,
       2,     2,     2,     2,    63,    64,    65,    66,    67,    68,
       2,     2,     2,     2,    69,    70,     2,    71,    72,    73,
      74,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      75,     2,     2,     2,     2,     2,    76,    77,    78,    79,
      80,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,    82,     2,     2,     2,     2,     2,     2,     2,
      83,    84,    85,     2,     2,     2,     2,     2,    86,     2,
       2,     2,     2,     2,     2,     2,    87,     2,     2,     2,
       2,     2,     2,    88,     2,    89,     2,     2,     2,    90,
      91,     2,    92,     2,     2,     2,     2,    93,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,    95,    96,    97,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    98,
       2,     2,     2,     2,     2,     2,     2,    99,     2,   100,
     101,     2,     2,     2,   102,   103,     2,     2,     2,     2,
       2,     2,   104,   105,     2,     2,   106,     2,   107,     2,
       2,   108,     2,     2,     2,     2,     2,   109,     2,     2,
       2,     2,     2,     2,   110,   111,     2,     2,   112,     2,
       2,     2,     2,     2,   113,     2,     2,     2,     2,   114,
       2,     2,     2,     2,     2,   115,   116,     2,     2,     2,
       2,   117,     2,   118,     2,   119,   120,     2,   121,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   122,
       2,     2,     2,     2,     2,     2,   123,     2,     2,   124,
     125,   126,     2,   127,     2,   128,     2,     2,   129,     2,
       2,     2,   130,     2,   131,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   132,   133,
       2,   134,     2,     2,     2,     2,     2,     2,   135,     2,
     136,   137,     2,   138,   139,   140,     2,     2,     2,     2,
       2,   141,   142,     2,     2,     2,     2,     2,   143,   144,
       2,   145,     2,     2,   146,     2,     2,   147,   148,     2,
     149,     2,   150,     2,     2,     2,     2,     2,     2,     2,
     151,     2,   152,     2,     2,   153,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   154,     2,
       2,   155,   156,   157,   158,     2,   159,     2,     2,     2,
       2,     2,     2,     2,   160,     2,     2,   161,   162,   163,
       2,     2,     2,   164,     2,   165,     2,     2,     2,   166,
     167,     2,   168,   169,     2,   170,     2,     2,     2,   171,
       2,     2,     2,   172,     2,     2,     2,   173,     2,     2,
       2,   174,   175,     2,     2,   176,     2,   177,   178,     2,
       2,   179,   180,     2,   181,     2,     2,     2,     2,     2,
     182,     2,     2,     2,   183,     2,     2,     2,     2,   184,
     185,     2,     2,   186,     2,     2,   187,     2,     2,   188,
       2,   189,   190,     2,   191,   192,   193,     2,     2,     2,
       2,     2,     2,     2,     2,   194,     2,     2,   195,     2,
       2,     2,     2,     2,     2,   196,     2,   197,     2,   198,
     199,   200,     2,     2,   201,   202,     2,     2,     2,   203,
       2,     2,     2,     2,     2,   204,   205,     2,     2,   206,
       2,     2,     2,     2,     2,     2,     2,     2,   207,     2,
       2,     2,     2,   208,     2,     2,     2,   209,   210,   211,
       2,   212,     2,     2,   213,   214,     2,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,     2,     2,
       2,   226,     2,     2,     2,     2,   227,   228,   229,   230,
     231,     2,     2,     2,     2,     2,     2,   232,     2,     2,
     233,   234,     2,     2,     2,     2,     2,   235,     2,   236,
     237,     2,     2,   238,     2,   239,   240,   241,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   242,     2,     2,     2,   243,
       2,     2,     2,     2,     2,     2,   244,   245,     2,     2,
     246,     2,     2,     2,     2,   247,     2,     2,     2,     2,
       2,     2,   248,   249,     2,     2,     2,     2,     2,     2,
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
       2,   250,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   251,   252,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    12,    15,    16,    19,    22,
      30,    34,    38,    41,    44,    47,    49,    53,    55,    58,
      61,    66,    73,    77,    81,    83,    87,    89,    93,    95,
      97,    99,   102,   105,   108,   111,   113,   115,   122,   131,
     132,   134,   136,   139,   142,   145,   148,   150,   152,   154,
     155,   157,   159,   162,   165,   168,   170,   172,   174,   183,
     192,   201,   210,   213,   216,   221,   226,   229,   232,   235,
     238,   239,   241,   242,   244,   246,   250,   253,   256,   258,
     260,   264,   266,   268,   272,   276,   280,   282,   286,   288,
     290,   292,   294,   296,   298,   300,   303,   308,   310,   314,
     316,   320,   323,   328,   330,   334,   336,   339,   344,   346,
     350,   352,   354,   356,   359,   363,   368,   371,   376,   377,
     380,   383,   388,   390,   394,   396,   398,   399,   405,   406,
     412,   414,   415,   419,   421,   425,   427,   431,   433,   437,
     439,   441,   445,   447,   449,   450,   452,   454,   460,   465,
     467,   469,   471,   474,   476,   478,   480,   482,   484,   486,
     488,   490,   492,   494,   496,   504,   511,   516,   521,   523,
     525,   527,   528,   530,   533,   535,   537,   539,   541,   545,
     548,   550,   552,   555,   557,   559,   560,   564,   566,   570,
     572,   576,   578,   580,   587,   588,   592,   594,   598,   599,
     601,   606,   612,   615,   617,   619,   624,   626,   630,   635,
     640,   645,   647,   651,   653,   655,   657,   660,   662,   664,
     666,   671,   672,   674,   675,   677,   679,   682,   685,   687,
     689,   691,   693,   695,   700,   702,   706,   708,   710,   712,
     715,   717,   719,   722,   725,   728,   730,   734,   739,   746,
     752,   758,   760,   764,   766,   769,   773,   774,   777,   779,
     782,   783,   785,   788,   790,   792,   796,   798,   802,   804,
     807,   809,   813,   816,   819,   820,   823,   824,   827,   828,
     831,   833,   835,   836,   838,   842,   846,   850,   854,   858,
     865,   870,   875,   880,   885,   890,   895,   897,   899,   901,
     903,   905,   907,   909,   911,   913,   915,   916,   918,   920,
     922,   923,   925,   927,   929,   931,   933,   935,   937,   939,
     944,   946,   951,   953,   958,   960,   966,   972,   974,   976,
     978,   980,   982,   987,   989,   994,  1001,  1006,  1008,  1013,
    1015,  1017,  1025,  1027,  1029,  1031,  1036,  1043,  1044,  1047,
    1052,  1054,  1056,  1058,  1060,  1062,  1064,  1066,  1068,  1070,
    1071,  1075,  1081,  1083,  1086,  1088,  1091,  1094,  1099,  1103,
    1105,  1108,  1113,  1120,  1124,  1126,  1128,  1130,  1132,  1134,
    1135,  1139,  1141,  1143,  1145,  1147,  1149,  1151,  1153,  1155,
    1157,  1159,  1161,  1163,  1165,  1167,  1172,  1177,  1183,  1185,
    1187,  1189,  1191,  1196,  1203,  1205,  1207,  1210,  1214,  1216,
    1218,  1220,  1225,  1227,  1229,  1237,  1242,  1244,  1247,  1251,
    1253,  1257,  1260,  1262,  1264,  1265,  1267,  1269,  1272,  1274,
    1278,  1280,  1282,  1284,  1286,  1288,  1293,  1295,  1300,  1301,
    1302,  1313,  1320,  1321,  1325,  1326,  1328,  1333,  1337,  1339,
    1345,  1353,  1354,  1357,  1358,  1360,  1362,  1364,  1366,  1370,
    1372,  1375,  1379,  1381,  1384,  1387,  1391,  1394,  1398,  1402,
    1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,
    1430,  1436,  1442,  1448,  1454,  1458,  1463,  1468,  1473,  1478,
    1483,  1488,  1493,  1498,  1502,  1507,  1509,  1511,  1515,  1517,
    1520,  1525,  1528,  1530,  1534,  1540,  1546,  1551,  1557,  1559,
    1561,  1563,  1565,  1567,  1569,  1575,  1579,  1585,  1589,  1591,
    1595,  1597,  1599,  1602,  1605,  1607,  1609,  1613,  1615,  1619,
    1625,  1629,  1635,  1643,  1645,  1649,  1653,  1655,  1657,  1661,
    1667,  1671,  1677,  1685,  1689,  1691,  1693,  1697,  1703,  1707,
    1713,  1721,  1723,  1725,  1727,  1730,  1732,  1734,  1735,  1737,
    1739,  1743,  1745,  1747,  1749,  1750,  1752,  1754,  1756,  1758,
    1760,  1762,  1764,  1767,  1769,  1771,  1772,  1774,  1777,  1779,
    1783,  1785,  1789,  1795,  1797,  1799,  1802,  1804,  1806,  1808,
    1810,  1812,  1814,  1816,  1818,  1822,  1826,  1830,  1834,  1836,
    1839,  1841,  1843,  1845,  1847,  1849,  1851,  1853,  1855,  1859,
    1863,  1867,  1873,  1879,  1884,  1891,  1900,  1909,  1916,  1925,
    1936,  1947,  1949,  1953,  1955,  1957,  1959,  1962,  1965,  1968,
    1969
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     460,     0,    -1,   177,   451,   257,   255,    -1,    -1,    86,
     455,    -1,   195,   366,    -1,    -1,    86,   455,    -1,   195,
     366,    -1,    49,   262,   146,   168,   159,   263,   146,    -1,
      45,   263,   146,    -1,    46,   263,   146,    -1,   215,   258,
      -1,    48,   263,    -1,    47,   263,    -1,   261,    -1,   258,
     223,   261,    -1,   260,    -1,   233,   260,    -1,   454,   392,
      -1,   454,   237,   454,   392,    -1,   454,   237,   454,   237,
     454,   392,    -1,   454,   237,   191,    -1,   259,   168,   264,
      -1,   259,    -1,   262,   223,   259,    -1,   264,    -1,   263,
     223,   264,    -1,   439,    -1,   179,    -1,   266,    -1,    91,
     451,    -1,   128,   451,    -1,   114,   453,    -1,    38,   454,
      -1,   277,    -1,   268,    -1,    94,   451,   159,   282,   146,
     269,    -1,    82,   451,   159,   282,   146,   278,   269,   278,
      -1,    -1,   270,    -1,   271,    -1,   270,   271,    -1,   238,
     272,    -1,   104,     3,    -1,    44,     3,    -1,    61,    -1,
      62,    -1,     4,    -1,    -1,   274,    -1,   275,    -1,   274,
     275,    -1,   238,   272,    -1,   246,     3,    -1,    24,    -1,
      25,    -1,   451,    -1,    72,   453,   239,   276,   159,   280,
     146,   273,    -1,    71,   453,   239,   276,   159,   280,   146,
     273,    -1,    73,   453,   239,   276,   159,   280,   146,   273,
      -1,    74,   453,   239,   276,   159,   280,   146,   273,    -1,
      50,   464,    -1,    51,   464,    -1,    90,   451,   226,   451,
      -1,    40,   451,   238,     6,    -1,    39,   451,    -1,    54,
     451,    -1,    36,   451,    -1,    37,   454,    -1,    -1,   111,
      -1,    -1,   111,    -1,   281,    -1,   280,   223,   281,    -1,
     454,   220,    -1,   454,   199,    -1,   454,    -1,   283,    -1,
     282,   223,   283,    -1,   346,    -1,   344,    -1,    42,   454,
     285,    -1,    43,   453,    69,    -1,    43,   453,    70,    -1,
     286,    -1,   285,   223,   286,    -1,   287,    -1,   290,    -1,
     293,    -1,   298,    -1,   301,    -1,   297,    -1,   296,    -1,
     216,   288,    -1,   216,   159,   289,   146,    -1,   283,    -1,
     283,   242,   454,    -1,   288,    -1,   289,   223,   288,    -1,
     201,   292,    -1,   201,   159,   291,   146,    -1,   292,    -1,
     291,   223,   292,    -1,   454,    -1,   167,   295,    -1,   167,
     159,   294,   146,    -1,   295,    -1,   294,   223,   295,    -1,
     283,    -1,    61,    -1,    62,    -1,    60,     3,    -1,    52,
     344,   300,    -1,    52,   159,   299,   146,    -1,   344,   300,
      -1,   299,   223,   344,   300,    -1,    -1,    55,   454,    -1,
      53,   302,    -1,    53,   159,   302,   146,    -1,   303,    -1,
     302,   223,   303,    -1,   454,    -1,    99,    -1,    -1,   106,
     306,   451,   309,   307,    -1,    -1,   178,   308,   159,   312,
     146,    -1,   433,    -1,    -1,   159,   310,   146,    -1,   311,
      -1,   310,   223,   311,    -1,   454,    -1,   454,   237,   454,
      -1,   313,    -1,   312,   223,   313,    -1,   439,    -1,   179,
      -1,   103,   451,   256,    -1,   113,    -1,   122,    -1,    -1,
     129,    -1,   319,    -1,    31,   454,    32,     6,    30,    -1,
      31,   454,    32,     6,    -1,    33,    -1,    26,    -1,    27,
      -1,    79,   454,    -1,    93,    -1,   316,    -1,   315,    -1,
     304,    -1,   318,    -1,   352,    -1,   356,    -1,   403,    -1,
     265,    -1,   267,    -1,   284,    -1,   186,   325,   239,   451,
     241,   330,   324,    -1,   172,   325,   239,   451,   203,   330,
      -1,   186,   323,   241,   330,    -1,   172,   323,   203,   330,
      -1,   147,    -1,   141,    -1,   225,    -1,    -1,    84,    -1,
     235,   391,    -1,    89,    -1,   217,    -1,   326,    -1,   327,
      -1,   326,   223,   327,    -1,   174,   328,    -1,   165,    -1,
     160,    -1,   177,   328,    -1,   181,    -1,   187,    -1,    -1,
     159,   329,   146,    -1,   393,    -1,   329,   223,   393,    -1,
     331,    -1,   330,   223,   331,    -1,   171,    -1,   391,    -1,
     102,   451,   333,   235,   424,   335,    -1,    -1,   159,   334,
     146,    -1,   393,    -1,   334,   223,   393,    -1,    -1,    83,
      -1,   182,   159,   423,   146,    -1,   105,   159,   339,   146,
     338,    -1,   119,   340,    -1,   341,    -1,   451,    -1,   451,
     159,   341,   146,    -1,   393,    -1,   341,   223,   393,    -1,
     176,   159,   343,   146,    -1,   134,   159,   343,   146,    -1,
     109,   159,   343,   146,    -1,   393,    -1,   343,   223,   393,
      -1,   342,    -1,   337,    -1,   336,    -1,   150,   398,    -1,
      97,    -1,    96,    -1,    95,    -1,   454,   382,   347,   348,
      -1,    -1,   345,    -1,    -1,   349,    -1,   350,    -1,   349,
     350,    -1,   351,   300,    -1,   140,    -1,    87,    -1,   176,
      -1,   134,    -1,   338,    -1,   182,   159,   423,   146,    -1,
     109,    -1,    77,   353,   355,    -1,   354,    -1,   391,    -1,
     356,    -1,   355,   356,    -1,   332,    -1,   322,    -1,   164,
     366,    -1,   195,   366,    -1,   203,   360,    -1,   362,    -1,
     360,   223,   362,    -1,   360,   223,   193,   362,    -1,   360,
     223,   193,   159,   360,   146,    -1,   360,    22,   361,   239,
     366,    -1,   360,    23,   361,   239,   366,    -1,   360,    -1,
     159,   360,   146,    -1,   451,    -1,   451,   397,    -1,   451,
     235,   397,    -1,    -1,   359,   364,    -1,   365,    -1,   358,
     365,    -1,    -1,   420,    -1,   420,   357,    -1,   357,    -1,
     367,    -1,   366,   240,   367,    -1,   368,    -1,   367,   218,
     368,    -1,   369,    -1,   231,   369,    -1,   379,    -1,   159,
     366,   146,    -1,   162,   434,    -1,   118,   434,    -1,    -1,
     161,   375,    -1,    -1,   161,   375,    -1,    -1,   161,   375,
      -1,   477,    -1,   398,    -1,    -1,   231,    -1,   439,   376,
     143,    -1,   439,   376,   107,    -1,   439,   378,   439,    -1,
     439,   168,   439,    -1,   439,   168,   179,    -1,   439,   376,
     145,   439,   218,   439,    -1,   439,   206,   374,   373,    -1,
     439,   138,   374,   373,    -1,   439,   245,   374,   372,    -1,
     439,   139,   374,   372,    -1,   439,   153,   374,   371,    -1,
     439,   108,   374,   371,    -1,   169,    -1,   188,    -1,   156,
      -1,   244,    -1,   144,    -1,   130,    -1,   377,    -1,   446,
      -1,   370,    -1,   439,    -1,    -1,   217,    -1,   134,    -1,
     176,    -1,    -1,   217,    -1,   134,    -1,   176,    -1,   383,
      -1,   384,    -1,   385,    -1,   387,    -1,   124,    -1,   124,
     159,   388,   146,    -1,   175,    -1,   175,   159,     3,   146,
      -1,   152,    -1,   152,   159,     3,   146,    -1,   149,    -1,
     149,   159,   389,   386,   146,    -1,   189,   159,   389,   386,
     146,    -1,   189,    -1,   198,    -1,   151,    -1,   142,    -1,
     125,    -1,   125,   159,   388,   146,    -1,   126,    -1,   126,
     159,     3,   146,    -1,   126,   159,     3,   223,     3,   146,
      -1,   133,   400,   241,   401,    -1,   133,    -1,   137,   400,
     241,   401,    -1,   425,    -1,   137,    -1,   137,   400,   159,
       3,   146,   241,   401,    -1,   209,    -1,   196,    -1,   154,
      -1,   154,   159,     3,   146,    -1,   154,   159,     3,   223,
       3,   146,    -1,    -1,   223,   390,    -1,   185,   159,   389,
     146,    -1,   207,    -1,   121,    -1,   185,    -1,    58,    -1,
       3,    -1,     3,    -1,     3,    -1,   454,    -1,     6,    -1,
      -1,   170,     3,   155,    -1,   170,     3,   223,     3,   155,
      -1,   396,    -1,   233,   396,    -1,   395,    -1,   233,   395,
      -1,   454,   392,    -1,   449,   237,   454,   392,    -1,   449,
     237,   191,    -1,   249,    -1,   454,   392,    -1,   449,   237,
     454,   392,    -1,   454,   237,   454,   237,   454,   392,    -1,
     449,   237,   191,    -1,   454,    -1,     6,    -1,   456,    -1,
       3,    -1,   414,    -1,    -1,   400,   241,   401,    -1,   213,
      -1,   190,    -1,   224,    -1,   204,    -1,   166,    -1,   173,
      -1,   135,    -1,   213,    -1,   190,    -1,   224,    -1,   204,
      -1,   166,    -1,   173,    -1,   135,    -1,   135,   159,     3,
     146,    -1,    41,   454,   159,   146,    -1,    41,   454,   159,
     443,   146,    -1,   408,    -1,   407,    -1,   404,    -1,   402,
      -1,   123,   405,   241,   405,    -1,   120,   449,   237,   406,
     241,   406,    -1,   454,    -1,   454,    -1,    98,   451,    -1,
     117,   451,   409,    -1,   112,    -1,    92,    -1,   411,    -1,
     411,   400,   241,   401,    -1,    34,    -1,   413,    -1,   413,
     400,   159,     3,   146,   241,   401,    -1,   413,   400,   241,
     401,    -1,    35,    -1,   148,   399,    -1,   192,   236,   416,
      -1,   417,    -1,   416,   223,   417,    -1,   418,   419,    -1,
       3,    -1,   394,    -1,    -1,   220,    -1,   199,    -1,   136,
     421,    -1,   422,    -1,   421,   223,   422,    -1,   394,    -1,
       3,    -1,   366,    -1,   433,    -1,   247,    -1,   247,   159,
       3,   146,    -1,   250,    -1,   250,   159,     3,   146,    -1,
      -1,    -1,   174,   435,   436,   427,   437,   428,   458,   363,
     430,   431,    -1,   174,   435,   436,   437,   363,   430,    -1,
      -1,   194,   381,   429,    -1,    -1,   415,    -1,   415,   131,
     432,   279,    -1,   131,   432,   279,    -1,   454,    -1,   174,
     435,   436,   437,   363,    -1,   159,   174,   435,   436,   437,
     363,   146,    -1,    -1,   184,     3,    -1,    -1,   217,    -1,
     134,    -1,   176,    -1,   438,    -1,   437,   223,   438,    -1,
     439,    -1,   439,   454,    -1,   439,   235,   454,    -1,   477,
      -1,   229,   477,    -1,   234,   477,    -1,   477,   200,   439,
      -1,   477,   445,    -1,   477,   191,   439,    -1,   477,   234,
     439,    -1,   477,   229,   439,    -1,   398,    -1,   180,    -1,
     157,    -1,   211,    -1,   248,    -1,   249,    -1,   247,    -1,
     191,    -1,    59,    -1,   221,   159,   380,   439,   146,    -1,
     227,   159,   380,   439,   146,    -1,   228,   159,   380,   439,
     146,    -1,   232,   159,   380,   439,   146,    -1,   183,   159,
     380,   439,   146,    -1,     4,   159,   146,    -1,     4,   159,
     443,   146,    -1,   213,   159,   443,   146,    -1,   190,   159,
     443,   146,    -1,   224,   159,   443,   146,    -1,    28,   159,
     443,   146,    -1,    29,   159,   443,   146,    -1,   214,   159,
     443,   146,    -1,   198,   159,   443,   146,    -1,   159,   439,
     146,    -1,   163,   159,   444,   146,    -1,   410,    -1,   412,
      -1,   197,   441,   243,    -1,   442,    -1,   441,   442,    -1,
     212,   366,   210,   439,    -1,   202,   439,    -1,   439,    -1,
     443,   223,   439,    -1,   148,   223,   400,   241,   401,    -1,
     470,   223,   400,   241,   401,    -1,   148,   400,   241,   401,
      -1,   439,   223,   400,   241,   401,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,   439,
     238,   159,   447,   146,    -1,   439,   238,   434,    -1,   439,
     158,   159,   447,   146,    -1,   439,   158,   434,    -1,   448,
      -1,   447,   223,   448,    -1,   470,    -1,   398,    -1,   229,
       3,    -1,   229,   456,    -1,   450,    -1,     6,    -1,     6,
     237,   454,    -1,   454,    -1,   454,   222,   454,    -1,   454,
     222,     6,   237,   454,    -1,   454,   233,   454,    -1,   454,
     233,   454,   222,   454,    -1,   454,   233,   454,   222,     6,
     237,   454,    -1,   452,    -1,     6,   237,   454,    -1,   454,
     237,   454,    -1,     6,    -1,   454,    -1,   454,   222,   454,
      -1,   454,   222,     6,   237,   454,    -1,   454,   233,   454,
      -1,   454,   233,   454,   222,   454,    -1,   454,   233,   454,
     222,     6,   237,   454,    -1,     6,   237,   454,    -1,     6,
      -1,   454,    -1,   454,   222,   454,    -1,   454,   222,     6,
     237,   454,    -1,   454,   233,   454,    -1,   454,   233,   454,
     222,   454,    -1,   454,   233,   454,   222,     6,   237,   454,
      -1,     4,    -1,     4,    -1,    15,    -1,   237,     3,    -1,
       4,    -1,     6,    -1,    -1,   454,    -1,   462,    -1,   460,
      16,   462,    -1,   305,    -1,   254,    -1,   314,    -1,    -1,
     471,    -1,   321,    -1,   463,    -1,   469,    -1,   461,    -1,
     320,    -1,     1,    -1,   465,   466,    -1,   459,    -1,   426,
      -1,    -1,   116,    -1,   115,   467,    -1,   468,    -1,   467,
     223,   468,    -1,   454,    -1,   454,   237,   454,    -1,     6,
     237,   454,   237,   454,    -1,   101,    -1,   100,    -1,    88,
     479,    -1,    85,    -1,    81,    -1,    78,    -1,    76,    -1,
      80,    -1,   476,    -1,    17,    -1,   472,    -1,   132,   457,
     317,    -1,    20,     6,    21,    -1,   159,   473,   146,    -1,
     473,   474,   473,    -1,     3,    -1,   475,     3,    -1,   234,
      -1,   229,    -1,   191,    -1,   200,    -1,   230,    -1,   234,
      -1,   229,    -1,   454,    -1,   454,   237,   191,    -1,   454,
     237,   249,    -1,   454,   237,   454,    -1,   454,   237,   454,
     237,   454,    -1,     6,   237,   454,   237,   454,    -1,   454,
     170,   473,   155,    -1,   454,   237,   454,   170,   473,   155,
      -1,   454,   237,   454,   237,   454,   170,   473,   155,    -1,
       6,   237,   454,   237,   454,   170,   473,   155,    -1,   454,
     170,   473,   223,   473,   155,    -1,   454,   237,   454,   170,
     473,   223,   473,   155,    -1,   454,   237,   454,   237,   454,
     170,   473,   223,   473,   155,    -1,     6,   237,   454,   237,
     454,   170,   473,   223,   473,   155,    -1,   478,    -1,   478,
      75,   382,    -1,   440,    -1,   470,    -1,   434,    -1,   217,
     434,    -1,   219,   434,    -1,   208,   434,    -1,    -1,     3,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   402,   402,   428,   431,   448,   453,   456,   473,   479,
     488,   497,   506,   513,   528,   583,   590,   601,   604,   609,
     616,   633,   650,   671,   680,   683,   691,   694,   702,   703,
     710,   713,   721,   724,   728,   734,   735,   739,   749,   763,
     764,   768,   769,   774,   782,   790,   798,   806,   816,   818,
     818,   821,   822,   826,   833,   840,   847,   856,   860,   867,
     879,   890,   896,   900,   904,   909,   913,   916,   920,   923,
     930,   931,   941,   942,   946,   947,   951,   960,   969,   976,
     979,   985,   988,   999,  1003,  1008,  1015,  1018,  1027,  1030,
    1034,  1038,  1042,  1046,  1050,  1058,  1062,  1070,  1073,  1080,
    1083,  1090,  1093,  1100,  1101,  1106,  1110,  1113,  1119,  1122,
    1128,  1135,  1136,  1140,  1148,  1152,  1159,  1161,  1166,  1167,
    1171,  1173,  1179,  1180,  1183,  1194,  1200,  1200,  1209,  1209,
    1218,  1243,  1246,  1254,  1257,  1264,  1267,  1275,  1276,  1282,
    1283,  1291,  1309,  1313,  1318,  1319,  1329,  1338,  1342,  1346,
    1351,  1355,  1359,  1362,  1369,  1370,  1371,  1375,  1376,  1377,
    1378,  1379,  1380,  1381,  1389,  1390,  1391,  1392,  1397,  1398,
    1399,  1402,  1403,  1404,  1408,  1409,  1410,  1414,  1415,  1419,
    1426,  1427,  1428,  1435,  1436,  1439,  1440,  1445,  1446,  1451,
    1452,  1457,  1458,  1463,  1470,  1471,  1476,  1477,  1481,  1482,
    1489,  1497,  1504,  1511,  1515,  1516,  1521,  1522,  1528,  1532,
    1537,  1544,  1545,  1551,  1554,  1557,  1564,  1565,  1566,  1567,
    1573,  1594,  1595,  1598,  1600,  1607,  1610,  1616,  1624,  1629,
    1635,  1640,  1646,  1649,  1654,  1662,  1671,  1676,  1680,  1681,
    1687,  1690,  1701,  1710,  1717,  1723,  1724,  1727,  1732,  1743,
    1747,  1754,  1755,  1759,  1763,  1767,  1774,  1779,  1787,  1790,
    1796,  1799,  1804,  1809,  1822,  1825,  1831,  1834,  1840,  1843,
    1849,  1852,  1859,  1863,  1874,  1874,  1875,  1875,  1876,  1876,
    1879,  1884,  1889,  1890,  1895,  1904,  1912,  1915,  1918,  1922,
    1929,  1932,  1936,  1939,  1942,  1945,  1951,  1958,  1961,  1964,
    1967,  1968,  1973,  1976,  1979,  1982,  1989,  1990,  1991,  1995,
    2002,  2003,  2004,  2008,  2022,  2029,  2030,  2031,  2035,  2036,
    2041,  2042,  2051,  2053,  2062,  2065,  2073,  2083,  2091,  2093,
    2094,  2095,  2096,  2097,  2098,  2099,  2107,  2108,  2109,  2110,
    2111,  2112,  2113,  2114,  2115,  2116,  2117,  2127,  2128,  2134,
    2136,  2137,  2138,  2139,  2143,  2147,  2151,  2158,  2159,  2164,
    2165,  2169,  2177,  2180,  2187,  2190,  2200,  2203,  2206,  2209,
    2216,  2223,  2231,  2240,  2247,  2251,  2252,  2253,  2254,  2259,
    2261,  2270,  2270,  2270,  2270,  2270,  2270,  2270,  2271,  2271,
    2271,  2271,  2271,  2271,  2271,  2271,  2286,  2294,  2306,  2307,
    2308,  2309,  2314,  2315,  2318,  2319,  2323,  2330,  2341,  2342,
    2355,  2356,  2360,  2364,  2365,  2368,  2374,  2378,  2401,  2411,
    2414,  2420,  2429,  2433,  2440,  2441,  2443,  2448,  2454,  2457,
    2463,  2464,  2471,  2484,  2494,  2501,  2518,  2525,  2550,  2552,
    2550,  2574,  2618,  2619,  2633,  2636,  2643,  2653,  2665,  2671,
    2684,  2699,  2701,  2707,  2708,  2709,  2710,  2720,  2723,  2729,
    2732,  2737,  2746,  2749,  2753,  2760,  2763,  2766,  2769,  2772,
    2775,  2776,  2777,  2778,  2779,  2780,  2781,  2782,  2783,  2785,
    2789,  2793,  2797,  2801,  2805,  2809,  2813,  2816,  2819,  2822,
    2825,  2828,  2831,  2834,  2837,  2841,  2845,  2849,  2857,  2860,
    2869,  2875,  2882,  2885,  2913,  2916,  2919,  2922,  2928,  2929,
    2930,  2931,  2932,  2933,  2938,  2942,  2946,  2950,  2957,  2960,
    2965,  2966,  2967,  2969,  2975,  2985,  2989,  2993,  2997,  3001,
    3005,  3009,  3013,  3021,  3031,  3036,  3040,  3044,  3048,  3052,
    3057,  3061,  3065,  3073,  3076,  3081,  3082,  3083,  3088,  3089,
    3090,  3098,  3101,  3106,  3107,  3111,  3112,  3117,  3141,  3158,
    3159,  3163,  3170,  3176,  3186,  3188,  3191,  3192,  3193,  3194,
    3196,  3199,  3203,  3208,  3212,  3218,  3219,  3222,  3227,  3228,
    3231,  3232,  3233,  3243,  3244,  3245,  3246,  3247,  3248,  3249,
    3250,  3254,  3260,  3262,  3281,  3289,  3296,  3297,  3298,  3299,
    3304,  3305,  3306,  3307,  3308,  3313,  3314,  3330,  3331,  3332,
    3333,  3334,  3335,  3336,  3337,  3338,  3339,  3341,  3342,  3343,
    3344,  3349,  3352,  3361,  3362,  3363,  3364,  3365,  3366,  3370,
    3371
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VALUE", "NAMED", "NAMED_GEN",
  "CHAR_VALUE", "NOT_USED_1", "NOT_USED_2", "NOT_USED_3", "NOT_USED_4",
  "NOT_USED_5", "NOT_USED_6", "NOT_USED_7", "NOT_USED_8", "NUMBER_VALUE",
  "SEMICOLON", "QUESTION_MARK", "CLINE", "CH", "MARK_VAR", "END_MARK_VAR",
  "LEFT_JOIN", "INNER_JOIN", "USING_BTREE", "USING_RTREE",
  "SET_BUFFERED_LOG", "SET_LOG", "MDY", "WEEKDAY", "MODE_ANSI",
  "START_DATABASE", "WITH_LOG_IN", "SET_CONSTRAINTS_ALL_IMMEDIATE",
  "DATETIME_VALUE", "INTERVAL_VALUE", "RECOVER_TABLE",
  "ROLLFORWARD_DATABASE", "DROP_TRIGGER", "DROP_AUDIT_FOR",
  "CREATE_AUDIT_FOR", "EXECUTE_PROCEDURE", "ALTER_TABLE", "ALTER_INDEX",
  "NEXT_SIZE", "XSET_MULTIPLY_EQUAL_OPEN_BRACKET",
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET",
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL",
  "XSET_OPEN_BRACKET", "CREATE_DATABASE", "DROP_DATABASE",
  "ADD_CONSTRAINT", "DROP_CONSTRAINT", "DROP_SYNONYM", "CONSTRAINT",
  "NOT_FIELD_TOUCHED_CURRENT", "FIELD_TOUCHED_CURRENT", "DOUBLE_PRECISION",
  "COUNT_MULTIPLY", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", "LOCK_MODE_ROW",
  "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE",
  "UNITS_SECOND", "TO_CLUSTER", "TO_NOT_CLUSTER", "CREATE_UC_IDX",
  "CREATE_U_IDX", "CREATE_C_IDX", "CREATE_IDX", "DOUBLE_COLON", "SQLSICS",
  "CREATE_SCHEMA", "SQLSIRR", "UPDATESTATS_T", "SQLSICR", "SQLSIDR",
  "CREATE_TEMP_TABLE", "WITH_CHECK_OPTION", "WITH_GRANT_OPTION",
  "SQLSLMNW", "WHERE_CURRENT_OF", "NOT_NULL_UNIQUE", "SQLSLMW",
  "ALL_PRIVILEGES", "CREATE_SYNONYM", "DROP_TABLE", "INEXCLUSIVE",
  "UPDATESTATS", "CREATE_TABLE", "DEFAULT_NULL", "DEFAULT_TODAY",
  "DEFAULT_USER", "UNLOCK_TABLE", "ROLLBACK_W", "SQLSEON", "SQLSEOFF",
  "CREATE_VIEW", "DELETE_FROM", "EXTENT_SIZE", "FOREIGN_KEY",
  "INSERT_INTO", "IS_NOT_NULL", "NOT_MATCHES", "PRIMARY_KEY",
  "USE_SESSION", "WITH_NO_LOG", "INSHARE", "BEGIN_WORK", "DROP_INDEX",
  "FOR_UPDATE_OF", "FOR_UPDATE", "LOCK_TABLE", "NOT_EXISTS", "REFERENCES",
  "RENCOL", "SMALLFLOAT", "COMMIT_W", "RENTAB", "KW_CHAR", "NCHAR",
  "NVARCHAR", "DELIMITER", "DROP_VIEW", "EXCLUSIVE", "GREATER_THAN_EQ",
  "INTO_TEMP", "DATABASE", "DATETIME", "DISTINCT", "FRACTION", "GROUP_BY",
  "INTERVAL", "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", "RESOURCE", "SMALLINT",
  "IS_NULL", "LESS_THAN_EQ", "BETWEEN", "CLOSE_BRACKET", "CONNECT",
  "KW_CURRENT", "KW_DECIMAL", "DEFAULT", "INTEGER", "SERIAL8", "MATCHES",
  "VARCHAR", "CLOSE_SQUARE", "GREATER_THAN", "KW_FALSE", "NOT_IN",
  "OPEN_BRACKET", "KW_DELETE", "KW_ESCAPE", "EXISTS", "EXTEND", "HAVING",
  "KW_INSERT", "MINUTE", "MODIFY", "EQUAL", "NOT_EQUAL", "OPEN_SQUARE",
  "PUBLIC", "REVOKE", "SECOND", "KW_SELECT", "SERIAL", "UNIQUE",
  "KW_UPDATE", "VALUES", "KW_NULL", "KW_TRUE", "ALTER", "CHECK", "COUNT",
  "KW_FIRST", "KW_FLOAT", "GRANT", "INDEX", "LESS_THAN", "MONEY", "MONTH",
  "KW_MULTIPLY", "ORDER", "OUTER", "UNION", "WHERE", "KW_BYTE", "CASE",
  "KW_DATE", "DESC", "KW_DIVIDE", "DROP", "ELSE", "FROM", "HOUR", "INTO",
  "LIKE", "REAL", "SOME", "KW_TEXT", "KW_THEN", "USER", "WHEN", "YEAR",
  "KW_DOW", "XSET", "ADD", "ALL", "KW_AND", "ANY", "ASC", "AVG", "COLON",
  "KW_COMMA", "DAY", "DBA", "KW_FOR", "XMAX", "XMIN", "KW_MINUS", "KW_MOD",
  "KW_NOT", "KW_SUM", "ATSIGN", "KW_PLUS", "KW_AS", "KW_BY", "KW_DOT",
  "KW_IN", "KW_ON", "KW_OR", "KW_TO", "BEFORE", "END", "TILDE", "ILIKE",
  "FILLFACTOR", "TIME", "KW_TODAY", "KW_ROWID", "TIMESTAMP", "KW_TAG",
  "LINTMODULEISLIBRARY", "$accept", "update_statement_c", "where_upd_p",
  "where_del_p", "set_clause_list_uc", "upd_columns_uc", "upd_column_name",
  "upd_column_name_specific", "col_1_up", "upd_col_list_sl",
  "upd_val_list_slil", "upd_val_sli", "drops_statement", "drops_c",
  "create_statement_ss", "create_c_2_ss", "opt_cr_table_extra",
  "cr_table_extra", "cr_table_extra_entry", "space_name",
  "op_cr_index_extra", "cr_index_extra", "cr_index_extra_entry",
  "cr_table_name", "create_c_1", "op_no_log", "op_no_log_i",
  "idx_column_list", "idx_column", "table_element_list_ss",
  "table_element_ss", "alter_statement_ss", "alter_clauses_ss",
  "alter_clause_ss", "alter_add_clause_ss", "add_column_clause_ss",
  "add_column_clauses_ss", "alter_drop_clause", "drop_column_list",
  "drop_column", "alter_modify_clause_ss", "modify_column_clauses_ss",
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next",
  "alter_add_constraint_clause", "table_constraint_definition_list_ss",
  "opt_constraint_name", "alter_drop_constraint_clause",
  "constraint_names", "constraint_name", "rollback_statement",
  "insert_statement_c", "$@1", "ins_2_ic", "$@2",
  "op_insert_column_list_sl", "insert_column_list_sl", "ins_column_name",
  "insert_value_list_slil", "insert_value_sli", "delete_statement_c",
  "begin_statement", "commit_statement", "op_db_exclusive",
  "misc_infx_stmt", "misc_infx_stmt_str", "sql_transact_commands",
  "sql_commands", "privilege_definition", "db_priv",
  "op_with_grant_option", "privileges", "action_list", "action",
  "op_grant_column_list", "grant_column_list", "grantee_list", "grantee",
  "view_definition_ss", "op_view_column_list", "view_column_list",
  "op_with_check_option", "check_constraint_definition_ss",
  "referential_constraint_definition", "references_specification",
  "references_columns", "referenced_table_and_columns",
  "references_column_list", "unique_constraint_definition",
  "unique_column_list", "table_constraint_definition_ss", "default_clause",
  "ct_column_definiton_ss", "op_default_clause",
  "op_column_constraint_list_ss", "column_constraint_list_ss",
  "column_constraint_ss", "column_constraint_ss_1", "schema_ss",
  "schema_authorization_clause", "schema_authorization_identifier",
  "schema_element_list_ss", "schema_element_ss", "having_clause_sli",
  "where_clause_sli", "from_clause_ts", "table_reference_list",
  "op_bracket_table_reference_list", "tname", "table_expression_2_select",
  "op_where_clause_2_select", "op_group_by_clause_2_select",
  "search_condition_sli", "boolean_term_sli", "boolean_factor_sli",
  "boolean_primary_sli", "exists_predicate_sli", "op_matches_escape",
  "op_ilike_escape", "op_like_escape", "pattern_sli", "escape_character",
  "op_not", "comparison_predicate_sli", "comp_op", "predicate_sli",
  "op_all", "op_u_all", "data_type", "data_type_i", "char_string_type",
  "exact_numeric_type", "op_scale", "approx_numeric_type", "length",
  "precision", "scale", "authorization_identifier", "op_col_arr",
  "column_name", "column_name_sli", "column_name_sli_specific",
  "column_name_specific", "correlation_name", "literal", "cur_part",
  "s_curr", "e_curr", "execute_procedure", "misc_sql", "rename_stmt",
  "rentabname", "rencolname", "unlock_stmt", "lock_stmt",
  "share_or_exclusive", "datetime_value_qualified", "datetime_value",
  "interval_value_qualified", "interval_value", "curr_clause",
  "order_by_clause_slil", "sort_specification_list_slil",
  "sort_specification_sli", "sort_spec_sli", "op_asc_desc",
  "group_by_clause_slil", "gr_column_specification_list_slil",
  "gr_column_specification_sli", "search_condition_sli_as_string",
  "query_specification_ss_converted", "sql_time_dtypes",
  "select_statement_ss_select", "$@3", "$@4", "union_select_statement2_ss",
  "sel_p2_select", "sel_finish_sf", "tmp_tabname",
  "query_specification_select", "subquery_sli", "op_first", "op_ad",
  "select_list_slil", "value_expression_pls_sli", "value_expression_sli",
  "value_expression_complex_sli", "sql_case_stmt", "sql_case_stmt_element",
  "value_expr_list_slil", "extend_qual_sli", "units_qual_i",
  "in_predicate_sli", "in_value_list_slil", "in_value_specification_sli",
  "table_name", "table_name_i", "table_name_not_for_column_prefix",
  "table_name_not_for_column_prefix_i", "idx_name", "identifier",
  "fetch_cursor_name_p", "real_number", "var_ident_qchar", "opt_into_sel",
  "var_ident", "sql_statement", "sql_bound_commands",
  "individual_sql_statement", "select_statement_ss_str_cfu",
  "var_ident_vl", "select_statement_ss_str_converted", "curs_forupdate",
  "cur_update_list", "colident", "set_cmd", "var_ident_ibind_sli",
  "set_database_cmd", "replace_with_variable", "arr_expr", "arr_next_math",
  "arr_int_sign", "column_name_x", "value_expression_initial_sli",
  "value_expression_initial_sli_nocast", "op_fgl_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  2204,  2205,  2206,  2207,  2208,  2209,  2210,  2211,
    2212,  2213,  2214,  2215,  2216,  2217,  2218,  2219,  2220,  2221,
    2222,  2223,  1002,  1005,  1028,  1029,  1054,  1057,  1059,  1060,
    1063,  1064,  1065,  1066,  1079,  1080,  1081,  1082,  1098,  1099,
    1100,  1104,  1111,  1112,  1113,  1150,  1151,  1152,  1153,  1154,
    1157,  1158,  1160,  1161,  1162,  1163,  1166,  1167,  1174,  1175,
    1195,  1196,  1197,  1204,  1205,  1206,  1207,  1208,  1209,  1214,
    1215,  1217,  1218,  1219,  1220,  1230,  1236,  1237,  1238,  1239,
    1240,  1251,  1252,  1260,  1261,  1262,  1268,  1276,  1283,  1285,
    1289,  1290,  1292,  1297,  1323,  1324,  1325,  1326,  1339,  1347,
    1349,  1350,  1354,  1355,  1362,  1363,  1366,  1368,  1371,  1377,
    1384,  1385,  1388,  1394,  1399,  1405,  1406,  1411,  1413,  1415,
    1416,  1418,  1429,  1436,  1439,  1440,  1441,  1443,  1445,  1448,
    1452,  1454,  1478,  1479,  1481,  1488,  1490,  1491,  1493,  1494,
    1495,  1501,  1502,  1508,  1509,  1511,  1514,  1517,  1518,  1520,
    1522,  1530,  1532,  1535,  1548,  1551,  1552,  1553,  1554,  1556,
    1564,  1567,  1568,  1569,  1573,  1575,  1579,  1580,  1582,  1583,
    1585,  1589,  1593,  1597,  1601,  1602,  1605,  1607,  1608,  1611,
    1612,  1614,  1620,  1624,  1629,  1630,  1633,  1636,  1639,  1641,
    1642,  1644,  1645,  1646,  1655,  1658,  1665,  1667,  1669,  1670,
    1671,  1674,  1675,  1679,  1685,  1686,  1689,  1698,  1703,  1707,
    1708,  1709,  1711,  1714,  1715,  1717,  1718,  1719,  1720,  1721,
    1722,  1723,  1724,  1725,  1726,  1727,  1731,  1736,  1737,  1738,
    1739,  1740,  1747,  1750,  1751,  1757,  1759,  1760,  1763,  1765,
    1766,  1767,  1805,  1809,  1816,  1817,  1820,  1825,  1832,  1833,
    2181,  2202,  2203
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   253,   254,   255,   255,   255,   256,   256,   256,   257,
     257,   257,   257,   257,   257,   258,   258,   259,   259,   260,
     260,   260,   260,   261,   262,   262,   263,   263,   264,   264,
     265,   266,   266,   266,   266,   267,   267,   268,   268,   269,
     269,   270,   270,   271,   271,   271,   271,   271,   272,   273,
     273,   274,   274,   275,   275,   275,   275,   276,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     278,   278,   279,   279,   280,   280,   281,   281,   281,   282,
     282,   283,   283,   284,   284,   284,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   287,   287,   288,   288,   289,
     289,   290,   290,   291,   291,   292,   293,   293,   294,   294,
     295,   296,   296,   297,   298,   298,   299,   299,   300,   300,
     301,   301,   302,   302,   303,   304,   306,   305,   308,   307,
     307,   309,   309,   310,   310,   311,   311,   312,   312,   313,
     313,   314,   315,   316,   317,   317,   318,   319,   319,   319,
     319,   319,   319,   319,   320,   320,   320,   321,   321,   321,
     321,   321,   321,   321,   322,   322,   322,   322,   323,   323,
     323,   324,   324,   324,   325,   325,   325,   326,   326,   327,
     327,   327,   327,   327,   327,   328,   328,   329,   329,   330,
     330,   331,   331,   332,   333,   333,   334,   334,   335,   335,
     336,   337,   338,   339,   340,   340,   341,   341,   342,   342,
     342,   343,   343,   344,   344,   344,   345,   345,   345,   345,
     346,   347,   347,   348,   348,   349,   349,   350,   351,   351,
     351,   351,   351,   351,   351,   352,   353,   354,   355,   355,
     356,   356,   357,   358,   359,   360,   360,   360,   360,   360,
     360,   361,   361,   362,   362,   362,   363,   363,   364,   364,
     365,   365,   365,   365,   366,   366,   367,   367,   368,   368,
     369,   369,   370,   370,   371,   371,   372,   372,   373,   373,
     374,   375,   376,   376,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   378,   378,   378,   378,
     378,   378,   379,   379,   379,   379,   380,   380,   380,   380,
     381,   381,   381,   381,   382,   383,   383,   383,   384,   384,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   386,   386,   387,
     387,   387,   387,   387,   388,   389,   390,   391,   391,   392,
     392,   392,   393,   393,   394,   394,   395,   395,   395,   395,
     396,   396,   396,   396,   397,   398,   398,   398,   398,   399,
     399,   400,   400,   400,   400,   400,   400,   400,   401,   401,
     401,   401,   401,   401,   401,   401,   402,   402,   403,   403,
     403,   403,   404,   404,   405,   406,   407,   408,   409,   409,
     410,   410,   411,   412,   412,   412,   413,   414,   415,   416,
     416,   417,   418,   418,   419,   419,   419,   420,   421,   421,
     422,   422,   423,   424,   425,   425,   425,   425,   427,   428,
     426,   429,   430,   430,   431,   431,   431,   431,   432,   433,
     434,   435,   435,   436,   436,   436,   436,   437,   437,   438,
     438,   438,   439,   439,   439,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   441,   441,
     442,   442,   443,   443,   444,   444,   444,   444,   445,   445,
     445,   445,   445,   445,   446,   446,   446,   446,   447,   447,
     448,   448,   448,   448,   449,   450,   450,   450,   450,   450,
     450,   450,   450,   451,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   453,   453,   453,   453,   453,   453,   453,
     453,   454,   455,   456,   456,   457,   457,   458,   459,   460,
     460,   461,   461,   461,   462,   462,   462,   462,   462,   462,
     462,   462,   463,   464,   465,   466,   466,   466,   467,   467,
     468,   468,   468,   469,   469,   469,   469,   469,   469,   469,
     469,   470,   470,   470,   471,   472,   473,   473,   473,   473,
     474,   474,   474,   474,   474,   475,   475,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   477,   477,   478,   478,   478,   478,   478,   478,   479,
     479
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     2,     2,     0,     2,     2,     7,
       3,     3,     2,     2,     2,     1,     3,     1,     2,     2,
       4,     6,     3,     3,     1,     3,     1,     3,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     6,     8,     0,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     1,     1,     1,     8,     8,
       8,     8,     2,     2,     4,     4,     2,     2,     2,     2,
       0,     1,     0,     1,     1,     3,     2,     2,     1,     1,
       3,     1,     1,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     3,     1,
       3,     2,     4,     1,     3,     1,     2,     4,     1,     3,
       1,     1,     1,     2,     3,     4,     2,     4,     0,     2,
       2,     4,     1,     3,     1,     1,     0,     5,     0,     5,
       1,     0,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     3,     1,     1,     0,     1,     1,     5,     4,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     6,     4,     4,     1,     1,
       1,     0,     1,     2,     1,     1,     1,     1,     3,     2,
       1,     1,     2,     1,     1,     0,     3,     1,     3,     1,
       3,     1,     1,     6,     0,     3,     1,     3,     0,     1,
       4,     5,     2,     1,     1,     4,     1,     3,     4,     4,
       4,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       4,     0,     1,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     1,     1,     2,
       1,     1,     2,     2,     2,     1,     3,     4,     6,     5,
       5,     1,     3,     1,     2,     3,     0,     2,     1,     2,
       0,     1,     2,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     2,     2,     0,     2,     0,     2,     0,     2,
       1,     1,     0,     1,     3,     3,     3,     3,     3,     6,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     4,     1,     4,     1,     5,     5,     1,     1,     1,
       1,     1,     4,     1,     4,     6,     4,     1,     4,     1,
       1,     7,     1,     1,     1,     4,     6,     0,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     5,     1,     2,     1,     2,     2,     4,     3,     1,
       2,     4,     6,     3,     1,     1,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     1,     1,
       1,     1,     4,     6,     1,     1,     2,     3,     1,     1,
       1,     4,     1,     1,     7,     4,     1,     2,     3,     1,
       3,     2,     1,     1,     0,     1,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     4,     1,     4,     0,     0,
      10,     6,     0,     3,     0,     1,     4,     3,     1,     5,
       7,     0,     2,     0,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     2,     2,     3,     2,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     1,     1,     3,     1,     2,
       4,     2,     1,     3,     5,     5,     4,     5,     1,     1,
       1,     1,     1,     1,     5,     3,     5,     3,     1,     3,
       1,     1,     2,     2,     1,     1,     3,     1,     3,     5,
       3,     5,     7,     1,     3,     3,     1,     1,     3,     5,
       3,     5,     7,     3,     1,     1,     3,     5,     3,     5,
       7,     1,     1,     1,     2,     1,     1,     0,     1,     1,
       3,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     0,     1,     2,     1,     3,
       1,     3,     5,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     5,     5,     4,     6,     8,     8,     6,     8,    10,
      10,     1,     3,     1,     1,     1,     2,     2,     2,     0,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   571,   150,   151,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   589,     0,   588,     0,   590,   587,     0,   586,   629,
       0,     0,   153,     0,     0,   125,   584,   583,     0,     0,
     126,   142,     0,     0,     0,   143,     0,     0,     0,     0,
     451,     0,     0,   562,   161,    30,   162,    36,    35,   163,
     156,   561,   563,   155,   154,   157,   146,   570,   566,   241,
     240,   158,   159,   401,   160,   400,   399,   398,   574,     0,
     569,   559,   567,   575,   568,   565,   551,     0,   536,    68,
     533,   537,    69,    34,    66,     0,     0,     0,   544,     0,
     545,   558,   573,    62,    63,    67,     0,     0,     0,     0,
     358,     0,   236,   237,   357,   152,     0,   630,   585,     0,
      31,     0,   406,   194,     6,     0,    33,     0,     0,     0,
     524,   527,     0,   404,    32,   555,   556,   144,   174,   169,
     168,   181,   180,   185,   185,   183,   184,   175,   170,     0,
       0,   176,   177,     0,   453,     0,     0,     0,     1,     0,
       0,   576,   572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,   112,     0,     0,     0,    83,    86,
      88,    89,    90,    94,    93,    91,    92,     0,    84,    85,
       0,     0,     0,     0,     0,     0,   235,   238,     0,     0,
       0,     0,     0,     0,     0,   141,   131,   409,   408,   407,
       0,     0,     0,     0,     0,   145,   594,     0,   179,   182,
       0,     0,     0,   452,   455,   456,   454,   438,     0,     0,
       0,     0,     0,     0,     3,     0,     0,   560,     0,   580,
     577,   578,   148,   534,     0,   538,   540,   535,    65,   377,
     551,   375,   553,   592,     0,     0,     0,   412,   416,   478,
     396,   379,   472,     0,     0,   471,     0,     0,   477,     0,
       0,     0,   473,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   476,   474,   475,   470,   495,
     410,   496,   413,   378,   625,   502,   623,     0,   607,   376,
     624,   593,   591,   462,   621,     0,     0,     0,     0,     0,
       0,   215,   214,   213,   118,     0,   120,   122,   124,   113,
       0,   110,   106,    82,    81,     0,     0,   101,   105,     0,
      97,    95,     0,   543,     0,   546,   548,     0,    57,     0,
       0,     0,   239,     0,    79,    64,     0,     0,     0,   196,
     362,     0,   359,     0,   552,     7,     0,     0,     0,     0,
       8,   264,   266,   268,   304,   302,   270,   305,   303,     0,
       0,   526,     0,   405,     0,   528,   530,   402,     0,   187,
     191,   167,   189,   192,     0,   178,     0,    29,     0,    26,
      28,     0,    14,    13,     0,    24,    17,     0,   359,    12,
       0,    15,     0,     0,     2,   166,     0,     0,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   387,   385,
     386,   382,   384,   381,   383,   417,     0,   451,     0,     0,
     306,     0,     0,     0,     0,   498,     0,     0,   628,     0,
       0,   626,   627,   306,     0,   306,   306,   463,   306,   464,
     554,     0,     0,   397,     0,     0,     0,   508,   509,   510,
     511,   512,   513,     0,     0,     0,     0,   466,     0,     0,
       0,     0,     0,   118,     0,     0,     0,   114,     0,     0,
       0,   108,   353,   351,   318,   331,   333,   337,   340,   330,
     324,   329,   322,   344,   320,   352,   327,   343,   328,   350,
     342,   434,   436,   221,   314,   315,   316,   317,   339,     0,
     103,    99,     0,     0,    87,     0,     0,     0,     0,     0,
       0,    70,     0,    39,   363,   195,     0,     0,     0,     0,
     370,   451,   198,   433,   273,     0,   282,   272,   269,     0,
       0,     0,   301,     0,     0,   300,     0,   298,     0,     0,
     296,   297,     0,   283,     0,   299,     0,     0,     0,     0,
     133,   135,   128,   127,   130,     0,     0,     0,   186,     0,
       0,     0,   439,   457,   459,    10,     0,    11,    18,     0,
       0,     0,    19,     0,     0,     4,     5,     0,     0,   581,
     579,   539,     0,   541,   484,     0,     0,   595,     0,     0,
       0,   453,   493,   379,     0,     0,   624,   308,   309,   307,
       0,     0,   501,     0,   497,   499,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,   598,     0,
     606,   605,     0,     0,   608,   609,   610,   467,   465,   469,
     468,   622,     0,   203,   206,     0,   211,     0,   115,     0,
     116,     0,   432,     0,   119,   121,   123,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   218,   217,     0,   222,   223,   102,     0,
      96,     0,    98,   547,     0,   549,     0,    74,    78,     0,
       0,     0,    71,    39,    80,     0,    46,    47,     0,     0,
      37,    40,    41,   197,   373,   359,     0,     0,   453,   199,
     193,   271,   265,   267,   274,   280,   278,   276,   274,     0,
     517,   288,   287,   278,     0,   515,   276,   285,   284,     0,
     286,   132,     0,     0,     0,   403,   529,     0,   531,   188,
     190,   165,     0,   557,     0,   460,    27,     0,    25,    22,
     359,    16,    23,   171,     0,     0,   485,     0,   489,   490,
     394,   392,   393,   389,   391,   388,   390,   380,     0,     0,
       0,     0,   494,     0,     0,   487,     0,   492,   486,   491,
       0,   488,     0,     0,     0,   411,     0,   415,     0,   613,
     602,   603,     0,   601,   604,   600,     0,   599,     0,     0,
       0,     0,   210,     0,   209,   118,   208,   200,   109,   354,
       0,     0,     0,     0,     0,     0,   355,   347,     0,     0,
       0,     0,   347,     0,     0,   375,   216,   229,   234,     0,
     231,   228,   230,     0,   232,   220,   224,   225,   118,   104,
     100,     0,    49,     0,    77,    76,    49,    49,    49,    70,
      45,    44,    48,    43,    42,   371,   360,     0,     0,     0,
       0,   295,     0,   291,     0,   293,   294,     0,   521,     0,
     518,   520,   290,     0,   292,     0,   134,   136,     0,     0,
     458,   256,   461,     0,     0,    20,   172,     0,   164,   582,
     542,   612,     0,   256,     0,     0,     0,     0,   483,   500,
     479,   480,   481,   482,     0,   596,     0,   597,     0,   611,
     201,   207,   212,   117,   319,   332,   334,     0,   336,     0,
     338,     0,     0,   323,   345,     0,   321,   349,     0,   435,
     437,   202,   204,     0,   226,   227,   550,    55,    56,     0,
       0,    59,    50,    51,    75,    58,    60,    61,    38,     0,
     359,   256,   275,   281,   279,   277,   522,   523,   516,     0,
     514,     0,   140,     0,   137,   139,   532,     0,   260,   442,
       0,   359,   173,     0,     0,     0,     0,   380,     0,     0,
       0,   617,   614,     0,     0,     0,     0,   356,   348,   325,
       0,   326,     0,     0,    53,    54,    52,   361,   372,   449,
     519,   289,   129,     0,   244,   245,   253,     0,     0,     0,
     263,   260,   257,   258,   261,   310,   444,     9,    21,     0,
     395,   450,   504,   507,   505,   414,     0,     0,   335,     0,
     346,     0,   233,   138,     0,     0,     0,     0,   254,   374,
     431,     0,   369,   430,   364,   427,   428,     0,   359,   242,
     243,   259,   262,   312,   313,   311,     0,     0,     0,   445,
     440,   616,     0,   618,   615,     0,   341,   205,     0,   251,
       0,     0,     0,   246,   255,   365,     0,     0,   366,   451,
     443,    72,   448,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   429,   368,   359,   453,    73,   447,   422,   423,
     418,   419,   424,    72,   620,   619,   252,   249,   250,     0,
     367,     0,     0,   426,   425,   421,   446,   248,   256,   420,
     442,   441
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    53,   404,   205,   234,   399,   400,   396,   401,   397,
     388,   389,    54,    55,    56,    57,   700,   701,   702,   853,
     941,   942,   943,   337,    58,   693,  1097,   686,   687,   343,
     321,    59,   178,   179,   180,   331,   512,   181,   509,   327,
     182,   480,   322,   183,   184,   185,   472,   477,   186,   316,
     317,    60,    61,   125,   563,   734,   370,   559,   560,   963,
     964,    62,    63,    64,   216,    65,    66,    67,    68,    69,
     149,   888,   150,   151,   152,   218,   378,   381,   382,    70,
     202,   348,   710,   311,   312,   834,   642,   931,   643,   313,
     645,   323,   676,   324,   677,   835,   836,   837,   838,    71,
     111,   112,   196,    72,  1010,  1011,   968,  1069,  1070,  1005,
     969,  1012,  1013,   652,   361,   362,   363,   364,   861,   865,
     863,   714,   952,   557,   365,   558,   366,   610,  1056,   503,
     504,   505,   506,   922,   507,   810,   817,   988,   383,   530,
     646,  1043,  1044,   350,  1038,   288,   425,   426,   767,    73,
      74,    75,   132,   372,    76,    77,   209,   289,   290,   291,
     292,   293,  1059,  1100,  1101,  1102,  1115,  1014,  1045,  1046,
     653,   532,   508,    78,   386,   743,  1080,  1016,  1060,  1081,
     533,   294,   154,   227,   572,   573,   367,   296,   434,   435,
     297,   605,   467,   368,   869,   870,   351,   130,  1006,    90,
      99,   298,   355,   299,   137,   881,   102,    79,    80,    81,
      82,   103,    83,   162,   240,   241,    84,   300,    85,   301,
     632,   796,   633,   302,   303,   304,   118
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -971
static const yytype_int16 yypact[] =
{
    2393,  -971,  -971,  -971,    96,  -971,   544,    96,    96,   544,
     544,    96,    96,   567,    96,    96,   544,   567,   567,   567,
     567,  -971,   600,  -971,    96,  -971,  -971,   544,  -971,   143,
     544,   544,  -971,   544,   544,  -971,  -971,  -971,   544,   544,
    -971,  -971,   567,   544,   626,  -971,    96,   544,   657,   502,
      42,   544,   502,  -971,  -971,  -971,  -971,  -971,  -971,  -971,
    -971,  -971,  -971,  -971,  -971,  -971,  -971,  -971,  -971,  -971,
    -971,  -971,  -971,  -971,  -971,  -971,  -971,  -971,  -971,   199,
    -971,  -971,  -971,   615,  -971,  -971,  -971,   180,    40,  -971,
    -971,   374,  -971,  -971,  -971,    63,   161,   480,   105,   394,
     -82,  -971,  -971,  -971,  -971,  -971,    74,   155,   159,   281,
    -971,    33,  -971,  -971,  -971,  -971,   301,  -971,  -971,   212,
    -971,   365,  -971,   376,   -25,   544,  -971,   264,   306,   356,
    -971,   255,   359,  -971,  -971,  -971,  -971,   489,  -971,  -971,
    -971,  -971,  -971,   450,   450,  -971,  -971,  -971,  -971,   421,
     405,   435,  -971,   669,   154,   132,   446,   441,  -971,  2393,
     665,  -971,  -971,   700,    96,   680,    96,    96,   720,  1228,
     608,    92,   734,  -971,  -971,   277,   100,   440,   524,  -971,
    -971,  -971,  -971,  -971,  -971,  -971,  -971,    96,  -971,  -971,
     687,    96,   544,   544,   544,   544,    33,  -971,   371,   544,
     371,    65,   525,   762,   993,  -971,   611,  -971,  -971,  -971,
      96,    96,   706,    96,    96,  -971,  -971,    65,  -971,  -971,
     104,   544,   661,  -971,  -971,  -971,  -971,  -971,  1322,  1322,
    1322,  1322,    54,    54,    23,   104,   544,  -971,   540,   546,
     562,  -971,   759,  -971,   551,  -971,   569,  -971,  -971,  -971,
     635,   559,  -971,  -971,   792,   648,   655,  -971,  -971,  -971,
    -971,   424,  -971,  1463,   656,  -971,   660,   663,  -971,    38,
     664,   670,  -971,   671,   684,   670,   670,   685,   690,   703,
     704,  2168,   708,  2168,   817,  -971,  -971,  -971,  -971,  -971,
     424,  -971,   424,  -971,  -971,  -971,  -971,   -70,   103,  -971,
    -971,  -971,  -971,   426,   784,   709,   710,   713,   272,   715,
     718,  -971,  -971,  -971,   810,    96,   658,  -971,  -971,  -971,
     371,  -971,  -971,  -971,  -971,   461,    96,  -971,  -971,   371,
     637,  -971,   480,  -971,   645,  -971,   666,   728,  -971,   736,
     740,   742,  -971,   -22,  -971,  -971,   -19,   626,    -9,  -971,
    -971,   652,   468,   724,  -971,  -971,   670,   758,   670,  1087,
     653,   691,  -971,  -971,  -971,  -971,  -971,   702,  -971,    96,
      94,  -971,   672,  -971,   668,  -971,   688,  -971,    11,  -971,
    -971,   689,  -971,  -971,   716,  -971,  1933,  -971,   110,  -971,
    -971,   118,   693,   693,    96,  -971,  -971,   139,   126,   695,
     743,  -971,   762,   993,  -971,   689,   681,    96,    96,   665,
    -971,    96,   714,  1557,    96,   903,  1933,  1933,  -971,  -971,
    -971,  -971,  -971,  -971,  -971,  -971,   686,    42,   779,  2027,
     254,  1933,  1933,   993,   439,  -971,  1933,   752,  -971,  1933,
    1933,  -971,  -971,   254,  1933,   254,   254,   426,   254,   426,
    -971,   694,     6,  -971,  1933,    76,    51,  -971,  -971,  -971,
    -971,  -971,  -971,  1933,  1933,  1933,  1933,  -971,   461,    65,
      65,    65,   160,   810,    65,   993,    96,  -971,   177,    96,
     178,  -971,  -971,  -971,   769,   770,   771,   424,   424,  -971,
     772,  -971,   775,   777,   778,   780,   783,  -971,  -971,  -971,
    -971,   785,   786,   619,  -971,  -971,  -971,  -971,  -971,   209,
    -971,  -971,   211,    96,  -971,    96,   719,    96,    96,    96,
      96,   832,   371,   204,  -971,  -971,    65,    78,   947,    96,
    -971,    42,   868,  -971,  -971,   -66,  2389,  -971,  -971,   993,
     993,  2168,  -971,  2168,  2168,  -971,  2168,  -971,   795,  1698,
    -971,  -971,  2168,  -971,   799,  -971,  2168,   393,  1933,   220,
    -971,   722,  -971,  -971,  -971,    96,    96,   730,  -971,    65,
     104,   104,   737,  -971,    56,  -971,  1322,  -971,  -971,   793,
      54,    79,  -971,    54,  1322,  -971,   653,   104,   725,  -971,
    -971,  -971,   731,  -971,  -971,   222,   733,  -971,   233,   238,
     531,   154,  -971,   429,   744,   819,   750,  -971,  -971,  -971,
    1933,   246,  -971,   206,  -971,  -971,   274,   276,   305,  1933,
     311,  1933,  1933,  1933,   531,   973,   531,  -971,  -971,    76,
    -971,  -971,   465,   975,  -971,  -971,   265,  -971,  -971,  -971,
    -971,  -971,   835,   760,  -971,   316,  -971,   328,  -971,   272,
    -971,   349,   653,   845,  -971,  -971,  -971,  -971,   371,   990,
     990,   991,   757,    43,   998,  1001,  1008,  1009,   998,   998,
    1012,  1013,  -971,  -971,  -971,   130,  -971,   251,  -971,    96,
    -971,   371,  -971,  -971,   781,  -971,   352,  -971,   133,   355,
     358,   361,  -971,   204,  -971,  1014,  -971,  -971,  1016,  1019,
    -971,   204,  -971,  -971,  -971,   854,    21,   788,   154,  -971,
    -971,  -971,   691,  -971,   865,   426,   873,   874,   865,   135,
    -971,  -971,  -971,   873,   135,  -971,   874,  -971,  -971,  1933,
    -971,  -971,    96,    96,   877,  -971,  -971,   803,  -971,  -971,
    -971,   689,  1933,  -971,    96,  -971,  -971,   882,  -971,  -971,
     351,  -971,  -971,   114,    96,    96,  -971,    96,  -971,  -971,
     883,  -971,  -971,  -971,  -971,  -971,  -971,  -971,  1933,   424,
     804,   424,  -971,   424,   898,  -971,  1933,  -971,  -971,  -971,
     900,  -971,   901,   902,   904,  -971,   905,  -971,   249,  -971,
    -971,  -971,    76,  -971,  -971,  -971,    76,  -971,    76,    96,
     935,    65,  -971,    65,  -971,   810,  -971,  -971,  -971,  -971,
     909,   911,   398,   531,  1057,   531,  -971,   838,   916,   400,
     919,   920,   838,   921,   923,  -971,  -971,  -971,  -971,   544,
    -971,  -971,  -971,   912,  -971,  -971,   251,  -971,   810,  -971,
    -971,    96,    98,    96,  -971,  -971,    98,    98,    98,   832,
    -971,  -971,  -971,  -971,  -971,  -971,  -971,  1067,    96,  1933,
     130,  -971,   130,  -971,   130,  -971,  -971,    49,  -971,   406,
    -971,  -971,  -971,   411,  -971,   856,  -971,  -971,  1792,    96,
    -971,   872,  -971,  1322,    96,  -971,  -971,   600,  -971,  -971,
    -971,   906,  1074,   366,   837,   531,   840,   841,  -971,  -971,
    -971,  -971,  -971,  -971,   842,  -971,   326,   574,   509,   914,
    -971,  -971,  -971,  -971,  -971,  -971,  -971,  1084,  -971,   942,
    -971,  1086,   946,  -971,  -971,  1091,  -971,  -971,   949,  -971,
    -971,  -971,   937,   993,  -971,  -971,  -971,  -971,  -971,  1019,
    1094,  -971,    98,  -971,  -971,  -971,  -971,  -971,  -971,   943,
     854,   366,  -971,  -971,  -971,  -971,  -971,  -971,  -971,   221,
    -971,  1933,  -971,   412,  -971,  -971,  -971,   544,   538,   907,
     422,   854,  -971,    76,   953,   954,   531,   957,   531,   531,
     531,  -971,  -971,    76,    76,   959,   869,  -971,  -971,  -971,
     960,  -971,    65,   963,  -971,  -971,  -971,  -971,  -971,  -971,
    -971,  -971,  -971,  1792,    67,  -971,    77,    82,   993,   993,
    -971,    28,  -971,  -971,   948,   279,   -17,  -971,  -971,   627,
    -971,  -971,  -971,  -971,  -971,  -971,   723,   673,  -971,   531,
    -971,   462,  -971,  -971,    99,    99,   128,    96,  -971,  -971,
    -971,    69,  -971,  -971,  -971,   890,  -971,   880,   470,   653,
     653,  -971,  -971,  -971,  -971,  -971,   940,    96,   884,   987,
    -971,  -971,    76,  -971,  -971,    76,  -971,  -971,   544,    67,
     885,   886,   112,  -971,  -971,  -971,    82,    83,  -971,    42,
    -971,  1015,  -971,   125,    96,   809,   829,   136,   993,   993,
     544,  -971,  -971,  -971,   854,   154,  -971,  -971,  -971,  -971,
     896,  -971,   288,  1015,  -971,  -971,  -971,   653,   653,   200,
    -971,  1933,   125,  -971,  -971,  -971,  -971,  -971,   366,  -971,
     907,  -971
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -971,  -971,  -971,  -971,  -971,  -971,  -181,   729,   545,  -971,
    -185,  -373,  -971,  -971,  -971,  -971,   434,  -971,   428,   191,
     -46,  -971,   189,   618,  -971,   283,    30,   333,   291,   936,
    -144,  -971,  -971,   805,  -971,  -272,  -971,  -971,  -971,  -277,
    -971,  -971,  -261,  -971,  -971,  -971,  -971,  -451,  -971,   820,
     659,  -971,  -971,  -971,  -971,  -971,  -971,  -971,   407,  -971,
     137,  -971,  -971,  -971,  -971,  -971,  -971,  -971,  -971,  -971,
    1090,  -971,  1092,  -971,   925,   999,  -971,  -198,   575,  -971,
    -971,  -971,  -971,  -971,  -971,   353,  -971,  -971,   156,  -971,
    -123,  -139,  -971,  -971,  -971,  -971,  -971,   313,  -971,  -971,
    -971,  -971,  -971,   -14,   140,  -971,  -971,  -847,   116,  -888,
    -821,  -971,   146,  -203,   620,   621,   801,  -971,   444,   432,
     442,   348,  -110,  -971,  -971,  -971,  -971,   388,  -971,   696,
    -971,  -971,  -971,   341,  -971,   506,   111,  -971,    -3,  -370,
    -176,  -970,   127,   822,   134,  -607,  -971,  -242,  -561,  -971,
    -971,  -971,   956,   602,  -971,  -971,  -971,  -971,  -971,  -971,
    -971,  -971,  -971,  -971,    60,  -971,  -971,  -971,  -971,   101,
     241,  -971,  -971,  -971,  -971,  -971,  -971,    55,  -971,    95,
     808,  -209,  -406,  -565,  -715,   438,  -137,  -971,  -971,   747,
     332,  -971,  -971,  -971,   458,   226,   -27,  -971,    68,  -971,
     739,    -4,   787,   319,  -971,  -971,  -971,  -971,  -971,  1028,
    -971,  1173,  -971,  -971,  -971,   789,  -971,  -405,  -971,  -971,
    -559,  -971,  -971,  -971,  -115,  -971,  -971
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -565
static const yytype_int16 yytable[] =
{
      87,   360,    91,    92,    93,    91,    91,    96,    97,   100,
     101,   101,    91,   100,   100,   100,   100,   129,   114,   113,
     115,   601,   650,    91,   606,   349,    91,    91,   582,    91,
      91,   314,   295,   330,    91,    91,   768,   405,   100,    91,
     131,   379,   133,    91,   391,   392,   393,    91,   451,   510,
     452,   395,   956,   893,   344,    86,   344,   511,    86,   481,
      86,   203,   438,   785,   252,   787,   441,   442,   826,    86,
     788,   128,   975,    86,    89,   128,   453,    94,    95,   628,
     711,    86,    86,    86,   105,  1040,    86,    86,   128,  1034,
    1035,   390,   390,   390,   390,   116,    86,   197,   119,   120,
      86,   121,   122,    86,    86,    88,   123,   124,    86,   402,
     110,   127,   868,  1099,  1057,   134,    86,   868,    88,   155,
    1004,    91,   937,   938,   521,   708,   428,   523,  1098,    86,
     999,   128,    86,   249,    88,    38,   825,   525,   249,    86,
     190,   251,  1099,   859,   951,   252,   117,   534,  1073,   537,
     252,   191,   253,   454,   535,   254,   239,   568,  1034,  1035,
     243,   245,   246,   247,  1007,   625,   447,   318,   449,   473,
     204,   325,   328,   325,   539,  1058,   856,   228,   229,   230,
     231,   232,   342,   333,  1091,   330,   335,   336,    91,    91,
      91,    91,  1008,   206,   325,    91,   325,   352,   886,   158,
     586,   522,   814,   746,   522,    49,   371,   373,   375,   376,
     133,   752,   163,   352,   526,   159,   114,    91,   403,    52,
     536,  1087,  1034,  1035,   249,    86,   153,   251,   398,   398,
     613,   114,    91,   906,   569,   629,   252,   907,   253,   908,
     432,   254,   634,  1109,   857,   662,   663,   626,   695,   574,
     433,   315,   918,   953,   920,   953,   575,   953,  1068,   326,
     338,   338,   338,   338,   577,   696,   697,   345,   531,   704,
     749,  1090,   562,   455,  1093,   380,   295,   164,   261,   295,
     295,    86,  1106,   261,   815,   579,   284,   394,   224,   384,
    1036,   744,   604,   644,   295,   612,   528,  1120,   347,   295,
     635,   168,   295,   295,   406,   630,   648,   295,   698,   427,
     631,   318,  1037,   192,   871,  1041,   325,   627,  1042,   871,
     169,  1072,   328,   655,   657,   325,   637,   638,   639,   640,
     225,  1042,   844,   576,   977,   855,   939,   570,   827,   720,
     456,   576,   187,   352,   940,   725,  1117,   233,   647,   887,
     703,   651,   868,   845,   913,   678,   207,   680,  1041,  1036,
     828,   770,   580,   581,   867,   561,   731,   284,   756,   261,
     829,   226,   284,   741,  1042,    86,   208,   305,   694,   758,
     885,   306,   305,   649,   759,   830,   306,   935,   607,   753,
     398,   831,   775,   739,   193,   905,  1118,   808,   194,   748,
     479,   658,   839,   588,   589,   239,   307,   591,   593,   840,
     596,   307,   722,  1053,  1019,  1022,   776,  1023,  1024,  1025,
     777,   730,   778,  1036,  1026,  1027,   715,   832,   715,   715,
     608,   715,   679,   833,   681,   798,   320,   715,   199,   390,
     790,   715,   699,   732,    86,   454,   539,   390,   309,   791,
     867,   779,   636,   309,   310,  1054,   454,   781,   284,   310,
     198,   454,   802,   188,   189,   352,   352,   352,  1066,   454,
     352,   609,   654,   774,   804,   318,   305,   212,   793,   794,
     306,   981,   780,   795,   782,   783,   784,  1113,   213,   457,
     458,   459,   460,   461,   462,   806,  1055,   454,   842,   454,
     727,   846,   799,  1085,   847,   307,  1086,   848,  1114,   682,
     805,   683,   685,   688,   688,   688,   688,   790,   325,   482,
     195,   528,   352,   705,   200,   707,   791,   894,   454,   896,
    1111,   897,   170,   171,   454,   201,   728,   330,   729,   803,
     172,   173,   174,   210,   916,   305,   924,   309,    86,   306,
      88,   803,   958,   310,   871,   793,   794,   960,  1002,   418,
     795,   373,   736,   738,   418,   352,   114,   114,  1017,   967,
     745,    86,   803,    98,   307,   843,   398,   750,   843,   398,
     998,   843,   483,   114,   843,   484,   485,   486,   884,   742,
     419,   138,   875,   211,   487,   419,   165,   420,   488,   329,
     214,  1018,   420,   489,    86,   574,   110,   166,  1067,   217,
     490,   167,   491,   492,   421,   493,   309,   463,   215,   421,
     789,   917,   310,   925,   220,   911,   464,   912,   422,   959,
      86,   574,   128,   422,   959,  1003,   494,   423,   528,   899,
     528,   432,   423,   139,   221,   576,   495,   175,   424,   140,
     496,   433,   769,   424,   325,   465,   790,   497,   222,   498,
     466,   135,   141,   136,   982,   791,   760,   142,   499,    86,
     500,   238,   223,  1095,  1007,   328,   143,   325,  1078,   144,
     236,   176,   614,   145,    86,   801,   244,   235,   792,   146,
     212,    86,   212,   334,   793,   794,   177,   761,   970,   795,
     790,   213,  1008,   213,   762,   529,   242,  -527,   501,   791,
      86,   502,   374,   305,   672,   673,   674,   306,    86,   147,
     592,   763,   574,    86,  1110,   684,   248,   148,   561,   877,
     160,   161,   983,  1009,    86,   764,   737,   319,   793,   794,
     882,   965,   307,   795,   765,   595,   390,   332,   598,   599,
     889,   890,   954,   891,   955,   766,   106,   107,   108,   109,
     353,   249,   250,   611,   251,   790,   354,   308,   616,   675,
     369,   617,   618,   252,   791,   253,   620,   407,   254,   821,
     822,   126,  1061,   408,   309,   409,   255,   256,   411,   410,
     310,   412,   257,   258,   413,   909,   414,   352,   415,   352,
     945,   946,   947,   793,   794,  1049,  1050,   416,   795,  -282,
     541,   339,   340,   341,   417,   429,   644,   259,   790,   430,
     450,   141,   431,   436,  1001,    91,   142,   791,  1064,   437,
     439,   619,   542,   621,   622,   143,   623,   936,   144,   688,
     543,   544,   145,   440,   443,  -282,   545,  -282,   146,   444,
    1062,   689,   690,   691,   950,   546,   793,   794,   547,   468,
     548,   795,   445,   446,   790,   476,   965,   448,   469,   470,
     549,   550,   471,   791,   474,   966,   356,   475,  1063,   513,
     971,   479,   515,   114,   972,  1107,  1108,   517,   516,   527,
     551,   716,   717,   539,   718,   518,  1065,   932,   531,   519,
     723,   520,   793,   794,   726,   566,   261,   795,   552,   540,
     567,   584,   570,   565,   790,   262,   576,   357,   583,   571,
     358,   264,   587,   791,   597,   602,   427,   600,   659,   660,
     661,   664,   427,   553,   665,   624,   666,   667,   265,   668,
     554,   266,   669,   692,   670,   671,   555,   556,   267,   268,
     706,   709,   793,   794,   719,   269,   270,   795,   724,   733,
     742,   747,   754,    91,  1104,   772,   271,   771,   755,   272,
     757,   273,   274,   773,   574,   275,   786,   276,   797,   277,
    1047,   800,   278,   801,  1105,   279,   280,   281,   352,   359,
     282,   807,   283,   809,   812,   284,   249,   250,   813,   251,
     790,   816,  1039,  1048,   818,   285,   286,   287,   252,   791,
     253,   819,   820,   254,  1047,   823,   824,   850,   841,   851,
     790,   255,   256,   852,   528,   858,   860,   257,   258,   791,
      91,    91,    91,  1039,   862,   864,   878,  1048,   793,   794,
     879,   883,   892,   795,   898,   895,   900,   901,   902,  1047,
     903,   904,   259,  1082,   829,   914,  1047,   915,   793,   794,
     919,   921,   923,   795,    91,   926,   927,   929,    91,   930,
     949,   933,  1048,  1094,   961,   967,   973,   974,   976,  1048,
    1082,   978,   979,   980,   984,  1047,    91,   985,   986,   987,
     249,   250,   989,   251,   990,   991,   992,   995,   997,  1020,
    1021,  1015,   252,  -506,   253,  1028,  1030,   254,  1048,  1032,
    1029,   356,  1008,  1076,  1079,   255,   256,  1077,  1084,  1112,
    1083,   257,   258,   578,  1088,  1089,  1096,   849,   751,   854,
     994,   996,   948,  1116,   944,   478,   346,   514,   656,   876,
    1033,   261,   156,   219,   157,   740,   259,   385,  1031,   934,
     262,  1071,   357,   910,  1052,   358,   264,  1051,   874,   712,
     538,   713,   866,   928,   641,   872,   811,   735,  1075,   524,
     377,  1074,  1119,   265,   993,  1121,   266,  1092,   564,  1103,
     880,   615,   873,   267,   268,  1000,   957,   237,   104,   585,
     269,   270,     0,     0,     0,     0,     0,     0,   590,     0,
       0,   271,     0,     0,   272,   356,   273,   274,     0,     0,
     275,     0,   276,     0,   277,     0,     0,   278,     0,     0,
     279,   280,   281,     0,   359,   282,     0,   283,     0,     0,
     284,   249,   250,     0,   251,   261,     0,     0,     0,     0,
     285,   286,   287,   252,   262,   253,   357,     0,   254,   358,
     264,     0,     0,     0,     0,     0,   255,   256,     0,     0,
       0,     0,   257,   258,     0,     0,     0,   265,     0,     0,
     266,     0,     0,     0,     0,     0,     0,   267,   268,     0,
       0,     0,     0,     0,   269,   270,     0,   259,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,   272,     0,
     273,   274,     0,     0,   275,     0,   276,     0,   277,     0,
       0,   278,     0,     0,   279,   280,   281,     0,     0,   282,
       0,   283,     0,     0,   284,   249,   250,     0,   251,     0,
       0,     0,     0,     0,   285,   286,   287,   252,     0,   253,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
     255,   256,     0,     0,     0,     0,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,   261,     0,     0,     0,
       0,   259,     0,     0,     0,   262,     0,   263,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
       0,   266,     0,     0,     0,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,   269,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,   272,
       0,   273,   274,     0,     0,   275,     0,   276,     0,   277,
       0,     0,   278,     0,     0,   279,   280,   281,     0,     0,
     282,     0,   283,     0,     0,   284,   249,   250,     0,   251,
     261,     0,     0,     0,     0,   285,   286,   287,   252,   262,
     253,   263,     0,   254,     0,   264,     0,     0,     0,     0,
       0,   255,   256,     0,     0,     0,     0,   257,   258,     0,
       0,   387,   265,     0,     0,   266,     0,     0,     0,     0,
       0,     0,   267,   268,     0,     0,     0,     0,     0,   269,
     270,     0,   259,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,   273,   274,     0,     0,   275,
       0,   276,     0,   277,     0,     0,   278,     0,     0,   279,
     280,   281,     0,     0,   282,     0,   283,     0,     0,   284,
     249,   250,     0,   251,     0,     0,     0,     0,     0,   285,
     286,   287,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,   255,   256,     0,     0,     0,
       0,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,   259,     0,     0,     0,
     262,     0,   263,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   427,     0,     0,
       0,     0,     0,   265,     0,     0,   266,     0,     0,     0,
       0,     0,     0,   267,   268,     0,     0,     0,     0,     0,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,   273,   274,     0,     0,
     275,     0,   276,     0,   277,     0,     0,   278,     0,     0,
     279,   280,   281,     0,     0,   282,     0,   283,     0,     0,
     284,   249,   250,   594,   251,   261,     0,     0,     0,     0,
     285,   286,   287,   252,   262,   253,   263,     0,   254,     0,
     264,     0,     0,     0,     0,     0,   255,   256,     0,     0,
       0,     0,   257,   258,     0,     0,     0,   265,     0,     0,
     266,     0,     0,     0,     0,     0,     0,   267,   268,     0,
       0,     0,     0,     0,   269,   270,     0,   259,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,   272,     0,
     273,   274,     0,     0,   275,     0,   276,     0,   277,     0,
       0,   278,     0,     0,   279,   280,   281,     0,     0,   282,
       0,   283,     0,     0,   284,   249,   250,     0,   251,     0,
       0,     0,     0,     0,   285,   286,   287,   252,     0,   253,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
     255,   256,     0,     0,     0,     0,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,   259,     0,     0,     0,   262,     0,   263,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   721,   265,     0,
       0,   266,     0,     0,     0,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,   269,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,   272,
       0,   273,   274,     0,     0,   275,     0,   276,     0,   277,
       0,     0,   278,     0,     0,   279,   280,   281,     0,     0,
     282,     0,   283,     0,     0,   284,   249,   250,     0,   251,
     261,     0,     0,     0,     0,   285,   286,   287,   252,   262,
     253,   263,     0,   254,     0,   264,     0,     0,     0,     0,
       0,   255,   256,     0,     0,     0,     0,   257,   258,     0,
       0,   962,   265,     0,     0,   266,     0,     0,     0,     0,
       0,     0,   267,   268,     0,     0,     0,     0,     0,   269,
     270,     0,   259,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,   272,     0,   273,   274,     0,     0,   275,
       0,   276,     0,   277,     0,     0,   278,     0,     0,   279,
     280,   281,     0,     0,   282,     0,   283,     0,     0,   284,
     249,   250,     0,   251,     0,     0,     0,     0,     0,   285,
     286,   287,   252,     0,   253,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,   255,   256,     0,     0,     0,
       0,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,   259,     0,     0,     0,
     262,     0,   263,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,   266,     0,     0,     0,
       0,     0,     0,   267,   268,     0,     0,     0,     0,     0,
     269,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,     0,   272,     0,   273,   274,     0,     0,
     275,     0,   276,     0,   277,     0,     0,   278,     0,     0,
     279,   280,   281,     0,     0,   282,     0,   283,     0,     0,
     284,   249,   250,     0,   251,   603,     0,     0,     0,     0,
     285,   286,   287,   252,   262,   253,   263,     0,   254,     0,
     264,     0,     0,     0,     0,     0,   255,   256,     0,     0,
       0,     0,   257,   258,     0,     0,     0,   265,     0,     0,
     266,     0,     0,     0,     0,     0,     0,   267,   268,     0,
       0,     0,     0,     0,   269,   270,     0,   259,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,   272,     0,
     273,   274,     0,     0,   275,     0,   276,     0,   277,     0,
       0,   278,     0,     0,   279,   280,   281,     0,     0,   282,
       0,   283,     0,     0,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   286,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,   263,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
       0,   266,     0,     0,     0,     0,     0,     0,   267,   268,
       0,     0,     0,     0,     0,   269,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,   272,
       0,   273,   274,     0,     0,   275,     0,   276,     0,   277,
       0,     0,   278,  -564,     1,   279,   280,     0,     0,     0,
     282,     0,     0,     0,     0,   284,     0,     0,     0,  -564,
       0,     0,     0,     0,     0,   285,   286,   287,     0,     2,
       3,     0,     0,     0,     4,     0,     5,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,     0,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    28,     0,
       0,    29,     0,    30,    31,     0,    32,    33,     0,     0,
       0,    34,    35,    36,    37,    38,    39,   541,     0,    40,
       0,     0,     0,     0,     0,     0,    41,    42,     0,     0,
      43,     0,     0,    44,     0,    45,    46,     0,     0,   542,
       0,    47,     0,     0,     0,    48,     0,   543,   544,     0,
       0,     0,     0,   545,     0,   602,     0,     0,     0,     0,
       0,     0,   546,     0,     0,   547,     0,   548,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   549,   550,     0,
       0,     0,     0,     0,     0,    49,     0,    50,     0,     0,
      51,     0,     0,     0,     0,     0,     0,   551,     0,    52,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   552,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     553,     0,     0,     0,     0,     0,     0,   554,     0,  -305,
       0,     0,     0,   555,   556
};

static const yytype_int16 yycheck[] =
{
       4,   204,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    44,    22,    22,
      24,   427,   473,    27,   429,   201,    30,    31,   398,    33,
      34,   170,   169,   177,    38,    39,   601,   235,    42,    43,
      44,   217,    46,    47,   229,   230,   231,    51,   290,   326,
     292,   232,     3,   768,   198,     4,   200,   329,     4,   320,
       4,    86,   271,   624,    15,   626,   275,   276,   675,     4,
     629,     6,   893,     4,     6,     6,   146,     9,    10,     3,
     146,     4,     4,     4,    16,     3,     4,     4,     6,    22,
      23,   228,   229,   230,   231,    27,     4,   111,    30,    31,
       4,    33,    34,     4,     4,     6,    38,    39,     4,    86,
       6,    43,   719,  1083,   131,    47,     4,   724,     6,    51,
     967,   125,    24,    25,   146,   531,   263,   146,     3,     4,
     951,     6,     4,     3,     6,   102,     6,   146,     3,     4,
     222,     6,  1112,   708,   859,    15,     3,   356,  1036,   358,
      15,   233,    17,   223,   357,    20,   160,   146,    22,    23,
     164,   165,   166,   167,   136,   159,   281,   171,   283,   308,
     195,   175,   176,   177,   240,   192,   155,    45,    46,    47,
      48,    49,   196,   187,  1072,   329,   190,   191,   192,   193,
     194,   195,   164,   125,   198,   199,   200,   201,    84,     0,
     403,   223,   159,   576,   223,   172,   210,   211,   212,   213,
     214,   584,    32,   217,   223,    16,   220,   221,   195,   186,
     357,  1068,    22,    23,     3,     4,   184,     6,   232,   233,
     433,   235,   236,   792,   223,   159,    15,   796,    17,   798,
     202,    20,   191,  1090,   223,   487,   488,   241,    44,   386,
     212,   159,   813,   860,   815,   862,   146,   864,   159,   159,
     192,   193,   194,   195,   146,    61,    62,   199,   174,   191,
     191,   159,   178,   170,   191,   171,   413,   237,   148,   416,
     417,     4,   146,   148,   241,   146,   237,   233,   134,   221,
     223,   235,   429,   469,   431,   432,   170,  1118,   233,   436,
     249,   238,   439,   440,   236,   229,   146,   444,   104,   174,
     234,   315,   235,   239,   719,   233,   320,   454,   249,   724,
     159,   193,   326,   146,   146,   329,   463,   464,   465,   466,
     176,   249,   199,   223,   895,   705,   238,   223,    87,   548,
     237,   223,   237,   347,   246,   554,   146,   215,   471,   235,
     526,   474,   959,   220,   805,   146,    92,   146,   233,   223,
     109,   603,   223,   237,   229,   369,   146,   237,   146,   148,
     119,   217,   237,   571,   249,     4,   112,   105,   522,   146,
     750,   109,   105,   223,   146,   134,   109,   838,   134,   587,
     394,   140,   146,   569,   239,   146,  1111,   658,   239,   580,
     223,   223,   679,   407,   408,   409,   134,   411,   412,   681,
     414,   134,   549,   134,   973,   976,   210,   978,   979,   980,
     146,   558,   146,   223,   983,   984,   541,   176,   543,   544,
     176,   546,   223,   182,   223,   170,   159,   552,   226,   576,
     191,   556,   238,   223,     4,   223,   240,   584,   176,   200,
     229,   146,   456,   176,   182,   176,   223,   146,   237,   182,
     159,   223,   146,    69,    70,   469,   470,   471,  1029,   223,
     474,   217,   476,   610,   146,   479,   105,   222,   229,   230,
     109,   155,   619,   234,   621,   622,   623,   199,   233,    63,
      64,    65,    66,    67,    68,   146,   217,   223,   146,   223,
     107,   146,   237,  1062,   146,   134,  1065,   146,   220,   513,
     649,   515,   516,   517,   518,   519,   520,   191,   522,    58,
     239,   170,   526,   527,   159,   529,   200,   769,   223,   771,
    1095,   773,    52,    53,   223,   159,   143,   681,   145,   223,
      60,    61,    62,   237,   146,   105,   146,   176,     4,   109,
       6,   223,   146,   182,   959,   229,   230,   146,   146,   135,
     234,   565,   566,   567,   135,   569,   570,   571,   146,   203,
     574,     4,   223,     6,   134,   223,   580,   581,   223,   583,
     950,   223,   121,   587,   223,   124,   125,   126,   237,   223,
     166,    89,   729,   237,   133,   166,   222,   173,   137,   159,
     241,   971,   173,   142,     4,   742,     6,   233,   146,   159,
     149,   237,   151,   152,   190,   154,   176,   191,   129,   190,
     155,   223,   182,   223,   203,   801,   200,   803,   204,   223,
       4,   768,     6,   204,   223,   223,   175,   213,   170,   776,
     170,   202,   213,   141,   239,   223,   185,   167,   224,   147,
     189,   212,   223,   224,   658,   229,   191,   196,   223,   198,
     234,     4,   160,     6,   155,   200,   135,   165,   207,     4,
     209,     6,     3,  1079,   136,   679,   174,   681,  1048,   177,
     239,   201,   243,   181,     4,   223,     6,   241,   223,   187,
     222,     4,   222,     6,   229,   230,   216,   166,   883,   234,
     191,   233,   164,   233,   173,   237,     6,   237,   247,   200,
       4,   250,     6,   105,    95,    96,    97,   109,     4,   217,
       6,   190,   859,     4,  1094,     6,     6,   225,   732,   733,
     115,   116,   223,   195,     4,   204,     6,     3,   229,   230,
     744,   878,   134,   234,   213,   413,   883,   223,   416,   417,
     754,   755,   862,   757,   864,   224,    17,    18,    19,    20,
     235,     3,     4,   431,     6,   191,     4,   159,   436,   150,
     159,   439,   440,    15,   200,    17,   444,   237,    20,   668,
     669,    42,   155,   237,   176,   223,    28,    29,   237,    30,
     182,   222,    34,    35,   159,   799,   237,   801,     6,   803,
     846,   847,   848,   229,   230,  1008,  1009,   159,   234,   107,
     108,   193,   194,   195,   159,   159,   992,    59,   191,   159,
       3,   160,   159,   159,   961,   829,   165,   200,   155,   159,
     159,   443,   130,   445,   446,   174,   448,   841,   177,   843,
     138,   139,   181,   159,   159,   143,   144,   145,   187,   159,
     223,   518,   519,   520,   858,   153,   229,   230,   156,    75,
     158,   234,   159,   159,   191,    55,  1003,   159,   159,   159,
     168,   169,   159,   200,   159,   879,   118,   159,   155,   242,
     884,   223,   237,   887,   887,  1088,  1089,   159,   222,   237,
     188,   543,   544,   240,   546,   159,   223,   829,   174,   159,
     552,   159,   229,   230,   556,   237,   148,   234,   206,   218,
     222,   168,   223,   241,   191,   157,   223,   159,   223,   203,
     162,   163,   241,   200,    21,   146,   174,   241,   159,   159,
     159,   159,   174,   231,   159,   241,   159,   159,   180,   159,
     238,   183,   159,   111,   159,   159,   244,   245,   190,   191,
       3,    83,   229,   230,   159,   197,   198,   234,   159,   237,
     223,   168,   237,   967,   155,   146,   208,   223,   237,   211,
     237,   213,   214,   223,  1111,   217,     3,   219,     3,   221,
    1007,   146,   224,   223,   155,   227,   228,   229,   992,   231,
     232,   146,   234,     3,     3,   237,     3,     4,   241,     6,
     191,     3,  1006,  1007,     3,   247,   248,   249,    15,   200,
      17,     3,     3,    20,  1041,     3,     3,     3,   237,     3,
     191,    28,    29,     4,   170,   237,   161,    34,    35,   200,
    1034,  1035,  1036,  1037,   161,   161,   159,  1041,   229,   230,
     237,   159,   159,   234,   146,   241,   146,   146,   146,  1076,
     146,   146,    59,  1057,   119,   146,  1083,   146,   229,   230,
       3,   223,   146,   234,  1068,   146,   146,   146,  1072,   146,
       3,   159,  1076,  1077,   218,   203,   170,     3,   241,  1083,
    1084,   241,   241,   241,   170,  1112,  1090,     3,   146,     3,
       3,     4,   146,     6,     3,   146,   159,     3,   155,   146,
     146,   194,    15,   146,    17,   146,   146,    20,  1112,   146,
     241,   118,   164,   223,   174,    28,    29,   237,   131,   223,
     236,    34,    35,   394,   239,   239,   111,   693,   583,   701,
     939,   942,   849,  1103,   843,   315,   200,   332,   479,   732,
    1003,   148,    52,   144,    52,   570,    59,   222,   992,   836,
     157,  1035,   159,   800,  1014,   162,   163,  1011,   726,   539,
     359,   540,   718,   822,   468,   723,   660,   565,  1041,   347,
     214,  1037,  1112,   180,   933,  1120,   183,  1076,   370,  1084,
     742,   434,   724,   190,   191,   959,   867,   159,    15,   402,
     197,   198,    -1,    -1,    -1,    -1,    -1,    -1,   409,    -1,
      -1,   208,    -1,    -1,   211,   118,   213,   214,    -1,    -1,
     217,    -1,   219,    -1,   221,    -1,    -1,   224,    -1,    -1,
     227,   228,   229,    -1,   231,   232,    -1,   234,    -1,    -1,
     237,     3,     4,    -1,     6,   148,    -1,    -1,    -1,    -1,
     247,   248,   249,    15,   157,    17,   159,    -1,    20,   162,
     163,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,   180,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,   211,    -1,
     213,   214,    -1,    -1,   217,    -1,   219,    -1,   221,    -1,
      -1,   224,    -1,    -1,   227,   228,   229,    -1,    -1,   232,
      -1,   234,    -1,    -1,   237,     3,     4,    -1,     6,    -1,
      -1,    -1,    -1,    -1,   247,   248,   249,    15,    -1,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   146,    -1,   148,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,   157,    -1,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,   211,
      -1,   213,   214,    -1,    -1,   217,    -1,   219,    -1,   221,
      -1,    -1,   224,    -1,    -1,   227,   228,   229,    -1,    -1,
     232,    -1,   234,    -1,    -1,   237,     3,     4,    -1,     6,
     148,    -1,    -1,    -1,    -1,   247,   248,   249,    15,   157,
      17,   159,    -1,    20,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,   179,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,   197,
     198,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,   211,    -1,   213,   214,    -1,    -1,   217,
      -1,   219,    -1,   221,    -1,    -1,   224,    -1,    -1,   227,
     228,   229,    -1,    -1,   232,    -1,   234,    -1,    -1,   237,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,   247,
     248,   249,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
     157,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
     197,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,    -1,    -1,   211,    -1,   213,   214,    -1,    -1,
     217,    -1,   219,    -1,   221,    -1,    -1,   224,    -1,    -1,
     227,   228,   229,    -1,    -1,   232,    -1,   234,    -1,    -1,
     237,     3,     4,   146,     6,   148,    -1,    -1,    -1,    -1,
     247,   248,   249,    15,   157,    17,   159,    -1,    20,    -1,
     163,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,   180,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,   211,    -1,
     213,   214,    -1,    -1,   217,    -1,   219,    -1,   221,    -1,
      -1,   224,    -1,    -1,   227,   228,   229,    -1,    -1,   232,
      -1,   234,    -1,    -1,   237,     3,     4,    -1,     6,    -1,
      -1,    -1,    -1,    -1,   247,   248,   249,    15,    -1,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,   157,    -1,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,   211,
      -1,   213,   214,    -1,    -1,   217,    -1,   219,    -1,   221,
      -1,    -1,   224,    -1,    -1,   227,   228,   229,    -1,    -1,
     232,    -1,   234,    -1,    -1,   237,     3,     4,    -1,     6,
     148,    -1,    -1,    -1,    -1,   247,   248,   249,    15,   157,
      17,   159,    -1,    20,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,   179,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,   197,
     198,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,   211,    -1,   213,   214,    -1,    -1,   217,
      -1,   219,    -1,   221,    -1,    -1,   224,    -1,    -1,   227,
     228,   229,    -1,    -1,   232,    -1,   234,    -1,    -1,   237,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,   247,
     248,   249,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   148,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
     157,    -1,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,    -1,    -1,   183,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
     197,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,    -1,    -1,   211,    -1,   213,   214,    -1,    -1,
     217,    -1,   219,    -1,   221,    -1,    -1,   224,    -1,    -1,
     227,   228,   229,    -1,    -1,   232,    -1,   234,    -1,    -1,
     237,     3,     4,    -1,     6,   148,    -1,    -1,    -1,    -1,
     247,   248,   249,    15,   157,    17,   159,    -1,    20,    -1,
     163,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,   180,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,   211,    -1,
     213,   214,    -1,    -1,   217,    -1,   219,    -1,   221,    -1,
      -1,   224,    -1,    -1,   227,   228,   229,    -1,    -1,   232,
      -1,   234,    -1,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,   159,    -1,    -1,
      -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,
      -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,   211,
      -1,   213,   214,    -1,    -1,   217,    -1,   219,    -1,   221,
      -1,    -1,   224,     0,     1,   227,   228,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,   247,   248,   249,    -1,    26,
      27,    -1,    -1,    -1,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    76,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    -1,
      -1,    88,    -1,    90,    91,    -1,    93,    94,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   108,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,
     117,    -1,    -1,   120,    -1,   122,   123,    -1,    -1,   130,
      -1,   128,    -1,    -1,    -1,   132,    -1,   138,   139,    -1,
      -1,    -1,    -1,   144,    -1,   146,    -1,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,   156,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,   174,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   238,    -1,   240,
      -1,    -1,    -1,   244,   245
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    26,    27,    31,    33,    36,    37,    38,    39,
      40,    41,    42,    43,    50,    51,    54,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    82,    85,    88,
      90,    91,    93,    94,    98,    99,   100,   101,   102,   103,
     106,   113,   114,   117,   120,   122,   123,   128,   132,   172,
     174,   177,   186,   254,   265,   266,   267,   268,   277,   284,
     304,   305,   314,   315,   316,   318,   319,   320,   321,   322,
     332,   352,   356,   402,   403,   404,   407,   408,   426,   460,
     461,   462,   463,   465,   469,   471,     4,   454,     6,   451,
     452,   454,   454,   454,   451,   451,   454,   454,     6,   453,
     454,   454,   459,   464,   464,   451,   453,   453,   453,   453,
       6,   353,   354,   391,   454,   454,   451,     3,   479,   451,
     451,   451,   451,   451,   451,   306,   453,   451,     6,   449,
     450,   454,   405,   454,   451,     4,     6,   457,    89,   141,
     147,   160,   165,   174,   177,   181,   187,   217,   225,   323,
     325,   326,   327,   184,   435,   451,   323,   325,     0,    16,
     115,   116,   466,    32,   237,   222,   233,   237,   238,   159,
      52,    53,    60,    61,    62,   167,   201,   216,   285,   286,
     287,   290,   293,   296,   297,   298,   301,   237,    69,    70,
     222,   233,   239,   239,   239,   239,   355,   356,   159,   226,
     159,   159,   333,    86,   195,   256,   451,    92,   112,   409,
     237,   237,   222,   233,   241,   129,   317,   159,   328,   328,
     203,   239,   223,     3,   134,   176,   217,   436,    45,    46,
      47,    48,    49,   215,   257,   241,   239,   462,     6,   454,
     467,   468,     6,   454,     6,   454,   454,   454,     6,     3,
       4,     6,    15,    17,    20,    28,    29,    34,    35,    59,
     146,   148,   157,   159,   163,   180,   183,   190,   191,   197,
     198,   208,   211,   213,   214,   217,   219,   221,   224,   227,
     228,   229,   232,   234,   237,   247,   248,   249,   398,   410,
     411,   412,   413,   414,   434,   439,   440,   443,   454,   456,
     470,   472,   476,   477,   478,   105,   109,   134,   159,   176,
     182,   336,   337,   342,   344,   159,   302,   303,   454,     3,
     159,   283,   295,   344,   346,   454,   159,   292,   454,   159,
     283,   288,   223,   454,     6,   454,   454,   276,   451,   276,
     276,   276,   356,   282,   283,   451,   282,   233,   334,   393,
     396,   449,   454,   235,     4,   455,   118,   159,   162,   231,
     366,   367,   368,   369,   370,   377,   379,   439,   446,   159,
     309,   454,   406,   454,     6,   454,   454,   405,   329,   393,
     171,   330,   331,   391,   451,   327,   427,   179,   263,   264,
     439,   263,   263,   263,   233,   259,   260,   262,   454,   258,
     259,   261,    86,   195,   255,   330,   451,   237,   237,   223,
      30,   237,   222,   159,   237,     6,   159,   159,   135,   166,
     173,   190,   204,   213,   224,   399,   400,   174,   439,   159,
     159,   159,   202,   212,   441,   442,   159,   159,   434,   159,
     159,   434,   434,   159,   159,   159,   159,   477,   159,   477,
       3,   400,   400,   146,   223,   170,   237,    63,    64,    65,
      66,    67,    68,   191,   200,   229,   234,   445,    75,   159,
     159,   159,   299,   344,   159,   159,    55,   300,   302,   223,
     294,   295,    58,   121,   124,   125,   126,   133,   137,   142,
     149,   151,   152,   154,   175,   185,   189,   196,   198,   207,
     209,   247,   250,   382,   383,   384,   385,   387,   425,   291,
     292,   288,   289,   242,   286,   237,   222,   159,   159,   159,
     159,   146,   223,   146,   396,   146,   223,   237,   170,   237,
     392,   174,   424,   433,   434,   366,   439,   434,   369,   240,
     218,   108,   130,   138,   139,   144,   153,   156,   158,   168,
     169,   188,   206,   231,   238,   244,   245,   376,   378,   310,
     311,   454,   178,   307,   433,   241,   237,   222,   146,   223,
     223,   203,   437,   438,   439,   146,   223,   146,   260,   146,
     223,   237,   392,   223,   168,   455,   366,   241,   454,   454,
     468,   454,     6,   454,   146,   443,   454,    21,   443,   443,
     241,   435,   146,   148,   439,   444,   470,   134,   176,   217,
     380,   443,   439,   366,   243,   442,   443,   443,   443,   380,
     443,   380,   380,   380,   241,   159,   241,   439,     3,   159,
     229,   234,   473,   475,   191,   249,   454,   439,   439,   439,
     439,   382,   339,   341,   393,   343,   393,   343,   146,   223,
     300,   343,   366,   423,   454,   146,   303,   146,   223,   159,
     159,   159,   400,   400,   159,   159,   159,   159,   159,   159,
     159,   159,    95,    96,    97,   150,   345,   347,   146,   223,
     146,   223,   454,   454,     6,   454,   280,   281,   454,   280,
     280,   280,   111,   278,   283,    44,    61,    62,   104,   238,
     269,   270,   271,   393,   191,   454,     3,   454,   435,    83,
     335,   146,   367,   368,   374,   477,   374,   374,   374,   159,
     434,   179,   439,   374,   159,   434,   374,   107,   143,   145,
     439,   146,   223,   237,   308,   406,   454,     6,   454,   393,
     331,   330,   223,   428,   235,   454,   264,   168,   259,   191,
     454,   261,   264,   330,   237,   237,   146,   237,   146,   146,
     135,   166,   173,   190,   204,   213,   224,   401,   436,   223,
     400,   223,   146,   223,   439,   146,   210,   146,   146,   146,
     439,   146,   439,   439,   439,   401,     3,   401,   473,   155,
     191,   200,   223,   229,   230,   234,   474,     3,   170,   237,
     146,   223,   146,   223,   146,   344,   146,   146,   295,     3,
     388,   388,     3,   241,   159,   241,     3,   389,     3,     3,
       3,   389,   389,     3,     3,     6,   398,    87,   109,   119,
     134,   140,   176,   182,   338,   348,   349,   350,   351,   292,
     288,   237,   146,   223,   199,   220,   146,   146,   146,   269,
       3,     3,     4,   272,   271,   392,   155,   223,   237,   436,
     161,   371,   161,   373,   161,   372,   371,   229,   398,   447,
     448,   470,   373,   447,   372,   439,   311,   454,   159,   237,
     438,   458,   454,   159,   237,   392,    84,   235,   324,   454,
     454,   454,   159,   437,   400,   241,   400,   400,   146,   439,
     146,   146,   146,   146,   146,   146,   473,   473,   473,   454,
     338,   393,   393,   300,   146,   146,   146,   223,   401,     3,
     401,   223,   386,   146,   146,   223,   146,   146,   386,   146,
     146,   340,   451,   159,   350,   300,   454,    24,    25,   238,
     246,   273,   274,   275,   281,   273,   273,   273,   278,     3,
     454,   437,   375,   398,   375,   375,     3,   456,   146,   223,
     146,   218,   179,   312,   313,   439,   454,   203,   359,   363,
     263,   454,   391,   170,     3,   363,   241,   401,   241,   241,
     241,   155,   155,   223,   170,     3,   146,     3,   390,   146,
       3,   146,   159,   423,   272,     3,   275,   155,   392,   363,
     448,   439,   146,   223,   360,   362,   451,   136,   164,   195,
     357,   358,   364,   365,   420,   194,   430,   146,   392,   473,
     146,   146,   401,   401,   401,   401,   473,   473,   146,   241,
     146,   341,   146,   313,    22,    23,   223,   235,   397,   454,
       3,   233,   249,   394,   395,   421,   422,   449,   454,   366,
     366,   365,   357,   134,   176,   217,   381,   131,   192,   415,
     431,   155,   223,   155,   155,   223,   401,   146,   159,   360,
     361,   361,   193,   362,   397,   395,   223,   237,   392,   174,
     429,   432,   454,   236,   131,   473,   473,   360,   239,   239,
     159,   362,   422,   191,   454,   435,   111,   279,     3,   394,
     416,   417,   418,   432,   155,   155,   146,   366,   366,   360,
     392,   436,   223,   199,   220,   419,   279,   146,   437,   417,
     363,   430
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 402 "sql.yacc"
    {
		// chk_for_update_on_serial($<str>2);
		if ((yyvsp[(4) - (4)].ptr)==0) {
		 	A4GL_warn("UPDATE with no WHERE clause"); 
		}
		(yyval.update_cmd)=(yyvsp[(3) - (4)].update_cmd);
		(yyval.update_cmd)->table=strdup((yyvsp[(2) - (4)].str));
		(yyval.update_cmd)->where_clause=(yyvsp[(4) - (4)].ptr);
		(yyval.update_cmd)->value_list=expand_slil((yyval.update_cmd)->value_list);

		if ((yyval.update_cmd)->column_list==0) {
			char colname[200];
			int idtype;
			int isize;
			int rval;
			rval = A4GLSQL_get_columns ((yyvsp[(2) - (4)].str), colname, &idtype, &isize);
			if (rval) {
				(yyval.update_cmd)->column_list=generate_update_column_list_for((yyvsp[(2) - (4)].str),  (yyval.update_cmd)->value_list);
			}
		}
		//debug_update_cmd($<update_cmd>$);
	}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 428 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 431 "sql.yacc"
    { 
		if (A4GLSQLCV_check_requirement("NO_FOR_UPDATE"))  {
			a4gl_yyerror("Your database cannot seem to handle FOR UPDATE");
		} else {

		//rm_quotes($<str>2);
		// THIS IS HIGHLY DANGEROUS - NEVER SET DROP_WHERE_CURRENT_OF 
		// UNLESS YOU REALLY KNOW WHAT YOU ARE DOING!!!!
		if (A4GL_isyes(acl_getenv("DROP_WHERE_CURRENT_OF"))) {
			(yyval.ptr)=0;
		} else {
			(yyval.ptr)=A4GL_new_expr_simple_expr((yyvsp[(2) - (2)].ptr), ET_EXPR_WHERE_CURRENT_OF);
			A4GL_cursor_current((yyvsp[(2) - (2)].ptr));
		}
		add_feature("UPDATE_WHERE_CURRENT_OF");
		}
	}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 448 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 453 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 456 "sql.yacc"
    { 
		if (A4GLSQLCV_check_requirement("NO_FOR_UPDATE"))  {
			a4gl_yyerror("Your database cannot seem to handle FOR UPDATE");
		} else {

		//rm_quotes($<str>2);
		// THIS IS HIGHLY DANGEROUS - NEVER SET DROP_WHERE_CURRENT_OF 
		// UNLESS YOU REALLY KNOW WHAT YOU ARE DOING!!!!
		if (A4GL_isyes(acl_getenv("DROP_WHERE_CURRENT_OF"))) {
				(yyval.ptr)=0;
		} else {
			(yyval.ptr)=A4GL_new_expr_simple_expr((yyvsp[(2) - (2)].ptr), ET_EXPR_WHERE_CURRENT_OF);
                        A4GL_cursor_current((yyvsp[(2) - (2)].ptr));
		}
		add_feature("DELETE_WHERE_CURRENT_OF");
		}
	}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 473 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 479 "sql.yacc"
    {
		add_feature("UPDATE_COLUMNLIST_EQ_VALUELIST");
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=(yyvsp[(2) - (7)].str_list);
		(yyval.update_cmd)->value_list=(yyvsp[(6) - (7)].s_select_list_item_list);
		(yyval.update_cmd)->where_clause=0;
    }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 488 "sql.yacc"
    {	
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=0; 		/* A column list of 0 means .* */
		(yyval.update_cmd)->value_list=(yyvsp[(2) - (3)].s_select_list_item_list);
		(yyval.update_cmd)->where_clause=0;
		add_feature("UPDATE_SET_STAR");
    }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 497 "sql.yacc"
    {	
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=0; 		/* A column list of 0 means .* */
		(yyval.update_cmd)->value_list=(yyvsp[(2) - (3)].s_select_list_item_list);
		(yyval.update_cmd)->where_clause=0;
		 add_feature("UPDATE_SET_STAR");
    }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 506 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 513 "sql.yacc"
    {
		char buff[200];
		SPRINTF1(buff,"%s.*", (yyvsp[(2) - (2)].str));
#ifdef SQLCOMPILER
		(yyval.sql_string)=strdup("IMPOSSIBLE") ;
#else
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=0; 		//* A column list of 0 means .* 
		(yyval.update_cmd)->value_list=(yyvsp[(2) - (2)].s_select_list_item_list);
		(yyval.update_cmd)->where_clause=0;

#endif
	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 528 "sql.yacc"
    {
		char buff[200];
		SPRINTF1(buff,"%s.*", (yyvsp[(2) - (2)].str));
#ifdef SQLCOMPILER
		(yyval.sql_string)=strdup("IMPOSSIBLE") ;
#else
		(yyval.update_cmd)=malloc(sizeof(struct struct_update_cmd));
		(yyval.update_cmd)->connid=0;
		(yyval.update_cmd)->table=0;
		(yyval.update_cmd)->column_list=0; 		//* A column list of 0 means .*
		(yyval.update_cmd)->value_list=(yyvsp[(2) - (2)].s_select_list_item_list);
		//$<update_cmd>$->value_list=make_select_list_item_list_from_variable_record(buff); 
		(yyval.update_cmd)->where_clause=0;
#endif
	}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 583 "sql.yacc"
    {
		(yyval.update_cmd)=malloc(sizeof(struct_update_cmd));
		(yyval.update_cmd)->column_list=new_str_list((yyvsp[(1) - (1)].upd_pair)->column_name);
		(yyval.update_cmd)->value_list=0;
		(yyval.update_cmd)->where_clause=0;
		(yyval.update_cmd)->value_list=local_new_select_list_item_list((yyvsp[(1) - (1)].upd_pair)->value);
	}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 590 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 601 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 604 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 609 "sql.yacc"
    {
                struct ilist *i;
                i=&(yyvsp[(2) - (2)].int_list);
                if (strcmp((yyvsp[(1) - (2)].str),"rowid")==0) { add_feature("ROWID"); }
                ADDMAP("Use Column",(yyvsp[(1) - (2)].str));
                strcpy((yyval.str),A4GLSQLCV_make_substr(A4GL_confirm_colname(current_upd_table,(yyvsp[(1) - (2)].str)), i->i0,i->i1,i->i2));
        }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 616 "sql.yacc"
    {
                struct ilist *i;
                if (strcmp((yyvsp[(3) - (4)].str),"rowid")==0) { add_feature("ROWID"); }
                if (A4GLSQLCV_check_requirement("NO_UPDATE_TABLE")) {
                        strcpy((yyval.str),(yyvsp[(3) - (4)].str));
                } else {
                        if (A4GLSQLCV_check_requirement("OMIT_UPDATE_TABLE")) {
                                SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(current_upd_table,(yyvsp[(3) - (4)].str)));
                        } else {
                                SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (4)].str)),(yyvsp[(3) - (4)].str)));
                        }
                }

                ADDMAP("Use Column",(yyval.str));
                i=&(yyvsp[(4) - (4)].int_list);
                strcpy((yyval.str),A4GLSQLCV_make_substr((yyval.str),i->i0,i->i1,i->i2));
        }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 633 "sql.yacc"
    {
                struct ilist *i;
                if (strcmp((yyvsp[(5) - (6)].str),"rowid")==0) { add_feature("ROWID"); }
                if (A4GLSQLCV_check_requirement("NO_UPDATE_TABLE")) {
                        strcpy((yyval.str),(yyvsp[(5) - (6)].str));
                } else {
                        if (A4GLSQLCV_check_requirement("OMIT_UPDATE_TABLE")) {
                                SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(current_upd_table,(yyvsp[(5) - (6)].str)));
                        } else {
                                SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str)),(yyvsp[(5) - (6)].str)));
                        }
                }

                ADDMAP("Use Column",(yyval.str));
                i=&(yyvsp[(6) - (6)].int_list);
                strcpy((yyval.str),A4GLSQLCV_make_substr((yyval.str),i->i0,i->i1,i->i2));
        }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 650 "sql.yacc"
    {
                if (A4GLSQLCV_check_requirement("NO_UPDATE_TABLE")) {
                        strcpy((yyval.str),"*");
                } else {
                if (A4GLSQLCV_check_requirement("OMIT_UPDATE_TABLE")) {
                        SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(current_upd_table,"*"));
                } else {
                        SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),"*"));
                }
                }

                ADDMAP("Use Column",(yyval.str));
        }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 671 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 680 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 683 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 691 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 694 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 702 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 703 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 710 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 713 "sql.yacc"
    {
			if (A4GLSQLCV_check_requirement("ADD_CASCADE")) {
				SPRINTF1((yyval.str), "DROP TABLE %s CASCADE",(yyvsp[(2) - (2)].str));
			} else {
				SPRINTF1((yyval.str), "DROP TABLE %s",(yyvsp[(2) - (2)].str));
			}
			add_feature("DROP_TABLE");
		}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 721 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 724 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 728 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 734 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 735 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 739 "sql.yacc"
    {
                if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS")) {
                        (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,kw_ob,(yyvsp[(4) - (6)].sql_string),kw_cb,acl_strdup(" WITH OIDS "),acl_strdup((yyvsp[(6) - (6)].str)),NULL);
                } else {
                        (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,kw_ob,(yyvsp[(4) - (6)].sql_string),kw_cb,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
                }

		add_feature("CREATE_TABLE");
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 749 "sql.yacc"
    {
		char *tstr;
		tstr="";
		if (strlen((yyvsp[(6) - (8)].str))) tstr=(yyvsp[(6) - (8)].str);
		if (strlen((yyvsp[(8) - (8)].str))) tstr=(yyvsp[(8) - (8)].str);
		map_create_temp((yyvsp[(2) - (8)].str),(yyvsp[(4) - (8)].sql_string));
		(yyval.sql_string)=A4GLSQLCV_create_temp_table((yyvsp[(2) - (8)].str),(yyvsp[(4) - (8)].sql_string),tstr,(yyvsp[(7) - (8)].str));
		add_feature("CREATE_TEMP_TABLE");
		acl_free((yyvsp[(4) - (8)].sql_string));
	}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 763 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 764 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 769 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 774 "sql.yacc"
    {
			add_feature("CREATE_TABLE_IN");
                        if (A4GLSQLCV_check_requirement("OMIT_TABLE_IN")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF1((yyval.str)," IN %s",(yyvsp[(2) - (2)].str));
			}
		}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 782 "sql.yacc"
    {
			add_feature("CREATE_TABLE_WITH_EXTENT_SIZE");
                        if (A4GLSQLCV_check_requirement("OMIT_TABLE_EXTENTS")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF1((yyval.str)," EXTENT SIZE %s",(yyvsp[(2) - (2)].str)); 
			}
	}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 790 "sql.yacc"
    {
			add_feature("CREATE_TABLE_WITH_NEXT_EXTENT_SIZE");
                        if (A4GLSQLCV_check_requirement("OMIT_TABLE_EXTENTS")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF1((yyval.str)," NEXT SIZE %s",(yyvsp[(2) - (2)].str)); 
			}
	}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 798 "sql.yacc"
    {
			add_feature("CREATE_TABLE_LOCK_MODE"); 
                        if (A4GLSQLCV_check_requirement("OMIT_LOCK_MODE")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF0((yyval.str)," LOCK MODE PAGE"); 
			}
	}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 806 "sql.yacc"
    {
			add_feature("CREATE_TABLE_LOCK_MODE");
                        if (A4GLSQLCV_check_requirement("OMIT_LOCK_MODE")) {
                                strcpy((yyval.str),"");
			} else {
				SPRINTF0((yyval.str)," LOCK MODE ROW"); 
			}
	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 818 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 818 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 822 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 826 "sql.yacc"
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_IN")) {
                                strcpy((yyval.str),"");
                        } else {
                                SPRINTF1((yyval.str)," IN %s",(yyvsp[(2) - (2)].str)); add_feature("INDEX_IN");
                        }
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 833 "sql.yacc"
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_FILLFACTOR")) {
                                strcpy((yyval.str),"");
                        } else {
                                SPRINTF1((yyval.str),"FILLFACTOR %s",(yyvsp[(2) - (2)].str)); add_feature("INDEX_FILLFACTOR");
                        }
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 840 "sql.yacc"
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_USING")) {
                                strcpy((yyval.str),"");
                        } else {
                                strcpy((yyval.str),"USING BTREE"); add_feature("INDEX_BTREE");
                        }
        }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 847 "sql.yacc"
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_USING")) {
                                strcpy((yyval.str),"");
                        } else {
                                strcpy((yyval.str),"USING RTREE"); add_feature("INDEX_RTREE");
                        }
        }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 856 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 860 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 867 "sql.yacc"
    {
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		add_feature("CLUSTER_INDEX");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
		if (A4GLSQLCV_check_requirement("OMIT_INDEX_CLUSTER")) {
		SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		} else {
		SPRINTF7((yyval.str),"CREATE UNIQUE CLUSTER INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		}
	}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 879 "sql.yacc"
    {
		add_feature("CREATE_INDEX");
		add_feature("CLUSTER_INDEX");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
		if (A4GLSQLCV_check_requirement("OMIT_INDEX_CLUSTER")) {
			SPRINTF7((yyval.str),"CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		} else {
			SPRINTF7((yyval.str),"CREATE CLUSTER INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		}
	}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 890 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 896 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 900 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 904 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 909 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 913 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 916 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 920 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 923 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 930 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 931 "sql.yacc"
    {
		add_feature("SELECT_INTO_TEMP_WITH_NO_LOG");
		if (A4GLSQLCV_check_requirement("OMIT_NO_LOG")) {
			strcpy((yyval.str),"");
		} else {
			SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		}
	}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 941 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 942 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 947 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 951 "sql.yacc"
    {
		add_feature("CREATE_INDEX_ASC");
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (2)].str)));
		if (A4GLSQLCV_check_requirement("OMIT_INDEX_ORDER")) {
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (2)].str));
		} else {
			SPRINTF1((yyval.str),"%s ASC",(yyvsp[(1) - (2)].str));
		}
}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 960 "sql.yacc"
    {
		add_feature("CREATE_INDEX_DESC");
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (2)].str)));
		if (A4GLSQLCV_check_requirement("OMIT_INDEX_ORDER")) {
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (2)].str));
		} else {
			SPRINTF1((yyval.str),"%s DESC",(yyvsp[(1) - (2)].str));
		}
}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 969 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 976 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 979 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 985 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 988 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 999 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1003 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1008 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1015 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1018 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1027 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1030 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1034 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1038 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1042 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1046 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1050 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1058 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1062 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1070 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1073 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1080 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1083 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1090 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1093 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1101 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1110 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1113 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1119 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1122 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1128 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1135 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1136 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1140 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1148 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1152 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1159 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1161 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1166 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1167 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1172 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1173 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1179 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1180 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1194 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1200 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1200 "sql.yacc"
    {
		(yyval.insert_cmd)=(yyvsp[(5) - (5)].insert_cmd);
		(yyval.insert_cmd)->connid=0;
		(yyval.insert_cmd)->table=acl_strdup((yyvsp[(3) - (5)].str));
		A4GL_set_associated_mem((yyval.insert_cmd), (yyval.insert_cmd)->table);
		(yyval.insert_cmd)->column_list=(yyvsp[(4) - (5)].str_list);
	}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1209 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1209 "sql.yacc"
    { 
		(yyval.insert_cmd)=malloc(sizeof(struct_insert_cmd));
		(yyval.insert_cmd)->connid=0;
		(yyval.insert_cmd)->column_list=0;
		(yyval.insert_cmd)->table=0;
		(yyval.insert_cmd)->value_list=0;
		(yyval.insert_cmd)->subselect=0;
		(yyval.insert_cmd)->value_list= expand_slil((yyvsp[(4) - (5)].s_select_list_item_list));
	}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1218 "sql.yacc"
    {
				if ((yyvsp[(1) - (1)].s_select)->sf==0) {
				        (yyvsp[(1) - (1)].s_select)->sf=acl_malloc2(sizeof(struct s_select_finish));
					(yyvsp[(1) - (1)].s_select)->sf->order_by=0;
					(yyvsp[(1) - (1)].s_select)->sf->into_temp=0;
					(yyvsp[(1) - (1)].s_select)->sf->nolog=0;
					(yyvsp[(1) - (1)].s_select)->sf->insert_into=0;
					A4GL_set_associated_mem((yyvsp[(1) - (1)].s_select), (yyvsp[(1) - (1)].s_select)->sf);
				}
				(yyvsp[(1) - (1)].s_select)->sf->insert_into=0;
		
        			map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
				add_feature("INSERT_INTO_SELECT_FROM");
	        (yyval.insert_cmd)=malloc(sizeof(struct_insert_cmd));
                (yyval.insert_cmd)->connid=0;
                (yyval.insert_cmd)->column_list=0;
                (yyval.insert_cmd)->table=0;
                (yyval.insert_cmd)->value_list=0;
                (yyval.insert_cmd)->subselect=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1243 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1246 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1254 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1257 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1264 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1267 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1275 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1276 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1282 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1283 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1291 "sql.yacc"
    {
			//A4GL_add_crud("DELETE",$<str>2);

			if ((yyvsp[(3) - (3)].ptr)==0) { A4GL_warn("DELETE with no WHERE clause"); }
			add_feature("ANSI_DELETE");

			/* if (strstr($<sql_string>4," EXISTS ")) { add_feature("DELETE_FROM_WHERE_EXISTS_SUBSELECT"); } */ /* @FIXME - add back in */

			(yyval.delete_cmd)=malloc(sizeof(struct struct_delete_cmd));
			(yyval.delete_cmd)->connid=NULL;
			(yyval.delete_cmd)->table=acl_strdup((yyvsp[(2) - (3)].str));
			(yyval.delete_cmd)->where_clause=(yyvsp[(3) - (3)].ptr);	
			A4GL_set_associated_mem((yyval.delete_cmd), (yyval.delete_cmd)->table);
			
		}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1309 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1313 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1318 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1319 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1329 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1338 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1342 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1347 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1351 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1355 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1359 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1362 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1369 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1370 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1371 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1375 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1376 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1377 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1378 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1379 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1380 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1381 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1389 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1390 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1391 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1392 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1402 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1403 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1404 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1408 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1409 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1416 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1419 "sql.yacc"
    {
		if (A4GLSQLCV_check_requirement("SIMPLE_GRANT_SELECT"))  {
			SPRINTF0((yyval.str)," SELECT");
		} else {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1428 "sql.yacc"
    {
		if (A4GLSQLCV_check_requirement("SIMPLE_GRANT_UPDATE"))  {
			SPRINTF0((yyval.str)," UPDATE");
		} else {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1439 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1441 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1447 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1453 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1463 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1470 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1472 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1478 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1481 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1482 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1489 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1498 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1505 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1517 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1523 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1528 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1532 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1538 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1546 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1551 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1554 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1557 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1564 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1565 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1566 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1567 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1573 "sql.yacc"
    {

			A4GL_debug("Str1:%s",(yyvsp[(1) - (4)].str));
			A4GL_debug("Str2:%s",(yyvsp[(2) - (4)].str));
			A4GL_debug("Str3:%s",(yyvsp[(3) - (4)].str));
			A4GL_debug("Str4:%s",(yyvsp[(4) - (4)].sql_string));

                (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (4)].str)),kw_space,acl_strdup((yyvsp[(2) - (4)].str)),NULL);
                if (strlen((yyvsp[(3) - (4)].str))) {
                        (yyval.sql_string)=make_sql_string_and_free((yyval.sql_string), kw_space,acl_strdup((yyvsp[(3) - (4)].str)),NULL);
                }
                if (strlen((yyvsp[(4) - (4)].sql_string))) {
                        (yyval.sql_string)=make_sql_string_and_free((yyval.sql_string), kw_space,acl_strdup((yyvsp[(4) - (4)].sql_string)),NULL);
                } else {
			free((yyvsp[(4) - (4)].sql_string));
		}


	}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1594 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1598 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1600 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1607 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1610 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1616 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1624 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1629 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1635 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1640 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1646 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1649 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1654 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1663 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1672 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1681 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1687 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1690 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1701 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1710 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1717 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1723 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1724 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1727 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1732 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1743 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1747 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1755 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1759 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1763 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1767 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1774 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1779 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1787 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1790 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1796 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1799 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1804 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1809 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1822 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1825 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1831 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1834 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1840 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1843 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1849 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1852 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1859 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1863 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1874 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1874 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1875 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1875 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1876 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1876 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1879 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1889 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1890 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1895 "sql.yacc"
    { 
		if (strlen((yyvsp[(2) - (3)].str))==0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNOTNULL,(yyvsp[(1) - (3)].s_select_list_item));
		}

		add_feature("WHERE_NULL");
	}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1904 "sql.yacc"
    { 
		if (strlen((yyvsp[(2) - (3)].str))==0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNOTNULL,(yyvsp[(1) - (3)].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
		}
		add_feature("WHERE_NULL");
	}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1912 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1915 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1918 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1922 "sql.yacc"
    { 
		if (strlen((yyvsp[(2) - (6)].str))) {
			(yyval.s_select_list_item)=new_select_list_item_op_between((yyvsp[(2) - (6)].str),(yyvsp[(1) - (6)].s_select_list_item),(yyvsp[(4) - (6)].s_select_list_item),(yyvsp[(6) - (6)].s_select_list_item),1);
		} else {
			(yyval.s_select_list_item)=new_select_list_item_op_between((yyvsp[(2) - (6)].str),(yyvsp[(1) - (6)].s_select_list_item),(yyvsp[(4) - (6)].s_select_list_item),(yyvsp[(6) - (6)].s_select_list_item),0);
		}
	}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1929 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1932 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1936 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1939 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1942 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 1945 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 1951 "sql.yacc"
    {
			if (A4GLSQLCV_check_requirement("NOT_EQUAL_AS_LESS_GREATER_THAN"))  {
				strcpy((yyval.str)," <> ");
			} else {
				strcpy((yyval.str)," != ");
			}
	}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 1958 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 1961 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1964 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1967 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1968 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1973 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1976 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1979 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1982 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1989 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1990 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1991 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1995 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2002 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2003 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2004 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2008 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2022 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2037 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2041 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2042 "sql.yacc"
    {
			add_feature("DDL_SERIAL");
			if (A4GLSQLCV_check_requirement("NO_SERIAL_START_VALUE"))  {
				SPRINTF0((yyval.str),"SERIAL");
			} else {
				SPRINTF1((yyval.str),"SERIAL(%s)",(yyvsp[(3) - (4)].str));
			}
	}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 2051 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2053 "sql.yacc"
    {
			add_feature("DDL_SERIAL8");
			if (A4GLSQLCV_check_requirement("NO_SERIAL_START_VALUE"))  {
				SPRINTF0((yyval.str),"SERIAL8");
			} else {
				SPRINTF1((yyval.str),"SERIAL8(%s)",(yyvsp[(3) - (4)].str));
			}
	}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 2062 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2065 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
		if (strlen((yyvsp[(4) - (5)].str))) {
			SPRINTF2((yyval.str),"DECIMAL(%s%s)",(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str));
		} else {
			SPRINTF1((yyval.str),"DECIMAL(%s)",(yyvsp[(3) - (5)].str));
		}
	}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 2073 "sql.yacc"
    {
 			add_feature("DDL_MONEY");
		if (A4GLSQLCV_check_requirement("MONEY_AS_DECIMAL")) {
			SPRINTF2((yyval.str)," DECIMAL(%s%s)",(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str));
		} else {
			SPRINTF2((yyval.str)," MONEY(%s%s)",(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str));
		}
	}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 2083 "sql.yacc"
    {
 			add_feature("DDL_MONEY");
		if (A4GLSQLCV_check_requirement ("MONEY_AS_DECIMAL")) {
			strcpy((yyval.str),"DECIMAL");
		} else {
			strcpy((yyval.str),"MONEY");
		}
	}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 2091 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2093 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2094 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2095 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2096 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2097 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2098 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2099 "sql.yacc"
    {
			add_feature("DDL_NVARCHAR");
			if (A4GLSQLCV_check_requirement("IGNORE_DTYPE_VARCHAR_MIN"))  {
				SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (6)].str));
			} else {
				SPRINTF2((yyval.str),"NVARCHAR(%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));
			}
	}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 2107 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2108 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2109 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2110 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2111 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2112 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2113 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2114 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2115 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2116 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2117 "sql.yacc"
    {
			add_feature("DDL_VARCHAR");
			if (A4GLSQLCV_check_requirement("IGNORE_DTYPE_VARCHAR_MIN"))  {
				SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (6)].str));
			} else {
				SPRINTF2((yyval.str),"VARCHAR(%s,%s)",(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str));
			}
		}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 2127 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2128 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2135 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2139 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2164 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2165 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2169 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2177 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2180 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2187 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2190 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2200 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2203 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2206 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2209 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2216 "sql.yacc"
    { 
		struct ilist *i;
		i=&(yyvsp[(2) - (2)].int_list);
		if (strcmp((yyvsp[(1) - (2)].str),"rowid")==0) { strcpy((yyvsp[(1) - (2)].str), A4GLSQLCV_get_sqlconst ("rowid")); add_feature("ROWID"); }
		ADDMAP("Use Column",(yyvsp[(1) - (2)].str));
		strcpy((yyval.str),A4GLSQLCV_make_substr(A4GLSQLCV_check_colname(0,(yyvsp[(1) - (2)].str)), i->i0,i->i1,i->i2));
	}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 2223 "sql.yacc"
    {
		struct ilist *i;
		if (strcmp((yyvsp[(3) - (4)].str),"rowid")==0) { strcpy((yyvsp[(3) - (4)].str), A4GLSQLCV_get_sqlconst ("rowid"));  add_feature("ROWID");}
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str)));
		ADDMAP("Use Column",(yyval.str));
		i=&(yyvsp[(4) - (4)].int_list);
		strcpy((yyval.str),A4GLSQLCV_make_substr((yyval.str),i->i0,i->i1,i->i2));
	}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 2231 "sql.yacc"
    {
		struct ilist *i;
		if (strcmp((yyvsp[(3) - (6)].str),"rowid")==0) { strcpy((yyvsp[(3) - (6)].str), A4GLSQLCV_get_sqlconst ("rowid")); add_feature("ROWID"); }
		// First identifier is the owner...
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname(A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].str)),(yyvsp[(5) - (6)].str)));
		ADDMAP("Use Column",(yyval.str));
		i=&(yyvsp[(4) - (6)].int_list);
		strcpy((yyval.str),A4GLSQLCV_make_substr((yyval.str),i->i0,i->i1,i->i2));
	}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 2240 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2251 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 2259 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); 
}
    break;

  case 380:

/* Line 1455 of yacc.c  */
#line 2261 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2271 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2286 "sql.yacc"
    {
		add_sql_function((yyvsp[(2) - (4)].str));
		if (A4GLSQLCV_check_requirement("EXECUTE_PROCEDURE_AS_EXEC")) {
			SPRINTF1((yyval.str),"EXEC %s",(yyvsp[(2) - (4)].str));
		} else {
			SPRINTF1((yyval.str),"EXECUTE PROCEDURE %s ()",(yyvsp[(2) - (4)].str));
		}
	}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2294 "sql.yacc"
    {
		add_sql_function((yyvsp[(2) - (5)].str));
		if (A4GLSQLCV_check_requirement("EXECUTE_PROCEDURE_AS_EXEC")) {
			SPRINTF2((yyval.str),"EXEC %s %s",(yyvsp[(2) - (5)].str), get_select_list_item_list(0, (yyvsp[(4) - (5)].s_select_list_item_list)));
		} else {
			SPRINTF2((yyval.str),"EXECUTE PROCEDURE %s (%s)",(yyvsp[(2) - (5)].str), get_select_list_item_list(0, (yyvsp[(4) - (5)].s_select_list_item_list)));
		}
	}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2306 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2307 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2308 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2309 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2314 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2315 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2323 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2330 "sql.yacc"
    {
		add_feature("LOCK_TABLE");
		SPRINTF3((yyval.str),"%s %s %s",
					(yyvsp[(1) - (3)].str),
					(yyvsp[(2) - (3)].str),
					(yyvsp[(3) - (3)].str)
					);
		}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2341 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2342 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2355 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2356 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2360 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2364 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2365 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2368 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2374 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2378 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2401 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2411 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2414 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2420 "sql.yacc"
    {
		if (strcmp((yyvsp[(2) - (2)].str),"DESC")!=0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ASC,(yyvsp[(1) - (2)].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_DESC,(yyvsp[(1) - (2)].s_select_list_item));
		}
	}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2429 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2433 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2440 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2442 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2444 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2448 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2454 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2457 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2463 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2464 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2471 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2484 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2494 "sql.yacc"
    { 
	if (A4GLSQLCV_check_requirement("ALLOW_TIME_DATATYPE")) {
       		strcpy((yyval.str),"TIME"); break;
	} else {
       		strcpy((yyval.str),"DATETIME HOUR TO FRACTION(2)"); break;
	}
 }
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2501 "sql.yacc"
    {
	int n;
       	n=atoi((yyvsp[(3) - (4)].str));
	if (A4GLSQLCV_check_requirement("ALLOW_TIME_DATATYPE")){ 
		sprintf((yyval.str),"TIME(%d)",n);
	} else {
        	switch (n) {
                	case 0: strcpy((yyval.str),"DATETIME HOUR TO SECOND"); break; 
                	case 1: strcpy((yyval.str),"DATETIME HOUR TO FRACTION(1)"); break;
                	case 2: strcpy((yyval.str),"DATETIME HOUR TO FRACTION(2)"); break;
                	case 3: strcpy((yyval.str),"DATETIME HOUR TO FRACTION(3)"); break;
                	case 4: strcpy((yyval.str),"DATETIME HOUR TO FRACTION(4)"); break;
                	case 5: strcpy((yyval.str),"DATETIME HOUR TO FRACTION(5)"); break;
                	default: a4gl_yyerror("Invalid time"); YYERROR;
        	}
	}
    }
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2518 "sql.yacc"
    {
	if (A4GLSQLCV_check_requirement("ALLOW_TIMESTAMP_DATATYPE")) {
		strcpy((yyval.str),"TIMESTAMP");
	} else {
                strcpy((yyval.str),"DATETIME YEAR TO FRACTION(2)"); 
	}
 }
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2525 "sql.yacc"
    {
        int n;
       	n=atoi((yyvsp[(3) - (4)].str));
	if (A4GLSQLCV_check_requirement("ALLOW_TIMESTAMP_DATATYPE")) {
		sprintf((yyval.str),"TIMESTAMP(%d)",n);
	} else {
        	switch (n) {
                	case 0: strcpy((yyval.str),"DATETIME YEAR TO SECOND"); break; 
                	case 1: strcpy((yyval.str),"DATETIME YEAR TO FRACTION(1)"); break;
                	case 2: strcpy((yyval.str),"DATETIME YEAR TO FRACTION(2)"); break;
                	case 3: strcpy((yyval.str),"DATETIME YEAR TO FRACTION(3)"); break;
                	case 4: strcpy((yyval.str),"DATETIME YEAR TO FRACTION(4)"); break;
                	case 5: strcpy((yyval.str),"DATETIME YEAR TO FRACTION(5)"); break;
                	default: a4gl_yyerror("Invalid time"); YYERROR;
        	}
	}
 }
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2550 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2552 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2554 "sql.yacc"
    {


		(yyval.s_select)=(yyvsp[(8) - (10)].s_select);
		if ((yyvsp[(2) - (10)].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[(2) - (10)].integer_val);
		}
		(yyval.s_select)->modifier=acl_strdup((yyvsp[(3) - (10)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		(yyval.s_select)->into=(yyvsp[(7) - (10)].ptr_list);
		(yyval.s_select)->select_list=(yyvsp[(5) - (10)].s_select_list_item_list);
		(yyval.s_select)->next=(yyvsp[(9) - (10)].s_select);
		(yyval.s_select)->sf=(yyvsp[(10) - (10)].s_select_finish);
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->sf);
}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2575 "sql.yacc"
    {
	        (yyval.s_select)=(yyvsp[(5) - (6)].s_select);
                (yyval.s_select)->modifier=acl_strdup((yyvsp[(3) - (6)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		if ((yyvsp[(2) - (6)].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[(2) - (6)].integer_val);
		}
                (yyval.s_select)->into=0;
                (yyval.s_select)->select_list=(yyvsp[(4) - (6)].s_select_list_item_list);
		(yyval.s_select)->next=(yyvsp[(6) - (6)].s_select);
	}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2618 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 2619 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 2633 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2636 "sql.yacc"
    {  
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		(yyval.s_select_finish)->order_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->into_temp=0;
		(yyval.s_select_finish)->nolog=0;
	}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2643 "sql.yacc"
    { 
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		add_feature("SELECT_INTO_TEMP_ORDER_BY");
		(yyval.s_select_finish)->order_by=(yyvsp[(1) - (4)].s_select_list_item_list);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->into_temp=strdup((yyvsp[(3) - (4)].str));
		A4GL_set_associated_mem((yyval.s_select_finish), (yyval.s_select_finish)->into_temp);
		(yyval.s_select_finish)->nolog=(yyvsp[(4) - (4)].integer_val);

	}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2653 "sql.yacc"
    { 
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		add_feature("SELECT_INTO_TEMP");
		(yyval.s_select_finish)->order_by=0;
		(yyval.s_select_finish)->into_temp=strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_finish), (yyval.s_select_finish)->into_temp);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->nolog=(yyvsp[(3) - (3)].integer_val);
}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2671 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(5) - (5)].s_select);
		if ((yyvsp[(2) - (5)].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[(2) - (5)].integer_val);
		}
		(yyval.s_select)->modifier=acl_strdup((yyvsp[(3) - (5)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		(yyval.s_select)->select_list=(yyvsp[(4) - (5)].s_select_list_item_list);
	}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2684 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(6) - (7)].s_select);
		if ((yyvsp[(3) - (7)].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[(3) - (7)].integer_val);
		}
		(yyval.s_select)->modifier=acl_strdup((yyvsp[(4) - (7)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		(yyval.s_select)->select_list=(yyvsp[(5) - (7)].s_select_list_item_list);
		(yyval.s_select_list_item)=new_select_list_subquery((yyval.s_select));
	}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2699 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2701 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2707 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2708 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2709 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2710 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2720 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2723 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2729 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2732 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2737 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2746 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2749 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2753 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2760 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2763 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2766 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2769 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 2772 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 2775 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 2776 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 2777 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 2778 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 2779 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 2780 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 2781 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 477:

/* Line 1455 of yacc.c  */
#line 2782 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 2783 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 2785 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 2789 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 2793 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 2797 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 2801 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 484:

/* Line 1455 of yacc.c  */
#line 2805 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 485:

/* Line 1455 of yacc.c  */
#line 2809 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1455 of yacc.c  */
#line 2813 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1455 of yacc.c  */
#line 2816 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 2819 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 2822 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 2825 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 2828 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 2831 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 2834 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 494:

/* Line 1455 of yacc.c  */
#line 2837 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 2841 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 2845 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 2849 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1455 of yacc.c  */
#line 2857 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 2860 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 2869 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1455 of yacc.c  */
#line 2875 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 2882 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 2885 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 2913 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 2916 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 506:

/* Line 1455 of yacc.c  */
#line 2919 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend(new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_CURRENT),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 507:

/* Line 1455 of yacc.c  */
#line 2922 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str));
	}
    break;

  case 508:

/* Line 1455 of yacc.c  */
#line 2928 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 509:

/* Line 1455 of yacc.c  */
#line 2929 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 2930 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 511:

/* Line 1455 of yacc.c  */
#line 2931 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 2932 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 513:

/* Line 1455 of yacc.c  */
#line 2933 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 2938 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 2942 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 516:

/* Line 1455 of yacc.c  */
#line 2946 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 2950 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 2957 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 2960 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 2965 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 2966 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 2967 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 2969 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 2975 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 2985 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 2989 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 2993 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 528:

/* Line 1455 of yacc.c  */
#line 2997 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 3001 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 3005 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 3009 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 3013 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 3021 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 3031 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 3036 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 536:

/* Line 1455 of yacc.c  */
#line 3040 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 3044 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 538:

/* Line 1455 of yacc.c  */
#line 3048 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 3052 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 3057 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 3061 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 542:

/* Line 1455 of yacc.c  */
#line 3065 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 3073 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 544:

/* Line 1455 of yacc.c  */
#line 3076 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 545:

/* Line 1455 of yacc.c  */
#line 3081 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 546:

/* Line 1455 of yacc.c  */
#line 3082 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 547:

/* Line 1455 of yacc.c  */
#line 3083 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 548:

/* Line 1455 of yacc.c  */
#line 3088 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 549:

/* Line 1455 of yacc.c  */
#line 3089 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 550:

/* Line 1455 of yacc.c  */
#line 3090 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 552:

/* Line 1455 of yacc.c  */
#line 3101 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 554:

/* Line 1455 of yacc.c  */
#line 3107 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 3112 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3163 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 3170 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3176 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3191 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3192 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3194 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3196 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3199 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3203 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3212 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3218 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 576:

/* Line 1455 of yacc.c  */
#line 3219 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3222 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3227 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3228 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3232 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3233 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3243 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3244 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3245 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3246 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3247 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3248 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3249 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3250 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3254 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3260 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3262 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3281 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3289 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3296 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3297 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3298 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3299 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3304 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 3305 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 3306 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3307 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3308 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3313 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3314 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3330 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3331 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 609:

/* Line 1455 of yacc.c  */
#line 3332 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 3333 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3334 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3335 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3336 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3337 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3338 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3339 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3341 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3342 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3343 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3344 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3349 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3352 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3361 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3362 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3363 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3364 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3365 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3366 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 3370 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 3371 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1455 of yacc.c  */
#line 8871 "y.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 3376 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

