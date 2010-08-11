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
     INT_VALUE = 2241,
     NAMED = 2242,
     NAMED_GEN = 2243,
     CHAR_VALUE = 2244,
     NOT_USED_1 = 2245,
     NOT_USED_2 = 2246,
     NOT_USED_3 = 2247,
     NOT_USED_4 = 2248,
     NOT_USED_5 = 2249,
     NOT_USED_6 = 2250,
     NOT_USED_7 = 2251,
     NOT_USED_8 = 2252,
     NUMBER_VALUE = 2253,
     SEMICOLON = 2254,
     QUESTION_MARK = 2255,
     CLINE = 2256,
     CH = 2257,
     MARK_VAR = 2258,
     END_MARK_VAR = 2259,
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
     DOUBLE_PRECISION = 1195,
     COUNT_MULTIPLY = 1196,
     MODIFY_NEXT_SIZE = 1216,
     LOCK_MODE_PAGE = 1217,
     LOCK_MODE_ROW = 1218,
     UNITS_YEAR = 1225,
     UNITS_MONTH = 1226,
     UNITS_DAY = 1227,
     UNITS_HOUR = 1228,
     UNITS_MINUTE = 1229,
     UNITS_SECOND = 1230,
     TO_CLUSTER = 1235,
     TO_NOT_CLUSTER = 1236,
     CREATE_UC_IDX = 1238,
     CREATE_U_IDX = 1239,
     CREATE_C_IDX = 1240,
     CREATE_IDX = 1241,
     DOUBLE_COLON = 1251,
     SQLSICS = 1257,
     CREATE_SCHEMA = 1258,
     SQLSIRR = 1259,
     UPDATESTATS_T = 1260,
     SQLSICR = 1261,
     SQLSIDR = 1272,
     CREATE_TEMP_TABLE = 1273,
     WITH_CHECK_OPTION = 1281,
     WITH_GRANT_OPTION = 1282,
     SQLSLMNW = 1283,
     WHERE_CURRENT_OF = 1289,
     NOT_NULL_UNIQUE = 1297,
     SQLSLMW = 1304,
     ALL_PRIVILEGES = 1306,
     CREATE_SYNONYM = 1310,
     DROP_TABLE = 1311,
     INEXCLUSIVE = 1313,
     UPDATESTATS = 1318,
     CREATE_TABLE = 1344,
     DEFAULT_NULL = 1345,
     DEFAULT_TODAY = 1346,
     DEFAULT_USER = 1347,
     EXIT_TODO = 1354,
     CONTINUE_TODO = 1355,
     UNLOCK_TABLE = 1362,
     ROLLBACK_W = 1370,
     SQLSEON = 1372,
     SQLSEOFF = 1373,
     CREATE_VIEW = 1377,
     DELETE_FROM = 1378,
     EXTENT_SIZE = 1385,
     FOREIGN_KEY = 1386,
     INSERT_INTO = 1389,
     IS_NOT_NULL = 1391,
     NOT_MATCHES = 1394,
     PRIMARY_KEY = 1400,
     WITH_NO_LOG = 1407,
     INSHARE = 1410,
     BEGIN_WORK = 1416,
     DROP_INDEX = 1421,
     FOR_UPDATE_OF = 1427,
     FOR_UPDATE = 1428,
     LOCK_TABLE = 1433,
     NOT_EXISTS = 1435,
     REFERENCES = 1437,
     RENCOL = 1438,
     SMALLFLOAT = 1440,
     COMMIT_W = 1451,
     RENTAB = 1458,
     KW_CHAR = 1461,
     NCHAR = 1462,
     NVARCHAR = 1463,
     DELIMITER = 1465,
     DROP_VIEW = 1467,
     EXCLUSIVE = 1470,
     GREATER_THAN_EQ = 1474,
     INTO_TEMP = 1476,
     DATABASE = 1500,
     DATETIME = 1501,
     DISTINCT = 1503,
     FRACTION = 1510,
     GROUP_BY = 1512,
     INTERVAL = 1513,
     NOT_LIKE = 1515,
     NOT_ILIKE = 1516,
     NOT_NULL = 1517,
     RESOURCE = 1523,
     SMALLINT = 1524,
     IS_NULL = 1530,
     LESS_THAN_EQ = 1531,
     BETWEEN = 1533,
     CLOSE_BRACKET = 1536,
     CONNECT = 1539,
     KW_CURRENT = 1540,
     KW_DECIMAL = 1542,
     DEFAULT = 1544,
     INTEGER = 1552,
     SERIAL8 = 1554,
     MATCHES = 1557,
     VARCHAR = 1570,
     CLOSE_SQUARE = 1573,
     GREATER_THAN = 1574,
     KW_FALSE = 1575,
     NOT_IN = 1576,
     OPEN_BRACKET = 1578,
     KW_DELETE = 1586,
     KW_ESCAPE = 1589,
     EXISTS = 1590,
     EXTEND = 1591,
     HAVING = 1595,
     KW_INSERT = 1597,
     MINUTE = 1601,
     MODIFY = 1602,
     EQUAL = 1604,
     NOT_EQUAL = 1605,
     OPEN_SQUARE = 1607,
     PUBLIC = 1611,
     KW_RETURN_KEY = 1614,
     REVOKE = 1616,
     SECOND = 1620,
     KW_SELECT = 1624,
     SERIAL = 1625,
     UNIQUE = 1628,
     KW_UPDATE = 1630,
     VALUES = 1631,
     KW_NULL = 1634,
     KW_TRUE = 1635,
     ALTER = 1637,
     CHECK = 1643,
     COUNT = 1647,
     KW_FIRST = 1652,
     KW_FLOAT = 1653,
     GRANT = 1656,
     INDEX = 1659,
     LESS_THAN = 1662,
     MONEY = 1664,
     MONTH = 1665,
     KW_MULTIPLY = 1667,
     ORDER = 1668,
     OUTER = 1669,
     UNION = 1678,
     WHERE = 1681,
     KW_BYTE = 1688,
     CASE = 1690,
     KW_DATE = 1692,
     DESC = 1693,
     KW_DIVIDE = 1694,
     DROP = 1697,
     ELSE = 1698,
     FROM = 1702,
     HOUR = 1708,
     INTO = 1709,
     LIKE = 1712,
     REAL = 1721,
     SOME = 1726,
     KW_TEXT = 1730,
     KW_THEN = 1731,
     USER = 1732,
     WHEN = 1734,
     YEAR = 1737,
     KW_DOW = 1738,
     XSET = 1740,
     ADD = 1741,
     ALL = 1742,
     KW_AND = 1743,
     ANY = 1744,
     ASC = 1745,
     AVG = 1746,
     COLON = 1747,
     KW_COMMA = 1748,
     DAY = 1749,
     DBA = 1750,
     KW_FOR = 1754,
     XMAX = 1759,
     XMIN = 1760,
     KW_MINUS = 1761,
     KW_MOD = 1762,
     KW_NOT = 1763,
     KW_SUM = 1770,
     ATSIGN = 1773,
     KW_PLUS = 1774,
     KW_AS = 1780,
     KW_BY = 1782,
     KW_DOT = 1783,
     KW_IN = 1786,
     KW_ON = 1788,
     KW_OR = 1789,
     KW_TO = 1790,
     BEFORE = 1828,
     END = 1832,
     TILDE = 1839,
     ILIKE = 1840,
     FILLFACTOR = 1843,
     TIME = 1848,
     KW_TODAY = 1855,
     KW_ROWID = 1856,
     TIMESTAMP = 2204,
     SET_TEXT_FORMAT = 2216,
     KW_TAG = 2226,
     LINTMODULEISLIBRARY = 2227,
     KW_PUBLIC = 2228,
     KW_PRIVATE = 2229,
     COPYBACK = 2230,
     REFERENCES_BLOBTYPE_DEFAULT_NULL = 2231,
     REFERENCES_BLOBTYPE = 2232,
     SORT = 2233,
     KWPIPE = 2234,
     KW_DONE = 2235,
     END_TODO = 2236,
     KW_TODO = 2237,
     KW_ALWAYS = 2238,
     PROGRAM_TIMEOUT = 2239
   };
