/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

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
     INT_VALUE = 2244,
     NAMED = 2245,
     NAMED_GEN = 2246,
     CHAR_VALUE = 2247,
     NOT_USED_1 = 2248,
     NOT_USED_2 = 2249,
     NOT_USED_3 = 2250,
     NOT_USED_4 = 2251,
     NOT_USED_5 = 2252,
     NOT_USED_6 = 2253,
     NOT_USED_7 = 2254,
     NOT_USED_8 = 2255,
     NUMBER_VALUE = 2256,
     SEMICOLON = 2257,
     QUESTION_MARK = 2258,
     CLINE = 2259,
     CH = 2260,
     MARK_VAR = 2261,
     END_MARK_VAR = 2262,
     WITH_LISTING_IN = 1001,
     SET_POSTGRESQL_SEARCH_PATH = 1002,
     SET_CONSTRAINTS_ALL_DEFERRED = 1003,
     KW_LIMIT = 1004,
     DOCUMENT = 1005,
     ON_EXCEPTION = 1007,
     SET_DEBUG_FILE_TO = 1008,
     CREATE_DBA_PROCEDURE = 1013,
     CREATE_FUNCTION = 1014,
     CREATE_DBA_FUNCTION = 1015,
     USE_SESSION = 1017,
     KW_RUN_CLIENT = 1018,
     LEFT_JOIN = 1020,
     IGNORE_ERRORS = 1023,
     SQLERRMESSAGE = 1024,
     DISPLAY_NULL_TO = 1025,
     UNBUFFERED = 1026,
     KW_PICTURE = 1027,
     ON_CHANGE = 1028,
     INNER_JOIN = 1029,
     UI_INTERFACE_DOT_FRONTCALL = 1032,
     UICOMBOBOX = 1036,
     UIFORM = 1039,
     USING_BTREE = 1055,
     USING_RTREE = 1056,
     SET_BUFFERED_LOG = 1075,
     SET_LOG = 1078,
     MDY = 1080,
     WEEKDAY = 1081,
     MODE_ANSI = 1084,
     START_DATABASE = 1085,
     WITH_LOG_IN = 1086,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1087,
     DATETIME_VALUE = 1100,
     INTERVAL_VALUE = 1101,
     RECOVER_TABLE = 1102,
     ROLLFORWARD_DATABASE = 1103,
     CONCAT_PIPES = 1117,
     DROP_TRIGGER = 1119,
     DROP_AUDIT_FOR = 1120,
     CREATE_AUDIT_FOR = 1121,
     EXECUTE_PROCEDURE = 1125,
     ALTER_TABLE = 1132,
     ALTER_INDEX = 1133,
     NEXT_SIZE = 1134,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1171,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1172,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1173,
     XSET_MULTIPLY_EQUAL = 1174,
     XSET_OPEN_BRACKET = 1175,
     CREATE_DATABASE = 1178,
     DROP_DATABASE = 1179,
     ADD_CONSTRAINT = 1181,
     DROP_CONSTRAINT = 1182,
     DROP_SYNONYM = 1183,
     CONSTRAINT = 1184,
     NOT_FIELD_TOUCHED_CURRENT = 1187,
     FIELD_TOUCHED_CURRENT = 1188,
     OBJECT_FUNCTION = 1190,
     DOUBLE_PRECISION = 1196,
     COUNT_MULTIPLY = 1197,
     MODIFY_NEXT_SIZE = 1217,
     LOCK_MODE_PAGE = 1218,
     LOCK_MODE_ROW = 1219,
     UNITS_YEAR = 1226,
     UNITS_MONTH = 1227,
     UNITS_DAY = 1228,
     UNITS_HOUR = 1229,
     UNITS_MINUTE = 1230,
     UNITS_SECOND = 1231,
     TO_CLUSTER = 1236,
     TO_NOT_CLUSTER = 1237,
     CREATE_UC_IDX = 1239,
     CREATE_U_IDX = 1240,
     CREATE_C_IDX = 1241,
     CREATE_IDX = 1242,
     DOUBLE_COLON = 1252,
     SQLSICS = 1258,
     CREATE_SCHEMA = 1259,
     SQLSIRR = 1260,
     UPDATESTATS_T = 1261,
     SQLSICR = 1262,
     SQLSIDR = 1273,
     CREATE_TEMP_TABLE = 1274,
     WITH_CHECK_OPTION = 1282,
     WITH_GRANT_OPTION = 1283,
     SQLSLMNW = 1284,
     WHERE_CURRENT_OF = 1290,
     NOT_NULL_UNIQUE = 1298,
     SQLSLMW = 1305,
     ALL_PRIVILEGES = 1307,
     CREATE_SYNONYM = 1311,
     DROP_TABLE = 1312,
     INEXCLUSIVE = 1314,
     UPDATESTATS = 1319,
     CREATE_TABLE = 1345,
     DEFAULT_NULL = 1346,
     DEFAULT_TODAY = 1347,
     DEFAULT_USER = 1348,
     EXIT_TODO = 1355,
     CONTINUE_TODO = 1356,
     UNLOCK_TABLE = 1363,
     ROLLBACK_W = 1371,
     SQLSEON = 1373,
     SQLSEOFF = 1374,
     CREATE_VIEW = 1378,
     DELETE_FROM = 1379,
     EXTENT_SIZE = 1386,
     FOREIGN_KEY = 1387,
     INSERT_INTO = 1390,
     IS_NOT_NULL = 1392,
     NOT_MATCHES = 1395,
     PRIMARY_KEY = 1401,
     WITH_NO_LOG = 1408,
     INSHARE = 1411,
     BEGIN_WORK = 1417,
     DROP_INDEX = 1422,
     FOR_UPDATE_OF = 1428,
     FOR_UPDATE = 1429,
     LOCK_TABLE = 1434,
     NOT_EXISTS = 1436,
     REFERENCES = 1438,
     RENCOL = 1439,
     SMALLFLOAT = 1441,
     COMMIT_W = 1452,
     RENTAB = 1459,
     KW_CHAR = 1462,
     NCHAR = 1463,
     NVARCHAR = 1464,
     DELIMITER = 1466,
     DROP_VIEW = 1468,
     EXCLUSIVE = 1471,
     GREATER_THAN_EQ = 1475,
     INTO_TEMP = 1477,
     DATABASE = 1501,
     DATETIME = 1502,
     DISTINCT = 1504,
     FRACTION = 1511,
     GROUP_BY = 1513,
     INTERVAL = 1514,
     NOT_LIKE = 1516,
     NOT_ILIKE = 1517,
     NOT_NULL = 1518,
     RESOURCE = 1524,
     SMALLINT = 1525,
     IS_NULL = 1531,
     LESS_THAN_EQ = 1532,
     BETWEEN = 1534,
     CLOSE_BRACKET = 1537,
     CONNECT = 1540,
     KW_CURRENT = 1541,
     KW_DECIMAL = 1543,
     DEFAULT = 1545,
     INTEGER = 1553,
     SERIAL8 = 1555,
     MATCHES = 1558,
     VARCHAR = 1571,
     CLOSE_SQUARE = 1574,
     GREATER_THAN = 1575,
     KW_FALSE = 1576,
     NOT_IN = 1577,
     OPEN_BRACKET = 1579,
     KW_DELETE = 1587,
     KW_ESCAPE = 1590,
     EXISTS = 1591,
     EXTEND = 1592,
     HAVING = 1596,
     KW_INSERT = 1598,
     MINUTE = 1602,
     MODIFY = 1603,
     EQUAL = 1605,
     NOT_EQUAL = 1606,
     OPEN_SQUARE = 1608,
     PUBLIC = 1612,
     KW_RETURN_KEY = 1615,
     REVOKE = 1617,
     SECOND = 1621,
     KW_SELECT = 1625,
     SERIAL = 1626,
     UNIQUE = 1629,
     KW_UPDATE = 1631,
     VALUES = 1632,
     KW_NULL = 1635,
     KW_TRUE = 1636,
     ALTER = 1638,
     CHECK = 1644,
     COUNT = 1648,
     KW_FIRST = 1653,
     KW_FLOAT = 1654,
     GRANT = 1657,
     INDEX = 1660,
     LESS_THAN = 1663,
     MONEY = 1665,
     MONTH = 1666,
     KW_MULTIPLY = 1668,
     ORDER = 1669,
     OUTER = 1670,
     UNION = 1679,
     WHERE = 1682,
     KW_BYTE = 1689,
     CASE = 1691,
     KW_DATE = 1693,
     DESC = 1694,
     KW_DIVIDE = 1695,
     DROP = 1698,
     ELSE = 1699,
     FROM = 1703,
     HOUR = 1709,
     INTO = 1710,
     LIKE = 1713,
     REAL = 1722,
     SOME = 1727,
     KW_TEXT = 1731,
     KW_THEN = 1732,
     USER = 1733,
     WHEN = 1735,
     YEAR = 1738,
     KW_DOW = 1739,
     XSET = 1741,
     ADD = 1742,
     ALL = 1743,
     KW_AND = 1744,
     ANY = 1745,
     ASC = 1746,
     AVG = 1747,
     COLON = 1748,
     KW_COMMA = 1749,
     DAY = 1750,
     DBA = 1751,
     KW_FOR = 1755,
     XMAX = 1760,
     XMIN = 1761,
     KW_MINUS = 1762,
     KW_MOD = 1763,
     KW_NOT = 1764,
     KW_SUM = 1771,
     ATSIGN = 1774,
     KW_PLUS = 1775,
     KW_AS = 1781,
     KW_BY = 1783,
     KW_DOT = 1784,
     KW_IN = 1787,
     KW_ON = 1789,
     KW_OR = 1790,
     KW_TO = 1791,
     BEFORE = 1829,
     END = 1833,
     TILDE = 1840,
     ILIKE = 1841,
     FILLFACTOR = 1844,
     TIME = 1849,
     KW_TODAY = 1856,
     KW_ROWID = 1857,
     TIMESTAMP = 2205,
     SET_TEXT_FORMAT = 2217,
     KW_TAG = 2227,
     LINTMODULEISLIBRARY = 2228,
     KW_PUBLIC = 2229,
     KW_PRIVATE = 2230,
     COPYBACK = 2231,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2232,
     REFERENCES_BLOBTYPE = 2233,
     SORT = 2234,
     KWPIPE = 2235,
     KW_DONE = 2236,
     END_TODO = 2237,
     KW_TODO = 2238,
     KW_ALWAYS = 2239,
     PROGRAM_TIMEOUT = 2240,
     USING_SQLTYPE = 2241,
     KW_OBJECT = 2242
   };
