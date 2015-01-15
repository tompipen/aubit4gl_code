/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.3"

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


#define A4GL_add_feature sqlc_A4GL_add_feature
#define A4GL_cursor_current sqlc_A4GL_cursor_current
#define A4GL_warn sqlc_A4GL_warn
#define add_feature sqlc_A4GL_add_feature
#define add_sql_function sqlc_add_sql_function
#define expand_slil sqlc_expand_slil
#define expand_slil sqlc_expand_slil
#define generate_update_column_list_for sqlc_generate_update_column_list_for
#define generate_update_column_list_for sqlc_generate_update_column_list_for
#define local_add_select_list_item_list sqlc_local_add_select_list_item_list
#define local_add_select_list_item_list sqlc_local_add_select_list_item_list
#define set_ignore_indicators sqlc_set_ignore_indicators
#define clr_ignore_indicators sqlc_clr_ignore_indicators
#define local_new_select_list_item_list sqlc_local_new_select_list_item_list
#define addmap sqlc_addmap
#define map_select_stmt sqlc_map_select_stmt
#define map_create_temp sqlc_map_create_temp
#define A4GL_db_used sqlc_A4GL_db_used
#define map_delete_update sqlc_map_delete_update

void add_sql_function(char *s);
void map_select_stmt (char *main_statement_type, struct s_select *select);
void map_create_temp(char *tab, char *src);

void A4GL_add_feature (char *feature);


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

#define insql c_sql_insql
int c_sql_insql=0;
static char *make_sql_string_and_free(char *,...);
char last_tmp_name[256];
#define ADDMAP(x,y) addmap_runtime(x,y)
#define ADDMAP_MODULE(x,y) addmap_runtime(x,y)

int yylineno;
//int table_cnt=0;
//char* curr_func="";
//char *infilename="";
static int doing_declare=0;
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
#line 223 "y.tab.c"

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
     INT_VALUE = 2283,
     NAMED = 2284,
     NAMED_GEN = 2285,
     CHAR_VALUE = 2286,
     NOT_USED_1 = 2287,
     NOT_USED_2 = 2288,
     NOT_USED_3 = 2289,
     NOT_USED_4 = 2290,
     NOT_USED_5 = 2291,
     NOT_USED_6 = 2292,
     NOT_USED_7 = 2293,
     NOT_USED_8 = 2294,
     NUMBER_VALUE = 2295,
     SEMICOLON = 2296,
     QUESTION_MARK = 2297,
     CLINE = 2298,
     CH = 2299,
     MARK_VAR = 2300,
     END_MARK_VAR = 2301,
     END_DIALOG = 1000,
     ACCEPT_DIALOG = 1001,
     EXIT_DIALOG = 1002,
     CONTINUE_DIALOG = 1003,
     AFTER_DIALOG = 1004,
     BEFORE_DIALOG = 1005,
     COUNT_OB = 1007,
     SUM_OB = 1008,
     XMAX_OB = 1009,
     XMIN_OB = 1010,
     AVG_OB = 1011,
     PERCENT_OB = 1012,
     WITH_LISTING_IN = 1013,
     BACKQUOTE = 1014,
     SET_UNDERLINE_ON = 1015,
     SET_UNDERLINE_OFF = 1016,
     SET_POSTGRESQL_SEARCH_PATH = 1017,
     SET_CONSTRAINTS_ALL_DEFERRED = 1018,
     KW_LIMIT = 1019,
     DOCUMENT = 1020,
     ON_EXCEPTION = 1022,
     SET_DEBUG_FILE_TO = 1023,
     CREATE_DBA_PROCEDURE = 1028,
     CREATE_FUNCTION = 1029,
     CREATE_DBA_FUNCTION = 1030,
     USE_SESSION = 1032,
     KW_RUN_CLIENT = 1033,
     LEFT_JOIN = 1035,
     IGNORE_ERRORS = 1038,
     SQLERRMESSAGE = 1039,
     DISPLAY_NULL_TO = 1040,
     UNBUFFERED = 1041,
     KW_PICTURE = 1042,
     ON_CHANGE = 1043,
     INNER_JOIN = 1044,
     UI_INTERFACE_DOT_FRONTCALL = 1047,
     UICOMBOBOX = 1051,
     UIBROWSER = 1052,
     UIPROGRESS = 1053,
     UIGANTT = 1054,
     UIFORM = 1057,
     USING_BTREE = 1073,
     USING_RTREE = 1074,
     RESUME_PAGE = 1085,
     FOR_EVERY_PAGE = 1086,
     SET_BUFFERED_LOG = 1095,
     SET_LOG = 1098,
     MDY = 1100,
     WEEKDAY = 1101,
     MODE_ANSI = 1104,
     START_DATABASE = 1105,
     WITH_LOG_IN = 1106,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1107,
     DATETIME_VALUE = 1120,
     INTERVAL_VALUE = 1121,
     RECOVER_TABLE = 1122,
     ROLLFORWARD_DATABASE = 1123,
     CONCAT_PIPES = 1137,
     DROP_TRIGGER = 1139,
     DROP_AUDIT_FOR = 1140,
     CREATE_AUDIT_FOR = 1141,
     EXECUTE_PROCEDURE = 1145,
     CURRENT_FIELD_DISPLAY_EQUAL = 1150,
     ALTER_TABLE = 1153,
     ALTER_INDEX = 1154,
     NEXT_SIZE = 1155,
     KW_WHENEVER_SIGNAL = 1192,
     KW_SIGNAL_TOKEN = 1193,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1194,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1195,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1196,
     XSET_MULTIPLY_EQUAL = 1197,
     XSET_OPEN_BRACKET = 1198,
     CREATE_DATABASE = 1201,
     DROP_DATABASE = 1202,
     ADD_CONSTRAINT = 1204,
     DROP_CONSTRAINT = 1205,
     DROP_SYNONYM = 1206,
     CONSTRAINT = 1207,
     NOT_FIELD_TOUCHED_CURRENT = 1210,
     FIELD_TOUCHED_CURRENT = 1211,
     OBJECT_FUNCTION = 1213,
     DOUBLE_PRECISION = 1219,
     COUNT_MULTIPLY = 1220,
     KW_ASCII_OPEN_BRACKET = 1229,
     MODIFY_NEXT_SIZE = 1241,
     LOCK_MODE_PAGE = 1242,
     LOCK_MODE_ROW = 1243,
     TO_UI = 1248,
     UNITS_YEAR = 1251,
     UNITS_MONTH = 1252,
     UNITS_DAY = 1253,
     UNITS_HOUR = 1254,
     UNITS_MINUTE = 1255,
     UNITS_SECOND = 1256,
     TO_CLUSTER = 1261,
     TO_NOT_CLUSTER = 1262,
     CREATE_UC_IDX = 1264,
     CREATE_U_IDX = 1265,
     CREATE_C_IDX = 1266,
     CREATE_IDX = 1267,
     DOUBLE_COLON = 1277,
     SQLSICS = 1283,
     CREATE_SCHEMA = 1284,
     SQLSIRR = 1285,
     UPDATESTATS_T = 1286,
     SQLSICR = 1287,
     SQLSIDR = 1298,
     CREATE_TEMP_TABLE = 1299,
     WITH_CHECK_OPTION = 1307,
     WITH_GRANT_OPTION = 1308,
     SQLSLMNW = 1309,
     WHERE_CURRENT_OF = 1315,
     NOT_NULL_UNIQUE = 1323,
     SQLSLMW = 1330,
     ALL_PRIVILEGES = 1332,
     CREATE_SYNONYM = 1336,
     DROP_TABLE = 1337,
     INEXCLUSIVE = 1339,
     REPORT_TO_FILE = 1340,
     REPORT_TO_UI = 1341,
     UPDATESTATS = 1346,
     CREATE_TABLE = 1372,
     DEFAULT_NULL = 1373,
     DEFAULT_TODAY = 1374,
     DEFAULT_USER = 1375,
     EXIT_TODO = 1382,
     CONTINUE_TODO = 1383,
     UNLOCK_TABLE = 1390,
     ROLLBACK_W = 1398,
     SQLSEON = 1400,
     SQLSEOFF = 1401,
     CREATE_VIEW = 1405,
     DELETE_FROM = 1406,
     EXTENT_SIZE = 1413,
     FOREIGN_KEY = 1414,
     INSERT_INTO = 1417,
     IS_NOT_NULL = 1419,
     NOT_MATCHES = 1422,
     PRIMARY_KEY = 1428,
     WITH_NO_LOG = 1435,
     INSHARE = 1438,
     BEGIN_WORK = 1444,
     DROP_INDEX = 1449,
     FOR_UPDATE_OF = 1455,
     FOR_UPDATE = 1456,
     LOCK_TABLE = 1461,
     NOT_EXISTS = 1463,
     REFERENCES = 1465,
     RENCOL = 1466,
     SMALLFLOAT = 1468,
     COMMIT_W = 1479,
     RENTAB = 1486,
     KW_CHAR = 1489,
     NCHAR = 1490,
     NVARCHAR = 1491,
     DELIMITER = 1493,
     DROP_VIEW = 1495,
     EXCLUSIVE = 1498,
     GREATER_THAN_EQ = 1502,
     INTO_TEMP = 1504,
     DATABASE = 1528,
     DATETIME = 1529,
     DISTINCT = 1531,
     FRACTION = 1538,
     GROUP_BY = 1540,
     INTERVAL = 1541,
     NOT_LIKE = 1543,
     NOT_ILIKE = 1544,
     NOT_NULL = 1545,
     RESOURCE = 1551,
     SMALLINT = 1552,
     IS_NULL = 1558,
     LESS_THAN_EQ = 1559,
     BETWEEN = 1561,
     CLOSE_BRACKET = 1564,
     CONNECT = 1567,
     KW_CURRENT = 1568,
     KW_DECIMAL = 1570,
     KW_DEFAULT = 1572,
     FGL_SYNCFIELDS = 1580,
     INTEGER = 1581,
     SERIAL8 = 1583,
     MATCHES = 1586,
     VARCHAR = 1599,
     CLOSE_SQUARE = 1602,
     GREATER_THAN = 1603,
     KW_FALSE = 1604,
     NOT_IN = 1605,
     OPEN_BRACKET_SELECT = 1607,
     OPEN_BRACKET = 1608,
     KW_DELETE = 1616,
     KW_ESCAPE = 1619,
     EXISTS = 1620,
     EXTEND = 1621,
     HAVING = 1625,
     KW_INSERT = 1627,
     MINUTE = 1631,
     MODIFY = 1632,
     EQUAL = 1634,
     NOT_EQUAL = 1635,
     OPEN_SQUARE = 1637,
     PUBLIC = 1641,
     KW_RETURN_KEY = 1644,
     REVOKE = 1646,
     SECOND = 1650,
     KW_SELECT = 1654,
     SERIAL = 1655,
     UNIQUE = 1658,
     KW_UPDATE = 1660,
     VALUES = 1661,
     KW_NULL = 1664,
     KW_TRUE = 1665,
     ALTER = 1667,
     CHECK = 1673,
     KW_FIRST = 1681,
     KW_FLOAT = 1682,
     GRANT = 1685,
     INDEX = 1688,
     LESS_THAN = 1691,
     MONEY = 1693,
     MONTH = 1694,
     KW_MULTIPLY = 1696,
     ORDER = 1697,
     OUTER = 1698,
     UNION = 1707,
     WHERE = 1710,
     KW_BYTE = 1717,
     CASE = 1719,
     KW_DATE = 1721,
     DESC = 1722,
     KW_DIVIDE = 1723,
     DROP = 1726,
     ELSE = 1727,
     FROM = 1731,
     HOUR = 1737,
     INTO = 1738,
     LIKE = 1741,
     REAL = 1750,
     SOME = 1755,
     KW_TEXT = 1759,
     KW_THEN = 1760,
     USER = 1761,
     WHEN = 1763,
     YEAR = 1766,
     KW_DOW = 1767,
     XSET = 1769,
     ADD = 1770,
     ALL = 1771,
     KW_AND = 1772,
     ANY = 1773,
     ASC = 1774,
     AVG = 1775,
     COLON = 1776,
     KW_COMMA = 1777,
     DAY = 1778,
     DBA = 1779,
     KW_FOR = 1783,
     XMAX = 1788,
     XMIN = 1789,
     KW_MINUS = 1790,
     KW_MOD = 1791,
     KW_NOT = 1792,
     KW_SUM = 1799,
     ATSIGN = 1802,
     KW_PLUS = 1803,
     KW_AS = 1809,
     KW_BY = 1811,
     KW_DOT = 1812,
     KW_IN = 1815,
     KW_ON = 1817,
     KW_OR = 1818,
     KW_TO = 1819,
     BEFORE = 1857,
     END = 1861,
     TILDE = 1868,
     ILIKE = 1869,
     FILLFACTOR = 1872,
     TIME = 1877,
     KW_TODAY = 1884,
     KW_ROWID = 1885,
     TIMESTAMP = 2233,
     KWPIPE = 2263,
     COUNT = 2276,
     DIALOG = 2277,
     SUBDIALOG = 2278,
     PDF_XY = 2279,
     SET_VALUE = 2280,
     KW_EMBEDDED = 2281
   };
