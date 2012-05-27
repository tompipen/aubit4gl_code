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
     INT_VALUE = 2247,
     NAMED = 2248,
     NAMED_GEN = 2249,
     CHAR_VALUE = 2250,
     NOT_USED_1 = 2251,
     NOT_USED_2 = 2252,
     NOT_USED_3 = 2253,
     NOT_USED_4 = 2254,
     NOT_USED_5 = 2255,
     NOT_USED_6 = 2256,
     NOT_USED_7 = 2257,
     NOT_USED_8 = 2258,
     NUMBER_VALUE = 2259,
     SEMICOLON = 2260,
     QUESTION_MARK = 2261,
     CLINE = 2262,
     CH = 2263,
     MARK_VAR = 2264,
     END_MARK_VAR = 2265,
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
     UIBROWSER = 1037,
     UIGANTT = 1038,
     UIFORM = 1041,
     USING_BTREE = 1057,
     USING_RTREE = 1058,
     SET_BUFFERED_LOG = 1077,
     SET_LOG = 1080,
     MDY = 1082,
     WEEKDAY = 1083,
     MODE_ANSI = 1086,
     START_DATABASE = 1087,
     WITH_LOG_IN = 1088,
     SET_CONSTRAINTS_ALL_IMMEDIATE = 1089,
     DATETIME_VALUE = 1102,
     INTERVAL_VALUE = 1103,
     RECOVER_TABLE = 1104,
     ROLLFORWARD_DATABASE = 1105,
     CONCAT_PIPES = 1119,
     DROP_TRIGGER = 1121,
     DROP_AUDIT_FOR = 1122,
     CREATE_AUDIT_FOR = 1123,
     EXECUTE_PROCEDURE = 1127,
     ALTER_TABLE = 1134,
     ALTER_INDEX = 1135,
     NEXT_SIZE = 1136,
     KW_WHENEVER_SIGNAL = 1173,
     KW_SIGNAL_TOKEN = 1174,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1175,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1176,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1177,
     XSET_MULTIPLY_EQUAL = 1178,
     XSET_OPEN_BRACKET = 1179,
     CREATE_DATABASE = 1182,
     DROP_DATABASE = 1183,
     ADD_CONSTRAINT = 1185,
     DROP_CONSTRAINT = 1186,
     DROP_SYNONYM = 1187,
     CONSTRAINT = 1188,
     NOT_FIELD_TOUCHED_CURRENT = 1191,
     FIELD_TOUCHED_CURRENT = 1192,
     OBJECT_FUNCTION = 1194,
     DOUBLE_PRECISION = 1200,
     COUNT_MULTIPLY = 1201,
     KW_ASCII_OPEN_BRACKET = 1210,
     MODIFY_NEXT_SIZE = 1222,
     LOCK_MODE_PAGE = 1223,
     LOCK_MODE_ROW = 1224,
     TO_UI = 1229,
     UNITS_YEAR = 1232,
     UNITS_MONTH = 1233,
     UNITS_DAY = 1234,
     UNITS_HOUR = 1235,
     UNITS_MINUTE = 1236,
     UNITS_SECOND = 1237,
     TO_CLUSTER = 1242,
     TO_NOT_CLUSTER = 1243,
     CREATE_UC_IDX = 1245,
     CREATE_U_IDX = 1246,
     CREATE_C_IDX = 1247,
     CREATE_IDX = 1248,
     DOUBLE_COLON = 1258,
     SQLSICS = 1264,
     CREATE_SCHEMA = 1265,
     SQLSIRR = 1266,
     UPDATESTATS_T = 1267,
     SQLSICR = 1268,
     SQLSIDR = 1279,
     CREATE_TEMP_TABLE = 1280,
     WITH_CHECK_OPTION = 1288,
     WITH_GRANT_OPTION = 1289,
     SQLSLMNW = 1290,
     WHERE_CURRENT_OF = 1296,
     NOT_NULL_UNIQUE = 1304,
     SQLSLMW = 1311,
     ALL_PRIVILEGES = 1313,
     CREATE_SYNONYM = 1317,
     DROP_TABLE = 1318,
     INEXCLUSIVE = 1320,
     REPORT_TO_FILE = 1321,
     REPORT_TO_UI = 1322,
     UPDATESTATS = 1327,
     CREATE_TABLE = 1353,
     DEFAULT_NULL = 1354,
     DEFAULT_TODAY = 1355,
     DEFAULT_USER = 1356,
     EXIT_TODO = 1363,
     CONTINUE_TODO = 1364,
     UNLOCK_TABLE = 1371,
     ROLLBACK_W = 1379,
     SQLSEON = 1381,
     SQLSEOFF = 1382,
     CREATE_VIEW = 1386,
     DELETE_FROM = 1387,
     EXTENT_SIZE = 1394,
     FOREIGN_KEY = 1395,
     INSERT_INTO = 1398,
     IS_NOT_NULL = 1400,
     NOT_MATCHES = 1403,
     PRIMARY_KEY = 1409,
     WITH_NO_LOG = 1416,
     INSHARE = 1419,
     BEGIN_WORK = 1425,
     DROP_INDEX = 1430,
     FOR_UPDATE_OF = 1436,
     FOR_UPDATE = 1437,
     LOCK_TABLE = 1442,
     NOT_EXISTS = 1444,
     REFERENCES = 1446,
     RENCOL = 1447,
     SMALLFLOAT = 1449,
     COMMIT_W = 1460,
     RENTAB = 1467,
     KW_CHAR = 1470,
     NCHAR = 1471,
     NVARCHAR = 1472,
     DELIMITER = 1474,
     DROP_VIEW = 1476,
     EXCLUSIVE = 1479,
     GREATER_THAN_EQ = 1483,
     INTO_TEMP = 1485,
     DATABASE = 1509,
     DATETIME = 1510,
     DISTINCT = 1512,
     FRACTION = 1519,
     GROUP_BY = 1521,
     INTERVAL = 1522,
     NOT_LIKE = 1524,
     NOT_ILIKE = 1525,
     NOT_NULL = 1526,
     RESOURCE = 1532,
     SMALLINT = 1533,
     IS_NULL = 1539,
     LESS_THAN_EQ = 1540,
     BETWEEN = 1542,
     CLOSE_BRACKET = 1545,
     CONNECT = 1548,
     KW_CURRENT = 1549,
     KW_DECIMAL = 1551,
     KW_DEFAULT = 1553,
     FGL_SYNCFIELDS = 1561,
     INTEGER = 1562,
     SERIAL8 = 1564,
     MATCHES = 1567,
     VARCHAR = 1580,
     CLOSE_SQUARE = 1583,
     GREATER_THAN = 1584,
     KW_FALSE = 1585,
     NOT_IN = 1586,
     OPEN_BRACKET_SELECT = 1588,
     OPEN_BRACKET = 1589,
     KW_DELETE = 1597,
     KW_ESCAPE = 1600,
     EXISTS = 1601,
     EXTEND = 1602,
     HAVING = 1606,
     KW_INSERT = 1608,
     MINUTE = 1612,
     MODIFY = 1613,
     EQUAL = 1615,
     NOT_EQUAL = 1616,
     OPEN_SQUARE = 1618,
     PUBLIC = 1622,
     KW_RETURN_KEY = 1625,
     REVOKE = 1627,
     SECOND = 1631,
     KW_SELECT = 1635,
     SERIAL = 1636,
     UNIQUE = 1639,
     KW_UPDATE = 1641,
     VALUES = 1642,
     KW_NULL = 1645,
     KW_TRUE = 1646,
     ALTER = 1648,
     CHECK = 1654,
     COUNT = 1658,
     KW_FIRST = 1663,
     KW_FLOAT = 1664,
     GRANT = 1667,
     INDEX = 1670,
     LESS_THAN = 1673,
     MONEY = 1675,
     MONTH = 1676,
     KW_MULTIPLY = 1678,
     ORDER = 1679,
     OUTER = 1680,
     UNION = 1689,
     WHERE = 1692,
     KW_BYTE = 1699,
     CASE = 1701,
     KW_DATE = 1703,
     DESC = 1704,
     KW_DIVIDE = 1705,
     DROP = 1708,
     ELSE = 1709,
     FROM = 1713,
     HOUR = 1719,
     INTO = 1720,
     LIKE = 1723,
     REAL = 1732,
     SOME = 1737,
     KW_TEXT = 1741,
     KW_THEN = 1742,
     USER = 1743,
     WHEN = 1745,
     YEAR = 1748,
     KW_DOW = 1749,
     XSET = 1751,
     ADD = 1752,
     ALL = 1753,
     KW_AND = 1754,
     ANY = 1755,
     ASC = 1756,
     AVG = 1757,
     COLON = 1758,
     KW_COMMA = 1759,
     DAY = 1760,
     DBA = 1761,
     KW_FOR = 1765,
     XMAX = 1770,
     XMIN = 1771,
     KW_MINUS = 1772,
     KW_MOD = 1773,
     KW_NOT = 1774,
     KW_SUM = 1781,
     ATSIGN = 1784,
     KW_PLUS = 1785,
     KW_AS = 1791,
     KW_BY = 1793,
     KW_DOT = 1794,
     KW_IN = 1797,
     KW_ON = 1799,
     KW_OR = 1800,
     KW_TO = 1801,
     BEFORE = 1839,
     END = 1843,
     TILDE = 1850,
     ILIKE = 1851,
     FILLFACTOR = 1854,
     TIME = 1859,
     KW_TODAY = 1866,
     KW_ROWID = 1867,
     TIMESTAMP = 2215,
     KWPIPE = 2245
   };