#endif
/* Tokens.  */
#define INT_VALUE 2241
#define NAMED 2242
#define NAMED_GEN 2243
#define CHAR_VALUE 2244
#define NOT_USED_1 2245
#define NOT_USED_2 2246
#define NOT_USED_3 2247
#define NOT_USED_4 2248
#define NOT_USED_5 2249
#define NOT_USED_6 2250
#define NOT_USED_7 2251
#define NOT_USED_8 2252
#define NUMBER_VALUE 2253
#define SEMICOLON 2254
#define QUESTION_MARK 2255
#define CLINE 2256
#define CH 2257
#define MARK_VAR 2258
#define END_MARK_VAR 2259
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
#define DOUBLE_PRECISION 1195
#define COUNT_MULTIPLY 1196
#define MODIFY_NEXT_SIZE 1216
#define LOCK_MODE_PAGE 1217
#define LOCK_MODE_ROW 1218
#define UNITS_YEAR 1225
#define UNITS_MONTH 1226
#define UNITS_DAY 1227
#define UNITS_HOUR 1228
#define UNITS_MINUTE 1229
#define UNITS_SECOND 1230
#define TO_CLUSTER 1235
#define TO_NOT_CLUSTER 1236
#define CREATE_UC_IDX 1238
#define CREATE_U_IDX 1239
#define CREATE_C_IDX 1240
#define CREATE_IDX 1241
#define DOUBLE_COLON 1251
#define SQLSICS 1257
#define CREATE_SCHEMA 1258
#define SQLSIRR 1259
#define UPDATESTATS_T 1260
#define SQLSICR 1261
#define SQLSIDR 1272
#define CREATE_TEMP_TABLE 1273
#define WITH_CHECK_OPTION 1281
#define WITH_GRANT_OPTION 1282
#define SQLSLMNW 1283
#define WHERE_CURRENT_OF 1289
#define NOT_NULL_UNIQUE 1297
#define SQLSLMW 1304
#define ALL_PRIVILEGES 1306
#define CREATE_SYNONYM 1310
#define DROP_TABLE 1311
#define INEXCLUSIVE 1313
#define UPDATESTATS 1318
#define CREATE_TABLE 1344
#define DEFAULT_NULL 1345
#define DEFAULT_TODAY 1346
#define DEFAULT_USER 1347
#define EXIT_TODO 1354
#define CONTINUE_TODO 1355
#define UNLOCK_TABLE 1362
#define ROLLBACK_W 1370
#define SQLSEON 1372
#define SQLSEOFF 1373
#define CREATE_VIEW 1377
#define DELETE_FROM 1378
#define EXTENT_SIZE 1385
#define FOREIGN_KEY 1386
#define INSERT_INTO 1389
#define IS_NOT_NULL 1391
#define NOT_MATCHES 1394
#define PRIMARY_KEY 1400
#define WITH_NO_LOG 1407
#define INSHARE 1410
#define BEGIN_WORK 1416
#define DROP_INDEX 1421
#define FOR_UPDATE_OF 1427
#define FOR_UPDATE 1428
#define LOCK_TABLE 1433
#define NOT_EXISTS 1435
#define REFERENCES 1437
#define RENCOL 1438
#define SMALLFLOAT 1440
#define COMMIT_W 1451
#define RENTAB 1458
#define KW_CHAR 1461
#define NCHAR 1462
#define NVARCHAR 1463
#define DELIMITER 1465
#define DROP_VIEW 1467
#define EXCLUSIVE 1470
#define GREATER_THAN_EQ 1474
#define INTO_TEMP 1476
#define DATABASE 1500
#define DATETIME 1501
#define DISTINCT 1503
#define FRACTION 1510
#define GROUP_BY 1512
#define INTERVAL 1513
#define NOT_LIKE 1515
#define NOT_ILIKE 1516
#define NOT_NULL 1517
#define RESOURCE 1523
#define SMALLINT 1524
#define IS_NULL 1530
#define LESS_THAN_EQ 1531
#define BETWEEN 1533
#define CLOSE_BRACKET 1536
#define CONNECT 1539
#define KW_CURRENT 1540
#define KW_DECIMAL 1542
#define DEFAULT 1544
#define INTEGER 1552
#define SERIAL8 1554
#define MATCHES 1557
#define VARCHAR 1570
#define CLOSE_SQUARE 1573
#define GREATER_THAN 1574
#define KW_FALSE 1575
#define NOT_IN 1576
#define OPEN_BRACKET 1578
#define KW_DELETE 1586
#define KW_ESCAPE 1589
#define EXISTS 1590
#define EXTEND 1591
#define HAVING 1595
#define KW_INSERT 1597
#define MINUTE 1601
#define MODIFY 1602
#define EQUAL 1604
#define NOT_EQUAL 1605
#define OPEN_SQUARE 1607
#define PUBLIC 1611
#define KW_RETURN_KEY 1614
#define REVOKE 1616
#define SECOND 1620
#define KW_SELECT 1624
#define SERIAL 1625
#define UNIQUE 1628
#define KW_UPDATE 1630
#define VALUES 1631
#define KW_NULL 1634
#define KW_TRUE 1635
#define ALTER 1637
#define CHECK 1643
#define COUNT 1647
#define KW_FIRST 1652
#define KW_FLOAT 1653
#define GRANT 1656
#define INDEX 1659
#define LESS_THAN 1662
#define MONEY 1664
#define MONTH 1665
#define KW_MULTIPLY 1667
#define ORDER 1668
#define OUTER 1669
#define UNION 1678
#define WHERE 1681
#define KW_BYTE 1688
#define CASE 1690
#define KW_DATE 1692
#define DESC 1693
#define KW_DIVIDE 1694
#define DROP 1697
#define ELSE 1698
#define FROM 1702
#define HOUR 1708
#define INTO 1709
#define LIKE 1712
#define REAL 1721
#define SOME 1726
#define KW_TEXT 1730
#define KW_THEN 1731
#define USER 1732
#define WHEN 1734
#define YEAR 1737
#define KW_DOW 1738
#define XSET 1740
#define ADD 1741
#define ALL 1742
#define KW_AND 1743
#define ANY 1744
#define ASC 1745
#define AVG 1746
#define COLON 1747
#define KW_COMMA 1748
#define DAY 1749
#define DBA 1750
#define KW_FOR 1754
#define XMAX 1759
#define XMIN 1760
#define KW_MINUS 1761
#define KW_MOD 1762
#define KW_NOT 1763
#define KW_SUM 1770
#define ATSIGN 1773
#define KW_PLUS 1774
#define KW_AS 1780
#define KW_BY 1782
#define KW_DOT 1783
#define KW_IN 1786
#define KW_ON 1788
#define KW_OR 1789
#define KW_TO 1790
#define BEFORE 1828
#define END 1832
#define TILDE 1839
#define ILIKE 1840
#define FILLFACTOR 1843
#define TIME 1848
#define KW_TODAY 1855
#define KW_ROWID 1856
#define TIMESTAMP 2204
#define SET_TEXT_FORMAT 2216
#define KW_TAG 2226
#define LINTMODULEISLIBRARY 2227
#define KW_PUBLIC 2228
#define KW_PRIVATE 2229
#define COPYBACK 2230
#define REFERENCES_BLOBTYPE_DEFAULT_NULL 2231
#define REFERENCES_BLOBTYPE 2232
#define SORT 2233
#define KWPIPE 2234
#define KW_DONE 2235
#define END_TODO 2236
#define KW_TODO 2237
#define KW_ALWAYS 2238
#define PROGRAM_TIMEOUT 2239




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
#line 862 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 874 "y.tab.c"

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
#define YYLAST   2270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  290
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  631
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1111

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   2259

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
       2,     2,     2,     2,     2,    80,    81,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    82,    83,    84,     2,
       2,     2,     2,     2,     2,    85,    86,    87,    88,    89,
      90,     2,     2,     2,     2,    91,    92,     2,    93,    94,
      95,    96,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    97,     2,     2,     2,     2,     2,    98,    99,   100,
     101,   102,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   103,   104,     2,     2,     2,     2,     2,     2,
       2,   105,   106,   107,     2,     2,     2,     2,     2,   108,
       2,     2,     2,     2,     2,     2,     2,   109,     2,     2,
       2,     2,     2,     2,   110,     2,   111,     2,     2,     2,
     112,   113,     2,   114,     2,     2,     2,     2,   115,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   116,   117,   118,   119,     2,     2,
       2,     2,     2,     2,   120,   121,     2,     2,     2,     2,
       2,     2,   122,     2,     2,     2,     2,     2,     2,     2,
     123,     2,   124,   125,     2,     2,     2,   126,   127,     2,
       2,     2,     2,     2,     2,   128,   129,     2,     2,   130,
       2,   131,     2,     2,   132,     2,     2,     2,     2,     2,
     133,     2,     2,     2,     2,     2,     2,   134,     2,     2,
     135,     2,     2,     2,     2,     2,   136,     2,     2,     2,
       2,   137,     2,     2,     2,     2,     2,   138,   139,     2,
       2,     2,     2,   140,     2,   141,     2,   142,   143,     2,
     144,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   145,     2,     2,     2,     2,     2,     2,   146,     2,
       2,   147,   148,   149,     2,   150,     2,   151,     2,     2,
     152,     2,     2,     2,   153,     2,   154,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     155,   156,     2,   157,     2,     2,     2,     2,     2,     2,
     158,     2,   159,   160,     2,   161,   162,   163,     2,     2,
       2,     2,     2,   164,   165,     2,     2,     2,     2,     2,
     166,   167,     2,   168,     2,     2,   169,     2,     2,   170,
     171,     2,   172,     2,   173,     2,     2,     2,     2,     2,
       2,     2,   174,     2,   175,     2,     2,   176,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     177,     2,     2,   178,   179,   180,   181,     2,   182,     2,
       2,     2,     2,     2,     2,     2,   183,     2,     2,   184,
     185,   186,     2,     2,     2,   187,     2,   188,     2,     2,
       2,   189,   190,     2,   191,   192,     2,   193,     2,     2,
       2,   194,     2,     2,   195,     2,   196,     2,     2,     2,
     197,     2,     2,     2,   198,   199,     2,     2,   200,     2,
     201,   202,     2,     2,   203,   204,     2,   205,     2,     2,
       2,     2,     2,   206,     2,     2,     2,   207,     2,     2,
       2,     2,   208,   209,     2,     2,   210,     2,     2,   211,
       2,     2,   212,     2,   213,   214,     2,   215,   216,   217,
       2,     2,     2,     2,     2,     2,     2,     2,   218,     2,
       2,   219,     2,     2,     2,     2,     2,     2,   220,     2,
     221,     2,   222,   223,   224,     2,     2,   225,   226,     2,
       2,     2,   227,     2,     2,     2,     2,     2,   228,   229,
       2,     2,   230,     2,     2,     2,     2,     2,     2,     2,
       2,   231,     2,     2,     2,     2,   232,     2,     2,     2,
     233,   234,   235,     2,   236,     2,     2,   237,   238,     2,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,     2,     2,     2,   250,     2,     2,     2,     2,   251,
     252,   253,   254,   255,     2,     2,     2,     2,     2,     2,
     256,     2,     2,   257,   258,     2,     2,     2,     2,     2,
     259,     2,   260,   261,     2,     2,   262,     2,   263,   264,
     265,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   266,     2,
       2,     2,   267,     2,     2,     2,     2,     2,     2,   268,
     269,     2,     2,   270,     2,     2,     2,     2,   271,     2,
       2,     2,     2,     2,     2,   272,   273,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   274,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   275,     2,     2,     2,
       2,     2,     2,     2,     2,     2,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21
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
     498,     0,    -1,   201,   489,   294,   292,    -1,    -1,   108,
     493,    -1,   219,   403,    -1,    -1,   108,   493,    -1,   219,
     403,    -1,    71,   299,   169,   191,   182,   300,   169,    -1,
      67,   300,   169,    -1,    68,   300,   169,    -1,   239,   295,
      -1,    70,   300,    -1,    69,   300,    -1,   298,    -1,   295,
     247,   298,    -1,   297,    -1,   257,   297,    -1,   492,   429,
      -1,   492,   261,   492,   429,    -1,   492,   261,   492,   261,
     492,   429,    -1,   492,   261,   215,    -1,   296,   191,   301,
      -1,   296,    -1,   299,   247,   296,    -1,   301,    -1,   300,
     247,   301,    -1,   476,    -1,   203,    -1,   303,    -1,   113,
     489,    -1,   151,   489,    -1,   137,   491,    -1,    60,   492,
      -1,   314,    -1,   305,    -1,   116,   489,   182,   319,   169,
     306,    -1,   104,   489,   182,   319,   169,   315,   306,   315,
      -1,    -1,   307,    -1,   308,    -1,   307,   308,    -1,   262,
     309,    -1,   128,     3,    -1,    66,     3,    -1,    83,    -1,
      84,    -1,     4,    -1,    -1,   311,    -1,   312,    -1,   311,
     312,    -1,   262,   309,    -1,   270,     3,    -1,    45,    -1,
      46,    -1,   489,    -1,    94,   491,   263,   313,   182,   317,
     169,   310,    -1,    93,   491,   263,   313,   182,   317,   169,
     310,    -1,    95,   491,   263,   313,   182,   317,   169,   310,
      -1,    96,   491,   263,   313,   182,   317,   169,   310,    -1,
      72,   502,    -1,    73,   502,    -1,   112,   489,   250,   489,
      -1,    62,   489,   262,     6,    -1,    61,   489,    -1,    76,
     489,    -1,    57,   489,    -1,    58,   492,    -1,    -1,   134,
      -1,    -1,   134,    -1,   318,    -1,   317,   247,   318,    -1,
     492,   244,    -1,   492,   223,    -1,   492,    -1,   320,    -1,
     319,   247,   320,    -1,   383,    -1,   381,    -1,    64,   492,
     322,    -1,    65,   491,    91,    -1,    65,   491,    92,    -1,
     323,    -1,   322,   247,   323,    -1,   324,    -1,   327,    -1,
     330,    -1,   335,    -1,   338,    -1,   334,    -1,   333,    -1,
     240,   325,    -1,   240,   182,   326,   169,    -1,   320,    -1,
     320,   266,   492,    -1,   325,    -1,   326,   247,   325,    -1,
     225,   329,    -1,   225,   182,   328,   169,    -1,   329,    -1,
     328,   247,   329,    -1,   492,    -1,   190,   332,    -1,   190,
     182,   331,   169,    -1,   332,    -1,   331,   247,   332,    -1,
     320,    -1,    83,    -1,    84,    -1,    82,     3,    -1,    74,
     381,   337,    -1,    74,   182,   336,   169,    -1,   381,   337,
      -1,   336,   247,   381,   337,    -1,    -1,    77,   492,    -1,
      75,   339,    -1,    75,   182,   339,   169,    -1,   340,    -1,
     339,   247,   340,    -1,   492,    -1,   123,    -1,    -1,   130,
     343,   489,   346,   344,    -1,    -1,   202,   345,   182,   349,
     169,    -1,   469,    -1,    -1,   182,   347,   169,    -1,   348,
      -1,   347,   247,   348,    -1,   492,    -1,   492,   261,   492,
      -1,   350,    -1,   349,   247,   350,    -1,   476,    -1,   203,
      -1,   127,   489,   293,    -1,   136,    -1,   145,    -1,    -1,
     152,    -1,   356,    -1,    52,   492,    53,     6,    51,    -1,
      52,   492,    53,     6,    -1,    54,    -1,    47,    -1,    48,
      -1,   101,   492,    -1,   115,    -1,   353,    -1,   352,    -1,
     341,    -1,   355,    -1,   389,    -1,   393,    -1,   439,    -1,
     302,    -1,   304,    -1,   321,    -1,   210,   362,   263,   489,
     265,   367,   361,    -1,   196,   362,   263,   489,   227,   367,
      -1,   210,   360,   265,   367,    -1,   196,   360,   227,   367,
      -1,   170,    -1,   164,    -1,   249,    -1,    -1,   106,    -1,
     259,   428,    -1,   111,    -1,   241,    -1,   363,    -1,   364,
      -1,   363,   247,   364,    -1,   198,   365,    -1,   188,    -1,
     183,    -1,   201,   365,    -1,   205,    -1,   211,    -1,    -1,
     182,   366,   169,    -1,   430,    -1,   366,   247,   430,    -1,
     368,    -1,   367,   247,   368,    -1,   194,    -1,   428,    -1,
     126,   489,   370,   259,   460,   372,    -1,    -1,   182,   371,
     169,    -1,   430,    -1,   371,   247,   430,    -1,    -1,   105,
      -1,   206,   182,   459,   169,    -1,   129,   182,   376,   169,
     375,    -1,   142,   377,    -1,   378,    -1,   489,    -1,   489,
     182,   378,   169,    -1,   430,    -1,   378,   247,   430,    -1,
     200,   182,   380,   169,    -1,   157,   182,   380,   169,    -1,
     133,   182,   380,   169,    -1,   430,    -1,   380,   247,   430,
      -1,   379,    -1,   374,    -1,   373,    -1,   173,   435,    -1,
     119,    -1,   118,    -1,   117,    -1,   492,   419,   384,   385,
      -1,    -1,   382,    -1,    -1,   386,    -1,   387,    -1,   386,
     387,    -1,   388,   337,    -1,   163,    -1,   109,    -1,   200,
      -1,   157,    -1,   375,    -1,   206,   182,   459,   169,    -1,
     133,    -1,    99,   390,   392,    -1,   391,    -1,   428,    -1,
     393,    -1,   392,   393,    -1,   369,    -1,   359,    -1,   187,
     403,    -1,   219,   403,    -1,   227,   397,    -1,   399,    -1,
     397,   247,   399,    -1,   397,   247,   217,   399,    -1,   397,
     247,   217,   182,   397,   169,    -1,   397,    34,   398,   263,
     403,    -1,   397,    41,   398,   263,   403,    -1,   397,    -1,
     182,   397,   169,    -1,   489,    -1,   489,   434,    -1,   489,
     259,   434,    -1,    -1,   396,   401,    -1,   402,    -1,   395,
     402,    -1,    -1,   456,    -1,   456,   394,    -1,   394,    -1,
     404,    -1,   403,   264,   404,    -1,   405,    -1,   404,   242,
     405,    -1,   406,    -1,   255,   406,    -1,   416,    -1,   182,
     403,   169,    -1,   185,   470,    -1,   141,   470,    -1,    -1,
     184,   412,    -1,    -1,   184,   412,    -1,    -1,   184,   412,
      -1,   515,    -1,   435,    -1,    -1,   255,    -1,   476,   413,
     166,    -1,   476,   413,   131,    -1,   476,   415,   476,    -1,
     476,   191,   476,    -1,   476,   191,   203,    -1,   476,   413,
     168,   476,   242,   476,    -1,   476,   230,   411,   410,    -1,
     476,   161,   411,   410,    -1,   476,   269,   411,   409,    -1,
     476,   162,   411,   409,    -1,   476,   176,   411,   408,    -1,
     476,   132,   411,   408,    -1,   192,    -1,   212,    -1,   179,
      -1,   268,    -1,   167,    -1,   153,    -1,   414,    -1,   484,
      -1,   407,    -1,   476,    -1,    -1,   241,    -1,   157,    -1,
     200,    -1,    -1,   241,    -1,   157,    -1,   200,    -1,   420,
      -1,   421,    -1,   422,    -1,   424,    -1,   147,    -1,   147,
     182,   425,   169,    -1,   199,    -1,   199,   182,     3,   169,
      -1,   175,    -1,   175,   182,     3,   169,    -1,   172,    -1,
     172,   182,   426,   423,   169,    -1,   213,   182,   426,   423,
     169,    -1,   213,    -1,   222,    -1,   174,    -1,   165,    -1,
     148,    -1,   148,   182,   425,   169,    -1,   149,    -1,   149,
     182,     3,   169,    -1,   149,   182,     3,   247,     3,   169,
      -1,   156,   437,   265,   438,    -1,   156,    -1,   160,   437,
     265,   438,    -1,   461,    -1,   160,    -1,   160,   437,   182,
       3,   169,   265,   438,    -1,   233,    -1,   220,    -1,   177,
      -1,   177,   182,     3,   169,    -1,   177,   182,     3,   247,
       3,   169,    -1,    -1,   247,   427,    -1,   209,   182,   426,
     169,    -1,   231,    -1,   144,    -1,   209,    -1,    80,    -1,
       3,    -1,     3,    -1,     3,    -1,   492,    -1,     6,    -1,
      -1,   193,     3,   178,    -1,   193,     3,   247,     3,   178,
      -1,   433,    -1,   257,   433,    -1,   432,    -1,   257,   432,
      -1,   492,   429,    -1,   487,   261,   492,   429,    -1,   487,
     261,   215,    -1,   273,    -1,   492,   429,    -1,   487,   261,
     492,   429,    -1,   492,   261,   492,   261,   492,   429,    -1,
     487,   261,   215,    -1,   492,    -1,     6,    -1,   494,    -1,
       3,    -1,   450,    -1,    -1,   437,   265,   438,    -1,   237,
      -1,   214,    -1,   248,    -1,   228,    -1,   189,    -1,   197,
      -1,   158,    -1,   237,    -1,   214,    -1,   248,    -1,   228,
      -1,   189,    -1,   197,    -1,   158,    -1,   158,   182,     3,
     169,    -1,   444,    -1,   443,    -1,   440,    -1,   146,   441,
     265,   441,    -1,   143,   487,   261,   442,   265,   442,    -1,
     492,    -1,   492,    -1,   122,   489,    -1,   140,   489,   445,
      -1,   135,    -1,   114,    -1,   447,    -1,   447,   437,   265,
     438,    -1,    55,    -1,   449,    -1,   449,   437,   182,     3,
     169,   265,   438,    -1,   449,   437,   265,   438,    -1,    56,
      -1,   171,   436,    -1,   216,   260,   452,    -1,   453,    -1,
     452,   247,   453,    -1,   454,   455,    -1,     3,    -1,   431,
      -1,    -1,   244,    -1,   223,    -1,   159,   457,    -1,   458,
      -1,   457,   247,   458,    -1,   431,    -1,     3,    -1,   403,
      -1,   469,    -1,   271,    -1,   271,   182,     3,   169,    -1,
     274,    -1,   274,   182,     3,   169,    -1,    -1,    -1,   198,
     471,   472,   463,   473,   464,   496,   400,   466,   467,    -1,
     198,   471,   472,   473,   400,   466,    -1,    -1,   218,   418,
     465,    -1,    -1,   451,    -1,   451,   154,   468,   316,    -1,
     154,   468,   316,    -1,   492,    -1,   198,   471,   472,   473,
     400,    -1,   182,   198,   471,   472,   473,   400,   169,    -1,
      -1,   208,     3,    -1,    -1,   241,    -1,   157,    -1,   200,
      -1,   474,    -1,   475,    -1,   473,   247,   475,    -1,   476,
      -1,   476,   492,    -1,   476,   259,   492,    -1,   515,    -1,
     253,   515,    -1,   258,   515,    -1,   515,   224,   476,    -1,
     515,   483,    -1,   515,   215,   476,    -1,   515,   258,   476,
      -1,   515,   253,   476,    -1,   515,    59,   476,    -1,   435,
      -1,   204,    -1,   180,    -1,   235,    -1,   272,    -1,   273,
      -1,   271,    -1,   215,    -1,    81,    -1,   245,   182,   417,
     476,   169,    -1,   251,   182,   417,   476,   169,    -1,   252,
     182,   417,   476,   169,    -1,   256,   182,   417,   476,   169,
      -1,   207,   182,   417,   476,   169,    -1,     4,   182,   169,
      -1,     4,   182,   480,   169,    -1,   237,   182,   480,   169,
      -1,   214,   182,   480,   169,    -1,   248,   182,   480,   169,
      -1,    49,   182,   480,   169,    -1,    50,   182,   480,   169,
      -1,   238,   182,   480,   169,    -1,   222,   182,   480,   169,
      -1,   182,   476,   169,    -1,   186,   182,   482,   169,    -1,
     446,    -1,   448,    -1,   221,   478,   267,    -1,   479,    -1,
     478,   479,    -1,   236,   403,   234,   476,    -1,   226,   476,
      -1,   476,    -1,   480,   247,   476,    -1,    -1,   247,   437,
     265,   438,    -1,   437,   265,   438,    -1,    -1,   508,   481,
      -1,   476,   481,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,    90,    -1,   476,   262,   182,   485,
     169,    -1,   476,   262,   470,    -1,   476,   181,   182,   485,
     169,    -1,   476,   181,   470,    -1,   486,    -1,   485,   247,
     486,    -1,   508,    -1,   435,    -1,   253,     3,    -1,   253,
     494,    -1,   488,    -1,     6,    -1,     6,   261,   492,    -1,
     492,    -1,   492,   246,   492,    -1,   492,   246,     6,   261,
     492,    -1,   492,   257,   492,    -1,   492,   257,   492,   246,
     492,    -1,   492,   257,   492,   246,     6,   261,   492,    -1,
     490,    -1,     6,   261,   492,    -1,   492,   261,   492,    -1,
       6,    -1,   492,    -1,   492,   246,   492,    -1,   492,   246,
       6,   261,   492,    -1,   492,   257,   492,    -1,   492,   257,
     492,   246,   492,    -1,   492,   257,   492,   246,     6,   261,
     492,    -1,     6,   261,   492,    -1,     6,    -1,   492,    -1,
     492,   246,   492,    -1,   492,   246,     6,   261,   492,    -1,
     492,   257,   492,    -1,   492,   257,   492,   246,   492,    -1,
     492,   257,   492,   246,     6,   261,   492,    -1,     4,    -1,
       4,    -1,    15,    -1,   261,     3,    -1,     4,    -1,     6,
      -1,    -1,   492,    -1,   500,    -1,   498,    16,   500,    -1,
     342,    -1,   291,    -1,   351,    -1,    -1,   509,    -1,   358,
      -1,   501,    -1,   507,    -1,   499,    -1,   357,    -1,     1,
      -1,   503,   504,    -1,   497,    -1,   462,    -1,    -1,   139,
      -1,   138,   505,    -1,   506,    -1,   505,   247,   506,    -1,
     492,    -1,   492,   261,   492,    -1,     6,   261,   492,   261,
     492,    -1,   125,    -1,   124,    -1,   110,   517,    -1,   107,
      -1,   103,    -1,   100,    -1,    98,    -1,   102,    -1,   514,
      -1,    17,    -1,   510,    -1,   155,   495,   354,    -1,    20,
       6,    21,    -1,   182,   511,   169,    -1,   511,   512,   511,
      -1,     3,    -1,   513,     3,    -1,   258,    -1,   253,    -1,
     215,    -1,   224,    -1,   254,    -1,   258,    -1,   253,    -1,
     492,    -1,   492,   261,   215,    -1,   492,   261,   273,    -1,
     492,   261,   492,    -1,   492,   261,   492,   261,   492,    -1,
       6,   261,   492,   261,   492,    -1,   492,   193,   511,   178,
      -1,   492,   261,   492,   193,   511,   178,    -1,   492,   261,
     492,   261,   492,   193,   511,   178,    -1,     6,   261,   492,
     261,   492,   193,   511,   178,    -1,   492,   193,   511,   247,
     511,   178,    -1,   492,   261,   492,   193,   511,   247,   511,
     178,    -1,   492,   261,   492,   261,   492,   193,   511,   247,
     511,   178,    -1,     6,   261,   492,   261,   492,   193,   511,
     247,   511,   178,    -1,   516,    -1,   516,    97,   419,    -1,
     477,    -1,   508,    -1,   470,    -1,   241,   470,    -1,   243,
     470,    -1,   232,   470,    -1,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   464,   464,   490,   493,   510,   515,   518,   535,   541,
     550,   559,   568,   575,   590,   645,   652,   663,   666,   671,
     678,   695,   712,   733,   742,   745,   753,   756,   764,   765,
     772,   775,   783,   786,   790,   796,   797,   801,   811,   825,
     826,   830,   831,   836,   844,   852,   860,   868,   878,   880,
     880,   883,   884,   888,   895,   902,   909,   918,   922,   929,
     941,   952,   958,   962,   966,   971,   975,   978,   982,   985,
     992,   993,  1003,  1004,  1008,  1009,  1013,  1022,  1031,  1038,
    1041,  1047,  1050,  1061,  1065,  1070,  1077,  1080,  1089,  1092,
    1096,  1100,  1104,  1108,  1112,  1120,  1124,  1132,  1135,  1142,
    1145,  1152,  1155,  1162,  1163,  1168,  1172,  1175,  1181,  1184,
    1190,  1197,  1198,  1202,  1210,  1214,  1221,  1223,  1228,  1229,
    1233,  1235,  1241,  1242,  1245,  1256,  1262,  1262,  1271,  1271,
    1280,  1305,  1308,  1316,  1319,  1326,  1329,  1337,  1338,  1344,
    1345,  1353,  1371,  1375,  1380,  1381,  1391,  1400,  1404,  1408,
    1413,  1417,  1421,  1424,  1431,  1432,  1433,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1451,  1452,  1453,  1454,  1459,  1460,
    1461,  1464,  1465,  1466,  1470,  1471,  1472,  1476,  1477,  1481,
    1488,  1489,  1490,  1497,  1498,  1501,  1502,  1507,  1508,  1513,
    1514,  1519,  1520,  1525,  1532,  1533,  1538,  1539,  1543,  1544,
    1551,  1559,  1566,  1573,  1577,  1578,  1583,  1584,  1590,  1594,
    1599,  1606,  1607,  1613,  1616,  1619,  1626,  1627,  1628,  1629,
    1635,  1658,  1659,  1662,  1664,  1671,  1674,  1680,  1688,  1693,
    1699,  1704,  1710,  1713,  1718,  1726,  1735,  1740,  1744,  1745,
    1751,  1754,  1765,  1774,  1781,  1787,  1788,  1791,  1796,  1807,
    1811,  1818,  1819,  1823,  1827,  1831,  1838,  1843,  1851,  1854,
    1860,  1863,  1868,  1873,  1886,  1889,  1895,  1898,  1904,  1907,
    1913,  1916,  1923,  1927,  1938,  1938,  1939,  1939,  1940,  1940,
    1943,  1948,  1953,  1954,  1959,  1968,  1976,  1979,  1982,  1986,
    1993,  1996,  2000,  2003,  2006,  2009,  2015,  2022,  2025,  2028,
    2031,  2032,  2037,  2040,  2043,  2046,  2053,  2054,  2055,  2059,
    2066,  2067,  2068,  2072,  2086,  2093,  2094,  2095,  2099,  2100,
    2105,  2106,  2115,  2117,  2126,  2129,  2137,  2147,  2155,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2171,  2172,  2173,  2174,
    2175,  2176,  2177,  2178,  2179,  2180,  2181,  2191,  2192,  2198,
    2200,  2201,  2202,  2203,  2207,  2211,  2215,  2222,  2223,  2228,
    2229,  2233,  2241,  2244,  2251,  2254,  2264,  2267,  2270,  2273,
    2280,  2287,  2295,  2304,  2311,  2315,  2320,  2321,  2322,  2327,
    2328,  2337,  2337,  2337,  2337,  2337,  2337,  2337,  2338,  2338,
    2338,  2338,  2338,  2338,  2338,  2338,  2383,  2384,  2385,  2390,
    2391,  2394,  2395,  2399,  2406,  2417,  2418,  2431,  2432,  2436,
    2440,  2441,  2444,  2450,  2454,  2477,  2487,  2490,  2496,  2505,
    2509,  2516,  2517,  2519,  2524,  2530,  2533,  2539,  2540,  2547,
    2560,  2570,  2577,  2594,  2601,  2626,  2628,  2626,  2650,  2694,
    2695,  2709,  2712,  2719,  2729,  2741,  2747,  2760,  2775,  2777,
    2783,  2784,  2785,  2786,  2796,  2803,  2806,  2812,  2815,  2820,
    2829,  2832,  2836,  2843,  2846,  2849,  2852,  2855,  2858,  2861,
    2862,  2863,  2864,  2865,  2866,  2867,  2868,  2869,  2871,  2875,
    2879,  2883,  2887,  2891,  2895,  2899,  2902,  2905,  2908,  2911,
    2914,  2917,  2920,  2923,  2927,  2931,  2935,  2943,  2946,  2955,
    2961,  2968,  2971,  2995,  2996,  2997,  3000,  3001,  3004,  3010,
    3011,  3012,  3013,  3014,  3015,  3020,  3024,  3028,  3032,  3039,
    3042,  3047,  3048,  3049,  3051,  3057,  3067,  3071,  3075,  3079,
    3083,  3087,  3091,  3095,  3103,  3113,  3118,  3122,  3126,  3130,
    3134,  3139,  3143,  3147,  3155,  3158,  3163,  3164,  3165,  3170,
    3171,  3172,  3180,  3183,  3188,  3189,  3193,  3194,  3199,  3223,
    3240,  3241,  3245,  3252,  3258,  3268,  3270,  3273,  3274,  3275,
    3276,  3278,  3281,  3285,  3290,  3294,  3300,  3301,  3304,  3309,
    3310,  3313,  3314,  3315,  3325,  3326,  3327,  3328,  3329,  3330,
    3331,  3332,  3336,  3342,  3344,  3363,  3371,  3378,  3379,  3380,
    3381,  3386,  3387,  3388,  3389,  3390,  3395,  3396,  3412,  3413,
    3414,  3415,  3416,  3417,  3418,  3419,  3420,  3421,  3423,  3424,
    3425,  3426,  3431,  3434,  3443,  3444,  3445,  3446,  3447,  3448,
    3452,  3453
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
  "DEFAULT_USER", "EXIT_TODO", "CONTINUE_TODO", "UNLOCK_TABLE",
  "ROLLBACK_W", "SQLSEON", "SQLSEOFF", "CREATE_VIEW", "DELETE_FROM",
  "EXTENT_SIZE", "FOREIGN_KEY", "INSERT_INTO", "IS_NOT_NULL",
  "NOT_MATCHES", "PRIMARY_KEY", "WITH_NO_LOG", "INSHARE", "BEGIN_WORK",
  "DROP_INDEX", "FOR_UPDATE_OF", "FOR_UPDATE", "LOCK_TABLE", "NOT_EXISTS",
  "REFERENCES", "RENCOL", "SMALLFLOAT", "COMMIT_W", "RENTAB", "KW_CHAR",
  "NCHAR", "NVARCHAR", "DELIMITER", "DROP_VIEW", "EXCLUSIVE",
  "GREATER_THAN_EQ", "INTO_TEMP", "DATABASE", "DATETIME", "DISTINCT",
  "FRACTION", "GROUP_BY", "INTERVAL", "NOT_LIKE", "NOT_ILIKE", "NOT_NULL",
  "RESOURCE", "SMALLINT", "IS_NULL", "LESS_THAN_EQ", "BETWEEN",
  "CLOSE_BRACKET", "CONNECT", "KW_CURRENT", "KW_DECIMAL", "DEFAULT",
  "INTEGER", "SERIAL8", "MATCHES", "VARCHAR", "CLOSE_SQUARE",
  "GREATER_THAN", "KW_FALSE", "NOT_IN", "OPEN_BRACKET", "KW_DELETE",
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
  "FILLFACTOR", "TIME", "KW_TODAY", "KW_ROWID", "TIMESTAMP",
  "SET_TEXT_FORMAT", "KW_TAG", "LINTMODULEISLIBRARY", "KW_PUBLIC",
  "KW_PRIVATE", "COPYBACK", "REFERENCES_BLOBTYPE_DEFAULT_NULL",
  "REFERENCES_BLOBTYPE", "SORT", "KWPIPE", "KW_DONE", "END_TODO",
  "KW_TODO", "KW_ALWAYS", "PROGRAM_TIMEOUT", "$accept",
  "update_statement_c", "where_upd_p", "where_del_p", "set_clause_list_uc",
  "upd_columns_uc", "upd_column_name", "upd_column_name_specific",
  "col_1_up", "upd_col_list_sl", "upd_val_list_slil", "upd_val_sli",
  "drops_statement", "drops_c", "create_statement_ss", "create_c_2_ss",
  "opt_cr_table_extra", "cr_table_extra", "cr_table_extra_entry",
  "space_name", "op_cr_index_extra", "cr_index_extra",
  "cr_index_extra_entry", "cr_table_name", "create_c_1", "op_no_log",
  "op_no_log_i", "idx_column_list", "idx_column", "table_element_list_ss",
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
       0,   256,  2240,  2241,  2242,  2243,  2244,  2245,  2246,  2247,
    2248,  2249,  2250,  2251,  2252,  2253,  2254,  2255,  2256,  2257,
    2258,  2259,  1001,  1002,  1003,  1004,  1005,  1007,  1008,  1013,
    1014,  1015,  1017,  1018,  1020,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1032,  1036,  1039,  1055,  1056,  1075,  1078,  1080,
    1081,  1084,  1085,  1086,  1087,  1100,  1101,  1102,  1103,  1117,
    1119,  1120,  1121,  1125,  1132,  1133,  1134,  1171,  1172,  1173,
    1174,  1175,  1178,  1179,  1181,  1182,  1183,  1184,  1187,  1188,
    1195,  1196,  1216,  1217,  1218,  1225,  1226,  1227,  1228,  1229,
    1230,  1235,  1236,  1238,  1239,  1240,  1241,  1251,  1257,  1258,
    1259,  1260,  1261,  1272,  1273,  1281,  1282,  1283,  1289,  1297,
    1304,  1306,  1310,  1311,  1313,  1318,  1344,  1345,  1346,  1347,
    1354,  1355,  1362,  1370,  1372,  1373,  1377,  1378,  1385,  1386,
    1389,  1391,  1394,  1400,  1407,  1410,  1416,  1421,  1427,  1428,
    1433,  1435,  1437,  1438,  1440,  1451,  1458,  1461,  1462,  1463,
    1465,  1467,  1470,  1474,  1476,  1500,  1501,  1503,  1510,  1512,
    1513,  1515,  1516,  1517,  1523,  1524,  1530,  1531,  1533,  1536,
    1539,  1540,  1542,  1544,  1552,  1554,  1557,  1570,  1573,  1574,
    1575,  1576,  1578,  1586,  1589,  1590,  1591,  1595,  1597,  1601,
    1602,  1604,  1605,  1607,  1611,  1614,  1616,  1620,  1624,  1625,
    1628,  1630,  1631,  1634,  1635,  1637,  1643,  1647,  1652,  1653,
    1656,  1659,  1662,  1664,  1665,  1667,  1668,  1669,  1678,  1681,
    1688,  1690,  1692,  1693,  1694,  1697,  1698,  1702,  1708,  1709,
    1712,  1721,  1726,  1730,  1731,  1732,  1734,  1737,  1738,  1740,
    1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,
    1754,  1759,  1760,  1761,  1762,  1763,  1770,  1773,  1774,  1780,
    1782,  1783,  1786,  1788,  1789,  1790,  1828,  1832,  1839,  1840,
    1843,  1848,  1855,  1856,  2204,  2216,  2226,  2227,  2228,  2229,
    2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   290,   291,   292,   292,   292,   293,   293,   293,   294,
     294,   294,   294,   294,   294,   295,   295,   296,   296,   297,
     297,   297,   297,   298,   299,   299,   300,   300,   301,   301,
     302,   303,   303,   303,   303,   304,   304,   305,   305,   306,
     306,   307,   307,   308,   308,   308,   308,   308,   309,   310,
     310,   311,   311,   312,   312,   312,   312,   313,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     315,   315,   316,   316,   317,   317,   318,   318,   318,   319,
     319,   320,   320,   321,   321,   321,   322,   322,   323,   323,
     323,   323,   323,   323,   323,   324,   324,   325,   325,   326,
     326,   327,   327,   328,   328,   329,   330,   330,   331,   331,
     332,   333,   333,   334,   335,   335,   336,   336,   337,   337,
     338,   338,   339,   339,   340,   341,   343,   342,   345,   344,
     344,   346,   346,   347,   347,   348,   348,   349,   349,   350,
     350,   351,   352,   353,   354,   354,   355,   356,   356,   356,
     356,   356,   356,   356,   357,   357,   357,   358,   358,   358,
     358,   358,   358,   358,   359,   359,   359,   359,   360,   360,
     360,   361,   361,   361,   362,   362,   362,   363,   363,   364,
     364,   364,   364,   364,   364,   365,   365,   366,   366,   367,
     367,   368,   368,   369,   370,   370,   371,   371,   372,   372,
     373,   374,   375,   376,   377,   377,   378,   378,   379,   379,
     379,   380,   380,   381,   381,   381,   382,   382,   382,   382,
     383,   384,   384,   385,   385,   386,   386,   387,   388,   388,
     388,   388,   388,   388,   388,   389,   390,   391,   392,   392,
     393,   393,   394,   395,   396,   397,   397,   397,   397,   397,
     397,   398,   398,   399,   399,   399,   400,   400,   401,   401,
     402,   402,   402,   402,   403,   403,   404,   404,   405,   405,
     406,   406,   407,   407,   408,   408,   409,   409,   410,   410,
     411,   412,   413,   413,   414,   414,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   415,   415,   415,   415,
     415,   415,   416,   416,   416,   416,   417,   417,   417,   417,
     418,   418,   418,   418,   419,   420,   420,   420,   421,   421,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   423,   423,   424,
     424,   424,   424,   424,   425,   426,   427,   428,   428,   429,
     429,   429,   430,   430,   431,   431,   432,   432,   432,   432,
     433,   433,   433,   433,   434,   435,   435,   435,   435,   436,
     436,   437,   437,   437,   437,   437,   437,   437,   438,   438,
     438,   438,   438,   438,   438,   438,   439,   439,   439,   440,
     440,   441,   442,   443,   444,   445,   445,   446,   446,   447,
     448,   448,   448,   449,   450,   451,   452,   452,   453,   454,
     454,   455,   455,   455,   456,   457,   457,   458,   458,   459,
     460,   461,   461,   461,   461,   463,   464,   462,   465,   466,
     466,   467,   467,   467,   467,   468,   469,   470,   471,   471,
     472,   472,   472,   472,   473,   474,   474,   475,   475,   475,
     476,   476,   476,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   478,   478,   479,
     479,   480,   480,   481,   481,   481,   482,   482,   482,   483,
     483,   483,   483,   483,   483,   484,   484,   484,   484,   485,
     485,   486,   486,   486,   486,   487,   488,   488,   488,   488,
     488,   488,   488,   488,   489,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   491,   491,   491,   491,   491,   491,
     491,   491,   492,   493,   494,   494,   495,   495,   496,   497,
     498,   498,   499,   499,   499,   500,   500,   500,   500,   500,
     500,   500,   500,   501,   502,   503,   504,   504,   504,   505,
     505,   506,   506,   506,   507,   507,   507,   507,   507,   507,
     507,   507,   508,   508,   508,   509,   510,   511,   511,   511,
     511,   512,   512,   512,   512,   512,   513,   513,   514,   514,
     514,   514,   514,   514,   514,   514,   514,   514,   514,   514,
     514,   514,   515,   515,   516,   516,   516,   516,   516,   516,
     517,   517
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
#define YYPACT_NINF -884
static const yytype_int16 yypact[] =
{
    2060,  -884,  -884,  -884,   151,  -884,   299,   151,   151,   299,
     299,   151,   771,   151,   151,   299,   771,   771,   771,   771,
    -884,   778,  -884,   151,  -884,  -884,   299,  -884,   244,   299,
     299,  -884,   299,   299,  -884,  -884,  -884,   299,   299,  -884,
    -884,   771,   299,   788,  -884,   151,   299,   848,   420,    46,
     299,   420,  -884,  -884,  -884,  -884,  -884,  -884,  -884,  -884,
    -884,  -884,  -884,  -884,  -884,  -884,  -884,  -884,  -884,  -884,
    -884,  -884,  -884,  -884,  -884,  -884,  -884,   323,  -884,  -884,
    -884,   276,  -884,  -884,  -884,   216,    66,  -884,  -884,   399,
    -884,  -884,  -884,   113,   408,    80,   123,   416,  -884,  -884,
    -884,  -884,  -884,   119,   157,   162,   165,  -884,    47,  -884,
    -884,  -884,  -884,   253,  -884,  -884,   226,  -884,   262,  -884,
     298,    29,   299,  -884,   177,   238,   248,  -884,   448,   251,
    -884,  -884,  -884,  -884,   365,  -884,  -884,  -884,  -884,  -884,
     347,   347,  -884,  -884,  -884,  -884,   311,   285,   321,  -884,
     599,   -24,   404,   318,   392,  -884,  2060,   854,  -884,  -884,
     611,   151,   864,   151,   151,   634,   524,    68,   665,  -884,
    -884,   288,   100,   297,   428,  -884,  -884,  -884,  -884,  -884,
    -884,  -884,  -884,   151,  -884,  -884,   887,   151,   299,   299,
     299,   299,    47,  -884,   300,   299,   300,    74,   433,   689,
     975,  -884,   517,  -884,  -884,  -884,   151,   151,   898,   151,
     151,  -884,  -884,    74,  -884,  -884,   116,   299,   698,  -884,
    -884,  -884,  -884,  -884,  1234,  1234,  1234,  1234,    58,    58,
      30,   116,   299,  -884,   446,   450,   465,  -884,   672,  -884,
     473,  -884,   482,  -884,  -884,   555,   560,   563,   525,   568,
     573,  -884,  -884,  -884,   679,   151,   516,  -884,  -884,  -884,
     300,  -884,  -884,  -884,  -884,   467,   151,  -884,  -884,   300,
     493,  -884,   408,  -884,   515,  -884,   533,   607,  -884,   615,
     620,   623,  -884,   -18,  -884,  -884,     8,   788,    38,  -884,
    -884,   553,   220,   626,  -884,  -884,  -884,   639,   574,  -884,
    -884,   833,   658,   666,  -884,  -884,  -884,   669,   512,  -884,
     712,   669,   681,  -884,   682,   685,  -884,    82,   693,   669,
    -884,   694,   700,   669,   669,   708,   713,   725,   726,  1832,
    1073,   730,  1832,   921,  -884,  -884,  -884,   661,   697,  -884,
    -884,  -884,  -884,  -884,  -884,  -884,   512,  -884,   512,  -884,
    -884,   604,  -884,  -884,     6,  -884,  -884,  -884,  -884,   351,
     838,   151,   363,  -884,   675,  -884,   687,  -884,   705,  -884,
      42,  -884,  -884,   696,  -884,  -884,   719,  -884,  1688,  1332,
    -884,    53,  -884,  -884,    83,   707,   707,   151,  -884,  -884,
     106,     7,   711,   761,  -884,   689,   975,  -884,   696,   701,
     151,   151,   854,  -884,   151,   911,    74,    74,    74,   133,
     679,    74,   975,   151,  -884,   175,   151,   239,  -884,  -884,
    -884,   777,   779,   780,   512,   512,  -884,   790,  -884,   792,
     793,   794,   795,   798,  -884,  -884,  -884,  -884,   800,   804,
     585,  -884,  -884,  -884,  -884,  -884,   258,  -884,  -884,   273,
     151,  -884,   151,   926,   151,   151,   151,   151,   853,   300,
     194,  -884,  -884,    74,    79,   985,   151,  -884,    46,   884,
    -884,  1461,   151,   970,  1688,  1688,   799,  -884,  -884,  -884,
    -884,  -884,  -884,  -884,  -884,  -884,   731,    46,   -26,   879,
    -884,  1688,    31,  1688,  1688,   975,   484,  -884,  1688,  -884,
    1688,  1688,  -884,  -884,    31,  1688,    31,    31,   351,  -884,
      31,   351,  -884,   975,   975,   733,   -12,  1832,  -884,  1832,
    1832,  -884,  1832,  -884,   817,  1545,  -884,  -884,  1832,  -884,
     818,  -884,  1832,   586,  1688,    76,    48,  1688,  -884,  -884,
    -884,  -884,  -884,  -884,  1688,  1688,  1688,  1688,  -884,   467,
     278,  -884,   740,  -884,  -884,  -884,   151,   151,   932,  -884,
      74,   116,   116,   755,  -884,  -884,    20,   835,  -884,  1234,
    -884,  -884,   814,    58,    92,  -884,    58,  1234,  -884,   661,
     116,   745,  -884,  -884,  -884,   746,  -884,   839,   762,  -884,
     289,  -884,   292,  -884,   525,  -884,   295,   661,   841,  -884,
    -884,  -884,  -884,   300,  1009,  1009,  1010,   749,    16,  1012,
    1013,  1014,  1015,  1012,  1012,  1020,  1024,  -884,  -884,  -884,
     124,  -884,   380,  -884,   151,  -884,   300,  -884,  -884,   767,
    -884,   316,  -884,   148,   332,   335,   341,  -884,   194,  -884,
    1026,  -884,  -884,  1030,  1031,  -884,   194,  -884,  -884,  -884,
     843,    17,   773,   -24,  -884,  -884,  -884,  -884,   345,   776,
    -884,   349,   350,   550,   -24,  -884,  -884,   449,   870,   437,
    -884,  -884,  -884,  1688,   354,  -884,   -54,  -884,  -884,   377,
     381,   382,  1688,   402,  1688,  1688,  1688,   697,  -884,   550,
    1040,   550,   860,   351,   863,   865,   860,    95,  -884,  -884,
    -884,   863,    95,  -884,   865,  -884,  -884,  1688,  -884,  -884,
      76,  -884,  -884,   287,  1047,  -884,  -884,    23,  -884,  -884,
    -884,  -884,  -884,  -884,  -884,   151,   151,   869,  -884,  -884,
     791,  -884,  -884,  -884,   696,  1688,  -884,   151,  -884,  -884,
     872,  -884,  -884,    26,  -884,  -884,    50,   151,   151,   917,
      74,  -884,    74,  -884,   679,  -884,  -884,  -884,  -884,   894,
     895,   412,   550,  1062,   550,  -884,   819,   903,   424,   909,
     912,   819,   913,   914,  -884,  -884,  -884,  -884,   299,  -884,
    -884,  -884,   885,  -884,  -884,   380,  -884,   679,  -884,  -884,
     151,    62,   151,  -884,  -884,    62,    62,    62,   853,  -884,
    -884,  -884,  -884,  -884,  -884,  -884,  1070,   151,  1688,  -884,
    1688,   151,  -884,  -884,   902,  -884,  -884,  -884,  -884,  -884,
    -884,  -884,  1688,   512,   815,  -884,  -884,  -884,   916,  -884,
    1688,  -884,  -884,  -884,   918,  -884,   920,   923,   925,  -884,
     927,  -884,   124,  -884,   124,  -884,   124,  -884,  -884,    94,
    -884,   431,  -884,  -884,  -884,   436,  -884,   844,   254,  -884,
    -884,  -884,    76,  -884,  -884,  -884,    76,  -884,    76,   151,
    -884,  -884,  1605,   151,  -884,   868,  -884,  1234,   151,  -884,
    -884,   778,  -884,  -884,  -884,  -884,  -884,  -884,  -884,  -884,
    -884,  -884,  1095,  -884,   930,  -884,  1097,   933,  -884,  -884,
    1098,  -884,  -884,   934,  -884,  -884,  -884,   922,   975,  -884,
    -884,  -884,  -884,  -884,  1031,  1102,  -884,    62,  -884,  -884,
    -884,  -884,  -884,  -884,   928,   843,   -66,  -884,   915,  1104,
     -66,   845,   550,  -884,  -884,  -884,  -884,  -884,  -884,   846,
    -884,  -884,  -884,  -884,  -884,  -884,  -884,    99,  -884,  1688,
    -884,   306,   589,   320,   919,  -884,   441,  -884,  -884,  -884,
     299,   460,   896,   443,   843,  -884,   944,   850,  -884,  -884,
    -884,   948,  -884,    74,   949,  -884,  -884,  -884,  -884,  -884,
    -884,    76,   950,   951,   550,  -884,   550,  -884,  -884,  -884,
    -884,    76,    76,  -884,  1605,    72,  -884,    61,    81,   975,
     975,  -884,    49,  -884,  -884,   937,    73,   174,  -884,  -884,
    -884,   550,  -884,   444,  -884,   591,  -884,  -884,  -884,  -884,
     575,   603,  -884,   143,   143,   144,   151,  -884,  -884,  -884,
      85,  -884,  -884,  -884,   878,  -884,   866,   580,   661,   661,
    -884,  -884,  -884,  -884,  -884,   935,   151,   871,   972,  -884,
    -884,  -884,  -884,    76,  -884,  -884,    76,   299,    72,   867,
     873,   168,  -884,  -884,  -884,    81,    96,  -884,    46,  -884,
     998,  -884,    89,   151,   631,   647,    90,   975,   975,   299,
    -884,  -884,  -884,   843,   -24,  -884,  -884,  -884,  -884,   888,
    -884,   149,   998,  -884,  -884,  -884,   661,   661,   130,  -884,
    1688,    89,  -884,  -884,  -884,  -884,  -884,   -66,  -884,   896,
    -884
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -884,  -884,  -884,  -884,  -884,  -884,  -168,   750,   562,  -884,
    -182,  -415,  -884,  -884,  -884,  -884,   501,  -884,   494,   228,
    -160,  -884,   227,   621,  -884,   352,    57,   375,   353,   955,
    -133,  -884,  -884,   880,  -884,  -242,  -884,  -884,  -884,  -243,
    -884,  -884,  -209,  -884,  -884,  -884,  -884,  -355,  -884,   901,
     737,  -884,  -884,  -884,  -884,  -884,  -884,  -884,   434,  -884,
     164,  -884,  -884,  -884,  -884,  -884,  -884,  -884,  -884,  -884,
    1111,  -884,  1112,  -884,   946,  1025,  -884,  -156,   606,  -884,
    -884,  -884,  -884,  -884,  -884,   419,  -884,  -884,   192,  -884,
    -137,  -131,  -884,  -884,  -884,  -884,  -884,   384,  -884,  -884,
    -884,  -884,  -884,    34,   166,  -884,  -884,  -834,   146,  -860,
    -801,  -884,   170,  -199,   660,   662,   847,  -884,   478,   471,
     477,   409,  -255,  -884,  -884,  -884,  -884,   313,  -884,   632,
    -884,  -884,  -884,   414,  -884,   578,  -118,  -884,    -1,  -370,
    -165,  -883,   150,   897,   160,  -556,  -884,  -290,  -568,  -884,
    -884,   977,   635,  -884,  -884,  -884,  -884,  -884,  -884,  -884,
    -884,  -884,  -884,    87,  -884,  -884,  -884,  -884,   127,   286,
    -884,  -884,  -884,  -884,  -884,  -884,    84,  -884,   122,   836,
    -179,  -438,  -617,  -751,  -884,   464,  -158,  -884,  -884,   704,
     413,   532,  -884,  -884,  -884,   500,   256,   -27,  -884,    44,
    -884,   904,    -4,   809,   356,  -884,  -884,  -884,  -884,  -884,
    1050,  -884,  1194,  -884,  -884,  -884,   807,  -884,  -460,  -884,
    -884,  -622,  -884,  -884,  -884,  -154,  -884,  -884
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
     113,   930,    84,   116,   117,   398,   118,   119,    84,   709,
     125,   120,   121,    84,  1029,    84,   124,   125,   858,    84,
     131,   125,  1087,    84,   152,   125,    84,   944,   296,    84,
      84,   298,   296,    84,    84,   298,  1023,   912,   913,   299,
     299,   488,   300,  1024,   299,   301,   300,   410,    89,   301,
      84,   839,   107,   841,  1023,   980,   995,   296,   477,   983,
     774,  1024,   490,   220,   607,   608,   270,   199,   395,   299,
     499,   850,   193,   665,   502,   503,   850,    84,    84,    86,
      86,   458,   489,   235,   739,    84,   880,   239,   241,   242,
     243,   960,   745,   258,  1023,  1062,   202,   265,   268,   265,
     690,  1024,    84,    37,    86,   508,   221,   460,   511,   273,
     830,   735,   275,   276,    89,    89,    89,    89,   670,  1088,
     265,    89,   265,   292,   893,   805,   895,   579,   763,   535,
     465,  1080,   363,   365,   367,   368,   130,   462,   998,   292,
     513,   559,   111,    89,   184,   185,   868,   222,  1088,   465,
     566,   567,   568,  1076,   391,   391,   282,   111,    89,   459,
    1042,   671,   278,   278,   278,   278,   999,   853,   513,   285,
     951,   589,   853,    48,   952,  1098,   953,   114,   200,   396,
     255,   258,   570,   691,   150,   459,   265,    51,   710,  1095,
     640,   376,   268,   715,   806,   265,   308,   536,   574,   160,
     308,   592,   672,  1043,   596,   572,   399,   641,   642,   737,
     804,   764,   266,   292,   869,   463,   941,   878,   941,   560,
     941,   203,    84,   487,   649,   308,   676,   561,   648,  1106,
     569,    84,   593,    84,    84,    86,  1109,   742,   494,   881,
     372,  1082,   204,   657,  1044,   387,   657,   657,   495,  1025,
    1026,   716,   643,   155,   914,  1057,   639,   161,  1046,   711,
     569,   287,   915,   667,   712,   657,   675,  1025,  1030,   156,
     657,   183,   657,   657,   600,   698,  1030,   657,   849,  1107,
    1079,   703,   849,   573,  1031,   333,   333,   552,  1031,  1015,
     333,  1061,  1031,   693,   985,   693,   693,   700,   693,  1020,
    1021,   793,  1102,   879,   693,   165,   708,  1025,   693,   718,
     594,   788,   188,   391,   789,   333,   719,   720,   721,   722,
    1047,   850,   794,  1103,   757,   732,   581,   582,   235,   888,
     584,   586,   292,   292,   292,   741,   734,   292,   602,   599,
     537,   383,   258,   465,   157,   158,  1018,   245,  1019,   383,
     189,   246,   416,   950,   746,   190,   245,   623,   191,   245,
     246,  1074,   910,   246,  1075,   194,   538,   539,   540,   541,
     542,   543,   625,  1050,   196,   247,   627,   724,   628,   630,
     633,   633,   633,   633,   247,   265,   644,   247,   751,   292,
     650,   753,   652,   754,   755,   859,   208,  1100,   659,   860,
     260,   224,   225,   226,   227,   228,   195,   209,   861,   269,
     197,   466,   166,   167,   989,   791,   603,   853,   249,   776,
     168,   169,   170,   270,   250,   770,   771,   249,   990,   206,
     249,   795,   860,   250,   796,   624,   250,   863,   864,   207,
     797,   861,   865,   777,   809,   828,   210,   211,   812,   813,
     626,   860,   778,   829,   834,   725,   836,   837,   838,   213,
     861,   135,   717,   931,   862,   860,   752,   779,   216,   752,
     863,   864,   752,   780,   861,   865,   831,   419,   217,   857,
     832,   833,   365,   729,   731,   979,   292,   111,   111,   863,
     864,   468,   738,   792,   865,   553,   544,   991,   218,   391,
     743,   835,   391,   863,   864,   545,   111,   566,   865,   792,
     781,   891,   792,   231,   136,   886,   782,   887,   792,   942,
     137,   943,   810,   899,  1009,   478,   810,   810,   171,   265,
     946,   810,   219,   138,   546,   948,  -503,   478,   139,   547,
     993,   420,  1008,  1051,   421,   422,   423,   238,   140,   998,
     268,   141,   265,   424,   810,   142,   479,   425,   810,   810,
    1084,   143,   426,   172,   480,   920,   921,   922,   479,   427,
     244,   428,   429,   229,   430,   162,   480,   999,   173,   810,
     566,   481,   927,   245,   245,   232,   163,   246,   246,   892,
     164,   144,   186,   481,   566,   482,   431,  1067,   259,   145,
     478,   900,   934,   187,   483,   272,   432,   482,   947,  1000,
     433,   247,   247,   947,   823,   484,   483,   434,   994,   435,
     569,   750,   293,   294,   208,   963,   823,   484,   436,   361,
     437,   479,   617,   618,   619,   209,   248,   400,   814,   480,
     494,   401,   402,  1099,   958,   296,   297,   705,   298,   383,
     495,   552,   871,   403,   249,   249,   481,   299,   405,   300,
     250,   250,   301,   876,   404,  -282,   517,   406,   438,   815,
     482,   439,   407,   883,   884,   408,   292,   816,   292,   483,
     411,   677,   706,  1054,   707,   412,   413,   518,   620,   450,
     484,   302,   303,   416,   817,   519,   520,   304,   305,  1052,
    -282,   521,  -282,   465,    89,    84,   452,    95,   818,   453,
     522,  1055,    84,   523,   107,   524,   911,   819,   633,   454,
     860,   988,    84,   306,   125,   525,   526,   455,   820,   861,
    1038,  1039,   456,   925,   860,   457,   860,   928,   589,  1093,
     279,   280,   281,   861,   464,   861,   527,   682,   860,   684,
     685,   471,   907,   686,   468,  1094,   208,   861,   863,   864,
     634,   635,   636,   865,   528,   472,   958,   209,  1053,   473,
     474,  -528,   863,   864,   863,   864,   860,   865,   475,   865,
    1056,   476,   132,   307,   133,   861,   863,   864,    84,   529,
     234,   865,   860,   491,   492,   954,   530,   493,    84,   959,
     240,   861,   531,   532,   964,   498,   500,   111,  1096,  1097,
     965,   138,   501,   308,   863,   864,   139,   661,   662,   865,
     504,    84,   309,   274,   310,   505,   140,   311,   312,   141,
     863,   864,    84,   142,   366,   865,   674,   506,   507,   143,
     487,   679,   510,   680,   681,    84,   313,   585,   683,   314,
     103,   104,   105,   106,   512,   513,   315,   316,   694,   695,
      84,   696,   629,   317,   318,   549,    84,   701,   730,   514,
     556,   704,   566,   561,   319,   123,   562,   320,   557,   321,
     322,   558,   577,   323,   569,   324,    89,   325,   576,   604,
     326,   605,   606,   327,   328,   329,   580,   330,   331,   292,
     332,  1036,   609,   333,   610,   611,   612,   613,   296,   297,
     614,   298,   615,   334,   335,   336,   616,   637,   651,   654,
     299,   660,   300,  1028,  1037,   301,   663,   487,   689,   697,
     702,   726,   735,  1036,   666,   740,   747,   748,   749,   750,
     756,   517,   758,   761,   762,   765,   767,   768,   769,    89,
      89,    89,  1028,   772,   302,   303,  1037,   773,   790,   799,
     304,   305,   518,   800,   807,   801,   465,   811,  1036,   826,
     519,   520,  1071,   840,   842,  1036,   521,   844,   666,   846,
     867,   872,   873,    89,   877,   522,   306,    89,   523,   778,
     524,  1037,  1083,   889,   890,   894,   896,   908,  1037,  1071,
     525,   526,   898,   924,  1036,    89,   296,   297,   901,   298,
     932,   902,   904,   905,   929,   933,   949,   935,   299,   936,
     300,   527,   937,   301,   938,   960,   939,  1037,   966,   967,
     968,   971,   970,   972,   973,   976,   978,   982,   981,   528,
     984,   986,   992,  1010,  1006,  1011,   307,  1012,  1014,  1016,
    1017,  -305,   302,   303,   999,  1065,  1073,  1066,   304,   305,
    1077,  1072,  1085,  1068,   529,  1101,  1078,   571,   744,   798,
     803,   530,   975,  -305,   977,   919,   308,   531,   532,  1105,
     923,   286,   451,   601,   306,   309,   415,   310,  1022,   870,
     311,   312,   153,   154,   377,  1013,   215,   733,   885,   909,
    1060,  1041,  1040,   687,   848,   856,   688,   509,   854,   313,
    1064,   723,   314,   760,   461,   903,  1063,   369,  1108,   315,
     316,   728,  1081,  1110,   974,  1092,   317,   318,   555,   874,
     678,   827,   855,   987,   578,   945,   233,   319,   101,   583,
     320,     0,   321,   322,   307,     0,   323,     0,   324,     0,
     325,     0,     0,   326,     0,     0,   327,   328,   329,     0,
     330,   331,     0,   332,     0,     0,   333,   296,   297,     0,
     298,     0,     0,     0,   308,     0,   334,   335,   336,   299,
       0,   300,     0,   309,   301,   310,     0,     0,   311,   312,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,     0,
     314,     0,     0,   302,   303,     0,     0,   315,   316,   304,
     305,     0,     0,     0,   317,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,     0,   320,     0,
     321,   322,     0,     0,   323,   306,   324,     0,   325,     0,
       0,   326,     0,     0,   327,   328,   329,     0,     0,   331,
       0,   332,     0,     0,   333,   296,   297,     0,   298,     0,
       0,     0,     0,     0,   334,   335,   336,   299,     0,   300,
       0,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,   303,     0,     0,     0,     0,   304,   305,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,     0,   306,   309,     0,   379,     0,     0,     0,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   380,   313,     0,
       0,   314,     0,     0,     0,     0,     0,     0,   315,   316,
       0,     0,     0,     0,     0,   317,   318,     0,     0,     0,
       0,     0,     0,     0,   296,   297,   319,   298,     0,   320,
       0,   321,   322,     0,     0,   323,   299,   324,   300,   325,
       0,   301,   326,     0,     0,   327,   328,   329,     0,     0,
     331,     0,   332,     0,     0,   333,     0,     0,     0,     0,
       0,     0,     0,   308,     0,   334,   335,   336,     0,     0,
     302,   303,   309,     0,   379,     0,   304,   305,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,     0,     0,   313,     0,     0,   314,
       0,     0,   306,     0,     0,     0,   315,   316,   296,   297,
       0,   298,     0,   317,   318,     0,     0,     0,     0,     0,
     299,     0,   300,     0,   319,   301,     0,   320,     0,   321,
     322,     0,     0,   323,     0,   324,     0,   325,     0,     0,
     326,     0,     0,   327,   328,   329,     0,     0,   331,     0,
     332,     0,     0,   333,   302,   303,     0,     0,     0,     0,
     304,   305,     0,   334,   335,   336,     0,     0,   296,   297,
       0,   298,     0,     0,     0,     0,     0,     0,     0,     0,
     299,     0,   300,     0,     0,   301,   306,     0,     0,     0,
     656,     0,   308,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,   379,     0,     0,     0,   312,     0,     0,
       0,     0,     0,     0,   302,   303,     0,     0,     0,     0,
     304,   305,     0,     0,     0,   313,     0,     0,   314,     0,
       0,     0,     0,     0,     0,   315,   316,     0,     0,     0,
       0,     0,   317,   318,     0,     0,   306,     0,     0,     0,
       0,   296,   297,   319,   298,     0,   320,     0,   321,   322,
       0,     0,   323,   299,   324,   300,   325,     0,   301,   326,
       0,     0,   327,   328,   329,     0,   308,   331,     0,   332,
       0,     0,   333,     0,     0,   309,     0,   379,     0,     0,
       0,   312,   334,   335,   336,     0,     0,   302,   303,     0,
       0,     0,     0,   304,   305,     0,     0,     0,   699,   313,
       0,     0,   314,     0,     0,     0,     0,     0,     0,   315,
     316,     0,     0,     0,     0,     0,   317,   318,     0,   306,
       0,     0,     0,     0,     0,     0,   308,   319,     0,     0,
     320,     0,   321,   322,     0,   309,   323,   379,   324,     0,
     325,   312,     0,   326,     0,     0,   327,   328,   329,     0,
       0,   331,     0,   332,     0,     0,   333,     0,   955,   313,
       0,     0,   314,     0,     0,     0,   334,   335,   336,   315,
     316,     0,     0,     0,     0,     0,   317,   318,     0,     0,
       0,     0,     0,     0,     0,   296,   297,   319,   298,     0,
     320,     0,   321,   322,     0,     0,   323,   299,   324,   300,
     325,     0,   301,   326,     0,     0,   327,   328,   329,   308,
       0,   331,     0,   332,     0,     0,   333,     0,   309,     0,
     379,     0,     0,     0,   312,     0,   334,   335,   336,     0,
       0,   302,   303,     0,     0,     0,     0,   304,   305,     0,
       0,     0,   313,     0,     0,   314,     0,     0,     0,     0,
       0,     0,   315,   316,     0,     0,     0,     0,     0,   317,
     318,     0,     0,   306,     0,     0,     0,     0,     0,     0,
     319,     0,     0,   320,     0,   321,   322,     0,     0,   323,
       0,   324,     0,   325,     0,     0,   326,     0,     0,   327,
     328,   329,     0,     0,   331,     0,   332,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
     335,   336,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,   379,     0,     0,     0,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   313,     0,     0,   314,
       0,     0,     0,     0,     0,     0,   315,   316,     0,     0,
       0,     0,     0,   317,   318,     0,     0,     0,     0,     0,
    -565,     1,     0,     0,   319,     0,     0,   320,     0,   321,
     322,     0,     0,   323,     0,   324,  -565,   325,     0,     0,
     326,     0,     0,   327,   328,     0,     0,     0,   331,     0,
       0,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,   335,   336,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     0,     0,     6,     7,     0,
       8,     9,    10,     0,    11,    12,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
      28,     0,    29,    30,     0,    31,    32,     0,     0,     0,
       0,     0,    33,    34,    35,    36,    37,    38,     0,     0,
      39,     0,     0,     0,     0,     0,    40,    41,     0,     0,
      42,     0,     0,    43,     0,    44,    45,     0,     0,     0,
       0,    46,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,     0,    49,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
      51
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
      26,   822,     4,    29,    30,   231,    32,    33,     4,     3,
       6,    37,    38,     4,     3,     4,    42,     6,   710,     4,
      46,     6,     3,     4,    50,     6,     4,     3,     3,     4,
       4,     6,     3,     4,     4,     6,    34,    45,    46,    15,
      15,   310,    17,    41,    15,    20,    17,   248,   122,    20,
       4,   689,     6,   691,    34,   926,   960,     3,   307,   930,
       6,    41,   311,   157,   424,   425,   269,   108,   108,    15,
     319,   697,   108,   169,   323,   324,   702,     4,     4,     6,
       6,   169,   310,   157,   569,     4,   106,   161,   162,   163,
     164,   227,   577,   167,    34,  1025,   122,   171,   172,   173,
     182,    41,     4,   126,     6,   329,   200,   169,   332,   183,
     234,   247,   186,   187,   188,   189,   190,   191,   157,  1072,
     194,   195,   196,   197,   762,   178,   764,   396,   182,   193,
     193,  1061,   206,   207,   208,   209,   210,   169,   159,   213,
     264,   169,   216,   217,    91,    92,   193,   241,  1101,   193,
     378,   379,   169,  1057,   228,   229,   192,   231,   232,   247,
     157,   200,   188,   189,   190,   191,   187,   697,   264,   195,
     862,   406,   702,   196,   866,  1079,   868,     3,   219,   219,
     182,   255,   169,   265,   208,   247,   260,   210,   182,   169,
      66,   217,   266,   215,   247,   269,   171,   261,   261,    53,
     171,   408,   241,   200,   411,   169,   232,    83,    84,   259,
     650,   265,   182,   287,   261,   247,   842,   261,   844,   247,
     846,   114,     4,   198,   215,   171,   495,   247,   463,   169,
     247,     4,   169,     4,     4,     6,  1107,   215,   226,   259,
     194,   215,   135,   471,   241,   257,   474,   475,   236,   247,
     259,   273,   128,     0,   262,   182,   459,   261,   154,   253,
     247,   257,   270,   491,   258,   493,   494,   247,   257,    16,
     498,   261,   500,   501,   169,   524,   257,   505,   253,  1100,
     182,   530,   253,   247,   273,   261,   261,   361,   273,   981,
     261,   217,   273,   517,   932,   519,   520,   525,   522,   991,
     992,   223,   223,   743,   528,   262,   534,   247,   532,   537,
     247,   624,   263,   387,   626,   261,   544,   545,   546,   547,
     216,   947,   244,   244,   603,   560,   400,   401,   402,   754,
     404,   405,   406,   407,   408,   573,   562,   411,   169,   413,
      59,   569,   416,   193,   138,   139,   984,   129,   986,   577,
     263,   133,   247,   169,   580,   263,   129,   169,   263,   129,
     133,  1053,   787,   133,  1056,   182,    85,    86,    87,    88,
      89,    90,   169,  1011,   182,   157,   450,   169,   452,   453,
     454,   455,   456,   457,   157,   459,   262,   157,   169,   463,
     464,   169,   466,   594,   169,   178,   246,  1084,   472,   215,
     182,    67,    68,    69,    70,    71,   250,   257,   224,   182,
     182,   261,    74,    75,   178,   169,   247,   947,   200,   109,
      82,    83,    84,   626,   206,   613,   614,   200,   178,   261,
     200,   169,   215,   206,   169,   247,   206,   253,   254,   261,
     169,   224,   258,   133,   169,   673,   265,   152,   169,   169,
     247,   215,   142,   169,   682,   247,   684,   685,   686,   182,
     224,   111,   536,   823,   247,   215,   247,   157,   227,   247,
     253,   254,   247,   163,   224,   258,   169,    80,   263,   707,
     169,   169,   556,   557,   558,   925,   560,   561,   562,   253,
     254,   198,   566,   247,   258,   202,   215,   247,   247,   573,
     574,   169,   576,   253,   254,   224,   580,   735,   258,   247,
     200,   169,   247,   265,   164,   750,   206,   752,   247,   844,
     170,   846,   247,   169,   964,   158,   247,   247,   190,   603,
     169,   247,     3,   183,   253,   169,   169,   158,   188,   258,
     169,   144,   169,   169,   147,   148,   149,     6,   198,   159,
     624,   201,   626,   156,   247,   205,   189,   160,   247,   247,
    1068,   211,   165,   225,   197,   795,   796,   797,   189,   172,
       6,   174,   175,   239,   177,   246,   197,   187,   240,   247,
     808,   214,   810,   129,   129,   263,   257,   133,   133,   247,
     261,   241,   246,   214,   822,   228,   199,  1037,     3,   249,
     158,   247,   830,   257,   237,   247,   209,   228,   247,   219,
     213,   157,   157,   247,   247,   248,   237,   220,   247,   222,
     247,   247,   259,     4,   246,   877,   247,   248,   231,   182,
     233,   189,   117,   118,   119,   257,   182,   261,   158,   197,
     226,   261,   247,  1083,   872,     3,     4,   131,     6,   877,
     236,   725,   726,    51,   200,   200,   214,    15,   246,    17,
     206,   206,    20,   737,   261,   131,   132,   182,   271,   189,
     228,   274,   182,   747,   748,   182,   750,   197,   752,   237,
     182,   267,   166,   178,   168,   182,    77,   153,   173,   266,
     248,    49,    50,   247,   214,   161,   162,    55,    56,   178,
     166,   167,   168,   193,   778,     4,   261,     6,   228,   246,
     176,   178,     4,   179,     6,   181,   790,   237,   792,   182,
     215,   949,     4,    81,     6,   191,   192,   182,   248,   224,
     999,  1000,   182,   807,   215,   182,   215,   811,   973,   178,
     189,   190,   191,   224,   261,   224,   212,   504,   215,   506,
     507,   182,   778,   510,   198,   178,   246,   224,   253,   254,
     455,   456,   457,   258,   230,   261,   994,   257,   247,     6,
     182,   261,   253,   254,   253,   254,   215,   258,   182,   258,
     247,   182,     4,   141,     6,   224,   253,   254,     4,   255,
       6,   258,   215,   182,   182,   869,   262,   182,     4,   873,
       6,   224,   268,   269,   878,   182,   182,   881,  1077,  1078,
     881,   183,   182,   171,   253,   254,   188,   474,   475,   258,
     182,     4,   180,     6,   182,   182,   198,   185,   186,   201,
     253,   254,     4,   205,     6,   258,   493,   182,   182,   211,
     198,   498,   182,   500,   501,     4,   204,     6,   505,   207,
      16,    17,    18,    19,     3,   264,   214,   215,   519,   520,
       4,   522,     6,   221,   222,    97,     4,   528,     6,   242,
     265,   532,  1100,   247,   232,    41,   227,   235,   261,   237,
     238,   246,   191,   241,   247,   243,   960,   245,   247,   182,
     248,   182,   182,   251,   252,   253,   265,   255,   256,   973,
     258,   998,   182,   261,   182,   182,   182,   182,     3,     4,
     182,     6,   182,   271,   272,   273,   182,   134,     3,   105,
      15,    21,    17,   997,   998,    20,   265,   198,   265,   182,
     182,   261,   247,  1030,   169,   191,   261,   261,   169,   247,
     169,   132,     3,     3,   265,     3,     3,     3,     3,  1023,
    1024,  1025,  1026,     3,    49,    50,  1030,     3,   261,     3,
      55,    56,   153,     3,   261,     4,   193,   261,  1065,   169,
     161,   162,  1046,     3,   184,  1072,   167,   184,   169,   184,
       3,   182,   261,  1057,   182,   176,    81,  1061,   179,   142,
     181,  1065,  1066,   169,   169,     3,   247,   182,  1072,  1073,
     191,   192,   169,     3,  1101,  1079,     3,     4,   169,     6,
     265,   169,   169,   169,   182,   169,   242,   169,    15,   169,
      17,   212,   169,    20,   169,   227,   169,  1101,     3,   169,
       3,     3,   169,   169,   182,     3,   178,     3,   193,   230,
     265,   265,   193,   169,   218,   265,   141,   169,   169,   169,
     169,   242,    49,    50,   187,   247,   154,   261,    55,    56,
     263,   260,   134,   198,   255,   247,   263,   387,   576,   638,
     646,   262,   914,   264,   917,   792,   171,   268,   269,  1092,
     798,   196,   272,   416,    81,   180,   255,   182,   994,   725,
     185,   186,    51,    51,   218,   973,   141,   561,   749,   785,
    1024,  1005,  1002,   513,   696,   704,   514,   330,   701,   204,
    1030,   549,   207,   605,   287,   771,  1026,   210,  1101,   214,
     215,   556,  1065,  1109,   908,  1073,   221,   222,   362,   735,
     496,   669,   702,   947,   395,   849,   156,   232,    14,   402,
     235,    -1,   237,   238,   141,    -1,   241,    -1,   243,    -1,
     245,    -1,    -1,   248,    -1,    -1,   251,   252,   253,    -1,
     255,   256,    -1,   258,    -1,    -1,   261,     3,     4,    -1,
       6,    -1,    -1,    -1,   171,    -1,   271,   272,   273,    15,
      -1,    17,    -1,   180,    20,   182,    -1,    -1,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
     207,    -1,    -1,    49,    50,    -1,    -1,   214,   215,    55,
      56,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,    -1,   235,    -1,
     237,   238,    -1,    -1,   241,    81,   243,    -1,   245,    -1,
      -1,   248,    -1,    -1,   251,   252,   253,    -1,    -1,   256,
      -1,   258,    -1,    -1,   261,     3,     4,    -1,     6,    -1,
      -1,    -1,    -1,    -1,   271,   272,   273,    15,    -1,    17,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,   180,    -1,   182,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,   204,    -1,
      -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
      -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,   232,     6,    -1,   235,
      -1,   237,   238,    -1,    -1,   241,    15,   243,    17,   245,
      -1,    20,   248,    -1,    -1,   251,   252,   253,    -1,    -1,
     256,    -1,   258,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,    -1,   271,   272,   273,    -1,    -1,
      49,    50,   180,    -1,   182,    -1,    55,    56,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,   207,
      -1,    -1,    81,    -1,    -1,    -1,   214,   215,     3,     4,
      -1,     6,    -1,   221,   222,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,    -1,   232,    20,    -1,   235,    -1,   237,
     238,    -1,    -1,   241,    -1,   243,    -1,   245,    -1,    -1,
     248,    -1,    -1,   251,   252,   253,    -1,    -1,   256,    -1,
     258,    -1,    -1,   261,    49,    50,    -1,    -1,    -1,    -1,
      55,    56,    -1,   271,   272,   273,    -1,    -1,     3,     4,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,    -1,    -1,    20,    81,    -1,    -1,    -1,
     169,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,    -1,   182,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,   204,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,
      -1,    -1,   221,   222,    -1,    -1,    81,    -1,    -1,    -1,
      -1,     3,     4,   232,     6,    -1,   235,    -1,   237,   238,
      -1,    -1,   241,    15,   243,    17,   245,    -1,    20,   248,
      -1,    -1,   251,   252,   253,    -1,   171,   256,    -1,   258,
      -1,    -1,   261,    -1,    -1,   180,    -1,   182,    -1,    -1,
      -1,   186,   271,   272,   273,    -1,    -1,    49,    50,    -1,
      -1,    -1,    -1,    55,    56,    -1,    -1,    -1,   203,   204,
      -1,    -1,   207,    -1,    -1,    -1,    -1,    -1,    -1,   214,
     215,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,   171,   232,    -1,    -1,
     235,    -1,   237,   238,    -1,   180,   241,   182,   243,    -1,
     245,   186,    -1,   248,    -1,    -1,   251,   252,   253,    -1,
      -1,   256,    -1,   258,    -1,    -1,   261,    -1,   203,   204,
      -1,    -1,   207,    -1,    -1,    -1,   271,   272,   273,   214,
     215,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,   232,     6,    -1,
     235,    -1,   237,   238,    -1,    -1,   241,    15,   243,    17,
     245,    -1,    20,   248,    -1,    -1,   251,   252,   253,   171,
      -1,   256,    -1,   258,    -1,    -1,   261,    -1,   180,    -1,
     182,    -1,    -1,    -1,   186,    -1,   271,   272,   273,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,   204,    -1,    -1,   207,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   215,    -1,    -1,    -1,    -1,    -1,   221,
     222,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
     232,    -1,    -1,   235,    -1,   237,   238,    -1,    -1,   241,
      -1,   243,    -1,   245,    -1,    -1,   248,    -1,    -1,   251,
     252,   253,    -1,    -1,   256,    -1,   258,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,
     272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,    -1,   182,    -1,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,   207,
      -1,    -1,    -1,    -1,    -1,    -1,   214,   215,    -1,    -1,
      -1,    -1,    -1,   221,   222,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,   232,    -1,    -1,   235,    -1,   237,
     238,    -1,    -1,   241,    -1,   243,    16,   245,    -1,    -1,
     248,    -1,    -1,   251,   252,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,   272,   273,    -1,    47,    48,    -1,
      -1,    -1,    52,    -1,    54,    -1,    -1,    57,    58,    -1,
      60,    61,    62,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
     110,    -1,   112,   113,    -1,   115,   116,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,   136,   137,    -1,    -1,
     140,    -1,    -1,   143,    -1,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,    47,    48,    52,    54,    57,    58,    60,    61,
      62,    64,    65,    72,    73,    76,    93,    94,    95,    96,
      98,    99,   100,   101,   102,   103,   104,   107,   110,   112,
     113,   115,   116,   122,   123,   124,   125,   126,   127,   130,
     136,   137,   140,   143,   145,   146,   151,   155,   196,   198,
     201,   210,   291,   302,   303,   304,   305,   314,   321,   341,
     342,   351,   352,   353,   355,   356,   357,   358,   359,   369,
     389,   393,   439,   440,   443,   444,   462,   498,   499,   500,
     501,   503,   507,   509,     4,   492,     6,   489,   490,   492,
     492,   492,   489,   489,   492,     6,   491,   492,   492,   497,
     502,   502,   489,   491,   491,   491,   491,     6,   390,   391,
     428,   492,   492,   489,     3,   517,   489,   489,   489,   489,
     489,   489,   343,   491,   489,     6,   487,   488,   492,   441,
     492,   489,     4,     6,   495,   111,   164,   170,   183,   188,
     198,   201,   205,   211,   241,   249,   360,   362,   363,   364,
     208,   471,   489,   360,   362,     0,    16,   138,   139,   504,
      53,   261,   246,   257,   261,   262,    74,    75,    82,    83,
      84,   190,   225,   240,   322,   323,   324,   327,   330,   333,
     334,   335,   338,   261,    91,    92,   246,   257,   263,   263,
     263,   263,   392,   393,   182,   250,   182,   182,   370,   108,
     219,   293,   489,   114,   135,   445,   261,   261,   246,   257,
     265,   152,   354,   182,   365,   365,   227,   263,   247,     3,
     157,   200,   241,   472,    67,    68,    69,    70,    71,   239,
     294,   265,   263,   500,     6,   492,   505,   506,     6,   492,
       6,   492,   492,   492,     6,   129,   133,   157,   182,   200,
     206,   373,   374,   379,   381,   182,   339,   340,   492,     3,
     182,   320,   332,   381,   383,   492,   182,   329,   492,   182,
     320,   325,   247,   492,     6,   492,   492,   313,   489,   313,
     313,   313,   393,   319,   320,   489,   319,   257,   371,   430,
     433,   487,   492,   259,     4,   493,     3,     4,     6,    15,
      17,    20,    49,    50,    55,    56,    81,   141,   171,   180,
     182,   185,   186,   204,   207,   214,   215,   221,   222,   232,
     235,   237,   238,   241,   243,   245,   248,   251,   252,   253,
     255,   256,   258,   261,   271,   272,   273,   403,   404,   405,
     406,   407,   414,   416,   435,   446,   447,   448,   449,   450,
     470,   476,   477,   484,   492,   494,   508,   510,   514,   515,
     516,   182,   346,   492,   442,   492,     6,   492,   492,   441,
     366,   430,   194,   367,   368,   428,   489,   364,   463,   182,
     203,   300,   301,   476,   300,   300,   300,   257,   296,   297,
     299,   492,   295,   296,   298,   108,   219,   292,   367,   489,
     261,   261,   247,    51,   261,   246,   182,   182,   182,   336,
     381,   182,   182,    77,   337,   339,   247,   331,   332,    80,
     144,   147,   148,   149,   156,   160,   165,   172,   174,   175,
     177,   199,   209,   213,   220,   222,   231,   233,   271,   274,
     419,   420,   421,   422,   424,   461,   328,   329,   325,   326,
     266,   323,   261,   246,   182,   182,   182,   182,   169,   247,
     169,   433,   169,   247,   261,   193,   261,   429,   198,   460,
     469,   182,   261,     6,   182,   182,   182,   470,   158,   189,
     197,   214,   228,   237,   248,   436,   437,   198,   403,   476,
     470,   182,   182,   182,   226,   236,   478,   479,   182,   470,
     182,   182,   470,   470,   182,   182,   182,   182,   515,   406,
     182,   515,     3,   264,   242,   437,   437,   132,   153,   161,
     162,   167,   176,   179,   181,   191,   192,   212,   230,   255,
     262,   268,   269,   413,   415,   193,   261,    59,    85,    86,
      87,    88,    89,    90,   215,   224,   253,   258,   483,    97,
     347,   348,   492,   202,   344,   469,   265,   261,   246,   169,
     247,   247,   227,   473,   474,   475,   476,   476,   169,   247,
     169,   297,   169,   247,   261,   429,   247,   191,   493,   403,
     265,   492,   492,   506,   492,     6,   492,   376,   378,   430,
     380,   430,   380,   169,   247,   337,   380,   403,   459,   492,
     169,   340,   169,   247,   182,   182,   182,   437,   437,   182,
     182,   182,   182,   182,   182,   182,   182,   117,   118,   119,
     173,   382,   384,   169,   247,   169,   247,   492,   492,     6,
     492,   317,   318,   492,   317,   317,   317,   134,   315,   320,
      66,    83,    84,   128,   262,   306,   307,   308,   430,   215,
     492,     3,   492,   471,   105,   372,   169,   476,   480,   492,
      21,   480,   480,   265,   471,   169,   169,   476,   482,   508,
     157,   200,   241,   417,   480,   476,   403,   267,   479,   480,
     480,   480,   417,   480,   417,   417,   417,   404,   405,   265,
     182,   265,   411,   515,   411,   411,   411,   182,   470,   203,
     476,   411,   182,   470,   411,   131,   166,   168,   476,     3,
     182,   253,   258,   511,   513,   215,   273,   492,   476,   476,
     476,   476,   476,   419,   169,   247,   261,   345,   442,   492,
       6,   492,   430,   368,   367,   247,   464,   259,   492,   301,
     191,   296,   215,   492,   298,   301,   367,   261,   261,   169,
     247,   169,   247,   169,   381,   169,   169,   332,     3,   425,
     425,     3,   265,   182,   265,     3,   426,     3,     3,     3,
     426,   426,     3,     3,     6,   435,   109,   133,   142,   157,
     163,   200,   206,   375,   385,   386,   387,   388,   329,   325,
     261,   169,   247,   223,   244,   169,   169,   169,   306,     3,
       3,     4,   309,   308,   429,   178,   247,   261,   472,   169,
     247,   261,   169,   169,   158,   189,   197,   214,   228,   237,
     248,   438,   472,   247,   437,   481,   169,   481,   476,   169,
     234,   169,   169,   169,   476,   169,   476,   476,   476,   438,
       3,   438,   184,   408,   184,   410,   184,   409,   408,   253,
     435,   485,   486,   508,   410,   485,   409,   476,   511,   178,
     215,   224,   247,   253,   254,   258,   512,     3,   193,   261,
     348,   492,   182,   261,   475,   496,   492,   182,   261,   429,
     106,   259,   361,   492,   492,   375,   430,   430,   337,   169,
     169,   169,   247,   438,     3,   438,   247,   423,   169,   169,
     247,   169,   169,   423,   169,   169,   377,   489,   182,   387,
     337,   492,    45,    46,   262,   270,   310,   311,   312,   318,
     310,   310,   310,   315,     3,   492,   473,   476,   492,   182,
     473,   437,   265,   169,   476,   169,   169,   169,   169,   169,
     412,   435,   412,   412,     3,   494,   169,   247,   169,   242,
     169,   511,   511,   511,   492,   203,   349,   350,   476,   492,
     227,   396,   400,   300,   492,   428,     3,   169,     3,   427,
     169,     3,   169,   182,   459,   309,     3,   312,   178,   429,
     400,   193,     3,   400,   265,   438,   265,   486,   476,   178,
     178,   247,   193,   169,   247,   397,   399,   489,   159,   187,
     219,   394,   395,   401,   402,   456,   218,   466,   169,   429,
     169,   265,   169,   378,   169,   511,   169,   169,   438,   438,
     511,   511,   350,    34,    41,   247,   259,   434,   492,     3,
     257,   273,   431,   432,   457,   458,   487,   492,   403,   403,
     402,   394,   157,   200,   241,   418,   154,   216,   451,   467,
     438,   169,   178,   247,   178,   178,   247,   182,   397,   398,
     398,   217,   399,   434,   432,   247,   261,   429,   198,   465,
     468,   492,   260,   154,   511,   511,   397,   263,   263,   182,
     399,   458,   215,   492,   471,   134,   316,     3,   431,   452,
     453,   454,   468,   178,   178,   169,   403,   403,   397,   429,
     472,   247,   223,   244,   455,   316,   169,   473,   453,   400,
     466
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
#line 464 "sql.yacc"
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
#line 490 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 493 "sql.yacc"
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
#line 510 "sql.yacc"
    {
		(yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 515 "sql.yacc"
    {
		(yyval.ptr)=0;
	}
    break;

  case 7:

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
		add_feature("DELETE_WHERE_CURRENT_OF");
		}
	}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 535 "sql.yacc"
    {
		 (yyval.ptr)=A4GL_new_select_list_item_expr((yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 541 "sql.yacc"
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
#line 550 "sql.yacc"
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
#line 559 "sql.yacc"
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
#line 568 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(2) - (2)].update_cmd);
		add_feature("UPDATE_COLUMN_EQ_VALUE_LIST");
    }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 575 "sql.yacc"
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
#line 590 "sql.yacc"
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
#line 645 "sql.yacc"
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
#line 652 "sql.yacc"
    {
		(yyval.update_cmd)=(yyvsp[(1) - (3)].update_cmd);
		add_str_list((yyval.update_cmd)->column_list, (yyvsp[(3) - (3)].upd_pair)->column_name);
		local_add_select_list_item_list((yyval.update_cmd)->value_list, (yyvsp[(3) - (3)].upd_pair)->value);
	}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 663 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(1) - (1)].str));
        }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 666 "sql.yacc"
    {
                strcpy((yyval.str),(yyvsp[(2) - (2)].str));
        }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 671 "sql.yacc"
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
#line 678 "sql.yacc"
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
#line 695 "sql.yacc"
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
#line 712 "sql.yacc"
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
#line 733 "sql.yacc"
    {
		(yyval.upd_pair)=malloc(sizeof(struct s_update_pair));
		(yyval.upd_pair)->column_name=acl_strdup((yyvsp[(1) - (3)].str));
		(yyval.upd_pair)->value=(yyvsp[(3) - (3)].s_select_list_item);
	}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 742 "sql.yacc"
    {
			(yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
		}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 745 "sql.yacc"
    {
			(yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
		}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 753 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 756 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 764 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 765 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 772 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 775 "sql.yacc"
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
#line 783 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s ",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_VIEW");
}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 786 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_INDEX_QUALIFIED_PATH");
			add_feature("DROP_INDEX");
}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 790 "sql.yacc"
    {SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
			add_feature("DROP_TRIGGER");
}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 796 "sql.yacc"
    {(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 797 "sql.yacc"
    {(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 801 "sql.yacc"
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
#line 811 "sql.yacc"
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
#line 825 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 826 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 831 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 836 "sql.yacc"
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
#line 844 "sql.yacc"
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
#line 852 "sql.yacc"
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
#line 860 "sql.yacc"
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
#line 868 "sql.yacc"
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
#line 880 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 880 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 884 "sql.yacc"
    {SPRINTF2((yyval.str),"%s%s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 888 "sql.yacc"
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
#line 895 "sql.yacc"
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
#line 902 "sql.yacc"
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
#line 909 "sql.yacc"
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
#line 918 "sql.yacc"
    { strcpy(last_tmp_name,(yyvsp[(1) - (1)].str)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 922 "sql.yacc"
    {SPRINTF7((yyval.str),"CREATE UNIQUE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
		add_feature("CREATE_INDEX");
		add_feature("CREATE_INDEX_UNIQUE");
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
	
}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 929 "sql.yacc"
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
#line 941 "sql.yacc"
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
#line 952 "sql.yacc"
    {
		if (strchr((yyvsp[(2) - (8)].str),'@') || strchr((yyvsp[(2) - (8)].str),':')) add_feature("CREATE_INDEX_QUALIFIED_PATH");
		if (strchr((yyvsp[(6) - (8)].str),',')) { add_feature("CREATE_INDEX_COMPOSITE"); }
			add_feature("CREATE_INDEX");
			SPRINTF7((yyval.str)," CREATE INDEX %s %s %s %s %s %s %s",(yyvsp[(2) - (8)].str),(yyvsp[(3) - (8)].str),(yyvsp[(4) - (8)].str),(yyvsp[(5) - (8)].str),(yyvsp[(6) - (8)].str),(yyvsp[(7) - (8)].str),(yyvsp[(8) - (8)].str));
	}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 958 "sql.yacc"
    {
		add_feature("CREATE_DATABASE");
		a4gl_yyerror("You cannot create a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 962 "sql.yacc"
    {
		add_feature("DROP_DATABASE");
		a4gl_yyerror("You cannot drop a database from within Aubit4gl - if the target database allows - prepare and execute it manually");
	}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 966 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (4)].str),'@') || strchr((yyvsp[(2) - (4)].str),':')) add_feature("CREATE_SYNONYM_QUALIFIED_PATH");
			add_feature("CREATE_SYNONYM");
			SPRINTF3((yyval.str),"%s %s FOR %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); 
	}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 971 "sql.yacc"
    { 
		add_feature("CREATE_AUDIT");
		SPRINTF2((yyval.str),"CREATE AUDIT FOR %s IN '%s'",(yyvsp[(2) - (4)].str),A4GL_strip_quotes((yyvsp[(4) - (4)].str))); 
	}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 975 "sql.yacc"
    { 
		add_feature("DROP_AUDIT");
		SPRINTF1((yyval.str),"DROP AUDIT FOR %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 978 "sql.yacc"
    { 
		if (strchr((yyvsp[(2) - (2)].str),'@') || strchr((yyvsp[(2) - (2)].str),':')) add_feature("DROP_SYNONYM_QUALIFIED_PATH");
		add_feature("DROP_SYNONYM");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 982 "sql.yacc"
    { 
		add_feature("RECOVER_TABLE");
		SPRINTF1((yyval.str),"RECOVER TABLE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 985 "sql.yacc"
    { 
		add_feature("ROLLFORWARD_DATABASE");
		SPRINTF1((yyval.str),"ROLLFORWARD DATABASE %s",(yyvsp[(2) - (2)].str)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 992 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 993 "sql.yacc"
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
#line 1003 "sql.yacc"
    {(yyval.integer_val)=0;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 1004 "sql.yacc"
    { (yyval.integer_val)=1;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 1009 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 1013 "sql.yacc"
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
#line 1022 "sql.yacc"
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
#line 1031 "sql.yacc"
    {
		strcpy((yyval.str),A4GL_confirm_colname(last_tmp_name,(yyvsp[(1) - (1)].str)));
}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 1038 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 1041 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,strdup("\n"),(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 1047 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 1050 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("   "),(yyvsp[(1) - (1)].sql_string),NULL);
	}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 1061 "sql.yacc"
    {
		add_feature("ALTER_TABLE");
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 1065 "sql.yacc"
    {
		add_feature("CLUSTER_INDEX");
		add_feature("ALTER_INDEX_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO CLUSTER"),NULL);
		}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 1070 "sql.yacc"
    {
		add_feature("ALTER_INDEX_NOT_CLUSTER");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ALTER INDEX "),acl_strdup((yyvsp[(2) - (3)].str)),acl_strdup(" TO NOT CLUSTER"),NULL);
		}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 1077 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 1080 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 1089 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 1092 "sql.yacc"
    {
	add_feature("ALTER_TABLE_DROP");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 1096 "sql.yacc"
    {
	add_feature("ALTER_TABLE_MODIFY");
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 1100 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 1104 "sql.yacc"
    {
		add_feature("ALTER_TABLE_DROP_CONSTRAINT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 1108 "sql.yacc"
    {
		add_feature("ALTER_TABLE_MODIFY_NEXT");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 1112 "sql.yacc"
    {
		add_feature("ALTER_TABLE_LOCK_MODE");
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 1120 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 1124 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("ADD "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 1132 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 1135 "sql.yacc"
    {
		add_feature("ALTER_TABLE_ADD_BEFORE");
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),acl_strdup(" BEFORE "),acl_strdup((yyvsp[(3) - (3)].str)),NULL);
	}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 1142 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 1145 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 1152 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP %s",(yyvsp[(2) - (2)].str));
	}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 1155 "sql.yacc"
    {
		SPRINTF1((yyval.str),"DROP (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 1163 "sql.yacc"
    {
		SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 1172 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 1175 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("MODIFY "),kw_ob,(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
	}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 1181 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 1184 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (3)].sql_string),kw_comma,(yyvsp[(3) - (3)].sql_string),NULL);
	}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 1190 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 1197 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (PAGE)");}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 1198 "sql.yacc"
    {strcpy((yyval.str),"LOCK MODE (ROW)");}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 1202 "sql.yacc"
    {
		add_feature("DDL_NEXT_SIZE");
		SPRINTF1((yyval.str),"MODIFY NEXT SIZE %d",atoi((yyvsp[(2) - (2)].str)));
	}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 1210 "sql.yacc"
    {
		add_feature("DDL_CONSTRAINT");
		SPRINTF2((yyval.str),"ADD CONSTRAINT %s%s",(yyvsp[(2) - (3)].sql_string),(yyvsp[(3) - (3)].str));
	}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1214 "sql.yacc"
    {
		add_feature("ADD_CONSTRAINT");
		SPRINTF1((yyval.str),"ADD CONSTRAINT (%s)",(yyvsp[(3) - (4)].sql_string));
	}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1221 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1223 "sql.yacc"
    {
	(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (4)].sql_string),kw_comma,(yyvsp[(3) - (4)].sql_string),acl_strdup((yyvsp[(4) - (4)].str)), NULL);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1228 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1229 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_CONSTRAINT");}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1234 "sql.yacc"
    { SPRINTF1((yyval.str),"DROP CONSTRAINT %s",(yyvsp[(2) - (2)].str)); add_feature("DROP_CONSTRAINT"); }
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1235 "sql.yacc"
    {add_feature("DROP_CONSTRAINT");
		SPRINTF1((yyval.str),"DROP CONSTRAINT (%s)",(yyvsp[(3) - (4)].str));
	}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1241 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1242 "sql.yacc"
    {SPRINTF2((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1256 "sql.yacc"
    {  add_feature("ROLLBACK_WORK"); }
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1262 "sql.yacc"
    { insql=1;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1262 "sql.yacc"
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
#line 1271 "sql.yacc"
    {insql=1;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1271 "sql.yacc"
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
#line 1280 "sql.yacc"
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
#line 1305 "sql.yacc"
    {
			(yyval.str_list)=0;
	}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1308 "sql.yacc"
    {
			(yyval.str_list)=(yyvsp[(2) - (3)].str_list);
			 add_feature("INSERT_COLUMNLIST_EQ_VALUELIST");
	}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1316 "sql.yacc"
    {
                        (yyval.str_list)=new_str_list((yyvsp[(1) - (1)].str));
	}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1319 "sql.yacc"
    {
                        (yyval.str_list)=add_str_list((yyvsp[(1) - (3)].str_list), (yyvsp[(3) - (3)].str));
	}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1326 "sql.yacc"
    {	
			strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1329 "sql.yacc"
    { 
			/* with a table prefix - on an insert ? We'll just silently drop it... */
			strcpy((yyval.str),(yyvsp[(3) - (3)].str));
			A4GL_warn("Dropped table prefix from INSERT column name");
	}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1337 "sql.yacc"
    { (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1338 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1344 "sql.yacc"
    {(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1345 "sql.yacc"
    {(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_NULL); }
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1353 "sql.yacc"
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
#line 1371 "sql.yacc"
    { add_feature("BEGIN_WORK"); }
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1375 "sql.yacc"
    { add_feature("COMMIT_WORK"); }
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1380 "sql.yacc"
    {(yyval.e_boolean)=EB_FALSE;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1381 "sql.yacc"
    {
		add_feature("DATABASE_EXCLUSIVE");
		{(yyval.e_boolean)=EB_TRUE;}
	}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1391 "sql.yacc"
    {
	char buff[256];
	(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)),NULL);
	SPRINTF1(buff,"Warning: Informix specific SQL @ line %d\n",yylineno);
	ansi_violation(buff,1);
	}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1400 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG_MODE_ANSI");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s MODE ANSI", (yyvsp[(2) - (5)].str),(yyvsp[(4) - (5)].str));
	}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1404 "sql.yacc"
    {
			add_feature("START_DATABASE_WITH_LOG");
			sprintf((yyval.str),"START DATABASE %s WITH LOG IN %s", (yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str));
	}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1409 "sql.yacc"
    {
			add_feature("SET_CONSTRAINTS_ALL_IMMEDIATE");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1413 "sql.yacc"
    {
		add_feature("SET_BUFFERED_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1417 "sql.yacc"
    {
		add_feature("SET_LOG");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1421 "sql.yacc"
    {
			SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("UPDATE_STATISTICS_TABLE");
	}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1424 "sql.yacc"
    {
		add_feature("UPDATE_STATISTICS");
			SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str)); 
	}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1431 "sql.yacc"
    { (yyval.integer_val)=1; }
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1432 "sql.yacc"
    { (yyval.integer_val)=-1; }
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1433 "sql.yacc"
    { (yyval.integer_val)=0; }
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1437 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1438 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1439 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1440 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1441 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1442 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1443 "sql.yacc"
    { (yyval.sql_string)=(yyvsp[(1) - (1)].sql_string); }
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1451 "sql.yacc"
    {SPRINTF7((yyval.str),"%s %s %s %s %s %s %s",(yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(3) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(5) - (7)].str),(yyvsp[(6) - (7)].str),(yyvsp[(7) - (7)].str));  add_feature("GRANT"); }
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1452 "sql.yacc"
    {SPRINTF6((yyval.str),"%s %s %s %s %s %s",(yyvsp[(1) - (6)].str),(yyvsp[(2) - (6)].str),(yyvsp[(3) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(5) - (6)].str),(yyvsp[(6) - (6)].str));  add_feature("REVOKE"); }
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1453 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("GRANT"); }
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1454 "sql.yacc"
    {SPRINTF4((yyval.str),"%s %s %s %s ",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));  add_feature("REVOKE"); }
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1464 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1465 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1466 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1470 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1471 "sql.yacc"
    {SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1478 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1481 "sql.yacc"
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
#line 1490 "sql.yacc"
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
#line 1501 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1503 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1509 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1515 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1525 "sql.yacc"
    {
		add_feature("CREATE_VIEW_AS_SELECT");
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (6)].str)),kw_space,acl_strdup((yyvsp[(2) - (6)].str)),kw_space,acl_strdup((yyvsp[(3) - (6)].str)),kw_space,acl_strdup((yyvsp[(4) - (6)].str)),kw_space,(yyvsp[(5) - (6)].sql_string),kw_space,acl_strdup((yyvsp[(6) - (6)].str)),NULL);
	
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1532 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1534 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1540 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1543 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1544 "sql.yacc"
    {
		add_feature("CREATE_VIEW_SELECT_WITH_CHECK");
	}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1551 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
	}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1560 "sql.yacc"
    {SPRINTF5((yyval.str)," %s %s %s %s %s",(yyvsp[(1) - (5)].str),(yyvsp[(2) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str));
	add_feature("DDL_FOREIGN_KEY");
}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1567 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
add_feature("DDL_REFERENCES");
}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1579 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1585 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1590 "sql.yacc"
    {
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_UNIQUE");
	}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1594 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF3((yyval.str)," UNIQUE %s %s %s",(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_DISTINCT");
	}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1600 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));
add_feature("DDL_PRIMARY_KEY");
}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1608 "sql.yacc"
    {SPRINTF3((yyval.str)," %s %s %s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1613 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1616 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1619 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1626 "sql.yacc"
    {SPRINTF2((yyval.str)," %s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1627 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("USER")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1628 "sql.yacc"
    {SPRINTF1((yyval.str)," DEFAULT %s", A4GLSQLCV_get_sqlconst("TODAY")); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1629 "sql.yacc"
    { SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str)); add_feature("DDL_DEFAULT_VALUE"); }
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1635 "sql.yacc"
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
#line 1658 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1662 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup("");
	}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1664 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1671 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1674 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1680 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),NULL);
	}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1688 "sql.yacc"
    {
		SPRINTF1((yyval.str)," %s ",(yyvsp[(1) - (1)].str));
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
	}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1693 "sql.yacc"
    {
		SPRINTF0((yyval.str)," NOT NULL UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_NOT_NULL");
		add_feature("DDL_UNIQUE");
	}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1699 "sql.yacc"
    {
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_UNIQUE");
	}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1704 "sql.yacc"
    {
		ansi_violation("Use UNIQUE not DISTINCT",0);
		SPRINTF0((yyval.str)," UNIQUE ");
		(yyval.sql_string)=acl_strdup((yyval.str));
		add_feature("DDL_DISTINCT");
	}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1710 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1713 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup("CHECK ("),(yyvsp[(3) - (4)].sql_string),kw_cb,NULL);
		add_feature("DDL_CHECK");
		
	}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1718 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free(acl_strdup(" PRIMARY KEY "),NULL);
		add_feature("DDL_PRIMARY_KEY");
	}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1727 "sql.yacc"
    {
		add_feature("CREATE_SCHEMA");

(yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (3)].str)),kw_space,acl_strdup((yyvsp[(2) - (3)].str)),kw_space,acl_strdup((yyvsp[(3) - (3)].str)),NULL);
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1736 "sql.yacc"
    {SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1745 "sql.yacc"
    {
		(yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),kw_space,(yyvsp[(2) - (2)].sql_string),NULL);
	}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1751 "sql.yacc"
    {
		(yyval.sql_string)=(yyvsp[(1) - (1)].sql_string);
	}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1754 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(1) - (1)].str));
	}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1765 "sql.yacc"
    {
		 add_feature("HAVING"); 
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1774 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1781 "sql.yacc"
    {
		(yyval.u_table)=(yyvsp[(2) - (2)].u_table);
	}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1787 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(1) - (1)].u_table);}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1788 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (3)].u_table),(yyvsp[(3) - (3)].u_table),E_OUTER_NONE,NULL);
	}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1791 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (4)].u_table),(yyvsp[(4) - (4)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1796 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (6)].u_table),(yyvsp[(5) - (6)].u_table),E_OUTER_NORMAL,NULL);
		A4GL_warn("OUTER join *may* not be portable to non-informix database");
		add_feature("SELECT_OUTER");
	}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1807 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_OUTER_LEFT_OUTER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_OUTER");
	}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1811 "sql.yacc"
    {
		(yyval.u_table)=A4GLSQLPARSE_append_tablename((yyvsp[(1) - (5)].u_table),(yyvsp[(3) - (5)].u_table),E_INNER, (yyvsp[(5) - (5)].s_select_list_item));
		add_feature("SELECT_INNER");
	}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1819 "sql.yacc"
    {(yyval.u_table)=(yyvsp[(2) - (3)].u_table);}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1823 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (1)].str),NULL);
	}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1827 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1831 "sql.yacc"
    { 
			//A4GL_add_crud("SELECT",$<str>1);
			(yyval.u_table)=A4GLSQLPARSE_new_tablename((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str));
	}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1838 "sql.yacc"
    {
			/* No from or where etc.. */
			/* eg.. select user ; */
			(yyval.s_select)=new_empty_select();
		}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1843 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->first=(yyvsp[(1) - (2)].u_table);
			A4GL_set_associated_mem( (yyval.s_select), (yyval.s_select)->first);
}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1851 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(1) - (1)].s_select);
	}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1854 "sql.yacc"
    {
		(yyval.s_select)=(yyvsp[(2) - (2)].s_select);
		(yyval.s_select)->where_clause=(yyvsp[(1) - (2)].s_select_list_item);
	}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1860 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
	}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 1863 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (1)].s_select_list_item_list);
		(yyval.s_select)->having=0;
	}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 1868 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=(yyvsp[(1) - (2)].s_select_list_item_list);
		(yyval.s_select)->having=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 1873 "sql.yacc"
    {
		(yyval.s_select)=new_empty_select();
		(yyval.s_select)->group_by=0;
		(yyval.s_select)->having=(yyvsp[(1) - (1)].s_select_list_item);

	}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 1886 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 1889 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," OR ");
	}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 1895 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 1898 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item)," AND ");
	}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1904 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 1907 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_NOT,(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 1913 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 1916 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 1923 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1927 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_NOT_EXISTS, (yyvsp[(2) - (2)].s_select_list_item));
		add_feature("WHERE_EXISTS");
	}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 1938 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1938 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_MATCHES_ESCAPE");}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 1939 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1939 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_ILIKE_ESCAPE");}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1940 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1940 "sql.yacc"
    {SPRINTF1((yyval.str)," ESCAPE %s",(yyvsp[(2) - (2)].str));add_feature("WHERE_LIKE_ESCAPE");}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1943 "sql.yacc"
    {
		 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1953 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1954 "sql.yacc"
    {strcpy((yyval.str)," NOT ");}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1959 "sql.yacc"
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
#line 1968 "sql.yacc"
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
#line 1976 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),(yyvsp[(2) - (3)].str));
	}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1979 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_op_expr((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),"=");
	}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1982 "sql.yacc"
    { 
			FPRINTF(stderr,"Warning: Corrected =NULL to IS NULL line %d\n",yylineno);
			(yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_ISNULL,(yyvsp[(1) - (3)].s_select_list_item));
	}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1986 "sql.yacc"
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
#line 1993 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 1996 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_LIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));

	}
    break;

  case 292:

