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
     INT_VALUE = 2249,
     NAMED = 2250,
     NAMED_GEN = 2251,
     CHAR_VALUE = 2252,
     NOT_USED_1 = 2253,
     NOT_USED_2 = 2254,
     NOT_USED_3 = 2255,
     NOT_USED_4 = 2256,
     NOT_USED_5 = 2257,
     NOT_USED_6 = 2258,
     NOT_USED_7 = 2259,
     NOT_USED_8 = 2260,
     NUMBER_VALUE = 2261,
     SEMICOLON = 2262,
     QUESTION_MARK = 2263,
     CLINE = 2264,
     CH = 2265,
     MARK_VAR = 2266,
     END_MARK_VAR = 2267,
     WITH_LISTING_IN = 1001,
     BACKQUOTE = 1002,
     SET_POSTGRESQL_SEARCH_PATH = 1003,
     SET_CONSTRAINTS_ALL_DEFERRED = 1004,
     KW_LIMIT = 1005,
     DOCUMENT = 1006,
     ON_EXCEPTION = 1008,
     SET_DEBUG_FILE_TO = 1009,
     CREATE_DBA_PROCEDURE = 1014,
     CREATE_FUNCTION = 1015,
     CREATE_DBA_FUNCTION = 1016,
     USE_SESSION = 1018,
     KW_RUN_CLIENT = 1019,
     LEFT_JOIN = 1021,
     IGNORE_ERRORS = 1024,
     SQLERRMESSAGE = 1025,
     DISPLAY_NULL_TO = 1026,
     UNBUFFERED = 1027,
     KW_PICTURE = 1028,
     ON_CHANGE = 1029,
     INNER_JOIN = 1030,
     UI_INTERFACE_DOT_FRONTCALL = 1033,
     UICOMBOBOX = 1037,
     UIBROWSER = 1038,
     UIPROGRESS = 1039,
     UIGANTT = 1040,
     UIFORM = 1043,
     USING_BTREE = 1059,
     USING_RTREE = 1060,
     SET_BUFFERED_LOG = 1079,
     SET_LOG = 1082,
     MDY = 1084,
     WEEKDAY = 1085,
     MODE_ANSI = 1088,
     START_DATABASE = 1089,
     WITH_LOG_IN = 1090,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1091,
     DATETIME_VALUE = 1104,
     INTERVAL_VALUE = 1105,
     RECOVER_TABLE = 1106,
     ROLLFORWARD_DATABASE = 1107,
     CONCAT_PIPES = 1121,
     DROP_TRIGGER = 1123,
     DROP_AUDIT_FOR = 1124,
     CREATE_AUDIT_FOR = 1125,
     EXECUTE_PROCEDURE = 1129,
     ALTER_TABLE = 1136,
     ALTER_INDEX = 1137,
     NEXT_SIZE = 1138,
     KW_WHENEVER_SIGNAL = 1175,
     KW_SIGNAL_TOKEN = 1176,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1177,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1178,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1179,
     XSET_MULTIPLY_EQUAL = 1180,
     XSET_OPEN_BRACKET = 1181,
     CREATE_DATABASE = 1184,
     DROP_DATABASE = 1185,
     ADD_CONSTRAINT = 1187,
     DROP_CONSTRAINT = 1188,
     DROP_SYNONYM = 1189,
     CONSTRAINT = 1190,
     NOT_FIELD_TOUCHED_CURRENT = 1193,
     FIELD_TOUCHED_CURRENT = 1194,
     OBJECT_FUNCTION = 1196,
     DOUBLE_PRECISION = 1202,
     COUNT_MULTIPLY = 1203,
     KW_ASCII_OPEN_BRACKET = 1212,
     MODIFY_NEXT_SIZE = 1224,
     LOCK_MODE_PAGE = 1225,
     LOCK_MODE_ROW = 1226,
     TO_UI = 1231,
     UNITS_YEAR = 1234,
     UNITS_MONTH = 1235,
     UNITS_DAY = 1236,
     UNITS_HOUR = 1237,
     UNITS_MINUTE = 1238,
     UNITS_SECOND = 1239,
     TO_CLUSTER = 1244,
     TO_NOT_CLUSTER = 1245,
     CREATE_UC_IDX = 1247,
     CREATE_U_IDX = 1248,
     CREATE_C_IDX = 1249,
     CREATE_IDX = 1250,
     DOUBLE_COLON = 1260,
     SQLSICS = 1266,
     CREATE_SCHEMA = 1267,
     SQLSIRR = 1268,
     UPDATESTATS_T = 1269,
     SQLSICR = 1270,
     SQLSIDR = 1281,
     CREATE_TEMP_TABLE = 1282,
     WITH_CHECK_OPTION = 1290,
     WITH_GRANT_OPTION = 1291,
     SQLSLMNW = 1292,
     WHERE_CURRENT_OF = 1298,
     NOT_NULL_UNIQUE = 1306,
     SQLSLMW = 1313,
     ALL_PRIVILEGES = 1315,
     CREATE_SYNONYM = 1319,
     DROP_TABLE = 1320,
     INEXCLUSIVE = 1322,
     REPORT_TO_FILE = 1323,
     REPORT_TO_UI = 1324,
     UPDATESTATS = 1329,
     CREATE_TABLE = 1355,
     DEFAULT_NULL = 1356,
     DEFAULT_TODAY = 1357,
     DEFAULT_USER = 1358,
     EXIT_TODO = 1365,
     CONTINUE_TODO = 1366,
     UNLOCK_TABLE = 1373,
     ROLLBACK_W = 1381,
     SQLSEON = 1383,
     SQLSEOFF = 1384,
     CREATE_VIEW = 1388,
     DELETE_FROM = 1389,
     EXTENT_SIZE = 1396,
     FOREIGN_KEY = 1397,
     INSERT_INTO = 1400,
     IS_NOT_NULL = 1402,
     NOT_MATCHES = 1405,
     PRIMARY_KEY = 1411,
     WITH_NO_LOG = 1418,
     INSHARE = 1421,
     BEGIN_WORK = 1427,
     DROP_INDEX = 1432,
     FOR_UPDATE_OF = 1438,
     FOR_UPDATE = 1439,
     LOCK_TABLE = 1444,
     NOT_EXISTS = 1446,
     REFERENCES = 1448,
     RENCOL = 1449,
     SMALLFLOAT = 1451,
     COMMIT_W = 1462,
     RENTAB = 1469,
     KW_CHAR = 1472,
     NCHAR = 1473,
     NVARCHAR = 1474,
     DELIMITER = 1476,
     DROP_VIEW = 1478,
     EXCLUSIVE = 1481,
     GREATER_THAN_EQ = 1485,
     INTO_TEMP = 1487,
     DATABASE = 1511,
     DATETIME = 1512,
     DISTINCT = 1514,
     FRACTION = 1521,
     GROUP_BY = 1523,
     INTERVAL = 1524,
     NOT_LIKE = 1526,
     NOT_ILIKE = 1527,
     NOT_NULL = 1528,
     RESOURCE = 1534,
     SMALLINT = 1535,
     IS_NULL = 1541,
     LESS_THAN_EQ = 1542,
     BETWEEN = 1544,
     CLOSE_BRACKET = 1547,
     CONNECT = 1550,
     KW_CURRENT = 1551,
     KW_DECIMAL = 1553,
     KW_DEFAULT = 1555,
     FGL_SYNCFIELDS = 1563,
     INTEGER = 1564,
     SERIAL8 = 1566,
     MATCHES = 1569,
     VARCHAR = 1582,
     CLOSE_SQUARE = 1585,
     GREATER_THAN = 1586,
     KW_FALSE = 1587,
     NOT_IN = 1588,
     OPEN_BRACKET_SELECT = 1590,
     OPEN_BRACKET = 1591,
     KW_DELETE = 1599,
     KW_ESCAPE = 1602,
     EXISTS = 1603,
     EXTEND = 1604,
     HAVING = 1608,
     KW_INSERT = 1610,
     MINUTE = 1614,
     MODIFY = 1615,
     EQUAL = 1617,
     NOT_EQUAL = 1618,
     OPEN_SQUARE = 1620,
     PUBLIC = 1624,
     KW_RETURN_KEY = 1627,
     REVOKE = 1629,
     SECOND = 1633,
     KW_SELECT = 1637,
     SERIAL = 1638,
     UNIQUE = 1641,
     KW_UPDATE = 1643,
     VALUES = 1644,
     KW_NULL = 1647,
     KW_TRUE = 1648,
     ALTER = 1650,
     CHECK = 1656,
     COUNT = 1660,
     KW_FIRST = 1665,
     KW_FLOAT = 1666,
     GRANT = 1669,
     INDEX = 1672,
     LESS_THAN = 1675,
     MONEY = 1677,
     MONTH = 1678,
     KW_MULTIPLY = 1680,
     ORDER = 1681,
     OUTER = 1682,
     UNION = 1691,
     WHERE = 1694,
     KW_BYTE = 1701,
     CASE = 1703,
     KW_DATE = 1705,
     DESC = 1706,
     KW_DIVIDE = 1707,
     DROP = 1710,
     ELSE = 1711,
     FROM = 1715,
     HOUR = 1721,
     INTO = 1722,
     LIKE = 1725,
     REAL = 1734,
     SOME = 1739,
     KW_TEXT = 1743,
     KW_THEN = 1744,
     USER = 1745,
     WHEN = 1747,
     YEAR = 1750,
     KW_DOW = 1751,
     XSET = 1753,
     ADD = 1754,
     ALL = 1755,
     KW_AND = 1756,
     ANY = 1757,
     ASC = 1758,
     AVG = 1759,
     COLON = 1760,
     KW_COMMA = 1761,
     DAY = 1762,
     DBA = 1763,
     KW_FOR = 1767,
     XMAX = 1772,
     XMIN = 1773,
     KW_MINUS = 1774,
     KW_MOD = 1775,
     KW_NOT = 1776,
     KW_SUM = 1783,
     ATSIGN = 1786,
     KW_PLUS = 1787,
     KW_AS = 1793,
     KW_BY = 1795,
     KW_DOT = 1796,
     KW_IN = 1799,
     KW_ON = 1801,
     KW_OR = 1802,
     KW_TO = 1803,
     BEFORE = 1841,
     END = 1845,
     TILDE = 1852,
     ILIKE = 1853,
     FILLFACTOR = 1856,
     TIME = 1861,
     KW_TODAY = 1868,
     KW_ROWID = 1869,
     TIMESTAMP = 2217,
     KWPIPE = 2247
   };