#endif
/* Tokens.  */
#define INT_VALUE 2283
#define NAMED 2284
#define NAMED_GEN 2285
#define CHAR_VALUE 2286
#define NOT_USED_1 2287
#define NOT_USED_2 2288
#define NOT_USED_3 2289
#define NOT_USED_4 2290
#define NOT_USED_5 2291
#define NOT_USED_6 2292
#define NOT_USED_7 2293
#define NOT_USED_8 2294
#define NUMBER_VALUE 2295
#define SEMICOLON 2296
#define QUESTION_MARK 2297
#define CLINE 2298
#define CH 2299
#define MARK_VAR 2300
#define END_MARK_VAR 2301
#define END_DIALOG 1000
#define ACCEPT_DIALOG 1001
#define EXIT_DIALOG 1002
#define CONTINUE_DIALOG 1003
#define AFTER_DIALOG 1004
#define BEFORE_DIALOG 1005
#define COUNT_OB 1007
#define SUM_OB 1008
#define XMAX_OB 1009
#define XMIN_OB 1010
#define AVG_OB 1011
#define PERCENT_OB 1012
#define WITH_LISTING_IN 1013
#define BACKQUOTE 1014
#define SET_UNDERLINE_ON 1015
#define SET_UNDERLINE_OFF 1016
#define SET_POSTGRESQL_SEARCH_PATH 1017
#define SET_CONSTRAINTS_ALL_DEFERRED 1018
#define KW_LIMIT 1019
#define DOCUMENT 1020
#define ON_EXCEPTION 1022
#define SET_DEBUG_FILE_TO 1023
#define CREATE_DBA_PROCEDURE 1028
#define CREATE_FUNCTION 1029
#define CREATE_DBA_FUNCTION 1030
#define USE_SESSION 1032
#define KW_RUN_CLIENT 1033
#define LEFT_JOIN 1035
#define IGNORE_ERRORS 1038
#define SQLERRMESSAGE 1039
#define DISPLAY_NULL_TO 1040
#define UNBUFFERED 1041
#define KW_PICTURE 1042
#define ON_CHANGE 1043
#define INNER_JOIN 1044
#define UI_INTERFACE_DOT_FRONTCALL 1047
#define UICOMBOBOX 1051
#define UIBROWSER 1052
#define UIPROGRESS 1053
#define UIGANTT 1054
#define UIFORM 1057
#define USING_BTREE 1073
#define USING_RTREE 1074
#define RESUME_PAGE 1085
#define FOR_EVERY_PAGE 1086
#define SET_BUFFERED_LOG 1095
#define SET_LOG 1098
#define MDY 1100
#define WEEKDAY 1101
#define MODE_ANSI 1104
#define START_DATABASE 1105
#define WITH_LOG_IN 1106
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1107
#define DATETIME_VALUE 1120
#define INTERVAL_VALUE 1121
#define RECOVER_TABLE 1122
#define ROLLFORWARD_DATABASE 1123
#define CONCAT_PIPES 1137
#define DROP_TRIGGER 1139
#define DROP_AUDIT_FOR 1140
#define CREATE_AUDIT_FOR 1141
#define EXECUTE_PROCEDURE 1145
#define CURRENT_FIELD_DISPLAY_EQUAL 1150
#define ALTER_TABLE 1153
#define ALTER_INDEX 1154
#define NEXT_SIZE 1155
#define KW_WHENEVER_SIGNAL 1192
#define KW_SIGNAL_TOKEN 1193
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1194
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1195
#define XSET_ident_DOT_MULTIPLY_EQUAL 1196
#define XSET_MULTIPLY_EQUAL 1197
#define XSET_OPEN_BRACKET 1198
#define CREATE_DATABASE 1201
#define DROP_DATABASE 1202
#define ADD_CONSTRAINT 1204
#define DROP_CONSTRAINT 1205
#define DROP_SYNONYM 1206
#define CONSTRAINT 1207
#define NOT_FIELD_TOUCHED_CURRENT 1210
#define FIELD_TOUCHED_CURRENT 1211
#define OBJECT_FUNCTION 1213
#define DOUBLE_PRECISION 1219
#define COUNT_MULTIPLY 1220
#define KW_ASCII_OPEN_BRACKET 1229
#define MODIFY_NEXT_SIZE 1241
#define LOCK_MODE_PAGE 1242
#define LOCK_MODE_ROW 1243
#define TO_UI 1248
#define UNITS_YEAR 1251
#define UNITS_MONTH 1252
#define UNITS_DAY 1253
#define UNITS_HOUR 1254
#define UNITS_MINUTE 1255
#define UNITS_SECOND 1256
#define TO_CLUSTER 1261
#define TO_NOT_CLUSTER 1262
#define CREATE_UC_IDX 1264
#define CREATE_U_IDX 1265
#define CREATE_C_IDX 1266
#define CREATE_IDX 1267
#define DOUBLE_COLON 1277
#define SQLSICS 1283
#define CREATE_SCHEMA 1284
#define SQLSIRR 1285
#define UPDATESTATS_T 1286
#define SQLSICR 1287
#define SQLSIDR 1298
#define CREATE_TEMP_TABLE 1299
#define WITH_CHECK_OPTION 1307
#define WITH_GRANT_OPTION 1308
#define SQLSLMNW 1309
#define WHERE_CURRENT_OF 1315
#define NOT_NULL_UNIQUE 1323
#define SQLSLMW 1330
#define ALL_PRIVILEGES 1332
#define CREATE_SYNONYM 1336
#define DROP_TABLE 1337
#define INEXCLUSIVE 1339
#define REPORT_TO_FILE 1340
#define REPORT_TO_UI 1341
#define UPDATESTATS 1346
#define CREATE_TABLE 1372
#define DEFAULT_NULL 1373
#define DEFAULT_TODAY 1374
#define DEFAULT_USER 1375
#define EXIT_TODO 1382
#define CONTINUE_TODO 1383
#define UNLOCK_TABLE 1390
#define ROLLBACK_W 1398
#define SQLSEON 1400
#define SQLSEOFF 1401
#define CREATE_VIEW 1405
#define DELETE_FROM 1406
#define EXTENT_SIZE 1413
#define FOREIGN_KEY 1414
#define INSERT_INTO 1417
#define IS_NOT_NULL 1419
#define NOT_MATCHES 1422
#define PRIMARY_KEY 1428
#define WITH_NO_LOG 1435
#define INSHARE 1438
#define BEGIN_WORK 1444
#define DROP_INDEX 1449
#define FOR_UPDATE_OF 1455
#define FOR_UPDATE 1456
#define LOCK_TABLE 1461
#define NOT_EXISTS 1463
#define REFERENCES 1465
#define RENCOL 1466
#define SMALLFLOAT 1468
#define COMMIT_W 1479
#define RENTAB 1486
#define KW_CHAR 1489
#define NCHAR 1490
#define NVARCHAR 1491
#define DELIMITER 1493
#define DROP_VIEW 1495
#define EXCLUSIVE 1498
#define GREATER_THAN_EQ 1502
#define INTO_TEMP 1504
#define DATABASE 1528
#define DATETIME 1529
#define DISTINCT 1531
#define FRACTION 1538
#define GROUP_BY 1540
#define INTERVAL 1541
#define NOT_LIKE 1543
#define NOT_ILIKE 1544
#define NOT_NULL 1545
#define RESOURCE 1551
#define SMALLINT 1552
#define IS_NULL 1558
#define LESS_THAN_EQ 1559
#define BETWEEN 1561
#define CLOSE_BRACKET 1564
#define CONNECT 1567
#define KW_CURRENT 1568
#define KW_DECIMAL 1570
#define KW_DEFAULT 1572
#define FGL_SYNCFIELDS 1580
#define INTEGER 1581
#define SERIAL8 1583
#define MATCHES 1586
#define VARCHAR 1599
#define CLOSE_SQUARE 1602
#define GREATER_THAN 1603
#define KW_FALSE 1604
#define NOT_IN 1605
#define OPEN_BRACKET_SELECT 1607
#define OPEN_BRACKET 1608
#define KW_DELETE 1616
#define KW_ESCAPE 1619
#define EXISTS 1620
#define EXTEND 1621
#define HAVING 1625
#define KW_INSERT 1627
#define MINUTE 1631
#define MODIFY 1632
#define EQUAL 1634
#define NOT_EQUAL 1635
#define OPEN_SQUARE 1637
#define PUBLIC 1641
#define KW_RETURN_KEY 1644
#define REVOKE 1646
#define SECOND 1650
#define KW_SELECT 1654
#define SERIAL 1655
#define UNIQUE 1658
#define KW_UPDATE 1660
#define VALUES 1661
#define KW_NULL 1664
#define KW_TRUE 1665
#define ALTER 1667
#define CHECK 1673
#define KW_FIRST 1681
#define KW_FLOAT 1682
#define GRANT 1685
#define INDEX 1688
#define LESS_THAN 1691
#define MONEY 1693
#define MONTH 1694
#define KW_MULTIPLY 1696
#define ORDER 1697
#define OUTER 1698
#define UNION 1707
#define WHERE 1710
#define KW_BYTE 1717
#define CASE 1719
#define KW_DATE 1721
#define DESC 1722
#define KW_DIVIDE 1723
#define DROP 1726
#define ELSE 1727
#define FROM 1731
#define HOUR 1737
#define INTO 1738
#define LIKE 1741
#define REAL 1750
#define SOME 1755
#define KW_TEXT 1759
#define KW_THEN 1760
#define USER 1761
#define WHEN 1763
#define YEAR 1766
#define KW_DOW 1767
#define XSET 1769
#define ADD 1770
#define ALL 1771
#define KW_AND 1772
#define ANY 1773
#define ASC 1774
#define AVG 1775
#define COLON 1776
#define KW_COMMA 1777
#define DAY 1778
#define DBA 1779
#define KW_FOR 1783
#define XMAX 1788
#define XMIN 1789
#define KW_MINUS 1790
#define KW_MOD 1791
#define KW_NOT 1792
#define KW_SUM 1799
#define ATSIGN 1802
#define KW_PLUS 1803
#define KW_AS 1809
#define KW_BY 1811
#define KW_DOT 1812
#define KW_IN 1815
#define KW_ON 1817
#define KW_OR 1818
#define KW_TO 1819
#define BEFORE 1857
#define END 1861
#define TILDE 1868
#define ILIKE 1869
#define FILLFACTOR 1872
#define TIME 1877
#define KW_TODAY 1884
#define KW_ROWID 1885
#define TIMESTAMP 2233
#define KWPIPE 2263
#define COUNT 2276
#define DIALOG 2277
#define SUBDIALOG 2278
#define PDF_XY 2279
#define SET_VALUE 2280
#define KW_EMBEDDED 2281




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 145 "sql.yacc"

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
#line 904 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 916 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  155
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  311
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  229
/* YYNRULES -- Number of rules.  */
#define YYNRULES  633
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
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
      22,    23,    24,    25,    26,    27,     2,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     2,    42,    43,     2,     2,     2,     2,    44,    45,
      46,     2,    47,    48,     2,    49,     2,     2,    50,    51,
      52,    53,    54,    55,    56,     2,     2,    57,     2,     2,
       2,    58,    59,    60,    61,     2,     2,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    65,    66,     2,     2,     2,
       2,     2,     2,     2,     2,    67,     2,     2,    68,     2,
      69,    70,     2,     2,    71,    72,    73,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      75,    76,    77,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    79,     2,    80,
      81,    82,     2,     2,     2,    83,     2,     2,     2,     2,
      84,     2,     2,    85,    86,    87,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    88,    89,    90,    91,    92,    93,    94,     2,
       2,    95,    96,     2,    97,    98,    99,   100,     2,     2,
     101,   102,     2,   103,     2,     2,     2,     2,     2,   104,
     105,     2,     2,     2,     2,     2,     2,     2,     2,   106,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   107,   108,   109,     2,     2,     2,     2,   110,     2,
       2,   111,   112,   113,   114,   115,   116,     2,     2,     2,
       2,   117,   118,     2,   119,   120,   121,   122,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   123,     2,     2,
       2,     2,     2,   124,   125,   126,   127,   128,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   129,   130,
       2,     2,     2,     2,     2,     2,     2,   131,   132,   133,
       2,     2,     2,     2,     2,   134,     2,     2,     2,     2,
       2,     2,     2,   135,     2,     2,     2,     2,     2,     2,
     136,     2,   137,     2,     2,     2,   138,   139,     2,   140,
     141,   142,     2,     2,     2,     2,   143,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   144,   145,   146,   147,     2,     2,     2,     2,
       2,     2,   148,   149,     2,     2,     2,     2,     2,     2,
     150,     2,     2,     2,     2,     2,     2,     2,   151,     2,
     152,   153,     2,     2,     2,   154,   155,     2,     2,     2,
       2,     2,     2,   156,   157,     2,     2,   158,     2,   159,
       2,     2,   160,     2,     2,     2,     2,     2,   161,     2,
       2,     2,     2,     2,     2,   162,     2,     2,   163,     2,
       2,     2,     2,     2,   164,     2,     2,     2,     2,   165,
       2,     2,     2,     2,     2,   166,   167,     2,     2,     2,
       2,   168,     2,   169,     2,   170,   171,     2,   172,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   173,
       2,     2,     2,     2,     2,     2,   174,     2,     2,   175,
     176,   177,     2,   178,     2,   179,     2,     2,   180,     2,
       2,     2,   181,     2,   182,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   183,   184,
       2,   185,     2,     2,     2,     2,     2,     2,   186,     2,
     187,   188,     2,   189,   190,   191,     2,     2,     2,     2,
       2,   192,   193,     2,     2,     2,     2,     2,   194,   195,
       2,   196,     2,     2,   197,     2,     2,   198,   199,     2,
     200,     2,   201,     2,     2,     2,     2,     2,     2,     2,
     202,   203,     2,   204,     2,     2,   205,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   206,
       2,     2,   207,   208,   209,   210,     2,   211,   212,     2,
       2,     2,     2,     2,     2,     2,   213,     2,     2,   214,
     215,   216,     2,     2,     2,   217,     2,   218,     2,     2,
       2,   219,   220,     2,   221,   222,     2,   223,     2,     2,
       2,   224,     2,     2,   225,     2,   226,     2,     2,     2,
     227,     2,     2,     2,   228,   229,     2,     2,   230,     2,
     231,   232,     2,     2,   233,   234,     2,   235,     2,     2,
       2,     2,     2,   236,     2,     2,     2,     2,     2,     2,
       2,   237,   238,     2,     2,   239,     2,     2,   240,     2,
       2,   241,     2,   242,   243,     2,   244,   245,   246,     2,
       2,     2,     2,     2,     2,     2,     2,   247,     2,     2,
     248,     2,     2,     2,     2,     2,     2,   249,     2,   250,
       2,   251,   252,   253,     2,     2,   254,   255,     2,     2,
       2,   256,     2,     2,     2,     2,     2,   257,   258,     2,
       2,   259,     2,     2,     2,     2,     2,     2,     2,     2,
     260,     2,     2,     2,     2,   261,     2,     2,     2,   262,
     263,   264,     2,   265,     2,     2,   266,   267,     2,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
       2,     2,     2,   279,     2,     2,     2,     2,   280,   281,
     282,   283,   284,     2,     2,     2,     2,     2,     2,   285,
       2,     2,   286,   287,     2,     2,     2,     2,     2,   288,
       2,   289,   290,     2,     2,   291,     2,   292,   293,   294,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   295,     2,     2,
       2,   296,     2,     2,     2,     2,     2,     2,   297,   298,
       2,     2,   299,     2,     2,     2,     2,   300,     2,     2,
       2,     2,     2,     2,   301,   302,     2,     2,     2,     2,
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
       2,     2,     2,   303,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   304,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   305,   306,   307,   308,
     309,   310,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    10,    13,    16,    17,    20,    23,
      31,    35,    39,    42,    45,    48,    50,    54,    56,    59,
      62,    67,    74,    78,    82,    84,    88,    90,    94,    96,
      98,   100,   103,   106,   109,   112,   114,   116,   123,   132,
     133,   135,   137,   140,   143,   146,   149,   151,   153,   155,
     156,   158,   160,   163,   166,   169,   171,   173,   175,   184,
     193,   202,   211,   214,   217,   222,   227,   230,   233,   236,
     239,   240,   242,   243,   245,   247,   251,   254,   257,   259,
     261,   265,   267,   269,   273,   277,   281,   283,   287,   289,
     291,   293,   295,   297,   299,   301,   304,   309,   311,   315,
     317,   321,   324,   329,   331,   335,   337,   340,   345,   347,
     351,   353,   355,   357,   360,   364,   369,   372,   377,   378,
     381,   384,   389,   391,   395,   397,   399,   400,   406,   407,
     413,   415,   416,   420,   422,   426,   428,   432,   434,   438,
     440,   442,   447,   449,   451,   452,   454,   456,   462,   467,
     469,   471,   473,   476,   478,   480,   482,   484,   486,   488,
     490,   492,   494,   496,   498,   506,   513,   518,   523,   525,
     527,   529,   530,   532,   535,   537,   539,   541,   543,   547,
     550,   552,   554,   557,   559,   561,   562,   566,   568,   572,
     574,   578,   580,   582,   589,   590,   594,   596,   600,   601,
     603,   608,   614,   617,   619,   621,   626,   628,   632,   637,
     642,   647,   649,   653,   655,   657,   659,   662,   664,   666,
     668,   673,   674,   676,   677,   679,   681,   684,   687,   689,
     691,   693,   695,   697,   702,   704,   708,   710,   712,   714,
     717,   719,   721,   724,   727,   730,   732,   736,   741,   748,
     754,   760,   762,   766,   768,   771,   775,   776,   779,   781,
     784,   785,   787,   790,   792,   794,   798,   800,   804,   806,
     809,   811,   815,   818,   821,   822,   825,   826,   829,   830,
     833,   835,   837,   838,   840,   844,   848,   852,   856,   860,
     867,   872,   877,   882,   887,   892,   897,   899,   901,   903,
     905,   907,   909,   911,   913,   915,   917,   918,   920,   922,
     924,   925,   927,   929,   931,   933,   935,   937,   939,   941,
     946,   948,   953,   955,   960,   962,   968,   974,   976,   978,
     980,   982,   984,   989,   991,   996,  1003,  1008,  1010,  1015,
    1017,  1019,  1027,  1029,  1031,  1033,  1038,  1045,  1046,  1049,
    1054,  1056,  1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,
    1073,  1077,  1083,  1085,  1088,  1090,  1093,  1096,  1101,  1105,
    1107,  1110,  1115,  1122,  1126,  1128,  1130,  1132,  1134,  1136,
    1137,  1141,  1143,  1145,  1147,  1149,  1151,  1153,  1155,  1157,
    1159,  1161,  1163,  1165,  1167,  1169,  1174,  1176,  1178,  1180,
    1185,  1192,  1194,  1196,  1199,  1203,  1205,  1207,  1209,  1214,
    1216,  1218,  1226,  1231,  1233,  1236,  1240,  1242,  1246,  1249,
    1251,  1253,  1254,  1256,  1258,  1261,  1263,  1267,  1269,  1271,
    1273,  1275,  1277,  1282,  1284,  1289,  1290,  1291,  1302,  1309,
    1310,  1314,  1315,  1317,  1322,  1326,  1328,  1334,  1341,  1342,
    1345,  1346,  1348,  1350,  1352,  1354,  1356,  1360,  1362,  1365,
    1369,  1371,  1374,  1377,  1381,  1384,  1388,  1392,  1396,  1400,
    1402,  1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,  1424,
    1430,  1436,  1442,  1448,  1452,  1457,  1462,  1467,  1472,  1477,
    1482,  1487,  1492,  1496,  1501,  1503,  1505,  1509,  1514,  1516,
    1519,  1524,  1527,  1529,  1533,  1534,  1539,  1543,  1544,  1547,
    1550,  1552,  1554,  1556,  1558,  1560,  1562,  1568,  1572,  1578,
    1582,  1584,  1588,  1590,  1592,  1595,  1598,  1600,  1602,  1606,
    1608,  1612,  1618,  1622,  1628,  1636,  1638,  1642,  1646,  1648,
    1650,  1654,  1660,  1664,  1670,  1678,  1682,  1684,  1686,  1690,
    1696,  1700,  1706,  1714,  1716,  1718,  1720,  1723,  1725,  1727,
    1728,  1730,  1732,  1736,  1738,  1740,  1742,  1743,  1745,  1747,
    1749,  1751,  1753,  1755,  1757,  1760,  1762,  1764,  1765,  1767,
    1770,  1772,  1776,  1778,  1782,  1788,  1790,  1792,  1795,  1797,
    1799,  1801,  1803,  1805,  1807,  1809,  1811,  1815,  1819,  1823,
    1827,  1829,  1832,  1834,  1836,  1838,  1840,  1842,  1844,  1846,
    1848,  1852,  1856,  1860,  1866,  1872,  1877,  1884,  1893,  1902,
    1909,  1918,  1929,  1940,  1942,  1946,  1948,  1950,  1952,  1955,
    1958,  1961,  1962,  1964
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     519,     0,    -1,   231,   510,   539,   315,   313,    -1,    -1,
     134,   514,    -1,   248,   424,    -1,    -1,   134,   514,    -1,
     248,   424,    -1,    94,   320,   197,   221,   212,   321,   197,
      -1,    90,   321,   197,    -1,    91,   321,   197,    -1,   268,
     316,    -1,    93,   321,    -1,    92,   321,    -1,   319,    -1,
     316,   276,   319,    -1,   318,    -1,   286,   318,    -1,   513,
     450,    -1,   513,   290,   513,   450,    -1,   513,   290,   513,
     290,   513,   450,    -1,   513,   290,   244,    -1,   317,   221,
     322,    -1,   317,    -1,   320,   276,   317,    -1,   322,    -1,
     321,   276,   322,    -1,   497,    -1,   233,    -1,   324,    -1,
     139,   510,    -1,   179,   510,    -1,   165,   512,    -1,    80,
     513,    -1,   335,    -1,   326,    -1,   144,   510,   212,   340,
     197,   327,    -1,   130,   510,   212,   340,   197,   336,   327,
     336,    -1,    -1,   328,    -1,   329,    -1,   328,   329,    -1,
     291,   330,    -1,   156,     3,    -1,    87,     3,    -1,   108,
      -1,   109,    -1,     4,    -1,    -1,   332,    -1,   333,    -1,
     332,   333,    -1,   291,   330,    -1,   299,     3,    -1,    63,
      -1,    64,    -1,   510,    -1,   120,   512,   292,   334,   212,
     338,   197,   331,    -1,   119,   512,   292,   334,   212,   338,
     197,   331,    -1,   121,   512,   292,   334,   212,   338,   197,
     331,    -1,   122,   512,   292,   334,   212,   338,   197,   331,
      -1,    95,   523,    -1,    96,   523,    -1,   138,   510,   279,
     510,    -1,    82,   510,   291,     6,    -1,    81,   510,    -1,
      99,   510,    -1,    77,   510,    -1,    78,   513,    -1,    -1,
     162,    -1,    -1,   162,    -1,   339,    -1,   338,   276,   339,
      -1,   513,   273,    -1,   513,   252,    -1,   513,    -1,   341,
      -1,   340,   276,   341,    -1,   404,    -1,   402,    -1,    85,
     513,   343,    -1,    86,   512,   117,    -1,    86,   512,   118,
      -1,   344,    -1,   343,   276,   344,    -1,   345,    -1,   348,
      -1,   351,    -1,   356,    -1,   359,    -1,   355,    -1,   354,
      -1,   269,   346,    -1,   269,   212,   347,   197,    -1,   341,
      -1,   341,   295,   513,    -1,   346,    -1,   347,   276,   346,
      -1,   254,   350,    -1,   254,   212,   349,   197,    -1,   350,
      -1,   349,   276,   350,    -1,   513,    -1,   220,   353,    -1,
     220,   212,   352,   197,    -1,   353,    -1,   352,   276,   353,
      -1,   341,    -1,   108,    -1,   109,    -1,   107,     3,    -1,
      97,   402,   358,    -1,    97,   212,   357,   197,    -1,   402,
     358,    -1,   357,   276,   402,   358,    -1,    -1,   100,   513,
      -1,    98,   360,    -1,    98,   212,   360,   197,    -1,   361,
      -1,   360,   276,   361,    -1,   513,    -1,   151,    -1,    -1,
     158,   364,   510,   367,   365,    -1,    -1,   232,   366,   212,
     370,   197,    -1,   490,    -1,    -1,   212,   368,   197,    -1,
     369,    -1,   368,   276,   369,    -1,   513,    -1,   513,   290,
     513,    -1,   371,    -1,   370,   276,   371,    -1,   497,    -1,
     233,    -1,   155,   539,   510,   314,    -1,   164,    -1,   173,
      -1,    -1,   180,    -1,   377,    -1,    72,   513,    73,     6,
      71,    -1,    72,   513,    73,     6,    -1,    74,    -1,    67,
      -1,    68,    -1,   127,   513,    -1,   143,    -1,   374,    -1,
     373,    -1,   362,    -1,   376,    -1,   410,    -1,   414,    -1,
     460,    -1,   323,    -1,   325,    -1,   342,    -1,   239,   383,
     292,   510,   294,   388,   382,    -1,   226,   383,   292,   510,
     256,   388,    -1,   239,   381,   294,   388,    -1,   226,   381,
     256,   388,    -1,   198,    -1,   192,    -1,   278,    -1,    -1,
     132,    -1,   288,   449,    -1,   137,    -1,   270,    -1,   384,
      -1,   385,    -1,   384,   276,   385,    -1,   228,   386,    -1,
     218,    -1,   213,    -1,   231,   386,    -1,   235,    -1,   240,
      -1,    -1,   212,   387,   197,    -1,   451,    -1,   387,   276,
     451,    -1,   389,    -1,   388,   276,   389,    -1,   224,    -1,
     449,    -1,   154,   510,   391,   288,   481,   393,    -1,    -1,
     212,   392,   197,    -1,   451,    -1,   392,   276,   451,    -1,
      -1,   131,    -1,   236,   212,   480,   197,    -1,   157,   212,
     397,   197,   396,    -1,   170,   398,    -1,   399,    -1,   510,
      -1,   510,   212,   399,   197,    -1,   451,    -1,   399,   276,
     451,    -1,   230,   212,   401,   197,    -1,   185,   212,   401,
     197,    -1,   161,   212,   401,   197,    -1,   451,    -1,   401,
     276,   451,    -1,   400,    -1,   395,    -1,   394,    -1,   201,
     456,    -1,   147,    -1,   146,    -1,   145,    -1,   513,   440,
     405,   406,    -1,    -1,   403,    -1,    -1,   407,    -1,   408,
      -1,   407,   408,    -1,   409,   358,    -1,   191,    -1,   135,
      -1,   230,    -1,   185,    -1,   396,    -1,   236,   212,   480,
     197,    -1,   161,    -1,   125,   411,   413,    -1,   412,    -1,
     449,    -1,   414,    -1,   413,   414,    -1,   390,    -1,   380,
      -1,   217,   424,    -1,   248,   424,    -1,   256,   418,    -1,
     420,    -1,   418,   276,   420,    -1,   418,   276,   246,   420,
      -1,   418,   276,   246,   212,   418,   197,    -1,   418,    49,
     419,   292,   424,    -1,   418,    56,   419,   292,   424,    -1,
     418,    -1,   212,   418,   197,    -1,   510,    -1,   510,   455,
      -1,   510,   288,   455,    -1,    -1,   417,   422,    -1,   423,
      -1,   416,   423,    -1,    -1,   477,    -1,   477,   415,    -1,
     415,    -1,   425,    -1,   424,   293,   425,    -1,   426,    -1,
     425,   271,   426,    -1,   427,    -1,   284,   427,    -1,   437,
      -1,   212,   424,   197,    -1,   215,   491,    -1,   169,   491,
      -1,    -1,   214,   433,    -1,    -1,   214,   433,    -1,    -1,
     214,   433,    -1,   536,    -1,   456,    -1,    -1,   284,    -1,
     497,   434,   194,    -1,   497,   434,   159,    -1,   497,   436,
     497,    -1,   497,   221,   497,    -1,   497,   221,   233,    -1,
     497,   434,   196,   497,   271,   497,    -1,   497,   259,   432,
     431,    -1,   497,   189,   432,   431,    -1,   497,   298,   432,
     430,    -1,   497,   190,   432,   430,    -1,   497,   205,   432,
     429,    -1,   497,   160,   432,   429,    -1,   222,    -1,   241,
      -1,   208,    -1,   297,    -1,   195,    -1,   181,    -1,   435,
      -1,   505,    -1,   428,    -1,   497,    -1,    -1,   270,    -1,
     185,    -1,   230,    -1,    -1,   270,    -1,   185,    -1,   230,
      -1,   441,    -1,   442,    -1,   443,    -1,   445,    -1,   175,
      -1,   175,   212,   446,   197,    -1,   229,    -1,   229,   212,
       3,   197,    -1,   204,    -1,   204,   212,     3,   197,    -1,
     200,    -1,   200,   212,   447,   444,   197,    -1,   242,   212,
     447,   444,   197,    -1,   242,    -1,   251,    -1,   203,    -1,
     193,    -1,   176,    -1,   176,   212,   446,   197,    -1,   177,
      -1,   177,   212,     3,   197,    -1,   177,   212,     3,   276,
       3,   197,    -1,   184,   458,   294,   459,    -1,   184,    -1,
     188,   458,   294,   459,    -1,   482,    -1,   188,    -1,   188,
     458,   212,     3,   197,   294,   459,    -1,   262,    -1,   249,
      -1,   206,    -1,   206,   212,     3,   197,    -1,   206,   212,
       3,   276,     3,   197,    -1,    -1,   276,   448,    -1,   238,
     212,   447,   197,    -1,   260,    -1,   172,    -1,   238,    -1,
     104,    -1,     3,    -1,     3,    -1,     3,    -1,   513,    -1,
       6,    -1,    -1,   223,     3,   207,    -1,   223,     3,   276,
       3,   207,    -1,   454,    -1,   286,   454,    -1,   453,    -1,
     286,   453,    -1,   513,   450,    -1,   508,   290,   513,   450,
      -1,   508,   290,   244,    -1,   302,    -1,   513,   450,    -1,
     508,   290,   513,   450,    -1,   513,   290,   513,   290,   513,
     450,    -1,   508,   290,   244,    -1,   513,    -1,     6,    -1,
     515,    -1,     3,    -1,   471,    -1,    -1,   458,   294,   459,
      -1,   266,    -1,   243,    -1,   277,    -1,   257,    -1,   219,
      -1,   227,    -1,   186,    -1,   266,    -1,   243,    -1,   277,
      -1,   257,    -1,   219,    -1,   227,    -1,   186,    -1,   186,
     212,     3,   197,    -1,   465,    -1,   464,    -1,   461,    -1,
     174,   462,   294,   462,    -1,   171,   508,   290,   463,   294,
     463,    -1,   513,    -1,   513,    -1,   150,   510,    -1,   168,
     510,   466,    -1,   163,    -1,   140,    -1,   468,    -1,   468,
     458,   294,   459,    -1,    75,    -1,   470,    -1,   470,   458,
     212,     3,   197,   294,   459,    -1,   470,   458,   294,   459,
      -1,    76,    -1,   199,   457,    -1,   245,   289,   473,    -1,
     474,    -1,   473,   276,   474,    -1,   475,   476,    -1,     3,
      -1,   452,    -1,    -1,   273,    -1,   252,    -1,   187,   478,
      -1,   479,    -1,   478,   276,   479,    -1,   452,    -1,     3,
      -1,   424,    -1,   490,    -1,   300,    -1,   300,   212,     3,
     197,    -1,   303,    -1,   303,   212,     3,   197,    -1,    -1,
      -1,   228,   492,   493,   484,   494,   485,   517,   421,   487,
     488,    -1,   228,   492,   493,   494,   421,   487,    -1,    -1,
     247,   439,   486,    -1,    -1,   472,    -1,   472,   182,   489,
     337,    -1,   182,   489,   337,    -1,   513,    -1,   228,   492,
     493,   494,   421,    -1,   211,   492,   493,   494,   421,   197,
      -1,    -1,   237,     3,    -1,    -1,   270,    -1,   185,    -1,
     230,    -1,   495,    -1,   496,    -1,   494,   276,   496,    -1,
     497,    -1,   497,   513,    -1,   497,   288,   513,    -1,   536,
      -1,   282,   536,    -1,   287,   536,    -1,   536,   253,   497,
      -1,   536,   504,    -1,   536,   244,   497,    -1,   536,   287,
     497,    -1,   536,   282,   497,    -1,   536,    79,   497,    -1,
     456,    -1,   234,    -1,   209,    -1,   264,    -1,   301,    -1,
     302,    -1,   300,    -1,   244,    -1,   105,    -1,   274,   212,
     438,   497,   197,    -1,   280,   212,   438,   497,   197,    -1,
     281,   212,   438,   497,   197,    -1,   285,   212,   438,   497,
     197,    -1,   305,   212,   438,   497,   197,    -1,     4,   212,
     197,    -1,     4,   212,   501,   197,    -1,   266,   212,   501,
     197,    -1,   243,   212,   501,   197,    -1,   277,   212,   501,
     197,    -1,    69,   212,   501,   197,    -1,    70,   212,   501,
     197,    -1,   267,   212,   501,   197,    -1,   251,   212,   501,
     197,    -1,   212,   497,   197,    -1,   216,   212,   503,   197,
      -1,   467,    -1,   469,    -1,   250,   499,   296,    -1,   250,
     424,   499,   296,    -1,   500,    -1,   499,   500,    -1,   265,
     424,   263,   497,    -1,   255,   497,    -1,   497,    -1,   501,
     276,   497,    -1,    -1,   276,   458,   294,   459,    -1,   458,
     294,   459,    -1,    -1,   529,   502,    -1,   497,   502,    -1,
     111,    -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,
     116,    -1,   497,   291,   212,   506,   197,    -1,   497,   291,
     491,    -1,   497,   210,   212,   506,   197,    -1,   497,   210,
     491,    -1,   507,    -1,   506,   276,   507,    -1,   529,    -1,
     456,    -1,   282,     3,    -1,   282,   515,    -1,   509,    -1,
       6,    -1,     6,   290,   513,    -1,   513,    -1,   513,   275,
     513,    -1,   513,   275,     6,   290,   513,    -1,   513,   286,
     513,    -1,   513,   286,   513,   275,   513,    -1,   513,   286,
     513,   275,     6,   290,   513,    -1,   511,    -1,     6,   290,
     513,    -1,   513,   290,   513,    -1,     6,    -1,   513,    -1,
     513,   275,   513,    -1,   513,   275,     6,   290,   513,    -1,
     513,   286,   513,    -1,   513,   286,   513,   275,   513,    -1,
     513,   286,   513,   275,     6,   290,   513,    -1,     6,   290,
     513,    -1,     6,    -1,   513,    -1,   513,   275,   513,    -1,
     513,   275,     6,   290,   513,    -1,   513,   286,   513,    -1,
     513,   286,   513,   275,   513,    -1,   513,   286,   513,   275,
       6,   290,   513,    -1,     4,    -1,     4,    -1,    15,    -1,
     290,     3,    -1,     4,    -1,     6,    -1,    -1,   513,    -1,
     521,    -1,   519,    16,   521,    -1,   363,    -1,   312,    -1,
     372,    -1,    -1,   530,    -1,   379,    -1,   522,    -1,   528,
      -1,   520,    -1,   378,    -1,     1,    -1,   524,   525,    -1,
     518,    -1,   483,    -1,    -1,   167,    -1,   166,   526,    -1,
     527,    -1,   526,   276,   527,    -1,   513,    -1,   513,   290,
     513,    -1,     6,   290,   513,   290,   513,    -1,   153,    -1,
     152,    -1,   136,   538,    -1,   133,    -1,   129,    -1,   126,
      -1,   124,    -1,   128,    -1,   535,    -1,    17,    -1,   531,
      -1,   183,   516,   375,    -1,    20,     6,    21,    -1,   212,
     532,   197,    -1,   532,   533,   532,    -1,     3,    -1,   534,
       3,    -1,   287,    -1,   282,    -1,   244,    -1,   253,    -1,
     283,    -1,   287,    -1,   282,    -1,   513,    -1,   513,   290,
     244,    -1,   513,   290,   302,    -1,   513,   290,   513,    -1,
     513,   290,   513,   290,   513,    -1,     6,   290,   513,   290,
     513,    -1,   513,   223,   532,   207,    -1,   513,   290,   513,
     223,   532,   207,    -1,   513,   290,   513,   290,   513,   223,
     532,   207,    -1,     6,   290,   513,   290,   513,   223,   532,
     207,    -1,   513,   223,   532,   276,   532,   207,    -1,   513,
     290,   513,   223,   532,   276,   532,   207,    -1,   513,   290,
     513,   290,   513,   223,   532,   276,   532,   207,    -1,     6,
     290,   513,   290,   513,   223,   532,   276,   532,   207,    -1,
     537,    -1,   537,   123,   440,    -1,   498,    -1,   529,    -1,
     491,    -1,   270,   491,    -1,   272,   491,    -1,   261,   491,
      -1,    -1,     3,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   486,   486,   515,   518,   535,   540,   543,   560,   566,
     575,   584,   593,   600,   615,   670,   677,   688,   691,   696,
     703,   720,   737,   758,   767,   770,   778,   781,   789,   790,
     797,   800,   808,   811,   815,   821,   822,   826,   836,   850,
     851,   855,   856,   861,   869,   877,   885,   893,   903,   905,
     905,   908,   909,   913,   920,   927,   934,   943,   947,   954,
     966,   977,   983,   987,   991,   996,  1000,  1003,  1007,  1010,
    1017,  1018,  1028,  1029,  1033,  1034,  1038,  1047,  1056,  1063,
    1066,  1072,  1075,  1086,  1090,  1095,  1102,  1105,  1114,  1117,
    1121,  1125,  1129,  1133,  1137,  1145,  1149,  1157,  1160,  1167,
    1170,  1177,  1180,  1187,  1188,  1193,  1197,  1200,  1206,  1209,
    1215,  1222,  1223,  1227,  1235,  1239,  1246,  1248,  1253,  1254,
    1258,  1260,  1266,  1267,  1270,  1281,  1287,  1287,  1296,  1296,
    1305,  1330,  1333,  1341,  1344,  1351,  1354,  1362,  1363,  1369,
    1370,  1378,  1400,  1404,  1409,  1410,  1420,  1429,  1433,  1437,
    1442,  1446,  1450,  1453,  1460,  1466,  1471,  1479,  1480,  1481,
    1482,  1483,  1484,  1485,  1493,  1494,  1495,  1496,  1501,  1502,
    1503,  1506,  1507,  1508,  1512,  1513,  1514,  1518,  1519,  1523,
    1530,  1531,  1532,  1539,  1540,  1543,  1544,  1549,  1550,  1555,
    1556,  1561,  1562,  1567,  1574,  1575,  1580,  1581,  1585,  1586,
    1593,  1601,  1608,  1615,  1619,  1620,  1625,  1626,  1632,  1636,
    1641,  1648,  1649,  1655,  1658,  1661,  1668,  1669,  1670,  1671,
    1677,  1700,  1701,  1704,  1706,  1713,  1716,  1722,  1730,  1735,
    1741,  1746,  1752,  1755,  1760,  1768,  1777,  1782,  1786,  1787,
    1793,  1796,  1807,  1816,  1823,  1829,  1830,  1833,  1838,  1849,
    1853,  1860,  1861,  1865,  1869,  1873,  1880,  1885,  1893,  1896,
    1902,  1905,  1910,  1915,  1928,  1931,  1937,  1940,  1946,  1949,
    1955,  1958,  1965,  1969,  1980,  1980,  1981,  1981,  1982,  1982,
    1985,  1990,  1995,  1996,  2001,  2010,  2018,  2021,  2024,  2028,
    2035,  2038,  2042,  2045,  2048,  2051,  2057,  2064,  2067,  2070,
    2073,  2074,  2079,  2082,  2085,  2088,  2095,  2096,  2097,  2101,
    2108,  2109,  2110,  2114,  2128,  2135,  2136,  2137,  2141,  2142,
    2147,  2148,  2157,  2159,  2168,  2171,  2179,  2189,  2197,  2199,
    2200,  2201,  2202,  2203,  2204,  2205,  2213,  2214,  2215,  2216,
    2217,  2218,  2219,  2220,  2221,  2222,  2223,  2233,  2234,  2240,
    2242,  2243,  2244,  2245,  2249,  2253,  2257,  2264,  2265,  2270,
    2271,  2275,  2283,  2286,  2293,  2296,  2306,  2309,  2312,  2315,
    2322,  2329,  2337,  2346,  2353,  2357,  2362,  2363,  2364,  2369,
    2370,  2379,  2379,  2379,  2379,  2379,  2379,  2379,  2380,  2380,
    2380,  2380,  2380,  2380,  2380,  2380,  2425,  2426,  2427,  2432,
    2433,  2436,  2437,  2441,  2448,  2459,  2460,  2473,  2474,  2478,
    2482,  2483,  2486,  2492,  2496,  2519,  2529,  2532,  2538,  2547,
    2551,  2558,  2559,  2561,  2566,  2572,  2575,  2581,  2582,  2589,
    2602,  2612,  2619,  2636,  2643,  2668,  2670,  2668,  2692,  2736,
    2737,  2751,  2754,  2761,  2771,  2783,  2789,  2802,  2817,  2819,
    2825,  2826,  2827,  2828,  2838,  2845,  2848,  2854,  2857,  2862,
    2871,  2874,  2878,  2885,  2888,  2891,  2894,  2897,  2900,  2903,
    2904,  2905,  2906,  2907,  2908,  2909,  2910,  2911,  2913,  2917,
    2921,  2925,  2929,  2933,  2937,  2941,  2944,  2947,  2950,  2953,
    2956,  2959,  2962,  2965,  2969,  2973,  2977,  2980,  2989,  2992,
    3001,  3007,  3014,  3017,  3041,  3042,  3043,  3046,  3047,  3050,
    3056,  3057,  3058,  3059,  3060,  3061,  3066,  3070,  3074,  3078,
    3085,  3088,  3093,  3094,  3095,  3097,  3103,  3113,  3117,  3121,
    3125,  3129,  3133,  3137,  3141,  3149,  3159,  3164,  3168,  3172,
    3176,  3180,  3185,  3189,  3193,  3201,  3204,  3209,  3210,  3211,
    3216,  3217,  3218,  3226,  3229,  3234,  3235,  3239,  3240,  3245,
    3270,  3287,  3288,  3292,  3299,  3305,  3315,  3317,  3320,  3321,
    3322,  3323,  3325,  3328,  3332,  3337,  3341,  3347,  3348,  3351,
    3356,  3357,  3360,  3361,  3362,  3372,  3373,  3374,  3375,  3376,
    3377,  3378,  3379,  3383,  3389,  3391,  3410,  3418,  3425,  3426,
    3427,  3428,  3433,  3434,  3435,  3436,  3437,  3442,  3443,  3459,
    3460,  3461,  3462,  3463,  3464,  3465,  3466,  3467,  3468,  3470,
    3471,  3472,  3473,  3478,  3481,  3490,  3491,  3492,  3493,  3494,
    3495,  3499,  3500,  3514
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
  "END_DIALOG", "ACCEPT_DIALOG", "EXIT_DIALOG", "CONTINUE_DIALOG",
  "AFTER_DIALOG", "BEFORE_DIALOG", "COUNT_OB", "SUM_OB", "XMAX_OB",
  "XMIN_OB", "AVG_OB", "PERCENT_OB", "WITH_LISTING_IN", "BACKQUOTE",
  "SET_UNDERLINE_ON", "SET_UNDERLINE_OFF", "SET_POSTGRESQL_SEARCH_PATH",
  "SET_CONSTRAINTS_ALL_DEFERRED", "KW_LIMIT", "DOCUMENT", "ON_EXCEPTION",
  "SET_DEBUG_FILE_TO", "CREATE_DBA_PROCEDURE", "CREATE_FUNCTION",
  "CREATE_DBA_FUNCTION", "USE_SESSION", "KW_RUN_CLIENT", "LEFT_JOIN",
  "IGNORE_ERRORS", "SQLERRMESSAGE", "DISPLAY_NULL_TO", "UNBUFFERED",
  "KW_PICTURE", "ON_CHANGE", "INNER_JOIN", "UI_INTERFACE_DOT_FRONTCALL",
  "UICOMBOBOX", "UIBROWSER", "UIPROGRESS", "UIGANTT", "UIFORM",
  "USING_BTREE", "USING_RTREE", "RESUME_PAGE", "FOR_EVERY_PAGE",
  "SET_BUFFERED_LOG", "SET_LOG", "MDY", "WEEKDAY", "MODE_ANSI",
  "START_DATABASE", "WITH_LOG_IN", "SET_CONSTRAINTS_ALL_IMMEDIATE",
  "DATETIME_VALUE", "INTERVAL_VALUE", "RECOVER_TABLE",
  "ROLLFORWARD_DATABASE", "CONCAT_PIPES", "DROP_TRIGGER", "DROP_AUDIT_FOR",
  "CREATE_AUDIT_FOR", "EXECUTE_PROCEDURE", "CURRENT_FIELD_DISPLAY_EQUAL",
  "ALTER_TABLE", "ALTER_INDEX", "NEXT_SIZE", "KW_WHENEVER_SIGNAL",
  "KW_SIGNAL_TOKEN", "XSET_MULTIPLY_EQUAL_OPEN_BRACKET",
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET",
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL",
  "XSET_OPEN_BRACKET", "CREATE_DATABASE", "DROP_DATABASE",
  "ADD_CONSTRAINT", "DROP_CONSTRAINT", "DROP_SYNONYM", "CONSTRAINT",
  "NOT_FIELD_TOUCHED_CURRENT", "FIELD_TOUCHED_CURRENT", "OBJECT_FUNCTION",
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "KW_ASCII_OPEN_BRACKET",
  "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", "LOCK_MODE_ROW", "TO_UI",
  "UNITS_YEAR", "UNITS_MONTH", "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE",
  "UNITS_SECOND", "TO_CLUSTER", "TO_NOT_CLUSTER", "CREATE_UC_IDX",
  "CREATE_U_IDX", "CREATE_C_IDX", "CREATE_IDX", "DOUBLE_COLON", "SQLSICS",
  "CREATE_SCHEMA", "SQLSIRR", "UPDATESTATS_T", "SQLSICR", "SQLSIDR",
  "CREATE_TEMP_TABLE", "WITH_CHECK_OPTION", "WITH_GRANT_OPTION",
  "SQLSLMNW", "WHERE_CURRENT_OF", "NOT_NULL_UNIQUE", "SQLSLMW",
  "ALL_PRIVILEGES", "CREATE_SYNONYM", "DROP_TABLE", "INEXCLUSIVE",
  "REPORT_TO_FILE", "REPORT_TO_UI", "UPDATESTATS", "CREATE_TABLE",
  "DEFAULT_NULL", "DEFAULT_TODAY", "DEFAULT_USER", "EXIT_TODO",
  "CONTINUE_TODO", "UNLOCK_TABLE", "ROLLBACK_W", "SQLSEON", "SQLSEOFF",
  "CREATE_VIEW", "DELETE_FROM", "EXTENT_SIZE", "FOREIGN_KEY",
  "INSERT_INTO", "IS_NOT_NULL", "NOT_MATCHES", "PRIMARY_KEY",
  "WITH_NO_LOG", "INSHARE", "BEGIN_WORK", "DROP_INDEX", "FOR_UPDATE_OF",
  "FOR_UPDATE", "LOCK_TABLE", "NOT_EXISTS", "REFERENCES", "RENCOL",
  "SMALLFLOAT", "COMMIT_W", "RENTAB", "KW_CHAR", "NCHAR", "NVARCHAR",
  "DELIMITER", "DROP_VIEW", "EXCLUSIVE", "GREATER_THAN_EQ", "INTO_TEMP",
  "DATABASE", "DATETIME", "DISTINCT", "FRACTION", "GROUP_BY", "INTERVAL",
  "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", "RESOURCE", "SMALLINT", "IS_NULL",
  "LESS_THAN_EQ", "BETWEEN", "CLOSE_BRACKET", "CONNECT", "KW_CURRENT",
  "KW_DECIMAL", "KW_DEFAULT", "FGL_SYNCFIELDS", "INTEGER", "SERIAL8",
  "MATCHES", "VARCHAR", "CLOSE_SQUARE", "GREATER_THAN", "KW_FALSE",
  "NOT_IN", "OPEN_BRACKET_SELECT", "OPEN_BRACKET", "KW_DELETE",
  "KW_ESCAPE", "EXISTS", "EXTEND", "HAVING", "KW_INSERT", "MINUTE",
  "MODIFY", "EQUAL", "NOT_EQUAL", "OPEN_SQUARE", "PUBLIC", "KW_RETURN_KEY",
  "REVOKE", "SECOND", "KW_SELECT", "SERIAL", "UNIQUE", "KW_UPDATE",
  "VALUES", "KW_NULL", "KW_TRUE", "ALTER", "CHECK", "KW_FIRST", "KW_FLOAT",
  "GRANT", "INDEX", "LESS_THAN", "MONEY", "MONTH", "KW_MULTIPLY", "ORDER",
  "OUTER", "UNION", "WHERE", "KW_BYTE", "CASE", "KW_DATE", "DESC",
  "KW_DIVIDE", "DROP", "ELSE", "FROM", "HOUR", "INTO", "LIKE", "REAL",
  "SOME", "KW_TEXT", "KW_THEN", "USER", "WHEN", "YEAR", "KW_DOW", "XSET",
  "ADD", "ALL", "KW_AND", "ANY", "ASC", "AVG", "COLON", "KW_COMMA", "DAY",
  "DBA", "KW_FOR", "XMAX", "XMIN", "KW_MINUS", "KW_MOD", "KW_NOT",
  "KW_SUM", "ATSIGN", "KW_PLUS", "KW_AS", "KW_BY", "KW_DOT", "KW_IN",
  "KW_ON", "KW_OR", "KW_TO", "BEFORE", "END", "TILDE", "ILIKE",
  "FILLFACTOR", "TIME", "KW_TODAY", "KW_ROWID", "TIMESTAMP", "KWPIPE",
  "COUNT", "DIALOG", "SUBDIALOG", "PDF_XY", "SET_VALUE", "KW_EMBEDDED",
  "$accept", "update_statement_c", "where_upd_p", "where_del_p",
  "set_clause_list_uc", "upd_columns_uc", "upd_column_name",
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
  "s_curr", "e_curr", "misc_sql", "rename_stmt", "rentabname",
  "rencolname", "unlock_stmt", "lock_stmt", "share_or_exclusive",
  "datetime_value_qualified", "datetime_value", "interval_value_qualified",
  "interval_value", "curr_clause", "order_by_clause_slil",
  "sort_specification_list_slil", "sort_specification_sli",
  "sort_spec_sli", "op_asc_desc", "group_by_clause_slil",
  "gr_column_specification_list_slil", "gr_column_specification_sli",
  "search_condition_sli_as_string", "query_specification_ss_converted",
  "sql_time_dtypes", "select_statement_ss_select", "$@3", "$@4",
  "union_select_statement2_ss", "sel_p2_select", "sel_finish_sf",
  "tmp_tabname", "query_specification_select", "subquery_sli", "op_first",
  "op_ad", "select_list_slil", "unexpanded_select_list_slil",
  "value_expression_pls_sli", "value_expression_sli",
  "value_expression_complex_sli", "sql_case_stmt", "sql_case_stmt_element",
  "value_expr_list_slil", "op_extend_from_to", "extend_qual_sli",
  "units_qual_i", "in_predicate_sli", "in_value_list_slil",
  "in_value_specification_sli", "table_name", "table_name_i",
  "table_name_not_for_column_prefix", "table_name_not_for_column_prefix_i",
  "idx_name", "identifier", "fetch_cursor_name_p", "real_number",
  "var_ident_qchar", "opt_into_sel", "var_ident", "sql_statement",
  "sql_bound_commands", "individual_sql_statement",
  "select_statement_ss_str_cfu", "var_ident_vl",
  "select_statement_ss_str_converted", "curs_forupdate", "cur_update_list",
  "colident", "set_cmd", "var_ident_ibind_sli", "set_database_cmd",
  "replace_with_variable", "arr_expr", "arr_next_math", "arr_int_sign",
  "column_name_x", "value_expression_initial_sli",
  "value_expression_initial_sli_nocast", "op_fgl_expr", "atline", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  2282,  2283,  2284,  2285,  2286,  2287,  2288,  2289,
    2290,  2291,  2292,  2293,  2294,  2295,  2296,  2297,  2298,  2299,
    2300,  2301,  1000,  1001,  1002,  1003,  1004,  1005,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1022,  1023,  1028,  1029,  1030,  1032,  1033,  1035,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1047,  1051,  1052,
    1053,  1054,  1057,  1073,  1074,  1085,  1086,  1095,  1098,  1100,
    1101,  1104,  1105,  1106,  1107,  1120,  1121,  1122,  1123,  1137,
    1139,  1140,  1141,  1145,  1150,  1153,  1154,  1155,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1201,  1202,  1204,  1205,  1206,
    1207,  1210,  1211,  1213,  1219,  1220,  1229,  1241,  1242,  1243,
    1248,  1251,  1252,  1253,  1254,  1255,  1256,  1261,  1262,  1264,
    1265,  1266,  1267,  1277,  1283,  1284,  1285,  1286,  1287,  1298,
    1299,  1307,  1308,  1309,  1315,  1323,  1330,  1332,  1336,  1337,
    1339,  1340,  1341,  1346,  1372,  1373,  1374,  1375,  1382,  1383,
    1390,  1398,  1400,  1401,  1405,  1406,  1413,  1414,  1417,  1419,
    1422,  1428,  1435,  1438,  1444,  1449,  1455,  1456,  1461,  1463,
    1465,  1466,  1468,  1479,  1486,  1489,  1490,  1491,  1493,  1495,
    1498,  1502,  1504,  1528,  1529,  1531,  1538,  1540,  1541,  1543,
    1544,  1545,  1551,  1552,  1558,  1559,  1561,  1564,  1567,  1568,
    1570,  1572,  1580,  1581,  1583,  1586,  1599,  1602,  1603,  1604,
    1605,  1607,  1608,  1616,  1619,  1620,  1621,  1625,  1627,  1631,
    1632,  1634,  1635,  1637,  1641,  1644,  1646,  1650,  1654,  1655,
    1658,  1660,  1661,  1664,  1665,  1667,  1673,  1681,  1682,  1685,
    1688,  1691,  1693,  1694,  1696,  1697,  1698,  1707,  1710,  1717,
    1719,  1721,  1722,  1723,  1726,  1727,  1731,  1737,  1738,  1741,
    1750,  1755,  1759,  1760,  1761,  1763,  1766,  1767,  1769,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1783,
    1788,  1789,  1790,  1791,  1792,  1799,  1802,  1803,  1809,  1811,
    1812,  1815,  1817,  1818,  1819,  1857,  1861,  1868,  1869,  1872,
    1877,  1884,  1885,  2233,  2263,  2276,  2277,  2278,  2279,  2280,
    2281
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   311,   312,   313,   313,   313,   314,   314,   314,   315,
     315,   315,   315,   315,   315,   316,   316,   317,   317,   318,
     318,   318,   318,   319,   320,   320,   321,   321,   322,   322,
     323,   324,   324,   324,   324,   325,   325,   326,   326,   327,
     327,   328,   328,   329,   329,   329,   329,   329,   330,   331,
     331,   332,   332,   333,   333,   333,   333,   334,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     336,   336,   337,   337,   338,   338,   339,   339,   339,   340,
     340,   341,   341,   342,   342,   342,   343,   343,   344,   344,
     344,   344,   344,   344,   344,   345,   345,   346,   346,   347,
     347,   348,   348,   349,   349,   350,   351,   351,   352,   352,
     353,   354,   354,   355,   356,   356,   357,   357,   358,   358,
     359,   359,   360,   360,   361,   362,   364,   363,   366,   365,
     365,   367,   367,   368,   368,   369,   369,   370,   370,   371,
     371,   372,   373,   374,   375,   375,   376,   377,   377,   377,
     377,   377,   377,   377,   378,   378,   378,   379,   379,   379,
     379,   379,   379,   379,   380,   380,   380,   380,   381,   381,
     381,   382,   382,   382,   383,   383,   383,   384,   384,   385,
     385,   385,   385,   385,   385,   386,   386,   387,   387,   388,
     388,   389,   389,   390,   391,   391,   392,   392,   393,   393,
     394,   395,   396,   397,   398,   398,   399,   399,   400,   400,
     400,   401,   401,   402,   402,   402,   403,   403,   403,   403,
     404,   405,   405,   406,   406,   407,   407,   408,   409,   409,
     409,   409,   409,   409,   409,   410,   411,   412,   413,   413,
     414,   414,   415,   416,   417,   418,   418,   418,   418,   418,
     418,   419,   419,   420,   420,   420,   421,   421,   422,   422,
     423,   423,   423,   423,   424,   424,   425,   425,   426,   426,
     427,   427,   428,   428,   429,   429,   430,   430,   431,   431,
     432,   433,   434,   434,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   436,   436,   436,   436,
     436,   436,   437,   437,   437,   437,   438,   438,   438,   438,
     439,   439,   439,   439,   440,   441,   441,   441,   442,   442,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   444,   444,   445,
     445,   445,   445,   445,   446,   447,   448,   449,   449,   450,
     450,   450,   451,   451,   452,   452,   453,   453,   453,   453,
     454,   454,   454,   454,   455,   456,   456,   456,   456,   457,
     457,   458,   458,   458,   458,   458,   458,   458,   459,   459,
     459,   459,   459,   459,   459,   459,   460,   460,   460,   461,
     461,   462,   463,   464,   465,   466,   466,   467,   467,   468,
     469,   469,   469,   470,   471,   472,   473,   473,   474,   475,
     475,   476,   476,   476,   477,   478,   478,   479,   479,   480,
     481,   482,   482,   482,   482,   484,   485,   483,   486,   487,
     487,   488,   488,   488,   488,   489,   490,   491,   492,   492,
     493,   493,   493,   493,   494,   495,   495,   496,   496,   496,
     497,   497,   497,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   499,   499,
     500,   500,   501,   501,   502,   502,   502,   503,   503,   503,
     504,   504,   504,   504,   504,   504,   505,   505,   505,   505,
     506,   506,   507,   507,   507,   507,   508,   509,   509,   509,
     509,   509,   509,   509,   509,   510,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   512,   512,   512,   512,   512,
     512,   512,   512,   513,   514,   515,   515,   516,   516,   517,
     518,   519,   519,   520,   520,   520,   521,   521,   521,   521,
     521,   521,   521,   521,   522,   523,   524,   525,   525,   525,
     526,   526,   527,   527,   527,   528,   528,   528,   528,   528,
     528,   528,   528,   529,   529,   529,   530,   531,   532,   532,
     532,   532,   533,   533,   533,   533,   533,   534,   534,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   536,   536,   537,   537,   537,   537,   537,
     537,   538,   538,   539
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     0,     2,     2,     7,
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
       1,     4,     1,     1,     0,     1,     1,     5,     4,     1,
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
       1,     1,     1,     1,     1,     4,     1,     1,     1,     4,
       6,     1,     1,     2,     3,     1,     1,     1,     4,     1,
       1,     7,     4,     1,     2,     3,     1,     3,     2,     1,
       1,     0,     1,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     4,     1,     4,     0,     0,    10,     6,     0,
       3,     0,     1,     4,     3,     1,     5,     6,     0,     2,
       0,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     2,     3,     2,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     5,     5,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     4,     1,     1,     3,     4,     1,     2,
       4,     2,     1,     3,     0,     4,     3,     0,     2,     2,
       1,     1,     1,     1,     1,     1,     5,     3,     5,     3,
       1,     3,     1,     1,     2,     2,     1,     1,     3,     1,
       3,     5,     3,     5,     7,     1,     3,     3,     1,     1,
       3,     5,     3,     5,     7,     3,     1,     1,     3,     5,
       3,     5,     7,     1,     1,     1,     2,     1,     1,     0,
       1,     1,     3,     1,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     0,     1,     2,
       1,     3,     1,     3,     5,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     5,     5,     4,     6,     8,     8,     6,
       8,    10,    10,     1,     3,     1,     1,     1,     2,     2,
       2,     0,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   573,   150,   151,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     591,     0,   590,     0,   592,   589,     0,   588,   631,     0,
       0,   153,     0,     0,   125,   586,   585,     0,   633,   126,
     142,     0,     0,     0,   143,     0,     0,     0,     0,   448,
       0,     0,   564,   161,    30,   162,    36,    35,   163,   156,
     563,   565,   155,   154,   157,   146,   572,   568,   241,   240,
     158,   159,   160,   398,   397,   396,   576,     0,   571,   561,
     569,   577,   570,   567,   553,     0,   538,    68,   535,   539,
      69,    34,    66,     0,     0,   546,     0,   547,   560,   575,
      62,    63,    67,     0,     0,     0,     0,   358,     0,   236,
     237,   357,   152,     0,   632,   587,     0,    31,     0,   403,
     194,     0,     0,    33,     0,     0,     0,   526,   529,     0,
     401,    32,   557,   558,   144,   174,   169,   168,   181,   180,
     185,   185,   183,   184,   175,   170,     0,     0,   176,   177,
       0,   450,   633,     0,     0,     1,     0,     0,   578,   574,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,    83,    86,    88,    89,    90,    94,
      93,    91,    92,     0,    84,    85,     0,     0,     0,     0,
       0,     0,   235,   238,     0,     0,     0,     0,     0,     6,
     131,   406,   405,   404,     0,     0,     0,     0,     0,   145,
     596,     0,   179,   182,     0,     0,     0,   449,   452,   453,
     451,   435,     0,     0,     0,   562,     0,   582,   579,   580,
     148,   536,     0,   540,   542,   537,    65,     0,     0,     0,
       0,     0,     0,   215,   214,   213,   118,     0,   120,   122,
     124,   113,     0,   110,   106,    82,    81,     0,     0,   101,
     105,     0,    97,    95,     0,   545,     0,   548,   550,     0,
      57,     0,     0,     0,   239,     0,    79,    64,     0,     0,
       0,   196,   362,     0,   359,     0,     0,     0,   141,     0,
       0,   528,     0,   402,     0,   530,   532,   399,     0,   187,
     191,   167,   189,   192,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     3,   166,     0,     0,     0,     0,   147,
       0,     0,     0,     0,     0,     0,   118,     0,     0,     0,
     114,     0,     0,     0,   108,   353,   351,   318,   331,   333,
     337,   340,   330,   324,   329,   322,   344,   320,   352,   327,
     343,   328,   350,   342,   431,   433,   221,   314,   315,   316,
     317,   339,     0,   103,    99,     0,     0,    87,     0,     0,
       0,     0,     0,     0,    70,     0,    39,   363,   195,     0,
       0,     0,     0,   370,   448,   198,   430,   554,     7,   377,
     553,   375,   555,   594,     0,     0,     0,   409,   413,   477,
       0,   379,   471,   448,     0,     0,     0,   470,     0,   476,
       0,     0,     0,   472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   475,   473,   474,
       0,     8,   264,   266,   268,   304,   302,   270,   469,   494,
     407,   495,   410,   378,   627,   305,   625,   303,   609,   376,
     626,   595,   593,   460,   623,     0,   133,   135,   128,   127,
     130,     0,     0,     0,   186,     0,     0,     0,     0,   436,
     454,   455,   457,    29,     0,    26,    28,     0,    14,    13,
       0,    24,    17,     0,   359,    12,     0,    15,     0,     0,
       2,     0,     0,   583,   581,   541,     0,   543,     0,   203,
     206,     0,   211,     0,   115,     0,   116,     0,   429,     0,
     119,   121,   123,   107,     0,     0,     0,     0,   387,   385,
     386,   382,   384,   381,   383,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   218,   217,     0,   222,
     223,   102,     0,    96,     0,    98,   549,     0,   551,     0,
      74,    78,     0,     0,     0,    71,    39,    80,     0,    46,
      47,     0,     0,    37,    40,    41,   197,   373,   359,     0,
       0,   450,   199,   193,     0,     0,     0,     0,     0,   273,
     414,     0,   450,     0,   282,   272,   507,     0,     0,     0,
       0,     0,   498,     0,   630,     0,     0,   628,   629,   306,
       0,   306,   306,   461,   269,   306,   462,   556,   306,     0,
       0,     0,     0,     0,   301,     0,     0,   300,     0,   298,
       0,     0,   296,   297,     0,   283,     0,   299,     0,     0,
       0,     0,     0,     0,   510,   511,   512,   513,   514,   515,
       0,     0,     0,     0,   464,     0,   132,     0,     0,     0,
     400,   531,     0,   533,   188,   190,   165,     0,     0,   559,
       0,   458,    10,     0,    11,    18,     0,     0,     0,    19,
       0,     0,     4,     5,   171,     0,     0,     0,     0,   210,
       0,   209,   118,   208,   200,   109,   354,     0,     0,     0,
       0,     0,     0,   355,   347,     0,     0,     0,     0,   347,
       0,     0,   375,   216,   229,   234,     0,   231,   228,   230,
       0,   232,   220,   224,   225,   118,   104,   100,     0,    49,
       0,    77,    76,    49,    49,    49,    70,    45,    44,    48,
      43,    42,   371,   360,     0,     0,     0,   483,   502,     0,
       0,   597,     0,     0,     0,     0,   271,   492,   504,     0,
     626,     0,   501,     0,     0,   496,   499,     0,     0,     0,
     308,   309,   307,     0,     0,     0,     0,     0,     0,   265,
     267,     0,     0,     0,   274,   280,   278,   276,   274,     0,
     519,   288,   287,   278,     0,   517,   276,   285,   284,     0,
     286,   600,     0,   608,   607,     0,     0,   610,   611,   612,
     468,   465,   463,   467,   466,   624,   134,   136,     0,     0,
     456,   256,   459,    27,     0,    25,    22,   359,    16,    23,
     172,     0,   164,   584,   544,   201,   207,   212,   117,   319,
     332,   334,     0,   394,   392,   393,   389,   391,   388,   390,
     336,     0,   338,     0,     0,   323,   345,     0,   321,   349,
       0,   432,   434,   202,   204,     0,   226,   227,   552,    55,
      56,     0,     0,    59,    50,    51,    75,    58,    60,    61,
      38,     0,   359,   256,   484,     0,     0,   488,   489,   380,
     256,     0,     0,   509,   493,   508,   486,     0,   497,   491,
     485,   490,     0,   487,     0,     0,     0,     0,   408,     0,
     412,     0,   295,     0,   291,     0,   293,   294,     0,   523,
       0,   520,   522,   290,     0,   292,     0,     0,   615,   604,
     605,     0,   603,   606,   602,     0,   601,     0,     0,   140,
       0,   137,   139,   534,     0,   260,   439,     0,     0,    20,
     173,     0,     0,     0,   356,   348,   325,     0,   326,     0,
       0,    53,    54,    52,   361,   372,   446,   503,   614,     0,
       0,     0,   500,   478,   479,   480,   481,   482,     0,   275,
     281,   279,   277,   524,   525,   518,     0,   516,     0,   598,
       0,   599,     0,   613,   129,     0,   244,   245,   253,     0,
       0,     0,   263,   260,   257,   258,   261,   310,   441,     0,
     359,   335,     0,     0,   346,     0,   233,     0,   447,     0,
     506,     0,   521,   289,   619,   616,     0,     0,   138,     0,
       0,     0,     0,   254,   374,   428,     0,   369,   427,   364,
     424,   425,     0,   359,   242,   243,   259,   262,   312,   313,
     311,     0,     0,     0,   442,   437,     9,    21,   395,   341,
     205,     0,   505,   411,     0,     0,     0,   251,     0,     0,
       0,   246,   255,   365,     0,     0,   366,   448,   440,    72,
     445,     0,     0,   618,     0,   620,   617,     0,     0,     0,
       0,     0,   247,   426,   368,   359,   450,    73,   444,   419,
     420,   415,   416,   421,    72,     0,     0,   252,   249,   250,
       0,   367,     0,     0,   423,   422,   418,   443,   622,   621,
     248,   256,   417,   439,   438
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,   490,   288,   313,   485,   486,   482,   487,   483,
     474,   475,    53,    54,    55,    56,   563,   564,   565,   730,
     863,   864,   865,   269,    57,   556,  1088,   549,   550,   275,
     253,    58,   174,   175,   176,   263,   365,   177,   362,   259,
     178,   333,   254,   179,   180,   181,   325,   330,   182,   248,
     249,    59,    60,   122,   459,   649,   290,   455,   456,   930,
     931,    61,    62,    63,   210,    64,    65,    66,    67,    68,
     146,   822,   147,   148,   149,   212,   298,   301,   302,    69,
     198,   280,   573,   243,   244,   711,   498,   853,   499,   245,
     501,   255,   539,   256,   540,   712,   713,   714,   715,    70,
     108,   109,   192,    71,   992,   993,   935,  1057,  1058,   987,
     936,   994,   995,   508,   432,   433,   434,   435,   902,   906,
     904,   774,   969,   629,   436,   630,   437,   763,  1041,   356,
     357,   358,   359,   844,   360,   687,   694,   945,   303,   383,
     502,  1028,  1029,   282,  1023,   438,   580,   882,   840,    72,
      73,   129,   292,    74,    75,   203,   439,   440,   441,   442,
     443,  1044,  1091,  1092,  1093,  1106,   996,  1030,  1031,   509,
     385,   361,    76,   306,   659,  1068,   998,  1045,  1069,   386,
     444,   151,   221,   469,   470,   471,   445,   446,   591,   592,
     739,   883,   749,   644,   447,   910,   911,   283,   127,   988,
      88,    96,   448,   388,   449,   134,   811,    99,    77,    78,
      79,    80,   100,    81,   159,   228,   229,    82,   450,    83,
     451,   795,   925,   796,   452,   453,   454,   115,   121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -887