/* Line 1464 of yacc.c  */
#line 2000 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 293:

/* Line 1464 of yacc.c  */
#line 2003 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_ILIKE,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 294:

/* Line 1464 of yacc.c  */
#line 2006 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 295:

/* Line 1464 of yacc.c  */
#line 2009 "sql.yacc"
    { 
			(yyval.s_select_list_item)=new_select_list_item_regex(E_SLI_REGEX_NOT_MATCHES,(yyvsp[(1) - (4)].s_select_list_item),(yyvsp[(3) - (4)].s_select_list_item),(yyvsp[(4) - (4)].str));
	}
    break;

  case 296:

/* Line 1464 of yacc.c  */
#line 2015 "sql.yacc"
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
#line 2022 "sql.yacc"
    {
			strcpy((yyval.str)," < ");
	}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 2025 "sql.yacc"
    {
			strcpy((yyval.str)," > ");
	}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 2028 "sql.yacc"
    {
			strcpy((yyval.str)," ~ ");
	}
    break;

  case 300:

/* Line 1464 of yacc.c  */
#line 2031 "sql.yacc"
    {strcpy((yyval.str)," <= ");}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 2032 "sql.yacc"
    {strcpy((yyval.str)," >= ");}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 2037 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 303:

/* Line 1464 of yacc.c  */
#line 2040 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 304:

/* Line 1464 of yacc.c  */
#line 2043 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 305:

/* Line 1464 of yacc.c  */
#line 2046 "sql.yacc"
    {
                 (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 306:

/* Line 1464 of yacc.c  */
#line 2053 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 307:

/* Line 1464 of yacc.c  */
#line 2054 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("AGG_ALL");}
    break;

  case 308:

/* Line 1464 of yacc.c  */
#line 2055 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 2059 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str)," DISTINCT ");
		add_feature("AGG_DISTINCT");
	}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2066 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 311:

/* Line 1464 of yacc.c  */
#line 2067 "sql.yacc"
    {strcpy((yyval.str)," ALL "); add_feature("UNION_ALL");}
    break;

  case 312:

/* Line 1464 of yacc.c  */
#line 2068 "sql.yacc"
    {
		strcpy((yyval.str)," DISTINCT ");
		add_feature("UNION_DISTINCT");
	}
    break;

  case 313:

/* Line 1464 of yacc.c  */
#line 2072 "sql.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		add_feature("UNION_DISTINCT");
		strcpy((yyval.str)," DISTINCT ");
	}
    break;

  case 314:

/* Line 1464 of yacc.c  */
#line 2086 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_dtype_alias((yyvsp[(1) - (1)].str)));
	}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2101 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s%s%s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2105 "sql.yacc"
    {strcpy((yyval.str),"SERIAL"); add_feature("DDL_SERIAL"); }
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2106 "sql.yacc"
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
#line 2115 "sql.yacc"
    {strcpy((yyval.str),"SERIAL8"); add_feature("DDL_SERIAL8"); }
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2117 "sql.yacc"
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
#line 2126 "sql.yacc"
    {
 			add_feature("DDL_DECIMAL");
	}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2129 "sql.yacc"
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
#line 2137 "sql.yacc"
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
#line 2147 "sql.yacc"
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
#line 2155 "sql.yacc"
    {strcpy((yyval.str),"DATE");
 			add_feature("DDL_DATE"); }
    break;

  case 329:

/* Line 1464 of yacc.c  */
#line 2157 "sql.yacc"
    {strcpy((yyval.str),"INTEGER");}
    break;

  case 330:

/* Line 1464 of yacc.c  */
#line 2158 "sql.yacc"
    {strcpy((yyval.str),"SMALLINT");}
    break;

  case 331:

/* Line 1464 of yacc.c  */
#line 2159 "sql.yacc"
    {strcpy((yyval.str),"NCHAR"); add_feature("DDL_NCHAR");}
    break;

  case 332:

/* Line 1464 of yacc.c  */
#line 2160 "sql.yacc"
    {SPRINTF1((yyval.str),"NCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NCHAR");}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2161 "sql.yacc"
    {add_feature("DDL_NVARCHAR");}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2162 "sql.yacc"
    {SPRINTF1((yyval.str),"NVARCHAR(%s)",(yyvsp[(3) - (4)].str)); add_feature("DDL_NVARCHAR");}
    break;

  case 335:

/* Line 1464 of yacc.c  */
#line 2163 "sql.yacc"
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
#line 2171 "sql.yacc"
    {SPRINTF2((yyval.str),"DATETIME %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_DATETIME");}
    break;

  case 337:

/* Line 1464 of yacc.c  */
#line 2172 "sql.yacc"
    {add_feature("DDL_DATETIME");}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2173 "sql.yacc"
    {SPRINTF2((yyval.str),"INTERVAL %s TO %s",(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2174 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2175 "sql.yacc"
    {add_feature("DDL_INTERVAL");}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2176 "sql.yacc"
    {SPRINTF3((yyval.str),"INTERVAL %s(%s) TO %s",(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str)); add_feature("DDL_INTERVAL");}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2177 "sql.yacc"
    {add_feature("DDL_TEXT");}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2178 "sql.yacc"
    {add_feature("DDL_BYTE");}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2179 "sql.yacc"
    {add_feature("DDL_VARCHAR");}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2180 "sql.yacc"
    {SPRINTF1((yyval.str),"VARCHAR(%s)",(yyvsp[(3) - (4)].str));add_feature("DDL_VARCHAR");}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2181 "sql.yacc"
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
#line 2191 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2192 "sql.yacc"
    {
		SPRINTF1((yyval.str),",%s",(yyvsp[(2) - (2)].str));
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2199 "sql.yacc"
    {SPRINTF4((yyval.str)," %s %s %s %s",(yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(3) - (4)].str),(yyvsp[(4) - (4)].str));}
    break;

  case 353:

/* Line 1464 of yacc.c  */
#line 2203 "sql.yacc"
    {add_feature("DDL_DOUBLE_PRECISION"); SPRINTF1((yyval.str)," %s",(yyvsp[(1) - (1)].str));}
    break;

  case 359:

/* Line 1464 of yacc.c  */
#line 2228 "sql.yacc"
    {(yyval.int_list.i0)=0;}
    break;

  case 360:

/* Line 1464 of yacc.c  */
#line 2229 "sql.yacc"
    {
		(yyval.int_list.i0)=1;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (3)].str));
	}
    break;

  case 361:

/* Line 1464 of yacc.c  */
#line 2233 "sql.yacc"
    {
		(yyval.int_list.i0)=2;
		(yyval.int_list.i1)=atoi((yyvsp[(2) - (5)].str));
		(yyval.int_list.i2)=atoi((yyvsp[(4) - (5)].str));
	}
    break;

  case 362:

/* Line 1464 of yacc.c  */
#line 2241 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(1) - (1)].str));
	}
    break;

  case 363:

/* Line 1464 of yacc.c  */
#line 2244 "sql.yacc"
    {
		strcpy((yyval.str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 364:

/* Line 1464 of yacc.c  */
#line 2251 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 365:

/* Line 1464 of yacc.c  */
#line 2254 "sql.yacc"
    {
		(yyval.s_select_list_item)= (yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 366:

/* Line 1464 of yacc.c  */
#line 2264 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_col(0,(yyvsp[(1) - (2)].str),&(yyvsp[(2) - (2)].int_list));
	}
    break;

  case 367:

/* Line 1464 of yacc.c  */
#line 2267 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),&(yyvsp[(4) - (4)].int_list));
	}
    break;

  case 368:

/* Line 1464 of yacc.c  */
#line 2270 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col((yyvsp[(1) - (3)].str),"*",0);
	}
    break;

  case 369:

/* Line 1464 of yacc.c  */
#line 2273 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_col(0,"rowid",0);
	}
    break;

  case 370:

/* Line 1464 of yacc.c  */
#line 2280 "sql.yacc"
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
#line 2287 "sql.yacc"
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
#line 2295 "sql.yacc"
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
#line 2304 "sql.yacc"
    {
		SPRINTF1((yyval.str),"%s",A4GLSQLCV_check_colname((yyvsp[(1) - (3)].str),"*"));
		ADDMAP("Use Column",(yyval.str));
	}
    break;

  case 375:

/* Line 1464 of yacc.c  */
#line 2315 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); 
#ifdef DEBUG
A4GL_debug("Set $<str>$ to %s\n",(yyval.str)); 
#endif
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2327 "sql.yacc"
    { strcpy((yyval.str),A4GLSQLCV_generate_current(0,0)); }
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2328 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_generate_current((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)));
	}
    break;

  case 395:

/* Line 1464 of yacc.c  */
#line 2338 "sql.yacc"
    {SPRINTF1((yyval.str),"FRACTION(%s)",(yyvsp[(3) - (4)].str));}
    break;

  case 396:

/* Line 1464 of yacc.c  */
#line 2383 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2384 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2385 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free(acl_strdup((yyvsp[(1) - (1)].str)), NULL);}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2390 "sql.yacc"
    { add_feature("RENAME_TABLE"); strcpy((yyval.str),A4GLSQLCV_rentab((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str))); }
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2391 "sql.yacc"
    { add_feature("RENAME_COLUMN"); strcpy((yyval.str),A4GLSQLCV_rencol((yyvsp[(2) - (6)].str),(yyvsp[(4) - (6)].str),(yyvsp[(6) - (6)].str)) ); }
    break;

  case 403:

/* Line 1464 of yacc.c  */
#line 2399 "sql.yacc"
    {
		add_feature("UNLOCK_TABLE");
		SPRINTF2((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));
	}
    break;

  case 404:

/* Line 1464 of yacc.c  */
#line 2406 "sql.yacc"
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
#line 2417 "sql.yacc"
    { add_feature("LOCK_TABLE_SHARED");}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2418 "sql.yacc"
    {add_feature("LOCK_TABLE_EXCLUSIVE");}
    break;

  case 407:

/* Line 1464 of yacc.c  */
#line 2431 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_datetime_value((yyvsp[(1) - (1)].str)));}
    break;

  case 408:

/* Line 1464 of yacc.c  */
#line 2432 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_make_dtime_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].str),0));}
    break;

  case 409:

/* Line 1464 of yacc.c  */
#line 2436 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;

  case 410:

/* Line 1464 of yacc.c  */
#line 2440 "sql.yacc"
    {strcpy((yyval.str),A4GLSQLCV_interval_value((yyvsp[(1) - (1)].str)));}
    break;

  case 411:

/* Line 1464 of yacc.c  */
#line 2441 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (7)].str),(yyvsp[(2) - (7)].str),(yyvsp[(4) - (7)].str),(yyvsp[(7) - (7)].str),0));
		}
    break;

  case 412:

/* Line 1464 of yacc.c  */
#line 2444 "sql.yacc"
    {
		strcpy((yyval.str),A4GLSQLCV_make_ival_extend((yyvsp[(1) - (4)].str),(yyvsp[(2) - (4)].str),(char *)0, (yyvsp[(4) - (4)].str),0));
	}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2450 "sql.yacc"
    {SPRINTF1((yyval.str),"%s",(yyvsp[(1) - (1)].str));}
    break;

  case 414:

/* Line 1464 of yacc.c  */
#line 2454 "sql.yacc"
    {
	strcpy((yyval.str),(yyvsp[(2) - (2)].str));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2477 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(3) - (3)].s_select_list_item_list);
		add_feature("ORDER_BY");
	}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2487 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 417:

/* Line 1464 of yacc.c  */
#line 2490 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 418:

/* Line 1464 of yacc.c  */
#line 2496 "sql.yacc"
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
#line 2505 "sql.yacc"
    { 
		add_feature("ORDER_BY_NUMBER");
		(yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str));
	}
    break;

  case 420:

/* Line 1464 of yacc.c  */
#line 2509 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
		(yyval.s_select_list_item)->data.type=E_SLI_COLUMN_ORDERBY;
	}
    break;

  case 421:

/* Line 1464 of yacc.c  */
#line 2516 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 422:

/* Line 1464 of yacc.c  */
#line 2518 "sql.yacc"
    {add_feature("ORDER_BY_ASC"); strcpy((yyval.str),"ASC");}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2520 "sql.yacc"
    {add_feature("ORDER_BY_DESC"); strcpy((yyval.str),"DESC");}
    break;

  case 424:

/* Line 1464 of yacc.c  */
#line 2524 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=(yyvsp[(2) - (2)].s_select_list_item_list);
	}
    break;

  case 425:

/* Line 1464 of yacc.c  */
#line 2530 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 426:

/* Line 1464 of yacc.c  */
#line 2533 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 427:

/* Line 1464 of yacc.c  */
#line 2539 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 428:

/* Line 1464 of yacc.c  */
#line 2540 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2547 "sql.yacc"
    {
	(yyval.sql_string)=get_select_list_item(0,(yyvsp[(1) - (1)].s_select_list_item));
}
    break;

  case 430:

/* Line 1464 of yacc.c  */
#line 2560 "sql.yacc"
    {
		A4GL_set_sql_lineno(yylineno);
		(yyval.sql_string)=make_select_stmt_v2(current_upd_table, (yyvsp[(1) - (1)].s_select),"");
		map_select_stmt("SELECT",(yyvsp[(1) - (1)].s_select));
		A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2570 "sql.yacc"
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
#line 2577 "sql.yacc"
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
#line 2594 "sql.yacc"
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
#line 2601 "sql.yacc"
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
#line 2626 "sql.yacc"
    { 
		//start_bind('i',0);
		 set_ignore_indicators();}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2628 "sql.yacc"
    { clr_ignore_indicators();}
    break;

  case 437:

/* Line 1464 of yacc.c  */
#line 2630 "sql.yacc"
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
#line 2651 "sql.yacc"
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
#line 2694 "sql.yacc"
    { (yyval.s_select)=0;}
    break;

  case 440:

/* Line 1464 of yacc.c  */
#line 2695 "sql.yacc"
    { 
		(yyval.s_select)=(yyvsp[(3) - (3)].s_select);
		(yyval.s_select)->union_op=acl_strdup((yyvsp[(2) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select), (yyval.s_select)->union_op);
		add_feature("SELECT_UNION"); 
	}
    break;

  case 441:

/* Line 1464 of yacc.c  */
#line 2709 "sql.yacc"
    {
		(yyval.s_select_finish)=0;
	}
    break;

  case 442:

/* Line 1464 of yacc.c  */
#line 2712 "sql.yacc"
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
#line 2719 "sql.yacc"
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
#line 2729 "sql.yacc"
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
#line 2747 "sql.yacc"
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
#line 2760 "sql.yacc"
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
#line 2775 "sql.yacc"
    {(yyval.integer_val)=-1;}
    break;

  case 449:

/* Line 1464 of yacc.c  */
#line 2777 "sql.yacc"
    {
		(yyval.integer_val)=atol((yyvsp[(2) - (2)].str));
	}
    break;

  case 450:

/* Line 1464 of yacc.c  */
#line 2783 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 451:

/* Line 1464 of yacc.c  */
#line 2784 "sql.yacc"
    {strcpy((yyval.str),"ALL"); add_feature("SELECT_ALL");}
    break;

  case 452:

/* Line 1464 of yacc.c  */
#line 2785 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT"); add_feature("SELECT_DISTINCT");}
    break;

  case 453:

/* Line 1464 of yacc.c  */
#line 2786 "sql.yacc"
    {strcpy((yyval.str),"DISTINCT");
		add_feature("SELECT_UNIQUE");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy((yyval.str),"DISTINCT");
	}
    break;

  case 454:

/* Line 1464 of yacc.c  */
#line 2796 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=rationalize_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item_list));
		}
    break;

  case 455:

/* Line 1464 of yacc.c  */
#line 2803 "sql.yacc"
    { 
		 (yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 456:

/* Line 1464 of yacc.c  */
#line 2806 "sql.yacc"
    { 
		(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 457:

/* Line 1464 of yacc.c  */
#line 2812 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
	}
    break;

  case 458:

/* Line 1464 of yacc.c  */
#line 2815 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(2) - (2)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 459:

/* Line 1464 of yacc.c  */
#line 2820 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (3)].s_select_list_item);
		(yyval.s_select_list_item)->alias=acl_strdup((yyvsp[(3) - (3)].str));
		A4GL_set_associated_mem((yyval.s_select_list_item), (yyval.s_select_list_item)->alias);
	}
    break;

  case 460:

/* Line 1464 of yacc.c  */
#line 2829 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); /* A4GLSQLCV_check_expr($<sql_string>1) */
	}
    break;

  case 461:

/* Line 1464 of yacc.c  */
#line 2832 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
		(yyval.s_select_list_item)->sign='-';
	}
    break;

  case 462:

/* Line 1464 of yacc.c  */
#line 2836 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (2)].s_select_list_item);
	}
    break;

  case 463:

/* Line 1464 of yacc.c  */
#line 2843 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "/");
	}
    break;

  case 464:

/* Line 1464 of yacc.c  */
#line 2846 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_simple_expr((enum e_sli)(yyvsp[(2) - (2)].integer_val), (yyvsp[(1) - (2)].s_select_list_item));
	}
    break;

  case 465:

/* Line 1464 of yacc.c  */
#line 2849 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "*");
	}
    break;

  case 466:

/* Line 1464 of yacc.c  */
#line 2852 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "+");
	}
    break;

  case 467:

/* Line 1464 of yacc.c  */
#line 2855 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "-");
	}
    break;

  case 468:

/* Line 1464 of yacc.c  */
#line 2858 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_op_expr ((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].s_select_list_item), "||");
	}
    break;

  case 469:

/* Line 1464 of yacc.c  */
#line 2861 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 470:

/* Line 1464 of yacc.c  */
#line 2862 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TRUE); }
    break;

  case 471:

/* Line 1464 of yacc.c  */
#line 2863 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_FALSE); }
    break;

  case 472:

/* Line 1464 of yacc.c  */
#line 2864 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_USER); }
    break;

  case 473:

/* Line 1464 of yacc.c  */
#line 2865 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TODAY); }
    break;

  case 474:

/* Line 1464 of yacc.c  */
#line 2866 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_ROWID); }
    break;

  case 475:

/* Line 1464 of yacc.c  */
#line 2867 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_TIME); }
    break;

  case 476:

/* Line 1464 of yacc.c  */
#line 2868 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_STAR); }
    break;

  case 477:

/* Line 1464 of yacc.c  */
#line 2869 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_BUILTIN_CONST_COUNT_STAR); }
    break;

  case 478:

/* Line 1464 of yacc.c  */
#line 2871 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_AVG,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_AVG");
	}
    break;

  case 479:

/* Line 1464 of yacc.c  */
#line 2875 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MAX,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MAX");
	}
    break;

  case 480:

/* Line 1464 of yacc.c  */
#line 2879 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_MIN,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_MIN");
	}
    break;

  case 481:

/* Line 1464 of yacc.c  */
#line 2883 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_SUM,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_SUM");
	}
    break;

  case 482:

/* Line 1464 of yacc.c  */
#line 2887 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_agg1(E_SLI_BUILTIN_AGG_COUNT,(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].s_select_list_item));
		add_feature("SELECT_COUNT");
	}
    break;

  case 483:

/* Line 1464 of yacc.c  */
#line 2891 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (3)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (3)].str),0);
	}
    break;

  case 484:

/* Line 1464 of yacc.c  */
#line 2895 "sql.yacc"
    {
		add_sql_function((yyvsp[(1) - (4)].str));
		(yyval.s_select_list_item)=new_select_list_item_fcall((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 485:

/* Line 1464 of yacc.c  */
#line 2899 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_YEAR,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 486:

/* Line 1464 of yacc.c  */
#line 2902 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MONTH,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 487:

/* Line 1464 of yacc.c  */
#line 2905 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 488:

/* Line 1464 of yacc.c  */
#line 2908 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_MDY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 489:

/* Line 1464 of yacc.c  */
#line 2911 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_WEEKDAY,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 490:

/* Line 1464 of yacc.c  */
#line 2914 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DOW,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 491:

/* Line 1464 of yacc.c  */
#line 2917 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_builtin_fcall(E_SLI_BUILTIN_FUNC_DATE,(yyvsp[(3) - (4)].s_select_list_item_list));
	}
    break;

  case 492:

/* Line 1464 of yacc.c  */
#line 2920 "sql.yacc"
    {
		  (yyval.s_select_list_item)=new_select_list_item_simple_expr(E_SLI_BRACKET_EXPR,(yyvsp[(2) - (3)].s_select_list_item));
	}
    break;

  case 493:

/* Line 1464 of yacc.c  */
#line 2923 "sql.yacc"
    { 
		add_feature("EXTEND"); 
		(yyval.s_select_list_item)=(yyvsp[(3) - (4)].s_select_list_item);
	}
    break;

  case 494:

/* Line 1464 of yacc.c  */
#line 2927 "sql.yacc"
    { 
		(yyval.s_select_list_item)=new_select_list_item_datetime((yyvsp[(1) - (1)].str));
		add_feature("FUNC_DATETIME");
	}
    break;

  case 495:

/* Line 1464 of yacc.c  */
#line 2931 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_interval((yyvsp[(1) - (1)].str));
		add_feature("FUNC_INTERVAL");
	}
    break;

  case 496:

/* Line 1464 of yacc.c  */
#line 2935 "sql.yacc"
    {
		(yyval.s_select_list_item)=(yyvsp[(2) - (3)].s_select_list_item);
	}
    break;

  case 497:

/* Line 1464 of yacc.c  */
#line 2943 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 498:

/* Line 1464 of yacc.c  */
#line 2946 "sql.yacc"
    {
		(yyval.s_select_list_item)=append_select_list_item_case(
							(yyvsp[(1) - (2)].s_select_list_item),
							(yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 499:

/* Line 1464 of yacc.c  */
#line 2955 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element(
				(yyvsp[(2) - (4)].s_select_list_item),
				(yyvsp[(4) - (4)].s_select_list_item));

	}
    break;

  case 500:

/* Line 1464 of yacc.c  */
#line 2961 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_case_element( 0, (yyvsp[(2) - (2)].s_select_list_item));
	}
    break;

  case 501:

/* Line 1464 of yacc.c  */
#line 2968 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 502:

/* Line 1464 of yacc.c  */
#line 2971 "sql.yacc"
    {
			(yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 503:

/* Line 1464 of yacc.c  */
#line 2995 "sql.yacc"
    {(yyval.str_list)=NULL;}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 2996 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(2) - (4)].str));  add_str_list((yyval.str_list),(yyvsp[(4) - (4)].str));}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 2997 "sql.yacc"
    { (yyval.str_list)=new_str_list((yyvsp[(1) - (3)].str));  add_str_list((yyval.str_list),(yyvsp[(3) - (3)].str));}
    break;

  case 507:

/* Line 1464 of yacc.c  */
#line 3001 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 3004 "sql.yacc"
    {
			(yyval.s_select_list_item)=new_select_list_item_extend((yyvsp[(1) - (2)].s_select_list_item),(yyvsp[(2) - (2)].str_list));
	}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 3010 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_YEAR;}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 3011 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MONTH;}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 3012 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_DAY;}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 3013 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_HOUR;}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 3014 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_MINUTE;}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 3015 "sql.yacc"
    {(yyval.integer_val)=E_SLI_UNITS_SECOND;}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 3020 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 3024 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 3028 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_slil((yyvsp[(1) - (5)].s_select_list_item),(yyvsp[(4) - (5)].s_select_list_item_list),E_SLI_NOT_IN_VALUES);
                add_feature("WHERE_IN");
        }
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 3032 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_op_sli((yyvsp[(1) - (3)].s_select_list_item),(yyvsp[(3) - (3)].s_select_list_item),E_SLI_NOT_IN_SELECT);
                add_feature("WHERE_IN_SELECT");
        }
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 3039 "sql.yacc"
    {
		(yyval.s_select_list_item_list)=local_new_select_list_item_list((yyvsp[(1) - (1)].s_select_list_item));
	}
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 3042 "sql.yacc"
    {
                (yyval.s_select_list_item_list)=local_add_select_list_item_list((yyvsp[(1) - (3)].s_select_list_item_list),(yyvsp[(3) - (3)].s_select_list_item));
	}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 3047 "sql.yacc"
    { (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 3048 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_literal((yyvsp[(1) - (1)].str)); }
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 3049 "sql.yacc"
    { 
		char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 3051 "sql.yacc"
    { char buff[256]; SPRINTF1(buff," -%s",(yyvsp[(2) - (2)].str)); (yyval.s_select_list_item)=new_select_list_item_literal(buff); }
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3057 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3067 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
             ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3071 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3075 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3079 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str), NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3083 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL, A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str),(yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3087 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL,(yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3091 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3095 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3103 "sql.yacc"
    {
                if (strstr((yyvsp[(1) - (1)].str),"systables")!=0) { add_feature("IFX_SYSTABLES"); }
                if (strstr((yyvsp[(1) - (1)].str),"syscolumns")!=0) { add_feature("IFX_SYSCOLUMNS"); }
                if (strstr((yyvsp[(1) - (1)].str),"sysindexes")!=0) { add_feature("IFX_SYSINDEXES"); }
                strcpy((yyval.str),A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));
                }
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3113 "sql.yacc"
    {

	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3118 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3122 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, A4GL_strip_quotes((yyvsp[(1) - (1)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3126 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3130 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (3)].str),NULL, A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3134 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (5)].str), NULL,A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3139 "sql.yacc"
    {
             SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename(NULL, (yyvsp[(1) - (3)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(3) - (3)].str))));
	     ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3143 "sql.yacc"
    {
            SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename( (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str), A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(5) - (5)].str))));
	    ADDMAP("Use Table",(yyval.str));
	}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3147 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_db_tablename((yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str))));
	     ADDMAP("Use Table",(yyval.str));
        }
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3155 "sql.yacc"
    {
	     SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)));
        }
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3158 "sql.yacc"
    {
	        SPRINTF1((yyval.str),"%s", A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (1)].str)));
                ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3163 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str)); ADDMAP("Use Index",(yyvsp[(1) - (1)].str)); }
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3164 "sql.yacc"
    { SPRINTF3((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3165 "sql.yacc"
    {
	     SPRINTF2((yyval.str),"%s:%s", (yyvsp[(1) - (5)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3170 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (3)].str)); ADDMAP("Use Index",(yyvsp[(1) - (3)].str)); }
    break;

  case 550:

/* Line 1464 of yacc.c  */
#line 3171 "sql.yacc"
    { SPRINTF4((yyval.str),"%s@%s%s%s",(yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str),(yyvsp[(4) - (5)].str),(yyvsp[(5) - (5)].str)); ADDMAP("Use Index",(yyval.str)); }
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3172 "sql.yacc"
    {
	     SPRINTF3((yyval.str),"%s@%s:%s", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), A4GLSQLCV_ownerize_tablename((yyvsp[(5) - (7)].str), (yyvsp[(7) - (7)].str)));
             ADDMAP("Use Index",(yyval.str));
        }
    break;

  case 553:

/* Line 1464 of yacc.c  */
#line 3183 "sql.yacc"
    {
                      (yyval.ptr)=A4GL_new_expr_simple_string(A4GL_get_clobbered_from((yyval.str)), ET_EXPR_IDENTIFIER);
	}
    break;

  case 555:

/* Line 1464 of yacc.c  */
#line 3189 "sql.yacc"
    { sprintf((yyval.str),".%s",(yyvsp[(2) - (2)].str)); }
    break;

  case 557:

/* Line 1464 of yacc.c  */
#line 3194 "sql.yacc"
    {strcpy((yyval.str), A4GL_strip_quotes ((yyvsp[(1) - (1)].str)));}
    break;

  case 562:

/* Line 1464 of yacc.c  */
#line 3245 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_insert_cmd((yyvsp[(1) - (1)].insert_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].insert_cmd));
			acl_free((yyvsp[(1) - (1)].insert_cmd));

		}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3252 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_update_cmd((yyvsp[(1) - (1)].update_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].update_cmd));
			acl_free((yyvsp[(1) - (1)].update_cmd));
		}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3258 "sql.yacc"
    {
			int converted;
			(yyval.sql_string)=get_delete_cmd((yyvsp[(1) - (1)].delete_cmd),&converted);
			A4GL_free_associated_mem((yyvsp[(1) - (1)].delete_cmd));
			acl_free((yyvsp[(1) - (1)].delete_cmd));
		}
    break;

  case 567:

/* Line 1464 of yacc.c  */
#line 3273 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3274 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 570:

/* Line 1464 of yacc.c  */
#line 3276 "sql.yacc"
    { print_exec_select((yyvsp[(1) - (1)].sql_string));  }
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3278 "sql.yacc"
    {
			print_sql_commit ((yyvsp[(1) - (1)].integer_val));
	}
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3281 "sql.yacc"
    {print_unable_to_parse();}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3285 "sql.yacc"
    { (yyval.sql_string)=make_sql_string_and_free((yyvsp[(1) - (2)].sql_string),acl_strdup((yyvsp[(2) - (2)].str)),0);
}
    break;

  case 575:

/* Line 1464 of yacc.c  */
#line 3294 "sql.yacc"
    {
			(yyval.sql_string)=make_select_stmt_v2("", (yyvsp[(1) - (1)].s_select),"");
			A4GL_free_select_stmt((yyvsp[(1) - (1)].s_select));
		}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3300 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3301 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate(NULL));
		}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3304 "sql.yacc"
    {
			strcpy((yyval.str),A4GLSQLCV_get_forupdate((yyvsp[(2) - (2)].str)));
		}
    break;

  case 579:

/* Line 1464 of yacc.c  */
#line 3309 "sql.yacc"
    { strcpy((yyval.str),(yyvsp[(1) - (1)].str)); }
    break;

  case 580:

/* Line 1464 of yacc.c  */
#line 3310 "sql.yacc"
    { sprintf((yyval.str),"%s,%s",(yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str)); }
    break;

  case 582:

/* Line 1464 of yacc.c  */
#line 3314 "sql.yacc"
    {sprintf((yyval.str),"%s.%s",A4GLSQLCV_ownerize_tablename(NULL, (yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3315 "sql.yacc"
    {
        sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str)), (yyvsp[(5) - (5)].str));
}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3325 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3326 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3327 "sql.yacc"
    { sprintf((yyval.str),"%s %s",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str)); print_exec_sql(acl_strdup((yyval.str))); }
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3328 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3329 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3330 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3331 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3332 "sql.yacc"
    { print_exec_sql(acl_strdup((yyvsp[(1) - (1)].str))); }
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3336 "sql.yacc"
    { 
	char *s;
	s=acl_strdup((yyvsp[(1) - (1)].str));
	(yyval.s_select_list_item)=new_select_list_item_column_from_transform(s);
	acl_free(s);
	}
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3342 "sql.yacc"
    {  
		(yyval.s_select_list_item)=new_select_list_item_builtin_const(E_SLI_QUERY_PLACEHOLDER);}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3344 "sql.yacc"
    {
		(yyval.s_select_list_item)=new_select_list_item_replace_var((yyvsp[(1) - (1)].sql_string));
	}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3363 "sql.yacc"
    {
        add_feature("DATABASE_USED");
       conn_db((yyvsp[(2) - (3)].str));
}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3371 "sql.yacc"
    {
		(yyval.sql_string)=acl_strdup((yyvsp[(2) - (3)].str));
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3378 "sql.yacc"
    {sprintf((yyval.str),"(%s)",(yyvsp[(2) - (3)].str));}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3379 "sql.yacc"
    { sprintf((yyval.str),"%s%s%s",(yyvsp[(1) - (3)].str),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].str));}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3380 "sql.yacc"
    {sprintf((yyval.str),"%d",atoi((yyvsp[(1) - (1)].str)));}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3381 "sql.yacc"
    {sprintf((yyval.str),"(%s%s)",(yyvsp[(1) - (2)].str),(yyvsp[(2) - (2)].str));}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3386 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3387 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3388 "sql.yacc"
    {strcpy((yyval.str),"*");}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3389 "sql.yacc"
    {strcpy((yyval.str),"/");}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3390 "sql.yacc"
    {strcpy((yyval.str),"%");}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3395 "sql.yacc"
    {strcpy((yyval.str),"+");}
    break;

  case 607:

/* Line 1464 of yacc.c  */
#line 3396 "sql.yacc"
    {strcpy((yyval.str),"-");}
    break;

  case 608:

/* Line 1464 of yacc.c  */
#line 3412 "sql.yacc"
    {sprintf((yyval.str),"%s", A4GLSQLCV_check_tablename((yyvsp[(1) - (1)].str)));}
    break;

  case 609:

/* Line 1464 of yacc.c  */
#line 3413 "sql.yacc"
    {sprintf((yyval.str),"%s.*", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)));}
    break;

  case 610:

/* Line 1464 of yacc.c  */
#line 3414 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", (yyvsp[(1) - (3)].str),A4GLSQLCV_get_sqlconst ("rowid"));}
    break;

  case 611:

/* Line 1464 of yacc.c  */
#line 3415 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (3)].str)),(yyvsp[(3) - (3)].str));}
    break;

  case 612:

/* Line 1464 of yacc.c  */
#line 3416 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 613:

/* Line 1464 of yacc.c  */
#line 3417 "sql.yacc"
    {sprintf((yyval.str),"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (5)].str),(yyvsp[(3) - (5)].str)),(yyvsp[(5) - (5)].str));}
    break;

  case 614:

/* Line 1464 of yacc.c  */
#line 3418 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (4)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (4)].str), 1,(yyvsp[(3) - (4)].str),0));}
    break;

  case 615:

/* Line 1464 of yacc.c  */
#line 3419 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (6)].str)),(yyvsp[(3) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(5) - (6)].str),0));}
    break;

  case 616:

/* Line 1464 of yacc.c  */
#line 3420 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0));  }
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3421 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str)), (yyvsp[(5) - (8)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,1,(yyvsp[(7) - (8)].str),0)); }
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3423 "sql.yacc"
    {sprintf((yyval.str),"%s", (yyvsp[(1) - (6)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s((yyvsp[(1) - (6)].str), 2,(yyvsp[(3) - (6)].str),(yyvsp[(5) - (6)].str)));}
    break;

  case 619:

/* Line 1464 of yacc.c  */
#line 3424 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename(NULL,(yyvsp[(1) - (8)].str)),(yyvsp[(3) - (8)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(5) - (8)].str),(yyvsp[(7) - (8)].str)));}
    break;

  case 620:

/* Line 1464 of yacc.c  */
#line 3425 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str)); strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str)));  }
    break;

  case 621:

/* Line 1464 of yacc.c  */
#line 3426 "sql.yacc"
    {char buff[256]; sprintf(buff,"%s.%s", A4GLSQLCV_ownerize_tablename((yyvsp[(1) - (10)].str),(yyvsp[(3) - (10)].str)), (yyvsp[(5) - (10)].str));  strcpy((yyval.str), A4GLSQLCV_make_substr_s(buff,2,(yyvsp[(7) - (10)].str),(yyvsp[(9) - (10)].str))); }
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3431 "sql.yacc"
    {
                (yyval.s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);
        }
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3434 "sql.yacc"
    {
                (yyval.s_select_list_item)=new_select_list_item_cast((yyvsp[(1) - (3)].s_select_list_item), (yyvsp[(3) - (3)].str));
        }
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3443 "sql.yacc"
    { (yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item); }
    break;

  case 625:

/* Line 1464 of yacc.c  */
#line 3444 "sql.yacc"
    {(yyvsp[(1) - (1)].s_select_list_item)=(yyvsp[(1) - (1)].s_select_list_item);}
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3445 "sql.yacc"
    {  (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_DONT_CARE,(yyvsp[(1) - (1)].s_select_list_item)); }
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3446 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ALL,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 628:

/* Line 1464 of yacc.c  */
#line 3447 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_ANY,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 629:

/* Line 1464 of yacc.c  */
#line 3448 "sql.yacc"
    { (yyval.s_select_list_item)=new_select_list_item_sq(E_SQE_SOME,(yyvsp[(2) - (2)].s_select_list_item)); }
    break;

  case 630:

/* Line 1464 of yacc.c  */
#line 3452 "sql.yacc"
    {strcpy((yyval.str),"");}
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3453 "sql.yacc"
    {strcpy((yyval.str),(yyvsp[(1) - (1)].str));}
    break;



/* Line 1464 of yacc.c  */
#line 8909 "y.tab.c"
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
#line 3459 "sql.yacc"


#if LEX_YY_PREGEN
#include "../../tools/no_yacc/cygwin/compilers/sql/lex.sqlparse_yy.c"
#else
#include "lex.yy.c"
#endif
#include "util.c"
#include "cmds.c"