#endif
/* Tokens.  */
#define INT_VALUE 2244
#define NAMED 2245
#define NAMED_GEN 2246
#define CHAR_VALUE 2247
#define NOT_USED_1 2248
#define NOT_USED_2 2249
#define NOT_USED_3 2250
#define NOT_USED_4 2251
#define NOT_USED_5 2252
#define NOT_USED_6 2253
#define NOT_USED_7 2254
#define NOT_USED_8 2255
#define NUMBER_VALUE 2256
#define SEMICOLON 2257
#define QUESTION_MARK 2258
#define CLINE 2259
#define CH 2260
#define MARK_VAR 2261
#define END_MARK_VAR 2262
#define WITH_LISTING_IN 1001
#define SET_POSTGRESQL_SEARCH_PATH 1002
#define SET_CONSTRAINTS_ALL_DEFERRED 1003
#define KW_LIMIT 1004
#define DOCUMENT 1005
#define ON_EXCEPTION 1007
#define SET_DEBUG_FILE_TO 1008
#define CREATE_DBA_PROCEDURE 1013
#define CREATE_FUNCTION 1014
#define CREATE_DBA_FUNCTION 1015
#define USE_SESSION 1017
#define KW_RUN_CLIENT 1018
#define LEFT_JOIN 1020
#define IGNORE_ERRORS 1023
#define SQLERRMESSAGE 1024
#define DISPLAY_NULL_TO 1025
#define UNBUFFERED 1026
#define KW_PICTURE 1027
#define ON_CHANGE 1028
#define INNER_JOIN 1029
#define UI_INTERFACE_DOT_FRONTCALL 1032
#define UICOMBOBOX 1036
#define UIFORM 1039
#define USING_BTREE 1055
#define USING_RTREE 1056
#define SET_BUFFERED_LOG 1075
#define SET_LOG 1078
#define MDY 1080
#define WEEKDAY 1081
#define MODE_ANSI 1084
#define START_DATABASE 1085
#define WITH_LOG_IN 1086
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1087
#define DATETIME_VALUE 1100
#define INTERVAL_VALUE 1101
#define RECOVER_TABLE 1102
#define ROLLFORWARD_DATABASE 1103
#define CONCAT_PIPES 1117
#define DROP_TRIGGER 1119
#define DROP_AUDIT_FOR 1120
#define CREATE_AUDIT_FOR 1121
#define EXECUTE_PROCEDURE 1125
#define ALTER_TABLE 1132
#define ALTER_INDEX 1133
#define NEXT_SIZE 1134
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1171
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1172
#define XSET_ident_DOT_MULTIPLY_EQUAL 1173
#define XSET_MULTIPLY_EQUAL 1174
#define XSET_OPEN_BRACKET 1175
#define CREATE_DATABASE 1178
#define DROP_DATABASE 1179
#define ADD_CONSTRAINT 1181
#define DROP_CONSTRAINT 1182
#define DROP_SYNONYM 1183
#define CONSTRAINT 1184
#define NOT_FIELD_TOUCHED_CURRENT 1187
#define FIELD_TOUCHED_CURRENT 1188
#define OBJECT_FUNCTION 1190
#define DOUBLE_PRECISION 1196
#define COUNT_MULTIPLY 1197
#define MODIFY_NEXT_SIZE 1217
#define LOCK_MODE_PAGE 1218
#define LOCK_MODE_ROW 1219
#define UNITS_YEAR 1226
#define UNITS_MONTH 1227
#define UNITS_DAY 1228
#define UNITS_HOUR 1229
#define UNITS_MINUTE 1230
#define UNITS_SECOND 1231
#define TO_CLUSTER 1236
#define TO_NOT_CLUSTER 1237
#define CREATE_UC_IDX 1239
#define CREATE_U_IDX 1240
#define CREATE_C_IDX 1241
#define CREATE_IDX 1242
#define DOUBLE_COLON 1252
#define SQLSICS 1258
#define CREATE_SCHEMA 1259
#define SQLSIRR 1260
#define UPDATESTATS_T 1261
#define SQLSICR 1262
#define SQLSIDR 1273
#define CREATE_TEMP_TABLE 1274
#define WITH_CHECK_OPTION 1282
#define WITH_GRANT_OPTION 1283
#define SQLSLMNW 1284
#define WHERE_CURRENT_OF 1290
#define NOT_NULL_UNIQUE 1298
#define SQLSLMW 1305
#define ALL_PRIVILEGES 1307
#define CREATE_SYNONYM 1311
#define DROP_TABLE 1312
#define INEXCLUSIVE 1314
#define UPDATESTATS 1319
#define CREATE_TABLE 1345
#define DEFAULT_NULL 1346
#define DEFAULT_TODAY 1347
#define DEFAULT_USER 1348
#define EXIT_TODO 1355
#define CONTINUE_TODO 1356
#define UNLOCK_TABLE 1363
#define ROLLBACK_W 1371
#define SQLSEON 1373
#define SQLSEOFF 1374
#define CREATE_VIEW 1378
#define DELETE_FROM 1379
#define EXTENT_SIZE 1386
#define FOREIGN_KEY 1387
#define INSERT_INTO 1390
#define IS_NOT_NULL 1392
#define NOT_MATCHES 1395
#define PRIMARY_KEY 1401
#define WITH_NO_LOG 1408
#define INSHARE 1411
#define BEGIN_WORK 1417
#define DROP_INDEX 1422
#define FOR_UPDATE_OF 1428
#define FOR_UPDATE 1429
#define LOCK_TABLE 1434
#define NOT_EXISTS 1436
#define REFERENCES 1438
#define RENCOL 1439
#define SMALLFLOAT 1441
#define COMMIT_W 1452
#define RENTAB 1459
#define KW_CHAR 1462
#define NCHAR 1463
#define NVARCHAR 1464
#define DELIMITER 1466
#define DROP_VIEW 1468
#define EXCLUSIVE 1471
#define GREATER_THAN_EQ 1475
#define INTO_TEMP 1477
#define DATABASE 1501
#define DATETIME 1502
#define DISTINCT 1504
#define FRACTION 1511
#define GROUP_BY 1513
#define INTERVAL 1514
#define NOT_LIKE 1516
#define NOT_ILIKE 1517
#define NOT_NULL 1518
#define RESOURCE 1524
#define SMALLINT 1525
#define IS_NULL 1531
#define LESS_THAN_EQ 1532
#define BETWEEN 1534
#define CLOSE_BRACKET 1537
#define CONNECT 1540
#define KW_CURRENT 1541
#define KW_DECIMAL 1543
#define DEFAULT 1545
#define INTEGER 1553
#define SERIAL8 1555
#define MATCHES 1558
#define VARCHAR 1571
#define CLOSE_SQUARE 1574
#define GREATER_THAN 1575
#define KW_FALSE 1576
#define NOT_IN 1577
#define OPEN_BRACKET 1579
#define KW_DELETE 1587
#define KW_ESCAPE 1590
#define EXISTS 1591
#define EXTEND 1592
#define HAVING 1596
#define KW_INSERT 1598
#define MINUTE 1602
#define MODIFY 1603
#define EQUAL 1605
#define NOT_EQUAL 1606
#define OPEN_SQUARE 1608
#define PUBLIC 1612
#define KW_RETURN_KEY 1615
#define REVOKE 1617
#define SECOND 1621
#define KW_SELECT 1625
#define SERIAL 1626
#define UNIQUE 1629
#define KW_UPDATE 1631
#define VALUES 1632
#define KW_NULL 1635
#define KW_TRUE 1636
#define ALTER 1638
#define CHECK 1644
#define COUNT 1648
#define KW_FIRST 1653
#define KW_FLOAT 1654
#define GRANT 1657
#define INDEX 1660
#define LESS_THAN 1663
#define MONEY 1665
#define MONTH 1666
#define KW_MULTIPLY 1668
#define ORDER 1669
#define OUTER 1670
#define UNION 1679
#define WHERE 1682
#define KW_BYTE 1689
#define CASE 1691
#define KW_DATE 1693
#define DESC 1694
#define KW_DIVIDE 1695
#define DROP 1698
#define ELSE 1699
#define FROM 1703
#define HOUR 1709
#define INTO 1710
#define LIKE 1713
#define REAL 1722
#define SOME 1727
#define KW_TEXT 1731
#define KW_THEN 1732
#define USER 1733
#define WHEN 1735
#define YEAR 1738
#define KW_DOW 1739
#define XSET 1741
#define ADD 1742
#define ALL 1743
#define KW_AND 1744
#define ANY 1745
#define ASC 1746
#define AVG 1747
#define COLON 1748
#define KW_COMMA 1749
#define DAY 1750
#define DBA 1751
#define KW_FOR 1755
#define XMAX 1760
#define XMIN 1761
#define KW_MINUS 1762
#define KW_MOD 1763
#define KW_NOT 1764
#define KW_SUM 1771
#define ATSIGN 1774
#define KW_PLUS 1775
#define KW_AS 1781
#define KW_BY 1783
#define KW_DOT 1784
#define KW_IN 1787
#define KW_ON 1789
#define KW_OR 1790
#define KW_TO 1791
#define BEFORE 1829
#define END 1833
#define TILDE 1840
#define ILIKE 1841
#define FILLFACTOR 1844
#define TIME 1849
#define KW_TODAY 1856
#define KW_ROWID 1857
#define TIMESTAMP 2205
#define SET_TEXT_FORMAT 2217
#define KW_TAG 2227
#define LINTMODULEISLIBRARY 2228
#define KW_PUBLIC 2229
#define KW_PRIVATE 2230
#define COPYBACK 2231
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2232
#define REFERENCES_BLOBTYPE 2233
#define SORT 2234
#define KWPIPE 2235
#define KW_DONE 2236
#define END_TODO 2237
#define KW_TODO 2238
#define KW_ALWAYS 2239
#define PROGRAM_TIMEOUT 2240
#define USING_SQLTYPE 2241
#define KW_OBJECT 2242




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
#line 868 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 880 "y.tab.c"

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
#define YYNTOKENS  293
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  631
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1111

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2262

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
       2,    22,    23,    24,    25,    26,     2,    27,    28,     2,
       2,     2,     2,    29,    30,    31,     2,    32,    33,     2,
      34,     2,     2,    35,    36,    37,    38,    39,    40,    41,
       2,     2,    42,     2,     2,     2,    43,     2,     2,    44,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    45,    46,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    47,     2,     2,    48,     2,
      49,    50,     2,     2,    51,    52,    53,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,    56,    57,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    59,     2,    60,
      61,    62,     2,     2,     2,    63,     2,     2,     2,     2,
       2,     2,    64,    65,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,    68,    69,    70,    71,     2,     2,    72,    73,
       2,    74,    75,    76,    77,     2,     2,    78,    79,     2,
      80,     2,     2,     2,     2,     2,    81,    82,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    83,    84,    85,
       2,     2,     2,     2,     2,     2,    86,    87,    88,    89,
      90,    91,     2,     2,     2,     2,    92,    93,     2,    94,
      95,    96,    97,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    98,     2,     2,     2,     2,     2,    99,   100,
     101,   102,   103,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   104,   105,     2,     2,     2,     2,     2,
       2,     2,   106,   107,   108,     2,     2,     2,     2,     2,
     109,     2,     2,     2,     2,     2,     2,     2,   110,     2,
       2,     2,     2,     2,     2,   111,     2,   112,     2,     2,
       2,   113,   114,     2,   115,     2,     2,     2,     2,   116,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   117,   118,   119,   120,     2,
       2,     2,     2,     2,     2,   121,   122,     2,     2,     2,
       2,     2,     2,   123,     2,     2,     2,     2,     2,     2,
       2,   124,     2,   125,   126,     2,     2,     2,   127,   128,
       2,     2,     2,     2,     2,     2,   129,   130,     2,     2,
     131,     2,   132,     2,     2,   133,     2,     2,     2,     2,
       2,   134,     2,     2,     2,     2,     2,     2,   135,     2,
       2,   136,     2,     2,     2,     2,     2,   137,     2,     2,
       2,     2,   138,     2,     2,     2,     2,     2,   139,   140,
       2,     2,     2,     2,   141,     2,   142,     2,   143,   144,
       2,   145,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   146,     2,     2,     2,     2,     2,     2,   147,
       2,     2,   148,   149,   150,     2,   151,     2,   152,     2,
       2,   153,     2,     2,     2,   154,     2,   155,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   156,   157,     2,   158,     2,     2,     2,     2,     2,
       2,   159,     2,   160,   161,     2,   162,   163,   164,     2,
       2,     2,     2,     2,   165,   166,     2,     2,     2,     2,
       2,   167,   168,     2,   169,     2,     2,   170,     2,     2,
     171,   172,     2,   173,     2,   174,     2,     2,     2,     2,
       2,     2,     2,   175,     2,   176,     2,     2,   177,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   178,     2,     2,   179,   180,   181,   182,     2,   183,
       2,     2,     2,     2,     2,     2,     2,   184,     2,     2,
     185,   186,   187,     2,     2,     2,   188,     2,   189,     2,
       2,     2,   190,   191,     2,   192,   193,     2,   194,     2,
       2,     2,   195,     2,     2,   196,     2,   197,     2,     2,
       2,   198,     2,     2,     2,   199,   200,     2,     2,   201,
       2,   202,   203,     2,     2,   204,   205,     2,   206,     2,
       2,     2,     2,     2,   207,     2,     2,     2,   208,     2,
       2,     2,     2,   209,   210,     2,     2,   211,     2,     2,
     212,     2,     2,   213,     2,   214,   215,     2,   216,   217,
     218,     2,     2,     2,     2,     2,     2,     2,     2,   219,
       2,     2,   220,     2,     2,     2,     2,     2,     2,   221,
       2,   222,     2,   223,   224,   225,     2,     2,   226,   227,
       2,     2,     2,   228,     2,     2,     2,     2,     2,   229,
     230,     2,     2,   231,     2,     2,     2,     2,     2,     2,
       2,     2,   232,     2,     2,     2,     2,   233,     2,     2,
       2,   234,   235,   236,     2,   237,     2,     2,   238,   239,
       2,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,     2,     2,     2,   251,     2,     2,     2,     2,
     252,   253,   254,   255,   256,     2,     2,     2,     2,     2,
       2,   257,     2,     2,   258,   259,     2,     2,     2,     2,
       2,   260,     2,   261,   262,     2,     2,   263,     2,   264,
     265,   266,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   267,
       2,     2,     2,   268,     2,     2,     2,     2,     2,     2,
     269,   270,     2,     2,   271,     2,     2,     2,     2,   272,
       2,     2,     2,     2,     2,     2,   273,   274,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   275,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   276,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21
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
    1308,  1312,  1313,  1315,  1320,  1324,  1326,  1332,  1340,  1341,
    1344,  1345,  1347,  1349,  1351,  1353,  1355,  1359,  1361,  1364,
    1368,  1370,  1373,  1376,  1380,  1383,  1387,  1391,  1395,  1399,
    1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1417,  1423,
    1429,  1435,  1441,  1447,  1451,  1456,  1461,  1466,  1471,  1476,
    1481,  1486,  1491,  1495,  1500,  1502,  1504,  1508,  1510,  1513,
    1518,  1521,  1523,  1527,  1528,  1533,  1537,  1538,  1541,  1544,
    1546,  1548,  1550,  1552,  1554,  1556,  1562,  1566,  1572,  1576,
    1578,  1582,  1584,  1586,  1589,  1592,  1594,  1596,  1600,  1602,
    1606,  1612,  1616,  1622,  1630,  1632,  1636,  1640,  1642,  1644,
    1648,  1654,  1658,  1664,  1672,  1676,  1678,  1680,  1684,  1690,
    1694,  1700,  1708,  1710,  1712,  1714,  1717,  1719,  1721,  1722,
    1724,  1726,  1730,  1732,  1734,  1736,  1737,  1739,  1741,  1743,
    1745,  1747,  1749,  1751,  1754,  1756,  1758,  1759,  1761,  1764,
    1766,  1770,  1772,  1776,  1782,  1784,  1786,  1789,  1791,  1793,
    1795,  1797,  1799,  1801,  1803,  1805,  1809,  1813,  1817,  1821,
    1823,  1826,  1828,  1830,  1832,  1834,  1836,  1838,  1840,  1842,
    1846,  1850,  1854,  1860,  1866,  1871,  1878,  1887,  1896,  1903,
    1912,  1923,  1934,  1936,  1940,  1942,  1944,  1946,  1949,  1952,
    1955,  1956
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     501,     0,    -1,   202,   492,   297,   295,    -1,    -1,   109,
     496,    -1,   220,   406,    -1,    -1,   109,   496,    -1,   220,
     406,    -1,    71,   302,   170,   192,   183,   303,   170,    -1,
      67,   303,   170,    -1,    68,   303,   170,    -1,   240,   298,
      -1,    70,   303,    -1,    69,   303,    -1,   301,    -1,   298,
     248,   301,    -1,   300,    -1,   258,   300,    -1,   495,   432,
      -1,   495,   262,   495,   432,    -1,   495,   262,   495,   262,
     495,   432,    -1,   495,   262,   216,    -1,   299,   192,   304,
      -1,   299,    -1,   302,   248,   299,    -1,   304,    -1,   303,
     248,   304,    -1,   479,    -1,   204,    -1,   306,    -1,   114,
     492,    -1,   152,   492,    -1,   138,   494,    -1,    60,   495,
      -1,   317,    -1,   308,    -1,   117,   492,   183,   322,   170,
     309,    -1,   105,   492,   183,   322,   170,   318,   309,   318,
      -1,    -1,   310,    -1,   311,    -1,   310,   311,    -1,   263,
     312,    -1,   129,     3,    -1,    66,     3,    -1,    84,    -1,
      85,    -1,     4,    -1,    -1,   314,    -1,   315,    -1,   314,
     315,    -1,   263,   312,    -1,   271,     3,    -1,    45,    -1,
      46,    -1,   492,    -1,    95,   494,   264,   316,   183,   320,
     170,   313,    -1,    94,   494,   264,   316,   183,   320,   170,
     313,    -1,    96,   494,   264,   316,   183,   320,   170,   313,
      -1,    97,   494,   264,   316,   183,   320,   170,   313,    -1,
      72,   505,    -1,    73,   505,    -1,   113,   492,   251,   492,
      -1,    62,   492,   263,     6,    -1,    61,   492,    -1,    76,
     492,    -1,    57,   492,    -1,    58,   495,    -1,    -1,   135,
      -1,    -1,   135,    -1,   321,    -1,   320,   248,   321,    -1,
     495,   245,    -1,   495,   224,    -1,   495,    -1,   323,    -1,
     322,   248,   323,    -1,   386,    -1,   384,    -1,    64,   495,
     325,    -1,    65,   494,    92,    -1,    65,   494,    93,    -1,
     326,    -1,   325,   248,   326,    -1,   327,    -1,   330,    -1,
     333,    -1,   338,    -1,   341,    -1,   337,    -1,   336,    -1,
     241,   328,    -1,   241,   183,   329,   170,    -1,   323,    -1,
     323,   267,   495,    -1,   328,    -1,   329,   248,   328,    -1,
     226,   332,    -1,   226,   183,   331,   170,    -1,   332,    -1,
     331,   248,   332,    -1,   495,    -1,   191,   335,    -1,   191,
     183,   334,   170,    -1,   335,    -1,   334,   248,   335,    -1,
     323,    -1,    84,    -1,    85,    -1,    83,     3,    -1,    74,
     384,   340,    -1,    74,   183,   339,   170,    -1,   384,   340,
      -1,   339,   248,   384,   340,    -1,    -1,    77,   495,    -1,
      75,   342,    -1,    75,   183,   342,   170,    -1,   343,    -1,
     342,   248,   343,    -1,   495,    -1,   124,    -1,    -1,   131,
     346,   492,   349,   347,    -1,    -1,   203,   348,   183,   352,
     170,    -1,   472,    -1,    -1,   183,   350,   170,    -1,   351,
      -1,   350,   248,   351,    -1,   495,    -1,   495,   262,   495,
      -1,   353,    -1,   352,   248,   353,    -1,   479,    -1,   204,
      -1,   128,   492,   296,    -1,   137,    -1,   146,    -1,    -1,
     153,    -1,   359,    -1,    52,   495,    53,     6,    51,    -1,
      52,   495,    53,     6,    -1,    54,    -1,    47,    -1,    48,
      -1,   102,   495,    -1,   116,    -1,   356,    -1,   355,    -1,
     344,    -1,   358,    -1,   392,    -1,   396,    -1,   442,    -1,
     305,    -1,   307,    -1,   324,    -1,   211,   365,   264,   492,
     266,   370,   364,    -1,   197,   365,   264,   492,   228,   370,
      -1,   211,   363,   266,   370,    -1,   197,   363,   228,   370,
      -1,   171,    -1,   165,    -1,   250,    -1,    -1,   107,    -1,
     260,   431,    -1,   112,    -1,   242,    -1,   366,    -1,   367,
      -1,   366,   248,   367,    -1,   199,   368,    -1,   189,    -1,
     184,    -1,   202,   368,    -1,   206,    -1,   212,    -1,    -1,
     183,   369,   170,    -1,   433,    -1,   369,   248,   433,    -1,
     371,    -1,   370,   248,   371,    -1,   195,    -1,   431,    -1,
     127,   492,   373,   260,   463,   375,    -1,    -1,   183,   374,
     170,    -1,   433,    -1,   374,   248,   433,    -1,    -1,   106,
      -1,   207,   183,   462,   170,    -1,   130,   183,   379,   170,
     378,    -1,   143,   380,    -1,   381,    -1,   492,    -1,   492,
     183,   381,   170,    -1,   433,    -1,   381,   248,   433,    -1,
     201,   183,   383,   170,    -1,   158,   183,   383,   170,    -1,
     134,   183,   383,   170,    -1,   433,    -1,   383,   248,   433,
      -1,   382,    -1,   377,    -1,   376,    -1,   174,   438,    -1,
     120,    -1,   119,    -1,   118,    -1,   495,   422,   387,   388,
      -1,    -1,   385,    -1,    -1,   389,    -1,   390,    -1,   389,
     390,    -1,   391,   340,    -1,   164,    -1,   110,    -1,   201,
      -1,   158,    -1,   378,    -1,   207,   183,   462,   170,    -1,
     134,    -1,   100,   393,   395,    -1,   394,    -1,   431,    -1,
     396,    -1,   395,   396,    -1,   372,    -1,   362,    -1,   188,
     406,    -1,   220,   406,    -1,   228,   400,    -1,   402,    -1,
     400,   248,   402,    -1,   400,   248,   218,   402,    -1,   400,
     248,   218,   183,   400,   170,    -1,   400,    34,   401,   264,
     406,    -1,   400,    41,   401,   264,   406,    -1,   400,    -1,
     183,   400,   170,    -1,   492,    -1,   492,   437,    -1,   492,
     260,   437,    -1,    -1,   399,   404,    -1,   405,    -1,   398,
     405,    -1,    -1,   459,    -1,   459,   397,    -1,   397,    -1,
     407,    -1,   406,   265,   407,    -1,   408,    -1,   407,   243,
     408,    -1,   409,    -1,   256,   409,    -1,   419,    -1,   183,
     406,   170,    -1,   186,   473,    -1,   142,   473,    -1,    -1,
     185,   415,    -1,    -1,   185,   415,    -1,    -1,   185,   415,
      -1,   518,    -1,   438,    -1,    -1,   256,    -1,   479,   416,
     167,    -1,   479,   416,   132,    -1,   479,   418,   479,    -1,
     479,   192,   479,    -1,   479,   192,   204,    -1,   479,   416,
     169,   479,   243,   479,    -1,   479,   231,   414,   413,    -1,
     479,   162,   414,   413,    -1,   479,   270,   414,   412,    -1,
     479,   163,   414,   412,    -1,   479,   177,   414,   411,    -1,
     479,   133,   414,   411,    -1,   193,    -1,   213,    -1,   180,
      -1,   269,    -1,   168,    -1,   154,    -1,   417,    -1,   487,
      -1,   410,    -1,   479,    -1,    -1,   242,    -1,   158,    -1,
     201,    -1,    -1,   242,    -1,   158,    -1,   201,    -1,   423,
      -1,   424,    -1,   425,    -1,   427,    -1,   148,    -1,   148,
     183,   428,   170,    -1,   200,    -1,   200,   183,     3,   170,
      -1,   176,    -1,   176,   183,     3,   170,    -1,   173,    -1,
     173,   183,   429,   426,   170,    -1,   214,   183,   429,   426,
     170,    -1,   214,    -1,   223,    -1,   175,    -1,   166,    -1,
     149,    -1,   149,   183,   428,   170,    -1,   150,    -1,   150,
     183,     3,   170,    -1,   150,   183,     3,   248,     3,   170,
      -1,   157,   440,   266,   441,    -1,   157,    -1,   161,   440,
     266,   441,    -1,   464,    -1,   161,    -1,   161,   440,   183,
       3,   170,   266,   441,    -1,   234,    -1,   221,    -1,   178,
      -1,   178,   183,     3,   170,    -1,   178,   183,     3,   248,
       3,   170,    -1,    -1,   248,   430,    -1,   210,   183,   429,
     170,    -1,   232,    -1,   145,    -1,   210,    -1,    81,    -1,
       3,    -1,     3,    -1,     3,    -1,   495,    -1,     6,    -1,
      -1,   194,     3,   179,    -1,   194,     3,   248,     3,   179,
      -1,   436,    -1,   258,   436,    -1,   435,    -1,   258,   435,
      -1,   495,   432,    -1,   490,   262,   495,   432,    -1,   490,
     262,   216,    -1,   274,    -1,   495,   432,    -1,   490,   262,
     495,   432,    -1,   495,   262,   495,   262,   495,   432,    -1,
     490,   262,   216,    -1,   495,    -1,     6,    -1,   497,    -1,
       3,    -1,   453,    -1,    -1,   440,   266,   441,    -1,   238,
      -1,   215,    -1,   249,    -1,   229,    -1,   190,    -1,   198,
      -1,   159,    -1,   238,    -1,   215,    -1,   249,    -1,   229,
      -1,   190,    -1,   198,    -1,   159,    -1,   159,   183,     3,
     170,    -1,   447,    -1,   446,    -1,   443,    -1,   147,   444,
     266,   444,    -1,   144,   490,   262,   445,   266,   445,    -1,
     495,    -1,   495,    -1,   123,   492,    -1,   141,   492,   448,
      -1,   136,    -1,   115,    -1,   450,    -1,   450,   440,   266,
     441,    -1,    55,    -1,   452,    -1,   452,   440,   183,     3,
     170,   266,   441,    -1,   452,   440,   266,   441,    -1,    56,
      -1,   172,   439,    -1,   217,   261,   455,    -1,   456,    -1,
     455,   248,   456,    -1,   457,   458,    -1,     3,    -1,   434,
      -1,    -1,   245,    -1,   224,    -1,   160,   460,    -1,   461,
      -1,   460,   248,   461,    -1,   434,    -1,     3,    -1,   406,
      -1,   472,    -1,   272,    -1,   272,   183,     3,   170,    -1,
     275,    -1,   275,   183,     3,   170,    -1,    -1,    -1,   199,
     474,   475,   466,   476,   467,   499,   403,   469,   470,    -1,
     199,   474,   475,   476,   403,   469,    -1,    -1,   219,   421,
     468,    -1,    -1,   454,    -1,   454,   155,   471,   319,    -1,
     155,   471,   319,    -1,   495,    -1,   199,   474,   475,   476,
     403,    -1,   183,   199,   474,   475,   476,   403,   170,    -1,
      -1,   209,     3,    -1,    -1,   242,    -1,   158,    -1,   201,
      -1,   477,    -1,   478,    -1,   476,   248,   478,    -1,   479,
      -1,   479,   495,    -1,   479,   260,   495,    -1,   518,    -1,
     254,   518,    -1,   259,   518,    -1,   518,   225,   479,    -1,
     518,   486,    -1,   518,   216,   479,    -1,   518,   259,   479,
      -1,   518,   254,   479,    -1,   518,    59,   479,    -1,   438,
      -1,   205,    -1,   181,    -1,   236,    -1,   273,    -1,   274,
      -1,   272,    -1,   216,    -1,    82,    -1,   246,   183,   420,
     479,   170,    -1,   252,   183,   420,   479,   170,    -1,   253,
     183,   420,   479,   170,    -1,   257,   183,   420,   479,   170,
      -1,   208,   183,   420,   479,   170,    -1,     4,   183,   170,
      -1,     4,   183,   483,   170,    -1,   238,   183,   483,   170,
      -1,   215,   183,   483,   170,    -1,   249,   183,   483,   170,
      -1,    49,   183,   483,   170,    -1,    50,   183,   483,   170,
      -1,   239,   183,   483,   170,    -1,   223,   183,   483,   170,
      -1,   183,   479,   170,    -1,   187,   183,   485,   170,    -1,
     449,    -1,   451,    -1,   222,   481,   268,    -1,   482,    -1,
     481,   482,    -1,   237,   406,   235,   479,    -1,   227,   479,
      -1,   479,    -1,   483,   248,   479,    -1,    -1,   248,   440,
     266,   441,    -1,   440,   266,   441,    -1,    -1,   511,   484,
      -1,   479,   484,    -1,    86,    -1,    87,    -1,    88,    -1,
      89,    -1,    90,    -1,    91,    -1,   479,   263,   183,   488,
     170,    -1,   479,   263,   473,    -1,   479,   182,   183,   488,
     170,    -1,   479,   182,   473,    -1,   489,    -1,   488,   248,
     489,    -1,   511,    -1,   438,    -1,   254,     3,    -1,   254,
     497,    -1,   491,    -1,     6,    -1,     6,   262,   495,    -1,
     495,    -1,   495,   247,   495,    -1,   495,   247,     6,   262,
     495,    -1,   495,   258,   495,    -1,   495,   258,   495,   247,
     495,    -1,   495,   258,   495,   247,     6,   262,   495,    -1,
     493,    -1,     6,   262,   495,    -1,   495,   262,   495,    -1,
       6,    -1,   495,    -1,   495,   247,   495,    -1,   495,   247,
       6,   262,   495,    -1,   495,   258,   495,    -1,   495,   258,
     495,   247,   495,    -1,   495,   258,   495,   247,     6,   262,
     495,    -1,     6,   262,   495,    -1,     6,    -1,   495,    -1,
     495,   247,   495,    -1,   495,   247,     6,   262,   495,    -1,
     495,   258,   495,    -1,   495,   258,   495,   247,   495,    -1,
     495,   258,   495,   247,     6,   262,   495,    -1,     4,    -1,
       4,    -1,    15,    -1,   262,     3,    -1,     4,    -1,     6,
      -1,    -1,   495,    -1,   503,    -1,   501,    16,   503,    -1,
     345,    -1,   294,    -1,   354,    -1,    -1,   512,    -1,   361,
      -1,   504,    -1,   510,    -1,   502,    -1,   360,    -1,     1,
      -1,   506,   507,    -1,   500,    -1,   465,    -1,    -1,   140,
      -1,   139,   508,    -1,   509,    -1,   508,   248,   509,    -1,
     495,    -1,   495,   262,   495,    -1,     6,   262,   495,   262,
     495,    -1,   126,    -1,   125,    -1,   111,   520,    -1,   108,
      -1,   104,    -1,   101,    -1,    99,    -1,   103,    -1,   517,
      -1,    17,    -1,   513,    -1,   156,   498,   357,    -1,    20,
       6,    21,    -1,   183,   514,   170,    -1,   514,   515,   514,
      -1,     3,    -1,   516,     3,    -1,   259,    -1,   254,    -1,
     216,    -1,   225,    -1,   255,    -1,   259,    -1,   254,    -1,
     495,    -1,   495,   262,   216,    -1,   495,   262,   274,    -1,
     495,   262,   495,    -1,   495,   262,   495,   262,   495,    -1,
       6,   262,   495,   262,   495,    -1,   495,   194,   514,   179,
      -1,   495,   262,   495,   194,   514,   179,    -1,   495,   262,
     495,   262,   495,   194,   514,   179,    -1,     6,   262,   495,
     262,   495,   194,   514,   179,    -1,   495,   194,   514,   248,
     514,   179,    -1,   495,   262,   495,   194,   514,   248,   514,
     179,    -1,   495,   262,   495,   262,   495,   194,   514,   248,
     514,   179,    -1,     6,   262,   495,   262,   495,   194,   514,
     248,   514,   179,    -1,   519,    -1,   519,    98,   422,    -1,
     480,    -1,   511,    -1,   473,    -1,   242,   473,    -1,   244,
     473,    -1,   233,   473,    -1,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   467,   467,   493,   496,   513,   518,   521,   538,   544,
     553,   562,   571,   578,   593,   648,   655,   666,   669,   674,
     681,   698,   715,   736,   745,   748,   756,   759,   767,   768,
     775,   778,   786,   789,   793,   799,   800,   804,   814,   828,
     829,   833,   834,   839,   847,   855,   863,   871,   881,   883,
     883,   886,   887,   891,   898,   905,   912,   921,   925,   932,
     944,   955,   961,   965,   969,   974,   978,   981,   985,   988,
     995,   996,  1006,  1007,  1011,  1012,  1016,  1025,  1034,  1041,
    1044,  1050,  1053,  1064,  1068,  1073,  1080,  1083,  1092,  1095,
    1099,  1103,  1107,  1111,  1115,  1123,  1127,  1135,  1138,  1145,
    1148,  1155,  1158,  1165,  1166,  1171,  1175,  1178,  1184,  1187,
    1193,  1200,  1201,  1205,  1213,  1217,  1224,  1226,  1231,  1232,
    1236,  1238,  1244,  1245,  1248,  1259,  1265,  1265,  1274,  1274,
    1283,  1308,  1311,  1319,  1322,  1329,  1332,  1340,  1341,  1347,
    1348,  1356,  1374,  1378,  1383,  1384,  1394,  1403,  1407,  1411,
    1416,  1420,  1424,  1427,  1434,  1435,  1436,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1454,  1455,  1456,  1457,  1462,  1463,
    1464,  1467,  1468,  1469,  1473,  1474,  1475,  1479,  1480,  1484,
    1491,  1492,  1493,  1500,  1501,  1504,  1505,  1510,  1511,  1516,
    1517,  1522,  1523,  1528,  1535,  1536,  1541,  1542,  1546,  1547,
    1554,  1562,  1569,  1576,  1580,  1581,  1586,  1587,  1593,  1597,
    1602,  1609,  1610,  1616,  1619,  1622,  1629,  1630,  1631,  1632,
    1638,  1661,  1662,  1665,  1667,  1674,  1677,  1683,  1691,  1696,
    1702,  1707,  1713,  1716,  1721,  1729,  1738,  1743,  1747,  1748,
    1754,  1757,  1768,  1777,  1784,  1790,  1791,  1794,  1799,  1810,
    1814,  1821,  1822,  1826,  1830,  1834,  1841,  1846,  1854,  1857,
    1863,  1866,  1871,  1876,  1889,  1892,  1898,  1901,  1907,  1910,
    1916,  1919,  1926,  1930,  1941,  1941,  1942,  1942,  1943,  1943,
    1946,  1951,  1956,  1957,  1962,  1971,  1979,  1982,  1985,  1989,
    1996,  1999,  2003,  2006,  2009,  2012,  2018,  2025,  2028,  2031,
    2034,  2035,  2040,  2043,  2046,  2049,  2056,  2057,  2058,  2062,
    2069,  2070,  2071,  2075,  2089,  2096,  2097,  2098,  2102,  2103,
    2108,  2109,  2118,  2120,  2129,  2132,  2140,  2150,  2158,  2160,
    2161,  2162,  2163,  2164,  2165,  2166,  2174,  2175,  2176,  2177,
    2178,  2179,  2180,  2181,  2182,  2183,  2184,  2194,  2195,  2201,
    2203,  2204,  2205,  2206,  2210,  2214,  2218,  2225,  2226,  2231,
    2232,  2236,  2244,  2247,  2254,  2257,  2267,  2270,  2273,  2276,
    2283,  2290,  2298,  2307,  2314,  2318,  2323,  2324,  2325,  2330,
    2331,  2340,  2340,  2340,  2340,  2340,  2340,  2340,  2341,  2341,
    2341,  2341,  2341,  2341,  2341,  2341,  2386,  2387,  2388,  2393,
    2394,  2397,  2398,  2402,  2409,  2420,  2421,  2434,  2435,  2439,
    2443,  2444,  2447,  2453,  2457,  2480,  2490,  2493,  2499,  2508,
    2512,  2519,  2520,  2522,  2527,  2533,  2536,  2542,  2543,  2550,
    2563,  2573,  2580,  2597,  2604,  2629,  2631,  2629,  2653,  2697,
    2698,  2712,  2715,  2722,  2732,  2744,  2750,  2763,  2778,  2780,
    2786,  2787,  2788,  2789,  2799,  2806,  2809,  2815,  2818,  2823,
    2832,  2835,  2839,  2846,  2849,  2852,  2855,  2858,  2861,  2864,
    2865,  2866,  2867,  2868,  2869,  2870,  2871,  2872,  2874,  2878,
    2882,  2886,  2890,  2894,  2898,  2902,  2905,  2908,  2911,  2914,
    2917,  2920,  2923,  2926,  2930,  2934,  2938,  2946,  2949,  2958,
    2964,  2971,  2974,  2998,  2999,  3000,  3003,  3004,  3007,  3013,
    3014,  3015,  3016,  3017,  3018,  3023,  3027,  3031,  3035,  3042,
    3045,  3050,  3051,  3052,  3054,  3060,  3070,  3074,  3078,  3082,
    3086,  3090,  3094,  3098,  3106,  3116,  3121,  3125,  3129,  3133,
    3137,  3142,  3146,  3150,  3158,  3161,  3166,  3167,  3168,  3173,
    3174,  3175,  3183,  3186,  3191,  3192,  3196,  3197,  3202,  3226,
    3243,  3244,  3248,  3255,  3261,  3271,  3273,  3276,  3277,  3278,
    3279,  3281,  3284,  3288,  3293,  3297,  3303,  3304,  3307,  3312,
    3313,  3316,  3317,  3318,  3328,  3329,  3330,  3331,  3332,  3333,
    3334,  3335,  3339,  3345,  3347,  3366,  3374,  3381,  3382,  3383,
    3384,  3389,  3390,  3391,  3392,  3393,  3398,  3399,  3415,  3416,
    3417,  3418,  3419,  3420,  3421,  3422,  3423,  3424,  3426,  3427,
    3428,  3429,  3434,  3437,  3446,  3447,  3448,  3449,  3450,  3451,
    3455,  3456
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
  "WITH_LISTING_IN", "SET_POSTGRESQL_SEARCH_PATH",
  "SET_CONSTRAINTS_ALL_DEFERRED", "KW_LIMIT", "DOCUMENT", "ON_EXCEPTION",
  "SET_DEBUG_FILE_TO", "CREATE_DBA_PROCEDURE", "CREATE_FUNCTION",
  "CREATE_DBA_FUNCTION", "USE_SESSION", "KW_RUN_CLIENT", "LEFT_JOIN",
  "IGNORE_ERRORS", "SQLERRMESSAGE", "DISPLAY_NULL_TO", "UNBUFFERED",
  "KW_PICTURE", "ON_CHANGE", "INNER_JOIN", "UI_INTERFACE_DOT_FRONTCALL",
  "UICOMBOBOX", "UIFORM", "USING_BTREE", "USING_RTREE", "SET_BUFFERED_LOG",
  "SET_LOG", "MDY", "WEEKDAY", "MODE_ANSI", "START_DATABASE",
  "WITH_LOG_IN", "SET_CONSTRAINTS_ALL_IMMEDIATE", "DATETIME_VALUE",
  "INTERVAL_VALUE", "RECOVER_TABLE", "ROLLFORWARD_DATABASE",
  "CONCAT_PIPES", "DROP_TRIGGER", "DROP_AUDIT_FOR", "CREATE_AUDIT_FOR",
  "EXECUTE_PROCEDURE", "ALTER_TABLE", "ALTER_INDEX", "NEXT_SIZE",
  "XSET_MULTIPLY_EQUAL_OPEN_BRACKET",
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET",
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL",
  "XSET_OPEN_BRACKET", "CREATE_DATABASE", "DROP_DATABASE",
  "ADD_CONSTRAINT", "DROP_CONSTRAINT", "DROP_SYNONYM", "CONSTRAINT",
  "NOT_FIELD_TOUCHED_CURRENT", "FIELD_TOUCHED_CURRENT", "OBJECT_FUNCTION",
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "MODIFY_NEXT_SIZE",
  "LOCK_MODE_PAGE", "LOCK_MODE_ROW", "UNITS_YEAR", "UNITS_MONTH",
  "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", "TO_CLUSTER",
  "TO_NOT_CLUSTER", "CREATE_UC_IDX", "CREATE_U_IDX", "CREATE_C_IDX",
  "CREATE_IDX", "DOUBLE_COLON", "SQLSICS", "CREATE_SCHEMA", "SQLSIRR",
  "UPDATESTATS_T", "SQLSICR", "SQLSIDR", "CREATE_TEMP_TABLE",
  "WITH_CHECK_OPTION", "WITH_GRANT_OPTION", "SQLSLMNW", "WHERE_CURRENT_OF",
  "NOT_NULL_UNIQUE", "SQLSLMW", "ALL_PRIVILEGES", "CREATE_SYNONYM",
  "DROP_TABLE", "INEXCLUSIVE", "UPDATESTATS", "CREATE_TABLE",
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
  "KW_DECIMAL", "DEFAULT", "INTEGER", "SERIAL8", "MATCHES", "VARCHAR",
  "CLOSE_SQUARE", "GREATER_THAN", "KW_FALSE", "NOT_IN", "OPEN_BRACKET",
  "KW_DELETE", "KW_ESCAPE", "EXISTS", "EXTEND", "HAVING", "KW_INSERT",
  "MINUTE", "MODIFY", "EQUAL", "NOT_EQUAL", "OPEN_SQUARE", "PUBLIC",
  "KW_RETURN_KEY", "REVOKE", "SECOND", "KW_SELECT", "SERIAL", "UNIQUE",
  "KW_UPDATE", "VALUES", "KW_NULL", "KW_TRUE", "ALTER", "CHECK", "COUNT",
  "KW_FIRST", "KW_FLOAT", "GRANT", "INDEX", "LESS_THAN", "MONEY", "MONTH",
  "KW_MULTIPLY", "ORDER", "OUTER", "UNION", "WHERE", "KW_BYTE", "CASE",
  "KW_DATE", "DESC", "KW_DIVIDE", "DROP", "ELSE", "FROM", "HOUR", "INTO",
  "LIKE", "REAL", "SOME", "KW_TEXT", "KW_THEN", "USER", "WHEN", "YEAR",
  "KW_DOW", "XSET", "ADD", "ALL", "KW_AND", "ANY", "ASC", "AVG", "COLON",
  "KW_COMMA", "DAY", "DBA", "KW_FOR", "XMAX", "XMIN", "KW_MINUS", "KW_MOD",
  "KW_NOT", "KW_SUM", "ATSIGN", "KW_PLUS", "KW_AS", "KW_BY", "KW_DOT",
  "KW_IN", "KW_ON", "KW_OR", "KW_TO", "BEFORE", "END", "TILDE", "ILIKE",
  "FILLFACTOR", "TIME", "KW_TODAY", "KW_ROWID", "TIMESTAMP",
  "SET_TEXT_FORMAT", "KW_TAG", "LINTMODULEISLIBRARY", "KW_PUBLIC",
  "KW_PRIVATE", "COPYBACK", "REFERENCES_BLOBTYPE_DEFAULT_NULL",
  "REFERENCES_BLOBTYPE", "SORT", "KWPIPE", "KW_DONE", "END_TODO",
  "KW_TODO", "KW_ALWAYS", "PROGRAM_TIMEOUT", "USING_SQLTYPE", "KW_OBJECT",
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
       0,   256,  2243,  2244,  2245,  2246,  2247,  2248,  2249,  2250,
    2251,  2252,  2253,  2254,  2255,  2256,  2257,  2258,  2259,  2260,
    2261,  2262,  1001,  1002,  1003,  1004,  1005,  1007,  1008,  1013,
    1014,  1015,  1017,  1018,  1020,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1032,  1036,  1039,  1055,  1056,  1075,  1078,  1080,
    1081,  1084,  1085,  1086,  1087,  1100,  1101,  1102,  1103,  1117,
    1119,  1120,  1121,  1125,  1132,  1133,  1134,  1171,  1172,  1173,
    1174,  1175,  1178,  1179,  1181,  1182,  1183,  1184,  1187,  1188,
    1190,  1196,  1197,  1217,  1218,  1219,  1226,  1227,  1228,  1229,
    1230,  1231,  1236,  1237,  1239,  1240,  1241,  1242,  1252,  1258,
    1259,  1260,  1261,  1262,  1273,  1274,  1282,  1283,  1284,  1290,
    1298,  1305,  1307,  1311,  1312,  1314,  1319,  1345,  1346,  1347,
    1348,  1355,  1356,  1363,  1371,  1373,  1374,  1378,  1379,  1386,
    1387,  1390,  1392,  1395,  1401,  1408,  1411,  1417,  1422,  1428,
    1429,  1434,  1436,  1438,  1439,  1441,  1452,  1459,  1462,  1463,
    1464,  1466,  1468,  1471,  1475,  1477,  1501,  1502,  1504,  1511,
    1513,  1514,  1516,  1517,  1518,  1524,  1525,  1531,  1532,  1534,
    1537,  1540,  1541,  1543,  1545,  1553,  1555,  1558,  1571,  1574,
    1575,  1576,  1577,  1579,  1587,  1590,  1591,  1592,  1596,  1598,
    1602,  1603,  1605,  1606,  1608,  1612,  1615,  1617,  1621,  1625,
    1626,  1629,  1631,  1632,  1635,  1636,  1638,  1644,  1648,  1653,
    1654,  1657,  1660,  1663,  1665,  1666,  1668,  1669,  1670,  1679,
    1682,  1689,  1691,  1693,  1694,  1695,  1698,  1699,  1703,  1709,
    1710,  1713,  1722,  1727,  1731,  1732,  1733,  1735,  1738,  1739,
    1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,
    1751,  1755,  1760,  1761,  1762,  1763,  1764,  1771,  1774,  1775,
    1781,  1783,  1784,  1787,  1789,  1790,  1791,  1829,  1833,  1840,
    1841,  1844,  1849,  1856,  1857,  2205,  2217,  2227,  2228,  2229,
    2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239,
    2240,  2241,  2242
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   293,   294,   295,   295,   295,   296,   296,   296,   297,
     297,   297,   297,   297,   297,   298,   298,   299,   299,   300,
     300,   300,   300,   301,   302,   302,   303,   303,   304,   304,
     305,   306,   306,   306,   306,   307,   307,   308,   308,   309,
     309,   310,   310,   311,   311,   311,   311,   311,   312,   313,
     313,   314,   314,   315,   315,   315,   315,   316,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   318,   319,   319,   320,   320,   321,   321,   321,   322,
     322,   323,   323,   324,   324,   324,   325,   325,   326,   326,
     326,   326,   326,   326,   326,   327,   327,   328,   328,   329,
     329,   330,   330,   331,   331,   332,   333,   333,   334,   334,
     335,   336,   336,   337,   338,   338,   339,   339,   340,   340,
     341,   341,   342,   342,   343,   344,   346,   345,   348,   347,
     347,   349,   349,   350,   350,   351,   351,   352,   352,   353,
     353,   354,   355,   356,   357,   357,   358,   359,   359,   359,
     359,   359,   359,   359,   360,   360,   360,   361,   361,   361,
     361,   361,   361,   361,   362,   362,   362,   362,   363,   363,
     363,   364,   364,   364,   365,   365,   365,   366,   366,   367,
     367,   367,   367,   367,   367,   368,   368,   369,   369,   370,
     370,   371,   371,   372,   373,   373,   374,   374,   375,   375,
     376,   377,   378,   379,   380,   380,   381,   381,   382,   382,
     382,   383,   383,   384,   384,   384,   385,   385,   385,   385,
     386,   387,   387,   388,   388,   389,   389,   390,   391,   391,
     391,   391,   391,   391,   391,   392,   393,   394,   395,   395,
     396,   396,   397,   398,   399,   400,   400,   400,   400,   400,
     400,   401,   401,   402,   402,   402,   403,   403,   404,   404,
     405,   405,   405,   405,   406,   406,   407,   407,   408,   408,
     409,   409,   410,   410,   411,   411,   412,   412,   413,   413,
     414,   415,   416,   416,   417,   417,   417,   417,   417,   417,
     417,   417,   417,   417,   417,   417,   418,   418,   418,   418,
     418,   418,   419,   419,   419,   419,   420,   420,   420,   420,
     421,   421,   421,   421,   422,   423,   423,   423,   424,   424,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   426,   426,   427,
     427,   427,   427,   427,   428,   429,   430,   431,   431,   432,
     432,   432,   433,   433,   434,   434,   435,   435,   435,   435,
     436,   436,   436,   436,   437,   438,   438,   438,   438,   439,
     439,   440,   440,   440,   440,   440,   440,   440,   441,   441,
     441,   441,   441,   441,   441,   441,   442,   442,   442,   443,
     443,   444,   445,   446,   447,   448,   448,   449,   449,   450,
     451,   451,   451,   452,   453,   454,   455,   455,   456,   457,
     457,   458,   458,   458,   459,   460,   460,   461,   461,   462,
     463,   464,   464,   464,   464,   466,   467,   465,   468,   469,
     469,   470,   470,   470,   470,   471,   472,   473,   474,   474,
     475,   475,   475,   475,   476,   477,   477,   478,   478,   478,
     479,   479,   479,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   481,   481,   482,
     482,   483,   483,   484,   484,   484,   485,   485,   485,   486,
     486,   486,   486,   486,   486,   487,   487,   487,   487,   488,
     488,   489,   489,   489,   489,   490,   491,   491,   491,   491,
     491,   491,   491,   491,   492,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   494,   494,   494,   494,   494,   494,
     494,   494,   495,   496,   497,   497,   498,   498,   499,   500,
     501,   501,   502,   502,   502,   503,   503,   503,   503,   503,
     503,   503,   503,   504,   505,   506,   507,   507,   507,   508,
     508,   509,   509,   509,   510,   510,   510,   510,   510,   510,
     510,   510,   511,   511,   511,   512,   513,   514,   514,   514,
     514,   515,   515,   515,   515,   515,   516,   516,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   518,   518,   519,   519,   519,   519,   519,   519,
     520,   520
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
       3,     0,     1,     4,     3,     1,     5,     7,     0,     2,
       0,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     2,     3,     2,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     5,     5,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     4,     1,     1,     3,     1,     2,     4,
       2,     1,     3,     0,     4,     3,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     5,     3,     5,     3,     1,
       3,     1,     1,     2,     2,     1,     1,     3,     1,     3,
       5,     3,     5,     7,     1,     3,     3,     1,     1,     3,
       5,     3,     5,     7,     3,     1,     1,     3,     5,     3,
       5,     7,     1,     1,     1,     2,     1,     1,     0,     1,
       1,     3,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     0,     1,     2,     1,
       3,     1,     3,     5,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     5,     5,     4,     6,     8,     8,     6,     8,
      10,    10,     1,     3,     1,     1,     1,     2,     2,     2,
       0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   572,   150,   151,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     590,     0,   589,     0,   591,   588,     0,   587,   630,     0,
       0,   153,     0,     0,   125,   585,   584,     0,     0,   126,
     142,     0,     0,     0,   143,     0,     0,     0,     0,   448,
       0,     0,   563,   161,    30,   162,    36,    35,   163,   156,
     562,   564,   155,   154,   157,   146,   571,   567,   241,   240,
     158,   159,   160,   398,   397,   396,   575,     0,   570,   560,
     568,   576,   569,   566,   552,     0,   537,    68,   534,   538,
      69,    34,    66,     0,     0,   545,     0,   546,   559,   574,
      62,    63,    67,     0,     0,     0,     0,   358,     0,   236,
     237,   357,   152,     0,   631,   586,     0,    31,     0,   403,
     194,     6,     0,    33,     0,     0,     0,   525,   528,     0,
     401,    32,   556,   557,   144,   174,   169,   168,   181,   180,
     185,   185,   183,   184,   175,   170,     0,     0,   176,   177,
       0,   450,     0,     0,     0,     1,     0,     0,   577,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,     0,     0,     0,    83,    86,    88,    89,    90,    94,
      93,    91,    92,     0,    84,    85,     0,     0,     0,     0,
       0,     0,   235,   238,     0,     0,     0,     0,     0,     0,
       0,   141,   131,   406,   405,   404,     0,     0,     0,     0,
       0,   145,   595,     0,   179,   182,     0,     0,     0,   449,
     452,   453,   451,   435,     0,     0,     0,     0,     0,     0,
       3,     0,     0,   561,     0,   581,   578,   579,   148,   535,
       0,   539,   541,   536,    65,     0,     0,     0,     0,     0,
       0,   215,   214,   213,   118,     0,   120,   122,   124,   113,
       0,   110,   106,    82,    81,     0,     0,   101,   105,     0,
      97,    95,     0,   544,     0,   547,   549,     0,    57,     0,
       0,     0,   239,     0,    79,    64,     0,     0,     0,   196,
     362,     0,   359,     0,   553,     7,   377,   552,   375,   554,
     593,     0,     0,     0,   409,   413,   477,     0,   379,   471,
       0,     0,     0,   470,     0,     0,   476,     0,     0,     0,
     472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   475,   473,   474,     8,   264,   266,
     268,   304,   302,   270,   469,   494,   407,   495,   410,   378,
     626,   305,   624,   303,   608,   376,   625,   594,   592,   460,
     622,     0,     0,   527,     0,   402,     0,   529,   531,   399,
       0,   187,   191,   167,   189,   192,     0,   178,     0,     0,
      29,     0,    26,    28,     0,    14,    13,     0,    24,    17,
       0,   359,    12,     0,    15,     0,     0,     2,   166,     0,
       0,     0,     0,   147,     0,     0,     0,     0,     0,     0,
     118,     0,     0,     0,   114,     0,     0,     0,   108,   353,
     351,   318,   331,   333,   337,   340,   330,   324,   329,   322,
     344,   320,   352,   327,   343,   328,   350,   342,   431,   433,
     221,   314,   315,   316,   317,   339,     0,   103,    99,     0,
       0,    87,     0,     0,     0,     0,     0,     0,    70,     0,
      39,   363,   195,     0,     0,     0,     0,   370,   448,   198,
     430,     0,     0,     0,     0,     0,     0,   273,   387,   385,
     386,   382,   384,   381,   383,   414,     0,   448,     0,   282,
     272,   506,   306,     0,     0,     0,     0,   497,     0,   629,
       0,     0,   627,   628,   306,     0,   306,   306,   461,   269,
     306,   462,   555,     0,     0,     0,     0,     0,   301,     0,
       0,   300,     0,   298,     0,     0,   296,   297,     0,   283,
       0,   299,     0,     0,     0,     0,     0,     0,   509,   510,
     511,   512,   513,   514,     0,     0,     0,     0,   464,     0,
       0,   133,   135,   128,   127,   130,     0,     0,     0,   186,
       0,     0,     0,   436,   454,   455,   457,     0,    10,     0,
      11,    18,     0,     0,     0,    19,     0,     0,     4,     5,
       0,     0,   582,   580,   540,     0,   542,     0,   203,   206,
       0,   211,     0,   115,     0,   116,     0,   429,     0,   119,
     121,   123,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   219,   218,   217,
       0,   222,   223,   102,     0,    96,     0,    98,   548,     0,
     550,     0,    74,    78,     0,     0,     0,    71,    39,    80,
       0,    46,    47,     0,     0,    37,    40,    41,   197,   373,
     359,     0,     0,   450,   199,   193,   483,   501,     0,     0,
     596,     0,     0,     0,   450,   271,   492,   503,     0,   625,
     308,   309,   307,     0,     0,   500,     0,   496,   498,     0,
       0,     0,     0,     0,     0,     0,     0,   265,   267,     0,
       0,     0,   274,   280,   278,   276,   274,     0,   518,   288,
     287,   278,     0,   516,   276,   285,   284,     0,   286,   599,
       0,   607,   606,     0,     0,   609,   610,   611,   468,   465,
     463,   467,   466,   623,   132,     0,     0,     0,   400,   530,
       0,   532,   188,   190,   165,     0,   558,     0,   458,    27,
       0,    25,    22,   359,    16,    23,   171,     0,     0,     0,
       0,   210,     0,   209,   118,   208,   200,   109,   354,     0,
       0,     0,     0,     0,     0,   355,   347,     0,     0,     0,
       0,   347,     0,     0,   375,   216,   229,   234,     0,   231,
     228,   230,     0,   232,   220,   224,   225,   118,   104,   100,
       0,    49,     0,    77,    76,    49,    49,    49,    70,    45,
      44,    48,    43,    42,   371,   360,     0,     0,     0,   484,
       0,     0,   488,   489,   394,   392,   393,   389,   391,   388,
     390,   380,     0,     0,     0,   508,   493,   507,     0,   486,
       0,   491,   485,   490,     0,   487,     0,     0,     0,   408,
       0,   412,     0,   295,     0,   291,     0,   293,   294,     0,
     522,     0,   519,   521,   290,     0,   292,     0,     0,   614,
     603,   604,     0,   602,   605,   601,     0,   600,     0,     0,
     134,   136,     0,     0,   456,   256,   459,     0,     0,    20,
     172,     0,   164,   583,   543,   201,   207,   212,   117,   319,
     332,   334,     0,   336,     0,   338,     0,     0,   323,   345,
       0,   321,   349,     0,   432,   434,   202,   204,     0,   226,
     227,   551,    55,    56,     0,     0,    59,    50,    51,    75,
      58,    60,    61,    38,     0,   359,   256,   502,   613,     0,
     256,     0,     0,   482,   499,   478,   479,   480,   481,     0,
     275,   281,   279,   277,   523,   524,   517,     0,   515,     0,
     597,     0,   598,     0,   612,   140,     0,   137,   139,   533,
       0,   260,   439,     0,   359,   173,     0,     0,   356,   348,
     325,     0,   326,     0,     0,    53,    54,    52,   361,   372,
     446,     0,     0,     0,     0,   505,     0,   520,   289,   618,
     615,     0,     0,   129,     0,   244,   245,   253,     0,     0,
       0,   263,   260,   257,   258,   261,   310,   441,     9,    21,
     335,     0,   346,     0,   233,     0,   395,   447,   504,   411,
       0,     0,   138,     0,     0,     0,     0,   254,   374,   428,
       0,   369,   427,   364,   424,   425,     0,   359,   242,   243,
     259,   262,   312,   313,   311,     0,     0,     0,   442,   437,
     341,   205,   617,     0,   619,   616,     0,     0,   251,     0,
       0,     0,   246,   255,   365,     0,     0,   366,   448,   440,
      72,   445,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   426,   368,   359,   450,    73,   444,   419,   420,   415,
     416,   421,    72,   621,   620,   252,   249,   250,     0,   367,
       0,     0,   423,   422,   418,   443,   248,   256,   417,   439,
     438
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    52,   397,   201,   230,   392,   393,   389,   394,   390,
     381,   382,    53,    54,    55,    56,   645,   646,   647,   802,
     916,   917,   918,   277,    57,   638,  1086,   631,   632,   283,
     261,    58,   174,   175,   176,   271,   449,   177,   446,   267,
     178,   417,   262,   179,   180,   181,   409,   414,   182,   256,
     257,    59,    60,   122,   554,   727,   362,   550,   551,   956,
     957,    61,    62,    63,   212,    64,    65,    66,    67,    68,
     146,   882,   147,   148,   149,   214,   370,   373,   374,    69,
     198,   288,   655,   251,   252,   783,   587,   906,   588,   253,
     590,   263,   621,   264,   622,   784,   785,   786,   787,    70,
     108,   109,   192,    71,  1001,  1002,   961,  1058,  1059,   996,
     962,  1003,  1004,   597,   338,   339,   340,   341,   843,   847,
     845,   692,   940,   533,   342,   534,   343,   673,  1045,   440,
     441,   442,   443,   897,   444,   759,   766,   969,   375,   467,
     591,  1032,  1033,   290,  1027,   344,   485,   824,   821,    72,
      73,   129,   364,    74,    75,   205,   345,   346,   347,   348,
     349,  1048,  1089,  1090,  1091,  1104,  1005,  1034,  1035,   598,
     469,   445,    76,   378,   736,  1069,  1007,  1049,  1070,   470,
     350,   151,   223,   563,   564,   565,   351,   352,   496,   497,
     658,   825,   668,   548,   353,   851,   852,   291,   127,   997,
      88,    96,   354,   295,   355,   134,   875,    99,    77,    78,
      79,    80,   100,    81,   159,   236,   237,    82,   356,    83,
     357,   713,   866,   714,   358,   359,   360,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -857