#endif
/* Tokens.  */
#define INT_VALUE 2249
#define NAMED 2250
#define NAMED_GEN 2251
#define CHAR_VALUE 2252
#define NOT_USED_1 2253
#define NOT_USED_2 2254
#define NOT_USED_3 2255
#define NOT_USED_4 2256
#define NOT_USED_5 2257
#define NOT_USED_6 2258
#define NOT_USED_7 2259
#define NOT_USED_8 2260
#define NUMBER_VALUE 2261
#define SEMICOLON 2262
#define QUESTION_MARK 2263
#define CLINE 2264
#define CH 2265
#define MARK_VAR 2266
#define END_MARK_VAR 2267
#define WITH_LISTING_IN 1001
#define BACKQUOTE 1002
#define SET_POSTGRESQL_SEARCH_PATH 1003
#define SET_CONSTRAINTS_ALL_DEFERRED 1004
#define KW_LIMIT 1005
#define DOCUMENT 1006
#define ON_EXCEPTION 1008
#define SET_DEBUG_FILE_TO 1009
#define CREATE_DBA_PROCEDURE 1014
#define CREATE_FUNCTION 1015
#define CREATE_DBA_FUNCTION 1016
#define USE_SESSION 1018
#define KW_RUN_CLIENT 1019
#define LEFT_JOIN 1021
#define IGNORE_ERRORS 1024
#define SQLERRMESSAGE 1025
#define DISPLAY_NULL_TO 1026
#define UNBUFFERED 1027
#define KW_PICTURE 1028
#define ON_CHANGE 1029
#define INNER_JOIN 1030
#define UI_INTERFACE_DOT_FRONTCALL 1033
#define UICOMBOBOX 1037
#define UIBROWSER 1038
#define UIPROGRESS 1039
#define UIGANTT 1040
#define UIFORM 1043
#define USING_BTREE 1059
#define USING_RTREE 1060
#define SET_BUFFERED_LOG 1079
#define SET_LOG 1082
#define MDY 1084
#define WEEKDAY 1085
#define MODE_ANSI 1088
#define START_DATABASE 1089
#define WITH_LOG_IN 1090
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1091
#define DATETIME_VALUE 1104
#define INTERVAL_VALUE 1105
#define RECOVER_TABLE 1106
#define ROLLFORWARD_DATABASE 1107
#define CONCAT_PIPES 1121
#define DROP_TRIGGER 1123
#define DROP_AUDIT_FOR 1124
#define CREATE_AUDIT_FOR 1125
#define EXECUTE_PROCEDURE 1129
#define ALTER_TABLE 1136
#define ALTER_INDEX 1137
#define NEXT_SIZE 1138
#define KW_WHENEVER_SIGNAL 1175
#define KW_SIGNAL_TOKEN 1176
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1177
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1178
#define XSET_ident_DOT_MULTIPLY_EQUAL 1179
#define XSET_MULTIPLY_EQUAL 1180
#define XSET_OPEN_BRACKET 1181
#define CREATE_DATABASE 1184
#define DROP_DATABASE 1185
#define ADD_CONSTRAINT 1187
#define DROP_CONSTRAINT 1188
#define DROP_SYNONYM 1189
#define CONSTRAINT 1190
#define NOT_FIELD_TOUCHED_CURRENT 1193
#define FIELD_TOUCHED_CURRENT 1194
#define OBJECT_FUNCTION 1196
#define DOUBLE_PRECISION 1202
#define COUNT_MULTIPLY 1203
#define KW_ASCII_OPEN_BRACKET 1212
#define MODIFY_NEXT_SIZE 1224
#define LOCK_MODE_PAGE 1225
#define LOCK_MODE_ROW 1226
#define TO_UI 1231
#define UNITS_YEAR 1234
#define UNITS_MONTH 1235
#define UNITS_DAY 1236
#define UNITS_HOUR 1237
#define UNITS_MINUTE 1238
#define UNITS_SECOND 1239
#define TO_CLUSTER 1244
#define TO_NOT_CLUSTER 1245
#define CREATE_UC_IDX 1247
#define CREATE_U_IDX 1248
#define CREATE_C_IDX 1249
#define CREATE_IDX 1250
#define DOUBLE_COLON 1260
#define SQLSICS 1266
#define CREATE_SCHEMA 1267
#define SQLSIRR 1268
#define UPDATESTATS_T 1269
#define SQLSICR 1270
#define SQLSIDR 1281
#define CREATE_TEMP_TABLE 1282
#define WITH_CHECK_OPTION 1290
#define WITH_GRANT_OPTION 1291
#define SQLSLMNW 1292
#define WHERE_CURRENT_OF 1298
#define NOT_NULL_UNIQUE 1306
#define SQLSLMW 1313
#define ALL_PRIVILEGES 1315
#define CREATE_SYNONYM 1319
#define DROP_TABLE 1320
#define INEXCLUSIVE 1322
#define REPORT_TO_FILE 1323
#define REPORT_TO_UI 1324
#define UPDATESTATS 1329
#define CREATE_TABLE 1355
#define DEFAULT_NULL 1356
#define DEFAULT_TODAY 1357
#define DEFAULT_USER 1358
#define EXIT_TODO 1365
#define CONTINUE_TODO 1366
#define UNLOCK_TABLE 1373
#define ROLLBACK_W 1381
#define SQLSEON 1383
#define SQLSEOFF 1384
#define CREATE_VIEW 1388
#define DELETE_FROM 1389
#define EXTENT_SIZE 1396
#define FOREIGN_KEY 1397
#define INSERT_INTO 1400
#define IS_NOT_NULL 1402
#define NOT_MATCHES 1405
#define PRIMARY_KEY 1411
#define WITH_NO_LOG 1418
#define INSHARE 1421
#define BEGIN_WORK 1427
#define DROP_INDEX 1432
#define FOR_UPDATE_OF 1438
#define FOR_UPDATE 1439
#define LOCK_TABLE 1444
#define NOT_EXISTS 1446
#define REFERENCES 1448
#define RENCOL 1449
#define SMALLFLOAT 1451
#define COMMIT_W 1462
#define RENTAB 1469
#define KW_CHAR 1472
#define NCHAR 1473
#define NVARCHAR 1474
#define DELIMITER 1476
#define DROP_VIEW 1478
#define EXCLUSIVE 1481
#define GREATER_THAN_EQ 1485
#define INTO_TEMP 1487
#define DATABASE 1511
#define DATETIME 1512
#define DISTINCT 1514
#define FRACTION 1521
#define GROUP_BY 1523
#define INTERVAL 1524
#define NOT_LIKE 1526
#define NOT_ILIKE 1527
#define NOT_NULL 1528
#define RESOURCE 1534
#define SMALLINT 1535
#define IS_NULL 1541
#define LESS_THAN_EQ 1542
#define BETWEEN 1544
#define CLOSE_BRACKET 1547
#define CONNECT 1550
#define KW_CURRENT 1551
#define KW_DECIMAL 1553
#define KW_DEFAULT 1555
#define FGL_SYNCFIELDS 1563
#define INTEGER 1564
#define SERIAL8 1566
#define MATCHES 1569
#define VARCHAR 1582
#define CLOSE_SQUARE 1585
#define GREATER_THAN 1586
#define KW_FALSE 1587
#define NOT_IN 1588
#define OPEN_BRACKET_SELECT 1590
#define OPEN_BRACKET 1591
#define KW_DELETE 1599
#define KW_ESCAPE 1602
#define EXISTS 1603
#define EXTEND 1604
#define HAVING 1608
#define KW_INSERT 1610
#define MINUTE 1614
#define MODIFY 1615
#define EQUAL 1617
#define NOT_EQUAL 1618
#define OPEN_SQUARE 1620
#define PUBLIC 1624
#define KW_RETURN_KEY 1627
#define REVOKE 1629
#define SECOND 1633
#define KW_SELECT 1637
#define SERIAL 1638
#define UNIQUE 1641
#define KW_UPDATE 1643
#define VALUES 1644
#define KW_NULL 1647
#define KW_TRUE 1648
#define ALTER 1650
#define CHECK 1656
#define COUNT 1660
#define KW_FIRST 1665
#define KW_FLOAT 1666
#define GRANT 1669
#define INDEX 1672
#define LESS_THAN 1675
#define MONEY 1677
#define MONTH 1678
#define KW_MULTIPLY 1680
#define ORDER 1681
#define OUTER 1682
#define UNION 1691
#define WHERE 1694
#define KW_BYTE 1701
#define CASE 1703
#define KW_DATE 1705
#define DESC 1706
#define KW_DIVIDE 1707
#define DROP 1710
#define ELSE 1711
#define FROM 1715
#define HOUR 1721
#define INTO 1722
#define LIKE 1725
#define REAL 1734
#define SOME 1739
#define KW_TEXT 1743
#define KW_THEN 1744
#define USER 1745
#define WHEN 1747
#define YEAR 1750
#define KW_DOW 1751
#define XSET 1753
#define ADD 1754
#define ALL 1755
#define KW_AND 1756
#define ANY 1757
#define ASC 1758
#define AVG 1759
#define COLON 1760
#define KW_COMMA 1761
#define DAY 1762
#define DBA 1763
#define KW_FOR 1767
#define XMAX 1772
#define XMIN 1773
#define KW_MINUS 1774
#define KW_MOD 1775
#define KW_NOT 1776
#define KW_SUM 1783
#define ATSIGN 1786
#define KW_PLUS 1787
#define KW_AS 1793
#define KW_BY 1795
#define KW_DOT 1796
#define KW_IN 1799
#define KW_ON 1801
#define KW_OR 1802
#define KW_TO 1803
#define BEFORE 1841
#define END 1845
#define TILDE 1852
#define ILIKE 1853
#define FILLFACTOR 1856
#define TIME 1861
#define KW_TODAY 1868
#define KW_ROWID 1869
#define TIMESTAMP 2217
#define KWPIPE 2247




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
#line 860 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 872 "y.tab.c"

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
#define YYLAST   2279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  289
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  632
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1113

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2267

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
       2,    22,    23,    24,    25,    26,    27,     2,    28,    29,
       2,     2,     2,     2,    30,    31,    32,     2,    33,    34,
       2,    35,     2,     2,    36,    37,    38,    39,    40,    41,
      42,     2,     2,    43,     2,     2,     2,    44,    45,    46,
      47,     2,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
      50,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,     2,    52,     2,    53,    54,     2,     2,    55,    56,
      57,    58,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    59,    60,    61,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    65,    66,     2,     2,     2,    67,
       2,     2,     2,     2,     2,     2,    68,    69,    70,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    71,    72,    73,    74,    75,
      76,    77,     2,     2,    78,    79,     2,    80,    81,    82,
      83,     2,     2,    84,    85,     2,    86,     2,     2,     2,
       2,     2,    87,    88,     2,     2,     2,     2,     2,     2,
       2,     2,    89,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    90,    91,    92,     2,     2,     2,
       2,    93,     2,     2,    94,    95,    96,    97,    98,    99,
       2,     2,     2,     2,   100,   101,     2,   102,   103,   104,
     105,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     106,     2,     2,     2,     2,     2,   107,   108,   109,   110,
     111,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   112,   113,     2,     2,     2,     2,     2,     2,     2,
     114,   115,   116,     2,     2,     2,     2,     2,   117,     2,
       2,     2,     2,     2,     2,     2,   118,     2,     2,     2,
       2,     2,     2,   119,     2,   120,     2,     2,     2,   121,
     122,     2,   123,   124,   125,     2,     2,     2,     2,   126,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   127,   128,   129,   130,     2,
       2,     2,     2,     2,     2,   131,   132,     2,     2,     2,
       2,     2,     2,   133,     2,     2,     2,     2,     2,     2,
       2,   134,     2,   135,   136,     2,     2,     2,   137,   138,
       2,     2,     2,     2,     2,     2,   139,   140,     2,     2,
     141,     2,   142,     2,     2,   143,     2,     2,     2,     2,
       2,   144,     2,     2,     2,     2,     2,     2,   145,     2,
       2,   146,     2,     2,     2,     2,     2,   147,     2,     2,
       2,     2,   148,     2,     2,     2,     2,     2,   149,   150,
       2,     2,     2,     2,   151,     2,   152,     2,   153,   154,
       2,   155,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   156,     2,     2,     2,     2,     2,     2,   157,
       2,     2,   158,   159,   160,     2,   161,     2,   162,     2,
       2,   163,     2,     2,     2,   164,     2,   165,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   166,   167,     2,   168,     2,     2,     2,     2,     2,
       2,   169,     2,   170,   171,     2,   172,   173,   174,     2,
       2,     2,     2,     2,   175,   176,     2,     2,     2,     2,
       2,   177,   178,     2,   179,     2,     2,   180,     2,     2,
     181,   182,     2,   183,     2,   184,     2,     2,     2,     2,
       2,     2,     2,   185,   186,     2,   187,     2,     2,   188,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   189,     2,     2,   190,   191,   192,   193,     2,
     194,   195,     2,     2,     2,     2,     2,     2,     2,   196,
       2,     2,   197,   198,   199,     2,     2,     2,   200,     2,
     201,     2,     2,     2,   202,   203,     2,   204,   205,     2,
     206,     2,     2,     2,   207,     2,     2,   208,     2,   209,
       2,     2,     2,   210,     2,     2,     2,   211,   212,     2,
       2,   213,     2,   214,   215,     2,     2,   216,   217,     2,
     218,     2,     2,     2,     2,     2,   219,     2,     2,     2,
     220,     2,     2,     2,     2,   221,   222,     2,     2,   223,
       2,     2,   224,     2,     2,   225,     2,   226,   227,     2,
     228,   229,   230,     2,     2,     2,     2,     2,     2,     2,
       2,   231,     2,     2,   232,     2,     2,     2,     2,     2,
       2,   233,     2,   234,     2,   235,   236,   237,     2,     2,
     238,   239,     2,     2,     2,   240,     2,     2,     2,     2,
       2,   241,   242,     2,     2,   243,     2,     2,     2,     2,
       2,     2,     2,     2,   244,     2,     2,     2,     2,   245,
       2,     2,     2,   246,   247,   248,     2,   249,     2,     2,
     250,   251,     2,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,     2,     2,     2,   263,     2,     2,
       2,     2,   264,   265,   266,   267,   268,     2,     2,     2,
       2,     2,     2,   269,     2,     2,   270,   271,     2,     2,
       2,     2,     2,   272,     2,   273,   274,     2,     2,   275,
       2,   276,   277,   278,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   279,     2,     2,     2,   280,     2,     2,     2,     2,
       2,     2,   281,   282,     2,     2,   283,     2,     2,     2,
       2,   284,     2,     2,     2,     2,     2,     2,   285,   286,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   287,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   288,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21
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
     497,     0,    -1,   214,   488,   293,   291,    -1,    -1,   117,
     492,    -1,   232,   402,    -1,    -1,   117,   492,    -1,   232,
     402,    -1,    77,   298,   180,   204,   195,   299,   180,    -1,
      73,   299,   180,    -1,    74,   299,   180,    -1,   252,   294,
      -1,    76,   299,    -1,    75,   299,    -1,   297,    -1,   294,
     260,   297,    -1,   296,    -1,   270,   296,    -1,   491,   428,
      -1,   491,   274,   491,   428,    -1,   491,   274,   491,   274,
     491,   428,    -1,   491,   274,   228,    -1,   295,   204,   300,
      -1,   295,    -1,   298,   260,   295,    -1,   300,    -1,   299,
     260,   300,    -1,   475,    -1,   216,    -1,   302,    -1,   122,
     488,    -1,   162,   488,    -1,   148,   490,    -1,    64,   491,
      -1,   313,    -1,   304,    -1,   127,   488,   195,   318,   180,
     305,    -1,   113,   488,   195,   318,   180,   314,   305,   314,
      -1,    -1,   306,    -1,   307,    -1,   306,   307,    -1,   275,
     308,    -1,   139,     3,    -1,    70,     3,    -1,    91,    -1,
      92,    -1,     4,    -1,    -1,   310,    -1,   311,    -1,   310,
     311,    -1,   275,   308,    -1,   283,     3,    -1,    49,    -1,
      50,    -1,   488,    -1,   103,   490,   276,   312,   195,   316,
     180,   309,    -1,   102,   490,   276,   312,   195,   316,   180,
     309,    -1,   104,   490,   276,   312,   195,   316,   180,   309,
      -1,   105,   490,   276,   312,   195,   316,   180,   309,    -1,
      78,   501,    -1,    79,   501,    -1,   121,   488,   263,   488,
      -1,    66,   488,   275,     6,    -1,    65,   488,    -1,    82,
     488,    -1,    61,   488,    -1,    62,   491,    -1,    -1,   145,
      -1,    -1,   145,    -1,   317,    -1,   316,   260,   317,    -1,
     491,   257,    -1,   491,   236,    -1,   491,    -1,   319,    -1,
     318,   260,   319,    -1,   382,    -1,   380,    -1,    68,   491,
     321,    -1,    69,   490,   100,    -1,    69,   490,   101,    -1,
     322,    -1,   321,   260,   322,    -1,   323,    -1,   326,    -1,
     329,    -1,   334,    -1,   337,    -1,   333,    -1,   332,    -1,
     253,   324,    -1,   253,   195,   325,   180,    -1,   319,    -1,
     319,   279,   491,    -1,   324,    -1,   325,   260,   324,    -1,
     238,   328,    -1,   238,   195,   327,   180,    -1,   328,    -1,
     327,   260,   328,    -1,   491,    -1,   203,   331,    -1,   203,
     195,   330,   180,    -1,   331,    -1,   330,   260,   331,    -1,
     319,    -1,    91,    -1,    92,    -1,    90,     3,    -1,    80,
     380,   336,    -1,    80,   195,   335,   180,    -1,   380,   336,
      -1,   335,   260,   380,   336,    -1,    -1,    83,   491,    -1,
      81,   338,    -1,    81,   195,   338,   180,    -1,   339,    -1,
     338,   260,   339,    -1,   491,    -1,   134,    -1,    -1,   141,
     342,   488,   345,   343,    -1,    -1,   215,   344,   195,   348,
     180,    -1,   468,    -1,    -1,   195,   346,   180,    -1,   347,
      -1,   346,   260,   347,    -1,   491,    -1,   491,   274,   491,
      -1,   349,    -1,   348,   260,   349,    -1,   475,    -1,   216,
      -1,   138,   488,   292,    -1,   147,    -1,   156,    -1,    -1,
     163,    -1,   355,    -1,    56,   491,    57,     6,    55,    -1,
      56,   491,    57,     6,    -1,    58,    -1,    51,    -1,    52,
      -1,   110,   491,    -1,   126,    -1,   352,    -1,   351,    -1,
     340,    -1,   354,    -1,   388,    -1,   392,    -1,   438,    -1,
     301,    -1,   303,    -1,   320,    -1,   223,   361,   276,   488,
     278,   366,   360,    -1,   209,   361,   276,   488,   240,   366,
      -1,   223,   359,   278,   366,    -1,   209,   359,   240,   366,
      -1,   181,    -1,   175,    -1,   262,    -1,    -1,   115,    -1,
     272,   427,    -1,   120,    -1,   254,    -1,   362,    -1,   363,
      -1,   362,   260,   363,    -1,   211,   364,    -1,   201,    -1,
     196,    -1,   214,   364,    -1,   218,    -1,   224,    -1,    -1,
     195,   365,   180,    -1,   429,    -1,   365,   260,   429,    -1,
     367,    -1,   366,   260,   367,    -1,   207,    -1,   427,    -1,
     137,   488,   369,   272,   459,   371,    -1,    -1,   195,   370,
     180,    -1,   429,    -1,   370,   260,   429,    -1,    -1,   114,
      -1,   219,   195,   458,   180,    -1,   140,   195,   375,   180,
     374,    -1,   153,   376,    -1,   377,    -1,   488,    -1,   488,
     195,   377,   180,    -1,   429,    -1,   377,   260,   429,    -1,
     213,   195,   379,   180,    -1,   168,   195,   379,   180,    -1,
     144,   195,   379,   180,    -1,   429,    -1,   379,   260,   429,
      -1,   378,    -1,   373,    -1,   372,    -1,   184,   434,    -1,
     130,    -1,   129,    -1,   128,    -1,   491,   418,   383,   384,
      -1,    -1,   381,    -1,    -1,   385,    -1,   386,    -1,   385,
     386,    -1,   387,   336,    -1,   174,    -1,   118,    -1,   213,
      -1,   168,    -1,   374,    -1,   219,   195,   458,   180,    -1,
     144,    -1,   108,   389,   391,    -1,   390,    -1,   427,    -1,
     392,    -1,   391,   392,    -1,   368,    -1,   358,    -1,   200,
     402,    -1,   232,   402,    -1,   240,   396,    -1,   398,    -1,
     396,   260,   398,    -1,   396,   260,   230,   398,    -1,   396,
     260,   230,   195,   396,   180,    -1,   396,    35,   397,   276,
     402,    -1,   396,    42,   397,   276,   402,    -1,   396,    -1,
     195,   396,   180,    -1,   488,    -1,   488,   433,    -1,   488,
     272,   433,    -1,    -1,   395,   400,    -1,   401,    -1,   394,
     401,    -1,    -1,   455,    -1,   455,   393,    -1,   393,    -1,
     403,    -1,   402,   277,   403,    -1,   404,    -1,   403,   255,
     404,    -1,   405,    -1,   268,   405,    -1,   415,    -1,   195,
     402,   180,    -1,   198,   469,    -1,   152,   469,    -1,    -1,
     197,   411,    -1,    -1,   197,   411,    -1,    -1,   197,   411,
      -1,   514,    -1,   434,    -1,    -1,   268,    -1,   475,   412,
     177,    -1,   475,   412,   142,    -1,   475,   414,   475,    -1,
     475,   204,   475,    -1,   475,   204,   216,    -1,   475,   412,
     179,   475,   255,   475,    -1,   475,   243,   410,   409,    -1,
     475,   172,   410,   409,    -1,   475,   282,   410,   408,    -1,
     475,   173,   410,   408,    -1,   475,   188,   410,   407,    -1,
     475,   143,   410,   407,    -1,   205,    -1,   225,    -1,   191,
      -1,   281,    -1,   178,    -1,   164,    -1,   413,    -1,   483,
      -1,   406,    -1,   475,    -1,    -1,   254,    -1,   168,    -1,
     213,    -1,    -1,   254,    -1,   168,    -1,   213,    -1,   419,
      -1,   420,    -1,   421,    -1,   423,    -1,   158,    -1,   158,
     195,   424,   180,    -1,   212,    -1,   212,   195,     3,   180,
      -1,   187,    -1,   187,   195,     3,   180,    -1,   183,    -1,
     183,   195,   425,   422,   180,    -1,   226,   195,   425,   422,
     180,    -1,   226,    -1,   235,    -1,   186,    -1,   176,    -1,
     159,    -1,   159,   195,   424,   180,    -1,   160,    -1,   160,
     195,     3,   180,    -1,   160,   195,     3,   260,     3,   180,
      -1,   167,   436,   278,   437,    -1,   167,    -1,   171,   436,
     278,   437,    -1,   460,    -1,   171,    -1,   171,   436,   195,
       3,   180,   278,   437,    -1,   246,    -1,   233,    -1,   189,
      -1,   189,   195,     3,   180,    -1,   189,   195,     3,   260,
       3,   180,    -1,    -1,   260,   426,    -1,   222,   195,   425,
     180,    -1,   244,    -1,   155,    -1,   222,    -1,    87,    -1,
       3,    -1,     3,    -1,     3,    -1,   491,    -1,     6,    -1,
      -1,   206,     3,   190,    -1,   206,     3,   260,     3,   190,
      -1,   432,    -1,   270,   432,    -1,   431,    -1,   270,   431,
      -1,   491,   428,    -1,   486,   274,   491,   428,    -1,   486,
     274,   228,    -1,   286,    -1,   491,   428,    -1,   486,   274,
     491,   428,    -1,   491,   274,   491,   274,   491,   428,    -1,
     486,   274,   228,    -1,   491,    -1,     6,    -1,   493,    -1,
       3,    -1,   449,    -1,    -1,   436,   278,   437,    -1,   250,
      -1,   227,    -1,   261,    -1,   241,    -1,   202,    -1,   210,
      -1,   169,    -1,   250,    -1,   227,    -1,   261,    -1,   241,
      -1,   202,    -1,   210,    -1,   169,    -1,   169,   195,     3,
     180,    -1,   443,    -1,   442,    -1,   439,    -1,   157,   440,
     278,   440,    -1,   154,   486,   274,   441,   278,   441,    -1,
     491,    -1,   491,    -1,   133,   488,    -1,   151,   488,   444,
      -1,   146,    -1,   123,    -1,   446,    -1,   446,   436,   278,
     437,    -1,    59,    -1,   448,    -1,   448,   436,   195,     3,
     180,   278,   437,    -1,   448,   436,   278,   437,    -1,    60,
      -1,   182,   435,    -1,   229,   273,   451,    -1,   452,    -1,
     451,   260,   452,    -1,   453,   454,    -1,     3,    -1,   430,
      -1,    -1,   257,    -1,   236,    -1,   170,   456,    -1,   457,
      -1,   456,   260,   457,    -1,   430,    -1,     3,    -1,   402,
      -1,   468,    -1,   284,    -1,   284,   195,     3,   180,    -1,
     287,    -1,   287,   195,     3,   180,    -1,    -1,    -1,   211,
     470,   471,   462,   472,   463,   495,   399,   465,   466,    -1,
     211,   470,   471,   472,   399,   465,    -1,    -1,   231,   417,
     464,    -1,    -1,   450,    -1,   450,   165,   467,   315,    -1,
     165,   467,   315,    -1,   491,    -1,   211,   470,   471,   472,
     399,    -1,   194,   470,   471,   472,   399,   180,    -1,    -1,
     221,     3,    -1,    -1,   254,    -1,   168,    -1,   213,    -1,
     473,    -1,   474,    -1,   472,   260,   474,    -1,   475,    -1,
     475,   491,    -1,   475,   272,   491,    -1,   514,    -1,   266,
     514,    -1,   271,   514,    -1,   514,   237,   475,    -1,   514,
     482,    -1,   514,   228,   475,    -1,   514,   271,   475,    -1,
     514,   266,   475,    -1,   514,    63,   475,    -1,   434,    -1,
     217,    -1,   192,    -1,   248,    -1,   285,    -1,   286,    -1,
     284,    -1,   228,    -1,    88,    -1,   258,   195,   416,   475,
     180,    -1,   264,   195,   416,   475,   180,    -1,   265,   195,
     416,   475,   180,    -1,   269,   195,   416,   475,   180,    -1,
     220,   195,   416,   475,   180,    -1,     4,   195,   180,    -1,
       4,   195,   479,   180,    -1,   250,   195,   479,   180,    -1,
     227,   195,   479,   180,    -1,   261,   195,   479,   180,    -1,
      53,   195,   479,   180,    -1,    54,   195,   479,   180,    -1,
     251,   195,   479,   180,    -1,   235,   195,   479,   180,    -1,
     195,   475,   180,    -1,   199,   195,   481,   180,    -1,   445,
      -1,   447,    -1,   234,   477,   280,    -1,   234,   402,   477,
     280,    -1,   478,    -1,   477,   478,    -1,   249,   402,   247,
     475,    -1,   239,   475,    -1,   475,    -1,   479,   260,   475,
      -1,    -1,   260,   436,   278,   437,    -1,   436,   278,   437,
      -1,    -1,   507,   480,    -1,   475,   480,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,    98,    -1,    99,    -1,
     475,   275,   195,   484,   180,    -1,   475,   275,   469,    -1,
     475,   193,   195,   484,   180,    -1,   475,   193,   469,    -1,
     485,    -1,   484,   260,   485,    -1,   507,    -1,   434,    -1,
     266,     3,    -1,   266,   493,    -1,   487,    -1,     6,    -1,
       6,   274,   491,    -1,   491,    -1,   491,   259,   491,    -1,
     491,   259,     6,   274,   491,    -1,   491,   270,   491,    -1,
     491,   270,   491,   259,   491,    -1,   491,   270,   491,   259,
       6,   274,   491,    -1,   489,    -1,     6,   274,   491,    -1,
     491,   274,   491,    -1,     6,    -1,   491,    -1,   491,   259,
     491,    -1,   491,   259,     6,   274,   491,    -1,   491,   270,
     491,    -1,   491,   270,   491,   259,   491,    -1,   491,   270,
     491,   259,     6,   274,   491,    -1,     6,   274,   491,    -1,
       6,    -1,   491,    -1,   491,   259,   491,    -1,   491,   259,
       6,   274,   491,    -1,   491,   270,   491,    -1,   491,   270,
     491,   259,   491,    -1,   491,   270,   491,   259,     6,   274,
     491,    -1,     4,    -1,     4,    -1,    15,    -1,   274,     3,
      -1,     4,    -1,     6,    -1,    -1,   491,    -1,   499,    -1,
     497,    16,   499,    -1,   341,    -1,   290,    -1,   350,    -1,
      -1,   508,    -1,   357,    -1,   500,    -1,   506,    -1,   498,
      -1,   356,    -1,     1,    -1,   502,   503,    -1,   496,    -1,
     461,    -1,    -1,   150,    -1,   149,   504,    -1,   505,    -1,
     504,   260,   505,    -1,   491,    -1,   491,   274,   491,    -1,
       6,   274,   491,   274,   491,    -1,   136,    -1,   135,    -1,
     119,   516,    -1,   116,    -1,   112,    -1,   109,    -1,   107,
      -1,   111,    -1,   513,    -1,    17,    -1,   509,    -1,   166,
     494,   353,    -1,    20,     6,    21,    -1,   195,   510,   180,
      -1,   510,   511,   510,    -1,     3,    -1,   512,     3,    -1,
     271,    -1,   266,    -1,   228,    -1,   237,    -1,   267,    -1,
     271,    -1,   266,    -1,   491,    -1,   491,   274,   228,    -1,
     491,   274,   286,    -1,   491,   274,   491,    -1,   491,   274,
     491,   274,   491,    -1,     6,   274,   491,   274,   491,    -1,
     491,   206,   510,   190,    -1,   491,   274,   491,   206,   510,
     190,    -1,   491,   274,   491,   274,   491,   206,   510,   190,
      -1,     6,   274,   491,   274,   491,   206,   510,   190,    -1,
     491,   206,   510,   260,   510,   190,    -1,   491,   274,   491,
     206,   510,   260,   510,   190,    -1,   491,   274,   491,   274,
     491,   206,   510,   260,   510,   190,    -1,     6,   274,   491,
     274,   491,   206,   510,   260,   510,   190,    -1,   515,    -1,
     515,   106,   418,    -1,   476,    -1,   507,    -1,   469,    -1,
     254,   469,    -1,   256,   469,    -1,   245,   469,    -1,    -1,
       3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   463,   463,   489,   492,   509,   514,   517,   534,   540,
     549,   558,   567,   574,   589,   644,   651,   662,   665,   670,
     677,   694,   711,   732,   741,   744,   752,   755,   763,   764,
     771,   774,   782,   785,   789,   795,   796,   800,   810,   824,
     825,   829,   830,   835,   843,   851,   859,   867,   877,   879,
     879,   882,   883,   887,   894,   901,   908,   917,   921,   928,
     940,   951,   957,   961,   965,   970,   974,   977,   981,   984,
     991,   992,  1002,  1003,  1007,  1008,  1012,  1021,  1030,  1037,
    1040,  1046,  1049,  1060,  1064,  1069,  1076,  1079,  1088,  1091,
    1095,  1099,  1103,  1107,  1111,  1119,  1123,  1131,  1134,  1141,
    1144,  1151,  1154,  1161,  1162,  1167,  1171,  1174,  1180,  1183,
    1189,  1196,  1197,  1201,  1209,  1213,  1220,  1222,  1227,  1228,
    1232,  1234,  1240,  1241,  1244,  1255,  1261,  1261,  1270,  1270,
    1279,  1304,  1307,  1315,  1318,  1325,  1328,  1336,  1337,  1343,
    1344,  1352,  1370,  1374,  1379,  1380,  1390,  1399,  1403,  1407,
    1412,  1416,  1420,  1423,  1430,  1436,  1441,  1449,  1450,  1451,
    1452,  1453,  1454,  1455,  1463,  1464,  1465,  1466,  1471,  1472,
    1473,  1476,  1477,  1478,  1482,  1483,  1484,  1488,  1489,  1493,
    1500,  1501,  1502,  1509,  1510,  1513,  1514,  1519,  1520,  1525,
    1526,  1531,  1532,  1537,  1544,  1545,  1550,  1551,  1555,  1556,
    1563,  1571,  1578,  1585,  1589,  1590,  1595,  1596,  1602,  1606,
    1611,  1618,  1619,  1625,  1628,  1631,  1638,  1639,  1640,  1641,
    1647,  1670,  1671,  1674,  1676,  1683,  1686,  1692,  1700,  1705,
    1711,  1716,  1722,  1725,  1730,  1738,  1747,  1752,  1756,  1757,
    1763,  1766,  1777,  1786,  1793,  1799,  1800,  1803,  1808,  1819,
    1823,  1830,  1831,  1835,  1839,  1843,  1850,  1855,  1863,  1866,
    1872,  1875,  1880,  1885,  1898,  1901,  1907,  1910,  1916,  1919,
    1925,  1928,  1935,  1939,  1950,  1950,  1951,  1951,  1952,  1952,
    1955,  1960,  1965,  1966,  1971,  1980,  1988,  1991,  1994,  1998,
    2005,  2008,  2012,  2015,  2018,  2021,  2027,  2034,  2037,  2040,
    2043,  2044,  2049,  2052,  2055,  2058,  2065,  2066,  2067,  2071,
    2078,  2079,  2080,  2084,  2098,  2105,  2106,  2107,  2111,  2112,
    2117,  2118,  2127,  2129,  2138,  2141,  2149,  2159,  2167,  2169,
    2170,  2171,  2172,  2173,  2174,  2175,  2183,  2184,  2185,  2186,
    2187,  2188,  2189,  2190,  2191,  2192,  2193,  2203,  2204,  2210,
    2212,  2213,  2214,  2215,  2219,  2223,  2227,  2234,  2235,  2240,
    2241,  2245,  2253,  2256,  2263,  2266,  2276,  2279,  2282,  2285,
    2292,  2299,  2307,  2316,  2323,  2327,  2332,  2333,  2334,  2339,
    2340,  2349,  2349,  2349,  2349,  2349,  2349,  2349,  2350,  2350,
    2350,  2350,  2350,  2350,  2350,  2350,  2395,  2396,  2397,  2402,
    2403,  2406,  2407,  2411,  2418,  2429,  2430,  2443,  2444,  2448,
    2452,  2453,  2456,  2462,  2466,  2489,  2499,  2502,  2508,  2517,
    2521,  2528,  2529,  2531,  2536,  2542,  2545,  2551,  2552,  2559,
    2572,  2582,  2589,  2606,  2613,  2638,  2640,  2638,  2662,  2706,
    2707,  2721,  2724,  2731,  2741,  2753,  2759,  2772,  2787,  2789,
    2795,  2796,  2797,  2798,  2808,  2815,  2818,  2824,  2827,  2832,
    2841,  2844,  2848,  2855,  2858,  2861,  2864,  2867,  2870,  2873,
    2874,  2875,  2876,  2877,  2878,  2879,  2880,  2881,  2883,  2887,
    2891,  2895,  2899,  2903,  2907,  2911,  2914,  2917,  2920,  2923,
    2926,  2929,  2932,  2935,  2939,  2943,  2947,  2950,  2959,  2962,
    2971,  2977,  2984,  2987,  3011,  3012,  3013,  3016,  3017,  3020,
    3026,  3027,  3028,  3029,  3030,  3031,  3036,  3040,  3044,  3048,
    3055,  3058,  3063,  3064,  3065,  3067,  3073,  3083,  3087,  3091,
    3095,  3099,  3103,  3107,  3111,  3119,  3129,  3134,  3138,  3142,
    3146,  3150,  3155,  3159,  3163,  3171,  3174,  3179,  3180,  3181,
    3186,  3187,  3188,  3196,  3199,  3204,  3205,  3209,  3210,  3215,
    3240,  3257,  3258,  3262,  3269,  3275,  3285,  3287,  3290,  3291,
    3292,  3293,  3295,  3298,  3302,  3307,  3311,  3317,  3318,  3321,
    3326,  3327,  3330,  3331,  3332,  3342,  3343,  3344,  3345,  3346,
    3347,  3348,  3349,  3353,  3359,  3361,  3380,  3388,  3395,  3396,
    3397,  3398,  3403,  3404,  3405,  3406,  3407,  3412,  3413,  3429,
    3430,  3431,  3432,  3433,  3434,  3435,  3436,  3437,  3438,  3440,
    3441,  3442,  3443,  3448,  3451,  3460,  3461,  3462,  3463,  3464,
    3465,  3469,  3470
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
  "WITH_LISTING_IN", "BACKQUOTE", "SET_POSTGRESQL_SEARCH_PATH",
  "SET_CONSTRAINTS_ALL_DEFERRED", "KW_LIMIT", "DOCUMENT", "ON_EXCEPTION",
  "SET_DEBUG_FILE_TO", "CREATE_DBA_PROCEDURE", "CREATE_FUNCTION",
  "CREATE_DBA_FUNCTION", "USE_SESSION", "KW_RUN_CLIENT", "LEFT_JOIN",
  "IGNORE_ERRORS", "SQLERRMESSAGE", "DISPLAY_NULL_TO", "UNBUFFERED",
  "KW_PICTURE", "ON_CHANGE", "INNER_JOIN", "UI_INTERFACE_DOT_FRONTCALL",
  "UICOMBOBOX", "UIBROWSER", "UIPROGRESS", "UIGANTT", "UIFORM",
  "USING_BTREE", "USING_RTREE", "SET_BUFFERED_LOG", "SET_LOG", "MDY",
  "WEEKDAY", "MODE_ANSI", "START_DATABASE", "WITH_LOG_IN",
  "SET_CONSTRAINTS_ALL_IMMEDIATE", "DATETIME_VALUE", "INTERVAL_VALUE",
  "RECOVER_TABLE", "ROLLFORWARD_DATABASE", "CONCAT_PIPES", "DROP_TRIGGER",
  "DROP_AUDIT_FOR", "CREATE_AUDIT_FOR", "EXECUTE_PROCEDURE", "ALTER_TABLE",
  "ALTER_INDEX", "NEXT_SIZE", "KW_WHENEVER_SIGNAL", "KW_SIGNAL_TOKEN",
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
  "VALUES", "KW_NULL", "KW_TRUE", "ALTER", "CHECK", "COUNT", "KW_FIRST",
  "KW_FLOAT", "GRANT", "INDEX", "LESS_THAN", "MONEY", "MONTH",
  "KW_MULTIPLY", "ORDER", "OUTER", "UNION", "WHERE", "KW_BYTE", "CASE",
  "KW_DATE", "DESC", "KW_DIVIDE", "DROP", "ELSE", "FROM", "HOUR", "INTO",
  "LIKE", "REAL", "SOME", "KW_TEXT", "KW_THEN", "USER", "WHEN", "YEAR",
  "KW_DOW", "XSET", "ADD", "ALL", "KW_AND", "ANY", "ASC", "AVG", "COLON",
  "KW_COMMA", "DAY", "DBA", "KW_FOR", "XMAX", "XMIN", "KW_MINUS", "KW_MOD",
  "KW_NOT", "KW_SUM", "ATSIGN", "KW_PLUS", "KW_AS", "KW_BY", "KW_DOT",
  "KW_IN", "KW_ON", "KW_OR", "KW_TO", "BEFORE", "END", "TILDE", "ILIKE",
  "FILLFACTOR", "TIME", "KW_TODAY", "KW_ROWID", "TIMESTAMP", "KWPIPE",
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
  "value_expression_initial_sli_nocast", "op_fgl_expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,  2248,  2249,  2250,  2251,  2252,  2253,  2254,  2255,
    2256,  2257,  2258,  2259,  2260,  2261,  2262,  2263,  2264,  2265,
    2266,  2267,  1001,  1002,  1003,  1004,  1005,  1006,  1008,  1009,
    1014,  1015,  1016,  1018,  1019,  1021,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1033,  1037,  1038,  1039,  1040,  1043,  1059,
    1060,  1079,  1082,  1084,  1085,  1088,  1089,  1090,  1091,  1104,
    1105,  1106,  1107,  1121,  1123,  1124,  1125,  1129,  1136,  1137,
    1138,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1184,  1185,
    1187,  1188,  1189,  1190,  1193,  1194,  1196,  1202,  1203,  1212,
    1224,  1225,  1226,  1231,  1234,  1235,  1236,  1237,  1238,  1239,
    1244,  1245,  1247,  1248,  1249,  1250,  1260,  1266,  1267,  1268,
    1269,  1270,  1281,  1282,  1290,  1291,  1292,  1298,  1306,  1313,
    1315,  1319,  1320,  1322,  1323,  1324,  1329,  1355,  1356,  1357,
    1358,  1365,  1366,  1373,  1381,  1383,  1384,  1388,  1389,  1396,
    1397,  1400,  1402,  1405,  1411,  1418,  1421,  1427,  1432,  1438,
    1439,  1444,  1446,  1448,  1449,  1451,  1462,  1469,  1472,  1473,
    1474,  1476,  1478,  1481,  1485,  1487,  1511,  1512,  1514,  1521,
    1523,  1524,  1526,  1527,  1528,  1534,  1535,  1541,  1542,  1544,
    1547,  1550,  1551,  1553,  1555,  1563,  1564,  1566,  1569,  1582,
    1585,  1586,  1587,  1588,  1590,  1591,  1599,  1602,  1603,  1604,
    1608,  1610,  1614,  1615,  1617,  1618,  1620,  1624,  1627,  1629,
    1633,  1637,  1638,  1641,  1643,  1644,  1647,  1648,  1650,  1656,
    1660,  1665,  1666,  1669,  1672,  1675,  1677,  1678,  1680,  1681,
    1682,  1691,  1694,  1701,  1703,  1705,  1706,  1707,  1710,  1711,
    1715,  1721,  1722,  1725,  1734,  1739,  1743,  1744,  1745,  1747,
    1750,  1751,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,
    1761,  1762,  1763,  1767,  1772,  1773,  1774,  1775,  1776,  1783,
    1786,  1787,  1793,  1795,  1796,  1799,  1801,  1802,  1803,  1841,
    1845,  1852,  1853,  1856,  1861,  1868,  1869,  2217,  2247
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   289,   290,   291,   291,   291,   292,   292,   292,   293,
     293,   293,   293,   293,   293,   294,   294,   295,   295,   296,
     296,   296,   296,   297,   298,   298,   299,   299,   300,   300,
     301,   302,   302,   302,   302,   303,   303,   304,   304,   305,
     305,   306,   306,   307,   307,   307,   307,   307,   308,   309,
     309,   310,   310,   311,   311,   311,   311,   312,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     314,   314,   315,   315,   316,   316,   317,   317,   317,   318,
     318,   319,   319,   320,   320,   320,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   323,   323,   324,   324,   325,
     325,   326,   326,   327,   327,   328,   329,   329,   330,   330,
     331,   332,   332,   333,   334,   334,   335,   335,   336,   336,
     337,   337,   338,   338,   339,   340,   342,   341,   344,   343,
     343,   345,   345,   346,   346,   347,   347,   348,   348,   349,
     349,   350,   351,   352,   353,   353,   354,   355,   355,   355,
     355,   355,   355,   355,   356,   356,   356,   357,   357,   357,
     357,   357,   357,   357,   358,   358,   358,   358,   359,   359,
     359,   360,   360,   360,   361,   361,   361,   362,   362,   363,
     363,   363,   363,   363,   363,   364,   364,   365,   365,   366,
     366,   367,   367,   368,   369,   369,   370,   370,   371,   371,
     372,   373,   374,   375,   376,   376,   377,   377,   378,   378,
     378,   379,   379,   380,   380,   380,   381,   381,   381,   381,
     382,   383,   383,   384,   384,   385,   385,   386,   387,   387,
     387,   387,   387,   387,   387,   388,   389,   390,   391,   391,
     392,   392,   393,   394,   395,   396,   396,   396,   396,   396,
     396,   397,   397,   398,   398,   398,   399,   399,   400,   400,
     401,   401,   401,   401,   402,   402,   403,   403,   404,   404,
     405,   405,   406,   406,   407,   407,   408,   408,   409,   409,
     410,   411,   412,   412,   413,   413,   413,   413,   413,   413,
     413,   413,   413,   413,   413,   413,   414,   414,   414,   414,
     414,   414,   415,   415,   415,   415,   416,   416,   416,   416,
     417,   417,   417,   417,   418,   419,   419,   419,   420,   420,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   422,   422,   423,
     423,   423,   423,   423,   424,   425,   426,   427,   427,   428,
     428,   428,   429,   429,   430,   430,   431,   431,   431,   431,
     432,   432,   432,   432,   433,   434,   434,   434,   434,   435,
     435,   436,   436,   436,   436,   436,   436,   436,   437,   437,
     437,   437,   437,   437,   437,   437,   438,   438,   438,   439,
     439,   440,   441,   442,   443,   444,   444,   445,   445,   446,
     447,   447,   447,   448,   449,   450,   451,   451,   452,   453,
     453,   454,   454,   454,   455,   456,   456,   457,   457,   458,
     459,   460,   460,   460,   460,   462,   463,   461,   464,   465,
     465,   466,   466,   466,   466,   467,   468,   469,   470,   470,
     471,   471,   471,   471,   472,   473,   473,   474,   474,   474,
     475,   475,   475,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   477,   477,
     478,   478,   479,   479,   480,   480,   480,   481,   481,   481,
     482,   482,   482,   482,   482,   482,   483,   483,   483,   483,
     484,   484,   485,   485,   485,   485,   486,   487,   487,   487,
     487,   487,   487,   487,   487,   488,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   490,   490,   490,   490,   490,
     490,   490,   490,   491,   492,   493,   493,   494,   494,   495,
     496,   497,   497,   498,   498,   498,   499,   499,   499,   499,
     499,   499,   499,   499,   500,   501,   502,   503,   503,   503,
     504,   504,   505,   505,   505,   506,   506,   506,   506,   506,
     506,   506,   506,   507,   507,   507,   508,   509,   510,   510,
     510,   510,   511,   511,   511,   511,   511,   512,   512,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   513,   513,   514,   514,   515,   515,   515,   515,   515,
     515,   516,   516
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
     448,     0,     0,     0,   470,     0,     0,   476,     0,     0,
       0,   472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   475,   473,   474,     8,   264,
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
     272,   507,   306,     0,     0,     0,     0,     0,   498,     0,
     630,     0,     0,   628,   629,   306,     0,   306,   306,   461,
     269,   306,   462,   556,     0,     0,     0,     0,     0,   301,
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
     626,   308,   309,   307,     0,     0,   501,     0,     0,   496,
     499,     0,     0,     0,     0,     0,     0,     0,     0,   265,
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
       0,   486,     0,   497,   491,   485,   490,     0,   487,     0,
       0,     0,   408,     0,   412,     0,   295,     0,   291,     0,
     293,   294,     0,   523,     0,   520,   522,   290,     0,   292,
       0,     0,   615,   604,   605,     0,   603,   606,   602,     0,
     601,     0,     0,   134,   136,     0,     0,   456,   256,   459,
       0,     0,    20,   172,     0,   164,   584,   544,   201,   207,
     212,   117,   319,   332,   334,     0,   336,     0,   338,     0,
       0,   323,   345,     0,   321,   349,     0,   432,   434,   202,
     204,     0,   226,   227,   552,    55,    56,     0,     0,    59,
      50,    51,    75,    58,    60,    61,    38,     0,   359,   256,
     503,   614,     0,     0,   260,     0,     0,     0,   482,   500,
     478,   479,   480,   481,     0,   275,   281,   279,   277,   524,
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
     848,   694,   945,   534,   343,   535,   344,   674,  1047,   441,
     442,   443,   444,   900,   445,   761,   768,   972,   376,   468,
     592,  1029,  1030,   290,  1024,   345,   485,   826,   823,    72,
      73,   129,   365,    74,    75,   205,   346,   347,   348,   349,
     350,  1050,  1091,  1092,  1093,  1106,   996,  1031,  1032,   599,
     470,   446,    76,   379,   738,  1071,  1010,  1051,  1072,   471,
     351,   151,   223,   564,   565,   566,   352,   353,   497,   498,
     659,   827,   669,   549,   354,   854,   855,   291,   127,   988,
      88,    96,   355,   295,   356,   134,   878,    99,    77,    78,
      79,    80,   100,    81,   159,   236,   237,    82,   357,    83,
     358,   715,   869,   716,   359,   360,   361,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -887