static const yytype_int16 yypact[] =
{
    1871,  -887,  -887,  -887,   205,  -887,   511,   205,   205,   511,
     511,   205,   526,   205,   205,   511,   526,   526,   526,   526,
    -887,   531,  -887,   205,  -887,  -887,   511,  -887,   292,   511,
     511,  -887,   511,   511,  -887,  -887,  -887,   511,  -887,  -887,
    -887,   526,   511,   633,  -887,   205,   511,   654,   356,   178,
     511,   356,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,   274,  -887,  -887,
    -887,   -15,  -887,  -887,  -887,   257,    31,  -887,  -887,   440,
    -887,  -887,  -887,    42,   345,    83,   164,   132,  -887,  -887,
    -887,  -887,  -887,   127,   142,   154,   174,  -887,    21,  -887,
    -887,  -887,  -887,   212,  -887,  -887,   149,  -887,   260,  -887,
     269,   511,   511,  -887,   137,   209,   214,  -887,   204,   218,
    -887,  -887,  -887,  -887,   328,  -887,  -887,  -887,  -887,  -887,
     306,   306,  -887,  -887,  -887,  -887,   286,   237,   281,  -887,
     558,    -7,  -887,   270,   293,  -887,  1871,   729,  -887,  -887,
     567,   205,   752,   205,   205,   594,   568,    93,   600,  -887,
    -887,   235,    97,   248,   336,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,   205,  -887,  -887,   760,   205,   511,   511,
     511,   511,    21,  -887,   284,   511,   284,    96,   331,   -30,
     415,  -887,  -887,  -887,   205,   205,   765,   205,   205,  -887,
    -887,    96,  -887,  -887,   125,   511,   763,  -887,  -887,  -887,
    -887,  -887,   104,   125,   511,  -887,   314,   340,   378,  -887,
     586,  -887,   380,  -887,   398,  -887,  -887,   473,   501,   505,
     537,   532,   535,  -887,  -887,  -887,   678,   205,   498,  -887,
    -887,  -887,   284,  -887,  -887,  -887,  -887,   503,   205,  -887,
    -887,   284,   486,  -887,   345,  -887,   495,  -887,   516,   585,
    -887,   588,   606,   607,  -887,   -71,  -887,  -887,   -59,   633,
     -25,  -887,  -887,   540,   497,   597,   818,   820,  -887,   205,
     -83,  -887,   554,  -887,   562,  -887,   590,  -887,    18,  -887,
    -887,   587,  -887,  -887,   615,  -887,  1548,  1139,  1139,  1139,
    1139,    66,    66,    -2,   587,   580,   205,   205,   729,  -887,
     205,   827,    96,    96,    96,   118,   678,    96,   820,   205,
    -887,   198,   205,   213,  -887,  -887,  -887,   664,   668,   675,
     462,   462,  -887,   680,  -887,   685,   687,   694,   695,   696,
    -887,  -887,  -887,  -887,   699,   701,   -31,  -887,  -887,  -887,
    -887,  -887,   226,  -887,  -887,   229,   205,  -887,   205,   830,
     205,   205,   205,   205,   726,   284,   141,  -887,  -887,    96,
      80,   888,   205,  -887,   178,   784,  -887,  -887,  -887,  -887,
     704,   604,  -887,  -887,   915,   710,   711,  -887,  -887,  -887,
     717,   462,  -887,   178,   820,   717,   721,  -887,   725,  -887,
     577,   728,   717,  -887,   731,   732,   717,   717,   734,   740,
     742,   748,  1635,   897,   756,  1635,   952,  -887,  -887,  -887,
     758,   681,   700,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
     462,  -887,   462,  -887,  -887,  1029,  -887,  -887,   -34,  -887,
    -887,  -887,  -887,   324,   852,   233,  -887,   689,  -887,  -887,
    -887,   205,   205,   849,  -887,    96,   125,   125,  1548,   706,
    -887,  -887,    23,  -887,   251,  -887,  -887,   252,   707,   707,
     205,  -887,  -887,   258,    70,   712,   759,  -887,   818,   820,
    -887,   125,   702,  -887,  -887,  -887,   714,  -887,   789,   730,
    -887,   267,  -887,   273,  -887,   537,  -887,   319,   681,   793,
    -887,  -887,  -887,  -887,   284,   994,   994,   998,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,   713,  -106,  1002,  1005,  1006,
    1007,  1002,  1002,  1008,  1009,  -887,  -887,  -887,    71,  -887,
     316,  -887,   205,  -887,   284,  -887,  -887,   723,  -887,   322,
    -887,   -46,   334,   339,   344,  -887,   141,  -887,  1011,  -887,
    -887,  1017,  1019,  -887,   141,  -887,  -887,  -887,   798,   -95,
     735,    -7,  -887,  -887,  1226,   205,  1003,  1548,  1548,  -887,
    -887,   733,    -7,   -77,  1095,  -887,  1548,  1548,  1548,   820,
      36,     6,  -887,  1548,  -887,  1548,  1548,  -887,  -887,    14,
    1548,    14,    14,   324,  -887,    14,   324,  -887,    14,   820,
     820,   736,   -73,  1635,  -887,  1635,  1635,  -887,  1635,  -887,
     481,  1326,  -887,  -887,  1635,  -887,   603,  -887,  1635,   581,
    1548,    60,    39,  1548,  -887,  -887,  -887,  -887,  -887,  -887,
    1548,  1548,  1548,  1548,  -887,   503,  -887,   205,   205,   814,
    -887,  -887,   738,  -887,  -887,  -887,   587,   836,  1548,  -887,
     205,  -887,  -887,  1139,  -887,  -887,   813,    66,    95,  -887,
      66,  1139,  -887,   681,   -23,   205,   205,   869,    96,  -887,
      96,  -887,   678,  -887,  -887,  -887,  -887,   843,   844,   347,
     491,  1039,   491,  -887,   767,   848,   353,   850,   851,   767,
     853,   854,  -887,  -887,  -887,  -887,   511,  -887,  -887,  -887,
     834,  -887,  -887,   316,  -887,   678,  -887,  -887,   205,   113,
     205,  -887,  -887,   113,   113,   113,   726,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  1046,   205,  1548,  -887,  -887,   362,
     768,  -887,   365,   366,   491,  1548,  -887,  -887,   374,   856,
     359,   379,  -887,     3,   394,  -887,  -887,   385,   391,   392,
    -887,  -887,  -887,  1548,   393,  1548,  1548,  1548,  1548,   700,
    -887,   491,  1052,   491,   845,   324,   855,   858,   845,   107,
    -887,  -887,  -887,   855,   107,  -887,   858,  -887,  -887,  1548,
    -887,  -887,    60,  -887,  -887,   563,  1054,  -887,  -887,    87,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  1448,   205,
    -887,   806,  -887,  -887,   861,  -887,  -887,   277,  -887,  -887,
    -887,   531,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  1062,   862,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,   878,  -887,  1075,   882,  -887,  -887,  1077,  -887,  -887,
     885,  -887,  -887,  -887,   871,   820,  -887,  -887,  -887,  -887,
    -887,  1019,  1082,  -887,   113,  -887,  -887,  -887,  -887,  -887,
    -887,   881,   798,  -115,  -887,  1548,   205,  -887,  -887,  -887,
    -115,   462,   795,  -887,  -887,  -887,  -887,  1548,  -887,  -887,
    -887,  -887,   894,  -887,   896,   898,   901,   906,  -887,   914,
    -887,    71,  -887,    71,  -887,    71,  -887,  -887,    47,  -887,
     408,  -887,  -887,  -887,   421,  -887,   846,   468,  -887,  -887,
    -887,    60,  -887,  -887,  -887,    60,  -887,    60,   205,  -887,
     424,  -887,  -887,  -887,   511,   305,   867,  1139,   205,  -887,
    -887,   918,  1113,   824,  -887,  -887,  -887,   922,  -887,    96,
     926,  -887,  -887,  -887,  -887,  -887,  -887,  -887,   903,   927,
     833,   491,  -887,  -887,  -887,  -887,  -887,  -887,   835,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,   107,  -887,  1548,  -887,
     326,   682,   622,   905,  -887,  1448,   117,  -887,    67,    84,
     820,   820,  -887,   -37,  -887,  -887,   913,    57,   -74,   425,
     798,  -887,   935,   491,  -887,   435,  -887,    60,  -887,   491,
    -887,   491,  -887,  -887,  -887,  -887,    60,    60,  -887,   119,
     119,    92,   205,  -887,  -887,  -887,    55,  -887,  -887,  -887,
     857,  -887,   847,   504,   681,   681,  -887,  -887,  -887,  -887,
    -887,   907,   205,   860,   954,  -887,  -887,  -887,  -887,  -887,
    -887,   666,  -887,  -887,   455,   674,   511,   117,   842,   859,
     136,  -887,  -887,  -887,    84,    99,  -887,   178,  -887,   976,
    -887,    88,   205,  -887,    60,  -887,  -887,    60,   220,   820,
     820,   511,  -887,  -887,  -887,   798,    -7,  -887,  -887,  -887,
    -887,   863,  -887,    26,   976,   649,   676,  -887,   681,   681,
     230,  -887,  1548,    88,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -115,  -887,   867,  -887
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -887,  -887,  -887,  -887,  -887,  -887,  -280,   670,   474,  -887,
    -254,  -517,  -887,  -887,  -887,  -887,   596,  -887,   582,   294,
      85,  -887,   289,   679,  -887,   431,    68,   513,   445,   964,
    -113,  -887,  -887,   902,  -887,  -210,  -887,  -887,  -887,  -179,
    -887,  -887,  -174,  -887,  -887,  -887,  -887,  -302,  -887,   921,
     838,  -887,  -887,  -887,  -887,  -887,  -887,  -887,   525,  -887,
     188,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    1124,  -887,  1125,  -887,   965,  1042,  -887,  -141,   719,  -887,
    -887,  -887,  -887,  -887,  -887,   509,  -887,  -887,   231,  -887,
    -180,  -121,  -887,  -887,  -887,  -887,  -887,   477,  -887,  -887,
    -887,  -887,  -887,    22,   195,  -887,  -887,  -801,   172,  -886,
    -752,  -887,   200,  -267,   591,   584,   772,  -887,   418,   417,
     422,   323,  -217,  -887,  -887,  -887,  -887,   194,  -887,   556,
    -887,  -887,  -887,   507,  -887,   688,  -228,  -887,   -20,  -461,
    -167,  -858,   181,   932,   190,  -520,  -887,  -306,  -536,  -887,
    -887,  1012,   755,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,   110,  -887,  -887,  -887,  -887,   153,   367,
    -887,  -887,  -887,  -887,  -887,  -887,   108,  -887,   155,   936,
    -176,  -363,  -535,  -688,  -887,   570,  -242,  -887,   641,  -486,
     400,   483,  -887,  -887,  -887,   451,   262,   -27,  -887,    43,
    -887,   743,    -4,   754,   332,  -887,  -887,  -887,  -887,  -887,
    1080,  -887,  1231,  -887,  -887,  -887,   929,  -887,  -554,  -887,
    -887,  -519,  -887,  -887,  -887,  -133,  -887,  -887,  1096
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -567
static const yytype_int16 yytable[] =
{
      85,   110,    89,    90,    91,    89,    89,    94,    97,    98,
      98,    89,    97,    97,    97,    97,   126,   111,   703,   112,
     431,   571,    89,   669,   506,    89,    89,    84,    89,    89,
     281,   481,   750,    89,   525,   526,   736,    97,    89,   128,
     582,   130,    89,    84,   299,   246,    89,   745,   873,    87,
     973,   364,    92,    93,   477,   478,   479,   880,   102,    84,
     262,   125,   392,   791,   472,   476,   476,   476,   476,   113,
      84,    84,   116,   117,   389,   118,   119,   702,   334,   363,
     120,   276,   314,   276,    84,   124,   392,  1025,    84,   131,
     125,  1089,    84,   152,   125,   581,    84,    84,    86,    84,
      84,    84,   125,    84,   286,   756,   691,   732,  1042,   820,
     389,    84,   733,   391,   535,   536,   537,    89,    89,   326,
     746,   956,   392,    84,   393,    86,   374,   394,   959,    84,
     193,   107,   488,   986,   611,  1061,   612,   583,   376,   772,
      84,   934,    86,   590,   503,   384,   813,   507,   262,   458,
     989,   157,   158,   227,   819,   500,   842,   231,   233,   234,
     235,   658,   584,   250,   199,   200,  1019,   257,   260,   257,
     538,  1043,   378,  1020,  1082,    37,   859,   860,   218,   265,
     990,   734,   267,   268,    89,    89,    89,    89,   692,   631,
     257,    89,   257,   284,   307,   308,   309,   310,   311,   760,
     291,   293,   295,   296,   130,   375,   721,   284,   879,    84,
     111,    89,   566,  1090,   274,   464,   609,   375,   287,   111,
      89,   773,   673,   219,   579,   912,   657,   722,   558,   585,
     912,   270,   270,   270,   270,   898,   594,   900,   277,    84,
     597,   598,  1038,   250,   761,  1090,   489,    48,   257,   559,
     560,   379,    84,   466,   260,  1078,   632,   257,   304,   909,
      51,   588,   557,   220,   909,   821,   887,   315,   756,  1019,
     401,   589,   792,   917,   155,   284,  1020,   201,  1104,  1019,
    1100,   184,   185,   797,   762,   457,  1020,  1039,    84,   603,
     156,   588,   606,   381,   465,   114,   609,   561,   654,  1105,
     202,   589,   755,   698,   699,   247,   401,   484,   484,   258,
     927,   660,   492,   493,   227,   504,   495,   497,   284,   284,
     284,   161,   753,   284,   567,   510,   656,  1040,   250,   609,
     160,  1056,   738,   165,   717,   738,   738,   426,  1060,   816,
     685,   798,   793,  1084,   748,   738,   752,   794,  1081,   300,
     674,   738,   480,   738,   738,  1022,   939,  1027,   738,  1113,
     668,   426,   545,   716,   546,   548,   551,   551,   551,   551,
    1026,   257,   312,   183,  1026,   284,   568,   928,   570,   782,
     828,   970,   279,   970,   682,   970,  1027,   815,   790,   908,
    1027,   800,   237,  1021,   505,   511,   238,   426,   801,   802,
     803,   804,   980,   633,   861,   237,   981,   186,   982,   238,
     513,   955,   862,   857,  1111,   150,   472,  1097,   187,   188,
     239,   476,   912,   541,   194,  1010,   543,  1110,   195,   476,
     646,   262,   562,   239,   189,   634,   635,   636,   637,   638,
     639,   237,   166,   167,   780,   238,   190,   252,   662,   664,
     785,   704,   168,   169,   170,   666,   909,   293,   651,   653,
     261,   284,   111,   111,   679,   241,   191,  1049,   661,   239,
     681,   242,   196,  1052,   332,  1053,   484,   705,   241,   206,
     775,   197,   775,   775,   242,   775,   706,   111,  1051,   514,
     207,   775,   989,   135,   472,   775,  1021,  1054,  1055,   204,
     381,   707,   542,   472,   205,   544,  1021,   708,   209,   647,
     257,   826,   208,   827,   241,    84,   683,    86,   211,   719,
     242,   892,   990,   894,   895,   896,   897,   663,   663,   215,
      84,   723,    95,  1014,   667,    84,   724,   107,   260,  1047,
     257,   725,   214,   680,   831,   518,   709,   916,   136,   680,
     846,  1102,   710,   991,   137,  1095,  -504,   216,  1096,   874,
     518,   217,   877,   878,   223,   171,   932,   938,   640,   138,
     919,   740,  1066,   230,   139,   960,   886,   641,   519,   920,
     389,   390,   889,   391,   140,   224,   520,   141,   890,   891,
     893,   142,   392,   519,   393,   680,   143,   394,   720,   172,
     236,   520,   521,   251,   316,   975,   642,   335,   922,   923,
     720,   643,   264,   924,   173,   720,   522,   521,   977,   285,
     720,   984,  1046,   832,  1101,   523,   144,   289,   799,   847,
     317,   522,  1050,   957,   145,   881,   524,    84,   875,   125,
     523,   875,   875,   457,   807,   962,   395,   396,   518,   588,
     881,   524,   397,   398,   318,   875,   812,   319,   132,   589,
     133,   875,  1075,   484,   817,   979,   484,   875,   875,   875,
     320,   823,   824,   321,   284,   336,   284,   833,   337,   338,
     339,   519,   399,   999,   976,   322,   971,   340,   972,   520,
     888,   341,   403,   779,   237,   476,   342,   976,   238,   919,
     985,   663,    89,   343,  1086,   521,   344,   345,   920,   346,
     834,   678,   919,   323,   858,   162,   551,   324,   835,   522,
     381,   920,   239,  1034,  1035,   237,   163,   381,   523,   238,
     164,   872,   347,    84,   836,   226,  1013,   922,   923,   524,
     787,   348,   924,   932,   327,   349,   400,   328,   837,   854,
     922,   923,   350,   239,   351,   924,    84,   838,   232,   103,
     104,   105,   106,   352,    84,   353,   266,   241,   839,    84,
     918,   294,   206,   242,   332,   788,   401,   789,   329,   206,
     240,   366,   500,   207,   123,   368,   402,   382,   403,   404,
     207,   369,   405,   406,  -529,   765,   766,   370,   241,   767,
     371,   940,   768,   354,   242,   933,   355,   919,   867,   868,
     869,   407,  1098,  1099,   403,   784,   920,   111,   372,   373,
     408,   409,   387,   389,   390,   384,   391,   410,   411,  1015,
     380,    84,   588,   496,    84,   392,   547,   393,   412,   921,
     394,   413,   589,   414,   415,   922,   923,   416,   461,   417,
     924,   418,   462,    84,   419,   652,  1108,   420,   421,   422,
     472,   423,   424,   466,   425,   463,   919,   426,   271,   272,
     273,   467,   958,  1073,   491,   920,   515,   427,   428,   429,
     516,  1076,   430,  1109,   552,   553,   554,   517,   555,   395,
     396,   569,   527,   919,   575,   397,   398,   528,  1016,   529,
     389,   390,   920,   391,   922,   923,   530,   531,   532,   924,
     919,   533,   392,   534,   393,   572,   574,   394,   919,   920,
     919,   576,   577,   578,   983,   399,   919,   920,   403,   920,
      89,   922,   923,   586,  1000,   920,   924,   587,   776,   777,
     593,   778,  1074,   595,   596,   284,   599,   783,   922,   923,
    1077,   786,   600,   924,   601,   607,   922,   923,   922,   923,
     602,   924,  1032,   924,   922,   923,   395,   396,   605,   924,
     608,   610,   397,   398,   609,   645,   138,   742,   743,   648,
     671,   139,   658,   663,  1024,  1033,   677,   751,   670,   400,
     684,   140,   675,   757,   141,   758,   759,   686,   142,  1032,
     764,   689,   399,   143,   676,   693,   678,   690,   695,   696,
     697,   700,   701,   718,   727,    89,    89,    89,  1024,   401,
     728,   381,  1033,   729,   741,   735,   808,   744,   809,   402,
     771,   403,   404,   747,   814,   405,   406,  1032,  1070,   706,
     829,   830,   841,   843,  1032,   845,   855,   848,   849,   871,
     851,   852,    89,   884,   407,   899,    89,   926,   876,   901,
    1033,  1085,   934,   408,   409,   941,   400,  1033,  1070,   903,
     410,   411,   905,   937,   942,   943,  1032,    89,   944,   946,
     947,   412,   948,   949,   413,   952,   414,   415,   954,   961,
     416,   963,   417,   964,   418,   965,   401,   419,   966,  1033,
     420,   421,   422,   967,   423,   424,   402,   425,   403,   404,
     426,   968,   405,   406,   997,  1001,  1002,   978,  1003,  1004,
     427,   428,   429,  1006,  1008,   430,  1007,  1009,  1017,  1011,
     990,   407,  1048,  1064,  1079,  1067,  1072,  1065,  1087,  1103,
     408,   409,   389,   390,   818,   391,   731,   410,   411,  1071,
     665,  1080,   726,   953,   392,   951,   393,   870,   412,   394,
     278,   413,  1107,   414,   415,   866,   367,   416,   331,   417,
     512,   418,   806,  1018,   419,   153,   154,   420,   421,   422,
    1005,   305,   424,   213,   425,   655,   825,   426,  -282,   613,
     856,  1037,  1059,  1036,   770,   604,   907,   427,   428,   429,
     769,   805,   430,   915,   688,   913,   850,  1063,   395,   396,
     614,   377,  1062,  1112,   397,   398,   650,  1083,   615,   616,
     297,  1114,   950,  -282,   617,  -282,   460,  1094,   810,   389,
     390,   754,   391,   885,   618,   914,   225,   619,  1012,   620,
     974,   392,   672,   393,   399,   101,   394,   494,   222,     0,
     621,   622,     0,     0,     0,   613,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     623,     0,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,   615,   616,     0,     0,   624,     0,
     617,     0,   747,     0,     0,   395,   396,     0,     0,     0,
     618,   397,   398,   619,     0,   620,     0,     0,     0,     0,
       0,     0,     0,   625,     0,     0,   621,   622,     0,     0,
     626,     0,     0,     0,     0,     0,   627,   628,     0,   389,
     390,   399,   391,     0,     0,     0,   623,     0,   401,     0,
       0,   392,     0,   393,     0,     0,   394,     0,   402,     0,
     403,   468,     0,     0,   624,   406,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -305,     0,     0,     0,
       0,     0,   473,   407,     0,     0,     0,     0,     0,   625,
       0,     0,   408,   409,     0,     0,   626,     0,  -305,   410,
     411,     0,   627,   628,     0,   395,   396,     0,     0,     0,
     412,   397,   398,   413,     0,   414,   415,     0,     0,   416,
       0,   417,     0,   418,     0,     0,   419,     0,     0,   420,
     421,   422,     0,   737,   424,   401,   425,     0,     0,   426,
       0,   399,     0,     0,     0,   402,     0,   403,   468,   427,
     428,   429,   406,     0,   430,     0,     0,     0,     0,     0,
       0,   389,   390,     0,   391,     0,     0,     0,     0,     0,
     407,     0,     0,   392,     0,   393,     0,     0,   394,   408,
     409,     0,     0,     0,     0,     0,   410,   411,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   412,     0,     0,
     413,     0,   414,   415,     0,     0,   416,     0,   417,     0,
     418,     0,     0,   419,     0,     0,   420,   421,   422,     0,
       0,   424,     0,   425,     0,     0,   426,   395,   396,     0,
       0,     0,     0,   397,   398,   401,   427,   428,   429,     0,
       0,   430,     0,     0,     0,   402,     0,   403,   468,     0,
       0,     0,   406,     0,     0,     0,     0,     0,     0,     0,
       0,   389,   390,   399,   391,     0,     0,     0,     0,   781,
     407,     0,     0,   392,     0,   393,     0,     0,   394,   408,
     409,     0,     0,     0,     0,     0,   410,   411,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   412,     0,     0,
     413,     0,   414,   415,     0,     0,   416,     0,   417,     0,
     418,     0,     0,   419,     0,     0,   420,   421,   422,     0,
       0,   424,     0,   425,     0,     0,   426,   395,   396,     0,
       0,     0,     0,   397,   398,     0,   427,   428,   429,     0,
       0,   430,     0,     0,     0,     0,     0,     0,   389,   390,
       0,   391,     0,     0,     0,     0,     0,   401,     0,     0,
     392,     0,   393,   399,     0,   394,     0,   402,     0,   403,
     468,     0,     0,     0,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   929,   407,     0,     0,     0,     0,     0,     0,     0,
       0,   408,   409,     0,     0,     0,     0,     0,   410,   411,
       0,     0,     0,     0,   395,   396,     0,     0,     0,   412,
     397,   398,   413,     0,   414,   415,     0,     0,   416,     0,
     417,     0,   418,     0,     0,   419,     0,     0,   420,   421,
     422,     0,     0,   424,     0,   425,     0,     0,   426,     0,
     399,     0,     0,     0,     0,     0,     0,   401,   427,   428,
     429,     0,     0,   430,     0,     0,     0,   402,     0,   403,
     468,     0,     0,     0,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   407,     0,     0,     0,     0,     0,     0,     0,
       0,   408,   409,     0,     0,     0,     0,     0,   410,   411,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   412,
       0,     0,   413,     0,   414,   415,     0,     0,   416,     0,
     417,     0,   418,     0,     0,   419,     0,     0,   420,   421,
     422,     0,     0,   424,   401,   425,     0,     0,   426,     0,
       0,     0,     0,     0,   402,     0,   403,   468,   427,   428,
     429,   406,     0,   430,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   407,
       0,  -566,     1,     0,     0,     0,     0,     0,   408,   409,
       0,     0,     0,     0,     0,   410,   411,  -566,     0,     0,
       0,     0,     0,     0,     0,     0,   412,     0,     0,   413,
       0,   414,   415,     0,     0,   416,     0,   417,     0,   418,
       0,     0,   419,     0,     0,   420,   421,     0,     0,     0,
     424,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   427,   428,   429,     2,     3,
     430,     0,     0,     4,     0,     5,     0,     0,     6,     7,
       0,     8,     9,    10,     0,     0,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,    28,     0,    29,
      30,     0,     0,     0,    31,    32,     0,     0,     0,     0,
       0,    33,    34,    35,    36,    37,    38,     0,     0,    39,
       0,     0,     0,     0,     0,    40,    41,     0,     0,    42,
       0,     0,    43,     0,    44,    45,     0,     0,     0,     0,
      46,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,    49,
       0,     0,    50,     0,     0,     0,     0,     0,     0,     0,
      51
};

static const yytype_int16 yycheck[] =
{
       4,    21,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    43,    21,   538,    23,
     287,   384,    26,   484,   326,    29,    30,     4,    32,    33,
     197,   311,   586,    37,   340,   341,   571,    41,    42,    43,
     403,    45,    46,     4,   211,   166,    50,   582,   736,     6,
       3,   261,     9,    10,   308,   309,   310,   745,    15,     4,
     173,     6,    15,     3,   306,   307,   308,   309,   310,    26,
       4,     4,    29,    30,     3,    32,    33,     6,   252,   258,
      37,   194,   223,   196,     4,    42,    15,     3,     4,    46,
       6,     3,     4,    50,     6,   401,     4,     4,     6,     4,
       4,     4,     6,     4,   134,   591,   212,   568,   182,   132,
       3,     4,   207,     6,   145,   146,   147,   121,   122,   240,
     197,   873,    15,     4,    17,     6,   197,    20,   880,     4,
     108,     6,   134,   934,   440,  1021,   442,   404,   197,   212,
       4,   256,     6,   410,   324,   228,   663,   327,   261,   232,
     187,   166,   167,   157,   671,   322,   692,   161,   162,   163,
     164,   276,   404,   167,   121,   122,    49,   171,   172,   173,
     201,   245,   197,    56,  1060,   154,    63,    64,   185,   183,
     217,   276,   186,   187,   188,   189,   190,   191,   294,   223,
     194,   195,   196,   197,    90,    91,    92,    93,    94,   185,
     204,   205,   206,   207,   208,   276,   252,   211,   744,     4,
     214,   215,   379,  1071,   192,   197,   293,   276,   248,   223,
     224,   294,   489,   230,   400,   779,   468,   273,    87,   405,
     784,   188,   189,   190,   191,   771,   412,   773,   195,     4,
     416,   417,   185,   247,   230,  1103,   248,   226,   252,   108,
     109,   276,     4,   276,   258,  1056,   290,   261,   215,   779,
     239,   255,   375,   270,   784,   288,   263,   224,   754,    49,
     199,   265,   212,   792,     0,   279,    56,   140,   252,    49,
    1081,   117,   118,   244,   270,   289,    56,   230,     4,   422,
      16,   255,   425,   223,   276,     3,   293,   156,   465,   273,
     163,   265,   296,   531,   532,   212,   199,   311,   312,   212,
     223,   288,   316,   317,   318,   197,   320,   321,   322,   323,
     324,   290,   589,   327,   244,   329,   467,   270,   332,   293,
      73,   212,   574,   291,   544,   577,   578,   290,   246,   244,
     514,   302,   282,   244,   586,   587,   588,   287,   212,   224,
     491,   593,   286,   595,   596,   288,   817,   302,   600,  1111,
     290,   290,   366,   542,   368,   369,   370,   371,   372,   373,
     286,   375,   268,   290,   286,   379,   380,   290,   382,   621,
     682,   901,   286,   903,   505,   905,   302,   667,   630,   282,
     302,   633,   157,   276,   276,   197,   161,   290,   640,   641,
     642,   643,   921,    79,   291,   157,   925,   275,   927,   161,
     197,   872,   299,   715,  1102,   237,   658,   197,   286,   292,
     185,   663,   976,   197,   212,   961,   197,   197,   279,   671,
     197,   544,   291,   185,   292,   111,   112,   113,   114,   115,
     116,   157,    97,    98,   620,   161,   292,   212,   197,   197,
     626,   135,   107,   108,   109,   197,   976,   461,   462,   463,
     212,   465,   466,   467,   197,   230,   292,  1003,   472,   185,
     197,   236,   212,  1009,   276,  1011,   480,   161,   230,   275,
     613,   212,   615,   616,   236,   618,   170,   491,  1007,   276,
     286,   624,   187,   137,   736,   628,   276,  1016,  1017,   290,
     223,   185,   276,   745,   290,   276,   276,   191,   180,   276,
     514,   678,   294,   680,   230,     4,   197,     6,   212,   197,
     236,   763,   217,   765,   766,   767,   768,   276,   276,   292,
       4,   197,     6,   207,   276,     4,   197,     6,   542,  1000,
     544,   197,   256,   276,   197,   186,   230,   789,   192,   276,
     197,  1086,   236,   248,   198,  1074,   197,   276,  1077,   197,
     186,     3,   197,   197,   294,   220,   808,   290,   244,   213,
     244,   575,  1033,     6,   218,   881,   197,   253,   219,   253,
       3,     4,   197,     6,   228,   292,   227,   231,   197,   197,
     197,   235,    15,   219,    17,   276,   240,    20,   276,   254,
       6,   227,   243,     3,   290,   197,   282,   104,   282,   283,
     276,   287,   276,   287,   269,   276,   257,   243,   197,   288,
     276,   197,   197,   276,  1085,   266,   270,   212,   632,   276,
     290,   257,   197,   875,   278,   276,   277,     4,   276,     6,
     266,   276,   276,   647,   648,   887,    69,    70,   186,   255,
     276,   277,    75,    76,   276,   276,   660,    71,     4,   265,
       6,   276,   207,   667,   668,   197,   670,   276,   276,   276,
     290,   675,   676,   275,   678,   172,   680,   186,   175,   176,
     177,   219,   105,   937,   276,   212,   903,   184,   905,   227,
     296,   188,   211,   212,   157,   937,   193,   276,   161,   244,
     276,   276,   706,   200,  1067,   243,   203,   204,   253,   206,
     219,   276,   244,   212,   718,   275,   720,   212,   227,   257,
     223,   253,   185,   990,   991,   157,   286,   223,   266,   161,
     290,   735,   229,     4,   243,     6,   978,   282,   283,   277,
     159,   238,   287,   985,   212,   242,   169,   212,   257,   706,
     282,   283,   249,   185,   251,   287,     4,   266,     6,    16,
      17,    18,    19,   260,     4,   262,     6,   230,   277,     4,
     207,     6,   275,   236,   276,   194,   199,   196,   100,   275,
     212,   295,   949,   286,    41,   290,   209,   290,   211,   212,
     286,   275,   215,   216,   290,   601,   602,   212,   230,   605,
     212,   821,   608,   300,   236,   809,   303,   244,   723,   724,
     725,   234,  1079,  1080,   211,   212,   253,   821,   212,   212,
     243,   244,     4,     3,     4,   228,     6,   250,   251,   207,
     290,     4,   255,     6,     4,    15,     6,    17,   261,   276,
      20,   264,   265,   266,   267,   282,   283,   270,   294,   272,
     287,   274,   290,     4,   277,     6,   207,   280,   281,   282,
    1102,   284,   285,   276,   287,   275,   244,   290,   189,   190,
     191,   256,   876,   207,   294,   253,   212,   300,   301,   302,
     212,   207,   305,   207,   371,   372,   373,   212,   162,    69,
      70,     3,   212,   244,   290,    75,    76,   212,   276,   212,
       3,     4,   253,     6,   282,   283,   212,   212,   212,   287,
     244,   212,    15,   212,    17,   131,   212,    20,   244,   253,
     244,     6,   212,   212,   928,   105,   244,   253,   211,   253,
     934,   282,   283,   212,   938,   253,   287,   212,   615,   616,
     212,   618,   276,   212,   212,   949,   212,   624,   282,   283,
     276,   628,   212,   287,   212,     3,   282,   283,   282,   283,
     212,   287,   989,   287,   282,   283,    69,    70,   212,   287,
     212,   271,    75,    76,   293,   123,   213,   577,   578,   290,
     221,   218,   276,   276,   988,   989,   197,   587,   276,   169,
     197,   228,   290,   593,   231,   595,   596,     3,   235,  1026,
     600,     3,   105,   240,   290,     3,   276,   294,     3,     3,
       3,     3,     3,   290,     3,  1019,  1020,  1021,  1022,   199,
       3,   223,  1026,     4,    21,   290,   212,   294,   290,   209,
     294,   211,   212,   197,   221,   215,   216,  1064,  1042,   170,
     197,   197,     3,   276,  1071,   197,   212,   197,   197,     3,
     197,   197,  1056,   197,   234,     3,  1060,     3,   290,   214,
    1064,  1065,   256,   243,   244,     3,   169,  1071,  1072,   214,
     250,   251,   214,   212,   212,   197,  1103,  1081,     3,   197,
       3,   261,   197,   212,   264,     3,   266,   267,   207,   294,
     270,   197,   272,   197,   274,   197,   199,   277,   197,  1103,
     280,   281,   282,   197,   284,   285,   209,   287,   211,   212,
     290,   197,   215,   216,   247,   197,     3,   271,   294,   197,
     300,   301,   302,   197,   197,   305,   223,   294,   223,   294,
     217,   234,   197,   276,   292,   228,   182,   290,   162,   276,
     243,   244,     3,     4,   670,     6,   564,   250,   251,   289,
     480,   292,   556,   864,    15,   861,    17,   726,   261,    20,
     196,   264,  1094,   266,   267,   720,   264,   270,   247,   272,
     332,   274,   647,   985,   277,    51,    51,   280,   281,   282,
     949,   216,   285,   141,   287,   466,   677,   290,   159,   160,
     713,   996,  1020,   993,   610,   423,   778,   300,   301,   302,
     609,   645,   305,   786,   516,   783,   699,  1026,    69,    70,
     181,   279,  1022,  1103,    75,    76,   461,  1064,   189,   190,
     208,  1113,   855,   194,   195,   196,   290,  1072,   658,     3,
       4,   590,     6,   750,   205,   784,   156,   208,   976,   210,
     908,    15,   488,    17,   105,    14,    20,   318,   152,    -1,
     221,   222,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,    -1,    -1,   259,    -1,
     195,    -1,   197,    -1,    -1,    69,    70,    -1,    -1,    -1,
     205,    75,    76,   208,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   284,    -1,    -1,   221,   222,    -1,    -1,
     291,    -1,    -1,    -1,    -1,    -1,   297,   298,    -1,     3,
       4,   105,     6,    -1,    -1,    -1,   241,    -1,   199,    -1,
      -1,    15,    -1,    17,    -1,    -1,    20,    -1,   209,    -1,
     211,   212,    -1,    -1,   259,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,
      -1,    -1,   233,   234,    -1,    -1,    -1,    -1,    -1,   284,
      -1,    -1,   243,   244,    -1,    -1,   291,    -1,   293,   250,
     251,    -1,   297,   298,    -1,    69,    70,    -1,    -1,    -1,
     261,    75,    76,   264,    -1,   266,   267,    -1,    -1,   270,
      -1,   272,    -1,   274,    -1,    -1,   277,    -1,    -1,   280,
     281,   282,    -1,   197,   285,   199,   287,    -1,    -1,   290,
      -1,   105,    -1,    -1,    -1,   209,    -1,   211,   212,   300,
     301,   302,   216,    -1,   305,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    15,    -1,    17,    -1,    -1,    20,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
     264,    -1,   266,   267,    -1,    -1,   270,    -1,   272,    -1,
     274,    -1,    -1,   277,    -1,    -1,   280,   281,   282,    -1,
      -1,   285,    -1,   287,    -1,    -1,   290,    69,    70,    -1,
      -1,    -1,    -1,    75,    76,   199,   300,   301,   302,    -1,
      -1,   305,    -1,    -1,    -1,   209,    -1,   211,   212,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,   105,     6,    -1,    -1,    -1,    -1,   233,
     234,    -1,    -1,    15,    -1,    17,    -1,    -1,    20,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
     264,    -1,   266,   267,    -1,    -1,   270,    -1,   272,    -1,
     274,    -1,    -1,   277,    -1,    -1,   280,   281,   282,    -1,
      -1,   285,    -1,   287,    -1,    -1,   290,    69,    70,    -1,
      -1,    -1,    -1,    75,    76,    -1,   300,   301,   302,    -1,
      -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      15,    -1,    17,   105,    -1,    20,    -1,   209,    -1,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,   261,
      75,    76,   264,    -1,   266,   267,    -1,    -1,   270,    -1,
     272,    -1,   274,    -1,    -1,   277,    -1,    -1,   280,   281,
     282,    -1,    -1,   285,    -1,   287,    -1,    -1,   290,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   199,   300,   301,
     302,    -1,    -1,   305,    -1,    -1,    -1,   209,    -1,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,   264,    -1,   266,   267,    -1,    -1,   270,    -1,
     272,    -1,   274,    -1,    -1,   277,    -1,    -1,   280,   281,
     282,    -1,    -1,   285,   199,   287,    -1,    -1,   290,    -1,
      -1,    -1,    -1,    -1,   209,    -1,   211,   212,   300,   301,
     302,   216,    -1,   305,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,
      -1,     0,     1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,   251,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,   264,
      -1,   266,   267,    -1,    -1,   270,    -1,   272,    -1,   274,
      -1,    -1,   277,    -1,    -1,   280,   281,    -1,    -1,    -1,
     285,    -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   300,   301,   302,    67,    68,
     305,    -1,    -1,    72,    -1,    74,    -1,    -1,    77,    78,
      -1,    80,    81,    82,    -1,    -1,    85,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,    -1,   124,   125,   126,   127,   128,
     129,   130,    -1,    -1,   133,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,   143,   144,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,   164,   165,    -1,    -1,   168,
      -1,    -1,   171,    -1,   173,   174,    -1,    -1,    -1,    -1,
     179,    -1,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,   228,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    67,    68,    72,    74,    77,    78,    80,    81,
      82,    85,    86,    95,    96,    99,   119,   120,   121,   122,
     124,   125,   126,   127,   128,   129,   130,   133,   136,   138,
     139,   143,   144,   150,   151,   152,   153,   154,   155,   158,
     164,   165,   168,   171,   173,   174,   179,   183,   226,   228,
     231,   239,   312,   323,   324,   325,   326,   335,   342,   362,
     363,   372,   373,   374,   376,   377,   378,   379,   380,   390,
     410,   414,   460,   461,   464,   465,   483,   519,   520,   521,
     522,   524,   528,   530,     4,   513,     6,   510,   511,   513,
     513,   513,   510,   510,   513,     6,   512,   513,   513,   518,
     523,   523,   510,   512,   512,   512,   512,     6,   411,   412,
     449,   513,   513,   510,     3,   538,   510,   510,   510,   510,
     510,   539,   364,   512,   510,     6,   508,   509,   513,   462,
     513,   510,     4,     6,   516,   137,   192,   198,   213,   218,
     228,   231,   235,   240,   270,   278,   381,   383,   384,   385,
     237,   492,   510,   381,   383,     0,    16,   166,   167,   525,
      73,   290,   275,   286,   290,   291,    97,    98,   107,   108,
     109,   220,   254,   269,   343,   344,   345,   348,   351,   354,
     355,   356,   359,   290,   117,   118,   275,   286,   292,   292,
     292,   292,   413,   414,   212,   279,   212,   212,   391,   510,
     510,   140,   163,   466,   290,   290,   275,   286,   294,   180,
     375,   212,   386,   386,   256,   292,   276,     3,   185,   230,
     270,   493,   539,   294,   292,   521,     6,   513,   526,   527,
       6,   513,     6,   513,   513,   513,     6,   157,   161,   185,
     212,   230,   236,   394,   395,   400,   402,   212,   360,   361,
     513,     3,   212,   341,   353,   402,   404,   513,   212,   350,
     513,   212,   341,   346,   276,   513,     6,   513,   513,   334,
     510,   334,   334,   334,   414,   340,   341,   510,   340,   286,
     392,   451,   454,   508,   513,   288,   134,   248,   314,   212,
     367,   513,   463,   513,     6,   513,   513,   462,   387,   451,
     224,   388,   389,   449,   510,   385,   484,    90,    91,    92,
      93,    94,   268,   315,   388,   510,   290,   290,   276,    71,
     290,   275,   212,   212,   212,   357,   402,   212,   212,   100,
     358,   360,   276,   352,   353,   104,   172,   175,   176,   177,
     184,   188,   193,   200,   203,   204,   206,   229,   238,   242,
     249,   251,   260,   262,   300,   303,   440,   441,   442,   443,
     445,   482,   349,   350,   346,   347,   295,   344,   290,   275,
     212,   212,   212,   212,   197,   276,   197,   454,   197,   276,
     290,   223,   290,   450,   228,   481,   490,     4,   514,     3,
       4,     6,    15,    17,    20,    69,    70,    75,    76,   105,
     169,   199,   209,   211,   212,   215,   216,   234,   243,   244,
     250,   251,   261,   264,   266,   267,   270,   272,   274,   277,
     280,   281,   282,   284,   285,   287,   290,   300,   301,   302,
     305,   424,   425,   426,   427,   428,   435,   437,   456,   467,
     468,   469,   470,   471,   491,   497,   498,   505,   513,   515,
     529,   531,   535,   536,   537,   368,   369,   513,   232,   365,
     490,   294,   290,   275,   197,   276,   276,   256,   212,   494,
     495,   496,   497,   233,   321,   322,   497,   321,   321,   321,
     286,   317,   318,   320,   513,   316,   317,   319,   134,   248,
     313,   294,   513,   513,   527,   513,     6,   513,   397,   399,
     451,   401,   451,   401,   197,   276,   358,   401,   424,   480,
     513,   197,   361,   197,   276,   212,   212,   212,   186,   219,
     227,   243,   257,   266,   277,   458,   458,   212,   212,   212,
     212,   212,   212,   212,   212,   145,   146,   147,   201,   403,
     405,   197,   276,   197,   276,   513,   513,     6,   513,   338,
     339,   513,   338,   338,   338,   162,   336,   341,    87,   108,
     109,   156,   291,   327,   328,   329,   451,   244,   513,     3,
     513,   492,   131,   393,   212,   290,     6,   212,   212,   491,
     457,   458,   492,   424,   497,   491,   212,   212,   255,   265,
     424,   499,   500,   212,   491,   212,   212,   491,   491,   212,
     212,   212,   212,   536,   427,   212,   536,     3,   212,   293,
     271,   458,   458,   160,   181,   189,   190,   195,   205,   208,
     210,   221,   222,   241,   259,   284,   291,   297,   298,   434,
     436,   223,   290,    79,   111,   112,   113,   114,   115,   116,
     244,   253,   282,   287,   504,   123,   197,   276,   290,   366,
     463,   513,     6,   513,   451,   389,   388,   497,   276,   485,
     288,   513,   197,   276,   197,   318,   197,   276,   290,   450,
     276,   221,   514,   424,   388,   290,   290,   197,   276,   197,
     276,   197,   402,   197,   197,   353,     3,   446,   446,     3,
     294,   212,   294,     3,   447,     3,     3,     3,   447,   447,
       3,     3,     6,   456,   135,   161,   170,   185,   191,   230,
     236,   396,   406,   407,   408,   409,   350,   346,   290,   197,
     276,   252,   273,   197,   197,   197,   327,     3,     3,     4,
     330,   329,   450,   207,   276,   290,   493,   197,   497,   501,
     513,    21,   501,   501,   294,   493,   197,   197,   497,   503,
     529,   501,   497,   424,   499,   296,   500,   501,   501,   501,
     185,   230,   270,   438,   501,   438,   438,   438,   438,   425,
     426,   294,   212,   294,   432,   536,   432,   432,   432,   212,
     491,   233,   497,   432,   212,   491,   432,   159,   194,   196,
     497,     3,   212,   282,   287,   532,   534,   244,   302,   513,
     497,   497,   497,   497,   497,   440,   369,   513,   212,   290,
     496,   517,   513,   322,   221,   317,   244,   513,   319,   322,
     132,   288,   382,   513,   513,   396,   451,   451,   358,   197,
     197,   197,   276,   186,   219,   227,   243,   257,   266,   277,
     459,     3,   459,   276,   444,   197,   197,   276,   197,   197,
     444,   197,   197,   398,   510,   212,   408,   358,   513,    63,
      64,   291,   299,   331,   332,   333,   339,   331,   331,   331,
     336,     3,   513,   494,   197,   276,   290,   197,   197,   459,
     494,   276,   458,   502,   197,   502,   197,   263,   296,   197,
     197,   197,   497,   197,   497,   497,   497,   497,   459,     3,
     459,   214,   429,   214,   431,   214,   430,   429,   282,   456,
     506,   507,   529,   431,   506,   430,   497,   532,   207,   244,
     253,   276,   282,   283,   287,   533,     3,   223,   290,   233,
     370,   371,   497,   513,   256,   417,   421,   212,   290,   450,
     449,     3,   212,   197,     3,   448,   197,     3,   197,   212,
     480,   330,     3,   333,   207,   450,   421,   497,   513,   421,
     458,   294,   497,   197,   197,   197,   197,   197,   197,   433,
     456,   433,   433,     3,   515,   197,   276,   197,   271,   197,
     532,   532,   532,   513,   197,   276,   418,   420,   510,   187,
     217,   248,   415,   416,   422,   423,   477,   247,   487,   321,
     513,   197,     3,   294,   197,   399,   197,   223,   197,   294,
     459,   294,   507,   497,   207,   207,   276,   223,   371,    49,
      56,   276,   288,   455,   513,     3,   286,   302,   452,   453,
     478,   479,   508,   513,   424,   424,   423,   415,   185,   230,
     270,   439,   182,   245,   472,   488,   197,   450,   197,   459,
     197,   532,   459,   459,   532,   532,   212,   418,   419,   419,
     246,   420,   455,   453,   276,   290,   450,   228,   486,   489,
     513,   289,   182,   207,   276,   207,   207,   276,   418,   292,
     292,   212,   420,   479,   244,   513,   492,   162,   337,     3,
     452,   473,   474,   475,   489,   532,   532,   197,   424,   424,
     418,   450,   493,   276,   252,   273,   476,   337,   207,   207,
     197,   494,   474,   421,   487
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (yystate)
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

/* Line 1464 of yacc.c  */
#line 486 "sql.yacc"
    {
		if ((yyvsp[(5) - (5)].ptr)==0 && (yyvsp[(2) - (5)].integer_val)>=0) {
   				if (A4GL_isyes(acl_getenv("A4GL_ERR_UPDNOWHERE"))) {
                                        yylineno=(yyvsp[(3) - (5)].integer_val);
                                        a4gl_yyerror("UPDATE with no WHERE clause");
                                } else {
		 			A4GL_warn("UPDATE with no WHERE clause"); 
				}
		}
		(yyval.update_cmd)=(yyvsp[(4) - (5)].update_cmd);
		(yyval.update_cmd)->table=strdup((yyvsp[(2) - (5)].str));
		(yyval.update_cmd)->where_clause=(yyvsp[(5) - (5)].ptr);
		(yyval.update_cmd)->value_list=expand_slil((yyval.update_cmd)->value_list);

		if ((yyval.update_cmd)->column_list==0) {
			char colname[200];
			int idtype;
			int isize;
			int rval;
			rval = A4GLSQL_get_columns ((yyvsp[(2) - (5)].str), colname, &idtype, &isize);
			if (rval) {
				(yyval.update_cmd)->column_list=generate_update_column_list_for((yyvsp[(2) - (5)].str),  (yyval.update_cmd)->value_list);
			}
		}
	}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 515 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 518 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 535 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 540 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 543 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 560 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 566 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 575 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 584 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 593 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 600 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 615 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 670 "sql.yacc"
    {
		(yyval.update_cmd)=malloc(sizeof(struct_update_cmd));
		(yyval.update_cmd)->column_list=new_str_list((yyvsp[(1) - (1)].upd_pair)->column_name);
		(yyval.update_cmd)->value_list=0;
		(yyval.update_cmd)->where_clause=0;
		(yyval.update_cmd)->value_list=local_new_select_list_item_list((yyvsp[(1) - (1)].upd_pair)->value);
	}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 677 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 688 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 691 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 696 "sql.yacc"
    {
                struct ilist *i;
                i=&(yyvsp[(2) - (2)].int_list);
                if (strcmp((yyvsp[(1) - (2)].str),"rowid")==0) { add_feature("ROWID"); }
                ADDMAP("Use Column",(yyvsp[(1) - (2)].str));
                strcpy((yyval.str),A4GLSQLCV_make_substr(A4GL_confirm_colname(current_upd_table,(yyvsp[(1) - (2)].str)), i->i0,i->i1,i->i2));
        }
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 703 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 720 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 737 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 758 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 767 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 770 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 778 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 781 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 789 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 790 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 797 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 800 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 808 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 811 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 815 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 821 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 822 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 826 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 836 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 850 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 851 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 856 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 861 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 869 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 877 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 885 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 893 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 905 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 905 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 909 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 913 "sql.yacc"
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_IN")) {
                                strcpy((yyval.str),"");
                        } else {
                                SPRINTF1((yyval.str)," IN %s",(yyvsp[(2) - (2)].str)); add_feature("INDEX_IN");
                        }
        }
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 920 "sql.yacc"
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_FILLFACTOR")) {
                                strcpy((yyval.str),"");
                        } else {
                                SPRINTF1((yyval.str),"FILLFACTOR %s",(yyvsp[(2) - (2)].str)); add_feature("INDEX_FILLFACTOR");
                        }
        }
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 927 "sql.yacc"
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_USING")) {
                                strcpy((yyval.str),"");
                        } else {
                                strcpy((yyval.str),"USING BTREE"); add_feature("INDEX_BTREE");
                        }
        }
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 934 "sql.yacc"
    {
                        if (A4GLSQLCV_check_requirement("OMIT_INDEX_USING")) {
                                strcpy((yyval.str),"");
                        } else {
                                strcpy((yyval.str),"USING RTREE"); add_feature("INDEX_RTREE");
                        }
        }
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 943 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 947 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 954 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 966 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 977 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 983 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 987 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 991 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 996 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 1000 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 1003 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 1007 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 1010 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 1017 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 1018 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 1028 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1029 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1034 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1038 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 1047 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 1056 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1063 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 1066 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 1072 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1075 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1086 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 1090 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1095 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1102 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1105 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1114 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1117 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1121 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1125 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1129 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1133 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1137 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1145 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1149 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1157 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1160 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1167 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1170 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1177 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1180 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1188 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1197 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1200 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1206 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1209 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1215 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1222 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1223 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1227 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1235 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1239 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1246 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1248 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1253 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1254 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1259 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1260 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1266 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1267 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1281 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1287 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1287 "sql.yacc"
    {
		(yyval.insert_cmd)=(yyvsp[(5) - (5)].insert_cmd);
		(yyval.insert_cmd)->connid=0;
		(yyval.insert_cmd)->table=acl_strdup((yyvsp[(3) - (5)].str));
		A4GL_set_associated_mem((yyval.insert_cmd), (yyval.insert_cmd)->table);
		(yyval.insert_cmd)->column_list=(yyvsp[(4) - (5)].str_list);
	}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 1296 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1296 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 1305 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 1330 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1333 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1341 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1344 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1351 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1354 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1362 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1363 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1369 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1370 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1378 "sql.yacc"
    {

			if ((yyvsp[(4) - (4)].ptr)==0 && (yyvsp[(2) - (4)].integer_val)>=0) { 
				if (A4GL_isyes(acl_getenv("A4GL_ERR_DELNOWHERE"))) {
					yylineno=(yyvsp[(2) - (4)].integer_val);
					a4gl_yyerror("DELETE with no WHERE clause"); 
				} else {
					A4GL_warn("DELETE with no WHERE clause"); 
				}
			}
			add_feature("ANSI_DELETE");

			(yyval.delete_cmd)=malloc(sizeof(struct struct_delete_cmd));
			(yyval.delete_cmd)->connid=NULL;
			(yyval.delete_cmd)->table=acl_strdup((yyvsp[(3) - (4)].str));
			(yyval.delete_cmd)->where_clause=(yyvsp[(4) - (4)].ptr);	
			A4GL_set_associated_mem((yyval.delete_cmd), (yyval.delete_cmd)->table);
			
		}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1400 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1404 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1409 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1410 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1420 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1429 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1433 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1438 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1442 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1446 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1450 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1453 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1460 "sql.yacc"
    { (yyval.integer_val)=1; 
#ifndef  SQLCOMPILER
				set_cmdlineno(token_read_on_line);
#endif

}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1466 "sql.yacc"
    { (yyval.integer_val)=-1; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1471 "sql.yacc"
    { (yyval.integer_val)=0; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1479 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1480 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1481 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1482 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1483 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1484 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1485 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1493 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1494 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1495 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1496 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1506 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1507 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1508 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1512 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1513 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1520 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1523 "sql.yacc"
    {
		if (A4GLSQLCV_check_requirement("SIMPLE_GRANT_SELECT"))  {
			SPRINTF0((yyval.str)," SELECT");
		} else {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 1532 "sql.yacc"
    {
		if (A4GLSQLCV_check_requirement("SIMPLE_GRANT_UPDATE"))  {
			SPRINTF0((yyval.str)," UPDATE");
		} else {
			SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		}
	}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 1543 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1545 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1551 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1557 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1567 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1574 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1576 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1582 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1585 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1586 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1593 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1602 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1609 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1621 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1627 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1632 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1636 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1642 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1650 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1655 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1658 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1661 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1668 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1669 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1670 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1671 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1677 "sql.yacc"
    {

#ifdef DEBUG
			A4GL_debug("Str1:%s",(yyvsp[(1) - (4)].str));
			A4GL_debug("Str2:%s",(yyvsp[(2) - (4)].str));
			A4GL_debug("Str3:%s",(yyvsp[(3) - (4)].str));
			A4GL_debug("Str4:%s",(yyvsp[(4) - (4)].sql_string));
#endif

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

/* Line 1464 of yacc.c  */
#line 1700 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1704 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1706 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1713 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1716 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1722 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1730 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1735 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1741 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1746 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1752 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1755 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1760 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1769 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1778 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1787 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1793 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1796 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1807 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1816 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1823 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1829 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1830 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1833 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1838 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1849 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1853 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1861 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1865 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1869 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1873 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1880 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1885 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1893 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1896 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1902 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1905 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1910 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1915 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1928 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1931 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1937 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1940 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1946 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1949 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1955 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1958 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1965 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1969 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1980 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1980 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1981 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1981 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1982 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1982 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1985 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1995 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1996 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 2001 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2010 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2018 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 2021 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 2024 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 2028 "sql.yacc"
    { 
		if (strlen((yyvsp[(2) - (6)].str))) {
			(yyval.s_select_list_item)=new_select_list_item_op_between((yyvsp[(2) - (6)].str),(yyvsp[(1) - (6)].s_select_list_item),(yyvsp[(4) - (6)].s_select_list_item),(yyvsp[(6) - (6)].s_select_list_item),1);
		} else {
			(yyval.s_select_list_item)=new_select_list_item_op_between((yyvsp[(2) - (6)].str),(yyvsp[(1) - (6)].s_select_list_item),(yyvsp[(4) - (6)].s_select_list_item),(yyvsp[(6) - (6)].s_select_list_item),0);
		}
	}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 2035 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 2038 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 2042 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 2045 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 2048 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 2051 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 2057 "sql.yacc"
    {
			if (A4GLSQLCV_check_requirement("NOT_EQUAL_AS_LESS_GREATER_THAN"))  {
				strcpy((yyval.str)," <> ");
			} else {
				strcpy((yyval.str)," != ");
			}
	}
    break;

  case 297:

/* Line 1464 of yacc.c  */
#line 2064 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 2067 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 2070 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 2073 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 2074 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 2079 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 2082 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 2085 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 2088 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 2095 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 2096 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 2097 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 2101 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2108 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 2109 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 2110 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 2114 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 2128 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2143 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2147 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2148 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2157 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2159 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2168 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2171 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2179 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2189 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2197 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 2199 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 2200 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 2201 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 2202 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2203 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2204 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 2205 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2213 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 2214 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2215 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2216 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2217 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2218 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2219 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2220 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2221 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2222 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2223 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2233 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2234 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2241 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 2245 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 2270 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 2271 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 2275 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 2283 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 2286 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 2293 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 2296 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 2306 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 2309 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 2312 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 2315 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 2322 "sql.yacc"
    { 
		struct ilist *i;
		i=&(yyvsp[(2) - (2)].int_list);
		if (strcmp((yyvsp[(1) - (2)].str),"rowid")==0) { strcpy((yyvsp[(1) - (2)].str), A4GLSQLCV_get_sqlconst ("rowid")); add_feature("ROWID"); }
		ADDMAP("Use Column",(yyvsp[(1) - (2)].str));
		strcpy((yyval.str),A4GLSQLCV_make_substr(A4GLSQLCV_check_colname(0,(yyvsp[(1) - (2)].str)), i->i0,i->i1,i->i2));
	}
    break;

  case 371:

/* Line 1464 of yacc.c  */
#line 2329 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2337 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 2346 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 2357 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2369 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2370 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 2380 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 2425 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2426 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2427 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2432 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2433 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 2441 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2448 "sql.yacc"
    {
		add_feature("LOCK_TABLE");
		SPRINTF3((yyval.str),"%s %s %s",
					(yyvsp[(1) - (3)].str),
					(yyvsp[(2) - (3)].str),
					(yyvsp[(3) - (3)].str)
					);
		}
    break;

  case 405:

/* Line 1464 of yacc.c  */
#line 2459 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2460 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2473 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2474 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2478 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2482 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2483 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2486 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2492 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2496 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2519 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2529 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2532 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2538 "sql.yacc"
    {
		if (strcmp((yyvsp[(2) - (2)].str),"DESC")!=0) {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ASC,(yyvsp[(1) - (2)].s_select_list_item));
		} else {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_DESC,(yyvsp[(1) - (2)].s_select_list_item));
		}
	}
    break;

  case 419:

/* Line 1464 of yacc.c  */
#line 2547 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2551 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2558 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2560 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2562 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2566 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2572 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2575 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2581 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2582 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2589 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2602 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2612 "sql.yacc"
    { 
	if (A4GLSQLCV_check_requirement("ALLOW_TIME_DATATYPE")) {
       		strcpy((yyval.str),"TIME"); break;
	} else {
       		strcpy((yyval.str),"DATETIME HOUR TO FRACTION(2)"); break;
	}
 }
    break;

  case 432:

/* Line 1464 of yacc.c  */
#line 2619 "sql.yacc"
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

  case 433:

/* Line 1464 of yacc.c  */
#line 2636 "sql.yacc"
    {
	if (A4GLSQLCV_check_requirement("ALLOW_TIMESTAMP_DATATYPE")) {
		strcpy((yyval.str),"TIMESTAMP");
	} else {
                strcpy((yyval.str),"DATETIME YEAR TO FRACTION(2)"); 
	}
 }
    break;

  case 434:

/* Line 1464 of yacc.c  */
#line 2643 "sql.yacc"
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

  case 435:

/* Line 1464 of yacc.c  */
#line 2668 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2670 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2672 "sql.yacc"
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

  case 438:

/* Line 1464 of yacc.c  */
#line 2693 "sql.yacc"
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

  case 439:

/* Line 1464 of yacc.c  */
#line 2736 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2737 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2751 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2754 "sql.yacc"
    {  
		(yyval.s_select_finish)=acl_malloc2(sizeof(struct s_select_finish));
		(yyval.s_select_finish)->order_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select_finish)->insert_into=0;
		(yyval.s_select_finish)->into_temp=0;
		(yyval.s_select_finish)->nolog=0;
	}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 2761 "sql.yacc"
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

  case 444:

/* Line 1464 of yacc.c  */
#line 2771 "sql.yacc"
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

  case 446:

/* Line 1464 of yacc.c  */
#line 2789 "sql.yacc"
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

  case 447:

/* Line 1464 of yacc.c  */
#line 2802 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(5) - (6)].s_select);
		if ((yyvsp[(2) - (6)].integer_val)!=-1) {
			(yyval.s_select)->limit.start=1;
			(yyval.s_select)->limit.end=(yyvsp[(2) - (6)].integer_val);
		}
		(yyval.s_select)->modifier=acl_strdup((yyvsp[(3) - (6)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->modifier);
		(yyval.s_select)->select_list=(yyvsp[(4) - (6)].s_select_list_item_list);
		(yyval.s_select_list_item)=new_select_list_subquery((yyval.s_select));
	}
    break;

  case 448:

/* Line 1464 of yacc.c  */
#line 2817 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2819 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2825 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2826 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2827 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2828 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2838 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item_list));
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2845 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2848 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2854 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2857 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2862 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2871 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2874 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2878 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2885 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2888 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2891 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2894 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2897 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2900 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2903 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2904 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2905 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2906 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2907 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2908 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2909 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2910 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2911 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2913 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2917 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2921 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2925 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2929 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2933 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2937 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2941 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2944 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2947 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2950 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2953 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2956 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2959 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2962 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2965 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2969 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2973 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2977 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2980 "sql.yacc"
    {
		(yyvsp[(3) - (4)].s_select_list_item)->data.s_select_list_item_data_u.sqlcase.master_condition=(yyvsp[(2) - (4)].s_select_list_item);
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2989 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 2992 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 3001 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 3007 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 3014 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 3017 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 3041 "sql.yacc"
    {(yyval.str_list)=NULL;}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 3042 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(2) - (4)].str));  add_str_list((yyval.str_list),(yyvsp[(4) - (4)].str));}
    break;

  case 506:

/* Line 1464 of yacc.c  */
#line 3043 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(1) - (3)].str));  add_str_list((yyval.str_list),(yyvsp[(3) - (3)].str));}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 3047 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 3050 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 3056 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 3057 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 3058 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 3059 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 3060 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 3061 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 3066 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 3070 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 3074 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 3078 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 3085 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 3088 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 3093 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 3094 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 3095 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3097 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3103 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3113 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3117 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3121 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3125 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3129 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3133 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3137 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3141 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3149 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3159 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3164 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3168 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3172 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3176 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3180 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3185 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3189 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3193 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3201 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3204 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3209 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3210 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3211 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 550:

/* Line 1464 of yacc.c  */
#line 3216 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3217 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 552:

/* Line 1464 of yacc.c  */
#line 3218 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 554:

/* Line 1464 of yacc.c  */
#line 3229 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 556:

/* Line 1464 of yacc.c  */
#line 3235 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 558:

/* Line 1464 of yacc.c  */
#line 3240 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 559:

/* Line 1464 of yacc.c  */
#line 3245 "sql.yacc"
    {(yyval.ptr_list)=0;}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3292 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3299 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 565:

/* Line 1464 of yacc.c  */
#line 3305 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3320 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1464 of yacc.c  */
#line 3321 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3323 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3325 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3328 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 574:

/* Line 1464 of yacc.c  */
#line 3332 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3341 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3347 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3348 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 579:

/* Line 1464 of yacc.c  */
#line 3351 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 3356 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 581:

/* Line 1464 of yacc.c  */
#line 3357 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3361 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3362 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3372 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3373 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3374 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3375 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3376 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3377 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3378 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3379 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3383 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3389 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3391 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3410 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3418 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3425 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3426 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3427 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3428 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3433 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3434 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3435 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3436 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3437 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 3442 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 3443 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 3459 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 3460 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 3461 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 3462 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 3463 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 3464 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 3465 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 3466 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3467 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3468 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 3470 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 3471 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 3472 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3473 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3478 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3481 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 3490 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3491 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3492 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 3493 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 3494 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 3495 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3499 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 632:

/* Line 1464 of yacc.c  */
#line 3500 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 633:

/* Line 1464 of yacc.c  */
#line 3514 "sql.yacc"
    {
	(yyval.integer_val)=-1;
}
    break;



/* Line 1464 of yacc.c  */
#line 8979 "y.tab.c"
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



/* Line 1684 of yacc.c  */
#line 3517 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