#endif
/* Tokens.  */
#define INT_VALUE 2247
#define NAMED 2248
#define NAMED_GEN 2249
#define CHAR_VALUE 2250
#define NOT_USED_1 2251
#define NOT_USED_2 2252
#define NOT_USED_3 2253
#define NOT_USED_4 2254
#define NOT_USED_5 2255
#define NOT_USED_6 2256
#define NOT_USED_7 2257
#define NOT_USED_8 2258
#define NUMBER_VALUE 2259
#define SEMICOLON 2260
#define QUESTION_MARK 2261
#define CLINE 2262
#define CH 2263
#define MARK_VAR 2264
#define END_MARK_VAR 2265
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
#define UIBROWSER 1037
#define UIGANTT 1038
#define UIFORM 1041
#define USING_BTREE 1057
#define USING_RTREE 1058
#define SET_BUFFERED_LOG 1077
#define SET_LOG 1080
#define MDY 1082
#define WEEKDAY 1083
#define MODE_ANSI 1086
#define START_DATABASE 1087
#define WITH_LOG_IN 1088
#define SET_CONSTRAINTS_ALL_IMMEDIATE 1089
#define DATETIME_VALUE 1102
#define INTERVAL_VALUE 1103
#define RECOVER_TABLE 1104
#define ROLLFORWARD_DATABASE 1105
#define CONCAT_PIPES 1119
#define DROP_TRIGGER 1121
#define DROP_AUDIT_FOR 1122
#define CREATE_AUDIT_FOR 1123
#define EXECUTE_PROCEDURE 1127
#define ALTER_TABLE 1134
#define ALTER_INDEX 1135
#define NEXT_SIZE 1136
#define KW_WHENEVER_SIGNAL 1173
#define KW_SIGNAL_TOKEN 1174
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1175
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1176
#define XSET_ident_DOT_MULTIPLY_EQUAL 1177
#define XSET_MULTIPLY_EQUAL 1178
#define XSET_OPEN_BRACKET 1179
#define CREATE_DATABASE 1182
#define DROP_DATABASE 1183
#define ADD_CONSTRAINT 1185
#define DROP_CONSTRAINT 1186
#define DROP_SYNONYM 1187
#define CONSTRAINT 1188
#define NOT_FIELD_TOUCHED_CURRENT 1191
#define FIELD_TOUCHED_CURRENT 1192
#define OBJECT_FUNCTION 1194
#define DOUBLE_PRECISION 1200
#define COUNT_MULTIPLY 1201
#define KW_ASCII_OPEN_BRACKET 1210
#define MODIFY_NEXT_SIZE 1222
#define LOCK_MODE_PAGE 1223
#define LOCK_MODE_ROW 1224
#define TO_UI 1229
#define UNITS_YEAR 1232
#define UNITS_MONTH 1233
#define UNITS_DAY 1234
#define UNITS_HOUR 1235
#define UNITS_MINUTE 1236
#define UNITS_SECOND 1237
#define TO_CLUSTER 1242
#define TO_NOT_CLUSTER 1243
#define CREATE_UC_IDX 1245
#define CREATE_U_IDX 1246
#define CREATE_C_IDX 1247
#define CREATE_IDX 1248
#define DOUBLE_COLON 1258
#define SQLSICS 1264
#define CREATE_SCHEMA 1265
#define SQLSIRR 1266
#define UPDATESTATS_T 1267
#define SQLSICR 1268
#define SQLSIDR 1279
#define CREATE_TEMP_TABLE 1280
#define WITH_CHECK_OPTION 1288
#define WITH_GRANT_OPTION 1289
#define SQLSLMNW 1290
#define WHERE_CURRENT_OF 1296
#define NOT_NULL_UNIQUE 1304
#define SQLSLMW 1311
#define ALL_PRIVILEGES 1313
#define CREATE_SYNONYM 1317
#define DROP_TABLE 1318
#define INEXCLUSIVE 1320
#define REPORT_TO_FILE 1321
#define REPORT_TO_UI 1322
#define UPDATESTATS 1327
#define CREATE_TABLE 1353
#define DEFAULT_NULL 1354
#define DEFAULT_TODAY 1355
#define DEFAULT_USER 1356
#define EXIT_TODO 1363
#define CONTINUE_TODO 1364
#define UNLOCK_TABLE 1371
#define ROLLBACK_W 1379
#define SQLSEON 1381
#define SQLSEOFF 1382
#define CREATE_VIEW 1386
#define DELETE_FROM 1387
#define EXTENT_SIZE 1394
#define FOREIGN_KEY 1395
#define INSERT_INTO 1398
#define IS_NOT_NULL 1400
#define NOT_MATCHES 1403
#define PRIMARY_KEY 1409
#define WITH_NO_LOG 1416
#define INSHARE 1419
#define BEGIN_WORK 1425
#define DROP_INDEX 1430
#define FOR_UPDATE_OF 1436
#define FOR_UPDATE 1437
#define LOCK_TABLE 1442
#define NOT_EXISTS 1444
#define REFERENCES 1446
#define RENCOL 1447
#define SMALLFLOAT 1449
#define COMMIT_W 1460
#define RENTAB 1467
#define KW_CHAR 1470
#define NCHAR 1471
#define NVARCHAR 1472
#define DELIMITER 1474
#define DROP_VIEW 1476
#define EXCLUSIVE 1479
#define GREATER_THAN_EQ 1483
#define INTO_TEMP 1485
#define DATABASE 1509
#define DATETIME 1510
#define DISTINCT 1512
#define FRACTION 1519
#define GROUP_BY 1521
#define INTERVAL 1522
#define NOT_LIKE 1524
#define NOT_ILIKE 1525
#define NOT_NULL 1526
#define RESOURCE 1532
#define SMALLINT 1533
#define IS_NULL 1539
#define LESS_THAN_EQ 1540
#define BETWEEN 1542
#define CLOSE_BRACKET 1545
#define CONNECT 1548
#define KW_CURRENT 1549
#define KW_DECIMAL 1551
#define KW_DEFAULT 1553
#define FGL_SYNCFIELDS 1561
#define INTEGER 1562
#define SERIAL8 1564
#define MATCHES 1567
#define VARCHAR 1580
#define CLOSE_SQUARE 1583
#define GREATER_THAN 1584
#define KW_FALSE 1585
#define NOT_IN 1586
#define OPEN_BRACKET_SELECT 1588
#define OPEN_BRACKET 1589
#define KW_DELETE 1597
#define KW_ESCAPE 1600
#define EXISTS 1601
#define EXTEND 1602
#define HAVING 1606
#define KW_INSERT 1608
#define MINUTE 1612
#define MODIFY 1613
#define EQUAL 1615
#define NOT_EQUAL 1616
#define OPEN_SQUARE 1618
#define PUBLIC 1622
#define KW_RETURN_KEY 1625
#define REVOKE 1627
#define SECOND 1631
#define KW_SELECT 1635
#define SERIAL 1636
#define UNIQUE 1639
#define KW_UPDATE 1641
#define VALUES 1642
#define KW_NULL 1645
#define KW_TRUE 1646
#define ALTER 1648
#define CHECK 1654
#define COUNT 1658
#define KW_FIRST 1663
#define KW_FLOAT 1664
#define GRANT 1667
#define INDEX 1670
#define LESS_THAN 1673
#define MONEY 1675
#define MONTH 1676
#define KW_MULTIPLY 1678
#define ORDER 1679
#define OUTER 1680
#define UNION 1689
#define WHERE 1692
#define KW_BYTE 1699
#define CASE 1701
#define KW_DATE 1703
#define DESC 1704
#define KW_DIVIDE 1705
#define DROP 1708
#define ELSE 1709
#define FROM 1713
#define HOUR 1719
#define INTO 1720
#define LIKE 1723
#define REAL 1732
#define SOME 1737
#define KW_TEXT 1741
#define KW_THEN 1742
#define USER 1743
#define WHEN 1745
#define YEAR 1748
#define KW_DOW 1749
#define XSET 1751
#define ADD 1752
#define ALL 1753
#define KW_AND 1754
#define ANY 1755
#define ASC 1756
#define AVG 1757
#define COLON 1758
#define KW_COMMA 1759
#define DAY 1760
#define DBA 1761
#define KW_FOR 1765
#define XMAX 1770
#define XMIN 1771
#define KW_MINUS 1772
#define KW_MOD 1773
#define KW_NOT 1774
#define KW_SUM 1781
#define ATSIGN 1784
#define KW_PLUS 1785
#define KW_AS 1791
#define KW_BY 1793
#define KW_DOT 1794
#define KW_IN 1797
#define KW_ON 1799
#define KW_OR 1800
#define KW_TO 1801
#define BEFORE 1839
#define END 1843
#define TILDE 1850
#define ILIKE 1851
#define FILLFACTOR 1854
#define TIME 1859
#define KW_TODAY 1866
#define KW_ROWID 1867
#define TIMESTAMP 2215
#define KWPIPE 2245




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
#line 856 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 868 "y.tab.c"

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
#define YYLAST   2195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  287
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  632
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1113

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2265

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
       2,     2,    42,     2,     2,     2,    43,    44,    45,     2,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    47,    48,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    49,     2,     2,
      50,     2,    51,    52,     2,     2,    53,    54,    55,    56,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    57,    58,    59,    60,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
       2,    62,    63,    64,     2,     2,     2,    65,     2,     2,
       2,     2,     2,     2,    66,    67,    68,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    70,    71,    72,    73,    74,    75,
       2,     2,    76,    77,     2,    78,    79,    80,    81,     2,
       2,    82,    83,     2,    84,     2,     2,     2,     2,     2,
      85,    86,     2,     2,     2,     2,     2,     2,     2,     2,
      87,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    88,    89,    90,     2,     2,     2,     2,    91,
       2,     2,    92,    93,    94,    95,    96,    97,     2,     2,
       2,     2,    98,    99,     2,   100,   101,   102,   103,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   104,     2,
       2,     2,     2,     2,   105,   106,   107,   108,   109,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   110,
     111,     2,     2,     2,     2,     2,     2,     2,   112,   113,
     114,     2,     2,     2,     2,     2,   115,     2,     2,     2,
       2,     2,     2,     2,   116,     2,     2,     2,     2,     2,
       2,   117,     2,   118,     2,     2,     2,   119,   120,     2,
     121,   122,   123,     2,     2,     2,     2,   124,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   125,   126,   127,   128,     2,     2,     2,
       2,     2,     2,   129,   130,     2,     2,     2,     2,     2,
       2,   131,     2,     2,     2,     2,     2,     2,     2,   132,
       2,   133,   134,     2,     2,     2,   135,   136,     2,     2,
       2,     2,     2,     2,   137,   138,     2,     2,   139,     2,
     140,     2,     2,   141,     2,     2,     2,     2,     2,   142,
       2,     2,     2,     2,     2,     2,   143,     2,     2,   144,
       2,     2,     2,     2,     2,   145,     2,     2,     2,     2,
     146,     2,     2,     2,     2,     2,   147,   148,     2,     2,
       2,     2,   149,     2,   150,     2,   151,   152,     2,   153,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     154,     2,     2,     2,     2,     2,     2,   155,     2,     2,
     156,   157,   158,     2,   159,     2,   160,     2,     2,   161,
       2,     2,     2,   162,     2,   163,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   164,
     165,     2,   166,     2,     2,     2,     2,     2,     2,   167,
       2,   168,   169,     2,   170,   171,   172,     2,     2,     2,
       2,     2,   173,   174,     2,     2,     2,     2,     2,   175,
     176,     2,   177,     2,     2,   178,     2,     2,   179,   180,
       2,   181,     2,   182,     2,     2,     2,     2,     2,     2,
       2,   183,   184,     2,   185,     2,     2,   186,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     187,     2,     2,   188,   189,   190,   191,     2,   192,   193,
       2,     2,     2,     2,     2,     2,     2,   194,     2,     2,
     195,   196,   197,     2,     2,     2,   198,     2,   199,     2,
       2,     2,   200,   201,     2,   202,   203,     2,   204,     2,
       2,     2,   205,     2,     2,   206,     2,   207,     2,     2,
       2,   208,     2,     2,     2,   209,   210,     2,     2,   211,
       2,   212,   213,     2,     2,   214,   215,     2,   216,     2,
       2,     2,     2,     2,   217,     2,     2,     2,   218,     2,
       2,     2,     2,   219,   220,     2,     2,   221,     2,     2,
     222,     2,     2,   223,     2,   224,   225,     2,   226,   227,
     228,     2,     2,     2,     2,     2,     2,     2,     2,   229,
       2,     2,   230,     2,     2,     2,     2,     2,     2,   231,
       2,   232,     2,   233,   234,   235,     2,     2,   236,   237,
       2,     2,     2,   238,     2,     2,     2,     2,     2,   239,
     240,     2,     2,   241,     2,     2,     2,     2,     2,     2,
       2,     2,   242,     2,     2,     2,     2,   243,     2,     2,
       2,   244,   245,   246,     2,   247,     2,     2,   248,   249,
       2,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,     2,     2,     2,   261,     2,     2,     2,     2,
     262,   263,   264,   265,   266,     2,     2,     2,     2,     2,
       2,   267,     2,     2,   268,   269,     2,     2,     2,     2,
       2,   270,     2,   271,   272,     2,     2,   273,     2,   274,
     275,   276,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   277,
       2,     2,     2,   278,     2,     2,     2,     2,     2,     2,
     279,   280,     2,     2,   281,     2,     2,     2,     2,   282,
       2,     2,     2,     2,     2,     2,   283,   284,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   285,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   286,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21
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
     495,     0,    -1,   212,   486,   291,   289,    -1,    -1,   115,
     490,    -1,   230,   400,    -1,    -1,   115,   490,    -1,   230,
     400,    -1,    75,   296,   178,   202,   193,   297,   178,    -1,
      71,   297,   178,    -1,    72,   297,   178,    -1,   250,   292,
      -1,    74,   297,    -1,    73,   297,    -1,   295,    -1,   292,
     258,   295,    -1,   294,    -1,   268,   294,    -1,   489,   426,
      -1,   489,   272,   489,   426,    -1,   489,   272,   489,   272,
     489,   426,    -1,   489,   272,   226,    -1,   293,   202,   298,
      -1,   293,    -1,   296,   258,   293,    -1,   298,    -1,   297,
     258,   298,    -1,   473,    -1,   214,    -1,   300,    -1,   120,
     486,    -1,   160,   486,    -1,   146,   488,    -1,    62,   489,
      -1,   311,    -1,   302,    -1,   125,   486,   193,   316,   178,
     303,    -1,   111,   486,   193,   316,   178,   312,   303,   312,
      -1,    -1,   304,    -1,   305,    -1,   304,   305,    -1,   273,
     306,    -1,   137,     3,    -1,    68,     3,    -1,    89,    -1,
      90,    -1,     4,    -1,    -1,   308,    -1,   309,    -1,   308,
     309,    -1,   273,   306,    -1,   281,     3,    -1,    47,    -1,
      48,    -1,   486,    -1,   101,   488,   274,   310,   193,   314,
     178,   307,    -1,   100,   488,   274,   310,   193,   314,   178,
     307,    -1,   102,   488,   274,   310,   193,   314,   178,   307,
      -1,   103,   488,   274,   310,   193,   314,   178,   307,    -1,
      76,   499,    -1,    77,   499,    -1,   119,   486,   261,   486,
      -1,    64,   486,   273,     6,    -1,    63,   486,    -1,    80,
     486,    -1,    59,   486,    -1,    60,   489,    -1,    -1,   143,
      -1,    -1,   143,    -1,   315,    -1,   314,   258,   315,    -1,
     489,   255,    -1,   489,   234,    -1,   489,    -1,   317,    -1,
     316,   258,   317,    -1,   380,    -1,   378,    -1,    66,   489,
     319,    -1,    67,   488,    98,    -1,    67,   488,    99,    -1,
     320,    -1,   319,   258,   320,    -1,   321,    -1,   324,    -1,
     327,    -1,   332,    -1,   335,    -1,   331,    -1,   330,    -1,
     251,   322,    -1,   251,   193,   323,   178,    -1,   317,    -1,
     317,   277,   489,    -1,   322,    -1,   323,   258,   322,    -1,
     236,   326,    -1,   236,   193,   325,   178,    -1,   326,    -1,
     325,   258,   326,    -1,   489,    -1,   201,   329,    -1,   201,
     193,   328,   178,    -1,   329,    -1,   328,   258,   329,    -1,
     317,    -1,    89,    -1,    90,    -1,    88,     3,    -1,    78,
     378,   334,    -1,    78,   193,   333,   178,    -1,   378,   334,
      -1,   333,   258,   378,   334,    -1,    -1,    81,   489,    -1,
      79,   336,    -1,    79,   193,   336,   178,    -1,   337,    -1,
     336,   258,   337,    -1,   489,    -1,   132,    -1,    -1,   139,
     340,   486,   343,   341,    -1,    -1,   213,   342,   193,   346,
     178,    -1,   466,    -1,    -1,   193,   344,   178,    -1,   345,
      -1,   344,   258,   345,    -1,   489,    -1,   489,   272,   489,
      -1,   347,    -1,   346,   258,   347,    -1,   473,    -1,   214,
      -1,   136,   486,   290,    -1,   145,    -1,   154,    -1,    -1,
     161,    -1,   353,    -1,    54,   489,    55,     6,    53,    -1,
      54,   489,    55,     6,    -1,    56,    -1,    49,    -1,    50,
      -1,   108,   489,    -1,   124,    -1,   350,    -1,   349,    -1,
     338,    -1,   352,    -1,   386,    -1,   390,    -1,   436,    -1,
     299,    -1,   301,    -1,   318,    -1,   221,   359,   274,   486,
     276,   364,   358,    -1,   207,   359,   274,   486,   238,   364,
      -1,   221,   357,   276,   364,    -1,   207,   357,   238,   364,
      -1,   179,    -1,   173,    -1,   260,    -1,    -1,   113,    -1,
     270,   425,    -1,   118,    -1,   252,    -1,   360,    -1,   361,
      -1,   360,   258,   361,    -1,   209,   362,    -1,   199,    -1,
     194,    -1,   212,   362,    -1,   216,    -1,   222,    -1,    -1,
     193,   363,   178,    -1,   427,    -1,   363,   258,   427,    -1,
     365,    -1,   364,   258,   365,    -1,   205,    -1,   425,    -1,
     135,   486,   367,   270,   457,   369,    -1,    -1,   193,   368,
     178,    -1,   427,    -1,   368,   258,   427,    -1,    -1,   112,
      -1,   217,   193,   456,   178,    -1,   138,   193,   373,   178,
     372,    -1,   151,   374,    -1,   375,    -1,   486,    -1,   486,
     193,   375,   178,    -1,   427,    -1,   375,   258,   427,    -1,
     211,   193,   377,   178,    -1,   166,   193,   377,   178,    -1,
     142,   193,   377,   178,    -1,   427,    -1,   377,   258,   427,
      -1,   376,    -1,   371,    -1,   370,    -1,   182,   432,    -1,
     128,    -1,   127,    -1,   126,    -1,   489,   416,   381,   382,
      -1,    -1,   379,    -1,    -1,   383,    -1,   384,    -1,   383,
     384,    -1,   385,   334,    -1,   172,    -1,   116,    -1,   211,
      -1,   166,    -1,   372,    -1,   217,   193,   456,   178,    -1,
     142,    -1,   106,   387,   389,    -1,   388,    -1,   425,    -1,
     390,    -1,   389,   390,    -1,   366,    -1,   356,    -1,   198,
     400,    -1,   230,   400,    -1,   238,   394,    -1,   396,    -1,
     394,   258,   396,    -1,   394,   258,   228,   396,    -1,   394,
     258,   228,   193,   394,   178,    -1,   394,    34,   395,   274,
     400,    -1,   394,    41,   395,   274,   400,    -1,   394,    -1,
     193,   394,   178,    -1,   486,    -1,   486,   431,    -1,   486,
     270,   431,    -1,    -1,   393,   398,    -1,   399,    -1,   392,
     399,    -1,    -1,   453,    -1,   453,   391,    -1,   391,    -1,
     401,    -1,   400,   275,   401,    -1,   402,    -1,   401,   253,
     402,    -1,   403,    -1,   266,   403,    -1,   413,    -1,   193,
     400,   178,    -1,   196,   467,    -1,   150,   467,    -1,    -1,
     195,   409,    -1,    -1,   195,   409,    -1,    -1,   195,   409,
      -1,   512,    -1,   432,    -1,    -1,   266,    -1,   473,   410,
     175,    -1,   473,   410,   140,    -1,   473,   412,   473,    -1,
     473,   202,   473,    -1,   473,   202,   214,    -1,   473,   410,
     177,   473,   253,   473,    -1,   473,   241,   408,   407,    -1,
     473,   170,   408,   407,    -1,   473,   280,   408,   406,    -1,
     473,   171,   408,   406,    -1,   473,   186,   408,   405,    -1,
     473,   141,   408,   405,    -1,   203,    -1,   223,    -1,   189,
      -1,   279,    -1,   176,    -1,   162,    -1,   411,    -1,   481,
      -1,   404,    -1,   473,    -1,    -1,   252,    -1,   166,    -1,
     211,    -1,    -1,   252,    -1,   166,    -1,   211,    -1,   417,
      -1,   418,    -1,   419,    -1,   421,    -1,   156,    -1,   156,
     193,   422,   178,    -1,   210,    -1,   210,   193,     3,   178,
      -1,   185,    -1,   185,   193,     3,   178,    -1,   181,    -1,
     181,   193,   423,   420,   178,    -1,   224,   193,   423,   420,
     178,    -1,   224,    -1,   233,    -1,   184,    -1,   174,    -1,
     157,    -1,   157,   193,   422,   178,    -1,   158,    -1,   158,
     193,     3,   178,    -1,   158,   193,     3,   258,     3,   178,
      -1,   165,   434,   276,   435,    -1,   165,    -1,   169,   434,
     276,   435,    -1,   458,    -1,   169,    -1,   169,   434,   193,
       3,   178,   276,   435,    -1,   244,    -1,   231,    -1,   187,
      -1,   187,   193,     3,   178,    -1,   187,   193,     3,   258,
       3,   178,    -1,    -1,   258,   424,    -1,   220,   193,   423,
     178,    -1,   242,    -1,   153,    -1,   220,    -1,    85,    -1,
       3,    -1,     3,    -1,     3,    -1,   489,    -1,     6,    -1,
      -1,   204,     3,   188,    -1,   204,     3,   258,     3,   188,
      -1,   430,    -1,   268,   430,    -1,   429,    -1,   268,   429,
      -1,   489,   426,    -1,   484,   272,   489,   426,    -1,   484,
     272,   226,    -1,   284,    -1,   489,   426,    -1,   484,   272,
     489,   426,    -1,   489,   272,   489,   272,   489,   426,    -1,
     484,   272,   226,    -1,   489,    -1,     6,    -1,   491,    -1,
       3,    -1,   447,    -1,    -1,   434,   276,   435,    -1,   248,
      -1,   225,    -1,   259,    -1,   239,    -1,   200,    -1,   208,
      -1,   167,    -1,   248,    -1,   225,    -1,   259,    -1,   239,
      -1,   200,    -1,   208,    -1,   167,    -1,   167,   193,     3,
     178,    -1,   441,    -1,   440,    -1,   437,    -1,   155,   438,
     276,   438,    -1,   152,   484,   272,   439,   276,   439,    -1,
     489,    -1,   489,    -1,   131,   486,    -1,   149,   486,   442,
      -1,   144,    -1,   121,    -1,   444,    -1,   444,   434,   276,
     435,    -1,    57,    -1,   446,    -1,   446,   434,   193,     3,
     178,   276,   435,    -1,   446,   434,   276,   435,    -1,    58,
      -1,   180,   433,    -1,   227,   271,   449,    -1,   450,    -1,
     449,   258,   450,    -1,   451,   452,    -1,     3,    -1,   428,
      -1,    -1,   255,    -1,   234,    -1,   168,   454,    -1,   455,
      -1,   454,   258,   455,    -1,   428,    -1,     3,    -1,   400,
      -1,   466,    -1,   282,    -1,   282,   193,     3,   178,    -1,
     285,    -1,   285,   193,     3,   178,    -1,    -1,    -1,   209,
     468,   469,   460,   470,   461,   493,   397,   463,   464,    -1,
     209,   468,   469,   470,   397,   463,    -1,    -1,   229,   415,
     462,    -1,    -1,   448,    -1,   448,   163,   465,   313,    -1,
     163,   465,   313,    -1,   489,    -1,   209,   468,   469,   470,
     397,    -1,   192,   468,   469,   470,   397,   178,    -1,    -1,
     219,     3,    -1,    -1,   252,    -1,   166,    -1,   211,    -1,
     471,    -1,   472,    -1,   470,   258,   472,    -1,   473,    -1,
     473,   489,    -1,   473,   270,   489,    -1,   512,    -1,   264,
     512,    -1,   269,   512,    -1,   512,   235,   473,    -1,   512,
     480,    -1,   512,   226,   473,    -1,   512,   269,   473,    -1,
     512,   264,   473,    -1,   512,    61,   473,    -1,   432,    -1,
     215,    -1,   190,    -1,   246,    -1,   283,    -1,   284,    -1,
     282,    -1,   226,    -1,    86,    -1,   256,   193,   414,   473,
     178,    -1,   262,   193,   414,   473,   178,    -1,   263,   193,
     414,   473,   178,    -1,   267,   193,   414,   473,   178,    -1,
     218,   193,   414,   473,   178,    -1,     4,   193,   178,    -1,
       4,   193,   477,   178,    -1,   248,   193,   477,   178,    -1,
     225,   193,   477,   178,    -1,   259,   193,   477,   178,    -1,
      51,   193,   477,   178,    -1,    52,   193,   477,   178,    -1,
     249,   193,   477,   178,    -1,   233,   193,   477,   178,    -1,
     193,   473,   178,    -1,   197,   193,   479,   178,    -1,   443,
      -1,   445,    -1,   232,   475,   278,    -1,   232,   400,   475,
     278,    -1,   476,    -1,   475,   476,    -1,   247,   400,   245,
     473,    -1,   237,   473,    -1,   473,    -1,   477,   258,   473,
      -1,    -1,   258,   434,   276,   435,    -1,   434,   276,   435,
      -1,    -1,   505,   478,    -1,   473,   478,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,
     473,   273,   193,   482,   178,    -1,   473,   273,   467,    -1,
     473,   191,   193,   482,   178,    -1,   473,   191,   467,    -1,
     483,    -1,   482,   258,   483,    -1,   505,    -1,   432,    -1,
     264,     3,    -1,   264,   491,    -1,   485,    -1,     6,    -1,
       6,   272,   489,    -1,   489,    -1,   489,   257,   489,    -1,
     489,   257,     6,   272,   489,    -1,   489,   268,   489,    -1,
     489,   268,   489,   257,   489,    -1,   489,   268,   489,   257,
       6,   272,   489,    -1,   487,    -1,     6,   272,   489,    -1,
     489,   272,   489,    -1,     6,    -1,   489,    -1,   489,   257,
     489,    -1,   489,   257,     6,   272,   489,    -1,   489,   268,
     489,    -1,   489,   268,   489,   257,   489,    -1,   489,   268,
     489,   257,     6,   272,   489,    -1,     6,   272,   489,    -1,
       6,    -1,   489,    -1,   489,   257,   489,    -1,   489,   257,
       6,   272,   489,    -1,   489,   268,   489,    -1,   489,   268,
     489,   257,   489,    -1,   489,   268,   489,   257,     6,   272,
     489,    -1,     4,    -1,     4,    -1,    15,    -1,   272,     3,
      -1,     4,    -1,     6,    -1,    -1,   489,    -1,   497,    -1,
     495,    16,   497,    -1,   339,    -1,   288,    -1,   348,    -1,
      -1,   506,    -1,   355,    -1,   498,    -1,   504,    -1,   496,
      -1,   354,    -1,     1,    -1,   500,   501,    -1,   494,    -1,
     459,    -1,    -1,   148,    -1,   147,   502,    -1,   503,    -1,
     502,   258,   503,    -1,   489,    -1,   489,   272,   489,    -1,
       6,   272,   489,   272,   489,    -1,   134,    -1,   133,    -1,
     117,   514,    -1,   114,    -1,   110,    -1,   107,    -1,   105,
      -1,   109,    -1,   511,    -1,    17,    -1,   507,    -1,   164,
     492,   351,    -1,    20,     6,    21,    -1,   193,   508,   178,
      -1,   508,   509,   508,    -1,     3,    -1,   510,     3,    -1,
     269,    -1,   264,    -1,   226,    -1,   235,    -1,   265,    -1,
     269,    -1,   264,    -1,   489,    -1,   489,   272,   226,    -1,
     489,   272,   284,    -1,   489,   272,   489,    -1,   489,   272,
     489,   272,   489,    -1,     6,   272,   489,   272,   489,    -1,
     489,   204,   508,   188,    -1,   489,   272,   489,   204,   508,
     188,    -1,   489,   272,   489,   272,   489,   204,   508,   188,
      -1,     6,   272,   489,   272,   489,   204,   508,   188,    -1,
     489,   204,   508,   258,   508,   188,    -1,   489,   272,   489,
     204,   508,   258,   508,   188,    -1,   489,   272,   489,   272,
     489,   204,   508,   258,   508,   188,    -1,     6,   272,   489,
     272,   489,   204,   508,   258,   508,   188,    -1,   513,    -1,
     513,   104,   416,    -1,   474,    -1,   505,    -1,   467,    -1,
     252,   467,    -1,   254,   467,    -1,   243,   467,    -1,    -1,
       3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   461,   461,   487,   490,   507,   512,   515,   532,   538,
     547,   556,   565,   572,   587,   642,   649,   660,   663,   668,
     675,   692,   709,   730,   739,   742,   750,   753,   761,   762,
     769,   772,   780,   783,   787,   793,   794,   798,   808,   822,
     823,   827,   828,   833,   841,   849,   857,   865,   875,   877,
     877,   880,   881,   885,   892,   899,   906,   915,   919,   926,
     938,   949,   955,   959,   963,   968,   972,   975,   979,   982,
     989,   990,  1000,  1001,  1005,  1006,  1010,  1019,  1028,  1035,
    1038,  1044,  1047,  1058,  1062,  1067,  1074,  1077,  1086,  1089,
    1093,  1097,  1101,  1105,  1109,  1117,  1121,  1129,  1132,  1139,
    1142,  1149,  1152,  1159,  1160,  1165,  1169,  1172,  1178,  1181,
    1187,  1194,  1195,  1199,  1207,  1211,  1218,  1220,  1225,  1226,
    1230,  1232,  1238,  1239,  1242,  1253,  1259,  1259,  1268,  1268,
    1277,  1302,  1305,  1313,  1316,  1323,  1326,  1334,  1335,  1341,
    1342,  1350,  1368,  1372,  1377,  1378,  1388,  1397,  1401,  1405,
    1410,  1414,  1418,  1421,  1428,  1434,  1439,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1461,  1462,  1463,  1464,  1469,  1470,
    1471,  1474,  1475,  1476,  1480,  1481,  1482,  1486,  1487,  1491,
    1498,  1499,  1500,  1507,  1508,  1511,  1512,  1517,  1518,  1523,
    1524,  1529,  1530,  1535,  1542,  1543,  1548,  1549,  1553,  1554,
    1561,  1569,  1576,  1583,  1587,  1588,  1593,  1594,  1600,  1604,
    1609,  1616,  1617,  1623,  1626,  1629,  1636,  1637,  1638,  1639,
    1645,  1668,  1669,  1672,  1674,  1681,  1684,  1690,  1698,  1703,
    1709,  1714,  1720,  1723,  1728,  1736,  1745,  1750,  1754,  1755,
    1761,  1764,  1775,  1784,  1791,  1797,  1798,  1801,  1806,  1817,
    1821,  1828,  1829,  1833,  1837,  1841,  1848,  1853,  1861,  1864,
    1870,  1873,  1878,  1883,  1896,  1899,  1905,  1908,  1914,  1917,
    1923,  1926,  1933,  1937,  1948,  1948,  1949,  1949,  1950,  1950,
    1953,  1958,  1963,  1964,  1969,  1978,  1986,  1989,  1992,  1996,
    2003,  2006,  2010,  2013,  2016,  2019,  2025,  2032,  2035,  2038,
    2041,  2042,  2047,  2050,  2053,  2056,  2063,  2064,  2065,  2069,
    2076,  2077,  2078,  2082,  2096,  2103,  2104,  2105,  2109,  2110,
    2115,  2116,  2125,  2127,  2136,  2139,  2147,  2157,  2165,  2167,
    2168,  2169,  2170,  2171,  2172,  2173,  2181,  2182,  2183,  2184,
    2185,  2186,  2187,  2188,  2189,  2190,  2191,  2201,  2202,  2208,
    2210,  2211,  2212,  2213,  2217,  2221,  2225,  2232,  2233,  2238,
    2239,  2243,  2251,  2254,  2261,  2264,  2274,  2277,  2280,  2283,
    2290,  2297,  2305,  2314,  2321,  2325,  2330,  2331,  2332,  2337,
    2338,  2347,  2347,  2347,  2347,  2347,  2347,  2347,  2348,  2348,
    2348,  2348,  2348,  2348,  2348,  2348,  2393,  2394,  2395,  2400,
    2401,  2404,  2405,  2409,  2416,  2427,  2428,  2441,  2442,  2446,
    2450,  2451,  2454,  2460,  2464,  2487,  2497,  2500,  2506,  2515,
    2519,  2526,  2527,  2529,  2534,  2540,  2543,  2549,  2550,  2557,
    2570,  2580,  2587,  2604,  2611,  2636,  2638,  2636,  2660,  2704,
    2705,  2719,  2722,  2729,  2739,  2751,  2757,  2770,  2785,  2787,
    2793,  2794,  2795,  2796,  2806,  2813,  2816,  2822,  2825,  2830,
    2839,  2842,  2846,  2853,  2856,  2859,  2862,  2865,  2868,  2871,
    2872,  2873,  2874,  2875,  2876,  2877,  2878,  2879,  2881,  2885,
    2889,  2893,  2897,  2901,  2905,  2909,  2912,  2915,  2918,  2921,
    2924,  2927,  2930,  2933,  2937,  2941,  2945,  2948,  2957,  2960,
    2969,  2975,  2982,  2985,  3009,  3010,  3011,  3014,  3015,  3018,
    3024,  3025,  3026,  3027,  3028,  3029,  3034,  3038,  3042,  3046,
    3053,  3056,  3061,  3062,  3063,  3065,  3071,  3081,  3085,  3089,
    3093,  3097,  3101,  3105,  3109,  3117,  3127,  3132,  3136,  3140,
    3144,  3148,  3153,  3157,  3161,  3169,  3172,  3177,  3178,  3179,
    3184,  3185,  3186,  3194,  3197,  3202,  3203,  3207,  3208,  3213,
    3238,  3255,  3256,  3260,  3267,  3273,  3283,  3285,  3288,  3289,
    3290,  3291,  3293,  3296,  3300,  3305,  3309,  3315,  3316,  3319,
    3324,  3325,  3328,  3329,  3330,  3340,  3341,  3342,  3343,  3344,
    3345,  3346,  3347,  3351,  3357,  3359,  3378,  3386,  3393,  3394,
    3395,  3396,  3401,  3402,  3403,  3404,  3405,  3410,  3411,  3427,
    3428,  3429,  3430,  3431,  3432,  3433,  3434,  3435,  3436,  3438,
    3439,  3440,  3441,  3446,  3449,  3458,  3459,  3460,  3461,  3462,
    3463,  3467,  3468
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
  "UICOMBOBOX", "UIBROWSER", "UIGANTT", "UIFORM", "USING_BTREE",
  "USING_RTREE", "SET_BUFFERED_LOG", "SET_LOG", "MDY", "WEEKDAY",
  "MODE_ANSI", "START_DATABASE", "WITH_LOG_IN",
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
       0,   256,  2246,  2247,  2248,  2249,  2250,  2251,  2252,  2253,
    2254,  2255,  2256,  2257,  2258,  2259,  2260,  2261,  2262,  2263,
    2264,  2265,  1001,  1002,  1003,  1004,  1005,  1007,  1008,  1013,
    1014,  1015,  1017,  1018,  1020,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1032,  1036,  1037,  1038,  1041,  1057,  1058,  1077,
    1080,  1082,  1083,  1086,  1087,  1088,  1089,  1102,  1103,  1104,
    1105,  1119,  1121,  1122,  1123,  1127,  1134,  1135,  1136,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1182,  1183,  1185,  1186,
    1187,  1188,  1191,  1192,  1194,  1200,  1201,  1210,  1222,  1223,
    1224,  1229,  1232,  1233,  1234,  1235,  1236,  1237,  1242,  1243,
    1245,  1246,  1247,  1248,  1258,  1264,  1265,  1266,  1267,  1268,
    1279,  1280,  1288,  1289,  1290,  1296,  1304,  1311,  1313,  1317,
    1318,  1320,  1321,  1322,  1327,  1353,  1354,  1355,  1356,  1363,
    1364,  1371,  1379,  1381,  1382,  1386,  1387,  1394,  1395,  1398,
    1400,  1403,  1409,  1416,  1419,  1425,  1430,  1436,  1437,  1442,
    1444,  1446,  1447,  1449,  1460,  1467,  1470,  1471,  1472,  1474,
    1476,  1479,  1483,  1485,  1509,  1510,  1512,  1519,  1521,  1522,
    1524,  1525,  1526,  1532,  1533,  1539,  1540,  1542,  1545,  1548,
    1549,  1551,  1553,  1561,  1562,  1564,  1567,  1580,  1583,  1584,
    1585,  1586,  1588,  1589,  1597,  1600,  1601,  1602,  1606,  1608,
    1612,  1613,  1615,  1616,  1618,  1622,  1625,  1627,  1631,  1635,
    1636,  1639,  1641,  1642,  1645,  1646,  1648,  1654,  1658,  1663,
    1664,  1667,  1670,  1673,  1675,  1676,  1678,  1679,  1680,  1689,
    1692,  1699,  1701,  1703,  1704,  1705,  1708,  1709,  1713,  1719,
    1720,  1723,  1732,  1737,  1741,  1742,  1743,  1745,  1748,  1749,
    1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,
    1761,  1765,  1770,  1771,  1772,  1773,  1774,  1781,  1784,  1785,
    1791,  1793,  1794,  1797,  1799,  1800,  1801,  1839,  1843,  1850,
    1851,  1854,  1859,  1866,  1867,  2215,  2245
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   287,   288,   289,   289,   289,   290,   290,   290,   291,
     291,   291,   291,   291,   291,   292,   292,   293,   293,   294,
     294,   294,   294,   295,   296,   296,   297,   297,   298,   298,
     299,   300,   300,   300,   300,   301,   301,   302,   302,   303,
     303,   304,   304,   305,   305,   305,   305,   305,   306,   307,
     307,   308,   308,   309,   309,   309,   309,   310,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     312,   312,   313,   313,   314,   314,   315,   315,   315,   316,
     316,   317,   317,   318,   318,   318,   319,   319,   320,   320,
     320,   320,   320,   320,   320,   321,   321,   322,   322,   323,
     323,   324,   324,   325,   325,   326,   327,   327,   328,   328,
     329,   330,   330,   331,   332,   332,   333,   333,   334,   334,
     335,   335,   336,   336,   337,   338,   340,   339,   342,   341,
     341,   343,   343,   344,   344,   345,   345,   346,   346,   347,
     347,   348,   349,   350,   351,   351,   352,   353,   353,   353,
     353,   353,   353,   353,   354,   354,   354,   355,   355,   355,
     355,   355,   355,   355,   356,   356,   356,   356,   357,   357,
     357,   358,   358,   358,   359,   359,   359,   360,   360,   361,
     361,   361,   361,   361,   361,   362,   362,   363,   363,   364,
     364,   365,   365,   366,   367,   367,   368,   368,   369,   369,
     370,   371,   372,   373,   374,   374,   375,   375,   376,   376,
     376,   377,   377,   378,   378,   378,   379,   379,   379,   379,
     380,   381,   381,   382,   382,   383,   383,   384,   385,   385,
     385,   385,   385,   385,   385,   386,   387,   388,   389,   389,
     390,   390,   391,   392,   393,   394,   394,   394,   394,   394,
     394,   395,   395,   396,   396,   396,   397,   397,   398,   398,
     399,   399,   399,   399,   400,   400,   401,   401,   402,   402,
     403,   403,   404,   404,   405,   405,   406,   406,   407,   407,
     408,   409,   410,   410,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   412,   412,   412,   412,
     412,   412,   413,   413,   413,   413,   414,   414,   414,   414,
     415,   415,   415,   415,   416,   417,   417,   417,   418,   418,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   420,   420,   421,
     421,   421,   421,   421,   422,   423,   424,   425,   425,   426,
     426,   426,   427,   427,   428,   428,   429,   429,   429,   429,
     430,   430,   430,   430,   431,   432,   432,   432,   432,   433,
     433,   434,   434,   434,   434,   434,   434,   434,   435,   435,
     435,   435,   435,   435,   435,   435,   436,   436,   436,   437,
     437,   438,   439,   440,   441,   442,   442,   443,   443,   444,
     445,   445,   445,   446,   447,   448,   449,   449,   450,   451,
     451,   452,   452,   452,   453,   454,   454,   455,   455,   456,
     457,   458,   458,   458,   458,   460,   461,   459,   462,   463,
     463,   464,   464,   464,   464,   465,   466,   467,   468,   468,
     469,   469,   469,   469,   470,   471,   471,   472,   472,   472,
     473,   473,   473,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   475,   475,
     476,   476,   477,   477,   478,   478,   478,   479,   479,   479,
     480,   480,   480,   480,   480,   480,   481,   481,   481,   481,
     482,   482,   483,   483,   483,   483,   484,   485,   485,   485,
     485,   485,   485,   485,   485,   486,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   488,   488,   488,   488,   488,
     488,   488,   488,   489,   490,   491,   491,   492,   492,   493,
     494,   495,   495,   496,   496,   496,   497,   497,   497,   497,
     497,   497,   497,   497,   498,   499,   500,   501,   501,   501,
     502,   502,   503,   503,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   505,   505,   505,   506,   507,   508,   508,
     508,   508,   509,   509,   509,   509,   509,   510,   510,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   512,   512,   513,   513,   513,   513,   513,
     513,   514,   514
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
#define YYPACT_NINF -808
static const yytype_int16 yypact[] =
{
    1974,  -808,  -808,  -808,   158,  -808,   471,   158,   158,   471,
     471,   158,   595,   158,   158,   471,   595,   595,   595,   595,
    -808,   608,  -808,   158,  -808,  -808,   471,  -808,   186,   471,
     471,  -808,   471,   471,  -808,  -808,  -808,   471,   471,  -808,
    -808,   595,   471,   634,  -808,   158,   471,   693,   476,    -8,
     471,   476,  -808,  -808,  -808,  -808,  -808,  -808,  -808,  -808,
    -808,  -808,  -808,  -808,  -808,  -808,  -808,  -808,  -808,  -808,
    -808,  -808,  -808,  -808,  -808,  -808,  -808,   439,  -808,  -808,
    -808,   111,  -808,  -808,  -808,   191,    -6,  -808,  -808,   324,
    -808,  -808,  -808,    -1,   453,     9,   392,   213,  -808,  -808,
    -808,  -808,  -808,   104,   156,   198,   233,  -808,    42,  -808,
    -808,  -808,  -808,   129,  -808,  -808,   182,  -808,   140,  -808,
     318,     6,   471,  -808,    51,   277,   296,  -808,   229,   309,
    -808,  -808,  -808,  -808,   411,  -808,  -808,  -808,  -808,  -808,
     387,   387,  -808,  -808,  -808,  -808,   350,   329,   349,  -808,
     639,   -10,   196,   369,   372,  -808,  1974,   743,  -808,  -808,
     644,   158,   750,   158,   158,   650,   620,   106,   673,  -808,
    -808,   278,   121,   291,   423,  -808,  -808,  -808,  -808,  -808,
    -808,  -808,  -808,   158,  -808,  -808,   785,   158,   471,   471,
     471,   471,    42,  -808,   293,   471,   293,    84,   432,   692,
     897,  -808,   514,  -808,  -808,  -808,   158,   158,   792,   158,
     158,  -808,  -808,    84,  -808,  -808,    98,   471,   543,  -808,
    -808,  -808,  -808,  -808,  1135,  1135,  1135,  1135,    59,    59,
      14,    98,   471,  -808,   446,   454,   450,  -808,   672,  -808,
     459,  -808,   494,  -808,  -808,   567,   570,   573,   568,   576,
     577,  -808,  -808,  -808,   694,   158,   522,  -808,  -808,  -808,
     293,  -808,  -808,  -808,  -808,   766,   158,  -808,  -808,   293,
     506,  -808,   453,  -808,   512,  -808,   536,   609,  -808,   615,
     622,   642,  -808,   -28,  -808,  -808,    30,   634,    40,  -808,
    -808,   546,   347,   629,  -808,  -808,  -808,   653,   586,  -808,
    -808,   842,   667,   674,  -808,  -808,  -808,   670,   435,  -808,
      -8,   897,   670,   682,  -808,   685,   688,  -808,   607,   689,
     670,  -808,   690,   695,   670,   670,   703,   709,   712,   713,
    1737,  1023,   714,  1737,   862,  -808,  -808,  -808,   611,   655,
    -808,  -808,  -808,  -808,  -808,  -808,  -808,   435,  -808,   435,
    -808,  -808,   818,  -808,  -808,   -53,  -808,  -808,  -808,  -808,
     426,   805,   158,   164,  -808,   635,  -808,   638,  -808,   656,
    -808,    48,  -808,  -808,   657,  -808,  -808,   678,  -808,  1611,
    1611,  -808,    61,  -808,  -808,    65,   660,   660,   158,  -808,
    -808,   122,   -50,   662,   719,  -808,   692,   897,  -808,   657,
     649,   158,   158,   743,  -808,   158,   813,    84,    84,    84,
     134,   694,    84,   897,   158,  -808,   159,   158,   168,  -808,
    -808,  -808,   733,   735,   744,   435,   435,  -808,   749,  -808,
     751,   752,   753,   759,   763,  -808,  -808,  -808,  -808,   764,
     767,   551,  -808,  -808,  -808,  -808,  -808,   179,  -808,  -808,
     218,   158,  -808,   158,   820,   158,   158,   158,   158,   793,
     293,    37,  -808,  -808,    84,    83,   958,   158,  -808,    -8,
     851,  -808,  1261,   158,   944,  1611,  1611,  -808,  -808,  -808,
    -808,  -808,  -808,  -808,  -808,  -808,   691,   -10,   -34,   541,
    -808,  1611,    12,  1611,  1611,   897,   187,   342,  -808,  1611,
    -808,  1611,  1611,  -808,  -808,    12,  1611,    12,    12,   426,
    -808,    12,   426,  -808,   897,   897,   698,   -23,  1737,  -808,
    1737,  1737,  -808,  1737,  -808,   344,  1373,  -808,  -808,  1737,
    -808,   440,  -808,  1737,   161,  1611,    57,    70,  1611,  -808,
    -808,  -808,  -808,  -808,  -808,  1611,  1611,  1611,  1611,  -808,
     766,   234,  -808,   705,  -808,  -808,  -808,   158,   158,   830,
    -808,    84,    98,    98,   708,  -808,  -808,    74,   800,  -808,
    1135,  -808,  -808,   777,    59,   144,  -808,    59,  1135,  -808,
     611,    98,   710,  -808,  -808,  -808,   720,  -808,   803,   738,
    -808,   243,  -808,   245,  -808,   568,  -808,   254,   611,   822,
    -808,  -808,  -808,  -808,   293,   988,   988,   995,   725,   -22,
    1000,  1002,  1003,  1008,  1000,  1000,  1009,  1010,  -808,  -808,
    -808,    93,  -808,   358,  -808,   158,  -808,   293,  -808,  -808,
     742,  -808,   258,  -808,   -79,   286,   288,   289,  -808,    37,
    -808,  1012,  -808,  -808,  1019,  1020,  -808,    37,  -808,  -808,
    -808,   824,   -43,   758,   -10,  -808,  -808,  -808,  -808,   290,
     760,  -808,   302,   304,   553,  1611,  -808,  -808,   240,   853,
     409,  -808,  -808,  -808,  1611,   307,  -808,    45,   361,  -808,
    -808,   316,   335,   339,  1611,   348,  1611,  1611,  1611,   655,
    -808,   553,  1030,   553,   840,   426,   841,   847,   840,    97,
    -808,  -808,  -808,   841,    97,  -808,   847,  -808,  -808,  1611,
    -808,  -808,    57,  -808,  -808,   669,  1034,  -808,  -808,   170,
    -808,  -808,  -808,  -808,  -808,  -808,  -808,   158,   158,   852,
    -808,  -808,   774,  -808,  -808,  -808,   657,  1611,  -808,   158,
    -808,  -808,   857,  -808,  -808,   211,  -808,  -808,    34,   158,
     158,   902,    84,  -808,    84,  -808,   694,  -808,  -808,  -808,
    -808,   876,   877,   360,   553,  1055,   553,  -808,   804,   887,
     367,   888,   889,   804,   891,   894,  -808,  -808,  -808,  -808,
     471,  -808,  -808,  -808,   880,  -808,  -808,   358,  -808,   694,
    -808,  -808,   158,    68,   158,  -808,  -808,    68,    68,    68,
     793,  -808,  -808,  -808,  -808,  -808,  -808,  -808,  1076,   158,
    1611,  -808,  1611,   158,  -808,  -808,   890,  -808,  -808,  -808,
    -808,  -808,  -808,  -808,    -3,   435,   806,  -808,  -808,  -808,
     908,  -808,  1611,  -808,  -808,  -808,  -808,   910,  -808,   914,
     918,   924,  -808,   925,  -808,    93,  -808,    93,  -808,    93,
    -808,  -808,    67,  -808,   378,  -808,  -808,  -808,   386,  -808,
     832,    22,  -808,  -808,  -808,    57,  -808,  -808,  -808,    57,
    -808,    57,   158,  -808,  -808,  1499,   158,  -808,   866,  -808,
    1135,   158,  -808,  -808,   608,  -808,  -808,  -808,  -808,  -808,
    -808,  -808,  -808,  -808,  -808,  1102,  -808,   928,  -808,  1104,
     930,  -808,  -808,  1107,  -808,  -808,   933,  -808,  -808,  -808,
     920,   897,  -808,  -808,  -808,  -808,  -808,  1020,  1111,  -808,
      68,  -808,  -808,  -808,  -808,  -808,  -808,   929,   824,    -3,
    -808,   912,  1116,   471,    31,   942,   845,   553,  -808,  -808,
    -808,  -808,  -808,  -808,   849,  -808,  -808,  -808,  -808,  -808,
    -808,  -808,    97,  -808,  1611,  -808,   270,   436,   704,   931,
    -808,   389,  -808,  -808,  -808,   899,   405,   824,  -808,   954,
     858,  -808,  -808,  -808,   959,  -808,    84,   966,  -808,  -808,
    -808,  -808,  -808,  -808,    57,   969,   105,  -808,    75,    80,
     897,   897,  -808,   157,  -808,  -808,   938,  -808,   553,  -808,
     553,  -808,  -808,  -808,  -808,    57,    57,  -808,  1499,    41,
     -33,  -808,  -808,  -808,   553,  -808,   408,  -808,   799,  -808,
     160,   160,   103,   158,  -808,  -808,  -808,    91,  -808,  -808,
    -808,   896,  -808,   885,   412,   611,   611,  -808,  -808,  -808,
    -808,   326,   907,  -808,  -808,  -808,  -808,   939,   158,   903,
     999,  -808,  -808,  -808,  -808,    57,   471,   105,   884,   893,
     169,  -808,  -808,  -808,    80,   145,  -808,  -808,  -808,    57,
      -8,  -808,  1025,  -808,    88,   158,   503,   101,   897,   897,
     471,  -808,  -808,  -808,   824,   706,   -10,  -808,  -808,  -808,
    -808,   917,  -808,    73,  1025,  -808,  -808,   611,   611,   102,
    -808,  -808,  1611,    88,  -808,  -808,  -808,  -808,  -808,    -3,
    -808,   899,  -808
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -808,  -808,  -808,  -808,  -808,  -808,  -184,   782,   600,  -808,
    -171,  -382,  -808,  -808,  -808,  -808,   539,  -808,   535,   267,
     -84,  -808,   263,   550,  -808,   388,    95,   385,   391,   994,
    -149,  -808,  -808,   919,  -808,  -221,  -808,  -808,  -808,  -231,
    -808,  -808,  -209,  -808,  -808,  -808,  -808,  -371,  -808,   940,
     779,  -808,  -808,  -808,  -808,  -808,  -808,  -808,   467,  -808,
     189,  -808,  -808,  -808,  -808,  -808,  -808,  -808,  -808,  -808,
    1147,  -808,  1148,  -808,   982,  1060,  -808,  -154,   640,  -808,
    -808,  -808,  -808,  -808,  -808,   455,  -808,  -808,   228,  -808,
      16,  -150,  -808,  -808,  -808,  -808,  -808,   418,  -808,  -808,
    -808,  -808,  -808,     5,   212,  -808,  -808,  -772,   188,  -775,
    -807,  -808,   214,  -180,   696,   697,   883,  -808,   513,   511,
     515,   364,    -2,  -808,  -808,  -808,  -808,   266,  -808,   675,
    -808,  -808,  -808,   449,  -808,   617,    72,  -808,   -20,  -362,
    -170,  -681,   197,   941,   203,  -571,  -808,  -285,  -632,  -808,
    -808,  1017,   676,  -808,  -808,  -808,  -808,  -808,  -808,  -808,
    -808,  -808,  -808,   126,  -808,  -808,  -808,  -808,   166,   320,
    -808,  -808,  -808,  -808,  -808,  -808,   123,  -808,   162,   869,
    -201,  -289,  -456,  -629,  -808,   498,  -159,  -808,   740,  -360,
     625,   569,  -808,  -808,  -808,   538,   292,   -25,  -808,    43,
    -808,   811,    -4,   844,   393,  -808,  -808,  -808,  -808,  -808,
    1087,  -808,  1232,  -808,  -808,  -808,   848,  -808,  -459,  -808,
    -808,  -655,  -808,  -808,  -808,   108,  -808,  -808
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
     949,   965,   116,   117,    84,   118,   119,   399,    84,    84,
     120,   121,   299,  1026,    84,   124,   125,    84,    84,   131,
     125,  1089,    84,   152,   125,    84,   296,   125,   411,   776,
     296,    84,    84,   298,   107,   641,   477,    84,   299,    86,
      84,   490,   299,   193,   300,   915,   916,   301,    89,   500,
     270,   199,   983,   503,   504,    84,   642,   643,   853,   396,
    1048,   488,   896,   853,   898,  1020,  1020,   680,   496,  1020,
     608,   609,  1021,  1021,   666,   807,  1021,   883,    84,    84,
     459,   536,   489,   235,   466,   795,   220,   239,   241,   242,
     243,   986,    84,   258,    84,   202,    86,   265,   268,   265,
     692,   765,   203,    84,   644,    86,   796,    37,   671,   273,
     654,   929,   275,   276,    89,    89,    89,    89,   741,   114,
     265,    89,   265,   292,  1049,   204,   747,   282,   810,   989,
     955,   221,   364,   366,   368,   369,   130,  1044,   461,   292,
     956,   150,   111,    89,   957,   808,   958,   580,   463,   537,
     567,   568,   575,   672,   392,   392,   560,   111,    89,   990,
     460,   278,   278,   278,   278,   933,   200,   590,   285,   569,
     856,   514,   222,   571,   397,   856,   160,  1061,   863,    48,
     712,   258,  1045,   693,   766,   737,   265,   864,   157,   158,
     377,   991,   268,    51,   673,   265,   161,   224,   225,   226,
     227,   228,   165,   308,   946,   400,   946,   308,   946,  1096,
    1108,   183,    84,   292,  1077,  1081,   866,   867,   460,   806,
     832,   868,   562,  1046,   649,    84,   717,    84,   464,   255,
     573,   707,  1111,   373,   884,   999,   561,  1104,  1099,   650,
     645,   640,   594,   658,   266,   677,   658,   658,   680,   570,
     514,   713,   194,   570,   700,   989,   714,   388,  1105,  1018,
     705,  1060,   668,   196,   658,   676,   708,   601,   709,   334,
     658,   917,   658,   658,   739,  1023,   603,   658,  1027,   918,
    1041,  1042,   287,  1056,   718,   990,  1027,   624,   553,  1022,
    1022,   852,  1080,  1022,  1028,   334,  1039,   702,  1040,   334,
     744,  1083,  1028,   469,   871,  1028,   710,   554,   188,   720,
     574,   853,  1052,   882,   392,   891,   721,   722,   723,   724,
     743,   734,   595,  1090,   790,   759,   626,   582,   583,   235,
    1076,   585,   587,   292,   292,   292,   791,   478,   292,   736,
     600,   384,   726,   258,  1085,   466,   245,   417,   913,   384,
     246,   753,  1090,   755,   494,   593,   604,   748,   597,   245,
     189,   245,   757,   246,   495,   246,   793,   625,   509,   155,
     479,   512,   872,   195,   247,   756,   229,   628,   480,   629,
     631,   634,   634,   634,   634,   156,   265,   247,  1003,   247,
     292,   651,   514,   653,   797,   481,   798,   799,   811,   660,
     186,   260,   190,  1109,   778,    84,   627,    86,   270,   482,
     814,   187,   815,   881,   269,   831,   208,   538,   483,   249,
     184,   185,   727,   856,   834,   250,   863,   209,   825,   484,
     779,   754,   249,   754,   249,   864,   567,   191,   250,   780,
     250,   197,   754,   835,  1067,   830,   794,   836,   539,   540,
     541,   542,   543,   544,   781,   837,   838,   839,   840,   841,
     782,   166,   167,   719,   866,   867,   310,   699,   894,   868,
     936,   168,   169,   170,   794,   902,   794,   794,   812,   206,
     860,   466,   863,   366,   731,   733,   951,   292,   111,   111,
     812,   864,   812,   740,   953,   812,   982,  1007,   207,   783,
     392,   745,   211,   392,   812,   784,   478,   111,   567,   494,
     213,   162,   889,  1011,   890,   210,  1053,  -504,   216,   495,
     866,   867,   163,   812,   135,   868,   164,   812,   494,    84,
     265,    95,   478,   217,   208,  1012,   812,   218,   495,   479,
     296,   297,    84,   298,   107,   209,   466,   480,   895,   467,
     679,   268,   299,   265,   300,   903,   695,   301,   695,   695,
    1102,   695,   310,   704,   481,   479,   952,   695,    84,   833,
     125,   695,   219,   480,   952,   231,   232,  1008,   482,   136,
     238,   567,   545,   930,   171,   137,   244,   483,   302,   303,
     481,   546,   863,   570,   304,   305,   752,   825,   484,   208,
     138,   864,  1066,   939,   482,   139,   259,   618,   619,   620,
     209,   272,   518,   483,  -529,   140,   772,   773,   141,   172,
     547,  1095,   142,   306,   484,   548,   294,   132,   143,   133,
     866,   867,   293,   519,   173,   868,   245,   362,   403,   966,
     246,   520,   521,   923,   924,   925,   963,   522,   401,   667,
     816,   384,  1100,   553,   874,   404,   402,   523,   144,   863,
     524,   405,   525,   621,   247,   879,   145,   138,   864,   279,
     280,   281,   139,   526,   527,   886,   887,    84,   292,   234,
     292,   406,   140,   817,    84,   141,   240,   307,   245,   142,
     407,   818,   246,   408,   528,   143,   409,   866,   867,   412,
     413,   684,   868,   686,   687,   414,    89,   688,   819,   249,
     417,  1086,   529,   451,   453,   250,   247,   308,   914,    84,
     634,   274,   820,   454,  -305,  1002,    84,   309,   367,   310,
     311,   821,   455,   312,   313,   928,   590,   530,   456,   931,
    1035,  1036,   822,   248,   531,   457,  -305,    84,   465,   586,
     532,   533,   314,   910,    84,   315,   630,   103,   104,   105,
     106,   249,   316,   317,    84,   458,   732,   250,   469,   318,
     319,   635,   636,   637,   494,   947,   472,   948,   474,   963,
     320,   420,   123,   321,   495,   322,   323,   862,   473,   324,
     475,   325,   310,   326,   968,   513,   327,   476,   959,   328,
     329,   330,   964,   331,   332,   491,   333,   967,   492,   334,
     111,   493,   499,   501,   696,   697,   514,   698,   502,   335,
     336,   337,  1004,   703,  1101,   863,   505,   706,  1097,  1098,
     296,   297,   506,   298,   864,   507,   508,   511,   515,   550,
     558,   557,   299,   559,   300,   562,   563,   301,   570,   421,
     577,   578,   422,   423,   424,   581,   605,   865,   606,    89,
     863,   425,   863,   866,   867,   426,   638,   607,   868,   864,
     427,   864,   610,   567,   611,   612,   613,   428,   302,   303,
     429,   430,   614,   431,   304,   305,   615,   616,  -282,   518,
     617,   652,  1005,   655,  1033,   661,   737,   664,   866,   867,
     866,   867,   292,   868,   691,   868,   432,   728,   667,   742,
     519,   751,   749,   306,  1025,  1034,   433,  1054,   520,   521,
     434,   760,   750,  -282,   522,  -282,   752,   435,   763,   436,
     758,   764,  1033,   767,   523,   769,   770,   524,   437,   525,
     438,   771,   774,   775,   792,   801,    89,    89,    89,  1025,
     526,   527,   802,  1034,   803,   863,   296,   297,   466,   298,
     809,   828,   813,   843,   864,   845,   847,   870,   299,  1033,
     300,   528,   849,   301,  1073,   875,   876,   307,   439,  1033,
     880,   440,    89,   780,   892,   893,    89,  1055,   897,   529,
    1034,  1084,   899,   866,   867,   901,   904,   905,   868,   907,
    1034,  1073,   908,   911,   302,   303,    89,   308,  1033,   927,
     304,   305,   937,   932,   530,   954,   938,   309,   940,   310,
     311,   531,   941,   312,   313,  1068,   942,   532,   533,  1034,
     662,   663,   943,   944,   933,   969,   970,   971,   973,   306,
     974,   975,   314,   976,   979,   315,   984,   981,   675,   985,
     997,   998,   316,   317,   681,  1000,   682,   683,  1009,   318,
     319,   685,  1013,   863,  1014,  1006,   990,  1015,   296,   297,
     320,   298,   864,   321,  1017,   322,   323,  1019,  1070,   324,
     299,   325,   300,   326,  1064,   301,   327,  1065,  1078,   328,
     329,   330,  1075,   331,   332,  1069,   333,  1079,  1087,   334,
     572,   866,   867,   307,  1074,  1103,   868,   746,   800,   335,
     336,   337,   805,   980,   978,   922,   302,   303,   926,  1107,
     286,   452,   304,   305,   873,   416,   602,  1043,   153,   154,
     378,   215,   735,   308,  1016,   912,   888,  1037,  1038,  1059,
     689,   851,   690,   309,   510,   310,   311,   859,   857,   312,
     313,   306,   906,   762,  1063,   725,  1062,   370,   462,  1110,
    1082,   977,   556,   730,  1112,   877,   678,  1094,   314,   829,
     579,   315,   858,   233,  1001,   950,   101,     0,   316,   317,
       0,   584,     0,     0,     0,   318,   319,     0,     0,     0,
       0,     0,     0,     0,   296,   297,   320,   298,     0,   321,
       0,   322,   323,     0,     0,   324,   299,   325,   300,   326,
       0,   301,   327,     0,     0,   328,   329,   330,     0,     0,
     332,     0,   333,     0,     0,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335,   336,   337,     0,     0,
       0,     0,   302,   303,     0,   308,     0,     0,   304,   305,
       0,     0,     0,     0,     0,   309,     0,   310,   380,     0,
       0,     0,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   306,     0,   381,
     314,     0,     0,   315,     0,     0,     0,     0,     0,     0,
     316,   317,     0,     0,     0,     0,     0,   318,   319,     0,
       0,     0,     0,     0,     0,     0,   296,   297,   320,   298,
       0,   321,     0,   322,   323,     0,     0,   324,   299,   325,
     300,   326,     0,   301,   327,     0,     0,   328,   329,   330,
       0,     0,   332,     0,   333,     0,     0,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   335,   336,   337,
       0,     0,     0,     0,   302,   303,     0,     0,     0,     0,
     304,   305,     0,     0,     0,     0,     0,     0,     0,   657,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,   310,   380,     0,     0,     0,   313,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,     0,     0,   315,
       0,     0,     0,     0,     0,     0,   316,   317,     0,     0,
       0,     0,     0,   318,   319,     0,     0,     0,     0,     0,
       0,     0,   296,   297,   320,   298,     0,   321,     0,   322,
     323,     0,     0,   324,   299,   325,   300,   326,     0,   301,
     327,     0,     0,   328,   329,   330,     0,     0,   332,     0,
     333,     0,     0,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   335,   336,   337,     0,     0,     0,     0,
     302,   303,     0,   308,     0,     0,   304,   305,     0,     0,
       0,     0,     0,   309,     0,   310,   380,     0,     0,     0,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,   701,   314,     0,
       0,   315,     0,     0,     0,     0,     0,     0,   316,   317,
       0,     0,     0,     0,     0,   318,   319,     0,     0,     0,
       0,     0,     0,     0,   296,   297,   320,   298,     0,   321,
       0,   322,   323,     0,     0,   324,   299,   325,   300,   326,
       0,   301,   327,     0,     0,   328,   329,   330,     0,     0,
     332,     0,   333,     0,     0,   334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335,   336,   337,     0,     0,
       0,     0,   302,   303,     0,     0,     0,     0,   304,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   309,
       0,   310,   380,     0,     0,     0,   313,   306,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   960,   314,     0,     0,   315,     0,     0,
       0,     0,     0,     0,   316,   317,     0,     0,     0,     0,
       0,   318,   319,     0,     0,     0,     0,     0,     0,     0,
     296,   297,   320,   298,     0,   321,     0,   322,   323,     0,
       0,   324,   299,   325,   300,   326,     0,   301,   327,     0,
       0,   328,   329,   330,     0,     0,   332,     0,   333,     0,
       0,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   335,   336,   337,     0,     0,     0,     0,   302,   303,
       0,   308,     0,     0,   304,   305,     0,     0,     0,     0,
       0,   309,     0,   310,   380,     0,     0,     0,   313,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,   314,     0,     0,   315,
       0,     0,     0,     0,     0,     0,   316,   317,     0,     0,
       0,     0,     0,   318,   319,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   320,     0,     0,   321,     0,   322,
     323,     0,     0,   324,     0,   325,     0,   326,     0,     0,
     327,     0,     0,   328,   329,   330,     0,     0,   332,     0,
     333,     0,     0,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   335,   336,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,     0,   310,
     380,     0,     0,     0,   313,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   314,     0,     0,   315,     0,     0,     0,     0,
       0,     0,   316,   317,     0,     0,     0,     0,     0,   318,
     319,     0,     0,     0,  -566,     1,     0,     0,     0,     0,
     320,     0,     0,   321,     0,   322,   323,     0,     0,   324,
    -566,   325,     0,   326,     0,     0,   327,     0,     0,   328,
     329,     0,     0,     0,   332,     0,     0,     0,     0,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   335,
     336,   337,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     0,     0,     6,     7,     0,     8,     9,    10,     0,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,    28,     0,    29,    30,     0,     0,     0,    31,    32,
       0,     0,     0,     0,     0,    33,    34,    35,    36,    37,
      38,     0,     0,    39,     0,     0,     0,     0,     0,    40,
      41,     0,     0,    42,     0,     0,    43,     0,    44,    45,
       0,     0,     0,     0,    46,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,    49,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,    51
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
       3,   878,    29,    30,     4,    32,    33,   231,     4,     4,
      37,    38,    15,     3,     4,    42,     6,     4,     4,    46,
       6,     3,     4,    50,     6,     4,     3,     6,   248,     6,
       3,     4,     4,     6,     6,    68,   307,     4,    15,     6,
       4,   312,    15,   108,    17,    47,    48,    20,   122,   320,
     269,   115,   929,   324,   325,     4,    89,    90,   699,   115,
     163,   311,   764,   704,   766,    34,    34,   497,   318,    34,
     425,   426,    41,    41,   178,   188,    41,   113,     4,     4,
     178,   204,   311,   157,   204,   234,   166,   161,   162,   163,
     164,   933,     4,   167,     4,   122,     6,   171,   172,   173,
     193,   193,   121,     4,   137,     6,   255,   135,   166,   183,
     469,   810,   186,   187,   188,   189,   190,   191,   570,     3,
     194,   195,   196,   197,   227,   144,   578,   192,   654,   168,
     178,   211,   206,   207,   208,   209,   210,   166,   178,   213,
     865,   219,   216,   217,   869,   258,   871,   397,   178,   272,
     379,   380,   272,   211,   228,   229,   178,   231,   232,   198,
     258,   188,   189,   190,   191,   238,   230,   407,   195,   178,
     699,   275,   252,   178,   230,   704,    55,  1022,   226,   207,
     193,   255,   211,   276,   276,   258,   260,   235,   147,   148,
     217,   230,   266,   221,   252,   269,   272,    71,    72,    73,
      74,    75,   273,   180,   845,   232,   847,   180,   849,   178,
     178,   272,     4,   287,  1056,  1060,   264,   265,   258,   651,
     245,   269,   258,   252,   464,     4,   226,     4,   258,   193,
     178,   140,  1109,   205,   270,   937,   258,   234,  1080,   226,
     273,   460,   178,   472,   193,   495,   475,   476,   678,   258,
     275,   264,   193,   258,   525,   168,   269,   268,   255,   984,
     531,   228,   491,   193,   493,   494,   175,   178,   177,   272,
     499,   273,   501,   502,   270,   270,   178,   506,   268,   281,
    1005,  1006,   268,   193,   284,   198,   268,   178,   362,   258,
     258,   264,   193,   258,   284,   272,   998,   526,  1000,   272,
     226,   226,   284,   209,   204,   284,   535,   213,   274,   538,
     258,   952,  1014,   745,   388,   756,   545,   546,   547,   548,
     574,   561,   258,  1074,   625,   604,   178,   401,   402,   403,
    1055,   405,   406,   407,   408,   409,   627,   167,   412,   563,
     414,   570,   178,   417,  1069,   204,   138,   258,   789,   578,
     142,   178,  1103,   178,   237,   409,   258,   581,   412,   138,
     274,   138,   178,   142,   247,   142,   178,   258,   330,     0,
     200,   333,   272,   261,   166,   595,   250,   451,   208,   453,
     454,   455,   456,   457,   458,    16,   460,   166,   188,   166,
     464,   465,   275,   467,   178,   225,   178,   178,   178,   473,
     257,   193,   274,  1102,   116,     4,   258,     6,   627,   239,
     178,   268,   178,   272,   193,   178,   257,    61,   248,   211,
      98,    99,   258,   952,   178,   217,   226,   268,   258,   259,
     142,   258,   211,   258,   211,   235,   665,   274,   217,   151,
     217,   193,   258,   178,   188,   674,   258,   178,    92,    93,
      94,    95,    96,    97,   166,   684,   178,   686,   687,   688,
     172,    78,    79,   537,   264,   265,   192,   193,   178,   269,
     825,    88,    89,    90,   258,   178,   258,   258,   258,   272,
     709,   204,   226,   557,   558,   559,   178,   561,   562,   563,
     258,   235,   258,   567,   178,   258,   928,   178,   272,   211,
     574,   575,   161,   577,   258,   217,   167,   581,   737,   237,
     193,   257,   752,   178,   754,   276,   178,   178,   238,   247,
     264,   265,   268,   258,   118,   269,   272,   258,   237,     4,
     604,     6,   167,   274,   257,   967,   258,   258,   247,   200,
       3,     4,     4,     6,     6,   268,   204,   208,   258,   272,
     278,   625,    15,   627,    17,   258,   518,    20,   520,   521,
    1086,   523,   192,   193,   225,   200,   258,   529,     4,   278,
       6,   533,     3,   208,   258,   276,   274,   258,   239,   173,
       6,   810,   226,   812,   201,   179,     6,   248,    51,    52,
     225,   235,   226,   258,    57,    58,   258,   258,   259,   257,
     194,   235,  1034,   832,   239,   199,     3,   126,   127,   128,
     268,   258,   141,   248,   272,   209,   614,   615,   212,   236,
     264,   188,   216,    86,   259,   269,     4,     4,   222,     6,
     264,   265,   270,   162,   251,   269,   138,   193,   258,   880,
     142,   170,   171,   797,   798,   799,   875,   176,   272,   178,
     167,   880,  1084,   727,   728,    53,   272,   186,   252,   226,
     189,   272,   191,   182,   166,   739,   260,   194,   235,   189,
     190,   191,   199,   202,   203,   749,   750,     4,   752,     6,
     754,   257,   209,   200,     4,   212,     6,   150,   138,   216,
     193,   208,   142,   193,   223,   222,   193,   264,   265,   193,
     193,   505,   269,   507,   508,    81,   780,   511,   225,   211,
     258,  1070,   241,   277,   272,   217,   166,   180,   792,     4,
     794,     6,   239,   257,   253,   954,     4,   190,     6,   192,
     193,   248,   193,   196,   197,   809,   976,   266,   193,   813,
     990,   991,   259,   193,   273,   193,   275,     4,   272,     6,
     279,   280,   215,   780,     4,   218,     6,    16,    17,    18,
      19,   211,   225,   226,     4,   193,     6,   217,   209,   232,
     233,   456,   457,   458,   237,   847,   193,   849,     6,  1008,
     243,    85,    41,   246,   247,   248,   249,   188,   272,   252,
     193,   254,   192,   256,   884,     3,   259,   193,   872,   262,
     263,   264,   876,   266,   267,   193,   269,   881,   193,   272,
     884,   193,   193,   193,   520,   521,   275,   523,   193,   282,
     283,   284,   188,   529,   188,   226,   193,   533,  1078,  1079,
       3,     4,   193,     6,   235,   193,   193,   193,   253,   104,
     272,   276,    15,   257,    17,   258,   238,    20,   258,   153,
     258,   202,   156,   157,   158,   276,   193,   258,   193,   933,
     226,   165,   226,   264,   265,   169,   143,   193,   269,   235,
     174,   235,   193,  1102,   193,   193,   193,   181,    51,    52,
     184,   185,   193,   187,    57,    58,   193,   193,   140,   141,
     193,     3,   258,   112,   989,    21,   258,   276,   264,   265,
     264,   265,   976,   269,   276,   269,   210,   272,   178,   202,
     162,   178,   272,    86,   988,   989,   220,   188,   170,   171,
     224,     3,   272,   175,   176,   177,   258,   231,     3,   233,
     178,   276,  1027,     3,   186,     3,     3,   189,   242,   191,
     244,     3,     3,     3,   272,     3,  1020,  1021,  1022,  1023,
     202,   203,     3,  1027,     4,   226,     3,     4,   204,     6,
     272,   178,   272,     3,   235,   195,   195,     3,    15,  1064,
      17,   223,   195,    20,  1048,   193,   272,   150,   282,  1074,
     193,   285,  1056,   151,   178,   178,  1060,   258,     3,   241,
    1064,  1065,   258,   264,   265,   178,   178,   178,   269,   178,
    1074,  1075,   178,   193,    51,    52,  1080,   180,  1103,     3,
      57,    58,   276,   193,   266,   253,   178,   190,   178,   192,
     193,   273,   178,   196,   197,   188,   178,   279,   280,  1103,
     475,   476,   178,   178,   238,     3,   178,     3,   178,    86,
       3,   178,   215,   193,     3,   218,   204,   188,   493,     3,
     178,   276,   225,   226,   499,   276,   501,   502,   229,   232,
     233,   506,   178,   226,   276,   204,   198,   178,     3,     4,
     243,     6,   235,   246,   178,   248,   249,   178,   209,   252,
      15,   254,    17,   256,   258,    20,   259,   272,   274,   262,
     263,   264,   163,   266,   267,   258,   269,   274,   143,   272,
     388,   264,   265,   150,   271,   258,   269,   577,   639,   282,
     283,   284,   647,   920,   917,   794,    51,    52,   800,  1094,
     196,   272,    57,    58,   727,   255,   417,  1008,    51,    51,
     218,   141,   562,   180,   976,   787,   751,   993,   996,  1021,
     514,   698,   515,   190,   331,   192,   193,   706,   703,   196,
     197,    86,   773,   606,  1027,   550,  1023,   210,   287,  1103,
    1064,   911,   363,   557,  1111,   737,   496,  1075,   215,   670,
     396,   218,   704,   156,   952,   852,    14,    -1,   225,   226,
      -1,   403,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,   243,     6,    -1,   246,
      -1,   248,   249,    -1,    -1,   252,    15,   254,    17,   256,
      -1,    20,   259,    -1,    -1,   262,   263,   264,    -1,    -1,
     267,    -1,   269,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,
      -1,    -1,    51,    52,    -1,   180,    -1,    -1,    57,    58,
      -1,    -1,    -1,    -1,    -1,   190,    -1,   192,   193,    -1,
      -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,   214,
     215,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,   243,     6,
      -1,   246,    -1,   248,   249,    -1,    -1,   252,    15,   254,
      17,   256,    -1,    20,   259,    -1,    -1,   262,   263,   264,
      -1,    -1,   267,    -1,   269,    -1,    -1,   272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,   284,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,   192,   193,    -1,    -1,    -1,   197,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,
      -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,   243,     6,    -1,   246,    -1,   248,
     249,    -1,    -1,   252,    15,   254,    17,   256,    -1,    20,
     259,    -1,    -1,   262,   263,   264,    -1,    -1,   267,    -1,
     269,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,
      51,    52,    -1,   180,    -1,    -1,    57,    58,    -1,    -1,
      -1,    -1,    -1,   190,    -1,   192,   193,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,   214,   215,    -1,
      -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
      -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,   243,     6,    -1,   246,
      -1,   248,   249,    -1,    -1,   252,    15,   254,    17,   256,
      -1,    20,   259,    -1,    -1,   262,   263,   264,    -1,    -1,
     267,    -1,   269,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   282,   283,   284,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,   192,   193,    -1,    -1,    -1,   197,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,   215,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,   243,     6,    -1,   246,    -1,   248,   249,    -1,
      -1,   252,    15,   254,    17,   256,    -1,    20,   259,    -1,
      -1,   262,   263,   264,    -1,    -1,   267,    -1,   269,    -1,
      -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,    51,    52,
      -1,   180,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,
      -1,   190,    -1,   192,   193,    -1,    -1,    -1,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,   215,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,
      -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,   246,    -1,   248,
     249,    -1,    -1,   252,    -1,   254,    -1,   256,    -1,    -1,
     259,    -1,    -1,   262,   263,   264,    -1,    -1,   267,    -1,
     269,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   282,   283,   284,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,   192,
     193,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,   232,
     233,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,   246,    -1,   248,   249,    -1,    -1,   252,
      16,   254,    -1,   256,    -1,    -1,   259,    -1,    -1,   262,
     263,    -1,    -1,    -1,   267,    -1,    -1,    -1,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      56,    -1,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,   101,   102,   103,    -1,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,   114,    -1,
      -1,   117,    -1,   119,   120,    -1,    -1,    -1,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,   134,   135,
     136,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,   145,
     146,    -1,    -1,   149,    -1,    -1,   152,    -1,   154,   155,
      -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,   209,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    49,    50,    54,    56,    59,    60,    62,    63,
      64,    66,    67,    76,    77,    80,   100,   101,   102,   103,
     105,   106,   107,   108,   109,   110,   111,   114,   117,   119,
     120,   124,   125,   131,   132,   133,   134,   135,   136,   139,
     145,   146,   149,   152,   154,   155,   160,   164,   207,   209,
     212,   221,   288,   299,   300,   301,   302,   311,   318,   338,
     339,   348,   349,   350,   352,   353,   354,   355,   356,   366,
     386,   390,   436,   437,   440,   441,   459,   495,   496,   497,
     498,   500,   504,   506,     4,   489,     6,   486,   487,   489,
     489,   489,   486,   486,   489,     6,   488,   489,   489,   494,
     499,   499,   486,   488,   488,   488,   488,     6,   387,   388,
     425,   489,   489,   486,     3,   514,   486,   486,   486,   486,
     486,   486,   340,   488,   486,     6,   484,   485,   489,   438,
     489,   486,     4,     6,   492,   118,   173,   179,   194,   199,
     209,   212,   216,   222,   252,   260,   357,   359,   360,   361,
     219,   468,   486,   357,   359,     0,    16,   147,   148,   501,
      55,   272,   257,   268,   272,   273,    78,    79,    88,    89,
      90,   201,   236,   251,   319,   320,   321,   324,   327,   330,
     331,   332,   335,   272,    98,    99,   257,   268,   274,   274,
     274,   274,   389,   390,   193,   261,   193,   193,   367,   115,
     230,   290,   486,   121,   144,   442,   272,   272,   257,   268,
     276,   161,   351,   193,   362,   362,   238,   274,   258,     3,
     166,   211,   252,   469,    71,    72,    73,    74,    75,   250,
     291,   276,   274,   497,     6,   489,   502,   503,     6,   489,
       6,   489,   489,   489,     6,   138,   142,   166,   193,   211,
     217,   370,   371,   376,   378,   193,   336,   337,   489,     3,
     193,   317,   329,   378,   380,   489,   193,   326,   489,   193,
     317,   322,   258,   489,     6,   489,   489,   310,   486,   310,
     310,   310,   390,   316,   317,   486,   316,   268,   368,   427,
     430,   484,   489,   270,     4,   490,     3,     4,     6,    15,
      17,    20,    51,    52,    57,    58,    86,   150,   180,   190,
     192,   193,   196,   197,   215,   218,   225,   226,   232,   233,
     243,   246,   248,   249,   252,   254,   256,   259,   262,   263,
     264,   266,   267,   269,   272,   282,   283,   284,   400,   401,
     402,   403,   404,   411,   413,   432,   443,   444,   445,   446,
     447,   467,   473,   474,   481,   489,   491,   505,   507,   511,
     512,   513,   193,   343,   489,   439,   489,     6,   489,   489,
     438,   363,   427,   205,   364,   365,   425,   486,   361,   460,
     193,   214,   297,   298,   473,   297,   297,   297,   268,   293,
     294,   296,   489,   292,   293,   295,   115,   230,   289,   364,
     486,   272,   272,   258,    53,   272,   257,   193,   193,   193,
     333,   378,   193,   193,    81,   334,   336,   258,   328,   329,
      85,   153,   156,   157,   158,   165,   169,   174,   181,   184,
     185,   187,   210,   220,   224,   231,   233,   242,   244,   282,
     285,   416,   417,   418,   419,   421,   458,   325,   326,   322,
     323,   277,   320,   272,   257,   193,   193,   193,   193,   178,
     258,   178,   430,   178,   258,   272,   204,   272,   426,   209,
     457,   466,   193,   272,     6,   193,   193,   467,   167,   200,
     208,   225,   239,   248,   259,   433,   434,   468,   400,   473,
     467,   193,   193,   193,   237,   247,   400,   475,   476,   193,
     467,   193,   193,   467,   467,   193,   193,   193,   193,   512,
     403,   193,   512,     3,   275,   253,   434,   434,   141,   162,
     170,   171,   176,   186,   189,   191,   202,   203,   223,   241,
     266,   273,   279,   280,   410,   412,   204,   272,    61,    92,
      93,    94,    95,    96,    97,   226,   235,   264,   269,   480,
     104,   344,   345,   489,   213,   341,   466,   276,   272,   257,
     178,   258,   258,   238,   470,   471,   472,   473,   473,   178,
     258,   178,   294,   178,   258,   272,   426,   258,   202,   490,
     400,   276,   489,   489,   503,   489,     6,   489,   373,   375,
     427,   377,   427,   377,   178,   258,   334,   377,   400,   456,
     489,   178,   337,   178,   258,   193,   193,   193,   434,   434,
     193,   193,   193,   193,   193,   193,   193,   193,   126,   127,
     128,   182,   379,   381,   178,   258,   178,   258,   489,   489,
       6,   489,   314,   315,   489,   314,   314,   314,   143,   312,
     317,    68,    89,    90,   137,   273,   303,   304,   305,   427,
     226,   489,     3,   489,   468,   112,   369,   178,   473,   477,
     489,    21,   477,   477,   276,   469,   178,   178,   473,   479,
     505,   166,   211,   252,   414,   477,   473,   400,   475,   278,
     476,   477,   477,   477,   414,   477,   414,   414,   414,   401,
     402,   276,   193,   276,   408,   512,   408,   408,   408,   193,
     467,   214,   473,   408,   193,   467,   408,   140,   175,   177,
     473,     3,   193,   264,   269,   508,   510,   226,   284,   489,
     473,   473,   473,   473,   473,   416,   178,   258,   272,   342,
     439,   489,     6,   489,   427,   365,   364,   258,   461,   270,
     489,   298,   202,   293,   226,   489,   295,   298,   364,   272,
     272,   178,   258,   178,   258,   178,   378,   178,   178,   329,
       3,   422,   422,     3,   276,   193,   276,     3,   423,     3,
       3,     3,   423,   423,     3,     3,     6,   432,   116,   142,
     151,   166,   172,   211,   217,   372,   382,   383,   384,   385,
     326,   322,   272,   178,   258,   234,   255,   178,   178,   178,
     303,     3,     3,     4,   306,   305,   426,   188,   258,   272,
     469,   178,   258,   272,   178,   178,   167,   200,   208,   225,
     239,   248,   259,   435,   470,   258,   434,   478,   178,   478,
     473,   178,   245,   278,   178,   178,   178,   473,   178,   473,
     473,   473,   435,     3,   435,   195,   405,   195,   407,   195,
     406,   405,   264,   432,   482,   483,   505,   407,   482,   406,
     473,   508,   188,   226,   235,   258,   264,   265,   269,   509,
       3,   204,   272,   345,   489,   193,   272,   472,   493,   489,
     193,   272,   426,   113,   270,   358,   489,   489,   372,   427,
     427,   334,   178,   178,   178,   258,   435,     3,   435,   258,
     420,   178,   178,   258,   178,   178,   420,   178,   178,   374,
     486,   193,   384,   334,   489,    47,    48,   273,   281,   307,
     308,   309,   315,   307,   307,   307,   312,     3,   489,   470,
     473,   489,   193,   238,   393,   397,   434,   276,   178,   473,
     178,   178,   178,   178,   178,   409,   432,   409,   409,     3,
     491,   178,   258,   178,   253,   178,   508,   508,   508,   489,
     214,   346,   347,   473,   489,   397,   297,   489,   425,     3,
     178,     3,   424,   178,     3,   178,   193,   456,   306,     3,
     309,   188,   426,   397,   204,     3,   394,   396,   486,   168,
     198,   230,   391,   392,   398,   399,   453,   178,   276,   435,
     276,   483,   473,   188,   188,   258,   204,   178,   258,   229,
     463,   178,   426,   178,   276,   178,   375,   178,   508,   178,
      34,    41,   258,   270,   431,   489,     3,   268,   284,   428,
     429,   454,   455,   484,   489,   400,   400,   399,   391,   435,
     435,   508,   508,   347,   166,   211,   252,   415,   163,   227,
     448,   464,   435,   178,   188,   258,   193,   394,   395,   395,
     228,   396,   431,   429,   258,   272,   426,   188,   188,   258,
     209,   462,   465,   489,   271,   163,   508,   394,   274,   274,
     193,   396,   455,   226,   489,   508,   468,   143,   313,     3,
     428,   449,   450,   451,   465,   188,   178,   400,   400,   394,
     426,   188,   469,   258,   234,   255,   452,   313,   178,   470,
     450,   397,   463
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
#line 461 "sql.yacc"
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
#line 487 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 490 "sql.yacc"
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
#line 507 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 512 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 515 "sql.yacc"
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
#line 532 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 538 "sql.yacc"
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
#line 547 "sql.yacc"
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
#line 556 "sql.yacc"
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
#line 565 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 572 "sql.yacc"
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
#line 587 "sql.yacc"
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
#line 642 "sql.yacc"
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
#line 649 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 660 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 663 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 668 "sql.yacc"
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
#line 675 "sql.yacc"
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
#line 692 "sql.yacc"
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
#line 709 "sql.yacc"
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
#line 730 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 739 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 742 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 750 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 753 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 761 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 762 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 769 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 772 "sql.yacc"
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
#line 780 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 783 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 787 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 793 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 794 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 798 "sql.yacc"
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
#line 808 "sql.yacc"
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
#line 822 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 823 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 828 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 833 "sql.yacc"
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
#line 841 "sql.yacc"
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
#line 849 "sql.yacc"
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
#line 857 "sql.yacc"
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
#line 865 "sql.yacc"
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
#line 877 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 877 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 881 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 885 "sql.yacc"
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
#line 892 "sql.yacc"
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
#line 899 "sql.yacc"
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
#line 906 "sql.yacc"
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
#line 915 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 919 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 926 "sql.yacc"
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
#line 938 "sql.yacc"
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
#line 949 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 955 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 959 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 963 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 968 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 972 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 975 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 979 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 982 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 989 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 990 "sql.yacc"
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
#line 1000 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1001 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1006 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1010 "sql.yacc"
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
#line 1019 "sql.yacc"
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
#line 1028 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1035 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 1038 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 1044 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1047 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1058 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 1062 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1067 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1074 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1077 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1086 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1089 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1093 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1097 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1101 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1105 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1109 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1117 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1121 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1129 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1132 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1139 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1142 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1149 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1152 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1160 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1169 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1172 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1178 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1181 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1187 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1194 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1195 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1199 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1207 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1211 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1218 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1220 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1225 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1226 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1231 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1232 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1238 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1239 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1253 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1259 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1259 "sql.yacc"
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
#line 1268 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1268 "sql.yacc"
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
#line 1277 "sql.yacc"
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
#line 1302 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1305 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1313 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1316 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1323 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1326 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1334 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1335 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1341 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1342 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1350 "sql.yacc"
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
#line 1368 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1372 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1377 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1378 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1388 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1397 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1401 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1406 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1410 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1414 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1418 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1421 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1428 "sql.yacc"
    { (yyval.integer_val)=1; 
#ifndef  SQLCOMPILER
				set_cmdlineno(token_read_on_line);
#endif

}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1434 "sql.yacc"
    { (yyval.integer_val)=-1; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1439 "sql.yacc"
    { (yyval.integer_val)=0; 
#ifndef  SQLCOMPILER
set_cmdlineno(token_read_on_line);
#endif
}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1447 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1448 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1449 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1450 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1451 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1452 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1453 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1461 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1462 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1463 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1464 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1474 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1475 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1476 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1480 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1481 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1488 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1491 "sql.yacc"
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
#line 1500 "sql.yacc"
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
#line 1511 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1513 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1519 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1525 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1535 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1542 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1544 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1550 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1553 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1554 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1561 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1570 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1577 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1589 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1595 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1600 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1604 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1610 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1618 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1623 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1626 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1629 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1636 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1637 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1638 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1639 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1645 "sql.yacc"
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
#line 1668 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1672 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1674 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1681 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1684 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1690 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1698 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1703 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1709 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1714 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1720 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1723 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1728 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1737 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1746 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1755 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1761 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1764 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1775 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1784 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1791 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1797 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1798 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1801 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1806 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1817 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1821 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1829 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1833 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1837 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1841 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1848 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1853 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1861 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1864 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1870 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1873 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1878 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1883 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1896 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1899 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1905 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1908 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1914 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1917 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1923 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1926 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1933 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1937 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1948 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1948 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1949 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1949 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1950 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1950 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1953 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1963 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1964 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1969 "sql.yacc"
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
#line 1978 "sql.yacc"
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
#line 1986 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1989 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1992 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1996 "sql.yacc"
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
#line 2003 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 2006 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 2010 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 2013 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 2016 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 2019 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 2025 "sql.yacc"
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
#line 2032 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 2035 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 2038 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 2041 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 2042 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 2047 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 2050 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 2053 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 2056 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 2063 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 2064 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 2065 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 2069 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2076 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 2077 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 2078 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 2082 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 2096 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2111 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2115 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2116 "sql.yacc"
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
#line 2125 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2127 "sql.yacc"
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
#line 2136 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2139 "sql.yacc"
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
#line 2147 "sql.yacc"
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
#line 2157 "sql.yacc"
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
#line 2165 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 2167 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 2168 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 2169 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 2170 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2171 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2172 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 2173 "sql.yacc"
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
#line 2181 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 2182 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2183 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2184 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2185 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2186 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2187 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2188 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2189 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2190 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2191 "sql.yacc"
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
#line 2201 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2202 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2209 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 2213 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 2238 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 2239 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 2243 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 2251 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 2254 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 2261 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 2264 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 2274 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 2277 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 2280 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 2283 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 2290 "sql.yacc"
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
#line 2297 "sql.yacc"
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
#line 2305 "sql.yacc"
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
#line 2314 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 2325 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2337 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2338 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 2348 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 2393 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2394 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2395 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2400 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2401 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 2409 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2416 "sql.yacc"
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
#line 2427 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2428 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2441 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2442 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2446 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2450 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2451 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2454 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2460 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2464 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2487 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2497 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2500 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2506 "sql.yacc"
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
#line 2515 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2519 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2526 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2528 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2530 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2534 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2540 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2543 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2549 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2550 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2557 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2570 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2580 "sql.yacc"
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
#line 2587 "sql.yacc"
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
#line 2604 "sql.yacc"
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
#line 2611 "sql.yacc"
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
#line 2636 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2638 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2640 "sql.yacc"
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
#line 2661 "sql.yacc"
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
#line 2704 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2705 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2719 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2722 "sql.yacc"
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
#line 2729 "sql.yacc"
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
#line 2739 "sql.yacc"
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
#line 2757 "sql.yacc"
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
#line 2770 "sql.yacc"
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
#line 2785 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2787 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2793 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2794 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2795 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2796 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2806 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item_list));
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2813 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2816 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2822 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2825 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2830 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2839 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2842 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2846 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2853 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2856 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2859 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2862 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2865 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2868 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2871 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2872 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2873 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2874 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2875 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2876 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2877 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2878 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2879 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2881 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2885 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2889 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2893 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2897 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2901 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2905 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2909 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2912 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2915 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2918 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2921 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2924 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2927 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2930 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2933 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2937 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2941 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2945 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2948 "sql.yacc"
    {
		(yyvsp[(3) - (4)].s_select_list_item)->data.s_select_list_item_data_u.sqlcase.master_condition=(yyvsp[(2) - (4)].s_select_list_item);
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2957 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 2960 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 2969 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 2975 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 2982 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 2985 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 3009 "sql.yacc"
    {(yyval.str_list)=NULL;}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 3010 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(2) - (4)].str));  add_str_list((yyval.str_list),(yyvsp[(4) - (4)].str));}
    break;

  case 506:

/* Line 1464 of yacc.c  */
#line 3011 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(1) - (3)].str));  add_str_list((yyval.str_list),(yyvsp[(3) - (3)].str));}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 3015 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 3018 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 3024 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 3025 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 3026 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 3027 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 3028 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 3029 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 3034 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 3038 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 3042 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 3046 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 3053 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 3056 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 3061 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 3062 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 3063 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3065 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3071 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3081 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3085 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3089 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3093 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3097 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3101 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3105 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3109 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3117 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3127 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3132 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3136 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3140 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3144 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3148 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3153 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3157 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3161 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3169 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3172 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3177 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3178 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3179 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 550:

/* Line 1464 of yacc.c  */
#line 3184 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3185 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 552:

/* Line 1464 of yacc.c  */
#line 3186 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 554:

/* Line 1464 of yacc.c  */
#line 3197 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 556:

/* Line 1464 of yacc.c  */
#line 3203 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 558:

/* Line 1464 of yacc.c  */
#line 3208 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 559:

/* Line 1464 of yacc.c  */
#line 3213 "sql.yacc"
    {(yyval.ptr_list)=0;}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3260 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3267 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 565:

/* Line 1464 of yacc.c  */
#line 3273 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3288 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 569:

/* Line 1464 of yacc.c  */
#line 3289 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3291 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3293 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3296 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 574:

/* Line 1464 of yacc.c  */
#line 3300 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3309 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3315 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3316 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 579:

/* Line 1464 of yacc.c  */
#line 3319 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 3324 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 581:

/* Line 1464 of yacc.c  */
#line 3325 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3329 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3330 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3340 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3341 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3342 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3343 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3344 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3345 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3346 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3347 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3351 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3357 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3359 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3378 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3386 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3393 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3394 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3395 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3396 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3401 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3402 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3403 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3404 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3405 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 3410 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 3411 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 3427 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 3428 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 3429 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 3430 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 3431 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 3432 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 3433 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 3434 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3435 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3436 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 3438 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 3439 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 3440 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3441 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3446 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3449 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 3458 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3459 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3460 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 3461 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 3462 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 3463 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3467 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 632:

/* Line 1464 of yacc.c  */
#line 3468 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1464 of yacc.c  */
#line 8919 "y.tab.c"
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
#line 3482 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