static const yytype_int16 yypact[] =
{
    2026,  -857,  -857,  -857,   121,  -857,   323,   121,   121,   323,
     323,   121,   629,   121,   121,   323,   629,   629,   629,   629,
    -857,   655,  -857,   121,  -857,  -857,   323,  -857,   153,   323,
     323,  -857,   323,   323,  -857,  -857,  -857,   323,   323,  -857,
    -857,   629,   323,   665,  -857,   121,   323,   685,   432,    17,
     323,   432,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,   289,  -857,  -857,
    -857,   395,  -857,  -857,  -857,   178,    -7,  -857,  -857,   447,
    -857,  -857,  -857,    -3,   184,    62,   563,    16,  -857,  -857,
    -857,  -857,  -857,    23,   118,   173,   190,  -857,    11,  -857,
    -857,  -857,  -857,   327,  -857,  -857,   278,  -857,   336,  -857,
     382,    -2,   323,  -857,    63,   309,   340,  -857,    35,   274,
    -857,  -857,  -857,  -857,   445,  -857,  -857,  -857,  -857,  -857,
     425,   425,  -857,  -857,  -857,  -857,   399,   372,   394,  -857,
     672,   -28,   414,   385,   415,  -857,  2026,   711,  -857,  -857,
     679,   121,   789,   121,   121,   693,   570,    89,   700,  -857,
    -857,   207,    95,   287,   462,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,   121,  -857,  -857,   809,   121,   323,   323,
     323,   323,    11,  -857,   145,   323,   145,   100,   460,   727,
     895,  -857,   559,  -857,  -857,  -857,   121,   121,   827,   121,
     121,  -857,  -857,   100,  -857,  -857,   127,   323,   790,  -857,
    -857,  -857,  -857,  -857,  1155,  1155,  1155,  1155,    48,    48,
      18,   127,   323,  -857,   485,   493,   516,  -857,   716,  -857,
     530,  -857,   555,  -857,  -857,   622,   631,   634,   660,   641,
     654,  -857,  -857,  -857,   765,   121,   602,  -857,  -857,  -857,
     145,  -857,  -857,  -857,  -857,   609,   121,  -857,  -857,   145,
     585,  -857,   184,  -857,   594,  -857,   613,   683,  -857,   687,
     688,   689,  -857,   -60,  -857,  -857,   -33,   665,    -5,  -857,
    -857,   614,   357,   669,  -857,  -857,  -857,   692,   620,  -857,
    -857,   882,   707,   710,  -857,  -857,  -857,   712,   534,  -857,
     424,   712,   721,  -857,   722,   723,  -857,    93,   728,   712,
    -857,   730,   735,   712,   712,   736,   741,   742,   743,  1797,
    1043,   744,  1797,   891,  -857,  -857,  -857,   668,   697,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,   534,  -857,   534,  -857,
    -857,   754,  -857,  -857,    70,  -857,  -857,  -857,  -857,   502,
     832,   121,   322,  -857,   675,  -857,   673,  -857,   702,  -857,
       2,  -857,  -857,   705,  -857,  -857,   724,  -857,  1686,  1258,
    -857,     6,  -857,  -857,    25,   706,   706,   121,  -857,  -857,
      37,   131,   709,   763,  -857,   727,   895,  -857,   705,   694,
     121,   121,   711,  -857,   121,   841,   100,   100,   100,    49,
     765,   100,   895,   121,  -857,   137,   121,   174,  -857,  -857,
    -857,   778,   779,   783,   534,   534,  -857,   785,  -857,   787,
     792,   793,   795,   797,  -857,  -857,  -857,  -857,   798,   799,
     588,  -857,  -857,  -857,  -857,  -857,   210,  -857,  -857,   243,
     121,  -857,   121,   842,   121,   121,   121,   121,   837,   145,
     163,  -857,  -857,   100,    79,   970,   121,  -857,    17,   878,
    -857,  1369,   121,   965,  1686,  1686,   788,  -857,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,   731,    17,    -8,  1718,
    -857,  1686,   234,  1686,  1686,   895,   416,  -857,  1686,  -857,
    1686,  1686,  -857,  -857,   234,  1686,   234,   234,   502,  -857,
     234,   502,  -857,   895,   895,   732,   -36,  1797,  -857,  1797,
    1797,  -857,  1797,  -857,   816,  1472,  -857,  -857,  1797,  -857,
     817,  -857,  1797,   413,  1686,    69,    20,  1686,  -857,  -857,
    -857,  -857,  -857,  -857,  1686,  1686,  1686,  1686,  -857,   609,
     263,  -857,   739,  -857,  -857,  -857,   121,   121,   845,  -857,
     100,   127,   127,   756,  -857,  -857,    58,   835,  -857,  1155,
    -857,  -857,   814,    48,    85,  -857,    48,  1155,  -857,   668,
     127,   745,  -857,  -857,  -857,   746,  -857,   839,   764,  -857,
     268,  -857,   270,  -857,   660,  -857,   294,   668,   843,  -857,
    -857,  -857,  -857,   145,  1008,  1008,  1011,   749,   -13,  1013,
    1015,  1022,  1024,  1013,  1013,  1025,  1026,  -857,  -857,  -857,
      94,  -857,   313,  -857,   121,  -857,   145,  -857,  -857,   768,
    -857,   295,  -857,   191,   299,   316,   319,  -857,   163,  -857,
    1028,  -857,  -857,  1029,  1030,  -857,   163,  -857,  -857,  -857,
     846,    22,   771,   -28,  -857,  -857,  -857,  -857,   320,   773,
    -857,   325,   326,   699,   -28,  -857,  -857,   591,   866,   606,
    -857,  -857,  -857,  1686,   331,  -857,   -84,  -857,  -857,   333,
     347,   352,  1686,   353,  1686,  1686,  1686,   697,  -857,   699,
    1036,   699,   856,   502,   858,   859,   856,   109,  -857,  -857,
    -857,   858,   109,  -857,   859,  -857,  -857,  1686,  -857,  -857,
      69,  -857,  -857,   282,  1045,  -857,  -857,   180,  -857,  -857,
    -857,  -857,  -857,  -857,  -857,   121,   121,   867,  -857,  -857,
     794,  -857,  -857,  -857,   705,  1686,  -857,   121,  -857,  -857,
     868,  -857,  -857,   298,  -857,  -857,    54,   121,   121,   909,
     100,  -857,   100,  -857,   765,  -857,  -857,  -857,  -857,   884,
     885,   361,   699,  1056,   699,  -857,   818,   894,   369,   900,
     901,   818,   902,   903,  -857,  -857,  -857,  -857,   323,  -857,
    -857,  -857,   896,  -857,  -857,   313,  -857,   765,  -857,  -857,
     121,    97,   121,  -857,  -857,    97,    97,    97,   837,  -857,
    -857,  -857,  -857,  -857,  -857,  -857,  1062,   121,  1686,  -857,
    1686,   121,  -857,  -857,   897,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  1686,   534,   811,  -857,  -857,  -857,   913,  -857,
    1686,  -857,  -857,  -857,   914,  -857,   915,   916,   917,  -857,
     918,  -857,    94,  -857,    94,  -857,    94,  -857,  -857,    76,
    -857,   376,  -857,  -857,  -857,   378,  -857,   847,   250,  -857,
    -857,  -857,    69,  -857,  -857,  -857,    69,  -857,    69,   121,
    -857,  -857,  1583,   121,  -857,   861,  -857,  1155,   121,  -857,
    -857,   655,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  1088,  -857,   924,  -857,  1092,   926,  -857,  -857,
    1098,  -857,  -857,   932,  -857,  -857,  -857,   921,   895,  -857,
    -857,  -857,  -857,  -857,  1030,  1102,  -857,    97,  -857,  -857,
    -857,  -857,  -857,  -857,   927,   846,   397,  -857,   919,  1104,
     397,   848,   699,  -857,  -857,  -857,  -857,  -857,  -857,   849,
    -857,  -857,  -857,  -857,  -857,  -857,  -857,    99,  -857,  1686,
    -857,   359,   514,   486,   922,  -857,   380,  -857,  -857,  -857,
     323,    29,   889,   389,   846,  -857,   939,   853,  -857,  -857,
    -857,   942,  -857,   100,   950,  -857,  -857,  -857,  -857,  -857,
    -857,    69,   951,   952,   699,  -857,   699,  -857,  -857,  -857,
    -857,    69,    69,  -857,  1583,    67,  -857,    61,    81,   895,
     895,  -857,   418,  -857,  -857,   935,   271,   155,  -857,  -857,
    -857,   699,  -857,   393,  -857,   637,  -857,  -857,  -857,  -857,
     433,   684,  -857,   171,   171,   116,   121,  -857,  -857,  -857,
      74,  -857,  -857,  -857,   876,  -857,   864,   454,   668,   668,
    -857,  -857,  -857,  -857,  -857,   928,   121,   869,   974,  -857,
    -857,  -857,  -857,    69,  -857,  -857,    69,   323,    67,   871,
     872,   194,  -857,  -857,  -857,    81,    88,  -857,    17,  -857,
     997,  -857,    92,   121,   648,   704,   114,   895,   895,   323,
    -857,  -857,  -857,   846,   -28,  -857,  -857,  -857,  -857,   890,
    -857,   233,   997,  -857,  -857,  -857,   668,   668,   130,  -857,
    1686,    92,  -857,  -857,  -857,  -857,  -857,   397,  -857,   889,
    -857
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -857,  -857,  -857,  -857,  -857,  -857,  -168,   753,   566,  -857,
    -182,  -258,  -857,  -857,  -857,  -857,   505,  -857,   499,   232,
     -17,  -857,   236,   608,  -857,   358,    68,   355,   363,   954,
    -133,  -857,  -857,   892,  -857,  -242,  -857,  -857,  -857,  -243,
    -857,  -857,  -209,  -857,  -857,  -857,  -857,  -355,  -857,   907,
     747,  -857,  -857,  -857,  -857,  -857,  -857,  -857,   440,  -857,
     172,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    1120,  -857,  1122,  -857,   956,  1035,  -857,  -156,   616,  -857,
    -857,  -857,  -857,  -857,  -857,   429,  -857,  -857,   206,  -857,
     175,  -131,  -857,  -857,  -857,  -857,  -857,   396,  -857,  -857,
    -857,  -857,  -857,    31,   177,  -857,  -857,  -780,   156,  -851,
    -776,  -857,   181,  -199,   671,   674,   857,  -857,   494,   482,
     488,   306,    13,  -857,  -857,  -857,  -857,   219,  -857,   642,
    -857,  -857,  -857,   421,  -857,   589,   138,  -857,    -1,  -370,
    -165,  -856,   165,   906,   170,  -556,  -857,  -290,  -568,  -857,
    -857,   987,   643,  -857,  -857,  -857,  -857,  -857,  -857,  -857,
    -857,  -857,  -857,   101,  -857,  -857,  -857,  -857,   133,   292,
    -857,  -857,  -857,  -857,  -857,  -857,    98,  -857,   128,   844,
    -179,  -438,  -617,  -751,  -857,   468,  -158,  -857,  -857,   713,
     490,   539,  -857,  -857,  -857,   510,   266,   -27,  -857,    44,
    -857,   719,    -4,   819,   367,  -857,  -857,  -857,  -857,  -857,
    1061,  -857,  1204,  -857,  -857,  -857,   820,  -857,  -460,  -857,
    -857,  -622,  -857,  -857,  -857,   -20,  -857,  -857
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -566
static const yytype_int16 yytable[] =
{
      85,   337,    89,    90,    91,    89,    89,    94,    97,    98,
      98,    89,    97,    97,    97,    97,   126,   111,   486,   112,
     110,   575,    89,   447,    84,    89,    89,   448,    89,    89,
     653,   669,   289,    89,    89,   254,   808,    97,    89,   128,
     270,   130,    89,   384,   385,   386,    89,   822,   371,   664,
      87,   418,    84,    92,    93,   595,   515,   926,   516,   102,
     388,   284,    84,   284,   775,    84,   383,   383,   383,   383,
     113,   930,   709,   116,   117,   398,   118,   119,    84,   944,
     125,   120,   121,    84,  1029,    84,   124,   125,   858,    84,
     131,   299,    84,    84,   152,  1087,    84,   296,   125,    84,
     774,  1023,   296,    84,    84,   298,   125,   199,  1024,   299,
     458,   488,   296,    84,   299,   298,   300,   410,    89,   301,
      84,   839,    86,   841,   299,    84,   300,   395,   477,   301,
     220,    84,   490,   107,   607,   608,   270,   460,    37,   193,
     499,   850,   912,   913,   502,   503,   850,   690,  1023,    84,
     980,   830,   489,   235,   983,  1024,   114,   239,   241,   242,
     243,   880,   665,   258,  1023,   462,   202,   265,   268,   265,
     763,  1024,   559,   221,  1062,    84,   568,    86,   203,   273,
     995,   513,   275,   276,    89,    89,    89,    89,   459,   998,
     265,    89,   265,   292,   893,   570,   895,   579,    84,   204,
      86,   805,   363,   365,   367,   368,   130,   572,    48,   292,
    1080,    84,   111,    89,   222,   459,  1088,   999,   200,   593,
     566,   567,    51,   282,   391,   391,   150,   111,    89,   640,
     691,   160,   278,   278,   278,   278,   715,   853,   396,   285,
     951,   589,   853,   463,   952,  1088,   953,   641,   642,  1000,
     560,   258,   710,   764,   569,   161,   265,   513,   166,   167,
     165,   376,   268,   186,   535,   265,   308,   168,   169,   170,
     806,   308,   255,   569,   187,   245,   399,  1076,   266,   246,
     804,   308,   208,   292,  1095,   573,   941,   188,   941,   155,
     941,    84,   643,   209,   716,   649,   676,   594,   648,  1098,
    1106,   742,   561,   247,  1082,   156,   387,   600,   487,   508,
    1046,   739,   511,   657,   881,  1025,   657,   657,   737,   745,
     494,  1026,   372,   711,   183,   465,   639,    84,   712,    86,
     495,  1109,   536,   667,  1061,   657,   675,   245,   333,  1030,
     657,   246,   657,   657,   602,   698,   249,   657,  1031,  1107,
    1030,   703,   250,   849,  1057,  1031,   333,   552,   287,  1015,
     914,   333,  1025,   849,   985,   247,  1031,   700,   915,  1020,
    1021,   333,  1047,   879,   868,   171,   708,  1079,  1025,   718,
     623,   788,   189,   391,   789,   416,   719,   720,   721,   722,
     260,   850,   670,   574,   757,   732,   581,   582,   235,   888,
     584,   586,   292,   292,   292,   741,   734,   292,   249,   599,
     172,   383,   258,   625,   250,   793,  1018,   245,  1019,   383,
     950,   246,   603,   776,   746,   173,   644,   296,   297,  1042,
     298,  1074,   910,   724,  1075,   671,   794,   190,   751,   299,
     753,   300,   869,  1050,   301,   247,   627,   777,   628,   630,
     633,   633,   633,   633,   191,   265,   778,  1102,   624,   292,
     650,   859,   652,   754,   755,   791,   860,  1100,   659,   795,
     269,   779,  1043,   302,   303,   861,   672,   780,  1103,   304,
     305,   224,   225,   226,   227,   228,   796,   853,   249,   797,
     809,   626,   465,   270,   250,   812,   813,   693,   860,   693,
     693,   829,   693,   831,   863,   864,   306,   861,   693,   865,
     194,   725,   693,  1044,   781,   828,   752,   832,   752,   196,
     782,   468,   833,   835,   834,   553,   836,   837,   838,   195,
     862,   891,   717,   931,   157,   158,   863,   864,   989,   899,
     210,   865,   752,   792,   135,   705,   946,   792,   948,   857,
     993,   465,   365,   729,   731,   979,   292,   111,   111,  1008,
     878,   537,   738,  1051,   792,   197,   307,   792,   810,   391,
     743,   206,   391,   810,   810,   860,   111,   566,   998,   810,
     706,   810,   707,   592,   861,   886,   596,   887,   538,   539,
     540,   541,   542,   543,  1009,   810,   308,   136,   211,   265,
     810,   810,   207,   137,   208,   309,   999,   310,   213,   892,
     311,   312,  1054,   863,   864,   209,   138,   900,   865,   466,
     268,   139,   265,   487,   947,   960,   947,   216,   994,   313,
    1084,   140,   314,    84,   141,    95,   217,   569,   142,   315,
     316,   750,   218,   494,   143,   735,   317,   318,   465,   860,
     566,   231,   927,   495,   229,   184,   185,   319,   861,    84,
     320,   107,   321,   322,   566,   990,   323,  1067,   324,    84,
     325,   125,   934,   326,   144,   219,   327,   328,   329,   232,
     330,   331,   145,   332,   677,   238,   333,   863,   864,   132,
     419,   133,   865,   478,   162,   963,   334,   335,   336,   244,
     245,   208,   860,   259,   246,   163,   617,   618,   619,   164,
     272,   861,   209,  1099,   958,    84,  -528,   234,   544,   383,
     293,   552,   871,   682,   479,   684,   685,   545,   247,   686,
     860,   294,   480,   876,   991,   103,   104,   105,   106,   861,
     863,   864,   361,   883,   884,   865,   292,   400,   292,   481,
     478,   770,   771,   248,   420,   401,   546,   421,   422,   423,
     123,   547,   620,   482,   402,   478,   424,   403,   863,   864,
     425,   249,   483,   865,    89,   426,  -503,   250,   920,   921,
     922,   479,   427,   484,   428,   429,   911,   430,   633,   480,
     245,   988,   404,    84,   246,   240,   479,   279,   280,   281,
    1038,  1039,   405,   925,   480,   406,   481,   928,   589,   431,
     634,   635,   636,    84,   407,   274,  1052,   408,   247,   432,
     482,   481,   907,   433,   411,   694,   695,  1093,   696,   483,
     434,    84,   435,   366,   701,   482,   958,   412,   704,   823,
     484,   436,   413,   437,   483,    84,    84,   585,   629,    84,
     416,   730,   450,   860,   823,   484,   452,   942,   814,   943,
     453,   249,   861,  1055,   860,   954,   454,   250,   468,   959,
     455,   456,   457,   861,   964,   471,   464,   111,  1096,  1097,
     965,   438,   472,  1094,   439,  1053,  -282,   517,   473,   815,
     474,   863,   864,   475,   512,   476,   865,   816,   296,   297,
     860,   298,   863,   864,   491,   492,   493,   865,   518,   861,
     299,   498,   300,   500,   817,   301,   519,   520,   501,   504,
     860,  -282,   521,  -282,   505,   506,   507,   510,   818,   861,
     549,   522,  1056,   513,   523,   557,   524,   819,   863,   864,
     514,   556,   566,   865,   302,   303,   525,   526,   820,   558,
     304,   305,   562,   561,   569,   577,    89,   576,   863,   864,
     580,   604,   605,   865,   661,   662,   606,   527,   609,   292,
     610,  1036,   637,   651,   138,   611,   612,   306,   613,   139,
     614,   615,   616,   674,   654,   528,   660,   487,   679,   140,
     680,   681,   141,  1028,  1037,   683,   142,   663,   689,   697,
     702,   726,   143,  1036,   735,   666,   740,   747,   748,   749,
     529,   758,   750,   756,   761,   762,   765,   530,   767,    89,
      89,    89,  1028,   531,   532,   768,  1037,   769,   772,   773,
     790,   799,   800,   807,   801,   811,   826,   307,  1036,   840,
     465,   842,  1071,   844,   846,  1036,   296,   297,   867,   298,
     872,   877,   778,    89,   889,   890,   873,    89,   299,   894,
     300,  1037,  1083,   301,   898,   924,   896,   308,  1037,  1071,
     901,   902,   904,   905,  1036,    89,   309,   932,   310,   908,
     929,   311,   312,   933,   935,   936,   937,   938,   939,   960,
     949,   966,   302,   303,   967,   968,   970,  1037,   304,   305,
     313,   971,   972,   314,   973,   976,   978,   982,  1006,  1010,
     315,   316,  1012,   981,   984,   986,   992,   317,   318,  1011,
    1014,  1016,  1017,   999,  1065,   306,  1066,  1068,   319,  1073,
    1072,   320,  1085,   321,   322,  1077,  1078,   323,  1101,   324,
     571,   325,   744,   798,   326,   803,   975,   327,   328,   329,
     286,   330,   331,   977,   332,   919,   923,   333,   296,   297,
    1105,   298,   415,   601,   451,   870,  1022,   334,   335,   336,
     299,   153,   300,   154,   377,   301,   215,   733,   885,  1013,
    1060,   909,  1041,  1040,   687,   307,   856,   509,   688,   854,
     848,   723,   903,   461,   760,  1064,  1063,   369,  1081,   728,
     974,  1092,  1108,   874,   302,   303,   555,  1110,   827,   678,
     304,   305,   855,   987,   578,   308,   945,   233,   101,     0,
       0,     0,   583,     0,   309,     0,   310,     0,     0,   311,
     312,     0,     0,     0,     0,     0,     0,   306,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
       0,   296,   297,     0,   298,   317,   318,     0,     0,     0,
       0,     0,     0,   299,     0,   300,   319,     0,   301,   320,
       0,   321,   322,     0,     0,   323,     0,   324,     0,   325,
       0,     0,   326,     0,     0,   327,   328,   329,     0,     0,
     331,     0,   332,     0,     0,   333,     0,   302,   303,     0,
       0,     0,     0,   304,   305,   334,   335,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,   309,     0,   379,     0,
     306,     0,   312,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   380,
     313,     0,     0,   314,     0,     0,     0,     0,     0,     0,
     315,   316,   296,   297,     0,   298,     0,   317,   318,     0,
       0,     0,     0,     0,   299,     0,   300,     0,   319,   301,
       0,   320,     0,   321,   322,     0,     0,   323,     0,   324,
       0,   325,     0,     0,   326,     0,     0,   327,   328,   329,
       0,     0,   331,     0,   332,     0,     0,   333,   302,   303,
       0,     0,     0,     0,   304,   305,     0,   334,   335,   336,
     308,     0,     0,     0,     0,     0,     0,     0,     0,   309,
       0,   379,     0,     0,     0,   312,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,     0,   487,     0,     0,
       0,     0,     0,   313,     0,     0,   314,     0,     0,     0,
       0,     0,     0,   315,   316,   296,   297,     0,   298,     0,
     317,   318,     0,     0,     0,     0,     0,   299,     0,   300,
       0,   319,   301,     0,   320,     0,   321,   322,     0,     0,
     323,     0,   324,     0,   325,     0,     0,   326,     0,     0,
     327,   328,   329,     0,     0,   331,     0,   332,     0,     0,
     333,   302,   303,     0,     0,     0,     0,   304,   305,     0,
     334,   335,   336,     0,     0,     0,     0,     0,     0,   656,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
     309,     0,   379,     0,   306,     0,   312,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   315,   316,   296,   297,     0,   298,
       0,   317,   318,     0,     0,     0,     0,     0,   299,     0,
     300,     0,   319,   301,     0,   320,     0,   321,   322,     0,
       0,   323,     0,   324,     0,   325,     0,     0,   326,     0,
       0,   327,   328,   329,     0,     0,   331,     0,   332,     0,
       0,   333,   302,   303,     0,     0,     0,     0,   304,   305,
       0,   334,   335,   336,   308,     0,     0,     0,     0,     0,
       0,     0,     0,   309,     0,   379,     0,     0,     0,   312,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   699,   313,     0,     0,
     314,     0,     0,     0,     0,     0,     0,   315,   316,   296,
     297,     0,   298,     0,   317,   318,     0,     0,     0,     0,
       0,   299,     0,   300,     0,   319,   301,     0,   320,     0,
     321,   322,     0,     0,   323,     0,   324,     0,   325,     0,
       0,   326,     0,     0,   327,   328,   329,     0,     0,   331,
       0,   332,     0,     0,   333,   302,   303,     0,     0,     0,
       0,   304,   305,     0,   334,   335,   336,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,     0,     0,   309,     0,   379,     0,   306,     0,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   955,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
     296,   297,     0,   298,     0,   317,   318,     0,     0,     0,
       0,     0,   299,     0,   300,     0,   319,   301,     0,   320,
       0,   321,   322,     0,     0,   323,     0,   324,     0,   325,
       0,     0,   326,     0,     0,   327,   328,   329,     0,     0,
     331,     0,   332,     0,     0,   333,   302,   303,     0,     0,
       0,   517,   304,   305,     0,   334,   335,   336,   308,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,   379,
       0,     0,   518,   312,     0,     0,     0,     0,     0,   306,
     519,   520,     0,     0,     0,     0,   521,     0,   666,     0,
       0,   313,     0,     0,   314,   522,     0,     0,   523,     0,
     524,   315,   316,     0,     0,     0,     0,     0,   317,   318,
     525,   526,     0,     0,     0,     0,     0,     0,     0,   319,
       0,     0,   320,     0,   321,   322,     0,     0,   323,     0,
     324,   527,   325,     0,     0,   326,     0,     0,   327,   328,
     329,     0,     0,   331,     0,   332,     0,     0,   333,   528,
       0,     0,     0,     0,     0,     0,     0,     0,   334,   335,
     336,  -305,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     0,     0,     0,   529,     0,     0,     0,   309,     0,
     379,   530,     0,  -305,   312,     0,     0,   531,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,   314,     0,     0,     0,     0,
       0,     0,   315,   316,     0,     0,     0,     0,     0,   317,
     318,     0,     0,     0,     0,     0,  -565,     1,     0,     0,
     319,     0,     0,   320,     0,   321,   322,     0,     0,   323,
       0,   324,  -565,   325,     0,     0,   326,     0,     0,   327,
     328,     0,     0,     0,   331,     0,     0,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
     335,   336,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     0,     0,     6,     7,     0,     8,     9,    10,     0,
      11,    12,     0,     0,     0,     0,     0,     0,    13,    14,
       0,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,    28,     0,    29,
      30,     0,    31,    32,     0,     0,     0,     0,     0,    33,
      34,    35,    36,    37,    38,     0,     0,    39,     0,     0,
       0,     0,     0,    40,    41,     0,     0,    42,     0,     0,
      43,     0,    44,    45,     0,     0,     0,     0,    46,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,    49,     0,     0,    50,     0,
       0,     0,     0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       4,   200,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    43,    21,   308,    23,
      21,   391,    26,   266,     4,    29,    30,   269,    32,    33,
     468,   491,   197,    37,    38,   166,   653,    41,    42,    43,
     173,    45,    46,   225,   226,   227,    50,   664,   213,   487,
       6,   260,     4,     9,    10,   410,   346,   808,   348,    15,
     228,   194,     4,   196,   620,     4,   224,   225,   226,   227,
      26,   822,     3,    29,    30,   231,    32,    33,     4,     3,
       6,    37,    38,     4,     3,     4,    42,     6,   710,     4,
      46,    15,     4,     4,    50,     3,     4,     3,     6,     4,
       6,    34,     3,     4,     4,     6,     6,   109,    41,    15,
     170,   310,     3,     4,    15,     6,    17,   248,   122,    20,
       4,   689,     6,   691,    15,     4,    17,   109,   307,    20,
     158,     4,   311,     6,   424,   425,   269,   170,   127,   108,
     319,   697,    45,    46,   323,   324,   702,   183,    34,     4,
     926,   235,   310,   157,   930,    41,     3,   161,   162,   163,
     164,   107,   170,   167,    34,   170,   122,   171,   172,   173,
     183,    41,   170,   201,  1025,     4,   170,     6,   115,   183,
     960,   265,   186,   187,   188,   189,   190,   191,   248,   160,
     194,   195,   196,   197,   762,   170,   764,   396,     4,   136,
       6,   179,   206,   207,   208,   209,   210,   170,   197,   213,
    1061,     4,   216,   217,   242,   248,  1072,   188,   220,   170,
     378,   379,   211,   192,   228,   229,   209,   231,   232,    66,
     266,    53,   188,   189,   190,   191,   216,   697,   220,   195,
     862,   406,   702,   248,   866,  1101,   868,    84,    85,   220,
     248,   255,   183,   266,   248,   262,   260,   265,    74,    75,
     263,   217,   266,   247,   194,   269,   172,    83,    84,    85,
     248,   172,   183,   248,   258,   130,   232,  1057,   183,   134,
     650,   172,   247,   287,   170,   248,   842,   264,   844,     0,
     846,     4,   129,   258,   274,   216,   495,   248,   463,  1079,
     170,   216,   248,   158,   216,    16,   258,   170,   199,   329,
     155,   569,   332,   471,   260,   248,   474,   475,   260,   577,
     227,   260,   195,   254,   262,   194,   459,     4,   259,     6,
     237,  1107,   262,   491,   218,   493,   494,   130,   262,   258,
     498,   134,   500,   501,   170,   524,   201,   505,   274,  1100,
     258,   530,   207,   254,   183,   274,   262,   361,   258,   981,
     263,   262,   248,   254,   932,   158,   274,   525,   271,   991,
     992,   262,   217,   743,   194,   191,   534,   183,   248,   537,
     170,   624,   264,   387,   626,   248,   544,   545,   546,   547,
     183,   947,   158,   262,   603,   560,   400,   401,   402,   754,
     404,   405,   406,   407,   408,   573,   562,   411,   201,   413,
     226,   569,   416,   170,   207,   224,   984,   130,   986,   577,
     170,   134,   248,   110,   580,   241,   263,     3,     4,   158,
       6,  1053,   787,   170,  1056,   201,   245,   264,   170,    15,
     170,    17,   262,  1011,    20,   158,   450,   134,   452,   453,
     454,   455,   456,   457,   264,   459,   143,   224,   248,   463,
     464,   179,   466,   594,   170,   170,   216,  1084,   472,   170,
     183,   158,   201,    49,    50,   225,   242,   164,   245,    55,
      56,    67,    68,    69,    70,    71,   170,   947,   201,   170,
     170,   248,   194,   626,   207,   170,   170,   517,   216,   519,
     520,   170,   522,   170,   254,   255,    82,   225,   528,   259,
     183,   248,   532,   242,   201,   673,   248,   170,   248,   183,
     207,   199,   170,   170,   682,   203,   684,   685,   686,   251,
     248,   170,   536,   823,   139,   140,   254,   255,   179,   170,
     266,   259,   248,   248,   112,   132,   170,   248,   170,   707,
     170,   194,   556,   557,   558,   925,   560,   561,   562,   170,
     262,    59,   566,   170,   248,   183,   142,   248,   248,   573,
     574,   262,   576,   248,   248,   216,   580,   735,   160,   248,
     167,   248,   169,   408,   225,   750,   411,   752,    86,    87,
      88,    89,    90,    91,   964,   248,   172,   165,   153,   603,
     248,   248,   262,   171,   247,   181,   188,   183,   183,   248,
     186,   187,   179,   254,   255,   258,   184,   248,   259,   262,
     624,   189,   626,   199,   248,   228,   248,   228,   248,   205,
    1068,   199,   208,     4,   202,     6,   264,   248,   206,   215,
     216,   248,   248,   227,   212,   248,   222,   223,   194,   216,
     808,   266,   810,   237,   240,    92,    93,   233,   225,     4,
     236,     6,   238,   239,   822,   179,   242,  1037,   244,     4,
     246,     6,   830,   249,   242,     3,   252,   253,   254,   264,
     256,   257,   250,   259,   268,     6,   262,   254,   255,     4,
      81,     6,   259,   159,   247,   877,   272,   273,   274,     6,
     130,   247,   216,     3,   134,   258,   118,   119,   120,   262,
     248,   225,   258,  1083,   872,     4,   262,     6,   216,   877,
     260,   725,   726,   504,   190,   506,   507,   225,   158,   510,
     216,     4,   198,   737,   248,    16,    17,    18,    19,   225,
     254,   255,   183,   747,   748,   259,   750,   262,   752,   215,
     159,   613,   614,   183,   145,   262,   254,   148,   149,   150,
      41,   259,   174,   229,   248,   159,   157,    51,   254,   255,
     161,   201,   238,   259,   778,   166,   170,   207,   795,   796,
     797,   190,   173,   249,   175,   176,   790,   178,   792,   198,
     130,   949,   262,     4,   134,     6,   190,   189,   190,   191,
     999,  1000,   247,   807,   198,   183,   215,   811,   973,   200,
     455,   456,   457,     4,   183,     6,   179,   183,   158,   210,
     229,   215,   778,   214,   183,   519,   520,   179,   522,   238,
     221,     4,   223,     6,   528,   229,   994,   183,   532,   248,
     249,   232,    77,   234,   238,     4,     4,     6,     6,     4,
     248,     6,   267,   216,   248,   249,   262,   844,   159,   846,
     247,   201,   225,   179,   216,   869,   183,   207,   199,   873,
     183,   183,   183,   225,   878,   183,   262,   881,  1077,  1078,
     881,   272,   262,   179,   275,   248,   132,   133,     6,   190,
     183,   254,   255,   183,     3,   183,   259,   198,     3,     4,
     216,     6,   254,   255,   183,   183,   183,   259,   154,   225,
      15,   183,    17,   183,   215,    20,   162,   163,   183,   183,
     216,   167,   168,   169,   183,   183,   183,   183,   229,   225,
      98,   177,   248,   265,   180,   262,   182,   238,   254,   255,
     243,   266,  1100,   259,    49,    50,   192,   193,   249,   247,
      55,    56,   228,   248,   248,   192,   960,   248,   254,   255,
     266,   183,   183,   259,   474,   475,   183,   213,   183,   973,
     183,   998,   135,     3,   184,   183,   183,    82,   183,   189,
     183,   183,   183,   493,   106,   231,    21,   199,   498,   199,
     500,   501,   202,   997,   998,   505,   206,   266,   266,   183,
     183,   262,   212,  1030,   248,   170,   192,   262,   262,   170,
     256,     3,   248,   170,     3,   266,     3,   263,     3,  1023,
    1024,  1025,  1026,   269,   270,     3,  1030,     3,     3,     3,
     262,     3,     3,   262,     4,   262,   170,   142,  1065,     3,
     194,   185,  1046,   185,   185,  1072,     3,     4,     3,     6,
     183,   183,   143,  1057,   170,   170,   262,  1061,    15,     3,
      17,  1065,  1066,    20,   170,     3,   248,   172,  1072,  1073,
     170,   170,   170,   170,  1101,  1079,   181,   266,   183,   183,
     183,   186,   187,   170,   170,   170,   170,   170,   170,   228,
     243,     3,    49,    50,   170,     3,   170,  1101,    55,    56,
     205,     3,   170,   208,   183,     3,   179,     3,   219,   170,
     215,   216,   170,   194,   266,   266,   194,   222,   223,   266,
     170,   170,   170,   188,   248,    82,   262,   199,   233,   155,
     261,   236,   135,   238,   239,   264,   264,   242,   248,   244,
     387,   246,   576,   638,   249,   646,   914,   252,   253,   254,
     196,   256,   257,   917,   259,   792,   798,   262,     3,     4,
    1092,     6,   255,   416,   272,   725,   994,   272,   273,   274,
      15,    51,    17,    51,   218,    20,   141,   561,   749,   973,
    1024,   785,  1005,  1002,   513,   142,   704,   330,   514,   701,
     696,   549,   771,   287,   605,  1030,  1026,   210,  1065,   556,
     908,  1073,  1101,   735,    49,    50,   362,  1109,   669,   496,
      55,    56,   702,   947,   395,   172,   849,   156,    14,    -1,
      -1,    -1,   402,    -1,   181,    -1,   183,    -1,    -1,   186,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,
      -1,     3,     4,    -1,     6,   222,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    -1,    17,   233,    -1,    20,   236,
      -1,   238,   239,    -1,    -1,   242,    -1,   244,    -1,   246,
      -1,    -1,   249,    -1,    -1,   252,   253,   254,    -1,    -1,
     257,    -1,   259,    -1,    -1,   262,    -1,    49,    50,    -1,
      -1,    -1,    -1,    55,    56,   272,   273,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,   183,    -1,
      82,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     205,    -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,
     215,   216,     3,     4,    -1,     6,    -1,   222,   223,    -1,
      -1,    -1,    -1,    -1,    15,    -1,    17,    -1,   233,    20,
      -1,   236,    -1,   238,   239,    -1,    -1,   242,    -1,   244,
      -1,   246,    -1,    -1,   249,    -1,    -1,   252,   253,   254,
      -1,    -1,   257,    -1,   259,    -1,    -1,   262,    49,    50,
      -1,    -1,    -1,    -1,    55,    56,    -1,   272,   273,   274,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
      -1,   183,    -1,    -1,    -1,   187,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,   205,    -1,    -1,   208,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,     3,     4,    -1,     6,    -1,
     222,   223,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,
      -1,   233,    20,    -1,   236,    -1,   238,   239,    -1,    -1,
     242,    -1,   244,    -1,   246,    -1,    -1,   249,    -1,    -1,
     252,   253,   254,    -1,    -1,   257,    -1,   259,    -1,    -1,
     262,    49,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,
     272,   273,   274,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,    -1,   183,    -1,    82,    -1,   187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,    -1,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,   215,   216,     3,     4,    -1,     6,
      -1,   222,   223,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      17,    -1,   233,    20,    -1,   236,    -1,   238,   239,    -1,
      -1,   242,    -1,   244,    -1,   246,    -1,    -1,   249,    -1,
      -1,   252,   253,   254,    -1,    -1,   257,    -1,   259,    -1,
      -1,   262,    49,    50,    -1,    -1,    -1,    -1,    55,    56,
      -1,   272,   273,   274,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,    -1,   183,    -1,    -1,    -1,   187,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,   205,    -1,    -1,
     208,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,     3,
       4,    -1,     6,    -1,   222,   223,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    17,    -1,   233,    20,    -1,   236,    -1,
     238,   239,    -1,    -1,   242,    -1,   244,    -1,   246,    -1,
      -1,   249,    -1,    -1,   252,   253,   254,    -1,    -1,   257,
      -1,   259,    -1,    -1,   262,    49,    50,    -1,    -1,    -1,
      -1,    55,    56,    -1,   272,   273,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,   183,    -1,    82,    -1,
     187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,    -1,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,   215,   216,
       3,     4,    -1,     6,    -1,   222,   223,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    17,    -1,   233,    20,    -1,   236,
      -1,   238,   239,    -1,    -1,   242,    -1,   244,    -1,   246,
      -1,    -1,   249,    -1,    -1,   252,   253,   254,    -1,    -1,
     257,    -1,   259,    -1,    -1,   262,    49,    50,    -1,    -1,
      -1,   133,    55,    56,    -1,   272,   273,   274,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,   183,
      -1,    -1,   154,   187,    -1,    -1,    -1,    -1,    -1,    82,
     162,   163,    -1,    -1,    -1,    -1,   168,    -1,   170,    -1,
      -1,   205,    -1,    -1,   208,   177,    -1,    -1,   180,    -1,
     182,   215,   216,    -1,    -1,    -1,    -1,    -1,   222,   223,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,
      -1,    -1,   236,    -1,   238,   239,    -1,    -1,   242,    -1,
     244,   213,   246,    -1,    -1,   249,    -1,    -1,   252,   253,
     254,    -1,    -1,   257,    -1,   259,    -1,    -1,   262,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   273,
     274,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   181,    -1,
     183,   263,    -1,   265,   187,    -1,    -1,   269,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,    -1,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,   222,
     223,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
     233,    -1,    -1,   236,    -1,   238,   239,    -1,    -1,   242,
      -1,   244,    16,   246,    -1,    -1,   249,    -1,    -1,   252,
     253,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
     273,   274,    -1,    47,    48,    -1,    -1,    -1,    52,    -1,
      54,    -1,    -1,    57,    58,    -1,    60,    61,    62,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    -1,    99,   100,   101,   102,   103,
     104,   105,    -1,    -1,   108,    -1,    -1,   111,    -1,   113,
     114,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,    -1,    -1,   131,    -1,    -1,
      -1,    -1,    -1,   137,   138,    -1,    -1,   141,    -1,    -1,
     144,    -1,   146,   147,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,    -1,    -1,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    47,    48,    52,    54,    57,    58,    60,    61,
      62,    64,    65,    72,    73,    76,    94,    95,    96,    97,
      99,   100,   101,   102,   103,   104,   105,   108,   111,   113,
     114,   116,   117,   123,   124,   125,   126,   127,   128,   131,
     137,   138,   141,   144,   146,   147,   152,   156,   197,   199,
     202,   211,   294,   305,   306,   307,   308,   317,   324,   344,
     345,   354,   355,   356,   358,   359,   360,   361,   362,   372,
     392,   396,   442,   443,   446,   447,   465,   501,   502,   503,
     504,   506,   510,   512,     4,   495,     6,   492,   493,   495,
     495,   495,   492,   492,   495,     6,   494,   495,   495,   500,
     505,   505,   492,   494,   494,   494,   494,     6,   393,   394,
     431,   495,   495,   492,     3,   520,   492,   492,   492,   492,
     492,   492,   346,   494,   492,     6,   490,   491,   495,   444,
     495,   492,     4,     6,   498,   112,   165,   171,   184,   189,
     199,   202,   206,   212,   242,   250,   363,   365,   366,   367,
     209,   474,   492,   363,   365,     0,    16,   139,   140,   507,
      53,   262,   247,   258,   262,   263,    74,    75,    83,    84,
      85,   191,   226,   241,   325,   326,   327,   330,   333,   336,
     337,   338,   341,   262,    92,    93,   247,   258,   264,   264,
     264,   264,   395,   396,   183,   251,   183,   183,   373,   109,
     220,   296,   492,   115,   136,   448,   262,   262,   247,   258,
     266,   153,   357,   183,   368,   368,   228,   264,   248,     3,
     158,   201,   242,   475,    67,    68,    69,    70,    71,   240,
     297,   266,   264,   503,     6,   495,   508,   509,     6,   495,
       6,   495,   495,   495,     6,   130,   134,   158,   183,   201,
     207,   376,   377,   382,   384,   183,   342,   343,   495,     3,
     183,   323,   335,   384,   386,   495,   183,   332,   495,   183,
     323,   328,   248,   495,     6,   495,   495,   316,   492,   316,
     316,   316,   396,   322,   323,   492,   322,   258,   374,   433,
     436,   490,   495,   260,     4,   496,     3,     4,     6,    15,
      17,    20,    49,    50,    55,    56,    82,   142,   172,   181,
     183,   186,   187,   205,   208,   215,   216,   222,   223,   233,
     236,   238,   239,   242,   244,   246,   249,   252,   253,   254,
     256,   257,   259,   262,   272,   273,   274,   406,   407,   408,
     409,   410,   417,   419,   438,   449,   450,   451,   452,   453,
     473,   479,   480,   487,   495,   497,   511,   513,   517,   518,
     519,   183,   349,   495,   445,   495,     6,   495,   495,   444,
     369,   433,   195,   370,   371,   431,   492,   367,   466,   183,
     204,   303,   304,   479,   303,   303,   303,   258,   299,   300,
     302,   495,   298,   299,   301,   109,   220,   295,   370,   492,
     262,   262,   248,    51,   262,   247,   183,   183,   183,   339,
     384,   183,   183,    77,   340,   342,   248,   334,   335,    81,
     145,   148,   149,   150,   157,   161,   166,   173,   175,   176,
     178,   200,   210,   214,   221,   223,   232,   234,   272,   275,
     422,   423,   424,   425,   427,   464,   331,   332,   328,   329,
     267,   326,   262,   247,   183,   183,   183,   183,   170,   248,
     170,   436,   170,   248,   262,   194,   262,   432,   199,   463,
     472,   183,   262,     6,   183,   183,   183,   473,   159,   190,
     198,   215,   229,   238,   249,   439,   440,   199,   406,   479,
     473,   183,   183,   183,   227,   237,   481,   482,   183,   473,
     183,   183,   473,   473,   183,   183,   183,   183,   518,   409,
     183,   518,     3,   265,   243,   440,   440,   133,   154,   162,
     163,   168,   177,   180,   182,   192,   193,   213,   231,   256,
     263,   269,   270,   416,   418,   194,   262,    59,    86,    87,
      88,    89,    90,    91,   216,   225,   254,   259,   486,    98,
     350,   351,   495,   203,   347,   472,   266,   262,   247,   170,
     248,   248,   228,   476,   477,   478,   479,   479,   170,   248,
     170,   300,   170,   248,   262,   432,   248,   192,   496,   406,
     266,   495,   495,   509,   495,     6,   495,   379,   381,   433,
     383,   433,   383,   170,   248,   340,   383,   406,   462,   495,
     170,   343,   170,   248,   183,   183,   183,   440,   440,   183,
     183,   183,   183,   183,   183,   183,   183,   118,   119,   120,
     174,   385,   387,   170,   248,   170,   248,   495,   495,     6,
     495,   320,   321,   495,   320,   320,   320,   135,   318,   323,
      66,    84,    85,   129,   263,   309,   310,   311,   433,   216,
     495,     3,   495,   474,   106,   375,   170,   479,   483,   495,
      21,   483,   483,   266,   474,   170,   170,   479,   485,   511,
     158,   201,   242,   420,   483,   479,   406,   268,   482,   483,
     483,   483,   420,   483,   420,   420,   420,   407,   408,   266,
     183,   266,   414,   518,   414,   414,   414,   183,   473,   204,
     479,   414,   183,   473,   414,   132,   167,   169,   479,     3,
     183,   254,   259,   514,   516,   216,   274,   495,   479,   479,
     479,   479,   479,   422,   170,   248,   262,   348,   445,   495,
       6,   495,   433,   371,   370,   248,   467,   260,   495,   304,
     192,   299,   216,   495,   301,   304,   370,   262,   262,   170,
     248,   170,   248,   170,   384,   170,   170,   335,     3,   428,
     428,     3,   266,   183,   266,     3,   429,     3,     3,     3,
     429,   429,     3,     3,     6,   438,   110,   134,   143,   158,
     164,   201,   207,   378,   388,   389,   390,   391,   332,   328,
     262,   170,   248,   224,   245,   170,   170,   170,   309,     3,
       3,     4,   312,   311,   432,   179,   248,   262,   475,   170,
     248,   262,   170,   170,   159,   190,   198,   215,   229,   238,
     249,   441,   475,   248,   440,   484,   170,   484,   479,   170,
     235,   170,   170,   170,   479,   170,   479,   479,   479,   441,
       3,   441,   185,   411,   185,   413,   185,   412,   411,   254,
     438,   488,   489,   511,   413,   488,   412,   479,   514,   179,
     216,   225,   248,   254,   255,   259,   515,     3,   194,   262,
     351,   495,   183,   262,   478,   499,   495,   183,   262,   432,
     107,   260,   364,   495,   495,   378,   433,   433,   340,   170,
     170,   170,   248,   441,     3,   441,   248,   426,   170,   170,
     248,   170,   170,   426,   170,   170,   380,   492,   183,   390,
     340,   495,    45,    46,   263,   271,   313,   314,   315,   321,
     313,   313,   313,   318,     3,   495,   476,   479,   495,   183,
     476,   440,   266,   170,   479,   170,   170,   170,   170,   170,
     415,   438,   415,   415,     3,   497,   170,   248,   170,   243,
     170,   514,   514,   514,   495,   204,   352,   353,   479,   495,
     228,   399,   403,   303,   495,   431,     3,   170,     3,   430,
     170,     3,   170,   183,   462,   312,     3,   315,   179,   432,
     403,   194,     3,   403,   266,   441,   266,   489,   479,   179,
     179,   248,   194,   170,   248,   400,   402,   492,   160,   188,
     220,   397,   398,   404,   405,   459,   219,   469,   170,   432,
     170,   266,   170,   381,   170,   514,   170,   170,   441,   441,
     514,   514,   353,    34,    41,   248,   260,   437,   495,     3,
     258,   274,   434,   435,   460,   461,   490,   495,   406,   406,
     405,   397,   158,   201,   242,   421,   155,   217,   454,   470,
     441,   170,   179,   248,   179,   179,   248,   183,   400,   401,
     401,   218,   402,   437,   435,   248,   262,   432,   199,   468,
     471,   495,   261,   155,   514,   514,   400,   264,   264,   183,
     402,   461,   216,   495,   474,   135,   319,     3,   434,   455,
     456,   457,   471,   179,   179,   170,   406,   406,   400,   432,
     475,   248,   224,   245,   458,   319,   170,   476,   456,   403,
     469
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
#line 467 "sql.yacc"
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
#line 493 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 496 "sql.yacc"
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
#line 513 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 518 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 521 "sql.yacc"
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
#line 538 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 544 "sql.yacc"
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
#line 553 "sql.yacc"
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
#line 562 "sql.yacc"
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
#line 571 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 578 "sql.yacc"
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
#line 593 "sql.yacc"
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
#line 648 "sql.yacc"
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
#line 655 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 666 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 669 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 674 "sql.yacc"
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
#line 681 "sql.yacc"
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
#line 698 "sql.yacc"
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
#line 715 "sql.yacc"
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
#line 736 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 745 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 748 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 756 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 759 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 767 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 768 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 775 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 778 "sql.yacc"
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
#line 786 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 789 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 793 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 799 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 800 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 804 "sql.yacc"
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
#line 814 "sql.yacc"
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
#line 828 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 829 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 834 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 839 "sql.yacc"
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
#line 847 "sql.yacc"
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
#line 855 "sql.yacc"
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
#line 863 "sql.yacc"
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
#line 871 "sql.yacc"
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
#line 883 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 883 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 887 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 891 "sql.yacc"
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
#line 898 "sql.yacc"
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
#line 905 "sql.yacc"
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
#line 912 "sql.yacc"
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
#line 921 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 925 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 932 "sql.yacc"
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
#line 944 "sql.yacc"
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
#line 955 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 961 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 965 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 969 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 974 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 978 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 981 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 985 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 988 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 995 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 996 "sql.yacc"
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
#line 1006 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1007 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1012 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1016 "sql.yacc"
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
#line 1025 "sql.yacc"
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
#line 1034 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1041 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 1044 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 1050 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1053 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1064 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 1068 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1073 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1080 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1083 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1092 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1095 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1099 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1103 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1107 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1111 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1115 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1123 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1127 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1135 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1138 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1145 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1148 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1155 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1158 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1166 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1175 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1178 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1184 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1187 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1193 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1200 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1201 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1205 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1213 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1217 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1224 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1226 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1231 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1232 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1237 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1238 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1244 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1245 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1259 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1265 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1265 "sql.yacc"
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
#line 1274 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1274 "sql.yacc"
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
#line 1283 "sql.yacc"
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
#line 1308 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1311 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1319 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1322 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1329 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1332 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1340 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1341 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1347 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1348 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1356 "sql.yacc"
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
#line 1374 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1378 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1383 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1384 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1394 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1403 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1407 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1412 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1416 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1420 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1424 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1427 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1434 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1435 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1436 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1440 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1441 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1442 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1443 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1444 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1445 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1446 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1454 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1455 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1456 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1457 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1467 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1468 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1469 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1473 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1474 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1481 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1484 "sql.yacc"
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
#line 1493 "sql.yacc"
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
#line 1504 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1506 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1512 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1518 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1528 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1535 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1537 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1543 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1546 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1547 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1554 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1563 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1570 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1582 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1588 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1593 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1597 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1603 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1611 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1616 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1619 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1622 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1629 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1630 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1631 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1632 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1638 "sql.yacc"
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
#line 1661 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1665 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1667 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1674 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1677 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1683 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1691 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1696 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1702 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1707 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1713 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1716 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1721 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1730 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1739 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1748 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1754 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1757 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1768 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1777 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1784 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1790 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1791 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1794 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1799 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1810 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1814 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1822 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1826 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1830 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1834 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1841 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1846 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1854 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1857 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1863 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1866 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1871 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1876 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1889 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1892 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1898 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1901 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1907 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1910 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1916 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1919 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1926 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1930 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1941 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1941 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1942 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1942 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1943 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1943 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1946 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1956 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1957 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1962 "sql.yacc"
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
#line 1971 "sql.yacc"
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
#line 1979 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1982 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1985 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1989 "sql.yacc"
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
#line 1996 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 1999 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 2003 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 2006 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 2009 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 2012 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 2018 "sql.yacc"
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
#line 2025 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 2028 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 2031 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 2034 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 2035 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 2040 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 2043 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 2046 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 2049 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 2056 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 2057 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 2058 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 2062 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2069 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 2070 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 2071 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 2075 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 2089 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2104 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2108 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2109 "sql.yacc"
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
#line 2118 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2120 "sql.yacc"
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
#line 2129 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2132 "sql.yacc"
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
#line 2140 "sql.yacc"
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
#line 2150 "sql.yacc"
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
#line 2158 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 2160 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 2161 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 2162 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 2163 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2164 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2165 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 2166 "sql.yacc"
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
#line 2174 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 2175 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2176 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2177 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2178 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2179 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2180 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2181 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2182 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2183 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2184 "sql.yacc"
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
#line 2194 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2195 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2202 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 2206 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 2231 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 2232 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 2236 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 2244 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 2247 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 2254 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 2257 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 2267 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 2270 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 2273 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 2276 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 2283 "sql.yacc"
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
#line 2290 "sql.yacc"
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
#line 2298 "sql.yacc"
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
#line 2307 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 2318 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2330 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2331 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 2341 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 2386 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2387 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2388 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2393 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2394 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 2402 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2409 "sql.yacc"
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
#line 2420 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2421 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2434 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2435 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2439 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2443 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2444 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2447 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2453 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2457 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2480 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2490 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2493 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2499 "sql.yacc"
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
#line 2508 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2512 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2519 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2521 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2523 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2527 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2533 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2536 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2542 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2543 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2550 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2563 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2573 "sql.yacc"
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
#line 2580 "sql.yacc"
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
#line 2597 "sql.yacc"
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
#line 2604 "sql.yacc"
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
#line 2629 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2631 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2633 "sql.yacc"
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
#line 2654 "sql.yacc"
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
#line 2697 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2698 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2712 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2715 "sql.yacc"
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
#line 2722 "sql.yacc"
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
#line 2732 "sql.yacc"
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
#line 2750 "sql.yacc"
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
#line 2763 "sql.yacc"
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

  case 448:

/* Line 1464 of yacc.c  */
#line 2778 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2780 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2786 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2787 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2788 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2789 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2799 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item_list));
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2806 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2809 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2815 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2818 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2823 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2832 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2835 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2839 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2846 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2849 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2852 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2855 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2858 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2861 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2864 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2865 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2866 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2867 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2868 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2869 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2870 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2871 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2872 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2874 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2878 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2882 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2886 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2890 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2894 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2898 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2902 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2905 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2908 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2911 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2914 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2917 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2920 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2923 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2926 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2930 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2934 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2938 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2946 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2949 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 2958 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 2964 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 2971 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 2974 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 2998 "sql.yacc"
    {(yyval.str_list)=NULL;}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 2999 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(2) - (4)].str));  add_str_list((yyval.str_list),(yyvsp[(4) - (4)].str));}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 3000 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(1) - (3)].str));  add_str_list((yyval.str_list),(yyvsp[(3) - (3)].str));}
    break;

  case 507:

/* Line 1464 of yacc.c  */
#line 3004 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 3007 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 3013 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 3014 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 3015 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 3016 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 3017 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 3018 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 3023 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 3027 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 3031 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 3035 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 3042 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 3045 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 3050 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 3051 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 3052 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 3054 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3060 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3070 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3074 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3078 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3082 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3086 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3090 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3094 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3098 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3106 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3116 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3121 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3125 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3129 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3133 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3137 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3142 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3146 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3150 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3158 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3161 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3166 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3167 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3168 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3173 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 550:

/* Line 1464 of yacc.c  */
#line 3174 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3175 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 553:

/* Line 1464 of yacc.c  */
#line 3186 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 555:

/* Line 1464 of yacc.c  */
#line 3192 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 557:

/* Line 1464 of yacc.c  */
#line 3197 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 562:

/* Line 1464 of yacc.c  */
#line 3248 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3255 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3261 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 567:

/* Line 1464 of yacc.c  */
#line 3276 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3277 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 570:

/* Line 1464 of yacc.c  */
#line 3279 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3281 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3284 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3288 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 575:

/* Line 1464 of yacc.c  */
#line 3297 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3303 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3304 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3307 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 579:

/* Line 1464 of yacc.c  */
#line 3312 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 3313 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 582:

/* Line 1464 of yacc.c  */
#line 3317 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3318 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3328 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3329 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3330 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3331 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3332 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3333 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3334 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3335 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3339 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3345 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3347 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3366 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3374 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3381 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3382 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3383 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3384 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3389 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3390 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3391 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3392 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3393 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3398 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 3399 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 3415 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 3416 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 3417 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 3418 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 3419 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 3420 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 3421 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 3422 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 3423 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3424 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3426 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 3427 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 3428 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 3429 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3434 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3437 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3446 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 3447 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3448 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3449 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 3450 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 3451 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 3455 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3456 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1464 of yacc.c  */
#line 8910 "y.tab.c"
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
#line 3462 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

