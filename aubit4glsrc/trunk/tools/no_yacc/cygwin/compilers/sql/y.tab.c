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
     INT_VALUE = 2275,
     NAMED = 2276,
     NAMED_GEN = 2277,
     CHAR_VALUE = 2278,
     NOT_USED_1 = 2279,
     NOT_USED_2 = 2280,
     NOT_USED_3 = 2281,
     NOT_USED_4 = 2282,
     NOT_USED_5 = 2283,
     NOT_USED_6 = 2284,
     NOT_USED_7 = 2285,
     NOT_USED_8 = 2286,
     NUMBER_VALUE = 2287,
     SEMICOLON = 2288,
     QUESTION_MARK = 2289,
     CLINE = 2290,
     CH = 2291,
     MARK_VAR = 2292,
     END_MARK_VAR = 2293,
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
     SET_POSTGRESQL_SEARCH_PATH = 1015,
     SET_CONSTRAINTS_ALL_DEFERRED = 1016,
     KW_LIMIT = 1017,
     DOCUMENT = 1018,
     ON_EXCEPTION = 1020,
     SET_DEBUG_FILE_TO = 1021,
     CREATE_DBA_PROCEDURE = 1026,
     CREATE_FUNCTION = 1027,
     CREATE_DBA_FUNCTION = 1028,
     USE_SESSION = 1030,
     KW_RUN_CLIENT = 1031,
     LEFT_JOIN = 1033,
     IGNORE_ERRORS = 1036,
     SQLERRMESSAGE = 1037,
     DISPLAY_NULL_TO = 1038,
     UNBUFFERED = 1039,
     KW_PICTURE = 1040,
     ON_CHANGE = 1041,
     INNER_JOIN = 1042,
     UI_INTERFACE_DOT_FRONTCALL = 1045,
     UICOMBOBOX = 1049,
     UIBROWSER = 1050,
     UIPROGRESS = 1051,
     UIGANTT = 1052,
     UIFORM = 1055,
     USING_BTREE = 1071,
     USING_RTREE = 1072,
     SET_BUFFERED_LOG = 1091,
     SET_LOG = 1094,
     MDY = 1096,
     WEEKDAY = 1097,
     MODE_ANSI = 1100,
     START_DATABASE = 1101,
     WITH_LOG_IN = 1102,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1103,
     DATETIME_VALUE = 1116,
     INTERVAL_VALUE = 1117,
     RECOVER_TABLE = 1118,
     ROLLFORWARD_DATABASE = 1119,
     CONCAT_PIPES = 1133,
     DROP_TRIGGER = 1135,
     DROP_AUDIT_FOR = 1136,
     CREATE_AUDIT_FOR = 1137,
     EXECUTE_PROCEDURE = 1141,
     ALTER_TABLE = 1148,
     ALTER_INDEX = 1149,
     NEXT_SIZE = 1150,
     KW_WHENEVER_SIGNAL = 1187,
     KW_SIGNAL_TOKEN = 1188,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1189,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1190,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1191,
     XSET_MULTIPLY_EQUAL = 1192,
     XSET_OPEN_BRACKET = 1193,
     CREATE_DATABASE = 1196,
     DROP_DATABASE = 1197,
     ADD_CONSTRAINT = 1199,
     DROP_CONSTRAINT = 1200,
     DROP_SYNONYM = 1201,
     CONSTRAINT = 1202,
     NOT_FIELD_TOUCHED_CURRENT = 1205,
     FIELD_TOUCHED_CURRENT = 1206,
     OBJECT_FUNCTION = 1208,
     DOUBLE_PRECISION = 1214,
     COUNT_MULTIPLY = 1215,
     KW_ASCII_OPEN_BRACKET = 1224,
     MODIFY_NEXT_SIZE = 1236,
     LOCK_MODE_PAGE = 1237,
     LOCK_MODE_ROW = 1238,
     TO_UI = 1243,
     UNITS_YEAR = 1246,
     UNITS_MONTH = 1247,
     UNITS_DAY = 1248,
     UNITS_HOUR = 1249,
     UNITS_MINUTE = 1250,
     UNITS_SECOND = 1251,
     TO_CLUSTER = 1256,
     TO_NOT_CLUSTER = 1257,
     CREATE_UC_IDX = 1259,
     CREATE_U_IDX = 1260,
     CREATE_C_IDX = 1261,
     CREATE_IDX = 1262,
     DOUBLE_COLON = 1272,
     SQLSICS = 1278,
     CREATE_SCHEMA = 1279,
     SQLSIRR = 1280,
     UPDATESTATS_T = 1281,
     SQLSICR = 1282,
     SQLSIDR = 1293,
     CREATE_TEMP_TABLE = 1294,
     WITH_CHECK_OPTION = 1302,
     WITH_GRANT_OPTION = 1303,
     SQLSLMNW = 1304,
     WHERE_CURRENT_OF = 1310,
     NOT_NULL_UNIQUE = 1318,
     SQLSLMW = 1325,
     ALL_PRIVILEGES = 1327,
     CREATE_SYNONYM = 1331,
     DROP_TABLE = 1332,
     INEXCLUSIVE = 1334,
     REPORT_TO_FILE = 1335,
     REPORT_TO_UI = 1336,
     UPDATESTATS = 1341,
     CREATE_TABLE = 1367,
     DEFAULT_NULL = 1368,
     DEFAULT_TODAY = 1369,
     DEFAULT_USER = 1370,
     EXIT_TODO = 1377,
     CONTINUE_TODO = 1378,
     UNLOCK_TABLE = 1385,
     ROLLBACK_W = 1393,
     SQLSEON = 1395,
     SQLSEOFF = 1396,
     CREATE_VIEW = 1400,
     DELETE_FROM = 1401,
     EXTENT_SIZE = 1408,
     FOREIGN_KEY = 1409,
     INSERT_INTO = 1412,
     IS_NOT_NULL = 1414,
     NOT_MATCHES = 1417,
     PRIMARY_KEY = 1423,
     WITH_NO_LOG = 1430,
     INSHARE = 1433,
     BEGIN_WORK = 1439,
     DROP_INDEX = 1444,
     FOR_UPDATE_OF = 1450,
     FOR_UPDATE = 1451,
     LOCK_TABLE = 1456,
     NOT_EXISTS = 1458,
     REFERENCES = 1460,
     RENCOL = 1461,
     SMALLFLOAT = 1463,
     COMMIT_W = 1474,
     RENTAB = 1481,
     KW_CHAR = 1484,
     NCHAR = 1485,
     NVARCHAR = 1486,
     DELIMITER = 1488,
     DROP_VIEW = 1490,
     EXCLUSIVE = 1493,
     GREATER_THAN_EQ = 1497,
     INTO_TEMP = 1499,
     DATABASE = 1523,
     DATETIME = 1524,
     DISTINCT = 1526,
     FRACTION = 1533,
     GROUP_BY = 1535,
     INTERVAL = 1536,
     NOT_LIKE = 1538,
     NOT_ILIKE = 1539,
     NOT_NULL = 1540,
     RESOURCE = 1546,
     SMALLINT = 1547,
     IS_NULL = 1553,
     LESS_THAN_EQ = 1554,
     BETWEEN = 1556,
     CLOSE_BRACKET = 1559,
     CONNECT = 1562,
     KW_CURRENT = 1563,
     KW_DECIMAL = 1565,
     KW_DEFAULT = 1567,
     FGL_SYNCFIELDS = 1575,
     INTEGER = 1576,
     SERIAL8 = 1578,
     MATCHES = 1581,
     VARCHAR = 1594,
     CLOSE_SQUARE = 1597,
     GREATER_THAN = 1598,
     KW_FALSE = 1599,
     NOT_IN = 1600,
     OPEN_BRACKET_SELECT = 1602,
     OPEN_BRACKET = 1603,
     KW_DELETE = 1611,
     KW_ESCAPE = 1614,
     EXISTS = 1615,
     EXTEND = 1616,
     HAVING = 1620,
     KW_INSERT = 1622,
     MINUTE = 1626,
     MODIFY = 1627,
     EQUAL = 1629,
     NOT_EQUAL = 1630,
     OPEN_SQUARE = 1632,
     PUBLIC = 1636,
     KW_RETURN_KEY = 1639,
     REVOKE = 1641,
     SECOND = 1645,
     KW_SELECT = 1649,
     SERIAL = 1650,
     UNIQUE = 1653,
     KW_UPDATE = 1655,
     VALUES = 1656,
     KW_NULL = 1659,
     KW_TRUE = 1660,
     ALTER = 1662,
     CHECK = 1668,
     KW_FIRST = 1676,
     KW_FLOAT = 1677,
     GRANT = 1680,
     INDEX = 1683,
     LESS_THAN = 1686,
     MONEY = 1688,
     MONTH = 1689,
     KW_MULTIPLY = 1691,
     ORDER = 1692,
     OUTER = 1693,
     UNION = 1702,
     WHERE = 1705,
     KW_BYTE = 1712,
     CASE = 1714,
     KW_DATE = 1716,
     DESC = 1717,
     KW_DIVIDE = 1718,
     DROP = 1721,
     ELSE = 1722,
     FROM = 1726,
     HOUR = 1732,
     INTO = 1733,
     LIKE = 1736,
     REAL = 1745,
     SOME = 1750,
     KW_TEXT = 1754,
     KW_THEN = 1755,
     USER = 1756,
     WHEN = 1758,
     YEAR = 1761,
     KW_DOW = 1762,
     XSET = 1764,
     ADD = 1765,
     ALL = 1766,
     KW_AND = 1767,
     ANY = 1768,
     ASC = 1769,
     AVG = 1770,
     COLON = 1771,
     KW_COMMA = 1772,
     DAY = 1773,
     DBA = 1774,
     KW_FOR = 1778,
     XMAX = 1783,
     XMIN = 1784,
     KW_MINUS = 1785,
     KW_MOD = 1786,
     KW_NOT = 1787,
     KW_SUM = 1794,
     ATSIGN = 1797,
     KW_PLUS = 1798,
     KW_AS = 1804,
     KW_BY = 1806,
     KW_DOT = 1807,
     KW_IN = 1810,
     KW_ON = 1812,
     KW_OR = 1813,
     KW_TO = 1814,
     BEFORE = 1852,
     END = 1856,
     TILDE = 1863,
     ILIKE = 1864,
     FILLFACTOR = 1867,
     TIME = 1872,
     KW_TODAY = 1879,
     KW_ROWID = 1880,
     TIMESTAMP = 2228,
     KWPIPE = 2258,
     COUNT = 2271,
     DIALOG = 2272,
     SUBDIALOG = 2273
   };