static const yytype_int16 yypact[] =
{
    2056,  -887,  -887,  -887,   135,  -887,   514,   135,   135,   514,
     514,   135,   613,   135,   135,   514,   613,   613,   613,   613,
    -887,   644,  -887,   135,  -887,  -887,   514,  -887,   151,   514,
     514,  -887,   514,   514,  -887,  -887,  -887,   514,   514,  -887,
    -887,   613,   514,   771,  -887,   135,   514,   792,   417,    22,
     514,   417,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,   145,  -887,  -887,
    -887,   392,  -887,  -887,  -887,   247,    23,  -887,  -887,   432,
    -887,  -887,  -887,    56,   341,   152,   495,   -82,  -887,  -887,
    -887,  -887,  -887,    65,    98,   159,   172,  -887,     6,  -887,
    -887,  -887,  -887,   263,  -887,  -887,   258,  -887,   277,  -887,
     306,    -2,   514,  -887,   203,   257,   273,  -887,   232,   305,
    -887,  -887,  -887,  -887,   438,  -887,  -887,  -887,  -887,  -887,
     409,   409,  -887,  -887,  -887,  -887,   394,   376,   382,  -887,
     677,   -12,   194,   398,   460,  -887,  2056,   809,  -887,  -887,
     704,   135,   830,   135,   135,   734,   560,    87,   744,  -887,
    -887,    82,   105,    95,   491,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,   135,  -887,  -887,   839,   135,   514,   514,
     514,   514,     6,  -887,   117,   514,   117,   102,   482,   755,
     891,  -887,   565,  -887,  -887,  -887,   135,   135,   854,   135,
     135,  -887,  -887,   102,  -887,  -887,   120,   514,   538,  -887,
    -887,  -887,  -887,  -887,  1163,  1163,  1163,  1163,    74,    74,
      32,   120,   514,  -887,   489,   510,   533,  -887,   747,  -887,
     544,  -887,   567,  -887,  -887,   624,   632,   635,   561,   640,
     643,  -887,  -887,  -887,   765,   135,   592,  -887,  -887,  -887,
     117,  -887,  -887,  -887,  -887,   946,   135,  -887,  -887,   117,
     583,  -887,   341,  -887,   593,  -887,   619,   698,  -887,   706,
     712,   718,  -887,    -7,  -887,  -887,    -5,   771,    64,  -887,
    -887,   647,   218,   713,  -887,  -887,  -887,   722,   651,  -887,
    -887,   920,   737,   742,  -887,  -887,  -887,   753,   551,  -887,
      22,   891,   753,   743,  -887,   754,   757,  -887,   605,   758,
     753,  -887,   759,   760,   753,   753,   761,   764,   768,   772,
    1825,  1009,   775,  1825,   945,  -887,  -887,  -887,   689,   716,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,   551,  -887,   551,
    -887,  -887,   490,  -887,  -887,   119,  -887,  -887,  -887,  -887,
     344,   868,   135,   374,  -887,   697,  -887,   703,  -887,   717,
    -887,    86,  -887,  -887,   720,  -887,  -887,   738,  -887,  1707,
    1707,  -887,   132,  -887,  -887,   216,   721,   721,   135,  -887,
    -887,   236,   146,   723,   778,  -887,   755,   891,  -887,   720,
     708,   135,   135,   809,  -887,   135,   881,   102,   102,   102,
     237,   765,   102,   891,   135,  -887,   243,   135,   245,  -887,
    -887,  -887,   793,   794,   795,   551,   551,  -887,   796,  -887,
     797,   798,   799,   800,   801,  -887,  -887,  -887,  -887,   802,
     803,   557,  -887,  -887,  -887,  -887,  -887,   250,  -887,  -887,
     254,   135,  -887,   135,   882,   135,   135,   135,   135,   842,
     117,    80,  -887,  -887,   102,    70,   996,   135,  -887,    22,
     886,  -887,  1281,   135,   980,  1707,  1707,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  -887,   725,   -12,   -78,   539,
    -887,  1707,    68,  1707,  1707,   891,   397,    53,  -887,  1707,
    -887,  1707,  1707,  -887,  -887,    68,  1707,    68,    68,   344,
    -887,    68,   344,  -887,   891,   891,   726,   -29,  1825,  -887,
    1825,  1825,  -887,  1825,  -887,   462,  1435,  -887,  -887,  1825,
    -887,   531,  -887,  1825,   142,  1707,    57,    59,  1707,  -887,
    -887,  -887,  -887,  -887,  -887,  1707,  1707,  1707,  1707,  -887,
     946,   256,  -887,   731,  -887,  -887,  -887,   135,   135,   898,
    -887,   102,   120,   120,   746,  -887,  -887,    66,   827,  -887,
    1163,  -887,  -887,   804,    74,    79,  -887,    74,  1163,  -887,
     689,   120,   735,  -887,  -887,  -887,   736,  -887,   831,   762,
    -887,   288,  -887,   300,  -887,   561,  -887,   301,   689,   834,
    -887,  -887,  -887,  -887,   117,  1017,  1017,  1018,   749,    28,
    1022,  1025,  1027,  1028,  1022,  1022,  1029,  1031,  -887,  -887,
    -887,   104,  -887,   311,  -887,   135,  -887,   117,  -887,  -887,
     763,  -887,   302,  -887,   -60,   314,   327,   328,  -887,    80,
    -887,  1032,  -887,  -887,  1033,  1034,  -887,    80,  -887,  -887,
    -887,   835,   -53,   766,   -12,  -887,  -887,  -887,  -887,   331,
     773,  -887,   337,   339,   673,  1707,  -887,  -887,   655,   862,
     366,  -887,  -887,  -887,  1707,   343,  -887,   -77,   363,  -887,
    -887,   346,   354,   369,  1707,   384,  1707,  1707,  1707,   716,
    -887,   673,  1042,   673,   849,   344,   851,   853,   849,    97,
    -887,  -887,  -887,   851,    97,  -887,   853,  -887,  -887,  1707,
    -887,  -887,    57,  -887,  -887,   272,  1048,  -887,  -887,   209,
    -887,  -887,  -887,  -887,  -887,  -887,  -887,   135,   135,   858,
    -887,  -887,   780,  -887,  -887,  -887,   720,  1707,  -887,   135,
    -887,  -887,   860,  -887,  -887,   238,  -887,  -887,    31,   135,
     135,   904,   102,  -887,   102,  -887,   765,  -887,  -887,  -887,
    -887,   878,   879,   385,   673,  1061,   673,  -887,   805,   887,
     387,   892,   894,   805,   895,   897,  -887,  -887,  -887,  -887,
     514,  -887,  -887,  -887,   871,  -887,  -887,   311,  -887,   765,
    -887,  -887,   135,    73,   135,  -887,  -887,    73,    73,    73,
     842,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  1076,   135,
    1707,  -887,  1707,   135,  -887,  -887,   885,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,   230,   551,   806,  -887,  -887,  -887,
     901,  -887,  1707,  -887,  -887,  -887,  -887,   902,  -887,   907,
     908,   911,  -887,   912,  -887,   104,  -887,   104,  -887,   104,
    -887,  -887,   101,  -887,   389,  -887,  -887,  -887,   395,  -887,
     838,   200,  -887,  -887,  -887,    57,  -887,  -887,  -887,    57,
    -887,    57,   135,  -887,  -887,  1553,   135,  -887,   855,  -887,
    1163,   135,  -887,  -887,   644,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,  -887,  -887,  1091,  -887,   916,  -887,  1095,
     922,  -887,  -887,  1097,  -887,  -887,   923,  -887,  -887,  -887,
     914,   891,  -887,  -887,  -887,  -887,  -887,  1034,  1104,  -887,
      73,  -887,  -887,  -887,  -887,  -887,  -887,   924,   835,   230,
    -887,   906,  1107,   514,   304,   935,   843,   673,  -887,  -887,
    -887,  -887,  -887,  -887,   845,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,    97,  -887,  1707,  -887,   580,   675,   285,   910,
    -887,   400,  -887,  -887,  -887,   889,   406,   835,  -887,   944,
     850,  -887,  -887,  -887,   947,  -887,   102,   950,  -887,  -887,
    -887,  -887,  -887,  -887,    57,   951,   109,  -887,    67,    84,
     891,   891,  -887,     8,  -887,  -887,   934,  -887,   673,  -887,
     673,  -887,  -887,  -887,  -887,    57,    57,  -887,  1553,   244,
     -18,  -887,  -887,  -887,   673,  -887,   410,  -887,   447,  -887,
     123,   123,   107,   135,  -887,  -887,  -887,    78,  -887,  -887,
    -887,   877,  -887,   864,   418,   689,   689,  -887,  -887,  -887,
    -887,   691,   471,  -887,  -887,  -887,  -887,   929,   135,   870,
     979,  -887,  -887,  -887,  -887,    57,   514,   109,   872,   874,
     158,  -887,  -887,  -887,    84,    92,  -887,  -887,  -887,    57,
      22,  -887,  1001,  -887,    91,   135,   694,   100,   891,   891,
     514,  -887,  -887,  -887,   835,   702,   -12,  -887,  -887,  -887,
    -887,   893,  -887,    52,  1001,  -887,  -887,   689,   689,   113,
    -887,  -887,  1707,    91,  -887,  -887,  -887,  -887,  -887,   230,
    -887,   889,  -887
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -887,  -887,  -887,  -887,  -887,  -887,  -184,   776,   574,  -887,
    -171,  -213,  -887,  -887,  -887,  -887,   515,  -887,   516,   253,
    -603,  -887,   251,   449,  -887,   373,    88,   240,   380,   988,
    -149,  -887,  -887,   913,  -887,  -221,  -887,  -887,  -887,  -231,
    -887,  -887,  -209,  -887,  -887,  -887,  -887,  -371,  -887,   931,
     770,  -887,  -887,  -887,  -887,  -887,  -887,  -887,   461,  -887,
     181,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    1142,  -887,  1143,  -887,   977,  1055,  -887,  -154,   636,  -887,
    -887,  -887,  -887,  -887,  -887,   446,  -887,  -887,   223,  -887,
     -50,  -150,  -887,  -887,  -887,  -887,  -887,   413,  -887,  -887,
    -887,  -887,  -887,    -3,   206,  -887,  -887,  -808,   184,  -886,
    -799,  -887,   213,  -180,   695,   696,   883,  -887,   512,   506,
     517,   308,    71,  -887,  -887,  -887,  -887,   278,  -887,   663,
    -887,  -887,  -887,   442,  -887,   612,    75,  -887,   -20,  -362,
    -170,  -856,   192,   937,   198,  -571,  -887,  -285,  -632,  -887,
    -887,  1015,   670,  -887,  -887,  -887,  -887,  -887,  -887,  -887,
    -887,  -887,  -887,   125,  -887,  -887,  -887,  -887,   167,   321,
    -887,  -887,  -887,  -887,  -887,  -887,   124,  -887,   163,   876,
     -66,  -289,  -456,  -629,  -887,   497,  -159,  -887,   745,  -405,
     434,   570,  -887,  -887,  -887,   541,   290,   -25,  -887,    43,
    -887,   750,    -4,   852,   401,  -887,  -887,  -887,  -887,  -887,
    1090,  -887,  1233,  -887,  -887,  -887,   846,  -887,  -459,  -887,
    -887,  -655,  -887,  -887,  -887,   -34,  -887,  -887
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
     576,   665,   670,    89,    89,   448,   824,    97,    89,   128,
     596,   130,    89,   372,   389,   284,    89,   284,   449,    87,
     777,   419,    92,    93,   385,   386,   387,   861,   102,   842,
     711,   844,   516,    84,   517,   384,   384,   384,   384,   113,
      84,    84,   116,   117,    84,   118,   119,   399,    84,   965,
     120,   121,    84,    84,   125,   124,    84,  1026,    84,   131,
     125,    84,   680,   152,  1089,    84,    84,   125,   411,    84,
     296,    84,   666,   298,   949,   193,    84,   296,   125,    84,
     776,    84,   299,    86,   300,   199,   299,   301,    89,   299,
     270,    84,   915,   916,    84,   986,   107,    84,   853,    86,
     983,   488,   896,   853,   898,  1020,  1061,   807,   496,    84,
     608,   609,  1021,    37,  1020,   155,   883,  1048,  1020,   396,
     641,  1021,   489,   235,   114,  1021,   220,   239,   241,   242,
     243,   156,    84,   258,    86,   202,   692,   265,   268,   265,
     832,   642,   643,   459,  1081,   461,   795,   186,   989,   273,
     654,   929,   275,   276,    89,    89,    89,    89,   187,   282,
     265,    89,   265,   292,   923,   924,   925,   796,   810,   514,
     514,   221,   364,   366,   368,   369,   130,   808,   990,   292,
     956,  1049,   111,    89,   957,    48,   958,   580,  1090,   644,
     567,   568,   245,   765,   392,   392,   246,   111,    89,    51,
     200,   278,   278,   278,   278,   245,   671,   590,   285,   246,
     856,   477,   222,   150,   463,   856,   490,  1090,  1077,   693,
     247,   258,   712,   460,   500,   460,   265,   245,   503,   504,
     377,   246,   268,   247,   397,   265,   560,   224,   225,   226,
     227,   228,  1099,   680,   946,   400,   946,   260,   946,   308,
    1096,   672,   255,   292,   707,   247,   308,   717,  1104,   806,
     269,   562,   494,  1108,   649,   249,   509,   161,   650,   512,
     266,   250,   495,   884,   160,   999,   766,   744,   249,  1105,
    1111,   640,   569,   658,   250,   677,   658,   658,  1056,   708,
    1083,   709,   673,   713,   464,   536,   203,   373,   714,  1018,
     249,   165,   668,   679,   658,   676,   250,  1060,   739,  1023,
     658,   188,   658,   658,   388,   718,   561,   658,   917,   204,
    1041,  1042,   466,  1080,  1027,   645,   918,   741,   553,   593,
    1022,  1027,   597,   852,  1028,   747,  1039,   702,  1040,  1022,
    1028,   334,   287,  1022,   189,   334,   710,  1028,   334,   720,
     955,   853,  1052,   882,   392,   891,   721,   722,   723,   724,
     743,   734,   570,   537,   790,   759,   571,   582,   583,   235,
    1076,   585,   587,   292,   292,   292,   791,   538,   292,   736,
     600,   384,  1044,   258,  1085,   871,   573,   594,   913,   384,
     575,   166,   167,   601,   466,   603,   183,   748,   863,   778,
     624,   168,   169,   170,   626,   190,   726,   864,   539,   540,
     541,   542,   543,   544,   466,   756,   229,   628,   191,   629,
     631,   634,   634,   634,   634,   779,   265,  1045,   194,   700,
     292,   651,   862,   653,   780,   705,   866,   867,   753,   660,
     933,   868,   196,  1109,   989,  1004,   570,   208,   270,   781,
     755,   757,   793,   872,   695,   782,   695,   695,   209,   695,
     737,   208,   467,   856,   797,   695,   574,   595,  1046,   695,
     863,   197,   209,   417,   990,   604,   567,   798,   799,   864,
     625,   811,   881,   863,   627,   830,   727,   814,    84,   815,
      86,   195,   864,   831,   783,   837,   834,   839,   840,   841,
     784,   206,   865,   719,   835,   478,   991,   135,   866,   867,
     936,   157,   158,   868,   171,  1005,  -504,   207,   754,   836,
     860,   866,   867,   366,   731,   733,   868,   292,   111,   111,
     754,   754,   794,   740,   838,   894,   982,   902,   479,   951,
     392,   745,   545,   392,   794,   953,   480,   111,   567,   172,
    1007,   546,   889,   210,   890,   469,  1011,   794,   794,   554,
    1053,   812,   136,   481,   173,   184,   185,   812,   137,   812,
     265,   211,   494,   812,   213,  1012,   812,   482,   296,   297,
     547,   298,   495,   138,   812,   548,   483,    84,   139,    95,
     299,   268,   300,   265,   466,   301,   825,   484,   140,   812,
    1102,   141,  -282,   518,   216,   142,   494,  1054,   279,   280,
     281,   143,   218,   833,   812,   895,   495,   903,    84,   952,
     107,   567,   217,   930,   519,   952,   310,   699,   302,   303,
    1008,  1068,   520,   521,   304,   305,   570,  -282,   522,  -282,
     752,   144,  1066,   939,   514,   863,   231,   208,   523,   145,
     219,   524,   518,   525,   864,   618,   619,   620,   209,   772,
     773,   162,  -529,   306,   526,   527,   635,   636,   637,   863,
     245,   245,   163,   519,   246,   246,   164,  1055,   864,   966,
     238,   520,   521,   866,   867,   528,   963,   522,   868,   667,
     478,   384,  1100,   553,   874,   310,   704,   523,   247,   247,
     524,  1069,   525,   529,   138,   879,   232,   866,   867,   139,
     244,   621,   868,   526,   527,   886,   887,   259,   292,   140,
     292,   272,   141,   479,   293,   248,   142,   307,   530,   294,
     362,   480,   143,   401,   528,   531,   103,   104,   105,   106,
    1003,   532,   533,   249,   249,    84,    89,   125,   481,   250,
     250,  1086,   529,   684,   402,   686,   687,   308,   914,   688,
     634,   123,   482,   403,  -305,  1002,   132,   309,   133,   310,
     311,   483,   404,   312,   313,   928,   590,   530,   863,   931,
    1035,  1036,   484,    84,   531,   234,  -305,   864,   405,   407,
     532,   533,   314,   910,   478,   315,   406,   408,   696,   697,
     409,   698,   316,   317,    84,   412,   240,   703,   413,   318,
     319,   706,   816,    84,   494,   274,   866,   867,   414,   963,
     320,   868,   417,   321,   495,   322,   323,   479,    84,   324,
     367,   325,   451,   326,   968,   480,   327,   453,   959,   328,
     329,   330,   964,   331,   332,   817,   333,   967,   454,   334,
     111,  1067,   481,   818,  1095,    84,    84,   586,   630,   335,
     336,   337,  1101,   455,   296,   297,   482,   298,  1097,  1098,
     819,   456,    84,   863,   732,   483,   299,   457,   300,   662,
     663,   301,   864,   458,   820,   825,   484,   472,   947,   863,
     948,   465,   863,   821,   469,   473,   474,   675,   864,    89,
     863,   864,   475,   681,   822,   682,   683,   476,   491,   864,
     685,   866,   867,   567,   302,   303,   868,   310,   513,   492,
     304,   305,   493,   499,   501,   502,   505,   866,   867,   506,
     866,   867,   868,   507,  1033,   868,   514,   508,   866,   867,
     511,   515,   292,   868,   550,   557,   559,   558,   563,   306,
     562,   570,   578,   577,  1025,  1034,   581,   638,   605,   606,
     607,   610,   611,   612,   613,   614,   615,   616,   617,   652,
     655,   661,  1033,   664,   691,   728,   737,   667,   742,   749,
     750,   751,   296,   297,   758,   298,    89,    89,    89,  1025,
     760,   763,   752,  1034,   299,   767,   300,   764,   769,   301,
     770,   771,   774,   420,   775,   801,   802,   792,   803,  1033,
     809,   466,   828,   307,  1073,   843,   845,   813,   847,  1033,
     849,   870,    89,   875,   876,   880,    89,   780,   892,   893,
    1034,  1084,   302,   303,   897,   899,   911,   901,   304,   305,
    1034,  1073,   904,   308,   905,   907,    89,   908,  1033,   927,
     932,   938,   940,   309,   937,   310,   311,   941,   942,   312,
     313,   943,   944,   954,   969,   933,   970,   306,   971,  1034,
     974,   421,   973,   975,   422,   423,   424,   979,   314,   976,
     985,   315,   984,   425,   981,   997,  1006,   426,   316,   317,
    1009,   998,   427,  1000,  1013,   318,   319,  1015,  1014,   428,
    1017,  1019,   429,   430,   990,   431,   320,  1064,  1065,   321,
    1070,   322,   323,  1074,  1075,   324,  1087,   325,  1078,   326,
    1079,   746,   327,  1103,   800,   328,   329,   330,   432,   331,
     332,   307,   333,   805,   572,   334,   296,   297,   433,   298,
     978,   980,   434,   926,   922,   335,   336,   337,   299,   435,
     300,   436,  1107,   301,   286,   452,   416,   602,   873,  1043,
     437,   308,   438,   153,   154,   378,   215,   888,   735,  1016,
     912,   309,  1038,   310,   311,  1059,  1037,   312,   313,   689,
     851,   690,   859,   725,   510,   906,   302,   303,   762,  1063,
     857,  1062,   304,   305,   462,   370,   314,   730,  1110,   315,
     439,  1082,   977,   440,   877,  1112,   316,   317,  1094,   556,
     829,   678,  1001,   318,   319,   858,   233,   101,   579,   584,
       0,   306,     0,   950,   320,     0,     0,   321,     0,   322,
     323,     0,     0,   324,     0,   325,     0,   326,     0,     0,
     327,     0,     0,   328,   329,   330,     0,     0,   332,     0,
     333,     0,     0,   334,   296,   297,     0,   298,     0,     0,
       0,     0,     0,   335,   336,   337,   299,     0,   300,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   302,   303,     0,     0,     0,     0,
     304,   305,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,   310,   380,     0,
       0,     0,   313,     0,     0,     0,     0,     0,     0,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   381,
     314,     0,     0,   315,     0,     0,     0,     0,     0,     0,
     316,   317,     0,     0,     0,     0,     0,   318,   319,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   320,     0,
       0,   321,     0,   322,   323,     0,     0,   324,     0,   325,
       0,   326,     0,     0,   327,     0,     0,   328,   329,   330,
       0,     0,   332,     0,   333,     0,     0,   334,   296,   297,
       0,   298,     0,     0,     0,     0,     0,   335,   336,   337,
     299,     0,   300,     0,     0,   301,     0,     0,     0,     0,
       0,   657,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   309,     0,   310,   380,     0,     0,     0,
     313,     0,     0,     0,     0,     0,     0,     0,   302,   303,
       0,     0,     0,     0,   304,   305,     0,     0,   314,     0,
       0,   315,     0,     0,     0,     0,     0,     0,   316,   317,
       0,     0,     0,     0,     0,   318,   319,     0,     0,     0,
       0,     0,     0,   306,     0,     0,   320,     0,     0,   321,
       0,   322,   323,     0,     0,   324,     0,   325,     0,   326,
       0,     0,   327,     0,     0,   328,   329,   330,     0,     0,
     332,     0,   333,     0,     0,   334,   296,   297,     0,   298,
       0,     0,     0,     0,     0,   335,   336,   337,   299,     0,
     300,     0,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   302,   303,     0,     0,
       0,     0,   304,   305,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,   310,
     380,     0,     0,     0,   313,     0,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   701,   314,     0,     0,   315,     0,     0,     0,     0,
       0,     0,   316,   317,     0,     0,     0,     0,     0,   318,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,     0,     0,   321,     0,   322,   323,     0,     0,   324,
       0,   325,     0,   326,     0,     0,   327,     0,     0,   328,
     329,   330,     0,     0,   332,     0,   333,     0,     0,   334,
     296,   297,     0,   298,     0,     0,     0,     0,     0,   335,
     336,   337,   299,     0,   300,     0,     0,   301,     0,     0,
       0,     0,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,   310,   380,     0,
       0,     0,   313,     0,     0,     0,     0,     0,     0,     0,
     302,   303,     0,     0,     0,     0,   304,   305,     0,   960,
     314,     0,     0,   315,     0,     0,     0,     0,     0,     0,
     316,   317,     0,     0,     0,     0,     0,   318,   319,     0,
       0,     0,     0,     0,     0,   306,     0,     0,   320,     0,
       0,   321,     0,   322,   323,     0,     0,   324,     0,   325,
       0,   326,     0,     0,   327,     0,     0,   328,   329,   330,
       0,     0,   332,     0,   333,     0,     0,   334,   296,   297,
       0,   298,     0,     0,     0,     0,     0,   335,   336,   337,
     299,     0,   300,     0,     0,   301,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,   303,
       0,     0,     0,     0,   304,   305,     0,     0,     0,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   309,
       0,   310,   380,     0,     0,     0,   313,     0,     0,     0,
       0,     0,     0,   306,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   314,     0,     0,   315,     0,     0,
       0,     0,     0,     0,   316,   317,     0,     0,     0,     0,
       0,   318,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,     0,     0,   321,     0,   322,   323,     0,
       0,   324,     0,   325,     0,   326,     0,     0,   327,     0,
       0,   328,   329,   330,     0,     0,   332,     0,   333,     0,
       0,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   335,   336,   337,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,   310,
     380,     0,     0,     0,   313,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   314,     0,     0,   315,     0,     0,     0,     0,
       0,     0,   316,   317,     0,     0,  -566,     1,     0,   318,
     319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,     0,  -566,   321,     0,   322,   323,     0,     0,   324,
       0,   325,     0,   326,     0,     0,   327,     0,     0,   328,
     329,     0,     0,     0,   332,     0,     0,     0,     0,   334,
       0,     0,     0,     0,     0,     0,     0,     2,     3,   335,
     336,   337,     4,     0,     5,     0,     0,     6,     7,     0,
       8,     9,    10,     0,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    14,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,    28,     0,    29,    30,     0,
       0,     0,    31,    32,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,     0,    39,     0,     0,
       0,     0,     0,    40,    41,     0,     0,    42,     0,     0,
      43,     0,    44,    45,     0,     0,     0,     0,    46,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    49,     0,     0,
      50,     0,     0,     0,     0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       4,    21,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   166,    21,    43,    23,
     200,   310,    26,   308,   173,    29,    30,   197,    32,    33,
     392,   487,   491,    37,    38,   266,   665,    41,    42,    43,
     411,    45,    46,   213,   228,   194,    50,   196,   269,     6,
     621,   260,     9,    10,   225,   226,   227,   712,    15,   691,
       3,   693,   347,     4,   349,   224,   225,   226,   227,    26,
       4,     4,    29,    30,     4,    32,    33,   231,     4,   878,
      37,    38,     4,     4,     6,    42,     4,     3,     4,    46,
       6,     4,   497,    50,     3,     4,     4,     6,   248,     4,
       3,     4,   180,     6,     3,   108,     4,     3,     6,     4,
       6,     4,    15,     6,    17,   117,    15,    20,   122,    15,
     269,     4,    49,    50,     4,   933,     6,     4,   699,     6,
     929,   311,   764,   704,   766,    35,  1022,   190,   318,     4,
     425,   426,    42,   137,    35,     0,   115,   165,    35,   117,
      70,    42,   311,   157,     3,    42,   168,   161,   162,   163,
     164,    16,     4,   167,     6,   122,   195,   171,   172,   173,
     247,    91,    92,   180,  1060,   180,   236,   259,   170,   183,
     469,   810,   186,   187,   188,   189,   190,   191,   270,   192,
     194,   195,   196,   197,   797,   798,   799,   257,   654,   277,
     277,   213,   206,   207,   208,   209,   210,   260,   200,   213,
     865,   229,   216,   217,   869,   209,   871,   397,  1074,   139,
     379,   380,   140,   195,   228,   229,   144,   231,   232,   223,
     232,   188,   189,   190,   191,   140,   168,   407,   195,   144,
     699,   307,   254,   221,   180,   704,   312,  1103,  1056,   278,
     168,   255,   195,   260,   320,   260,   260,   140,   324,   325,
     217,   144,   266,   168,   232,   269,   180,    73,    74,    75,
      76,    77,  1080,   678,   845,   232,   847,   195,   849,   182,
     180,   213,   195,   287,   142,   168,   182,   228,   236,   651,
     195,   260,   239,   180,   464,   213,   330,   274,   228,   333,
     195,   219,   249,   272,    57,   937,   278,   228,   213,   257,
    1109,   460,   180,   472,   219,   495,   475,   476,   195,   177,
     228,   179,   254,   266,   260,   206,   123,   207,   271,   984,
     213,   275,   491,   280,   493,   494,   219,   230,   272,   272,
     499,   276,   501,   502,   270,   286,   260,   506,   275,   146,
    1005,  1006,   206,   195,   270,   275,   283,   570,   362,   409,
     260,   270,   412,   266,   286,   578,   998,   526,  1000,   260,
     286,   274,   270,   260,   276,   274,   535,   286,   274,   538,
     180,   952,  1014,   745,   388,   756,   545,   546,   547,   548,
     574,   561,   260,   274,   625,   604,   180,   401,   402,   403,
    1055,   405,   406,   407,   408,   409,   627,    63,   412,   563,
     414,   570,   168,   417,  1069,   206,   180,   180,   789,   578,
     274,    80,    81,   180,   206,   180,   274,   581,   228,   118,
     180,    90,    91,    92,   180,   276,   180,   237,    94,    95,
      96,    97,    98,    99,   206,   595,   252,   451,   276,   453,
     454,   455,   456,   457,   458,   144,   460,   213,   195,   525,
     464,   465,   190,   467,   153,   531,   266,   267,   180,   473,
     240,   271,   195,  1102,   170,   190,   260,   259,   627,   168,
     180,   180,   180,   274,   518,   174,   520,   521,   270,   523,
     260,   259,   274,   952,   180,   529,   260,   260,   254,   533,
     228,   195,   270,   260,   200,   260,   665,   180,   180,   237,
     260,   180,   274,   228,   260,   674,   260,   180,     4,   180,
       6,   263,   237,   180,   213,   684,   180,   686,   687,   688,
     219,   274,   260,   537,   180,   169,   232,   120,   266,   267,
     825,   149,   150,   271,   203,   260,   180,   274,   260,   180,
     709,   266,   267,   557,   558,   559,   271,   561,   562,   563,
     260,   260,   260,   567,   180,   180,   928,   180,   202,   180,
     574,   575,   228,   577,   260,   180,   210,   581,   737,   238,
     180,   237,   752,   278,   754,   211,   180,   260,   260,   215,
     180,   260,   175,   227,   253,   100,   101,   260,   181,   260,
     604,   163,   239,   260,   195,   967,   260,   241,     3,     4,
     266,     6,   249,   196,   260,   271,   250,     4,   201,     6,
      15,   625,    17,   627,   206,    20,   260,   261,   211,   260,
    1086,   214,   142,   143,   240,   218,   239,   190,   189,   190,
     191,   224,   260,   280,   260,   260,   249,   260,     4,   260,
       6,   810,   276,   812,   164,   260,   194,   195,    53,    54,
     260,   190,   172,   173,    59,    60,   260,   177,   178,   179,
     260,   254,  1034,   832,   277,   228,   278,   259,   188,   262,
       3,   191,   143,   193,   237,   128,   129,   130,   270,   614,
     615,   259,   274,    88,   204,   205,   456,   457,   458,   228,
     140,   140,   270,   164,   144,   144,   274,   260,   237,   880,
       6,   172,   173,   266,   267,   225,   875,   178,   271,   180,
     169,   880,  1084,   727,   728,   194,   195,   188,   168,   168,
     191,   260,   193,   243,   196,   739,   276,   266,   267,   201,
       6,   184,   271,   204,   205,   749,   750,     3,   752,   211,
     754,   260,   214,   202,   272,   195,   218,   152,   268,     4,
     195,   210,   224,   274,   225,   275,    16,    17,    18,    19,
     190,   281,   282,   213,   213,     4,   780,     6,   227,   219,
     219,  1070,   243,   505,   274,   507,   508,   182,   792,   511,
     794,    41,   241,   260,   255,   954,     4,   192,     6,   194,
     195,   250,    55,   198,   199,   809,   976,   268,   228,   813,
     990,   991,   261,     4,   275,     6,   277,   237,   274,   195,
     281,   282,   217,   780,   169,   220,   259,   195,   520,   521,
     195,   523,   227,   228,     4,   195,     6,   529,   195,   234,
     235,   533,   169,     4,   239,     6,   266,   267,    83,  1008,
     245,   271,   260,   248,   249,   250,   251,   202,     4,   254,
       6,   256,   279,   258,   884,   210,   261,   274,   872,   264,
     265,   266,   876,   268,   269,   202,   271,   881,   259,   274,
     884,   190,   227,   210,   190,     4,     4,     6,     6,   284,
     285,   286,   190,   195,     3,     4,   241,     6,  1078,  1079,
     227,   195,     4,   228,     6,   250,    15,   195,    17,   475,
     476,    20,   237,   195,   241,   260,   261,   195,   847,   228,
     849,   274,   228,   250,   211,   274,     6,   493,   237,   933,
     228,   237,   195,   499,   261,   501,   502,   195,   195,   237,
     506,   266,   267,  1102,    53,    54,   271,   194,     3,   195,
      59,    60,   195,   195,   195,   195,   195,   266,   267,   195,
     266,   267,   271,   195,   989,   271,   277,   195,   266,   267,
     195,   255,   976,   271,   106,   278,   259,   274,   240,    88,
     260,   260,   204,   260,   988,   989,   278,   145,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,     3,
     114,    21,  1027,   278,   278,   274,   260,   180,   204,   274,
     274,   180,     3,     4,   180,     6,  1020,  1021,  1022,  1023,
       3,     3,   260,  1027,    15,     3,    17,   278,     3,    20,
       3,     3,     3,    87,     3,     3,     3,   274,     4,  1064,
     274,   206,   180,   152,  1048,     3,   197,   274,   197,  1074,
     197,     3,  1056,   195,   274,   195,  1060,   153,   180,   180,
    1064,  1065,    53,    54,     3,   260,   195,   180,    59,    60,
    1074,  1075,   180,   182,   180,   180,  1080,   180,  1103,     3,
     195,   180,   180,   192,   278,   194,   195,   180,   180,   198,
     199,   180,   180,   255,     3,   240,   180,    88,     3,  1103,
       3,   155,   180,   180,   158,   159,   160,     3,   217,   195,
       3,   220,   206,   167,   190,   180,   206,   171,   227,   228,
     231,   278,   176,   278,   180,   234,   235,   180,   278,   183,
     180,   180,   186,   187,   200,   189,   245,   260,   274,   248,
     211,   250,   251,   273,   165,   254,   145,   256,   276,   258,
     276,   577,   261,   260,   639,   264,   265,   266,   212,   268,
     269,   152,   271,   647,   388,   274,     3,     4,   222,     6,
     917,   920,   226,   800,   794,   284,   285,   286,    15,   233,
      17,   235,  1094,    20,   196,   272,   255,   417,   727,  1008,
     244,   182,   246,    51,    51,   218,   141,   751,   562,   976,
     787,   192,   996,   194,   195,  1021,   993,   198,   199,   514,
     698,   515,   706,   550,   331,   773,    53,    54,   606,  1027,
     703,  1023,    59,    60,   287,   210,   217,   557,  1103,   220,
     284,  1064,   911,   287,   737,  1111,   227,   228,  1075,   363,
     670,   496,   952,   234,   235,   704,   156,    14,   396,   403,
      -1,    88,    -1,   852,   245,    -1,    -1,   248,    -1,   250,
     251,    -1,    -1,   254,    -1,   256,    -1,   258,    -1,    -1,
     261,    -1,    -1,   264,   265,   266,    -1,    -1,   269,    -1,
     271,    -1,    -1,   274,     3,     4,    -1,     6,    -1,    -1,
      -1,    -1,    -1,   284,   285,   286,    15,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,   248,    -1,   250,   251,    -1,    -1,   254,    -1,   256,
      -1,   258,    -1,    -1,   261,    -1,    -1,   264,   265,   266,
      -1,    -1,   269,    -1,   271,    -1,    -1,   274,     3,     4,
      -1,     6,    -1,    -1,    -1,    -1,    -1,   284,   285,   286,
      15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,   180,    -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,    -1,   194,   195,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,   217,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,   234,   235,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,   245,    -1,    -1,   248,
      -1,   250,   251,    -1,    -1,   254,    -1,   256,    -1,   258,
      -1,    -1,   261,    -1,    -1,   264,   265,   266,    -1,    -1,
     269,    -1,   271,    -1,    -1,   274,     3,     4,    -1,     6,
      -1,    -1,    -1,    -1,    -1,   284,   285,   286,    15,    -1,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,   182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,   217,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,   234,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,    -1,    -1,   248,    -1,   250,   251,    -1,    -1,   254,
      -1,   256,    -1,   258,    -1,    -1,   261,    -1,    -1,   264,
     265,   266,    -1,    -1,   269,    -1,   271,    -1,    -1,   274,
       3,     4,    -1,     6,    -1,    -1,    -1,    -1,    -1,   284,
     285,   286,    15,    -1,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,   216,
     217,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,   234,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,   245,    -1,
      -1,   248,    -1,   250,   251,    -1,    -1,   254,    -1,   256,
      -1,   258,    -1,    -1,   261,    -1,    -1,   264,   265,   266,
      -1,    -1,   269,    -1,   271,    -1,    -1,   274,     3,     4,
      -1,     6,    -1,    -1,    -1,    -1,    -1,   284,   285,   286,
      15,    -1,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   217,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,   234,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,    -1,    -1,   248,    -1,   250,   251,    -1,
      -1,   254,    -1,   256,    -1,   258,    -1,    -1,   261,    -1,
      -1,   264,   265,   266,    -1,    -1,   269,    -1,   271,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   284,   285,   286,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,   227,   228,    -1,    -1,     0,     1,    -1,   234,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,    -1,    16,   248,    -1,   250,   251,    -1,    -1,   254,
      -1,   256,    -1,   258,    -1,    -1,   261,    -1,    -1,   264,
     265,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,   284,
     285,   286,    56,    -1,    58,    -1,    -1,    61,    62,    -1,
      64,    65,    66,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,    -1,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,   116,    -1,    -1,   119,    -1,   121,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,   133,
     134,   135,   136,   137,   138,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,   147,   148,    -1,    -1,   151,    -1,    -1,
     154,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,    -1,   211,    -1,    -1,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    51,    52,    56,    58,    61,    62,    64,    65,
      66,    68,    69,    78,    79,    82,   102,   103,   104,   105,
     107,   108,   109,   110,   111,   112,   113,   116,   119,   121,
     122,   126,   127,   133,   134,   135,   136,   137,   138,   141,
     147,   148,   151,   154,   156,   157,   162,   166,   209,   211,
     214,   223,   290,   301,   302,   303,   304,   313,   320,   340,
     341,   350,   351,   352,   354,   355,   356,   357,   358,   368,
     388,   392,   438,   439,   442,   443,   461,   497,   498,   499,
     500,   502,   506,   508,     4,   491,     6,   488,   489,   491,
     491,   491,   488,   488,   491,     6,   490,   491,   491,   496,
     501,   501,   488,   490,   490,   490,   490,     6,   389,   390,
     427,   491,   491,   488,     3,   516,   488,   488,   488,   488,
     488,   488,   342,   490,   488,     6,   486,   487,   491,   440,
     491,   488,     4,     6,   494,   120,   175,   181,   196,   201,
     211,   214,   218,   224,   254,   262,   359,   361,   362,   363,
     221,   470,   488,   359,   361,     0,    16,   149,   150,   503,
      57,   274,   259,   270,   274,   275,    80,    81,    90,    91,
      92,   203,   238,   253,   321,   322,   323,   326,   329,   332,
     333,   334,   337,   274,   100,   101,   259,   270,   276,   276,
     276,   276,   391,   392,   195,   263,   195,   195,   369,   117,
     232,   292,   488,   123,   146,   444,   274,   274,   259,   270,
     278,   163,   353,   195,   364,   364,   240,   276,   260,     3,
     168,   213,   254,   471,    73,    74,    75,    76,    77,   252,
     293,   278,   276,   499,     6,   491,   504,   505,     6,   491,
       6,   491,   491,   491,     6,   140,   144,   168,   195,   213,
     219,   372,   373,   378,   380,   195,   338,   339,   491,     3,
     195,   319,   331,   380,   382,   491,   195,   328,   491,   195,
     319,   324,   260,   491,     6,   491,   491,   312,   488,   312,
     312,   312,   392,   318,   319,   488,   318,   270,   370,   429,
     432,   486,   491,   272,     4,   492,     3,     4,     6,    15,
      17,    20,    53,    54,    59,    60,    88,   152,   182,   192,
     194,   195,   198,   199,   217,   220,   227,   228,   234,   235,
     245,   248,   250,   251,   254,   256,   258,   261,   264,   265,
     266,   268,   269,   271,   274,   284,   285,   286,   402,   403,
     404,   405,   406,   413,   415,   434,   445,   446,   447,   448,
     449,   469,   475,   476,   483,   491,   493,   507,   509,   513,
     514,   515,   195,   345,   491,   441,   491,     6,   491,   491,
     440,   365,   429,   207,   366,   367,   427,   488,   363,   462,
     195,   216,   299,   300,   475,   299,   299,   299,   270,   295,
     296,   298,   491,   294,   295,   297,   117,   232,   291,   366,
     488,   274,   274,   260,    55,   274,   259,   195,   195,   195,
     335,   380,   195,   195,    83,   336,   338,   260,   330,   331,
      87,   155,   158,   159,   160,   167,   171,   176,   183,   186,
     187,   189,   212,   222,   226,   233,   235,   244,   246,   284,
     287,   418,   419,   420,   421,   423,   460,   327,   328,   324,
     325,   279,   322,   274,   259,   195,   195,   195,   195,   180,
     260,   180,   432,   180,   260,   274,   206,   274,   428,   211,
     459,   468,   195,   274,     6,   195,   195,   469,   169,   202,
     210,   227,   241,   250,   261,   435,   436,   470,   402,   475,
     469,   195,   195,   195,   239,   249,   402,   477,   478,   195,
     469,   195,   195,   469,   469,   195,   195,   195,   195,   514,
     405,   195,   514,     3,   277,   255,   436,   436,   143,   164,
     172,   173,   178,   188,   191,   193,   204,   205,   225,   243,
     268,   275,   281,   282,   412,   414,   206,   274,    63,    94,
      95,    96,    97,    98,    99,   228,   237,   266,   271,   482,
     106,   346,   347,   491,   215,   343,   468,   278,   274,   259,
     180,   260,   260,   240,   472,   473,   474,   475,   475,   180,
     260,   180,   296,   180,   260,   274,   428,   260,   204,   492,
     402,   278,   491,   491,   505,   491,     6,   491,   375,   377,
     429,   379,   429,   379,   180,   260,   336,   379,   402,   458,
     491,   180,   339,   180,   260,   195,   195,   195,   436,   436,
     195,   195,   195,   195,   195,   195,   195,   195,   128,   129,
     130,   184,   381,   383,   180,   260,   180,   260,   491,   491,
       6,   491,   316,   317,   491,   316,   316,   316,   145,   314,
     319,    70,    91,    92,   139,   275,   305,   306,   307,   429,
     228,   491,     3,   491,   470,   114,   371,   180,   475,   479,
     491,    21,   479,   479,   278,   471,   180,   180,   475,   481,
     507,   168,   213,   254,   416,   479,   475,   402,   477,   280,
     478,   479,   479,   479,   416,   479,   416,   416,   416,   403,
     404,   278,   195,   278,   410,   514,   410,   410,   410,   195,
     469,   216,   475,   410,   195,   469,   410,   142,   177,   179,
     475,     3,   195,   266,   271,   510,   512,   228,   286,   491,
     475,   475,   475,   475,   475,   418,   180,   260,   274,   344,
     441,   491,     6,   491,   429,   367,   366,   260,   463,   272,
     491,   300,   204,   295,   228,   491,   297,   300,   366,   274,
     274,   180,   260,   180,   260,   180,   380,   180,   180,   331,
       3,   424,   424,     3,   278,   195,   278,     3,   425,     3,
       3,     3,   425,   425,     3,     3,     6,   434,   118,   144,
     153,   168,   174,   213,   219,   374,   384,   385,   386,   387,
     328,   324,   274,   180,   260,   236,   257,   180,   180,   180,
     305,     3,     3,     4,   308,   307,   428,   190,   260,   274,
     471,   180,   260,   274,   180,   180,   169,   202,   210,   227,
     241,   250,   261,   437,   472,   260,   436,   480,   180,   480,
     475,   180,   247,   280,   180,   180,   180,   475,   180,   475,
     475,   475,   437,     3,   437,   197,   407,   197,   409,   197,
     408,   407,   266,   434,   484,   485,   507,   409,   484,   408,
     475,   510,   190,   228,   237,   260,   266,   267,   271,   511,
       3,   206,   274,   347,   491,   195,   274,   474,   495,   491,
     195,   274,   428,   115,   272,   360,   491,   491,   374,   429,
     429,   336,   180,   180,   180,   260,   437,     3,   437,   260,
     422,   180,   180,   260,   180,   180,   422,   180,   180,   376,
     488,   195,   386,   336,   491,    49,    50,   275,   283,   309,
     310,   311,   317,   309,   309,   309,   314,     3,   491,   472,
     475,   491,   195,   240,   395,   399,   436,   278,   180,   475,
     180,   180,   180,   180,   180,   411,   434,   411,   411,     3,
     493,   180,   260,   180,   255,   180,   510,   510,   510,   491,
     216,   348,   349,   475,   491,   399,   299,   491,   427,     3,
     180,     3,   426,   180,     3,   180,   195,   458,   308,     3,
     311,   190,   428,   399,   206,     3,   396,   398,   488,   170,
     200,   232,   393,   394,   400,   401,   455,   180,   278,   437,
     278,   485,   475,   190,   190,   260,   206,   180,   260,   231,
     465,   180,   428,   180,   278,   180,   377,   180,   510,   180,
      35,    42,   260,   272,   433,   491,     3,   270,   286,   430,
     431,   456,   457,   486,   491,   402,   402,   401,   393,   437,
     437,   510,   510,   349,   168,   213,   254,   417,   165,   229,
     450,   466,   437,   180,   190,   260,   195,   396,   397,   397,
     230,   398,   433,   431,   260,   274,   428,   190,   190,   260,
     211,   464,   467,   491,   273,   165,   510,   396,   276,   276,
     195,   398,   457,   228,   491,   510,   470,   145,   315,     3,
     430,   451,   452,   453,   467,   190,   180,   402,   402,   396,
     428,   190,   471,   260,   236,   257,   454,   315,   180,   472,
     452,   399,   465
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
#line 463 "sql.yacc"
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
#line 489 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 492 "sql.yacc"
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
#line 509 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 514 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 517 "sql.yacc"
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
#line 534 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 540 "sql.yacc"
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
#line 549 "sql.yacc"
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
#line 558 "sql.yacc"
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
#line 567 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 574 "sql.yacc"
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
#line 589 "sql.yacc"
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
#line 644 "sql.yacc"
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
#line 651 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 662 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 665 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 670 "sql.yacc"
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
#line 677 "sql.yacc"
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
#line 694 "sql.yacc"
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
#line 711 "sql.yacc"
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
#line 732 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 741 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 744 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 752 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 755 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 763 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 764 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 771 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 774 "sql.yacc"
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
#line 782 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 785 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 789 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 795 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 796 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 800 "sql.yacc"
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
#line 810 "sql.yacc"
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
#line 824 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 825 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 830 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 835 "sql.yacc"
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
#line 843 "sql.yacc"
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
#line 851 "sql.yacc"
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
#line 859 "sql.yacc"
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
#line 867 "sql.yacc"
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
#line 879 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 879 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 883 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 887 "sql.yacc"
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
#line 894 "sql.yacc"
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
#line 901 "sql.yacc"
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
#line 908 "sql.yacc"
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
#line 917 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 921 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 928 "sql.yacc"
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
#line 940 "sql.yacc"
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
#line 951 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 957 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 961 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 965 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 970 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 974 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 977 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 981 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 984 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 991 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 992 "sql.yacc"
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
#line 1002 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1003 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1008 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1012 "sql.yacc"
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
#line 1021 "sql.yacc"
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
#line 1030 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1037 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 1040 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 1046 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1049 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1060 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 1064 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1069 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1076 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1079 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1088 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1091 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1095 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1099 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1103 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1107 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1111 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1119 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1123 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1131 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1134 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1141 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1144 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1151 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1154 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1162 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1171 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1174 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1180 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1183 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1189 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1196 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1197 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1201 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1209 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1213 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1220 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1222 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1227 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1228 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1233 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1234 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1240 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1241 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1255 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1261 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1261 "sql.yacc"
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
#line 1270 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1270 "sql.yacc"
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
#line 1279 "sql.yacc"
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
#line 1304 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1307 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1315 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1318 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1325 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1328 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1336 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1337 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1343 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1344 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1352 "sql.yacc"
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
#line 1370 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1374 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1379 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1380 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1390 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1399 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1403 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1408 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1412 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1416 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1420 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1423 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1430 "sql.yacc"
    { (yyval.integer_val)=1; 
#ifndef  SQLCOMPILER
				set_cmdlineno(token_read_on_line);
#endif

}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1436 "sql.yacc"
    { (yyval.integer_val)=-1; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1441 "sql.yacc"
    { (yyval.integer_val)=0; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1449 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1450 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1451 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1452 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1453 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1454 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1455 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1463 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1464 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1465 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1466 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1476 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1477 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1478 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1482 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1483 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1490 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1493 "sql.yacc"
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
#line 1502 "sql.yacc"
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
#line 1513 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1515 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1521 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1527 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1537 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1544 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1546 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1552 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1555 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1556 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1563 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1572 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1579 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1591 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1597 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1602 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1606 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1612 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1620 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1625 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1628 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1631 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1638 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1639 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1640 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1641 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1647 "sql.yacc"
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
#line 1670 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1674 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1676 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1683 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1686 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1692 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1700 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1705 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1711 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1716 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1722 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1725 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1730 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1739 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1748 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1757 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1763 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1766 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1777 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1786 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1793 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1799 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1800 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1803 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1808 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1819 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1823 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1831 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1835 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1839 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1843 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1850 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1855 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1863 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1866 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1872 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1875 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1880 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1885 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1898 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1901 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1907 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1910 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1916 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1919 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1925 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1928 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1935 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1939 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1950 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1950 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1951 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1951 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1952 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1952 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1955 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1965 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1966 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1971 "sql.yacc"
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
#line 1980 "sql.yacc"
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
#line 1988 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1991 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1994 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1998 "sql.yacc"
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
#line 2005 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 2008 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 2012 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 2015 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 2018 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 2021 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 2027 "sql.yacc"
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
#line 2034 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 2037 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 2040 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 2043 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 2044 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 2049 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 2052 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 2055 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 2058 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 2065 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 2066 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 2067 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 2071 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2078 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 2079 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 2080 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 2084 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 2098 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2113 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2117 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2118 "sql.yacc"
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
#line 2127 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2129 "sql.yacc"
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
#line 2138 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2141 "sql.yacc"
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
#line 2149 "sql.yacc"
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
#line 2159 "sql.yacc"
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
#line 2167 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 2169 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 2170 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 2171 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 2172 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2173 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2174 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 2175 "sql.yacc"
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
#line 2183 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 2184 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2185 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2186 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2187 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2188 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2189 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2190 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2191 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2192 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2193 "sql.yacc"
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
#line 2203 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2204 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2211 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 2215 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 2240 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 2241 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 2245 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 2253 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 2256 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 2263 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 2266 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 2276 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 2279 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 2282 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 2285 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 2292 "sql.yacc"
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
#line 2299 "sql.yacc"
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
#line 2307 "sql.yacc"
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
#line 2316 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 2327 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2339 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2340 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 2350 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 2395 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2396 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2397 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2402 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2403 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 2411 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2418 "sql.yacc"
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
#line 2429 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2430 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2443 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2444 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2448 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2452 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2453 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2456 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2462 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2466 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2489 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2499 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2502 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2508 "sql.yacc"
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
#line 2517 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2521 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2528 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2530 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2532 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2536 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2542 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2545 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2551 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2552 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2559 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2572 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2582 "sql.yacc"
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
#line 2589 "sql.yacc"
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
#line 2606 "sql.yacc"
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
#line 2613 "sql.yacc"
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
#line 2638 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2640 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2642 "sql.yacc"
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
#line 2663 "sql.yacc"
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
#line 2706 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2707 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2721 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2724 "sql.yacc"
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
#line 2731 "sql.yacc"
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
#line 2741 "sql.yacc"
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
#line 2759 "sql.yacc"
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
#line 2772 "sql.yacc"
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
#line 2787 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2789 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2795 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2796 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2797 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2798 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2808 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item_list));
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2815 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2818 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2824 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2827 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2832 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2841 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2844 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2848 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2855 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2858 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2861 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2864 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2867 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2870 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2873 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2874 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2875 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2876 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2877 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2878 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2879 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2880 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2881 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2883 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2887 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2891 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2895 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2899 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2903 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2907 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2911 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2914 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2917 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2920 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2923 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2926 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2929 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2932 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2935 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2939 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2943 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2947 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2950 "sql.yacc"
    {
		(yyvsp[(3) - (4)].s_select_list_item)->data.s_select_list_item_data_u.sqlcase.master_condition=(yyvsp[(2) - (4)].s_select_list_item);
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2959 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 2962 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 2971 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 2977 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 2984 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 2987 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 3011 "sql.yacc"
    {(yyval.str_list)=NULL;}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 3012 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(2) - (4)].str));  add_str_list((yyval.str_list),(yyvsp[(4) - (4)].str));}
    break;

  case 506:

/* Line 1464 of yacc.c  */
#line 3013 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(1) - (3)].str));  add_str_list((yyval.str_list),(yyvsp[(3) - (3)].str));}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 3017 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 3020 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 3026 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 3027 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 3028 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 3029 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 3030 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 3031 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 3036 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 3040 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 3044 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 3048 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 3055 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 3058 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 3063 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 3064 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 3065 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3067 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3073 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3083 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3087 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3091 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3095 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3099 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3103 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3107 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3111 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3119 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3129 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3134 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3138 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3142 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3146 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3150 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3155 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3159 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3163 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3171 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3174 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3179 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3180 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3181 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 550:

/* Line 1464 of yacc.c  */
#line 3186 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3187 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 552:

/* Line 1464 of yacc.c  */
#line 3188 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 554:

/* Line 1464 of yacc.c  */
#line 3199 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 556:

/* Line 1464 of yacc.c  */
#line 3205 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 558:

/* Line 1464 of yacc.c  */
#line 3210 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 559:

/* Line 1464 of yacc.c  */
#line 3215 "sql.yacc"
    {(yyval.ptr_list)=0;}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3262 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3269 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 565:

/* Line 1464 of yacc.c  */
#line 3275 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3290 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1464 of yacc.c  */
#line 3291 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3293 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3295 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3298 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 574:

/* Line 1464 of yacc.c  */
#line 3302 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3311 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3317 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3318 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 579:

/* Line 1464 of yacc.c  */
#line 3321 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 3326 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 581:

/* Line 1464 of yacc.c  */
#line 3327 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3331 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3332 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3342 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3343 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3344 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3345 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3346 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3347 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3348 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3349 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3353 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3359 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3361 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3380 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3388 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3395 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3396 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3397 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3398 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3403 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3404 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3405 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3406 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3407 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 3412 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 3413 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 3429 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 3430 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 3431 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 3432 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 3433 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 3434 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 3435 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 3436 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3437 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3438 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 3440 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 3441 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 3442 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3443 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3448 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3451 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 3460 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3461 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3462 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 3463 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 3464 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 3465 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3469 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 632:

/* Line 1464 of yacc.c  */
#line 3470 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1464 of yacc.c  */
#line 8939 "y.tab.c"
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
#line 3484 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