#endif
/* Tokens.  */
#define INT_VALUE 2275
#define NAMED 2276
#define NAMED_GEN 2277
#define CHAR_VALUE 2278
#define NOT_USED_1 2279
#define NOT_USED_2 2280
#define NOT_USED_3 2281
#define NOT_USED_4 2282
#define NOT_USED_5 2283
#define NOT_USED_6 2284
#define NOT_USED_7 2285
#define NOT_USED_8 2286
#define NUMBER_VALUE 2287
#define SEMICOLON 2288
#define QUESTION_MARK 2289
#define CLINE 2290
#define CH 2291
#define MARK_VAR 2292
#define END_MARK_VAR 2293
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
#define SET_POSTGRESQL_SEARCH_PATH 1015
#define SET_CONSTRAINTS_ALL_DEFERRED 1016
#define KW_LIMIT 1017
#define DOCUMENT 1018
#define ON_EXCEPTION 1020
#define SET_DEBUG_FILE_TO 1021
#define CREATE_DBA_PROCEDURE 1026
#define CREATE_FUNCTION 1027
#define CREATE_DBA_FUNCTION 1028
#define USE_SESSION 1030
#define KW_RUN_CLIENT 1031
#define LEFT_JOIN 1033
#define IGNORE_ERRORS 1036
#define SQLERRMESSAGE 1037
#define DISPLAY_NULL_TO 1038
#define UNBUFFERED 1039
#define KW_PICTURE 1040
#define ON_CHANGE 1041
#define INNER_JOIN 1042
#define UI_INTERFACE_DOT_FRONTCALL 1045
#define UICOMBOBOX 1049
#define UIBROWSER 1050
#define UIPROGRESS 1051
#define UIGANTT 1052
#define UIFORM 1055
#define USING_BTREE 1071
#define USING_RTREE 1072
#define SET_BUFFERED_LOG 1091
#define SET_LOG 1094
#define MDY 1096
#define WEEKDAY 1097
#define MODE_ANSI 1100
#define START_DATABASE 1101
#define WITH_LOG_IN 1102
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1103
#define DATETIME_VALUE 1116
#define INTERVAL_VALUE 1117
#define RECOVER_TABLE 1118
#define ROLLFORWARD_DATABASE 1119
#define CONCAT_PIPES 1133
#define DROP_TRIGGER 1135
#define DROP_AUDIT_FOR 1136
#define CREATE_AUDIT_FOR 1137
#define EXECUTE_PROCEDURE 1141
#define ALTER_TABLE 1148
#define ALTER_INDEX 1149
#define NEXT_SIZE 1150
#define KW_WHENEVER_SIGNAL 1187
#define KW_SIGNAL_TOKEN 1188
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1189
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1190
#define XSET_ident_DOT_MULTIPLY_EQUAL 1191
#define XSET_MULTIPLY_EQUAL 1192
#define XSET_OPEN_BRACKET 1193
#define CREATE_DATABASE 1196
#define DROP_DATABASE 1197
#define ADD_CONSTRAINT 1199
#define DROP_CONSTRAINT 1200
#define DROP_SYNONYM 1201
#define CONSTRAINT 1202
#define NOT_FIELD_TOUCHED_CURRENT 1205
#define FIELD_TOUCHED_CURRENT 1206
#define OBJECT_FUNCTION 1208
#define DOUBLE_PRECISION 1214
#define COUNT_MULTIPLY 1215
#define KW_ASCII_OPEN_BRACKET 1224
#define MODIFY_NEXT_SIZE 1236
#define LOCK_MODE_PAGE 1237
#define LOCK_MODE_ROW 1238
#define TO_UI 1243
#define UNITS_YEAR 1246
#define UNITS_MONTH 1247
#define UNITS_DAY 1248
#define UNITS_HOUR 1249
#define UNITS_MINUTE 1250
#define UNITS_SECOND 1251
#define TO_CLUSTER 1256
#define TO_NOT_CLUSTER 1257
#define CREATE_UC_IDX 1259
#define CREATE_U_IDX 1260
#define CREATE_C_IDX 1261
#define CREATE_IDX 1262
#define DOUBLE_COLON 1272
#define SQLSICS 1278
#define CREATE_SCHEMA 1279
#define SQLSIRR 1280
#define UPDATESTATS_T 1281
#define SQLSICR 1282
#define SQLSIDR 1293
#define CREATE_TEMP_TABLE 1294
#define WITH_CHECK_OPTION 1302
#define WITH_GRANT_OPTION 1303
#define SQLSLMNW 1304
#define WHERE_CURRENT_OF 1310
#define NOT_NULL_UNIQUE 1318
#define SQLSLMW 1325
#define ALL_PRIVILEGES 1327
#define CREATE_SYNONYM 1331
#define DROP_TABLE 1332
#define INEXCLUSIVE 1334
#define REPORT_TO_FILE 1335
#define REPORT_TO_UI 1336
#define UPDATESTATS 1341
#define CREATE_TABLE 1367
#define DEFAULT_NULL 1368
#define DEFAULT_TODAY 1369
#define DEFAULT_USER 1370
#define EXIT_TODO 1377
#define CONTINUE_TODO 1378
#define UNLOCK_TABLE 1385
#define ROLLBACK_W 1393
#define SQLSEON 1395
#define SQLSEOFF 1396
#define CREATE_VIEW 1400
#define DELETE_FROM 1401
#define EXTENT_SIZE 1408
#define FOREIGN_KEY 1409
#define INSERT_INTO 1412
#define IS_NOT_NULL 1414
#define NOT_MATCHES 1417
#define PRIMARY_KEY 1423
#define WITH_NO_LOG 1430
#define INSHARE 1433
#define BEGIN_WORK 1439
#define DROP_INDEX 1444
#define FOR_UPDATE_OF 1450
#define FOR_UPDATE 1451
#define LOCK_TABLE 1456
#define NOT_EXISTS 1458
#define REFERENCES 1460
#define RENCOL 1461
#define SMALLFLOAT 1463
#define COMMIT_W 1474
#define RENTAB 1481
#define KW_CHAR 1484
#define NCHAR 1485
#define NVARCHAR 1486
#define DELIMITER 1488
#define DROP_VIEW 1490
#define EXCLUSIVE 1493
#define GREATER_THAN_EQ 1497
#define INTO_TEMP 1499
#define DATABASE 1523
#define DATETIME 1524
#define DISTINCT 1526
#define FRACTION 1533
#define GROUP_BY 1535
#define INTERVAL 1536
#define NOT_LIKE 1538
#define NOT_ILIKE 1539
#define NOT_NULL 1540
#define RESOURCE 1546
#define SMALLINT 1547
#define IS_NULL 1553
#define LESS_THAN_EQ 1554
#define BETWEEN 1556
#define CLOSE_BRACKET 1559
#define CONNECT 1562
#define KW_CURRENT 1563
#define KW_DECIMAL 1565
#define KW_DEFAULT 1567
#define FGL_SYNCFIELDS 1575
#define INTEGER 1576
#define SERIAL8 1578
#define MATCHES 1581
#define VARCHAR 1594
#define CLOSE_SQUARE 1597
#define GREATER_THAN 1598
#define KW_FALSE 1599
#define NOT_IN 1600
#define OPEN_BRACKET_SELECT 1602
#define OPEN_BRACKET 1603
#define KW_DELETE 1611
#define KW_ESCAPE 1614
#define EXISTS 1615
#define EXTEND 1616
#define HAVING 1620
#define KW_INSERT 1622
#define MINUTE 1626
#define MODIFY 1627
#define EQUAL 1629
#define NOT_EQUAL 1630
#define OPEN_SQUARE 1632
#define PUBLIC 1636
#define KW_RETURN_KEY 1639
#define REVOKE 1641
#define SECOND 1645
#define KW_SELECT 1649
#define SERIAL 1650
#define UNIQUE 1653
#define KW_UPDATE 1655
#define VALUES 1656
#define KW_NULL 1659
#define KW_TRUE 1660
#define ALTER 1662
#define CHECK 1668
#define KW_FIRST 1676
#define KW_FLOAT 1677
#define GRANT 1680
#define INDEX 1683
#define LESS_THAN 1686
#define MONEY 1688
#define MONTH 1689
#define KW_MULTIPLY 1691
#define ORDER 1692
#define OUTER 1693
#define UNION 1702
#define WHERE 1705
#define KW_BYTE 1712
#define CASE 1714
#define KW_DATE 1716
#define DESC 1717
#define KW_DIVIDE 1718
#define DROP 1721
#define ELSE 1722
#define FROM 1726
#define HOUR 1732
#define INTO 1733
#define LIKE 1736
#define REAL 1745
#define SOME 1750
#define KW_TEXT 1754
#define KW_THEN 1755
#define USER 1756
#define WHEN 1758
#define YEAR 1761
#define KW_DOW 1762
#define XSET 1764
#define ADD 1765
#define ALL 1766
#define KW_AND 1767
#define ANY 1768
#define ASC 1769
#define AVG 1770
#define COLON 1771
#define KW_COMMA 1772
#define DAY 1773
#define DBA 1774
#define KW_FOR 1778
#define XMAX 1783
#define XMIN 1784
#define KW_MINUS 1785
#define KW_MOD 1786
#define KW_NOT 1787
#define KW_SUM 1794
#define ATSIGN 1797
#define KW_PLUS 1798
#define KW_AS 1804
#define KW_BY 1806
#define KW_DOT 1807
#define KW_IN 1810
#define KW_ON 1812
#define KW_OR 1813
#define KW_TO 1814
#define BEFORE 1852
#define END 1856
#define TILDE 1863
#define ILIKE 1864
#define FILLFACTOR 1867
#define TIME 1872
#define KW_TODAY 1879
#define KW_ROWID 1880
#define TIMESTAMP 2228
#define KWPIPE 2258
#define COUNT 2271
#define DIALOG 2272
#define SUBDIALOG 2273




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 144 "sql.yacc"

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
#line 888 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 900 "y.tab.c"

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
#define YYLAST   2237

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  303
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  632
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1113

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2293

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
      31,    32,    33,    34,    35,    36,    37,    38,    39,     2,
      40,    41,     2,     2,     2,     2,    42,    43,    44,     2,
      45,    46,     2,    47,     2,     2,    48,    49,    50,    51,
      52,    53,    54,     2,     2,    55,     2,     2,     2,    56,
      57,    58,    59,     2,     2,    60,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,    62,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,     2,    64,     2,    65,    66,     2,     2,
      67,    68,    69,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    71,    72,    73,    74,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,    76,    77,    78,     2,     2,
       2,    79,     2,     2,     2,     2,     2,     2,    80,    81,
      82,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    83,    84,    85,
      86,    87,    88,    89,     2,     2,    90,    91,     2,    92,
      93,    94,    95,     2,     2,    96,    97,     2,    98,     2,
       2,     2,     2,     2,    99,   100,     2,     2,     2,     2,
       2,     2,     2,     2,   101,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   102,   103,   104,     2,
       2,     2,     2,   105,     2,     2,   106,   107,   108,   109,
     110,   111,     2,     2,     2,     2,   112,   113,     2,   114,
     115,   116,   117,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   118,     2,     2,     2,     2,     2,   119,   120,
     121,   122,   123,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   124,   125,     2,     2,     2,     2,     2,
       2,     2,   126,   127,   128,     2,     2,     2,     2,     2,
     129,     2,     2,     2,     2,     2,     2,     2,   130,     2,
       2,     2,     2,     2,     2,   131,     2,   132,     2,     2,
       2,   133,   134,     2,   135,   136,   137,     2,     2,     2,
       2,   138,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   139,   140,   141,
     142,     2,     2,     2,     2,     2,     2,   143,   144,     2,
       2,     2,     2,     2,     2,   145,     2,     2,     2,     2,
       2,     2,     2,   146,     2,   147,   148,     2,     2,     2,
     149,   150,     2,     2,     2,     2,     2,     2,   151,   152,
       2,     2,   153,     2,   154,     2,     2,   155,     2,     2,
       2,     2,     2,   156,     2,     2,     2,     2,     2,     2,
     157,     2,     2,   158,     2,     2,     2,     2,     2,   159,
       2,     2,     2,     2,   160,     2,     2,     2,     2,     2,
     161,   162,     2,     2,     2,     2,   163,     2,   164,     2,
     165,   166,     2,   167,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   168,     2,     2,     2,     2,     2,
       2,   169,     2,     2,   170,   171,   172,     2,   173,     2,
     174,     2,     2,   175,     2,     2,     2,   176,     2,   177,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   178,   179,     2,   180,     2,     2,     2,
       2,     2,     2,   181,     2,   182,   183,     2,   184,   185,
     186,     2,     2,     2,     2,     2,   187,   188,     2,     2,
       2,     2,     2,   189,   190,     2,   191,     2,     2,   192,
       2,     2,   193,   194,     2,   195,     2,   196,     2,     2,
       2,     2,     2,     2,     2,   197,   198,     2,   199,     2,
       2,   200,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   201,     2,     2,   202,   203,   204,
     205,     2,   206,   207,     2,     2,     2,     2,     2,     2,
       2,   208,     2,     2,   209,   210,   211,     2,     2,     2,
     212,     2,   213,     2,     2,     2,   214,   215,     2,   216,
     217,     2,   218,     2,     2,     2,   219,     2,     2,   220,
       2,   221,     2,     2,     2,   222,     2,     2,     2,   223,
     224,     2,     2,   225,     2,   226,   227,     2,     2,   228,
     229,     2,   230,     2,     2,     2,     2,     2,   231,     2,
       2,     2,     2,     2,     2,     2,   232,   233,     2,     2,
     234,     2,     2,   235,     2,     2,   236,     2,   237,   238,
       2,   239,   240,   241,     2,     2,     2,     2,     2,     2,
       2,     2,   242,     2,     2,   243,     2,     2,     2,     2,
       2,     2,   244,     2,   245,     2,   246,   247,   248,     2,
       2,   249,   250,     2,     2,     2,   251,     2,     2,     2,
       2,     2,   252,   253,     2,     2,   254,     2,     2,     2,
       2,     2,     2,     2,     2,   255,     2,     2,     2,     2,
     256,     2,     2,     2,   257,   258,   259,     2,   260,     2,
       2,   261,   262,     2,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,     2,     2,     2,   274,     2,
       2,     2,     2,   275,   276,   277,   278,   279,     2,     2,
       2,     2,     2,     2,   280,     2,     2,   281,   282,     2,
       2,     2,     2,     2,   283,     2,   284,   285,     2,     2,
     286,     2,   287,   288,   289,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   290,     2,     2,     2,   291,     2,     2,     2,
       2,     2,     2,   292,   293,     2,     2,   294,     2,     2,
       2,     2,   295,     2,     2,     2,     2,     2,     2,   296,
     297,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   298,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   299,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   300,   301,   302,     2,     3,     4,     5,     6,     7,
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
    1157,  1159,  1161,  1163,  1165,  1167,  1172,  1174,  1176,  1178,
    1183,  1190,  1192,  1194,  1197,  1201,  1203,  1205,  1207,  1212,
    1214,  1216,  1224,  1229,  1231,  1234,  1238,  1240,  1244,  1247,
    1249,  1251,  1252,  1254,  1256,  1259,  1261,  1265,  1267,  1269,
    1271,  1273,  1275,  1280,  1282,  1287,  1288,  1289,  1300,  1307,
    1308,  1312,  1313,  1315,  1320,  1324,  1326,  1332,  1339,  1340,
    1343,  1344,  1346,  1348,  1350,  1352,  1354,  1358,  1360,  1363,
    1367,  1369,  1372,  1375,  1379,  1382,  1386,  1390,  1394,  1398,
    1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,  1416,  1422,
    1428,  1434,  1440,  1446,  1450,  1455,  1460,  1465,  1470,  1475,
    1480,  1485,  1490,  1494,  1499,  1501,  1503,  1507,  1512,  1514,
    1517,  1522,  1525,  1527,  1531,  1532,  1537,  1541,  1542,  1545,
    1548,  1550,  1552,  1554,  1556,  1558,  1560,  1566,  1570,  1576,
    1580,  1582,  1586,  1588,  1590,  1593,  1596,  1598,  1600,  1604,
    1606,  1610,  1616,  1620,  1626,  1634,  1636,  1640,  1644,  1646,
    1648,  1652,  1658,  1662,  1668,  1676,  1680,  1682,  1684,  1688,
    1694,  1698,  1704,  1712,  1714,  1716,  1718,  1721,  1723,  1725,
    1726,  1728,  1730,  1734,  1736,  1738,  1740,  1741,  1743,  1745,
    1747,  1749,  1751,  1753,  1755,  1758,  1760,  1762,  1763,  1765,
    1768,  1770,  1774,  1776,  1780,  1786,  1788,  1790,  1793,  1795,
    1797,  1799,  1801,  1803,  1805,  1807,  1809,  1813,  1817,  1821,
    1825,  1827,  1830,  1832,  1834,  1836,  1838,  1840,  1842,  1844,
    1846,  1850,  1854,  1858,  1864,  1870,  1875,  1882,  1891,  1900,
    1907,  1916,  1927,  1938,  1940,  1944,  1946,  1948,  1950,  1953,
    1956,  1959,  1960
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     511,     0,    -1,   226,   502,   307,   305,    -1,    -1,   129,
     506,    -1,   243,   416,    -1,    -1,   129,   506,    -1,   243,
     416,    -1,    89,   312,   192,   216,   207,   313,   192,    -1,
      85,   313,   192,    -1,    86,   313,   192,    -1,   263,   308,
      -1,    88,   313,    -1,    87,   313,    -1,   311,    -1,   308,
     271,   311,    -1,   310,    -1,   281,   310,    -1,   505,   442,
      -1,   505,   285,   505,   442,    -1,   505,   285,   505,   285,
     505,   442,    -1,   505,   285,   239,    -1,   309,   216,   314,
      -1,   309,    -1,   312,   271,   309,    -1,   314,    -1,   313,
     271,   314,    -1,   489,    -1,   228,    -1,   316,    -1,   134,
     502,    -1,   174,   502,    -1,   160,   504,    -1,    76,   505,
      -1,   327,    -1,   318,    -1,   139,   502,   207,   332,   192,
     319,    -1,   125,   502,   207,   332,   192,   328,   319,   328,
      -1,    -1,   320,    -1,   321,    -1,   320,   321,    -1,   286,
     322,    -1,   151,     3,    -1,    82,     3,    -1,   103,    -1,
     104,    -1,     4,    -1,    -1,   324,    -1,   325,    -1,   324,
     325,    -1,   286,   322,    -1,   294,     3,    -1,    61,    -1,
      62,    -1,   502,    -1,   115,   504,   287,   326,   207,   330,
     192,   323,    -1,   114,   504,   287,   326,   207,   330,   192,
     323,    -1,   116,   504,   287,   326,   207,   330,   192,   323,
      -1,   117,   504,   287,   326,   207,   330,   192,   323,    -1,
      90,   515,    -1,    91,   515,    -1,   133,   502,   274,   502,
      -1,    78,   502,   286,     6,    -1,    77,   502,    -1,    94,
     502,    -1,    73,   502,    -1,    74,   505,    -1,    -1,   157,
      -1,    -1,   157,    -1,   331,    -1,   330,   271,   331,    -1,
     505,   268,    -1,   505,   247,    -1,   505,    -1,   333,    -1,
     332,   271,   333,    -1,   396,    -1,   394,    -1,    80,   505,
     335,    -1,    81,   504,   112,    -1,    81,   504,   113,    -1,
     336,    -1,   335,   271,   336,    -1,   337,    -1,   340,    -1,
     343,    -1,   348,    -1,   351,    -1,   347,    -1,   346,    -1,
     264,   338,    -1,   264,   207,   339,   192,    -1,   333,    -1,
     333,   290,   505,    -1,   338,    -1,   339,   271,   338,    -1,
     249,   342,    -1,   249,   207,   341,   192,    -1,   342,    -1,
     341,   271,   342,    -1,   505,    -1,   215,   345,    -1,   215,
     207,   344,   192,    -1,   345,    -1,   344,   271,   345,    -1,
     333,    -1,   103,    -1,   104,    -1,   102,     3,    -1,    92,
     394,   350,    -1,    92,   207,   349,   192,    -1,   394,   350,
      -1,   349,   271,   394,   350,    -1,    -1,    95,   505,    -1,
      93,   352,    -1,    93,   207,   352,   192,    -1,   353,    -1,
     352,   271,   353,    -1,   505,    -1,   146,    -1,    -1,   153,
     356,   502,   359,   357,    -1,    -1,   227,   358,   207,   362,
     192,    -1,   482,    -1,    -1,   207,   360,   192,    -1,   361,
      -1,   360,   271,   361,    -1,   505,    -1,   505,   285,   505,
      -1,   363,    -1,   362,   271,   363,    -1,   489,    -1,   228,
      -1,   150,   502,   306,    -1,   159,    -1,   168,    -1,    -1,
     175,    -1,   369,    -1,    68,   505,    69,     6,    67,    -1,
      68,   505,    69,     6,    -1,    70,    -1,    63,    -1,    64,
      -1,   122,   505,    -1,   138,    -1,   366,    -1,   365,    -1,
     354,    -1,   368,    -1,   402,    -1,   406,    -1,   452,    -1,
     315,    -1,   317,    -1,   334,    -1,   234,   375,   287,   502,
     289,   380,   374,    -1,   221,   375,   287,   502,   251,   380,
      -1,   234,   373,   289,   380,    -1,   221,   373,   251,   380,
      -1,   193,    -1,   187,    -1,   273,    -1,    -1,   127,    -1,
     283,   441,    -1,   132,    -1,   265,    -1,   376,    -1,   377,
      -1,   376,   271,   377,    -1,   223,   378,    -1,   213,    -1,
     208,    -1,   226,   378,    -1,   230,    -1,   235,    -1,    -1,
     207,   379,   192,    -1,   443,    -1,   379,   271,   443,    -1,
     381,    -1,   380,   271,   381,    -1,   219,    -1,   441,    -1,
     149,   502,   383,   283,   473,   385,    -1,    -1,   207,   384,
     192,    -1,   443,    -1,   384,   271,   443,    -1,    -1,   126,
      -1,   231,   207,   472,   192,    -1,   152,   207,   389,   192,
     388,    -1,   165,   390,    -1,   391,    -1,   502,    -1,   502,
     207,   391,   192,    -1,   443,    -1,   391,   271,   443,    -1,
     225,   207,   393,   192,    -1,   180,   207,   393,   192,    -1,
     156,   207,   393,   192,    -1,   443,    -1,   393,   271,   443,
      -1,   392,    -1,   387,    -1,   386,    -1,   196,   448,    -1,
     142,    -1,   141,    -1,   140,    -1,   505,   432,   397,   398,
      -1,    -1,   395,    -1,    -1,   399,    -1,   400,    -1,   399,
     400,    -1,   401,   350,    -1,   186,    -1,   130,    -1,   225,
      -1,   180,    -1,   388,    -1,   231,   207,   472,   192,    -1,
     156,    -1,   120,   403,   405,    -1,   404,    -1,   441,    -1,
     406,    -1,   405,   406,    -1,   382,    -1,   372,    -1,   212,
     416,    -1,   243,   416,    -1,   251,   410,    -1,   412,    -1,
     410,   271,   412,    -1,   410,   271,   241,   412,    -1,   410,
     271,   241,   207,   410,   192,    -1,   410,    47,   411,   287,
     416,    -1,   410,    54,   411,   287,   416,    -1,   410,    -1,
     207,   410,   192,    -1,   502,    -1,   502,   447,    -1,   502,
     283,   447,    -1,    -1,   409,   414,    -1,   415,    -1,   408,
     415,    -1,    -1,   469,    -1,   469,   407,    -1,   407,    -1,
     417,    -1,   416,   288,   417,    -1,   418,    -1,   417,   266,
     418,    -1,   419,    -1,   279,   419,    -1,   429,    -1,   207,
     416,   192,    -1,   210,   483,    -1,   164,   483,    -1,    -1,
     209,   425,    -1,    -1,   209,   425,    -1,    -1,   209,   425,
      -1,   528,    -1,   448,    -1,    -1,   279,    -1,   489,   426,
     189,    -1,   489,   426,   154,    -1,   489,   428,   489,    -1,
     489,   216,   489,    -1,   489,   216,   228,    -1,   489,   426,
     191,   489,   266,   489,    -1,   489,   254,   424,   423,    -1,
     489,   184,   424,   423,    -1,   489,   293,   424,   422,    -1,
     489,   185,   424,   422,    -1,   489,   200,   424,   421,    -1,
     489,   155,   424,   421,    -1,   217,    -1,   236,    -1,   203,
      -1,   292,    -1,   190,    -1,   176,    -1,   427,    -1,   497,
      -1,   420,    -1,   489,    -1,    -1,   265,    -1,   180,    -1,
     225,    -1,    -1,   265,    -1,   180,    -1,   225,    -1,   433,
      -1,   434,    -1,   435,    -1,   437,    -1,   170,    -1,   170,
     207,   438,   192,    -1,   224,    -1,   224,   207,     3,   192,
      -1,   199,    -1,   199,   207,     3,   192,    -1,   195,    -1,
     195,   207,   439,   436,   192,    -1,   237,   207,   439,   436,
     192,    -1,   237,    -1,   246,    -1,   198,    -1,   188,    -1,
     171,    -1,   171,   207,   438,   192,    -1,   172,    -1,   172,
     207,     3,   192,    -1,   172,   207,     3,   271,     3,   192,
      -1,   179,   450,   289,   451,    -1,   179,    -1,   183,   450,
     289,   451,    -1,   474,    -1,   183,    -1,   183,   450,   207,
       3,   192,   289,   451,    -1,   257,    -1,   244,    -1,   201,
      -1,   201,   207,     3,   192,    -1,   201,   207,     3,   271,
       3,   192,    -1,    -1,   271,   440,    -1,   233,   207,   439,
     192,    -1,   255,    -1,   167,    -1,   233,    -1,    99,    -1,
       3,    -1,     3,    -1,     3,    -1,   505,    -1,     6,    -1,
      -1,   218,     3,   202,    -1,   218,     3,   271,     3,   202,
      -1,   446,    -1,   281,   446,    -1,   445,    -1,   281,   445,
      -1,   505,   442,    -1,   500,   285,   505,   442,    -1,   500,
     285,   239,    -1,   297,    -1,   505,   442,    -1,   500,   285,
     505,   442,    -1,   505,   285,   505,   285,   505,   442,    -1,
     500,   285,   239,    -1,   505,    -1,     6,    -1,   507,    -1,
       3,    -1,   463,    -1,    -1,   450,   289,   451,    -1,   261,
      -1,   238,    -1,   272,    -1,   252,    -1,   214,    -1,   222,
      -1,   181,    -1,   261,    -1,   238,    -1,   272,    -1,   252,
      -1,   214,    -1,   222,    -1,   181,    -1,   181,   207,     3,
     192,    -1,   457,    -1,   456,    -1,   453,    -1,   169,   454,
     289,   454,    -1,   166,   500,   285,   455,   289,   455,    -1,
     505,    -1,   505,    -1,   145,   502,    -1,   163,   502,   458,
      -1,   158,    -1,   135,    -1,   460,    -1,   460,   450,   289,
     451,    -1,    71,    -1,   462,    -1,   462,   450,   207,     3,
     192,   289,   451,    -1,   462,   450,   289,   451,    -1,    72,
      -1,   194,   449,    -1,   240,   284,   465,    -1,   466,    -1,
     465,   271,   466,    -1,   467,   468,    -1,     3,    -1,   444,
      -1,    -1,   268,    -1,   247,    -1,   182,   470,    -1,   471,
      -1,   470,   271,   471,    -1,   444,    -1,     3,    -1,   416,
      -1,   482,    -1,   295,    -1,   295,   207,     3,   192,    -1,
     298,    -1,   298,   207,     3,   192,    -1,    -1,    -1,   223,
     484,   485,   476,   486,   477,   509,   413,   479,   480,    -1,
     223,   484,   485,   486,   413,   479,    -1,    -1,   242,   431,
     478,    -1,    -1,   464,    -1,   464,   177,   481,   329,    -1,
     177,   481,   329,    -1,   505,    -1,   223,   484,   485,   486,
     413,    -1,   206,   484,   485,   486,   413,   192,    -1,    -1,
     232,     3,    -1,    -1,   265,    -1,   180,    -1,   225,    -1,
     487,    -1,   488,    -1,   486,   271,   488,    -1,   489,    -1,
     489,   505,    -1,   489,   283,   505,    -1,   528,    -1,   277,
     528,    -1,   282,   528,    -1,   528,   248,   489,    -1,   528,
     496,    -1,   528,   239,   489,    -1,   528,   282,   489,    -1,
     528,   277,   489,    -1,   528,    75,   489,    -1,   448,    -1,
     229,    -1,   204,    -1,   259,    -1,   296,    -1,   297,    -1,
     295,    -1,   239,    -1,   100,    -1,   269,   207,   430,   489,
     192,    -1,   275,   207,   430,   489,   192,    -1,   276,   207,
     430,   489,   192,    -1,   280,   207,   430,   489,   192,    -1,
     300,   207,   430,   489,   192,    -1,     4,   207,   192,    -1,
       4,   207,   493,   192,    -1,   261,   207,   493,   192,    -1,
     238,   207,   493,   192,    -1,   272,   207,   493,   192,    -1,
      65,   207,   493,   192,    -1,    66,   207,   493,   192,    -1,
     262,   207,   493,   192,    -1,   246,   207,   493,   192,    -1,
     207,   489,   192,    -1,   211,   207,   495,   192,    -1,   459,
      -1,   461,    -1,   245,   491,   291,    -1,   245,   416,   491,
     291,    -1,   492,    -1,   491,   492,    -1,   260,   416,   258,
     489,    -1,   250,   489,    -1,   489,    -1,   493,   271,   489,
      -1,    -1,   271,   450,   289,   451,    -1,   450,   289,   451,
      -1,    -1,   521,   494,    -1,   489,   494,    -1,   106,    -1,
     107,    -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,
     489,   286,   207,   498,   192,    -1,   489,   286,   483,    -1,
     489,   205,   207,   498,   192,    -1,   489,   205,   483,    -1,
     499,    -1,   498,   271,   499,    -1,   521,    -1,   448,    -1,
     277,     3,    -1,   277,   507,    -1,   501,    -1,     6,    -1,
       6,   285,   505,    -1,   505,    -1,   505,   270,   505,    -1,
     505,   270,     6,   285,   505,    -1,   505,   281,   505,    -1,
     505,   281,   505,   270,   505,    -1,   505,   281,   505,   270,
       6,   285,   505,    -1,   503,    -1,     6,   285,   505,    -1,
     505,   285,   505,    -1,     6,    -1,   505,    -1,   505,   270,
     505,    -1,   505,   270,     6,   285,   505,    -1,   505,   281,
     505,    -1,   505,   281,   505,   270,   505,    -1,   505,   281,
     505,   270,     6,   285,   505,    -1,     6,   285,   505,    -1,
       6,    -1,   505,    -1,   505,   270,   505,    -1,   505,   270,
       6,   285,   505,    -1,   505,   281,   505,    -1,   505,   281,
     505,   270,   505,    -1,   505,   281,   505,   270,     6,   285,
     505,    -1,     4,    -1,     4,    -1,    15,    -1,   285,     3,
      -1,     4,    -1,     6,    -1,    -1,   505,    -1,   513,    -1,
     511,    16,   513,    -1,   355,    -1,   304,    -1,   364,    -1,
      -1,   522,    -1,   371,    -1,   514,    -1,   520,    -1,   512,
      -1,   370,    -1,     1,    -1,   516,   517,    -1,   510,    -1,
     475,    -1,    -1,   162,    -1,   161,   518,    -1,   519,    -1,
     518,   271,   519,    -1,   505,    -1,   505,   285,   505,    -1,
       6,   285,   505,   285,   505,    -1,   148,    -1,   147,    -1,
     131,   530,    -1,   128,    -1,   124,    -1,   121,    -1,   119,
      -1,   123,    -1,   527,    -1,    17,    -1,   523,    -1,   178,
     508,   367,    -1,    20,     6,    21,    -1,   207,   524,   192,
      -1,   524,   525,   524,    -1,     3,    -1,   526,     3,    -1,
     282,    -1,   277,    -1,   239,    -1,   248,    -1,   278,    -1,
     282,    -1,   277,    -1,   505,    -1,   505,   285,   239,    -1,
     505,   285,   297,    -1,   505,   285,   505,    -1,   505,   285,
     505,   285,   505,    -1,     6,   285,   505,   285,   505,    -1,
     505,   218,   524,   202,    -1,   505,   285,   505,   218,   524,
     202,    -1,   505,   285,   505,   285,   505,   218,   524,   202,
      -1,     6,   285,   505,   285,   505,   218,   524,   202,    -1,
     505,   218,   524,   271,   524,   202,    -1,   505,   285,   505,
     218,   524,   271,   524,   202,    -1,   505,   285,   505,   285,
     505,   218,   524,   271,   524,   202,    -1,     6,   285,   505,
     285,   505,   218,   524,   271,   524,   202,    -1,   529,    -1,
     529,   118,   432,    -1,   490,    -1,   521,    -1,   483,    -1,
     265,   483,    -1,   267,   483,    -1,   256,   483,    -1,    -1,
       3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   477,   477,   503,   506,   523,   528,   531,   548,   554,
     563,   572,   581,   588,   603,   658,   665,   676,   679,   684,
     691,   708,   725,   746,   755,   758,   766,   769,   777,   778,
     785,   788,   796,   799,   803,   809,   810,   814,   824,   838,
     839,   843,   844,   849,   857,   865,   873,   881,   891,   893,
     893,   896,   897,   901,   908,   915,   922,   931,   935,   942,
     954,   965,   971,   975,   979,   984,   988,   991,   995,   998,
    1005,  1006,  1016,  1017,  1021,  1022,  1026,  1035,  1044,  1051,
    1054,  1060,  1063,  1074,  1078,  1083,  1090,  1093,  1102,  1105,
    1109,  1113,  1117,  1121,  1125,  1133,  1137,  1145,  1148,  1155,
    1158,  1165,  1168,  1175,  1176,  1181,  1185,  1188,  1194,  1197,
    1203,  1210,  1211,  1215,  1223,  1227,  1234,  1236,  1241,  1242,
    1246,  1248,  1254,  1255,  1258,  1269,  1275,  1275,  1284,  1284,
    1293,  1318,  1321,  1329,  1332,  1339,  1342,  1350,  1351,  1357,
    1358,  1366,  1384,  1388,  1393,  1394,  1404,  1413,  1417,  1421,
    1426,  1430,  1434,  1437,  1444,  1450,  1455,  1463,  1464,  1465,
    1466,  1467,  1468,  1469,  1477,  1478,  1479,  1480,  1485,  1486,
    1487,  1490,  1491,  1492,  1496,  1497,  1498,  1502,  1503,  1507,
    1514,  1515,  1516,  1523,  1524,  1527,  1528,  1533,  1534,  1539,
    1540,  1545,  1546,  1551,  1558,  1559,  1564,  1565,  1569,  1570,
    1577,  1585,  1592,  1599,  1603,  1604,  1609,  1610,  1616,  1620,
    1625,  1632,  1633,  1639,  1642,  1645,  1652,  1653,  1654,  1655,
    1661,  1684,  1685,  1688,  1690,  1697,  1700,  1706,  1714,  1719,
    1725,  1730,  1736,  1739,  1744,  1752,  1761,  1766,  1770,  1771,
    1777,  1780,  1791,  1800,  1807,  1813,  1814,  1817,  1822,  1833,
    1837,  1844,  1845,  1849,  1853,  1857,  1864,  1869,  1877,  1880,
    1886,  1889,  1894,  1899,  1912,  1915,  1921,  1924,  1930,  1933,
    1939,  1942,  1949,  1953,  1964,  1964,  1965,  1965,  1966,  1966,
    1969,  1974,  1979,  1980,  1985,  1994,  2002,  2005,  2008,  2012,
    2019,  2022,  2026,  2029,  2032,  2035,  2041,  2048,  2051,  2054,
    2057,  2058,  2063,  2066,  2069,  2072,  2079,  2080,  2081,  2085,
    2092,  2093,  2094,  2098,  2112,  2119,  2120,  2121,  2125,  2126,
    2131,  2132,  2141,  2143,  2152,  2155,  2163,  2173,  2181,  2183,
    2184,  2185,  2186,  2187,  2188,  2189,  2197,  2198,  2199,  2200,
    2201,  2202,  2203,  2204,  2205,  2206,  2207,  2217,  2218,  2224,
    2226,  2227,  2228,  2229,  2233,  2237,  2241,  2248,  2249,  2254,
    2255,  2259,  2267,  2270,  2277,  2280,  2290,  2293,  2296,  2299,
    2306,  2313,  2321,  2330,  2337,  2341,  2346,  2347,  2348,  2353,
    2354,  2363,  2363,  2363,  2363,  2363,  2363,  2363,  2364,  2364,
    2364,  2364,  2364,  2364,  2364,  2364,  2409,  2410,  2411,  2416,
    2417,  2420,  2421,  2425,  2432,  2443,  2444,  2457,  2458,  2462,
    2466,  2467,  2470,  2476,  2480,  2503,  2513,  2516,  2522,  2531,
    2535,  2542,  2543,  2545,  2550,  2556,  2559,  2565,  2566,  2573,
    2586,  2596,  2603,  2620,  2627,  2652,  2654,  2652,  2676,  2720,
    2721,  2735,  2738,  2745,  2755,  2767,  2773,  2786,  2801,  2803,
    2809,  2810,  2811,  2812,  2822,  2829,  2832,  2838,  2841,  2846,
    2855,  2858,  2862,  2869,  2872,  2875,  2878,  2881,  2884,  2887,
    2888,  2889,  2890,  2891,  2892,  2893,  2894,  2895,  2897,  2901,
    2905,  2909,  2913,  2917,  2921,  2925,  2928,  2931,  2934,  2937,
    2940,  2943,  2946,  2949,  2953,  2957,  2961,  2964,  2973,  2976,
    2985,  2991,  2998,  3001,  3025,  3026,  3027,  3030,  3031,  3034,
    3040,  3041,  3042,  3043,  3044,  3045,  3050,  3054,  3058,  3062,
    3069,  3072,  3077,  3078,  3079,  3081,  3087,  3097,  3101,  3105,
    3109,  3113,  3117,  3121,  3125,  3133,  3143,  3148,  3152,  3156,
    3160,  3164,  3169,  3173,  3177,  3185,  3188,  3193,  3194,  3195,
    3200,  3201,  3202,  3210,  3213,  3218,  3219,  3223,  3224,  3229,
    3254,  3271,  3272,  3276,  3283,  3289,  3299,  3301,  3304,  3305,
    3306,  3307,  3309,  3312,  3316,  3321,  3325,  3331,  3332,  3335,
    3340,  3341,  3344,  3345,  3346,  3356,  3357,  3358,  3359,  3360,
    3361,  3362,  3363,  3367,  3373,  3375,  3394,  3402,  3409,  3410,
    3411,  3412,  3417,  3418,  3419,  3420,  3421,  3426,  3427,  3443,
    3444,  3445,  3446,  3447,  3448,  3449,  3450,  3451,  3452,  3454,
    3455,  3456,  3457,  3462,  3465,  3474,  3475,  3476,  3477,  3478,
    3479,  3483,  3484
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
  "SET_POSTGRESQL_SEARCH_PATH", "SET_CONSTRAINTS_ALL_DEFERRED", "KW_LIMIT",
  "DOCUMENT", "ON_EXCEPTION", "SET_DEBUG_FILE_TO", "CREATE_DBA_PROCEDURE",
  "CREATE_FUNCTION", "CREATE_DBA_FUNCTION", "USE_SESSION", "KW_RUN_CLIENT",
  "LEFT_JOIN", "IGNORE_ERRORS", "SQLERRMESSAGE", "DISPLAY_NULL_TO",
  "UNBUFFERED", "KW_PICTURE", "ON_CHANGE", "INNER_JOIN",
  "UI_INTERFACE_DOT_FRONTCALL", "UICOMBOBOX", "UIBROWSER", "UIPROGRESS",
  "UIGANTT", "UIFORM", "USING_BTREE", "USING_RTREE", "SET_BUFFERED_LOG",
  "SET_LOG", "MDY", "WEEKDAY", "MODE_ANSI", "START_DATABASE",
  "WITH_LOG_IN", "SET_CONSTRAINTS_ALL_IMMEDIATE", "DATETIME_VALUE",
  "INTERVAL_VALUE", "RECOVER_TABLE", "ROLLFORWARD_DATABASE",
  "CONCAT_PIPES", "DROP_TRIGGER", "DROP_AUDIT_FOR", "CREATE_AUDIT_FOR",
  "EXECUTE_PROCEDURE", "ALTER_TABLE", "ALTER_INDEX", "NEXT_SIZE",
  "KW_WHENEVER_SIGNAL", "KW_SIGNAL_TOKEN",
  "XSET_MULTIPLY_EQUAL_OPEN_BRACKET",
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
  "COUNT", "DIALOG", "SUBDIALOG", "$accept", "update_statement_c",
  "where_upd_p", "where_del_p", "set_clause_list_uc", "upd_columns_uc",
  "upd_column_name", "upd_column_name_specific", "col_1_up",
  "upd_col_list_sl", "upd_val_list_slil", "upd_val_sli", "drops_statement",
  "drops_c", "create_statement_ss", "create_c_2_ss", "opt_cr_table_extra",
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
  "value_expression_initial_sli_nocast", "op_fgl_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  2274,  2275,  2276,  2277,  2278,  2279,  2280,  2281,
    2282,  2283,  2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,
    2292,  2293,  1000,  1001,  1002,  1003,  1004,  1005,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1020,  1021,  1026,  1027,  1028,  1030,  1031,  1033,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1045,  1049,  1050,  1051,  1052,
    1055,  1071,  1072,  1091,  1094,  1096,  1097,  1100,  1101,  1102,
    1103,  1116,  1117,  1118,  1119,  1133,  1135,  1136,  1137,  1141,
    1148,  1149,  1150,  1187,  1188,  1189,  1190,  1191,  1192,  1193,
    1196,  1197,  1199,  1200,  1201,  1202,  1205,  1206,  1208,  1214,
    1215,  1224,  1236,  1237,  1238,  1243,  1246,  1247,  1248,  1249,
    1250,  1251,  1256,  1257,  1259,  1260,  1261,  1262,  1272,  1278,
    1279,  1280,  1281,  1282,  1293,  1294,  1302,  1303,  1304,  1310,
    1318,  1325,  1327,  1331,  1332,  1334,  1335,  1336,  1341,  1367,
    1368,  1369,  1370,  1377,  1378,  1385,  1393,  1395,  1396,  1400,
    1401,  1408,  1409,  1412,  1414,  1417,  1423,  1430,  1433,  1439,
    1444,  1450,  1451,  1456,  1458,  1460,  1461,  1463,  1474,  1481,
    1484,  1485,  1486,  1488,  1490,  1493,  1497,  1499,  1523,  1524,
    1526,  1533,  1535,  1536,  1538,  1539,  1540,  1546,  1547,  1553,
    1554,  1556,  1559,  1562,  1563,  1565,  1567,  1575,  1576,  1578,
    1581,  1594,  1597,  1598,  1599,  1600,  1602,  1603,  1611,  1614,
    1615,  1616,  1620,  1622,  1626,  1627,  1629,  1630,  1632,  1636,
    1639,  1641,  1645,  1649,  1650,  1653,  1655,  1656,  1659,  1660,
    1662,  1668,  1676,  1677,  1680,  1683,  1686,  1688,  1689,  1691,
    1692,  1693,  1702,  1705,  1712,  1714,  1716,  1717,  1718,  1721,
    1722,  1726,  1732,  1733,  1736,  1745,  1750,  1754,  1755,  1756,
    1758,  1761,  1762,  1764,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,  1772,  1773,  1774,  1778,  1783,  1784,  1785,  1786,  1787,
    1794,  1797,  1798,  1804,  1806,  1807,  1810,  1812,  1813,  1814,
    1852,  1856,  1863,  1864,  1867,  1872,  1879,  1880,  2228,  2258,
    2271,  2272,  2273
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   303,   304,   305,   305,   305,   306,   306,   306,   307,
     307,   307,   307,   307,   307,   308,   308,   309,   309,   310,
     310,   310,   310,   311,   312,   312,   313,   313,   314,   314,
     315,   316,   316,   316,   316,   317,   317,   318,   318,   319,
     319,   320,   320,   321,   321,   321,   321,   321,   322,   323,
     323,   324,   324,   325,   325,   325,   325,   326,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     328,   328,   329,   329,   330,   330,   331,   331,   331,   332,
     332,   333,   333,   334,   334,   334,   335,   335,   336,   336,
     336,   336,   336,   336,   336,   337,   337,   338,   338,   339,
     339,   340,   340,   341,   341,   342,   343,   343,   344,   344,
     345,   346,   346,   347,   348,   348,   349,   349,   350,   350,
     351,   351,   352,   352,   353,   354,   356,   355,   358,   357,
     357,   359,   359,   360,   360,   361,   361,   362,   362,   363,
     363,   364,   365,   366,   367,   367,   368,   369,   369,   369,
     369,   369,   369,   369,   370,   370,   370,   371,   371,   371,
     371,   371,   371,   371,   372,   372,   372,   372,   373,   373,
     373,   374,   374,   374,   375,   375,   375,   376,   376,   377,
     377,   377,   377,   377,   377,   378,   378,   379,   379,   380,
     380,   381,   381,   382,   383,   383,   384,   384,   385,   385,
     386,   387,   388,   389,   390,   390,   391,   391,   392,   392,
     392,   393,   393,   394,   394,   394,   395,   395,   395,   395,
     396,   397,   397,   398,   398,   399,   399,   400,   401,   401,
     401,   401,   401,   401,   401,   402,   403,   404,   405,   405,
     406,   406,   407,   408,   409,   410,   410,   410,   410,   410,
     410,   411,   411,   412,   412,   412,   413,   413,   414,   414,
     415,   415,   415,   415,   416,   416,   417,   417,   418,   418,
     419,   419,   420,   420,   421,   421,   422,   422,   423,   423,
     424,   425,   426,   426,   427,   427,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   428,   428,   428,   428,
     428,   428,   429,   429,   429,   429,   430,   430,   430,   430,
     431,   431,   431,   431,   432,   433,   433,   433,   434,   434,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   436,   436,   437,
     437,   437,   437,   437,   438,   439,   440,   441,   441,   442,
     442,   442,   443,   443,   444,   444,   445,   445,   445,   445,
     446,   446,   446,   446,   447,   448,   448,   448,   448,   449,
     449,   450,   450,   450,   450,   450,   450,   450,   451,   451,
     451,   451,   451,   451,   451,   451,   452,   452,   452,   453,
     453,   454,   455,   456,   457,   458,   458,   459,   459,   460,
     461,   461,   461,   462,   463,   464,   465,   465,   466,   467,
     467,   468,   468,   468,   469,   470,   470,   471,   471,   472,
     473,   474,   474,   474,   474,   476,   477,   475,   478,   479,
     479,   480,   480,   480,   480,   481,   482,   483,   484,   484,
     485,   485,   485,   485,   486,   487,   487,   488,   488,   488,
     489,   489,   489,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   491,   491,
     492,   492,   493,   493,   494,   494,   494,   495,   495,   495,
     496,   496,   496,   496,   496,   496,   497,   497,   497,   497,
     498,   498,   499,   499,   499,   499,   500,   501,   501,   501,
     501,   501,   501,   501,   501,   502,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   505,   506,   507,   507,   508,   508,   509,
     510,   511,   511,   512,   512,   512,   513,   513,   513,   513,
     513,   513,   513,   513,   514,   515,   516,   517,   517,   517,
     518,   518,   519,   519,   519,   520,   520,   520,   520,   520,
     520,   520,   520,   521,   521,   521,   522,   523,   524,   524,
     524,   524,   525,   525,   525,   525,   525,   526,   526,   527,
     527,   527,   527,   527,   527,   527,   527,   527,   527,   527,
     527,   527,   527,   528,   528,   529,   529,   529,   529,   529,
     529,   530,   530
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
       2,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   573,   150,   151,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     591,     0,   590,     0,   592,   589,     0,   588,   631,     0,
       0,   153,     0,     0,   125,   586,   585,     0,     0,   126,
     142,     0,     0,     0,   143,     0,     0,     0,     0,   448,
       0,     0,   564,   161,    30,   162,    36,    35,   163,   156,
     563,   565,   155,   154,   157,   146,   572,   568,   241,   240,
     158,   159,   160,   398,   397,   396,   576,     0,   571,   561,
     569,   577,   570,   567,   553,     0,   538,    68,   535,   539,
      69,    34,    66,     0,     0,   546,     0,   547,   560,   575,
      62,    63,    67,     0,     0,     0,     0,   358,     0,   236,
     237,   357,   152,     0,   632,   587,     0,    31,     0,   403,
     194,     6,     0,    33,     0,     0,     0,   526,   529,     0,
     401,    32,   557,   558,   144,   174,   169,   168,   181,   180,
     185,   185,   183,   184,   175,   170,     0,     0,   176,   177,
       0,   450,     0,     0,     0,     1,     0,     0,   578,   574,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,    83,    86,    88,    89,    90,    94,
      93,    91,    92,     0,    84,    85,     0,     0,     0,     0,
       0,     0,   235,   238,     0,     0,     0,     0,     0,     0,
       0,   141,   131,   406,   405,   404,     0,     0,     0,     0,
       0,   145,   596,     0,   179,   182,     0,     0,     0,   449,
     452,   453,   451,   435,     0,     0,     0,     0,     0,     0,
       3,     0,     0,   562,     0,   582,   579,   580,   148,   536,
       0,   540,   542,   537,    65,     0,     0,     0,     0,     0,
       0,   215,   214,   213,   118,     0,   120,   122,   124,   113,
       0,   110,   106,    82,    81,     0,     0,   101,   105,     0,
      97,    95,     0,   545,     0,   548,   550,     0,    57,     0,
       0,     0,   239,     0,    79,    64,     0,     0,     0,   196,
     362,     0,   359,     0,   554,     7,   377,   553,   375,   555,
     594,     0,     0,     0,   409,   413,   477,     0,   379,   471,
     448,     0,     0,     0,   470,     0,   476,     0,     0,     0,
     472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   475,   473,   474,     0,     8,   264,
     266,   268,   304,   302,   270,   469,   494,   407,   495,   410,
     378,   627,   305,   625,   303,   609,   376,   626,   595,   593,
     460,   623,     0,     0,   528,     0,   402,     0,   530,   532,
     399,     0,   187,   191,   167,   189,   192,     0,   178,     0,
       0,    29,     0,    26,    28,     0,    14,    13,     0,    24,
      17,     0,   359,    12,     0,    15,     0,     0,     2,   166,
       0,     0,     0,     0,   147,     0,     0,     0,     0,     0,
       0,   118,     0,     0,     0,   114,     0,     0,     0,   108,
     353,   351,   318,   331,   333,   337,   340,   330,   324,   329,
     322,   344,   320,   352,   327,   343,   328,   350,   342,   431,
     433,   221,   314,   315,   316,   317,   339,     0,   103,    99,
       0,     0,    87,     0,     0,     0,     0,     0,     0,    70,
       0,    39,   363,   195,     0,     0,     0,     0,   370,   448,
     198,   430,     0,     0,     0,     0,     0,   273,   387,   385,
     386,   382,   384,   381,   383,   414,     0,   450,     0,   282,
     272,   507,     0,     0,     0,     0,     0,   498,     0,   630,
       0,     0,   628,   629,   306,     0,   306,   306,   461,   269,
     306,   462,   556,   306,     0,     0,     0,     0,     0,   301,
       0,     0,   300,     0,   298,     0,     0,   296,   297,     0,
     283,     0,   299,     0,     0,     0,     0,     0,     0,   510,
     511,   512,   513,   514,   515,     0,     0,     0,     0,   464,
       0,     0,   133,   135,   128,   127,   130,     0,     0,     0,
     186,     0,     0,     0,   436,   454,   455,   457,     0,    10,
       0,    11,    18,     0,     0,     0,    19,     0,     0,     4,
       5,     0,     0,   583,   581,   541,     0,   543,     0,   203,
     206,     0,   211,     0,   115,     0,   116,     0,   429,     0,
     119,   121,   123,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,   218,
     217,     0,   222,   223,   102,     0,    96,     0,    98,   549,
       0,   551,     0,    74,    78,     0,     0,     0,    71,    39,
      80,     0,    46,    47,     0,     0,    37,    40,    41,   197,
     373,   359,     0,     0,   450,   199,   193,   483,   502,     0,
       0,   597,     0,     0,     0,     0,   271,   492,   504,     0,
     626,     0,   501,     0,     0,   496,   499,     0,     0,     0,
     308,   309,   307,     0,     0,     0,     0,     0,     0,   265,
     267,     0,     0,     0,   274,   280,   278,   276,   274,     0,
     519,   288,   287,   278,     0,   517,   276,   285,   284,     0,
     286,   600,     0,   608,   607,     0,     0,   610,   611,   612,
     468,   465,   463,   467,   466,   624,   132,     0,     0,     0,
     400,   531,     0,   533,   188,   190,   165,     0,   559,     0,
     458,    27,     0,    25,    22,   359,    16,    23,   171,     0,
       0,     0,     0,   210,     0,   209,   118,   208,   200,   109,
     354,     0,     0,     0,     0,     0,     0,   355,   347,     0,
       0,     0,     0,   347,     0,     0,   375,   216,   229,   234,
       0,   231,   228,   230,     0,   232,   220,   224,   225,   118,
     104,   100,     0,    49,     0,    77,    76,    49,    49,    49,
      70,    45,    44,    48,    43,    42,   371,   360,     0,     0,
       0,   484,     0,     0,   488,   489,   394,   392,   393,   389,
     391,   388,   390,   380,   256,     0,     0,   509,   493,   508,
     486,     0,   497,   491,   485,   490,     0,   487,     0,     0,
       0,     0,   408,     0,   412,     0,   295,     0,   291,     0,
     293,   294,     0,   523,     0,   520,   522,   290,     0,   292,
       0,     0,   615,   604,   605,     0,   603,   606,   602,     0,
     601,     0,     0,   134,   136,     0,     0,   456,   256,   459,
       0,     0,    20,   172,     0,   164,   584,   544,   201,   207,
     212,   117,   319,   332,   334,     0,   336,     0,   338,     0,
       0,   323,   345,     0,   321,   349,     0,   432,   434,   202,
     204,     0,   226,   227,   552,    55,    56,     0,     0,    59,
      50,    51,    75,    58,    60,    61,    38,     0,   359,   256,
     503,   614,     0,     0,   260,     0,     0,     0,   500,   478,
     479,   480,   481,   482,     0,   275,   281,   279,   277,   524,
     525,   518,     0,   516,     0,   598,     0,   599,     0,   613,
     140,     0,   137,   139,   534,   439,     0,   359,   173,     0,
       0,   356,   348,   325,     0,   326,     0,     0,    53,    54,
      52,   361,   372,   446,     0,     0,   244,   245,   253,     0,
       0,     0,   263,   260,   257,   258,   261,   447,     0,   506,
       0,   521,   289,   619,   616,     0,     0,   129,     0,   310,
     441,     9,    21,   335,     0,   346,     0,   233,     0,   395,
       0,     0,     0,     0,   254,   374,   428,     0,   369,   427,
     364,   424,   425,     0,   359,   242,   243,   259,   262,   505,
     411,     0,     0,   138,   312,   313,   311,     0,     0,     0,
     442,   437,   341,   205,   618,     0,     0,   251,     0,     0,
       0,   246,   255,   365,     0,     0,   366,   620,   617,     0,
     448,   440,    72,   445,     0,     0,     0,     0,     0,     0,
       0,   247,   426,   368,   359,     0,   450,    73,   444,   419,
     420,   415,   416,   421,    72,   622,   252,   249,   250,     0,
     367,   621,     0,     0,   423,   422,   418,   443,   248,   256,
     417,   439,   438
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,   398,   201,   230,   393,   394,   390,   395,   391,
     382,   383,    53,    54,    55,    56,   646,   647,   648,   804,
     919,   920,   921,   277,    57,   639,  1088,   632,   633,   283,
     261,    58,   174,   175,   176,   271,   450,   177,   447,   267,
     178,   418,   262,   179,   180,   181,   410,   415,   182,   256,
     257,    59,    60,   122,   555,   729,   363,   551,   552,   961,
     962,    61,    62,    63,   212,    64,    65,    66,    67,    68,
     146,   885,   147,   148,   149,   214,   371,   374,   375,    69,
     198,   288,   656,   251,   252,   785,   588,   909,   589,   253,
     591,   263,   622,   264,   623,   786,   787,   788,   789,    70,
     108,   109,   192,    71,   992,   993,   934,  1057,  1058,   987,
     935,   994,   995,   598,   339,   340,   341,   342,   846,   850,
     848,   694,   945,   534,   343,   535,   344,   683,  1047,   441,
     442,   443,   444,   900,   445,   761,   768,   972,   376,   468,
     592,  1029,  1030,   290,  1024,   345,   485,   826,   823,    72,
      73,   129,   365,    74,    75,   205,   346,   347,   348,   349,
     350,  1050,  1091,  1092,  1093,  1106,   996,  1031,  1032,   599,
     470,   446,    76,   379,   738,  1071,  1010,  1051,  1072,   471,
     351,   151,   223,   564,   565,   566,   352,   353,   496,   497,
     659,   827,   669,   549,   354,   854,   855,   291,   127,   988,
      88,    96,   355,   295,   356,   134,   878,    99,    77,    78,
      79,    80,   100,    81,   159,   236,   237,    82,   357,    83,
     358,   715,   869,   716,   359,   360,   361,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -948
static const yytype_int16 yypact[] =
{
    2003,  -948,  -948,  -948,   145,  -948,   600,   145,   145,   600,
     600,   145,   614,   145,   145,   600,   614,   614,   614,   614,
    -948,   652,  -948,   145,  -948,  -948,   600,  -948,   196,   600,
     600,  -948,   600,   600,  -948,  -948,  -948,   600,   600,  -948,
    -948,   614,   600,   774,  -948,   145,   600,   793,   404,    66,
     600,   404,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,   293,  -948,  -948,
    -948,   427,  -948,  -948,  -948,   238,    36,  -948,  -948,   218,
    -948,  -948,  -948,    38,   383,    42,   558,   -93,  -948,  -948,
    -948,  -948,  -948,    49,    81,    86,   150,  -948,     1,  -948,
    -948,  -948,  -948,   241,  -948,  -948,   184,  -948,   267,  -948,
     273,     4,   600,  -948,   306,   247,   259,  -948,    -9,   201,
    -948,  -948,  -948,  -948,   374,  -948,  -948,  -948,  -948,  -948,
     349,   349,  -948,  -948,  -948,  -948,   309,   278,   297,  -948,
     622,   -70,    85,   307,   316,  -948,  2003,   797,  -948,  -948,
     623,   145,   829,   145,   145,   635,   455,    98,   630,  -948,
    -948,   264,   111,   277,   379,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,   145,  -948,  -948,   837,   145,   600,   600,
     600,   600,     1,  -948,   122,   600,   122,    91,   372,   657,
     962,  -948,   471,  -948,  -948,  -948,   145,   145,   840,   145,
     145,  -948,  -948,    91,  -948,  -948,   130,   600,   536,  -948,
    -948,  -948,  -948,  -948,  1199,  1199,  1199,  1199,    56,    56,
      16,   130,   600,  -948,   429,   432,   454,  -948,   674,  -948,
     462,  -948,   490,  -948,  -948,   554,   557,   563,   314,   567,
     568,  -948,  -948,  -948,   692,   145,   521,  -948,  -948,  -948,
     122,  -948,  -948,  -948,  -948,   496,   145,  -948,  -948,   122,
     506,  -948,   383,  -948,   515,  -948,   534,   601,  -948,   607,
     611,   612,  -948,   -31,  -948,  -948,   -17,   774,   -16,  -948,
    -948,   545,   428,   639,  -948,  -948,  -948,   658,   552,  -948,
    -948,   832,   663,   666,  -948,  -948,  -948,   668,   438,  -948,
      66,   962,   668,   669,  -948,   671,  -948,   836,   672,   668,
    -948,   677,   680,   668,   668,   681,   687,   688,   689,  1768,
    1087,   693,  1768,   878,  -948,  -948,  -948,   696,   625,   645,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,   438,  -948,   438,
    -948,  -948,   631,  -948,  -948,    34,  -948,  -948,  -948,  -948,
     406,   798,   145,   256,  -948,   629,  -948,   637,  -948,   660,
    -948,     2,  -948,  -948,   656,  -948,  -948,   682,  -948,  1653,
    1653,  -948,     8,  -948,  -948,     9,   664,   664,   145,  -948,
    -948,    26,   105,   667,   712,  -948,   657,   962,  -948,   656,
     648,   145,   145,   797,  -948,   145,   846,    91,    91,    91,
      37,   692,    91,   962,   145,  -948,    92,   145,   109,  -948,
    -948,  -948,   732,   734,   735,   438,   438,  -948,   738,  -948,
     739,   741,   742,   743,   744,  -948,  -948,  -948,  -948,   745,
     746,   616,  -948,  -948,  -948,  -948,  -948,   114,  -948,  -948,
     123,   145,  -948,   145,   851,   145,   145,   145,   145,   800,
     122,   141,  -948,  -948,    91,    51,   951,   145,  -948,    66,
     833,  -948,  1314,   145,   937,  1653,  1653,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  -948,   673,   -70,   -73,   771,
    -948,  1653,  1653,  1653,   962,   376,   476,  -948,  1653,  -948,
    1653,  1653,  -948,  -948,    17,  1653,    17,    17,   406,  -948,
      17,   406,  -948,    17,   962,   962,   678,   -59,  1768,  -948,
    1768,  1768,  -948,  1768,  -948,   486,  1426,  -948,  -948,  1768,
    -948,   494,  -948,  1768,   433,  1653,    89,    47,  1653,  -948,
    -948,  -948,  -948,  -948,  -948,  1653,  1653,  1653,  1653,  -948,
     496,   163,  -948,   675,  -948,  -948,  -948,   145,   145,   865,
    -948,    91,   130,   130,   698,  -948,  -948,    52,   778,  -948,
    1199,  -948,  -948,   757,    56,   101,  -948,    56,  1199,  -948,
     625,   130,   690,  -948,  -948,  -948,   695,  -948,   786,   710,
    -948,   165,  -948,   167,  -948,   314,  -948,   168,   625,   791,
    -948,  -948,  -948,  -948,   122,   983,   983,   986,   701,   -53,
     988,   989,   990,   991,   988,   988,   992,   993,  -948,  -948,
    -948,   132,  -948,   312,  -948,   145,  -948,   122,  -948,  -948,
     713,  -948,   172,  -948,  -104,   191,   226,   229,  -948,   141,
    -948,   994,  -948,  -948,   996,   997,  -948,   141,  -948,  -948,
    -948,   785,    24,   719,   -70,  -948,  -948,  -948,  -948,   230,
     720,  -948,   233,   239,   541,  1653,  -948,  -948,   435,   814,
     467,   248,  -948,   -80,   477,  -948,  -948,   263,   275,   301,
    -948,  -948,  -948,  1653,   315,  1653,  1653,  1653,  1653,   645,
    -948,   541,  1005,   541,   801,   406,   802,   803,   801,    97,
    -948,  -948,  -948,   802,    97,  -948,   803,  -948,  -948,  1653,
    -948,  -948,    89,  -948,  -948,   270,  1006,  -948,  -948,   138,
    -948,  -948,  -948,  -948,  -948,  -948,  -948,   145,   145,   806,
    -948,  -948,   729,  -948,  -948,  -948,   656,  1653,  -948,   145,
    -948,  -948,   808,  -948,  -948,   320,  -948,  -948,     5,   145,
     145,   855,    91,  -948,    91,  -948,   692,  -948,  -948,  -948,
    -948,   830,   834,   319,   541,  1018,   541,  -948,   753,   839,
     330,   843,   844,   753,   849,   853,  -948,  -948,  -948,  -948,
     600,  -948,  -948,  -948,   822,  -948,  -948,   312,  -948,   692,
    -948,  -948,   145,    68,   145,  -948,  -948,    68,    68,    68,
     800,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  1029,   145,
    1653,  -948,  1653,   145,  -948,  -948,   831,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -105,   438,   759,  -948,  -948,  -948,
    -948,  1653,  -948,  -948,  -948,  -948,   859,  -948,   861,   862,
     863,   866,  -948,   874,  -948,   132,  -948,   132,  -948,   132,
    -948,  -948,    67,  -948,   331,  -948,  -948,  -948,   338,  -948,
     807,   243,  -948,  -948,  -948,    89,  -948,  -948,  -948,    89,
    -948,    89,   145,  -948,  -948,  1541,   145,  -948,   816,  -948,
    1199,   145,  -948,  -948,   652,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,  -948,  -948,  1065,  -948,   877,  -948,  1069,
     885,  -948,  -948,  1076,  -948,  -948,   888,  -948,  -948,  -948,
     876,   962,  -948,  -948,  -948,  -948,  -948,   997,  1081,  -948,
      68,  -948,  -948,  -948,  -948,  -948,  -948,   883,   785,  -105,
    -948,   869,  1085,   600,   401,   897,   805,   541,  -948,  -948,
    -948,  -948,  -948,  -948,   811,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,    97,  -948,  1653,  -948,   426,   495,   303,   891,
    -948,   339,  -948,  -948,  -948,   864,   343,   785,  -948,   918,
     825,  -948,  -948,  -948,   925,  -948,    91,   927,  -948,  -948,
    -948,  -948,  -948,  -948,    89,   928,    59,  -948,    55,    80,
     962,   962,  -948,   214,  -948,  -948,   910,  -948,   541,  -948,
     541,  -948,  -948,  -948,  -948,    89,    89,  -948,  1541,    39,
      30,  -948,  -948,  -948,   541,  -948,   369,  -948,   360,  -948,
     103,   103,    90,   145,  -948,  -948,  -948,    73,  -948,  -948,
    -948,   852,  -948,   845,   484,   625,   625,  -948,  -948,  -948,
    -948,   550,   615,  -948,  -948,  -948,  -948,   901,   145,   841,
     950,  -948,  -948,  -948,  -948,    89,   600,    59,   847,   848,
     118,  -948,  -948,  -948,    80,   104,  -948,  -948,  -948,    89,
      66,  -948,   971,  -948,    84,   145,   627,    57,   962,   962,
     600,  -948,  -948,  -948,   785,   643,   -70,  -948,  -948,  -948,
    -948,   858,  -948,     3,   971,  -948,  -948,   625,   625,    74,
    -948,  -948,  1653,    84,  -948,  -948,  -948,  -948,  -948,  -105,
    -948,   864,  -948
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -948,  -948,  -948,  -948,  -948,  -948,  -165,   749,   561,  -948,
    -195,  -258,  -948,  -948,  -948,  -948,   500,  -948,   493,   224,
    -205,  -948,   222,   593,  -948,   344,    53,   368,   351,   947,
    -149,  -948,  -948,   879,  -948,  -215,  -948,  -948,  -948,  -218,
    -948,  -948,  -189,  -948,  -948,  -948,  -948,  -361,  -948,   893,
     733,  -948,  -948,  -948,  -948,  -948,  -948,  -948,   419,  -948,
     146,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    1098,  -948,  1104,  -948,   939,  1019,  -948,  -157,   599,  -948,
    -948,  -948,  -948,  -948,  -948,   412,  -948,  -948,   186,  -948,
    -109,  -150,  -948,  -948,  -948,  -948,  -948,   377,  -948,  -948,
    -948,  -948,  -948,   -30,   169,  -948,  -948,  -817,   149,  -871,
    -787,  -948,   174,  -180,   661,   659,   850,  -948,   473,   470,
     474,   411,  -580,  -948,  -948,  -948,  -948,   205,  -948,   628,
    -948,  -948,  -948,   408,  -948,   573,   116,  -948,   -20,  -352,
    -170,  -947,   155,   896,   161,  -560,  -948,  -285,  -568,  -948,
    -948,   975,   632,  -948,  -948,  -948,  -948,  -948,  -948,  -948,
    -948,  -948,  -948,    83,  -948,  -948,  -948,  -948,   124,   279,
    -948,  -948,  -948,  -948,  -948,  -948,    82,  -948,   117,   835,
     -66,  -289,  -443,  -629,  -948,   457,  -159,  -948,   700,  -397,
     414,   526,  -948,  -948,  -948,   502,   245,   -25,  -948,    43,
    -948,   842,    -4,   813,   347,  -948,  -948,  -948,  -948,  -948,
    1048,  -948,  1196,  -948,  -948,  -948,   809,  -948,  -456,  -948,
    -948,  -655,  -948,  -948,  -948,    46,  -948,  -948
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -567
static const yytype_int16 yytable[] =
{
      85,   110,    89,    90,    91,    89,    89,    94,    97,    98,
      98,    89,    97,    97,    97,    97,   254,   111,   126,   112,
     338,   487,    89,   486,   270,    89,    89,   289,    89,    89,
     385,   386,   387,    89,    89,   670,   824,    97,    89,   128,
     576,   130,    89,   372,   665,   284,    89,   284,   448,    87,
     596,    84,    92,    93,   449,    84,    84,   861,   102,    84,
      84,   777,   516,   389,   517,   384,   384,   384,   384,   113,
     949,   419,   116,   117,   399,   118,   119,    84,   193,   125,
     120,   121,   299,  1026,    84,   124,   125,  1089,    84,   131,
     125,   965,   711,   152,    84,    84,    86,   125,   411,   676,
     296,    84,    84,   298,  1020,    84,  1020,    84,    84,    86,
     220,  1021,   299,  1021,   300,    84,   986,   301,    89,   666,
     270,  1020,    84,   842,    86,   844,    84,  1090,  1021,   915,
     916,   488,   883,   199,    84,   296,   107,   495,   776,   853,
     608,   609,   983,   795,   853,   396,   933,   299,   692,    84,
      37,  1061,   489,   235,   765,   221,  1090,   239,   241,   242,
     243,   459,   282,   258,   796,   202,   737,   265,   268,   265,
     224,   225,   226,   227,   228,   461,   463,   186,   831,   273,
     654,   929,   275,   276,    89,    89,    89,    89,   187,  1081,
     265,    89,   265,   292,   560,   222,   896,   680,   898,   114,
     569,   571,   364,   366,   368,   369,   130,  1048,   514,   292,
     956,   810,   111,    89,   957,   514,   958,   580,   573,  1044,
     567,   568,    48,   641,   392,   392,   807,   111,    89,   594,
     693,   278,   278,   278,   278,    51,   766,   590,   285,  1077,
     460,   477,   681,   856,   642,   643,   490,   200,   856,  1096,
    1104,   258,   536,   499,   460,   464,   265,   502,   503,   397,
     377,   208,   268,  1099,  1045,   265,  1108,   947,    84,   948,
    1049,  1105,   209,   561,   245,   400,   562,   676,   246,   570,
     570,    84,   682,   292,   601,   946,   717,   946,   884,   946,
     650,   308,   644,   155,   649,   808,   712,   574,   150,   806,
     593,   603,   247,   597,  1046,   255,   624,   160,   595,   156,
    1056,   640,   741,   658,   673,   626,   658,   658,   266,   537,
     747,   161,  1111,   466,   165,  1080,   308,   183,  1022,  1018,
    1022,  1060,   668,   658,   672,   739,   188,   388,  1023,   658,
     744,   658,   658,  1083,   718,  1022,   658,   249,   229,   373,
    1041,  1042,   333,   250,   917,   726,   871,   753,   553,   755,
     757,  1027,   918,   417,   793,  1027,   713,   702,   189,   999,
    1028,   714,   287,   190,   852,   508,   710,  1028,   511,   720,
     604,  1028,   333,   797,   392,   625,   721,   722,   723,   724,
     575,   734,   853,   882,   627,   891,   989,   582,   583,   235,
    1076,   585,   587,   292,   292,   292,   736,   790,   292,   743,
     600,   384,   791,   258,  1085,   759,   245,   333,   798,   384,
     246,   799,   811,   872,   748,   814,   990,   645,   913,   245,
    1039,   815,  1040,   246,   727,   955,   754,   191,   754,   754,
     830,   203,   778,   794,   247,   756,  1052,   628,   194,   629,
     631,   634,   634,   634,   634,   833,   265,   247,   195,   700,
     292,   651,   794,   653,   204,   705,   245,   834,   779,   660,
     246,   260,   862,  1109,   196,   166,   167,   780,   270,   469,
     197,   538,   863,   554,   269,   168,   169,   170,   162,   249,
     210,   864,   781,   835,   247,   250,   856,   794,   782,   163,
     794,   812,   249,   164,   812,  1004,   567,   837,   250,   863,
     812,   894,   539,   540,   541,   542,   543,   544,   864,   812,
     866,   867,   902,   951,   836,   868,   838,   839,   840,   841,
     953,  1007,   206,   719,   812,  1011,   135,   783,   466,   249,
     936,   865,   863,   784,   207,   250,   812,   866,   867,   211,
     860,   864,   868,   366,   731,   733,   213,   292,   111,   111,
     216,  1053,  1054,   740,   695,   217,   695,   695,   218,   695,
     392,   745,   812,   392,  1005,   695,   982,   111,   567,   695,
     866,   867,   889,   989,   890,   868,   812,   707,   157,   158,
     895,   136,   923,   924,   925,   420,   231,   137,   171,   863,
     265,   903,   952,   232,    84,   881,    86,   245,   864,   952,
    1008,   246,   138,   990,   570,  1012,   478,   139,    84,   478,
      95,   268,   708,   265,   709,   219,   493,   140,  1003,   238,
     141,  1055,   172,   259,   142,   247,   494,   866,   867,   143,
     752,   244,   868,  1102,   991,   545,   466,   173,   478,   479,
     272,   567,   479,   930,   546,   293,    84,   480,   107,  -504,
     480,   294,   248,   421,   514,   863,   422,   423,   424,   144,
     184,   185,   938,   481,   864,   425,   481,   145,   362,   426,
     249,   479,  1066,   547,   427,   966,   250,   482,   548,   480,
     482,   428,   310,   699,   429,   430,   483,   431,   208,   483,
     310,   704,   466,   866,   867,   481,   825,   484,   868,   209,
     484,   685,   686,   467,   401,   687,   963,   402,   688,   482,
     432,   384,   816,   553,   874,   403,   493,   493,   483,   433,
     772,   773,  1100,   434,   863,   879,   494,   494,   825,   484,
     435,   404,   436,   864,   138,   886,   887,   405,   292,   139,
     292,   437,  1067,   438,   208,   817,   618,   619,   620,   140,
     406,   407,   141,   818,   408,   209,   142,   675,   832,  -529,
     409,   143,   866,   867,   412,   413,    89,   868,    84,   819,
     125,  1086,   279,   280,   281,  -282,   518,   414,   914,   863,
     634,   439,   417,   820,   440,  1002,   451,   132,   864,   133,
     453,    84,   821,   234,   454,   928,   590,   519,   455,   931,
    1035,  1036,   621,   822,   456,   520,   521,  1068,   457,   458,
    -282,   522,  -282,   910,   635,   636,   637,   866,   867,  1095,
     465,   523,   868,    84,   524,   240,   525,   473,   474,   296,
     297,    84,   298,   274,    84,  1101,   367,   526,   527,   963,
      84,   299,   586,   300,   863,    84,   301,   630,   103,   104,
     105,   106,   469,   864,   968,   472,   863,   528,   959,    84,
     475,   732,   964,   476,   310,   864,   491,   967,   492,   498,
     111,   512,   863,   123,   500,   529,  1069,   501,   504,   662,
     663,   864,   866,   867,   505,   506,   507,   868,  1097,  1098,
     510,   302,   303,   513,   866,   867,   671,   304,   305,   868,
     530,   515,   677,   514,   678,   679,   550,   531,   557,   684,
     866,   867,   558,   532,   533,   868,   518,   562,   578,    89,
     559,   696,   697,   563,   698,   570,   306,   581,   577,   605,
     703,   606,   607,   567,   706,   610,   611,   519,   612,   613,
     614,   615,   616,   617,   652,   520,   521,   638,   661,   655,
     728,   522,   664,   667,  1033,   296,   297,   691,   298,   737,
     667,   523,   292,   742,   524,   749,   525,   299,   751,   300,
     750,   752,   301,   758,  1025,  1034,   760,   526,   527,   763,
     764,   767,   769,   770,   771,   774,   775,   801,   792,   802,
     307,   803,  1033,   466,   809,   813,   828,   528,   843,   870,
     845,   847,   849,   875,   876,   880,    89,    89,    89,  1025,
     780,   897,   892,  1034,   899,   529,   893,   302,   303,   911,
     308,   901,   927,   304,   305,   904,   905,  -305,   932,  1033,
     309,   907,   310,   311,  1073,   908,   312,   313,   937,  1033,
     530,   939,    89,   940,   941,   942,    89,   531,   943,  -305,
    1034,  1084,   306,   532,   533,   314,   944,   933,   969,   970,
    1034,  1073,   971,   954,   315,   316,    89,   973,  1033,   974,
     975,   317,   318,   976,   979,   981,   493,   984,   985,   997,
     296,   297,   319,   298,   998,   320,   494,   321,   322,  1034,
    1000,   323,   299,   324,   300,   325,  1009,   301,   326,  1006,
    1013,   327,   328,   329,  1014,   330,   331,  1015,   332,  1017,
    1019,   333,   990,  1064,  1070,  1074,   307,  1075,  1087,  1103,
    1065,   334,   335,   336,  1078,  1079,   337,   572,   746,   800,
     805,   978,   980,   286,   926,   922,   873,  1107,   416,   153,
     602,   452,   302,   303,  1043,   154,   308,   378,   304,   305,
     215,   735,  1016,   888,   912,  1038,   309,  1037,   310,   311,
    1059,   851,   312,   313,   690,   689,   859,   857,   725,   762,
     509,   906,  1063,   462,  1062,   370,  1110,   306,  1082,   730,
     977,   314,  1094,  1112,   877,   674,   829,  1001,   556,   950,
     315,   316,   296,   297,   233,   298,   858,   317,   318,   579,
     101,     0,   584,     0,   299,     0,   300,     0,   319,   301,
       0,   320,     0,   321,   322,     0,     0,   323,     0,   324,
       0,   325,     0,     0,   326,     0,     0,   327,   328,   329,
       0,   330,   331,     0,   332,     0,     0,   333,     0,     0,
       0,   307,     0,     0,     0,     0,     0,   334,   335,   336,
       0,     0,   337,     0,   302,   303,     0,     0,     0,     0,
     304,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,   310,   311,     0,     0,   312,   313,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,   296,   297,     0,
     298,     0,     0,     0,     0,   315,   316,     0,     0,   299,
       0,   300,   317,   318,   301,     0,     0,     0,     0,     0,
       0,     0,     0,   319,     0,     0,   320,     0,   321,   322,
       0,     0,   323,     0,   324,     0,   325,     0,     0,   326,
       0,     0,   327,   328,   329,     0,     0,   331,     0,   332,
       0,     0,   333,     0,     0,     0,     0,     0,     0,   302,
     303,     0,   334,   335,   336,   304,   305,   337,     0,     0,
       0,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   309,     0,   310,   380,     0,     0,     0,
     313,     0,     0,     0,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   381,   314,   296,
     297,     0,   298,     0,     0,     0,     0,   315,   316,     0,
       0,   299,     0,   300,   317,   318,   301,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,     0,   320,     0,
     321,   322,     0,     0,   323,     0,   324,     0,   325,     0,
       0,   326,     0,     0,   327,   328,   329,     0,     0,   331,
       0,   332,     0,     0,   333,     0,     0,     0,     0,     0,
       0,   302,   303,     0,   334,   335,   336,   304,   305,   337,
       0,     0,     0,     0,     0,     0,   657,     0,   308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   309,     0,
     310,   380,     0,     0,     0,   313,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   314,   296,   297,     0,   298,     0,     0,
       0,     0,   315,   316,     0,     0,   299,     0,   300,   317,
     318,   301,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,     0,   320,     0,   321,   322,     0,     0,   323,
       0,   324,     0,   325,     0,     0,   326,     0,     0,   327,
     328,   329,     0,     0,   331,     0,   332,     0,     0,   333,
       0,     0,     0,     0,     0,     0,   302,   303,     0,   334,
     335,   336,   304,   305,   337,     0,     0,     0,     0,     0,
     308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,   310,   380,     0,     0,     0,   313,     0,     0,
       0,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   701,   314,   296,   297,     0,   298,
       0,     0,     0,     0,   315,   316,     0,     0,   299,     0,
     300,   317,   318,   301,     0,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,   320,     0,   321,   322,     0,
       0,   323,     0,   324,     0,   325,     0,     0,   326,     0,
       0,   327,   328,   329,     0,     0,   331,     0,   332,     0,
       0,   333,     0,     0,     0,     0,     0,     0,   302,   303,
       0,   334,   335,   336,   304,   305,   337,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,   310,   380,     0,
       0,     0,   313,   306,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   960,
     314,   296,   297,     0,   298,     0,     0,     0,     0,   315,
     316,     0,     0,   299,     0,   300,   317,   318,   301,     0,
       0,     0,     0,     0,     0,     0,     0,   319,     0,     0,
     320,     0,   321,   322,     0,     0,   323,     0,   324,     0,
     325,     0,     0,   326,     0,     0,   327,   328,   329,     0,
       0,   331,     0,   332,     0,     0,   333,     0,     0,     0,
       0,     0,     0,   302,   303,     0,   334,   335,   336,   304,
     305,   337,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,   310,
     380,     0,     0,     0,   313,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   314,     0,     0,     0,     0,     0,     0,     0,
       0,   315,   316,     0,     0,     0,     0,     0,   317,   318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,     0,   320,     0,   321,   322,     0,     0,   323,     0,
     324,     0,   325,     0,     0,   326,     0,     0,   327,   328,
     329,     0,     0,   331,     0,   332,     0,     0,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   334,   335,
     336,     0,     0,   337,     0,     0,     0,     0,     0,     0,
       0,     0,   308,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,   310,   380,     0,     0,     0,   313,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   314,     0,     0,
       0,     0,     0,  -566,     1,     0,   315,   316,     0,     0,
       0,     0,     0,   317,   318,     0,     0,     0,     0,  -566,
       0,     0,     0,     0,   319,     0,     0,   320,     0,   321,
     322,     0,     0,   323,     0,   324,     0,   325,     0,     0,
     326,     0,     0,   327,   328,     0,     0,     0,   331,     0,
       0,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,   335,   336,     2,     3,   337,     0,
       0,     4,     0,     5,     0,     0,     6,     7,     0,     8,
       9,    10,     0,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,    27,     0,     0,    28,     0,    29,    30,     0,     0,
       0,    31,    32,     0,     0,     0,     0,     0,    33,    34,
      35,    36,    37,    38,     0,     0,    39,     0,     0,     0,
       0,     0,    40,    41,     0,     0,    42,     0,     0,    43,
       0,    44,    45,     0,     0,     0,     0,    46,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,    49,     0,     0,    50,
       0,     0,     0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       4,    21,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   166,    21,    43,    23,
     200,   310,    26,   308,   173,    29,    30,   197,    32,    33,
     225,   226,   227,    37,    38,   491,   665,    41,    42,    43,
     392,    45,    46,   213,   487,   194,    50,   196,   266,     6,
     411,     4,     9,    10,   269,     4,     4,   712,    15,     4,
       4,   621,   347,   228,   349,   224,   225,   226,   227,    26,
       3,   260,    29,    30,   231,    32,    33,     4,   108,     6,
      37,    38,    15,     3,     4,    42,     6,     3,     4,    46,
       6,   878,     3,    50,     4,     4,     6,     6,   248,   496,
       3,     4,     4,     6,    47,     4,    47,     4,     4,     6,
     180,    54,    15,    54,    17,     4,   933,    20,   122,   192,
     269,    47,     4,   691,     6,   693,     4,  1074,    54,    61,
      62,   311,   127,   129,     4,     3,     6,   317,     6,   699,
     425,   426,   929,   247,   704,   129,   251,    15,   207,     4,
     149,  1022,   311,   157,   207,   225,  1103,   161,   162,   163,
     164,   192,   192,   167,   268,   122,   271,   171,   172,   173,
      85,    86,    87,    88,    89,   192,   192,   270,   258,   183,
     469,   810,   186,   187,   188,   189,   190,   191,   281,  1060,
     194,   195,   196,   197,   192,   265,   764,   180,   766,     3,
     192,   192,   206,   207,   208,   209,   210,   177,   288,   213,
     865,   654,   216,   217,   869,   288,   871,   397,   192,   180,
     379,   380,   221,    82,   228,   229,   202,   231,   232,   192,
     289,   188,   189,   190,   191,   234,   289,   407,   195,  1056,
     271,   307,   225,   699,   103,   104,   312,   243,   704,   192,
     247,   255,   218,   319,   271,   271,   260,   323,   324,   243,
     217,   270,   266,  1080,   225,   269,   192,   847,     4,   849,
     240,   268,   281,   271,   152,   232,   271,   674,   156,   271,
     271,     4,   265,   287,   192,   845,   239,   847,   283,   849,
     239,   194,   151,     0,   464,   271,   207,   271,   232,   651,
     409,   192,   180,   412,   265,   207,   192,    69,   271,    16,
     207,   460,   570,   472,   494,   192,   475,   476,   207,   285,
     578,   285,  1109,   218,   286,   207,   194,   285,   271,   984,
     271,   241,   491,   492,   493,   283,   287,   281,   283,   498,
     239,   500,   501,   239,   297,   271,   505,   225,   263,   219,
    1005,  1006,   285,   231,   286,   192,   218,   192,   362,   192,
     192,   281,   294,   271,   192,   281,   277,   526,   287,   937,
     297,   282,   281,   287,   277,   329,   535,   297,   332,   538,
     271,   297,   285,   192,   388,   271,   545,   546,   547,   548,
     285,   561,   952,   745,   271,   756,   182,   401,   402,   403,
    1055,   405,   406,   407,   408,   409,   563,   625,   412,   574,
     414,   570,   627,   417,  1069,   604,   152,   285,   192,   578,
     156,   192,   192,   285,   581,   192,   212,   286,   789,   152,
     998,   192,  1000,   156,   271,   192,   271,   287,   271,   271,
     192,   135,   130,   271,   180,   595,  1014,   451,   207,   453,
     454,   455,   456,   457,   458,   192,   460,   180,   274,   525,
     464,   465,   271,   467,   158,   531,   152,   192,   156,   473,
     156,   207,   202,  1102,   207,    92,    93,   165,   627,   223,
     207,    75,   239,   227,   207,   102,   103,   104,   270,   225,
     289,   248,   180,   192,   180,   231,   952,   271,   186,   281,
     271,   271,   225,   285,   271,   202,   665,   192,   231,   239,
     271,   192,   106,   107,   108,   109,   110,   111,   248,   271,
     277,   278,   192,   192,   683,   282,   685,   686,   687,   688,
     192,   192,   285,   537,   271,   192,   132,   225,   218,   225,
     825,   271,   239,   231,   285,   231,   271,   277,   278,   175,
     709,   248,   282,   557,   558,   559,   207,   561,   562,   563,
     251,   192,   202,   567,   518,   287,   520,   521,   271,   523,
     574,   575,   271,   577,   271,   529,   928,   581,   737,   533,
     277,   278,   752,   182,   754,   282,   271,   154,   161,   162,
     271,   187,   797,   798,   799,    99,   289,   193,   215,   239,
     604,   271,   271,   287,     4,   285,     6,   152,   248,   271,
     271,   156,   208,   212,   271,   967,   181,   213,     4,   181,
       6,   625,   189,   627,   191,     3,   250,   223,   202,     6,
     226,   271,   249,     3,   230,   180,   260,   277,   278,   235,
     271,     6,   282,  1086,   243,   239,   218,   264,   181,   214,
     271,   810,   214,   812,   248,   283,     4,   222,     6,   192,
     222,     4,   207,   167,   288,   239,   170,   171,   172,   265,
     112,   113,   831,   238,   248,   179,   238,   273,   207,   183,
     225,   214,  1034,   277,   188,   880,   231,   252,   282,   222,
     252,   195,   206,   207,   198,   199,   261,   201,   270,   261,
     206,   207,   218,   277,   278,   238,   271,   272,   282,   281,
     272,   506,   507,   285,   285,   510,   875,   285,   513,   252,
     224,   880,   181,   727,   728,   271,   250,   250,   261,   233,
     614,   615,  1084,   237,   239,   739,   260,   260,   271,   272,
     244,    67,   246,   248,   208,   749,   750,   285,   752,   213,
     754,   255,   202,   257,   270,   214,   140,   141,   142,   223,
     270,   207,   226,   222,   207,   281,   230,   291,   291,   285,
     207,   235,   277,   278,   207,   207,   780,   282,     4,   238,
       6,  1070,   189,   190,   191,   154,   155,    95,   792,   239,
     794,   295,   271,   252,   298,   954,   290,     4,   248,     6,
     285,     4,   261,     6,   270,   809,   976,   176,   207,   813,
     990,   991,   196,   272,   207,   184,   185,   202,   207,   207,
     189,   190,   191,   780,   456,   457,   458,   277,   278,   202,
     285,   200,   282,     4,   203,     6,   205,   285,     6,     3,
       4,     4,     6,     6,     4,   202,     6,   216,   217,  1008,
       4,    15,     6,    17,   239,     4,    20,     6,    16,    17,
      18,    19,   223,   248,   884,   207,   239,   236,   872,     4,
     207,     6,   876,   207,   206,   248,   207,   881,   207,   207,
     884,     3,   239,    41,   207,   254,   271,   207,   207,   475,
     476,   248,   277,   278,   207,   207,   207,   282,  1078,  1079,
     207,    65,    66,   207,   277,   278,   492,    71,    72,   282,
     279,   266,   498,   288,   500,   501,   118,   286,   289,   505,
     277,   278,   285,   292,   293,   282,   155,   271,   216,   933,
     270,   520,   521,   251,   523,   271,   100,   289,   271,   207,
     529,   207,   207,  1102,   533,   207,   207,   176,   207,   207,
     207,   207,   207,   207,     3,   184,   185,   157,    21,   126,
     285,   190,   289,   192,   989,     3,     4,   289,     6,   271,
     192,   200,   976,   216,   203,   285,   205,    15,   192,    17,
     285,   271,    20,   192,   988,   989,     3,   216,   217,     3,
     289,     3,     3,     3,     3,     3,     3,     3,   285,     3,
     164,     4,  1027,   218,   285,   285,   192,   236,     3,     3,
     209,   209,   209,   207,   285,   207,  1020,  1021,  1022,  1023,
     165,     3,   192,  1027,   271,   254,   192,    65,    66,   207,
     194,   192,     3,    71,    72,   192,   192,   266,   207,  1064,
     204,   192,   206,   207,  1048,   192,   210,   211,   289,  1074,
     279,   192,  1056,   192,   192,   192,  1060,   286,   192,   288,
    1064,  1065,   100,   292,   293,   229,   192,   251,     3,   192,
    1074,  1075,     3,   266,   238,   239,  1080,   192,  1103,     3,
     192,   245,   246,   207,     3,   202,   250,   218,     3,   192,
       3,     4,   256,     6,   289,   259,   260,   261,   262,  1103,
     289,   265,    15,   267,    17,   269,   242,    20,   272,   218,
     192,   275,   276,   277,   289,   279,   280,   192,   282,   192,
     192,   285,   212,   271,   223,   284,   164,   177,   157,   271,
     285,   295,   296,   297,   287,   287,   300,   388,   577,   639,
     647,   917,   920,   196,   800,   794,   727,  1094,   255,    51,
     417,   272,    65,    66,  1008,    51,   194,   218,    71,    72,
     141,   562,   976,   751,   787,   996,   204,   993,   206,   207,
    1021,   698,   210,   211,   515,   514,   706,   703,   550,   606,
     330,   773,  1027,   287,  1023,   210,  1103,   100,  1064,   557,
     911,   229,  1075,  1111,   737,   495,   670,   952,   363,   852,
     238,   239,     3,     4,   156,     6,   704,   245,   246,   396,
      14,    -1,   403,    -1,    15,    -1,    17,    -1,   256,    20,
      -1,   259,    -1,   261,   262,    -1,    -1,   265,    -1,   267,
      -1,   269,    -1,    -1,   272,    -1,    -1,   275,   276,   277,
      -1,   279,   280,    -1,   282,    -1,    -1,   285,    -1,    -1,
      -1,   164,    -1,    -1,    -1,    -1,    -1,   295,   296,   297,
      -1,    -1,   300,    -1,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,   206,   207,    -1,    -1,   210,   211,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   229,     3,     4,    -1,
       6,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    15,
      -1,    17,   245,   246,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,    -1,    -1,   259,    -1,   261,   262,
      -1,    -1,   265,    -1,   267,    -1,   269,    -1,    -1,   272,
      -1,    -1,   275,   276,   277,    -1,    -1,   280,    -1,   282,
      -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,   295,   296,   297,    71,    72,   300,    -1,    -1,
      -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,   206,   207,    -1,    -1,    -1,
     211,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,     3,
       4,    -1,     6,    -1,    -1,    -1,    -1,   238,   239,    -1,
      -1,    15,    -1,    17,   245,   246,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,   259,    -1,
     261,   262,    -1,    -1,   265,    -1,   267,    -1,   269,    -1,
      -1,   272,    -1,    -1,   275,   276,   277,    -1,    -1,   280,
      -1,   282,    -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,   295,   296,   297,    71,    72,   300,
      -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
     206,   207,    -1,    -1,    -1,   211,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,   238,   239,    -1,    -1,    15,    -1,    17,   245,
     246,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,   259,    -1,   261,   262,    -1,    -1,   265,
      -1,   267,    -1,   269,    -1,    -1,   272,    -1,    -1,   275,
     276,   277,    -1,    -1,   280,    -1,   282,    -1,    -1,   285,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,   295,
     296,   297,    71,    72,   300,    -1,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,   229,     3,     4,    -1,     6,
      -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    15,    -1,
      17,   245,   246,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,    -1,    -1,   259,    -1,   261,   262,    -1,
      -1,   265,    -1,   267,    -1,   269,    -1,    -1,   272,    -1,
      -1,   275,   276,   277,    -1,    -1,   280,    -1,   282,    -1,
      -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,   295,   296,   297,    71,    72,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,   206,   207,    -1,
      -1,    -1,   211,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     229,     3,     4,    -1,     6,    -1,    -1,    -1,    -1,   238,
     239,    -1,    -1,    15,    -1,    17,   245,   246,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,
     259,    -1,   261,   262,    -1,    -1,   265,    -1,   267,    -1,
     269,    -1,    -1,   272,    -1,    -1,   275,   276,   277,    -1,
      -1,   280,    -1,   282,    -1,    -1,   285,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    -1,   295,   296,   297,    71,
      72,   300,    -1,    -1,    -1,    -1,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,   206,
     207,    -1,    -1,    -1,   211,    -1,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,   246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    -1,   259,    -1,   261,   262,    -1,    -1,   265,    -1,
     267,    -1,   269,    -1,    -1,   272,    -1,    -1,   275,   276,
     277,    -1,    -1,   280,    -1,   282,    -1,    -1,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,   296,
     297,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,    -1,   206,   207,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,   238,   239,    -1,    -1,
      -1,    -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,   256,    -1,    -1,   259,    -1,   261,
     262,    -1,    -1,   265,    -1,   267,    -1,   269,    -1,    -1,
     272,    -1,    -1,   275,   276,    -1,    -1,    -1,   280,    -1,
      -1,    -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   295,   296,   297,    63,    64,   300,    -1,
      -1,    68,    -1,    70,    -1,    -1,    73,    74,    -1,    76,
      77,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,   116,
     117,    -1,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,   128,    -1,    -1,   131,    -1,   133,   134,    -1,    -1,
      -1,   138,   139,    -1,    -1,    -1,    -1,    -1,   145,   146,
     147,   148,   149,   150,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,   163,    -1,    -1,   166,
      -1,   168,   169,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,    -1,   223,    -1,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    63,    64,    68,    70,    73,    74,    76,    77,
      78,    80,    81,    90,    91,    94,   114,   115,   116,   117,
     119,   120,   121,   122,   123,   124,   125,   128,   131,   133,
     134,   138,   139,   145,   146,   147,   148,   149,   150,   153,
     159,   160,   163,   166,   168,   169,   174,   178,   221,   223,
     226,   234,   304,   315,   316,   317,   318,   327,   334,   354,
     355,   364,   365,   366,   368,   369,   370,   371,   372,   382,
     402,   406,   452,   453,   456,   457,   475,   511,   512,   513,
     514,   516,   520,   522,     4,   505,     6,   502,   503,   505,
     505,   505,   502,   502,   505,     6,   504,   505,   505,   510,
     515,   515,   502,   504,   504,   504,   504,     6,   403,   404,
     441,   505,   505,   502,     3,   530,   502,   502,   502,   502,
     502,   502,   356,   504,   502,     6,   500,   501,   505,   454,
     505,   502,     4,     6,   508,   132,   187,   193,   208,   213,
     223,   226,   230,   235,   265,   273,   373,   375,   376,   377,
     232,   484,   502,   373,   375,     0,    16,   161,   162,   517,
      69,   285,   270,   281,   285,   286,    92,    93,   102,   103,
     104,   215,   249,   264,   335,   336,   337,   340,   343,   346,
     347,   348,   351,   285,   112,   113,   270,   281,   287,   287,
     287,   287,   405,   406,   207,   274,   207,   207,   383,   129,
     243,   306,   502,   135,   158,   458,   285,   285,   270,   281,
     289,   175,   367,   207,   378,   378,   251,   287,   271,     3,
     180,   225,   265,   485,    85,    86,    87,    88,    89,   263,
     307,   289,   287,   513,     6,   505,   518,   519,     6,   505,
       6,   505,   505,   505,     6,   152,   156,   180,   207,   225,
     231,   386,   387,   392,   394,   207,   352,   353,   505,     3,
     207,   333,   345,   394,   396,   505,   207,   342,   505,   207,
     333,   338,   271,   505,     6,   505,   505,   326,   502,   326,
     326,   326,   406,   332,   333,   502,   332,   281,   384,   443,
     446,   500,   505,   283,     4,   506,     3,     4,     6,    15,
      17,    20,    65,    66,    71,    72,   100,   164,   194,   204,
     206,   207,   210,   211,   229,   238,   239,   245,   246,   256,
     259,   261,   262,   265,   267,   269,   272,   275,   276,   277,
     279,   280,   282,   285,   295,   296,   297,   300,   416,   417,
     418,   419,   420,   427,   429,   448,   459,   460,   461,   462,
     463,   483,   489,   490,   497,   505,   507,   521,   523,   527,
     528,   529,   207,   359,   505,   455,   505,     6,   505,   505,
     454,   379,   443,   219,   380,   381,   441,   502,   377,   476,
     207,   228,   313,   314,   489,   313,   313,   313,   281,   309,
     310,   312,   505,   308,   309,   311,   129,   243,   305,   380,
     502,   285,   285,   271,    67,   285,   270,   207,   207,   207,
     349,   394,   207,   207,    95,   350,   352,   271,   344,   345,
      99,   167,   170,   171,   172,   179,   183,   188,   195,   198,
     199,   201,   224,   233,   237,   244,   246,   255,   257,   295,
     298,   432,   433,   434,   435,   437,   474,   341,   342,   338,
     339,   290,   336,   285,   270,   207,   207,   207,   207,   192,
     271,   192,   446,   192,   271,   285,   218,   285,   442,   223,
     473,   482,   207,   285,     6,   207,   207,   483,   181,   214,
     222,   238,   252,   261,   272,   449,   450,   484,   416,   489,
     483,   207,   207,   250,   260,   416,   491,   492,   207,   483,
     207,   207,   483,   483,   207,   207,   207,   207,   528,   419,
     207,   528,     3,   207,   288,   266,   450,   450,   155,   176,
     184,   185,   190,   200,   203,   205,   216,   217,   236,   254,
     279,   286,   292,   293,   426,   428,   218,   285,    75,   106,
     107,   108,   109,   110,   111,   239,   248,   277,   282,   496,
     118,   360,   361,   505,   227,   357,   482,   289,   285,   270,
     192,   271,   271,   251,   486,   487,   488,   489,   489,   192,
     271,   192,   310,   192,   271,   285,   442,   271,   216,   506,
     416,   289,   505,   505,   519,   505,     6,   505,   389,   391,
     443,   393,   443,   393,   192,   271,   350,   393,   416,   472,
     505,   192,   353,   192,   271,   207,   207,   207,   450,   450,
     207,   207,   207,   207,   207,   207,   207,   207,   140,   141,
     142,   196,   395,   397,   192,   271,   192,   271,   505,   505,
       6,   505,   330,   331,   505,   330,   330,   330,   157,   328,
     333,    82,   103,   104,   151,   286,   319,   320,   321,   443,
     239,   505,     3,   505,   484,   126,   385,   192,   489,   493,
     505,    21,   493,   493,   289,   485,   192,   192,   489,   495,
     521,   493,   489,   416,   491,   291,   492,   493,   493,   493,
     180,   225,   265,   430,   493,   430,   430,   430,   430,   417,
     418,   289,   207,   289,   424,   528,   424,   424,   424,   207,
     483,   228,   489,   424,   207,   483,   424,   154,   189,   191,
     489,     3,   207,   277,   282,   524,   526,   239,   297,   505,
     489,   489,   489,   489,   489,   432,   192,   271,   285,   358,
     455,   505,     6,   505,   443,   381,   380,   271,   477,   283,
     505,   314,   216,   309,   239,   505,   311,   314,   380,   285,
     285,   192,   271,   192,   271,   192,   394,   192,   192,   345,
       3,   438,   438,     3,   289,   207,   289,     3,   439,     3,
       3,     3,   439,   439,     3,     3,     6,   448,   130,   156,
     165,   180,   186,   225,   231,   388,   398,   399,   400,   401,
     342,   338,   285,   192,   271,   247,   268,   192,   192,   192,
     319,     3,     3,     4,   322,   321,   442,   202,   271,   285,
     485,   192,   271,   285,   192,   192,   181,   214,   222,   238,
     252,   261,   272,   451,   486,   271,   450,   494,   192,   494,
     192,   258,   291,   192,   192,   192,   489,   192,   489,   489,
     489,   489,   451,     3,   451,   209,   421,   209,   423,   209,
     422,   421,   277,   448,   498,   499,   521,   423,   498,   422,
     489,   524,   202,   239,   248,   271,   277,   278,   282,   525,
       3,   218,   285,   361,   505,   207,   285,   488,   509,   505,
     207,   285,   442,   127,   283,   374,   505,   505,   388,   443,
     443,   350,   192,   192,   192,   271,   451,     3,   451,   271,
     436,   192,   192,   271,   192,   192,   436,   192,   192,   390,
     502,   207,   400,   350,   505,    61,    62,   286,   294,   323,
     324,   325,   331,   323,   323,   323,   328,     3,   505,   486,
     489,   505,   207,   251,   409,   413,   450,   289,   489,   192,
     192,   192,   192,   192,   192,   425,   448,   425,   425,     3,
     507,   192,   271,   192,   266,   192,   524,   524,   524,   505,
     228,   362,   363,   489,   505,   413,   313,   505,   441,     3,
     192,     3,   440,   192,     3,   192,   207,   472,   322,     3,
     325,   202,   442,   413,   218,     3,   410,   412,   502,   182,
     212,   243,   407,   408,   414,   415,   469,   192,   289,   451,
     289,   499,   489,   202,   202,   271,   218,   192,   271,   242,
     479,   192,   442,   192,   289,   192,   391,   192,   524,   192,
      47,    54,   271,   283,   447,   505,     3,   281,   297,   444,
     445,   470,   471,   500,   505,   416,   416,   415,   407,   451,
     451,   524,   524,   363,   180,   225,   265,   431,   177,   240,
     464,   480,   451,   192,   202,   271,   207,   410,   411,   411,
     241,   412,   447,   445,   271,   285,   442,   202,   202,   271,
     223,   478,   481,   505,   284,   177,   524,   410,   287,   287,
     207,   412,   471,   239,   505,   524,   484,   157,   329,     3,
     444,   465,   466,   467,   481,   202,   192,   416,   416,   410,
     442,   202,   485,   271,   247,   268,   468,   329,   192,   486,
     466,   413,   479
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

/* Line 1464 of yacc.c  */
#line 477 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 503 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 506 "sql.yacc"
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
#line 523 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 528 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 531 "sql.yacc"
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
#line 548 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 554 "sql.yacc"
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
#line 563 "sql.yacc"
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
#line 572 "sql.yacc"
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
#line 581 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 588 "sql.yacc"
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
#line 603 "sql.yacc"
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
#line 658 "sql.yacc"
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
#line 665 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 676 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 679 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 684 "sql.yacc"
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
#line 691 "sql.yacc"
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
#line 708 "sql.yacc"
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
#line 725 "sql.yacc"
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
#line 746 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 755 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 758 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 766 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 769 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 777 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 778 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 785 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 788 "sql.yacc"
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
#line 796 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 799 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 803 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 809 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 810 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 814 "sql.yacc"
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
#line 824 "sql.yacc"
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
#line 838 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 839 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 844 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 849 "sql.yacc"
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
#line 857 "sql.yacc"
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
#line 865 "sql.yacc"
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
#line 873 "sql.yacc"
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
#line 881 "sql.yacc"
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
#line 893 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 893 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 897 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 901 "sql.yacc"
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
#line 908 "sql.yacc"
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
#line 915 "sql.yacc"
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
#line 922 "sql.yacc"
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
#line 931 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 935 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 942 "sql.yacc"
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
#line 954 "sql.yacc"
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
#line 965 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 971 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 975 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 979 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 984 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 988 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 991 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 995 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 998 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 1005 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 1006 "sql.yacc"
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
#line 1016 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1017 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1022 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1026 "sql.yacc"
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
#line 1035 "sql.yacc"
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
#line 1044 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1051 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 1054 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 1060 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1063 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1074 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 1078 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1083 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1090 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1093 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1102 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1105 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1109 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1113 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1117 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1121 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1125 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1133 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1137 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1145 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1148 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1155 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1158 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1165 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1168 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1176 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1185 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1188 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1194 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1197 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1203 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1210 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1211 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1215 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1223 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1227 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1234 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1236 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1241 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1242 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1247 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1248 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1254 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1255 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1269 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1275 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1275 "sql.yacc"
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
#line 1284 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1284 "sql.yacc"
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
#line 1293 "sql.yacc"
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
#line 1318 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1321 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1329 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1332 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1339 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1342 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1350 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1351 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1357 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1358 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1366 "sql.yacc"
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

/* Line 1464 of yacc.c  */
#line 1384 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1388 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1393 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1394 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1404 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1413 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1417 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1422 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1426 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1430 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1434 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1437 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1444 "sql.yacc"
    { (yyval.integer_val)=1; 
#ifndef  SQLCOMPILER
				set_cmdlineno(token_read_on_line);
#endif

}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1450 "sql.yacc"
    { (yyval.integer_val)=-1; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1455 "sql.yacc"
    { (yyval.integer_val)=0; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1463 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1464 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1465 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1466 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1467 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1468 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1469 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1477 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1478 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1479 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1480 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1490 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1491 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1492 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1496 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1497 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1504 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1507 "sql.yacc"
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
#line 1516 "sql.yacc"
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
#line 1527 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1529 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1535 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1541 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1551 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1558 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1560 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1566 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1569 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1570 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1577 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1586 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1593 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1605 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1611 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1616 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1620 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1626 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1634 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1639 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1642 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1645 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1652 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1653 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1654 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1655 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1661 "sql.yacc"
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
#line 1684 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1688 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1690 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1697 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1700 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1706 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1714 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1719 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1725 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1730 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1736 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1739 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1744 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1753 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1762 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1771 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1777 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1780 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1791 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1800 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1807 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1813 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1814 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1817 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1822 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1833 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1837 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1845 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1849 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1853 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1857 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1864 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1869 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1877 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1880 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1886 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1889 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1894 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1899 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1912 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1915 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1921 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1924 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1930 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1933 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1939 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1942 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1949 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1953 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1964 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1964 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1965 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1965 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1966 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1966 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1969 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1979 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1980 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1985 "sql.yacc"
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
#line 1994 "sql.yacc"
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
#line 2002 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 2005 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 2008 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 2012 "sql.yacc"
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
#line 2019 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 2022 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 2026 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 2029 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 2032 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 2035 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 2041 "sql.yacc"
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
#line 2048 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 2051 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 2054 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 2057 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 2058 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 2063 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 2066 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 2069 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 2072 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 2079 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 2080 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 2081 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 2085 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2092 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 2093 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 2094 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 2098 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 2112 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2127 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2131 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2132 "sql.yacc"
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
#line 2141 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2143 "sql.yacc"
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
#line 2152 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2155 "sql.yacc"
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
#line 2163 "sql.yacc"
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
#line 2173 "sql.yacc"
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
#line 2181 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 2183 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 2184 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 2185 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 2186 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2187 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2188 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 2189 "sql.yacc"
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
#line 2197 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 2198 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2199 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2200 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2201 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2202 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2203 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2204 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2205 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2206 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2207 "sql.yacc"
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
#line 2217 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2218 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2225 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 2229 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 2254 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 2255 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 2259 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 2267 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 2270 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 2277 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 2280 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 2290 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 2293 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 2296 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 2299 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 2306 "sql.yacc"
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
#line 2313 "sql.yacc"
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
#line 2321 "sql.yacc"
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
#line 2330 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 2341 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2353 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2354 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 2364 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 2409 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2410 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2411 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2416 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2417 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 2425 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2432 "sql.yacc"
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
#line 2443 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2444 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2457 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2458 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2462 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2466 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2467 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2470 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2476 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2480 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2503 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2513 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2516 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2522 "sql.yacc"
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
#line 2531 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2535 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2542 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2544 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2546 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2550 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2556 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2559 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2565 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2566 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2573 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2586 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2596 "sql.yacc"
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
#line 2603 "sql.yacc"
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
#line 2620 "sql.yacc"
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
#line 2627 "sql.yacc"
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
#line 2652 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2654 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2656 "sql.yacc"
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
#line 2677 "sql.yacc"
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
#line 2720 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2721 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2735 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2738 "sql.yacc"
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
#line 2745 "sql.yacc"
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
#line 2755 "sql.yacc"
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
#line 2773 "sql.yacc"
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
#line 2786 "sql.yacc"
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
#line 2801 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2803 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2809 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2810 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2811 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2812 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2822 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item_list));
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2829 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2832 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2838 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2841 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2846 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2855 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2858 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2862 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2869 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2872 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2875 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2878 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2881 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2884 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2887 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2888 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2889 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2890 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2891 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2892 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2893 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2894 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2895 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2897 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2901 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2905 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2909 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2913 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2917 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2921 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2925 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2928 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2931 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2934 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2937 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2940 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2943 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2946 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2949 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2953 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2957 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2961 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2964 "sql.yacc"
    {
		(yyvsp[(3) - (4)].s_select_list_item)->data.s_select_list_item_data_u.sqlcase.master_condition=(yyvsp[(2) - (4)].s_select_list_item);
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2973 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 2976 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 2985 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 2991 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 2998 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 3001 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 3025 "sql.yacc"
    {(yyval.str_list)=NULL;}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 3026 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(2) - (4)].str));  add_str_list((yyval.str_list),(yyvsp[(4) - (4)].str));}
    break;

  case 506:

/* Line 1464 of yacc.c  */
#line 3027 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(1) - (3)].str));  add_str_list((yyval.str_list),(yyvsp[(3) - (3)].str));}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 3031 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 3034 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 3040 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 3041 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 3042 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 3043 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 3044 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 3045 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 3050 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 3054 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 3058 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 3062 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 3069 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 3072 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 3077 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 3078 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 3079 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3081 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3087 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3097 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3101 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3105 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3109 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3113 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3117 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3121 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3125 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3133 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3143 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3148 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3152 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3156 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3160 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3164 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3169 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3173 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3177 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3185 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3188 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3193 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3194 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3195 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 550:

/* Line 1464 of yacc.c  */
#line 3200 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3201 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 552:

/* Line 1464 of yacc.c  */
#line 3202 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 554:

/* Line 1464 of yacc.c  */
#line 3213 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 556:

/* Line 1464 of yacc.c  */
#line 3219 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 558:

/* Line 1464 of yacc.c  */
#line 3224 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 559:

/* Line 1464 of yacc.c  */
#line 3229 "sql.yacc"
    {(yyval.ptr_list)=0;}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3276 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3283 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 565:

/* Line 1464 of yacc.c  */
#line 3289 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3304 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1464 of yacc.c  */
#line 3305 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3307 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3309 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3312 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 574:

/* Line 1464 of yacc.c  */
#line 3316 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3325 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3331 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3332 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 579:

/* Line 1464 of yacc.c  */
#line 3335 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 3340 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 581:

/* Line 1464 of yacc.c  */
#line 3341 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3345 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3346 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3356 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3357 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3358 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3359 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3360 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3361 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3362 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3363 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3367 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3373 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3375 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3394 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3402 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3409 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3410 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3411 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3412 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3417 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3418 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3419 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3420 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3421 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 3426 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 3427 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 3443 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 3444 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 3445 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 3446 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 3447 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 3448 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 3449 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 3450 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3451 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3452 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 3454 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 3455 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 3456 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3457 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3462 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3465 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 3474 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3475 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3476 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 3477 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 3478 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 3479 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3483 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 632:

/* Line 1464 of yacc.c  */
#line 3484 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1464 of yacc.c  */
#line 8967 "y.tab.c"
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
#line 3498 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

